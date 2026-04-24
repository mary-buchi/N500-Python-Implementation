//## begin module%3E19820301EF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E19820301EF.cm

//## begin module%3E19820301EF.cp preserve=no
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
//## end module%3E19820301EF.cp

//## Module: EBDIcrea%3E19820301EF; Package body
//## Subsystem: EBDI (Diagnostics)%3E197C2800D6
//## Source file: R:\Embedded\src\EBDI\EBDIcrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E19820301EF.additionalIncludes preserve=no
//## end module%3E19820301EF.additionalIncludes

//## begin module%3E19820301EF.includes preserve=yes
//## end module%3E19820301EF.includes

// EBDIintf
#include "EBDIintf.h"
// EBDIcrea
#include "EBDIcrea.h"
//## begin module%3E19820301EF.declarations preserve=no
//## end module%3E19820301EF.declarations

//## begin module%3E19820301EF.additionalDeclarations preserve=yes
//## end module%3E19820301EF.additionalDeclarations


// Class CDIDiagnosticCreatorV0 

CDIDiagnosticCreatorV0::CDIDiagnosticCreatorV0()
  //## begin CDIDiagnosticCreatorV0::CDIDiagnosticCreatorV0%.hasinit preserve=no
  //## end CDIDiagnosticCreatorV0::CDIDiagnosticCreatorV0%.hasinit
  //## begin CDIDiagnosticCreatorV0::CDIDiagnosticCreatorV0%.initialization preserve=yes
  :CPIObjCreatorDiagnostics(_T(""))
  //## end CDIDiagnosticCreatorV0::CDIDiagnosticCreatorV0%.initialization
{
  //## begin CDIDiagnosticCreatorV0::CDIDiagnosticCreatorV0%.body preserve=yes
  //## end CDIDiagnosticCreatorV0::CDIDiagnosticCreatorV0%.body
}


CDIDiagnosticCreatorV0::~CDIDiagnosticCreatorV0()
{
  //## begin CDIDiagnosticCreatorV0::~CDIDiagnosticCreatorV0%.body preserve=yes
  //## end CDIDiagnosticCreatorV0::~CDIDiagnosticCreatorV0%.body
}



//## Other Operations (implementation)
IPIDiagnosticInterface* CDIDiagnosticCreatorV0::Create (UINT p_uiID)
{
  //## begin CDIDiagnosticCreatorV0::Create%1041861675.body preserve=yes
	IPIDiagnosticInterface* l_Intf = new CDIDiagnosticInterface(p_uiID);

	return l_Intf;
  //## end CDIDiagnosticCreatorV0::Create%1041861675.body
}

// Additional Declarations
  //## begin CDIDiagnosticCreatorV0%3E198B090328.declarations preserve=yes
  //## end CDIDiagnosticCreatorV0%3E198B090328.declarations

//## begin module%3E19820301EF.epilog preserve=yes
//## end module%3E19820301EF.epilog
