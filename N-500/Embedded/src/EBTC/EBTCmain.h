//## begin module%3EE993230153.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE993230153.cm

//## begin module%3EE993230153.cp preserve=no
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
//## end module%3EE993230153.cp

//## Module: EBTCmain%3EE993230153; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCmain.h

#ifndef EBTCmain_h
#define EBTCmain_h 1

//## begin module%3EE993230153.additionalIncludes preserve=no
//## end module%3EE993230153.additionalIncludes

//## begin module%3EE993230153.includes preserve=yes
//## end module%3EE993230153.includes

//## begin module%3EE993230153.declarations preserve=no
//## end module%3EE993230153.declarations

//## begin module%3EE993230153.additionalDeclarations preserve=yes
extern "C" EBTC_DLL_DECL void InitInstance();

extern "C" EBTC_DLL_DECL void ExitInstance();
//## end module%3EE993230153.additionalDeclarations


//## begin TC_MAIN%3EE99289022E.preface preserve=yes
//## end TC_MAIN%3EE99289022E.preface

//## Class: TC_MAIN%3EE99289022E; Class Utility
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EE993A70192;CTCStateMachineEngine { -> }
//## Uses: <unnamed>%3EE9C09801FF;CTCInterfaceRegistry { -> }

// This Class is Implementation Only
//## begin TC_MAIN%3EE99289022E.postscript preserve=yes
//## end TC_MAIN%3EE99289022E.postscript

//## begin module%3EE993230153.epilog preserve=yes
//## end module%3EE993230153.epilog


#endif
