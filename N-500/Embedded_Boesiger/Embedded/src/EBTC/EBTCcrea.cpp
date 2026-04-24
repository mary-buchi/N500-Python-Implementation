//## begin module%3DE5EDC60081.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EDC60081.cm

//## begin module%3DE5EDC60081.cp preserve=no
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
//## end module%3DE5EDC60081.cp

//## Module: EBTCcrea%3DE5EDC60081; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EDC60081.additionalIncludes preserve=no
//## end module%3DE5EDC60081.additionalIncludes

//## begin module%3DE5EDC60081.includes preserve=yes
//## end module%3DE5EDC60081.includes

// EBTCintf
#include "EBTCintf.h"
// EBTCcrea
#include "EBTCcrea.h"
//## begin module%3DE5EDC60081.declarations preserve=no
//## end module%3DE5EDC60081.declarations

//## begin module%3DE5EDC60081.additionalDeclarations preserve=yes
//## end module%3DE5EDC60081.additionalDeclarations


// Class CTCTemperatureControlCreatorV0 

CTCTemperatureControlCreatorV0::CTCTemperatureControlCreatorV0()
  //## begin CTCTemperatureControlCreatorV0::CTCTemperatureControlCreatorV0%.hasinit preserve=no
  //## end CTCTemperatureControlCreatorV0::CTCTemperatureControlCreatorV0%.hasinit
  //## begin CTCTemperatureControlCreatorV0::CTCTemperatureControlCreatorV0%.initialization preserve=yes
    :CPIObjCreatorTemperatureControl(_T(""))
  //## end CTCTemperatureControlCreatorV0::CTCTemperatureControlCreatorV0%.initialization
{
  //## begin CTCTemperatureControlCreatorV0::CTCTemperatureControlCreatorV0%.body preserve=yes
  //## end CTCTemperatureControlCreatorV0::CTCTemperatureControlCreatorV0%.body
}


CTCTemperatureControlCreatorV0::~CTCTemperatureControlCreatorV0()
{
  //## begin CTCTemperatureControlCreatorV0::~CTCTemperatureControlCreatorV0%.body preserve=yes
  //## end CTCTemperatureControlCreatorV0::~CTCTemperatureControlCreatorV0%.body
}



//## Other Operations (implementation)
IPITemperatureControlInterface* CTCTemperatureControlCreatorV0::Create (UINT p_uiID)
{
  //## begin CTCTemperatureControlCreatorV0::Create%1038899301.body preserve=yes
	IPITemperatureControlInterface* l_Intf = new CTCTemperatureControlInterface(p_uiID);
    l_Intf->InitInstance();

	return l_Intf;
  //## end CTCTemperatureControlCreatorV0::Create%1038899301.body
}

// Additional Declarations
  //## begin CTCTemperatureControlCreatorV0%3DEC5681031D.declarations preserve=yes
  //## end CTCTemperatureControlCreatorV0%3DEC5681031D.declarations

// Class CTCTemperatureControlCreatorV2 

CTCTemperatureControlCreatorV2::CTCTemperatureControlCreatorV2()
  //## begin CTCTemperatureControlCreatorV2::CTCTemperatureControlCreatorV2%.hasinit preserve=no
  //## end CTCTemperatureControlCreatorV2::CTCTemperatureControlCreatorV2%.hasinit
  //## begin CTCTemperatureControlCreatorV2::CTCTemperatureControlCreatorV2%.initialization preserve=yes
    :CPIObjCreatorTemperatureControl(_T("2"))
  //## end CTCTemperatureControlCreatorV2::CTCTemperatureControlCreatorV2%.initialization
{
  //## begin CTCTemperatureControlCreatorV2::CTCTemperatureControlCreatorV2%.body preserve=yes
  //## end CTCTemperatureControlCreatorV2::CTCTemperatureControlCreatorV2%.body
}


CTCTemperatureControlCreatorV2::~CTCTemperatureControlCreatorV2()
{
  //## begin CTCTemperatureControlCreatorV2::~CTCTemperatureControlCreatorV2%.body preserve=yes
  //## end CTCTemperatureControlCreatorV2::~CTCTemperatureControlCreatorV2%.body
}



//## Other Operations (implementation)
IPITemperatureControlInterface* CTCTemperatureControlCreatorV2::Create (UINT p_uiID)
{
  //## begin CTCTemperatureControlCreatorV2::Create%1218193718.body preserve=yes
	IPITemperatureControlInterface* l_Intf = new CTCTemperatureControlInterface2(p_uiID);
    l_Intf->InitInstance();

	return l_Intf;
  //## end CTCTemperatureControlCreatorV2::Create%1218193718.body
}

// Additional Declarations
  //## begin CTCTemperatureControlCreatorV2%489C283403A8.declarations preserve=yes
  //## end CTCTemperatureControlCreatorV2%489C283403A8.declarations

//## begin module%3DE5EDC60081.epilog preserve=yes
//## end module%3DE5EDC60081.epilog
