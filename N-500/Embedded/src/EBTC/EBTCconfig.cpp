//## begin module%3E41045C0373.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E41045C0373.cm

//## begin module%3E41045C0373.cp preserve=no
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
//## end module%3E41045C0373.cp

//## Module: EBTCconfig%3E41045C0373; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCconfig.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E41045C0373.additionalIncludes preserve=no
//## end module%3E41045C0373.additionalIncludes

//## begin module%3E41045C0373.includes preserve=yes
//## end module%3E41045C0373.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBPItype
#include "EBPItype.h"
// EBCOimct
#include "EBCOimct.h"
// EBTCpid
#include "EBTCpid.h"
// EBTCconn
#include "EBTCconn.h"
// EBTClogic
#include "EBTClogic.h"
// EBTCprocess
#include "EBTCprocess.h"
// EBTCconfig
#include "EBTCconfig.h"
// EBTCidle
#include "EBTCidle.h"
// EBTCimpl
#include "EBTCimpl.h"
// EBTCident
#include "EBTCident.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3E41045C0373.declarations preserve=no
//## end module%3E41045C0373.declarations

//## begin module%3E41045C0373.additionalDeclarations preserve=yes
//## end module%3E41045C0373.additionalDeclarations


// Class CTCStateConfigNotSet 

//## begin CTCStateConfigNotSet::pInstance%3E4120AF01DD.role preserve=no  public: static CTCStateConfigNotSet {1..1 -> 1..1RFHN}
CTCStateConfigNotSet *CTCStateConfigNotSet::m_pInstance;
//## end CTCStateConfigNotSet::pInstance%3E4120AF01DD.role


CTCStateConfigNotSet::CTCStateConfigNotSet()
  //## begin CTCStateConfigNotSet::CTCStateConfigNotSet%.hasinit preserve=no
  //## end CTCStateConfigNotSet::CTCStateConfigNotSet%.hasinit
  //## begin CTCStateConfigNotSet::CTCStateConfigNotSet%.initialization preserve=yes
  //## end CTCStateConfigNotSet::CTCStateConfigNotSet%.initialization
{
  //## begin CTCStateConfigNotSet::CTCStateConfigNotSet%.body preserve=yes
  //## end CTCStateConfigNotSet::CTCStateConfigNotSet%.body
}


CTCStateConfigNotSet::~CTCStateConfigNotSet()
{
  //## begin CTCStateConfigNotSet::~CTCStateConfigNotSet%.body preserve=yes
  //## end CTCStateConfigNotSet::~CTCStateConfigNotSet%.body
}



//## Other Operations (implementation)
void CTCStateConfigNotSet::Create ()
{
  //## begin CTCStateConfigNotSet::Create%1044457421.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CTCStateConfigNotSet();
  //## end CTCStateConfigNotSet::Create%1044457421.body
}

CTCStateConfigNotSet* CTCStateConfigNotSet::GetInstance ()
{
  //## begin CTCStateConfigNotSet::GetInstance%1044457422.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CTCStateConfigNotSet::GetInstance%1044457422.body
}

void CTCStateConfigNotSet::Delete ()
{
  //## begin CTCStateConfigNotSet::Delete%1038899332.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CTCStateConfigNotSet::Delete%1038899332.body
}

// Additional Declarations
  //## begin CTCStateConfigNotSet%3E40E95001FC.declarations preserve=yes
  //## end CTCStateConfigNotSet%3E40E95001FC.declarations

// Class CTCStateConfig 

CTCStateConfig::CTCStateConfig()
  //## begin CTCStateConfig::CTCStateConfig%.hasinit preserve=no
  //## end CTCStateConfig::CTCStateConfig%.hasinit
  //## begin CTCStateConfig::CTCStateConfig%.initialization preserve=yes
  //## end CTCStateConfig::CTCStateConfig%.initialization
{
  //## begin CTCStateConfig::CTCStateConfig%.body preserve=yes
  //## end CTCStateConfig::CTCStateConfig%.body
}


CTCStateConfig::~CTCStateConfig()
{
  //## begin CTCStateConfig::~CTCStateConfig%.body preserve=yes
  //## end CTCStateConfig::~CTCStateConfig%.body
}



//## Other Operations (implementation)
void CTCStateConfig::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateConfig::Shutdown%1044457420.body preserve=yes
	 p_pContext->ChangeState(CTCStateCreated::GetInstance());
  //## end CTCStateConfig::Shutdown%1044457420.body
}

void CTCStateConfig::SetConfiguration (ICOStateMachineContext* p_pContext, CPITemperatureControlConfig* p_pConfig)
{
  //## begin CTCStateConfig::SetConfiguration%1044604253.body preserve=yes
	const DWORD dw230VOFF = 0;
	const DWORD dw230VON = 1;
	const DWORD dw115VOFF = 2;
	const DWORD dw115VON = 3;

	GetpContext(p_pContext)->SetpConfig(p_pConfig);
	GetpContext( p_pContext )->GetpLogic()->SetdwOutputID(p_pConfig->GetdwIDHeaterOutput());
    
	if( p_pConfig->GeteLineVoltage() == e115V )
	{
		GetpContext( p_pContext )->GetpLogic()->SetdwOn( dw115VON );
		GetpContext( p_pContext )->GetpLogic()->SetdwOff( dw115VOFF );
	}
	else if ( p_pConfig->GeteLineVoltage() == e230V )
	{
		GetpContext( p_pContext )->GetpLogic()->SetdwOn( dw230VON );
		GetpContext( p_pContext )->GetpLogic()->SetdwOff( dw230VOFF );
	}

    p_pContext->ChangeState(CTCStateConfigSetConfig::GetInstance());
  //## end CTCStateConfig::SetConfiguration%1044604253.body
}

void CTCStateConfig::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateConfig::CleanupInitialize%1055317629.body preserve=yes
	p_pContext->ChangeState(CTCStateCreated::GetInstance());
  //## end CTCStateConfig::CleanupInitialize%1055317629.body
}

void CTCStateConfig::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateConfig::ConnectionLost%1055335989.body preserve=yes
	p_pContext->ChangeState( CTCStateNotConnectedConfig::GetInstance() );
  //## end CTCStateConfig::ConnectionLost%1055335989.body
}

void CTCStateConfig::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateConfig::Startup%1055922854.body preserve=yes
	p_pContext->ChangeState(CTCStateConfigNotSet::GetInstance());
  //## end CTCStateConfig::Startup%1055922854.body
}

void CTCStateConfig::Stop (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateConfig::Stop%1070632807.body preserve=yes
	CO_TRACE(TC_ID, _T("Stop executed. It's an empty function... \n"));
  //## end CTCStateConfig::Stop%1070632807.body
}

void CTCStateConfig::CellUndocked (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateConfig::CellUndocked%1216975790.body preserve=yes
		p_pContext->ChangeState( CTCStateCreated::GetInstance() );
  //## end CTCStateConfig::CellUndocked%1216975790.body
}

// Additional Declarations
  //## begin CTCStateConfig%3E4106B80324.declarations preserve=yes
  //## end CTCStateConfig%3E4106B80324.declarations

// Class CTCStateConfigProfileNotSet 

//## begin CTCStateConfigProfileNotSet::pInstance%3E4120100334.role preserve=no  public: static CTCStateConfigProfileNotSet {1..1 -> 1..1RFHN}
CTCStateConfigProfileNotSet *CTCStateConfigProfileNotSet::m_pInstance;
//## end CTCStateConfigProfileNotSet::pInstance%3E4120100334.role


CTCStateConfigProfileNotSet::CTCStateConfigProfileNotSet()
  //## begin CTCStateConfigProfileNotSet::CTCStateConfigProfileNotSet%.hasinit preserve=no
  //## end CTCStateConfigProfileNotSet::CTCStateConfigProfileNotSet%.hasinit
  //## begin CTCStateConfigProfileNotSet::CTCStateConfigProfileNotSet%.initialization preserve=yes
  //## end CTCStateConfigProfileNotSet::CTCStateConfigProfileNotSet%.initialization
{
  //## begin CTCStateConfigProfileNotSet::CTCStateConfigProfileNotSet%.body preserve=yes
  //## end CTCStateConfigProfileNotSet::CTCStateConfigProfileNotSet%.body
}


CTCStateConfigProfileNotSet::~CTCStateConfigProfileNotSet()
{
  //## begin CTCStateConfigProfileNotSet::~CTCStateConfigProfileNotSet%.body preserve=yes
  //## end CTCStateConfigProfileNotSet::~CTCStateConfigProfileNotSet%.body
}



//## Other Operations (implementation)
void CTCStateConfigProfileNotSet::Delete ()
{
  //## begin CTCStateConfigProfileNotSet::Delete%1044522141.body preserve=yes
	if (m_pInstance != NULL)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CTCStateConfigProfileNotSet::Delete%1044522141.body
}

void CTCStateConfigProfileNotSet::Create ()
{
  //## begin CTCStateConfigProfileNotSet::Create%1044522142.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CTCStateConfigProfileNotSet();
  //## end CTCStateConfigProfileNotSet::Create%1044522142.body
}

CTCStateConfigProfileNotSet* CTCStateConfigProfileNotSet::GetInstance ()
{
  //## begin CTCStateConfigProfileNotSet::GetInstance%1044522143.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CTCStateConfigProfileNotSet::GetInstance%1044522143.body
}

void CTCStateConfigProfileNotSet::SetProfile (ICOStateMachineContext* p_pContext, CPITemperatureControlProfile* p_pProfile)
{
  //## begin CTCStateConfigProfileNotSet::SetProfile%1044604256.body preserve=yes
	GetpContext(p_pContext)->SetpProfile(p_pProfile);
	p_pContext->ChangeState(CTCStateConfigSetProfile::GetInstance());
  //## end CTCStateConfigProfileNotSet::SetProfile%1044604256.body
}

// Additional Declarations
  //## begin CTCStateConfigProfileNotSet%3E41072601FC.declarations preserve=yes
  //## end CTCStateConfigProfileNotSet%3E41072601FC.declarations

// Class CTCStateConfigSetProfile 

//## begin CTCStateConfigSetProfile::pInstance%3E41201801FC.role preserve=no  public: static CTCStateConfigSetProfile {1..1 -> 1..1RFHN}
CTCStateConfigSetProfile *CTCStateConfigSetProfile::m_pInstance;
//## end CTCStateConfigSetProfile::pInstance%3E41201801FC.role


CTCStateConfigSetProfile::CTCStateConfigSetProfile()
  //## begin CTCStateConfigSetProfile::CTCStateConfigSetProfile%.hasinit preserve=no
  //## end CTCStateConfigSetProfile::CTCStateConfigSetProfile%.hasinit
  //## begin CTCStateConfigSetProfile::CTCStateConfigSetProfile%.initialization preserve=yes
  //## end CTCStateConfigSetProfile::CTCStateConfigSetProfile%.initialization
{
  //## begin CTCStateConfigSetProfile::CTCStateConfigSetProfile%.body preserve=yes
  //## end CTCStateConfigSetProfile::CTCStateConfigSetProfile%.body
}


CTCStateConfigSetProfile::~CTCStateConfigSetProfile()
{
  //## begin CTCStateConfigSetProfile::~CTCStateConfigSetProfile%.body preserve=yes
  //## end CTCStateConfigSetProfile::~CTCStateConfigSetProfile%.body
}



//## Other Operations (implementation)
void CTCStateConfigSetProfile::Delete ()
{
  //## begin CTCStateConfigSetProfile::Delete%1044522144.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CTCStateConfigSetProfile::Delete%1044522144.body
}

void CTCStateConfigSetProfile::Create ()
{
  //## begin CTCStateConfigSetProfile::Create%1044522145.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CTCStateConfigSetProfile();
  //## end CTCStateConfigSetProfile::Create%1044522145.body
}

CTCStateConfigSetProfile* CTCStateConfigSetProfile::GetInstance ()
{
  //## begin CTCStateConfigSetProfile::GetInstance%1044522146.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CTCStateConfigSetProfile::GetInstance%1044522146.body
}

void CTCStateConfigSetProfile::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateConfigSetProfile::Do%1044873652.body preserve=yes

	// State change.
	p_pContext->ChangeState(CTCStateConfigIdle::GetInstance());

  //## end CTCStateConfigSetProfile::Do%1044873652.body
}

// Additional Declarations
  //## begin CTCStateConfigSetProfile%3E4107360140.declarations preserve=yes
  //## end CTCStateConfigSetProfile%3E4107360140.declarations

// Class CTCStateConfigSetConfig 

//## begin CTCStateConfigSetConfig::pInstance%3E412DD800A5.role preserve=no  public: static CTCStateConfigSetConfig {1..1 -> 1..1RFHN}
CTCStateConfigSetConfig *CTCStateConfigSetConfig::m_pInstance;
//## end CTCStateConfigSetConfig::pInstance%3E412DD800A5.role



CTCStateConfigSetConfig::CTCStateConfigSetConfig()
  //## begin CTCStateConfigSetConfig::CTCStateConfigSetConfig%.hasinit preserve=no
  //## end CTCStateConfigSetConfig::CTCStateConfigSetConfig%.hasinit
  //## begin CTCStateConfigSetConfig::CTCStateConfigSetConfig%.initialization preserve=yes
  //## end CTCStateConfigSetConfig::CTCStateConfigSetConfig%.initialization
{
  //## begin CTCStateConfigSetConfig::CTCStateConfigSetConfig%.body preserve=yes
  //## end CTCStateConfigSetConfig::CTCStateConfigSetConfig%.body
}


CTCStateConfigSetConfig::~CTCStateConfigSetConfig()
{
  //## begin CTCStateConfigSetConfig::~CTCStateConfigSetConfig%.body preserve=yes
  //## end CTCStateConfigSetConfig::~CTCStateConfigSetConfig%.body
}



//## Other Operations (implementation)
void CTCStateConfigSetConfig::Create ()
{
  //## begin CTCStateConfigSetConfig::Create%1044522148.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CTCStateConfigSetConfig();
  //## end CTCStateConfigSetConfig::Create%1044522148.body
}

CTCStateConfigSetConfig* CTCStateConfigSetConfig::GetInstance ()
{
  //## begin CTCStateConfigSetConfig::GetInstance%1044522149.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CTCStateConfigSetConfig::GetInstance%1044522149.body
}

void CTCStateConfigSetConfig::Delete ()
{
  //## begin CTCStateConfigSetConfig::Delete%1044522147.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CTCStateConfigSetConfig::Delete%1044522147.body
}

void CTCStateConfigSetConfig::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateConfigSetConfig::Do%1044873650.body preserve=yes

	// Autotransition: After the initialisation automaticly go to the next state.
	// Calculate PID limits.

	p_pContext->ChangeState(CTCStateConfigProfileNotSet::GetInstance());

  //## end CTCStateConfigSetConfig::Do%1044873650.body
}

// Additional Declarations
  //## begin CTCStateConfigSetConfig%3E410F1E020B.declarations preserve=yes
  //## end CTCStateConfigSetConfig%3E410F1E020B.declarations

// Class CTCStateConfigIdle 

//## begin CTCStateConfigIdle::pInstance%3EE6F4F103A0.role preserve=no  public: static CTCStateConfigIdle {1..1 -> 1..1RFHN}
CTCStateConfigIdle *CTCStateConfigIdle::m_pInstance;
//## end CTCStateConfigIdle::pInstance%3EE6F4F103A0.role


CTCStateConfigIdle::CTCStateConfigIdle()
  //## begin CTCStateConfigIdle::CTCStateConfigIdle%.hasinit preserve=no
  //## end CTCStateConfigIdle::CTCStateConfigIdle%.hasinit
  //## begin CTCStateConfigIdle::CTCStateConfigIdle%.initialization preserve=yes
  //## end CTCStateConfigIdle::CTCStateConfigIdle%.initialization
{
  //## begin CTCStateConfigIdle::CTCStateConfigIdle%.body preserve=yes
  //## end CTCStateConfigIdle::CTCStateConfigIdle%.body
}


CTCStateConfigIdle::~CTCStateConfigIdle()
{
  //## begin CTCStateConfigIdle::~CTCStateConfigIdle%.body preserve=yes
  //## end CTCStateConfigIdle::~CTCStateConfigIdle%.body
}



//## Other Operations (implementation)
void CTCStateConfigIdle::Create ()
{
  //## begin CTCStateConfigIdle::Create%1055317650.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CTCStateConfigIdle();
  //## end CTCStateConfigIdle::Create%1055317650.body
}

CTCStateConfigIdle* CTCStateConfigIdle::GetInstance ()
{
  //## begin CTCStateConfigIdle::GetInstance%1055317651.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CTCStateConfigIdle::GetInstance%1055317651.body
}

void CTCStateConfigIdle::Delete ()
{
  //## begin CTCStateConfigIdle::Delete%1055317652.body preserve=yes
	if (m_pInstance != NULL)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CTCStateConfigIdle::Delete%1055317652.body
}

void CTCStateConfigIdle::SetProfile (ICOStateMachineContext* p_pContext, CPITemperatureControlProfile* p_pProfile)
{
  //## begin CTCStateConfigIdle::SetProfile%1055317653.body preserve=yes
	GetpContext(p_pContext)->SetpProfile(p_pProfile);
	p_pContext->ChangeState(CTCStateConfigSetProfile::GetInstance());
  //## end CTCStateConfigIdle::SetProfile%1055317653.body
}

void CTCStateConfigIdle::Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pIncidentSyncObj)
{
  //## begin CTCStateConfigIdle::Start%1055335990.body preserve=yes
	GetpContext(p_pContext)->GetpLogic()->SetpIncidentSyncObject(p_pIncidentSyncObj);
	p_pContext->ChangeState(CTCStateProcessControl::GetInstance());
  //## end CTCStateConfigIdle::Start%1055335990.body
}

void CTCStateConfigIdle::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateConfigIdle::Enter%1055833092.body preserve=yes

    try
    {
		IHIInterface::GetInstance()->DisableWatchdog();

	    GetpContext(p_pContext)->GetpLogic()->SetpIncidentSyncObject(NULL);

	    double l_dKp = GetpContext(p_pContext)->GetpConfig()->GetiPid_Kp();
	    l_dKp /= 1000;

	    double l_dTi = GetpContext(p_pContext)->GetpConfig()->GetiPid_Ti();
	    l_dTi /= 1000;

	    double l_dTv = GetpContext(p_pContext)->GetpConfig()->GetiPid_Tv();
	    l_dTv /= 1000;

	    double l_dNomTemp = GetpContext(p_pContext)->GetpProfile()->GetiTemperatureNominal();
	    l_dNomTemp /= 1000;

	    // lower limit
	    double l_dLLimit = GetpContext(p_pContext)->GetpConfig()->GetiPid_LLimit();

	    // upper limit
	    double l_dULimit = GetpContext(p_pContext)->GetpConfig()->GetiPid_ULimit();

	    double l_dTs = GetpContext(p_pContext)->GetpConfig()->GetiPid_Ts();
	    l_dTs /= 1000;

	    GetpContext(p_pContext)->PIDReset();

	    GetpContext(p_pContext)->PIDSet(
		    l_dNomTemp,
		    l_dKp, 
		    l_dTi, 
		    l_dTv,
		    l_dLLimit,
		    l_dULimit,
		    l_dTs);

	    GetpContext(p_pContext)->GetpLogic()->Init();
	    GetpContext(p_pContext)->GetpLogic()->HeaterOff();
    }
    catch(...)
    {
        throw;
    }


  //## end CTCStateConfigIdle::Enter%1055833092.body
}

// Additional Declarations
  //## begin CTCStateConfigIdle%3EE6F4F10399.declarations preserve=yes
  //## end CTCStateConfigIdle%3EE6F4F10399.declarations

//## begin module%3E41045C0373.epilog preserve=yes
//## end module%3E41045C0373.epilog
