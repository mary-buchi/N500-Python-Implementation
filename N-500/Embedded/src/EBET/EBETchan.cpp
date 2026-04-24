//## begin module%3D9D884C0096.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3D9D884C0096.cm

//## begin module%3D9D884C0096.cp preserve=no
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
//## end module%3D9D884C0096.cp

//## Module: EBETchan%3D9D884C0096; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchan.cpp

// stdafx
#include "stdafx.h"
//## begin module%3D9D884C0096.additionalIncludes preserve=no
//## end module%3D9D884C0096.additionalIncludes

//## begin module%3D9D884C0096.includes preserve=yes
//## end module%3D9D884C0096.includes

// EBETread
#include "EBETread.h"
// EBETchan
#include "EBETchan.h"
// EBETbrws
#include "EBETbrws.h"
// EBETflog
#include "EBETflog.h"
// EBETsess
#include "EBETsess.h"
// EBETchi2
#include "EBETchi2.h"
// EBETchsy
#include "EBETchsy.h"
// EBETchdg
#include "EBETchdg.h"
// EBETchet
#include "EBETchet.h"
// EBETchcw
#include "EBETchcw.h"
// EBETchcp
#include "EBETchcp.h"
// EBETchct
#include "EBETchct.h"
// EBETchot
#include "EBETchot.h"
// EBETchsr
#include "EBETchsr.h"
// EBETchpo
#include "EBETchpo.h"
// EBETchcr
#include "EBETchcr.h"
// EBETchmc
#include "EBETchmc.h"
// EBETchst
#include "EBETchst.h"
// EBETwrit
#include "EBETwrit.h"
// EBETmesg
#include "EBETmesg.h"
// EBPIfact
#include "EBPIfact.h"
// EBPIintf
#include "EBPIintf.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBCOsync
#include "EBCOsync.h"
// EBSYexcp
#include "EBSYexcp.h"


//## begin module%3D9D884C0096.declarations preserve=no
//## end module%3D9D884C0096.declarations

//## begin module%3D9D884C0096.additionalDeclarations preserve=yes
// exception ID's
#define IDE_ETHERNET_INVALID_COMMAND		4000
#define IDE_ETHERNET_UNEXPECTED_EXCEPTION	4001
//## end module%3D9D884C0096.additionalDeclarations


// Class CETChannel 


//## begin CETChannel::uiPortNoObjCreator%3DB50428033E.attr preserve=no  private: static UINT {U} 8090
UINT CETChannel::m_uiPortNoObjCreator = 8090;
//## end CETChannel::uiPortNoObjCreator%3DB50428033E.attr

//## begin CETChannel::uiPortNoStepperMotors%3DB5045E00EC.attr preserve=no  private: static UINT {U} 8091
UINT CETChannel::m_uiPortNoStepperMotors = 8091;
//## end CETChannel::uiPortNoStepperMotors%3DB5045E00EC.attr

//## begin CETChannel::uiPortNoMeasChannel%3DB5045F00AE.attr preserve=no  private: static UINT {U} 8092
UINT CETChannel::m_uiPortNoMeasChannel = 8092;
//## end CETChannel::uiPortNoMeasChannel%3DB5045F00AE.attr

//## begin CETChannel::uiPortNoPersistentObjects%3DBC0AD70316.attr preserve=no  private: static UINT {U} 8093
UINT CETChannel::m_uiPortNoPersistentObjects = 8093;
//## end CETChannel::uiPortNoPersistentObjects%3DBC0AD70316.attr

//## begin CETChannel::uiPortNoSensors%3DBC0AE700CA.attr preserve=no  private: static UINT {U} 8094
UINT CETChannel::m_uiPortNoSensors = 8094;
//## end CETChannel::uiPortNoSensors%3DBC0AE700CA.attr

//## begin CETChannel::uiPortNoOutputs%3DBC0AED0368.attr preserve=no  private: static UINT {U} 8095
UINT CETChannel::m_uiPortNoOutputs = 8095;
//## end CETChannel::uiPortNoOutputs%3DBC0AED0368.attr

//## begin CETChannel::uiPortNoTempControl%3DBC0AF803A0.attr preserve=no  private: static UINT {U} 8096
UINT CETChannel::m_uiPortNoTempControl = 8096;
//## end CETChannel::uiPortNoTempControl%3DBC0AF803A0.attr

//## begin CETChannel::uiPortNoPowerControl%3DBC0B05007D.attr preserve=no  private: static UINT {U} 8097
UINT CETChannel::m_uiPortNoPowerControl = 8097;
//## end CETChannel::uiPortNoPowerControl%3DBC0B05007D.attr

//## begin CETChannel::uiPortNoWedgeControl%3DBC0B0D00C5.attr preserve=no  private: static UINT {U} 8098
UINT CETChannel::m_uiPortNoWedgeControl = 8098;
//## end CETChannel::uiPortNoWedgeControl%3DBC0B0D00C5.attr

//## begin CETChannel::uiPortNoEvents%3DBC0B180233.attr preserve=no  private: static UINT {U} 8099
UINT CETChannel::m_uiPortNoEvents = 8099;
//## end CETChannel::uiPortNoEvents%3DBC0B180233.attr

//## begin CETChannel::uiPortNoDiagnostic%3DF736B901FC.attr preserve=no  private: static UINT {U} 8100
UINT CETChannel::m_uiPortNoDiagnostic = 8100;
//## end CETChannel::uiPortNoDiagnostic%3DF736B901FC.attr

//## begin CETChannel::uiPortNoSystem%3EE5C32203BB.attr preserve=no  private: static UINT {U} 8101
UINT CETChannel::m_uiPortNoSystem = 8101;
//## end CETChannel::uiPortNoSystem%3EE5C32203BB.attr

//## begin CETChannel::uiPortNoI2CBus%3EE5EB2A01A8.attr preserve=no  private: static UINT {U} 8102
UINT CETChannel::m_uiPortNoI2CBus = 8102;
//## end CETChannel::uiPortNoI2CBus%3EE5EB2A01A8.attr
















CETChannel::CETChannel (const CString& p_sName, const UINT p_uiPortNo)
  //## begin CETChannel::CETChannel%1034142084.hasinit preserve=no
      : m_uiPortNo(p_uiPortNo), m_iState(0), m_hSocket(NULL), m_hSocketEvent(NULL), m_hMessageEvent(NULL), m_hEndedReaderEvent(NULL)
  //## end CETChannel::CETChannel%1034142084.hasinit
  //## begin CETChannel::CETChannel%1034142084.initialization preserve=yes
, CETThread(p_sName)
  //## end CETChannel::CETChannel%1034142084.initialization
{
  //## begin CETChannel::CETChannel%1034142084.body preserve=yes
    m_hSocketEvent  = ::CreateEvent(NULL, true, false, NULL);
    m_hMessageEvent = ::CreateEvent(NULL, true, false, NULL);
	m_hEndedReaderEvent = ::CreateEvent(NULL, true, false, NULL);
  //## end CETChannel::CETChannel%1034142084.body
}


CETChannel::~CETChannel()
{
  //## begin CETChannel::~CETChannel%.body preserve=yes
    TerminateHelpers();

	for(POSITION l_Pos=m_Clients.GetStartPosition(); l_Pos!=NULL;)
	{
		CETClient* l_pClient = NULL;
		SOCKET l_hClient;

		m_Clients.GetNextAssoc(l_Pos, l_hClient, l_pClient);
		delete l_pClient;
	}
	m_Clients.RemoveAll();

    if (m_hSocketEvent)
        ::CloseHandle(m_hSocketEvent);
    m_hSocketEvent = NULL;

    if (m_hMessageEvent)
        ::CloseHandle(m_hMessageEvent);
    m_hMessageEvent = NULL;

	if (m_hEndedReaderEvent)
		::CloseHandle(m_hEndedReaderEvent);
	m_hEndedReaderEvent = NULL;

    if (m_hSocket != NULL && m_hSocket != INVALID_SOCKET)
        ::closesocket(m_hSocket);
    m_hSocket = NULL;
  //## end CETChannel::~CETChannel%.body
}



//## Other Operations (implementation)
DWORD CETChannel::ThreadMain ()
{
  //## begin CETChannel::ThreadMain%1034142085.body preserve=yes
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

        HANDLE l_WaitHandles[] = { m_hTerminationEvent, m_hEndedReaderEvent, m_hSocketEvent, m_hMessageEvent  };

        bool l_bExecuting = true;
        while (l_bExecuting)
        {
			m_iState = 0;
            int l_iSignalledIndex = ::WaitForMultipleObjects(4, l_WaitHandles, false, INFINITE);
			m_iState = 77;
            switch(l_iSignalledIndex)
            {
				case WAIT_OBJECT_0+0:
					// terminate thread
					l_bExecuting = false;
					break;

				case WAIT_OBJECT_0+1:
					::ResetEvent(m_hEndedReaderEvent);
					HandleEndedReaders();
					break;

				case WAIT_OBJECT_0+2:
					// accept new connection
					::ResetEvent(m_hSocketEvent);

					if (DetermineSocketEvent())
					{
						AcceptClient();
					}
					break;

				case WAIT_OBJECT_0+3:
					// new message arrived
					HandleNewMessage();
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
  //## end CETChannel::ThreadMain%1034142085.body
}

void CETChannel::Initialize (DWORD p_dwIPConfig)
{
  //## begin CETChannel::Initialize%1034142088.body preserve=yes
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
  //## end CETChannel::Initialize%1034142088.body
}

void CETChannel::AcceptClient ()
{
  //## begin CETChannel::AcceptClient%1034142089.body preserve=yes
	m_iState = 1;
	try
	{
		CETFileLogger::GetInstance()->AddMessage(_T("Channel Accept.Start, socket=%d"), m_hSocket);
		SOCKET l_hClient = /*accept(m_hSocket, NULL, NULL);*/ WSAAccept(m_hSocket, NULL, NULL, NULL, NULL);
		CETFileLogger::GetInstance()->AddMessage(_T("Channel Accept.Done, socket=%d"), m_hSocket);
		if (l_hClient == INVALID_SOCKET)
		{
			ASSERT(FALSE);
			// TODO: exception management
		}

		// store client socket connection
		m_Clients[l_hClient] = new CETClient(l_hClient);

		// add or update session
		CETSessionManager::GetInstance()->AddToSession(m_uiPortNo, l_hClient);

		// create new reader and writers for the client
		CString l_sName = "Channel Writer: ";
		l_sName += m_sName;
		CETChannelWriter* l_pWriter = new CETChannelWriter(this, l_sName, l_hClient);
		m_ChannelWriters[l_hClient] = l_pWriter;
		l_pWriter->Start();

		l_sName = "Channel Reader: ";
		l_sName += m_sName;
		CETChannelReader* l_pReader = new CETChannelReader(this, l_sName, l_hClient, m_hSocketEvent, l_pWriter);
		m_ChannelReaders[l_hClient] = l_pReader;
		l_pReader->Start();
	}
	catch(...)
	{
		CETFileLogger::GetInstance()->AddMessage(_T("Exception in AcceptClient, socket=%d"), m_hSocket);
	}
  //## end CETChannel::AcceptClient%1034142089.body
}

void CETChannel::AddMessage (CETChannelMessageEnvoy* p_pMessage)
{
  //## begin CETChannel::AddMessage%1034230430.body preserve=yes
    CSingleLock l_Lock(&m_MessageLock, true);

    // add message to list of messages
    m_MessageList.AddTail(p_pMessage);
    ::SetEvent(m_hMessageEvent);
  //## end CETChannel::AddMessage%1034230430.body
}

void CETChannel::HandleNewMessage ()
{
  //## begin CETChannel::HandleNewMessage%1034230431.body preserve=yes
 	m_iState = 2;
	CSingleLock l_Lock(&m_MessageLock, true);

	try
	{
		// process all messages
		for (POSITION l_Pos=m_MessageList.GetHeadPosition(); l_Pos!=NULL;)
		{
			CETChannelMessageEnvoy* l_pMsg = m_MessageList.GetNext(l_Pos);
			try
			{
				ProcessMessage(l_pMsg);
			}
			catch(XCOException* p_pException)
			{
				// invoking the the appropriate message handler resolted in an exception
				l_pMsg->GetpMsg()->SetuiExceptionID(p_pException->GetuiExceptionID());
				p_pException->Delete();

				CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(l_pMsg->GetpMsg()->GetReply());
				FindWriter(l_pMsg->GethSocket())->AddMessage(l_pReply);
			}

			// delete message
			l_pMsg->ReleaseRef();
		}

		// remove all
		m_MessageList.RemoveAll();
		::ResetEvent(m_hMessageEvent);
	}
	catch(...)
	{
		CETFileLogger::GetInstance()->AddMessage(_T("Exception in HandleNewMessage, socket=%d"), m_hSocket);
	}
  //## end CETChannel::HandleNewMessage%1034230431.body
}

void CETChannel::HandleEndedReaders ()
{
  //## begin CETChannel::HandleEndedReaders%1183386645.body preserve=yes
	m_iState = 3;
	try
	{
		SOCKET l_hSocket = NULL;
		do
		{
			// extract socket
			l_hSocket = NULL;
			{
				CSingleLock l_Lock(&m_EndedReaderLock, true);
				if (m_EndedReaders.GetCount() > 0)
				{
					l_hSocket = m_EndedReaders.RemoveHead();
				}
			}

			if (l_hSocket != NULL)
			{
				CETClient* l_pClient = NULL;
				if (m_Clients.Lookup(l_hSocket, l_pClient))
				{
					delete l_pClient;
					m_Clients.RemoveKey(l_hSocket);
					CETFileLogger::GetInstance()->AddMessage(_T("Terminate ended reader, socket=%d"), l_hSocket);

					try
					{
						CETChannelReader* l_pReader = m_ChannelReaders[l_hSocket];
						l_pReader->Terminate();
					}
					catch(...)
					{
						CETFileLogger::GetInstance()->AddMessage(_T("Could not terminate reader, socket=%d"), l_hSocket);
					}
					m_ChannelReaders.RemoveKey(l_hSocket);
					m_ChannelWriters.RemoveKey(l_hSocket);

					CETSessionManager::GetInstance()->RemoveFromSession(m_uiPortNo, l_hSocket);
					::closesocket(l_hSocket);
				}
				else
				{
					CETFileLogger::GetInstance()->AddMessage(_T("Reader already terminated, socket=%d"), l_hSocket);
				}
			}
		} while (l_hSocket != NULL);
	}
	catch(...)
	{
		CETFileLogger::GetInstance()->AddMessage(_T("Exception in HandleEndedReaders, socket=%d"), m_hSocket);
	}

  //## end CETChannel::HandleEndedReaders%1183386645.body
}

void CETChannel::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannel::ProcessMessage%1034230432.body preserve=yes
	m_iState = 4;
	try
	{
		switch(p_pMsg->GetpMsg()->GeteCommand())
		{
			case eCmdNameConnection:
				OnNameConnection(p_pMsg);
				break;

			default:
				// send error reply
				CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
				l_pReply->GetpMsg()->SetuiExceptionID(IDE_ETHERNET_INVALID_COMMAND);

				FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
				break;
		}
	}
	catch(XCOException* p_pException)
	{
		// send error reply
		CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
		l_pReply->GetpMsg()->SetuiExceptionID(p_pException->GetuiExceptionID());

		FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
		p_pException->Delete();
	}
	catch(...)
	{
		CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
		l_pReply->GetpMsg()->SetuiExceptionID(IDE_ETHERNET_UNEXPECTED_EXCEPTION);

		FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
	}
  //## end CETChannel::ProcessMessage%1034230432.body
}

CETChannelWriter* CETChannel::FindWriter (SOCKET p_hSocket)
{
  //## begin CETChannel::FindWriter%1034230446.body preserve=yes
    CETChannelWriter* l_pWriter = NULL;
    BOOL l_bFound = m_ChannelWriters.Lookup(p_hSocket, l_pWriter);
    ASSERT(l_bFound);

    return l_pWriter;
  //## end CETChannel::FindWriter%1034230446.body
}

CETChannelMessage* CETChannel::UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength)
{
  //## begin CETChannel::UnwrapTelegram%1035273379.body preserve=yes
    CETChannelMessage* l_pMsg = new CETChannelMessage(p_pbyStream, p_uiStreamLength);

    switch(l_pMsg->GeteCommand())
    {
        case eCmdNameConnection:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageString(p_pbyStream, p_uiStreamLength);
            break;
    }

    return l_pMsg;
  //## end CETChannel::UnwrapTelegram%1035273379.body
}

BOOL CETChannel::DetermineSocketEvent ()
{
  //## begin CETChannel::DetermineSocketEvent%1064223157.body preserve=yes
	try
	{
		m_iState = 10;
		// try to talk to existing sockets
		WSANETWORKEVENTS l_Events;
		int l_iRes = ::WSAEnumNetworkEvents(m_hSocket, NULL, &l_Events);
		ASSERT(l_iRes == 0);

		if (l_Events.lNetworkEvents & FD_ACCEPT)
			return true;

		return false;
	}
	catch(...)
	{
		CETFileLogger::GetInstance()->AddMessage(_T("Exception in DetermineSocketEvent, socket=%d"), m_hSocket);
		return false;
	}
  //## end CETChannel::DetermineSocketEvent%1064223157.body
}

void CETChannel::ReaderTerminated (CETChannelReader* p_pReader)
{
  //## begin CETChannel::ReaderTerminated%1164812376.body preserve=yes
	CSingleLock l_Lock(&m_EndedReaderLock, true);

	CETFileLogger::GetInstance()->AddMessage(_T("Calling Reader terminated, socket=%d, state=%d"), m_hSocket, m_iState);

	m_EndedReaders.AddTail(p_pReader->GethSocket());
	::SetEvent(m_hEndedReaderEvent);
  //## end CETChannel::ReaderTerminated%1164812376.body
}

void CETChannel::TerminateConnection (SOCKET p_hSocket)
{
  //## begin CETChannel::TerminateConnection%1182942146.body preserve=yes
	m_iState = 5;
	CETChannelReader* l_pReader = NULL;
	if (m_ChannelReaders.Lookup(p_hSocket ,l_pReader))
	{
		CETFileLogger::GetInstance()->AddMessage(_T("End Reader socket=%d"), p_hSocket);
		l_pReader->End();
	}

	// reader will:
	//		- terminate writer
	//		- close socket
	//		- call ReaderTerminated on channel context,
	//			which removes both readers and writers from hash tables
  //## end CETChannel::TerminateConnection%1182942146.body
}

void CETChannel::TerminateHelpers ()
{
  //## begin CETChannel::TerminateHelpers%1064223158.body preserve=yes
	m_iState = 6;
	CETFileLogger::GetInstance()->AddMessage(_T("Terminate helpers on socket=%d"), m_hSocket);
	for(POSITION l_Pos = m_ChannelReaders.GetStartPosition(); l_Pos!=NULL;)
	{
		CETChannelReader* l_pReader = NULL;
		SOCKET l_hSocket;

		m_ChannelReaders.GetNextAssoc(l_Pos, l_hSocket, l_pReader);
		l_pReader->Terminate();
	}
    m_ChannelReaders.RemoveAll();
    m_ChannelWriters.RemoveAll();

  //## end CETChannel::TerminateHelpers%1064223158.body
}

void CETChannel::OnNameConnection (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannel::OnNameConnection%1182942149.body preserve=yes
	NameConnection(p_pMsg);

	// prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannel::OnNameConnection%1182942149.body
}

bool CETChannel::NameConnection (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannel::NameConnection%1182971545.body preserve=yes
	m_iState = 7;
	CETChannelMessageString* l_pMsg = dynamic_cast<CETChannelMessageString*>(p_pMsg->GetpMsg());
	SOCKET l_hSocketClient = p_pMsg->GethSocket();
	CETClient* l_pMyClient = m_Clients[l_hSocketClient];
	l_pMyClient->SetsName(l_pMsg->GetsString());
	CList<SOCKET, SOCKET> l_DeadSockets;

	CETSession* l_pCurrentSession = CETSessionManager::GetInstance()->FindSessionBySocket(l_hSocketClient);
	ASSERT(l_pCurrentSession != NULL);
	l_pCurrentSession->SetsName(l_pMsg->GetsString());
	if (!l_pCurrentSession->GetbIsPrimary())
	{
        try
        {
            // only change active sessions to primary if the system is not busy or if it is busy by the same client
            // primary session are responsible for the detection and handling of disconnecting process
            IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
            CCOSyncObjectPtr l_pSyncObj = l_pSystem->RegisterClient(l_pMsg->GetsString());
            l_pSyncObj->Synchronize();

            // named sessions have to be primary!
		    CETSessionManager::GetInstance()->SetPrimarySession(l_pCurrentSession);
        }
        catch(XSYExceptionErrorDeviceBusy* p_pException)
        {
            p_pException->Delete();
        }
        catch(XCOException* p_pException)
        {
            p_pException->Delete();
        }
	}

	for (POSITION l_Pos=m_Clients.GetStartPosition(); l_Pos!=NULL;)
	{
		CETClient*  l_pClient;
		SOCKET      l_hSocket;

		m_Clients.GetNextAssoc(l_Pos, l_hSocket, l_pClient);
		if (l_hSocket != p_pMsg->GethSocket())
		{
			CETSession* l_pSession = CETSessionManager::GetInstance()->FindSessionBySocket(l_hSocket);
			ASSERT(l_pSession != NULL);

			if (l_pMyClient->GetsName() == l_pClient->GetsName())
			{
				if (l_pSession->IsClosing())
				{
					CETFileLogger::GetInstance()->AddMessage(_T("Closing Session detected, socket=%d"), l_hSocket);
				}

				l_DeadSockets.AddTail(l_hSocket);			
			}
		}
	}

	if (l_DeadSockets.GetCount() > 0)
	{
		for (POSITION l_Pos=l_DeadSockets.GetHeadPosition(); l_Pos!=NULL;)
		{
			SOCKET l_hClient = l_DeadSockets.GetNext(l_Pos);
			TerminateConnection(l_hClient);
		}
	}

	return l_DeadSockets.GetCount() > 0;
  //## end CETChannel::NameConnection%1182971545.body
}

void CETChannel::GetPortNumbers (CList<UINT, UINT&>& p_PortNumbers)
{
  //## begin CETChannel::GetPortNumbers%1183443835.body preserve=yes
	p_PortNumbers.RemoveAll();
	p_PortNumbers.AddTail(m_uiPortNoDiagnostic);
	p_PortNumbers.AddTail(m_uiPortNoEvents);
	p_PortNumbers.AddTail(m_uiPortNoI2CBus);
	p_PortNumbers.AddTail(m_uiPortNoMeasChannel);
	p_PortNumbers.AddTail(m_uiPortNoObjCreator);
	p_PortNumbers.AddTail(m_uiPortNoOutputs);
	p_PortNumbers.AddTail(m_uiPortNoPersistentObjects);
	p_PortNumbers.AddTail(m_uiPortNoPowerControl);
	p_PortNumbers.AddTail(m_uiPortNoSensors);
	p_PortNumbers.AddTail(m_uiPortNoStepperMotors);
	p_PortNumbers.AddTail(m_uiPortNoSystem);
	p_PortNumbers.AddTail(m_uiPortNoTempControl);
	p_PortNumbers.AddTail(m_uiPortNoWedgeControl);
  //## end CETChannel::GetPortNumbers%1183443835.body
}

// Additional Declarations
  //## begin CETChannel%3DA2F3090146.declarations preserve=yes
  //## end CETChannel%3DA2F3090146.declarations

// Class CETChannelFactory 

//## begin CETChannelFactory::pInstance%3DA2F3710399.role preserve=no  public: static CETChannelFactory {1..1 -> 1..1RFHN}
CETChannelFactory *CETChannelFactory::m_pInstance;
//## end CETChannelFactory::pInstance%3DA2F3710399.role




CETChannelFactory::CETChannelFactory()
  //## begin CETChannelFactory::CETChannelFactory%.hasinit preserve=no
      : m_pBrowserService(NULL)
  //## end CETChannelFactory::CETChannelFactory%.hasinit
  //## begin CETChannelFactory::CETChannelFactory%.initialization preserve=yes
  //## end CETChannelFactory::CETChannelFactory%.initialization
{
  //## begin CETChannelFactory::CETChannelFactory%.body preserve=yes
    m_pBrowserService = new CETBrowserService();
    m_pBrowserService->Start();
  //## end CETChannelFactory::CETChannelFactory%.body
}


CETChannelFactory::~CETChannelFactory()
{
  //## begin CETChannelFactory::~CETChannelFactory%.body preserve=yes
    if (m_pBrowserService != NULL)
    {
        m_pBrowserService->Terminate();
        m_pBrowserService = NULL;
    }

    // stop all channels
    for (POSITION l_Pos=m_ChannelList.GetHeadPosition(); l_Pos!=NULL;)
    {
        CETChannel* l_Channel = m_ChannelList.GetNext(l_Pos);

        CO_TRACE1(_T("ET"), _T("Terminating Ethernet Channel: %s"), (LPCTSTR)l_Channel->GetsName());
        l_Channel->Terminate();       
    }

    m_ChannelList.RemoveAll();
  //## end CETChannelFactory::~CETChannelFactory%.body
}



//## Other Operations (implementation)
void CETChannelFactory::Create ()
{
  //## begin CETChannelFactory::Create%1034087076.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CETChannelFactory();
  //## end CETChannelFactory::Create%1034087076.body
}

void CETChannelFactory::Delete ()
{
  //## begin CETChannelFactory::Delete%1034087077.body preserve=yes
    delete m_pInstance;
    m_pInstance = NULL;
  //## end CETChannelFactory::Delete%1034087077.body
}

CETChannelFactory* CETChannelFactory::GetInstance ()
{
  //## begin CETChannelFactory::GetInstance%1034087078.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CETChannelFactory::GetInstance%1034087078.body
}

void CETChannelFactory::CreateChannels ()
{
  //## begin CETChannelFactory::CreateChannels%1034087079.body preserve=yes
    m_ChannelList.AddTail(new CETChannelObjCreator());
    m_ChannelList.AddTail(new CETChannelStepperMotors());
    m_ChannelList.AddTail(new CETChannelMeasurementChannel());
    m_ChannelList.AddTail(new CETChannelPersistentObjects());
    m_ChannelList.AddTail(new CETChannelSensors());
    m_ChannelList.AddTail(new CETChannelOutputs());
    m_ChannelList.AddTail(new CETChannelControlTemperature());
    m_ChannelList.AddTail(new CETChannelControlPower());
    m_ChannelList.AddTail(new CETChannelControlWedge());
    m_ChannelList.AddTail(new CETChannelEvents());
    m_ChannelList.AddTail(new CETChannelDiagnostics());
    m_ChannelList.AddTail(new CETChannelSystem());
    m_ChannelList.AddTail(new CETChannelI2CBus());

    // start all channels
    for (POSITION l_Pos=m_ChannelList.GetHeadPosition(); l_Pos!=NULL;)
    {
        CETChannel* l_Channel = m_ChannelList.GetNext(l_Pos);
        l_Channel->Initialize(0);
        l_Channel->Start();
    }
  //## end CETChannelFactory::CreateChannels%1034087079.body
}

//## Get and Set Operations for Associations (implementation)

CETBrowserService * CETChannelFactory::GetpBrowserService ()
{
  //## begin CETChannelFactory::GetpBrowserService%477629AE0245.get preserve=no
  return m_pBrowserService;
  //## end CETChannelFactory::GetpBrowserService%477629AE0245.get
}

// Additional Declarations
  //## begin CETChannelFactory%3DA2F3530175.declarations preserve=yes
  //## end CETChannelFactory%3DA2F3530175.declarations

// Class CETChannelMessageEnvoy 







CETChannelMessageEnvoy::CETChannelMessageEnvoy (CETChannelMessage* p_pMsg, SOCKET p_hSocket)
  //## begin CETChannelMessageEnvoy::CETChannelMessageEnvoy%1034230445.hasinit preserve=no
      : m_pMsg(p_pMsg), m_hSocket(NULL), m_pServerSyncObj(NULL)
  //## end CETChannelMessageEnvoy::CETChannelMessageEnvoy%1034230445.hasinit
  //## begin CETChannelMessageEnvoy::CETChannelMessageEnvoy%1034230445.initialization preserve=yes
  , ICORefCounting(_T("CETChannelMessageEnvoy"))
  //## end CETChannelMessageEnvoy::CETChannelMessageEnvoy%1034230445.initialization
{
  //## begin CETChannelMessageEnvoy::CETChannelMessageEnvoy%1034230445.body preserve=yes
    m_hSocket = p_hSocket;
  //## end CETChannelMessageEnvoy::CETChannelMessageEnvoy%1034230445.body
}

CETChannelMessageEnvoy::CETChannelMessageEnvoy (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj)
  //## begin CETChannelMessageEnvoy::CETChannelMessageEnvoy%1034407671.hasinit preserve=no
      : m_pMsg(p_pMsg), m_hSocket(NULL), m_pServerSyncObj(NULL)
  //## end CETChannelMessageEnvoy::CETChannelMessageEnvoy%1034407671.hasinit
  //## begin CETChannelMessageEnvoy::CETChannelMessageEnvoy%1034407671.initialization preserve=yes
  , ICORefCounting(_T("CETChannelMessageEnvoy"))
  //## end CETChannelMessageEnvoy::CETChannelMessageEnvoy%1034407671.initialization
{
  //## begin CETChannelMessageEnvoy::CETChannelMessageEnvoy%1034407671.body preserve=yes
    if (!p_pSyncObj)
    {
        // create default sync object
        m_pServerSyncObj = new CCOSyncObject(_T("ET:ChannelMessageEnvoy"));
        m_pServerSyncObj->SignalCompletion();
    }
    else
    {
        // keep sync object
        m_pServerSyncObj = p_pSyncObj;
        m_pServerSyncObj->AddRef();
    }
  //## end CETChannelMessageEnvoy::CETChannelMessageEnvoy%1034407671.body
}


CETChannelMessageEnvoy::~CETChannelMessageEnvoy()
{
  //## begin CETChannelMessageEnvoy::~CETChannelMessageEnvoy%.body preserve=yes
    if (m_pServerSyncObj)
        m_pServerSyncObj->ReleaseRef();
    m_pServerSyncObj = NULL;

    delete m_pMsg;
    m_pMsg = NULL;
  //## end CETChannelMessageEnvoy::~CETChannelMessageEnvoy%.body
}



//## Other Operations (implementation)
void CETChannelMessageEnvoy::HandleReturnValue ()
{
  //## begin CETChannelMessageEnvoy::HandleReturnValue%1037346554.body preserve=yes
    try
    {
        // handle return value and any attached exceptions
        ProcessAsyncReturnValue();
    }
    catch(XCOException* p_pException)
    {
        // supply exception info
        m_pMsg->SetuiExceptionID(p_pException->GetuiExceptionID());
        m_pMsg->SetiData(p_pException->GetdwErrorCode());
        m_pMsg->SetsObjRefVersion((WCHAR*)(LPCTSTR)p_pException->GetPlainText());
        p_pException->Delete();
    }
  //## end CETChannelMessageEnvoy::HandleReturnValue%1037346554.body
}

void CETChannelMessageEnvoy::ProcessAsyncReturnValue ()
{
  //## begin CETChannelMessageEnvoy::ProcessAsyncReturnValue%1034575095.body preserve=yes
    // check sync object for exceptions
    m_pServerSyncObj->HasException();
  //## end CETChannelMessageEnvoy::ProcessAsyncReturnValue%1034575095.body
}

//## Get and Set Operations for Associations (implementation)

CETChannelMessage * CETChannelMessageEnvoy::GetpMsg ()
{
  //## begin CETChannelMessageEnvoy::GetpMsg%3DA5494601DF.get preserve=no
  return m_pMsg;
  //## end CETChannelMessageEnvoy::GetpMsg%3DA5494601DF.get
}

SOCKET CETChannelMessageEnvoy::GethSocket ()
{
  //## begin CETChannelMessageEnvoy::GethSocket%3DA549700374.get preserve=no
  return m_hSocket;
  //## end CETChannelMessageEnvoy::GethSocket%3DA549700374.get
}

CCOSyncObject * CETChannelMessageEnvoy::GetpServerSyncObj ()
{
  //## begin CETChannelMessageEnvoy::GetpServerSyncObj%3DA6D3AA0156.get preserve=no
  return m_pServerSyncObj;
  //## end CETChannelMessageEnvoy::GetpServerSyncObj%3DA6D3AA0156.get
}

void CETChannelMessageEnvoy::SetpServerSyncObj (CCOSyncObject * value)
{
  //## begin CETChannelMessageEnvoy::SetpServerSyncObj%3DA6D3AA0156.set preserve=no
  m_pServerSyncObj = value;
  //## end CETChannelMessageEnvoy::SetpServerSyncObj%3DA6D3AA0156.set
}

// Additional Declarations
  //## begin CETChannelMessageEnvoy%3DA5492902E8.declarations preserve=yes
  //## end CETChannelMessageEnvoy%3DA5492902E8.declarations

// Class CETChannelMessageEnvoyInt 

CETChannelMessageEnvoyInt::CETChannelMessageEnvoyInt (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj)
  //## begin CETChannelMessageEnvoyInt::CETChannelMessageEnvoyInt%1034575094.hasinit preserve=no
  //## end CETChannelMessageEnvoyInt::CETChannelMessageEnvoyInt%1034575094.hasinit
  //## begin CETChannelMessageEnvoyInt::CETChannelMessageEnvoyInt%1034575094.initialization preserve=yes
: CETChannelMessageEnvoy(p_pMsg, p_pSyncObj)
  //## end CETChannelMessageEnvoyInt::CETChannelMessageEnvoyInt%1034575094.initialization
{
  //## begin CETChannelMessageEnvoyInt::CETChannelMessageEnvoyInt%1034575094.body preserve=yes
  //## end CETChannelMessageEnvoyInt::CETChannelMessageEnvoyInt%1034575094.body
}


CETChannelMessageEnvoyInt::~CETChannelMessageEnvoyInt()
{
  //## begin CETChannelMessageEnvoyInt::~CETChannelMessageEnvoyInt%.body preserve=yes
  //## end CETChannelMessageEnvoyInt::~CETChannelMessageEnvoyInt%.body
}



//## Other Operations (implementation)
void CETChannelMessageEnvoyInt::ProcessAsyncReturnValue ()
{
  //## begin CETChannelMessageEnvoyInt::ProcessAsyncReturnValue%1034575096.body preserve=yes
    // check for exceptions
    CETChannelMessageEnvoy::ProcessAsyncReturnValue();

    ASSERT(m_pServerSyncObj != NULL);

    // expect integer return value
    CCOSyncObjectInt* l_pSyncObj = dynamic_cast<CCOSyncObjectInt*>(m_pServerSyncObj);
    ASSERT(l_pSyncObj != NULL);
    m_pMsg->SetiData(l_pSyncObj->GetValue());
  //## end CETChannelMessageEnvoyInt::ProcessAsyncReturnValue%1034575096.body
}

// Additional Declarations
  //## begin CETChannelMessageEnvoyInt%3DAA82B90275.declarations preserve=yes
  //## end CETChannelMessageEnvoyInt%3DAA82B90275.declarations

// Class CETChannelMessageEnvoyMeasurementDataPackage 

CETChannelMessageEnvoyMeasurementDataPackage::CETChannelMessageEnvoyMeasurementDataPackage (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj)
  //## begin CETChannelMessageEnvoyMeasurementDataPackage::CETChannelMessageEnvoyMeasurementDataPackage%1034922743.hasinit preserve=no
  //## end CETChannelMessageEnvoyMeasurementDataPackage::CETChannelMessageEnvoyMeasurementDataPackage%1034922743.hasinit
  //## begin CETChannelMessageEnvoyMeasurementDataPackage::CETChannelMessageEnvoyMeasurementDataPackage%1034922743.initialization preserve=yes
: CETChannelMessageEnvoy(p_pMsg, p_pSyncObj)
  //## end CETChannelMessageEnvoyMeasurementDataPackage::CETChannelMessageEnvoyMeasurementDataPackage%1034922743.initialization
{
  //## begin CETChannelMessageEnvoyMeasurementDataPackage::CETChannelMessageEnvoyMeasurementDataPackage%1034922743.body preserve=yes
  //## end CETChannelMessageEnvoyMeasurementDataPackage::CETChannelMessageEnvoyMeasurementDataPackage%1034922743.body
}


CETChannelMessageEnvoyMeasurementDataPackage::~CETChannelMessageEnvoyMeasurementDataPackage()
{
  //## begin CETChannelMessageEnvoyMeasurementDataPackage::~CETChannelMessageEnvoyMeasurementDataPackage%.body preserve=yes
  //## end CETChannelMessageEnvoyMeasurementDataPackage::~CETChannelMessageEnvoyMeasurementDataPackage%.body
}



//## Other Operations (implementation)
void CETChannelMessageEnvoyMeasurementDataPackage::ProcessAsyncReturnValue ()
{
  //## begin CETChannelMessageEnvoyMeasurementDataPackage::ProcessAsyncReturnValue%1034922744.body preserve=yes
    // check for exceptions
    CETChannelMessageEnvoy::ProcessAsyncReturnValue();

    CPISyncObjDataPackage* l_pSyncObj = dynamic_cast<CPISyncObjDataPackage*>(m_pServerSyncObj);
    ASSERT(l_pSyncObj != NULL);
    CETChannelMessageMeasurementDataPackage* l_pMsg = (CETChannelMessageMeasurementDataPackage*)m_pMsg;

    if (l_pSyncObj->HasValue())
        l_pMsg->SetpDataPackage(l_pSyncObj->GetValue());
  //## end CETChannelMessageEnvoyMeasurementDataPackage::ProcessAsyncReturnValue%1034922744.body
}

// Additional Declarations
  //## begin CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.declarations preserve=yes
  //## end CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.declarations

// Class CETChannelMessageEnvoyStepperLimitFootPrint 

CETChannelMessageEnvoyStepperLimitFootPrint::CETChannelMessageEnvoyStepperLimitFootPrint (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj)
  //## begin CETChannelMessageEnvoyStepperLimitFootPrint::CETChannelMessageEnvoyStepperLimitFootPrint%1036738403.hasinit preserve=no
  //## end CETChannelMessageEnvoyStepperLimitFootPrint::CETChannelMessageEnvoyStepperLimitFootPrint%1036738403.hasinit
  //## begin CETChannelMessageEnvoyStepperLimitFootPrint::CETChannelMessageEnvoyStepperLimitFootPrint%1036738403.initialization preserve=yes
: CETChannelMessageEnvoy(p_pMsg, p_pSyncObj)
  //## end CETChannelMessageEnvoyStepperLimitFootPrint::CETChannelMessageEnvoyStepperLimitFootPrint%1036738403.initialization
{
  //## begin CETChannelMessageEnvoyStepperLimitFootPrint::CETChannelMessageEnvoyStepperLimitFootPrint%1036738403.body preserve=yes
  //## end CETChannelMessageEnvoyStepperLimitFootPrint::CETChannelMessageEnvoyStepperLimitFootPrint%1036738403.body
}


CETChannelMessageEnvoyStepperLimitFootPrint::~CETChannelMessageEnvoyStepperLimitFootPrint()
{
  //## begin CETChannelMessageEnvoyStepperLimitFootPrint::~CETChannelMessageEnvoyStepperLimitFootPrint%.body preserve=yes
  //## end CETChannelMessageEnvoyStepperLimitFootPrint::~CETChannelMessageEnvoyStepperLimitFootPrint%.body
}



//## Other Operations (implementation)
void CETChannelMessageEnvoyStepperLimitFootPrint::ProcessAsyncReturnValue ()
{
  //## begin CETChannelMessageEnvoyStepperLimitFootPrint::ProcessAsyncReturnValue%1036738404.body preserve=yes
    // check for exceptions
    CETChannelMessageEnvoy::ProcessAsyncReturnValue();

    CCOSyncObjectIntArray* l_pSyncObj = dynamic_cast<CCOSyncObjectIntArray*>(m_pServerSyncObj);
    ASSERT(l_pSyncObj != NULL);
    CETChannelMessageStepperLimitFootPrint* l_pMsg = (CETChannelMessageStepperLimitFootPrint*)m_pMsg;

    l_pMsg->SetpFootPrint(l_pSyncObj->GetValue());
  //## end CETChannelMessageEnvoyStepperLimitFootPrint::ProcessAsyncReturnValue%1036738404.body
}

// Additional Declarations
  //## begin CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.declarations preserve=yes
  //## end CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.declarations

// Class CETChannelMessageEnvoyBool 

CETChannelMessageEnvoyBool::CETChannelMessageEnvoyBool (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj)
  //## begin CETChannelMessageEnvoyBool::CETChannelMessageEnvoyBool%1037346569.hasinit preserve=no
  //## end CETChannelMessageEnvoyBool::CETChannelMessageEnvoyBool%1037346569.hasinit
  //## begin CETChannelMessageEnvoyBool::CETChannelMessageEnvoyBool%1037346569.initialization preserve=yes
: CETChannelMessageEnvoy(p_pMsg, p_pSyncObj)
  //## end CETChannelMessageEnvoyBool::CETChannelMessageEnvoyBool%1037346569.initialization
{
  //## begin CETChannelMessageEnvoyBool::CETChannelMessageEnvoyBool%1037346569.body preserve=yes
  //## end CETChannelMessageEnvoyBool::CETChannelMessageEnvoyBool%1037346569.body
}


CETChannelMessageEnvoyBool::~CETChannelMessageEnvoyBool()
{
  //## begin CETChannelMessageEnvoyBool::~CETChannelMessageEnvoyBool%.body preserve=yes
  //## end CETChannelMessageEnvoyBool::~CETChannelMessageEnvoyBool%.body
}



//## Other Operations (implementation)
void CETChannelMessageEnvoyBool::ProcessAsyncReturnValue ()
{
  //## begin CETChannelMessageEnvoyBool::ProcessAsyncReturnValue%1037346570.body preserve=yes
    // check for exceptions
    CETChannelMessageEnvoy::ProcessAsyncReturnValue();

    ASSERT(m_pServerSyncObj != NULL);

    // expect integer return value
    CCOSyncObjectBool* l_pSyncObj = dynamic_cast<CCOSyncObjectBool*>(m_pServerSyncObj);
    ASSERT(l_pSyncObj != NULL);
    m_pMsg->SetiData(l_pSyncObj->GetValue());
  //## end CETChannelMessageEnvoyBool::ProcessAsyncReturnValue%1037346570.body
}

// Additional Declarations
  //## begin CETChannelMessageEnvoyBool%3DD4EC600336.declarations preserve=yes
  //## end CETChannelMessageEnvoyBool%3DD4EC600336.declarations

// Class CETChannelMessageEnvoyPersistentIdentification 

CETChannelMessageEnvoyPersistentIdentification::CETChannelMessageEnvoyPersistentIdentification (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj)
  //## begin CETChannelMessageEnvoyPersistentIdentification::CETChannelMessageEnvoyPersistentIdentification%1039528816.hasinit preserve=no
  //## end CETChannelMessageEnvoyPersistentIdentification::CETChannelMessageEnvoyPersistentIdentification%1039528816.hasinit
  //## begin CETChannelMessageEnvoyPersistentIdentification::CETChannelMessageEnvoyPersistentIdentification%1039528816.initialization preserve=yes
: CETChannelMessageEnvoy(p_pMsg, p_pSyncObj)
  //## end CETChannelMessageEnvoyPersistentIdentification::CETChannelMessageEnvoyPersistentIdentification%1039528816.initialization
{
  //## begin CETChannelMessageEnvoyPersistentIdentification::CETChannelMessageEnvoyPersistentIdentification%1039528816.body preserve=yes
  //## end CETChannelMessageEnvoyPersistentIdentification::CETChannelMessageEnvoyPersistentIdentification%1039528816.body
}


CETChannelMessageEnvoyPersistentIdentification::~CETChannelMessageEnvoyPersistentIdentification()
{
  //## begin CETChannelMessageEnvoyPersistentIdentification::~CETChannelMessageEnvoyPersistentIdentification%.body preserve=yes
  //## end CETChannelMessageEnvoyPersistentIdentification::~CETChannelMessageEnvoyPersistentIdentification%.body
}



//## Other Operations (implementation)
void CETChannelMessageEnvoyPersistentIdentification::ProcessAsyncReturnValue ()
{
  //## begin CETChannelMessageEnvoyPersistentIdentification::ProcessAsyncReturnValue%1039528817.body preserve=yes
    // check for exceptions
    CETChannelMessageEnvoy::ProcessAsyncReturnValue();

    CPISyncObjListPersistentItems* l_pSyncObj = dynamic_cast<CPISyncObjListPersistentItems*>(m_pServerSyncObj);
    ASSERT(l_pSyncObj != NULL);
    CETChannelMessagePersistentIdentification* l_pMsg = (CETChannelMessagePersistentIdentification*)m_pMsg;

    l_pMsg->SetpPersistentIdentification(l_pSyncObj->GetValue());
  //## end CETChannelMessageEnvoyPersistentIdentification::ProcessAsyncReturnValue%1039528817.body
}

// Additional Declarations
  //## begin CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.declarations preserve=yes
  //## end CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.declarations

// Class CETChannelMessageEnvoyPersistentParameter 

CETChannelMessageEnvoyPersistentParameter::CETChannelMessageEnvoyPersistentParameter (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj)
  //## begin CETChannelMessageEnvoyPersistentParameter::CETChannelMessageEnvoyPersistentParameter%1039528818.hasinit preserve=no
  //## end CETChannelMessageEnvoyPersistentParameter::CETChannelMessageEnvoyPersistentParameter%1039528818.hasinit
  //## begin CETChannelMessageEnvoyPersistentParameter::CETChannelMessageEnvoyPersistentParameter%1039528818.initialization preserve=yes
: CETChannelMessageEnvoy(p_pMsg, p_pSyncObj)
  //## end CETChannelMessageEnvoyPersistentParameter::CETChannelMessageEnvoyPersistentParameter%1039528818.initialization
{
  //## begin CETChannelMessageEnvoyPersistentParameter::CETChannelMessageEnvoyPersistentParameter%1039528818.body preserve=yes
  //## end CETChannelMessageEnvoyPersistentParameter::CETChannelMessageEnvoyPersistentParameter%1039528818.body
}


CETChannelMessageEnvoyPersistentParameter::~CETChannelMessageEnvoyPersistentParameter()
{
  //## begin CETChannelMessageEnvoyPersistentParameter::~CETChannelMessageEnvoyPersistentParameter%.body preserve=yes
  //## end CETChannelMessageEnvoyPersistentParameter::~CETChannelMessageEnvoyPersistentParameter%.body
}



//## Other Operations (implementation)
void CETChannelMessageEnvoyPersistentParameter::ProcessAsyncReturnValue ()
{
  //## begin CETChannelMessageEnvoyPersistentParameter::ProcessAsyncReturnValue%1039528819.body preserve=yes
    // check for exceptions
    CETChannelMessageEnvoy::ProcessAsyncReturnValue();

    CPISyncObjListPersistentItems* l_pSyncObj = dynamic_cast<CPISyncObjListPersistentItems*>(m_pServerSyncObj);
    ASSERT(l_pSyncObj != NULL);
    CETChannelMessagePersistentParameter* l_pMsg = (CETChannelMessagePersistentParameter*)m_pMsg;

    l_pMsg->SetpPersistentParameter(l_pSyncObj->GetValue());
  //## end CETChannelMessageEnvoyPersistentParameter::ProcessAsyncReturnValue%1039528819.body
}

// Additional Declarations
  //## begin CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.declarations preserve=yes
  //## end CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.declarations

// Class CETChannelMessageEnvoyPersistentSoftwareComponentVersion 

CETChannelMessageEnvoyPersistentSoftwareComponentVersion::CETChannelMessageEnvoyPersistentSoftwareComponentVersion (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj)
  //## begin CETChannelMessageEnvoyPersistentSoftwareComponentVersion::CETChannelMessageEnvoyPersistentSoftwareComponentVersion%1039528820.hasinit preserve=no
  //## end CETChannelMessageEnvoyPersistentSoftwareComponentVersion::CETChannelMessageEnvoyPersistentSoftwareComponentVersion%1039528820.hasinit
  //## begin CETChannelMessageEnvoyPersistentSoftwareComponentVersion::CETChannelMessageEnvoyPersistentSoftwareComponentVersion%1039528820.initialization preserve=yes
: CETChannelMessageEnvoy(p_pMsg, p_pSyncObj)
  //## end CETChannelMessageEnvoyPersistentSoftwareComponentVersion::CETChannelMessageEnvoyPersistentSoftwareComponentVersion%1039528820.initialization
{
  //## begin CETChannelMessageEnvoyPersistentSoftwareComponentVersion::CETChannelMessageEnvoyPersistentSoftwareComponentVersion%1039528820.body preserve=yes
  //## end CETChannelMessageEnvoyPersistentSoftwareComponentVersion::CETChannelMessageEnvoyPersistentSoftwareComponentVersion%1039528820.body
}


CETChannelMessageEnvoyPersistentSoftwareComponentVersion::~CETChannelMessageEnvoyPersistentSoftwareComponentVersion()
{
  //## begin CETChannelMessageEnvoyPersistentSoftwareComponentVersion::~CETChannelMessageEnvoyPersistentSoftwareComponentVersion%.body preserve=yes
  //## end CETChannelMessageEnvoyPersistentSoftwareComponentVersion::~CETChannelMessageEnvoyPersistentSoftwareComponentVersion%.body
}



//## Other Operations (implementation)
void CETChannelMessageEnvoyPersistentSoftwareComponentVersion::ProcessAsyncReturnValue ()
{
  //## begin CETChannelMessageEnvoyPersistentSoftwareComponentVersion::ProcessAsyncReturnValue%1039528821.body preserve=yes
    // check for exceptions
    CETChannelMessageEnvoy::ProcessAsyncReturnValue();

    CPISyncObjListSWCompVersion* l_pSyncObj = dynamic_cast<CPISyncObjListSWCompVersion*>(m_pServerSyncObj);
    ASSERT(l_pSyncObj != NULL);
    CETChannelMessagePersistentSoftwareComponentVersion* l_pMsg = (CETChannelMessagePersistentSoftwareComponentVersion*)m_pMsg;

    CPIPersistentSoftwareComponentVersionList* l_pList = l_pSyncObj->GetValue();
    l_pMsg->SetComponentVersions(l_pList->GetComponentVersions());
    l_pList->ReleaseRef();
  //## end CETChannelMessageEnvoyPersistentSoftwareComponentVersion::ProcessAsyncReturnValue%1039528821.body
}

// Additional Declarations
  //## begin CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.declarations preserve=yes
  //## end CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.declarations

// Class CETChannelMessageEnvoySystemGetObjectList 

CETChannelMessageEnvoySystemGetObjectList::CETChannelMessageEnvoySystemGetObjectList (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj)
  //## begin CETChannelMessageEnvoySystemGetObjectList::CETChannelMessageEnvoySystemGetObjectList%1063715465.hasinit preserve=no
  //## end CETChannelMessageEnvoySystemGetObjectList::CETChannelMessageEnvoySystemGetObjectList%1063715465.hasinit
  //## begin CETChannelMessageEnvoySystemGetObjectList::CETChannelMessageEnvoySystemGetObjectList%1063715465.initialization preserve=yes
: CETChannelMessageEnvoy(p_pMsg, p_pSyncObj)
  //## end CETChannelMessageEnvoySystemGetObjectList::CETChannelMessageEnvoySystemGetObjectList%1063715465.initialization
{
  //## begin CETChannelMessageEnvoySystemGetObjectList::CETChannelMessageEnvoySystemGetObjectList%1063715465.body preserve=yes
  //## end CETChannelMessageEnvoySystemGetObjectList::CETChannelMessageEnvoySystemGetObjectList%1063715465.body
}


CETChannelMessageEnvoySystemGetObjectList::~CETChannelMessageEnvoySystemGetObjectList()
{
  //## begin CETChannelMessageEnvoySystemGetObjectList::~CETChannelMessageEnvoySystemGetObjectList%.body preserve=yes
  //## end CETChannelMessageEnvoySystemGetObjectList::~CETChannelMessageEnvoySystemGetObjectList%.body
}



//## Other Operations (implementation)
void CETChannelMessageEnvoySystemGetObjectList::ProcessAsyncReturnValue ()
{
  //## begin CETChannelMessageEnvoySystemGetObjectList::ProcessAsyncReturnValue%1063715466.body preserve=yes
    // check for exceptions
    CETChannelMessageEnvoy::ProcessAsyncReturnValue();

    CPISyncObjectStringArray* l_pSyncObj = dynamic_cast<CPISyncObjectStringArray*>(m_pServerSyncObj);
    ASSERT(l_pSyncObj != NULL);
    CETChannelMessageSystemGetObjectList* l_pMsg = (CETChannelMessageSystemGetObjectList*)m_pMsg;

    l_pMsg->SetpObjList(l_pSyncObj->GetValue());
  //## end CETChannelMessageEnvoySystemGetObjectList::ProcessAsyncReturnValue%1063715466.body
}

// Additional Declarations
  //## begin CETChannelMessageEnvoySystemGetObjectList%3F6728910377.declarations preserve=yes
  //## end CETChannelMessageEnvoySystemGetObjectList%3F6728910377.declarations

// Class CETChannelMessageEnvoyI2CAdcMax1037 

CETChannelMessageEnvoyI2CAdcMax1037::CETChannelMessageEnvoyI2CAdcMax1037 (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj)
  //## begin CETChannelMessageEnvoyI2CAdcMax1037::CETChannelMessageEnvoyI2CAdcMax1037%1074861339.hasinit preserve=no
  //## end CETChannelMessageEnvoyI2CAdcMax1037::CETChannelMessageEnvoyI2CAdcMax1037%1074861339.hasinit
  //## begin CETChannelMessageEnvoyI2CAdcMax1037::CETChannelMessageEnvoyI2CAdcMax1037%1074861339.initialization preserve=yes
: CETChannelMessageEnvoy(p_pMsg, p_pSyncObj)
  //## end CETChannelMessageEnvoyI2CAdcMax1037::CETChannelMessageEnvoyI2CAdcMax1037%1074861339.initialization
{
  //## begin CETChannelMessageEnvoyI2CAdcMax1037::CETChannelMessageEnvoyI2CAdcMax1037%1074861339.body preserve=yes
  //## end CETChannelMessageEnvoyI2CAdcMax1037::CETChannelMessageEnvoyI2CAdcMax1037%1074861339.body
}


CETChannelMessageEnvoyI2CAdcMax1037::~CETChannelMessageEnvoyI2CAdcMax1037()
{
  //## begin CETChannelMessageEnvoyI2CAdcMax1037::~CETChannelMessageEnvoyI2CAdcMax1037%.body preserve=yes
  //## end CETChannelMessageEnvoyI2CAdcMax1037::~CETChannelMessageEnvoyI2CAdcMax1037%.body
}



//## Other Operations (implementation)
void CETChannelMessageEnvoyI2CAdcMax1037::ProcessAsyncReturnValue ()
{
  //## begin CETChannelMessageEnvoyI2CAdcMax1037::ProcessAsyncReturnValue%1074861340.body preserve=yes
    // check for exceptions
    CETChannelMessageEnvoy::ProcessAsyncReturnValue();

    CPISyncObjDataADCMAX1037* l_pSyncObj = dynamic_cast<CPISyncObjDataADCMAX1037*>(m_pServerSyncObj);
    ASSERT(l_pSyncObj != NULL);
    CETChannelMessageI2CAdcMax1037* l_pMsg = (CETChannelMessageI2CAdcMax1037*)m_pMsg;

    l_pMsg->SetpDataAdc(l_pSyncObj->GetValue());
  //## end CETChannelMessageEnvoyI2CAdcMax1037::ProcessAsyncReturnValue%1074861340.body
}

// Additional Declarations
  //## begin CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.declarations preserve=yes
  //## end CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.declarations

// Class CETChannelMessageEnvoyString 

CETChannelMessageEnvoyString::CETChannelMessageEnvoyString (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj)
  //## begin CETChannelMessageEnvoyString::CETChannelMessageEnvoyString%1095233134.hasinit preserve=no
  //## end CETChannelMessageEnvoyString::CETChannelMessageEnvoyString%1095233134.hasinit
  //## begin CETChannelMessageEnvoyString::CETChannelMessageEnvoyString%1095233134.initialization preserve=yes
  : CETChannelMessageEnvoy(p_pMsg, p_pSyncObj)
  //## end CETChannelMessageEnvoyString::CETChannelMessageEnvoyString%1095233134.initialization
{
  //## begin CETChannelMessageEnvoyString::CETChannelMessageEnvoyString%1095233134.body preserve=yes
  //## end CETChannelMessageEnvoyString::CETChannelMessageEnvoyString%1095233134.body
}


CETChannelMessageEnvoyString::~CETChannelMessageEnvoyString()
{
  //## begin CETChannelMessageEnvoyString::~CETChannelMessageEnvoyString%.body preserve=yes
  //## end CETChannelMessageEnvoyString::~CETChannelMessageEnvoyString%.body
}



//## Other Operations (implementation)
void CETChannelMessageEnvoyString::ProcessAsyncReturnValue ()
{
  //## begin CETChannelMessageEnvoyString::ProcessAsyncReturnValue%1095233135.body preserve=yes
    // check for exceptions
    CETChannelMessageEnvoy::ProcessAsyncReturnValue();

    ASSERT(m_pServerSyncObj != NULL);

    // expect string return value
    CCOSyncObjectCString* l_pSyncObj = dynamic_cast<CCOSyncObjectCString*>(m_pServerSyncObj);
    ASSERT(l_pSyncObj != NULL);
    ((CETChannelMessageString*)m_pMsg)->SetsString(l_pSyncObj->GetValue());
  //## end CETChannelMessageEnvoyString::ProcessAsyncReturnValue%1095233135.body
}

// Additional Declarations
  //## begin CETChannelMessageEnvoyString%4148088C0213.declarations preserve=yes
  //## end CETChannelMessageEnvoyString%4148088C0213.declarations

// Class CETClient 




CETClient::CETClient (SOCKET p_hClient)
  //## begin CETClient::CETClient%1182934535.hasinit preserve=no
      : m_hClient(p_hClient)
  //## end CETClient::CETClient%1182934535.hasinit
  //## begin CETClient::CETClient%1182934535.initialization preserve=yes
  //## end CETClient::CETClient%1182934535.initialization
{
  //## begin CETClient::CETClient%1182934535.body preserve=yes
  //## end CETClient::CETClient%1182934535.body
}


CETClient::~CETClient()
{
  //## begin CETClient::~CETClient%.body preserve=yes
  //## end CETClient::~CETClient%.body
}


//## Get and Set Operations for Class Attributes (implementation)

const CString CETClient::GetsName () const
{
  //## begin CETClient::GetsName%4682255B0299.get preserve=no
  return m_sName;
  //## end CETClient::GetsName%4682255B0299.get
}

void CETClient::SetsName (CString value)
{
  //## begin CETClient::SetsName%4682255B0299.set preserve=no
  m_sName = value;
  //## end CETClient::SetsName%4682255B0299.set
}

//## Get and Set Operations for Associations (implementation)

SOCKET CETClient::GethClient ()
{
  //## begin CETClient::GethClient%46822592025D.get preserve=no
  return m_hClient;
  //## end CETClient::GethClient%46822592025D.get
}

// Additional Declarations
  //## begin CETClient%468225410089.declarations preserve=yes
  //## end CETClient%468225410089.declarations

//## begin module%3D9D884C0096.epilog preserve=yes
//## end module%3D9D884C0096.epilog
