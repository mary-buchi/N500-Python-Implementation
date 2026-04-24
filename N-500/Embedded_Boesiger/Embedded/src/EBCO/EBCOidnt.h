//## begin module%3DA3C0D803AE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA3C0D803AE.cm

//## begin module%3DA3C0D803AE.cp preserve=no
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
//## end module%3DA3C0D803AE.cp

//## Module: EBCOidnt%3DA3C0D803AE; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOidnt.h

#ifndef EBCOidnt_h
#define EBCOidnt_h 1

//## begin module%3DA3C0D803AE.additionalIncludes preserve=no
//## end module%3DA3C0D803AE.additionalIncludes

//## begin module%3DA3C0D803AE.includes preserve=yes
//## end module%3DA3C0D803AE.includes

//## begin module%3DA3C0D803AE.declarations preserve=no
//## end module%3DA3C0D803AE.declarations

//## begin module%3DA3C0D803AE.additionalDeclarations preserve=yes
#define CO_ID   _T("CO")

// exception ID's
#define IDE_CORE_WRONG_STATE			1000
#define IDE_CORE_CLEANUP_STOP			1001
#define IDE_CORE_CLEANUP_INITIALIZE		1002
#define IDE_CORE_NATIVE_EXCEPTION       1010
#define IDE_CORE_MEMORY_EXCEPTION       1011
#define IDE_CORE_TIMEOUT                1012
#define IDE_CORE_CELL_UNDOCKED          1013

//## end module%3DA3C0D803AE.additionalDeclarations


//## begin CO_IDENTIFIERS%3DA3C0F60247.preface preserve=yes
//## end CO_IDENTIFIERS%3DA3C0F60247.preface

//## Class: CO_IDENTIFIERS%3DA3C0F60247; Class Utility
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin CO_IDENTIFIERS%3DA3C0F60247.postscript preserve=yes
//## end CO_IDENTIFIERS%3DA3C0F60247.postscript

//## begin CO_EXCEPTIONS%3DA3C19A01DA.preface preserve=yes
//## end CO_EXCEPTIONS%3DA3C19A01DA.preface

//## Class: CO_EXCEPTIONS%3DA3C19A01DA; Class Utility
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin CO_EXCEPTIONS%3DA3C19A01DA.postscript preserve=yes
//## end CO_EXCEPTIONS%3DA3C19A01DA.postscript

//## begin module%3DA3C0D803AE.epilog preserve=yes
//## end module%3DA3C0D803AE.epilog


#endif
