//## begin module%3E71A74A028F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E71A74A028F.cm

//## begin module%3E71A74A028F.cp preserve=no
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
//## end module%3E71A74A028F.cp

//## Module: EBSTconfig%3E71A74A028F; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTconfig.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E71A74A028F.additionalIncludes preserve=no
//## end module%3E71A74A028F.additionalIncludes

//## begin module%3E71A74A028F.includes preserve=yes
//## end module%3E71A74A028F.includes

// EBCOimct
#include "EBCOimct.h"
// EBPItype
#include "EBPItype.h"
// EBSTlogic
#include "EBSTlogic.h"
// EBSTconfig
#include "EBSTconfig.h"
// EBSTidle
#include "EBSTidle.h"
// EBSTidnt
#include "EBSTidnt.h"
// EBSTimpl
#include "EBSTimpl.h"
// EBSThwconn
#include "EBSThwconn.h"
//## begin module%3E71A74A028F.declarations preserve=no
//## end module%3E71A74A028F.declarations

//## begin module%3E71A74A028F.additionalDeclarations preserve=yes
//## end module%3E71A74A028F.additionalDeclarations


// Class CSTStateConfigStart 

//## begin CSTStateConfigStart::pInstance%3E75C8A60208.role preserve=no  public: static CSTStateConfigStart {1..1 -> 1..1RFHN}
CSTStateConfigStart *CSTStateConfigStart::m_pInstance = NULL;
//## end CSTStateConfigStart::pInstance%3E75C8A60208.role


CSTStateConfigStart::CSTStateConfigStart()
  //## begin CSTStateConfigStart::CSTStateConfigStart%.hasinit preserve=no
  //## end CSTStateConfigStart::CSTStateConfigStart%.hasinit
  //## begin CSTStateConfigStart::CSTStateConfigStart%.initialization preserve=yes
  //## end CSTStateConfigStart::CSTStateConfigStart%.initialization
{
  //## begin CSTStateConfigStart::CSTStateConfigStart%.body preserve=yes
  //## end CSTStateConfigStart::CSTStateConfigStart%.body
}


CSTStateConfigStart::~CSTStateConfigStart()
{
  //## begin CSTStateConfigStart::~CSTStateConfigStart%.body preserve=yes
  //## end CSTStateConfigStart::~CSTStateConfigStart%.body
}



//## Other Operations (implementation)
void CSTStateConfigStart::Create ()
{
  //## begin CSTStateConfigStart::Create%1047892464.body preserve=yes
    m_pInstance = new CSTStateConfigStart();
  //## end CSTStateConfigStart::Create%1047892464.body
}

void CSTStateConfigStart::Delete ()
{
  //## begin CSTStateConfigStart::Delete%1047892465.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CSTStateConfigStart::Delete%1047892465.body
}

CSTStateConfigStart* CSTStateConfigStart::GetInstance ()
{
  //## begin CSTStateConfigStart::GetInstance%1047892466.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateConfigStart::GetInstance%1047892466.body
}

// Additional Declarations
  //## begin CSTStateConfigStart%3E71A141028F.declarations preserve=yes
  //## end CSTStateConfigStart%3E71A141028F.declarations

// Class CSTStateConfigConfigSet 

//## begin CSTStateConfigConfigSet::pInstance%3E75C8AD00E0.role preserve=no  public: static CSTStateConfigConfigSet {1..1 -> 1..1RFHN}
CSTStateConfigConfigSet *CSTStateConfigConfigSet::m_pInstance = NULL;
//## end CSTStateConfigConfigSet::pInstance%3E75C8AD00E0.role


CSTStateConfigConfigSet::CSTStateConfigConfigSet()
  //## begin CSTStateConfigConfigSet::CSTStateConfigConfigSet%.hasinit preserve=no
  //## end CSTStateConfigConfigSet::CSTStateConfigConfigSet%.hasinit
  //## begin CSTStateConfigConfigSet::CSTStateConfigConfigSet%.initialization preserve=yes
  //## end CSTStateConfigConfigSet::CSTStateConfigConfigSet%.initialization
{
  //## begin CSTStateConfigConfigSet::CSTStateConfigConfigSet%.body preserve=yes
  //## end CSTStateConfigConfigSet::CSTStateConfigConfigSet%.body
}


CSTStateConfigConfigSet::~CSTStateConfigConfigSet()
{
  //## begin CSTStateConfigConfigSet::~CSTStateConfigConfigSet%.body preserve=yes
  //## end CSTStateConfigConfigSet::~CSTStateConfigConfigSet%.body
}



//## Other Operations (implementation)
void CSTStateConfigConfigSet::Create ()
{
  //## begin CSTStateConfigConfigSet::Create%1047892467.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSTStateConfigConfigSet();
  //## end CSTStateConfigConfigSet::Create%1047892467.body
}

void CSTStateConfigConfigSet::Delete ()
{
  //## begin CSTStateConfigConfigSet::Delete%1047892468.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CSTStateConfigConfigSet::Delete%1047892468.body
}

CSTStateConfigConfigSet* CSTStateConfigConfigSet::GetInstance ()
{
  //## begin CSTStateConfigConfigSet::GetInstance%1047892469.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateConfigConfigSet::GetInstance%1047892469.body
}

void CSTStateConfigConfigSet::SetProfile (ICOStateMachineContext* p_pContext, CPIStepperMotorProfile* p_pProfile)
{
  //## begin CSTStateConfigConfigSet::SetProfile%1047904788.body preserve=yes
	
	//1. Get implementation pointer. 2. Write new profile.
	GetpContext(p_pContext)->SetpProfile(p_pProfile);
	ASSERT(p_pProfile != NULL);

	// Reset speedrate to 100%
	GetpContext(p_pContext)->GetpLogic()->AjustActualSpeed(100);

	p_pContext->ChangeState(CSTStateConfigProfileSet::GetInstance());
  //## end CSTStateConfigConfigSet::SetProfile%1047904788.body
}

void CSTStateConfigConfigSet::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateConfigConfigSet::Do%1066295286.body preserve=yes
  //## end CSTStateConfigConfigSet::Do%1066295286.body
}

// Additional Declarations
  //## begin CSTStateConfigConfigSet%3E71A1AF02BE.declarations preserve=yes
  //## end CSTStateConfigConfigSet%3E71A1AF02BE.declarations

// Class CSTStateConfigProfileSet 

//## begin CSTStateConfigProfileSet::pInstance%3E75C8B001BB.role preserve=no  public: static CSTStateConfigProfileSet {1..1 -> 1..1RFHN}
CSTStateConfigProfileSet *CSTStateConfigProfileSet::m_pInstance = NULL;
//## end CSTStateConfigProfileSet::pInstance%3E75C8B001BB.role


CSTStateConfigProfileSet::CSTStateConfigProfileSet()
  //## begin CSTStateConfigProfileSet::CSTStateConfigProfileSet%.hasinit preserve=no
  //## end CSTStateConfigProfileSet::CSTStateConfigProfileSet%.hasinit
  //## begin CSTStateConfigProfileSet::CSTStateConfigProfileSet%.initialization preserve=yes
  //## end CSTStateConfigProfileSet::CSTStateConfigProfileSet%.initialization
{
  //## begin CSTStateConfigProfileSet::CSTStateConfigProfileSet%.body preserve=yes
  //## end CSTStateConfigProfileSet::CSTStateConfigProfileSet%.body
}


CSTStateConfigProfileSet::~CSTStateConfigProfileSet()
{
  //## begin CSTStateConfigProfileSet::~CSTStateConfigProfileSet%.body preserve=yes
  //## end CSTStateConfigProfileSet::~CSTStateConfigProfileSet%.body
}



//## Other Operations (implementation)
void CSTStateConfigProfileSet::Create ()
{
  //## begin CSTStateConfigProfileSet::Create%1047892470.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSTStateConfigProfileSet();
  //## end CSTStateConfigProfileSet::Create%1047892470.body
}

void CSTStateConfigProfileSet::Delete ()
{
  //## begin CSTStateConfigProfileSet::Delete%1047892471.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CSTStateConfigProfileSet::Delete%1047892471.body
}

CSTStateConfigProfileSet* CSTStateConfigProfileSet::GetInstance ()
{
  //## begin CSTStateConfigProfileSet::GetInstance%1047892472.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateConfigProfileSet::GetInstance%1047892472.body
}

void CSTStateConfigProfileSet::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateConfigProfileSet::Do%1047971049.body preserve=yes
	// Auto transition to next state.
	p_pContext->ChangeState(CSTStateIdle::GetInstance());
  //## end CSTStateConfigProfileSet::Do%1047971049.body
}

// Additional Declarations
  //## begin CSTStateConfigProfileSet%3E71A1B20241.declarations preserve=yes
  //## end CSTStateConfigProfileSet%3E71A1B20241.declarations

// Class CSTStateConfig 

CSTStateConfig::CSTStateConfig()
  //## begin CSTStateConfig::CSTStateConfig%.hasinit preserve=no
  //## end CSTStateConfig::CSTStateConfig%.hasinit
  //## begin CSTStateConfig::CSTStateConfig%.initialization preserve=yes
  //## end CSTStateConfig::CSTStateConfig%.initialization
{
  //## begin CSTStateConfig::CSTStateConfig%.body preserve=yes
  //## end CSTStateConfig::CSTStateConfig%.body
}


CSTStateConfig::~CSTStateConfig()
{
  //## begin CSTStateConfig::~CSTStateConfig%.body preserve=yes
  //## end CSTStateConfig::~CSTStateConfig%.body
}



//## Other Operations (implementation)
void CSTStateConfig::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateConfig::Shutdown%1047892473.body preserve=yes
	p_pContext->ChangeState(CSTStateCreated::GetInstance());
  //## end CSTStateConfig::Shutdown%1047892473.body
}

void CSTStateConfig::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateConfig::CleanupInitialize%1053438555.body preserve=yes
	p_pContext->ChangeState(CSTStateCreated::GetInstance());
  //## end CSTStateConfig::CleanupInitialize%1053438555.body
}

void CSTStateConfig::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateConfig::ConnectionLost%1055428401.body preserve=yes
	p_pContext->ChangeState(CSTStateCreated::GetInstance());
  //## end CSTStateConfig::ConnectionLost%1055428401.body
}

void CSTStateConfig::SetConfig (ICOStateMachineContext* p_pContext, CPIStepperMotorConfig* p_pConfig)
{
  //## begin CSTStateConfig::SetConfig%1064473096.body preserve=yes
	GetpContext(p_pContext)->SetpConfig(p_pConfig);
 	p_pContext->ChangeState(CSTStateConfigConfigSet::GetInstance());
  //## end CSTStateConfig::SetConfig%1064473096.body
}

// Additional Declarations
  //## begin CSTStateConfig%3E719E9F03A9.declarations preserve=yes
  //## end CSTStateConfig%3E719E9F03A9.declarations

//## begin module%3E71A74A028F.epilog preserve=yes
//## end module%3E71A74A028F.epilog
