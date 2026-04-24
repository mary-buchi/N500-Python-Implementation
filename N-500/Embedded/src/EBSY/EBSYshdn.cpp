//## begin module%3ED3626D03B6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3ED3626D03B6.cm

//## begin module%3ED3626D03B6.cp preserve=no
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
//## end module%3ED3626D03B6.cp

//## Module: EBSYshdn%3ED3626D03B6; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYshdn.cpp

// stdafx
#include "stdafx.h"
//## begin module%3ED3626D03B6.additionalIncludes preserve=no
//## end module%3ED3626D03B6.additionalIncludes

//## begin module%3ED3626D03B6.includes preserve=yes
#ifdef _WIN32_WCE
	#include "Pm.h"
	#include "Pkfuncs.h"
#endif
//## end module%3ED3626D03B6.includes

// EBCOimct
#include "EBCOimct.h"
// EBPImain
#include "EBPImain.h"
// EBSYmhan
#include "EBSYmhan.h"
// EBSYshdn
#include "EBSYshdn.h"
// EBSYcrea
#include "EBSYcrea.h"
// EBHIintf
#include "EBHIintf.h"
//## begin module%3ED3626D03B6.declarations preserve=no
//## end module%3ED3626D03B6.declarations

//## begin module%3ED3626D03B6.additionalDeclarations preserve=yes
//## end module%3ED3626D03B6.additionalDeclarations


// Class CSYStateShuttingDown 


//## begin CSYStateShuttingDown::pInstance%3EE5E2D901EC.role preserve=no  public: static CSYStateShuttingDown {1..1 -> 1..1RFHN}
CSYStateShuttingDown *CSYStateShuttingDown::m_pInstance = NULL;
//## end CSYStateShuttingDown::pInstance%3EE5E2D901EC.role


CSYStateShuttingDown::CSYStateShuttingDown()
  //## begin CSYStateShuttingDown::CSYStateShuttingDown%.hasinit preserve=no
      : m_bRebootSystem(false)
  //## end CSYStateShuttingDown::CSYStateShuttingDown%.hasinit
  //## begin CSYStateShuttingDown::CSYStateShuttingDown%.initialization preserve=yes
  //## end CSYStateShuttingDown::CSYStateShuttingDown%.initialization
{
  //## begin CSYStateShuttingDown::CSYStateShuttingDown%.body preserve=yes
  //## end CSYStateShuttingDown::CSYStateShuttingDown%.body
}


CSYStateShuttingDown::~CSYStateShuttingDown()
{
  //## begin CSYStateShuttingDown::~CSYStateShuttingDown%.body preserve=yes
  //## end CSYStateShuttingDown::~CSYStateShuttingDown%.body
}



//## Other Operations (implementation)
void CSYStateShuttingDown::Create ()
{
  //## begin CSYStateShuttingDown::Create%1055252194.body preserve=yes

	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSYStateShuttingDown();

  //## end CSYStateShuttingDown::Create%1055252194.body
}

void CSYStateShuttingDown::Delete ()
{
  //## begin CSYStateShuttingDown::Delete%1055252195.body preserve=yes

    if (m_pInstance)
    {
        delete m_pInstance;
    }

    m_pInstance = NULL;

  //## end CSYStateShuttingDown::Delete%1055252195.body
}

CSYStateShuttingDown* CSYStateShuttingDown::GetInstance ()
{
  //## begin CSYStateShuttingDown::GetInstance%1055252196.body preserve=yes

    ASSERT(m_pInstance != NULL);
    return m_pInstance;

  //## end CSYStateShuttingDown::GetInstance%1055252196.body
}

EPIDeviceState CSYStateShuttingDown::GetDeviceState ()
{
  //## begin CSYStateShuttingDown::GetDeviceState%1056436742.body preserve=yes
    return eNotConnected;
  //## end CSYStateShuttingDown::GetDeviceState%1056436742.body
}

void CSYStateShuttingDown::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateShuttingDown::Do%1056027091.body preserve=yes
    // handle on board leds
    CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHILedRed), 0);
    CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHILedGreen), 0);

    // turn off lamp and laser
	CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDLmpSelection), 0);
	CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDLmpOnOff), 0);
	CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDLmpSelection), 1);
	CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDLmpOnOff), 0);
	CHIInterface::GetInstance()->SetDWord(CHIInterface::GetInstance()->GetStaticObjID(eHIIDIOLaser), 0);

    CO_TRACE(SY_ID, _T("Shuttingdown: Stop PI System"));
    CPISystem::Stop();

    CO_TRACE(SY_ID, _T("Shuttingdown: Unloading Assemblies"));
    CSYModuleHandling::DeRegisterAllInterfaces();
    CSYModuleHandling::UnloadAllDLLs();

    if (m_bRebootSystem)
    {
      CO_TRACE(SY_ID, _T("Shuttingdown: Restart System"));
      // HW Watchdog -> System Reboot
      CHIInterface::GetInstance()->EnableWatchdog(eHIWd1s);
    }

  	p_pContext->ChangeState(CSYStateCreated::GetInstance());

  //## end CSYStateShuttingDown::Do%1056027091.body
}

//## Get and Set Operations for Class Attributes (implementation)

BOOL CSYStateShuttingDown::GetbRebootSystem ()
{
  //## begin CSYStateShuttingDown::GetbRebootSystem%4098B0760348.get preserve=no
  return m_bRebootSystem;
  //## end CSYStateShuttingDown::GetbRebootSystem%4098B0760348.get
}

void CSYStateShuttingDown::SetbRebootSystem (BOOL value)
{
  //## begin CSYStateShuttingDown::SetbRebootSystem%4098B0760348.set preserve=no
  m_bRebootSystem = value;
  //## end CSYStateShuttingDown::SetbRebootSystem%4098B0760348.set
}

// Additional Declarations
  //## begin CSYStateShuttingDown%3EE5E2D901E4.declarations preserve=yes
  //## end CSYStateShuttingDown%3EE5E2D901E4.declarations

//## begin module%3ED3626D03B6.epilog preserve=yes
//## end module%3ED3626D03B6.epilog
