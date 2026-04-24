//## begin module%3E6DD9C10196.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E6DD9C10196.cm

//## begin module%3E6DD9C10196.cp preserve=no
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
//## end module%3E6DD9C10196.cp

//## Module: EBMCproc%3E6DD9C10196; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCproc.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E6DD9C10196.additionalIncludes preserve=no
//## end module%3E6DD9C10196.additionalIncludes

//## begin module%3E6DD9C10196.includes preserve=yes
//## end module%3E6DD9C10196.includes

// EBPItype
#include "EBPItype.h"
// EBCOimct
#include "EBCOimct.h"
// EBMCsimu
#include "EBMCsimu.h"
// EBMCconn
#include "EBMCconn.h"
// EBMCdata
#include "EBMCdata.h"
// EBMCproc
#include "EBMCproc.h"
// EBMCidle
#include "EBMCidle.h"
// EBMCimpl
#include "EBMCimpl.h"
// EBHIintf
#include "EBHIintf.h"
// EBHIdefi
#include "EBHIdefi.h"


//## begin module%3E6DD9C10196.declarations preserve=no
//## end module%3E6DD9C10196.declarations

//## begin module%3E6DD9C10196.additionalDeclarations preserve=yes
//## end module%3E6DD9C10196.additionalDeclarations


// Class CMCStateProfileNotAssign 

//## begin CMCStateProfileNotAssign::pInstance%3E6DDC5B02CF.role preserve=no  public: static CMCStateProfileNotAssign {1..1 -> 1..1RFHN}
CMCStateProfileNotAssign *CMCStateProfileNotAssign::m_pInstance = NULL;
//## end CMCStateProfileNotAssign::pInstance%3E6DDC5B02CF.role


CMCStateProfileNotAssign::CMCStateProfileNotAssign()
  //## begin CMCStateProfileNotAssign::CMCStateProfileNotAssign%.hasinit preserve=no
  //## end CMCStateProfileNotAssign::CMCStateProfileNotAssign%.hasinit
  //## begin CMCStateProfileNotAssign::CMCStateProfileNotAssign%.initialization preserve=yes
  //## end CMCStateProfileNotAssign::CMCStateProfileNotAssign%.initialization
{
  //## begin CMCStateProfileNotAssign::CMCStateProfileNotAssign%.body preserve=yes
  //## end CMCStateProfileNotAssign::CMCStateProfileNotAssign%.body
}


CMCStateProfileNotAssign::~CMCStateProfileNotAssign()
{
  //## begin CMCStateProfileNotAssign::~CMCStateProfileNotAssign%.body preserve=yes
  //## end CMCStateProfileNotAssign::~CMCStateProfileNotAssign%.body
}



//## Other Operations (implementation)
void CMCStateProfileNotAssign::Delete ()
{
  //## begin CMCStateProfileNotAssign::Delete%1047364721.body preserve=yes
  if(m_pInstance)
    delete m_pInstance;
  m_pInstance = NULL;
  //## end CMCStateProfileNotAssign::Delete%1047364721.body
}

void CMCStateProfileNotAssign::Create ()
{
  //## begin CMCStateProfileNotAssign::Create%1047364722.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CMCStateProfileNotAssign();
  //## end CMCStateProfileNotAssign::Create%1047364722.body
}

CMCStateProfileNotAssign* CMCStateProfileNotAssign::GetInstance ()
{
  //## begin CMCStateProfileNotAssign::GetInstance%1047364723.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CMCStateProfileNotAssign::GetInstance%1047364723.body
}

void CMCStateProfileNotAssign::SetProfile (ICOStateMachineContext* p_pContext, CPIMeasurementChannelProfile* p_pProfile)
{
  //## begin CMCStateProfileNotAssign::SetProfile%1047364713.body preserve=yes
  CMCStateProfile::GetInstance()->SetpProfile(p_pProfile);
  p_pContext->ChangeState(CMCStateProfile::GetInstance());
  //## end CMCStateProfileNotAssign::SetProfile%1047364713.body
}

// Additional Declarations
  //## begin CMCStateProfileNotAssign%3E6DD9860290.declarations preserve=yes
  //## end CMCStateProfileNotAssign%3E6DD9860290.declarations

// Class CMCStateProcess 

//## begin CMCStateProcess::bMCInitialized%3E6DDFFF036C.role preserve=no  public: static BOOL {1..1 -> 1..1VFHN}
BOOL CMCStateProcess::m_bMCInitialized = FALSE;
//## end CMCStateProcess::bMCInitialized%3E6DDFFF036C.role

CMCStateProcess::CMCStateProcess()
  //## begin CMCStateProcess::CMCStateProcess%.hasinit preserve=no
  //## end CMCStateProcess::CMCStateProcess%.hasinit
  //## begin CMCStateProcess::CMCStateProcess%.initialization preserve=yes
  //## end CMCStateProcess::CMCStateProcess%.initialization
{
  //## begin CMCStateProcess::CMCStateProcess%.body preserve=yes
  //## end CMCStateProcess::CMCStateProcess%.body
}


CMCStateProcess::~CMCStateProcess()
{
  //## begin CMCStateProcess::~CMCStateProcess%.body preserve=yes
  //## end CMCStateProcess::~CMCStateProcess%.body
}



//## Other Operations (implementation)
void CMCStateProcess::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateProcess::Shutdown%1047364714.body preserve=yes
	m_bMCInitialized = false;
	CMCStateProfile::GetInstance()->SetpProfile(NULL);
	p_pContext->ChangeState(CMCStateCreated::GetInstance());
  //## end CMCStateProcess::Shutdown%1047364714.body
}

void CMCStateProcess::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateProcess::ConnectionLost%1063260200.body preserve=yes
	p_pContext->ChangeState(CMCStateNotConnected::GetInstance());
  //## end CMCStateProcess::ConnectionLost%1063260200.body
}

void CMCStateProcess::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateProcess::Startup%1063717516.body preserve=yes
	m_bMCInitialized = false;
	p_pContext->ChangeState(CMCStateProfileNotAssign::GetInstance());
  //## end CMCStateProcess::Startup%1063717516.body
}

void CMCStateProcess::CleanupStop (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateProcess::CleanupStop%1080293048.body preserve=yes
  CleanupInitialize(p_pContext);
  //## end CMCStateProcess::CleanupStop%1080293048.body
}

void CMCStateProcess::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateProcess::CleanupInitialize%1080293049.body preserve=yes
  //## end CMCStateProcess::CleanupInitialize%1080293049.body
}

// Additional Declarations
  //## begin CMCStateProcess%3E6DDA5E01E4.declarations preserve=yes
  //## end CMCStateProcess%3E6DDA5E01E4.declarations

// Class CMCStateProfile 

//## begin CMCStateProfile::pInstance%3E6DDC8E0243.role preserve=no  public: static CMCStateProfile {1..1 -> 1..1RFHN}
CMCStateProfile *CMCStateProfile::m_pInstance = NULL;
//## end CMCStateProfile::pInstance%3E6DDC8E0243.role



CMCStateProfile::CMCStateProfile()
  //## begin CMCStateProfile::CMCStateProfile%.hasinit preserve=no
      : m_pProfile(NULL)
  //## end CMCStateProfile::CMCStateProfile%.hasinit
  //## begin CMCStateProfile::CMCStateProfile%.initialization preserve=yes
  //## end CMCStateProfile::CMCStateProfile%.initialization
{
  //## begin CMCStateProfile::CMCStateProfile%.body preserve=yes
  //## end CMCStateProfile::CMCStateProfile%.body
}


CMCStateProfile::~CMCStateProfile()
{
  //## begin CMCStateProfile::~CMCStateProfile%.body preserve=yes
  //## end CMCStateProfile::~CMCStateProfile%.body
}



//## Other Operations (implementation)
void CMCStateProfile::Delete ()
{
  //## begin CMCStateProfile::Delete%1047364724.body preserve=yes
  if(m_pInstance)
    delete m_pInstance;
  m_pInstance = NULL;
  //## end CMCStateProfile::Delete%1047364724.body
}

void CMCStateProfile::Create ()
{
  //## begin CMCStateProfile::Create%1047364725.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CMCStateProfile();
  //## end CMCStateProfile::Create%1047364725.body
}

CMCStateProfile* CMCStateProfile::GetInstance ()
{
  //## begin CMCStateProfile::GetInstance%1047364726.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CMCStateProfile::GetInstance%1047364726.body
}

void CMCStateProfile::Initialize (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateProfile::Initialize%1047364715.body preserve=yes
  p_pContext->ChangeState(CMCStateInitializing::GetInstance());
  //## end CMCStateProfile::Initialize%1047364715.body
}

void CMCStateProfile::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateProfile::Do%1085646424.body preserve=yes
  CHIMCParameter::SetdwMinTransferDataSize(m_pProfile->GetdwMinDataSize());
  CHIMCParameter::SetdwMaxTransferDataSize(m_pProfile->GetdwMaxDataSize());
  
  CCOSyncObjectPtr l_pSyncObj = IHIInterface::GetInstance()->SetNewStreamBufferSize(m_pProfile->GetdwStreamBufferSizeInByte());
  l_pSyncObj->Synchronize();

  if (m_bMCInitialized)
	  p_pContext->ChangeState(CMCStateInitialized::GetInstance());
  //## end CMCStateProfile::Do%1085646424.body
}

//## Get and Set Operations for Associations (implementation)

void CMCStateProfile::SetpProfile (CPIMeasurementChannelProfile * value)
{
  //## begin CMCStateProfile::SetpProfile%40B5A9E602B0.set preserve=yes
  if (m_pProfile != NULL)
    m_pProfile->ReleaseRef();

  m_pProfile = value;
  if (m_pProfile)
	m_pProfile->AddRef();
  //## end CMCStateProfile::SetpProfile%40B5A9E602B0.set
}

// Additional Declarations
  //## begin CMCStateProfile%3E6DDAF7000F.declarations preserve=yes
  //## end CMCStateProfile%3E6DDAF7000F.declarations

// Class CMCStateInitialized 

//## begin CMCStateInitialized::pInstance%3E6DDC9E02DF.role preserve=no  public: static CMCStateInitialized {1..1 -> 1..1RFHN}
CMCStateInitialized *CMCStateInitialized::m_pInstance = NULL;
//## end CMCStateInitialized::pInstance%3E6DDC9E02DF.role


CMCStateInitialized::CMCStateInitialized()
  //## begin CMCStateInitialized::CMCStateInitialized%.hasinit preserve=no
  //## end CMCStateInitialized::CMCStateInitialized%.hasinit
  //## begin CMCStateInitialized::CMCStateInitialized%.initialization preserve=yes
  //## end CMCStateInitialized::CMCStateInitialized%.initialization
{
  //## begin CMCStateInitialized::CMCStateInitialized%.body preserve=yes
  //## end CMCStateInitialized::CMCStateInitialized%.body
}


CMCStateInitialized::~CMCStateInitialized()
{
  //## begin CMCStateInitialized::~CMCStateInitialized%.body preserve=yes
  //## end CMCStateInitialized::~CMCStateInitialized%.body
}



//## Other Operations (implementation)
void CMCStateInitialized::Delete ()
{
  //## begin CMCStateInitialized::Delete%1047364727.body preserve=yes
  if(m_pInstance)
    delete m_pInstance;
  m_pInstance = NULL;
  //## end CMCStateInitialized::Delete%1047364727.body
}

void CMCStateInitialized::Create ()
{
  //## begin CMCStateInitialized::Create%1047364728.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CMCStateInitialized();
  //## end CMCStateInitialized::Create%1047364728.body
}

CMCStateInitialized* CMCStateInitialized::GetInstance ()
{
  //## begin CMCStateInitialized::GetInstance%1047364729.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CMCStateInitialized::GetInstance%1047364729.body
}

void CMCStateInitialized::Start (ICOStateMachineContext* p_pContext, UINT p_uiCycleID)
{
  //## begin CMCStateInitialized::Start%1047364717.body preserve=yes
    CHIMCParameter::SetdwCycleID(p_uiCycleID);
    if (GetpContext(p_pContext)->GetbHWPresent())
    {
        if (!IHIInterface::GetInstance()->MCDataAcquisitionStart())
        {
            ASSERT(false);
            // TEST.PB TODO exception
        }

        p_pContext->ChangeState(CMCStateDataAcquistionReady::GetInstance());
    }
    else
    {
        p_pContext->ChangeState(CMCStateDataSimulationPrepare::GetInstance());
    }
  //## end CMCStateInitialized::Start%1047364717.body
}

void CMCStateInitialized::SetProfile (ICOStateMachineContext* p_pContext, CPIMeasurementChannelProfile* p_pProfile)
{
  //## begin CMCStateInitialized::SetProfile%1047364718.body preserve=yes
  CMCStateProfile::GetInstance()->SetpProfile(p_pProfile);
  p_pContext->ChangeState(CMCStateProfile::GetInstance());
  //## end CMCStateInitialized::SetProfile%1047364718.body
}

void CMCStateInitialized::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateInitialized::Enter%1067518846.body preserve=yes
  m_bMCInitialized = TRUE;
  p_pContext->GetpStateMachineEngine()->Cleanup();
  //## end CMCStateInitialized::Enter%1067518846.body
}

void CMCStateInitialized::Initialize (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateInitialized::Initialize%1131608383.body preserve=yes
  //## end CMCStateInitialized::Initialize%1131608383.body
}

// Additional Declarations
  //## begin CMCStateInitialized%3E6DDB090251.declarations preserve=yes
  //## end CMCStateInitialized%3E6DDB090251.declarations

// Class CMCStateInitializing 

//## begin CMCStateInitializing::pInstance%3FA134D1029F.role preserve=no  public: static CMCStateInitializing {1..1 -> 1..1RFHN}
CMCStateInitializing *CMCStateInitializing::m_pInstance;
//## end CMCStateInitializing::pInstance%3FA134D1029F.role


CMCStateInitializing::CMCStateInitializing()
  //## begin CMCStateInitializing::CMCStateInitializing%.hasinit preserve=no
  //## end CMCStateInitializing::CMCStateInitializing%.hasinit
  //## begin CMCStateInitializing::CMCStateInitializing%.initialization preserve=yes
  //## end CMCStateInitializing::CMCStateInitializing%.initialization
{
  //## begin CMCStateInitializing::CMCStateInitializing%.body preserve=yes
  //## end CMCStateInitializing::CMCStateInitializing%.body
}


CMCStateInitializing::~CMCStateInitializing()
{
  //## begin CMCStateInitializing::~CMCStateInitializing%.body preserve=yes
  //## end CMCStateInitializing::~CMCStateInitializing%.body
}



//## Other Operations (implementation)
void CMCStateInitializing::Delete ()
{
  //## begin CMCStateInitializing::Delete%1067518842.body preserve=yes
  delete m_pInstance;
  m_pInstance = NULL;
  //## end CMCStateInitializing::Delete%1067518842.body
}

void CMCStateInitializing::Create ()
{
  //## begin CMCStateInitializing::Create%1067518843.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CMCStateInitializing();
  //## end CMCStateInitializing::Create%1067518843.body
}

CMCStateInitializing* CMCStateInitializing::GetInstance ()
{
  //## begin CMCStateInitializing::GetInstance%1067518844.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CMCStateInitializing::GetInstance%1067518844.body
}

void CMCStateInitializing::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateInitializing::Do%1067518845.body preserve=yes
  if (!GetpContext(p_pContext)->GetbHWPresent())
  {
    GetpContext(p_pContext)->GetpCtrlSimulation()->Initialize();
  }

  p_pContext->ChangeState(CMCStateInitialized::GetInstance());
  //## end CMCStateInitializing::Do%1067518845.body
}

// Additional Declarations
  //## begin CMCStateInitializing%3FA134A4005D.declarations preserve=yes
  //## end CMCStateInitializing%3FA134A4005D.declarations

//## begin module%3E6DD9C10196.epilog preserve=yes
//## end module%3E6DD9C10196.epilog
