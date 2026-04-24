//## begin module%3F019020016F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F019020016F.cm

//## begin module%3F019020016F.cp preserve=no
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
//## end module%3F019020016F.cp

//## Module: EBPIexcp%3F019020016F; Package body
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPIexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F019020016F.additionalIncludes preserve=no
//## end module%3F019020016F.additionalIncludes

//## begin module%3F019020016F.includes preserve=yes
//## end module%3F019020016F.includes

// EBPIexcp
#include "EBPIexcp.h"
//## begin module%3F019020016F.declarations preserve=no
//## end module%3F019020016F.declarations

//## begin module%3F019020016F.additionalDeclarations preserve=yes
//## end module%3F019020016F.additionalDeclarations


// Class XPIExceptionErrorMissingCreator 

XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const CString& p_sRawText)
  //## begin XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067246.hasinit preserve=no
  //## end XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067246.hasinit
  //## begin XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067246.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_sRawText)
  //## end XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067246.initialization
{
  //## begin XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067246.body preserve=yes
  //## end XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067246.body
}

XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067247.hasinit preserve=no
  //## end XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067247.hasinit
  //## begin XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067247.initialization preserve=yes
  : XCOExceptionError (p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067247.initialization
{
  //## begin XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067247.body preserve=yes
  //## end XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067247.body
}

XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator (XCOExceptionError* p_pOrigException)
  //## begin XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067248.hasinit preserve=no
  //## end XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067248.hasinit
  //## begin XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067248.initialization preserve=yes
  : XCOExceptionError (p_pOrigException)
  //## end XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067248.initialization
{
  //## begin XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067248.body preserve=yes
  //## end XPIExceptionErrorMissingCreator::XPIExceptionErrorMissingCreator%1057067248.body
}


XPIExceptionErrorMissingCreator::~XPIExceptionErrorMissingCreator()
{
  //## begin XPIExceptionErrorMissingCreator::~XPIExceptionErrorMissingCreator%.body preserve=yes
  //## end XPIExceptionErrorMissingCreator::~XPIExceptionErrorMissingCreator%.body
}



//## Other Operations (implementation)
void XPIExceptionErrorMissingCreator::Throw ()
{
  //## begin XPIExceptionErrorMissingCreator::Throw%1057067249.body preserve=yes
    throw this;
  //## end XPIExceptionErrorMissingCreator::Throw%1057067249.body
}

XCOException* XPIExceptionErrorMissingCreator::Clone ()
{
  //## begin XPIExceptionErrorMissingCreator::Clone%1057067250.body preserve=yes
	XPIExceptionErrorMissingCreator* l_pClone = new XPIExceptionErrorMissingCreator(this);
	return l_pClone;
  //## end XPIExceptionErrorMissingCreator::Clone%1057067250.body
}

// Additional Declarations
  //## begin XPIExceptionErrorMissingCreator%3F018EED02E6.declarations preserve=yes
  //## end XPIExceptionErrorMissingCreator%3F018EED02E6.declarations

// Class XPIExceptionInvalidObjReference 

XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine)
  //## begin XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference%1062769442.hasinit preserve=no
  //## end XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference%1062769442.hasinit
  //## begin XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference%1062769442.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, 0)
  //## end XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference%1062769442.initialization
{
  //## begin XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference%1062769442.body preserve=yes
  //## end XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference%1062769442.body
}

XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference (XCOExceptionError* p_pOrigException)
  //## begin XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference%1062769443.hasinit preserve=no
  //## end XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference%1062769443.hasinit
  //## begin XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference%1062769443.initialization preserve=yes
  : XCOExceptionError (p_pOrigException)
  //## end XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference%1062769443.initialization
{
  //## begin XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference%1062769443.body preserve=yes
  //## end XPIExceptionInvalidObjReference::XPIExceptionInvalidObjReference%1062769443.body
}


XPIExceptionInvalidObjReference::~XPIExceptionInvalidObjReference()
{
  //## begin XPIExceptionInvalidObjReference::~XPIExceptionInvalidObjReference%.body preserve=yes
  //## end XPIExceptionInvalidObjReference::~XPIExceptionInvalidObjReference%.body
}



//## Other Operations (implementation)
void XPIExceptionInvalidObjReference::Throw ()
{
  //## begin XPIExceptionInvalidObjReference::Throw%1062769444.body preserve=yes
    throw this;
  //## end XPIExceptionInvalidObjReference::Throw%1062769444.body
}

XCOException* XPIExceptionInvalidObjReference::Clone ()
{
  //## begin XPIExceptionInvalidObjReference::Clone%1062769445.body preserve=yes
	XPIExceptionInvalidObjReference* l_pClone = new XPIExceptionInvalidObjReference(this);
	return l_pClone;
  //## end XPIExceptionInvalidObjReference::Clone%1062769445.body
}

// Additional Declarations
  //## begin XPIExceptionInvalidObjReference%3F58927D00BE.declarations preserve=yes
  //## end XPIExceptionInvalidObjReference%3F58927D00BE.declarations

// Class XPIExceptionErrorTokenizing 

XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine)
  //## begin XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing%1107335986.hasinit preserve=no
  //## end XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing%1107335986.hasinit
  //## begin XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing%1107335986.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, 0)
  //## end XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing%1107335986.initialization
{
  //## begin XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing%1107335986.body preserve=yes
  //## end XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing%1107335986.body
}

XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing (XCOExceptionError* p_pOrigException)
  //## begin XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing%1107335987.hasinit preserve=no
  //## end XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing%1107335987.hasinit
  //## begin XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing%1107335987.initialization preserve=yes
  : XCOExceptionError (p_pOrigException)
  //## end XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing%1107335987.initialization
{
  //## begin XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing%1107335987.body preserve=yes
  //## end XPIExceptionErrorTokenizing::XPIExceptionErrorTokenizing%1107335987.body
}


XPIExceptionErrorTokenizing::~XPIExceptionErrorTokenizing()
{
  //## begin XPIExceptionErrorTokenizing::~XPIExceptionErrorTokenizing%.body preserve=yes
  //## end XPIExceptionErrorTokenizing::~XPIExceptionErrorTokenizing%.body
}



//## Other Operations (implementation)
void XPIExceptionErrorTokenizing::Throw ()
{
  //## begin XPIExceptionErrorTokenizing::Throw%1107335988.body preserve=yes
    throw this;
  //## end XPIExceptionErrorTokenizing::Throw%1107335988.body
}

XCOException* XPIExceptionErrorTokenizing::Clone ()
{
  //## begin XPIExceptionErrorTokenizing::Clone%1107335989.body preserve=yes
	XPIExceptionErrorTokenizing* l_pClone = new XPIExceptionErrorTokenizing(this);
	return l_pClone;
  //## end XPIExceptionErrorTokenizing::Clone%1107335989.body
}

// Additional Declarations
  //## begin XPIExceptionErrorTokenizing%42009B6F00E1.declarations preserve=yes
  //## end XPIExceptionErrorTokenizing%42009B6F00E1.declarations

//## begin module%3F019020016F.epilog preserve=yes
//## end module%3F019020016F.epilog
