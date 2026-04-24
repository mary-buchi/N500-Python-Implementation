//## begin module%3FDD89000271.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FDD89000271.cm

//## begin module%3FDD89000271.cp preserve=no
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
//## end module%3FDD89000271.cp

//## Module: EBI2CEPROMmain%3FDD89000271; Package specification
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Source file: R:\Embedded\src\EBI2CEPROM\EBI2CEPROMmain.h

#ifndef EBI2CEPROMmain_h
#define EBI2CEPROMmain_h 1

//## begin module%3FDD89000271.additionalIncludes preserve=no
//## end module%3FDD89000271.additionalIncludes

//## begin module%3FDD89000271.includes preserve=yes
//## end module%3FDD89000271.includes

//## begin module%3FDD89000271.declarations preserve=no
//## end module%3FDD89000271.declarations

//## begin module%3FDD89000271.additionalDeclarations preserve=yes
extern "C" EBI2CEPROM_DLL_DECL void InitInstance();

extern "C" EBI2CEPROM_DLL_DECL void ExitInstance();
//## end module%3FDD89000271.additionalDeclarations


//## begin I2CEPROM_MAIN%3FDD86A701A5.preface preserve=yes
//## end I2CEPROM_MAIN%3FDD86A701A5.preface

//## Class: I2CEPROM_MAIN%3FDD86A701A5; Class Utility
//## Category: EBI2CEprom (I2C Eprom Device)%3EE73672030D
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FDD8A690213;CI2CEpromInterfaceRegistry { -> }

// This Class is Implementation Only
//## begin I2CEPROM_MAIN%3FDD86A701A5.postscript preserve=yes
//## end I2CEPROM_MAIN%3FDD86A701A5.postscript

//## begin module%3FDD89000271.epilog preserve=yes
//## end module%3FDD89000271.epilog


#endif
