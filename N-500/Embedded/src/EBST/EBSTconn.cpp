//## begin module%3EE5C9C50380.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE5C9C50380.cm

//## begin module%3EE5C9C50380.cp preserve=no
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
//## end module%3EE5C9C50380.cp

//## Module: EBSTconn%3EE5C9C50380; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTconn.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE5C9C50380.additionalIncludes preserve=no
//## end module%3EE5C9C50380.additionalIncludes

//## begin module%3EE5C9C50380.includes preserve=yes
//## end module%3EE5C9C50380.includes

// EBSTidnt
#include "EBSTidnt.h"
// EBCOimct
#include "EBCOimct.h"
// EBSTlimit
#include "EBSTlimit.h"
// EBSTidle
#include "EBSTidle.h"
// EBSTimpl
#include "EBSTimpl.h"
// EBSThwconn
#include "EBSThwconn.h"
// EBSTconn
#include "EBSTconn.h"
//## begin module%3EE5C9C50380.declarations preserve=no
//## end module%3EE5C9C50380.declarations

//## begin module%3EE5C9C50380.additionalDeclarations preserve=yes
//## end module%3EE5C9C50380.additionalDeclarations


// Class CSTStateConnectionNotConnected 

//## begin CSTStateConnectionNotConnected::pInstance%3EE5CAC10073.role preserve=no  public: static CSTStateConnectionNotConnected {1..1 -> 1..1RFHN}
CSTStateConnectionNotConnected *CSTStateConnectionNotConnected::m_pInstance;
//## end CSTStateConnectionNotConnected::pInstance%3EE5CAC10073.role


CSTStateConnectionNotConnected::CSTStateConnectionNotConnected()
  //## begin CSTStateConnectionNotConnected::CSTStateConnectionNotConnected%.hasinit preserve=no
  //## end CSTStateConnectionNotConnected::CSTStateConnectionNotConnected%.hasinit
  //## begin CSTStateConnectionNotConnected::CSTStateConnectionNotConnected%.initialization preserve=yes
  //## end CSTStateConnectionNotConnected::CSTStateConnectionNotConnected%.initialization
{
  //## begin CSTStateConnectionNotConnected::CSTStateConnectionNotConnected%.body preserve=yes
  //## end CSTStateConnectionNotConnected::CSTStateConnectionNotConnected%.body
}


CSTStateConnectionNotConnected::~CSTStateConnectionNotConnected()
{
  //## begin CSTStateConnectionNotConnected::~CSTStateConnectionNotConnected%.body preserve=yes
  //## end CSTStateConnectionNotConnected::~CSTStateConnectionNotConnected%.body
}



//## Other Operations (implementation)
void CSTStateConnectionNotConnected::Create ()
{
  //## begin CSTStateConnectionNotConnected::Create%1055247437.body preserve=yes
	m_pInstance = new CSTStateConnectionNotConnected();
  //## end CSTStateConnectionNotConnected::Create%1055247437.body
}

void CSTStateConnectionNotConnected::Delete ()
{
  //## begin CSTStateConnectionNotConnected::Delete%1055247438.body preserve=yes
	if(m_pInstance)
      delete m_pInstance;
    m_pInstance = NULL;
  //## end CSTStateConnectionNotConnected::Delete%1055247438.body
}

CSTStateConnectionNotConnected* CSTStateConnectionNotConnected::GetInstance ()
{
  //## begin CSTStateConnectionNotConnected::GetInstance%1055247439.body preserve=yes
	ASSERT(m_pInstance != NULL);
    return m_pInstance;
  //## end CSTStateConnectionNotConnected::GetInstance%1055247439.body
}

void CSTStateConnectionNotConnected::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateConnectionNotConnected::Do%1055247440.body preserve=yes

	// Stop worker thread limit switches.
	GetpContext(p_pContext)->GetpLimitHandler()->Stop();

	// Stop the motor.
	GetpContext(p_pContext)->GetpHwConnection()->Moving(STOP);

  //## end CSTStateConnectionNotConnected::Do%1055247440.body
}

void CSTStateConnectionNotConnected::ConnectionEstablished (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateConnectionNotConnected::ConnectionEstablished%1056003014.body preserve=yes
	p_pContext->ChangeState(CSTStateIdle::GetInstance());
  //## end CSTStateConnectionNotConnected::ConnectionEstablished%1056003014.body
}

void CSTStateConnectionNotConnected::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CSTStateConnectionNotConnected::Shutdown%1064494053.body preserve=yes
	p_pContext->ChangeState(CSTStateCreated::GetInstance());
  //## end CSTStateConnectionNotConnected::Shutdown%1064494053.body
}

// Additional Declarations
  //## begin CSTStateConnectionNotConnected%3EE5C6A900FF.declarations preserve=yes
  //## end CSTStateConnectionNotConnected%3EE5C6A900FF.declarations

//## begin module%3EE5C9C50380.epilog preserve=yes
//## end module%3EE5C9C50380.epilog
