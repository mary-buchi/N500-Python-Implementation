//## begin module%3DA1487D02B2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA1487D02B2.cm

//## begin module%3DA1487D02B2.cp preserve=no
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
//## end module%3DA1487D02B2.cp

//## Module: EBETread%3DA1487D02B2; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETread.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA1487D02B2.additionalIncludes preserve=no
//## end module%3DA1487D02B2.additionalIncludes

//## begin module%3DA1487D02B2.includes preserve=yes
//## end module%3DA1487D02B2.includes

// EBETchan
#include "EBETchan.h"
// EBETmesg
#include "EBETmesg.h"
// EBETread
#include "EBETread.h"
// EBETflog
#include "EBETflog.h"
// EBETwrit
#include "EBETwrit.h"


//## begin module%3DA1487D02B2.declarations preserve=no
//## end module%3DA1487D02B2.declarations

//## begin module%3DA1487D02B2.additionalDeclarations preserve=yes
//## end module%3DA1487D02B2.additionalDeclarations


// Class CETChannelReader 








//## begin CETChannelReader::uiDataBufferSize%3DB3E1CC00DC.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
UINT CETChannelReader::m_uiDataBufferSize = 1024;
//## end CETChannelReader::uiDataBufferSize%3DB3E1CC00DC.role






CETChannelReader::CETChannelReader (CETChannel* p_pContext, const CString& p_sName, SOCKET p_hSocket, HANDLE p_hSocketEvent, CETChannelWriter* p_pWriter)
  //## begin CETChannelReader::CETChannelReader%1033980241.hasinit preserve=no
      : m_pmfnDataPackageHandler(NULL), m_dwTotalReadBytes(0), m_dwCurrentTelegramSize(0), m_bDisconnected(false), m_hSocket(p_hSocket), m_hDataEvent(NULL), m_pContext(p_pContext), m_hSocketEvent(p_hSocketEvent), m_pWriter(p_pWriter), m_hEndEvent(NULL)
  //## end CETChannelReader::CETChannelReader%1033980241.hasinit
  //## begin CETChannelReader::CETChannelReader%1033980241.initialization preserve=yes
  , CETThread(p_sName)
  //## end CETChannelReader::CETChannelReader%1033980241.initialization
{
  //## begin CETChannelReader::CETChannelReader%1033980241.body preserve=yes
    m_hDataEvent = ::CreateEvent(NULL, true, false, NULL);
	m_hEndEvent  = ::CreateEvent(NULL, true, false, NULL);

    // initialize data package handler
    m_pmfnDataPackageHandler = &CETChannelReader::ExpectNewTelegram;
  //## end CETChannelReader::CETChannelReader%1033980241.body
}


CETChannelReader::~CETChannelReader()
{
  //## begin CETChannelReader::~CETChannelReader%.body preserve=yes
    if (m_hDataEvent)
        ::CloseHandle(m_hDataEvent);
    m_hDataEvent = NULL;
	if (m_hEndEvent)
		::CloseHandle(m_hEndEvent);
	m_hEndEvent = NULL;
  //## end CETChannelReader::~CETChannelReader%.body
}



//## Other Operations (implementation)
void CETChannelReader::End ()
{
  //## begin CETChannelReader::End%1183386646.body preserve=yes
	::SetEvent(m_hEndEvent);
  //## end CETChannelReader::End%1183386646.body
}

DWORD CETChannelReader::ThreadMain ()
{
  //## begin CETChannelReader::ThreadMain%1033980243.body preserve=yes
    try
    {
        bool l_bExecuting = true;
        while (l_bExecuting)
        {
            // do the work
            l_bExecuting = (this->*m_pmfnDataPackageHandler)();
        }

		CETFileLogger::GetInstance()->AddMessage(_T("Reader terminated normally, socket=%d"), m_hSocket);
    }
    catch(XETExceptionConnectionLost* p_pException)
	{
		CETFileLogger::GetInstance()->AddMessage(_T("Reader terminated with connection lost, socket=%d"), m_hSocket);
		p_pException->Delete();
	}
    catch(...)
    {
		CO_TRACE1(_T("ET"), _T("Reader '%s', terminated with exception"), (LPCTSTR)m_pContext->GetsName());
		CETFileLogger::GetInstance()->AddMessage(_T("Reader terminated with exception, socket=%d"), m_hSocket);
    }

    return 0;
  //## end CETChannelReader::ThreadMain%1033980243.body
}

bool CETChannelReader::ReadData (DWORD& p_dwReadBytes, CETChannelReaderDataPackage* p_pDataPackage)
{
  //## begin CETChannelReader::ReadData%1033980244.body preserve=yes
    DWORD l_dwFlags = 0;
    WSAOVERLAPPED l_Overlapped;
    memset(&l_Overlapped, 0, sizeof(WSAOVERLAPPED));
    l_Overlapped.hEvent = m_hDataEvent;

	int l_iErr = WSARecv(
					m_hSocket,   
					&p_pDataPackage->GetData(), // LPWSABUF lpBuffers,
					1,                          // DWORD dwBufferCount,
					&p_dwReadBytes,             // LPDWORD lpNumberOfBytesRecvd,
					&l_dwFlags,                 // LPDWORD lpFlags,
					&l_Overlapped,              // LPWSAOVERLAPPED lpOverlapped,
					NULL);                      // LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    if (l_iErr = SOCKET_ERROR && WSAGetLastError() == WSA_IO_PENDING)
    {
        // async io
        HANDLE l_Handles[] = { m_hSocketEvent, m_hDataEvent, m_hEndEvent, m_hTerminationEvent };
        bool l_bDataReceived = false;
        do
        {
            switch(WSAWaitForMultipleEvents(4, l_Handles, false, INFINITE, false))
            {
				case WAIT_OBJECT_0:
					{
						::ResetEvent(m_hSocketEvent);
						WSANETWORKEVENTS l_Events;
						int l_iRes = ::WSAEnumNetworkEvents(m_hSocket, NULL, &l_Events);
						ASSERT(l_iRes == 0);

						if (l_Events.lNetworkEvents & FD_CLOSE)
						{
							// connection has been closed
							m_pmfnDataPackageHandler = &CETChannelReader::DoDisconnected;
							return false;
						}
					}
					break;

				case WAIT_OBJECT_0+1:
					::ResetEvent(m_hDataEvent);

					WSAGetOverlappedResult(
						m_hSocket,
						&l_Overlapped,      // LPWSAOVERLAPPED lpOverlapped,
						&p_dwReadBytes, // LPDWORD lpcbTransfer,
						false,              // BOOL fWait,
						&l_dwFlags);        // LPDWORD lpdwFlags

					l_bDataReceived = true;
					break;

				case WAIT_OBJECT_0+2:
					// end event signalled -> change to disconnected and detach from channel
					CETFileLogger::GetInstance()->AddMessage(_T("Command End on Reader thread received, socket=%d"), m_hSocket);
					m_pmfnDataPackageHandler = &CETChannelReader::DoDisconnected;
					return false;

				case WAIT_OBJECT_0+3:
					// termination event signalled -> just end thread
					throw new XETExceptionConnectionLost();

				default:
					ASSERT(FALSE);
					break;
            }
        } while (!l_bDataReceived);

    }
    else if (l_iErr != 0)
    {
		// ??
		CETFileLogger::GetInstance()->AddMessage(_T("Change to DoDisconnected (A), socket=%d"), m_hSocket);
		m_pmfnDataPackageHandler = &CETChannelReader::DoDisconnected;
		return false;
    }
	
	if (p_dwReadBytes == 0)
	{
		// connection has been closed
		CETFileLogger::GetInstance()->AddMessage(_T("Change to DoDisconnected (B), socket=%d"), m_hSocket);
		m_pmfnDataPackageHandler = &CETChannelReader::DoDisconnected;
		return false;
	}

    return true;
  //## end CETChannelReader::ReadData%1033980244.body
}

bool CETChannelReader::ExpectNewTelegram ()
{
  //## begin CETChannelReader::ExpectNewTelegram%1035183484.body preserve=yes
    DWORD l_dwReadBytes = 0;
    CETChannelReaderDataPackage* l_pDataPackage = new CETChannelReaderDataPackage(m_uiDataBufferSize);

    if (!ReadData(l_dwReadBytes, l_pDataPackage))
    {
        // enter disconnected state
        delete l_pDataPackage;
        return true;
    }

    l_pDataPackage->SetuiDataSize(l_dwReadBytes);
	return HandleNewDataPackage(l_pDataPackage);
  //## end CETChannelReader::ExpectNewTelegram%1035183484.body
}

bool CETChannelReader::ExpectNextDataPackage ()
{
  //## begin CETChannelReader::ExpectNextDataPackage%1035183485.body preserve=yes
    DWORD l_dwReadBytes = 0;
    CETChannelReaderDataPackage* l_pDataPackage = new CETChannelReaderDataPackage(m_uiDataBufferSize);

    if (!ReadData(l_dwReadBytes, l_pDataPackage))
    {
        // disconnected
        delete l_pDataPackage;
        return true;
    }

    l_pDataPackage->SetuiDataSize(l_dwReadBytes);
    if (m_dwTotalReadBytes+l_dwReadBytes == m_dwCurrentTelegramSize)
    {
        // entire telegram finally read
        m_TempDataPackages.AddTail(l_pDataPackage);
        m_dwTotalReadBytes += l_dwReadBytes;

        l_pDataPackage = MergeTempDataPackages();
        CETChannelMessage* l_pMsg = m_pContext->UnwrapTelegram((BYTE*)l_pDataPackage->GetData().buf, l_pDataPackage->GetuiDataSize());
        m_pContext->AddMessage(new CETChannelMessageEnvoy(l_pMsg, m_hSocket));
        delete l_pDataPackage;

        // expect new telegram
        m_pmfnDataPackageHandler = &CETChannelReader::ExpectNewTelegram;
    }
    else if (m_dwTotalReadBytes+l_dwReadBytes < m_dwCurrentTelegramSize)
    {
        // telegram still not complete
        m_TempDataPackages.AddTail(l_pDataPackage);
        m_dwTotalReadBytes += l_dwReadBytes;
    }
    else
    {
        //  if (m_dwTotalReadBytes+l_dwReadBytes > m_dwCurrentTelegramSize)
		DWORD l_dwMissingFragment = m_dwCurrentTelegramSize - m_dwTotalReadBytes;
		CETChannelReaderDataPackage* l_pLastDataPackage = new CETChannelReaderDataPackage((BYTE*)l_pDataPackage->GetData().buf, l_dwMissingFragment);
		l_pDataPackage->ExtractMessage(l_dwMissingFragment);

		// add that to the list of received packages
		m_TempDataPackages.AddTail(l_pLastDataPackage);
		m_dwTotalReadBytes += l_dwMissingFragment;;
		CETChannelReaderDataPackage* l_pMergedPackage = MergeTempDataPackages();
        CETChannelMessage* l_pMsg = m_pContext->UnwrapTelegram((BYTE*)l_pMergedPackage->GetData().buf, l_pMergedPackage->GetuiDataSize());
        m_pContext->AddMessage(new CETChannelMessageEnvoy(l_pMsg, m_hSocket));
        delete l_pMergedPackage;
		l_pMergedPackage = NULL;

		// handle the rest
        m_pmfnDataPackageHandler = &CETChannelReader::ExpectNewTelegram;
		return HandleNewDataPackage(l_pDataPackage);
    }

    return true;
  //## end CETChannelReader::ExpectNextDataPackage%1035183485.body
}

bool CETChannelReader::ExpectMinimalDataPackage ()
{
  //## begin CETChannelReader::ExpectMinimalDataPackage%1064564699.body preserve=yes
    DWORD l_dwReadBytes = 0;
    CETChannelReaderDataPackage* l_pDataPackage = new CETChannelReaderDataPackage(m_uiDataBufferSize);

    if (!ReadData(l_dwReadBytes, l_pDataPackage))
    {
        // enter disconnected state
        delete l_pDataPackage;
        return true;
    }

    l_pDataPackage->SetuiDataSize(l_dwReadBytes);
    m_TempDataPackages.AddTail(l_pDataPackage);
    m_dwTotalReadBytes += l_dwReadBytes;

    if (m_dwTotalReadBytes >= 4)
    {
        // now we've got enought data
        l_pDataPackage = MergeTempDataPackages();

        return HandleNewDataPackage(l_pDataPackage);
    }

    return true;
  //## end CETChannelReader::ExpectMinimalDataPackage%1064564699.body
}

bool CETChannelReader::DoDisconnected ()
{
  //## begin CETChannelReader::DoDisconnected%1057242738.body preserve=yes
	try
	{
		m_bDisconnected = true;

		// terminate writer
		m_pWriter->Terminate();
		m_pWriter = NULL;
	}
	catch(...)
	{
		CETFileLogger::GetInstance()->AddMessage(_T("Exception in DoDisconnected, terminating writer"));
	}

	m_pContext->ReaderTerminated(this);
	m_pmfnDataPackageHandler = &CETChannelReader::DoEnded;

    return true;
  //## end CETChannelReader::DoDisconnected%1057242738.body
}

bool CETChannelReader::DoEnded ()
{
  //## begin CETChannelReader::DoEnded%1183386644.body preserve=yes
	CETFileLogger::GetInstance()->AddMessage(_T("Entering Ended State, socket=%d"), m_hSocket);		
	HANDLE l_Handles[] = { m_hEndEvent, m_hTerminationEvent};
	switch(::WaitForMultipleObjects(2, l_Handles, false, INFINITE))
	{
		case WAIT_OBJECT_0:
			::ResetEvent(m_hEndEvent);
			return true;

		case WAIT_OBJECT_0+1:
			::ResetEvent(m_hTerminationEvent);
			return false;

		default:
			ASSERT(false);
			return true;
	}
  //## end CETChannelReader::DoEnded%1183386644.body
}

CETChannelReaderDataPackage* CETChannelReader::MergeTempDataPackages ()
{
  //## begin CETChannelReader::MergeTempDataPackages%1035183488.body preserve=yes
    CETChannelReaderDataPackage* l_pDataPackage = new CETChannelReaderDataPackage(m_dwTotalReadBytes);
    BYTE* l_pbyStream = (BYTE*)l_pDataPackage->GetData().buf;
    DWORD l_dwOffset = 0;
    for (POSITION l_Pos=m_TempDataPackages.GetHeadPosition(); l_Pos!=NULL;)
    {
        CETChannelReaderDataPackage* l_pTempPackage = m_TempDataPackages.GetNext(l_Pos);
        memcpy(l_pbyStream+l_dwOffset, (BYTE*)l_pTempPackage->GetData().buf, l_pTempPackage->GetuiDataSize());
        l_dwOffset += l_pTempPackage->GetuiDataSize();
        delete l_pTempPackage;
    }

    m_TempDataPackages.RemoveAll();
    l_pDataPackage->SetuiDataSize(m_dwTotalReadBytes);
    m_dwTotalReadBytes = 0;

    return l_pDataPackage;
  //## end CETChannelReader::MergeTempDataPackages%1035183488.body
}

bool CETChannelReader::HandleNewDataPackage (CETChannelReaderDataPackage* p_pDataPackage)
{
  //## begin CETChannelReader::HandleNewDataPackage%1064516449.body preserve=yes
	DWORD l_dwDataSize = p_pDataPackage->GetuiDataSize();

    if (l_dwDataSize == 0)
	{
		CETFileLogger::GetInstance()->AddMessage(_T("Change to DoDisconnected (F), socket=%d"), m_hSocket);
		m_pmfnDataPackageHandler = &CETChannelReader::DoDisconnected;
		delete p_pDataPackage;
		return true;
	}

    if (l_dwDataSize < 4)
    {
        // not enough data to determine telegram size
        m_TempDataPackages.RemoveAll();
        m_TempDataPackages.AddTail(p_pDataPackage);
        m_dwTotalReadBytes = l_dwDataSize;

        // expect minimum data package
        m_pmfnDataPackageHandler = &CETChannelReader::ExpectMinimalDataPackage;
        return true;
    }

    m_dwCurrentTelegramSize = p_pDataPackage->DetermineTotalTelegramSize();
    if (l_dwDataSize == m_dwCurrentTelegramSize)
    {
        // entire telegram could be read
        CETChannelMessage* l_pMsg = m_pContext->UnwrapTelegram((BYTE*)p_pDataPackage->GetData().buf, p_pDataPackage->GetuiDataSize());
        m_pContext->AddMessage(new CETChannelMessageEnvoy(l_pMsg, m_hSocket));
    }
    else if (l_dwDataSize < m_dwCurrentTelegramSize)
    {
        // start reading more data packages
        m_TempDataPackages.RemoveAll();
        m_TempDataPackages.AddTail(p_pDataPackage);
        m_dwTotalReadBytes = l_dwDataSize;
        p_pDataPackage = NULL;

        // expect next data package
        m_pmfnDataPackageHandler = &CETChannelReader::ExpectNextDataPackage;
    }
    else if (l_dwDataSize > m_dwCurrentTelegramSize)
    {
        // obviously there was more than one telegram in the queue
        bool l_bProcessDataPackage = true;
        do
        {
            // extract one
            CETChannelMessage* l_pMsg = m_pContext->UnwrapTelegram((BYTE*)p_pDataPackage->GetData().buf, m_dwCurrentTelegramSize);
            m_pContext->AddMessage(new CETChannelMessageEnvoy(l_pMsg, m_hSocket));

            // remove the bytes consumed by the extracted message
            p_pDataPackage->ExtractMessage(m_dwCurrentTelegramSize);
            if (p_pDataPackage->GetuiDataSize() == 0)
            {
                l_bProcessDataPackage = false;
            }
            else
            {
                m_dwCurrentTelegramSize = p_pDataPackage->DetermineTotalTelegramSize();
                if (p_pDataPackage->GetuiDataSize() < m_dwCurrentTelegramSize)
                {
                    // incomplete rest -> restart
                    m_pmfnDataPackageHandler = &CETChannelReader::ExpectNewTelegram;
                    return HandleNewDataPackage(p_pDataPackage);                    
                }
            }
        } while (l_bProcessDataPackage);
    }

    // cleanup
    delete p_pDataPackage;

    return true;
  //## end CETChannelReader::HandleNewDataPackage%1064516449.body
}

//## Get and Set Operations for Class Attributes (implementation)

bool CETChannelReader::GetbDisconnected ()
{
  //## begin CETChannelReader::GetbDisconnected%3F6F0ECB0164.get preserve=no
  return m_bDisconnected;
  //## end CETChannelReader::GetbDisconnected%3F6F0ECB0164.get
}

//## Get and Set Operations for Associations (implementation)

SOCKET CETChannelReader::GethSocket ()
{
  //## begin CETChannelReader::GethSocket%3DA1490400A0.get preserve=no
  return m_hSocket;
  //## end CETChannelReader::GethSocket%3DA1490400A0.get
}

// Additional Declarations
  //## begin CETChannelReader%3DA148910273.declarations preserve=yes
  //## end CETChannelReader%3DA148910273.declarations

// Class CETChannelReaderDataPackage 





CETChannelReaderDataPackage::CETChannelReaderDataPackage (UINT p_uiSize)
  //## begin CETChannelReaderDataPackage::CETChannelReaderDataPackage%1035183486.hasinit preserve=no
      : m_uiBufferSize(p_uiSize), m_uiDataSize(0)
  //## end CETChannelReaderDataPackage::CETChannelReaderDataPackage%1035183486.hasinit
  //## begin CETChannelReaderDataPackage::CETChannelReaderDataPackage%1035183486.initialization preserve=yes
  //## end CETChannelReaderDataPackage::CETChannelReaderDataPackage%1035183486.initialization
{
  //## begin CETChannelReaderDataPackage::CETChannelReaderDataPackage%1035183486.body preserve=yes
    m_Data.buf = new char[p_uiSize];
    m_Data.len = p_uiSize;
  //## end CETChannelReaderDataPackage::CETChannelReaderDataPackage%1035183486.body
}

CETChannelReaderDataPackage::CETChannelReaderDataPackage (BYTE* p_pbyDataPackage, UINT p_uiSize)
  //## begin CETChannelReaderDataPackage::CETChannelReaderDataPackage%1064516448.hasinit preserve=no
      : m_uiBufferSize(p_uiSize), m_uiDataSize(0)
  //## end CETChannelReaderDataPackage::CETChannelReaderDataPackage%1064516448.hasinit
  //## begin CETChannelReaderDataPackage::CETChannelReaderDataPackage%1064516448.initialization preserve=yes
  //## end CETChannelReaderDataPackage::CETChannelReaderDataPackage%1064516448.initialization
{
  //## begin CETChannelReaderDataPackage::CETChannelReaderDataPackage%1064516448.body preserve=yes
    m_Data.buf = new char[p_uiSize];
	memcpy(m_Data.buf, p_pbyDataPackage, p_uiSize);
    m_Data.len = p_uiSize;
  //## end CETChannelReaderDataPackage::CETChannelReaderDataPackage%1064516448.body
}


CETChannelReaderDataPackage::~CETChannelReaderDataPackage()
{
  //## begin CETChannelReaderDataPackage::~CETChannelReaderDataPackage%.body preserve=yes
    delete [] m_Data.buf;
    m_Data.buf = NULL;
  //## end CETChannelReaderDataPackage::~CETChannelReaderDataPackage%.body
}



//## Other Operations (implementation)
DWORD CETChannelReaderDataPackage::DetermineTotalTelegramSize ()
{
  //## begin CETChannelReaderDataPackage::DetermineTotalTelegramSize%1035183487.body preserve=yes
    return *((long*)m_Data.buf);
  //## end CETChannelReaderDataPackage::DetermineTotalTelegramSize%1035183487.body
}

void CETChannelReaderDataPackage::ExtractMessage (UINT p_uiSize)
{
  //## begin CETChannelReaderDataPackage::ExtractMessage%1043747867.body preserve=yes
    ASSERT(p_uiSize<=m_Data.len);

    char* l_Buf = new char[m_Data.len-p_uiSize];
    memcpy(l_Buf, m_Data.buf+p_uiSize, m_Data.len-p_uiSize);

    // assign new buffer
    delete [] m_Data.buf;
    m_Data.buf  = l_Buf;
    m_Data.len -= p_uiSize;
    m_uiBufferSize -= p_uiSize;
    m_uiDataSize   -= p_uiSize;
  //## end CETChannelReaderDataPackage::ExtractMessage%1043747867.body
}

//## Get and Set Operations for Class Attributes (implementation)

UINT CETChannelReaderDataPackage::GetuiBufferSize ()
{
  //## begin CETChannelReaderDataPackage::GetuiBufferSize%3DB3E621039B.get preserve=no
  return m_uiBufferSize;
  //## end CETChannelReaderDataPackage::GetuiBufferSize%3DB3E621039B.get
}

UINT CETChannelReaderDataPackage::GetuiDataSize ()
{
  //## begin CETChannelReaderDataPackage::GetuiDataSize%3DB3F39B005F.get preserve=no
  return m_uiDataSize;
  //## end CETChannelReaderDataPackage::GetuiDataSize%3DB3F39B005F.get
}

void CETChannelReaderDataPackage::SetuiDataSize (UINT value)
{
  //## begin CETChannelReaderDataPackage::SetuiDataSize%3DB3F39B005F.set preserve=no
  m_uiDataSize = value;
  //## end CETChannelReaderDataPackage::SetuiDataSize%3DB3F39B005F.set
}

//## Get and Set Operations for Associations (implementation)

WSABUF& CETChannelReaderDataPackage::GetData ()
{
  //## begin CETChannelReaderDataPackage::GetData%3DB3E7490253.get preserve=no
  return m_Data;
  //## end CETChannelReaderDataPackage::GetData%3DB3E7490253.get
}

// Additional Declarations
  //## begin CETChannelReaderDataPackage%3DB3E5F50188.declarations preserve=yes
  //## end CETChannelReaderDataPackage%3DB3E5F50188.declarations

//## begin module%3DA1487D02B2.epilog preserve=yes
//## end module%3DA1487D02B2.epilog
