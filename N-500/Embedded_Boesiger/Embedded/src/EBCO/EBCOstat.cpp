//## begin module%3B9147060340.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B9147060340.cm

//## begin module%3B9147060340.cp preserve=no
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
//## end module%3B9147060340.cp

//## Module: EBCOstat%3B9147060340; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOstat.cpp

// stdafx
#include "stdafx.h"
//## begin module%3B9147060340.additionalIncludes preserve=no
//## end module%3B9147060340.additionalIncludes

//## begin module%3B9147060340.includes preserve=yes
//## end module%3B9147060340.includes

// EBCOimct
#include "EBCOimct.h"
// EBCOidnt
#include "EBCOidnt.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBCOstat
#include "EBCOstat.h"


//## begin module%3B9147060340.declarations preserve=no
//## end module%3B9147060340.declarations

//## begin module%3B9147060340.additionalDeclarations preserve=yes
#include <typeinfo.h>
//## end module%3B9147060340.additionalDeclarations


// Class CCOState 




CCOState::CCOState()
  //## begin CCOState::CCOState%.hasinit preserve=no
  //## end CCOState::CCOState%.hasinit
  //## begin CCOState::CCOState%.initialization preserve=yes
  //## end CCOState::CCOState%.initialization
{
  //## begin CCOState::CCOState%.body preserve=yes
  //## end CCOState::CCOState%.body
}


CCOState::~CCOState()
{
  //## begin CCOState::~CCOState%.body preserve=yes
  //## end CCOState::~CCOState%.body
}



//## Other Operations (implementation)
CString CCOState::GetStateName ()
{
  //## begin CCOState::GetStateName%1034324674.body preserve=yes
    const type_info& l_TypeInfo = typeid(*this);

    return CString(l_TypeInfo.name());
  //## end CCOState::GetStateName%1034324674.body
}

void CCOState::Enter (ICOStateMachineContext* p_pContext)
{
  //## begin CCOState::Enter%1034324675.body preserve=yes
  //## end CCOState::Enter%1034324675.body
}

void CCOState::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CCOState::Do%1034324676.body preserve=yes
  //## end CCOState::Do%1034324676.body
}

void CCOState::Exit (ICOStateMachineContext* p_pContext)
{
  //## begin CCOState::Exit%1034324677.body preserve=yes
  //## end CCOState::Exit%1034324677.body
}

CCOState* CCOState::SaveHistory (ICOStateMachineContext* p_pContext)
{
  //## begin CCOState::SaveHistory%1034324678.body preserve=yes
    return NULL;
  //## end CCOState::SaveHistory%1034324678.body
}

void CCOState::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CCOState::Startup%999456380.body preserve=yes
    XCO_INVALID_STATE(CO_ID);
  //## end CCOState::Startup%999456380.body
}

void CCOState::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CCOState::Shutdown%999456381.body preserve=yes
    XCO_INVALID_STATE(CO_ID);
  //## end CCOState::Shutdown%999456381.body
}

void CCOState::OnTimer (ICOStateMachineContext* p_pContext)
{
  //## begin CCOState::OnTimer%1053348763.body preserve=yes
    XCO_INVALID_STATE(CO_ID);
  //## end CCOState::OnTimer%1053348763.body
}

void CCOState::CleanupStop (ICOStateMachineContext* p_pContext)
{
  //## begin CCOState::CleanupStop%1001240160.body preserve=yes
    XCO_INVALID_STATE(CO_ID);
  //## end CCOState::CleanupStop%1001240160.body
}

void CCOState::CleanupInitialize (ICOStateMachineContext* p_pContext)
{
  //## begin CCOState::CleanupInitialize%1001240161.body preserve=yes
    XCO_INVALID_STATE(CO_ID);
  //## end CCOState::CleanupInitialize%1001240161.body
}

void CCOState::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CCOState::ConnectionEstablished%1055313961.body preserve=yes
    XCO_INVALID_STATE(CO_ID);
  //## end CCOState::ConnectionEstablished%1055313961.body
}

void CCOState::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CCOState::ConnectionLost%1055313962.body preserve=yes
    XCO_INVALID_STATE(CO_ID);
  //## end CCOState::ConnectionLost%1055313962.body
}

// Additional Declarations
  //## begin CCOState%3B9281FC00F2.declarations preserve=yes
  //## end CCOState%3B9281FC00F2.declarations

//## begin module%3B9147060340.epilog preserve=yes
//## end module%3B9147060340.epilog
