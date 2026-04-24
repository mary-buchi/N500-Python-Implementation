//## begin module%3DAAE3DA013C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAE3DA013C.cm

//## begin module%3DAAE3DA013C.cp preserve=no
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
//## end module%3DAAE3DA013C.cp

//## Module: EBMCsten%3DAAE3DA013C; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCsten.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DAAE3DA013C.additionalIncludes preserve=no
//## end module%3DAAE3DA013C.additionalIncludes

//## begin module%3DAAE3DA013C.includes preserve=yes
//## end module%3DAAE3DA013C.includes

// EBMCsten
#include "EBMCsten.h"
// EBMCidnt
#include "EBMCidnt.h"
// EBMCconn
#include "EBMCconn.h"
// EBMCacti
#include "EBMCacti.h"
// EBMCdata
#include "EBMCdata.h"
// EBMCproc
#include "EBMCproc.h"
// EBMCidle
#include "EBMCidle.h"
//## begin module%3DAAE3DA013C.declarations preserve=no
//## end module%3DAAE3DA013C.declarations

//## begin module%3DAAE3DA013C.additionalDeclarations preserve=yes
//## end module%3DAAE3DA013C.additionalDeclarations


// Class CMCStateMachineEngine 

CMCStateMachineEngine::CMCStateMachineEngine (ICOStateMachineContext* p_pContext)
  //## begin CMCStateMachineEngine::CMCStateMachineEngine%1034575117.hasinit preserve=no
  //## end CMCStateMachineEngine::CMCStateMachineEngine%1034575117.hasinit
  //## begin CMCStateMachineEngine::CMCStateMachineEngine%1034575117.initialization preserve=yes
  : CCOStateMachineEngine(p_pContext)
  //## end CMCStateMachineEngine::CMCStateMachineEngine%1034575117.initialization
{
  //## begin CMCStateMachineEngine::CMCStateMachineEngine%1034575117.body preserve=yes
  //## end CMCStateMachineEngine::CMCStateMachineEngine%1034575117.body
}


CMCStateMachineEngine::~CMCStateMachineEngine()
{
  //## begin CMCStateMachineEngine::~CMCStateMachineEngine%.body preserve=yes
  //## end CMCStateMachineEngine::~CMCStateMachineEngine%.body
}



//## Other Operations (implementation)
void CMCStateMachineEngine::BuildStateMachine ()
{
  //## begin CMCStateMachineEngine::BuildStateMachine%1034575119.body preserve=yes
    CMCStateCreated::Create();
    CMCStateProfileNotAssign::Create();
    CMCStateProfile::Create();
    CMCStateInitialized::Create();
    CMCStateInitializing::Create();
    CMCStateDataAcquistionReady::Create();
    CMCStateGetDataPackage::Create();
    CMCStateNotConnected::Create();
    CMCStateDataSimulationPrepare::Create();
    CMCStateDataSimulationReady::Create();
  //## end CMCStateMachineEngine::BuildStateMachine%1034575119.body
}

CCOState* CMCStateMachineEngine::GetInitializeState ()
{
  //## begin CMCStateMachineEngine::GetInitializeState%1042097143.body preserve=yes
    return CMCStateCreated::GetInstance();
  //## end CMCStateMachineEngine::GetInitializeState%1042097143.body
}

void CMCStateMachineEngine::CreateActions (CTypedPtrList<CPtrList, CCOAction*>& p_ActionList)
{
  //## begin CMCStateMachineEngine::CreateActions%1034575120.body preserve=yes
  p_ActionList.AddTail(new CMCActionGetDataPackage(IDA_GETDATAPACKAGE, m_pContext));
  //## end CMCStateMachineEngine::CreateActions%1034575120.body
}

void CMCStateMachineEngine::DeleteStateMachine ()
{
  //## begin CMCStateMachineEngine::DeleteStateMachine%1034575118.body preserve=yes

    CMCStateCreated::Delete();
    CMCStateProfileNotAssign::Delete();
    CMCStateProfile::Delete();
    CMCStateInitialized::Delete();
    CMCStateInitializing::Delete();
    CMCStateDataAcquistionReady::Delete();
    CMCStateGetDataPackage::Delete();
    CMCStateNotConnected::Delete();
    CMCStateDataSimulationPrepare::Delete();
    CMCStateDataSimulationReady::Delete();
  //## end CMCStateMachineEngine::DeleteStateMachine%1034575118.body
}

// Additional Declarations
  //## begin CMCStateMachineEngine%3DAAE9820294.declarations preserve=yes
  //## end CMCStateMachineEngine%3DAAE9820294.declarations

//## begin module%3DAAE3DA013C.epilog preserve=yes
//## end module%3DAAE3DA013C.epilog
