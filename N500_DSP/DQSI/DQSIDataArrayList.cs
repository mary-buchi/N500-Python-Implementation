using System;
using System.Collections.Generic;
using System.Diagnostics;
using Buchi.HWToolbox.Common;

namespace Buchi.DataAcquisition
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// This class is a container which stores the laser, the detector and the
    /// status data. You can add data or remove data from this container.
    /// If data is added the first time, the ADC shift will be applied (remove
    /// detector and laser data). All status flags (e.g. error bit) in the status
    /// stream have to be shifted back before the examinations of the scans can be done.
    /// This class is not MT safe (for every result object is a new instance made 
    /// of this class)
    /// </summary>
    public class CDQDataArrayList
    {
        /// <summary>Contains the laser data</summary>
        private List<double> m_LaserData;

        /// <summary>Contains the detector data</summary>
        private List<double> m_DetectorData;

        /// <summary>Contains the status data</summary>
        private List<uint> m_StatusData;

        /// <summary>Contains number of occured errors</summary>
        private int m_iErrorCounter = 0;

        /// <summary>Contains the last status bit. If an error
        /// or an overflow status was found, the succeeding scan must
        /// be ignored.</summary>
        private uint m_uiLastStatus = m_uiUnknownDirection;  // initial start value

        private const uint m_uiBitForwardScan = CTBMeasurementChannelDataPackage.m_uiBitForwardScan;
        private const uint m_uiBitReverseScan = CTBMeasurementChannelDataPackage.m_uiBitReverseScan;
        private const uint m_uiBitOverflow = CTBMeasurementChannelDataPackage.m_uiBitOverflow;
        private const uint m_uiBitError = CTBMeasurementChannelDataPackage.m_uiBitError;
        private const uint m_uiUnknownDirection = 1;  // (0 is already used) 

        /// <summary>Properties</summary>
        public int Size { get { return m_DetectorData.Count; } }
        public int ErrorCounter { get { return m_iErrorCounter; } set { m_iErrorCounter = value; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Constructor
        /// </summary>
        public CDQDataArrayList()
        {
            m_LaserData = new List<double>(400000);
            m_DetectorData = new List<double>(400000);
            m_StatusData = new List<uint>(400000);
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Clears the buffer
        /// </summary>
        public void Clear()
        {
            m_LaserData.Clear();
            m_DetectorData.Clear();
            m_StatusData.Clear();
        }

        /// <summary>
        /// prepares the array list for a new run
        /// </summary>
        public void Start()
        {
            Clear();

            m_iErrorCounter = 0;
            m_uiLastStatus = m_uiUnknownDirection;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Appends laser, detector and status vectors to existing array. Do data
        /// shift on start of each new measurement
        /// </summary>
        /// <param name="p_LaserData">The laser data</param>
        /// <param name="p_DetectorData">The detetor data</param>
        /// <param name="p_Status">The status data</param>
        /// <param name="p_iDataShift">Length of data shift</param>
        /// sequence has been added</param>
        public void Add(double[] p_LaserData, double[] p_DetectorData, uint[] p_Status, int p_iDataShift)
        {
            Debug.Assert(p_LaserData.Length == p_DetectorData.Length && p_DetectorData.Length == p_Status.Length);

            // append data
            m_LaserData.AddRange(p_LaserData);
            m_DetectorData.AddRange(p_DetectorData);
            m_StatusData.AddRange(p_Status);

            // do shift only first time (ADC and filter shift)
            if (m_DetectorData.Count == p_DetectorData.Length && p_DetectorData.Length > p_iDataShift)
            {
                m_DetectorData.RemoveRange(0, p_iDataShift);
                m_LaserData.RemoveRange(0, p_iDataShift);
            }

            // spreads overflow and error flags in status data if needed
            if (p_iDataShift != 0)
            {
                int iStart = m_StatusData.Count - p_Status.Length;
                SpreadInStatusData(m_uiBitError, iStart, p_iDataShift);
                SpreadInStatusData(m_uiBitOverflow, iStart, p_iDataShift);
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Spread error flag as long as shift is, if one error flag is found in a status bit.
        /// </summary>
        /// <param name="p_uiBit">Test this error bit</param>
        /// <param name="p_iStart">Test this error bit</param>
        /// <param name="p_iDataShift">Length of data shift</param>
        private void SpreadInStatusData(uint p_uiBit, int p_iStart, int p_iDataShift)
        {
            // shift overflow and error flags in status data
            for (int i = p_iStart; i < m_StatusData.Count; i++)
            {
                // test if a bad bit is contained
                if (p_uiBit == (p_uiBit & (uint)m_StatusData[i]))
                {
                    SpreadBit(p_uiBit, i, p_iDataShift);
                }
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Spreads the bad bit as long as data shift is.
        /// </summary>
        /// <param name="p_uiBit">Spread this error bit</param>
        /// <param name="p_Index">Spread bit at this position</param>
        /// <param name="p_iDataShift">Length of data shift</param>
        private void SpreadBit(uint p_uiBit, int p_Index, int p_iDataShift)
        {
            // Spread bit
            for (int start = p_Index - p_iDataShift; start < p_Index; start++)
            {
                if (start >= 0)
                {
                    m_StatusData[start] = ((uint)m_StatusData[start] | p_uiBit);
                }
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns all contained data and removes it from buffer. The data is
        /// formated to 16.8 format (/256)
        /// </summary>
        /// <param name="p_LaserData">The laser data</param>
        /// <param name="p_DetectorData">The detetor data</param>
        /// <param name="p_Status">The status data</param>
        public void GetPackage(out double[] p_LaserData, out double[] p_DetectorData, out CDQScanList p_StatusList)
        {
            Debug.Assert(m_LaserData.Count == m_DetectorData.Count);

            if (m_DetectorData.Count != 0)
            {
                // return the data arrays
                p_LaserData = new double[m_DetectorData.Count];
                p_DetectorData = new double[m_DetectorData.Count];
                p_StatusList = new CDQScanList();

                m_LaserData.CopyTo(0, p_LaserData, 0, m_DetectorData.Count);
                m_DetectorData.CopyTo(0, p_DetectorData, 0, m_DetectorData.Count);
                p_StatusList.Create(m_StatusData, m_DetectorData.Count);

                // clear buffers
                Clear();
            }
            else
            {
                // return 0 data if not enough data is available
                p_LaserData = new double[0];
                p_DetectorData = new double[0];
                p_StatusList = new CDQScanList();
            }

            // format the data to 16.8 format (/256)
            FormatData(ref p_LaserData);
            FormatData(ref p_DetectorData);
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Format data to 16.8 format.
        /// </summary>
        /// <param name="p_dbData"></param>
        private void FormatData(ref double[] p_dbData)
        {
            const double l_FormatFactor = 256.0;

            for (int i = 0; i < p_dbData.Length; i++)
            {
                p_dbData[i] /= l_FormatFactor;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        ///  This method returns the end of the next bit sequence and the type
        ///  of the bit sequence. The type can be: forward, reverse, error or
        ///  overflow. If the sequence is not terminated or the next sequence
        ///  is bad, false will be returned.
        /// </summary>
        /// <param name="p_iStart">Start of scan</param>
        /// <param name="p_iEnd">End of scan (out)</param>
        /// <returns>Return the bit type of the found sequence</returns>
#if !DEBUG
        private bool GetNextSequence(int p_iStart, out int p_iEnd, out uint p_uiStatus)
#else
        public bool GetNextSequence(int p_iStart, out int p_iEnd, out uint p_uiStatus)   // public for unit test
#endif
        {
            // get first status byte
            int l_iIndex = p_iStart;
            p_uiStatus = (uint)m_StatusData[l_iIndex];
            p_iEnd = l_iIndex;

            // test regular case 
            if (p_uiStatus == m_uiBitForwardScan || p_uiStatus == m_uiBitReverseScan)
            { // do nothing, all is ok
            }
            // test overflow
            else if (m_uiBitOverflow == (m_uiBitOverflow & p_uiStatus))
            {
                Debug.WriteLine("DQ: Invalid data: Overflow sequence in data found");
                //CCOExceptionManager.GetInstance().TraceMessage(ID.DQ_ID, "Invalid data: Overflow sequence in raw data removed");
            }
            // test error
            else if (m_uiBitError == (m_uiBitError & p_uiStatus))
            {
                Debug.WriteLine("DQ: Invalid data: Error sequence in data found");
                //CCOExceptionManager.GetInstance().TraceMessage(ID.DQ_ID, "Invalid data: Error sequence in raw data removed");
                m_iErrorCounter++;
            }
            // get any other invalid states
            else
            {
                // this line should not be reached, the HW should not deliver such states
                Debug.WriteLine("DQ: Invalid data: Invalid sequence in data found, state: " + p_uiStatus.ToString("x"));
                //CCOExceptionManager.GetInstance().TraceMessage(ID.DQ_ID, "Invalid data: Invalid sequence in raw data removed, state: " + p_uiStatus.ToString("x"));
                m_iErrorCounter++;
            }

            // get rest of sequence
            l_iIndex++;

            while (l_iIndex < m_DetectorData.Count)
            {
                if ((uint)m_StatusData[l_iIndex] != p_uiStatus)
                {
                    // start of new sequence
                    p_iEnd = l_iIndex - 1;

                    // test if next scan is ok
                    if ((uint)m_StatusData[l_iIndex] == m_uiBitForwardScan || (uint)m_StatusData[l_iIndex] == m_uiBitReverseScan)
                    {
                        Debug.WriteLine($"DQ: Valid data sequence, status: {p_uiStatus.ToString("x")} - length: {p_iEnd - p_iStart}");

                        return true;
                    }
                    else
                    {
                        Debug.WriteLine("DQ: Invalid data: 1 scan ignored before invalid data sequence, length: " + (p_iEnd - p_iStart).ToString());
                        //CCOExceptionManager.GetInstance().TraceMessage(ID.DQ_ID, "Invalid data: 1 scan ignored before invalid data sequence, length: " + (p_iEnd - p_iStart).ToString());
                        return false;
                    }
                }
                l_iIndex++;
            }
            // sequence is not yet terminated
            p_iEnd = m_DetectorData.Count - 1;
            return false;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a new datalist which contains the next valid (forw-rev) scan pair. If no valid
        /// scan pair is available, null will be returned. All overflow or error sequences
        /// will be removed by this algorithm. The following rules are applied:
        /// 1. first scan will be always ignored
        /// 2. a forward scan is only accepted in a For|Rev|For sequence
        /// 3. a reverse scan is only accepted in a Rev|For|Rev sequence
        /// </summary>
        /// <param name="p_iMinScanSize">Minimal scan size</param>
        /// <returns>Data array list which contains the next for /rev. scan pair</returns>
        public CDQDataArrayList GetScanPair(int p_iMinScanSize)
        {
            CDQDataArrayList l_NewDataList = null;

            // test if data size is ok
            if (m_DetectorData.Count >= p_iMinScanSize * 2)
            {
                int l_iStartForward = 0;
                int l_iEndForward = 0;
                int l_iStartReverse = 0;
                int l_iEndReverse = 0;
                bool l_bReverseOk = false;
                uint l_uiLast = m_uiLastStatus;

                // find first correct scan pair
                while (!l_bReverseOk && l_iStartForward <= (m_DetectorData.Count - (2 * p_iMinScanSize)))
                {
                    // find first correct forward scan
                    if (FindScan(l_iStartForward, out l_iEndForward, p_iMinScanSize, m_uiBitForwardScan))
                    {
                        // find the successing reverse scan
                        l_iStartReverse = l_iEndForward + 1;
                        if (FindScan(l_iStartReverse, out l_iEndReverse, p_iMinScanSize, m_uiBitReverseScan))
                        {
                            l_bReverseOk = true;
                        }
                        else
                        {
                            l_iStartForward = l_iEndReverse + 1;
                        }
                    }
                    else
                    {
                        l_iStartForward = l_iEndForward + 1;
                    }
                }

                // add scan pair if correct pair was found
                if (l_bReverseOk)
                {
                    l_NewDataList = new CDQDataArrayList();
                    int l_iLength = l_iEndReverse - l_iStartForward + 1;
                    Debug.Assert(l_iStartForward + l_iLength <= m_DetectorData.Count, "DQ: Bad length");

                    // add data to new list
                    l_NewDataList.m_DetectorData.AddRange(m_DetectorData.GetRange(l_iStartForward, l_iLength));
                    l_NewDataList.m_LaserData.AddRange(m_LaserData.GetRange(l_iStartForward, l_iLength));
                    l_NewDataList.m_StatusData.AddRange(m_StatusData.GetRange(l_iStartForward, l_iLength));
                    l_NewDataList.ErrorCounter = m_iErrorCounter;

                    // remove from existing list
                    m_DetectorData.RemoveRange(0, l_iEndReverse + 1);
                    m_LaserData.RemoveRange(0, l_iEndReverse + 1);
                    m_StatusData.RemoveRange(0, l_iEndReverse + 1);
                }
                else
                {
                    // reset status if no pair is added
                    m_uiLastStatus = l_uiLast;
                }
                m_iErrorCounter = 0;
            }
            return l_NewDataList;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Find the wanted scan. It must have a minimum length. The scan starts
        /// at the given start point. If an error or overflow is detected, the succeeding
        /// sequence is ignored. If the scan is not terminated within the given data, false
        /// will be returned.
        /// </summary>
        /// <param name="p_iStartReverse">Start point</param>
        /// <param name="p_iEndReverse">[out] End point, of current scan</param>
        /// <param name="p_iMinScanSize">Minimum of scan</param>
        /// <returns>True if wanted scan was found</returns>
        private bool FindScan(int p_iStart, out int p_iEnd, int p_iMinScanSize, uint p_uiDirectionBit)
        {
            int l_iEnd = p_iStart;
            uint l_uiStatus = 0;
            bool l_bResult = false;

            // make shure index is not out of range
            if (p_iStart < m_DetectorData.Count)
            {
                // get next scan
                bool l_bFound = GetNextSequence(p_iStart, out l_iEnd, out l_uiStatus);

                // verify scan direction
                if (l_bFound && l_uiStatus == p_uiDirectionBit && (l_iEnd - p_iStart + 1) >= p_iMinScanSize)
                {
                    l_bResult = true; // scan found
                }
            }
            p_iEnd = l_iEnd;

            // ignore scan after the detection of a bad state bit
            if (m_uiLastStatus != m_uiBitForwardScan && m_uiLastStatus != m_uiBitReverseScan)
            {
                // the first scan of a measurement is always ignored, it may be a not complete forward scan
                if (m_uiLastStatus != m_uiUnknownDirection)
                {
                    Debug.WriteLine("DQ: Invalid data: 1 scan ignored after invalid data sequence, length: " + (l_iEnd - p_iStart));
                    //CCOExceptionManager.GetInstance().TraceMessage(ID.DQ_ID, "Invalid data: 1 scan ignored after invalid data sequence, length: " + (l_iEnd - p_iStart));
                }
                l_bResult = false;
            }
            m_uiLastStatus = l_uiStatus;
            return l_bResult;
        }
    } // class
}
