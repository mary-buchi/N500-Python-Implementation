//## begin module%3EE5C05A008E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE5C05A008E.cm

//## begin module%3EE5C05A008E.cp preserve=no
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
//## end module%3EE5C05A008E.cp

//## Module: EBETchi2%3EE5C05A008E; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchi2.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE5C05A008E.additionalIncludes preserve=no
//## end module%3EE5C05A008E.additionalIncludes

//## begin module%3EE5C05A008E.includes preserve=yes
//## end module%3EE5C05A008E.includes

// EBPIintf
#include "EBPIintf.h"
// EBETchi2
#include "EBETchi2.h"
// EBETwrit
#include "EBETwrit.h"
// EBETmesg
#include "EBETmesg.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBPIfact
#include "EBPIfact.h"
//## begin module%3EE5C05A008E.declarations preserve=no
//## end module%3EE5C05A008E.declarations

//## begin module%3EE5C05A008E.additionalDeclarations preserve=yes
//## end module%3EE5C05A008E.additionalDeclarations


// Class CETChannelI2CBus 

CETChannelI2CBus::CETChannelI2CBus()
  //## begin CETChannelI2CBus::CETChannelI2CBus%.hasinit preserve=no
  //## end CETChannelI2CBus::CETChannelI2CBus%.hasinit
  //## begin CETChannelI2CBus::CETChannelI2CBus%.initialization preserve=yes
: CETChannel("Tcp channel I2C Bus Devices", m_uiPortNoI2CBus)
  //## end CETChannelI2CBus::CETChannelI2CBus%.initialization
{
  //## begin CETChannelI2CBus::CETChannelI2CBus%.body preserve=yes
  //## end CETChannelI2CBus::CETChannelI2CBus%.body
}


CETChannelI2CBus::~CETChannelI2CBus()
{
  //## begin CETChannelI2CBus::~CETChannelI2CBus%.body preserve=yes
  //## end CETChannelI2CBus::~CETChannelI2CBus%.body
}



//## Other Operations (implementation)
CETChannelMessage* CETChannelI2CBus::UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength)
{
  //## begin CETChannelI2CBus::UnwrapTelegram%1057156748.body preserve=yes
    CETChannelMessage* l_pMsg = CETChannel::UnwrapTelegram(p_pbyStream, p_uiStreamLength);
    switch(l_pMsg->GeteCommand())
    {
    case eCmdI2CTempDS1631ZSetConfig:
        delete l_pMsg;
        l_pMsg = new CETChannelMessageI2CTempDS1631ZConfig(p_pbyStream, p_uiStreamLength);
        break;
    }

    return l_pMsg;
  //## end CETChannelI2CBus::UnwrapTelegram%1057156748.body
}

void CETChannelI2CBus::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelI2CBus::ProcessMessage%1055243211.body preserve=yes
    try
    {
        switch(p_pMsg->GetpMsg()->GeteCommand())
        {
            // temp controller
        case eCmdI2CTempDS1631ZStartup:
            OnTempDS1631ZStartup(p_pMsg);
            break;
        case eCmdI2CTempDS1631ZShutdown:
            OnTempDS1631ZShutdown(p_pMsg);
            break;
        case eCmdI2CTempDS1631ZSetConfig:
            OnTempDS1631ZSetConfig(p_pMsg);
            break;
        case eCmdI2CTempDS1631ZGetValue:
            OnTempDS1631ZGetValue(p_pMsg);
            break;
            // ADC
        case eCmdI2CAdcMax1037Startup:
            OnAdcMax1037Startup(p_pMsg);
            break;
        case eCmdI2CAdcMax1037Shutdown:
            OnAdcMax1037Shutdown(p_pMsg);
            break;
        case eCmdI2CAdcMax1037Initialize:
            OnAdcMax1037Initialize(p_pMsg);
            break;
        case eCmdI2CAdcMax1037GetData:
            OnAdcMax1037GetData(p_pMsg);
            break;
            // digital poti
        case eCmdI2CPotiAD5245Startup:
            OnPotiAD5245Startup(p_pMsg);
            break;
        case eCmdI2CPotiAD5245Shutdown:
            OnPotiAD5245Shutdown(p_pMsg);
            break;
        case eCmdI2CPotiAD5245WriteValue:
            OnPotiAD5245WriteValue(p_pMsg);
            break;
        case eCmdI2CPotiAD5245ReadValue:
            OnPotiAD5245ReadValue(p_pMsg);
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
  //## end CETChannelI2CBus::ProcessMessage%1055243211.body
}

void CETChannelI2CBus::OnTempDS1631ZStartup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelI2CBus::OnTempDS1631ZStartup%1055243212.body preserve=yes
    ICOSyncInterface* l_pSensor = CPIObjectFactory::GetInstance()->QuerySensorDS1631Z(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pSensor->Startup();

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelI2CBus::OnTempDS1631ZStartup%1055243212.body
}

void CETChannelI2CBus::OnTempDS1631ZShutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelI2CBus::OnTempDS1631ZShutdown%1055243213.body preserve=yes
    ICOSyncInterface* l_pSensor = CPIObjectFactory::GetInstance()->QuerySensorDS1631Z(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pSensor->Shutdown();

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelI2CBus::OnTempDS1631ZShutdown%1055243213.body
}

void CETChannelI2CBus::OnTempDS1631ZSetConfig (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelI2CBus::OnTempDS1631ZSetConfig%1055243214.body preserve=yes
    IPII2CTempSensorDS1631Z* l_pSensor = CPIObjectFactory::GetInstance()->QuerySensorDS1631Z(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageI2CTempDS1631ZConfig* l_pMsg = dynamic_cast<CETChannelMessageI2CTempDS1631ZConfig*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pSensor->SetSensorConfig(l_pMsg->GetpConfig());

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelI2CBus::OnTempDS1631ZSetConfig%1055243214.body
}

void CETChannelI2CBus::OnTempDS1631ZGetValue (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelI2CBus::OnTempDS1631ZGetValue%1055243215.body preserve=yes
    IPII2CTempSensorDS1631Z* l_pSensor = CPIObjectFactory::GetInstance()->QuerySensorDS1631Z(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pSensor->GetTemperature();

    // prepare reply
    CETChannelMessageEnvoyInt* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelI2CBus::OnTempDS1631ZGetValue%1055243215.body
}

void CETChannelI2CBus::OnAdcMax1037Startup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelI2CBus::OnAdcMax1037Startup%1074861335.body preserve=yes
    ICOSyncInterface* l_pAdc = CPIObjectFactory::GetInstance()->QueryADCMAX1037(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pAdc->Startup();

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelI2CBus::OnAdcMax1037Startup%1074861335.body
}

void CETChannelI2CBus::OnAdcMax1037Shutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelI2CBus::OnAdcMax1037Shutdown%1074861336.body preserve=yes
    ICOSyncInterface* l_pAdc = CPIObjectFactory::GetInstance()->QueryADCMAX1037(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pAdc->Shutdown();

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelI2CBus::OnAdcMax1037Shutdown%1074861336.body
}

void CETChannelI2CBus::OnAdcMax1037Initialize (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelI2CBus::OnAdcMax1037Initialize%1074846782.body preserve=yes
    IPII2CADCMAX1037* l_pAdc = CPIObjectFactory::GetInstance()->QueryADCMAX1037(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pAdc->Initialize();

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelI2CBus::OnAdcMax1037Initialize%1074846782.body
}

void CETChannelI2CBus::OnAdcMax1037GetData (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelI2CBus::OnAdcMax1037GetData%1074846783.body preserve=yes
    IPII2CADCMAX1037* l_pAdc = CPIObjectFactory::GetInstance()->QueryADCMAX1037(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pAdc->GetData();

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyI2CAdcMax1037(
        new CETChannelMessageI2CAdcMax1037(p_pMsg->GetpMsg()->GetReply()), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelI2CBus::OnAdcMax1037GetData%1074846783.body
}

void CETChannelI2CBus::OnPotiAD5245Startup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelI2CBus::OnPotiAD5245Startup%1074861337.body preserve=yes
    ICOSyncInterface* l_pPoti= CPIObjectFactory::GetInstance()->QueryDigitalPotiAD5245(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPoti->Startup();

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelI2CBus::OnPotiAD5245Startup%1074861337.body
}

void CETChannelI2CBus::OnPotiAD5245Shutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelI2CBus::OnPotiAD5245Shutdown%1074861338.body preserve=yes
    ICOSyncInterface* l_pPoti = CPIObjectFactory::GetInstance()->QueryDigitalPotiAD5245(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPoti->Shutdown();

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelI2CBus::OnPotiAD5245Shutdown%1074861338.body
}

void CETChannelI2CBus::OnPotiAD5245ReadValue (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelI2CBus::OnPotiAD5245ReadValue%1074846784.body preserve=yes
    IPII2CDigitalPotiAD5245* l_pPoti= CPIObjectFactory::GetInstance()->QueryDigitalPotiAD5245(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPoti->ReadValue();

    // prepare reply
	CETChannelMessageEnvoyInt* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelI2CBus::OnPotiAD5245ReadValue%1074846784.body
}

void CETChannelI2CBus::OnPotiAD5245WriteValue (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelI2CBus::OnPotiAD5245WriteValue%1074846785.body preserve=yes
    IPII2CDigitalPotiAD5245* l_pPoti = CPIObjectFactory::GetInstance()->QueryDigitalPotiAD5245(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pPoti->WriteValue(p_pMsg->GetpMsg()->GetiData());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelI2CBus::OnPotiAD5245WriteValue%1074846785.body
}

// Additional Declarations
  //## begin CETChannelI2CBus%3EE5D34500AE.declarations preserve=yes
  //## end CETChannelI2CBus%3EE5D34500AE.declarations

//## begin module%3EE5C05A008E.epilog preserve=yes
//## end module%3EE5C05A008E.epilog
