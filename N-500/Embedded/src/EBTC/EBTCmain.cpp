//## begin module%3EE992790182.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE992790182.cm

//## begin module%3EE992790182.cp preserve=no
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
//## end module%3EE992790182.cp

//## Module: EBTCmain%3EE992790182; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE992790182.additionalIncludes preserve=no
//## end module%3EE992790182.additionalIncludes

//## begin module%3EE992790182.includes preserve=yes
//## end module%3EE992790182.includes

// EBTCmain
#include "EBTCmain.h"
// EBTCsten
#include "EBTCsten.h"
// EBTCregy
#include "EBTCregy.h"
//## begin module%3EE992790182.declarations preserve=no
//## end module%3EE992790182.declarations

//## begin module%3EE992790182.additionalDeclarations preserve=yes
extern "C" void InitInstance()
{
	CTCStateMachineEngine::BuildStateMachine();

	CTCInterfaceRegistry::RegisterInterfaces();
}

extern "C" void ExitInstance()
{
	CTCStateMachineEngine::DeleteStateMachine();
}
//## end module%3EE992790182.additionalDeclarations


//## begin module%3EE992790182.epilog preserve=yes
//## end module%3EE992790182.epilog
