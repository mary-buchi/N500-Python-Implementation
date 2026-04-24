//## begin module%3EE8634F02BF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE8634F02BF.cm

//## begin module%3EE8634F02BF.cp preserve=no
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
//## end module%3EE8634F02BF.cp

//## Module: EBI2CTEMPenum%3EE8634F02BF; Package specification
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Source file: R:\Embedded\src\EBI2CTEMP\EBI2CTEMPenum.h

#ifndef EBI2CTEMPenum_h
#define EBI2CTEMPenum_h 1

//## begin module%3EE8634F02BF.additionalIncludes preserve=no
//## end module%3EE8634F02BF.additionalIncludes

//## begin module%3EE8634F02BF.includes preserve=yes
//## end module%3EE8634F02BF.includes

//## begin module%3EE8634F02BF.declarations preserve=no
//## end module%3EE8634F02BF.declarations

//## begin module%3EE8634F02BF.additionalDeclarations preserve=yes
//## end module%3EE8634F02BF.additionalDeclarations


//## begin EI2CTEMPResolution%3EE8631901E4.preface preserve=yes
//## end EI2CTEMPResolution%3EE8631901E4.preface

//## Class: EI2CTEMPResolution%3EE8631901E4
//## Category: EBI2CTemp (I2C Temperature Device)%3EE73654004E
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum{eI2CTemp9BitResolution, eI2CTemp10BitResolution, eI2CTemp11BitResolution, eI2CTemp12BitResolution} EI2CTEMPResolution;

//## begin EI2CTEMPResolution%3EE8631901E4.postscript preserve=yes
//## end EI2CTEMPResolution%3EE8631901E4.postscript

//## begin module%3EE8634F02BF.epilog preserve=yes
//## end module%3EE8634F02BF.epilog


#endif
