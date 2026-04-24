//## begin module%3DA3CC6B00C0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA3CC6B00C0.cm

//## begin module%3DA3CC6B00C0.cp preserve=no
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
//## end module%3DA3CC6B00C0.cp

//## Module: EBETthrd%3DA3CC6B00C0; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETthrd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA3CC6B00C0.additionalIncludes preserve=no
//## end module%3DA3CC6B00C0.additionalIncludes

//## begin module%3DA3CC6B00C0.includes preserve=yes
//## end module%3DA3CC6B00C0.includes

// EBETthrd
#include "EBETthrd.h"
// EBETflog
#include "EBETflog.h"


//## begin module%3DA3CC6B00C0.declarations preserve=no
//## end module%3DA3CC6B00C0.declarations

//## begin module%3DA3CC6B00C0.additionalDeclarations preserve=yes
//## end module%3DA3CC6B00C0.additionalDeclarations


// Class CETThread 





CETThread::CETThread (const CString& p_sName)
  //## begin CETThread::CETThread%1034142080.hasinit preserve=no
      : m_dwThreadID(0), m_sName(p_sName), m_hTerminationEvent(NULL), m_hThread(NULL)
  //## end CETThread::CETThread%1034142080.hasinit
  //## begin CETThread::CETThread%1034142080.initialization preserve=yes
  //## end CETThread::CETThread%1034142080.initialization
{
  //## begin CETThread::CETThread%1034142080.body preserve=yes
    m_hTerminationEvent = ::CreateEvent(NULL, true, false, NULL);
  //## end CETThread::CETThread%1034142080.body
}


CETThread::~CETThread()
{
  //## begin CETThread::~CETThread%.body preserve=yes
    if (m_hTerminationEvent)
        ::CloseHandle(m_hTerminationEvent);
    m_hTerminationEvent = NULL;

    if (m_hThread)
        ::CloseHandle(m_hThread);
    m_hThread = NULL;
  //## end CETThread::~CETThread%.body
}


//## Other Operations (implementation)
void CETThread::Start ()
{
  //## begin CETThread::Start%1034142083.body preserve=yes

    m_hThread = ::CreateThread(NULL, 16384, (LPTHREAD_START_ROUTINE)ThreadMain_, this, 0, &m_dwThreadID);

	if (m_hThread==NULL)
	{
		CString l_sStr;
		l_sStr.Format(_T("Thread '%s' not started -------------------"), (LPCTSTR)m_sName);
		CO_TRACE(_T("ET"), (LPCTSTR)l_sStr);
	}

  //## end CETThread::Start%1034142083.body
}

void CETThread::Terminate ()
{
  //## begin CETThread::Terminate%1034142086.body preserve=yes
	HANDLE l_hThread = m_hThread;

	::SetEvent(m_hTerminationEvent);
	if (::WaitForSingleObject(l_hThread, 5000) == WAIT_TIMEOUT)
		CETFileLogger::GetInstance()->AddMessage(_T("Terminating thread timed out, handle=%d"), (int)l_hThread);
  //## end CETThread::Terminate%1034142086.body
}

DWORD CETThread::ThreadMain_ (LPVOID p_Parameter)
{
  //## begin CETThread::ThreadMain_%1034142082.body preserve=yes
	CString l_sStr;
	l_sStr.Format(_T("Thread '%s, ID:%x' started"), (LPCTSTR)((CETThread*)p_Parameter)->m_sName,
        ((CETThread*)p_Parameter)->m_dwThreadID);
	CO_TRACE(_T("ET"), (LPCTSTR)l_sStr);

	DWORD l_dwRes = ((CETThread*)p_Parameter)->ThreadMain();
	CO_TRACE1(_T("ET"), _T("Thread '%s' terminated"), (LPCTSTR)((CETThread*)p_Parameter)->m_sName);
	CETFileLogger::GetInstance()->AddMessage(_T("Thread terminated, handle=%d"), (int)((CETThread*)p_Parameter)->m_hThread);

	// commit suicide
	delete ((CETThread*)p_Parameter);

	return l_dwRes;
  //## end CETThread::ThreadMain_%1034142082.body
}

//## Get and Set Operations for Class Attributes (implementation)

CString CETThread::GetsName ()
{
  //## begin CETThread::GetsName%3DA3CE5E02E3.get preserve=no
  return m_sName;
  //## end CETThread::GetsName%3DA3CE5E02E3.get
}

// Additional Declarations
  //## begin CETThread%3DA3CC7902A5.declarations preserve=yes
  //## end CETThread%3DA3CC7902A5.declarations

//## begin module%3DA3CC6B00C0.epilog preserve=yes
//## end module%3DA3CC6B00C0.epilog
