//## begin module%3DA5C6130326.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA5C6130326.cm

//## begin module%3DA5C6130326.cp preserve=no
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
//## end module%3DA5C6130326.cp

//## Module: EBSTcrea%3DA5C6130326; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA5C6130326.additionalIncludes preserve=no
//## end module%3DA5C6130326.additionalIncludes

//## begin module%3DA5C6130326.includes preserve=yes
//## end module%3DA5C6130326.includes

// EBSTcrea
#include "EBSTcrea.h"
// EBSTintf
#include "EBSTintf.h"
//## begin module%3DA5C6130326.declarations preserve=no
//## end module%3DA5C6130326.declarations

//## begin module%3DA5C6130326.additionalDeclarations preserve=yes
//## end module%3DA5C6130326.additionalDeclarations


// Class CSTStepperCreatorV0 

CSTStepperCreatorV0::CSTStepperCreatorV0()
  //## begin CSTStepperCreatorV0::CSTStepperCreatorV0%.hasinit preserve=no
  //## end CSTStepperCreatorV0::CSTStepperCreatorV0%.hasinit
  //## begin CSTStepperCreatorV0::CSTStepperCreatorV0%.initialization preserve=yes
  : CPIObjCreatorStepperMotor(_T(""))
  //## end CSTStepperCreatorV0::CSTStepperCreatorV0%.initialization
{
  //## begin CSTStepperCreatorV0::CSTStepperCreatorV0%.body preserve=yes
  //## end CSTStepperCreatorV0::CSTStepperCreatorV0%.body
}


CSTStepperCreatorV0::~CSTStepperCreatorV0()
{
  //## begin CSTStepperCreatorV0::~CSTStepperCreatorV0%.body preserve=yes
  //## end CSTStepperCreatorV0::~CSTStepperCreatorV0%.body
}



//## Other Operations (implementation)
IPIStepperMotorInterface* CSTStepperCreatorV0::Create (UINT p_uiID)
{
  //## begin CSTStepperCreatorV0::Create%1034272541.body preserve=yes
    IPIStepperMotorInterface* l_Intf = new CSTStepperMotorInterface(p_uiID);
    l_Intf->InitInstance();

	return l_Intf;
  //## end CSTStepperCreatorV0::Create%1034272541.body
}

// Additional Declarations
  //## begin CSTStepperCreatorV0%3DA5C65500D2.declarations preserve=yes
  //## end CSTStepperCreatorV0%3DA5C65500D2.declarations

//## begin module%3DA5C6130326.epilog preserve=yes
//## end module%3DA5C6130326.epilog
