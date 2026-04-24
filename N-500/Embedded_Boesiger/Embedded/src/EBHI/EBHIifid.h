//## begin module%3F5436680261.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F5436680261.cm

//## begin module%3F5436680261.cp preserve=no
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
//## end module%3F5436680261.cp

//## Module: EBHIifid%3F5436680261; Package specification
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIifid.h

#ifndef EBHIifid_h
#define EBHIifid_h 1

//## begin module%3F5436680261.additionalIncludes preserve=no
//## end module%3F5436680261.additionalIncludes

//## begin module%3F5436680261.includes preserve=yes
//## end module%3F5436680261.includes

//## begin module%3F5436680261.declarations preserve=no
//## end module%3F5436680261.declarations

//## begin module%3F5436680261.additionalDeclarations preserve=yes
//## end module%3F5436680261.additionalDeclarations
// static ID's
#define IU_IDLED2Red				2002 // (Output) ID of LED 2 red
#define IU_IDLED3Red            	2003 // (Output) ID of LED 3 red
#define IU_IDLED4Yellow         	2004 // (Output) ID of LED 4 yellow
#define IU_IDLED5Yellow         	2005 // (Output) ID of LED 5 yellow
#define IU_IDLED6Green          	2006 // (Output) ID of LED 6 green
#define IU_IDLED7Green          	2007 // (Output) ID of LED 7 green

// static ID's lamp control
#define IU_IDLmpActCurrent      	3000 // (Output) ID process register 
#define IU_IDLmpActVoltagePri   	3001 // (Output) ID process register 
#define IU_IDLmpActVoltageSec   	3003 // (Output) ID process register 
#define IU_IDLmpNomVoltage      	4000 // (Output) ID process register 
#define IU_IDLmpSelection       	2023 // (Output) ID process register 
#define IU_IDLmpOnOff           	2022 // (Output) ID process register 

// static ID's dig. output
#define IU_IDIOLaser				2020 // (Output) ID of Laser

// static ID's MC
#define MC_IDDockingState           1100
#define MC_IDButtonStart            1105
#define MC_IDButtonStop             1106

// static ID's analog input
#define IU_IDHwWarningErrorState  	3010 // (input) ID of HW exceptions

//## end HI_PCINTF_IDENTIFIERS%3F5435BD0251.preface

//## Class: HI_PCINTF_IDENTIFIERS%3F5435BD0251; Class Utility
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin HI_PCINTF_IDENTIFIERS%3F5435BD0251.postscript preserve=yes
//## end HI_PCINTF_IDENTIFIERS%3F5435BD0251.postscript

//## begin module%3F5436680261.epilog preserve=yes
//## end module%3F5436680261.epilog


#endif
