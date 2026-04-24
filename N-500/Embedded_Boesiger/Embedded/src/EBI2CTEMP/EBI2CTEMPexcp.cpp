//## begin module%3EE73756030D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE73756030D.cm

//## begin module%3EE73756030D.cp preserve=no
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
//## end module%3EE73756030D.cp

//## Module: EBI2CTEMPexcp%3EE73756030D; Package body
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Source file: R:\Embedded\src\EBI2CTEMP\EBI2CTEMPexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EE73756030D.additionalIncludes preserve=no
//## end module%3EE73756030D.additionalIncludes

//## begin module%3EE73756030D.includes preserve=yes
//## end module%3EE73756030D.includes

// EBI2CTEMPexcp
#include "EBI2CTEMPexcp.h"
//## begin module%3EE73756030D.declarations preserve=no
//## end module%3EE73756030D.declarations

//## begin module%3EE73756030D.additionalDeclarations preserve=yes
//## end module%3EE73756030D.additionalDeclarations


// Class XI2CTempExceptionError 

XI2CTempExceptionError::XI2CTempExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XI2CTempExceptionError::XI2CTempExceptionError%1055398085.hasinit preserve=no
  //## end XI2CTempExceptionError::XI2CTempExceptionError%1055398085.hasinit
  //## begin XI2CTempExceptionError::XI2CTempExceptionError%1055398085.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XI2CTempExceptionError::XI2CTempExceptionError%1055398085.initialization
{
  //## begin XI2CTempExceptionError::XI2CTempExceptionError%1055398085.body preserve=yes
  //## end XI2CTempExceptionError::XI2CTempExceptionError%1055398085.body
}

XI2CTempExceptionError::XI2CTempExceptionError (XCOExceptionError* p_pOrigException)
  //## begin XI2CTempExceptionError::XI2CTempExceptionError%1055398086.hasinit preserve=no
  //## end XI2CTempExceptionError::XI2CTempExceptionError%1055398086.hasinit
  //## begin XI2CTempExceptionError::XI2CTempExceptionError%1055398086.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XI2CTempExceptionError::XI2CTempExceptionError%1055398086.initialization
{
  //## begin XI2CTempExceptionError::XI2CTempExceptionError%1055398086.body preserve=yes
  //## end XI2CTempExceptionError::XI2CTempExceptionError%1055398086.body
}


XI2CTempExceptionError::~XI2CTempExceptionError()
{
  //## begin XI2CTempExceptionError::~XI2CTempExceptionError%.body preserve=yes
  //## end XI2CTempExceptionError::~XI2CTempExceptionError%.body
}



//## Other Operations (implementation)
void XI2CTempExceptionError::Throw ()
{
  //## begin XI2CTempExceptionError::Throw%1055398087.body preserve=yes
    throw this;
  //## end XI2CTempExceptionError::Throw%1055398087.body
}

XCOException* XI2CTempExceptionError::Clone ()
{
  //## begin XI2CTempExceptionError::Clone%1055398088.body preserve=yes
  XI2CTempExceptionError* l_pClone = new XI2CTempExceptionError(this);
  return l_pClone;
  //## end XI2CTempExceptionError::Clone%1055398088.body
}

// Additional Declarations
  //## begin XI2CTempExceptionError%3EE876FF0222.declarations preserve=yes
  //## end XI2CTempExceptionError%3EE876FF0222.declarations

//## begin module%3EE73756030D.epilog preserve=yes
//## end module%3EE73756030D.epilog


