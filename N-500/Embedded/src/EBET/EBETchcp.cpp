//## begin module%3DBC093301B4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC093301B4.cm

//## begin module%3DBC093301B4.cp preserve=no
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
//## end module%3DBC093301B4.cp

//## Module: EBETchcp%3DBC093301B4; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DBC093301B4.additionalIncludes preserve=no
//## end module%3DBC093301B4.additionalIncludes

//## begin module%3DBC093301B4.includes preserve=yes
//## end module%3DBC093301B4.includes

// EBETchcp
#include "EBETchcp.h"
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
//## begin module%3DBC093301B4.declarations preserve=no
//## end module%3DBC093301B4.declarations

//## begin module%3DBC093301B4.additionalDeclarations preserve=yes
//## end module%3DBC093301B4.additionalDeclarations


// Class CETChannelControlPower 

CETChannelControlPower::CETChannelControlPower()
  //## begin CETChannelControlPower::CETChannelControlPower%.hasinit preserve=no
  //## end CETChannelControlPower::CETChannelControlPower%.hasinit
  //## begin CETChannelControlPower::CETChannelControlPower%.initialization preserve=yes
  : CETChannel("Tcp channel power control", m_uiPortNoPowerControl)
  //## end CETChannelControlPower::CETChannelControlPower%.initialization
{
  //## begin CETChannelControlPower::CETChannelControlPower%.body preserve=yes
  //## end CETChannelControlPower::CETChannelControlPower%.body
}


CETChannelControlPower::~CETChannelControlPower()
{
  //## begin CETChannelControlPower::~CETChannelControlPower%.body preserve=yes
  //## end CETChannelControlPower::~CETChannelControlPower%.body
}



//## Other Operations (implementation)
CETChannelMessage* CETChannelControlPower::UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength)
{
  //## begin CETChannelControlPower::UnwrapTelegram%1037257515.body preserve=yes
    CETChannelMessage* l_pMsg = CETChannel::UnwrapTelegram(p_pbyStream, p_uiStreamLength);
    switch(l_pMsg->GeteCommand())
    {
        case eCmdPwrCtrlSetProfile:
            delete l_pMsg;
            l_pMsg = new CETChannelMessagePowerProfile(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdPwrCtrlSetConfig:
            delete l_pMsg;
            l_pMsg = new CETChannelMessagePowerConfig(p_pbyStream, p_uiStreamLength);
            break;
    }

    return l_pMsg;
  //## end CETChannelControlPower::UnwrapTelegram%1037257515.body
}

void CETChannelControlPower::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlPower::ProcessMessage%1035733647.body preserve=yes
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
            case eCmdPwrCtrlSetProfile:
                OnSetProfile(p_pMsg);
				break;
            case eCmdPwrCtrlSetConfig:
                OnSetConfiguration(p_pMsg);
				break;
            case eCmdPwrCtrlStart:
                OnStart(p_pMsg);
				break;
            case eCmdPwrCtrlStop:
                OnStop(p_pMsg);
				break;
            case eCmdPwrCtrlPowerOn:
                OnPowerOn(p_pMsg);
                break;
            case eCmdPwrCtrlPowerOff:
                OnPowerOff(p_pMsg);
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
  //## end CETChannelControlPower::ProcessMessage%1035733647.body
}

void CETChannelControlPower::OnStartup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlPower::OnStartup%1035733648.body preserve=yes
    IPIPowerControlInterface* l_pPowerCtrl = CPIObjectFactory::GetInstance()->QueryPowerControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPowerCtrl->Startup();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlPower::OnStartup%1035733648.body
}

void CETChannelControlPower::OnShutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlPower::OnShutdown%1035733649.body preserve=yes
    IPIPowerControlInterface* l_pPowerCtrl = CPIObjectFactory::GetInstance()->QueryPowerControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPowerCtrl->Shutdown();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);

    // make sure, that any incident messages are removed!
    FindWriter(p_pMsg->GethSocket())->RemoveIncidentMessage(p_pMsg->GetpMsg()->GetuiObjRefID());
  //## end CETChannelControlPower::OnShutdown%1035733649.body
}

void CETChannelControlPower::OnSetProfile (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlPower::OnSetProfile%1037257511.body preserve=yes
    IPIPowerControlInterface* l_pPowerCtrl = CPIObjectFactory::GetInstance()->QueryPowerControl(p_pMsg->GetpMsg()->GetuiObjRefID());
	CETChannelMessagePowerProfile* l_pMsg = dynamic_cast<CETChannelMessagePowerProfile*>(p_pMsg->GetpMsg());
	ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pPowerCtrl->SetProfile(l_pMsg->GetpProfile());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlPower::OnSetProfile%1037257511.body
}

void CETChannelControlPower::OnSetConfiguration (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlPower::OnSetConfiguration%1037308030.body preserve=yes
    IPIPowerControlInterface* l_pPowerCtrl = CPIObjectFactory::GetInstance()->QueryPowerControl(p_pMsg->GetpMsg()->GetuiObjRefID());
	CETChannelMessagePowerConfig* l_pMsg = dynamic_cast<CETChannelMessagePowerConfig*>(p_pMsg->GetpMsg());
	ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pPowerCtrl->SetConfiguration(l_pMsg->GetpConfig());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlPower::OnSetConfiguration%1037308030.body
}

void CETChannelControlPower::OnStart (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlPower::OnStart%1037257513.body preserve=yes
    IPIPowerControlInterface* l_pPowerCtrl = CPIObjectFactory::GetInstance()->QueryPowerControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectArrayPtr l_pSyncObjArray = l_pPowerCtrl->Start();

    // prepare execution reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObjArray->GetAt(0));
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);

    // prepare incident reply
    CETChannelMessageEnvoy* l_pIncReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObjArray->GetAt(1));
    FindWriter(p_pMsg->GethSocket())->AddIncidentMessage(l_pIncReply);
  //## end CETChannelControlPower::OnStart%1037257513.body
}

void CETChannelControlPower::OnStop (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlPower::OnStop%1037257514.body preserve=yes
    IPIPowerControlInterface* l_pPowerCtrl = CPIObjectFactory::GetInstance()->QueryPowerControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPowerCtrl->Stop();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);

    // remove incident from list
    FindWriter(p_pMsg->GethSocket())->RemoveIncidentMessage(p_pMsg->GetpMsg()->GetuiObjRefID());
  //## end CETChannelControlPower::OnStop%1037257514.body
}

void CETChannelControlPower::OnPowerOn (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlPower::OnPowerOn%1076659629.body preserve=yes
    IPIPowerControlInterface* l_pPowerCtrl = CPIObjectFactory::GetInstance()->QueryPowerControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPowerCtrl->PowerOn();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlPower::OnPowerOn%1076659629.body
}

void CETChannelControlPower::OnPowerOff (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlPower::OnPowerOff%1076659630.body preserve=yes
    IPIPowerControlInterface* l_pPowerCtrl = CPIObjectFactory::GetInstance()->QueryPowerControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPowerCtrl->PowerOff();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlPower::OnPowerOff%1076659630.body
}

// Additional Declarations
  //## begin CETChannelControlPower%3DBC088203AE.declarations preserve=yes
  //## end CETChannelControlPower%3DBC088203AE.declarations

//## begin module%3DBC093301B4.epilog preserve=yes
//## end module%3DBC093301B4.epilog
