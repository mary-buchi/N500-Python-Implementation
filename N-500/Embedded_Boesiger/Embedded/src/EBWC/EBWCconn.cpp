//## begin module%3F6017BE00EA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F6017BE00EA.cm

//## begin module%3F6017BE00EA.cp preserve=no
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
//## end module%3F6017BE00EA.cp

//## Module: EBWCconn%3F6017BE00EA; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCconn.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F6017BE00EA.additionalIncludes preserve=no
//## end module%3F6017BE00EA.additionalIncludes

//## begin module%3F6017BE00EA.includes preserve=yes
//## end module%3F6017BE00EA.includes

// EBCOimct
#include "EBCOimct.h"
// EBWCconn
#include "EBWCconn.h"
// EBWCinit
#include "EBWCinit.h"
// EBWCconf
#include "EBWCconf.h"
// EBWCidle
#include "EBWCidle.h"
// EBWCidnt
#include "EBWCidnt.h"
//## begin module%3F6017BE00EA.declarations preserve=no
//## end module%3F6017BE00EA.declarations

//## begin module%3F6017BE00EA.additionalDeclarations preserve=yes
//## end module%3F6017BE00EA.additionalDeclarations


// Class CWCStateNotConnected 

//## begin CWCStateNotConnected::pInstance%3F6018350187.role preserve=no  public: static CWCStateNotConnected {1..1 -> 1..1RFHN}
CWCStateNotConnected *CWCStateNotConnected::m_pInstance;
//## end CWCStateNotConnected::pInstance%3F6018350187.role


CWCStateNotConnected::CWCStateNotConnected()
  //## begin CWCStateNotConnected::CWCStateNotConnected%.hasinit preserve=no
  //## end CWCStateNotConnected::CWCStateNotConnected%.hasinit
  //## begin CWCStateNotConnected::CWCStateNotConnected%.initialization preserve=yes
  //## end CWCStateNotConnected::CWCStateNotConnected%.initialization
{
  //## begin CWCStateNotConnected::CWCStateNotConnected%.body preserve=yes
  //## end CWCStateNotConnected::CWCStateNotConnected%.body
}


CWCStateNotConnected::~CWCStateNotConnected()
{
  //## begin CWCStateNotConnected::~CWCStateNotConnected%.body preserve=yes
  //## end CWCStateNotConnected::~CWCStateNotConnected%.body
}



//## Other Operations (implementation)
void CWCStateNotConnected::Create ()
{
  //## begin CWCStateNotConnected::Create%1063260189.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CWCStateNotConnected();
  //## end CWCStateNotConnected::Create%1063260189.body
}

CWCStateNotConnected* CWCStateNotConnected::GetInstance ()
{
  //## begin CWCStateNotConnected::GetInstance%1063260190.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CWCStateNotConnected::GetInstance%1063260190.body
}

void CWCStateNotConnected::Delete ()
{
  //## begin CWCStateNotConnected::Delete%1063260191.body preserve=yes
    if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CWCStateNotConnected::Delete%1063260191.body
}

void CWCStateNotConnected::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateNotConnected::ConnectionEstablished%1063260193.body preserve=yes
  p_pContext->ChangeState(CWCStateConfigInitDAC::GetInstance(), p_pContext->GetAction(IDA_INITIALIZE));
  //## end CWCStateNotConnected::ConnectionEstablished%1063260193.body
}

void CWCStateNotConnected::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateNotConnected::Shutdown%1063260194.body preserve=yes
    CWCStateConfig::SetbWCProfileExist(FALSE);
    CWCStateInitialize::SetbWCInitialized(FALSE);
	CWCStateConfig::SetpConfig(NULL);
	CWCStateConfigProfile::GetInstance()->SetpProfile(NULL);
	p_pContext->ChangeState(CWCStateCreated::GetInstance());
  //## end CWCStateNotConnected::Shutdown%1063260194.body
}

// Additional Declarations
  //## begin CWCStateNotConnected%3F6017910242.declarations preserve=yes
  //## end CWCStateNotConnected%3F6017910242.declarations

// Class CWCStateNotConnectedDuringConfig 

//## begin CWCStateNotConnectedDuringConfig::pInstance%3FCB33210233.role preserve=no  public: static CWCStateNotConnectedDuringConfig {1..1 -> 1..1RFHN}
CWCStateNotConnectedDuringConfig *CWCStateNotConnectedDuringConfig::m_pInstance;
//## end CWCStateNotConnectedDuringConfig::pInstance%3FCB33210233.role


CWCStateNotConnectedDuringConfig::CWCStateNotConnectedDuringConfig()
  //## begin CWCStateNotConnectedDuringConfig::CWCStateNotConnectedDuringConfig%.hasinit preserve=no
  //## end CWCStateNotConnectedDuringConfig::CWCStateNotConnectedDuringConfig%.hasinit
  //## begin CWCStateNotConnectedDuringConfig::CWCStateNotConnectedDuringConfig%.initialization preserve=yes
  //## end CWCStateNotConnectedDuringConfig::CWCStateNotConnectedDuringConfig%.initialization
{
  //## begin CWCStateNotConnectedDuringConfig::CWCStateNotConnectedDuringConfig%.body preserve=yes
  //## end CWCStateNotConnectedDuringConfig::CWCStateNotConnectedDuringConfig%.body
}


CWCStateNotConnectedDuringConfig::~CWCStateNotConnectedDuringConfig()
{
  //## begin CWCStateNotConnectedDuringConfig::~CWCStateNotConnectedDuringConfig%.body preserve=yes
  //## end CWCStateNotConnectedDuringConfig::~CWCStateNotConnectedDuringConfig%.body
}



//## Other Operations (implementation)
void CWCStateNotConnectedDuringConfig::Create ()
{
  //## begin CWCStateNotConnectedDuringConfig::Create%1070263829.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CWCStateNotConnectedDuringConfig();
  //## end CWCStateNotConnectedDuringConfig::Create%1070263829.body
}

CWCStateNotConnectedDuringConfig* CWCStateNotConnectedDuringConfig::GetInstance ()
{
  //## begin CWCStateNotConnectedDuringConfig::GetInstance%1070263830.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CWCStateNotConnectedDuringConfig::GetInstance%1070263830.body
}

void CWCStateNotConnectedDuringConfig::Delete ()
{
  //## begin CWCStateNotConnectedDuringConfig::Delete%1070263831.body preserve=yes
  if(m_pInstance)
    delete m_pInstance;
  m_pInstance = NULL;
  //## end CWCStateNotConnectedDuringConfig::Delete%1070263831.body
}

void CWCStateNotConnectedDuringConfig::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateNotConnectedDuringConfig::ConnectionEstablished%1070263832.body preserve=yes
  p_pContext->ChangeState(CWCStateConfigNotAssign::GetInstance());
  //## end CWCStateNotConnectedDuringConfig::ConnectionEstablished%1070263832.body
}

void CWCStateNotConnectedDuringConfig::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateNotConnectedDuringConfig::Shutdown%1070263833.body preserve=yes
	p_pContext->ChangeState(CWCStateCreated::GetInstance());
  //## end CWCStateNotConnectedDuringConfig::Shutdown%1070263833.body
}

// Additional Declarations
  //## begin CWCStateNotConnectedDuringConfig%3FCB31E80232.declarations preserve=yes
  //## end CWCStateNotConnectedDuringConfig%3FCB31E80232.declarations

//## begin module%3F6017BE00EA.epilog preserve=yes
//## end module%3F6017BE00EA.epilog
