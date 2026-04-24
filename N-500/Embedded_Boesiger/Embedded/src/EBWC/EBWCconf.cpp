//## begin module%3E38FDBA0280.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E38FDBA0280.cm

//## begin module%3E38FDBA0280.cp preserve=no
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
//## end module%3E38FDBA0280.cp

//## Module: EBWCconf%3E38FDBA0280; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCconf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E38FDBA0280.additionalIncludes preserve=no
//## end module%3E38FDBA0280.additionalIncludes

//## begin module%3E38FDBA0280.includes preserve=yes
#ifndef _WIN32_WCE
  #include <math.h>
#endif
//## end module%3E38FDBA0280.includes

// EBWCimpl
#include "EBWCimpl.h"
// EBCOimct
#include "EBCOimct.h"
// EBPItype
#include "EBPItype.h"
// EBWCidnt
#include "EBWCidnt.h"
// EBWCexcp
#include "EBWCexcp.h"
// EBWCconn
#include "EBWCconn.h"
// EBWCacti
#include "EBWCacti.h"
// EBWCinit
#include "EBWCinit.h"
// EBWCconf
#include "EBWCconf.h"
// EBWCidle
#include "EBWCidle.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3E38FDBA0280.declarations preserve=no
//## end module%3E38FDBA0280.declarations

//## begin module%3E38FDBA0280.additionalDeclarations preserve=yes
//## end module%3E38FDBA0280.additionalDeclarations


// Class CWCStateConfig 

//## begin CWCStateConfig::pConfig%3E3936F90158.role preserve=no  public: static CPIWedgeControlConfig {1..1 -> 1..1RFHN}
CPIWedgeControlConfig *CWCStateConfig::m_pConfig = NULL;
//## end CWCStateConfig::pConfig%3E3936F90158.role

//## begin CWCStateConfig::bWCProfileExist%3E393F9A0168.role preserve=no  public: static BOOL {1..1 -> 1..1VFHN}
BOOL CWCStateConfig::m_bWCProfileExist = FALSE;
//## end CWCStateConfig::bWCProfileExist%3E393F9A0168.role

//## begin CWCStateConfig::HWDef%3E50F03B03AA.role preserve=no  public: static CHITDefinitions {1..1 -> 1..1VHN}
CHITDefinitions CWCStateConfig::m_HWDef;
//## end CWCStateConfig::HWDef%3E50F03B03AA.role

//## begin CWCStateConfig::dwRunAfterTime%3ECA2FE301E5.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
DWORD CWCStateConfig::m_dwRunAfterTime = 0;
//## end CWCStateConfig::dwRunAfterTime%3ECA2FE301E5.role

//## begin CWCStateConfig::pInstance%3FBB6F490149.role preserve=no  public: static CWCStateConfig {1..1 -> 1..1RFHN}
CWCStateConfig *CWCStateConfig::m_pInstance;
//## end CWCStateConfig::pInstance%3FBB6F490149.role


//## begin CWCStateConfig::pHWConfig%3FBB8B26011A.role preserve=no  public: static CHIIOCSetWCConfiguration {1..1 -> 1..1RFHN}
CHIIOCSetWCConfiguration *CWCStateConfig::m_pHWConfig = NULL;
//## end CWCStateConfig::pHWConfig%3FBB8B26011A.role

//## begin CWCStateConfig::dwCalibDACOffsetValue%3FBCB26C00BB.role preserve=no  public: static DWORD {1..1 -> 1..1VFHN}
DWORD CWCStateConfig::m_dwCalibDACOffsetValue = CHITDACMAX5712::GetcdwDefaultOffsetValue();
//## end CWCStateConfig::dwCalibDACOffsetValue%3FBCB26C00BB.role

CWCStateConfig::CWCStateConfig()
  //## begin CWCStateConfig::CWCStateConfig%.hasinit preserve=no
  //## end CWCStateConfig::CWCStateConfig%.hasinit
  //## begin CWCStateConfig::CWCStateConfig%.initialization preserve=yes
  //## end CWCStateConfig::CWCStateConfig%.initialization
{
  //## begin CWCStateConfig::CWCStateConfig%.body preserve=yes
  //## end CWCStateConfig::CWCStateConfig%.body
}


CWCStateConfig::~CWCStateConfig()
{
  //## begin CWCStateConfig::~CWCStateConfig%.body preserve=yes
  //## end CWCStateConfig::~CWCStateConfig%.body
}



//## Other Operations (implementation)
void CWCStateConfig::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfig::Shutdown%1043916999.body preserve=yes
  try
  {
    m_bWCProfileExist = FALSE;
    
    IHIInterface::GetInstance()->WCEmergencyStop();
 
    if (m_pHWConfig)
      delete m_pHWConfig;
    m_pHWConfig = NULL;

	CWCStateConfig::SetbWCProfileExist(FALSE);
    CWCStateInitialize::SetbWCInitialized(FALSE);
	CWCStateConfig::SetpConfig(NULL);
	CWCStateConfigProfile::GetInstance()->SetpProfile(NULL);

    p_pContext->ChangeState(CWCStateCreated::GetInstance());
  }
  catch(...)
  {
    throw;
  }
  //## end CWCStateConfig::Shutdown%1043916999.body
}

void CWCStateConfig::CleanupStop (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfig::CleanupStop%1053065378.body preserve=yes
  CleanupInitialize(p_pContext);
  //## end CWCStateConfig::CleanupStop%1053065378.body
}

void CWCStateConfig::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfig::CleanupInitialize%1053065379.body preserve=yes
  try
  {
    m_bWCProfileExist = FALSE;
  
    IHIInterface::GetInstance()->WCEmergencyStop();

    if (m_pHWConfig)
      delete m_pHWConfig;
    m_pHWConfig = NULL;

    p_pContext->ChangeState(CWCStateConfigNotAssign::GetInstance());
  }
  catch(...)
  {
    p_pContext->ChangeState(CWCStateConfigNotAssign::GetInstance());
  }
  //## end CWCStateConfig::CleanupInitialize%1053065379.body
}

void CWCStateConfig::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfig::ConnectionLost%1063260201.body preserve=yes
  try
  {
    IHIInterface::GetInstance()->WCEmergencyStop();
  	p_pContext->ChangeState(CWCStateNotConnectedDuringConfig::GetInstance());
  }
  catch(...)
  {
    throw;
  }
  //## end CWCStateConfig::ConnectionLost%1063260201.body
}

void CWCStateConfig::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfig::Startup%1063723576.body preserve=yes
	p_pContext->ChangeState(CWCStateConfigNotAssign::GetInstance());
  //## end CWCStateConfig::Startup%1063723576.body
}

void CWCStateConfig::SetConfiguration (ICOStateMachineContext* p_pContext, CPIWedgeControlConfig* p_pConfig)
{
  //## begin CWCStateConfig::SetConfiguration%1066973962.body preserve=yes
  SetpConfig(p_pConfig);    
  p_pContext->ChangeState(CWCStateConfiguration::GetInstance());
  //## end CWCStateConfig::SetConfiguration%1066973962.body
}

void CWCStateConfig::Stop (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfig::Stop%1076932561.body preserve=yes
  //## end CWCStateConfig::Stop%1076932561.body
}

//## Get and Set Operations for Associations (implementation)

CPIWedgeControlConfig * CWCStateConfig::GetpConfig ()
{
  //## begin CWCStateConfig::GetpConfig%3E3936F90158.get preserve=no
  return m_pConfig;
  //## end CWCStateConfig::GetpConfig%3E3936F90158.get
}

void CWCStateConfig::SetpConfig (CPIWedgeControlConfig * value)
{
  //## begin CWCStateConfig::SetpConfig%3E3936F90158.set preserve=yes
  if (m_pConfig != NULL)
    m_pConfig->ReleaseRef();

  m_pConfig = value;
  if (m_pConfig)
	m_pConfig->AddRef();
  //## end CWCStateConfig::SetpConfig%3E3936F90158.set
}

const BOOL CWCStateConfig::GetbWCProfileExist ()
{
  //## begin CWCStateConfig::GetbWCProfileExist%3E393F9A0168.get preserve=no
  return m_bWCProfileExist;
  //## end CWCStateConfig::GetbWCProfileExist%3E393F9A0168.get
}

void CWCStateConfig::SetbWCProfileExist (BOOL value)
{
  //## begin CWCStateConfig::SetbWCProfileExist%3E393F9A0168.set preserve=no
  m_bWCProfileExist = value;
  //## end CWCStateConfig::SetbWCProfileExist%3E393F9A0168.set
}

const DWORD CWCStateConfig::GetdwRunAfterTime ()
{
  //## begin CWCStateConfig::GetdwRunAfterTime%3ECA2FE301E5.get preserve=no
  return m_dwRunAfterTime;
  //## end CWCStateConfig::GetdwRunAfterTime%3ECA2FE301E5.get
}

void CWCStateConfig::SetdwRunAfterTime (DWORD value)
{
  //## begin CWCStateConfig::SetdwRunAfterTime%3ECA2FE301E5.set preserve=no
  m_dwRunAfterTime = value;
  //## end CWCStateConfig::SetdwRunAfterTime%3ECA2FE301E5.set
}

CHIIOCSetWCConfiguration * CWCStateConfig::GetpHWConfig ()
{
  //## begin CWCStateConfig::GetpHWConfig%3FBB8B26011A.get preserve=no
  return m_pHWConfig;
  //## end CWCStateConfig::GetpHWConfig%3FBB8B26011A.get
}

void CWCStateConfig::SetpHWConfig (CHIIOCSetWCConfiguration * value)
{
  //## begin CWCStateConfig::SetpHWConfig%3FBB8B26011A.set preserve=no
  m_pHWConfig = value;
  //## end CWCStateConfig::SetpHWConfig%3FBB8B26011A.set
}

DWORD CWCStateConfig::GetdwCalibDACOffsetValue ()
{
  //## begin CWCStateConfig::GetdwCalibDACOffsetValue%3FBCB26C00BB.get preserve=no
  return m_dwCalibDACOffsetValue;
  //## end CWCStateConfig::GetdwCalibDACOffsetValue%3FBCB26C00BB.get
}

void CWCStateConfig::SetdwCalibDACOffsetValue (DWORD value)
{
  //## begin CWCStateConfig::SetdwCalibDACOffsetValue%3FBCB26C00BB.set preserve=no
  m_dwCalibDACOffsetValue = value;
  //## end CWCStateConfig::SetdwCalibDACOffsetValue%3FBCB26C00BB.set
}

// Additional Declarations
  //## begin CWCStateConfig%3E38FD1000DA.declarations preserve=yes
  //## end CWCStateConfig%3E38FD1000DA.declarations

// Class CWCStateConfiguration 

//## begin CWCStateConfiguration::pInstance%3E38FF1401A6.role preserve=no  public: static CWCStateConfiguration {1..1 -> 1..1RFHN}
CWCStateConfiguration *CWCStateConfiguration::m_pInstance;
//## end CWCStateConfiguration::pInstance%3E38FF1401A6.role


CWCStateConfiguration::CWCStateConfiguration()
  //## begin CWCStateConfiguration::CWCStateConfiguration%.hasinit preserve=no
  //## end CWCStateConfiguration::CWCStateConfiguration%.hasinit
  //## begin CWCStateConfiguration::CWCStateConfiguration%.initialization preserve=yes
  //## end CWCStateConfiguration::CWCStateConfiguration%.initialization
{
  //## begin CWCStateConfiguration::CWCStateConfiguration%.body preserve=yes
  //## end CWCStateConfiguration::CWCStateConfiguration%.body
}


CWCStateConfiguration::~CWCStateConfiguration()
{
  //## begin CWCStateConfiguration::~CWCStateConfiguration%.body preserve=yes
  if (m_pConfig != NULL)
    m_pConfig->ReleaseRef();
  m_pConfig = NULL;
  //## end CWCStateConfiguration::~CWCStateConfiguration%.body
}



//## Other Operations (implementation)
void CWCStateConfiguration::Create ()
{
  //## begin CWCStateConfiguration::Create%1043917008.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CWCStateConfiguration();
  //## end CWCStateConfiguration::Create%1043917008.body
}

void CWCStateConfiguration::Delete ()
{
  //## begin CWCStateConfiguration::Delete%1043917009.body preserve=yes
  if(m_pInstance)
    delete m_pInstance;
  m_pInstance = NULL;
  //## end CWCStateConfiguration::Delete%1043917009.body
}

CWCStateConfiguration* CWCStateConfiguration::GetInstance ()
{
  //## begin CWCStateConfiguration::GetInstance%1043917010.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CWCStateConfiguration::GetInstance%1043917010.body
}

void CWCStateConfiguration::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfiguration::Do%1043917043.body preserve=yes
  double l_dAccTime(0);
  double l_dDecTime(0);
  double l_dAccReferToFrequency(0);
  double l_dDecReferToFrequency(0);
  double l_dNomVelocity(0);

  DWORD l_dwAccTicks(0);
  DWORD l_dwDecTicks(0);
  DWORD l_dwAccVelocityInc(0);
  DWORD l_dwAccVelocityIni(0);
  DWORD l_dwDecVelocityInc(0);
  DWORD l_dwDecVelocityRest(0);
  DWORD l_dwAccDistance(0);
  DWORD l_dwDecDistance(0);

  // ISR sample Time in [ns]
  DWORD l_dwIsrSampleTime = m_HWDef.GetdwIsrSampleTime();
  ASSERT(l_dwIsrSampleTime != 0);
  
  DWORD l_dwWC_Ydac = 0;
  DWORD l_dwWC_Kdac = 0;
  DWORD l_dwWC_Kp = 0;
  DWORD l_dwTi = 0;
  DWORD l_dwWC_Ki = 0;
  DWORD l_dwWC_Kd = 0;
  DWORD l_dwDACLimitUpper = 0;
  DWORD l_dwDACLimitLower = 0;

  const DWORD l_dwDACConvFactor = 100000;
  try
  {
    if ((m_pConfig->GetdwWC_Gain_DAC() == 0) || (m_pConfig->GetdwWC_Kdac() == 0))
    {
   	  throw new XWCExceptionError(WC_ID, IDE_WC_WRONG_CONFIG_PARAM, _T(__FILE__), __LINE__, 0);
    }

    ///////////////////////////////
    // controller parameter
    // DAC - offset factor
    l_dwWC_Ydac = m_pConfig->GetdwWC_Offset_DAC();
    // DAC - conversion factor ([A]->[f']) and DAC gain factor [nA]
    // convert DAC gain [nA]->[A]
    l_dwWC_Kdac =  (DWORD)(l_dwDACConvFactor / (((double)(m_pConfig->GetdwWC_Gain_DAC() * 1e-9)) * m_pConfig->GetdwWC_Kdac()));
    // P - factor
    l_dwWC_Kp = l_dwWC_Kdac * m_pConfig->GetdwWC_P();
  
    if (m_pConfig->GetdwWC_TN() != 0)
    { // I - factor Tn [us] -> [ns]
      l_dwTi = (m_pConfig->GetdwWC_TN()* (DWORD)1e3);
      l_dwWC_Ki = (l_dwWC_Kp * l_dwIsrSampleTime) / (2 * l_dwTi);
    }
  
    if (m_pConfig->GetdwWC_TV() != 0)
    { // D - factor Tv [us] -> [ns]
      l_dwWC_Kd = (l_dwWC_Kp * m_pConfig->GetdwWC_TV()* (DWORD)1e3) / l_dwIsrSampleTime;
    }
  
    l_dwDACLimitUpper = m_pConfig->GetdwDACLimitUp();
    if (l_dwDACLimitUpper > CHITDACMAX5712::GetcdwUpperLimit())
    {
      l_dwDACLimitUpper = CHITDACMAX5712::GetcdwUpperLimit();
    }

    l_dwDACLimitLower = m_pConfig->GetdwDACLimitDown();
    if (l_dwDACLimitLower < CHITDACMAX5712::GetcdwLowerLimit())
    {
      l_dwDACLimitLower = CHITDACMAX5712::GetcdwUpperLimit();
    }

    ////////////////////////////////////////////////////////////////////////
    // acceleration from [m/s^2] -> [1/s^2] 
    ASSERT(CHITDefinitions::GetcdLaserZeroCrossDistance() != 0);
    l_dAccReferToFrequency = (double)m_pConfig->GetdwNomAcc() / CHITDefinitions::GetcdLaserZeroCrossDistance(); // Unit [m];
    l_dDecReferToFrequency = (double)m_pConfig->GetdwNomDec() / CHITDefinitions::GetcdLaserZeroCrossDistance(); // Unit [m];
    
    if ((l_dAccReferToFrequency == 0) || (l_dDecReferToFrequency == 0) || (m_pConfig->GetdwNomAcc() == 0) || (m_pConfig->GetdwNomDec() == 0))
    {
   	  throw new XWCExceptionError(WC_ID, IDE_WC_WRONG_PROFILE_PARAM, _T(__FILE__), __LINE__, 0);
    }

    l_dAccTime  = (double)m_pConfig->GetdwNomVelocity() / l_dAccReferToFrequency;
    // Isr sample Time [ns] -> [s]
    l_dwAccTicks = (DWORD)(floor(l_dAccTime  / ((double)(m_HWDef.GetdwIsrSampleTime() * 1e-9))));

    // acceleration distance (numer of laser zero crosses)
    l_dNomVelocity = (double)m_pConfig->GetdwNomVelocity();
    l_dwAccDistance = (DWORD)ceil(((pow(l_dNomVelocity,2) * CHITDefinitions::GetcdLaserZeroCrossDistance())/((double)m_pConfig->GetdwNomAcc())));

    if (l_dwAccDistance == 0)
    {
   	  l_dwAccDistance = 1;
    }
    
    l_dwAccVelocityInc = (DWORD)floor(l_dNomVelocity / (double)l_dwAccDistance);
    l_dwAccVelocityIni = (DWORD)fmod(l_dNomVelocity, (double)l_dwAccDistance);
  
    ////////////////////////////////////////////////////////////////////////
    // deceleration
    l_dDecTime = (double)m_pConfig->GetdwNomVelocity() / l_dDecReferToFrequency;
    // Isr sample Time [ns] -> [s]
    l_dwDecTicks = (DWORD)(floor(l_dDecTime / ((double)(m_HWDef.GetdwIsrSampleTime() * 1e-9))));  
  
    // deceleration distance (numer of laser zero crosses)
    l_dwDecDistance = (DWORD)ceil(((pow(l_dNomVelocity,2) * CHITDefinitions::GetcdLaserZeroCrossDistance())/((double)m_pConfig->GetdwNomDec())));

    if (l_dwDecDistance == 0)
    {
   	  l_dwDecDistance = 1;
    }

    l_dwDecVelocityInc  = (DWORD)floor(l_dNomVelocity / (double)l_dwDecDistance);
    l_dwDecVelocityRest = (DWORD)fmod(l_dNomVelocity, (double)l_dwDecDistance);

    // ISR Time Ticks (ISR Sample Time [ns] -> [ms])
    DWORD l_dwMaxCurrentISRTicks = (DWORD)floor((double)m_pConfig->GetdwMaxCurrentTime() / ((double)(m_HWDef.GetdwIsrSampleTime() * 1e-6))); 

    if (GetpContext(p_pContext)->GetbHWPresent())
    {
      m_pHWConfig = new CHIIOCSetWCConfiguration(m_pConfig->GetdwNomVelocity(),
                                                 l_dwAccVelocityInc,
                                                 l_dwAccVelocityIni,
                                                 l_dwAccDistance,
                                                 l_dwDecVelocityInc,
                                                 l_dwDecVelocityRest,
                                                 l_dwDecDistance,
                                                 m_pConfig->GetdwWedgeControllerVelocityEdge(),
                                                 m_pConfig->GetdwStaticFrictionForward(),
                                                 m_pConfig->GetdwStaticFrictionBackward(),
                                                 m_pConfig->GetdwVelocityWarnHighRange(),
                                                 m_pConfig->GetdwVelocityWarnLowRange(),
                                                 m_pConfig->GetdwVelocityErrorHighRange(),
                                                 m_pConfig->GetdwVelocityErrorLowRange(),
                                                 m_pConfig->GetdwForwardStartDistance(),
                                                 m_pConfig->GetdwForwardEndDistance(),
                                                 m_pConfig->GetdwMeasuringDistance(),
                                                 m_pConfig->GetdwBackwardStartDistance(),
                                                 m_pConfig->GetdwRefDistance1(),
                                                 l_dwWC_Kp,
                                                 l_dwWC_Ki,
                                                 l_dwWC_Kd,
                                                 l_dwDACConvFactor,
                                                 l_dwWC_Ydac,
                                                 l_dwDACLimitUpper,
                                                 l_dwDACLimitLower,
                                                 m_pConfig->GetdwDACLimitSlewRate(),
                                                 m_pConfig->GetdwRunAfterTime(),
                                                 m_pConfig->GetdwAccStandBy(),
                                                 l_dwMaxCurrentISRTicks);

#ifdef _WIN32_WCE
      IHIInterface::GetInstance()->WCSetConfiguration(m_pHWConfig);
#else
      // write config parameter to file
      DebugWriteWCConfigToFile(_T("WCHWConfig.txt"), m_pHWConfig);
#endif
    }
    m_dwRunAfterTime = m_pConfig->GetdwRunAfterTime();

    p_pContext->ChangeState(CWCStateConfigInitDAC::GetInstance());
  }
	catch(...)
	{
		throw;
	}
  //## end CWCStateConfiguration::Do%1043917043.body
}

void CWCStateConfiguration::DebugWriteWCConfigToFile (CString p_strFileName, CHIIOCSetWCConfiguration* p_pConfig)
{
  //## begin CWCStateConfiguration::DebugWriteWCConfigToFile%1065698584.body preserve=yes
  int l_nIndex = 0;
  CFile l_f1;
  CString l_strVal = _T("");
  CString l_strParameter = _T("");
  if( !l_f1.Open( p_strFileName, CFile::modeCreate | CFile::modeWrite)) {
    CO_TRACE(WC_ID, _T("Could not create WC config file"));
  }
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwNomVelocity(), l_nIndex, _T("p_dwNomVelocity"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwNomAcc(), l_nIndex, _T("p_dwNomAcc"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwIniAcc(), l_nIndex, _T("p_dwIniAcc"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwAccDistance(), l_nIndex, _T("p_dwAccDistance"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwNomDec(), l_nIndex, _T("p_dwNomDec"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwRestDec(), l_nIndex, _T("p_dwRestDec"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwDecDistance(), l_nIndex, _T("p_dwDecDistance"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwWedgeControllerVelocityEdge(), l_nIndex, _T("p_dwWedgeControllerVelocityEdge"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwVelocityWarnHighRange(), l_nIndex, _T("p_dwVelocityWarnHighRange"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwVelocityWarnLowRange(), l_nIndex, _T("p_dwVelocityWarnLowRange"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwVelocityErrorHighRange(), l_nIndex, _T("p_dwVelocityErrorHighRange"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwVelocityErrorLowRange(), l_nIndex, _T("p_dwVelocityErrorLowRange"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwForwardStartDistance(), l_nIndex, _T("p_dwForwardStartDistance"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwForwardEndDistance(), l_nIndex, _T("p_dwForwardEndDistance"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwMeasuringDistance(), l_nIndex, _T("p_dwMeasuringDistance"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwBackwardStartDistance(), l_nIndex, _T("p_dwBackwardStartDistance"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwRefDistance1(), l_nIndex, _T("p_dwRefDistance1"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwWC_Kp(), l_nIndex, _T("p_dwWC_Kp"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwWC_Ki(), l_nIndex, _T("p_dwWC_Ki"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwWC_Kd(), l_nIndex, _T("p_dwWC_Kd"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwWC_DACConvFactor(), l_nIndex, _T("p_dwWC_DACConvFactor"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwWC_Ydac(), l_nIndex, _T("p_dwWC_Ydac"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwDACLimitUp(), l_nIndex, _T("p_dwDACLimitUp"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwDACLimitDown(), l_nIndex, _T("p_dwDACLimitDown"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwDACLimitSlr(), l_nIndex, _T("p_dwDACLimitSlr"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwRunAfterTimeTicks(), l_nIndex, _T("p_dwRunAfterTimeTicks"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pConfig->GetdwAccStandBy(), l_nIndex, _T("p_dwAccStandBy"));
  l_strParameter+=l_strVal;

  int l_nLength = l_strParameter.GetLength() * 2; // UNICODE
  l_f1.Write(l_strParameter, l_nLength);
  l_f1.Close();  
  //## end CWCStateConfiguration::DebugWriteWCConfigToFile%1065698584.body
}

// Additional Declarations
  //## begin CWCStateConfiguration%3E39192D001F.declarations preserve=yes
  //## end CWCStateConfiguration%3E39192D001F.declarations

// Class CWCStateConfigProfile 

//## begin CWCStateConfigProfile::pInstance%3E392166030E.role preserve=no  public: static CWCStateConfigProfile {1..1 -> 1..1RFHN}
CWCStateConfigProfile *CWCStateConfigProfile::m_pInstance;
//## end CWCStateConfigProfile::pInstance%3E392166030E.role



CWCStateConfigProfile::CWCStateConfigProfile()
  //## begin CWCStateConfigProfile::CWCStateConfigProfile%.hasinit preserve=no
      : m_pProfile(NULL)
  //## end CWCStateConfigProfile::CWCStateConfigProfile%.hasinit
  //## begin CWCStateConfigProfile::CWCStateConfigProfile%.initialization preserve=yes
  //## end CWCStateConfigProfile::CWCStateConfigProfile%.initialization
{
  //## begin CWCStateConfigProfile::CWCStateConfigProfile%.body preserve=yes
  //## end CWCStateConfigProfile::CWCStateConfigProfile%.body
}


CWCStateConfigProfile::~CWCStateConfigProfile()
{
  //## begin CWCStateConfigProfile::~CWCStateConfigProfile%.body preserve=yes
  if (m_pProfile != NULL)
    m_pProfile->ReleaseRef();
  m_pProfile = NULL;
  //## end CWCStateConfigProfile::~CWCStateConfigProfile%.body
}



//## Other Operations (implementation)
void CWCStateConfigProfile::Create ()
{
  //## begin CWCStateConfigProfile::Create%1043917011.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CWCStateConfigProfile();
  //## end CWCStateConfigProfile::Create%1043917011.body
}

void CWCStateConfigProfile::Delete ()
{
  //## begin CWCStateConfigProfile::Delete%1043917012.body preserve=yes
    if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CWCStateConfigProfile::Delete%1043917012.body
}

CWCStateConfigProfile* CWCStateConfigProfile::GetInstance ()
{
  //## begin CWCStateConfigProfile::GetInstance%1043917013.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CWCStateConfigProfile::GetInstance%1043917013.body
}

void CWCStateConfigProfile::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfigProfile::Enter%1046351114.body preserve=yes
  try
  {
    p_pContext->GetpStateMachineEngine()->Cleanup(); // clean all actions
  }
	catch(...)
	{
		throw;
	}
  //## end CWCStateConfigProfile::Enter%1046351114.body
}

void CWCStateConfigProfile::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfigProfile::Do%1043917047.body preserve=yes

    try
    {

        if (GetpContext(p_pContext)->GetbHWPresent())
        {
            CHIIOCSetWCProfile l_WCProfile(m_pProfile->GetdwScanMode(),
                                             m_pProfile->GetdwRefDistance2());

#ifdef _WIN32_WCE
            IHIInterface::GetInstance()->WCSetProfile(&l_WCProfile);
#else
            DebugWriteWCProfileToFile(_T("WCHWProfile.txt"), &l_WCProfile);
#endif 
        }

        m_bWCProfileExist = TRUE;

        p_pContext->ChangeState(CWCStateInitializeStopped::GetInstance());
    }
    catch(...)
    {
        throw;
    }

  //## end CWCStateConfigProfile::Do%1043917047.body
}

void CWCStateConfigProfile::SetProfile (ICOStateMachineContext* p_pContext, CPIWedgeControlProfile* p_pProfile)
{
  //## begin CWCStateConfigProfile::SetProfile%1052978388.body preserve=yes
  this->SetpProfile(p_pProfile);  
  p_pContext->ChangeState(this);  // => calls CWCStateConfigProfile::Do(..)
  //## end CWCStateConfigProfile::SetProfile%1052978388.body
}

void CWCStateConfigProfile::Initialize (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfigProfile::Initialize%1043917048.body preserve=yes
  CWCActionInitialize* l_pAction = (CWCActionInitialize*)p_pContext->GetAction(IDA_INITIALIZE);
  l_pAction->SetdwInitializedEvent(m_pConfig->GetdwWCIdInitializedEvent());
  p_pContext->ChangeState(CWCStateInitializing::GetInstance(), l_pAction);
  //## end CWCStateConfigProfile::Initialize%1043917048.body
}

void CWCStateConfigProfile::DebugWriteWCProfileToFile (CString p_strFileName, CHIIOCSetWCProfile* p_pProfile)
{
  //## begin CWCStateConfigProfile::DebugWriteWCProfileToFile%1065698585.body preserve=yes
  int l_nIndex = 0;
  CFile l_f1;
  CString l_strVal = _T("");
  CString l_strParameter = _T("");
  if( !l_f1.Open( p_strFileName, CFile::modeCreate | CFile::modeWrite)) {
    CO_TRACE(WC_ID, _T("Could not create WC profile file"));
  }
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pProfile->GetdwScanMode(), l_nIndex, _T("p_dwScanMode"));
  l_strParameter+=l_strVal;
  l_nIndex++;
  l_strVal.Format(_T("%d, //%02d %s \r\n"),p_pProfile->GetdwRefDistance2(), l_nIndex, _T("p_dwRefDistance2"));
  l_strParameter+=l_strVal;

  int l_nLength = l_strParameter.GetLength() * 2; // UNICODE
  l_f1.Write(l_strParameter, l_nLength);
  l_f1.Close();  
  //## end CWCStateConfigProfile::DebugWriteWCProfileToFile%1065698585.body
}

//## Get and Set Operations for Associations (implementation)

void CWCStateConfigProfile::SetpProfile (CPIWedgeControlProfile * value)
{
  //## begin CWCStateConfigProfile::SetpProfile%3E393D1E0020.set preserve=yes
  if (m_pProfile != NULL)
    m_pProfile->ReleaseRef();

  m_pProfile = value;
  if (m_pProfile)
	m_pProfile->AddRef();
  //## end CWCStateConfigProfile::SetpProfile%3E393D1E0020.set
}

// Additional Declarations
  //## begin CWCStateConfigProfile%3E39197700AB.declarations preserve=yes
  //## end CWCStateConfigProfile%3E39197700AB.declarations

// Class CWCStateConfigNotAssign 

//## begin CWCStateConfigNotAssign::pInstance%3E3927F300FB.role preserve=no  public: static CWCStateConfigNotAssign {1..1 -> 1..1RFHN}
CWCStateConfigNotAssign *CWCStateConfigNotAssign::m_pInstance;
//## end CWCStateConfigNotAssign::pInstance%3E3927F300FB.role


CWCStateConfigNotAssign::CWCStateConfigNotAssign()
  //## begin CWCStateConfigNotAssign::CWCStateConfigNotAssign%.hasinit preserve=no
  //## end CWCStateConfigNotAssign::CWCStateConfigNotAssign%.hasinit
  //## begin CWCStateConfigNotAssign::CWCStateConfigNotAssign%.initialization preserve=yes
  //## end CWCStateConfigNotAssign::CWCStateConfigNotAssign%.initialization
{
  //## begin CWCStateConfigNotAssign::CWCStateConfigNotAssign%.body preserve=yes
  //## end CWCStateConfigNotAssign::CWCStateConfigNotAssign%.body
}


CWCStateConfigNotAssign::~CWCStateConfigNotAssign()
{
  //## begin CWCStateConfigNotAssign::~CWCStateConfigNotAssign%.body preserve=yes
  //## end CWCStateConfigNotAssign::~CWCStateConfigNotAssign%.body
}



//## Other Operations (implementation)
void CWCStateConfigNotAssign::Create ()
{
  //## begin CWCStateConfigNotAssign::Create%1043917038.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CWCStateConfigNotAssign();
  //## end CWCStateConfigNotAssign::Create%1043917038.body
}

void CWCStateConfigNotAssign::Delete ()
{
  //## begin CWCStateConfigNotAssign::Delete%1043917039.body preserve=yes
    if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CWCStateConfigNotAssign::Delete%1043917039.body
}

CWCStateConfigNotAssign* CWCStateConfigNotAssign::GetInstance ()
{
  //## begin CWCStateConfigNotAssign::GetInstance%1043917040.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CWCStateConfigNotAssign::GetInstance%1043917040.body
}

void CWCStateConfigNotAssign::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfigNotAssign::Do%1088517553.body preserve=yes
  try
  {
    IHIInterface::GetInstance()->WCReset();
  }
  catch(...)
  {
   
    // no throw cmd -> endless loop!
  }
  //## end CWCStateConfigNotAssign::Do%1088517553.body
}

// Additional Declarations
  //## begin CWCStateConfigNotAssign%3E3927950138.declarations preserve=yes
  //## end CWCStateConfigNotAssign%3E3927950138.declarations

// Class CWCStateConfigInitDAC 

//## begin CWCStateConfigInitDAC::pInstance%3FBB6EA100FB.role preserve=no  public: static CWCStateConfigInitDAC {1..1 -> RFHN}
CWCStateConfigInitDAC *CWCStateConfigInitDAC::m_pInstance;
//## end CWCStateConfigInitDAC::pInstance%3FBB6EA100FB.role


CWCStateConfigInitDAC::CWCStateConfigInitDAC()
  //## begin CWCStateConfigInitDAC::CWCStateConfigInitDAC%.hasinit preserve=no
  //## end CWCStateConfigInitDAC::CWCStateConfigInitDAC%.hasinit
  //## begin CWCStateConfigInitDAC::CWCStateConfigInitDAC%.initialization preserve=yes
  //## end CWCStateConfigInitDAC::CWCStateConfigInitDAC%.initialization
{
  //## begin CWCStateConfigInitDAC::CWCStateConfigInitDAC%.body preserve=yes
  //## end CWCStateConfigInitDAC::CWCStateConfigInitDAC%.body
}


CWCStateConfigInitDAC::~CWCStateConfigInitDAC()
{
  //## begin CWCStateConfigInitDAC::~CWCStateConfigInitDAC%.body preserve=yes
  //## end CWCStateConfigInitDAC::~CWCStateConfigInitDAC%.body
}



//## Other Operations (implementation)
void CWCStateConfigInitDAC::Create ()
{
  //## begin CWCStateConfigInitDAC::Create%1069248595.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CWCStateConfigInitDAC();
  //## end CWCStateConfigInitDAC::Create%1069248595.body
}

void CWCStateConfigInitDAC::Delete ()
{
  //## begin CWCStateConfigInitDAC::Delete%1069248596.body preserve=yes
  if(m_pInstance)
    delete m_pInstance;
  m_pInstance = NULL;
  //## end CWCStateConfigInitDAC::Delete%1069248596.body
}

CWCStateConfigInitDAC* CWCStateConfigInitDAC::GetInstance ()
{
  //## begin CWCStateConfigInitDAC::GetInstance%1069248597.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CWCStateConfigInitDAC::GetInstance%1069248597.body
}

void CWCStateConfigInitDAC::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfigInitDAC::Enter%1074582787.body preserve=yes
  p_pContext->GetpStateMachineEngine()->Cleanup(); // clean all actions
  //## end CWCStateConfigInitDAC::Enter%1074582787.body
}

void CWCStateConfigInitDAC::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfigInitDAC::Do%1069248599.body preserve=yes
  try
  {
    CCOSyncObjectPtr l_pSyncObj = NULL;
    DWORD l_dwInputState = 0;

    // unmask event
    IHIInterface::GetInstance()->UnMaskHWEvent(m_pConfig->GetdwWCIdCurDirEvent(), eHIHardwareEvent);
    Sleep(10); // wait until event are up to date!

    // turn off wc PID controller
    l_pSyncObj = IHIInterface::GetInstance()->WCControllerON(FALSE);
    l_pSyncObj->Synchronize();

    l_pSyncObj = IHIInterface::GetInstance()->WCInitializeDAC();
    l_pSyncObj->Synchronize();

  
    l_dwInputState = IHIInterface::GetInstance()->GetDWord(m_pConfig->GetdwWCIdCurDirInput());
    
    CWCActionCurrDir* l_pAction = (CWCActionCurrDir*)p_pContext->GetAction(IDA_DAC_CURR_DIR);
    
    CWCStateConfig::SetdwCalibDACOffsetValue(CHITDACMAX5712::GetcdwDefaultOffsetValue());
    
    l_pAction->SetdwCurrDirEvent(m_pConfig->GetdwWCIdCurDirInput());
  
    CO_TRACE1(WC_ID,_T("WC DAC Current Direction State: %d"),l_dwInputState);

    if (l_dwInputState != 0)
    {
      // act current positive
      l_pAction->SeteEventRegistration(eHILow);
      p_pContext->ChangeState(CWCStateConfigCalibDACDecCurr::GetInstance(),l_pAction);
    }
    else
    { // act current negative
      l_pAction->SeteEventRegistration(eHIHigh);
      p_pContext->ChangeState(CWCStateConfigCalibDACIncCurr::GetInstance(),l_pAction);
    }
  }
  catch(...)
  {
    throw;
  }
  //## end CWCStateConfigInitDAC::Do%1069248599.body
}

// Additional Declarations
  //## begin CWCStateConfigInitDAC%3FBB6DE602BF.declarations preserve=yes
  //## end CWCStateConfigInitDAC%3FBB6DE602BF.declarations

// Class CWCStateConfigDACCalibrated 

//## begin CWCStateConfigDACCalibrated::pInstance%3FBB6FE900CC.role preserve=no  public: static CWCStateConfigDACCalibrated {1..1 -> 1..1RFHN}
CWCStateConfigDACCalibrated *CWCStateConfigDACCalibrated::m_pInstance;
//## end CWCStateConfigDACCalibrated::pInstance%3FBB6FE900CC.role


CWCStateConfigDACCalibrated::CWCStateConfigDACCalibrated()
  //## begin CWCStateConfigDACCalibrated::CWCStateConfigDACCalibrated%.hasinit preserve=no
  //## end CWCStateConfigDACCalibrated::CWCStateConfigDACCalibrated%.hasinit
  //## begin CWCStateConfigDACCalibrated::CWCStateConfigDACCalibrated%.initialization preserve=yes
  //## end CWCStateConfigDACCalibrated::CWCStateConfigDACCalibrated%.initialization
{
  //## begin CWCStateConfigDACCalibrated::CWCStateConfigDACCalibrated%.body preserve=yes
  //## end CWCStateConfigDACCalibrated::CWCStateConfigDACCalibrated%.body
}


CWCStateConfigDACCalibrated::~CWCStateConfigDACCalibrated()
{
  //## begin CWCStateConfigDACCalibrated::~CWCStateConfigDACCalibrated%.body preserve=yes
  //## end CWCStateConfigDACCalibrated::~CWCStateConfigDACCalibrated%.body
}



//## Other Operations (implementation)
void CWCStateConfigDACCalibrated::Create ()
{
  //## begin CWCStateConfigDACCalibrated::Create%1069248605.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CWCStateConfigDACCalibrated();
  //## end CWCStateConfigDACCalibrated::Create%1069248605.body
}

void CWCStateConfigDACCalibrated::Delete ()
{
  //## begin CWCStateConfigDACCalibrated::Delete%1069248606.body preserve=yes
  if(m_pInstance)
    delete m_pInstance;
  m_pInstance = NULL;
  //## end CWCStateConfigDACCalibrated::Delete%1069248606.body
}

CWCStateConfigDACCalibrated* CWCStateConfigDACCalibrated::GetInstance ()
{
  //## begin CWCStateConfigDACCalibrated::GetInstance%1069248607.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CWCStateConfigDACCalibrated::GetInstance%1069248607.body
}

void CWCStateConfigDACCalibrated::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfigDACCalibrated::Enter%1069318248.body preserve=yes
  p_pContext->GetpStateMachineEngine()->Cleanup(); // clean all actions
  //## end CWCStateConfigDACCalibrated::Enter%1069318248.body
}

void CWCStateConfigDACCalibrated::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfigDACCalibrated::Do%1069248609.body preserve=yes
  CCOSyncObjectPtr l_pSyncObj = NULL;
  try
  {
    if (GetpContext(p_pContext)->GetbHWPresent())
    {
      m_pHWConfig->SetdwWC_Ydac(m_dwCalibDACOffsetValue);
      CO_TRACE1(WC_ID,_T("WC DAC calibration value = %d"),m_dwCalibDACOffsetValue);
#ifdef _WIN32_WCE
      // mask "WedgeControl Current Direction" Input Event
      IHIInterface::GetInstance()->MaskHWEvent(m_pConfig->GetdwWCIdCurDirEvent(), eHIHardwareEvent);

      // mask "WedgeControl Light Barrier" Input Event
      IHIInterface::GetInstance()->MaskHWEvent(m_pConfig->GetdwWCLightBarrierEvent(), eHIHardwareEvent);

      IHIInterface::GetInstance()->WCSetConfiguration(m_pHWConfig);
      
      l_pSyncObj = IHIInterface::GetInstance()->WCControllerON(TRUE);
      l_pSyncObj->Synchronize();
#else
      // write config parameter to file
      CWCStateConfiguration::GetInstance()->DebugWriteWCConfigToFile(_T("WCHWConfig.txt"), m_pHWConfig);
#endif
    }


  if (CWCStateConfig::GetbWCProfileExist())
    p_pContext->ChangeState(CWCStateConfigProfile::GetInstance());
  }
  catch(...)
  {
    throw;
  }
  //## end CWCStateConfigDACCalibrated::Do%1069248609.body
}

void CWCStateConfigDACCalibrated::SetProfile (ICOStateMachineContext* p_pContext, CPIWedgeControlProfile* p_pProfile)
{
  //## begin CWCStateConfigDACCalibrated::SetProfile%1069248610.body preserve=yes
  CWCStateConfigProfile::GetInstance()->SetpProfile(p_pProfile);
  p_pContext->ChangeState(CWCStateConfigProfile::GetInstance());
  //## end CWCStateConfigDACCalibrated::SetProfile%1069248610.body
}

// Additional Declarations
  //## begin CWCStateConfigDACCalibrated%3FBB6FA900EA.declarations preserve=yes
  //## end CWCStateConfigDACCalibrated%3FBB6FA900EA.declarations

// Class CWCStateConfigCalibDACIncCurr 

//## begin CWCStateConfigCalibDACIncCurr::pInstance%3FBC81770178.role preserve=no  public: static CWCStateConfigCalibDACIncCurr {1..1 -> 1..1RFHN}
CWCStateConfigCalibDACIncCurr *CWCStateConfigCalibDACIncCurr::m_pInstance;
//## end CWCStateConfigCalibDACIncCurr::pInstance%3FBC81770178.role


CWCStateConfigCalibDACIncCurr::CWCStateConfigCalibDACIncCurr()
  //## begin CWCStateConfigCalibDACIncCurr::CWCStateConfigCalibDACIncCurr%.hasinit preserve=no
  //## end CWCStateConfigCalibDACIncCurr::CWCStateConfigCalibDACIncCurr%.hasinit
  //## begin CWCStateConfigCalibDACIncCurr::CWCStateConfigCalibDACIncCurr%.initialization preserve=yes
  //## end CWCStateConfigCalibDACIncCurr::CWCStateConfigCalibDACIncCurr%.initialization
{
  //## begin CWCStateConfigCalibDACIncCurr::CWCStateConfigCalibDACIncCurr%.body preserve=yes
  //## end CWCStateConfigCalibDACIncCurr::CWCStateConfigCalibDACIncCurr%.body
}


CWCStateConfigCalibDACIncCurr::~CWCStateConfigCalibDACIncCurr()
{
  //## begin CWCStateConfigCalibDACIncCurr::~CWCStateConfigCalibDACIncCurr%.body preserve=yes
  //## end CWCStateConfigCalibDACIncCurr::~CWCStateConfigCalibDACIncCurr%.body
}



//## Other Operations (implementation)
void CWCStateConfigCalibDACIncCurr::Create ()
{
  //## begin CWCStateConfigCalibDACIncCurr::Create%1069318237.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CWCStateConfigCalibDACIncCurr();
  //## end CWCStateConfigCalibDACIncCurr::Create%1069318237.body
}

void CWCStateConfigCalibDACIncCurr::Delete ()
{
  //## begin CWCStateConfigCalibDACIncCurr::Delete%1069318238.body preserve=yes
  if(m_pInstance)
    delete m_pInstance;
  m_pInstance = NULL;
  //## end CWCStateConfigCalibDACIncCurr::Delete%1069318238.body
}

CWCStateConfigCalibDACIncCurr* CWCStateConfigCalibDACIncCurr::GetInstance ()
{
  //## begin CWCStateConfigCalibDACIncCurr::GetInstance%1069318239.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CWCStateConfigCalibDACIncCurr::GetInstance%1069318239.body
}

void CWCStateConfigCalibDACIncCurr::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfigCalibDACIncCurr::Enter%1069318249.body preserve=yes
  //## end CWCStateConfigCalibDACIncCurr::Enter%1069318249.body
}

void CWCStateConfigCalibDACIncCurr::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfigCalibDACIncCurr::Do%1069318240.body preserve=yes
	CWCActionCurrDir* l_pAction = (CWCActionCurrDir*)p_pContext->GetAction(IDA_DAC_CURR_DIR);
	CCOSyncObject* l_pSyncObj = l_pAction->GetpServerSyncObj();
    
	// do not act on high prio commands!!!!
	switch(p_pContext->WaitOnActionDone(l_pSyncObj, CO_WAKE_MASK_ACTIONS_ALL, CHITDACMAX5712::GetcdwWaitTimeAutoCalibration()))
	{
	  /*case eIRActionsDone:
		l_pAction->Done();
		l_pAction->SeteEventRegistration(eHILow);
		p_pContext->ChangeState(CWCStateConfigCalibDACDecCurr::GetInstance(), l_pAction);
		break;*/

    case eIRActionsDone:
      l_pAction->Done();
      l_pAction->SeteEventRegistration(eHIHigh);
      p_pContext->ChangeState(CWCStateConfigDACCalibrated::GetInstance());
      break;

  
	  case eIRTimeout:
		// inc. DAC value
		m_dwCalibDACOffsetValue+= 1;
		if (m_dwCalibDACOffsetValue > (CHITDACMAX5712::GetcdwDefaultOffsetValue() + CHITDACMAX5712::GetcdwMaxOffsetCalibError()))
		{
		  throw new XWCExceptionError(WC_ID, IDE_WC_DAC_CALIBRATION_ERROR, _T(__FILE__), __LINE__, 0);
		}
		else
		{
		  CO_TRACE1(WC_ID,_T("WC actual DAC calibration value = %d"),m_dwCalibDACOffsetValue);
		  IHIInterface::GetInstance()->WCSetDACValue(m_dwCalibDACOffsetValue);
		  p_pContext->ChangeState(CWCStateConfigCalibDACIncCurr::GetInstance());
		}  
		break;

	  case eIRCmdAboveNormal:
	  case eIRCmdHigh:
	  default:
		throw new XWCExceptionError(WC_ID, IDE_WC_DAC_CALIBRATION_ERROR, _T(__FILE__), __LINE__, 0);
		break;
  
	}
  //## end CWCStateConfigCalibDACIncCurr::Do%1069318240.body
}

// Additional Declarations
  //## begin CWCStateConfigCalibDACIncCurr%3FBC810B0138.declarations preserve=yes
  //## end CWCStateConfigCalibDACIncCurr%3FBC810B0138.declarations

// Class CWCStateConfigCalibDACDecCurr 

//## begin CWCStateConfigCalibDACDecCurr::pInstance%3FBC81FF03D9.role preserve=no  public: static CWCStateConfigCalibDACDecCurr {1..1 -> 1..1RFHN}
CWCStateConfigCalibDACDecCurr *CWCStateConfigCalibDACDecCurr::m_pInstance;
//## end CWCStateConfigCalibDACDecCurr::pInstance%3FBC81FF03D9.role


CWCStateConfigCalibDACDecCurr::CWCStateConfigCalibDACDecCurr()
  //## begin CWCStateConfigCalibDACDecCurr::CWCStateConfigCalibDACDecCurr%.hasinit preserve=no
  //## end CWCStateConfigCalibDACDecCurr::CWCStateConfigCalibDACDecCurr%.hasinit
  //## begin CWCStateConfigCalibDACDecCurr::CWCStateConfigCalibDACDecCurr%.initialization preserve=yes
  //## end CWCStateConfigCalibDACDecCurr::CWCStateConfigCalibDACDecCurr%.initialization
{
  //## begin CWCStateConfigCalibDACDecCurr::CWCStateConfigCalibDACDecCurr%.body preserve=yes
  //## end CWCStateConfigCalibDACDecCurr::CWCStateConfigCalibDACDecCurr%.body
}


CWCStateConfigCalibDACDecCurr::~CWCStateConfigCalibDACDecCurr()
{
  //## begin CWCStateConfigCalibDACDecCurr::~CWCStateConfigCalibDACDecCurr%.body preserve=yes
  //## end CWCStateConfigCalibDACDecCurr::~CWCStateConfigCalibDACDecCurr%.body
}



//## Other Operations (implementation)
void CWCStateConfigCalibDACDecCurr::Create ()
{
  //## begin CWCStateConfigCalibDACDecCurr::Create%1069318241.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CWCStateConfigCalibDACDecCurr();
  //## end CWCStateConfigCalibDACDecCurr::Create%1069318241.body
}

void CWCStateConfigCalibDACDecCurr::Delete ()
{
  //## begin CWCStateConfigCalibDACDecCurr::Delete%1069318242.body preserve=yes
  if(m_pInstance)
    delete m_pInstance;
  m_pInstance = NULL;
  //## end CWCStateConfigCalibDACDecCurr::Delete%1069318242.body
}

CWCStateConfigCalibDACDecCurr* CWCStateConfigCalibDACDecCurr::GetInstance ()
{
  //## begin CWCStateConfigCalibDACDecCurr::GetInstance%1069318243.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CWCStateConfigCalibDACDecCurr::GetInstance%1069318243.body
}

void CWCStateConfigCalibDACDecCurr::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfigCalibDACDecCurr::Enter%1069318250.body preserve=yes
  //## end CWCStateConfigCalibDACDecCurr::Enter%1069318250.body
}

void CWCStateConfigCalibDACDecCurr::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateConfigCalibDACDecCurr::Do%1069318244.body preserve=yes
	CWCActionCurrDir* l_pAction = (CWCActionCurrDir*)p_pContext->GetAction(IDA_DAC_CURR_DIR);
	CCOSyncObject* l_pSyncObj = l_pAction->GetpServerSyncObj();

	// do not act on high prio commands!!!!
    switch(p_pContext->WaitOnActionDone(l_pSyncObj, CO_WAKE_MASK_ACTIONS_ALL, CHITDACMAX5712::GetcdwWaitTimeAutoCalibration()))
    {
      /*case eIRActionsDone:
        l_pAction->Done();
        l_pAction->SeteEventRegistration(eHIHigh);
        p_pContext->ChangeState(CWCStateConfigDACCalibrated::GetInstance());
        break;*/

	    case eIRActionsDone:
		    l_pAction->Done();
		    l_pAction->SeteEventRegistration(eHIHigh);
		    p_pContext->ChangeState(CWCStateConfigCalibDACIncCurr::GetInstance(), l_pAction);
		    break;

      
      case eIRTimeout:
        // inc. DAC value
        m_dwCalibDACOffsetValue-= 1;
        if (m_dwCalibDACOffsetValue < (CHITDACMAX5712::GetcdwDefaultOffsetValue() - CHITDACMAX5712::GetcdwMaxOffsetCalibError()))
        {
       	  throw new XWCExceptionError(WC_ID, IDE_WC_DAC_CALIBRATION_ERROR, _T(__FILE__), __LINE__, 0);
        }
        else
        {
          CO_TRACE1(WC_ID,_T("WC actual DAC calibration value = %d"),m_dwCalibDACOffsetValue);
          IHIInterface::GetInstance()->WCSetDACValue(m_dwCalibDACOffsetValue);
          p_pContext->ChangeState(CWCStateConfigCalibDACDecCurr::GetInstance());
        }  
        break;

      case eIRCmdAboveNormal:
      case eIRCmdHigh:
      default:
     	  throw new XWCExceptionError(WC_ID, IDE_WC_DAC_CALIBRATION_ERROR, _T(__FILE__), __LINE__, 0);
          break;
      
    }
  //## end CWCStateConfigCalibDACDecCurr::Do%1069318244.body
}

// Additional Declarations
  //## begin CWCStateConfigCalibDACDecCurr%3FBC81A5033C.declarations preserve=yes
  //## end CWCStateConfigCalibDACDecCurr%3FBC81A5033C.declarations

//## begin module%3E38FDBA0280.epilog preserve=yes
//## end module%3E38FDBA0280.epilog
