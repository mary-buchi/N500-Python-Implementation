//## begin module%3E1981F50385.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E1981F50385.cm

//## begin module%3E1981F50385.cp preserve=no
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
//## end module%3E1981F50385.cp

//## Module: EBDIregy%3E1981F50385; Package body
//## Subsystem: EBDI (Diagnostics)%3E197C2800D6
//## Source file: R:\Embedded\src\EBDI\EBDIregy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E1981F50385.additionalIncludes preserve=no
//## end module%3E1981F50385.additionalIncludes

//## begin module%3E1981F50385.includes preserve=yes
//## end module%3E1981F50385.includes

// EBPIfact
#include "EBPIfact.h"
// EBDIcrea
#include "EBDIcrea.h"
// EBDIregy
#include "EBDIregy.h"
//## begin module%3E1981F50385.declarations preserve=no
//## end module%3E1981F50385.declarations

//## begin module%3E1981F50385.additionalDeclarations preserve=yes
//## end module%3E1981F50385.additionalDeclarations


// Class CDIInterfaceRegistry 


//## Other Operations (implementation)
void CDIInterfaceRegistry::RegisterInterfaces ()
{
  //## begin CDIInterfaceRegistry::RegisterInterfaces%1041861674.body preserve=yes
	CPIObjectFactory::GetInstance()->RegisterCreator(new CDIDiagnosticCreatorV0());
  //## end CDIInterfaceRegistry::RegisterInterfaces%1041861674.body
}

// Additional Declarations
  //## begin CDIInterfaceRegistry%3E198BCC0143.declarations preserve=yes
  //## end CDIInterfaceRegistry%3E198BCC0143.declarations

//## begin module%3E1981F50385.epilog preserve=yes
//## end module%3E1981F50385.epilog
