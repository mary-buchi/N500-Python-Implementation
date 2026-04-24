//## begin module%3DA5DDFB00C3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA5DDFB00C3.cm

//## begin module%3DA5DDFB00C3.cp preserve=no
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
//## end module%3DA5DDFB00C3.cp

//## Module: EBSTimpl%3DA5DDFB00C3; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTimpl.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA5DDFB00C3.additionalIncludes preserve=no
//## end module%3DA5DDFB00C3.additionalIncludes

//## begin module%3DA5DDFB00C3.includes preserve=yes
//## end module%3DA5DDFB00C3.includes

// EBCOsync
#include "EBCOsync.h"
// EBSTlimit
#include "EBSTlimit.h"
// EBSTlogic
#include "EBSTlogic.h"
// EBPItype
#include "EBPItype.h"
// EBSTsten
#include "EBSTsten.h"
// EBSTimpl
#include "EBSTimpl.h"
// EBSTintf
#include "EBSTintf.h"
// EBSThwconn
#include "EBSThwconn.h"
// EBSTexcp
#include "EBSTexcp.h"


//## begin module%3DA5DDFB00C3.declarations preserve=no
//## end module%3DA5DDFB00C3.declarations

//## begin module%3DA5DDFB00C3.additionalDeclarations preserve=yes
//## end module%3DA5DDFB00C3.additionalDeclarations


// Class CSTStepperMotorImplementation 













CSTStepperMotorImplementation::CSTStepperMotorImplementation (CSTStepperMotorInterface* p_pInterface)
  //## begin CSTStepperMotorImplementation::CSTStepperMotorImplementation%1034272545.hasinit preserve=no
      : m_pLimitHandler(NULL), m_pPositionMachine(NULL), m_pHwConnection(NULL), m_pProfile(NULL), m_pConfig(NULL), m_pLogic(NULL), m_pHomeSyncObj(NULL), m_pStopSyncObj(NULL)
  //## end CSTStepperMotorImplementation::CSTStepperMotorImplementation%1034272545.hasinit
  //## begin CSTStepperMotorImplementation::CSTStepperMotorImplementation%1034272545.initialization preserve=yes
  , ICOAsyncImplementation(p_pInterface)
  //## end CSTStepperMotorImplementation::CSTStepperMotorImplementation%1034272545.initialization
{
  //## begin CSTStepperMotorImplementation::CSTStepperMotorImplementation%1034272545.body preserve=yes
  //## end CSTStepperMotorImplementation::CSTStepperMotorImplementation%1034272545.body
}


CSTStepperMotorImplementation::~CSTStepperMotorImplementation()
{
  //## begin CSTStepperMotorImplementation::~CSTStepperMotorImplementation%.body preserve=yes
	
	// Housekeeping.	
	if (m_pStateMachineEngine != NULL)
		delete m_pStateMachineEngine;
	m_pStateMachineEngine = NULL;

	if (m_pLimitHandler != NULL)
		delete m_pLimitHandler;
	m_pLimitHandler = NULL;

	if (m_pPositionMachine != NULL)
		delete m_pPositionMachine;
	m_pPositionMachine = NULL;

	if (m_pHwConnection != NULL)
		delete m_pHwConnection;
	m_pHwConnection = NULL;

	if (m_pLogic != NULL)
		delete m_pLogic;
	m_pLogic = NULL;

	if (m_pProfile != NULL)
		m_pProfile->ReleaseRef();
	m_pProfile = NULL;

	if (m_pConfig != NULL)
		m_pConfig->ReleaseRef();
	m_pConfig = NULL;

	if (m_pHomeSyncObj != NULL)
		m_pHomeSyncObj->ReleaseRef();
	m_pHomeSyncObj = NULL;

	if (m_pStopSyncObj != NULL)
		m_pStopSyncObj->ReleaseRef();
	m_pStopSyncObj = NULL;


  //## end CSTStepperMotorImplementation::~CSTStepperMotorImplementation%.body
}



//## Other Operations (implementation)
void CSTStepperMotorImplementation::InitInstance ()
{
  //## begin CSTStepperMotorImplementation::InitInstance%1034329211.body preserve=yes
    m_pStateMachineEngine	= new CSTStateMachineEngine(this);
	m_pLimitHandler			= new CSTLimitHandler(this);
	m_pPositionMachine		= new CSTPositionMachine(this);
	m_pHwConnection			= new CSTHardwareConnection(this);
	m_pLogic				= new CSTLogic(this);

    ICOAsyncImplementation::InitInstance();
  //## end CSTStepperMotorImplementation::InitInstance%1034329211.body
}

bool CSTStepperMotorImplementation::HandleErrorException (XCOExceptionError* p_pException)
{
  //## begin CSTStepperMotorImplementation::HandleErrorException%1071666884.body preserve=yes
    if (dynamic_cast<XSTExceptionLimit*>(p_pException) != NULL)
        return true;

    return ICOAsyncImplementation::HandleErrorException(p_pException);
  //## end CSTStepperMotorImplementation::HandleErrorException%1071666884.body
}

//## Get and Set Operations for Associations (implementation)

CSTLimitHandler * CSTStepperMotorImplementation::GetpLimitHandler ()
{
  //## begin CSTStepperMotorImplementation::GetpLimitHandler%3E797A820371.get preserve=yes
	ASSERT(m_pLimitHandler != NULL);
	return m_pLimitHandler;
  //## end CSTStepperMotorImplementation::GetpLimitHandler%3E797A820371.get
}

CSTPositionMachine * CSTStepperMotorImplementation::GetpPositionMachine ()
{
  //## begin CSTStepperMotorImplementation::GetpPositionMachine%3E8AA63600A1.get preserve=yes
	ASSERT(m_pPositionMachine != NULL);
	return m_pPositionMachine;
  //## end CSTStepperMotorImplementation::GetpPositionMachine%3E8AA63600A1.get
}

CSTHardwareConnection * CSTStepperMotorImplementation::GetpHwConnection ()
{
  //## begin CSTStepperMotorImplementation::GetpHwConnection%3F323408018C.get preserve=no
  return m_pHwConnection;
  //## end CSTStepperMotorImplementation::GetpHwConnection%3F323408018C.get
}

void CSTStepperMotorImplementation::SetpHwConnection (CSTHardwareConnection * value)
{
  //## begin CSTStepperMotorImplementation::SetpHwConnection%3F323408018C.set preserve=no
  m_pHwConnection = value;
  //## end CSTStepperMotorImplementation::SetpHwConnection%3F323408018C.set
}

CPIStepperMotorProfile * CSTStepperMotorImplementation::GetpProfile ()
{
  //## begin CSTStepperMotorImplementation::GetpProfile%3F4F6ACD0262.get preserve=no
  return m_pProfile;
  //## end CSTStepperMotorImplementation::GetpProfile%3F4F6ACD0262.get
}

void CSTStepperMotorImplementation::SetpProfile (CPIStepperMotorProfile * value)
{
  //## begin CSTStepperMotorImplementation::SetpProfile%3F4F6ACD0262.set preserve=yes
	ASSERT(value != NULL);

  	if (m_pProfile != NULL)
	{
		m_pProfile->ReleaseRef();
	}

	m_pProfile = value;
	m_pProfile->AddRef();
  //## end CSTStepperMotorImplementation::SetpProfile%3F4F6ACD0262.set
}

CPIStepperMotorConfig * CSTStepperMotorImplementation::GetpConfig ()
{
  //## begin CSTStepperMotorImplementation::GetpConfig%3F4F6AD001F4.get preserve=no
  return m_pConfig;
  //## end CSTStepperMotorImplementation::GetpConfig%3F4F6AD001F4.get
}

void CSTStepperMotorImplementation::SetpConfig (CPIStepperMotorConfig * value)
{
  //## begin CSTStepperMotorImplementation::SetpConfig%3F4F6AD001F4.set preserve=yes
  	ASSERT(value != NULL);

  	if (m_pConfig != NULL)
		m_pConfig->ReleaseRef();

	m_pConfig = value;
	m_pConfig->AddRef();
  //## end CSTStepperMotorImplementation::SetpConfig%3F4F6AD001F4.set
}

CSTLogic * CSTStepperMotorImplementation::GetpLogic ()
{
  //## begin CSTStepperMotorImplementation::GetpLogic%3F4F7184000F.get preserve=no
  return m_pLogic;
  //## end CSTStepperMotorImplementation::GetpLogic%3F4F7184000F.get
}

void CSTStepperMotorImplementation::SetpLogic (CSTLogic * value)
{
  //## begin CSTStepperMotorImplementation::SetpLogic%3F4F7184000F.set preserve=no
  m_pLogic = value;
  //## end CSTStepperMotorImplementation::SetpLogic%3F4F7184000F.set
}

CCOSyncObjectInt * CSTStepperMotorImplementation::GetpHomeSyncObj ()
{
  //## begin CSTStepperMotorImplementation::GetpHomeSyncObj%472606AC0107.get preserve=no
  return m_pHomeSyncObj;
  //## end CSTStepperMotorImplementation::GetpHomeSyncObj%472606AC0107.get
}

void CSTStepperMotorImplementation::SetpHomeSyncObj (CCOSyncObjectInt * value)
{
  //## begin CSTStepperMotorImplementation::SetpHomeSyncObj%472606AC0107.set preserve=yes
	if (m_pHomeSyncObj != NULL)
		m_pHomeSyncObj->ReleaseRef();
	
	m_pHomeSyncObj = value;
	if (m_pHomeSyncObj != NULL)
		m_pHomeSyncObj->AddRef();
  //## end CSTStepperMotorImplementation::SetpHomeSyncObj%472606AC0107.set
}

CCOSyncObject * CSTStepperMotorImplementation::GetpStopSyncObj ()
{
  //## begin CSTStepperMotorImplementation::GetpStopSyncObj%489AB3F0007D.get preserve=no
  return m_pStopSyncObj;
  //## end CSTStepperMotorImplementation::GetpStopSyncObj%489AB3F0007D.get
}

void CSTStepperMotorImplementation::SetpStopSyncObj (CCOSyncObject * value)
{
  //## begin CSTStepperMotorImplementation::SetpStopSyncObj%489AB3F0007D.set preserve=yes
	if (m_pStopSyncObj != NULL)
		m_pStopSyncObj->ReleaseRef();
	
	m_pStopSyncObj = value;
	if (m_pStopSyncObj != NULL)
		m_pStopSyncObj->AddRef();
  //## end CSTStepperMotorImplementation::SetpStopSyncObj%489AB3F0007D.set
}

// Additional Declarations
  //## begin CSTStepperMotorImplementation%3DA5DE12038D.declarations preserve=yes
  //## end CSTStepperMotorImplementation%3DA5DE12038D.declarations

//## begin module%3DA5DDFB00C3.epilog preserve=yes
//## end module%3DA5DDFB00C3.epilog
