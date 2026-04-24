//## begin module%3FA609E700CB.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FA609E700CB.cm

//## begin module%3FA609E700CB.cp preserve=no
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
//## end module%3FA609E700CB.cp

//## Module: EBPOshdn%3FA609E700CB; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOshdn.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FA609E700CB.additionalIncludes preserve=no
//## end module%3FA609E700CB.additionalIncludes

//## begin module%3FA609E700CB.includes preserve=yes
//## end module%3FA609E700CB.includes

// EBPOshdn
#include "EBPOshdn.h"
// EBPOeprom
#include "EBPOeprom.h"
// EBPOcounter
#include "EBPOcounter.h"
// EBPOlogic
#include "EBPOlogic.h"
//## begin module%3FA609E700CB.declarations preserve=no
//## end module%3FA609E700CB.declarations

//## begin module%3FA609E700CB.additionalDeclarations preserve=yes
//## end module%3FA609E700CB.additionalDeclarations


// Class CPOStateShuttingDown 

//## begin CPOStateShuttingDown::pInstance%3F97CD780354.role preserve=no  public: static CPOStateShuttingDown {1..1 -> 1..1RFHN}
CPOStateShuttingDown *CPOStateShuttingDown::m_pInstance;
//## end CPOStateShuttingDown::pInstance%3F97CD780354.role


CPOStateShuttingDown::CPOStateShuttingDown()
  //## begin CPOStateShuttingDown::CPOStateShuttingDown%.hasinit preserve=no
  //## end CPOStateShuttingDown::CPOStateShuttingDown%.hasinit
  //## begin CPOStateShuttingDown::CPOStateShuttingDown%.initialization preserve=yes
  //## end CPOStateShuttingDown::CPOStateShuttingDown%.initialization
{
  //## begin CPOStateShuttingDown::CPOStateShuttingDown%.body preserve=yes
  //## end CPOStateShuttingDown::CPOStateShuttingDown%.body
}


CPOStateShuttingDown::~CPOStateShuttingDown()
{
  //## begin CPOStateShuttingDown::~CPOStateShuttingDown%.body preserve=yes
  //## end CPOStateShuttingDown::~CPOStateShuttingDown%.body
}



//## Other Operations (implementation)
void CPOStateShuttingDown::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateShuttingDown::Do%1066888971.body preserve=yes

	// Stop timer.
	GetpImpl(p_pContext)->StopTimer();

	// Update eprom values.
	GetpImpl(p_pContext)->GetpLifeTimeCounterHandler()->UpdateEpromValues();
	GetpImpl(p_pContext)->GetpLifeTimeCounterHandler()->DeleteCounterList();

	// Delete parameter list.
	GetpImpl(p_pContext)->GetpLogic()->GetpEprom()->ResetNewLists();
	GetpImpl(p_pContext)->GetpLogic()->GetpEprom()->ResetUpdatedLifeTimeList();
	GetpImpl(p_pContext)->GetpLogic()->GetpEprom()->SetbHeaderInfoUpToDate(false);

	p_pContext->ChangeState(CPOStateCreated::GetInstance());
  //## end CPOStateShuttingDown::Do%1066888971.body
}

void CPOStateShuttingDown::Create ()
{
  //## begin CPOStateShuttingDown::Create%1066888997.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPOStateShuttingDown();
  //## end CPOStateShuttingDown::Create%1066888997.body
}

void CPOStateShuttingDown::Delete ()
{
  //## begin CPOStateShuttingDown::Delete%1066888998.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPOStateShuttingDown::Delete%1066888998.body
}

CPOStateShuttingDown* CPOStateShuttingDown::GetInstance ()
{
  //## begin CPOStateShuttingDown::GetInstance%1066888999.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPOStateShuttingDown::GetInstance%1066888999.body
}

void CPOStateShuttingDown::CleanupStop (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateShuttingDown::CleanupStop%1087983835.body preserve=yes
  CleanupInitialize(p_pContext);
  //## end CPOStateShuttingDown::CleanupStop%1087983835.body
}

void CPOStateShuttingDown::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateShuttingDown::CleanupInitialize%1087983836.body preserve=yes
  p_pContext->ChangeState(CPOStateCreated::GetInstance());
  //## end CPOStateShuttingDown::CleanupInitialize%1087983836.body
}

// Additional Declarations
  //## begin CPOStateShuttingDown%3F93AF0403DF.declarations preserve=yes
  //## end CPOStateShuttingDown%3F93AF0403DF.declarations

//## begin module%3FA609E700CB.epilog preserve=yes
//## end module%3FA609E700CB.epilog
