//## begin module%3F02C69A030B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F02C69A030B.cm

//## begin module%3F02C69A030B.cp preserve=no
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
//## end module%3F02C69A030B.cp

//## Module: EBI2CTEMPcrea%3F02C69A030B; Package body
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Source file: R:\Embedded\src\EBI2CTEMP\EBI2CTEMPcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F02C69A030B.additionalIncludes preserve=no
//## end module%3F02C69A030B.additionalIncludes

//## begin module%3F02C69A030B.includes preserve=yes
//## end module%3F02C69A030B.includes

// EBI2CTEMPcrea
#include "EBI2CTEMPcrea.h"
// EBI2CTEMPintf
#include "EBI2CTEMPintf.h"
//## begin module%3F02C69A030B.declarations preserve=no
//## end module%3F02C69A030B.declarations

//## begin module%3F02C69A030B.additionalDeclarations preserve=yes
//## end module%3F02C69A030B.additionalDeclarations


// Class CI2CTempSensorDS1631ZCreatorV0s 

CI2CTempSensorDS1631ZCreatorV0s::CI2CTempSensorDS1631ZCreatorV0s()
  //## begin CI2CTempSensorDS1631ZCreatorV0s::CI2CTempSensorDS1631ZCreatorV0s%.hasinit preserve=no
  //## end CI2CTempSensorDS1631ZCreatorV0s::CI2CTempSensorDS1631ZCreatorV0s%.hasinit
  //## begin CI2CTempSensorDS1631ZCreatorV0s::CI2CTempSensorDS1631ZCreatorV0s%.initialization preserve=yes
  : CPIObjCreatorI2CSensorDS1631Z(_T(""))
  //## end CI2CTempSensorDS1631ZCreatorV0s::CI2CTempSensorDS1631ZCreatorV0s%.initialization
{
  //## begin CI2CTempSensorDS1631ZCreatorV0s::CI2CTempSensorDS1631ZCreatorV0s%.body preserve=yes
  //## end CI2CTempSensorDS1631ZCreatorV0s::CI2CTempSensorDS1631ZCreatorV0s%.body
}


CI2CTempSensorDS1631ZCreatorV0s::~CI2CTempSensorDS1631ZCreatorV0s()
{
  //## begin CI2CTempSensorDS1631ZCreatorV0s::~CI2CTempSensorDS1631ZCreatorV0s%.body preserve=yes
  //## end CI2CTempSensorDS1631ZCreatorV0s::~CI2CTempSensorDS1631ZCreatorV0s%.body
}



//## Other Operations (implementation)
IPII2CTempSensorDS1631Z* CI2CTempSensorDS1631ZCreatorV0s::Create (UINT p_uiID)
{
  //## begin CI2CTempSensorDS1631ZCreatorV0s::Create%1057146616.body preserve=yes

  IPII2CTempSensorDS1631Z* l_Intf = new CI2CTempSensorDS1631Z(p_uiID);

	return l_Intf;

  //## end CI2CTempSensorDS1631ZCreatorV0s::Create%1057146616.body
}

// Additional Declarations
  //## begin CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.declarations preserve=yes
  //## end CI2CTempSensorDS1631ZCreatorV0s%3F02C5190135.declarations

//## begin module%3F02C69A030B.epilog preserve=yes
//## end module%3F02C69A030B.epilog
