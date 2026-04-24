//## begin module%3DB50DDA012B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DB50DDA012B.cm

//## begin module%3DB50DDA012B.cp preserve=no
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
//## end module%3DB50DDA012B.cp

//## Module: EBPIenum%3DB50DDA012B; Package specification
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPIenum.h

#ifndef EBPIenum_h
#define EBPIenum_h 1

//## begin module%3DB50DDA012B.additionalIncludes preserve=no
//## end module%3DB50DDA012B.additionalIncludes

//## begin module%3DB50DDA012B.includes preserve=yes
//## end module%3DB50DDA012B.includes


class EBTC_DLL_DECL CTCLogic;

//## begin module%3DB50DDA012B.declarations preserve=no
//## end module%3DB50DDA012B.declarations

//## begin module%3DB50DDA012B.additionalDeclarations preserve=yes
//## end module%3DB50DDA012B.additionalDeclarations


//## begin EPIMotorPolarity%3DB50CE403DA.preface preserve=yes
//## end EPIMotorPolarity%3DB50CE403DA.preface

//## Class: EPIMotorPolarity%3DB50CE403DA
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum { ePIMotorPolarityNormal, ePIMotorPolarityReverse } EPIMotorPolarity;

//## begin EPIMotorPolarity%3DB50CE403DA.postscript preserve=yes
//## end EPIMotorPolarity%3DB50CE403DA.postscript

//## begin EPILimitAction%3DB50CF902A2.preface preserve=yes
//## end EPILimitAction%3DB50CF902A2.preface

//## Class: EPILimitAction%3DB50CF902A2
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {ePILimitActionDisabled, ePILimitActionStop, ePILimitActionDecelerate, ePILimitActionFootprint } EPILimitAction;

//## begin EPILimitAction%3DB50CF902A2.postscript preserve=yes
//## end EPILimitAction%3DB50CF902A2.postscript

//## begin EPILimitCharacteristics%3DB50D030215.preface preserve=yes
//## end EPILimitCharacteristics%3DB50D030215.preface

//## Class: EPILimitCharacteristics%3DB50D030215
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum { ePILimitHardEdgeRaising, ePILimitHardEdgeFalling, ePILimitSoftEdgeRaising, ePILimitSoftEdgeFalling} EPILimitCharacteristics;

//## begin EPILimitCharacteristics%3DB50D030215.postscript preserve=yes
//## end EPILimitCharacteristics%3DB50D030215.postscript

//## begin EPIPersistentParameterType%3DB8F3CE03BC.preface preserve=yes
//## end EPIPersistentParameterType%3DB8F3CE03BC.preface

//## Class: EPIPersistentParameterType%3DB8F3CE03BC
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum { ePIParameterTypeInt, ePIParameterTypeString, ePIParameterTypeDouble } EPIPersistentParameterType;

//## begin EPIPersistentParameterType%3DB8F3CE03BC.postscript preserve=yes
//## end EPIPersistentParameterType%3DB8F3CE03BC.postscript

//## begin EPIPolarity%3DB9299300B4.preface preserve=yes
//## end EPIPolarity%3DB9299300B4.preface

//## Class: EPIPolarity%3DB9299300B4
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum { eSensorActiveHigh, eSensorActiveLow } EPIPolarity;

//## begin EPIPolarity%3DB9299300B4.postscript preserve=yes
//## end EPIPolarity%3DB9299300B4.postscript

//## begin EPILifeTimeCounter%3E9AB1D3039A.preface preserve=yes
//## end EPILifeTimeCounter%3E9AB1D3039A.preface

//## Class: EPILifeTimeCounter%3E9AB1D3039A
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {eLampPrimary, 
	eLampSecondary,
	eLaser,
	eInstrumentUnit,
	eScan,
	eDetector
	} EPILifeTimeCounter;

//## begin EPILifeTimeCounter%3E9AB1D3039A.postscript preserve=yes
//## end EPILifeTimeCounter%3E9AB1D3039A.postscript

//## begin EPILamp%3F66F4AA023F.preface preserve=yes
//## end EPILamp%3F66F4AA023F.preface

//## Class: EPILamp%3F66F4AA023F
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {ePrimaryLamp, eSecondaryLamp} EPILamp;

//## begin EPILamp%3F66F4AA023F.postscript preserve=yes
//## end EPILamp%3F66F4AA023F.postscript

//## begin EPIRegisterType%3F939A5401D2.preface preserve=yes
//## end EPIRegisterType%3F939A5401D2.preface

//## Class: EPIRegisterType%3F939A5401D2
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum { eRead, eWrite } EPIRegisterType;

//## begin EPIRegisterType%3F939A5401D2.postscript preserve=yes
//## end EPIRegisterType%3F939A5401D2.postscript

//## begin EPIEpromSection%3FF159EE01DA.preface preserve=yes
//## end EPIEpromSection%3FF159EE01DA.preface

//## Class: EPIEpromSection%3FF159EE01DA
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum{ePISectionHeader, ePISectionIdent, ePISectionPara, ePISectionLifeTimeCounter} EPIEpromSection;

//## begin EPIEpromSection%3FF159EE01DA.postscript preserve=yes
//## end EPIEpromSection%3FF159EE01DA.postscript

//## begin EPIHeaterState%40CD891203E0.preface preserve=yes
//## end EPIHeaterState%40CD891203E0.preface

//## Class: EPIHeaterState%40CD891203E0
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {eOn, eOff, ePwm} EPIHeaterState;

//## begin EPIHeaterState%40CD891203E0.postscript preserve=yes
//## end EPIHeaterState%40CD891203E0.postscript

//## begin EPILineVoltage%41947C5602CB.preface preserve=yes
//## end EPILineVoltage%41947C5602CB.preface

//## Class: EPILineVoltage%41947C5602CB
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {e115V, e230V} EPILineVoltage;

//## begin EPILineVoltage%41947C5602CB.postscript preserve=yes
//## end EPILineVoltage%41947C5602CB.postscript

//## begin module%3DB50DDA012B.epilog preserve=yes
//## end module%3DB50DDA012B.epilog


#endif
