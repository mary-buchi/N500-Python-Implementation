//## begin module%3EDC5B3C01EF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01EF.cm

//## begin module%3EDC5B3C01EF.cp preserve=no
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
//## end module%3EDC5B3C01EF.cp

//## Module: EBSYstat%3EDC5B3C01EF; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYstat.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EDC5B3C01EF.additionalIncludes preserve=no
//## end module%3EDC5B3C01EF.additionalIncludes

//## begin module%3EDC5B3C01EF.includes preserve=yes
//## end module%3EDC5B3C01EF.includes

// EBPIfact
#include "EBPIfact.h"
// EBSYshdn
#include "EBSYshdn.h"
// EBSYstat
#include "EBSYstat.h"
// EBSYimpl
#include "EBSYimpl.h"


//## begin module%3EDC5B3C01EF.declarations preserve=no
//## end module%3EDC5B3C01EF.declarations

//## begin module%3EDC5B3C01EF.additionalDeclarations preserve=yes
//## end module%3EDC5B3C01EF.additionalDeclarations


// Class CSYState 

CSYState::CSYState()
  //## begin CSYState::CSYState%.hasinit preserve=no
  //## end CSYState::CSYState%.hasinit
  //## begin CSYState::CSYState%.initialization preserve=yes
  //## end CSYState::CSYState%.initialization
{
  //## begin CSYState::CSYState%.body preserve=yes
  //## end CSYState::CSYState%.body
}


CSYState::~CSYState()
{
  //## begin CSYState::~CSYState%.body preserve=yes
  //## end CSYState::~CSYState%.body
}



//## Other Operations (implementation)
void CSYState::StartDevice (ICOStateMachineContext* p_pContext)
{
  //## begin CSYState::StartDevice%1055753497.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::StartDevice%1055753497.body
}

void CSYState::ResetDevice (ICOStateMachineContext* p_pContext)
{
  //## begin CSYState::ResetDevice%1055753498.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::ResetDevice%1055753498.body
}

void CSYState::SetStandbyTimeout (ICOStateMachineContext* p_pContext, unsigned int p_uiTimeout)
{
  //## begin CSYState::SetStandbyTimeout%1056695977.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::SetStandbyTimeout%1056695977.body
}

void CSYState::SetInterfaceConfig (ICOStateMachineContext* p_pContext, CPIInterfaceConfig* p_pInterfaceConfig, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYState::SetInterfaceConfig%1056523873.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::SetInterfaceConfig%1056523873.body
}

void CSYState::ReadSoftwareVersions (ICOStateMachineContext* p_pContext, CPISyncObjListSWCompVersion* p_pClientSyncObj)
{
  //## begin CSYState::ReadSoftwareVersions%1055753500.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::ReadSoftwareVersions%1055753500.body
}

void CSYState::DownloadSoftwareComponents (ICOStateMachineContext* p_pContext, CPIPersistentSoftwareComponentList* p_pComponentList, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYState::DownloadSoftwareComponents%1055753502.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::DownloadSoftwareComponents%1055753502.body
}

void CSYState::DownloadSoftwareComponent (ICOStateMachineContext* p_pContext, CPIPersistentSoftwareComponent* p_pComponent)
{
  //## begin CSYState::DownloadSoftwareComponent%1199783729.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::DownloadSoftwareComponent%1199783729.body
}

void CSYState::SetComponentState (ICOStateMachineContext* p_pContext, const CString& p_sComponentId, const bool p_bActive)
{
  //## begin CSYState::SetComponentState%1061359182.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::SetComponentState%1061359182.body
}

void CSYState::GetObjectList (ICOStateMachineContext* p_pContext, CPISyncObjectStringArray* p_pSyncObj)
{
  //## begin CSYState::GetObjectList%1063715461.body preserve=yes
    CStringArray* l_StrArray = new CStringArray();
    CPIObjectFactory::GetInstance()->GetObjectStates(*l_StrArray);

    p_pSyncObj->SetValue(l_StrArray);
  //## end CSYState::GetObjectList%1063715461.body
}

void CSYState::SetSystemTime (ICOStateMachineContext* p_pContext, const SYSTEMTIME& p_SystemTime)
{
  //## begin CSYState::SetSystemTime%1064429418.body preserve=yes
	::SetSystemTime(&p_SystemTime);
  //## end CSYState::SetSystemTime%1064429418.body
}

void CSYState::RegisterClient (ICOStateMachineContext* p_pContext, const CString& p_sClient)
{
  //## begin CSYState::RegisterClient%1096656409.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::RegisterClient%1096656409.body
}

void CSYState::GetVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYState::GetVersion%1096656417.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::GetVersion%1096656417.body
}

void CSYState::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CSYState::CleanupInitialize%1077175169.body preserve=yes
    CSYStateShuttingDown::GetInstance()->SetbRebootSystem(true);
	p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());
  //## end CSYState::CleanupInitialize%1077175169.body
}

CSYSystemImplementation* CSYState::GetpContext (ICOStateMachineContext* p_pContext)
{
  //## begin CSYState::GetpContext%1083737621.body preserve=yes
    CSYSystemImplementation* l_pContext = dynamic_cast<CSYSystemImplementation*>(p_pContext);
    ASSERT(l_pContext != NULL);

    return l_pContext;
  //## end CSYState::GetpContext%1083737621.body
}

void CSYState::GetOsVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYState::GetOsVersion%1108540798.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::GetOsVersion%1108540798.body
}

void CSYState::GetFpgaVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYState::GetFpgaVersion%1108540799.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::GetFpgaVersion%1108540799.body
}

void CSYState::StartDownload (ICOStateMachineContext* p_pContext)
{
  //## begin CSYState::StartDownload%1199783740.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::StartDownload%1199783740.body
}

void CSYState::EndDownload (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYState::EndDownload%1199783741.body preserve=yes
    XCO_INVALID_STATE(SY_ID);
  //## end CSYState::EndDownload%1199783741.body
}

// Additional Declarations
  //## begin CSYState%3EDC5B9C00C2.declarations preserve=yes
  //## end CSYState%3EDC5B9C00C2.declarations

//## begin module%3EDC5B3C01EF.epilog preserve=yes
//## end module%3EDC5B3C01EF.epilog
