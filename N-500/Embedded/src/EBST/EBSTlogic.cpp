//## begin module%3E75E2740294.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E75E2740294.cm

//## begin module%3E75E2740294.cp preserve=no
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
//## end module%3E75E2740294.cp

//## Module: EBSTlogic%3E75E2740294; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTlogic.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E75E2740294.additionalIncludes preserve=no
//## end module%3E75E2740294.additionalIncludes

//## begin module%3E75E2740294.includes preserve=yes
#include <math.h>
//## end module%3E75E2740294.includes

// EBSTexcp
#include "EBSTexcp.h"
// EBSTlogic
#include "EBSTlogic.h"
// EBPItype
#include "EBPItype.h"
// EBSThwconn
#include "EBSThwconn.h"
// EBSTidnt
#include "EBSTidnt.h"
// EBSTimpl
#include "EBSTimpl.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3E75E2740294.declarations preserve=no
//## end module%3E75E2740294.declarations

//## begin module%3E75E2740294.additionalDeclarations preserve=yes
//## end module%3E75E2740294.additionalDeclarations


// Class CSTPositionMachine 










CSTPositionMachine::CSTPositionMachine (CSTStepperMotorImplementation* p_pContext)
  //## begin CSTPositionMachine::CSTPositionMachine%1070350935.hasinit preserve=no
      : m_iStartPos(0), m_iEndPos(0), m_ePolarity(ePIMotorPolarityNormal), m_uiDistance(0), m_uiSearchDistance(0), m_eFastFindingDirection(ePIMotorPolarityNormal), m_bSearchLimitFromOpposite(false), m_pContext(p_pContext)
  //## end CSTPositionMachine::CSTPositionMachine%1070350935.hasinit
  //## begin CSTPositionMachine::CSTPositionMachine%1070350935.initialization preserve=yes
  //## end CSTPositionMachine::CSTPositionMachine%1070350935.initialization
{
  //## begin CSTPositionMachine::CSTPositionMachine%1070350935.body preserve=yes
  //## end CSTPositionMachine::CSTPositionMachine%1070350935.body
}


CSTPositionMachine::~CSTPositionMachine()
{
  //## begin CSTPositionMachine::~CSTPositionMachine%.body preserve=yes
  //## end CSTPositionMachine::~CSTPositionMachine%.body
}



//## Other Operations (implementation)
void CSTPositionMachine::MoveAbsolute (const INT p_iPosition)
{
  //## begin CSTPositionMachine::MoveAbsolute%1049266860.body preserve=yes

	// Old end position is new start position.
	m_iStartPos = m_iEndPos;
	m_iEndPos = p_iPosition;

	Polarity();
	Distance ();

  //## end CSTPositionMachine::MoveAbsolute%1049266860.body
}

void CSTPositionMachine::MoveRelative (const INT p_iSteps)
{
  //## begin CSTPositionMachine::MoveRelative%1049266861.body preserve=yes
	
	// Old end position is new start position.
	m_iStartPos = m_iEndPos;
	m_iEndPos = m_iStartPos + p_iSteps;

	Polarity();
	Distance ();

  //## end CSTPositionMachine::MoveRelative%1049266861.body
}

void CSTPositionMachine::TrackPosition ()
{
  //## begin CSTPositionMachine::TrackPosition%1069405834.body preserve=yes

	INT l_iActPos = 0, l_iDeltaDistance = 0;
	bool l_bHardwarePresent = m_pContext->GetpHwConnection()->GetbHardwarePresent();

	if (l_bHardwarePresent)
	{
		l_iActPos = m_pContext->GetpHwConnection()->GetRelativePos(0);
		l_iDeltaDistance = m_uiDistance - abs(l_iActPos);
	}

	if (m_uiDistance > 0)
	{
		switch (m_ePolarity)
		{
		case ePIMotorPolarityNormal:
			m_iEndPos -= l_iDeltaDistance;
			break;

		case ePIMotorPolarityReverse:
			m_iEndPos += l_iDeltaDistance;
			break;

		default:
			ASSERT(FALSE);
		}
	}

  //## end CSTPositionMachine::TrackPosition%1069405834.body
}

void CSTPositionMachine::Reset ()
{
  //## begin CSTPositionMachine::Reset%1070350934.body preserve=yes
	m_iEndPos			= 0;
	m_iStartPos			= 0;
	m_uiDistance		= 0;
	m_uiSearchDistance	= 0;
  //## end CSTPositionMachine::Reset%1070350934.body
}

void CSTPositionMachine::Distance ()
{
  //## begin CSTPositionMachine::Distance%1071668966.body preserve=yes
	m_uiDistance = abs(m_iEndPos - m_iStartPos);
  //## end CSTPositionMachine::Distance%1071668966.body
}

void CSTPositionMachine::Polarity ()
{
  //## begin CSTPositionMachine::Polarity%1071668967.body preserve=yes
	if (m_iStartPos <= m_iEndPos)
	{
		m_ePolarity = ePIMotorPolarityNormal;
	}
	else
	{
		m_ePolarity = ePIMotorPolarityReverse;
	}
  //## end CSTPositionMachine::Polarity%1071668967.body
}

//## Get and Set Operations for Class Attributes (implementation)

INT CSTPositionMachine::GetiStartPos ()
{
  //## begin CSTPositionMachine::GetiStartPos%3E8A9E4E036E.get preserve=no
  return m_iStartPos;
  //## end CSTPositionMachine::GetiStartPos%3E8A9E4E036E.get
}

void CSTPositionMachine::SetiStartPos (INT value)
{
  //## begin CSTPositionMachine::SetiStartPos%3E8A9E4E036E.set preserve=no
  m_iStartPos = value;
  //## end CSTPositionMachine::SetiStartPos%3E8A9E4E036E.set
}

INT CSTPositionMachine::GetiEndPos ()
{
  //## begin CSTPositionMachine::GetiEndPos%3E8A9E7502C3.get preserve=no
  return m_iEndPos;
  //## end CSTPositionMachine::GetiEndPos%3E8A9E7502C3.get
}

void CSTPositionMachine::SetiEndPos (INT value)
{
  //## begin CSTPositionMachine::SetiEndPos%3E8A9E7502C3.set preserve=no
  m_iEndPos = value;
  //## end CSTPositionMachine::SetiEndPos%3E8A9E7502C3.set
}

EPIMotorPolarity CSTPositionMachine::GetePolarity ()
{
  //## begin CSTPositionMachine::GetePolarity%3F54403900FA.get preserve=no
  return m_ePolarity;
  //## end CSTPositionMachine::GetePolarity%3F54403900FA.get
}

void CSTPositionMachine::SetePolarity (EPIMotorPolarity value)
{
  //## begin CSTPositionMachine::SetePolarity%3F54403900FA.set preserve=no
  m_ePolarity = value;
  //## end CSTPositionMachine::SetePolarity%3F54403900FA.set
}

UINT CSTPositionMachine::GetuiDistance ()
{
  //## begin CSTPositionMachine::GetuiDistance%3F5741B50186.get preserve=no
  return m_uiDistance;
  //## end CSTPositionMachine::GetuiDistance%3F5741B50186.get
}

void CSTPositionMachine::SetuiDistance (UINT value)
{
  //## begin CSTPositionMachine::SetuiDistance%3F5741B50186.set preserve=no
  m_uiDistance = value;
  //## end CSTPositionMachine::SetuiDistance%3F5741B50186.set
}

UINT CSTPositionMachine::GetuiSearchDistance ()
{
  //## begin CSTPositionMachine::GetuiSearchDistance%3F58762A0290.get preserve=no
  return m_uiSearchDistance;
  //## end CSTPositionMachine::GetuiSearchDistance%3F58762A0290.get
}

void CSTPositionMachine::SetuiSearchDistance (UINT value)
{
  //## begin CSTPositionMachine::SetuiSearchDistance%3F58762A0290.set preserve=no
  m_uiSearchDistance = value;
  //## end CSTPositionMachine::SetuiSearchDistance%3F58762A0290.set
}

EPIMotorPolarity CSTPositionMachine::GeteFastFindingDirection ()
{
  //## begin CSTPositionMachine::GeteFastFindingDirection%3FE0603E0244.get preserve=no
  return m_eFastFindingDirection;
  //## end CSTPositionMachine::GeteFastFindingDirection%3FE0603E0244.get
}

void CSTPositionMachine::SeteFastFindingDirection (EPIMotorPolarity value)
{
  //## begin CSTPositionMachine::SeteFastFindingDirection%3FE0603E0244.set preserve=no
  m_eFastFindingDirection = value;
  //## end CSTPositionMachine::SeteFastFindingDirection%3FE0603E0244.set
}

bool CSTPositionMachine::GetbSearchLimitFromOpposite ()
{
  //## begin CSTPositionMachine::GetbSearchLimitFromOpposite%471CEEC601E9.get preserve=no
  return m_bSearchLimitFromOpposite;
  //## end CSTPositionMachine::GetbSearchLimitFromOpposite%471CEEC601E9.get
}

void CSTPositionMachine::SetbSearchLimitFromOpposite (bool value)
{
  //## begin CSTPositionMachine::SetbSearchLimitFromOpposite%471CEEC601E9.set preserve=no
  m_bSearchLimitFromOpposite = value;
  //## end CSTPositionMachine::SetbSearchLimitFromOpposite%471CEEC601E9.set
}

// Additional Declarations
  //## begin CSTPositionMachine%3E8A978E032C.declarations preserve=yes
  //## end CSTPositionMachine%3E8A978E032C.declarations

// Class CSTLogic 































CSTLogic::CSTLogic (CSTStepperMotorImplementation* p_pContext)
  //## begin CSTLogic::CSTLogic%1062145997.hasinit preserve=no
      : m_dwSteps(0), m_bLimitHit(false), m_dwSpeedRateOld(0), m_dbVEnd(0.0), m_dbSearchDuration(0), m_dbAccDuration(0), m_dwCurIterations(0), m_dwCurIterationCnt(0), m_dbTimeBase(0), m_dbDeltaT(0.0), m_dbBaseTimeLimit(0), m_dbS1(0), m_dbS2(0), m_dbS3(0), m_dbS4(0), m_dbS5(0), m_dbVEndOrg(0), m_bNoAccelleration(false), m_bNoRunSpeed(false), m_dbRunDuration(0), m_dwIT1(0), m_dwIT3(0), m_dwIT5(0), m_dwHomingCounter(0), m_iHomingOldPosition(0), m_iHomingLatchedPosition(0), m_dbSpeedAfterAcceleration(0.0), m_pContext(p_pContext)
  //## end CSTLogic::CSTLogic%1062145997.hasinit
  //## begin CSTLogic::CSTLogic%1062145997.initialization preserve=yes
  //## end CSTLogic::CSTLogic%1062145997.initialization
{
  //## begin CSTLogic::CSTLogic%1062145997.body preserve=yes
    LARGE_INTEGER l_liFrequency;
    QueryPerformanceFrequency( &l_liFrequency );

    if (l_liFrequency.QuadPart != 0)
        m_liFrequency = l_liFrequency;
	else
        ASSERT(false);

  //## end CSTLogic::CSTLogic%1062145997.body
}


CSTLogic::~CSTLogic()
{
  //## begin CSTLogic::~CSTLogic%.body preserve=yes
  //## end CSTLogic::~CSTLogic%.body
}



//## Other Operations (implementation)
void CSTLogic::AjustActualSpeed (UINT p_uiSpeedRate)
{
  //## begin CSTLogic::AjustActualSpeed%1062398083.body preserve=yes

	m_dwSpeedRateOld = p_uiSpeedRate;
	DWORD l_dwSpeed = m_pContext->GetpProfile()->GetuiSpeed();
	DWORD l_dwVEnd = (l_dwSpeed * p_uiSpeedRate / 100);

	m_dbVEnd = MakeHardwareVelocity((double)l_dwVEnd);
	m_dbVEndOrg = m_dbVEnd;

  //## end CSTLogic::AjustActualSpeed%1062398083.body
}

void CSTLogic::ElapsedTime (const CString& p_sMsg)
{
  //## begin CSTLogic::ElapsedTime%1063892106.body preserve=yes
	
	LARGE_INTEGER l_liCounter;

	QueryPerformanceCounter( &l_liCounter );

	double l_dbActualTime = (double)l_liCounter.QuadPart / (double) m_liFrequency.QuadPart * 1000;

	double l_dbDelta = l_dbActualTime - m_dbBaseTimeLimit;

	CString l_sMsg;
	l_sMsg.Format(_T("Elapsed time %s: %f [ms]"), p_sMsg, l_dbDelta);

	CO_TRACE(ST_ID,l_sMsg);

  //## end CSTLogic::ElapsedTime%1063892106.body
}

void CSTLogic::Ramp ()
{
  //## begin CSTLogic::Ramp%1065074933.body preserve=yes

	// Config and profile stuff.
	double dt = (double)m_pContext->GetpConfig()->GetuiSamplingTime()/1000.0;
	double ve = m_dbVEndOrg;
	double vo = MakeHardwareVelocity(m_pContext->GetpProfile()->GetuiSpeedStartup());				// Startup velocity vo.
    double a = m_pContext->GetpProfile()->GetuiNomAccDec();					// Accelleration, decelleration.
	double vs = MakeHardwareVelocity(m_pContext->GetpProfile()->GetuiSpeedSearch());	// Search speed.
	double s4 = m_pContext->GetpPositionMachine()->GetuiSearchDistance();	// Search distance.
	double s = m_pContext->GetpPositionMachine()->GetuiDistance();			// Total steps to do.

	double t1 = (ve-vo)/a;					// Accellertion time.
	double s1 = ((ve*ve)-(vo*vo))/(2*a);	// Acc way.

	if (s4==0)
	{
		// without search speed iteration
		vs=ve;
	}
	double s3 = ((vs*vs)-(ve*ve))/(-2*a);
	double s5 = ((vo*vo)-(vs*vs))/(-2*a);

    double t3 = (vs-ve)/-a;
	double t4 = s4/vs;
    double t5 = (vo-vs)/-a;

	double s2 = s-s4-s1-s3;

	if (s4==0.0)
	{
		s2 -= s5;
	}

	double t2 = s2/ve;

	m_bNoAccelleration = false;
	m_bNoRunSpeed = false;

	if ( s <= (s1 + s3 + s4 + s5) )
	{
		// VEnd not reachable. Calc new VEnd.
		ve = sqrt( (a*(s-s4)) + (vo*vo) );

		if (s4==0.0)
		{
			// without search speed iteration
			vs=ve;
		}

		t1 = (ve-vo)/a;
		s1 = ( (ve*ve)-(vo*vo) )/(2*a);	// Acc way.			
		s3 = s1-s4;
		s2 = 0;
		t2 = 0;
		t3 = (vs-ve)/-a;
		t4 = s4/vs;
		t5 = (vo-vs)/-a;
		m_bNoRunSpeed = true;
	}

	if ( t1 < (4 * dt) )
	{
		// Accelleration to big. No accelleration and decelleration phase.
		ve = vo;
		s2 = s-s4;
		t2 = s2/ve;
		m_bNoAccelleration = true;
	}

	m_dwIT1 = (DWORD)(t1/dt)-1;
	m_dwIT3 = (DWORD)(t3/dt)-1;
	m_dwIT5 = (DWORD)(t5/dt)-1;
	m_dbDeltaT = 0;
	if (m_dwIT1 > 0)
		m_dbDeltaT = t1/m_dwIT1;
	
	m_dbVEnd = ve;
	m_dbAccDuration = t1;
	m_dbRunDuration = t2;
	m_dbSearchDuration = t4;
	m_dbS1 = s1;
	m_dbS2 = s2;
	m_dbS3 = s3;
	m_dbS4 = s4;
	m_dbS5 = s5;

  //## end CSTLogic::Ramp%1065074933.body
}

void CSTLogic::Accelerate (double &p_dDeltaT, double &p_dSpeed, const double &p_da, const double &p_dvo)
{
  //## begin CSTLogic::Accelerate%1065074934.body preserve=yes
	p_dDeltaT = m_dbDeltaT;
	p_dSpeed = (double)m_dwCurIterationCnt*m_dbDeltaT*p_da+p_dvo;

  //## end CSTLogic::Accelerate%1065074934.body
}

double CSTLogic::GetDeltaTime ()
{
  //## begin CSTLogic::GetDeltaTime%1065125307.body preserve=yes
	
    LARGE_INTEGER l_iTime;
	
	// Get counter value.
	QueryPerformanceCounter(&l_iTime);		

	double l_dRet;

	l_dRet = ((double)l_iTime.QuadPart) * 1E3 / (double)m_liFrequency.QuadPart;

    ASSERT( l_dRet  > m_dbTimeBase );

	return l_dRet - m_dbTimeBase;
  //## end CSTLogic::GetDeltaTime%1065125307.body
}

void CSTLogic::SetTimeBaseToNow ()
{
  //## begin CSTLogic::SetTimeBaseToNow%1065125308.body preserve=yes

    // Return value: [micro seconds]
	LARGE_INTEGER l_iTime;
	
	// Set counter start value.
	QueryPerformanceCounter(&l_iTime);				

	double l_dRet;

	l_dRet = ((double)l_iTime.QuadPart) * 1E3 / (double)m_liFrequency.QuadPart;

    ASSERT( l_dRet  > m_dbTimeBase );

	m_dbTimeBase = l_dRet;
  //## end CSTLogic::SetTimeBaseToNow%1065125308.body
}

void CSTLogic::AddMissedIterations (DWORD p_dwMissedIterations)
{
  //## begin CSTLogic::AddMissedIterations%1065164418.body preserve=yes
	m_dwCurIterationCnt += p_dwMissedIterations;
  //## end CSTLogic::AddMissedIterations%1065164418.body
}

bool CSTLogic::NextIterationStep ()
{
  //## begin CSTLogic::NextIterationStep%1065164419.body preserve=yes
	m_dwCurIterationCnt++;

	return m_dwCurIterationCnt < m_dwCurIterations;
  //## end CSTLogic::NextIterationStep%1065164419.body
}

void CSTLogic::ResetIteration (ESTIterationType p_eIterationType)
{
  //## begin CSTLogic::ResetIteration%1065164420.body preserve=yes
	m_dwCurIterationCnt = 0;

	switch(p_eIterationType)
	{
	case eIT1:
		m_dwCurIterations = m_dwIT1;
		break;
	case eIT3:
		m_dwCurIterations = m_dwIT3;
		break;
	case eIT5:
		m_dwCurIterations = m_dwIT5;
		break;
	default:
		ASSERT(FALSE);
		break;
	}
  //## end CSTLogic::ResetIteration%1065164420.body
}

double CSTLogic::GetDeltaSpeed (const double p_dbAcceleration)
{
  //## begin CSTLogic::GetDeltaSpeed%1065164421.body preserve=yes
	return (double)m_dbDeltaT*p_dbAcceleration;
  //## end CSTLogic::GetDeltaSpeed%1065164421.body
}

void CSTLogic::WatchStepsDeviation (const int p_iNomPos, const int p_iActPos)
{
  //## begin CSTLogic::WatchStepsDeviation%1065511408.body preserve=yes
	int l_dwDeviation = abs(p_iNomPos) - abs(p_iActPos);

	if ( l_dwDeviation > MAX_STEPS_DEVIATION )
	{
		// Exception.
		CString l_sTrace;
		l_sTrace.Format(_T(" Exception in file: %s line: %d. Max. step deviation bigger than %d Steps during moving.\n"),_T(__FILE__), __LINE__, MAX_STEPS_DEVIATION);
		CO_TRACE(ST_ID, l_sTrace);
		throw new XSTExceptionErrorStepsDeviation(ST_ID, IDE_ST_STEPS_DEVIATION, _T(__FILE__), __LINE__, 0);
	}
  //## end CSTLogic::WatchStepsDeviation%1065511408.body
}

double CSTLogic::MakeHardwareVelocity (const double& p_dbValue)
{
  //## begin CSTLogic::MakeHardwareVelocity%1065511413.body preserve=yes
	const double m_dbFaktor = 5425.3472; // Details see "Spezificationen FPGA 030926.doc"

	// Time value in hardware world. 
	// Converted speed ([Herz] or [Steps/s]) to "hardware velocity" (rounded).
	DWORD l_dwTime =  (DWORD)( ( (1.0/p_dbValue) * m_dbFaktor ) + 0.5 );

	// With this speed the stepper moves.
	double l_dbSpeed = m_dbFaktor/l_dwTime;

	return l_dbSpeed;
  //## end CSTLogic::MakeHardwareVelocity%1065511413.body
}

bool CSTLogic::GetTickNumber (double& p_dbTickNumber)
{
  //## begin CSTLogic::GetTickNumber%1065684040.body preserve=yes

	// Calculates time in [milli seconds];
	// Returns true if ok.

	LARGE_INTEGER l_liFrequency, l_liActTickNumber;
	const double MILLI_SECONDS = 1000.0;
	
	 // Get frequenzy of this computer.							// Get actual ticks
	BOOL l_bRet =  QueryPerformanceFrequency(&l_liFrequency) && QueryPerformanceCounter(&l_liActTickNumber);

	if (l_bRet)
	{
		p_dbTickNumber = (double)l_liActTickNumber.QuadPart * MILLI_SECONDS / (double)l_liFrequency.QuadPart;
		return true;
	}
	else
	{
		return false;
	}
  //## end CSTLogic::GetTickNumber%1065684040.body
}

bool CSTLogic::CheckHomePosition ()
{
  //## begin CSTLogic::CheckHomePosition%1066031291.body preserve=yes

	int l_iEndPos = m_pContext->GetpPositionMachine()->GetiEndPos();

	CString l_sTraceMsg;
	l_sTraceMsg.Format(_T("Home iteration: %d, Position: %d"), m_dwHomingCounter, l_iEndPos);
	CO_TRACE(ST_ID, l_sTraceMsg);
	bool l_bHomingOk = true;

	switch (m_dwHomingCounter)
	{
	case 0:
		{
			// First approach
			m_dwHomingCounter = 1;
		}
		break;

	case 1:
		{
			// Second approach. Slowly. Save position.
			m_iHomingOldPosition = l_iEndPos;
			m_dwHomingCounter = 2;
		}
		break;

	case 2:
		{
			// Third approach. Save position.
			if (m_iHomingOldPosition == l_iEndPos)
			{
				// Position 2nd time ok. Homing finish.
				m_dwHomingCounter = 4;
			}
			else
			{
				// Position not ok. Try it again.
				m_iHomingOldPosition = l_iEndPos;
				m_dwHomingCounter = 3;
			}
		}
		break;

	case 3:
		{
			if (m_iHomingOldPosition != l_iEndPos)
			{
				l_bHomingOk = false;
			}
			m_dwHomingCounter = 4;
		}
		break;

	default:
		{
			ASSERT(FALSE);
		}
	}

	return l_bHomingOk;

  //## end CSTLogic::CheckHomePosition%1066031291.body
}

//## Get and Set Operations for Class Attributes (implementation)

DWORD CSTLogic::GetdwSteps ()
{
  //## begin CSTLogic::GetdwSteps%3F5331A50148.get preserve=no
  return m_dwSteps;
  //## end CSTLogic::GetdwSteps%3F5331A50148.get
}

void CSTLogic::SetdwSteps (DWORD value)
{
  //## begin CSTLogic::SetdwSteps%3F5331A50148.set preserve=no
  m_dwSteps = value;
  //## end CSTLogic::SetdwSteps%3F5331A50148.set
}

bool CSTLogic::GetbLimitHit ()
{
  //## begin CSTLogic::GetbLimitHit%3FE05E9302A2.get preserve=no
  return m_bLimitHit;
  //## end CSTLogic::GetbLimitHit%3FE05E9302A2.get
}

void CSTLogic::SetbLimitHit (bool value)
{
  //## begin CSTLogic::SetbLimitHit%3FE05E9302A2.set preserve=no
  m_bLimitHit = value;
  //## end CSTLogic::SetbLimitHit%3FE05E9302A2.set
}

DWORD CSTLogic::GetdwSpeedRateOld ()
{
  //## begin CSTLogic::GetdwSpeedRateOld%3EA51E100203.get preserve=no
  return m_dwSpeedRateOld;
  //## end CSTLogic::GetdwSpeedRateOld%3EA51E100203.get
}

void CSTLogic::SetdwSpeedRateOld (DWORD value)
{
  //## begin CSTLogic::SetdwSpeedRateOld%3EA51E100203.set preserve=no
  m_dwSpeedRateOld = value;
  //## end CSTLogic::SetdwSpeedRateOld%3EA51E100203.set
}

double CSTLogic::GetdbVEnd ()
{
  //## begin CSTLogic::GetdbVEnd%3E9560BA0213.get preserve=no
  return m_dbVEnd;
  //## end CSTLogic::GetdbVEnd%3E9560BA0213.get
}

void CSTLogic::SetdbVEnd (double value)
{
  //## begin CSTLogic::SetdbVEnd%3E9560BA0213.set preserve=no
  m_dbVEnd = value;
  //## end CSTLogic::SetdbVEnd%3E9560BA0213.set
}

double CSTLogic::GetdbSearchDuration ()
{
  //## begin CSTLogic::GetdbSearchDuration%3F582EFC029F.get preserve=no
  return m_dbSearchDuration;
  //## end CSTLogic::GetdbSearchDuration%3F582EFC029F.get
}

double CSTLogic::GetdbAccDuration ()
{
  //## begin CSTLogic::GetdbAccDuration%3F7A83F702C4.get preserve=no
  return m_dbAccDuration;
  //## end CSTLogic::GetdbAccDuration%3F7A83F702C4.get
}

void CSTLogic::SetdbAccDuration (double value)
{
  //## begin CSTLogic::SetdbAccDuration%3F7A83F702C4.set preserve=no
  m_dbAccDuration = value;
  //## end CSTLogic::SetdbAccDuration%3F7A83F702C4.set
}

DWORD CSTLogic::GetdwCurIterations ()
{
  //## begin CSTLogic::GetdwCurIterations%3F7BE61A0266.get preserve=no
  return m_dwCurIterations;
  //## end CSTLogic::GetdwCurIterations%3F7BE61A0266.get
}

DWORD CSTLogic::GetdwCurIterationCnt ()
{
  //## begin CSTLogic::GetdwCurIterationCnt%3F7C880E011C.get preserve=no
  return m_dwCurIterationCnt;
  //## end CSTLogic::GetdwCurIterationCnt%3F7C880E011C.get
}

double CSTLogic::GetdbTimeBase ()
{
  //## begin CSTLogic::GetdbTimeBase%3F7C8541005D.get preserve=no
  return m_dbTimeBase;
  //## end CSTLogic::GetdbTimeBase%3F7C8541005D.get
}

double CSTLogic::GetdbDeltaT ()
{
  //## begin CSTLogic::GetdbDeltaT%3F7C87A903DE.get preserve=no
  return m_dbDeltaT;
  //## end CSTLogic::GetdbDeltaT%3F7C87A903DE.get
}

double CSTLogic::GetdbBaseTimeLimit ()
{
  //## begin CSTLogic::GetdbBaseTimeLimit%3FBE0DEC0160.get preserve=no
  return m_dbBaseTimeLimit;
  //## end CSTLogic::GetdbBaseTimeLimit%3FBE0DEC0160.get
}

void CSTLogic::SetdbBaseTimeLimit (double value)
{
  //## begin CSTLogic::SetdbBaseTimeLimit%3FBE0DEC0160.set preserve=no
  m_dbBaseTimeLimit = value;
  //## end CSTLogic::SetdbBaseTimeLimit%3FBE0DEC0160.set
}

double CSTLogic::GetdbS1 ()
{
  //## begin CSTLogic::GetdbS1%3F8160440166.get preserve=no
  return m_dbS1;
  //## end CSTLogic::GetdbS1%3F8160440166.get
}

double CSTLogic::GetdbS2 ()
{
  //## begin CSTLogic::GetdbS2%3F81607D0157.get preserve=no
  return m_dbS2;
  //## end CSTLogic::GetdbS2%3F81607D0157.get
}

double CSTLogic::GetdbS3 ()
{
  //## begin CSTLogic::GetdbS3%3F81607F02CE.get preserve=no
  return m_dbS3;
  //## end CSTLogic::GetdbS3%3F81607F02CE.get
}

double CSTLogic::GetdbS4 ()
{
  //## begin CSTLogic::GetdbS4%3F8160810166.get preserve=no
  return m_dbS4;
  //## end CSTLogic::GetdbS4%3F8160810166.get
}

double CSTLogic::GetdbS5 ()
{
  //## begin CSTLogic::GetdbS5%3F81608401D4.get preserve=no
  return m_dbS5;
  //## end CSTLogic::GetdbS5%3F81608401D4.get
}

double CSTLogic::GetdbVEndOrg ()
{
  //## begin CSTLogic::GetdbVEndOrg%3F8161F800DA.get preserve=no
  return m_dbVEndOrg;
  //## end CSTLogic::GetdbVEndOrg%3F8161F800DA.get
}

bool CSTLogic::GetbNoAccelleration ()
{
  //## begin CSTLogic::GetbNoAccelleration%3F81622B034B.get preserve=no
  return m_bNoAccelleration;
  //## end CSTLogic::GetbNoAccelleration%3F81622B034B.get
}

bool CSTLogic::GetbNoRunSpeed ()
{
  //## begin CSTLogic::GetbNoRunSpeed%3F81626102CE.get preserve=no
  return m_bNoRunSpeed;
  //## end CSTLogic::GetbNoRunSpeed%3F81626102CE.get
}

double CSTLogic::GetdbRunDuration ()
{
  //## begin CSTLogic::GetdbRunDuration%3F8162BA03D7.get preserve=no
  return m_dbRunDuration;
  //## end CSTLogic::GetdbRunDuration%3F8162BA03D7.get
}

DWORD CSTLogic::GetdwIT1 ()
{
  //## begin CSTLogic::GetdwIT1%3F81733D01F3.get preserve=no
  return m_dwIT1;
  //## end CSTLogic::GetdwIT1%3F81733D01F3.get
}

DWORD CSTLogic::GetdwIT3 ()
{
  //## begin CSTLogic::GetdwIT3%3F8173950109.get preserve=no
  return m_dwIT3;
  //## end CSTLogic::GetdwIT3%3F8173950109.get
}

DWORD CSTLogic::GetdwIT5 ()
{
  //## begin CSTLogic::GetdwIT5%3F8173960270.get preserve=no
  return m_dwIT5;
  //## end CSTLogic::GetdwIT5%3F8173960270.get
}

DWORD CSTLogic::GetdwHomingCounter ()
{
  //## begin CSTLogic::GetdwHomingCounter%3F8A6BF002AB.get preserve=no
  return m_dwHomingCounter;
  //## end CSTLogic::GetdwHomingCounter%3F8A6BF002AB.get
}

void CSTLogic::SetdwHomingCounter (DWORD value)
{
  //## begin CSTLogic::SetdwHomingCounter%3F8A6BF002AB.set preserve=no
  m_dwHomingCounter = value;
  //## end CSTLogic::SetdwHomingCounter%3F8A6BF002AB.set
}

void CSTLogic::SetiHomingOldPosition (int value)
{
  //## begin CSTLogic::SetiHomingOldPosition%3F8A6C430079.set preserve=no
  m_iHomingOldPosition = value;
  //## end CSTLogic::SetiHomingOldPosition%3F8A6C430079.set
}

INT CSTLogic::GetiHomingLatchedPosition ()
{
  //## begin CSTLogic::GetiHomingLatchedPosition%43424A840131.get preserve=no
  return m_iHomingLatchedPosition;
  //## end CSTLogic::GetiHomingLatchedPosition%43424A840131.get
}

void CSTLogic::SetiHomingLatchedPosition (INT value)
{
  //## begin CSTLogic::SetiHomingLatchedPosition%43424A840131.set preserve=no
  m_iHomingLatchedPosition = value;
  //## end CSTLogic::SetiHomingLatchedPosition%43424A840131.set
}

double CSTLogic::GetdbSpeedAfterAcceleration ()
{
  //## begin CSTLogic::GetdbSpeedAfterAcceleration%4A1242C30192.get preserve=no
  return m_dbSpeedAfterAcceleration;
  //## end CSTLogic::GetdbSpeedAfterAcceleration%4A1242C30192.get
}

void CSTLogic::SetdbSpeedAfterAcceleration (double value)
{
  //## begin CSTLogic::SetdbSpeedAfterAcceleration%4A1242C30192.set preserve=no
  m_dbSpeedAfterAcceleration = value;
  //## end CSTLogic::SetdbSpeedAfterAcceleration%4A1242C30192.set
}

// Additional Declarations
  //## begin CSTLogic%3F4F6A1B03A9.declarations preserve=yes
  //## end CSTLogic%3F4F6A1B03A9.declarations

//## begin module%3E75E2740294.epilog preserve=yes
//## end module%3E75E2740294.epilog
