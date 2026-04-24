//## begin module%3F49F8270290.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F49F8270290.cm

//## begin module%3F49F8270290.cp preserve=no
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
//## end module%3F49F8270290.cp

//## Module: EBI2CADCexcp%3F49F8270290; Package body
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Source file: R:\Embedded\src\EBI2CADC\EBI2CADCexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F49F8270290.additionalIncludes preserve=no
//## end module%3F49F8270290.additionalIncludes

//## begin module%3F49F8270290.includes preserve=yes
//## end module%3F49F8270290.includes

// EBI2CADCexcp
#include "EBI2CADCexcp.h"
//## begin module%3F49F8270290.declarations preserve=no
//## end module%3F49F8270290.declarations

//## begin module%3F49F8270290.additionalDeclarations preserve=yes
//## end module%3F49F8270290.additionalDeclarations


// Class XI2CADCExceptionError 

XI2CADCExceptionError::XI2CADCExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XI2CADCExceptionError::XI2CADCExceptionError%1061804167.hasinit preserve=no
  //## end XI2CADCExceptionError::XI2CADCExceptionError%1061804167.hasinit
  //## begin XI2CADCExceptionError::XI2CADCExceptionError%1061804167.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XI2CADCExceptionError::XI2CADCExceptionError%1061804167.initialization
{
  //## begin XI2CADCExceptionError::XI2CADCExceptionError%1061804167.body preserve=yes
  //## end XI2CADCExceptionError::XI2CADCExceptionError%1061804167.body
}

XI2CADCExceptionError::XI2CADCExceptionError (XCOExceptionError* p_pOrigException)
  //## begin XI2CADCExceptionError::XI2CADCExceptionError%1061804168.hasinit preserve=no
  //## end XI2CADCExceptionError::XI2CADCExceptionError%1061804168.hasinit
  //## begin XI2CADCExceptionError::XI2CADCExceptionError%1061804168.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XI2CADCExceptionError::XI2CADCExceptionError%1061804168.initialization
{
  //## begin XI2CADCExceptionError::XI2CADCExceptionError%1061804168.body preserve=yes
  //## end XI2CADCExceptionError::XI2CADCExceptionError%1061804168.body
}


XI2CADCExceptionError::~XI2CADCExceptionError()
{
  //## begin XI2CADCExceptionError::~XI2CADCExceptionError%.body preserve=yes
  //## end XI2CADCExceptionError::~XI2CADCExceptionError%.body
}



//## Other Operations (implementation)
void XI2CADCExceptionError::Throw ()
{
  //## begin XI2CADCExceptionError::Throw%1061804169.body preserve=yes
    throw this;
  //## end XI2CADCExceptionError::Throw%1061804169.body
}

XCOException* XI2CADCExceptionError::Clone ()
{
  //## begin XI2CADCExceptionError::Clone%1061804170.body preserve=yes
  XI2CADCExceptionError* l_pClone = new XI2CADCExceptionError(this);
  return l_pClone;
  //## end XI2CADCExceptionError::Clone%1061804170.body
}

// Additional Declarations
  //## begin XI2CADCExceptionError%3F4A1D06002E.declarations preserve=yes
  //## end XI2CADCExceptionError%3F4A1D06002E.declarations

//## begin module%3F49F8270290.epilog preserve=yes
//## end module%3F49F8270290.epilog
