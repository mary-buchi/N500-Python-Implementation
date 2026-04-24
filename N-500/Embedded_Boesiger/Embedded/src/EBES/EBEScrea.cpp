//## begin module%3DE5EC4902D3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EC4902D3.cm

//## begin module%3DE5EC4902D3.cp preserve=no
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
//## end module%3DE5EC4902D3.cp

//## Module: EBEScrea%3DE5EC4902D3; Package body
//## Subsystem: EBES (Event Source)%3DE5E67F00D0
//## Source file: R:\Embedded\src\EBES\EBEScrea.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DE5EC4902D3.additionalIncludes preserve=no
//## end module%3DE5EC4902D3.additionalIncludes

//## begin module%3DE5EC4902D3.includes preserve=yes
//## end module%3DE5EC4902D3.includes

// EBESintf
#include "EBESintf.h"
// EBEScrea
#include "EBEScrea.h"
//## begin module%3DE5EC4902D3.declarations preserve=no
//## end module%3DE5EC4902D3.declarations

//## begin module%3DE5EC4902D3.additionalDeclarations preserve=yes
//## end module%3DE5EC4902D3.additionalDeclarations


// Class CESEventSourceCreatorV0 

CESEventSourceCreatorV0::CESEventSourceCreatorV0()
  //## begin CESEventSourceCreatorV0::CESEventSourceCreatorV0%.hasinit preserve=no
  //## end CESEventSourceCreatorV0::CESEventSourceCreatorV0%.hasinit
  //## begin CESEventSourceCreatorV0::CESEventSourceCreatorV0%.initialization preserve=yes
  :CPIObjCreatorEventSource(_T(""))
  //## end CESEventSourceCreatorV0::CESEventSourceCreatorV0%.initialization
{
  //## begin CESEventSourceCreatorV0::CESEventSourceCreatorV0%.body preserve=yes
  //## end CESEventSourceCreatorV0::CESEventSourceCreatorV0%.body
}


CESEventSourceCreatorV0::~CESEventSourceCreatorV0()
{
  //## begin CESEventSourceCreatorV0::~CESEventSourceCreatorV0%.body preserve=yes
  //## end CESEventSourceCreatorV0::~CESEventSourceCreatorV0%.body
}



//## Other Operations (implementation)
IPIEventSourceInterface* CESEventSourceCreatorV0::Create (UINT p_uiID)
{
  //## begin CESEventSourceCreatorV0::Create%1038837051.body preserve=yes
	IPIEventSourceInterface* l_Intf = new CESEventSourceInterface(p_uiID);

	return l_Intf;
  //## end CESEventSourceCreatorV0::Create%1038837051.body
}

// Additional Declarations
  //## begin CESEventSourceCreatorV0%3DE7107402CD.declarations preserve=yes
  //## end CESEventSourceCreatorV0%3DE7107402CD.declarations

//## begin module%3DE5EC4902D3.epilog preserve=yes
//## end module%3DE5EC4902D3.epilog
