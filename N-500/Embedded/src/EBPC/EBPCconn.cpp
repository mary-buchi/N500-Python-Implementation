//## begin module%3EED769F03A1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F03A1.cm

//## begin module%3EED769F03A1.cp preserve=no
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
//## end module%3EED769F03A1.cp

//## Module: EBPCconn%3EED769F03A1; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCconn.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F03A1.additionalIncludes preserve=no
//## end module%3EED769F03A1.additionalIncludes

//## begin module%3EED769F03A1.includes preserve=yes
//## end module%3EED769F03A1.includes

// EBCOimct
#include "EBCOimct.h"
// EBPCconn
#include "EBPCconn.h"
// EBPClogic
#include "EBPClogic.h"
// EBPCconfig
#include "EBPCconfig.h"
// EBPCidle
#include "EBPCidle.h"
// EBPCimpl
#include "EBPCimpl.h"
// EBPCcrea
#include "EBPCcrea.h"
// EBPCident
#include "EBPCident.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3EED769F03A1.declarations preserve=no
//## end module%3EED769F03A1.declarations

//## begin module%3EED769F03A1.additionalDeclarations preserve=yes
//## end module%3EED769F03A1.additionalDeclarations


// Class CPCStateNotConnected 

//## begin CPCStateNotConnected::pInstance%3EED76CC0928.role preserve=no  public: static CPCStateNotConnected {1..1 -> 1..1RFHN}
CPCStateNotConnected *CPCStateNotConnected::m_pInstance;
//## end CPCStateNotConnected::pInstance%3EED76CC0928.role


CPCStateNotConnected::CPCStateNotConnected()
  //## begin CPCStateNotConnected::CPCStateNotConnected%.hasinit preserve=no
  //## end CPCStateNotConnected::CPCStateNotConnected%.hasinit
  //## begin CPCStateNotConnected::CPCStateNotConnected%.initialization preserve=yes
  //## end CPCStateNotConnected::CPCStateNotConnected%.initialization
{
  //## begin CPCStateNotConnected::CPCStateNotConnected%.body preserve=yes
  //## end CPCStateNotConnected::CPCStateNotConnected%.body
}


CPCStateNotConnected::~CPCStateNotConnected()
{
  //## begin CPCStateNotConnected::~CPCStateNotConnected%.body preserve=yes
  //## end CPCStateNotConnected::~CPCStateNotConnected%.body
}



//## Other Operations (implementation)
void CPCStateNotConnected::Create ()
{
  //## begin CPCStateNotConnected::Create%1055317642.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateNotConnected();
  //## end CPCStateNotConnected::Create%1055317642.body
}

CPCStateNotConnected* CPCStateNotConnected::GetInstance ()
{
  //## begin CPCStateNotConnected::GetInstance%1055317643.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateNotConnected::GetInstance%1055317643.body
}

void CPCStateNotConnected::Delete ()
{
  //## begin CPCStateNotConnected::Delete%1055317644.body preserve=yes
	if (m_pInstance != NULL)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPCStateNotConnected::Delete%1055317644.body
}

void CPCStateNotConnected::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateNotConnected::Do%1055317645.body preserve=yes
	GetpImplementation(p_pContext)->GetpLogic()->SetVoltage(CHIInterface::GetInstance()->GetStaticObjID(eHILmpStandByVoltage));
  //## end CPCStateNotConnected::Do%1055317645.body
}

void CPCStateNotConnected::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateNotConnected::Shutdown%1055317655.body preserve=yes
	p_pContext->ChangeState(CPCStateCreated::GetInstance());
  //## end CPCStateNotConnected::Shutdown%1055317655.body
}

void CPCStateNotConnected::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateNotConnected::ConnectionEstablished%1066285475.body preserve=yes
	p_pContext->ChangeState( CPCStateIdleStandBy::GetInstance() );
  //## end CPCStateNotConnected::ConnectionEstablished%1066285475.body
}

// Additional Declarations
  //## begin CPCStateNotConnected%3EED76CC07A4.declarations preserve=yes
  //## end CPCStateNotConnected%3EED76CC07A4.declarations

// Class CPCStateNotConnectedNoConfig 

//## begin CPCStateNotConnectedNoConfig::pInstance%4106141D0003.role preserve=no  public: static CPCStateNotConnectedNoConfig {1..1 -> 1..1RFHN}
CPCStateNotConnectedNoConfig *CPCStateNotConnectedNoConfig::m_pInstance;
//## end CPCStateNotConnectedNoConfig::pInstance%4106141D0003.role


CPCStateNotConnectedNoConfig::CPCStateNotConnectedNoConfig()
  //## begin CPCStateNotConnectedNoConfig::CPCStateNotConnectedNoConfig%.hasinit preserve=no
  //## end CPCStateNotConnectedNoConfig::CPCStateNotConnectedNoConfig%.hasinit
  //## begin CPCStateNotConnectedNoConfig::CPCStateNotConnectedNoConfig%.initialization preserve=yes
  //## end CPCStateNotConnectedNoConfig::CPCStateNotConnectedNoConfig%.initialization
{
  //## begin CPCStateNotConnectedNoConfig::CPCStateNotConnectedNoConfig%.body preserve=yes
  //## end CPCStateNotConnectedNoConfig::CPCStateNotConnectedNoConfig%.body
}


CPCStateNotConnectedNoConfig::~CPCStateNotConnectedNoConfig()
{
  //## begin CPCStateNotConnectedNoConfig::~CPCStateNotConnectedNoConfig%.body preserve=yes
  //## end CPCStateNotConnectedNoConfig::~CPCStateNotConnectedNoConfig%.body
}



//## Other Operations (implementation)
void CPCStateNotConnectedNoConfig::Create ()
{
  //## begin CPCStateNotConnectedNoConfig::Create%1090917496.body preserve=yes
 	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateNotConnectedNoConfig();
  //## end CPCStateNotConnectedNoConfig::Create%1090917496.body
}

CPCStateNotConnectedNoConfig* CPCStateNotConnectedNoConfig::GetInstance ()
{
  //## begin CPCStateNotConnectedNoConfig::GetInstance%1090917497.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateNotConnectedNoConfig::GetInstance%1090917497.body
}

void CPCStateNotConnectedNoConfig::Delete ()
{
  //## begin CPCStateNotConnectedNoConfig::Delete%1090917498.body preserve=yes
	if (m_pInstance != NULL)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPCStateNotConnectedNoConfig::Delete%1090917498.body
}

void CPCStateNotConnectedNoConfig::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateNotConnectedNoConfig::Do%1090917499.body preserve=yes
  //## end CPCStateNotConnectedNoConfig::Do%1090917499.body
}

void CPCStateNotConnectedNoConfig::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateNotConnectedNoConfig::Shutdown%1090917500.body preserve=yes
    p_pContext->ChangeState( CPCStateCreated::GetInstance() );
  //## end CPCStateNotConnectedNoConfig::Shutdown%1090917500.body
}

void CPCStateNotConnectedNoConfig::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateNotConnectedNoConfig::ConnectionEstablished%1090917501.body preserve=yes
    p_pContext->ChangeState( CPCStateConfigNotSet::GetInstance() );
  //## end CPCStateNotConnectedNoConfig::ConnectionEstablished%1090917501.body
}

// Additional Declarations
  //## begin CPCStateNotConnectedNoConfig%410613A80267.declarations preserve=yes
  //## end CPCStateNotConnectedNoConfig%410613A80267.declarations

//## begin module%3EED769F03A1.epilog preserve=yes
//## end module%3EED769F03A1.epilog
