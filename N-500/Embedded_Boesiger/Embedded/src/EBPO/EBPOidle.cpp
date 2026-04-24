//## begin module%3DE5EB4800DF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EB4800DF.cm

//## begin module%3DE5EB4800DF.cp preserve=no
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
//## end module%3DE5EB4800DF.cp

//## Module: EBPOidle%3DE5EB4800DF; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOidle.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EB4800DF.additionalIncludes preserve=no
//## end module%3DE5EB4800DF.additionalIncludes

//## begin module%3DE5EB4800DF.includes preserve=yes
//## end module%3DE5EB4800DF.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBPItias
#include "EBPItias.h"
// EBPItype
#include "EBPItype.h"
// EBPOshdn
#include "EBPOshdn.h"
// EBPOeprom
#include "EBPOeprom.h"
// EBPOcounter
#include "EBPOcounter.h"
// EBPOlogic
#include "EBPOlogic.h"
// EBPOnotc
#include "EBPOnotc.h"
// EBPOstor
#include "EBPOstor.h"
// EBPOlcnt
#include "EBPOlcnt.h"
// EBPOcnfg
#include "EBPOcnfg.h"
// EBPOidle
#include "EBPOidle.h"
// EBPOidnt
#include "EBPOidnt.h"
//## begin module%3DE5EB4800DF.declarations preserve=no
//## end module%3DE5EB4800DF.declarations

//## begin module%3DE5EB4800DF.additionalDeclarations preserve=yes
//## end module%3DE5EB4800DF.additionalDeclarations


// Class CPOStateIdle 

//## begin CPOStateIdle::pInstance%3F97CD700334.role preserve=no  public: static CPOStateIdle {1..1 -> 1..1RFHN}
CPOStateIdle *CPOStateIdle::m_pInstance;
//## end CPOStateIdle::pInstance%3F97CD700334.role


CPOStateIdle::CPOStateIdle()
  //## begin CPOStateIdle::CPOStateIdle%.hasinit preserve=no
  //## end CPOStateIdle::CPOStateIdle%.hasinit
  //## begin CPOStateIdle::CPOStateIdle%.initialization preserve=yes
  //## end CPOStateIdle::CPOStateIdle%.initialization
{
  //## begin CPOStateIdle::CPOStateIdle%.body preserve=yes
  //## end CPOStateIdle::CPOStateIdle%.body
}


CPOStateIdle::~CPOStateIdle()
{
  //## begin CPOStateIdle::~CPOStateIdle%.body preserve=yes
  //## end CPOStateIdle::~CPOStateIdle%.body
}



//## Other Operations (implementation)
void CPOStateIdle::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateIdle::CleanupInitialize%1066888978.body preserve=yes
	GetpImpl(p_pContext)->GetpLogic()->MCUndock();
  //## end CPOStateIdle::CleanupInitialize%1066888978.body
}

void CPOStateIdle::StartMonitoring (ICOStateMachineContext* p_pContext, const EPILifeTimeCounter p_eDevice)
{
  //## begin CPOStateIdle::StartMonitoring%1066888979.body preserve=yes
	
	GetpImpl(p_pContext)->GetpLifeTimeCounterHandler()->StartMonitoring(p_eDevice);

  //## end CPOStateIdle::StartMonitoring%1066888979.body
}

void CPOStateIdle::StopMonitoring (ICOStateMachineContext* p_pContext, const EPILifeTimeCounter p_eDevice)
{
  //## begin CPOStateIdle::StopMonitoring%1066888980.body preserve=yes

	GetpImpl(p_pContext)->GetpLifeTimeCounterHandler()->StopMonitoring(p_eDevice);

  //## end CPOStateIdle::StopMonitoring%1066888980.body
}

void CPOStateIdle::Save (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateIdle::Save%1066888981.body preserve=yes
	p_pContext->ChangeState(CPOStateStoreReading::GetInstance());
  //## end CPOStateIdle::Save%1066888981.body
}

void CPOStateIdle::ReadParameters (ICOStateMachineContext* p_pContext, CPISyncObjListPersistentItems *p_pSyncObjParameters)
{
  //## begin CPOStateIdle::ReadParameters%1066888982.body preserve=yes
	// list of persistent items
	CTypedPtrList<CPtrList, CPIPersistentItem*> l_List;

	// fill list with data of all eproms
	GetpImpl(p_pContext)->GetpLogic()->ReadParameter(l_List);

	// new list
	CPIPersistentItemList *l_PersistentItemList = new CPIPersistentItemList(l_List);

	// Add list to sync object.
	p_pSyncObjParameters->SetValue(l_PersistentItemList);

	// Signal the sync object.
	p_pSyncObjParameters->SignalCompletion();
  //## end CPOStateIdle::ReadParameters%1066888982.body
}

void CPOStateIdle::Create ()
{
  //## begin CPOStateIdle::Create%1066888988.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPOStateIdle();
  //## end CPOStateIdle::Create%1066888988.body
}

void CPOStateIdle::Delete ()
{
  //## begin CPOStateIdle::Delete%1066888989.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPOStateIdle::Delete%1066888989.body
}

CPOStateIdle * CPOStateIdle::GetInstance ()
{
  //## begin CPOStateIdle::GetInstance%1066888990.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPOStateIdle::GetInstance%1066888990.body
}

void CPOStateIdle::ReadLifeTimeCounter (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj, EPILifeTimeCounter p_eCounter)
{
  //## begin CPOStateIdle::ReadLifeTimeCounter%1066918322.body preserve=yes
	int l_iCounterValue = GetpImpl(p_pContext)->GetpLogic()->ReadLifeTimeCounter(p_eCounter);
	p_pClientSyncObj->SetValue(l_iCounterValue);
	p_pClientSyncObj->SignalCompletion();
  //## end CPOStateIdle::ReadLifeTimeCounter%1066918322.body
}

void CPOStateIdle::ReadIdentifications (ICOStateMachineContext* p_pContext, CPISyncObjListPersistentItems *p_pSyncObjParameters)
{
  //## begin CPOStateIdle::ReadIdentifications%1066980585.body preserve=yes
	// list of persistent items
	CTypedPtrList<CPtrList, CPIPersistentItem*> l_List;

	// fill list with data of all eproms
	GetpImpl(p_pContext)->GetpLogic()->ReadIdentifications(l_List);

	// new list
	CPIPersistentItemList *l_PersistentItemList = new CPIPersistentItemList(l_List);

	// Add list to sync object.
	p_pSyncObjParameters->SetValue(l_PersistentItemList);

	// Signal the sync object.
	p_pSyncObjParameters->SignalCompletion();
  //## end CPOStateIdle::ReadIdentifications%1066980585.body
}

void CPOStateIdle::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateIdle::Do%1067251213.body preserve=yes
	CPOLifeTimeCounterHandler *l_pLifeTime = GetpImpl(p_pContext)->GetpLifeTimeCounterHandler();

	// First time startup.
	if (CPITicksAtStart::m_dwTicksAtStartUp > 0)
	{
		// [s]
		DWORD l_dwElTimeSinceStartUp = (GetTickCount() - CPITicksAtStart::m_dwTicksAtStartUp) / 1000;
		EPILamp l_eLamp = CPITicksAtStart::m_eLamp;

		switch (l_eLamp)
		{
			case ePrimaryLamp:
				l_pLifeTime->StartMonitoring(eLampPrimary, l_dwElTimeSinceStartUp);
				break;

			case eSecondaryLamp:
				l_pLifeTime->StartMonitoring(eLampSecondary, l_dwElTimeSinceStartUp);
				break;

			default:
				ASSERT(false);
				break;
		}

		l_pLifeTime->StartMonitoring(eLaser, l_dwElTimeSinceStartUp);
		CPITicksAtStart::m_dwTicksAtStartUp = 0;
	}

	// After connetion established.
	if (l_pLifeTime->GetdwTicksAtConnLost() > 0)
	{
		l_pLifeTime->AddDeltaValues((GetTickCount() - l_pLifeTime->GetdwTicksAtConnLost()) / 1000);
		l_pLifeTime->SetdwTicksAtConnLost(0);
	}
  //## end CPOStateIdle::Do%1067251213.body
}

void CPOStateIdle::OnTimer (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateIdle::OnTimer%1067251214.body preserve=yes
	p_pContext->ChangeState(CPOStateLifeTimeCounterSum::GetInstance());
  //## end CPOStateIdle::OnTimer%1067251214.body
}

void CPOStateIdle::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateIdle::ConnectionLost%1067251218.body preserve=yes
	p_pContext->ChangeState(CPOStateNotConnected::GetInstance());
  //## end CPOStateIdle::ConnectionLost%1067251218.body
}

void CPOStateIdle::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateIdle::Startup%1067251223.body preserve=yes
	GetpImpl(p_pContext)->StopTimer();
	p_pContext->ChangeState(CPOStateConfigStart::GetInstance());
  //## end CPOStateIdle::Startup%1067251223.body
}

void CPOStateIdle::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateIdle::Shutdown%1067262119.body preserve=yes
	p_pContext->ChangeState(CPOStateShuttingDown::GetInstance());
  //## end CPOStateIdle::Shutdown%1067262119.body
}

void CPOStateIdle::WriteLifeTimeCounter (ICOStateMachineContext* p_pContext, const EPILifeTimeCounter p_eCounter, const UINT &p_uiValue)
{
  //## begin CPOStateIdle::WriteLifeTimeCounter%1068458447.body preserve=yes
	GetpImpl(p_pContext)->GetpLogic()->WriteLifeTimeCounter(p_eCounter, p_uiValue);
  //## end CPOStateIdle::WriteLifeTimeCounter%1068458447.body
}

void CPOStateIdle::WriteIdentification (ICOStateMachineContext* p_pContext, CPIPersistentIdent* p_pIdentification)
{
  //## begin CPOStateIdle::WriteIdentification%1077884326.body preserve=yes
	GetpImpl(p_pContext)->GetpLogic()->WriteIdent(p_pIdentification);
  //## end CPOStateIdle::WriteIdentification%1077884326.body
}

void CPOStateIdle::WriteParameter (ICOStateMachineContext* p_pContext, CPIPersistentPara* p_pParameter)
{
  //## begin CPOStateIdle::WriteParameter%1077884328.body preserve=yes
	GetpImpl(p_pContext)->GetpLogic()->WriteParameter(p_pParameter);
  //## end CPOStateIdle::WriteParameter%1077884328.body
}

void CPOStateIdle::Reset (ICOStateMachineContext* p_pContext, EPIEpromSection p_eSection)
{
  //## begin CPOStateIdle::Reset%1077888067.body preserve=yes
	GetpImpl(p_pContext)->GetpLogic()->Reset(p_eSection);
  //## end CPOStateIdle::Reset%1077888067.body
}

void CPOStateIdle::MeasurementCellUndocked (ICOStateMachineContext* p_pContext)
{
  //## begin CPOStateIdle::MeasurementCellUndocked%1080142969.body preserve=yes
	GetpImpl(p_pContext)->GetpLogic()->MCUndock();
  //## end CPOStateIdle::MeasurementCellUndocked%1080142969.body
}

// Additional Declarations
  //## begin CPOStateIdle%3F93ADF202C6.declarations preserve=yes
  //## end CPOStateIdle%3F93ADF202C6.declarations

//## begin module%3DE5EB4800DF.epilog preserve=yes
//## end module%3DE5EB4800DF.epilog
