#include <algorithm>
#include <cmath>
#include <iterator>
#include <memory>
#include <numeric>
#include <stdexcept>

#include "Configuration.h"
#include "DSP.h"
#include "FFT.h"
#include "Vector.h"

//////////////////////////////////////////////////////////////////////////
void DSP::apply_apodization(size_t len, const std::vector<double>& data_in, std::vector<double>& data_out)
{
	// Apply an apodization of length len to the input data and write it to the output data
	const size_t border_length = (len + 1) / 2;
	const size_t middle_length = data_in.size() - 2 * border_length;

	std::vector<double> border(border_length);
	std::vector<double> apodization(data_in.size());

	// Weight the border, going smoothly from to 0 to 1
	double T = (double)(border_length);
	for (size_t i = 0; i < border_length; i++) {
		double scale = 0.5 * (1.0 - cos(pi * (i + 1.0) / T));
		border[i] = scale;
	}

	for (size_t i = 0; i < border_length; i++) {
		apodization[i] = border[i];
	}

	for (size_t i = 0; i < middle_length; i++) {
		apodization[border_length + i] = 1.0;
	}

	for (size_t i = 0; i < border_length; i++) {
		apodization[border_length + middle_length + i] = border[border_length - 1 - i];
	}

	for (size_t i = 0; i < data_in.size(); i++) {
		data_out.push_back(data_in[i] * apodization[i]);
	}
}

//////////////////////////////////////////////////////////////////////////
void DSP::apply_fir_filter(const std::vector<double>& data_in, const std::vector<double>& fir_filter, std::vector<double>& data_out)
{
	Vector::convolution(data_in, fir_filter, data_out);
}

//////////////////////////////////////////////////////////////////////////
// private
double DSP::calculate_threshold(const std::vector<double>::const_iterator first, const std::vector<double>::const_iterator last)
{
	const auto minmax = std::minmax_element(first, last);
	auto diff = *minmax.second - *minmax.first;
	auto threshold = (0.5 * diff) / 3;

	return threshold;
}

//////////////////////////////////////////////////////////////////////////
bool DSP::check_peak_to_peak_amplitude(const std::vector<double>& data)
{
	// Check if the peak to peak difference is OK
	auto threshold = calculate_threshold(std::begin(data), std::end(data));

	if (threshold < configuration.min_laser_pp_amplitude) {
		return false;
	}

	return true;
}

//////////////////////////////////////////////////////////////////////////
void DSP::detect_zero_crossings(const std::vector<double>& data, std::vector<double>& zero_crossings)
{
	// The peak to peak difference must have been checked before calling this code

	auto threshold = calculate_threshold(std::begin(data), std::end(data));
	size_t sample_count = 0;
	double xis = 0.0;
	bool zero_crossings_found = false;

	// Using 3 data points for zero crossing determination
	while (sample_count < data.size() - 3) {
		zero_crossings_found = false;

		// Ignore noise values which are below the threshold
		while (abs(data[sample_count]) < threshold && sample_count < data.size() - 3) {
			sample_count++;
		}

		// Calculate next zero crossing
		while (!zero_crossings_found && sample_count < data.size() - 3) {
			// Find 2 points around 0.0, one positive and the other negative
			if ((data[sample_count + 1] > 0 && data[sample_count + 2] <= 0) ||
				(data[sample_count + 1] < 0 && data[sample_count + 2] >= 0)) {

				// Set triple index to the first of the next three points
				auto triple_idx = sample_count;

				// Take the two points around 0 and find the closest point
				// to 0. Increment the triple index if necessary to get
				// afterwards the 3 points which are closest to 0. So, the
				// window is reduced from 4 points (2 positive, 2 negative)
				// to the closest 3 points where the second point is the
				// closest one to 0.
				if (data[sample_count] > 0) {
					// negative slope
					if (data[sample_count + 1] + data[sample_count + 2] > 0) {
						// Third point is closer to 0 then the second
						triple_idx++;
					}
				}
				else {
					// positive slope
					if (data[sample_count + 1] + data[sample_count + 2] < 0) {
						// Third point is closer to 0 then the second
						triple_idx++;
					}
				}

				// Use the 3 found points and do sine interpolation to
				// aproximate the zero crossing
				auto y1 = data[triple_idx];
				auto y2 = data[triple_idx + 1];
				auto y3 = data[triple_idx + 2];

				xis = sine_interpolation(y1, y2, y3);

				zero_crossings.push_back(xis + triple_idx + 1);
				zero_crossings_found = true;
			}
			sample_count++;
		}
	}

	// Resize the zero crossings vector. Do not use the last zero crossing. 
	// It might be too close to the end of the data.
	zero_crossings.pop_back();
}

//////////////////////////////////////////////////////////////////////////
double DSP::sine_interpolation(double y1, double y2, double y3)
{
	auto szc = sign(y3);
	double xis = 0.0;

	if (y2 != 0) {
		auto ck = (y3 + y1) / (2 * y2);

		if (-1 < ck && ck < 1) {
			auto kx = std::acos(ck);
			auto a = (y3 + y1) / 2;
			auto b = (y3 - y1) / 2;
			auto phi = std::atan(sqrt(abs(y2 * y2 - (a * a)) / (b * b)));
			xis = phi / kx;

			if (szc * sign(y2) == 1) {
				xis = -xis;
			}
		}
		else {
			xis = -2 * y2 / (y3 - y1);
		}
	}
	else {
		xis = 0.0;
	}

	if (isnan(xis)) {
		xis = 0.0;
	}
	
	return xis;
}

//////////////////////////////////////////////////////////////////////////
void DSP::interpolate_interferogram(const std::vector<double>& zero_crossings, const std::vector<double>& data, std::vector<double>& time_axis, std::vector<double>& data_interpolated)
{
	std::vector<double> x_in;
	std::vector<double> x_out;

	const double sampling_frequency = configuration.sampling_frequency;
	const double channel_delay = configuration.channel_delay;
	const double time_step = 1 / sampling_frequency;

	for (size_t i = 0; i < data.size(); i++) {
		x_in.push_back(time_step * i);
	}

	for (size_t i = 0; i < zero_crossings.size(); i++) {
		x_out.push_back(zero_crossings[i] / sampling_frequency + channel_delay);
	}

	Vector::free_cubic_spline_interpolation(x_in, data, x_out, data_interpolated);

	// Put time information into x-axis of interpolated interferogram
	for (auto& zc : zero_crossings) {
		time_axis.push_back(zc / sampling_frequency);
	}
}

//////////////////////////////////////////////////////////////////////////
void DSP::build_speed_vector(size_t len, const std::vector<double>& time_axis, std::vector<double>& speed_vector)
{
	for (size_t i = 0; i < len - 1; i++) {
		auto diff = time_axis[i + 1] - time_axis[i];
		double speed = 0.0;

		if (diff != 0.0) {
			speed = 1.0 / diff;
		}

		// At the start push the same speed twice
		if (i == 0) {
			speed_vector.push_back(speed);
			speed_vector.push_back(speed);
		}
		else {
			speed_vector.push_back(speed);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
size_t DSP::find_peak(const std::vector<double>& ifg, size_t area_start, size_t area_end, ScanDirection scan_direction)
{
	size_t peak{ 0 };

	if (scan_direction == ScanDirection::forward) {
		peak = area_start + configuration.peak_target_forward_left_side;
	}
	else {
		peak = area_end + 1 - (configuration.peak_target_reverse_left_side - 1);
	}

	// Get the search window
	// -1 used for compatibility with MATLAB in origianl N-500 software
	size_t search_window_start = peak - 1 - configuration.peak_search_window / 2;
	std::vector<double> real;
	Vector::slice(ifg, search_window_start, configuration.peak_search_window, real);

	// Do the zero-filling in the search window sector
	std::vector<double> window;
	zero_filling(real, configuration.zero_filling_find_peaks, window);

	// Find the absolute maximum in the window
	//////////////////////////////////////////

	auto end_window = window.size() - 1;
	size_t max_index = 0;
	Vector::max_at(window, max_index);

	// Step left until local min and the foloowing max is found
	auto min_left = step_to_next_peak(max_index, 0, window, PeakType::min);
	auto max_left = step_to_next_peak(min_left, 0, window, PeakType::max);

	// Step right until local min and the following max is found
	auto min_right = step_to_next_peak(max_index, end_window, window, PeakType::min);
	auto max_right = step_to_next_peak(min_right, end_window, window, PeakType::max);

	// Find the bigger maximum
	size_t start = 0;
	size_t end = 0;

	if (window[max_left] > window[max_right]) {
		start = max_left;
		end = max_index;
	}
	else {
		start = max_index;
		end = max_right;
	}

	// Find the absolute minimum
	std::vector<double> selection(window.size(), 0.0);
	for (size_t i = start; i < end + 1; i++) {
		selection[i] = 1.0;
	}

	size_t min_index = 0;
	Vector::min_at(window, selection, min_index);

	// Get the two closest samples to the found minimum and chose the smaller one
	auto floor = std::floor(min_index * (1.0 / configuration.zero_filling_find_peaks));
	auto ceiling = std::ceil(min_index * (1.0 / configuration.zero_filling_find_peaks));
	auto floor_index = peak - (configuration.peak_search_window / 2) + floor - 1;
	auto ceiling_index = peak - (configuration.peak_search_window / 2) + ceiling - 1;

	if (ifg[floor_index] <= ifg[ceiling_index]) {
		return floor_index - area_start;
	}
	else {
		return ceiling_index - area_start;
	}
}

//////////////////////////////////////////////////////////////////////////
bool DSP::enough_points(size_t start, size_t end, size_t peak, ScanDirection scan_direction)
{
	auto len = end - start;
	auto peak_relative = scan_direction == ScanDirection::forward ? peak - start : len - peak + start;

	auto test = peak_relative < (configuration.useful_left_points - 1) ||
		len - peak_relative - 1 < configuration.useful_points_per_scan() - (configuration.useful_left_points - 1) + 1;

	return !test;
}

//////////////////////////////////////////////////////////////////////////
void DSP::create_reference_scan(const std::vector<double>& interferogram, size_t scan_window_start, size_t peak_idx, std::vector<double>& data_out, ScanDirection scan_direction)
{
	size_t start = scan_window_start;
	size_t peak = peak_idx - start;
	size_t window_start = start + peak - (configuration.isolate_scan_window / 2);
	if (scan_direction == ScanDirection::reverse) window_start++;
	size_t window_end = window_start + configuration.isolate_scan_window;
	std::copy(interferogram.begin() + window_start, interferogram.begin() + window_end, std::back_inserter(data_out));
}

//////////////////////////////////////////////////////////////////////////
size_t DSP::compute_shift(const std::vector<double>& interferogram, const std::vector<double>& reference_scan, size_t start_scan, size_t peak_scan, ScanDirection scan_direction)
{
	size_t useful_left_points = configuration.useful_left_points - 1;
	size_t interferogram_size = configuration.useful_points_per_scan();
	size_t start = start_scan;
	size_t start_correction = ScanDirection::forward == scan_direction ? 0 : 1;
	size_t peak = peak_scan - start_scan;

	size_t shift = compute_shift(interferogram, reference_scan, start + start_correction, peak);
	size_t shifted_start = start;

	if (ScanDirection::forward == scan_direction) {
		shifted_start += peak + shift - useful_left_points;
	}
	else {
		shifted_start += peak + shift - (interferogram_size - useful_left_points) + 1;
	}

	return shifted_start;
}

//////////////////////////////////////////////////////////////////////////
size_t DSP::compute_shift(const std::vector<double>& interferogram, const std::vector<double>& reference_scan, size_t area_start, size_t peak_idx)
{
	double smallest_deviation = std::numeric_limits<double>::max();
	size_t best_index = 0;

	// Compute 3 norms
	for (auto shift_idx = -1; shift_idx < 2; shift_idx++) {
		size_t start_idx = area_start + peak_idx + shift_idx - configuration.isolate_scan_window / 2;

		std::vector<double> peak_window;
		std::copy(interferogram.begin() + start_idx, interferogram.begin() + start_idx + reference_scan.size(), std::back_inserter(peak_window));

		std::vector<double> diff;
		for (size_t idx = 0; idx < reference_scan.size(); idx++) {
			diff.push_back(reference_scan[idx] - peak_window[idx]);
		}

		// Norm
		double norm = 0.0;
		for (auto& d : diff) {
			norm += d * d;
		}

		// Take the norm with the smallest deviation
		if (norm < smallest_deviation) {
			smallest_deviation = norm;
			best_index = shift_idx;
		}

		peak_window.clear();
		diff.clear();
	}

	return best_index;
}

//////////////////////////////////////////////////////////////////////////
bool DSP::speed_is_ok(size_t start_idx, const std::vector<double>& speed_vector)
{
	size_t length = configuration.useful_points_per_scan();
	double average_speed = Vector::mean(speed_vector, start_idx, length);
	double limit = average_speed * configuration.max_velocity_deviation_percentage / 100.0;
	bool ok = true;

	for (size_t idx = start_idx; idx < start_idx + length && ok; idx++) {
		if (abs(speed_vector[idx] - average_speed) > limit) {
			ok = false;
		}
	}

	return ok;
}

//////////////////////////////////////////////////////////////////////////
void DSP::calculate_averaged_scans(const std::vector<std::vector<double>>& scans_vector, std::vector<double>& data_out)
{
	auto size = scans_vector[0].size();

	// Initialize output data with 0
	for (auto idx = 0; idx < size; idx++) {
		data_out.push_back(0.0);
	}

	// Calculate the sum for every index
	for (auto& scan : scans_vector) {
		for (auto idx = 0; idx < size; idx++) {
			data_out[idx] += scan[idx];
		}
	}

	auto length = scans_vector.size();

	// Calculate the average for every index
	for (auto idx = 0; idx < size; idx++) {
		data_out[idx] /= length;
	}
}

//////////////////////////////////////////////////////////////////////////
void DSP::calculate_centered_averaged_scans(const std::vector<double>& interferogram, std::vector<double>& data_out)
{
	auto useful_left_points = configuration.useful_left_points;
	auto zfc = configuration.zero_filling_center_average;

	auto length = interferogram.size();
	auto new_length = (size_t)(std::pow(2.0, std::ceil(std::log(length) / std::log(2))));
	auto diff_length = new_length - length;

	// zero filling
	std::vector<double> ifg;
	for (auto i = 0; i < diff_length / 2; i++) {
		ifg.push_back(0.0);
	}
	for (auto& v : interferogram) {
		ifg.push_back(v);
	}
	for (auto i = 0; i < diff_length / 2; i++) {
		ifg.push_back(0.0);
	}

	std::vector<double> zero_filled;
	zero_filling(ifg, zfc, zero_filled);

	// Find minimum around +/-1 of the peak point
	auto start = zfc * ((useful_left_points - 1) + diff_length / 2 - 1);
	auto end = zfc * ((useful_left_points + 1) + diff_length / 2 - 1);

	// Find the last absolute minimum between start and end in the
	// interferogram window.
	size_t min_idx = 0;
	std::vector<double> selection(zero_filled.size(), 0.0);
	Vector::selection(selection, start, (end - start + 1), 1.0);
	Vector::min_at(zero_filled, selection, min_idx);

	// Build shifted interferogram
	auto start_sel = min_idx - (useful_left_points - 1) * zfc;
	auto end_sel = min_idx + (length - useful_left_points) * zfc;

	auto sel_len = end_sel - start_sel + 1;
	size_t shifted_len = 1 + sel_len / 8;

	for (auto i = 0; i < shifted_len; i++) {
		// take every zero filling length element
		data_out.push_back(zero_filled[start_sel + i * zfc]);
	}
}

//////////////////////////////////////////////////////////////////////////
void DSP::zero_filling(const std::vector<double>& pwin, size_t nzf, std::vector<double>& yy)
{
	// zerofilling in the search window for smoothing
	// translated the matlab code
	// mentioned in the comment of the N - 500 code:
	//
	// Matlab code :
	// lzi = (nzf - 1) * pwinsize;
	// yy = nzf * real(ifft(fftshift([zeros(lzi / 2);
	//                                fftshift(fft(pwin));
	//                                zeros(lzi / 2)])));
	//
	// nzf = number of zeros used for filling
	// pwin = the search window containing the peaks
	// yy = the output zerofilled vector

	if (nzf <= 1) {
		std::copy(pwin.begin(), pwin.end(), std::back_inserter(yy));
		return;
	}

	auto pwin_size = pwin.size();
	
	std::vector<std::complex<double>> pwin_complex;
	Vector::complex(pwin, pwin_complex);

	FFT fft;
	fft.init(pwin_size);
	fft.fft(pwin_complex);
	Vector::fftshift_complex(pwin_complex);

	// add zeros to left and right side of window and do zerofilling
	auto lzi = (nzf - 1) * pwin_size;

	std::vector<std::complex<double>> zz;
	for (auto i = 0; i < lzi / 2; i++) {
		zz.push_back(0.0);
	}
	for (auto& c : pwin_complex) {
		zz.push_back(c);
	}
	for (auto i = 0; i < lzi / 2; i++) {
		zz.push_back(0.0);
	}

	fft.init(zz.size());
	Vector::fftshift_complex(zz);
	fft.ifft(zz);

	// Take only the real part of the complex numbers for the result
	for (auto& c : zz) {
		yy.push_back(nzf * c.real());
	}
}

//////////////////////////////////////////////////////////////////////////
void DSP::calculate_phase_correction(const std::vector<double>& interferogram, std::vector<double>& data_out)
{
	// Phase correction using 'Forman' algorithm

	// Parameters
	auto correction_window_size = configuration.phase_correction_window_size;
	auto apodization_type_1 = configuration.phase_correction_apodization_1;
	auto apodization_type_2 = configuration.phase_correction_apodization_2;
	auto userful_left_points = configuration.useful_left_points - 1;

	// Support only Blackman apodization
	if (apodization_type_1 != 6)
		throw std::runtime_error(std::string("unexpected apodization type. apodization type must be blackman."));
	if (apodization_type_2 != 6)
		throw std::runtime_error(std::string("unexpected apodization type. apodization type must be blackman."));

	auto peak_idx = userful_left_points;

	// Use window around peak
	auto window_start = peak_idx - correction_window_size / 2;
	std::vector<double> peak_window;
	Vector::slice(interferogram, window_start, correction_window_size, peak_window);

	// Use blackman apodization
	std::vector<double> apodization_vec(peak_window.size(), 1.0);
	apply_blackman_weighting(apodization_vec);
	std::vector<double> apod_peak_window;
	for (size_t i = 0; i < peak_window.size(); i++) {
		apod_peak_window.push_back(apodization_vec[i] * peak_window[i]);
	}

	// fftshift -> ifft -> fftshift
	FFT fft;
	std::vector<std::complex<double>> apod_peak_window_complex;
	Vector::complex(apod_peak_window, apod_peak_window_complex);
	fft.init(apod_peak_window_complex.size());
	Vector::fftshift_complex(apod_peak_window_complex);
	fft.ifft(apod_peak_window_complex);
	Vector::fftshift_complex(apod_peak_window_complex);

	std::vector<double> real_spectra;
	Vector::abs(apod_peak_window_complex, real_spectra);
	std::vector<std::complex<double>> phase_conj;
	Vector::conj(apod_peak_window_complex, phase_conj);
	auto zero_limit = 1E-8 * Vector::mean(real_spectra);

	// divide by value of spectra or set to zero if the value is too small
	for (size_t i = 0; i < phase_conj.size(); i++) {
		phase_conj[i] = real_spectra[i] > zero_limit ? phase_conj[i] / real_spectra[i] : 0.0;
	}

	// set certain areas to 0.0
	phase_conj[0] = 0.0;
	for (auto i = configuration.phase_correction_window_size / 2 - 1; i <= configuration.phase_correction_window_size / 2 + 1; i++) {
		phase_conj[i] = 0.0;
	}

	// get phase spectra
	fft.init(phase_conj.size());
	Vector::fftshift_complex(phase_conj);
	fft.fft(phase_conj);
	Vector::fftshift_complex(phase_conj);
	
	std::vector<std::complex<double>> apod_theta; 
	
	for (auto i = 0; i < apodization_vec.size(); i++) {
		apod_theta.push_back(phase_conj[i] * apodization_vec[i]);
	}
	std::vector<double> apod_theta_re;
	Vector::real(apod_theta, apod_theta_re);

	std::vector<double> interferogram_conv;
	Vector::convolution(interferogram, apod_theta_re, interferogram_conv);
	Vector::scale(interferogram_conv, 1.0 / configuration.phase_correction_window_size);
	Vector::slice(interferogram_conv, configuration.phase_correction_window_size / 2, interferogram.size(), data_out);
}

//////////////////////////////////////////////////////////////////////////
void DSP::apply_blackman_weighting(std::vector<double>& vec)
{
	auto LEN = vec.size();
	auto T = (double)LEN;

	for (auto i = 0; i < LEN; i++) {
		auto t = (double)(i)-0.5 * T;
		auto scale = 0.42 + 0.5 * cos((double)pi * t / (T / 2)) + 0.08 * cos(2.0 * (double)pi * t / (T / 2));
		vec[i] *= scale;
	}
}

//////////////////////////////////////////////////////////////////////////
void DSP::calculate_raw_spectrum(const std::vector<double>& interferogram, std::vector<double>& spectrum)
{
	auto useful_left_points = configuration.useful_left_points - 1;
	auto interferogram_size = configuration.interferogram_size();
	auto zeros_cnt = configuration.zero_filling_phase_correction;

	// Mirror single sided interferogram
	auto peak_position = useful_left_points;
	std::vector<double> mirrored_interferogram;
	mirror_interferogram(interferogram, peak_position, interferogram_size, mirrored_interferogram);

	// Apodization vector
	std::vector<double> apodization_vec(mirrored_interferogram.size(), 1.0);
	apply_blackman_weighting(apodization_vec);
	Vector::fftshift(apodization_vec.data(), apodization_vec.size());

	// Apply apodization vector to mirrored interferogram
	std::vector<double> apod_interferogram;
	for (auto i = 0; i < mirrored_interferogram.size(); i++) {
		apod_interferogram.push_back(mirrored_interferogram[i] * apodization_vec[i]);
	}
	Vector::fftshift(apod_interferogram.data(), apod_interferogram.size());

	// Create zero-filled vector (next higher squaring)
	std::vector<double> zero_filled_interferogram;
	zero_filling(apod_interferogram, interferogram_size, zeros_cnt, zero_filled_interferogram);
	Vector::fftshift(zero_filled_interferogram.data(), zero_filled_interferogram.size());

	// Fourier transformation of zero filled interferogram
	FFT fft;
	std::vector<std::complex<double>> zero_filled_interferogram_complex;
	Vector::complex(zero_filled_interferogram, zero_filled_interferogram_complex);
	fft.init(zero_filled_interferogram_complex.size());
	fft.fft(zero_filled_interferogram_complex);

	// Use half of the real part (symmetrical)
	std::vector<double> re;
	Vector::real(zero_filled_interferogram_complex, re);
	Vector::slice(re, 0, re.size() / 2, spectrum);
}

//////////////////////////////////////////////////////////////////////////
void DSP::mirror_interferogram(const std::vector<double>& interferogram, size_t pos, size_t len, std::vector<double>& mirrored)
{
	std::vector<double> part_1, part_2;
	Vector::slice(interferogram, pos, len, part_1);
	Vector::slice(interferogram, pos + 1, len, part_2);
	std::reverse(part_2.begin(), part_2.end());
	std::copy(part_1.begin(), part_1.end(), std::back_inserter(mirrored));
	std::copy(part_2.begin(), part_2.end(), std::back_inserter(mirrored));
}

//////////////////////////////////////////////////////////////////////////
void DSP::zero_filling(const std::vector<double>& vec, size_t len, size_t zeros_cnt, std::vector<double>& zero_filled)
{
	auto next_power_of_2 = (int)ceil(log10(len) / log10(2));
	auto zeros = zeros_cnt * (int)pow(2, next_power_of_2) - len;
	std::vector<double> zeros_vec(zeros, 0.0);
	std::copy(zeros_vec.begin(), zeros_vec.end(), std::back_inserter(zero_filled));
	std::copy(vec.begin(), vec.end(), std::back_inserter(zero_filled));
	std::copy(zeros_vec.begin(), zeros_vec.end(), std::back_inserter(zero_filled));
}

//////////////////////////////////////////////////////////////////////////
void DSP::calculate_dispersion_corrected_spectrum(const std::vector<double>& raw_spectrum, double temperature, std::vector<double>& spectrum, std::vector<double>& axis)
{
	// u-target-axis u=nu*deltan(nu)
	std::vector<double> ut_axis;
	build_ut_axis(temperature, ut_axis);

	// u-source-axis of spectrum in cm^-1
	std::vector<double> us_axis;
	build_us_axis(raw_spectrum.size(), temperature, us_axis);

	// Spline-interpolate spectrum from old u-axis (us_axis) to new u-axis (ut_axis)
	Vector::free_cubic_spline_interpolation(us_axis, raw_spectrum, ut_axis, spectrum);

	// The target axis is the axis of the resulting spectrum
	std::copy(ut_axis.begin(), ut_axis.end(), std::back_inserter(axis));
}

//////////////////////////////////////////////////////////////////////////
void DSP::build_ut_axis(double temperature, std::vector<double>& axis)
{
	auto wave_end = configuration.wave_number_start + configuration.wave_number_step * (configuration.wave_numbers - 1);
	std::vector<double> nu_axis;
	build_step_vector(configuration.wave_number_start, configuration.wave_number_step, wave_end, nu_axis);

	std::vector<double> t0;
	for (auto d : nu_axis) {
		t0.push_back(pow(d * 100.0, -1));
	}
	std::vector<double> t1;
	bire_fteo2(t0, temperature, t1);

	Vector::mult(nu_axis, t1, axis);
}

//////////////////////////////////////////////////////////////////////////
void DSP::build_step_vector(double start, double step, double end, std::vector<double>& vec)
{
	auto length = get_step_vector_length(start, step, end);
	auto value = start;

	for (size_t i = 0; i < length; i++) {
		vec.push_back(value);
		value += step;
	}
}

//////////////////////////////////////////////////////////////////////////
size_t DSP::get_step_vector_length(double start, double step, double end)
{
	return (size_t)((end - start + step) / step);
}

//////////////////////////////////////////////////////////////////////////
void DSP::build_us_axis(size_t len, double temperature, std::vector<double>& axis)
{
	std::vector<double> lambda_vec(1, configuration.laser_lambda);

	// Sample spacing (as wedge thickness)
	std::vector<double> corrected_lambda;
	bire_fteo2(lambda_vec, temperature, corrected_lambda);
	auto delta_x = configuration.laser_lambda / (2 * corrected_lambda[0]);

	// Spacing on u-axis
	auto delta_u = 1 / (2 * delta_x * len);
	auto umax = delta_u * len;

	// u-axis of spectrum in cm^-1
	std::vector<double> u_axis;
	build_step_vector(0, 1, (double)(len - 1), u_axis);

	Vector::scale(u_axis, 0.01 * umax / len); // !!! divide by len not by (len - 1) !!!

	std::copy(u_axis.begin(), u_axis.end(), std::back_inserter(axis));
}

//////////////////////////////////////////////////////////////////////////
void DSP::bire_fteo2(const std::vector<double>& vec, double temperature, std::vector<double>& corrected_vec)
{
	// Rescale units from meter to micrometer
	std::vector<double> mvec;
	for (auto d : vec) mvec.push_back(d * 1.0E+6);

	auto dcc1 = configuration.dispersion_correction_coefficient_1;
	auto dcc2 = configuration.dispersion_correction_coefficient_2;
	auto dcc3 = configuration.dispersion_correction_coefficient_3;
	auto dcc4 = configuration.dispersion_correction_coefficient_4;
	auto dcc_b1 = configuration.dispersion_correction_coefficient_b1;
	auto dcc_b2 = configuration.dispersion_correction_coefficient_b2;
	auto dcc_t0 = configuration.dispersion_correction_coefficient_t0;

	for (auto v : mvec) {
		auto x = pow(v, -2) * dcc2 + dcc1 + pow(v, -4) * dcc3 + pow(v, 2) * dcc4 +
			(pow(v, -2) * dcc_b2 + dcc_b1) * (temperature - dcc_t0);
		corrected_vec.push_back(x);
	}
}

//////////////////////////////////////////////////////////////////////////
void DSP::calculate_average_spectrum(const std::vector<double>& spectrum1, const std::vector<double>& spectrum2, std::vector<double>& average_spectrum)
{
	for (size_t i = 0; i < spectrum1.size(); i++) {
		if (i >= spectrum2.size()) break;
		average_spectrum.push_back((spectrum1[i] + spectrum2[i]) / 2);
	}
}

//////////////////////////////////////////////////////////////////////////
size_t DSP::step_to_next_peak(size_t start, size_t end, std::vector<double> v, PeakType peak_type)
{
	if (start == end) {
		return end;
	}

	auto i = start;
	auto increment = end < start ? -1 : +1;

	while (i != end) {
		auto tmp = v[i];
		i += increment;

		if (peak_type == PeakType::max && v[i] < tmp) {
			return i - increment;
		}

		if (peak_type == PeakType::min && v[i] > tmp) {
			return i - increment;
		}
	}

	return end;
}
