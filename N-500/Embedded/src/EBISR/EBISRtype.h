//## begin module%3E4216FE0280.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E4216FE0280.cm

//## begin module%3E4216FE0280.cp preserve=no
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
//## end module%3E4216FE0280.cp

//## Module: EBISRtype%3E4216FE0280; Package specification
//## Subsystem: EBISR (Interrupt Service Routine)%3E40DF6A00CB
//## Source file: R:\Embedded\src\EBISR\EBISRtype.h

#ifndef EBISRtype_h
#define EBISRtype_h 1

//## begin module%3E4216FE0280.additionalIncludes preserve=no
//## end module%3E4216FE0280.additionalIncludes

//## begin module%3E4216FE0280.includes preserve=yes
//## end module%3E4216FE0280.includes

//## begin module%3E4216FE0280.declarations preserve=no
//## end module%3E4216FE0280.declarations

//## begin module%3E4216FE0280.additionalDeclarations preserve=yes
//## end module%3E4216FE0280.additionalDeclarations


//## begin EISRWCPosState%3E4215A202BF.preface preserve=yes
//## end EISRWCPosState%3E4215A202BF.preface

//## Class: EISRWCPosState%3E4215A202BF
//## Category: EBISR (Interrupt Service Routine)%3E40DF26004E
//## Subsystem: EBISR (Interrupt Service Routine)%3E40DF6A00CB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum{
eWCIdle,
eWCIniPos, 
eWCStartPos,
eWCAccForward,
eWCNomVelocityForward,
eWCForwardMeasuring,
eWCDecForward,
eWCReversePos,
eWCAccBackward,
eWCNomVelocityBackward,
eWCBackwardMeasuring,
eWCDecBackward,
eWCEnd} EISRWCPosState;

//## begin EISRWCPosState%3E4215A202BF.postscript preserve=yes
//## end EISRWCPosState%3E4215A202BF.postscript

//## begin EISRWCState%3E4A5F9800DA.preface preserve=yes
//## end EISRWCState%3E4A5F9800DA.preface

//## Class: EISRWCState%3E4A5F9800DA
//## Category: EBISR (Interrupt Service Routine)%3E40DF26004E
//## Subsystem: EBISR (Interrupt Service Routine)%3E40DF6A00CB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum{
eWCNotIni,
eWCNoConfig,
eWCConfig,
eWCProfile,
eWCInitialize,
eWCInitialized,
eWCNotReferenced,
eWCReferencing,
eWCReferenced,
eWCMeasuring,
eWCEndMeasuring,
eWCParking,
eWCParked,
eWCStopping,
eWCStopped} EISRWCState;

//## begin EISRWCState%3E4A5F9800DA.postscript preserve=yes
//## end EISRWCState%3E4A5F9800DA.postscript

//## begin module%3E4216FE0280.epilog preserve=yes
//## end module%3E4216FE0280.epilog


#endif
