//## begin module%3F4B4EAF00EA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F4B4EAF00EA.cm

//## begin module%3F4B4EAF00EA.cp preserve=no
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
//## end module%3F4B4EAF00EA.cp

//## Module: EBI2CDPregy%3F4B4EAF00EA; Package body
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Source file: R:\Embedded\src\EBI2CDP\EBI2CDPregy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F4B4EAF00EA.additionalIncludes preserve=no
//## end module%3F4B4EAF00EA.additionalIncludes

//## begin module%3F4B4EAF00EA.includes preserve=yes
//## end module%3F4B4EAF00EA.includes

// EBPIfact
#include "EBPIfact.h"
// EBI2CDPcrea
#include "EBI2CDPcrea.h"
// EBI2CDPregy
#include "EBI2CDPregy.h"
//## begin module%3F4B4EAF00EA.declarations preserve=no
//## end module%3F4B4EAF00EA.declarations

//## begin module%3F4B4EAF00EA.additionalDeclarations preserve=yes
//## end module%3F4B4EAF00EA.additionalDeclarations


// Class CI2CDigitalPotiInterfaceRegistry 


//## Other Operations (implementation)
void CI2CDigitalPotiInterfaceRegistry::RegisterInterfaces ()
{
  //## begin CI2CDigitalPotiInterfaceRegistry::RegisterInterfaces%1061902075.body preserve=yes
  CPIObjectFactory::GetInstance()->RegisterCreator(new CI2CDigitalPotiAD5245CreatorV0s());
  //## end CI2CDigitalPotiInterfaceRegistry::RegisterInterfaces%1061902075.body
}

// Additional Declarations
  //## begin CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.declarations preserve=yes
  //## end CI2CDigitalPotiInterfaceRegistry%3F4B61C0005D.declarations

//## begin module%3F4B4EAF00EA.epilog preserve=yes
//## end module%3F4B4EAF00EA.epilog
