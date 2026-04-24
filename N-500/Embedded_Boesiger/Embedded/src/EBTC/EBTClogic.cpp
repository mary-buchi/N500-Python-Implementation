//## begin module%3E538BD7032C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E538BD7032C.cm

//## begin module%3E538BD7032C.cp preserve=no
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
//## end module%3E538BD7032C.cp

//## Module: EBTClogic%3E538BD7032C; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTClogic.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E538BD7032C.additionalIncludes preserve=no
//## end module%3E538BD7032C.additionalIncludes

//## begin module%3E538BD7032C.includes preserve=yes
#ifdef _WIN32_WCE
  #include <pkfuncs.h>
#else
  #include <math.h>
#endif
//## end module%3E538BD7032C.includes

// EBCOsync
#include "EBCOsync.h"
// EBPIcpst
#include "EBPIcpst.h"
// EBPIenum
#include "EBPIenum.h"
// EBPIfact
#include "EBPIfact.h"
// EBPIintf
#include "EBPIintf.h"
// EBTCsim
#include "EBTCsim.h"
// EBTCpid
#include "EBTCpid.h"
// EBTCexcp
#include "EBTCexcp.h"
// EBTClogic
#include "EBTClogic.h"
// EBTCsten
#include "EBTCsten.h"
// EBTCimpl
#include "EBTCimpl.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3E538BD7032C.declarations preserve=no
//## end module%3E538BD7032C.declarations

//## begin module%3E538BD7032C.additionalDeclarations preserve=yes
#include "EBTCident.h"
//## end module%3E538BD7032C.additionalDeclarations


// Class CTCLogic 















CTCLogic::CTCLogic (CTCTemperatureControlImplementation* p_pContext)
  //## begin CTCLogic::CTCLogic%1045561403.hasinit preserve=no
      : m_bHardwarePresent(false), m_bHeaterOn(false), m_dTempAct(0), m_dDutyCycle(0), m_bStartWatchErrorLimits(false), m_pContext(p_pContext), m_pIncidentSyncObject(NULL), m_pSensor(NULL), m_pHeaterSimulatorWorkerThread(NULL)
  //## end CTCLogic::CTCLogic%1045561403.hasinit
  //## begin CTCLogic::CTCLogic%1045561403.initialization preserve=yes
  //## end CTCLogic::CTCLogic%1045561403.initialization
{
  //## begin CTCLogic::CTCLogic%1045561403.body preserve=yes
	m_bHardwarePresent = CPIComponentsState::GetInstance()->GetComponentState(TC_ID);

	if( !m_bHardwarePresent )
	{
		// Creates a new thread.
		m_pHeaterSimulatorWorkerThread = new CTCHeaterSimulatorWorkerThread();

		// Starts the thread.
		CCOSyncObjectPtr l_SyncObj = m_pHeaterSimulatorWorkerThread->Start();
		l_SyncObj->Synchronize();
	}

  //## end CTCLogic::CTCLogic%1045561403.body
}


CTCLogic::~CTCLogic()
{
  //## begin CTCLogic::~CTCLogic%.body preserve=yes

	if (m_pIncidentSyncObject != NULL)
		m_pIncidentSyncObject->ReleaseRef();
	m_pIncidentSyncObject = NULL;

	if( m_pHeaterSimulatorWorkerThread != NULL )
	{
		m_pHeaterSimulatorWorkerThread->TerminateThread();
		delete m_pHeaterSimulatorWorkerThread;
	}

	m_pHeaterSimulatorWorkerThread = NULL;

  //## end CTCLogic::~CTCLogic%.body
}



//## Other Operations (implementation)
void CTCLogic::CheckTemp ()
{
  //## begin CTCLogic::CheckTemp%1046071779.body preserve=yes
	CString l_sMsg;

	// Get error ranges in [%]
	double l_dTempErrorLimit = (double)GetpContext()->GetpProfile()->GetiTemperatureErrorULimit();
	l_dTempErrorLimit /= 1000;

	double l_dNomValue = (double)GetpContext()->GetpProfile()->GetiTemperatureNominal();
	l_dNomValue /= 1000;
    
	// Limit in Grad celsius.
	double l_dDeltaTempLimit = l_dTempErrorLimit / 100 * l_dNomValue;

	// Define when to start.
	if ( !m_bStartWatchErrorLimits )
	{
		// Start temp watch first time, when the lower error limit is reached.
		m_bStartWatchErrorLimits = ( (m_dTempAct ) > ( l_dNomValue - l_dDeltaTempLimit + 1) ) &&  ( (m_dTempAct ) < ( l_dNomValue + l_dDeltaTempLimit -1 ));
	}

	if( m_bStartWatchErrorLimits )
	{
		if ( m_dTempAct > ( l_dNomValue + l_dDeltaTempLimit ) )
		{
			// Upper limit reached.
			l_sMsg.Format(_T("File: %s Line: %d Error %d\n"), _T(__FILE__), __LINE__, 0);
			CO_TRACE(TC_ID, l_sMsg);
			throw new XTCExceptionTemperatureErrorULimit(TC_ID, IDE_TC_TEMPERATURE_ERROR_ULIMIT, _T(__FILE__), __LINE__, 0);
		}
		else if ( m_dTempAct < ( l_dNomValue - l_dDeltaTempLimit ) )
		{
			l_sMsg.Format(_T("File: %s Line: %d Error %d\n"),_T(__FILE__), __LINE__, 0);
			CO_TRACE(TC_ID, l_sMsg);
			throw new XTCExceptionTemperatureErrorLLimit(TC_ID, IDE_TC_TEMPERATURE_ERROR_LLIMIT, _T(__FILE__), __LINE__, 0);
		}
	}
  //## end CTCLogic::CheckTemp%1046071779.body
}

void CTCLogic::GetTemp ()
{
  //## begin CTCLogic::GetTemp%1058349232.body preserve=yes

	CCOSyncObjectInt* l_pSyncObjInt = NULL;

	try
	{
		if ( m_bHardwarePresent )
		{
			ASSERT( m_pSensor != NULL );
			l_pSyncObjInt = m_pSensor->GetTemperature();
			ASSERT(l_pSyncObjInt != NULL);
		}
		else
		{
			ASSERT( m_pHeaterSimulatorWorkerThread != NULL );
			l_pSyncObjInt = m_pHeaterSimulatorWorkerThread->GetTemp();
		}

		m_dTempAct = (double)l_pSyncObjInt->GetValue(); // [mili degree]
		m_dTempAct /=1000; // degree

		l_pSyncObjInt->ReleaseRef();

	}
	catch( XCOExceptionErrorTimeout* )
	{
		// I2C produced an error.
		// Sensor defect, or cell unpluged.
		if( l_pSyncObjInt != NULL )
		{
			l_pSyncObjInt->ReleaseRef();
		}
		l_pSyncObjInt = NULL;

		throw;
	}

  //## end CTCLogic::GetTemp%1058349232.body
}

void CTCLogic::HeaterOn ()
{
  //## begin CTCLogic::HeaterOn%1086854780.body preserve=yes
	if (!m_bHeaterOn )
	{
		if (m_bHardwarePresent)
		{
			IHIInterface::GetInstance()->SetDWord(m_dwOutputID, m_dwOn);
		}
		else
		{
			m_pHeaterSimulatorWorkerThread->HeaterOn( m_dDutyCycle );
		}
		CO_TRACE(TC_ID, _T("Heater ON"));
		m_bHeaterOn = true;
	}
  //## end CTCLogic::HeaterOn%1086854780.body
}

void CTCLogic::HeaterOff ()
{
  //## begin CTCLogic::HeaterOff%1086854781.body preserve=yes
	if(m_bHeaterOn)
	{
		if (m_bHardwarePresent)
		{
			IHIInterface::GetInstance()->SetDWord(m_dwOutputID, m_dwOff);
		}
		else
		{
			m_pHeaterSimulatorWorkerThread->HeaterOff();
		}
		CO_TRACE(TC_ID, _T("Heater OFF"));
		m_bHeaterOn = false;
	}
  //## end CTCLogic::HeaterOff%1086854781.body
}

void CTCLogic::Init ()
{
  //## begin CTCLogic::Init%1086959230.body preserve=yes
	try
	{
		// Initalize I2C Temperature sensor.
		DWORD l_dwID = GetpContext()->GetpConfig()->GetdwIDHeaterTemperatureSensor();

		// TC is not the owner of this object. No add, and release ref.
		m_pSensor = CPIObjectFactory::GetInstance()->CreateSensorDS1631Z( l_dwID, _T("") );
		ASSERT( m_pSensor != NULL );

		CCOSyncObjectPtr l_pSyncObject = m_pSensor->SetSensorConfig( GetpContext()->GetpConfig()->GetpSensorConfig() );
		l_pSyncObject->Synchronize(1000);
		Sleep(500);	// Wait until the sensor has been configurated.

		// get temp once to be sure i2c works
		CCOSyncObjectPtr l_SyncObj = m_pSensor->GetTemperature(); 
		l_SyncObj->Synchronize(1000);

		m_bStartWatchErrorLimits = false;
	}
	catch(XCOException *)
	{
		throw;
	}

  //## end CTCLogic::Init%1086959230.body
}

//## Get and Set Operations for Class Attributes (implementation)

double CTCLogic::GetdTempAct ()
{
  //## begin CTCLogic::GetdTempAct%40CD733702C7.get preserve=no
  return m_dTempAct;
  //## end CTCLogic::GetdTempAct%40CD733702C7.get
}

double CTCLogic::GetdDutyCycle ()
{
  //## begin CTCLogic::GetdDutyCycle%40CEB110030E.get preserve=no
  return m_dDutyCycle;
  //## end CTCLogic::GetdDutyCycle%40CEB110030E.get
}

void CTCLogic::SetdDutyCycle (double value)
{
  //## begin CTCLogic::SetdDutyCycle%40CEB110030E.set preserve=yes
	m_dDutyCycle = value;

	if ( value >= 1.0 )
	{ 
		m_eHeaterState = eOn;
	}
	else if ( value <= 0.0 )
	{
		m_eHeaterState = eOff;
	}
	else
	{
		m_eHeaterState = ePwm;
	}
  //## end CTCLogic::SetdDutyCycle%40CEB110030E.set
}

DWORD CTCLogic::GetdwOn ()
{
  //## begin CTCLogic::GetdwOn%419487960182.get preserve=no
  return m_dwOn;
  //## end CTCLogic::GetdwOn%419487960182.get
}

void CTCLogic::SetdwOn (DWORD value)
{
  //## begin CTCLogic::SetdwOn%419487960182.set preserve=no
  m_dwOn = value;
  //## end CTCLogic::SetdwOn%419487960182.set
}

DWORD CTCLogic::GetdwOff ()
{
  //## begin CTCLogic::GetdwOff%419487B103A8.get preserve=no
  return m_dwOff;
  //## end CTCLogic::GetdwOff%419487B103A8.get
}

void CTCLogic::SetdwOff (DWORD value)
{
  //## begin CTCLogic::SetdwOff%419487B103A8.set preserve=no
  m_dwOff = value;
  //## end CTCLogic::SetdwOff%419487B103A8.set
}

DWORD CTCLogic::GetdwOutputID ()
{
  //## begin CTCLogic::GetdwOutputID%4194B21801F6.get preserve=no
  return m_dwOutputID;
  //## end CTCLogic::GetdwOutputID%4194B21801F6.get
}

void CTCLogic::SetdwOutputID (DWORD value)
{
  //## begin CTCLogic::SetdwOutputID%4194B21801F6.set preserve=no
  m_dwOutputID = value;
  //## end CTCLogic::SetdwOutputID%4194B21801F6.set
}

//## Get and Set Operations for Associations (implementation)

CTCTemperatureControlImplementation * CTCLogic::GetpContext ()
{
  //## begin CTCLogic::GetpContext%3E539AB50296.get preserve=no
  return m_pContext;
  //## end CTCLogic::GetpContext%3E539AB50296.get
}

CCOSyncObject * CTCLogic::GetpIncidentSyncObject ()
{
  //## begin CTCLogic::GetpIncidentSyncObject%3EEF2E5302EE.get preserve=no
  return m_pIncidentSyncObject;
  //## end CTCLogic::GetpIncidentSyncObject%3EEF2E5302EE.get
}

void CTCLogic::SetpIncidentSyncObject (CCOSyncObject * value)
{
  //## begin CTCLogic::SetpIncidentSyncObject%3EEF2E5302EE.set preserve=yes
	if (m_pIncidentSyncObject)
	{
		m_pIncidentSyncObject->ReleaseRef();
	}

	m_pIncidentSyncObject = value;
	if (m_pIncidentSyncObject)
	{
		m_pIncidentSyncObject->AddRef();
	}
  //## end CTCLogic::SetpIncidentSyncObject%3EEF2E5302EE.set
}

EPIHeaterState CTCLogic::GeteHeaterState ()
{
  //## begin CTCLogic::GeteHeaterState%40CD89910130.get preserve=no
  return m_eHeaterState;
  //## end CTCLogic::GeteHeaterState%40CD89910130.get
}

void CTCLogic::SeteHeaterState (EPIHeaterState value)
{
  //## begin CTCLogic::SeteHeaterState%40CD89910130.set preserve=no
  m_eHeaterState = value;
  //## end CTCLogic::SeteHeaterState%40CD89910130.set
}

// Additional Declarations
  //## begin CTCLogic%3E535FA20138.declarations preserve=yes
  //## end CTCLogic%3E535FA20138.declarations

//## begin module%3E538BD7032C.epilog preserve=yes
//## end module%3E538BD7032C.epilog
