#pragma once

#include <complex>
#include <iterator>
#include <vector>

/// <summary>
/// Provides functions on vectors
/// </summary>
static class Vector
{
public:
    /// <summary>
    /// Convolution / Linear Filter / Faltung
    /// Warning: filter vector should not be longer than the data vector
    /// </summary>
    /// <param name="vec1">in: </param>
    /// <param name="x">in: data vector</param>
    /// <param name="k">in: filter vector</param>
    /// <param name="c">out: convoluted data vector</param>
    static void convolution(const std::vector<double>& x, const std::vector<double>& k, std::vector<double>& c);
    
    
    /// <summary>
    /// Cubic Spline Interpolation
    /// Interpolates the curve given with x-values given in x_in and y-values in y_in at the
    /// x-values given in x_out. The interpolated y-values are returned in y_out.
    /// </summary>
    /// <param name="x_in">in: x-axis input  values</param>
    /// <param name="y_in">in: y-axis input  values</param>
    /// <param name="x_out">in: x-axis output values</param>
    /// <param name="y_out">out: y-axis output values</param>
    static void free_cubic_spline_interpolation(const std::vector<double>& x_in, const std::vector<double>& y_in, const std::vector<double>& x_out, std::vector<double>& y_out);

    /// <summary>
    /// Creates a complex vector, given a real vector. The real values are the
    /// values of the real vector, and the imaginary values are all set to zero.
    /// </summary>
    /// <param name="v">in: real vector</param>
    /// <param name="cv">out: complex vector</param>
    static void complex(const std::vector<double>& v, std::vector<std::complex<double>>& cv);

    /// <summary>
    /// Swap left and right halves of a complex vector.
    /// This is used before and after FFT/IFFT calculations.
    /// </summary>
    /// <param name="cv">in/out: complex vector</param>
    static void fftshift_complex(std::vector<std::complex<double>>& cv);

    /// <summary>
    /// Swap left and right halves of a real vector.
    /// This is used before and after FFT/IFFT calculations.
    /// </summary>
    /// <param name="cv">in/out: real vector</param>
    static void fftshift(double data[], size_t size);

    /// <summary>
    /// Computes the average of a slice of a vector.
    /// </summary>
    /// <param name="v">in: data vector</param>
    /// <param name="start_idx">in: start index of the slice</param>
    /// <param name="length">in: length of the slice</param>
    /// <returns>Average</returns>
    static double mean(const std::vector<double>& v, size_t start_idx, size_t length);

    /// <summary>
    /// Computes the mean of a vector.
    /// </summary>
    /// <param name="v">in: data vector</param>
    /// <returns>mean value</returns>
    static double mean(const std::vector<double>& v);

    /// <summary>
    /// Takes a vector of complex values and creates a vector with their absolute values.
    /// </summary>
    /// <param name="cv">in: vector with complex values</param>
    /// <param name="v">out: real vector with the absolute values</param>
    static void abs(const std::vector<std::complex<double>>& cv, std::vector<double>& v);

    /// <summary>
    /// Takes a complex vector and creates another complex vector containing
    /// their conjugate values.
    /// </summary>
    /// <param name="cv">in: vector with complex values</param>
    /// <param name="cv_conj">out: vector with conjugated complex values</param>
    static void conj(const std::vector<std::complex<double>>& cv, std::vector<std::complex<double>>& cv_conj);

    /// <summary>
    /// Takes a vector of complex numbers and creates a vector with their real values.
    /// </summary>
    /// <param name="cv">in: complex vector</param>
    /// <param name="v">out: real vector with the real parts</param>
    static void real(const std::vector<std::complex<double>>& cv, std::vector<double>& v);

    /// <summary>
    /// Multiplies two vectors with real values, element by element.
    /// </summary>
    /// <param name="a">in: vector</param>
    /// <param name="b">in: vector</param>
    /// <param name="c">out: vector, a * b</param>
    static void mult(const std::vector<double>& a, const std::vector<double>& b, std::vector<double>& c);

    /// <summary>
    /// Scale a vector in place with a value.
    /// </summary>
    /// <param name="vec"></param>
    /// <param name="x"></param>
    static void scale(std::vector<double>& vec, double x);

    /// <summary>
    /// Creates a slice of a vector with a given start index and length of the slice.
    /// </summary>
    /// <param name="vec>in: vector to be sliced</param>
    /// <param name="start">in: start index of slice</param>
    /// <param name="len">in: length of slice</param>
    /// <param name="vec_out">out: slice of input vector</param>
    static void slice(const std::vector<double>& vec, size_t start, size_t len, std::vector<double>& vec_out);

    /// <summary>
    /// Calculates the minimum of a vector and the index of its last occurrence, from left to right.
    /// </summary>
    /// <param name="v">in: input vector</param>
    /// <param name="at">out: index of last minimum</param>
    /// <return>minimum of vector</return>
    static double max_at(const std::vector<double>& v, size_t& at);

    /// <summary>
    /// Calculates the minimum of a slice of a vector and the index of its last occurrence, from left to rigth.
    /// </summary>
    /// <param name="v">in: input vector</param>
    /// <param name="sel">in: selection vector defining the slice</param>
    /// <param name="at">out: index of last minimum, from left to rigth</param>
    static double min_at(const std::vector<double>& v, const std::vector<double>& sel, size_t& at);

    /// <summary>
    /// Creates a selection vector in place from a zero filled input vector. The selection is defined
    /// by its start index and its length. The value given in val is set in the selection area.
    /// </summary>
    /// <param name="v">in/out: input vector</param>
    /// <param name="start">in: start of selection area</param>
    /// <param name="len">in: length of selection area</param>
    /// <param name="val">in: value of the elements in the selection area</param>
    static void selection(std::vector<double>& v, size_t start, size_t len, double val);
};
