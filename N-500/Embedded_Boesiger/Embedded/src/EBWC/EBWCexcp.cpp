//## begin module%3FB4AF0B01A5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FB4AF0B01A5.cm

//## begin module%3FB4AF0B01A5.cp preserve=no
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
//## end module%3FB4AF0B01A5.cp

//## Module: EBWCexcp%3FB4AF0B01A5; Package body
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%3FB4AF0B01A5.additionalIncludes preserve=no
//## end module%3FB4AF0B01A5.additionalIncludes

//## begin module%3FB4AF0B01A5.includes preserve=yes
//## end module%3FB4AF0B01A5.includes

// EBWCexcp
#include "EBWCexcp.h"
//## begin module%3FB4AF0B01A5.declarations preserve=no
//## end module%3FB4AF0B01A5.declarations

//## begin module%3FB4AF0B01A5.additionalDeclarations preserve=yes
//## end module%3FB4AF0B01A5.additionalDeclarations


// Class XWCExceptionError 

XWCExceptionError::XWCExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XWCExceptionError::XWCExceptionError%1068804683.hasinit preserve=no
  //## end XWCExceptionError::XWCExceptionError%1068804683.hasinit
  //## begin XWCExceptionError::XWCExceptionError%1068804683.initialization preserve=yes
	:XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XWCExceptionError::XWCExceptionError%1068804683.initialization
{
  //## begin XWCExceptionError::XWCExceptionError%1068804683.body preserve=yes
  //## end XWCExceptionError::XWCExceptionError%1068804683.body
}

XWCExceptionError::XWCExceptionError (XCOExceptionError* p_pOrigException)
  //## begin XWCExceptionError::XWCExceptionError%1068804684.hasinit preserve=no
  //## end XWCExceptionError::XWCExceptionError%1068804684.hasinit
  //## begin XWCExceptionError::XWCExceptionError%1068804684.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XWCExceptionError::XWCExceptionError%1068804684.initialization
{
  //## begin XWCExceptionError::XWCExceptionError%1068804684.body preserve=yes
  //## end XWCExceptionError::XWCExceptionError%1068804684.body
}


XWCExceptionError::~XWCExceptionError()
{
  //## begin XWCExceptionError::~XWCExceptionError%.body preserve=yes
  //## end XWCExceptionError::~XWCExceptionError%.body
}



//## Other Operations (implementation)
void XWCExceptionError::Throw ()
{
  //## begin XWCExceptionError::Throw%1068804685.body preserve=yes
	throw this;
  //## end XWCExceptionError::Throw%1068804685.body
}

XCOException* XWCExceptionError::Clone ()
{
  //## begin XWCExceptionError::Clone%1068804686.body preserve=yes
	XWCExceptionError* l_pClone = new XWCExceptionError(this);
	return l_pClone;
  //## end XWCExceptionError::Clone%1068804686.body
}

// Additional Declarations
  //## begin XWCExceptionError%3FB4AECD02CE.declarations preserve=yes
  //## end XWCExceptionError%3FB4AECD02CE.declarations

//## begin module%3FB4AF0B01A5.epilog preserve=yes
//## end module%3FB4AF0B01A5.epilog
