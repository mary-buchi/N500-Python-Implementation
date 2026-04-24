//## begin module%3DAAE3F201C9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAE3F201C9.cm

//## begin module%3DAAE3F201C9.cp preserve=no
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
//## end module%3DAAE3F201C9.cp

//## Module: EBMCstat%3DAAE3F201C9; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCstat.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DAAE3F201C9.additionalIncludes preserve=no
//## end module%3DAAE3F201C9.additionalIncludes

//## begin module%3DAAE3F201C9.includes preserve=yes
//## end module%3DAAE3F201C9.includes

// EBCOexcp
#include "EBCOexcp.h"
// EBMCstat
#include "EBMCstat.h"
// EBMCimpl
#include "EBMCimpl.h"
// EBMCidnt
#include "EBMCidnt.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3DAAE3F201C9.declarations preserve=no
//## end module%3DAAE3F201C9.declarations

//## begin module%3DAAE3F201C9.additionalDeclarations preserve=yes
//## end module%3DAAE3F201C9.additionalDeclarations


// Class CMCState 

CMCState::CMCState()
  //## begin CMCState::CMCState%.hasinit preserve=no
  //## end CMCState::CMCState%.hasinit
  //## begin CMCState::CMCState%.initialization preserve=yes
  //## end CMCState::CMCState%.initialization
{
  //## begin CMCState::CMCState%.body preserve=yes
  //## end CMCState::CMCState%.body
}


CMCState::~CMCState()
{
  //## begin CMCState::~CMCState%.body preserve=yes
  //## end CMCState::~CMCState%.body
}



//## Other Operations (implementation)
void CMCState::GetDataPackage (ICOStateMachineContext* p_pContext, CPISyncObjDataPackage* p_pClientSyncObj)
{
  //## begin CMCState::GetDataPackage%1034835010.body preserve=yes
    XCO_INVALID_STATE(MC_ID);
  //## end CMCState::GetDataPackage%1034835010.body
}

void CMCState::Stop (ICOStateMachineContext* p_pContext)
{
  //## begin CMCState::Stop%1038405591.body preserve=yes
    XCO_INVALID_STATE(MC_ID);
  //## end CMCState::Stop%1038405591.body
}

void CMCState::Start (ICOStateMachineContext* p_pContext, UINT p_uiCycleID)
{
  //## begin CMCState::Start%1038405592.body preserve=yes
    XCO_INVALID_STATE(MC_ID);
  //## end CMCState::Start%1038405592.body
}

void CMCState::SetProfile (ICOStateMachineContext* p_pContext, CPIMeasurementChannelProfile* p_pProfile)
{
  //## begin CMCState::SetProfile%1038405593.body preserve=yes
    XCO_INVALID_STATE(MC_ID);
  //## end CMCState::SetProfile%1038405593.body
}

void CMCState::Initialize (ICOStateMachineContext* p_pContext)
{
  //## begin CMCState::Initialize%1038405594.body preserve=yes
    XCO_INVALID_STATE(MC_ID);
  //## end CMCState::Initialize%1038405594.body
}

CMCMeasurementChannelImplementation* CMCState::GetpContext (ICOStateMachineContext* p_pContext)
{
  //## begin CMCState::GetpContext%1066894462.body preserve=yes
    CMCMeasurementChannelImplementation* l_pContext = dynamic_cast<CMCMeasurementChannelImplementation*>(p_pContext);
    ASSERT(l_pContext != NULL);

    return l_pContext;
  //## end CMCState::GetpContext%1066894462.body
}

// Additional Declarations
  //## begin CMCState%3DAAE7F800FE.declarations preserve=yes
  //## end CMCState%3DAAE7F800FE.declarations

//## begin module%3DAAE3F201C9.epilog preserve=yes
//## end module%3DAAE3F201C9.epilog
