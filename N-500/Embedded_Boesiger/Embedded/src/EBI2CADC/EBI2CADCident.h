//## begin module%3F49F7CF008C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F49F7CF008C.cm

//## begin module%3F49F7CF008C.cp preserve=no
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
//## end module%3F49F7CF008C.cp

//## Module: EBI2CADCident%3F49F7CF008C; Package specification
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Source file: R:\Embedded\src\EBI2CADC\EBI2CADCident.h

#ifndef EBI2CADCident_h
#define EBI2CADCident_h 1

//## begin module%3F49F7CF008C.additionalIncludes preserve=no
//## end module%3F49F7CF008C.additionalIncludes

//## begin module%3F49F7CF008C.includes preserve=yes
//## end module%3F49F7CF008C.includes

//## begin module%3F49F7CF008C.declarations preserve=no
//## end module%3F49F7CF008C.declarations

//## begin module%3F49F7CF008C.additionalDeclarations preserve=yes
#define I2CADC_ID           "I2CADC"


// exception ID's
#define IDE_I2C_INTF_MAX1037_HW_INTF_ERROR    	  		  2100
#define IDE_I2C_INTF_MAX1037_WRONG_ID             		  2101
#define IDE_I2C_INTF_MAX1037_SETUP_ERROR	    		      2102
#define IDE_I2C_INTF_MAX1037_SETUP_ACK_ERROR 		        2103
#define IDE_I2C_INTF_MAX1037_DATA_ERROR      		        2104
#define IDE_I2C_INTF_MAX1037_DATA_ACK_ERROR 		        2105
#define IDE_I2C_INTF_MAX1037_WRONG_DATA_SIZE            2106

//## end module%3F49F7CF008C.additionalDeclarations


//## begin I2CADC_IDENTIFIERS%3F49FA8A0290.preface preserve=yes
//## end I2CADC_IDENTIFIERS%3F49FA8A0290.preface

//## Class: I2CADC_IDENTIFIERS%3F49FA8A0290; Class Utility
//## Category: EBI2CADC (I2C ADC)%3F49CFE2030D
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin I2CADC_IDENTIFIERS%3F49FA8A0290.postscript preserve=yes
//## end I2CADC_IDENTIFIERS%3F49FA8A0290.postscript

//## begin module%3F49F7CF008C.epilog preserve=yes
//## end module%3F49F7CF008C.epilog


#endif
