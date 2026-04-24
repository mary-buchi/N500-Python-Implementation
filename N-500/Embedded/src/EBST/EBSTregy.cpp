//## begin module%3DA5C91E025E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA5C91E025E.cm

//## begin module%3DA5C91E025E.cp preserve=no
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
//## end module%3DA5C91E025E.cp

//## Module: EBSTregy%3DA5C91E025E; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTregy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA5C91E025E.additionalIncludes preserve=no
//## end module%3DA5C91E025E.additionalIncludes

//## begin module%3DA5C91E025E.includes preserve=yes
//## end module%3DA5C91E025E.includes

// EBPIfact
#include "EBPIfact.h"
// EBSTsten
#include "EBSTsten.h"
// EBSTregy
#include "EBSTregy.h"
// EBSTcrea
#include "EBSTcrea.h"
//## begin module%3DA5C91E025E.declarations preserve=no
//## end module%3DA5C91E025E.declarations

//## begin module%3DA5C91E025E.additionalDeclarations preserve=yes
//## end module%3DA5C91E025E.additionalDeclarations


// Class CSTInterfaceRegistry 

CSTInterfaceRegistry::CSTInterfaceRegistry()
  //## begin CSTInterfaceRegistry::CSTInterfaceRegistry%.hasinit preserve=no
  //## end CSTInterfaceRegistry::CSTInterfaceRegistry%.hasinit
  //## begin CSTInterfaceRegistry::CSTInterfaceRegistry%.initialization preserve=yes
  //## end CSTInterfaceRegistry::CSTInterfaceRegistry%.initialization
{
  //## begin CSTInterfaceRegistry::CSTInterfaceRegistry%.body preserve=yes
  //## end CSTInterfaceRegistry::CSTInterfaceRegistry%.body
}


CSTInterfaceRegistry::~CSTInterfaceRegistry()
{
  //## begin CSTInterfaceRegistry::~CSTInterfaceRegistry%.body preserve=yes
	CSTStateMachineEngine::DeleteStateMachine();
  //## end CSTInterfaceRegistry::~CSTInterfaceRegistry%.body
}



//## Other Operations (implementation)
void CSTInterfaceRegistry::RegisterInterfaces ()
{
  //## begin CSTInterfaceRegistry::RegisterInterfaces%1034272543.body preserve=yes
	CPIObjectFactory::GetInstance()->RegisterCreator(new CSTStepperCreatorV0());
  //## end CSTInterfaceRegistry::RegisterInterfaces%1034272543.body
}

// Additional Declarations
  //## begin CSTInterfaceRegistry%3DA5C93A018C.declarations preserve=yes
  //## end CSTInterfaceRegistry%3DA5C93A018C.declarations

//## begin module%3DA5C91E025E.epilog preserve=yes
//## end module%3DA5C91E025E.epilog
