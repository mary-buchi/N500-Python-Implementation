//## begin module%3EE7378E001F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE7378E001F.cm

//## begin module%3EE7378E001F.cp preserve=no
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
//## end module%3EE7378E001F.cp

//## Module: EBI2CEPROMident%3EE7378E001F; Package specification
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Source file: R:\Embedded\src\EBI2CEPROM\EBI2CEPROMident.h

#ifndef EBI2CEPROMident_h
#define EBI2CEPROMident_h 1

//## begin module%3EE7378E001F.additionalIncludes preserve=no
//## end module%3EE7378E001F.additionalIncludes

//## begin module%3EE7378E001F.includes preserve=yes
//## end module%3EE7378E001F.includes

//## begin module%3EE7378E001F.declarations preserve=no
//## end module%3EE7378E001F.declarations

//## begin module%3EE7378E001F.additionalDeclarations preserve=yes
//## end module%3EE7378E001F.additionalDeclarations


//## begin I2CEPROM_IDENTIFIERS%3EE82C87006D.preface preserve=yes
//## end I2CEPROM_IDENTIFIERS%3EE82C87006D.preface

//## Class: I2CEPROM_IDENTIFIERS%3EE82C87006D; Class Utility
//## Category: EBI2CEprom (I2C Eprom Device)%3EE73672030D
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin I2CEPROM_IDENTIFIERS%3EE82C87006D.postscript preserve=yes
#define I2CEPROM_ID                      _T("I2CEPROM")


// exception ID's
#define IDE_I2C_INTF_24LC515_HW_INTF_ERROR    	  	    2300
#define IDE_I2C_INTF_24LC515_READ_BYTE_ERROR            2301
#define IDE_I2C_INTF_24LC515_READ_BYTE_ACK_ERROR        2302
#define IDE_I2C_INTF_24LC515_DATA_BUFFER_ERROR          2303
#define IDE_I2C_INTF_24LC515_WRITE_BYTE_ERROR           2304
#define IDE_I2C_INTF_24LC515_WRITE_BYTE_ACK_ERROR       2305
#define IDE_I2C_INTF_24LC515_WRITE_PAGE_ACK_ERROR       2306
#define IDE_I2C_INTF_24LC515_WRITE_PAGE_DATA_ERROR      2307
#define IDE_I2C_INTF_24LC515_WRONG_DATA_SIZE      	    2308
#define IDE_I2C_INTF_24LC515_ACKNOWLEDGE_ERROR     	    2309
//## end I2CEPROM_IDENTIFIERS%3EE82C87006D.postscript

//## begin module%3EE7378E001F.epilog preserve=yes
//## end module%3EE7378E001F.epilog


#endif
