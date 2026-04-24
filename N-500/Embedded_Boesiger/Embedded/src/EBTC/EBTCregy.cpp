//## begin module%3DE5EDBC02F2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EDBC02F2.cm

//## begin module%3DE5EDBC02F2.cp preserve=no
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
//## end module%3DE5EDBC02F2.cp

//## Module: EBTCregy%3DE5EDBC02F2; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCregy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EDBC02F2.additionalIncludes preserve=no
//## end module%3DE5EDBC02F2.additionalIncludes

//## begin module%3DE5EDBC02F2.includes preserve=yes
//## end module%3DE5EDBC02F2.includes

// EBPIfact
#include "EBPIfact.h"
// EBTCsten
#include "EBTCsten.h"
// EBTCcrea
#include "EBTCcrea.h"
// EBTCregy
#include "EBTCregy.h"
//## begin module%3DE5EDBC02F2.declarations preserve=no
//## end module%3DE5EDBC02F2.declarations

//## begin module%3DE5EDBC02F2.additionalDeclarations preserve=yes
//## end module%3DE5EDBC02F2.additionalDeclarations


// Class CTCInterfaceRegistry 

CTCInterfaceRegistry::CTCInterfaceRegistry()
  //## begin CTCInterfaceRegistry::CTCInterfaceRegistry%.hasinit preserve=no
  //## end CTCInterfaceRegistry::CTCInterfaceRegistry%.hasinit
  //## begin CTCInterfaceRegistry::CTCInterfaceRegistry%.initialization preserve=yes
  //## end CTCInterfaceRegistry::CTCInterfaceRegistry%.initialization
{
  //## begin CTCInterfaceRegistry::CTCInterfaceRegistry%.body preserve=yes
  //## end CTCInterfaceRegistry::CTCInterfaceRegistry%.body
}


CTCInterfaceRegistry::~CTCInterfaceRegistry()
{
  //## begin CTCInterfaceRegistry::~CTCInterfaceRegistry%.body preserve=yes
  //## end CTCInterfaceRegistry::~CTCInterfaceRegistry%.body
}



//## Other Operations (implementation)
void CTCInterfaceRegistry::RegisterInterfaces ()
{
  //## begin CTCInterfaceRegistry::RegisterInterfaces%1038899300.body preserve=yes
	CPIObjectFactory::GetInstance()->RegisterCreator(new CTCTemperatureControlCreatorV0());
	CPIObjectFactory::GetInstance()->RegisterCreator(new CTCTemperatureControlCreatorV2());
  //## end CTCInterfaceRegistry::RegisterInterfaces%1038899300.body
}

// Additional Declarations
  //## begin CTCInterfaceRegistry%3DEC56B201F4.declarations preserve=yes
  //## end CTCInterfaceRegistry%3DEC56B201F4.declarations

//## begin module%3DE5EDBC02F2.epilog preserve=yes
//## end module%3DE5EDBC02F2.epilog
