//## begin module%3ECA3CA101C9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3ECA3CA101C9.cm

//## begin module%3ECA3CA101C9.cp preserve=no
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
//## end module%3ECA3CA101C9.cp

//## Module: EBSTexcp%3ECA3CA101C9; Package body
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%3ECA3CA101C9.additionalIncludes preserve=no
//## end module%3ECA3CA101C9.additionalIncludes

//## begin module%3ECA3CA101C9.includes preserve=yes
//## end module%3ECA3CA101C9.includes

// EBSTexcp
#include "EBSTexcp.h"
//## begin module%3ECA3CA101C9.declarations preserve=no
//## end module%3ECA3CA101C9.declarations

//## begin module%3ECA3CA101C9.additionalDeclarations preserve=yes
//## end module%3ECA3CA101C9.additionalDeclarations


// Class XSTExceptionError 

XSTExceptionError::XSTExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XSTExceptionError::XSTExceptionError%1053507529.hasinit preserve=no
  //## end XSTExceptionError::XSTExceptionError%1053507529.hasinit
  //## begin XSTExceptionError::XSTExceptionError%1053507529.initialization preserve=yes
    : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XSTExceptionError::XSTExceptionError%1053507529.initialization
{
  //## begin XSTExceptionError::XSTExceptionError%1053507529.body preserve=yes
  //## end XSTExceptionError::XSTExceptionError%1053507529.body
}

XSTExceptionError::XSTExceptionError (XCOExceptionError* p_pOrigException)
  //## begin XSTExceptionError::XSTExceptionError%1053507530.hasinit preserve=no
  //## end XSTExceptionError::XSTExceptionError%1053507530.hasinit
  //## begin XSTExceptionError::XSTExceptionError%1053507530.initialization preserve=yes
    : XCOExceptionError(p_pOrigException)
  //## end XSTExceptionError::XSTExceptionError%1053507530.initialization
{
  //## begin XSTExceptionError::XSTExceptionError%1053507530.body preserve=yes
  //## end XSTExceptionError::XSTExceptionError%1053507530.body
}


XSTExceptionError::~XSTExceptionError()
{
  //## begin XSTExceptionError::~XSTExceptionError%.body preserve=yes
  //## end XSTExceptionError::~XSTExceptionError%.body
}



//## Other Operations (implementation)
void XSTExceptionError::Throw ()
{
  //## begin XSTExceptionError::Throw%1053507531.body preserve=yes
	throw this;
  //## end XSTExceptionError::Throw%1053507531.body
}

XCOException* XSTExceptionError::Clone ()
{
  //## begin XSTExceptionError::Clone%1053507532.body preserve=yes
	XSTExceptionError* l_pClone = new XSTExceptionError(this);
	return l_pClone;
  //## end XSTExceptionError::Clone%1053507532.body
}

// Additional Declarations
  //## begin XSTExceptionError%3ECA418D01E9.declarations preserve=yes
  //## end XSTExceptionError%3ECA418D01E9.declarations

// Class XSTExceptionLimit 

XSTExceptionLimit::XSTExceptionLimit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XSTExceptionLimit::XSTExceptionLimit%1053507534.hasinit preserve=no
  //## end XSTExceptionLimit::XSTExceptionLimit%1053507534.hasinit
  //## begin XSTExceptionLimit::XSTExceptionLimit%1053507534.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XSTExceptionLimit::XSTExceptionLimit%1053507534.initialization
{
  //## begin XSTExceptionLimit::XSTExceptionLimit%1053507534.body preserve=yes
  //## end XSTExceptionLimit::XSTExceptionLimit%1053507534.body
}

XSTExceptionLimit::XSTExceptionLimit (XCOExceptionError* p_pOrigException)
  //## begin XSTExceptionLimit::XSTExceptionLimit%1053507535.hasinit preserve=no
  //## end XSTExceptionLimit::XSTExceptionLimit%1053507535.hasinit
  //## begin XSTExceptionLimit::XSTExceptionLimit%1053507535.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XSTExceptionLimit::XSTExceptionLimit%1053507535.initialization
{
  //## begin XSTExceptionLimit::XSTExceptionLimit%1053507535.body preserve=yes
  //## end XSTExceptionLimit::XSTExceptionLimit%1053507535.body
}


XSTExceptionLimit::~XSTExceptionLimit()
{
  //## begin XSTExceptionLimit::~XSTExceptionLimit%.body preserve=yes
  //## end XSTExceptionLimit::~XSTExceptionLimit%.body
}



//## Other Operations (implementation)
void XSTExceptionLimit::Throw ()
{
  //## begin XSTExceptionLimit::Throw%1053507536.body preserve=yes
	throw this;
  //## end XSTExceptionLimit::Throw%1053507536.body
}

XCOException* XSTExceptionLimit::Clone ()
{
  //## begin XSTExceptionLimit::Clone%1053507537.body preserve=yes
	XSTExceptionLimit* l_pClone = new XSTExceptionLimit(this);
	return l_pClone;
  //## end XSTExceptionLimit::Clone%1053507537.body
}

// Additional Declarations
  //## begin XSTExceptionLimit%3ECB4CBF01A5.declarations preserve=yes
  //## end XSTExceptionLimit%3ECB4CBF01A5.declarations

// Class XSTExceptionSoftLimitHit 

XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit%1055751813.hasinit preserve=no
  //## end XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit%1055751813.hasinit
  //## begin XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit%1055751813.initialization preserve=yes
	: XSTExceptionLimit(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit%1055751813.initialization
{
  //## begin XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit%1055751813.body preserve=yes
  //## end XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit%1055751813.body
}

XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit (XCOExceptionError* p_pOrigException)
  //## begin XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit%1055751814.hasinit preserve=no
  //## end XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit%1055751814.hasinit
  //## begin XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit%1055751814.initialization preserve=yes
	: XSTExceptionLimit(p_pOrigException)
  //## end XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit%1055751814.initialization
{
  //## begin XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit%1055751814.body preserve=yes
  //## end XSTExceptionSoftLimitHit::XSTExceptionSoftLimitHit%1055751814.body
}


XSTExceptionSoftLimitHit::~XSTExceptionSoftLimitHit()
{
  //## begin XSTExceptionSoftLimitHit::~XSTExceptionSoftLimitHit%.body preserve=yes
  //## end XSTExceptionSoftLimitHit::~XSTExceptionSoftLimitHit%.body
}



//## Other Operations (implementation)
void XSTExceptionSoftLimitHit::Throw ()
{
  //## begin XSTExceptionSoftLimitHit::Throw%1055751815.body preserve=yes
	throw this;
  //## end XSTExceptionSoftLimitHit::Throw%1055751815.body
}

XCOException* XSTExceptionSoftLimitHit::Clone ()
{
  //## begin XSTExceptionSoftLimitHit::Clone%1055751816.body preserve=yes
	XSTExceptionSoftLimitHit* l_pClone = new XSTExceptionSoftLimitHit(this);
	return l_pClone;
  //## end XSTExceptionSoftLimitHit::Clone%1055751816.body
}

// Additional Declarations
  //## begin XSTExceptionSoftLimitHit%3EED7D4F02EF.declarations preserve=yes
  //## end XSTExceptionSoftLimitHit%3EED7D4F02EF.declarations

// Class XSTExceptionErrorStepsDeviation 

XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation%1065511409.hasinit preserve=no
  //## end XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation%1065511409.hasinit
  //## begin XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation%1065511409.initialization preserve=yes
	: XSTExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation%1065511409.initialization
{
  //## begin XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation%1065511409.body preserve=yes
  //## end XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation%1065511409.body
}

XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation (XCOExceptionError* p_pOrigException)
  //## begin XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation%1065511410.hasinit preserve=no
  //## end XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation%1065511410.hasinit
  //## begin XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation%1065511410.initialization preserve=yes
	: XSTExceptionError(p_pOrigException)
  //## end XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation%1065511410.initialization
{
  //## begin XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation%1065511410.body preserve=yes
  //## end XSTExceptionErrorStepsDeviation::XSTExceptionErrorStepsDeviation%1065511410.body
}


XSTExceptionErrorStepsDeviation::~XSTExceptionErrorStepsDeviation()
{
  //## begin XSTExceptionErrorStepsDeviation::~XSTExceptionErrorStepsDeviation%.body preserve=yes
  //## end XSTExceptionErrorStepsDeviation::~XSTExceptionErrorStepsDeviation%.body
}



//## Other Operations (implementation)
void XSTExceptionErrorStepsDeviation::Throw ()
{
  //## begin XSTExceptionErrorStepsDeviation::Throw%1065511411.body preserve=yes
	throw this;
  //## end XSTExceptionErrorStepsDeviation::Throw%1065511411.body
}

XCOException* XSTExceptionErrorStepsDeviation::Clone ()
{
  //## begin XSTExceptionErrorStepsDeviation::Clone%1065511412.body preserve=yes
	XSTExceptionErrorStepsDeviation* l_pClone = new XSTExceptionErrorStepsDeviation(this);
	return l_pClone;
  //## end XSTExceptionErrorStepsDeviation::Clone%1065511412.body
}

// Additional Declarations
  //## begin XSTExceptionErrorStepsDeviation%3F826BA90341.declarations preserve=yes
  //## end XSTExceptionErrorStepsDeviation%3F826BA90341.declarations

// Class XSTExceptionHoming 

XSTExceptionHoming::XSTExceptionHoming (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XSTExceptionHoming::XSTExceptionHoming%1066031269.hasinit preserve=no
  //## end XSTExceptionHoming::XSTExceptionHoming%1066031269.hasinit
  //## begin XSTExceptionHoming::XSTExceptionHoming%1066031269.initialization preserve=yes
	:XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XSTExceptionHoming::XSTExceptionHoming%1066031269.initialization
{
  //## begin XSTExceptionHoming::XSTExceptionHoming%1066031269.body preserve=yes
  //## end XSTExceptionHoming::XSTExceptionHoming%1066031269.body
}

XSTExceptionHoming::XSTExceptionHoming (XCOExceptionError* p_pOrigException)
  //## begin XSTExceptionHoming::XSTExceptionHoming%1066031270.hasinit preserve=no
  //## end XSTExceptionHoming::XSTExceptionHoming%1066031270.hasinit
  //## begin XSTExceptionHoming::XSTExceptionHoming%1066031270.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XSTExceptionHoming::XSTExceptionHoming%1066031270.initialization
{
  //## begin XSTExceptionHoming::XSTExceptionHoming%1066031270.body preserve=yes
  //## end XSTExceptionHoming::XSTExceptionHoming%1066031270.body
}


XSTExceptionHoming::~XSTExceptionHoming()
{
  //## begin XSTExceptionHoming::~XSTExceptionHoming%.body preserve=yes
  //## end XSTExceptionHoming::~XSTExceptionHoming%.body
}



//## Other Operations (implementation)
void XSTExceptionHoming::Throw ()
{
  //## begin XSTExceptionHoming::Throw%1066031271.body preserve=yes
	throw this;
  //## end XSTExceptionHoming::Throw%1066031271.body
}

XCOException* XSTExceptionHoming::Clone ()
{
  //## begin XSTExceptionHoming::Clone%1066031272.body preserve=yes
	XSTExceptionHoming* l_pClone = new XSTExceptionHoming(this);
	return l_pClone;
  //## end XSTExceptionHoming::Clone%1066031272.body
}

// Additional Declarations
  //## begin XSTExceptionHoming%3F8A5FEF0269.declarations preserve=yes
  //## end XSTExceptionHoming%3F8A5FEF0269.declarations

// Class XSTExcepitonHomingSensorNotFound 

XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound%1066031273.hasinit preserve=no
  //## end XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound%1066031273.hasinit
  //## begin XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound%1066031273.initialization preserve=yes
  :XSTExceptionHoming(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound%1066031273.initialization
{
  //## begin XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound%1066031273.body preserve=yes
  //## end XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound%1066031273.body
}

XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound (XCOExceptionError* p_pOrigException)
  //## begin XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound%1066031274.hasinit preserve=no
  //## end XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound%1066031274.hasinit
  //## begin XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound%1066031274.initialization preserve=yes
  :XSTExceptionHoming(p_pOrigException)
  //## end XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound%1066031274.initialization
{
  //## begin XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound%1066031274.body preserve=yes
  //## end XSTExcepitonHomingSensorNotFound::XSTExcepitonHomingSensorNotFound%1066031274.body
}


XSTExcepitonHomingSensorNotFound::~XSTExcepitonHomingSensorNotFound()
{
  //## begin XSTExcepitonHomingSensorNotFound::~XSTExcepitonHomingSensorNotFound%.body preserve=yes
  //## end XSTExcepitonHomingSensorNotFound::~XSTExcepitonHomingSensorNotFound%.body
}



//## Other Operations (implementation)
void XSTExcepitonHomingSensorNotFound::Throw ()
{
  //## begin XSTExcepitonHomingSensorNotFound::Throw%1066031275.body preserve=yes
	throw this;
  //## end XSTExcepitonHomingSensorNotFound::Throw%1066031275.body
}

XCOException* XSTExcepitonHomingSensorNotFound::Clone ()
{
  //## begin XSTExcepitonHomingSensorNotFound::Clone%1066031276.body preserve=yes
	XSTExcepitonHomingSensorNotFound* l_pClone = new XSTExcepitonHomingSensorNotFound(this);
	return l_pClone;
  //## end XSTExcepitonHomingSensorNotFound::Clone%1066031276.body
}

// Additional Declarations
  //## begin XSTExcepitonHomingSensorNotFound%3F8A6008018E.declarations preserve=yes
  //## end XSTExcepitonHomingSensorNotFound%3F8A6008018E.declarations

// Class XSTExceptionHomingRepeatAccuracy 

XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy%1066031277.hasinit preserve=no
  //## end XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy%1066031277.hasinit
  //## begin XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy%1066031277.initialization preserve=yes
  : XSTExceptionHoming(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy%1066031277.initialization
{
  //## begin XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy%1066031277.body preserve=yes
  //## end XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy%1066031277.body
}

XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy (XCOExceptionError* p_pOrigException)
  //## begin XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy%1066031278.hasinit preserve=no
  //## end XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy%1066031278.hasinit
  //## begin XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy%1066031278.initialization preserve=yes
  : XSTExceptionHoming(p_pOrigException)
  //## end XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy%1066031278.initialization
{
  //## begin XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy%1066031278.body preserve=yes
  //## end XSTExceptionHomingRepeatAccuracy::XSTExceptionHomingRepeatAccuracy%1066031278.body
}


XSTExceptionHomingRepeatAccuracy::~XSTExceptionHomingRepeatAccuracy()
{
  //## begin XSTExceptionHomingRepeatAccuracy::~XSTExceptionHomingRepeatAccuracy%.body preserve=yes
  //## end XSTExceptionHomingRepeatAccuracy::~XSTExceptionHomingRepeatAccuracy%.body
}



//## Other Operations (implementation)
void XSTExceptionHomingRepeatAccuracy::Throw ()
{
  //## begin XSTExceptionHomingRepeatAccuracy::Throw%1066031279.body preserve=yes
	throw this;
  //## end XSTExceptionHomingRepeatAccuracy::Throw%1066031279.body
}

XCOException* XSTExceptionHomingRepeatAccuracy::Clone ()
{
  //## begin XSTExceptionHomingRepeatAccuracy::Clone%1066031280.body preserve=yes
	XSTExceptionHomingRepeatAccuracy* l_pClone = new XSTExceptionHomingRepeatAccuracy(this);
	return l_pClone;
  //## end XSTExceptionHomingRepeatAccuracy::Clone%1066031280.body
}

// Additional Declarations
  //## begin XSTExceptionHomingRepeatAccuracy%3F8A604403E0.declarations preserve=yes
  //## end XSTExceptionHomingRepeatAccuracy%3F8A604403E0.declarations

// Class XSTExceptionTimeOnTime 

XSTExceptionTimeOnTime::XSTExceptionTimeOnTime (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XSTExceptionTimeOnTime::XSTExceptionTimeOnTime%1066031281.hasinit preserve=no
  //## end XSTExceptionTimeOnTime::XSTExceptionTimeOnTime%1066031281.hasinit
  //## begin XSTExceptionTimeOnTime::XSTExceptionTimeOnTime%1066031281.initialization preserve=yes
  :XSTExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XSTExceptionTimeOnTime::XSTExceptionTimeOnTime%1066031281.initialization
{
  //## begin XSTExceptionTimeOnTime::XSTExceptionTimeOnTime%1066031281.body preserve=yes
  //## end XSTExceptionTimeOnTime::XSTExceptionTimeOnTime%1066031281.body
}

XSTExceptionTimeOnTime::XSTExceptionTimeOnTime (XCOExceptionError* p_pOrigException)
  //## begin XSTExceptionTimeOnTime::XSTExceptionTimeOnTime%1066031282.hasinit preserve=no
  //## end XSTExceptionTimeOnTime::XSTExceptionTimeOnTime%1066031282.hasinit
  //## begin XSTExceptionTimeOnTime::XSTExceptionTimeOnTime%1066031282.initialization preserve=yes
  :XSTExceptionError(p_pOrigException)
  //## end XSTExceptionTimeOnTime::XSTExceptionTimeOnTime%1066031282.initialization
{
  //## begin XSTExceptionTimeOnTime::XSTExceptionTimeOnTime%1066031282.body preserve=yes
  //## end XSTExceptionTimeOnTime::XSTExceptionTimeOnTime%1066031282.body
}


XSTExceptionTimeOnTime::~XSTExceptionTimeOnTime()
{
  //## begin XSTExceptionTimeOnTime::~XSTExceptionTimeOnTime%.body preserve=yes
  //## end XSTExceptionTimeOnTime::~XSTExceptionTimeOnTime%.body
}



//## Other Operations (implementation)
void XSTExceptionTimeOnTime::Throw ()
{
  //## begin XSTExceptionTimeOnTime::Throw%1066031283.body preserve=yes
  	throw this;
  //## end XSTExceptionTimeOnTime::Throw%1066031283.body
}

XCOException* XSTExceptionTimeOnTime::Clone ()
{
  //## begin XSTExceptionTimeOnTime::Clone%1066031284.body preserve=yes
	XSTExceptionTimeOnTime* l_pClone = new XSTExceptionTimeOnTime(this);
	return l_pClone;
  //## end XSTExceptionTimeOnTime::Clone%1066031284.body
}

// Additional Declarations
  //## begin XSTExceptionTimeOnTime%3F8A64730396.declarations preserve=yes
  //## end XSTExceptionTimeOnTime%3F8A64730396.declarations

// Class XSTExceptionHomingLimitConfig 

XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig%1066031287.hasinit preserve=no
  //## end XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig%1066031287.hasinit
  //## begin XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig%1066031287.initialization preserve=yes
  :XSTExceptionHoming(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig%1066031287.initialization
{
  //## begin XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig%1066031287.body preserve=yes
  //## end XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig%1066031287.body
}

XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig (XCOExceptionError* p_pOrigException)
  //## begin XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig%1066031288.hasinit preserve=no
  //## end XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig%1066031288.hasinit
  //## begin XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig%1066031288.initialization preserve=yes
	:XSTExceptionHoming(p_pOrigException)
  //## end XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig%1066031288.initialization
{
  //## begin XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig%1066031288.body preserve=yes
  //## end XSTExceptionHomingLimitConfig::XSTExceptionHomingLimitConfig%1066031288.body
}


XSTExceptionHomingLimitConfig::~XSTExceptionHomingLimitConfig()
{
  //## begin XSTExceptionHomingLimitConfig::~XSTExceptionHomingLimitConfig%.body preserve=yes
  //## end XSTExceptionHomingLimitConfig::~XSTExceptionHomingLimitConfig%.body
}



//## Other Operations (implementation)
void XSTExceptionHomingLimitConfig::Throw ()
{
  //## begin XSTExceptionHomingLimitConfig::Throw%1066031289.body preserve=yes
	throw this;
  //## end XSTExceptionHomingLimitConfig::Throw%1066031289.body
}

XCOException* XSTExceptionHomingLimitConfig::Clone ()
{
  //## begin XSTExceptionHomingLimitConfig::Clone%1066031290.body preserve=yes
	XSTExceptionHomingLimitConfig* l_pClone = new XSTExceptionHomingLimitConfig(this);
	return l_pClone;
  //## end XSTExceptionHomingLimitConfig::Clone%1066031290.body
}

// Additional Declarations
  //## begin XSTExceptionHomingLimitConfig%3F8A8D9E00C7.declarations preserve=yes
  //## end XSTExceptionHomingLimitConfig%3F8A8D9E00C7.declarations

// Class XSTExceptionLimitJitter 

XSTExceptionLimitJitter::XSTExceptionLimitJitter (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XSTExceptionLimitJitter::XSTExceptionLimitJitter%1071664278.hasinit preserve=no
  //## end XSTExceptionLimitJitter::XSTExceptionLimitJitter%1071664278.hasinit
  //## begin XSTExceptionLimitJitter::XSTExceptionLimitJitter%1071664278.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XSTExceptionLimitJitter::XSTExceptionLimitJitter%1071664278.initialization
{
  //## begin XSTExceptionLimitJitter::XSTExceptionLimitJitter%1071664278.body preserve=yes
  //## end XSTExceptionLimitJitter::XSTExceptionLimitJitter%1071664278.body
}

XSTExceptionLimitJitter::XSTExceptionLimitJitter (XCOExceptionError* p_pOrigException)
  //## begin XSTExceptionLimitJitter::XSTExceptionLimitJitter%1071664279.hasinit preserve=no
  //## end XSTExceptionLimitJitter::XSTExceptionLimitJitter%1071664279.hasinit
  //## begin XSTExceptionLimitJitter::XSTExceptionLimitJitter%1071664279.initialization preserve=yes
    : XCOExceptionError(p_pOrigException)
  //## end XSTExceptionLimitJitter::XSTExceptionLimitJitter%1071664279.initialization
{
  //## begin XSTExceptionLimitJitter::XSTExceptionLimitJitter%1071664279.body preserve=yes
  //## end XSTExceptionLimitJitter::XSTExceptionLimitJitter%1071664279.body
}


XSTExceptionLimitJitter::~XSTExceptionLimitJitter()
{
  //## begin XSTExceptionLimitJitter::~XSTExceptionLimitJitter%.body preserve=yes
  //## end XSTExceptionLimitJitter::~XSTExceptionLimitJitter%.body
}



//## Other Operations (implementation)
void XSTExceptionLimitJitter::Throw ()
{
  //## begin XSTExceptionLimitJitter::Throw%1071664280.body preserve=yes
	throw this;
  //## end XSTExceptionLimitJitter::Throw%1071664280.body
}

XCOException* XSTExceptionLimitJitter::Clone ()
{
  //## begin XSTExceptionLimitJitter::Clone%1071664281.body preserve=yes
	XSTExceptionLimitJitter* l_pClone = new XSTExceptionLimitJitter(this);
	return l_pClone;
  //## end XSTExceptionLimitJitter::Clone%1071664281.body
}

// Additional Declarations
  //## begin XSTExceptionLimitJitter%3FCC6F180196.declarations preserve=yes
  //## end XSTExceptionLimitJitter%3FCC6F180196.declarations

// Class XSTExceptionHardLimitHit 

XSTExceptionHardLimitHit::XSTExceptionHardLimitHit (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XSTExceptionHardLimitHit::XSTExceptionHardLimitHit%1071664274.hasinit preserve=no
  //## end XSTExceptionHardLimitHit::XSTExceptionHardLimitHit%1071664274.hasinit
  //## begin XSTExceptionHardLimitHit::XSTExceptionHardLimitHit%1071664274.initialization preserve=yes
  :XSTExceptionLimit(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XSTExceptionHardLimitHit::XSTExceptionHardLimitHit%1071664274.initialization
{
  //## begin XSTExceptionHardLimitHit::XSTExceptionHardLimitHit%1071664274.body preserve=yes
  //## end XSTExceptionHardLimitHit::XSTExceptionHardLimitHit%1071664274.body
}

XSTExceptionHardLimitHit::XSTExceptionHardLimitHit (XCOExceptionError* p_pOrigException)
  //## begin XSTExceptionHardLimitHit::XSTExceptionHardLimitHit%1071664275.hasinit preserve=no
  //## end XSTExceptionHardLimitHit::XSTExceptionHardLimitHit%1071664275.hasinit
  //## begin XSTExceptionHardLimitHit::XSTExceptionHardLimitHit%1071664275.initialization preserve=yes
	:XSTExceptionLimit(p_pOrigException)
  //## end XSTExceptionHardLimitHit::XSTExceptionHardLimitHit%1071664275.initialization
{
  //## begin XSTExceptionHardLimitHit::XSTExceptionHardLimitHit%1071664275.body preserve=yes
  //## end XSTExceptionHardLimitHit::XSTExceptionHardLimitHit%1071664275.body
}


XSTExceptionHardLimitHit::~XSTExceptionHardLimitHit()
{
  //## begin XSTExceptionHardLimitHit::~XSTExceptionHardLimitHit%.body preserve=yes
  //## end XSTExceptionHardLimitHit::~XSTExceptionHardLimitHit%.body
}



//## Other Operations (implementation)
void XSTExceptionHardLimitHit::Throw ()
{
  //## begin XSTExceptionHardLimitHit::Throw%1071664276.body preserve=yes
	throw this;
  //## end XSTExceptionHardLimitHit::Throw%1071664276.body
}

XCOException* XSTExceptionHardLimitHit::Clone ()
{
  //## begin XSTExceptionHardLimitHit::Clone%1071664277.body preserve=yes
	XSTExceptionHardLimitHit* l_pClone = new XSTExceptionHardLimitHit(this);
	return l_pClone;
  //## end XSTExceptionHardLimitHit::Clone%1071664277.body
}

// Additional Declarations
  //## begin XSTExceptionHardLimitHit%3FE04C170235.declarations preserve=yes
  //## end XSTExceptionHardLimitHit%3FE04C170235.declarations

//## begin module%3ECA3CA101C9.epilog preserve=yes
//## end module%3ECA3CA101C9.epilog
