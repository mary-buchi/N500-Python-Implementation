//## begin module%3EF049AC0176.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF049AC0176.cm

//## begin module%3EF049AC0176.cp preserve=no
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
//## end module%3EF049AC0176.cp

//## Module: EBMCmain%3EF049AC0176; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EF049AC0176.additionalIncludes preserve=no
//## end module%3EF049AC0176.additionalIncludes

//## begin module%3EF049AC0176.includes preserve=yes
//## end module%3EF049AC0176.includes

// EBMCregy
#include "EBMCregy.h"
// EBMCsten
#include "EBMCsten.h"
// EBMCmain
#include "EBMCmain.h"
//## begin module%3EF049AC0176.declarations preserve=no
//## end module%3EF049AC0176.declarations

//## begin module%3EF049AC0176.additionalDeclarations preserve=yes

extern "C" void InitInstance()
{
	CMCStateMachineEngine::BuildStateMachine();

	CMCInterfaceRegistry::RegisterInterfaces();
}

extern "C" void ExitInstance()
{
	CMCStateMachineEngine::DeleteStateMachine();
}

//## end module%3EF049AC0176.additionalDeclarations


//## begin module%3EF049AC0176.epilog preserve=yes
//## end module%3EF049AC0176.epilog
