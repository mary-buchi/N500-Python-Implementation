//## begin module%3EE5D730032B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE5D730032B.cm

//## begin module%3EE5D730032B.cp preserve=no
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
//## end module%3EE5D730032B.cp

//## Module: EBSYifcf%3EE5D730032B; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYifcf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE5D730032B.additionalIncludes preserve=no
//## end module%3EE5D730032B.additionalIncludes

//## begin module%3EE5D730032B.includes preserve=yes
//## end module%3EE5D730032B.includes

// EBPItype
#include "EBPItype.h"
// EBSYimpl
#include "EBSYimpl.h"
// EBSYifse
#include "EBSYifse.h"
// EBSYifcf
#include "EBSYifcf.h"
// EBSYshdn
#include "EBSYshdn.h"


//## begin module%3EE5D730032B.declarations preserve=no
//## end module%3EE5D730032B.declarations

//## begin module%3EE5D730032B.additionalDeclarations preserve=yes
//## end module%3EE5D730032B.additionalDeclarations


// Class CSYStateConstitutionConfigInterface 

//## begin CSYStateConstitutionConfigInterface::pInstance%3EE5D24D00E5.role preserve=no  public: static CSYStateConstitutionConfigInterface {1..1 -> 1..1RFHN}
CSYStateConstitutionConfigInterface *CSYStateConstitutionConfigInterface::m_pInstance = NULL;
//## end CSYStateConstitutionConfigInterface::pInstance%3EE5D24D00E5.role



CSYStateConstitutionConfigInterface::CSYStateConstitutionConfigInterface()
  //## begin CSYStateConstitutionConfigInterface::CSYStateConstitutionConfigInterface%.hasinit preserve=no
      : m_pInterfaceConfig(NULL)
  //## end CSYStateConstitutionConfigInterface::CSYStateConstitutionConfigInterface%.hasinit
  //## begin CSYStateConstitutionConfigInterface::CSYStateConstitutionConfigInterface%.initialization preserve=yes
  //## end CSYStateConstitutionConfigInterface::CSYStateConstitutionConfigInterface%.initialization
{
  //## begin CSYStateConstitutionConfigInterface::CSYStateConstitutionConfigInterface%.body preserve=yes
  //## end CSYStateConstitutionConfigInterface::CSYStateConstitutionConfigInterface%.body
}


CSYStateConstitutionConfigInterface::~CSYStateConstitutionConfigInterface()
{
  //## begin CSYStateConstitutionConfigInterface::~CSYStateConstitutionConfigInterface%.body preserve=yes
  //## end CSYStateConstitutionConfigInterface::~CSYStateConstitutionConfigInterface%.body
}



//## Other Operations (implementation)
void CSYStateConstitutionConfigInterface::Create ()
{
  //## begin CSYStateConstitutionConfigInterface::Create%1055252179.body preserve=yes

	ASSERT(m_pInstance == NULL);
    m_pInstance = new CSYStateConstitutionConfigInterface();

  //## end CSYStateConstitutionConfigInterface::Create%1055252179.body
}

void CSYStateConstitutionConfigInterface::Delete ()
{
  //## begin CSYStateConstitutionConfigInterface::Delete%1055252180.body preserve=yes
    if (m_pInstance)
        delete m_pInstance;
    m_pInstance = NULL;
  //## end CSYStateConstitutionConfigInterface::Delete%1055252180.body
}

CSYStateConstitutionConfigInterface* CSYStateConstitutionConfigInterface::GetInstance ()
{
  //## begin CSYStateConstitutionConfigInterface::GetInstance%1055252181.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSYStateConstitutionConfigInterface::GetInstance%1055252181.body
}

EPIDeviceState CSYStateConstitutionConfigInterface::GetDeviceState ()
{
  //## begin CSYStateConstitutionConfigInterface::GetDeviceState%1056436752.body preserve=yes
    return eNotConnected;
  //## end CSYStateConstitutionConfigInterface::GetDeviceState%1056436752.body
}

void CSYStateConstitutionConfigInterface::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSYStateConstitutionConfigInterface::Do%1056523874.body preserve=yes

    // Set new interface config
    CSYInterfaceSettings::SetIPAddress (m_pInterfaceConfig);

    CSYStateShuttingDown::GetInstance()->SetbRebootSystem(true);
  	p_pContext->ChangeState(CSYStateShuttingDown::GetInstance());

    // signal command sync object
    CCOSyncObject* l_pSyncObj = GetpContext(p_pContext)->GetpSetInterfaceCfgSyncObj();
    ASSERT(l_pSyncObj != NULL);
    l_pSyncObj->SignalCompletion();
    GetpContext(p_pContext)->SetpSetInterfaceCfgSyncObj(NULL);

  //## end CSYStateConstitutionConfigInterface::Do%1056523874.body
}

//## Get and Set Operations for Associations (implementation)

void CSYStateConstitutionConfigInterface::SetpInterfaceConfig (CPIInterfaceConfig * value)
{
  //## begin CSYStateConstitutionConfigInterface::SetpInterfaceConfig%4097FFAF00F9.set preserve=no
  m_pInterfaceConfig = value;
  //## end CSYStateConstitutionConfigInterface::SetpInterfaceConfig%4097FFAF00F9.set
}

// Additional Declarations
  //## begin CSYStateConstitutionConfigInterface%3EE5D24D00D0.declarations preserve=yes
  //## end CSYStateConstitutionConfigInterface%3EE5D24D00D0.declarations

//## begin module%3EE5D730032B.epilog preserve=yes
//## end module%3EE5D730032B.epilog
