//## begin module%3DE5EDB200C0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EDB200C0.cm

//## begin module%3DE5EDB200C0.cp preserve=no
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
//## end module%3DE5EDB200C0.cp

//## Module: EBTCident%3DE5EDB200C0; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCident.h

#ifndef EBTCident_h
#define EBTCident_h 1

//## begin module%3DE5EDB200C0.additionalIncludes preserve=no
//## end module%3DE5EDB200C0.additionalIncludes

//## begin module%3DE5EDB200C0.includes preserve=yes
//## end module%3DE5EDB200C0.includes

//## begin module%3DE5EDB200C0.declarations preserve=no
//## end module%3DE5EDB200C0.declarations

//## begin module%3DE5EDB200C0.additionalDeclarations preserve=yes
#define TC_ID						_T("TC")

#define IDE_TC_HEATER_SHORTED				1500
#define IDE_TC_HEATER_INTERRUPTED			1501
#define IDE_TC_TEMPERATURE_WARNING_LLIMIT	1502
#define IDE_TC_TEMPERATURE_WARNING_ULIMIT	1503
#define IDE_TC_TEMPERATURE_ERROR_LLIMIT		1504
#define IDE_TC_TEMPERATURE_ERROR_ULIMIT		1505

//## end module%3DE5EDB200C0.additionalDeclarations


//## begin TC_IDENTIFIERS%3DEC713A0189.preface preserve=yes
//## end TC_IDENTIFIERS%3DEC713A0189.preface

//## Class: TC_IDENTIFIERS%3DEC713A0189; Class Utility
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin TC_IDENTIFIERS%3DEC713A0189.postscript preserve=yes
//## end TC_IDENTIFIERS%3DEC713A0189.postscript

//## begin module%3DE5EDB200C0.epilog preserve=yes
//## end module%3DE5EDB200C0.epilog


#endif
