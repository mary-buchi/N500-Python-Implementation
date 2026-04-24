//## begin module%3DAAACF20004.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAACF20004.cm

//## begin module%3DAAACF20004.cp preserve=no
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
//## end module%3DAAACF20004.cp

//## Module: EBETchst%3DAAACF20004; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchst.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DAAACF20004.additionalIncludes preserve=no
//## end module%3DAAACF20004.additionalIncludes

//## begin module%3DAAACF20004.includes preserve=yes
//## end module%3DAAACF20004.includes

// EBETchst
#include "EBETchst.h"
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


//## begin module%3DAAACF20004.declarations preserve=no
//## end module%3DAAACF20004.declarations

//## begin module%3DAAACF20004.additionalDeclarations preserve=yes
//## end module%3DAAACF20004.additionalDeclarations


// Class CETChannelStepperMotors 

CETChannelStepperMotors::CETChannelStepperMotors()
  //## begin CETChannelStepperMotors::CETChannelStepperMotors%.hasinit preserve=no
  //## end CETChannelStepperMotors::CETChannelStepperMotors%.hasinit
  //## begin CETChannelStepperMotors::CETChannelStepperMotors%.initialization preserve=yes
  : CETChannel("Tcp channel stepper motors", m_uiPortNoStepperMotors)
  //## end CETChannelStepperMotors::CETChannelStepperMotors%.initialization
{
  //## begin CETChannelStepperMotors::CETChannelStepperMotors%.body preserve=yes
  //## end CETChannelStepperMotors::CETChannelStepperMotors%.body
}


CETChannelStepperMotors::~CETChannelStepperMotors()
{
  //## begin CETChannelStepperMotors::~CETChannelStepperMotors%.body preserve=yes
  //## end CETChannelStepperMotors::~CETChannelStepperMotors%.body
}



//## Other Operations (implementation)
CETChannelMessage* CETChannelStepperMotors::UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength)
{
  //## begin CETChannelStepperMotors::UnwrapTelegram%1035273380.body preserve=yes
    CETChannelMessage* l_pMsg = CETChannel::UnwrapTelegram(p_pbyStream, p_uiStreamLength);
    switch(l_pMsg->GeteCommand())
    {
        case eCmdStepperMoveAbsolute:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageTwoInteger(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdStepperMoveRelative:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageTwoInteger(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdStepperMoveManual:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageTwoInteger(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdStepperSetConfig:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageStepperConfig(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdStepperSetProfile:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageStepperProfile(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdStepperLimitAdd:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageStepperLimit(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdStepperLimitConfig:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageStepperLimit(p_pbyStream, p_uiStreamLength);
            break;
		case eCmdStepperHome:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageTwoInteger(p_pbyStream, p_uiStreamLength);
            break;
		case eCmdStepperHome2:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageStepperHome(p_pbyStream, p_uiStreamLength);
            break;
    }

    return l_pMsg;
  //## end CETChannelStepperMotors::UnwrapTelegram%1035273380.body
}

void CETChannelStepperMotors::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::ProcessMessage%1034230448.body preserve=yes
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
            case eCmdStepperMoveAbsolute:
                OnMoveAbsolute(p_pMsg);
                break;
            case eCmdStepperMoveRelative:
                OnMoveRelative(p_pMsg);
                break;
            case eCmdStepperMoveManual:
                OnMoveManual(p_pMsg);
                break;
            case eCmdStepperGetPosition:
                OnGetPosition(p_pMsg);
                break;
            case eCmdStepperStop:
                OnStop(p_pMsg);
                break;
            case eCmdStepperStopImmediately:
                OnStopImmediately(p_pMsg);
                break;
            case eCmdStepperSetProfile:
                OnSetProfile(p_pMsg);
                break;
            case eCmdStepperSetConfig:
                OnSetConfig(p_pMsg);
                break;
            case eCmdStepperSetSpeed:
                OnSetSpeed(p_pMsg);
                break;
            case eCmdStepperLimitAdd:
                OnLimitAdd(p_pMsg);
                break;
            case eCmdStepperLimitConfig:
                OnLimitConfig(p_pMsg);
                break;
            case eCmdStepperLimitGetFootPrint:
                OnLimitGetFootPrint(p_pMsg);
                break;
            case eCmdStepperLimitActivate:
                OnLimitActivate(p_pMsg);
                break;
            case eCmdStepperLimitDeactivate:
                OnLimitDeactivate(p_pMsg);
                break;
            case eCmdStepperHome:
                OnHome(p_pMsg);
                break;
            case eCmdStepperHome2:
                OnHome2(p_pMsg);
                break;
            case eCmdStepperHomeSetPosition:
                OnHomeSetPosition(p_pMsg);
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
  //## end CETChannelStepperMotors::ProcessMessage%1034230448.body
}

void CETChannelStepperMotors::OnStartup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnStartup%1034230449.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->Startup();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnStartup%1034230449.body
}

void CETChannelStepperMotors::OnShutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnShutdown%1034407672.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->Shutdown();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnShutdown%1034407672.body
}

void CETChannelStepperMotors::OnMoveAbsolute (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnMoveAbsolute%1035273377.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageTwoInteger* l_pMsg = dynamic_cast<CETChannelMessageTwoInteger*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);

    CCOSyncObjectPtr l_pSyncObj = l_pMotor->MoveAbsolute(l_pMsg->GetiInt0(), l_pMsg->GetiInt1());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnMoveAbsolute%1035273377.body
}

void CETChannelStepperMotors::OnMoveRelative (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnMoveRelative%1036680699.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageTwoInteger* l_pMsg = dynamic_cast<CETChannelMessageTwoInteger*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);

    CCOSyncObjectPtr l_pSyncObj = l_pMotor->MoveRelative(l_pMsg->GetiInt0(), l_pMsg->GetiInt1());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnMoveRelative%1036680699.body
}

void CETChannelStepperMotors::OnMoveManual (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnMoveManual%1036680700.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageTwoInteger* l_pMsg = dynamic_cast<CETChannelMessageTwoInteger*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);

    CCOSyncObjectPtr l_pSyncObj = l_pMotor->MoveManual(l_pMsg->GetiInt0(), l_pMsg->GetiInt1());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnMoveManual%1036680700.body
}

void CETChannelStepperMotors::OnGetPosition (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnGetPosition%1034575093.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->GetPosition();

    // prepare reply
	CETChannelMessageEnvoyInt* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnGetPosition%1034575093.body
}

void CETChannelStepperMotors::OnStop (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnStop%1036680701.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->Stop();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnStop%1036680701.body
}

void CETChannelStepperMotors::OnStopImmediately (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnStopImmediately%1036680702.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->StopImmediately();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnStopImmediately%1036680702.body
}

void CETChannelStepperMotors::OnSetProfile (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnSetProfile%1036680703.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageStepperProfile* l_pMsg = dynamic_cast<CETChannelMessageStepperProfile*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->SetProfile(l_pMsg->GetpProfile());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnSetProfile%1036680703.body
}

void CETChannelStepperMotors::OnSetConfig (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnSetConfig%1049965452.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageStepperConfig* l_pMsg = dynamic_cast<CETChannelMessageStepperConfig*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->SetConfig(l_pMsg->GetpConfig());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnSetConfig%1049965452.body
}

void CETChannelStepperMotors::OnSetSpeed (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnSetSpeed%1036680704.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->SetSpeed(p_pMsg->GetpMsg()->GetiData());

    // prepare reply
	CETChannelMessageEnvoyInt* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnSetSpeed%1036680704.body
}

void CETChannelStepperMotors::OnLimitAdd (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnLimitAdd%1036680705.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageStepperLimit* l_pMsg = dynamic_cast<CETChannelMessageStepperLimit*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
	CPIObjIdentification* l_pObjID = new CPIObjIdentification(l_pMsg->GetuiSensorID());
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->LimitAdd(l_pObjID, l_pMsg->GeteLimitCharacteristics(), l_pMsg->GeteLimitAction());
    l_pObjID->ReleaseRef();

    // prepare reply
	  CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnLimitAdd%1036680705.body
}

void CETChannelStepperMotors::OnLimitConfig (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnLimitConfig%1036680706.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageStepperLimit* l_pMsg = dynamic_cast<CETChannelMessageStepperLimit*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CPIObjIdentification* l_pObjID = new CPIObjIdentification(l_pMsg->GetuiSensorID());
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->LimitConfig(l_pObjID, l_pMsg->GeteLimitCharacteristics(), l_pMsg->GeteLimitAction());
    l_pObjID->ReleaseRef();
    // prepare reply
	  CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnLimitConfig%1036680706.body
}

void CETChannelStepperMotors::OnLimitGetFootPrint (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnLimitGetFootPrint%1036680707.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->LimitGetFootPrint();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyStepperLimitFootPrint(
            new CETChannelMessageStepperLimitFootPrint(p_pMsg->GetpMsg()->GetReply()),
            l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnLimitGetFootPrint%1036680707.body
}

void CETChannelStepperMotors::OnLimitActivate (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnLimitActivate%1036680708.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->LimitActivate();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnLimitActivate%1036680708.body
}

void CETChannelStepperMotors::OnLimitDeactivate (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnLimitDeactivate%1036680709.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->LimitDeactivate();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnLimitDeactivate%1036680709.body
}

void CETChannelStepperMotors::OnHome (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnHome%1036680710.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());

	CETChannelMessageTwoInteger* l_pMsg = dynamic_cast<CETChannelMessageTwoInteger*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);

	EPIMotorPolarity l_ePolarity = (EPIMotorPolarity)l_pMsg->GetiInt0();
	CPIObjIdentification* l_pObjID = new CPIObjIdentification(l_pMsg->GetiInt1());
    
	CCOSyncObjectPtr l_pSyncObj = l_pMotor->Home(l_ePolarity, l_pObjID);

    // prepare reply
	CETChannelMessageEnvoyInt* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnHome%1036680710.body
}

void CETChannelStepperMotors::OnHome2 (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnHome2%1193077640.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());

	CETChannelMessageStepperHome* l_pMsg = dynamic_cast<CETChannelMessageStepperHome*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);

	CPIObjIdentification* l_pObjID = new CPIObjIdentification(l_pMsg->GetiLimitID());
    
	CCOSyncObjectPtr l_pSyncObj = l_pMotor->Home(l_pMsg->GeteFastFindingDirection(), l_pMsg->GetbSearchLimitFromOpposite(), l_pObjID);

    // prepare reply
	CETChannelMessageEnvoyInt* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnHome2%1193077640.body
}

void CETChannelStepperMotors::OnHomeSetPosition (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelStepperMotors::OnHomeSetPosition%1036680711.body preserve=yes
    IPIStepperMotorInterface* l_pMotor = CPIObjectFactory::GetInstance()->QueryStepperMotor(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pMotor->HomeSetPosition(p_pMsg->GetpMsg()->GetiData());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelStepperMotors::OnHomeSetPosition%1036680711.body
}

// Additional Declarations
  //## begin CETChannelStepperMotors%3DA58EA500A5.declarations preserve=yes
  //## end CETChannelStepperMotors%3DA58EA500A5.declarations

//## begin module%3DAAACF20004.epilog preserve=yes
//## end module%3DAAACF20004.epilog
