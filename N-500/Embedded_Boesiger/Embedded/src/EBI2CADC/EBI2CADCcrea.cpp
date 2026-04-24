//## begin module%3F49FA1F03C8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F49FA1F03C8.cm

//## begin module%3F49FA1F03C8.cp preserve=no
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
//## end module%3F49FA1F03C8.cp

//## Module: EBI2CADCcrea%3F49FA1F03C8; Package body
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Source file: R:\Embedded\src\EBI2CADC\EBI2CADCcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F49FA1F03C8.additionalIncludes preserve=no
//## end module%3F49FA1F03C8.additionalIncludes

//## begin module%3F49FA1F03C8.includes preserve=yes
//## end module%3F49FA1F03C8.includes

// EBI2CADCcrea
#include "EBI2CADCcrea.h"
// EBI2CADCintf
#include "EBI2CADCintf.h"
//## begin module%3F49FA1F03C8.declarations preserve=no
//## end module%3F49FA1F03C8.declarations

//## begin module%3F49FA1F03C8.additionalDeclarations preserve=yes
//## end module%3F49FA1F03C8.additionalDeclarations


// Class CI2CADCMAX1037CreatorV0s 

CI2CADCMAX1037CreatorV0s::CI2CADCMAX1037CreatorV0s()
  //## begin CI2CADCMAX1037CreatorV0s::CI2CADCMAX1037CreatorV0s%.hasinit preserve=no
  //## end CI2CADCMAX1037CreatorV0s::CI2CADCMAX1037CreatorV0s%.hasinit
  //## begin CI2CADCMAX1037CreatorV0s::CI2CADCMAX1037CreatorV0s%.initialization preserve=yes
  : CPIObjCreatorI2CADCMAX1037(_T(""))
  //## end CI2CADCMAX1037CreatorV0s::CI2CADCMAX1037CreatorV0s%.initialization
{
  //## begin CI2CADCMAX1037CreatorV0s::CI2CADCMAX1037CreatorV0s%.body preserve=yes
  //## end CI2CADCMAX1037CreatorV0s::CI2CADCMAX1037CreatorV0s%.body
}


CI2CADCMAX1037CreatorV0s::~CI2CADCMAX1037CreatorV0s()
{
  //## begin CI2CADCMAX1037CreatorV0s::~CI2CADCMAX1037CreatorV0s%.body preserve=yes
  //## end CI2CADCMAX1037CreatorV0s::~CI2CADCMAX1037CreatorV0s%.body
}



//## Other Operations (implementation)
IPII2CADCMAX1037* CI2CADCMAX1037CreatorV0s::Create (UINT p_uiID)
{
  //## begin CI2CADCMAX1037CreatorV0s::Create%1061804156.body preserve=yes
    IPII2CADCMAX1037* l_Intf = new CI2CADCMAX1037(p_uiID);

	return l_Intf;
  //## end CI2CADCMAX1037CreatorV0s::Create%1061804156.body
}

// Additional Declarations
  //## begin CI2CADCMAX1037CreatorV0s%3F4A070A007D.declarations preserve=yes
  //## end CI2CADCMAX1037CreatorV0s%3F4A070A007D.declarations

//## begin module%3F49FA1F03C8.epilog preserve=yes
//## end module%3F49FA1F03C8.epilog
