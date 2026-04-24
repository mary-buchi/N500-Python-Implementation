//## begin module%400248890360.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%400248890360.cm

//## begin module%400248890360.cp preserve=no
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
//## end module%400248890360.cp

//## Module: EBPOexcp%400248890360; Package body
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%400248890360.additionalIncludes preserve=no
//## end module%400248890360.additionalIncludes

//## begin module%400248890360.includes preserve=yes
//## end module%400248890360.includes

// EBPOexcp
#include "EBPOexcp.h"
//## begin module%400248890360.declarations preserve=no
//## end module%400248890360.declarations

//## begin module%400248890360.additionalDeclarations preserve=yes
//## end module%400248890360.additionalDeclarations


// Class XPOExceptionError 

XPOExceptionError::XPOExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XPOExceptionError::XPOExceptionError%1073894412.hasinit preserve=no
  //## end XPOExceptionError::XPOExceptionError%1073894412.hasinit
  //## begin XPOExceptionError::XPOExceptionError%1073894412.initialization preserve=yes
  	: XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XPOExceptionError::XPOExceptionError%1073894412.initialization
{
  //## begin XPOExceptionError::XPOExceptionError%1073894412.body preserve=yes
  //## end XPOExceptionError::XPOExceptionError%1073894412.body
}

XPOExceptionError::XPOExceptionError (XCOExceptionError* p_pOrigException)
  //## begin XPOExceptionError::XPOExceptionError%1073894413.hasinit preserve=no
  //## end XPOExceptionError::XPOExceptionError%1073894413.hasinit
  //## begin XPOExceptionError::XPOExceptionError%1073894413.initialization preserve=yes
  	: XCOExceptionError(p_pOrigException)
  //## end XPOExceptionError::XPOExceptionError%1073894413.initialization
{
  //## begin XPOExceptionError::XPOExceptionError%1073894413.body preserve=yes
  //## end XPOExceptionError::XPOExceptionError%1073894413.body
}


XPOExceptionError::~XPOExceptionError()
{
  //## begin XPOExceptionError::~XPOExceptionError%.body preserve=yes
  //## end XPOExceptionError::~XPOExceptionError%.body
}



//## Other Operations (implementation)
void XPOExceptionError::Throw ()
{
  //## begin XPOExceptionError::Throw%1073894414.body preserve=yes
	throw this;
  //## end XPOExceptionError::Throw%1073894414.body
}

XCOException* XPOExceptionError::Clone ()
{
  //## begin XPOExceptionError::Clone%1073894415.body preserve=yes
	XPOExceptionError* l_pClone = new XPOExceptionError(this);
	return l_pClone;
  //## end XPOExceptionError::Clone%1073894415.body
}

// Additional Declarations
  //## begin XPOExceptionError%40024814038F.declarations preserve=yes
  //## end XPOExceptionError%40024814038F.declarations

// Class XPOExceptionHeader 

XPOExceptionHeader::XPOExceptionHeader (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XPOExceptionHeader::XPOExceptionHeader%1073894416.hasinit preserve=no
  //## end XPOExceptionHeader::XPOExceptionHeader%1073894416.hasinit
  //## begin XPOExceptionHeader::XPOExceptionHeader%1073894416.initialization preserve=yes
  	: XPOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XPOExceptionHeader::XPOExceptionHeader%1073894416.initialization
{
  //## begin XPOExceptionHeader::XPOExceptionHeader%1073894416.body preserve=yes
  //## end XPOExceptionHeader::XPOExceptionHeader%1073894416.body
}

XPOExceptionHeader::XPOExceptionHeader (XCOExceptionError* p_pOrigException)
  //## begin XPOExceptionHeader::XPOExceptionHeader%1073894417.hasinit preserve=no
  //## end XPOExceptionHeader::XPOExceptionHeader%1073894417.hasinit
  //## begin XPOExceptionHeader::XPOExceptionHeader%1073894417.initialization preserve=yes
  	: XPOExceptionError(p_pOrigException)
  //## end XPOExceptionHeader::XPOExceptionHeader%1073894417.initialization
{
  //## begin XPOExceptionHeader::XPOExceptionHeader%1073894417.body preserve=yes
  //## end XPOExceptionHeader::XPOExceptionHeader%1073894417.body
}


XPOExceptionHeader::~XPOExceptionHeader()
{
  //## begin XPOExceptionHeader::~XPOExceptionHeader%.body preserve=yes
  //## end XPOExceptionHeader::~XPOExceptionHeader%.body
}



//## Other Operations (implementation)
XCOException* XPOExceptionHeader::Clone ()
{
  //## begin XPOExceptionHeader::Clone%1073894418.body preserve=yes
	XPOExceptionHeader* l_pClone = new XPOExceptionHeader(this);
	return l_pClone;
  //## end XPOExceptionHeader::Clone%1073894418.body
}

void XPOExceptionHeader::Throw ()
{
  //## begin XPOExceptionHeader::Throw%1073894419.body preserve=yes
	throw this;
  //## end XPOExceptionHeader::Throw%1073894419.body
}

// Additional Declarations
  //## begin XPOExceptionHeader%400249170014.declarations preserve=yes
  //## end XPOExceptionHeader%400249170014.declarations

// Class XPOExceptionEpromFull 

XPOExceptionEpromFull::XPOExceptionEpromFull (XCOExceptionError* p_pOrigException)
  //## begin XPOExceptionEpromFull::XPOExceptionEpromFull%1073894420.hasinit preserve=no
  //## end XPOExceptionEpromFull::XPOExceptionEpromFull%1073894420.hasinit
  //## begin XPOExceptionEpromFull::XPOExceptionEpromFull%1073894420.initialization preserve=yes
  	: XPOExceptionError(p_pOrigException)
  //## end XPOExceptionEpromFull::XPOExceptionEpromFull%1073894420.initialization
{
  //## begin XPOExceptionEpromFull::XPOExceptionEpromFull%1073894420.body preserve=yes
  //## end XPOExceptionEpromFull::XPOExceptionEpromFull%1073894420.body
}

XPOExceptionEpromFull::XPOExceptionEpromFull (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XPOExceptionEpromFull::XPOExceptionEpromFull%1073894421.hasinit preserve=no
  //## end XPOExceptionEpromFull::XPOExceptionEpromFull%1073894421.hasinit
  //## begin XPOExceptionEpromFull::XPOExceptionEpromFull%1073894421.initialization preserve=yes
  	: XPOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XPOExceptionEpromFull::XPOExceptionEpromFull%1073894421.initialization
{
  //## begin XPOExceptionEpromFull::XPOExceptionEpromFull%1073894421.body preserve=yes
  //## end XPOExceptionEpromFull::XPOExceptionEpromFull%1073894421.body
}


XPOExceptionEpromFull::~XPOExceptionEpromFull()
{
  //## begin XPOExceptionEpromFull::~XPOExceptionEpromFull%.body preserve=yes
  //## end XPOExceptionEpromFull::~XPOExceptionEpromFull%.body
}



//## Other Operations (implementation)
XCOException* XPOExceptionEpromFull::Clone ()
{
  //## begin XPOExceptionEpromFull::Clone%1073894422.body preserve=yes
	XPOExceptionEpromFull* l_pClone = new XPOExceptionEpromFull(this);
	return l_pClone;
  //## end XPOExceptionEpromFull::Clone%1073894422.body
}

void XPOExceptionEpromFull::Throw ()
{
  //## begin XPOExceptionEpromFull::Throw%1073894423.body preserve=yes
	throw this;
  //## end XPOExceptionEpromFull::Throw%1073894423.body
}

// Additional Declarations
  //## begin XPOExceptionEpromFull%4002496E0237.declarations preserve=yes
  //## end XPOExceptionEpromFull%4002496E0237.declarations

// Class XPOExceptionWrongDataSize 

XPOExceptionWrongDataSize::XPOExceptionWrongDataSize (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XPOExceptionWrongDataSize::XPOExceptionWrongDataSize%1073894424.hasinit preserve=no
  //## end XPOExceptionWrongDataSize::XPOExceptionWrongDataSize%1073894424.hasinit
  //## begin XPOExceptionWrongDataSize::XPOExceptionWrongDataSize%1073894424.initialization preserve=yes
  	: XPOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XPOExceptionWrongDataSize::XPOExceptionWrongDataSize%1073894424.initialization
{
  //## begin XPOExceptionWrongDataSize::XPOExceptionWrongDataSize%1073894424.body preserve=yes
  //## end XPOExceptionWrongDataSize::XPOExceptionWrongDataSize%1073894424.body
}

XPOExceptionWrongDataSize::XPOExceptionWrongDataSize (XCOExceptionError* p_pOrigException)
  //## begin XPOExceptionWrongDataSize::XPOExceptionWrongDataSize%1073894425.hasinit preserve=no
  //## end XPOExceptionWrongDataSize::XPOExceptionWrongDataSize%1073894425.hasinit
  //## begin XPOExceptionWrongDataSize::XPOExceptionWrongDataSize%1073894425.initialization preserve=yes
  	: XPOExceptionError(p_pOrigException)
  //## end XPOExceptionWrongDataSize::XPOExceptionWrongDataSize%1073894425.initialization
{
  //## begin XPOExceptionWrongDataSize::XPOExceptionWrongDataSize%1073894425.body preserve=yes
  //## end XPOExceptionWrongDataSize::XPOExceptionWrongDataSize%1073894425.body
}


XPOExceptionWrongDataSize::~XPOExceptionWrongDataSize()
{
  //## begin XPOExceptionWrongDataSize::~XPOExceptionWrongDataSize%.body preserve=yes
  //## end XPOExceptionWrongDataSize::~XPOExceptionWrongDataSize%.body
}



//## Other Operations (implementation)
void XPOExceptionWrongDataSize::Throw ()
{
  //## begin XPOExceptionWrongDataSize::Throw%1073894426.body preserve=yes
	throw this;
  //## end XPOExceptionWrongDataSize::Throw%1073894426.body
}

XCOException* XPOExceptionWrongDataSize::Clone ()
{
  //## begin XPOExceptionWrongDataSize::Clone%1073894427.body preserve=yes
	XPOExceptionWrongDataSize* l_pClone = new XPOExceptionWrongDataSize(this);
	return l_pClone;
  //## end XPOExceptionWrongDataSize::Clone%1073894427.body
}

// Additional Declarations
  //## begin XPOExceptionWrongDataSize%40024B62013D.declarations preserve=yes
  //## end XPOExceptionWrongDataSize%40024B62013D.declarations

//## begin module%400248890360.epilog preserve=yes
//## end module%400248890360.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin XPOExceptionTokenizing::XPOExceptionTokenizing%1073894428.initialization preserve=no
  	: XPOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
//## end XPOExceptionTokenizing::XPOExceptionTokenizing%1073894428.initialization

//## begin XPOExceptionTokenizing::XPOExceptionTokenizing%1073894429.initialization preserve=no
  	: XPOExceptionError(p_pOrigException)
//## end XPOExceptionTokenizing::XPOExceptionTokenizing%1073894429.initialization

//## begin XPOExceptionTokenizing::Throw%1073894430.body preserve=no
	throw this;
//## end XPOExceptionTokenizing::Throw%1073894430.body

//## begin XPOExceptionTokenizing::Clone%1073894431.body preserve=no
	XPOExceptionTokenizing* l_pClone = new XPOExceptionTokenizing(this);
	return l_pClone;
//## end XPOExceptionTokenizing::Clone%1073894431.body

#endif
