//## begin module%3DAE56270341.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAE56270341.cm

//## begin module%3DAE56270341.cp preserve=no
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
//## end module%3DAE56270341.cp

//## Module: EBMCtype%3DAE56270341; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCtype.h

#ifndef EBMCtype_h
#define EBMCtype_h 1

//## begin module%3DAE56270341.additionalIncludes preserve=no
//## end module%3DAE56270341.additionalIncludes

//## begin module%3DAE56270341.includes preserve=yes
//## end module%3DAE56270341.includes

// EBCOsypr
#include "EBCOsypr.h"

class EBPI_DLL_DECL CPIMeasurementChannelDataPackage;

//## begin module%3DAE56270341.declarations preserve=no
//## end module%3DAE56270341.declarations

//## begin module%3DAE56270341.additionalDeclarations preserve=yes
//## end module%3DAE56270341.additionalDeclarations


//## begin CMCSyncObjDataPackage%3DAE55EB02B4.preface preserve=yes
//## end CMCSyncObjDataPackage%3DAE55EB02B4.preface

//## Class: CMCSyncObjDataPackage%3DAE55EB02B4; Instantiated Class
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAE56750238;CPIMeasurementChannelDataPackage { -> F}

typedef CCOSyncObjectParameterized< CPIMeasurementChannelDataPackage* > CMCSyncObjDataPackage;

//## begin CMCSyncObjDataPackage%3DAE55EB02B4.postscript preserve=yes
//## end CMCSyncObjDataPackage%3DAE55EB02B4.postscript

//## begin CMCSyncObjDataPackage.instantiation preserve=no
template class CCOSyncObjectParameterized< CPIMeasurementChannelDataPackage* >;
//## end CMCSyncObjDataPackage.instantiation
//## begin module%3DAE56270341.epilog preserve=yes
//## end module%3DAE56270341.epilog


#endif
