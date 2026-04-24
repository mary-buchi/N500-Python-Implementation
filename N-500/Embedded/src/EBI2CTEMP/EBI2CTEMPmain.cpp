//## begin module%3F02C903021D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F02C903021D.cm

//## begin module%3F02C903021D.cp preserve=no
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
//## end module%3F02C903021D.cp

//## Module: EBI2CTEMPmain%3F02C903021D; Package body
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Source file: R:\Embedded\src\EBI2CTEMP\EBI2CTEMPmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F02C903021D.additionalIncludes preserve=no
//## end module%3F02C903021D.additionalIncludes

//## begin module%3F02C903021D.includes preserve=yes
//## end module%3F02C903021D.includes

// EBI2CTEMPmain
#include "EBI2CTEMPmain.h"
// EBI2CTEMPregy
#include "EBI2CTEMPregy.h"
//## begin module%3F02C903021D.declarations preserve=no
//## end module%3F02C903021D.declarations

//## begin module%3F02C903021D.additionalDeclarations preserve=yes
extern "C" void InitInstance()
{
    CI2CTempInterfaceRegistry::RegisterInterfaces();
}

extern "C" void ExitInstance()
{
}
//## end module%3F02C903021D.additionalDeclarations


//## begin module%3F02C903021D.epilog preserve=yes
//## end module%3F02C903021D.epilog
