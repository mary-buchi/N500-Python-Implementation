//## begin module%3FDD88E0030D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FDD88E0030D.cm

//## begin module%3FDD88E0030D.cp preserve=no
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
//## end module%3FDD88E0030D.cp

//## Module: EBI2CEPROMregy%3FDD88E0030D; Package body
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Source file: R:\Embedded\src\EBI2CEPROM\EBI2CEPROMregy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FDD88E0030D.additionalIncludes preserve=no
//## end module%3FDD88E0030D.additionalIncludes

//## begin module%3FDD88E0030D.includes preserve=yes
//## end module%3FDD88E0030D.includes

// EBPIfact
#include "EBPIfact.h"
// EBI2CEPROMcrea
#include "EBI2CEPROMcrea.h"
// EBI2CEPROMregy
#include "EBI2CEPROMregy.h"
//## begin module%3FDD88E0030D.declarations preserve=no
//## end module%3FDD88E0030D.declarations

//## begin module%3FDD88E0030D.additionalDeclarations preserve=yes
//## end module%3FDD88E0030D.additionalDeclarations


// Class CI2CEpromInterfaceRegistry 


//## Other Operations (implementation)
void CI2CEpromInterfaceRegistry::RegisterInterfaces ()
{
  //## begin CI2CEpromInterfaceRegistry::RegisterInterfaces%1071483520.body preserve=yes
    CPIObjectFactory::GetInstance()->RegisterCreator(new CI2CEprom24LC515CreatorV0s());
  //## end CI2CEpromInterfaceRegistry::RegisterInterfaces%1071483520.body
}

// Additional Declarations
  //## begin CI2CEpromInterfaceRegistry%3FDD8A11038A.declarations preserve=yes
  //## end CI2CEpromInterfaceRegistry%3FDD8A11038A.declarations

//## begin module%3FDD88E0030D.epilog preserve=yes
//## end module%3FDD88E0030D.epilog
