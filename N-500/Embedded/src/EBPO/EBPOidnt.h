//## begin module%3DE5EACC0321.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EACC0321.cm

//## begin module%3DE5EACC0321.cp preserve=no
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
//## end module%3DE5EACC0321.cp

//## Module: EBPOidnt%3DE5EACC0321; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOidnt.h

#ifndef EBPOidnt_h
#define EBPOidnt_h 1

//## begin module%3DE5EACC0321.additionalIncludes preserve=no
//## end module%3DE5EACC0321.additionalIncludes

//## begin module%3DE5EACC0321.includes preserve=yes
//## end module%3DE5EACC0321.includes

//## begin module%3DE5EACC0321.declarations preserve=no
//## end module%3DE5EACC0321.declarations

//## begin module%3DE5EACC0321.additionalDeclarations preserve=yes
#define PO_ID					_T("PO")

#define IDE_HEADER_VERSION			1800
#define IDE_HEADER_IDENT_LENGTH		1801
#define IDE_HEADER_PARA_LENGTH		1802
#define IDE_HEADER_LIFETIME_LENGTH	1803
#define IDE_HEADER_GENERAL			1804
#define IDE_EPROM_FULL				1805
#define IDE_WRONG_DATASIZE			1806

static const int HEADER_LEN = 6;	// First 6 chars in the eprom contains the header length.
#ifdef _UNICODE
	static const int BYTES_PER_CHAR = 2;	// kbit		-> bit		-> byte		-> chars	-> wchars  
#else										// 512kbit	-> 524288	-> 65536	-> 65536	-> 32768
	static const int BYTES_PER_CHAR = 1;
#endif
static const int HEADER_VERSION = 2;
static const int TIME_OUT		= 10000; // i2c timeout 10s

//## end module%3DE5EACC0321.additionalDeclarations


//## begin PO_IDENTIFIERS%3DE5F3A5014D.preface preserve=yes
//## end PO_IDENTIFIERS%3DE5F3A5014D.preface

//## Class: PO_IDENTIFIERS%3DE5F3A5014D; Class Utility
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin PO_IDENTIFIERS%3DE5F3A5014D.postscript preserve=yes
//## end PO_IDENTIFIERS%3DE5F3A5014D.postscript

//## begin module%3DE5EACC0321.epilog preserve=yes
//## end module%3DE5EACC0321.epilog


#endif

