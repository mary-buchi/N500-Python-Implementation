//## begin module%3FDD88FA01A5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FDD88FA01A5.cm

//## begin module%3FDD88FA01A5.cp preserve=no
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
//## end module%3FDD88FA01A5.cp

//## Module: EBI2CEPROMmain%3FDD88FA01A5; Package body
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Source file: R:\Embedded\src\EBI2CEPROM\EBI2CEPROMmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FDD88FA01A5.additionalIncludes preserve=no
//## end module%3FDD88FA01A5.additionalIncludes

//## begin module%3FDD88FA01A5.includes preserve=yes
//## end module%3FDD88FA01A5.includes

// EBI2CEPROMmain
#include "EBI2CEPROMmain.h"
// EBI2CEPROMregy
#include "EBI2CEPROMregy.h"
//## begin module%3FDD88FA01A5.declarations preserve=no
//## end module%3FDD88FA01A5.declarations

//## begin module%3FDD88FA01A5.additionalDeclarations preserve=yes
extern "C" void InitInstance()
{
    CI2CEpromInterfaceRegistry::RegisterInterfaces();
}

extern "C" void ExitInstance()
{
}
//## end module%3FDD88FA01A5.additionalDeclarations


//## begin module%3FDD88FA01A5.epilog preserve=yes
//## end module%3FDD88FA01A5.epilog
