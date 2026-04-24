using Buchi.HWToolbox.Common;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

namespace Buchi.DataAcquisition
{
    /// <summary>Direction of one scan</summary>
    public enum eDirection { Unknown, Forward, Reverse }

    /// -----------------------------------------------------------------------
    /// <summary>
    /// This class contains a list of scans. This list can be used to read 
    /// the start and end point of the forward and reverse scan of a data package.
    /// </summary>
    public class CDQScanList
    {
        /// <summary>Structur for storing one scan</summary>
        protected struct CDQScan
        {
            /// <summary>Length of one scan</summary>
            private int m_iLength;

            /// <summary>Direction of one scan (forward, reverse)</summary>
            private eDirection m_Direction;

            /// ---------------------------------------------------------------
            /// <summary>Property</summary>
            public int Length { get { return m_iLength; } set { m_iLength = value; } }
            public eDirection Direction { get { return m_Direction; } }

            /// ---------------------------------------------------------------
            /// <summary>
            /// Constructor
            /// </summary>
            /// <param name="p_iLength">Length of one scan</param>
            /// <param name="p_Direction">Direction of one scan</param>
            public CDQScan(int p_iLength, eDirection p_Direction)
            {
                m_iLength = p_iLength;
                m_Direction = p_Direction;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>This list contains scans</summary>
        protected List<CDQScan> m_ScanList = new List<CDQScan>();

        /// <summary>Returns the number of scan which are contained in the list.</summary>
        public int Count { get { return m_ScanList.Count; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates from a status array a scan list. Each status byte of the array
        /// is checked. A scan is a sequence of the same bytes. There are 
        /// - forward scans
        /// - reverse scans
        /// - error (forw. / rev.) scans
        /// - overflow (forw. / rev.) scans
        /// </summary>
        /// <param name="p_Status">The status array</param>
        /// <param name="p_PackageSize">Maximal range which is searched</param>
        public void Create(List<uint> p_Status, int p_PackageSize)
        {
            if (p_Status.Count > 0 && p_PackageSize > 0)
            {
                int l_Start = 0;
                int l_ScanLength = GetScanLength(p_Status, l_Start, p_PackageSize);

                // find the scans
                while (l_ScanLength != 0 && l_Start < p_PackageSize)
                {
                    // build an entry for each found scan and add it to the list
                    uint l_Status = (uint)p_Status[l_Start];
                    CDQScan l_Scan = new CDQScan(l_ScanLength, GetDirectionFromStatus(l_Status));
                    m_ScanList.Add(l_Scan);
                    l_Start += l_ScanLength;
                    l_ScanLength = GetScanLength(p_Status, l_Start, p_PackageSize);
                }
            }
        }

        public void Clear()
        {
            m_ScanList.Clear();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Sets a new start point. All scans before this start point will be 
        /// removed. They are not used any more.
        /// </summary>
        /// <param name="p_Start">The new start point</param>
        public void SetStart(int p_Start)
        {
            Debug.Assert(p_Start <= GetEndData(m_ScanList.Count - 1));
            int i = 0;
            int l_Rest = 0;

            int l_Current = GetEndData(0);

            // find scan which contains the new start point
            while (p_Start >= l_Current && i < (m_ScanList.Count - 1))
            {
                i++;
                l_Current = GetEndData(i);
            }

            // remove all scans before the new start point
            if (i > 0)
            {
                l_Rest = GetEndData(i - 1) + 1;  // number of scan datas up to index i (+1 for [0])
                m_ScanList.RemoveRange(0, i);
            }

            // set new length in first scan
            SetLength(0, GetLength(0) - (p_Start - l_Rest));
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Appends a scan list to an existing scan list. If the tangent scans of 
        /// the two lists have the same direction, one scan will be built from 
        /// the two. Otherwise the two lists will be appended without modification.
        /// </summary>
        /// <param name="p_ScanList">Append this list</param>
        public void Append(CDQScanList p_ScanList)
        {
            if (p_ScanList != null && p_ScanList.Count > 0)
            {
                // build a new scan from two tangent scans, if the direction is the same
                if (m_ScanList.Count != 0 &&
                    GetDirectionFromScan(m_ScanList.Count - 1) == p_ScanList.GetDirectionFromScan(0))
                {
                    // get sum of the two scan length
                    p_ScanList.SetLength(0, (GetLength(Count - 1) + p_ScanList.GetLength(0)));

                    // remove one scan
                    m_ScanList.RemoveAt(Count - 1);
                }

                // append the two lists
                m_ScanList.AddRange(p_ScanList.m_ScanList);
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns the index of the last data of the selected scan.
        /// </summary>
        /// <param name="p_Index">Selected scan</param>
        /// <returns>Index of the start data of the selected scan</returns>
        public int GetStartData(int p_Index)
        {
            int i = 0;
            int l_Start = 0;

            while (i < p_Index)
            {
                l_Start += GetLength(i);
                i++;
            }
            return l_Start;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns the index of the last data of the selected scan.
        /// </summary>
        /// <param name="p_Index">Selected scan</param>
        /// <returns>Index of the last data of the selected scan</returns>
        public int GetEndData(int p_Index)
        {
            int i = 0;
            int l_End = 0;

            while (i <= p_Index)
            {
                l_End += GetLength(i);
                i++;
            }
            if (l_End == 0)
            {
                return 0;
            }
            else
            {
                return l_End - 1;
            }
        }

        /// -------------------------------------------------------------------
        /// 
        /// <summary>
        /// Returns the length of selected scan.
        /// </summary>
        /// <param name="p_Index">Selected scan</param>
        /// <returns>Length of selected scan</returns>
        public int GetLength(int p_Index)
        {
            return m_ScanList[p_Index].Length;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Set Length of selected scan.
        /// </summary>
        /// <param name="p_Index">Selected scan</param>
        /// <param name="p_iLength">Scan length</param>
        public void SetLength(int p_Index, int p_iLength)
        {
            CDQScan l_Scan = m_ScanList[p_Index];
            l_Scan.Length = p_iLength;
            m_ScanList[p_Index] = l_Scan;
        }


        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns the total length of all scans.
        /// </summary>
        /// <returns>Total length of all scans</returns>
        public int GetLengthSum()
        {
            if (Count > 0)
            {
                return (GetEndData(Count - 1) + 1);
            }
            else
            {
                return 0;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Adds one scan to the list.
        /// </summary>
        /// <param name="p_iLength">Length of the added scan</param>
        /// <param name="p_Direction">Direction of the added scan</param>
        /// 
#if !DEBUG
        private void Add(int p_iLength, eDirection p_Direction)
#else
        public void Add(int p_iLength, eDirection p_Direction)   // public for unit test
#endif
        {
            CDQScan l_Scan = new CDQScan(p_iLength, p_Direction);
            m_ScanList.Add(l_Scan);
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns the direction of the selected data.
        /// </summary>
        /// <param name="p_Index">Selected data</param>
        /// <returns>Data direction</returns>
        public eDirection GetDirectionFromData(int p_DataIndex)
        {
            // is p_DataIndex within range?
            if (m_ScanList.Count > 0 && p_DataIndex <= GetEndData(m_ScanList.Count - 1))
            {
                int i = 0;
                int l_ScanEndIndex = GetEndData(i);

                while (l_ScanEndIndex < p_DataIndex)
                {
                    i++;                            // get next scan
                    l_ScanEndIndex = GetEndData(i);
                }
                return GetDirectionFromScan(i);
            }
            else
            {
                return eDirection.Unknown;
            }

        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns the direction of the selected scan.
        /// </summary>
        /// <param name="p_Index">Selected scan</param>
        /// <returns>Scan direction</returns>
        private eDirection GetDirectionFromScan(int p_ScanIndex)
        {
            return ((CDQScan)m_ScanList[p_ScanIndex]).Direction;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Return the direction of the given status byte.
        /// </summary>
        /// <param name="p_Status">The status byte</param>
        /// <returns>The direction</returns>
        public static eDirection GetDirectionFromStatus(uint p_Status)
        {
            uint l_uiBitForwardScan = CTBMeasurementChannelDataPackage.m_uiBitForwardScan;
            uint l_uiBitReverseScan = CTBMeasurementChannelDataPackage.m_uiBitReverseScan;

            if ((p_Status & l_uiBitForwardScan) == l_uiBitForwardScan)
            {
                return eDirection.Forward;
            }
            else if ((p_Status & l_uiBitReverseScan) == l_uiBitReverseScan)
            {
                return eDirection.Reverse;
            }
            else
            {
                Debug.Assert(false, "Unknown direction");
                return eDirection.Unknown;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Determines the length of a sequence of the same direction. Each byte
        /// is checked.
        /// </summary>
        /// <param name="p_Status">Array which contains the status bytes.</param>
        /// <param name="p_Start">Start point of the sequence</param>
        /// <param name="p_PackageSize">Maximal range which is searched</param>
        /// <returns></returns>
#if !DEBUG
        private int GetScanLength(List<uint> p_Status, int p_Start, int p_PackageSize)
#else
        public int GetScanLength(List<uint> p_Status, int p_Start, int p_PackageSize)   // public for unit test
#endif
        {
            int l_Counter = 0;

            if (p_Status.Count > p_Start)
            {
                uint l_CurrentStatus = p_Status[p_Start];

                while ((p_Start + l_Counter) < p_Status.Count && (p_Start + l_Counter) < p_PackageSize)
                {
                    if (p_Status[p_Start + l_Counter] != l_CurrentStatus)
                    {
                        return l_Counter;
                    }
                    l_Counter++;
                }
            }
            else
            {
                return 0;
            }
            return l_Counter;
        }
    }
}
