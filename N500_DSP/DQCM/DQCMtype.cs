using Buchi.Core.Math;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buchi.DataAcquisition.Common
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// State of scan or scanpair
    /// </summary>
    public enum EDQScanState
    {
        eUnknown = 0,
        eOk,
        eErrorBadRawDataLength,
        eErrorNotEnoughZeroPoints,
        eErrorBadLaserAmplitude,
        eErrorPeakDeviationForward,
        eErrorPeakDeviationReverse,
        eErrorScanWindowTooShort,
        eErrorBadForwardScanPeak,
        eErrorBadReverseScanPeak,
        eErrorBadSpeed,
        eErrorScanQualityCheckFailed
    }
}

namespace Buchi.DataAcquisition.Common
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// Measurement Context
    /// </summary>
    public enum EDQMeasurementContext
    {
        eUnknown = 0,
        eInternalReference,
        eExternalReference,
        eSample
    }
}

namespace Buchi.DataAcquisition.Common
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// This class stores the centered recorded interferogram
    /// </summary>
    [Serializable()]
    public class CDQResultRecordInterferogram
    {
        /// <summary>The recorded centered reverse interferogram
        /// x axis: samples 
        /// x start: XStart (Peak is on 0)
        /// x step: 1 sample
        /// y: ADC value
        /// y start: 0.0
        /// </summary>
        private CCOInterferogram m_ReverseInterferogram;

        /// <summary>The recorded centered reverse interferogram</summary>
        private CCOInterferogram m_ForwardInterferogram;

        /// <summary>The recorded averaged forward interferogram (used for tests)</summary>
        private CCOInterferogram m_AveragedForwardInterferogram;

        /// <summary>The recorded averaged reverse interferogram (used for tests)</summary>
        private CCOInterferogram m_AveragedReverseInterferogram;

        /// <summary>Number of valid recorded scan pairs</summary>
        private int m_iScanPairCount;

        /// <summary>Start on x axis, peak is on 0</summary>
        private int m_iXStart;

        /// <summary>Scan info list</summary>
        private CDQResultScanInfoList m_ScanInfoList;

        /// -------------------------------------------------------------------
        /// <summary>Property</summary>
        public CCOInterferogram ForwardInterferogram { get { return m_ForwardInterferogram; } }
        public CCOInterferogram ReverseInterferogram { get { return m_ReverseInterferogram; } }
        public CCOInterferogram AveragedForwardInterferogram { get { return m_AveragedForwardInterferogram; } }
        public CCOInterferogram AveragedReverseInterferogram { get { return m_AveragedReverseInterferogram; } }
        public int ScanPairCount { get { return m_iScanPairCount; } }
        public int XStart { get { return m_iXStart; } }
        public CDQResultScanInfoList ScanInfoList { get { return m_ScanInfoList; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="p_ForwardInterferogram">The recorded centered forward interferogram</param>
        /// <param name="p_ReverseInterferogram">The recorded centered reverse interferogram</param>
        /// <param name="p_AveragedForwardInterferogram">The recorded averaged forward interferogram</param>
        /// <param name="p_AveragedReverseInterferogram">The recorded averaged reverse interferogram</param>
        /// <param name="p_ScanPairCount">Number of used scan pairs</param>
        /// <param name="p_iXStart">Start of x axis</param>
        /// <param name="p_ErrorList">Error info list</param> 
        public CDQResultRecordInterferogram(
                CCOInterferogram p_ForwardInterferogram
            , CCOInterferogram p_ReverseInterferogram
            , CCOInterferogram p_AveragedForwardInterferogram
            , CCOInterferogram p_AveragedReverseInterferogram
            , int p_iScanPairCount
            , int p_iXStart
            , CDQResultScanInfoList p_ScanInfoList)
        {
            m_ForwardInterferogram = p_ForwardInterferogram;
            m_ReverseInterferogram = p_ReverseInterferogram;
            m_AveragedForwardInterferogram = p_AveragedForwardInterferogram;
            m_AveragedReverseInterferogram = p_AveragedReverseInterferogram;
            m_iScanPairCount = p_iScanPairCount;
            m_iXStart = p_iXStart;
            m_ScanInfoList = p_ScanInfoList;
        }
    }
}

namespace Buchi.DataAcquisition.Common
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// This class stores the calculated spectra
    /// </summary>
    [Serializable()]
    public class CDQResultRecordSpectra
    {
        /// <summary>The recorded reverse interferogram
        /// x axis: samples 
        /// x start: XStartInterferogram (Peak is on 0)
        /// x step: 1 sample
        /// y: value
        /// y start: 0.0
        /// </summary>
        private CCOInterferogram m_ReverseInterferogram;

        /// <summary>The recorded forward interferogram (see rev. interferogram)</summary>
        private CCOInterferogram m_ForwardInterferogram;

        /// <summary>The calculated reverse spectra (Get x, y axis values from the spectrum)</summary>
        private CCOSpectrum m_ReverseSpectra;

        /// <summary>The calculated forward spectra (Get x, y axis values from the spectrum)
        /// </summary>
        private CCOSpectrum m_ForwardSpectra;

        /// <summary>The average spectra from forw. and rev. spectra
        /// (Get x, y axis values from the spectrum)</summary>
        private CCOSpectrum m_AverageSpectra;

        /// <summary>Number of valid recorded scan pairs</summary>
        private int m_iScanPairCount;

        /// <summary>Start on x axis of interferograms, peak is on 0</summary>
        private int m_iXStartInterferogram;

        /// <summary>Scan info list</summary>
        private CDQResultScanInfoList m_ScanInfoList;

        /// -------------------------------------------------------------------
        /// <summary>Property</summary>
        public CCOSpectrum ReverseSpectra { get { return m_ReverseSpectra; } }
        public CCOSpectrum ForwardSpectra { get { return m_ForwardSpectra; } }
        public CCOSpectrum AverageSpectra { get { return m_AverageSpectra; } }
        public CCOInterferogram ReverseInterferogram { get { return m_ReverseInterferogram; } }
        public CCOInterferogram ForwardInterferogram { get { return m_ForwardInterferogram; } }
        public int ScanPairCount { get { return m_iScanPairCount; } }
        public int XStartInterferogram { get { return m_iXStartInterferogram; } }
        public CDQResultScanInfoList ScanInfoList { get { return m_ScanInfoList; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="p_ForwardInterferogram">The recorded forward interferogram</param>
        /// <param name="p_ReverseInterferogram">The recorded reverse interferogram</param>
        /// <param name="p_ForwardSpectra">The calculated forward spectra</param>
        /// <param name="p_ReverseSpectra">The calculated reverse spectra</param>
        /// <param name="p_AverageSpectra">The average spectra from forw. and rev. spectra</param>
        /// <param name="p_ScanPairCount">Number of used scan pairs</param>
        /// <param name="p_iXStartInterferogram">Start of x axis of interferograms</param>
        /// <param name="p_ErrorList">Error info list</param> 
        public CDQResultRecordSpectra(CCOInterferogram p_ForwardInterferogram
            , CCOInterferogram p_ReverseInterferogram
            , CCOSpectrum p_ForwardSpectra
            , CCOSpectrum p_ReverseSpectra
            , CCOSpectrum p_AverageSpectra
            , int p_iScanPairCount
            , int p_iXStartInterferogram
            , CDQResultScanInfoList p_ScanInfoList)
        {
            m_ForwardInterferogram = p_ForwardInterferogram;
            m_ReverseInterferogram = p_ReverseInterferogram;
            m_ForwardSpectra = p_ForwardSpectra;
            m_ReverseSpectra = p_ReverseSpectra;
            m_AverageSpectra = p_AverageSpectra;
            m_iScanPairCount = p_iScanPairCount;
            m_iXStartInterferogram = p_iXStartInterferogram;
            m_ScanInfoList = p_ScanInfoList;
        }
    }
}

namespace Buchi.DataAcquisition.Common
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// This class stores the filtered detector and the laser points of one scan pair (forw-rev).
    /// </summary>
    [Serializable()]
    public class CDQResultFilteredData
    {
        /// <summary>Filtered Interferogram of one scan pair 
        /// x axis: time [ms]
        /// x start: 0.0
        /// x step: xStep
        /// y axis: ADC value
        /// y start: 0.0
        /// </summary>
        private CCOVector m_Interferogram;

        /// <summary>Laser data of one scan pair (see interferogram)</summary>
        private CCOVector m_Laser;

        /// <summary>[ms] Step size for laser and interferogram x axis</summary>
        private double m_dbXStep;


        /// -------------------------------------------------------------------
        /// <summary>Property</summary>
        public CCOVector Interferogram { get { return m_Interferogram; } }
        public CCOVector Laser { get { return m_Laser; } }
        public double xStep { get { return m_dbXStep; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="p_Interferogram">One recorded scan pair interferogram</param>
        /// <param name="p_Laser">Laser data</param>
        /// <param name="p_iXStep">Step size on x axis</param>
        public CDQResultFilteredData(CCOVector p_Interferogram, CCOVector p_Laser, double p_dbXStep)
        {
            m_Interferogram = p_Interferogram;
            m_Laser = p_Laser;
            m_dbXStep = p_dbXStep;
        }
    }
}

namespace Buchi.DataAcquisition.Common
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// This class stores the interpolated detector and the zero laser points of one scan pair (forw-rev).
    /// </summary>
    [Serializable()]
    public class CDQResultInterpolatedData
    {
        /// <summary>Time data of one scan pair (see interferogram)</summary>
        private CCOVector m_Time;

        /// <summary>Interpolated Interferogram of one scan pair </summary>
        private CCOVector m_Interferogram;


        /// -------------------------------------------------------------------
        /// <summary>Property</summary>
        public CCOVector Time { get { return m_Time; } }
        public CCOVector Interferogram { get { return m_Interferogram; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="p_Time">Time information for the interferogram</param>
        /// <param name="p_Interferogram">One recorded scan pair interferogram</param>
        public CDQResultInterpolatedData(CCOVector p_Time, CCOVector p_Interferogram)
        {
            m_Time = p_Time;
            m_Interferogram = p_Interferogram;
        }
    }
}


namespace Buchi.DataAcquisition.Common
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// This class stores the raw detector and the laser points of one scan pair (forw-rev).
    /// </summary>
    [Serializable()]
    public class CDQResultRawData
    {
        /// <summary>Interferogram of one scan pair 
        /// x axis: time [ms]
        /// x start: 0.0
        /// x step: xStep
        /// y axis: value
        /// y start: 0.0
        /// </summary>
        private CCOVector m_Interferogram;

        /// <summary>Laser data of one scan pair (see interferogram)</summary>
        private CCOVector m_Laser;

        /// <summary>[ms] Step size for laser and interferogram x axis</summary>
        private double m_dbXStep;

        /// -------------------------------------------------------------------
        /// <summary>Property</summary>
        public CCOVector Interferogram { get { return m_Interferogram; } }
        public CCOVector Laser { get { return m_Laser; } }
        public double xStep { get { return m_dbXStep; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="p_Interferogram">One recorded scan pair interferogram</param>
        /// <param name="p_Laser">Laser data</param>
        /// <param name="p_iXStep">Step size on x axis</param>
        public CDQResultRawData(CCOVector p_Interferogram, CCOVector p_Laser, double p_dbXStep)
        {
            m_Interferogram = p_Interferogram;
            m_Laser = p_Laser;
            m_dbXStep = p_dbXStep;
        }
    }
}


namespace Buchi.DataAcquisition.Common
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// This class stores the interferogram and the speed vector of one scan pair.
    /// </summary>
    [Serializable()]
    public class CDQResultSpeed
    {
        /// <summary>Forward time information of one scan</summary>
        private CCOVector m_TimeForward;

        /// <summary>Reverse time information of one scan</summary>
        private CCOVector m_TimeReverse;

        /// <summary>Forward interferogram of one scan
        /// x axis: samples 1 to n
        /// x start: 1
        /// x step: 1 sample
        /// y axis: ADC value
        /// y start: 0.0
        /// </summary>
        private CCOVector m_InterferogramForward;

        /// <summary>Reverse (mirrored) interferogram of one scan (see forw. interferogram)</summary>
        private CCOVector m_InterferogramReverse;

        /// <summary>Forward speed of one scan
        /// x axis: samples 1 to n
        /// x start: 1
        /// x step: 1 sample
        /// y axis: velocity [Hz] 
        /// y start: 0.0
        /// </summary>
        private CCOVector m_SpeedForward;

        /// <summary>Reverse (mirrored) speed of one scan (see forw. speed)</summary>
        private CCOVector m_SpeedReverse;

        /// -------------------------------------------------------------------
        /// <summary>Property</summary>
        public CCOVector TimeForward { get { return m_TimeForward; } }
        public CCOVector TimeReverse { get { return m_TimeReverse; } }
        public CCOVector InterferogramForward { get { return m_InterferogramForward; } }
        public CCOVector InterferogramReverse { get { return m_InterferogramReverse; } }
        public CCOVector SpeedForward { get { return m_SpeedForward; } }
        public CCOVector SpeedReverse { get { return m_SpeedReverse; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="p_TimeForward">Time of recorded forward interferogram</param>
        /// <param name="p_TimeReverse">Time of recorded reverse interferogram</param>
        /// <param name="p_InterferogramForward">One recorded forward interferogram</param>
        /// <param name="p_InterferogramReverse">One recorded reverse interferogram</param>
        /// <param name="p_SpeedForward">Forward speed</param>
        /// <param name="p_SpeedReverse">Reverse speed</param>
        /// <param name="p_dbXStep">Step size on x axis</param>
        public CDQResultSpeed(
              CCOVector p_TimeForward
            , CCOVector p_TimeReverse
            , CCOVector p_InterferogramForward
            , CCOVector p_InterferogramReverse
            , CCOVector p_SpeedForward
            , CCOVector p_SpeedReverse)
        {
            m_TimeForward = p_TimeForward;
            m_TimeReverse = p_TimeReverse;
            m_InterferogramForward = p_InterferogramForward;
            m_InterferogramReverse = p_InterferogramReverse;
            m_SpeedForward = p_SpeedForward;
            m_SpeedReverse = p_SpeedReverse;
        }
    }
}

namespace Buchi.DataAcquisition.Common
{
    /// -----------------------------------------------------------------------
    /// <summary>
    /// This class stores the mean and noise (standard deviation) of forward
    /// and reverse scans.
    /// </summary>
    [Serializable()]
    public class CDQResultNoiseTest
    {
        /// <summary>Mean of forward scans
        /// x axis: wavenumber [cm-1]
        /// x start: xStart
        /// x step: xStep
        /// y axis: mean  
        /// y start: 0.0
        /// </summary>
        private CCOVector m_MeanForward;

        /// <summary>Mean of reverse scans (see meanForward)</summary>
        private CCOVector m_MeanReverse;

        private CCOVector m_MeanAverage;

        /// <summary>Noise (standard deviation) of forward scans 
        /// x axis: wavenumber [cm-1]
        /// x start: xStart
        /// x step: xStep
        /// y axis: sigma / mean  
        /// y start: 0.0
        /// </summary>
        private CCOVector m_NoiseForward;

        /// <summary>Noise (standard deviation) of reverse scans (see noiseForward)</summary>
        private CCOVector m_NoiseReverse;

        private CCOVector m_NoiseAverage;

        /// <summary>Start value of x axis for noise and mean vector</summary>
        private double m_dbXStart;

        /// <summary>Step value of x axis for noise and mean vector</summary>
        private double m_dbXStep;

        /// -------------------------------------------------------------------
        /// <summary>Property</summary>
        public CCOVector MeanForward { get { return m_MeanForward; } }
        public CCOVector MeanReverse { get { return m_MeanReverse; } }
        public CCOVector MeanAverage { get { return m_MeanAverage; } }
        public CCOVector NoiseForward { get { return m_NoiseForward; } }
        public CCOVector NoiseReverse { get { return m_NoiseReverse; } }
        public CCOVector NoiseAverage { get { return m_NoiseAverage; } }
        public double xStart { get { return m_dbXStart; } }
        public double xStep { get { return m_dbXStep; } }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="p_MeanForward">Mean of forward scans</param>
        /// <param name="p_MeanReverse">Mean of reverse scans</param>
        /// <param name="p_NoiseForward">Noise (standard deviation) of forward scans</param>
        /// <param name="p_NoiseReverse">Noise (standard deviation) of reverse scans</param>
        /// <param name="p_iXStart">Start value of x axis</param>
        /// <param name="p_iXStep">Step value of x axis</param>
        public CDQResultNoiseTest(
            CCOVector p_MeanAverage,
            CCOVector p_MeanForward,
            CCOVector p_MeanReverse,
            CCOVector p_NoiseAverage,
            CCOVector p_NoiseForward,
            CCOVector p_NoiseReverse,
            double p_dbXStart,
            double p_dbXStep)
        {
            m_MeanAverage = p_MeanAverage;
            m_MeanForward = p_MeanForward;
            m_MeanReverse = p_MeanReverse;
            m_NoiseAverage = p_NoiseAverage;
            m_NoiseForward = p_NoiseForward;
            m_NoiseReverse = p_NoiseReverse;
            m_dbXStart = p_dbXStart;
            m_dbXStep = p_dbXStep;
        }
    }
}

namespace Buchi.DataAcquisition.Common
{ 
    /// -----------------------------------------------------------------------
    /// <summary>
    /// This class stores scan information
    /// </summary>
    [Serializable()]
    public class CDQScanInfo
    {
        /// <summary>Errors found in raw data</summary>
        public int RawDataReadingErrors;

        /// <summary>Error info</summary>
        public string ErrorInfo;

        /// <summary>State of scan (Error, ..)</summary>
        public EDQScanState ScanState;

        /// <summary>Forward peak</summary>
        public int PeakForward;

        /// <summary>Reverse peak</summary>
        public int PeakReverse;

        /// <summary>Forward peak value</summary>
        public double PeakForwardValue;

        /// <summary>Reverse peak value</summary>
        public double PeakReverseValue;

        /// <summary>Forward peak shift</summary>
        public int ShiftForward;

        /// <summary>Reverse peak shift</summary>
        public int ShiftReverse;

        /// -----------------------------------------------------------------------
        /// <summary>
        /// Set error state
        /// </summary>
        /// <param name="l_sErrorInfo"></param>
        /// <param name="p_eDQScanState"></param>
        public void SetError(string l_sErrorInfo, EDQScanState p_eDQScanState)
        {
            ErrorInfo = l_sErrorInfo;
            ScanState = p_eDQScanState;
        }
        /// -------------------------------------------------------------------
        /// <summary>
        /// Show full scan info as string used for debug output
        /// </summary>
        public override string ToString()
        {
            string l_sErrorInfo = ErrorInfo;

            // add new line for error info for nicer format
            if (ErrorInfo != null && ErrorInfo != "")
            {
                l_sErrorInfo = "    " + Environment.NewLine + l_sErrorInfo;
            }
            return "   State: " + ScanState +
                "   Peak fw: " + PeakForward +
                "   Peak rv: " + PeakReverse +
                "   Peak fw value: " + string.Format("{0,16}", PeakReverseValue) +
                "   Peak rv value: " + string.Format("{0,16}", PeakReverseValue) +
                "   Peak shift fw: " + ShiftForward +
                "   Peak shift rv: " + ShiftReverse +
                "   Raw data errors: " + RawDataReadingErrors +
                "   Error Info: " + l_sErrorInfo;
        }
    }

    /// -----------------------------------------------------------------------
    /// <summary>
    /// This class stores the scan information list
    /// </summary>
    [Serializable()]
    public class CDQResultScanInfoList
    {
        /// <summary>Contains error info items</summary>
        private List<CDQScanInfo> m_ScanList = new List<CDQScanInfo>();

        /// <summary>Properties</summary>
        public int CountScanPairs { get { return m_ScanList.Count; } }

        /// -----------------------------------------------------------------------
        /// <summary>
        /// Add an scan infor item
        /// </summary>
        /// <param name="p_sErrorText">Error reason</param>
        public void Add(CDQScanInfo p_ScanInfo)
        {
            m_ScanList.Add(p_ScanInfo);
        }

        /// -----------------------------------------------------------------------
        /// <summary>
        /// Get last item in list
        /// </summary>
        public CDQScanInfo GetCurrent()
        {
            if (m_ScanList.Count > 0)
            {
                return m_ScanList[m_ScanList.Count - 1];
            }
            else
            {
                return null;
            }
        }

        /// -----------------------------------------------------------------------
        /// <summary>
        /// Return info, if entry exists, else return null
        /// </summary>
        /// <param name="p_iItemNo">Position of item (0 .. Count-1) </param>
        public CDQScanInfo GetItem(int p_iItemNo)
        {
            if (p_iItemNo >= 0 && p_iItemNo < m_ScanList.Count)
            {
                return m_ScanList[p_iItemNo];
            }
            else
            {
                return null;
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Show full scan info as string used for debug output, with newline added, e.g.
        /// "eErrorBadReverseScanPeak - Bad reverse scan, peak: 2243, scan length: 4024, needed useful left points: 350"
        /// </summary>
        public override string ToString()
        {
            CDQScanInfo l_ScanInfo = null;
            string l_sInfo = "";

            for (int i = 0; i < m_ScanList.Count; i++)
            {
                l_ScanInfo = m_ScanList[i];
                l_sInfo += string.Format("{0,3}", (i + 1)) + l_ScanInfo.ToString() + System.Environment.NewLine;
            }
            return l_sInfo;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Get overview information of all scans in one measurment, e.g.
        /// 2 Error(s) - Bad reverse scan peak
        /// ********************************
        /// 2 Total error scan pairs
        /// 3 Total good scan pairs
        /// 5 Total scan pairs 
        /// </summary>
        public string GetErrorOverview()
        {
            string l_sResult = System.Environment.NewLine;
            Array l_StateArray = Enum.GetValues(typeof(EDQScanState));

            // get errors of raw data
            l_sResult += "***************************" + System.Environment.NewLine;
            l_sResult += "A) Raw data stream:" + System.Environment.NewLine;
            l_sResult += string.Format("{0,3}", CountErrorsRawData()) + " Total errors in raw data stream" + System.Environment.NewLine;
            l_sResult += System.Environment.NewLine;
            l_sResult += "***************************" + System.Environment.NewLine;
            l_sResult += "B) Scan Pairs:" + System.Environment.NewLine;

            // get all state informations
            foreach (int i in l_StateArray)
            {
                if ((EDQScanState)i != EDQScanState.eOk)
                {
                    l_sResult += GetErrorFromState((EDQScanState)i);
                }
            }

            // add total
            l_sResult += "--------------------------------------------------------" + System.Environment.NewLine;
            l_sResult += string.Format("{0,3}", CountErrors()) + " Total bad scan pairs" + System.Environment.NewLine;
            l_sResult += string.Format("{0,3}", GetErrorFromState(EDQScanState.eOk));
            l_sResult += string.Format("{0,3}", CountScanPairs) + " Total scan pairs";

            return l_sResult;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public string GetScanQualityOverview()
        {
            string l_sResult = System.Environment.NewLine;

            // get errors of raw data
            for (int i = 0; i < m_ScanList.Count; i++)
            {
                if (m_ScanList[i].ScanState == EDQScanState.eErrorScanQualityCheckFailed)
                {
                    l_sResult += "Scan No. " + i.ToString() + " " + m_ScanList[i].ErrorInfo + System.Environment.NewLine;
                }
            }

            return l_sResult;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Get infor string of one state, state name and count (e.g. 12 Bad raw data length)
        /// </summary>
        private string GetErrorFromState(EDQScanState p_eScanState)
        {
            string l_sResult = "";
            int l_iCount = CountState(p_eScanState);

            if (l_iCount > 0)
            {
                l_sResult = string.Format("{0,3}", l_iCount);
                switch (p_eScanState)
                {
                    case EDQScanState.eOk: { l_sResult += " Total good scan pairs"; break; }
                    case EDQScanState.eErrorBadRawDataLength: { l_sResult += " Error(s) - Bad raw data length"; break; }
                    case EDQScanState.eErrorNotEnoughZeroPoints: { l_sResult += " Error(s) - Not enough zero points"; break; }
                    case EDQScanState.eErrorBadLaserAmplitude: { l_sResult += " Error(s) - Bad laser amplitude"; break; }
                    case EDQScanState.eErrorPeakDeviationForward: { l_sResult += " Error(s) - Peak forward deviation"; break; }
                    case EDQScanState.eErrorPeakDeviationReverse: { l_sResult += " Error(s) - Peak reverse deviation"; break; }
                    case EDQScanState.eErrorScanWindowTooShort: { l_sResult += " Error(s) - Scan window is too small"; break; }
                    case EDQScanState.eErrorBadForwardScanPeak: { l_sResult += " Error(s) - Bad forward scan peak"; break; }
                    case EDQScanState.eErrorBadReverseScanPeak: { l_sResult += " Error(s) - Bad reverse scan peak"; break; }
                    case EDQScanState.eErrorBadSpeed: { l_sResult += " Error(s) - Bad speed"; break; }
                    case EDQScanState.eErrorScanQualityCheckFailed: { l_sResult += " Error(s) - Quality Check Failed"; break; }
                    default: { Trace.Fail("DQ: Invalid arg"); break; }
                }
                l_sResult += Environment.NewLine;
            }
            return l_sResult;
        }

        /// -----------------------------------------------------------------------
        /// <summary>
        /// Return total number of error sequences (excluding raw data errors)
        /// </summary>
        /// <returns>Total error number</returns>
        public int CountErrors()
        {
            int l_iErrorCount = 0;

            foreach (object l_obj in m_ScanList)
            {
                if (((CDQScanInfo)l_obj).ScanState != EDQScanState.eOk)
                {
                    l_iErrorCount++;
                }
            }
            return l_iErrorCount;
        }

        /// -----------------------------------------------------------------------
        /// <summary>
        /// Return total number of bad raw data sequences
        /// (type: 0er, error, unknown states)
        /// </summary>
        /// <returns>Total error number</returns>
        public int CountErrorsRawData()
        {
            int l_iErrorCount = 0;

            foreach (CDQScanInfo l_info in m_ScanList)
            {
                l_iErrorCount += l_info.RawDataReadingErrors;
            }
            return l_iErrorCount;
        }

        /// -----------------------------------------------------------------------
        /// <summary>
        /// Return number of searched state
        /// </summary>
        /// <returns>Total number of state</returns>
        public int CountState(EDQScanState l_eScanState)
        {
            int l_iCount = 0;

            foreach (object l_obj in m_ScanList)
            {
                if (((CDQScanInfo)l_obj).ScanState == l_eScanState)
                {
                    l_iCount++;
                }
            }
            return l_iCount;
        }
    }
}