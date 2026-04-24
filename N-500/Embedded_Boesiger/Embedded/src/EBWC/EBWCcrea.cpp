//## begin module%3DD0B45E01BF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD0B45E01BF.cm

//## begin module%3DD0B45E01BF.cp preserve=no
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
//## end module%3DD0B45E01BF.cp

//## Module: EBWCcrea%3DD0B45E01BF; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DD0B45E01BF.additionalIncludes preserve=no
//## end module%3DD0B45E01BF.additionalIncludes

//## begin module%3DD0B45E01BF.includes preserve=yes
//## end module%3DD0B45E01BF.includes

// EBWCintf
#include "EBWCintf.h"
// EBWCcrea
#include "EBWCcrea.h"
//## begin module%3DD0B45E01BF.declarations preserve=no
//## end module%3DD0B45E01BF.declarations

//## begin module%3DD0B45E01BF.additionalDeclarations preserve=yes
//## end module%3DD0B45E01BF.additionalDeclarations


// Class CWCWedgeControlCreatorV0 

CWCWedgeControlCreatorV0::CWCWedgeControlCreatorV0()
  //## begin CWCWedgeControlCreatorV0::CWCWedgeControlCreatorV0%.hasinit preserve=no
  //## end CWCWedgeControlCreatorV0::CWCWedgeControlCreatorV0%.hasinit
  //## begin CWCWedgeControlCreatorV0::CWCWedgeControlCreatorV0%.initialization preserve=yes
  : CPIObjCreatorWedgeControl(_T(""))
  //## end CWCWedgeControlCreatorV0::CWCWedgeControlCreatorV0%.initialization
{
  //## begin CWCWedgeControlCreatorV0::CWCWedgeControlCreatorV0%.body preserve=yes
  //## end CWCWedgeControlCreatorV0::CWCWedgeControlCreatorV0%.body
}


CWCWedgeControlCreatorV0::~CWCWedgeControlCreatorV0()
{
  //## begin CWCWedgeControlCreatorV0::~CWCWedgeControlCreatorV0%.body preserve=yes
  //## end CWCWedgeControlCreatorV0::~CWCWedgeControlCreatorV0%.body
}



//## Other Operations (implementation)
IPIWedgeControlInterface* CWCWedgeControlCreatorV0::Create (UINT p_uiID)
{
  //## begin CWCWedgeControlCreatorV0::Create%1037094237.body preserve=yes
	IPIWedgeControlInterface* l_Intf = new CWCWedgeControlInterface(p_uiID);
    l_Intf->InitInstance();

	return l_Intf;
  //## end CWCWedgeControlCreatorV0::Create%1037094237.body
}

// Additional Declarations
  //## begin CWCWedgeControlCreatorV0%3DD0B3420394.declarations preserve=yes
  //## end CWCWedgeControlCreatorV0%3DD0B3420394.declarations

//## begin module%3DD0B45E01BF.epilog preserve=yes
//## end module%3DD0B45E01BF.epilog
