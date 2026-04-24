#include "FFT.h"
#include <stdexcept>
#include <string>

//////////////////////////////////////////////////////////////////////////////
// init static members
//////////////////////////////////////////////////////////////////////////////
//std::vector<double> FFT::wr = { 1.0 };
//std::vector<double> FFT::wi = { 0.0 };

//////////////////////////////////////////////////////////////////////////////
// public
//////////////////////////////////////////////////////////////////////////////

void FFT::init(size_t slice_length)
{
    const int MAX_SLICE_LEN = 2147483647;   // (2^32)/2-1
    const double pi = 3.14159265358979;

    if ((slice_length <= 2) || (slice_length >= MAX_SLICE_LEN)) {
        throw std::runtime_error(std::string("fft: slice length either too small or too large"));
    }

    // calculate power_of_two from slice_len and set slice_len to next fitting power of 2.
    // 
    //	Calculation example 1:
    //
    //	slice_len	= 500
    //		x		= 500	250	125	  62   31   15   7   3    1    0  
    //	count		=   0	  1	  2	   3	4    5   6   7    8    9
    //	slice_len	=	1	  2   4    8   16   32  64 128  256  512 = 2^9 = 2^count
    //
    //
    //	Calculation example 2: (border case)
    //
    //	slice_len	= 4			 ==> BUG: power of 2 becomes next hight power of 2 ! ==> THEREFORE x = slice_len - 1 !!!!!
    //		x		= 4 2 1 0	  
    //	count		= 0 1 2	3
    //	slice_len	= 1	2 4	8

    int x = slice_length - 1; // -1 see the border case example
    int count = 0;
    slice_len = 1;
    for (; ;) {
        if (0 == x) {
            power_of_two = count;
            break;
        }
        x /= 2;                 // integer division
        count++;                // count up
        slice_len += slice_len; // double it
    }

    if (slice_len == wr.size() - 1 &&
        slice_len == wi.size() - 1) {
        // wr and wi are already calculated!
        return;
    }

    // create sin/cos tables
    wr.resize(slice_len + 1);
    wi.resize(slice_len + 1);

    double p = 2.0 * pi / (double)slice_len;
    double a;
    for (size_t k = 0; k < slice_len; k++) {
        a = (double)k * p;
        wr[k + 1] = +cos(a);
        wi[k + 1] = -sin(a);
    }
}

void FFT::ifft(std::vector<std::complex<double>>& cv)
{
    std::vector<double> real;
    std::vector<double> imag;

    // populate the real and imag vectors
    for (auto& c : cv) {
        real.push_back(c.real());
        imag.push_back(c.imag());
    }

    ifft(real, imag);

    // populate the complex vector
    cv.clear();
    for (size_t i = 0; i < real.size(); i++) {
        std::complex<double> c(real[i], imag[i]);
        cv.push_back(c);
    }
}

void FFT::ifft(std::vector<double>& re, std::vector<double>& im)
{
    fft(re, im, true);
    
    for (auto& v : re) {
        v /= slice_len;
    }

    for (auto& v : im) {
        v /= slice_len;
    }
}

void FFT::fft(std::vector<std::complex<double>>& cv)
{
    std::vector<double> real;
    std::vector<double> imag;

    // populate the real and imag vectors
    for (auto& c : cv) {
        real.push_back(c.real());
        imag.push_back(c.imag());
    }

    fft(real, imag, false);

    // populate the complex vector
    cv.clear();
    for (size_t i = 0; i < real.size(); i++) {
        std::complex<double> c(real[i], imag[i]);
        cv.push_back(c);
    }
}

void FFT::fft(std::vector<double>& re, std::vector<double>& im)
{
    fft(re, im, false);
}


//////////////////////////////////////////////////////////////////////////////
// private
//////////////////////////////////////////////////////////////////////////////

void FFT::fft(std::vector<double>& x, std::vector<double>& y, bool inverse_flag)
{
	if ((x.size() != y.size()) || (x.size() > slice_len)) {
		throw std::runtime_error(std::string("fft: real and imaginary vectors must be the same size"));
	}

	int n = slice_len;
	int m = power_of_two;

	// This code is using array indexing starting at 1, so add a 0 to the beginnning
	// of the vectors => C indexing to Pascal indexing
	x.insert(x.begin(), 0.0);
	y.insert(y.begin(), 0.0);

    /////  BEGIN : Second-Order Goertzel Algorithmus  ///////////////////
    double c, s, xt, yt;
    int ie, ia, n1, n2, l, j, i, k;

    // array index starts at 1 !
    n2 = n;
    for (k = 1; k <= m; k++) {
        n1 = n2;
        n2 = n2 / 2;
        ie = n / n1;
        ia = 1;
        for (j = 1; j <= n2; j++) {
            c = wr[ia];
            s = wi[ia];
            ia = ia + ie;
            for (i = j; i < n; i = i + n1) {
                l = i + n2;
                xt = x[i] - x[l];
                x[i] = x[i] + x[l];
                yt = y[i] - y[l];
                y[i] = y[i] + y[l];
                x[l] = xt * c + yt * s;
                y[l] = yt * c - xt * s;
            }
        }
    }
    // unshuffle 
    j = 1;
    n1 = n - 1;
    for (i = 1; i <= n1; i++) {
        if (i < j) {
            xt = x[j];
            x[j] = x[i];
            x[i] = xt;
            xt = y[j];
            y[j] = y[i];
            y[i] = xt;
        }
        k = n / 2;
        while (k < j) {
            j = j - k;
            k = k / 2;
        }
        j = j + k;
    }

    //////  END : Second-Order Goertzel Algorithmus  ///////////////////

    // reverse from element 2 to n if regular fft is called
    if (!inverse_flag) {
        std::reverse(x.begin() + 2, x.end());
        std::reverse(y.begin() + 2, y.end());
    }

    // Revert back from 1 based Pascal indexing to 0 based C indexing
    x.erase(x.begin());
    y.erase(y.begin());
}