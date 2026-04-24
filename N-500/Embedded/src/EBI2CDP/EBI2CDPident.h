//## begin module%3F4B4E6B0000.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F4B4E6B0000.cm

//## begin module%3F4B4E6B0000.cp preserve=no
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
//## end module%3F4B4E6B0000.cp

//## Module: EBI2CDPident%3F4B4E6B0000; Package specification
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Source file: R:\Embedded\src\EBI2CDP\EBI2CDPident.h

#ifndef EBI2CDPident_h
#define EBI2CDPident_h 1

//## begin module%3F4B4E6B0000.additionalIncludes preserve=no
//## end module%3F4B4E6B0000.additionalIncludes

//## begin module%3F4B4E6B0000.includes preserve=yes
//## end module%3F4B4E6B0000.includes

//## begin module%3F4B4E6B0000.declarations preserve=no
//## end module%3F4B4E6B0000.declarations

//## begin module%3F4B4E6B0000.additionalDeclarations preserve=yes
#define I2CDP_ID           "I2CDP"


// exception ID's
#define IDE_I2C_INTF_AD5245_HW_INTF_ERROR    	  		  2200
#define IDE_I2C_INTF_AD5245_WRONG_ID             		  2201
#define IDE_I2C_INTF_AD5245_WRITE_ERROR	    		      2202
#define IDE_I2C_INTF_AD5245_WRITE_ACK_ERROR 		      2203
#define IDE_I2C_INTF_AD5245_READ_ERROR      		      2204
#define IDE_I2C_INTF_AD5245_READ_ACK_ERROR 		        2205
#define IDE_I2C_INTF_AD5245_WRONG_DATA_SIZE           2206

//## end module%3F4B4E6B0000.additionalDeclarations


//## begin I2CDP_IDENTIFIERS%3F4B4F4A00EA.preface preserve=yes
//## end I2CDP_IDENTIFIERS%3F4B4F4A00EA.preface

//## Class: I2CDP_IDENTIFIERS%3F4B4F4A00EA; Class Utility
//## Category: EBI2CDP (I2C Digital Potentiometer)%3F4B4CE20177
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin I2CDP_IDENTIFIERS%3F4B4F4A00EA.postscript preserve=yes
//## end I2CDP_IDENTIFIERS%3F4B4F4A00EA.postscript

//## begin module%3F4B4E6B0000.epilog preserve=yes
//## end module%3F4B4E6B0000.epilog


#endif
