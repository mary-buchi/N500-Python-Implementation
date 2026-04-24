//## begin module%3EED769F0350.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F0350.cm

//## begin module%3EED769F0350.cp preserve=no
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
//## end module%3EED769F0350.cp

//## Module: EBPCcrea%3EED769F0350; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F0350.additionalIncludes preserve=no
//## end module%3EED769F0350.additionalIncludes

//## begin module%3EED769F0350.includes preserve=yes
//## end module%3EED769F0350.includes

// EBCOimct
#include "EBCOimct.h"
// EBPCconfig
#include "EBPCconfig.h"
// EBPCintf
#include "EBPCintf.h"
// EBPCcrea
#include "EBPCcrea.h"
// EBPCident
#include "EBPCident.h"
//## begin module%3EED769F0350.declarations preserve=no
//## end module%3EED769F0350.declarations

//## begin module%3EED769F0350.additionalDeclarations preserve=yes
//## end module%3EED769F0350.additionalDeclarations


// Class CPCPowerControlCreatorV0 

CPCPowerControlCreatorV0::CPCPowerControlCreatorV0()
  //## begin CPCPowerControlCreatorV0::CPCPowerControlCreatorV0%.hasinit preserve=no
  //## end CPCPowerControlCreatorV0::CPCPowerControlCreatorV0%.hasinit
  //## begin CPCPowerControlCreatorV0::CPCPowerControlCreatorV0%.initialization preserve=yes
	:CPIObjCreatorPowerControl(_T(""))
  //## end CPCPowerControlCreatorV0::CPCPowerControlCreatorV0%.initialization
{
  //## begin CPCPowerControlCreatorV0::CPCPowerControlCreatorV0%.body preserve=yes
  //## end CPCPowerControlCreatorV0::CPCPowerControlCreatorV0%.body
}


CPCPowerControlCreatorV0::~CPCPowerControlCreatorV0()
{
  //## begin CPCPowerControlCreatorV0::~CPCPowerControlCreatorV0%.body preserve=yes
  //## end CPCPowerControlCreatorV0::~CPCPowerControlCreatorV0%.body
}



//## Other Operations (implementation)
IPIPowerControlInterface* CPCPowerControlCreatorV0::Create (UINT p_uiID)
{
  //## begin CPCPowerControlCreatorV0::Create%1038899301.body preserve=yes
  IPIPowerControlInterface* l_Intf = new CPCPowerControlInterface(p_uiID);
  l_Intf->InitInstance();

  return l_Intf;
  //## end CPCPowerControlCreatorV0::Create%1038899301.body
}

// Additional Declarations
  //## begin CPCPowerControlCreatorV0%3EED76CC02EB.declarations preserve=yes
  //## end CPCPowerControlCreatorV0%3EED76CC02EB.declarations

// Class CPCStateCreated 

//## begin CPCStateCreated::pInstance%3EED76CC08A0.role preserve=no  public: static CPCStateCreated {1..1 -> 1..1RFHN}
CPCStateCreated *CPCStateCreated::m_pInstance;
//## end CPCStateCreated::pInstance%3EED76CC08A0.role


CPCStateCreated::CPCStateCreated()
  //## begin CPCStateCreated::CPCStateCreated%.hasinit preserve=no
  //## end CPCStateCreated::CPCStateCreated%.hasinit
  //## begin CPCStateCreated::CPCStateCreated%.initialization preserve=yes
  //## end CPCStateCreated::CPCStateCreated%.initialization
{
  //## begin CPCStateCreated::CPCStateCreated%.body preserve=yes
  //## end CPCStateCreated::CPCStateCreated%.body
}


CPCStateCreated::~CPCStateCreated()
{
  //## begin CPCStateCreated::~CPCStateCreated%.body preserve=yes
  //## end CPCStateCreated::~CPCStateCreated%.body
}



//## Other Operations (implementation)
void CPCStateCreated::Create ()
{
  //## begin CPCStateCreated::Create%1038899331.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CPCStateCreated();
  //## end CPCStateCreated::Create%1038899331.body
}

void CPCStateCreated::Delete ()
{
  //## begin CPCStateCreated::Delete%1044522140.body preserve=yes
	ASSERT(m_pInstance != NULL);
    delete m_pInstance;
	m_pInstance = NULL;
  //## end CPCStateCreated::Delete%1044522140.body
}

CPCStateCreated* CPCStateCreated::GetInstance ()
{
  //## begin CPCStateCreated::GetInstance%1038899333.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CPCStateCreated::GetInstance%1038899333.body
}

void CPCStateCreated::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateCreated::Startup%1044629618.body preserve=yes
	p_pContext->ChangeState(CPCStateConfigNotSet::GetInstance());
  //## end CPCStateCreated::Startup%1044629618.body
}

void CPCStateCreated::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateCreated::ConnectionEstablished%1063223347.body preserve=yes
  //## end CPCStateCreated::ConnectionEstablished%1063223347.body
}

void CPCStateCreated::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CPCStateCreated::ConnectionLost%1063223348.body preserve=yes
  //## end CPCStateCreated::ConnectionLost%1063223348.body
}

// Additional Declarations
  //## begin CPCStateCreated%3EED76CC035E.declarations preserve=yes
  //## end CPCStateCreated%3EED76CC035E.declarations

//## begin module%3EED769F0350.epilog preserve=yes
//## end module%3EED769F0350.epilog
