//## begin module%4341377602C0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%4341377602C0.cm

//## begin module%4341377602C0.cp preserve=no
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
//## end module%4341377602C0.cp

//## Module: EBSThome%4341377602C0; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSThome.cpp

// stdafx
#include "stdafx.h"
//## begin module%4341377602C0.additionalIncludes preserve=no
//## end module%4341377602C0.additionalIncludes

//## begin module%4341377602C0.includes preserve=yes
//## end module%4341377602C0.includes

// EBCOimct
#include "EBCOimct.h"
// EBSTconn
#include "EBSTconn.h"
// EBSTexcp
#include "EBSTexcp.h"
// EBSTlmwk
#include "EBSTlmwk.h"
// EBSTlimit
#include "EBSTlimit.h"
// EBSTlogic
#include "EBSTlogic.h"
// EBPItype
#include "EBPItype.h"
// EBSThome
#include "EBSThome.h"
// EBSTactn
#include "EBSTactn.h"
// EBSThwconn
#include "EBSThwconn.h"
// EBSTidle
#include "EBSTidle.h"
// EBSTidnt
#include "EBSTidnt.h"
// EBSTimpl
#include "EBSTimpl.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%4341377602C0.declarations preserve=no
//## end module%4341377602C0.declarations

//## begin module%4341377602C0.additionalDeclarations preserve=yes
//## end module%4341377602C0.additionalDeclarations


// Class CSTStateHome 


CSTStateHome::CSTStateHome()
  //## begin CSTStateHome::CSTStateHome%.hasinit preserve=no
  //## end CSTStateHome::CSTStateHome%.hasinit
  //## begin CSTStateHome::CSTStateHome%.initialization preserve=yes
  //## end CSTStateHome::CSTStateHome%.initialization
{
  //## begin CSTStateHome::CSTStateHome%.body preserve=yes
  //## end CSTStateHome::CSTStateHome%.body
}


CSTStateHome::~CSTStateHome()
{
  //## begin CSTStateHome::~CSTStateHome%.body preserve=yes
  //## end CSTStateHome::~CSTStateHome%.body
}



//## Other Operations (implementation)
void CSTStateHome::StopImmediately (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateHome::StopImmediately%1047904774.body preserve=yes
	p_pContext->ChangeState(CSTStateIdle::GetInstance());
  //## end CSTStateHome::StopImmediately%1047904774.body
}

void CSTStateHome::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateHome::CleanupInitialize%1053438562.body preserve=yes
	CSTLimitHandler* l_pLimitHandler = GetpContext(p_pContext)->GetpLimitHandler();
	CSTLimitSwitch* l_pLimit = l_pLimitHandler->FindLimitSwitch(l_pLimitHandler->GetpHomeLimitID());
	l_pLimit->RestoreOriginalCharacteristics();
	GetpContext(p_pContext)->SetpHomeSyncObj(NULL);

	p_pContext->ChangeState(CSTStateIdle::GetInstance());
  //## end CSTStateHome::CleanupInitialize%1053438562.body
}

void CSTStateHome::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateHome::ConnectionLost%1055922859.body preserve=yes
	p_pContext->ChangeState(CSTStateConnectionNotConnected::GetInstance());
  //## end CSTStateHome::ConnectionLost%1055922859.body
}

void CSTStateHome::OnLimitHit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID)
{
  //## begin CSTStateHome::OnLimitHit%1065684032.body preserve=yes
	// Save limit switch ID to implementation.
	GetpContext(p_pContext)->GetpLimitHandler()->SetpLimitSwitchIDHit(p_pLimitID);
  //## end CSTStateHome::OnLimitHit%1065684032.body
}

bool CSTStateHome::OnSoftLimit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID)
{
  //## begin CSTStateHome::OnSoftLimit%1065684033.body preserve=yes

	return true;
  //## end CSTStateHome::OnSoftLimit%1065684033.body
}

bool CSTStateHome::OnHardLimit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID)
{
  //## begin CSTStateHome::OnHardLimit%1065684034.body preserve=yes

		return true;
  //## end CSTStateHome::OnHardLimit%1065684034.body
}

// Additional Declarations
  //## begin CSTStateHome%3E71A0AC0203.declarations preserve=yes
  //## end CSTStateHome%3E71A0AC0203.declarations

// Class CSTStateHomePrepare 

//## begin CSTStateHomePrepare::pInstance%4341383401B6.role preserve=no  public: static CSTStateHomePrepare {1..1 -> 1..1RFHN}
CSTStateHomePrepare *CSTStateHomePrepare::m_pInstance = NULL;
//## end CSTStateHomePrepare::pInstance%4341383401B6.role


CSTStateHomePrepare::CSTStateHomePrepare()
  //## begin CSTStateHomePrepare::CSTStateHomePrepare%.hasinit preserve=no
  //## end CSTStateHomePrepare::CSTStateHomePrepare%.hasinit
  //## begin CSTStateHomePrepare::CSTStateHomePrepare%.initialization preserve=yes
  //## end CSTStateHomePrepare::CSTStateHomePrepare%.initialization
{
  //## begin CSTStateHomePrepare::CSTStateHomePrepare%.body preserve=yes
  //## end CSTStateHomePrepare::CSTStateHomePrepare%.body
}


CSTStateHomePrepare::~CSTStateHomePrepare()
{
  //## begin CSTStateHomePrepare::~CSTStateHomePrepare%.body preserve=yes
  //## end CSTStateHomePrepare::~CSTStateHomePrepare%.body
}



//## Other Operations (implementation)
void CSTStateHomePrepare::Create ()
{
  //## begin CSTStateHomePrepare::Create%1128347816.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSTStateHomePrepare();
  //## end CSTStateHomePrepare::Create%1128347816.body
}

void CSTStateHomePrepare::Delete ()
{
  //## begin CSTStateHomePrepare::Delete%1128347817.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSTStateHomePrepare::Delete%1128347817.body
}

CSTStateHomePrepare* CSTStateHomePrepare::GetInstance ()
{
  //## begin CSTStateHomePrepare::GetInstance%1128347818.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSTStateHomePrepare::GetInstance%1128347818.body
}

void CSTStateHomePrepare::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateHomePrepare::Do%1128347819.body preserve=yes
	GetpContext(p_pContext)->GetpHwConnection()->StartHoming(GetpContext(p_pContext)->GetpPositionMachine()->GetiEndPos());

	// Reset position machine.
	GetpContext(p_pContext)->GetpPositionMachine()->Reset();

	GetpContext(p_pContext)->GetpLogic()->SetdbBaseTimeLimit(0);
	CSTLimitHandler* l_pLimitHandler = GetpContext(p_pContext)->GetpLimitHandler();
	CSTLimitSwitch* l_pLimit = l_pLimitHandler->FindLimitSwitch(l_pLimitHandler->GetpHomeLimitID());

	l_pLimit->RestoreOriginalCharacteristics();
	bool l_bIsAtHome = l_pLimitHandler->IsAtHome();
	if (!l_bIsAtHome)
	{
		// Start limit handler worker thread.
		l_pLimit->RestoreOriginalCharacteristics();
		l_pLimitHandler->Activate();
		l_pLimitHandler->Start();

		// just start accelerating
		p_pContext->ChangeState(CSTStateHomeAccelerating::GetInstance());
	}
	else
	{
		// move out of the limit
		l_pLimit->ActivateReverseCharacteristics();
		l_pLimitHandler->Activate();
		l_pLimitHandler->Start();

		CSTActionMove* l_pAction = (CSTActionMove*)p_pContext->GetAction(IDA_MOVE);
		l_pAction->SetdwSpeed(GetpContext(p_pContext)->GetpProfile()->GetuiSpeedStartup());
		l_pAction->SetdwSteps(CONTINUOUS);

		// Set steps.
		switch (GetpContext(p_pContext)->GetpPositionMachine()->GeteFastFindingDirection())	
		{
			case ePIMotorPolarityNormal:
				GetpContext(p_pContext)->GetpPositionMachine()->MoveRelative(-CONTINUOUS);
				break;

			case ePIMotorPolarityReverse:
				GetpContext(p_pContext)->GetpPositionMachine()->MoveRelative(CONTINUOUS);
				break;

			default:
				ASSERT(false);
		}

		p_pContext->ChangeState(CSTStateHomeMovingOutOfLimit::GetInstance(), l_pAction);
	}
  //## end CSTStateHomePrepare::Do%1128347819.body
}

// Additional Declarations
  //## begin CSTStateHomePrepare%4341371702C4.declarations preserve=yes
  //## end CSTStateHomePrepare%4341371702C4.declarations

// Class CSTStateHomeFastFindingLimit 

//## begin CSTStateHomeFastFindingLimit::pInstance%4341386D0243.role preserve=no  public: static CSTStateHomeFastFindingLimit {1..1 -> 1..1RFHN}
CSTStateHomeFastFindingLimit *CSTStateHomeFastFindingLimit::m_pInstance = NULL;
//## end CSTStateHomeFastFindingLimit::pInstance%4341386D0243.role


CSTStateHomeFastFindingLimit::CSTStateHomeFastFindingLimit()
  //## begin CSTStateHomeFastFindingLimit::CSTStateHomeFastFindingLimit%.hasinit preserve=no
  //## end CSTStateHomeFastFindingLimit::CSTStateHomeFastFindingLimit%.hasinit
  //## begin CSTStateHomeFastFindingLimit::CSTStateHomeFastFindingLimit%.initialization preserve=yes
  //## end CSTStateHomeFastFindingLimit::CSTStateHomeFastFindingLimit%.initialization
{
  //## begin CSTStateHomeFastFindingLimit::CSTStateHomeFastFindingLimit%.body preserve=yes
  //## end CSTStateHomeFastFindingLimit::CSTStateHomeFastFindingLimit%.body
}


CSTStateHomeFastFindingLimit::~CSTStateHomeFastFindingLimit()
{
  //## begin CSTStateHomeFastFindingLimit::~CSTStateHomeFastFindingLimit%.body preserve=yes
  //## end CSTStateHomeFastFindingLimit::~CSTStateHomeFastFindingLimit%.body
}



//## Other Operations (implementation)
void CSTStateHomeFastFindingLimit::Create ()
{
  //## begin CSTStateHomeFastFindingLimit::Create%1128347820.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSTStateHomeFastFindingLimit();
  //## end CSTStateHomeFastFindingLimit::Create%1128347820.body
}

void CSTStateHomeFastFindingLimit::Delete ()
{
  //## begin CSTStateHomeFastFindingLimit::Delete%1128347821.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSTStateHomeFastFindingLimit::Delete%1128347821.body
}

CSTStateHomeFastFindingLimit* CSTStateHomeFastFindingLimit::GetInstance ()
{
  //## begin CSTStateHomeFastFindingLimit::GetInstance%1128347822.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSTStateHomeFastFindingLimit::GetInstance%1128347822.body
}

void CSTStateHomeFastFindingLimit::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateHomeFastFindingLimit::Do%1128347823.body preserve=yes
	// Get hardware present.
	bool l_bHardwarePresent = GetpContext(p_pContext)->GetpHwConnection()->GetbHardwarePresent();			

	DWORD l_dwTimeout = GetpContext(p_pContext)->GetpConfig()->GetdwHomingTimeout();
	ASSERT(l_dwTimeout > 0);

	// New object.
	CCOSyncObjectPtr l_pSyncObj = new CCOSyncObject(_T("ST:StateFastFindingLimit"));

	ECOInterruptReason	l_eReason = p_pContext->WaitOnActionDone(
			l_pSyncObj, 
			CO_WAKE_MASK_CMD_ABOVE_NORMAL + CO_WAKE_MASK_CMD_HIGH + CO_WAKE_MASK_ACTIONS_ALL, 
			l_dwTimeout);

	switch(l_eReason)
	{
		case eIRCmdAboveNormal:
			{
				// Limit hit. Kind of limit? Do we have to exit? ChangeState(this). Get limit switch ID which was hit.
				CPIObjIdentification* l_pObjectIdent = GetpContext(p_pContext)->GetpLimitHandler()->GetpLimitSwitchIDHit();

				// Get limit switch which was hit.
				CSTLimitSwitch* l_pLimitSwitch = GetpContext(p_pContext)->GetpLimitHandler()->FindLimitSwitch(l_pObjectIdent);

				// LimitSwitch characteristics.
				EPILimitCharacteristics l_eLimitCharacter = l_pLimitSwitch->GeteCurLimitCharacteristics();

				switch (l_eLimitCharacter)
				{
					case ePILimitSoftEdgeFalling:
					case ePILimitSoftEdgeRaising:
						// Soft limit hit.
						ASSERT(false);
						break;

					case ePILimitHardEdgeFalling:
					case ePILimitHardEdgeRaising:
						{
							// Home sensor hit.
							CO_TRACE(ST_ID,_T("Home sensor hit."));

							// keep current position
							GetpContext(p_pContext)->GetpLogic()->SetiHomingLatchedPosition(
								GetpContext(p_pContext)->GetpHwConnection()->GetRelativePos());

							// Change state.
							p_pContext->ChangeState(CSTStateHomeDeceleratingToStop::GetInstance());	
						}
						break;

					default:
						ASSERT(false);
				}
			}
			break;

		case eIRCmdHigh:
			// l_pAction->Done();
			// Stop Abort Suspend-resume -> Exit
			break;

		case eIRActionsDone:
		case eIRTimeout:
			{
				// Time out. Home sensor not reached.
				if (l_bHardwarePresent)
				{	
					CO_TRACE(ST_ID,_T("Time out. Home sensor not found.\n"));
					CString l_strMsg(_T(""));
					l_strMsg.Format(_T(" Exception in File: %s, Line: %d, Error: %d\n"), _T(__FILE__), __LINE__, 0);
					CO_TRACE(ST_ID,l_strMsg);
					throw new XSTExcepitonHomingSensorNotFound(ST_ID, IDE_ST_HOMING_SENSOR_NOT_FOUND, _T(__FILE__), __LINE__, 0);
				}
				else
				{
					// Stop moving.
					GetpContext(p_pContext)->GetpHwConnection()->Stoping();
					GetpContext(p_pContext)->GetpPositionMachine()->TrackPosition();
					p_pContext->ChangeState(CSTStateHomeAtLatchedLimit::GetInstance());
				}

			}
			break;

		default:
			ASSERT(false);
			break;
	}

  //## end CSTStateHomeFastFindingLimit::Do%1128347823.body
}

// Additional Declarations
  //## begin CSTStateHomeFastFindingLimit%434137230271.declarations preserve=yes
  //## end CSTStateHomeFastFindingLimit%434137230271.declarations

// Class CSTStateHomeMovingBackToLatchedLimit 

//## begin CSTStateHomeMovingBackToLatchedLimit::pInstance%4341387201D2.role preserve=no  public: static CSTStateHomeMovingBackToLatchedLimit {1..1 -> 1..1RFHN}
CSTStateHomeMovingBackToLatchedLimit *CSTStateHomeMovingBackToLatchedLimit::m_pInstance = NULL;
//## end CSTStateHomeMovingBackToLatchedLimit::pInstance%4341387201D2.role


CSTStateHomeMovingBackToLatchedLimit::CSTStateHomeMovingBackToLatchedLimit()
  //## begin CSTStateHomeMovingBackToLatchedLimit::CSTStateHomeMovingBackToLatchedLimit%.hasinit preserve=no
  //## end CSTStateHomeMovingBackToLatchedLimit::CSTStateHomeMovingBackToLatchedLimit%.hasinit
  //## begin CSTStateHomeMovingBackToLatchedLimit::CSTStateHomeMovingBackToLatchedLimit%.initialization preserve=yes
  //## end CSTStateHomeMovingBackToLatchedLimit::CSTStateHomeMovingBackToLatchedLimit%.initialization
{
  //## begin CSTStateHomeMovingBackToLatchedLimit::CSTStateHomeMovingBackToLatchedLimit%.body preserve=yes
  //## end CSTStateHomeMovingBackToLatchedLimit::CSTStateHomeMovingBackToLatchedLimit%.body
}


CSTStateHomeMovingBackToLatchedLimit::~CSTStateHomeMovingBackToLatchedLimit()
{
  //## begin CSTStateHomeMovingBackToLatchedLimit::~CSTStateHomeMovingBackToLatchedLimit%.body preserve=yes
  //## end CSTStateHomeMovingBackToLatchedLimit::~CSTStateHomeMovingBackToLatchedLimit%.body
}



//## Other Operations (implementation)
void CSTStateHomeMovingBackToLatchedLimit::Create ()
{
  //## begin CSTStateHomeMovingBackToLatchedLimit::Create%1128347824.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSTStateHomeMovingBackToLatchedLimit();
  //## end CSTStateHomeMovingBackToLatchedLimit::Create%1128347824.body
}

void CSTStateHomeMovingBackToLatchedLimit::Delete ()
{
  //## begin CSTStateHomeMovingBackToLatchedLimit::Delete%1128347825.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSTStateHomeMovingBackToLatchedLimit::Delete%1128347825.body
}

CSTStateHomeMovingBackToLatchedLimit* CSTStateHomeMovingBackToLatchedLimit::GetInstance ()
{
  //## begin CSTStateHomeMovingBackToLatchedLimit::GetInstance%1128347826.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSTStateHomeMovingBackToLatchedLimit::GetInstance%1128347826.body
}

void CSTStateHomeMovingBackToLatchedLimit::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateHomeMovingBackToLatchedLimit::Do%1128347827.body preserve=yes
	CSTActionMove* l_pAction = (CSTActionMove*)p_pContext->GetAction(IDA_MOVE);
	ECOInterruptReason l_eReason = p_pContext->WaitOnActionDone(
		l_pAction->GetpServerSyncObj(), 
		CO_WAKE_MASK_CMD_ABOVE_NORMAL+CO_WAKE_MASK_CMD_HIGH+CO_WAKE_MASK_ACTIONS_ALL);
	if (l_eReason == eIRActionsDone)
	{
		l_pAction->Done();

		GetpContext(p_pContext)->GetpHwConnection()->TrackHomingSteps();

		CSTPositionMachine* l_pPos = GetpContext(p_pContext)->GetpPositionMachine();
		CSTLimitHandler* l_pLimitHandler = GetpContext(p_pContext)->GetpLimitHandler();
		if (!l_pLimitHandler->IsAtHome())
		{
			// limit not found
			CCOSyncObjectPtr l_pSyncObj;
			int l_iStep = l_pPos->GetePolarity() == ePIMotorPolarityNormal ? 1 : -1;
			l_pPos->Reset();

			CSTHardwareConnection* l_pHWCon = GetpContext(p_pContext)->GetpHwConnection();
			double l_dSpeed = GetpContext(p_pContext)->GetpProfile()->GetuiSpeedHome();
			l_pHWCon->SetVelocity((DWORD)l_dSpeed);

			DWORD l_dwAxisPlay = GetpContext(p_pContext)->GetpConfig()->GetdwAxisPlay();

			DWORD l_dwMoveEventID = GetpContext(p_pContext)->GetpConfig()->GetdwIDMovingTerminationEvent();
			l_pSyncObj = IHIInterface::GetInstance()->OpenEvent(l_dwMoveEventID, eHIUndefined );

			bool l_bLimitFound = false;
			int l_iStepCnt = 0;
			do
			{
				l_pPos->MoveRelative(l_iStep);
				l_pHWCon->Moving(1);
				l_pSyncObj->Synchronize();
				l_pSyncObj->ResetCompletion();

				GetpContext(p_pContext)->GetpHwConnection()->TrackHomingSteps();

				if (l_pLimitHandler->IsAtHome())
					l_bLimitFound = true;

			} while (!l_bLimitFound &&
					 l_iStepCnt++ < (int)(2*l_dwAxisPlay));

			if (l_bLimitFound)
			{
				// add two extra steps to stabalize the sensor state
				l_pPos->MoveRelative(2*l_iStep);
				l_pHWCon->Moving(2);
				l_pSyncObj->Synchronize();
				l_pSyncObj->ResetCompletion();

				GetpContext(p_pContext)->GetpHwConnection()->TrackHomingSteps();
			}

			IHIInterface::GetInstance()->CloseEvent(l_dwMoveEventID, l_pSyncObj);

			if (!l_bLimitFound)
			{
				// limit not found
				throw new XSTExcepitonHomingSensorNotFound(ST_ID, IDE_ST_HOMING_SENSOR_NOT_FOUND, _T(__FILE__), __LINE__, 0);
			}
		}

		p_pContext->ChangeState(CSTStateHomeAtLatchedLimit::GetInstance());
	}
	else
	{
		ASSERT(FALSE);
	}
  //## end CSTStateHomeMovingBackToLatchedLimit::Do%1128347827.body
}

// Additional Declarations
  //## begin CSTStateHomeMovingBackToLatchedLimit%4341374B014C.declarations preserve=yes
  //## end CSTStateHomeMovingBackToLatchedLimit%4341374B014C.declarations

// Class CSTStateHomeDeceleratingToStop 

//## begin CSTStateHomeDeceleratingToStop::pInstance%4341427A0262.role preserve=no  public: static CSTStateHomeDeceleratingToStop { -> 1..1RFHN}
CSTStateHomeDeceleratingToStop *CSTStateHomeDeceleratingToStop::m_pInstance = NULL;
//## end CSTStateHomeDeceleratingToStop::pInstance%4341427A0262.role


CSTStateHomeDeceleratingToStop::CSTStateHomeDeceleratingToStop()
  //## begin CSTStateHomeDeceleratingToStop::CSTStateHomeDeceleratingToStop%.hasinit preserve=no
  //## end CSTStateHomeDeceleratingToStop::CSTStateHomeDeceleratingToStop%.hasinit
  //## begin CSTStateHomeDeceleratingToStop::CSTStateHomeDeceleratingToStop%.initialization preserve=yes
  //## end CSTStateHomeDeceleratingToStop::CSTStateHomeDeceleratingToStop%.initialization
{
  //## begin CSTStateHomeDeceleratingToStop::CSTStateHomeDeceleratingToStop%.body preserve=yes
  //## end CSTStateHomeDeceleratingToStop::CSTStateHomeDeceleratingToStop%.body
}


CSTStateHomeDeceleratingToStop::~CSTStateHomeDeceleratingToStop()
{
  //## begin CSTStateHomeDeceleratingToStop::~CSTStateHomeDeceleratingToStop%.body preserve=yes
  //## end CSTStateHomeDeceleratingToStop::~CSTStateHomeDeceleratingToStop%.body
}



//## Other Operations (implementation)
void CSTStateHomeDeceleratingToStop::Create ()
{
  //## begin CSTStateHomeDeceleratingToStop::Create%1128347828.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSTStateHomeDeceleratingToStop();
  //## end CSTStateHomeDeceleratingToStop::Create%1128347828.body
}

void CSTStateHomeDeceleratingToStop::Delete ()
{
  //## begin CSTStateHomeDeceleratingToStop::Delete%1128347829.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSTStateHomeDeceleratingToStop::Delete%1128347829.body
}

CSTStateHomeDeceleratingToStop* CSTStateHomeDeceleratingToStop::GetInstance ()
{
  //## begin CSTStateHomeDeceleratingToStop::GetInstance%1128347830.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSTStateHomeDeceleratingToStop::GetInstance%1128347830.body
}

void CSTStateHomeDeceleratingToStop::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateHomeDeceleratingToStop::Do%1128347831.body preserve=yes
	// Synchronisation object smart pointer.
	CCOSyncObjectPtr l_pSyncObj = NULL; 
	try
	{
		// New object.
		l_pSyncObj = new CCOSyncObject(_T("ST:StateHomeDeceleratingToStop"));

		// Pointer to implementation.
		CSTStepperMotorImplementation *l_pImplementation= GetpContext(p_pContext);
		ASSERT(l_pImplementation != NULL);

		// Pointer to logic.
		CSTLogic *l_pLogic = l_pImplementation->GetpLogic();
		ASSERT(l_pLogic != NULL);

		CPIStepperMotorProfile* l_pProfile = l_pImplementation->GetpProfile();
		const double l_dSpeedAfterAcceleration = l_pLogic->GetdbSpeedAfterAcceleration();

		// Get timeout from config.
		const double l_dt = (double)l_pImplementation->GetpConfig()->GetuiSamplingTime()/1000.0;
		const double l_da = -(double)l_pProfile->GetuiNomAccDec();
		// const double l_dvo = l_pLogic->GetdbVEnd() + l_pLogic->GetDeltaSpeed(l_da);

		const double l_dvo = l_dSpeedAfterAcceleration + l_da * l_dt;

		const double l_dt1 = ((double)l_pProfile->GetuiSpeedStartup() - l_dSpeedAfterAcceleration)/l_da;
		const DWORD  l_dwIterations = (DWORD)abs((int)(l_dt1/l_dt)-1);
		const double l_dDeltaT = l_dt1 / l_dwIterations;
		DWORD l_dwItCount = 0;

        CString l_sStr;
        
        l_sStr.Format(_T("CSTStateHomeDeceleratingToStop: SpeedAfterAcceleration=%f, l_dt=%f,l_da=%f,l_dvo=%f,l_dt1=%f,l_dwInterations=%d,l_dDeltaT=%f\n"),
            l_dSpeedAfterAcceleration, l_dt, l_da, l_dvo,l_dt1,l_dwIterations, l_dDeltaT);
        CO_TRACE(ST_ID, (LPCTSTR)l_sStr);

        l_sStr.Format(_T("CSTStateHomeDeceleratingToStop: SpeedHome=%d,SpeedStartup=%d,SpeedSearch=%d,Speed=%d,NomAcc=%d"),
            l_pProfile->GetuiSpeedHome(), l_pProfile->GetuiSpeedStartup(), l_pProfile->GetuiSpeedSearch(), l_pProfile->GetuiSpeed(), l_pProfile->GetuiNomAccDec());
        CO_TRACE(ST_ID, (LPCTSTR)l_sStr);

		// State if false.
		bool l_bHighPrioCmd = false;

		// disable any limits
		CSTLimitHandler* l_pLimitHandler = l_pImplementation->GetpLimitHandler();
		l_pLimitHandler->Stop();
		l_pLimitHandler->Deactivate();
		l_pLimitHandler->Start();

		// Increase motor velocity.
		l_pLogic->SetTimeBaseToNow();
		CO_TRACE(ST_ID, _T("Starting Decceleration"));

		double l_dSpeed = 0;
		do
		{
			double l_dwDeltaSpeed = (double)l_dwItCount*l_dDeltaT*l_da;
			l_dSpeed = l_dvo + l_dwDeltaSpeed;
			
			GetpContext(p_pContext)->GetpHwConnection()->SetVelocity(l_dSpeed);
			GetpContext(p_pContext)->GetpHwConnection()->SetValid(eVelocityValid);

			// CO_TRACE1(ST_ID, _T("Descreasing speed : %d \n"), (DWORD)l_dSpeed);

			ECOInterruptReason l_eReason = eIRTimeout;
			// nominal timeout

            DWORD l_dwTimeout = (DWORD)abs((int)(l_dDeltaT*1000.0));

			// Timer
			l_eReason = p_pContext->WaitOnActionDone(
				l_pSyncObj, 
				CO_WAKE_MASK_CMD_ABOVE_NORMAL+CO_WAKE_MASK_CMD_HIGH+CO_WAKE_MASK_ACTIONS_ALL, 
				l_dwTimeout);

			switch(l_eReason)
			{
			case eIRCmdAboveNormal:
			case eIRActionsDone:
				// 
				ASSERT(false);
				break;


			case eIRCmdHigh:
				l_bHighPrioCmd = true;
				break;

			case eIRTimeout:
				// control acceleration finished? exit?
				break;

			default:
				ASSERT(false);
				break;
			}
		} while (!l_bHighPrioCmd &&
			     l_dwItCount++ < l_dwIterations);

		if (l_bHighPrioCmd)
		{
			ASSERT(FALSE);
		}
		else
		{	
			// Stop the motor.
			GetpContext(p_pContext)->GetpHwConnection()->Stoping();
			GetpContext(p_pContext)->GetpHwConnection()->TrackHomingSteps();

			DWORD l_dwAxisPlay = l_pImplementation->GetpConfig()->GetdwAxisPlay();

			// keep position
			int l_iDistance = GetpContext(p_pContext)->GetpHwConnection()->GetRelativePos() -
				l_pLogic->GetiHomingLatchedPosition();
			ASSERT(l_iDistance >= 0);
			if (!l_pLimitHandler->IsAtHome() || l_iDistance > (int)l_dwAxisPlay)
			{
				// move back into limit respectively the limit edge
				if (l_iDistance > (int)l_dwAxisPlay)
					l_iDistance -= (int)l_dwAxisPlay;
				else
					l_iDistance = 1;

				CSTPositionMachine* l_pPos = GetpContext(p_pContext)->GetpPositionMachine();
				l_pPos->Reset();
				if (l_pPos->GetePolarity() == ePIMotorPolarityNormal)
					l_pPos->MoveRelative(-l_iDistance);
				else
					l_pPos->MoveRelative(l_iDistance);

				CSTActionMove* l_pAction = (CSTActionMove*)p_pContext->GetAction(IDA_MOVE);
				l_pAction->SetdwSpeed(l_pProfile->GetuiSpeedStartup());
				l_pAction->SetdwSteps(abs(l_iDistance));

				// complete movement, expect to stay in limit - and try to find it stepwise if the home sensor
				// still does not show it
				p_pContext->ChangeState(CSTStateHomeMovingBackToLatchedLimit::GetInstance(), l_pAction);
			}
			else
			{
				// home sensor is already active...
				p_pContext->ChangeState(CSTStateHomeAtLatchedLimit::GetInstance());
			}
		}
	}
	catch(...)
	{
		throw;
	}
  //## end CSTStateHomeDeceleratingToStop::Do%1128347831.body
}

// Additional Declarations
  //## begin CSTStateHomeDeceleratingToStop%434142360083.declarations preserve=yes
  //## end CSTStateHomeDeceleratingToStop%434142360083.declarations

// Class CSTStateHomeAtLatchedLimit 

//## begin CSTStateHomeAtLatchedLimit::pInstance%43426B0F0290.role preserve=no  public: static CSTStateHomeAtLatchedLimit {1..1 -> 1..1RFHN}
CSTStateHomeAtLatchedLimit *CSTStateHomeAtLatchedLimit::m_pInstance = NULL;
//## end CSTStateHomeAtLatchedLimit::pInstance%43426B0F0290.role


CSTStateHomeAtLatchedLimit::CSTStateHomeAtLatchedLimit()
  //## begin CSTStateHomeAtLatchedLimit::CSTStateHomeAtLatchedLimit%.hasinit preserve=no
  //## end CSTStateHomeAtLatchedLimit::CSTStateHomeAtLatchedLimit%.hasinit
  //## begin CSTStateHomeAtLatchedLimit::CSTStateHomeAtLatchedLimit%.initialization preserve=yes
  //## end CSTStateHomeAtLatchedLimit::CSTStateHomeAtLatchedLimit%.initialization
{
  //## begin CSTStateHomeAtLatchedLimit::CSTStateHomeAtLatchedLimit%.body preserve=yes
  //## end CSTStateHomeAtLatchedLimit::CSTStateHomeAtLatchedLimit%.body
}


CSTStateHomeAtLatchedLimit::~CSTStateHomeAtLatchedLimit()
{
  //## begin CSTStateHomeAtLatchedLimit::~CSTStateHomeAtLatchedLimit%.body preserve=yes
  //## end CSTStateHomeAtLatchedLimit::~CSTStateHomeAtLatchedLimit%.body
}



//## Other Operations (implementation)
void CSTStateHomeAtLatchedLimit::Create ()
{
  //## begin CSTStateHomeAtLatchedLimit::Create%1128355569.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSTStateHomeAtLatchedLimit();
  //## end CSTStateHomeAtLatchedLimit::Create%1128355569.body
}

void CSTStateHomeAtLatchedLimit::Delete ()
{
  //## begin CSTStateHomeAtLatchedLimit::Delete%1128355570.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSTStateHomeAtLatchedLimit::Delete%1128355570.body
}

CSTStateHomeAtLatchedLimit* CSTStateHomeAtLatchedLimit::GetInstance ()
{
  //## begin CSTStateHomeAtLatchedLimit::GetInstance%1128355571.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSTStateHomeAtLatchedLimit::GetInstance%1128355571.body
}

void CSTStateHomeAtLatchedLimit::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateHomeAtLatchedLimit::Do%1128355572.body preserve=yes
	// limit must be active
	CSTPositionMachine* l_pPos = GetpContext(p_pContext)->GetpPositionMachine();
	CSTLimitHandler* l_pLimitHandler = GetpContext(p_pContext)->GetpLimitHandler();
	if (!l_pLimitHandler->IsAtHome())
	{
		// limit not found
		throw new XSTExcepitonHomingSensorNotFound(ST_ID, IDE_ST_HOMING_SENSOR_NOT_FOUND, _T(__FILE__), __LINE__, 0);
	}

	CSTLimitSwitch* l_pLimit = l_pLimitHandler->FindLimitSwitch(l_pLimitHandler->GetpHomeLimitID());
	l_pLimit->ActivateReverseCharacteristics();
	l_pLimitHandler->Stop();
	l_pLimitHandler->Activate();
	l_pLimitHandler->Start();

	if (!l_pPos->GetbSearchLimitFromOpposite())
	{
		// move out of the limit again to be able to move stepwise into the limit from the same direction than the home process has started
		DWORD l_dwAxisPlay = GetpContext(p_pContext)->GetpConfig()->GetdwAxisPlay();

		// okay, now drive out of limit
		l_pPos->Reset();
		if (l_pPos->GeteFastFindingDirection() == ePIMotorPolarityNormal)
			l_pPos->MoveRelative(-2*l_dwAxisPlay);
		else
			l_pPos->MoveRelative(2*l_dwAxisPlay);

		CSTActionMove* l_pAction = (CSTActionMove*)p_pContext->GetAction(IDA_MOVE);
		l_pAction->SetdwSpeed(GetpContext(p_pContext)->GetpProfile()->GetuiSpeedStartup());
		l_pAction->SetdwSteps(2*l_dwAxisPlay);

		// Change state.
		p_pContext->ChangeState(CSTStateHomeLeavingLimit::GetInstance(), l_pAction);
	}
	else
	{
		// just move stepwise out of the limit
		p_pContext->ChangeState(CSTStateHomeSlowlyFindingLimitFromOpposite::GetInstance());
	}
  //## end CSTStateHomeAtLatchedLimit::Do%1128355572.body
}

// Additional Declarations
  //## begin CSTStateHomeAtLatchedLimit%43426A9902FD.declarations preserve=yes
  //## end CSTStateHomeAtLatchedLimit%43426A9902FD.declarations

// Class CSTStateHomeLeavingLimit 

//## begin CSTStateHomeLeavingLimit::pInstance%4342736102F6.role preserve=no  public: static CSTStateHomeLeavingLimit {1..1 -> 1..1RFHN}
CSTStateHomeLeavingLimit *CSTStateHomeLeavingLimit::m_pInstance = NULL;
//## end CSTStateHomeLeavingLimit::pInstance%4342736102F6.role


CSTStateHomeLeavingLimit::CSTStateHomeLeavingLimit()
  //## begin CSTStateHomeLeavingLimit::CSTStateHomeLeavingLimit%.hasinit preserve=no
  //## end CSTStateHomeLeavingLimit::CSTStateHomeLeavingLimit%.hasinit
  //## begin CSTStateHomeLeavingLimit::CSTStateHomeLeavingLimit%.initialization preserve=yes
  //## end CSTStateHomeLeavingLimit::CSTStateHomeLeavingLimit%.initialization
{
  //## begin CSTStateHomeLeavingLimit::CSTStateHomeLeavingLimit%.body preserve=yes
  //## end CSTStateHomeLeavingLimit::CSTStateHomeLeavingLimit%.body
}


CSTStateHomeLeavingLimit::~CSTStateHomeLeavingLimit()
{
  //## begin CSTStateHomeLeavingLimit::~CSTStateHomeLeavingLimit%.body preserve=yes
  //## end CSTStateHomeLeavingLimit::~CSTStateHomeLeavingLimit%.body
}



//## Other Operations (implementation)
void CSTStateHomeLeavingLimit::Create ()
{
  //## begin CSTStateHomeLeavingLimit::Create%1128355574.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSTStateHomeLeavingLimit();
  //## end CSTStateHomeLeavingLimit::Create%1128355574.body
}

void CSTStateHomeLeavingLimit::Delete ()
{
  //## begin CSTStateHomeLeavingLimit::Delete%1128355575.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSTStateHomeLeavingLimit::Delete%1128355575.body
}

CSTStateHomeLeavingLimit* CSTStateHomeLeavingLimit::GetInstance ()
{
  //## begin CSTStateHomeLeavingLimit::GetInstance%1128355576.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSTStateHomeLeavingLimit::GetInstance%1128355576.body
}

void CSTStateHomeLeavingLimit::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateHomeLeavingLimit::Do%1128355577.body preserve=yes
	try
	{
		// Pointer to implementation.
		CSTStepperMotorImplementation *l_pImplementation= GetpContext(p_pContext);
		ASSERT(l_pImplementation != NULL);

		CSTActionMove* l_pAction = (CSTActionMove*)p_pContext->GetAction(IDA_MOVE);

		// State if false.
		bool l_bHighPrioCmd = false, l_bLimitHit = false;
		bool l_bContinue = true;
		do
		{
			// Timer
			ECOInterruptReason l_eReason = p_pContext->WaitOnActionDone(
				l_pAction->GetpServerSyncObj(), 
				CO_WAKE_MASK_CMD_ABOVE_NORMAL+CO_WAKE_MASK_CMD_HIGH+CO_WAKE_MASK_ACTIONS_ALL);

			switch(l_eReason)
			{
				case eIRCmdAboveNormal:
					{
						// limit hit. kind of limit? do we have to exit? ChangeState(this). Get limit switch ID which was hit.
						CPIObjIdentification* l_pObjectIdent = GetpContext(p_pContext)->GetpLimitHandler()->GetpLimitSwitchIDHit();

						// Get limit switch which was hit.
						CSTLimitSwitch* l_pLimitSwitch = GetpContext(p_pContext)->GetpLimitHandler()->FindLimitSwitch(l_pObjectIdent);

						// LimitSwitch characteristics.
						EPILimitCharacteristics l_ePILimitCharacter = l_pLimitSwitch->GeteCurLimitCharacteristics();

						switch (l_ePILimitCharacter)
						{
							case ePILimitSoftEdgeFalling:
							case ePILimitSoftEdgeRaising:
								// Soft limit hit.
								l_bLimitHit = OnSoftLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
								break;

							case ePILimitHardEdgeFalling:
							case ePILimitHardEdgeRaising:
								// Hard limit hit.
								l_bLimitHit = OnHardLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
								break;

							default:
								ASSERT(false);
						}
					}
					break;

				case eIRActionsDone:
					l_pAction->Done();
					l_bContinue = false;
					break;


				case eIRCmdHigh:
					l_bHighPrioCmd = true;
					break;

				case eIRTimeout:
				default:
					ASSERT(false);
					break;
			}
		} while (l_bContinue && !l_bHighPrioCmd);

		GetpContext(p_pContext)->GetpHwConnection()->TrackHomingSteps();

		if (!l_bLimitHit)
		{
			// limit not found
			throw new XSTExcepitonHomingSensorNotFound(ST_ID, IDE_ST_HOMING_SENSOR_NOT_FOUND, _T(__FILE__), __LINE__, 0);
		}

		p_pContext->ChangeState(CSTStateHomeSlowlyFindingLimit::GetInstance());
	}
	catch(...)
	{
		throw;
	}
  //## end CSTStateHomeLeavingLimit::Do%1128355577.body
}

// Additional Declarations
  //## begin CSTStateHomeLeavingLimit%4342732102D5.declarations preserve=yes
  //## end CSTStateHomeLeavingLimit%4342732102D5.declarations

// Class CSTStateHomeSlowlyFindingLimit 

//## begin CSTStateHomeSlowlyFindingLimit::pInstance%4342963D01A8.role preserve=no  public: static CSTStateHomeSlowlyFindingLimit {1..1 -> 1..1RFHN}
CSTStateHomeSlowlyFindingLimit *CSTStateHomeSlowlyFindingLimit::m_pInstance = NULL;
//## end CSTStateHomeSlowlyFindingLimit::pInstance%4342963D01A8.role


CSTStateHomeSlowlyFindingLimit::CSTStateHomeSlowlyFindingLimit()
  //## begin CSTStateHomeSlowlyFindingLimit::CSTStateHomeSlowlyFindingLimit%.hasinit preserve=no
  //## end CSTStateHomeSlowlyFindingLimit::CSTStateHomeSlowlyFindingLimit%.hasinit
  //## begin CSTStateHomeSlowlyFindingLimit::CSTStateHomeSlowlyFindingLimit%.initialization preserve=yes
  //## end CSTStateHomeSlowlyFindingLimit::CSTStateHomeSlowlyFindingLimit%.initialization
{
  //## begin CSTStateHomeSlowlyFindingLimit::CSTStateHomeSlowlyFindingLimit%.body preserve=yes
  //## end CSTStateHomeSlowlyFindingLimit::CSTStateHomeSlowlyFindingLimit%.body
}


CSTStateHomeSlowlyFindingLimit::~CSTStateHomeSlowlyFindingLimit()
{
  //## begin CSTStateHomeSlowlyFindingLimit::~CSTStateHomeSlowlyFindingLimit%.body preserve=yes
  //## end CSTStateHomeSlowlyFindingLimit::~CSTStateHomeSlowlyFindingLimit%.body
}



//## Other Operations (implementation)
void CSTStateHomeSlowlyFindingLimit::Create ()
{
  //## begin CSTStateHomeSlowlyFindingLimit::Create%1128355578.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSTStateHomeSlowlyFindingLimit();
  //## end CSTStateHomeSlowlyFindingLimit::Create%1128355578.body
}

void CSTStateHomeSlowlyFindingLimit::Delete ()
{
  //## begin CSTStateHomeSlowlyFindingLimit::Delete%1128355579.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSTStateHomeSlowlyFindingLimit::Delete%1128355579.body
}

CSTStateHomeSlowlyFindingLimit* CSTStateHomeSlowlyFindingLimit::GetInstance ()
{
  //## begin CSTStateHomeSlowlyFindingLimit::GetInstance%1128355580.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSTStateHomeSlowlyFindingLimit::GetInstance%1128355580.body
}

void CSTStateHomeSlowlyFindingLimit::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateHomeSlowlyFindingLimit::Do%1128355581.body preserve=yes
	CCOSyncObjectPtr l_pSyncObj;
	DWORD l_dwMoveEventID = GetpContext(p_pContext)->GetpConfig()->GetdwIDMovingTerminationEvent();
	try
	{
		// configure limit handler to default again
		CSTLimitHandler* l_pLimitHandler = GetpContext(p_pContext)->GetpLimitHandler();
		CSTLimitSwitch* l_pLimit = l_pLimitHandler->FindLimitSwitch(l_pLimitHandler->GetpHomeLimitID());
		l_pLimit->RestoreOriginalCharacteristics();
		l_pLimitHandler->Stop();

		CSTPositionMachine* l_pPos = GetpContext(p_pContext)->GetpPositionMachine();
		int l_iStep = l_pPos->GeteFastFindingDirection() == ePIMotorPolarityNormal ? 1 : -1;
		l_pPos->Reset();

		CSTHardwareConnection* l_pHWCon = GetpContext(p_pContext)->GetpHwConnection();
		double l_dSpeed = GetpContext(p_pContext)->GetpProfile()->GetuiSpeedHome();
		l_pHWCon->SetVelocity((DWORD)l_dSpeed);

		DWORD l_dwAxisPlay = GetpContext(p_pContext)->GetpConfig()->GetdwAxisPlay();

		l_pSyncObj = IHIInterface::GetInstance()->OpenEvent(l_dwMoveEventID, eHIUndefined );

		bool l_bLimitFound = false;
		int l_iStepCnt = 0;
		do
		{
			l_pPos->MoveRelative(l_iStep);
			l_pHWCon->Moving(1);
			l_pSyncObj->Synchronize();
			l_pSyncObj->ResetCompletion();

			GetpContext(p_pContext)->GetpHwConnection()->TrackHomingSteps();

			Sleep((DWORD)(1000.0/l_dSpeed));
			if (l_pLimitHandler->IsAtHome())
				l_bLimitFound = true;

		} while (!l_bLimitFound &&
				 l_iStepCnt++ < (int)(2*l_dwAxisPlay));

		// add steps to position machine
		l_pPos->Reset();

		IHIInterface::GetInstance()->CloseEvent(l_dwMoveEventID, l_pSyncObj);

		l_pLimit->RestoreOriginalCharacteristics();
		l_pLimitHandler->Stop();
		l_pLimitHandler->Activate();
		l_pLimitHandler->Start();

		if (!l_bLimitFound)
		{
			// limit not found
			throw new XSTExcepitonHomingSensorNotFound(ST_ID, IDE_ST_HOMING_SENSOR_NOT_FOUND, _T(__FILE__), __LINE__, 0);
		}

		INT l_iHomingPos = l_pHWCon->GetHomingSteps();

		CCOSyncObjectInt* l_pSyncObj = GetpContext(p_pContext)->GetpHomeSyncObj();
		ASSERT(l_pSyncObj != NULL);
		l_pSyncObj->SetValue(l_iHomingPos);
		GetpContext(p_pContext)->SetpHomeSyncObj(NULL);

		p_pContext->ChangeState(CSTStateIdle::GetInstance());
	}
	catch(...)
	{
		if (l_pSyncObj)
			IHIInterface::GetInstance()->CloseEvent(l_dwMoveEventID, l_pSyncObj);
		throw;
	}

  //## end CSTStateHomeSlowlyFindingLimit::Do%1128355581.body
}

// Additional Declarations
  //## begin CSTStateHomeSlowlyFindingLimit%434295F20109.declarations preserve=yes
  //## end CSTStateHomeSlowlyFindingLimit%434295F20109.declarations

// Class CSTStateHomeMovingOutOfLimit 

//## begin CSTStateHomeMovingOutOfLimit::pInstance%43437C5903A2.role preserve=no  public: static CSTStateHomeMovingOutOfLimit {1..1 -> 1..1RFHN}
CSTStateHomeMovingOutOfLimit *CSTStateHomeMovingOutOfLimit::m_pInstance = NULL;
//## end CSTStateHomeMovingOutOfLimit::pInstance%43437C5903A2.role


CSTStateHomeMovingOutOfLimit::CSTStateHomeMovingOutOfLimit()
  //## begin CSTStateHomeMovingOutOfLimit::CSTStateHomeMovingOutOfLimit%.hasinit preserve=no
  //## end CSTStateHomeMovingOutOfLimit::CSTStateHomeMovingOutOfLimit%.hasinit
  //## begin CSTStateHomeMovingOutOfLimit::CSTStateHomeMovingOutOfLimit%.initialization preserve=yes
  //## end CSTStateHomeMovingOutOfLimit::CSTStateHomeMovingOutOfLimit%.initialization
{
  //## begin CSTStateHomeMovingOutOfLimit::CSTStateHomeMovingOutOfLimit%.body preserve=yes
  //## end CSTStateHomeMovingOutOfLimit::CSTStateHomeMovingOutOfLimit%.body
}


CSTStateHomeMovingOutOfLimit::~CSTStateHomeMovingOutOfLimit()
{
  //## begin CSTStateHomeMovingOutOfLimit::~CSTStateHomeMovingOutOfLimit%.body preserve=yes
  //## end CSTStateHomeMovingOutOfLimit::~CSTStateHomeMovingOutOfLimit%.body
}



//## Other Operations (implementation)
void CSTStateHomeMovingOutOfLimit::Create ()
{
  //## begin CSTStateHomeMovingOutOfLimit::Create%1128355582.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSTStateHomeMovingOutOfLimit();
  //## end CSTStateHomeMovingOutOfLimit::Create%1128355582.body
}

void CSTStateHomeMovingOutOfLimit::Delete ()
{
  //## begin CSTStateHomeMovingOutOfLimit::Delete%1128355583.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSTStateHomeMovingOutOfLimit::Delete%1128355583.body
}

CSTStateHomeMovingOutOfLimit* CSTStateHomeMovingOutOfLimit::GetInstance ()
{
  //## begin CSTStateHomeMovingOutOfLimit::GetInstance%1128355584.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSTStateHomeMovingOutOfLimit::GetInstance%1128355584.body
}

void CSTStateHomeMovingOutOfLimit::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateHomeMovingOutOfLimit::Do%1128355585.body preserve=yes
	try
	{
		// Pointer to implementation.
		CSTStepperMotorImplementation* l_pImplementation = GetpContext(p_pContext);
		ASSERT(l_pImplementation != NULL);

		CSTPositionMachine* l_pPos = l_pImplementation->GetpPositionMachine();
		CSTHardwareConnection* l_pHWCon = l_pImplementation->GetpHwConnection();

		CSTActionMove* l_pAction = (CSTActionMove*)p_pContext->GetAction(IDA_MOVE);

		CSTLimitHandler* l_pLimitHandler = l_pImplementation->GetpLimitHandler();
		EPIMotorPolarity l_ePolarity = l_pPos->GeteFastFindingDirection();

		DWORD l_dwAxisPlay = l_pImplementation->GetpConfig()->GetdwAxisPlay();

		// State if false.
		bool l_bHighPrioCmd = false, l_bLimitHit = false, l_bTimeout = false;
		bool l_bContinue = true;
		do
		{
			// Timer
			ECOInterruptReason l_eReason = p_pContext->WaitOnActionDone(
				l_pAction->GetpServerSyncObj(), 
				CO_WAKE_MASK_CMD_ABOVE_NORMAL+CO_WAKE_MASK_CMD_HIGH+CO_WAKE_MASK_ACTIONS_ALL,
				GetpContext(p_pContext)->GetpConfig()->GetdwHomingTimeout());

			switch(l_eReason)
			{
				case eIRCmdAboveNormal:
					{
						// limit hit. kind of limit? do we have to exit? ChangeState(this). Get limit switch ID which was hit.
						CPIObjIdentification* l_pObjectIdent = GetpContext(p_pContext)->GetpLimitHandler()->GetpLimitSwitchIDHit();

						// Get limit switch which was hit.
						CSTLimitSwitch* l_pLimitSwitch = GetpContext(p_pContext)->GetpLimitHandler()->FindLimitSwitch(l_pObjectIdent);

						// LimitSwitch characteristics.
						EPILimitCharacteristics l_ePILimitCharacter = l_pLimitSwitch->GeteCurLimitCharacteristics();

						switch (l_ePILimitCharacter)
						{
							case ePILimitSoftEdgeFalling:
							case ePILimitSoftEdgeRaising:
								// Soft limit hit.
								l_bLimitHit = OnSoftLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
								break;

							case ePILimitHardEdgeFalling:
							case ePILimitHardEdgeRaising:
								// Hard limit hit.
								l_bLimitHit = OnHardLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
								break;

							default:
								ASSERT(false);
						}

						if (l_bLimitHit)
						{
							GetpContext(p_pContext)->GetpHwConnection()->TrackHomingSteps();

							// change destination now that we know about the limit position
							l_pPos->TrackPosition();
							if (l_ePolarity == ePIMotorPolarityNormal)
								l_pPos->MoveRelative(-(int)l_dwAxisPlay);
							else
								l_pPos->MoveRelative(l_dwAxisPlay);
							l_pHWCon->SetSteps(l_dwAxisPlay);
							l_pHWCon->SetValid(eStepsValid);
						}
					}
					break;

				case eIRActionsDone:
					l_pAction->Done();
					l_bContinue = false;
					break;


				case eIRCmdHigh:
					l_bHighPrioCmd = true;
					break;

				case eIRTimeout:
					// limit not found
					l_bTimeout = true;
					break;

				default:
					ASSERT(false);
					break;
			}
		} while (l_bContinue && !l_bHighPrioCmd && !l_bTimeout);

		GetpContext(p_pContext)->GetpHwConnection()->TrackHomingSteps();

		if (!l_bLimitHit || l_bTimeout)
		{
			// limit not found
			throw new XSTExcepitonHomingSensorNotFound(ST_ID, IDE_ST_HOMING_SENSOR_NOT_FOUND, _T(__FILE__), __LINE__, 0);
		}

		if (GetpContext(p_pContext)->GetpPositionMachine()->GetbSearchLimitFromOpposite())
		{
			CPIObjIdentification* l_pObjectIdent = GetpContext(p_pContext)->GetpLimitHandler()->GetpLimitSwitchIDHit();
			CSTLimitSwitch* l_pLimit = GetpContext(p_pContext)->GetpLimitHandler()->FindLimitSwitch(l_pObjectIdent);
			l_pLimit->RestoreOriginalCharacteristics();
			l_pLimitHandler->Stop();
			l_pLimitHandler->Activate();
			l_pLimitHandler->Start();

			// just start accelerating
			p_pContext->ChangeState(CSTStateHomeAccelerating::GetInstance());
		}
		else
		{
			p_pContext->ChangeState(CSTStateHomeSlowlyFindingLimit::GetInstance());
		}
	}
	catch(...)
	{
		throw;
	}
  //## end CSTStateHomeMovingOutOfLimit::Do%1128355585.body
}

// Additional Declarations
  //## begin CSTStateHomeMovingOutOfLimit%43437355024E.declarations preserve=yes
  //## end CSTStateHomeMovingOutOfLimit%43437355024E.declarations

// Class CSTStateHomeAccelerating 

//## begin CSTStateHomeAccelerating::pInstance%4487D3510322.role preserve=no  public: static CSTStateHomeAccelerating {1..1 -> 1..1RFHN}
CSTStateHomeAccelerating *CSTStateHomeAccelerating::m_pInstance;
//## end CSTStateHomeAccelerating::pInstance%4487D3510322.role


CSTStateHomeAccelerating::CSTStateHomeAccelerating()
  //## begin CSTStateHomeAccelerating::CSTStateHomeAccelerating%.hasinit preserve=no
  //## end CSTStateHomeAccelerating::CSTStateHomeAccelerating%.hasinit
  //## begin CSTStateHomeAccelerating::CSTStateHomeAccelerating%.initialization preserve=yes
  //## end CSTStateHomeAccelerating::CSTStateHomeAccelerating%.initialization
{
  //## begin CSTStateHomeAccelerating::CSTStateHomeAccelerating%.body preserve=yes
  //## end CSTStateHomeAccelerating::CSTStateHomeAccelerating%.body
}


CSTStateHomeAccelerating::~CSTStateHomeAccelerating()
{
  //## begin CSTStateHomeAccelerating::~CSTStateHomeAccelerating%.body preserve=yes
  //## end CSTStateHomeAccelerating::~CSTStateHomeAccelerating%.body
}



//## Other Operations (implementation)
void CSTStateHomeAccelerating::Create ()
{
  //## begin CSTStateHomeAccelerating::Create%1149752278.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSTStateHomeAccelerating();
  //## end CSTStateHomeAccelerating::Create%1149752278.body
}

void CSTStateHomeAccelerating::Delete ()
{
  //## begin CSTStateHomeAccelerating::Delete%1149752279.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSTStateHomeAccelerating::Delete%1149752279.body
}

CSTStateHomeAccelerating* CSTStateHomeAccelerating::GetInstance ()
{
  //## begin CSTStateHomeAccelerating::GetInstance%1149752280.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSTStateHomeAccelerating::GetInstance%1149752280.body
}

void CSTStateHomeAccelerating::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateHomeAccelerating::Do%1149752281.body preserve=yes
	// Synchronisation object smart pointer.
	CCOSyncObjectPtr l_pSyncObj = NULL;

	try
	{
		// New object.
		l_pSyncObj = new CCOSyncObject(_T("ST:StateHomeAccelerating"));

		// Pointer to implementation.
		CSTStepperMotorImplementation *l_pImplementation= GetpContext(p_pContext);

		// Pointer to logic.
		CSTLogic *l_pLogic = l_pImplementation->GetpLogic();

		CPIStepperMotorProfile* l_pProfile = l_pImplementation->GetpProfile();
		
		// State if false.
		bool l_bHighPrioCmd = false;
		bool l_bLimitHit = false;

		const double l_da = (double)l_pProfile->GetuiNomAccDec();
		DWORD l_dwItCount = 0;
        const UINT l_uidt = l_pImplementation->GetpConfig()->GetuiSamplingTime();
		double l_ddv = l_da * ((double)l_uidt / 1000.0);
		double l_dActSpeed = l_ddv;
		const double l_dMaxSpeed = (double)l_pProfile->GetuiSpeed();

		CSTPositionMachine* l_pPos = GetpContext(p_pContext)->GetpPositionMachine();

		if (l_pPos->GeteFastFindingDirection() == ePIMotorPolarityNormal)
		{
			l_pPos->MoveRelative(CONTINUOUS);
		}
		else
		{
			l_pPos->MoveRelative(-CONTINUOUS);
		}

		// continious run until max speed is reached
		GetpContext(p_pContext)->GetpHwConnection()->SetSteps(CONTINUOUS);
		GetpContext(p_pContext)->GetpHwConnection()->SetVelocity(l_dActSpeed);
		GetpContext(p_pContext)->GetpHwConnection()->SetValid(eStepsAndVelocityValid);

		// increase speed
		while (l_dActSpeed < l_dMaxSpeed && !l_bHighPrioCmd && !l_bLimitHit)
		{
			// Timer
			ECOInterruptReason l_eReason = p_pContext->WaitOnActionDone(
				l_pSyncObj, 
				CO_WAKE_MASK_CMD_ABOVE_NORMAL+CO_WAKE_MASK_CMD_HIGH+CO_WAKE_MASK_ACTIONS_ALL, 
				(DWORD)l_uidt);

			switch(l_eReason)
			{

			case eIRCmdAboveNormal:
			{
				// limit hit. kind of limit? do we have to exit? Get limit switch ID which was hit.
				CPIObjIdentification* l_pObjectIdent = GetpContext(p_pContext)->GetpLimitHandler()->GetpLimitSwitchIDHit();

				// Get limit switch which was hit.
				CSTLimitSwitch* l_pLimitSwitch = GetpContext(p_pContext)->GetpLimitHandler()->FindLimitSwitch(l_pObjectIdent);

				// LimitSwitch characteristics.
				EPILimitCharacteristics l_ePILimitCharacter = l_pLimitSwitch->GeteCurLimitCharacteristics();

				switch (l_ePILimitCharacter)
				{
				case ePILimitSoftEdgeFalling:
				case ePILimitSoftEdgeRaising:
				default:
					ASSERT(false);
					break;

				case ePILimitHardEdgeFalling:
				case ePILimitHardEdgeRaising:
					// Hard limit hit. true --> stop acceleration and exit state.
					l_bLimitHit = true;
					break;
				}
			}
			break;
			
			case eIRCmdHigh:
				l_bHighPrioCmd = true;
				break;

			case eIRTimeout:
				// increase speed
				l_dActSpeed += l_ddv;
				GetpContext(p_pContext)->GetpHwConnection()->SetVelocity(l_dActSpeed);
				GetpContext(p_pContext)->GetpHwConnection()->SetValid(eVelocityValid);
				break;

			default:
			case eIRActionsDone:
				ASSERT(false);
				break;

			}
		}


		if(l_bHighPrioCmd)
		{
			// Change state.
			GetpContext(p_pContext)->SetpHomeSyncObj(NULL);
			p_pContext->ChangeState(CSTStateIdle::GetInstance());
		
		}
		else if(l_bLimitHit)
		{	
			// Change state.
			// Home sensor hit.
			CO_TRACE(ST_ID,_T("Home sensor hit."));

			// keep current position
			GetpContext(p_pContext)->GetpLogic()->SetiHomingLatchedPosition(
				GetpContext(p_pContext)->GetpHwConnection()->GetRelativePos());
            GetpContext(p_pContext)->GetpLogic()->SetdbSpeedAfterAcceleration(l_dActSpeed);
			p_pContext->ChangeState(CSTStateHomeDeceleratingToStop::GetInstance());
		}
		else
		{
			// Change state.
//			GetpContext(p_pContext)->GetpHwConnection()->SetVelocity(l_dMaxSpeed);
//			GetpContext(p_pContext)->GetpHwConnection()->SetValid(eVelocityValid);

            GetpContext(p_pContext)->GetpLogic()->SetdbSpeedAfterAcceleration(l_dActSpeed);
			p_pContext->ChangeState(CSTStateHomeFastFindingLimit::GetInstance());
		}

	}
	catch(...)
	{
		l_pSyncObj = NULL;

		throw;
	}
  //## end CSTStateHomeAccelerating::Do%1149752281.body
}

// Additional Declarations
  //## begin CSTStateHomeAccelerating%4487D2A10346.declarations preserve=yes
  //## end CSTStateHomeAccelerating%4487D2A10346.declarations

// Class CSTStateHomeSlowlyFindingLimitFromOpposite 

//## begin CSTStateHomeSlowlyFindingLimitFromOpposite::pInstance%471CF2B00320.role preserve=no  public: static CSTStateHomeSlowlyFindingLimitFromOpposite {1..1 -> 1..1RFHN}
CSTStateHomeSlowlyFindingLimitFromOpposite *CSTStateHomeSlowlyFindingLimitFromOpposite::m_pInstance = NULL;
//## end CSTStateHomeSlowlyFindingLimitFromOpposite::pInstance%471CF2B00320.role


CSTStateHomeSlowlyFindingLimitFromOpposite::CSTStateHomeSlowlyFindingLimitFromOpposite()
  //## begin CSTStateHomeSlowlyFindingLimitFromOpposite::CSTStateHomeSlowlyFindingLimitFromOpposite%.hasinit preserve=no
  //## end CSTStateHomeSlowlyFindingLimitFromOpposite::CSTStateHomeSlowlyFindingLimitFromOpposite%.hasinit
  //## begin CSTStateHomeSlowlyFindingLimitFromOpposite::CSTStateHomeSlowlyFindingLimitFromOpposite%.initialization preserve=yes
  //## end CSTStateHomeSlowlyFindingLimitFromOpposite::CSTStateHomeSlowlyFindingLimitFromOpposite%.initialization
{
  //## begin CSTStateHomeSlowlyFindingLimitFromOpposite::CSTStateHomeSlowlyFindingLimitFromOpposite%.body preserve=yes
  //## end CSTStateHomeSlowlyFindingLimitFromOpposite::CSTStateHomeSlowlyFindingLimitFromOpposite%.body
}


CSTStateHomeSlowlyFindingLimitFromOpposite::~CSTStateHomeSlowlyFindingLimitFromOpposite()
{
  //## begin CSTStateHomeSlowlyFindingLimitFromOpposite::~CSTStateHomeSlowlyFindingLimitFromOpposite%.body preserve=yes
  //## end CSTStateHomeSlowlyFindingLimitFromOpposite::~CSTStateHomeSlowlyFindingLimitFromOpposite%.body
}



//## Other Operations (implementation)
void CSTStateHomeSlowlyFindingLimitFromOpposite::Create ()
{
  //## begin CSTStateHomeSlowlyFindingLimitFromOpposite::Create%1193077631.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSTStateHomeSlowlyFindingLimitFromOpposite();
  //## end CSTStateHomeSlowlyFindingLimitFromOpposite::Create%1193077631.body
}

void CSTStateHomeSlowlyFindingLimitFromOpposite::Delete ()
{
  //## begin CSTStateHomeSlowlyFindingLimitFromOpposite::Delete%1193077632.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSTStateHomeSlowlyFindingLimitFromOpposite::Delete%1193077632.body
}

CSTStateHomeSlowlyFindingLimitFromOpposite* CSTStateHomeSlowlyFindingLimitFromOpposite::GetInstance ()
{
  //## begin CSTStateHomeSlowlyFindingLimitFromOpposite::GetInstance%1193077633.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSTStateHomeSlowlyFindingLimitFromOpposite::GetInstance%1193077633.body
}

void CSTStateHomeSlowlyFindingLimitFromOpposite::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateHomeSlowlyFindingLimitFromOpposite::Do%1193077634.body preserve=yes
	CCOSyncObjectPtr l_pSyncObj;
	DWORD l_dwMoveEventID = GetpContext(p_pContext)->GetpConfig()->GetdwIDMovingTerminationEvent();
	try
	{
		// configure limit handler to default again
		CSTLimitHandler* l_pLimitHandler = GetpContext(p_pContext)->GetpLimitHandler();
		CSTLimitSwitch* l_pLimit = l_pLimitHandler->FindLimitSwitch(l_pLimitHandler->GetpHomeLimitID());
		l_pLimitHandler->Stop();

		CSTPositionMachine* l_pPos = GetpContext(p_pContext)->GetpPositionMachine();
		int l_iStep = l_pPos->GeteFastFindingDirection() == ePIMotorPolarityNormal ? -1 : 1;
		l_pPos->Reset();

		CSTHardwareConnection* l_pHWCon = GetpContext(p_pContext)->GetpHwConnection();
		double l_dSpeed = GetpContext(p_pContext)->GetpProfile()->GetuiSpeedHome();
		l_pHWCon->SetVelocity((DWORD)l_dSpeed);

		DWORD l_dwAxisPlay = GetpContext(p_pContext)->GetpConfig()->GetdwAxisPlay();

		l_pSyncObj = IHIInterface::GetInstance()->OpenEvent(l_dwMoveEventID, eHIUndefined );

		bool l_bLimitFound = false;
		int l_iStepCnt = 0;
		do
		{
			l_pPos->MoveRelative(l_iStep);
			l_pHWCon->Moving(1);
			l_pSyncObj->Synchronize();
			l_pSyncObj->ResetCompletion();

			GetpContext(p_pContext)->GetpHwConnection()->TrackHomingSteps();

			Sleep((DWORD)(1000.0/l_dSpeed));
			if (l_pLimitHandler->IsAtHome())
				l_bLimitFound = true;

		} while (!l_bLimitFound &&
				 l_iStepCnt++ < (int)(2*l_dwAxisPlay));

		// add steps to position machine
		l_pPos->Reset();

		IHIInterface::GetInstance()->CloseEvent(l_dwMoveEventID, l_pSyncObj);

		// restore limit configuration
		l_pLimit->RestoreOriginalCharacteristics();
		l_pLimitHandler->Stop();
		l_pLimitHandler->Activate();
		l_pLimitHandler->Start();

		if (!l_bLimitFound)
		{
			// limit not found
			throw new XSTExcepitonHomingSensorNotFound(ST_ID, IDE_ST_HOMING_SENSOR_NOT_FOUND, _T(__FILE__), __LINE__, 0);
		}

		INT l_iHomingPos = l_pHWCon->GetHomingSteps();
		CCOSyncObjectInt* l_pSyncObj = GetpContext(p_pContext)->GetpHomeSyncObj();
		ASSERT(l_pSyncObj != NULL);
		l_pSyncObj->SetValue(l_iHomingPos);
		GetpContext(p_pContext)->SetpHomeSyncObj(NULL);

		p_pContext->ChangeState(CSTStateIdle::GetInstance());
	}
	catch(...)
	{
		if (l_pSyncObj)
			IHIInterface::GetInstance()->CloseEvent(l_dwMoveEventID, l_pSyncObj);
		throw;
	}
  //## end CSTStateHomeSlowlyFindingLimitFromOpposite::Do%1193077634.body
}

// Additional Declarations
  //## begin CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.declarations preserve=yes
  //## end CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.declarations

//## begin module%4341377602C0.epilog preserve=yes
//## end module%4341377602C0.epilog
