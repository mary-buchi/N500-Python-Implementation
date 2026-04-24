//## begin module%3DF5AF54009C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DF5AF54009C.cm

//## begin module%3DF5AF54009C.cp preserve=no
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
//## end module%3DF5AF54009C.cp

//## Module: EBIOregy%3DF5AF54009C; Package body
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Source file: R:\Embedded\src\EBIO\EBIOregy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DF5AF54009C.additionalIncludes preserve=no
//## end module%3DF5AF54009C.additionalIncludes

//## begin module%3DF5AF54009C.includes preserve=yes
//## end module%3DF5AF54009C.includes

// EBPIfact
#include "EBPIfact.h"
// EBIOcrea
#include "EBIOcrea.h"
// EBIOregy
#include "EBIOregy.h"
//## begin module%3DF5AF54009C.declarations preserve=no
//## end module%3DF5AF54009C.declarations

//## begin module%3DF5AF54009C.additionalDeclarations preserve=yes
//## end module%3DF5AF54009C.additionalDeclarations


// Class CIOInterfaceRegistry 


//## Other Operations (implementation)
void CIOInterfaceRegistry::RegisterInterfaces ()
{
  //## begin CIOInterfaceRegistry::RegisterInterfaces%1039513439.body preserve=yes
	CPIObjectFactory::GetInstance()->RegisterCreator(new CIOOutputAnalogCreatorV0());
	CPIObjectFactory::GetInstance()->RegisterCreator(new CIOOutputDigitalCreatorV0());
	CPIObjectFactory::GetInstance()->RegisterCreator(new CIOSensorAnalogCreatorV0());
	CPIObjectFactory::GetInstance()->RegisterCreator(new CIOSensorDigitalCreatorV0());
  //## end CIOInterfaceRegistry::RegisterInterfaces%1039513439.body
}

// Additional Declarations
  //## begin CIOInterfaceRegistry%3DF5B9C201B5.declarations preserve=yes
  //## end CIOInterfaceRegistry%3DF5B9C201B5.declarations

//## begin module%3DF5AF54009C.epilog preserve=yes
//## end module%3DF5AF54009C.epilog
