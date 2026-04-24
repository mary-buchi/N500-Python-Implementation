//## begin module%3EED769F038C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F038C.cm

//## begin module%3EED769F038C.cp preserve=no
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
//## end module%3EED769F038C.cp

//## Module: EBPCproc%3EED769F038C; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCproc.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F038C.additionalIncludes preserve=no
//## end module%3EED769F038C.additionalIncludes

//## begin module%3EED769F038C.includes preserve=yes
//## end module%3EED769F038C.includes

// EBCOimct
#include "EBCOimct.h"
// EBPItype
#include "EBPItype.h"
// EBPCexcp
#include "EBPCexcp.h"
// EBPCconn
#include "EBPCconn.h"
// EBPClogic
#include "EBPClogic.h"
// EBPCpid
#include "EBPCpid.h"
// EBPCproc
#include "EBPCproc.h"
// EBPCidle
#include "EBPCidle.h"
// EBPCimpl
#include "EBPCimpl.h"
// EBPCcrea
#include "EBPCcrea.h"
// EBPCident
#include "EBPCident.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3EED769F038C.declarations preserve=no
//## end module%3EED769F038C.declarations

//## begin module%3EED769F038C.additionalDeclarations preserve=yes
//## end module%3EED769F038C.additionalDeclarations


// Class CPCStateProcessControling 

//## begin CPCStateProcessControling::pInstance%3EED76CC08E8.role preserve=no  public: static CPCStateProcessControling {1..1 -> 1..1RFHN}
CPCStateProcessControling *CPCStateProcessControling::m_pInstance;
//## end CPCStateProcessControling::pInstance%3EED76CC08E8.role


CPCStateProcessControling::CPCStateProcessControling()
  //## begin CPCStateProcessControling::CPCStateProcessControling%.hasinit preserve=no
  //## end CPCStateProcessControling::CPCStateProcessControling%.hasinit
  //## begin CPCStateProcessControling::CPCStateProcessControling%.initialization preserve=yes
  //## end CPCStateProcessControling::CPCStateProcessControling%.initialization
{
  //## begin CPCStateProcessControling::CPCStateProcessControling%.body preserve=yes
  //## end CPCStateProcessControling::CPCStateProcessControling%.body
}


CPCStateProcessControling::~CPCStateProcessControling()
{
  //## begin CPCStateProcessControling::~CPCStateProcessControling%.body preserve=yes
  //## end CPCStateProcessControling::~CPCStateProcessControling%.body
}



//## Other Operations (implementation)
void CPCStateProcessControling::Create ()
{
  //## begin CPCStateProcessControling::Create%1044522166.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateProcessControling();
  //## end CPCStateProcessControling::Create%1044522166.body
}

CPCStateProcessControling* CPCStateProcessControling::GetInstance ()
{
  //## begin CPCStateProcessControling::GetInstance%1044522167.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateProcessControling::GetInstance%1044522167.body
}

void CPCStateProcessControling::Delete ()
{
  //## begin CPCStateProcessControling::Delete%1044522168.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPCStateProcessControling::Delete%1044522168.body
}

void CPCStateProcessControling::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateProcessControling::Do%1045140118.body preserve=yes

	CCOSyncObjectPtr l_pSyncObjPtr = NULL;
	try
	{
		l_pSyncObjPtr = new CCOSyncObject();

		// Pointer to logic.
		CPCLogic *l_pLogic= GetpImplementation(p_pContext)->GetpLogic();
		ASSERT(l_pLogic != NULL);

		// Pointer to config.
		CPIPowerControlConfig *l_pConfig= GetpImplementation(p_pContext)->GetpConfig();
		ASSERT(l_pLogic != NULL);

		// Pointer to profile.
		CPIPowerControlProfile *l_pProfile= GetpImplementation(p_pContext)->GetpProfile();
		ASSERT(l_pProfile != NULL);

		DWORD l_dwTicks = GetTickCount() - l_pLogic->GetdwTimeBase();
        CString l_sTrace;

		double l_dActPower = (double)l_pLogic->ActPower() / 1E3;
		double l_dActCurrent = (double)l_pLogic->ActCurrent() / 1E3;
		double l_dActVoltage = (double)l_pLogic->ActVoltage() / 1E3;

		double l_dPowerErrorLLimit = (double)l_pProfile->GetuiPowerErrorLLimit() / 1E3;
		double l_dPowerErrorULimit = (double)l_pProfile->GetuiPowerErrorULimit() / 1E3;

		// Error lower limit.
		if (l_dActPower < l_dPowerErrorLLimit)
		{
			l_sTrace.Format(_T("Error power lower limit. Exeption in file: %s line: %d \n"),_T(__FILE__), __LINE__);
			CO_TRACE(PC_ID, l_sTrace);
			throw new XPCExceptionErrorInterrupted(PC_ID, IDE_PC_INTERRUPTED, _T(__FILE__), __LINE__, 0);
		}

		// Error upper limit.
		if (l_dActPower > l_dPowerErrorULimit)
		{
			l_sTrace.Format(_T("Error power upper limit. Exeption in file: %s line: %d \n"),_T(__FILE__), __LINE__);
			CO_TRACE(PC_ID, l_sTrace);
			throw new XPCExceptionErrorShorted(PC_ID, IDE_PC_SHORTED, _T(__FILE__), __LINE__, 0);
		}

		// Controll /////////////////////////////////
		double l_dPowerNominal	= l_pProfile->GetuiPowerNominal();
		// convert [mW] --> [W]
		l_dPowerNominal /= 1E3;

		double l_dPidOut = GetpImplementation(p_pContext)->GetpPID()->Do(l_dPowerNominal , l_dActPower);
		l_pLogic->SetDAC((DWORD)l_dPidOut);

		DWORD l_dwSamplingTime = l_pConfig->GetuiPid_Ts();
		
		// wait...
		if (p_pContext->WaitOnActionDone(l_pSyncObjPtr, CO_WAKE_MASK_DEFAULT, l_dwSamplingTime) == eIRTimeout)
			p_pContext->ChangeState(this);
		//else
		// do nothing state change made in commands stop and connection lost
		// p_pContext->ChangeState(CPCStateIdleStandBy::GetInstance());

	}
	catch(...)
	{
		throw;
	}

  //## end CPCStateProcessControling::Do%1045140118.body
}

// Additional Declarations
  //## begin CPCStateProcessControling%3EED76CC0714.declarations preserve=yes
  //## end CPCStateProcessControling%3EED76CC0714.declarations

// Class CPCStateProcess 

CPCStateProcess::CPCStateProcess()
  //## begin CPCStateProcess::CPCStateProcess%.hasinit preserve=no
  //## end CPCStateProcess::CPCStateProcess%.hasinit
  //## begin CPCStateProcess::CPCStateProcess%.initialization preserve=yes
  //## end CPCStateProcess::CPCStateProcess%.initialization
{
  //## begin CPCStateProcess::CPCStateProcess%.body preserve=yes
  //## end CPCStateProcess::CPCStateProcess%.body
}


CPCStateProcess::~CPCStateProcess()
{
  //## begin CPCStateProcess::~CPCStateProcess%.body preserve=yes
  //## end CPCStateProcess::~CPCStateProcess%.body
}



//## Other Operations (implementation)
void CPCStateProcess::Stop (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateProcess::Stop%1077117394.body preserve=yes
	p_pContext->ChangeState(CPCStateIdleStandBy::GetInstance());
  //## end CPCStateProcess::Stop%1077117394.body
}

void CPCStateProcess::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateProcess::CleanupInitialize%1077117395.body preserve=yes
	p_pContext->ChangeState(CPCStateIdlePowerOff::GetInstance());
  //## end CPCStateProcess::CleanupInitialize%1077117395.body
}

void CPCStateProcess::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateProcess::ConnectionLost%1077117396.body preserve=yes
	p_pContext->ChangeState(CPCStateNotConnected::GetInstance());
  //## end CPCStateProcess::ConnectionLost%1077117396.body
}

void CPCStateProcess::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateProcess::Shutdown%1183379134.body preserve=yes
	GetpImplementation(p_pContext)->GetpLogic()->PowerOff();
	p_pContext->ChangeState(CPCStateCreated::GetInstance());
  //## end CPCStateProcess::Shutdown%1183379134.body
}

// Additional Declarations
  //## begin CPCStateProcess%4033805B0086.declarations preserve=yes
  //## end CPCStateProcess%4033805B0086.declarations

// Class CPCStateProcessStarting 

//## begin CPCStateProcessStarting::pInstance%4033817400E5.role preserve=no  public: static CPCStateProcessStarting {1..1 -> 1..1RFHN}
CPCStateProcessStarting *CPCStateProcessStarting::m_pInstance;
//## end CPCStateProcessStarting::pInstance%4033817400E5.role


CPCStateProcessStarting::CPCStateProcessStarting()
  //## begin CPCStateProcessStarting::CPCStateProcessStarting%.hasinit preserve=no
  //## end CPCStateProcessStarting::CPCStateProcessStarting%.hasinit
  //## begin CPCStateProcessStarting::CPCStateProcessStarting%.initialization preserve=yes
  //## end CPCStateProcessStarting::CPCStateProcessStarting%.initialization
{
  //## begin CPCStateProcessStarting::CPCStateProcessStarting%.body preserve=yes
  //## end CPCStateProcessStarting::CPCStateProcessStarting%.body
}


CPCStateProcessStarting::~CPCStateProcessStarting()
{
  //## begin CPCStateProcessStarting::~CPCStateProcessStarting%.body preserve=yes
  //## end CPCStateProcessStarting::~CPCStateProcessStarting%.body
}



//## Other Operations (implementation)
void CPCStateProcessStarting::Create ()
{
  //## begin CPCStateProcessStarting::Create%1077117397.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateProcessStarting();
  //## end CPCStateProcessStarting::Create%1077117397.body
}

CPCStateProcessStarting* CPCStateProcessStarting::GetInstance ()
{
  //## begin CPCStateProcessStarting::GetInstance%1077117398.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateProcessStarting::GetInstance%1077117398.body
}

void CPCStateProcessStarting::Delete ()
{
  //## begin CPCStateProcessStarting::Delete%1077117399.body preserve=yes
	if(m_pInstance != NULL)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPCStateProcessStarting::Delete%1077117399.body
}

void CPCStateProcessStarting::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateProcessStarting::Do%1077117400.body preserve=yes
	// Sync object smart pointer.
	CCOSyncObjectPtr l_SyncObjectPtr = NULL;

	try
	{
		double l_dPowerNominal = GetpImplementation(p_pContext)->GetpProfile()->GetuiPowerNominal(); 
		l_dPowerNominal /= 1E3;

		UINT l_uiNominalVoltageULimit = GetpImplementation(p_pContext)->GetpConfig()->GetuiNominalVoltageULimit();

		bool l_bStop = false;
		l_SyncObjectPtr = new CCOSyncObject;
		UINT l_uiTimeOut = GetpImplementation(p_pContext)->GetpConfig()->GetuiSoftStartDeltaTime();
		UINT l_uiDeltaVoltage = GetpImplementation(p_pContext)->GetpConfig()->GetuiSoftStartDeltaVoltage();

		UINT l_uiVLampDesired = CHIInterface::GetInstance()->GetStaticObjID(eHILmpStandByVoltage);
		double l_dActPower = 0;

		do
		{
			l_dActPower = GetpImplementation(p_pContext)->GetpLogic()->ActPower();
			l_dActPower /= 1E3;

			l_uiVLampDesired += l_uiDeltaVoltage;
			GetpImplementation(p_pContext)->GetpLogic()->SetVoltage(l_uiVLampDesired);

			// wait...
			ECOInterruptReason eReason = p_pContext->WaitOnActionDone(l_SyncObjectPtr, CO_WAKE_MASK_DEFAULT, l_uiTimeOut);

			switch(eReason)
			{
			case eIRTimeout:
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

		}while (!l_bStop && (l_dActPower < l_dPowerNominal) && (l_uiVLampDesired < l_uiNominalVoltageULimit));

		if (!l_bStop)
		{
			// Preset pid 
			double l_dI = l_uiVLampDesired * 1E-3;
			GetpImplementation(p_pContext)->GetpPID()->PresetI1(l_dI);

			p_pContext->ChangeState(CPCStateProcessSwinging::GetInstance());
		}
	}
	catch(...) 
	{
		throw;
	}
  //## end CPCStateProcessStarting::Do%1077117400.body
}

// Additional Declarations
  //## begin CPCStateProcessStarting%4033806E01ED.declarations preserve=yes
  //## end CPCStateProcessStarting%4033806E01ED.declarations

// Class CPCStateProcessSwinging 

//## begin CPCStateProcessSwinging::pInstance%4035CD000364.role preserve=no  public: static CPCStateProcessSwinging {1..1 -> 1..1RFHN}
CPCStateProcessSwinging *CPCStateProcessSwinging::m_pInstance;
//## end CPCStateProcessSwinging::pInstance%4035CD000364.role


CPCStateProcessSwinging::CPCStateProcessSwinging()
  //## begin CPCStateProcessSwinging::CPCStateProcessSwinging%.hasinit preserve=no
  //## end CPCStateProcessSwinging::CPCStateProcessSwinging%.hasinit
  //## begin CPCStateProcessSwinging::CPCStateProcessSwinging%.initialization preserve=yes
  //## end CPCStateProcessSwinging::CPCStateProcessSwinging%.initialization
{
  //## begin CPCStateProcessSwinging::CPCStateProcessSwinging%.body preserve=yes
  //## end CPCStateProcessSwinging::CPCStateProcessSwinging%.body
}


CPCStateProcessSwinging::~CPCStateProcessSwinging()
{
  //## begin CPCStateProcessSwinging::~CPCStateProcessSwinging%.body preserve=yes
  //## end CPCStateProcessSwinging::~CPCStateProcessSwinging%.body
}



//## Other Operations (implementation)
void CPCStateProcessSwinging::Create ()
{
  //## begin CPCStateProcessSwinging::Create%1077262878.body preserve=yes
	ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateProcessSwinging();
  //## end CPCStateProcessSwinging::Create%1077262878.body
}

CPCStateProcessSwinging* CPCStateProcessSwinging::GetInstance ()
{
  //## begin CPCStateProcessSwinging::GetInstance%1077262879.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateProcessSwinging::GetInstance%1077262879.body
}

void CPCStateProcessSwinging::Delete ()
{
  //## begin CPCStateProcessSwinging::Delete%1077262880.body preserve=yes
	if(m_pInstance != NULL)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CPCStateProcessSwinging::Delete%1077262880.body
}

void CPCStateProcessSwinging::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateProcessSwinging::Do%1077262881.body preserve=yes
	CCOSyncObject* l_pStartSyncObj = NULL;

	// Singal the start sync object
	l_pStartSyncObj = GetpImplementation(p_pContext)->GetpLogic()->GetpStartSyncObject();
	l_pStartSyncObj->SignalCompletion();	
	GetpImplementation(p_pContext)->GetpLogic()->SetpStartSyncObject(NULL);

	// change state
	p_pContext->ChangeState(CPCStateProcessControling::GetInstance());

  //## end CPCStateProcessSwinging::Do%1077262881.body
}

// Additional Declarations
  //## begin CPCStateProcessSwinging%4035CCCD03C1.declarations preserve=yes
  //## end CPCStateProcessSwinging%4035CCCD03C1.declarations

//## begin module%3EED769F038C.epilog preserve=yes
//## end module%3EED769F038C.epilog
