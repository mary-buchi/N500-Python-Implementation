//## begin module%3F93ABF90333.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F93ABF90333.cm

//## begin module%3F93ABF90333.cp preserve=no
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
//## end module%3F93ABF90333.cp

//## Module: EBPOnotc%3F93ABF90333; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOnotc.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F93ABF90333.additionalIncludes preserve=no
//## end module%3F93ABF90333.additionalIncludes

//## begin module%3F93ABF90333.includes preserve=yes
//## end module%3F93ABF90333.includes

// EBPItias
#include "EBPItias.h"
// EBPOshdn
#include "EBPOshdn.h"
// EBPOcounter
#include "EBPOcounter.h"
// EBPOnotc
#include "EBPOnotc.h"
// EBPOidle
#include "EBPOidle.h"
//## begin module%3F93ABF90333.declarations preserve=no
//## end module%3F93ABF90333.declarations

//## begin module%3F93ABF90333.additionalDeclarations preserve=yes
//## end module%3F93ABF90333.additionalDeclarations


// Class CPOStateNotConnected 

//## begin CPOStateNotConnected::pInstance%3F97CD7500F3.role preserve=no  public: static CPOStateNotConnected {1..1 -> 1..1RFHN}
CPOStateNotConnected *CPOStateNotConnected::m_pInstance;
//## end CPOStateNotConnected::pInstance%3F97CD7500F3.role


CPOStateNotConnected::CPOStateNotConnected()
  //## begin CPOStateNotConnected::CPOStateNotConnected%.hasinit preserve=no
  //## end CPOStateNotConnected::CPOStateNotConnected%.hasinit
  //## begin CPOStateNotConnected::CPOStateNotConnected%.initialization preserve=yes
  //## end CPOStateNotConnected::CPOStateNotConnected%.initialization
{
  //## begin CPOStateNotConnected::CPOStateNotConnected%.body preserve=yes
  //## end CPOStateNotConnected::CPOStateNotConnected%.body
}


CPOStateNotConnected::~CPOStateNotConnected()
{
  //## begin CPOStateNotConnected::~CPOStateNotConnected%.body preserve=yes
  //## end CPOStateNotConnected::~CPOStateNotConnected%.body
}



//## Other Operations (implementation)
void CPOStateNotConnected::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateNotConnected::Shutdown%1066888972.body preserve=yes
	p_pContext->ChangeState(CPOStateShuttingDown::GetInstance());
  //## end CPOStateNotConnected::Shutdown%1066888972.body
}

void CPOStateNotConnected::Create ()
{
  //## begin CPOStateNotConnected::Create%1066889000.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPOStateNotConnected();
  //## end CPOStateNotConnected::Create%1066889000.body
}

void CPOStateNotConnected::Delete ()
{
  //## begin CPOStateNotConnected::Delete%1066889001.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPOStateNotConnected::Delete%1066889001.body
}

CPOStateNotConnected * CPOStateNotConnected::GetInstance ()
{
  //## begin CPOStateNotConnected::GetInstance%1066889002.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPOStateNotConnected::GetInstance%1066889002.body
}

void CPOStateNotConnected::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateNotConnected::ConnectionEstablished%1067251212.body preserve=yes
	DWORD l_dwTimerInterval = GetpImpl(p_pContext)->GetpConfig()->GetdwTimerInterval();
	l_dwTimerInterval *= 1000;

	GetpImpl(p_pContext)->StartTimer(l_dwTimerInterval);
	p_pContext->ChangeState(CPOStateIdle::GetInstance());
  //## end CPOStateNotConnected::ConnectionEstablished%1067251212.body
}

void CPOStateNotConnected::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateNotConnected::Do%1079681378.body preserve=yes
	CPOLifeTimeCounterHandler *l_pLifetime = NULL;
	l_pLifetime = GetpImpl(p_pContext)->GetpLifeTimeCounterHandler();
	l_pLifetime->SetdwTicksAtConnLost(GetTickCount());

	GetpImpl(p_pContext)->StopTimer();
  //## end CPOStateNotConnected::Do%1079681378.body
}

// Additional Declarations
  //## begin CPOStateNotConnected%3F93AEF40258.declarations preserve=yes
  //## end CPOStateNotConnected%3F93AEF40258.declarations

//## begin module%3F93ABF90333.epilog preserve=yes
//## end module%3F93ABF90333.epilog
