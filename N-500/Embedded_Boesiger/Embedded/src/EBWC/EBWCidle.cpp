//## begin module%3DD1045D0292.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD1045D0292.cm

//## begin module%3DD1045D0292.cp preserve=no
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
//## end module%3DD1045D0292.cp

//## Module: EBWCidle%3DD1045D0292; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCidle.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DD1045D0292.additionalIncludes preserve=no
//## end module%3DD1045D0292.additionalIncludes

//## begin module%3DD1045D0292.includes preserve=yes
//## end module%3DD1045D0292.includes

// EBCOimct
#include "EBCOimct.h"
// EBWCconf
#include "EBWCconf.h"
// EBWCcomd
#include "EBWCcomd.h"
// EBWCidle
#include "EBWCidle.h"
// EBWCidnt
#include "EBWCidnt.h"
//## begin module%3DD1045D0292.declarations preserve=no
//## end module%3DD1045D0292.declarations

//## begin module%3DD1045D0292.additionalDeclarations preserve=yes
//## end module%3DD1045D0292.additionalDeclarations


// Class CWCStateCreated 

//## begin CWCStateCreated::pInstance%3DD104D500AF.role preserve=no  public: static CWCStateCreated {1..1 -> 1..1RFHN}
CWCStateCreated *CWCStateCreated::m_pInstance;
//## end CWCStateCreated::pInstance%3DD104D500AF.role


CWCStateCreated::CWCStateCreated()
  //## begin CWCStateCreated::CWCStateCreated%.hasinit preserve=no
  //## end CWCStateCreated::CWCStateCreated%.hasinit
  //## begin CWCStateCreated::CWCStateCreated%.initialization preserve=yes
  //## end CWCStateCreated::CWCStateCreated%.initialization
{
  //## begin CWCStateCreated::CWCStateCreated%.body preserve=yes
  //## end CWCStateCreated::CWCStateCreated%.body
}


CWCStateCreated::~CWCStateCreated()
{
  //## begin CWCStateCreated::~CWCStateCreated%.body preserve=yes
  //## end CWCStateCreated::~CWCStateCreated%.body
}



//## Other Operations (implementation)
void CWCStateCreated::Create ()
{
  //## begin CWCStateCreated::Create%1037094246.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CWCStateCreated();
  //## end CWCStateCreated::Create%1037094246.body
}

void CWCStateCreated::Delete ()
{
  //## begin CWCStateCreated::Delete%1037094247.body preserve=yes
    if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CWCStateCreated::Delete%1037094247.body
}

CWCStateCreated* CWCStateCreated::GetInstance ()
{
  //## begin CWCStateCreated::GetInstance%1037094248.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CWCStateCreated::GetInstance%1037094248.body
}

void CWCStateCreated::Startup (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateCreated::Startup%1037094249.body preserve=yes
    p_pContext->ChangeState(CWCStateConfigNotAssign::GetInstance());
    CO_TRACE(WC_ID, _T("WC State Created - Startup executed\n"));
  //## end CWCStateCreated::Startup%1037094249.body
}

void CWCStateCreated::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateCreated::Shutdown%1037094250.body preserve=yes
    CO_TRACE(WC_ID, _T("WC State Created - Shutdown executed\n"));
  //## end CWCStateCreated::Shutdown%1037094250.body
}

void CWCStateCreated::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateCreated::ConnectionEstablished%1063223351.body preserve=yes
  //## end CWCStateCreated::ConnectionEstablished%1063223351.body
}

void CWCStateCreated::ConnectionLost (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateCreated::ConnectionLost%1063223352.body preserve=yes
  //## end CWCStateCreated::ConnectionLost%1063223352.body
}

// Additional Declarations
  //## begin CWCStateCreated%3DD10496013A.declarations preserve=yes
  //## end CWCStateCreated%3DD10496013A.declarations

//## begin module%3DD1045D0292.epilog preserve=yes
//## end module%3DD1045D0292.epilog
