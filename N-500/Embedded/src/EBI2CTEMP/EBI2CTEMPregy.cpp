//## begin module%3F02C89603DE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F02C89603DE.cm

//## begin module%3F02C89603DE.cp preserve=no
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
//## end module%3F02C89603DE.cp

//## Module: EBI2CTEMPregy%3F02C89603DE; Package body
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Source file: R:\Embedded\src\EBI2CTEMP\EBI2CTEMPregy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F02C89603DE.additionalIncludes preserve=no
//## end module%3F02C89603DE.additionalIncludes

//## begin module%3F02C89603DE.includes preserve=yes
//## end module%3F02C89603DE.includes

// EBPIfact
#include "EBPIfact.h"
// EBI2CTEMPregy
#include "EBI2CTEMPregy.h"
// EBI2CTEMPcrea
#include "EBI2CTEMPcrea.h"
//## begin module%3F02C89603DE.declarations preserve=no
//## end module%3F02C89603DE.declarations

//## begin module%3F02C89603DE.additionalDeclarations preserve=yes
//## end module%3F02C89603DE.additionalDeclarations


// Class CI2CTempInterfaceRegistry 


//## Other Operations (implementation)
void CI2CTempInterfaceRegistry::RegisterInterfaces ()
{
  //## begin CI2CTempInterfaceRegistry::RegisterInterfaces%1057146733.body preserve=yes

    CPIObjectFactory::GetInstance()->RegisterCreator(new CI2CTempSensorDS1631ZCreatorV0s());

  //## end CI2CTempInterfaceRegistry::RegisterInterfaces%1057146733.body
}

// Additional Declarations
  //## begin CI2CTempInterfaceRegistry%3F02C7C900D7.declarations preserve=yes
  //## end CI2CTempInterfaceRegistry%3F02C7C900D7.declarations

//## begin module%3F02C89603DE.epilog preserve=yes
//## end module%3F02C89603DE.epilog
