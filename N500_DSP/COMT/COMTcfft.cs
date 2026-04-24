using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buchi.Core.Math
{
    /// <summary>
    /// Fast Fourier Transformation
    /// 
    /// bei Initialisierung werden sin und cos Tabellen angelegt für bessere Performance.
    /// 
    /// </summary>
    public class CCOFFT // ClassCOreFFT
    {
        /// <summary>
        /// Länge der FFT z.B. 1024
        /// </summary>
        int m_SliceLen;
        public int SliceLen
        {
            get
            {
                return m_SliceLen;
            }
            // set: read only
        }

        /// <summary>
        /// FFT Länge als Power of 2, z.B. 10 bei SliceLen 1024
        /// </summary>
        int m_PowerOfTwo;
        public int PowerOfTwo
        {
            get
            {
                return m_PowerOfTwo;
            }
            // set: read only
        }

        /// <summary>
        /// Winkel Realteil,     +cos() Tabelle
        /// </summary>
        static CCOVector wr = new CCOVector(0);     // wr und wi sind Membervariablen ! zwecks Überprüfbarkeit des Algorithmus so belassen (kein m_wr)

        /// <summary>
        /// Winkel Imaginärteil, -sin() Tabelle
        /// </summary>
        static CCOVector wi = new CCOVector(0);     // wr und wi sind Membervariablen ! zwecks Überprüfbarkeit des Algorithmus so belassen (kein m_wr)

        /// <summary>
        /// Inverse FFT (analog MATLAB ifft), real and imag are scaled with number of datapoints
        /// </summary>
        /// <param name="cv">complex vector</param>
        public void Ifft(ref CCOComplexVector cv)
        {
            CCOVector l_Real = cv.Real;
            CCOVector l_Imag = cv.Imag;

            Ifft(ref l_Real, ref l_Imag);
            cv.Real = l_Real;
            cv.Imag = l_Imag;
        }

        /// <summary>
        /// Inverse FFT (analog MATLAB ifft), real and imag are scaled with number of datapoints
        /// </summary>
        /// <param name="Real"></param>
        /// <param name="Imag"></param>
        public void Ifft(ref CCOVector p_Real, ref CCOVector p_Imag)
        {
            Fft(p_Real, p_Imag, true);
            p_Real /= m_SliceLen;
            p_Imag /= m_SliceLen;
        }

        /// <summary>
        /// Complex FFT, analog MATLAB fft                 
        /// </summary>
        /// <param name="cv">complex vector</param>
        public void Fft(CCOComplexVector cv)
        {
            Fft(cv.Real, cv.Imag, false);
        }

        /// <summary>
        /// Complex FFT, analog MATLAB fft  
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        public void Fft(CCOVector Real, CCOVector Imag)
        {
            Fft(Real, Imag, false);
        }

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
        ///   Q u e l l e :                          
        ///      Second-Order Goertzel Algorithmus   
        ///      DFT/FFT and Convolution Algorythms
        ///       Theorie and Implementation
        ///       C.S.Burrus and T.W.Parks
        ///       Rice University
        ///       John Wiley & Sons                  
        /// </summary>
        /// <param name="x">real</param>
        /// <param name="y">imag</param>
        /// <param name="p_InverseFlag">True if ifft is called</param>
        private void Fft(CCOVector x, CCOVector y, bool p_InverseFlag)
        {
            if (!(x.Length == y.Length) || !(x.Length <= m_SliceLen))
            {
                throw new ArgumentException("real and imag vector must be the same size");
            }
            int n = m_SliceLen;
            int m = m_PowerOfTwo;

            /*
					x.Extend(n + 1);  			// auf FFT Länge anpassen, für 1-Indexierter Vektor muss ums eins verlängert werden..
					y.Extend(n + 1); 
					x.ShiftRight(1);			// ..und dann eins nach rechts geschoben werden
					y.ShiftRight(1);
			*/
            x.IndexingCToPascal();
            y.IndexingCToPascal();

            /////  BEGIN : Second-Order Goertzel Algorithmus  ///////////////////
            double c, s, xt, yt;
            int ie, ia, n1, n2, l, j, i, k;

            // 1-Indexiert !
            n2 = n;
            for (k = 1; k <= m; k++)
            {
                n1 = n2;
                n2 = n2 / 2;
                ie = n / n1;
                ia = 1;
                for (j = 1; j <= n2; j++)
                {
                    c = wr[ia];
                    s = wi[ia];
                    ia = ia + ie;
                    for (i = j; i < n; i = i + n1)
                    {
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
            for (i = 1; i <= n1; i++)
            {
                if (i < j)
                {
                    xt = x[j];
                    x[j] = x[i];
                    x[i] = xt;
                    xt = y[j];
                    y[j] = y[i];
                    y[i] = xt;
                }
                k = n / 2;
                while (k < j)
                {
                    j = j - k;
                    k = k / 2;
                }
                j = j + k;
            }

            //////  END : Second-Order Goertzel Algorithmus  ///////////////////

            // reverse from element 2 to n if regular fft is called
            if (!p_InverseFlag)
            {
                Array.Reverse(x.el, 2, m_SliceLen - 1);
                Array.Reverse(y.el, 2, m_SliceLen - 1);
            }
            x.IndexingPascalToC();
            y.IndexingPascalToC();
        }


        /// <summary>
        /// Init der FFT
        /// legt sin/cos Tabelle an.
        /// </summary>
        public void Init(int SliceLen)
        {
            const int MAX_SLICE_LEN = 2147483647;   // (2^32)/2-1
            if (!(SliceLen > 2 && SliceLen < MAX_SLICE_LEN))
            {
                throw new ArgumentException("SliceLen not ok");
            }

            // m_PowerOfTwo aus SliceLen bestimmen und m_SliceLen auf nächste passende 2-er Potenz setzten.
            // 
            //	Berechnungs Beispiel 1:
            //
            //	SLiceLen	= 500
            //		x		= 500	250	125	  62   31   15   7   3    1    0  
            //	count		=   0	  1	  2	   3	4    5   6   7    8    9
            //	m_SLiceLen	=	1	  2   4    8   16   32  64 128  256  512 = 2^9 = 2^count
            //
            //
            //	Berechnungs Beispiel 2: (Grenzfall)
            //
            //	SLiceLen	= 4			 ==> Bug aus 2er Potenz wird nächst höhere 2er Potenz ! ==> DARUM x = SLiceLen - 1 !!!!!
            //		x		= 4 2 1 0	  
            //	count		= 0 1 2	3
            //	m_SLiceLen	= 1	2 4	8
            //

            int x = SliceLen - 1; // -1 siehe Beispiel Grenzfall
            int count = 0;
            m_SliceLen = 1;
            for (; ; )
            {
                if (0 == x)
                {
                    m_PowerOfTwo = count;
                    break;
                }
                x /= 2;                 // integer Division
                count++;                // hochzählen
                m_SliceLen += m_SliceLen;   // verdoppeln
            }

            if (m_SliceLen == wr.Length - 1 &&
                m_SliceLen == wi.Length - 1)
            {
                // wr und wi sind schon berechnet ! 
                return;
            }

            // sin/cos Tabelle erzeugen.
            wr.Init(m_SliceLen + 1);
            wi.Init(m_SliceLen + 1);
            double p = 2.0 * System.Math.PI / (double)m_SliceLen;
            double a;
            for (int k = 0; k < m_SliceLen; k++)
            {
                a = (double)k * p;
                wr[k + 1] = +System.Math.Cos(a);
                wi[k + 1] = -System.Math.Sin(a);
            }
            return;
        }

        /// <summary>
        /// Skaliert mit Anzahl Datenpunkten der FFT
        /// </summary>
        public void Scale(ref CCOComplexVector cv)
        {
            cv.Real /= m_SliceLen;
            cv.Imag /= m_SliceLen;
        }

        /// <summary>
        /// fftshift 
        /// Vertauschen der linken und rechten Vektorhälften
        /// </summary>
        /// <param name="re">real</param>
        /// <param name="im">imag</param>
        public void Fftshift(CCOComplexVector cv)
        {
            cv.Real = cv.Real.Flip();
            cv.Imag = cv.Imag.Flip();
        }


        public enum WeightingFunctions
        {
            None = 0,                   /* 0 No Window (Box-Car, Rectangle)							*/
            Hamming = 1,                /* 1 Hamming (Happ-Genzel)		(wie in BCAP-Nirvis-FFT)	*/
            Hanning = 2,                /* 2 Hanning (cosine)										*/
            BlackManHarris3Term = 3,    /* 3 Blackman-Harris 3 Term									*/
            BlackManHarris4Term = 4,    /* 4 Blackman-Harris 4 Term									*/
            Bartlett = 5,               /* 5 Bartlet (triangle)										*/
            /*0-5 fix zugewiesen für NIRCal 4.21 Kompatibilität	--------*/
            Blackman,               /* 6 Blackman												*/
            BlackmanExact,          /* 7 BlackmanExact											*/
            Forman
        };              /* 8 Forman													*/



        /*
         * 	if( WeightingID == FFT_WEIGHTING_FUNC_NONE ) return TRUE;	// nichts zu tun !

            int i;
            const int LEN = vec.Length();
            double t;
            const double T = double(LEN);
            double scale;

            switch(WeightingID)
            {












            default : 
                TRACE("Error : CFFT::Weighting : no valid WeightingID %d\n", WeightingID);
        //		ASSERT( FALSE );
                return FALSE;
            }
            return TRUE;
        }
         * */

        /// <summary>
        /// Scales Vector vec with the selected Weighting Function.
        /// </summary>
        /// <param name="vec">vector to process</param>
        /// <param name="WeightingID">WeightingFunctions</param>
        public void Weighting(CCOVector vec, WeightingFunctions WeightingID)
        {
            // folgende Konstanten machen die Formeln lesbarer zum validieren
            const double PI = System.Math.PI;
            /*const*/
            int LEN = vec.Length;
            /*const*/
            double T = (double)LEN;     // "Perioden Dauer"

            int i;
            double t, scale;

            switch (WeightingID)
            {
                case WeightingFunctions.None:
                    // nothing todo
                    break;

                // Hamming (Happ-Genzel) (wie in BCAP-Nirvis-FFT)
                case WeightingFunctions.Hamming:
                    for (i = 0; i < LEN; i++)
                    {
                        t = (double)(i) - 0.5 * T;
                        scale = 0.54 + 0.46 * System.Math.Cos(PI * t / (T / 2));
                        vec[i] *= scale;
                    }
                    break;

                // Hanning (cosine)
                case WeightingFunctions.Hanning:
                    for (i = 0; i < LEN; i++)
                    {
                        t = (double)(i) - 0.5 * T;
                        // The Fast Fourier Transform and its Application, E. Oran Brigham, p.182
                        scale = 0.5 * (1.0 + System.Math.Cos(2.0 * PI * t / (T / 2)));
                        vec[i] *= scale;
                    }
                    break;


                // Blackman-Harris 3 Term
                case WeightingFunctions.BlackManHarris3Term:
                    for (i = 0; i < LEN; i++)
                    {
                        t = (double)(i) - 0.5 * T;
                        // Applied Spectroscopy Volume 43, Number 4, 1989
                        // Datenverarbeitung ind der FT-IR Spektroskopie, Jörn Gornholz, Werner Herres
                        scale = 0.42323 + 0.49755 * System.Math.Cos(PI * t / (T / 2)) + 0.07922 * System.Math.Cos(2 * PI * t / (T / 2));
                        vec[i] *= scale;
                    }
                    break;

                // Blackman-Harris 4 Term
                case WeightingFunctions.BlackManHarris4Term:
                    for (i = 0; i < LEN; i++)
                    {
                        t = (double)(i) - 0.5 * T;
                        // Datenverarbeitung ind der FT-IR Spektroskopie, Jörn Gornholz, Werner Herres
                        scale = 0.35875 + 0.48829 * System.Math.Cos(PI * t / (T / 2)) + 0.14128 * System.Math.Cos(2 * PI * t / (T / 2)) + 0.01168 * System.Math.Cos(3 * PI * t / (T / 2));
                        // Applied Spectroscopy Volume 43, Number 4, 1989 <-- hat Fehler drin !!!!
                        // scale = 0.35875 + 0.48829*cos(PI*t/T) + 0.14128*cos(2*PI*t/T) + 0.1168*cos(3*PI*t/T);	
                        vec[i] *= scale;
                    }
                    break;


                // Bartlet (triangle)
                case WeightingFunctions.Bartlett:
                    for (i = 0; i < LEN; i++)
                    {
                        t = (double)(i) - 0.5 * T;
                        // The Fast Fourier Transform and its Application, E. Oran Brigham, p.182
                        scale = 1.0 - (2.0 * System.Math.Abs(t) / T);
                        vec[i] *= scale;
                    }
                    break;

                // Blackman
                case WeightingFunctions.Blackman:
                    for (i = 0; i < LEN; i++)
                    {
                        t = (double)(i) - 0.5 * T;
                        scale = 0.42 + 0.5 * System.Math.Cos(PI * t / (T / 2)) + 0.08 * System.Math.Cos(2.0 * PI * t / (T / 2));
                        vec[i] *= scale;
                    }
                    break;

                // Blackman Exact
                case WeightingFunctions.BlackmanExact:
                    for (i = 0; i < LEN; i++)
                    {
                        t = (double)(i) - 0.5 * T;
                        scale = 0.42659071 + 0.49656062 * System.Math.Cos(PI * t / (T / 2)) + 0.07684867 * System.Math.Cos(2.0 * PI * t / (T / 2));
                        vec[i] *= scale;
                    }
                    break;

                // Forman
                case WeightingFunctions.Forman:
                    // apod=(1-(apod.^2)).^2;
                    for (i = 0; i < LEN; i++)
                    {
                        t = (double)(i) - 0.5 * T;
                        scale = System.Math.Pow(1.0 - System.Math.Pow(t / (T / 2), 2), 2);
                        vec[i] *= scale;
                    }
                    break;

                default:
                    Trace.Assert(false, "Unknown FFT Weighting Function ID");
                    break;
            }
        }

        /// <summary>
        /// Does the zero filling of a curve, used for smoothing. The new vector will be bigger
        /// old vector length: n
        /// new vector length: n * p_iFactor
        /// 
        /// This method returns the same result as the MATLAB code:
        /// 
        /// lzi=(nzf-1)*pwinsize;
        /// yy=nzf * real(ifft(fftshift([zeros(lzi/2);fftshift(fft(pwin));zeros(lzi/2)])));
        /// </summary>
        /// <param name="p_Vector">Apply zero filling to this vector points</param>
        /// <param name="p_Factor">Zero fill factor</param>
        /// <returns></returns>
        public CCOVector ZeroFilling(CCOVector p_Vector, int p_iFactor)
        {
            Debug.Assert(p_Vector.Length > 0);
            Debug.Assert(p_iFactor > 1);

            if (p_iFactor > 1)
            {
                // fft and fftshift
                int l_iWinSize = p_Vector.Length;
                CCOComplexVector l_CxVector = new CCOComplexVector(p_Vector);
                CCOFFT l_FFT = new CCOFFT();
                l_FFT.Init(l_iWinSize);
                Debug.Assert(p_Vector.Length == l_FFT.SliceLen, "InputVector must have a length which is a power of 2!!" +
                    Environment.NewLine + p_Vector.Length.ToString() + " != " + l_FFT.SliceLen.ToString());
                l_FFT.Fft(l_CxVector);
                l_FFT.Fftshift(l_CxVector);

                // add zeros to left and right side of window and do zerofilling
                int l_iZeroSize = l_iWinSize * (p_iFactor - 1);
                CCOVector l_Zeros = new CCOVector(l_iZeroSize / 2);
                CCOVector[] l_RealArray = { l_Zeros, l_CxVector.Real, l_Zeros };
                CCOVector[] l_ImagArray = { l_Zeros, l_CxVector.Imag, l_Zeros };
                CCOVector l_RealFilled = new CCOVector(l_RealArray);
                CCOVector l_ImagFilled = new CCOVector(l_ImagArray);
                CCOComplexVector l_CxFilled = new CCOComplexVector(l_RealFilled, l_ImagFilled);
                l_FFT.Init(l_iZeroSize + l_iWinSize);
                l_FFT.Fftshift(l_CxFilled);
                l_FFT.Ifft(ref l_CxFilled);

                return l_CxFilled.Real * p_iFactor;
            }
            else
            {
                return new CCOVector(p_Vector);   // copy vector
            }
        }


        /// <summary>
        /// Does the zero filling of a curve, used for peak fitting. 
        /// The p_Vector is treated in symmetric way to avoid discontiouities.
        /// This allows this routine to be used with spectra data.
        /// The new vector will be bigger.
        /// 
        /// old vector length: n, any size is possible !
        /// new vector length: p_iFactor*(n-1)+1	(no extrapolation, that's why is not p_iFactor*n )
        /// </summary>
        /// <remarks>
        /// This method is similar to MATLAB's INTERPFT 1-D interpolation using FFT method. (interpft.m)
        /// 
        /// MATLAB Code:  zfspectrum.m
        ///	function zs = zfspectrum(spectrum,zf)				%zfspectrum(spectrum,zf) interpolates the vector spectrum using zf-times zerofilling.
        ///	n=length(spectrum);
        ///	m=2^ceil(log2(n));									%next power of 2
        ///	s=[spectrum;spectrum(n)*ones(m-n,1)];				%fill to next power of 2
        ///	s=fftshift([s;s(end:-1:1)]);						%make symmetric to avoid discontiouities
        ///	a = fft(s);
        ///	b = [a(1:m);zeros((zf-1)*2*m,1);a(m+1:(end))];      %insert zeros and remove asymmety
        ///	b(m+1,:) = b(m+1,:)/2;								% nyquist half
        /// b(m+1 +(zf-1)*2*m,:) = b(m+1,:);
        ///	y = fftshift(zf*real(ifft(b)));						%only real part contains information
        ///	y = y(1:(1+zf*(n-1)));								%first half contains all the info
        ///	zs=y;
        ///	</remarks>
        /// <param name="p_Vector">Apply symmetric zero filling to this vector points</param>
        /// <param name="p_Factor">Zero fill factor</param>
        /// <returns></returns>
        public CCOVector ZeroFillingSymmetric(CCOVector p_Vector, int p_iFactor)
        {
            Debug.Assert(p_Vector.Length > 0);
            Debug.Assert(p_iFactor > 1);
            if (p_iFactor > 1)                                  // p_iFactor = zf = 8
            {
                // m=2^ceil(log2(n));							// m = next power of 2 = 2048
                // m=2^ceil(log2(n)+0.5);	<== +0.5 damit es auch mit 2er Potenzen funktioniert
                int n = p_Vector.Length;                        // n = 1557 = l_iWinSize
                int m = (int)System.Math.Pow(2.0, System.Math.Ceiling(System.Math.Log((double)n, 2.0) + 0.5));

                // Fill
                CCOVector Filler = new CCOVector(m - n);
                Filler.FillSelection(0, Filler.Length, p_Vector[n - 1]); // Filler is to keep the last value of the p_Vector constant, to to avoid discontiouities
                CCOVector[] Concatinate = { p_Vector, Filler };
                CCOVector s = new CCOVector(Concatinate);       // 2048

                // Reverse
                CCOVector sReverse = new CCOVector(m);      // reverse
                sReverse = s.Reverse();

                // Symmetry
                CCOVector[] Concatinate2 = { s, sReverse };     // 4096 = 2*m
                CCOVector ss = new CCOVector(Concatinate2); // make symmetric to avoid discontiouities

                CCOVector imag = new CCOVector(2 * m);          // imag = 0
                CCOComplexVector a = new CCOComplexVector(ss, imag);

                CCOFFT l_FFT = new CCOFFT();
                l_FFT.Init(2 * m);                              // 4096 = 2*m
                l_FFT.Fftshift(a);
                l_FFT.Fft(a);                                   // a ; 4096 = 2*m

                // insert zeros and remove asymmetry in complex domain
                // %b = [ a(1:m) ;  zeros((zf-1)*2*m,1); a(m+1:(end)) ];		// [ m ; (zf-1)*2*m ; m ] : total length = 2*m*zf = 32768
                /* // zfspectrum2.m Version2
				CCOVector aLowerReal = a.Real.GetSlice( 0,m );
				CCOVector aLowerImag = a.Imag.GetSlice( 0,m ); 
				CCOVector aUpperReal = a.Real.GetSlice( m,m );
				CCOVector aUpperImag = a.Imag.GetSlice( m,m ); 
				 */
                //  b = [a(1:(m+1));zeros((zf-1)*2*m,1);a((m+2):(end))];		//<== zfspectrum3.m ! neuste Version, ergibt bei Testdaten, das selbe ergebnis wie Version2
                CCOVector zeros = new CCOVector((p_iFactor - 1) * 2 * m);   // p_iFactor = zf
                CCOVector aLowerReal = a.Real.GetSlice(0, m + 1);
                CCOVector aLowerImag = a.Imag.GetSlice(0, m + 1);
                CCOVector aUpperReal = a.Real.GetSlice(m + 1, m - 1);
                CCOVector aUpperImag = a.Imag.GetSlice(m + 1, m - 1);

                CCOVector[] aReals = { aLowerReal, zeros, aUpperReal };
                CCOVector[] aImags = { aLowerImag, zeros, aUpperImag };
                CCOVector aReal = new CCOVector(aReals);
                CCOVector aImag = new CCOVector(aImags);
                CCOComplexVector b = new CCOComplexVector(aReal, aImag);

                // b(m+1,:) = b(m+1,:)/2;						// nyquist half
                b.Real[m] /= 2.0;
                b.Imag[m] /= 2.0;

                // b(m+1 +(zf-1)*2*m,:) = b(m+1,:);
                b.Real[m + (p_iFactor - 1) * 2 * m] = b.Real[m];
                b.Imag[m + (p_iFactor - 1) * 2 * m] = b.Imag[m];

                //	y = fftshift(zf*real(ifft(b)));				// only real part contains information
                CCOFFT l_FFTbig = new CCOFFT();
                l_FFTbig.Init(2 * m * p_iFactor);                   // 2*m*zf = 32768
                l_FFTbig.Ifft(ref b);
                l_FFTbig.Fftshift(b);

                //	y = y(1:(1+zf*(n-1)));						// first half contains all the info
                return b.Real.GetSlice(0, 1 + p_iFactor * (n - 1)) * (double)p_iFactor;
            }
            else
            {
                return new CCOVector(p_Vector);                 // copy vector
            }
        }

    }
}
