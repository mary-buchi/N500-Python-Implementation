//## begin module%3EEDB50A011F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EEDB50A011F.cm

//## begin module%3EEDB50A011F.cp preserve=no
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
//## end module%3EEDB50A011F.cp

//## Module: EBSYcntd%3EEDB50A011F; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYcntd.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EEDB50A011F.additionalIncludes preserve=no
//## end module%3EEDB50A011F.additionalIncludes

//## begin module%3EEDB50A011F.includes preserve=yes
//## end module%3EEDB50A011F.includes

// EBSYrgun
#include "EBSYrgun.h"
// EBPIcpst
#include "EBPIcpst.h"
// EBPImain
#include "EBPImain.h"
// EBSYswdl
#include "EBSYswdl.h"
// EBSYmhan
#include "EBSYmhan.h"
// EBSYshdn
#include "EBSYshdn.h"
// EBSYcrea
#include "EBSYcrea.h"
// EBSYimpl
#include "EBSYimpl.h"
// EBSYpstb
#include "EBSYpstb.h"
// EBSYcntd
#include "EBSYcntd.h"
// EBSYifcf
#include "EBSYifcf.h"
// EBSYrdsw
#include "EBSYrdsw.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3EEDB50A011F.declarations preserve=no
//## end module%3EEDB50A011F.declarations

//## begin module%3EEDB50A011F.additionalDeclarations preserve=yes
//## end module%3EEDB50A011F.additionalDeclarations


// Class CSYStateConstitutionConnected 

//## begin CSYStateConstitutionConnected::pInstance%3EDC5B9C033C.role preserve=no  public: static CSYStateConstitutionConnected {1..1 -> RFHN}
CSYStateConstitutionConnected *CSYStateConstitutionConnected::m_pInstance = NULL;
//## end CSYStateConstitutionConnected::pInstance%3EDC5B9C033C.role


CSYStateConstitutionConnected::CSYStateConstitutionConnected()
  //## begin CSYStateConstitutionConnected::CSYStateConstitutionConnected%.hasinit preserve=no
  //## end CSYStateConstitutionConnected::CSYStateConstitutionConnected%.hasinit
  //## begin CSYStateConstitutionConnected::CSYStateConstitutionConnected%.initialization preserve=yes
  //## end CSYStateConstitutionConnected::CSYStateConstitutionConnected%.initialization
{
  //## begin CSYStateConstitutionConnected::CSYStateConstitutionConnected%.body preserve=yes
  //## end CSYStateConstitutionConnected::CSYStateConstitutionConnected%.body
}


CSYStateConstitutionConnected::~CSYStateConstitutionConnected()
{
  //## begin CSYStateConstitutionConnected::~CSYStateConstitutionConnected%.body preserve=yes
  //## end CSYStateConstitutionConnected::~CSYStateConstitutionConnected%.body
}



//## Other Operations (implementation)
void CSYStateConstitutionConnected::Create ()
{
  //## begin CSYStateConstitutionConnected::Create%1044959885.body preserve=yes

	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSYStateConstitutionConnected();

  //## end CSYStateConstitutionConnected::Create%1044959885.body
}

void CSYStateConstitutionConnected::Delete ()
{
  //## begin CSYStateConstitutionConnected::Delete%1044959887.body preserve=yes

    if (m_pInstance)
    {
        delete m_pInstance;
    }

    m_pInstance = NULL;

  //## end CSYStateConstitutionConnected::Delete%1044959887.body
}

CSYStateConstitutionConnected* CSYStateConstitutionConnected::GetInstance ()
{
  //## begin CSYStateConstitutionConnected::GetInstance%1044959886.body preserve=yes

	ASSERT(m_pInstance != NULL);
    return m_pInstance;

  //## end CSYStateConstitutionConnected::GetInstance%1044959886.body
}

EPIDeviceState CSYStateConstitutionConnected::GetDeviceState ()
{
  //## begin CSYStateConstitutionConnected::GetDeviceState%1056436751.body preserve=yes
    return eReadyForDownload;
  //## end CSYStateConstitutionConnected::GetDeviceState%1056436751.body
}

void CSYStateConstitutionConnected::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionConnected::Do%1057322343.body preserve=yes
    // handle on board leds
    CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHILedRed), 0);
    CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHILedGreen), 1);

    // Delete all files from last backup
    CSYModuleHandling::CleanupBackupDLLs();
  //## end CSYStateConstitutionConnected::Do%1057322343.body
}

void CSYStateConstitutionConnected::SetInterfaceConfig (ICOStateMachineContext* p_pContext, CPIInterfaceConfig* p_pInterfaceConfig, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYStateConstitutionConnected::SetInterfaceConfig%1055753495.body preserve=yes

    GetpContext(p_pContext)->SetpSetInterfaceCfgSyncObj(p_pClientSyncObj);
	CSYStateConstitutionConfigInterface::GetInstance()->SetpInterfaceConfig(p_pInterfaceConfig);
	p_pContext->ChangeState(CSYStateConstitutionConfigInterface::GetInstance());

  //## end CSYStateConstitutionConnected::SetInterfaceConfig%1055753495.body
}

void CSYStateConstitutionConnected::ReadSoftwareVersions (ICOStateMachineContext* p_pContext, CPISyncObjListSWCompVersion* p_pClientSyncObj)
{
  //## begin CSYStateConstitutionConnected::ReadSoftwareVersions%1056358086.body preserve=yes

	CSYStateConstitutionReadSoftwareVersions::GetInstance()->SetpClientSyncObj(p_pClientSyncObj);
    p_pContext->ChangeState(CSYStateConstitutionReadSoftwareVersions::GetInstance());

  //## end CSYStateConstitutionConnected::ReadSoftwareVersions%1056358086.body
}

void CSYStateConstitutionConnected::DownloadSoftwareComponents (ICOStateMachineContext* p_pContext, CPIPersistentSoftwareComponentList* p_pComponentList, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYStateConstitutionConnected::DownloadSoftwareComponents%1055753506.body preserve=yes

    // Set parameter for later use in new state
    CSYStateConstitutionDownloadSoftwareComponents::GetInstance()->SetpClientSyncObj(p_pClientSyncObj);
    CSYStateConstitutionDownloadSoftwareComponents::GetInstance()->SetpSoftwareComponentList(p_pComponentList);
	p_pContext->ChangeState(CSYStateConstitutionDownloadSoftwareComponents::GetInstance());

  //## end CSYStateConstitutionConnected::DownloadSoftwareComponents%1055753506.body
}

void CSYStateConstitutionConnected::StartDevice (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionConnected::StartDevice%1055753496.body preserve=yes

	p_pContext->ChangeState(CSYStateConstitutionRegisteringUnits::GetInstance());

  //## end CSYStateConstitutionConnected::StartDevice%1055753496.body
}

void CSYStateConstitutionConnected::ResetDevice (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionConnected::ResetDevice%1056695969.body preserve=yes
    CSYStateShuttingDown::GetInstance()->SetbRebootSystem(true);
  	p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());
  //## end CSYStateConstitutionConnected::ResetDevice%1056695969.body
}

void CSYStateConstitutionConnected::SetStandbyTimeout (ICOStateMachineContext* p_pContext, unsigned int p_uiTimeout)
{
  //## begin CSYStateConstitutionConnected::SetStandbyTimeout%1056695978.body preserve=yes
    GetpContext(p_pContext)->SetuiWarmupTimeout(p_uiTimeout);
  //## end CSYStateConstitutionConnected::SetStandbyTimeout%1056695978.body
}

void CSYStateConstitutionConnected::SetComponentState (ICOStateMachineContext* p_pContext, const CString& p_sComponentId, const bool p_bActive)
{
  //## begin CSYStateConstitutionConnected::SetComponentState%1061359183.body preserve=yes

    CPIComponentsState::GetInstance()->SetComponentState(p_sComponentId, p_bActive);

  //## end CSYStateConstitutionConnected::SetComponentState%1061359183.body
}

void CSYStateConstitutionConnected::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionConnected::ConnectionLost%1083744904.body preserve=yes
    p_pContext->ChangeState(CSYStateConstitutionStandByWarmingUp::GetInstance());
  //## end CSYStateConstitutionConnected::ConnectionLost%1083744904.body
}

void CSYStateConstitutionConnected::RegisterClient (ICOStateMachineContext* p_pContext, const CString& p_sClient)
{
  //## begin CSYStateConstitutionConnected::RegisterClient%1096656410.body preserve=yes
    GetpContext(p_pContext)->RegisterClient(p_sClient);
  //## end CSYStateConstitutionConnected::RegisterClient%1096656410.body
}

void CSYStateConstitutionConnected::StartDownload (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionConnected::StartDownload%1200165526.body preserve=yes
	p_pContext->ChangeState(CSYStateConstitutionDownloadStarted::GetInstance());
  //## end CSYStateConstitutionConnected::StartDownload%1200165526.body
}

// Additional Declarations
  //## begin CSYStateConstitutionConnected%3EDC5B9C02A8.declarations preserve=yes

  //## end CSYStateConstitutionConnected%3EDC5B9C02A8.declarations
//## begin module%3EEDB50A011F.epilog preserve=yes
//## end module%3EEDB50A011F.epilog
