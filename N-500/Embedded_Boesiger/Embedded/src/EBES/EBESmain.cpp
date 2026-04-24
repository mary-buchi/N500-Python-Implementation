//## begin module%3EF0544400CA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF0544400CA.cm

//## begin module%3EF0544400CA.cp preserve=no
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
//## end module%3EF0544400CA.cp

//## Module: EBESmain%3EF0544400CA; Package body
//## Subsystem: EBES (Event Source)%3DE5E67F00D0
//## Source file: R:\Embedded\src\EBES\EBESmain.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EF0544400CA.additionalIncludes preserve=no
//## end module%3EF0544400CA.additionalIncludes

//## begin module%3EF0544400CA.includes preserve=yes
//## end module%3EF0544400CA.includes

// EBESmain
#include "EBESmain.h"
// EBESregy
#include "EBESregy.h"
//## begin module%3EF0544400CA.declarations preserve=no
//## end module%3EF0544400CA.declarations

//## begin module%3EF0544400CA.additionalDeclarations preserve=yes

extern "C" void InitInstance()
{
	CESInterfaceRegistry::RegisterInterfaces();
}

extern "C" void ExitInstance()
{
}

//## end module%3EF0544400CA.additionalDeclarations


//## begin module%3EF0544400CA.epilog preserve=yes
//## end module%3EF0544400CA.epilog
