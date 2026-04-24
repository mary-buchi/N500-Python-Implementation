//## begin module%3F49FA0000BB.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F49FA0000BB.cm

//## begin module%3F49FA0000BB.cp preserve=no
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
//## end module%3F49FA0000BB.cp

//## Module: EBI2CADCregy%3F49FA0000BB; Package body
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Source file: R:\Embedded\src\EBI2CADC\EBI2CADCregy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F49FA0000BB.additionalIncludes preserve=no
//## end module%3F49FA0000BB.additionalIncludes

//## begin module%3F49FA0000BB.includes preserve=yes
//## end module%3F49FA0000BB.includes

// EBPIfact
#include "EBPIfact.h"
// EBI2CADCcrea
#include "EBI2CADCcrea.h"
// EBI2CADCregy
#include "EBI2CADCregy.h"
//## begin module%3F49FA0000BB.declarations preserve=no
//## end module%3F49FA0000BB.declarations

//## begin module%3F49FA0000BB.additionalDeclarations preserve=yes
//## end module%3F49FA0000BB.additionalDeclarations


// Class CI2CADCInterfaceRegistry 


//## Other Operations (implementation)
void CI2CADCInterfaceRegistry::RegisterInterfaces ()
{
  //## begin CI2CADCInterfaceRegistry::RegisterInterfaces%1061804157.body preserve=yes
  CPIObjectFactory::GetInstance()->RegisterCreator(new CI2CADCMAX1037CreatorV0s());
  //## end CI2CADCInterfaceRegistry::RegisterInterfaces%1061804157.body
}

// Additional Declarations
  //## begin CI2CADCInterfaceRegistry%3F4A1046035B.declarations preserve=yes
  //## end CI2CADCInterfaceRegistry%3F4A1046035B.declarations

//## begin module%3F49FA0000BB.epilog preserve=yes
//## end module%3F49FA0000BB.epilog
