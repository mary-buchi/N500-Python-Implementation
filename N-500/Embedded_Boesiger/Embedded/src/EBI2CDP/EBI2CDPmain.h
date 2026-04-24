//## begin module%3F4B4EA9002E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F4B4EA9002E.cm

//## begin module%3F4B4EA9002E.cp preserve=no
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
//## end module%3F4B4EA9002E.cp

//## Module: EBI2CDPmain%3F4B4EA9002E; Package specification
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Source file: R:\Embedded\src\EBI2CDP\EBI2CDPmain.h

#ifndef EBI2CDPmain_h
#define EBI2CDPmain_h 1

//## begin module%3F4B4EA9002E.additionalIncludes preserve=no
//## end module%3F4B4EA9002E.additionalIncludes

//## begin module%3F4B4EA9002E.includes preserve=yes
//## end module%3F4B4EA9002E.includes

//## begin module%3F4B4EA9002E.declarations preserve=no
//## end module%3F4B4EA9002E.declarations

//## begin module%3F4B4EA9002E.additionalDeclarations preserve=yes
extern "C" EBI2CDP_DLL_DECL void InitInstance();

extern "C" EBI2CDP_DLL_DECL void ExitInstance();
//## end module%3F4B4EA9002E.additionalDeclarations


//## begin I2CDP_MAIN%3F4B642B0196.preface preserve=yes
//## end I2CDP_MAIN%3F4B642B0196.preface

//## Class: I2CDP_MAIN%3F4B642B0196
//## Category: EBI2CDP (I2C Digital Potentiometer)%3F4B4CE20177
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F4B646501F4;CI2CDPInterfaceRegistry { -> }

// This Class is Implementation Only
//## begin I2CDP_MAIN%3F4B642B0196.postscript preserve=yes
//## end I2CDP_MAIN%3F4B642B0196.postscript

//## begin module%3F4B4EA9002E.epilog preserve=yes
//## end module%3F4B4EA9002E.epilog


#endif
