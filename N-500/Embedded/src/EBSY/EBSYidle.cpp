//## begin module%3EED88180125.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED88180125.cm

//## begin module%3EED88180125.cp preserve=no
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
//## end module%3EED88180125.cp

//## Module: EBSYidle%3EED88180125; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYidle.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED88180125.additionalIncludes preserve=no
//## end module%3EED88180125.additionalIncludes

//## begin module%3EED88180125.includes preserve=yes
//## end module%3EED88180125.includes

// EBPIfact
#include "EBPIfact.h"
// EBSYimpl
#include "EBSYimpl.h"
// EBSYidle
#include "EBSYidle.h"
// EBSYifcf
#include "EBSYifcf.h"
// EBSYrdsw
#include "EBSYrdsw.h"
//## begin module%3EED88180125.declarations preserve=no
//## end module%3EED88180125.declarations

//## begin module%3EED88180125.additionalDeclarations preserve=yes
#include "..\EBET\EBETflog.h"
//## end module%3EED88180125.additionalDeclarations


// Class CSYStateProcessIdle 

//## begin CSYStateProcessIdle::pInstance%3EDC5B9C034C.role preserve=no  public: static CSYStateProcessIdle {1..1 -> 1..1RFHN}
CSYStateProcessIdle *CSYStateProcessIdle::m_pInstance = NULL;
//## end CSYStateProcessIdle::pInstance%3EDC5B9C034C.role


CSYStateProcessIdle::CSYStateProcessIdle()
  //## begin CSYStateProcessIdle::CSYStateProcessIdle%.hasinit preserve=no
  //## end CSYStateProcessIdle::CSYStateProcessIdle%.hasinit
  //## begin CSYStateProcessIdle::CSYStateProcessIdle%.initialization preserve=yes
  //## end CSYStateProcessIdle::CSYStateProcessIdle%.initialization
{
  //## begin CSYStateProcessIdle::CSYStateProcessIdle%.body preserve=yes
  //## end CSYStateProcessIdle::CSYStateProcessIdle%.body
}


CSYStateProcessIdle::~CSYStateProcessIdle()
{
  //## begin CSYStateProcessIdle::~CSYStateProcessIdle%.body preserve=yes
  //## end CSYStateProcessIdle::~CSYStateProcessIdle%.body
}



//## Other Operations (implementation)
void CSYStateProcessIdle::Create ()
{
  //## begin CSYStateProcessIdle::Create%1044959879.body preserve=yes

    ASSERT(m_pInstance == NULL);
    m_pInstance = new CSYStateProcessIdle();
	
  //## end CSYStateProcessIdle::Create%1044959879.body
}

void CSYStateProcessIdle::Delete ()
{
  //## begin CSYStateProcessIdle::Delete%1044959880.body preserve=yes

    if (m_pInstance)
    {
        delete m_pInstance;
    }

    m_pInstance = NULL;

  //## end CSYStateProcessIdle::Delete%1044959880.body
}

CSYStateProcessIdle* CSYStateProcessIdle::GetInstance ()
{
  //## begin CSYStateProcessIdle::GetInstance%1044959881.body preserve=yes

	ASSERT(m_pInstance != NULL);
    return m_pInstance;

  //## end CSYStateProcessIdle::GetInstance%1044959881.body
}

void CSYStateProcessIdle::ReadSoftwareVersions (ICOStateMachineContext* p_pContext, CPISyncObjListSWCompVersion* p_pClientSyncObj)
{
  //## begin CSYStateProcessIdle::ReadSoftwareVersions%1067594683.body preserve=yes
    CSYStateProcessReadSoftwareVersions::GetInstance()->SetpClientSyncObj(p_pClientSyncObj);
    p_pContext->ChangeState(CSYStateProcessReadSoftwareVersions::GetInstance());
  //## end CSYStateProcessIdle::ReadSoftwareVersions%1067594683.body
}

void CSYStateProcessIdle::SetInterfaceConfig (ICOStateMachineContext* p_pContext, CPIInterfaceConfig* p_pInterfaceConfig, CCOSyncObject* p_pClientSyncObj)
{
  //## begin CSYStateProcessIdle::SetInterfaceConfig%1091689304.body preserve=yes
    GetpContext(p_pContext)->SetpSetInterfaceCfgSyncObj(p_pClientSyncObj);
	CSYStateConstitutionConfigInterface::GetInstance()->SetpInterfaceConfig(p_pInterfaceConfig);
	p_pContext->ChangeState(CSYStateConstitutionConfigInterface::GetInstance());
  //## end CSYStateProcessIdle::SetInterfaceConfig%1091689304.body
}

void CSYStateProcessIdle::SetStandbyTimeout (ICOStateMachineContext* p_pContext, unsigned int p_uiTimeout)
{
  //## begin CSYStateProcessIdle::SetStandbyTimeout%1096722426.body preserve=yes
    GetpContext(p_pContext)->SetuiWarmupTimeout(p_uiTimeout);
  //## end CSYStateProcessIdle::SetStandbyTimeout%1096722426.body
}

void CSYStateProcessIdle::StartDevice (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcessIdle::StartDevice%1182780770.body preserve=yes
	CSYStateProcess::StartDevice(p_pContext);
  //## end CSYStateProcessIdle::StartDevice%1182780770.body
}

void CSYStateProcessIdle::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateProcessIdle::ConnectionEstablished%1183536496.body preserve=yes
	//The connection has been restablished
#ifdef DEBUG
	CETFileLogger::GetInstance()->AddMessage(_T("CSYStateProcessIdle::ConnectionEstablished -> CPIObjectFactory::GetInstance()->RestartDevice()"));
#endif
	CPIObjectFactory::GetInstance()->RestartDevice();
  //## end CSYStateProcessIdle::ConnectionEstablished%1183536496.body
}

// Additional Declarations
  //## begin CSYStateProcessIdle%3EDC5B9C02C2.declarations preserve=yes
  //## end CSYStateProcessIdle%3EDC5B9C02C2.declarations

//## begin module%3EED88180125.epilog preserve=yes
//## end module%3EED88180125.epilog
