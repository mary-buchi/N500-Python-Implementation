//## begin module%3DBC092003B5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC092003B5.cm

//## begin module%3DBC092003B5.cp preserve=no
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
//## end module%3DBC092003B5.cp

//## Module: EBETchct%3DBC092003B5; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchct.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DBC092003B5.additionalIncludes preserve=no
//## end module%3DBC092003B5.additionalIncludes

//## begin module%3DBC092003B5.includes preserve=yes
//## end module%3DBC092003B5.includes

// EBETwrit
#include "EBETwrit.h"
// EBETmesg
#include "EBETmesg.h"
// EBETchct
#include "EBETchct.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBPIfact
#include "EBPIfact.h"
// EBPIintf
#include "EBPIintf.h"
//## begin module%3DBC092003B5.declarations preserve=no
//## end module%3DBC092003B5.declarations

//## begin module%3DBC092003B5.additionalDeclarations preserve=yes
//## end module%3DBC092003B5.additionalDeclarations


// Class CETChannelControlTemperature 

CETChannelControlTemperature::CETChannelControlTemperature()
  //## begin CETChannelControlTemperature::CETChannelControlTemperature%.hasinit preserve=no
  //## end CETChannelControlTemperature::CETChannelControlTemperature%.hasinit
  //## begin CETChannelControlTemperature::CETChannelControlTemperature%.initialization preserve=yes
  : CETChannel("Tcp channel temperature control", m_uiPortNoTempControl)
  //## end CETChannelControlTemperature::CETChannelControlTemperature%.initialization
{
  //## begin CETChannelControlTemperature::CETChannelControlTemperature%.body preserve=yes
  //## end CETChannelControlTemperature::CETChannelControlTemperature%.body
}


CETChannelControlTemperature::~CETChannelControlTemperature()
{
  //## begin CETChannelControlTemperature::~CETChannelControlTemperature%.body preserve=yes
  //## end CETChannelControlTemperature::~CETChannelControlTemperature%.body
}



//## Other Operations (implementation)
void CETChannelControlTemperature::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlTemperature::ProcessMessage%1035733651.body preserve=yes
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
            case eCmdTempCtrlSetProfile:
                OnSetProfile(p_pMsg);
				break;
            case eCmdTempCtrlSetConfig:
                OnSetConfiguration(p_pMsg);
				break;
            case eCmdTempCtrlGetTemperature:
                OnGetTemperature(p_pMsg);
				break;
            case eCmdTempCtrlStart:
                OnStart(p_pMsg);
				break;
            case eCmdTempCtrlStop:
                OnStop(p_pMsg);
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
  //## end CETChannelControlTemperature::ProcessMessage%1035733651.body
}

CETChannelMessage* CETChannelControlTemperature::UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength)
{
  //## begin CETChannelControlTemperature::UnwrapTelegram%1037257503.body preserve=yes
    CETChannelMessage* l_pMsg = CETChannel::UnwrapTelegram(p_pbyStream, p_uiStreamLength);
    switch(l_pMsg->GeteCommand())
    {
        case eCmdTempCtrlSetProfile:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageTemperatureProfile(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdTempCtrlSetConfig:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageTemperatureConfig(p_pbyStream, p_uiStreamLength);
            break;
    }

    return l_pMsg;
  //## end CETChannelControlTemperature::UnwrapTelegram%1037257503.body
}

void CETChannelControlTemperature::OnStartup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlTemperature::OnStartup%1035733652.body preserve=yes
    IPITemperatureControlInterface* l_pTempCtrl = CPIObjectFactory::GetInstance()->QueryTemperatureControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pTempCtrl->Startup();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlTemperature::OnStartup%1035733652.body
}

void CETChannelControlTemperature::OnShutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlTemperature::OnShutdown%1035733653.body preserve=yes
    IPITemperatureControlInterface* l_pTempCtrl = CPIObjectFactory::GetInstance()->QueryTemperatureControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pTempCtrl->Shutdown();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);

    // make sure, that any incident messages are removed!
    FindWriter(p_pMsg->GethSocket())->RemoveIncidentMessage(p_pMsg->GetpMsg()->GetuiObjRefID());
  //## end CETChannelControlTemperature::OnShutdown%1035733653.body
}

void CETChannelControlTemperature::OnSetProfile (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlTemperature::OnSetProfile%1037257504.body preserve=yes
    IPITemperatureControlInterface* l_pTempCtrl = CPIObjectFactory::GetInstance()->QueryTemperatureControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageTemperatureProfile* l_pMsg = dynamic_cast<CETChannelMessageTemperatureProfile*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pTempCtrl->SetProfile(l_pMsg->GetpProfile());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlTemperature::OnSetProfile%1037257504.body
}

void CETChannelControlTemperature::OnSetConfiguration (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlTemperature::OnSetConfiguration%1037257505.body preserve=yes
    IPITemperatureControlInterface* l_pTempCtrl = CPIObjectFactory::GetInstance()->QueryTemperatureControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageTemperatureConfig* l_pMsg = dynamic_cast<CETChannelMessageTemperatureConfig*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pTempCtrl->SetConfiguration(l_pMsg->GetpConfig());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlTemperature::OnSetConfiguration%1037257505.body
}

void CETChannelControlTemperature::OnStart (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlTemperature::OnStart%1037257506.body preserve=yes
    IPITemperatureControlInterface* l_pTempCtrl = CPIObjectFactory::GetInstance()->QueryTemperatureControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectArrayPtr l_pSyncObjArray = l_pTempCtrl->Start();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObjArray->GetAt(0));
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);

    // prepare incident reply
	CETChannelMessageEnvoy* l_pIncReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObjArray->GetAt(1));
    FindWriter(p_pMsg->GethSocket())->AddIncidentMessage(l_pIncReply);
  //## end CETChannelControlTemperature::OnStart%1037257506.body
}

void CETChannelControlTemperature::OnStop (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlTemperature::OnStop%1037257507.body preserve=yes
    IPITemperatureControlInterface* l_pTempCtrl = CPIObjectFactory::GetInstance()->QueryTemperatureControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pTempCtrl->Stop();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);

    // remove incident from list
    FindWriter(p_pMsg->GethSocket())->RemoveIncidentMessage(p_pMsg->GetpMsg()->GetuiObjRefID());
  //## end CETChannelControlTemperature::OnStop%1037257507.body
}

void CETChannelControlTemperature::OnGetTemperature (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelControlTemperature::OnGetTemperature%1037257508.body preserve=yes
    IPITemperatureControlInterface* l_pTempCtrl = CPIObjectFactory::GetInstance()->QueryTemperatureControl(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pTempCtrl->GetTemperature();

    // prepare reply
	  CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelControlTemperature::OnGetTemperature%1037257508.body
}

// Additional Declarations
  //## begin CETChannelControlTemperature%3DBC087400C9.declarations preserve=yes
  //## end CETChannelControlTemperature%3DBC087400C9.declarations

//## begin module%3DBC092003B5.epilog preserve=yes
//## end module%3DBC092003B5.epilog
