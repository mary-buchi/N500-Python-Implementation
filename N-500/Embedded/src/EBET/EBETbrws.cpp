//## begin module%47761E340395.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%47761E340395.cm

//## begin module%47761E340395.cp preserve=no
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
//## end module%47761E340395.cp

//## Module: EBETbrws%47761E340395; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETbrws.cpp

// stdafx
#include "stdafx.h"
//## begin module%47761E340395.additionalIncludes preserve=no
//## end module%47761E340395.additionalIncludes

//## begin module%47761E340395.includes preserve=yes
#include "Iphlpapi.h"
//## end module%47761E340395.includes

// EBETbrws
#include "EBETbrws.h"
// EBPIfact
#include "EBPIfact.h"
// EBPIintf
#include "EBPIintf.h"
// EBCOexcp
#include "EBCOexcp.h"


//## begin module%47761E340395.declarations preserve=no
//## end module%47761E340395.declarations

//## begin module%47761E340395.additionalDeclarations preserve=yes
//## end module%47761E340395.additionalDeclarations


// Class CETBrowserService 











CETBrowserService::CETBrowserService()
  //## begin CETBrowserService::CETBrowserService%.hasinit preserve=no
      : m_iPortNo(51229), m_sScanMessage(_T("Buchi DeviceScan")), m_sScanMessageReply(_T("Buchi DeviceScan Reply")), m_uiInstrumentEpromID(5006), m_sIPAddress(_T("????")), m_sArticleNo(_T("46210")), m_sSerialNo(_T("????")), m_hSocket(NULL), m_hEvent(NULL)
  //## end CETBrowserService::CETBrowserService%.hasinit
  //## begin CETBrowserService::CETBrowserService%.initialization preserve=yes
  , CETThread(_T("Browser Service"))
  //## end CETBrowserService::CETBrowserService%.initialization
{
  //## begin CETBrowserService::CETBrowserService%.body preserve=yes
    m_hEvent = ::CreateEvent(NULL, false, false, NULL);

    InitializeAdapterInfo();
    InitializeSerialNo();
  //## end CETBrowserService::CETBrowserService%.body
}


CETBrowserService::~CETBrowserService()
{
  //## begin CETBrowserService::~CETBrowserService%.body preserve=yes
    if (m_hEvent != NULL)
        ::CloseHandle(m_hEvent);
    m_hEvent = NULL;
    if (m_hSocket != NULL && m_hSocket != INVALID_SOCKET)
        ::closesocket(m_hSocket);
    m_hSocket = NULL;
  //## end CETBrowserService::~CETBrowserService%.body
}



//## Other Operations (implementation)
DWORD CETBrowserService::ThreadMain ()
{
  //## begin CETBrowserService::ThreadMain%1198923433.body preserve=yes
    if ((m_hSocket = socket (AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) 
    {
		AfxTrace(_T("Allocating socket failed! Error: %d\n"), WSAGetLastError());
        return -1;
    }

    if (WSAEventSelect(m_hSocket, m_hEvent, FD_READ) == SOCKET_ERROR) 
    {
		AfxTrace(_T("Allocating socket failed! Error: %d\n"), WSAGetLastError());
        return -1;
    }

	int l_bOptVal = 1;
	if (::setsockopt(m_hSocket, SOL_SOCKET, SO_BROADCAST, (char*)&l_bOptVal, sizeof(int)) == SOCKET_ERROR)
	{
		AfxTrace(_T("setsockopt failed! Error: %d\n"), WSAGetLastError());
        return -1;
	}
	if (::setsockopt(m_hSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&l_bOptVal, sizeof(int)) == SOCKET_ERROR)
	{
		AfxTrace(_T("setsockopt failed! Error: %d\n"), WSAGetLastError());
        return -1;
	}

    // Fill out the local socket's address information.
    SOCKADDR_IN local_sin;
    local_sin.sin_family = AF_INET;
    local_sin.sin_port = htons (m_iPortNo);  
    local_sin.sin_addr.s_addr = htonl (INADDR_ANY);

    // Associate the local address with Sock.
    if (bind (m_hSocket, 
        (struct sockaddr FAR *) &local_sin, 
        sizeof (local_sin)) == SOCKET_ERROR) 
    {
		AfxTrace(_T("Allocating socket failed! Error: %d\n"), WSAGetLastError());
        return -1;
    }

	SendHello();

    bool l_bRunning = true;
    HANDLE l_WaitHandles[] = { m_hTerminationEvent, m_hEvent };
    while(l_bRunning)
    {
        int l_iSignalledIndex = ::WaitForMultipleObjects(2, l_WaitHandles, false, INFINITE);
        switch(l_iSignalledIndex)
        {
			case WAIT_OBJECT_0+0:
				// terminate thread
				SendGoodbye();
				l_bRunning = false;
				break;

			case WAIT_OBJECT_0+1:
				// ::ResetEvent(m_hEvent);
                ReadData();
				break;

			default:
				ASSERT(FALSE);
        }  
    }

    return 0;
  //## end CETBrowserService::ThreadMain%1198923433.body
}

void CETBrowserService::ReadData ()
{
  //## begin CETBrowserService::ReadData%1198923434.body preserve=yes
    char l_Buffer[4096];
	memset(l_Buffer, 0, sizeof(l_Buffer));
    SOCKADDR_IN recv_sin;
    int iRecvLen = sizeof (recv_sin);

	int l_iReturn = 0;
    if ((l_iReturn = recvfrom(m_hSocket, 
        l_Buffer,
        sizeof(l_Buffer),         
        0,
        (struct sockaddr FAR *) &recv_sin,
        &iRecvLen)) == SOCKET_ERROR)
    {
		// master has probably closed connection
		AfxTrace(_T("recvfrom failed! Error: %d\n"), WSAGetLastError());
        return;
    }
    else
    {
		WCHAR l_sUnicodeBuffer[4096];
		::MultiByteToWideChar(CP_ACP, 0, l_Buffer, l_iReturn, l_sUnicodeBuffer, sizeof(l_sUnicodeBuffer));
        CString l_sText; CString l_sHostIP;
        if (SplitMessage(l_sUnicodeBuffer, l_sText, l_sHostIP))
        {
            if (l_sText == m_sScanMessage)
            {
                char l_sDestIP[256];
				memset(l_sDestIP, 0, sizeof(l_sDestIP));
                ::WideCharToMultiByte(
                        CP_ACP, 0, 
                        (LPCTSTR)l_sHostIP,
                        l_sHostIP.GetLength(),
                        l_sDestIP,  
                        sizeof(l_sDestIP), NULL, NULL);

                // Fill out the desination socket's address information.
                SOCKADDR_IN dest_sin;
                dest_sin.sin_family = AF_INET;
                dest_sin.sin_port = htons (m_iPortNo+1);  
                dest_sin.sin_addr.s_addr = inet_addr (l_sDestIP);

                if (m_sIPAddress == _T("????"))
                {
                    // re-read adapter info
                    InitializeAdapterInfo();
                }

				char l_sAnsiBuffer[1024];
				memset(l_sAnsiBuffer, 0, sizeof(l_sAnsiBuffer));
                CString l_sReply = _T("Text=") + m_sScanMessageReply + _T(";HostIP=") + m_sIPAddress + _T(";ArticleNo=") + m_sArticleNo +_T(";SerialNo=") + m_sSerialNo + _T(";IsSBC=false") + _T(";@");
				::WideCharToMultiByte(CP_ACP, 0, (LPCTSTR)l_sReply, l_sReply.GetLength(), (LPSTR)l_sAnsiBuffer, sizeof(l_sAnsiBuffer), NULL, NULL);

                // Send a message to the multicasting address.
                if (sendto (m_hSocket, 
                    l_sAnsiBuffer,
                    strlen(l_sAnsiBuffer),
                    0,
                    (struct sockaddr FAR *) &dest_sin,
                    sizeof (dest_sin)) == SOCKET_ERROR)
                {
					// master has probably closed connection
					AfxTrace(_T("recvfrom failed! Error: %d\n"), WSAGetLastError());
                }
            }
        }
    }
  //## end CETBrowserService::ReadData%1198923434.body
}

void CETBrowserService::SendHello ()
{
  //## begin CETBrowserService::SendHello%1241507175.body preserve=yes
	char l_sAnsiBuffer[1024];
	memset(l_sAnsiBuffer, 0, sizeof(l_sAnsiBuffer));
    CString l_sMessage = _T("Text=Buchi Device Hello;HostIP=") + m_sIPAddress + _T(";ArticleNo=") + m_sArticleNo +_T(";SerialNo=") + m_sSerialNo + _T(";IsSBC=false") + _T(";@");
	::WideCharToMultiByte(CP_ACP, 0, (LPCTSTR)l_sMessage, l_sMessage.GetLength(), (LPSTR)l_sAnsiBuffer, sizeof(l_sAnsiBuffer), NULL, NULL);

    SOCKADDR_IN dest_sin;
    dest_sin.sin_family = AF_INET;
    dest_sin.sin_port = htons (m_iPortNo+1);  
    dest_sin.sin_addr.s_addr = INADDR_BROADCAST;

	if (sendto(m_hSocket, 
		l_sAnsiBuffer,
		strlen(l_sAnsiBuffer),
		0,
		(struct sockaddr*)&dest_sin,
		sizeof(dest_sin)) == SOCKET_ERROR)
	{
		// master has probably closed connection
		AfxTrace(_T("send failed! Error: %d\n"), WSAGetLastError());
	}
  //## end CETBrowserService::SendHello%1241507175.body
}

void CETBrowserService::SendGoodbye ()
{
  //## begin CETBrowserService::SendGoodbye%1241507176.body preserve=yes
	char l_sAnsiBuffer[1024];
	memset(l_sAnsiBuffer, 0, sizeof(l_sAnsiBuffer));
    CString l_sMessage = _T("Text=Buchi Device Goodbye;HostIP=") + m_sIPAddress + _T(";ArticleNo=") + m_sArticleNo +_T(";SerialNo=") + m_sSerialNo + _T(";IsSBC=false") + _T(";@");
	::WideCharToMultiByte(CP_ACP, 0, (LPCTSTR)l_sMessage, l_sMessage.GetLength(), (LPSTR)l_sAnsiBuffer, sizeof(l_sAnsiBuffer), NULL, NULL);

	bool l_bOptVal = true;
	if (::setsockopt(m_hSocket, SOL_SOCKET, SO_BROADCAST, (char*)&l_bOptVal, sizeof(bool)) == SOCKET_ERROR)
	{
		AfxTrace(_T("setsockopt failed! Error: %d\n"), WSAGetLastError());
	}

    SOCKADDR_IN dest_sin;
    dest_sin.sin_family = AF_INET;
    dest_sin.sin_port = htons (m_iPortNo+1);  
    dest_sin.sin_addr.s_addr = INADDR_BROADCAST;

	if (sendto(m_hSocket, 
		l_sAnsiBuffer,
		strlen(l_sAnsiBuffer),
		0,
		(struct sockaddr*)&dest_sin,
		sizeof(dest_sin)) == SOCKET_ERROR)
	{
		// master has probably closed connection
		AfxTrace(_T("send failed! Error: %d\n"), WSAGetLastError());
	}
  //## end CETBrowserService::SendGoodbye%1241507176.body
}

bool CETBrowserService::SplitMessage (const CString& p_sMsg, CString& p_sText, CString& p_sHostIP)
{
  //## begin CETBrowserService::SplitMessage%1198923435.body preserve=yes
    int l_iStartIdx = p_sMsg.Find(_T("Text="));
    if (l_iStartIdx == -1)
        return false;
    int l_iEndIdx = p_sMsg.Find(_T(';'), l_iStartIdx + 5);
    if (l_iEndIdx == -1)
        return false;
    p_sText = p_sMsg.Mid(l_iStartIdx+5, l_iEndIdx - l_iStartIdx - 5);

    l_iStartIdx = p_sMsg.Find(_T("HostIP="), l_iEndIdx);
    if (l_iStartIdx == -1)
        return false;
    l_iEndIdx = p_sMsg.Find(_T(';'), l_iStartIdx + 7);
    if (l_iEndIdx == -1)
        return false;
    p_sHostIP = p_sMsg.Mid(l_iStartIdx+7, l_iEndIdx - l_iStartIdx - 7);

    return true;
  //## end CETBrowserService::SplitMessage%1198923435.body
}

void CETBrowserService::InitializeAdapterInfo ()
{
  //## begin CETBrowserService::InitializeAdapterInfo%1198923436.body preserve=yes
    BYTE* l_pBuffer = NULL;
    ULONG l_ulBufferSize = 0;
    PIP_ADAPTER_ADDRESSES l_pAddresses = NULL;

    ::GetAdaptersAddresses(AF_INET, 0, NULL, l_pAddresses, &l_ulBufferSize);
    l_pBuffer = new BYTE[l_ulBufferSize];
    l_pAddresses = (PIP_ADAPTER_ADDRESSES)l_pBuffer;
    if (GetAdaptersAddresses(AF_INET, 0, NULL, l_pAddresses, &l_ulBufferSize) != ERROR_SUCCESS)
    {
        m_sIPAddress = _T("????");
    }
	else
	{
		PIP_ADAPTER_ADDRESSES l_pAdapter = NULL;
		PIP_ADAPTER_ADDRESSES l_pLocalPtr = l_pAddresses;
		CString l_sFriendlyName = _T("Local Area Connection");
		do
		{
			if (l_sFriendlyName == l_pLocalPtr->FriendlyName)
			{
				l_pAdapter = l_pLocalPtr;
				break;
			}
			l_pLocalPtr = l_pLocalPtr->Next;
		} while (l_pLocalPtr != NULL);

		if (l_pAdapter == NULL)
			l_pAdapter = l_pAddresses;

		if (l_pAdapter != NULL && l_pAdapter->FirstUnicastAddress)
		{
			sockaddr_in* l_pAddress = (sockaddr_in*)l_pAdapter->FirstUnicastAddress->Address.lpSockaddr;
			m_sIPAddress = inet_ntoa(l_pAddress->sin_addr);
		}
	}

    delete [] l_pBuffer;
  //## end CETBrowserService::InitializeAdapterInfo%1198923436.body
}

void CETBrowserService::InitializeSerialNo ()
{
  //## begin CETBrowserService::InitializeSerialNo%1198923437.body preserve=yes
    CPISyncObjListPersistentItems* l_pSyncObj = NULL;
    CPIPersistentConfig* l_pCfg = new CPIPersistentConfig(300,30,0);
    try
    {
        IPIPersistentObjInterface* l_pEprom = CPIObjectFactory::GetInstance()->CreatePersistentObjectManager(m_uiInstrumentEpromID, _T(""));
        CCOSyncObjectPtr l_pSy = l_pEprom->Startup();
        l_pSy->Synchronize();
        l_pSy = l_pEprom->SetConfig(l_pCfg);
        l_pSy->Synchronize();
        l_pCfg->ReleaseRef();
        l_pCfg = NULL;

        l_pSyncObj = l_pEprom->ReadIdentifications();
        l_pSyncObj->Synchronize();

        CPIPersistentItemList* l_pList = l_pSyncObj->GetValue();
        CTypedPtrList<CPtrList, CPIPersistentItem*>& l_Items = l_pList->GetItems();
        for(POSITION l_Pos = l_Items.GetHeadPosition(); l_Pos!=NULL;)
        {
            CPIPersistentIdent* l_pItem = (CPIPersistentIdent*)l_Items.GetNext(l_Pos);
            if (l_pItem->GetsArticleNo() == _T("46210"))
            {
                m_sSerialNo = l_pItem->GetsSerialNo();
                break;
            }
        }
        l_pList->ReleaseRef();
        l_pSyncObj->ReleaseRef();
        l_pSyncObj = NULL;
    }
    catch(XCOException* p_pException)
    {
        p_pException->Delete();
        if (l_pCfg)
            l_pCfg->ReleaseRef();
        if (l_pSyncObj)
            l_pSyncObj->ReleaseRef();
    }
  //## end CETBrowserService::InitializeSerialNo%1198923437.body
}

// Additional Declarations
  //## begin CETBrowserService%47761E500146.declarations preserve=yes
  //## end CETBrowserService%47761E500146.declarations

//## begin module%47761E340395.epilog preserve=yes
//## end module%47761E340395.epilog
