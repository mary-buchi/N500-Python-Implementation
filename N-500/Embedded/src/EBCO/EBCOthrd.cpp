//## begin module%3B86D1DF0391.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B86D1DF0391.cm

//## begin module%3B86D1DF0391.cp preserve=no
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
//## end module%3B86D1DF0391.cp

//## Module: EBCOthrd%3B86D1DF0391; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOthrd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3B86D1DF0391.additionalIncludes preserve=no
//## end module%3B86D1DF0391.additionalIncludes

//## begin module%3B86D1DF0391.includes preserve=yes
// #include <eh.h>
//## end module%3B86D1DF0391.includes

// EBCOidnt
#include "EBCOidnt.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBCOsync
#include "EBCOsync.h"
// EBCOthrd
#include "EBCOthrd.h"


//## begin module%3B86D1DF0391.declarations preserve=no
//## end module%3B86D1DF0391.declarations

//## begin module%3B86D1DF0391.additionalDeclarations preserve=yes
//## end module%3B86D1DF0391.additionalDeclarations


// Class ICOThreadWork 

ICOThreadWork::ICOThreadWork (const CString& p_sName, const INT p_iPriority, const UINT p_uiStackSize)
  //## begin ICOThreadWork::ICOThreadWork%998945407.hasinit preserve=no
  //## end ICOThreadWork::ICOThreadWork%998945407.hasinit
  //## begin ICOThreadWork::ICOThreadWork%998945407.initialization preserve=yes
  : ICOThread(p_sName, p_iPriority, p_uiStackSize)
  //## end ICOThreadWork::ICOThreadWork%998945407.initialization
{
  //## begin ICOThreadWork::ICOThreadWork%998945407.body preserve=yes
  //## end ICOThreadWork::ICOThreadWork%998945407.body
}


ICOThreadWork::~ICOThreadWork()
{
  //## begin ICOThreadWork::~ICOThreadWork%.body preserve=yes
	if (m_pStartupSyncObj)
		m_pStartupSyncObj->ReleaseRef();
	m_pStartupSyncObj = NULL;
  //## end ICOThreadWork::~ICOThreadWork%.body
}



//## Other Operations (implementation)
BOOL ICOThreadWork::InitInstance ()
{
  //## begin ICOThreadWork::InitInstance%998945410.body preserve=yes
    // register native exception translater
	// TODO:
    // _set_se_translator(TranslateException);

	return TRUE;
  //## end ICOThreadWork::InitInstance%998945410.body
}

int ICOThreadWork::Run ()
{
  //## begin ICOThreadWork::Run%998945409.body preserve=yes
	int l_iRes;

	// thread started
	CString l_sStr;
	l_sStr.Format(_T("Thread 0x%03x %s started"), m_nThreadID, (LPCTSTR)m_sName);
	CO_TRACE(CO_ID, (LPCTSTR)l_sStr);

	// mark thread as running
	m_bRunning = true;

	// do start handshake
	ASSERT(m_pStartupSyncObj != NULL);
	m_pStartupSyncObj->SignalCompletion();
	m_pStartupSyncObj->ReleaseRef();
	m_pStartupSyncObj = NULL;

#ifdef _WIN32_WCE
    ::CeSetThreadPriority(m_hThread, m_iPriority);
#else
    SetThreadPriority(m_iPriority);
#endif

	try
	{
		l_iRes = ThreadMain();

		// thread terminated
		l_sStr.Format(_T("Thread 0x%03x %s terminated"), m_nThreadID, (LPCTSTR)m_sName);
		CO_TRACE(CO_ID, (LPCTSTR)l_sStr);

		m_bRunning = false;
	}
	catch(...)
	{
		// thread terminated with exception
		l_sStr.Format(_T("Thread 0x%03x %s terminated with exception"), m_nThreadID, (LPCTSTR)m_sName);
		CO_TRACE(CO_ID, (LPCTSTR)l_sStr);

		m_bRunning = false;
	}

	return l_iRes;
  //## end ICOThreadWork::Run%998945409.body
}

// Additional Declarations
  //## begin ICOThreadWork%3B86D25701E5.declarations preserve=yes
  //## end ICOThreadWork%3B86D25701E5.declarations

// Class ICOThread 







ICOThread::ICOThread (const CString& p_sName, const INT p_iPriority, const UINT p_uiStackSize)
  //## begin ICOThread::ICOThread%998945406.hasinit preserve=no
      : m_bRunning(false), m_iPriority(p_iPriority), m_sName(p_sName), m_uiStackSize(p_uiStackSize), m_pStartupSyncObj(NULL)
  //## end ICOThread::ICOThread%998945406.hasinit
  //## begin ICOThread::ICOThread%998945406.initialization preserve=yes
  //## end ICOThread::ICOThread%998945406.initialization
{
  //## begin ICOThread::ICOThread%998945406.body preserve=yes
	m_bAutoDelete = TRUE;
  //## end ICOThread::ICOThread%998945406.body
}


ICOThread::~ICOThread()
{
  //## begin ICOThread::~ICOThread%.body preserve=yes
  //## end ICOThread::~ICOThread%.body
}



//## Other Operations (implementation)
void ICOThread::TranslateException (unsigned int p_uiExceptionCode, EXCEPTION_POINTERS*  p_pExceptionInfo)
{
  //## begin ICOThread::TranslateException%1001268500.body preserve=yes
   CString sMessage;
   
   DWORD dwAddress = reinterpret_cast<DWORD> (p_pExceptionInfo->ExceptionRecord->ExceptionAddress);

   switch (p_uiExceptionCode)
   {
      case EXCEPTION_ACCESS_VIOLATION:
      {
         DWORD dwInfoLen = p_pExceptionInfo->ExceptionRecord->NumberParameters;
         if (dwInfoLen >= 2)
         {
            CString sRead;
            if (p_pExceptionInfo->ExceptionRecord->ExceptionInformation[0] == 0)
            {
               sRead = _T ("Reading");
            }
            else
            {
               sRead = _T ("Writing");
            }

            DWORD dwAccessedAddress = p_pExceptionInfo->ExceptionRecord->ExceptionInformation[1];

            sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X! (%4!s! at Address 0x%5!X!)"), 
                                    p_uiExceptionCode, 
                                    _T ("Access Violation"),
                                    dwAddress,
                                    sRead,
                                    dwAccessedAddress
                                   );
         }
         else
         {
            sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                    p_uiExceptionCode, 
                                    _T ("Access Violation"),
                                    dwAddress
                                   );
         }
         break;
      }

      case EXCEPTION_DATATYPE_MISALIGNMENT:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Datatype Misalignment"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_BREAKPOINT:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Breakpoint"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_SINGLE_STEP:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Single Step"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Array Bound Exceeded"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_FLT_DENORMAL_OPERAND:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Floating Point Denormal Operand"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_FLT_DIVIDE_BY_ZERO:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Floating Point Divide By Zero"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_FLT_INEXACT_RESULT:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Floating Point Inexact Result"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_FLT_INVALID_OPERATION:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Floating Point Invalid Operation"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_FLT_OVERFLOW:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!   at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Floating Point Overflow"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_FLT_STACK_CHECK:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Floating Point Stack Check"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_FLT_UNDERFLOW:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Floating Point Underflow"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_INT_DIVIDE_BY_ZERO:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Integer Divide By Zero"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_INT_OVERFLOW:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Integer Overflow"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_STACK_OVERFLOW:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Stack Overflow"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_PRIV_INSTRUCTION:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Privileged Instruction"),
                                 dwAddress
                                );
         break;
      }
      case EXCEPTION_IN_PAGE_ERROR:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("In Page Error"),
                                 dwAddress
                                );
         break;
      }
      // Debug Exceptions
      case DBG_TERMINATE_THREAD:
       {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Terminate Thread"),
                                 dwAddress
                                );
         break;
      }
      case DBG_TERMINATE_PROCESS:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Terminate Process"),
                                 dwAddress
                                );
         break;
      }
      case DBG_CONTROL_C:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Control+C"),
                                 dwAddress
                                );
         break;
      }
      case DBG_CONTROL_BREAK:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Control+Break"),
                                 dwAddress
                                );
         break;
      }
      case RPC_S_UNKNOWN_IF:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("RPC Unknown Interface"),
                                 dwAddress
                                );
         break;
      }
      case RPC_S_SERVER_UNAVAILABLE:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("RPC Server Unavailable"),
                                 dwAddress
                                );
         break;
      }
      default:
      {
         sMessage.FormatMessage (_T ("Win32 Exception: 0x%1!X!: %2!s!  at Address 0x%3!X!"), 
                                 p_uiExceptionCode, 
                                 _T ("Unknown"),
                                 dwAddress
                                );
         break;
      } 
   } // end switch

   throw new XCOExceptionErrorNative(CO_ID, IDE_CORE_NATIVE_EXCEPTION, __FILE__, __LINE__, sMessage);
  //## end ICOThread::TranslateException%1001268500.body
}

void ICOThread::TerminateThread ()
{
  //## begin ICOThread::TerminateThread%999108315.body preserve=yes
	if (m_bRunning)
	{
		HANDLE l_hThread = m_hThread;

		// signal termination event
		m_TerminationEvent.SetEvent();
	        
		if( GetCurrentThreadId() != m_nThreadID )
		{
			// Different thread is destroying, therefore wait until finished.
			DWORD dwResult = ::WaitForSingleObject( l_hThread, 1500 );
			if (dwResult == WAIT_TIMEOUT)
			{
				// retry
				dwResult = ::WaitForSingleObject( l_hThread, 5000 );
				if (dwResult == WAIT_TIMEOUT)
				{
					CO_TRACE1(CO_ID, _T("Thread 0x%0x not responding -> killing"), l_hThread);
					::TerminateThread(l_hThread, 0);
				}
			}
		}
		else
		{
			// This is the worker thread commiting suicide.
			m_bAutoDelete = TRUE;  
		}
	}
  //## end ICOThread::TerminateThread%999108315.body
}

CCOSyncObject* ICOThread::Start ()
{
  //## begin ICOThread::Start%1037192862.body preserve=yes
	m_pStartupSyncObj = new CCOSyncObject();
	m_pStartupSyncObj->AddRef();
    CCOSyncObject* l_pSyncObj = m_pStartupSyncObj;

    CreateThread(0, m_uiStackSize);

	return l_pSyncObj;
  //## end ICOThread::Start%1037192862.body
}

// Additional Declarations
  //## begin ICOThread%3B8AB1B0035A.declarations preserve=yes
  //## end ICOThread%3B8AB1B0035A.declarations

//## begin module%3B86D1DF0391.epilog preserve=yes
//## end module%3B86D1DF0391.epilog
