//## begin module%3DAE54C9009F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAE54C9009F.cm

//## begin module%3DAE54C9009F.cp preserve=no
//	/*====================================================*
//	  * Copyright  : Büchi Labortechnik AG, Meierseggstr. 40,
//	  *                   9230 Flawil, Switzerland.
//	  *
//	  * Filename   : $Workfile:$
//	  * System     :
//	  * Function   :
//	  * Author     :
//	  * References :
//	  * Contents   :
//	  *
//	  * $History:$
//	  *=====================================================*
//	  */
//## end module%3DAE54C9009F.cp

//## Module: EBPItype%3DAE54C9009F; Package body
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPItype.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DAE54C9009F.additionalIncludes preserve=no
//## end module%3DAE54C9009F.additionalIncludes

//## begin module%3DAE54C9009F.includes preserve=yes
//## end module%3DAE54C9009F.includes

// EBPIconst
#include "EBPIconst.h"
// EBPIidnt
#include "EBPIidnt.h"
// EBPIexcp
#include "EBPIexcp.h"
// EBPItype
#include "EBPItype.h"


//## begin module%3DAE54C9009F.declarations preserve=no
//## end module%3DAE54C9009F.declarations

//## begin module%3DAE54C9009F.additionalDeclarations preserve=yes
//## end module%3DAE54C9009F.additionalDeclarations


// Class CPIMeasurementChannelDataPackage 






CPIMeasurementChannelDataPackage::CPIMeasurementChannelDataPackage (UINT p_uiID, UINT p_uiSize, BYTE* p_pLaserData, BYTE* p_pDetectorData)
  //## begin CPIMeasurementChannelDataPackage::CPIMeasurementChannelDataPackage%1034835012.hasinit preserve=no
      : m_uiID(p_uiID), m_uiSize(p_uiSize), m_pLaserData(p_pLaserData), m_pDetectorData(p_pDetectorData)
  //## end CPIMeasurementChannelDataPackage::CPIMeasurementChannelDataPackage%1034835012.hasinit
  //## begin CPIMeasurementChannelDataPackage::CPIMeasurementChannelDataPackage%1034835012.initialization preserve=yes
  //## end CPIMeasurementChannelDataPackage::CPIMeasurementChannelDataPackage%1034835012.initialization
{
  //## begin CPIMeasurementChannelDataPackage::CPIMeasurementChannelDataPackage%1034835012.body preserve=yes
  //## end CPIMeasurementChannelDataPackage::CPIMeasurementChannelDataPackage%1034835012.body
}


CPIMeasurementChannelDataPackage::~CPIMeasurementChannelDataPackage()
{
  //## begin CPIMeasurementChannelDataPackage::~CPIMeasurementChannelDataPackage%.body preserve=yes
    delete [] m_pLaserData;
    delete [] m_pDetectorData;
    m_pLaserData = NULL;
    m_pDetectorData = NULL;
  //## end CPIMeasurementChannelDataPackage::~CPIMeasurementChannelDataPackage%.body
}


//## Get and Set Operations for Class Attributes (implementation)

UINT CPIMeasurementChannelDataPackage::GetuiID ()
{
  //## begin CPIMeasurementChannelDataPackage::GetuiID%3DAE5531011D.get preserve=no
  return m_uiID;
  //## end CPIMeasurementChannelDataPackage::GetuiID%3DAE5531011D.get
}

UINT CPIMeasurementChannelDataPackage::GetuiSize ()
{
  //## begin CPIMeasurementChannelDataPackage::GetuiSize%3DAE555601C9.get preserve=no
  return m_uiSize;
  //## end CPIMeasurementChannelDataPackage::GetuiSize%3DAE555601C9.get
}

BYTE* CPIMeasurementChannelDataPackage::GetpLaserData ()
{
  //## begin CPIMeasurementChannelDataPackage::GetpLaserData%3DAE556F0071.get preserve=no
  return m_pLaserData;
  //## end CPIMeasurementChannelDataPackage::GetpLaserData%3DAE556F0071.get
}

BYTE* CPIMeasurementChannelDataPackage::GetpDetectorData ()
{
  //## begin CPIMeasurementChannelDataPackage::GetpDetectorData%3DB7BC81018C.get preserve=no
  return m_pDetectorData;
  //## end CPIMeasurementChannelDataPackage::GetpDetectorData%3DB7BC81018C.get
}

// Additional Declarations
  //## begin CPIMeasurementChannelDataPackage%3DAE54DC0264.declarations preserve=yes
  //## end CPIMeasurementChannelDataPackage%3DAE54DC0264.declarations

// Class CPIObjIdentification 









CPIObjIdentification::CPIObjIdentification (UINT p_uiID)
  //## begin CPIObjIdentification::CPIObjIdentification%1036680714.hasinit preserve=no
      : m_uiID(p_uiID)
  //## end CPIObjIdentification::CPIObjIdentification%1036680714.hasinit
  //## begin CPIObjIdentification::CPIObjIdentification%1036680714.initialization preserve=yes
  //## end CPIObjIdentification::CPIObjIdentification%1036680714.initialization
{
  //## begin CPIObjIdentification::CPIObjIdentification%1036680714.body preserve=yes
  //## end CPIObjIdentification::CPIObjIdentification%1036680714.body
}


CPIObjIdentification::~CPIObjIdentification()
{
  //## begin CPIObjIdentification::~CPIObjIdentification%.body preserve=yes
  //## end CPIObjIdentification::~CPIObjIdentification%.body
}


bool CPIObjIdentification::operator==(const CPIObjIdentification &right) const
{
  //## begin CPIObjIdentification::operator==%.body preserve=yes
	return m_uiID == right.m_uiID;
  //## end CPIObjIdentification::operator==%.body
}

bool CPIObjIdentification::operator!=(const CPIObjIdentification &right) const
{
  //## begin CPIObjIdentification::operator!=%.body preserve=yes
	return m_uiID != right.m_uiID;
  //## end CPIObjIdentification::operator!=%.body
}


//## Get and Set Operations for Class Attributes (implementation)

UINT CPIObjIdentification::GetuiID ()
{
  //## begin CPIObjIdentification::GetuiID%3DCA8DFE023C.get preserve=no
  return m_uiID;
  //## end CPIObjIdentification::GetuiID%3DCA8DFE023C.get
}

// Additional Declarations
  //## begin CPIObjIdentification%3DB50C20034E.declarations preserve=yes
  //## end CPIObjIdentification%3DB50C20034E.declarations

// Class CPIPersistentSoftwareComponent 








CPIPersistentSoftwareComponent::CPIPersistentSoftwareComponent (WCHAR* p_sName, bool p_bRequiresReboot, bool p_bIsFPGASource, bool p_bIsWinCEImage, BYTE* p_pbyImage, INT p_iImageSize)
  //## begin CPIPersistentSoftwareComponent::CPIPersistentSoftwareComponent%1035528319.hasinit preserve=no
      : m_bRequiresReboot(p_bRequiresReboot), m_pImage(p_pbyImage), m_iImageSize(p_iImageSize), m_bIsFPGASource(p_bIsFPGASource), m_bIsWinCEImage(p_bIsWinCEImage)
  //## end CPIPersistentSoftwareComponent::CPIPersistentSoftwareComponent%1035528319.hasinit
  //## begin CPIPersistentSoftwareComponent::CPIPersistentSoftwareComponent%1035528319.initialization preserve=yes
  //## end CPIPersistentSoftwareComponent::CPIPersistentSoftwareComponent%1035528319.initialization
{
  //## begin CPIPersistentSoftwareComponent::CPIPersistentSoftwareComponent%1035528319.body preserve=yes
    wcscpy(m_sName, p_sName);
  //## end CPIPersistentSoftwareComponent::CPIPersistentSoftwareComponent%1035528319.body
}


CPIPersistentSoftwareComponent::~CPIPersistentSoftwareComponent()
{
  //## begin CPIPersistentSoftwareComponent::~CPIPersistentSoftwareComponent%.body preserve=yes
    delete [] m_pImage;
    m_pImage = NULL;
  //## end CPIPersistentSoftwareComponent::~CPIPersistentSoftwareComponent%.body
}


//## Get and Set Operations for Class Attributes (implementation)

WCHAR* CPIPersistentSoftwareComponent::GetsName ()
{
  //## begin CPIPersistentSoftwareComponent::GetsName%3DB901AE03B2.get preserve=no
  return m_sName;
  //## end CPIPersistentSoftwareComponent::GetsName%3DB901AE03B2.get
}

bool CPIPersistentSoftwareComponent::GetbRequiresReboot ()
{
  //## begin CPIPersistentSoftwareComponent::GetbRequiresReboot%3DB901D500D3.get preserve=no
  return m_bRequiresReboot;
  //## end CPIPersistentSoftwareComponent::GetbRequiresReboot%3DB901D500D3.get
}

BYTE* CPIPersistentSoftwareComponent::GetpImage ()
{
  //## begin CPIPersistentSoftwareComponent::GetpImage%3DB902150066.get preserve=no
  return m_pImage;
  //## end CPIPersistentSoftwareComponent::GetpImage%3DB902150066.get
}

INT CPIPersistentSoftwareComponent::GetiImageSize ()
{
  //## begin CPIPersistentSoftwareComponent::GetiImageSize%40960A9F00CB.get preserve=no
  return m_iImageSize;
  //## end CPIPersistentSoftwareComponent::GetiImageSize%40960A9F00CB.get
}

bool CPIPersistentSoftwareComponent::GetbIsFPGASource ()
{
  //## begin CPIPersistentSoftwareComponent::GetbIsFPGASource%4107608C007D.get preserve=no
  return m_bIsFPGASource;
  //## end CPIPersistentSoftwareComponent::GetbIsFPGASource%4107608C007D.get
}

bool CPIPersistentSoftwareComponent::GetbIsWinCEImage ()
{
  //## begin CPIPersistentSoftwareComponent::GetbIsWinCEImage%410760CB036B.get preserve=no
  return m_bIsWinCEImage;
  //## end CPIPersistentSoftwareComponent::GetbIsWinCEImage%410760CB036B.get
}

// Additional Declarations
  //## begin CPIPersistentSoftwareComponent%3DB9016E0298.declarations preserve=yes
  //## end CPIPersistentSoftwareComponent%3DB9016E0298.declarations

// Class CPIPersistentSoftwareComponentVersion 





CPIPersistentSoftwareComponentVersion::CPIPersistentSoftwareComponentVersion (WCHAR* p_sName, WCHAR* p_sVersion)
  //## begin CPIPersistentSoftwareComponentVersion::CPIPersistentSoftwareComponentVersion%1035528320.hasinit preserve=no
  //## end CPIPersistentSoftwareComponentVersion::CPIPersistentSoftwareComponentVersion%1035528320.hasinit
  //## begin CPIPersistentSoftwareComponentVersion::CPIPersistentSoftwareComponentVersion%1035528320.initialization preserve=yes
  //## end CPIPersistentSoftwareComponentVersion::CPIPersistentSoftwareComponentVersion%1035528320.initialization
{
  //## begin CPIPersistentSoftwareComponentVersion::CPIPersistentSoftwareComponentVersion%1035528320.body preserve=yes
    wcscpy(m_sName, p_sName);
    wcscpy(m_sVersion, p_sVersion);
  //## end CPIPersistentSoftwareComponentVersion::CPIPersistentSoftwareComponentVersion%1035528320.body
}


CPIPersistentSoftwareComponentVersion::~CPIPersistentSoftwareComponentVersion()
{
  //## begin CPIPersistentSoftwareComponentVersion::~CPIPersistentSoftwareComponentVersion%.body preserve=yes
  //## end CPIPersistentSoftwareComponentVersion::~CPIPersistentSoftwareComponentVersion%.body
}


//## Get and Set Operations for Class Attributes (implementation)

WCHAR* CPIPersistentSoftwareComponentVersion::GetsName ()
{
  //## begin CPIPersistentSoftwareComponentVersion::GetsName%3DB904D50335.get preserve=no
  return m_sName;
  //## end CPIPersistentSoftwareComponentVersion::GetsName%3DB904D50335.get
}

WCHAR* CPIPersistentSoftwareComponentVersion::GetsVersion ()
{
  //## begin CPIPersistentSoftwareComponentVersion::GetsVersion%3DB904D70018.get preserve=no
  return m_sVersion;
  //## end CPIPersistentSoftwareComponentVersion::GetsVersion%3DB904D70018.get
}

// Additional Declarations
  //## begin CPIPersistentSoftwareComponentVersion%3DB9049E01CD.declarations preserve=yes
  //## end CPIPersistentSoftwareComponentVersion%3DB9049E01CD.declarations

// Class CPITemperatureControlProfile 









CPITemperatureControlProfile::CPITemperatureControlProfile (int p_iTemperatureNominal, int p_iTemperatureWarningULimit, int p_iTemperatureWarningLLimit, int p_iTemperatureErrorULimit, int p_iTemperatureErrorLLimit)
  //## begin CPITemperatureControlProfile::CPITemperatureControlProfile%1049124052.hasinit preserve=no
      : m_iTemperatureNominal(p_iTemperatureNominal), m_iTemperatureWarningULimit(p_iTemperatureWarningULimit), m_iTemperatureWarningLLimit(p_iTemperatureWarningLLimit), m_iTemperatureErrorULimit(p_iTemperatureErrorULimit), m_iTemperatureErrorLLimit(p_iTemperatureErrorLLimit)
  //## end CPITemperatureControlProfile::CPITemperatureControlProfile%1049124052.hasinit
  //## begin CPITemperatureControlProfile::CPITemperatureControlProfile%1049124052.initialization preserve=yes
  //## end CPITemperatureControlProfile::CPITemperatureControlProfile%1049124052.initialization
{
  //## begin CPITemperatureControlProfile::CPITemperatureControlProfile%1049124052.body preserve=yes
  //## end CPITemperatureControlProfile::CPITemperatureControlProfile%1049124052.body
}


CPITemperatureControlProfile::~CPITemperatureControlProfile()
{
  //## begin CPITemperatureControlProfile::~CPITemperatureControlProfile%.body preserve=yes
  //## end CPITemperatureControlProfile::~CPITemperatureControlProfile%.body
}


//## Get and Set Operations for Class Attributes (implementation)

int CPITemperatureControlProfile::GetiTemperatureNominal ()
{
  //## begin CPITemperatureControlProfile::GetiTemperatureNominal%3DB93F4202A8.get preserve=no
  return m_iTemperatureNominal;
  //## end CPITemperatureControlProfile::GetiTemperatureNominal%3DB93F4202A8.get
}

int CPITemperatureControlProfile::GetiTemperatureWarningULimit ()
{
  //## begin CPITemperatureControlProfile::GetiTemperatureWarningULimit%3DB9387F03E1.get preserve=no
  return m_iTemperatureWarningULimit;
  //## end CPITemperatureControlProfile::GetiTemperatureWarningULimit%3DB9387F03E1.get
}

int CPITemperatureControlProfile::GetiTemperatureWarningLLimit ()
{
  //## begin CPITemperatureControlProfile::GetiTemperatureWarningLLimit%3DB938500364.get preserve=no
  return m_iTemperatureWarningLLimit;
  //## end CPITemperatureControlProfile::GetiTemperatureWarningLLimit%3DB938500364.get
}

int CPITemperatureControlProfile::GetiTemperatureErrorULimit ()
{
  //## begin CPITemperatureControlProfile::GetiTemperatureErrorULimit%3DB9389F01CD.get preserve=no
  return m_iTemperatureErrorULimit;
  //## end CPITemperatureControlProfile::GetiTemperatureErrorULimit%3DB9389F01CD.get
}

int CPITemperatureControlProfile::GetiTemperatureErrorLLimit ()
{
  //## begin CPITemperatureControlProfile::GetiTemperatureErrorLLimit%3DB9388C026A.get preserve=no
  return m_iTemperatureErrorLLimit;
  //## end CPITemperatureControlProfile::GetiTemperatureErrorLLimit%3DB9388C026A.get
}

// Additional Declarations
  //## begin CPITemperatureControlProfile%3DB937ED017F.declarations preserve=yes
  //## end CPITemperatureControlProfile%3DB937ED017F.declarations

// Class CPITemperatureControlConfig 
















CPITemperatureControlConfig::CPITemperatureControlConfig (const int p_iPid_Kp, const int p_iPid_Ti, const int p_iPid_Tv, const int p_iPid_LLimit, const int p_iPid_ULimit, const int p_iPid_Ts, EPILineVoltage p_eLineVoltage, const DWORD p_dwIDHeaterTemperatureSensor, const DWORD p_dwIDHeaterOutput, CPIConfigDS1631Z* p_pSensorConfig)
  //## begin CPITemperatureControlConfig::CPITemperatureControlConfig%1035548922.hasinit preserve=no
      : m_iPid_Kp(p_iPid_Kp), m_iPid_Ti(p_iPid_Ti), m_iPid_Tv(p_iPid_Tv), m_iPid_LLimit(p_iPid_LLimit), m_iPid_ULimit(p_iPid_ULimit), m_iPid_Ts(p_iPid_Ts), m_dwIDHeaterTemperatureSensor(p_dwIDHeaterTemperatureSensor), m_dwIDHeaterOutput(p_dwIDHeaterOutput), m_pSensorConfig(p_pSensorConfig), m_eLineVoltage(p_eLineVoltage)
  //## end CPITemperatureControlConfig::CPITemperatureControlConfig%1035548922.hasinit
  //## begin CPITemperatureControlConfig::CPITemperatureControlConfig%1035548922.initialization preserve=yes
  //## end CPITemperatureControlConfig::CPITemperatureControlConfig%1035548922.initialization
{
  //## begin CPITemperatureControlConfig::CPITemperatureControlConfig%1035548922.body preserve=yes
	m_pSensorConfig->AddRef();
  //## end CPITemperatureControlConfig::CPITemperatureControlConfig%1035548922.body
}


CPITemperatureControlConfig::~CPITemperatureControlConfig()
{
  //## begin CPITemperatureControlConfig::~CPITemperatureControlConfig%.body preserve=yes
	if (m_pSensorConfig)
		m_pSensorConfig->ReleaseRef();
	m_pSensorConfig = NULL;
  //## end CPITemperatureControlConfig::~CPITemperatureControlConfig%.body
}


//## Get and Set Operations for Class Attributes (implementation)

INT CPITemperatureControlConfig::GetiPid_Kp ()
{
  //## begin CPITemperatureControlConfig::GetiPid_Kp%3E5C7DAA0321.get preserve=no
  return m_iPid_Kp;
  //## end CPITemperatureControlConfig::GetiPid_Kp%3E5C7DAA0321.get
}

INT CPITemperatureControlConfig::GetiPid_Ti ()
{
  //## begin CPITemperatureControlConfig::GetiPid_Ti%3E5C7DF401B9.get preserve=no
  return m_iPid_Ti;
  //## end CPITemperatureControlConfig::GetiPid_Ti%3E5C7DF401B9.get
}

INT CPITemperatureControlConfig::GetiPid_Tv ()
{
  //## begin CPITemperatureControlConfig::GetiPid_Tv%3E5C7E0F00DE.get preserve=no
  return m_iPid_Tv;
  //## end CPITemperatureControlConfig::GetiPid_Tv%3E5C7E0F00DE.get
}

INT CPITemperatureControlConfig::GetiPid_LLimit ()
{
  //## begin CPITemperatureControlConfig::GetiPid_LLimit%3E5C7E94035F.get preserve=no
  return m_iPid_LLimit;
  //## end CPITemperatureControlConfig::GetiPid_LLimit%3E5C7E94035F.get
}

INT CPITemperatureControlConfig::GetiPid_ULimit ()
{
  //## begin CPITemperatureControlConfig::GetiPid_ULimit%40D14CEF0157.get preserve=no
  return m_iPid_ULimit;
  //## end CPITemperatureControlConfig::GetiPid_ULimit%40D14CEF0157.get
}

INT CPITemperatureControlConfig::GetiPid_Ts ()
{
  //## begin CPITemperatureControlConfig::GetiPid_Ts%3E5C7EC00071.get preserve=no
  return m_iPid_Ts;
  //## end CPITemperatureControlConfig::GetiPid_Ts%3E5C7EC00071.get
}

const DWORD CPITemperatureControlConfig::GetdwIDHeaterTemperatureSensor ()
{
  //## begin CPITemperatureControlConfig::GetdwIDHeaterTemperatureSensor%3F151FC300A4.get preserve=no
  return m_dwIDHeaterTemperatureSensor;
  //## end CPITemperatureControlConfig::GetdwIDHeaterTemperatureSensor%3F151FC300A4.get
}

DWORD CPITemperatureControlConfig::GetdwIDHeaterOutput ()
{
  //## begin CPITemperatureControlConfig::GetdwIDHeaterOutput%3F15204E03B1.get preserve=no
  return m_dwIDHeaterOutput;
  //## end CPITemperatureControlConfig::GetdwIDHeaterOutput%3F15204E03B1.get
}

//## Get and Set Operations for Associations (implementation)

CPIConfigDS1631Z * CPITemperatureControlConfig::GetpSensorConfig ()
{
  //## begin CPITemperatureControlConfig::GetpSensorConfig%40C9ADE8000C.get preserve=no
  return m_pSensorConfig;
  //## end CPITemperatureControlConfig::GetpSensorConfig%40C9ADE8000C.get
}

EPILineVoltage CPITemperatureControlConfig::GeteLineVoltage ()
{
  //## begin CPITemperatureControlConfig::GeteLineVoltage%41947CE30292.get preserve=no
  return m_eLineVoltage;
  //## end CPITemperatureControlConfig::GeteLineVoltage%41947CE30292.get
}

// Additional Declarations
  //## begin CPITemperatureControlConfig%3DB93818022B.declarations preserve=yes
  //## end CPITemperatureControlConfig%3DB93818022B.declarations

// Class CPIPowerControlProfile 







CPIPowerControlProfile::CPIPowerControlProfile (const UINT p_uiPowerNominal, const UINT p_uiPowerErrorULimit, const UINT p_uiPowerErrorLLimit)
  //## begin CPIPowerControlProfile::CPIPowerControlProfile%1049124051.hasinit preserve=no
      : m_uiPowerNominal(p_uiPowerNominal), m_uiPowerErrorULimit(p_uiPowerErrorULimit), m_uiPowerErrorLLimit(p_uiPowerErrorLLimit)
  //## end CPIPowerControlProfile::CPIPowerControlProfile%1049124051.hasinit
  //## begin CPIPowerControlProfile::CPIPowerControlProfile%1049124051.initialization preserve=yes
  //## end CPIPowerControlProfile::CPIPowerControlProfile%1049124051.initialization
{
  //## begin CPIPowerControlProfile::CPIPowerControlProfile%1049124051.body preserve=yes
  //## end CPIPowerControlProfile::CPIPowerControlProfile%1049124051.body
}


CPIPowerControlProfile::~CPIPowerControlProfile()
{
  //## begin CPIPowerControlProfile::~CPIPowerControlProfile%.body preserve=yes
  //## end CPIPowerControlProfile::~CPIPowerControlProfile%.body
}


//## Get and Set Operations for Class Attributes (implementation)

UINT CPIPowerControlProfile::GetuiPowerNominal ()
{
  //## begin CPIPowerControlProfile::GetuiPowerNominal%3E8961F3006D.get preserve=no
  return m_uiPowerNominal;
  //## end CPIPowerControlProfile::GetuiPowerNominal%3E8961F3006D.get
}

UINT CPIPowerControlProfile::GetuiPowerErrorULimit ()
{
  //## begin CPIPowerControlProfile::GetuiPowerErrorULimit%3E8962000271.get preserve=no
  return m_uiPowerErrorULimit;
  //## end CPIPowerControlProfile::GetuiPowerErrorULimit%3E8962000271.get
}

UINT CPIPowerControlProfile::GetuiPowerErrorLLimit ()
{
  //## begin CPIPowerControlProfile::GetuiPowerErrorLLimit%3E8961FE029F.get preserve=no
  return m_uiPowerErrorLLimit;
  //## end CPIPowerControlProfile::GetuiPowerErrorLLimit%3E8961FE029F.get
}

// Additional Declarations
  //## begin CPIPowerControlProfile%3DB9480101BE.declarations preserve=yes
  //## end CPIPowerControlProfile%3DB9480101BE.declarations

// Class CPIWedgeControlProfile 






CPIWedgeControlProfile::CPIWedgeControlProfile (DWORD p_dwScanMode, DWORD p_dwRefDistance2)
  //## begin CPIWedgeControlProfile::CPIWedgeControlProfile%1043748202.hasinit preserve=no
      : m_dwScanMode(p_dwScanMode), m_dwRefDistance2(p_dwRefDistance2)
  //## end CPIWedgeControlProfile::CPIWedgeControlProfile%1043748202.hasinit
  //## begin CPIWedgeControlProfile::CPIWedgeControlProfile%1043748202.initialization preserve=yes
  //## end CPIWedgeControlProfile::CPIWedgeControlProfile%1043748202.initialization
{
  //## begin CPIWedgeControlProfile::CPIWedgeControlProfile%1043748202.body preserve=yes
  //## end CPIWedgeControlProfile::CPIWedgeControlProfile%1043748202.body
}


CPIWedgeControlProfile::~CPIWedgeControlProfile()
{
  //## begin CPIWedgeControlProfile::~CPIWedgeControlProfile%.body preserve=yes
  //## end CPIWedgeControlProfile::~CPIWedgeControlProfile%.body
}


//## Get and Set Operations for Class Attributes (implementation)

const DWORD CPIWedgeControlProfile::GetdwScanMode () const
{
  //## begin CPIWedgeControlProfile::GetdwScanMode%3FBC8ED501A5.get preserve=no
  return m_dwScanMode;
  //## end CPIWedgeControlProfile::GetdwScanMode%3FBC8ED501A5.get
}

void CPIWedgeControlProfile::SetdwScanMode (DWORD value)
{
  //## begin CPIWedgeControlProfile::SetdwScanMode%3FBC8ED501A5.set preserve=no
  m_dwScanMode = value;
  //## end CPIWedgeControlProfile::SetdwScanMode%3FBC8ED501A5.set
}

const DWORD CPIWedgeControlProfile::GetdwRefDistance2 () const
{
  //## begin CPIWedgeControlProfile::GetdwRefDistance2%3E2E73A100F7.get preserve=no
  return m_dwRefDistance2;
  //## end CPIWedgeControlProfile::GetdwRefDistance2%3E2E73A100F7.get
}

void CPIWedgeControlProfile::SetdwRefDistance2 (DWORD value)
{
  //## begin CPIWedgeControlProfile::SetdwRefDistance2%3E2E73A100F7.set preserve=no
  m_dwRefDistance2 = value;
  //## end CPIWedgeControlProfile::SetdwRefDistance2%3E2E73A100F7.set
}

// Additional Declarations
  //## begin CPIWedgeControlProfile%3DB9494E0354.declarations preserve=yes
  //## end CPIWedgeControlProfile%3DB9494E0354.declarations

// Class CPIWedgeControlConfig 







































CPIWedgeControlConfig::CPIWedgeControlConfig (DWORD p_dwNomVelocity, DWORD p_dwNomAcc, DWORD p_dwNomDec, DWORD p_dwWedgeControllerVelocityEdge, DWORD p_dwStaticFrictionForward, DWORD p_dwStaticFrictionBackward, DWORD p_dwVelocityWarnHighRange, DWORD p_dwVelocityWarnLowRange, DWORD p_dwVelocityErrorHighRange, DWORD p_dwVelocityErrorLowRange, DWORD p_dwForwardStartDistance, DWORD p_dwForwardEndDistance, DWORD p_dwMeasuringDistance, DWORD p_dwBackwardStartDistance, DWORD p_dwRefDistance1, DWORD p_dwWC_P, DWORD p_dwWC_TN, DWORD p_dwWC_TV, DWORD p_dwWC_Kdac, DWORD p_dwWC_Gain_DAC, DWORD p_dwWC_Offset_DAC, DWORD p_dwDACLimitUp, DWORD p_dwDACLimitDown, DWORD p_dwDACLimitSlewRate, DWORD p_dwRunAfterTime, DWORD p_dwMaxCurrentTime, DWORD p_dwAccStandBy, DWORD p_dwWCIdInitializedEvent, DWORD p_dwWCIdReferencedEvent, DWORD p_dwWCIdStoppedEvent, DWORD p_dwWCIdParkedEvent, DWORD p_dwWCIdCurDirEvent, DWORD p_dwWCLightBarrierEvent, DWORD p_dwWCIdMeasuringExcEvent, DWORD p_dwWCIdCurDirInput)
  //## begin CPIWedgeControlConfig::CPIWedgeControlConfig%1043229923.hasinit preserve=no
      : m_dwNomVelocity(p_dwNomVelocity), m_dwNomAcc(p_dwNomAcc), m_dwNomDec(p_dwNomDec), m_dwWedgeControllerVelocityEdge(p_dwWedgeControllerVelocityEdge), m_dwStaticFrictionForward(p_dwStaticFrictionForward), m_dwStaticFrictionBackward(p_dwStaticFrictionBackward), m_dwVelocityWarnHighRange(p_dwVelocityWarnHighRange), m_dwVelocityWarnLowRange(p_dwVelocityWarnLowRange), m_dwVelocityErrorHighRange(p_dwVelocityErrorHighRange), m_dwVelocityErrorLowRange(p_dwVelocityErrorLowRange), m_dwForwardStartDistance(p_dwForwardStartDistance), m_dwForwardEndDistance(p_dwForwardEndDistance), m_dwMeasuringDistance(p_dwMeasuringDistance), m_dwBackwardStartDistance(p_dwBackwardStartDistance), m_dwRefDistance1(p_dwRefDistance1), m_dwWC_P(p_dwWC_P), m_dwWC_TN(p_dwWC_TN), m_dwWC_TV(p_dwWC_TV), m_dwWC_Kdac(p_dwWC_Kdac), m_dwWC_Gain_DAC(p_dwWC_Gain_DAC), m_dwWC_Offset_DAC(p_dwWC_Offset_DAC), m_dwDACLimitUp(p_dwDACLimitUp), m_dwDACLimitDown(p_dwDACLimitDown), m_dwDACLimitSlewRate(p_dwDACLimitSlewRate), m_dwRunAfterTime(p_dwRunAfterTime), m_dwMaxCurrentTime(p_dwMaxCurrentTime), m_dwAccStandBy(p_dwAccStandBy), m_dwWCIdInitializedEvent(p_dwWCIdInitializedEvent), m_dwWCIdReferencedEvent(p_dwWCIdReferencedEvent), m_dwWCIdStoppedEvent(p_dwWCIdStoppedEvent), m_dwWCIdParkedEvent(p_dwWCIdParkedEvent), m_dwWCIdCurDirEvent(p_dwWCIdCurDirEvent), m_dwWCLightBarrierEvent(p_dwWCLightBarrierEvent), m_dwWCIdMeasuringExcEvent(p_dwWCIdMeasuringExcEvent), m_dwWCIdCurDirInput(p_dwWCIdCurDirInput)
  //## end CPIWedgeControlConfig::CPIWedgeControlConfig%1043229923.hasinit
  //## begin CPIWedgeControlConfig::CPIWedgeControlConfig%1043229923.initialization preserve=yes
  //## end CPIWedgeControlConfig::CPIWedgeControlConfig%1043229923.initialization
{
  //## begin CPIWedgeControlConfig::CPIWedgeControlConfig%1043229923.body preserve=yes
  //## end CPIWedgeControlConfig::CPIWedgeControlConfig%1043229923.body
}


CPIWedgeControlConfig::~CPIWedgeControlConfig()
{
  //## begin CPIWedgeControlConfig::~CPIWedgeControlConfig%.body preserve=yes
  //## end CPIWedgeControlConfig::~CPIWedgeControlConfig%.body
}


//## Get and Set Operations for Class Attributes (implementation)

const DWORD CPIWedgeControlConfig::GetdwNomVelocity () const
{
  //## begin CPIWedgeControlConfig::GetdwNomVelocity%3E36570B0280.get preserve=no
  return m_dwNomVelocity;
  //## end CPIWedgeControlConfig::GetdwNomVelocity%3E36570B0280.get
}

void CPIWedgeControlConfig::SetdwNomVelocity (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwNomVelocity%3E36570B0280.set preserve=no
  m_dwNomVelocity = value;
  //## end CPIWedgeControlConfig::SetdwNomVelocity%3E36570B0280.set
}

const DWORD CPIWedgeControlConfig::GetdwNomAcc () const
{
  //## begin CPIWedgeControlConfig::GetdwNomAcc%3E36568E0148.get preserve=no
  return m_dwNomAcc;
  //## end CPIWedgeControlConfig::GetdwNomAcc%3E36568E0148.get
}

void CPIWedgeControlConfig::SetdwNomAcc (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwNomAcc%3E36568E0148.set preserve=no
  m_dwNomAcc = value;
  //## end CPIWedgeControlConfig::SetdwNomAcc%3E36568E0148.set
}

const DWORD CPIWedgeControlConfig::GetdwNomDec () const
{
  //## begin CPIWedgeControlConfig::GetdwNomDec%3E3656D6029F.get preserve=no
  return m_dwNomDec;
  //## end CPIWedgeControlConfig::GetdwNomDec%3E3656D6029F.get
}

void CPIWedgeControlConfig::SetdwNomDec (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwNomDec%3E3656D6029F.set preserve=no
  m_dwNomDec = value;
  //## end CPIWedgeControlConfig::SetdwNomDec%3E3656D6029F.set
}

const DWORD CPIWedgeControlConfig::GetdwWedgeControllerVelocityEdge () const
{
  //## begin CPIWedgeControlConfig::GetdwWedgeControllerVelocityEdge%3FB4A9840138.get preserve=no
  return m_dwWedgeControllerVelocityEdge;
  //## end CPIWedgeControlConfig::GetdwWedgeControllerVelocityEdge%3FB4A9840138.get
}

void CPIWedgeControlConfig::SetdwWedgeControllerVelocityEdge (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWedgeControllerVelocityEdge%3FB4A9840138.set preserve=no
  m_dwWedgeControllerVelocityEdge = value;
  //## end CPIWedgeControlConfig::SetdwWedgeControllerVelocityEdge%3FB4A9840138.set
}

const DWORD CPIWedgeControlConfig::GetdwStaticFrictionForward () const
{
  //## begin CPIWedgeControlConfig::GetdwStaticFrictionForward%402B97560251.get preserve=no
  return m_dwStaticFrictionForward;
  //## end CPIWedgeControlConfig::GetdwStaticFrictionForward%402B97560251.get
}

void CPIWedgeControlConfig::SetdwStaticFrictionForward (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwStaticFrictionForward%402B97560251.set preserve=no
  m_dwStaticFrictionForward = value;
  //## end CPIWedgeControlConfig::SetdwStaticFrictionForward%402B97560251.set
}

const DWORD CPIWedgeControlConfig::GetdwStaticFrictionBackward () const
{
  //## begin CPIWedgeControlConfig::GetdwStaticFrictionBackward%402B98E202DE.get preserve=no
  return m_dwStaticFrictionBackward;
  //## end CPIWedgeControlConfig::GetdwStaticFrictionBackward%402B98E202DE.get
}

void CPIWedgeControlConfig::SetdwStaticFrictionBackward (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwStaticFrictionBackward%402B98E202DE.set preserve=no
  m_dwStaticFrictionBackward = value;
  //## end CPIWedgeControlConfig::SetdwStaticFrictionBackward%402B98E202DE.set
}

const DWORD CPIWedgeControlConfig::GetdwVelocityWarnHighRange () const
{
  //## begin CPIWedgeControlConfig::GetdwVelocityWarnHighRange%3E2E69C100A9.get preserve=no
  return m_dwVelocityWarnHighRange;
  //## end CPIWedgeControlConfig::GetdwVelocityWarnHighRange%3E2E69C100A9.get
}

void CPIWedgeControlConfig::SetdwVelocityWarnHighRange (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwVelocityWarnHighRange%3E2E69C100A9.set preserve=no
  m_dwVelocityWarnHighRange = value;
  //## end CPIWedgeControlConfig::SetdwVelocityWarnHighRange%3E2E69C100A9.set
}

const DWORD CPIWedgeControlConfig::GetdwVelocityWarnLowRange () const
{
  //## begin CPIWedgeControlConfig::GetdwVelocityWarnLowRange%3E2E6D670117.get preserve=no
  return m_dwVelocityWarnLowRange;
  //## end CPIWedgeControlConfig::GetdwVelocityWarnLowRange%3E2E6D670117.get
}

void CPIWedgeControlConfig::SetdwVelocityWarnLowRange (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwVelocityWarnLowRange%3E2E6D670117.set preserve=no
  m_dwVelocityWarnLowRange = value;
  //## end CPIWedgeControlConfig::SetdwVelocityWarnLowRange%3E2E6D670117.set
}

const DWORD CPIWedgeControlConfig::GetdwVelocityErrorHighRange () const
{
  //## begin CPIWedgeControlConfig::GetdwVelocityErrorHighRange%3E2E6FA80201.get preserve=no
  return m_dwVelocityErrorHighRange;
  //## end CPIWedgeControlConfig::GetdwVelocityErrorHighRange%3E2E6FA80201.get
}

void CPIWedgeControlConfig::SetdwVelocityErrorHighRange (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwVelocityErrorHighRange%3E2E6FA80201.set preserve=no
  m_dwVelocityErrorHighRange = value;
  //## end CPIWedgeControlConfig::SetdwVelocityErrorHighRange%3E2E6FA80201.set
}

const DWORD CPIWedgeControlConfig::GetdwVelocityErrorLowRange () const
{
  //## begin CPIWedgeControlConfig::GetdwVelocityErrorLowRange%3E2E708A01F1.get preserve=no
  return m_dwVelocityErrorLowRange;
  //## end CPIWedgeControlConfig::GetdwVelocityErrorLowRange%3E2E708A01F1.get
}

void CPIWedgeControlConfig::SetdwVelocityErrorLowRange (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwVelocityErrorLowRange%3E2E708A01F1.set preserve=no
  m_dwVelocityErrorLowRange = value;
  //## end CPIWedgeControlConfig::SetdwVelocityErrorLowRange%3E2E708A01F1.set
}

const DWORD CPIWedgeControlConfig::GetdwForwardStartDistance () const
{
  //## begin CPIWedgeControlConfig::GetdwForwardStartDistance%3E2E720D0136.get preserve=no
  return m_dwForwardStartDistance;
  //## end CPIWedgeControlConfig::GetdwForwardStartDistance%3E2E720D0136.get
}

void CPIWedgeControlConfig::SetdwForwardStartDistance (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwForwardStartDistance%3E2E720D0136.set preserve=no
  m_dwForwardStartDistance = value;
  //## end CPIWedgeControlConfig::SetdwForwardStartDistance%3E2E720D0136.set
}

const DWORD CPIWedgeControlConfig::GetdwForwardEndDistance () const
{
  //## begin CPIWedgeControlConfig::GetdwForwardEndDistance%3E2E7274024F.get preserve=no
  return m_dwForwardEndDistance;
  //## end CPIWedgeControlConfig::GetdwForwardEndDistance%3E2E7274024F.get
}

void CPIWedgeControlConfig::SetdwForwardEndDistance (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwForwardEndDistance%3E2E7274024F.set preserve=no
  m_dwForwardEndDistance = value;
  //## end CPIWedgeControlConfig::SetdwForwardEndDistance%3E2E7274024F.set
}

const DWORD CPIWedgeControlConfig::GetdwMeasuringDistance () const
{
  //## begin CPIWedgeControlConfig::GetdwMeasuringDistance%3E2E72A20339.get preserve=no
  return m_dwMeasuringDistance;
  //## end CPIWedgeControlConfig::GetdwMeasuringDistance%3E2E72A20339.get
}

void CPIWedgeControlConfig::SetdwMeasuringDistance (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwMeasuringDistance%3E2E72A20339.set preserve=no
  m_dwMeasuringDistance = value;
  //## end CPIWedgeControlConfig::SetdwMeasuringDistance%3E2E72A20339.set
}

const DWORD CPIWedgeControlConfig::GetdwBackwardStartDistance () const
{
  //## begin CPIWedgeControlConfig::GetdwBackwardStartDistance%3E2E72FE02EB.get preserve=no
  return m_dwBackwardStartDistance;
  //## end CPIWedgeControlConfig::GetdwBackwardStartDistance%3E2E72FE02EB.get
}

void CPIWedgeControlConfig::SetdwBackwardStartDistance (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwBackwardStartDistance%3E2E72FE02EB.set preserve=no
  m_dwBackwardStartDistance = value;
  //## end CPIWedgeControlConfig::SetdwBackwardStartDistance%3E2E72FE02EB.set
}

const DWORD CPIWedgeControlConfig::GetdwRefDistance1 () const
{
  //## begin CPIWedgeControlConfig::GetdwRefDistance1%3E2E737002DC.get preserve=no
  return m_dwRefDistance1;
  //## end CPIWedgeControlConfig::GetdwRefDistance1%3E2E737002DC.get
}

void CPIWedgeControlConfig::SetdwRefDistance1 (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwRefDistance1%3E2E737002DC.set preserve=no
  m_dwRefDistance1 = value;
  //## end CPIWedgeControlConfig::SetdwRefDistance1%3E2E737002DC.set
}

const DWORD CPIWedgeControlConfig::GetdwWC_P () const
{
  //## begin CPIWedgeControlConfig::GetdwWC_P%3E2E73EF005B.get preserve=no
  return m_dwWC_P;
  //## end CPIWedgeControlConfig::GetdwWC_P%3E2E73EF005B.get
}

void CPIWedgeControlConfig::SetdwWC_P (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWC_P%3E2E73EF005B.set preserve=no
  m_dwWC_P = value;
  //## end CPIWedgeControlConfig::SetdwWC_P%3E2E73EF005B.set
}

const DWORD CPIWedgeControlConfig::GetdwWC_TN () const
{
  //## begin CPIWedgeControlConfig::GetdwWC_TN%3E2E741102DC.get preserve=no
  return m_dwWC_TN;
  //## end CPIWedgeControlConfig::GetdwWC_TN%3E2E741102DC.get
}

void CPIWedgeControlConfig::SetdwWC_TN (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWC_TN%3E2E741102DC.set preserve=no
  m_dwWC_TN = value;
  //## end CPIWedgeControlConfig::SetdwWC_TN%3E2E741102DC.set
}

const DWORD CPIWedgeControlConfig::GetdwWC_TV () const
{
  //## begin CPIWedgeControlConfig::GetdwWC_TV%3E2E7437009A.get preserve=no
  return m_dwWC_TV;
  //## end CPIWedgeControlConfig::GetdwWC_TV%3E2E7437009A.get
}

void CPIWedgeControlConfig::SetdwWC_TV (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWC_TV%3E2E7437009A.set preserve=no
  m_dwWC_TV = value;
  //## end CPIWedgeControlConfig::SetdwWC_TV%3E2E7437009A.set
}

const DWORD CPIWedgeControlConfig::GetdwWC_Kdac () const
{
  //## begin CPIWedgeControlConfig::GetdwWC_Kdac%3F9642460177.get preserve=no
  return m_dwWC_Kdac;
  //## end CPIWedgeControlConfig::GetdwWC_Kdac%3F9642460177.get
}

void CPIWedgeControlConfig::SetdwWC_Kdac (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWC_Kdac%3F9642460177.set preserve=no
  m_dwWC_Kdac = value;
  //## end CPIWedgeControlConfig::SetdwWC_Kdac%3F9642460177.set
}

const DWORD CPIWedgeControlConfig::GetdwWC_Gain_DAC () const
{
  //## begin CPIWedgeControlConfig::GetdwWC_Gain_DAC%3F9642780242.get preserve=no
  return m_dwWC_Gain_DAC;
  //## end CPIWedgeControlConfig::GetdwWC_Gain_DAC%3F9642780242.get
}

void CPIWedgeControlConfig::SetdwWC_Gain_DAC (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWC_Gain_DAC%3F9642780242.set preserve=no
  m_dwWC_Gain_DAC = value;
  //## end CPIWedgeControlConfig::SetdwWC_Gain_DAC%3F9642780242.set
}

const DWORD CPIWedgeControlConfig::GetdwWC_Offset_DAC () const
{
  //## begin CPIWedgeControlConfig::GetdwWC_Offset_DAC%3F9642AF0119.get preserve=no
  return m_dwWC_Offset_DAC;
  //## end CPIWedgeControlConfig::GetdwWC_Offset_DAC%3F9642AF0119.get
}

void CPIWedgeControlConfig::SetdwWC_Offset_DAC (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWC_Offset_DAC%3F9642AF0119.set preserve=no
  m_dwWC_Offset_DAC = value;
  //## end CPIWedgeControlConfig::SetdwWC_Offset_DAC%3F9642AF0119.set
}

const DWORD CPIWedgeControlConfig::GetdwDACLimitUp () const
{
  //## begin CPIWedgeControlConfig::GetdwDACLimitUp%3E2E74570174.get preserve=no
  return m_dwDACLimitUp;
  //## end CPIWedgeControlConfig::GetdwDACLimitUp%3E2E74570174.get
}

void CPIWedgeControlConfig::SetdwDACLimitUp (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwDACLimitUp%3E2E74570174.set preserve=no
  m_dwDACLimitUp = value;
  //## end CPIWedgeControlConfig::SetdwDACLimitUp%3E2E74570174.set
}

const DWORD CPIWedgeControlConfig::GetdwDACLimitDown () const
{
  //## begin CPIWedgeControlConfig::GetdwDACLimitDown%3E2E748A0397.get preserve=no
  return m_dwDACLimitDown;
  //## end CPIWedgeControlConfig::GetdwDACLimitDown%3E2E748A0397.get
}

void CPIWedgeControlConfig::SetdwDACLimitDown (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwDACLimitDown%3E2E748A0397.set preserve=no
  m_dwDACLimitDown = value;
  //## end CPIWedgeControlConfig::SetdwDACLimitDown%3E2E748A0397.set
}

const DWORD CPIWedgeControlConfig::GetdwDACLimitSlewRate () const
{
  //## begin CPIWedgeControlConfig::GetdwDACLimitSlewRate%3F9642CE03A9.get preserve=no
  return m_dwDACLimitSlewRate;
  //## end CPIWedgeControlConfig::GetdwDACLimitSlewRate%3F9642CE03A9.get
}

void CPIWedgeControlConfig::SetdwDACLimitSlewRate (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwDACLimitSlewRate%3F9642CE03A9.set preserve=no
  m_dwDACLimitSlewRate = value;
  //## end CPIWedgeControlConfig::SetdwDACLimitSlewRate%3F9642CE03A9.set
}

const DWORD CPIWedgeControlConfig::GetdwRunAfterTime () const
{
  //## begin CPIWedgeControlConfig::GetdwRunAfterTime%3E2E74AD01D2.get preserve=no
  return m_dwRunAfterTime;
  //## end CPIWedgeControlConfig::GetdwRunAfterTime%3E2E74AD01D2.get
}

void CPIWedgeControlConfig::SetdwRunAfterTime (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwRunAfterTime%3E2E74AD01D2.set preserve=no
  m_dwRunAfterTime = value;
  //## end CPIWedgeControlConfig::SetdwRunAfterTime%3E2E74AD01D2.set
}

const DWORD CPIWedgeControlConfig::GetdwMaxCurrentTime () const
{
  //## begin CPIWedgeControlConfig::GetdwMaxCurrentTime%402B948E0213.get preserve=no
  return m_dwMaxCurrentTime;
  //## end CPIWedgeControlConfig::GetdwMaxCurrentTime%402B948E0213.get
}

void CPIWedgeControlConfig::SetdwMaxCurrentTime (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwMaxCurrentTime%402B948E0213.set preserve=no
  m_dwMaxCurrentTime = value;
  //## end CPIWedgeControlConfig::SetdwMaxCurrentTime%402B948E0213.set
}

const DWORD CPIWedgeControlConfig::GetdwAccStandBy () const
{
  //## begin CPIWedgeControlConfig::GetdwAccStandBy%3E53A45700AB.get preserve=no
  return m_dwAccStandBy;
  //## end CPIWedgeControlConfig::GetdwAccStandBy%3E53A45700AB.get
}

void CPIWedgeControlConfig::SetdwAccStandBy (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwAccStandBy%3E53A45700AB.set preserve=no
  m_dwAccStandBy = value;
  //## end CPIWedgeControlConfig::SetdwAccStandBy%3E53A45700AB.set
}

const DWORD CPIWedgeControlConfig::GetdwWCIdInitializedEvent () const
{
  //## begin CPIWedgeControlConfig::GetdwWCIdInitializedEvent%3FB4A9CD031C.get preserve=no
  return m_dwWCIdInitializedEvent;
  //## end CPIWedgeControlConfig::GetdwWCIdInitializedEvent%3FB4A9CD031C.get
}

void CPIWedgeControlConfig::SetdwWCIdInitializedEvent (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWCIdInitializedEvent%3FB4A9CD031C.set preserve=no
  m_dwWCIdInitializedEvent = value;
  //## end CPIWedgeControlConfig::SetdwWCIdInitializedEvent%3FB4A9CD031C.set
}

const DWORD CPIWedgeControlConfig::GetdwWCIdReferencedEvent () const
{
  //## begin CPIWedgeControlConfig::GetdwWCIdReferencedEvent%3FB4A9FD008C.get preserve=no
  return m_dwWCIdReferencedEvent;
  //## end CPIWedgeControlConfig::GetdwWCIdReferencedEvent%3FB4A9FD008C.get
}

void CPIWedgeControlConfig::SetdwWCIdReferencedEvent (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWCIdReferencedEvent%3FB4A9FD008C.set preserve=no
  m_dwWCIdReferencedEvent = value;
  //## end CPIWedgeControlConfig::SetdwWCIdReferencedEvent%3FB4A9FD008C.set
}

const DWORD CPIWedgeControlConfig::GetdwWCIdStoppedEvent () const
{
  //## begin CPIWedgeControlConfig::GetdwWCIdStoppedEvent%3FB4A9FD030D.get preserve=no
  return m_dwWCIdStoppedEvent;
  //## end CPIWedgeControlConfig::GetdwWCIdStoppedEvent%3FB4A9FD030D.get
}

void CPIWedgeControlConfig::SetdwWCIdStoppedEvent (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWCIdStoppedEvent%3FB4A9FD030D.set preserve=no
  m_dwWCIdStoppedEvent = value;
  //## end CPIWedgeControlConfig::SetdwWCIdStoppedEvent%3FB4A9FD030D.set
}

const DWORD CPIWedgeControlConfig::GetdwWCIdParkedEvent () const
{
  //## begin CPIWedgeControlConfig::GetdwWCIdParkedEvent%3FB4A9FE00FA.get preserve=no
  return m_dwWCIdParkedEvent;
  //## end CPIWedgeControlConfig::GetdwWCIdParkedEvent%3FB4A9FE00FA.get
}

void CPIWedgeControlConfig::SetdwWCIdParkedEvent (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWCIdParkedEvent%3FB4A9FE00FA.set preserve=no
  m_dwWCIdParkedEvent = value;
  //## end CPIWedgeControlConfig::SetdwWCIdParkedEvent%3FB4A9FE00FA.set
}

const DWORD CPIWedgeControlConfig::GetdwWCIdCurDirEvent () const
{
  //## begin CPIWedgeControlConfig::GetdwWCIdCurDirEvent%3FBB74B2037A.get preserve=no
  return m_dwWCIdCurDirEvent;
  //## end CPIWedgeControlConfig::GetdwWCIdCurDirEvent%3FBB74B2037A.get
}

void CPIWedgeControlConfig::SetdwWCIdCurDirEvent (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWCIdCurDirEvent%3FBB74B2037A.set preserve=no
  m_dwWCIdCurDirEvent = value;
  //## end CPIWedgeControlConfig::SetdwWCIdCurDirEvent%3FBB74B2037A.set
}

const DWORD CPIWedgeControlConfig::GetdwWCLightBarrierEvent () const
{
  //## begin CPIWedgeControlConfig::GetdwWCLightBarrierEvent%3FD5A351031C.get preserve=no
  return m_dwWCLightBarrierEvent;
  //## end CPIWedgeControlConfig::GetdwWCLightBarrierEvent%3FD5A351031C.get
}

void CPIWedgeControlConfig::SetdwWCLightBarrierEvent (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWCLightBarrierEvent%3FD5A351031C.set preserve=no
  m_dwWCLightBarrierEvent = value;
  //## end CPIWedgeControlConfig::SetdwWCLightBarrierEvent%3FD5A351031C.set
}

const DWORD CPIWedgeControlConfig::GetdwWCIdMeasuringExcEvent () const
{
  //## begin CPIWedgeControlConfig::GetdwWCIdMeasuringExcEvent%402B93ED003E.get preserve=no
  return m_dwWCIdMeasuringExcEvent;
  //## end CPIWedgeControlConfig::GetdwWCIdMeasuringExcEvent%402B93ED003E.get
}

void CPIWedgeControlConfig::SetdwWCIdMeasuringExcEvent (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWCIdMeasuringExcEvent%402B93ED003E.set preserve=no
  m_dwWCIdMeasuringExcEvent = value;
  //## end CPIWedgeControlConfig::SetdwWCIdMeasuringExcEvent%402B93ED003E.set
}

const DWORD CPIWedgeControlConfig::GetdwWCIdCurDirInput () const
{
  //## begin CPIWedgeControlConfig::GetdwWCIdCurDirInput%3FBCD8E50399.get preserve=no
  return m_dwWCIdCurDirInput;
  //## end CPIWedgeControlConfig::GetdwWCIdCurDirInput%3FBCD8E50399.get
}

void CPIWedgeControlConfig::SetdwWCIdCurDirInput (DWORD value)
{
  //## begin CPIWedgeControlConfig::SetdwWCIdCurDirInput%3FBCD8E50399.set preserve=no
  m_dwWCIdCurDirInput = value;
  //## end CPIWedgeControlConfig::SetdwWCIdCurDirInput%3FBCD8E50399.set
}

// Additional Declarations
  //## begin CPIWedgeControlConfig%3DB9495C0095.declarations preserve=yes
  //## end CPIWedgeControlConfig%3DB9495C0095.declarations

// Class CPIMeasurementChannelProfile 







CPIMeasurementChannelProfile::CPIMeasurementChannelProfile (DWORD p_dwMinDataSize, DWORD p_dwMaxDataSize, DWORD p_dwStreamBufferSizeInByte)
  //## begin CPIMeasurementChannelProfile::CPIMeasurementChannelProfile%1047390943.hasinit preserve=no
      : m_dwMinDataSize(p_dwMinDataSize), m_dwMaxDataSize(p_dwMaxDataSize), m_dwStreamBufferSizeInByte(p_dwStreamBufferSizeInByte)
  //## end CPIMeasurementChannelProfile::CPIMeasurementChannelProfile%1047390943.hasinit
  //## begin CPIMeasurementChannelProfile::CPIMeasurementChannelProfile%1047390943.initialization preserve=yes
  //## end CPIMeasurementChannelProfile::CPIMeasurementChannelProfile%1047390943.initialization
{
  //## begin CPIMeasurementChannelProfile::CPIMeasurementChannelProfile%1047390943.body preserve=yes
  //## end CPIMeasurementChannelProfile::CPIMeasurementChannelProfile%1047390943.body
}


CPIMeasurementChannelProfile::~CPIMeasurementChannelProfile()
{
  //## begin CPIMeasurementChannelProfile::~CPIMeasurementChannelProfile%.body preserve=yes
  //## end CPIMeasurementChannelProfile::~CPIMeasurementChannelProfile%.body
}


//## Get and Set Operations for Class Attributes (implementation)

DWORD CPIMeasurementChannelProfile::GetdwMinDataSize ()
{
  //## begin CPIMeasurementChannelProfile::GetdwMinDataSize%3E6DEA91006D.get preserve=no
  return m_dwMinDataSize;
  //## end CPIMeasurementChannelProfile::GetdwMinDataSize%3E6DEA91006D.get
}

DWORD CPIMeasurementChannelProfile::GetdwMaxDataSize ()
{
  //## begin CPIMeasurementChannelProfile::GetdwMaxDataSize%3E6DEA91008C.get preserve=no
  return m_dwMaxDataSize;
  //## end CPIMeasurementChannelProfile::GetdwMaxDataSize%3E6DEA91008C.get
}

DWORD CPIMeasurementChannelProfile::GetdwStreamBufferSizeInByte ()
{
  //## begin CPIMeasurementChannelProfile::GetdwStreamBufferSizeInByte%40B5A5E50177.get preserve=no
  return m_dwStreamBufferSizeInByte;
  //## end CPIMeasurementChannelProfile::GetdwStreamBufferSizeInByte%40B5A5E50177.get
}

// Additional Declarations
  //## begin CPIMeasurementChannelProfile%3DBCE42E023C.declarations preserve=yes
  //## end CPIMeasurementChannelProfile%3DBCE42E023C.declarations

// Class CPIPowerControlConfig 






































CPIPowerControlConfig::CPIPowerControlConfig (const DWORD p_dwIDActCurrent, const DWORD p_dwIDActVoltage, const DWORD p_dwIDNomVoltage, const DWORD p_dwIDLampSelection, const DWORD p_dwIDLampOnOff, const UINT p_uiPid_Kp, const UINT p_uiPid_Ti, const UINT p_uiPid_Tv, const INT p_iPid_ULimit, const INT p_iPid_LLimit, const UINT p_uiPid_Ts, const UINT p_uiSoftStartDeltaVoltage, const UINT p_uiSoftStartDeltaTime, const UINT p_uiWarmUpTime, const UINT p_uiNominalVoltage, const UINT p_uiNominalVoltageLLimit, const UINT p_uiNominalVoltageULimit, const UINT p_uiNominalVoltageRegisterRange, const UINT p_uiNominalVoltageGain, const INT p_iNominalVoltageOffset, const UINT p_uiVMeteringADCRange, const INT p_iVMeteringADCOffset, const UINT p_uiVMeteringADCVRef, const UINT p_uiVMeteringGain, const UINT p_uiVMeteringSmoothFactor, const UINT p_uiIMeteringADCRange, const INT p_iIMeteringADCOffset, const UINT p_uiIMeteringADCVRef, const UINT p_uiIMeteringGain, const UINT p_uiIMeteringRShunt, const UINT p_uiIMeteringSmoothFactor, const UINT p_uiMaxSettlingTime, const UINT p_uiDeltaOszillationLimit, EPILamp p_eActiveLamp)
  //## begin CPIPowerControlConfig::CPIPowerControlConfig%1049124050.hasinit preserve=no
      : m_dwIDActCurrent(p_dwIDActCurrent), m_dwIDActVoltage(p_dwIDActVoltage), m_dwIDNomVoltage(p_dwIDNomVoltage), m_dwIDLampSelection(p_dwIDLampSelection), m_dwIDLampOnOff(p_dwIDLampOnOff), m_uiPid_Kp(p_uiPid_Kp), m_uiPid_Ti(p_uiPid_Ti), m_uiPid_Tv(p_uiPid_Tv), m_iPid_ULimit(p_iPid_ULimit), m_iPid_LLimit(p_iPid_LLimit), m_uiPid_Ts(p_uiPid_Ts), m_uiSoftStartDeltaVoltage(p_uiSoftStartDeltaVoltage), m_uiSoftStartDeltaTime(p_uiSoftStartDeltaTime), m_uiWarmUpTime(p_uiWarmUpTime), m_uiNominalVoltage(p_uiNominalVoltage), m_uiNominalVoltageLLimit(p_uiNominalVoltageLLimit), m_uiNominalVoltageULimit(p_uiNominalVoltageULimit), m_uiNominalVoltageRegisterRange(p_uiNominalVoltageRegisterRange), m_uiNominalVoltageGain(p_uiNominalVoltageGain), m_iNominalVoltageOffset(p_iNominalVoltageOffset), m_uiVMeteringADCRange(p_uiVMeteringADCRange), m_iVMeteringADCOffset(p_iVMeteringADCOffset), m_uiVMeteringADCVRef(p_uiVMeteringADCVRef), m_uiVMeteringGain(p_uiVMeteringGain), m_uiVMeteringSmoothFactor(p_uiVMeteringSmoothFactor), m_uiIMeteringADCRange(p_uiIMeteringADCRange), m_iIMeteringADCOffset(p_iIMeteringADCOffset), m_uiIMeteringADCVRef(p_uiIMeteringADCVRef), m_uiIMeteringGain(p_uiIMeteringGain), m_uiIMeteringRShunt(p_uiIMeteringRShunt), m_uiIMeteringSmoothFactor(p_uiIMeteringSmoothFactor), m_uiMaxSettlingTime(p_uiMaxSettlingTime), m_uiDeltaOszillationLimit(p_uiDeltaOszillationLimit), m_eActiveLamp(p_eActiveLamp)
  //## end CPIPowerControlConfig::CPIPowerControlConfig%1049124050.hasinit
  //## begin CPIPowerControlConfig::CPIPowerControlConfig%1049124050.initialization preserve=yes
  //## end CPIPowerControlConfig::CPIPowerControlConfig%1049124050.initialization
{
  //## begin CPIPowerControlConfig::CPIPowerControlConfig%1049124050.body preserve=yes
  //## end CPIPowerControlConfig::CPIPowerControlConfig%1049124050.body
}


CPIPowerControlConfig::~CPIPowerControlConfig()
{
  //## begin CPIPowerControlConfig::~CPIPowerControlConfig%.body preserve=yes
  //## end CPIPowerControlConfig::~CPIPowerControlConfig%.body
}


//## Get and Set Operations for Class Attributes (implementation)

DWORD CPIPowerControlConfig::GetdwIDActCurrent ()
{
  //## begin CPIPowerControlConfig::GetdwIDActCurrent%3F0D6A8303B0.get preserve=no
  return m_dwIDActCurrent;
  //## end CPIPowerControlConfig::GetdwIDActCurrent%3F0D6A8303B0.get
}

DWORD CPIPowerControlConfig::GetdwIDActVoltage ()
{
  //## begin CPIPowerControlConfig::GetdwIDActVoltage%3F0D69D20352.get preserve=no
  return m_dwIDActVoltage;
  //## end CPIPowerControlConfig::GetdwIDActVoltage%3F0D69D20352.get
}

DWORD CPIPowerControlConfig::GetdwIDNomVoltage ()
{
  //## begin CPIPowerControlConfig::GetdwIDNomVoltage%3F0D6B0801DB.get preserve=no
  return m_dwIDNomVoltage;
  //## end CPIPowerControlConfig::GetdwIDNomVoltage%3F0D6B0801DB.get
}

DWORD CPIPowerControlConfig::GetdwIDLampSelection ()
{
  //## begin CPIPowerControlConfig::GetdwIDLampSelection%3F6A92640157.get preserve=no
  return m_dwIDLampSelection;
  //## end CPIPowerControlConfig::GetdwIDLampSelection%3F6A92640157.get
}

DWORD CPIPowerControlConfig::GetdwIDLampOnOff ()
{
  //## begin CPIPowerControlConfig::GetdwIDLampOnOff%3F6A929E02AF.get preserve=no
  return m_dwIDLampOnOff;
  //## end CPIPowerControlConfig::GetdwIDLampOnOff%3F6A929E02AF.get
}

UINT CPIPowerControlConfig::GetuiPid_Kp ()
{
  //## begin CPIPowerControlConfig::GetuiPid_Kp%3E896204000F.get preserve=no
  return m_uiPid_Kp;
  //## end CPIPowerControlConfig::GetuiPid_Kp%3E896204000F.get
}

UINT CPIPowerControlConfig::GetuiPid_Ti ()
{
  //## begin CPIPowerControlConfig::GetuiPid_Ti%3E8962060000.get preserve=no
  return m_uiPid_Ti;
  //## end CPIPowerControlConfig::GetuiPid_Ti%3E8962060000.get
}

UINT CPIPowerControlConfig::GetuiPid_Tv ()
{
  //## begin CPIPowerControlConfig::GetuiPid_Tv%3E89620C034B.get preserve=no
  return m_uiPid_Tv;
  //## end CPIPowerControlConfig::GetuiPid_Tv%3E89620C034B.get
}

INT CPIPowerControlConfig::GetiPid_ULimit ()
{
  //## begin CPIPowerControlConfig::GetiPid_ULimit%3E89620F001F.get preserve=no
  return m_iPid_ULimit;
  //## end CPIPowerControlConfig::GetiPid_ULimit%3E89620F001F.get
}

INT CPIPowerControlConfig::GetiPid_LLimit ()
{
  //## begin CPIPowerControlConfig::GetiPid_LLimit%3E896211009C.get preserve=no
  return m_iPid_LLimit;
  //## end CPIPowerControlConfig::GetiPid_LLimit%3E896211009C.get
}

UINT CPIPowerControlConfig::GetuiPid_Ts ()
{
  //## begin CPIPowerControlConfig::GetuiPid_Ts%3E896212036B.get preserve=no
  return m_uiPid_Ts;
  //## end CPIPowerControlConfig::GetuiPid_Ts%3E896212036B.get
}

UINT CPIPowerControlConfig::GetuiSoftStartDeltaVoltage ()
{
  //## begin CPIPowerControlConfig::GetuiSoftStartDeltaVoltage%3F0D6B3401EB.get preserve=no
  return m_uiSoftStartDeltaVoltage;
  //## end CPIPowerControlConfig::GetuiSoftStartDeltaVoltage%3F0D6B3401EB.get
}

UINT CPIPowerControlConfig::GetuiSoftStartDeltaTime ()
{
  //## begin CPIPowerControlConfig::GetuiSoftStartDeltaTime%3F0D6B590064.get preserve=no
  return m_uiSoftStartDeltaTime;
  //## end CPIPowerControlConfig::GetuiSoftStartDeltaTime%3F0D6B590064.get
}

UINT CPIPowerControlConfig::GetuiWarmUpTime ()
{
  //## begin CPIPowerControlConfig::GetuiWarmUpTime%4018C8DB000F.get preserve=no
  return m_uiWarmUpTime;
  //## end CPIPowerControlConfig::GetuiWarmUpTime%4018C8DB000F.get
}

UINT CPIPowerControlConfig::GetuiNominalVoltage ()
{
  //## begin CPIPowerControlConfig::GetuiNominalVoltage%3F0D6C0D013F.get preserve=no
  return m_uiNominalVoltage;
  //## end CPIPowerControlConfig::GetuiNominalVoltage%3F0D6C0D013F.get
}

UINT CPIPowerControlConfig::GetuiNominalVoltageLLimit ()
{
  //## begin CPIPowerControlConfig::GetuiNominalVoltageLLimit%40177EEE0232.get preserve=no
  return m_uiNominalVoltageLLimit;
  //## end CPIPowerControlConfig::GetuiNominalVoltageLLimit%40177EEE0232.get
}

UINT CPIPowerControlConfig::GetuiNominalVoltageULimit ()
{
  //## begin CPIPowerControlConfig::GetuiNominalVoltageULimit%40177EF4004E.get preserve=no
  return m_uiNominalVoltageULimit;
  //## end CPIPowerControlConfig::GetuiNominalVoltageULimit%40177EF4004E.get
}

UINT CPIPowerControlConfig::GetuiNominalVoltageRegisterRange ()
{
  //## begin CPIPowerControlConfig::GetuiNominalVoltageRegisterRange%40178C3701F4.get preserve=no
  return m_uiNominalVoltageRegisterRange;
  //## end CPIPowerControlConfig::GetuiNominalVoltageRegisterRange%40178C3701F4.get
}

UINT CPIPowerControlConfig::GetuiNominalVoltageGain ()
{
  //## begin CPIPowerControlConfig::GetuiNominalVoltageGain%4017800E0177.get preserve=no
  return m_uiNominalVoltageGain;
  //## end CPIPowerControlConfig::GetuiNominalVoltageGain%4017800E0177.get
}

INT CPIPowerControlConfig::GetiNominalVoltageOffset ()
{
  //## begin CPIPowerControlConfig::GetiNominalVoltageOffset%401780AD00EA.get preserve=no
  return m_iNominalVoltageOffset;
  //## end CPIPowerControlConfig::GetiNominalVoltageOffset%401780AD00EA.get
}

UINT CPIPowerControlConfig::GetuiVMeteringADCRange ()
{
  //## begin CPIPowerControlConfig::GetuiVMeteringADCRange%3F0D6BC300E1.get preserve=no
  return m_uiVMeteringADCRange;
  //## end CPIPowerControlConfig::GetuiVMeteringADCRange%3F0D6BC300E1.get
}

INT CPIPowerControlConfig::GetiVMeteringADCOffset ()
{
  //## begin CPIPowerControlConfig::GetiVMeteringADCOffset%3F0E728B0181.get preserve=no
  return m_iVMeteringADCOffset;
  //## end CPIPowerControlConfig::GetiVMeteringADCOffset%3F0E728B0181.get
}

UINT CPIPowerControlConfig::GetuiVMeteringADCVRef ()
{
  //## begin CPIPowerControlConfig::GetuiVMeteringADCVRef%40177F710232.get preserve=no
  return m_uiVMeteringADCVRef;
  //## end CPIPowerControlConfig::GetuiVMeteringADCVRef%40177F710232.get
}

UINT CPIPowerControlConfig::GetuiVMeteringGain ()
{
  //## begin CPIPowerControlConfig::GetuiVMeteringGain%3F0E865002F8.get preserve=no
  return m_uiVMeteringGain;
  //## end CPIPowerControlConfig::GetuiVMeteringGain%3F0E865002F8.get
}

UINT CPIPowerControlConfig::GetuiVMeteringSmoothFactor ()
{
  //## begin CPIPowerControlConfig::GetuiVMeteringSmoothFactor%401931F80280.get preserve=no
  return m_uiVMeteringSmoothFactor;
  //## end CPIPowerControlConfig::GetuiVMeteringSmoothFactor%401931F80280.get
}

UINT CPIPowerControlConfig::GetuiIMeteringADCRange ()
{
  //## begin CPIPowerControlConfig::GetuiIMeteringADCRange%3F12B46C0140.get preserve=no
  return m_uiIMeteringADCRange;
  //## end CPIPowerControlConfig::GetuiIMeteringADCRange%3F12B46C0140.get
}

INT CPIPowerControlConfig::GetiIMeteringADCOffset ()
{
  //## begin CPIPowerControlConfig::GetiIMeteringADCOffset%3F0E7D880048.get preserve=no
  return m_iIMeteringADCOffset;
  //## end CPIPowerControlConfig::GetiIMeteringADCOffset%3F0E7D880048.get
}

UINT CPIPowerControlConfig::GetuiIMeteringADCVRef ()
{
  //## begin CPIPowerControlConfig::GetuiIMeteringADCVRef%401782B803A9.get preserve=no
  return m_uiIMeteringADCVRef;
  //## end CPIPowerControlConfig::GetuiIMeteringADCVRef%401782B803A9.get
}

UINT CPIPowerControlConfig::GetuiIMeteringGain ()
{
  //## begin CPIPowerControlConfig::GetuiIMeteringGain%3F0E81E3000A.get preserve=no
  return m_uiIMeteringGain;
  //## end CPIPowerControlConfig::GetuiIMeteringGain%3F0E81E3000A.get
}

UINT CPIPowerControlConfig::GetuiIMeteringRShunt ()
{
  //## begin CPIPowerControlConfig::GetuiIMeteringRShunt%3F6A90B00000.get preserve=no
  return m_uiIMeteringRShunt;
  //## end CPIPowerControlConfig::GetuiIMeteringRShunt%3F6A90B00000.get
}

UINT CPIPowerControlConfig::GetuiIMeteringSmoothFactor ()
{
  //## begin CPIPowerControlConfig::GetuiIMeteringSmoothFactor%401933FA004E.get preserve=no
  return m_uiIMeteringSmoothFactor;
  //## end CPIPowerControlConfig::GetuiIMeteringSmoothFactor%401933FA004E.get
}

UINT CPIPowerControlConfig::GetuiMaxSettlingTime ()
{
  //## begin CPIPowerControlConfig::GetuiMaxSettlingTime%403F22B100FA.get preserve=no
  return m_uiMaxSettlingTime;
  //## end CPIPowerControlConfig::GetuiMaxSettlingTime%403F22B100FA.get
}

UINT CPIPowerControlConfig::GetuiDeltaOszillationLimit ()
{
  //## begin CPIPowerControlConfig::GetuiDeltaOszillationLimit%403F22B300FA.get preserve=no
  return m_uiDeltaOszillationLimit;
  //## end CPIPowerControlConfig::GetuiDeltaOszillationLimit%403F22B300FA.get
}

EPILamp CPIPowerControlConfig::GeteActiveLamp ()
{
  //## begin CPIPowerControlConfig::GeteActiveLamp%3F6A92FF03C8.get preserve=no
  return m_eActiveLamp;
  //## end CPIPowerControlConfig::GeteActiveLamp%3F6A92FF03C8.get
}

// Additional Declarations
  //## begin CPIPowerControlConfig%3DD410A003E2.declarations preserve=yes
  //## end CPIPowerControlConfig%3DD410A003E2.declarations

//## begin CPISyncObjListSWCompVersion.instantiation preserve=no
template class CCOSyncObjectParameterizedByRef< CPIPersistentSoftwareComponentVersionList* >;
//## end CPISyncObjListSWCompVersion.instantiation
// Class CPIPersistentItemList 




CPIPersistentItemList::CPIPersistentItemList (const CTypedPtrList<CPtrList, CPIPersistentItem*>& p_Items)
  //## begin CPIPersistentItemList::CPIPersistentItemList%1066980584.hasinit preserve=no
  //## end CPIPersistentItemList::CPIPersistentItemList%1066980584.hasinit
  //## begin CPIPersistentItemList::CPIPersistentItemList%1066980584.initialization preserve=yes
  //## end CPIPersistentItemList::CPIPersistentItemList%1066980584.initialization
{
  //## begin CPIPersistentItemList::CPIPersistentItemList%1066980584.body preserve=yes
    for (POSITION l_Pos=p_Items.GetHeadPosition(); l_Pos!=NULL;)
    {
        m_Items.AddTail(p_Items.GetNext(l_Pos));
    }

  //## end CPIPersistentItemList::CPIPersistentItemList%1066980584.body
}


CPIPersistentItemList::~CPIPersistentItemList()
{
  //## begin CPIPersistentItemList::~CPIPersistentItemList%.body preserve=yes
    for (POSITION l_Pos=m_Items.GetHeadPosition(); l_Pos!=NULL;)
    {
        m_Items.GetNext(l_Pos)->ReleaseRef();
    }
    m_Items.RemoveAll();

  //## end CPIPersistentItemList::~CPIPersistentItemList%.body
}


//## Get and Set Operations for Associations (implementation)

CTypedPtrList<CPtrList, CPIPersistentItem*>& CPIPersistentItemList::GetItems ()
{
  //## begin CPIPersistentItemList::GetItems%3F93E08903A0.get preserve=no
  return m_Items;
  //## end CPIPersistentItemList::GetItems%3F93E08903A0.get
}

// Additional Declarations
  //## begin CPIPersistentItemList%3DF6090302A7.declarations preserve=yes
  //## end CPIPersistentItemList%3DF6090302A7.declarations

// Class CPIPersistentSoftwareComponentVersionList 


CPIPersistentSoftwareComponentVersionList::CPIPersistentSoftwareComponentVersionList (const CTypedPtrList<CPtrList, CPIPersistentSoftwareComponentVersion*>& p_ComponentVersions)
  //## begin CPIPersistentSoftwareComponentVersionList::CPIPersistentSoftwareComponentVersionList%1039528824.hasinit preserve=no
  //## end CPIPersistentSoftwareComponentVersionList::CPIPersistentSoftwareComponentVersionList%1039528824.hasinit
  //## begin CPIPersistentSoftwareComponentVersionList::CPIPersistentSoftwareComponentVersionList%1039528824.initialization preserve=yes
  //## end CPIPersistentSoftwareComponentVersionList::CPIPersistentSoftwareComponentVersionList%1039528824.initialization
{
  //## begin CPIPersistentSoftwareComponentVersionList::CPIPersistentSoftwareComponentVersionList%1039528824.body preserve=yes
    for (POSITION l_Pos=p_ComponentVersions.GetHeadPosition(); l_Pos!=NULL;)
    {
        m_ComponentVersions.AddTail(p_ComponentVersions.GetNext(l_Pos));
    }
  //## end CPIPersistentSoftwareComponentVersionList::CPIPersistentSoftwareComponentVersionList%1039528824.body
}


CPIPersistentSoftwareComponentVersionList::~CPIPersistentSoftwareComponentVersionList()
{
  //## begin CPIPersistentSoftwareComponentVersionList::~CPIPersistentSoftwareComponentVersionList%.body preserve=yes
    for (POSITION l_Pos=m_ComponentVersions.GetHeadPosition(); l_Pos!=NULL;)
    {
        m_ComponentVersions.GetNext(l_Pos)->ReleaseRef();
    }
    m_ComponentVersions.RemoveAll();
  //## end CPIPersistentSoftwareComponentVersionList::~CPIPersistentSoftwareComponentVersionList%.body
}


//## Get and Set Operations for Associations (implementation)

CTypedPtrList<CPtrList, CPIPersistentSoftwareComponentVersion*>& CPIPersistentSoftwareComponentVersionList::GetComponentVersions ()
{
  //## begin CPIPersistentSoftwareComponentVersionList::GetComponentVersions%3DF60AE7016F.get preserve=no
  return m_ComponentVersions;
  //## end CPIPersistentSoftwareComponentVersionList::GetComponentVersions%3DF60AE7016F.get
}

// Additional Declarations
  //## begin CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.declarations preserve=yes
  //## end CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.declarations

// Class CPIPersistentSoftwareComponentList 





CPIPersistentSoftwareComponentList::CPIPersistentSoftwareComponentList (const CTypedPtrList<CPtrList, CPIPersistentSoftwareComponent*>& p_Components)
  //## begin CPIPersistentSoftwareComponentList::CPIPersistentSoftwareComponentList%1039528825.hasinit preserve=no
  //## end CPIPersistentSoftwareComponentList::CPIPersistentSoftwareComponentList%1039528825.hasinit
  //## begin CPIPersistentSoftwareComponentList::CPIPersistentSoftwareComponentList%1039528825.initialization preserve=yes
  //## end CPIPersistentSoftwareComponentList::CPIPersistentSoftwareComponentList%1039528825.initialization
{
  //## begin CPIPersistentSoftwareComponentList::CPIPersistentSoftwareComponentList%1039528825.body preserve=yes
    for (POSITION l_Pos=p_Components.GetHeadPosition(); l_Pos!=NULL;)
    {
        m_Components.AddTail(p_Components.GetNext(l_Pos));
    }
  //## end CPIPersistentSoftwareComponentList::CPIPersistentSoftwareComponentList%1039528825.body
}


CPIPersistentSoftwareComponentList::~CPIPersistentSoftwareComponentList()
{
  //## begin CPIPersistentSoftwareComponentList::~CPIPersistentSoftwareComponentList%.body preserve=yes

    for (POSITION l_Pos=m_Components.GetHeadPosition(); l_Pos!=NULL;)
    {
        m_Components.GetNext(l_Pos)->ReleaseRef();
    }
    m_Components.RemoveAll();

  //## end CPIPersistentSoftwareComponentList::~CPIPersistentSoftwareComponentList%.body
}


//## Get and Set Operations for Associations (implementation)

CTypedPtrList<CPtrList, CPIPersistentSoftwareComponent*>& CPIPersistentSoftwareComponentList::GetComponents ()
{
  //## begin CPIPersistentSoftwareComponentList::GetComponents%3DF60C2D0344.get preserve=no
  return m_Components;
  //## end CPIPersistentSoftwareComponentList::GetComponents%3DF60C2D0344.get
}

// Additional Declarations
  //## begin CPIPersistentSoftwareComponentList%3DF60C110343.declarations preserve=yes
  //## end CPIPersistentSoftwareComponentList%3DF60C110343.declarations

// Class CPIStepperMotorConfig 
















CPIStepperMotorConfig::CPIStepperMotorConfig (const DWORD p_dwAxisPlay, const DWORD p_dwHomingTimeout, const DWORD p_dwIDMovingTerminationEvent, const UINT p_uiSamplingTime, const DWORD p_dwIDStepValid, const DWORD p_dwIDVelValid, const DWORD p_dwIDStep, const DWORD p_dwIDVelocity, const DWORD p_dwIDActualPos,  const DWORD p_dwIDActualDirection, const DWORD p_dwIDDirection,  const DWORD p_dwIDRestartValid)
  //## begin CPIStepperMotorConfig::CPIStepperMotorConfig%1047636419.hasinit preserve=no
      : m_dwAxisPlay(p_dwAxisPlay), m_dwHomingTimeout(p_dwHomingTimeout), m_dwIDMovingTerminationEvent(p_dwIDMovingTerminationEvent), m_uiSamplingTime(p_uiSamplingTime), m_dwIDStepValid(p_dwIDStepValid), m_dwIDVelValid(p_dwIDVelValid), m_dwIDStep(p_dwIDStep), m_dwIDVelocity(p_dwIDVelocity), m_dwIDActualPos(p_dwIDActualPos), m_dwIDActualDirection(p_dwIDActualDirection), m_dwIDDirection(p_dwIDDirection), m_dwIDRestartValid(p_dwIDRestartValid)
  //## end CPIStepperMotorConfig::CPIStepperMotorConfig%1047636419.hasinit
  //## begin CPIStepperMotorConfig::CPIStepperMotorConfig%1047636419.initialization preserve=yes
  //## end CPIStepperMotorConfig::CPIStepperMotorConfig%1047636419.initialization
{
  //## begin CPIStepperMotorConfig::CPIStepperMotorConfig%1047636419.body preserve=yes
  //## end CPIStepperMotorConfig::CPIStepperMotorConfig%1047636419.body
}


CPIStepperMotorConfig::~CPIStepperMotorConfig()
{
  //## begin CPIStepperMotorConfig::~CPIStepperMotorConfig%.body preserve=yes
  //## end CPIStepperMotorConfig::~CPIStepperMotorConfig%.body
}


//## Get and Set Operations for Class Attributes (implementation)

DWORD CPIStepperMotorConfig::GetdwAxisPlay ()
{
  //## begin CPIStepperMotorConfig::GetdwAxisPlay%434F757B03CB.get preserve=no
  return m_dwAxisPlay;
  //## end CPIStepperMotorConfig::GetdwAxisPlay%434F757B03CB.get
}

DWORD CPIStepperMotorConfig::GetdwHomingTimeout ()
{
  //## begin CPIStepperMotorConfig::GetdwHomingTimeout%434F766B014F.get preserve=yes
	ASSERT(m_dwHomingTimeout > 0);
	return m_dwHomingTimeout;
  //## end CPIStepperMotorConfig::GetdwHomingTimeout%434F766B014F.get
}

DWORD CPIStepperMotorConfig::GetdwIDMovingTerminationEvent ()
{
  //## begin CPIStepperMotorConfig::GetdwIDMovingTerminationEvent%3E70A2E10138.get preserve=yes
  return m_dwIDMovingTerminationEvent;
  //## end CPIStepperMotorConfig::GetdwIDMovingTerminationEvent%3E70A2E10138.get
}

UINT CPIStepperMotorConfig::GetuiSamplingTime ()
{
  //## begin CPIStepperMotorConfig::GetuiSamplingTime%3E8AF8060032.get preserve=yes
  ASSERT(m_uiSamplingTime > 0);
  return m_uiSamplingTime;
  //## end CPIStepperMotorConfig::GetuiSamplingTime%3E8AF8060032.get
}

DWORD CPIStepperMotorConfig::GetdwIDStepValid ()
{
  //## begin CPIStepperMotorConfig::GetdwIDStepValid%3F4469B70291.get preserve=no
  return m_dwIDStepValid;
  //## end CPIStepperMotorConfig::GetdwIDStepValid%3F4469B70291.get
}

DWORD CPIStepperMotorConfig::GetdwIDVelValid ()
{
  //## begin CPIStepperMotorConfig::GetdwIDVelValid%3F446A2102D0.get preserve=no
  return m_dwIDVelValid;
  //## end CPIStepperMotorConfig::GetdwIDVelValid%3F446A2102D0.get
}

DWORD CPIStepperMotorConfig::GetdwIDStep ()
{
  //## begin CPIStepperMotorConfig::GetdwIDStep%3F446A3900AD.get preserve=no
  return m_dwIDStep;
  //## end CPIStepperMotorConfig::GetdwIDStep%3F446A3900AD.get
}

DWORD CPIStepperMotorConfig::GetdwIDVelocity ()
{
  //## begin CPIStepperMotorConfig::GetdwIDVelocity%3F446A8D005F.get preserve=no
  return m_dwIDVelocity;
  //## end CPIStepperMotorConfig::GetdwIDVelocity%3F446A8D005F.get
}

DWORD CPIStepperMotorConfig::GetdwIDActualPos ()
{
  //## begin CPIStepperMotorConfig::GetdwIDActualPos%3F446AB00253.get preserve=no
  return m_dwIDActualPos;
  //## end CPIStepperMotorConfig::GetdwIDActualPos%3F446AB00253.get
}

DWORD CPIStepperMotorConfig::GetdwIDActualDirection ()
{
  //## begin CPIStepperMotorConfig::GetdwIDActualDirection%3F446ACC038B.get preserve=no
  return m_dwIDActualDirection;
  //## end CPIStepperMotorConfig::GetdwIDActualDirection%3F446ACC038B.get
}

DWORD CPIStepperMotorConfig::GetdwIDDirection ()
{
  //## begin CPIStepperMotorConfig::GetdwIDDirection%3F446A55030E.get preserve=no
  return m_dwIDDirection;
  //## end CPIStepperMotorConfig::GetdwIDDirection%3F446A55030E.get
}

DWORD CPIStepperMotorConfig::GetdwIDRestartValid ()
{
  //## begin CPIStepperMotorConfig::GetdwIDRestartValid%3F56FD90032C.get preserve=no
  return m_dwIDRestartValid;
  //## end CPIStepperMotorConfig::GetdwIDRestartValid%3F56FD90032C.get
}

// Additional Declarations
  //## begin CPIStepperMotorConfig%3E70582C0280.declarations preserve=yes
  //## end CPIStepperMotorConfig%3E70582C0280.declarations

// Class CPIStepperMotorProfile 









CPIStepperMotorProfile::CPIStepperMotorProfile (const UINT p_uiSpeedHome, const UINT p_uiSpeedStartup, const UINT p_uiNomAccDec, const UINT p_uiSpeed, const UINT p_uiSpeedSearch)
  //## begin CPIStepperMotorProfile::CPIStepperMotorProfile%1047636420.hasinit preserve=no
      : m_uiSpeedHome(p_uiSpeedHome), m_uiSpeedStartup(p_uiSpeedStartup), m_uiSpeedSearch(p_uiSpeedSearch), m_uiSpeed(p_uiSpeed), m_uiNomAccDec(p_uiNomAccDec)
  //## end CPIStepperMotorProfile::CPIStepperMotorProfile%1047636420.hasinit
  //## begin CPIStepperMotorProfile::CPIStepperMotorProfile%1047636420.initialization preserve=yes
  //## end CPIStepperMotorProfile::CPIStepperMotorProfile%1047636420.initialization
{
  //## begin CPIStepperMotorProfile::CPIStepperMotorProfile%1047636420.body preserve=yes
  //## end CPIStepperMotorProfile::CPIStepperMotorProfile%1047636420.body
}


CPIStepperMotorProfile::~CPIStepperMotorProfile()
{
  //## begin CPIStepperMotorProfile::~CPIStepperMotorProfile%.body preserve=yes
  //## end CPIStepperMotorProfile::~CPIStepperMotorProfile%.body
}


//## Get and Set Operations for Class Attributes (implementation)

UINT CPIStepperMotorProfile::GetuiSpeedHome ()
{
  //## begin CPIStepperMotorProfile::GetuiSpeedHome%434F778F0177.get preserve=no
  return m_uiSpeedHome;
  //## end CPIStepperMotorProfile::GetuiSpeedHome%434F778F0177.get
}

UINT CPIStepperMotorProfile::GetuiSpeedStartup ()
{
  //## begin CPIStepperMotorProfile::GetuiSpeedStartup%3E71B3E60147.get preserve=yes
    ASSERT(m_uiSpeedStartup);
	return m_uiSpeedStartup;
  //## end CPIStepperMotorProfile::GetuiSpeedStartup%3E71B3E60147.get
}

UINT CPIStepperMotorProfile::GetuiSpeedSearch ()
{
  //## begin CPIStepperMotorProfile::GetuiSpeedSearch%3E71B4D802CE.get preserve=yes
	ASSERT(m_uiSpeedSearch > 0);
	return m_uiSpeedSearch;
  //## end CPIStepperMotorProfile::GetuiSpeedSearch%3E71B4D802CE.get
}

UINT CPIStepperMotorProfile::GetuiSpeed ()
{
  //## begin CPIStepperMotorProfile::GetuiSpeed%3E71B413028F.get preserve=yes
	ASSERT(m_uiSpeed > 0);
	return m_uiSpeed;
  //## end CPIStepperMotorProfile::GetuiSpeed%3E71B413028F.get
}

UINT CPIStepperMotorProfile::GetuiNomAccDec ()
{
  //## begin CPIStepperMotorProfile::GetuiNomAccDec%3E71B41201A5.get preserve=yes
	ASSERT(m_uiNomAccDec > 0);
	return m_uiNomAccDec;
  //## end CPIStepperMotorProfile::GetuiNomAccDec%3E71B41201A5.get
}

// Additional Declarations
  //## begin CPIStepperMotorProfile%3E71AE8803C8.declarations preserve=yes
  //## end CPIStepperMotorProfile%3E71AE8803C8.declarations

// Class CPIInterfaceConfig 









CPIInterfaceConfig::CPIInterfaceConfig (const EPIInterface p_eInterface, const DWORD p_dwAddress, const DWORD p_dwMask, const DWORD p_dwGateway, const bool p_bUseDHCP)
  //## begin CPIInterfaceConfig::CPIInterfaceConfig%1055243186.hasinit preserve=no
      : m_dwAddress(p_dwAddress), m_dwMask(p_dwMask), m_dwGateway(p_dwGateway), m_bUseDHCP(p_bUseDHCP), m_eInterface(p_eInterface)
  //## end CPIInterfaceConfig::CPIInterfaceConfig%1055243186.hasinit
  //## begin CPIInterfaceConfig::CPIInterfaceConfig%1055243186.initialization preserve=yes
  //## end CPIInterfaceConfig::CPIInterfaceConfig%1055243186.initialization
{
  //## begin CPIInterfaceConfig::CPIInterfaceConfig%1055243186.body preserve=yes
  //## end CPIInterfaceConfig::CPIInterfaceConfig%1055243186.body
}


CPIInterfaceConfig::~CPIInterfaceConfig()
{
  //## begin CPIInterfaceConfig::~CPIInterfaceConfig%.body preserve=yes
  //## end CPIInterfaceConfig::~CPIInterfaceConfig%.body
}


//## Get and Set Operations for Class Attributes (implementation)

DWORD CPIInterfaceConfig::GetdwAddress ()
{
  //## begin CPIInterfaceConfig::GetdwAddress%3EE5BA3702A2.get preserve=no
  return m_dwAddress;
  //## end CPIInterfaceConfig::GetdwAddress%3EE5BA3702A2.get
}

DWORD CPIInterfaceConfig::GetdwMask ()
{
  //## begin CPIInterfaceConfig::GetdwMask%3EE5BA480031.get preserve=no
  return m_dwMask;
  //## end CPIInterfaceConfig::GetdwMask%3EE5BA480031.get
}

DWORD CPIInterfaceConfig::GetdwGateway ()
{
  //## begin CPIInterfaceConfig::GetdwGateway%3EE5BA510198.get preserve=no
  return m_dwGateway;
  //## end CPIInterfaceConfig::GetdwGateway%3EE5BA510198.get
}

bool CPIInterfaceConfig::GetbUseDHCP ()
{
  //## begin CPIInterfaceConfig::GetbUseDHCP%4110A2B703D5.get preserve=no
  return m_bUseDHCP;
  //## end CPIInterfaceConfig::GetbUseDHCP%4110A2B703D5.get
}

// Additional Declarations
  //## begin CPIInterfaceConfig%3EE5B9DC00DD.declarations preserve=yes
  //## end CPIInterfaceConfig%3EE5B9DC00DD.declarations

// Class CPIConfigDS1631Z 





CPIConfigDS1631Z::CPIConfigDS1631Z (EPIModeDS1631Z p_eMode, EPIResolutionDS1631Z p_eResolution)
  //## begin CPIConfigDS1631Z::CPIConfigDS1631Z%1055243210.hasinit preserve=no
      : m_eResolution(p_eResolution), m_eMode(p_eMode)
  //## end CPIConfigDS1631Z::CPIConfigDS1631Z%1055243210.hasinit
  //## begin CPIConfigDS1631Z::CPIConfigDS1631Z%1055243210.initialization preserve=yes
  //## end CPIConfigDS1631Z::CPIConfigDS1631Z%1055243210.initialization
{
  //## begin CPIConfigDS1631Z::CPIConfigDS1631Z%1055243210.body preserve=yes
  //## end CPIConfigDS1631Z::CPIConfigDS1631Z%1055243210.body
}


CPIConfigDS1631Z::~CPIConfigDS1631Z()
{
  //## begin CPIConfigDS1631Z::~CPIConfigDS1631Z%.body preserve=yes
  //## end CPIConfigDS1631Z::~CPIConfigDS1631Z%.body
}


//## Get and Set Operations for Associations (implementation)

EPIResolutionDS1631Z CPIConfigDS1631Z::GeteResolution ()
{
  //## begin CPIConfigDS1631Z::GeteResolution%3EE5E003014B.get preserve=no
  return m_eResolution;
  //## end CPIConfigDS1631Z::GeteResolution%3EE5E003014B.get
}

EPIModeDS1631Z CPIConfigDS1631Z::GeteMode ()
{
  //## begin CPIConfigDS1631Z::GeteMode%3EE5E082013B.get preserve=no
  return m_eMode;
  //## end CPIConfigDS1631Z::GeteMode%3EE5E082013B.get
}

// Additional Declarations
  //## begin CPIConfigDS1631Z%3EE5DF1300EC.declarations preserve=yes
  //## end CPIConfigDS1631Z%3EE5DF1300EC.declarations

// Class CPIDataADCMAX1037 






CPIDataADCMAX1037::CPIDataADCMAX1037 (BYTE p_cAIN0, BYTE p_cAIN1, BYTE p_cAIN2, BYTE p_cAIN3)
  //## begin CPIDataADCMAX1037::CPIDataADCMAX1037%1061804143.hasinit preserve=no
      : m_cDataAIN0(p_cAIN0), m_cDataAIN1(p_cAIN1), m_cDataAIN2(p_cAIN2), m_cDataAIN3(p_cAIN3)
  //## end CPIDataADCMAX1037::CPIDataADCMAX1037%1061804143.hasinit
  //## begin CPIDataADCMAX1037::CPIDataADCMAX1037%1061804143.initialization preserve=yes
  //## end CPIDataADCMAX1037::CPIDataADCMAX1037%1061804143.initialization
{
  //## begin CPIDataADCMAX1037::CPIDataADCMAX1037%1061804143.body preserve=yes
  //## end CPIDataADCMAX1037::CPIDataADCMAX1037%1061804143.body
}


CPIDataADCMAX1037::~CPIDataADCMAX1037()
{
  //## begin CPIDataADCMAX1037::~CPIDataADCMAX1037%.body preserve=yes
  //## end CPIDataADCMAX1037::~CPIDataADCMAX1037%.body
}



//## Other Operations (implementation)
BYTE CPIDataADCMAX1037::GetDataAIN0 ()
{
  //## begin CPIDataADCMAX1037::GetDataAIN0%1061804146.body preserve=yes
  return m_cDataAIN0;
  //## end CPIDataADCMAX1037::GetDataAIN0%1061804146.body
}

BYTE CPIDataADCMAX1037::GetDataAIN1 ()
{
  //## begin CPIDataADCMAX1037::GetDataAIN1%1061804147.body preserve=yes
  return m_cDataAIN1;
  //## end CPIDataADCMAX1037::GetDataAIN1%1061804147.body
}

BYTE CPIDataADCMAX1037::GetDataAIN2 ()
{
  //## begin CPIDataADCMAX1037::GetDataAIN2%1061804148.body preserve=yes
  return m_cDataAIN2;
  //## end CPIDataADCMAX1037::GetDataAIN2%1061804148.body
}

BYTE CPIDataADCMAX1037::GetDataAIN3 ()
{
  //## begin CPIDataADCMAX1037::GetDataAIN3%1061804149.body preserve=yes
  return m_cDataAIN3;
  //## end CPIDataADCMAX1037::GetDataAIN3%1061804149.body
}

// Additional Declarations
  //## begin CPIDataADCMAX1037%3F49CE12000F.declarations preserve=yes
  //## end CPIDataADCMAX1037%3F49CE12000F.declarations

// Class CPII2CConfig 

CPII2CConfig::CPII2CConfig()
  //## begin CPII2CConfig::CPII2CConfig%.hasinit preserve=no
  //## end CPII2CConfig::CPII2CConfig%.hasinit
  //## begin CPII2CConfig::CPII2CConfig%.initialization preserve=yes
  //## end CPII2CConfig::CPII2CConfig%.initialization
{
  //## begin CPII2CConfig::CPII2CConfig%.body preserve=yes
  //## end CPII2CConfig::CPII2CConfig%.body
}

CPII2CConfig::CPII2CConfig (DWORD p_dwLogIDBusNumber, DWORD p_dwLogIDTransferSpeed, DWORD p_dwLogIDInData, DWORD p_dwLogIDOutData)
  //## begin CPII2CConfig::CPII2CConfig%1063032868.hasinit preserve=no
  //## end CPII2CConfig::CPII2CConfig%1063032868.hasinit
  //## begin CPII2CConfig::CPII2CConfig%1063032868.initialization preserve=yes
  //## end CPII2CConfig::CPII2CConfig%1063032868.initialization
{
  //## begin CPII2CConfig::CPII2CConfig%1063032868.body preserve=yes
  //## end CPII2CConfig::CPII2CConfig%1063032868.body
}


CPII2CConfig::~CPII2CConfig()
{
  //## begin CPII2CConfig::~CPII2CConfig%.body preserve=yes
  //## end CPII2CConfig::~CPII2CConfig%.body
}


// Additional Declarations
  //## begin CPII2CConfig%3F5C983E0399.declarations preserve=yes
  //## end CPII2CConfig%3F5C983E0399.declarations

//## begin CPISyncObjectStringArray.instantiation preserve=no
template class CCOSyncObjectParameterized< CStringArray* >;
//## end CPISyncObjectStringArray.instantiation
// Class CPIPersistentLifeTimeCounter 



CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter (const CString& p_sItem)
  //## begin CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter%1064853107.hasinit preserve=no
  //## end CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter%1064853107.hasinit
  //## begin CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter%1064853107.initialization preserve=yes
  //## end CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter%1064853107.initialization
{
  //## begin CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter%1064853107.body preserve=yes
	CStringList l_List;
	POSITION l_Pos = NULL;
	CPIPersistentItem::Split(p_sItem, _T("=,;."), l_List);

	// Device
	l_Pos = l_List.Find(DEVICE);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	l_List.GetNext(l_Pos);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	if (l_List.GetAt(l_Pos) == PRI_LMP)
		m_eDevice = eLampPrimary;

	else if (l_List.GetAt(l_Pos) == SEC_LMP)
		m_eDevice = eLampSecondary;

	else if (l_List.GetAt(l_Pos) == LASER)
		m_eDevice = eLaser;

	else if (l_List.GetAt(l_Pos) == INSTR_UNIT)
		m_eDevice = eInstrumentUnit;

	else if (l_List.GetAt(l_Pos) == SCANS)
		m_eDevice = eScan;

	else if (l_List.GetAt(l_Pos) == DETECTOR)
		m_eDevice = eDetector;

	else 
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	// Data
	l_Pos = l_List.Find(DATA);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	l_List.GetNext(l_Pos);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	m_uiValue = _wtoi(l_List.GetAt(l_Pos));

  //## end CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter%1064853107.body
}

CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter (const EPILifeTimeCounter p_eDevice, const UINT p_uiValue)
  //## begin CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter%1068448312.hasinit preserve=no
  //## end CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter%1068448312.hasinit
  //## begin CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter%1068448312.initialization preserve=yes
      : m_eDevice(p_eDevice), m_uiValue(p_uiValue)
  //## end CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter%1068448312.initialization
{
  //## begin CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter%1068448312.body preserve=yes
  //## end CPIPersistentLifeTimeCounter::CPIPersistentLifeTimeCounter%1068448312.body
}


CPIPersistentLifeTimeCounter::~CPIPersistentLifeTimeCounter()
{
  //## begin CPIPersistentLifeTimeCounter::~CPIPersistentLifeTimeCounter%.body preserve=yes
  //## end CPIPersistentLifeTimeCounter::~CPIPersistentLifeTimeCounter%.body
}



//## Other Operations (implementation)
CString CPIPersistentLifeTimeCounter::ToString ()
{
  //## begin CPIPersistentLifeTimeCounter::ToString%1074505553.body preserve=yes
	CString l_sDummy, l_sLifeTime;

	switch(m_eDevice)
	{
	case eLampPrimary:
		l_sDummy = PRI_LMP;
		break;

	case eLampSecondary:
		l_sDummy = SEC_LMP;
		break;

	case eLaser:
		l_sDummy = LASER;
		break;

	case eInstrumentUnit:
		l_sDummy = INSTR_UNIT;
		break;

	case eScan:
		l_sDummy = SCANS;
		break;

	case eDetector:
		l_sDummy = DETECTOR;
		break;

	default:
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	}
    
	l_sDummy.Format(DEVICE + _T("=%s,"), l_sDummy);
	l_sLifeTime += l_sDummy;

	l_sDummy.Format(DATA + _T("=%d;"), m_uiValue);
	l_sLifeTime += l_sDummy;

	return l_sLifeTime;
  //## end CPIPersistentLifeTimeCounter::ToString%1074505553.body
}

//## Get and Set Operations for Associations (implementation)

EPILifeTimeCounter CPIPersistentLifeTimeCounter::GeteDevice ()
{
  //## begin CPIPersistentLifeTimeCounter::GeteDevice%3F781D350264.get preserve=no
  return m_eDevice;
  //## end CPIPersistentLifeTimeCounter::GeteDevice%3F781D350264.get
}

UINT CPIPersistentLifeTimeCounter::GetuiValue ()
{
  //## begin CPIPersistentLifeTimeCounter::GetuiValue%3F781D5D035E.get preserve=no
  return m_uiValue;
  //## end CPIPersistentLifeTimeCounter::GetuiValue%3F781D5D035E.get
}

// Additional Declarations
  //## begin CPIPersistentLifeTimeCounter%3F781CA30021.declarations preserve=yes
  //## end CPIPersistentLifeTimeCounter%3F781CA30021.declarations

// Class CPIPersistentIdent 





CPIPersistentIdent::CPIPersistentIdent (LPCTSTR p_sIdent)
  //## begin CPIPersistentIdent::CPIPersistentIdent%1066717292.hasinit preserve=no
  //## end CPIPersistentIdent::CPIPersistentIdent%1066717292.hasinit
  //## begin CPIPersistentIdent::CPIPersistentIdent%1066717292.initialization preserve=yes
      : m_sSerialNo(_T(""))
	  , m_sArticleNo(_T(""))
  //## end CPIPersistentIdent::CPIPersistentIdent%1066717292.initialization
{
  //## begin CPIPersistentIdent::CPIPersistentIdent%1066717292.body preserve=yes
	
	// persistent identification sample string
	// Art=1563,Ver=02.12,Ser=17596;

	CStringList l_List;
	POSITION l_Pos = NULL;
	CPIPersistentItem::Split(p_sIdent, _T("=,;"), l_List);

	// Article number
	l_Pos = l_List.Find(ART_NR);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	l_List.GetNext(l_Pos);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	m_sArticleNo = l_List.GetAt(l_Pos);

	// Version
	l_Pos = l_List.Find(VERSION);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	l_List.GetNext(l_Pos);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	m_oVersion.m_sVersion = l_List.GetAt(l_Pos);
	
	// Serial number
	l_Pos = l_List.Find(SERIAL_NR);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	l_List.GetNext(l_Pos);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	m_sSerialNo = l_List.GetAt(l_Pos);
   
  //## end CPIPersistentIdent::CPIPersistentIdent%1066717292.body
}

CPIPersistentIdent::CPIPersistentIdent (LPCTSTR p_sSerialNo, LPCTSTR p_sArticleNo, CPIIdentificationVersion p_oVersion)
  //## begin CPIPersistentIdent::CPIPersistentIdent%1073378938.hasinit preserve=no
  //## end CPIPersistentIdent::CPIPersistentIdent%1073378938.hasinit
  //## begin CPIPersistentIdent::CPIPersistentIdent%1073378938.initialization preserve=yes
      : m_sSerialNo(p_sSerialNo), m_sArticleNo(p_sArticleNo), m_oVersion(p_oVersion)
  //## end CPIPersistentIdent::CPIPersistentIdent%1073378938.initialization
{
  //## begin CPIPersistentIdent::CPIPersistentIdent%1073378938.body preserve=yes
  //## end CPIPersistentIdent::CPIPersistentIdent%1073378938.body
}


CPIPersistentIdent::~CPIPersistentIdent()
{
  //## begin CPIPersistentIdent::~CPIPersistentIdent%.body preserve=yes
  //## end CPIPersistentIdent::~CPIPersistentIdent%.body
}



//## Other Operations (implementation)
CString CPIPersistentIdent::ToString ()
{
  //## begin CPIPersistentIdent::ToString%1074505555.body preserve=yes
	CString l_sDummy, l_sIdent;

	l_sDummy.Format(ART_NR + _T("=%s,"), m_sArticleNo);
	l_sIdent += l_sDummy;

	l_sDummy.Format(VERSION + _T("=%s,"), m_oVersion.m_sVersion);
	l_sIdent += l_sDummy;

	l_sDummy.Format(SERIAL_NR + _T("=%s;"), m_sSerialNo);
	l_sIdent += l_sDummy;

	return l_sIdent;
  //## end CPIPersistentIdent::ToString%1074505555.body
}

//## Get and Set Operations for Associations (implementation)

CString CPIPersistentIdent::GetsSerialNo ()
{
  //## begin CPIPersistentIdent::GetsSerialNo%3F7825D40199.get preserve=no
  return m_sSerialNo;
  //## end CPIPersistentIdent::GetsSerialNo%3F7825D40199.get
}

CString CPIPersistentIdent::GetsArticleNo ()
{
  //## begin CPIPersistentIdent::GetsArticleNo%3F7825D703CB.get preserve=no
  return m_sArticleNo;
  //## end CPIPersistentIdent::GetsArticleNo%3F7825D703CB.get
}

// Additional Declarations
  //## begin CPIPersistentIdent%3F781CB9032E.declarations preserve=yes
  //## end CPIPersistentIdent%3F781CB9032E.declarations

// Class CPIPersistentItem 












CPIPersistentItem::CPIPersistentItem()
  //## begin CPIPersistentItem::CPIPersistentItem%.hasinit preserve=no
  //## end CPIPersistentItem::CPIPersistentItem%.hasinit
  //## begin CPIPersistentItem::CPIPersistentItem%.initialization preserve=yes
  //## end CPIPersistentItem::CPIPersistentItem%.initialization
{
  //## begin CPIPersistentItem::CPIPersistentItem%.body preserve=yes
  //## end CPIPersistentItem::CPIPersistentItem%.body
}


CPIPersistentItem::~CPIPersistentItem()
{
  //## begin CPIPersistentItem::~CPIPersistentItem%.body preserve=yes
  //## end CPIPersistentItem::~CPIPersistentItem%.body
}



//## Other Operations (implementation)
void CPIPersistentItem::Split (LPCTSTR p_sSource, LPCTSTR p_sSeparator, CStringList& p_List)
{
  //## begin CPIPersistentItem::Split%1074531758.body preserve=yes
	p_List.RemoveAll();

	wchar_t *l_pSou = (wchar_t*) p_sSource;
	wchar_t *l_pSep = (wchar_t*) p_sSeparator;

	wchar_t *l_pToken = wcstok(l_pSou, l_pSep);
	while (l_pToken != NULL)
	{
		// While there are tokens in "source"
		p_List.AddTail((LPCTSTR)l_pToken);     

		// Get next token:
	    l_pToken = wcstok(NULL, l_pSep);
	}
  //## end CPIPersistentItem::Split%1074531758.body
}

// Additional Declarations
  //## begin CPIPersistentItem%3F93E453014F.declarations preserve=yes
  //## end CPIPersistentItem%3F93E453014F.declarations

//## begin CPISyncObjListPersistentItems.instantiation preserve=no
template class EBPI_DLL_DECL CCOSyncObjectParameterizedByRef< CPIPersistentItemList* >;
//## end CPISyncObjListPersistentItems.instantiation
// Class CPIPersistentPara 






CPIPersistentPara::CPIPersistentPara (const CString& p_sPara)
  //## begin CPIPersistentPara::CPIPersistentPara%1066715715.hasinit preserve=no
  //## end CPIPersistentPara::CPIPersistentPara%1066715715.hasinit
  //## begin CPIPersistentPara::CPIPersistentPara%1066715715.initialization preserve=yes
  //## end CPIPersistentPara::CPIPersistentPara%1066715715.initialization
{
  //## begin CPIPersistentPara::CPIPersistentPara%1066715715.body preserve=yes

	// Parameter sample
	// Name=Roger,Type=Int,Data=1973;
	// Name=Edi,Type=String,Data=;		 legitimate!
	
	CStringList l_List;
	POSITION l_Pos = NULL;
	CPIPersistentItem::Split(p_sPara, _T("=,;"), l_List);

	// Parameter name
	l_Pos = l_List.Find(NAME);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);
	
	l_List.GetNext(l_Pos);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	m_sParaName = l_List.GetAt(l_Pos);

    // Parameter version
    l_Pos = l_List.Find(VERSION);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

    l_List.GetNext(l_Pos);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

    m_sVersion = l_List.GetAt(l_Pos);

	// Type
	l_Pos = l_List.Find(TYPE);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	l_List.GetNext(l_Pos);

	if (l_List.GetAt(l_Pos) == TYPE_INT)
		m_eParameterType = ePIParameterTypeInt;

	else if (l_List.GetAt(l_Pos) == TYPE_DOUBLE)
		m_eParameterType = ePIParameterTypeDouble;

	else if (l_List.GetAt(l_Pos) == TYPE_STRING)
		m_eParameterType = ePIParameterTypeString;

	else
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);


	// Data
	l_Pos = l_List.Find(DATA);
	if (l_Pos == NULL)
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	l_List.GetNext(l_Pos);

	// empty strings! 
	if (l_Pos != NULL)
	{
		m_sData = l_List.GetAt(l_Pos);
	}
	else
	{
		// data is an empty string
		m_sData = _T("");
	}

  //## end CPIPersistentPara::CPIPersistentPara%1066715715.body
}


CPIPersistentPara::~CPIPersistentPara()
{
  //## begin CPIPersistentPara::~CPIPersistentPara%.body preserve=yes
  //## end CPIPersistentPara::~CPIPersistentPara%.body
}



//## Other Operations (implementation)
CString CPIPersistentPara::ToString ()
{
  //## begin CPIPersistentPara::ToString%1074505554.body preserve=yes
	CString l_sDummy, l_sType, l_sData, l_sPara;
    
	switch (m_eParameterType)
	{
	case ePIParameterTypeInt:
		l_sType = TYPE_INT;
		break;

	case ePIParameterTypeDouble:
		l_sType = TYPE_DOUBLE;
		break;

	case ePIParameterTypeString:
		l_sType = TYPE_STRING;
		break;

	default:
		throw new XPIExceptionErrorTokenizing(PI_ID, IDE_ERROR_TOKENIZING, _T(__FILE__), __LINE__);

	}

	l_sDummy.Format( NAME + _T("=%s,"), m_sParaName );
	l_sPara += l_sDummy;

    l_sDummy.Format( VERSION + _T("=%s,"), m_sVersion);
	l_sPara += l_sDummy;

	l_sDummy.Format( TYPE + _T("=%s,"), l_sType );
	l_sPara += l_sDummy;

	l_sDummy.Format( DATA + _T("=%s;"), m_sData );
	l_sPara += l_sDummy;

	return l_sPara;
  //## end CPIPersistentPara::ToString%1074505554.body
}

//## Get and Set Operations for Associations (implementation)

CString CPIPersistentPara::GetsParaName ()
{
  //## begin CPIPersistentPara::GetsParaName%3F93E2920017.get preserve=no
  return m_sParaName;
  //## end CPIPersistentPara::GetsParaName%3F93E2920017.get
}

CString CPIPersistentPara::GetsVersion ()
{
  //## begin CPIPersistentPara::GetsVersion%40602B7F030F.get preserve=no
  return m_sVersion;
  //## end CPIPersistentPara::GetsVersion%40602B7F030F.get
}

// Additional Declarations
  //## begin CPIPersistentPara%3F94CBBD0345.declarations preserve=yes
  //## end CPIPersistentPara%3F94CBBD0345.declarations

// Class CPIPersistentConfig 







CPIPersistentConfig::CPIPersistentConfig (const DWORD p_dwTimerIntervalFactor, const DWORD p_dwTimerInterval, const DWORD p_dwHeaderStartAddress)
  //## begin CPIPersistentConfig::CPIPersistentConfig%1066803566.hasinit preserve=no
      : m_dwTimerIntervalFactor(p_dwTimerIntervalFactor), m_dwTimerInterval(p_dwTimerInterval), m_dwHeaderStartAddress(p_dwHeaderStartAddress)
  //## end CPIPersistentConfig::CPIPersistentConfig%1066803566.hasinit
  //## begin CPIPersistentConfig::CPIPersistentConfig%1066803566.initialization preserve=yes
  //## end CPIPersistentConfig::CPIPersistentConfig%1066803566.initialization
{
  //## begin CPIPersistentConfig::CPIPersistentConfig%1066803566.body preserve=yes
  //## end CPIPersistentConfig::CPIPersistentConfig%1066803566.body
}


CPIPersistentConfig::~CPIPersistentConfig()
{
  //## begin CPIPersistentConfig::~CPIPersistentConfig%.body preserve=yes
  //## end CPIPersistentConfig::~CPIPersistentConfig%.body
}


//## Get and Set Operations for Class Attributes (implementation)

DWORD CPIPersistentConfig::GetdwTimerIntervalFactor ()
{
  //## begin CPIPersistentConfig::GetdwTimerIntervalFactor%3F951F13024B.get preserve=yes
	ASSERT(m_dwTimerIntervalFactor != 0);
	return m_dwTimerIntervalFactor;
  //## end CPIPersistentConfig::GetdwTimerIntervalFactor%3F951F13024B.get
}

DWORD CPIPersistentConfig::GetdwTimerInterval ()
{
  //## begin CPIPersistentConfig::GetdwTimerInterval%3FA0C20003A9.get preserve=yes
	ASSERT(m_dwTimerInterval != 0);
	return m_dwTimerInterval;
  //## end CPIPersistentConfig::GetdwTimerInterval%3FA0C20003A9.get
}

DWORD CPIPersistentConfig::GetdwHeaderStartAddress ()
{
  //## begin CPIPersistentConfig::GetdwHeaderStartAddress%4004F31A029F.get preserve=no
  return m_dwHeaderStartAddress;
  //## end CPIPersistentConfig::GetdwHeaderStartAddress%4004F31A029F.get
}

// Additional Declarations
  //## begin CPIPersistentConfig%3F9500740096.declarations preserve=yes
  //## end CPIPersistentConfig%3F9500740096.declarations

// Class CPIIdentificationVersion 





CPIIdentificationVersion::CPIIdentificationVersion()
  //## begin CPIIdentificationVersion::CPIIdentificationVersion%.hasinit preserve=no
  //## end CPIIdentificationVersion::CPIIdentificationVersion%.hasinit
  //## begin CPIIdentificationVersion::CPIIdentificationVersion%.initialization preserve=yes
  : m_uiMajor(0)
  , m_uiMinor(0)
  //## end CPIIdentificationVersion::CPIIdentificationVersion%.initialization
{
  //## begin CPIIdentificationVersion::CPIIdentificationVersion%.body preserve=yes
  //## end CPIIdentificationVersion::CPIIdentificationVersion%.body
}

CPIIdentificationVersion::CPIIdentificationVersion(const CPIIdentificationVersion &right)
  //## begin CPIIdentificationVersion::CPIIdentificationVersion%copy.hasinit preserve=no
  //## end CPIIdentificationVersion::CPIIdentificationVersion%copy.hasinit
  //## begin CPIIdentificationVersion::CPIIdentificationVersion%copy.initialization preserve=yes
  //## end CPIIdentificationVersion::CPIIdentificationVersion%copy.initialization
{
  //## begin CPIIdentificationVersion::CPIIdentificationVersion%copy.body preserve=yes
	m_uiMajor = right.m_uiMajor;
	m_uiMinor = right.m_uiMinor;
	m_sVersion = right.m_sVersion;
  //## end CPIIdentificationVersion::CPIIdentificationVersion%copy.body
}

CPIIdentificationVersion::CPIIdentificationVersion (const UINT p_uiMajor, const UINT p_uiMinor)
  //## begin CPIIdentificationVersion::CPIIdentificationVersion%1066980586.hasinit preserve=no
  //## end CPIIdentificationVersion::CPIIdentificationVersion%1066980586.hasinit
  //## begin CPIIdentificationVersion::CPIIdentificationVersion%1066980586.initialization preserve=yes
      : m_uiMajor(p_uiMajor)
	  , m_uiMinor(p_uiMinor)
  //## end CPIIdentificationVersion::CPIIdentificationVersion%1066980586.initialization
{
  //## begin CPIIdentificationVersion::CPIIdentificationVersion%1066980586.body preserve=yes
	m_sVersion.Format(_T("%d.%d"), m_uiMajor, m_uiMinor);
  //## end CPIIdentificationVersion::CPIIdentificationVersion%1066980586.body
}

CPIIdentificationVersion::CPIIdentificationVersion (LPCTSTR p_sVersion)
  //## begin CPIIdentificationVersion::CPIIdentificationVersion%1074678215.hasinit preserve=no
  //## end CPIIdentificationVersion::CPIIdentificationVersion%1074678215.hasinit
  //## begin CPIIdentificationVersion::CPIIdentificationVersion%1074678215.initialization preserve=yes
  : m_sVersion(p_sVersion)
  //## end CPIIdentificationVersion::CPIIdentificationVersion%1074678215.initialization
{
  //## begin CPIIdentificationVersion::CPIIdentificationVersion%1074678215.body preserve=yes
  //## end CPIIdentificationVersion::CPIIdentificationVersion%1074678215.body
}


CPIIdentificationVersion::~CPIIdentificationVersion()
{
  //## begin CPIIdentificationVersion::~CPIIdentificationVersion%.body preserve=yes
  //## end CPIIdentificationVersion::~CPIIdentificationVersion%.body
}


// Additional Declarations
  //## begin CPIIdentificationVersion%3F98E79701A0.declarations preserve=yes
  //## end CPIIdentificationVersion%3F98E79701A0.declarations

// Class CPII2CDataStream 







CPII2CDataStream::CPII2CDataStream (BYTE* p_pI2CDataStream, int p_nSize)
  //## begin CPII2CDataStream::CPII2CDataStream%1071126821.hasinit preserve=no
      : m_pcI2CDataStream(p_pI2CDataStream), m_nSize(p_nSize)
  //## end CPII2CDataStream::CPII2CDataStream%1071126821.hasinit
  //## begin CPII2CDataStream::CPII2CDataStream%1071126821.initialization preserve=yes
  //## end CPII2CDataStream::CPII2CDataStream%1071126821.initialization
{
  //## begin CPII2CDataStream::CPII2CDataStream%1071126821.body preserve=yes
  //## end CPII2CDataStream::CPII2CDataStream%1071126821.body
}


CPII2CDataStream::~CPII2CDataStream()
{
  //## begin CPII2CDataStream::~CPII2CDataStream%.body preserve=yes
  if (m_pcI2CDataStream)
    delete [] m_pcI2CDataStream;
  m_pcI2CDataStream = NULL;
  //## end CPII2CDataStream::~CPII2CDataStream%.body
}


//## Get and Set Operations for Class Attributes (implementation)

BYTE* CPII2CDataStream::GetpcI2CDataStream ()
{
  //## begin CPII2CDataStream::GetpcI2CDataStream%3FD83AC302DE.get preserve=no
  return m_pcI2CDataStream;
  //## end CPII2CDataStream::GetpcI2CDataStream%3FD83AC302DE.get
}

int CPII2CDataStream::GetnSize ()
{
  //## begin CPII2CDataStream::GetnSize%3FD83B42035B.get preserve=no
  return m_nSize;
  //## end CPII2CDataStream::GetnSize%3FD83B42035B.get
}

// Additional Declarations
  //## begin CPII2CDataStream%3FD8310603B9.declarations preserve=yes
  //## end CPII2CDataStream%3FD8310603B9.declarations

//## begin module%3DAE54C9009F.epilog preserve=yes
//## end module%3DAE54C9009F.epilog
