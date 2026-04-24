//## begin module%3EF053D7005D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF053D7005D.cm

//## begin module%3EF053D7005D.cp preserve=no
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
//## end module%3EF053D7005D.cp

//## Module: EBWCmain%3EF053D7005D; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EF053D7005D.additionalIncludes preserve=no
//## end module%3EF053D7005D.additionalIncludes

//## begin module%3EF053D7005D.includes preserve=yes
//## end module%3EF053D7005D.includes

// EBWCsten
#include "EBWCsten.h"
// EBWCregy
#include "EBWCregy.h"
// EBWCmain
#include "EBWCmain.h"
//## begin module%3EF053D7005D.declarations preserve=no
//## end module%3EF053D7005D.declarations

//## begin module%3EF053D7005D.additionalDeclarations preserve=yes

extern "C" void InitInstance()
{
	CWCStateMachineEngine::BuildStateMachine();

	CWCInterfaceRegistry::RegisterInterfaces();
}

extern "C" void ExitInstance()
{
	CWCStateMachineEngine::DeleteStateMachine();
}

//## end module%3EF053D7005D.additionalDeclarations


//## begin module%3EF053D7005D.epilog preserve=yes
//## end module%3EF053D7005D.epilog
