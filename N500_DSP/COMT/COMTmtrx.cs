using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buchi.Core.Math
{
    #region CCOMatrix
    /// <summary>
    /// Matrix Class
    /// 
    /// Matrix[row][column] = element
    /// 
    /// row, column : zero based indices
    ///	row range : 0..nrow-1
    ///	col range : 0..ncol-1
    ///	
    ///	nrow : number of rows
    ///	ncol : number of columns
    /// </summary>
    /// <remarks>
    /// FAQ:
    /// - Submatrix? use GetSlice
    /// </remarks>
    [Serializable()]
    public class CCOMatrix //: CDBPersistenceClass
    {
        #region data member
        /// <summary>
        /// constant for an empty matrix. If a matrix must be returned in a failure case.
        /// </summary>
        public static readonly CCOMatrix EMPTY_MATRIX = new CCOMatrix();        // C++ : static const CCOMatrix EMPTY_MATRIX;

        /// <summary>
        /// number of double elements in use
        /// </summary>
        public static long m_ElementsInUse = 0;

        /// <summary>
        /// maximal double elements during use. max memory peak.
        /// </summary>
        public static long m_ElementsInUseMaxPeak = 0;

        /// <summary>
        /// approximative Floating Point Operation counter.
        /// </summary>
        public static long m_Flops = 0;

        /// <summary>
        /// Matrix as a array of row vectors
        /// </summary>
        internal CCOVector[] col;           // internal (friend) for function dot()

        /// <summary>
        /// Number of rows
        /// </summary>
        int m_nrow;
        /// <summary>
        /// Number of rows
        /// </summary>
        public int nrow
        {
            get { return m_nrow; }
            // set : read only because of resizing
        }


        /// <summary>
        /// Number of columns
        /// </summary>
        int m_ncol;
        /// <summary>
        /// Number of columns
        /// </summary>
        public int ncol
        {
            get { return m_ncol; }
            // set : read only because of resizing
        }


        /// <summary>
        /// Virtual Matrix size
        /// </summary>
        /// <seealso cref="SetVirtualSize"/>
        /// <seealso cref="ResetVirtualSize"/>
        private int m_nrowVirtual;

        /// <summary>
        /// Virtual Matrix size
        /// </summary>
        /// <seealso cref="SetVirtualSize"/>
        /// <seealso cref="ResetVirtualSize"/>
        private int m_ncolVirtual;

        #endregion

        #region methods

        /// <summary>
        /// Matrix size constructor
        /// </summary>
        /// <param name="row"></param>
        /// <param name="col"></param>
        public CCOMatrix(int row, int col)
        {
            Init(row, col);
        }

        /// <summary>
        /// CCOVector to Matrix converter
        /// The Matrix contains one row with the given Vector
        /// </summary>
        public CCOMatrix(CCOVector other)
        {
            Init(1, other.Length);
            col[0] = other;
        }

        /// <summary>
        /// Matrix Constructor with the content of an other Matrix
        /// </summary>
        public CCOMatrix(CCOMatrix other)
        {
            other.CopyTo(this);
        }

        /// <summary>
        /// Copies all Matrix elements to an other Matrix
        /// </summary>
        /// <param name="other"></param>
        public void CopyTo(CCOMatrix other)
        {
            other.Init(this.nrow, this.ncol);
            for (int i = 0; i < nrow; i++)
            {
                for (int k = 0; k < ncol; k++)
                {
                    other.col[i].el[k] = this.col[i].el[k];
                }
            }
        }

        /// <summary>
        /// Init Matrix by size
        /// </summary>
        /// <param name="nr">number of rows</param>
        /// <param name="nc">number of columns</param>
        /// <returns></returns>
        public void Init(int nr, int nc)
        {
            Release();
            if (nr > 0 && nc > 0)
            {
                col = new CCOVector[nr];
                m_ElementsInUse += (nr * nc);
                // measure max peak
                m_ElementsInUseMaxPeak = System.Math.Max(m_ElementsInUseMaxPeak, m_ElementsInUse);

                for (int i = 0; i < nr; i++)
                {
                    col[i] = new CCOVector(nc);
                }
                m_ncol = nc;
                m_nrow = nr;
            }
        }

        /// <summary>
        /// Inits a row by a double array
        /// the matrix must be Init'ed befoer to the correct
        /// final size!!
        /// </summary>
        /// <param name="p_iRow">the row to Init (statrting at 0)</param>
        /// <param name="p_DoubleArray">A double[]</param>
        /// <returns></returns>
        public void InitRow(int p_iRow, double[] p_DoubleArray)
        {
            if (p_iRow >= m_nrow || p_iRow < 0)
            {
                throw new ArgumentException("Index error in InitRow");
            }
            else if (p_DoubleArray.Length != m_ncol)
            {
                throw new ArgumentException("Length of double array is not the same as the matrix's col size");
            }
            else
            {
                // OK we go on.....
                col[p_iRow].Init(p_DoubleArray);
            }
        }


        /// <summary>
        /// Destruktor
        /// </summary>
        ~CCOMatrix()
        {
            m_ElementsInUse -= (ncol * nrow);
        }


        /// <summary>
        /// Release a Matrix
        /// cleans it up for GC
        /// </summary>
        public void Release()
        {
            col = null;
            m_ncol = 0;
            m_nrow = 0;
        }

        /// <summary>
        /// empty init
        /// </summary>
        public void Init()
        {
            Release();
        }

        /// <summary>
        /// default constructor
        /// </summary>
        public CCOMatrix()
        {
            Init();
        }

        /// <summary>
        /// Matrix row index operator. 
        /// Access to a Maxtrix row Vector
        /// </summary>
        public CCOVector this[int i]
        {
            get
            {
                Trace.Assert(i < nrow);
                Trace.Assert(i >= 0);
                return col[i];
            }
            set
            {
                Trace.Assert(i < nrow);
                Trace.Assert(i >= 0);
                col[i] = value;
            }
        }


        /// <summary>
        /// Returns the Matrix in text form.
        /// </summary>
        /// <returns></returns>
        public override String ToString()
        {
            StringBuilder builder = new StringBuilder();
            if (nrow == 0 || ncol == 0)
            {
                builder.Append("EMPTY_MATRIX");
            }
            for (int i = 0; i < nrow; i++)
            {
                for (int j = 0; j < ncol; j++)
                {
                    builder.Append(col[i][j] + " ");
                }
                builder.Append(Environment.NewLine);
            }
            return builder.ToString();
        }

        /// <summary>
        /// Returns the Matrix in text form.
        /// </summary>
        /// <param name="formatter">Formatting string like "E17"</param>
        /// <returns></returns>
        public String ToString(string formatter)
        {
            StringBuilder builder = new StringBuilder();
            if (nrow == 0 || ncol == 0)
            {
                builder.Append("EMPTY_MATRIX");
            }
            for (int i = 0; i < nrow; i++)
            {
                for (int j = 0; j < ncol; j++)
                {
                    builder.Append(col[i][j].ToString(formatter) + " ");
                }
                builder.Append(Environment.NewLine);
            }
            return builder.ToString();
        }


        /// <summary>
        /// Matrix addition. 
        /// Matrices must have the same size.
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>X = L + R</returns>
        public static CCOMatrix operator +(CCOMatrix L, CCOMatrix R)
        {
            if ((L.ncol != R.ncol) || (L.nrow != R.nrow))   // compatible size?
            {
                throw new ArgumentException("Matrix dimensions are not in same size.");
            }
            CCOMatrix X = new CCOMatrix(L.nrow, L.ncol);
            for (int i = 0; i < L.nrow; i++)
            {
                X[i] = L[i] + R[i];                         // row-wise vector addition
            }
            m_Flops += L.nrow * L.ncol;
            return X;
        }


        /// <summary>
        /// Matrix subtraction. 
        /// Matrices must have the same size.
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>X = L - R</returns>
        public static CCOMatrix operator -(CCOMatrix L, CCOMatrix R)
        {
            Trace.Assert(L.ncol == R.ncol && L.nrow == R.nrow);

            if ((L.ncol != R.ncol) || (L.nrow != R.nrow))   // compatible size?
            {
                throw new ArgumentException("Matrix dimensions are not in same size.");
            }
            CCOMatrix X = new CCOMatrix(L.nrow, L.ncol);
            for (int i = 0; i < L.nrow; i++)
            {
                X[i] = L[i] - R[i];                         // row-wise vector subtraction
            }
            m_Flops += L.nrow * L.ncol;
            return X;
        }



        /// <summary>
        /// Compares two Matrices of equality.
        /// Incompatible size will return false.
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>true / false : Matrices are identical in size and value</returns>
        public static bool operator ==(CCOMatrix L, CCOMatrix R)
        {
            if (ReferenceEquals(L, R))
            {
                return true;
            }
            else if (ReferenceEquals(L, null) || ReferenceEquals(R, null))
            {
                return false;
            }
            if ((L.ncol != R.ncol) || (L.nrow != R.nrow))   // compatible size?
            {
                return false;                                   // Matrices are not equal in size
            }
            int i, k;
            for (i = 0; i < L.nrow; i++)
            {
                for (k = 0; k < L.ncol; k++)
                {
                    if (L[i][k] != R[i][k])
                    {
                        return false;                           // Matrices are not equal in at least one value
                    }
                }
            }
            return true;                                        // Matrices are identical
        }

        /// <summary>
        /// Compares two Matrices of NOT equality.
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>true / false : Matrices are NOT identical in size and value</returns>
        public static bool operator !=(CCOMatrix L, CCOMatrix R)
        {
            return !(L == R);                                   // Matrices are not identical
        }

        /// <summary>
        /// Equals / ==
        /// </summary>
        /// <param name="m"></param>
        /// <returns></returns>
        public override bool Equals(object obj)
        {
            // Follow the contract defined on the Object.Equals Method 
            if ((obj == null) || (GetType() != obj.GetType())) { return false; }
            return (this == (CCOMatrix)obj);
        }

        /// <summary>
        /// GetHashCode
        /// </summary>
        /// <returns></returns>
        public override int GetHashCode()
        {
            return nrow ^ ncol;     // XOR analog to CPoint
        }



        /// <summary>
        /// Matrix Multiplication
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>X = L * R</returns>
        public static CCOMatrix operator *(CCOMatrix L, CCOMatrix R)
        {
            if (L.ncol != R.nrow)   // are dimesions equal?
            {
                throw new ArgumentException("Matrix dimensions are not valid for multiplication.");
            }

            // Precalculation of the numbers of opeations for the multiplication
            int FlopsForMultiplication = (L.nrow * R.ncol * L.ncol) * 2;  // ADD und MUL
            m_Flops = m_Flops + FlopsForMultiplication;

            CCOMatrix res = new CCOMatrix(L.nrow, R.ncol);              // Result Matrix Init                    

            int NROW = L.nrow;
            int NCOL = L.ncol;
            int OTHER_NCOL = R.ncol;

            // loop nesting is optimized!
            // performance optimized element access with .el[]
            double sum;
            for (int j = 0; j < OTHER_NCOL; j++)
            {
                for (int i = 0; i < NROW; i++)
                {
                    sum = 0.0;
                    for (int k = 0; k < NCOL; k++)
                    {
                        sum += L.col[i].el[k] * R.col[k].el[j];
                    }
                    res.col[i].el[j] = sum;
                }
            }
            return res;
        }

        /// <summary>
        /// MultiplyTranspose
        /// Multiply this Matrix with the transposed MatB Matrix
        /// </summary>
        /// <param name="MatB">internally transposed before multiplication</param>
        /// <param name="MatRes">Result</param>
        public void MultiplyTranspose(CCOMatrix MatB, CCOMatrix MatRes)
        {
            if ((ncol != MatB.ncol) || (MatB.nrow != MatRes.ncol) || (MatRes.nrow != nrow))
            {
                throw new ArgumentException("Matrix dimensions are not valid for MultiplyTranspose.");
            }
            for (int i = 0; i < nrow; i++)
            {
                for (int j = 0; j < MatB.nrow; j++)
                {
                    MatRes.col[i].el[j] = this.col[i].Dot(MatB.col[j]);
                }
            }
            m_Flops += (nrow * MatB.nrow * ncol) * 2;
        }



        /// <summary>
        /// TransposeMultiply
        /// Multiply this Matrix transposed with the MatB Matrix
        /// </summary>
        /// <param name="MatB"></param>
        /// <param name="MatRes">Result</param>
        public void TransposeMultiply(CCOMatrix MatB, CCOMatrix MatRes)
        {
            if ((nrow != MatB.nrow) || (MatB.ncol != MatRes.ncol) || (MatRes.nrow != ncol))
            {
                throw new ArgumentException("Matrix dimensions are not valid for TransposeMultiply.");
            }
            double sum;
            for (int i = 0; i < ncol; i++)
            {
                for (int j = 0; j < MatB.ncol; j++)
                {
                    sum = 0.0;
                    for (int k = 0; k < nrow; k++)
                    {
                        sum += col[k].el[i] * MatB.col[k].el[j];
                    }
                    MatRes.col[i].el[j] = sum;
                }
            }
            m_Flops = m_Flops + (nrow * MatB.nrow * ncol) * 2;
        }




        /// <summary>
        /// Saves the Maxrix as ASCII to file.
        /// Matrix Row is a text line.
        /// </summary>
        /// <param name="FileName"></param>
        public virtual void Save(string FileName)
        {
            StreamWriter stream = File.CreateText(FileName);
            stream.Write(this.ToString());
            stream.Close();
        }

        /// <summary>
        /// Reads a ASCII file with a formatted rectangular value block into the matrix.
        /// The values have to be space separated.
        /// The number of rows and columns is estimated on the rectangular value block.
        /// </summary>
        /// <param name="FileName"></param>
        public virtual void Load(string FileName)
        {
            char[] SEPERATOR = { ' ' };
            int Words = 0;
            string Line;
            StreamReader stream = File.OpenText(FileName);
            Line = stream.ReadLine();
            if (Line == null)
            {
                Trace.Assert(false, "Empty File!");
                return;
            }

            // estimate values per row
            Line = Line.Trim();
            string[] RowValues = Line.Split(SEPERATOR, StringSplitOptions.RemoveEmptyEntries); // TM 080729 do not count empty lines as one word
            Words = RowValues.GetLength(0);

            if (Words == 0) // TM 080729 no values in first line -> no matrix
            {
                Trace.Assert(false, "Empty File!");
                return;
            }

            // estimate number of lines of the file
            int rows = 0;							// start counting with the line above
            while (Line != null)		            // count to the end of file
            {
                Line = Line.Trim();
                RowValues = Line.Split(SEPERATOR, StringSplitOptions.RemoveEmptyEntries);
                if (RowValues.GetLength(0) == Words)
                {
                    rows++;
                }
                Line = stream.ReadLine();
            }
            stream.Close();

            // read the Matrix
            this.Init(rows, Words);             // matrix allocation
            stream = File.OpenText(FileName);       // open input file
            for (int i = 0; i < rows; i++)
            {
                Line = stream.ReadLine();

                // split the line
                Line = Line.Trim();
                RowValues = Line.Split(SEPERATOR, StringSplitOptions.RemoveEmptyEntries); // TM 080729
                Words = RowValues.GetLength(0);

                for (int j = 0; j < Words; j++)
                {
                    this[i][j] = Convert.ToDouble(RowValues[j]);
                }
            }
            stream.Close();
        }





        /// <summary>
        /// Determinant of a Matrix
        /// The Matrix must be a square Matrix.
        /// The determinant of an LU decomposed matrix is just the product of the diagonal elements,
        /// Matrix muss quadratisch sein.
        /// Flops estimated : N+N*N/2
        /// </summary>
        /// <param name="d">Determinant of a Matrix</param>
        /// <returns>false if the matrix is singular</returns>
        public bool Det(double d)
        {
            if (this.ncol != this.nrow)
            {
                Trace.Assert(false, "Matrix must be square !");
                return false;
            }
            int n = this.ncol;
            CCOVector indx = new CCOVector(n);
            CCOMatrix a = new CCOMatrix(this);
            bool ret = Ludcmp(a, n, indx, d);       // This returns d as +/- 1
            if (ret == false)
            {
                Trace.Assert(false, "Matrix is Singular !");
                return false;
            }
            for (int j = 0; j < n; j++)
            {
                d *= a.col[j].el[j];
            }
            m_Flops += n + n * n / 2;
            return true;
        }


        /// <summary>
        /// Inverse of a Matrix 
        /// 
        /// Using the above LU decomposition and backsubstitution routines, it is com-pletely straightforward to 
        /// find the inverse of a matrix column by column. (there is no better way to do it)
        ///
        /// Bei N*N Matrix ergibt sich etwa N*N*N/2 FLOPS (war aus Literertur aber nicht genau ersichtlich !)
        ///
        /// Reference: NUMERICAL RECIPIES IN PASCAL/C, P. 46
        /// Method : LU Decomposition
        /// </summary>
        /// <param name="Inv">returns the Inverse Matrix</param>
        /// <returns>true if the inverse Matrix has been calculated.</returns>
        public bool Inverse(CCOMatrix Inv)
        {
            if (this.ncol != this.nrow)
            {
                Trace.Assert(false, "Matrix must be square !");
                return false;
            }
            int n = this.ncol;
            double d = 0.0;
            CCOMatrix a = new CCOMatrix(this);
            CCOMatrix y = new CCOMatrix(n, n);
            CCOVector indx = new CCOVector(n);
            CCOVector column = new CCOVector(n);

            bool ret = Ludcmp(a, n, indx, d);
            if (ret == false)
            {
                Trace.Assert(false, "Matrix is Singular !");
                return false;                               // Matrix is Singular !
            }
            for (int j = 0; j < n; j++)
            {
                column.Zero();
                column[j] = 1.0;
                Lubksb(a, n, indx, column);

                // y.SetColVector( j, column );
                for (int i = 0; i < n; i++)
                {
                    y.col[i].el[j] = column[i];
                }
            }
            y.CopyTo(Inv);                              // result
            m_Flops += n * n * n / 2;
            return true;                                    // Matrix inversion successful
        }


        /// <summary>
        /// Ludcmp - LU decomposition
        /// This routine is used in combination with lubksb to solve linear equations or invert a matrix. 
        /// Given a matrix a[1..n][1..n], this routine replaces it by the LU decomposition of a rowwise permutation of itself. 
        /// a and n are input. 
        /// a is output, arranged as in equation (2.3.14) above; 
        /// </summary>
        /// <param name="a"></param>
        /// <param name="n"></param>
        /// <param name="indx">indx[1..n] is an output vector that records the row permutation effected by the partial pivoting.</param>
        /// <param name="d">d is output as +/-1 depending on whether the number of row interchanges was even or odd, respectively.</param>
        /// <returns></returns>
        public bool Ludcmp(CCOMatrix a, int n, CCOVector indx, double d)
        {
            double tiny = 1.0e-20;                      // 1.0e-20;
            int k, j, i;
            int imax = -1;                              // -1 for no valid index
            double sum, dum, big;
            CCOVector vv = new CCOVector(n);            // vv stores the implicit scaling of each row.
            d = 1.0;                                    // No row interchanges yet. 
            for (i = 0; i < n; i++)                     // Loop over rows to get the implicit scaling information.
            {
                big = 0.0;
                for (j = 0; j < n; j++)
                {
                    if (System.Math.Abs(a.col[i][j]) > big)
                    {
                        big = System.Math.Abs(a.col[i][j]);
                    }
                }
                if (0.0 == big) { return false; }       // No nonzero largest element.
                vv[i] = 1.0 / big;                      // Save the scaling.
            }
            for (j = 0; j < n; j++)                     // This is the loop over columns of Crout's method.
            {
                for (i = 0; i < j; i++)
                {                                       // This is equation (2.3.12) except for i = j. 
                    sum = a.col[i][j];
                    for (k = 0; k < i; k++)
                    {
                        sum -= a.col[i][k] * a.col[k][j];
                    }
                    a.col[i][j] = sum;
                }
                big = 0.0;                              // Initialize for the search for largest pivot element. 
                for (i = j; i < n; i++)                 // This is i = j of equation (2.3.12) and i = j +1: ::N of equation (2.3.13). 
                {
                    sum = a.col[i][j];
                    for (k = 0; k < j; k++)
                    {
                        sum -= a.col[i][k] * a.col[k][j];
                    }
                    a.col[i][j] = sum;

                    dum = vv[i] * System.Math.Abs(sum);
                    if (dum >= big)                 // Is the Figure of merit for the pivot better than the best so far? 
                    {
                        big = dum;
                        imax = i;
                    }
                }
                if (j != imax)                          // Do we need to interchange rows? 
                {
                    for (k = 0; k < n; k++)             // Yes, do so... 
                    {
                        dum = a.col[imax][k];
                        a.col[imax][k] = a.col[j][k];
                        a.col[j][k] = dum;
                    }
                    d = -d;                             // ...and change the parity of d. 
                    vv[imax] = vv[j];                   // Also interchange the scale factor.
                }
                indx[j] = imax;
                if (0.0 == a.col[j][j])
                {
                    a.col[j][j] = tiny;
                }                                       // If the pivot element is zero the matrix is singular (at least to the precision of the algorithm). 
                                                        // For some applications on singular matrices, it is desirable to substitute TINY for zero. 
                if (j != (n - 1))                       // Now, Finally, divide by the pivot element. 
                {
                    dum = 1.0 / a.col[j][j];
                    for (i = j + 1; i < n; i++)
                    {
                        a.col[i][j] *= dum;
                    }
                }
            }                                           // Go back for the next column in the reduction.
            return true;
        }

        /// <summary>
        /// Lubksb 
        /// 
        /// Solves the set of n linear equations A . X = B. Herea[1..n][1..n] is input, 
        /// not as the matrix A but rather as its LU decomposition, determined by the routine ludcmp. 
        /// indx[1..n] is input as the permutation vector returned by ludcmp. 
        /// b[1..n] is input as the right-hand side vector B, and returns with the solution vector X. 
        /// a, n, and indx are not modified by this routine and can be left in place for successive 
        /// calls with different right-hand sides b. This routine takes into account the possibility 
        /// that b will begin with many zero elements, so it is e.cient for use in matrix inversion. 
        /// </summary>
        /// <param name="a"></param>
        /// <param name="n"></param>
        /// <param name="indx"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        bool Lubksb(CCOMatrix a, int n, CCOVector indx, CCOVector b)
        {
            int j, ip, ii, i;
            double sum;
            ii = -1;                                        // initialisierung für keinen gültigen Index.
            for (i = 0; i < n; i++)                         // When ii is set to a positive value, it will become the index of the frst 
                                                            // nonvanishing element of b. We now do the forward substitution, equation (2.3.6). 
                                                            // The only new wrinkle is to unscramble the permutation as we go. 
            {
                ip = (int)(indx[i]);
                sum = b[ip];
                b[ip] = b[i];
                if (ii > -1)
                {
                    for (j = ii; j < i; j++)
                    {
                        sum -= a.col[i][j] * b[j];
                    }
                }
                else if (0.0 != sum) { ii = i; }            // A nonzero element was encountered, so from now on we will 
                                                            // have to do the sums in the loop above. 
                b[i] = sum;
            }
            for (i = n - 1; i >= 0; i--)                            // Now we do the backsubstitution, equation (2.3.7). 

            {
                sum = b[i];
                for (j = i + 1; j < n; j++)
                {
                    sum -= a.col[i][j] * b[j];              // Store a component of the solution vector X. 
                }
                b[i] = sum / a.col[i][i];
            }                                               // All done! 
            return true;
        }





        /// <summary>
        /// Min
        /// </summary>
        /// <returns>minimum value of all matrix elements</returns>
        public double Min()
        {
            double m = col[0].el[0];
            for (int i = 0; i < nrow; i++)
            {
                m = System.Math.Min(m, col[i].Min());
            }
            return m;
        }

        /// <summary>
        /// Max
        /// </summary>
        /// <returns>maximum value of all matrix elements</returns>
        public double Max()
        {
            double m = col[0].el[0];
            for (int i = 0; i < nrow; i++)
            {
                m = System.Math.Max(m, col[i].Max());
            }
            return m;
        }


        /// <summary>
        /// MaxAt
        /// </summary>
        /// <param name="y">last row where Max was found</param>
        /// <param name="x">last col where Max was found</param>
        public void MaxAt(out int y, out int x)
        {
            CCOVector Posi = new CCOVector(nrow);       // indices
            CCOVector Posv = new CCOVector(nrow);       // values
            int pos;
            for (int i = 0; i < nrow; i++)
            {
                Posv[i] = col[i].MaxAt(out pos);        // values  of maximas over all rows
                Posi[i] = (double)pos;                  // indizes of maximas over all rows
            }
            Posv.MaxAt(out y);
            x = (int)(Posi[y]);
        }

        /// <summary>
        /// MinAt
        /// </summary>
        /// <param name="y">last row where Min was found</param>
        /// <param name="x">last col where Min was found</param>
        public void MinAt(out int y, out int x)
        {
            CCOVector Posi = new CCOVector(nrow);       // indices
            CCOVector Posv = new CCOVector(nrow);       // values
            int pos;
            for (int i = 0; i < nrow; i++)
            {
                Posv[i] = col[i].MinAt(out pos);        // values  of minimas over all rows
                Posi[i] = (double)pos;                  // indizes of minimas over all rows
            }
            Posv.MinAt(out y);
            x = (int)(Posi[y]);
        }

        /// <summary>
        /// Calculate Mean value vector
        /// </summary>
        /// <returns></returns>
        public CCOVector Mean()
        {
            CCOVector Res = new CCOVector(ncol);
            for (int i = 0; i < nrow; i++)
            {
                Res += col[i];
            }
            Res /= nrow;
            return Res;
        }

        /// <summary>
        /// calculates the standard deviation vector
        /// </summary>
        /// <returns></returns>
        public CCOVector Sdev()
        {
            CCOVector Res = new CCOVector(ncol);
            CCOVector Tmp = new CCOVector();
            for (int i = 0; i < nrow; i++)
            {
                Tmp = GetColVector(i);
                Res[i] = Tmp.Sdev();
            }
            return Res;
        }


        /// <summary>
        /// Set Column Vector into a Matrix.
        /// Matrix row dimension must be equal with Column length.
        /// </summary>
        /// <param name="ColIndex">Column Index</param>
        /// <param name="Column">Vector</param>
        public void SetColVector(int ColIndex, CCOVector Column)
        {
            if (Column.Length != nrow)
            {
                throw new ArgumentException("Matrix row dimension must be equal with Column length.");
            }
            for (int i = 0; i < nrow; i++)
            {
                col[i].el[ColIndex] = Column[i];
            }
        }

        /// <summary>
        /// Set Row Vector into a Matrix.
        /// Matrix column dimension must be equal with Column length.
        /// </summary>
        /// <param name="ColIndex">Row Index</param>
        /// <param name="Column">Vector</param>
        public void SetRowVector(int RowIndex, CCOVector Row)
        {
            if (Row.Length != this.ncol)
            {
                throw new ArgumentException("Matrix column dimension must be equal with Column length.");
            }
            Row.CopyTo(this.col[RowIndex]);
        }

        /// <summary>
        /// Matrix Size temporarily set to a smaller size for partwise Matrix operations. 
        /// I.e. used for Matrix multiplication with reduced number of Factors.
        /// A ResetVirtualSize has to follow after the operation.
        /// </summary>
        /// <seealso cref="ResetVirtualSize"/> 
        /// <param name="p_y"></param>
        /// <param name="p_x"></param>
        public void SetVirtualSize(int p_row, int p_col)
        {
            if (p_row > nrow || p_col > ncol)
            {
                Trace.Assert(false, "the virtual matrix size can not be bigger that the original matrix size");
                return;
            }
            if (p_row == 0 || p_col == 0)
            {
                Trace.Assert(false, "the virtual matrix size can not be 0 in any dimension");
                return;
            }
            // save original sizes
            m_nrowVirtual = m_nrow;
            m_ncolVirtual = m_ncol;

            // set the virtual size, for all depending Matrix operations
            m_nrow = p_row;
            m_ncol = p_col;
        }

        /// <summary>
        /// Undo the SetVirtualSize.
        /// Sets the Matrix size to its original size.
        /// </summary>
        /// <seealso cref="SetVirtualSize"/>
        public void ResetVirtualSize()
        {
            if (m_ncolVirtual == 0 || m_nrowVirtual == 0)
            {
                Trace.Assert(false, "the virtual matrix size can not be reseted. The reason can be a forgotten SetVirtualSize");
                return;
            }
            m_ncol = m_ncolVirtual;
            m_nrow = m_nrowVirtual;
        }


        /// <summary>
        /// Sets all unselected Matrix elements to the given value.
        /// The selection is given by row and column selection vectors.
        /// Selected is equal 1.
        /// Selected elements are all these tey have a row AND a colum selection.
        /// </summary>
        /// <param name="p_Value">value set in all selected Matrix elements</param>
        /// <param name="p_XSel">Column Selection vector</param>
        /// <param name="p_YSel">Row Selection Vector</param>
        public void SetUnselectedToValue(double p_Value, CCOVector p_XSel, CCOVector p_YSel)
        {
            const double SELECTED = 1.0;
            int X = p_XSel.Length;
            int Y = p_YSel.Length;
            if (X == 0 || Y == 0) { return; }       // nothing to do
            int x, y;
            for (y = 0; y < Y; y++)             // row-wise cheching
            {
                for (x = 0; x < X; x++)
                {
                    if (p_XSel.el[x] != SELECTED ||      // if only one selection is unselected, the value will be set
                        p_YSel.el[y] != SELECTED)
                    {
                        this.col[y].el[x] = p_Value;
                    }
                }
            }
        }

        /// -------------------------------------------------------------------
        /// <summary>
        /// Resizes the existing matrix to the wanted dimension. If only the 
        /// row number is changed, this can be done effiziently by adding
        /// or deleting row vectors.
        /// </summary>
        /// <param name="p_Row">Number of rows</param>
        /// <param name="p_Col">Number of columns</param>
        public virtual void Resize(int p_Row, int p_Col)
        {
            Debug.Assert(p_Row >= 0 && p_Col >= 0);
            int RowSize = 0;

            // resize row dimension (resize the vector array)
            if (p_Row != m_nrow)
            {
                // get the smaller number for the row size
                if (p_Row > m_nrow)
                {
                    RowSize = m_nrow;
                }
                else
                {
                    RowSize = p_Row;
                }

                // copy elements from existing array to new array
                CCOVector[] newCol = new CCOVector[p_Row];
                Array.Copy(col, 0, newCol, 0, RowSize);
                col = newCol;
                m_nrow = p_Row;
            }

            // resize coloumn dimension - resize each column vector and add new vectors 
            // if needed
            if (p_Col != m_ncol || RowSize != 0)
            {
                for (int i = 0; i < m_nrow; i++)
                {
                    if (!(col[i] != null))
                    {
                        // add a new column vector
                        col[i] = new CCOVector(p_Col);
                    }
                    else
                    {
                        // resize existing column vector
                        if (p_Col != col[i].Length)
                        {
                            col[i].Resize(p_Col);
                        }
                    }
                    m_ncol = p_Col;
                } // for
            } // if
        } // Resize

        /// -------------------------------------------------------------------
        /// <summary>
        /// Returns a new matrix with the wanted dimensions. All elements
        /// are copied from the existing matrix within the given range. If
        /// a dimension is out of range of the existing matrix, this range
        /// will be filled with 0.0.
        /// </summary>
        /// <param name="p_RowStart">Start of Row</param>
        /// <param name="p_RowLength">Length of Row</param>
        /// <param name="p_ColStart">Start of Column</param>
        /// <param name="p_ColLength">Length of Column</param>
        /// <returns>Returns a new matrix with the wanted dimensions</returns>
        public virtual CCOMatrix GetSlice(int p_RowStart, int p_RowLength, int p_ColStart, int p_ColLength)
        {
            Debug.Assert(p_RowStart >= 0 && p_RowLength >= 0 && p_ColStart >= 0 && p_ColLength >= 0);

            // build new matrix with new dimensions
            CCOMatrix Slice = new CCOMatrix(p_RowLength, p_ColLength);

            // find row and col end for coping elements
            int RowEnd;
            int ColEnd;

            if (this.nrow < p_RowStart + p_RowLength)
            { RowEnd = this.nrow; }
            else
            { RowEnd = p_RowStart + p_RowLength; }

            if (this.ncol < p_ColStart + p_ColLength)
            { ColEnd = this.ncol; }
            else
            { ColEnd = p_ColStart + p_ColLength; }

            // copy all elements from existing matrix
            for (int Row = p_RowStart; Row < RowEnd; Row++)
            {
                for (int Col = p_ColStart; Col < ColEnd; Col++)
                {
                    Slice[Row - p_RowStart][Col - p_ColStart] = this[Row][Col];
                } // for
            } // for

            return Slice;
        }


        /// <summary>
        /// Get a column vector from a matrix.
        /// </summary>
        /// <param name="ColIndex">Column Index</param>
        public CCOVector GetColVector(int p_ColIndex)
        {
            CCOVector Column = new CCOVector(nrow);
            for (int i = 0; i < nrow; i++)
            {
                Column[i] = col[i].el[p_ColIndex];
            }
            return Column;
        }

        /// <summary>
        /// Get a row vector from a matrix.
        /// </summary>
        /// <param name="ColIndex">Row Index</param>
        public CCOVector GetRowVector(int p_RowIndex)
        {
            CCOVector Row = new CCOVector(ncol);
            col[p_RowIndex].CopyTo(Row);
            return Row;
        }

        /// <summary>
        /// Matrix Transposition
        /// </summary>
        /// <returns>transposed matrix</returns>
        public CCOMatrix Transpose()
        {
            CCOMatrix Transposed = new CCOMatrix(ncol, nrow);   // row and col swapped!
            for (int i = 0; i < nrow; i++)                          // all row of the original
            {
                Transposed.SetColVector(i, this[i]);            // copy this.row to Transposed.col 
            }
            return Transposed;
        }

        /// <summary>
        /// Remove the wanted row from the matrix
        /// </summary>
        /// <param name="ColIndex">Row Index</param>
        public void RemoveRow(int p_RowIndex)
        {
            Debug.Assert(p_RowIndex < nrow);

            if (p_RowIndex < nrow)
            {
                // remove the selected row
                for (int i = p_RowIndex; i < m_nrow - 1; i++)
                {
                    col[i] = col[i + 1];
                }
                Resize(nrow - 1, ncol);
            }
        }

        /// <summary>
        /// Matrix Multiplication by scalar value
        /// </summary>
        /// <param name="L">Matrix</param>
        /// <param name="d">scalar value</param>
        /// <returns>X = L * d</returns>
        public static CCOMatrix operator *(CCOMatrix L, double d)
        {
            // Precalculation of the numbers of opeations for the multiplication
            int FlopsForMultiplication = (L.nrow * L.ncol);
            m_Flops = m_Flops + FlopsForMultiplication;

            CCOMatrix res = new CCOMatrix(L.nrow, L.ncol);
            // performance optimized element access with .el[]
            for (int j = 0; j < L.nrow; j++)
            {
                for (int i = 0; i < L.ncol; i++)
                {
                    res.col[j].el[i] = L.col[j].el[i] * d;
                }
            }
            return res;
        }


        /// <summary>
        /// Vandermonde matrix.
        /// this will be initialices as Vandermonde matrix.
        /// m*(n+1) Vandermonde matrix size.
        /// m is size of x
        /// 
        /// A Vandermonde matrix is a type of matrix that arises in the polynomial least squares fitting, 
        /// Lagrange interpolating polynomials (Hoffman and Kunze p. 114), and the reconstruction of a 
        /// statistical distribution from the distribution's moments (von Mises 1964; Press et al. 1992, p. 83).
        /// </summary>
        /// <param name="n">n</param>
        /// <param name="x">x vector</param>
        public void Vandermonde(int n, CCOVector x)
        {
            int m = x.Length;
            this.Init(m, n + 1);

            CCOVector pot = new CCOVector(m);
            pot.Fill(1.0);

            for (int i = 0; i < n + 1; i++)
            {
                //				this.SetColVector( i, pot );	// Mathematica style
                this.SetColVector(n - i, pot);  // Matlab style
                pot *= x;
            }
            // m_Flops = m_Flops + m*n; // Flops are counted in CCOVector !
        }


        #endregion

        #region CDBPersistenceClass stuff

        /// <summary>
        /// static Load matrix method for the specific MatrixID
        /// </summary>
        /// <param name="p_MatrixID">primary key for the vector</param>
        //public static CCOMatrix LoadStatic(int p_MatrixID)
        //{
        //    return CCOMatrix.LoadStatic(p_MatrixID, null);
        //}

        /// <summary>
        /// static Load matrix method for the specific MatrixID
        /// </summary>
        /// <param name="p_MatrixID">primary key for the vector</param>
        /// <param name="p_LifecylceContext">lifecycle context to use or null</param>
        //public static CCOMatrix LoadStatic(int p_MatrixID, CDBLifecycleContext p_LifecylceContext)
        //{
        //    CCOMatrix l_Matrix = new CCOMatrix();
        //    l_Matrix.CreateMapper(EDBAction.eShallow, p_LifecylceContext);
        //    l_Matrix.Load(p_MatrixID);
        //    l_Matrix.DeleteMapper(EDBAction.eShallow);
        //    return l_Matrix;
        //}

        /// <summary>
        /// Load matrix method for the specific MatrixID
        /// </summary>
        /// <param name="p_MatrixID">primary key for the matrix</param>
        //public virtual void Load(int p_MatrixID)
        //{
        //    object[] l_ParList = { p_MatrixID };
        //    base.Load(l_ParList, EDBAction.eDeep);
        //}


        /// <summary>
        /// Abs
        /// </summary>
        /// <returns>Abs all matrix elements</returns>
        public CCOMatrix Abs()
        {
            CCOMatrix ret = new CCOMatrix(this);
            for (int i = 0; i < nrow; i++)
            {
                ret.col[i] = ret.col[i].Abs();
            }
            return ret;
        }



        #endregion

    } // public class CCOMatrix
    #endregion CCOMatrix

    #region CCOQRDecomposition

    /// <summary>
    /// QR Decomposition.
    /// 
    /// For an m-by-n matrix A with m >= n, the QR decomposition is an m-by-n
    /// orthogonal matrix Q and an n-by-n upper triangular matrix R so that
    /// A = Q*R.
    /// 
    /// The QR decompostion always exists, even if the matrix does not have
    /// full rank, so the constructor will never fail.  The primary use of the
    /// QR decomposition is in the least squares solution of nonsquare systems
    /// of simultaneous linear equations.  This will fail if IsFullRank()
    /// returns false.
    /// </summary>
    public class CCOQRDecomposition
    {
        #region data member

        /// <summary>
        /// Array for internal storage of decomposition.
        /// serial internal array storage.
        /// </summary>
        private CCOMatrix QR;

        /// <summary>
        /// Row and column dimensions.
        /// serial column dimension.
        /// serial row dimension.
        /// </summary>
        private int m, n;

        /// <summary>
        /// Array for internal storage of diagonal of R.
        /// serial diagonal of R.
        /// </summary>
        private double[] Rdiag;

        #endregion //  Class variables

        #region Constructor

        /// <summary>
        /// QR Decomposition, computed by Householder reflections.
        /// </summary>
        /// <param name="A">Rectangular matrix</param>
        /// <returns>Structure to access R and the Householder vectors and compute Q.</returns>
        public CCOQRDecomposition(CCOMatrix A)
        {
            // Initialize.
            QR = new CCOMatrix(A);
            m = A.nrow;
            n = A.ncol;
            Rdiag = new double[n];

            // Main loop.
            for (int k = 0; k < n; k++)
            {
                // Compute 2-norm of k-th column without under/overflow.
                double nrm = 0;
                for (int i = k; i < m; i++)
                {
                    nrm = Maths.Hypot(nrm, QR[i][k]);
                }

                if (nrm != 0.0)
                {
                    // Form k-th Householder vector.
                    if (QR[k][k] < 0)
                    {
                        nrm = -nrm;
                    }
                    for (int i = k; i < m; i++)
                    {
                        QR[i][k] /= nrm;
                    }
                    QR[k][k] += 1.0;

                    // Apply transformation to remaining columns.
                    for (int j = k + 1; j < n; j++)
                    {
                        double s = 0.0;
                        for (int i = k; i < m; i++)
                        {
                            s += QR[i][k] * QR[i][j];
                        }
                        s = (-s) / QR[k][k];
                        for (int i = k; i < m; i++)
                        {
                            QR[i][j] += s * QR[i][k];
                        }
                    }
                }
                Rdiag[k] = -nrm;
            }
        }

        #endregion //  Constructor

        #region Public Properties

        /// <summary>Is the matrix full rank?</summary>
        /// <returns>true if R, and hence A, has full rank.</returns>
        virtual public bool FullRank
        {
            get
            {
                for (int j = 0; j < n; j++)
                {
                    if (Rdiag[j] == 0)
                        return false;
                }
                return true;
            }
        }

        /// <summary>Return the Householder vectors</summary>
        /// <returns>Lower trapezoidal matrix whose columns define the reflections</returns>
        virtual public CCOMatrix H
        {
            get
            {
                CCOMatrix H = new CCOMatrix(m, n);
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (i >= j)
                        {
                            H[i][j] = QR[i][j];
                        }
                        else
                        {
                            H[i][j] = 0.0;
                        }
                    }
                }
                return H;
            }

        }

        /// <summary>Return the upper triangular factor</summary>
        /// <returns>R</returns>
        virtual public CCOMatrix R
        {
            get
            {
                CCOMatrix R = new CCOMatrix(n, n);
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (i < j)
                        {
                            R[i][j] = QR[i][j];
                        }
                        else if (i == j)
                        {
                            R[i][j] = Rdiag[i];
                        }
                        else
                        {
                            R[i][j] = 0.0;
                        }
                    }
                }
                return R;
            }
        }

        /// <summary>Generate and return the (economy-sized) orthogonal factor</summary>
        /// <returns>Q</returns>
        virtual public CCOMatrix Q
        {
            get
            {
                CCOMatrix Q = new CCOMatrix(m, n);
                for (int k = n - 1; k >= 0; k--)
                {
                    for (int i = 0; i < m; i++)
                    {
                        Q[i][k] = 0.0;
                    }
                    Q[k][k] = 1.0;
                    for (int j = k; j < n; j++)
                    {
                        if (QR[k][k] != 0)
                        {
                            double s = 0.0;
                            for (int i = k; i < m; i++)
                            {
                                s += QR[i][k] * Q[i][j];
                            }
                            s = (-s) / QR[k][k];
                            for (int i = k; i < m; i++)
                            {
                                Q[i][j] += s * QR[i][k];
                            }
                        }
                    }
                }
                return Q;
            }

        }
        #endregion //  Public Properties

        #region Public Methods

        /// <summary>Least squares solution of A*X = B</summary>
        /// <param name="B">A Matrix with as many rows as A and any number of columns.</param>
        /// <returns>X that minimizes the two norm of Q*R*X-B.</returns>
        /// <exception cref="System.ArgumentException"> Matrix row dimensions must agree.</exception>
        /// <exception cref="System.SystemException"> Matrix is rank deficient.</exception>
        public virtual CCOMatrix Solve(CCOMatrix B)
        {
            if (B.nrow != m)
            {
                throw new System.ArgumentException("CCOMatrix row dimensions must agree.");
            }
            if (!this.FullRank)
            {
                throw new System.SystemException("CCOMatrix is rank deficient.");
            }

            // Copy right hand side
            int nx = B.ncol;
            CCOMatrix X = new CCOMatrix(B);

            // Compute Y = transpose(Q)*B
            for (int k = 0; k < n; k++)
            {
                for (int j = 0; j < nx; j++)
                {
                    double s = 0.0;
                    for (int i = k; i < m; i++)
                    {
                        s += QR[i][k] * X[i][j];
                    }
                    s = (-s) / QR[k][k];
                    for (int i = k; i < m; i++)
                    {
                        X[i][j] += s * QR[i][k];
                    }
                }
            }
            // Solve R*X = Y;
            for (int k = n - 1; k >= 0; k--)
            {
                for (int j = 0; j < nx; j++)
                {
                    X[k][j] /= Rdiag[k];
                }
                for (int i = 0; i < k; i++)
                {
                    for (int j = 0; j < nx; j++)
                    {
                        X[i][j] -= X[k][j] * QR[i][k];
                    }
                }
            }

            //return (new GeneralMatrix(X, n, nx).GetMatrix(0, n - 1, 0, nx - 1));
            return X.GetSlice(0, n, 0, nx);
        }

        #endregion //  Public Methods
    }
    #endregion CCOQRDecomposition

    #region Internal Maths utility
    internal class Maths
    {
        /// <summary>
        ///  sqrt(a^2 + b^2) without under/overflow.
        /// </summary>
        /// <param name="a">a</param>
        /// <param name="b">b</param>
        /// <returns>sqrt(a^2 + b^2)</returns>
        public static double Hypot(double a, double b)
        {
            double r;
            if (System.Math.Abs(a) > System.Math.Abs(b))
            {
                r = b / a;
                r = System.Math.Abs(a) * System.Math.Sqrt(1 + r * r);
            }
            else if (b != 0)
            {
                r = a / b;
                r = System.Math.Abs(b) * System.Math.Sqrt(1 + r * r);
            }
            else
            {
                r = 0.0;
            }
            return r;
        }
    }
    #endregion   // Internal Maths utility
}
