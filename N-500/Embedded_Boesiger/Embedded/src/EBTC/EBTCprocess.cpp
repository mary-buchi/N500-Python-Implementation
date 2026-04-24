//## begin module%3E41046C0373.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E41046C0373.cm

//## begin module%3E41046C0373.cp preserve=no
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
//## end module%3E41046C0373.cp

//## Module: EBTCprocess%3E41046C0373; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCprocess.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E41046C0373.additionalIncludes preserve=no
//## end module%3E41046C0373.additionalIncludes

//## begin module%3E41046C0373.includes preserve=yes
//## end module%3E41046C0373.includes

// EBCOimct
#include "EBCOimct.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBPItype
#include "EBPItype.h"
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
// EBTCconn
#include "EBTCconn.h"
// EBTCident
#include "EBTCident.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3E41046C0373.declarations preserve=no
//## end module%3E41046C0373.declarations

//## begin module%3E41046C0373.additionalDeclarations preserve=yes
//## end module%3E41046C0373.additionalDeclarations


// Class CTCStateProcess 

CTCStateProcess::CTCStateProcess()
  //## begin CTCStateProcess::CTCStateProcess%.hasinit preserve=no
  //## end CTCStateProcess::CTCStateProcess%.hasinit
  //## begin CTCStateProcess::CTCStateProcess%.initialization preserve=yes
  //## end CTCStateProcess::CTCStateProcess%.initialization
{
  //## begin CTCStateProcess::CTCStateProcess%.body preserve=yes
  //## end CTCStateProcess::CTCStateProcess%.body
}


CTCStateProcess::~CTCStateProcess()
{
  //## begin CTCStateProcess::~CTCStateProcess%.body preserve=yes
  //## end CTCStateProcess::~CTCStateProcess%.body
}



//## Other Operations (implementation)
void CTCStateProcess::Stop (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateProcess::Stop%1044604252.body preserve=yes
	p_pContext->ChangeState(CTCStateConfigIdle::GetInstance());
  //## end CTCStateProcess::Stop%1044604252.body
}

void CTCStateProcess::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateProcess::CleanupInitialize%1055317631.body preserve=yes

	// Mute further exceptions with this cosmic construction.
	try{ GetpContext(p_pContext)->GetpLogic()->HeaterOff(); }catch(...){}

	p_pContext->ChangeState(CTCStateConfigIdle::GetInstance());
  //## end CTCStateProcess::CleanupInitialize%1055317631.body
}

void CTCStateProcess::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateProcess::ConnectionLost%1055922853.body preserve=yes

	GetpContext(p_pContext)->GetpLogic()->HeaterOff();

	p_pContext->ChangeState( CTCStateNotConnectedProcess::GetInstance() );

  //## end CTCStateProcess::ConnectionLost%1055922853.body
}

void CTCStateProcess::Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pIncidentSyncObj)
{
  //## begin CTCStateProcess::Start%1056003015.body preserve=yes
	CO_TRACE(TC_ID, _T("CTCStateProcess - ???? Why is start executed\n"));
  //## end CTCStateProcess::Start%1056003015.body
}

void CTCStateProcess::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateProcess::Shutdown%1183379135.body preserve=yes
	//CO_TRACE(TC_ID, _T("CTCStateProcess - Shutdown (Disable Watchdog, go into CTCStateCreated)"));
	IHIInterface::GetInstance()->DisableWatchdog();
	GetpContext(p_pContext)->GetpLogic()->HeaterOff();
	p_pContext->ChangeState( CTCStateCreated::GetInstance() );
  //## end CTCStateProcess::Shutdown%1183379135.body
}

void CTCStateProcess::CellUndocked (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateProcess::CellUndocked%1216975786.body preserve=yes
	//CO_TRACE(TC_ID, _T("CTCStateProcess - CellUndocked (Disable Watchdog, go into CTCStateConfigIdle)"));
	IHIInterface::GetInstance()->DisableWatchdog();
	GetpContext(p_pContext)->GetpLogic()->HeaterOff();
	p_pContext->ChangeState( CTCStateCreated::GetInstance() );
  //## end CTCStateProcess::CellUndocked%1216975786.body
}

// Additional Declarations
  //## begin CTCStateProcess%3E41070F017F.declarations preserve=yes
  //## end CTCStateProcess%3E41070F017F.declarations

// Class CTCStateProcessControl 

//## begin CTCStateProcessControl::pInstance%3E51FF3702CD.role preserve=no  public: static CTCStateProcessControl {1..1 -> 1..1RFHN}
CTCStateProcessControl *CTCStateProcessControl::m_pInstance = NULL;
//## end CTCStateProcessControl::pInstance%3E51FF3702CD.role


CTCStateProcessControl::CTCStateProcessControl()
  //## begin CTCStateProcessControl::CTCStateProcessControl%.hasinit preserve=no
  //## end CTCStateProcessControl::CTCStateProcessControl%.hasinit
  //## begin CTCStateProcessControl::CTCStateProcessControl%.initialization preserve=yes
  //## end CTCStateProcessControl::CTCStateProcessControl%.initialization
{
  //## begin CTCStateProcessControl::CTCStateProcessControl%.body preserve=yes
  //## end CTCStateProcessControl::CTCStateProcessControl%.body
}


CTCStateProcessControl::~CTCStateProcessControl()
{
  //## begin CTCStateProcessControl::~CTCStateProcessControl%.body preserve=yes
  //## end CTCStateProcessControl::~CTCStateProcessControl%.body
}



//## Other Operations (implementation)
void CTCStateProcessControl::Create ()
{
  //## begin CTCStateProcessControl::Create%1044522166.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CTCStateProcessControl();
  //## end CTCStateProcessControl::Create%1044522166.body
}

CTCStateProcessControl* CTCStateProcessControl::GetInstance ()
{
  //## begin CTCStateProcessControl::GetInstance%1044522167.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CTCStateProcessControl::GetInstance%1044522167.body
}

void CTCStateProcessControl::Delete ()
{
  //## begin CTCStateProcessControl::Delete%1044522168.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CTCStateProcessControl::Delete%1044522168.body
}

void CTCStateProcessControl::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateProcessControl::Do%1045140118.body preserve=yes

    try
    {
	    // Get actual temperature in °C.
	    GetpContext(p_pContext)->GetpLogic()->GetTemp();
	    GetpContext(p_pContext)->GetpLogic()->CheckTemp();

		IHIInterface::GetInstance()->EnableWatchdog(eHIWd60s);

	    double l_dTempAct = GetpContext(p_pContext)->GetpLogic()->GetdTempAct();
	    CO_TRACE1(TC_ID, _T("Sample temp: %.4f"), l_dTempAct);

	    // PID Controler
	    double l_dPidOut = GetpContext(p_pContext)->PIDDo( l_dTempAct );
	    
	    // Calc duty cycle.
	    GetpContext(p_pContext)->GetpLogic()->SetdDutyCycle( l_dPidOut );

	    switch( GetpContext(p_pContext)->GetpLogic()->GeteHeaterState() )
	    {
	    case eOn:
	    case eOff:
		    // Go idling.
		    p_pContext->ChangeState(CTCStateProcessIdle::GetInstance());
		    break;

	    case ePwm:
		    p_pContext->ChangeState(CTCStateProcessPwmHigh::GetInstance());
		    break;

	    default:
		    ASSERT(false);
	    }
 
	}

	
    catch(...)
    {
		// e.g. XCOExceptionCellUndocked
		throw;
    }
	
  //## end CTCStateProcessControl::Do%1045140118.body
}

// Additional Declarations
  //## begin CTCStateProcessControl%3E410AAF0353.declarations preserve=yes
  //## end CTCStateProcessControl%3E410AAF0353.declarations

// Class CTCStateProcessIdle 

//## begin CTCStateProcessIdle::pInstance%3E4230DB0095.role preserve=no  public: static CTCStateProcessIdle {1..1 -> 1..1RFHN}
CTCStateProcessIdle *CTCStateProcessIdle::m_pInstance = NULL;
//## end CTCStateProcessIdle::pInstance%3E4230DB0095.role


CTCStateProcessIdle::CTCStateProcessIdle()
  //## begin CTCStateProcessIdle::CTCStateProcessIdle%.hasinit preserve=no
  //## end CTCStateProcessIdle::CTCStateProcessIdle%.hasinit
  //## begin CTCStateProcessIdle::CTCStateProcessIdle%.initialization preserve=yes
  //## end CTCStateProcessIdle::CTCStateProcessIdle%.initialization
{
  //## begin CTCStateProcessIdle::CTCStateProcessIdle%.body preserve=yes
  //## end CTCStateProcessIdle::CTCStateProcessIdle%.body
}


CTCStateProcessIdle::~CTCStateProcessIdle()
{
  //## begin CTCStateProcessIdle::~CTCStateProcessIdle%.body preserve=yes
  //## end CTCStateProcessIdle::~CTCStateProcessIdle%.body
}



//## Other Operations (implementation)
void CTCStateProcessIdle::Create ()
{
  //## begin CTCStateProcessIdle::Create%1044522158.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CTCStateProcessIdle();
  //## end CTCStateProcessIdle::Create%1044522158.body
}

CTCStateProcessIdle* CTCStateProcessIdle::GetInstance ()
{
  //## begin CTCStateProcessIdle::GetInstance%1044522159.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CTCStateProcessIdle::GetInstance%1044522159.body
}

void CTCStateProcessIdle::Delete ()
{
  //## begin CTCStateProcessIdle::Delete%1044522160.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CTCStateProcessIdle::Delete%1044522160.body
}

void CTCStateProcessIdle::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateProcessIdle::Do%1045140119.body preserve=yes

	// WaitOnActionDone needs a sync object.
	try
	{
		CCOSyncObjectPtr l_pSyncObj;

		l_pSyncObj = new CCOSyncObject();
		if( GetpContext(p_pContext)->GetpLogic()->GeteHeaterState() == eOn )
		{
			GetpContext(p_pContext)->GetpLogic()->HeaterOn();
		}
		else if ( GetpContext(p_pContext)->GetpLogic()->GeteHeaterState() == eOff )
		{
			GetpContext(p_pContext)->GetpLogic()->HeaterOff();
		}

		// Sampling time.
		DWORD l_dwSamplingTime = (DWORD)GetpContext(p_pContext)->GetpConfig()->GetiPid_Ts();

		ECOInterruptReason l_eReason = p_pContext->WaitOnActionDone(
			l_pSyncObj, 
			CO_WAKE_MASK_CMD_ABOVE_NORMAL+CO_WAKE_MASK_CMD_HIGH+CO_WAKE_MASK_ACTIONS_ALL, 
			l_dwSamplingTime);

		switch(l_eReason)
		{
		case eIRActionsDone:
			ASSERT(false);
			break;

		case eIRCmdAboveNormal:
			break;

		case eIRCmdHigh:
			// stop/about/suspend-resume/connectionlost -> exit
			// do nothing state change made in the commands
			break;

		case eIRTimeout:
			// control. exit?
			// auto transition: go cyclic to state ProcessControl.
			p_pContext->ChangeState(CTCStateProcessControl::GetInstance());
			break;

		default:
			ASSERT(FALSE);
		}

	}

	catch(...)
	{
		// e.g. XCOExceptionCellUndocked
		throw;
	}


  //## end CTCStateProcessIdle::Do%1045140119.body
}

// Additional Declarations
  //## begin CTCStateProcessIdle%3E410A8301DC.declarations preserve=yes
  //## end CTCStateProcessIdle%3E410A8301DC.declarations

// Class CTCStateProcessPwmHigh 

//## begin CTCStateProcessPwmHigh::pInstance%40CD688E01BE.role preserve=no  public: static CTCStateProcessPwmHigh {1..1 -> 1..1RFHN}
CTCStateProcessPwmHigh *CTCStateProcessPwmHigh::m_pInstance = NULL;
//## end CTCStateProcessPwmHigh::pInstance%40CD688E01BE.role


CTCStateProcessPwmHigh::CTCStateProcessPwmHigh()
  //## begin CTCStateProcessPwmHigh::CTCStateProcessPwmHigh%.hasinit preserve=no
  //## end CTCStateProcessPwmHigh::CTCStateProcessPwmHigh%.hasinit
  //## begin CTCStateProcessPwmHigh::CTCStateProcessPwmHigh%.initialization preserve=yes
  //## end CTCStateProcessPwmHigh::CTCStateProcessPwmHigh%.initialization
{
  //## begin CTCStateProcessPwmHigh::CTCStateProcessPwmHigh%.body preserve=yes
  //## end CTCStateProcessPwmHigh::CTCStateProcessPwmHigh%.body
}


CTCStateProcessPwmHigh::~CTCStateProcessPwmHigh()
{
  //## begin CTCStateProcessPwmHigh::~CTCStateProcessPwmHigh%.body preserve=yes
  //## end CTCStateProcessPwmHigh::~CTCStateProcessPwmHigh%.body
}



//## Other Operations (implementation)
void CTCStateProcessPwmHigh::Create ()
{
  //## begin CTCStateProcessPwmHigh::Create%1087195410.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CTCStateProcessPwmHigh();
  //## end CTCStateProcessPwmHigh::Create%1087195410.body
}

CTCStateProcessPwmHigh* CTCStateProcessPwmHigh::GetInstance ()
{
  //## begin CTCStateProcessPwmHigh::GetInstance%1087195411.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CTCStateProcessPwmHigh::GetInstance%1087195411.body
}

void CTCStateProcessPwmHigh::Delete ()
{
  //## begin CTCStateProcessPwmHigh::Delete%1087195412.body preserve=yes
	if(m_pInstance != NULL)
	{
      delete m_pInstance;
	}
    m_pInstance = NULL;

  //## end CTCStateProcessPwmHigh::Delete%1087195412.body
}

void CTCStateProcessPwmHigh::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateProcessPwmHigh::Do%1087195413.body preserve=yes
    
	CCOSyncObjectPtr l_pSyncObj = NULL;
	try
	{
		// New object.
		l_pSyncObj = new CCOSyncObject();

		// Switch heater on.
		GetpContext(p_pContext)->GetpLogic()->HeaterOn();

		// get time out form config. (dutycycle * sampling time)
		DWORD l_dwTimeOut = (DWORD)( GetpContext(p_pContext)->GetpLogic()->GetdDutyCycle() * GetpContext(p_pContext)->GetpConfig()->GetiPid_Ts() );

		ECOInterruptReason l_eReason = p_pContext->WaitOnActionDone(
				l_pSyncObj, 
				CO_WAKE_MASK_CMD_ABOVE_NORMAL + CO_WAKE_MASK_CMD_HIGH + CO_WAKE_MASK_ACTIONS_ALL, 
				l_dwTimeOut);

		switch(l_eReason)
		{
		case eIRActionsDone:
			ASSERT(false);
			break;

		case eIRCmdAboveNormal:
			ASSERT(false);
			break;

		case eIRCmdHigh:
			// Stop Abort Suspend-resume -> Exit
			// do nothing state change made in the commands
			break;

		case eIRTimeout:
			p_pContext->ChangeState( CTCStateProcessPwmLow::GetInstance() );
			break;

		default:
			ASSERT(false);
			break;
		}
	}
	catch(...)
	{
		throw;
	}
  //## end CTCStateProcessPwmHigh::Do%1087195413.body
}

// Additional Declarations
  //## begin CTCStateProcessPwmHigh%40CD681A0065.declarations preserve=yes
  //## end CTCStateProcessPwmHigh%40CD681A0065.declarations

// Class CTCStateProcessPwmLow 

//## begin CTCStateProcessPwmLow::pInstance%40CD68910289.role preserve=no  public: static CTCStateProcessPwmLow {1..1 -> 1..1RFHN}
CTCStateProcessPwmLow *CTCStateProcessPwmLow::m_pInstance = NULL;
//## end CTCStateProcessPwmLow::pInstance%40CD68910289.role


CTCStateProcessPwmLow::CTCStateProcessPwmLow()
  //## begin CTCStateProcessPwmLow::CTCStateProcessPwmLow%.hasinit preserve=no
  //## end CTCStateProcessPwmLow::CTCStateProcessPwmLow%.hasinit
  //## begin CTCStateProcessPwmLow::CTCStateProcessPwmLow%.initialization preserve=yes
  //## end CTCStateProcessPwmLow::CTCStateProcessPwmLow%.initialization
{
  //## begin CTCStateProcessPwmLow::CTCStateProcessPwmLow%.body preserve=yes
  //## end CTCStateProcessPwmLow::CTCStateProcessPwmLow%.body
}


CTCStateProcessPwmLow::~CTCStateProcessPwmLow()
{
  //## begin CTCStateProcessPwmLow::~CTCStateProcessPwmLow%.body preserve=yes
  //## end CTCStateProcessPwmLow::~CTCStateProcessPwmLow%.body
}



//## Other Operations (implementation)
void CTCStateProcessPwmLow::Create ()
{
  //## begin CTCStateProcessPwmLow::Create%1087195414.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CTCStateProcessPwmLow();
  //## end CTCStateProcessPwmLow::Create%1087195414.body
}

CTCStateProcessPwmLow* CTCStateProcessPwmLow::GetInstance ()
{
  //## begin CTCStateProcessPwmLow::GetInstance%1087195415.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CTCStateProcessPwmLow::GetInstance%1087195415.body
}

void CTCStateProcessPwmLow::Delete ()
{
  //## begin CTCStateProcessPwmLow::Delete%1087195416.body preserve=yes
	if(m_pInstance != NULL)
	{
      delete m_pInstance;
	}
    m_pInstance = NULL;
  //## end CTCStateProcessPwmLow::Delete%1087195416.body
}

void CTCStateProcessPwmLow::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateProcessPwmLow::Do%1087195417.body preserve=yes
	CCOSyncObjectPtr l_pSyncObj = NULL;
	try
	{
		// New object.
		l_pSyncObj = new CCOSyncObject();

		// Switch heater on.
		GetpContext(p_pContext)->GetpLogic()->HeaterOff();

		// get time out form config. (dutycycle * sampling time)
		DWORD l_dwTimeOut = (DWORD)( (1 - GetpContext(p_pContext)->GetpLogic()->GetdDutyCycle()) * GetpContext(p_pContext)->GetpConfig()->GetiPid_Ts() );

		ECOInterruptReason l_eReason = p_pContext->WaitOnActionDone(
				l_pSyncObj, 
				CO_WAKE_MASK_CMD_ABOVE_NORMAL + CO_WAKE_MASK_CMD_HIGH + CO_WAKE_MASK_ACTIONS_ALL, 
				l_dwTimeOut);

		switch(l_eReason)
		{
		case eIRActionsDone:
			ASSERT(false);
			break;

		case eIRCmdAboveNormal:
			ASSERT(false);
			break;

		case eIRCmdHigh:
			// Stop Abort Suspend-resume -> Exit
			// do nothing state change made in the commands
			break;

		case eIRTimeout:
			p_pContext->ChangeState( CTCStateProcessControl::GetInstance() );
			break;

		default:
			ASSERT(false);
			break;
		}
	}
	catch(...)
	{
		throw;
	}
  //## end CTCStateProcessPwmLow::Do%1087195417.body
}

// Additional Declarations
  //## begin CTCStateProcessPwmLow%40CD682C01CD.declarations preserve=yes
  //## end CTCStateProcessPwmLow%40CD682C01CD.declarations

//## begin module%3E41046C0373.epilog preserve=yes
//## end module%3E41046C0373.epilog
