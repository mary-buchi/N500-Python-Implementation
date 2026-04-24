//## begin module%3DD103B0010B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD103B0010B.cm

//## begin module%3DD103B0010B.cp preserve=no
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
//## end module%3DD103B0010B.cp

//## Module: EBWCstat%3DD103B0010B; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCstat.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DD103B0010B.additionalIncludes preserve=no
//## end module%3DD103B0010B.additionalIncludes

//## begin module%3DD103B0010B.includes preserve=yes
//## end module%3DD103B0010B.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBCOsync
#include "EBCOsync.h"
// EBPItype
#include "EBPItype.h"
// EBWCstat
#include "EBWCstat.h"
// EBWCimpl
#include "EBWCimpl.h"
// EBWCidnt
#include "EBWCidnt.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3DD103B0010B.declarations preserve=no
//## end module%3DD103B0010B.declarations

//## begin module%3DD103B0010B.additionalDeclarations preserve=yes
//## end module%3DD103B0010B.additionalDeclarations


// Class CWCState 


CWCState::CWCState()
  //## begin CWCState::CWCState%.hasinit preserve=no
      : m_pHWIntf(NULL)
  //## end CWCState::CWCState%.hasinit
  //## begin CWCState::CWCState%.initialization preserve=yes
  //## end CWCState::CWCState%.initialization
{
  //## begin CWCState::CWCState%.body preserve=yes
  m_pHWIntf = IHIInterface::GetInstance();
  //## end CWCState::CWCState%.body
}


CWCState::~CWCState()
{
  //## begin CWCState::~CWCState%.body preserve=yes
  //## end CWCState::~CWCState%.body
}



//## Other Operations (implementation)
CWCWedgeControlImplementation* CWCState::GetpContext (ICOStateMachineContext* p_pContext)
{
  //## begin CWCState::GetpContext%1053429541.body preserve=yes
  CWCWedgeControlImplementation* l_pContext = dynamic_cast<CWCWedgeControlImplementation*>(p_pContext);
  ASSERT(l_pContext != NULL);

  return l_pContext;
  //## end CWCState::GetpContext%1053429541.body
}

void CWCState::Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pSyncStartObj, CCOSyncObjectInt* p_pSyncExcObj)
{
  //## begin CWCState::Start%1037279662.body preserve=yes
  XCO_INVALID_STATE(WC_ID);
  //## end CWCState::Start%1037279662.body
}

void CWCState::SetProfile (ICOStateMachineContext* p_pContext, CPIWedgeControlProfile* p_pProfile)
{
  //## begin CWCState::SetProfile%1037951605.body preserve=yes
  XCO_INVALID_STATE(WC_ID);
  //## end CWCState::SetProfile%1037951605.body
}

void CWCState::Stop (ICOStateMachineContext* p_pContext)
{
  //## begin CWCState::Stop%1037951606.body preserve=yes
  XCO_INVALID_STATE(WC_ID);
  //## end CWCState::Stop%1037951606.body
}

void CWCState::SetConfiguration (ICOStateMachineContext* p_pContext, CPIWedgeControlConfig* p_pConfig)
{
  //## begin CWCState::SetConfiguration%1037951607.body preserve=yes
  XCO_INVALID_STATE(WC_ID);
  //## end CWCState::SetConfiguration%1037951607.body
}

void CWCState::Park (ICOStateMachineContext* p_pContext)
{
  //## begin CWCState::Park%1038217317.body preserve=yes
  XCO_INVALID_STATE(WC_ID);
  //XCO_INVALID_STATE(WC_ID);
  //## end CWCState::Park%1038217317.body
}

void CWCState::Referencing (ICOStateMachineContext* p_pContext)
{
  //## begin CWCState::Referencing%1038217318.body preserve=yes
  XCO_INVALID_STATE(WC_ID);
  //## end CWCState::Referencing%1038217318.body
}

void CWCState::Initialize (ICOStateMachineContext* p_pContext)
{
  //## begin CWCState::Initialize%1038217321.body preserve=yes
  XCO_INVALID_STATE(WC_ID);
  //## end CWCState::Initialize%1038217321.body
}

void CWCState::GetDacZeroCurrent (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj)
{
  //## begin CWCState::GetDacZeroCurrent%1149148978.body preserve=yes
  XCO_INVALID_STATE(WC_ID);
  //## end CWCState::GetDacZeroCurrent%1149148978.body
}

// Additional Declarations
  //## begin CWCState%3DD10434032E.declarations preserve=yes
  //## end CWCState%3DD10434032E.declarations

//## begin module%3DD103B0010B.epilog preserve=yes
//## end module%3DD103B0010B.epilog
