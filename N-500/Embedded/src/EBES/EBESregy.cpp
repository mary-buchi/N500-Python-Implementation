//## begin module%3DE5EC3C0331.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EC3C0331.cm

//## begin module%3DE5EC3C0331.cp preserve=no
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
//## end module%3DE5EC3C0331.cp

//## Module: EBESregy%3DE5EC3C0331; Package body
//## Subsystem: EBES (Event Source)%3DE5E67F00D0
//## Source file: R:\Embedded\src\EBES\EBESregy.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EC3C0331.additionalIncludes preserve=no
//## end module%3DE5EC3C0331.additionalIncludes

//## begin module%3DE5EC3C0331.includes preserve=yes
//## end module%3DE5EC3C0331.includes

// EBPIfact
#include "EBPIfact.h"
// EBEScrea
#include "EBEScrea.h"
// EBESregy
#include "EBESregy.h"
//## begin module%3DE5EC3C0331.declarations preserve=no
//## end module%3DE5EC3C0331.declarations

//## begin module%3DE5EC3C0331.additionalDeclarations preserve=yes
//## end module%3DE5EC3C0331.additionalDeclarations


// Class CESInterfaceRegistry 


//## Other Operations (implementation)
void CESInterfaceRegistry::RegisterInterfaces ()
{
  //## begin CESInterfaceRegistry::RegisterInterfaces%1038837066.body preserve=yes
	CPIObjectFactory::GetInstance()->RegisterCreator(new CESEventSourceCreatorV0());
  //## end CESInterfaceRegistry::RegisterInterfaces%1038837066.body
}

// Additional Declarations
  //## begin CESInterfaceRegistry%3DEB71E90334.declarations preserve=yes
  //## end CESInterfaceRegistry%3DEB71E90334.declarations

//## begin module%3DE5EC3C0331.epilog preserve=yes
//## end module%3DE5EC3C0331.epilog
