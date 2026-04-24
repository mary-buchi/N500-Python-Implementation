#pragma once

#include <complex>
#include <iterator>
#include <vector>

#include "Configuration.h"

enum class ScanDirection {
	unknown,
	forward,
	reverse
};

enum class PeakType {
	min,
	max
};

class DSP
{
	const long double pi = 3.141592653589793238462643383279502884L;

public:
	Configuration configuration;

	DSP() {}

	int sign(double x)
	{
		return x > 0 ? 1 : x < 0 ? -1 : 0;
	}

	/// <summary>
	/// Apply apodization on start and end of data with a given border length.
	/// This is used for apodization of the laser signal.
	/// </summary>
	/// <param name="len">Input: The length of the border area which is apodized</param>
	/// <param name="dat_in">Input: The data to apodize</param>
	/// <param name="dat_out">Output: The apodized data</param>
	void apply_apodization(size_t len, const std::vector<double>& data_in, std::vector<double>& data_out);

	/// <summary>
	/// Apply a FIR filter to data.
	/// Apply apodization to laser signal before applying the FIR filter to it.
	/// </summary>
	/// <param name="data_in">Input: The data to apply the fir filter to</param>
	/// <param name="fir_ilter">Input: The fir filter to be applied</param>
	/// <param name="data_out">Output: The filtered data</param>
	void apply_fir_filter(const std::vector<double>& data_in, const std::vector<double>& fir_filter, std::vector<double>& data_out);

	/// <summary>
	/// Check whether the data has a minimal peak to peak amplitude.
	/// Call this before calling detect_zero_crossings.
	/// Depends on Configuration:
	/// - min_laser_pp_amplitude
	/// </summary>
	/// <param name="data">Input: The data to be checked</param>
	/// <returns>Returns true if the peak to peak amplitude check succeeded</returns>
	bool check_peak_to_peak_amplitude(const std::vector<double>& data);
	
	/// <summary>
	/// Detect the zero crossings of data.
	/// Verify that the peak to peak amplitude of the data is good enough
	/// before calling this function.
	/// Does not depend on Configuration.
	/// </summary>
	/// <param name="data">Input: The data for detecting the zero crossings</param>
	/// <param name="zero_crossings">Output: The data containing the zero crossings of the input data</param>
	void detect_zero_crossings(const std::vector<double>& data, std::vector<double>& zero_crossings);
	
	/// <summary>
	/// Interpolate the detector data on the laser signal zero crossings.
	/// For interpolating the detector values at the zero-crossings of the laser signal,
	/// the time axis is calculated and the interpolated signal and the time axis
	/// are returned as output parameters.
	/// Depends on Configuration:
	/// - sampling_frequency
	/// - channel_delay
	/// </summary>
	/// <param name="zero_crossings">Input: The zero crossings of the laser signal</param>
	/// <param name="detectorData">Input: The fir filtered detector data</param>
	/// <param name="time_axis">Output: The time axis of the interpolated detector values</param>
	/// <param name="data_interpolated">Output: The interpolated detector values</param>
	void interpolate_interferogram(const std::vector<double>& zero_crossings, const std::vector<double>& data, std::vector<double>& time_axis, std::vector<double>& data_interpolated);

	/// <summary>
	/// Calculates the speed between consecutive time values
	/// </summary>
	/// <param name="len">Input: The length of the interpolated dectector data</param>
	/// <param name="time_axis">Input: The time axis</param>
	/// <param name="speed_vector">Output: The speed vector</param>
	void build_speed_vector(size_t len, const std::vector<double>& time_axis, std::vector<double>& speed_vector);
	
	/// <summary>
	/// Returns the start and end indices of the forward and reverse scans.
	/// Does not depend on Configuration.
	/// </summary>
	/// <param name="zero_crossings">Input: The zero crossings of the laser signal</param>
	/// <param name="start_forward">Output: Start index of the forward scan</param>
	/// <param name="end_forward">Output: End index of the forward scan</param>
	/// <param name="start_reverse">Output: Start index of the reverse scan</param>
	/// <param name="end_reverse">Output: End index of the reverse scan</param>
	void find_scan_windows(const std::vector<double>& zero_crossings, size_t& start_forward, size_t& end_forward, size_t& start_reverse, size_t& end_reverse)
	{
		auto len = zero_crossings.size() / 2;
		start_forward = 0;
		end_forward = start_forward + len;
		start_reverse = end_forward + 1;
		end_reverse = zero_crossings.size() - 1;
	}
	
	/// <summary>
	/// Finds the forward and reverse peaks.
	/// Depends on Configuration:
	/// - peak_search_window
	/// - zero_filling_find_peaks
	/// - peak_target_forward_left_side
	/// - peak_target_reverse_left_side
	/// </summary>
	/// <param name="data">Input: Interpolated detector data</param>
	/// <param name="start_forward">Input: Start index of the forward scan</param>
	/// <param name="end_forward">Input: End index of the forward scan</param>
	/// <param name="start_reverse">Input: Start index of the reverse scan</param>
	/// <param name="end_reverse">Input: End index of the reverse scan</param>
	/// <param name="peak_forward">Output: Index of the forward peak</param>
	/// <param name="peak_reverse">Output: Index of the reverse peak</param>
	void find_peaks(const std::vector<double>& data, size_t start_forward, size_t end_forward, size_t start_reverse, size_t end_reverse, size_t& peak_forward, size_t& peak_reverse)
	{
		peak_forward = find_peak(data, start_forward, end_forward, ScanDirection::forward);
		peak_reverse = find_peak(data, start_reverse, end_reverse, ScanDirection::reverse);

		peak_forward += start_forward;
		peak_reverse += start_reverse;
	}
	
	/// <summary>
	/// Checks whether a forward scan has enough points for further processing.
	/// Depends on Configuration:
	/// - useful_left_points
	/// - useful_points_per_scan
	/// </summary>
	/// <param name="start">Input: Start index of forward scan</param>
	/// <param name="end">Input: End index of forward scan</param>
	/// <param name="peak">Input: Index of peak of forward scan</param>
	/// <returns>Returns true if the forward scan contains enough points</returns>
	bool enough_points_forward(size_t start, size_t end, size_t peak)
	{
		return enough_points(start, end, peak, ScanDirection::forward);
	}

	/// <summary>
	/// Checks whether a reverse scan has enough points for further processing.
	/// Depends on Configuration:
	/// - useful_left_points
	/// - useful_points_per_scan
	/// </summary>
	/// <param name="start">Input: Start index of reverse scan</param>
	/// <param name="end">Input: End index of reverse scan</param>
	/// <param name="peak">Input: Index of peak of reverse scan</param>
	/// <returns>Returns true if the reverse scan contains enough points</returns>
	bool enough_points_reverse(size_t start, size_t end, size_t peak)
	{
		return enough_points(start, end, peak, ScanDirection::reverse);
	}
	
	/// <summary>
	/// Creates a forward reference scan for use in isolate_scan method.
	/// Depends on Configuration:
	/// - isolate_scan_window
	/// </summary>
	/// <param name="interferogram">Input: The forward interferogram to be taken as reference</param>
	/// <param name="scan_window_start">Input: Index of start of forward scan window</param>
	/// <param name="peak_idx">Input: Index of forward peak</param>
	/// <param name="data_out">Output: Forward reference scan</param>
	void create_reference_scan_forward(const std::vector<double>& interferogram, size_t scan_window_start, size_t peak_idx, std::vector<double>& data_out)
	{
		create_reference_scan(interferogram, scan_window_start, peak_idx, data_out, ScanDirection::forward);
	}

	/// <summary>
	/// Creates a reverse reference scan for use in isolate_scan method.
	/// Depends on Configuration:
	/// - isolate_scan_window
	/// </summary>
	/// <param name="interferogram">Input: The reverse interferogram to be taken as reference</param>
	/// <param name="scan_window_start">Input: Index of start of reverse scan window</param>
	/// <param name="peak_idx">Input: Index of reverse peak</param>
	/// <param name="data_out">Output: Reverse reference scan</param>
	void create_reference_scan_reverse(const std::vector<double>& interferogram, size_t scan_window_start, size_t peak_idx, std::vector<double>& data_out)
	{
		create_reference_scan(interferogram, scan_window_start, peak_idx, data_out, ScanDirection::reverse);
	}
	
	/// <summary>
	/// Computes shift of start index of a forward interferogram so that its peak coincides with the peak of the forward reference scan.
	/// Depends on Configuration:
	/// - isolate_scan_window
	/// - useful_left_points
	/// - useful_points_per_scan
	/// </summary>
	/// <param name="interferogram">Input: The forward interferogram</param>
	/// <param name="reference_scan">Inputs: The forward reference scan</param>
	/// <param name="start_scan">Input: Start index of forward scan window</param>
	/// <param name="peakScan">Input: Index of peak of forward scan</param>
	/// <returns>Returns the amount of shift needed</returns>
	size_t compute_shift_forward(const std::vector<double>& interferogram, const std::vector<double>& reference_scan, size_t start_scan, size_t peak_scan)
	{
		return compute_shift(interferogram, reference_scan, start_scan, peak_scan, ScanDirection::forward);
	}
	
	/// <summary>
	/// Computes shift of start index of a reverse interferogram so that its peak coincides with the peak of the forward reference scan.
	/// Depends on Configuration:
	/// - isolate_scan_window
	/// - useful_left_points
	/// - useful_points_per_scan
	/// </summary>
	/// <param name="interferogram">Input: The reverse interferogram</param>
	/// <param name="reference_scan">Inputs: The reverse reference scan</param>
	/// <param name="start_scan">Input: Start index of reverse scan window</param>
	/// <param name="peakScan">Input: Index of peak of reverse scan</param>
	/// <returns>Returns the amount of shift needed</returns>
	size_t compute_shift_reverse(const std::vector<double>& interferogram, const std::vector<double>& reference_scan, size_t start_scan, size_t peak_scan)
	{
		return compute_shift(interferogram, reference_scan, start_scan, peak_scan, ScanDirection::reverse);
	}
	
	/// <summary>
	/// Checks if the speed deviation is inside of given limits.
	/// Depends on Configuration:
	/// - max_velocity_deviation_percentage
	/// </summary>
	/// <param name="start_idx">Input: Start index for velocity deviation check</param>
	/// <param name="speed_vector">Input: The speed vector to check for velocity deviation</param>
	/// <returns>Returns true if the velocity deviation is within given limits</returns>
	bool speed_is_ok(size_t start_idx, const std::vector<double>& speed_vector);

	/// <summary>
	/// Shifts the forward scan so that its peak coincides with the given forward reference scan.
	/// Compute shift of start index with compute_shift and check if the velocity is within limits
	/// before calling this function.
	/// Depends on Configuration:
	/// - useful_points_per_scan
	/// </summary>
	/// <param name="interferogram">Input: The forward interferogram</param>
	/// <param name="shifted_start">Input: Shift of the start index of the forward scan window</param>
	/// <param name="data_out">Output: The isolated forward scan</param>
	void calculate_isolate_forward(const std::vector<double>& interferogram, size_t shifted_start, std::vector<double>& data_out)
	{
		calculate_isolate(interferogram, shifted_start, data_out);
	}
	
	/// <summary>
	/// Shifts the reverse scan so that its peak coincides with the given reverse reference scan.
	/// Compute shift of start index with compute_shift and check if the velocity is within limits
	/// before calling this function.
	/// Depends on Configuration:
	/// - useful_points_per_scan
	/// </summary>
	/// <param name="interferogram">Input: The reverse interferogram</param>
	/// <param name="shifted_start">Input: Shift of the start index of the reverse scan window</param>
	/// <param name="data_out">Output: The isolated reverse scan</param>
	void calculate_isolate_reverse(const std::vector<double>& interferogram, size_t shifted_start, std::vector<double>& data_out)
	{
		calculate_isolate(interferogram, shifted_start, data_out);
		std::reverse(data_out.begin(), data_out.end());
	}

	/// <summary>
	/// Calculate the average of a list of scans.
	/// Does not depend on Configuration.
	/// </summary>
	/// <param name="scans_vector">Input: The list of scans to average</param>
	/// <param name="data_out">Ouput: The average of the scans</param>
	void calculate_averaged_scans(const std::vector<std::vector<double>>& scans_vector, std::vector<double>& data_out);

	/// <summary>
	/// Center the averaged scans - it is possible that the peak has moved by +/- 1
	/// when calculating the average, so move it back to its correct position.
	/// Call this after calculate_averaged_scans.
	/// Depends on Configuration:
	/// - useful_left_points
	/// - zero_filling_center_average
	/// </summary>
	/// <param name="interferogram">Input: The interferogram to be centered</param>
	/// <param name="data_out">Output: The centered interferogram</param>
	void calculate_centered_averaged_scans(const std::vector<double>& interferogram, std::vector<double>& data_out);

	/// <summary>
	/// Calculate the phase correction of an interferogram.
	/// Call this after calculate_centered_averaged_scans.
	/// Depends on Configuration:
	/// - phase_correction_window_size
	/// - useful_left_points
	/// </summary>
	/// <param name="interferogram">Input: Centered interferogram</param>
	/// <param name="data_out">Output: Phase corrected interferogram</param>
	void calculate_phase_correction(const std::vector<double>& interferogram, std::vector<double>& data_out);

	/// <summary>
	/// Calculates the raw spectrum for an interferogram (should be phase corrected).
	/// Call this after calculate_phase_correction.
	/// Depends on Configuration:
	/// - useful_left_points
	/// - interferogram_size
	/// - zero_filling_phase_correction
	/// </summary>
	/// <param name="interferogram">Input: The phase corrected interferogram</param>
	/// <param name="spectrum">Output: The raw spectrum</param>
	void calculate_raw_spectrum(const std::vector<double>& interferogram, std::vector<double>& spectrum);

	/// <summary>
	/// Calculate the dispersion correction of the raw spectrum.
	/// Call this after calculate_raw_spectrum
	/// Depends on Configuration:
	/// - dispersion_correction_coefficient_1
	/// - dispersion_correction_coefficient_2
	/// - dispersion_correction_coefficient_3
	/// - dispersion_correction_coefficient_4
	/// - dispersion_correction_coefficient_b1
	/// - dispersion_correction_coefficient_b2
	/// - dispersion_correction_coefficient_t0
	/// - wave_numbers
	/// - wave_number_start
	/// - wave_number_step
	/// - laser_lambda
	/// </summary>
	/// <param name="raw_spectrum">Input: The raw spectrum to be corrected</param>
	/// <param name="temperature">Input: The temperature of the wedge drive</param>
	/// <param name="spectrum">Output: The corrected spectrum</param>
	/// <param name="axis">Output: The x-axis of the corrected spectrum</param>
	void calculate_dispersion_corrected_spectrum(const std::vector<double>& raw_spectrum, double temperature, std::vector<double>& spectrum, std::vector<double>& axis);
	
	/// <summary>
	/// Calculate the average of two spectra.
	/// </summary>
	/// <param name="spectrum1">Input: Spectrum 1</param>
	/// <param name="spectrum2">Input: Spectrum 2</param>
	/// <param name="average_spectrum">Output: Average spectrum</param>
	void calculate_average_spectrum(const std::vector<double>& spectrum1, const std::vector<double>& spectrum2, std::vector<double>& average_spectrum);

private:
	double calculate_threshold(const std::vector<double>::const_iterator first, const std::vector<double>::const_iterator last);
	double sine_interpolation(double y1, double y2, double y3);
	size_t find_peak(const std::vector<double>& data, size_t area_start, size_t area_end, ScanDirection scan_direction);
	bool enough_points(size_t start, size_t end, size_t peak, ScanDirection scan_direction);
	void create_reference_scan(const std::vector<double>& interferogram, size_t scan_window_start, size_t peak_idx, std::vector<double>& data_out, ScanDirection scan_direction);
	size_t compute_shift(const std::vector<double>& interferogram, const std::vector<double>& reference_scan, size_t start_scan, size_t peak_scan, ScanDirection scan_direction);
	size_t compute_shift(const std::vector<double>& interferogram, const std::vector<double>& reference_scan, size_t area_start, size_t peak_idx);
	void calculate_isolate(const std::vector<double>& interferogram, size_t shifted_start, std::vector<double>& data_out)
	{
		size_t length = configuration.useful_points_per_scan();
		std::copy(interferogram.begin() + shifted_start, interferogram.begin() + shifted_start + length, std::back_inserter(data_out));
	}
	void zero_filling(const std::vector<double>& pwin, size_t nzf, std::vector<double>& yy);
	void zero_filling(const std::vector<double>& vec, size_t len, size_t zeros_cnt, std::vector<double>& zero_filled);
	void apply_blackman_weighting(std::vector<double>& vec);
	void mirror_interferogram(const std::vector<double>& interferogram, size_t pos, size_t len, std::vector<double>& mirrored);
	void build_ut_axis(double temperature, std::vector<double>& axis);
	void build_us_axis(size_t len, double temperature, std::vector<double>& axis);
	void build_step_vector(double start, double step, double end, std::vector<double>& vec);
	size_t get_step_vector_length(double start, double step, double end);
	void bire_fteo2(const std::vector<double>& vec, double temperature, std::vector<double>& corrected_vec);
	size_t step_to_next_peak(size_t start, size_t end, std::vector<double> v, PeakType peak_type);
};

