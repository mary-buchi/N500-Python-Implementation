//## begin module%3FCB352A0186.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FCB352A0186.cm

//## begin module%3FCB352A0186.cp preserve=no
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
//## end module%3FCB352A0186.cp

//## Module: EBWCemst%3FCB352A0186; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCemst.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FCB352A0186.additionalIncludes preserve=no
//## end module%3FCB352A0186.additionalIncludes

//## begin module%3FCB352A0186.includes preserve=yes
//## end module%3FCB352A0186.includes

// EBCOimct
#include "EBCOimct.h"
// EBWCconn
#include "EBWCconn.h"
// EBWCidle
#include "EBWCidle.h"
// EBHIintf
#include "EBHIintf.h"
// EBWCemst
#include "EBWCemst.h"
//## begin module%3FCB352A0186.declarations preserve=no
//## end module%3FCB352A0186.declarations

//## begin module%3FCB352A0186.additionalDeclarations preserve=yes
//## end module%3FCB352A0186.additionalDeclarations


// Class CWCStateEmergencyStop 

//## begin CWCStateEmergencyStop::pInstance%3FCB37680223.role preserve=no  public: static CWCStateEmergencyStop {1..1 -> 1..1RFHN}
CWCStateEmergencyStop *CWCStateEmergencyStop::m_pInstance;
//## end CWCStateEmergencyStop::pInstance%3FCB37680223.role


CWCStateEmergencyStop::CWCStateEmergencyStop()
  //## begin CWCStateEmergencyStop::CWCStateEmergencyStop%.hasinit preserve=no
  //## end CWCStateEmergencyStop::CWCStateEmergencyStop%.hasinit
  //## begin CWCStateEmergencyStop::CWCStateEmergencyStop%.initialization preserve=yes
  //## end CWCStateEmergencyStop::CWCStateEmergencyStop%.initialization
{
  //## begin CWCStateEmergencyStop::CWCStateEmergencyStop%.body preserve=yes
  //## end CWCStateEmergencyStop::CWCStateEmergencyStop%.body
}


CWCStateEmergencyStop::~CWCStateEmergencyStop()
{
  //## begin CWCStateEmergencyStop::~CWCStateEmergencyStop%.body preserve=yes
  //## end CWCStateEmergencyStop::~CWCStateEmergencyStop%.body
}



//## Other Operations (implementation)
void CWCStateEmergencyStop::Create ()
{
  //## begin CWCStateEmergencyStop::Create%1070263834.body preserve=yes
  ASSERT(m_pInstance == NULL);
  m_pInstance = new CWCStateEmergencyStop();
  //## end CWCStateEmergencyStop::Create%1070263834.body
}

CWCStateEmergencyStop* CWCStateEmergencyStop::GetInstance ()
{
  //## begin CWCStateEmergencyStop::GetInstance%1070263835.body preserve=yes
  ASSERT(m_pInstance != NULL);
  return m_pInstance;
  //## end CWCStateEmergencyStop::GetInstance%1070263835.body
}

void CWCStateEmergencyStop::Delete ()
{
  //## begin CWCStateEmergencyStop::Delete%1070263836.body preserve=yes
  if(m_pInstance)
    delete m_pInstance;
  m_pInstance = NULL;
  //## end CWCStateEmergencyStop::Delete%1070263836.body
}

void CWCStateEmergencyStop::Shutdown (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateEmergencyStop::Shutdown%1070263837.body preserve=yes
	p_pContext->ChangeState(CWCStateCreated::GetInstance());
  //## end CWCStateEmergencyStop::Shutdown%1070263837.body
}

void CWCStateEmergencyStop::Do (ICOStateMachineContext* p_pContext)
{
  //## begin CWCStateEmergencyStop::Do%1070263838.body preserve=yes
	try
  {
    IHIInterface::GetInstance()->WCEmergencyStop();
    p_pContext->ChangeState(CWCStateNotConnected::GetInstance());
  }
  catch(...)
  {
    throw;
  }
  //## end CWCStateEmergencyStop::Do%1070263838.body
}

// Additional Declarations
  //## begin CWCStateEmergencyStop%3FCB349E009C.declarations preserve=yes
  //## end CWCStateEmergencyStop%3FCB349E009C.declarations

//## begin module%3FCB352A0186.epilog preserve=yes
//## end module%3FCB352A0186.epilog
