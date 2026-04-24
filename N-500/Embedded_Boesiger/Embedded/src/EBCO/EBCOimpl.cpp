//## begin module%3B8D3AD4020C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8D3AD4020C.cm

//## begin module%3B8D3AD4020C.cp preserve=no
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
//## end module%3B8D3AD4020C.cp

//## Module: EBCOimpl%3B8D3AD4020C; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOimpl.cpp

// stdafx
#include "stdafx.h"
//## begin module%3B8D3AD4020C.additionalIncludes preserve=no
//## end module%3B8D3AD4020C.additionalIncludes

//## begin module%3B8D3AD4020C.includes preserve=yes
//## end module%3B8D3AD4020C.includes

// EBCOidnt
#include "EBCOidnt.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBCOcomd
#include "EBCOcomd.h"
// EBCOimpl
#include "EBCOimpl.h"
// EBCOwkth
#include "EBCOwkth.h"
// EBCOintf
#include "EBCOintf.h"


//## begin module%3B8D3AD4020C.declarations preserve=no
//## end module%3B8D3AD4020C.declarations

//## begin module%3B8D3AD4020C.additionalDeclarations preserve=yes
//## end module%3B8D3AD4020C.additionalDeclarations


// Class ICOAsyncImplementation 






ICOAsyncImplementation::ICOAsyncImplementation (ICOAsyncInterface* p_pInterface)
  //## begin ICOAsyncImplementation::ICOAsyncImplementation%999204134.hasinit preserve=no
      : m_sSubsystemID(p_pInterface->GetsSubsystemID()), m_pInterface(p_pInterface), m_pWorkerThread(NULL)
  //## end ICOAsyncImplementation::ICOAsyncImplementation%999204134.hasinit
  //## begin ICOAsyncImplementation::ICOAsyncImplementation%999204134.initialization preserve=yes
  //## end ICOAsyncImplementation::ICOAsyncImplementation%999204134.initialization
{
  //## begin ICOAsyncImplementation::ICOAsyncImplementation%999204134.body preserve=yes
  //## end ICOAsyncImplementation::ICOAsyncImplementation%999204134.body
}


ICOAsyncImplementation::~ICOAsyncImplementation()
{
  //## begin ICOAsyncImplementation::~ICOAsyncImplementation%.body preserve=yes
	// m_pWorkerThread auto deletes ...
  //## end ICOAsyncImplementation::~ICOAsyncImplementation%.body
}



//## Other Operations (implementation)
void ICOAsyncImplementation::InitInstance ()
{
  //## begin ICOAsyncImplementation::InitInstance%999280838.body preserve=yes
	// create worker thread
	m_pWorkerThread = new CCOThreadWorkImplementation(this, m_sSubsystemID);
	m_pWorkerThread->InitInstance();

    // state machine engine should have been created
    ASSERT(m_pStateMachineEngine != NULL);

    // build state machine
    m_pStateMachineEngine->Create();

    // start worker thread
    CCOSyncObjectPtr l_SyncObj = m_pWorkerThread->Start();
	l_SyncObj->Synchronize();
  //## end ICOAsyncImplementation::InitInstance%999280838.body
}

void ICOAsyncImplementation::ExitInstance ()
{
  //## begin ICOAsyncImplementation::ExitInstance%999280841.body preserve=yes
    // delete state machine
//    m_pStateMachineEngine->DeleteStateMachine();

	// destroy worker thread
	m_pWorkerThread->TerminateThread();
  //## end ICOAsyncImplementation::ExitInstance%999280841.body
}

void ICOAsyncImplementation::DispatchCommand (CCOCommand* p_pCommand)
{
  //## begin ICOAsyncImplementation::DispatchCommand%999108321.body preserve=yes
    try
    {
        // execute command and process state machine
        m_pStateMachineEngine->Run(p_pCommand);
    }
	catch(XCOExceptionError* p_pException)
	{
		// subsystem specific exception, to pass to the client??
		if (!HandleErrorException(p_pException))
		{
			try
			{
				CCOCommandCleanupInitialize l_Command(this);
				l_Command.CreateSyncObjects();
				m_pStateMachineEngine->Run(&l_Command);

				// clean up state machine
				m_pStateMachineEngine->Cleanup();
			}
			catch(...)
			{
                // it is not supported to throw excpetions within a cleanup cycle
				ASSERT(FALSE);	
			}

            throw new XCOExceptionCleanupInitialize(p_pException);
		}
		else
			throw;
	}
    catch(XCOExceptionCleanupStop*)
    {
        try
        {
            // cleanup stop case
            CCOCommandCleanupStop l_Command(this);
		    l_Command.CreateSyncObjects();
            m_pStateMachineEngine->Run(&l_Command);

            // clean up state machine
            m_pStateMachineEngine->Cleanup();
        }
		catch(...)
		{
            // it is not supported to throw excpetions within a cleanup cycle
			ASSERT(FALSE);	
		}

        throw;
    }
    catch(XCOExceptionCleanupInitialize*)
    {
        try
        {
            // cleanup initialze case
            CCOCommandCleanupInitialize l_Command(this);
		    l_Command.CreateSyncObjects();
            m_pStateMachineEngine->Run(&l_Command);

            // clean up state machine
            m_pStateMachineEngine->Cleanup();
        }
		catch(...)
		{
            // it is not supported to throw excpetions within a cleanup cycle
			ASSERT(FALSE);	
		}

        throw;
    }
    catch(XCOExceptionInvalidState*)
    {
        // let wrong state pass by
        throw;
    }
    catch(...)
    {
        try
        {
            // cleanup initialze case
            CCOCommandCleanupInitialize l_Command(this);
		    l_Command.CreateSyncObjects();
            m_pStateMachineEngine->Run(&l_Command);

            // clean up state machine
            m_pStateMachineEngine->Cleanup();
        }
		catch(...)
		{
            // it is not supported to throw excpetions within a cleanup cycle
			ASSERT(FALSE);	
		}

        XCO_CLEANUP_INIT(CO_ID);
    }
  //## end ICOAsyncImplementation::DispatchCommand%999108321.body
}

void ICOAsyncImplementation::AddCommand (CCOCommand* p_pCommand, const ECOAsyncCallQueue p_ePriority)
{
  //## begin ICOAsyncImplementation::AddCommand%999280844.body preserve=yes
    m_pWorkerThread->AddCommand(p_pCommand, p_ePriority);
  //## end ICOAsyncImplementation::AddCommand%999280844.body
}

CString ICOAsyncImplementation::GetsCurrentState ()
{
  //## begin ICOAsyncImplementation::GetsCurrentState%1000031200.body preserve=yes
    return m_pStateMachineEngine->GetsCurrentState();
  //## end ICOAsyncImplementation::GetsCurrentState%1000031200.body
}

CString ICOAsyncImplementation::GetsContextID ()
{
  //## begin ICOAsyncImplementation::GetsContextID%1000925470.body preserve=yes
    return m_sSubsystemID;
  //## end ICOAsyncImplementation::GetsContextID%1000925470.body
}

void ICOAsyncImplementation::StartTimer (UINT p_uiInterval)
{
  //## begin ICOAsyncImplementation::StartTimer%1053348766.body preserve=yes
    m_pWorkerThread->StartTimer(p_uiInterval);
  //## end ICOAsyncImplementation::StartTimer%1053348766.body
}

void ICOAsyncImplementation::StopTimer ()
{
  //## begin ICOAsyncImplementation::StopTimer%1053348767.body preserve=yes
    m_pWorkerThread->StopTimer();
  //## end ICOAsyncImplementation::StopTimer%1053348767.body
}

void ICOAsyncImplementation::SuspendCommandQueue (const ECOAsyncCallQueue p_eQueue)
{
  //## begin ICOAsyncImplementation::SuspendCommandQueue%1000752293.body preserve=yes
    m_pWorkerThread->SuspendCommandQueue(p_eQueue);
  //## end ICOAsyncImplementation::SuspendCommandQueue%1000752293.body
}

void ICOAsyncImplementation::ResumeCommandQueue (const ECOAsyncCallQueue p_eQueue)
{
  //## begin ICOAsyncImplementation::ResumeCommandQueue%1000752294.body preserve=yes
    m_pWorkerThread->ResumeCommandQueue(p_eQueue);
  //## end ICOAsyncImplementation::ResumeCommandQueue%1000752294.body
}

void ICOAsyncImplementation::FlushCommandQueue (const ECOAsyncCallQueue p_eQueue)
{
  //## begin ICOAsyncImplementation::FlushCommandQueue%1000752295.body preserve=yes
    m_pWorkerThread->FlushCommandQueue(p_eQueue);
  //## end ICOAsyncImplementation::FlushCommandQueue%1000752295.body
}

void ICOAsyncImplementation::ResetWaitReasonFlags ()
{
  //## begin ICOAsyncImplementation::ResetWaitReasonFlags%1066286190.body preserve=yes
  //## end ICOAsyncImplementation::ResetWaitReasonFlags%1066286190.body
}

bool ICOAsyncImplementation::HandleErrorException (XCOExceptionError* p_pException)
{
  //## begin ICOAsyncImplementation::HandleErrorException%1071666883.body preserve=yes
    return false;
  //## end ICOAsyncImplementation::HandleErrorException%1071666883.body
}

ECOInterruptReason ICOAsyncImplementation::WaitOnActionDone (CCOSyncObjectArray* p_pSyncArray, const DWORD p_dwWakeUpMask, const DWORD p_dwTimeout, UINT& p_uiSignalledIndex)
{
  //## begin ICOAsyncImplementation::WaitOnActionDone%1001017242.body preserve=yes
    ResetWaitReasonFlags();
    return m_pWorkerThread->WaitOnActionDone(p_pSyncArray, p_dwWakeUpMask, p_dwTimeout, p_uiSignalledIndex);
  //## end ICOAsyncImplementation::WaitOnActionDone%1001017242.body
}

ECOInterruptReason ICOAsyncImplementation::WaitOnActionDone (CCOSyncObject* p_pSyncObj, const DWORD p_dwWakeUpMask, const DWORD p_dwTimeout)
{
  //## begin ICOAsyncImplementation::WaitOnActionDone%1001017243.body preserve=yes
    CCOSyncObjectArrayPtr l_pSyncArray = new CCOSyncObjectArray();

    l_pSyncArray->Add(p_pSyncObj);
    return WaitOnActionDone(l_pSyncArray, p_dwWakeUpMask, p_dwTimeout);
  //## end ICOAsyncImplementation::WaitOnActionDone%1001017243.body
}

//## Get and Set Operations for Class Attributes (implementation)

const CString ICOAsyncImplementation::GetsSubsystemID () const
{
  //## begin ICOAsyncImplementation::GetsSubsystemID%3B8FD97801E9.get preserve=no
  return m_sSubsystemID;
  //## end ICOAsyncImplementation::GetsSubsystemID%3B8FD97801E9.get
}

//## Get and Set Operations for Associations (implementation)

ICOAsyncInterface * ICOAsyncImplementation::GetpInterface ()
{
  //## begin ICOAsyncImplementation::GetpInterface%3DA69D4700A9.get preserve=no
  return m_pInterface;
  //## end ICOAsyncImplementation::GetpInterface%3DA69D4700A9.get
}

// Additional Declarations
  //## begin ICOAsyncImplementation%3B8D3AAC02FE.declarations preserve=yes
  //## end ICOAsyncImplementation%3B8D3AAC02FE.declarations

//## begin module%3B8D3AD4020C.epilog preserve=yes
//## end module%3B8D3AD4020C.epilog
