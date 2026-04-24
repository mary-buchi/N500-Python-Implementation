//## begin module%3EF0546A0251.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF0546A0251.cm

//## begin module%3EF0546A0251.cp preserve=no
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
//## end module%3EF0546A0251.cp

//## Module: EBIOmain%3EF0546A0251; Package body
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Source file: R:\Embedded\src\EBIO\EBIOmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EF0546A0251.additionalIncludes preserve=no
//## end module%3EF0546A0251.additionalIncludes

//## begin module%3EF0546A0251.includes preserve=yes
//## end module%3EF0546A0251.includes

// EBIOmain
#include "EBIOmain.h"
// EBIOregy
#include "EBIOregy.h"
//## begin module%3EF0546A0251.declarations preserve=no
//## end module%3EF0546A0251.declarations

//## begin module%3EF0546A0251.additionalDeclarations preserve=yes
extern "C" void InitInstance()
{
	CIOInterfaceRegistry::RegisterInterfaces();
}

extern "C" void ExitInstance()
{

}

//## end module%3EF0546A0251.additionalDeclarations


//## begin module%3EF0546A0251.epilog preserve=yes
//## end module%3EF0546A0251.epilog
