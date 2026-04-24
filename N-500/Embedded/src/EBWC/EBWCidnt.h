//## begin module%3DCFD73F01A0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DCFD73F01A0.cm

//## begin module%3DCFD73F01A0.cp preserve=no
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
//## end module%3DCFD73F01A0.cp

//## Module: EBWCidnt%3DCFD73F01A0; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCidnt.h

#ifndef EBWCidnt_h
#define EBWCidnt_h 1

//## begin module%3DCFD73F01A0.additionalIncludes preserve=no
//## end module%3DCFD73F01A0.additionalIncludes

//## begin module%3DCFD73F01A0.includes preserve=yes
//## end module%3DCFD73F01A0.includes

//## begin module%3DCFD73F01A0.declarations preserve=no
//## end module%3DCFD73F01A0.declarations

//## begin module%3DCFD73F01A0.additionalDeclarations preserve=yes
#define WC_ID           _T("WC")

// action identifiers
#define IDA_INITIALIZE              0
#define IDA_REFERENCING             1
#define IDA_START_NUMBER_OF_SCAN    2
#define IDA_STOPPING                3
#define IDA_DAC_CURR_DIR            4
#define IDA_MEASURING_EXCEPTION     5



// exception ID's
#define IDE_WC_WRONG_CONFIG_PARAM     1600
#define IDE_WC_WRONG_PROFILE_PARAM    1601
#define IDE_WC_WRONG_STATE_CMD        1602
#define IDE_WC_DAC_CALIBRATION_ERROR  1603
#define IDE_WC_REFERENCING_ERROR      1604
#define IDE_WC_INITIALIZING_ERROR     1605
#define IDE_WC_STOPPING_ERROR         1606
#define IDE_WC_START_ERROR            1607
#define IDE_WC_MEASURING_ERROR        1608
#define IDE_WC_WEDGEDRIVE_ERROR		  1607

//## end module%3DCFD73F01A0.additionalDeclarations


//## begin WC_IDENTIFIERS%3DD0AAC000C5.preface preserve=yes
//## end WC_IDENTIFIERS%3DD0AAC000C5.preface

//## Class: WC_IDENTIFIERS%3DD0AAC000C5; Class Utility
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin WC_IDENTIFIERS%3DD0AAC000C5.postscript preserve=yes
//## end WC_IDENTIFIERS%3DD0AAC000C5.postscript

//## begin module%3DCFD73F01A0.epilog preserve=yes
//## end module%3DCFD73F01A0.epilog


#endif
