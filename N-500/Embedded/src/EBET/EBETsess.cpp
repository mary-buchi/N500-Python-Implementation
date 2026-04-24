//## begin module%468A41AB031D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%468A41AB031D.cm

//## begin module%468A41AB031D.cp preserve=no
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
//## end module%468A41AB031D.cp

//## Module: EBETsess%468A41AB031D; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETsess.cpp

// stdafx
#include "stdafx.h"
//## begin module%468A41AB031D.additionalIncludes preserve=no
//## end module%468A41AB031D.additionalIncludes

//## begin module%468A41AB031D.includes preserve=yes
//## end module%468A41AB031D.includes

// EBETchan
#include "EBETchan.h"
// EBETflog
#include "EBETflog.h"
// EBETsess
#include "EBETsess.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBPIfact
#include "EBPIfact.h"
// EBPIintf
#include "EBPIintf.h"


//## begin module%468A41AB031D.declarations preserve=no
//## end module%468A41AB031D.declarations

//## begin module%468A41AB031D.additionalDeclarations preserve=yes
//## end module%468A41AB031D.additionalDeclarations


// Class CETSession 




//## begin CETSession::iNextSessionID%468C8C86023A.attr preserve=no  private: static int {U} 0
int CETSession::m_iNextSessionID = 0;
//## end CETSession::iNextSessionID%468C8C86023A.attr








CETSession::CETSession (bool p_bIsPrimary)
  //## begin CETSession::CETSession%1183443839.hasinit preserve=no
      : m_iStartTime(0), m_iSessenID(0), m_bIsPrimary(p_bIsPrimary), m_eState(eOpening), m_hSessionOpenEvent(NULL)
  //## end CETSession::CETSession%1183443839.hasinit
  //## begin CETSession::CETSession%1183443839.initialization preserve=yes
  //## end CETSession::CETSession%1183443839.initialization
{
  //## begin CETSession::CETSession%1183443839.body preserve=yes
	m_hSessionOpenEvent = ::CreateEvent(NULL, true, false, NULL);
	CETChannel::GetPortNumbers(m_PortNumbers);
	m_iStartTime = ::GetTickCount();
	m_iSessenID = m_iNextSessionID++;
  //## end CETSession::CETSession%1183443839.body
}


CETSession::~CETSession()
{
  //## begin CETSession::~CETSession%.body preserve=yes
	if (m_hSessionOpenEvent != NULL)
		::CloseHandle(m_hSessionOpenEvent);
	m_hSessionOpenEvent = NULL;
  //## end CETSession::~CETSession%.body
}



//## Other Operations (implementation)
void CETSession::SetSocket (UINT p_iPortNo, SOCKET p_hSocket)
{
  //## begin CETSession::SetSocket%1183443833.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, true);

	SOCKET l_hSocket = NULL;
	UINT l_uiPortNo = 0;

	if (!m_Sockets.Lookup(l_uiPortNo, l_hSocket))
	{
		CETFileLogger::GetInstance()->AddMessage(_T("Adding socket to session(%d), socket=%d"), m_iSessenID, l_hSocket);
		m_iStartTime = ::GetTickCount();
		m_Sockets[p_iPortNo] = p_hSocket;
		if (IsComplete())
		{
			CETFileLogger::GetInstance()->AddMessage(_T("Session changed to open, session is primary=%d"), m_bIsPrimary);
			m_eState = eOpen;
			::SetEvent(m_hSessionOpenEvent);

			if (m_bIsPrimary)
			{
				try
				{
					// tell system interface
					CETFileLogger::GetInstance()->AddMessage(_T("Broadcasting Connection established, session=%d"), m_iSessenID);
					CCOSyncObjectPtr l_pSyncObj = CPIObjectFactory::GetInstance()->QuerySystemInterface()->ConnectionEstablished();
					l_pSyncObj->Synchronize();
					CETFileLogger::GetInstance()->AddMessage(_T("Broadcast done, session=%d"), m_iSessenID);
				}
				catch(...)
				{
					CETFileLogger::GetInstance()->AddMessage(_T("Exception broadcasting Connection established, session=%d"), m_iSessenID);
				}
			}
		}
	}
	else
	{
		ASSERT(FALSE);
	}
  //## end CETSession::SetSocket%1183443833.body
}

bool CETSession::ContainsSocket (SOCKET p_hSocket)
{
  //## begin CETSession::ContainsSocket%1183443834.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, true);

	for(POSITION l_Pos=m_Sockets.GetStartPosition(); l_Pos!=NULL;)
	{
		SOCKET l_hSocket = NULL;
		UINT l_uiPortNo = 0;

		m_Sockets.GetNextAssoc(l_Pos, l_uiPortNo, l_hSocket);
		if (l_hSocket == p_hSocket)
			return true;
	}

	return false;
  //## end CETSession::ContainsSocket%1183443834.body
}

bool CETSession::IsComplete ()
{
  //## begin CETSession::IsComplete%1183443836.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, true);

	SOCKET l_hSocket;

	bool l_bRetValue = true;
	for(POSITION l_Pos=m_PortNumbers.GetHeadPosition(); l_Pos!=NULL;)
	{
		UINT l_uiPortNo = m_PortNumbers.GetNext(l_Pos);
		if (!m_Sockets.Lookup(l_uiPortNo, l_hSocket))
		{
			l_bRetValue = false;
		}
	}

	return l_bRetValue;
  //## end CETSession::IsComplete%1183443836.body
}

bool CETSession::RemoveSocket (SOCKET p_hSocket)
{
  //## begin CETSession::RemoveSocket%1183443837.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, true);

	for(POSITION l_Pos=m_Sockets.GetStartPosition(); l_Pos!=NULL;)
	{
		SOCKET l_hSocket = NULL;
		UINT l_uiPortNo = 0;

		m_Sockets.GetNextAssoc(l_Pos, l_uiPortNo, l_hSocket);
		if (l_hSocket == p_hSocket)
		{
			m_eState = eClosing;
			m_Sockets.RemoveKey(l_uiPortNo);
			break;
		}
	}

	CETFileLogger::GetInstance()->AddMessage(_T("Removing socket from session(%d), remaining sockets in session=%d"), m_iSessenID, m_Sockets.GetCount());

	bool l_bIsClosed = m_Sockets.GetCount() == 0;
	if (m_bIsPrimary && l_bIsClosed)
	{
		CETFileLogger::GetInstance()->AddMessage(_T("Broadcasting ConnectionLost, session=%d"), m_iSessenID);
		CCOSyncObjectPtr l_pSyncObj = CPIObjectFactory::GetInstance()->QuerySystemInterface()->ConnectionLost();
	}

	return l_bIsClosed;
  //## end CETSession::RemoveSocket%1183443837.body
}

bool CETSession::IsOpening ()
{
  //## begin CETSession::IsOpening%1183494355.body preserve=yes
	return m_eState == eOpening;
  //## end CETSession::IsOpening%1183494355.body
}

bool CETSession::IsOpen ()
{
  //## begin CETSession::IsOpen%1183494356.body preserve=yes
	return m_eState == eOpen;
  //## end CETSession::IsOpen%1183494356.body
}

bool CETSession::IsClosing ()
{
  //## begin CETSession::IsClosing%1183494357.body preserve=yes
	return m_eState == eClosing;
  //## end CETSession::IsClosing%1183494357.body
}

void CETSession::WaitForSession ()
{
  //## begin CETSession::WaitForSession%1183704511.body preserve=yes
	::WaitForSingleObject(m_hSessionOpenEvent, INFINITE);
  //## end CETSession::WaitForSession%1183704511.body
}

//## Get and Set Operations for Class Attributes (implementation)

int CETSession::GetiSessenID ()
{
  //## begin CETSession::GetiSessenID%468C8C4F0385.get preserve=no
  return m_iSessenID;
  //## end CETSession::GetiSessenID%468C8C4F0385.get
}

//## Get and Set Operations for Associations (implementation)

bool CETSession::GetbIsPrimary ()
{
  //## begin CETSession::GetbIsPrimary%468A6A9401A0.get preserve=no
  return m_bIsPrimary;
  //## end CETSession::GetbIsPrimary%468A6A9401A0.get
}

void CETSession::SetbIsPrimary (bool value)
{
  //## begin CETSession::SetbIsPrimary%468A6A9401A0.set preserve=no
  m_bIsPrimary = value;
  //## end CETSession::SetbIsPrimary%468A6A9401A0.set
}

const CString& CETSession::GetsName () const
{
  //## begin CETSession::GetsName%468DFF5C0064.get preserve=no
  return m_sName;
  //## end CETSession::GetsName%468DFF5C0064.get
}

void CETSession::SetsName (const CString& value)
{
  //## begin CETSession::SetsName%468DFF5C0064.set preserve=no
  m_sName = value;
  //## end CETSession::SetsName%468DFF5C0064.set
}

// Additional Declarations
  //## begin CETSession%468A41DC0011.declarations preserve=yes
  //## end CETSession%468A41DC0011.declarations

// Class CETSessionManager 

//## begin CETSessionManager::pInstance%468A42490249.role preserve=no  public: static CETSessionManager { -> RFHN}
CETSessionManager *CETSessionManager::m_pInstance = NULL;
//## end CETSessionManager::pInstance%468A42490249.role




CETSessionManager::CETSessionManager()
  //## begin CETSessionManager::CETSessionManager%.hasinit preserve=no
  //## end CETSessionManager::CETSessionManager%.hasinit
  //## begin CETSessionManager::CETSessionManager%.initialization preserve=yes
  //## end CETSessionManager::CETSessionManager%.initialization
{
  //## begin CETSessionManager::CETSessionManager%.body preserve=yes
  //## end CETSessionManager::CETSessionManager%.body
}


CETSessionManager::~CETSessionManager()
{
  //## begin CETSessionManager::~CETSessionManager%.body preserve=yes
  	for(POSITION l_Pos=m_Sessions.GetHeadPosition(); l_Pos!=NULL;)
	{
		CETSession* l_pSession = m_Sessions.GetNext(l_Pos);
		delete l_pSession;
	}
	m_Sessions.RemoveAll();
  //## end CETSessionManager::~CETSessionManager%.body
}



//## Other Operations (implementation)
void CETSessionManager::Create ()
{
  //## begin CETSessionManager::Create%1183443828.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CETSessionManager();
  //## end CETSessionManager::Create%1183443828.body
}

void CETSessionManager::Delete ()
{
  //## begin CETSessionManager::Delete%1183443829.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CETSessionManager::Delete%1183443829.body
}

CETSessionManager* CETSessionManager::GetInstance ()
{
  //## begin CETSessionManager::GetInstance%1183443830.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CETSessionManager::GetInstance%1183443830.body
}

CETSession* CETSessionManager::AddToSession (UINT p_uiPortNo, SOCKET p_hSocket)
{
  //## begin CETSessionManager::AddToSession%1183443831.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, true);
	CETSession* l_pSession = FindSessionBySocket(p_hSocket);
	if (l_pSession == NULL)
	{
		l_pSession = FindOpeningSession();
		if (l_pSession == NULL)
		{
			l_pSession = new CETSession(m_Sessions.GetCount() == 0);
			m_Sessions.AddTail(l_pSession);
			CETFileLogger::GetInstance()->AddMessage(_T("Create New Session(%d), session cnt=%d"), l_pSession->GetiSessenID(), m_Sessions.GetCount());
		}
	}

	ASSERT(l_pSession != NULL);
	l_pSession->SetSocket(p_uiPortNo, p_hSocket);
	return l_pSession;
  //## end CETSessionManager::AddToSession%1183443831.body
}

void CETSessionManager::RemoveFromSession (UINT p_uiPortNo, SOCKET p_hSocket)
{
  //## begin CETSessionManager::RemoveFromSession%1183443838.body preserve=yes
	CSingleLock l_Lock(&m_AccessLock, true);
	CETSession* l_pSession = FindSessionBySocket(p_hSocket);
	ASSERT(l_pSession != NULL);

	if (l_pSession->RemoveSocket(p_hSocket))
	{
		// the session is empty now -> remove from list
		for(POSITION l_Pos=m_Sessions.GetHeadPosition(); l_Pos!=NULL;)
		{
			POSITION l_CurPos = l_Pos;
			CETSession* l_pTmp = m_Sessions.GetNext(l_Pos);
			if (l_pTmp == l_pSession)
			{
				m_Sessions.RemoveAt(l_CurPos);
				CETFileLogger::GetInstance()->AddMessage(_T("Deleting Session(%d), session cnt=%d"), l_pSession->GetiSessenID(), m_Sessions.GetCount());
				delete l_pSession;
				break;
			}
		}
	}
  //## end CETSessionManager::RemoveFromSession%1183443838.body
}

CETSession* CETSessionManager::FindSessionBySocket (SOCKET p_hSocket)
{
  //## begin CETSessionManager::FindSessionBySocket%1183443832.body preserve=yes
	for(POSITION l_Pos=m_Sessions.GetHeadPosition(); l_Pos!=NULL;)
	{
		CETSession* l_pSession = m_Sessions.GetNext(l_Pos);
		if (l_pSession->ContainsSocket(p_hSocket))
			return l_pSession;
	}

	return NULL;
  //## end CETSessionManager::FindSessionBySocket%1183443832.body
}

void CETSessionManager::SetPrimarySession (CETSession* p_pSession)
{
  //## begin CETSessionManager::SetPrimarySession%1183536495.body preserve=yes
	BOOL l_bReconnected = false;
	CSingleLock l_Lock(&m_AccessLock, true);
	for(POSITION l_Pos=m_Sessions.GetHeadPosition(); l_Pos!=NULL;)
	{
		CETSession* l_pTmp = m_Sessions.GetNext(l_Pos);
		if (l_pTmp != p_pSession)
		{
			// degrade session to non-primary
			CETFileLogger::GetInstance()->AddMessage(_T("Degrading session(%d) to non-primary"), l_pTmp->GetiSessenID());
			if (l_pTmp->GetbIsPrimary())
				l_bReconnected = true;
			l_pTmp->SetbIsPrimary(false);
		}
	}

	CETFileLogger::GetInstance()->AddMessage(_T("Change session(%d) to primary"), p_pSession->GetiSessenID());
	p_pSession->SetbIsPrimary(true);

	if (l_bReconnected)
	{
		CETFileLogger::GetInstance()->AddMessage(_T("CONNECTION RE-ESTABLISHED"));
		IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
		CCOSyncObject*  pSyncObj;
		// We should be in SY-State ProcessIdle
		CETFileLogger::GetInstance()->AddMessage(_T("--> SY ConnectionEstablished"));
		pSyncObj = pIntf->ConnectionEstablished();
		pSyncObj->Synchronize();
		pSyncObj->ReleaseRef();
	} 

	//## end CETSessionManager::SetPrimarySession%1183536495.body
}

CETSession* CETSessionManager::FindOpeningSession ()
{
  //## begin CETSessionManager::FindOpeningSession%1183494354.body preserve=yes
	for(POSITION l_Pos=m_Sessions.GetHeadPosition(); l_Pos!=NULL;)
	{
		CETSession* l_pSession = m_Sessions.GetNext(l_Pos);
		if (l_pSession->IsOpening())
		{
			return l_pSession;
		}
	}

	return NULL;
  //## end CETSessionManager::FindOpeningSession%1183494354.body
}

// Additional Declarations
  //## begin CETSessionManager%468A41E703BA.declarations preserve=yes
  //## end CETSessionManager%468A41E703BA.declarations

//## begin module%468A41AB031D.epilog preserve=yes
//## end module%468A41AB031D.epilog
