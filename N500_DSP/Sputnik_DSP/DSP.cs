using Buchi.Core.Math;
using System;
using System.Linq;
using System.Text.Json;

namespace Sputnik_DSP
{
    class Configuration
    {
        // Delay of ADC in seconds
        internal double AdcDelay { get; set; } = 0.00044698;
        // Interferogram: True if center average has to be used (disable this flag only for tests)
        internal bool CenterAverageApplied { get; set; } = true;
        // Delay between laser and interferogram channels in seconds
        internal double ChannelDelay { get; set; } = -0.0000023;
        // PhaseCorrection: Coefficient 1 used in dispersion correction
        internal double DispersionCorrectionCoefficient1 { get; set; } = 0.139242676;
        // PhaseCorrection: Coefficient 2 used in dispersion correction
        internal double DispersionCorrectionCoefficient2 { get; set; } = 0.005021617;
        // PhaseCorrection: Coefficient 3 used in dispersion correction
        internal double DispersionCorrectionCoefficient3 { get; set; } = 0.000323913;
        // PhaseCorrection: Coefficient 4 used in dispersion correction
        internal double DispersionCorrectionCoefficient4 { get; set; } = -0.000528157;
        // PhaseCorrection: Coefficient b1 used in dispersion correction
        internal double DispersionCorrectionCoefficientB1 { get; set; } = 2.76E-07;
        // PhaseCorrection: Coefficient b2 used in dispersion correction
        internal double DispersionCorrectionCoefficientB2 { get; set; } = 3.12E-07;
        // PhaseCorrection: Coefficient t0 used in dispersion correction
        internal double DispersionCorrectionCoefficientT0 { get; set; } = 36;
        // Running a full scan
        internal bool FullScan { get; set; } = true;
        // Interferogram: Resolution of full scan (only for documentation)
        internal int FullScanResolution { get; set; } = 8;
        // Interferogram: Resolution of full scan (only for documentation)
        internal int HalfScanResolution { get; set; } = 16;
        // Interferogram: Size of interferogram in full scan
        internal int InterferogramSizeFullScan { get; set; } = 2532;
        // Interferogram: Size of interferogram in half scan
        internal int InterferogramSizeHalfScan { get; set; } = 1300;
        // Interferogram: Start 'invalid scan percentage check' after reaching this limit
        internal int InvalidScanStartCheck { get; set; } = 5;
        // Interferogram: Use this search interval (+/-) around the peak to shift scans according to the reference scan
        internal int IsolateScanWindow { get; set; } = 64;
        // PhaseCorrection: HeNe-laser wavelength
        internal double LaserLambda { get; set; } = 6.33E-07;
        // ScanQualityCheck: Testvalue for a scan to be accepted (deltaNoise/deltaSignal)max>MaxAllowedRelativeError
        internal double MaxAllowedRelativeError { get; set; } = 0.1;
        // Max size in bytes of a data package read from the control board
        internal int MaxDataSize { get; set; } = 409600;
        // Interferogram: [%] Maximal allowed percentage of invalid scans in one measurement
        internal int MaxInvalidScanPercentage { get; set; } = 20;
        // Interferogram: Maximal allowed (+/-) point deviation from 1. Scan
        internal int MaxPeakDeviation { get; set; } = 256;
        // Interferogram: [%] Maximal allowed deviation of velocity of wedge drive in percentage
        internal int MaxVelocityDeviationPercentage { get; set; } = 20;
        // ScanQualityCheck: Min. Signal amplitude for the check to be performed (otherwise the scan is always ok)
        internal double MinDeltaSignal { get; set; } = 100.0;
        // Minimal required peak to peak amplitude in the laser signal
        internal int MinLaserPPAmplitude { get; set; } = 150;
        // Interferogram: Use this search interval (+/-) around the target peak to find the measured peak (power of 2)
        internal int PeakSearchWindow { get; set; } = 512;
        // Interferogram: Target value of peak in a forward scan (in FindPeak), measured from the left, small side
        internal int PeakTargetForwardLeftSide { get; set; } = 800;
        // Interferogram: Target value of peak in a reverse scan (in FindPeak), measured from the left, small side
        internal int PeakTargetReverseLeftSide { get; set; } = 800;
        // PhaseCorrection:Used window size in phase correction
        internal int PhaseCorrectionWindowSize { get; set; } = 512;
        // Interferogram: 1 = regular sample, 0 = tablets (used in DispersionCorrection)
        internal bool RegularSample { get; set; } = true;
        // ScanQualityCheck: 1 (true) = scan quality check enabled; 0 (false) = disabled
        internal bool RobustnessOn { get; set; } = false;
        // Used sampling frequency in Hz
        internal uint SamplingFrequency { get; set; } = 86805;
        // PhaseCorrection: This flag tells if the transfilter flag is used (1 = on, 0 = off)
        internal bool TransfilterOn { get; set; } = false;
        // PhaseCorrection: Parameter ndiv is used in the regular transfilter
        internal double TransfilterParam_ndiv_Regular2 { get; set; } = 9.5;
        // PhaseCorrection: Parameter ndiv is used in the transfilter for tablets
        internal double TransfilterParam_ndiv_Tablets2 { get; set; } = 6.5;
        // PhaseCorrection: Parameter s is used in the regular transfilter
        internal double TransfilterParam_s_Regular2 { get; set; } = 8;
        // PhaseCorrection:Parameter s is used in the transfilter for tablets
        internal double TransfilterParam_s_Tablets2 { get; set; } = 9;
        // Number of useful points on the left side (forward scan) of the peak
        internal int UsefulLeftPoints { get; set; } = 351;
        // Number of useful points on the right side (forward scan) of the peak
        // for a full scan
        internal int UsefulPointsFullScan { get; set; } = 3400;
        // Number of useful points on the right side (forward scan) of the peak
        // for a half scan
        internal int UsefulPointsHalfScan { get; set; } = 1700;
        // PhaseCorrection: Number of points in spectra
        internal int WaveNumbers { get; set; } = 1501;
        // PhaseCorrection: Starting wave number (used in DispersionCorrection)
        internal double WaveNumberStart { get; set; } = 4000;
        // PhaseCorrection:Steps of wave number  (used in DispersionCorrection)
        internal double WaveNumberStep { get; set; } = 4;
        // Interferogram: Number of applied zero filling in Center Average
        internal int ZeroFillingCenterAverage { get; set; } = 8;
        // Interferogram: Number of applied zero filling in Find Peaks
        internal int ZeroFillingFindPeaks { get; set; } = 4;
        // PhaseCorrection: Number of applied zero filling in Phase Correction
        internal int ZeroFillingPhaseCorrection { get; set; } = 8;

        // Computed properties
        // Initial data shift of a scan in seconds. Depends
        // on ADC delay and sampling frequency
        internal int DataShift => (int)Math.Round(AdcDelay * SamplingFrequency);
        // The time for a given sample index
        internal double GetTimeFromSample(double sample) => sample / SamplingFrequency;
        // The interferogram size depends on doing a full or half scan
        internal int InterferogramSize => FullScan ? InterferogramSizeFullScan : InterferogramSizeHalfScan;
        // The minimal size of a raw scan
        internal int MinRawDataSize => 4 * (FullScan ? UsefulPointsFullScan : UsefulPointsHalfScan);
        // The transfilter parameters, depending on beeing a regular measurement cell
        internal double TransfilterParam_ndiv => RegularSample ? TransfilterParam_ndiv_Regular2 : TransfilterParam_ndiv_Tablets2;
        internal double TransfilterParam_s => RegularSample ? TransfilterParam_s_Regular2 : TransfilterParam_s_Tablets2;
        // Number of useful points in a scan
        internal int UsefulPointsPerScan => FullScan ? UsefulPointsFullScan : UsefulPointsHalfScan;
    }

    /// <summary>
    /// Provides DSP functions based on original N-500 DSP implementation. It uses the original
    /// math libraries with their original project and class names.
    /// Only DSP functions are provided, no state is retained, all state must be handled
    /// by the calling code. Conversion of byte arrays to meaningful double or integer
    /// arrays is not part of this library.
    /// </summary>
    public static class DSP
    {
        static Configuration cfg = new Configuration();

        /// <summary>
        /// Set the configuration parameters. Use this if other values than the
        /// default values are used.
        /// </summary>
        /// <param name="configurationJson"></param>
        public static void InitConfiguration(string configurationJson)
        {
            cfg = JsonSerializer.Deserialize<Configuration>(configurationJson);
        }

        /// <summary>
        /// Apply apodization on start and end of data with a given border length.
        /// This is used for apodization of the laser signal.
        /// </summary>
        /// <param name="data">The data to apply apodization</param>
        /// <param name="borderLength">The length of the border area to apply apodization</param>
        /// <returns></returns>
        public static double[] ApplyApodization(double[] data, int borderLength)
        {
            var middleLength = data.Length - 2 * borderLength;
            var borderVec = new CCOVector(borderLength);
            var middleVec = new CCOVector(middleLength);
            borderVec.FillSelection(0, borderLength, 1.0);
            middleVec.FillSelection(0, middleLength, 1.0);
            DoWeighting(borderVec);
            CCOVector[] appodList = { borderVec, middleVec, borderVec.Reverse() };
            var appodVec = new CCOVector(appodList);

            var dataVec = new CCOVector(data);
            dataVec *= appodVec;

            return dataVec.GetNativeBuffer();
        }

        private static void DoWeighting(CCOVector vec)
        {
            var length = vec.Length;

            for (var i = 0; i < vec.Length; i++)
            {
                var scale = 0.5 * (1.0 - System.Math.Cos(System.Math.PI * (i + 1.0) / length));
                vec[i] *= scale;
            }
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Apply a FIR filter to a data array.
        /// Apply apodization to laser singal before applying the FIR filter to it.
        /// </summary>
        /// <param name="data"></param>
        /// <param name="firFilter"></param>
        /// <returns></returns>
        public static double[] ApplyFIRFilter(double[] data, double[] firFilter)
        {
            var filteredVec = CCOVector.Conv(new CCOVector(data), new CCOVector(firFilter));

            return filteredVec.GetNativeBuffer();
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Check if the data has a minimal peak to peak amplitude.
        /// Call this before calling DetectZeroCrossings.
        /// Depends on Configuration:
        /// - MinLaserPPAmplitude
        /// </summary>
        /// <param name="data"></param>
        /// <returns></returns>
        public static bool CheckPeak2PeakAmplitude(double[] data)
        {
            var threshold = CalculateThreshold(data);
            return threshold >= cfg.MinLaserPPAmplitude;
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Detect the zero crossings of data.
        /// Verify that the peak to peak amplitude of the data is good enough
        /// before calling this function.
        /// Does not depend on Configuration.
        /// </summary>
        /// <param name="data"></param>
        /// <param name="zeroCrossings"></param>
        /// <returns></returns>
        public static void DetectZeroCrossings(double[] data, out double[] zeroCrossings)
        {
            var threshold = CalculateThreshold(data);
            var sampleCount = 0;
            var xis = 0.0;
            var zeroCrossingFound = false;
            var dataVec = new CCOVector(data);
            var zeroCrossingsVec = new CCOVector(dataVec.Length / 4);
            var zeroCrossingsCount = 0;
            var trippleIndex = 0;

            while (sampleCount < dataVec.Length - 3)
            {
                zeroCrossingFound = false;

                // Ignore noise values below the threshold
                while (Math.Abs(dataVec[sampleCount]) < threshold && sampleCount < dataVec.Length - 3)
                {
                    sampleCount++;
                }

                // Calculate next zero crossing
                while (!zeroCrossingFound && sampleCount < dataVec.Length - 3)
                {
                    // Find two points near 0, a positive and a negative point
                    if ((dataVec[sampleCount + 1] > 0 && dataVec[sampleCount + 2] <= 0) ||
                        (dataVec[sampleCount + 1] < 0 && dataVec[sampleCount + 2] >= 0))
                    {
                        // Resize vector if it is too short (should actually not happen)
                        if (zeroCrossingsVec.Length <= zeroCrossingsCount)
                        {
                            zeroCrossingsVec.Resize(zeroCrossingsCount + 100);
                        }

                        // Set tripple index to the first of the next three points
                        trippleIndex = sampleCount;

                        // Take the two points around 0 and find the closest point to 0. Increment
                        // the triple counter if necessary to get afterwards the 3 points which
                        // are closest to 0. So, the window is reduced from 4 points (2 positive,
                        // 2 negative) to the closest 3 points.
                        if (dataVec[sampleCount] > 0)
                        {
                            // negative slope
                            if (dataVec[sampleCount + 1] + dataVec[sampleCount + 2] > 0)
                            {
                                trippleIndex++;
                            }
                        }
                        else
                        {
                            // positive slope
                            if (dataVec[sampleCount + 1] + dataVec[sampleCount + 2] < 0)
                            {
                                trippleIndex++;
                            }
                        }

                        // Use the three found points and do a sinus interpolation
                        var y1 = dataVec[trippleIndex];
                        var y2 = dataVec[trippleIndex + 1];
                        var y3 = dataVec[trippleIndex + 2];

                        xis = DoSinusInterpolation(y1, y2, y3);

                        zeroCrossingsVec[zeroCrossingsCount] = xis + trippleIndex + 1;
                        zeroCrossingsCount++;
                        zeroCrossingFound = true;
                    }
                    sampleCount++;
                }
            }
            // Resize the zero crossings vector to the number of found zero crossings.
            // Do not use the last zero. It might be too close to the end of the data.
            zeroCrossingsVec.Resize(zeroCrossingsCount - 1);

            zeroCrossings = zeroCrossingsVec.GetNativeBuffer();
        }

        private static double CalculateThreshold(double[] data)
        {
            var diff = data.Max() - data.Min();
            var threshold = (0.5 * diff) / 3;

            return threshold;
        }

        private static double DoSinusInterpolation(double y1, double y2, double y3)
        {
            var szc = GetSign(y3);
            var xis = 0.0;

            if (y2 != 0)                                // if y(2)~=0,
            {
                var ck = (y3 + y1) / (2 * y2);          // ck=(y(3)+y(1))/(2*y(2));

                // ensure div 0 is not allowed
                if (ck < 1 && ck > -1)
                {
                    var kx = Math.Acos(ck);             // kx=acos(ck);
                    var phi =
                        Math.Atan(                                              // phi=atan(
                        Math.Sqrt(                                              // sqrt(
                        Math.Abs((y2 * y2) - Math.Pow(((y3 + y1) / 2), 2)) /    // abs((y(2)^2-((y(3)+y(1))/2)^2)/
                        Math.Pow(((y3 - y1) / 2), 2)));                         // ((y(3)-y(1))/2)^2)));
                    xis = phi / kx;                     // xis=phi/kx;
                    if (szc * GetSign(y2) == 1.0)       // if (szc*sign(y(2))==1),
                    {
                        xis = -xis;                     // xis=-xis;  ?????             
                    }
                }
                else
                {
                    // linear interpolation
                    xis = -2 * y2 / (y3 - y1);          // xis=-2*y(2)/(y(3)-y(1));
                }
            }
            else
            {
                xis = 0.0;
            }

            if (Double.IsNaN(xis))    // set xis to 0 if a div by 0 occured
            {
                // this line should not be reached!
                xis = 0.0;
            }

            return xis;
        }

        private static double GetSign(double number)
        {
            return number > 0.0 ? 1.0 : number < 0.0 ? -1.0 : 0.0;
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Given detector data, interpolate the data on the laser signal zero crossings.
        /// For interpolating the detector values at the zero-crossings of the laser signal,
        /// The time axis is calculated and the interpolated signal as well the time axis
        /// are returned in out parameters.
        /// Depends on Configuration:
        /// - SamplingFrequency
        /// - ChannelDelay
        /// </summary>
        /// <param name="zeroCrossings">Zero crossings of laser signal</param>
        /// <param name="detectorData">The filtered detector data</param>
        /// <param name="timeAxis">The time axis of the interpolated detector values</param>
        /// <param name="interpolatedDetectorData">The interpolated detector values</param>
        public static void InterpolateDetectorData(
            double[] zeroCrossings,
            double[] detectorData,
            out double[] timeAxis,
            out double[] interpolatedDetectorData)
        {
            // Build time axis
            var timeVec = new CCOVector(detectorData.Length);
            var timeStep = 1.0 / cfg.SamplingFrequency;

            for (var i = 0; i < timeVec.Length; i++)
            {
                timeVec[i] = timeStep * i;
            }

            // Correct time of zero crossings
            var laserZeroCrossingsVec = new CCOVector(zeroCrossings);
            var correctedZeroCrossingsVec = laserZeroCrossingsVec / cfg.SamplingFrequency;
            correctedZeroCrossingsVec += cfg.ChannelDelay;

            CCOVector sampleAtZeros;
            var ok = new CCOVector().FreeCubicSpline(timeVec, new CCOVector(detectorData), correctedZeroCrossingsVec, out sampleAtZeros);

            var ifg = new CCOMatrix(zeroCrossings.Length, 2); // Col 0: time information, Col 1: sample data

            Console.WriteLine($"samples at zeros length: {sampleAtZeros.Length}, ifg Rows: {ifg.nrow}");
            // sampled data
            ifg.SetColVector(1, sampleAtZeros);

            // sampled time axis
            for (var i = 0; i < zeroCrossings.Length; i++)
            {
                ifg[i][0] = zeroCrossings[i] / cfg.SamplingFrequency;
            }

            timeAxis = ifg.GetColVector(0).GetNativeBuffer();
            interpolatedDetectorData = ifg.GetColVector(1).GetNativeBuffer();
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Returns the start and end indices of the forward and reverse scans.
        /// Does not depend on Configuration.
        /// </summary>
        /// <param name="zeroCrossings"></param>
        /// <param name="startFwd"></param>
        /// <param name="endFwd"></param>
        /// <param name="startRev"></param>
        /// <param name="endRev"></param>
        public static void FindScanWindows(double[] zeroCrossings, out int startFwd, out int endFwd, out int startRev, out int endRev)
        {
            var length = zeroCrossings.Length / 2;
            startFwd = 0;
            endFwd = startFwd + length;
            startRev = endFwd + 1;
            endRev = zeroCrossings.Length - 1;
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Calculates the speed between consecutive time values
        /// </summary>
        /// <param name="ifg"></param>
        /// <param name="time_axis"></param>
        /// <param name="speed"></param>
        public static void BuildSpeedVector(int length, double[] time_axis, out double[] speed)
        {
            var speedVec = new CCOVector(length);

            // Fill speed vector
            for (var i = 0; i < length - 1; i++)
            {
                var diff = time_axis[i + 1] - time_axis[i];

                if (diff != 0.0)
                {
                    speedVec[i + 1] = 1.0 / diff;
                }
                else
                {
                    speedVec[i + 1] = 0.0;
                }
            }

            // Use same value for first 2 speed values
            speedVec[0] = speedVec[1];

            speed = speedVec.GetNativeBuffer();
        }

        private enum eDirection { Unknown, Forward, Reverse }
        private enum EDQPeakType { eMin = -1, eMax = 1 };

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Finds the forward and reverse peaks.
        /// Depends on Configuration:
        /// - PeakSearchWindow
        /// - ZeroFillingFindPeaks
        /// - PeakTargetForwardLeftSide
        /// - PeakTargetReverseLeftSide
        /// </summary>
        /// <param name="startFwd"></param>
        /// <param name="endFwd"></param>
        /// <param name="startRev"></param>
        /// <param name="endRev"></param>
        /// <param name="ifg"></param>
        /// <param name="peakFwd"></param>
        /// <param name="peakRev"></param>
        public static void FindPeaks(int startFwd, int endFwd, int startRev, int endRev, double[] ifg,
            out int peakFwd, out int peakRev)
        {
            peakFwd = FindPeak(ifg, startFwd, endFwd, eDirection.Forward);
            peakRev = FindPeak(ifg, startRev, endRev, eDirection.Reverse);

            peakFwd += startFwd;
            peakRev += startRev;
        }

        private static int FindPeak(double[] ifg, int areaStart, int areaEnd, eDirection direction)
        {
            var peak = 0;

            // Initialize the peak index
            if (direction == eDirection.Forward)
            {
                peak = areaStart + cfg.PeakTargetForwardLeftSide;
            }
            else
            {
                peak = areaEnd + 1 - (cfg.PeakTargetReverseLeftSide - 1);
            }

            // Get the search window
            var searchWindowStart = peak - 1 - (cfg.PeakSearchWindow / 2); // -1 used for compatibility with MATLAB
            var real = new CCOVector(ifg).GetSlice(searchWindowStart, cfg.PeakSearchWindow);

            // Do the zero-filling in the search window sector
            var fft = new CCOFFT();
            var window = fft.ZeroFilling(real, cfg.ZeroFillingFindPeaks);

            // Find the absolute max in the window
            var endWindow = window.Length - 1;
            var maxIndex = 0;
            window.MaxAt(out maxIndex);

            // Step left until local min and the foloowing max is found
            var minLeft = StepToNextPeak(maxIndex, 0, window, EDQPeakType.eMin);
            var maxLeft = StepToNextPeak(minLeft, 0, window, EDQPeakType.eMax);

            // Step right until local min and the following max is found
            var minRight = StepToNextPeak(maxIndex, endWindow, window, EDQPeakType.eMin);
            var maxRight = StepToNextPeak(minRight, endWindow, window, EDQPeakType.eMax);

            // Find the bigger max
            var start = 0;
            var end = 0;

            if (window[maxLeft] > window[maxRight])
            {
                start = maxLeft;
                end = maxIndex;
            }
            else
            {
                start = maxIndex;
                end = maxRight;
            }

            // Find the absolute minimum
            var minIndex = 0;
            var selection = new CCOVector(window.Length);
            selection.FillSelection(start, end - start + 1, 1);
            window.MinAt(out minIndex, selection);

            // Get the two closest samples to the found minimum and chose the smaller one
            var floor = (int)Math.Floor(minIndex * (1.0 / cfg.ZeroFillingFindPeaks));
            var ceiling = (int)Math.Ceiling(minIndex * (1.0 / cfg.ZeroFillingFindPeaks));
            var floorIndex = peak - (cfg.PeakSearchWindow / 2) + floor - 1;
            var ceilingIndex = peak - (cfg.PeakSearchWindow / 2) + ceiling - 1;

            if (ifg[floorIndex] <= ifg[ceilingIndex])
            {
                return floorIndex - areaStart;
            }
            else
            {
                return ceilingIndex - areaStart;
            }
        }

        private static int StepToNextPeak(int start, int end, CCOVector vec, EDQPeakType peakType)
        {
            // Test boundaries
            if (start == end)
            {
                return end;
            }

            var i = start;
            var increment = (end - start) / Math.Abs(end - start); // +1 or -1

            while (i != end)
            {
                var tmp = vec[i];
                i += increment;

                if (peakType == EDQPeakType.eMax && vec[i] < tmp)
                {
                    return i -= increment;
                }

                if (peakType == EDQPeakType.eMin && vec[i] > tmp)
                {
                    return i -= increment;
                }
            }

            return end;
        }

        //////////////////////////////////////////////////////////////////////
        /// Isolating Scans (forward and reverse separately)
        /// 1. Check if scan has enough points with EnoughPoints
        /// 2. Use the first forward/reverse scans as reference scans with CreateReferenceScan
        /// 3. Isolate the scan (do this also for reference scans) with IsolateScan
        /// 4. Check the speed of the isolated scan with IsSpeedOk
        //////////////////////////////////////////////////////////////////////

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Checks whether a scan has enough points for further processing.
        /// Depends on Configuration:
        /// - UsefulLeftPoints
        /// - UsefulPointsPerScan
        /// </summary>
        /// <param name="startScan"></param>
        /// <param name="endScan"></param>
        /// <param name="peakScan"></param>
        /// <param name="reverse"></param>
        /// <returns></returns>
        public static bool EnoughPoints(int startScan, int endScan, int peakScan, bool reverse = false)
        {
            var length = endScan - startScan;
            var peak = reverse ? length - peakScan + startScan : peakScan - startScan;

            var test = peak < (cfg.UsefulLeftPoints - 1) ||
                length - peak - 1 < cfg.UsefulPointsPerScan - (cfg.UsefulLeftPoints - 1) + 1;

            return !test;
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Creates a reference scan for use in IsolateScan method.
        /// Depends on Configuration:
        /// - IsolateScanWindow
        /// </summary>
        /// <param name="interferogram"></param>
        /// <param name="peak"></param>
        /// <param name="referenceScan"></param>
        public static void CreateReferenceScan(double[] interferogram, int peak,
            out double[] referenceScan, bool reverse = false)
        {
            var windowStart = (reverse ? 1 : 0) + peak - (cfg.IsolateScanWindow / 2);
            var winSlice = new CCOVector(interferogram).GetSlice(windowStart, cfg.IsolateScanWindow);
            referenceScan = winSlice.GetNativeBuffer();
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Shifts the scan so that its peak coincides with the given reference scan.
        /// Depends on Configuration:
        /// - IsolateScanWindow
        /// - UsefulLeftPoints
        /// - UsefulPointsPerScan
        /// </summary>
        /// <param name="interferogram"></param>
        /// <param name="referenceScan"></param>
        /// <param name="startScan"></param>
        /// <param name="peakScan"></param>
        /// <param name="shiftedStart"></param>
        /// <param name="shiftedScan"></param>
        /// <param name="reverse"></param>
        /// <returns></returns>
        public static void IsolateScan(double[] interferogram, double[] referenceScan,
            int startScan, int peakScan, out int shiftedStart, out double[] shiftedScan, bool reverse = false)
        {
            var ulp = cfg.UsefulLeftPoints - 1;
            var interferogramSize = cfg.UsefulPointsPerScan;
            var start = startScan;
            var peak = peakScan - startScan;

            var shift = ComputeShift(new CCOVector(interferogram), new CCOVector(referenceScan),
                start + (reverse ? 1 : 0), peak);

            if (!reverse)
            {
                shiftedStart = start + peak + shift - ulp;
            }
            else
            {
                shiftedStart = start + peak + shift - (interferogramSize - ulp) + 1;
            }

            var slice = new CCOVector(interferogram).GetSlice(shiftedStart, interferogramSize);

            if (reverse)
            {
                slice = slice.Reverse();
            }

            shiftedScan = slice.GetNativeBuffer();
        }

        private static int ComputeShift(CCOVector interferogram, CCOVector referenceScan, int areaStart, int peakIndex)
        {
            var smallestDeviation = double.MaxValue;
            var bestIndex = 0;
            CCOVector peakWindow;

            // Compute three norms
            for (var shiftIndex = -1; shiftIndex < 2; shiftIndex++)
            {
                var startRow = areaStart + peakIndex + shiftIndex - cfg.IsolateScanWindow / 2;
                peakWindow = interferogram.GetSlice(startRow, referenceScan.Length);
                var diff = referenceScan - peakWindow;

                // norm vector
                var norm = diff.Sqr().Sum();
                if (norm < smallestDeviation)
                {
                    smallestDeviation = norm;
                    bestIndex = shiftIndex;
                }
            }

            return bestIndex;
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Checks if the speed deviation is inside of given limits.
        /// Depends on Configuration:
        /// - MaxVelocityDeviationPercentage
        /// </summary>
        /// <param name="speed"></param>
        /// <param name="start"></param>
        /// <param name="length"></param>
        /// <returns></returns>
        public static bool IsSpeedOk(double[] speed, int start)
        {
            var averageSpeed = GetAverageSpeed(speed, start, cfg.UsefulPointsPerScan);

            return IsSpeedWithinTolerance(speed, start, cfg.UsefulPointsPerScan, averageSpeed);
        }

        private static double GetAverageSpeed(double[] speed, int start, int length)
        {
            var sum = 0.0;

            for (var i = start; i < start + length; i++)
            {
                sum += speed[i];
            }

            return sum / length;
        }

        private static bool IsSpeedWithinTolerance(double[] speed, int start, int length, double averageSpeed)
        {
            var limit = averageSpeed * cfg.MaxVelocityDeviationPercentage / 100.0;

            for (var i = start; i < start + length; i++)
            {
                if (Math.Abs(speed[i] - averageSpeed) > limit)
                {
                    return false;
                }
            }

            return true;
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Calculate the average of an array of scans.
        /// Does not depend on Configuration.
        /// </summary>
        /// <param name="scans"></param>
        /// <param name="average"></param>
        public static void AverageScans(double[][] scans, out double[] average)
        {
            var sumVec = new CCOVector(scans[0].Length);
            sumVec.Zero();

            for (var i = 0; i < scans.Length; i++)
            {
                sumVec += new CCOVector(scans[i]);
            }

            sumVec.Div(scans.Length);

            average = sumVec.GetNativeBuffer();
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Center the averaged scans - it is possible that the peak has moved by +/- 1
        /// when calculating the average, so move it back to its correct position.
        /// Depends on Configuration:
        /// - UsefulLeftPoints
        /// - ZeroFillingCenterAverage
        /// </summary>
        /// <param name="average"></param>
        /// <param name="centered"></param>
        public static void CenterAveraged(double[] average, out double[] centered)
        {
            var averageVec = new CCOVector(average);
            var length = averageVec.Length;
            var newLength = (int)Math.Pow(2.0, Math.Ceiling(Math.Log((double)length) / Math.Log(2.0)));
            var diffLength = newLength - length;

            // Zerofilling
            var zerosVec = new CCOVector(diffLength / 2);
            var interfArray = new CCOVector[] { zerosVec, averageVec, zerosVec };
            var interfVec = new CCOVector(interfArray);

            var fft = new CCOFFT();
            var zeroFilledVec = fft.ZeroFilling(interfVec, cfg.ZeroFillingCenterAverage);

            // Find max peak around (+1/-1) the peak point
            var start = cfg.ZeroFillingCenterAverage * ((cfg.UsefulLeftPoints - 1) + diffLength / 2 - 1);
            var end = cfg.ZeroFillingCenterAverage * ((cfg.UsefulLeftPoints + 1) + diffLength / 2 - 1);
            var max = 0;

            // Mark selection and get the maximum in selection
            var selectionVec = new CCOVector(zeroFilledVec.Length);
            selectionVec.FillSelection(start, (end - start + 1), 1.0);
            zeroFilledVec.MinAt(out max, selectionVec);

            // Build shifted initerferogram
            var startSel = max - (cfg.UsefulLeftPoints - 1) * cfg.ZeroFillingCenterAverage;
            var endSel = max + (length - cfg.UsefulLeftPoints) * cfg.ZeroFillingCenterAverage;
            var selectBlock = new CCOVector(zeroFilledVec.Length);
            selectBlock.BlockSelect(startSel, endSel - startSel + 1, 1, cfg.ZeroFillingCenterAverage - 1);
            var shiftedVec = zeroFilledVec.ShrinkToSelection(selectBlock);

            centered = shiftedVec.GetNativeBuffer();
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Perform phase correction on an interferogram.
        /// Depends on Configuration:
        /// - PhaseCorrectionWindowSize
        /// - UsefulLeftPoints
        /// </summary>
        /// <param name="interferogram"></param>
        /// <param name="phaseCorrectedInterferogram"></param>
        public static void PerformPhaseCorrection(double[] interferogram, out double[] phaseCorrectedInterferogram)
        {
            var interferogramVec = new CCOVector(interferogram);
            var apodizationType1 = CCOFFT.WeightingFunctions.Blackman;
            var apodizationType2 = CCOFFT.WeightingFunctions.Blackman;
            var ulp = cfg.UsefulLeftPoints - 1;
            var peakIndex = ulp;

            // Use window around peak
            var peakWindowVec = interferogramVec.GetSlice(
                peakIndex - cfg.PhaseCorrectionWindowSize / 2, cfg.PhaseCorrectionWindowSize);

            // Use apodization
            var apodizationVec = new CCOVector(peakWindowVec.Length);
            apodizationVec.FillSelection(0, apodizationVec.Length, 1.0);
            var fft0 = new CCOFFT();
            fft0.Weighting(apodizationVec, apodizationType1);
            var apodPeakWindowVec = peakWindowVec * apodizationVec;

            // Flip - IFFT - Flip
            var apodPeakWindowCxVec = new CCOComplexVector(apodPeakWindowVec);
            var fft1 = new CCOFFT();
            fft1.Init(apodPeakWindowCxVec.Real.Length);
            var flippedCxVec0 = apodPeakWindowCxVec.Flip();
            fft1.Ifft(ref flippedCxVec0);
            var spectraCxVec = flippedCxVec0.Flip();
            var realSpectraVec = spectraCxVec.Abs();

            // Conjugated complex vector
            spectraCxVec.Conj();
            var phaseCnjCxVec = spectraCxVec;

            var zeroLimit = 1E-8 * realSpectraVec.Mean();

            // Divide through amount of spectra or set to zero if the value is small enough
            for (var cnt = 0; cnt < phaseCnjCxVec.Imag.Length; cnt++)
            {
                if (realSpectraVec[cnt] > zeroLimit)
                {
                    phaseCnjCxVec.Real[cnt] /= realSpectraVec[cnt];
                    phaseCnjCxVec.Imag[cnt] /= realSpectraVec[cnt];
                }
                else
                {
                    phaseCnjCxVec.Real[cnt] = 0.0;
                    phaseCnjCxVec.Imag[cnt] = 0.0;
                }
            }

            // Set certain areas to 0.0
            phaseCnjCxVec.Real[0] = 0.0;
            phaseCnjCxVec.Imag[0] = 0.0;

            for (var cnt = cfg.PhaseCorrectionWindowSize / 2 - 1; cnt <= cfg.PhaseCorrectionWindowSize / 2 + 1; cnt++)
            {
                phaseCnjCxVec.Real[cnt] = 0.0;
                phaseCnjCxVec.Imag[cnt] = 0.0;
            }

            // Get phase spectra
            var fftTheta = new CCOFFT();
            fftTheta.Init(phaseCnjCxVec.Real.Length);
            var flippedCxVec1 = phaseCnjCxVec.Flip();
            fftTheta.Fft(flippedCxVec1);
            var thetaCxVec = flippedCxVec1.Flip();

            // Use apodization
            var apodizationVec2 = new CCOVector(peakWindowVec.Length);
            apodizationVec2.FillSelection(0, apodizationVec2.Length, 1.0);
            var fft2 = new CCOFFT();
            fft2.Weighting(apodizationVec2, apodizationType2);
            var apodThetaCxVec = thetaCxVec * apodizationVec2;

            var convInterferogramVec = CCOVector.Conv(interferogramVec, apodThetaCxVec.Real) /
                cfg.PhaseCorrectionWindowSize;

            phaseCorrectedInterferogram = convInterferogramVec.GetSlice(
                cfg.PhaseCorrectionWindowSize / 2, interferogramVec.Length).GetNativeBuffer();
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Computes the raw spectrum for an interferogram (should be phase corrected).
        /// Depends on Configuration:
        /// - UsefulLeftPoints
        /// - InterferogramSize
        /// - ZeroFillingPhaseCorrection
        /// </summary>
        /// <param name="interferogram"></param>
        /// <param name="rawSpectrum"></param>
        public static void ComputeRawSpectrum(double[] interferogram, out double[] rawSpectrum)
        {
            var interferogramVec = new CCOVector(interferogram);
            var apodizationType = CCOFFT.WeightingFunctions.Blackman;
            var ulp = cfg.UsefulLeftPoints - 1;

            // Mirror single sided interferogram
            var peakPosition = ulp;
            var interParts = new CCOVector[]
            {
                interferogramVec.GetSlice(peakPosition, cfg.InterferogramSize),
                interferogramVec.GetSlice(peakPosition + 1, cfg.InterferogramSize).Reverse()
            };
            var mirroredInterferogramVec = new CCOVector(interParts);

            // Compute apodization and apply it to the mirrored interferogram
            var apodizationVec = new CCOVector(mirroredInterferogramVec.Length);
            apodizationVec.FillSelection(0, apodizationVec.Length, 1.0);
            var fft0 = new CCOFFT();
            fft0.Weighting(apodizationVec, apodizationType);
            var apodInterferogramVec = mirroredInterferogramVec * apodizationVec.Flip();

            // Create zero filled vector (next higher squaring)
            var nextPower2 = (int)System.Math.Ceiling(System.Math.Log10(cfg.InterferogramSize) / System.Math.Log10(2));
            var zeros = cfg.ZeroFillingPhaseCorrection * (int)System.Math.Pow(2, nextPower2) - cfg.InterferogramSize;
            var zeroFilledParts = new CCOVector[]
            {
                new CCOVector(zeros),
                apodInterferogramVec.Flip(),
                new CCOVector(zeros)
            };

            var zeroFilledInterferogramVec = new CCOVector(zeroFilledParts);
            zeroFilledInterferogramVec = zeroFilledInterferogramVec.Flip();

            // Fourier transformation
            var fft1 = new CCOFFT();
            fft1.Init(zeroFilledInterferogramVec.Length);
            var spectraCxVec = new CCOComplexVector(zeroFilledInterferogramVec);
            fft1.Fft(spectraCxVec);

            // Use half of the real part (symmetrical)
            var realSpectraVec = spectraCxVec.Real.GetSlice(0, spectraCxVec.Length / 2);
            rawSpectrum = realSpectraVec.GetNativeBuffer();
        }

        //////////////////////////////////////////////////////////////////////
        /// <summary>
        /// Apply the dispersion correction to the raw spectrum.
        /// Depends on Configuration:
        /// - DispersionCorrectionCoefficient1
        /// - DispersionCorrectionCoefficient2
        /// - DispersionCorrectionCoefficient3
        /// - DispersionCorrectionCoefficient4
        /// - DispersionCorrectionCoefficientB1
        /// - DispersionCorrectionCoefficientB2
        /// - DispersionCorrectionCoefficientT0
        /// - WaveNumbers
        /// - WaveNumberStart
        /// - WaveNumberStep
        /// - LaserLambda
        /// </summary>
        /// <param name="rawSpectrum"></param>
        /// <param name="wedgeDriveTemperature"></param>
        /// <param name="spectrum"></param>
        /// <param name="axis"></param>
        public static void DispersionCorrection(
            double[] rawSpectrum,
            double wedgeDriveTemperature,
            out double[] spectrum,
            out double[] axis)
        {
            // u-target-axis u=nu*deltan(nu)
            var utAxis = BuildUtAxis(wedgeDriveTemperature);

            // u-source-axis of spectrum in cm^-1
            var usAxis = BuildUsAxis(rawSpectrum.Length, wedgeDriveTemperature);

            // Spline-interpolate spectrum from old u-axis (usAxis) to new u-axis (utAxis)
            var rawSpectrumVec = new CCOVector(rawSpectrum);
            CCOVector splinedSpectrumVec;
            var ok = rawSpectrumVec.FreeCubicSpline(usAxis, rawSpectrumVec, utAxis, out splinedSpectrumVec);

            spectrum = splinedSpectrumVec.GetNativeBuffer();
            axis = utAxis.GetNativeBuffer();

        }

        private static CCOVector BuildUtAxis(double wedgeDriveTemperature)
        {
            var waveEnd = cfg.WaveNumberStart + cfg.WaveNumberStep * (cfg.WaveNumbers - 1);
            var nuAxis = BuildStepVector(cfg.WaveNumberStart, cfg.WaveNumberStep, waveEnd);

            var utAxis = nuAxis * Birefteo2((nuAxis * 100).Power(-1), wedgeDriveTemperature);

            return utAxis;
        }

        private static CCOVector BuildStepVector(double startValue, double step, double endValue)
        {
            var length = GetStepVectorLength(startValue, step, endValue);
            var vector = new CCOVector(length);

            var value = startValue;
            for (var i = 0; i < length; i++)
            {
                vector[i] = value;
                value += step;
            }

            return vector;
        }

        private static int GetStepVectorLength(double startValue, double step, double endValue)
        {
            return (int)((endValue - startValue + step) / step);
        }

        private static CCOVector Birefteo2(CCOVector vector, double wedgeDriveTemperature)
        {
            var vec = vector * 1.0E+6; // rescale units from m to micrometer
            var dcc1 = cfg.DispersionCorrectionCoefficient1;
            var dcc2 = cfg.DispersionCorrectionCoefficient2;
            var dcc3 = cfg.DispersionCorrectionCoefficient3;
            var dcc4 = cfg.DispersionCorrectionCoefficient4;
            var dccB1 = cfg.DispersionCorrectionCoefficientB1;
            var dccB2 = cfg.DispersionCorrectionCoefficientB2;
            var dccT0 = cfg.DispersionCorrectionCoefficientT0;

            var result =
                vec.Power(-2) * dcc2 + dcc1 + vec.Power(-4) * dcc3 + vec.Power(2) * dcc4 +
                (vec.Power(-2) * dccB2 + dccB1) * (wedgeDriveTemperature - dccT0);

            return result;
        }

        private static CCOVector BuildUsAxis(int spectrumLength, double wedgeDriveTemperature)
        {
            var lambdaVec = new CCOVector(1);
            lambdaVec[0] = cfg.LaserLambda;

            // Sample spacing (as wedge thickness)
            var deltaX = cfg.LaserLambda / (2 * (Birefteo2(lambdaVec, wedgeDriveTemperature))[0]);

            // Spacing on u-axis
            var deltaU = 1 / (2 * deltaX * spectrumLength);
            var umax = deltaU * spectrumLength;

            // u-axis of spectrum in cm^-1
            var axis = BuildStepVector(0, 1, spectrumLength - 1);
            var usAxis = axis * 0.01 * umax / spectrumLength; // !!!! divide by l_iLength not by (l_iLength-1)!!!

            return usAxis;
        }

        /// <summary>
        /// Calculates the average of two vectors.
        /// </summary>
        /// <param name="vec1"></param>
        /// <param name="vec2"></param>
        /// <param name="avg"></param>
        public static void CalculateAverage(double[] vec1, double[] vec2, out double[] avg)
        {
            var vec1Vec = new CCOVector(vec1);
            var vec2Vec = new CCOVector(vec2);
            var avgVec = (vec1Vec + vec2Vec) / 2;
            avg = avgVec.GetNativeBuffer();
        }
    }
}
