//## begin module%3DF72EE90279.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DF72EE90279.cm

//## begin module%3DF72EE90279.cp preserve=no
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
//## end module%3DF72EE90279.cp

//## Module: EBETchdg%3DF72EE90279; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchdg.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DF72EE90279.additionalIncludes preserve=no
//## end module%3DF72EE90279.additionalIncludes

//## begin module%3DF72EE90279.includes preserve=yes
//## end module%3DF72EE90279.includes

// EBETchdg
#include "EBETchdg.h"
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
//## begin module%3DF72EE90279.declarations preserve=no
//## end module%3DF72EE90279.declarations

//## begin module%3DF72EE90279.additionalDeclarations preserve=yes
//## end module%3DF72EE90279.additionalDeclarations


// Class CETChannelDiagnostics 

CETChannelDiagnostics::CETChannelDiagnostics()
  //## begin CETChannelDiagnostics::CETChannelDiagnostics%.hasinit preserve=no
  //## end CETChannelDiagnostics::CETChannelDiagnostics%.hasinit
  //## begin CETChannelDiagnostics::CETChannelDiagnostics%.initialization preserve=yes
  : CETChannel("Tcp channel Diagnostic", m_uiPortNoDiagnostic)
  //## end CETChannelDiagnostics::CETChannelDiagnostics%.initialization
{
  //## begin CETChannelDiagnostics::CETChannelDiagnostics%.body preserve=yes
  //## end CETChannelDiagnostics::CETChannelDiagnostics%.body
}


CETChannelDiagnostics::~CETChannelDiagnostics()
{
  //## begin CETChannelDiagnostics::~CETChannelDiagnostics%.body preserve=yes
  //## end CETChannelDiagnostics::~CETChannelDiagnostics%.body
}



//## Other Operations (implementation)
CETChannelMessage* CETChannelDiagnostics::UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength)
{
  //## begin CETChannelDiagnostics::UnwrapTelegram%1039609797.body preserve=yes
    CETChannelMessage* l_pMsg = CETChannel::UnwrapTelegram(p_pbyStream, p_uiStreamLength);
    switch(l_pMsg->GeteCommand())
    {
        case eCmdDiagReadDWord:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageTwoInteger(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdDiagWriteDWord:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageTwoInteger(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdDiagI2CEpromByteRead:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageTwoInteger(p_pbyStream, p_uiStreamLength);
            break;
        case eCmdDiagI2CEpromByteWrite:
            delete l_pMsg;
            l_pMsg = new CETChannelMessageTwoInteger(p_pbyStream, p_uiStreamLength);
            break;            
    }

    return l_pMsg;
  //## end CETChannelDiagnostics::UnwrapTelegram%1039609797.body
}

void CETChannelDiagnostics::ProcessMessage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::ProcessMessage%1039609788.body preserve=yes
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
            case eCmdDiagReadDWord:
                OnReadDWord(p_pMsg);
		        break;
            case eCmdDiagWriteDWord:
                OnWriteDWord(p_pMsg);
		        break;
            case eCmdDiagEnableEventSignal:
                OnEnableEventSignalisation(p_pMsg);
		        break;
            case eCmdDiagDisableEventSignal:
                OnDisableEventSignalisation(p_pMsg);
		        break;
            case eCmdDiagPCSetNomVoltage:
                OnPCSetNomVoltage(p_pMsg);
                break;
            case eCmdDiagPCLampSelection:
                OnPCLampSelection(p_pMsg);
                break;
            case eCmdDiagPCLampOnOff:
                OnPCLampOnOff(p_pMsg);
                break;
            case eCmdDiagPCGetActCurrent:
                OnPCGetActCurrent(p_pMsg);
                break;
            case eCmdDiagPCGetActVoltage:
                OnPCGetActVoltage(p_pMsg);
                break;
            case eCmdDiagPCGetLampIdentification:
                OnPCGetLampIdentification(p_pMsg);
                break;
            case eCmdDiagWCGetActVelocityCounts:
                OnWCGetActVelocityCounts(p_pMsg);
                break;
            case eCmdDiagWCGetLastVelocityCounts:
                OnWCGetLastVelocityCounts(p_pMsg);
                break;
            case eCmdDiagWCGetPosition:
                OnWCGetPosition(p_pMsg);
                break;
            case eCmdDiagWCInitializeDAC:
                OnWCInitializeDAC(p_pMsg);
                break;
            case eCmdDiagWCSetDACValue:
                OnWCSetDACValue(p_pMsg);
                break;
            case eCmdDiagReadFpgaArtNr:
                OnReadFpgaArtNr(p_pMsg);
                break;
            case eCmdDiagReadFpgaSwVersion:
                OnReadFpgaSwVersion(p_pMsg);
                break;
            case eCmdDiagI2CEpromByteRead:
                OnI2CEpromByteRead(p_pMsg);
                break;
            case eCmdDiagI2CEpromByteWrite:
                OnI2CEpromByteWrite(p_pMsg);
                break;

            case eCmdDiagGetDigitsLaserLevelDetection:
                OnGetDigitsLaserLevelDetection(p_pMsg);
                break;

            case eCmdDiagReleaseHWReset:
                OnReleaseHWReset(p_pMsg);
                break;

            case eCmdDiagDisableWatchdog:
                OnDisableWatchdog(p_pMsg);
                break;

            case eCmdDiagGetOsVersion:
                OnGetOsVersion(p_pMsg);
                break;

            case eCmdDiagGetUsedMemory:
                OnGetUsedMemory(p_pMsg);
                break;

			case eCmdDiagGetMemoryAllocInfo:
				OnGetMemoryAllocInfo(p_pMsg);
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
  //## end CETChannelDiagnostics::ProcessMessage%1039609788.body
}

void CETChannelDiagnostics::OnStartup (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnStartup%1039609789.body preserve=yes
    IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->Startup();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnStartup%1039609789.body
}

void CETChannelDiagnostics::OnShutdown (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnShutdown%1039609790.body preserve=yes
    IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->Shutdown();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnShutdown%1039609790.body
}

void CETChannelDiagnostics::OnReadDWord (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnReadDWord%1039609791.body preserve=yes
    IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageTwoInteger* l_pMsg = dynamic_cast<CETChannelMessageTwoInteger*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->ReadDWord((UINT)l_pMsg->GetiInt0(), (EPIRegisterType)l_pMsg->GetiInt1());

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyInt(
        p_pMsg->GetpMsg()->GetReply(),l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnReadDWord%1039609791.body
}

void CETChannelDiagnostics::OnWriteDWord (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnWriteDWord%1039609792.body preserve=yes
    IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
    CETChannelMessageTwoInteger* l_pMsg = dynamic_cast<CETChannelMessageTwoInteger*>(p_pMsg->GetpMsg());
    ASSERT(l_pMsg != NULL);
    CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->WriteDWord((UINT)l_pMsg->GetiInt0(), (UINT)l_pMsg->GetiInt1(), (EPIRegisterType)l_pMsg->GetiData());

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnWriteDWord%1039609792.body
}

void CETChannelDiagnostics::OnEnableEventSignalisation (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnEnableEventSignalisation%1066286191.body preserve=yes
    IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->EnableEventSignalisation();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnEnableEventSignalisation%1066286191.body
}

void CETChannelDiagnostics::OnDisableEventSignalisation (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnDisableEventSignalisation%1066286192.body preserve=yes
    IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->DisableEventSignalisation();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnDisableEventSignalisation%1066286192.body
}

void CETChannelDiagnostics::OnPCSetNomVoltage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnPCSetNomVoltage%1095062172.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->PCSetNomVoltage((DWORD)p_pMsg->GetpMsg()->GetiData());

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnPCSetNomVoltage%1095062172.body
}

void CETChannelDiagnostics::OnPCLampSelection (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnPCLampSelection%1095062173.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->PCLampSelection((EPILamp)p_pMsg->GetpMsg()->GetiData());

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnPCLampSelection%1095062173.body
}

void CETChannelDiagnostics::OnPCLampOnOff (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnPCLampOnOff%1095062174.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  
  bool l_bValue;
  if (p_pMsg->GetpMsg()->GetiData() == 0)
    l_bValue = false;
  else
    l_bValue = true;

  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->PCLampOnOff(l_bValue);

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnPCLampOnOff%1095062174.body
}

void CETChannelDiagnostics::OnPCGetActCurrent (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnPCGetActCurrent%1095062175.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->PCGetActCurrent();

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnPCGetActCurrent%1095062175.body
}

void CETChannelDiagnostics::OnPCGetActVoltage (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnPCGetActVoltage%1095062176.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->PCGetActVoltage((EPILamp)p_pMsg->GetpMsg()->GetiData());

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnPCGetActVoltage%1095062176.body
}

void CETChannelDiagnostics::OnPCGetLampIdentification (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnPCGetLampIdentification%1095062177.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->PCGetLampIdentification((EPILamp)p_pMsg->GetpMsg()->GetiData());

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnPCGetLampIdentification%1095062177.body
}

void CETChannelDiagnostics::OnWCGetActVelocityCounts (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnWCGetActVelocityCounts%1095062178.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->WCGetActVelocityCounts();

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnWCGetActVelocityCounts%1095062178.body
}

void CETChannelDiagnostics::OnWCGetLastVelocityCounts (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnWCGetLastVelocityCounts%1095062179.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->WCGetLastVelocityCounts();

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnWCGetLastVelocityCounts%1095062179.body
}

void CETChannelDiagnostics::OnWCGetPosition (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnWCGetPosition%1095062180.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->WCGetPosition();

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnWCGetPosition%1095062180.body
}

void CETChannelDiagnostics::OnWCInitializeDAC (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnWCInitializeDAC%1095062181.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->WCInitializeDAC();

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnWCInitializeDAC%1095062181.body
}

void CETChannelDiagnostics::OnWCSetDACValue (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnWCSetDACValue%1095062182.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->WCSetDACValue((DWORD)p_pMsg->GetpMsg()->GetiData());

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnWCSetDACValue%1095062182.body
}

void CETChannelDiagnostics::OnReadFpgaArtNr (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnReadFpgaArtNr%1095062183.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->ReadFpgaArtNr();

  // prepare reply
  CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyString(
        new CETChannelMessageString(p_pMsg->GetpMsg()->GetReply()), l_pSyncObj);

  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnReadFpgaArtNr%1095062183.body
}

void CETChannelDiagnostics::OnReadFpgaSwVersion (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnReadFpgaSwVersion%1095062184.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->ReadFpgaSwVersion();

  // prepare reply
  CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyString(
        new CETChannelMessageString(p_pMsg->GetpMsg()->GetReply()), l_pSyncObj);

  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnReadFpgaSwVersion%1095062184.body
}

void CETChannelDiagnostics::OnI2CEpromByteRead (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnI2CEpromByteRead%1095062185.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CETChannelMessageTwoInteger* l_pMsg = dynamic_cast<CETChannelMessageTwoInteger*>(p_pMsg->GetpMsg());
  ASSERT(l_pMsg != NULL);
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->I2CEpromByteRead((DWORD)l_pMsg->GetiInt0(),(WORD)l_pMsg->GetiInt1());

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnI2CEpromByteRead%1095062185.body
}

void CETChannelDiagnostics::OnI2CEpromByteWrite (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnI2CEpromByteWrite%1095062186.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CETChannelMessageTwoInteger* l_pMsg = dynamic_cast<CETChannelMessageTwoInteger*>(p_pMsg->GetpMsg());
  ASSERT(l_pMsg != NULL);
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->I2CEpromByteWrite((DWORD)p_pMsg->GetpMsg()->GetiData(),(WORD)l_pMsg->GetiInt0(),(BYTE)l_pMsg->GetiInt1());

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnI2CEpromByteWrite%1095062186.body
}

void CETChannelDiagnostics::OnGetDigitsLaserLevelDetection (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnGetDigitsLaserLevelDetection%1097656363.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->GetDigitsLaserLevelDetection();

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyInt(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnGetDigitsLaserLevelDetection%1097656363.body
}

void CETChannelDiagnostics::OnReleaseHWReset (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnReleaseHWReset%1097656364.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->ReleaseHWReset();

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnReleaseHWReset%1097656364.body
}

void CETChannelDiagnostics::OnDisableWatchdog (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnDisableWatchdog%1097656365.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->DisableWatchdog();

  // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoy(p_pMsg->GetpMsg()->GetReply(), l_pSyncObj);
  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnDisableWatchdog%1097656365.body
}

void CETChannelDiagnostics::OnGetOsVersion (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnGetOsVersion%1108366392.body preserve=yes
  IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
  CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->GetOsVersion();

  // prepare reply
  CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyString(
        new CETChannelMessageString(p_pMsg->GetpMsg()->GetReply()), l_pSyncObj);

  FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnGetOsVersion%1108366392.body
}

void CETChannelDiagnostics::OnGetUsedMemory (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnGetUsedMemory%1174554256.body preserve=yes
    IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->GetUsedMemory();

    // prepare reply
    CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyInt(
        p_pMsg->GetpMsg()->GetReply(),l_pSyncObj);

    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnGetUsedMemory%1174554256.body
}

void CETChannelDiagnostics::OnGetMemoryAllocInfo (CETChannelMessageEnvoy* p_pMsg)
{
  //## begin CETChannelDiagnostics::OnGetMemoryAllocInfo%1174997742.body preserve=yes
    IPIDiagnosticInterface* l_pDiagIntf = CPIObjectFactory::GetInstance()->QueryDiagnostic(p_pMsg->GetpMsg()->GetuiObjRefID());
    CCOSyncObjectPtr l_pSyncObj = l_pDiagIntf->GetMemoryAllocInfo();

    // prepare reply
	CETChannelMessageEnvoy* l_pReply = new CETChannelMessageEnvoyString(
        new CETChannelMessageString(p_pMsg->GetpMsg()->GetReply()), l_pSyncObj);
    FindWriter(p_pMsg->GethSocket())->AddMessage(l_pReply);
  //## end CETChannelDiagnostics::OnGetMemoryAllocInfo%1174997742.body
}

// Additional Declarations
  //## begin CETChannelDiagnostics%3DF72EBF025A.declarations preserve=yes
  //## end CETChannelDiagnostics%3DF72EBF025A.declarations

//## begin module%3DF72EE90279.epilog preserve=yes
//## end module%3DF72EE90279.epilog
