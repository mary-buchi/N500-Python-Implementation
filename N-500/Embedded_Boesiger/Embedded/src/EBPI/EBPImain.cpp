//## begin module%3DA4887F00F7.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA4887F00F7.cm

//## begin module%3DA4887F00F7.cp preserve=no
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
//## end module%3DA4887F00F7.cp

//## Module: EBPImain%3DA4887F00F7; Package body
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPImain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA4887F00F7.additionalIncludes preserve=no
//## end module%3DA4887F00F7.additionalIncludes

//## begin module%3DA4887F00F7.includes preserve=yes
//## end module%3DA4887F00F7.includes

// EBPIfact
#include "EBPIfact.h"
// EBPImain
#include "EBPImain.h"
// EBPIcpst
#include "EBPIcpst.h"
// EBPIidnt
#include "EBPIidnt.h"


//## begin module%3DA4887F00F7.declarations preserve=no
//## end module%3DA4887F00F7.declarations

//## begin module%3DA4887F00F7.additionalDeclarations preserve=yes
//## end module%3DA4887F00F7.additionalDeclarations


// Class CPISystem 

CPISystem::CPISystem()
  //## begin CPISystem::CPISystem%.hasinit preserve=no
  //## end CPISystem::CPISystem%.hasinit
  //## begin CPISystem::CPISystem%.initialization preserve=yes
  //## end CPISystem::CPISystem%.initialization
{
  //## begin CPISystem::CPISystem%.body preserve=yes
  //## end CPISystem::CPISystem%.body
}


CPISystem::~CPISystem()
{
  //## begin CPISystem::~CPISystem%.body preserve=yes
  //## end CPISystem::~CPISystem%.body
}



//## Other Operations (implementation)
void CPISystem::Create ()
{
  //## begin CPISystem::Create%1034190393.body preserve=yes
    CPIDriverFactory::Create();
	CPIDriverFactory::GetInstance()->LoadDrivers();
    CPIObjectFactory::Create();
    CPIComponentsState::Create();
  //## end CPISystem::Create%1034190393.body
}

void CPISystem::Start ()
{
  //## begin CPISystem::Start%1055492123.body preserve=yes
    CPIDriverFactory::GetInstance()->Start();
  //## end CPISystem::Start%1055492123.body
}

void CPISystem::Stop ()
{
  //## begin CPISystem::Stop%1056354244.body preserve=yes
    CO_TRACE(PI_ID, _T("Shuttingdown: Stop Driver"));
    CPIDriverFactory::GetInstance()->Stop();

    CO_TRACE(PI_ID, _T("Shuttingdown: Cleanup Objects"));
    CPIObjectFactory::GetInstance()->Reset();
    CPIObjectFactory::GetInstance()->ReleaseCreators();
  //## end CPISystem::Stop%1056354244.body
}

void CPISystem::Delete ()
{
  //## begin CPISystem::Delete%1034190394.body preserve=yes
    CPIComponentsState::Delete();

    CO_TRACE(PI_ID, _T("Shuttingdown: Delete Driver Factory"));
    CPIDriverFactory::Delete();

    CO_TRACE(PI_ID, _T("Shuttingdown: Delete Object Factory"));
    CPIObjectFactory::Delete();

  //## end CPISystem::Delete%1034190394.body
}

// Additional Declarations
  //## begin CPISystem%3DA4895803CA.declarations preserve=yes
  //## end CPISystem%3DA4895803CA.declarations

// Class CPIDriverFactory 

//## begin CPIDriverFactory::pInstance%3DA48A9203C2.role preserve=no  public: static CPIDriverFactory {1..1 -> 1..1RFHN}
CPIDriverFactory *CPIDriverFactory::m_pInstance = NULL;
//## end CPIDriverFactory::pInstance%3DA48A9203C2.role



CPIDriverFactory::CPIDriverFactory()
  //## begin CPIDriverFactory::CPIDriverFactory%.hasinit preserve=no
      : m_pTcpDriver(NULL)
  //## end CPIDriverFactory::CPIDriverFactory%.hasinit
  //## begin CPIDriverFactory::CPIDriverFactory%.initialization preserve=yes
  //## end CPIDriverFactory::CPIDriverFactory%.initialization
{
  //## begin CPIDriverFactory::CPIDriverFactory%.body preserve=yes
  //## end CPIDriverFactory::CPIDriverFactory%.body
}


CPIDriverFactory::~CPIDriverFactory()
{
  //## begin CPIDriverFactory::~CPIDriverFactory%.body preserve=yes
	if (m_pTcpDriver)
	{
		// shutdown driver
		(*(m_pTcpDriver->GetpShutdownMethod()))();

		::FreeLibrary(m_pTcpDriver->GethLibrary());
		delete m_pTcpDriver;
		m_pTcpDriver = NULL;
	}
  //## end CPIDriverFactory::~CPIDriverFactory%.body
}



//## Other Operations (implementation)
void CPIDriverFactory::Create ()
{
  //## begin CPIDriverFactory::Create%1034190395.body preserve=yes
	ASSERT(m_pInstance == NULL);
	m_pInstance = new CPIDriverFactory();
  //## end CPIDriverFactory::Create%1034190395.body
}

void CPIDriverFactory::Delete ()
{
  //## begin CPIDriverFactory::Delete%1034190396.body preserve=yes
	delete m_pInstance;
	m_pInstance = NULL;
  //## end CPIDriverFactory::Delete%1034190396.body
}

CPIDriverFactory* CPIDriverFactory::GetInstance ()
{
  //## begin CPIDriverFactory::GetInstance%1034190397.body preserve=yes
	ASSERT(m_pInstance != NULL);
	return m_pInstance;
  //## end CPIDriverFactory::GetInstance%1034190397.body
}

void CPIDriverFactory::LoadDrivers ()
{
  //## begin CPIDriverFactory::LoadDrivers%1034190398.body preserve=yes
	// load tcp library
	HMODULE l_hLib = ::LoadLibrary(_T("EBET.dll"));
	if (l_hLib)
	{
		// get standard entries 
#ifdef _WIN32_WCE
    FARPROC l_fnInvokeMethod	= ::GetProcAddress(l_hLib, _T("InvokeDriver"));
		FARPROC l_fnShutdownMethod	= ::GetProcAddress(l_hLib, _T("ShutdownDriver"));
#else
    // from function "GetProcAddress" only the ANSI version is available under Win NT/2000
    FARPROC l_fnInvokeMethod	= ::GetProcAddress(l_hLib, "InvokeDriver");
		FARPROC l_fnShutdownMethod	= ::GetProcAddress(l_hLib, "ShutdownDriver");
#endif


		// store info
		m_pTcpDriver = new CPIDriverEntry(l_hLib, (TINVOKE_DRIVER_PROC)l_fnInvokeMethod, (TINVOKE_DRIVER_PROC)l_fnShutdownMethod);
	}
  //## end CPIDriverFactory::LoadDrivers%1034190398.body
}

void CPIDriverFactory::Start ()
{
  //## begin CPIDriverFactory::Start%1034190400.body preserve=yes
	// TODO: just tcp driver for now
	ASSERT(m_pTcpDriver != NULL);
	(*(m_pTcpDriver->GetpInvokeMethod()))();
  //## end CPIDriverFactory::Start%1034190400.body
}

void CPIDriverFactory::Stop ()
{
  //## begin CPIDriverFactory::Stop%1056354243.body preserve=yes
	if (m_pTcpDriver != NULL)
	    (*(m_pTcpDriver->GetpShutdownMethod()))();
  //## end CPIDriverFactory::Stop%1056354243.body
}

// Additional Declarations
  //## begin CPIDriverFactory%3DA48A7A00F6.declarations preserve=yes
  //## end CPIDriverFactory%3DA48A7A00F6.declarations

// Class CPIDriverEntry 





CPIDriverEntry::CPIDriverEntry (HMODULE p_hLibrary, TINVOKE_DRIVER_PROC p_fnInvokeMethod, TINVOKE_DRIVER_PROC p_fnShutdownMethod)
  //## begin CPIDriverEntry::CPIDriverEntry%1034190399.hasinit preserve=no
      : m_pInvokeMethod(p_fnInvokeMethod), m_hLibrary(p_hLibrary), m_pShutdownMethod(p_fnShutdownMethod)
  //## end CPIDriverEntry::CPIDriverEntry%1034190399.hasinit
  //## begin CPIDriverEntry::CPIDriverEntry%1034190399.initialization preserve=yes
  //## end CPIDriverEntry::CPIDriverEntry%1034190399.initialization
{
  //## begin CPIDriverEntry::CPIDriverEntry%1034190399.body preserve=yes
  //## end CPIDriverEntry::CPIDriverEntry%1034190399.body
}


CPIDriverEntry::~CPIDriverEntry()
{
  //## begin CPIDriverEntry::~CPIDriverEntry%.body preserve=yes
  //## end CPIDriverEntry::~CPIDriverEntry%.body
}


//## Get and Set Operations for Associations (implementation)

TINVOKE_DRIVER_PROC CPIDriverEntry::GetpInvokeMethod ()
{
  //## begin CPIDriverEntry::GetpInvokeMethod%3DA48D800104.get preserve=no
  return m_pInvokeMethod;
  //## end CPIDriverEntry::GetpInvokeMethod%3DA48D800104.get
}

HMODULE CPIDriverEntry::GethLibrary ()
{
  //## begin CPIDriverEntry::GethLibrary%3DA48E6E03E1.get preserve=no
  return m_hLibrary;
  //## end CPIDriverEntry::GethLibrary%3DA48E6E03E1.get
}

TINVOKE_DRIVER_PROC CPIDriverEntry::GetpShutdownMethod ()
{
  //## begin CPIDriverEntry::GetpShutdownMethod%3DA491660217.get preserve=no
  return m_pShutdownMethod;
  //## end CPIDriverEntry::GetpShutdownMethod%3DA491660217.get
}

// Additional Declarations
  //## begin CPIDriverEntry%3DA48BB70124.declarations preserve=yes
  //## end CPIDriverEntry%3DA48BB70124.declarations

//## begin module%3DA4887F00F7.epilog preserve=yes
//## end module%3DA4887F00F7.epilog
