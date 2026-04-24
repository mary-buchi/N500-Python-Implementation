//## begin module%3DE5EDE503AE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EDE503AE.cm

//## begin module%3DE5EDE503AE.cp preserve=no
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
//## end module%3DE5EDE503AE.cp

//## Module: EBTCstat%3DE5EDE503AE; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCstat.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EDE503AE.additionalIncludes preserve=no
//## end module%3DE5EDE503AE.additionalIncludes

//## begin module%3DE5EDE503AE.includes preserve=yes
//## end module%3DE5EDE503AE.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBPItype
#include "EBPItype.h"
// EBTClogic
#include "EBTClogic.h"
// EBTCstat
#include "EBTCstat.h"
// EBTCimpl
#include "EBTCimpl.h"
// EBTCident
#include "EBTCident.h"


//## begin module%3DE5EDE503AE.declarations preserve=no
//## end module%3DE5EDE503AE.declarations

//## begin module%3DE5EDE503AE.additionalDeclarations preserve=yes
//## end module%3DE5EDE503AE.additionalDeclarations


// Class CTCState 

CTCState::CTCState()
  //## begin CTCState::CTCState%.hasinit preserve=no
  //## end CTCState::CTCState%.hasinit
  //## begin CTCState::CTCState%.initialization preserve=yes
  //## end CTCState::CTCState%.initialization
{
  //## begin CTCState::CTCState%.body preserve=yes
  //## end CTCState::CTCState%.body
}


CTCState::~CTCState()
{
  //## begin CTCState::~CTCState%.body preserve=yes
  //## end CTCState::~CTCState%.body
}



//## Other Operations (implementation)
void CTCState::SetProfile (ICOStateMachineContext* p_pContext, CPITemperatureControlProfile* p_pProfile)
{
  //## begin CTCState::SetProfile%1038899345.body preserve=yes
    CO_TRACE(TC_ID, _T("TC - SetProfile"));
	XCO_INVALID_STATE(TC_ID);
  //## end CTCState::SetProfile%1038899345.body
}

void CTCState::SetConfiguration (ICOStateMachineContext* p_pContext, CPITemperatureControlConfig* p_pConfig)
{
  //## begin CTCState::SetConfiguration%1038899346.body preserve=yes
    CO_TRACE(TC_ID, _T("TC SetConfiguration()"));
	XCO_INVALID_STATE(TC_ID);
  //## end CTCState::SetConfiguration%1038899346.body
}

void CTCState::Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pIncidentSyncObj)
{
  //## begin CTCState::Start%1038899347.body preserve=yes
    CO_TRACE(TC_ID, _T("TC - Start"));
	XCO_INVALID_STATE(TC_ID);
  //## end CTCState::Start%1038899347.body
}

void CTCState::Stop (ICOStateMachineContext* p_pContext)
{
  //## begin CTCState::Stop%1038899348.body preserve=yes
    CO_TRACE(TC_ID, _T("TC - Stop"));
	XCO_INVALID_STATE(TC_ID);
  //## end CTCState::Stop%1038899348.body
}

void CTCState::GetTemperature (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj)
{
  //## begin CTCState::GetTemperature%1038899349.body preserve=yes
	CO_TRACE(TC_ID, _T("TC - GetTemperature. Not supported. Take the sensor directly. \n"));
	XCO_INVALID_STATE(TC_ID);
  //## end CTCState::GetTemperature%1038899349.body
}

CTCTemperatureControlImplementation* CTCState::GetpContext (ICOStateMachineContext* p_pContext)
{
  //## begin CTCState::GetpContext%1045561405.body preserve=yes
	CTCTemperatureControlImplementation* l_pContext;
	l_pContext = dynamic_cast<CTCTemperatureControlImplementation*>(p_pContext);
	ASSERT(l_pContext != NULL);
	return l_pContext;
  //## end CTCState::GetpContext%1045561405.body
}

void CTCState::CellUndocked (ICOStateMachineContext* p_pContext)
{
  //## begin CTCState::CellUndocked%1216975785.body preserve=yes
	CO_TRACE(TC_ID, _T("TC - CellUndocked."));
	XCO_INVALID_STATE(TC_ID);
  //## end CTCState::CellUndocked%1216975785.body
}

// Additional Declarations
  //## begin CTCState%3DEC7197017A.declarations preserve=yes
  //## end CTCState%3DEC7197017A.declarations

//## begin module%3DE5EDE503AE.epilog preserve=yes
//## end module%3DE5EDE503AE.epilog
