//## begin module%3EF05DAD005D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF05DAD005D.cm

//## begin module%3EF05DAD005D.cp preserve=no
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
//## end module%3EF05DAD005D.cp

//## Module: EBDImain%3EF05DAD005D; Package specification
//## Subsystem: EBDI (Diagnostics)%3E197C2800D6
//## Source file: R:\Embedded\src\EBDI\EBDImain.h

#ifndef EBDImain_h
#define EBDImain_h 1

//## begin module%3EF05DAD005D.additionalIncludes preserve=no
//## end module%3EF05DAD005D.additionalIncludes

//## begin module%3EF05DAD005D.includes preserve=yes
//## end module%3EF05DAD005D.includes

//## begin module%3EF05DAD005D.declarations preserve=no
//## end module%3EF05DAD005D.declarations

//## begin module%3EF05DAD005D.additionalDeclarations preserve=yes

extern "C" EBDI_DLL_DECL void InitInstance();

extern "C" EBDI_DLL_DECL void ExitInstance();

//## end module%3EF05DAD005D.additionalDeclarations


//## begin DI_MAIN%3EF05E220119.preface preserve=yes
//## end DI_MAIN%3EF05E220119.preface

//## Class: DI_MAIN%3EF05E220119; Class Utility
//## Category: EBDI (Diagnostics)%3E197C790124
//## Subsystem: EBDI (Diagnostics)%3E197C2800D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EF05EA102CE;CDIInterfaceRegistry { -> }

// This Class is Implementation Only
//## begin DI_MAIN%3EF05E220119.postscript preserve=yes
//## end DI_MAIN%3EF05E220119.postscript

//## begin module%3EF05DAD005D.epilog preserve=yes
//## end module%3EF05DAD005D.epilog


#endif
