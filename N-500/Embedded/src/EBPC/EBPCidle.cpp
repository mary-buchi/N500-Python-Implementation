//## begin module%3EED769F0364.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F0364.cm

//## begin module%3EED769F0364.cp preserve=no
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
//## end module%3EED769F0364.cp

//## Module: EBPCidle%3EED769F0364; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCidle.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F0364.additionalIncludes preserve=no
//## end module%3EED769F0364.additionalIncludes

//## begin module%3EED769F0364.includes preserve=yes
//## end module%3EED769F0364.includes

// EBCOimct
#include "EBCOimct.h"
// EBPItype
#include "EBPItype.h"
// EBPCpid
#include "EBPCpid.h"
// EBPCexcp
#include "EBPCexcp.h"
// EBPCconn
#include "EBPCconn.h"
// EBPClogic
#include "EBPClogic.h"
// EBPCproc
#include "EBPCproc.h"
// EBPCconfig
#include "EBPCconfig.h"
// EBPCidle
#include "EBPCidle.h"
// EBPCimpl
#include "EBPCimpl.h"
// EBPCcrea
#include "EBPCcrea.h"
// EBPCident
#include "EBPCident.h"
// EBHIenum
#include "EBHIenum.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3EED769F0364.declarations preserve=no
//## end module%3EED769F0364.declarations

//## begin module%3EED769F0364.additionalDeclarations preserve=yes
//## end module%3EED769F0364.additionalDeclarations


// Class CPCStateIdleStarting 

//## begin CPCStateIdleStarting::pInstance%4027910500A3.role preserve=no  public: static CPCStateIdleStarting {1..1 -> 1..1RFHN}
CPCStateIdleStarting *CPCStateIdleStarting::m_pInstance;
//## end CPCStateIdleStarting::pInstance%4027910500A3.role


CPCStateIdleStarting::CPCStateIdleStarting()
  //## begin CPCStateIdleStarting::CPCStateIdleStarting%.hasinit preserve=no
  //## end CPCStateIdleStarting::CPCStateIdleStarting%.hasinit
  //## begin CPCStateIdleStarting::CPCStateIdleStarting%.initialization preserve=yes
  //## end CPCStateIdleStarting::CPCStateIdleStarting%.initialization
{
  //## begin CPCStateIdleStarting::CPCStateIdleStarting%.body preserve=yes
  //## end CPCStateIdleStarting::CPCStateIdleStarting%.body
}


CPCStateIdleStarting::~CPCStateIdleStarting()
{
  //## begin CPCStateIdleStarting::~CPCStateIdleStarting%.body preserve=yes
  //## end CPCStateIdleStarting::~CPCStateIdleStarting%.body
}



//## Other Operations (implementation)
void CPCStateIdleStarting::Create ()
{
  //## begin CPCStateIdleStarting::Create%1076330421.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateIdleStarting();
  //## end CPCStateIdleStarting::Create%1076330421.body
}

void CPCStateIdleStarting::Delete ()
{
  //## begin CPCStateIdleStarting::Delete%1076330422.body preserve=yes
	if (m_pInstance != NULL)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPCStateIdleStarting::Delete%1076330422.body
}

CPCStateIdleStarting* CPCStateIdleStarting::GetInstance ()
{
  //## begin CPCStateIdleStarting::GetInstance%1076330423.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateIdleStarting::GetInstance%1076330423.body
}

void CPCStateIdleStarting::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateIdleStarting::Do%1076330424.body preserve=yes

	// Sync object smart pointer.
	CCOSyncObjectPtr p_SyncObjectPtr = NULL;

	// Pointer to logic.
	CPCLogic *l_pLogic = GetpImplementation(p_pContext)->GetpLogic();
	ASSERT(l_pLogic != NULL);

	// Pointer to configuration.
	CPIPowerControlConfig *l_pConfig = GetpImplementation(p_pContext)->GetpConfig();
	ASSERT(l_pLogic != NULL);

	UINT l_dwStandByVoltage = CHIInterface::GetInstance()->GetStaticObjID(eHILmpStandByVoltage); // [mV]
	UINT l_uiDeltaVoltage	= GetpImplementation(p_pContext)->GetpConfig()->GetuiSoftStartDeltaVoltage();
	UINT l_uiVLampDesired	= GetpImplementation(p_pContext)->GetpConfig()->GetuiNominalVoltageLLimit();

	bool l_bStop = false;

	try
	{
		// Config and profile stuff.
		UINT l_uiTimeOut = l_pConfig->GetuiWarmUpTime();

		p_SyncObjectPtr = new CCOSyncObject;

		// Start lamp.
		l_pLogic->PowerOn();

		do
		{
			// wait...
			ECOInterruptReason eReason = p_pContext->WaitOnActionDone(p_SyncObjectPtr, CO_WAKE_MASK_DEFAULT, l_uiTimeOut);

			// change time out after warmup
			l_uiTimeOut = l_pConfig->GetuiSoftStartDeltaTime();

			switch(eReason)
			{
			case eIRTimeout:
				l_pLogic->SetVoltage(l_uiVLampDesired);
				l_uiVLampDesired += l_uiDeltaVoltage;
				// inc voltage
				break;

			case eIRCmdHigh:
				l_bStop = true;
				break;

			case eIRActionsDone:
			case eIRCmdAboveNormal:
			default:
				l_bStop = true;
				break;
			}

		}while (!l_bStop && (l_uiVLampDesired < l_dwStandByVoltage));

		p_pContext->ChangeState( CPCStateIdleStandBy::GetInstance() );

	}
	catch(...)
	{
		throw;
	}
  //## end CPCStateIdleStarting::Do%1076330424.body
}

// Additional Declarations
  //## begin CPCStateIdleStarting%3EED76CC06C6.declarations preserve=yes
  //## end CPCStateIdleStarting%3EED76CC06C6.declarations

// Class CPCStateIdlePowerOff 

//## begin CPCStateIdlePowerOff::pInstance%3EED76CC08C8.role preserve=no  public: static CPCStateIdlePowerOff {1..1 -> 1..1RFHN}
CPCStateIdlePowerOff *CPCStateIdlePowerOff::m_pInstance;
//## end CPCStateIdlePowerOff::pInstance%3EED76CC08C8.role


CPCStateIdlePowerOff::CPCStateIdlePowerOff()
  //## begin CPCStateIdlePowerOff::CPCStateIdlePowerOff%.hasinit preserve=no
  //## end CPCStateIdlePowerOff::CPCStateIdlePowerOff%.hasinit
  //## begin CPCStateIdlePowerOff::CPCStateIdlePowerOff%.initialization preserve=yes
  //## end CPCStateIdlePowerOff::CPCStateIdlePowerOff%.initialization
{
  //## begin CPCStateIdlePowerOff::CPCStateIdlePowerOff%.body preserve=yes
  //## end CPCStateIdlePowerOff::CPCStateIdlePowerOff%.body
}


CPCStateIdlePowerOff::~CPCStateIdlePowerOff()
{
  //## begin CPCStateIdlePowerOff::~CPCStateIdlePowerOff%.body preserve=yes
  //## end CPCStateIdlePowerOff::~CPCStateIdlePowerOff%.body
}



//## Other Operations (implementation)
void CPCStateIdlePowerOff::Create ()
{
  //## begin CPCStateIdlePowerOff::Create%1044522158.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateIdlePowerOff();
  //## end CPCStateIdlePowerOff::Create%1044522158.body
}

CPCStateIdlePowerOff* CPCStateIdlePowerOff::GetInstance ()
{
  //## begin CPCStateIdlePowerOff::GetInstance%1044522159.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateIdlePowerOff::GetInstance%1044522159.body
}

void CPCStateIdlePowerOff::Delete ()
{
  //## begin CPCStateIdlePowerOff::Delete%1044522160.body preserve=yes
	if (m_pInstance != NULL)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPCStateIdlePowerOff::Delete%1044522160.body
}

void CPCStateIdlePowerOff::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateIdlePowerOff::Do%1045140119.body preserve=yes
	GetpImplementation(p_pContext)->GetpLogic()->PowerOff();
  //## end CPCStateIdlePowerOff::Do%1045140119.body
}

void CPCStateIdlePowerOff::PowerOn (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateIdlePowerOff::PowerOn%1076339213.body preserve=yes
	p_pContext->ChangeState( CPCStateIdleStarting::GetInstance() );		
  //## end CPCStateIdlePowerOff::PowerOn%1076339213.body
}

// Additional Declarations
  //## begin CPCStateIdlePowerOff%3EED76CC0724.declarations preserve=yes
  //## end CPCStateIdlePowerOff%3EED76CC0724.declarations

// Class CPCStateIdle 

CPCStateIdle::CPCStateIdle()
  //## begin CPCStateIdle::CPCStateIdle%.hasinit preserve=no
  //## end CPCStateIdle::CPCStateIdle%.hasinit
  //## begin CPCStateIdle::CPCStateIdle%.initialization preserve=yes
  //## end CPCStateIdle::CPCStateIdle%.initialization
{
  //## begin CPCStateIdle::CPCStateIdle%.body preserve=yes
  //## end CPCStateIdle::CPCStateIdle%.body
}


CPCStateIdle::~CPCStateIdle()
{
  //## begin CPCStateIdle::~CPCStateIdle%.body preserve=yes
  //## end CPCStateIdle::~CPCStateIdle%.body
}



//## Other Operations (implementation)
void CPCStateIdle::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateIdle::CleanupInitialize%1063954793.body preserve=yes
	p_pContext->ChangeState( CPCStateIdlePowerOff::GetInstance() );
  //## end CPCStateIdle::CleanupInitialize%1063954793.body
}

void CPCStateIdle::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateIdle::Startup%1076339193.body preserve=yes
	p_pContext->ChangeState( CPCStateConfigNotSet::GetInstance() );
  //## end CPCStateIdle::Startup%1076339193.body
}

void CPCStateIdle::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateIdle::ConnectionLost%1076339201.body preserve=yes
	p_pContext->ChangeState( CPCStateNotConnected::GetInstance() );
  //## end CPCStateIdle::ConnectionLost%1076339201.body
}

void CPCStateIdle::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateIdle::Shutdown%1076339202.body preserve=yes
	p_pContext->ChangeState( CPCStateCreated::GetInstance() );
  //## end CPCStateIdle::Shutdown%1076339202.body
}

void CPCStateIdle::Stop (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateIdle::Stop%1077027754.body preserve=yes
	CO_TRACE(PC_ID, _T("Stop executed. It's an empty funtion..."));
  //## end CPCStateIdle::Stop%1077027754.body
}

// Additional Declarations
  //## begin CPCStateIdle%3EED76CC07BF.declarations preserve=yes
  //## end CPCStateIdle%3EED76CC07BF.declarations

// Class CPCStateIdleCheckPower 

//## begin CPCStateIdleCheckPower::pInstance%4027989E0324.role preserve=no  public: static CPCStateIdleCheckPower {1..1 -> 1..1RFHN}
CPCStateIdleCheckPower *CPCStateIdleCheckPower::m_pInstance;
//## end CPCStateIdleCheckPower::pInstance%4027989E0324.role


CPCStateIdleCheckPower::CPCStateIdleCheckPower()
  //## begin CPCStateIdleCheckPower::CPCStateIdleCheckPower%.hasinit preserve=no
  //## end CPCStateIdleCheckPower::CPCStateIdleCheckPower%.hasinit
  //## begin CPCStateIdleCheckPower::CPCStateIdleCheckPower%.initialization preserve=yes
  //## end CPCStateIdleCheckPower::CPCStateIdleCheckPower%.initialization
{
  //## begin CPCStateIdleCheckPower::CPCStateIdleCheckPower%.body preserve=yes
  //## end CPCStateIdleCheckPower::CPCStateIdleCheckPower%.body
}


CPCStateIdleCheckPower::~CPCStateIdleCheckPower()
{
  //## begin CPCStateIdleCheckPower::~CPCStateIdleCheckPower%.body preserve=yes
  //## end CPCStateIdleCheckPower::~CPCStateIdleCheckPower%.body
}



//## Other Operations (implementation)
void CPCStateIdleCheckPower::Create ()
{
  //## begin CPCStateIdleCheckPower::Create%1076330417.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateIdleCheckPower();
  //## end CPCStateIdleCheckPower::Create%1076330417.body
}

void CPCStateIdleCheckPower::Delete ()
{
  //## begin CPCStateIdleCheckPower::Delete%1076330418.body preserve=yes
	if (m_pInstance != NULL)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPCStateIdleCheckPower::Delete%1076330418.body
}

CPCStateIdleCheckPower* CPCStateIdleCheckPower::GetInstance ()
{
  //## begin CPCStateIdleCheckPower::GetInstance%1076330419.body preserve=yes
  	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateIdleCheckPower::GetInstance%1076330419.body
}

void CPCStateIdleCheckPower::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateIdleCheckPower::Do%1076330420.body preserve=yes
	UINT l_uiActPower = GetpImplementation(p_pContext)->GetpLogic()->ActPower();
	UINT l_uiPowerLLimit = GetpImplementation(p_pContext)->GetpProfile()->GetuiPowerErrorLLimit();

	if ( l_uiActPower < l_uiPowerLLimit )
		p_pContext->ChangeState(CPCStateIdleStarting::GetInstance());
	else
		p_pContext->ChangeState(CPCStateIdleStandBy::GetInstance());
  //## end CPCStateIdleCheckPower::Do%1076330420.body
}

// Additional Declarations
  //## begin CPCStateIdleCheckPower%402790940381.declarations preserve=yes
  //## end CPCStateIdleCheckPower%402790940381.declarations

// Class CPCStateIdleStandBy 

//## begin CPCStateIdleStandBy::pInstance%40279A3B020A.role preserve=no  public: static CPCStateIdleStandBy {1..1 -> 1..1RFHN}
CPCStateIdleStandBy *CPCStateIdleStandBy::m_pInstance;
//## end CPCStateIdleStandBy::pInstance%40279A3B020A.role


CPCStateIdleStandBy::CPCStateIdleStandBy()
  //## begin CPCStateIdleStandBy::CPCStateIdleStandBy%.hasinit preserve=no
  //## end CPCStateIdleStandBy::CPCStateIdleStandBy%.hasinit
  //## begin CPCStateIdleStandBy::CPCStateIdleStandBy%.initialization preserve=yes
  //## end CPCStateIdleStandBy::CPCStateIdleStandBy%.initialization
{
  //## begin CPCStateIdleStandBy::CPCStateIdleStandBy%.body preserve=yes
  //## end CPCStateIdleStandBy::CPCStateIdleStandBy%.body
}


CPCStateIdleStandBy::~CPCStateIdleStandBy()
{
  //## begin CPCStateIdleStandBy::~CPCStateIdleStandBy%.body preserve=yes
  //## end CPCStateIdleStandBy::~CPCStateIdleStandBy%.body
}



//## Other Operations (implementation)
void CPCStateIdleStandBy::Create ()
{
  //## begin CPCStateIdleStandBy::Create%1076330425.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateIdleStandBy();
  //## end CPCStateIdleStandBy::Create%1076330425.body
}

void CPCStateIdleStandBy::Delete ()
{
  //## begin CPCStateIdleStandBy::Delete%1076330426.body preserve=yes
	if(m_pInstance != NULL)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPCStateIdleStandBy::Delete%1076330426.body
}

CPCStateIdleStandBy* CPCStateIdleStandBy::GetInstance ()
{
  //## begin CPCStateIdleStandBy::GetInstance%1076330427.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateIdleStandBy::GetInstance%1076330427.body
}

void CPCStateIdleStandBy::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateIdleStandBy::Do%1076330428.body preserve=yes

	DWORD l_dwStandByVoltage = CHIInterface::GetInstance()->GetStaticObjID(eHILmpStandByVoltage); // [mV]
	GetpImplementation(p_pContext)->GetpLogic()->SelectLamp();
	GetpImplementation(p_pContext)->GetpLogic()->SetVoltage(l_dwStandByVoltage);

//	GetpImplementation(p_pContext)->GetpPID()->Set(4, 1, 0, 10.5, 8.5, 100);
//	GetpImplementation(p_pContext)->GetpLogic()->SetbInitDone(false);

  //## end CPCStateIdleStandBy::Do%1076330428.body
}

void CPCStateIdleStandBy::Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObject)
{
  //## begin CPCStateIdleStandBy::Start%1076339212.body preserve=yes
	
	// Save sync object. Signal it when oszillation of lamp is in the tolerance band.
	GetpImplementation(p_pContext)->GetpLogic()->SetpStartSyncObject(p_pClientSyncObject);

	p_pContext->ChangeState( CPCStateProcessStarting::GetInstance() );
  //## end CPCStateIdleStandBy::Start%1076339212.body
}

void CPCStateIdleStandBy::PowerOff (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateIdleStandBy::PowerOff%1076339214.body preserve=yes
	p_pContext->ChangeState( CPCStateIdlePowerOff::GetInstance() );
  //## end CPCStateIdleStandBy::PowerOff%1076339214.body
}

void CPCStateIdleStandBy::Exit (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateIdleStandBy::Exit%1076482787.body preserve=yes
	GetpImplementation(p_pContext)->GetpLogic()->SetdwTimeBase( GetTickCount() );
	GetpImplementation(p_pContext)->GetpPID()->Reset();
	GetpImplementation(p_pContext)->GetpLogic()->SetuiSettlingTime(0);
  //## end CPCStateIdleStandBy::Exit%1076482787.body
}

// Additional Declarations
  //## begin CPCStateIdleStandBy%40279A2A03BF.declarations preserve=yes
  //## end CPCStateIdleStandBy%40279A2A03BF.declarations

//## begin module%3EED769F0364.epilog preserve=yes
//## end module%3EED769F0364.epilog
