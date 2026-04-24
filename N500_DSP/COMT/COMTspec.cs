using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace Buchi.Core.Math
{
    /// <summary>
    /// spectrum type, defines the the names of the axes
    /// </summary>
    public enum ECOSpectrumType
    {
        eReflectance,
        eTransmittance,
        eAbsorbance,
        eIntensity,
    }
}

namespace Buchi.Core.Math
{
    /// <summary>
    /// defined possible sources where the spectrum comes from
    /// </summary>
    public enum ECOSpectrumSourceType
    {
        eNIRWare,
        eImport,
    }
}


namespace Buchi.Core.Math
{
    /// <summary>
    /// This class represents a spectrum as defined in the database table RE_Spectrum
    /// </summary>
    [Serializable()]
    public class CCOSpectrum : ICloneable //: CDBPersistenceClass, ICloneable
    {
        /// <summary>
        /// creates an empty spectrum with no data points
        /// </summary>
        public CCOSpectrum()
        {
            m_Vector = new CCOVector();
            m_Version = new CCOVersionInfo("1");
            m_iGain = 0;
            m_dbGainFactor = 1.0;
        }

        /// <summary>
        /// copy constructor
        /// </summary>
        public CCOSpectrum(CCOSpectrum p_Right)
        {
            //m_bLoaded = p_Right.m_bLoaded;
            if (p_Right.m_CustomXVector != null)
                m_CustomXVector = new CCOVector(p_Right.m_CustomXVector);
            m_dDataResolution = p_Right.m_dDataResolution;
            m_dInstrumentResolution = p_Right.m_dInstrumentResolution;
            m_eCharacteristicType = p_Right.m_eCharacteristicType;
            m_eSourceType = p_Right.m_eSourceType;
            m_eSpectrumType = p_Right.m_eSpectrumType;
            m_eXAxisType = p_Right.m_eXAxisType;
            m_eYAxisType = p_Right.m_eYAxisType;
            m_iNumberOfScans = p_Right.m_iNumberOfScans;
            m_iSpectrumID = p_Right.m_iSpectrumID;
            m_sComment = p_Right.m_sComment;
            m_sCustomData = p_Right.m_sCustomData;
            m_sInstrumentSerialNo = p_Right.m_sInstrumentSerialNo;
            m_sInstrumentType = p_Right.m_sInstrumentType;
            m_sMeasurementCellOptionType = p_Right.m_sMeasurementCellOptionType;
            m_sMeasurementCellSerialNo = p_Right.m_sMeasurementCellSerialNo;
            m_sMeasurementCellType = p_Right.m_sMeasurementCellType;
            m_SpectrumGUID = new Guid(p_Right.m_SpectrumGUID.ToString());
            m_sUser = p_Right.m_sUser;
            m_TimeStamp = new DateTime(p_Right.TimeStamp.Ticks);
            m_Vector = new CCOVector(p_Right.m_Vector);
            m_Version = new CCOVersionInfo(p_Right.m_Version.Version);
            m_dbXStart = p_Right.m_dbXStart;
            m_iXLength = p_Right.m_iXLength;
            m_dbInstrumentTemperature = p_Right.m_dbInstrumentTemperature;
            m_dbSampleTemperature = p_Right.m_dbSampleTemperature;
            m_ForwardIFG = p_Right.m_ForwardIFG;
            m_ReverseIFG = p_Right.m_ReverseIFG;
            m_dbGainFactor = p_Right.m_dbGainFactor;
            m_iGain = p_Right.m_iGain;
        }

        /// <summary>
        /// checks certain attributes whether the given spectrum is compatible to the current spectrum
        /// </summary>
        /// <param name="p_Right">spectrum to compare</param>
        /// <returns>true, if the spectrum is compatible</returns>
        public bool IsCompatible(CCOSpectrum p_Right)
        {
            return (m_dbXStart == p_Right.m_dbXStart &&
                    m_iXLength == p_Right.m_iXLength &&
                    m_dDataResolution == p_Right.m_dDataResolution &&
                    m_dInstrumentResolution == p_Right.m_dInstrumentResolution &&
                    m_eSpectrumType == p_Right.m_eSpectrumType);
        }

        #region properties
        // Properties

        /// <summary>
        /// spectrum type such as Transmission, Reflectance
        /// </summary>
        ECOSpectrumType m_eSpectrumType;
        public ECOSpectrumType SpectrumType
        {
            get { return m_eSpectrumType; }
            set { m_eSpectrumType = value; }
        }

        /// <summary>
        /// NIRWare or various Imports
        /// </summary>
        private ECOSpectrumSourceType m_eSourceType;
        //[PersistentColName("SpectrumSourceType")]
        public ECOSpectrumSourceType SourceType
        {
            get { return m_eSourceType; }
            set { m_eSourceType = value; }
        }

        /// <summary>
        /// Spectrum Characteristics such as Internal/External Reference, Sample
        /// </summary>
        private ECOSpectrumCharacteristicType m_eCharacteristicType;
        //[PersistentColName("SpectrumCharacteristicType")]
        public ECOSpectrumCharacteristicType Characteristic
        {
            get { return m_eCharacteristicType; }
            set { m_eCharacteristicType = value; }
        }

        /// <summary>
        /// unit of the X Axis, such as nm, cm-1, Custom X Vector
        /// </summary>
        private ECOSpectrumXAxisType m_eXAxisType;
        //[PersistentColName("SpectrumXAxisType")]
        public ECOSpectrumXAxisType XAxisType
        {
            get { return m_eXAxisType; }
            set { m_eXAxisType = value; }
        }

        /// <summary>
        /// unit of the Y axis, such as Intensity, Transmission, Reflection, Absorbance
        /// </summary>
        private ECOSpectrumYAxisType m_eYAxisType;
        //[PersistentColName("SpectrumYAxisType")]
        public ECOSpectrumYAxisType YAxisType
        {
            get { return m_eYAxisType; }
            set { m_eYAxisType = value; }
        }

        /// <summary>
        /// the DB ID of the spectrum
        /// </summary>
        private int m_iSpectrumID;
        public int SpectrumID
        {
            get { return m_iSpectrumID; }
            set { m_iSpectrumID = value; }
        }

        /// <summary>
        /// GUID of the spectrum
        /// </summary>
        private Guid m_SpectrumGUID;
        //[PersistentColName("GUID")]
        public Guid SpectrumGUID
        {
            get { return m_SpectrumGUID; }
            set { m_SpectrumGUID = value; }
        }


        /// <summary>
        /// spectrum data as a double vector
        /// </summary>
        private CCOVector m_Vector;
        public CCOVector Vector
        {
            get { return m_Vector; }
            set
            {
                m_Vector = value;
                m_iXLength = m_Vector.Length;
            }
        }

        /// <summary>
        /// number of scans used to record this spectrum
        /// </summary>
        private int m_iNumberOfScans;
        public int NumberOfScans
        {
            get { return m_iNumberOfScans; }
            set { m_iNumberOfScans = value; }
        }

        /// <summary>
        /// spectrum comment
        /// </summary>
        private string m_sComment;
        public string Comment
        {
            get { return m_sComment; }
            set { m_sComment = value; }
        }

        /// <summary>
        /// spectrum version info
        /// </summary>
        private CCOVersionInfo m_Version;
        //[PersistentColName("VersionNo", "Version")]
        public CCOVersionInfo Version
        {
            get { return m_Version; }
            set { m_Version = value; }
        }

        /// <summary>
        /// Instrument Resolution in cm-1
        /// </summary>
        private double m_dInstrumentResolution;
        public double InstrumentResolution
        {
            get { return m_dInstrumentResolution; }
            set { m_dInstrumentResolution = value; }
        }

        /// <summary>
        /// Data Resolution in cm-1
        /// </summary>
        private double m_dDataResolution;
        public double DataResolution
        {
            get { return m_dDataResolution; }
            set { m_dDataResolution = value; }
        }

        /// <summary>
        /// instrument type info
        /// </summary>
        private string m_sInstrumentType;
        public string InstrumentType
        {
            get { return m_sInstrumentType; }
            set { m_sInstrumentType = value; }
        }

        /// <summary>
        /// instrument serial number
        /// </summary>
        private string m_sInstrumentSerialNo;
        public string InstrumentSerialNo
        {
            get { return m_sInstrumentSerialNo; }
            set { m_sInstrumentSerialNo = value; }
        }

        /// <summary>
        /// measurement cell type info
        /// </summary>
        private string m_sMeasurementCellType;
        public string MeasurementCellType
        {
            get { return m_sMeasurementCellType; }
            set { m_sMeasurementCellType = value; }
        }

        /// <summary>
        /// measurement cell serial number
        /// </summary>
        private string m_sMeasurementCellSerialNo;
        public string MeasurementCellSerialNo
        {
            get { return m_sMeasurementCellSerialNo; }
            set { m_sMeasurementCellSerialNo = value; }
        }

        /// <summary>
        /// measurement cell option type
        /// </summary>
        private string m_sMeasurementCellOptionType;
        public string MeasurementCellOptionType
        {
            get { return m_sMeasurementCellOptionType; }
            set { m_sMeasurementCellOptionType = value; }
        }

        /// <summary>
        /// date/time when the spectrum was stored in the database
        /// </summary>
        private DateTime m_TimeStamp;
        public DateTime TimeStamp
        {
            get { return m_TimeStamp; }
            set { m_TimeStamp = value; }
        }

        /// <summary>
        /// name of the user, that stored the spectrum
        /// </summary>
        private string m_sUser;
        //[PersistentColName("UserName")]
        public string User
        {
            get { return m_sUser; }
            set { m_sUser = value; }
        }

        /// <summary>
        /// custom X vector -> must match the XAxisType
        /// </summary>
        private CCOVector m_CustomXVector;
        public CCOVector CustomXVector
        {
            get { return m_CustomXVector; }
            set { m_CustomXVector = value; }
        }

        /// <summary>
        /// any custom defined string, containing format descriptions from foreign data imports
        /// </summary>
        private string m_sCustomData;
        public string CustomData
        {
            get { return m_sCustomData; }
            set { m_sCustomData = value; }
        }

        /// <summary>
        /// starting point of the X axis. Only used when no custom X vector is supplied
        /// </summary>
        private double m_dbXStart;
        public double XStart
        {
            get { return m_dbXStart; }
            set
            {
                m_dbXStart = value;
            }
        }

        /// <summary>
        /// length of the X vector
        /// </summary>
        private int m_iXLength;
        public int XLength
        {
            get { return m_iXLength; }
            set { m_iXLength = value; }
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

        /// <summary>
        /// sample temperature (Liquid Cell only)
        /// </summary>
        private double m_dbSampleTemperature;
        public double SampleTemperature
        {
            get { return m_dbSampleTemperature; }
            set { m_dbSampleTemperature = value; }
        }

        /// <summary>
        /// controls loading and saving of the interferogram
        /// </summary>
        private bool m_bSaveLoadInterferogram;
        public bool SaveLoadInterferogram
        {
            get { return m_bSaveLoadInterferogram; }
            set { m_bSaveLoadInterferogram = value; }
        }

        /// <summary>
        /// optional forward interferogram
        /// </summary>
        private CCOInterferogram m_ForwardIFG;
        //[PersistentForeignKey("ForwardInterferogramID", "InterferogramID", "SaveLoadInterferogram")]
        public CCOInterferogram ForwardIFG
        {
            get { return m_ForwardIFG; }
            set { m_ForwardIFG = value; }
        }

        /// <summary>
        /// optional reverse interferogram
        /// </summary>
        private CCOInterferogram m_ReverseIFG;
        //[PersistentForeignKey("ReverseInterferogramID", "InterferogramID", "SaveLoadInterferogram")]
        public CCOInterferogram ReverseIFG
        {
            get { return m_ReverseIFG; }
            set { m_ReverseIFG = value; }
        }

        /// <summary>
        /// detector gain setting during measuring
        /// mainly used for cell solids transmittance
        /// </summary>
        private double m_dbGainFactor;
        public double GainFactor
        {
            get { return m_dbGainFactor; }
            set { m_dbGainFactor = value; }
        }

        /// <summary>
        /// detector gain used for measuring
        /// mainly used for cell solids transmittance
        /// </summary>
        private int m_iGain;
        public int Gain
        {
            get { return m_iGain; }
            set { m_iGain = value; }
        }

        private bool useCustomData;
        /// <summary>
        /// Gets or sets a value indicating whether [use custom data].
        /// </summary>
        /// <value>
        ///   <c>true</c> if [use custom data]; otherwise, <c>false</c>.
        /// </value>
        public bool UseCustomData
        {
            get { return useCustomData; }
            set { useCustomData = value; }
        }

        private string serial;
        /// <summary>
        /// Gets or sets the serial.
        /// </summary>
        /// <value>
        /// The serial.
        /// </value>
        public string Serial
        {
            get { return serial; }
            set { serial = value; }
        }

        private string name;
        /// <summary>
        /// Gets or sets the name.
        /// </summary>
        /// <value>
        /// The name.
        /// </value>
        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        private bool active;
        /// <summary>
        /// Gets or sets a value indicating whether [active].
        /// </summary>
        /// <value>
        ///   <c>true</c> if [active]; otherwise, <c>false</c>.
        /// </value>
        public bool Active
        {
            get { return active; }
            set { active = value; }
        }

        private string linkedItem1;
        /// <summary>
        /// Gets or sets the linked item1.
        /// </summary>
        /// <value>
        /// The linked item1.
        /// </value>
        public string LinkedItem1
        {
            get { return linkedItem1; }
            set { linkedItem1 = value; }
        }

        private string linkedItem2;
        /// <summary>
        /// Gets or sets the linked item2.
        /// </summary>
        /// <value>
        /// The linked item2.
        /// </value>
        public string LinkedItem2
        {
            get { return linkedItem2; }
            set { linkedItem2 = value; }
        }

        private CCOArticleInfo article;
        /// <summary>
        /// Gets or sets the article.
        /// </summary>
        /// <value>
        /// The article.
        /// </value>
        public Buchi.Core.CCOArticleInfo Article
        {
            get { return article; }
            set { article = value; }
        }

        /// <summary>
        /// Serializes the custom data.
        /// </summary>
        /// <returns></returns>
        public bool SerializeCustomData()
        {
            useCustomData = true;
            bool iRet = false;
            CCOCustomData cd = new CCOCustomData();
            if (cd.Initialize(serial, name, active, linkedItem1, linkedItem2, article))
            {
                if (cd.HasXMLCustomData)
                {
                    m_sCustomData = cd.XmlString;
                    iRet = true;
                }
            }

            return iRet;
        }

        /// <summary>
        /// Deserializes the custom data.
        /// </summary>
        /// <returns></returns>
        public bool DeserializeCustomData()
        {
            useCustomData = true;
            bool iRet = false;
            CCOCustomData cd = new CCOCustomData();
            if (cd.Initialize(m_sCustomData))
            {
                if (cd.HasXMLCustomData)
                {
                    serial = cd.Serial;
                    active = cd.Active;
                    name = cd.Name;
                    linkedItem1 = cd.LinkedItem1;
                    linkedItem2 = cd.LinkedItem2;
                    article = cd.Article;
                    iRet = true;
                }
            }

            return iRet;
        }
        #endregion

        #region Equality methods

        /// <summary>
        /// Compares two Spectra of equality.
        /// </summary>
        /// <param name="l"></param>
        /// <param name="r"></param>
        /// <returns>true / false : Spectra are identical</returns>
        public static bool operator ==(CCOSpectrum l, CCOSpectrum r)
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
            {
                return (
                    l.m_CustomXVector == r.m_CustomXVector &&
                    l.m_eCharacteristicType == r.m_eCharacteristicType &&
                    l.m_eSourceType == r.m_eSourceType &&
                    l.m_eXAxisType == r.m_eXAxisType &&
                    l.m_eYAxisType == r.m_eYAxisType &&
                    l.m_dDataResolution == r.m_dDataResolution &&
                    l.m_dInstrumentResolution == r.m_dInstrumentResolution &&
                    l.m_iNumberOfScans == r.m_iNumberOfScans &&
                    l.m_iSpectrumID == r.m_iSpectrumID &&
                    l.m_sComment == r.m_sComment &&
                    l.m_sCustomData == r.m_sCustomData &&
                    l.m_sInstrumentSerialNo == r.m_sInstrumentSerialNo &&
                    l.m_sInstrumentType == r.m_sInstrumentType &&
                    l.m_sMeasurementCellOptionType == r.m_sMeasurementCellOptionType &&
                    l.m_sMeasurementCellSerialNo == r.m_sMeasurementCellSerialNo &&
                    l.m_sMeasurementCellType == r.m_sMeasurementCellType &&
                    l.m_SpectrumGUID == r.m_SpectrumGUID &&
                    l.m_eSpectrumType == r.m_eSpectrumType &&
                    l.m_sUser == r.m_sUser &&
                    //                    l.m_TimeStamp == r.m_TimeStamp &&
                    l.m_Vector == r.m_Vector &&
                    l.m_Version == r.m_Version &&
                    l.m_dbInstrumentTemperature == r.m_dbInstrumentTemperature &&
                    l.m_dbSampleTemperature == r.m_dbSampleTemperature &&
                    l.m_dbXStart == r.m_dbXStart &&
                    l.m_iXLength == r.m_iXLength &&
                    l.GainFactor == r.GainFactor);
            }
        }

        /// <summary>
        /// Compares two Spectra of NOT equality.
        /// </summary>
        /// <param name="L"></param>
        /// <param name="R"></param>
        /// <returns>true / false : Spectra are NOT identical</returns>
        public static bool operator !=(CCOSpectrum l, CCOSpectrum r)
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
            if (!(o is CCOSpectrum))
                return false;
            return this == (CCOSpectrum)o;
        }

        /// <summary>
        /// GetHashCode
        /// </summary>
        /// <returns></returns>
        public override int GetHashCode()
        {
            return m_iSpectrumID + m_Vector.Length;
        }

        /// <summary>
        /// Clone inherited from ICloneable
        /// </summary>
        /// <returns></returns>
        public object Clone()
        {
            CCOSpectrum l_Clone = new CCOSpectrum();
            if (m_CustomXVector != null)
                l_Clone.m_CustomXVector = new CCOVector(m_CustomXVector);
            l_Clone.m_eCharacteristicType = m_eCharacteristicType;
            l_Clone.m_eSourceType = m_eSourceType;
            l_Clone.m_eXAxisType = m_eXAxisType;
            l_Clone.m_eYAxisType = m_eYAxisType;
            l_Clone.m_dDataResolution = m_dDataResolution;
            l_Clone.m_dInstrumentResolution = m_dInstrumentResolution;
            l_Clone.m_iNumberOfScans = m_iNumberOfScans;
            l_Clone.m_iSpectrumID = m_iSpectrumID;
            l_Clone.m_sComment = m_sComment;
            l_Clone.m_sCustomData = m_sCustomData;
            l_Clone.m_sInstrumentSerialNo = m_sInstrumentSerialNo;
            l_Clone.m_sInstrumentType = m_sInstrumentType;
            l_Clone.m_sMeasurementCellOptionType = m_sMeasurementCellOptionType;
            l_Clone.m_sMeasurementCellSerialNo = m_sMeasurementCellSerialNo;
            l_Clone.m_sMeasurementCellType = m_sMeasurementCellType;
            l_Clone.m_SpectrumGUID = m_SpectrumGUID;
            l_Clone.m_eSpectrumType = m_eSpectrumType;
            l_Clone.m_sUser = m_sUser;
            l_Clone.m_TimeStamp = m_TimeStamp;
            if (m_Vector != null)
                l_Clone.m_Vector = new CCOVector(m_Vector);
            l_Clone.m_Version = new CCOVersionInfo(m_Version.Version);
            l_Clone.m_dbXStart = m_dbXStart;
            l_Clone.m_iXLength = m_iXLength;
            l_Clone.m_dbInstrumentTemperature = m_dbInstrumentTemperature;
            l_Clone.m_dbSampleTemperature = m_dbSampleTemperature;
            l_Clone.m_ForwardIFG = m_ForwardIFG;
            l_Clone.m_ReverseIFG = m_ReverseIFG;
            l_Clone.m_dbGainFactor = m_dbGainFactor;
            l_Clone.m_iGain = m_iGain;

            return l_Clone;
        }

        #endregion

        #region CDBPersistenceClass stuff

        /// <summary>
        /// static Load spectrum method for the specific SpectrumID
        /// </summary>
        /// <param name="p_MatrixID">primary key for the spectrum</param>
        //public static CCOSpectrum LoadStatic(int p_SpectrumID)
        //{
        //    return CCOSpectrum.LoadStatic(p_SpectrumID, null);
        //}

        /// <summary>
        /// static Load spectrum method for the specific SpectrumID
        /// </summary>
        /// <param name="p_MatrixID">primary key for the spectrum</param>
        /// <param name="p_LifecylceContext">lifecycle context to use or null</param>
        //public static CCOSpectrum LoadStatic(int p_SpectrumID, CDBLifecycleContext p_LifecylceContext)
        //{
        //    CCOSpectrum l_Spectrum = new CCOSpectrum();
        //    l_Spectrum.CreateMapper(EDBAction.eShallow, p_LifecylceContext);
        //    l_Spectrum.Load(p_SpectrumID);
        //    l_Spectrum.DeleteMapper(EDBAction.eShallow);
        //    return l_Spectrum;
        //}

        /// <summary>
        /// Load spectrum method for the specific SpectrumID
        /// </summary>
        /// <param name="p_MatrixID">primary key for the spectrum</param>
        //public virtual void Load(int p_SpectrumID)
        //{
        //    object[] l_ParList = { p_SpectrumID };
        //    base.Load(l_ParList, EDBAction.eDeep);
        //}

        /// <summary>
        /// create sub mappers
        /// </summary>
        /// <param name="p_LifecylceContext"></param>
        //protected override void CreateSubMappers(CDBLifecycleContext p_LifecylceContext)
        //{
        //    if (m_ForwardIFG != null)
        //        m_ForwardIFG.CreateMapper(EDBAction.eDeep, p_LifecylceContext);
        //    if (m_ReverseIFG != null)
        //        m_ReverseIFG.CreateMapper(EDBAction.eDeep, p_LifecylceContext);
        //}

        /// <summary>
        /// delete sub mappers
        /// </summary>
        //protected override void DeleteSubMappers()
        //{
        //    if (m_ForwardIFG != null)
        //        m_ForwardIFG.DeleteMapper(EDBAction.eDeep);
        //    if (m_ReverseIFG != null)
        //        m_ReverseIFG.DeleteMapper(EDBAction.eDeep);
        //}


        #endregion

    }
}

namespace Buchi.Core.Math
{
    public enum ECOSpectrumCharacteristicType
    {
        eInternalReference,
        eExternalReference,
        eSample,
        eGoldMaster,
        eGoldMasterAverage,
        eCorrectionVectorGlass,
        eMasterExternalReference,
        eCorrectionVectorMaster,
        eExternalReferenceSpecific,
        eCorrectionVectorExternalReference,
    }
}
namespace Buchi.Core.Math
{
    public enum ECOSpectrumXAxisType
    {
        eWavenumber,
        eWavelength,
        eCustomXVector
    }
}
namespace Buchi.Core.Math
{
    public enum ECOSpectrumYAxisType
    {
        eIntensity,
        eTransmission,
        eReflection,
        eAbsorbance
    }
}

namespace Buchi.Core.Math
{
    [Serializable()]
    public class CCOSpectrumDataReport //: Database.Persistence.CDBPersistenceClass
    {
        /// <summary>
        /// uniq database identifier
        /// </summary>
        public int SpectrumDataReportID
        {
            set { m_iSpectrumDataReportID = value; }
            get { return m_iSpectrumDataReportID; }
        }

        /// <summary>
        /// original spectrum
        /// </summary>
        public CCOSpectrum Spectrum
        {
            get { return m_Spectrum; }
        }

        /// <summary>
        /// X vector
        /// </summary>
        public double[] XValue
        {
            set { m_XValue = value; }
            get { return m_XValue; }
        }

        /// <summary>
        /// Y vector
        /// </summary>
        public double[] YValue
        {
            set { m_YValue = value; }
            get { return m_YValue; }
        }

        /// <summary>
        /// initialize reduced data spectrum
        /// </summary>
        /// <param name="p_Spectrum"></param>
        public CCOSpectrumDataReport(CCOSpectrum p_Spectrum)
        {
            m_Spectrum = p_Spectrum;
        }

        /// <summary>
        /// computes the reduced data set
        /// </summary>
        public void ComputeReducedDataSet()
        {
            const int l_iReduceFactor = 5;
            int l_iSize = (int)((m_Spectrum.Vector.Length - 1) / l_iReduceFactor) + 1;
            m_XValue = new double[l_iSize];
            m_YValue = new double[l_iSize];
            for (int l_iCnt = 0; l_iCnt < l_iSize; l_iCnt++)
            {
                if (m_Spectrum.XAxisType == ECOSpectrumXAxisType.eCustomXVector)
                {
                    m_XValue[l_iCnt] = m_Spectrum.CustomXVector[l_iCnt * l_iReduceFactor];
                }
                else
                {
                    m_XValue[l_iCnt] = m_Spectrum.XStart + l_iCnt * l_iReduceFactor * m_Spectrum.DataResolution;
                }
                m_YValue[l_iCnt] = m_Spectrum.Vector[l_iCnt * l_iReduceFactor];
            }
        }

        private int m_iSpectrumDataReportID;
        private CCOSpectrum m_Spectrum;
        private double[] m_XValue;
        private double[] m_YValue;
    }
}

namespace Buchi.Core.Math
{
    internal class CCOCustomData
    {
        private string xmlString;
        /// <summary>
        /// Gets or sets the XML string.
        /// </summary>
        /// <value>
        /// The XML string.
        /// </value>
	    public string XmlString
        {
            get { return xmlString; }
        }

        private bool hasXMLCustomData;
        /// <summary>
        /// Gets or sets a value indicating whether [has XML custom data].
        /// </summary>
        /// <value>
        ///   <c>true</c> if [has XML custom data]; otherwise, <c>false</c>.
        /// </value>
        public bool HasXMLCustomData
        {
            get { return hasXMLCustomData; }
        }

        private string serial;
        /// <summary>
        /// Gets or sets the serial.
        /// </summary>
        /// <value>
        /// The serial.
        /// </value>
        public string Serial
        {
            get { return serial; }
        }

        private string name;
        /// <summary>
        /// Gets the name.
        /// </summary>
        /// <value>
        /// The name.
        /// </value>
        public string Name
        {
            get { return name; }
        }

        private bool active;
        /// <summary>
        /// Gets or sets a value indicating whether [active].
        /// </summary>
        /// <value>
        ///   <c>true</c> if [active]; otherwise, <c>false</c>.
        /// </value>
        public bool Active
        {
            get { return active; }
        }

        private string linkedItem1;
        /// <summary>
        /// Gets or sets the linked item1.
        /// </summary>
        /// <value>
        /// The linked item1.
        /// </value>
        public string LinkedItem1
        {
            get { return linkedItem1; }
            set { linkedItem1 = value; }
        }

        private string linkedItem2;
        /// <summary>
        /// Gets or sets the linked item2.
        /// </summary>
        /// <value>
        /// The linked item2.
        /// </value>
        public string LinkedItem2
        {
            get { return linkedItem2; }
            set { linkedItem2 = value; }
        }

        private CCOArticleInfo article;
        /// <summary>
        /// Gets or sets the article.
        /// </summary>
        /// <value>
        /// The article.
        /// </value>
        public Buchi.Core.CCOArticleInfo Article
        {
            get { return article; }
            set { article = value; }
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="CCOCustomData"/> class.
        /// </summary>
        public CCOCustomData()
        {
            xmlString = "";
            hasXMLCustomData = false;
            active = false;
            serial = "";
            name = "";
            linkedItem1 = "";
            linkedItem2 = "";
            article = null; // new CCOArticleInfo("<Unknown>");
        }

        /// <summary>
        /// Initializes the specified line.
        /// </summary>
        /// <param name="line">The line.</param>
        /// <returns></returns>
        public bool Initialize(string line)
        {
            bool iRet = false;
            hasXMLCustomData = false;
            try
            {
                XmlDocument doc = new XmlDocument();
                doc.LoadXml(line);
                XmlNodeList nSerialList = doc.GetElementsByTagName("Serial");
                XmlNodeList nActiveList = doc.GetElementsByTagName("Active");
                XmlNodeList nNameList = doc.GetElementsByTagName("Name");
                XmlNodeList nLink1List = doc.GetElementsByTagName("Link1");
                XmlNodeList nLink2List = doc.GetElementsByTagName("Link2");
                XmlNodeList nArticleList = doc.GetElementsByTagName("Article");
                if (nSerialList.Count > 0 && nActiveList.Count > 0)
                {
                    serial = nSerialList[0].InnerText;
                    active = (nActiveList[0].InnerText == "1" ? true : false);
                    if (nNameList.Count > 0)
                    {
                        name = nNameList[0].InnerText;
                    }
                    if (nLink1List.Count > 0)
                    {
                        linkedItem1 = nLink1List[0].InnerText;
                    }
                    if (nLink2List.Count > 0)
                    {
                        linkedItem2 = nLink2List[0].InnerText;
                    }
                    if (nArticleList.Count > 0)
                    {
                        if (!String.IsNullOrEmpty(nArticleList[0].InnerText))
                        {
                            article = new CCOArticleInfo(nArticleList[0].InnerText);
                        }
                    }
                    hasXMLCustomData = true;
                    iRet = true;
                }
            }
            catch { }

            return iRet;
        }

        /// <summary>
        /// Initializes the by XML string.
        /// </summary>
        /// <param name="serial">The serial.</param>
        /// <param name="name">The name.</param>
        /// <param name="active">if set to <c>true</c> [active].</param>
        /// <param name="linkedItem1">The linked item1.</param>
        /// <param name="linkedItem2">The linked item2.</param>
        /// <param name="article">The article.</param>
        /// <returns></returns>
        public bool Initialize(string serial, string name, bool active, string linkedItem1, string linkedItem2, CCOArticleInfo article)
        {
            hasXMLCustomData = false;
            bool iRet = true;
            this.serial = serial;
            this.active = active;
            this.name = name;
            this.linkedItem1 = linkedItem1;
            this.linkedItem2 = linkedItem2;
            this.article = article;

            XmlDocument doc = new XmlDocument();
            XmlNode nCustomData = doc.CreateNode(XmlNodeType.Element, "CustomData", "");
            XmlNode root = doc.AppendChild(nCustomData);

            XmlNode nSerial = doc.CreateNode(XmlNodeType.Element, "Serial", "");
            nSerial.InnerText = serial;
            XmlNode nActive = doc.CreateNode(XmlNodeType.Element, "Active", "");
            nActive.InnerText = (active ? "1" : "0");
            XmlNode nName = doc.CreateNode(XmlNodeType.Element, "Name", "");
            nName.InnerText = name;
            XmlNode nLink1 = doc.CreateNode(XmlNodeType.Element, "Link1", "");
            nLink1.InnerText = linkedItem1;
            XmlNode nLink2 = doc.CreateNode(XmlNodeType.Element, "Link2", "");
            nLink2.InnerText = linkedItem2;
            XmlNode nArticle = doc.CreateNode(XmlNodeType.Element, "Article", "");
            nArticle.InnerText = (article == null ? "" : article.ArticleNo);

            root.AppendChild(nSerial);
            root.AppendChild(nActive);
            root.AppendChild(nName);
            root.AppendChild(nLink1);
            root.AppendChild(nLink2);
            root.AppendChild(nArticle);

            StringWriter sw = new StringWriter();
            XmlTextWriter tx = new XmlTextWriter(sw);
            doc.WriteTo(tx);
            xmlString = sw.ToString();
            hasXMLCustomData = true;
            return iRet;
        }
    }
}