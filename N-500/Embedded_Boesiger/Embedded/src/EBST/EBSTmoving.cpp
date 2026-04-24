//## begin module%3E71A71501D4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E71A71501D4.cm

//## begin module%3E71A71501D4.cp preserve=no
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
//## end module%3E71A71501D4.cp

//## Module: EBSTmoving%3E71A71501D4; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTmoving.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E71A71501D4.additionalIncludes preserve=no
//## end module%3E71A71501D4.additionalIncludes

//## begin module%3E71A71501D4.includes preserve=yes
//## end module%3E71A71501D4.includes

// EBCOimct
#include "EBCOimct.h"
// EBSTlmwk
#include "EBSTlmwk.h"
// EBSTlimit
#include "EBSTlimit.h"
// EBSTlogic
#include "EBSTlogic.h"
// EBSTmoving
#include "EBSTmoving.h"
// EBSTidle
#include "EBSTidle.h"
// EBPItype
#include "EBPItype.h"
// EBSTidnt
#include "EBSTidnt.h"
// EBSTimpl
#include "EBSTimpl.h"
// EBSThwconn
#include "EBSThwconn.h"
// EBSTconn
#include "EBSTconn.h"
// EBSTexcp
#include "EBSTexcp.h"
// EBHIintf
#include "EBHIintf.h"
// EBHIenum
#include "EBHIenum.h"


//## begin module%3E71A71501D4.declarations preserve=no
//## end module%3E71A71501D4.declarations

//## begin module%3E71A71501D4.additionalDeclarations preserve=yes
#define ROUND(x) (DWORD)(((double)(x))+0.5)
//## end module%3E71A71501D4.additionalDeclarations


// Class CSTStateMoving 

CSTStateMoving::CSTStateMoving()
  //## begin CSTStateMoving::CSTStateMoving%.hasinit preserve=no
  //## end CSTStateMoving::CSTStateMoving%.hasinit
  //## begin CSTStateMoving::CSTStateMoving%.initialization preserve=yes
  //## end CSTStateMoving::CSTStateMoving%.initialization
{
  //## begin CSTStateMoving::CSTStateMoving%.body preserve=yes
  //## end CSTStateMoving::CSTStateMoving%.body
}


CSTStateMoving::~CSTStateMoving()
{
  //## begin CSTStateMoving::~CSTStateMoving%.body preserve=yes
  //## end CSTStateMoving::~CSTStateMoving%.body
}



//## Other Operations (implementation)
void CSTStateMoving::StopImmediately (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateMoving::StopImmediately%1047904772.body preserve=yes
	p_pContext->ChangeState(CSTStateIdle::GetInstance());
  //## end CSTStateMoving::StopImmediately%1047904772.body
}

bool CSTStateMoving::Stop (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSTStateMoving::Stop%1047904789.body preserve=yes
	GetpContext(p_pContext)->SetpStopSyncObj(p_pClientSyncObj);
	return false;
  //## end CSTStateMoving::Stop%1047904789.body
}

bool CSTStateMoving::OnSoftLimit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID)
{
  //## begin CSTStateMoving::OnSoftLimit%1051258412.body preserve=yes
	TRACE(_T("OnSoftLimit(), it's an empty function..."));
	return false;
  //## end CSTStateMoving::OnSoftLimit%1051258412.body
}

bool CSTStateMoving::OnHardLimit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID)
{
  //## begin CSTStateMoving::OnHardLimit%1048669926.body preserve=yes

	CSTLimitSwitch *l_pLimitSwitch = GetpContext(p_pContext)->GetpLimitHandler()->FindLimitSwitch(p_pLimitID);
	
	EPILimitAction eLimitAction = l_pLimitSwitch->GeteLimitAction();

	switch (eLimitAction)	
	{
	case ePILimitActionDecelerate:
	case ePILimitActionStop:
		{
			// bit for the exception
			GetpContext(p_pContext)->GetpLogic()->SetbLimitHit(true);

			// Hard limit hit. Stop the motor.
			p_pContext->ChangeState(CSTStateIdle::GetInstance());
		}
		break;

	case ePILimitActionFootprint:
	case ePILimitActionDisabled:
		{
			ASSERT(false);
		}
		break;
	}

	return true;
  //## end CSTStateMoving::OnHardLimit%1048669926.body
}

void CSTStateMoving::OnLimitHit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID)
{
  //## begin CSTStateMoving::OnLimitHit%1048669927.body preserve=yes

	// Save limit switch ID to implementation.
	GetpContext(p_pContext)->GetpLimitHandler()->SetpLimitSwitchIDHit(p_pLimitID);

  //## end CSTStateMoving::OnLimitHit%1048669927.body
}

void CSTStateMoving::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateMoving::CleanupInitialize%1053438558.body preserve=yes
	p_pContext->ChangeState(CSTStateIdle::GetInstance());
  //## end CSTStateMoving::CleanupInitialize%1053438558.body
}

void CSTStateMoving::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateMoving::ConnectionLost%1055922858.body preserve=yes
	p_pContext->ChangeState(CSTStateConnectionNotConnected::GetInstance());
  //## end CSTStateMoving::ConnectionLost%1055922858.body
}

void CSTStateMoving::ComputeTiming (CSTLogic* p_pLogic, double p_dDeltaT, DWORD& p_dwTimeout, DWORD& p_dwNominalTime, DWORD& p_dwMissedTime, DWORD& p_dwMissedSteps)
{
  //## begin CSTStateMoving::ComputeTiming%1090846594.body preserve=yes

    double l_dbTimeout = p_dDeltaT*1000.0;
    double l_dbNominalTime = l_dbTimeout*p_pLogic->GetdwCurIterationCnt();
    double l_dbMissedTime = p_pLogic->GetDeltaTime()-l_dbNominalTime;
    double l_dbMissedSteps = l_dbMissedTime / l_dbTimeout;

    p_dwNominalTime = ROUND(l_dbNominalTime);
    p_dwMissedTime  = ROUND(l_dbMissedTime);
    p_dwMissedSteps = ROUND(l_dbMissedSteps);
    p_dwTimeout     = ROUND(l_dbTimeout);

	if (p_dwMissedSteps > 0)
		p_dwMissedTime %= p_dwTimeout;

    p_dwTimeout -= p_dwMissedTime;
	if (p_dwMissedSteps > 0)
		p_pLogic->AddMissedIterations(p_dwMissedSteps);

  //## end CSTStateMoving::ComputeTiming%1090846594.body
}

// Additional Declarations
  //## begin CSTStateMoving%3E71A09D035B.declarations preserve=yes
  //## end CSTStateMoving%3E71A09D035B.declarations

// Class CSTStateMovingIncreaseSpeed 

//## begin CSTStateMovingIncreaseSpeed::pInstance%3E75C8B300E0.role preserve=no  public: static CSTStateMovingIncreaseSpeed {1..1 -> 1..1RFHN}
CSTStateMovingIncreaseSpeed *CSTStateMovingIncreaseSpeed::m_pInstance = NULL;
//## end CSTStateMovingIncreaseSpeed::pInstance%3E75C8B300E0.role


CSTStateMovingIncreaseSpeed::CSTStateMovingIncreaseSpeed()
  //## begin CSTStateMovingIncreaseSpeed::CSTStateMovingIncreaseSpeed%.hasinit preserve=no
  //## end CSTStateMovingIncreaseSpeed::CSTStateMovingIncreaseSpeed%.hasinit
  //## begin CSTStateMovingIncreaseSpeed::CSTStateMovingIncreaseSpeed%.initialization preserve=yes
  //## end CSTStateMovingIncreaseSpeed::CSTStateMovingIncreaseSpeed%.initialization
{
  //## begin CSTStateMovingIncreaseSpeed::CSTStateMovingIncreaseSpeed%.body preserve=yes
  //## end CSTStateMovingIncreaseSpeed::CSTStateMovingIncreaseSpeed%.body
}


CSTStateMovingIncreaseSpeed::~CSTStateMovingIncreaseSpeed()
{
  //## begin CSTStateMovingIncreaseSpeed::~CSTStateMovingIncreaseSpeed%.body preserve=yes
  //## end CSTStateMovingIncreaseSpeed::~CSTStateMovingIncreaseSpeed%.body
}



//## Other Operations (implementation)
void CSTStateMovingIncreaseSpeed::Create ()
{
  //## begin CSTStateMovingIncreaseSpeed::Create%1047892492.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSTStateMovingIncreaseSpeed();

  //## end CSTStateMovingIncreaseSpeed::Create%1047892492.body
}

void CSTStateMovingIncreaseSpeed::Delete ()
{
  //## begin CSTStateMovingIncreaseSpeed::Delete%1047892493.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;

  //## end CSTStateMovingIncreaseSpeed::Delete%1047892493.body
}

CSTStateMovingIncreaseSpeed* CSTStateMovingIncreaseSpeed::GetInstance ()
{
  //## begin CSTStateMovingIncreaseSpeed::GetInstance%1047892494.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateMovingIncreaseSpeed::GetInstance%1047892494.body
}

void CSTStateMovingIncreaseSpeed::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateMovingIncreaseSpeed::Do%1047971043.body preserve=yes

	// Synchronisation object smart pointer.
	CCOSyncObjectPtr l_pSyncObj = NULL; 
	try
	{
		// New object.
		l_pSyncObj = new CCOSyncObject();

		// Pointer to implementation.
		CSTStepperMotorImplementation *l_pImplementation= GetpContext(p_pContext);
		ASSERT(l_pImplementation != NULL);

		// Pointer to logic.
		CSTLogic *l_pLogic = l_pImplementation->GetpLogic();
		ASSERT(l_pLogic != NULL);

		// Get profile timeout from config.
		const double l_da = l_pImplementation->GetpProfile()->GetuiNomAccDec();
		const double l_dvo = l_pLogic->MakeHardwareVelocity(l_pImplementation->GetpProfile()->GetuiSpeedStartup());

		// State if false.
		bool l_bHighPrioCmd = false, l_bLimitHit = false;

		// Increase motor velocity.
		double l_dDeltaT = 0, l_dSpeed = 0;

		l_pLogic->SetTimeBaseToNow();
		l_pLogic->ResetIteration(eIT1);
		CO_TRACE(ST_ID, _T("Starting Acceleration"));

		do
		{
			l_pLogic->Accelerate(l_dDeltaT, l_dSpeed, l_da, l_dvo);

			l_dSpeed = GetpContext(p_pContext)->GetpHwConnection()->SetVelocity(l_dSpeed);
			
			// First iteration.
			if (l_pLogic->GetdwCurIterationCnt() < 1)
			{
				// First iteration.
				GetpContext(p_pContext)->GetpHwConnection()->SetValid(eStepsAndVelocityValid);

			}
			else
			{
				// Next iterations.
				GetpContext(p_pContext)->GetpHwConnection()->SetValid(eVelocityValid);
			}

            DWORD l_dwTimeout, l_dwNominalTime, l_dwMissedTime, l_dwMissedSteps;
            ComputeTiming(l_pLogic, l_dDeltaT, l_dwTimeout, l_dwNominalTime, l_dwMissedTime, l_dwMissedSteps);

			ECOInterruptReason l_eReason = eIRTimeout;

			CString l_sStr;
			l_sStr.Format(_T("MissedSteps=%d, MissedTime=%d, ComputedTimeout=%d"), l_dwMissedSteps, l_dwMissedTime, l_dwTimeout);
			CO_TRACE(ST_ID, (LPCTSTR)l_sStr);

			if (l_pLogic->GetdwCurIterationCnt() < l_pLogic->GetdwCurIterations())
			{
				// Timer
				l_eReason = p_pContext->WaitOnActionDone(
					l_pSyncObj, 
					CO_WAKE_MASK_CMD_ABOVE_NORMAL+CO_WAKE_MASK_CMD_HIGH+CO_WAKE_MASK_ACTIONS_ALL, 
					l_dwTimeout);
			}

			switch(l_eReason)
			{
			case eIRActionsDone:
				// 
				ASSERT(false);
				break;

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
					{
					// Soft limit hit. false --> do nothing
					l_bLimitHit = OnSoftLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
					}
					break;

				case ePILimitHardEdgeFalling:
				case ePILimitHardEdgeRaising:
					{
					// Hard limit hit. true --> stop iteration and exit state.
					l_bLimitHit = OnHardLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
					break;
					}

				default:
					ASSERT(false);
				}
				}
				break;

			case eIRCmdHigh:
				{
				// Connectionlost(), Stop(), StopImmediately()
				// (not impl), Abort(), Suspend-resume()
				//
				l_bHighPrioCmd = true;

				CSTHardwareConnection *l_pHwConn = GetpContext(p_pContext)->GetpHwConnection();
				CSTPositionMachine *l_pPosMach = GetpContext(p_pContext)->GetpPositionMachine();

				GetpContext(p_pContext)->GetpPositionMachine()->SetuiSearchDistance(0);
				GetpContext(p_pContext)->GetpLogic()->Ramp();

				// correct position
				l_pPosMach->TrackPosition();

				// get steps to stop proper
				int l_iSteps = (int) l_pLogic->GetdbS1();

				// get actual moving direction
				EPIMotorPolarity l_ePolarity = l_pPosMach->GetePolarity();

				switch (l_ePolarity)
				{
					case ePIMotorPolarityNormal:
						{
							l_iSteps *= 1;
						}
						break;

					case ePIMotorPolarityReverse:
						{
							l_iSteps *= -1;
						}
						break;

					default:
						ASSERT(false);

				}

                // make new "moverelative" to keep the position.
				l_pPosMach->MoveRelative( l_iSteps );

				// after stop is executed, write new end position to hardware
				GetpContext(p_pContext)->GetpHwConnection()->SetSteps( (DWORD)l_pLogic->GetdbS1() );
				GetpContext(p_pContext)->GetpHwConnection()->SetValid( eStepsValid );
				///////////////////////////////////////////////////////////////////////

				}
				break;

			case eIRTimeout:
				// control acceleration finished? exit?
				break;

			default:
				ASSERT(false);
				break;
			}
		} while (!l_bLimitHit && !l_bHighPrioCmd &&
			     l_pLogic->NextIterationStep());

		if (l_bHighPrioCmd)
		{
			// Change state.
			p_pContext->ChangeState(CSTStateMovingDecreaseToStop::GetInstance());
		}
		else if (l_bLimitHit)
		{
			// do nothing
		}
		else
		{
			if (l_pLogic->GetbNoRunSpeed())
			{
				// Trace act. pos.
				int l_iNomPos = (int)l_pLogic->GetdbS1();
				int l_iActPos = abs(GetpContext(p_pContext)->GetpHwConnection()->GetRelativePos(l_iNomPos));
				l_pLogic->WatchStepsDeviation(l_iNomPos, l_iActPos);

				CString l_sStr;
				l_sStr.Format(_T("Step deviation at increase speed end: %d, Nom=%d,Act=%d"), l_iNomPos-l_iActPos, l_iNomPos, l_iActPos);
				CO_TRACE(ST_ID, (LPCTSTR)l_sStr);

				// Go to search distance or not.
				if ( GetpContext(p_pContext)->GetpPositionMachine()->GetuiSearchDistance() != 0 )
				{
					p_pContext->ChangeState(CSTStateMovingDecreaseToSearchSpeed::GetInstance());
				}
				else
				{
					p_pContext->ChangeState(CSTStateMovingDecreaseToStop::GetInstance());
				}
			}
			else
			{
				CO_TRACE1(ST_ID, _T("Reached End Speed %d"), (DWORD)l_dSpeed);
				CO_TRACE1(ST_ID, _T("Changing to run speed at time %.5f"), l_pLogic->GetDeltaTime());
				p_pContext->ChangeState(CSTStateMovingRunSpeed::GetInstance());
			}
		}

	}
	catch(...)
	{
		throw;
	}

  //## end CSTStateMovingIncreaseSpeed::Do%1047971043.body
}

// Additional Declarations
  //## begin CSTStateMovingIncreaseSpeed%3E71A1440167.declarations preserve=yes
  //## end CSTStateMovingIncreaseSpeed%3E71A1440167.declarations

// Class CSTStateMovingRunSpeed 

//## begin CSTStateMovingRunSpeed::pInstance%3E75C8B601AB.role preserve=no  public: static CSTStateMovingRunSpeed {1..1 -> 1..1RFHN}
CSTStateMovingRunSpeed *CSTStateMovingRunSpeed::m_pInstance = NULL;
//## end CSTStateMovingRunSpeed::pInstance%3E75C8B601AB.role


CSTStateMovingRunSpeed::CSTStateMovingRunSpeed()
  //## begin CSTStateMovingRunSpeed::CSTStateMovingRunSpeed%.hasinit preserve=no
  //## end CSTStateMovingRunSpeed::CSTStateMovingRunSpeed%.hasinit
  //## begin CSTStateMovingRunSpeed::CSTStateMovingRunSpeed%.initialization preserve=yes
  //## end CSTStateMovingRunSpeed::CSTStateMovingRunSpeed%.initialization
{
  //## begin CSTStateMovingRunSpeed::CSTStateMovingRunSpeed%.body preserve=yes
  //## end CSTStateMovingRunSpeed::CSTStateMovingRunSpeed%.body
}


CSTStateMovingRunSpeed::~CSTStateMovingRunSpeed()
{
  //## begin CSTStateMovingRunSpeed::~CSTStateMovingRunSpeed%.body preserve=yes
  //## end CSTStateMovingRunSpeed::~CSTStateMovingRunSpeed%.body
}



//## Other Operations (implementation)
void CSTStateMovingRunSpeed::Create ()
{
  //## begin CSTStateMovingRunSpeed::Create%1047892495.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSTStateMovingRunSpeed();
  //## end CSTStateMovingRunSpeed::Create%1047892495.body
}

void CSTStateMovingRunSpeed::Delete ()
{
  //## begin CSTStateMovingRunSpeed::Delete%1047892496.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CSTStateMovingRunSpeed::Delete%1047892496.body
}

CSTStateMovingRunSpeed* CSTStateMovingRunSpeed::GetInstance ()
{
  //## begin CSTStateMovingRunSpeed::GetInstance%1047892497.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateMovingRunSpeed::GetInstance%1047892497.body
}

void CSTStateMovingRunSpeed::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateMovingRunSpeed::Do%1047971044.body preserve=yes

	// Synchronisation object smart pointer.
	CCOSyncObjectPtr l_pSyncObj = NULL; 
	try
	{
		// New object.
		l_pSyncObj = new CCOSyncObject();

		CSTLogic *l_pLogic = GetpContext(p_pContext)->GetpLogic();
		ASSERT(l_pLogic != NULL);

		// Trace act. pos.
		int l_iNomPos = (int)(l_pLogic->GetdbS1());
		int l_iActPos = abs(GetpContext(p_pContext)->GetpHwConnection()->GetRelativePos(l_iNomPos));
		l_pLogic->WatchStepsDeviation(l_iNomPos, l_iActPos);

		CString l_sStr;
		l_sStr.Format(_T("Position deviation after increasing end: %d, Nom=%d,Act=%d"), l_iNomPos-l_iActPos, l_iNomPos, l_iActPos);
		CO_TRACE(ST_ID, (LPCTSTR)l_sStr);

		bool l_bLimitHit = false, l_bHighPrioCmd = false, l_bRun = true;

		// Set run speed.
		GetpContext(p_pContext)->GetpHwConnection()->SetVelocity(l_pLogic->GetdbVEnd());
		GetpContext(p_pContext)->GetpHwConnection()->SetValid(eVelocityValid);		

		// Get start time.
		double l_dbStartTime = 0.0, l_dbEndTime = 0.0;
		DWORD l_dwElapsedTime = 0;
		BOOL l_bRet = l_pLogic->GetTickNumber(l_dbStartTime);
		ASSERT(l_bRet);
		DWORD l_dwTimeout = (DWORD)(l_pLogic->GetdbRunDuration() * 1000.0);

		do
		{
			// Timer
			ECOInterruptReason l_eReason = p_pContext->WaitOnActionDone(
				l_pSyncObj, 
				CO_WAKE_MASK_CMD_ABOVE_NORMAL+CO_WAKE_MASK_CMD_HIGH+CO_WAKE_MASK_ACTIONS_ALL,
				l_dwTimeout);
			
			// End time.
			BOOL l_bRet = l_pLogic->GetTickNumber(l_dbEndTime);
			ASSERT(l_bRet);

			l_dwElapsedTime = (DWORD)(l_dbEndTime - l_dbStartTime);

			if (l_dwTimeout >= l_dwElapsedTime)
			{
				l_dwTimeout -= l_dwElapsedTime;
			}
			else
			{
				l_dwTimeout = 0;
				l_bRun = false;
			}
			
			switch(l_eReason)
			{
			case eIRActionsDone:
				// 
				ASSERT(false);
				break;

			case eIRCmdAboveNormal:
				{ // limit hit. kind of limit? do we have to exit? ChangeState(this);

				// Get limit switch ID which was hit.
				CPIObjIdentification* l_pObjectIdent = GetpContext(p_pContext)->GetpLimitHandler()->GetpLimitSwitchIDHit();

				// Get limit switch which was hit.
				CSTLimitSwitch* l_pLimitSwitch = GetpContext(p_pContext)->GetpLimitHandler()->FindLimitSwitch(l_pObjectIdent);

				// LimitSwitch characteristics.
				EPILimitCharacteristics l_ePILimitCharacter = l_pLimitSwitch->GeteCurLimitCharacteristics();

				switch (l_ePILimitCharacter)
					{
					case ePILimitSoftEdgeFalling:
					case ePILimitSoftEdgeRaising:
						{
							// Soft limit hit.
							l_bLimitHit = OnSoftLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
							l_pLogic->GetTickNumber(l_dbStartTime);
						}
						break;

					case ePILimitHardEdgeFalling:
					case ePILimitHardEdgeRaising:
						// Hard limit hit.
						{
							l_bLimitHit = OnHardLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
							l_bRun = false;
							//  : calculate new end position and write result to the hardware 
						}
						break;

					default:
						ASSERT(false);
					}
				}
				break;

			case eIRCmdHigh:
				{

				// Connectionlost(), Stop(), StopImmediately()
				// (not impl), Abort(), Suspend-resume()

				// Stop	//////////////////////////////////////////////////////////////////
				l_bHighPrioCmd = true;
				l_bRun = false;

				CSTHardwareConnection *l_pHwConn = GetpContext(p_pContext)->GetpHwConnection();
				ASSERT(l_pHwConn != NULL);

				CSTPositionMachine *l_pPosMach = GetpContext(p_pContext)->GetpPositionMachine();
				ASSERT(l_pPosMach != NULL);

				GetpContext(p_pContext)->GetpPositionMachine()->SetuiSearchDistance(0);
				GetpContext(p_pContext)->GetpLogic()->Ramp();

				// correct position
				l_pPosMach->TrackPosition();

				// get steps to stop proper
				int l_iSteps = (int) l_pLogic->GetdbS1();

				// get actual moving direction
				EPIMotorPolarity l_ePolarity = l_pPosMach->GetePolarity();

				switch (l_ePolarity)
				{
					case ePIMotorPolarityNormal:
						{
							l_iSteps *= 1;
						}
						break;

					case ePIMotorPolarityReverse:
						{
							l_iSteps *= -1;
						}
						break;

					default:
						ASSERT(false);

				}

                // make new "moverelative" to keep the position.
				l_pPosMach->MoveRelative( l_iSteps );

				// after stop is executed, write new end position to hardware
				GetpContext(p_pContext)->GetpHwConnection()->SetSteps( (DWORD)l_pLogic->GetdbS1() );
				GetpContext(p_pContext)->GetpHwConnection()->SetValid( eStepsValid );
				///////////////////////////////////////////////////////////////////////

				}
				break;

			case eIRTimeout:
				{
					// Trace act. pos.
					l_iNomPos = (int)(l_pLogic->GetdbS2()+l_pLogic->GetdbS1());
					l_iActPos = abs(GetpContext(p_pContext)->GetpHwConnection()->GetRelativePos(l_iNomPos));
					l_pLogic->WatchStepsDeviation(l_iNomPos, l_iActPos);

					l_sStr = _T("");
					l_sStr.Format(_T("Position deviation at run speed end: %d, Nom=%d,Act=%d"), l_iNomPos - l_iActPos, l_iNomPos, l_iActPos);
					CO_TRACE(ST_ID, (LPCTSTR)l_sStr);

					l_bRun = false;
				}
				break;

			default:
				ASSERT(false);
			}
		}
		while(l_bRun);

		bool l_bSearchDistanceNotNull = ( GetpContext(p_pContext)->GetpPositionMachine()->GetuiSearchDistance() ) > 0;


		if (l_bHighPrioCmd)
		{
			// only stop case is implemented
			p_pContext->ChangeState(CSTStateMovingDecreaseToStop::GetInstance());
		}
		else if(l_bLimitHit)
		{
			// do nothing
		}
		else 
		{
			// Searchspeed activ
			if ( l_bSearchDistanceNotNull )
			{
				p_pContext->ChangeState(CSTStateMovingDecreaseToSearchSpeed::GetInstance());
			}
			else
			{
				CO_TRACE1(ST_ID, _T("Changing to decreasing at time %.5f"), l_pLogic->GetDeltaTime());
				p_pContext->ChangeState(CSTStateMovingDecreaseToStop::GetInstance());
			}
		}
	}
	catch(...)
	{
		throw;
	}

  //## end CSTStateMovingRunSpeed::Do%1047971044.body
}

bool CSTStateMovingRunSpeed::OnHardLimit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID)
{
  //## begin CSTStateMovingRunSpeed::OnHardLimit%1065684039.body preserve=yes
	CSTLimitSwitch *l_pLimitSwitch = GetpContext(p_pContext)->GetpLimitHandler()->FindLimitSwitch(p_pLimitID);
	
	EPILimitAction eLimitAction = l_pLimitSwitch->GeteLimitAction();

	switch (eLimitAction)	
	{
	case ePILimitActionDecelerate:
		{
			CSTLogic *l_pLogic = GetpContext(p_pContext)->GetpLogic();
			ASSERT(l_pLogic != NULL);

			CSTHardwareConnection *l_pHwConn = GetpContext(p_pContext)->GetpHwConnection();
			ASSERT(l_pHwConn != NULL);

			CSTPositionMachine *l_pPosMach = GetpContext(p_pContext)->GetpPositionMachine();
			ASSERT(l_pPosMach != NULL);

			GetpContext(p_pContext)->GetpPositionMachine()->SetuiSearchDistance(0);
			GetpContext(p_pContext)->GetpLogic()->Ramp();

			// correct position
			l_pPosMach->TrackPosition();

			// get steps to stop proper
			int l_iSteps = (int) l_pLogic->GetdbS1();

			// get actual moving direction
			EPIMotorPolarity l_ePolarity = l_pPosMach->GetePolarity();

			switch (l_ePolarity)
			{
				case ePIMotorPolarityNormal:
					{
						l_iSteps *= 1;
					}
					break;

				case ePIMotorPolarityReverse:
					{
						l_iSteps *= -1;
					}
					break;

				default:
					ASSERT(false);

			}

            // make new "moverelative" to keep the position.
			l_pPosMach->MoveRelative( l_iSteps );
                        
			// after stop is executed, write new end position to hardware
			GetpContext(p_pContext)->GetpHwConnection()->SetSteps( (DWORD)l_pLogic->GetdbS1() );
			GetpContext(p_pContext)->GetpHwConnection()->SetValid( eStepsValid );

			// bit for the exception
			GetpContext(p_pContext)->GetpLogic()->SetbLimitHit(true);

			// state change
			p_pContext->ChangeState(CSTStateMovingDecreaseToStop::GetInstance());

		}
		break;

	case ePILimitActionStop:
		{
		// bit for the exception
		GetpContext(p_pContext)->GetpLogic()->SetbLimitHit(true);

		// change state
		p_pContext->ChangeState(CSTStateIdle::GetInstance());
		}
		break;

	case ePILimitActionFootprint:
	case ePILimitActionDisabled:
		{
			ASSERT(false);
		}
		break;
	}

	return true;
  //## end CSTStateMovingRunSpeed::OnHardLimit%1065684039.body
}

// Additional Declarations
  //## begin CSTStateMovingRunSpeed%3E71A1530212.declarations preserve=yes
  //## end CSTStateMovingRunSpeed%3E71A1530212.declarations

// Class CSTStateMovingDecreaseToSearchSpeed 

//## begin CSTStateMovingDecreaseToSearchSpeed::pInstance%3E75C8C70073.role preserve=no  public: static CSTStateMovingDecreaseToSearchSpeed {1..1 -> 1..1RFHN}
CSTStateMovingDecreaseToSearchSpeed *CSTStateMovingDecreaseToSearchSpeed::m_pInstance = NULL;
//## end CSTStateMovingDecreaseToSearchSpeed::pInstance%3E75C8C70073.role


CSTStateMovingDecreaseToSearchSpeed::CSTStateMovingDecreaseToSearchSpeed()
  //## begin CSTStateMovingDecreaseToSearchSpeed::CSTStateMovingDecreaseToSearchSpeed%.hasinit preserve=no
  //## end CSTStateMovingDecreaseToSearchSpeed::CSTStateMovingDecreaseToSearchSpeed%.hasinit
  //## begin CSTStateMovingDecreaseToSearchSpeed::CSTStateMovingDecreaseToSearchSpeed%.initialization preserve=yes
  //## end CSTStateMovingDecreaseToSearchSpeed::CSTStateMovingDecreaseToSearchSpeed%.initialization
{
  //## begin CSTStateMovingDecreaseToSearchSpeed::CSTStateMovingDecreaseToSearchSpeed%.body preserve=yes
  //## end CSTStateMovingDecreaseToSearchSpeed::CSTStateMovingDecreaseToSearchSpeed%.body
}


CSTStateMovingDecreaseToSearchSpeed::~CSTStateMovingDecreaseToSearchSpeed()
{
  //## begin CSTStateMovingDecreaseToSearchSpeed::~CSTStateMovingDecreaseToSearchSpeed%.body preserve=yes
  //## end CSTStateMovingDecreaseToSearchSpeed::~CSTStateMovingDecreaseToSearchSpeed%.body
}



//## Other Operations (implementation)
void CSTStateMovingDecreaseToSearchSpeed::Create ()
{
  //## begin CSTStateMovingDecreaseToSearchSpeed::Create%1047892498.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSTStateMovingDecreaseToSearchSpeed();
  //## end CSTStateMovingDecreaseToSearchSpeed::Create%1047892498.body
}

void CSTStateMovingDecreaseToSearchSpeed::Delete ()
{
  //## begin CSTStateMovingDecreaseToSearchSpeed::Delete%1047892499.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CSTStateMovingDecreaseToSearchSpeed::Delete%1047892499.body
}

CSTStateMovingDecreaseToSearchSpeed* CSTStateMovingDecreaseToSearchSpeed::GetInstance ()
{
  //## begin CSTStateMovingDecreaseToSearchSpeed::GetInstance%1047892500.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateMovingDecreaseToSearchSpeed::GetInstance%1047892500.body
}

void CSTStateMovingDecreaseToSearchSpeed::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateMovingDecreaseToSearchSpeed::Do%1047971045.body preserve=yes

	// Synchronisation object smart pointer.
	CCOSyncObjectPtr l_pSyncObj = NULL; 
	try
	{
		// New object.
		l_pSyncObj = new CCOSyncObject();

		// Pointer to implementation.
		CSTStepperMotorImplementation *l_pImplementation= GetpContext(p_pContext);
		ASSERT(l_pImplementation != NULL);

		// Pointer to logic.
		CSTLogic *l_pLogic = l_pImplementation->GetpLogic();
		ASSERT(l_pLogic != NULL);

		l_pLogic->ResetIteration(eIT3);
		
		// Get timeout from config.
		const double l_da = -(double)l_pImplementation->GetpProfile()->GetuiNomAccDec();
		const double l_dvo = l_pLogic->GetdbVEnd() + l_pLogic->GetDeltaSpeed(l_da);

		// State if false.
		bool l_bHighPrioCmd = false, l_bLimitHit = false;

		// Increase motor velocity.
		double l_dDeltaT = 0, l_dSpeed = 0;

		l_pLogic->SetTimeBaseToNow();
		CO_TRACE(ST_ID, _T("Starting Decceleration"));

		do
		{
			l_pLogic->Accelerate(l_dDeltaT, l_dSpeed, l_da, l_dvo);

			GetpContext(p_pContext)->GetpHwConnection()->SetVelocity(l_dSpeed);
			GetpContext(p_pContext)->GetpHwConnection()->SetValid(eVelocityValid);

			CO_TRACE1(ST_ID, _T("Descreasing Speed : %d"), (DWORD)l_dSpeed);

			ECOInterruptReason l_eReason = eIRTimeout;
			// nominal timeout
            DWORD l_dwTimeout, l_dwNominalTime, l_dwMissedTime, l_dwMissedSteps;
            ComputeTiming(l_pLogic, l_dDeltaT, l_dwTimeout, l_dwNominalTime, l_dwMissedTime, l_dwMissedSteps);
			CString l_sStr;
			l_sStr.Format(_T("MissedSteps=%d, MissedTime=%d, ComputedTimeout=%d"), l_dwMissedSteps, l_dwMissedTime, l_dwTimeout);
			CO_TRACE(ST_ID, (LPCTSTR)l_sStr);

			if (l_pLogic->GetdwCurIterationCnt() < l_pLogic->GetdwCurIterations())
			{
				// Timer
				l_eReason = p_pContext->WaitOnActionDone(
					l_pSyncObj, 
					CO_WAKE_MASK_CMD_ABOVE_NORMAL+CO_WAKE_MASK_CMD_HIGH+CO_WAKE_MASK_ACTIONS_ALL, 
					l_dwTimeout);
			}

			switch(l_eReason)
			{
			case eIRActionsDone:
				// 
				ASSERT(false);
				break;

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
					{
					// Soft limit hit.
					l_bLimitHit = OnSoftLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
					}
					break;

				case ePILimitHardEdgeFalling:
				case ePILimitHardEdgeRaising:
					{
					// Hard limit hit.
					l_bLimitHit = OnHardLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
					// Stop the iteration.
					}
					break;

				default:
					ASSERT(false);
				}
				}
				break;

			case eIRCmdHigh:
				{
				// Connectionlost(), Stop(), StopImmediately()
				// (not impl), Abort(), Suspend-resume()
				//
				l_bHighPrioCmd = true;
				}
				break;

			case eIRTimeout:
				// control acceleration finished? exit?
				break;

			default:
				ASSERT(false);
				break;
			}
		} while (!l_bLimitHit && !l_bHighPrioCmd &&
			     l_pLogic->NextIterationStep());

		if (l_bLimitHit)
		{	
			// Do nothing.
		}
		else
		{
			CO_TRACE1(ST_ID, _T("Changing to search speed at time %.5f"), l_pLogic->GetDeltaTime());
			p_pContext->ChangeState(CSTStateMovingSearchSpeed::GetInstance());
		}
	}
	catch(...)
	{
		throw;
	}
  //## end CSTStateMovingDecreaseToSearchSpeed::Do%1047971045.body
}

// Additional Declarations
  //## begin CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.declarations preserve=yes
  //## end CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.declarations

// Class CSTStateMovingSearchSpeed 

//## begin CSTStateMovingSearchSpeed::pInstance%3E75C8C4015D.role preserve=no  public: static CSTStateMovingSearchSpeed {1..1 -> 1..1RFHN}
CSTStateMovingSearchSpeed *CSTStateMovingSearchSpeed::m_pInstance = NULL;
//## end CSTStateMovingSearchSpeed::pInstance%3E75C8C4015D.role


CSTStateMovingSearchSpeed::CSTStateMovingSearchSpeed()
  //## begin CSTStateMovingSearchSpeed::CSTStateMovingSearchSpeed%.hasinit preserve=no
  //## end CSTStateMovingSearchSpeed::CSTStateMovingSearchSpeed%.hasinit
  //## begin CSTStateMovingSearchSpeed::CSTStateMovingSearchSpeed%.initialization preserve=yes
  //## end CSTStateMovingSearchSpeed::CSTStateMovingSearchSpeed%.initialization
{
  //## begin CSTStateMovingSearchSpeed::CSTStateMovingSearchSpeed%.body preserve=yes
  //## end CSTStateMovingSearchSpeed::CSTStateMovingSearchSpeed%.body
}


CSTStateMovingSearchSpeed::~CSTStateMovingSearchSpeed()
{
  //## begin CSTStateMovingSearchSpeed::~CSTStateMovingSearchSpeed%.body preserve=yes
  //## end CSTStateMovingSearchSpeed::~CSTStateMovingSearchSpeed%.body
}



//## Other Operations (implementation)
void CSTStateMovingSearchSpeed::Create ()
{
  //## begin CSTStateMovingSearchSpeed::Create%1047892501.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSTStateMovingSearchSpeed();
  //## end CSTStateMovingSearchSpeed::Create%1047892501.body
}

void CSTStateMovingSearchSpeed::Delete ()
{
  //## begin CSTStateMovingSearchSpeed::Delete%1047892502.body preserve=yes
	if(m_pInstance != NULL)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CSTStateMovingSearchSpeed::Delete%1047892502.body
}

CSTStateMovingSearchSpeed* CSTStateMovingSearchSpeed::GetInstance ()
{
  //## begin CSTStateMovingSearchSpeed::GetInstance%1047892503.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateMovingSearchSpeed::GetInstance%1047892503.body
}

void CSTStateMovingSearchSpeed::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateMovingSearchSpeed::Do%1047971046.body preserve=yes

	// Synchronisation object smart pointer.
	CCOSyncObjectPtr l_pSyncObj = NULL; 
	try
	{
		// New object.
		l_pSyncObj = new CCOSyncObject();

		CSTLogic *l_pLogic = GetpContext(p_pContext)->GetpLogic();
		ASSERT(l_pLogic != NULL);

		bool l_bLimitHit = false, l_bHighPrioCmd = false;

		// Search speed from profile.
		UINT l_uiSearchSpeed = GetpContext(p_pContext)->GetpProfile()->GetuiSpeedSearch();

		// Search speed converted to hardware world.
		DWORD l_dwSearchSpeed = (DWORD)(0.5 + l_pLogic->MakeHardwareVelocity((double)l_uiSearchSpeed));

		GetpContext(p_pContext)->GetpHwConnection()->SetVelocity(l_dwSearchSpeed);
		GetpContext(p_pContext)->GetpHwConnection()->SetValid(eVelocityValid);

		// Timer.
		ECOInterruptReason l_eReason = p_pContext->WaitOnActionDone(
			l_pSyncObj, 
			CO_WAKE_MASK_CMD_ABOVE_NORMAL+CO_WAKE_MASK_CMD_HIGH+CO_WAKE_MASK_ACTIONS_ALL, 
			(DWORD)(l_pLogic->GetdbSearchDuration() * 1000.0));

		switch(l_eReason)
		{
		case eIRActionsDone:
			// 
			ASSERT(false);
			break;

		case eIRCmdAboveNormal:
			{ // limit hit. kind of limit? do we have to exit? ChangeState(this);

				// Get limit switch ID which was hit.
				CPIObjIdentification* l_pObjectIdent = GetpContext(p_pContext)->GetpLimitHandler()->GetpLimitSwitchIDHit();

				// Get limit switch which was hit.
				CSTLimitSwitch* l_pLimitSwitch = GetpContext(p_pContext)->GetpLimitHandler()->FindLimitSwitch(l_pObjectIdent);

				// LimitSwitch characteristics.
				EPILimitCharacteristics l_ePILimitCharacter = l_pLimitSwitch->GeteCurLimitCharacteristics();

				switch (l_ePILimitCharacter)
					{
					case ePILimitSoftEdgeFalling:
					case ePILimitSoftEdgeRaising:
						{
						// Soft limit hit.
						// True: Do nothing just get out.
						l_bLimitHit = OnSoftLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
						break;
						}

					case ePILimitHardEdgeFalling:
					case ePILimitHardEdgeRaising:
						{
						// Hard limit hit.
						// True: Do nothing just get out.
						l_bLimitHit = OnHardLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
						}
						break;

					default:
						ASSERT(false);
					}
				}
			break;

		case eIRCmdHigh:
			{
			// Connectionlost(), Stop(), StopImmediately()
			// (not impl), Abort(), Suspend-resume()
			//
			l_bHighPrioCmd = true;
			}
			break;

		case eIRTimeout:
			{
			// control
			}
			break;

		default:
			ASSERT(false);
		}

		// Trace act. pos.
		int l_iNomPos = (int) (l_pLogic->GetdbS2()+l_pLogic->GetdbS1()+l_pLogic->GetdbS3()+l_pLogic->GetdbS4());
		int l_iActPos = abs(GetpContext(p_pContext)->GetpHwConnection()->GetRelativePos(l_iNomPos));
		CString l_sStr(_T(""));
		l_sStr.Format(_T("Position deviation at search speed end: %d, Nom=%d,Act=%d"), l_iNomPos-l_iActPos, l_iNomPos,l_iActPos);
		CO_TRACE(ST_ID, (LPCTSTR)l_sStr);

		l_pLogic->WatchStepsDeviation(l_iNomPos, l_iActPos);

		if (l_bHighPrioCmd || l_bLimitHit)
		{
			// Do nothing. State change made already in command.
		}
		else
		{
			p_pContext->ChangeState(CSTStateMovingEndPosition::GetInstance());
		}
	}
	catch(...)
	{
		throw;
	}
  //## end CSTStateMovingSearchSpeed::Do%1047971046.body
}

bool CSTStateMovingSearchSpeed::OnSoftLimit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID)
{
  //## begin CSTStateMovingSearchSpeed::OnSoftLimit%1065684035.body preserve=yes

	// bit for the exception
	GetpContext(p_pContext)->GetpLogic()->SetbLimitHit(true);

	p_pContext->ChangeState(CSTStateIdle::GetInstance());
	return true;

  //## end CSTStateMovingSearchSpeed::OnSoftLimit%1065684035.body
}

// Additional Declarations
  //## begin CSTStateMovingSearchSpeed%3E71A15C0128.declarations preserve=yes
  //## end CSTStateMovingSearchSpeed%3E71A15C0128.declarations

// Class CSTStateMovingDecreaseToStop 

//## begin CSTStateMovingDecreaseToStop::pInstance%3E75C8C1039F.role preserve=no  public: static CSTStateMovingDecreaseToStop {1..1 -> 1..1RFHN}
CSTStateMovingDecreaseToStop *CSTStateMovingDecreaseToStop::m_pInstance = NULL;
//## end CSTStateMovingDecreaseToStop::pInstance%3E75C8C1039F.role


CSTStateMovingDecreaseToStop::CSTStateMovingDecreaseToStop()
  //## begin CSTStateMovingDecreaseToStop::CSTStateMovingDecreaseToStop%.hasinit preserve=no
  //## end CSTStateMovingDecreaseToStop::CSTStateMovingDecreaseToStop%.hasinit
  //## begin CSTStateMovingDecreaseToStop::CSTStateMovingDecreaseToStop%.initialization preserve=yes
  //## end CSTStateMovingDecreaseToStop::CSTStateMovingDecreaseToStop%.initialization
{
  //## begin CSTStateMovingDecreaseToStop::CSTStateMovingDecreaseToStop%.body preserve=yes
  //## end CSTStateMovingDecreaseToStop::CSTStateMovingDecreaseToStop%.body
}


CSTStateMovingDecreaseToStop::~CSTStateMovingDecreaseToStop()
{
  //## begin CSTStateMovingDecreaseToStop::~CSTStateMovingDecreaseToStop%.body preserve=yes
  //## end CSTStateMovingDecreaseToStop::~CSTStateMovingDecreaseToStop%.body
}



//## Other Operations (implementation)
void CSTStateMovingDecreaseToStop::Create ()
{
  //## begin CSTStateMovingDecreaseToStop::Create%1047892504.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSTStateMovingDecreaseToStop();
  //## end CSTStateMovingDecreaseToStop::Create%1047892504.body
}

void CSTStateMovingDecreaseToStop::Delete ()
{
  //## begin CSTStateMovingDecreaseToStop::Delete%1047892505.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CSTStateMovingDecreaseToStop::Delete%1047892505.body
}

CSTStateMovingDecreaseToStop* CSTStateMovingDecreaseToStop::GetInstance ()
{
  //## begin CSTStateMovingDecreaseToStop::GetInstance%1047892506.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateMovingDecreaseToStop::GetInstance%1047892506.body
}

void CSTStateMovingDecreaseToStop::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateMovingDecreaseToStop::Do%1047971047.body preserve=yes

	// Synchronisation object smart pointer.
	CCOSyncObjectPtr l_pSyncObj = NULL; 
	try
	{
		// New object.
		l_pSyncObj = new CCOSyncObject();

		// Pointer to implementation.
		CSTStepperMotorImplementation *l_pImplementation= GetpContext(p_pContext);
		ASSERT(l_pImplementation != NULL);

		// Pointer to logic.
		CSTLogic *l_pLogic = l_pImplementation->GetpLogic();
		ASSERT(l_pLogic != NULL);

		l_pLogic->ResetIteration(eIT5);
		
		// Get timeout from config.
		const double l_da = -(double)l_pImplementation->GetpProfile()->GetuiNomAccDec();
		const double l_dvo = l_pLogic->GetdbVEnd() + l_pLogic->GetDeltaSpeed(l_da);

		// State if false.
		bool l_bHighPrioCmd = false, l_bLimitHit = false;

		// Increase motor velocity.
		double l_dDeltaT = 0, l_dSpeed = 0;

		l_pLogic->SetTimeBaseToNow();
		CO_TRACE(ST_ID, _T("Starting Decceleration"));

		do
		{
			l_pLogic->Accelerate(l_dDeltaT, l_dSpeed, l_da, l_dvo);
			
			GetpContext(p_pContext)->GetpHwConnection()->SetVelocity(l_dSpeed);
			GetpContext(p_pContext)->GetpHwConnection()->SetValid(eVelocityValid);

			CO_TRACE1(ST_ID, _T("Descreasing speed : %d"), (DWORD)l_dSpeed);

			ECOInterruptReason l_eReason = eIRTimeout;
			// nominal timeout

            DWORD l_dwTimeout, l_dwNominalTime, l_dwMissedTime, l_dwMissedSteps;
            ComputeTiming(l_pLogic, l_dDeltaT, l_dwTimeout, l_dwNominalTime, l_dwMissedTime, l_dwMissedSteps);
			CString l_sStr;
			l_sStr.Format(_T("MissedSteps=%d, MissedTime=%d, ComputedTimeout=%d"), l_dwMissedSteps, l_dwMissedTime, l_dwTimeout);
			CO_TRACE(ST_ID, (LPCTSTR)l_sStr);

			if (l_pLogic->GetdwCurIterationCnt() < l_pLogic->GetdwCurIterations())
			{
				// Timer
				l_eReason = p_pContext->WaitOnActionDone(
					l_pSyncObj, 
					CO_WAKE_MASK_CMD_ABOVE_NORMAL+CO_WAKE_MASK_CMD_HIGH+CO_WAKE_MASK_ACTIONS_ALL, 
					l_dwTimeout);
			}

			switch(l_eReason)
			{
			case eIRActionsDone:
				// 
				ASSERT(false);
				break;

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
					// Stop the iteration.
					break;

				default:
					ASSERT(false);
				}
				}
				break;

			case eIRCmdHigh:
				{
				// Connectionlost(), Stop(), StopImmediately()
				// (not impl), Abort(), Suspend-resume()
				//
				l_bHighPrioCmd = true;
				}
				break;

			case eIRTimeout:
				// control acceleration finished? exit?
				break;

			default:
				ASSERT(false);
				break;
			}
		} while (!l_bLimitHit && !l_bHighPrioCmd &&
			     l_pLogic->NextIterationStep());

		if (l_bLimitHit)
		{
			// Do nothing.
		}
		else
		{	
			CO_TRACE1(ST_ID, _T("Changing to end position at time %.4f"), l_pLogic->GetDeltaTime());
			p_pContext->ChangeState(CSTStateMovingEndPosition::GetInstance());
		}

	}
	catch(...)
	{
		throw;
	}
  //## end CSTStateMovingDecreaseToStop::Do%1047971047.body
}

// Additional Declarations
  //## begin CSTStateMovingDecreaseToStop%3E71A1A801A5.declarations preserve=yes
  //## end CSTStateMovingDecreaseToStop%3E71A1A801A5.declarations

// Class CSTStateMovingEndPosition 

//## begin CSTStateMovingEndPosition::pInstance%3E75C8BF01CA.role preserve=no  public: static CSTStateMovingEndPosition {1..1 -> 1..1RFHN}
CSTStateMovingEndPosition *CSTStateMovingEndPosition::m_pInstance = NULL;
//## end CSTStateMovingEndPosition::pInstance%3E75C8BF01CA.role


CSTStateMovingEndPosition::CSTStateMovingEndPosition()
  //## begin CSTStateMovingEndPosition::CSTStateMovingEndPosition%.hasinit preserve=no
  //## end CSTStateMovingEndPosition::CSTStateMovingEndPosition%.hasinit
  //## begin CSTStateMovingEndPosition::CSTStateMovingEndPosition%.initialization preserve=yes
  //## end CSTStateMovingEndPosition::CSTStateMovingEndPosition%.initialization
{
  //## begin CSTStateMovingEndPosition::CSTStateMovingEndPosition%.body preserve=yes
  //## end CSTStateMovingEndPosition::CSTStateMovingEndPosition%.body
}


CSTStateMovingEndPosition::~CSTStateMovingEndPosition()
{
  //## begin CSTStateMovingEndPosition::~CSTStateMovingEndPosition%.body preserve=yes
  //## end CSTStateMovingEndPosition::~CSTStateMovingEndPosition%.body
}



//## Other Operations (implementation)
void CSTStateMovingEndPosition::Create ()
{
  //## begin CSTStateMovingEndPosition::Create%1047892507.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSTStateMovingEndPosition();
  //## end CSTStateMovingEndPosition::Create%1047892507.body
}

void CSTStateMovingEndPosition::Delete ()
{
  //## begin CSTStateMovingEndPosition::Delete%1047892508.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CSTStateMovingEndPosition::Delete%1047892508.body
}

CSTStateMovingEndPosition* CSTStateMovingEndPosition::GetInstance ()
{
  //## begin CSTStateMovingEndPosition::GetInstance%1047892509.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateMovingEndPosition::GetInstance%1047892509.body
}

void CSTStateMovingEndPosition::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateMovingEndPosition::Do%1047971048.body preserve=yes
	
	CCOSyncObjectPtr l_pDummySyncObj = NULL; 
	try
	{
		// Trace act. pos.
		INT l_iNomPos = (INT) GetpContext(p_pContext)->GetpPositionMachine()->GetuiDistance();
		INT l_iActPos = abs(GetpContext(p_pContext)->GetpHwConnection()->GetRelativePos(l_iNomPos));
		//TODO:	GetpContext(p_pContext)->GetpLogic()->WatchStepsDeviation(l_iNomPos, l_iActPos);

		CString l_sStr;
		l_sStr.Format(_T("Position deviation before stoping the motor: %d, Nom=%d,Act=%d"), l_iNomPos-l_iActPos, l_iNomPos, l_iActPos);
		CO_TRACE(ST_ID, (LPCTSTR)l_sStr);

		// get stored sync object from hwconnection
		CCOSyncObject *l_pSyncObject = GetpContext(p_pContext)->GetpHwConnection()->GetpMovingEvent();
		ASSERT( l_pSyncObject != NULL );

		// wait until motor has finished moving
		l_pSyncObject->Synchronize( 5000 );

		// Change state.
		p_pContext->ChangeState(CSTStateIdle::GetInstance());

		// in case we have been stopped we signall the stop sync object
		CCOSyncObject* l_pStopSyncObj = GetpContext(p_pContext)->GetpStopSyncObj();
		if (l_pStopSyncObj != NULL)
		{
			l_pStopSyncObj->SignalCompletion();
			GetpContext(p_pContext)->SetpStopSyncObj(NULL);
		}
	}
	catch(...)
	{
        throw;
	}

  //## end CSTStateMovingEndPosition::Do%1047971048.body
}

// Additional Declarations
  //## begin CSTStateMovingEndPosition%3E71A1AB002E.declarations preserve=yes
  //## end CSTStateMovingEndPosition%3E71A1AB002E.declarations

// Class CSTStateMovingPreparation 

//## begin CSTStateMovingPreparation::pInstance%3E967F990197.role preserve=no  public: static CSTStateMovingPreparation {1..1 -> 1..1RFHN}
CSTStateMovingPreparation *CSTStateMovingPreparation::m_pInstance;
//## end CSTStateMovingPreparation::pInstance%3E967F990197.role


CSTStateMovingPreparation::CSTStateMovingPreparation()
  //## begin CSTStateMovingPreparation::CSTStateMovingPreparation%.hasinit preserve=no
  //## end CSTStateMovingPreparation::CSTStateMovingPreparation%.hasinit
  //## begin CSTStateMovingPreparation::CSTStateMovingPreparation%.initialization preserve=yes
  //## end CSTStateMovingPreparation::CSTStateMovingPreparation%.initialization
{
  //## begin CSTStateMovingPreparation::CSTStateMovingPreparation%.body preserve=yes
  //## end CSTStateMovingPreparation::CSTStateMovingPreparation%.body
}


CSTStateMovingPreparation::~CSTStateMovingPreparation()
{
  //## begin CSTStateMovingPreparation::~CSTStateMovingPreparation%.body preserve=yes
  //## end CSTStateMovingPreparation::~CSTStateMovingPreparation%.body
}



//## Other Operations (implementation)
void CSTStateMovingPreparation::Create ()
{
  //## begin CSTStateMovingPreparation::Create%1050050605.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSTStateMovingPreparation();
  //## end CSTStateMovingPreparation::Create%1050050605.body
}

void CSTStateMovingPreparation::Delete ()
{
  //## begin CSTStateMovingPreparation::Delete%1050050606.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CSTStateMovingPreparation::Delete%1050050606.body
}

CSTStateMovingPreparation* CSTStateMovingPreparation::GetInstance ()
{
  //## begin CSTStateMovingPreparation::GetInstance%1050050607.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateMovingPreparation::GetInstance%1050050607.body
}

void CSTStateMovingPreparation::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateMovingPreparation::Do%1050050608.body preserve=yes

	// Get pointer to implementation.
	CSTStepperMotorImplementation *l_pImplementation= GetpContext(p_pContext);
	ASSERT(l_pImplementation != NULL);

	// Get pointer to limithandler.
	CSTLimitHandler *l_pLimitHandler= l_pImplementation->GetpLimitHandler();
	ASSERT(l_pLimitHandler != NULL);

	// Get pointer to hardware connection.
	CSTHardwareConnection *l_pHwConn= l_pImplementation->GetpHwConnection();
	ASSERT(l_pHwConn != NULL);

	// Start worker thread limit switches.
	l_pLimitHandler->Start();

	// Reset footprints.
	l_pLimitHandler->ResetFootprint();

	// Get pointer to logic.
	CSTLogic * l_pLogic = GetpContext(p_pContext)->GetpLogic();
	ASSERT(l_pLogic != NULL);

	// Init logic controller.
	l_pLogic->Ramp();

	// Get the values calulated in the commands MoveAbsolut(), MoveRelativ(), From the position calculator.
	CSTPositionMachine *l_pPosMachine = GetpContext(p_pContext)->GetpPositionMachine();
	ASSERT(l_pPosMachine != NULL);

	// Get distance.
	UINT l_uiDist = l_pPosMachine->GetuiDistance();

	// Set steps to do.
	l_pHwConn->SetSteps( l_uiDist );


	// open moving event, if distance is bigger 0
	if( l_uiDist > 0 )
	{
		DWORD l_dwId = GetpContext(p_pContext)->GetpConfig()->GetdwIDMovingTerminationEvent();
		CCOSyncObjectPtr l_pSyncObject = IHIInterface::GetInstance()->OpenEvent( l_dwId, eHIUndefined );
		ASSERT( l_pSyncObject != NULL);

		ASSERT( l_pHwConn->GetpMovingEvent() == NULL );
		l_pHwConn->SetpMovingEvent( l_pSyncObject );		
	}

	// state change
	if (l_uiDist == 0)
	{
		// Start-, Endposition are identical. State change to state idle.
		p_pContext->ChangeState(CSTStateIdle::GetInstance());
	}
	else if ( l_pLogic->GetbNoAccelleration() )
	{
		// No accelleration go direct to run speed.
		p_pContext->ChangeState(CSTStateMovingWithStartupSpeed::GetInstance());
	}
	else
	{
		// Regular case.
		p_pContext->ChangeState(CSTStateMovingIncreaseSpeed::GetInstance());
	}
  //## end CSTStateMovingPreparation::Do%1050050608.body
}

// Additional Declarations
  //## begin CSTStateMovingPreparation%3E967F6E0119.declarations preserve=yes
  //## end CSTStateMovingPreparation%3E967F6E0119.declarations

// Class CSTStateMovingWithStartupSpeed 

//## begin CSTStateMovingWithStartupSpeed::pInstance%3ECDD2F201B5.role preserve=no  public: static CSTStateMovingWithStartupSpeed {1..1 -> 1..1RFHN}
CSTStateMovingWithStartupSpeed *CSTStateMovingWithStartupSpeed::m_pInstance = NULL;
//## end CSTStateMovingWithStartupSpeed::pInstance%3ECDD2F201B5.role


CSTStateMovingWithStartupSpeed::CSTStateMovingWithStartupSpeed()
  //## begin CSTStateMovingWithStartupSpeed::CSTStateMovingWithStartupSpeed%.hasinit preserve=no
  //## end CSTStateMovingWithStartupSpeed::CSTStateMovingWithStartupSpeed%.hasinit
  //## begin CSTStateMovingWithStartupSpeed::CSTStateMovingWithStartupSpeed%.initialization preserve=yes
  //## end CSTStateMovingWithStartupSpeed::CSTStateMovingWithStartupSpeed%.initialization
{
  //## begin CSTStateMovingWithStartupSpeed::CSTStateMovingWithStartupSpeed%.body preserve=yes
  //## end CSTStateMovingWithStartupSpeed::CSTStateMovingWithStartupSpeed%.body
}


CSTStateMovingWithStartupSpeed::~CSTStateMovingWithStartupSpeed()
{
  //## begin CSTStateMovingWithStartupSpeed::~CSTStateMovingWithStartupSpeed%.body preserve=yes
  //## end CSTStateMovingWithStartupSpeed::~CSTStateMovingWithStartupSpeed%.body
}



//## Other Operations (implementation)
void CSTStateMovingWithStartupSpeed::Create ()
{
  //## begin CSTStateMovingWithStartupSpeed::Create%1053672324.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSTStateMovingWithStartupSpeed();
  //## end CSTStateMovingWithStartupSpeed::Create%1053672324.body
}

void CSTStateMovingWithStartupSpeed::Delete ()
{
  //## begin CSTStateMovingWithStartupSpeed::Delete%1053672325.body preserve=yes
	if(m_pInstance != NULL)
	{
      delete m_pInstance;
	}
    m_pInstance = NULL;
  //## end CSTStateMovingWithStartupSpeed::Delete%1053672325.body
}

CSTStateMovingWithStartupSpeed* CSTStateMovingWithStartupSpeed::GetInstance ()
{
  //## begin CSTStateMovingWithStartupSpeed::GetInstance%1053672326.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateMovingWithStartupSpeed::GetInstance%1053672326.body
}

void CSTStateMovingWithStartupSpeed::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateMovingWithStartupSpeed::Do%1053672327.body preserve=yes
	
	// Synchronisation object smart pointer.
 	CCOSyncObjectPtr l_pSyncObj = NULL;

	try
	{
		// New object.
		l_pSyncObj = new CCOSyncObject();

		// Pointer to logic.
		CSTLogic *l_pLogic = GetpContext(p_pContext)->GetpLogic();
		ASSERT(l_pLogic != NULL);

		// Set speed.
		GetpContext(p_pContext)->GetpHwConnection()->SetVelocity(l_pLogic->GetdbVEnd());
		GetpContext(p_pContext)->GetpHwConnection()->SetValid(eStepsAndVelocityValid);

		bool l_bHardLimitHit = false, l_bHighPrioCmd = false;

		// Get timeout.
		DWORD l_dwTimeOut = (DWORD)(1000.0 * GetpContext(p_pContext)->GetpLogic()->GetdbRunDuration());

		ECOInterruptReason l_eReason = p_pContext->WaitOnActionDone(l_pSyncObj,
			CO_WAKE_MASK_CMD_ABOVE_NORMAL+CO_WAKE_MASK_CMD_HIGH+CO_WAKE_MASK_ACTIONS_ALL,
			l_dwTimeOut);

		switch(l_eReason)
		{
		case eIRActionsDone:
			// 
			ASSERT(false);
			break;

		case eIRCmdAboveNormal:
			{ // limit hit. kind of limit? do we have to exit? ChangeState(this);

				// Get limit switch ID which was hit.
				CPIObjIdentification* l_pObjectIdent = GetpContext(p_pContext)->GetpLimitHandler()->GetpLimitSwitchIDHit();

				// Get limit switch which was hit.
				CSTLimitSwitch* l_pLimitSwitch = GetpContext(p_pContext)->GetpLimitHandler()->FindLimitSwitch(l_pObjectIdent);

				// LimitSwitch characteristics.
				EPILimitCharacteristics l_ePILimitCharacter = l_pLimitSwitch->GeteCurLimitCharacteristics();

				switch (l_ePILimitCharacter)
					{
					case ePILimitSoftEdgeFalling:
					case ePILimitSoftEdgeRaising:
						{
						// Soft limit hit.
						OnSoftLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
						break;
						}

					case ePILimitHardEdgeFalling:
					case ePILimitHardEdgeRaising:
						// Hard limit hit.
						{
						OnHardLimit(p_pContext, l_pLimitSwitch->GetpLimitID());
						l_bHardLimitHit = true;
						//  : calculate new end position and write result to the hardware 

						}
						break;

					default:
						ASSERT(false);
					}
				}
			break;

		case eIRCmdHigh:
			{
			// Connectionlost(), Stop(), StopImmediately()
			// (not impl), Abort(), Suspend-resume()
			//
			l_bHighPrioCmd = true;
			}
			break;

		case eIRTimeout:
			{
			// control
			}
			break;

		default:
			ASSERT(false);
		}

		// Trace act. pos.
		int l_iNomPos = (int)(l_pLogic->GetdbS2());
		int l_iActPos = abs(GetpContext(p_pContext)->GetpHwConnection()->GetRelativePos(l_iNomPos));
		//l_pLogic->WatchStepsDeviation(l_iNomPos, l_iActPos);

		CString l_sStr(_T(""));
		l_sStr.Format(_T("Position deviation at stepwise end: %d, Nom=%d,Act=%d"), l_iNomPos-l_iActPos, l_iNomPos,l_iActPos);
		CO_TRACE(ST_ID, (LPCTSTR)l_sStr);

		if ( l_bHardLimitHit )
		{
			// Do nothing. State change made already in command.
		}
		else if ( l_bHighPrioCmd )
		{
			p_pContext->ChangeState( CSTStateIdle::GetInstance() );
		}
		else
		{
			p_pContext->ChangeState( CSTStateMovingEndPosition::GetInstance() );
		}

	}
	catch(...)
	{
		throw;
	}

  //## end CSTStateMovingWithStartupSpeed::Do%1053672327.body
}

// Additional Declarations
  //## begin CSTStateMovingWithStartupSpeed%3ECDD21800E9.declarations preserve=yes
  //## end CSTStateMovingWithStartupSpeed%3ECDD21800E9.declarations

//## begin module%3E71A71501D4.epilog preserve=yes
//## end module%3E71A71501D4.epilog
