using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buchi.DataAcquisition
{
    /// <summary>
    /// The configuration class holds the configuration parameters that are
    /// read from the database in the N-500 source code.
    /// </summary>
    public static class DQSIController
    {
        // How many scan pairs wanted in current measurement
        public static int ScanPairTotal { get; set; } = 1;
        // Indicates if a noise test is run
        public static bool NoiseTest { get; set; } = false;

        // N-500
        // Delay of ADC in seconds
        public static double AdcDelay { get; set; } = 0.00044698;
        // Interferogram: True if center average has to be used (disable this flag only for tests)
        public static bool CenterAverageApplied { get; set; } = true;
        // Delay between laser and interferogram channels in seconds
        public static double ChannelDelay { get; set; } = -0.0000023;
        // PhaseCorrection: Coefficient 1 used in dispersion correction
        public static double DispersionCorrectionCoefficient1 { get; set; } = 0.139242676;
        // PhaseCorrection: Coefficient 2 used in dispersion correction
        public static double DispersionCorrectionCoefficient2 { get; set; } = 0.005021617;
        // PhaseCorrection: Coefficient 3 used in dispersion correction
        public static double DispersionCorrectionCoefficient3 { get; set; } = 0.000323913;
        // PhaseCorrection: Coefficient 4 used in dispersion correction
        public static double DispersionCorrectionCoefficient4 { get; set; } = -0.000528157;
        // PhaseCorrection: Coefficient b1 used in dispersion correction
        public static double DispersionCorrectionCoefficientB1 { get; set; } = 2.76E-07;
        // PhaseCorrection: Coefficient b2 used in dispersion correction
        public static double DispersionCorrectionCoefficientB2 { get; set; } = 3.12E-07;
        // PhaseCorrection: Coefficient t0 used in dispersion correction
        public static double DispersionCorrectionCoefficientT0 { get; set; } = 36;
        // Running a full scan
        public static bool FullScan { get; set; } = true;
        // Interferogram: Resolution of full scan (only for documentation)
        public static int FullScanResolution { get; set; } = 8;
        // Interferogram: Resolution of half scan (only for documentation)
        public static int HalfScanResolution { get; set; } = 16;
        // Interferogram: Size of interferogram in full scan
        public static int InterferogramSizeFullScan { get; set; } = 2532;
        // Interferogram: Size of interferogram in half scan
        public static int InterferogramSizeHalfScan { get; set; } = 1300;
        // Interferogram: Start 'invalid scan percentage check' after reaching this limit
        public static int InvalidScanStartCheck { get; set; } = 5;
        // Interferogram: Use this search interval (+/-) around the peak to shift scans according to the reference scan
        public static int IsolateScanWindow { get; set; } = 64;
        // PhaseCorrection: HeNe-laser wavelength
        public static double LaserLambda { get; set; } = 6.33E-07;
        // ScanQualityCheck: Testvalue for a scan to be accepted (deltaNoise/deltaSignal)max>MaxAllowedRelativeError
        public static double MaxAllowedRelativeError { get; set; } = 0.1;
        // Max size in bytes of a data package read from the control board
        public static int MaxDataSize { get; set; } = 409600;
        // Interferogram: [%] Maximal allowed percentage of invalid scans in one measurement
        public static int MaxInvalidScanPercentage { get; set; } = 20;
        // Interferogram: Maximal allowed (+/-) point deviation from 1. Scan
        public static int MaxPeakDeviation { get; set; } = 256;
        // ScanQualityCheck: [%] Maximal allowed percentage of scan quality failures in one measurement
        public static int MaxScanQualityFailurePercentage { get; set; } = 80;
        // Interferogram: [%] Maximal allowed deviation of velocity of wedge drive in percentage
        public static int MaxVelocityDeviationPercentage { get; set; } = 20;
        // ScanQualityCheck: Min. Signal amplitude for the check to be performed (otherwise the scan is always ok)
        public static double MinDeltaSignal { get; set; } = 100.0;
        // Minimal required peak to peak amplitude in the laser signal
        public static int MinLaserPPAmplitude { get; set; } = 150;
        // Interferogram: Use this search interval (+/-) around the target peak to find the measured peak (power of 2)
        public static int PeakSearchWindow { get; set; } = 512;
        // Interferogram: Target value of peak in a forward scan (in FindPeak), measured from the left, small side
        public static int PeakTargetForwardLeftSide { get; set; } = 800;
        // Interferogram: Target value of peak in a reverse scan (in FindPeak), measured from the left, small side
        public static int PeakTargetReverseLeftSide { get; set; } = 800;
        // PhaseCorrection:Used window size in phase correction
        public static int PhaseCorrectionWindowSize { get; set; } = 512;
        // Interferogram: 1 = regular sample, 0 = tablets (used in DispersionCorrection)
        public static bool RegularSample { get; set; } = true;
        // ScanQualityCheck: 1 (true) = scan quality check enabled; 0 (false) = disabled
        public static bool RobustnessOn { get; set; } = false;
        // Used sampling frequency in Hz
        public static uint SamplingFrequency { get; set; } = 86805;
        // PhaseCorrection: This flag tells if the transfilter flag is used (1 = on, 0 = off)
        public static bool TransfilterOn { get; set; } = false;
        // PhaseCorrection: Parameter ndiv is used in the regular transfilter
        public static double TransfilterParam_ndiv_Regular2 { get; set; } = 9.5;
        // PhaseCorrection: Parameter ndiv is used in the transfilter for tablets
        public static double TransfilterParam_ndiv_Tablets2 { get; set; } = 6.5;
        // PhaseCorrection: Parameter s is used in the regular transfilter
        public static double TransfilterParam_s_Regular2 { get; set; } = 8;
        // PhaseCorrection:Parameter s is used in the transfilter for tablets
        public static double TransfilterParam_s_Tablets2 { get; set; } = 9;
        // Number of useful points on the left side (forward scan) of the peak
        public static int UsefulLeftPoints { get; set; } = 351;
        // Number of useful points on the right side (forward scan) of the peak
        // for a full scan
        public static int UsefulPointsFullScan { get; set; } = 3400;
        // Number of useful points on the right side (forward scan) of the peak
        // for a half scan
        public static int UsefulPointsHalfScan { get; set; } = 1700;
        // PhaseCorrection: Number of points in spectra
        public static int WaveNumbers { get; set; } = 1501;
        // PhaseCorrection: Starting wave number (used in DispersionCorrection)
        public static double WaveNumberStart { get; set; } = 4000;
        // PhaseCorrection:Steps of wave number  (used in DispersionCorrection)
        public static double WaveNumberStep { get; set; } = 4;
        // Interferogram: Number of applied zero filling in Center Average
        public static int ZeroFillingCenterAverage { get; set; } = 8;
        // Interferogram: Number of applied zero filling in Find Peaks
        public static int ZeroFillingFindPeaks { get; set; } = 4;
        // PhaseCorrection: Number of applied zero filling in Phase Correction
        public static int ZeroFillingPhaseCorrection { get; set; } = 8;

        // Computed properties
        // Initial data shift of a scan in seconds. Depends
        // on ADC delay and sampling frequency
        public static int DataShift => (int)Math.Round(AdcDelay * SamplingFrequency);
        // The time for a given sample index
        public static double GetTimeFromSample(double sample) => sample / SamplingFrequency;
        // The interferogram size depends on doing a full or half scan
        public static int InterferogramSize = FullScan ? InterferogramSizeFullScan : InterferogramSizeHalfScan;
        // Maximum allowed scan quality errors
        public static int MaxAllowedScanQualityFailures = (int)(ScanPairTotal + 100.0 / (100.0 - MaxScanQualityFailurePercentage)) - ScanPairTotal;
        // The minimal size of a raw scan
        public static int MinRawScanSize => 4 * (FullScan ? UsefulPointsFullScan : UsefulPointsHalfScan);
        // The resolution of the scan depends on full or half sca
        public static int ScanResolution => FullScan ? FullScanResolution : HalfScanResolution;
        // The transfilter parameters, depending on beeing a regular measurement cell
        public static double TransfilterParam_ndiv => RegularSample ? TransfilterParam_ndiv_Regular2 : TransfilterParam_ndiv_Tablets2;
        public static double TransfilterParam_s => RegularSample ? TransfilterParam_s_Regular2 : TransfilterParam_s_Tablets2;
        // Number of useful points in a scan
        public static int UsefulPointsPerScan => FullScan ? UsefulPointsFullScan : UsefulPointsHalfScan;

        // DSP Filters
        // Laser filter
        public static double[] LaserFilter { get; set; }
        // Detector filter
        public static double[] DetectorFilter { get; set; }
        // Detector filter LP2
        public static double[] DetectorFilterLp2 { get; set; }
    }
}
