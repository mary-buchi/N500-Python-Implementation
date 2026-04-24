//## begin module%3DAAE82E019A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAE82E019A.cm

//## begin module%3DAAE82E019A.cp preserve=no
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
//## end module%3DAAE82E019A.cp

//## Module: EBMCidle%3DAAE82E019A; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCidle.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DAAE82E019A.additionalIncludes preserve=no
//## end module%3DAAE82E019A.additionalIncludes

//## begin module%3DAAE82E019A.includes preserve=yes
#include <stdlib.h>
//## end module%3DAAE82E019A.includes

// EBCOimct
#include "EBCOimct.h"
// EBPItype
#include "EBPItype.h"
// EBMCproc
#include "EBMCproc.h"
// EBMCcomd
#include "EBMCcomd.h"
// EBMCidle
#include "EBMCidle.h"
//## begin module%3DAAE82E019A.declarations preserve=no
//## end module%3DAAE82E019A.declarations

//## begin module%3DAAE82E019A.additionalDeclarations preserve=yes
//## end module%3DAAE82E019A.additionalDeclarations


// Class CMCStateCreated 

//## begin CMCStateCreated::pInstance%3DAAE85103AE.role preserve=no  public: static CMCStateCreated {1..1 -> 1..1RFHN}
CMCStateCreated *CMCStateCreated::m_pInstance = NULL;
//## end CMCStateCreated::pInstance%3DAAE85103AE.role


CMCStateCreated::CMCStateCreated()
  //## begin CMCStateCreated::CMCStateCreated%.hasinit preserve=no
  //## end CMCStateCreated::CMCStateCreated%.hasinit
  //## begin CMCStateCreated::CMCStateCreated%.initialization preserve=yes
  //## end CMCStateCreated::CMCStateCreated%.initialization
{
  //## begin CMCStateCreated::CMCStateCreated%.body preserve=yes
  //## end CMCStateCreated::CMCStateCreated%.body
}


CMCStateCreated::~CMCStateCreated()
{
  //## begin CMCStateCreated::~CMCStateCreated%.body preserve=yes
  //## end CMCStateCreated::~CMCStateCreated%.body
}



//## Other Operations (implementation)
void CMCStateCreated::Delete ()
{
  //## begin CMCStateCreated::Delete%1034575115.body preserve=yes
    delete m_pInstance;
    m_pInstance = NULL;
  //## end CMCStateCreated::Delete%1034575115.body
}

void CMCStateCreated::Create ()
{
  //## begin CMCStateCreated::Create%1034575114.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CMCStateCreated();
  //## end CMCStateCreated::Create%1034575114.body
}

CMCStateCreated* CMCStateCreated::GetInstance ()
{
  //## begin CMCStateCreated::GetInstance%1034575116.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CMCStateCreated::GetInstance%1034575116.body
}

void CMCStateCreated::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateCreated::Startup%1034922745.body preserve=yes
  p_pContext->ChangeState(CMCStateProfileNotAssign::GetInstance());
  //## end CMCStateCreated::Startup%1034922745.body
}

void CMCStateCreated::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateCreated::ConnectionEstablished%1063223349.body preserve=yes
  //## end CMCStateCreated::ConnectionEstablished%1063223349.body
}

void CMCStateCreated::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateCreated::ConnectionLost%1063223350.body preserve=yes
  //## end CMCStateCreated::ConnectionLost%1063223350.body
}

// Additional Declarations
  //## begin CMCStateCreated%3DAAE83A01D9.declarations preserve=yes
  //## end CMCStateCreated%3DAAE83A01D9.declarations

//## begin module%3DAAE82E019A.epilog preserve=yes
//## end module%3DAAE82E019A.epilog
