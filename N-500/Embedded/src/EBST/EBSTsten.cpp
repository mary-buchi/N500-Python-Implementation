//## begin module%3DA6C18701B3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA6C18701B3.cm

//## begin module%3DA6C18701B3.cp preserve=no
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
//## end module%3DA6C18701B3.cp

//## Module: EBSTsten%3DA6C18701B3; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTsten.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA6C18701B3.additionalIncludes preserve=no
//## end module%3DA6C18701B3.additionalIncludes

//## begin module%3DA6C18701B3.includes preserve=yes
//## end module%3DA6C18701B3.includes

// EBSTconfig
#include "EBSTconfig.h"
// EBSTmoving
#include "EBSTmoving.h"
// EBSTidle
#include "EBSTidle.h"
// EBSTsten
#include "EBSTsten.h"
// EBSThome
#include "EBSThome.h"
// EBSTactn
#include "EBSTactn.h"
// EBSTconn
#include "EBSTconn.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3DA6C18701B3.declarations preserve=no
//## end module%3DA6C18701B3.declarations

//## begin module%3DA6C18701B3.additionalDeclarations preserve=yes
//## end module%3DA6C18701B3.additionalDeclarations


// Class CSTStateMachineEngine 

CSTStateMachineEngine::CSTStateMachineEngine (ICOStateMachineContext* p_pContext)
  //## begin CSTStateMachineEngine::CSTStateMachineEngine%1034329212.hasinit preserve=no
  //## end CSTStateMachineEngine::CSTStateMachineEngine%1034329212.hasinit
  //## begin CSTStateMachineEngine::CSTStateMachineEngine%1034329212.initialization preserve=yes
  : CCOStateMachineEngine(p_pContext)
  //## end CSTStateMachineEngine::CSTStateMachineEngine%1034329212.initialization
{
  //## begin CSTStateMachineEngine::CSTStateMachineEngine%1034329212.body preserve=yes
  //## end CSTStateMachineEngine::CSTStateMachineEngine%1034329212.body
}


CSTStateMachineEngine::~CSTStateMachineEngine()
{
  //## begin CSTStateMachineEngine::~CSTStateMachineEngine%.body preserve=yes
  //## end CSTStateMachineEngine::~CSTStateMachineEngine%.body
}



//## Other Operations (implementation)
void CSTStateMachineEngine::BuildStateMachine ()
{
  //## begin CSTStateMachineEngine::BuildStateMachine%1034329214.body preserve=yes
	CSTStateCreated::Create();
	CSTStateConfigStart::Create();
	CSTStateConfigConfigSet::Create();
	CSTStateConfigProfileSet::Create();
	CSTStateIdle::Create();
	CSTStateMovingPreparation::Create();
	CSTStateMovingIncreaseSpeed::Create();
	CSTStateMovingRunSpeed::Create();
	CSTStateMovingDecreaseToSearchSpeed::Create();
	CSTStateMovingSearchSpeed::Create();
	CSTStateMovingDecreaseToStop::Create();
	CSTStateMovingEndPosition::Create();
	CSTStateMovingWithStartupSpeed::Create();
	CSTStateConnectionNotConnected::Create();
	CSTStateHomePrepare::Create();
	CSTStateHomeFastFindingLimit::Create();
	CSTStateHomeDeceleratingToStop::Create();
	CSTStateHomeMovingBackToLatchedLimit::Create();
	CSTStateHomeAtLatchedLimit::Create();
	CSTStateHomeLeavingLimit::Create();
	CSTStateHomeSlowlyFindingLimit::Create();
	CSTStateHomeMovingOutOfLimit::Create();
	CSTStateHomeAccelerating::Create();
	CSTStateHomeSlowlyFindingLimitFromOpposite::Create();
  //## end CSTStateMachineEngine::BuildStateMachine%1034329214.body
}

CCOState* CSTStateMachineEngine::GetInitializeState ()
{
  //## begin CSTStateMachineEngine::GetInitializeState%1042097146.body preserve=yes
    return CSTStateCreated::GetInstance();
  //## end CSTStateMachineEngine::GetInitializeState%1042097146.body
}

void CSTStateMachineEngine::CreateActions (CTypedPtrList<CPtrList, CCOAction*>& p_ActionList)
{
  //## begin CSTStateMachineEngine::CreateActions%1034329215.body preserve=yes
	p_ActionList.AddTail(new CSTActionMove(m_pContext));
  //## end CSTStateMachineEngine::CreateActions%1034329215.body
}

void CSTStateMachineEngine::DeleteStateMachine ()
{
  //## begin CSTStateMachineEngine::DeleteStateMachine%1034329213.body preserve=yes
    CSTStateCreated::Delete();
	CSTStateConfigStart::Delete();
	CSTStateConfigConfigSet::Delete();
	CSTStateConfigProfileSet::Delete();
	CSTStateIdle::Delete();
	CSTStateMovingPreparation::Delete();
	CSTStateMovingIncreaseSpeed::Delete();
	CSTStateMovingRunSpeed::Delete();
	CSTStateMovingDecreaseToSearchSpeed::Delete();
	CSTStateMovingSearchSpeed::Delete();
	CSTStateMovingDecreaseToStop::Delete();
	CSTStateMovingEndPosition::Delete();
	CSTStateMovingWithStartupSpeed::Delete();
	CSTStateConnectionNotConnected::Delete();
	CSTStateHomePrepare::Delete();
	CSTStateHomeFastFindingLimit::Delete();
	CSTStateHomeDeceleratingToStop::Delete();
	CSTStateHomeMovingBackToLatchedLimit::Delete();
	CSTStateHomeMovingBackToLatchedLimit::Delete();
	CSTStateHomeAtLatchedLimit::Delete();
	CSTStateHomeLeavingLimit::Delete();
	CSTStateHomeSlowlyFindingLimit::Delete();
	CSTStateHomeMovingOutOfLimit::Delete();
	CSTStateHomeAccelerating::Delete();
	CSTStateHomeSlowlyFindingLimitFromOpposite::Delete();
  //## end CSTStateMachineEngine::DeleteStateMachine%1034329213.body
}

// Additional Declarations
  //## begin CSTStateMachineEngine%3DA6C1A50397.declarations preserve=yes
  //## end CSTStateMachineEngine%3DA6C1A50397.declarations

//## begin module%3DA6C18701B3.epilog preserve=yes
//## end module%3DA6C18701B3.epilog
