//## begin module%3DAAAD0203DC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAAD0203DC.cm

//## begin module%3DAAAD0203DC.cp preserve=no
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
//## end module%3DAAAD0203DC.cp

//## Module: EBETchmc%3DAAAD0203DC; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchmc.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DAAAD0203DC.additionalIncludes preserve=no
//## end module%3DAAAD0203DC.additionalIncludes

//## begin module%3DAAAD0203DC.includes preserve=yes
//## end module%3DAAAD0203DC.includes

// EBETchmc
#include "EBETchmc.h"
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


//## begin module%3DAAAD0203DC.declarations preserve=no
//## end module%3DAAAD0203DC.declarations

//## begin module%3DAAAD0203DC.additionalDeclarations preserve=yes
//## end module%3DAAAD0203DC.additionalDeclarations


// Class CETChannelMeasurementChannel 

CETChannelMeasurementChannel::CETChannelMeasurementChannel()
  //## begin CETChannelMeasurementChannel::CETChannelMeasurementChannel%.hasinit preserve=no
  //## end CETChannelMeasurementChannel::CETChannelMeasurementChannel%.hasinit
  //## begin CETChannelMeasurementChannel::CETChannelMeasurementChannel%.initialization preserve=yes
  : CETChannel("Tcp channel measurment channel", m_uiPortNoMeasChannel)
  //## end CETChannelMeasurementChannel::CETChannelMeasurementChannel%.initialization
{
  //## begin CETChannelMeasurementChannel::CETChannelMeasurementChannel%.body preserve=yes
  //## end CETChannelMeasurementChannel::CETChannelMeasurementChannel%.body
}


CETChannelMeasurementChannel::~CETChannelMeasurementChannel()
{
  //## begin CETChannelMeasurementChannel::~CETChannelMeasurementChannel%.body preserve=yes
  //## end CETChannelMeasurementChannel::~CETChannelMeasurementChannel%.body
}



//## Other Operations (implementation)
CETChannelMessage* CETChannelMeasurementChannel::UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength)
{
  //## begin CETChannelMeasurementChannel::UnwrapTelegram%1037103470.body preserve=yes
    CETChannelMessage* l_pMsg = CETChannel::UnwrapTelegram(p_pbyStream, p_uiStreamLength);
    switch(l_pMsg->GeteCommand())
    {
        case eCmdMeasChannelSetProfile:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageMeasurementChannelProfile(p_pbyStream, p_uiStreamLength);
            break;
    }

    return l_pMsg;
  //## end CETChannelMeasurementChannel::UnwrapTelegram%1037103470.body
}

void CETChannelMeasurementChannel::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelMeasurementChannel::ProcessMessage%1034575098.body preserve=yes
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
            case eCmdMeasChannelSetProfile:
                OnSetProfile(p_pMsg);
                break;
            case eCmdMeasChannelInitialize:
                OnInitialize(p_pMsg);
                break;
            case eCmdMeasChannelStart:
                OnStart(p_pMsg);
                break;
            case eCmdMeasChannelStop:
                OnStop(p_pMsg);
                break;
            case eCmdMeasChannelGetDataPackage:
                OnGetDataPackage(p_pMsg);
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
  //## end CETChannelMeasurementChannel::ProcessMessage%1034575098.body
}

void CETChannelMeasurementChannel::OnStartup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelMeasurementChannel::OnStartup%1034575099.body preserve=yes
    IPIMeasurementChannelInterface* l_pChannel = CPIObjectFactory::GetInstance()->QueryMeasurementChannel(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pChannel->Startup();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelMeasurementChannel::OnStartup%1034575099.body
}

void CETChannelMeasurementChannel::OnShutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelMeasurementChannel::OnShutdown%1034575100.body preserve=yes
    IPIMeasurementChannelInterface* l_pChannel = CPIObjectFactory::GetInstance()->QueryMeasurementChannel(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pChannel->Shutdown();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelMeasurementChannel::OnShutdown%1034575100.body
}

void CETChannelMeasurementChannel::OnSetProfile (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelMeasurementChannel::OnSetProfile%1037103466.body preserve=yes
    IPIMeasurementChannelInterface* l_pChannel = CPIObjectFactory::GetInstance()->QueryMeasurementChannel(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageMeasurementChannelProfile* l_pMsg = dynamic_cast<CETChannelMessageMeasurementChannelProfile*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pChannel->SetProfile(l_pMsg->GetpProfile());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelMeasurementChannel::OnSetProfile%1037103466.body
}

void CETChannelMeasurementChannel::OnInitialize (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelMeasurementChannel::OnInitialize%1037103467.body preserve=yes
    IPIMeasurementChannelInterface* l_pChannel = CPIObjectFactory::GetInstance()->QueryMeasurementChannel(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pChannel->Initialize();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelMeasurementChannel::OnInitialize%1037103467.body
}

void CETChannelMeasurementChannel::OnStart (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelMeasurementChannel::OnStart%1037103468.body preserve=yes
    IPIMeasurementChannelInterface* l_pChannel = CPIObjectFactory::GetInstance()->QueryMeasurementChannel(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pChannel->Start(p_pMsg->GetpMsg()->GetiData());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelMeasurementChannel::OnStart%1037103468.body
}

void CETChannelMeasurementChannel::OnStop (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelMeasurementChannel::OnStop%1037103469.body preserve=yes
    IPIMeasurementChannelInterface* l_pChannel = CPIObjectFactory::GetInstance()->QueryMeasurementChannel(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pChannel->Stop();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelMeasurementChannel::OnStop%1037103469.body
}

void CETChannelMeasurementChannel::OnGetDataPackage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelMeasurementChannel::OnGetDataPackage%1034835018.body preserve=yes
    IPIMeasurementChannelInterface* l_pChannel = CPIObjectFactory::GetInstance()->QueryMeasurementChannel(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pChannel->GetDataPackage();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyMeasurementDataPackage(
            new CETChannelMessageMeasurementDataPackage(p_pMsg->GetpMsg()->GetReply()),
            l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelMeasurementChannel::OnGetDataPackage%1034835018.body
}

// Additional Declarations
  //## begin CETChannelMeasurementChannel%3DAAAFC6014C.declarations preserve=yes
  //## end CETChannelMeasurementChannel%3DAAAFC6014C.declarations

//## begin module%3DAAAD0203DC.epilog preserve=yes
//## end module%3DAAAD0203DC.epilog
