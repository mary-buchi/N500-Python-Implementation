//## begin module%3EED769F035F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F035F.cm

//## begin module%3EED769F035F.cp preserve=no
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
//## end module%3EED769F035F.cp

//## Module: EBPCstat%3EED769F035F; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCstat.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F035F.additionalIncludes preserve=no
//## end module%3EED769F035F.additionalIncludes

//## begin module%3EED769F035F.includes preserve=yes
//## end module%3EED769F035F.includes

// EBPCstat
#include "EBPCstat.h"
// EBPItype
#include "EBPItype.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBPCimpl
#include "EBPCimpl.h"
// EBPCident
#include "EBPCident.h"


//## begin module%3EED769F035F.declarations preserve=no
//## end module%3EED769F035F.declarations

//## begin module%3EED769F035F.additionalDeclarations preserve=yes
//## end module%3EED769F035F.additionalDeclarations


// Class CPCState 

CPCState::CPCState()
  //## begin CPCState::CPCState%.hasinit preserve=no
  //## end CPCState::CPCState%.hasinit
  //## begin CPCState::CPCState%.initialization preserve=yes
  //## end CPCState::CPCState%.initialization
{
  //## begin CPCState::CPCState%.body preserve=yes
  //## end CPCState::CPCState%.body
}


CPCState::~CPCState()
{
  //## begin CPCState::~CPCState%.body preserve=yes
  //## end CPCState::~CPCState%.body
}



//## Other Operations (implementation)
void CPCState::SetProfile (ICOStateMachineContext* p_pContext, CPIPowerControlProfile* p_pProfile)
{
  //## begin CPCState::SetProfile%1038899345.body preserve=yes
	XCO_INVALID_STATE(PC_ID);
  //## end CPCState::SetProfile%1038899345.body
}

void CPCState::SetConfiguration (ICOStateMachineContext* p_pContext, CPIPowerControlConfig* p_pConfig)
{
  //## begin CPCState::SetConfiguration%1038899346.body preserve=yes
	XCO_INVALID_STATE(PC_ID);
  //## end CPCState::SetConfiguration%1038899346.body
}

void CPCState::Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObject)
{
  //## begin CPCState::Start%1038899347.body preserve=yes
	XCO_INVALID_STATE(PC_ID);
  //## end CPCState::Start%1038899347.body
}

void CPCState::Stop (ICOStateMachineContext* p_pContext)
{
  //## begin CPCState::Stop%1038899348.body preserve=yes
	XCO_INVALID_STATE(PC_ID);
  //## end CPCState::Stop%1038899348.body
}

CPCPowerControlImplementation* CPCState::GetpImplementation (ICOStateMachineContext* p_pContext)
{
  //## begin CPCState::GetpImplementation%1045561405.body preserve=yes
	CPCPowerControlImplementation* l_pContext;
	l_pContext = dynamic_cast<CPCPowerControlImplementation*>(p_pContext);
	ASSERT(l_pContext != NULL);
	return l_pContext;
  //## end CPCState::GetpImplementation%1045561405.body
}

void CPCState::PowerOff (ICOStateMachineContext* p_pContext)
{
  //## begin CPCState::PowerOff%1076339199.body preserve=yes
	XCO_INVALID_STATE(PC_ID);
  //## end CPCState::PowerOff%1076339199.body
}

void CPCState::PowerOn (ICOStateMachineContext* p_pContext)
{
  //## begin CPCState::PowerOn%1076339200.body preserve=yes
	XCO_INVALID_STATE(PC_ID);
  //## end CPCState::PowerOn%1076339200.body
}

// Additional Declarations
  //## begin CPCState%3EED76CC0377.declarations preserve=yes
  //## end CPCState%3EED76CC0377.declarations

//## begin module%3EED769F035F.epilog preserve=yes
//## end module%3EED769F035F.epilog
