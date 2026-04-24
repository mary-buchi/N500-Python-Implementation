//## begin module%3FD026080242.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FD026080242.cm

//## begin module%3FD026080242.cp preserve=no
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
//## end module%3FD026080242.cp

//## Module: EBMCexcp%3FD026080242; Package body
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FD026080242.additionalIncludes preserve=no
//## end module%3FD026080242.additionalIncludes

//## begin module%3FD026080242.includes preserve=yes
//## end module%3FD026080242.includes

// EBMCexcp
#include "EBMCexcp.h"
//## begin module%3FD026080242.declarations preserve=no
//## end module%3FD026080242.declarations

//## begin module%3FD026080242.additionalDeclarations preserve=yes
//## end module%3FD026080242.additionalDeclarations


// Class XMCExceptionError 

XMCExceptionError::XMCExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XMCExceptionError::XMCExceptionError%1070606790.hasinit preserve=no
  //## end XMCExceptionError::XMCExceptionError%1070606790.hasinit
  //## begin XMCExceptionError::XMCExceptionError%1070606790.initialization preserve=yes
	:XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XMCExceptionError::XMCExceptionError%1070606790.initialization
{
  //## begin XMCExceptionError::XMCExceptionError%1070606790.body preserve=yes
  //## end XMCExceptionError::XMCExceptionError%1070606790.body
}

XMCExceptionError::XMCExceptionError (XCOExceptionError* p_pOrigException)
  //## begin XMCExceptionError::XMCExceptionError%1070606791.hasinit preserve=no
  //## end XMCExceptionError::XMCExceptionError%1070606791.hasinit
  //## begin XMCExceptionError::XMCExceptionError%1070606791.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XMCExceptionError::XMCExceptionError%1070606791.initialization
{
  //## begin XMCExceptionError::XMCExceptionError%1070606791.body preserve=yes
  //## end XMCExceptionError::XMCExceptionError%1070606791.body
}


XMCExceptionError::~XMCExceptionError()
{
  //## begin XMCExceptionError::~XMCExceptionError%.body preserve=yes
  //## end XMCExceptionError::~XMCExceptionError%.body
}



//## Other Operations (implementation)
void XMCExceptionError::Throw ()
{
  //## begin XMCExceptionError::Throw%1070606792.body preserve=yes
	throw this;
  //## end XMCExceptionError::Throw%1070606792.body
}

XCOException* XMCExceptionError::Clone ()
{
  //## begin XMCExceptionError::Clone%1070606793.body preserve=yes
	XMCExceptionError* l_pClone = new XMCExceptionError(this);
	return l_pClone;
  //## end XMCExceptionError::Clone%1070606793.body
}

// Additional Declarations
  //## begin XMCExceptionError%3FD0273400EA.declarations preserve=yes
  //## end XMCExceptionError%3FD0273400EA.declarations

//## begin module%3FD026080242.epilog preserve=yes
//## end module%3FD026080242.epilog
