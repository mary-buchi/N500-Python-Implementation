//## begin module%3EF063BD0123.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF063BD0123.cm

//## begin module%3EF063BD0123.cp preserve=no
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
//## end module%3EF063BD0123.cp

//## Module: EBSTmain%3EF063BD0123; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EF063BD0123.additionalIncludes preserve=no
//## end module%3EF063BD0123.additionalIncludes

//## begin module%3EF063BD0123.includes preserve=yes
//## end module%3EF063BD0123.includes

// EBSTsten
#include "EBSTsten.h"
// EBSTregy
#include "EBSTregy.h"
// EBSTmain
#include "EBSTmain.h"
//## begin module%3EF063BD0123.declarations preserve=no
//## end module%3EF063BD0123.declarations

//## begin module%3EF063BD0123.additionalDeclarations preserve=yes
extern "C" void InitInstance()
{
	CSTStateMachineEngine::BuildStateMachine();

	CSTInterfaceRegistry::RegisterInterfaces();
}

extern "C" void ExitInstance()
{
	CSTStateMachineEngine::DeleteStateMachine();
}
//## end module%3EF063BD0123.additionalDeclarations


//## begin module%3EF063BD0123.epilog preserve=yes
//## end module%3EF063BD0123.epilog
