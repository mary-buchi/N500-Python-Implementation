//## begin module%3EF05DB40186.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF05DB40186.cm

//## begin module%3EF05DB40186.cp preserve=no
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
//## end module%3EF05DB40186.cp

//## Module: EBDImain%3EF05DB40186; Package body
//## Subsystem: EBDI (Diagnostics)%3E197C2800D6
//## Source file: R:\Embedded\src\EBDI\EBDImain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EF05DB40186.additionalIncludes preserve=no
//## end module%3EF05DB40186.additionalIncludes

//## begin module%3EF05DB40186.includes preserve=yes
//## end module%3EF05DB40186.includes

// EBDImain
#include "EBDImain.h"
// EBDIregy
#include "EBDIregy.h"
//## begin module%3EF05DB40186.declarations preserve=no
//## end module%3EF05DB40186.declarations

//## begin module%3EF05DB40186.additionalDeclarations preserve=yes

extern "C" void InitInstance()
{
	CDIInterfaceRegistry::RegisterInterfaces();
}

extern "C" void ExitInstance()
{
}

//## end module%3EF05DB40186.additionalDeclarations


//## begin module%3EF05DB40186.epilog preserve=yes
//## end module%3EF05DB40186.epilog
