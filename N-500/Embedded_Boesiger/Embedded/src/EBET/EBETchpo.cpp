//## begin module%3DBC08DE0143.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC08DE0143.cm

//## begin module%3DBC08DE0143.cp preserve=no
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
//## end module%3DBC08DE0143.cp

//## Module: EBETchpo%3DBC08DE0143; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchpo.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DBC08DE0143.additionalIncludes preserve=no
//## end module%3DBC08DE0143.additionalIncludes

//## begin module%3DBC08DE0143.includes preserve=yes
//## end module%3DBC08DE0143.includes

// EBETchpo
#include "EBETchpo.h"
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
//## begin module%3DBC08DE0143.declarations preserve=no
//## end module%3DBC08DE0143.declarations

//## begin module%3DBC08DE0143.additionalDeclarations preserve=yes
//## end module%3DBC08DE0143.additionalDeclarations


// Class CETChannelPersistentObjects 

CETChannelPersistentObjects::CETChannelPersistentObjects()
  //## begin CETChannelPersistentObjects::CETChannelPersistentObjects%.hasinit preserve=no
  //## end CETChannelPersistentObjects::CETChannelPersistentObjects%.hasinit
  //## begin CETChannelPersistentObjects::CETChannelPersistentObjects%.initialization preserve=yes
  : CETChannel("Tcp channel persistent objects", m_uiPortNoPersistentObjects)
  //## end CETChannelPersistentObjects::CETChannelPersistentObjects%.initialization
{
  //## begin CETChannelPersistentObjects::CETChannelPersistentObjects%.body preserve=yes
  //## end CETChannelPersistentObjects::CETChannelPersistentObjects%.body
}


CETChannelPersistentObjects::~CETChannelPersistentObjects()
{
  //## begin CETChannelPersistentObjects::~CETChannelPersistentObjects%.body preserve=yes
  //## end CETChannelPersistentObjects::~CETChannelPersistentObjects%.body
}



//## Other Operations (implementation)
CETChannelMessage* CETChannelPersistentObjects::UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength)
{
  //## begin CETChannelPersistentObjects::UnwrapTelegram%1037346571.body preserve=yes
    CETChannelMessage* l_pMsg = CETChannel::UnwrapTelegram(p_pbyStream, p_uiStreamLength);
    switch(l_pMsg->GeteCommand())
    {
        case eCmdPsObjWriteParameter:
            delete l_pMsg;
            l_pMsg = new CETChannelMessagePersistentParameter(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdPsObjWriteLifeTimeCounter:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageTwoInteger(p_pbyStream, p_uiStreamLength);
            break;
       case eCmdPsObjWriteIdentification:
            delete l_pMsg;
            l_pMsg = new CETChannelMessagePersistentIdentification(p_pbyStream, p_uiStreamLength);
            break;
       case eCmdPsObjSetConfig:
            delete l_pMsg;
            l_pMsg = new CETChannelMessagePersistentConfig(p_pbyStream, p_uiStreamLength);
            break;
    }

    return l_pMsg;
  //## end CETChannelPersistentObjects::UnwrapTelegram%1037346571.body
}

void CETChannelPersistentObjects::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::ProcessMessage%1035733663.body preserve=yes
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
            case eCmdPsObjReadParameters:
                OnReadParameters(p_pMsg);
				break;
            case eCmdPsObjWriteParameter:
                OnWriteParameter(p_pMsg);
				break;
            case eCmdPsObjStartMonitoring:
                OnStartMonitoring(p_pMsg);
				break;
            case eCmdPsObjStopMonitoring:
                OnStopMonitoring(p_pMsg);
				break;
            case eCmdPsObjSave:
                OnSave(p_pMsg);
				break;
            case eCmdPsObjReadLifeTimeCounter:
                OnReadLifeTimeCounter(p_pMsg);
                break;
            case eCmdPsObjWriteLifeTimeCounter:
                OnWriteLifeTimeCounter(p_pMsg);
                break;
            case eCmdPsObjReadIdentifications :
                OnReadIdentifications(p_pMsg);
                break;
            case eCmdPsObjWriteIdentification :
                OnWriteIdentification(p_pMsg);
                break;
            case eCmdPsObjSetConfig :
                OnSetConfig(p_pMsg);
                break;
            case eCmdPsObjReset :
                OnReset(p_pMsg);
                break;
            case eCmdPsObjCellUndocked :
                OnMeasurementCellUndocked(p_pMsg);
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
  //## end CETChannelPersistentObjects::ProcessMessage%1035733663.body
}

void CETChannelPersistentObjects::OnStartup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnStartup%1035733664.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->Startup();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnStartup%1035733664.body
}

void CETChannelPersistentObjects::OnShutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnShutdown%1035733665.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->Shutdown();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnShutdown%1035733665.body
}

void CETChannelPersistentObjects::OnReadParameters (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnReadParameters%1037346576.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->ReadParameters();

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyPersistentParameter(
        new CETChannelMessagePersistentParameter(p_pMsg->GetpMsg()->GetReply()), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnReadParameters%1037346576.body
}

void CETChannelPersistentObjects::OnWriteParameter (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnWriteParameter%1037346577.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessagePersistentParameter* l_pMsg = dynamic_cast<CETChannelMessagePersistentParameter*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CPIPersistentPara* l_pParameter = (CPIPersistentPara*)l_pMsg->GetpPersistentParameter()->GetItems().GetTail();
    ASSERT(l_pParameter != NULL);

//    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->WriteParameter(l_pParameter, l_pMsg->GetPersistentLocation());
	CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->WriteParameter(l_pParameter);

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnWriteParameter%1037346577.body
}

void CETChannelPersistentObjects::OnStartMonitoring (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnStartMonitoring%1074087101.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->StartMonitoring((EPILifeTimeCounter) p_pMsg->GetpMsg()->GetiData());

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnStartMonitoring%1074087101.body
}

void CETChannelPersistentObjects::OnStopMonitoring (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnStopMonitoring%1074087102.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->StopMonitoring((EPILifeTimeCounter) p_pMsg->GetpMsg()->GetiData());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnStopMonitoring%1074087102.body
}

void CETChannelPersistentObjects::OnSave (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnSave%1074087103.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->Save();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnSave%1074087103.body
}

void CETChannelPersistentObjects::OnReadLifeTimeCounter (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnReadLifeTimeCounter%1050325541.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->ReadLifeTimeCounter((EPILifeTimeCounter) p_pMsg->GetpMsg()->GetiData());

    // prepare reply
	CETChannelMessageEnvoyInt* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnReadLifeTimeCounter%1050325541.body
}

void CETChannelPersistentObjects::OnWriteLifeTimeCounter (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnWriteLifeTimeCounter%1050325542.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageTwoInteger* l_pMsg = dynamic_cast<CETChannelMessageTwoInteger*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);

    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->WriteLifeTimeCounter(
        (EPILifeTimeCounter)l_pMsg->GetiInt0(), (UINT)l_pMsg->GetiInt1());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnWriteLifeTimeCounter%1050325542.body
}

void CETChannelPersistentObjects::OnReadIdentifications (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnReadIdentifications%1037346572.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->ReadIdentifications();

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyPersistentIdentification(
        new CETChannelMessagePersistentIdentification(p_pMsg->GetpMsg()->GetReply()), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnReadIdentifications%1037346572.body
}

void CETChannelPersistentObjects::OnWriteIdentification (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnWriteIdentification%1037346573.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessagePersistentIdentification* l_pMsg = dynamic_cast<CETChannelMessagePersistentIdentification*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CPIPersistentIdent* l_pIdentfication = (CPIPersistentIdent*)l_pMsg->GetpPersistentIdentification()->GetItems().GetTail();
    ASSERT(l_pIdentfication != NULL);

    //CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->WriteIdentification(
    //    l_pIdentfication, l_pMsg->GetPersistentLocation());
    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->WriteIdentification(l_pIdentfication);

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnWriteIdentification%1037346573.body
}

void CETChannelPersistentObjects::OnSetConfig (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnSetConfig%1074087104.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessagePersistentConfig* l_pMsg = dynamic_cast<CETChannelMessagePersistentConfig*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->SetConfig(l_pMsg->GetpConfig());

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnSetConfig%1074087104.body
}

void CETChannelPersistentObjects::OnReset (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnReset%1074087105.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->Reset( (EPIEpromSection) p_pMsg->GetpMsg()->GetiData() );

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnReset%1074087105.body
}

void CETChannelPersistentObjects::OnMeasurementCellUndocked (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnMeasurementCellUndocked%1080141460.body preserve=yes
    IPIPersistentObjInterface* l_pPersObjManager = CPIObjectFactory::GetInstance()->QueryPersistentObjManager(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPersObjManager->MeasurementCellUndocked();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelPersistentObjects::OnMeasurementCellUndocked%1080141460.body
}

void CETChannelPersistentObjects::OnReadSoftwareVersions (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnReadSoftwareVersions%1037346578.body preserve=yes
  //## end CETChannelPersistentObjects::OnReadSoftwareVersions%1037346578.body
}

void CETChannelPersistentObjects::OnDownloadSoftwareComponents (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelPersistentObjects::OnDownloadSoftwareComponents%1037346579.body preserve=yes
  //## end CETChannelPersistentObjects::OnDownloadSoftwareComponents%1037346579.body
}

// Additional Declarations
  //## begin CETChannelPersistentObjects%3DBC082C02E2.declarations preserve=yes
  //## end CETChannelPersistentObjects%3DBC082C02E2.declarations

//## begin module%3DBC08DE0143.epilog preserve=yes
//## end module%3DBC08DE0143.epilog
