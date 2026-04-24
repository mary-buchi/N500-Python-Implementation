//## begin module%3F49F9DE0196.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F49F9DE0196.cm

//## begin module%3F49F9DE0196.cp preserve=no
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
//## end module%3F49F9DE0196.cp

//## Module: EBI2CADCmain%3F49F9DE0196; Package body
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Source file: R:\Embedded\src\EBI2CADC\EBI2CADCmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F49F9DE0196.additionalIncludes preserve=no
//## end module%3F49F9DE0196.additionalIncludes

//## begin module%3F49F9DE0196.includes preserve=yes
//## end module%3F49F9DE0196.includes

// EBI2CADCregy
#include "EBI2CADCregy.h"
// EBI2CADCmain
#include "EBI2CADCmain.h"
//## begin module%3F49F9DE0196.declarations preserve=no
//## end module%3F49F9DE0196.declarations

//## begin module%3F49F9DE0196.additionalDeclarations preserve=yes
extern "C" void InitInstance()
{
    CI2CADCInterfaceRegistry::RegisterInterfaces();
}

extern "C" void ExitInstance()
{
}
//## end module%3F49F9DE0196.additionalDeclarations


//## begin module%3F49F9DE0196.epilog preserve=yes
//## end module%3F49F9DE0196.epilog
