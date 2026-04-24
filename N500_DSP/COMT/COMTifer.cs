using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buchi.Core.Math
{
    /// <summary>
    /// inteferogramm type
    /// </summary>
    public enum ECOInterferogramType
    {
        eForwardRecord,
        eReverseRecord,
    }

    public class CCOInterferogram
    {
        /// <summary>
        /// ctor, creates an empty interferogram with no data points
        /// </summary>
        public CCOInterferogram()
        {
            m_InterferogramID = 0;
            m_InterferogramType = ECOInterferogramType.eForwardRecord;
            m_Vector = new CCOVector();
        }

        /// <summary>
        /// copy constructor
        /// </summary>
        /// <param name="p_Right"></param>
        public CCOInterferogram(CCOInterferogram p_Right)
        {
            m_InterferogramID = p_Right.m_InterferogramID;
            m_InterferogramType = p_Right.m_InterferogramType;
            m_Vector = new CCOVector(p_Right.Vector);
            m_Version = new CCOVersionInfo(p_Right.Version.Version);
            m_dbInstrumentTemperature = p_Right.m_dbInstrumentTemperature;
        }

        /// <summary>
        /// constructor for an interferogram with present raw data
        /// </summary>
        /// <param name="p_DataVector">data vector</param>
        /// <param name="p_eType">IFG type</param>
        /// <param name="p_dbInstrumentTemperature">current instrument temperature</param>
        public CCOInterferogram(CCOVector p_DataVector, ECOInterferogramType p_eType, double p_dbInstrumentTemperature)
        {
            m_InterferogramID = 0;
            m_InterferogramType = p_eType;
            m_Vector = p_DataVector;
            m_dbInstrumentTemperature = p_dbInstrumentTemperature;
        }

        #region properties

        int m_InterferogramID;
        public int InterferogramID
        {
            get { return m_InterferogramID; }
            set { m_InterferogramID = value; }
        }

        ECOInterferogramType m_InterferogramType;
        public ECOInterferogramType InterferogramType
        {
            get { return m_InterferogramType; }
            set { m_InterferogramType = value; }
        }

        CCOVector m_Vector;
        public CCOVector Vector
        {
            get { return m_Vector; }
            set { m_Vector = value; }
        }

        /// <summary>
        /// spectrum version info
        /// </summary>
        private CCOVersionInfo m_Version = new CCOVersionInfo("1");
        public CCOVersionInfo Version
        {
            get { return m_Version; }
            set { m_Version = value; }
        }

        /// <summary>
        /// instrument temperature
        /// </summary>
        private double m_dbInstrumentTemperature;
        public double InstrumentTemperature
        {
            get { return m_dbInstrumentTemperature; }
            set { m_dbInstrumentTemperature = value; }
        }

        #endregion

        #region Equality methods

        /// <summary>
        /// Compares two Interferograms of equality.
        /// </summary>
        /// <param name="l"></param>
        /// <param name="r"></param>
        /// <returns>true / false : Interferograms are identical</returns>
        public static bool operator ==(CCOInterferogram l, CCOInterferogram r)
        {
            if (ReferenceEquals(l, r))
            {
                return true;
            }
            else if (ReferenceEquals(l, null) || ReferenceEquals(r, null))
            {
                return false;
            }
            else
                return l.m_InterferogramType == r.m_InterferogramType &&
                        l.m_Vector == r.m_Vector &&
                        l.m_Version == r.m_Version;
        }

        /// <summary>
        /// Compares two Interferograms of NOT equality.
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>true / false : Interferograms are NOT identical</returns>
        public static bool operator !=(CCOInterferogram l, CCOInterferogram r)
        {
            return !(l == r);
        }

        /// <summary>
        /// Equals / ==
        /// Followa the contract defined on the Object.Equals Method.
        /// </summary>
        /// <param name="obj">any object</param>
        /// <returns>true, if object member data are equal</returns>
        public override bool Equals(object o)
        {
            if (!(o is CCOInterferogram))
                return false;
            return this == (CCOInterferogram)o;
        }

        /// <summary>
        /// GetHashCode
        /// </summary>
        /// <returns></returns>
        public override int GetHashCode()
        {
            return m_InterferogramID + m_Vector.Length;
        }

        /// <summary>
        /// Clone inherited from ICloneable
        /// </summary>
        /// <returns></returns>
        public object Clone()
        {
            CCOInterferogram l_newSpectrum = new CCOInterferogram();

            //l_newSpectrum.m_bLoaded = false;
            l_newSpectrum.m_InterferogramID = 0;
            l_newSpectrum.m_InterferogramType = m_InterferogramType;
            m_Vector.CopyTo(l_newSpectrum.m_Vector);
            l_newSpectrum.m_Version = new CCOVersionInfo(m_Version.Version);

            return l_newSpectrum;
        }

        #endregion
    }
}
