#include "Vector.h"
#include <numeric>

//////////////////////////////////////////////////////////////////////////
void Vector::convolution(const std::vector<double>& x, const std::vector<double>& k, std::vector<double>& c)
{
	const size_t N = x.size();				// length of time series
	const size_t K = k.size();				// window size
	std::vector<double> y(N + K - 1, 0.0);	// filtered output vector

	// Apply filter (taken from NIRSolution software COMTvect.cs > Conv()
	// //////////////////////////////////////////////////////////////////

	double sum;

	// Process the first filter length separately (for performance reasons)
	size_t x_idx, k_idx;
	for (x_idx = 0; x_idx < K; x_idx++) {
		sum = 0.0;
		for (k_idx = 0; k_idx < K; k_idx++) {
			if (k_idx > x_idx)
				break;

			sum += k[k_idx] * x[x_idx - k_idx];
		}

		y[x_idx] = sum;
	}

	// Now process all from the second to the penultimate filter length
	for (x_idx = K; x_idx < N; x_idx++) {
		sum = 0.0;
		for (k_idx = 0; k_idx < K; k_idx++) {
			sum += k[k_idx] * x[x_idx - k_idx];
		}

		y[x_idx] = sum;
	}

	// Finally process the last filter length
	for (x_idx = N; x_idx < N + K - 1; x_idx++) {
		sum = 0.0;
		for (k_idx = 0; k_idx < K; k_idx++) {
			if (x_idx - k_idx < N)
				sum += k[k_idx] * x[x_idx - k_idx];
		}

		y[x_idx] = sum;
	}

	// Make output vec
	std::copy(y.begin(), y.end(), std::back_inserter(c));
}

//////////////////////////////////////////////////////////////////////////
void Vector::free_cubic_spline_interpolation(const std::vector<double>& x_in, const std::vector<double>& y_in, const std::vector<double>& x_out, std::vector<double>& y_out)
{
	// This alogrithm is taken from the original N-500 software
	// COMTvect.cs: FreeCubicSpline
	const size_t len_in = x_in.size();  // length of the input vector
	const size_t len_out = x_out.size();  // length of the output vector

	// The original algorithm uses 1-based arrays, so prepend a 0 to the arrays
	std::vector<double> xi(len_in + 1);
	std::vector<double> yi(len_in + 1);
	std::vector<double> yo(len_out + 1);
	std::vector<double> xo(len_out + 1);

	xi[0] = 0.0;
	for (size_t i = 0; i < len_in; i++) {
		xi[i + 1] = x_in[i];
	}
	yi[0] = 0.0;
	for (size_t i = 0; i < len_in; i++) {
		yi[i + 1] = y_in[i];
	}
	xo[0] = 0.0;
	for (size_t i = 0; i < len_out; i++) {
		xo[i + 1] = x_out[i];
	}
	for (size_t i = 0; i < len_out + 1; i++) {
		yo[i] = 0.0;
	}

	std::vector<double> a2(len_in + 1);
	std::vector<double> Gamma(len_in + 1);
	std::vector<double> X(len_in + 1);

	for (size_t i = 0; i < len_in + 1; i++) {
		a2[i] = 0.0;
		Gamma[i] = 0.0;
		X[i] = 0.0;
	}

	// Calculate coefficients needed for the spline
	for (size_t i = 2; i < len_in; i++) {
		auto d = (yi[i + 1] - yi[i]) / (xi[i + 1] - xi[i]) - (yi[i] - yi[i - 1]) / (xi[i] - xi[i - 1]);
		Gamma[i] = 3 * d;
	}

	Gamma[1] = 0.0;
	Gamma[len_in] = 0.0;

	X[1] = 0.0;
	X[len_in] = 0.0;
	X[2] = 2 * (xi[3] - xi[1]);

	for (size_t i = 3; i < len_in; i++) {
		auto d = 2 * (xi[i + 1] - xi[i - 1]) - (xi[i] - xi[i - 1]) * (xi[i] - xi[i - 1]) / X[i - 1];
		X[i] = d;
		d = Gamma[i] - Gamma[i - 1] * (xi[i] - xi[i - 1]) / X[i - 1];
		Gamma[i] = d;
	}

	a2[1] = 0.0;
	a2[len_in] = 0.0;
	a2[len_in - 1] = Gamma[len_in - 1] / X[len_in - 1];

	for (size_t i = len_in - 2; i > 1; i--) {
		auto d = (Gamma[i] - (xi[i + 1] - xi[i]) * a2[i + 1]) / X[i];
		a2[i] = d;
	}

	double Hi = 0.0;
	double H = 0.0;
	double x = 0.0;
	double a1 = 0.0;
	double a3 = 0.0;

	size_t j = 1;
	for (size_t i = 1; i < len_out + 1; i++) {
		while (xi[j] < xo[i]) {
			if (j == len_in)
				break;
			j++;
		}
		x = xo[i] - xi[j - 1];
		Hi = xi[j] - xi[j - 1];
		a3 = (a2[j] - a2[j - 1]) / (3 * Hi);
		a1 = (yi[j] - yi[j - 1]) / Hi - Hi * (2 * a2[j - 1] + a2[j]) / 3;
		H = a3 * x + a2[j - 1];
		H = H * x + a1;
		H = H * x + yi[j - 1];
		yo[i] = H;
	}

	// Copy yo into YO (dropping index 0)
	for (size_t i = 1; i < len_out + 1; i++) {
		y_out.push_back(yo[i]);
	}
}

//////////////////////////////////////////////////////////////////////////
void Vector::complex(const std::vector<double>& v, std::vector<std::complex<double>>& cv)
{
	for (auto& v : v) {
		std::complex<double> c(v, 0.0);
		cv.push_back(c);
	}
}


//////////////////////////////////////////////////////////////////////////
void Vector::fftshift_complex(std::vector<std::complex<double>>& cv)
{
	auto size = cv.size();

	std::vector<double> real, imag;
	for (auto& c : cv) {
		real.push_back(c.real());
		imag.push_back(c.imag());
	}

	fftshift(real.data(), size);
	fftshift(imag.data(), size);

	cv.clear();
	for (size_t i = 0; i < real.size(); i++) {
		std::complex<double> c(real[i], imag[i]);
		cv.push_back(c);
	}
}

//////////////////////////////////////////////////////////////////////////
void Vector::fftshift(double data[], size_t size)
{
	// swap left and right parts of (complex) data array

	if (size <= 1) return;

	// Use a temp vector t for creating the result
	std::vector<double> t;
	// init t
	for (auto i = 0; i < size; i++) {
		t.push_back(0.0);
	}

	auto i = 0;
	auto len2 = size / 2;
	auto odd = size % 2; // 1: odd, 0: even

	for (i = 0; i < len2; i++) {
		t[i] = data[i + len2 + odd];	// lower half
		t[i + len2] = data[i];			// upper half
	}

	// if odd then the last element has to be handled seperately
	if (odd == 1) {
		t[i + len2] = data[i];
	}

	// return t
	for (auto i = 0; i < size; i++) {
		data[i] = t[i];
	}
}

//////////////////////////////////////////////////////////////////////////
double Vector::mean(const std::vector<double>& v, size_t start_idx, size_t length)
{
	return std::accumulate(v.begin() + start_idx, v.begin() + start_idx + length, 0.0) / length;
}

//////////////////////////////////////////////////////////////////////////
double Vector::mean(const std::vector<double>& v)
{
	return mean(v, 0, v.size());
}

//////////////////////////////////////////////////////////////////////////
void Vector::abs(const std::vector<std::complex<double>>& cv, std::vector<double>& v)
{
	for (auto& c : cv) {
		v.push_back(std::abs(c));
	}
}

//////////////////////////////////////////////////////////////////////////
void Vector::conj(const std::vector<std::complex<double>>& cv, std::vector<std::complex<double>>& cv_conj)
{
	for (auto& c : cv) {
		cv_conj.push_back(std::conj(c));
	}
}

//////////////////////////////////////////////////////////////////////////
void Vector::real(const std::vector<std::complex<double>>& cv, std::vector<double>& v)
{
	for (auto& c : cv) {
		v.push_back(c.real());
	}
}

//////////////////////////////////////////////////////////////////////////
void Vector::mult(const std::vector<double>& a, const std::vector<double>& b, std::vector<double>& c)
{
	for (auto i = 0; i < a.size(); i++) {
		c.push_back(a[i] * b[i]);
	}
}

//////////////////////////////////////////////////////////////////////////
void Vector::scale(std::vector<double>& vec, double x)
{
	for (auto& e : vec) {
		e *= x;
	}
}

//////////////////////////////////////////////////////////////////////////
void Vector::slice(const std::vector<double>& vec, size_t start, size_t len, std::vector<double>& vec_out)
{
	std::copy(vec.begin() + start, vec.begin() + start + len, std::back_inserter(vec_out));
}


//////////////////////////////////////////////////////////////////////////
double Vector::max_at(const std::vector<double>& v, size_t& at)
{
	at = 0;

	if (v.size() == 0) {
		return 0;
	}

	double m = v[0];
	for (size_t i = 1; i < v.size(); i++) {
		if (v[i] >= m) {
			m = v[i];
			at = i;		// position of the LAST maximum
		}
	}

	return m;
}

//////////////////////////////////////////////////////////////////////////
double Vector::min_at(const std::vector<double>& v, const std::vector<double>& sel, size_t& at)
{
	double min = INT32_MAX;
	at = 0;

	if (v.size() == 0 || v.size() != sel.size() || max_at(sel, at) < 1.0) {
		at = 0;
		return 0.0;
	}

	at = 0;

	for (size_t i = 0; i < v.size(); i++) {
		if (sel[i] > 0.0) {
			// selected
			if (v[i] <= min) {
				// new minimum
				min = v[i];
				at = i;		// position of last minimum
			}
		}
	}

	return min;
}

//////////////////////////////////////////////////////////////////////////
void Vector::selection(std::vector<double>& v, size_t start, size_t len, double val)
{
	for (size_t i = start; i < std::min(start + len, v.size()); i++) {
		v[i] = val;
	}
}
