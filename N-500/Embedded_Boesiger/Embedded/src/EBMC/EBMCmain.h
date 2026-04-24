//## begin module%3EF04E6B0213.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF04E6B0213.cm

//## begin module%3EF04E6B0213.cp preserve=no
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
//## end module%3EF04E6B0213.cp

//## Module: EBMCmain%3EF04E6B0213; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCmain.h

#ifndef EBMCmain_h
#define EBMCmain_h 1

//## begin module%3EF04E6B0213.additionalIncludes preserve=no
//## end module%3EF04E6B0213.additionalIncludes

//## begin module%3EF04E6B0213.includes preserve=yes
//## end module%3EF04E6B0213.includes

//## begin module%3EF04E6B0213.declarations preserve=no
//## end module%3EF04E6B0213.declarations

//## begin module%3EF04E6B0213.additionalDeclarations preserve=yes

extern "C" EBMC_DLL_DECL void InitInstance();

extern "C" EBMC_DLL_DECL void ExitInstance();

//## end module%3EF04E6B0213.additionalDeclarations


//## begin MC_MAIN%3EF049660186.preface preserve=yes
//## end MC_MAIN%3EF049660186.preface

//## Class: MC_MAIN%3EF049660186; Class Utility
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EF04A7700AB;CMCStateMachineEngine { -> }
//## Uses: <unnamed>%3EF04A7B01E4;CMCInterfaceRegistry { -> }

// This Class is Implementation Only
//## begin MC_MAIN%3EF049660186.postscript preserve=yes
//## end MC_MAIN%3EF049660186.postscript

//## begin module%3EF04E6B0213.epilog preserve=yes
//## end module%3EF04E6B0213.epilog


#endif
