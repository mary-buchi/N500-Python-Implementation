using Buchi.DataAcquisition;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace N500_DSP
{
    /// <summary>
    /// Provides static methods for calling "original" N-500 digital signal processing code
    /// </summary>
    public static class DSP
    {
        /// -------------------------------------------------------------------
        /// <summary>
        /// Set the configuration.
        /// Call this before measuring, if you don't want to use the default settings.
        /// </summary>
        public static void SetConfiguration(string json)
        {
            var objects = JObject.Parse(json);
            DQSIController.AdcDelay = double.Parse(objects.GetValue("adcDelay").ToString());
            DQSIController.DispersionCorrectionCoefficient1 = double.Parse(objects.GetValue("dispersionCorrectionCoefficient1").ToString());
            DQSIController.DispersionCorrectionCoefficient2 = double.Parse(objects.GetValue("dispersionCorrectionCoefficient2").ToString());
            DQSIController.DispersionCorrectionCoefficient3 = double.Parse(objects.GetValue("dispersionCorrectionCoefficient3").ToString());
            DQSIController.DispersionCorrectionCoefficient4 = double.Parse(objects.GetValue("dispersionCorrectionCoefficient4").ToString());
            DQSIController.DispersionCorrectionCoefficientB1 = double.Parse(objects.GetValue("dispersionCorrectionCoefficientB1").ToString());
            DQSIController.DispersionCorrectionCoefficientB2 = double.Parse(objects.GetValue("dispersionCorrectionCoefficientB2").ToString());
            DQSIController.DispersionCorrectionCoefficientT0 = double.Parse(objects.GetValue("dispersionCorrectionCoefficientT0").ToString());
            DQSIController.CenterAverageApplied = Boolean.Parse(objects.GetValue("centerAverageApplied").ToString());
            DQSIController.ChannelDelay = double.Parse(objects.GetValue("channelDelay").ToString());
            DQSIController.FullScan = Boolean.Parse(objects.GetValue("fullScan").ToString());
            DQSIController.FullScanResolution = int.Parse(objects.GetValue("fullScanResolution").ToString());
            DQSIController.HalfScanResolution = int.Parse(objects.GetValue("halfScanResolution").ToString());
            DQSIController.InterferogramSizeFullScan = int.Parse(objects.GetValue("interferogramSizeFullScan").ToString());
            DQSIController.InterferogramSizeHalfScan = int.Parse(objects.GetValue("interferogramSizeHalfScan").ToString());
            DQSIController.InvalidScanStartCheck = int.Parse(objects.GetValue("invalidScanStartCheck").ToString());
            DQSIController.IsolateScanWindow = int.Parse(objects.GetValue("isolateScanWindow").ToString());
            DQSIController.LaserLambda = double.Parse(objects.GetValue("laserLambda").ToString());
            DQSIController.MaxAllowedRelativeError = double.Parse(objects.GetValue("maxAllowedRelativeError").ToString());
            DQSIController.MaxDataSize = int.Parse(objects.GetValue("maxDataSize").ToString());
            DQSIController.MaxInvalidScanPercentage = int.Parse(objects.GetValue("maxInvalidScanPercentage").ToString());
            DQSIController.MaxPeakDeviation = int.Parse(objects.GetValue("maxPeakDeviation").ToString());
            DQSIController.MaxScanQualityFailurePercentage = int.Parse(objects.GetValue("maxScanQualityFailurePercentage").ToString());
            DQSIController.MaxVelocityDeviationPercentage = int.Parse(objects.GetValue("maxVelocityDeviationPercentage").ToString());
            DQSIController.MinDeltaSignal = double.Parse(objects.GetValue("minDeltaSignal").ToString());
            DQSIController.MinLaserPPAmplitude = int.Parse(objects.GetValue("minLaserPpAmplitude").ToString());
            DQSIController.PeakTargetForwardLeftSide = int.Parse(objects.GetValue("peakTargetForwardLeftSide").ToString());
            DQSIController.PeakTargetReverseLeftSide = int.Parse(objects.GetValue("peakTargetReverseLeftSide").ToString());
            DQSIController.PeakSearchWindow = int.Parse(objects.GetValue("peakSearchWindow").ToString());
            DQSIController.PhaseCorrectionWindowSize = int.Parse(objects.GetValue("phaseCorrectionWindowSize").ToString());
            DQSIController.RobustnessOn = Boolean.Parse(objects.GetValue("robustnessOn").ToString());
            DQSIController.RegularSample = Boolean.Parse(objects.GetValue("regularSample").ToString());
            DQSIController.SamplingFrequency = uint.Parse(objects.GetValue("samplingFrequency").ToString());
            DQSIController.TransfilterOn = bool.Parse(objects.GetValue("transfilterOn").ToString());
            DQSIController.TransfilterParam_ndiv_Regular2 = double.Parse(objects.GetValue("transfilterParam_ndiv_Regular2").ToString());
            DQSIController.TransfilterParam_ndiv_Tablets2 = double.Parse(objects.GetValue("transfilterParam_ndiv_Tablets2").ToString());
            DQSIController.TransfilterParam_s_Regular2 = double.Parse(objects.GetValue("transfilterParam_s_Regular2").ToString());
            DQSIController.TransfilterParam_s_Tablets2 = double.Parse(objects.GetValue("transfilterParam_s_Tablets2").ToString());
            DQSIController.UsefulLeftPoints = int.Parse(objects.GetValue("usefulLeftPoints").ToString());
            DQSIController.UsefulPointsFullScan = int.Parse(objects.GetValue("usefulPointsFullScan").ToString());
            DQSIController.UsefulPointsHalfScan = int.Parse(objects.GetValue("usefulPointsHalfScan").ToString());
            DQSIController.WaveNumbers = int.Parse(objects.GetValue("waveNumbers").ToString());
            DQSIController.WaveNumberStart = double.Parse(objects.GetValue("waveNumberStart").ToString());
            DQSIController.WaveNumberStep = double.Parse(objects.GetValue("waveNumberStep").ToString());
            DQSIController.ZeroFillingFindPeaks = int.Parse(objects.GetValue("zeroFillingFindPeaks").ToString());
            DQSIController.ZeroFillingFindPeaks = int.Parse(objects.GetValue("zeroFillingFindPeaks").ToString());
            DQSIController.ZeroFillingCenterAverage = int.Parse(objects.GetValue("zeroFillingCenterAverage").ToString());
            DQSIController.ZeroFillingPhaseCorrection = int.Parse(objects.GetValue("zeroFillingPhaseCorrection").ToString());
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Set the DSP filters.
        /// Call this before measuring.
        /// </summary>
        public static void SetDspFilters(string laserFilterPath, string detectorFilterPath,
            string detectorFilterLp2Path)
        {
            // load laser filter coefficients
            List<string> nums = File.ReadLines(laserFilterPath).ToList();
            double[] laserFilter = new double[nums.Count];

            foreach (var (v, i) in nums.Select((v, i) => (v, i)))
            {
                laserFilter[i] = Double.Parse(v);
            }

            // load detector filter coefficients
            nums = File.ReadLines(detectorFilterPath).ToList();
            double[] detectorFilter = new double[nums.Count];

            foreach (var (v, i) in nums.Select((v, i) => (v, i)))
            {
                detectorFilter[i] = Double.Parse(v);
            }

            // load detector filter LP2 coefficients
            nums = File.ReadLines(detectorFilterLp2Path).ToList();
            double[] detectorFilterLp2 = new double[nums.Count];

            foreach (var (v, i) in nums.Select((v, i) => (v, i)))
            {
                detectorFilterLp2[i] = Double.Parse(v);
            }

            DQSIController.LaserFilter = laserFilter;
            DQSIController.DetectorFilter = detectorFilter;
            DQSIController.DetectorFilterLp2 = detectorFilterLp2;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Initialize the various measurement classe. Call this once at the
        /// start of the program using this dll.
        /// </summary>
        public static void Init()
        {
            CDQStateRecordingInvalidData.Create();
            CDQStateRecordingStartMeasurement.Create();
            CDQStateRecordingReadData.Create();
            CDQStateRecordingResultRawData.Create();
            CDQStateRecordingFilterDataPackage.Create();
            CDQStateRecordingResultFilteredData.Create();
            CDQStateRecordingCheckScanQuality.Create();
            CDQStateRecordingDetectLaserZeroPoints.Create();
            CDQStateRecordingResultInterpolatedData.Create();
            CDQStateRecordingSampleAtZeroPoints.Create();
            CDQStateRecordingFindScanWindows.Create();
            CDQStateRecordingGetSpeedVector.Create();
            CDQStateRecordingResultSpeed.Create();
            CDQStateRecordingFindPeaks.Create();
            CDQStateRecordingIsolateScans.Create();
            CDQStateRecordingAverageScans.Create();
            CDQStateRecordingCenterAveraged.Create();
            CDQStateSpectraPhaseCorrection.Create();
            CDQStateSpectraRaw.Create();
            CDQStateSpectraDispersionCorrection.Create();
            CDQStateRecordingNoiseTest.Create();
            CDQStateRecordingResultNoiseTest.Create();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Start a new measurement. Clear the stored data from previous measurement.
        /// </summary>
        public static void StartMeasurement(int scanPairTotal, bool noiseTest = false)
        {
            DQSIController.ScanPairTotal = scanPairTotal;
            DQSIController.NoiseTest = noiseTest;

            CDQStateRecordingStartMeasurement.GetInstance().Do();
        }

        public static void AddDataPackage(byte[] dataPackage)
        {
            CDQStateRecordingStartMeasurement.GetInstance().AddDataPackage(dataPackage);
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Measure the speed of the scans.
        /// </summarr>
        public static void DoSpeedMeasurement(
            out double[] timeForward,
            out double[] timeReverse,
            out double[] speedForward,
            out double[] speedReverse)
        {
            ReadDataPackage();
            FilterDataPackage();
            InterpolateAtZeroCrossings();
            FindScanWindows();
            GetSpeedVector(
                out timeForward,
                out timeReverse,
                out speedForward,
                out speedReverse);
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Do a complete measurement, calculating the interferograms and the
        /// spectra.
        /// </summary>
        public static void DoSpectraMeasurement()
        {
            ReadDataPackage();
            FilterDataPackage();
            InterpolateAtZeroCrossings();
            FindScanWindows();
            GetSpeedVector();
            FindPeaks();
            IsolateScans();
            AverageScans();
        }

        /// <summary>
        /// Do a noise test.
        /// </summary>
        public static void DoNoiseTest()
        {
            DoSpectraMeasurement();
            CDQStateSpectraPhaseCorrection.GetInstance().Do();
            CDQStateSpectraRaw.GetInstance().Do();
            CDQStateSpectraDispersionCorrection.GetInstance().Do();
            CDQStateRecordingNoiseTest.GetInstance().Do();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Read the data package and create raw forward/reverse scans.
        /// </summary>
        public static void ReadDataPackage()
        {
            CDQStateRecordingReadData.GetInstance().Do();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Read the data package and create raw forward/reverse scans and return
        /// the created data. 
        /// </summary>
        public static void ReadDataPackage(out double[] detector, out double[] laser, out double xStep)
        {
            ReadDataPackage();

            var result = CDQStateRecordingResultRawData.GetInstance().Do();
            detector = result.Interferogram.GetNativeBuffer();
            laser = result.Laser.GetNativeBuffer();
            xStep = result.xStep;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Filter the data package.
        /// </summary>
        public static void FilterDataPackage()
        {
            CDQStateRecordingFilterDataPackage.GetInstance().Do();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Filter the data package with results
        /// </summary>
        public static void FilterDataPackage(out double[] detector, out double[] laser, out double xStep)
        {
            FilterDataPackage();

            var result = CDQStateRecordingResultFilteredData.GetInstance().Do();
            detector = result.Interferogram.GetNativeBuffer();
            laser = result.Laser.GetNativeBuffer();
            xStep = result.xStep;
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Interpolate detector signal at the zero crossing points of the laser signal
        /// </summary>
        public static void InterpolateAtZeroCrossings()
        {
            CDQStateRecordingDetectLaserZeroPoints.GetInstance().Do();
            CDQStateRecordingSampleAtZeroPoints.GetInstance().Do();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Interpolate detector signal at the zero crossing points of the laser signal
        /// and return the resultant data.
        /// </summary>
        public static void InterpolateAtZeroCrossings(out double[] time, out double[] detector)
        {
            InterpolateAtZeroCrossings();

            var result = CDQStateRecordingResultInterpolatedData.GetInstance().Do();
            time = result.Time.GetNativeBuffer();
            detector = result.Interferogram.GetNativeBuffer();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Find the scan windows for the current measurement.
        /// </summary>
        public static void FindScanWindows()
        {
            CDQStateRecordingFindScanWindows.GetInstance().Do();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Get the speed vector.
        /// </summary>
        public static void GetSpeedVector()
        {
            CDQStateRecordingGetSpeedVector.GetInstance().Do();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Get the speed vector and return the speed vectors
        /// </summary>
        public static void GetSpeedVector(
            out double[] timeForward,
            out double[] timeReverse,
            out double[] speedForward,
            out double[] speedReverse)
        {
            GetSpeedVector();

            var result = CDQStateRecordingResultSpeed.GetInstance().Do();
            timeForward = result.TimeForward.GetNativeBuffer();
            timeReverse = result.TimeReverse.GetNativeBuffer();
            speedForward = result.SpeedForward.GetNativeBuffer();
            speedReverse = result.SpeedReverse.GetNativeBuffer();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Find the scan peaks.
        /// </summary>
        public static void FindPeaks()
        {
            CDQStateRecordingFindPeaks.GetInstance().Do();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Shift the scans to the same peak point and reverse the "reverse" scans.
        /// </summary>
        public static void IsolateScans()
        {
            CDQStateRecordingIsolateScans.GetInstance().Do();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Average continously the scans of the current measurement.
        /// After reaching the requested scans count, the average is centered
        /// to the peak.
        /// </summary>
        public static void AverageScans()
        {
            CDQStateRecordingAverageScans.GetInstance().Do();
        }

        //public static void CenterAveragedScans()
        //{
        //    CDQStateRecordingCenterAveraged.GetInstance().Do();
        //}

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns the centered average forward and reverse scans
        /// </summary>
        /// <param name="centeredForward"></param>
        /// <param name="centeredReverse"></param>
        public static void GetCenterAveragedScans(out double[] centeredForward, out double[] centeredReverse)
        {
            centeredForward = CDQStateRecordingCenterAveraged.GetInstance().CenteredForward.Vector.GetNativeBuffer();
            centeredReverse = CDQStateRecordingCenterAveraged.GetInstance().CenteredReverse.Vector.GetNativeBuffer();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Calculate the forward and reverse spectra from the interferograms.
        /// </summary>
        public static void Spectra(
            out double[] interferogramForward, out double[] interferogramReverse, out int xStart,
            out double[] spectrumForward, out double[] spectrumReverse,
            out double[] spectrumAverage, out double[] wnAxis)
        {
            CDQStateRecordingCenterAveraged.GetInstance().Do();
            CDQStateSpectraPhaseCorrection.GetInstance().Do();
            CDQStateSpectraRaw.GetInstance().Do();
            CDQStateSpectraDispersionCorrection.GetInstance().Do();

            var result = CDQStateSpectraDispersionCorrection.GetInstance().SignalPackageCompletion();
            interferogramForward = result.ForwardInterferogram.Vector.GetNativeBuffer();
            interferogramReverse = result.ForwardInterferogram.Vector.GetNativeBuffer();
            xStart = result.XStartInterferogram;
            spectrumForward = result.ForwardSpectra.Vector.GetNativeBuffer();
            spectrumReverse = result.ReverseSpectra.Vector.GetNativeBuffer();
            spectrumAverage = result.AverageSpectra.Vector.GetNativeBuffer();

            // Calculate wave number axis
            var wnStart = result.AverageSpectra.XStart;
            var wnStep = result.AverageSpectra.DataResolution;
            wnAxis = new double[result.AverageSpectra.Vector.Length];
            for (var i = 0; i < result.AverageSpectra.Vector.Length; i++)
            {
                wnAxis[i] = wnStart + wnStep * i;
            }
        }

        public static void NoiseTest(
            out double[] meanForward, out double[] meanReverse, out double[] meanAverage,
            out double[] noiseForward, out double[] noiseReverse, out double[] noiseAverage,
            out double xStart, out double xStep)
        {
            var result = CDQStateRecordingResultNoiseTest.GetInstance().Result;

            meanForward = result.MeanForward.GetNativeBuffer();
            meanReverse = result.MeanReverse.GetNativeBuffer();
            meanAverage = result.MeanAverage.GetNativeBuffer();

            noiseForward = result.NoiseForward.GetNativeBuffer();
            noiseReverse = result.NoiseReverse.GetNativeBuffer();
            noiseAverage = result.NoiseAverage.GetNativeBuffer();

            xStart = result.xStart;
            xStep = result.xStep;
        }
    }
}
