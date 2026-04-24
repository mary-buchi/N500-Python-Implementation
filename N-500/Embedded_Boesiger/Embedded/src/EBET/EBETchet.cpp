//## begin module%3DBC095D033B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC095D033B.cm

//## begin module%3DBC095D033B.cp preserve=no
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
//## end module%3DBC095D033B.cp

//## Module: EBETchet%3DBC095D033B; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchet.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DBC095D033B.additionalIncludes preserve=no
//## end module%3DBC095D033B.additionalIncludes

//## begin module%3DBC095D033B.includes preserve=yes
//## end module%3DBC095D033B.includes

// EBETchet
#include "EBETchet.h"
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
//## begin module%3DBC095D033B.declarations preserve=no
//## end module%3DBC095D033B.declarations

//## begin module%3DBC095D033B.additionalDeclarations preserve=yes
//## end module%3DBC095D033B.additionalDeclarations


// Class CETChannelEvents 

CETChannelEvents::CETChannelEvents()
  //## begin CETChannelEvents::CETChannelEvents%.hasinit preserve=no
  //## end CETChannelEvents::CETChannelEvents%.hasinit
  //## begin CETChannelEvents::CETChannelEvents%.initialization preserve=yes
  : CETChannel("Tcp channel events", m_uiPortNoEvents)
  //## end CETChannelEvents::CETChannelEvents%.initialization
{
  //## begin CETChannelEvents::CETChannelEvents%.body preserve=yes
  //## end CETChannelEvents::CETChannelEvents%.body
}


CETChannelEvents::~CETChannelEvents()
{
  //## begin CETChannelEvents::~CETChannelEvents%.body preserve=yes
  //## end CETChannelEvents::~CETChannelEvents%.body
}



//## Other Operations (implementation)
void CETChannelEvents::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelEvents::ProcessMessage%1035733639.body preserve=yes
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
            case eCmdEventSourceRegister:
                OnRegisterForEvent(p_pMsg);
                break;
            case eCmdEventSourceUnregister:
                OnUnregisterFromEvent(p_pMsg);
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
  //## end CETChannelEvents::ProcessMessage%1035733639.body
}

void CETChannelEvents::OnStartup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelEvents::OnStartup%1035733640.body preserve=yes
    IPIEventSourceInterface* l_pEvSource = CPIObjectFactory::GetInstance()->QueryEventSource(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pEvSource->Startup();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelEvents::OnStartup%1035733640.body
}

void CETChannelEvents::OnShutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelEvents::OnShutdown%1035733641.body preserve=yes
    IPIEventSourceInterface* l_pEvSource = CPIObjectFactory::GetInstance()->QueryEventSource(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pEvSource->Shutdown();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelEvents::OnShutdown%1035733641.body
}

void CETChannelEvents::OnRegisterForEvent (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelEvents::OnRegisterForEvent%1037632260.body preserve=yes
    IPIEventSourceInterface* l_pEvSource = CPIObjectFactory::GetInstance()->QueryEventSource(p_pMsg->GetpMsg()->GetuiObjRefID());
    INT l_iEventID; 
    CCOSyncObjectArrayPtr l_pSyncObjArray = l_pEvSource->RegisterForEvent(p_pMsg->GetpMsg()->GetiData(), l_iEventID);

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObjArray->GetAt(0));
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);

    // prepare incident reply
    CETChannelMessage* l_pReplyMsg = p_pMsg->GetpMsg()->GetReply();
    l_pReplyMsg->SetuiObjRefID(l_iEventID);
	CETChannelMessageEnvoy* l_pIncReply = new CETChannelMessageEnvoy(l_pReplyMsg, l_pSyncObjArray->GetAt(1));
    FindWriter(p_pMsg->GethSocket())->AddIncidentMessage(l_pIncReply);
  //## end CETChannelEvents::OnRegisterForEvent%1037632260.body
}

void CETChannelEvents::OnUnregisterFromEvent (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelEvents::OnUnregisterFromEvent%1037632261.body preserve=yes
    IPIEventSourceInterface* l_pEvSource = CPIObjectFactory::GetInstance()->QueryEventSource(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pEvSource->UnRegisterFromEvent(p_pMsg->GetpMsg()->GetiData());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);

    // remove incident from list
    FindWriter(p_pMsg->GethSocket())->RemoveIncidentMessage(p_pMsg->GetpMsg()->GetiData());
  //## end CETChannelEvents::OnUnregisterFromEvent%1037632261.body
}

// Additional Declarations
  //## begin CETChannelEvents%3DBC08AE0217.declarations preserve=yes
  //## end CETChannelEvents%3DBC08AE0217.declarations

//## begin module%3DBC095D033B.epilog preserve=yes
//## end module%3DBC095D033B.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin CETChannelEvents::UnwrapTelegram%1037632259.body preserve=no
    CETChannelMessage* l_pMsg = CETChannel::UnwrapTelegram(p_pbyStream, p_uiStreamLength);
    switch(l_pMsg->GeteCommand())
    {
        case eCmdEventSourceRegister:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageTwoInteger(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdEventSourceUnregister:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageTwoInteger(p_pbyStream, p_uiStreamLength);
            break;
    }

    return l_pMsg;
//## end CETChannelEvents::UnwrapTelegram%1037632259.body

#endif
