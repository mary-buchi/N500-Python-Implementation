//## begin module%3E38FDE00242.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E38FDE00242.cm

//## begin module%3E38FDE00242.cp preserve=no
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
//## end module%3E38FDE00242.cp

//## Module: EBWCproc%3E38FDE00242; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCproc.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E38FDE00242.additionalIncludes preserve=no
//## end module%3E38FDE00242.additionalIncludes

//## begin module%3E38FDE00242.includes preserve=yes
//## end module%3E38FDE00242.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBCOimct
#include "EBCOimct.h"
// EBWCemst
#include "EBWCemst.h"
// EBWCexcp
#include "EBWCexcp.h"
// EBWCconn
#include "EBWCconn.h"
// EBWCacti
#include "EBWCacti.h"
// EBWCproc
#include "EBWCproc.h"
// EBWCinit
#include "EBWCinit.h"
// EBWCconf
#include "EBWCconf.h"
// EBWCidle
#include "EBWCidle.h"
// EBWCimpl
#include "EBWCimpl.h"
// EBWCidnt
#include "EBWCidnt.h"
// EBHIintf
#include "EBHIintf.h"
// EBHIexcp
#include "EBHIexcp.h"
//## begin module%3E38FDE00242.declarations preserve=no
//## end module%3E38FDE00242.declarations

//## begin module%3E38FDE00242.additionalDeclarations preserve=yes
//## end module%3E38FDE00242.additionalDeclarations


// Class CWCStateProcess 

CWCStateProcess::CWCStateProcess()
  //## begin CWCStateProcess::CWCStateProcess%.hasinit preserve=no
  //## end CWCStateProcess::CWCStateProcess%.hasinit
  //## begin CWCStateProcess::CWCStateProcess%.initialization preserve=yes
  //## end CWCStateProcess::CWCStateProcess%.initialization
{
  //## begin CWCStateProcess::CWCStateProcess%.body preserve=yes
  //## end CWCStateProcess::CWCStateProcess%.body
}


CWCStateProcess::~CWCStateProcess()
{
  //## begin CWCStateProcess::~CWCStateProcess%.body preserve=yes
  //## end CWCStateProcess::~CWCStateProcess%.body
}



//## Other Operations (implementation)
void CWCStateProcess::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcess::Shutdown%1043917003.body preserve=yes
  try
  {
    CWCStateConfig::SetbWCProfileExist(FALSE);
    CWCStateInitialize::SetbWCInitialized(FALSE);
	CWCStateConfig::SetpConfig(NULL);
	CWCStateConfigProfile::GetInstance()->SetpProfile(NULL);
    IHIInterface::GetInstance()->WCEmergencyStop();
    p_pContext->ChangeState(CWCStateCreated::GetInstance());
  }
  catch(...)
  {
    throw;
  }
  //## end CWCStateProcess::Shutdown%1043917003.body
}

void CWCStateProcess::CleanupStop (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcess::CleanupStop%1053065382.body preserve=yes
  CleanupInitialize(p_pContext);
  //## end CWCStateProcess::CleanupStop%1053065382.body
}

void CWCStateProcess::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcess::CleanupInitialize%1053065383.body preserve=yes
  try
  {
    CWCStateInitialize::SetbWCInitialized(FALSE);
    CWCStateInitialize::SetbWCStartCmd(FALSE);
    IHIInterface::GetInstance()->WCEmergencyStop();
    p_pContext->ChangeState(CWCStateConfigInitDAC::GetInstance());
  }
  catch(...)
  {
    p_pContext->ChangeState(CWCStateConfigInitDAC::GetInstance());
  }
  //## end CWCStateProcess::CleanupInitialize%1053065383.body
}

void CWCStateProcess::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcess::ConnectionLost%1063260203.body preserve=yes
  try
  {
    CWCStateInitialize::SetbWCInitialized(FALSE);
    IHIInterface::GetInstance()->WCEmergencyStop();
  	p_pContext->ChangeState(CWCStateNotConnected::GetInstance());
  }
  catch(...)
  {
  	p_pContext->ChangeState(CWCStateNotConnected::GetInstance());
  }
  //## end CWCStateProcess::ConnectionLost%1063260203.body
}

// Additional Declarations
  //## begin CWCStateProcess%3E38FD340232.declarations preserve=yes
  //## end CWCStateProcess%3E38FD340232.declarations

// Class CWCStateProcMeasuring 




//## begin CWCStateProcMeasuring::pInstance%3E39001900CC.role preserve=no  public: static CWCStateProcMeasuring {1..1 -> 1..1RFHN}
CWCStateProcMeasuring *CWCStateProcMeasuring::m_pInstance;
//## end CWCStateProcMeasuring::pInstance%3E39001900CC.role


CWCStateProcMeasuring::CWCStateProcMeasuring()
  //## begin CWCStateProcMeasuring::CWCStateProcMeasuring%.hasinit preserve=no
      : m_bIsStopCmd(false), m_bIsShutdownCmd(false), m_bIsConnectionLostCmd(false)
  //## end CWCStateProcMeasuring::CWCStateProcMeasuring%.hasinit
  //## begin CWCStateProcMeasuring::CWCStateProcMeasuring%.initialization preserve=yes
  //## end CWCStateProcMeasuring::CWCStateProcMeasuring%.initialization
{
  //## begin CWCStateProcMeasuring::CWCStateProcMeasuring%.body preserve=yes
  //## end CWCStateProcMeasuring::CWCStateProcMeasuring%.body
}


CWCStateProcMeasuring::~CWCStateProcMeasuring()
{
  //## begin CWCStateProcMeasuring::~CWCStateProcMeasuring%.body preserve=yes
  //## end CWCStateProcMeasuring::~CWCStateProcMeasuring%.body
}



//## Other Operations (implementation)
void CWCStateProcMeasuring::Create ()
{
  //## begin CWCStateProcMeasuring::Create%1043917026.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CWCStateProcMeasuring();
  //## end CWCStateProcMeasuring::Create%1043917026.body
}

void CWCStateProcMeasuring::Delete ()
{
  //## begin CWCStateProcMeasuring::Delete%1043917027.body preserve=yes
    if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CWCStateProcMeasuring::Delete%1043917027.body
}

CWCStateProcMeasuring* CWCStateProcMeasuring::GetInstance ()
{
  //## begin CWCStateProcMeasuring::GetInstance%1043917028.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CWCStateProcMeasuring::GetInstance%1043917028.body
}

void CWCStateProcMeasuring::Stop (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcMeasuring::Stop%1043996013.body preserve=yes
    m_bIsStopCmd = true;
  //## end CWCStateProcMeasuring::Stop%1043996013.body
}

void CWCStateProcMeasuring::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcMeasuring::Shutdown%1165065052.body preserve=yes
	m_bIsShutdownCmd = true;
  //## end CWCStateProcMeasuring::Shutdown%1165065052.body
}

void CWCStateProcMeasuring::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcMeasuring::ConnectionLost%1165065054.body preserve=yes
	m_bIsConnectionLostCmd = true;
  //## end CWCStateProcMeasuring::ConnectionLost%1165065054.body
}

void CWCStateProcMeasuring::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcMeasuring::Do%1052978394.body preserve=yes
    DWORD l_dwErrorCode = 0;
    try
    {
        m_bIsStopCmd = false;
		m_bIsShutdownCmd = false;
		m_bIsConnectionLostCmd = false;

        CCOSyncObject* l_pSyncObj = p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->GetpServerSyncObj();
        switch(p_pContext->WaitOnActionDone(l_pSyncObj))
        {
          case eIRActionsDone:
	        p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->Done();

	        // wedge control exception
	        l_dwErrorCode = IHIInterface::GetInstance()->GetHWExceptionErrorCode();
	        GetpContext(p_pContext)->GetpSyncExcObj()->SetValue(l_dwErrorCode);
	        GetpContext(p_pContext)->GetpSyncExcObj()->AttachException(new XWCExceptionError(WC_ID, IDE_WC_WEDGEDRIVE_ERROR, _T(__FILE__), __LINE__, l_dwErrorCode));

	        XCO_CLEANUP_INIT(WC_ID);
	        break;

          case eIRCmdAboveNormal:
          case eIRCmdHigh:
	        if (m_bIsStopCmd)
	        {
		        p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->Done();
		        p_pContext->ChangeState(CWCStateProcFollowUpMeasuring::GetInstance(), p_pContext->GetAction(IDA_MEASURING_EXCEPTION));

		        m_bIsStopCmd = false;
	        }
	        else if (m_bIsShutdownCmd)
	        {
				p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->Done();

				CWCStateProcess::Shutdown(p_pContext);
	        }
			else if (m_bIsConnectionLostCmd)
			{
				p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->Done();

				CWCStateProcess::ConnectionLost(p_pContext);
			}
	        break;

          default:
	        ASSERT(FALSE);
	        break;

        }
    }
    catch(XHIHardwareExceptionError* p_pException)
    {
      p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->Cancel();

      // wedge control exception
      DWORD l_dwErrorCode = IHIInterface::GetInstance()->GetHWExceptionErrorCode();
      GetpContext(p_pContext)->GetpSyncExcObj()->SetValue(l_dwErrorCode);
      GetpContext(p_pContext)->GetpSyncExcObj()->AttachException(new XWCExceptionError(WC_ID, IDE_WC_WEDGEDRIVE_ERROR, _T(__FILE__), __LINE__, l_dwErrorCode));

      p_pException->Delete();
      XCO_CLEANUP_INIT(WC_ID);
    }

  //## end CWCStateProcMeasuring::Do%1052978394.body
}

// Additional Declarations
  //## begin CWCStateProcMeasuring%3E391A87002E.declarations preserve=yes
  //## end CWCStateProcMeasuring%3E391A87002E.declarations

// Class CWCStateProcFollowUpMeasuring 





//## begin CWCStateProcFollowUpMeasuring::pInstance%3E39246D035C.role preserve=no  public: static CWCStateProcFollowUpMeasuring {1..1 -> 1..1RFHN}
CWCStateProcFollowUpMeasuring *CWCStateProcFollowUpMeasuring::m_pInstance;
//## end CWCStateProcFollowUpMeasuring::pInstance%3E39246D035C.role


CWCStateProcFollowUpMeasuring::CWCStateProcFollowUpMeasuring()
  //## begin CWCStateProcFollowUpMeasuring::CWCStateProcFollowUpMeasuring%.hasinit preserve=no
      : m_bIsStartCmd(false), m_bIsStopCmd(false), m_bIsShutdownCmd(false), m_bIsConnectionLostCmd(false)
  //## end CWCStateProcFollowUpMeasuring::CWCStateProcFollowUpMeasuring%.hasinit
  //## begin CWCStateProcFollowUpMeasuring::CWCStateProcFollowUpMeasuring%.initialization preserve=yes
  //## end CWCStateProcFollowUpMeasuring::CWCStateProcFollowUpMeasuring%.initialization
{
  //## begin CWCStateProcFollowUpMeasuring::CWCStateProcFollowUpMeasuring%.body preserve=yes
  //## end CWCStateProcFollowUpMeasuring::CWCStateProcFollowUpMeasuring%.body
}


CWCStateProcFollowUpMeasuring::~CWCStateProcFollowUpMeasuring()
{
  //## begin CWCStateProcFollowUpMeasuring::~CWCStateProcFollowUpMeasuring%.body preserve=yes
  //## end CWCStateProcFollowUpMeasuring::~CWCStateProcFollowUpMeasuring%.body
}



//## Other Operations (implementation)
void CWCStateProcFollowUpMeasuring::Create ()
{
  //## begin CWCStateProcFollowUpMeasuring::Create%1043917029.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CWCStateProcFollowUpMeasuring();
  //## end CWCStateProcFollowUpMeasuring::Create%1043917029.body
}

void CWCStateProcFollowUpMeasuring::Delete ()
{
  //## begin CWCStateProcFollowUpMeasuring::Delete%1043917030.body preserve=yes
    if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CWCStateProcFollowUpMeasuring::Delete%1043917030.body
}

CWCStateProcFollowUpMeasuring* CWCStateProcFollowUpMeasuring::GetInstance ()
{
  //## begin CWCStateProcFollowUpMeasuring::GetInstance%1043917031.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CWCStateProcFollowUpMeasuring::GetInstance%1043917031.body
}

void CWCStateProcFollowUpMeasuring::Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pSyncStartObj, CCOSyncObjectInt* p_pSyncExcObj)
{
  //## begin CWCStateProcFollowUpMeasuring::Start%1100615761.body preserve=yes
    GetpContext(p_pContext)->SetpSyncStartObj(p_pSyncStartObj);
    GetpContext(p_pContext)->SetpSyncExcObj(p_pSyncExcObj);

    m_bIsStartCmd = true;
  //## end CWCStateProcFollowUpMeasuring::Start%1100615761.body
}

void CWCStateProcFollowUpMeasuring::Stop (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcFollowUpMeasuring::Stop%1043996015.body preserve=yes
    m_bIsStopCmd = true;
  //## end CWCStateProcFollowUpMeasuring::Stop%1043996015.body
}

void CWCStateProcFollowUpMeasuring::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcFollowUpMeasuring::Shutdown%1165065053.body preserve=yes
	m_bIsShutdownCmd = true;
  //## end CWCStateProcFollowUpMeasuring::Shutdown%1165065053.body
}

void CWCStateProcFollowUpMeasuring::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcFollowUpMeasuring::ConnectionLost%1165065055.body preserve=yes
	m_bIsConnectionLostCmd = true;
  //## end CWCStateProcFollowUpMeasuring::ConnectionLost%1165065055.body
}

void CWCStateProcFollowUpMeasuring::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcFollowUpMeasuring::Do%1053429958.body preserve=yes
	// start "follow up measuring timmer" -> [ms]
	try
	{
        m_bIsStartCmd = false;
        m_bIsStopCmd = false;
		m_bIsShutdownCmd = false;
		m_bIsConnectionLostCmd = false;

		// wedge drive EXCEPTION
		DWORD l_dwErrorCode = IHIInterface::GetInstance()->GetHWExceptionErrorCode();
		if (l_dwErrorCode != 0)
		{
		  GetpContext(p_pContext)->GetpSyncExcObj()->SetValue(l_dwErrorCode);
		  GetpContext(p_pContext)->GetpSyncExcObj()->AttachException(new XWCExceptionError(WC_ID, IDE_WC_WEDGEDRIVE_ERROR, _T(__FILE__), __LINE__, l_dwErrorCode));
		  XCO_CLEANUP_INIT(WC_ID);
		}

		if (CWCStateConfig::GetdwRunAfterTime() > 0)
		{
			// wedge drive EXCEPTION
			CCOSyncObject* l_pSyncObj = p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->GetpServerSyncObj();
			switch(p_pContext->WaitOnActionDone(l_pSyncObj, CO_WAKE_MASK_DEFAULT, CWCStateConfig::GetdwRunAfterTime()* 1000))
			{
			    case eIRActionsDone:
				    p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->Done();

				    // wedge control exception
				    l_dwErrorCode = IHIInterface::GetInstance()->GetHWExceptionErrorCode();
				    GetpContext(p_pContext)->GetpSyncExcObj()->SetValue(l_dwErrorCode);
				    GetpContext(p_pContext)->GetpSyncExcObj()->AttachException(new XWCExceptionError(WC_ID, IDE_WC_WEDGEDRIVE_ERROR, _T(__FILE__), __LINE__, l_dwErrorCode));

				    XCO_CLEANUP_INIT(WC_ID);
				    break;
   
			    case eIRCmdAboveNormal:
			    case eIRCmdHigh:
                    if (m_bIsStartCmd)
                    {
				        p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->Done();

                        p_pContext->ChangeState(CWCStateProcMeasuring::GetInstance(), p_pContext->GetAction(IDA_MEASURING_EXCEPTION));
                        GetpContext(p_pContext)->GetpSyncStartObj()->SignalCompletion();
                    }
                    else if (m_bIsStopCmd)
                    {
				        p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->Done();

                        CWCActionStopMeasuring* l_pAction = (CWCActionStopMeasuring*)p_pContext->GetAction(IDA_STOPPING);
                        l_pAction->SetdwStoppedEvent(CWCStateConfig::GetpConfig()->GetdwWCIdStoppedEvent());
                        p_pContext->ChangeState(CWCStateProcStopping::GetInstance(), l_pAction);
                    }
					else if (m_bIsShutdownCmd)
					{
				        p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->Done();

						CWCStateProcess::Shutdown(p_pContext);
					}
					else if (m_bIsConnectionLostCmd)
					{
						p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->Done();

						CWCStateProcess::ConnectionLost(p_pContext);
					}
				    break;

                case eIRTimeout:
                    {
				        p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->Done();

                        // follow up measuring time is up -> change state
                        CWCActionStopMeasuring* l_pAction = (CWCActionStopMeasuring*)p_pContext->GetAction(IDA_STOPPING);
                        l_pAction->SetdwStoppedEvent(CWCStateConfig::GetpConfig()->GetdwWCIdStoppedEvent());
                        p_pContext->ChangeState(CWCStateProcStopping::GetInstance(), l_pAction);
                    }
                    break;

			    default:
				    ASSERT(FALSE);
				    break;

			}
		}
		else
		{
			p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->Done();

			CWCActionStopMeasuring* l_pAction = (CWCActionStopMeasuring*)p_pContext->GetAction(IDA_STOPPING);
			l_pAction->SetdwStoppedEvent(CWCStateConfig::GetpConfig()->GetdwWCIdStoppedEvent());
			p_pContext->ChangeState(CWCStateProcStopping::GetInstance(), l_pAction);
		}
	}
	catch(XHIHardwareExceptionError* p_pException)
    {
		p_pContext->GetAction(IDA_MEASURING_EXCEPTION)->Cancel();

		// wedge control exception
		DWORD l_dwErrorCode = IHIInterface::GetInstance()->GetHWExceptionErrorCode();
		GetpContext(p_pContext)->GetpSyncExcObj()->SetValue(l_dwErrorCode);
		GetpContext(p_pContext)->GetpSyncExcObj()->AttachException(new XWCExceptionError(WC_ID, IDE_WC_WEDGEDRIVE_ERROR, _T(__FILE__), __LINE__, l_dwErrorCode));
		p_pException->Delete();

		XCO_CLEANUP_INIT(WC_ID);
	}
  //## end CWCStateProcFollowUpMeasuring::Do%1053429958.body
}

// Additional Declarations
  //## begin CWCStateProcFollowUpMeasuring%3E391A9E004E.declarations preserve=yes
  //## end CWCStateProcFollowUpMeasuring%3E391A9E004E.declarations

// Class CWCStateProcStopping 

//## begin CWCStateProcStopping::pInstance%3EC499030272.role preserve=no  public: static CWCStateProcStopping {1..1 -> 1..1RFHN}
CWCStateProcStopping *CWCStateProcStopping::m_pInstance;
//## end CWCStateProcStopping::pInstance%3EC499030272.role


CWCStateProcStopping::CWCStateProcStopping()
  //## begin CWCStateProcStopping::CWCStateProcStopping%.hasinit preserve=no
  //## end CWCStateProcStopping::CWCStateProcStopping%.hasinit
  //## begin CWCStateProcStopping::CWCStateProcStopping%.initialization preserve=yes
  //## end CWCStateProcStopping::CWCStateProcStopping%.initialization
{
  //## begin CWCStateProcStopping::CWCStateProcStopping%.body preserve=yes
  //## end CWCStateProcStopping::CWCStateProcStopping%.body
}


CWCStateProcStopping::~CWCStateProcStopping()
{
  //## begin CWCStateProcStopping::~CWCStateProcStopping%.body preserve=yes
  //## end CWCStateProcStopping::~CWCStateProcStopping%.body
}



//## Other Operations (implementation)
void CWCStateProcStopping::Create ()
{
  //## begin CWCStateProcStopping::Create%1053065368.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CWCStateProcStopping();
  //## end CWCStateProcStopping::Create%1053065368.body
}

void CWCStateProcStopping::Delete ()
{
  //## begin CWCStateProcStopping::Delete%1053065369.body preserve=yes
    if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CWCStateProcStopping::Delete%1053065369.body
}

CWCStateProcStopping* CWCStateProcStopping::GetInstance ()
{
  //## begin CWCStateProcStopping::GetInstance%1053065370.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CWCStateProcStopping::GetInstance%1053065370.body
}

void CWCStateProcStopping::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcStopping::Do%1053065371.body preserve=yes
  try
  {
    CCOSyncObject* l_pSyncObj = p_pContext->GetAction(IDA_STOPPING)->GetpServerSyncObj();
    
    switch(p_pContext->WaitOnActionDone(l_pSyncObj,CO_WAKE_MASK_DEFAULT,4000))
    {
      case eIRActionsDone:
        p_pContext->GetAction(IDA_STOPPING)->Done();
        p_pContext->ChangeState(CWCStateInitializeStopped::GetInstance());
        break;
      
      case eIRTimeout:
       	throw new XWCExceptionError(WC_ID, IDE_WC_STOPPING_ERROR, _T(__FILE__), __LINE__, 0);
        break;
      
      case eIRCmdAboveNormal:
      case eIRCmdHigh:
        p_pContext->GetAction(IDA_STOPPING)->Done();
        break;
      
      default:
       	throw new XWCExceptionError(WC_ID, IDE_WC_STOPPING_ERROR, _T(__FILE__), __LINE__, 0);
        break;
      
    }
  }
  catch(...)
  {
    throw;
  }
  //## end CWCStateProcStopping::Do%1053065371.body
}

// Additional Declarations
  //## begin CWCStateProcStopping%3EC4983B00DA.declarations preserve=yes
  //## end CWCStateProcStopping%3EC4983B00DA.declarations

// Class CWCStateProcStarting 

//## begin CWCStateProcStarting::pInstance%419A20F9010A.role preserve=no  public: static CWCStateProcStarting {1..1 -> 1..1RFHN}
CWCStateProcStarting *CWCStateProcStarting::m_pInstance = NULL;
//## end CWCStateProcStarting::pInstance%419A20F9010A.role


CWCStateProcStarting::CWCStateProcStarting()
  //## begin CWCStateProcStarting::CWCStateProcStarting%.hasinit preserve=no
  //## end CWCStateProcStarting::CWCStateProcStarting%.hasinit
  //## begin CWCStateProcStarting::CWCStateProcStarting%.initialization preserve=yes
  //## end CWCStateProcStarting::CWCStateProcStarting%.initialization
{
  //## begin CWCStateProcStarting::CWCStateProcStarting%.body preserve=yes
  //## end CWCStateProcStarting::CWCStateProcStarting%.body
}


CWCStateProcStarting::~CWCStateProcStarting()
{
  //## begin CWCStateProcStarting::~CWCStateProcStarting%.body preserve=yes
  //## end CWCStateProcStarting::~CWCStateProcStarting%.body
}



//## Other Operations (implementation)
void CWCStateProcStarting::Create ()
{
  //## begin CWCStateProcStarting::Create%1100615763.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CWCStateProcStarting();
  //## end CWCStateProcStarting::Create%1100615763.body
}

void CWCStateProcStarting::Delete ()
{
  //## begin CWCStateProcStarting::Delete%1100615764.body preserve=yes
    delete m_pInstance;
    m_pInstance = NULL;
  //## end CWCStateProcStarting::Delete%1100615764.body
}

CWCStateProcStarting* CWCStateProcStarting::GetInstance ()
{
  //## begin CWCStateProcStarting::GetInstance%1100615765.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CWCStateProcStarting::GetInstance%1100615765.body
}

void CWCStateProcStarting::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateProcStarting::Do%1100615766.body preserve=yes
    // start wedge drive
	IHIInterface::GetInstance()->WCStart();
  
	// wedge drive EXCEPTION
	DWORD l_dwErrorCode = IHIInterface::GetInstance()->GetHWExceptionErrorCode();
	if (l_dwErrorCode != 0)
	{
	  GetpContext(p_pContext)->GetpSyncExcObj()->SetValue(l_dwErrorCode);
	  GetpContext(p_pContext)->GetpSyncExcObj()->AttachException(new XWCExceptionError(WC_ID, IDE_WC_WEDGEDRIVE_ERROR, _T(__FILE__), __LINE__, l_dwErrorCode));
	  XCO_CLEANUP_INIT(WC_ID);
	}

    // signal started
    GetpContext(p_pContext)->GetpSyncStartObj()->SignalCompletion();

    CWCActionMeasuring* l_pAction = (CWCActionMeasuring*)p_pContext->GetAction(IDA_MEASURING_EXCEPTION);
    l_pAction->SetdwMeasuringExcEvent(CWCStateConfig::GetpConfig()->GetdwWCIdMeasuringExcEvent());
    p_pContext->ChangeState(CWCStateProcMeasuring::GetInstance(), l_pAction);
  //## end CWCStateProcStarting::Do%1100615766.body
}

// Additional Declarations
  //## begin CWCStateProcStarting%419A1C280387.declarations preserve=yes
  //## end CWCStateProcStarting%419A1C280387.declarations

//## begin module%3E38FDE00242.epilog preserve=yes
//## end module%3E38FDE00242.epilog
