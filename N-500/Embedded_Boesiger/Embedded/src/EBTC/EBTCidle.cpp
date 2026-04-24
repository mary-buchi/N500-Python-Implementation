//## begin module%3DE5EDEB038F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EDEB038F.cm

//## begin module%3DE5EDEB038F.cp preserve=no
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
//## end module%3DE5EDEB038F.cp

//## Module: EBTCidle%3DE5EDEB038F; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCidle.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EDEB038F.additionalIncludes preserve=no
//## end module%3DE5EDEB038F.additionalIncludes

//## begin module%3DE5EDEB038F.includes preserve=yes
//## end module%3DE5EDEB038F.includes

// EBCOimct
#include "EBCOimct.h"
// EBTCconfig
#include "EBTCconfig.h"
// EBTCidle
#include "EBTCidle.h"
//## begin module%3DE5EDEB038F.declarations preserve=no
//## end module%3DE5EDEB038F.declarations

//## begin module%3DE5EDEB038F.additionalDeclarations preserve=yes
//## end module%3DE5EDEB038F.additionalDeclarations


// Class CTCStateCreated 

//## begin CTCStateCreated::pInstance%3DEC6F2901AA.role preserve=no  public: static CTCStateCreated {1..1 -> 1..1RFHN}
CTCStateCreated *CTCStateCreated::m_pInstance;
//## end CTCStateCreated::pInstance%3DEC6F2901AA.role


CTCStateCreated::CTCStateCreated()
  //## begin CTCStateCreated::CTCStateCreated%.hasinit preserve=no
  //## end CTCStateCreated::CTCStateCreated%.hasinit
  //## begin CTCStateCreated::CTCStateCreated%.initialization preserve=yes
  //## end CTCStateCreated::CTCStateCreated%.initialization
{
  //## begin CTCStateCreated::CTCStateCreated%.body preserve=yes
  //## end CTCStateCreated::CTCStateCreated%.body
}


CTCStateCreated::~CTCStateCreated()
{
  //## begin CTCStateCreated::~CTCStateCreated%.body preserve=yes
  //## end CTCStateCreated::~CTCStateCreated%.body
}



//## Other Operations (implementation)
void CTCStateCreated::Create ()
{
  //## begin CTCStateCreated::Create%1038899331.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CTCStateCreated();
  //## end CTCStateCreated::Create%1038899331.body
}

void CTCStateCreated::Delete ()
{
  //## begin CTCStateCreated::Delete%1044522140.body preserve=yes
    delete m_pInstance;
	m_pInstance = NULL;
  //## end CTCStateCreated::Delete%1044522140.body
}

CTCStateCreated* CTCStateCreated::GetInstance ()
{
  //## begin CTCStateCreated::GetInstance%1038899333.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CTCStateCreated::GetInstance%1038899333.body
}

void CTCStateCreated::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateCreated::Startup%1044629618.body preserve=yes
	p_pContext->ChangeState(CTCStateConfigNotSet::GetInstance());
  //## end CTCStateCreated::Startup%1044629618.body
}

void CTCStateCreated::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateCreated::ConnectionEstablished%1063223345.body preserve=yes
  //## end CTCStateCreated::ConnectionEstablished%1063223345.body
}

void CTCStateCreated::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CTCStateCreated::ConnectionLost%1063223346.body preserve=yes
  //## end CTCStateCreated::ConnectionLost%1063223346.body
}

// Additional Declarations
  //## begin CTCStateCreated%3DEC6EBA03DB.declarations preserve=yes
  //## end CTCStateCreated%3DEC6EBA03DB.declarations

//## begin module%3DE5EDEB038F.epilog preserve=yes
//## end module%3DE5EDEB038F.epilog
