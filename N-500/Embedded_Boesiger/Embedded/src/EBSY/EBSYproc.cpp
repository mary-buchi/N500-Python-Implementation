//## begin module%3EDC5B3C0203.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C0203.cm

//## begin module%3EDC5B3C0203.cp preserve=no
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
//## end module%3EDC5B3C0203.cp

//## Module: EBSYproc%3EDC5B3C0203; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYproc.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EDC5B3C0203.additionalIncludes preserve=no
//## end module%3EDC5B3C0203.additionalIncludes

//## begin module%3EDC5B3C0203.includes preserve=yes
//## end module%3EDC5B3C0203.includes

// EBSYcrea
#include "EBSYcrea.h"
// EBSYimpl
#include "EBSYimpl.h"
// EBSYproc
#include "EBSYproc.h"
// EBSYpstb
#include "EBSYpstb.h"
// EBSYshdn
#include "EBSYshdn.h"
//## begin module%3EDC5B3C0203.declarations preserve=no
//## end module%3EDC5B3C0203.declarations

//## begin module%3EDC5B3C0203.additionalDeclarations preserve=yes
#include "..\EBET\EBETflog.h"
//## end module%3EDC5B3C0203.additionalDeclarations


// Class CSYStateProcess 

CSYStateProcess::CSYStateProcess()
  //## begin CSYStateProcess::CSYStateProcess%.hasinit preserve=no
  //## end CSYStateProcess::CSYStateProcess%.hasinit
  //## begin CSYStateProcess::CSYStateProcess%.initialization preserve=yes
  //## end CSYStateProcess::CSYStateProcess%.initialization
{
  //## begin CSYStateProcess::CSYStateProcess%.body preserve=yes
  //## end CSYStateProcess::CSYStateProcess%.body
}


CSYStateProcess::~CSYStateProcess()
{
  //## begin CSYStateProcess::~CSYStateProcess%.body preserve=yes
  //## end CSYStateProcess::~CSYStateProcess%.body
}


//## Other Operations (implementation)
EPIDeviceState CSYStateProcess::GetDeviceState ()
{
  //## begin CSYStateProcess::GetDeviceState%1056436740.body preserve=yes
    return eRunning;
  //## end CSYStateProcess::GetDeviceState%1056436740.body
}

void CSYStateProcess::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcess::ConnectionLost%1055753509.body preserve=yes
#ifdef DEBUG
	CETFileLogger::GetInstance()->AddMessage(_T("CSYStateProcess::ConnectionLost"));
#endif
	p_pContext->ChangeState(CSYStateProcessStandByDisconnecting::GetInstance());

  //## end CSYStateProcess::ConnectionLost%1055753509.body
}

void CSYStateProcess::ResetDevice (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcess::ResetDevice%1056027090.body preserve=yes
    CSYStateShuttingDown::GetInstance()->SetbRebootSystem(true);
  	p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());
  //## end CSYStateProcess::ResetDevice%1056027090.body
}

void CSYStateProcess::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcess::Startup%1064318156.body preserve=yes
  //## end CSYStateProcess::Startup%1064318156.body
}

void CSYStateProcess::StartDevice (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcess::StartDevice%1064318157.body preserve=yes
  //## end CSYStateProcess::StartDevice%1064318157.body
}

void CSYStateProcess::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcess::Shutdown%1083744905.body preserve=yes
	p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());
  //## end CSYStateProcess::Shutdown%1083744905.body
}

void CSYStateProcess::RegisterClient (ICOStateMachineContext* p_pContext, const CString& p_sClient)
{
  //## begin CSYStateProcess::RegisterClient%1096656411.body preserve=yes
    GetpContext(p_pContext)->RegisterClient(p_sClient);
  //## end CSYStateProcess::RegisterClient%1096656411.body
}

void CSYStateProcess::GetVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYStateProcess::GetVersion%1096656420.body preserve=yes
    CCOSyncObjectCString* l_pSyncObj = dynamic_cast<CCOSyncObjectCString*>(p_pClientSyncObj);
    ASSERT(l_pSyncObj != NULL);

    l_pSyncObj->SetValue(GetpContext(p_pContext)->GetSoftwareVersion());
  //## end CSYStateProcess::GetVersion%1096656420.body
}

void CSYStateProcess::GetOsVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYStateProcess::GetOsVersion%1108540794.body preserve=yes
    CCOSyncObjectCString* l_pSyncObj = dynamic_cast<CCOSyncObjectCString*>(p_pClientSyncObj);
    ASSERT(l_pSyncObj != NULL);

    l_pSyncObj->SetValue(GetpContext(p_pContext)->GetOsVersion());
  //## end CSYStateProcess::GetOsVersion%1108540794.body
}

void CSYStateProcess::GetFpgaVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYStateProcess::GetFpgaVersion%1108540795.body preserve=yes
    CCOSyncObjectCString* l_pSyncObj = dynamic_cast<CCOSyncObjectCString*>(p_pClientSyncObj);
    ASSERT(l_pSyncObj != NULL);

    l_pSyncObj->SetValue(GetpContext(p_pContext)->GetFpgaVersion());
  //## end CSYStateProcess::GetFpgaVersion%1108540795.body
}

// Additional Declarations
  //## begin CSYStateProcess%3EDC5B9C02EA.declarations preserve=yes
  //## end CSYStateProcess%3EDC5B9C02EA.declarations

//## begin module%3EDC5B3C0203.epilog preserve=yes
//## end module%3EDC5B3C0203.epilog
