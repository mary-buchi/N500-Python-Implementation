//## begin module%3EE737B00177.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE737B00177.cm

//## begin module%3EE737B00177.cp preserve=no
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
//## end module%3EE737B00177.cp

//## Module: EBI2CEPROMexcp%3EE737B00177; Package body
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Source file: R:\Embedded\src\EBI2CEPROM\EBI2CEPROMexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE737B00177.additionalIncludes preserve=no
//## end module%3EE737B00177.additionalIncludes

//## begin module%3EE737B00177.includes preserve=yes
//## end module%3EE737B00177.includes

// EBI2CEPROMexcp
#include "EBI2CEPROMexcp.h"
//## begin module%3EE737B00177.declarations preserve=no
//## end module%3EE737B00177.declarations

//## begin module%3EE737B00177.additionalDeclarations preserve=yes
//## end module%3EE737B00177.additionalDeclarations


// Class XI2CEpromExceptionError 

XI2CEpromExceptionError::XI2CEpromExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XI2CEpromExceptionError::XI2CEpromExceptionError%1054707812.hasinit preserve=no
  //## end XI2CEpromExceptionError::XI2CEpromExceptionError%1054707812.hasinit
  //## begin XI2CEpromExceptionError::XI2CEpromExceptionError%1054707812.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XI2CEpromExceptionError::XI2CEpromExceptionError%1054707812.initialization
{
  //## begin XI2CEpromExceptionError::XI2CEpromExceptionError%1054707812.body preserve=yes
  //## end XI2CEpromExceptionError::XI2CEpromExceptionError%1054707812.body
}

XI2CEpromExceptionError::XI2CEpromExceptionError (XCOExceptionError* p_pOrigException)
  //## begin XI2CEpromExceptionError::XI2CEpromExceptionError%1054707813.hasinit preserve=no
  //## end XI2CEpromExceptionError::XI2CEpromExceptionError%1054707813.hasinit
  //## begin XI2CEpromExceptionError::XI2CEpromExceptionError%1054707813.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XI2CEpromExceptionError::XI2CEpromExceptionError%1054707813.initialization
{
  //## begin XI2CEpromExceptionError::XI2CEpromExceptionError%1054707813.body preserve=yes
  //## end XI2CEpromExceptionError::XI2CEpromExceptionError%1054707813.body
}


XI2CEpromExceptionError::~XI2CEpromExceptionError()
{
  //## begin XI2CEpromExceptionError::~XI2CEpromExceptionError%.body preserve=yes
  //## end XI2CEpromExceptionError::~XI2CEpromExceptionError%.body
}



//## Other Operations (implementation)
void XI2CEpromExceptionError::Throw ()
{
  //## begin XI2CEpromExceptionError::Throw%1054707814.body preserve=yes
    throw this;
  //## end XI2CEpromExceptionError::Throw%1054707814.body
}

XCOException* XI2CEpromExceptionError::Clone ()
{
  //## begin XI2CEpromExceptionError::Clone%1054707815.body preserve=yes
  XI2CEpromExceptionError* l_pClone = new XI2CEpromExceptionError(this);
  return l_pClone;
  //## end XI2CEpromExceptionError::Clone%1054707815.body
}

// Additional Declarations
  //## begin XI2CEpromExceptionError%3EDDB7BB0128.declarations preserve=yes
  //## end XI2CEpromExceptionError%3EDDB7BB0128.declarations

//## begin module%3EE737B00177.epilog preserve=yes
//## end module%3EE737B00177.epilog
