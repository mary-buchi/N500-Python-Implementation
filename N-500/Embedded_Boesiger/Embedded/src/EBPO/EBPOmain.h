//## begin module%3EF054150128.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF054150128.cm

//## begin module%3EF054150128.cp preserve=no
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
//## end module%3EF054150128.cp

//## Module: EBPOmain%3EF054150128; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOmain.h

#ifndef EBPOmain_h
#define EBPOmain_h 1

//## begin module%3EF054150128.additionalIncludes preserve=no
//## end module%3EF054150128.additionalIncludes

//## begin module%3EF054150128.includes preserve=yes
//## end module%3EF054150128.includes

//## begin module%3EF054150128.declarations preserve=no
//## end module%3EF054150128.declarations

//## begin module%3EF054150128.additionalDeclarations preserve=yes

extern "C" EBPO_DLL_DECL void InitInstance();

extern "C" EBPO_DLL_DECL void ExitInstance();

//## end module%3EF054150128.additionalDeclarations


//## begin PO_MAIN%3EF051BF000F.preface preserve=yes
//## end PO_MAIN%3EF051BF000F.preface

//## Class: PO_MAIN%3EF051BF000F; Class Utility
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EF05303006D;CPOStateMachineEngine { -> }
//## Uses: <unnamed>%3EF0530B03D8;CPOInterfaceRegistry { -> }

// This Class is Implementation Only
//## begin PO_MAIN%3EF051BF000F.postscript preserve=yes
//## end PO_MAIN%3EF051BF000F.postscript

//## begin module%3EF054150128.epilog preserve=yes
//## end module%3EF054150128.epilog


#endif
