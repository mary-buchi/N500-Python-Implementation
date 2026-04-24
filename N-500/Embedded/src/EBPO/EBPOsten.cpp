//## begin module%3DE5EB340218.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EB340218.cm

//## begin module%3DE5EB340218.cp preserve=no
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
//## end module%3DE5EB340218.cp

//## Module: EBPOsten%3DE5EB340218; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOsten.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EB340218.additionalIncludes preserve=no
//## end module%3DE5EB340218.additionalIncludes

//## begin module%3DE5EB340218.includes preserve=yes
//## end module%3DE5EB340218.includes

// EBPOshdn
#include "EBPOshdn.h"
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
// EBPOstat
#include "EBPOstat.h"
// EBPOsten
#include "EBPOsten.h"
//## begin module%3DE5EB340218.declarations preserve=no
//## end module%3DE5EB340218.declarations

//## begin module%3DE5EB340218.additionalDeclarations preserve=yes
//## end module%3DE5EB340218.additionalDeclarations


// Class CPOStateMachineEngine 

CPOStateMachineEngine::CPOStateMachineEngine (ICOStateMachineContext* p_pContext)
  //## begin CPOStateMachineEngine::CPOStateMachineEngine%1038495073.hasinit preserve=no
  //## end CPOStateMachineEngine::CPOStateMachineEngine%1038495073.hasinit
  //## begin CPOStateMachineEngine::CPOStateMachineEngine%1038495073.initialization preserve=yes
  : CCOStateMachineEngine(p_pContext)
  //## end CPOStateMachineEngine::CPOStateMachineEngine%1038495073.initialization
{
  //## begin CPOStateMachineEngine::CPOStateMachineEngine%1038495073.body preserve=yes
  //## end CPOStateMachineEngine::CPOStateMachineEngine%1038495073.body
}


CPOStateMachineEngine::~CPOStateMachineEngine()
{
  //## begin CPOStateMachineEngine::~CPOStateMachineEngine%.body preserve=yes
  //## end CPOStateMachineEngine::~CPOStateMachineEngine%.body
}



//## Other Operations (implementation)
void CPOStateMachineEngine::BuildStateMachine ()
{
  //## begin CPOStateMachineEngine::BuildStateMachine%1038495058.body preserve=yes
    CPOStateCreated::Create();
	CPOStateConfigStart::Create();
	CPOStateConfigAssigned::Create();
	CPOStateShuttingDown::Create();
	CPOStateNotConnected::Create();
	CPOStateIdle::Create();
	CPOStateLifeTimeCounterSum::Create();
	CPOStateLifeTimeCounterSave::Create();
	CPOStateStoreReading::Create ();
	CPOStateStoreParse::Create();
	CPOStateStoreWriting::Create();
  //## end CPOStateMachineEngine::BuildStateMachine%1038495058.body
}

CCOState* CPOStateMachineEngine::GetInitializeState ()
{
  //## begin CPOStateMachineEngine::GetInitializeState%1042097145.body preserve=yes
    return CPOStateCreated::GetInstance(); // default state subsystem
  //## end CPOStateMachineEngine::GetInitializeState%1042097145.body
}

void CPOStateMachineEngine::CreateActions (CTypedPtrList<CPtrList, CCOAction*>& p_ActionList)
{
  //## begin CPOStateMachineEngine::CreateActions%1038495059.body preserve=yes
  //## end CPOStateMachineEngine::CreateActions%1038495059.body
}

void CPOStateMachineEngine::DeleteStateMachine ()
{
  //## begin CPOStateMachineEngine::DeleteStateMachine%1038495057.body preserve=yes
    CPOStateCreated::Delete();
	CPOStateConfigAssigned::Delete();
	CPOStateConfigStart::Delete();
	CPOStateShuttingDown::Delete();
	CPOStateNotConnected::Delete();
	CPOStateIdle::Delete();
	CPOStateLifeTimeCounterSum::Delete();
	CPOStateLifeTimeCounterSave::Delete();
	CPOStateStoreReading::Delete ();
	CPOStateStoreParse::Delete();
	CPOStateStoreWriting::Delete();
  //## end CPOStateMachineEngine::DeleteStateMachine%1038495057.body
}

// Additional Declarations
  //## begin CPOStateMachineEngine%3DE636EE02D3.declarations preserve=yes
  //## end CPOStateMachineEngine%3DE636EE02D3.declarations

//## begin module%3DE5EB340218.epilog preserve=yes
//## end module%3DE5EB340218.epilog
