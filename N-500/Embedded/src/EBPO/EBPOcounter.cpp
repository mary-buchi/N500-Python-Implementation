//## begin module%3F9E1D9800B2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F9E1D9800B2.cm

//## begin module%3F9E1D9800B2.cp preserve=no
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
//## end module%3F9E1D9800B2.cp

//## Module: EBPOcounter%3F9E1D9800B2; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOcounter.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F9E1D9800B2.additionalIncludes preserve=no
//## end module%3F9E1D9800B2.additionalIncludes

//## begin module%3F9E1D9800B2.includes preserve=yes
//## end module%3F9E1D9800B2.includes

// EBPIconst
#include "EBPIconst.h"
// EBPOimpl
#include "EBPOimpl.h"
// EBPOidnt
#include "EBPOidnt.h"
// EBPOcounter
#include "EBPOcounter.h"
// EBPOlogic
#include "EBPOlogic.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3F9E1D9800B2.declarations preserve=no
//## end module%3F9E1D9800B2.declarations

//## begin module%3F9E1D9800B2.additionalDeclarations preserve=yes
//## end module%3F9E1D9800B2.additionalDeclarations


// Class CPOLifeTimeCounterHandler 







CPOLifeTimeCounterHandler::CPOLifeTimeCounterHandler (CPOPersistentObjImplementation* p_pImpl)
  //## begin CPOLifeTimeCounterHandler::CPOLifeTimeCounterHandler%1067267864.hasinit preserve=no
      : m_dwElapsedAutoSaveTime(0), m_dwTicksAtConnLost(0), m_pImpl(p_pImpl)
  //## end CPOLifeTimeCounterHandler::CPOLifeTimeCounterHandler%1067267864.hasinit
  //## begin CPOLifeTimeCounterHandler::CPOLifeTimeCounterHandler%1067267864.initialization preserve=yes
  //## end CPOLifeTimeCounterHandler::CPOLifeTimeCounterHandler%1067267864.initialization
{
  //## begin CPOLifeTimeCounterHandler::CPOLifeTimeCounterHandler%1067267864.body preserve=yes
  //## end CPOLifeTimeCounterHandler::CPOLifeTimeCounterHandler%1067267864.body
}


CPOLifeTimeCounterHandler::~CPOLifeTimeCounterHandler()
{
  //## begin CPOLifeTimeCounterHandler::~CPOLifeTimeCounterHandler%.body preserve=yes
	DeleteCounterList();
  //## end CPOLifeTimeCounterHandler::~CPOLifeTimeCounterHandler%.body
}



//## Other Operations (implementation)
void CPOLifeTimeCounterHandler::StartMonitoring (EPILifeTimeCounter p_eDevice, const UINT p_uiStartUpValue)
{
  //## begin CPOLifeTimeCounterHandler::StartMonitoring%1067324997.body preserve=yes
	CSingleLock l_Lock(&m_CounterLock, TRUE);

	m_pImpl->StartTimer(m_pImpl->GetpConfig()->GetdwTimerInterval() * 1000);

	CPOLifeTimeCounter *l_pCounter = FindCounter(p_eDevice);

	if (l_pCounter == NULL)
	{
		if (p_eDevice == eScan)
		{
			// Reset scans in hi
			CCOSyncObjectInt *l_pSyncObj = CHIInterface::GetInstance()->GetNumberOfWCScan();
			l_pSyncObj->ReleaseRef();
        }

		// Counter not found. Add it to list.
		m_Counters.AddTail(new CPOLifeTimeCounter(p_eDevice, 0, p_uiStartUpValue));
	}

  //## end CPOLifeTimeCounterHandler::StartMonitoring%1067324997.body
}

void CPOLifeTimeCounterHandler::StopMonitoring (const EPILifeTimeCounter &p_eDevice)
{
  //## begin CPOLifeTimeCounterHandler::StopMonitoring%1067324998.body preserve=yes

	CPOLifeTimeCounter *l_pCounter = FindCounter(p_eDevice);

	if (l_pCounter != NULL)
	{
		// Counter found. Change Monitoring started bit.
		l_pCounter->SetbMonitoringStarted(false);
	}

  //## end CPOLifeTimeCounterHandler::StopMonitoring%1067324998.body
}

CPOLifeTimeCounter* CPOLifeTimeCounterHandler::FindCounter (const EPILifeTimeCounter p_eCounter)
{
  //## begin CPOLifeTimeCounterHandler::FindCounter%1067325002.body preserve=yes
	CSingleLock l_Lock(&m_CounterLock, TRUE);

	for (POSITION l_Pos = m_Counters.GetHeadPosition(); l_Pos!=NULL;)
	{
		// Position next list object.
		CPOLifeTimeCounter *l_pCounter = m_Counters.GetNext(l_Pos);
		ASSERT(l_pCounter != NULL);

		// Compare to objects. Dereferenzieren.!
		if (l_pCounter->GeteDevice() == p_eCounter)
		{
			return l_pCounter;
		}
	}
	// Counter not found.
	return NULL;

  //## end CPOLifeTimeCounterHandler::FindCounter%1067325002.body
}

void CPOLifeTimeCounterHandler::AddDeltaValues (const UINT p_uiDeltaValue)
{
  //## begin CPOLifeTimeCounterHandler::AddDeltaValues%1067325004.body preserve=yes
	CSingleLock l_Lock(&m_CounterLock, TRUE);

	for (POSITION l_Pos = m_Counters.GetHeadPosition(); l_Pos != NULL;)
	{
		// Position next list object.
		CPOLifeTimeCounter *l_pCounter = m_Counters.GetNext(l_Pos);
		ASSERT(l_pCounter != NULL);

		// Is monitoring started?
		if (l_pCounter->GetbMonitoringStarted())
		{
			EPILifeTimeCounter l_eCounter = l_pCounter->GeteDevice();

			switch (l_eCounter)
			{
			case eLampPrimary:
			case eLampSecondary:
			case eLaser:
			case eInstrumentUnit:
			case eDetector:
				// Monitoring started. Increment delta time.
				l_pCounter->IncDeltaValue(p_uiDeltaValue) ;
				break;

			case eScan:
				{
					CCOSyncObjectInt *l_pSyncObjectInt = CHIInterface::GetInstance()->GetNumberOfWCScan();
					UINT l_uiNumberOfScans = l_pSyncObjectInt->GetValue();
					l_pSyncObjectInt->ReleaseRef();
					l_pCounter->IncDeltaValue(l_uiNumberOfScans);
				}
				break;
	
			default:
				ASSERT(false);
			}
		}
	}
  //## end CPOLifeTimeCounterHandler::AddDeltaValues%1067325004.body
}

UINT CPOLifeTimeCounterHandler::NumberOfActivatedCounter ()
{
  //## begin CPOLifeTimeCounterHandler::NumberOfActivatedCounter%1067325005.body preserve=yes
	CSingleLock l_Lock(&m_CounterLock, TRUE);

	UINT l_uiCnt = 0;
	for (POSITION l_Pos = m_Counters.GetHeadPosition(); l_Pos != NULL;)
	{
		// Position next list object.
		CPOLifeTimeCounter *l_pCounter = m_Counters.GetNext(l_Pos);
		ASSERT(l_pCounter != NULL);

		// Is monitoring started?
		if (l_pCounter->GetbMonitoringStarted())
		{
			// Monitoring started. Increment value.
			l_uiCnt++;
		}
	}
	return l_uiCnt;
  //## end CPOLifeTimeCounterHandler::NumberOfActivatedCounter%1067325005.body
}

void CPOLifeTimeCounterHandler::ResetDeltaValue ()
{
  //## begin CPOLifeTimeCounterHandler::ResetDeltaValue%1067498934.body preserve=yes
	CSingleLock l_Lock(&m_CounterLock, TRUE);

	for (POSITION l_Pos = m_Counters.GetHeadPosition(); l_Pos != NULL;)
	{
		// Position of next list object.
		CPOLifeTimeCounter *l_pCounter = m_Counters.GetNext(l_Pos);
		ASSERT(l_pCounter != NULL);
		l_pCounter->SetuiDeltaValue(0);
	}
  //## end CPOLifeTimeCounterHandler::ResetDeltaValue%1067498934.body
}

void CPOLifeTimeCounterHandler::RemoveNotActivatedCounter ()
{
  //## begin CPOLifeTimeCounterHandler::RemoveNotActivatedCounter%1067498935.body preserve=yes
	CSingleLock l_Lock(&m_CounterLock, TRUE);

	POSITION l_Pos1, l_Pos2;

	for (l_Pos1 = m_Counters.GetHeadPosition(); l_Pos1 != NULL;)
	{
		l_Pos2 = l_Pos1;

		// Position of next list object.
		CPOLifeTimeCounter *l_pCounter = m_Counters.GetNext(l_Pos1);
		ASSERT(l_pCounter != NULL);

		if (!l_pCounter->GetbMonitoringStarted())
		{
			m_Counters.RemoveAt(l_Pos2);
			l_pCounter->ReleaseRef();
		}
	}

	// Stop timer if no counter is acivated.
	if (NumberOfActivatedCounter() == 0)
	{
		// No counter activated. Stop timer interval.
		m_pImpl->StopTimer();
	}
  //## end CPOLifeTimeCounterHandler::RemoveNotActivatedCounter%1067498935.body
}

void CPOLifeTimeCounterHandler::IncElapsedAutoSaveTime ()
{
  //## begin CPOLifeTimeCounterHandler::IncElapsedAutoSaveTime%1067498936.body preserve=yes
	DWORD l_dwTimerInterval = GetpImpl()->GetpConfig()->GetdwTimerInterval();
	l_dwTimerInterval *= 1000;		// Convert from [s] to [ms]
	m_dwElapsedAutoSaveTime += l_dwTimerInterval;
  //## end CPOLifeTimeCounterHandler::IncElapsedAutoSaveTime%1067498936.body
}

void CPOLifeTimeCounterHandler::UpdateEpromValues ()
{
  //## begin CPOLifeTimeCounterHandler::UpdateEpromValues%1068021105.body preserve=yes
	CSingleLock l_Lock(&m_CounterLock, TRUE);

	for (POSITION l_Pos = m_Counters.GetHeadPosition(); l_Pos != NULL;)
	{
		// Position next list object.
		CPOLifeTimeCounter *l_pCounter = m_Counters.GetNext(l_Pos);
		ASSERT(l_pCounter != NULL);

		// Is monitoring started?
		if (l_pCounter->GetbMonitoringStarted())
		{
			GetpImpl()->GetpLogic()->UpdateLifeTimeCounter(l_pCounter);
		}
	}

	if (NumberOfActivatedCounter() > 0)
	{
		// Save values to eprom.
		GetpImpl()->GetpLogic()->SaveLifeTime();
	}
  //## end CPOLifeTimeCounterHandler::UpdateEpromValues%1068021105.body
}

void CPOLifeTimeCounterHandler::DeleteCounterList ()
{
  //## begin CPOLifeTimeCounterHandler::DeleteCounterList%1080142972.body preserve=yes
	CSingleLock l_Lock(&m_CounterLock, TRUE);

	for (POSITION l_Pos = m_Counters.GetHeadPosition(); l_Pos!=NULL;)
	{
		// set position to next list object
		CPOLifeTimeCounter *l_pCounter = m_Counters.GetNext(l_Pos);
		ASSERT(l_pCounter != NULL);

		if (l_pCounter != NULL)
		{
			l_pCounter->ReleaseRef();
		}
		l_pCounter = NULL;
	}
	m_Counters.RemoveAll();
  //## end CPOLifeTimeCounterHandler::DeleteCounterList%1080142972.body
}

//## Get and Set Operations for Class Attributes (implementation)

DWORD CPOLifeTimeCounterHandler::GetdwElapsedAutoSaveTime ()
{
  //## begin CPOLifeTimeCounterHandler::GetdwElapsedAutoSaveTime%3FA0E0BC008C.get preserve=no
  return m_dwElapsedAutoSaveTime;
  //## end CPOLifeTimeCounterHandler::GetdwElapsedAutoSaveTime%3FA0E0BC008C.get
}

void CPOLifeTimeCounterHandler::SetdwElapsedAutoSaveTime (DWORD value)
{
  //## begin CPOLifeTimeCounterHandler::SetdwElapsedAutoSaveTime%3FA0E0BC008C.set preserve=no
  m_dwElapsedAutoSaveTime = value;
  //## end CPOLifeTimeCounterHandler::SetdwElapsedAutoSaveTime%3FA0E0BC008C.set
}

DWORD CPOLifeTimeCounterHandler::GetdwTicksAtConnLost ()
{
  //## begin CPOLifeTimeCounterHandler::GetdwTicksAtConnLost%405AB4BB02E8.get preserve=no
  return m_dwTicksAtConnLost;
  //## end CPOLifeTimeCounterHandler::GetdwTicksAtConnLost%405AB4BB02E8.get
}

void CPOLifeTimeCounterHandler::SetdwTicksAtConnLost (DWORD value)
{
  //## begin CPOLifeTimeCounterHandler::SetdwTicksAtConnLost%405AB4BB02E8.set preserve=no
  m_dwTicksAtConnLost = value;
  //## end CPOLifeTimeCounterHandler::SetdwTicksAtConnLost%405AB4BB02E8.set
}

//## Get and Set Operations for Associations (implementation)

CPOPersistentObjImplementation * CPOLifeTimeCounterHandler::GetpImpl ()
{
  //## begin CPOLifeTimeCounterHandler::GetpImpl%3F9D412F0230.get preserve=no
  return m_pImpl;
  //## end CPOLifeTimeCounterHandler::GetpImpl%3F9D412F0230.get
}

// Additional Declarations
  //## begin CPOLifeTimeCounterHandler%3F9D409F0358.declarations preserve=yes
  //## end CPOLifeTimeCounterHandler%3F9D409F0358.declarations

// Class CPOLifeTimeCounter 




CPOLifeTimeCounter::CPOLifeTimeCounter (const CString& p_sItem)
  //## begin CPOLifeTimeCounter::CPOLifeTimeCounter%1067325001.hasinit preserve=no
      : m_bMonitoringStarted(true)
  //## end CPOLifeTimeCounter::CPOLifeTimeCounter%1067325001.hasinit
  //## begin CPOLifeTimeCounter::CPOLifeTimeCounter%1067325001.initialization preserve=yes
  , CPIPersistentLifeTimeCounter(p_sItem)
  , m_uiDeltaValue(0)
  //## end CPOLifeTimeCounter::CPOLifeTimeCounter%1067325001.initialization
{
  //## begin CPOLifeTimeCounter::CPOLifeTimeCounter%1067325001.body preserve=yes
  //## end CPOLifeTimeCounter::CPOLifeTimeCounter%1067325001.body
}

CPOLifeTimeCounter::CPOLifeTimeCounter (EPILifeTimeCounter p_eDevice, const UINT p_uiValue, const UINT p_uiDeltaValue)
  //## begin CPOLifeTimeCounter::CPOLifeTimeCounter%1068448313.hasinit preserve=no
      : m_bMonitoringStarted(true)
  //## end CPOLifeTimeCounter::CPOLifeTimeCounter%1068448313.hasinit
  //## begin CPOLifeTimeCounter::CPOLifeTimeCounter%1068448313.initialization preserve=yes
  , CPIPersistentLifeTimeCounter(p_eDevice, p_uiValue)
  , m_uiDeltaValue(p_uiDeltaValue)
  //## end CPOLifeTimeCounter::CPOLifeTimeCounter%1068448313.initialization
{
  //## begin CPOLifeTimeCounter::CPOLifeTimeCounter%1068448313.body preserve=yes
  //## end CPOLifeTimeCounter::CPOLifeTimeCounter%1068448313.body
}


CPOLifeTimeCounter::~CPOLifeTimeCounter()
{
  //## begin CPOLifeTimeCounter::~CPOLifeTimeCounter%.body preserve=yes
  //## end CPOLifeTimeCounter::~CPOLifeTimeCounter%.body
}



//## Other Operations (implementation)
void CPOLifeTimeCounter::IncCounterValue (const UINT p_uiDeltaValue)
{
  //## begin CPOLifeTimeCounter::IncCounterValue%1073631915.body preserve=yes
	m_uiValue += p_uiDeltaValue;
  //## end CPOLifeTimeCounter::IncCounterValue%1073631915.body
}

void CPOLifeTimeCounter::IncDeltaValue (const UINT p_uiDeltaValue)
{
  //## begin CPOLifeTimeCounter::IncDeltaValue%1074066584.body preserve=yes
	m_uiDeltaValue += p_uiDeltaValue;
  //## end CPOLifeTimeCounter::IncDeltaValue%1074066584.body
}

void CPOLifeTimeCounter::ResetValues ()
{
  //## begin CPOLifeTimeCounter::ResetValues%1074066585.body preserve=yes
	m_uiDeltaValue = 0;
	m_uiValue = 0;
  //## end CPOLifeTimeCounter::ResetValues%1074066585.body
}

//## Get and Set Operations for Associations (implementation)

UINT CPOLifeTimeCounter::GetuiDeltaValue ()
{
  //## begin CPOLifeTimeCounter::GetuiDeltaValue%3F9E21FB03A1.get preserve=no
  return m_uiDeltaValue;
  //## end CPOLifeTimeCounter::GetuiDeltaValue%3F9E21FB03A1.get
}

void CPOLifeTimeCounter::SetuiDeltaValue (UINT value)
{
  //## begin CPOLifeTimeCounter::SetuiDeltaValue%3F9E21FB03A1.set preserve=no
  m_uiDeltaValue = value;
  //## end CPOLifeTimeCounter::SetuiDeltaValue%3F9E21FB03A1.set
}

bool CPOLifeTimeCounter::GetbMonitoringStarted ()
{
  //## begin CPOLifeTimeCounter::GetbMonitoringStarted%3F9E2A4201BC.get preserve=no
  return m_bMonitoringStarted;
  //## end CPOLifeTimeCounter::GetbMonitoringStarted%3F9E2A4201BC.get
}

void CPOLifeTimeCounter::SetbMonitoringStarted (bool value)
{
  //## begin CPOLifeTimeCounter::SetbMonitoringStarted%3F9E2A4201BC.set preserve=no
  m_bMonitoringStarted = value;
  //## end CPOLifeTimeCounter::SetbMonitoringStarted%3F9E2A4201BC.set
}

// Additional Declarations
  //## begin CPOLifeTimeCounter%3F9E1B52015E.declarations preserve=yes
  //## end CPOLifeTimeCounter%3F9E1B52015E.declarations

//## begin module%3F9E1D9800B2.epilog preserve=yes
//## end module%3F9E1D9800B2.epilog
