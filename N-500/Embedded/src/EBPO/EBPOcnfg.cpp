//## begin module%3F93A8D202E5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F93A8D202E5.cm

//## begin module%3F93A8D202E5.cp preserve=no
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
//## end module%3F93A8D202E5.cp

//## Module: EBPOcnfg%3F93A8D202E5; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOcnfg.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F93A8D202E5.additionalIncludes preserve=no
//## end module%3F93A8D202E5.additionalIncludes

//## begin module%3F93A8D202E5.includes preserve=yes
//## end module%3F93A8D202E5.includes

// EBPOeprom
#include "EBPOeprom.h"
// EBPOcounter
#include "EBPOcounter.h"
// EBPOlogic
#include "EBPOlogic.h"
// EBPOnotc
#include "EBPOnotc.h"
// EBPOcnfg
#include "EBPOcnfg.h"
// EBPOidle
#include "EBPOidle.h"
//## begin module%3F93A8D202E5.declarations preserve=no
//## end module%3F93A8D202E5.declarations

//## begin module%3F93A8D202E5.additionalDeclarations preserve=yes
//## end module%3F93A8D202E5.additionalDeclarations


// Class CPOStateConfig 

CPOStateConfig::CPOStateConfig()
  //## begin CPOStateConfig::CPOStateConfig%.hasinit preserve=no
  //## end CPOStateConfig::CPOStateConfig%.hasinit
  //## begin CPOStateConfig::CPOStateConfig%.initialization preserve=yes
  //## end CPOStateConfig::CPOStateConfig%.initialization
{
  //## begin CPOStateConfig::CPOStateConfig%.body preserve=yes
  //## end CPOStateConfig::CPOStateConfig%.body
}


CPOStateConfig::~CPOStateConfig()
{
  //## begin CPOStateConfig::~CPOStateConfig%.body preserve=yes
  //## end CPOStateConfig::~CPOStateConfig%.body
}



//## Other Operations (implementation)
void CPOStateConfig::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateConfig::Startup%1067238812.body preserve=yes
	p_pContext->ChangeState(CPOStateConfigStart::GetInstance());
  //## end CPOStateConfig::Startup%1067238812.body
}

void CPOStateConfig::SetConfig (ICOStateMachineContext* p_pContext, CPIPersistentConfig* p_pConfig)
{
  //## begin CPOStateConfig::SetConfig%1067238813.body preserve=yes

	GetpImpl(p_pContext)->SetpConfig(p_pConfig);
	GetpImpl(p_pContext)->GetpLogic()->SetConfig();

	p_pContext->ChangeState(CPOStateConfigAssigned::GetInstance());
  //## end CPOStateConfig::SetConfig%1067238813.body
}

void CPOStateConfig::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateConfig::CleanupInitialize%1067238814.body preserve=yes
	p_pContext->ChangeState(CPOStateConfigStart::GetInstance());
  //## end CPOStateConfig::CleanupInitialize%1067238814.body
}

void CPOStateConfig::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateConfig::ConnectionLost%1067243913.body preserve=yes
	p_pContext->ChangeState(CPOStateNotConnected::GetInstance());
  //## end CPOStateConfig::ConnectionLost%1067243913.body
}

void CPOStateConfig::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateConfig::Shutdown%1067262118.body preserve=yes
	p_pContext->ChangeState(CPOStateCreated::GetInstance());
  //## end CPOStateConfig::Shutdown%1067262118.body
}

// Additional Declarations
  //## begin CPOStateConfig%3F93AD120120.declarations preserve=yes
  //## end CPOStateConfig%3F93AD120120.declarations

// Class CPOStateConfigStart 

//## begin CPOStateConfigStart::pInstance%3F97CD8B00D3.role preserve=no  public: static CPOStateConfigStart {1..1 -> 1..1RFHN}
CPOStateConfigStart *CPOStateConfigStart::m_pInstance;
//## end CPOStateConfigStart::pInstance%3F97CD8B00D3.role


CPOStateConfigStart::CPOStateConfigStart()
  //## begin CPOStateConfigStart::CPOStateConfigStart%.hasinit preserve=no
  //## end CPOStateConfigStart::CPOStateConfigStart%.hasinit
  //## begin CPOStateConfigStart::CPOStateConfigStart%.initialization preserve=yes
  //## end CPOStateConfigStart::CPOStateConfigStart%.initialization
{
  //## begin CPOStateConfigStart::CPOStateConfigStart%.body preserve=yes
  //## end CPOStateConfigStart::CPOStateConfigStart%.body
}


CPOStateConfigStart::~CPOStateConfigStart()
{
  //## begin CPOStateConfigStart::~CPOStateConfigStart%.body preserve=yes
  //## end CPOStateConfigStart::~CPOStateConfigStart%.body
}



//## Other Operations (implementation)
void CPOStateConfigStart::Create ()
{
  //## begin CPOStateConfigStart::Create%1066888991.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPOStateConfigStart();
  //## end CPOStateConfigStart::Create%1066888991.body
}

void CPOStateConfigStart::Delete ()
{
  //## begin CPOStateConfigStart::Delete%1066888992.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPOStateConfigStart::Delete%1066888992.body
}

CPOStateConfigStart* CPOStateConfigStart::GetInstance ()
{
  //## begin CPOStateConfigStart::GetInstance%1066888993.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPOStateConfigStart::GetInstance%1066888993.body
}

void CPOStateConfigStart::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateConfigStart::Do%1067238815.body preserve=yes
  //## end CPOStateConfigStart::Do%1067238815.body
}

// Additional Declarations
  //## begin CPOStateConfigStart%3F93AD2F0074.declarations preserve=yes
  //## end CPOStateConfigStart%3F93AD2F0074.declarations

// Class CPOStateConfigAssigned 

//## begin CPOStateConfigAssigned::pInstance%3F97CD8E0066.role preserve=no  public: static CPOStateConfigAssigned {1..1 -> 1..1RFHN}
CPOStateConfigAssigned *CPOStateConfigAssigned::m_pInstance;
//## end CPOStateConfigAssigned::pInstance%3F97CD8E0066.role


CPOStateConfigAssigned::CPOStateConfigAssigned()
  //## begin CPOStateConfigAssigned::CPOStateConfigAssigned%.hasinit preserve=no
  //## end CPOStateConfigAssigned::CPOStateConfigAssigned%.hasinit
  //## begin CPOStateConfigAssigned::CPOStateConfigAssigned%.initialization preserve=yes
  //## end CPOStateConfigAssigned::CPOStateConfigAssigned%.initialization
{
  //## begin CPOStateConfigAssigned::CPOStateConfigAssigned%.body preserve=yes
  //## end CPOStateConfigAssigned::CPOStateConfigAssigned%.body
}


CPOStateConfigAssigned::~CPOStateConfigAssigned()
{
  //## begin CPOStateConfigAssigned::~CPOStateConfigAssigned%.body preserve=yes
  //## end CPOStateConfigAssigned::~CPOStateConfigAssigned%.body
}



//## Other Operations (implementation)
void CPOStateConfigAssigned::Create ()
{
  //## begin CPOStateConfigAssigned::Create%1066888994.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPOStateConfigAssigned();
  //## end CPOStateConfigAssigned::Create%1066888994.body
}

void CPOStateConfigAssigned::Delete ()
{
  //## begin CPOStateConfigAssigned::Delete%1066888995.body preserve=yes
	if( m_pInstance )
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPOStateConfigAssigned::Delete%1066888995.body
}

CPOStateConfigAssigned * CPOStateConfigAssigned::GetInstance ()
{
  //## begin CPOStateConfigAssigned::GetInstance%1066888996.body preserve=yes
	ASSERT( m_pInstance != NULL );
    return m_pInstance;
  //## end CPOStateConfigAssigned::GetInstance%1066888996.body
}

void CPOStateConfigAssigned::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateConfigAssigned::Do%1067238816.body preserve=yes
	p_pContext->ChangeState(CPOStateIdle::GetInstance());
  //## end CPOStateConfigAssigned::Do%1067238816.body
}

// Additional Declarations
  //## begin CPOStateConfigAssigned%3F93AD8501FB.declarations preserve=yes
  //## end CPOStateConfigAssigned%3F93AD8501FB.declarations

//## begin module%3F93A8D202E5.epilog preserve=yes
//## end module%3F93A8D202E5.epilog
