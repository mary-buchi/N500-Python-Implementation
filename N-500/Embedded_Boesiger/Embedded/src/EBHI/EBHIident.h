//## begin module%3E2268A300A8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E2268A300A8.cm

//## begin module%3E2268A300A8.cp preserve=no
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
//## end module%3E2268A300A8.cp

//## Module: EBHIident%3E2268A300A8; Package specification
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIident.h

#ifndef EBHIident_h
#define EBHIident_h 1

//## begin module%3E2268A300A8.additionalIncludes preserve=no
//## end module%3E2268A300A8.additionalIncludes

//## begin module%3E2268A300A8.includes preserve=yes
//## end module%3E2268A300A8.includes

//## begin module%3E2268A300A8.declarations preserve=no
//## end module%3E2268A300A8.declarations

//## begin module%3E2268A300A8.additionalDeclarations preserve=yes
#define HI_ID           _T("HI")

// exception ID's
#define IDE_HW_INTF_PCI_DRIVER_ERROR	  		        1100
#define IDE_HW_INTF_ERROR            		  	        1101
#define IDE_HW_INTF_ALLOC_STREAMBUFFER_ERROR        1102
#define IDE_HW_INTF_ALLOC_PROCESSIMAGE_ERROR        1103
#define IDE_HW_INTF_IFM_BUFFER_OVERFLOW             1104
#define IDE_HW_INTF_LASER_BUFFER_OVERFLOW           1105
#define IDE_HW_INTF_IFM_LASER_SIZE_MISMATCH         1106
#define IDE_HW_INTF_IFM_LASER_DATA_ERROR            1107
#define IDE_HW_INTF_WRONG_LOG_ID                    1108
#define IDE_HW_INTF_NO_WRITE_ACCESS                 1109
#define IDE_HW_INTF_VALID_DATA_ERROR                1110
#define IDE_HW_INTF_INVALID_OBJ_ID		    	        1111
#define IDE_HW_INTF_ERROR_EVENT_SIGNALISATION       1112
#define IDE_HW_INTF_HW_EXCEPTION                    1113
#define IDE_HW_INTF_FPGA_VERSION_MISMATCH           1114
#define IDE_HW_INTF_MEMORY_LOW                      1115



//## end module%3E2268A300A8.additionalDeclarations


//## begin HI_IDENTIFIERS%3E22721001D1.preface preserve=yes
//## end HI_IDENTIFIERS%3E22721001D1.preface

//## Class: HI_IDENTIFIERS%3E22721001D1; Class Utility
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin HI_IDENTIFIERS%3E22721001D1.postscript preserve=yes
//## end HI_IDENTIFIERS%3E22721001D1.postscript

//## begin module%3E2268A300A8.epilog preserve=yes
//## end module%3E2268A300A8.epilog


#endif
