//## begin module%3FDD88BF001F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FDD88BF001F.cm

//## begin module%3FDD88BF001F.cp preserve=no
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
//## end module%3FDD88BF001F.cp

//## Module: EBI2CEPROMcrea%3FDD88BF001F; Package body
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Source file: R:\Embedded\src\EBI2CEPROM\EBI2CEPROMcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FDD88BF001F.additionalIncludes preserve=no
//## end module%3FDD88BF001F.additionalIncludes

//## begin module%3FDD88BF001F.includes preserve=yes
//## end module%3FDD88BF001F.includes

// EBI2CEPROMintf
#include "EBI2CEPROMintf.h"
// EBI2CEPROMcrea
#include "EBI2CEPROMcrea.h"
//## begin module%3FDD88BF001F.declarations preserve=no
//## end module%3FDD88BF001F.declarations

//## begin module%3FDD88BF001F.additionalDeclarations preserve=yes
//## end module%3FDD88BF001F.additionalDeclarations


// Class CI2CEprom24LC515CreatorV0s 

CI2CEprom24LC515CreatorV0s::CI2CEprom24LC515CreatorV0s()
  //## begin CI2CEprom24LC515CreatorV0s::CI2CEprom24LC515CreatorV0s%.hasinit preserve=no
  //## end CI2CEprom24LC515CreatorV0s::CI2CEprom24LC515CreatorV0s%.hasinit
  //## begin CI2CEprom24LC515CreatorV0s::CI2CEprom24LC515CreatorV0s%.initialization preserve=yes
  : CPIObjCreatorI2CEprom24LC515(_T(""))
  //## end CI2CEprom24LC515CreatorV0s::CI2CEprom24LC515CreatorV0s%.initialization
{
  //## begin CI2CEprom24LC515CreatorV0s::CI2CEprom24LC515CreatorV0s%.body preserve=yes
  //## end CI2CEprom24LC515CreatorV0s::CI2CEprom24LC515CreatorV0s%.body
}


CI2CEprom24LC515CreatorV0s::~CI2CEprom24LC515CreatorV0s()
{
  //## begin CI2CEprom24LC515CreatorV0s::~CI2CEprom24LC515CreatorV0s%.body preserve=yes
  //## end CI2CEprom24LC515CreatorV0s::~CI2CEprom24LC515CreatorV0s%.body
}



//## Other Operations (implementation)
IPII2CEprom24LC515* CI2CEprom24LC515CreatorV0s::Create (UINT p_uiID)
{
  //## begin CI2CEprom24LC515CreatorV0s::Create%1071483521.body preserve=yes
  IPII2CEprom24LC515* l_Intf = new CI2CEprom24LC515(p_uiID);

	return l_Intf;
  //## end CI2CEprom24LC515CreatorV0s::Create%1071483521.body
}

// Additional Declarations
  //## begin CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.declarations preserve=yes
  //## end CI2CEprom24LC515CreatorV0s%3FDD8BA2002E.declarations

//## begin module%3FDD88BF001F.epilog preserve=yes
//## end module%3FDD88BF001F.epilog
