using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buchi.Core.Math
{
    /// <summary>
    /// Complex Vector
    /// </summary>
    public class CCOComplexVector   // ClassCOreComplexVector
    {
        /// <summary>
        /// Real Part of Complex Vector
        /// </summary>
        private CCOVector m_Real;
        public CCOVector Real
        {
            get
            {
                return m_Real;
            }
            set
            {
                m_Real = value;
            }
        }

        /// <summary>
        /// Imaginary Part of Complex Vector
        /// </summary>
        private CCOVector m_Imag;
        public CCOVector Imag
        {
            get
            {
                return m_Imag;
            }
            set
            {
                m_Imag = value;
            }
        }

        /// <summary>
        /// Constructor with Real and Imag Parts
        /// </summary>
        /// <param name="Real"></param>
        /// <param name="Imag"></param>
        public CCOComplexVector(CCOVector Real, CCOVector Imag)
        {
            Trace.Assert(Real.Length == Imag.Length, "Real and Imag part have to be in same size.");
            m_Imag = Imag;
            m_Real = Real;
        }

        /// <summary>
        /// Constructor with Real Part only
        /// </summary>
        /// <param name="Real"></param>
        /// <param name="Imag"></param>
        public CCOComplexVector(CCOVector Real)
        {
            m_Real = Real;
            m_Imag = new CCOVector(Real.Length);
        }


        /// <summary>
        /// Constructor by size
        /// </summary>
        /// <param name="size">number of complex vector elements</param>
        public CCOComplexVector(int size)
        {
            Init(size);
        }

        /// <summary>
        /// Default Constructor
        /// </summary>
        public CCOComplexVector()
        {
            // TODO: oder besser auf EMPTY_VECTOR setzen?
            m_Real = new CCOVector();
            m_Imag = new CCOVector();
        }

        /// <summary>
        /// Init by size
        /// </summary>
        /// <param name="size">number of complex vector elements</param>
        public void Init(int size)
        {
            m_Real = new CCOVector(size);
            m_Imag = new CCOVector(size);
        }

        /// <summary>
        /// Property Length
        /// </summary>
        /// <returns>number of complex vector elements</returns>
        public int Length
        {
            get
            {
                Trace.Assert(m_Real.Length == m_Imag.Length);
                return m_Real.Length;
            }
        }



        /// <summary>
        /// Complex Vector addition. 
        /// Vectors must have the same size.
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>X = L + R</returns>
        public static CCOComplexVector operator +(CCOComplexVector L, CCOComplexVector R)
        {
            Trace.Assert(L.Length == R.Length);
            CCOComplexVector X = new CCOComplexVector(L.Length);

            X.Real = L.Real + R.Real;
            X.Imag = L.Imag + R.Imag;

            return X;
        }

        /// <summary>
        /// Complex Vector subtraction. 
        /// Vectors must have the same size.
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>X = L - R</returns>
        public static CCOComplexVector operator -(CCOComplexVector L, CCOComplexVector R)
        {
            Trace.Assert(L.Length == R.Length);
            CCOComplexVector X = new CCOComplexVector(L.Length);

            X.Real = L.Real - R.Real;
            X.Imag = L.Imag - R.Imag;

            return X;
        }


        /// <summary>
        /// Absolute Values of Complex vector
        /// r : absolute value
        /// z = x + i*y = r*e^(i*Phi)
        /// <seealso cref="Angle"/>
        /// </summary>
        /// <returns>Vector with Absolute Values</returns>
        public CCOVector Abs()
        {
            CCOVector r = new CCOVector(Length);
            for (int i = 0; i < Length; i++)
            {
                r[i] = System.Math.Sqrt(Real[i] * Real[i] + Imag[i] * Imag[i]);
            }
            return r;
        }


        /// <summary>
        /// Angle 
        /// Phi: -PI ... +PI
        /// z = x + i*y = r*e^(i*Phi)
        /// <seealso cref="CCOComplexVector.Abs"/>
        /// </summary>
        /// <returns></returns>
        public CCOVector Angle()
        {
            CCOVector p = new CCOVector(Length);
            for (int i = 0; i < Length; i++)
            {
                p[i] = System.Math.Atan2(Real[i], Imag[i]);
            }
            return p;
        }

        /// <summary>
        /// Complex Conjugate
        /// </summary>
        public void Conj()
        {
            Imag *= -1.0;
        }

        /// <summary>
        /// Builds a new complex vector with a flipped real and imag part.  
        /// Useful for fft.
        /// e.g. imag "1 2 3 4"     flipped: "3 4 1 2"	     even number
        ///           "1 2 3 4 5"   flipped: "4 5 3 1 2"	 odd number
        /// </summary>
        /// <returns>flipped complex vector</returns>
        public CCOComplexVector Flip()
        {
            CCOComplexVector NewComplexVector = new CCOComplexVector();

            NewComplexVector.m_Imag = this.m_Imag.Flip();
            NewComplexVector.m_Real = this.m_Real.Flip();

            return NewComplexVector;
        }

        /// <summary>
        /// Multiplicate complex vector with vector. Vectors must have the same size.
        /// </summary>
        /// <param name="L">complex vector</param>
        /// <param name="R">vector</param>
        /// <returns>The multiplicated complex vector</returns>
        public static CCOComplexVector operator *(CCOComplexVector p_Vector, CCOVector p_Right)
        {
            Trace.Assert(p_Vector.Length == p_Right.Length);

            CCOComplexVector Result = new CCOComplexVector(p_Vector.Length);

            for (int i = 0; i < Result.Length; i++)
            {
                Result.Real[i] = p_Vector.Real[i] * p_Right[i];
                Result.Imag[i] = p_Vector.Imag[i] * p_Right[i];
            }

            return Result;
        }

        /// <summary>
        /// Save all items from a complex vector to a file. So it can be 
        /// tested with Matlab.
        /// </summary>
        /// <param name="p_FileName">Fully qualified name of file</param>
        public void Save(string p_sFileName)
        {
            StreamWriter l_File;

            try
            {
                l_File = File.CreateText(p_sFileName);
            }
            catch
            {
                Trace.Assert(false, "File was not created");
                throw;
            }

            for (int i = 0; i < Length; i++)
            {
                l_File.WriteLine(Real[i].ToString("E17") + " " + Imag[i].ToString("E17"));
            }

            l_File.Close();
        }
    }
}
