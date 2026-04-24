//## begin module%3F6CA813017A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F6CA813017A.cm

//## begin module%3F6CA813017A.cp preserve=no
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
//## end module%3F6CA813017A.cp

//## Module: EBETsmon%3F6CA813017A; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETsmon.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F6CA813017A.additionalIncludes preserve=no
//## end module%3F6CA813017A.additionalIncludes

//## begin module%3F6CA813017A.includes preserve=yes
//## end module%3F6CA813017A.includes

// EBETsmon
#include "EBETsmon.h"
// EBCOsync
#include "EBCOsync.h"


//## begin module%3F6CA813017A.declarations preserve=no
//## end module%3F6CA813017A.declarations

//## begin module%3F6CA813017A.additionalDeclarations preserve=yes
//## end module%3F6CA813017A.additionalDeclarations


// Class CETSystemMonitor 

//## begin CETSystemMonitor::pInstance%3F6CA8300064.role preserve=no  public: static CETSystemMonitor {1..1 -> 1..1RFHN}
CETSystemMonitor *CETSystemMonitor::m_pInstance = NULL;
//## end CETSystemMonitor::pInstance%3F6CA8300064.role










CETSystemMonitor::CETSystemMonitor()
  //## begin CETSystemMonitor::CETSystemMonitor%.hasinit preserve=no
      : m_hSocketEvent(NULL), m_hMessageEvent(NULL), m_hSocket(NULL), m_uiPortNo(8105), m_pQueueFlushSyncObj(NULL)
  //## end CETSystemMonitor::CETSystemMonitor%.hasinit
  //## begin CETSystemMonitor::CETSystemMonitor%.initialization preserve=yes
  , CETThread("System Monitor")
  //## end CETSystemMonitor::CETSystemMonitor%.initialization
{
  //## begin CETSystemMonitor::CETSystemMonitor%.body preserve=yes
    m_hSocketEvent  = ::CreateEvent(NULL, true, false, NULL);
    m_hMessageEvent = ::CreateEvent(NULL, true, false, NULL);

	// store instance reference
	m_pMonitor = this;
  //## end CETSystemMonitor::CETSystemMonitor%.body
}


CETSystemMonitor::~CETSystemMonitor()
{
  //## begin CETSystemMonitor::~CETSystemMonitor%.body preserve=yes
    if (m_hSocketEvent)
        ::CloseHandle(m_hSocketEvent);
    m_hSocketEvent = NULL;

    if (m_hMessageEvent)
        ::CloseHandle(m_hMessageEvent);
    m_hMessageEvent = NULL;

	// close all listeners
	for (POSITION l_Pos=m_Listeners.GetHeadPosition(); l_Pos!=NULL;)
	{
		::closesocket(m_Listeners.GetNext(l_Pos));
	}
	m_Listeners.RemoveAll();

	if (m_hSocket != NULL && m_hSocket != INVALID_SOCKET)
		::closesocket(m_hSocket);
	m_hSocket = NULL;

    // remove messages
    for (POSITION l_Pos1=m_Messages.GetHeadPosition(); l_Pos1!=NULL;)
    {
	    delete m_Messages.GetNext(l_Pos1);
    }
    m_Messages.RemoveAll();


	// reset monitor instance reference
	m_pMonitor = NULL;
  //## end CETSystemMonitor::~CETSystemMonitor%.body
}



//## Other Operations (implementation)
void CETSystemMonitor::Create ()
{
  //## begin CETSystemMonitor::Create%1064085910.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CETSystemMonitor();
	m_pInstance->Initialize();
	m_pInstance->Start();
  //## end CETSystemMonitor::Create%1064085910.body
}

void CETSystemMonitor::Delete ()
{
  //## begin CETSystemMonitor::Delete%1064085911.body preserve=yes
	if (m_pInstance)
	{
		m_pInstance->Terminate();
	}
	m_pInstance = NULL;
  //## end CETSystemMonitor::Delete%1064085911.body
}

CETSystemMonitor* CETSystemMonitor::GetInstance ()
{
  //## begin CETSystemMonitor::GetInstance%1064085912.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CETSystemMonitor::GetInstance%1064085912.body
}

void CETSystemMonitor::Initialize ()
{
  //## begin CETSystemMonitor::Initialize%1064085914.body preserve=yes
    int l_iErr;
    struct sockaddr_in l_Address;

    m_hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_hSocket == INVALID_SOCKET)
    {
        // TODO: exception management
        ASSERT(FALSE);
        l_iErr = WSAGetLastError();
    }
 
    memset(&l_Address, 0, sizeof(l_Address));
    l_Address.sin_family = AF_INET;
    l_Address.sin_addr.s_addr = INADDR_ANY; /* any interface */     
    l_Address.sin_port = htons(m_uiPortNo);

    l_iErr = bind(m_hSocket, (const sockaddr*)&l_Address, sizeof(l_Address));
    if (l_iErr == SOCKET_ERROR)
    {
        // TODO: exception management
        ASSERT(FALSE);
        l_iErr = WSAGetLastError();
    }
  //## end CETSystemMonitor::Initialize%1064085914.body
}

DWORD CETSystemMonitor::ThreadMain ()
{
  //## begin CETSystemMonitor::ThreadMain%1064085913.body preserve=yes
    try
    {
        // register connection request event
        int l_iErr = WSAEventSelect(m_hSocket, m_hSocketEvent, FD_ACCEPT);
        if (l_iErr == SOCKET_ERROR)
        {
            // TODO: exception management
            ASSERT(FALSE);
            l_iErr = WSAGetLastError();
        }

        // put socket into listening state
        l_iErr = listen(m_hSocket, 5);
        if (l_iErr == SOCKET_ERROR)
        {
            // TODO: exception management
            ASSERT(FALSE);
            l_iErr = WSAGetLastError();
        }

        HANDLE l_WaitHandles[] = { m_hTerminationEvent, m_hSocketEvent, m_hMessageEvent };

        bool l_bExecuting = true;
        while (l_bExecuting)
        {
            int l_iSignalledIndex = ::WaitForMultipleObjects(3, l_WaitHandles, false, INFINITE);
            switch(l_iSignalledIndex)
            {
                case WAIT_OBJECT_0+0:
                    // terminate thread
                    l_bExecuting = false;
                    break;

                case WAIT_OBJECT_0+1:
                    // accept new connection
                    ::ResetEvent(m_hSocketEvent);

                    AcceptListener();
                    break;

                case WAIT_OBJECT_0+2:
                    // new message arrived
					::ResetEvent(m_hMessageEvent);
                    ProcessMessages();
                    break;

                default:
                    ASSERT(FALSE);
            }  
        }

        return 0;
    }
	catch(...)
    {
        ASSERT(FALSE);
        return 0;
    }
  //## end CETSystemMonitor::ThreadMain%1064085913.body
}

void CETSystemMonitor::AcceptListener ()
{
  //## begin CETSystemMonitor::AcceptListener%1064085915.body preserve=yes
    SOCKET l_hClient = accept(m_hSocket, NULL, NULL);
    if (l_hClient != INVALID_SOCKET)
    {
	    // add to list of present clients
	    m_Listeners.AddTail(l_hClient);
    }
  //## end CETSystemMonitor::AcceptListener%1064085915.body
}

void CETSystemMonitor::AddMessage (const CString& p_sUnitID, const CString& p_sMessage)
{
  //## begin CETSystemMonitor::AddMessage%1064258348.body preserve=yes
	CETSystemMonitorMessage* l_pMsg = new CETSystemMonitorMessage(p_sUnitID, p_sMessage);

	CSingleLock l_Lock(&m_QueueLock, true);
	m_Messages.AddTail(l_pMsg);
	::SetEvent(m_hMessageEvent);
  //## end CETSystemMonitor::AddMessage%1064258348.body
}

void CETSystemMonitor::FlushQueue ()
{
  //## begin CETSystemMonitor::FlushQueue%1084342562.body preserve=yes
	CETSystemMonitorMessage* l_pMsg = new CETSystemMonitorMessage(_T("ET"), _T("Queue Flushed"));

	CSingleLock l_Lock(&m_QueueLock, true);
    m_pQueueFlushSyncObj = new CCOSyncObject();
    CCOSyncObject* l_pQueueFlushSyncObj = m_pQueueFlushSyncObj;
    l_pQueueFlushSyncObj->AddRef();
	m_Messages.AddTail(l_pMsg);
	::SetEvent(m_hMessageEvent);

    l_Lock.Unlock();

    // wait for completion
    l_pQueueFlushSyncObj->Synchronize();
    l_pQueueFlushSyncObj->ReleaseRef();
  //## end CETSystemMonitor::FlushQueue%1084342562.body
}

void CETSystemMonitor::ProcessMessages ()
{
  //## begin CETSystemMonitor::ProcessMessages%1064258349.body preserve=yes
	CETSystemMonitorMessage* l_pMsg = NULL;

	do
	{
		l_pMsg = NULL;
		{
			// pick next message
			CSingleLock l_Lock(&m_QueueLock, true);
			if (m_Messages.GetCount() > 0)
			{
				l_pMsg = m_Messages.RemoveHead();
			}
		}

		if (l_pMsg != NULL)
		{
			// trace message locally
			l_pMsg->Trace();

			// transport message to listener
			BYTE* l_pbyBuffer;
			DWORD l_dwBufferSize;
			l_pMsg->Serialize(l_pbyBuffer, l_dwBufferSize);

			// send message to all listeners
			for (POSITION l_Pos = m_Listeners.GetHeadPosition(); l_Pos!=NULL;)
			{
				POSITION l_CurPos = l_Pos;
				SOCKET l_hListener = m_Listeners.GetNext(l_Pos);
				if (send(l_hListener, (const char*)l_pbyBuffer, l_dwBufferSize, 0) == SOCKET_ERROR)
				{
					// listener failed -> connection broken -> remove from list
					m_Listeners.RemoveAt(l_CurPos);
					::closesocket(l_hListener);
				}
			}
			delete [] l_pbyBuffer;
			delete l_pMsg;
		}

	} while (l_pMsg != NULL);

	CSingleLock l_Lock(&m_QueueLock, true);
    if (m_pQueueFlushSyncObj)
    {
        m_pQueueFlushSyncObj->SignalCompletion();
        m_pQueueFlushSyncObj->ReleaseRef();
        m_pQueueFlushSyncObj = NULL;
    }
  //## end CETSystemMonitor::ProcessMessages%1064258349.body
}

// Additional Declarations
  //## begin CETSystemMonitor%3F6CA7AD024F.declarations preserve=yes
  //## end CETSystemMonitor%3F6CA7AD024F.declarations

// Class CETSystemMonitorMessage 





CETSystemMonitorMessage::CETSystemMonitorMessage (const CString& p_sUnitID, const CString& p_sMessage)
  //## begin CETSystemMonitorMessage::CETSystemMonitorMessage%1064258347.hasinit preserve=no
      : m_sUnitID(p_sUnitID), m_sMessage(p_sMessage)
  //## end CETSystemMonitorMessage::CETSystemMonitorMessage%1064258347.hasinit
  //## begin CETSystemMonitorMessage::CETSystemMonitorMessage%1064258347.initialization preserve=yes
  //## end CETSystemMonitorMessage::CETSystemMonitorMessage%1064258347.initialization
{
  //## begin CETSystemMonitorMessage::CETSystemMonitorMessage%1064258347.body preserve=yes
    // get time in system time format
	SYSTEMTIME l_st;
	GetLocalTime(&l_st);

	// get necessary buffer size
	int nSize = GetTimeFormat(
		LOCALE_SYSTEM_DEFAULT, 
		LOCALE_NOUSEROVERRIDE, 
		&l_st, 
		NULL, 
		NULL, 
		0);

	// format the time
	CString l_sTime;
	GetTimeFormat(
		LOCALE_SYSTEM_DEFAULT, 
		LOCALE_NOUSEROVERRIDE, 
		&l_st, 
		NULL, 
		l_sTime.GetBuffer(nSize), 
		nSize);

	l_sTime.ReleaseBuffer();

    m_sTimeStamp = l_sTime;
	
  //## end CETSystemMonitorMessage::CETSystemMonitorMessage%1064258347.body
}


CETSystemMonitorMessage::~CETSystemMonitorMessage()
{
  //## begin CETSystemMonitorMessage::~CETSystemMonitorMessage%.body preserve=yes
  //## end CETSystemMonitorMessage::~CETSystemMonitorMessage%.body
}



//## Other Operations (implementation)
void CETSystemMonitorMessage::Serialize (BYTE*& p_pbyBuffer, DWORD& p_dwSize)
{
  //## begin CETSystemMonitorMessage::Serialize%1064258350.body preserve=yes
	// build message string
	CString l_sMsg = m_sUnitID + _T("@") + m_sTimeStamp + _T("@") + m_sMessage;

	// prepare buffer
	p_dwSize    = sizeof(DWORD) + l_sMsg.GetLength()*2+2;
	p_pbyBuffer = new BYTE[p_dwSize];
	*((DWORD*)p_pbyBuffer) = p_dwSize;
	wcscpy((WCHAR*)(p_pbyBuffer+sizeof(DWORD)), (LPCTSTR)l_sMsg);
  //## end CETSystemMonitorMessage::Serialize%1064258350.body
}

void CETSystemMonitorMessage::Trace ()
{
  //## begin CETSystemMonitorMessage::Trace%1064258351.body preserve=yes
	TRACE(m_sUnitID+_T("@")+m_sTimeStamp+_T("@")+m_sMessage+_T("\n"));
  //## end CETSystemMonitorMessage::Trace%1064258351.body
}

// Additional Declarations
  //## begin CETSystemMonitorMessage%3F6CAE3501D1.declarations preserve=yes
  //## end CETSystemMonitorMessage%3F6CAE3501D1.declarations

//## begin module%3F6CA813017A.epilog preserve=yes
//## end module%3F6CA813017A.epilog
