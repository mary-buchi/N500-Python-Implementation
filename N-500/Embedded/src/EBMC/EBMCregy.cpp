//## begin module%3DAAD4710208.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAD4710208.cm

//## begin module%3DAAD4710208.cp preserve=no
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
//## end module%3DAAD4710208.cp

//## Module: EBMCregy%3DAAD4710208; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCregy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DAAD4710208.additionalIncludes preserve=no
//## end module%3DAAD4710208.additionalIncludes

//## begin module%3DAAD4710208.includes preserve=yes
//## end module%3DAAD4710208.includes

// EBPIfact
#include "EBPIfact.h"
// EBMCsten
#include "EBMCsten.h"
// EBMCcrea
#include "EBMCcrea.h"
// EBMCregy
#include "EBMCregy.h"
//## begin module%3DAAD4710208.declarations preserve=no
//## end module%3DAAD4710208.declarations

//## begin module%3DAAD4710208.additionalDeclarations preserve=yes
//## end module%3DAAD4710208.additionalDeclarations


// Class CMCInterfaceRegistry 

CMCInterfaceRegistry::CMCInterfaceRegistry()
  //## begin CMCInterfaceRegistry::CMCInterfaceRegistry%.hasinit preserve=no
  //## end CMCInterfaceRegistry::CMCInterfaceRegistry%.hasinit
  //## begin CMCInterfaceRegistry::CMCInterfaceRegistry%.initialization preserve=yes
  //## end CMCInterfaceRegistry::CMCInterfaceRegistry%.initialization
{
  //## begin CMCInterfaceRegistry::CMCInterfaceRegistry%.body preserve=yes
  //## end CMCInterfaceRegistry::CMCInterfaceRegistry%.body
}


CMCInterfaceRegistry::~CMCInterfaceRegistry()
{
  //## begin CMCInterfaceRegistry::~CMCInterfaceRegistry%.body preserve=yes
  CMCStateMachineEngine::DeleteStateMachine();
  //## end CMCInterfaceRegistry::~CMCInterfaceRegistry%.body
}



//## Other Operations (implementation)
void CMCInterfaceRegistry::RegisterInterfaces ()
{
  //## begin CMCInterfaceRegistry::RegisterInterfaces%1034575110.body preserve=yes
	CPIObjectFactory::GetInstance()->RegisterCreator(
		new CMCMeasurementChannelCreatorV0());
  //## end CMCInterfaceRegistry::RegisterInterfaces%1034575110.body
}

// Additional Declarations
  //## begin CMCInterfaceRegistry%3DAAD43D02E2.declarations preserve=yes
  //## end CMCInterfaceRegistry%3DAAD43D02E2.declarations

//## begin module%3DAAD4710208.epilog preserve=yes
//## end module%3DAAD4710208.epilog
