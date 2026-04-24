#pragma once

#include <complex>
#include <vector>

/// <summary>
/// Fast Fourier Transformation
/// 
/// sine and cosine tables are created on init, for better performance.
/// This is taken from the original N-500 C# code: COMTcfft.cs
/// </summary>
class FFT
{
private:
	/// <summary>
	/// Length of the FFT, e.g. 1024
	/// </summary>
	size_t slice_len;
public:
	size_t get_slice_len() { return slice_len; }

private:
	/// <summary>
	/// Length of FFT as power of 2, e.g. 10 for slice_len 1024
	/// </summary>
	int power_of_two;
public:
	int get_power_of_two() { return power_of_two; }

private:
	/// <summary>
	/// Angle, real part, +cosine table
	/// </summary>
	std::vector<double> wr;

	/// <summary>
	/// Angle, imaginary part, -sine table
	/// </summary>
	std::vector<double> wi;

public:
	/// <summary>
	/// Inverse FFT (analog MATLAB ifft), real and imag are scaled with number of datapoints
	/// </summary>
	/// <param name="cv">complex vector</param>
	void ifft(std::vector<std::complex<double>>& cv);

	/// <summary>
	/// Inverse FFT (analog MATLAB ifft), real and imag are scaled with number of datapoints
	/// </summary>
	/// <param name="re"></param>
	/// <param name="im"></param>
	void ifft(std::vector<double>& re, std::vector<double>& im);

	/// <summary>
	/// Complex FFT, analog MATLAB fft                 
	/// </summary>
	/// <param name="cv">complex vector</param>
	void fft(std::vector<std::complex<double>>& cv);

	/// <summary>
	/// Complex FFT, analog MATLAB fft  
	/// </summary>
	/// <param name="re"></param>
	/// <param name="im"></param>
	void fft(std::vector<double>& re, std::vector<double>& im);

private:
	/// <summary>
	/// Complex FFT with inverse flage for IFFT
	/// 
	/// A COOLEY-TUKEY RADIX2, DIF FFT PROGRAMM
	/// COMPLEX INPUT DATA IN ARRAYS X AND Y
	/// TABLE LOOK-UP OF W VALUES
	/// (Numerical Recipies p. 108)
	/// 
	/// Aufwand N*ld(N) Multiplikationen
	///
	///   S o u r c e :                          
	///      Second-Order Goertzel Algorithmus   
	///      DFT/FFT and Convolution Algorythms
	///       Theorie and Implementation
	///       C.S.Burrus and T.W.Parks
	///       Rice University
	///       John Wiley & Sons                  
	/// </summary>
	/// <param name="x">real</param>
	/// <param name="y">imag</param>
	/// <param name="inverse_flag">True if ifft is called</param>
	void fft(std::vector<double>& x, std::vector<double>& y, bool inverse_flag);

public:
	/// <summary>
	/// Init of the FFT
	/// creates the sin/cos tables.
	/// </summary>
	void init(size_t slice_len);
};
