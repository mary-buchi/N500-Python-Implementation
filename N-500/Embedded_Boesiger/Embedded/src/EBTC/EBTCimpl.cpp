//## begin module%3DE5EDD8014D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EDD8014D.cm

//## begin module%3DE5EDD8014D.cp preserve=no
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
//## end module%3DE5EDD8014D.cp

//## Module: EBTCimpl%3DE5EDD8014D; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCimpl.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EDD8014D.additionalIncludes preserve=no
//## end module%3DE5EDD8014D.additionalIncludes

//## begin module%3DE5EDD8014D.includes preserve=yes
//## end module%3DE5EDD8014D.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBPItype
#include "EBPItype.h"
// EBTCpid2
#include "EBTCpid2.h"
// EBTCpid
#include "EBTCpid.h"
// EBTClogic
#include "EBTClogic.h"
// EBTCcomd
#include "EBTCcomd.h"
// EBTCsten
#include "EBTCsten.h"
// EBTCimpl
#include "EBTCimpl.h"
// EBTCintf
#include "EBTCintf.h"


//## begin module%3DE5EDD8014D.declarations preserve=no
//## end module%3DE5EDD8014D.declarations

//## begin module%3DE5EDD8014D.additionalDeclarations preserve=yes
//## end module%3DE5EDD8014D.additionalDeclarations


// Class CTCTemperatureControlImplementation 






CTCTemperatureControlImplementation::CTCTemperatureControlImplementation (CTCTemperatureControlInterface* p_pInterface)
  //## begin CTCTemperatureControlImplementation::CTCTemperatureControlImplementation%1038899314.hasinit preserve=no
      : m_pLogic(NULL), m_pConfig(NULL), m_pProfile(NULL), m_pPidController(NULL)
  //## end CTCTemperatureControlImplementation::CTCTemperatureControlImplementation%1038899314.hasinit
  //## begin CTCTemperatureControlImplementation::CTCTemperatureControlImplementation%1038899314.initialization preserve=yes
	  ,ICOAsyncImplementation(p_pInterface)
  //## end CTCTemperatureControlImplementation::CTCTemperatureControlImplementation%1038899314.initialization
{
  //## begin CTCTemperatureControlImplementation::CTCTemperatureControlImplementation%1038899314.body preserve=yes
  //## end CTCTemperatureControlImplementation::CTCTemperatureControlImplementation%1038899314.body
}


CTCTemperatureControlImplementation::~CTCTemperatureControlImplementation()
{
  //## begin CTCTemperatureControlImplementation::~CTCTemperatureControlImplementation%.body preserve=yes
	if (m_pLogic != NULL)
		delete m_pLogic;
	m_pLogic = NULL;

	if (m_pPidController != NULL)
		delete m_pPidController;
	m_pPidController = NULL;

	if (m_pProfile != NULL)
		m_pProfile->ReleaseRef();
	m_pProfile = NULL;

	if (m_pConfig != NULL)
		m_pConfig->ReleaseRef();
	m_pConfig = NULL;

  //## end CTCTemperatureControlImplementation::~CTCTemperatureControlImplementation%.body
}



//## Other Operations (implementation)
void CTCTemperatureControlImplementation::InitInstance ()
{
  //## begin CTCTemperatureControlImplementation::InitInstance%1038899315.body preserve=yes
    m_pStateMachineEngine = new CTCStateMachineEngine(this);

	m_pLogic = new CTCLogic(this);
	m_pPidController = new CTCPid();
	
	ICOAsyncImplementation::InitInstance();
  //## end CTCTemperatureControlImplementation::InitInstance%1038899315.body
}

bool CTCTemperatureControlImplementation::HandleErrorException (XCOExceptionError* p_pException)
{
  //## begin CTCTemperatureControlImplementation::HandleErrorException%1216975782.body preserve=yes
	if (dynamic_cast<XCOExceptionCellUndocked*>(p_pException) != NULL)
	{
		try
		{
			CTCCommandCellUndocked l_Command(this);
			l_Command.CreateSyncObjects();
			m_pStateMachineEngine->Run(&l_Command);

			// clean up state machine
			m_pStateMachineEngine->Cleanup();
		}
		catch(...)
		{
            // it is not supported to throw excpetions here
			ASSERT(FALSE);	
		}
		return true;
	}
	else
	{
		return ICOAsyncImplementation::HandleErrorException(p_pException);
	}
  //## end CTCTemperatureControlImplementation::HandleErrorException%1216975782.body
}

double CTCTemperatureControlImplementation::PIDDo (double p_pActualTemp)
{
  //## begin CTCTemperatureControlImplementation::PIDDo%1216975787.body preserve=yes
	return m_pPidController->Do(p_pActualTemp);
  //## end CTCTemperatureControlImplementation::PIDDo%1216975787.body
}

void CTCTemperatureControlImplementation::PIDReset ()
{
  //## begin CTCTemperatureControlImplementation::PIDReset%1216975788.body preserve=yes
	m_pPidController->Reset();
  //## end CTCTemperatureControlImplementation::PIDReset%1216975788.body
}

void CTCTemperatureControlImplementation::PIDSet (double p_NomTemp, double p_dKp, double p_dTi, double p_dTv, double p_dLLimit, double p_dULimit, double p_dTs)
{
  //## begin CTCTemperatureControlImplementation::PIDSet%1216975789.body preserve=yes
	m_pPidController->Set(p_NomTemp,p_dKp,p_dTi,p_dTv,p_dLLimit,p_dULimit,p_dTs);
  //## end CTCTemperatureControlImplementation::PIDSet%1216975789.body
}

//## Get and Set Operations for Associations (implementation)

CTCLogic * CTCTemperatureControlImplementation::GetpLogic ()
{
  //## begin CTCTemperatureControlImplementation::GetpLogic%3E53978E010F.get preserve=yes
	ASSERT( m_pLogic != NULL );
	return m_pLogic;
  //## end CTCTemperatureControlImplementation::GetpLogic%3E53978E010F.get
}

CPITemperatureControlConfig * CTCTemperatureControlImplementation::GetpConfig ()
{
  //## begin CTCTemperatureControlImplementation::GetpConfig%3E53B62E0287.get preserve=yes
	ASSERT( m_pConfig != NULL );
	return m_pConfig;
  //## end CTCTemperatureControlImplementation::GetpConfig%3E53B62E0287.get
}

void CTCTemperatureControlImplementation::SetpConfig (CPITemperatureControlConfig * value)
{
  //## begin CTCTemperatureControlImplementation::SetpConfig%3E53B62E0287.set preserve=yes
	if ( m_pConfig != NULL )
	{
		m_pConfig->ReleaseRef();
	}

	m_pConfig = value;
	if ( m_pConfig != NULL)
	{
		m_pConfig->AddRef();
	}
  //## end CTCTemperatureControlImplementation::SetpConfig%3E53B62E0287.set
}

CPITemperatureControlProfile * CTCTemperatureControlImplementation::GetpProfile ()
{
  //## begin CTCTemperatureControlImplementation::GetpProfile%3E8C23F40051.get preserve=yes
	ASSERT( m_pConfig != NULL );
	return m_pProfile;
  //## end CTCTemperatureControlImplementation::GetpProfile%3E8C23F40051.get
}

void CTCTemperatureControlImplementation::SetpProfile (CPITemperatureControlProfile * value)
{
  //## begin CTCTemperatureControlImplementation::SetpProfile%3E8C23F40051.set preserve=yes
	if ( m_pProfile != NULL )
	{
		m_pProfile->ReleaseRef();
	}

	m_pProfile = value;
	if ( m_pProfile != NULL)
	{
		m_pProfile->AddRef();
	}
  //## end CTCTemperatureControlImplementation::SetpProfile%3E8C23F40051.set
}

CTCPid * CTCTemperatureControlImplementation::GetpPidController ()
{
  //## begin CTCTemperatureControlImplementation::GetpPidController%40C87A01029C.get preserve=yes
	ASSERT( m_pPidController != NULL );
	return m_pPidController;
  //## end CTCTemperatureControlImplementation::GetpPidController%40C87A01029C.get
}

// Additional Declarations
  //## begin CTCTemperatureControlImplementation%3DEC5F100252.declarations preserve=yes
  //## end CTCTemperatureControlImplementation%3DEC5F100252.declarations

// Class CTCTemperatureControlImplementation2 


CTCTemperatureControlImplementation2::CTCTemperatureControlImplementation2 (CTCTemperatureControlInterface2* p_pInterface)
  //## begin CTCTemperatureControlImplementation2::CTCTemperatureControlImplementation2%1217858754.hasinit preserve=no
      : m_pPidController2(NULL)
  //## end CTCTemperatureControlImplementation2::CTCTemperatureControlImplementation2%1217858754.hasinit
  //## begin CTCTemperatureControlImplementation2::CTCTemperatureControlImplementation2%1217858754.initialization preserve=yes
  , CTCTemperatureControlImplementation(p_pInterface)
  //## end CTCTemperatureControlImplementation2::CTCTemperatureControlImplementation2%1217858754.initialization
{
  //## begin CTCTemperatureControlImplementation2::CTCTemperatureControlImplementation2%1217858754.body preserve=yes
  //## end CTCTemperatureControlImplementation2::CTCTemperatureControlImplementation2%1217858754.body
}


CTCTemperatureControlImplementation2::~CTCTemperatureControlImplementation2()
{
  //## begin CTCTemperatureControlImplementation2::~CTCTemperatureControlImplementation2%.body preserve=yes
  //## end CTCTemperatureControlImplementation2::~CTCTemperatureControlImplementation2%.body
}



//## Other Operations (implementation)
void CTCTemperatureControlImplementation2::InitInstance ()
{
  //## begin CTCTemperatureControlImplementation2::InitInstance%1217858753.body preserve=yes

	m_pPidController2 = new CTCPid2();
	CTCTemperatureControlImplementation::InitInstance();
  //## end CTCTemperatureControlImplementation2::InitInstance%1217858753.body
}

double CTCTemperatureControlImplementation2::PIDDo (double p_pActualTemp)
{
  //## begin CTCTemperatureControlImplementation2::PIDDo%1217858750.body preserve=yes
	return m_pPidController2->Do(p_pActualTemp);
  //## end CTCTemperatureControlImplementation2::PIDDo%1217858750.body
}

void CTCTemperatureControlImplementation2::PIDReset ()
{
  //## begin CTCTemperatureControlImplementation2::PIDReset%1217858751.body preserve=yes
	m_pPidController2->Reset();
  //## end CTCTemperatureControlImplementation2::PIDReset%1217858751.body
}

void CTCTemperatureControlImplementation2::PIDSet (double p_NomTemp, double p_dKp, double p_dTi, double p_dTv, double p_dLLimit, double p_dULimit, double p_dTs)
{
  //## begin CTCTemperatureControlImplementation2::PIDSet%1217858752.body preserve=yes
	m_pPidController2->Set(p_NomTemp,p_dKp,p_dTi,p_dTv,p_dLLimit,p_dULimit,p_dTs);
  //## end CTCTemperatureControlImplementation2::PIDSet%1217858752.body
}

//## Get and Set Operations for Associations (implementation)

CTCPid2 * CTCTemperatureControlImplementation2::GetpPidController2 ()
{
  //## begin CTCTemperatureControlImplementation2::GetpPidController2%48970AE80181.get preserve=no
  return m_pPidController2;
  //## end CTCTemperatureControlImplementation2::GetpPidController2%48970AE80181.get
}

// Additional Declarations
  //## begin CTCTemperatureControlImplementation2%48970A5402EA.declarations preserve=yes
  //## end CTCTemperatureControlImplementation2%48970A5402EA.declarations

//## begin module%3DE5EDD8014D.epilog preserve=yes
//## end module%3DE5EDD8014D.epilog
