//## begin module%3EE6DFEA0177.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE6DFEA0177.cm

//## begin module%3EE6DFEA0177.cp preserve=no
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
//## end module%3EE6DFEA0177.cp

//## Module: EBTCconn%3EE6DFEA0177; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCconn.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE6DFEA0177.additionalIncludes preserve=no
//## end module%3EE6DFEA0177.additionalIncludes

//## begin module%3EE6DFEA0177.includes preserve=yes
//## end module%3EE6DFEA0177.includes

// EBCOimct
#include "EBCOimct.h"
// EBTCconn
#include "EBTCconn.h"
// EBTCconfig
#include "EBTCconfig.h"
// EBTCidle
#include "EBTCidle.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3EE6DFEA0177.declarations preserve=no
//## end module%3EE6DFEA0177.declarations

//## begin module%3EE6DFEA0177.additionalDeclarations preserve=yes
//## end module%3EE6DFEA0177.additionalDeclarations


// Class CTCStateNotConnectedProcess 

//## begin CTCStateNotConnectedProcess::pInstance%3EE6E70F019F.role preserve=no  public: static CTCStateNotConnectedProcess {1..1 -> 1..1RFHN}
CTCStateNotConnectedProcess *CTCStateNotConnectedProcess::m_pInstance = NULL;
//## end CTCStateNotConnectedProcess::pInstance%3EE6E70F019F.role


CTCStateNotConnectedProcess::CTCStateNotConnectedProcess()
  //## begin CTCStateNotConnectedProcess::CTCStateNotConnectedProcess%.hasinit preserve=no
  //## end CTCStateNotConnectedProcess::CTCStateNotConnectedProcess%.hasinit
  //## begin CTCStateNotConnectedProcess::CTCStateNotConnectedProcess%.initialization preserve=yes
  //## end CTCStateNotConnectedProcess::CTCStateNotConnectedProcess%.initialization
{
  //## begin CTCStateNotConnectedProcess::CTCStateNotConnectedProcess%.body preserve=yes
  //## end CTCStateNotConnectedProcess::CTCStateNotConnectedProcess%.body
}


CTCStateNotConnectedProcess::~CTCStateNotConnectedProcess()
{
  //## begin CTCStateNotConnectedProcess::~CTCStateNotConnectedProcess%.body preserve=yes
  //## end CTCStateNotConnectedProcess::~CTCStateNotConnectedProcess%.body
}



//## Other Operations (implementation)
void CTCStateNotConnectedProcess::Create ()
{
  //## begin CTCStateNotConnectedProcess::Create%1055317642.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CTCStateNotConnectedProcess();
  //## end CTCStateNotConnectedProcess::Create%1055317642.body
}

CTCStateNotConnectedProcess* CTCStateNotConnectedProcess::GetInstance ()
{
  //## begin CTCStateNotConnectedProcess::GetInstance%1055317643.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CTCStateNotConnectedProcess::GetInstance%1055317643.body
}

void CTCStateNotConnectedProcess::Delete ()
{
  //## begin CTCStateNotConnectedProcess::Delete%1055317644.body preserve=yes
	if (m_pInstance != NULL)
      delete m_pInstance;

    m_pInstance = NULL;
  //## end CTCStateNotConnectedProcess::Delete%1055317644.body
}

void CTCStateNotConnectedProcess::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateNotConnectedProcess::ConnectionEstablished%1055317654.body preserve=yes
	p_pContext->ChangeState( CTCStateConfigIdle::GetInstance() );
  //## end CTCStateNotConnectedProcess::ConnectionEstablished%1055317654.body
}

void CTCStateNotConnectedProcess::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateNotConnectedProcess::Enter%1183536503.body preserve=yes
	CHIInterface::GetInstance()->DisableWatchdog();
  //## end CTCStateNotConnectedProcess::Enter%1183536503.body
}

// Additional Declarations
  //## begin CTCStateNotConnectedProcess%3EE6E70F0196.declarations preserve=yes
  //## end CTCStateNotConnectedProcess%3EE6E70F0196.declarations

// Class CTCStateNotConnected 

CTCStateNotConnected::CTCStateNotConnected()
  //## begin CTCStateNotConnected::CTCStateNotConnected%.hasinit preserve=no
  //## end CTCStateNotConnected::CTCStateNotConnected%.hasinit
  //## begin CTCStateNotConnected::CTCStateNotConnected%.initialization preserve=yes
  //## end CTCStateNotConnected::CTCStateNotConnected%.initialization
{
  //## begin CTCStateNotConnected::CTCStateNotConnected%.body preserve=yes
  //## end CTCStateNotConnected::CTCStateNotConnected%.body
}


CTCStateNotConnected::~CTCStateNotConnected()
{
  //## begin CTCStateNotConnected::~CTCStateNotConnected%.body preserve=yes
  //## end CTCStateNotConnected::~CTCStateNotConnected%.body
}



//## Other Operations (implementation)
void CTCStateNotConnected::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateNotConnected::Shutdown%1092990419.body preserve=yes
	p_pContext->ChangeState( CTCStateCreated::GetInstance() );
  //## end CTCStateNotConnected::Shutdown%1092990419.body
}

void CTCStateNotConnected::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateNotConnected::CleanupInitialize%1092990420.body preserve=yes
	p_pContext->ChangeState( CTCStateCreated::GetInstance() );
  //## end CTCStateNotConnected::CleanupInitialize%1092990420.body
}

void CTCStateNotConnected::CellUndocked (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateNotConnected::CellUndocked%1216975791.body preserve=yes
	p_pContext->ChangeState( CTCStateCreated::GetInstance() );
  //## end CTCStateNotConnected::CellUndocked%1216975791.body
}

// Additional Declarations
  //## begin CTCStateNotConnected%4125B18C00B8.declarations preserve=yes
  //## end CTCStateNotConnected%4125B18C00B8.declarations

// Class CTCStateNotConnectedConfig 

//## begin CTCStateNotConnectedConfig::pInstance%4125B52E003C.role preserve=no  public: static CTCStateNotConnectedConfig {1..1 -> 1..1RFHN}
CTCStateNotConnectedConfig *CTCStateNotConnectedConfig::m_pInstance;
//## end CTCStateNotConnectedConfig::pInstance%4125B52E003C.role


CTCStateNotConnectedConfig::CTCStateNotConnectedConfig()
  //## begin CTCStateNotConnectedConfig::CTCStateNotConnectedConfig%.hasinit preserve=no
  //## end CTCStateNotConnectedConfig::CTCStateNotConnectedConfig%.hasinit
  //## begin CTCStateNotConnectedConfig::CTCStateNotConnectedConfig%.initialization preserve=yes
  //## end CTCStateNotConnectedConfig::CTCStateNotConnectedConfig%.initialization
{
  //## begin CTCStateNotConnectedConfig::CTCStateNotConnectedConfig%.body preserve=yes
  //## end CTCStateNotConnectedConfig::CTCStateNotConnectedConfig%.body
}


CTCStateNotConnectedConfig::~CTCStateNotConnectedConfig()
{
  //## begin CTCStateNotConnectedConfig::~CTCStateNotConnectedConfig%.body preserve=yes
  //## end CTCStateNotConnectedConfig::~CTCStateNotConnectedConfig%.body
}



//## Other Operations (implementation)
void CTCStateNotConnectedConfig::Create ()
{
  //## begin CTCStateNotConnectedConfig::Create%1092990421.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CTCStateNotConnectedConfig();
  //## end CTCStateNotConnectedConfig::Create%1092990421.body
}

CTCStateNotConnectedConfig* CTCStateNotConnectedConfig::GetInstance ()
{
  //## begin CTCStateNotConnectedConfig::GetInstance%1092990422.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CTCStateNotConnectedConfig::GetInstance%1092990422.body
}

void CTCStateNotConnectedConfig::Delete ()
{
  //## begin CTCStateNotConnectedConfig::Delete%1092990423.body preserve=yes
	if (m_pInstance != NULL)
      delete m_pInstance;

    m_pInstance = NULL;
  //## end CTCStateNotConnectedConfig::Delete%1092990423.body
}

void CTCStateNotConnectedConfig::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateNotConnectedConfig::ConnectionEstablished%1092990424.body preserve=yes
	p_pContext->ChangeState( CTCStateConfigNotSet::GetInstance() );
  //## end CTCStateNotConnectedConfig::ConnectionEstablished%1092990424.body
}

void CTCStateNotConnectedConfig::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateNotConnectedConfig::Enter%1183536504.body preserve=yes
	CHIInterface::GetInstance()->DisableWatchdog();
  //## end CTCStateNotConnectedConfig::Enter%1183536504.body
}

// Additional Declarations
  //## begin CTCStateNotConnectedConfig%4125B1FC03E5.declarations preserve=yes
  //## end CTCStateNotConnectedConfig%4125B1FC03E5.declarations

//## begin module%3EE6DFEA0177.epilog preserve=yes
//## end module%3EE6DFEA0177.epilog
