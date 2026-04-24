//## begin module%3DD100C8031F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD100C8031F.cm

//## begin module%3DD100C8031F.cp preserve=no
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
//## end module%3DD100C8031F.cp

//## Module: EBWCsten%3DD100C8031F; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCsten.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DD100C8031F.additionalIncludes preserve=no
//## end module%3DD100C8031F.additionalIncludes

//## begin module%3DD100C8031F.includes preserve=yes
//## end module%3DD100C8031F.includes

// EBWCconn
#include "EBWCconn.h"
// EBWCacti
#include "EBWCacti.h"
// EBWCproc
#include "EBWCproc.h"
// EBWCinit
#include "EBWCinit.h"
// EBWCconf
#include "EBWCconf.h"
// EBWCidle
#include "EBWCidle.h"
// EBWCsten
#include "EBWCsten.h"
// EBWCidnt
#include "EBWCidnt.h"
// EBWCemst
#include "EBWCemst.h"
//## begin module%3DD100C8031F.declarations preserve=no
//## end module%3DD100C8031F.declarations

//## begin module%3DD100C8031F.additionalDeclarations preserve=yes
//## end module%3DD100C8031F.additionalDeclarations


// Class CWCStateMachineEngine 

CWCStateMachineEngine::CWCStateMachineEngine (ICOStateMachineContext* p_pContext)
  //## begin CWCStateMachineEngine::CWCStateMachineEngine%1037094242.hasinit preserve=no
  //## end CWCStateMachineEngine::CWCStateMachineEngine%1037094242.hasinit
  //## begin CWCStateMachineEngine::CWCStateMachineEngine%1037094242.initialization preserve=yes
  : CCOStateMachineEngine(p_pContext)
  //## end CWCStateMachineEngine::CWCStateMachineEngine%1037094242.initialization
{
  //## begin CWCStateMachineEngine::CWCStateMachineEngine%1037094242.body preserve=yes
  //## end CWCStateMachineEngine::CWCStateMachineEngine%1037094242.body
}


CWCStateMachineEngine::~CWCStateMachineEngine()
{
  //## begin CWCStateMachineEngine::~CWCStateMachineEngine%.body preserve=yes
  //## end CWCStateMachineEngine::~CWCStateMachineEngine%.body
}



//## Other Operations (implementation)
void CWCStateMachineEngine::BuildStateMachine ()
{
  //## begin CWCStateMachineEngine::BuildStateMachine%1037094244.body preserve=yes
  CWCStateCreated::Create();
  CWCStateConfigNotAssign::Create();
  CWCStateConfigInitDAC::Create();
  CWCStateConfigCalibDACDecCurr::Create();
  CWCStateConfigCalibDACIncCurr::Create();
  CWCStateConfigDACCalibrated::Create();
  CWCStateConfiguration::Create();
  CWCStateConfigProfile::Create();
  CWCStateInitializing::Create();
  CWCStateInitializeStopped::Create();
  CWCStateInitializeReferencing::Create();
  CWCStateProcMeasuring::Create();
  CWCStateProcFollowUpMeasuring::Create();
  CWCStateProcStopping::Create();
  CWCStateProcStarting::Create();
  CWCStateNotConnected::Create();
  CWCStateNotConnectedDuringConfig::Create();
  CWCStateEmergencyStop::Create();
  //## end CWCStateMachineEngine::BuildStateMachine%1037094244.body
}

CCOState* CWCStateMachineEngine::GetInitializeState ()
{
  //## begin CWCStateMachineEngine::GetInitializeState%1042097140.body preserve=yes
  return CWCStateCreated::GetInstance(); // default state subsystem
  //## end CWCStateMachineEngine::GetInitializeState%1042097140.body
}

void CWCStateMachineEngine::CreateActions (CTypedPtrList<CPtrList,CCOAction*>& p_ActionList)
{
  //## begin CWCStateMachineEngine::CreateActions%1037094245.body preserve=yes
  p_ActionList.AddTail(new CWCActionInitialize(IDA_INITIALIZE, m_pContext));
  p_ActionList.AddTail(new CWCActionReferencing(IDA_REFERENCING, m_pContext));
  p_ActionList.AddTail(new CWCActionStopMeasuring(IDA_STOPPING, m_pContext));
  p_ActionList.AddTail(new CWCActionCurrDir(IDA_DAC_CURR_DIR, m_pContext));
  p_ActionList.AddTail(new CWCActionMeasuring(IDA_MEASURING_EXCEPTION, m_pContext));
  //## end CWCStateMachineEngine::CreateActions%1037094245.body
}

void CWCStateMachineEngine::DeleteStateMachine ()
{
  //## begin CWCStateMachineEngine::DeleteStateMachine%1037094243.body preserve=yes
  CWCStateCreated::Delete();
  CWCStateConfigNotAssign::Delete();
  CWCStateConfigInitDAC::Delete();
  CWCStateConfigCalibDACDecCurr::Delete();
  CWCStateConfigCalibDACIncCurr::Delete();
  CWCStateConfigDACCalibrated::Delete();
  CWCStateConfiguration::Delete();
  CWCStateConfigProfile::Delete();
  CWCStateInitializing::Delete();
  CWCStateInitializeStopped::Delete();
  CWCStateInitializeReferencing::Delete();
  CWCStateProcMeasuring::Delete();
  CWCStateProcFollowUpMeasuring::Delete();
  CWCStateProcStopping::Delete();
  CWCStateProcStarting::Delete();
  CWCStateNotConnected::Delete();
  CWCStateNotConnectedDuringConfig::Delete();
  CWCStateEmergencyStop::Delete();
  //## end CWCStateMachineEngine::DeleteStateMachine%1037094243.body
}

// Additional Declarations
  //## begin CWCStateMachineEngine%3DD100ED0031.declarations preserve=yes
  //## end CWCStateMachineEngine%3DD100ED0031.declarations

//## begin module%3DD100C8031F.epilog preserve=yes
//## end module%3DD100C8031F.epilog
