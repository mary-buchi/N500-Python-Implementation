//## begin module%3EF0541F0213.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF0541F0213.cm

//## begin module%3EF0541F0213.cp preserve=no
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
//## end module%3EF0541F0213.cp

//## Module: EBPOmain%3EF0541F0213; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EF0541F0213.additionalIncludes preserve=no
//## end module%3EF0541F0213.additionalIncludes

//## begin module%3EF0541F0213.includes preserve=yes
//## end module%3EF0541F0213.includes

// EBPOmain
#include "EBPOmain.h"
// EBPOsten
#include "EBPOsten.h"
// EBPOregy
#include "EBPOregy.h"
//## begin module%3EF0541F0213.declarations preserve=no
//## end module%3EF0541F0213.declarations

//## begin module%3EF0541F0213.additionalDeclarations preserve=yes

extern "C" void InitInstance()
{
	CPOStateMachineEngine::BuildStateMachine();
	CPOInterfaceRegistry::RegisterInterfaces();
}

extern "C" void ExitInstance()
{
	CPOStateMachineEngine::DeleteStateMachine();
}

//## end module%3EF0541F0213.additionalDeclarations


//## begin module%3EF0541F0213.epilog preserve=yes
//## end module%3EF0541F0213.epilog
