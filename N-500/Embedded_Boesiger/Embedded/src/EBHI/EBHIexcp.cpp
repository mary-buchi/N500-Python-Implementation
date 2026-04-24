//## begin module%3E364B1A0222.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E364B1A0222.cm

//## begin module%3E364B1A0222.cp preserve=no
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
//## end module%3E364B1A0222.cp

//## Module: EBHIexcp%3E364B1A0222; Package body
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E364B1A0222.additionalIncludes preserve=no
//## end module%3E364B1A0222.additionalIncludes

//## begin module%3E364B1A0222.includes preserve=yes
//## end module%3E364B1A0222.includes

// EBHIexcp
#include "EBHIexcp.h"
//## begin module%3E364B1A0222.declarations preserve=no
//## end module%3E364B1A0222.declarations

//## begin module%3E364B1A0222.additionalDeclarations preserve=yes
//## end module%3E364B1A0222.additionalDeclarations


// Class XHIExceptionError 

XHIExceptionError::XHIExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XHIExceptionError::XHIExceptionError%1043738360.hasinit preserve=no
  //## end XHIExceptionError::XHIExceptionError%1043738360.hasinit
  //## begin XHIExceptionError::XHIExceptionError%1043738360.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XHIExceptionError::XHIExceptionError%1043738360.initialization
{
  //## begin XHIExceptionError::XHIExceptionError%1043738360.body preserve=yes
  //## end XHIExceptionError::XHIExceptionError%1043738360.body
}

XHIExceptionError::XHIExceptionError (XCOExceptionError* p_pOrigException)
  //## begin XHIExceptionError::XHIExceptionError%1043738361.hasinit preserve=no
  //## end XHIExceptionError::XHIExceptionError%1043738361.hasinit
  //## begin XHIExceptionError::XHIExceptionError%1043738361.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XHIExceptionError::XHIExceptionError%1043738361.initialization
{
  //## begin XHIExceptionError::XHIExceptionError%1043738361.body preserve=yes
  //## end XHIExceptionError::XHIExceptionError%1043738361.body
}


XHIExceptionError::~XHIExceptionError()
{
  //## begin XHIExceptionError::~XHIExceptionError%.body preserve=yes
  //## end XHIExceptionError::~XHIExceptionError%.body
}



//## Other Operations (implementation)
void XHIExceptionError::Throw ()
{
  //## begin XHIExceptionError::Throw%1043738362.body preserve=yes
    throw this;
  //## end XHIExceptionError::Throw%1043738362.body
}

XCOException* XHIExceptionError::Clone ()
{
  //## begin XHIExceptionError::Clone%1043738363.body preserve=yes
  XHIExceptionError* l_pClone = new XHIExceptionError(this);
  return l_pClone;
  //## end XHIExceptionError::Clone%1043738363.body
}

// Additional Declarations
  //## begin XHIExceptionError%3E364C4A0148.declarations preserve=yes
  //## end XHIExceptionError%3E364C4A0148.declarations

// Class XHIHardwareExceptionError 


XHIHardwareExceptionError::XHIHardwareExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, CArray <DWORD,DWORD>* p_pdwExceptionArray)
  //## begin XHIHardwareExceptionError::XHIHardwareExceptionError%1053679531.hasinit preserve=no
  //## end XHIHardwareExceptionError::XHIHardwareExceptionError%1053679531.hasinit
  //## begin XHIHardwareExceptionError::XHIHardwareExceptionError%1053679531.initialization preserve=yes
  :XHIExceptionError (p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, 0)
  //## end XHIHardwareExceptionError::XHIHardwareExceptionError%1053679531.initialization
{
  //## begin XHIHardwareExceptionError::XHIHardwareExceptionError%1053679531.body preserve=yes
  m_pdwExceptionArray = p_pdwExceptionArray;
  //## end XHIHardwareExceptionError::XHIHardwareExceptionError%1053679531.body
}

XHIHardwareExceptionError::XHIHardwareExceptionError (XHIHardwareExceptionError* p_pOrigException)
  //## begin XHIHardwareExceptionError::XHIHardwareExceptionError%1053679532.hasinit preserve=no
  //## end XHIHardwareExceptionError::XHIHardwareExceptionError%1053679532.hasinit
  //## begin XHIHardwareExceptionError::XHIHardwareExceptionError%1053679532.initialization preserve=yes
  :XHIExceptionError (p_pOrigException)
  //## end XHIHardwareExceptionError::XHIHardwareExceptionError%1053679532.initialization
{
  //## begin XHIHardwareExceptionError::XHIHardwareExceptionError%1053679532.body preserve=yes
  for (int ii = 0; ii < p_pOrigException->GetpdwExceptionArray()->GetSize(); ii++)
  {
    m_pdwExceptionArray->SetAt(ii, p_pOrigException->GetpdwExceptionArray()->GetAt(ii));
  }
  //## end XHIHardwareExceptionError::XHIHardwareExceptionError%1053679532.body
}


XHIHardwareExceptionError::~XHIHardwareExceptionError()
{
  //## begin XHIHardwareExceptionError::~XHIHardwareExceptionError%.body preserve=yes
  //## end XHIHardwareExceptionError::~XHIHardwareExceptionError%.body
}



//## Other Operations (implementation)
void XHIHardwareExceptionError::Throw ()
{
  //## begin XHIHardwareExceptionError::Throw%1053679533.body preserve=yes
  throw this;
  //## end XHIHardwareExceptionError::Throw%1053679533.body
}

XCOException* XHIHardwareExceptionError::Clone ()
{
  //## begin XHIHardwareExceptionError::Clone%1053679534.body preserve=yes
  XHIHardwareExceptionError* l_pClone = new XHIHardwareExceptionError(this);
  return l_pClone;
  //## end XHIHardwareExceptionError::Clone%1053679534.body
}

//## Get and Set Operations for Class Attributes (implementation)

const CArray <DWORD,DWORD>* XHIHardwareExceptionError::GetpdwExceptionArray () const
{
  //## begin XHIHardwareExceptionError::GetpdwExceptionArray%3ECDEADF030D.get preserve=no
  return m_pdwExceptionArray;
  //## end XHIHardwareExceptionError::GetpdwExceptionArray%3ECDEADF030D.get
}

// Additional Declarations
  //## begin XHIHardwareExceptionError%3ECDDF21005D.declarations preserve=yes
  //## end XHIHardwareExceptionError%3ECDDF21005D.declarations

//## begin module%3E364B1A0222.epilog preserve=yes
//## end module%3E364B1A0222.epilog
