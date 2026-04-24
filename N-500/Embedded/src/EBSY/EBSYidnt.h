//## begin module%3EDC5B3C01C4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EDC5B3C01C4.cm

//## begin module%3EDC5B3C01C4.cp preserve=no
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
//## end module%3EDC5B3C01C4.cp

//## Module: EBSYidnt%3EDC5B3C01C4; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYidnt.h

#ifndef EBSYidnt_h
#define EBSYidnt_h 1

//## begin module%3EDC5B3C01C4.additionalIncludes preserve=no
//## end module%3EDC5B3C01C4.additionalIncludes

//## begin module%3EDC5B3C01C4.includes preserve=yes
//## end module%3EDC5B3C01C4.includes

//## begin module%3EDC5B3C01C4.declarations preserve=no
//## end module%3EDC5B3C01C4.declarations

//## begin module%3EDC5B3C01C4.additionalDeclarations preserve=yes
#define SY_ID           _T("SY")

// exception identifiers
#define IDE_UPDATE_COMPONENT        1700
#define IDE_SYSTEM_REBOOT           1701
#define IDE_FPGA_DOWNLOAD_TIMEOUT   1702
#define IDE_FPGA_EXECUTION_ERROR    1703
#define IDE_DEVICE_BUSY             1704
#define IDE_WINCE_DOWNLOAD_ERROR    1705
#define IDE_EB_FILE_DOWNLOAD_ERROR  1706
//## end module%3EDC5B3C01C4.additionalDeclarations


//## begin SY_IDENTIFIERS%3EDC5B9C0057.preface preserve=yes
//## end SY_IDENTIFIERS%3EDC5B9C0057.preface

//## Class: SY_IDENTIFIERS%3EDC5B9C0057; Class Utility
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin SY_IDENTIFIERS%3EDC5B9C0057.postscript preserve=yes
//## end SY_IDENTIFIERS%3EDC5B9C0057.postscript

//## begin module%3EDC5B3C01C4.epilog preserve=yes
//## end module%3EDC5B3C01C4.epilog


#endif
