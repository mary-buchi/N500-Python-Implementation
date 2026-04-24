//## begin module%3E38FDC802EE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E38FDC802EE.cm

//## begin module%3E38FDC802EE.cp preserve=no
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
//## end module%3E38FDC802EE.cp

//## Module: EBWCinit%3E38FDC802EE; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCinit.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E38FDC802EE.additionalIncludes preserve=no
//## end module%3E38FDC802EE.additionalIncludes

//## begin module%3E38FDC802EE.includes preserve=yes
//## end module%3E38FDC802EE.includes

// EBWCimpl
#include "EBWCimpl.h"
// EBCOimct
#include "EBCOimct.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBWCidnt
#include "EBWCidnt.h"
// EBWCemst
#include "EBWCemst.h"
// EBWCexcp
#include "EBWCexcp.h"
// EBWCconn
#include "EBWCconn.h"
// EBWCacti
#include "EBWCacti.h"
// EBWCproc
#include "EBWCproc.h"
// EBWCinit
#include "EBWCinit.h"
// EBWCconf
#include "EBWCconf.h"
// EBWCidle
#include "EBWCidle.h"
// EBHIexcp
#include "EBHIexcp.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3E38FDC802EE.declarations preserve=no
//## end module%3E38FDC802EE.declarations

//## begin module%3E38FDC802EE.additionalDeclarations preserve=yes
//## end module%3E38FDC802EE.additionalDeclarations


// Class CWCStateInitialize 

//## begin CWCStateInitialize::bWCInitialized%3E394388036C.role preserve=no  public: static BOOL {1..1 -> 1..1VFHN}
BOOL CWCStateInitialize::m_bWCInitialized = FALSE;
//## end CWCStateInitialize::bWCInitialized%3E394388036C.role

//## begin CWCStateInitialize::bWCStartCmd%3FCB5A9C01A6.role preserve=no  public: static BOOL {1..1 -> 1..1VFHN}
BOOL CWCStateInitialize::m_bWCStartCmd = false;
//## end CWCStateInitialize::bWCStartCmd%3FCB5A9C01A6.role

CWCStateInitialize::CWCStateInitialize()
  //## begin CWCStateInitialize::CWCStateInitialize%.hasinit preserve=no
  //## end CWCStateInitialize::CWCStateInitialize%.hasinit
  //## begin CWCStateInitialize::CWCStateInitialize%.initialization preserve=yes
  //## end CWCStateInitialize::CWCStateInitialize%.initialization
{
  //## begin CWCStateInitialize::CWCStateInitialize%.body preserve=yes
  //## end CWCStateInitialize::CWCStateInitialize%.body
}


CWCStateInitialize::~CWCStateInitialize()
{
  //## begin CWCStateInitialize::~CWCStateInitialize%.body preserve=yes
  //## end CWCStateInitialize::~CWCStateInitialize%.body
}



//## Other Operations (implementation)
void CWCStateInitialize::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateInitialize::Startup%1066311477.body preserve=yes
	m_bWCStartCmd = false;
  p_pContext->ChangeState(CWCStateConfigNotAssign::GetInstance());
  //## end CWCStateInitialize::Startup%1066311477.body
}

void CWCStateInitialize::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateInitialize::Shutdown%1043917007.body preserve=yes
  try
  {
    m_bWCStartCmd = false;
    CWCStateConfig::SetbWCProfileExist(FALSE);
    CWCStateInitialize::SetbWCInitialized(FALSE);
	CWCStateConfig::SetpConfig(NULL);
	CWCStateConfigProfile::GetInstance()->SetpProfile(NULL);
    IHIInterface::GetInstance()->WCEmergencyStop();
    p_pContext->ChangeState(CWCStateCreated::GetInstance());
  }
  catch(...)
  {
    throw;
  }
  //## end CWCStateInitialize::Shutdown%1043917007.body
}

void CWCStateInitialize::SetConfiguration (ICOStateMachineContext* p_pContext, CPIWedgeControlConfig* p_pConfig)
{
  //## begin CWCStateInitialize::SetConfiguration%1043917050.body preserve=yes
    CWCStateConfiguration::GetInstance()->SetpConfig(p_pConfig);
    p_pContext->ChangeState(CWCStateConfiguration::GetInstance());
  //## end CWCStateInitialize::SetConfiguration%1043917050.body
}

void CWCStateInitialize::CleanupStop (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateInitialize::CleanupStop%1053065380.body preserve=yes
  CleanupInitialize(p_pContext);
  //## end CWCStateInitialize::CleanupStop%1053065380.body
}

void CWCStateInitialize::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateInitialize::CleanupInitialize%1053065381.body preserve=yes
  try
  {
    m_bWCStartCmd = false;
    m_bWCInitialized = FALSE;
    IHIInterface::GetInstance()->WCEmergencyStop();
    p_pContext->ChangeState(CWCStateConfigInitDAC::GetInstance());
  }
  catch(...)
  {
    p_pContext->ChangeState(CWCStateConfigInitDAC::GetInstance());
  }
  //## end CWCStateInitialize::CleanupInitialize%1053065381.body
}

void CWCStateInitialize::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateInitialize::ConnectionLost%1063260202.body preserve=yes
  try
  {
  	m_bWCStartCmd = false;
    m_bWCInitialized = false;
    IHIInterface::GetInstance()->WCEmergencyStop();
  	p_pContext->ChangeState(CWCStateNotConnected::GetInstance());
  }
  catch(...)
  {
  	p_pContext->ChangeState(CWCStateNotConnected::GetInstance());
  }
  //## end CWCStateInitialize::ConnectionLost%1063260202.body
}

void CWCStateInitialize::Stop (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateInitialize::Stop%1100615762.body preserve=yes
  //## end CWCStateInitialize::Stop%1100615762.body
}

//## Get and Set Operations for Associations (implementation)

const BOOL CWCStateInitialize::GetbWCInitialized ()
{
  //## begin CWCStateInitialize::GetbWCInitialized%3E394388036C.get preserve=no
  return m_bWCInitialized;
  //## end CWCStateInitialize::GetbWCInitialized%3E394388036C.get
}

void CWCStateInitialize::SetbWCInitialized (BOOL value)
{
  //## begin CWCStateInitialize::SetbWCInitialized%3E394388036C.set preserve=no
  m_bWCInitialized = value;
  //## end CWCStateInitialize::SetbWCInitialized%3E394388036C.set
}

BOOL CWCStateInitialize::GetbWCStartCmd ()
{
  //## begin CWCStateInitialize::GetbWCStartCmd%3FCB5A9C01A6.get preserve=no
  return m_bWCStartCmd;
  //## end CWCStateInitialize::GetbWCStartCmd%3FCB5A9C01A6.get
}

void CWCStateInitialize::SetbWCStartCmd (BOOL value)
{
  //## begin CWCStateInitialize::SetbWCStartCmd%3FCB5A9C01A6.set preserve=no
  m_bWCStartCmd = value;
  //## end CWCStateInitialize::SetbWCStartCmd%3FCB5A9C01A6.set
}

// Additional Declarations
  //## begin CWCStateInitialize%3E38FD1B02CE.declarations preserve=yes
  //## end CWCStateInitialize%3E38FD1B02CE.declarations

// Class CWCStateInitializeStopped 

//## begin CWCStateInitializeStopped::pInstance%3E39226202A0.role preserve=no  public: static CWCStateInitializeStopped {1..1 -> 1..1RFHN}
CWCStateInitializeStopped *CWCStateInitializeStopped::m_pInstance;
//## end CWCStateInitializeStopped::pInstance%3E39226202A0.role


CWCStateInitializeStopped::CWCStateInitializeStopped()
  //## begin CWCStateInitializeStopped::CWCStateInitializeStopped%.hasinit preserve=no
  //## end CWCStateInitializeStopped::CWCStateInitializeStopped%.hasinit
  //## begin CWCStateInitializeStopped::CWCStateInitializeStopped%.initialization preserve=yes
  //## end CWCStateInitializeStopped::CWCStateInitializeStopped%.initialization
{
  //## begin CWCStateInitializeStopped::CWCStateInitializeStopped%.body preserve=yes
  //## end CWCStateInitializeStopped::CWCStateInitializeStopped%.body
}


CWCStateInitializeStopped::~CWCStateInitializeStopped()
{
  //## begin CWCStateInitializeStopped::~CWCStateInitializeStopped%.body preserve=yes
  //## end CWCStateInitializeStopped::~CWCStateInitializeStopped%.body
}



//## Other Operations (implementation)
void CWCStateInitializeStopped::Create ()
{
  //## begin CWCStateInitializeStopped::Create%1043917017.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CWCStateInitializeStopped();
  //## end CWCStateInitializeStopped::Create%1043917017.body
}

void CWCStateInitializeStopped::Delete ()
{
  //## begin CWCStateInitializeStopped::Delete%1043917018.body preserve=yes
    if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CWCStateInitializeStopped::Delete%1043917018.body
}

CWCStateInitializeStopped* CWCStateInitializeStopped::GetInstance ()
{
  //## begin CWCStateInitializeStopped::GetInstance%1043917019.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CWCStateInitializeStopped::GetInstance%1043917019.body
}

void CWCStateInitializeStopped::Initialize (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateInitializeStopped::Initialize%1052978389.body preserve=yes
	CCOSyncObjectPtr l_pSyncObj = NULL;
    try
    {
        if (GetpContext(p_pContext)->GetbHWPresent())
        {
            l_pSyncObj = IHIInterface::GetInstance()->WCInitialize(CWCStateConfig::GetpConfig()->GetdwWCIdInitializedEvent());
            l_pSyncObj->Synchronize(4000);


			IHIInterface::GetInstance()->CloseEvent(CWCStateConfig::GetpConfig()->GetdwWCIdInitializedEvent(), l_pSyncObj);
        }
    }
	catch(XHIExceptionError* p_pException)
	{
		if (l_pSyncObj != NULL)
			IHIInterface::GetInstance()->CloseEvent(CWCStateConfig::GetpConfig()->GetdwWCIdInitializedEvent(), l_pSyncObj);
		DWORD l_dwErrorCode = p_pException->GetdwErrorCode();
        p_pException->Delete();
       	throw new XWCExceptionError(WC_ID, IDE_WC_INITIALIZING_ERROR, _T(__FILE__), __LINE__, l_dwErrorCode);
	}
    catch(XCOExceptionError* p_pException)
    {
		if (l_pSyncObj != NULL)
			IHIInterface::GetInstance()->CloseEvent(CWCStateConfig::GetpConfig()->GetdwWCIdInitializedEvent(), l_pSyncObj);
        p_pException->Delete();
        DWORD l_dwErrorCode = IHIInterface::GetInstance()->GetHWExceptionErrorCode();
       	throw new XWCExceptionError(WC_ID, IDE_WC_INITIALIZING_ERROR, _T(__FILE__), __LINE__, l_dwErrorCode);
    }
  //## end CWCStateInitializeStopped::Initialize%1052978389.body
}

void CWCStateInitializeStopped::Referencing (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateInitializeStopped::Referencing%1043996009.body preserve=yes
	CCOSyncObjectPtr l_pSyncObj = NULL;
    try
    {
        if (GetpContext(p_pContext)->GetbHWPresent())
        {
            l_pSyncObj = IHIInterface::GetInstance()->WCReferencing(CWCStateConfig::GetpConfig()->GetdwWCIdReferencedEvent());
            l_pSyncObj->Synchronize(4000);

			IHIInterface::GetInstance()->CloseEvent(CWCStateConfig::GetpConfig()->GetdwWCIdReferencedEvent(), l_pSyncObj);
        }
    }
	catch(XHIExceptionError* p_pException)
	{
		if (l_pSyncObj != NULL)
			IHIInterface::GetInstance()->CloseEvent(CWCStateConfig::GetpConfig()->GetdwWCIdInitializedEvent(), l_pSyncObj);
		DWORD l_dwErrorCode = p_pException->GetdwErrorCode();
        p_pException->Delete();
       	throw new XWCExceptionError(WC_ID, IDE_WC_REFERENCING_ERROR, _T(__FILE__), __LINE__, l_dwErrorCode);
	}
    catch(XCOExceptionError* p_pException)
    {
		if (l_pSyncObj != NULL)
			IHIInterface::GetInstance()->CloseEvent(CWCStateConfig::GetpConfig()->GetdwWCIdReferencedEvent(), l_pSyncObj);
        p_pException->Delete();
        DWORD l_dwErrorCode = IHIInterface::GetInstance()->GetHWExceptionErrorCode();
       	throw new XWCExceptionError(WC_ID, IDE_WC_REFERENCING_ERROR, _T(__FILE__), __LINE__, l_dwErrorCode);
    }
  //## end CWCStateInitializeStopped::Referencing%1043996009.body
}

void CWCStateInitializeStopped::Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pSyncStartObj, CCOSyncObjectInt* p_pSyncExcObj)
{
  //## begin CWCStateInitializeStopped::Start%1070263840.body preserve=yes
  CWCActionInitialize* l_pAction = (CWCActionInitialize*)p_pContext->GetAction(IDA_INITIALIZE);
  l_pAction->SetdwInitializedEvent(CWCStateConfig::GetpConfig()->GetdwWCIdInitializedEvent());
  
  GetpContext(p_pContext)->SetpSyncStartObj(p_pSyncStartObj);
  GetpContext(p_pContext)->SetpSyncExcObj(p_pSyncExcObj);

  p_pContext->ChangeState(CWCStateInitializing::GetInstance(), l_pAction);
  //## end CWCStateInitializeStopped::Start%1070263840.body
}

void CWCStateInitializeStopped::SetProfile (ICOStateMachineContext* p_pContext, CPIWedgeControlProfile* p_pProfile)
{
  //## begin CWCStateInitializeStopped::SetProfile%1104756850.body preserve=yes
    CWCStateConfigProfile::GetInstance()->SetpProfile(p_pProfile);
    p_pContext->ChangeState(CWCStateConfigProfile::GetInstance());
  //## end CWCStateInitializeStopped::SetProfile%1104756850.body
}

void CWCStateInitializeStopped::GetDacZeroCurrent (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj)
{
  //## begin CWCStateInitializeStopped::GetDacZeroCurrent%1149148977.body preserve=yes
	int l_iDacZeroCurrent = (int)CWCStateConfig::GetdwCalibDACOffsetValue();
	p_pClientSyncObj->SetValue(l_iDacZeroCurrent);
	p_pClientSyncObj->SignalCompletion();
  //## end CWCStateInitializeStopped::GetDacZeroCurrent%1149148977.body
}

// Additional Declarations
  //## begin CWCStateInitializeStopped%3E3919A0002E.declarations preserve=yes
  //## end CWCStateInitializeStopped%3E3919A0002E.declarations

// Class CWCStateInitializing 

//## begin CWCStateInitializing::pInstance%3E38FFDD032C.role preserve=no  public: static CWCStateInitializing {1..1 -> 1..1RFHN}
CWCStateInitializing *CWCStateInitializing::m_pInstance;
//## end CWCStateInitializing::pInstance%3E38FFDD032C.role


CWCStateInitializing::CWCStateInitializing()
  //## begin CWCStateInitializing::CWCStateInitializing%.hasinit preserve=no
  //## end CWCStateInitializing::CWCStateInitializing%.hasinit
  //## begin CWCStateInitializing::CWCStateInitializing%.initialization preserve=yes
  //## end CWCStateInitializing::CWCStateInitializing%.initialization
{
  //## begin CWCStateInitializing::CWCStateInitializing%.body preserve=yes
  //## end CWCStateInitializing::CWCStateInitializing%.body
}


CWCStateInitializing::~CWCStateInitializing()
{
  //## begin CWCStateInitializing::~CWCStateInitializing%.body preserve=yes
  //## end CWCStateInitializing::~CWCStateInitializing%.body
}



//## Other Operations (implementation)
void CWCStateInitializing::Create ()
{
  //## begin CWCStateInitializing::Create%1043917014.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CWCStateInitializing();
  //## end CWCStateInitializing::Create%1043917014.body
}

void CWCStateInitializing::Delete ()
{
  //## begin CWCStateInitializing::Delete%1043917015.body preserve=yes
    if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CWCStateInitializing::Delete%1043917015.body
}

CWCStateInitializing* CWCStateInitializing::GetInstance ()
{
  //## begin CWCStateInitializing::GetInstance%1043917016.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CWCStateInitializing::GetInstance%1043917016.body
}

void CWCStateInitializing::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateInitializing::Do%1046252826.body preserve=yes
  DWORD l_dwErrorCode = 0;
  try
  {
    CCOSyncObject* l_pSyncObj = p_pContext->GetAction(IDA_INITIALIZE)->GetpServerSyncObj();
    
    switch(p_pContext->WaitOnActionDone(l_pSyncObj,CO_WAKE_MASK_DEFAULT,4000))
    {
      case eIRActionsDone:
        p_pContext->GetAction(IDA_INITIALIZE)->Done();

        {
            CWCActionReferencing* l_pAction = (CWCActionReferencing*)p_pContext->GetAction(IDA_REFERENCING);
            l_pAction->SetdwReferencedEvent(CWCStateConfig::GetpConfig()->GetdwWCIdReferencedEvent());

            p_pContext->ChangeState(CWCStateInitializeReferencing::GetInstance(), l_pAction);
        }
        break;
      
      case eIRTimeout:
        l_dwErrorCode = IHIInterface::GetInstance()->GetHWExceptionErrorCode();
       	throw new XWCExceptionError(WC_ID, IDE_WC_INITIALIZING_ERROR, _T(__FILE__), __LINE__, l_dwErrorCode);
        break;
      
      case eIRCmdAboveNormal:
      case eIRCmdHigh:
        p_pContext->GetAction(IDA_INITIALIZE)->Done();
        break;
      
      default:
        ASSERT(FALSE);
        break;
      
    }
  }
  catch(...)
  {
    throw;
  }
  //## end CWCStateInitializing::Do%1046252826.body
}

// Additional Declarations
  //## begin CWCStateInitializing%3E3919C4037A.declarations preserve=yes
  //## end CWCStateInitializing%3E3919C4037A.declarations

// Class CWCStateInitializeReferencing 

//## begin CWCStateInitializeReferencing::pInstance%3E3922DF033D.role preserve=no  public: static CWCStateInitializeReferencing {1..1 -> 1..1RFHN}
CWCStateInitializeReferencing *CWCStateInitializeReferencing::m_pInstance;
//## end CWCStateInitializeReferencing::pInstance%3E3922DF033D.role


CWCStateInitializeReferencing::CWCStateInitializeReferencing()
  //## begin CWCStateInitializeReferencing::CWCStateInitializeReferencing%.hasinit preserve=no
  //## end CWCStateInitializeReferencing::CWCStateInitializeReferencing%.hasinit
  //## begin CWCStateInitializeReferencing::CWCStateInitializeReferencing%.initialization preserve=yes
  //## end CWCStateInitializeReferencing::CWCStateInitializeReferencing%.initialization
{
  //## begin CWCStateInitializeReferencing::CWCStateInitializeReferencing%.body preserve=yes
  //## end CWCStateInitializeReferencing::CWCStateInitializeReferencing%.body
}


CWCStateInitializeReferencing::~CWCStateInitializeReferencing()
{
  //## begin CWCStateInitializeReferencing::~CWCStateInitializeReferencing%.body preserve=yes
  //## end CWCStateInitializeReferencing::~CWCStateInitializeReferencing%.body
}



//## Other Operations (implementation)
void CWCStateInitializeReferencing::Create ()
{
  //## begin CWCStateInitializeReferencing::Create%1043917020.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CWCStateInitializeReferencing();
  //## end CWCStateInitializeReferencing::Create%1043917020.body
}

void CWCStateInitializeReferencing::Delete ()
{
  //## begin CWCStateInitializeReferencing::Delete%1043917021.body preserve=yes
    if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CWCStateInitializeReferencing::Delete%1043917021.body
}

CWCStateInitializeReferencing* CWCStateInitializeReferencing::GetInstance ()
{
  //## begin CWCStateInitializeReferencing::GetInstance%1043917022.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CWCStateInitializeReferencing::GetInstance%1043917022.body
}

void CWCStateInitializeReferencing::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateInitializeReferencing::Do%1046252827.body preserve=yes
  DWORD l_dwErrorCode = 0;
  try
  {
    CCOSyncObject* l_pSyncObj = p_pContext->GetAction(IDA_REFERENCING)->GetpServerSyncObj();
    switch(p_pContext->WaitOnActionDone(l_pSyncObj,CO_WAKE_MASK_DEFAULT,4000))
    {
      case eIRActionsDone:
        p_pContext->GetAction(IDA_REFERENCING)->Done();
        p_pContext->ChangeState(CWCStateProcStarting::GetInstance());
        break;
      
      case eIRTimeout:
        l_dwErrorCode = IHIInterface::GetInstance()->GetHWExceptionErrorCode();
       	throw new XWCExceptionError(WC_ID, IDE_WC_REFERENCING_ERROR, _T(__FILE__), __LINE__, l_dwErrorCode);
        break;
      
      case eIRCmdAboveNormal:
      case eIRCmdHigh:
        p_pContext->GetAction(IDA_REFERENCING)->Done();
        break;
      
      default:
        ASSERT(FALSE);
        break;
      
    }
  }
  catch(...)
  {
    throw;
  }
  //## end CWCStateInitializeReferencing::Do%1046252827.body
}

// Additional Declarations
  //## begin CWCStateInitializeReferencing%3E391A4200FA.declarations preserve=yes
  //## end CWCStateInitializeReferencing%3E391A4200FA.declarations

//## begin module%3E38FDC802EE.epilog preserve=yes
//## end module%3E38FDC802EE.epilog
