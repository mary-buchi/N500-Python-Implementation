//## begin module%3EED769F035A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F035A.cm

//## begin module%3EED769F035A.cp preserve=no
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
//## end module%3EED769F035A.cp

//## Module: EBPCsten%3EED769F035A; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCsten.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F035A.additionalIncludes preserve=no
//## end module%3EED769F035A.additionalIncludes

//## begin module%3EED769F035A.includes preserve=yes
//## end module%3EED769F035A.includes

// EBPCconn
#include "EBPCconn.h"
// EBPCproc
#include "EBPCproc.h"
// EBPCconfig
#include "EBPCconfig.h"
// EBPCidle
#include "EBPCidle.h"
// EBPCsten
#include "EBPCsten.h"
// EBPCcrea
#include "EBPCcrea.h"
//## begin module%3EED769F035A.declarations preserve=no
//## end module%3EED769F035A.declarations

//## begin module%3EED769F035A.additionalDeclarations preserve=yes
//## end module%3EED769F035A.additionalDeclarations


// Class CPCStateMachineEngine 

CPCStateMachineEngine::CPCStateMachineEngine (ICOStateMachineContext* p_pContext)
  //## begin CPCStateMachineEngine::CPCStateMachineEngine%1038899318.hasinit preserve=no
  //## end CPCStateMachineEngine::CPCStateMachineEngine%1038899318.hasinit
  //## begin CPCStateMachineEngine::CPCStateMachineEngine%1038899318.initialization preserve=yes
  : CCOStateMachineEngine(p_pContext)
  //## end CPCStateMachineEngine::CPCStateMachineEngine%1038899318.initialization
{
  //## begin CPCStateMachineEngine::CPCStateMachineEngine%1038899318.body preserve=yes
  //## end CPCStateMachineEngine::CPCStateMachineEngine%1038899318.body
}


CPCStateMachineEngine::~CPCStateMachineEngine()
{
  //## begin CPCStateMachineEngine::~CPCStateMachineEngine%.body preserve=yes
  //## end CPCStateMachineEngine::~CPCStateMachineEngine%.body
}



//## Other Operations (implementation)
void CPCStateMachineEngine::BuildStateMachine ()
{
  //## begin CPCStateMachineEngine::BuildStateMachine%1038899319.body preserve=yes
    CPCStateCreated::Create();
	CPCStateConfigNotSet::Create();
	CPCStateConfigSet::Create();
	CPCStateConfigProfileNotSet::Create ();
	CPCStateConfigProfileSet::Create ();
	CPCStateIdlePowerOff::Create (); 
	CPCStateIdleCheckPower::Create ();
	CPCStateIdleStarting::Create();
	CPCStateIdleStandBy::Create();
	CPCStateProcessStarting::Create();
	CPCStateProcessSwinging::Create ();
	CPCStateProcessControling::Create();
	CPCStateNotConnected::Create();
	CPCStateNotConnectedNoConfig::Create();
  //## end CPCStateMachineEngine::BuildStateMachine%1038899319.body
}

CCOState* CPCStateMachineEngine::GetInitializeState ()
{
  //## begin CPCStateMachineEngine::GetInitializeState%1042097147.body preserve=yes
    return CPCStateCreated::GetInstance(); // default state subsystem
  //## end CPCStateMachineEngine::GetInitializeState%1042097147.body
}

void CPCStateMachineEngine::CreateActions (CTypedPtrList<CPtrList, CCOAction*>& p_ActionList)
{
  //## begin CPCStateMachineEngine::CreateActions%1038899320.body preserve=yes
  //## end CPCStateMachineEngine::CreateActions%1038899320.body
}

void CPCStateMachineEngine::DeleteStateMachine ()
{
  //## begin CPCStateMachineEngine::DeleteStateMachine%1038899321.body preserve=yes
    CPCStateCreated::Delete();
	CPCStateConfigNotSet::Delete();
	CPCStateConfigSet::Delete();
	CPCStateConfigProfileNotSet::Delete ();
	CPCStateConfigProfileSet::Delete ();
	CPCStateIdlePowerOff::Delete (); 
	CPCStateIdleCheckPower::Delete ();
	CPCStateIdleStarting::Delete();
	CPCStateIdleStandBy::Delete();
	CPCStateProcessStarting::Delete();
	CPCStateProcessSwinging::Delete ();
	CPCStateProcessControling::Delete();
	CPCStateNotConnected::Delete();
	CPCStateNotConnectedNoConfig::Delete();
  //## end CPCStateMachineEngine::DeleteStateMachine%1038899321.body
}

// Additional Declarations
  //## begin CPCStateMachineEngine%3EED76CC033F.declarations preserve=yes
  //## end CPCStateMachineEngine%3EED76CC033F.declarations

//## begin module%3EED769F035A.epilog preserve=yes
//## end module%3EED769F035A.epilog
