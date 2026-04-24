//## begin module%3EED769F03AD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F03AD.cm

//## begin module%3EED769F03AD.cp preserve=no
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
//## end module%3EED769F03AD.cp

//## Module: EBPCexcp%3EED769F03AD; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F03AD.additionalIncludes preserve=no
//## end module%3EED769F03AD.additionalIncludes

//## begin module%3EED769F03AD.includes preserve=yes
//## end module%3EED769F03AD.includes

// EBPCexcp
#include "EBPCexcp.h"
//## begin module%3EED769F03AD.declarations preserve=no
//## end module%3EED769F03AD.declarations

//## begin module%3EED769F03AD.additionalDeclarations preserve=yes
//## end module%3EED769F03AD.additionalDeclarations


// Class XPCExceptionError 

XPCExceptionError::XPCExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XPCExceptionError::XPCExceptionError%1055484806.hasinit preserve=no
  //## end XPCExceptionError::XPCExceptionError%1055484806.hasinit
  //## begin XPCExceptionError::XPCExceptionError%1055484806.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XPCExceptionError::XPCExceptionError%1055484806.initialization
{
  //## begin XPCExceptionError::XPCExceptionError%1055484806.body preserve=yes
  //## end XPCExceptionError::XPCExceptionError%1055484806.body
}

XPCExceptionError::XPCExceptionError (XCOExceptionError* p_pOrigException)
  //## begin XPCExceptionError::XPCExceptionError%1055484807.hasinit preserve=no
  //## end XPCExceptionError::XPCExceptionError%1055484807.hasinit
  //## begin XPCExceptionError::XPCExceptionError%1055484807.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XPCExceptionError::XPCExceptionError%1055484807.initialization
{
  //## begin XPCExceptionError::XPCExceptionError%1055484807.body preserve=yes
  //## end XPCExceptionError::XPCExceptionError%1055484807.body
}


XPCExceptionError::~XPCExceptionError()
{
  //## begin XPCExceptionError::~XPCExceptionError%.body preserve=yes
  //## end XPCExceptionError::~XPCExceptionError%.body
}


// Additional Declarations
  //## begin XPCExceptionError%3EED76CC0808.declarations preserve=yes
  //## end XPCExceptionError%3EED76CC0808.declarations

// Class XPCExceptionErrorShorted 

XPCExceptionErrorShorted::XPCExceptionErrorShorted (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XPCExceptionErrorShorted::XPCExceptionErrorShorted%1055484810.hasinit preserve=no
  //## end XPCExceptionErrorShorted::XPCExceptionErrorShorted%1055484810.hasinit
  //## begin XPCExceptionErrorShorted::XPCExceptionErrorShorted%1055484810.initialization preserve=yes
  : XPCExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XPCExceptionErrorShorted::XPCExceptionErrorShorted%1055484810.initialization
{
  //## begin XPCExceptionErrorShorted::XPCExceptionErrorShorted%1055484810.body preserve=yes
  //## end XPCExceptionErrorShorted::XPCExceptionErrorShorted%1055484810.body
}

XPCExceptionErrorShorted::XPCExceptionErrorShorted (XCOExceptionError* p_pOrigException)
  //## begin XPCExceptionErrorShorted::XPCExceptionErrorShorted%1055484811.hasinit preserve=no
  //## end XPCExceptionErrorShorted::XPCExceptionErrorShorted%1055484811.hasinit
  //## begin XPCExceptionErrorShorted::XPCExceptionErrorShorted%1055484811.initialization preserve=yes
  : XPCExceptionError(p_pOrigException)
  //## end XPCExceptionErrorShorted::XPCExceptionErrorShorted%1055484811.initialization
{
  //## begin XPCExceptionErrorShorted::XPCExceptionErrorShorted%1055484811.body preserve=yes
  //## end XPCExceptionErrorShorted::XPCExceptionErrorShorted%1055484811.body
}


XPCExceptionErrorShorted::~XPCExceptionErrorShorted()
{
  //## begin XPCExceptionErrorShorted::~XPCExceptionErrorShorted%.body preserve=yes
  //## end XPCExceptionErrorShorted::~XPCExceptionErrorShorted%.body
}



//## Other Operations (implementation)
void XPCExceptionErrorShorted::Throw ()
{
  //## begin XPCExceptionErrorShorted::Throw%1055484812.body preserve=yes
	throw this;
  //## end XPCExceptionErrorShorted::Throw%1055484812.body
}

XCOException* XPCExceptionErrorShorted::Clone ()
{
  //## begin XPCExceptionErrorShorted::Clone%1055484813.body preserve=yes
	XPCExceptionErrorShorted* l_pClone = new XPCExceptionErrorShorted(this);
	ASSERT(l_pClone != NULL);
	return l_pClone;
  //## end XPCExceptionErrorShorted::Clone%1055484813.body
}

// Additional Declarations
  //## begin XPCExceptionErrorShorted%3EED76CC082A.declarations preserve=yes
  //## end XPCExceptionErrorShorted%3EED76CC082A.declarations

// Class XPCExceptionErrorInterrupted 

XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted%1055833080.hasinit preserve=no
  //## end XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted%1055833080.hasinit
  //## begin XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted%1055833080.initialization preserve=yes
  :XPCExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted%1055833080.initialization
{
  //## begin XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted%1055833080.body preserve=yes
  //## end XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted%1055833080.body
}

XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted (XCOExceptionError* p_pOrigException)
  //## begin XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted%1055833081.hasinit preserve=no
  //## end XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted%1055833081.hasinit
  //## begin XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted%1055833081.initialization preserve=yes
  :XPCExceptionError(p_pOrigException)
  //## end XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted%1055833081.initialization
{
  //## begin XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted%1055833081.body preserve=yes
  //## end XPCExceptionErrorInterrupted::XPCExceptionErrorInterrupted%1055833081.body
}


XPCExceptionErrorInterrupted::~XPCExceptionErrorInterrupted()
{
  //## begin XPCExceptionErrorInterrupted::~XPCExceptionErrorInterrupted%.body preserve=yes
  //## end XPCExceptionErrorInterrupted::~XPCExceptionErrorInterrupted%.body
}



//## Other Operations (implementation)
void XPCExceptionErrorInterrupted::Throw ()
{
  //## begin XPCExceptionErrorInterrupted::Throw%1055833082.body preserve=yes
	throw this;
  //## end XPCExceptionErrorInterrupted::Throw%1055833082.body
}

XCOException* XPCExceptionErrorInterrupted::Clone ()
{
  //## begin XPCExceptionErrorInterrupted::Clone%1055833083.body preserve=yes
	XPCExceptionErrorInterrupted* l_pClone = new XPCExceptionErrorInterrupted(this);
	ASSERT(l_pClone != NULL);
	return l_pClone;
  //## end XPCExceptionErrorInterrupted::Clone%1055833083.body
}

// Additional Declarations
  //## begin XPCExceptionErrorInterrupted%3EEF09F200AB.declarations preserve=yes
  //## end XPCExceptionErrorInterrupted%3EEF09F200AB.declarations

// Class XPCExceptionErrorSettlingTime 

XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime%1077262884.hasinit preserve=no
  //## end XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime%1077262884.hasinit
  //## begin XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime%1077262884.initialization preserve=yes
  :XPCExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime%1077262884.initialization
{
  //## begin XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime%1077262884.body preserve=yes
  //## end XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime%1077262884.body
}

XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime (XCOExceptionError* p_pOrigException)
  //## begin XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime%1077262885.hasinit preserve=no
  //## end XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime%1077262885.hasinit
  //## begin XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime%1077262885.initialization preserve=yes
  :XPCExceptionError(p_pOrigException)
  //## end XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime%1077262885.initialization
{
  //## begin XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime%1077262885.body preserve=yes
  //## end XPCExceptionErrorSettlingTime::XPCExceptionErrorSettlingTime%1077262885.body
}


XPCExceptionErrorSettlingTime::~XPCExceptionErrorSettlingTime()
{
  //## begin XPCExceptionErrorSettlingTime::~XPCExceptionErrorSettlingTime%.body preserve=yes
  //## end XPCExceptionErrorSettlingTime::~XPCExceptionErrorSettlingTime%.body
}



//## Other Operations (implementation)
void XPCExceptionErrorSettlingTime::Throw ()
{
  //## begin XPCExceptionErrorSettlingTime::Throw%1077262886.body preserve=yes
	throw this;
  //## end XPCExceptionErrorSettlingTime::Throw%1077262886.body
}

XCOException* XPCExceptionErrorSettlingTime::Clone ()
{
  //## begin XPCExceptionErrorSettlingTime::Clone%1077262887.body preserve=yes
	XPCExceptionErrorSettlingTime* l_pClone = new XPCExceptionErrorSettlingTime(this);
	ASSERT(l_pClone != NULL);
	return l_pClone;
  //## end XPCExceptionErrorSettlingTime::Clone%1077262887.body
}

// Additional Declarations
  //## begin XPCExceptionErrorSettlingTime%4035D7C50130.declarations preserve=yes
  //## end XPCExceptionErrorSettlingTime%4035D7C50130.declarations

//## begin module%3EED769F03AD.epilog preserve=yes
//## end module%3EED769F03AD.epilog
