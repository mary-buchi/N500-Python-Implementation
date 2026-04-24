using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buchi.Core
{
    public class CCOVersionInfo : IConvertible
    {
        /// <summary>
        /// version info
        /// </summary>
        private string[] m_sVersionInfo;

        /// <summary>
        /// construction
        /// </summary>
        /// <param name="p_sVersion">version info like "1.0.0.0" or "1.*"</param>
        public CCOVersionInfo(string p_sVersion)
        {
            char[] l_Deli = { '.' };
            m_sVersionInfo = p_sVersion.Trim().Split(l_Deli);
            for (int l_iCnt = 0; l_iCnt < m_sVersionInfo.Length; l_iCnt++)
            {
                if (m_sVersionInfo[l_iCnt].Length > 1)
                {
                    m_sVersionInfo[l_iCnt] = m_sVersionInfo[l_iCnt].TrimStart(new char[] { '0' });
                    if (m_sVersionInfo[l_iCnt] == "")
                        m_sVersionInfo[l_iCnt] = "0";
                }
            }

            Trace.Assert(m_sVersionInfo.Length > 0);
        }

        /// <summary>
        /// validates a given version string
        /// </summary>
        /// <param name="p_String">true if accepted</param>
        /// <returns></returns>
        static public bool Validate(string p_String)
        {
            try
            {
                if (p_String.Length == 0)
                {
                    return false;
                }
                CCOVersionInfo vi = new CCOVersionInfo(p_String);
                return vi.Major != "0";
            }
            catch
            {
                return false;
            }
        }

        /// <summary>
        /// transforms the version into a string again!
        /// </summary>
        public string Version
        {
            get
            {
                string l_sVersion = "";
                for (int l_iCnt = 0; l_iCnt < m_sVersionInfo.Length; l_iCnt++)
                {
                    if (l_sVersion != "")
                        l_sVersion += ".";
                    l_sVersion += m_sVersionInfo[l_iCnt].ToString();
                }
                return l_sVersion;
            }
        }

        /// <summary>
        /// transforms the version into a buchi string again
        /// 
        /// fills the version with leading unicode char
        /// e.g. 
        /// 1.1 <-> 01.01
        /// </summary>
        public string VersionBuchi
        {
            get
            {
                string l_sRet = "";
                for (int rr = 0; rr < m_sVersionInfo.Length; rr++)
                {
                    if (l_sRet != "")
                        l_sRet += ".";

                    l_sRet += m_sVersionInfo[rr].PadLeft(2, '0');
                }
                return l_sRet;
            }
        }
        /// <summary>
        /// major part property
        /// </summary>
        public string Major
        {
            get
            {
                if (m_sVersionInfo.Length == 0)
                    return "";
                return m_sVersionInfo[0];
            }
        }

        /// <summary>
        /// major part property
        /// </summary>
        public string Minor
        {
            get
            {
                if (m_sVersionInfo.Length < 2)
                    return "";
                return m_sVersionInfo[1];
            }
        }

        /// <summary>
        /// Build part property
        /// </summary>
        public string Build
        {
            get
            {
                if (m_sVersionInfo.Length < 3)
                    return "";
                return m_sVersionInfo[2];
            }
        }

        /// <summary>
        /// checks, whether the given version number is a compatible one, meaning
        /// that only the major part divers
        /// </summary>
        /// <param name="p_Right">version number to compare</param>
        /// <returns>true, if only the major number divers or a wildcard is used</returns>
        public bool IsCompatible(CCOVersionInfo p_Right)
        {
            if (this.Major == "*" || p_Right == null || p_Right.Major == "*")
                return true;

            if (this.Major == p_Right.Major)
                return true;

            return false;
        }

        /// <summary>
        /// comparison operator
        /// </summary>
        /// <param name="p_Left"></param>
        /// <param name="p_Right"></param>
        /// <returns></returns>
        public static bool operator ==(CCOVersionInfo p_Left, CCOVersionInfo p_Right)
        {
            if (ReferenceEquals(p_Left, p_Right))
            {
                return true;
            }
            else if (ReferenceEquals(p_Left, null) || ReferenceEquals(p_Right, null))
            {
                return false;
            }

            string l_sLeft = p_Left.Major;
            if (l_sLeft == "")
                l_sLeft = "0";

            string l_sRight = p_Right.Major;
            if (l_sRight == "")
                l_sRight = "0";

            if (l_sLeft == "*" || l_sRight == "*")
                return true;

            int l_iLeft = Convert.ToInt32(l_sLeft);
            int l_iRight = Convert.ToInt32(l_sRight);

            // compare major
            if (l_iLeft != l_iRight)
                return false;

            // compare minor
            l_sLeft = p_Left.Minor;
            if (l_sLeft == "")
                l_sLeft = "0";

            l_sRight = p_Right.Minor;
            if (l_sRight == "")
                l_sRight = "0";

            if (l_sLeft == "*" || l_sRight == "*")
                return true;

            l_iLeft = Convert.ToInt32(l_sLeft);
            l_iRight = Convert.ToInt32(l_sRight);
            if (l_iLeft != l_iRight)
                return false;

            // compare build
            l_sLeft = p_Left.Build;
            if (l_sLeft == "")
                l_sLeft = "0";

            l_sRight = p_Right.Build;
            if (l_sRight == "")
                l_sRight = "0";

            if (l_sLeft == "*" || l_sRight == "*")
                return true;

            l_iLeft = Convert.ToInt32(l_sLeft);
            l_iRight = Convert.ToInt32(l_sRight);
            if (l_iLeft != l_iRight)
                return false;

            // seam to be identical
            return true;
        }

        /// <summary>
        /// comparison operator
        /// </summary>
        /// <param name="p_Left"></param>
        /// <param name="p_Right"></param>
        /// <returns></returns>
        public static bool operator !=(CCOVersionInfo p_Left, CCOVersionInfo p_Right)
        {
            return !(p_Left == p_Right);
        }

        /// <summary>
        /// smaller/equal operator
        /// </summary>
        /// <param name="p_Left"></param>
        /// <param name="p_Right"></param>
        /// <returns></returns>
        public static bool operator <=(CCOVersionInfo p_Left, CCOVersionInfo p_Right)
        {
            bool l_bRes = p_Left < p_Right;
            if (!l_bRes)
                l_bRes = p_Left == p_Right;

            return l_bRes;
        }

        /// <summary>
        /// bigger/equal operator
        /// </summary>
        /// <param name="p_Left"></param>
        /// <param name="p_Right"></param>
        /// <returns></returns>
        public static bool operator >=(CCOVersionInfo p_Left, CCOVersionInfo p_Right)
        {
            bool l_bRes = p_Left > p_Right;
            if (!l_bRes)
                l_bRes = p_Left == p_Right;

            return l_bRes;
        }

        /// <summary>
        /// smaller operator
        /// </summary>
        /// <param name="p_Left"></param>
        /// <param name="p_Right"></param>
        /// <returns></returns>
        public static bool operator <(CCOVersionInfo p_Left, CCOVersionInfo p_Right)
        {
            string l_sLeft = p_Left.Major;
            if (l_sLeft == "")
                l_sLeft = "0";

            string l_sRight = p_Right.Major;
            if (l_sRight == "")
                l_sRight = "0";

            if (l_sLeft == "*" || l_sRight == "*")
                return true;

            int l_iLeft = Convert.ToInt32(l_sLeft);
            int l_iRight = Convert.ToInt32(l_sRight);

            // compare major
            if (l_iLeft < l_iRight)
                return true;
            else if (l_iLeft > l_iRight)
                return false;

            // compare minor
            l_sLeft = p_Left.Minor;
            if (l_sLeft == "")
                l_sLeft = "0";

            l_sRight = p_Right.Minor;
            if (l_sRight == "")
                l_sRight = "0";

            if (l_sLeft == "*" || l_sRight == "*")
                return false;

            l_iLeft = Convert.ToInt32(l_sLeft);
            l_iRight = Convert.ToInt32(l_sRight);
            if (l_iLeft < l_iRight)
                return true;
            else if (l_iLeft > l_iRight)
                return false;

            // compare build
            l_sLeft = p_Left.Build;
            if (l_sLeft == "")
                l_sLeft = "0";

            l_sRight = p_Right.Build;
            if (l_sRight == "")
                l_sRight = "0";

            if (l_sLeft == "*" || l_sRight == "*")
                return false;
            l_iLeft = Convert.ToInt32(l_sLeft);
            l_iRight = Convert.ToInt32(l_sRight);
            if (l_iLeft < l_iRight)
                return true;
            else if (l_iLeft > l_iRight)
                return false;

            // seam to be identical
            return false;
        }

        /// <summary>
        /// bigger operator
        /// </summary>
        /// <param name="p_Left"></param>
        /// <param name="p_Right"></param>
        /// <returns></returns>
        public static bool operator >(CCOVersionInfo p_Left, CCOVersionInfo p_Right)
        {
            string l_sLeft = p_Left.Major;
            if (l_sLeft == "")
                l_sLeft = "0";

            string l_sRight = p_Right.Major;
            if (l_sRight == "")
                l_sRight = "0";

            if (l_sLeft == "*" || l_sRight == "*")
                return true;

            // compare major
            int l_iLeft = Convert.ToInt32(l_sLeft);
            int l_iRight = Convert.ToInt32(l_sRight);
            if (l_iLeft < l_iRight)
                return false;
            else if (l_iLeft > l_iRight)
                return true;

            // compare minor
            l_sLeft = p_Left.Minor;
            if (l_sLeft == "")
                l_sLeft = "0";

            l_sRight = p_Right.Minor;
            if (l_sRight == "")
                l_sRight = "0";

            if (l_sLeft == "*" || l_sRight == "*")
                return false;

            l_iLeft = Convert.ToInt32(l_sLeft);
            l_iRight = Convert.ToInt32(l_sRight);
            if (l_iLeft < l_iRight)
                return false;
            else if (l_iLeft > l_iRight)
                return true;

            // compare build
            l_sLeft = p_Left.Build;
            if (l_sLeft == "")
                l_sLeft = "0";

            l_sRight = p_Right.Build;
            if (l_sRight == "")
                l_sRight = "0";

            if (l_sLeft == "*" || l_sRight == "*")
                return false;

            l_iLeft = Convert.ToInt32(l_sLeft);
            l_iRight = Convert.ToInt32(l_sRight);
            if (l_iLeft < l_iRight)
                return false;
            else if (l_iLeft > l_iRight)
                return true;

            // seam to be identical
            return false;
        }

        /// <summary>
        /// checks, whether two object are the same
        /// </summary>
        /// <param name="p_Right"></param>
        /// <returns></returns>
        public override bool Equals(object p_Right)
        {
            return this == (CCOVersionInfo)p_Right;
        }

        /// <summary>
        /// supplies a hashcode
        /// </summary>
        /// <returns></returns>
        public override int GetHashCode()
        {
            // not usable!!
            return 0;
        }

        #region IConvertible Members

        public ulong ToUInt64(IFormatProvider provider)
        {
            if (m_sVersionInfo.Length > 0)
            {
                return Convert.ToUInt64(m_sVersionInfo[0]);
            }
            else
            {
                return 0;
            }
        }

        public sbyte ToSByte(IFormatProvider provider)
        {
            return 0;
        }

        public double ToDouble(IFormatProvider provider)
        {
            if (m_sVersionInfo.Length == 1)
            {
                return Convert.ToDouble(m_sVersionInfo[0]);
            }
            else if (m_sVersionInfo.Length == 2)
            {
                return Convert.ToDouble(this.Version);
            }
            else
            {
                return 0;
            }
        }

        public DateTime ToDateTime(IFormatProvider provider)
        {
            return new DateTime();
        }

        public float ToSingle(IFormatProvider provider)
        {
            if (m_sVersionInfo.Length == 1)
            {
                return Convert.ToSingle(m_sVersionInfo[0]);
            }
            else
            {
                return 0;
            }
        }

        public bool ToBoolean(IFormatProvider provider)
        {
            return false;
        }

        public int ToInt32(IFormatProvider provider)
        {
            if (m_sVersionInfo.Length == 1)
            {
                return Convert.ToInt32(m_sVersionInfo[0]);
            }
            else
            {
                return 0;
            }
        }

        public ushort ToUInt16(IFormatProvider provider)
        {
            if (m_sVersionInfo.Length == 1)
            {
                return Convert.ToUInt16(m_sVersionInfo[0]);
            }
            else
            {
                return 0;
            }
        }

        public short ToInt16(IFormatProvider provider)
        {
            if (m_sVersionInfo.Length == 1)
            {
                return Convert.ToInt16(m_sVersionInfo[0]);
            }
            else
            {
                return 0;
            }
        }

        string System.IConvertible.ToString(IFormatProvider provider)
        {
            return this.Version;
        }

        public byte ToByte(IFormatProvider provider)
        {
            return 0;
        }

        public char ToChar(IFormatProvider provider)
        {
            return '\0';
        }

        public long ToInt64(IFormatProvider provider)
        {
            if (m_sVersionInfo.Length == 1)
            {
                return Convert.ToInt64(m_sVersionInfo[0]);
            }
            else
            {
                return 0;
            }
        }

        public System.TypeCode GetTypeCode()
        {
            return Convert.GetTypeCode(this);
        }

        public decimal ToDecimal(IFormatProvider provider)
        {
            if (m_sVersionInfo.Length == 1)
            {
                return Convert.ToDecimal(m_sVersionInfo[0]);
            }
            else
            {
                return 0;
            }
        }

        public object ToType(Type conversionType, IFormatProvider provider)
        {
            return null;
        }

        public uint ToUInt32(IFormatProvider provider)
        {
            if (m_sVersionInfo.Length == 1)
            {
                return Convert.ToUInt32(m_sVersionInfo[0]);
            }
            else
            {
                return 0;
            }
        }

        #endregion

        /// <summary>
        /// Returns a <see cref="T:System.String"/> that represents the current <see cref="T:System.Object"/>.
        /// </summary>
        /// <returns>
        /// A <see cref="T:System.String"/> that represents the current <see cref="T:System.Object"/>.
        /// </returns>
        public override string ToString()
        {
            return Version;
        }
    }
}

