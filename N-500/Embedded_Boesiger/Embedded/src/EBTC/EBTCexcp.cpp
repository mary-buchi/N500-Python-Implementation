//## begin module%3EE9C87B021E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE9C87B021E.cm

//## begin module%3EE9C87B021E.cp preserve=no
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
//## end module%3EE9C87B021E.cp

//## Module: EBTCexcp%3EE9C87B021E; Package body
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE9C87B021E.additionalIncludes preserve=no
//## end module%3EE9C87B021E.additionalIncludes

//## begin module%3EE9C87B021E.includes preserve=yes
//## end module%3EE9C87B021E.includes

// EBTCexcp
#include "EBTCexcp.h"
//## begin module%3EE9C87B021E.declarations preserve=no
//## end module%3EE9C87B021E.declarations

//## begin module%3EE9C87B021E.additionalDeclarations preserve=yes
//## end module%3EE9C87B021E.additionalDeclarations


// Class XTCExceptionError 

XTCExceptionError::XTCExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XTCExceptionError::XTCExceptionError%1055484806.hasinit preserve=no
  //## end XTCExceptionError::XTCExceptionError%1055484806.hasinit
  //## begin XTCExceptionError::XTCExceptionError%1055484806.initialization preserve=yes
	: XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XTCExceptionError::XTCExceptionError%1055484806.initialization
{
  //## begin XTCExceptionError::XTCExceptionError%1055484806.body preserve=yes
  //## end XTCExceptionError::XTCExceptionError%1055484806.body
}

XTCExceptionError::XTCExceptionError (XCOExceptionError* p_pOrigException)
  //## begin XTCExceptionError::XTCExceptionError%1055484807.hasinit preserve=no
  //## end XTCExceptionError::XTCExceptionError%1055484807.hasinit
  //## begin XTCExceptionError::XTCExceptionError%1055484807.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XTCExceptionError::XTCExceptionError%1055484807.initialization
{
  //## begin XTCExceptionError::XTCExceptionError%1055484807.body preserve=yes
  //## end XTCExceptionError::XTCExceptionError%1055484807.body
}


XTCExceptionError::~XTCExceptionError()
{
  //## begin XTCExceptionError::~XTCExceptionError%.body preserve=yes
  //## end XTCExceptionError::~XTCExceptionError%.body
}


// Additional Declarations
  //## begin XTCExceptionError%3EE9C402000B.declarations preserve=yes
  //## end XTCExceptionError%3EE9C402000B.declarations

// Class XTCExceptionTemperature 

XTCExceptionTemperature::XTCExceptionTemperature (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XTCExceptionTemperature::XTCExceptionTemperature%1055484804.hasinit preserve=no
  //## end XTCExceptionTemperature::XTCExceptionTemperature%1055484804.hasinit
  //## begin XTCExceptionTemperature::XTCExceptionTemperature%1055484804.initialization preserve=yes
	: XTCExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XTCExceptionTemperature::XTCExceptionTemperature%1055484804.initialization
{
  //## begin XTCExceptionTemperature::XTCExceptionTemperature%1055484804.body preserve=yes
  //## end XTCExceptionTemperature::XTCExceptionTemperature%1055484804.body
}

XTCExceptionTemperature::XTCExceptionTemperature (XCOExceptionError* p_pOrigException)
  //## begin XTCExceptionTemperature::XTCExceptionTemperature%1055484805.hasinit preserve=no
  //## end XTCExceptionTemperature::XTCExceptionTemperature%1055484805.hasinit
  //## begin XTCExceptionTemperature::XTCExceptionTemperature%1055484805.initialization preserve=yes
	: XTCExceptionError(p_pOrigException)
  //## end XTCExceptionTemperature::XTCExceptionTemperature%1055484805.initialization
{
  //## begin XTCExceptionTemperature::XTCExceptionTemperature%1055484805.body preserve=yes
  //## end XTCExceptionTemperature::XTCExceptionTemperature%1055484805.body
}


XTCExceptionTemperature::~XTCExceptionTemperature()
{
  //## begin XTCExceptionTemperature::~XTCExceptionTemperature%.body preserve=yes
  //## end XTCExceptionTemperature::~XTCExceptionTemperature%.body
}


// Additional Declarations
  //## begin XTCExceptionTemperature%3EE9C4860182.declarations preserve=yes
  //## end XTCExceptionTemperature%3EE9C4860182.declarations

// Class XTCExceptionErrorHeaterFailure 

XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure%1055484810.hasinit preserve=no
  //## end XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure%1055484810.hasinit
  //## begin XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure%1055484810.initialization preserve=yes
    : XTCExceptionError (p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure%1055484810.initialization
{
  //## begin XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure%1055484810.body preserve=yes
  //## end XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure%1055484810.body
}

XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure (XCOExceptionError* p_pOrigException)
  //## begin XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure%1055484811.hasinit preserve=no
  //## end XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure%1055484811.hasinit
  //## begin XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure%1055484811.initialization preserve=yes
	  : XTCExceptionError(p_pOrigException)
  //## end XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure%1055484811.initialization
{
  //## begin XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure%1055484811.body preserve=yes
  //## end XTCExceptionErrorHeaterFailure::XTCExceptionErrorHeaterFailure%1055484811.body
}


XTCExceptionErrorHeaterFailure::~XTCExceptionErrorHeaterFailure()
{
  //## begin XTCExceptionErrorHeaterFailure::~XTCExceptionErrorHeaterFailure%.body preserve=yes
  //## end XTCExceptionErrorHeaterFailure::~XTCExceptionErrorHeaterFailure%.body
}


// Additional Declarations
  //## begin XTCExceptionErrorHeaterFailure%3EE9C6BD022E.declarations preserve=yes
  //## end XTCExceptionErrorHeaterFailure%3EE9C6BD022E.declarations

// Class XTCExceptionTemperatureErrorLLimit 

XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit (XCOExceptionError* p_pOrigException)
  //## begin XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit%1055484822.hasinit preserve=no
  //## end XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit%1055484822.hasinit
  //## begin XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit%1055484822.initialization preserve=yes
	: XTCExceptionTemperature(p_pOrigException)
  //## end XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit%1055484822.initialization
{
  //## begin XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit%1055484822.body preserve=yes
  //## end XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit%1055484822.body
}

XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit%1055484823.hasinit preserve=no
  //## end XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit%1055484823.hasinit
  //## begin XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit%1055484823.initialization preserve=yes
	: XTCExceptionTemperature(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit%1055484823.initialization
{
  //## begin XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit%1055484823.body preserve=yes
  //## end XTCExceptionTemperatureErrorLLimit::XTCExceptionTemperatureErrorLLimit%1055484823.body
}


XTCExceptionTemperatureErrorLLimit::~XTCExceptionTemperatureErrorLLimit()
{
  //## begin XTCExceptionTemperatureErrorLLimit::~XTCExceptionTemperatureErrorLLimit%.body preserve=yes
  //## end XTCExceptionTemperatureErrorLLimit::~XTCExceptionTemperatureErrorLLimit%.body
}



//## Other Operations (implementation)
void XTCExceptionTemperatureErrorLLimit::Throw ()
{
  //## begin XTCExceptionTemperatureErrorLLimit::Throw%1055484820.body preserve=yes
	throw this;
  //## end XTCExceptionTemperatureErrorLLimit::Throw%1055484820.body
}

XCOException* XTCExceptionTemperatureErrorLLimit::Clone ()
{
  //## begin XTCExceptionTemperatureErrorLLimit::Clone%1055484821.body preserve=yes
	XTCExceptionTemperatureErrorLLimit* l_pClone = new XTCExceptionTemperatureErrorLLimit(this);
	return l_pClone;
  //## end XTCExceptionTemperatureErrorLLimit::Clone%1055484821.body
}

// Additional Declarations
  //## begin XTCExceptionTemperatureErrorLLimit%3EE9D0670124.declarations preserve=yes
  //## end XTCExceptionTemperatureErrorLLimit%3EE9D0670124.declarations

// Class XTCExceptionTemperatureWarningLLimit 

XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit%1055484824.hasinit preserve=no
  //## end XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit%1055484824.hasinit
  //## begin XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit%1055484824.initialization preserve=yes
	: XTCExceptionTemperature(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit%1055484824.initialization
{
  //## begin XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit%1055484824.body preserve=yes
  //## end XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit%1055484824.body
}

XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit (XCOExceptionError* p_pOrigException)
  //## begin XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit%1055484825.hasinit preserve=no
  //## end XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit%1055484825.hasinit
  //## begin XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit%1055484825.initialization preserve=yes
	: XTCExceptionTemperature(p_pOrigException)
  //## end XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit%1055484825.initialization
{
  //## begin XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit%1055484825.body preserve=yes
  //## end XTCExceptionTemperatureWarningLLimit::XTCExceptionTemperatureWarningLLimit%1055484825.body
}


XTCExceptionTemperatureWarningLLimit::~XTCExceptionTemperatureWarningLLimit()
{
  //## begin XTCExceptionTemperatureWarningLLimit::~XTCExceptionTemperatureWarningLLimit%.body preserve=yes
  //## end XTCExceptionTemperatureWarningLLimit::~XTCExceptionTemperatureWarningLLimit%.body
}



//## Other Operations (implementation)
void XTCExceptionTemperatureWarningLLimit::Throw ()
{
  //## begin XTCExceptionTemperatureWarningLLimit::Throw%1055484826.body preserve=yes
	throw this;
  //## end XTCExceptionTemperatureWarningLLimit::Throw%1055484826.body
}

XCOException* XTCExceptionTemperatureWarningLLimit::Clone ()
{
  //## begin XTCExceptionTemperatureWarningLLimit::Clone%1055484827.body preserve=yes
	XTCExceptionTemperatureWarningLLimit* l_pClone = new XTCExceptionTemperatureWarningLLimit(this);
	return l_pClone;
  //## end XTCExceptionTemperatureWarningLLimit::Clone%1055484827.body
}

// Additional Declarations
  //## begin XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.declarations preserve=yes
  //## end XTCExceptionTemperatureWarningLLimit%3EE9D08D0337.declarations

// Class XTCExceptionTemperatureWarningULimit 

XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit%1055484828.hasinit preserve=no
  //## end XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit%1055484828.hasinit
  //## begin XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit%1055484828.initialization preserve=yes
	: XTCExceptionTemperature(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit%1055484828.initialization
{
  //## begin XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit%1055484828.body preserve=yes
  //## end XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit%1055484828.body
}

XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit (XCOExceptionError* p_pOrigException)
  //## begin XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit%1055484829.hasinit preserve=no
  //## end XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit%1055484829.hasinit
  //## begin XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit%1055484829.initialization preserve=yes
	: XTCExceptionTemperature(p_pOrigException)
  //## end XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit%1055484829.initialization
{
  //## begin XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit%1055484829.body preserve=yes
  //## end XTCExceptionTemperatureWarningULimit::XTCExceptionTemperatureWarningULimit%1055484829.body
}


XTCExceptionTemperatureWarningULimit::~XTCExceptionTemperatureWarningULimit()
{
  //## begin XTCExceptionTemperatureWarningULimit::~XTCExceptionTemperatureWarningULimit%.body preserve=yes
  //## end XTCExceptionTemperatureWarningULimit::~XTCExceptionTemperatureWarningULimit%.body
}



//## Other Operations (implementation)
void XTCExceptionTemperatureWarningULimit::Throw ()
{
  //## begin XTCExceptionTemperatureWarningULimit::Throw%1055484830.body preserve=yes
	throw this;
  //## end XTCExceptionTemperatureWarningULimit::Throw%1055484830.body
}

XCOException* XTCExceptionTemperatureWarningULimit::Clone ()
{
  //## begin XTCExceptionTemperatureWarningULimit::Clone%1055484831.body preserve=yes
	XTCExceptionTemperatureWarningULimit* l_pClone = new XTCExceptionTemperatureWarningULimit(this);
	return l_pClone;
  //## end XTCExceptionTemperatureWarningULimit::Clone%1055484831.body
}

// Additional Declarations
  //## begin XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.declarations preserve=yes
  //## end XTCExceptionTemperatureWarningULimit%3EE9D0A0001B.declarations

// Class XTCExceptionTemperatureErrorULimit 

XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit%1055484818.hasinit preserve=no
  //## end XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit%1055484818.hasinit
  //## begin XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit%1055484818.initialization preserve=yes
	: XTCExceptionTemperature(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit%1055484818.initialization
{
  //## begin XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit%1055484818.body preserve=yes
  //## end XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit%1055484818.body
}

XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit (XCOExceptionError* p_pOrigException)
  //## begin XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit%1055484819.hasinit preserve=no
  //## end XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit%1055484819.hasinit
  //## begin XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit%1055484819.initialization preserve=yes
	: XTCExceptionTemperature(p_pOrigException)
  //## end XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit%1055484819.initialization
{
  //## begin XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit%1055484819.body preserve=yes
  //## end XTCExceptionTemperatureErrorULimit::XTCExceptionTemperatureErrorULimit%1055484819.body
}


XTCExceptionTemperatureErrorULimit::~XTCExceptionTemperatureErrorULimit()
{
  //## begin XTCExceptionTemperatureErrorULimit::~XTCExceptionTemperatureErrorULimit%.body preserve=yes
  //## end XTCExceptionTemperatureErrorULimit::~XTCExceptionTemperatureErrorULimit%.body
}



//## Other Operations (implementation)
void XTCExceptionTemperatureErrorULimit::Throw ()
{
  //## begin XTCExceptionTemperatureErrorULimit::Throw%1055484816.body preserve=yes
	throw this;
  //## end XTCExceptionTemperatureErrorULimit::Throw%1055484816.body
}

XCOException* XTCExceptionTemperatureErrorULimit::Clone ()
{
  //## begin XTCExceptionTemperatureErrorULimit::Clone%1055484817.body preserve=yes
	XTCExceptionTemperatureErrorULimit* l_pClone = new XTCExceptionTemperatureErrorULimit(this);
	return l_pClone;
  //## end XTCExceptionTemperatureErrorULimit::Clone%1055484817.body
}

// Additional Declarations
  //## begin XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.declarations preserve=yes
  //## end XTCExceptionTemperatureErrorULimit%3EE9D0DA026C.declarations

// Class XTCExceptionErrorInterrupted 

XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted%1055833084.hasinit preserve=no
  //## end XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted%1055833084.hasinit
  //## begin XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted%1055833084.initialization preserve=yes
  :XTCExceptionErrorHeaterFailure(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted%1055833084.initialization
{
  //## begin XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted%1055833084.body preserve=yes
  //## end XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted%1055833084.body
}

XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted (XCOExceptionError* p_pOrigException)
  //## begin XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted%1055833085.hasinit preserve=no
  //## end XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted%1055833085.hasinit
  //## begin XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted%1055833085.initialization preserve=yes
  :XTCExceptionErrorHeaterFailure(p_pOrigException)
  //## end XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted%1055833085.initialization
{
  //## begin XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted%1055833085.body preserve=yes
  //## end XTCExceptionErrorInterrupted::XTCExceptionErrorInterrupted%1055833085.body
}


XTCExceptionErrorInterrupted::~XTCExceptionErrorInterrupted()
{
  //## begin XTCExceptionErrorInterrupted::~XTCExceptionErrorInterrupted%.body preserve=yes
  //## end XTCExceptionErrorInterrupted::~XTCExceptionErrorInterrupted%.body
}



//## Other Operations (implementation)
void XTCExceptionErrorInterrupted::Throw ()
{
  //## begin XTCExceptionErrorInterrupted::Throw%1055833086.body preserve=yes
	throw this;
  //## end XTCExceptionErrorInterrupted::Throw%1055833086.body
}

XCOException* XTCExceptionErrorInterrupted::Clone ()
{
  //## begin XTCExceptionErrorInterrupted::Clone%1055833087.body preserve=yes
	XTCExceptionErrorInterrupted* l_pClone = new XTCExceptionErrorInterrupted(this);
	ASSERT(l_pClone != NULL);
	return l_pClone;
  //## end XTCExceptionErrorInterrupted::Clone%1055833087.body
}

// Additional Declarations
  //## begin XTCExceptionErrorInterrupted%3EEF0D230109.declarations preserve=yes
  //## end XTCExceptionErrorInterrupted%3EEF0D230109.declarations

// Class XTCExceptionErrorShorted 

XTCExceptionErrorShorted::XTCExceptionErrorShorted (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XTCExceptionErrorShorted::XTCExceptionErrorShorted%1055833088.hasinit preserve=no
  //## end XTCExceptionErrorShorted::XTCExceptionErrorShorted%1055833088.hasinit
  //## begin XTCExceptionErrorShorted::XTCExceptionErrorShorted%1055833088.initialization preserve=yes
  :XTCExceptionErrorHeaterFailure(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XTCExceptionErrorShorted::XTCExceptionErrorShorted%1055833088.initialization
{
  //## begin XTCExceptionErrorShorted::XTCExceptionErrorShorted%1055833088.body preserve=yes
  //## end XTCExceptionErrorShorted::XTCExceptionErrorShorted%1055833088.body
}

XTCExceptionErrorShorted::XTCExceptionErrorShorted (XCOExceptionError* p_pOrigException)
  //## begin XTCExceptionErrorShorted::XTCExceptionErrorShorted%1055833089.hasinit preserve=no
  //## end XTCExceptionErrorShorted::XTCExceptionErrorShorted%1055833089.hasinit
  //## begin XTCExceptionErrorShorted::XTCExceptionErrorShorted%1055833089.initialization preserve=yes
  :XTCExceptionErrorHeaterFailure(p_pOrigException)
  //## end XTCExceptionErrorShorted::XTCExceptionErrorShorted%1055833089.initialization
{
  //## begin XTCExceptionErrorShorted::XTCExceptionErrorShorted%1055833089.body preserve=yes
  //## end XTCExceptionErrorShorted::XTCExceptionErrorShorted%1055833089.body
}


XTCExceptionErrorShorted::~XTCExceptionErrorShorted()
{
  //## begin XTCExceptionErrorShorted::~XTCExceptionErrorShorted%.body preserve=yes
  //## end XTCExceptionErrorShorted::~XTCExceptionErrorShorted%.body
}



//## Other Operations (implementation)
void XTCExceptionErrorShorted::Throw ()
{
  //## begin XTCExceptionErrorShorted::Throw%1055833090.body preserve=yes
	throw this;
  //## end XTCExceptionErrorShorted::Throw%1055833090.body
}

XCOException* XTCExceptionErrorShorted::Clone ()
{
  //## begin XTCExceptionErrorShorted::Clone%1055833091.body preserve=yes
	XTCExceptionErrorShorted* l_pClone = new XTCExceptionErrorShorted(this);
	ASSERT(l_pClone != NULL);
	return l_pClone;
  //## end XTCExceptionErrorShorted::Clone%1055833091.body
}

// Additional Declarations
  //## begin XTCExceptionErrorShorted%3EEF0D410147.declarations preserve=yes
  //## end XTCExceptionErrorShorted%3EEF0D410147.declarations

//## begin module%3EE9C87B021E.epilog preserve=yes
//## end module%3EE9C87B021E.epilog
