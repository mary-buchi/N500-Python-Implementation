//## begin module%40CFFAD0039C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%40CFFAD0039C.cm

//## begin module%40CFFAD0039C.cp preserve=no
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
//## end module%40CFFAD0039C.cp

//## Module: EBTCsim%40CFFAD0039C; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCsim.cpp

// stdafx
#include "stdafx.h"
//## begin module%40CFFAD0039C.additionalIncludes preserve=no
//## end module%40CFFAD0039C.additionalIncludes

//## begin module%40CFFAD0039C.includes preserve=yes
//## end module%40CFFAD0039C.includes

// EBTCsim
#include "EBTCsim.h"


//## begin module%40CFFAD0039C.declarations preserve=no
//## end module%40CFFAD0039C.declarations

//## begin module%40CFFAD0039C.additionalDeclarations preserve=yes
//## end module%40CFFAD0039C.additionalDeclarations


// Class CTCHeaterSimulatorWorkerThread 











CTCHeaterSimulatorWorkerThread::CTCHeaterSimulatorWorkerThread()
  //## begin CTCHeaterSimulatorWorkerThread::CTCHeaterSimulatorWorkerThread%.hasinit preserve=no
      : m_bHeaterOn(false), m_dTime(0), m_dActTemp(22.3)
  //## end CTCHeaterSimulatorWorkerThread::CTCHeaterSimulatorWorkerThread%.hasinit
  //## begin CTCHeaterSimulatorWorkerThread::CTCHeaterSimulatorWorkerThread%.initialization preserve=yes
  , ICOThreadWork( _T("Heater Simulation") )
  //## end CTCHeaterSimulatorWorkerThread::CTCHeaterSimulatorWorkerThread%.initialization
{
  //## begin CTCHeaterSimulatorWorkerThread::CTCHeaterSimulatorWorkerThread%.body preserve=yes
  //## end CTCHeaterSimulatorWorkerThread::CTCHeaterSimulatorWorkerThread%.body
}


CTCHeaterSimulatorWorkerThread::~CTCHeaterSimulatorWorkerThread()
{
  //## begin CTCHeaterSimulatorWorkerThread::~CTCHeaterSimulatorWorkerThread%.body preserve=yes
  //## end CTCHeaterSimulatorWorkerThread::~CTCHeaterSimulatorWorkerThread%.body
}



//## Other Operations (implementation)
int CTCHeaterSimulatorWorkerThread::ThreadMain ()
{
  //## begin CTCHeaterSimulatorWorkerThread::ThreadMain%1087372580.body preserve=yes
	bool l_bRunning = true;
	while (l_bRunning)
	{
		try
		{
			DWORD l_dwTimeOut = 100;	// [ms]
			m_dTime += l_dwTimeOut;			// 100ms

			Sleep(l_dwTimeOut);		

			if( m_bHeaterOn )
			{
				IncreaseTemp();
			}
			else
			{
				DecreaseTemp();
			}
		}
		catch(...)
		{
			// TODO:
			ASSERT(false);
		}
	}

	return 0;
  //## end CTCHeaterSimulatorWorkerThread::ThreadMain%1087372580.body
}

void CTCHeaterSimulatorWorkerThread::IncreaseTemp ()
{
  //## begin CTCHeaterSimulatorWorkerThread::IncreaseTemp%1087372583.body preserve=yes
	if (m_dActTemp < 100)
	{
		m_dActTemp += (0.005 * m_dDutyCycle);
	}
	else
	{
		m_dActTemp = 100;
	}
  //## end CTCHeaterSimulatorWorkerThread::IncreaseTemp%1087372583.body
}

void CTCHeaterSimulatorWorkerThread::DecreaseTemp ()
{
  //## begin CTCHeaterSimulatorWorkerThread::DecreaseTemp%1087372584.body preserve=yes
	if ( m_dActTemp > 20 )
	{
		m_dActTemp -= 0.0001;
	}
	else
	{
		m_dActTemp = 20;
	}
  //## end CTCHeaterSimulatorWorkerThread::DecreaseTemp%1087372584.body
}

void CTCHeaterSimulatorWorkerThread::HeaterOn (const double p_dDutyCycle)
{
  //## begin CTCHeaterSimulatorWorkerThread::HeaterOn%1087372587.body preserve=yes
	m_dDutyCycle = p_dDutyCycle;
	m_dTime = 0.0;
	m_dDelay = 30;
	m_dTempMinus1 = m_dActTemp;
	m_bHeaterOn = true;
  //## end CTCHeaterSimulatorWorkerThread::HeaterOn%1087372587.body
}

void CTCHeaterSimulatorWorkerThread::HeaterOff ()
{
  //## begin CTCHeaterSimulatorWorkerThread::HeaterOff%1087372588.body preserve=yes
	m_dTime = 0.0;
	m_dDelay = 60; //[s]
	m_dTempMinus1 = m_dActTemp;
	m_bHeaterOn = false;
  //## end CTCHeaterSimulatorWorkerThread::HeaterOff%1087372588.body
}

CCOSyncObjectInt* CTCHeaterSimulatorWorkerThread::GetTemp ()
{
  //## begin CTCHeaterSimulatorWorkerThread::GetTemp%1087372589.body preserve=yes
	return new CCOSyncObjectInt( (int)(m_dActTemp*1000.0) );
  //## end CTCHeaterSimulatorWorkerThread::GetTemp%1087372589.body
}

// Additional Declarations
  //## begin CTCHeaterSimulatorWorkerThread%40CFFB09035E.declarations preserve=yes
  //## end CTCHeaterSimulatorWorkerThread%40CFFB09035E.declarations

//## begin module%40CFFAD0039C.epilog preserve=yes
//## end module%40CFFAD0039C.epilog
