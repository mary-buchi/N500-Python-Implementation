//## begin module%40980CC1000A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%40980CC1000A.cm

//## begin module%40980CC1000A.cp preserve=no
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
//## end module%40980CC1000A.cp

//## Module: EBSYpstb%40980CC1000A; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYpstb.cpp

// stdafx
#include "stdafx.h"
//## begin module%40980CC1000A.additionalIncludes preserve=no
//## end module%40980CC1000A.additionalIncludes

//## begin module%40980CC1000A.includes preserve=yes
//## end module%40980CC1000A.includes

// EBPIfact
#include "EBPIfact.h"
// EBSYimpl
#include "EBSYimpl.h"
// EBSYcons
#include "EBSYcons.h"
// EBSYidle
#include "EBSYidle.h"
// EBSYrgun
#include "EBSYrgun.h"
// EBSYshdn
#include "EBSYshdn.h"
// EBSYcrea
#include "EBSYcrea.h"
// EBSYpstb
#include "EBSYpstb.h"
//## begin module%40980CC1000A.declarations preserve=no
//## end module%40980CC1000A.declarations

//## begin module%40980CC1000A.additionalDeclarations preserve=yes
#include "..\EBET\EBETflog.h"
//## end module%40980CC1000A.additionalDeclarations


// Class CSYStateProcessStandBy 

CSYStateProcessStandBy::CSYStateProcessStandBy()
  //## begin CSYStateProcessStandBy::CSYStateProcessStandBy%.hasinit preserve=no
  //## end CSYStateProcessStandBy::CSYStateProcessStandBy%.hasinit
  //## begin CSYStateProcessStandBy::CSYStateProcessStandBy%.initialization preserve=yes
  //## end CSYStateProcessStandBy::CSYStateProcessStandBy%.initialization
{
  //## begin CSYStateProcessStandBy::CSYStateProcessStandBy%.body preserve=yes
  //## end CSYStateProcessStandBy::CSYStateProcessStandBy%.body
}


CSYStateProcessStandBy::~CSYStateProcessStandBy()
{
  //## begin CSYStateProcessStandBy::~CSYStateProcessStandBy%.body preserve=yes
  //## end CSYStateProcessStandBy::~CSYStateProcessStandBy%.body
}



//## Other Operations (implementation)
EPIDeviceState CSYStateProcessStandBy::GetDeviceState ()
{
  //## begin CSYStateProcessStandBy::GetDeviceState%1083700317.body preserve=yes
	return eNotConnected;
  //## end CSYStateProcessStandBy::GetDeviceState%1083700317.body
}

void CSYStateProcessStandBy::ResetDevice (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcessStandBy::ResetDevice%1083700318.body preserve=yes
    CSYStateShuttingDown::GetInstance()->SetbRebootSystem(true);
  	p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());
  //## end CSYStateProcessStandBy::ResetDevice%1083700318.body
}

// Additional Declarations
  //## begin CSYStateProcessStandBy%40980BE903AD.declarations preserve=yes
  //## end CSYStateProcessStandBy%40980BE903AD.declarations

// Class CSYStateProcessStandByDisconnecting 

//## begin CSYStateProcessStandByDisconnecting::pInstance%40980D28013F.role preserve=no  public: static CSYStateProcessStandByDisconnecting {1..1 -> 1..1RFHN}
CSYStateProcessStandByDisconnecting *CSYStateProcessStandByDisconnecting::m_pInstance = NULL;
//## end CSYStateProcessStandByDisconnecting::pInstance%40980D28013F.role


CSYStateProcessStandByDisconnecting::CSYStateProcessStandByDisconnecting()
  //## begin CSYStateProcessStandByDisconnecting::CSYStateProcessStandByDisconnecting%.hasinit preserve=no
  //## end CSYStateProcessStandByDisconnecting::CSYStateProcessStandByDisconnecting%.hasinit
  //## begin CSYStateProcessStandByDisconnecting::CSYStateProcessStandByDisconnecting%.initialization preserve=yes
  //## end CSYStateProcessStandByDisconnecting::CSYStateProcessStandByDisconnecting%.initialization
{
  //## begin CSYStateProcessStandByDisconnecting::CSYStateProcessStandByDisconnecting%.body preserve=yes
  //## end CSYStateProcessStandByDisconnecting::CSYStateProcessStandByDisconnecting%.body
}


CSYStateProcessStandByDisconnecting::~CSYStateProcessStandByDisconnecting()
{
  //## begin CSYStateProcessStandByDisconnecting::~CSYStateProcessStandByDisconnecting%.body preserve=yes
  //## end CSYStateProcessStandByDisconnecting::~CSYStateProcessStandByDisconnecting%.body
}



//## Other Operations (implementation)
void CSYStateProcessStandByDisconnecting::Create ()
{
  //## begin CSYStateProcessStandByDisconnecting::Create%1083700302.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSYStateProcessStandByDisconnecting();
  //## end CSYStateProcessStandByDisconnecting::Create%1083700302.body
}

void CSYStateProcessStandByDisconnecting::Delete ()
{
  //## begin CSYStateProcessStandByDisconnecting::Delete%1083700303.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSYStateProcessStandByDisconnecting::Delete%1083700303.body
}

CSYStateProcessStandByDisconnecting* CSYStateProcessStandByDisconnecting::GetInstance ()
{
  //## begin CSYStateProcessStandByDisconnecting::GetInstance%1083700304.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSYStateProcessStandByDisconnecting::GetInstance%1083700304.body
}

void CSYStateProcessStandByDisconnecting::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcessStandByDisconnecting::Do%1083700305.body preserve=yes
    // Send all already connected interfaces the connection lost event
#ifdef DEBUG
	CETFileLogger::GetInstance()->AddMessage(_T("CSYStateProcessStandByDisconnecting::Do"));
#endif
    CPIObjectFactory::GetInstance()->SendCmdConnectionLost();

	p_pContext->ChangeState(CSYStateProcessStandByIdle::GetInstance());
  //## end CSYStateProcessStandByDisconnecting::Do%1083700305.body
}

// Additional Declarations
  //## begin CSYStateProcessStandByDisconnecting%40980C760215.declarations preserve=yes
  //## end CSYStateProcessStandByDisconnecting%40980C760215.declarations

// Class CSYStateProcessStandByIdle 

//## begin CSYStateProcessStandByIdle::pInstance%40980D40025D.role preserve=no  public: static CSYStateProcessStandByIdle {1..1 -> 1..1RFHN}
CSYStateProcessStandByIdle *CSYStateProcessStandByIdle::m_pInstance = NULL;
//## end CSYStateProcessStandByIdle::pInstance%40980D40025D.role


CSYStateProcessStandByIdle::CSYStateProcessStandByIdle()
  //## begin CSYStateProcessStandByIdle::CSYStateProcessStandByIdle%.hasinit preserve=no
  //## end CSYStateProcessStandByIdle::CSYStateProcessStandByIdle%.hasinit
  //## begin CSYStateProcessStandByIdle::CSYStateProcessStandByIdle%.initialization preserve=yes
  //## end CSYStateProcessStandByIdle::CSYStateProcessStandByIdle%.initialization
{
  //## begin CSYStateProcessStandByIdle::CSYStateProcessStandByIdle%.body preserve=yes
  //## end CSYStateProcessStandByIdle::CSYStateProcessStandByIdle%.body
}


CSYStateProcessStandByIdle::~CSYStateProcessStandByIdle()
{
  //## begin CSYStateProcessStandByIdle::~CSYStateProcessStandByIdle%.body preserve=yes
  //## end CSYStateProcessStandByIdle::~CSYStateProcessStandByIdle%.body
}



//## Other Operations (implementation)
void CSYStateProcessStandByIdle::Create ()
{
  //## begin CSYStateProcessStandByIdle::Create%1083700306.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSYStateProcessStandByIdle();
  //## end CSYStateProcessStandByIdle::Create%1083700306.body
}

void CSYStateProcessStandByIdle::Delete ()
{
  //## begin CSYStateProcessStandByIdle::Delete%1083700307.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSYStateProcessStandByIdle::Delete%1083700307.body
}

CSYStateProcessStandByIdle* CSYStateProcessStandByIdle::GetInstance ()
{
  //## begin CSYStateProcessStandByIdle::GetInstance%1083700308.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSYStateProcessStandByIdle::GetInstance%1083700308.body
}

void CSYStateProcessStandByIdle::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcessStandByIdle::ConnectionEstablished%1083700313.body preserve=yes
#ifdef DEBUG
	CETFileLogger::GetInstance()->AddMessage(_T("CSYStateProcessStandByIdle::ConnectionEstablished"));
#endif
	p_pContext->ChangeState(CSYStateProcessStandByConnecting::GetInstance());
  //## end CSYStateProcessStandByIdle::ConnectionEstablished%1083700313.body
}

void CSYStateProcessStandByIdle::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcessStandByIdle::Enter%1083737622.body preserve=yes
#ifdef DEBUG
	CETFileLogger::GetInstance()->AddMessage(_T("CSYStateProcessStandByIdle::Enter"));
#endif
    GetpContext(p_pContext)->ResetClient();
    GetpContext(p_pContext)->StartTimer(GetpContext(p_pContext)->GetuiWarmupTimeout());
  //## end CSYStateProcessStandByIdle::Enter%1083737622.body
}

void CSYStateProcessStandByIdle::Exit (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcessStandByIdle::Exit%1083737623.body preserve=yes
#ifdef DEBUG
	CETFileLogger::GetInstance()->AddMessage(_T("CSYStateProcessStandByIdle::Exit"));
#endif
    GetpContext(p_pContext)->StopTimer();
  //## end CSYStateProcessStandByIdle::Exit%1083737623.body
}

void CSYStateProcessStandByIdle::OnTimer (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcessStandByIdle::OnTimer%1083737624.body preserve=yes
    p_pContext->ChangeState(CSYStateConstitutionUnregisteringUnits::GetInstance());
  //## end CSYStateProcessStandByIdle::OnTimer%1083737624.body
}

// Additional Declarations
  //## begin CSYStateProcessStandByIdle%40980C8702B0.declarations preserve=yes
  //## end CSYStateProcessStandByIdle%40980C8702B0.declarations

// Class CSYStateProcessStandByConnecting 

//## begin CSYStateProcessStandByConnecting::pInstance%40980D55023E.role preserve=no  public: static CSYStateProcessStandByConnecting {1..1 -> 1..1RFHN}
CSYStateProcessStandByConnecting *CSYStateProcessStandByConnecting::m_pInstance = NULL;
//## end CSYStateProcessStandByConnecting::pInstance%40980D55023E.role


CSYStateProcessStandByConnecting::CSYStateProcessStandByConnecting()
  //## begin CSYStateProcessStandByConnecting::CSYStateProcessStandByConnecting%.hasinit preserve=no
  //## end CSYStateProcessStandByConnecting::CSYStateProcessStandByConnecting%.hasinit
  //## begin CSYStateProcessStandByConnecting::CSYStateProcessStandByConnecting%.initialization preserve=yes
  //## end CSYStateProcessStandByConnecting::CSYStateProcessStandByConnecting%.initialization
{
  //## begin CSYStateProcessStandByConnecting::CSYStateProcessStandByConnecting%.body preserve=yes
  //## end CSYStateProcessStandByConnecting::CSYStateProcessStandByConnecting%.body
}


CSYStateProcessStandByConnecting::~CSYStateProcessStandByConnecting()
{
  //## begin CSYStateProcessStandByConnecting::~CSYStateProcessStandByConnecting%.body preserve=yes
  //## end CSYStateProcessStandByConnecting::~CSYStateProcessStandByConnecting%.body
}



//## Other Operations (implementation)
void CSYStateProcessStandByConnecting::Create ()
{
  //## begin CSYStateProcessStandByConnecting::Create%1083700309.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSYStateProcessStandByConnecting();
  //## end CSYStateProcessStandByConnecting::Create%1083700309.body
}

void CSYStateProcessStandByConnecting::Delete ()
{
  //## begin CSYStateProcessStandByConnecting::Delete%1083700310.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSYStateProcessStandByConnecting::Delete%1083700310.body
}

CSYStateProcessStandByConnecting* CSYStateProcessStandByConnecting::GetInstance ()
{
  //## begin CSYStateProcessStandByConnecting::GetInstance%1083700311.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSYStateProcessStandByConnecting::GetInstance%1083700311.body
}

void CSYStateProcessStandByConnecting::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcessStandByConnecting::Do%1083700312.body preserve=yes
    // Send all before already connected interfaces the connection established event
#ifdef DEBUG
	CETFileLogger::GetInstance()->AddMessage(_T("CSYStateProcessStandByConnecting::Do"));
#endif
    CPIObjectFactory::GetInstance()->SendCmdConnectionEstablished();
  	p_pContext->ChangeState(CSYStateProcessIdle::GetInstance());
  //## end CSYStateProcessStandByConnecting::Do%1083700312.body
}

// Additional Declarations
  //## begin CSYStateProcessStandByConnecting%40980C9701C3.declarations preserve=yes
  //## end CSYStateProcessStandByConnecting%40980C9701C3.declarations

//## begin module%40980CC1000A.epilog preserve=yes
//## end module%40980CC1000A.epilog
