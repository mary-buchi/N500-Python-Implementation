#pragma once

#include <math.h>

struct Configuration
{
	// Delay of ADC in seconds
	const double adc_delay = 0.00044698;

	// Delay between laser and interferogram channels in seconds
	const double channel_delay = -0.0000023;

	// Interferogram: Factor used for formatting the float values received from the control board
	const double format_factor = 256.0;

	// PhaseCorrection: Coefficient 1 used in dispersion correction
	const double dispersion_correction_coefficient_1 = 0.139242676;

	// PhaseCorrection: Coefficient 2 used in dispersion correction
	const double dispersion_correction_coefficient_2 = 0.005021617;

	// PhaseCorrection: Coefficient 3 used in dispersion correction
	const double dispersion_correction_coefficient_3 = 0.000323913;

	// PhaseCorrection: Coefficient 4 used in dispersion correction
	const double dispersion_correction_coefficient_4 = -0.000528157;

	// PhaseCorrection: Coefficient b1 used in dispersion correction
	const double dispersion_correction_coefficient_b1 = 2.76E-07;

	// PhaseCorrection: Coefficient b2 used in dispersion correction
	const double dispersion_correction_coefficient_b2 = 3.12E-07;

	// PhaseCorrection: Coefficient t0 used in dispersion correction
	const double dispersion_correction_coefficient_t0 = 36.0;

	// Running a full scan, as opposed to half scan
	bool full_scan = true;

	// Interferogram: Resolution of full scan (only for documentation)
	const unsigned int full_scan_resolution = 8;

	// Interferogram: Resolution of half scan (only for documentation)
	const unsigned int half_scan_resolution = 16;

	// Apodization function applied on interferogram
	const unsigned int interferogram_apodization = 6; //Code for Blackman in N-500 software

	// Interferogram: Size of interferogram in full scan
	const unsigned int interferogram_size_full_scan = 2532;

	// Interferogram: Size of interferogram in half scan
	const unsigned int interferogram_size_half_scan = 1300;

	// Interferogram: Start 'invalid scan percentage check' after reaching this limit
	const unsigned int invalid_scan_start_check = 5;

	// Interferogram: Search interval (+/-) around the peak to shift scans according to the	reference scan
	const unsigned int isolate_scan_window = 64;

	// PhaseCorrection: HeNe-laser wavelength
	const double laser_lambda = 6.33E-07;

	// ScanQualityCheck: Testvalue for a scan to be accepted (deltaNoise/deltaSignal)max>MaxAllowedRelativeError
	const double max_allowed_relative_error = 0.1;

	// Max size in bytes of a data package read from the control board
	const unsigned int max_data_size = 409600;

	// Interferogram: [%] Maximal allowed percentage of invalid scans in one measurement
	const unsigned int max_invalid_scans_percentage = 20;

	// Interferogram: Maximal allowed (+/-) point deviation of peak from first Scan
	const unsigned int max_peak_deviation = 256;

	// Interferogram: [%] Maximal allowed deviation of wedged drive velocity in percentage
	const unsigned int max_velocity_deviation_percentage = 20;

	// ScanQualityCheck: Min. Signal amplitude for the check to be performed (otherwise the scan is always ok)
	const double min_delta_signal = 100.0;

	// Minimal required peak to peak amplitude in the laser signal
	const unsigned int min_laser_pp_amplitude = 150;

	// Interferogram: Used search interval (+/-) around the target peak to find the measured peak(power of 2)
	const unsigned int peak_search_window = 512;

	// Interferogram: Target value of peak in a forward scan (in FindPeak), measured from the left, small side
	const unsigned int peak_target_forward_left_side = 800;

	// Interferogram: Target value of peak in a reverse scan (in FindPeak), measured from the left, small side
	const unsigned int peak_target_reverse_left_side = 800;

	// Phase Correction:
	// 0: No Window
	// 1 : Hamming(Happ - Genzel)
	// 2 : Hanning(cosine)
	// 3 : Blackman - Harris
	// 4 : Blackman - Harris 4 Term
	// 5 : Bartlet(triangle)
	// 6 : Blackman
	// 7 : Blackman Exact
	// 8 : Forman
	const unsigned int phase_correction_apodization_1 = 6;

	// PhaseCorrection: Used window size in phase correction
	const unsigned int phase_correction_window_size = 512;

	// Phase Correction, as phase_correction_appodization_1
	const unsigned int phase_correction_apodization_2 = 6;

	// Interferogram: 1 = regular sample, 0 = tablets (used in DispersionCorrection)
	const bool regular_sample{ true };

	// ScanQualityCheck: 1 (true) = scan quality check enabled; 0 (false) = disabled
	const bool robustness_on{ false };

	// Used sampling frequency in Hz
	const unsigned int sampling_frequency = 86805;

	// PhaseCorrection: Parameter ndiv is used in the regular transfilter
	const double transfilter_param_ndiv_regular2{ 9.5 };

	// PhaseCorrection: Parameter ndiv is used in the transfilter for tablets
	const double transfilter_param_ndiv_tablets2{ 6.6 };

	// PhaseCorrection: Parameter s is used in the regular transfilter
	const double transfilter_param_s_regular2{ 8 };

	// PhaseCorrection: Parameter s is used in the transfilter for tablets
	const double transfilter_param_s_tablets2{ 9 };

	// Number of useful points on the lef side (forward scan) of the peak
	const unsigned int useful_left_points = 351;

	// Number of useful points on the right side (forward scan) of the peak	for a full scan
	const unsigned int useful_points_full_scan = 3400;

	// Number of useful points on the right side (forward scan) of the peak for a half scan
	const unsigned int useful_points_half_scan = 1700;

	// PhaseCorrection: number of points in spectra
	const unsigned int wave_numbers = 1501;

	// PhaseCorrection:Starting wave number (used in DispersionCorrection)
	const double wave_number_start = 4000;

	// PhaseCorrection:Steps of wave number  (used in DispersionCorrection)
	const double wave_number_step = 4;

	// Interferogram: Number of applied zero filling in Center Average
	const unsigned int zero_filling_center_average = 8;

	// interferogram: Number of applied zero filling in Find Peaks
	const unsigned int zero_filling_find_peaks = 4;

	// PhaseCorrection: Number of applied zero filling in Phase Correction
	const unsigned int zero_filling_phase_correction = 8;


	// Computed properties

	unsigned int data_shift() const
	{
		// Initial data shift of a scan in seconds. Depends on
		// ADC delay and sampling frequency.
		return (int)round(adc_delay * sampling_frequency);
	}

	double get_time_from_sample(double sample) const
	{
		// The time for a given sample index
		return sample / sampling_frequency;
	}

	unsigned int interferogram_size() const
	{
		return full_scan ? interferogram_size_full_scan : interferogram_size_half_scan;
	}

	unsigned int min_raw_data_size() const
	{
		// The minimal size of a scan (half or full scan)
		return 4 * (full_scan ?  useful_points_full_scan : useful_points_half_scan);
	}

	double transfilter_param_ndiv() const
	{
		// The transfilter parameter ndiv, depending on beeing a regular measurement cell or not
		return regular_sample ? transfilter_param_ndiv_regular2 : transfilter_param_ndiv_tablets2;
	}

	double transfilter_param_s() const
	{
		// The transfilter parameter s, depending on beeing a regular measurement cell or not
		return regular_sample ? transfilter_param_s_regular2 : transfilter_param_s_tablets2;
	}

	unsigned int useful_points_per_scan() const
	{
		// Number of useful points in one scan
		return full_scan ? useful_points_full_scan : useful_points_half_scan;
	}
};