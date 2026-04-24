//## begin module%3DAAAD7602C3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAAD7602C3.cm

//## begin module%3DAAAD7602C3.cp preserve=no
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
//## end module%3DAAAD7602C3.cp

//## Module: EBETchcr%3DAAAD7602C3; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchcr.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DAAAD7602C3.additionalIncludes preserve=no
//## end module%3DAAAD7602C3.additionalIncludes

//## begin module%3DAAAD7602C3.includes preserve=yes
//## end module%3DAAAD7602C3.includes

// EBETchcr
#include "EBETchcr.h"
// EBETwrit
#include "EBETwrit.h"
// EBETmesg
#include "EBETmesg.h"
// EBPIfact
#include "EBPIfact.h"
// EBPIintf
#include "EBPIintf.h"


//## begin module%3DAAAD7602C3.declarations preserve=no
//## end module%3DAAAD7602C3.declarations

//## begin module%3DAAAD7602C3.additionalDeclarations preserve=yes
//## end module%3DAAAD7602C3.additionalDeclarations


// Class CETChannelObjCreator 

CETChannelObjCreator::CETChannelObjCreator()
  //## begin CETChannelObjCreator::CETChannelObjCreator%.hasinit preserve=no
  //## end CETChannelObjCreator::CETChannelObjCreator%.hasinit
  //## begin CETChannelObjCreator::CETChannelObjCreator%.initialization preserve=yes
  : CETChannel("Tcp channel obj creator", m_uiPortNoObjCreator)
  //## end CETChannelObjCreator::CETChannelObjCreator%.initialization
{
  //## begin CETChannelObjCreator::CETChannelObjCreator%.body preserve=yes
  //## end CETChannelObjCreator::CETChannelObjCreator%.body
}


CETChannelObjCreator::~CETChannelObjCreator()
{
  //## begin CETChannelObjCreator::~CETChannelObjCreator%.body preserve=yes
  //## end CETChannelObjCreator::~CETChannelObjCreator%.body
}



//## Other Operations (implementation)
void CETChannelObjCreator::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::ProcessMessage%1034230433.body preserve=yes
    switch(p_pMsg->GetpMsg()->GeteCommand())
    {
        case eObjCrDeleteObject:
			OnDeleteObject(p_pMsg);
			break;
        case eObjCrMotorStepper:
            OnCreateStepper(p_pMsg);
            break;
        case eObjCrMeasurementChannel:
            OnCreateMeasurementChannel(p_pMsg);
            break;
        case eObjCrSensorAnalog:
            OnCreateAnalogSensor(p_pMsg);
            break;
        case eObjCrSensorDigital:
            OnCreateDigitalSensor(p_pMsg);
            break;
        case eObjCrOutputAnalog:
            OnCreateAnalogOutput(p_pMsg);
            break;
        case eObjCrOutputDigital:
            OnCreateDigitalOutput(p_pMsg);
            break;
        case eObjCrTemperatureControl:
            OnCreateTemperatureControl(p_pMsg);
            break;
        case eObjCrPowerControl:
            OnCreatePowerControl(p_pMsg);
            break;
        case eObjCrWedgeControl:
            OnCreateWedgeControl(p_pMsg);
            break;
        case eObjCrEventSource:
            OnCreateEventSource(p_pMsg);
            break;
        case eObJCrPersistentObjMananager:
            OnCreatePersistentObjManager(p_pMsg);
            break;
        case eObjCrDiagnostics:
            OnCreateDiagnostics(p_pMsg);
            break;
        case eObjCrSystem:
            OnCreateSystem(p_pMsg);
            break;
        case eObjCrI2CTempSensorDS1631Z:
            OnCreateI2CTempSensorDS1631Z(p_pMsg);
            break;
        case eObjCrI2CAdcMax1037:
            OnCreateI2CAdcMax1037(p_pMsg);
            break;
        case eObjCrI2CDigitalPotiAD5245:
            OnI2CDigitalPotiAD5245(p_pMsg);
            break;
		default:
			CETChannel::ProcessMessage(p_pMsg);
			break;
    }
  //## end CETChannelObjCreator::ProcessMessage%1034230433.body
}

void CETChannelObjCreator::OnDeleteObject (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnDeleteObject%1034407673.body preserve=yes
    CPIObjectFactory::GetInstance()->DeleteObject(p_pMsg->GetpMsg()->GetuiObjRefID());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnDeleteObject%1034407673.body
}

void CETChannelObjCreator::OnCreateStepper (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreateStepper%1034230434.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->CreateStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pMotor->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreateStepper%1034230434.body
}

void CETChannelObjCreator::OnCreateMeasurementChannel (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreateMeasurementChannel%1034575101.body preserve=yes
    IPIMeasurementChannelInterface* l_pMeasurementChannel = CPIObjectFactory::GetInstance()->CreateMeasurementChannel(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pMeasurementChannel->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreateMeasurementChannel%1034575101.body
}

void CETChannelObjCreator::OnCreateAnalogSensor (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreateAnalogSensor%1037103457.body preserve=yes
    IPISensorAnalogInterface* l_pObj = CPIObjectFactory::GetInstance()->CreateAnalogSensor(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreateAnalogSensor%1037103457.body
}

void CETChannelObjCreator::OnCreateDigitalSensor (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreateDigitalSensor%1037103458.body preserve=yes
    IPISensorDigitalInterface* l_pObj = CPIObjectFactory::GetInstance()->CreateDigitalSensor(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreateDigitalSensor%1037103458.body
}

void CETChannelObjCreator::OnCreateAnalogOutput (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreateAnalogOutput%1037103459.body preserve=yes
    IPIOutputAnalogInterface* l_pObj = CPIObjectFactory::GetInstance()->CreateAnalogOutput(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreateAnalogOutput%1037103459.body
}

void CETChannelObjCreator::OnCreateDigitalOutput (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreateDigitalOutput%1037103460.body preserve=yes
    IPIOutputDigitalInterface* l_pObj = CPIObjectFactory::GetInstance()->CreateDigitalOutput(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreateDigitalOutput%1037103460.body
}

void CETChannelObjCreator::OnCreateTemperatureControl (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreateTemperatureControl%1037103461.body preserve=yes
    IPITemperatureControlInterface* l_pObj = CPIObjectFactory::GetInstance()->CreateTemperatureControl(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreateTemperatureControl%1037103461.body
}

void CETChannelObjCreator::OnCreatePowerControl (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreatePowerControl%1037103462.body preserve=yes
    IPIPowerControlInterface* l_pObj = CPIObjectFactory::GetInstance()->CreatePowerControl(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreatePowerControl%1037103462.body
}

void CETChannelObjCreator::OnCreateWedgeControl (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreateWedgeControl%1037103463.body preserve=yes
    IPIWedgeControlInterface* l_pObj = CPIObjectFactory::GetInstance()->CreateWedgeControl(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreateWedgeControl%1037103463.body
}

void CETChannelObjCreator::OnCreateEventSource (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreateEventSource%1037103464.body preserve=yes
    IPIEventSourceInterface* l_pObj = CPIObjectFactory::GetInstance()->CreateEventSource(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreateEventSource%1037103464.body
}

void CETChannelObjCreator::OnCreatePersistentObjManager (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreatePersistentObjManager%1037103465.body preserve=yes
    IPIPersistentObjInterface* l_pObj = CPIObjectFactory::GetInstance()->CreatePersistentObjectManager(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreatePersistentObjManager%1037103465.body
}

void CETChannelObjCreator::OnCreateDiagnostics (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreateDiagnostics%1039623391.body preserve=yes
    IPIDiagnosticInterface* l_pObj = CPIObjectFactory::GetInstance()->CreateDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreateDiagnostics%1039623391.body
}

void CETChannelObjCreator::OnCreateSystem (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreateSystem%1055492120.body preserve=yes
    IPISystemInterface* l_pObj = CPIObjectFactory::GetInstance()->QuerySystemInterface();

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreateSystem%1055492120.body
}

void CETChannelObjCreator::OnCreateI2CTempSensorDS1631Z (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreateI2CTempSensorDS1631Z%1055492121.body preserve=yes
    IPII2CTempSensorDS1631Z* l_pObj = CPIObjectFactory::GetInstance()->CreateSensorDS1631Z(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
	l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreateI2CTempSensorDS1631Z%1055492121.body
}

void CETChannelObjCreator::OnCreateI2CAdcMax1037 (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnCreateI2CAdcMax1037%1074848545.body preserve=yes
    IPII2CADCMAX1037* l_pObj = CPIObjectFactory::GetInstance()->CreateADCMAX1037(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
    l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnCreateI2CAdcMax1037%1074848545.body
}

void CETChannelObjCreator::OnI2CDigitalPotiAD5245 (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelObjCreator::OnI2CDigitalPotiAD5245%1074848546.body preserve=yes
    IPII2CDigitalPotiAD5245* l_pObj = CPIObjectFactory::GetInstance()->CreateDigitalPotiAD5245(p_pMsg->GetpMsg()->GetuiObjRefID(), p_pMsg->GetpMsg()->GetsObjRefVersion());

    // send reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply());
    l_pReply->GetpMsg()->SetuiObjRefID(l_pObj->GetuiID());

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelObjCreator::OnI2CDigitalPotiAD5245%1074848546.body
}

// Additional Declarations
  //## begin CETChannelObjCreator%3DA2F3260378.declarations preserve=yes
  //## end CETChannelObjCreator%3DA2F3260378.declarations

//## begin module%3DAAAD7602C3.epilog preserve=yes
//## end module%3DAAAD7602C3.epilog
