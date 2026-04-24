//## begin module%3EED8B600131.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED8B600131.cm

//## begin module%3EED8B600131.cp preserve=no
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
//## end module%3EED8B600131.cp

//## Module: EBSYcons%3EED8B600131; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYcons.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED8B600131.additionalIncludes preserve=no
//## end module%3EED8B600131.additionalIncludes

//## begin module%3EED8B600131.includes preserve=yes
#include "Iphlpapi.h"
//## end module%3EED8B600131.includes

// EBPItias
#include "EBPItias.h"
// EBPIcpst
#include "EBPIcpst.h"
// EBPIfact
#include "EBPIfact.h"
// EBPImain
#include "EBPImain.h"
// EBSYmhan
#include "EBSYmhan.h"
// EBSYshdn
#include "EBSYshdn.h"
// EBSYcrea
#include "EBSYcrea.h"
// EBSYimpl
#include "EBSYimpl.h"
// EBSYifse
#include "EBSYifse.h"
// EBSYcntd
#include "EBSYcntd.h"
// EBSYcons
#include "EBSYcons.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3EED8B600131.declarations preserve=no
//## end module%3EED8B600131.declarations

//## begin module%3EED8B600131.additionalDeclarations preserve=yes
//## end module%3EED8B600131.additionalDeclarations


// Class CSYStateConstitutionStandByWarmingUp 

//## begin CSYStateConstitutionStandByWarmingUp::pInstance%3EDC5B9C0324.role preserve=no  public: static CSYStateConstitutionStandByWarmingUp {1..1 -> 1..1RFHN}
CSYStateConstitutionStandByWarmingUp *CSYStateConstitutionStandByWarmingUp::m_pInstance = NULL;
//## end CSYStateConstitutionStandByWarmingUp::pInstance%3EDC5B9C0324.role


CSYStateConstitutionStandByWarmingUp::CSYStateConstitutionStandByWarmingUp()
  //## begin CSYStateConstitutionStandByWarmingUp::CSYStateConstitutionStandByWarmingUp%.hasinit preserve=no
  //## end CSYStateConstitutionStandByWarmingUp::CSYStateConstitutionStandByWarmingUp%.hasinit
  //## begin CSYStateConstitutionStandByWarmingUp::CSYStateConstitutionStandByWarmingUp%.initialization preserve=yes
  //## end CSYStateConstitutionStandByWarmingUp::CSYStateConstitutionStandByWarmingUp%.initialization
{
  //## begin CSYStateConstitutionStandByWarmingUp::CSYStateConstitutionStandByWarmingUp%.body preserve=yes
  //## end CSYStateConstitutionStandByWarmingUp::CSYStateConstitutionStandByWarmingUp%.body
}


CSYStateConstitutionStandByWarmingUp::~CSYStateConstitutionStandByWarmingUp()
{
  //## begin CSYStateConstitutionStandByWarmingUp::~CSYStateConstitutionStandByWarmingUp%.body preserve=yes
  //## end CSYStateConstitutionStandByWarmingUp::~CSYStateConstitutionStandByWarmingUp%.body
}



//## Other Operations (implementation)
void CSYStateConstitutionStandByWarmingUp::Create ()
{
  //## begin CSYStateConstitutionStandByWarmingUp::Create%1044959869.body preserve=yes

	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSYStateConstitutionStandByWarmingUp();

  //## end CSYStateConstitutionStandByWarmingUp::Create%1044959869.body
}

void CSYStateConstitutionStandByWarmingUp::Delete ()
{
  //## begin CSYStateConstitutionStandByWarmingUp::Delete%1044959871.body preserve=yes

    delete m_pInstance;
    m_pInstance = NULL;

  //## end CSYStateConstitutionStandByWarmingUp::Delete%1044959871.body
}

CSYStateConstitutionStandByWarmingUp* CSYStateConstitutionStandByWarmingUp::GetInstance ()
{
  //## begin CSYStateConstitutionStandByWarmingUp::GetInstance%1044959870.body preserve=yes

    ASSERT(m_pInstance != NULL);
    return m_pInstance;

  //## end CSYStateConstitutionStandByWarmingUp::GetInstance%1044959870.body
}

EPIDeviceState CSYStateConstitutionStandByWarmingUp::GetDeviceState ()
{
  //## begin CSYStateConstitutionStandByWarmingUp::GetDeviceState%1056436750.body preserve=yes
    return eNotConnected;
  //## end CSYStateConstitutionStandByWarmingUp::GetDeviceState%1056436750.body
}

void CSYStateConstitutionStandByWarmingUp::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionStandByWarmingUp::ConnectionEstablished%1055753492.body preserve=yes
    p_pContext->ChangeState(CSYStateConstitutionConnected::GetInstance());
  //## end CSYStateConstitutionStandByWarmingUp::ConnectionEstablished%1055753492.body
}

void CSYStateConstitutionStandByWarmingUp::ResetDevice (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionStandByWarmingUp::ResetDevice%1056640217.body preserve=yes
    CSYStateShuttingDown::GetInstance()->SetbRebootSystem(true);
  	p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());
  //## end CSYStateConstitutionStandByWarmingUp::ResetDevice%1056640217.body
}

void CSYStateConstitutionStandByWarmingUp::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionStandByWarmingUp::Enter%1083737618.body preserve=yes
    GetpContext(p_pContext)->ResetClient();
    GetpContext(p_pContext)->StartTimer(GetpContext(p_pContext)->GetuiWarmupTimeout());
  //## end CSYStateConstitutionStandByWarmingUp::Enter%1083737618.body
}

void CSYStateConstitutionStandByWarmingUp::OnTimer (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionStandByWarmingUp::OnTimer%1083737619.body preserve=yes
    p_pContext->ChangeState(CSYStateConstitutionStandBy::GetInstance());
  //## end CSYStateConstitutionStandByWarmingUp::OnTimer%1083737619.body
}

void CSYStateConstitutionStandByWarmingUp::Exit (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionStandByWarmingUp::Exit%1083737620.body preserve=yes
    GetpContext(p_pContext)->StopTimer();
  //## end CSYStateConstitutionStandByWarmingUp::Exit%1083737620.body
}

// Additional Declarations
  //## begin CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.declarations preserve=yes
  //## end CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.declarations

// Class CSYStateConstitution 

CSYStateConstitution::CSYStateConstitution()
  //## begin CSYStateConstitution::CSYStateConstitution%.hasinit preserve=no
  //## end CSYStateConstitution::CSYStateConstitution%.hasinit
  //## begin CSYStateConstitution::CSYStateConstitution%.initialization preserve=yes
  //## end CSYStateConstitution::CSYStateConstitution%.initialization
{
  //## begin CSYStateConstitution::CSYStateConstitution%.body preserve=yes
  //## end CSYStateConstitution::CSYStateConstitution%.body
}


CSYStateConstitution::~CSYStateConstitution()
{
  //## begin CSYStateConstitution::~CSYStateConstitution%.body preserve=yes
  //## end CSYStateConstitution::~CSYStateConstitution%.body
}



//## Other Operations (implementation)
void CSYStateConstitution::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitution::Shutdown%1044959867.body preserve=yes
	p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());
  //## end CSYStateConstitution::Shutdown%1044959867.body
}

EPIDeviceState CSYStateConstitution::GetDeviceState ()
{
  //## begin CSYStateConstitution::GetDeviceState%1056436741.body preserve=yes
    return eNotConnected;
  //## end CSYStateConstitution::GetDeviceState%1056436741.body
}

void CSYStateConstitution::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitution::Startup%1064318158.body preserve=yes
  //## end CSYStateConstitution::Startup%1064318158.body
}

void CSYStateConstitution::GetVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYStateConstitution::GetVersion%1096656419.body preserve=yes
    CCOSyncObjectCString* l_pSyncObj = dynamic_cast<CCOSyncObjectCString*>(p_pClientSyncObj);
    ASSERT(l_pSyncObj != NULL);

    l_pSyncObj->SetValue(GetpContext(p_pContext)->GetSoftwareVersion());
  //## end CSYStateConstitution::GetVersion%1096656419.body
}

void CSYStateConstitution::CleanupStop (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitution::CleanupStop%1083651472.body preserve=yes
    CleanupInitialize(p_pContext);
  //## end CSYStateConstitution::CleanupStop%1083651472.body
}

void CSYStateConstitution::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitution::CleanupInitialize%1083651473.body preserve=yes
    CSYStateShuttingDown::GetInstance()->SetbRebootSystem(true);
    p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());
  //## end CSYStateConstitution::CleanupInitialize%1083651473.body
}

void CSYStateConstitution::WarmUp ()
{
  //## begin CSYStateConstitution::WarmUp%1083700294.body preserve=yes
	bool l_bHardwareExist = CPIComponentsState::GetInstance()->GetComponentState(_T("PC"));

	IHIInterface *l_pHIIntf = CHIInterface::GetInstance();
	ASSERT(l_pHIIntf != NULL);

	if (l_bHardwareExist)
	{
		//////////////////////////////////////////////////////////////////////////////
		// Start lamp
		// get ID's
		const DWORD l_dwIDLampSelection	= l_pHIIntf->GetStaticObjID(eHIIDLmpSelection);
		const DWORD l_dwIDLampOnOff		= l_pHIIntf->GetStaticObjID(eHIIDLmpOnOff);
		const DWORD l_dwIDActCurrent	= l_pHIIntf->GetStaticObjID(eHIIDLmpActCurrent);

		// constants
		const DWORD l_uiNomVoltageLLimit = l_pHIIntf->GetStaticObjID(eHILmpNomVoltageLLimit);
		const DWORD l_uiStandByVoltage = l_pHIIntf->GetStaticObjID(eHILmpStandByVoltage);
		const DWORD l_uiActCurrLLimit = l_pHIIntf->GetStaticObjID(eHILmpActCurrLLimit);

		// make digits
		const DWORD l_uiDigitsNomVoltageLLimit = (DWORD)(1233.5 * (l_uiNomVoltageLLimit/1000.0) + (-4366)); // formula see lamp control docs
		const DWORD l_uiDigitsStandByVoltage = (DWORD)(1233.5 * (l_uiStandByVoltage/1000.0) + (-4366));	// formula see lamp control docs
		const DWORD l_uiDigitsActCurrLLimit = (DWORD)((((l_uiActCurrLLimit/1000.0) * 4096 * 10 * 0.1 / 2.5) + 0) * 0.9);	// formula see lamp control docs  // 90% of nom. value
		const DWORD l_dwTimeOut = 1000;
		const DWORD l_dwDeltaTimeOut = 100;

		// switch on primary lamp
		CPITicksAtStart::m_eLamp = ePrimaryLamp;
		l_pHIIntf->SetDWord(l_dwIDLampSelection, 0); // 0 = primary lamp
		SetLmpNomReg(l_uiDigitsNomVoltageLLimit);	 // set nom. voltage
		l_pHIIntf->SetDWord(l_dwIDLampOnOff, 1);
		Sleep(l_dwTimeOut);

		// get act lamp current to check. is pri lamp switched on?
		UINT l_uiRegNomValue = l_pHIIntf->GetDWord(l_dwIDActCurrent);

		if ( l_uiRegNomValue < l_uiDigitsActCurrLLimit ) 
		{
			// Primary lamp not switched on. Switch on seondary lamp.
			CPITicksAtStart::m_eLamp = eSecondaryLamp;
			l_pHIIntf->SetDWord(l_dwIDLampSelection, 1);	// 1 = primary lamp
			SetLmpNomReg(l_uiDigitsNomVoltageLLimit);					// set nom. voltage
			l_pHIIntf->SetDWord(l_dwIDLampOnOff, 1);
			Sleep(l_dwTimeOut);
		}

		// increase voltage
		UINT l_uiLmpRegister = l_uiDigitsNomVoltageLLimit;
		while (l_uiLmpRegister < l_uiDigitsStandByVoltage)
		{
			l_uiLmpRegister += 200;			// 200 digits
			SetLmpNomReg(l_uiLmpRegister);	// set nom. voltage
			Sleep(l_dwDeltaTimeOut);
		}
		// set standby voltage
		SetLmpNomReg(l_uiDigitsStandByVoltage);
	}

	// start laser
	l_bHardwareExist = CPIComponentsState::GetInstance()->GetComponentState(_T("IO"));
	if (l_bHardwareExist)
	{
		DWORD l_dwIDIOLaser = l_pHIIntf->GetStaticObjID(eHIIDIOLaser);
		l_pHIIntf->SetDWord(l_dwIDIOLaser, 1);
	}

	// set ticks at start up tickcounter valid for Lamp 1 and 2 and the laser.
	CPITicksAtStart::m_dwTicksAtStartUp = GetTickCount();
  //## end CSYStateConstitution::WarmUp%1083700294.body
}

void CSYStateConstitution::SetLmpNomReg (const DWORD p_uiRegValue)
{
  //## begin CSYStateConstitution::SetLmpNomReg%1083700295.body preserve=yes
	DWORD l_dwIDNomVoltage = CHIInterface::GetInstance()->GetStaticObjID(eHIIDLmpNomVoltage);
	CHIInterface::GetInstance()->SetDWord(l_dwIDNomVoltage, p_uiRegValue);
  //## end CSYStateConstitution::SetLmpNomReg%1083700295.body
}

void CSYStateConstitution::GetOsVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYStateConstitution::GetOsVersion%1108540796.body preserve=yes
    CCOSyncObjectCString* l_pSyncObj = dynamic_cast<CCOSyncObjectCString*>(p_pClientSyncObj);
    ASSERT(l_pSyncObj != NULL);

    l_pSyncObj->SetValue(GetpContext(p_pContext)->GetOsVersion());
  //## end CSYStateConstitution::GetOsVersion%1108540796.body
}

void CSYStateConstitution::GetFpgaVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYStateConstitution::GetFpgaVersion%1108540797.body preserve=yes
    CCOSyncObjectCString* l_pSyncObj = dynamic_cast<CCOSyncObjectCString*>(p_pClientSyncObj);
    ASSERT(l_pSyncObj != NULL);

    l_pSyncObj->SetValue(GetpContext(p_pContext)->GetFpgaVersion());
  //## end CSYStateConstitution::GetFpgaVersion%1108540797.body
}

// Additional Declarations
  //## begin CSYStateConstitution%3EDC5B9C02DC.declarations preserve=yes
  //## end CSYStateConstitution%3EDC5B9C02DC.declarations

// Class CSYStateConstitutionStartingUp 

//## begin CSYStateConstitutionStartingUp::pInstance%4097F4090110.role preserve=no  public: static CSYStateConstitutionStartingUp {1..1 -> 1..1RFHN}
CSYStateConstitutionStartingUp *CSYStateConstitutionStartingUp::m_pInstance = NULL;
//## end CSYStateConstitutionStartingUp::pInstance%4097F4090110.role


CSYStateConstitutionStartingUp::CSYStateConstitutionStartingUp()
  //## begin CSYStateConstitutionStartingUp::CSYStateConstitutionStartingUp%.hasinit preserve=no
  //## end CSYStateConstitutionStartingUp::CSYStateConstitutionStartingUp%.hasinit
  //## begin CSYStateConstitutionStartingUp::CSYStateConstitutionStartingUp%.initialization preserve=yes
  //## end CSYStateConstitutionStartingUp::CSYStateConstitutionStartingUp%.initialization
{
  //## begin CSYStateConstitutionStartingUp::CSYStateConstitutionStartingUp%.body preserve=yes
  //## end CSYStateConstitutionStartingUp::CSYStateConstitutionStartingUp%.body
}


CSYStateConstitutionStartingUp::~CSYStateConstitutionStartingUp()
{
  //## begin CSYStateConstitutionStartingUp::~CSYStateConstitutionStartingUp%.body preserve=yes
  //## end CSYStateConstitutionStartingUp::~CSYStateConstitutionStartingUp%.body
}



//## Other Operations (implementation)
void CSYStateConstitutionStartingUp::Create ()
{
  //## begin CSYStateConstitutionStartingUp::Create%1083700290.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSYStateConstitutionStartingUp();
  //## end CSYStateConstitutionStartingUp::Create%1083700290.body
}

void CSYStateConstitutionStartingUp::Delete ()
{
  //## begin CSYStateConstitutionStartingUp::Delete%1083700291.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSYStateConstitutionStartingUp::Delete%1083700291.body
}

CSYStateConstitutionStartingUp* CSYStateConstitutionStartingUp::GetInstance ()
{
  //## begin CSYStateConstitutionStartingUp::GetInstance%1083700292.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSYStateConstitutionStartingUp::GetInstance%1083700292.body
}

void CSYStateConstitutionStartingUp::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionStartingUp::Do%1083700293.body preserve=yes
	// load and register pre-loaded assemblies
    CSYModuleHandling::LoadAllDLLs(true);
    CSYModuleHandling::RegisterAllInterfaces(true);

    bool l_bDHCPEnabled;
    CString l_sAddress; CString l_sSubnetMask;
    if (ReadIPConfig(l_bDHCPEnabled, l_sAddress, l_sSubnetMask))
    {
		// activate system password

        // activate IP config after a CE image update
        char l_sAddr[256];
		memset(l_sAddr, 0, sizeof(l_sAddr));
        ::WideCharToMultiByte(CP_ACP, 0, (LPCTSTR)l_sAddress, l_sAddress.GetLength(), l_sAddr, sizeof(l_sAddr), NULL, NULL);
        char l_sMask[256];
		memset(l_sMask, 0, sizeof(l_sAddr));
        ::WideCharToMultiByte(CP_ACP, 0, (LPCTSTR)l_sSubnetMask, l_sSubnetMask.GetLength(), l_sMask, sizeof(l_sMask), NULL, NULL);

        DWORD l_dwAddress = inet_addr(l_sAddr);
        DWORD l_dwMask = inet_addr(l_sMask);
        CPIInterfaceConfig* l_pCfg = new CPIInterfaceConfig(eEthernet, l_dwAddress, l_dwMask, 0, l_bDHCPEnabled);
        CSYInterfaceSettings::SetIPAddress(l_pCfg);
        l_pCfg->ReleaseRef();

		// delete IP file and reboot again
        DeleteFile(sWinCEImageLocation + _T("\\IPconfig.txt"));

		// and reboot again
        CSYStateShuttingDown::GetInstance()->SetbRebootSystem(true);
        p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());
    }
    else
    {
	    // startup lamp
	    WarmUp();

	    // activate PC communication
	    CPISystem::Start();

	    // wait for connection
	    p_pContext->ChangeState(CSYStateConstitutionStandByWarmingUp::GetInstance());
    }
  //## end CSYStateConstitutionStartingUp::Do%1083700293.body
}

bool CSYStateConstitutionStartingUp::ReadIPConfig (bool& p_bDHCPEnabled, CString& p_sAddress, CString& p_sSubnetMask)
{
  //## begin CSYStateConstitutionStartingUp::ReadIPConfig%1199351101.body preserve=yes
    CString l_sFileName = sWinCEImageLocation + _T("\\IPconfig.txt");

    try
    {
        CFile l_File;
        if (l_File.Open((LPCTSTR)l_sFileName, CFile::modeRead))
        {
            BYTE* l_pBuffer = new BYTE[(int)l_File.GetLength()];
            l_File.Read(l_pBuffer, (int)l_File.GetLength());
            l_File.Close();

            CString l_sLine = (WCHAR*)l_pBuffer;
            delete[] l_pBuffer;

            int l_iStartIdx = l_sLine.Find(_T("DHCPenabled="));
            if (l_iStartIdx == -1)
                return false;
            int l_iEndIdx = l_sLine.Find(_T(';'), l_iStartIdx + 12);
            if (l_iEndIdx == -1)
                return false;            
            CString l_sDHCP = l_sLine.Mid(l_iStartIdx+12, l_iEndIdx - l_iStartIdx - 12);
            p_bDHCPEnabled = _wtoi((LPCTSTR)l_sDHCP) != 0;

            l_iStartIdx = l_sLine.Find(_T("IPAddress="), l_iEndIdx);
            if (l_iStartIdx == -1)
                return false;
            l_iEndIdx = l_sLine.Find(_T(';'), l_iStartIdx + 10);
            if (l_iEndIdx == -1)
                return false;
            p_sAddress = l_sLine.Mid(l_iStartIdx+10, l_iEndIdx - l_iStartIdx - 10);

            l_iStartIdx = l_sLine.Find(_T("SubnetMask="), l_iEndIdx);
            if (l_iStartIdx == -1)
                return false;
            l_iEndIdx = l_sLine.Find(_T(';'), l_iStartIdx + 11);
            if (l_iEndIdx == -1)
                return false;
            p_sSubnetMask = l_sLine.Mid(l_iStartIdx+11, l_iEndIdx - l_iStartIdx - 11);

            return true;
        }

        return false;
    }
    catch(CFileException *l_pException)
    {
        l_pException->Delete();
        return false;
    }
  //## end CSYStateConstitutionStartingUp::ReadIPConfig%1199351101.body
}

// Additional Declarations
  //## begin CSYStateConstitutionStartingUp%4097F361038F.declarations preserve=yes
  //## end CSYStateConstitutionStartingUp%4097F361038F.declarations

// Class CSYStateConstitutionStandBy 

//## begin CSYStateConstitutionStandBy::pInstance%409806C703A4.role preserve=no  public: static CSYStateConstitutionStandBy {1..1 -> 1..1RFHN}
CSYStateConstitutionStandBy *CSYStateConstitutionStandBy::m_pInstance = NULL;
//## end CSYStateConstitutionStandBy::pInstance%409806C703A4.role


CSYStateConstitutionStandBy::CSYStateConstitutionStandBy()
  //## begin CSYStateConstitutionStandBy::CSYStateConstitutionStandBy%.hasinit preserve=no
  //## end CSYStateConstitutionStandBy::CSYStateConstitutionStandBy%.hasinit
  //## begin CSYStateConstitutionStandBy::CSYStateConstitutionStandBy%.initialization preserve=yes
  //## end CSYStateConstitutionStandBy::CSYStateConstitutionStandBy%.initialization
{
  //## begin CSYStateConstitutionStandBy::CSYStateConstitutionStandBy%.body preserve=yes
  //## end CSYStateConstitutionStandBy::CSYStateConstitutionStandBy%.body
}


CSYStateConstitutionStandBy::~CSYStateConstitutionStandBy()
{
  //## begin CSYStateConstitutionStandBy::~CSYStateConstitutionStandBy%.body preserve=yes
  //## end CSYStateConstitutionStandBy::~CSYStateConstitutionStandBy%.body
}



//## Other Operations (implementation)
void CSYStateConstitutionStandBy::Create ()
{
  //## begin CSYStateConstitutionStandBy::Create%1083700296.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CSYStateConstitutionStandBy();
  //## end CSYStateConstitutionStandBy::Create%1083700296.body
}

void CSYStateConstitutionStandBy::Delete ()
{
  //## begin CSYStateConstitutionStandBy::Delete%1083700297.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CSYStateConstitutionStandBy::Delete%1083700297.body
}

CSYStateConstitutionStandBy* CSYStateConstitutionStandBy::GetInstance ()
{
  //## begin CSYStateConstitutionStandBy::GetInstance%1083700298.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CSYStateConstitutionStandBy::GetInstance%1083700298.body
}

void CSYStateConstitutionStandBy::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionStandBy::ConnectionEstablished%1083700300.body preserve=yes
    // warm up
	WarmUp();

    // change to connected state
    p_pContext->ChangeState(CSYStateConstitutionConnected::GetInstance());
  //## end CSYStateConstitutionStandBy::ConnectionEstablished%1083700300.body
}

void CSYStateConstitutionStandBy::ResetDevice (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionStandBy::ResetDevice%1083700301.body preserve=yes
	CSYStateShuttingDown::GetInstance()->SetbRebootSystem(true);
  	p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());
  //## end CSYStateConstitutionStandBy::ResetDevice%1083700301.body
}

void CSYStateConstitutionStandBy::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionStandBy::Enter%1096648862.body preserve=yes
    GetpContext(p_pContext)->ResetClient();
  //## end CSYStateConstitutionStandBy::Enter%1096648862.body
}

void CSYStateConstitutionStandBy::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionStandBy::Do%1083700299.body preserve=yes
    // turn off lamp and laser
	CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDLmpSelection), 0);
	CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDLmpOnOff), 0);
	CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDLmpSelection), 1);
	CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDLmpOnOff), 0);
	CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDIOLaser), 0);

	// CPIObjectFactory::GetInstance()->Reset(false);
  //## end CSYStateConstitutionStandBy::Do%1083700299.body
}

// Additional Declarations
  //## begin CSYStateConstitutionStandBy%40980690021E.declarations preserve=yes
  //## end CSYStateConstitutionStandBy%40980690021E.declarations

// Class CSYStateConstitutionConsiderInterfaceReset 

//## begin CSYStateConstitutionConsiderInterfaceReset::pInstance%4110FD82002C.role preserve=no  public: static CSYStateConstitutionConsiderInterfaceReset {1..1 -> 1..1RFHN}
CSYStateConstitutionConsiderInterfaceReset *CSYStateConstitutionConsiderInterfaceReset::m_pInstance = NULL;
//## end CSYStateConstitutionConsiderInterfaceReset::pInstance%4110FD82002C.role


CSYStateConstitutionConsiderInterfaceReset::CSYStateConstitutionConsiderInterfaceReset()
  //## begin CSYStateConstitutionConsiderInterfaceReset::CSYStateConstitutionConsiderInterfaceReset%.hasinit preserve=no
  //## end CSYStateConstitutionConsiderInterfaceReset::CSYStateConstitutionConsiderInterfaceReset%.hasinit
  //## begin CSYStateConstitutionConsiderInterfaceReset::CSYStateConstitutionConsiderInterfaceReset%.initialization preserve=yes
  //## end CSYStateConstitutionConsiderInterfaceReset::CSYStateConstitutionConsiderInterfaceReset%.initialization
{
  //## begin CSYStateConstitutionConsiderInterfaceReset::CSYStateConstitutionConsiderInterfaceReset%.body preserve=yes
  //## end CSYStateConstitutionConsiderInterfaceReset::CSYStateConstitutionConsiderInterfaceReset%.body
}


CSYStateConstitutionConsiderInterfaceReset::~CSYStateConstitutionConsiderInterfaceReset()
{
  //## begin CSYStateConstitutionConsiderInterfaceReset::~CSYStateConstitutionConsiderInterfaceReset%.body preserve=yes
  //## end CSYStateConstitutionConsiderInterfaceReset::~CSYStateConstitutionConsiderInterfaceReset%.body
}



//## Other Operations (implementation)
void CSYStateConstitutionConsiderInterfaceReset::Create ()
{
  //## begin CSYStateConstitutionConsiderInterfaceReset::Create%1091609205.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CSYStateConstitutionConsiderInterfaceReset();
  //## end CSYStateConstitutionConsiderInterfaceReset::Create%1091609205.body
}

void CSYStateConstitutionConsiderInterfaceReset::Delete ()
{
  //## begin CSYStateConstitutionConsiderInterfaceReset::Delete%1091609206.body preserve=yes
    delete m_pInstance;
    m_pInstance = NULL;
  //## end CSYStateConstitutionConsiderInterfaceReset::Delete%1091609206.body
}

CSYStateConstitutionConsiderInterfaceReset* CSYStateConstitutionConsiderInterfaceReset::GetInstance ()
{
  //## begin CSYStateConstitutionConsiderInterfaceReset::GetInstance%1091609207.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSYStateConstitutionConsiderInterfaceReset::GetInstance%1091609207.body
}

void CSYStateConstitutionConsiderInterfaceReset::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionConsiderInterfaceReset::Do%1091609208.body preserve=yes
	IHIInterface *l_pHIIntf = CHIInterface::GetInstance();
	ASSERT(l_pHIIntf != NULL);

    // only check buttons if the MC is docked
    bool l_bMCDocked = l_pHIIntf->GetDWord(l_pHIIntf->GetStaticObjID(eHIIDDockingState)) != 0;
    if (!l_bMCDocked)
    {
        p_pContext->ChangeState(CSYStateConstitutionStartingUp::GetInstance());
        return;
    }

    for (int l_iCnt=0; l_iCnt<5; l_iCnt++)
    {
        bool l_bStartButtonPressed = l_pHIIntf->GetDWord(l_pHIIntf->GetStaticObjID(eHIIDButtonStart)) != 0;
        bool l_bStopButtonPressed  = l_pHIIntf->GetDWord(l_pHIIntf->GetStaticObjID(eHIIDButtonStop)) != 0;

        if (!l_bStartButtonPressed || !l_bStopButtonPressed)
        {
            p_pContext->ChangeState(CSYStateConstitutionStartingUp::GetInstance());
            return;
        }

        ::Sleep(1000);
    }

    // button's have been pressed for more than five seconds -> reset interface
    p_pContext->ChangeState(CSYStateConstitutionResetInterface::GetInstance());
  //## end CSYStateConstitutionConsiderInterfaceReset::Do%1091609208.body
}

// Additional Declarations
  //## begin CSYStateConstitutionConsiderInterfaceReset%4110FD380329.declarations preserve=yes
  //## end CSYStateConstitutionConsiderInterfaceReset%4110FD380329.declarations

// Class CSYStateConstitutionResetInterface 

//## begin CSYStateConstitutionResetInterface::pInstance%4110FE1F0201.role preserve=no  public: static CSYStateConstitutionResetInterface {1..1 -> 1..1RFHN}
CSYStateConstitutionResetInterface *CSYStateConstitutionResetInterface::m_pInstance = NULL;
//## end CSYStateConstitutionResetInterface::pInstance%4110FE1F0201.role


CSYStateConstitutionResetInterface::CSYStateConstitutionResetInterface()
  //## begin CSYStateConstitutionResetInterface::CSYStateConstitutionResetInterface%.hasinit preserve=no
  //## end CSYStateConstitutionResetInterface::CSYStateConstitutionResetInterface%.hasinit
  //## begin CSYStateConstitutionResetInterface::CSYStateConstitutionResetInterface%.initialization preserve=yes
  //## end CSYStateConstitutionResetInterface::CSYStateConstitutionResetInterface%.initialization
{
  //## begin CSYStateConstitutionResetInterface::CSYStateConstitutionResetInterface%.body preserve=yes
  //## end CSYStateConstitutionResetInterface::CSYStateConstitutionResetInterface%.body
}


CSYStateConstitutionResetInterface::~CSYStateConstitutionResetInterface()
{
  //## begin CSYStateConstitutionResetInterface::~CSYStateConstitutionResetInterface%.body preserve=yes
  //## end CSYStateConstitutionResetInterface::~CSYStateConstitutionResetInterface%.body
}



//## Other Operations (implementation)
void CSYStateConstitutionResetInterface::Create ()
{
  //## begin CSYStateConstitutionResetInterface::Create%1091609209.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CSYStateConstitutionResetInterface();
  //## end CSYStateConstitutionResetInterface::Create%1091609209.body
}

void CSYStateConstitutionResetInterface::Delete ()
{
  //## begin CSYStateConstitutionResetInterface::Delete%1091609210.body preserve=yes
    delete m_pInstance;
    m_pInstance = NULL;
  //## end CSYStateConstitutionResetInterface::Delete%1091609210.body
}

CSYStateConstitutionResetInterface* CSYStateConstitutionResetInterface::GetInstance ()
{
  //## begin CSYStateConstitutionResetInterface::GetInstance%1091609211.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSYStateConstitutionResetInterface::GetInstance%1091609211.body
}

void CSYStateConstitutionResetInterface::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionResetInterface::Do%1091609212.body preserve=yes
                                                                           // 192.168.1.1 255.255.255.0
    CPIInterfaceConfig* l_pInterfaceConfig = new CPIInterfaceConfig(eEthernet, 0x0101A8C0, 0x00FFFFFF, 0, false);
    CSYInterfaceSettings::SetIPAddress (l_pInterfaceConfig);
    l_pInterfaceConfig->ReleaseRef();

    CSYStateShuttingDown::GetInstance()->SetbRebootSystem(true);
  	p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());
  //## end CSYStateConstitutionResetInterface::Do%1091609212.body
}

// Additional Declarations
  //## begin CSYStateConstitutionResetInterface%4110FDDD0164.declarations preserve=yes
  //## end CSYStateConstitutionResetInterface%4110FDDD0164.declarations

//## begin module%3EED8B600131.epilog preserve=yes
//## end module%3EED8B600131.epilog

