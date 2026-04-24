//## begin module%3F4B4E900261.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F4B4E900261.cm

//## begin module%3F4B4E900261.cp preserve=no
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
//## end module%3F4B4E900261.cp

//## Module: EBI2CDPexcp%3F4B4E900261; Package body
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Source file: R:\Embedded\src\EBI2CDP\EBI2CDPexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F4B4E900261.additionalIncludes preserve=no
//## end module%3F4B4E900261.additionalIncludes

//## begin module%3F4B4E900261.includes preserve=yes
//## end module%3F4B4E900261.includes

// EBI2CDPexcp
#include "EBI2CDPexcp.h"
//## begin module%3F4B4E900261.declarations preserve=no
//## end module%3F4B4E900261.declarations

//## begin module%3F4B4E900261.additionalDeclarations preserve=yes
//## end module%3F4B4E900261.additionalDeclarations


// Class XI2CDPExceptionError 

XI2CDPExceptionError::XI2CDPExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XI2CDPExceptionError::XI2CDPExceptionError%1061902085.hasinit preserve=no
  //## end XI2CDPExceptionError::XI2CDPExceptionError%1061902085.hasinit
  //## begin XI2CDPExceptionError::XI2CDPExceptionError%1061902085.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XI2CDPExceptionError::XI2CDPExceptionError%1061902085.initialization
{
  //## begin XI2CDPExceptionError::XI2CDPExceptionError%1061902085.body preserve=yes
  //## end XI2CDPExceptionError::XI2CDPExceptionError%1061902085.body
}

XI2CDPExceptionError::XI2CDPExceptionError (XCOExceptionError* p_pOrigException)
  //## begin XI2CDPExceptionError::XI2CDPExceptionError%1061902086.hasinit preserve=no
  //## end XI2CDPExceptionError::XI2CDPExceptionError%1061902086.hasinit
  //## begin XI2CDPExceptionError::XI2CDPExceptionError%1061902086.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XI2CDPExceptionError::XI2CDPExceptionError%1061902086.initialization
{
  //## begin XI2CDPExceptionError::XI2CDPExceptionError%1061902086.body preserve=yes
  //## end XI2CDPExceptionError::XI2CDPExceptionError%1061902086.body
}


XI2CDPExceptionError::~XI2CDPExceptionError()
{
  //## begin XI2CDPExceptionError::~XI2CDPExceptionError%.body preserve=yes
  //## end XI2CDPExceptionError::~XI2CDPExceptionError%.body
}



//## Other Operations (implementation)
void XI2CDPExceptionError::Throw ()
{
  //## begin XI2CDPExceptionError::Throw%1061902087.body preserve=yes
    throw this;
  //## end XI2CDPExceptionError::Throw%1061902087.body
}

XCOException* XI2CDPExceptionError::Clone ()
{
  //## begin XI2CDPExceptionError::Clone%1061902088.body preserve=yes
  XI2CDPExceptionError* l_pClone = new XI2CDPExceptionError(this);
  return l_pClone;
  //## end XI2CDPExceptionError::Clone%1061902088.body
}

// Additional Declarations
  //## begin XI2CDPExceptionError%3F4B63C200FA.declarations preserve=yes
  //## end XI2CDPExceptionError%3F4B63C200FA.declarations

//## begin module%3F4B4E900261.epilog preserve=yes
//## end module%3F4B4E900261.epilog
