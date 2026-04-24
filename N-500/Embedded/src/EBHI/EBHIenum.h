//## begin module%3E880B2E009C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E880B2E009C.cm

//## begin module%3E880B2E009C.cp preserve=no
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
//## end module%3E880B2E009C.cp

//## Module: EBHIenum%3E880B2E009C; Package specification
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIenum.h

#ifndef EBHIenum_h
#define EBHIenum_h 1

//## begin module%3E880B2E009C.additionalIncludes preserve=no
//## end module%3E880B2E009C.additionalIncludes

//## begin module%3E880B2E009C.includes preserve=yes
//## end module%3E880B2E009C.includes

//## begin module%3E880B2E009C.declarations preserve=no
//## end module%3E880B2E009C.declarations

//## begin module%3E880B2E009C.additionalDeclarations preserve=yes
//## end module%3E880B2E009C.additionalDeclarations


//## begin EHIOpenEventRegistration%3E880B550242.preface preserve=yes
//## end EHIOpenEventRegistration%3E880B550242.preface

//## Class: EHIOpenEventRegistration%3E880B550242
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {eHIUndefined, eHILow, eHIHigh} EHIOpenEventRegistration;

//## begin EHIOpenEventRegistration%3E880B550242.postscript preserve=yes
//## end EHIOpenEventRegistration%3E880B550242.postscript

//## begin EHIProcessImageDataType%3EB65AA7009C.preface preserve=yes
//## end EHIProcessImageDataType%3EB65AA7009C.preface

//## Class: EHIProcessImageDataType%3EB65AA7009C
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {eHIBool, eHIWORD, eHIDWORD, eHIInt} EHIProcessImageDataType;

//## begin EHIProcessImageDataType%3EB65AA7009C.postscript preserve=yes
//## end EHIProcessImageDataType%3EB65AA7009C.postscript

//## begin EHIStaticObjID%3F9D2C840266.preface preserve=yes
//## end EHIStaticObjID%3F9D2C840266.preface

//## Class: EHIStaticObjID%3F9D2C840266
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {
  eHILedGreen,
  eHILedRed,
  eHIIDLmpActCurrent,
  eHIIDLmpActVoltagePri,
  eHIIDLmpActVoltageSec,
  eHIIDLmpNomVoltage,
  eHIIDLmpSelection,
  eHIIDLmpOnOff,
  eHILmpStandByVoltage,
  eHILmpNomVoltageLLimit,
  eHILmpActCurrLLimit,
  eHIIDIOLaser,
  eHIIDDockingState,
  eHIIDButtonStart,
  eHIIDButtonStop,
  eHIIDHwExceptions} EHIStaticObjID;

//## begin EHIStaticObjID%3F9D2C840266.postscript preserve=yes
//## end EHIStaticObjID%3F9D2C840266.postscript

//## begin EHIEventMaskType%3FC20B3B029F.preface preserve=yes
//## end EHIEventMaskType%3FC20B3B029F.preface

//## Class: EHIEventMaskType%3FC20B3B029F
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum{eHIHardwareEvent, eHIWedgeControlEvent} EHIEventMaskType;

//## begin EHIEventMaskType%3FC20B3B029F.postscript preserve=yes
//## end EHIEventMaskType%3FC20B3B029F.postscript

//## begin EHIWatchDogTime%422331F900A7.preface preserve=yes
//## end EHIWatchDogTime%422331F900A7.preface

//## Class: EHIWatchDogTime%422331F900A7
//	-----------------------------
//	See datasheet maxim max6369-max6374 sheet 5.
//	-----------------------------
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef  enum {
 eHIWd1ms = 0, 
 eHIWd10ms = 1, 
 eHIWd30ms = 2, 
 eHIWdDisabled = 3, 
 eHIWd100ms = 4, 
 eHIWd1s = 5, 
 eHIWd10s = 6, 
 eHIWd60s = 7} EHIWatchDogTime;

//## begin EHIWatchDogTime%422331F900A7.postscript preserve=yes
//## end EHIWatchDogTime%422331F900A7.postscript

//## begin module%3E880B2E009C.epilog preserve=yes
//## end module%3E880B2E009C.epilog


#endif
