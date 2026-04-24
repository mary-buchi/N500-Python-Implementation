//## begin module%3B8D3DA6005B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8D3DA6005B.cm

//## begin module%3B8D3DA6005B.cp preserve=no
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
//## end module%3B8D3DA6005B.cp

//## Module: EBCOenum%3B8D3DA6005B; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOenum.h

#ifndef EBCOenum_h
#define EBCOenum_h 1

//## begin module%3B8D3DA6005B.additionalIncludes preserve=no
//## end module%3B8D3DA6005B.additionalIncludes

//## begin module%3B8D3DA6005B.includes preserve=yes
//## end module%3B8D3DA6005B.includes

//## begin module%3B8D3DA6005B.declarations preserve=no
//## end module%3B8D3DA6005B.declarations

//## begin module%3B8D3DA6005B.additionalDeclarations preserve=yes
//## end module%3B8D3DA6005B.additionalDeclarations


//## begin ECOAsyncCallQueue%3B8D3DB300C8.preface preserve=yes
//## end ECOAsyncCallQueue%3B8D3DB300C8.preface

//## Class: ECOAsyncCallQueue%3B8D3DB300C8
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {
  eCOQueueNormal, 
  eCOQueueAboveNormal, 
  eCOQueueHigh,
  eCOQueueLastItem } ECOAsyncCallQueue;

//## begin ECOAsyncCallQueue%3B8D3DB300C8.postscript preserve=yes
//## end ECOAsyncCallQueue%3B8D3DB300C8.postscript

//## begin ECOAsyncThreadWakeUpReason%3B8D407D02E1.preface preserve=yes
//## end ECOAsyncThreadWakeUpReason%3B8D407D02E1.preface

//## Class: ECOAsyncThreadWakeUpReason%3B8D407D02E1
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {
  eCOWakeUpTerminateThread, 
  eCOWakeUpCommandNormal, 
  eCOWakeUpCommandAboveNormal,
  eCOWakeUpCommandHigh,
  eCOWakeUpImplEvent, 
  eCOWakeUpTimeout,
  eCOWakeUpLastItem } ECOAsyncThreadWakeUpReason;

//## begin ECOAsyncThreadWakeUpReason%3B8D407D02E1.postscript preserve=yes
//## end ECOAsyncThreadWakeUpReason%3B8D407D02E1.postscript

//## begin module%3B8D3DA6005B.epilog preserve=yes
//## end module%3B8D3DA6005B.epilog


#endif
