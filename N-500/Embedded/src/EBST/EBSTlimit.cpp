//## begin module%3E797F3D0267.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E797F3D0267.cm

//## begin module%3E797F3D0267.cp preserve=no
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
//## end module%3E797F3D0267.cp

//## Module: EBSTlimit%3E797F3D0267; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTlimit.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E797F3D0267.additionalIncludes preserve=no
//## end module%3E797F3D0267.additionalIncludes

//## begin module%3E797F3D0267.includes preserve=yes
//## end module%3E797F3D0267.includes

// EBCOsync
#include "EBCOsync.h"
// EBPItype
#include "EBPItype.h"
// EBSTidnt
#include "EBSTidnt.h"
// EBSTimpl
#include "EBSTimpl.h"
// EBSTintf
#include "EBSTintf.h"
// EBSThwconn
#include "EBSThwconn.h"
// EBSTexcp
#include "EBSTexcp.h"
// EBSTlmwk
#include "EBSTlmwk.h"
// EBSTlimit
#include "EBSTlimit.h"
// EBSTlogic
#include "EBSTlogic.h"
// EBHIintf
#include "EBHIintf.h"
// EBHIenum
#include "EBHIenum.h"


//## begin module%3E797F3D0267.declarations preserve=no
//## end module%3E797F3D0267.declarations

//## begin module%3E797F3D0267.additionalDeclarations preserve=yes
//## end module%3E797F3D0267.additionalDeclarations


// Class CSTLimitHandler 









CSTLimitHandler::CSTLimitHandler (CSTStepperMotorImplementation* p_pContext)
  //## begin CSTLimitHandler::CSTLimitHandler%1048149994.hasinit preserve=no
      : m_pContext(p_pContext), m_pLimitWorkerThread(NULL), m_pLimitSwitchIDHit(NULL), m_pHomeLimitID(NULL)
  //## end CSTLimitHandler::CSTLimitHandler%1048149994.hasinit
  //## begin CSTLimitHandler::CSTLimitHandler%1048149994.initialization preserve=yes
  //## end CSTLimitHandler::CSTLimitHandler%1048149994.initialization
{
  //## begin CSTLimitHandler::CSTLimitHandler%1048149994.body preserve=yes

	// Creates a new thread.
	m_pLimitWorkerThread = new CSTLimitWorkerThread(this);

	// Starts the thread.
	CCOSyncObjectPtr l_SyncObj = m_pLimitWorkerThread->Start();
	l_SyncObj->Synchronize();

  //## end CSTLimitHandler::CSTLimitHandler%1048149994.body
}


CSTLimitHandler::~CSTLimitHandler()
{
  //## begin CSTLimitHandler::~CSTLimitHandler%.body preserve=yes

	// Stops and terminates worker thread.
	if (m_pLimitWorkerThread != NULL)
	{
		// Object is deleted automatically after terminating the thread
		CCOSyncObjectPtr l_pSyncObj = m_pLimitWorkerThread->Deactivate();
		l_pSyncObj->Synchronize();
		m_pLimitWorkerThread->TerminateThread();
		m_pLimitWorkerThread = NULL;
	}


	// Deletes all limit switches
	Reset();	

	if (m_pLimitSwitchIDHit != NULL)
	{
		m_pLimitSwitchIDHit->ReleaseRef();
	}
	m_pLimitSwitchIDHit = NULL;


	if (m_pHomeLimitID != NULL)
	{
		m_pHomeLimitID->ReleaseRef();
	}
	m_pHomeLimitID = NULL;


  //## end CSTLimitHandler::~CSTLimitHandler%.body
}



//## Other Operations (implementation)
void CSTLimitHandler::Add (CPIObjIdentification* p_pSensorID, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction)
{
  //## begin CSTLimitHandler::Add%1048149995.body preserve=yes

	CString l_sTrace, l_sAction, l_sCharacter;
	UINT l_uiID = p_pSensorID->GetuiID();

	switch(p_eLimitAction)
	{
		case ePILimitActionDisabled:
			l_sAction = _T("ePILimitActionDisabled");
			break;

		case ePILimitActionStop:
			l_sAction = _T("ePILimitActionStop");
			break;

		case ePILimitActionDecelerate:
			l_sAction = _T("ePILimitActionDecelerate");
			break;

		case ePILimitActionFootprint:
			l_sAction = _T("ePILimitActionFootprint");
			break;

		default:
			ASSERT(false);
	}

	switch(p_eLimitCharacteristics)
	{
		case ePILimitHardEdgeRaising:
			l_sCharacter = _T("ePILimitHardEdgeRaising");
			break;

		case ePILimitHardEdgeFalling:
			l_sCharacter = _T("ePILimitHardEdgeFalling");
			break;

		case ePILimitSoftEdgeRaising:
			l_sCharacter = _T("ePILimitSoftEdgeRaising");
			break;

		case ePILimitSoftEdgeFalling:
			l_sCharacter = _T("ePILimitSoftEdgeFalling");
			break;

		default:
			ASSERT(false);
	}

	l_sTrace.Format(_T("LimitAdd(%d, %s, %s)"), l_uiID, l_sCharacter, l_sAction);
	CO_TRACE(ST_ID, l_sTrace);

	// Change configuration of this limit switch.
	CSTLimitSwitch *l_pLimitSwitch = NULL;
	UINT l_uiLimitID = p_pSensorID->GetuiID();
	BOOL l_bFound = m_Limits.Lookup(l_uiLimitID, l_pLimitSwitch);

	if (l_bFound)
	{
		// Limit switch exists. Change configuration.
		l_pLimitSwitch->SeteLimitAction(p_eLimitAction);
		l_pLimitSwitch->SeteOriginalLimitCharacteristics(p_eLimitCharacteristics);
	}
	else
	{
		// Add switch, if it doesn't exist.
		l_pLimitSwitch = new CSTLimitSwitch(p_pSensorID, p_eLimitAction, p_eLimitCharacteristics);
		m_Limits.SetAt(l_uiLimitID, l_pLimitSwitch);
	}

  //## end CSTLimitHandler::Add%1048149995.body
}

void CSTLimitHandler::Config (CPIObjIdentification* p_pSensor, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction)
{
  //## begin CSTLimitHandler::Config%1048149996.body preserve=yes

	CString l_sTrace, l_sAction, l_sCharacter;
	UINT l_uiID = p_pSensor->GetuiID();

	switch(p_eLimitAction)
	{
		case ePILimitActionDisabled:
			l_sAction = _T("ePILimitActionDisabled");
			break;

		case ePILimitActionStop:
			l_sAction = _T("ePILimitActionStop");
			break;

		case ePILimitActionDecelerate:
			l_sAction = _T("ePILimitActionDecelerate");
			break;

		case ePILimitActionFootprint:
			l_sAction = _T("ePILimitActionFootprint");
			break;

		default:
			ASSERT(false);
	}

	switch(p_eLimitCharacteristics)
	{
		case ePILimitHardEdgeRaising:
			l_sCharacter = _T("ePILimitHardEdgeRaising");
			break;

		case ePILimitHardEdgeFalling:
			l_sCharacter = _T("ePILimitHardEdgeFalling");
			break;

		case ePILimitSoftEdgeRaising:
			l_sCharacter = _T("ePILimitSoftEdgeRaising");
			break;

		case ePILimitSoftEdgeFalling:
			l_sCharacter = _T("ePILimitSoftEdgeFalling");
			break;

		default:
			ASSERT(false);
	}

	l_sTrace.Format(_T("LimitConfig(%d, %s, %s)"), l_uiID, l_sCharacter, l_sAction);
	CO_TRACE(ST_ID, l_sTrace);

	CSTLimitSwitch *l_pLimitSwitch = NULL;
	UINT l_uiLimitID = p_pSensor->GetuiID();
	BOOL l_bFound = m_Limits.Lookup(l_uiLimitID, l_pLimitSwitch);

	if (l_bFound)	
	{	
		// Limit switch exists. Change configuration.
		l_pLimitSwitch->SeteLimitAction(p_eLimitAction);
		l_pLimitSwitch->SeteOriginalLimitCharacteristics(p_eLimitCharacteristics);
	}
	else
	{
		// Exception:
		CString l_sTrace;
		l_sTrace.Format(_T("Exception in file: %s line: %d. Limit switch not found.\n"),_T(__FILE__), __LINE__);
		CO_TRACE(ST_ID, l_sTrace);
		throw new XSTExceptionLimit(ST_ID, IDE_ST_LIMITSWITCH_NOT_FOUND, _T(__FILE__), __LINE__, 0);
	}

  //## end CSTLimitHandler::Config%1048149996.body
}

void CSTLimitHandler::Activate ()
{
  //## begin CSTLimitHandler::Activate%1048149997.body preserve=yes
	if (!GetbLimitsEnabled())
	{
		SetbLimitsEnabled(true);
	}
  //## end CSTLimitHandler::Activate%1048149997.body
}

void CSTLimitHandler::Deactivate ()
{
  //## begin CSTLimitHandler::Deactivate%1048149998.body preserve=yes
	if (GetbLimitsEnabled())
	{
		SetbLimitsEnabled(false);
	}
  //## end CSTLimitHandler::Deactivate%1048149998.body
}

CArray<INT, INT>* CSTLimitHandler::GetFootprint ()
{
  //## begin CSTLimitHandler::GetFootprint%1048149999.body preserve=yes

	for (POSITION l_Pos = m_Limits.GetStartPosition(); l_Pos != NULL;)
	{
		UINT l_uiKey = 0;
		CSTLimitSwitch* l_pLimit = NULL;
		m_Limits.GetNextAssoc(l_Pos, l_uiKey, l_pLimit);
		if (l_pLimit->GeteLimitAction() == ePILimitActionFootprint)
		{
			return l_pLimit->GetFootprints();
		}
	}

	// Exception:
	CString l_sTrace;
	l_sTrace.Format(_T("Exception in file: %s line: %d. Get footprints executed, but no footprint limitswitch configured.\n"),_T(__FILE__), __LINE__);
	CO_TRACE(ST_ID, l_sTrace);
	throw new XSTExceptionLimit(ST_ID, IDE_ST_FOOTPRINT_LIMIT_NOT_FOUND, _T(__FILE__), __LINE__, 0);

  //## end CSTLimitHandler::GetFootprint%1048149999.body
}

void CSTLimitHandler::SetFootprint (const int p_iPosition)
{
  //## begin CSTLimitHandler::SetFootprint%1048150000.body preserve=yes
	
	bool l_bFootPrintFound= false;

	for (POSITION l_Pos = m_Limits.GetStartPosition(); l_Pos != NULL;)
	{
		UINT l_uiKey = 0;
		CSTLimitSwitch* l_pLimit = NULL;
		m_Limits.GetNextAssoc(l_Pos, l_uiKey, l_pLimit);
		// Footprint limit switch?
		if (l_pLimit->GeteLimitAction() == ePILimitActionFootprint)
		{
			ASSERT(!l_bFootPrintFound); // More than one footprint limitswitch.
			l_pLimit->AddFootprint(p_iPosition);
			l_bFootPrintFound= true;
		}
	}


	// Footprint limit switch not found.
	ASSERT(l_bFootPrintFound);

  //## end CSTLimitHandler::SetFootprint%1048150000.body
}

void CSTLimitHandler::OnHit (UINT p_uiLimitID)
{
  //## begin CSTLimitHandler::OnHit%1048150001.body preserve=yes
	
	double l_dbTime = 0, l_dbDeltaTime = 0;
	GetpContext()->GetpLogic()->GetTickNumber(l_dbTime);
	l_dbDeltaTime = l_dbTime - GetpContext()->GetpLogic()->GetdbBaseTimeLimit(); 
	CO_TRACE1(ST_ID, _T("CSTLimitHandler::OnHit() elapsed time: %f [ms]"), l_dbDeltaTime);

	// Get pointer to the stepper motor interface.
	CSTStepperMotorInterface* l_pIntf = dynamic_cast<CSTStepperMotorInterface*>(m_pContext->GetpInterface());
	ASSERT(l_pIntf != NULL);

	// Only when the limits are enabled do something.
	if (m_bLimitsEnabled)
	{   
		// This limit switch has been hit.
		CSTLimitSwitch* l_pLimit = NULL;
		BOOL l_bRes = m_Limits.Lookup(p_uiLimitID, l_pLimit);
		ASSERT(l_bRes);

		// Make homesensor jitter free.
		double l_dbActTime = 0.0;
		GetpContext()->GetpLogic()->GetTickNumber(l_dbActTime);

		double l_dbTimeStamp = l_pLimit->GetdbTimeStamp();
		bool l_bSkip = false;
		INT l_iDeltaTimeStamp = 0;

		if (l_dbTimeStamp != 0.0)
		{
			l_iDeltaTimeStamp = (INT) (l_dbActTime - l_dbTimeStamp);
			CO_TRACE1(ST_ID, _T("Jitter time: %d"),l_iDeltaTimeStamp);

			// Calc. delta time stamp.
			if (MIN_JITTER_TIME > l_iDeltaTimeStamp)
			{
				l_bSkip = true;
			}
		}

		// Set new time stamp.
		l_pLimit->SetdbTimeStamp(l_dbActTime);

		if (!l_bSkip)
		{
			EPILimitAction l_eLimitAction = l_pLimit->GeteLimitAction();

			switch(l_eLimitAction)
			{

			case ePILimitActionDisabled:
				{
				// Action is disabled. Do nothing.
				}
				break;
			   
			case ePILimitActionStop:
			case ePILimitActionDecelerate:
				{
					// Execute command on the stepper motor interface.
					CCOSyncObjectPtr l_SyncObj = l_pIntf->OnLimitHit(l_pLimit->GetpLimitID());
					// no synchronization requited
				}
				break;

			case ePILimitActionFootprint:
				{
				// Get actual motor position from hardware.
				int l_iActualPosition= GetpContext()->GetpHwConnection()->GetRelativePos(0);
				SetFootprint(l_iActualPosition);
				}
				break;

			default:
				// Value of l_eLimitAction undefined.
				ASSERT(false);
				break;
			}
		}
	}

  //## end CSTLimitHandler::OnHit%1048150001.body
}

void CSTLimitHandler::Reset ()
{
  //## begin CSTLimitHandler::Reset%1053438554.body preserve=yes

	for (POSITION l_Pos = m_Limits.GetStartPosition(); l_Pos != NULL;)
	{
		UINT l_uiKey = 0;
		CSTLimitSwitch* l_pLimit = NULL;
		m_Limits.GetNextAssoc(l_Pos, l_uiKey, l_pLimit);
		delete l_pLimit;
	}

	m_Limits.RemoveAll();

  //## end CSTLimitHandler::Reset%1053438554.body
}

void CSTLimitHandler::Start ()
{
  //## begin CSTLimitHandler::Start%1048150002.body preserve=yes
	
	// Activates the limit watch
	ResetEvents ();
	CCOSyncObjectPtr l_pSyncObj = m_pLimitWorkerThread->Activate();
	l_pSyncObj->Synchronize();

    // resets the jitter time after each moving
    ResetJitterTime();

  //## end CSTLimitHandler::Start%1048150002.body
}

void CSTLimitHandler::Stop ()
{
  //## begin CSTLimitHandler::Stop%1048150003.body preserve=yes
	
	if (m_pLimitWorkerThread != NULL)
	{
		// Object is deleted automatically after terminating the thread
		CCOSyncObjectPtr l_pSyncObj = m_pLimitWorkerThread->Deactivate();
		l_pSyncObj->Synchronize();
	}
  //## end CSTLimitHandler::Stop%1048150003.body
}

CCOSyncObjectArray* CSTLimitHandler::GetLimitSwitchEvents (CArray<UINT, UINT>& p_LimitIDs)
{
  //## begin CSTLimitHandler::GetLimitSwitchEvents%1048237054.body preserve=yes
	CCOSyncObjectArray* l_pSyncArray = new CCOSyncObjectArray();
	p_LimitIDs.SetSize(m_Limits.GetCount());

	// Scan the limit switch array and get the switch actions
	UINT l_uiCnt=0;
	for (POSITION l_Pos = m_Limits.GetStartPosition(); l_Pos!=NULL;)
	{
		UINT l_uiKey;
		CSTLimitSwitch* l_pLimit = NULL;
		m_Limits.GetNextAssoc(l_Pos, l_uiKey, l_pLimit);
		CCOSyncObject* l_pLimitEvent = l_pLimit->GetEvent();
		if (l_pLimitEvent != NULL)
		{
			l_pSyncArray->Add(l_pLimitEvent);
			p_LimitIDs.SetAt(l_uiCnt++, l_pLimit->GetpLimitID()->GetuiID());
		}
	}

	return l_pSyncArray;
  //## end CSTLimitHandler::GetLimitSwitchEvents%1048237054.body
}

CSTLimitSwitch* CSTLimitHandler::FindLimitSwitch (CPIObjIdentification* p_pLimitID)
{
  //## begin CSTLimitHandler::FindLimitSwitch%1048836484.body preserve=yes
	CSTLimitSwitch* l_pLimit = NULL;
	UINT l_uiLimitID = p_pLimitID->GetuiID();
	if (m_Limits.Lookup(l_uiLimitID, l_pLimit))
		return l_pLimit;

	// Exception:
	CString l_sTrace;
	l_sTrace.Format(_T("Exception in file: %s line: %d. Limit switch not found.\n"),_T(__FILE__), __LINE__);
	CO_TRACE(ST_ID, l_sTrace);
	throw new XSTExceptionLimit(ST_ID, IDE_ST_LIMITSWITCH_NOT_FOUND, _T(__FILE__), __LINE__, 0);
  //## end CSTLimitHandler::FindLimitSwitch%1048836484.body
}

bool CSTLimitHandler::SoftLimitPresent ()
{
  //## begin CSTLimitHandler::SoftLimitPresent%1049092070.body preserve=yes

	for (POSITION l_Pos = m_Limits.GetStartPosition(); l_Pos != NULL;)
	{
		UINT l_uiKey = 0;
		CSTLimitSwitch* l_pLimit = NULL;
		m_Limits.GetNextAssoc(l_Pos, l_uiKey, l_pLimit);
		if ((l_pLimit->GeteCurLimitCharacteristics() == ePILimitSoftEdgeFalling) ||
			(l_pLimit->GeteCurLimitCharacteristics() == ePILimitSoftEdgeRaising))
		{
			return true;
		}
	}

	return false;
  //## end CSTLimitHandler::SoftLimitPresent%1049092070.body
}

void CSTLimitHandler::ResetFootprint ()
{
  //## begin CSTLimitHandler::ResetFootprint%1060170828.body preserve=yes
	bool l_bFootPrintFound= false;

	for (POSITION l_Pos = m_Limits.GetStartPosition(); l_Pos != NULL;)
	{
		UINT l_uiKey = 0;
		CSTLimitSwitch* l_pLimit = NULL;
		m_Limits.GetNextAssoc(l_Pos, l_uiKey, l_pLimit);

		// Footprint limit switch?
		if (l_pLimit->GeteLimitAction() == ePILimitActionFootprint)
		{
			if( l_bFootPrintFound )
			{
				// Exception:
				CString l_sTrace;
				l_sTrace.Format(_T("Exception in file: %s line: %d. Limit switch not found.\n"),_T(__FILE__), __LINE__);
				CO_TRACE(ST_ID, l_sTrace);
				throw new XSTExceptionLimit(ST_ID, IDE_ST_MULTI_FOOTPRINT_LIMITS, _T(__FILE__), __LINE__, 0);
			}

			l_pLimit->ResetFootprints();
			l_bFootPrintFound = true;
		}
	}

  //## end CSTLimitHandler::ResetFootprint%1060170828.body
}

void CSTLimitHandler::ResetEvents ()
{
  //## begin CSTLimitHandler::ResetEvents%1069232321.body preserve=yes

	for (POSITION l_Pos = m_Limits.GetStartPosition(); l_Pos != NULL;)
	{
		UINT l_uiKey = 0;
		CSTLimitSwitch* l_pLimit = NULL;
		m_Limits.GetNextAssoc(l_Pos, l_uiKey, l_pLimit);
		l_pLimit->ResetEvent();
	}

  //## end CSTLimitHandler::ResetEvents%1069232321.body
}

bool CSTLimitHandler::IsAtHome ()
{
  //## begin CSTLimitHandler::IsAtHome%1066031268.body preserve=yes
	bool l_bIsActive = false, l_bIsAtHome = false;

	CSTLimitSwitch *l_pLimit = m_pContext->GetpLimitHandler()->FindLimitSwitch(m_pHomeLimitID);

	if (l_pLimit != NULL)
	{
		DWORD l_dwId = m_pHomeLimitID->GetuiID();
		l_bIsActive = GetpContext()->GetpHwConnection()->IsActive(l_dwId);
		
		EPILimitCharacteristics l_eCharacteristics = l_pLimit->GeteCurLimitCharacteristics();

		switch (l_eCharacteristics)
		{
		case ePILimitHardEdgeFalling:
			{
				l_bIsAtHome = !l_bIsActive;
			}
			break;

		case ePILimitHardEdgeRaising:
			{
				l_bIsAtHome = l_bIsActive;
			}
			break;

		case ePILimitSoftEdgeFalling:
		case ePILimitSoftEdgeRaising:
		default:
			{
				// Exception:
				CString l_sTrace;
				l_sTrace.Format(_T("Exception in file: %s line: %d. Home limit config not proper.\n"),_T(__FILE__), __LINE__);
				CO_TRACE(ST_ID, l_sTrace);
				throw new XSTExceptionHomingLimitConfig(ST_ID, IDE_ST_HOMING_LIMIT_CONFIG, _T(__FILE__), __LINE__, 0);
			}
		}
	}
	else
	{
		// Exception:
		CString l_sTrace;
		l_sTrace.Format(_T("Exception in file: %s line: %d. Home limit config not proper.\n"),_T(__FILE__), __LINE__);
		CO_TRACE(ST_ID, l_sTrace);
		throw new XSTExceptionHomingLimitConfig(ST_ID, IDE_ST_HOMING_LIMIT_CONFIG, _T(__FILE__), __LINE__, 0);
	}

	return l_bIsAtHome;

  //## end CSTLimitHandler::IsAtHome%1066031268.body
}

void CSTLimitHandler::ResetJitterTime ()
{
  //## begin CSTLimitHandler::ResetJitterTime%1091177734.body preserve=yes

    // after each moving jitter time will be reseted

	for (POSITION l_Pos = m_Limits.GetStartPosition(); l_Pos != NULL;)
	{
		UINT l_uiKey = 0;
		CSTLimitSwitch* l_pLimit = NULL;
		m_Limits.GetNextAssoc(l_Pos, l_uiKey, l_pLimit);
		l_pLimit->SetdbTimeStamp( 0.0 );
	}

  //## end CSTLimitHandler::ResetJitterTime%1091177734.body
}

//## Get and Set Operations for Associations (implementation)

CSTStepperMotorImplementation * CSTLimitHandler::GetpContext ()
{
  //## begin CSTLimitHandler::GetpContext%3E797B660016.get preserve=no
  return m_pContext;
  //## end CSTLimitHandler::GetpContext%3E797B660016.get
}

CPIObjIdentification * CSTLimitHandler::GetpLimitSwitchIDHit ()
{
  //## begin CSTLimitHandler::GetpLimitSwitchIDHit%3EA92B5E0201.get preserve=yes
	ASSERT(m_pLimitSwitchIDHit != NULL);
	return m_pLimitSwitchIDHit;
  //## end CSTLimitHandler::GetpLimitSwitchIDHit%3EA92B5E0201.get
}

void CSTLimitHandler::SetpLimitSwitchIDHit (CPIObjIdentification * value)
{
  //## begin CSTLimitHandler::SetpLimitSwitchIDHit%3EA92B5E0201.set preserve=yes
	if (m_pLimitSwitchIDHit)
		m_pLimitSwitchIDHit->ReleaseRef();

	m_pLimitSwitchIDHit = value;
	if (m_pLimitSwitchIDHit)
		m_pLimitSwitchIDHit->AddRef();
  //## end CSTLimitHandler::SetpLimitSwitchIDHit%3EA92B5E0201.set
}

bool CSTLimitHandler::GetbLimitsEnabled ()
{
  //## begin CSTLimitHandler::GetbLimitsEnabled%3EACC6A803B2.get preserve=no
  return m_bLimitsEnabled;
  //## end CSTLimitHandler::GetbLimitsEnabled%3EACC6A803B2.get
}

void CSTLimitHandler::SetbLimitsEnabled (bool value)
{
  //## begin CSTLimitHandler::SetbLimitsEnabled%3EACC6A803B2.set preserve=no
  m_bLimitsEnabled = value;
  //## end CSTLimitHandler::SetbLimitsEnabled%3EACC6A803B2.set
}

CPIObjIdentification * CSTLimitHandler::GetpHomeLimitID ()
{
  //## begin CSTLimitHandler::GetpHomeLimitID%3FBCE53B0277.get preserve=yes
  ASSERT(m_pHomeLimitID != NULL);
  return m_pHomeLimitID;
  //## end CSTLimitHandler::GetpHomeLimitID%3FBCE53B0277.get
}

void CSTLimitHandler::SetpHomeLimitID (CPIObjIdentification * value)
{
  //## begin CSTLimitHandler::SetpHomeLimitID%3FBCE53B0277.set preserve=yes
	ASSERT(value != NULL);

	if(m_pHomeLimitID != NULL)
		m_pHomeLimitID->ReleaseRef();

	m_pHomeLimitID = value;
	m_pHomeLimitID->AddRef();
  //## end CSTLimitHandler::SetpHomeLimitID%3FBCE53B0277.set
}

// Additional Declarations
  //## begin CSTLimitHandler%3E7974260025.declarations preserve=yes
  //## end CSTLimitHandler%3E7974260025.declarations

// Class CSTLimitSwitch 









CSTLimitSwitch::CSTLimitSwitch (CPIObjIdentification* p_pLimitID, const EPILimitAction p_eLimitAction, const EPILimitCharacteristics p_eLimitCharacteristics)
  //## begin CSTLimitSwitch::CSTLimitSwitch%1048237049.hasinit preserve=no
      : m_eLimitAction(p_eLimitAction), m_eCurLimitCharacteristics(p_eLimitCharacteristics), m_pLimitID(p_pLimitID), m_pOpenEvent(NULL), m_dbTimeStamp(0.0), m_eOriginalLimitCharacteristics(p_eLimitCharacteristics)
  //## end CSTLimitSwitch::CSTLimitSwitch%1048237049.hasinit
  //## begin CSTLimitSwitch::CSTLimitSwitch%1048237049.initialization preserve=yes
  //## end CSTLimitSwitch::CSTLimitSwitch%1048237049.initialization
{
  //## begin CSTLimitSwitch::CSTLimitSwitch%1048237049.body preserve=yes
	m_pLimitID->AddRef();
	
	// Get event form HI.
	// Declare variables:
	EHIOpenEventRegistration l_eOpenEventRegistration = eHILow;

	switch (m_eCurLimitCharacteristics)
	{
		case ePILimitHardEdgeFalling:
		case ePILimitSoftEdgeFalling:
			l_eOpenEventRegistration = eHILow;
			break;

		case ePILimitHardEdgeRaising:
		case ePILimitSoftEdgeRaising:
			l_eOpenEventRegistration = eHIHigh;
			break;

		default:
			ASSERT(false);
	}

	m_pOpenEvent = CHIInterface::GetInstance()->OpenEvent(m_pLimitID->GetuiID(), l_eOpenEventRegistration);
	ASSERT(m_pOpenEvent != NULL);

  //## end CSTLimitSwitch::CSTLimitSwitch%1048237049.body
}


CSTLimitSwitch::~CSTLimitSwitch()
{
  //## begin CSTLimitSwitch::~CSTLimitSwitch%.body preserve=yes

	if (m_pOpenEvent != NULL)
	{
		// Get switch identification.
		CHIInterface::GetInstance()->CloseEvent(m_pLimitID->GetuiID(), m_pOpenEvent);
		m_pOpenEvent->ReleaseRef();
	}
	m_pOpenEvent = NULL;

	if (m_pLimitID != NULL)
		m_pLimitID->ReleaseRef();
	m_pLimitID = NULL;

  //## end CSTLimitSwitch::~CSTLimitSwitch%.body
}



//## Other Operations (implementation)
CCOSyncObject* CSTLimitSwitch::GetEvent ()
{
  //## begin CSTLimitSwitch::GetEvent%1048237055.body preserve=yes
	ASSERT(m_pOpenEvent != NULL);

	if (m_eLimitAction == ePILimitActionDisabled)
		return NULL;

	return m_pOpenEvent;
  //## end CSTLimitSwitch::GetEvent%1048237055.body
}

void CSTLimitSwitch::AddFootprint (const int p_iPosition)
{
  //## begin CSTLimitSwitch::AddFootprint%1059997034.body preserve=yes
	ASSERT( m_eLimitAction == ePILimitActionFootprint);
	m_pFootprint.AddTail(p_iPosition);

  //## end CSTLimitSwitch::AddFootprint%1059997034.body
}

void CSTLimitSwitch::ResetFootprints ()
{
  //## begin CSTLimitSwitch::ResetFootprints%1059997035.body preserve=yes
	m_pFootprint.RemoveAll();
  //## end CSTLimitSwitch::ResetFootprints%1059997035.body
}

CArray<INT,INT>* CSTLimitSwitch::GetFootprints ()
{
  //## begin CSTLimitSwitch::GetFootprints%1060170829.body preserve=yes
	
	// Declare new Array.
	CArray<INT,INT>* l_pFootprintsArray = new CArray<INT,INT>;

	// Get size from footprint list.
	int l_iSize= m_pFootprint.GetCount();

	// Set array size.
	l_pFootprintsArray->SetSize(l_iSize);

	// Restore from CList to CArray.
	int l_iCnt=0;
	for (POSITION l_Pos=m_pFootprint.GetHeadPosition(); l_Pos!=NULL;)
	{
		// Get data from list.
		INT l_iPosition= m_pFootprint.GetNext(l_Pos);
		// Save data to array.
		l_pFootprintsArray->SetAt(l_iCnt, l_iPosition);
		// Increment counter.
		l_iCnt++;
	}

	return l_pFootprintsArray;
	
  //## end CSTLimitSwitch::GetFootprints%1060170829.body
}

void CSTLimitSwitch::ResetEvent ()
{
  //## begin CSTLimitSwitch::ResetEvent%1069232322.body preserve=yes
	if (m_pOpenEvent->GetbIsSignalled())
	{
		m_pOpenEvent->ResetCompletion();
	}
  //## end CSTLimitSwitch::ResetEvent%1069232322.body
}

void CSTLimitSwitch::ActivateReverseCharacteristics ()
{
  //## begin CSTLimitSwitch::ActivateReverseCharacteristics%1128355573.body preserve=yes
	switch (m_eOriginalLimitCharacteristics)
	{
		case ePILimitHardEdgeFalling:
			m_eCurLimitCharacteristics = ePILimitHardEdgeRaising;
			break;
		case ePILimitSoftEdgeFalling:
			m_eCurLimitCharacteristics = ePILimitSoftEdgeRaising;
			break;

		case ePILimitHardEdgeRaising:
			m_eCurLimitCharacteristics = ePILimitHardEdgeFalling;
			break;
		case ePILimitSoftEdgeRaising:
			m_eCurLimitCharacteristics = ePILimitSoftEdgeFalling;
			break;

		default:
			ASSERT(false);
	}

	CHIInterface::GetInstance()->CloseEvent(m_pLimitID->GetuiID(), m_pOpenEvent);
	m_pOpenEvent->ReleaseRef();
	m_pOpenEvent = NULL;

	EHIOpenEventRegistration l_eOpenEventRegistration = eHILow;

	switch (m_eCurLimitCharacteristics)
	{
		case ePILimitHardEdgeFalling:
		case ePILimitSoftEdgeFalling:
			l_eOpenEventRegistration = eHILow;
			break;

		case ePILimitHardEdgeRaising:
		case ePILimitSoftEdgeRaising:
			l_eOpenEventRegistration = eHIHigh;
			break;

		default:
			ASSERT(false);
	}

	m_pOpenEvent = CHIInterface::GetInstance()->OpenEvent(m_pLimitID->GetuiID(), l_eOpenEventRegistration);
	ASSERT(m_pOpenEvent != NULL);
  //## end CSTLimitSwitch::ActivateReverseCharacteristics%1128355573.body
}

void CSTLimitSwitch::RestoreOriginalCharacteristics ()
{
  //## begin CSTLimitSwitch::RestoreOriginalCharacteristics%1128355586.body preserve=yes
	SeteOriginalLimitCharacteristics(m_eOriginalLimitCharacteristics);
  //## end CSTLimitSwitch::RestoreOriginalCharacteristics%1128355586.body
}

//## Get and Set Operations for Associations (implementation)

EPILimitAction CSTLimitSwitch::GeteLimitAction ()
{
  //## begin CSTLimitSwitch::GeteLimitAction%3E797E120352.get preserve=no
  return m_eLimitAction;
  //## end CSTLimitSwitch::GeteLimitAction%3E797E120352.get
}

void CSTLimitSwitch::SeteLimitAction (EPILimitAction value)
{
  //## begin CSTLimitSwitch::SeteLimitAction%3E797E120352.set preserve=no
  m_eLimitAction = value;
  //## end CSTLimitSwitch::SeteLimitAction%3E797E120352.set
}

EPILimitCharacteristics CSTLimitSwitch::GeteCurLimitCharacteristics ()
{
  //## begin CSTLimitSwitch::GeteCurLimitCharacteristics%3E797E16018D.get preserve=no
  return m_eCurLimitCharacteristics;
  //## end CSTLimitSwitch::GeteCurLimitCharacteristics%3E797E16018D.get
}

CPIObjIdentification * CSTLimitSwitch::GetpLimitID ()
{
  //## begin CSTLimitSwitch::GetpLimitID%3E7ED67A0088.get preserve=no
  return m_pLimitID;
  //## end CSTLimitSwitch::GetpLimitID%3E7ED67A0088.get
}

void CSTLimitSwitch::SetpLimitID (CPIObjIdentification * value)
{
  //## begin CSTLimitSwitch::SetpLimitID%3E7ED67A0088.set preserve=no
  m_pLimitID = value;
  //## end CSTLimitSwitch::SetpLimitID%3E7ED67A0088.set
}

double CSTLimitSwitch::GetdbTimeStamp ()
{
  //## begin CSTLimitSwitch::GetdbTimeStamp%3FBB2AF40250.get preserve=no
  return m_dbTimeStamp;
  //## end CSTLimitSwitch::GetdbTimeStamp%3FBB2AF40250.get
}

void CSTLimitSwitch::SetdbTimeStamp (double value)
{
  //## begin CSTLimitSwitch::SetdbTimeStamp%3FBB2AF40250.set preserve=no
  m_dbTimeStamp = value;
  //## end CSTLimitSwitch::SetdbTimeStamp%3FBB2AF40250.set
}

void CSTLimitSwitch::SeteOriginalLimitCharacteristics (EPILimitCharacteristics value)
{
  //## begin CSTLimitSwitch::SeteOriginalLimitCharacteristics%4343CFBE0007.set preserve=yes
	m_eOriginalLimitCharacteristics = value;
	m_eCurLimitCharacteristics = value;

	CHIInterface::GetInstance()->CloseEvent(m_pLimitID->GetuiID(), m_pOpenEvent);
	m_pOpenEvent->ReleaseRef();
	m_pOpenEvent = NULL;

	EHIOpenEventRegistration l_eOpenEventRegistration = eHILow;

	switch (m_eOriginalLimitCharacteristics)
	{
		case ePILimitHardEdgeFalling:
		case ePILimitSoftEdgeFalling:
			l_eOpenEventRegistration = eHILow;
			break;

		case ePILimitHardEdgeRaising:
		case ePILimitSoftEdgeRaising:
			l_eOpenEventRegistration = eHIHigh;
			break;

		default:
			ASSERT(false);
	}

	m_pOpenEvent = CHIInterface::GetInstance()->OpenEvent(m_pLimitID->GetuiID(), l_eOpenEventRegistration);
	ASSERT(m_pOpenEvent != NULL);
  //## end CSTLimitSwitch::SeteOriginalLimitCharacteristics%4343CFBE0007.set
}

// Additional Declarations
  //## begin CSTLimitSwitch%3E7980A4013E.declarations preserve=yes
  //## end CSTLimitSwitch%3E7980A4013E.declarations

//## begin module%3E797F3D0267.epilog preserve=yes
//## end module%3E797F3D0267.epilog
