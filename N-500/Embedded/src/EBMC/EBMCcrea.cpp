//## begin module%3DAAD4C40014.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAD4C40014.cm

//## begin module%3DAAD4C40014.cp preserve=no
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
//## end module%3DAAD4C40014.cp

//## Module: EBMCcrea%3DAAD4C40014; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DAAD4C40014.additionalIncludes preserve=no
//## end module%3DAAD4C40014.additionalIncludes

//## begin module%3DAAD4C40014.includes preserve=yes
//## end module%3DAAD4C40014.includes

// EBMCintf
#include "EBMCintf.h"
// EBMCcrea
#include "EBMCcrea.h"


//## begin module%3DAAD4C40014.declarations preserve=no
//## end module%3DAAD4C40014.declarations

//## begin module%3DAAD4C40014.additionalDeclarations preserve=yes
//## end module%3DAAD4C40014.additionalDeclarations


// Class CMCMeasurementChannelCreatorV0 

CMCMeasurementChannelCreatorV0::CMCMeasurementChannelCreatorV0()
  //## begin CMCMeasurementChannelCreatorV0::CMCMeasurementChannelCreatorV0%.hasinit preserve=no
  //## end CMCMeasurementChannelCreatorV0::CMCMeasurementChannelCreatorV0%.hasinit
  //## begin CMCMeasurementChannelCreatorV0::CMCMeasurementChannelCreatorV0%.initialization preserve=yes
  : CPIObjCreatorMeasurementChannel(_T(""))
  //## end CMCMeasurementChannelCreatorV0::CMCMeasurementChannelCreatorV0%.initialization
{
  //## begin CMCMeasurementChannelCreatorV0::CMCMeasurementChannelCreatorV0%.body preserve=yes
  //## end CMCMeasurementChannelCreatorV0::CMCMeasurementChannelCreatorV0%.body
}


CMCMeasurementChannelCreatorV0::~CMCMeasurementChannelCreatorV0()
{
  //## begin CMCMeasurementChannelCreatorV0::~CMCMeasurementChannelCreatorV0%.body preserve=yes
  //## end CMCMeasurementChannelCreatorV0::~CMCMeasurementChannelCreatorV0%.body
}



//## Other Operations (implementation)
IPIMeasurementChannelInterface* CMCMeasurementChannelCreatorV0::Create (UINT p_uiID)
{
  //## begin CMCMeasurementChannelCreatorV0::Create%1034575109.body preserve=yes
    IPIMeasurementChannelInterface* l_Intf = new CMCMeasurementChannelInterface(p_uiID);
    l_Intf->InitInstance();

	return l_Intf;
  //## end CMCMeasurementChannelCreatorV0::Create%1034575109.body
}

// Additional Declarations
  //## begin CMCMeasurementChannelCreatorV0%3DAAD4A8018B.declarations preserve=yes
  //## end CMCMeasurementChannelCreatorV0%3DAAD4A8018B.declarations

//## begin module%3DAAD4C40014.epilog preserve=yes
//## end module%3DAAD4C40014.epilog
