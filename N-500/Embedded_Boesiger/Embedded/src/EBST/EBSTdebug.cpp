//## begin module%3E75E78D0302.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E75E78D0302.cm

//## begin module%3E75E78D0302.cp preserve=no
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
//## end module%3E75E78D0302.cp

//## Module: EBSTdebug%3E75E78D0302; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTdebug.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E75E78D0302.additionalIncludes preserve=no
//## end module%3E75E78D0302.additionalIncludes

//## begin module%3E75E78D0302.includes preserve=yes
//## end module%3E75E78D0302.includes

// EBSTimpl
#include "EBSTimpl.h"
// EBSTdebug
#include "EBSTdebug.h"


//## begin module%3E75E78D0302.declarations preserve=no
//## end module%3E75E78D0302.declarations

//## begin module%3E75E78D0302.additionalDeclarations preserve=yes
//## end module%3E75E78D0302.additionalDeclarations


// Class CSTDebug 







CSTDebug::CSTDebug (CSTStepperMotorImplementation* p_pContext)
  //## begin CSTDebug::CSTDebug%1048150004.hasinit preserve=no
      : m_bRotationDirection(false), m_uiStepsToGo(0), m_uiSpeed(0), m_bEnable(false), m_pContext(p_pContext)
  //## end CSTDebug::CSTDebug%1048150004.hasinit
  //## begin CSTDebug::CSTDebug%1048150004.initialization preserve=yes
  //## end CSTDebug::CSTDebug%1048150004.initialization
{
  //## begin CSTDebug::CSTDebug%1048150004.body preserve=yes
  //## end CSTDebug::CSTDebug%1048150004.body
}


CSTDebug::~CSTDebug()
{
  //## begin CSTDebug::~CSTDebug%.body preserve=yes
  //## end CSTDebug::~CSTDebug%.body
}


//## Get and Set Operations for Associations (implementation)

CSTStepperMotorImplementation * CSTDebug::GetpContext ()
{
  //## begin CSTDebug::GetpContext%3E75E5100005.get preserve=no
  return m_pContext;
  //## end CSTDebug::GetpContext%3E75E5100005.get
}

// Additional Declarations
  //## begin CSTDebug%3E75E4E80081.declarations preserve=yes
  //## end CSTDebug%3E75E4E80081.declarations

//## begin module%3E75E78D0302.epilog preserve=yes
//## end module%3E75E78D0302.epilog
