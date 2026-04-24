//## begin module%4004111C0399.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%4004111C0399.cm

//## begin module%4004111C0399.cp preserve=no
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
//## end module%4004111C0399.cp

//## Module: EBISRident%4004111C0399; Package specification
//## Subsystem: EBISR (Interrupt Service Routine)%3E40DF6A00CB
//## Source file: R:\Embedded\src\EBISR\EBISRident.h

#ifndef EBISRident_h
#define EBISRident_h 1

//## begin module%4004111C0399.additionalIncludes preserve=no
//## end module%4004111C0399.additionalIncludes

//## begin module%4004111C0399.includes preserve=yes
//## end module%4004111C0399.includes

//## begin module%4004111C0399.declarations preserve=no
//## end module%4004111C0399.declarations

//## begin module%4004111C0399.additionalDeclarations preserve=yes

//## end module%4004111C0399.additionalDeclarations


//## begin ISR_IDENTIFIERS%400410F001D4.preface preserve=yes
//## end ISR_IDENTIFIERS%400410F001D4.preface

//## Class: ISR_IDENTIFIERS%400410F001D4; Class Utility
//## Category: EBISR (Interrupt Service Routine)%3E40DF26004E
//## Subsystem: EBISR (Interrupt Service Routine)%3E40DF6A00CB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin ISR_IDENTIFIERS%400410F001D4.postscript preserve=yes
#define ISR_ID                      "ISR"


// exception ID's
#define IDE_ISR_ERROR    	  		                        1000

// exception bit masks
#define IDE_ISR_BM_USER_EXCEPTION                       0x00000001
#define IDE_ISR_BM_USER_EMERGENCY_STOP                  0x00000002
#define IDE_ISR_BM_LASER_DETECTION                      0x00000004
#define IDE_ISR_BM_UPPER_VELOCITY_RANGE                 0x00000008
#define IDE_ISR_BM_LOWER_VELOCITY_RANGE                 0x00000010
#define IDE_ISR_BM_ZERO_CROSS_WATCH_CNT_RANGE           0x00000020
#define IDE_ISR_BM_WRONG_DATA_SIZE                      0x00000040
#define IDE_ISR_BM_WEDGE_DRIVE_NOT_STOPPED              0x00000080
#define IDE_ISR_BM_INVALID_CMD                          0x00000100
#define IDE_ISR_BM_MAX_CURRENT                          0x00000200
#define IDE_ISR_BM_DRIVE_NOT_IN_LIGHT_BARRIER           0x00000400
#define IDE_ISR_BM_REFERENCE_LIGHT_BARRIER				0x00000800


//## end ISR_IDENTIFIERS%400410F001D4.postscript

//## begin module%4004111C0399.epilog preserve=yes
//## end module%4004111C0399.epilog


#endif
