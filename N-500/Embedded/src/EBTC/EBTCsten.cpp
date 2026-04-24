//## begin module%3DE5EDE00024.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EDE00024.cm

//## begin module%3DE5EDE00024.cp preserve=no
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
//## end module%3DE5EDE00024.cp

//## Module: EBTCsten%3DE5EDE00024; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCsten.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EDE00024.additionalIncludes preserve=no
//## end module%3DE5EDE00024.additionalIncludes

//## begin module%3DE5EDE00024.includes preserve=yes
//## end module%3DE5EDE00024.includes

// EBTCconn
#include "EBTCconn.h"
// EBTCprocess
#include "EBTCprocess.h"
// EBTCconfig
#include "EBTCconfig.h"
// EBTCidle
#include "EBTCidle.h"
// EBTCsten
#include "EBTCsten.h"
//## begin module%3DE5EDE00024.declarations preserve=no
//## end module%3DE5EDE00024.declarations

//## begin module%3DE5EDE00024.additionalDeclarations preserve=yes
//## end module%3DE5EDE00024.additionalDeclarations


// Class CTCStateMachineEngine 

CTCStateMachineEngine::CTCStateMachineEngine (ICOStateMachineContext* p_pContext)
  //## begin CTCStateMachineEngine::CTCStateMachineEngine%1038899318.hasinit preserve=no
  //## end CTCStateMachineEngine::CTCStateMachineEngine%1038899318.hasinit
  //## begin CTCStateMachineEngine::CTCStateMachineEngine%1038899318.initialization preserve=yes
  : CCOStateMachineEngine(p_pContext)
  //## end CTCStateMachineEngine::CTCStateMachineEngine%1038899318.initialization
{
  //## begin CTCStateMachineEngine::CTCStateMachineEngine%1038899318.body preserve=yes
  //## end CTCStateMachineEngine::CTCStateMachineEngine%1038899318.body
}


CTCStateMachineEngine::~CTCStateMachineEngine()
{
  //## begin CTCStateMachineEngine::~CTCStateMachineEngine%.body preserve=yes
  //## end CTCStateMachineEngine::~CTCStateMachineEngine%.body
}



//## Other Operations (implementation)
void CTCStateMachineEngine::BuildStateMachine ()
{
  //## begin CTCStateMachineEngine::BuildStateMachine%1038899319.body preserve=yes
    CTCStateCreated::Create();
	CTCStateConfigNotSet::Create();
	CTCStateConfigSetConfig::Create();
	CTCStateConfigProfileNotSet::Create ();
	CTCStateConfigSetProfile::Create ();
	CTCStateConfigIdle::Create();
	CTCStateProcessIdle::Create (); 
	CTCStateProcessControl::Create ();
	CTCStateProcessPwmHigh::Create();
	CTCStateProcessPwmLow::Create();
	CTCStateNotConnectedConfig::Create();
	CTCStateNotConnectedProcess::Create();
  //## end CTCStateMachineEngine::BuildStateMachine%1038899319.body
}

CCOState* CTCStateMachineEngine::GetInitializeState ()
{
  //## begin CTCStateMachineEngine::GetInitializeState%1042097147.body preserve=yes
    return CTCStateCreated::GetInstance(); // default state subsystem
  //## end CTCStateMachineEngine::GetInitializeState%1042097147.body
}

void CTCStateMachineEngine::CreateActions (CTypedPtrList<CPtrList, CCOAction*>& p_ActionList)
{
  //## begin CTCStateMachineEngine::CreateActions%1038899320.body preserve=yes
  //## end CTCStateMachineEngine::CreateActions%1038899320.body
}

void CTCStateMachineEngine::DeleteStateMachine ()
{
  //## begin CTCStateMachineEngine::DeleteStateMachine%1038899321.body preserve=yes
    CTCStateCreated::Delete();
	CTCStateConfigNotSet::Delete();
	CTCStateConfigSetConfig::Delete();
	CTCStateConfigProfileNotSet::Delete ();
	CTCStateConfigSetProfile::Delete ();
	CTCStateProcessIdle::Delete ();
	CTCStateProcessControl::Delete ();
	CTCStateProcessPwmHigh::Delete();
	CTCStateProcessPwmLow::Delete();
	CTCStateConfigIdle::Delete();
	CTCStateNotConnectedConfig::Delete();
	CTCStateNotConnectedProcess::Delete();
  //## end CTCStateMachineEngine::DeleteStateMachine%1038899321.body
}

// Additional Declarations
  //## begin CTCStateMachineEngine%3DEC63C60252.declarations preserve=yes
  //## end CTCStateMachineEngine%3DEC63C60252.declarations

//## begin module%3DE5EDE00024.epilog preserve=yes
//## end module%3DE5EDE00024.epilog
