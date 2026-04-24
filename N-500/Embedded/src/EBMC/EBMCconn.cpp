//## begin module%3F60194201B5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F60194201B5.cm

//## begin module%3F60194201B5.cp preserve=no
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
//## end module%3F60194201B5.cp

//## Module: EBMCconn%3F60194201B5; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCconn.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F60194201B5.additionalIncludes preserve=no
//## end module%3F60194201B5.additionalIncludes

//## begin module%3F60194201B5.includes preserve=yes
//## end module%3F60194201B5.includes

// EBCOimct
#include "EBCOimct.h"
// EBMCconn
#include "EBMCconn.h"
// EBMCproc
#include "EBMCproc.h"
// EBMCidle
#include "EBMCidle.h"
//## begin module%3F60194201B5.declarations preserve=no
//## end module%3F60194201B5.declarations

//## begin module%3F60194201B5.additionalDeclarations preserve=yes
//## end module%3F60194201B5.additionalDeclarations


// Class CMCStateNotConnected 

//## begin CMCStateNotConnected::pInstance%3F60199A03BA.role preserve=no  public: static CMCStateNotConnected {1..1 -> 1..1RFHN}
CMCStateNotConnected *CMCStateNotConnected::m_pInstance;
//## end CMCStateNotConnected::pInstance%3F60199A03BA.role


CMCStateNotConnected::CMCStateNotConnected()
  //## begin CMCStateNotConnected::CMCStateNotConnected%.hasinit preserve=no
  //## end CMCStateNotConnected::CMCStateNotConnected%.hasinit
  //## begin CMCStateNotConnected::CMCStateNotConnected%.initialization preserve=yes
  //## end CMCStateNotConnected::CMCStateNotConnected%.initialization
{
  //## begin CMCStateNotConnected::CMCStateNotConnected%.body preserve=yes
  //## end CMCStateNotConnected::CMCStateNotConnected%.body
}


CMCStateNotConnected::~CMCStateNotConnected()
{
  //## begin CMCStateNotConnected::~CMCStateNotConnected%.body preserve=yes
  //## end CMCStateNotConnected::~CMCStateNotConnected%.body
}



//## Other Operations (implementation)
CMCStateNotConnected* CMCStateNotConnected::GetInstance ()
{
  //## begin CMCStateNotConnected::GetInstance%1063260195.body preserve=yes
    ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CMCStateNotConnected::GetInstance%1063260195.body
}

void CMCStateNotConnected::Delete ()
{
  //## begin CMCStateNotConnected::Delete%1063260196.body preserve=yes
    if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CMCStateNotConnected::Delete%1063260196.body
}

void CMCStateNotConnected::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateNotConnected::ConnectionEstablished%1063260198.body preserve=yes
	  p_pContext->ChangeState(CMCStateInitialized::GetInstance());
  //## end CMCStateNotConnected::ConnectionEstablished%1063260198.body
}

void CMCStateNotConnected::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CMCStateNotConnected::Shutdown%1063260199.body preserve=yes
	CMCStateProfile::GetInstance()->SetpProfile(NULL);
	p_pContext->ChangeState(CMCStateCreated::GetInstance());
  //## end CMCStateNotConnected::Shutdown%1063260199.body
}

void CMCStateNotConnected::Create ()
{
  //## begin CMCStateNotConnected::Create%1063260204.body preserve=yes
    ASSERT(m_pInstance == NULL);
    m_pInstance = new CMCStateNotConnected();
  //## end CMCStateNotConnected::Create%1063260204.body
}

// Additional Declarations
  //## begin CMCStateNotConnected%3F60190A006D.declarations preserve=yes
  //## end CMCStateNotConnected%3F60190A006D.declarations

//## begin module%3F60194201B5.epilog preserve=yes
//## end module%3F60194201B5.epilog
