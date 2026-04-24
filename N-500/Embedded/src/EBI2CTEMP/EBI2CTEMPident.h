//## begin module%3EE73726003E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE73726003E.cm

//## begin module%3EE73726003E.cp preserve=no
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
//## end module%3EE73726003E.cp

//## Module: EBI2CTEMPident%3EE73726003E; Package specification
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Source file: R:\Embedded\src\EBI2CTEMP\EBI2CTEMPident.h

#ifndef EBI2CTEMPident_h
#define EBI2CTEMPident_h 1

//## begin module%3EE73726003E.additionalIncludes preserve=no
//## end module%3EE73726003E.additionalIncludes

//## begin module%3EE73726003E.includes preserve=yes
//## end module%3EE73726003E.includes

//## begin module%3EE73726003E.declarations preserve=no
//## end module%3EE73726003E.declarations

//## begin module%3EE73726003E.additionalDeclarations preserve=yes
#define I2CTEMP_ID           _T("I2CTEMP")

// exception ID's
#define IDE_I2C_INTF_DS1631Z_HW_INTF_ERROR    	  		  2400
#define IDE_I2C_INTF_DS1631Z_WRONG_ID             		  2401
#define IDE_I2C_INTF_DS1631Z_SET_CONFIG_ERROR	    	  2402
#define IDE_I2C_INTF_DS1631Z_SET_CONFIG_ACK_ERROR 		  2403
#define IDE_I2C_INTF_DS1631Z_GET_CONFIG_ERROR      		  2404
#define IDE_I2C_INTF_DS1631Z_GET_CONFIG_ACK_ERROR 		  2405
#define IDE_I2C_INTF_DS1631Z_START_TEMP_ERROR      		  2406
#define IDE_I2C_INTF_DS1631Z_START_TEMP_ACK_ERROR 		  2407
#define IDE_I2C_INTF_DS1631Z_STOP_TEMP_ERROR 	      	  2408
#define IDE_I2C_INTF_DS1631Z_STOP_TEMP_ACK_ERROR 	  	  2409
#define IDE_I2C_INTF_DS1631Z_GET_TEMP_ERROR       		  2410
#define IDE_I2C_INTF_DS1631Z_GET_TEMP_ACK_ERROR    		  2411
#define IDE_I2C_INTF_DS1631Z_WRONG_DATA_SIZE      		  2412
#define IDE_I2C_INTF_DS1631Z_MODEONESHOT_NOT_SUPPORTED	  2413


//## end module%3EE73726003E.additionalDeclarations


//## begin I2CTEMP_IDENTIFIERS%3EE8172C03A9.preface preserve=yes
//## end I2CTEMP_IDENTIFIERS%3EE8172C03A9.preface

//## Class: I2CTEMP_IDENTIFIERS%3EE8172C03A9; Class Utility
//## Category: EBI2CTemp (I2C Temperature Device)%3EE73654004E
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin I2CTEMP_IDENTIFIERS%3EE8172C03A9.postscript preserve=yes
//## end I2CTEMP_IDENTIFIERS%3EE8172C03A9.postscript

//## begin module%3EE73726003E.epilog preserve=yes
//## end module%3EE73726003E.epilog


#endif
