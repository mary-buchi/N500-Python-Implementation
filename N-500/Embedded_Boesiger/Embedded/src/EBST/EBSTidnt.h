//## begin module%3DA6BE7B0210.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA6BE7B0210.cm

//## begin module%3DA6BE7B0210.cp preserve=no
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
//## end module%3DA6BE7B0210.cp

//## Module: EBSTidnt%3DA6BE7B0210; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTidnt.h

#ifndef EBSTidnt_h
#define EBSTidnt_h 1

//## begin module%3DA6BE7B0210.additionalIncludes preserve=no
//## end module%3DA6BE7B0210.additionalIncludes

//## begin module%3DA6BE7B0210.includes preserve=yes
//## end module%3DA6BE7B0210.includes

//## begin module%3DA6BE7B0210.declarations preserve=no
//## end module%3DA6BE7B0210.declarations

//## begin module%3DA6BE7B0210.additionalDeclarations preserve=yes
#define ST_ID					_T("ST")

// exception ID's
#define IDE_ST_HARD_LIMIT_HIT				1400
#define IDE_ST_SOFT_LIMIT_HIT				1401
#define IDE_ST_STEPS_DEVIATION				1402
#define IDE_ST_HOMING_LIMIT_CONFIG			1403 
#define IDE_ST_HOMING_SENSOR_NOT_FOUND		1404 
#define IDE_ST_HOMING_REPEAT_ACCURACY		1405
#define IDE_ST_LMIT_JITTER					1406
#define IDE_ST_MULTI_FOOTPRINT_LIMITS		1407	// only one footprint limit switch allowed
#define IDE_ST_FOOTPRINT_LIMIT_NOT_FOUND	1408	// get footprint executed, but no footprint limitswitch configured
#define IDE_ST_LIMITSWITCH_NOT_FOUND		1409	// change config executed, but switch id doesn't exist. switch wasn't added to this motor.

// action ID's
#define IDA_MOVE						0

static const INT STOP					= 0x0;
static const INT CONTINUOUS				= 0xFFFFF;
static const INT MIN_JITTER_TIME		= 50;		// 50ms
static const INT MAX_STEPS_DEVIATION	= 10;

//## end module%3DA6BE7B0210.additionalDeclarations


//## begin ST_IDENTIFIERS%3DA6BE85028D.preface preserve=yes
//## end ST_IDENTIFIERS%3DA6BE85028D.preface

//## Class: ST_IDENTIFIERS%3DA6BE85028D; Class Utility
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

// This Class is Implementation Only
//## begin ST_IDENTIFIERS%3DA6BE85028D.postscript preserve=yes
//## end ST_IDENTIFIERS%3DA6BE85028D.postscript

//## begin module%3DA6BE7B0210.epilog preserve=yes
//## end module%3DA6BE7B0210.epilog


#endif

