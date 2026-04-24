//## begin module%3DE5EADA01E9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EADA01E9.cm

//## begin module%3DE5EADA01E9.cp preserve=no
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
//## end module%3DE5EADA01E9.cp

//## Module: EBPOregy%3DE5EADA01E9; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOregy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EADA01E9.additionalIncludes preserve=no
//## end module%3DE5EADA01E9.additionalIncludes

//## begin module%3DE5EADA01E9.includes preserve=yes
//## end module%3DE5EADA01E9.includes

// EBPIfact
#include "EBPIfact.h"
// EBPOsten
#include "EBPOsten.h"
// EBPOcrea
#include "EBPOcrea.h"
// EBPOregy
#include "EBPOregy.h"
//## begin module%3DE5EADA01E9.declarations preserve=no
//## end module%3DE5EADA01E9.declarations

//## begin module%3DE5EADA01E9.additionalDeclarations preserve=yes
//## end module%3DE5EADA01E9.additionalDeclarations


// Class CPOInterfaceRegistry 


//## Other Operations (implementation)
void CPOInterfaceRegistry::RegisterInterfaces ()
{
  //## begin CPOInterfaceRegistry::RegisterInterfaces%1037094236.body preserve=yes
	CPIObjectFactory::GetInstance()->RegisterCreator(new CPOPersistentObjCreatorV0());
  //## end CPOInterfaceRegistry::RegisterInterfaces%1037094236.body
}

// Additional Declarations
  //## begin CPOInterfaceRegistry%3DE63D080014.declarations preserve=yes
  //## end CPOInterfaceRegistry%3DE63D080014.declarations

//## begin module%3DE5EADA01E9.epilog preserve=yes
//## end module%3DE5EADA01E9.epilog
