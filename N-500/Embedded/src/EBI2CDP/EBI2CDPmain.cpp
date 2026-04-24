//## begin module%3F4B4EA10128.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F4B4EA10128.cm

//## begin module%3F4B4EA10128.cp preserve=no
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
//## end module%3F4B4EA10128.cp

//## Module: EBI2CDPmain%3F4B4EA10128; Package body
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Source file: R:\Embedded\src\EBI2CDP\EBI2CDPmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F4B4EA10128.additionalIncludes preserve=no
//## end module%3F4B4EA10128.additionalIncludes

//## begin module%3F4B4EA10128.includes preserve=yes
//## end module%3F4B4EA10128.includes

// EBI2CDPregy
#include "EBI2CDPregy.h"
// EBI2CDPmain
#include "EBI2CDPmain.h"
//## begin module%3F4B4EA10128.declarations preserve=no
//## end module%3F4B4EA10128.declarations

//## begin module%3F4B4EA10128.additionalDeclarations preserve=yes
extern "C" void InitInstance()
{
    CI2CDigitalPotiInterfaceRegistry::RegisterInterfaces();
}

extern "C" void ExitInstance()
{
}
//## end module%3F4B4EA10128.additionalDeclarations


//## begin module%3F4B4EA10128.epilog preserve=yes
//## end module%3F4B4EA10128.epilog
