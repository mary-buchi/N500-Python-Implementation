//## begin module%3EED769F0355.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F0355.cm

//## begin module%3EED769F0355.cp preserve=no
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
//## end module%3EED769F0355.cp

//## Module: EBPCimpl%3EED769F0355; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCimpl.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F0355.additionalIncludes preserve=no
//## end module%3EED769F0355.additionalIncludes

//## begin module%3EED769F0355.includes preserve=yes
//## end module%3EED769F0355.includes

// EBPItype
#include "EBPItype.h"
// EBPClogic
#include "EBPClogic.h"
// EBPCsten
#include "EBPCsten.h"
// EBPCimpl
#include "EBPCimpl.h"
// EBPCintf
#include "EBPCintf.h"
// EBPCpid
#include "EBPCpid.h"


//## begin module%3EED769F0355.declarations preserve=no
//## end module%3EED769F0355.declarations

//## begin module%3EED769F0355.additionalDeclarations preserve=yes
//## end module%3EED769F0355.additionalDeclarations


// Class CPCPowerControlImplementation 






CPCPowerControlImplementation::CPCPowerControlImplementation (CPCPowerControlInterface* p_pInterface)
  //## begin CPCPowerControlImplementation::CPCPowerControlImplementation%1038899314.hasinit preserve=no
      : m_pLogic(NULL), m_pConfig(NULL), m_pProfile(NULL), m_pPID(NULL)
  //## end CPCPowerControlImplementation::CPCPowerControlImplementation%1038899314.hasinit
  //## begin CPCPowerControlImplementation::CPCPowerControlImplementation%1038899314.initialization preserve=yes
	  ,ICOAsyncImplementation(p_pInterface)
  //## end CPCPowerControlImplementation::CPCPowerControlImplementation%1038899314.initialization
{
  //## begin CPCPowerControlImplementation::CPCPowerControlImplementation%1038899314.body preserve=yes
  //## end CPCPowerControlImplementation::CPCPowerControlImplementation%1038899314.body
}


CPCPowerControlImplementation::~CPCPowerControlImplementation()
{
  //## begin CPCPowerControlImplementation::~CPCPowerControlImplementation%.body preserve=yes
	if (m_pLogic != NULL)
		delete m_pLogic;
	m_pLogic = NULL;

	if (m_pProfile != NULL)
		m_pProfile->ReleaseRef();
	m_pProfile = NULL;

	if (m_pConfig != NULL)
		m_pConfig->ReleaseRef();
	m_pConfig = NULL;

	if (m_pPID != NULL)
		delete m_pPID;
	m_pPID = NULL;

  //## end CPCPowerControlImplementation::~CPCPowerControlImplementation%.body
}



//## Other Operations (implementation)
void CPCPowerControlImplementation::InitInstance ()
{
  //## begin CPCPowerControlImplementation::InitInstance%1038899315.body preserve=yes
    m_pStateMachineEngine = new CPCStateMachineEngine(this);

	m_pLogic = new CPCLogic(this);
	m_pPID = new CPCPid();
	
	ICOAsyncImplementation::InitInstance();
  //## end CPCPowerControlImplementation::InitInstance%1038899315.body
}

//## Get and Set Operations for Associations (implementation)

CPCLogic * CPCPowerControlImplementation::GetpLogic ()
{
  //## begin CPCPowerControlImplementation::GetpLogic%3EED76CC08F0.get preserve=yes
	ASSERT(m_pLogic != NULL);
	return m_pLogic;
  //## end CPCPowerControlImplementation::GetpLogic%3EED76CC08F0.get
}

CPIPowerControlConfig * CPCPowerControlImplementation::GetpConfig ()
{
  //## begin CPCPowerControlImplementation::GetpConfig%3F0E8CCD01CF.get preserve=yes
	ASSERT(m_pConfig != NULL);
	return m_pConfig;
  //## end CPCPowerControlImplementation::GetpConfig%3F0E8CCD01CF.get
}

void CPCPowerControlImplementation::SetpConfig (CPIPowerControlConfig * value)
{
  //## begin CPCPowerControlImplementation::SetpConfig%3F0E8CCD01CF.set preserve=yes
	if (m_pConfig != NULL)
		m_pConfig->ReleaseRef();

	m_pConfig = value;
	m_pConfig->AddRef();
  //## end CPCPowerControlImplementation::SetpConfig%3F0E8CCD01CF.set
}

CPIPowerControlProfile * CPCPowerControlImplementation::GetpProfile ()
{
  //## begin CPCPowerControlImplementation::GetpProfile%3F13F773028B.get preserve=yes
	ASSERT(m_pProfile != NULL);
	return m_pProfile;
  //## end CPCPowerControlImplementation::GetpProfile%3F13F773028B.get
}

void CPCPowerControlImplementation::SetpProfile (CPIPowerControlProfile * value)
{
  //## begin CPCPowerControlImplementation::SetpProfile%3F13F773028B.set preserve=yes
	if (m_pProfile != NULL)
		m_pProfile->ReleaseRef();

	m_pProfile = value;
	m_pProfile->AddRef();
  //## end CPCPowerControlImplementation::SetpProfile%3F13F773028B.set
}

CPCPid * CPCPowerControlImplementation::GetpPID ()
{
  //## begin CPCPowerControlImplementation::GetpPID%40346A6F017F.get preserve=yes
	ASSERT(m_pPID != NULL);
	return m_pPID;
  //## end CPCPowerControlImplementation::GetpPID%40346A6F017F.get
}

// Additional Declarations
  //## begin CPCPowerControlImplementation%3EED76CC032D.declarations preserve=yes
  //## end CPCPowerControlImplementation%3EED76CC032D.declarations

//## begin module%3EED769F0355.epilog preserve=yes
//## end module%3EED769F0355.epilog
