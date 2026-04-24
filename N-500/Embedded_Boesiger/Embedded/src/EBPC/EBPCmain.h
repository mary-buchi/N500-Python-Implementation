//## begin module%3EED769F03AB.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F03AB.cm

//## begin module%3EED769F03AB.cp preserve=no
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
//## end module%3EED769F03AB.cp

//## Module: EBPCmain%3EED769F03AB; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCmain.h

#ifndef EBPCmain_h
#define EBPCmain_h 1

//## begin module%3EED769F03AB.additionalIncludes preserve=no
//## end module%3EED769F03AB.additionalIncludes

//## begin module%3EED769F03AB.includes preserve=yes
//## end module%3EED769F03AB.includes

//## begin module%3EED769F03AB.declarations preserve=no
//## end module%3EED769F03AB.declarations

//## begin module%3EED769F03AB.additionalDeclarations preserve=yes
extern "C" EBPC_DLL_DECL void InitInstance();

extern "C" EBPC_DLL_DECL void ExitInstance();

//## end module%3EED769F03AB.additionalDeclarations


//## begin PC_MAIN%3EED76CC07ED.preface preserve=yes
//## end PC_MAIN%3EED76CC07ED.preface

//## Class: PC_MAIN%3EED76CC07ED; Class Utility
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EED76CC07EF;CPCStateMachineEngine { -> }
//## Uses: <unnamed>%3EED76CC07F2;CPCInterfaceRegistry { -> }

// This Class is Implementation Only
//## begin PC_MAIN%3EED76CC07ED.postscript preserve=yes
//## end PC_MAIN%3EED76CC07ED.postscript

//## begin module%3EED769F03AB.epilog preserve=yes
//## end module%3EED769F03AB.epilog


#endif
