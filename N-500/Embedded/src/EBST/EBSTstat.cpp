//## begin module%3DA6C2500099.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA6C2500099.cm

//## begin module%3DA6C2500099.cp preserve=no
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
//## end module%3DA6C2500099.cp

//## Module: EBSTstat%3DA6C2500099; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTstat.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA6C2500099.additionalIncludes preserve=no
//## end module%3DA6C2500099.additionalIncludes

//## begin module%3DA6C2500099.includes preserve=yes
//## end module%3DA6C2500099.includes

// EBCOtype
#include "EBCOtype.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBSTlimit
#include "EBSTlimit.h"
// EBSTstat
#include "EBSTstat.h"
// EBPItype
#include "EBPItype.h"
// EBSTidnt
#include "EBSTidnt.h"
// EBSTimpl
#include "EBSTimpl.h"
// EBSTexcp
#include "EBSTexcp.h"


//## begin module%3DA6C2500099.declarations preserve=no
//## end module%3DA6C2500099.declarations

//## begin module%3DA6C2500099.additionalDeclarations preserve=yes
//## end module%3DA6C2500099.additionalDeclarations


// Class CSTState 

CSTState::CSTState()
  //## begin CSTState::CSTState%.hasinit preserve=no
  //## end CSTState::CSTState%.hasinit
  //## begin CSTState::CSTState%.initialization preserve=yes
  //## end CSTState::CSTState%.initialization
{
  //## begin CSTState::CSTState%.body preserve=yes
  //## end CSTState::CSTState%.body
}


CSTState::~CSTState()
{
  //## begin CSTState::~CSTState%.body preserve=yes
  //## end CSTState::~CSTState%.body
}



//## Other Operations (implementation)
void CSTState::GetPosition (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj)
{
  //## begin CSTState::GetPosition%1034575087.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::GetPosition%1034575087.body
}

void CSTState::MoveAbsolute (ICOStateMachineContext* p_pContext, INT p_iTargetPosition, INT p_iSearchDistance)
{
  //## begin CSTState::MoveAbsolute%1038217297.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::MoveAbsolute%1038217297.body
}

void CSTState::MoveRelative (ICOStateMachineContext* p_pContext, INT p_iTotalDistance, INT p_iSearchDistance)
{
  //## begin CSTState::MoveRelative%1038217298.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::MoveRelative%1038217298.body
}

void CSTState::MoveManual (ICOStateMachineContext* p_pContext, INT p_iEndPosition, INT p_uiSpeed)
{
  //## begin CSTState::MoveManual%1038217299.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::MoveManual%1038217299.body
}

bool CSTState::Stop (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSTState::Stop%1038217300.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::Stop%1038217300.body
}

void CSTState::StopImmediately (ICOStateMachineContext* p_pContext)
{
  //## begin CSTState::StopImmediately%1038217301.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::StopImmediately%1038217301.body
}

void CSTState::SetProfile (ICOStateMachineContext* p_pContext, CPIStepperMotorProfile* p_pProfile)
{
  //## begin CSTState::SetProfile%1038217302.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::SetProfile%1038217302.body
}

void CSTState::LimitAdd (ICOStateMachineContext* p_pContext, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction, CPIObjIdentification* p_pSensor)
{
  //## begin CSTState::LimitAdd%1038217304.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::LimitAdd%1038217304.body
}

void CSTState::LimitConfig (ICOStateMachineContext* p_pContext, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction, CPIObjIdentification* p_pSensor)
{
  //## begin CSTState::LimitConfig%1038217305.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::LimitConfig%1038217305.body
}

void CSTState::LimitActivate (ICOStateMachineContext* p_pContext)
{
  //## begin CSTState::LimitActivate%1038217306.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::LimitActivate%1038217306.body
}

void CSTState::LimitDeactivate (ICOStateMachineContext* p_pContext)
{
  //## begin CSTState::LimitDeactivate%1038217307.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::LimitDeactivate%1038217307.body
}

void CSTState::Home (ICOStateMachineContext* p_pContext, const EPIMotorPolarity p_eFastFindingDirection, const bool p_bSearchLimitFromOpposite, CPIObjIdentification* p_pHomeLimitID, CCOSyncObjectInt* p_pClientSyncObj)
{
  //## begin CSTState::Home%1038217308.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::Home%1038217308.body
}

void CSTState::HomeSetPosition (ICOStateMachineContext* p_pContext, INT p_iPosition)
{
  //## begin CSTState::HomeSetPosition%1038217309.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::HomeSetPosition%1038217309.body
}

void CSTState::LimitGetFootPrint (ICOStateMachineContext* p_pContext, CCOSyncObjectIntArray* p_pClientSyncObj)
{
  //## begin CSTState::LimitGetFootPrint%1038217310.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::LimitGetFootPrint%1038217310.body
}

void CSTState::SetConfig (ICOStateMachineContext* p_pContext, CPIStepperMotorConfig* p_pConfig)
{
  //## begin CSTState::SetConfig%1047647377.body preserve=yes
    XCO_INVALID_STATE(ST_ID);
  //## end CSTState::SetConfig%1047647377.body
}

void CSTState::SetSpeed (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj, UINT p_uiSpeed)
{
  //## begin CSTState::SetSpeed%1047904790.body preserve=yes
    XCO_INVALID_STATE(ST_ID);
  //## end CSTState::SetSpeed%1047904790.body
}

CSTStepperMotorImplementation* CSTState::GetpContext (ICOStateMachineContext* p_pContext)
{
  //## begin CSTState::GetpContext%1048057976.body preserve=yes
	
	//Get instance of implementation by casting the context pointer.
	CSTStepperMotorImplementation* l_pContext;
	l_pContext = dynamic_cast<CSTStepperMotorImplementation*>(p_pContext);
	ASSERT(l_pContext != NULL);
	return l_pContext;

  //## end CSTState::GetpContext%1048057976.body
}

void CSTState::OnLimitHit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID)
{
  //## begin CSTState::OnLimitHit%1048581162.body preserve=yes
	XCO_INVALID_STATE(ST_ID);
  //## end CSTState::OnLimitHit%1048581162.body
}

// Additional Declarations
  //## begin CSTState%3DA6C29E0136.declarations preserve=yes
  //## end CSTState%3DA6C29E0136.declarations

//## begin module%3DA6C2500099.epilog preserve=yes
//## end module%3DA6C2500099.epilog
