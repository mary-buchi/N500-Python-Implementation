//## begin module%3DBC090802B6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC090802B6.cm

//## begin module%3DBC090802B6.cp preserve=no
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
//## end module%3DBC090802B6.cp

//## Module: EBETchot%3DBC090802B6; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchot.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DBC090802B6.additionalIncludes preserve=no
//## end module%3DBC090802B6.additionalIncludes

//## begin module%3DBC090802B6.includes preserve=yes
//## end module%3DBC090802B6.includes

// EBETchot
#include "EBETchot.h"
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
//## begin module%3DBC090802B6.declarations preserve=no
//## end module%3DBC090802B6.declarations

//## begin module%3DBC090802B6.additionalDeclarations preserve=yes
//## end module%3DBC090802B6.additionalDeclarations


// Class CETChannelOutputs 

CETChannelOutputs::CETChannelOutputs()
  //## begin CETChannelOutputs::CETChannelOutputs%.hasinit preserve=no
  //## end CETChannelOutputs::CETChannelOutputs%.hasinit
  //## begin CETChannelOutputs::CETChannelOutputs%.initialization preserve=yes
  : CETChannel("Tcp channel outputs", m_uiPortNoOutputs)
  //## end CETChannelOutputs::CETChannelOutputs%.initialization
{
  //## begin CETChannelOutputs::CETChannelOutputs%.body preserve=yes
  //## end CETChannelOutputs::CETChannelOutputs%.body
}


CETChannelOutputs::~CETChannelOutputs()
{
  //## begin CETChannelOutputs::~CETChannelOutputs%.body preserve=yes
  //## end CETChannelOutputs::~CETChannelOutputs%.body
}



//## Other Operations (implementation)
void CETChannelOutputs::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelOutputs::ProcessMessage%1035733655.body preserve=yes
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
            case eCmdOutputAnalogSetValue:
                OnAnalogSetValue(p_pMsg);
				break;
            case eCmdOutputAnalogGetValue:
                OnAnalogGetValue(p_pMsg);
				break;
            case eCmdOutputDigitalSet:
                OnDigitalSet(p_pMsg);
				break;
            case eCmdOutputDigitalClear:
                OnDigitalClear(p_pMsg);
				break;
            case eCmdOutputDigitalIsActive:
                OnDigitalIsActive(p_pMsg);
                break;
            case eCmdOutputDigitalSetPolarity:
                OnDigitalSetPolarity(p_pMsg);
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
  //## end CETChannelOutputs::ProcessMessage%1035733655.body
}

void CETChannelOutputs::OnStartup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelOutputs::OnStartup%1035733656.body preserve=yes
    ICOSyncInterface* l_pOutput = CPIObjectFactory::GetInstance()->QueryOutput(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pOutput->Startup();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelOutputs::OnStartup%1035733656.body
}

void CETChannelOutputs::OnShutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelOutputs::OnShutdown%1035733657.body preserve=yes
    ICOSyncInterface* l_pOutput = CPIObjectFactory::GetInstance()->QueryOutput(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pOutput->Shutdown();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelOutputs::OnShutdown%1035733657.body
}

void CETChannelOutputs::OnAnalogSetValue (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelOutputs::OnAnalogSetValue%1037346562.body preserve=yes
    IPIOutputAnalogInterface* l_pOutput = CPIObjectFactory::GetInstance()->QueryAnalogOutput(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pOutput->SetValue(p_pMsg->GetpMsg()->GetiData());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelOutputs::OnAnalogSetValue%1037346562.body
}

void CETChannelOutputs::OnAnalogGetValue (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelOutputs::OnAnalogGetValue%1037346563.body preserve=yes
    IPIOutputAnalogInterface* l_pOutput = CPIObjectFactory::GetInstance()->QueryAnalogOutput(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pOutput->GetValue();

    // prepare reply
	CETChannelMessageEnvoyInt* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelOutputs::OnAnalogGetValue%1037346563.body
}

void CETChannelOutputs::OnDigitalSet (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelOutputs::OnDigitalSet%1037346564.body preserve=yes
    IPIOutputDigitalInterface* l_pOutput = CPIObjectFactory::GetInstance()->QueryDigitalOutput(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pOutput->Set();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelOutputs::OnDigitalSet%1037346564.body
}

void CETChannelOutputs::OnDigitalClear (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelOutputs::OnDigitalClear%1037346565.body preserve=yes
    IPIOutputDigitalInterface* l_pOutput = CPIObjectFactory::GetInstance()->QueryDigitalOutput(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pOutput->Clear();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelOutputs::OnDigitalClear%1037346565.body
}

void CETChannelOutputs::OnDigitalIsActive (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelOutputs::OnDigitalIsActive%1037346568.body preserve=yes
    IPIOutputDigitalInterface* l_pOutput = CPIObjectFactory::GetInstance()->QueryDigitalOutput(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pOutput->IsActive();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyBool(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelOutputs::OnDigitalIsActive%1037346568.body
}

void CETChannelOutputs::OnDigitalSetPolarity (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelOutputs::OnDigitalSetPolarity%1037346566.body preserve=yes
    IPIOutputDigitalInterface* l_pOutput = CPIObjectFactory::GetInstance()->QueryDigitalOutput(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pOutput->SetPolarity((EPIPolarity)p_pMsg->GetpMsg()->GetiData());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelOutputs::OnDigitalSetPolarity%1037346566.body
}

// Additional Declarations
  //## begin CETChannelOutputs%3DBC085F01D7.declarations preserve=yes
  //## end CETChannelOutputs%3DBC085F01D7.declarations

//## begin module%3DBC090802B6.epilog preserve=yes
//## end module%3DBC090802B6.epilog
