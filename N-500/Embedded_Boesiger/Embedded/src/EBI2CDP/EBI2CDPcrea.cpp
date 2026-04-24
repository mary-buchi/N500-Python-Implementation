//## begin module%3F4B4EBF0119.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F4B4EBF0119.cm

//## begin module%3F4B4EBF0119.cp preserve=no
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
//## end module%3F4B4EBF0119.cp

//## Module: EBI2CDPcrea%3F4B4EBF0119; Package body
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Source file: R:\Embedded\src\EBI2CDP\EBI2CDPcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F4B4EBF0119.additionalIncludes preserve=no
//## end module%3F4B4EBF0119.additionalIncludes

//## begin module%3F4B4EBF0119.includes preserve=yes
//## end module%3F4B4EBF0119.includes

// EBI2CDPcrea
#include "EBI2CDPcrea.h"
// EBI2CDPintf
#include "EBI2CDPintf.h"
//## begin module%3F4B4EBF0119.declarations preserve=no
//## end module%3F4B4EBF0119.declarations

//## begin module%3F4B4EBF0119.additionalDeclarations preserve=yes
//## end module%3F4B4EBF0119.additionalDeclarations


// Class CI2CDigitalPotiAD5245CreatorV0s 

CI2CDigitalPotiAD5245CreatorV0s::CI2CDigitalPotiAD5245CreatorV0s()
  //## begin CI2CDigitalPotiAD5245CreatorV0s::CI2CDigitalPotiAD5245CreatorV0s%.hasinit preserve=no
  //## end CI2CDigitalPotiAD5245CreatorV0s::CI2CDigitalPotiAD5245CreatorV0s%.hasinit
  //## begin CI2CDigitalPotiAD5245CreatorV0s::CI2CDigitalPotiAD5245CreatorV0s%.initialization preserve=yes
  //## end CI2CDigitalPotiAD5245CreatorV0s::CI2CDigitalPotiAD5245CreatorV0s%.initialization
{
  //## begin CI2CDigitalPotiAD5245CreatorV0s::CI2CDigitalPotiAD5245CreatorV0s%.body preserve=yes
  //## end CI2CDigitalPotiAD5245CreatorV0s::CI2CDigitalPotiAD5245CreatorV0s%.body
}


CI2CDigitalPotiAD5245CreatorV0s::~CI2CDigitalPotiAD5245CreatorV0s()
{
  //## begin CI2CDigitalPotiAD5245CreatorV0s::~CI2CDigitalPotiAD5245CreatorV0s%.body preserve=yes
  //## end CI2CDigitalPotiAD5245CreatorV0s::~CI2CDigitalPotiAD5245CreatorV0s%.body
}



//## Other Operations (implementation)
IPII2CDigitalPotiAD5245* CI2CDigitalPotiAD5245CreatorV0s::Create (UINT p_uiID)
{
  //## begin CI2CDigitalPotiAD5245CreatorV0s::Create%1061902076.body preserve=yes
  IPII2CDigitalPotiAD5245* l_Intf = new CI2CDigitalPotiAD5245(p_uiID);
	return l_Intf;
  //## end CI2CDigitalPotiAD5245CreatorV0s::Create%1061902076.body
}

// Additional Declarations
  //## begin CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.declarations preserve=yes
  //## end CI2CDigitalPotiAD5245CreatorV0s%3F4B6136036B.declarations

//## begin module%3F4B4EBF0119.epilog preserve=yes
//## end module%3F4B4EBF0119.epilog
