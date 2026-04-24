//## begin module%3DBC094A006C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC094A006C.cm

//## begin module%3DBC094A006C.cp preserve=no
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
//## end module%3DBC094A006C.cp

//## Module: EBETchcw%3DBC094A006C; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchcw.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DBC094A006C.additionalIncludes preserve=no
//## end module%3DBC094A006C.additionalIncludes

//## begin module%3DBC094A006C.includes preserve=yes
//## end module%3DBC094A006C.includes

// EBETchcw
#include "EBETchcw.h"
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
//## begin module%3DBC094A006C.declarations preserve=no
//## end module%3DBC094A006C.declarations

//## begin module%3DBC094A006C.additionalDeclarations preserve=yes
//## end module%3DBC094A006C.additionalDeclarations


// Class CETChannelControlWedge 

CETChannelControlWedge::CETChannelControlWedge()
  //## begin CETChannelControlWedge::CETChannelControlWedge%.hasinit preserve=no
  //## end CETChannelControlWedge::CETChannelControlWedge%.hasinit
  //## begin CETChannelControlWedge::CETChannelControlWedge%.initialization preserve=yes
  : CETChannel("Tcp channel wedge control", m_uiPortNoWedgeControl)
  //## end CETChannelControlWedge::CETChannelControlWedge%.initialization
{
  //## begin CETChannelControlWedge::CETChannelControlWedge%.body preserve=yes
  //## end CETChannelControlWedge::CETChannelControlWedge%.body
}


CETChannelControlWedge::~CETChannelControlWedge()
{
  //## begin CETChannelControlWedge::~CETChannelControlWedge%.body preserve=yes
  //## end CETChannelControlWedge::~CETChannelControlWedge%.body
}



//## Other Operations (implementation)
CETChannelMessage* CETChannelControlWedge::UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength)
{
  //## begin CETChannelControlWedge::UnwrapTelegram%1037172636.body preserve=yes
    CETChannelMessage* l_pMsg = CETChannel::UnwrapTelegram(p_pbyStream, p_uiStreamLength);
    switch(l_pMsg->GeteCommand())
    {
        case eCmdWedgeCtrlSetProfile:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageWedgeProfile(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdWedgeCtrlSetConfig:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageWedgeConfig(p_pbyStream, p_uiStreamLength);
            break;
    }

    return l_pMsg;
  //## end CETChannelControlWedge::UnwrapTelegram%1037172636.body
}

void CETChannelControlWedge::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlWedge::ProcessMessage%1035733643.body preserve=yes
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
            case eCmdWedgeCtrlSetProfile:
                OnSetProfile(p_pMsg);
				break;
            case eCmdWedgeCtrlSetConfig:
                OnSetConfig(p_pMsg);
				break;
            case eCmdWedgeCtrlPark:
                OnPark(p_pMsg);
				break;
            case eCmdWedgeCtrlInitialize:
                OnInitialize(p_pMsg);
				break;
            case eCmdWedgeCtrlReference:
                OnReference(p_pMsg);
				break;
            case eCmdWedgeCtrlStart:
                OnStart(p_pMsg);
				break;
            case eCmdWedgeCtrlStop:
                OnStop(p_pMsg);
				break;
            case eCmdWedgeCtrlGetDacZeroCurrent:
                OnGetDacZeroCurrent(p_pMsg);
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
  //## end CETChannelControlWedge::ProcessMessage%1035733643.body
}

void CETChannelControlWedge::OnStartup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlWedge::OnStartup%1035733644.body preserve=yes
    IPIWedgeControlInterface* l_pWedgeCtrl = CPIObjectFactory::GetInstance()->QueryWedgeControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pWedgeCtrl->Startup();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlWedge::OnStartup%1035733644.body
}

void CETChannelControlWedge::OnShutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlWedge::OnShutdown%1035733645.body preserve=yes
    IPIWedgeControlInterface* l_pWedgeCtrl = CPIObjectFactory::GetInstance()->QueryWedgeControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pWedgeCtrl->Shutdown();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);

    // make sure, that any incident messages are removed!
    FindWriter(p_pMsg->GethSocket())->RemoveIncidentMessage(p_pMsg->GetpMsg()->GetuiObjRefID());
  //## end CETChannelControlWedge::OnShutdown%1035733645.body
}

void CETChannelControlWedge::OnSetProfile (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlWedge::OnSetProfile%1037172631.body preserve=yes
    IPIWedgeControlInterface* l_pWedgeCtrl = CPIObjectFactory::GetInstance()->QueryWedgeControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageWedgeProfile* l_pMsg = dynamic_cast<CETChannelMessageWedgeProfile*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pWedgeCtrl->SetProfile(l_pMsg->GetpProfile());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlWedge::OnSetProfile%1037172631.body
}

void CETChannelControlWedge::OnSetConfig (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlWedge::OnSetConfig%1037172637.body preserve=yes
    IPIWedgeControlInterface* l_pWedgeCtrl = CPIObjectFactory::GetInstance()->QueryWedgeControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageWedgeConfig* l_pMsg = dynamic_cast<CETChannelMessageWedgeConfig*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pWedgeCtrl->SetConfiguration(l_pMsg->GetpConfig());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlWedge::OnSetConfig%1037172637.body
}

void CETChannelControlWedge::OnInitialize (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlWedge::OnInitialize%1037172632.body preserve=yes
    IPIWedgeControlInterface* l_pWedgeCtrl = CPIObjectFactory::GetInstance()->QueryWedgeControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pWedgeCtrl->Initialize();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlWedge::OnInitialize%1037172632.body
}

void CETChannelControlWedge::OnReference (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlWedge::OnReference%1069774272.body preserve=yes
    IPIWedgeControlInterface* l_pWedgeCtrl = CPIObjectFactory::GetInstance()->QueryWedgeControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pWedgeCtrl->Referencing();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlWedge::OnReference%1069774272.body
}

void CETChannelControlWedge::OnStart (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlWedge::OnStart%1037172633.body preserve=yes
    IPIWedgeControlInterface* l_pWedgeCtrl = CPIObjectFactory::GetInstance()->QueryWedgeControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectArrayPtr l_pSyncObjArray = l_pWedgeCtrl->Start(p_pMsg->GetpMsg()->GetiData());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObjArray->GetAt(0));
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);

    // prepare incident reply
    CETChannelMessageEnvoy* l_pIncReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObjArray->GetAt(1));
    FindWriter(p_pMsg->GethSocket())->AddIncidentMessage(l_pIncReply);
  //## end CETChannelControlWedge::OnStart%1037172633.body
}

void CETChannelControlWedge::OnStop (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlWedge::OnStop%1037172634.body preserve=yes
    IPIWedgeControlInterface* l_pWedgeCtrl = CPIObjectFactory::GetInstance()->QueryWedgeControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pWedgeCtrl->Stop();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);

    // do not remove incident message -> wedge drive stops not really (follow up measuring)
    // FindWriter(p_pMsg->GethSocket())->RemoveIncidentMessage(p_pMsg->GetpMsg()->GetuiObjRefID());
  //## end CETChannelControlWedge::OnStop%1037172634.body
}

void CETChannelControlWedge::OnPark (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlWedge::OnPark%1037172635.body preserve=yes
    IPIWedgeControlInterface* l_pWedgeCtrl = CPIObjectFactory::GetInstance()->QueryWedgeControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pWedgeCtrl->Park();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlWedge::OnPark%1037172635.body
}

void CETChannelControlWedge::OnGetDacZeroCurrent (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlWedge::OnGetDacZeroCurrent%1149159893.body preserve=yes
    IPIWedgeControlInterface* l_pWedgeCtrl = CPIObjectFactory::GetInstance()->QueryWedgeControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pWedgeCtrl->GetDacZeroCurrent();

    // prepare reply
	CETChannelMessageEnvoyInt* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlWedge::OnGetDacZeroCurrent%1149159893.body
}

// Additional Declarations
  //## begin CETChannelControlWedge%3DBC0894025F.declarations preserve=yes
  //## end CETChannelControlWedge%3DBC0894025F.declarations

//## begin module%3DBC094A006C.epilog preserve=yes
//## end module%3DBC094A006C.epilog
