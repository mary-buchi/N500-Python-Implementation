//## begin module%3DA6C2660107.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA6C2660107.cm

//## begin module%3DA6C2660107.cp preserve=no
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
//## end module%3DA6C2660107.cp

//## Module: EBSTidle%3DA6C2660107; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTidle.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA6C2660107.additionalIncludes preserve=no
//## end module%3DA6C2660107.additionalIncludes

//## begin module%3DA6C2660107.includes preserve=yes
//## end module%3DA6C2660107.includes

// EBCOimct
#include "EBCOimct.h"
// EBSTlmwk
#include "EBSTlmwk.h"
// EBSTlimit
#include "EBSTlimit.h"
// EBSTlogic
#include "EBSTlogic.h"
// EBSTconfig
#include "EBSTconfig.h"
// EBSTmoving
#include "EBSTmoving.h"
// EBSTcomd
#include "EBSTcomd.h"
// EBSTidle
#include "EBSTidle.h"
// EBPItype
#include "EBPItype.h"
// EBSTidnt
#include "EBSTidnt.h"
// EBSTimpl
#include "EBSTimpl.h"
// EBSThome
#include "EBSThome.h"
// EBSThwconn
#include "EBSThwconn.h"
// EBSTconn
#include "EBSTconn.h"
// EBSTexcp
#include "EBSTexcp.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3DA6C2660107.declarations preserve=no
//## end module%3DA6C2660107.declarations

//## begin module%3DA6C2660107.additionalDeclarations preserve=yes
//## end module%3DA6C2660107.additionalDeclarations


// Class CSTStateCreated 

//## begin CSTStateCreated::pInstance%3DA6C2DA02DC.role preserve=no  public: static CSTStateCreated {1..1 -> 1..1RFHN}
CSTStateCreated *CSTStateCreated::m_pInstance = NULL;
//## end CSTStateCreated::pInstance%3DA6C2DA02DC.role


CSTStateCreated::CSTStateCreated()
  //## begin CSTStateCreated::CSTStateCreated%.hasinit preserve=no
  //## end CSTStateCreated::CSTStateCreated%.hasinit
  //## begin CSTStateCreated::CSTStateCreated%.initialization preserve=yes
  //## end CSTStateCreated::CSTStateCreated%.initialization
{
  //## begin CSTStateCreated::CSTStateCreated%.body preserve=yes
  //## end CSTStateCreated::CSTStateCreated%.body
}


CSTStateCreated::~CSTStateCreated()
{
  //## begin CSTStateCreated::~CSTStateCreated%.body preserve=yes
  //## end CSTStateCreated::~CSTStateCreated%.body
}



//## Other Operations (implementation)
void CSTStateCreated::Create ()
{
  //## begin CSTStateCreated::Create%1034329216.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CSTStateCreated();
  //## end CSTStateCreated::Create%1034329216.body
}

void CSTStateCreated::Delete ()
{
  //## begin CSTStateCreated::Delete%1034329217.body preserve=yes
	if( m_pInstance != NULL )
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CSTStateCreated::Delete%1034329217.body
}

CSTStateCreated* CSTStateCreated::GetInstance ()
{
  //## begin CSTStateCreated::GetInstance%1034329218.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateCreated::GetInstance%1034329218.body
}

void CSTStateCreated::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateCreated::Startup%1034329220.body preserve=yes
	p_pContext->ChangeState(CSTStateConfigStart::GetInstance());
  //## end CSTStateCreated::Startup%1034329220.body
}

void CSTStateCreated::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateCreated::Shutdown%1034449586.body preserve=yes
  //## end CSTStateCreated::Shutdown%1034449586.body
}

void CSTStateCreated::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateCreated::ConnectionEstablished%1063223343.body preserve=yes
  //## end CSTStateCreated::ConnectionEstablished%1063223343.body
}

void CSTStateCreated::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateCreated::ConnectionLost%1063223344.body preserve=yes
  //## end CSTStateCreated::ConnectionLost%1063223344.body
}

// Additional Declarations
  //## begin CSTStateCreated%3DA6C2BD03C6.declarations preserve=yes
  //## end CSTStateCreated%3DA6C2BD03C6.declarations

// Class CSTStateIdle 

//## begin CSTStateIdle::pInstance%3E76C48A0280.role preserve=no  public: static CSTStateIdle {1..1 -> 1..1RFHN}
CSTStateIdle *CSTStateIdle::m_pInstance;
//## end CSTStateIdle::pInstance%3E76C48A0280.role


CSTStateIdle::CSTStateIdle()
  //## begin CSTStateIdle::CSTStateIdle%.hasinit preserve=no
  //## end CSTStateIdle::CSTStateIdle%.hasinit
  //## begin CSTStateIdle::CSTStateIdle%.initialization preserve=yes
  //## end CSTStateIdle::CSTStateIdle%.initialization
{
  //## begin CSTStateIdle::CSTStateIdle%.body preserve=yes
  //## end CSTStateIdle::CSTStateIdle%.body
}


CSTStateIdle::~CSTStateIdle()
{
  //## begin CSTStateIdle::~CSTStateIdle%.body preserve=yes
  //## end CSTStateIdle::~CSTStateIdle%.body
}



//## Other Operations (implementation)
void CSTStateIdle::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateIdle::Shutdown%1047971035.body preserve=yes

	// Housekeeping: Disconnect limit switches from hardware.
	GetpContext(p_pContext)->GetpLimitHandler()->Reset();

	p_pContext->ChangeState(CSTStateCreated::GetInstance());
  //## end CSTStateIdle::Shutdown%1047971035.body
}

void CSTStateIdle::GetPosition (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj)
{
  //## begin CSTStateIdle::GetPosition%1047904776.body preserve=yes
	
	// Pointer to position machine object.
	CSTPositionMachine* l_pPositionMachine = GetpContext(p_pContext)->GetpPositionMachine();
	ASSERT(l_pPositionMachine != NULL);
	
	int l_iPos = l_pPositionMachine->GetiEndPos();
	p_pClientSyncObj->SetValue(l_iPos);
	p_pClientSyncObj->SignalCompletion();

  //## end CSTStateIdle::GetPosition%1047904776.body
}

void CSTStateIdle::MoveAbsolute (ICOStateMachineContext* p_pContext, INT p_iTargetPosition, INT p_iSearchDistance)
{
  //## begin CSTStateIdle::MoveAbsolute%1047904777.body preserve=yes

	// Get pointer to position calculator.
	CSTPositionMachine* l_pPositionMachine = GetpContext(p_pContext)->GetpPositionMachine();
	ASSERT(l_pPositionMachine != NULL);

	// Use methods from position calculator.
	l_pPositionMachine->MoveAbsolute(p_iTargetPosition);
	l_pPositionMachine->SetuiSearchDistance(p_iSearchDistance);

	p_pContext->ChangeState(CSTStateMovingPreparation::GetInstance());
  //## end CSTStateIdle::MoveAbsolute%1047904777.body
}

void CSTStateIdle::MoveRelative (ICOStateMachineContext* p_pContext, INT p_iTotalDistance, INT p_iSearchDistance)
{
  //## begin CSTStateIdle::MoveRelative%1047904778.body preserve=yes
	// Get pointer to position calculator.
	CSTPositionMachine* l_pPositionMachine = GetpContext(p_pContext)->GetpPositionMachine();
	ASSERT(l_pPositionMachine != NULL);

	// Use methods from position calculator.
	l_pPositionMachine->MoveRelative(p_iTotalDistance);
	l_pPositionMachine->SetuiSearchDistance(p_iSearchDistance);

	p_pContext->ChangeState(CSTStateMovingPreparation::GetInstance());
  //## end CSTStateIdle::MoveRelative%1047904778.body
}

void CSTStateIdle::SetProfile (ICOStateMachineContext* p_pContext, CPIStepperMotorProfile* p_pProfile)
{
  //## begin CSTStateIdle::SetProfile%1047904779.body preserve=yes
	GetpContext(p_pContext)->SetpProfile(p_pProfile);
	ASSERT(p_pProfile != NULL);

	// Reset speedrate to 100%
	GetpContext(p_pContext)->GetpLogic()->AjustActualSpeed(100);

	p_pContext->ChangeState(CSTStateConfigProfileSet::GetInstance());
  //## end CSTStateIdle::SetProfile%1047904779.body
}

void CSTStateIdle::SetSpeed (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj, UINT p_uiSpeed)
{
  //## begin CSTStateIdle::SetSpeed%1038217303.body preserve=yes
	
	// Save old speed to syncronisation object.
	p_pClientSyncObj->SetValue(GetpContext(p_pContext)->GetpLogic()->GetdwSpeedRateOld());

	// Calculate new speed.
	GetpContext(p_pContext)->GetpLogic()->AjustActualSpeed(p_uiSpeed);

	//
	p_pClientSyncObj->SignalCompletion();

  //## end CSTStateIdle::SetSpeed%1038217303.body
}

void CSTStateIdle::LimitAdd (ICOStateMachineContext* p_pContext, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction, CPIObjIdentification* p_pSensor)
{
  //## begin CSTStateIdle::LimitAdd%1047904780.body preserve=yes
	GetpContext(p_pContext)->GetpLimitHandler()->Add(p_pSensor, p_eLimitCharacteristics, p_eLimitAction);
  //## end CSTStateIdle::LimitAdd%1047904780.body
}

void CSTStateIdle::LimitActivate (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateIdle::LimitActivate%1047904782.body preserve=yes
	GetpContext(p_pContext)->GetpLimitHandler()->Activate();
  //## end CSTStateIdle::LimitActivate%1047904782.body
}

void CSTStateIdle::LimitDeactivate (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateIdle::LimitDeactivate%1047904783.body preserve=yes
	GetpContext(p_pContext)->GetpLimitHandler()->Deactivate();
  //## end CSTStateIdle::LimitDeactivate%1047904783.body
}

void CSTStateIdle::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateIdle::Startup%1066295284.body preserve=yes
	p_pContext->ChangeState(CSTStateConfigStart::GetInstance());
  //## end CSTStateIdle::Startup%1066295284.body
}

void CSTStateIdle::HomeSetPosition (ICOStateMachineContext* p_pContext, INT p_iPosition)
{
  //## begin CSTStateIdle::HomeSetPosition%1047904785.body preserve=yes

	// Motor stays on endposition. Home position is new end position.
	GetpContext(p_pContext)->GetpPositionMachine()->SetiEndPos(p_iPosition);

  //## end CSTStateIdle::HomeSetPosition%1047904785.body
}

void CSTStateIdle::LimitGetFootPrint (ICOStateMachineContext* p_pContext, CCOSyncObjectIntArray* p_pClientSyncObj)
{
  //## begin CSTStateIdle::LimitGetFootPrint%1047904786.body preserve=yes

	// Declare new array.
	CArray<INT, INT>* l_pArray= GetpContext(p_pContext)->GetpLimitHandler()->GetFootprint();
	
	// Add array to sync object.
	p_pClientSyncObj->SetValue(new CCOIntegerArray(*l_pArray));
	delete l_pArray;

	// Signal the sync object.
	p_pClientSyncObj->SignalCompletion();

  //## end CSTStateIdle::LimitGetFootPrint%1047904786.body
}

void CSTStateIdle::Create ()
{
  //## begin CSTStateIdle::Create%1047971032.body preserve=yes
	m_pInstance = new CSTStateIdle();
  //## end CSTStateIdle::Create%1047971032.body
}

void CSTStateIdle::Delete ()
{
  //## begin CSTStateIdle::Delete%1047971033.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CSTStateIdle::Delete%1047971033.body
}

CSTStateIdle* CSTStateIdle::GetInstance ()
{
  //## begin CSTStateIdle::GetInstance%1047971034.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateIdle::GetInstance%1047971034.body
}

void CSTStateIdle::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateIdle::Do%1047971036.body preserve=yes

	CCOSyncObject *l_pSyncObject = NULL;
	DWORD l_dwId = 0;

	GetpContext(p_pContext)->GetpPositionMachine()->TrackPosition();

	// Stop worker thread limit switches.
	GetpContext(p_pContext)->GetpLimitHandler()->Stop();

	// Stop the motor.
	GetpContext(p_pContext)->GetpHwConnection()->Stoping();

	// get pointer to hardware connection
	l_pSyncObject = GetpContext(p_pContext)->GetpHwConnection()->GetpMovingEvent();
	l_dwId = GetpContext(p_pContext)->GetpConfig()->GetdwIDMovingTerminationEvent();

	// close moving event, if he is open
	if( l_pSyncObject != NULL )
		IHIInterface::GetInstance()->CloseEvent( l_dwId, l_pSyncObject );

	GetpContext(p_pContext)->GetpHwConnection()->SetpMovingEvent( NULL );

	// limit exception?
	bool l_bLimitHit = GetpContext(p_pContext)->GetpLogic()->GetbLimitHit();
	if( l_bLimitHit )
	{
		// reset bit
		GetpContext(p_pContext)->GetpLogic()->SetbLimitHit(false);

		// Exception.
		CString l_sTrace;
		l_sTrace.Format(_T("Exception in file: %s line: %d. Limit hit."),_T(__FILE__), __LINE__);
		CO_TRACE(ST_ID, l_sTrace);
		throw new XSTExceptionLimit(ST_ID, IDE_ST_HARD_LIMIT_HIT, _T(__FILE__), __LINE__, 0);
	}

  //## end CSTStateIdle::Do%1047971036.body
}

void CSTStateIdle::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateIdle::Enter%1048757601.body preserve=yes

	// Resets all actions, which are not finished.
	p_pContext->GetpStateMachineEngine()->Cleanup();

  //## end CSTStateIdle::Enter%1048757601.body
}

void CSTStateIdle::StopImmediately (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateIdle::StopImmediately%1048771776.body preserve=yes
	CO_TRACE(ST_ID,_T("ST State Idle - StopImmediately() executed (it's an empty function...)\n"));
  //## end CSTStateIdle::StopImmediately%1048771776.body
}

bool CSTStateIdle::Stop (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSTStateIdle::Stop%1048771777.body preserve=yes
	CO_TRACE(ST_ID,_T("ST State Idle - Stop() executed (it's an empty function...)\n"));
	return true;
  //## end CSTStateIdle::Stop%1048771777.body
}

void CSTStateIdle::LimitConfig (ICOStateMachineContext* p_pContext, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction, CPIObjIdentification* p_pSensor)
{
  //## begin CSTStateIdle::LimitConfig%1048771779.body preserve=yes
	GetpContext(p_pContext)->GetpLimitHandler()->Config(p_pSensor, p_eLimitCharacteristics, p_eLimitAction);
  //## end CSTStateIdle::LimitConfig%1048771779.body
}

void CSTStateIdle::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateIdle::CleanupInitialize%1053438560.body preserve=yes
	p_pContext->ChangeState(this);
  //## end CSTStateIdle::CleanupInitialize%1053438560.body
}

void CSTStateIdle::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateIdle::ConnectionLost%1055922856.body preserve=yes
	p_pContext->ChangeState(CSTStateConnectionNotConnected::GetInstance());
  //## end CSTStateIdle::ConnectionLost%1055922856.body
}

void CSTStateIdle::Home (ICOStateMachineContext* p_pContext, const EPIMotorPolarity p_eFastFindingDirection, const bool p_bSearchLimitFromOpposite, CPIObjIdentification* p_pHomeLimitID, CCOSyncObjectInt* p_pClientSyncObj)
{
  //## begin CSTStateIdle::Home%1069341917.body preserve=yes
	GetpContext(p_pContext)->SetpHomeSyncObj(p_pClientSyncObj);
	GetpContext(p_pContext)->GetpPositionMachine()->SeteFastFindingDirection(p_eFastFindingDirection);
	GetpContext(p_pContext)->GetpPositionMachine()->SetbSearchLimitFromOpposite(p_bSearchLimitFromOpposite);
	GetpContext(p_pContext)->GetpLimitHandler()->SetpHomeLimitID(p_pHomeLimitID);
	p_pHomeLimitID->ReleaseRef();

	// p_pContext->ChangeState(CSTStateHomingPreparation::GetInstance());
	p_pContext->ChangeState(CSTStateHomePrepare::GetInstance());

  //## end CSTStateIdle::Home%1069341917.body
}

// Additional Declarations
  //## begin CSTStateIdle%3E71A0870118.declarations preserve=yes
  //## end CSTStateIdle%3E71A0870118.declarations

//## begin module%3DA6C2660107.epilog preserve=yes
//## end module%3DA6C2660107.epilog
