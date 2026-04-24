//## begin module%3DD0B1CF0132.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD0B1CF0132.cm

//## begin module%3DD0B1CF0132.cp preserve=no
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
//## end module%3DD0B1CF0132.cp

//## Module: EBWCregy%3DD0B1CF0132; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCregy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DD0B1CF0132.additionalIncludes preserve=no
//## end module%3DD0B1CF0132.additionalIncludes

//## begin module%3DD0B1CF0132.includes preserve=yes
//## end module%3DD0B1CF0132.includes

// EBPIfact
#include "EBPIfact.h"
// EBWCsten
#include "EBWCsten.h"
// EBWCcrea
#include "EBWCcrea.h"
// EBWCregy
#include "EBWCregy.h"
//## begin module%3DD0B1CF0132.declarations preserve=no
//## end module%3DD0B1CF0132.declarations

//## begin module%3DD0B1CF0132.additionalDeclarations preserve=yes
//## end module%3DD0B1CF0132.additionalDeclarations


// Class CWCInterfaceRegistry 

CWCInterfaceRegistry::CWCInterfaceRegistry()
  //## begin CWCInterfaceRegistry::CWCInterfaceRegistry%.hasinit preserve=no
  //## end CWCInterfaceRegistry::CWCInterfaceRegistry%.hasinit
  //## begin CWCInterfaceRegistry::CWCInterfaceRegistry%.initialization preserve=yes
  //## end CWCInterfaceRegistry::CWCInterfaceRegistry%.initialization
{
  //## begin CWCInterfaceRegistry::CWCInterfaceRegistry%.body preserve=yes
  //## end CWCInterfaceRegistry::CWCInterfaceRegistry%.body
}


CWCInterfaceRegistry::~CWCInterfaceRegistry()
{
  //## begin CWCInterfaceRegistry::~CWCInterfaceRegistry%.body preserve=yes
  CWCStateMachineEngine::DeleteStateMachine();
  //## end CWCInterfaceRegistry::~CWCInterfaceRegistry%.body
}



//## Other Operations (implementation)
void CWCInterfaceRegistry::RegisterInterfaces ()
{
  //## begin CWCInterfaceRegistry::RegisterInterfaces%1042097141.body preserve=yes
	CPIObjectFactory::GetInstance()->RegisterCreator(
		new CWCWedgeControlCreatorV0());
  //## end CWCInterfaceRegistry::RegisterInterfaces%1042097141.body
}

// Additional Declarations
  //## begin CWCInterfaceRegistry%3DD0B2E2000A.declarations preserve=yes
  //## end CWCInterfaceRegistry%3DD0B2E2000A.declarations

//## begin module%3DD0B1CF0132.epilog preserve=yes
//## end module%3DD0B1CF0132.epilog
