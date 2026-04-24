#include "pch.h"
#include "Configuration.h"
#include "DSP.h"

#include <fstream>
#include <vector>


class ConfigurationFixtureBase : public testing::Test {
protected:
	Configuration cfg; // = Configuration{};
};

class ConfigurationFixture : public ConfigurationFixtureBase {
protected:
	void SetUp() override {
		ConfigurationFixtureBase::SetUp();
	}

	void TearDown() override{
		ConfigurationFixtureBase::TearDown();
	}
};

TEST_F(ConfigurationFixture, DataShiftIsComputedCorrectly) {
	EXPECT_EQ(cfg.data_shift(), round(cfg.adc_delay * cfg.sampling_frequency));
}

TEST_F(ConfigurationFixture, TimeFromSampleIsComputedCorrectly) {
	EXPECT_DOUBLE_EQ(cfg.get_time_from_sample(42.42), 42.42 / cfg.sampling_frequency);
}

TEST_F(ConfigurationFixture, InterferogramSizeForFullScanIsCorrect) {
	cfg.full_scan = true;
	EXPECT_EQ(cfg.interferogram_size(), cfg.interferogram_size_full_scan);
}

TEST_F(ConfigurationFixture, InterferogramSizeForHalfScanIsCorrect) {
	cfg.full_scan = false;
	EXPECT_EQ(cfg.interferogram_size(), cfg.interferogram_size_half_scan);
}

TEST_F(ConfigurationFixture, MinRawDataSizeForFullScanIsCorrect) {
	cfg.full_scan = true;
	EXPECT_EQ(cfg.min_raw_data_size(), 4 * cfg.useful_points_full_scan);
}

TEST_F(ConfigurationFixture, MinRawDataSizeForHalfScanIsCorrect) {
	cfg.full_scan = false;
	EXPECT_EQ(cfg.min_raw_data_size(), 4 * cfg.useful_points_half_scan);
}

class DSPFixtureBase : public testing::Test {
protected:
	const double max_deviation = 1E-10;
	const double wedge_drive_temperature = 30.0;
	DSP* dsp;
	const std::string n500_path = R"(C:\Users\mary\Documents\Sputnik_DSP_CPP\N-500\)";
	std::ifstream ifs_laser_fir_filter{ n500_path + "N-500_FilterLaser.txt" };
	std::ifstream ifs_laser_data{ n500_path + "laser_0.txt" };
	std::ifstream ifs_laser_apod{ n500_path + "laser_apodization_0.txt" };
	std::ifstream ifs_laser_fir_filtered{ n500_path + "laser_filtered_0.txt" };
	std::ifstream ifs_laser_zero_crossings{ n500_path + "laser_zero_crossings_0.txt" };

	std::ifstream ifs_detector_fir_filter{ n500_path + "N-500_FilterDetector.txt" };
	std::ifstream ifs_detector_data{ n500_path + "detector_0.txt" };
	std::ifstream ifs_detector_fir_filtered{ n500_path + "detector_filtered_0.txt" };
	std::ifstream ifs_detector_interpolated{ n500_path + "detector_interpolated_0.txt" };
	
	std::ifstream ifs_time_axis{ n500_path + "time_axis_0.txt" };
	std::ifstream ifs_speed_vector{ n500_path + "speed_vector_0.txt" };
	std::ifstream ifs_scan_windows{ n500_path + "scan_windows_0.txt" };
	std::ifstream ifs_peaks{ n500_path + "peaks_0.txt" };
	std::ifstream ifs_enough_points{ n500_path + "enough_points_0.txt" };

	std::ifstream ifs_reference_scan_forward{ n500_path + "reference_scan_forward.txt" };
	std::ifstream ifs_reference_scan_reverse{ n500_path + "reference_scan_reverse.txt" };
	std::ifstream ifs_shifted_start{ n500_path + "shifted_start_0.txt" };
	std::ifstream ifs_speed_ok{ n500_path + "speed_ok_0.txt" };
	std::ifstream ifs_shifted_scan_forward{ n500_path + "shifted_scan_forward_0.txt" };
	std::ifstream ifs_shifted_scan_reverse{ n500_path + "shifted_scan_reverse_0.txt" };

	std::ifstream ifs_shifted_scan_0_forward{ n500_path + "shifted_scan_forward_0.txt" };
	std::ifstream ifs_shifted_scan_1_forward{ n500_path + "shifted_scan_forward_1.txt" };
	std::ifstream ifs_shifted_scan_2_forward{ n500_path + "shifted_scan_forward_2.txt" };
	std::ifstream ifs_shifted_scan_3_forward{ n500_path + "shifted_scan_forward_3.txt" };
	std::ifstream ifs_shifted_scan_0_reverse{ n500_path + "shifted_scan_reverse_0.txt" };
	std::ifstream ifs_shifted_scan_1_reverse{ n500_path + "shifted_scan_reverse_1.txt" };
	std::ifstream ifs_shifted_scan_2_reverse{ n500_path + "shifted_scan_reverse_2.txt" };
	std::ifstream ifs_shifted_scan_3_reverse{ n500_path + "shifted_scan_reverse_3.txt" };

	std::ifstream ifs_average_scan_forward{ n500_path + "average_scan_forward.txt" };
	std::ifstream ifs_average_scan_reverse{ n500_path + "average_scan_reverse.txt" };
	std::ifstream ifs_centered_average_scan_forward{ n500_path + "centered_average_scan_forward.txt" };
	std::ifstream ifs_centered_average_scan_reverse{ n500_path + "centered_average_scan_reverse.txt" };

	std::ifstream ifs_phase_corrected_scan_forward{ n500_path + "phase_corrected_scan_forward.txt" };
	std::ifstream ifs_phase_corrected_scan_reverse{ n500_path + "phase_corrected_scan_reverse.txt" };
	std::ifstream ifs_raw_spectrum_forward{ n500_path + "raw_spectrum_forward.txt" };
	std::ifstream ifs_raw_spectrum_reverse{ n500_path + "raw_spectrum_reverse.txt" };
	std::ifstream ifs_dispersion_corrected_spectrum_forward{ n500_path + "dispersion_corrected_spectrum_forward.txt" };
	std::ifstream ifs_axis_dispersion_corrected_spectrum_forward{ n500_path + "axis_dispersion_corrected_spectrum_forward.txt" };
	std::ifstream ifs_dispersion_corrected_spectrum_reverse{ n500_path + "dispersion_corrected_spectrum_reverse.txt" };
	std::ifstream ifs_axis_dispersion_corrected_spectrum_reverse{ n500_path + "axis_dispersion_corrected_spectrum_reverse.txt" };
	std::ifstream ifs_dispersion_corrected_spectrum_average{ n500_path + "dispersion_corrected_spectrum_average.txt" };

	std::vector<double> read_doubles(std::ifstream& ifs) {
		return read_values<double>(ifs);
	}

	std::vector<int> read_ints(std::ifstream& ifs) {
		return read_values<int>(ifs);
	}

	std::vector<bool> read_bools(std::ifstream& ifs) {
		return read_values<bool>(ifs);
	}

	template <typename T> 
	std::vector<T> read_values(std::ifstream& ifs) {
		std::vector<T> res;
		for (T x; ifs >> x;) {
			res.push_back(x);
		}
		return res;
	}
};

class DSPFixture : public DSPFixtureBase {
protected:
	void SetUp() override {
		DSPFixtureBase::SetUp();
		dsp = new DSP();
	}

	void TearDown() override {
		dsp = nullptr;
		ifs_laser_fir_filter.close();
		ifs_laser_data.close();
		ifs_laser_apod.close();
		ifs_laser_fir_filtered.close();
		ifs_laser_zero_crossings.close();

		ifs_detector_fir_filter.close();
		ifs_detector_data.close();
		ifs_detector_fir_filtered.close();
		ifs_detector_interpolated.close();

		ifs_time_axis.close();
		ifs_speed_vector.close();
		ifs_scan_windows.close();
		ifs_peaks.close();
		ifs_enough_points.close();
		ifs_reference_scan_forward.close();
		ifs_reference_scan_reverse.close();
		ifs_shifted_start.close();
		ifs_speed_ok.close();
		ifs_shifted_scan_forward.close();
		ifs_shifted_scan_reverse.close();

		ifs_shifted_scan_0_forward.close();
		ifs_shifted_scan_1_forward.close();
		ifs_shifted_scan_2_forward.close();
		ifs_shifted_scan_3_forward.close();

		ifs_shifted_scan_0_reverse.close();
		ifs_shifted_scan_1_reverse.close();
		ifs_shifted_scan_2_reverse.close();
		ifs_shifted_scan_3_reverse.close();

		ifs_average_scan_forward.close();
		ifs_average_scan_reverse.close();
		ifs_centered_average_scan_forward.close();
		ifs_centered_average_scan_reverse.close();

		ifs_phase_corrected_scan_forward.close();
		ifs_phase_corrected_scan_reverse.close();
		ifs_raw_spectrum_forward.close();
		ifs_raw_spectrum_reverse.close();
		ifs_dispersion_corrected_spectrum_average.close();
		ifs_axis_dispersion_corrected_spectrum_forward.close();
		ifs_dispersion_corrected_spectrum_reverse.close();
		ifs_axis_dispersion_corrected_spectrum_reverse.close();
		ifs_dispersion_corrected_spectrum_average.close();

		DSPFixtureBase::TearDown();
	}
};

TEST_F(DSPFixture, SignOfPositiveDoubleIsOne) {
	EXPECT_EQ(dsp->sign(0.2), 1);
}

TEST_F(DSPFixture, SignOfNegativDoubleIsMinusOne) {
	EXPECT_EQ(dsp->sign(-0.2), -1);
}

TEST_F(DSPFixture, SignOfZeroIsZero) {
	EXPECT_EQ(dsp->sign(0.0), 0);
}

TEST_F(DSPFixture, LaserApodization) {
	std::vector<double> laser_fir_filter;
	std::vector<double> laser_data;
	std::vector<double> laser_apod;
	std::vector<double> result;

	laser_fir_filter = read_doubles(ifs_laser_fir_filter);
	laser_data = read_doubles(ifs_laser_data);
	laser_apod = read_doubles(ifs_laser_apod);

	dsp->apply_apodization(laser_fir_filter.size(), laser_data, result);

	ASSERT_EQ(laser_apod.size(), result.size());

	for (size_t i = 0; i < laser_apod.size(); i++) {
		EXPECT_DOUBLE_EQ(laser_apod[i], result[i]);
	}

	laser_fir_filter.clear();
	laser_data.clear();
	laser_apod.clear();
	result.clear();
}

TEST_F(DSPFixture, LaserFirFilter) {
	std::vector<double> laser_fir_filter;
	std::vector<double> laser_apod;
	std::vector<double> laser_fir_filtered;
	std::vector<double> result;

	laser_fir_filter = read_doubles(ifs_laser_fir_filter);
	laser_apod = read_doubles(ifs_laser_apod);
	laser_fir_filtered = read_doubles(ifs_laser_fir_filtered);

	dsp->apply_fir_filter(laser_apod, laser_fir_filter, result);

	ASSERT_EQ(laser_fir_filtered.size(), result.size());

	for (size_t i = 0; i < laser_fir_filtered.size(); i++) {
		EXPECT_DOUBLE_EQ(laser_fir_filtered[i], result[i]);
	}

	laser_fir_filter.clear();
	laser_apod.clear();
	laser_fir_filtered.clear();
	result.clear();
}

TEST_F(DSPFixture, DetectorFirFilter) {
	std::vector<double> detector_fir_filter;
	std::vector<double> detector_data;
	std::vector<double> detector_fir_filtered;
	std::vector<double> result;

	detector_fir_filter = read_doubles(ifs_detector_fir_filter);
	detector_data = read_doubles(ifs_detector_data);
	detector_fir_filtered = read_doubles(ifs_detector_fir_filtered);

	dsp->apply_fir_filter(detector_data, detector_fir_filter, result);

	ASSERT_EQ(detector_fir_filtered.size(), result.size());

	for (size_t i = 0; i < detector_fir_filtered.size(); i++) {
		EXPECT_DOUBLE_EQ(detector_fir_filtered[i], result[i]);
	}

	detector_fir_filter.clear();
	detector_data.clear();
	detector_fir_filtered.clear();
	result.clear();
}

TEST_F(DSPFixture, CheckPeakToPeakAmplitude) {
	std::vector<double> laser_fir_filtered;

	laser_fir_filtered = read_doubles(ifs_laser_fir_filtered);

	EXPECT_TRUE(dsp->check_peak_to_peak_amplitude(laser_fir_filtered));

	laser_fir_filtered.clear();
}

TEST_F(DSPFixture, DetectZeroCrossings) {
	std::vector<double> laser_fir_filtered;
	std::vector<double> laser_zero_crossings;
	std::vector<double> result;

	laser_fir_filtered = read_doubles(ifs_laser_fir_filtered);
	laser_zero_crossings = read_doubles(ifs_laser_zero_crossings);

	dsp->detect_zero_crossings(laser_fir_filtered, result);

	ASSERT_EQ(laser_zero_crossings.size(), result.size());

	for (size_t i = 0; i < laser_zero_crossings.size(); i++) {
		EXPECT_DOUBLE_EQ(laser_zero_crossings[i], result[i]);
	}

	laser_fir_filtered.clear();
	laser_zero_crossings.clear();
	result.clear();
}

TEST_F(DSPFixture, InterpolateDetectorData) {
	std::vector<double> laser_zero_crossings;
	std::vector<double> detector_fir_filtered;
	std::vector<double> detector_interpolated;
	std::vector<double> time_axis;

	laser_zero_crossings = read_doubles(ifs_laser_zero_crossings);
	detector_fir_filtered = read_doubles(ifs_detector_fir_filtered);
	detector_interpolated = read_doubles(ifs_detector_interpolated);
	time_axis = read_doubles(ifs_time_axis);

	std::vector<double> res_time_axis;
	std::vector<double> res_interpolated;

	dsp->interpolate_interferogram(laser_zero_crossings, detector_fir_filtered, res_time_axis, res_interpolated);

	ASSERT_EQ(time_axis.size(), res_time_axis.size());
	ASSERT_EQ(detector_interpolated.size(), res_interpolated.size());

	for (size_t i = 0; i < time_axis.size(); i++) {
		EXPECT_DOUBLE_EQ(time_axis[i], res_time_axis[i]);
	}

	for (size_t i = 0; i < detector_interpolated.size(); i++) {
		EXPECT_DOUBLE_EQ(detector_interpolated[i], res_interpolated[i]);
	}

	laser_zero_crossings.clear();
	detector_fir_filtered.clear();
	detector_interpolated.clear();
	time_axis.clear();
	res_time_axis.clear();
	res_interpolated.clear();
}

TEST_F(DSPFixture, BuildSpeedVector) {
	std::vector<double> detector_interpolated;
	std::vector<double> speed_vector;
	std::vector<double> time_axis;
	std::vector<double> result;

	detector_interpolated = read_doubles(ifs_detector_interpolated);
	speed_vector = read_doubles(ifs_speed_vector);
	time_axis = read_doubles(ifs_time_axis);

	dsp->build_speed_vector(detector_interpolated.size(), time_axis, result);

	ASSERT_EQ(speed_vector.size(), result.size());

	for (size_t i = 0; i < speed_vector.size(); i++) {
		EXPECT_DOUBLE_EQ(speed_vector[i], result[i]);
	}

	speed_vector.clear();
	time_axis.clear();
	result.clear();
}

TEST_F(DSPFixture, FindScanWindows) {
	std::vector<double> laser_zero_crossings;
	std::vector<int> scan_windows;
	size_t start_forward, end_forward, start_reverse, end_reverse;

	laser_zero_crossings = read_doubles(ifs_laser_zero_crossings);
	scan_windows = read_ints(ifs_scan_windows);

	dsp->find_scan_windows(laser_zero_crossings, start_forward, end_forward, start_reverse, end_reverse);

	EXPECT_EQ(scan_windows[0], start_forward);
	EXPECT_EQ(scan_windows[1], end_forward);
	EXPECT_EQ(scan_windows[2], start_reverse);
	EXPECT_EQ(scan_windows[3], end_reverse);

	laser_zero_crossings.clear();
	scan_windows.clear();
}

TEST_F(DSPFixture, FindPeaks) {
	std::vector<double> detector_interpolated;
	std::vector<int> scan_windows;
	std::vector<int> peaks;
	size_t peak_forward, peak_reverse;

	detector_interpolated = read_doubles(ifs_detector_interpolated);
	scan_windows = read_ints(ifs_scan_windows);
	peaks = read_ints(ifs_peaks);

	dsp->find_peaks(detector_interpolated, scan_windows[0], scan_windows[1], scan_windows[2], scan_windows[3], peak_forward, peak_reverse);

	EXPECT_EQ(peaks[0], peak_forward);
	EXPECT_EQ(peaks[1], peak_reverse);

	detector_interpolated.clear();
	scan_windows.clear();
	peaks.clear();
}

TEST_F(DSPFixture, EnoughPointsForward) {
	std::vector<int> scan_windows;
	std::vector<int> peaks;
	std::vector<bool> enough_points;

	scan_windows = read_ints(ifs_scan_windows);
	peaks = read_ints(ifs_peaks);
	enough_points = read_bools(ifs_enough_points);

	bool ok_forward = dsp->enough_points_forward(scan_windows[0], scan_windows[1], peaks[0]);

	EXPECT_EQ(enough_points[0], ok_forward);

	scan_windows.clear();
	peaks.clear();
	enough_points.clear();
}

TEST_F(DSPFixture, EnoughPointsReverse) {
	std::vector<int> scan_windows;
	std::vector<int> peaks;
	std::vector<bool> enough_points;

	scan_windows = read_ints(ifs_scan_windows);
	peaks = read_ints(ifs_peaks);
	enough_points = read_bools(ifs_enough_points);

	bool ok_reverse = dsp->enough_points_reverse(scan_windows[2], scan_windows[3], peaks[1]);

	EXPECT_EQ(enough_points[1], ok_reverse);

	scan_windows.clear();
	peaks.clear();
	enough_points.clear();
}

TEST_F(DSPFixture, CreateReferenceScanForward) {
	std::vector<double> detector_interpolated;
	std::vector<int> scan_windows;
	std::vector<int> peaks;
	std::vector<double> reference_scan;
	std::vector<double> result;

	detector_interpolated = read_doubles(ifs_detector_interpolated);
	scan_windows = read_ints(ifs_scan_windows);
	peaks = read_ints(ifs_peaks);
	reference_scan = read_doubles(ifs_reference_scan_forward);

	size_t start = scan_windows[0];
	size_t peak = peaks[0];
	dsp->create_reference_scan_forward(detector_interpolated, start, peak, result);

	ASSERT_EQ(reference_scan.size(), result.size());

	for (size_t i = 0; i < reference_scan.size(); i++) {
		EXPECT_DOUBLE_EQ(reference_scan[i], result[i]);
	}

	detector_interpolated.clear();
	scan_windows.clear();
	peaks.clear();
	reference_scan.clear();
}

TEST_F(DSPFixture, CreateReferenceScanReverse) {
	std::vector<double> detector_interpolated;
	std::vector<int> scan_windows;
	std::vector<int> peaks;
	std::vector<double> reference_scan;
	std::vector<double> result;

	detector_interpolated = read_doubles(ifs_detector_interpolated);
	scan_windows = read_ints(ifs_scan_windows);
	peaks = read_ints(ifs_peaks);
	reference_scan = read_doubles(ifs_reference_scan_reverse);

	size_t start = scan_windows[2];
	size_t peak = peaks[1];
	dsp->create_reference_scan_reverse(detector_interpolated, start, peak, result);

	ASSERT_EQ(reference_scan.size(), result.size());

	for (size_t i = 0; i < reference_scan.size(); i++) {
		EXPECT_DOUBLE_EQ(reference_scan[i], result[i]);
	}

	detector_interpolated.clear();
	scan_windows.clear();
	peaks.clear();
	reference_scan.clear();
}

TEST_F(DSPFixture, CalculateShiftForward) {
	std::vector<double> detector_interpolated;
	std::vector<int> scan_windows;
	std::vector<int> peaks;
	std::vector<double> reference_scan;
	std::vector<int> shifted_start;

	detector_interpolated = read_doubles(ifs_detector_interpolated);
	scan_windows = read_ints(ifs_scan_windows);
	peaks = read_ints(ifs_peaks);
	reference_scan = read_doubles(ifs_reference_scan_forward);
	shifted_start = read_ints(ifs_shifted_start);

	size_t start = scan_windows[0];
	size_t peak = peaks[0];
	size_t res_shifted_start = dsp->compute_shift_forward(detector_interpolated, reference_scan, start, peak);

	EXPECT_EQ(shifted_start[0], res_shifted_start);

	detector_interpolated.clear();
	scan_windows.clear();
	peaks.clear();
	reference_scan.clear();
}

TEST_F(DSPFixture, CalculateShiftReverse) {
	std::vector<double> detector_interpolated;
	std::vector<int> scan_windows;
	std::vector<int> peaks;
	std::vector<double> reference_scan;
	std::vector<int> shifted_start;

	detector_interpolated = read_doubles(ifs_detector_interpolated);
	scan_windows = read_ints(ifs_scan_windows);
	peaks = read_ints(ifs_peaks);
	reference_scan = read_doubles(ifs_reference_scan_reverse);
	shifted_start = read_ints(ifs_shifted_start);

	size_t start = scan_windows[2];
	size_t peak = peaks[1];
	size_t res_shifted_start = dsp->compute_shift_reverse(detector_interpolated, reference_scan, start, peak);

	EXPECT_EQ(shifted_start[1], res_shifted_start);

	detector_interpolated.clear();
	scan_windows.clear();
	peaks.clear();
	reference_scan.clear();
}

TEST_F(DSPFixture, SpeedIsOkForward) {
	std::vector<double> speed_vector;
	std::vector<int> shifted_start;
	std::vector<bool> speed_ok;

	speed_vector = read_doubles(ifs_speed_vector);
	shifted_start = read_ints(ifs_shifted_start);
	speed_ok = read_bools(ifs_speed_ok);

	bool ok = dsp->speed_is_ok(shifted_start[0], speed_vector);

	EXPECT_EQ(speed_ok[0], ok);

	speed_vector.clear();
	shifted_start.clear();
	speed_ok.clear();
}


TEST_F(DSPFixture, SpeedIsOkReverse) {
	std::vector<double> speed_vector;
	std::vector<int> shifted_start;
	std::vector<bool> speed_ok;

	speed_vector = read_doubles(ifs_speed_vector);
	shifted_start = read_ints(ifs_shifted_start);
	speed_ok = read_bools(ifs_speed_ok);

	bool ok = dsp->speed_is_ok(shifted_start[1], speed_vector);

	EXPECT_EQ(speed_ok[1], ok);

	speed_vector.clear();
	shifted_start.clear();
	speed_ok.clear();
}

TEST_F(DSPFixture, CalculateIsolateForward) {
	std::vector<double> detector_interpolated;
	std::vector<int> shifted_start;
	std::vector<double> shifted_scan;
	std::vector<double> result;

	detector_interpolated = read_doubles(ifs_detector_interpolated);
	shifted_start = read_ints(ifs_shifted_start);
	shifted_scan = read_doubles(ifs_shifted_scan_forward);

	dsp->calculate_isolate_forward(detector_interpolated, shifted_start[0], result);

	ASSERT_EQ(shifted_scan.size(), result.size());

	for (size_t i = 0; i < shifted_scan.size(); i++) {
		EXPECT_DOUBLE_EQ(shifted_scan[i], result[i]);
	}

	detector_interpolated.clear();
	shifted_start.clear();
	shifted_scan.clear();
	result.clear();
}

TEST_F(DSPFixture, CalculateIsolateReverse) {
	std::vector<double> detector_interpolated;
	std::vector<int> shifted_start;
	std::vector<double> shifted_scan;
	std::vector<double> result;

	detector_interpolated = read_doubles(ifs_detector_interpolated);
	shifted_start = read_ints(ifs_shifted_start);
	shifted_scan = read_doubles(ifs_shifted_scan_reverse);

	dsp->calculate_isolate_reverse(detector_interpolated, shifted_start[1], result);

	ASSERT_EQ(shifted_scan.size(), result.size());

	for (size_t i = 0; i < shifted_scan.size(); i++) {
		EXPECT_DOUBLE_EQ(shifted_scan[i], result[i]);
	}

	detector_interpolated.clear();
	shifted_start.clear();
	shifted_scan.clear();
	result.clear();
}

TEST_F(DSPFixture, CalculateAveragedScansForward) {
	std::vector<std::vector<double>> scans_vector;
	std::vector<double> average_scan;
	std::vector<double> result;

	scans_vector.push_back(read_doubles(ifs_shifted_scan_0_forward));
	scans_vector.push_back(read_doubles(ifs_shifted_scan_1_forward));
	scans_vector.push_back(read_doubles(ifs_shifted_scan_2_forward));
	scans_vector.push_back(read_doubles(ifs_shifted_scan_3_forward));

	average_scan = read_doubles(ifs_average_scan_forward);

	dsp->calculate_averaged_scans(scans_vector, result);

	ASSERT_EQ(average_scan.size(), result.size());

	for (size_t i = 0; i < average_scan.size(); i++) {
		EXPECT_DOUBLE_EQ(average_scan[i], result[i]);
	}

	for (auto i = 0; i < 4; i++)
		scans_vector[i].clear();
	scans_vector.clear();
	average_scan.clear();
	result.clear();
}

TEST_F(DSPFixture, CalculateAveragedScansReverse) {
	std::vector<std::vector<double>> scans_vector;
	std::vector<double> average_scan;
	std::vector<double> result;

	scans_vector.push_back(read_doubles(ifs_shifted_scan_0_reverse));
	scans_vector.push_back(read_doubles(ifs_shifted_scan_1_reverse));
	scans_vector.push_back(read_doubles(ifs_shifted_scan_2_reverse));
	scans_vector.push_back(read_doubles(ifs_shifted_scan_3_reverse));

	average_scan = read_doubles(ifs_average_scan_reverse);

	dsp->calculate_averaged_scans(scans_vector, result);

	ASSERT_EQ(average_scan.size(), result.size());

	for (size_t i = 0; i < average_scan.size(); i++) {
		EXPECT_DOUBLE_EQ(average_scan[i], result[i]);
	}

	for (auto i = 0; i < 4; i++)
		scans_vector[i].clear();
	scans_vector.clear();
	average_scan.clear();
	result.clear();
}

TEST_F(DSPFixture, CalculateCenteredAveragedScansForward) {
	std::vector<double> average_scan;
	std::vector<double> centered_average_scan;
	std::vector<double> result;

	average_scan = read_doubles(ifs_average_scan_forward);
	centered_average_scan = read_doubles(ifs_centered_average_scan_forward);

	dsp->calculate_centered_averaged_scans(average_scan, result);

	ASSERT_EQ(centered_average_scan.size(), result.size());

	for (size_t i = 0; i < centered_average_scan.size(); i++) {
		EXPECT_LE(abs(centered_average_scan[i] - result[i]), max_deviation);
	}

	average_scan.clear();
	centered_average_scan.clear();
	result.clear();
}

TEST_F(DSPFixture, CalculateCenteredAveragedScansReverse) {
	std::vector<double> average_scan;
	std::vector<double> centered_average_scan;
	std::vector<double> result;

	average_scan = read_doubles(ifs_average_scan_reverse);
	centered_average_scan = read_doubles(ifs_centered_average_scan_reverse);

	dsp->calculate_centered_averaged_scans(average_scan, result);

	ASSERT_EQ(centered_average_scan.size(), result.size());

	for (size_t i = 0; i < centered_average_scan.size(); i++) {
		EXPECT_LE(abs(centered_average_scan[i] - result[i]), max_deviation);
	}

	average_scan.clear();
	centered_average_scan.clear();
	result.clear();
}

TEST_F(DSPFixture, CalculatePhaseCorrectionForward) {
	std::vector<double> centered_average_scan;
	std::vector<double> phase_corrected_scan;
	std::vector<double> result;

	centered_average_scan = read_doubles(ifs_centered_average_scan_forward);
	phase_corrected_scan = read_doubles(ifs_phase_corrected_scan_forward);

	dsp->calculate_phase_correction(centered_average_scan, result);

	ASSERT_EQ(phase_corrected_scan.size(), result.size());

	for (size_t i = 0; i < phase_corrected_scan.size(); i++) {
		EXPECT_LE(abs(phase_corrected_scan[i] - result[i]), max_deviation);
	}

	centered_average_scan.clear();
	phase_corrected_scan.clear();
	result.clear();
}

TEST_F(DSPFixture, CalculatePhaseCorrectionReverse) {
	std::vector<double> centered_average_scan;
	std::vector<double> phase_corrected_scan;
	std::vector<double> result;

	centered_average_scan = read_doubles(ifs_centered_average_scan_reverse);
	phase_corrected_scan = read_doubles(ifs_phase_corrected_scan_reverse);

	dsp->calculate_phase_correction(centered_average_scan, result);

	ASSERT_EQ(phase_corrected_scan.size(), result.size());

	for (size_t i = 0; i < phase_corrected_scan.size(); i++) {
		EXPECT_LE(abs(phase_corrected_scan[i] - result[i]), max_deviation);
	}

	centered_average_scan.clear();
	phase_corrected_scan.clear();
	result.clear();
}

TEST_F(DSPFixture, CalculateRawSpectrumForward) {
	std::vector<double> phase_corrected_scan;
	std::vector<double> raw_spectrum;
	std::vector<double> result;

	phase_corrected_scan = read_doubles(ifs_phase_corrected_scan_forward);
	raw_spectrum = read_doubles(ifs_raw_spectrum_forward);

	dsp->calculate_raw_spectrum(phase_corrected_scan, result);

	ASSERT_EQ(raw_spectrum.size(), result.size());

	for (size_t i = 0; i < raw_spectrum.size(); i++) {
		EXPECT_LE(abs(raw_spectrum[i] - result[i]), max_deviation);
	}

	phase_corrected_scan.clear();
	raw_spectrum.clear();
	result.clear();
}

TEST_F(DSPFixture, CalculateRawSpectrumReverse) {
	std::vector<double> phase_corrected_scan;
	std::vector<double> raw_spectrum;
	std::vector<double> result;

	phase_corrected_scan = read_doubles(ifs_phase_corrected_scan_reverse);
	raw_spectrum = read_doubles(ifs_raw_spectrum_reverse);

	dsp->calculate_raw_spectrum(phase_corrected_scan, result);

	ASSERT_EQ(raw_spectrum.size(), result.size());

	for (size_t i = 0; i < raw_spectrum.size(); i++) {
		EXPECT_LE(abs(raw_spectrum[i] - result[i]), max_deviation);
	}

	phase_corrected_scan.clear();
	raw_spectrum.clear();
	result.clear();
}

TEST_F(DSPFixture, CalculateDispersionCorrectedSpectrumForward) {
	std::vector<double> raw_spectrum;
	std::vector<double> dispersion_corrected_spectrum;
	std::vector<double> axis_dispersion_corrected_spectrum;
	std::vector<double> spectrum;
	std::vector<double> axis;

	raw_spectrum = read_doubles(ifs_raw_spectrum_forward);
	dispersion_corrected_spectrum = read_doubles(ifs_dispersion_corrected_spectrum_forward);
	axis_dispersion_corrected_spectrum = read_doubles(ifs_axis_dispersion_corrected_spectrum_forward);

	dsp->calculate_dispersion_corrected_spectrum(raw_spectrum, wedge_drive_temperature, spectrum, axis);

	ASSERT_EQ(dispersion_corrected_spectrum.size(), spectrum.size());
	ASSERT_EQ(axis_dispersion_corrected_spectrum.size(), axis.size());

	for (size_t i = 0; i < dispersion_corrected_spectrum.size(); i++) {
		EXPECT_LE(abs(dispersion_corrected_spectrum[i] - spectrum[i]), max_deviation);
	}
	for (size_t i = 0; i < axis_dispersion_corrected_spectrum.size(); i++) {
		EXPECT_LE(abs(axis_dispersion_corrected_spectrum[i] - axis[i]), max_deviation);
	}

	raw_spectrum.clear();
	dispersion_corrected_spectrum.clear();
	axis_dispersion_corrected_spectrum.clear();
	spectrum.clear();
	axis.clear();
}

TEST_F(DSPFixture, CalculateDispersionCorrectedSpectrumReverse) {
	std::vector<double> raw_spectrum;
	std::vector<double> dispersion_corrected_spectrum;
	std::vector<double> axis_dispersion_corrected_spectrum;
	std::vector<double> spectrum;
	std::vector<double> axis;

	raw_spectrum = read_doubles(ifs_raw_spectrum_reverse);
	dispersion_corrected_spectrum = read_doubles(ifs_dispersion_corrected_spectrum_reverse);
	axis_dispersion_corrected_spectrum = read_doubles(ifs_axis_dispersion_corrected_spectrum_reverse);

	dsp->calculate_dispersion_corrected_spectrum(raw_spectrum, wedge_drive_temperature, spectrum, axis);

	ASSERT_EQ(dispersion_corrected_spectrum.size(), spectrum.size());
	ASSERT_EQ(axis_dispersion_corrected_spectrum.size(), axis.size());

	for (size_t i = 0; i < dispersion_corrected_spectrum.size(); i++) {
		EXPECT_LE(abs(dispersion_corrected_spectrum[i] - spectrum[i]), max_deviation);
	}
	for (size_t i = 0; i < axis_dispersion_corrected_spectrum.size(); i++) {
		EXPECT_LE(abs(axis_dispersion_corrected_spectrum[i] - axis[i]), max_deviation);
	}

	raw_spectrum.clear();
	dispersion_corrected_spectrum.clear();
	axis_dispersion_corrected_spectrum.clear();
	spectrum.clear();
	axis.clear();
}

TEST_F(DSPFixture, CalculateDispersionCorrectedSpectrumAverage) {
	std::vector<double> dispersion_corrected_spectrum_forward;
	std::vector<double> dispersion_corrected_spectrum_reverse;
	std::vector<double> dispersion_corrected_spectrum_average;
	std::vector<double> result;

	dispersion_corrected_spectrum_forward = read_doubles(ifs_dispersion_corrected_spectrum_forward);
	dispersion_corrected_spectrum_reverse = read_doubles(ifs_dispersion_corrected_spectrum_reverse);
	dispersion_corrected_spectrum_average = read_doubles(ifs_dispersion_corrected_spectrum_average);

	dsp->calculate_average_spectrum(dispersion_corrected_spectrum_forward, dispersion_corrected_spectrum_reverse, result);

	ASSERT_EQ(dispersion_corrected_spectrum_average.size(), result.size());

	for (size_t i = 0; i < dispersion_corrected_spectrum_average.size(); i++) {
		EXPECT_LE(abs(dispersion_corrected_spectrum_average[i]) - result[i], max_deviation);
	}

	dispersion_corrected_spectrum_forward.clear();
	dispersion_corrected_spectrum_reverse.clear();
	dispersion_corrected_spectrum_average.clear();
	result.clear();
}
