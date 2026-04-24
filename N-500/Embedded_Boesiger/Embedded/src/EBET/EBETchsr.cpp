//## begin module%3DBC08F402CC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC08F402CC.cm

//## begin module%3DBC08F402CC.cp preserve=no
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
//## end module%3DBC08F402CC.cp

//## Module: EBETchsr%3DBC08F402CC; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchsr.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DBC08F402CC.additionalIncludes preserve=no
//## end module%3DBC08F402CC.additionalIncludes

//## begin module%3DBC08F402CC.includes preserve=yes
//## end module%3DBC08F402CC.includes

// EBETchsr
#include "EBETchsr.h"
// EBETwrit
#include "EBETwrit.h"
// EBETmesg
#include "EBETmesg.h"
// EBCOintf
#include "EBCOintf.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBPIfact
#include "EBPIfact.h"
// EBPIintf
#include "EBPIintf.h"
//## begin module%3DBC08F402CC.declarations preserve=no
//## end module%3DBC08F402CC.declarations

//## begin module%3DBC08F402CC.additionalDeclarations preserve=yes
//## end module%3DBC08F402CC.additionalDeclarations


// Class CETChannelSensors 

CETChannelSensors::CETChannelSensors()
  //## begin CETChannelSensors::CETChannelSensors%.hasinit preserve=no
  //## end CETChannelSensors::CETChannelSensors%.hasinit
  //## begin CETChannelSensors::CETChannelSensors%.initialization preserve=yes
  : CETChannel("Tcp channel sensors", m_uiPortNoSensors)
  //## end CETChannelSensors::CETChannelSensors%.initialization
{
  //## begin CETChannelSensors::CETChannelSensors%.body preserve=yes
  //## end CETChannelSensors::CETChannelSensors%.body
}


CETChannelSensors::~CETChannelSensors()
{
  //## begin CETChannelSensors::~CETChannelSensors%.body preserve=yes
  //## end CETChannelSensors::~CETChannelSensors%.body
}



//## Other Operations (implementation)
void CETChannelSensors::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSensors::ProcessMessage%1035733659.body preserve=yes
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
            case eCmdSensorAnalogGetValue:
                OnAnalogGetValue(p_pMsg);
				break;
            case eCmdSensorDigitalIsActive:
                OnDigitalIsActive(p_pMsg);
				break;
            case eCmdSensorDigitalSetPolarity:
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
  //## end CETChannelSensors::ProcessMessage%1035733659.body
}

void CETChannelSensors::OnStartup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSensors::OnStartup%1035733660.body preserve=yes
    ICOSyncInterface* l_pSensor = CPIObjectFactory::GetInstance()->QuerySensor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pSensor->Startup();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSensors::OnStartup%1035733660.body
}

void CETChannelSensors::OnShutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSensors::OnShutdown%1035733661.body preserve=yes
    ICOSyncInterface* l_pSensor = CPIObjectFactory::GetInstance()->QuerySensor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pSensor->Shutdown();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSensors::OnShutdown%1035733661.body
}

void CETChannelSensors::OnAnalogGetValue (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSensors::OnAnalogGetValue%1037346556.body preserve=yes
    IPISensorAnalogInterface* l_pSensor = CPIObjectFactory::GetInstance()->QueryAnalogSensor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pSensor->GetValue();

    // prepare reply
	CETChannelMessageEnvoyInt* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSensors::OnAnalogGetValue%1037346556.body
}

void CETChannelSensors::OnDigitalSetPolarity (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSensors::OnDigitalSetPolarity%1037346558.body preserve=yes
    IPISensorDigitalInterface* l_pSensor = CPIObjectFactory::GetInstance()->QueryDigitalSensor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pSensor->SetPolarity((EPIPolarity)p_pMsg->GetpMsg()->GetiData());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSensors::OnDigitalSetPolarity%1037346558.body
}

void CETChannelSensors::OnDigitalIsActive (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelSensors::OnDigitalIsActive%1037346559.body preserve=yes
    IPISensorDigitalInterface* l_pSensor = CPIObjectFactory::GetInstance()->QueryDigitalSensor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pSensor->IsActive();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyBool(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelSensors::OnDigitalIsActive%1037346559.body
}

// Additional Declarations
  //## begin CETChannelSensors%3DBC08530266.declarations preserve=yes
  //## end CETChannelSensors%3DBC08530266.declarations

//## begin module%3DBC08F402CC.epilog preserve=yes
//## end module%3DBC08F402CC.epilog


