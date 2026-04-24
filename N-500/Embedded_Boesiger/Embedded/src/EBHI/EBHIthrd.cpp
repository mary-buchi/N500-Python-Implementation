//## begin module%3E227AEB01CF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E227AEB01CF.cm

//## begin module%3E227AEB01CF.cp preserve=no
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
//## end module%3E227AEB01CF.cp

//## Module: EBHIthrd%3E227AEB01CF; Package body
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIthrd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E227AEB01CF.additionalIncludes preserve=no
//## end module%3E227AEB01CF.additionalIncludes

//## begin module%3E227AEB01CF.includes preserve=yes
#ifdef _WIN32_WCE
  #include "Pkfuncs.h"
#endif
//## end module%3E227AEB01CF.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBCOsync
#include "EBCOsync.h"
// EBHIdefi
#include "EBHIdefi.h"
// EBHIexcp
#include "EBHIexcp.h"
// EBHIcomd
#include "EBHIcomd.h"
// EBHIthrd
#include "EBHIthrd.h"
// EBHIintf
#include "EBHIintf.h"
// EBHIident
#include "EBHIident.h"
// EBHITrsm
#include "EBHITrsm.h"


//## begin module%3E227AEB01CF.declarations preserve=no
//## end module%3E227AEB01CF.declarations

//## begin module%3E227AEB01CF.additionalDeclarations preserve=yes
//## end module%3E227AEB01CF.additionalDeclarations


// Class CHIEventWorkerThread 



//## begin CHIEventWorkerThread::pInstance%3E5A240E0291.role preserve=no  public: static CHIEventWorkerThread {1..1 -> RFHN}
CHIEventWorkerThread *CHIEventWorkerThread::m_pInstance;
//## end CHIEventWorkerThread::pInstance%3E5A240E0291.role









CHIEventWorkerThread::CHIEventWorkerThread (const CString& p_sName, const UINT p_uiStackSize, const bool p_bHWPresent)
  //## begin CHIEventWorkerThread::CHIEventWorkerThread%1046077276.hasinit preserve=no
      : m_bHWPresent(p_bHWPresent), m_bTerminating(false), m_dwWCIrqNumber(0), m_bEnableEventSignalisation(true), m_pSyncObj(NULL), m_dwHWExceptionEventNr(0)
  //## end CHIEventWorkerThread::CHIEventWorkerThread%1046077276.hasinit
  //## begin CHIEventWorkerThread::CHIEventWorkerThread%1046077276.initialization preserve=yes
  ,ICOThreadWork(p_sName, 100, p_uiStackSize)
  //## end CHIEventWorkerThread::CHIEventWorkerThread%1046077276.initialization
{
  //## begin CHIEventWorkerThread::CHIEventWorkerThread%1046077276.body preserve=yes
  m_pSyncObj = new CCOSyncObject(_T("HI:EventWorkerThread"));
  //## end CHIEventWorkerThread::CHIEventWorkerThread%1046077276.body
}


CHIEventWorkerThread::~CHIEventWorkerThread()
{
  //## begin CHIEventWorkerThread::~CHIEventWorkerThread%.body preserve=yes
	// release event map
	POSITION l_Pos = m_EventMap.GetStartPosition();
	while(l_Pos!=NULL)
	{
		DWORD l_dwID;
		CHIEventRegistration* l_pEventReg;
		m_EventMap.GetNextAssoc(l_Pos, l_dwID, l_pEventReg);
		delete l_pEventReg;
	}
	m_EventMap.RemoveAll();

  m_pSyncObj->ReleaseRef();
  //## end CHIEventWorkerThread::~CHIEventWorkerThread%.body
}



//## Other Operations (implementation)
int CHIEventWorkerThread::ThreadMain ()
{
  //## begin CHIEventWorkerThread::ThreadMain%1046077277.body preserve=yes
  try
  {
    DWORD l_dwRetVal = 0;
    bool  l_bExitThread = false;
    IHIInterface* l_pHWIntf = IHIInterface::GetInstance();

    if (m_bHWPresent)
    {

#ifdef _WIN32_WCE
      m_pInstance->m_dwWCIrqNumber = l_pHWIntf->GetdwWCIrqNumber();
  
      BOOL l_bRetValue = InterruptInitialize(m_pInstance->m_dwWCIrqNumber,      // IRQ ID to be associated with this thread (IST)
                                             (HANDLE)m_pInstance->m_WCIrqEvent, // Event to be signaled when the IRQ is triggered
                                             NULL,
                                             0);

      if (!l_bRetValue)
      {
        CO_TRACE1(HI_ID, _T("WC InterruptInitialize failed; WCIRQ Number %d\n"),m_pInstance->m_dwWCIrqNumber);
        ASSERT(FALSE);
      }

      l_pHWIntf->ClearWCIrq();
      l_pHWIntf->EnableWCIrq();

      l_pHWIntf->NotifyWCISRtoSendEvent();
      l_dwRetVal = WaitForSingleObject(m_WCIrqEvent, 1000);
      switch (l_dwRetVal)
      {
        case WAIT_OBJECT_0:
          {
            CO_TRACE(HI_ID, _T("First ISR Event -> ok"));
            m_WCIrqEvent.ResetEvent();
            
            if (!CHIInterface::GetInstance()->AcknowledgeEventSignalisation())
            {
              ASSERT(FALSE);
            }

            m_pSyncObj->SignalCompletion();

            break;
          }
        case WAIT_TIMEOUT:
        case WAIT_FAILED:
          {
            CO_TRACE(HI_ID, _T("First ISR Event -> failed\n"));
            XHIExceptionError* l_pException = new XHIExceptionError(HI_ID, IDE_HW_INTF_ERROR_EVENT_SIGNALISATION, _T(__FILE__), __LINE__, l_dwRetVal);
            m_pSyncObj->AttachException(l_pException);
            break;
          }
        default:
          {
            ASSERT(FALSE);
            break;
          }
      }
    }
    else
    {
      m_pSyncObj->SignalCompletion();
#endif
	}


    while (!l_bExitThread)
    {
      if (DoIdle())
      { // exit thread
        l_bExitThread = true;
      }
      else
      { // execute command
        l_bExitThread = false;
        ExecuteISREvent();
      } // end if
    } // end while

#ifdef _WIN32_WCE
    if (l_pHWIntf != NULL)
    {
      // disables the WC IRQ in the spartan
      l_pHWIntf->DisableWCIrq();
      CO_TRACE(HI_ID, _T("DisableWCIrq completed"));
    }

    if (m_dwWCIrqNumber)
    {
      // This function signals to the kernel that interrupt processing has been completed
      // disables the WC IRQ specified by the WC IRQ identifier.
      InterruptDisable(m_dwWCIrqNumber);
      CO_TRACE(HI_ID, _T("InterruptDisable completed"));
    }
#endif

  }
  catch(...)
  {
    CO_TRACE(HI_ID, _T("CHIEventWorkerThread() catch"));
    ASSERT(FALSE);
  }
  
  return 0;
  //## end CHIEventWorkerThread::ThreadMain%1046077277.body
}

void CHIEventWorkerThread::CreateInstance (const bool p_bHWPresent)
{
  //## begin CHIEventWorkerThread::CreateInstance%1046077278.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CHIEventWorkerThread(_T("EBHIEventWorkerThread"), 0, p_bHWPresent);
    CCOSyncObjectPtr l_SyncObj = m_pInstance->Start();    
	l_SyncObj->Synchronize(2000);
  //## end CHIEventWorkerThread::CreateInstance%1046077278.body
}

void CHIEventWorkerThread::DeleteInstance ()
{
  //## begin CHIEventWorkerThread::DeleteInstance%1046077279.body preserve=yes
    if (m_pInstance)
    {
      m_pInstance->TerminateThread();
      m_pInstance = NULL;
    }
  //## end CHIEventWorkerThread::DeleteInstance%1046077279.body
}

CHIEventWorkerThread* CHIEventWorkerThread::GetInstance ()
{
  //## begin CHIEventWorkerThread::GetInstance%1046077280.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CHIEventWorkerThread::GetInstance%1046077280.body
}

void CHIEventWorkerThread::TerminateThread ()
{
  //## begin CHIEventWorkerThread::TerminateThread%1067437968.body preserve=yes
    if (m_bHWPresent)
    {
	    if (m_bRunning)
	    {
		    HANDLE l_hThread = m_hThread;
        m_bTerminating = true;

		    // signal termination event
        m_WCIrqEvent.SetEvent();
    	        
		    if( GetCurrentThreadId() != m_nThreadID )
		    {
			    // Different thread is destroying, therefore wait until finished.
			    DWORD dwResult = ::WaitForSingleObject( l_hThread, 30000 );
		    }
		    else
		    {
			    // This is the worker thread commiting suicide.
			    m_bAutoDelete = TRUE;  
		    }
	    }
    }
    else
    {
        ICOThreadWork::TerminateThread();
    }
  //## end CHIEventWorkerThread::TerminateThread%1067437968.body
}

bool CHIEventWorkerThread::DoIdle ()
{
  //## begin CHIEventWorkerThread::DoIdle%1046077281.body preserve=yes
  bool l_bRetVal = false;

  if (m_bHWPresent)
  {
    ::WaitForSingleObject(m_WCIrqEvent, INFINITE);
    m_WCIrqEvent.ResetEvent();

    if (m_bTerminating)
        return true;

    return false;
  }
  else
  {
    ::WaitForSingleObject(m_TerminationEvent, INFINITE);
    l_bRetVal = true;
  }
  
  return l_bRetVal;
  //## end CHIEventWorkerThread::DoIdle%1046077281.body
}

bool CHIEventWorkerThread::ExecuteISREvent ()
{
  //## begin CHIEventWorkerThread::ExecuteISREvent%1046077282.body preserve=yes
  bool l_bRetVal = false;

  if (m_bHWPresent)
  {
    if (m_bEnableEventSignalisation)
    {
      // check I2C event register
      CheckI2CEvent();
      // check WC state register
      CheckWCEvents();
      // check event register
      CheckDigInputEvents();
      // check stepper motors event
      CheckStepperEvents();
      // check hardware (ISR) events
      CheckHWExceptions();
    }
    else
    {
      CO_TRACE(HI_ID, _T("Event received -> check disabled"));
    }

    if (!CHIInterface::GetInstance()->AcknowledgeEventSignalisation())
    {
      ASSERT(FALSE);
    }
  }
  return l_bRetVal;
  //## end CHIEventWorkerThread::ExecuteISREvent%1046077282.body
}

CCOSyncObject* CHIEventWorkerThread::OpenEvent (DWORD p_dwID, EHIOpenEventRegistration p_eRegistration)
{
  //## begin CHIEventWorkerThread::OpenEvent%1050387899.body preserve=yes
	CHIEventRegistration*	l_pOpenEvent = NULL;
	CCOSyncObject*			l_pSyncObj = NULL;

	CSingleLock l_Lock(&m_AccessLock, TRUE);

	if (m_EventMap.Lookup(p_dwID, l_pOpenEvent))
	{
		// attach new registration to already existing entry
		l_pSyncObj = l_pOpenEvent->Add(p_eRegistration);
	}
	else
	{
		// register new event
		l_pOpenEvent = new CHIEventRegistration();
		m_EventMap.SetAt(p_dwID, l_pOpenEvent);

		l_pSyncObj = l_pOpenEvent->Add(p_eRegistration);
	}

	return l_pSyncObj;
  //## end CHIEventWorkerThread::OpenEvent%1050387899.body
}

void CHIEventWorkerThread::CloseEvent (DWORD p_dwID, CCOSyncObject* p_pSyncObj)
{
  //## begin CHIEventWorkerThread::CloseEvent%1050387900.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, TRUE);
	CHIEventRegistration* l_pOpenEvent = NULL;
	if (!m_EventMap.Lookup(p_dwID, l_pOpenEvent))
	{
		// wrong id
		throw new XHIExceptionError(HI_ID, IDE_HW_INTF_INVALID_OBJ_ID, _T(__FILE__), __LINE__, 0);
	}

	if (l_pOpenEvent->Remove(p_pSyncObj))
	{
		m_EventMap.RemoveKey(p_dwID);
		delete l_pOpenEvent;
	}
  //## end CHIEventWorkerThread::CloseEvent%1050387900.body
}

void CHIEventWorkerThread::CheckHWExceptions ()
{
  //## begin CHIEventWorkerThread::CheckHWExceptions%1054101545.body preserve=yes
    CHIEventRegistration* l_pEvent = NULL;
    DWORD l_dwMaskRegister = 0xFFFFFFFE; 

    DWORD* l_pdwAdr = CHITReservedSharedMemory::GetI2CEventRegStartAdr();
    if (l_pdwAdr == NULL)
    { 
      ASSERT(FALSE);
    }

    DWORD l_dwObjID = IHIInterface::GetInstance()->GetStaticObjID(eHIIDHwExceptions);
	  DWORD l_dwLogID = IHIInterface::GetInstance()->GetLogicalID(l_dwObjID);

    if (l_dwLogID == 0)
    {
      // no exception defined
      return;
    }
  
  
    if (*l_pdwAdr & l_dwMaskRegister) // mask out I2C event 
    {
      // HW (warning error) event occured
      // clear HW event register
      *l_pdwAdr = *l_pdwAdr & ~l_dwMaskRegister;

      // event signaled !!!
      CO_TRACE(HI_ID, _T("Received HW Exception Event"));

      CSingleLock l_Lock(&m_AccessLock, TRUE);
      if (m_EventMap.Lookup(l_dwLogID, l_pEvent))
      {        
        l_pEvent->CheckRegisteredHWWarnErrState();
      }
    }
  //## end CHIEventWorkerThread::CheckHWExceptions%1054101545.body
}

void CHIEventWorkerThread::CheckWCEvents ()
{
  //## begin CHIEventWorkerThread::CheckWCEvents%1052803855.body preserve=yes
    DWORD* l_pdwWCEventStartAdr = CHITReservedSharedMemory::GetWCEventRegStartAdr();
    DWORD* l_pdwWCExceptionStartAdr = CHITReservedSharedMemory::GetHWExceptionRegStartAdr();

    if ((l_pdwWCEventStartAdr == NULL) || (l_pdwWCExceptionStartAdr == NULL))
    { 
       ASSERT(FALSE);
    }

    EHIOpenEventRegistration l_eStateChange = eHIUndefined;
    CHIEventRegistration* l_pEvent = NULL;
    DWORD l_dwLogID = 0;
    DWORD l_dwMaskRegister = 0x1;  
    DWORD l_dwDWordSize = (8 * sizeof(DWORD));

    // determine base LogID of the wc input
    DWORD l_dwLogIDBaseAdr = CHITReservedSharedMemory::GetcdwAdrOffsetWCEventReg() << CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr();
    DWORD l_dwLogIDDataWidth = 0x1 << CHIProcessImageParameter::GetcdwShiftCountsDataWidth();
    l_dwLogID = l_dwLogIDBaseAdr | l_dwLogIDDataWidth;

    l_dwMaskRegister = 0x1;

    for (DWORD l_dwBitPos = 0; l_dwBitPos < l_dwDWordSize; l_dwBitPos++)
    {
      l_dwMaskRegister = 0x1 << l_dwBitPos;
      if (*l_pdwWCEventStartAdr & l_dwMaskRegister)
      {
        // event signaled !!!
        CO_TRACE(HI_ID, _T("Received WC Event"));

        CSingleLock l_Lock(&m_AccessLock, TRUE);
        try
        {
          if (m_EventMap.Lookup(l_dwLogID, l_pEvent))
          {         
            // event is registered
            l_pEvent->CheckRegisteredWCState(NULL);
          }
        }
        catch(...)
        {
          throw;
        }
      }
      
      l_dwLogID++;
      *l_pdwWCEventStartAdr&= (~l_dwMaskRegister);
    }
  //## end CHIEventWorkerThread::CheckWCEvents%1052803855.body
}

void CHIEventWorkerThread::CheckDigInputEvents ()
{
  //## begin CHIEventWorkerThread::CheckDigInputEvents%1050387901.body preserve=yes
  DWORD l_dwLogID = 0;
  
  PDWORD l_pdwDigInputEventStartAdr = CHITReservedSharedMemory::GetDigInputEventRegStartAdr();
  PDWORD l_pdwDigInputStartAdr = CHITReservedSharedMemory::GetDigInputRegStartAdr();
  PDWORD l_pdwDigInputRaisingEdgeAdr = CHITReservedSharedMemory::GetDigInputRaisingEdgeRegStartAdr();
  PDWORD l_pdwDigInputTrailingEdgeAdr = CHITReservedSharedMemory::GetDigInputTrailingEdgeRegStartAdr();

  if ((l_pdwDigInputEventStartAdr == NULL) || (l_pdwDigInputStartAdr == NULL))
  { 
    ASSERT(FALSE);
  }

  EHIOpenEventRegistration l_eStateChange = eHIUndefined;
  DWORD l_dwMaskRegister = 1;
  DWORD l_dwDWordSize = (8 * sizeof(DWORD)); // DWORD size in bit
  
  CHIEventRegistration* l_pEvent = NULL;
  
  for (DWORD l_dwAdrOffset = 0; l_dwAdrOffset < CHITReservedSharedMemory::GetcdwNumbersOfDigInputEventReg(); l_dwAdrOffset++)
  {   
    // determine base LogID of the digital input
    DWORD l_dwLogIDBaseAdr = (CHITReservedSharedMemory::GetcdwAdrOffsetDigInputReg() + (l_dwAdrOffset*sizeof(DWORD))) << CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr();
    DWORD l_dwLogIDDataWidth = 0x1 << CHIProcessImageParameter::GetcdwShiftCountsDataWidth();
    l_dwLogID = l_dwLogIDBaseAdr | l_dwLogIDDataWidth;

    for (DWORD l_dwBitPos = 0; l_dwBitPos < l_dwDWordSize; l_dwBitPos++)
    {
      l_dwMaskRegister = 0x1 << l_dwBitPos;
      if (l_pdwDigInputEventStartAdr[l_dwAdrOffset] & l_dwMaskRegister)
      {
        l_pdwDigInputEventStartAdr[l_dwAdrOffset]&= (~l_dwMaskRegister);

        // event signaled !!!
        CO_TRACE(HI_ID, _T("Received Digital Input Event"));
        
        // check changed state - LOW->HIGH
        if ((l_pdwDigInputRaisingEdgeAdr[l_dwAdrOffset] & l_dwMaskRegister) != 0)
        {
          l_pdwDigInputRaisingEdgeAdr[l_dwAdrOffset]&= (~l_dwMaskRegister);

          // input have changed from LOW -> HIGH
          CSingleLock l_Lock(&m_AccessLock, TRUE);
          XHIHardwareExceptionError* l_pException = NULL;
          try
          {
            if (m_EventMap.Lookup(l_dwLogID, l_pEvent))
            {
              // event is registered          
              // element was found -> check registered state and send the event
              l_pEvent->CheckRegisteredHWState(eHIHigh, l_pException);
              CO_TRACE1(HI_ID,_T("Event Number: %#010xhas changed from LOW->HIGH"),l_dwLogID);
            }
          }
          catch(...)
          {
            if (l_pException)
            {
              delete l_pException;
            }
            l_pException = NULL;
            throw;
          }
        }
        // check changed state - HIGH -> LOW
        if ((l_pdwDigInputTrailingEdgeAdr[l_dwAdrOffset] & l_dwMaskRegister) != 0)
        {
          l_pdwDigInputTrailingEdgeAdr[l_dwAdrOffset]&= (~l_dwMaskRegister);

          // input have changed from HIGH -> LOW
          CSingleLock l_Lock(&m_AccessLock, TRUE);
          XHIHardwareExceptionError* l_pException = NULL;
          try
          {
            if (m_EventMap.Lookup(l_dwLogID, l_pEvent))
            {
              // event is registered          
              // element was found -> check registered state and send the event
              l_pEvent->CheckRegisteredHWState(eHILow, l_pException);
              CO_TRACE1(HI_ID,_T("Event Number: %#010x has changed from HIGH->LOW"),l_dwLogID);
            }
          }
          catch(...)
          {
            if (l_pException)
            {
              delete l_pException;
            }
            l_pException = NULL;
            throw;
          }
        }
      }

      l_dwLogID++;  
    } // END - for (DWORD l_dwBitPos = 0; l_dwBitPos < l_dwDWordSize; l_dwBitPos++)
    
  } // END - for (DWORD l_dwAdrOffset = 0; l_dwAdrOffset < CHIT.....

  //## end CHIEventWorkerThread::CheckDigInputEvents%1050387901.body
}

void CHIEventWorkerThread::CheckStepperEvents ()
{
  //## begin CHIEventWorkerThread::CheckStepperEvents%1066028228.body preserve=yes
  DWORD* l_pdwStartAdr = CHITReservedSharedMemory::GetStepperEventRegStartAdr();
  if (l_pdwStartAdr == NULL)
  { 
    ASSERT(FALSE);
  }

  CHIEventRegistration* l_pEvent = NULL;
  DWORD l_dwLogID = 0;
  DWORD l_dwMaskRegister = 1; 
  DWORD l_dwDWordSize = (8 * sizeof(DWORD));
  
  for (DWORD l_dwAdrOffset = 0; l_dwAdrOffset < CHITReservedSharedMemory::GetcdwNumbersOfStepperEventReg(); l_dwAdrOffset++)
  {   
    // determine base LogID of the digital input
    DWORD l_dwLogIDBaseAdr = (CHITReservedSharedMemory::GetcdwAdrOffsetStepperEventReg() + (l_dwAdrOffset*sizeof(DWORD))) << CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr();
    DWORD l_dwLogIDDataWidth = 0x1 << CHIProcessImageParameter::GetcdwShiftCountsDataWidth();
    l_dwLogID = l_dwLogIDBaseAdr | l_dwLogIDDataWidth;

    for (DWORD l_dwBitPos = 0; l_dwBitPos < l_dwDWordSize; l_dwBitPos++)
    {
      l_dwMaskRegister = 0x1 << l_dwBitPos;
      if (l_pdwStartAdr[l_dwAdrOffset] & l_dwMaskRegister)
      {
        l_pdwStartAdr[l_dwAdrOffset]&= (~l_dwMaskRegister);

        // event signaled !!!
        CO_TRACE(HI_ID, _T("Received Stepper Event"));

        CSingleLock l_Lock(&m_AccessLock, TRUE);
        if (m_EventMap.Lookup(l_dwLogID, l_pEvent))
        {        
          l_pEvent->CheckRegisteredExceptionState();
        }
      }
    
      l_dwLogID++;
    }
  }
  //## end CHIEventWorkerThread::CheckStepperEvents%1066028228.body
}

void CHIEventWorkerThread::CheckI2CEvent ()
{
  //## begin CHIEventWorkerThread::CheckI2CEvent%1071211735.body preserve=yes
    DWORD* l_pdwAdr = CHITReservedSharedMemory::GetI2CEventRegStartAdr();
    if (l_pdwAdr == NULL)
    { 
      ASSERT(FALSE);
    }

    DWORD l_dwLogID = CHII2CParameter::GetcdwI2CLogID();
    CHIEventRegistration* l_pEvent = NULL;
    DWORD l_dwMaskRegister = 0x1; 
    
    if (*l_pdwAdr & l_dwMaskRegister)
    {
      // clear I2C event register
      *l_pdwAdr = *l_pdwAdr & ~l_dwMaskRegister;

      // event signaled !!!
      CO_TRACE(HI_ID, _T("Received I2C Event"));

      CSingleLock l_Lock(&m_AccessLock, TRUE);
      if (m_EventMap.Lookup(l_dwLogID, l_pEvent))
      {        
        l_pEvent->CheckRegisteredI2CState();
      }
    }
    
  //## end CHIEventWorkerThread::CheckI2CEvent%1071211735.body
}

CCOSyncObject* CHIEventWorkerThread::EnableEventSignalisation ()
{
  //## begin CHIEventWorkerThread::EnableEventSignalisation%1066028226.body preserve=yes
    m_bEnableEventSignalisation = true;
	CCOSyncObject* l_pSyncObj = new CCOSyncObject();
	l_pSyncObj->SignalCompletion();
	return l_pSyncObj;
  //## end CHIEventWorkerThread::EnableEventSignalisation%1066028226.body
}

CCOSyncObject* CHIEventWorkerThread::DisableEventSignalisation ()
{
  //## begin CHIEventWorkerThread::DisableEventSignalisation%1066028227.body preserve=yes
    m_bEnableEventSignalisation = false;
	CCOSyncObject* l_pSyncObj = new CCOSyncObject();
	l_pSyncObj->SignalCompletion();
	return l_pSyncObj;
  //## end CHIEventWorkerThread::DisableEventSignalisation%1066028227.body
}

CCOSyncObjectArray* CHIEventWorkerThread::DebugGetEvents (DWORD p_dwID)
{
  //## begin CHIEventWorkerThread::DebugGetEvents%1067329236.body preserve=yes
	CHIEventRegistration*	l_pOpenEvent = NULL;
	CCOSyncObject*			l_pSyncObj = NULL;

	CSingleLock l_Lock(&m_AccessLock, TRUE);

	if (!m_EventMap.Lookup(p_dwID, l_pOpenEvent))
    {
		// wrong id
		throw new XHIExceptionError(HI_ID, IDE_HW_INTF_INVALID_OBJ_ID, _T(__FILE__), __LINE__, 0);
    }

    return l_pOpenEvent->DebugGetEvents();
  //## end CHIEventWorkerThread::DebugGetEvents%1067329236.body
}

void CHIEventWorkerThread::DebugSetEvents (DWORD p_dwID)
{
  //## begin CHIEventWorkerThread::DebugSetEvents%1067329237.body preserve=yes
	CHIEventRegistration*	l_pOpenEvent = NULL;
	CCOSyncObject*			l_pSyncObj = NULL;

	CSingleLock l_Lock(&m_AccessLock, TRUE);

	if (!m_EventMap.Lookup(p_dwID, l_pOpenEvent))
    {
		// wrong id
		throw new XHIExceptionError(HI_ID, IDE_HW_INTF_INVALID_OBJ_ID, _T(__FILE__), __LINE__, 0);
    }

    l_pOpenEvent->DebugSetEvents();
  //## end CHIEventWorkerThread::DebugSetEvents%1067329237.body
}

//## Get and Set Operations for Associations (implementation)

CCOSyncObject * CHIEventWorkerThread::GetpSyncObj ()
{
  //## begin CHIEventWorkerThread::GetpSyncObj%3FCCA24803B9.get preserve=yes
  m_pSyncObj->AddRef();
  return m_pSyncObj;
  //## end CHIEventWorkerThread::GetpSyncObj%3FCCA24803B9.get
}

DWORD CHIEventWorkerThread::GetdwHWExceptionEventNr ()
{
  //## begin CHIEventWorkerThread::GetdwHWExceptionEventNr%400D1D270280.get preserve=no
  return m_dwHWExceptionEventNr;
  //## end CHIEventWorkerThread::GetdwHWExceptionEventNr%400D1D270280.get
}

void CHIEventWorkerThread::SetdwHWExceptionEventNr (DWORD value)
{
  //## begin CHIEventWorkerThread::SetdwHWExceptionEventNr%400D1D270280.set preserve=no
  m_dwHWExceptionEventNr = value;
  //## end CHIEventWorkerThread::SetdwHWExceptionEventNr%400D1D270280.set
}

// Additional Declarations
  //## begin CHIEventWorkerThread%3E5A23B80119.declarations preserve=yes
  //## end CHIEventWorkerThread%3E5A23B80119.declarations

// Class CHIEventRegistrationConfig 




CHIEventRegistrationConfig::CHIEventRegistrationConfig (EHIOpenEventRegistration p_eRegistrationKind)
  //## begin CHIEventRegistrationConfig::CHIEventRegistrationConfig%1050387898.hasinit preserve=no
      : m_eRegistrationKind(p_eRegistrationKind), m_pSyncObj(NULL)
  //## end CHIEventRegistrationConfig::CHIEventRegistrationConfig%1050387898.hasinit
  //## begin CHIEventRegistrationConfig::CHIEventRegistrationConfig%1050387898.initialization preserve=yes
  //## end CHIEventRegistrationConfig::CHIEventRegistrationConfig%1050387898.initialization
{
  //## begin CHIEventRegistrationConfig::CHIEventRegistrationConfig%1050387898.body preserve=yes
  m_pSyncObj = new CCOSyncObject(_T("HI:Event registration"));
  //## end CHIEventRegistrationConfig::CHIEventRegistrationConfig%1050387898.body
}


CHIEventRegistrationConfig::~CHIEventRegistrationConfig()
{
  //## begin CHIEventRegistrationConfig::~CHIEventRegistrationConfig%.body preserve=yes
  m_pSyncObj->ReleaseRef();
  //## end CHIEventRegistrationConfig::~CHIEventRegistrationConfig%.body
}


//## Get and Set Operations for Class Attributes (implementation)

EHIOpenEventRegistration CHIEventRegistrationConfig::GeteRegistrationKind ()
{
  //## begin CHIEventRegistrationConfig::GeteRegistrationKind%3E9BA6D301C5.get preserve=no
  return m_eRegistrationKind;
  //## end CHIEventRegistrationConfig::GeteRegistrationKind%3E9BA6D301C5.get
}

//## Get and Set Operations for Associations (implementation)

CCOSyncObject * CHIEventRegistrationConfig::GetpSyncObj ()
{
  //## begin CHIEventRegistrationConfig::GetpSyncObj%3E9BCBD80291.get preserve=no
  return m_pSyncObj;
  //## end CHIEventRegistrationConfig::GetpSyncObj%3E9BCBD80291.get
}

// Additional Declarations
  //## begin CHIEventRegistrationConfig%3E9BA6230186.declarations preserve=yes
  //## end CHIEventRegistrationConfig%3E9BA6230186.declarations

// Class CHIDatapackageWorkerThread 


//## begin CHIDatapackageWorkerThread::pInstance%3F9FD22E0391.role preserve=no  public: static CHIDatapackageWorkerThread {1..1 -> 1..1RFHN}
CHIDatapackageWorkerThread *CHIDatapackageWorkerThread::m_pInstance = NULL;
//## end CHIDatapackageWorkerThread::pInstance%3F9FD22E0391.role






CHIDatapackageWorkerThread::CHIDatapackageWorkerThread()
  //## begin CHIDatapackageWorkerThread::CHIDatapackageWorkerThread%.hasinit preserve=no
      : m_pSyncObjDataPackage(NULL), m_pStopSyncObj(NULL)
  //## end CHIDatapackageWorkerThread::CHIDatapackageWorkerThread%.hasinit
  //## begin CHIDatapackageWorkerThread::CHIDatapackageWorkerThread%.initialization preserve=yes
  , ICOThreadWork(_T("HI Datapackage Worker Thread"))
  //## end CHIDatapackageWorkerThread::CHIDatapackageWorkerThread%.initialization
{
  //## begin CHIDatapackageWorkerThread::CHIDatapackageWorkerThread%.body preserve=yes
  //## end CHIDatapackageWorkerThread::CHIDatapackageWorkerThread%.body
}


CHIDatapackageWorkerThread::~CHIDatapackageWorkerThread()
{
  //## begin CHIDatapackageWorkerThread::~CHIDatapackageWorkerThread%.body preserve=yes
    if (m_pSyncObjDataPackage != NULL)
        m_pSyncObjDataPackage->ReleaseRef();
  //## end CHIDatapackageWorkerThread::~CHIDatapackageWorkerThread%.body
}



//## Other Operations (implementation)
int CHIDatapackageWorkerThread::ThreadMain ()
{
  //## begin CHIDatapackageWorkerThread::ThreadMain%1067437963.body preserve=yes
    try
    {
        HANDLE l_pWaitHandles[] = 
        {
            (HANDLE)m_TerminationEvent, (HANDLE)m_CommandEvent, (HANDLE)m_StopEvent
        };
        bool l_bRunning = true;
        while (l_bRunning)
        {
			bool l_bIsStopped = false;
            DWORD l_dwRes = 0;
            l_dwRes = ::WaitForMultipleObjects(3, l_pWaitHandles, false, INFINITE);
            switch(l_dwRes)
            {
                case 0:
                    // exit thread
                    l_bRunning = false;
                    break;

                case 1:
                    // keep going with mc data packages
                    m_CommandEvent.ResetEvent();
                    l_bIsStopped = !DoGetDataPackage();
                    break;

                case 2:
					l_bIsStopped = true;
                    break;

                default:                    
                    ASSERT(FALSE);
                    break;
            }

			if (l_bIsStopped)
			{
                CSingleLock l_Lock(&m_AccessLock, true);
                // stop transfer mc data packages
                m_StopEvent.ResetEvent();
                if (m_pSyncObjDataPackage)
                {                            
                    m_pSyncObjDataPackage->ReleaseRef();
                    m_pSyncObjDataPackage = NULL;
                }

                ASSERT(m_pStopSyncObj != NULL);
                m_pStopSyncObj->SignalCompletion();
                m_pStopSyncObj->ReleaseRef();
                m_pStopSyncObj = NULL;
			}
        }
    }
    catch(...)
    {
        ASSERT(FALSE);
    }
    return 0;
  //## end CHIDatapackageWorkerThread::ThreadMain%1067437963.body
}

void CHIDatapackageWorkerThread::CreateInstance (const bool p_bHWPresent)
{
  //## begin CHIDatapackageWorkerThread::CreateInstance%1067437964.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CHIDatapackageWorkerThread();
    CCOSyncObjectPtr l_SyncObj = m_pInstance->Start();
	l_SyncObj->Synchronize(2000);
  //## end CHIDatapackageWorkerThread::CreateInstance%1067437964.body
}

void CHIDatapackageWorkerThread::DeleteInstance ()
{
  //## begin CHIDatapackageWorkerThread::DeleteInstance%1067437965.body preserve=yes
    if (m_pInstance)
        m_pInstance->TerminateThread();

    m_pInstance = NULL;
  //## end CHIDatapackageWorkerThread::DeleteInstance%1067437965.body
}

CHIDatapackageWorkerThread* CHIDatapackageWorkerThread::GetInstance ()
{
  //## begin CHIDatapackageWorkerThread::GetInstance%1067437966.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CHIDatapackageWorkerThread::GetInstance%1067437966.body
}

bool CHIDatapackageWorkerThread::DoGetDataPackage ()
{
  //## begin CHIDatapackageWorkerThread::DoGetDataPackage%1067437967.body preserve=yes

	BYTE* l_pLaserData = NULL;
	BYTE* l_pDetectorData = NULL;
	
	try
	{
		DWORD l_dwAvailableDataSize;
		do
		{ 
			l_dwAvailableDataSize = CHITReservedSharedMemory::GetIFMDataSize() * sizeof(DWORD);
			if (l_dwAvailableDataSize < CHIMCParameter::GetdwMinTransferDataSize())
			{
				if (::WaitForSingleObject((HANDLE)m_StopEvent, 200) == WAIT_OBJECT_0)
				{
					return false;
				}
			}
		} while (l_dwAvailableDataSize < CHIMCParameter::GetdwMinTransferDataSize());

		DWORD l_dwPackageSize = min(CHIMCParameter::GetdwMaxTransferDataSize(), l_dwAvailableDataSize);

		// allocate buffers
		l_pLaserData = new BYTE[l_dwPackageSize];
		l_pDetectorData = new BYTE[l_dwPackageSize];

		// copy laser data
		DWORD l_dwNewReadOffset = CopyStreamData(
			CHITReservedSharedMemory::GetLaserBufferBaseAdr(),
			CHITReservedSharedMemory::GetLaserDataVirtualStartAdr(),
			CHITReservedSharedMemory::GetdwLaserTotalBufferSize(),
			l_pLaserData,
			l_dwPackageSize,
			true);
		CHITReservedSharedMemory::SetLaserDataVirtualStartAdrOffset(CHITReservedSharedMemory::GetLaserDataVirtualStartAdrOffset() + l_dwNewReadOffset);

		// copy detector data
		l_dwNewReadOffset = CopyStreamData(
			CHITReservedSharedMemory::GetIFMBufferBaseAdr(),
			CHITReservedSharedMemory::GetIFMDataVirtualStartAdr(),
			CHITReservedSharedMemory::GetdwIFMTotalBufferSize(),
			l_pDetectorData,
			l_dwPackageSize,
			false);
		CHITReservedSharedMemory::SetIFMDataVirtualStartAdrOffset(CHITReservedSharedMemory::GetIFMDataVirtualStartAdrOffset() + l_dwNewReadOffset);

		// move write pointers
		CHITReservedSharedMemory::DecIFMDataSize(l_dwPackageSize / sizeof(DWORD));
		CHITReservedSharedMemory::DecLaserDataSize(l_dwPackageSize / sizeof(DWORD));

		// signal result
		CSingleLock l_Lock(&m_AccessLock, TRUE);
		
		ASSERT(m_pSyncObjDataPackage != NULL);
		m_pSyncObjDataPackage->SetValue(new CPIMeasurementChannelDataPackage(
			CHIMCParameter::GetdwCycleID(),
			(UINT)l_dwPackageSize, l_pLaserData, l_pDetectorData));
		m_pSyncObjDataPackage->SignalCompletion();
		
		m_pSyncObjDataPackage->ReleaseRef();
		m_pSyncObjDataPackage = NULL;


		return true;
	}
	catch(XCOExceptionError* p_pException)
	{
		delete [] l_pLaserData;
		delete [] l_pDetectorData;

		if (m_pSyncObjDataPackage != NULL)
		{
			m_pSyncObjDataPackage->AttachException(p_pException);
			m_pSyncObjDataPackage->ReleaseRef();
			m_pSyncObjDataPackage = NULL;
		}
		
		return true;
	}
  //## end CHIDatapackageWorkerThread::DoGetDataPackage%1067437967.body
}

CPISyncObjDataPackage* CHIDatapackageWorkerThread::GetDataPackage ()
{
  //## begin CHIDatapackageWorkerThread::GetDataPackage%1083091762.body preserve=yes
    CSingleLock l_Lock(&m_AccessLock, true);

    ASSERT(m_pSyncObjDataPackage == NULL);
    m_pSyncObjDataPackage = new CPISyncObjDataPackage(NULL);
    m_pSyncObjDataPackage->AddRef();
    m_CommandEvent.SetEvent();

    return m_pSyncObjDataPackage;
  //## end CHIDatapackageWorkerThread::GetDataPackage%1083091762.body
}

CCOSyncObject* CHIDatapackageWorkerThread::Stop ()
{
  //## begin CHIDatapackageWorkerThread::Stop%1083231111.body preserve=yes
  CCOSyncObject* l_pSyncObj = NULL;
  CSingleLock l_Lock(&m_AccessLock, true);
  if (m_pSyncObjDataPackage)
  {
    m_pStopSyncObj = new CCOSyncObject();
    l_pSyncObj = m_pStopSyncObj;
    l_pSyncObj->AddRef();
    m_StopEvent.SetEvent();
  }
  else
  {
    l_pSyncObj = new CCOSyncObject();
    l_pSyncObj->SignalCompletion();
  }
  return l_pSyncObj;
  //## end CHIDatapackageWorkerThread::Stop%1083231111.body
}

DWORD CHIDatapackageWorkerThread::CopyStreamData (const DWORD* p_pBufferBaseAddr, const DWORD* p_pCurrentReadPtr, const DWORD p_dwBufferLength, BYTE* p_pStreamDataBuffer, const DWORD p_dwBytesToCopy, const bool p_bIsLaser)
{
  //## begin CHIDatapackageWorkerThread::CopyStreamData%1179822604.body preserve=yes
	DWORD l_dwAvailableDwords = p_dwBufferLength - (p_pCurrentReadPtr - p_pBufferBaseAddr);
	
	if (l_dwAvailableDwords >= p_dwBytesToCopy / sizeof(DWORD))
	{
		CopyMemory(p_pStreamDataBuffer, p_pCurrentReadPtr, p_dwBytesToCopy);

		return p_dwBytesToCopy / sizeof(DWORD);
	}
	else
	{
		CopyMemory(p_pStreamDataBuffer, p_pCurrentReadPtr, l_dwAvailableDwords * sizeof(DWORD));

		DWORD* l_pRewindedReadPtr = NULL;
		if (p_bIsLaser)
		{
			CHITReservedSharedMemory::SetLaserDataVirtualStartAdrOffset(CHITReservedSharedMemory::GetcdwFirstDataAdr());
			l_pRewindedReadPtr = CHITReservedSharedMemory::GetLaserDataVirtualStartAdr();
		}
		else
		{
			CHITReservedSharedMemory::SetIFMDataVirtualStartAdrOffset(CHITReservedSharedMemory::GetcdwFirstDataAdr());
			l_pRewindedReadPtr = CHITReservedSharedMemory::GetIFMDataVirtualStartAdr();
		}

		CopyMemory(p_pStreamDataBuffer + l_dwAvailableDwords * sizeof(DWORD), l_pRewindedReadPtr, p_dwBytesToCopy - (l_dwAvailableDwords * sizeof(DWORD)));

		return p_dwBytesToCopy / sizeof(DWORD) - l_dwAvailableDwords;
	}
  //## end CHIDatapackageWorkerThread::CopyStreamData%1179822604.body
}

// Additional Declarations
  //## begin CHIDatapackageWorkerThread%3F9FD1000286.declarations preserve=yes
  //## end CHIDatapackageWorkerThread%3F9FD1000286.declarations

// Class CHII2CWorkerThread 

//## begin CHII2CWorkerThread::pInstance%3E2298500162.role preserve=no  public: static CHII2CWorkerThread {1..1 -> 1..1RFHN}
CHII2CWorkerThread *CHII2CWorkerThread::m_pInstance;
//## end CHII2CWorkerThread::pInstance%3E2298500162.role





CHII2CWorkerThread::CHII2CWorkerThread (const CString& p_sName, const UINT p_uiStackSize)
  //## begin CHII2CWorkerThread::CHII2CWorkerThread%1042447556.hasinit preserve=no
      : m_QueueEvent(NULL)
  //## end CHII2CWorkerThread::CHII2CWorkerThread%1042447556.hasinit
  //## begin CHII2CWorkerThread::CHII2CWorkerThread%1042447556.initialization preserve=yes
  ,ICOThreadWork(p_sName, p_uiStackSize)
  //## end CHII2CWorkerThread::CHII2CWorkerThread%1042447556.initialization
{
  //## begin CHII2CWorkerThread::CHII2CWorkerThread%1042447556.body preserve=yes
  //## end CHII2CWorkerThread::CHII2CWorkerThread%1042447556.body
}


CHII2CWorkerThread::~CHII2CWorkerThread()
{
  //## begin CHII2CWorkerThread::~CHII2CWorkerThread%.body preserve=yes
  //## end CHII2CWorkerThread::~CHII2CWorkerThread%.body
}



//## Other Operations (implementation)
int CHII2CWorkerThread::ThreadMain ()
{
  //## begin CHII2CWorkerThread::ThreadMain%1042447541.body preserve=yes
  bool l_bRetVal = false;
  bool  l_bExitThread = false;

  while (!l_bExitThread)
  {
    if (DoIdle())
    { // exit thread
      l_bExitThread = true;
    }
    else
    { // execute command
      l_bRetVal = ExecuteCommand();
      ASSERT(l_bRetVal);
    } // end if
  } // end while
  
  return l_bRetVal;
  //## end CHII2CWorkerThread::ThreadMain%1042447541.body
}

void CHII2CWorkerThread::CreateInstance ()
{
  //## begin CHII2CWorkerThread::CreateInstance%1042447550.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CHII2CWorkerThread(_T("EBHII2CThread"));
  CCOSyncObjectPtr l_SyncObj = m_pInstance->Start();
	l_SyncObj->Synchronize(2000);
  //## end CHII2CWorkerThread::CreateInstance%1042447550.body
}

void CHII2CWorkerThread::DeleteInstance ()
{
  //## begin CHII2CWorkerThread::DeleteInstance%1042447551.body preserve=yes
    if (m_pInstance)
    {
      m_pInstance->TerminateThread();
    }
    m_pInstance = NULL;
  //## end CHII2CWorkerThread::DeleteInstance%1042447551.body
}

CHII2CWorkerThread* CHII2CWorkerThread::GetInstance ()
{
  //## begin CHII2CWorkerThread::GetInstance%1042447552.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CHII2CWorkerThread::GetInstance%1042447552.body
}

CPISyncObjI2CDataStream* CHII2CWorkerThread::AddCommand (CHII2CCommand* p_pCommand)
{
  //## begin CHII2CWorkerThread::AddCommand%1042447553.body preserve=yes
  p_pCommand->AddRef();
  p_pCommand->CreateSyncObjects();
  CSingleLock l_Lock(&m_AccessLock, TRUE);
  
  m_QueueCommand.AddTail(p_pCommand);
  m_QueueEvent.SetEvent();

  return p_pCommand->GetpSyncObj();
  //## end CHII2CWorkerThread::AddCommand%1042447553.body
}

bool CHII2CWorkerThread::DoIdle ()
{
  //## begin CHII2CWorkerThread::DoIdle%1042447554.body preserve=yes
  DWORD l_dwRes = 0;
  bool l_bRetVal = false;

  // thread events
  CArray<CSyncObject*, CEvent*> SyncArray;
  SyncArray.Add(&m_TerminationEvent);
  SyncArray.Add(&m_QueueEvent);       
  
 	// set thread sleeping
	CMultiLock l_Lock((CSyncObject**)SyncArray.GetData(), SyncArray.GetSize());
  l_dwRes = l_Lock.Lock(INFINITE, FALSE);

  
  if (l_dwRes == WAIT_OBJECT_0)
	{
    // termination event
    CO_TRACE(HI_ID, _T("EBHI - Termination Event for EBHII2CWorkerThread"));
    l_bRetVal = true;
  }
  else if (l_dwRes == WAIT_OBJECT_0+1)
  {
		// Queue Event
    //CO_TRACE(HI_ID, _T("EBHI - Queue Event for EBHII2CWorkerThread"));
    l_bRetVal = false;
  }
  else
  {
    ASSERT(false); //should never happen !!!
  } // end if

  return l_bRetVal;
  //## end CHII2CWorkerThread::DoIdle%1042447554.body
}

bool CHII2CWorkerThread::ExecuteCommand ()
{
  //## begin CHII2CWorkerThread::ExecuteCommand%1042447555.body preserve=yes
  bool l_bRetVal = true;
  bool l_bKeepGoing = true;
  do
  {
    CHII2CCommand* l_Cmd = NULL;
    {
      CSingleLock l_Lock(&m_AccessLock, TRUE);
      if (m_QueueCommand.GetCount() > 0)
      {
        // get command from thread queue
        l_Cmd = m_QueueCommand.RemoveHead();
        m_QueueEvent.ResetEvent();
      }
      else
        l_bKeepGoing = false;
    }
    
    if (l_Cmd)
    {
      // execute command
      l_Cmd->Execute();
      l_Cmd->ReleaseRef();
    }
  } while (l_bKeepGoing);

  return l_bRetVal;
  //## end CHII2CWorkerThread::ExecuteCommand%1042447555.body
}

// Additional Declarations
  //## begin CHII2CWorkerThread%3E227BB3027B.declarations preserve=yes
  //## end CHII2CWorkerThread%3E227BB3027B.declarations

// Class CHIEventRegistration 




CHIEventRegistration::CHIEventRegistration()
  //## begin CHIEventRegistration::CHIEventRegistration%.hasinit preserve=no
  //## end CHIEventRegistration::CHIEventRegistration%.hasinit
  //## begin CHIEventRegistration::CHIEventRegistration%.initialization preserve=yes
  //## end CHIEventRegistration::CHIEventRegistration%.initialization
{
  //## begin CHIEventRegistration::CHIEventRegistration%.body preserve=yes
  //## end CHIEventRegistration::CHIEventRegistration%.body
}


CHIEventRegistration::~CHIEventRegistration()
{
  //## begin CHIEventRegistration::~CHIEventRegistration%.body preserve=yes
	for (POSITION l_Pos=m_EventRegConfigList.GetHeadPosition(); l_Pos!=NULL;)
	{
		delete m_EventRegConfigList.GetNext(l_Pos);
	}
	m_EventRegConfigList.RemoveAll();
  //## end CHIEventRegistration::~CHIEventRegistration%.body
}



//## Other Operations (implementation)
CCOSyncObject* CHIEventRegistration::Add (EHIOpenEventRegistration p_eEventType)
{
  //## begin CHIEventRegistration::Add%1067281894.body preserve=yes
  CSingleLock l_Lock(&m_AccessLock, TRUE);
  CHIEventRegistrationConfig* l_pCfg = new CHIEventRegistrationConfig(p_eEventType);
  m_EventRegConfigList.AddTail(l_pCfg);

  return l_pCfg->GetpSyncObj();
  //## end CHIEventRegistration::Add%1067281894.body
}

bool CHIEventRegistration::Remove (CCOSyncObject* p_pSyncObj)
{
  //## begin CHIEventRegistration::Remove%1067281895.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, TRUE);

	bool l_bItemFound = false;
	for (POSITION l_Pos=m_EventRegConfigList.GetHeadPosition(); l_Pos!=NULL;)
	{
		POSITION l_CurPos = l_Pos;
		CHIEventRegistrationConfig* l_pCfg = m_EventRegConfigList.GetNext(l_Pos);
		if (l_pCfg->GetpSyncObj() == p_pSyncObj)
		{
			// item has been found
			delete l_pCfg;
			m_EventRegConfigList.RemoveAt(l_CurPos);
			l_bItemFound = true;
			break;
		}
	}

	if (!l_bItemFound)
	{
		// wrong id
		throw new XHIExceptionError(HI_ID, IDE_HW_INTF_INVALID_OBJ_ID, _T(__FILE__), __LINE__, 0);
	}

	return m_EventRegConfigList.GetCount() == 0;
  //## end CHIEventRegistration::Remove%1067281895.body
}

void CHIEventRegistration::CheckRegisteredWCState (XHIHardwareExceptionError* p_pXException)
{
  //## begin CHIEventRegistration::CheckRegisteredWCState%1053584949.body preserve=yes
  CSingleLock l_Lock(&m_AccessLock, TRUE);
  for (POSITION l_Pos = m_EventRegConfigList.GetHeadPosition(); l_Pos!=NULL;)
  {
    CHIEventRegistrationConfig * l_pEventRegConfig = m_EventRegConfigList.GetNext(l_Pos);
    if (p_pXException == NULL)
    {
      l_pEventRegConfig->GetpSyncObj()->SignalCompletion();
    }
    else
    {
      l_pEventRegConfig->GetpSyncObj()->AttachException(p_pXException);
    }
  }
  //## end CHIEventRegistration::CheckRegisteredWCState%1053584949.body
}

void CHIEventRegistration::CheckRegisteredExceptionState (XHIExceptionError* p_pXException)
{
  //## begin CHIEventRegistration::CheckRegisteredExceptionState%1054101546.body preserve=yes
  CSingleLock l_Lock(&m_AccessLock, TRUE);
  for (POSITION l_Pos = m_EventRegConfigList.GetHeadPosition(); l_Pos!=NULL;)
  {
    CHIEventRegistrationConfig * l_pEventRegConfig = m_EventRegConfigList.GetNext(l_Pos);
    if (p_pXException == NULL)
    {
      l_pEventRegConfig->GetpSyncObj()->SignalCompletion();
    }
    else
    {
      l_pEventRegConfig->GetpSyncObj()->AttachException(p_pXException);
    }
  }
  //## end CHIEventRegistration::CheckRegisteredExceptionState%1054101546.body
}

void CHIEventRegistration::CheckRegisteredHWState (EHIOpenEventRegistration p_eStateChange, XHIHardwareExceptionError* p_pXException)
{
  //## begin CHIEventRegistration::CheckRegisteredHWState%1052117442.body preserve=yes
  CSingleLock l_Lock(&m_AccessLock, TRUE);
  for (POSITION l_Pos = m_EventRegConfigList.GetHeadPosition(); l_Pos!=NULL;)
  {
    CHIEventRegistrationConfig * l_pEventRegConfig = m_EventRegConfigList.GetNext(l_Pos);
    if (p_pXException == NULL)
    {
      if (l_pEventRegConfig->GeteRegistrationKind() == eHIUndefined ||
          p_eStateChange == l_pEventRegConfig->GeteRegistrationKind())
      {
        CO_TRACE1(HI_ID,_T("SignalCompletion - actual defined state %d"),p_eStateChange);
        l_pEventRegConfig->GetpSyncObj()->SignalCompletion();
      }
    }
    else
    {
      l_pEventRegConfig->GetpSyncObj()->AttachException(p_pXException);
    }
  }
  
  //## end CHIEventRegistration::CheckRegisteredHWState%1052117442.body
}

void CHIEventRegistration::CheckRegisteredI2CState ()
{
  //## begin CHIEventRegistration::CheckRegisteredI2CState%1071211739.body preserve=yes
  CSingleLock l_Lock(&m_AccessLock, TRUE);
  for (POSITION l_Pos = m_EventRegConfigList.GetHeadPosition(); l_Pos!=NULL;)
  {
    CHIEventRegistrationConfig * l_pEventRegConfig = m_EventRegConfigList.GetNext(l_Pos);
    l_pEventRegConfig->GetpSyncObj()->SignalCompletion();
  }
  //## end CHIEventRegistration::CheckRegisteredI2CState%1071211739.body
}

void CHIEventRegistration::CheckRegisteredHWWarnErrState ()
{
  //## begin CHIEventRegistration::CheckRegisteredHWWarnErrState%1096438040.body preserve=yes
  CSingleLock l_Lock(&m_AccessLock, TRUE);
  for (POSITION l_Pos = m_EventRegConfigList.GetHeadPosition(); l_Pos!=NULL;)
  {
    CHIEventRegistrationConfig * l_pEventRegConfig = m_EventRegConfigList.GetNext(l_Pos);
    l_pEventRegConfig->GetpSyncObj()->SignalCompletion();
  }
  //## end CHIEventRegistration::CheckRegisteredHWWarnErrState%1096438040.body
}

CCOSyncObjectArray* CHIEventRegistration::DebugGetEvents ()
{
  //## begin CHIEventRegistration::DebugGetEvents%1067329238.body preserve=yes
    CCOSyncObjectArray* l_pSyncArray = new CCOSyncObjectArray();
	for (POSITION l_Pos=m_EventRegConfigList.GetHeadPosition(); l_Pos!=NULL;)
	{
		l_pSyncArray->Add(m_EventRegConfigList.GetNext(l_Pos)->GetpSyncObj(), true);
	}

    return l_pSyncArray;
  //## end CHIEventRegistration::DebugGetEvents%1067329238.body
}

void CHIEventRegistration::DebugSetEvents ()
{
  //## begin CHIEventRegistration::DebugSetEvents%1067329239.body preserve=yes
	for (POSITION l_Pos=m_EventRegConfigList.GetHeadPosition(); l_Pos!=NULL;)
	{
		m_EventRegConfigList.GetNext(l_Pos)->GetpSyncObj()->SignalCompletion();
	}
  //## end CHIEventRegistration::DebugSetEvents%1067329239.body
}

// Additional Declarations
  //## begin CHIEventRegistration%3E9ABC11005D.declarations preserve=yes
  //## end CHIEventRegistration%3E9ABC11005D.declarations

//## begin module%3E227AEB01CF.epilog preserve=yes
//## end module%3E227AEB01CF.epilog
