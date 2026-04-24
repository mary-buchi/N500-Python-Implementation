//## begin module%3B8D2EA70155.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8D2EA70155.cm

//## begin module%3B8D2EA70155.cp preserve=no
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
//## end module%3B8D2EA70155.cp

//## Module: EBCOwkth%3B8D2EA70155; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOwkth.cpp

// stdafx
#include "stdafx.h"
//## begin module%3B8D2EA70155.additionalIncludes preserve=no
//## end module%3B8D2EA70155.additionalIncludes

//## begin module%3B8D2EA70155.includes preserve=yes
//## end module%3B8D2EA70155.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBCOcomd
#include "EBCOcomd.h"
// EBCOqueu
#include "EBCOqueu.h"
// EBCOimpl
#include "EBCOimpl.h"
// EBCOwkth
#include "EBCOwkth.h"
// EBCOthtm
#include "EBCOthtm.h"


//## begin module%3B8D2EA70155.declarations preserve=no
//## end module%3B8D2EA70155.declarations

//## begin module%3B8D2EA70155.additionalDeclarations preserve=yes
//## end module%3B8D2EA70155.additionalDeclarations


// Class CCOThreadWorkImplementation 









CCOThreadWorkImplementation::CCOThreadWorkImplementation (ICOAsyncImplementation* p_pContext, const CString& p_sName, const UINT p_uiStackSize)
  //## begin CCOThreadWorkImplementation::CCOThreadWorkImplementation%999108313.hasinit preserve=no
      : m_pContext(p_pContext), m_pTimer(NULL)
  //## end CCOThreadWorkImplementation::CCOThreadWorkImplementation%999108313.hasinit
  //## begin CCOThreadWorkImplementation::CCOThreadWorkImplementation%999108313.initialization preserve=yes
  , ICOThreadWork(p_sName, p_uiStackSize)
  //## end CCOThreadWorkImplementation::CCOThreadWorkImplementation%999108313.initialization
{
  //## begin CCOThreadWorkImplementation::CCOThreadWorkImplementation%999108313.body preserve=yes
	// build command queues
	m_CommandQueues.SetSize(eCOQueueLastItem);
	m_CommandQueues.SetAt(eCOQueueNormal,				new CCOCommandQueue(eCOQueueNormal));
	m_CommandQueues.SetAt(eCOQueueAboveNormal,			new CCOCommandQueue(eCOQueueAboveNormal));
	m_CommandQueues.SetAt(eCOQueueHigh,				    new CCOCommandQueue(eCOQueueHigh));

	// setup queue events
	m_QueueEvents.SetSize(eCOQueueLastItem);
	m_QueueEvents.SetAt(eCOQueueNormal,			&m_CommandQueues.GetAt(eCOQueueNormal)->GetQueueEvent());
	m_QueueEvents.SetAt(eCOQueueAboveNormal,	&m_CommandQueues.GetAt(eCOQueueAboveNormal)->GetQueueEvent());
	m_QueueEvents.SetAt(eCOQueueHigh,			&m_CommandQueues.GetAt(eCOQueueHigh)->GetQueueEvent());
  //## end CCOThreadWorkImplementation::CCOThreadWorkImplementation%999108313.body
}


CCOThreadWorkImplementation::~CCOThreadWorkImplementation()
{
  //## begin CCOThreadWorkImplementation::~CCOThreadWorkImplementation%.body preserve=yes
    CSingleLock l_Lock(&m_TimerAccessLock, TRUE);
    if (m_pTimer)
    {
        m_pTimer->TerminateThread();
        m_pTimer = NULL;
    }
    l_Lock.Unlock();

	// cleanup queues
	delete m_CommandQueues.GetAt(eCOQueueNormal);
	delete m_CommandQueues.GetAt(eCOQueueAboveNormal);
	delete m_CommandQueues.GetAt(eCOQueueHigh);

	m_QueueEvents.RemoveAll();
	m_CommandQueues.RemoveAll();

  //## end CCOThreadWorkImplementation::~CCOThreadWorkImplementation%.body
}



//## Other Operations (implementation)
void CCOThreadWorkImplementation::AddCommand (CCOCommand* p_pCommand, const ECOAsyncCallQueue p_ePriority, const bool p_bUniqCommand)
{
  //## begin CCOThreadWorkImplementation::AddCommand%999280845.body preserve=yes
    // add command to queue
    m_CommandQueues.GetAt(p_ePriority)->AddTail(p_pCommand, p_bUniqCommand);
  //## end CCOThreadWorkImplementation::AddCommand%999280845.body
}

void CCOThreadWorkImplementation::SuspendCommandQueue (const ECOAsyncCallQueue p_eQueue)
{
  //## begin CCOThreadWorkImplementation::SuspendCommandQueue%1000752290.body preserve=yes
    m_CommandQueues.GetAt(p_eQueue)->Suspend();
  //## end CCOThreadWorkImplementation::SuspendCommandQueue%1000752290.body
}

void CCOThreadWorkImplementation::ResumeCommandQueue (const ECOAsyncCallQueue p_eQueue)
{
  //## begin CCOThreadWorkImplementation::ResumeCommandQueue%1000752291.body preserve=yes
    m_CommandQueues.GetAt(p_eQueue)->Resume();
  //## end CCOThreadWorkImplementation::ResumeCommandQueue%1000752291.body
}

void CCOThreadWorkImplementation::FlushCommandQueue (const ECOAsyncCallQueue p_eQueue)
{
  //## begin CCOThreadWorkImplementation::FlushCommandQueue%1000752292.body preserve=yes
    m_CommandQueues.GetAt(p_eQueue)->Flush();
  //## end CCOThreadWorkImplementation::FlushCommandQueue%1000752292.body
}

ECOInterruptReason CCOThreadWorkImplementation::WaitOnActionDone (CCOSyncObjectArray* p_pSyncArray, const DWORD p_dwWakeUpMask, const DWORD p_dwTimeout, UINT& p_uiSignalledIndex)
{
  //## begin CCOThreadWorkImplementation::WaitOnActionDone%1001017247.body preserve=yes
    UINT                l_uiSignalledIndex, l_uiCustomStartIndex;
    ECOInterruptReason  l_eIReason;
	CArray<CSyncObject*, CSyncObject*> l_SyncArray;

	l_SyncArray.Add(&m_TerminationEvent);
    
    // normal command queue
	l_SyncArray.Add(&m_DummyEvent);                            

    // above normal queue
    if (p_dwWakeUpMask & CO_WAKE_MASK_CMD_ABOVE_NORMAL)
	    l_SyncArray.Add(m_QueueEvents.GetAt(eCOQueueAboveNormal));
    else
        l_SyncArray.Add(&m_DummyEvent);

    // high prio queue
    if (p_dwWakeUpMask & CO_WAKE_MASK_CMD_HIGH)
	    l_SyncArray.Add(m_QueueEvents.GetAt(eCOQueueHigh));
    else
        l_SyncArray.Add(&m_DummyEvent);

    // add custom events
    l_uiCustomStartIndex = l_SyncArray.GetSize();
    for (int l_iCnt=0; l_iCnt<p_pSyncArray->GetSize(); l_iCnt++)
    {
        l_SyncArray.Add(p_pSyncArray->GetAt(l_iCnt));
    }

    bool l_bKeepWaiting = true;
    while (l_bKeepWaiting)
    {
        // wait for event
        switch(WaitForEvent(&l_SyncArray, p_dwTimeout, l_uiSignalledIndex))
        {
            case eCOWakeUpCommandHigh:
                ASSERT(p_dwWakeUpMask & CO_WAKE_MASK_CMD_HIGH);
            case eCOWakeUpTerminateThread:
                l_eIReason = eIRCmdHigh;
                break;

            case eCOWakeUpCommandAboveNormal:
                ASSERT(p_dwWakeUpMask & CO_WAKE_MASK_CMD_ABOVE_NORMAL);
                l_eIReason = eIRCmdAboveNormal;
                break;

            case eCOWakeUpImplEvent:
                l_eIReason = eIRActionsDone;
                break;

            case eCOWakeUpTimeout:
                l_eIReason = eIRTimeout;
                break;

            case eCOWakeUpCommandNormal:
            default:
                ASSERT(FALSE);
        }

        // consider exceptions
        p_pSyncArray->HasException();

        if (l_eIReason != eIRActionsDone ||
            !(p_dwWakeUpMask & CO_WAKE_MASK_ACTIONS_ALL))
        {
            // exit loop
            l_bKeepWaiting = false;

            if (&p_uiSignalledIndex && l_eIReason == eIRActionsDone)
            {
                // supply index of signalled action
                p_uiSignalledIndex = l_uiSignalledIndex;
            }
        }
        else
        {
            // we only may exit from the loop after all actions have been signalled
            // -> remove signalled sync object from array and check size
            l_SyncArray.RemoveAt(l_uiSignalledIndex + l_uiCustomStartIndex);

            if (l_SyncArray.GetSize() == (long)l_uiCustomStartIndex)
            {
                // ok, all have been signalled
                l_bKeepWaiting = false;
            }
        }
    }

    return l_eIReason;
  //## end CCOThreadWorkImplementation::WaitOnActionDone%1001017247.body
}

void CCOThreadWorkImplementation::StartTimer (UINT p_uiInterval)
{
  //## begin CCOThreadWorkImplementation::StartTimer%1053348759.body preserve=yes
    CSingleLock l_Lock(&m_TimerAccessLock, TRUE);

    if (!m_pTimer)
    {
        m_pTimer = new CCOThreadTimer(this, p_uiInterval);
        CCOSyncObjectPtr l_SyncObj = m_pTimer->Start();
		l_SyncObj->Synchronize();
    }
  //## end CCOThreadWorkImplementation::StartTimer%1053348759.body
}

void CCOThreadWorkImplementation::StopTimer ()
{
  //## begin CCOThreadWorkImplementation::StopTimer%1053348760.body preserve=yes
    CSingleLock l_Lock(&m_TimerAccessLock, TRUE);

    if (m_pTimer)
    {
        CCOThreadTimer* l_pTimer = m_pTimer;
        m_pTimer = NULL;
        l_pTimer->TerminateThread();

        // skip pending commands, already stored in the queue
        m_CommandQueues[eCOQueueAboveNormal]->SkipCommand(typeid(CCOCommandTimer));
    }
  //## end CCOThreadWorkImplementation::StopTimer%1053348760.body
}

void CCOThreadWorkImplementation::OnTimer ()
{
  //## begin CCOThreadWorkImplementation::OnTimer%1053348757.body preserve=yes
    CSingleLock l_Lock(&m_TimerAccessLock, TRUE);

    if (m_pTimer)
    {
        // execute timer command with higher priority
        CCOCommandTimer* l_pCmd = new CCOCommandTimer(m_pContext);
        l_pCmd->CreateSyncObjects();
        AddCommand(l_pCmd, eCOQueueAboveNormal, true);
    }
  //## end CCOThreadWorkImplementation::OnTimer%1053348757.body
}

int CCOThreadWorkImplementation::ThreadMain ()
{
  //## begin CCOThreadWorkImplementation::ThreadMain%999108314.body preserve=yes
	bool l_bKeepRunning = true;

	while (l_bKeepRunning)
	{
		CArray<CSyncObject*, CSyncObject*>* l_pSyncArray = NULL;

		try
		{
			// create array of sync objects to wait for
			l_pSyncArray = BuildStandardSyncArray();
			if (WaitForEvent(l_pSyncArray) == eCOWakeUpTerminateThread)
			{
				// terminate thread -> exit main loop
				l_bKeepRunning = false;
			}

			// cleanup array
			delete l_pSyncArray;
		}
		catch(...)
		{
			// should never happen !!
			ASSERT(FALSE);

			delete l_pSyncArray;
		}
	}

	return 0;
  //## end CCOThreadWorkImplementation::ThreadMain%999108314.body
}

ECOAsyncThreadWakeUpReason CCOThreadWorkImplementation::WaitForEvent (CArray<CSyncObject*, CSyncObject*>* p_pSyncArray, const DWORD p_dwTimeout, UINT& p_uiSignalledIndex)
{
  //## begin CCOThreadWorkImplementation::WaitForEvent%999108316.body preserve=yes
	ECOAsyncThreadWakeUpReason l_eWakeUpReason = eCOWakeUpTerminateThread;
    UINT    l_uiSignalledIndex;
    DWORD   l_dwRes;

	// go to sleep
	CMultiLock l_Lock((CSyncObject**)p_pSyncArray->GetData(), p_pSyncArray->GetSize());
	switch (l_dwRes = l_Lock.Lock(p_dwTimeout, FALSE))
	{
		case WAIT_OBJECT_0:	
            // termination event
			l_eWakeUpReason = eCOWakeUpTerminateThread;
			break;

		case WAIT_OBJECT_0+1:
			// normal priority command
			l_eWakeUpReason = eCOWakeUpCommandNormal;
			DispatchCommand(eCOQueueNormal);
			break;

		case WAIT_OBJECT_0+2:
			// above normal priority command
			l_eWakeUpReason = eCOWakeUpCommandAboveNormal;
			DispatchCommand(eCOQueueAboveNormal);
			break;

		case WAIT_OBJECT_0+3:
			// normal priority command
			l_eWakeUpReason = eCOWakeUpCommandHigh;
			DispatchCommand(eCOQueueHigh);
			break;

		case WAIT_TIMEOUT:
			l_eWakeUpReason = eCOWakeUpTimeout;
			break;

		default:
			// implementation event
			l_eWakeUpReason = eCOWakeUpImplEvent;

            l_uiSignalledIndex = l_dwRes - (WAIT_OBJECT_0+4);
            if ((long)l_uiSignalledIndex > p_pSyncArray->GetSize()-1)
            {
                // what is beeing signalled???
                ASSERT(FALSE);
            }
            else
            {
                if (&p_uiSignalledIndex)
                {
                    // supply index of the signalled object
                    p_uiSignalledIndex = l_uiSignalledIndex;
                }
            }
			break;
	}

	return l_eWakeUpReason;
  //## end CCOThreadWorkImplementation::WaitForEvent%999108316.body
}

CArray<CSyncObject*, CSyncObject*>* CCOThreadWorkImplementation::BuildStandardSyncArray ()
{
  //## begin CCOThreadWorkImplementation::BuildStandardSyncArray%999108317.body preserve=yes
	CArray<CSyncObject*, CSyncObject*>* l_pSyncArray = new CArray<CSyncObject*, CSyncObject*>;

	l_pSyncArray->Add(&m_TerminationEvent);
	l_pSyncArray->Add(m_QueueEvents.GetAt(eCOQueueNormal));
	l_pSyncArray->Add(m_QueueEvents.GetAt(eCOQueueAboveNormal));
	l_pSyncArray->Add(m_QueueEvents.GetAt(eCOQueueHigh));

	return l_pSyncArray;
  //## end CCOThreadWorkImplementation::BuildStandardSyncArray%999108317.body
}

void CCOThreadWorkImplementation::DispatchCommand (const ECOAsyncCallQueue p_eCommandQueue)
{
  //## begin CCOThreadWorkImplementation::DispatchCommand%999108318.body preserve=yes
    CCOCommand* l_pCommand = NULL;

	try
	{
		// get pending command
		if (l_pCommand = m_CommandQueues.GetAt(p_eCommandQueue)->RemoveHead())
        {
		    // let context process command
		    m_pContext->DispatchCommand(l_pCommand);

            // command has successfully been executed and may be destroyed
            delete l_pCommand;
        }
	}
    catch(XCOException* p_pException)
    {
        // command ended up with an exception -> attach it to the sync object
        l_pCommand->AttachException(p_pException);
        delete l_pCommand;
    }
	catch(...)
	{
        ASSERT(FALSE);
        delete l_pCommand;
	}
  //## end CCOThreadWorkImplementation::DispatchCommand%999108318.body
}

// Additional Declarations
  //## begin CCOThreadWorkImplementation%3B8D2E6C0377.declarations preserve=yes
  //## end CCOThreadWorkImplementation%3B8D2E6C0377.declarations

//## begin module%3B8D2EA70155.epilog preserve=yes
//## end module%3B8D2EA70155.epilog
