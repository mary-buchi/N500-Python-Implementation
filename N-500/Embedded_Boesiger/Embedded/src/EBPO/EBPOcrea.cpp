//## begin module%3DE5EAFF0004.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EAFF0004.cm

//## begin module%3DE5EAFF0004.cp preserve=no
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
//## end module%3DE5EAFF0004.cp

//## Module: EBPOcrea%3DE5EAFF0004; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EAFF0004.additionalIncludes preserve=no
//## end module%3DE5EAFF0004.additionalIncludes

//## begin module%3DE5EAFF0004.includes preserve=yes
//## end module%3DE5EAFF0004.includes

// EBPOintf
#include "EBPOintf.h"
// EBPOcrea
#include "EBPOcrea.h"
//## begin module%3DE5EAFF0004.declarations preserve=no
//## end module%3DE5EAFF0004.declarations

//## begin module%3DE5EAFF0004.additionalDeclarations preserve=yes
//## end module%3DE5EAFF0004.additionalDeclarations


// Class CPOPersistentObjCreatorV0 

CPOPersistentObjCreatorV0::CPOPersistentObjCreatorV0()
  //## begin CPOPersistentObjCreatorV0::CPOPersistentObjCreatorV0%.hasinit preserve=no
  //## end CPOPersistentObjCreatorV0::CPOPersistentObjCreatorV0%.hasinit
  //## begin CPOPersistentObjCreatorV0::CPOPersistentObjCreatorV0%.initialization preserve=yes
  :CPIObjCreatorPersistentObject(_T(""))
  //## end CPOPersistentObjCreatorV0::CPOPersistentObjCreatorV0%.initialization
{
  //## begin CPOPersistentObjCreatorV0::CPOPersistentObjCreatorV0%.body preserve=yes
  //## end CPOPersistentObjCreatorV0::CPOPersistentObjCreatorV0%.body
}


CPOPersistentObjCreatorV0::~CPOPersistentObjCreatorV0()
{
  //## begin CPOPersistentObjCreatorV0::~CPOPersistentObjCreatorV0%.body preserve=yes
  //## end CPOPersistentObjCreatorV0::~CPOPersistentObjCreatorV0%.body
}



//## Other Operations (implementation)
IPIPersistentObjInterface* CPOPersistentObjCreatorV0::Create (UINT p_uiID)
{
  //## begin CPOPersistentObjCreatorV0::Create%1038493580.body preserve=yes
	IPIPersistentObjInterface* l_Intf = new CPOPersistentObjInterface(p_uiID);
    l_Intf->InitInstance();

	return l_Intf;
  //## end CPOPersistentObjCreatorV0::Create%1038493580.body
}

// Additional Declarations
  //## begin CPOPersistentObjCreatorV0%3DE626DA02F2.declarations preserve=yes
  //## end CPOPersistentObjCreatorV0%3DE626DA02F2.declarations

//## begin module%3DE5EAFF0004.epilog preserve=yes
//## end module%3DE5EAFF0004.epilog
