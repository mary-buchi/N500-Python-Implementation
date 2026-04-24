//## begin module%3EF063BB02B9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EF063BB02B9.cm

//## begin module%3EF063BB02B9.cp preserve=no
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
//## end module%3EF063BB02B9.cp

//## Module: EBSTmain%3EF063BB02B9; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTmain.h

#ifndef EBSTmain_h
#define EBSTmain_h 1

//## begin module%3EF063BB02B9.additionalIncludes preserve=no
//## end module%3EF063BB02B9.additionalIncludes

//## begin module%3EF063BB02B9.includes preserve=yes
//## end module%3EF063BB02B9.includes

//## begin module%3EF063BB02B9.declarations preserve=no
//## end module%3EF063BB02B9.declarations

//## begin module%3EF063BB02B9.additionalDeclarations preserve=yes
extern "C" EBST_DLL_DECL void InitInstance();

extern "C" EBST_DLL_DECL void ExitInstance();
//## end module%3EF063BB02B9.additionalDeclarations


//## begin ST_MAIN%3EF064240304.preface preserve=yes
//## end ST_MAIN%3EF064240304.preface

//## Class: ST_MAIN%3EF064240304
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EF06456005A;CSTInterfaceRegistry { -> }
//## Uses: <unnamed>%3EF064760020;CSTStateMachineEngine { -> }

// This Class is Implementation Only
//## begin ST_MAIN%3EF064240304.postscript preserve=yes
//## end ST_MAIN%3EF064240304.postscript

//## begin module%3EF063BB02B9.epilog preserve=yes
//## end module%3EF063BB02B9.epilog


#endif
