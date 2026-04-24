//## begin module%3E6DE60F0280.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E6DE60F0280.cm

//## begin module%3E6DE60F0280.cp preserve=no
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
//## end module%3E6DE60F0280.cp

//## Module: EBMCdata%3E6DE60F0280; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCdata.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E6DE60F0280.additionalIncludes preserve=no
//## end module%3E6DE60F0280.additionalIncludes

//## begin module%3E6DE60F0280.includes preserve=yes
//## end module%3E6DE60F0280.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBCOimct
#include "EBCOimct.h"
// EBMCimpl
#include "EBMCimpl.h"
// EBMCidnt
#include "EBMCidnt.h"
// EBMCexcp
#include "EBMCexcp.h"
// EBMCsimu
#include "EBMCsimu.h"
// EBMCdata
#include "EBMCdata.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3E6DE60F0280.declarations preserve=no
//## end module%3E6DE60F0280.declarations

//## begin module%3E6DE60F0280.additionalDeclarations preserve=yes
//## end module%3E6DE60F0280.additionalDeclarations


// Class CMCStateDataAcquistionReady 

//## begin CMCStateDataAcquistionReady::pInstance%3E6DDCB101D5.role preserve=no  public: static CMCStateDataAcquistionReady {1..1 -> 1..1RFHN}
CMCStateDataAcquistionReady *CMCStateDataAcquistionReady::m_pInstance = NULL;
//## end CMCStateDataAcquistionReady::pInstance%3E6DDCB101D5.role


CMCStateDataAcquistionReady::CMCStateDataAcquistionReady()
  //## begin CMCStateDataAcquistionReady::CMCStateDataAcquistionReady%.hasinit preserve=no
  //## end CMCStateDataAcquistionReady::CMCStateDataAcquistionReady%.hasinit
  //## begin CMCStateDataAcquistionReady::CMCStateDataAcquistionReady%.initialization preserve=yes
  //## end CMCStateDataAcquistionReady::CMCStateDataAcquistionReady%.initialization
{
  //## begin CMCStateDataAcquistionReady::CMCStateDataAcquistionReady%.body preserve=yes
  //## end CMCStateDataAcquistionReady::CMCStateDataAcquistionReady%.body
}


CMCStateDataAcquistionReady::~CMCStateDataAcquistionReady()
{
  //## begin CMCStateDataAcquistionReady::~CMCStateDataAcquistionReady%.body preserve=yes
  //## end CMCStateDataAcquistionReady::~CMCStateDataAcquistionReady%.body
}



//## Other Operations (implementation)
void CMCStateDataAcquistionReady::Delete ()
{
  //## begin CMCStateDataAcquistionReady::Delete%1047364730.body preserve=yes
  if(m_pInstance)
    delete m_pInstance;
  m_pInstance = NULL;
  //## end CMCStateDataAcquistionReady::Delete%1047364730.body
}

void CMCStateDataAcquistionReady::Create ()
{
  //## begin CMCStateDataAcquistionReady::Create%1047364731.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CMCStateDataAcquistionReady();
  //## end CMCStateDataAcquistionReady::Create%1047364731.body
}

CMCStateDataAcquistionReady* CMCStateDataAcquistionReady::GetInstance ()
{
  //## begin CMCStateDataAcquistionReady::GetInstance%1047364732.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CMCStateDataAcquistionReady::GetInstance%1047364732.body
}

void CMCStateDataAcquistionReady::GetDataPackage (ICOStateMachineContext* p_pContext, CPISyncObjDataPackage* p_pClientSyncObj)
{
  //## begin CMCStateDataAcquistionReady::GetDataPackage%1047364720.body preserve=yes
  CO_TRACE(MC_ID, _T("CMCStateDataAcquistionReady::GetDataPackage() - Begin"));

  p_pContext->GetAction(IDA_GETDATAPACKAGE)->SetpClientSyncObj(p_pClientSyncObj);
  p_pContext->ChangeState(CMCStateGetDataPackage::GetInstance(), p_pContext->GetAction(IDA_GETDATAPACKAGE));

  CO_TRACE(MC_ID, _T("CMCStateDataAcquistionReady::GetDataPackage() - End"));
  //## end CMCStateDataAcquistionReady::GetDataPackage%1047364720.body
}

// Additional Declarations
  //## begin CMCStateDataAcquistionReady%3E6DDBF60261.declarations preserve=yes
  //## end CMCStateDataAcquistionReady%3E6DDBF60261.declarations

// Class CMCStateGetDataPackage 

//## begin CMCStateGetDataPackage::pInstance%3E6DDCBA0109.role preserve=no  public: static CMCStateGetDataPackage {1..1 -> RFHN}
CMCStateGetDataPackage *CMCStateGetDataPackage::m_pInstance = NULL;
//## end CMCStateGetDataPackage::pInstance%3E6DDCBA0109.role


CMCStateGetDataPackage::CMCStateGetDataPackage()
  //## begin CMCStateGetDataPackage::CMCStateGetDataPackage%.hasinit preserve=no
  //## end CMCStateGetDataPackage::CMCStateGetDataPackage%.hasinit
  //## begin CMCStateGetDataPackage::CMCStateGetDataPackage%.initialization preserve=yes
  //## end CMCStateGetDataPackage::CMCStateGetDataPackage%.initialization
{
  //## begin CMCStateGetDataPackage::CMCStateGetDataPackage%.body preserve=yes
  //## end CMCStateGetDataPackage::CMCStateGetDataPackage%.body
}


CMCStateGetDataPackage::~CMCStateGetDataPackage()
{
  //## begin CMCStateGetDataPackage::~CMCStateGetDataPackage%.body preserve=yes
  //## end CMCStateGetDataPackage::~CMCStateGetDataPackage%.body
}



//## Other Operations (implementation)
void CMCStateGetDataPackage::Delete ()
{
  //## begin CMCStateGetDataPackage::Delete%1047364733.body preserve=yes
  if(m_pInstance)
    delete m_pInstance;
  m_pInstance = NULL;
  //## end CMCStateGetDataPackage::Delete%1047364733.body
}

void CMCStateGetDataPackage::Create ()
{
  //## begin CMCStateGetDataPackage::Create%1047364734.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CMCStateGetDataPackage();
  //## end CMCStateGetDataPackage::Create%1047364734.body
}

CMCStateGetDataPackage* CMCStateGetDataPackage::GetInstance ()
{
  //## begin CMCStateGetDataPackage::GetInstance%1047364735.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CMCStateGetDataPackage::GetInstance%1047364735.body
}

void CMCStateGetDataPackage::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateGetDataPackage::Do%1047390944.body preserve=yes
  CPISyncObjDataPackage* l_pSyncObj = dynamic_cast<CPISyncObjDataPackage*>(p_pContext->GetAction(IDA_GETDATAPACKAGE)->GetpServerSyncObj());
  ASSERT(l_pSyncObj != NULL);

  try
  {
    switch(p_pContext->WaitOnActionDone(l_pSyncObj))
    {
      case eIRActionsDone:
        p_pContext->GetAction(IDA_GETDATAPACKAGE)->Done();
        p_pContext->ChangeState(CMCStateDataAcquistionReady::GetInstance());
        break;

      case eIRCmdHigh:
        break;
      
      default:
       	throw new XMCExceptionError(MC_ID, IDE_MC_GET_DATA_PACKAGE_ERROR, _T(__FILE__), __LINE__, 0);
        break;
    }
  }
  catch(...)
  {
    throw;
  }
  //## end CMCStateGetDataPackage::Do%1047390944.body
}

// Additional Declarations
  //## begin CMCStateGetDataPackage%3E6DDC0D03D8.declarations preserve=yes
  //## end CMCStateGetDataPackage%3E6DDC0D03D8.declarations

// Class CMCStateDataSimulationPrepare 

//## begin CMCStateDataSimulationPrepare::pInstance%3F9787420236.role preserve=no  public: static CMCStateDataSimulationPrepare {1..1 -> 1..1RFHN}
CMCStateDataSimulationPrepare *CMCStateDataSimulationPrepare::m_pInstance = NULL;
//## end CMCStateDataSimulationPrepare::pInstance%3F9787420236.role


CMCStateDataSimulationPrepare::CMCStateDataSimulationPrepare()
  //## begin CMCStateDataSimulationPrepare::CMCStateDataSimulationPrepare%.hasinit preserve=no
  //## end CMCStateDataSimulationPrepare::CMCStateDataSimulationPrepare%.hasinit
  //## begin CMCStateDataSimulationPrepare::CMCStateDataSimulationPrepare%.initialization preserve=yes
  //## end CMCStateDataSimulationPrepare::CMCStateDataSimulationPrepare%.initialization
{
  //## begin CMCStateDataSimulationPrepare::CMCStateDataSimulationPrepare%.body preserve=yes
  //## end CMCStateDataSimulationPrepare::CMCStateDataSimulationPrepare%.body
}


CMCStateDataSimulationPrepare::~CMCStateDataSimulationPrepare()
{
  //## begin CMCStateDataSimulationPrepare::~CMCStateDataSimulationPrepare%.body preserve=yes
  //## end CMCStateDataSimulationPrepare::~CMCStateDataSimulationPrepare%.body
}



//## Other Operations (implementation)
void CMCStateDataSimulationPrepare::Delete ()
{
  //## begin CMCStateDataSimulationPrepare::Delete%1066894463.body preserve=yes
    delete m_pInstance;
    m_pInstance = NULL;
  //## end CMCStateDataSimulationPrepare::Delete%1066894463.body
}

void CMCStateDataSimulationPrepare::Create ()
{
  //## begin CMCStateDataSimulationPrepare::Create%1066894464.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CMCStateDataSimulationPrepare();
  //## end CMCStateDataSimulationPrepare::Create%1066894464.body
}

CMCStateDataSimulationPrepare* CMCStateDataSimulationPrepare::GetInstance ()
{
  //## begin CMCStateDataSimulationPrepare::GetInstance%1066894465.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CMCStateDataSimulationPrepare::GetInstance%1066894465.body
}

void CMCStateDataSimulationPrepare::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateDataSimulationPrepare::Do%1066894466.body preserve=yes
    GetpContext(p_pContext)->GetpCtrlSimulation()->Start();
    p_pContext->ChangeState(CMCStateDataSimulationReady::GetInstance());
  //## end CMCStateDataSimulationPrepare::Do%1066894466.body
}

// Additional Declarations
  //## begin CMCStateDataSimulationPrepare%3F9786DF0301.declarations preserve=yes
  //## end CMCStateDataSimulationPrepare%3F9786DF0301.declarations

// Class CMCStateDataSimulationReady 

//## begin CMCStateDataSimulationReady::pInstance%3F979AF801D9.role preserve=no  public: static CMCStateDataSimulationReady {1..1 -> 1..1RFHN}
CMCStateDataSimulationReady *CMCStateDataSimulationReady::m_pInstance = NULL;
//## end CMCStateDataSimulationReady::pInstance%3F979AF801D9.role


CMCStateDataSimulationReady::CMCStateDataSimulationReady()
  //## begin CMCStateDataSimulationReady::CMCStateDataSimulationReady%.hasinit preserve=no
  //## end CMCStateDataSimulationReady::CMCStateDataSimulationReady%.hasinit
  //## begin CMCStateDataSimulationReady::CMCStateDataSimulationReady%.initialization preserve=yes
  //## end CMCStateDataSimulationReady::CMCStateDataSimulationReady%.initialization
{
  //## begin CMCStateDataSimulationReady::CMCStateDataSimulationReady%.body preserve=yes
  //## end CMCStateDataSimulationReady::CMCStateDataSimulationReady%.body
}


CMCStateDataSimulationReady::~CMCStateDataSimulationReady()
{
  //## begin CMCStateDataSimulationReady::~CMCStateDataSimulationReady%.body preserve=yes
  //## end CMCStateDataSimulationReady::~CMCStateDataSimulationReady%.body
}



//## Other Operations (implementation)
void CMCStateDataSimulationReady::Delete ()
{
  //## begin CMCStateDataSimulationReady::Delete%1066894468.body preserve=yes
    delete m_pInstance;
    m_pInstance = NULL;
  //## end CMCStateDataSimulationReady::Delete%1066894468.body
}

void CMCStateDataSimulationReady::Create ()
{
  //## begin CMCStateDataSimulationReady::Create%1066894469.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CMCStateDataSimulationReady();
  //## end CMCStateDataSimulationReady::Create%1066894469.body
}

CMCStateDataSimulationReady* CMCStateDataSimulationReady::GetInstance ()
{
  //## begin CMCStateDataSimulationReady::GetInstance%1066894470.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CMCStateDataSimulationReady::GetInstance%1066894470.body
}

void CMCStateDataSimulationReady::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateDataSimulationReady::Do%1066894471.body preserve=yes
  //## end CMCStateDataSimulationReady::Do%1066894471.body
}

void CMCStateDataSimulationReady::GetDataPackage (ICOStateMachineContext* p_pContext, CPISyncObjDataPackage* p_pClientSyncObj)
{
  //## begin CMCStateDataSimulationReady::GetDataPackage%1066894472.body preserve=yes
    CPIMeasurementChannelDataPackage* l_pDataPackage = GetpContext(p_pContext)->GetpCtrlSimulation()->GetDataPackage();
    p_pClientSyncObj->SetValue(l_pDataPackage);
    p_pClientSyncObj->SignalCompletion();
  //## end CMCStateDataSimulationReady::GetDataPackage%1066894472.body
}

// Additional Declarations
  //## begin CMCStateDataSimulationReady%3F979AAD036E.declarations preserve=yes
  //## end CMCStateDataSimulationReady%3F979AAD036E.declarations

// Class CMCStateData 

CMCStateData::CMCStateData()
  //## begin CMCStateData::CMCStateData%.hasinit preserve=no
  //## end CMCStateData::CMCStateData%.hasinit
  //## begin CMCStateData::CMCStateData%.initialization preserve=yes
  //## end CMCStateData::CMCStateData%.initialization
{
  //## begin CMCStateData::CMCStateData%.body preserve=yes
  //## end CMCStateData::CMCStateData%.body
}


CMCStateData::~CMCStateData()
{
  //## begin CMCStateData::~CMCStateData%.body preserve=yes
  //## end CMCStateData::~CMCStateData%.body
}



//## Other Operations (implementation)
void CMCStateData::Stop (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateData::Stop%1047364719.body preserve=yes
    if (GetpContext(p_pContext)->GetbHWPresent())
    {
        IHIInterface::GetInstance()->MCDataAcquisitionStop();
    }
  
    p_pContext->ChangeState(CMCStateInitialized::GetInstance());
  //## end CMCStateData::Stop%1047364719.body
}

void CMCStateData::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateData::CleanupInitialize%1080293047.body preserve=yes
  try
  {
    Stop(p_pContext);
  }
  catch(...)
  {
    p_pContext->ChangeState(CMCStateInitialized::GetInstance());
  }
  //## end CMCStateData::CleanupInitialize%1080293047.body
}

void CMCStateData::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateData::ConnectionLost%1083826160.body preserve=yes
    if (GetpContext(p_pContext)->GetbHWPresent())
    {
        IHIInterface::GetInstance()->MCDataAcquisitionStop();
    }

    CMCStateProcess::ConnectionLost(p_pContext);
  //## end CMCStateData::ConnectionLost%1083826160.body
}

// Additional Declarations
  //## begin CMCStateData%3E6DDA46036B.declarations preserve=yes
  //## end CMCStateData%3E6DDA46036B.declarations

//## begin module%3E6DE60F0280.epilog preserve=yes
//## end module%3E6DE60F0280.epilog
