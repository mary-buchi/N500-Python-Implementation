//## begin module%3EED769F03A6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F03A6.cm

//## begin module%3EED769F03A6.cp preserve=no
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
//## end module%3EED769F03A6.cp

//## Module: EBPCmain%3EED769F03A6; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F03A6.additionalIncludes preserve=no
//## end module%3EED769F03A6.additionalIncludes

//## begin module%3EED769F03A6.includes preserve=yes
//## end module%3EED769F03A6.includes

// EBPCmain
#include "EBPCmain.h"
// EBPCsten
#include "EBPCsten.h"
// EBPCregy
#include "EBPCregy.h"
//## begin module%3EED769F03A6.declarations preserve=no
//## end module%3EED769F03A6.declarations

//## begin module%3EED769F03A6.additionalDeclarations preserve=yes
extern "C" void InitInstance()
{
	CPCStateMachineEngine::BuildStateMachine();

	CPCInterfaceRegistry::RegisterInterfaces();
}

extern "C" void ExitInstance()
{
	CPCStateMachineEngine::DeleteStateMachine();
}
//## end module%3EED769F03A6.additionalDeclarations


//## begin module%3EED769F03A6.epilog preserve=yes
//## end module%3EED769F03A6.epilog
