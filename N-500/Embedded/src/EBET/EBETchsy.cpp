//## begin module%3EE5C03A02F0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE5C03A02F0.cm

//## begin module%3EE5C03A02F0.cp preserve=no
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
//## end module%3EE5C03A02F0.cp

//## Module: EBETchsy%3EE5C03A02F0; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchsy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE5C03A02F0.additionalIncludes preserve=no
//## end module%3EE5C03A02F0.additionalIncludes

//## begin module%3EE5C03A02F0.includes preserve=yes
//## end module%3EE5C03A02F0.includes

// EBETflog
#include "EBETflog.h"
// EBETsess
#include "EBETsess.h"
// EBETchsy
#include "EBETchsy.h"
// EBETwrit
#include "EBETwrit.h"
// EBETmesg
#include "EBETmesg.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBPIfact
#include "EBPIfact.h"
// EBPIintf
#include "EBPIintf.h"
//## begin module%3EE5C03A02F0.declarations preserve=no
//## end module%3EE5C03A02F0.declarations

//## begin module%3EE5C03A02F0.additionalDeclarations preserve=yes
//## end module%3EE5C03A02F0.additionalDeclarations


// Class CETChannelSystem 

CETChannelSystem::CETChannelSystem()
  //## begin CETChannelSystem::CETChannelSystem%.hasinit preserve=no
  //## end CETChannelSystem::CETChannelSystem%.hasinit
  //## begin CETChannelSystem::CETChannelSystem%.initialization preserve=yes
  : CETChannel("Tcp channel system", m_uiPortNoSystem)
  //## end CETChannelSystem::CETChannelSystem%.initialization
{
  //## begin CETChannelSystem::CETChannelSystem%.body preserve=yes
  //## end CETChannelSystem::CETChannelSystem%.body
}


CETChannelSystem::~CETChannelSystem()
{
  //## begin CETChannelSystem::~CETChannelSystem%.body preserve=yes
  //## end CETChannelSystem::~CETChannelSystem%.body
}



//## Other Operations (implementation)
CETChannelMessage* CETChannelSystem::UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength)
{
  //## begin CETChannelSystem::UnwrapTelegram%1055243196.body preserve=yes
    CETChannelMessage* l_pMsg = CETChannel::UnwrapTelegram(p_pbyStream, p_uiStreamLength);
    switch(l_pMsg->GeteCommand())
    {
        case eCmdSysWriteIdentification:
            delete l_pMsg;
            l_pMsg = new CETChannelMessagePersistentIdentification(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdSysDownloadSoftware:
            delete l_pMsg;
            l_pMsg = new CETChannelMessagePersistentSoftwareComponent(p_pbyStream, p_uiStreamLength);
            break;
		case eCmdSysDownloadSoftwareComponent:
            delete l_pMsg;
            l_pMsg = new CETChannelMessagePersistentSoftwareComponent(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdSysSetInterfaceConfig:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageSystemInterfaceConfig(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdSysSetComponentState:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageSystemComponentState(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdSysSetTime:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageSystemSetTime(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdSysRegisterClient:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageString(p_pbyStream, p_uiStreamLength);
            break;
    }

    return l_pMsg;
  //## end CETChannelSystem::UnwrapTelegram%1055243196.body
}

void CETChannelSystem::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::ProcessMessage%1055243197.body preserve=yes
	try
	{
		switch(p_pMsg->GetpMsg()->GeteCommand())
		{
			case eCmdStartup:
				OnStartup(p_pMsg);
				break;
			case eCmdShutdown:
				OnShutdown(p_pMsg);
				break;
            case eCmdSysReadIdentifications:
                OnReadIdentifications(p_pMsg);
				break;
            case eCmdSysWriteIdentification:
                OnWriteIdentification(p_pMsg);
				break;
            case eCmdSysReadSWVersions:
                OnReadSoftwareVersions(p_pMsg);
				break;
            case eCmdSysDownloadSoftware:
                OnDownloadSoftwareComponents(p_pMsg);
				break;
			case eCmdSysDownloadSoftwareComponent:
				OnDownloadSoftwareComponent(p_pMsg);
				break;
			case eCmdSysStartDownload:
				OnStartDownload(p_pMsg);
				break;
			case eCmdSysEndDownload:
				OnEndDownload(p_pMsg);
				break;
            case eCmdSysGetState:
                OnGetState(p_pMsg);
                break;
            case eCmdSysReset:
                OnResetDevice(p_pMsg);
                break;
            case eCmdSysStart:
                OnStartDevice(p_pMsg);
                break;
            case eCmdSysSetInterfaceConfig:
                OnSetInterfaceConfig(p_pMsg);
                break;
            case eCmdSysSetComponentState:
                OnSetComponentState(p_pMsg);
                break;
            case eCmdSysGetObjectList:
                OnGetObjectList(p_pMsg);
                break;
			case eCmdSysSetTime:
				OnSetTime(p_pMsg);
				break;
            case eCmdSysRegisterClient:
                OnRegisterClient(p_pMsg);
                break;
            case eCmdSysGetVersion:
                OnGetVersion(p_pMsg);
                break;
             case eCmdSysGetOsVersion:
                OnGetOsVersion(p_pMsg);
                break;
             case eCmdSysGetFpgaVersion:
                OnGetFpgaVersion(p_pMsg);
                break;
            case eCmdSysSetStandbyTimeout:
                OnSetStandbyTimeout(p_pMsg);
                break;
            case eCmdSysPing:
                OnPing(p_pMsg);
                break;

			default:
				CETChannel::ProcessMessage(p_pMsg);
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
		ASSERT(FALSE);
	}
  //## end CETChannelSystem::ProcessMessage%1055243197.body
}

void CETChannelSystem::OnStartup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnStartup%1055243198.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->Startup();

	CETSession* l_pSession = CETSessionManager::GetInstance()->FindSessionBySocket(p_pMsg->GethSocket());
	ASSERT(l_pSession != NULL);
	CETFileLogger::GetInstance()->AddMessage(_T("System Channel, waiting for session(%d) ..."), l_pSession->GetiSessenID());
	l_pSession->WaitForSession();
	CETFileLogger::GetInstance()->AddMessage(_T("System Channel, waiting for session(%d) done"), l_pSession->GetiSessenID());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnStartup%1055243198.body
}

void CETChannelSystem::OnShutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnShutdown%1055243199.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->Shutdown();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnShutdown%1055243199.body
}

void CETChannelSystem::OnReadIdentifications (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnReadIdentifications%1055243200.body preserve=yes
/*    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->ReadIdentifications();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyPersistentIdentification(
        new CETChannelMessagePersistentIdentification(p_pMsg->GetpMsg()->GetReply()),
            l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);*/ // todo 
  //## end CETChannelSystem::OnReadIdentifications%1055243200.body
}

void CETChannelSystem::OnWriteIdentification (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnWriteIdentification%1055243201.body preserve=yes
/*    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CETChannelMessagePersistentIdentification* l_pMsg = dynamic_cast<CETChannelMessagePersistentIdentification*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->WriteIdentification( dynamic_cast<CPIPersistentIdent*>( l_pMsg->GetIdentifications().GetAt(0)) );

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);*/ // todo
  //## end CETChannelSystem::OnWriteIdentification%1055243201.body
}

void CETChannelSystem::OnReadSoftwareVersions (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnReadSoftwareVersions%1055243202.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->ReadSoftwareVersions();

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyPersistentSoftwareComponentVersion(
        new CETChannelMessagePersistentSoftwareComponentVersion(p_pMsg->GetpMsg()->GetReply()),
            l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnReadSoftwareVersions%1055243202.body
}

void CETChannelSystem::OnDownloadSoftwareComponents (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnDownloadSoftwareComponents%1055243203.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CETChannelMessagePersistentSoftwareComponent* l_pMsg = dynamic_cast<CETChannelMessagePersistentSoftwareComponent*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->DownloadSoftwareComponents(l_pMsg->GetpComponents());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnDownloadSoftwareComponents%1055243203.body
}

void CETChannelSystem::OnStartDevice (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnStartDevice%1055243205.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->StartDevice();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnStartDevice%1055243205.body
}

void CETChannelSystem::OnResetDevice (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnResetDevice%1055243206.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->ResetDevice();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnResetDevice%1055243206.body
}

void CETChannelSystem::OnGetState (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnGetState%1055243207.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    EPIDeviceState l_eState = l_pSystem->GetDeviceState();

	CETSession* l_pSession = CETSessionManager::GetInstance()->FindSessionBySocket(p_pMsg->GethSocket());
	ASSERT(l_pSession != NULL);
	CETFileLogger::GetInstance()->AddMessage(_T("System Channel, waiting for session(%d) ..."), l_pSession->GetiSessenID());
	l_pSession->WaitForSession();
	CETFileLogger::GetInstance()->AddMessage(_T("System Channel, waiting for session(%d) done"), l_pSession->GetiSessenID());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
    l_pReply->GetpMsg()->SetiData(l_eState);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnGetState%1055243207.body
}

void CETChannelSystem::OnSetInterfaceConfig (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnSetInterfaceConfig%1055243208.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CETChannelMessageSystemInterfaceConfig* l_pMsg = dynamic_cast<CETChannelMessageSystemInterfaceConfig*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->SetInterfaceConfig(l_pMsg->GetpConfig());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnSetInterfaceConfig%1055243208.body
}

void CETChannelSystem::OnSetComponentState (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnSetComponentState%1061562115.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CETChannelMessageSystemComponentState* l_pMsg = dynamic_cast<CETChannelMessageSystemComponentState*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->SetComponentState(l_pMsg->GetsCpoName(), l_pMsg->GetbState());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnSetComponentState%1061562115.body
}

void CETChannelSystem::OnGetObjectList (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnGetObjectList%1063715464.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->GetObjectList();

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoySystemGetObjectList(
        new CETChannelMessageSystemGetObjectList(*p_pMsg->GetpMsg()->GetReply()),
            l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnGetObjectList%1063715464.body
}

void CETChannelSystem::OnSetTime (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnSetTime%1064429413.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CETChannelMessageSystemSetTime* l_pMsg = dynamic_cast<CETChannelMessageSystemSetTime*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->SetSystemTime(l_pMsg->GetSystemTime());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnSetTime%1064429413.body
}

void CETChannelSystem::OnRegisterClient (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnRegisterClient%1096656412.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CETChannelMessageString* l_pMsg = dynamic_cast<CETChannelMessageString*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);

	CETSession* l_pSession = CETSessionManager::GetInstance()->FindSessionBySocket(p_pMsg->GethSocket());
	ASSERT(l_pSession != NULL);
	CETFileLogger::GetInstance()->AddMessage(_T("System Channel, waiting for session(%d) ..."), l_pSession->GetiSessenID());
	l_pSession->WaitForSession();
	CETFileLogger::GetInstance()->AddMessage(_T("System Channel, waiting for session(%d) done"), l_pSession->GetiSessenID());

    CCOSyncObjectPtr l_pSyncObj = l_pSystem->RegisterClient(l_pMsg->GetsString());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnRegisterClient%1096656412.body
}

void CETChannelSystem::OnGetVersion (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnGetVersion%1096656421.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->GetVersion();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyString(
        new CETChannelMessageString(p_pMsg->GetpMsg()->GetReply()), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnGetVersion%1096656421.body
}

void CETChannelSystem::OnSetStandbyTimeout (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnSetStandbyTimeout%1096717652.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->SetStandbyTimeout((UINT)p_pMsg->GetpMsg()->GetiData());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnSetStandbyTimeout%1096717652.body
}

void CETChannelSystem::OnPing (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnPing%1101721837.body preserve=yes
    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnPing%1101721837.body
}

void CETChannelSystem::OnGetOsVersion (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnGetOsVersion%1108540802.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->GetOsVersion();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyString(
        new CETChannelMessageString(p_pMsg->GetpMsg()->GetReply()), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnGetOsVersion%1108540802.body
}

void CETChannelSystem::OnGetFpgaVersion (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnGetFpgaVersion%1108540803.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->GetFpgaVersion();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyString(
        new CETChannelMessageString(p_pMsg->GetpMsg()->GetReply()), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnGetFpgaVersion%1108540803.body
}

void CETChannelSystem::OnStartDownload (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnStartDownload%1200053481.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->StartDownload();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnStartDownload%1200053481.body
}

void CETChannelSystem::OnDownloadSoftwareComponent (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnDownloadSoftwareComponent%1200053482.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CETChannelMessagePersistentSoftwareComponent* l_pMsg = dynamic_cast<CETChannelMessagePersistentSoftwareComponent*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CTypedPtrList<CPtrList, CPIPersistentSoftwareComponent*>& l_CpoList = l_pMsg->GetpComponents()->GetComponents();
    CCOSyncObjectPtr l_pSyncObj = NULL;
    if (l_CpoList.GetCount() > 0)
    {
        l_pSyncObj = l_pSystem->DownloadSoftwareComponent(l_CpoList.GetHead());
    }
    else
    {
        l_pSyncObj = new CCOSyncObject();
        l_pSyncObj->SignalCompletion();
    }

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnDownloadSoftwareComponent%1200053482.body
}

void CETChannelSystem::OnEndDownload (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSystem::OnEndDownload%1200053483.body preserve=yes
    IPISystemInterface* l_pSystem = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr l_pSyncObj = l_pSystem->EndDownload();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSystem::OnEndDownload%1200053483.body
}

// Additional Declarations
  //## begin CETChannelSystem%3EE5C01E031F.declarations preserve=yes
  //## end CETChannelSystem%3EE5C01E031F.declarations

//## begin module%3EE5C03A02F0.epilog preserve=yes
//## end module%3EE5C03A02F0.epilog
