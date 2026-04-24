//## begin module%3EED769F034B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F034B.cm

//## begin module%3EED769F034B.cp preserve=no
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
//## end module%3EED769F034B.cp

//## Module: EBPCregy%3EED769F034B; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCregy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F034B.additionalIncludes preserve=no
//## end module%3EED769F034B.additionalIncludes

//## begin module%3EED769F034B.includes preserve=yes
//## end module%3EED769F034B.includes

// EBPIfact
#include "EBPIfact.h"
// EBPCsten
#include "EBPCsten.h"
// EBPCcrea
#include "EBPCcrea.h"
// EBPCregy
#include "EBPCregy.h"
//## begin module%3EED769F034B.declarations preserve=no
//## end module%3EED769F034B.declarations

//## begin module%3EED769F034B.additionalDeclarations preserve=yes
//## end module%3EED769F034B.additionalDeclarations


// Class CPCInterfaceRegistry 

CPCInterfaceRegistry::CPCInterfaceRegistry()
  //## begin CPCInterfaceRegistry::CPCInterfaceRegistry%.hasinit preserve=no
  //## end CPCInterfaceRegistry::CPCInterfaceRegistry%.hasinit
  //## begin CPCInterfaceRegistry::CPCInterfaceRegistry%.initialization preserve=yes
  //## end CPCInterfaceRegistry::CPCInterfaceRegistry%.initialization
{
  //## begin CPCInterfaceRegistry::CPCInterfaceRegistry%.body preserve=yes
  //## end CPCInterfaceRegistry::CPCInterfaceRegistry%.body
}


CPCInterfaceRegistry::~CPCInterfaceRegistry()
{
  //## begin CPCInterfaceRegistry::~CPCInterfaceRegistry%.body preserve=yes
  //## end CPCInterfaceRegistry::~CPCInterfaceRegistry%.body
}



//## Other Operations (implementation)
void CPCInterfaceRegistry::RegisterInterfaces ()
{
  //## begin CPCInterfaceRegistry::RegisterInterfaces%1038899300.body preserve=yes
	CPIObjectFactory::GetInstance()->RegisterCreator(new CPCPowerControlCreatorV0());
  //## end CPCInterfaceRegistry::RegisterInterfaces%1038899300.body
}

// Additional Declarations
  //## begin CPCInterfaceRegistry%3EED76CC02F8.declarations preserve=yes
  //## end CPCInterfaceRegistry%3EED76CC02F8.declarations

//## begin module%3EED769F034B.epilog preserve=yes
//## end module%3EED769F034B.epilog
