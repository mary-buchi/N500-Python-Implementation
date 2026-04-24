using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buchi.Core.Math
{
    /// <summary>
    /// Vector Operation based on doubles
    /// 
    /// </summary>

    //	internal class CCOVector
    [Serializable()]
    public class CCOVector // : CDBPersistenceClass
    {
        #region data member

        /// <summary>
        /// constant for an empty vector. If a vector must be returned in a failure case.
        /// </summary>
        public static readonly CCOVector EMPTY_VECTOR = new CCOVector();

        /// <summary>
        /// number of double elements in use
        /// </summary>
        public static long ElementsInUse = 0;

        /// <summary>
        /// maximal double elements during use. max memory peak.
        /// </summary>
        public static long ElementsInUseMaxPeak = 0;

        /// <summary>
        /// approximative Floating Point Operation counter.
        /// </summary>
        public static long Flops = 0;

        /// <summary>
        /// vector elements as double array
        /// </summary>
        internal double[] el;               // internal (friend)

        /// <summary>
        /// The length of the Vector. Number of Vector elements.
        /// </summary>
        int len;
        /// <summary>
        /// Get the Vector length, number of elements
        /// </summary>
        public int Length
        {
            get { return len; }
            // set : read only because of resizing -> use SetSize / Extend / Shrink
        }
        #endregion

        #region constants

        private const double m_Select = 1.0;
        private const double m_Deselect = 0.0;

        #endregion

        #region methods
        /// <summary>
        /// default constructor
        /// </summary>
        public CCOVector()
        {
            len = 0;
            el = null;
        }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="p_Elements">These array elements will be used by the vector</param>
        public CCOVector(double[] p_Elements)
        {
            len = p_Elements.Length;
            el = p_Elements;
            ElementsInUse += len;
            // measure max peak
            ElementsInUseMaxPeak = System.Math.Max(ElementsInUseMaxPeak, ElementsInUse);
        }

        /// <summary>
        /// Constructor builds a vector from a vector array. All vectors will be appended
        /// in sequence to the new built vector.
        /// </summary>
        /// <param name="p_Right">Build new vector from this array</param>
        public CCOVector(CCOVector[] p_Right)
        {
            Debug.Assert(p_Right != null);
            int LengthSum = 0;

            // get length sum of all vectors
            for (int i = 0; i < p_Right.Length; i++)
            {
                LengthSum += p_Right[i].Length;
            }

            // build new vector and append all vectors from array
            Init(LengthSum);
            int Offset = 0;

            for (int i = 0; i < p_Right.Length; i++)
            {
                if (p_Right[i].Length != 0)
                {
                    Array.Copy(p_Right[i].GetNativeBuffer(), 0, el, Offset, p_Right[i].Length);
                    Offset += p_Right[i].Length;
                }
            }
        }

        /// <summary>
        /// Constructor builds a vector from a 24 bit stream 
        /// </summary>
        /// <param name="p_24BitByteStream"></param>
        public CCOVector(byte[] p_24BitByteStream)
        {
            Trace.Assert(p_24BitByteStream.Length > 0, "Bad length");

            len = (int)(p_24BitByteStream.Length / 3);

            if (len > 0)
            {
                el = new double[len];
                uint l_Value;
                for (int l_Cnt = 0; l_Cnt < len; l_Cnt++)
                {
                    l_Value = ((uint)p_24BitByteStream[l_Cnt * 3 + 2]) << 16 |
                        ((uint)p_24BitByteStream[l_Cnt * 3 + 1]) << 8 |
                        (uint)p_24BitByteStream[l_Cnt * 3];

                    // check for negative values
                    if ((p_24BitByteStream[l_Cnt * 3 + 2] & 0x80) != 0)    // most significant bit is set
                        l_Value |= 0xFF000000;

                    int l_iValue = (int)l_Value;
                    el[l_Cnt] = (double)l_iValue;
                }
            }
        }

        /// <summary>
        /// Destruktor
        /// </summary>
        ~CCOVector()
        {
            ElementsInUse -= len;
        }

        /// <summary>
        /// Releases the vector
        /// </summary>
        public void Release()
        {
            len = 0;
            el = null;
        }

        /// <summary>
        /// copy constructor
        /// </summary>
        /// <param name="X"></param>
        public CCOVector(CCOVector x)
        {
            Init(x.len);
            x.el.CopyTo(el, 0);
        }


        /// <summary>
        /// CopyTo
        /// use this instead of = operator
        /// </summary>
        /// <param name="x">x will be resized</param>
        public void CopyTo(CCOVector x)
        {
            if (x.Equals(this))
            {
                Trace.Assert(false, "copy to itself, seems to be a coding mistake!");
                return;
            }
            x.Init(len);
            el.CopyTo(x.el, 0);
        }

        /// <summary>
        /// size init constructor
        /// </summary>
        /// <param name="n"></param>
        public CCOVector(int n)
        {
            Init(n);
        }

        /// <summary>
        /// Initiate the vector with the given size
        /// </summary>
        /// <param name="p_Vector">a double []</param>
        /// <returns>always true</returns>
        public bool Init(double[] p_Vector)
        {
            if (p_Vector.Length > 0)
            {
                len = p_Vector.Length;
                el = p_Vector;
                ElementsInUse += len;
                // measure max peak
                ElementsInUseMaxPeak = System.Math.Max(ElementsInUseMaxPeak, ElementsInUse);
            }
            else
            {
                Release();
            }
            return true;
        }

        /// <summary>
        /// Initiate the vector with the given size
        /// </summary>
        /// <param name="n">size</param>
        /// <returns></returns>
        public bool Init(int n)
        {
            if (n > 0)
            {
                len = n;
                el = new double[n];
                ElementsInUse += n;
                // measure max peak
                ElementsInUseMaxPeak = System.Math.Max(ElementsInUseMaxPeak, ElementsInUse);
            }
            else
            {
                Release();
            }
            return true;
        }

        public void Init()
        {
            Release();
        }

        /// <summary>
        /// Returns the Vector in text form.
        /// </summary>
        /// <returns></returns>
        public override String ToString()
        {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < len; i++)
            {
                builder.Append(el[i] + " ");
            }
            return builder.ToString();
        }



        /// <summary>
        /// index operator
        /// </summary>
        public double this[int i]
        {
            get
            {
                //				Trace.Assert(i < len);
                //				Trace.Assert(i >= 0);
                return el[i];
            }
            set
            {
                //				Trace.Assert(i < len);
                //				Trace.Assert(i >= 0);
                el[i] = value;
            }
        }


        /// <summary>
        /// Redim the Vector to an new size.
        /// </summary>
        /// <seealso cref="Shrink"/>
        /// <seealso cref="Extend"/>
        /// <param name="n">new size</param>
        /// <returns></returns>
        public bool Resize(int n)
        {
            if (n == len)
            {
                return true;
            }
            else if (n < len)
            {
                return Shrink(n);
            }
            else
            {
                return Extend(n);
            }
        }

        /// <summary>
        /// Shrinks the Vector to size n.
        /// To entend the Vector use Extend or SetSize.
        /// Elements above n will be cutted away.
        /// </summary>
        /// <seealso cref="Extend"/>
        /// <seealso cref="SetSize"/>
        /// <param name="n"></param>
        /// <returns></returns>
        private bool Shrink(int n)
        {
            if (n == len) { return true; }
            if (n < 0 || n > len)
            {
                Trace.Assert(false, "CCOVector can not be Shrinked to the given value");
                return false;
            }
            ElementsInUse -= (len - n);                     // reduce by shrink size

            // create new buffer
            double[] Shrinked = new double[n];

            for (int i = 0; i < n; i++)                     // copy the kept part
            {
                Shrinked[i] = el[i];
            }

            // delete old buffer
            el = null;
            len = 0;

            // this reconstruction
            len = n;
            el = Shrinked;
            return true;
        }


        /// <summary>
        /// Extends the Vector to size n.
        /// To shorten the Vector use Shrink or SetSize.
        /// New elements are filled with 0.0
        /// </summary>		
        /// <seealso cref="Shrink"/>
        /// <seealso cref="SetSize"/>
        /// <param name="?">the new Vector length</param>
        private bool Extend(int n)
        {
            if (n == len) { return true; }
            if (n < 0 || n < len)
            {
                Trace.Assert(false, "CCOVector can not be Extended to the given value");
                return false;
            }
            ElementsInUse += (n - len);                     // increase by extended size

            // create new buffer
            double[] Data = new double[n];
            el.CopyTo(Data, 0);

            // delete old buffer
            el = null;

            // this reconstruction
            len = n;
            el = Data;
            return true;
        }





        /// <summary>
        /// Compares two Vectors of equality.
        /// Incompatible size will return false.
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>true / false : Vector are identical in size and value</returns>
        public static bool operator ==(CCOVector L, CCOVector R)
        {
            if (ReferenceEquals(L, R))
            {
                return true;
            }
            else if (ReferenceEquals(L, null) || ReferenceEquals(R, null))
            {
                return false;
            }
            else if ((L.len != R.len))                      // compatible size?
            {
                return false;                                   // Vectors are not equal in size
            }
            for (int i = 0; i < L.len; i++)
            {
                if (L.el[i] != R.el[i])
                {
                    return false;                               // Vectors are not equal in at least one value
                }
            }
            return true;                                        // Vectors are identical
        }

        /// <summary>
        /// Compares two Vectors of NOT equality.
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>true / false : Vectors are NOT identical in size and value</returns>
        public static bool operator !=(CCOVector L, CCOVector R)
        {
            return !(L == R);                                   // Vectors are not identical
        }


        /// <summary>
        /// Equals / ==
        /// Followa the contract defined on the Object.Equals Method.
        /// </summary>
        /// <param name="obj">any object</param>
        /// <returns>true, if object member data are equal</returns>
        public override bool Equals(object obj)
        {
            // Follow the contract defined on the Object.Equals Method 
            if ((obj == null) || (GetType() != obj.GetType())) { return false; }
            return (this == (CCOVector)obj);
        }

        /// <summary>
        /// GetHashCode
        /// </summary>
        /// <returns></returns>
        public override int GetHashCode()
        {
            return len;                             // a simple Hash
        }


        /// <summary>
        /// Vector addition. 
        /// Vectors must have the same size.
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>X = L + R</returns>
        public static CCOVector operator +(CCOVector L, CCOVector R)
        {
            if (L.len != R.len) throw new ArgumentException("Vector dimensions are not in same size.");
            CCOVector X = new CCOVector(L.len);
            for (int i = 0; i < L.len; i++)
            {
                //X[i] = L[i] + R[i];				// acces via [] operator
                X.el[i] = L.el[i] + R.el[i];        // direct acces for faster code
            }
            Flops += L.len;
            return X;
        }


        /// <summary>
        /// Vector subtraction. 
        /// Vectors must have the same size.
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>X = L - R</returns>
        public static CCOVector operator -(CCOVector L, CCOVector R)
        {
            if (L.len != R.len) throw new ArgumentException("Vector dimensions are not in same size.");
            CCOVector X = new CCOVector(L.len);
            for (int i = 0; i < L.len; i++)
            {
                //X[i] = L[i] - R[i];				// acces via [] operator
                X.el[i] = L.el[i] - R.el[i];        // direct acces for faster code
            }
            Flops += L.len;
            return X;
        }

        /// <summary>
        /// Subtract from the given scalar d each vector element
        /// </summary>
        /// <param name="d">Scalar subtractor</param>
        /// <param name="vec">Vector</param>
        /// <returns></returns>
        public static CCOVector operator -(double d, CCOVector vec)
        {
            CCOVector X = new CCOVector(vec.len);

            for (int i = 0; i < vec.Length; i++)
            {
                X.el[i] = d - vec.el[i];
            }
            Flops += vec.Length;

            return X;
        }

        /// <summary>
        /// Vector element by element Multiplication. 
        /// Vectors must have the same size.
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>X = L * R</returns>
        public static CCOVector operator *(CCOVector L, CCOVector R)
        {
            if (L.len != R.len) throw new ArgumentException("Vector dimensions are not in same size.");
            CCOVector X = new CCOVector(L.len);
            for (int i = 0; i < L.len; i++)
            {
                X.el[i] = L.el[i] * R.el[i];        // direct acces for faster code
            }
            Flops += L.len;
            return X;
        }


        /// <summary>
        /// Vector element by element Division. 
        /// Vectors must have the same size.
        /// Division by zero : caugth by defalt Math exception
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>X = L / R</returns>
        public static CCOVector operator /(CCOVector L, CCOVector R)
        {
            if (L.len != R.len) throw new ArgumentException("Vector dimensions are not in same size.");
            CCOVector X = new CCOVector(L.len);
            for (int i = 0; i < L.len; i++)
            {   // division by zero : caugth by defalt Math exception
                X.el[i] = L.el[i] / R.el[i];        // direct acces for faster code
            }
            Flops += L.len;
            return X;
        }




        /// <summary>
        /// Divide each Vector element by the given scalar d
        /// </summary>
        /// <param name="vec"></param>
        /// <param name="d">scalar divisor</param>
        /// <returns></returns>
        public static CCOVector operator /(CCOVector vec, double d)
        {
            if (d == 0.0) throw new ArgumentException("Division by zero is not allowed");
            CCOVector X = new CCOVector(vec.len);
            for (int i = 0; i < vec.len; i++)
            {
                X.el[i] = vec.el[i] / d;
            }
            Flops += vec.len;
            return X;
        }


        /// <summary>
        /// Multiply each Vector element by the given scalar d
        /// </summary>
        /// <param name="vec"></param>
        /// <param name="d">scalar multiplier</param>
        /// <returns></returns>
        public static CCOVector operator *(CCOVector vec, double d)
        {
            CCOVector X = new CCOVector(vec.len);
            for (int i = 0; i < vec.len; i++)
            {
                X.el[i] = vec.el[i] * d;
            }
            Flops += vec.len;
            return X;
        }

        /// <summary>
        /// Addition to each Vector element the given scalar d
        /// </summary>
        /// <param name="vec"></param>
        /// <param name="d">scalar additive</param>
        /// <returns></returns>
        public static CCOVector operator +(CCOVector vec, double d)
        {
            CCOVector X = new CCOVector(vec.len);
            for (int i = 0; i < vec.len; i++)
            {
                X.el[i] = vec.el[i] + d;
            }
            Flops += vec.len;
            return X;
        }

        /// <summary>
        /// Subtract to each Vector element the given scalar d
        /// </summary>
        /// <param name="vec"></param>
        /// <param name="d">scalar subtractor</param>
        /// <returns></returns>
        public static CCOVector operator -(CCOVector vec, double d)
        {
            CCOVector X = new CCOVector(vec.len);
            for (int i = 0; i < vec.len; i++)
            {
                X.el[i] = vec.el[i] - d;
            }
            Flops += vec.len;
            return X;
        }

        /// <summary>
        /// Multiplicates each vector element local with the given scalar d
        /// </summary>
        public void Mult(double d)
        {
            for (int i = 0; i < len; i++)
            {
                el[i] = el[i] * d;
            }
            Flops += len;
        }

        /// <summary>
        /// Divide each vector element local with the given scalar d
        /// </summary>
        public void Div(double d)
        {
            for (int i = 0; i < len; i++)
            {
                el[i] = el[i] / d;
            }
            Flops += len;
        }

        /// <summary>
        /// Scalar product of two vectors
        /// </summary>
        /// <param name="other">second vector</param>
        /// <returns>scalar product</returns>
        public double Dot(CCOVector other)
        {
            if (this.len != other.len) throw new ArgumentException("Vector dimensions are not in same size.");
            double sum = 0.0;
            for (int i = 0; i < len; i++)
            {
                sum += el[i] * other.el[i];
            }
            Flops += len;
            return sum;
        }


        /// <summary>
        /// Shifts the Vector elements pos Positions to right.
        /// Left incoming elements are set to 0.
        /// 
        /// Value		5 6	0 2	8
        /// ShiftRight(1)
        /// 			0 5 6 0 2
        /// </summary>
        /// <param name="Pos">Positions</param>
        public void ShiftRight(int pos)
        {
            if (!(pos > 0) || !(pos < len)) throw new ArgumentException("number of positions are not in range");
            int i;
            for (i = len - 1; i >= pos; i--)
            {
                el[i] = el[i - pos];
            }
            for (i = 0; i < pos; i++)
            {
                el[i] = 0.0;
            }
        }

        /// <summary>
        /// Shifts the Vector elements pos Positions to left.
        /// Right incoming elements are set to 0.
        /// 
        /// index		0 1 2 3 4
        /// Value		5 6	0 2	8
        /// ShiftLeft(1)
        ///				6 0 2 8 0
        ///
        /// index		0 1 2 3 4
        /// Value		5 6	0 2	8
        /// ShiftLeft(3)
        ///				2 8 0 0 0
        /// </summary>
        /// <param name="Pos">Positions</param>
        public void ShiftLeft(int pos)
        {
            if (!(pos > 0) || !(pos < len)) throw new ArgumentException("number of positions are not in range");
            int i;
            for (i = 0; i < len - pos; i++)
            {
                el[i] = el[i + pos];
            }
            for (i = len - pos; i < len; i++)
            {
                el[i] = 0.0;
            }
        }

        /// <summary>
        /// Extracts a new vector from an existing vector. The slice begins at the startindex "from"
        /// (zero based) and has the wanted length.
        /// </summary>
        /// <param name="from">The zero based vector index at which the slice starts</param>
        /// <param name="length">The number of elements in the slice</param>
        /// <returns>The new vector</returns>
        public CCOVector GetSlice(int from, int length)
        {
            // test input parameters
            if (!(from >= 0) || !(from < len) || !(length > 0) || !(len - from >= length)) throw new ArgumentException("from, length are not in range");

            // build new vector
            CCOVector ret = new CCOVector(length);

            for (int i = 0; i < length; i++)
            {
                ret[i] = el[from + i];
            }
            return ret;
        }

        /// <summary>
        /// Root Mean Squared Deviation
        /// 
        ///					1  __n			2
        /// RMSD	= sqrt( -  >   (Xi - Yi)   )
        ///					n  --
        ///					   i=1
        ///	Anwendung:				   
        ///		Residual = RMSD( SpectraPretreated, ReconstructedSpectra)	
        /// </summary>
        /// <param name="x"></param>
        /// <param name="y"></param>
        /// <returns></returns>
        public double RMSD(CCOVector x, CCOVector y)
        {
            if (!(x.Length == y.Length)) throw new ArgumentException("Vector dimensions are not in same size.");
            CCOVector diff = new CCOVector();
            diff = x - y;
            double sum = System.Math.Sqrt(diff.Dot(diff) / x.Length);
            return sum;
        }

        /// <summary>
        /// Limits the vector to top. The maximum value in the vector will be <= the limit
        /// </summary>
        /// <param name="limit">The limit value</param>
        public void LimitTop(double limit)
        {
            for (int i = 0; i < el.Length; i++)
            {
                if (el[i] > limit) el[i] = limit;
            }
        }

        /// <summary>
        /// Limits the vector to bottom. The minimum value vector will be >= the limit
        /// </summary>
        /// <param name="limit">The limit value</param>
        public void LimitBottom(double limit)
        {
            for (int i = 0; i < el.Length; i++)
            {
                if (el[i] < limit) el[i] = limit;
            }
        }


        /// <summary>
        /// Linear Filter
        /// - for NIRCal Pretreatments (Derivatives, Smoothings, etc.)
        /// - special Convolution with scaling, reversed filter (NIR-News / Savitzky Goaly Notation)
        /// - output data size is equal input data size
        /// - border range (half filter length) is filled with first calculated value 
        ///   to avoid discontinuity for example following derivatives
        /// - filter vector should not be longer tahn the data vector
        /// </summary>
        /// <param name="this">data vector</param>
        /// <param name="filter">filter vector</param>
        /// <param name="scale">scale</param>
        /// <returns>Result vector has the same size as the data vector</returns>
        public CCOVector LinearFilter(CCOVector filter, double scale)
        {
            int npts = this.Length;
            int fnpts = filter.Length;
            int fnpts_half = (int)(System.Math.Ceiling((double)(fnpts - 1) / 2.0));
            CCOVector res = new CCOVector(npts);
            CCOVector filt = new CCOVector(filter);

            if (fnpts > npts)
            {
                Trace.Assert(false, "filter is longer than data vector");
                return CCOVector.EMPTY_VECTOR;
            }


            /* //vorschlag für neuen code
						// fold center range
						int Bstart = (fnpts_half);	
						int Bend   = Bstart + (npts - fnpts);	
						double sum;
						for( int n = Bstart; n <= Bend ; n++ )
						{          
							sum = 0.0;  
							for( int m=0; m <= (fnpts-1); m++ )
							{
								sum += filt[(fnpts-1)-m] * el[ m + (n-Bstart) ];
							}	
							res[n] = sum;		
						}         

						// fade beginning
						for( int n = 0; n <= (Bstart-1); n++ )
						{
							res[n] = res[Bstart];
						}

						// fade the end
						for( int n = (Bend+1); n <= (npts-1); n++ )
						{
							res[n] = res[Bend];
						}

						// scaling  
						res /= scale;
			*/


            // mittlerer Bereich berechnen
            double sum;
            for (int n = (fnpts_half + 1); n <= (npts - fnpts_half); n++)
            {
                sum = 0.0;
                for (int m = 1; m <= fnpts; m++)
                {
                    sum = sum + filt[(fnpts) - m] * el[n - fnpts_half + m - 1 - 1];
                }
                res[n - 1] = sum;
            }

            // Anfang und Ende ausglätten
            for (int n = 0; n <= fnpts_half - 1; n++)
            {
                res[n] = res[fnpts_half + 1];
                res[npts - n - 1] = res[npts - fnpts_half - 1];
            }

            // ganzer Vektor skalieren      
            res /= scale;


            Flops += npts * fnpts;  // aprox.
            return res;
        }

        /// <summary>
        /// Convolution / Linear Filter / Faltung
        /// - filter vector should not be longer tahn the data vector
        /// </summary>
        /// <param name="this">data vector</param>
        /// <param name="filter">filter vector</param>
        /// <returns>Result vector has the same size as the data vector</returns>
        public CCOVector Convolution(CCOVector filter)
        {
            int npts = this.Length;
            int fnpts = filter.Length;
            int fnpts_half = (int)(System.Math.Ceiling((double)(fnpts - 1) / 2.0));
            CCOVector res = new CCOVector(npts);
            CCOVector filt = new CCOVector(filter);

            if (fnpts > npts)
            {
                Trace.Assert(false, "filter is longer than data vector");
                return CCOVector.EMPTY_VECTOR;
            }

            // claculate center range
            double sum;
            for (int n = (fnpts_half + 1); n <= (npts - fnpts_half); n++)
            {
                sum = 0.0;
                for (int m = 1; m <= fnpts; m++)
                {
                    sum += filt.el[fnpts - m] * el[n - fnpts_half + m - 1 - 1];
                }
                res.el[n - 1] = sum;
            }
            /*
						// fade start and end part
						for( int n=0; n<=fnpts_half-1; n++ )
						{
							res[n] = res[fnpts_half + 1];
							res[npts-n-1] = res[npts - fnpts_half-1]; 
						}
			*/
            Flops += npts * fnpts;  // aprox.
            return res;
        }


        /// <summary>
        /// Get the double vector native buffer
        /// </summary>
        /// <returns>vector's native buffer double[]</returns>
        public double[] GetNativeBuffer()
        {
            return el;
        }

        /// <summary>
        /// Computes the convolution of vector A and B (A >= B).
        /// The result is the same as a convolution in MATLAB (Size = A.Length + B.Length - 1).
        /// </summary>
        /// <param name="p_VectorA">filter vector</param>
        /// <param name="p_VectorB">data vector</param>
        /// <returns>result vector</returns>
        public static CCOVector Conv(CCOVector p_VectorA, CCOVector p_VectorB)
        {
            Debug.Assert(p_VectorA.Length >= p_VectorB.Length);

            int l_iSizeA = p_VectorA.len;
            int l_iSizeB = p_VectorB.len;
            double[] l_dbVectorA = p_VectorA.GetNativeBuffer();
            double[] l_dbVectorB = p_VectorB.GetNativeBuffer();

            CCOVector l_Result = new CCOVector(l_dbVectorA.Length + l_dbVectorB.Length - 1);
            l_Result.Zero();
            double[] l_dbResult = l_Result.GetNativeBuffer();
            double l_dbSum;

            // process the first filter length separately (for performance reasons)
            int l_iACnt, l_iBCnt;
            for (l_iACnt = 0; l_iACnt < l_iSizeB; l_iACnt++)
            {
                l_dbSum = 0.0;
                for (l_iBCnt = 0; l_iBCnt < l_iSizeB; l_iBCnt++)
                {
                    if (l_iBCnt > l_iACnt)
                        break;

                    l_dbSum += l_dbVectorB[l_iBCnt] * l_dbVectorA[l_iACnt - l_iBCnt];
                }

                l_dbResult[l_iACnt] = l_dbSum;
            }

            // ok now process all minus the last filter length
            for (l_iACnt = l_iSizeB; l_iACnt < l_iSizeA; l_iACnt++)
            {
                l_dbSum = 0.0;
                for (l_iBCnt = 0; l_iBCnt < l_iSizeB; l_iBCnt++)
                {
                    l_dbSum += l_dbVectorB[l_iBCnt] * l_dbVectorA[l_iACnt - l_iBCnt];
                }

                l_dbResult[l_iACnt] = l_dbSum;
            }

            // and finally the last filter length
            for (l_iACnt = l_iSizeA; l_iACnt < l_iSizeA + l_iSizeB - 1; l_iACnt++)
            {
                l_dbSum = 0.0;
                for (l_iBCnt = 0; l_iBCnt < l_iSizeB; l_iBCnt++)
                {
                    if (l_iACnt - l_iBCnt < l_iSizeA)
                        l_dbSum += l_dbVectorB[l_iBCnt] * l_dbVectorA[l_iACnt - l_iBCnt];
                }

                l_dbResult[l_iACnt] = l_dbSum;
            }

            Flops += l_iSizeA * l_iSizeB;   // aprox.
            return l_Result;
        }



        /// <summary>
        /// Min, returns the Max value of the vector.
        /// </summary>
        /// <returns>Minimum</returns>
        public double Min()
        {
            if (len == 0) { Trace.Assert(false); return 0.0; }
            double m = el[0];
            for (int i = 1; i < len; i++)
            {
                m = System.Math.Min(m, el[i]);
            }
            Flops += len;
            return m;
        }

        /// <summary>
        /// Max, returns the Max value of the vector.
        /// </summary>
        /// <returns>Maximum</returns>
        public double Max()
        {
            if (len == 0) { Trace.Assert(false); return 0.0; }
            double m = el[0];
            for (int i = 1; i < len; i++)
            {
                m = System.Math.Max(m, el[i]);
            }
            Flops += len;
            return m;
        }

        /// <summary>
        /// MinAt
        /// </summary>
        /// <param name="at">position of last Minimum in the vector (zero-based)</param>
        /// <returns>Minimum</returns>
        public double MinAt(out int at)
        {
            at = 0;
            if (len == 0) { Trace.Assert(false); return 0.0; }
            double m = el[0];
            for (int i = 1; i < len; i++)
            {
                if (el[i] <= m) // new minima ?
                {
                    m = el[i];
                    at = i;         // position of last minima
                }
            }
            Flops += len;
            return m;
        }

        /// <summary>
        /// MinAt
        /// </summary>
        /// <param name="at">position of last minimum in the vector (zero-based)</param>
        /// <param name="sel">set range vector</param>
        /// <returns></returns>
        public double MinAt(out int at, CCOVector sel)
        {
            double l_Min = Int32.MaxValue;
            at = 0;

            if (len == 0) { Trace.Assert(false); return 0.0; }
            if (sel.len != len) { Trace.Assert(false); return 0.0; }
            if (sel.Sum() == 0.0) { Trace.Assert(false); return 0.0; }  // nothing selected

            for (int i = 0; i < len; i++)
            {
                if (sel.el[i] > 0.0)                     // selected
                {
                    if (el[i] <= l_Min)                  // new minimum ?
                    {
                        l_Min = el[i];
                        at = i;                       // position of last minimum
                    }
                }
            }
            Flops += len;
            return l_Min;
        }

        /// <summary>
        /// MaxAt
        /// </summary>
        /// <param name="at">position of last maximum in the vector (zero-based)</param>
        /// <returns>Maximum</returns>
        public double MaxAt(out int at)
        {
            at = 0;
            if (len == 0) { Trace.Assert(false); return 0.0; }
            double m = el[0];
            for (int i = 1; i < len; i++)
            {
                if (el[i] >= m) // new maxima ?
                {
                    m = el[i];
                    at = i;         // position of last maxima
                }
            }
            Flops += len;
            return m;
        }

        /// <summary>
        /// MaxAt
        /// </summary>
        /// <param name="at">position of last Maximum in the vector (zero-based)</param>
        /// <param name="sel">set range vector</param>
        /// <returns></returns>
        public double MaxAt(out int at, CCOVector sel)
        {
            double l_Max = Int32.MinValue;
            at = 0;

            if (len == 0) { Trace.Assert(false); return 0.0; }
            if (sel.len != len) { Trace.Assert(false); return 0.0; }
            if (sel.Sum() == 0.0) { Trace.Assert(false); return 0.0; }  // nothing selected

            for (int i = 0; i < len; i++)
            {
                if (sel.el[i] > 0.0)                     // selected
                {
                    if (el[i] >= l_Max)                   // new maxima ?
                    {
                        l_Max = el[i];
                        at = i;                       // position of last maxima
                    }
                }
            }
            Flops += len;
            return l_Max;
        }

        /// <summary>
        /// Mean / Mittelwert 
        /// </summary>
        /// <returns>Mean</returns>
        public double Mean()
        {
            if (len == 0) { Trace.Assert(false, "vector has no elements"); return 0.0; }
            return Sum() / (double)(len);
        }


        /// <summary>
        /// Sum sums up all vector elements
        /// </summary>
        /// <returns>sum</returns>
        public double Sum()
        {
            double sum = 0.0;
            for (int i = 0; i < len; i++)
            {
                sum += el[i];
            }
            Flops += len;
            return sum;
        }

        /// <summary>
        /// calculates the absorbance vector
        /// 
        /// this vector must be a transmission
        /// 
        /// A = -log10(T)
        /// </summary>
        /// <returns></returns>
        public CCOVector GetAbsorbance()
        {
            const double l_dLimiter = 1.0e-10;
            CCOVector res = new CCOVector(this);
            for (int i = 0; i < len; i++)
            {
                res.el[i] = -System.Math.Log10(System.Math.Max(this.el[i], l_dLimiter));
            }
            Flops += len;
            return res;
        }

        /// <summary>
        /// calculates the transmission vector
        /// 
        /// this vector must be a absorbance
        /// T = pow10(-A)
        /// </summary>
        /// <returns></returns>
        public CCOVector GetTransmission()
        {
            CCOVector res = new CCOVector(this);
            for (int i = 0; i < len; i++)
            {
                res.el[i] = System.Math.Pow(10.0, -this.el[i]);
            }
            Flops += len;
            return res;
        }


        /// <summary>
        /// Varianz 
        /// 
        ///		Varianz = 1/(N-1) * SUM( (Xi-Mean(X))^2 )
        ///		
        /// other names:
        /// - Varianz
        /// - mittlere quadratische Abweichung
        /// - (Standardabweichung)^2
        /// - formula character : Sigma-Square
        /// </summary>
        /// <returns>Variance</returns>
        public double Variance()
        {
            if (len < 2) { Trace.Assert(false, "vector needs at least 2 elements"); return 0.0; }
            CCOVector diff = new CCOVector(this);
            diff -= Mean();
            return diff.Dot(diff) / (double)(len - 1);  // -1 : one degree of freedom for mean
        }

        /// <summary>
        /// Varianz 
        /// 
        ///		Varianz = 1/(N-1) * SUM( (Xi-Mean(X))^2 )
        ///		
        /// other names:
        /// - Varianz
        /// - mittlere quadratische Abweichung
        /// - (Standardabweichung)^2
        /// - formula character : Sigma-Square
        /// </summary>
        /// <param name="p_Sel">selection</param>
        /// <returns>Variance</returns>
        public double Variance(CCOVector p_Sel)
        {
            if (p_Sel.Sum() < 2) { Trace.Assert(false, "variance for zero or one element can't be calculated"); return 0.0; }
            CCOVector shrink = this.ShrinkToSelection(p_Sel);
            return shrink.Variance();
        }

        /// <summary>
        /// Standard Deviation / Sdev
        /// Standardabweichung der Vector Elemente     
        /// 
        ///		Sdev = sqrt( 1/(N-1) * SUM( (Xi-Mean(X))^2 ) )
        ///		
        /// other names:
        /// - sqrt(Varianz)
        /// - Standardabweichung
        /// - formula character : Sigma
        /// </summary>
        /// <returns>Sdev</returns>
        public double Sdev()
        {
            return System.Math.Sqrt(Variance());
        }

        /// <summary>
        /// Standard Deviation / Sdev
        /// Standardabweichung der Vector Elemente     
        /// 
        ///		Sdev = sqrt( 1/(N-1) * SUM( (Xi-Mean(X))^2 ) )
        ///		
        /// other names:
        /// - sqrt(Varianz)
        /// - Standardabweichung
        /// - formula character : Sigma
        /// <param name="p_Sel">selection</param>
        /// <returns></returns>
        public double Sdev(CCOVector p_Sel)
        {
            return System.Math.Sqrt(Variance(p_Sel));
        }




        /// <summary>
        /// Abs / Absolute value
        /// </summary>
        /// <returns>vector with absolute element values</returns>
        public CCOVector Abs()
        {
            CCOVector res = new CCOVector(this);
            for (int i = 0; i < len; i++)
            {
                res.el[i] = System.Math.Abs(res.el[i]);
            }
            Flops += len;
            return res;
        }

        /// <summary>
        /// Sqrt / Square Root
        /// </summary>
        /// <returns>vector with sqrt element values</returns>
        public CCOVector Sqrt()
        {
            CCOVector res = new CCOVector(this);
            for (int i = 0; i < len; i++)
            {
                res.el[i] = System.Math.Sqrt(res.el[i]);
            }
            Flops += len;
            return res;
        }

        /// <summary>
        /// Sqr / Square value / x*x
        /// </summary>
        /// <returns>vector with squared element values</returns>
        public CCOVector Sqr()
        {
            CCOVector res = new CCOVector(this);
            for (int i = 0; i < len; i++)
            {
                res.el[i] *= res.el[i];
            }
            Flops += len;
            return res;
        }

        /// <summary>
        /// Reziprocal
        /// </summary>
        /// <returns>vector with 1/element values</returns>
        public CCOVector Reziprocal()
        {
            CCOVector res = new CCOVector(this);
            for (int i = 0; i < len; i++)
            {
                res.el[i] = 1.0 / res.el[i];		// use of default division by zero exception
            }
            Flops += len;
            return res;
        }


        /// <summary>
        /// convert 0-based vector to 1-based vector
        /// </summary>
        public void IndexingCToPascal()
        {	// hier könnte man mit CopyTo noch optimieren
            Extend(len + 1);
            ShiftRight(1);
        }


        /// <summary>
        /// convert 1-based vector to 0-based vector
        /// </summary>		
        public void IndexingPascalToC()
        {
            ShiftLeft(1);
            Shrink(len - 1);
        }



        /// <summary>
        /// Cubic Spline Interpolation
        /// </summary>
        /// <param name="cXI">in: x-axis input  values</param>
        /// <param name="cYI">in: y-axis input  values</param>
        /// <param name="cXO">in: x-axis output values</param>
        /// <param name="cYO">out:y-axis output values</param>
        /// <returns>false in parameter not ok</returns>
        public bool FreeCubicSpline(CCOVector cXI, CCOVector cYI, CCOVector cXO, out CCOVector cYO)
        {
            /// Internal Notes:
            /// - german documentation because of german document reference
            /// - Gl.11 bezieht sich auf die Gleichungs Nummer der Herleitung (Dr. U. Glaus, BCAP Software)
            /// - wird verwendet um Spektren-X-Skalen auf äquidistante Stützstellen umzurechnen.

            cYO = new CCOVector();	// out !
            // YO ist Ergebnis Vektor!
            // Alle Vektoren der Schnittstelle sind 0-indexiert !
            int LenI = cXI.Length;									// Länge der Input  Vektoren XI und YI
            int LenO = cXO.Length;									// Länge der Output Vektoren XO und YO
            if (!(LenI == cYI.Length)) { return false; }		// XI und YI nicht gleich lang
            //	if( !( LenO ==  YO.Length ))	 { return false; }		// XO und YO nicht gleich lang
            //	if( !( LenI > LenO)  )			 { return false; }		// Input Vektor muss länger sein als Output Vektor, denn es wird interpoliert nicht extrapoliert.
            if (!(LenI > 3)) { return false; }
            if (!(LenO > 3)) { return false; }

            // XI und XO müssen aufsteigend geordnet sein: 
            if (!(cXI[1] < cXI[2])) { return false; }		// XI[1]<XI[2]<...<XI[N]
            if (!(cXI[LenI - 2] < cXI[LenI - 1])) { return false; }		// XI[1]<XI[2]<...<XI[N]
            if (!(cXO[1] < cXO[2])) { return false; }		// XO[1]<XO[2]<...<XO[N]
            if (!(cXO[LenO - 2] < cXO[LenO - 1])) { return false; }		// XO[1]<XO[2]<...<XO[N]
            //	if( !( cXI[1]      < cXO[1]		 )){ return false; }	// Output X Bereich muss innerhalb des Input X Bereichs liegen
            //	if( !( cXI[LenI-1] > cXO[LenO-1] )){ return false; }	// Output X Bereich muss innerhalb des Input X Bereichs liegen

            // original Algorithmus basiert auf 1-indizierten Vektoren, darum hier umwandeln.
            CCOVector XI = new CCOVector(cXI); XI.IndexingCToPascal();
            CCOVector YI = new CCOVector(cYI); YI.IndexingCToPascal();
            CCOVector XO = new CCOVector(cXO); XO.IndexingCToPascal();
            CCOVector YO = new CCOVector(LenO); YO.IndexingCToPascal();
            CCOVector a2 = new CCOVector(LenI); a2.IndexingCToPascal();

            int i, j;
            double Hi, H, x, a1, a3;
            {   // lokale Koeffizienten Berechnung
                // <local> PROCEDURE Get2Coefficients()
                CCOVector Gamma = new CCOVector(LenI + 1);

                CCOVector X = new CCOVector(LenI + 1);
                for (i = 2; i < LenI; i++)
                {                                               // Gl.11
                    Gamma[i] = 3 * ((YI[i + 1] - YI[i]) / (XI[i + 1] - XI[i]) -
                        (YI[i] - YI[i - 1]) / (XI[i] - XI[i - 1]));
                }
                Gamma[1] = 0;
                Gamma[LenI] = 0;
                X[1] = 0;
                X[LenI] = 0;
                X[2] = 2 * (XI[3] - XI[1]);                 // Gl.13.1
                for (i = 3; i < LenI; i++)
                {                                               // Gl.13  (2x)
                    X[i] = 2 * (XI[i + 1] - XI[i - 1]) - (XI[i] - XI[i - 1]) * (XI[i] - XI[i - 1]) / X[i - 1];
                    Gamma[i] = Gamma[i] - Gamma[i - 1] * (XI[i] - XI[i - 1]) / X[i - 1];
                }
                a2[1] = 0;
                a2[LenI] = 0;
                a2[LenI - 1] = Gamma[LenI - 1] / X[LenI - 1];       // Gl.15

                for (int k = (LenI - 2); k >= 2; k--)
                {
                    a2[k] = (Gamma[k] - (XI[k + 1] - XI[k]) * a2[k + 1]) / X[k];    // Gl.16
                }
            }	// <local> PROCEDURE Get2Coefficients()

            j = 1;
            for (i = 1; i <= LenO; i++)
            {
                while (XI[j] < XO[i])
                {
                    if (j == LenI) { break; }
                    j++;
                }

                x = XO[i] - XI[j - 1];
                Hi = XI[j] - XI[j - 1];
                a3 = (a2[j] - a2[j - 1]) / (3 * Hi);
                a1 = (YI[j] - YI[j - 1]) / Hi - Hi * (2 * a2[j - 1] + a2[j]) / 3;
                H = a3 * x + a2[j - 1];
                H = H * x + a1;
                H = H * x + YI[j - 1];
                YO[i] = H;
            }
            YO.IndexingPascalToC();
            YO.CopyTo(cYO);

            Flops += LenO * 20 + LenI * 8 + LenI * 11 + LenI * 4;		// approx. - loops only
            return true;
        } // FreeCubicSpline 



        /// <summary>
        /// geometrical vector length
        /// </summary>
        /// <returns></returns>
        public double GeomLength()
        {
            return System.Math.Sqrt(this.Dot(this));
        }

        /// <summary>
        /// norm the vector to geometrical vector length of 1.0
        /// </summary>
        /// <returns></returns>
        public CCOVector Normalize()
        {
            double sum = GeomLength();
            if (sum == 0)
            {
                Trace.Assert(false, "vector can not be normalized");
                return EMPTY_VECTOR;
            }
            CCOVector res = new CCOVector(this);
            res /= sum;				// scale Vector by geom. Vector length
            return res;
        }


        /// <summary>
        /// successive differences
        /// 
        ///		res(i) = vec(i+1) - vec(i)
        ///		
        /// - vector needs at least 2 elements
        /// - the last diff element is copied from its predecessor to avoid discontinuity
        /// </summary>
        /// <param name="data"></param>
        /// <returns>differences vector in same size as original data</returns>
        public CCOVector Diff()
        {
            if (len < 2)
            {
                Trace.Assert(false, "vector needs at least 2 elements");
                return EMPTY_VECTOR;
            }
            CCOVector res = new CCOVector(this);
            for (int i = 0; i < len - 1; i++)
            {
                res.el[i] = this.el[i + 1] - this.el[i];
            }
            Flops += len - 1;
            res.el[len - 1] = res.el[len - 2];	// the last diff element is copied from its predecessor to avoid discontinuity
            return res;
        }

        /// <summary>
        /// Flips Vector halfs. Swaps upper and lower vector halfs. Useful for fft.
        /// e.g. "1 2 3 4"     flipped: "3 4 1 2"	 even number
        ///      "1 2 3 4 5"   flipped: "4 5 1 2 3"	 odd number
        ///  This function is called "fftshift" in MATLAB
        /// </summary>
        /// <returns>flipped vector</returns>
        public CCOVector Flip()
        {
            CCOVector res = new CCOVector(this);
            int i = 0;
            int len2 = len / 2;

            if (len > 1)
            {
                int odd = len % 2;					//  1:odd, 0:even
                for (i = 0; i < len2; i++)
                {
                    res.el[i] = this.el[i + len2 + odd]; // lower half
                    res.el[i + len2] = this.el[i];              // upper half
                }
                // if odd, build last element
                if (odd == 1)
                {
                    res.el[i + len2] = this.el[i];
                }
            }
            return res;
        }

        /// <summary>
        /// Constructor with string
        /// useful for testing
        /// </summary>
        /// <param name="s">example vector "1 2 3 4"</param>
        public CCOVector(string s)
        {
            char[] SEPERATOR = { ' ' };
            s = s.Trim();
            string[] v = s.Split(SEPERATOR);
            int vlen = v.GetLength(0);

            this.Init(vlen);
            for (int i = 0; i < vlen; i++)
            {
                this.el[i] = Convert.ToDouble(v[i]);
            }
        }

        /// <summary>
        /// zeros all vector elements
        /// </summary>
        public void Zero()
        {
            for (int i = 0; i < len; i++)
            {
                el[i] = 0.0;
            }
            Flops += len;
        }


        /// <summary>
        /// Fills the vector with Random values between 0.0 and 1.0
        /// </summary>
        public void RandFill()
        {
            Random rnd = new Random();
            for (int i = 0; i < len; i++)
            {
                el[i] = rnd.NextDouble();
            }
            Flops += len;
        }


        /////////////////////////////////
        //// UN-TESTED NEW FUNCTIONS ////
        /////////////////////////////////



        /// <summary>
        /// Mean of all values in set range
        /// </summary>
        /// <param name="sel">set range vector</param>
        /// <returns>Mean</returns>
        public double Mean(CCOVector sel)
        {
            if (len == 0) { Trace.Assert(false); return 0.0; }
            if (sel.len != len) { Trace.Assert(false); return 0.0; }
            double NumValues = sel.Sum();
            if (NumValues == 0.0) { Trace.Assert(false); return 0.0; }	// nothing selected
            return Sum(sel) / NumValues;
        }


        /// <summary>
        /// Sum of all values in set range
        /// </summary>
        /// <param name="sel">set range vector</param>
        /// <returns>Sum</returns>
        public double Sum(CCOVector sel)
        {
            if (len == 0) { Trace.Assert(false); return 0.0; }
            if (sel.len != len) { Trace.Assert(false); return 0.0; }
            if (sel.Sum() == 0.0) { Trace.Assert(false); return 0.0; }	// nothing selected
            double sum = 0.0;
            for (int i = 0; i < len; i++)
            {
                if (sel.el[i] > 0.0)	   // selected
                {
                    sum += el[i];
                }
            }
            return sum;
        }



        /// <summary>
        /// Max of all values in set range
        /// </summary>
        /// <param name="sel">set range vector</param>
        /// <returns>Max</returns>
        public double Max(CCOVector sel)
        {
            if (len == 0) { Trace.Assert(false); return 0.0; }
            if (sel.len != len) { Trace.Assert(false); return 0.0; }
            if (sel.Sum() == 0.0) { Trace.Assert(false); return 0.0; }	// nothing selected
            double m = -(double.MaxValue);
            for (int i = 0; i < len; i++)
            {
                if (sel.el[i] > 0.0)	   // selected
                {
                    m = System.Math.Max(m, el[i]);
                }
            }
            return m;
        }


        /// <summary>
        /// Min of all values in set range
        /// </summary>
        /// <param name="sel"></param>
        /// <returns></returns>
        public double Min(CCOVector sel)
        {
            if (len == 0) { Trace.Assert(false); return 0.0; }
            if (sel.len != len) { Trace.Assert(false); return 0.0; }
            if (sel.Sum() == 0.0) { Trace.Assert(false); return 0.0; }	// nothing selected
            double m = +(double.MaxValue);
            for (int i = 0; i < len; i++)
            {
                if (sel.el[i] > 0.0)	   // selected
                {
                    m = System.Math.Min(m, el[i]);
                }
            }
            return m;
        }


        /// <summary>
        /// geometrical vector length in set range
        /// </summary>
        /// <param name="sel">set range</param>
        /// <returns>geometrical vector length</returns>
        public double GeomLength(CCOVector sel)
        {
            if (sel.len != len) { Trace.Assert(false); return 0.0; }
            double sum = 0.0;
            for (int i = 0; i < len; i++)
            {
                if (sel.el[i] > 0.0)	   // selected
                {
                    sum += (el[i] * el[i]);
                }
            }
            return System.Math.Sqrt(sum);
        }


        /// -------------------------------------------------------------------
        /// <summary>
        /// Loads a file and reads all numeric data from that file into the vector.
        /// </summary>
        /// <param name="p_sFileName">Fully qualified name of file</param>
        public void Load(string p_sFileName)
        {
            Debug.Assert(p_sFileName.Length != 0);

            StreamReader l_Stream;
            try
            {
                l_Stream = File.OpenText(p_sFileName);
            }
            catch
            {
                // file not opened
                Trace.Assert(false, "Could not open file");
                throw;
            }
            BuildVectorFromText(l_Stream.ReadToEnd());
            l_Stream.Close();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Scan a text, read each numeric data from that text and store
        /// it as double in the vector
        /// </summary>
        /// <param name="p_Text">Scan this text</param>
        private void BuildVectorFromText(string p_Text)
        {
            Debug.Assert(p_Text.Length != 0);

            int l_Index = 0;
            int l_StartIndex = 0;
            int l_EndIndex = 0;
            char[] l_StartCharacter = new Char[12] { '-', '.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
            char[] l_EndCharacter = new Char[15] { '-', '+', 'e', 'E', '.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
            ArrayList l_TmpVector = new ArrayList(100); // temporary vector with init size 100

            // read each number
            while (l_Index < p_Text.Length)
            {
                // find starting character
                l_StartIndex = p_Text.IndexOfAny(l_StartCharacter, l_Index);
                if (-1 == l_StartIndex)
                {
                    break;  // end of text
                }
                l_Index = l_StartIndex;
                l_Index++;

                // find ending character
                while (l_Index == p_Text.IndexOfAny(l_EndCharacter, l_Index))
                {
                    l_Index++;
                }
                l_EndIndex = l_Index;
                l_Index++;

                // read next number and store it in the vector
                string l_StringValue = p_Text.Substring(l_StartIndex, l_EndIndex - l_StartIndex);
                l_TmpVector.Add(Convert.ToDouble(l_StringValue));
            }
            // copy the new vector
            Object[] l_ObjectArray = l_TmpVector.ToArray();
            Trace.Assert(l_ObjectArray.Length > 0, "Bad array length");
            Release();
            Init(l_ObjectArray.Length);
            Array.Copy(l_ObjectArray, el, l_ObjectArray.Length);
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Save all items from a vector to a file. So it can be tested with 
        /// Matlab.
        /// </summary>
        /// <param name="p_FileName">Fully qualified name of file</param>
        public void Save(string p_FileName)
        {
            StreamWriter l_File;
            try
            {
                l_File = File.CreateText(p_FileName);
            }
            catch
            {
                // file not created
                Trace.Assert(false, "Could not create file");
                throw;
            }

            // write on each line a number
            foreach (double l_Number in el)
            {
                l_File.WriteLine(l_Number.ToString("E17") + " ");
            }

            l_File.Close();
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a new vector with all elements in reverse order. If the array is null, 
        /// then also the returned array will be null.
        /// e.g. "1 2 3 4" -> "4 3 2 1"
        /// </summary>
        /// <returns>Vector in reverse order</returns>
        public virtual CCOVector Reverse()
        {
            CCOVector Result = null;

            if (el != null)
            {
                Result = new CCOVector(el.Length);

                for (int i = 0; i < el.Length; i++)
                {
                    Result.el[i] = el[el.Length - i - 1];
                }
            }
            return Result;
        }

        /// <summary>
        /// Shrinks this vector to a given selection.
        /// e.g. 
        /// this		1 2 3 4
        /// Selection   0 1 0 1
        /// Result      2 4
        /// </summary>
        /// <param name="p_Selection">selection vector  0:unselected , 1:selected</param>
        /// <returns>shrinked vector</returns>
        public virtual CCOVector ShrinkToSelection(CCOVector p_Selection)
        {
            Trace.Assert(p_Selection.Length == this.Length, "selection and data must have the same size ");
            CCOVector shrinked = new CCOVector((int)p_Selection.Sum());
            int x = 0;
            for (int i = 0; i < this.Length; i++)
            {
                if (p_Selection[i] == 1.0)
                {
                    shrinked[x] = this[i];
                    x++;
                }
            }
            return shrinked;
        }

        /// <summary>
        /// Fills a vector with a certain value. This method can be used to build selectors for 
        /// functions like (MaxAt, ..)
        /// </summary>
        /// <param name="p_Start">Start index</param>
        /// <param name="p_Length">Length of selection</param>
        /// <param name="p_Value">Fill value</param>
        public void FillSelection(int p_Start, int p_Length, double p_Value)
        {
            if (this.len >= p_Start + p_Length)
            {
                for (int i = p_Start; i < p_Start + p_Length; i++)
                {
                    this.el[i] = p_Value;
                }
            }
        }

        /// <summary>
        /// Used for block selection of vector elements. 
        /// </summary>
        /// <param name="p_RangeFrom">Start index</param>
        /// <param name="p_Length">Length</param>
        /// <param name="p_BlockSelect">Length of selection</param>
        /// <param name="p_BlockLeave">Length of unselected part</param>
        public void BlockSelect(int p_RangeFrom, int p_Length, int p_BlockSelect, int p_BlockLeave)
        {
            Debug.Assert(p_RangeFrom >= 0 &&
                p_Length <= len - p_RangeFrom &&
                p_Length >= 0 &&
                p_BlockSelect > 0 &&
                p_BlockLeave > 0);

            if (len == 0 || p_Length == 0)
            {
                return;    // do nothing
            }

            int p_RangeTo = p_RangeFrom + p_Length - 1;
            int k;
            int i = p_RangeFrom;
            for (; ; )
            {
                // Select part
                for (k = i; k < (i + p_BlockSelect); k++)
                {
                    if (k > p_RangeTo) break;	// for k
                    el[k] = m_Select;			// select
                }
                i = k;
                if (i > p_RangeTo) break;		// for (;;)

                // Leave part (Deselect Part)
                for (k = i; k < (i + p_BlockLeave); k++)
                {
                    if (k > p_RangeTo) break;	// for k
                    el[k] = m_Deselect;			// deselect
                }
                i = k;
                if (i > p_RangeTo) break;		// for (;;)
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Power this^y
        /// </summary>
        /// <param name="p_y"></param>
        /// <returns>vector with Pow values</returns>
        public CCOVector Power(double p_y)
        {
            CCOVector res = new CCOVector(this.Length);

            for (int i = 0; i < this.Length; i++)
            {
                res[i] = System.Math.Pow(el[i], p_y);
            }

            return res;
        }


        /// <summary>
        /// Searches peaks in data with a peakfit.
        /// </summary>
        /// <param name="this">data vector. Make sure the data is scaled right (i.e. convert transmission to absorbance before)</param>
        /// <param name="p_Peaks">peak center positions in x-axis to be found</param>
        /// <param name="p_DataResolution">equidistant x-spacing</param>
        /// <param name="p_DataStart">start of x-axis</param>
        /// <param name="p_ZeroFilling">FFT zerofilling factor. I.e. 8</param>
        /// <param name="p_Fraction">Peak fraction. greater 0.0, less or equal 1.0. I.e. 0.99. Amount of peak base used for fit.</param> 
        /// <returns>found peak center positions in x-axis in p_Data. EMPTY_VECTOR if bad parameters or bad data. Peak position = p_DataStart-p_DataResolution if there is no peak found</returns>
        public CCOVector PeakFit(CCOVector p_Peaks, double p_DataResolution, double p_DataStart, int p_ZeroFilling, double p_Fraction)
        {
            // data check
            int n = this.Length;
            if (n < 4) { Debug.Assert(false); return CCOVector.EMPTY_VECTOR; }  // 4-th order polynom fit
            if (p_Peaks.Length < 1) { Debug.Assert(false); return CCOVector.EMPTY_VECTOR; } // at least 1 peak to search

            // parameter check
            if (p_Fraction <= 0.0) { Debug.Assert(false); return CCOVector.EMPTY_VECTOR; }
            if (p_Fraction > 1.0) { Debug.Assert(false); return CCOVector.EMPTY_VECTOR; }
            if (p_DataResolution <= 0.0) { Debug.Assert(false); return CCOVector.EMPTY_VECTOR; }
            if (p_ZeroFilling < 1) { Debug.Assert(false); return CCOVector.EMPTY_VECTOR; }  // we don't shirnk the data !

            // standard wavenumber axis
            CCOVector nu = new CCOVector(n);                            // nu=xstart+xstep*[0:(n-1)]';       
            nu.IndexFill(p_DataStart, p_DataResolution);

            // axis after zerofilling
            CCOVector nu_zf = new CCOVector(n * p_ZeroFilling);     // nu_zf= xstart + (xstep/zf)* [ 0:(zf*(n-1)) ]';    
            nu_zf.IndexFill(p_DataStart, p_DataResolution / (double)p_ZeroFilling);

            // calculate refined spectrum starting from normal spectrum using zerofilling
            CCOFFT l_FFT = new CCOFFT();
            CCOVector a_zf = l_FFT.ZeroFillingSymmetric(this, p_ZeroFilling);   // a_zf=zfspectrum(a,zf);
                                                                                //a_zf.Save( @"C:\temp\a_zf.DAT" );

            // Calculate 2nd derivative
            CCOVector d2a_zf = new CCOVector(a_zf);
            d2a_zf.SecondDerivativeSavitzkyGolay7Point();
            //d2a_zf.Save( @"C:\temp\d2a_zf2.DAT" );

            // PeaksFound
            CCOVector devl = new CCOVector(p_Peaks.Length);             // devl=zeros(size(PCent));

            // step thru peaklist
            for (int k = 0; k < p_Peaks.Length; k++)
            {
                double nupeak0 = p_Peaks[k];                                // nupeak0=PCent(k);

                int pos;                                                    // find point closest to peak-wavenumber
                double a = ((CCOVector)(nu_zf - nupeak0)).Abs().MinAt(out pos); // [a pos]=min(abs((nu_zf-nupeak0))); 
                Debug.WriteLine("pos=" + pos.ToString() + " , a=" + a.ToString());

                double ypeak = d2a_zf[pos];                             // ypeak  = d2a_zf(pos);
                double psign = System.Math.Sign(ypeak);                 // psign  = sign(ypeak);
                double ylimit = (1.0 - p_Fraction) * psign * ypeak;             // ylimit = (1-pfraction)*psign*ypeak;

                int nul = pos;                                              // find peak limit on the left hand side
                int nur = pos;                                              // find peak limit on the right hand side
                while (nul > 0) if (psign * d2a_zf[nul - 1] >= ylimit) nul--; else break;
                while (nur < d2a_zf.Length) if (psign * d2a_zf[nur + 1] >= ylimit) nur++; else break;
                Debug.WriteLine("nul=" + nul.ToString() + " , nur=" + nur.ToString());

                //    %select window for fit
                CCOVector x = nu_zf.GetSlice(nul, nur - nul + 1);           // x = nu_zf(nul:nur);

                // BOS + MEYT 040316 auf Spektren statt auf 2.Ableitung, weil sonst "flache" Peaks am ungünstigen Ort lokalisiert werden. 
                //CCOVector y = d2a_zf.GetSlice( nul, nur-nul+1 )*psign;	// y = psign*d2a_zf(nul:nur);    %flip peak if negative
                CCOVector y = a_zf.GetSlice(nul, nur - nul + 1) * (-psign);     // y = psign*d2a_zf(nul:nur);    %flip peak if negative


                // mean center axis, set spacing to 1 (for equidistant axis)
                double xm = x.Mean();                                       // xm=mean(x);
                double xdelta = (x[x.Length - 1] - x[0]) / (double)(x.Length - 1);  // xdelta=(x(end)-x(1))/(length(x)-1);
                CCOVector xr = (x - xm) / xdelta;                               // xr=(x-xm)/xdelta;

                // fit, 1st derivative, 2nd derivative 
                int n_fp = 4;                                               // order of fitting polynomial
                CCOVector fp = xr.PolyFit(y, n_fp);                 // fp   = polyfit(xr,y,n_fp);
                CCOVector dfp = fp.PolyDer();                               // dfp  = polyder(fp);
                CCOVector dfp2 = dfp.PolyDer();                             // dfp2 = polyder(dfp);

                // find roots
                CCOVector r = dfp.RootsCubic();                         // we get only real roots	// r=roots(dfp);
                CCOVector rr = new CCOVector(1);                            // rr=[];
                for (int kr = 0; kr < r.Length; kr++)                           // for kr=1:length(r),
                {
                    if (r[kr] >= xr[0] && r[kr] <= xr[xr.Length - 1])       // in range?   //  if (r(kr)>=xr(1) && r(kr)<=xr(end))
                    {
                        if (dfp2.PolyVal(r[kr]) <= 0)                   // maximum? //    if (polyval(dfp2,r(kr))<=0)
                        {
                            rr[rr.Length - 1] = r[kr];                  // rr=[rr;r(kr)]; 
                            rr.Extend(rr.Length + 1);                       // resize vector for next value
                        }
                    }
                }
                double nupeak = xm + xdelta * rr[0];                        // nupeak=xm+xdelta*rr(1);

                // return the deviations
                // double dev = nupeak - nupeak0;							// dev=nupeak-nupeak0;
                // devl[k] = dev;											// devl(k)=dev;

                // return the found peaks
                devl[k] = nupeak;

            }// next k
            return devl;                                                    // PeaksFound
        }



        /// <summary>
        /// Second Derivative Savitzky Golay 9 Point
        /// </summary>
        /// <param name="this">data vector to be treated</param>
        public void SecondDerivativeSavitzkyGolay9Point()
        {
            CCOVector Filter = new CCOVector(9);
            Filter[0] = 28.0;
            Filter[1] = 7.0;
            Filter[2] = -8.0;
            Filter[3] = -17.0;
            Filter[4] = -20.0;
            Filter[5] = -17.0;
            Filter[6] = -8.0;
            Filter[7] = 7.0;
            Filter[8] = 28.0;
            this.LinearFilter(Filter, 462.0).CopyTo(this);
        }

        /// <summary>
        /// Second Derivative Savitzky Golay 7 Point
        /// </summary>
        /// <param name="this">data vector to be treated</param>
        public void SecondDerivativeSavitzkyGolay7Point()
        {
            CCOVector Filter = new CCOVector(7);
            Filter[0] = 5.0;
            Filter[1] = 0.0;
            Filter[2] = -3.0;
            Filter[3] = -4.0;
            Filter[4] = -3.0;
            Filter[5] = 0.0;
            Filter[6] = 5.0;
            this.LinearFilter(Filter, 42.0).CopyTo(this);
        }


        /// <summary>
        /// Fills the vector with equidistant values.
        /// Used for building x-axis scales.
        /// </summary>
        /// <param name="p_Start">start value for index 0</param>
        /// <param name="p_Step">increment value for successive indices</param>
        public void IndexFill(double p_Start, double p_Step)
        {
            for (int i = 0; i < len; i++)
            {
                el[i] = p_Start + (double)i * p_Step;
            }
        }

        /// <summary>
        /// Fills the vector with value d
        /// </summary>
        public void Fill(double d)
        {
            for (int i = 0; i < len; i++)
            {
                el[i] = d;
            }
        }


        /// <summary>
        /// Round each vector element.
        /// Useful for result testing.
        /// </summary>
        /// <param name="p_NumDigits">The number of significant fractional digits (precision) in the return value.</param>
        /// <returns></returns>
        public CCOVector Round(int p_NumDigits)
        {
            CCOVector ret = new CCOVector(this);
            for (int i = 0; i < ret.Length; i++)
            {
                ret[i] = System.Math.Round(ret[i], p_NumDigits);
            }
            return ret;
        }


        /// <summary>
        /// Fit polynomial to data.
        /// </summary>
        /// <remarks>
        ///	function p = mypolyfit(x,y,n)
        ///	%MYPOLYFIT Fit polynomial to data.
        ///	%   MYPOLYFIT(X,Y,N) finds the coefficients of a polynomial P(X) of
        ///	%   degree N that fits the data, P(X(I))~=Y(I), in a least-squares sense.
        ///	%
        ///	%   See also POLYFIT, POLY, POLYVAL, ROOTS.
        ///
        ///	if ~isequal(size(x),size(y))
        ///		error('X and Y vectors must be the same size.')
        ///	end
        ///
        ///	x = x(:);
        ///	y = y(:);
        ///
        ///	% Construct Vandermonde matrix.
        ///	V(:,n+1) = ones(length(x),1);
        ///	for j = n:-1:1
        ///		V(:,j) = x.*V(:,j+1);
        ///	end
        ///
        ///	% Solve least squares problem, and save the Cholesky factor.
        ///	[Q,R] = qr(V,0);
        ///	p = R\(Q'*y);    % Same as p = V\y;		// Backslash or left matrix divide. If A is a square matrix, A\B is roughly the same as inv(A)*B   
        ///	r = y - V*p;
        ///	p = p.';          % Polynomial coefficients are row vectors by convention.
        /// </remarks>
        /// <param name="this">data X(I)</param>
        /// <param name="y">data Y(I)</param>
        /// <param name="n">polynomial degree</param>
        /// <returns>coefficients of a polynomial P(X) of degree N that fits the data, P(X(I))~=Y(I), in a least-squares sense</returns>
        public CCOVector PolyFit(CCOVector y, int n)
        {
            if (this.Length != y.Length) { Debug.Assert(false); return CCOVector.EMPTY_VECTOR; }

            CCOMatrix V = new CCOMatrix();
            V.Vandermonde(n, this);

            CCOQRDecomposition QR = new CCOQRDecomposition(V);
            CCOMatrix Q = QR.Q;
            CCOMatrix R = QR.R;

            CCOMatrix QY = new CCOMatrix(1, n);
            CCOMatrix YY = new CCOMatrix(y);
            QY = YY * Q;

            CCOMatrix RInv = new CCOMatrix();
            R.Inverse(RInv);

            CCOMatrix P = new CCOMatrix(RInv.ncol, 1);
            RInv.MultiplyTranspose(QY, P);  // P = RInv * QY
            return P.GetColVector(0);
        }

        /// <summary>
        /// Regressions Koeffizient R (nicht R^2) von 2 Vektoren x und y
        /// </summary>
        /// <param name="y">2. Vector</param>
        /// <returns></returns>
        public double RegressionCoefficient(CCOVector y)
        {
            CCOVector a = new CCOVector(this);
            CCOVector b = new CCOVector(y);
            a -= this.Mean();
            b -= y.Mean();
            // Sxx = dot(a,a)
            // Syy = dot(b,b)
            // Sxy = dot(a,b)
            // RegressionCoefficient = Sxy / Sqrt(Sxx*Syy)
            double Nenner = System.Math.Sqrt(a.Dot(a) * b.Dot(b));
            if (System.Math.Abs(Nenner) <= Double.MinValue) // DBL_MIN ist nahe 0.0 !
            {
                return 0.0;
            }
            return a.Dot(b) / Nenner;
        }

        /// <summary>
        /// Differentiate polynomial.
        /// Returns the derivative of the polynomial whose coefficients are the elements of vector.
        /// i.e. polynomial = [ 4 3 2 1 0 ] = p[4]*x^4 + p[2]*x^3 + .. + p[1]*x^1 + p[0]*x^0
        /// a*x^b  --> derived -->  b*a*x^(b-1)
        /// </summary>
        /// <remarks>similar to MATLAB polyder.m</remarks>
        /// <returns>derivative of the polynomial</returns>
        public CCOVector PolyDer()
        {
            CCOVector ret;
            int n = this.Length;            // polynom degree
            if (n < 2)
            {
                ret = new CCOVector(1);     // one zero element
            }
            else
            {
                ret = new CCOVector(n - 1); // reduced degree
                ret.IndexFill(n - 1, -1);   // exponents b
                ret *= this.GetSlice(0, n - 1);
            }
            return ret;
        }

        /// <summary>
        /// RootsCubic
        /// finds the real roots of a cubic polynomial p
        /// Ref. Numerical Recipes in Pascal, Cambridge UP, p. 164
        /// </summary>
        /// <returns>real roots of a cubic polynomial</returns>
        public CCOVector RootsCubic()
        {
            CCOVector a = new CCOVector(this.GetSlice(1, this.Length - 1));
            a /= this[0];                                                       //	a=p(2:end)./(p(1));
            a.IndexingCToPascal();                                              // to keep the algoritms indices
            double Q = (a[1] * a[1] - 3.0 * a[2]) / 9.0;                            //	Q=((a(1)^2)-3*a(2))/9;
            double R = (2.0 * (a[1] * a[1] * a[1]) - 9.0 * a[1] * a[2] + 27.0 * a[3]) / 54.0;//	R=(2*(a(1)^3)-9*a(1)*a(2)+27*a(3))/54;
            double QQQ = Q * Q * Q;
            double RR = R * R;
            CCOVector r;
            if (QQQ - RR >= 0.0)                                                //	if (Q^3-R^2)>=0,
            {   // three real roots
                r = new CCOVector(3);
                double theta = System.Math.Acos(R / System.Math.Sqrt(QQQ)); // theta=acos(R/sqrt(Q^3));
                                                                            // r=-2*sqrt(Q)*cos([theta;theta+2*pi;theta+4*pi]/3)-a(1)/3;
                r[0] = -2.0 * System.Math.Sqrt(Q) * System.Math.Cos((theta) / 3.0) - a[1] / 3.0;
                r[1] = -2.0 * System.Math.Sqrt(Q) * System.Math.Cos((theta + 2.0 * System.Math.PI) / 3.0) - a[1] / 3.0;
                r[2] = -2.0 * System.Math.Sqrt(Q) * System.Math.Cos((theta + 4.0 * System.Math.PI) / 3.0) - a[1] / 3.0;
            }
            else
            {   // one real root
                r = new CCOVector(1);
                // r=-sign(R)*((sqrt(R^2-Q^3)+abs(R))^(1/3)+Q*(sqrt(R^2-Q^3)+abs(R))^(-1/3))-a(1)/3;
                double RQ3 = System.Math.Pow(System.Math.Sqrt(RR - QQQ) + System.Math.Abs(R), 1.0 / 3.0);
                r[0] = -System.Math.Sign(R) * (RQ3 + Q / RQ3) - a[1] / 3.0;
            }
            return r;
        }


        /// <summary>
        /// POLYVAL Evaluate polynomial.
        /// Y = P.POLYVAL(X), when P is a vector of length N+1 whose elements
        /// are the coefficients of a polynomial, is the value of the
        /// polynomial evaluated at X.
        ///
        /// Y = P(1)*X^N + P(2)*X^(N-1) + ... + P(N)*X + P(N+1)
        /// </summary>
        /// <param name="X">polynomial evaluated at X</param>
        /// <returns>the value of the polynomial evaluated at X</returns>
        public double PolyVal(double x)
        {
            int nc = this.Length;
            double y = 0;
            for (int i = 0; i < nc; i++)
            {
                y += this[i] * System.Math.Pow(x, (nc - 1) - i);
            }
            return y;
        }



        #endregion

        #region CDBPersistenceClass stuff

        /// <summary>
        /// static Load vector method for the specific MatrixID
        /// </summary>
        /// <param name="p_VectorID">primary key for the vector</param>
        //public static CCOVector LoadStatic(int p_VectorID)
        //{
        //    return CCOVector.LoadStatic(p_VectorID, null);
        //}

        /// <summary>
        /// static Load vector method for the specific MatrixID
        /// </summary>
        /// <param name="p_VectorID">primary key for the vector</param>
        /// <param name="p_LifecylceContext">lifecycle context to use or null</param>
        //public static CCOVector LoadStatic(int p_VectorID, CDBLifecycleContext p_LifecylceContext)
        //{
        //    CCOVector l_Vector = new CCOVector();
        //    l_Vector.CreateMapper(EDBAction.eShallow, p_LifecylceContext);
        //    l_Vector.Load(p_VectorID);
        //    l_Vector.DeleteMapper(EDBAction.eShallow);
        //    return l_Vector;
        //}

        /// <summary>
        /// Load vector method for the specific MatrixID
        /// </summary>
        /// <param name="p_VectorID">primary key for the vector</param>
        //public virtual void Load(int p_VectorID)
        //{
        //    object[] l_ParList = { p_VectorID };
        //    base.Load(l_ParList, EDBAction.eDeep);
        //}

        #endregion

    } // public class CCOVector
}
