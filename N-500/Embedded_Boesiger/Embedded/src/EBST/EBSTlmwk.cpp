//## begin module%3E7AD325003B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E7AD325003B.cm

//## begin module%3E7AD325003B.cp preserve=no
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
//## end module%3E7AD325003B.cp

//## Module: EBSTlmwk%3E7AD325003B; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTlmwk.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E7AD325003B.additionalIncludes preserve=no
//## end module%3E7AD325003B.additionalIncludes

//## begin module%3E7AD325003B.includes preserve=yes
//## end module%3E7AD325003B.includes

// EBCOsync
#include "EBCOsync.h"
// EBSTimpl
#include "EBSTimpl.h"
// EBSTlmwk
#include "EBSTlmwk.h"
// EBSTlimit
#include "EBSTlimit.h"
// EBSTlogic
#include "EBSTlogic.h"


//## begin module%3E7AD325003B.declarations preserve=no
//## end module%3E7AD325003B.declarations

//## begin module%3E7AD325003B.additionalDeclarations preserve=yes
//## end module%3E7AD325003B.additionalDeclarations


// Class CSTLimitWorkerThread 









CSTLimitWorkerThread::CSTLimitWorkerThread (CSTLimitHandler* p_pContext)
  //## begin CSTLimitWorkerThread::CSTLimitWorkerThread%1048237047.hasinit preserve=no
      : m_bStarted(false), m_pContext(p_pContext), m_pCmdSyncObj(NULL)
  //## end CSTLimitWorkerThread::CSTLimitWorkerThread%1048237047.hasinit
  //## begin CSTLimitWorkerThread::CSTLimitWorkerThread%1048237047.initialization preserve=yes
    , ICOThreadWork("Limit Worker Thread", 100)
  //## end CSTLimitWorkerThread::CSTLimitWorkerThread%1048237047.initialization
{
  //## begin CSTLimitWorkerThread::CSTLimitWorkerThread%1048237047.body preserve=yes
	// ::SetThreadPriorityBoost(m_hThread, false);
  //## end CSTLimitWorkerThread::CSTLimitWorkerThread%1048237047.body
}


CSTLimitWorkerThread::~CSTLimitWorkerThread()
{
  //## begin CSTLimitWorkerThread::~CSTLimitWorkerThread%.body preserve=yes
	if (m_pCmdSyncObj)
		m_pCmdSyncObj->ReleaseRef();
	m_pCmdSyncObj = NULL;
  //## end CSTLimitWorkerThread::~CSTLimitWorkerThread%.body
}



//## Other Operations (implementation)
int CSTLimitWorkerThread::ThreadMain ()
{
  //## begin CSTLimitWorkerThread::ThreadMain%1048237048.body preserve=yes

	int l_iDef = GetThreadPriority();
	SetThreadPriority(100);

	bool l_bRunning = true;
	while (l_bRunning)
	{
		try
		{
			if (m_bStarted)
				l_bRunning = DoLimits();
			else
				l_bRunning = DoIdle();
		}
		catch(...)
		{
			// TODO:
			ASSERT(false);
		}
	}

	return 0;
  //## end CSTLimitWorkerThread::ThreadMain%1048237048.body
}

CCOSyncObject* CSTLimitWorkerThread::Activate ()
{
  //## begin CSTLimitWorkerThread::Activate%1048237050.body preserve=yes
	ASSERT(m_pCmdSyncObj == NULL);
	m_pCmdSyncObj = new CCOSyncObject(_T("ST:LimitWorkerThread::Activate"));
	m_pCmdSyncObj->AddRef();

	CCOSyncObject* l_pSyncObj = m_pCmdSyncObj;
	m_StartEvent.SetEvent();
	return l_pSyncObj;
  //## end CSTLimitWorkerThread::Activate%1048237050.body
}

CCOSyncObject* CSTLimitWorkerThread::Deactivate ()
{
  //## begin CSTLimitWorkerThread::Deactivate%1048237051.body preserve=yes
	ASSERT(m_pCmdSyncObj == NULL);
	m_pCmdSyncObj = new CCOSyncObject(_T("ST:LimitWorkerThread::Deactivate"));
	m_pCmdSyncObj->AddRef();

	CCOSyncObject* l_pSyncObj = m_pCmdSyncObj;
	m_StopEvent.SetEvent();
	return l_pSyncObj;
  //## end CSTLimitWorkerThread::Deactivate%1048237051.body
}

bool CSTLimitWorkerThread::DoIdle ()
{
  //## begin CSTLimitWorkerThread::DoIdle%1048237052.body preserve=yes
	// put 2 events into an array
	// Create an array of synchronization objects that you wish to wait on.
	CO_TRACE(_T("ST"), _T("Do Idle()"));

	CSyncObject* l_Events[] = 
	{
		&m_TerminationEvent,
		&m_StartEvent,
		&m_StopEvent
	};

	CMultiLock l_Lock(l_Events, 3);

	// Call the Lock member function to determine if a resource (event) is available (signaled).
	// This will cause the thread to wait until one of the events is signaled.
	DWORD l_SignalledIndex = l_Lock.Lock(INFINITE, false);

	switch(l_SignalledIndex)
	{
		case 0:
			// termination event
			return false;

		case 1:
			// start event occured
			m_StopEvent.ResetEvent();
			m_StartEvent.ResetEvent();
			m_bStarted = true;

			{
				// do handshake with activate/deactivate
				CCOSyncObject* l_pSyncObj = m_pCmdSyncObj;
				ASSERT(l_pSyncObj != NULL);
				m_pCmdSyncObj = NULL;
				l_pSyncObj->SignalCompletion();
				l_pSyncObj->ReleaseRef();
			}
			return true; 

		case 2:
			// stop event occured
			m_StopEvent.ResetEvent();
			m_StartEvent.ResetEvent();

			{
				// do handshake with activate/deactivate
				CCOSyncObject* l_pSyncObj = m_pCmdSyncObj;
				ASSERT(l_pSyncObj != NULL);
				m_pCmdSyncObj = NULL;
				l_pSyncObj->SignalCompletion();
				l_pSyncObj->ReleaseRef();
			}
			return true; 

		default:
			ASSERT(false);
	}

	return true;
  //## end CSTLimitWorkerThread::DoIdle%1048237052.body
}

bool CSTLimitWorkerThread::DoLimits ()
{
  //## begin CSTLimitWorkerThread::DoLimits%1048237053.body preserve=yes
	CO_TRACE(_T("ST"), _T("Do Limits()"));
	
	CCOSyncObjectArray* l_LimitEvents = NULL;

	try
	{
		bool l_bRetValue = false;

		// Each time a event occured, search the switch in the list.
		
		// 2 Events are always in the Array: Start and stop from the workertread
		const UINT l_uiLimitOffset = 2;

		// Declare: pointer array for sync objects
		CTypedPtrArray<CPtrArray,CSyncObject*> l_SyncArray;

		// Add termination event to array
		l_SyncArray.Add(&m_TerminationEvent);

		// Add stop event to array
		l_SyncArray.Add(&m_StopEvent);
	         
		// Get the events for all limit switches.
		CArray<UINT, UINT> l_LimitIDs;
		l_LimitEvents = m_pContext->GetLimitSwitchEvents(l_LimitIDs);
		
		// Determine the limit event array size.
		int l_iNumberOfLimitEvents = l_LimitEvents->GetSize();

		// Add the limit event array to the syncronisation array
		for (int l_iCnt=0; l_iCnt < l_iNumberOfLimitEvents; l_iCnt++)
		{    
			l_SyncArray.Add(l_LimitEvents->GetAt(l_iCnt));
		}

		// Constructs a CMultiLock object.
		CMultiLock l_Lock((CSyncObject**)l_SyncArray.GetData(), l_SyncArray.GetSize());

		// Will return as soon as one or more of the synchronization objects becomes signaled.
		DWORD l_SignalledIndex = l_Lock.Lock(INFINITE, false);
		
		// Get tickcount.
		m_pContext->GetpContext()->GetpLogic()->ElapsedTime(_T("Limit worker thread"));

		// TODO: watch for exceptions

		switch(l_SignalledIndex)
		{
			case 0:
				// termination event
				break;

			case 1:
				// stop event occured
				m_StartEvent.ResetEvent();
				m_StopEvent.ResetEvent();
				m_bStarted = false;
				l_bRetValue = true;

				{
					// do handshake with activate/deactivate
					CCOSyncObject* l_pSyncObj = m_pCmdSyncObj;
					ASSERT(l_pSyncObj != NULL);
					m_pCmdSyncObj = NULL;
					l_pSyncObj->SignalCompletion();
					l_pSyncObj->ReleaseRef();
				}
				break;

			default:
				if (l_SignalledIndex >= l_uiLimitOffset && l_SignalledIndex < l_uiLimitOffset + l_iNumberOfLimitEvents)
				{
					// A limit has been hit.
					int l_iHitLimit = l_SignalledIndex - l_uiLimitOffset;
					m_pContext->OnHit(l_LimitIDs.GetAt(l_iHitLimit));
					l_bRetValue = true;
				}
				else
				{	// An undefined event was signaled. Scro.
					ASSERT(false);
				}
		}

		l_LimitEvents->ReleaseRef();
		return l_bRetValue;
	}
	catch(...)
	{
		l_LimitEvents->ReleaseRef();
		throw;
	}

  //## end CSTLimitWorkerThread::DoLimits%1048237053.body
}

// Additional Declarations
  //## begin CSTLimitWorkerThread%3E7AD30701A3.declarations preserve=yes
  //## end CSTLimitWorkerThread%3E7AD30701A3.declarations

//## begin module%3E7AD325003B.epilog preserve=yes
//## end module%3E7AD325003B.epilog
