using Buchi.Core.Math;
using Buchi.Core;
using Buchi.DataAcquisition.Common;
using Buchi.DeviceInterface.Ethernet;
using Buchi.HWToolbox.Common;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.Remoting.Contexts;
using System.Text;
using System.Threading.Tasks;

// The state machine things are taken out from the original source code.
// Although the descriptions still refer to the state machine...

namespace Buchi.DataAcquisition
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// This state class is a part of the state machine. Its a substate of the
    /// the state "Process". It starts one measurement sequence
    /// </summary>
    public class CDQStateRecordingStartMeasurement
    {
        private CDQDataArrayList m_RawData;

        private bool m_FirstDataPackage = true;

        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingStartMeasurement m_Instance;

        /// <summary>Contains the scan info list of one measurement</summary>
        private Common.CDQResultScanInfoList m_ScanInfoList;

        /// <summary>Properties</summary>
        public CDQDataArrayList RawData { get { return m_RawData; } }
        public Common.CDQResultScanInfoList ScanInfoList { get { return m_ScanInfoList; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary>
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingStartMeasurement();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingStartMeasurement GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Does the initial work before each measurement. Cleans the data.
        /// </summary>
        /// <param name="p_Context">The current state machine context</param>
        public void Do()
        {
            // check if nr of scans is ok
            if (DQSIController.ScanPairTotal <= 0)
            {
                Console.WriteLine("DQ: Bad number of scan pairs");
                return;
            }

            // clear any old results
            ClearForNewMeasurement();

            // go reading data packages
        }

        /// <summary>
        /// Adds a data package to the raw data store.
        /// In the original code, this raw data store is filled in a separate state machine
        /// running in parallel to the processing of the data. We want to avoid this here.
        /// </summary>
        /// <param name="dataPackage">The byte array with the received data from the instrument</param>
        public void AddDataPackage(byte[] dataPackage)
        {
            Console.WriteLine("Add one data package");

            var chan = new CTBChannelMeasurementChannels();
            var package = chan.UnwrapDataPackage(dataPackage);

            if (package.Command == ETBChannelCommand.eCmdMeasChannelGetDataPackage)
            {
                CTBMeasurementChannelDataPackage data = (CTBMeasurementChannelDataPackage)package.GetReturnValue();
                data.GetData(out double[] laser, out double[] detector, out uint[] status);

                if (m_FirstDataPackage)
                {
                    m_RawData = new CDQDataArrayList();
                    m_RawData.Start();
                    m_FirstDataPackage = false;
                }
                if (m_RawData == null) m_RawData = new CDQDataArrayList();
                m_RawData.Add(laser, detector, status, DQSIController.DataShift);
            }
            else
            {
                Console.WriteLine($"Unhandled command: {package.Command}");
            }
        }



        /// -------------------------------------------------------------------
        /// <summary>
        /// Clear for new measurement sequence
        /// </summary>
        private void ClearForNewMeasurement()
        {
            // clear all data in the filter state
            CDQStateRecordingFilterDataPackage.GetInstance().ClearForNewMeasurement();

            // clear all data in the CheckScanQuality state
            CDQStateRecordingCheckScanQuality.GetInstance().ClearForNewMeasurement();

            // clear the interferogram averages
            CDQStateRecordingAverageScans.GetInstance().ClearForNewMeasurement();

            // clear the centered interferogram
            CDQStateRecordingCenterAveraged.GetInstance().ClearForNewMeasurement();

            // clear spectras
            CDQStateSpectraDispersionCorrection.GetInstance().ClearForNewMeasurement();

            // clear noise test
            CDQStateRecordingNoiseTest.GetInstance().ClearForNewMeasurement();

            // clear invalid data
            CDQStateRecordingInvalidData.GetInstance().ClearForNewMeasurement();

            // clear reference values 
            CDQStateRecordingIsolateScans.GetInstance().ClearForNewMeasurement();

            // init Scan info List
            m_ScanInfoList = new CDQResultScanInfoList();

            // init data package store
            m_RawData = null;
            m_FirstDataPackage = true;
        }
    }
}

namespace Buchi.DataAcquisition
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// This state class is a part of the state machine. Its a substate of the
    /// the state "Process". It reads new data
    /// </summary>
    public class CDQStateRecordingReadData
    {
        /// <summary>Contains the raw data of one package. </summary>
        private CDQDataArrayList m_RawData;

        /// <summary>Properties</summary>
        public CDQDataArrayList RawData { get { return m_RawData; } }

        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingReadData m_Instance;

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary>
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingReadData();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingReadData GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        public void Clear()
        {
            if (m_RawData != null)
                m_RawData.Clear();
            m_RawData = null;
        }

        /// <summary>
        /// Reads one new raw data package.
        /// </summary>
        public void Do()
        {
            Console.WriteLine("Start reading one data package");

            // This is quite a bit changed from the original code, as the reading of the
            // instrument data is not happening in a separate state machine, but the
            // data is loaded beforehand in CDQStateRecordingStartMeasurement.GetInstance().RawData

            // add one scan info item
            CDQScanInfo l_ScanInfo = new CDQScanInfo();
            l_ScanInfo.ScanState = EDQScanState.eOk;
            CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList.Add(l_ScanInfo);

            m_RawData = CDQStateRecordingStartMeasurement.GetInstance().RawData.GetScanPair(DQSIController.MinRawScanSize);

            if (m_RawData == null)
            {
                var msg = "Not enough data for a scan";
                Console.WriteLine(msg);
                throw new Exception(msg);
            }

            // test if data is ok
            if (m_RawData.Size >= (DQSIController.MinRawScanSize * 2))
            {
                // set number of occured errors while reading this package
                CDQStateRecordingInvalidData.GetInstance().ErrorCounter += m_RawData.ErrorCounter;
                l_ScanInfo.RawDataReadingErrors = m_RawData.ErrorCounter;

                // test if too many errors
                if (m_RawData.ErrorCounter > 0)
                {
                    // test if too many errors
                    int l_invalidScanStartCheck = DQSIController.InvalidScanStartCheck;
                    int l_iScanPairTotal = DQSIController.ScanPairTotal;
                    double l_dbMaxInvalidScanPercentage = DQSIController.MaxInvalidScanPercentage;
                    CDQStateRecordingInvalidData.GetInstance().CheckNumberOfErrors(l_invalidScanStartCheck, l_iScanPairTotal, l_dbMaxInvalidScanPercentage);
                }
            }
            else
            {
                // get next data package
                string l_sError = "Bad scan pair length: " + m_RawData.Size.ToString() + ", needed: " + DQSIController.MinRawScanSize * 2;
                l_ScanInfo.SetError(l_sError, EDQScanState.eErrorBadRawDataLength);
                CDQStateRecordingInvalidData.GetInstance().Do();
            }
        }
    }
}

namespace Buchi.DataAcquisition
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// This state class is a part of the state machine. Its a substate of the
    /// the state "Process". It does the filtering of the data packages
    /// </summary>
    public class CDQStateRecordingFilterDataPackage //: Buchi.DataAcquisition.CDQStateRecording
    {
        /// <summary>
        /// Contains the filtered laser values of one package. Each entry has
        /// an appropriate entry at the same index in filtered detector and status data.
        /// </summary>
        public CCOVector FilteredLaser
        {
            get { return m_FilteredLaser; }
            set { m_FilteredLaser = value; }
        }

        /// <summary>
        /// Contains the filtered detector values of one package. Each entry has
        /// an appropriate entry at the same index in filtered laser and status data.
        /// </summary>
        public CCOVector FilteredDetector
        {
            get { return m_FilteredDetector; }
            set { m_FilteredDetector = value; }
        }

        /// <summary>
        /// This list contains all scan status information (start, end and direction) 
        /// of one package after the filtering was done on the laser and detector data.
        /// </summary>
        public CDQScanList ScanList
        {
            get { return m_ScanList; }
        }

        /// <summary>
        /// Raw Detector Signal
        /// </summary>
        public CCOVector RawDetector
        {
            get { return m_RawDetector; }
        }


        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary>
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingFilterDataPackage();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingFilterDataPackage GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        public void Clear()
        {
            if (m_FilteredLaser != null)
            {
                m_FilteredLaser.Release();
                m_FilteredLaser = null;
            }
            if (m_FilteredDetector != null)
            {
                m_FilteredDetector.Release();
                m_FilteredDetector = null;
            }
            if (m_ScanList != null)
            {
                m_ScanList.Clear();
            }
            if (m_RawDetector != null)
            {
                m_RawDetector.Release();
                m_RawDetector = null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Does the filtering with a FIR filter. Incoming data packages will be
        /// filtered. If the filtered data can not be fully used (scan fragements),
        /// it will be saved for the next treatement.
        /// </summary>
        public void Do()
        {
            Console.WriteLine("Start filtering one data package");

            // get one raw data package
            CDQDataArrayList l_RawData = CDQStateRecordingReadData.GetInstance().RawData;

            // filter the data package
            FilterData(l_RawData);

            // go on checking the scan quality of the filtered data
            Console.WriteLine("Finished filtering one data package");
            CDQStateRecordingCheckScanQuality.GetInstance().Do();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Filter the data.
        /// The filtered data is time shifted to match the time scale of the raw data.
        /// An apodisation is applied to the beginning and end of the raw data to 
        /// avoid artefacts.
        /// </summary>
        /// <param name="p_Context">The current state machine context</param>
        private void FilterData(CDQDataArrayList l_RawData)
        {
            // load filter coefficients
            double[] l_FilterLaserArray = DQSIController.LaserFilter;
            double[] l_FilterDetectorArray = DQSIController.DetectorFilter;
            Debug.Assert(l_FilterLaserArray.Length == l_FilterDetectorArray.Length);

            // get data
            double[] l_LaserData, l_DetectorData;
            l_RawData.GetPackage(out l_LaserData, out l_DetectorData, out m_ScanList);

            m_RawDetector = new CCOVector(l_DetectorData);

            // apply apodization on start and end of laser data
            int l_iBorderLength = (l_FilterLaserArray.Length + 1) / 2;
            int l_iMiddleLength = l_LaserData.Length - 2 * l_iBorderLength;
            CCOVector l_Border = new CCOVector(l_iBorderLength);
            CCOVector l_Middle = new CCOVector(l_iMiddleLength);
            l_Border.FillSelection(0, l_iBorderLength, 1.0);
            l_Middle.FillSelection(0, l_iMiddleLength, 1.0);
            DoWeighting(l_Border);
            CCOVector[] l_Appod = { l_Border, l_Middle, l_Border.Reverse() };
            CCOVector l_Appodization = new CCOVector(l_Appod);

            CCOVector l_Laser = new CCOVector(l_LaserData);
            l_Laser *= l_Appodization;

            // filter data
            m_FilteredLaser = null;
            m_FilteredDetector = null;
            m_FilteredLaser = CCOVector.Conv(l_Laser, new CCOVector(l_FilterLaserArray));
            m_FilteredDetector = CCOVector.Conv(new CCOVector(l_DetectorData), new CCOVector(l_FilterDetectorArray));
            m_FilteredLaser = m_FilteredLaser.GetSlice(l_iBorderLength, l_LaserData.Length);
            m_FilteredDetector = m_FilteredDetector.GetSlice(l_iBorderLength, l_LaserData.Length);
            // todo.stad could be optimized (getslice costs memory)

            // Number of samples must be the same for detector, laser and status
            Console.WriteLine("DQ: Filtered status: " + (m_ScanList.GetEndData(m_ScanList.Count - 1) + 1) + " laser: " + m_FilteredLaser.Length + " detector: " + m_FilteredDetector.Length);
        }

        /// -----------------------------------------------------------------------
        /// <summary>
        /// Do weighting used for apodisation
        /// </summary>
        /// <param name="p_Vector">Weight this vector</param>
        private void DoWeighting(CCOVector p_Vector)
        {
            double scale;
            int iLength = p_Vector.Length;

            for (int i = 0; i < p_Vector.Length; i++)
            {
                scale = 0.5 * (1.0 - System.Math.Cos(System.Math.PI * (i + 1.0) / iLength));
                p_Vector[i] *= scale;
            }
        }

        /// -----------------------------------------------------------------------
        /// <summary>
        /// Clear all data. Do this before a new measurement.
        /// </summary>
        public void ClearForNewMeasurement()
        {
            // clear the filter data
            m_FilteredLaser = null;
            m_FilteredDetector = null;
            m_ScanList = null;
        }

        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingFilterDataPackage m_Instance;

        /// <summary>Contains the filtered laser values of one package. Each entry has
        /// an appropriate entry at the same index in filtered detector and status data. </summary>
        private CCOVector m_FilteredLaser;

        /// <summary>Contains the filtered detector values of one package. Each entry has
        /// an appropriate entry at the same index in filtered laser and status data.</summary>
        private CCOVector m_FilteredDetector;

        /// <summary>This list contains all scan status information (start, end and direction) 
        /// of one package after the filtering was done on the laser and detector data. </summary>
        private CDQScanList m_ScanList;

        private CCOVector m_RawDetector;
    }
}


namespace Buchi.DataAcquisition
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// This state class is a part of the state machine. Its a substate of the
    /// the state "Process". It checks the quality of scans (bubble detection)
    /// </summary>
    public class CDQStateRecordingCheckScanQuality //: Buchi.DataAcquisition.CDQStateRecording
    {

        /// <summary>Lowpass filtered half Detector Vector</summary>
        public CCOVector LPFilteredDetectorData
        {
            get { return m_LPFilteredDetectorData; }
            set { m_LPFilteredDetectorData = value; }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary>
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingCheckScanQuality();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingCheckScanQuality GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        public void Clear()
        {
            if (m_LPFilteredDetectorData != null)
            {
                m_LPFilteredDetectorData.Release();
                m_LPFilteredDetectorData = null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Checks the quality of the filtered scan.
        /// The data is first processed with a lowpass filter.
        /// The quality is (delta lowpass(filtered signal))max/(delta filtered signal)max
        /// </summary>
        public void Do()
        {
            Console.WriteLine("Start checking the scan quality of one data package");

            // Perform Scan Quality Check only if MeasurementContext=Sample and Robustness is on
            if (/*GetContext(p_Context).Controller.MeasurementContext == EDQMeasurementContext.eSample
                &&*/ DQSIController.RobustnessOn)
            {
                // get the filtered data package
                CCOVector l_FilteredDetector = CDQStateRecordingFilterDataPackage.GetInstance().FilteredDetector;

                // Perform Scan Quality Check only if there is a signal
                if (l_FilteredDetector.Abs().Max() > DQSIController.MinDeltaSignal)
                {
                    // filter the data package
                    //LowpassFilter2(l_FilteredDetector, p_Context);
                    LowpassFilter2(CDQStateRecordingFilterDataPackage.GetInstance().RawDetector);

                    //calculate the quality
                    double l_RelativeError = m_LPFilteredDetectorData.Abs().Max() / l_FilteredDetector.Abs().Max();
                    Debug.Print("--------------------------------- Relative Error = " + l_RelativeError.ToString());
                    DebugAppendRelativeError(l_RelativeError);
                    if (l_RelativeError > DQSIController.MaxAllowedRelativeError)
                    {
                        //bad data
                        Debug.Print("-------------------------------------> Bubbles!!");
                        CDQScanInfo l_ScanInfo = CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList.GetCurrent();
                        string l_sError = "Scan quality check failed. Relative Error: " + l_RelativeError.ToString();
                        l_ScanInfo.SetError(l_sError, EDQScanState.eErrorScanQualityCheckFailed);
                        CDQStateRecordingInvalidData.GetInstance().Do();
                        return;
                    }
                }
            }

            // go on finding zero points in filtered data
            Console.WriteLine("Finished checking scan quality of one data package");
        }

        void DebugAppendRelativeError(double p_RelativeError)
        {
            Console.WriteLine($"Relative Error{p_RelativeError}");
        }


        /// -------------------------------------------------------------------
        /// <summary>
        /// Perform a lowpass filter on the half of the filtered data.
        /// </summary>
        /// <param name="p_Data">Filtered detector data vector</param>
        private void LowpassFilter2(CCOVector p_SourceData)
        {
            const int l_iReductionFactor = 2;
            int l_iResultDataLength = p_SourceData.Length / l_iReductionFactor;

            m_LPFilteredDetectorData = new CCOVector(l_iResultDataLength);

            CCOVector l_FilterLP = new CCOVector(DQSIController.DetectorFilterLp2);
            int l_iHalfFilterLenght = l_FilterLP.Length / 2;

            double l_dSum;
            int l_iFrom;
            int l_iTo;

            for (int i = 0; i < l_iResultDataLength; i++)
            {
                l_dSum = 0.0;

                l_iFrom = i > (l_iResultDataLength - l_iHalfFilterLenght - 1) ? i - (l_iResultDataLength - l_iHalfFilterLenght - 1) : 0;
                l_iTo = i < l_iHalfFilterLenght - 1 ? i + l_iHalfFilterLenght : l_FilterLP.Length - 1;

                for (int j = l_iFrom; j <= l_iTo; j++)
                    l_dSum += p_SourceData[l_iReductionFactor * (i + l_iHalfFilterLenght - j)] * l_FilterLP[j];

                m_LPFilteredDetectorData[i] = l_dSum;
            }
        }

        /// -----------------------------------------------------------------------
        /// <summary>
        /// Clear all data. Do this before a new measurement.
        /// </summary>
        public void ClearForNewMeasurement()
        {
            // clear the filter data
            m_LPFilteredDetectorData = null;
        }

        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingCheckScanQuality m_Instance;

        private CCOVector m_LPFilteredDetectorData;
    }
}


namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingDetectLaserZeroPoints //: Buchi.DataAcquisition.CDQStateRecording
    {
        /// <summary>
        /// Contains the sample numbers where a zero point was detected
        /// </summary>
        private Core.Math.CCOVector m_ZeroPoints;

        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingDetectLaserZeroPoints m_Instance;

        /// <summary>properties</summary>
        public CCOVector LaserZeroPoints { get { return m_ZeroPoints; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary>
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingDetectLaserZeroPoints();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingDetectLaserZeroPoints GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        public void Clear()
        {
            if (m_ZeroPoints != null)
            {
                m_ZeroPoints.Release();
                m_ZeroPoints = null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Detect all zero points in the laser data and store these values
        /// in a new vector.
        /// </summary>
        public void Do()
        {
            Console.WriteLine("Start detecting zero points");

            // get reference to laser channel
            CCOVector l_LaserChannel = CDQStateRecordingFilterDataPackage.GetInstance().FilteredLaser;

            // Find the zero points in the laser channel and test if PeakPeak value is ok
            if (!FindLaserZeroPoints(l_LaserChannel, out m_ZeroPoints, DQSIController.MinLaserPPAmplitude))
            {
                Console.WriteLine("laser peak-peak is bad");
                return;
            }

            // test if enough zero points are available
            if (m_ZeroPoints.Length < 2 * DQSIController.UsefulPointsPerScan)
            {
                CDQScanInfo l_ScanInfo = CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList.GetCurrent();
                string l_sError = "Not enough zero points found: " + m_ZeroPoints.Length + " , needed: " + 2 * DQSIController.UsefulPointsPerScan;
                l_ScanInfo.SetError(l_sError, EDQScanState.eErrorNotEnoughZeroPoints);
                //p_Context.ChangeState(CDQStateRecordingInvalidData.GetInstance());   // go to "not enough data"
                CDQStateRecordingInvalidData.GetInstance().Do();
                return;
            }
            
            Console.WriteLine("DQ: Zero points: " + m_ZeroPoints.Length.ToString());
            Console.WriteLine("Finished detecting zero points");

            // go on to interpolation
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Find all zero points in the laser data and store these values
        /// in a new vector. The zero-crossings are determined in a window of 
        /// 3 points width using sine-interpolation
        /// The 3 points are the 3 closest points to 0.
        /// </summary>
        /// <param name="p_LaserChannel">Contains the filtered laser data</param>
        /// <param name="p_ZeroPoints">Will be filled with the found zero points</param>
        /// <param name="p_dbMinLaserPPAmplitude">minimal peak-peak value of laser</param>
        /// <returns>True if zero points are found, else laser amplitude is not ok</returns>
        public bool FindLaserZeroPoints(CCOVector p_LaserChannel, out CCOVector p_ZeroPoints, double p_dbMinLaserPPAmplitude)
        {
            int l_iTrippleIndex;
            int l_iZeroCnt = 0;

            // create new container, large enough, will be shrinked later
            p_ZeroPoints = new CCOVector(p_LaserChannel.Length / 4);

            // get access to the laser samples
            double[] l_dbLaserData = p_LaserChannel.GetNativeBuffer();

            double l_Diff = p_LaserChannel.Max() - p_LaserChannel.Min();
            double l_Threshold = (0.5 * l_Diff) / 3;

            if (l_Threshold < p_dbMinLaserPPAmplitude)
            {
                CDQScanInfo l_ScanInfo = CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList.GetCurrent();
                string l_sError = "Bad laser amplitude, min: " + p_LaserChannel.Min() + ", max: " + p_LaserChannel.Max() + ", Threshold: " + l_Threshold + ", needed min. PP value: " + p_dbMinLaserPPAmplitude;
                l_ScanInfo.SetError(l_sError, EDQScanState.eErrorBadLaserAmplitude);
                return false;
            }

            int l_iSampleCnt = 0;
            double xis = 0.0;
            bool l_bZeroPointFound = false;

            while (l_iSampleCnt < (p_LaserChannel.Length - 3))
            {
                l_bZeroPointFound = false;

                // ignore noise values, which are below the threshold
                while (Math.Abs(l_dbLaserData[l_iSampleCnt]) < l_Threshold && l_iSampleCnt < (p_LaserChannel.Length - 3))
                {
                    l_iSampleCnt++;
                }

                // calculate next zero point
                while (!l_bZeroPointFound && l_iSampleCnt < (p_LaserChannel.Length - 3))
                {
                    // find two points around 0, a positive and a negative point
                    if (((l_dbLaserData[l_iSampleCnt + 1] > 0) && (l_dbLaserData[l_iSampleCnt + 2] <= 0)) ||
                        ((l_dbLaserData[l_iSampleCnt + 1] < 0) && (l_dbLaserData[l_iSampleCnt + 2] >= 0)))
                    {
                        // resize array if it is to short
                        if (p_ZeroPoints.Length <= l_iZeroCnt)
                        {
                            p_ZeroPoints.Resize(l_iZeroCnt + 100);  // This should be never called
                            Trace.WriteLine("The zero point array has been resized");
                        }

                        // Set tripple index to the first of the next three points
                        l_iTrippleIndex = l_iSampleCnt;

                        // Take the two points around 0 and find the closest point to 0. Increment
                        // the triple counter if necessary to get afterwards the 3 points which
                        // are closest to 0. So, the window is reduced from 4 points (2 positive,
                        // 2 negative) to the closest 3 points.
                        if (l_dbLaserData[l_iSampleCnt] > 0)
                        {
                            // negative slope
                            if ((l_dbLaserData[l_iSampleCnt + 1] + l_dbLaserData[l_iSampleCnt + 2]) > 0)
                                l_iTrippleIndex++;
                        }
                        else
                        {
                            // positive slope
                            if ((l_dbLaserData[l_iSampleCnt + 1] + l_dbLaserData[l_iSampleCnt + 2]) < 0)
                                l_iTrippleIndex++;
                        }

                        // use the three found points and do sinus interpolation
                        double y1 = l_dbLaserData[l_iTrippleIndex];
                        double y2 = l_dbLaserData[l_iTrippleIndex + 1];
                        double y3 = l_dbLaserData[l_iTrippleIndex + 2];

                        // start sinus interpolation
                        double szc = GetSign(l_dbLaserData[l_iTrippleIndex + 2]);    // szc=sign(laserf(k+1));

                        if (y2 != 0)                                // if y(2)~=0,
                        {
                            double ck = (y3 + y1) / (2 * y2);     // ck=(y(3)+y(1))/(2*y(2));

                            // ensure div 0 is not allowed
                            if (ck < 1 && ck > -1)
                            {
                                double kx = Math.Acos(ck);         // kx=acos(ck);
                                double phi =
                                    Math.Atan(                                              // phi=atan(
                                    Math.Sqrt(                                              // sqrt(
                                    Math.Abs((y2 * y2) - Math.Pow(((y3 + y1) / 2), 2)) /      // abs((y(2)^2-((y(3)+y(1))/2)^2)/
                                    Math.Pow(((y3 - y1) / 2), 2)));                         // ((y(3)-y(1))/2)^2)));
                                xis = phi / kx;                     // xis=phi/kx;
                                if (szc * GetSign(y2) == 1.0)       // if (szc*sign(y(2))==1),
                                {
                                    xis = -xis;                     // xis=-xis;  ?????             
                                }
                            }
                            else
                            {
                                Debug.WriteLine("DQ: linear interpolation");
                                xis = -2 * y2 / (y3 - y1);          // xis=-2*y(2)/(y(3)-y(1));
                            }
                        }
                        else
                        {
                            xis = 0.0;
                        }

                        if (Double.IsNaN(xis))    // set xis to 0 if a div by 0 occured
                        {
                            Console.WriteLine("DQ: Error - NaN received");  // this line should not be reached!
                            xis = 0.0;
                        }
                        // end sinus interpolation

                        p_ZeroPoints[l_iZeroCnt] = xis + l_iTrippleIndex + 1;
                        l_iZeroCnt++;
                        l_bZeroPointFound = true;

                    } // if
                    l_iSampleCnt++;
                } // while (!l_bZeroPointFound..
            } // while (l_iSampleCnt..

            // set usable length of array
            p_ZeroPoints.Resize(l_iZeroCnt - 1);  // do not save last zero! might be too close to file end (see MATLAB)

            return true;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Return sign of number.
        /// </summary>
        /// <param name="p_dbNumber">Test this number</param>
        /// <returns>sign of number</returns>
        private double GetSign(double p_dbNumber)
        {
            if (p_dbNumber > 0.0)
            {
                return 1.0;
            }
            else if (p_dbNumber < 0.0)
            {
                return -1.0;
            }
            else
            {
                return 0.0;
            }
        }
    }
}


namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingSampleAtZeroPoints //: Buchi.DataAcquisition.CDQStateRecording
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingSampleAtZeroPoints m_Instance;

        /// <summary>
        /// The interferogram contains a sample value and the timestamp of the sample 
        /// [0] sample time
        /// [1] sample data 
        ///</summary>
        private Core.Math.CCOMatrix m_InterFerogram;

        /// <summary>properties</summary>
        public CCOMatrix InterpolatedInterferogram { get { return m_InterFerogram; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingSampleAtZeroPoints();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingSampleAtZeroPoints GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        public void Clear()
        {
            if (m_InterFerogram != null)
            {
                m_InterFerogram.Release();
                m_InterFerogram = null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Find the interferogram points using the zero points from the laser
        /// data.
        /// </summary>
        public void Do()
        {
            Console.WriteLine("Start interpolating interferogram at laser zero points");

            // get reference to laser zero points
            CCOVector l_LaserZeroPoints = CDQStateRecordingDetectLaserZeroPoints.GetInstance().LaserZeroPoints;

            // get reference to measured interferogram
            CCOVector l_FilteredDetectorChannel = CDQStateRecordingFilterDataPackage.GetInstance().FilteredDetector;

            // get the samples
            FindDetectorSamples(l_LaserZeroPoints, l_FilteredDetectorChannel);

            Console.WriteLine("Finished interpolating interferogram");
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Find the interferogram points using the zero points from the laser
        /// data. Use spline.
        /// </summary>
        /// <param name="p_LaserZeroPoints">The zero poins in the laser data</param>
        /// <param name="p_FilteredDetectorChannel">The filtered detector data</param>
        public void FindDetectorSamples(
            CCOVector p_LaserZeroPoints,
            CCOVector p_FilteredDetectorChannel)
        {
            // build time axis
            CCOVector l_Time = new CCOVector(p_FilteredDetectorChannel.Length);
            double l_dbSampleFrequency = DQSIController.SamplingFrequency;
            double l_dbTimeStep = 1 / l_dbSampleFrequency;
            for (int i = 0; i < l_Time.Length; i++)
            {
                l_Time[i] = l_dbTimeStep * i;
            }

            // apply spline
            CCOVector l_LaserZero = p_LaserZeroPoints / l_dbSampleFrequency;

            // add channel delay
            l_LaserZero += DQSIController.ChannelDelay;

            CCOVector l_SampleAtZero;
            new CCOVector().FreeCubicSpline(l_Time, p_FilteredDetectorChannel, l_LaserZero, out l_SampleAtZero);

            // set sampled data
            m_InterFerogram = new CCOMatrix(p_LaserZeroPoints.Length, 2);
            m_InterFerogram.SetColVector(1, l_SampleAtZero);

            // set sampled time axis
            for (int i = 0; i < p_LaserZeroPoints.Length; i++)
            {
                m_InterFerogram[i][0] = DQSIController.GetTimeFromSample(p_LaserZeroPoints[i]);
            }
        }
    }
}

namespace Buchi.DataAcquisition
{
    public struct CDQScanWindow
    {
        public int Start;
        public int End;

        public CDQScanWindow(int p_Start, int p_End)
        {
            Start = p_Start;
            End = p_End;
        }
    } // struct DQWindow
}

namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingFindScanWindows //: Buchi.DataAcquisition.CDQStateRecording
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingFindScanWindows m_Instance;

        /// <summary>Contains the reverse scans (Nr. forward scans == reverse scans).               
        /// </summary>
        private List<CDQScanWindow> m_ReverseScans;

        /// <summary>Contains the forward scans (Nr. forward scans == reverse scans).
        /// </summary>
        private List<CDQScanWindow> m_ForwardScans;

        /// <summary>properties</summary>
        public List<CDQScanWindow> ForwardScans { get { return m_ForwardScans; } }
        public List<CDQScanWindow> ReverseScans { get { return m_ReverseScans; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingFindScanWindows();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingFindScanWindows GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        public void Clear()
        {
            if (m_ForwardScans != null)
            {
                m_ForwardScans.Clear();
            }
            if (m_ReverseScans != null)
            {
                m_ReverseScans.Clear();
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Finds the scan windows using the status byte. 
        /// </summary>
        public void Do()
        {
            Console.WriteLine("Start finding scan windows");

            // find the scan windows
            FindScanWindows();

            // test if at least one valid pair was found
            if (ForwardScans.Count == 0 || ReverseScans.Count == 0)
            {
                // go to "not enough data"
                CDQStateRecordingInvalidData.GetInstance().Do();
                return;
            }

            Console.WriteLine("Finished finding scan pairs: " + ForwardScans.Count);

            // go on isolating scans
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Finds the scan window pairs with the help of the status byte, which contains
        /// PostConditons: Only for / rev pairs with enough useful points are listed
        /// </summary>
        public void FindScanWindows()
        {
            // get link to interpolated interferogram
            CCOMatrix l_InterFerogram = CDQStateRecordingSampleAtZeroPoints.GetInstance().InterpolatedInterferogram;

            // get the list with the scan windows
            CDQScanList l_ScanList = CDQStateRecordingFilterDataPackage.GetInstance().ScanList;
            m_ForwardScans = new List<CDQScanWindow>();
            m_ReverseScans = new List<CDQScanWindow>();

            // get usefull points of one scan
            int l_iScanMin = DQSIController.UsefulPointsPerScan;

            // build the scan windows
            CCOVector l_LaserZeroPoints = CDQStateRecordingDetectLaserZeroPoints.GetInstance().LaserZeroPoints;
            int l_iStartStample = 0;    // start in sampled array
            int l_iEndSample = 0;    // start in sampled array
            int l_ScanLength = 0;
            eDirection l_Direction = eDirection.Unknown;
            eDirection l_ScanDirection = eDirection.Unknown;

            // build the scans
            for (int i = 0; i < l_ScanList.Count; i++)
            {
                // get shiftet windows start and end in sampled array
                l_iStartStample = l_iEndSample;
                l_iEndSample = GetEndIndex(l_ScanList.GetEndData(i), l_LaserZeroPoints);
                l_ScanDirection = l_ScanList.GetDirectionFromData(l_ScanList.GetEndData(i));
                l_ScanLength = l_iEndSample - l_iStartStample;

                // add forward scan
                if (l_ScanDirection == eDirection.Forward && l_ScanLength >= l_iScanMin &&
                    (l_Direction == eDirection.Unknown || l_Direction == eDirection.Reverse))
                {
                    if (m_ForwardScans.Count != m_ReverseScans.Count)   // test if last added scan was a reverse scan 
                    {
                        m_ForwardScans.RemoveAt(m_ForwardScans.Count - 1);
                    }
                    CDQScanWindow l_ForwardWindow = new CDQScanWindow(l_iStartStample, l_iEndSample);
                    m_ForwardScans.Add(l_ForwardWindow);
                    Console.WriteLine("- Forward Start value: " + l_LaserZeroPoints[l_iStartStample] + " at: " + l_iStartStample);
                    l_Direction = eDirection.Forward;
                    Debug.Assert(m_ForwardScans.Count == m_ReverseScans.Count + 1);
                }
                // add reverse scan
                else if (l_ScanDirection == eDirection.Reverse && l_Direction == eDirection.Forward &&
                    l_ScanLength >= l_iScanMin)
                {
                    // Debug.Assert(l_iEndSample - l_iStartStample > 3900);
                    CDQScanWindow l_ReverseWindow = new CDQScanWindow(l_iStartStample, l_iEndSample);
                    m_ReverseScans.Add(l_ReverseWindow);
                    Console.WriteLine("- Reverse Start value: " + l_LaserZeroPoints[l_iStartStample] + " at: " + l_iStartStample);
                    l_Direction = eDirection.Reverse;
                    Debug.Assert(m_ForwardScans.Count == m_ReverseScans.Count);
                }
                else
                {
                    if (l_ScanLength < l_iScanMin)
                    {
                        CDQScanInfo l_ScanInfo = CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList.GetCurrent();
                        string l_sError = "FindScanWindows: Scan " + i + " is too short, length: " + l_ScanLength + " (start: " + l_iStartStample + ", end: " + l_iEndSample + "), needed: " + l_iScanMin;
                        l_ScanInfo.SetError(l_sError, EDQScanState.eErrorScanWindowTooShort);
                        // Occures at end of package or if scan is bad
                    }
                    else if (l_ScanDirection == eDirection.Reverse && l_Direction != eDirection.Forward)
                    {
                        // occrures after forward scan was too short
                        Console.WriteLine("DQ: FindScanWindows - Reverse Scan ignored");
                    }
                    l_Direction = eDirection.Unknown;
                }
                l_iEndSample++;
            }

            // test if a single forward was added as last scan
            if (m_ForwardScans.Count == m_ReverseScans.Count + 1)
            {
                m_ForwardScans.RemoveAt(m_ForwardScans.Count - 1);
            }

            Debug.Assert(m_ForwardScans.Count == m_ReverseScans.Count);
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Gets the vector index.
        /// p_Vector[index] < p_Value && p_Vector[index + 1 ] >= p_Value
        /// </summary>
        /// <param name="p_Value">Search this value</param>
        /// <param name="p_Vector">Search in this vector</param>
        /// <returns>Vector index</returns>
        public int GetEndIndex(double p_Value, CCOVector p_Vector)
        {
            Debug.Assert(p_Vector != null && p_Vector.Length > 0);

            if (p_Vector[0] > p_Value)
            {
                return 0;
            }
            else if (p_Vector[p_Vector.Length - 1] < p_Value)
            {
                return p_Vector.Length - 1;
            }
            else
            {
                int i = 0;
                double l_Current = p_Vector[0];

                while (l_Current < p_Value && i < p_Vector.Length)
                {
                    l_Current = p_Vector[i];
                    i++;
                }
                i -= 2;      // get the index before the value
                return i;
            }
        }
    }
}

namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingGetSpeedVector //: Buchi.DataAcquisition.CDQStateRecording
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingGetSpeedVector m_Instance;

        /// <summary>
        /// Contains the speed values of the wedge drive. The speed is measured by analyzing
        /// the time difference of two raw datas. The speed should be constant during a scan.
        /// </summary>
        private CCOVector m_SpeedVector;

        /// <summary>properties</summary>
        public CCOVector SpeedVector { get { return m_SpeedVector; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingGetSpeedVector();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingGetSpeedVector GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        public void Clear()
        {
            if (m_SpeedVector != null)
            {
                m_SpeedVector.Release();
                m_SpeedVector = null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        ///Get speed vector 
        /// </summary>
        public void Do()
        {
            Console.WriteLine("Start getting speed vector");

            // get link to interpolated interferogram
            CCOMatrix l_InterFerogram = CDQStateRecordingSampleAtZeroPoints.GetInstance().InterpolatedInterferogram;

            // build speed vector
            m_SpeedVector = BuildSpeedVector(l_InterFerogram);

            Console.WriteLine("Finished getting speed vector");
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Builds the speed vector.
        /// use same entry for speed[0] and speed[1]
        /// </summary>
        /// <param name="p_InterFerogram">Use this interferogram</param>
        /// <returns></returns>
        public CCOVector BuildSpeedVector(CCOMatrix p_InterFerogram)
        {
            /// Contains the speed values of the wedge drive. The speed is measured by analyzing
            /// the time difference of two samples. The speed should be constant during a scan and
            /// it should slow down at the turning points.
            int l_iVectorLength = p_InterFerogram.nrow;
            double l_dbDiff = 0.0;

            CCOVector l_SpeedVector = new CCOVector(p_InterFerogram.nrow);

            // Fill speed vector
            for (int l_iCnt = 0; l_iCnt < l_iVectorLength - 1; l_iCnt++)
            {
                l_dbDiff = p_InterFerogram[l_iCnt + 1][0] - p_InterFerogram[l_iCnt][0];
                if (l_dbDiff != 0.0)
                {
                    l_SpeedVector[l_iCnt + 1] = 1.0 / l_dbDiff;
                }
                else
                {
                    l_SpeedVector[l_iCnt + 1] = 0.0;
                }
            }
            // use same entry for speed[0] and speed[1]
            l_SpeedVector[0] = l_SpeedVector[1];

            return l_SpeedVector;
        }
    }
}

namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingFindPeaks //: Buchi.DataAcquisition.CDQStateRecording
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingFindPeaks m_Instance;

        /// <summary>Contains the forward index scan peaks</summary>
        private CCOVector m_PeaksForward;

        /// <summary>Contains the reverse index scan peaks</summary>
        private CCOVector m_PeaksReverse;

        /// <summary>Window width for the interferogram peak search</summary>
        private int m_iPeakSearchWindow;

        /// <summary>Factor of zero filling for the method find peak</summary>
        private int m_iZeroFillingFindPeaks;

        /// <summary>Set this flag true if the the max. peak of the interferogram
        /// is a positive value.</summary>
        private bool m_bPosMaxPeak = false;

        /// <summary>Peak type</summary>
        private enum EDQPeakType { eMin = -1, eMax = 1 };

        /// <summary>properties</summary>
        public CCOVector PeaksForward { get { return m_PeaksForward; } }
        public CCOVector PeaksReverse { get { return m_PeaksReverse; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingFindPeaks();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingFindPeaks GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        public void Clear()
        {
            if (m_PeaksForward != null)
            {
                m_PeaksForward.Release();
                m_PeaksForward = null;
            }
            if (m_PeaksReverse != null)
            {
                m_PeaksReverse.Release();
                m_PeaksReverse = null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Find the scan peaks. If a peak has to much deviation the scan pair
        /// will be ignored.
        /// </summary>
        public void Do()
        {
            Console.WriteLine("Start finding peaks");

            // get links
            List<CDQScanWindow> l_ForwardWindows = CDQStateRecordingFindScanWindows.GetInstance().ForwardScans;
            List<CDQScanWindow> l_ReverseWindows = CDQStateRecordingFindScanWindows.GetInstance().ReverseScans;
            CCOMatrix l_InterFerogram = CDQStateRecordingSampleAtZeroPoints.GetInstance().InterpolatedInterferogram;
            Debug.Assert(l_ForwardWindows.Count == l_ReverseWindows.Count);

            m_iPeakSearchWindow = DQSIController.PeakSearchWindow;
            m_iZeroFillingFindPeaks = DQSIController.ZeroFillingFindPeaks;
            m_PeaksForward = new CCOVector(l_ForwardWindows.Count);
            m_PeaksReverse = new CCOVector(l_ForwardWindows.Count);

            int l_iStartFor, l_iEndFor, l_iPeakFor;
            int l_iStartRev, l_iEndRev, l_iPeakRev;
            int l_iLeftSide;

            // get forward scan params
            l_iStartFor = l_ForwardWindows[0].Start;
            l_iEndFor = l_ForwardWindows[0].End;
            l_iPeakFor = FindPeak(l_InterFerogram, l_iStartFor, l_iEndFor, eDirection.Forward);

            // get reverse scan params
            l_iStartRev = l_ReverseWindows[0].Start;
            l_iEndRev = l_ReverseWindows[0].End;
            l_iPeakRev = FindPeak(l_InterFerogram, l_iStartRev, l_iEndRev, eDirection.Reverse);
            l_iLeftSide = l_iEndRev - l_iStartRev - l_iPeakRev;

            // add peak info
            CDQScanInfo l_ScanInfo = CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList.GetCurrent();
            l_ScanInfo.PeakForward = l_iPeakFor - l_iStartFor;
            l_ScanInfo.PeakReverse = l_iStartRev - l_iPeakRev;
            l_ScanInfo.PeakForwardValue = l_InterFerogram[l_iStartFor + l_iPeakFor][1];
            l_ScanInfo.PeakReverseValue = l_InterFerogram[l_iStartRev + l_iPeakRev][1];

            // test peak deviation and add good scan pairs
            if (IsPeakDeviationOk(l_iPeakFor, eDirection.Forward) &&
                IsPeakDeviationOk(l_iLeftSide, eDirection.Reverse))
            {
                m_PeaksForward[0] = l_iStartFor + l_iPeakFor;
                m_PeaksReverse[0] = l_iStartRev + l_iPeakRev;
                Console.WriteLine("DQ: Scan pair added, forward peak: " + l_iPeakFor + " reverse peak: " + l_iPeakRev);
            }
            else
            {
                //p_Context.ChangeState(CDQStateRecordingInvalidData.GetInstance());  // peak deviation
                CDQStateRecordingInvalidData.GetInstance().Do();
                return;
            }

            Console.WriteLine("Finished finding peaks");

            // go on averaging interferograms
        }

        /// -------------------------------------------------------------------
        /// <summary>
        ///  Test if peak is within the given tolerance deviation. 
        /// </summary>
        /// <param name="p_iPeakIndex">Test peak index</param>
        /// <param name="p_Directon">Direction of scan</param>
        /// <returns>Returns true if peak deviation is ok</returns>
        private bool IsPeakDeviationOk(int p_iPeakIndex, eDirection p_Directon)
        {
            // test forward scan
            if (eDirection.Forward == p_Directon)
            {
                if (Math.Abs(p_iPeakIndex - DQSIController.PeakTargetForwardLeftSide) <= DQSIController.MaxPeakDeviation)
                {
                    return true;
                }
                else
                {
                    CDQScanInfo l_ScanInfo = CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList.GetCurrent();
                    string l_sError = "Forward has too much peak deviation. Peak: " + p_iPeakIndex +
                        " Target: " + DQSIController.PeakTargetForwardLeftSide +
                        " (+/-" + DQSIController.MaxPeakDeviation + ")";
                    l_ScanInfo.SetError(l_sError, EDQScanState.eErrorPeakDeviationForward);
                    return false;
                }
            }
            // test reverse scan
            else if (eDirection.Reverse == p_Directon)
            {
                if (Math.Abs(p_iPeakIndex - DQSIController.PeakTargetReverseLeftSide) <= DQSIController.MaxPeakDeviation)
                {
                    return true;
                }
                else
                {
                    CDQScanInfo l_ScanInfo = CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList.GetCurrent();
                    string l_sError = "Reverse has too much peak deviation. Peak: " + p_iPeakIndex +
                            " Target: " + DQSIController.PeakTargetReverseLeftSide +
                            " (+/-" + DQSIController.MaxPeakDeviation + ")";
                    l_ScanInfo.SetError(l_sError, EDQScanState.eErrorPeakDeviationReverse);
                    return false;
                }
            }
            else
            {
                Console.WriteLine("DQ: Unknown scan direction");
                return false;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Find the peak in one scan.
        /// 1. Use zerofilling
        /// 2. Get max. in searchwindow
        /// 3. Get local. max to both sides of max.
        /// 4. Take the bigger of the calculated max.
        /// 5. Find the local min. between the to max. peaks
        /// 6. Take the closest sample
        /// Return MinInt if peak can not be found (e.g. all peaks are 0)
        /// </summary>
        /// <param name="p_InterFerogram">Search this interferogram</param>
        /// <param name="p_iAreaStart">Begin search at this point</param>
        /// <param name="p_iAreaEnd">End search at this point</param>
        /// <returns>Peak index</returns>
        private int FindPeak(CCOMatrix p_InterFerogram,
                             int p_iAreaStart,
                             int p_iAreaEnd,
                             eDirection p_Direction)
        {
            // get the supposed peak
            int l_iPeak;

            if (p_Direction == eDirection.Forward)
            {
                l_iPeak = p_iAreaStart + DQSIController.PeakTargetForwardLeftSide;
            }
            else
            {
                l_iPeak = p_iAreaEnd + 1 - (DQSIController.PeakTargetReverseLeftSide - 1);
            }

            // get the search window
            int l_iSearchWinStart = l_iPeak - 1 - (m_iPeakSearchWindow / 2);   // -1 used for compatibility with MATLAB
            CCOVector l_Real = p_InterFerogram.GetColVector(1).GetSlice(l_iSearchWinStart, m_iPeakSearchWindow);

            // do the zero filling in the search window vector
            CCOFFT l_FFT = new CCOFFT();
            CCOVector l_Window = l_FFT.ZeroFilling(l_Real, m_iZeroFillingFindPeaks);

            if (m_bPosMaxPeak)
            {
                l_Window = l_Window * -1;  // invert the sign if the interferogram has a positive max. peak 
            }

            // find the absolut max in the window
            int l_EndWindow = l_Window.Length - 1;
            int l_MaxIndex;
            l_Window.MaxAt(out l_MaxIndex);

            // step left until local min and the following max is found
            int l_MinLeft = StepToNextPeak(l_MaxIndex, 0, l_Window, EDQPeakType.eMin);
            int l_MaxLeft = StepToNextPeak(l_MinLeft, 0, l_Window, EDQPeakType.eMax);

            // step right until local min and the following max is found
            int l_MinRight = StepToNextPeak(l_MaxIndex, l_EndWindow, l_Window, EDQPeakType.eMin);
            int l_MaxRight = StepToNextPeak(l_MinRight, l_EndWindow, l_Window, EDQPeakType.eMax);

            // find the bigger max
            int l_Start, l_End;
            if (l_Window[l_MaxLeft] > l_Window[l_MaxRight])
            {
                l_Start = l_MaxLeft;
                l_End = l_MaxIndex;
            }
            else
            {
                l_Start = l_MaxIndex;
                l_End = l_MaxRight;
            }

            // find the absolut minimum
            int l_MinIndex;
            CCOVector l_Selection = new CCOVector(l_Window.Length);
            l_Selection.FillSelection(l_Start, l_End - l_Start + 1, 1);
            l_Window.MinAt(out l_MinIndex, l_Selection);

            // get the two closest samples to the found minimum and chose the smaller
            int l_Floor = (int)Math.Floor(l_MinIndex * (1.0 / m_iZeroFillingFindPeaks));
            int l_Ceiling = (int)Math.Ceiling(l_MinIndex * (1.0 / m_iZeroFillingFindPeaks));
            int l_FloorIndex = l_iPeak - (m_iPeakSearchWindow / 2) + l_Floor - 1;   // -1 used for compatibility with MATLAB
            int l_CeilingIndex = l_iPeak - (m_iPeakSearchWindow / 2) + l_Ceiling - 1;

            if (p_InterFerogram[l_FloorIndex][1] <= p_InterFerogram[l_CeilingIndex][1])
            {
                Console.WriteLine("DQ: Peak: " + (l_FloorIndex - p_iAreaStart) + " value: " + (p_InterFerogram[l_FloorIndex][1]));
                return (l_FloorIndex - p_iAreaStart);
            }
            else
            {
                Console.WriteLine("DQ: Peak: " + (l_CeilingIndex - p_iAreaStart) + " value: " + (p_InterFerogram[l_CeilingIndex][1]));
                return (l_CeilingIndex - p_iAreaStart);
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Step from a start point to an end point in a vector and search 
        /// for a local peak. Return the vector index of the found peak. This
        /// method can be used to search local min or max. If no peak is found,
        /// the end index will be returned.
        /// </summary>
        /// <param name="p_iStart">Start index</param>
        /// <param name="p_iEnd">End index</param>
        /// <param name="p_Vector">Search in this vector</param>
        /// <param name="p_PeakType">Min or Max type</param>
        /// <returns>Peak index</returns>
        private int StepToNextPeak(int p_iStart, int p_iEnd, CCOVector p_Vector, EDQPeakType p_PeakType)
        {
            // test boundaries
            if (p_iStart == p_iEnd)
            {
                return p_iEnd;
            }

            int l_iPeakType = (int)p_PeakType;
            int i = p_iStart;
            int l_Increment = (p_iEnd - p_iStart) / Math.Abs(p_iEnd - p_iStart);  // 1 or -1
            double l_dbTemp;

            while (i != p_iEnd)
            {
                l_dbTemp = p_Vector[i];
                i += l_Increment;        // +1 or -1

                if ((p_PeakType == EDQPeakType.eMax) &&
                    (p_Vector[i] < l_dbTemp))
                {
                    return i -= l_Increment;
                }
                else if ((p_PeakType == EDQPeakType.eMin) &&
                    (p_Vector[i] > l_dbTemp))
                {
                    return i -= l_Increment;
                }
            }
            return p_iEnd;
        }
    }
}

namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingIsolateScans //: Buchi.DataAcquisition.CDQStateRecording
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingIsolateScans m_Instance;

        /// <summary>Speed vector</summary>
        private CCOVector m_Speed;

        /// <summary>[%] Maximal allowed deviation of velocity of wedge drive in percentage</summary>
        private double m_dbMaxVelocityDeviationPercentage;

        /// <summary>Contains the forward scans (Nr. forward scans == reverse scans).
        /// m_ForwardScans[0] to [scan number]: forward scan
        /// forward scan  [0] to [scan length]: sample value
        /// </summary>
        private CCOMatrix m_ForwardScans;

        /// <summary>Contains the reverse scans (Nr. forward scans == reverse scans).
        /// m_ReverseScans[0] to [scan number]: reverse scan
        /// reverse scan  [0] to [scan length]: sample value
        /// </summary>
        private CCOMatrix m_ReverseScans;

        /// <summary>Contains the forward scan reference</summary>
        private CCOVector m_ForwardReference = null;

        /// <summary>Contains the reverse scan reference</summary>
        private CCOVector m_ReverseReference = null;

        /// <summary>Window width for the centering</summary>
        private int m_iIsolateScanWindow;

        /// <summary>Number of relevant points on the left side (forward scan, small side) of the peak</summary>
        private int m_iUsefulLeftPoints;

        /// <summary>Size of the interferogram (full or half scan)</summary>
        private int m_iInterferogramSize;

        /// <summary>properties</summary>
        public CCOMatrix ForwardScans { get { return m_ForwardScans; } }
        public CCOMatrix ReverseScans { get { return m_ReverseScans; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingIsolateScans();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingIsolateScans GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        public void Clear()
        {
            if (m_ForwardScans != null)
            {
                m_ForwardScans.Release();
                m_ForwardScans = null;
            }
            if (m_ReverseScans != null)
            {
                m_ReverseScans.Release();
                m_ReverseScans = null;
            }
            if (m_Speed != null)
            {
                m_Speed.Release();
                m_Speed = null;
            }
            if (m_ForwardReference != null)
            {
                m_ForwardReference.Release();
                m_ForwardReference = null;
            }
            if (m_ReverseReference != null)
            {
                m_ReverseReference.Release();
                m_ReverseReference = null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Shift the scans to the same peak point and reverse the "reverse" scans.
        /// Two tests are done. 
        /// - Test if enough data points are given
        /// - Test speed within the useful data point range
        /// </summary>
        public void Do()
        {
            Console.WriteLine("Start isolating single scans");

            // get links
            m_iIsolateScanWindow = DQSIController.IsolateScanWindow;
            m_iUsefulLeftPoints = DQSIController.UsefulLeftPoints - 1; // array starts at 0
            m_iInterferogramSize = DQSIController.UsefulPointsPerScan;
            m_dbMaxVelocityDeviationPercentage = DQSIController.MaxVelocityDeviationPercentage;
            List<CDQScanWindow> l_ForwardScanList = CDQStateRecordingFindScanWindows.GetInstance().ForwardScans;
            List<CDQScanWindow> l_ReverseScanList = CDQStateRecordingFindScanWindows.GetInstance().ReverseScans;
            Debug.Assert(l_ForwardScanList.Count == l_ReverseScanList.Count);
            CCOMatrix l_InterFerogram = CDQStateRecordingSampleAtZeroPoints.GetInstance().InterpolatedInterferogram;
            CCOVector l_PeaksFor = CDQStateRecordingFindPeaks.GetInstance().PeaksForward;
            CCOVector l_PeaksRev = CDQStateRecordingFindPeaks.GetInstance().PeaksReverse;
            m_Speed = CDQStateRecordingGetSpeedVector.GetInstance().SpeedVector;

            int l_iStart, l_iLength, l_iShiftedStart, l_iPeak;
            int l_iShift = 0;
            m_ForwardScans = new CCOMatrix(l_ForwardScanList.Count, 1);
            m_ReverseScans = new CCOMatrix(l_ForwardScanList.Count, 1);

            // get start, end, ...
            l_iStart = l_ForwardScanList[0].Start;
            l_iLength = l_ForwardScanList[0].End - l_iStart;
            l_iPeak = (int)l_PeaksFor[0] - l_iStart;
            CDQScanInfo l_ScanInfo = CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList.GetCurrent();

            // test if enough points are available for forward scan
            if (!EnoughPoints(l_iPeak, l_iLength))
            {
                string l_sError = "Bad forward scan, peak: " + l_iPeak + ", scan length: " + l_iLength + ", needed useful left points: " + m_iUsefulLeftPoints;
                l_ScanInfo.SetError(l_sError, EDQScanState.eErrorBadForwardScanPeak);
                // get next data package
                CDQStateRecordingInvalidData.GetInstance().Do();
                return;
            }

            // get first forward scan window as reference
            if (m_ForwardReference == null)
            {
                int l_iWindowStart = l_iStart + l_iPeak - (m_iIsolateScanWindow / 2);
                CCOMatrix l_WinSlice = l_InterFerogram.GetSlice(l_iWindowStart, m_iIsolateScanWindow, 0, 2);
                m_ForwardReference = l_WinSlice.GetColVector(1);  // todo.stad more effiz: GetColVector - avoid one copy
            }
            else
            {
                l_iShift = ComputeShift(l_InterFerogram, m_ForwardReference, l_iStart, l_iPeak);
                l_ScanInfo.ShiftForward = l_iShift;
                Debug.WriteLine("DQ: Forward interferogram was shifted: " + l_iShift);
            }

            // test speed and save forward interferogram
            l_iShiftedStart = l_iStart + l_iPeak + l_iShift - m_iUsefulLeftPoints;
            if (!IsSpeedOk(l_iShiftedStart, m_iInterferogramSize))
            {
                //p_Context.ChangeState(CDQStateRecordingInvalidData.GetInstance());
                CDQStateRecordingInvalidData.GetInstance().Do();
                return;
            }
            CCOMatrix l_Slice = l_InterFerogram.GetSlice(l_iShiftedStart, m_iInterferogramSize, 0, 2);
            m_ForwardScans[0] = l_Slice.GetColVector(1);  // todo.stad more effiz: GetColVector - avoid one copy

            // get first reverse scan window as reference
            l_iStart = l_ReverseScanList[0].Start;
            l_iLength = l_ReverseScanList[0].End - l_iStart;
            l_iPeak = (int)l_PeaksRev[0] - l_iStart;
            Debug.WriteLine($"RevScan: start = {l_iStart}, peak = {l_PeaksRev[0]}");
            // test if enough points are available
            if (!EnoughPoints(l_iLength - l_iPeak, l_iLength))
            {
                string l_sError = "Bad reverse scan, peak: " + l_iPeak + ", scan length: " + l_iLength + ", needed useful left points: " + m_iUsefulLeftPoints;
                l_ScanInfo.SetError(l_sError, EDQScanState.eErrorBadReverseScanPeak);
                // get next data package
                CDQStateRecordingInvalidData.GetInstance().Do();
                return;
            }

            if (m_ReverseReference == null)
            {
                int l_iWindowStart = l_iStart + 1 + l_iPeak - (m_iIsolateScanWindow / 2);    // + 1 for reverse scan
                CCOMatrix l_WinSlice = l_InterFerogram.GetSlice(l_iWindowStart, m_iIsolateScanWindow, 0, 2);
                m_ReverseReference = l_WinSlice.GetColVector(1);  // todo.stad more effiz: GetColVector - avoid one copy
            }
            else
            {
                l_iShift = ComputeShift(l_InterFerogram, m_ReverseReference, l_iStart + 1, l_iPeak); // + 1 for reverse scan
                l_ScanInfo.ShiftReverse = l_iShift;
                Console.WriteLine("DQ: Reverse interferogram was shifted: " + (-l_iShift));  // use inverse value for comp. with Matlab code
            }

            // test speed and save reverse interferogram
            l_iShiftedStart = l_iStart + l_iPeak + l_iShift - (m_iInterferogramSize - m_iUsefulLeftPoints) + 1;
            if (!IsSpeedOk(l_iShiftedStart, m_iInterferogramSize))
            {
                //p_Context.ChangeState(CDQStateRecordingInvalidData.GetInstance());
                CDQStateRecordingInvalidData.GetInstance().Do();
                return;
            }
            l_Slice = l_InterFerogram.GetSlice(l_iShiftedStart, m_iInterferogramSize, 0, 2);
            m_ReverseScans[0] = l_Slice.GetColVector(1).Reverse();  // todo.stad more effiz: GetColVector - avoid one copy

            m_ForwardScans.Resize(1, m_iInterferogramSize);
            m_ReverseScans.Resize(1, m_iInterferogramSize);

            // go on averaging interferograms
            Console.WriteLine("Finished isolating scans");
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Test if enough points are available (length) and if enough points
        /// are given left from the peak.
        /// </summary>
        /// <param name="l_iPeak">The peak</param>
        /// <param name="l_iLength">given length</param>
        /// <returns>True if enough points are given</returns>
        bool EnoughPoints(int l_iPeak, int l_iLength)
        {
            if ((l_iPeak < m_iUsefulLeftPoints) ||
                ((l_iLength - l_iPeak - 1) < (m_iInterferogramSize - m_iUsefulLeftPoints + 1)))
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        ///  Compare the given interferogram with a reference and shift it +/- 1
        ///  point if necessary.
        /// </summary>
        /// <param name="p_InterFerogram">Shift this interferogram</param>
        /// <param name="p_Reference">This is the reference interferogram</param>
        /// <param name="p_iAreaStart">Start of interferogram</param>
        /// <param name="p_iPeakIndex">Peak index</param>
        /// <returns>The best matching shift position</returns>
        private int ComputeShift(CCOMatrix p_InterFerogram, CCOVector p_Reference, int p_iAreaStart, int p_iPeakIndex)
        {
            double l_dbSmallestDeviation = double.MaxValue;
            int l_iBestIndex = 0;
            CCOMatrix l_PeakWindow;

            // compute three norms
            for (int l_iShiftIndex = -1; l_iShiftIndex < 2; l_iShiftIndex++)
            {
                int l_StartRow = p_iAreaStart + p_iPeakIndex + l_iShiftIndex - m_iIsolateScanWindow / 2;
                l_PeakWindow = p_InterFerogram.GetSlice(l_StartRow, p_Reference.Length, 0, p_InterFerogram.ncol);
                CCOVector l_Diff = p_Reference - l_PeakWindow.GetColVector(1); // todo.stad could be more efficient

                // norm vector
                double l_dbNorm = l_Diff.Sqr().Sum();
                if (l_dbNorm < l_dbSmallestDeviation)
                {
                    l_dbSmallestDeviation = l_dbNorm;
                    l_iBestIndex = l_iShiftIndex;
                }
            }

            return l_iBestIndex;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Test if speed is ok
        /// </summary>
        /// <param name="p_iStart">start of speed test interval</param>
        /// <param name="l_iLength">length of speed test interval</param>
        /// <returns>True if speed deviation is within tolerance</returns>
        public bool IsSpeedOk(int p_iStart, int l_iLength)
        {
            // get the average speed
            double m_dbAverageSpeed = GetAverageSpeed(p_iStart, l_iLength);
            Console.WriteLine($"Average Speed: {m_dbAverageSpeed}");

            // is speed ok?
            if (!IsSpeedWithinTolerance(p_iStart, l_iLength, m_dbAverageSpeed))
            {
                // ignore this scan pair  
                return false;
            }
            else
            {
                return true;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Tests if a chosen speed vector is within a certain tolerance.
        /// </summary>
        /// <param name="p_Start">Start index of test range</param>
        /// <param name="p_iLength">length of range</param>
        /// <param name="p_dbAverage">The average speed</param>
        /// <returns>True if the range in the speed vector is within the tolerance</returns>
        public bool IsSpeedWithinTolerance(int p_iStart, int p_iLength, double p_dbAverage)
        {
            double dbLimit = p_dbAverage * m_dbMaxVelocityDeviationPercentage / 100.0;

            for (int i = p_iStart; i < p_iStart + p_iLength; i++)
            {
                if (Math.Abs(m_Speed[i] - p_dbAverage) > dbLimit)
                {
                    CDQScanInfo l_ScanInfo = CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList.GetCurrent();
                    string l_sError = "Bad speed at: " + i + " (start: " + p_iStart + ", length: " + p_iLength + ", speed: " + m_Speed[i] + "), average speed: " + p_dbAverage + ", tolerance: " + m_dbMaxVelocityDeviationPercentage + "%";
                    l_ScanInfo.SetError(l_sError, EDQScanState.eErrorBadSpeed);
                    return false;
                }
            }
            return true;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Gets the average speed of a interval.
        /// </summary>
        /// <param name="p_iStart">Start point in tested vector</param>
        /// <param name="p_iLength">Length of tested range</param>
        /// <returns>average</returns>
        public double GetAverageSpeed(int p_iStart, int p_iLength)
        {
            double l_dbSum = 0.0;

            for (int i = p_iStart; i < p_iStart + p_iLength; i++)
            {
                l_dbSum += m_Speed[i];
            }
            return (l_dbSum / p_iLength);
        }


        /// <summary>
        /// ClearForNewMeasurement
        /// </summary>
        public void ClearForNewMeasurement()
        {
            m_ForwardReference = null;
            m_ReverseReference = null;
        }
    }
}

namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingAverageScans //: Buchi.DataAcquisition.CDQStateRecording
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingAverageScans m_Instance;

        /// <summary>contains the average scan of all reverse scans</summary>
        private CCOVector m_ReverseInterferogram;

        /// <summary>contains the average scan of all forward scans</summary>
        private CCOVector m_ForwardInterferogram;

        public CCOVector ForwardInterferogram { get { return m_ForwardInterferogram; } }
        public CCOVector ReverseInterferogram { get { return m_ReverseInterferogram; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingAverageScans();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingAverageScans GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Calcultate the average of the scans. There must be the same number of
        /// forward and reverse scans.
        /// </summary>
        public void Do()
        {
            if (DQSIController.NoiseTest)
            {
                // set counter to 0 -> no averaging effect for noise test
                CDQStateRecordingCenterAveraged.GetInstance().ScanPairCount = 0;
                ClearForNewMeasurement();
            }
            // calc average
            CalculateAverage();

            // read next package if scan number is not reached
            if (CDQStateRecordingCenterAveraged.GetInstance().ScanPairCount < DQSIController.ScanPairTotal &&
                !DQSIController.NoiseTest)
            {
                // nothing to do
            }
            else
            {
                // center average
                CDQStateRecordingCenterAveraged.GetInstance().Do();
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Clear container for new measurement sequence
        /// </summary>
        public void ClearForNewMeasurement()
        {
            m_ReverseInterferogram = null;
            m_ForwardInterferogram = null;
        }

        public void Clear()
        {
            if (m_ForwardInterferogram != null)
            {
                m_ForwardInterferogram.Release();
                m_ForwardInterferogram = null;
            }
            if (m_ReverseInterferogram != null)
            {
                m_ReverseInterferogram.Release();
                m_ReverseInterferogram = null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Calcultate the average of the scans. There must be the same number of
        /// forward and reverse scans.
        /// </summary>
        private void CalculateAverage()
        {
            Console.WriteLine("Start averaging scans of one package");

            // get links to scan arrays
            CCOMatrix l_ForwardScans = CDQStateRecordingIsolateScans.GetInstance().ForwardScans;
            CCOMatrix l_ReverseScans = CDQStateRecordingIsolateScans.GetInstance().ReverseScans;
            int l_iScanPairCount = CDQStateRecordingCenterAveraged.GetInstance().ScanPairCount;
            Debug.Assert(l_ForwardScans.nrow == l_ReverseScans.nrow);

            // create new containers
            if (m_ForwardInterferogram == null && m_ReverseInterferogram == null)
            {
                m_ForwardInterferogram = new CCOVector(l_ForwardScans.ncol);
                m_ReverseInterferogram = new CCOVector(l_ReverseScans.ncol);
            }

            // calc number of needed interferograms
            int l_iNeededScanNr = l_ForwardScans.nrow;
            int l_iScanPairTotal = DQSIController.ScanPairTotal;
            if (l_iNeededScanNr + l_iScanPairCount > l_iScanPairTotal)
            {
                l_iNeededScanNr = l_iScanPairTotal - l_iScanPairCount;
            }

            // compute average forward interferogram
            int l_iNewScanPairCount = l_iNeededScanNr + l_iScanPairCount;
            double l_dbSum = 0.0;

            Debug.Print("Averaged Scans with " + l_iNewScanPairCount + " scans.");

            for (int l_iDataPointCnt = 0; l_iDataPointCnt < l_ForwardScans.ncol; l_iDataPointCnt++)
            {
                l_dbSum = 0.0;
                for (int l_iScanCnt = 0; l_iScanCnt < l_iNeededScanNr; l_iScanCnt++)
                {
                    l_dbSum += l_ForwardScans[l_iScanCnt][l_iDataPointCnt];
                }
                // add to existing average
                m_ForwardInterferogram[l_iDataPointCnt] = (((double)m_ForwardInterferogram[l_iDataPointCnt] * (double)l_iScanPairCount) + l_dbSum) /
                    (double)l_iNewScanPairCount;
            }

            // compute average reverse interferogram
            for (int l_iDataPointCnt = 0; l_iDataPointCnt < l_ReverseScans.ncol; l_iDataPointCnt++)
            {
                l_dbSum = 0.0;
                for (int l_iScanCnt = 0; l_iScanCnt < l_iNeededScanNr; l_iScanCnt++)
                {
                    l_dbSum += l_ReverseScans[l_iScanCnt][l_iDataPointCnt];
                }
                // add to existing average
                m_ReverseInterferogram[l_iDataPointCnt] = (((double)m_ReverseInterferogram[l_iDataPointCnt] * (double)l_iScanPairCount) + l_dbSum) /
                    (double)l_iNewScanPairCount;
            }

            CDQStateRecordingCenterAveraged.GetInstance().ScanPairCount = l_iNewScanPairCount;

            Console.WriteLine("Finished averaging scans of one package - Total: " + l_iNewScanPairCount);

        }
    }
}

namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingCenterAveraged //: Buchi.DataAcquisition.CDQStateRecording
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingCenterAveraged m_Instance;

        /// <summary>contains the centered average reverse scan</summary>
        private CCOInterferogram m_CenteredReverse;

        /// <summary>contains the centered average forward scan</summary>
        private CCOInterferogram m_CenteredForward;

        /// <summary>Zero filling used for center the average</summary>
        private int m_iZeroFilling;

        /// <summary>Number of scan pairs which were already used to calculate the current average</summary>
        private int m_iScanPairCount = 0;

        /// <summary>Properties</summary>
        public CCOInterferogram CenteredForward { get { return m_CenteredForward; } set { m_CenteredForward = value; } }
        public CCOInterferogram CenteredReverse { get { return m_CenteredReverse; } set { m_CenteredReverse = value; } }
        public int ScanPairCount { get { return m_iScanPairCount; } set { m_iScanPairCount = value; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingCenterAveraged();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingCenterAveraged GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Clear container for new measurement sequence
        /// </summary>
        public void ClearForNewMeasurement()
        {
            m_CenteredReverse = null;
            m_CenteredForward = null;
            m_iScanPairCount = 0;
        }

        public void Clear()
        {
            if (m_CenteredForward != null)
            {
                m_CenteredForward.Vector.Release();
                m_CenteredForward = null;
            }
            if (m_CenteredReverse != null)
            {
                m_CenteredReverse.Vector.Release();
                m_CenteredReverse = null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Calcultate the centered average of the scans. There must be the same number of
        /// forward and reverse scans.
        /// </summary>
        public void Do()
        {
            Console.WriteLine("Start centering averaged scans");

            // center averaged scans
            CCOVector m_ForwardInterferogram = CDQStateRecordingAverageScans.GetInstance().ForwardInterferogram;
            CCOVector m_ReverseInterferogram = CDQStateRecordingAverageScans.GetInstance().ReverseInterferogram;
            m_iZeroFilling = DQSIController.ZeroFillingCenterAverage;
            int l_iUsefulLeftPoints = DQSIController.UsefulLeftPoints;

            int l_iInstrumentTemperature = 42; // GetContext(p_Context).GetInstrumentTemperature();

            // center interferograms if wanted
            if (DQSIController.CenterAverageApplied)
            {
                m_CenteredForward = new CCOInterferogram(
                    CenterAveraged(m_ForwardInterferogram, l_iUsefulLeftPoints),
                    ECOInterferogramType.eForwardRecord, l_iInstrumentTemperature);
                m_CenteredReverse = new CCOInterferogram(
                    CenterAveraged(m_ReverseInterferogram, l_iUsefulLeftPoints),
                    ECOInterferogramType.eReverseRecord, l_iInstrumentTemperature);
            }
            else
            {
                // don't apply center function (only used for test)
                m_CenteredForward = new CCOInterferogram(m_ForwardInterferogram, ECOInterferogramType.eForwardRecord, l_iInstrumentTemperature);
                m_CenteredReverse = new CCOInterferogram(m_ReverseInterferogram, ECOInterferogramType.eReverseRecord, l_iInstrumentTemperature);
            }

            Console.WriteLine("Finished centering averaged scans");
            Console.WriteLine("DQ: scan pair nr: " + m_iScanPairCount + " added");

            // Go on to spectra phase correction
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Enlarge resolution of interferogram with zero filling and determine
        /// the peak. Do shift on interferogram if needed.
        /// </summary>
        /// <param name="p_Interferogram">input interferogram</param>
        /// <param name="p_iUsefulLeftPoints">Index of peak target</param>
        /// <returns>Shifted interferogram</returns>
        public CCOVector CenterAveraged(CCOVector p_Interferogram, int p_iUsefulLeftPoints)
        {
            Debug.Assert(p_Interferogram != null);

            int l_iLength = p_Interferogram.Length;
            int l_iNewLength = (int)Math.Pow(2.0, (Math.Ceiling(Math.Log((double)l_iLength) / Math.Log(2.0))));
            int l_iDiffLength = l_iNewLength - l_iLength;

            // do the zero filling
            CCOVector l_Zeros = new CCOVector(l_iDiffLength / 2);
            CCOVector[] l_InterfArray = { l_Zeros, p_Interferogram, l_Zeros };
            CCOVector l_Interf = new CCOVector(l_InterfArray);

            CCOFFT l_FFT = new CCOFFT();
            CCOVector l_ZeroFilled = l_FFT.ZeroFilling(l_Interf, m_iZeroFilling);

            // find max peak around (+1 / -1) the peak point
            int l_iStart = m_iZeroFilling * ((p_iUsefulLeftPoints - 1) + l_iDiffLength / 2 - 1);
            int l_iEnd = m_iZeroFilling * ((p_iUsefulLeftPoints + 1) + l_iDiffLength / 2 - 1);
            int l_iMax;

            // mark selection and get max in selection
            CCOVector l_Selection = new CCOVector(l_ZeroFilled.Length);
            l_Selection.FillSelection(l_iStart, (l_iEnd - l_iStart + 1), 1.0);
            l_ZeroFilled.MinAt(out l_iMax, l_Selection);

            // build shifted interferogram
            int l_iStartSel = l_iMax - (p_iUsefulLeftPoints - 1) * m_iZeroFilling;
            int l_iEndSel = l_iMax + ((l_iLength - p_iUsefulLeftPoints) * m_iZeroFilling);
            CCOVector l_SelectBlock = new CCOVector(l_ZeroFilled.Length);
            l_SelectBlock.BlockSelect(l_iStartSel, l_iEndSel - l_iStartSel + 1, 1, m_iZeroFilling - 1);
            CCOVector l_Shifted = l_ZeroFilled.ShrinkToSelection(l_SelectBlock);
            Debug.Assert(l_Shifted.Length == p_Interferogram.Length);

            return l_Shifted;
        }
    }
}

namespace Buchi.DataAcquisition
{
    public class CDQStateSpectraPhaseCorrection //: Buchi.DataAcquisition.CDQStateSpectra
    {

        /// <summary>The unique instance of the class</summary>
        private static CDQStateSpectraPhaseCorrection m_Instance;

        /// <summary>The accumulated reverse interferogram</summary>
        private Core.Math.CCOVector m_ReverseInterferogram;

        /// <summary>The accumulated forward interferogram</summary>
        private Core.Math.CCOVector m_ForwardInterferogram;

        /// <summary>The window size ofr the phase correction</summary>
        private int m_iCorrWindowWidth;

        /// <summary>UsefulLeftPoints</summary>
        private int m_iUsefulLeftPoints;

        /// <summary>Type of apodization</summary>
        private CCOFFT.WeightingFunctions m_ApodizationType1;

        /// <summary>Type of apodization</summary>
        private CCOFFT.WeightingFunctions m_ApodizationType2;

        /// <summary>properties</summary>
        public CCOVector PhaseCorrectedForwardInterferogram { get { return m_ForwardInterferogram; } }
        public CCOVector PhaseCorrectedReverseInterferogram { get { return m_ReverseInterferogram; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateSpectraPhaseCorrection();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateSpectraPhaseCorrection GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        public void Clear()
        {
            if (m_ReverseInterferogram != null)
            {
                m_ReverseInterferogram.Release();
                m_ReverseInterferogram = null;
            }
            if (m_ForwardInterferogram != null)
            {
                m_ForwardInterferogram.Release();
                m_ForwardInterferogram = null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Do phase correction
        /// </summary>
        public void Do()
        {
            // get params
            m_iCorrWindowWidth = DQSIController.PhaseCorrectionWindowSize;
            m_ApodizationType1 = CCOFFT.WeightingFunctions.Blackman;
            m_ApodizationType2 = CCOFFT.WeightingFunctions.Blackman;
            m_iUsefulLeftPoints = DQSIController.UsefulLeftPoints - 1;  // array starts at 0

            // get interferogram
            CCOVector l_ForwardInterferogram = CDQStateRecordingCenterAveraged.GetInstance().CenteredForward.Vector;
            CCOVector l_ReverseInterferogram = CDQStateRecordingCenterAveraged.GetInstance().CenteredReverse.Vector;

            // test if interferogram is ok
            if (l_ForwardInterferogram == null || l_ReverseInterferogram == null ||
                l_ForwardInterferogram.Length != l_ReverseInterferogram.Length ||
                l_ReverseInterferogram.Length != DQSIController.UsefulPointsPerScan)
            {
                // return to state ready
                Console.WriteLine("No valid interferogram found");
                return;
            }

            Console.WriteLine("Start phase correction");

            // perform phase correction using the 'forman' algorythm
            m_ForwardInterferogram = PerformPhaseCorrection(l_ForwardInterferogram);
            m_ReverseInterferogram = PerformPhaseCorrection(l_ReverseInterferogram);

            Console.WriteLine("Finished phase correction");

            // go on computing the raw spectra
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// phase corrects the given interferogram using the 'forman' algorythm
        /// </summary>
        /// <param name="p_Interferogram">interferogram vector</param>
        /// <returns>phase corrected interferogram</returns>
        private CCOVector PerformPhaseCorrection(CCOVector p_Interferogram)
        {
            int l_iPeakIndex = m_iUsefulLeftPoints;
            Trace.Assert(l_iPeakIndex > m_iCorrWindowWidth / 2);

            // use window around peak
            CCOVector l_PeakWindow = p_Interferogram.GetSlice(l_iPeakIndex - m_iCorrWindowWidth / 2, m_iCorrWindowWidth);

            // use apodization
            CCOVector l_Apodization = new CCOVector(l_PeakWindow.Length);
            l_Apodization.FillSelection(0, l_Apodization.Length, 1.0);
            CCOFFT l_Fft = new CCOFFT();
            l_Fft.Weighting(l_Apodization, m_ApodizationType1);
            CCOVector l_ApodPeakWindow = l_PeakWindow * l_Apodization;

            // Flip - IFFT - Flip
            CCOComplexVector l_CxApodPeakWindow = new CCOComplexVector(l_ApodPeakWindow);
            CCOFFT l_FFT = new CCOFFT();
            l_FFT.Init(l_CxApodPeakWindow.Real.Length);
            CCOComplexVector l_CxFlipped = l_CxApodPeakWindow.Flip();
            l_FFT.Ifft(ref l_CxFlipped);
            CCOComplexVector l_CxSpectra = l_CxFlipped.Flip();
            CCOVector l_RealSpectra = l_CxSpectra.Abs();

            // conjugated complex vector
            l_CxSpectra.Conj();
            CCOComplexVector l_PhaseCnj = l_CxSpectra;

            double l_dbZeroLimit = 1E-8 * l_RealSpectra.Mean();

            // divide through amount of spectra or set to zero if the value is small enough
            for (int l_iCnt = 0; l_iCnt < l_PhaseCnj.Imag.Length; l_iCnt++)
            {
                if (l_RealSpectra[l_iCnt] > l_dbZeroLimit)
                {
                    l_PhaseCnj.Real[l_iCnt] /= l_RealSpectra[l_iCnt];
                    l_PhaseCnj.Imag[l_iCnt] /= l_RealSpectra[l_iCnt];
                }
                else
                {
                    l_PhaseCnj.Real[l_iCnt] = 0;
                    l_PhaseCnj.Imag[l_iCnt] = 0;
                }
            }

            // set certain areas to 0
            l_PhaseCnj.Real[0] = 0;
            l_PhaseCnj.Imag[0] = 0;

            for (int l_iCnt = m_iCorrWindowWidth / 2 - 1; l_iCnt <= m_iCorrWindowWidth / 2 + 1; l_iCnt++)
            {
                l_PhaseCnj.Real[l_iCnt] = 0;
                l_PhaseCnj.Imag[l_iCnt] = 0;
            }

            // test if transfilter is on
            if (DQSIController.TransfilterOn)
            {
                // get transfilter parameters
                double l_dbTransFilterParam_s = DQSIController.TransfilterParam_s;
                double l_dbTransFilterNdiv = DQSIController.TransfilterParam_ndiv;

                TransFilter(l_PhaseCnj, l_dbTransFilterParam_s, l_dbTransFilterNdiv);
            }

            // get phase spectra
            CCOFFT l_FFTTheta = new CCOFFT();
            l_FFTTheta.Init(l_PhaseCnj.Real.Length);
            CCOComplexVector L_CxFlipped = l_PhaseCnj.Flip();
            l_FFTTheta.Fft(L_CxFlipped);
            CCOComplexVector l_Theta = L_CxFlipped.Flip();

            // use apodization
            CCOVector l_Apodization2 = new CCOVector(l_PeakWindow.Length);
            l_Apodization2.FillSelection(0, l_Apodization2.Length, 1.0);
            CCOFFT l_Fft2 = new CCOFFT();
            l_Fft2.Weighting(l_Apodization2, m_ApodizationType2);
            CCOComplexVector l_ApodTheta = l_Theta * l_Apodization2;

            CCOVector l_ConvInterferogram = CCOVector.Conv(p_Interferogram, l_ApodTheta.Real) / m_iCorrWindowWidth;
            CCOVector l_Result = l_ConvInterferogram.GetSlice(m_iCorrWindowWidth / 2, p_Interferogram.Length);
            return l_Result;
        }


        /// -------------------------------------------------------------------

        /// <summary>
        /// The transfilter sets certain areas to 0.
        /// </summary>
        /// <param name="p_CxVector">Set certain values of this vector to 0.</param>
        /// <param name="p_Param_s">Paramter s</param>
        /// <param name="p_ParamNdiv">Parameter ndiv</param>
        private void TransFilter(CCOComplexVector p_CxVector, double p_Param_s, double p_ParamNdiv)
        {
            // set certain areas to zero
            p_CxVector.Real[0] = 0;
            p_CxVector.Imag[0] = 0;

            for (int l_iCnt = 1; l_iCnt <= m_iCorrWindowWidth / p_Param_s; l_iCnt++)
            {
                p_CxVector.Real[l_iCnt] = 0;
                p_CxVector.Imag[l_iCnt] = 0;
            }
            for (int l_iCnt = (int)(m_iCorrWindowWidth / 2 - m_iCorrWindowWidth / p_ParamNdiv);
                l_iCnt <= m_iCorrWindowWidth / 2 + m_iCorrWindowWidth / p_ParamNdiv + 1; l_iCnt++)
            {
                p_CxVector.Real[l_iCnt] = 0;
                p_CxVector.Imag[l_iCnt] = 0;
            }
            for (int l_iCnt = m_iCorrWindowWidth - (int)(m_iCorrWindowWidth / p_Param_s);
                l_iCnt < m_iCorrWindowWidth; l_iCnt++)
            {
                p_CxVector.Real[l_iCnt] = 0;
                p_CxVector.Imag[l_iCnt] = 0;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Build a vector [startValue..EndValue] with a defined step size.
        /// </summary>
        /// <param name="p_StartValue">start value</param>
        /// <param name="p_Step">step size</param>
        /// <param name="p_EndValue">end value</param>
        /// <returns>The built vector</returns>
        public static CCOVector BuildStepVector(double p_StartValue, double p_Step, double p_EndValue)
        {
            int Length = GetStepVectorLength(p_StartValue, p_Step, p_EndValue);
            CCOVector Vector = new CCOVector(Length);

            double Value = p_StartValue;

            for (int i = 0; i < Length; i++)
            {
                Vector[i] = Value;
                Value += p_Step;
            }
            return Vector;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Get vector size.
        /// </summary>
        /// <param name="p_StartValue">start value</param>
        /// <param name="p_Step">step size</param>
        /// <param name="p_EndValue">end value</param>
        /// <returns>The built vector</returns>
        public static int GetStepVectorLength(double p_StartValue, double p_Step, double p_EndValue)
        {
            Trace.Assert(p_Step != 0.0 &&
                ((p_Step > 0 && p_EndValue > p_StartValue) ||
                (p_Step < 0 && p_EndValue < p_StartValue)));

            return (int)((p_EndValue - p_StartValue + p_Step) / p_Step);
        }
    }
}

namespace Buchi.DataAcquisition
{
    public class CDQStateSpectraRaw //: Buchi.DataAcquisition.CDQStateSpectra
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateSpectraRaw m_Instance;

        /// <summary>contains the reverse spectra</summary>
        private Core.Math.CCOVector m_ReverseSpectra;

        /// <summary>contains the forward spectra</summary>
        private Core.Math.CCOVector m_ForwardSpectra;

        /// <summary>Size of interferogram used for spectra</summary>
        private int m_iInterferogramSize;

        /// <summary>UsefulLeftPoints</summary>
        private int m_iUsefulLeftPoints;

        /// <summary>Zero filling used in phase correction</summary>
        private int m_iZeroFilling;

        /// <summary>Type of apodization</summary>
        private CCOFFT.WeightingFunctions m_ApodizationType;

        /// <summary>properties</summary>
        public CCOVector ForwardSpectra { get { return m_ForwardSpectra; } }
        public CCOVector ReverseSpectra { get { return m_ReverseSpectra; } }


        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateSpectraRaw();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateSpectraRaw GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        public void Clear()
        {
            if (m_ForwardSpectra != null)
            {
                m_ForwardSpectra.Release();
                m_ForwardSpectra = null;
            }
            if (m_ReverseSpectra != null)
            {
                m_ReverseSpectra.Release();
                m_ReverseSpectra = null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Compute the raw spectra.
        /// </summary>
        public void Do()
        {
            // read parameter
            //m_iInterferogramSize = DQSIController.UsefulPointsPerScan;
            m_ApodizationType = CCOFFT.WeightingFunctions.Blackman; //GetContext(p_Context).Controller.InterferogramApodization;
            m_iUsefulLeftPoints = DQSIController.UsefulLeftPoints - 1; // array starts at 0
            m_iInterferogramSize = DQSIController.InterferogramSize;
            m_iZeroFilling = DQSIController.ZeroFillingPhaseCorrection;

            CCOVector l_ForwardInterferogram = CDQStateSpectraPhaseCorrection.GetInstance().PhaseCorrectedForwardInterferogram;
            CCOVector l_ReverseInterferogram = CDQStateSpectraPhaseCorrection.GetInstance().PhaseCorrectedReverseInterferogram;

            Console.WriteLine("Start computing the raw spectras");

            // compute the raw spectras
            m_ForwardSpectra = ComputeRawSpectra(l_ForwardInterferogram);
            m_ReverseSpectra = ComputeRawSpectra(l_ReverseInterferogram);

            Console.WriteLine("Finished computing the raw spectras");

            // go on to dispersion correction
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Computes the raw spectra from a phase corrected interferogram
        /// </summary>
        /// <param name="p_Interferogram">phase corrected interferogram</param>
        /// <returns></returns>
        private CCOVector ComputeRawSpectra(CCOVector p_Interferogram)
        {
            // mirror single sided interferogram
            int l_iPeakPosition = m_iUsefulLeftPoints;
            CCOVector[] l_InterParts = {p_Interferogram.GetSlice(l_iPeakPosition, m_iInterferogramSize),
                                        (p_Interferogram.GetSlice(l_iPeakPosition+1, m_iInterferogramSize)).Reverse()};
            CCOVector l_MirroredInterferogram = new CCOVector(l_InterParts);

            // compute apodization and apply it to the mirrored interferogram
            CCOVector l_Apodization = new CCOVector(l_MirroredInterferogram.Length);
            l_Apodization.FillSelection(0, l_Apodization.Length, 1.0);
            CCOFFT l_Fft = new CCOFFT();
            l_Fft.Weighting(l_Apodization, m_ApodizationType);
            CCOVector l_ApodInterferogram = l_MirroredInterferogram * l_Apodization.Flip();

            // create zero filled vector (next higher squaring)
            int l_NextPower2 = (int)System.Math.Ceiling(System.Math.Log10(m_iInterferogramSize) / System.Math.Log10(2));
            int l_iZeros = m_iZeroFilling * (int)System.Math.Pow(2, l_NextPower2) - m_iInterferogramSize;
            CCOVector[] l_ZeroFilledParts =
            {
                new CCOVector(l_iZeros),
                l_ApodInterferogram.Flip(),
                new CCOVector(l_iZeros)
            };

            CCOVector l_ZeroFilledInterferogram = new CCOVector(l_ZeroFilledParts);
            l_ZeroFilledInterferogram = l_ZeroFilledInterferogram.Flip();

            // fourier transformation
            CCOFFT l_FFT = new CCOFFT();
            l_FFT.Init(l_ZeroFilledInterferogram.Length);
            CCOComplexVector l_CxSpectra = new CCOComplexVector(l_ZeroFilledInterferogram);
            l_FFT.Fft(l_CxSpectra);

            // use half of the real part (symmetrical)
            CCOVector l_RealSpectra = l_CxSpectra.Real.GetSlice(0, l_CxSpectra.Length / 2);

            return l_RealSpectra;
        }
    }
}


namespace Buchi.DataAcquisition
{
    public class CDQStateSpectraDispersionCorrection
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateSpectraDispersionCorrection m_Instance;

        /// <summary>contains the reverse spectra</summary>
        private Core.Math.CCOVector m_SpectraReverse;

        /// <summary>contains the forward spectra</summary>
        private Core.Math.CCOVector m_SpectraForward;

        /// <summary>contains the average spectra</summary>
        private Core.Math.CCOVector m_SpectraAverage;

        /// <summary>HeNe-laser wavelength</summary>
        private double m_dbLaserLambda;

        /// <summary>[cm-1] x axes of spectrum</summary>
        private CCOVector m_Nuaxis;

        /// <summary>Coefficients for spectra.</summary>
        private double m_db1;
        private double m_db2;
        private double m_db3;
        private double m_db4;
        private double m_b1;
        private double m_b2;
        private double m_T0;
        private double m_dbTempWedgeDrive;

        /// <summary>Start, step and number of points in spectra</summary>
        private int m_WaveNumber;
        private double m_WaveNumberStart;
        private double m_WaveNumberStep;

        /// <summary>Properties</summary>
        public CCOVector SpectraForward { get { return m_SpectraForward; } }
        public CCOVector SpectraReverse { get { return m_SpectraReverse; } }
        public CCOVector SpectraAverage { get { return m_SpectraAverage; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateSpectraDispersionCorrection();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateSpectraDispersionCorrection GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        public void Clear()
        {
            if (m_SpectraAverage != null)
            {
                m_SpectraAverage.Release();
                m_SpectraAverage = null;
            }
            if (m_SpectraForward != null)
            {
                m_SpectraForward.Release();
                m_SpectraForward = null;
            }
            if (m_SpectraReverse != null)
            {
                m_SpectraReverse.Release();
                m_SpectraReverse = null;
            }
            if (m_Nuaxis != null)
            {
                m_Nuaxis.Release();
                m_Nuaxis = null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Compute the dispersion correction
        /// </summary>
        public void Do()
        {
            Console.WriteLine("Start dispersion correction");

            // get params
            m_db1 = DQSIController.DispersionCorrectionCoefficient1;
            m_db2 = DQSIController.DispersionCorrectionCoefficient2;
            m_db3 = DQSIController.DispersionCorrectionCoefficient3;
            m_db4 = DQSIController.DispersionCorrectionCoefficient4;
            m_b1 = DQSIController.DispersionCorrectionCoefficientB1;
            m_b2 = DQSIController.DispersionCorrectionCoefficientB2;
            m_T0 = DQSIController.DispersionCorrectionCoefficientT0;
            m_WaveNumber = DQSIController.WaveNumbers;
            m_WaveNumberStart = DQSIController.WaveNumberStart;
            m_WaveNumberStep = DQSIController.WaveNumberStep;
            m_dbLaserLambda = DQSIController.LaserLambda;

            // get temp of wedge drive
            m_dbTempWedgeDrive = (double)CDQStateRecordingCenterAveraged.GetInstance().CenteredForward.InstrumentTemperature / 1000;

            // get spectras
            CCOVector l_ForwardSpectra = CDQStateSpectraRaw.GetInstance().ForwardSpectra;
            CCOVector l_ReverseSpectra = CDQStateSpectraRaw.GetInstance().ReverseSpectra;

            // calculate corrected spectra
            m_SpectraForward = DispersionCorrection(l_ForwardSpectra);
            m_SpectraReverse = DispersionCorrection(l_ReverseSpectra);

            // calculate the average spectra
            m_SpectraAverage = (m_SpectraForward + m_SpectraReverse) / 2;

            Console.WriteLine("Finished dispersion correction");

            // signal the completion of the spectra
            if (!DQSIController.NoiseTest)
            {
                // measurement is completed
                //GetContext(p_Context).StopDataReaderThread();
                int l_iScanPairCount = CDQStateRecordingCenterAveraged.GetInstance().ScanPairCount;
                Console.WriteLine("Finished spectra (" + l_iScanPairCount + " scans)");

                //SignalPackageCompletion();
            }
            else
            {
                // do noise test
            }
        }

        /// -------------------------------------------------------k------------
        /// <summary>
        /// Do the dispersion correction
        /// </summary>
        /// <param name="l_Spectrum">Correct this spectrum</param>
        public CCOVector DispersionCorrection(CCOVector p_Spectrum)
        {
            // u-target-axis u=nu*deltan(nu)
            CCOVector l_Utaxis = BuildUtaxis();

            // u-axis of spectrum in cm^-1
            CCOVector l_Usaxis = BuildUsaxis(p_Spectrum.Length);

            // spline-interpolate spectrum from old u-axis (usaxis) to new u-axis (utaxis)
            CCOVector l_SplinedSpectrum;
            if (!p_Spectrum.FreeCubicSpline(l_Usaxis, p_Spectrum, l_Utaxis, out l_SplinedSpectrum))
            {
                Debug.Assert(false);
            }

            return l_SplinedSpectrum;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Build axe used for spline
        /// </summary>
        /// <returns>Axe</returns>
        public CCOVector BuildUtaxis()
        {
            double l_dbWaveEnd = m_WaveNumberStart + m_WaveNumberStep * (m_WaveNumber - 1);
            m_Nuaxis = CDQStateSpectraPhaseCorrection.BuildStepVector(m_WaveNumberStart, m_WaveNumberStep, l_dbWaveEnd);

            // u-target-axis u=nu*deltan(nu)
            CCOVector l_Utaxis = m_Nuaxis * Birefteo2((m_Nuaxis * 100).Power(-1));
            return l_Utaxis;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Build axe used for spline
        /// </summary>
        /// <param name="l_SpectrumLength">Length of spectrum</param>
        /// <returns>Axe</returns>
        public CCOVector BuildUsaxis(int l_iSpectrumLength)
        {
            CCOVector l_Lambdal = new CCOVector(1);
            l_Lambdal[0] = m_dbLaserLambda;

            // sample spacing (as wedge thickness)                                  
            double l_dbDeltaX = m_dbLaserLambda / (2 * (Birefteo2(l_Lambdal))[0]);

            //spacing on u-axis
            double l_dbDeltaU = 1 / (2 * l_dbDeltaX * l_iSpectrumLength);
            double l_dbUmax = l_dbDeltaU * l_iSpectrumLength;

            // u-axis of spectrum in cm^-1
            CCOVector l_Axis = CDQStateSpectraPhaseCorrection.BuildStepVector(0, 1, l_iSpectrumLength - 1);
            CCOVector l_Usaxis = l_Axis * 0.01 * l_dbUmax / l_iSpectrumLength;   // !!!! divide by l_iLength not by (l_iLength-1)!!

            return l_Usaxis;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// birefteo2(lambda) gives variation of the birefringence of TeO2
        /// as a function of wavelength lambda [m].
        /// </summary>
        /// <param name="p_Interferogram">phase corrected interferogram</param>
        /// <returns></returns>
        private CCOVector Birefteo2(CCOVector p_Vector)
        {
            CCOVector l_vec = p_Vector * 1.0E+6;   // rescale units from m to um
            CCOVector l_result =
                l_vec.Power(-2) * m_db2 + m_db1 + l_vec.Power(-4) * m_db3 + l_vec.Power(2) * m_db4 +
                (l_vec.Power(-2) * m_b2 + m_b1) * (m_dbTempWedgeDrive - m_T0);
            return l_result;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Signal the client sync object that one data package has been read and 
        /// the spectra has been calculated.
        /// </summary>
        public CDQResultRecordSpectra SignalPackageCompletion()
        {
            // terminate one measurement, build new result object
            int l_iScanPairCount = CDQStateRecordingCenterAveraged.GetInstance().ScanPairCount;
            CDQResultScanInfoList l_ScanInfoList = CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList;

            // build all spectrum
            CCOSpectrum l_SpectrumForward = BuildSpectrum(m_SpectraForward);
            CCOSpectrum l_SpectrumReverse = BuildSpectrum(m_SpectraReverse);
            CCOSpectrum l_SpectrumAverage = BuildSpectrum(m_SpectraAverage);
            int l_ixStart = 1 - DQSIController.UsefulLeftPoints;

            CDQResultRecordSpectra l_Result = new CDQResultRecordSpectra(
                new CCOInterferogram(CDQStateRecordingCenterAveraged.GetInstance().CenteredForward),
                new CCOInterferogram(CDQStateRecordingCenterAveraged.GetInstance().CenteredReverse),
                l_SpectrumForward,
                l_SpectrumReverse,
                l_SpectrumAverage,
                l_iScanPairCount,
                l_ixStart,
                l_ScanInfoList
                );
            return l_Result;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Add properties of spectrum
        /// </summary>
        /// <param name="p_Vector">spectrum data in a vector</param>
        /// <returns>Fille spectrum</returns>
        private CCOSpectrum BuildSpectrum(CCOVector p_Vector)
        {
            int l_iScanPairCount = CDQStateRecordingCenterAveraged.GetInstance().ScanPairCount;

            CCOSpectrum l_Spectrum = new CCOSpectrum();

            // (non) l_Spectrum.Characteristic 
            // (non) l_Spectrum.Comment 
            // (non) l_Spectrum.CustomData 
            // (non) l_Spectrum.CustomXVector        = new CCOVector(m_Nuaxis);
            l_Spectrum.DataResolution = DQSIController.WaveNumberStep;
            l_Spectrum.InstrumentResolution = DQSIController.ScanResolution;
            // (non) l_Spectrum.InstrumentSerialNo 
            // (non) l_Spectrum.InstrumentType 
            // (non) l_Spectrum.Loaded 
            // (non) l_Spectrum.MeasurementCellOptionType 
            // (non) l_Spectrum.MeasurementCellSerialNo 
            // (non) l_Spectrum.MeasurementCellType 
            l_Spectrum.NumberOfScans = l_iScanPairCount;
            l_Spectrum.SourceType = ECOSpectrumSourceType.eNIRWare;
            l_Spectrum.SpectrumGUID = Guid.NewGuid();
            // (non) l_Spectrum.SpectrumID   
            // (non) l_Spectrum.SpectrumType 
            // (non) l_Spectrum.TimeStamp    
            // (non) l_Spectrum.User      
            l_Spectrum.Vector = new CCOVector(p_Vector);
            l_Spectrum.Version = new CCOVersionInfo("1");
            l_Spectrum.XAxisType = ECOSpectrumXAxisType.eWavenumber;
            // (non) l_Spectrum.YAxisType
            l_Spectrum.XStart = DQSIController.WaveNumberStart;

            l_Spectrum.ForwardIFG = new CCOInterferogram(CDQStateRecordingCenterAveraged.GetInstance().CenteredForward);
            l_Spectrum.ReverseIFG = new CCOInterferogram(CDQStateRecordingCenterAveraged.GetInstance().CenteredReverse);
            l_Spectrum.InstrumentTemperature = l_Spectrum.ForwardIFG.InstrumentTemperature;

            return l_Spectrum;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Clear container for new measurement sequence
        /// </summary>
        public void ClearForNewMeasurement()
        {
            m_SpectraForward = CCOVector.EMPTY_VECTOR;
            m_SpectraReverse = CCOVector.EMPTY_VECTOR;
        }
    }
}

namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingInvalidData //: Buchi.DataAcquisition.CDQStateRecording
    {

        /// <summary>Properties</summary>
        public int ErrorCounter { get { return m_iErrorCounter; } set { m_iErrorCounter = value; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingInvalidData();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingInvalidData GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Prepare for reading the next data package or stop measurement
        /// </summary>
        public void Do()
        {
            try
            {

                // show error on output and in DB
                CDQScanInfo l_ScanInfo = CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList.GetCurrent();
                if (l_ScanInfo.ScanState == EDQScanState.eErrorScanQualityCheckFailed)
                {
                    m_iQualityFailuresCounter++;
                }
                else
                {
                    m_iErrorCounter++;
                }
                string l_sError = l_ScanInfo.ScanState.ToString() + " -  " + l_ScanInfo.ErrorInfo;
                Console.WriteLine("DQ: ERROR " + l_sError);
                //CCOExceptionManager.GetInstance().TraceMessage(ID.DQ_ID, l_sError);

                // test if too many errors
                int l_invalidScanStartCheck = DQSIController.InvalidScanStartCheck;
                int l_iScanPairTotal = DQSIController.ScanPairTotal;
                double l_dbMaxInvalidScanPercentage = DQSIController.MaxInvalidScanPercentage;
                CheckNumberOfErrors(l_invalidScanStartCheck, l_iScanPairTotal, l_dbMaxInvalidScanPercentage);

                // test if scan quality failure
                int l_iMaxAllowedScanQualityFailures = DQSIController.MaxAllowedScanQualityFailures;
                CheckNumberOfScanQuailityFailures(l_iMaxAllowedScanQualityFailures);

                //p_Context.ChangeState(CDQStateRecordingReadNext.GetInstance());
            }
            catch
            {
                var msg = "DQ: Too many invalid data, reading was stopped";
                Console.WriteLine(msg);
                throw new Exception(msg);
            }

        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Check whether too many many error scans were detected
        /// </summary>
        /// <param name="p_Context">The current state machine context</param>
        /// <exception cref="XDQExceptionBadMeasurement">if too many errors occured</exception>
        public void CheckNumberOfErrors(int p_invalidScanStartCheck, int p_iScanPairTotal, double p_dbMaxInvalidScanPercentage)
        {
            // start test after a minimum of correct scans is reached (e.g. 5 scans are done)
            int l_iScanPairCount = CDQStateRecordingCenterAveraged.GetInstance().ScanPairCount;
            int l_iScansDone = l_iScanPairCount + m_iErrorCounter;

            if (l_iScansDone >= p_invalidScanStartCheck)
            {
                // apply percentage check
                if (100 * (m_iErrorCounter / (double)p_iScanPairTotal) >= p_dbMaxInvalidScanPercentage)
                {
                    string l_sError = CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList.GetErrorOverview();
                    var msg = "DQ: Too many bad scans: " + l_sError;
                    Console.WriteLine(msg);
                    throw new Exception(msg);
                }
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// 
        /// </summary>
        public void CheckNumberOfScanQuailityFailures(int p_MaxAllowedScanQualityFailures)
        {
            if (m_iQualityFailuresCounter > p_MaxAllowedScanQualityFailures)
            {
                string l_sError = CDQStateRecordingStartMeasurement.GetInstance().ScanInfoList.GetScanQualityOverview();
                throw new Exception(l_sError);
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Reset error counter for a new measurement
        /// </summary>
        public void ClearForNewMeasurement()
        {
            m_iErrorCounter = 0;
            m_iQualityFailuresCounter = 0;
        }

        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingInvalidData m_Instance;

        /// <summary>Counts the errors during one measurement</summary>
        private int m_iErrorCounter;

        /// <summary>Counts the Scan Quality Failures during one measurement</summary>
        private int m_iQualityFailuresCounter;
    }
}


namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingNoiseTest //: Buchi.DataAcquisition.CDQStateSpectra
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingNoiseTest m_Instance;

        /// <summary>Number of read scans</summary>
        private int m_iScanPairCount;

        /// <summary>Stores single forward spectrum (n col = n spectrums) </summary>
        private CCOMatrix m_ForwardSpectrum;

        /// <summary>Stores single reverse spectrum (n col = n spectrums)</summary>
        private CCOMatrix m_ReverseSpectrum;

        /// <summary>Stores single average spectrum (n col = n spectrums)</summary>
        private CCOMatrix m_AverageSpectrum;

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingNoiseTest();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingNoiseTest GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        public void Clear()
        {
            if (m_ForwardSpectrum != null)
            {
                m_ForwardSpectrum.Release();
                m_ForwardSpectrum = null;
            }
            if (m_ReverseSpectrum != null)
            {
                m_ReverseSpectrum.Release();
                m_ReverseSpectrum = null;
            }
            if (m_AverageSpectrum != null)
            {
                m_AverageSpectrum.Release();
                m_AverageSpectrum = null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Build result of noise test
        /// </summary>
        public void Do()
        {
            int l_iScanPairTotal = DQSIController.ScanPairTotal;
            m_iScanPairCount++;

            // test if matrix must be built
            if (m_ForwardSpectrum == null)
            {
                int l_SpectrumSize = DQSIController.WaveNumbers;
                m_ForwardSpectrum = new CCOMatrix(l_iScanPairTotal, l_SpectrumSize);
                m_ReverseSpectrum = new CCOMatrix(l_iScanPairTotal, l_SpectrumSize);
                m_AverageSpectrum = new CCOMatrix(l_iScanPairTotal, l_SpectrumSize);
            }

            // store spectrums for building the result
            m_ForwardSpectrum[m_iScanPairCount - 1] = CDQStateSpectraDispersionCorrection.GetInstance().SpectraForward;
            m_ReverseSpectrum[m_iScanPairCount - 1] = CDQStateSpectraDispersionCorrection.GetInstance().SpectraReverse;
            m_AverageSpectrum[m_iScanPairCount - 1] = CDQStateSpectraDispersionCorrection.GetInstance().SpectraAverage;

            // read next scan if total is not reached
            if (m_iScanPairCount < l_iScanPairTotal)
            {
                // read next data package
                return;
            }
            else
            {
                // all spectras are computed - calculate noise result
                CDQResultNoiseTest l_Result = BuildNoiseResult();
                m_ForwardSpectrum = null;   // reset members
                m_ReverseSpectrum = null;
                m_AverageSpectrum = null;
                Console.WriteLine("Finished noise test with (" + m_iScanPairCount + " scans)");
                m_iScanPairCount = 0;

                CDQStateRecordingResultNoiseTest.GetInstance().Do(l_Result);
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Build the result of the noise test.
        /// </summary>
        /// <returns>Noise test result</returns>
        private Common.CDQResultNoiseTest BuildNoiseResult()
        {
            // build mean and sdev result
            CCOVector l_MeanForward = GetMean(m_ForwardSpectrum);
            CCOVector l_MeanReverse = GetMean(m_ReverseSpectrum);
            CCOVector l_MeanAverage = GetMean(m_AverageSpectrum);
            CCOVector l_NoiseForward = GetStandardDeviation(m_ForwardSpectrum) / l_MeanForward;
            CCOVector l_NoiseReverse = GetStandardDeviation(m_ReverseSpectrum) / l_MeanReverse;
            CCOVector l_NoiseAverage = GetStandardDeviation(m_AverageSpectrum) / l_MeanAverage;
            double l_dbXStart = DQSIController.WaveNumberStart;
            double l_dbXStep = DQSIController.WaveNumberStep;

            return new CDQResultNoiseTest(l_MeanAverage, l_MeanForward, l_MeanReverse, l_NoiseAverage, l_NoiseForward, l_NoiseReverse, l_dbXStart, l_dbXStep);
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Calculates the standard deviation of each vector in a matrix and
        /// returns the result in a vector
        /// </summary>
        /// <param name="p_SpectrumMatrix">input matrix</param>
        /// <returns>Vector with calculated sdev</returns>
        private CCOVector GetStandardDeviation(CCOMatrix p_SpectrumMatrix)
        {
            CCOVector l_SDevVector = new CCOVector(p_SpectrumMatrix.ncol);

            for (int i = 0; i < p_SpectrumMatrix.ncol; i++)
            {
                l_SDevVector[i] = p_SpectrumMatrix.GetColVector(i).Sdev();
            }
            return l_SDevVector;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Calculates the mean of each vector in a matrix and
        /// returns the result in a vector
        /// </summary>
        /// <param name="p_SpectrumMatrix">input matrix</param>
        /// <returns>Vector with calculated mean values</returns>
        private CCOVector GetMean(CCOMatrix p_SpectrumMatrix)
        {
            CCOVector l_Mean = new CCOVector(p_SpectrumMatrix.ncol);

            for (int i = 0; i < p_SpectrumMatrix.ncol; i++)
            {
                l_Mean[i] = p_SpectrumMatrix.GetColVector(i).Mean();
            }
            return l_Mean;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Clear container for new measurement sequence
        /// </summary>
        public void ClearForNewMeasurement()
        {
            m_iScanPairCount = 0;
            m_ForwardSpectrum = null;
            m_ReverseSpectrum = null;
            m_AverageSpectrum = null;
        }
    }
}


namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingResultRawData //: Buchi.DataAcquisition.CDQStateRecording
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingResultRawData m_Instance;

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingResultRawData();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingResultRawData GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Build result
        /// </summary>
        public CDQResultRawData Do()
        {
            // build intermediate result and signal object
            CDQDataArrayList l_RawData = CDQStateRecordingReadData.GetInstance().RawData;

            // get raw data
            CDQScanList l_ScanList;
            double[] l_LaserData, l_DetectorData;
            l_RawData.GetPackage(out l_LaserData, out l_DetectorData, out l_ScanList);
            CCOVector l_Laser = new CCOVector(l_LaserData);
            CCOVector l_Detector = new CCOVector(l_DetectorData);
            double l_dbTimeStep = 1.0 / DQSIController.SamplingFrequency;
            CDQResultRawData l_Data = new CDQResultRawData(l_Detector, l_Laser, l_dbTimeStep);

            return l_Data;
        }
    }
}


namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingResultFilteredData //: Buchi.DataAcquisition.CDQStateRecording
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingResultFilteredData m_Instance;

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingResultFilteredData();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingResultFilteredData GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Build result
        /// </summary>
        public CDQResultFilteredData Do()
        {
            // build intermediate result and signal object
            CCOVector l_Interferogram = CDQStateRecordingFilterDataPackage.GetInstance().FilteredDetector;
            CCOVector l_Laser = CDQStateRecordingFilterDataPackage.GetInstance().FilteredLaser;
            double l_dbTimeStep = 1.0 / DQSIController.SamplingFrequency;
            CDQResultFilteredData l_Data = new CDQResultFilteredData(l_Interferogram, l_Laser, l_dbTimeStep);

            return l_Data;
        }
    }
}

namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingResultInterpolatedData //: Buchi.DataAcquisition.CDQStateRecording
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingResultInterpolatedData m_Instance;

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingResultInterpolatedData();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingResultInterpolatedData GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Build result
        /// </summary>
        public CDQResultInterpolatedData Do()
        {
            // build intermediate result and signal object
            CCOVector l_Time = CDQStateRecordingSampleAtZeroPoints.GetInstance().InterpolatedInterferogram.GetColVector(0);
            CCOVector l_Interferogram = CDQStateRecordingSampleAtZeroPoints.GetInstance().InterpolatedInterferogram.GetColVector(1);
            CDQResultInterpolatedData l_Data = new CDQResultInterpolatedData(l_Time, l_Interferogram);

            return l_Data;
        }
    }
}

namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingResultSpeed //: Buchi.DataAcquisition.CDQStateRecording
    {
        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingResultSpeed m_Instance;

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingResultSpeed();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingResultSpeed GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Build result
        /// </summary>
        public CDQResultSpeed Do()
        {
            // build intermediate result and signal object
            int l_iReverseWindowStart = ((CDQScanWindow)CDQStateRecordingFindScanWindows.GetInstance().ReverseScans[0]).Start;
            CCOVector l_Time = CDQStateRecordingSampleAtZeroPoints.GetInstance().InterpolatedInterferogram.GetColVector(0);
            CCOVector l_Ifg = CDQStateRecordingSampleAtZeroPoints.GetInstance().InterpolatedInterferogram.GetColVector(1);
            CCOVector l_Speed = CDQStateRecordingGetSpeedVector.GetInstance().SpeedVector;
            CCOVector l_TimeForward = l_Time.GetSlice(0, l_iReverseWindowStart);
            CCOVector l_TimeReverse = l_Time.GetSlice(l_iReverseWindowStart, l_Ifg.Length - l_iReverseWindowStart).Reverse();
            CCOVector l_IfgForward = l_Ifg.GetSlice(0, l_iReverseWindowStart);
            CCOVector l_IfgReverse = l_Ifg.GetSlice(l_iReverseWindowStart, l_Ifg.Length - l_iReverseWindowStart).Reverse();
            CCOVector l_SpeedForward = l_Speed.GetSlice(0, l_iReverseWindowStart);
            CCOVector l_SpeedReverse = l_Speed.GetSlice(l_iReverseWindowStart, l_Ifg.Length - l_iReverseWindowStart).Reverse();
            CDQResultSpeed l_Data = new CDQResultSpeed(l_TimeForward, l_TimeReverse, l_IfgForward, l_IfgReverse, l_SpeedForward, l_SpeedReverse);

            // wait for next command
            return l_Data;
        }
    }
}

namespace Buchi.DataAcquisition
{
    public class CDQStateRecordingResultNoiseTest //: Buchi.DataAcquisition.CDQStateRecording
    {
        private CDQResultNoiseTest m_Result;

        public CDQResultNoiseTest Result { get => m_Result; }
        /// <summary>The unique instance of the class</summary>
        private static CDQStateRecordingResultNoiseTest m_Instance;

        /// -------------------------------------------------------------------
        /// <summary>
        /// Creates the one and only instance of the class
        /// </summary
        public static void Create()
        {
            Trace.Assert(m_Instance == null);
            m_Instance = new CDQStateRecordingResultNoiseTest();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Deletes the one and only instance of the class
        /// </summary>
        public static void Delete()
        {
            m_Instance = null;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a reference to the one and only instance of the class
        /// </summary>
        /// <returns>Returns a reference to the instance</returns>
        public static CDQStateRecordingResultNoiseTest GetInstance()
        {
            Trace.Assert(m_Instance != null);
            return m_Instance;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Build result
        /// </summary>
        public void Do(CDQResultNoiseTest p_Result)
        {
            // build intermediate result
            m_Result = p_Result;
        }
    }
}
