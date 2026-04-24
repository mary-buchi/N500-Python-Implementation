//## begin module%3EF053CF006D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF053CF006D.cm

//## begin module%3EF053CF006D.cp preserve=no
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
//## end module%3EF053CF006D.cp

//## Module: EBWCmain%3EF053CF006D; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCmain.h

#ifndef EBWCmain_h
#define EBWCmain_h 1

//## begin module%3EF053CF006D.additionalIncludes preserve=no
//## end module%3EF053CF006D.additionalIncludes

//## begin module%3EF053CF006D.includes preserve=yes
//## end module%3EF053CF006D.includes

//## begin module%3EF053CF006D.declarations preserve=no
//## end module%3EF053CF006D.declarations

//## begin module%3EF053CF006D.additionalDeclarations preserve=yes

extern "C" EBWC_DLL_DECL void InitInstance();

extern "C" EBWC_DLL_DECL void ExitInstance();

//## end module%3EF053CF006D.additionalDeclarations


//## begin WC_MAIN%3EF050BD0270.preface preserve=yes
//## end WC_MAIN%3EF050BD0270.preface

//## Class: WC_MAIN%3EF050BD0270; Class Utility
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EF052BA03C8;CWCInterfaceRegistry { -> }
//## Uses: <unnamed>%3EF052BC00AB;CWCStateMachineEngine { -> }

// This Class is Implementation Only
//## begin WC_MAIN%3EF050BD0270.postscript preserve=yes
//## end WC_MAIN%3EF050BD0270.postscript

//## begin module%3EF053CF006D.epilog preserve=yes
//## end module%3EF053CF006D.epilog


#endif
