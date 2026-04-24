//## begin module%3DA53C27022C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA53C27022C.cm

//## begin module%3DA53C27022C.cp preserve=no
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
//## end module%3DA53C27022C.cp

//## Module: EBETwrit%3DA53C27022C; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETwrit.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA53C27022C.additionalIncludes preserve=no
//## end module%3DA53C27022C.additionalIncludes

//## begin module%3DA53C27022C.includes preserve=yes
//## end module%3DA53C27022C.includes

// EBETwrit
#include "EBETwrit.h"
// EBETmesg
#include "EBETmesg.h"
// EBETchan
#include "EBETchan.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBCOsync
#include "EBCOsync.h"


//## begin module%3DA53C27022C.declarations preserve=no
//## end module%3DA53C27022C.declarations

//## begin module%3DA53C27022C.additionalDeclarations preserve=yes
//## end module%3DA53C27022C.additionalDeclarations


// Class CETChannelWriter 












CETChannelWriter::CETChannelWriter (CETChannel* p_pContext, const CString& p_sName, SOCKET p_hSocket)
  //## begin CETChannelWriter::CETChannelWriter%1034230440.hasinit preserve=no
      : m_dwWaitIndexNewMessage(0), m_dwWaitIndexTermination(1), m_dwWaitIndexStartMessageSignalled(2), m_bDisconnected(false), m_hSocket(p_hSocket), m_hMessageEvent(NULL), m_pContext(p_pContext)
  //## end CETChannelWriter::CETChannelWriter%1034230440.hasinit
  //## begin CETChannelWriter::CETChannelWriter%1034230440.initialization preserve=yes
  , CETThread(p_sName)
  //## end CETChannelWriter::CETChannelWriter%1034230440.initialization
{
  //## begin CETChannelWriter::CETChannelWriter%1034230440.body preserve=yes
    m_hMessageEvent = ::CreateEvent(NULL, true, false, NULL);
  //## end CETChannelWriter::CETChannelWriter%1034230440.body
}


CETChannelWriter::~CETChannelWriter()
{
  //## begin CETChannelWriter::~CETChannelWriter%.body preserve=yes
    if (m_hMessageEvent)
        ::CloseHandle(m_hMessageEvent);
    m_hMessageEvent = NULL;

	// cleanup any pending messages
    for (POSITION l_Pos=m_MessageList.GetHeadPosition(); l_Pos!=NULL;)
    {
        CETChannelMessageEnvoy* l_MsgEnvoy = (CETChannelMessageEnvoy*)m_MessageList.GetNext(l_Pos);
        l_MsgEnvoy->ReleaseRef();
    }
    m_MessageList.RemoveAll();

    // cleanup any pending incident messages
    for (POSITION l_Pos=m_IncidentMessageList.GetHeadPosition(); l_Pos!=NULL;)
    {
        CETChannelMessageEnvoy* l_MsgEnvoy = (CETChannelMessageEnvoy*)m_IncidentMessageList.GetNext(l_Pos);
        l_MsgEnvoy->ReleaseRef();
    }
    m_IncidentMessageList.RemoveAll();
  //## end CETChannelWriter::~CETChannelWriter%.body
}



//## Other Operations (implementation)
DWORD CETChannelWriter::ThreadMain ()
{
  //## begin CETChannelWriter::ThreadMain%1034230442.body preserve=yes

	try
	{
		bool l_bExecuting = true;
		while (l_bExecuting)
		{
			// create wait handle array
			INT l_iIncidentIndex = 0;
			HANDLE* l_hHandleArray = NULL;
			CTypedPtrArray<CPtrArray, CETChannelMessageEnvoy*> l_LinkedMessages;
			INT l_iNoOfHandles = CreateWaitHandleArray(l_hHandleArray, l_LinkedMessages, l_iIncidentIndex);

			// wait for event
			DWORD l_dwSignalledIndex = ::WaitForMultipleObjects(l_iNoOfHandles, l_hHandleArray, false, INFINITE);
			switch(l_dwSignalledIndex)
			{
				case WAIT_TIMEOUT:
					ASSERT(FALSE);
					break;

				default:
					if (l_dwSignalledIndex == WAIT_OBJECT_0+m_dwWaitIndexNewMessage)
					{
						// got new message -> add message to the list of wait handles
						::ResetEvent(m_hMessageEvent);
					}
					else if (l_dwSignalledIndex == WAIT_OBJECT_0+m_dwWaitIndexTermination)
					{
						// stop executing
						l_bExecuting = false;
					}
					else if (l_dwSignalledIndex >= (WAIT_OBJECT_0+m_dwWaitIndexStartMessageSignalled) &&
							l_dwSignalledIndex < (DWORD)(WAIT_OBJECT_0+l_iIncidentIndex))
					{
						// a message has been signalled
						CETChannelMessageEnvoy* l_pSignalledMsg = l_LinkedMessages.GetAt(l_dwSignalledIndex-m_dwWaitIndexStartMessageSignalled);
						ProcessSignalledMessage(l_pSignalledMsg);
					}
					else if (l_dwSignalledIndex >= (DWORD)(WAIT_OBJECT_0+l_iIncidentIndex) &&
							l_dwSignalledIndex < (DWORD)(WAIT_OBJECT_0+l_iNoOfHandles))
					{
						// an incident message has been signalled
						CETChannelMessageEnvoy* l_pSignalledMsg = l_LinkedMessages.GetAt(l_dwSignalledIndex-m_dwWaitIndexStartMessageSignalled);
						ProcessSignalledIncidentMessage(l_pSignalledMsg);
					}
					else
					{
						// NOT supported
						ASSERT(FALSE);
					}
					break;
			}

			// cleanup        
			for (int l_iCnt=0; l_iCnt<l_LinkedMessages.GetSize(); l_iCnt++)
			{
				CETChannelMessageEnvoy* l_pMsg = l_LinkedMessages.GetAt(l_iCnt);
				l_pMsg->ReleaseRef();
			}
			l_LinkedMessages.RemoveAll();

			delete [] l_hHandleArray;
		}
    }
	catch(XETExceptionConnectionLost* p_pException)
	{
		// connection has been lost
		m_bDisconnected = true;
		p_pException->Delete();
	}
	catch(...)
	{
		m_bDisconnected = true;
	}

	if (m_bDisconnected)
	{
		// wait for termination signal
		::WaitForSingleObject(m_hTerminationEvent, INFINITE);
	}

    return 0;
  //## end CETChannelWriter::ThreadMain%1034230442.body
}

void CETChannelWriter::AddMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelWriter::AddMessage%1034230441.body preserve=yes
    CSingleLock l_Lock(&m_MessageLock, true);

	m_MessageList.AddTail(p_pMsg);
    ::SetEvent(m_hMessageEvent);
  //## end CETChannelWriter::AddMessage%1034230441.body
}

void CETChannelWriter::AddIncidentMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelWriter::AddIncidentMessage%1037346552.body preserve=yes
    CSingleLock l_Lock(&m_MessageLock, true);

    // check for uniq incident messages
    bool l_bMessageReplaced = false;
    for (POSITION l_Pos=m_IncidentMessageList.GetHeadPosition(); l_Pos!=NULL;)
    {
        POSITION l_CurPos = l_Pos;
        CETChannelMessageEnvoy* l_pMsg = m_IncidentMessageList.GetNext(l_Pos);
        if (l_pMsg->GetpMsg()->GetuiObjRefID() == p_pMsg->GetpMsg()->GetuiObjRefID())
        {
            // object is found
            l_pMsg->ReleaseRef();
            m_IncidentMessageList.SetAt(l_CurPos, p_pMsg);
            l_bMessageReplaced = true;
            break;
        }
    }

    if (!l_bMessageReplaced)
	    m_IncidentMessageList.AddTail(p_pMsg);

    ::SetEvent(m_hMessageEvent);
  //## end CETChannelWriter::AddIncidentMessage%1037346552.body
}

void CETChannelWriter::RemoveIncidentMessage (UINT p_uiObjRefID)
{
  //## begin CETChannelWriter::RemoveIncidentMessage%1037346555.body preserve=yes
    CSingleLock l_Lock(&m_MessageLock, true);

    // try to find message
    for (POSITION l_Pos=m_IncidentMessageList.GetHeadPosition(); l_Pos!=NULL;)
    {
        POSITION l_CurPos = l_Pos;
        CETChannelMessageEnvoy* l_pMsg = m_IncidentMessageList.GetNext(l_Pos);
        if (l_pMsg->GetpMsg()->GetuiObjRefID() == p_uiObjRefID)
        {
            // object is found
            l_pMsg->ReleaseRef();
            m_IncidentMessageList.RemoveAt(l_CurPos);
            return;
        }
    }
  //## end CETChannelWriter::RemoveIncidentMessage%1037346555.body
}

void CETChannelWriter::NewMessages ()
{
  //## begin CETChannelWriter::NewMessages%1034230443.body preserve=yes
	CETChannelMessageEnvoy* l_pMsg = NULL;
	BYTE* l_pbyStream = NULL;

	try
	{
		POSITION l_Pos = NULL;
		CSingleLock l_lock(&m_MessageLock);

		// process all messages
		do
		{
			// get access to queue
			l_lock.Lock();  
			l_Pos = m_MessageList.GetHeadPosition();
			if (l_Pos != NULL)
			{
				l_pMsg = m_MessageList.GetAt(l_Pos);
				m_MessageList.RemoveAt(l_Pos);
				::ResetEvent(m_hMessageEvent);

				// release queue
				l_lock.Unlock();
	            
				INT   l_iStreamLength;
				l_pMsg->GetpMsg()->Serialize(l_pbyStream, l_iStreamLength);

				if (send(m_hSocket, (const char*)l_pbyStream, l_iStreamLength, 0) == SOCKET_ERROR)
				{                
					// connection has been lost
					throw new XETExceptionConnectionLost();
				}

				// cleanup
				delete [] l_pbyStream;
				l_pbyStream = NULL;
				l_pMsg->ReleaseRef();
				l_pMsg = NULL;
			}
		} while (l_Pos != NULL);
	}
	catch(...)
	{
		if (l_pbyStream)
			delete [] l_pbyStream;
		if (l_pMsg)
			l_pMsg->ReleaseRef();

		throw;
	}
  //## end CETChannelWriter::NewMessages%1034230443.body
}

void CETChannelWriter::ProcessSignalledMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelWriter::ProcessSignalledMessage%1034329221.body preserve=yes
    BYTE* l_pbyStream = NULL;
	CETChannelMessageEnvoy* l_pMsg = p_pMsg;
    CETChannelMessage* l_pErrorMsg = NULL;

	try
	{
		CSingleLock l_Lock(&m_MessageLock, true);

		// remove signalled message from message queue
		POSITION l_Pos = m_MessageList.Find(l_pMsg);
		ASSERT(l_Pos != NULL);
		m_MessageList.RemoveAt(l_Pos);

		// release queue
		l_Lock.Unlock();

		// process return value
		l_pMsg->HandleReturnValue();

		INT   l_iStreamLength;

        try
        {
		    l_pMsg->GetpMsg()->Serialize(l_pbyStream, l_iStreamLength);
        }
        catch(XCOExceptionErrorMemoryAllocation* p_pException)
        {
            p_pException->Delete();

            l_pErrorMsg = l_pMsg->GetpMsg()->GetErrorReply(p_pException->GetuiExceptionID());
            l_pErrorMsg->Serialize(l_pbyStream, l_iStreamLength);
        }

		if (send(m_hSocket, (const char*)l_pbyStream, l_iStreamLength, 0) == SOCKET_ERROR)
		{
			throw new XETExceptionConnectionLost();
		}

		// cleanup
		delete [] l_pbyStream;
		l_pbyStream = NULL;
		l_pMsg->ReleaseRef();
		l_pMsg = NULL;

        delete l_pErrorMsg;
	}
	catch(...)
	{
		if (l_pbyStream)
			delete [] l_pbyStream;
		if (l_pMsg)
			l_pMsg->ReleaseRef();

		throw;
	}
  //## end CETChannelWriter::ProcessSignalledMessage%1034329221.body
}

void CETChannelWriter::ProcessSignalledIncidentMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelWriter::ProcessSignalledIncidentMessage%1037346553.body preserve=yes
	BYTE* l_pbyStream = NULL;
	try
	{
		// process return value
		p_pMsg->HandleReturnValue();

		INT   l_iStreamLength;
		p_pMsg->GetpMsg()->Serialize(l_pbyStream, l_iStreamLength);

		if (send(m_hSocket, (const char*)l_pbyStream, l_iStreamLength, 0) == SOCKET_ERROR)
		{
			throw new XETExceptionConnectionLost();
		}

		// cleanup
		delete [] l_pbyStream;
		l_pbyStream = NULL;

		p_pMsg->GetpServerSyncObj()->ResetCompletion();
	}
	catch(...)
	{
		if (l_pbyStream)
			delete [] l_pbyStream;
		p_pMsg->GetpServerSyncObj()->ResetCompletion();

		throw;
	}
  //## end CETChannelWriter::ProcessSignalledIncidentMessage%1037346553.body
}

INT CETChannelWriter::CreateWaitHandleArray (HANDLE*& p_hArray, CTypedPtrArray<CPtrArray, CETChannelMessageEnvoy*>& p_LinkedMessages, INT& p_iIncidentStartIndex)
{
  //## begin CETChannelWriter::CreateWaitHandleArray%1034407670.body preserve=yes
    CSingleLock l_lock(&m_MessageLock, true);

	INT l_iNoOfMessages = m_MessageList.GetCount() + m_IncidentMessageList.GetCount();
	p_LinkedMessages.SetSize(l_iNoOfMessages);
	
	p_hArray = new HANDLE[m_dwWaitIndexStartMessageSignalled+l_iNoOfMessages];
	p_hArray[m_dwWaitIndexNewMessage] = m_hMessageEvent;
	p_hArray[m_dwWaitIndexTermination] = m_hTerminationEvent;

	// add sync objects of messages
	int l_iCnt=m_dwWaitIndexStartMessageSignalled;
	for (POSITION l_Pos=m_MessageList.GetHeadPosition(); l_Pos!=NULL;)
	{
		CETChannelMessageEnvoy* l_pMsg = m_MessageList.GetNext(l_Pos);
		p_LinkedMessages.SetAt(l_iCnt-m_dwWaitIndexStartMessageSignalled, l_pMsg);
		p_hArray[l_iCnt++] = (HANDLE)(*l_pMsg->GetpServerSyncObj());
        l_pMsg->AddRef();
	}

    // add incident messages
    p_iIncidentStartIndex = l_iCnt;
    
    for (POSITION l_Pos = m_IncidentMessageList.GetHeadPosition(); l_Pos!=NULL;)
    {
		CETChannelMessageEnvoy* l_pMsg = m_IncidentMessageList.GetNext(l_Pos);
		p_LinkedMessages.SetAt(l_iCnt-m_dwWaitIndexStartMessageSignalled, l_pMsg);
		p_hArray[l_iCnt++] = (HANDLE)(*l_pMsg->GetpServerSyncObj());
        l_pMsg->AddRef();
    }

	return m_dwWaitIndexStartMessageSignalled+l_iNoOfMessages;
  //## end CETChannelWriter::CreateWaitHandleArray%1034407670.body
}

//## Get and Set Operations for Class Attributes (implementation)

BOOL CETChannelWriter::GetbDisconnected ()
{
  //## begin CETChannelWriter::GetbDisconnected%3F6F57D0022F.get preserve=no
  return m_bDisconnected;
  //## end CETChannelWriter::GetbDisconnected%3F6F57D0022F.get
}

//## Get and Set Operations for Associations (implementation)

SOCKET CETChannelWriter::GethSocket ()
{
  //## begin CETChannelWriter::GethSocket%3DA53C4B0048.get preserve=no
  return m_hSocket;
  //## end CETChannelWriter::GethSocket%3DA53C4B0048.get
}

// Additional Declarations
  //## begin CETChannelWriter%3DA53BEC022C.declarations preserve=yes
  //## end CETChannelWriter%3DA53BEC022C.declarations

// Class XETExceptionConnectionLost 

XETExceptionConnectionLost::XETExceptionConnectionLost()
  //## begin XETExceptionConnectionLost::XETExceptionConnectionLost%.hasinit preserve=no
  //## end XETExceptionConnectionLost::XETExceptionConnectionLost%.hasinit
  //## begin XETExceptionConnectionLost::XETExceptionConnectionLost%.initialization preserve=yes
  //## end XETExceptionConnectionLost::XETExceptionConnectionLost%.initialization
{
  //## begin XETExceptionConnectionLost::XETExceptionConnectionLost%.body preserve=yes
  //## end XETExceptionConnectionLost::XETExceptionConnectionLost%.body
}


XETExceptionConnectionLost::~XETExceptionConnectionLost()
{
  //## begin XETExceptionConnectionLost::~XETExceptionConnectionLost%.body preserve=yes
  //## end XETExceptionConnectionLost::~XETExceptionConnectionLost%.body
}


// Additional Declarations
  //## begin XETExceptionConnectionLost%3F6F5546039D.declarations preserve=yes
  //## end XETExceptionConnectionLost%3F6F5546039D.declarations

//## begin module%3DA53C27022C.epilog preserve=yes
//## end module%3DA53C27022C.epilog
