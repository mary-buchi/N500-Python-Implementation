//## begin module%3F93A937019D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F93A937019D.cm

//## begin module%3F93A937019D.cp preserve=no
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
//## end module%3F93A937019D.cp

//## Module: EBPOlcnt%3F93A937019D; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOlcnt.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F93A937019D.additionalIncludes preserve=no
//## end module%3F93A937019D.additionalIncludes

//## begin module%3F93A937019D.includes preserve=yes
//## end module%3F93A937019D.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBPOcounter
#include "EBPOcounter.h"
// EBPOlogic
#include "EBPOlogic.h"
// EBPOlcnt
#include "EBPOlcnt.h"
// EBPOidle
#include "EBPOidle.h"
//## begin module%3F93A937019D.declarations preserve=no
//## end module%3F93A937019D.declarations

//## begin module%3F93A937019D.additionalDeclarations preserve=yes
//## end module%3F93A937019D.additionalDeclarations


// Class CPOStateLifeTimeCounterSum 

//## begin CPOStateLifeTimeCounterSum::pInstance%3F97CD960007.role preserve=no  public: static CPOStateLifeTimeCounterSum {1..1 -> 1..1RFHN}
CPOStateLifeTimeCounterSum *CPOStateLifeTimeCounterSum::m_pInstance;
//## end CPOStateLifeTimeCounterSum::pInstance%3F97CD960007.role


CPOStateLifeTimeCounterSum::CPOStateLifeTimeCounterSum()
  //## begin CPOStateLifeTimeCounterSum::CPOStateLifeTimeCounterSum%.hasinit preserve=no
  //## end CPOStateLifeTimeCounterSum::CPOStateLifeTimeCounterSum%.hasinit
  //## begin CPOStateLifeTimeCounterSum::CPOStateLifeTimeCounterSum%.initialization preserve=yes
  //## end CPOStateLifeTimeCounterSum::CPOStateLifeTimeCounterSum%.initialization
{
  //## begin CPOStateLifeTimeCounterSum::CPOStateLifeTimeCounterSum%.body preserve=yes
  //## end CPOStateLifeTimeCounterSum::CPOStateLifeTimeCounterSum%.body
}


CPOStateLifeTimeCounterSum::~CPOStateLifeTimeCounterSum()
{
  //## begin CPOStateLifeTimeCounterSum::~CPOStateLifeTimeCounterSum%.body preserve=yes
  //## end CPOStateLifeTimeCounterSum::~CPOStateLifeTimeCounterSum%.body
}



//## Other Operations (implementation)
void CPOStateLifeTimeCounterSum::Create ()
{
  //## begin CPOStateLifeTimeCounterSum::Create%1066889006.body preserve=yes
  	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPOStateLifeTimeCounterSum();
  //## end CPOStateLifeTimeCounterSum::Create%1066889006.body
}

void CPOStateLifeTimeCounterSum::Delete ()
{
  //## begin CPOStateLifeTimeCounterSum::Delete%1066889007.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPOStateLifeTimeCounterSum::Delete%1066889007.body
}

CPOStateLifeTimeCounterSum* CPOStateLifeTimeCounterSum::GetInstance ()
{
  //## begin CPOStateLifeTimeCounterSum::GetInstance%1066889008.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPOStateLifeTimeCounterSum::GetInstance%1066889008.body
}

void CPOStateLifeTimeCounterSum::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateLifeTimeCounterSum::Do%1067251216.body preserve=yes

	// Get auto save time from config.
	DWORD l_dwTimerInterval = GetpImpl(p_pContext)->GetpConfig()->GetdwTimerInterval();
	DWORD l_dwSaveTime = l_dwTimerInterval * GetpImpl(p_pContext)->GetpConfig()->GetdwTimerIntervalFactor();
	l_dwSaveTime  *= 1000;	// [s]

	DWORD l_dwElapsedAutoSaveTime = GetpImpl(p_pContext)->GetpLifeTimeCounterHandler()->GetdwElapsedAutoSaveTime();

	// Save to eprom or not.
	if (l_dwElapsedAutoSaveTime >= l_dwSaveTime)
	{
        // Save to eprom.
		GetpImpl(p_pContext)->GetpLifeTimeCounterHandler()->SetdwElapsedAutoSaveTime(0);
		p_pContext->ChangeState(CPOStateLifeTimeCounterSave::GetInstance());
	}
	else
	{
		// Continue to sum.
		GetpImpl(p_pContext)->GetpLifeTimeCounterHandler()->IncElapsedAutoSaveTime();
		p_pContext->ChangeState(CPOStateIdle::GetInstance());

		// Inc. delta counter values.
		GetpImpl(p_pContext)->GetpLifeTimeCounterHandler()->AddDeltaValues( l_dwTimerInterval );
	}

  //## end CPOStateLifeTimeCounterSum::Do%1067251216.body
}

// Additional Declarations
  //## begin CPOStateLifeTimeCounterSum%3F93AEB500E1.declarations preserve=yes
  //## end CPOStateLifeTimeCounterSum%3F93AEB500E1.declarations

// Class CPOStateLifeTimeCounterSave 

//## begin CPOStateLifeTimeCounterSave::pInstance%3F97CD930102.role preserve=no  public: static CPOStateLifeTimeCounterSave {1..1 -> 1..1RFHN}
CPOStateLifeTimeCounterSave *CPOStateLifeTimeCounterSave::m_pInstance;
//## end CPOStateLifeTimeCounterSave::pInstance%3F97CD930102.role


CPOStateLifeTimeCounterSave::CPOStateLifeTimeCounterSave()
  //## begin CPOStateLifeTimeCounterSave::CPOStateLifeTimeCounterSave%.hasinit preserve=no
  //## end CPOStateLifeTimeCounterSave::CPOStateLifeTimeCounterSave%.hasinit
  //## begin CPOStateLifeTimeCounterSave::CPOStateLifeTimeCounterSave%.initialization preserve=yes
  //## end CPOStateLifeTimeCounterSave::CPOStateLifeTimeCounterSave%.initialization
{
  //## begin CPOStateLifeTimeCounterSave::CPOStateLifeTimeCounterSave%.body preserve=yes
  //## end CPOStateLifeTimeCounterSave::CPOStateLifeTimeCounterSave%.body
}


CPOStateLifeTimeCounterSave::~CPOStateLifeTimeCounterSave()
{
  //## begin CPOStateLifeTimeCounterSave::~CPOStateLifeTimeCounterSave%.body preserve=yes
  //## end CPOStateLifeTimeCounterSave::~CPOStateLifeTimeCounterSave%.body
}



//## Other Operations (implementation)
void CPOStateLifeTimeCounterSave::Create ()
{
  //## begin CPOStateLifeTimeCounterSave::Create%1066889003.body preserve=yes
  	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPOStateLifeTimeCounterSave();
  //## end CPOStateLifeTimeCounterSave::Create%1066889003.body
}

void CPOStateLifeTimeCounterSave::Delete ()
{
  //## begin CPOStateLifeTimeCounterSave::Delete%1066889004.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPOStateLifeTimeCounterSave::Delete%1066889004.body
}

CPOStateLifeTimeCounterSave* CPOStateLifeTimeCounterSave::GetInstance ()
{
  //## begin CPOStateLifeTimeCounterSave::GetInstance%1066889005.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPOStateLifeTimeCounterSave::GetInstance%1066889005.body
}

void CPOStateLifeTimeCounterSave::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateLifeTimeCounterSave::Do%1067251217.body preserve=yes
	// Update eprom values.
	GetpImpl(p_pContext)->GetpLifeTimeCounterHandler()->UpdateEpromValues();

	// Reset delta values
	GetpImpl(p_pContext)->GetpLifeTimeCounterHandler()->ResetDeltaValue();

	// Remove all not acitvated counter from list.
	GetpImpl(p_pContext)->GetpLifeTimeCounterHandler()->RemoveNotActivatedCounter();

	p_pContext->ChangeState(CPOStateIdle::GetInstance());
  //## end CPOStateLifeTimeCounterSave::Do%1067251217.body
}

// Additional Declarations
  //## begin CPOStateLifeTimeCounterSave%3F93AECC0333.declarations preserve=yes
  //## end CPOStateLifeTimeCounterSave%3F93AECC0333.declarations

// Class CPOStateLifeTimeCounter 

CPOStateLifeTimeCounter::CPOStateLifeTimeCounter()
  //## begin CPOStateLifeTimeCounter::CPOStateLifeTimeCounter%.hasinit preserve=no
  //## end CPOStateLifeTimeCounter::CPOStateLifeTimeCounter%.hasinit
  //## begin CPOStateLifeTimeCounter::CPOStateLifeTimeCounter%.initialization preserve=yes
  //## end CPOStateLifeTimeCounter::CPOStateLifeTimeCounter%.initialization
{
  //## begin CPOStateLifeTimeCounter::CPOStateLifeTimeCounter%.body preserve=yes
  //## end CPOStateLifeTimeCounter::CPOStateLifeTimeCounter%.body
}


CPOStateLifeTimeCounter::~CPOStateLifeTimeCounter()
{
  //## begin CPOStateLifeTimeCounter::~CPOStateLifeTimeCounter%.body preserve=yes
  //## end CPOStateLifeTimeCounter::~CPOStateLifeTimeCounter%.body
}



//## Other Operations (implementation)
void CPOStateLifeTimeCounter::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateLifeTimeCounter::CleanupInitialize%1067325000.body preserve=yes
	GetpImpl(p_pContext)->GetpLogic()->MCUndock();
	p_pContext->ChangeState(CPOStateIdle::GetInstance());
  //## end CPOStateLifeTimeCounter::CleanupInitialize%1067325000.body
}

// Additional Declarations
  //## begin CPOStateLifeTimeCounter%3F9E208F0333.declarations preserve=yes
  //## end CPOStateLifeTimeCounter%3F9E208F0333.declarations

//## begin module%3F93A937019D.epilog preserve=yes
//## end module%3F93A937019D.epilog
