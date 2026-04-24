//## begin module%3E26B74B01E2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E26B74B01E2.cm

//## begin module%3E26B74B01E2.cp preserve=no
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
//## end module%3E26B74B01E2.cp

//## Module: EBHITenum%3E26B74B01E2; Package specification
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Source file: R:\Embedded\src\EBHIT\EBHITenum.h

#ifndef EBHITenum_h
#define EBHITenum_h 1

//## begin module%3E26B74B01E2.additionalIncludes preserve=no
//## end module%3E26B74B01E2.additionalIncludes

//## begin module%3E26B74B01E2.includes preserve=yes
//## end module%3E26B74B01E2.includes

//## begin module%3E26B74B01E2.declarations preserve=no
//## end module%3E26B74B01E2.declarations

//## begin module%3E26B74B01E2.additionalDeclarations preserve=yes
//## end module%3E26B74B01E2.additionalDeclarations


//## begin EHIWCPosState%3E3FC6C80157.preface preserve=yes
//## end EHIWCPosState%3E3FC6C80157.preface

//## Class: EHIWCPosState%3E3FC6C80157
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum{eHIWCIniPos, eHIWCAccForward, eHIWCVNomForward, eHIWCtoFStartMesPos, eHIWCFStartMesPos, eHIWCFMeasuring, eHIWCEndFMesuring, eHIWCtoFEndPos, eHIWCFEndPos, eHIWCDecForward, eHIWCReversePos, eHIWCAccBackward, eHIWCVNomBackward, eHIWCtoBStartMesPos, eHIWCBStartMesPos, eHIWCBMeasuring, eHIWCEndBMesuring, eHIWCtoBEndPos, eHIWCBEndPos, eHIWCSearchLb, eHIWCLbDetected, eHIWCDecBackward, eHIWCRefDistance1, eHIWCRefDistance2, eHIWCEnd} EHIWCPosState;

//## begin EHIWCPosState%3E3FC6C80157.postscript preserve=yes
//## end EHIWCPosState%3E3FC6C80157.postscript

//## begin EHIWCState%3E37F30D003E.preface preserve=yes
//## end EHIWCState%3E37F30D003E.preface

//## Class: EHIWCState%3E37F30D003E
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum{eHIWCNotIni, eHIWCIniActive, eHIWCIni, eHIWCRefActive, eHIWCRef, eHIWCMeasureActive, eHIWCMeasure, eHIWCParkActive, eHIWCPark} EHIWCState;

//## begin EHIWCState%3E37F30D003E.postscript preserve=yes
//## end EHIWCState%3E37F30D003E.postscript

//## begin EHITOpenEventRegistration%3E786D9603A9.preface preserve=yes
//## end EHITOpenEventRegistration%3E786D9603A9.preface

//## Class: EHITOpenEventRegistration%3E786D9603A9
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {eHITHigh, eHITLow} EHITOpenEventRegistration;

//## begin EHITOpenEventRegistration%3E786D9603A9.postscript preserve=yes
//## end EHITOpenEventRegistration%3E786D9603A9.postscript

//## begin module%3E26B74B01E2.epilog preserve=yes
//## end module%3E26B74B01E2.epilog


#endif
