//## begin module%415D8BFE00CE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%415D8BFE00CE.cm

//## begin module%415D8BFE00CE.cp preserve=no
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
//## end module%415D8BFE00CE.cp

//## Module: EBSYexcp%415D8BFE00CE; Package body
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%415D8BFE00CE.additionalIncludes preserve=no
//## end module%415D8BFE00CE.additionalIncludes

//## begin module%415D8BFE00CE.includes preserve=yes
//## end module%415D8BFE00CE.includes

// EBSYexcp
#include "EBSYexcp.h"


//## begin module%415D8BFE00CE.declarations preserve=no
//## end module%415D8BFE00CE.declarations

//## begin module%415D8BFE00CE.additionalDeclarations preserve=yes
//## end module%415D8BFE00CE.additionalDeclarations


// Class XSYExceptionErrorDeviceBusy 


XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const CString& p_sClient)
  //## begin XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy%1096648857.hasinit preserve=no
  //## end XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy%1096648857.hasinit
  //## begin XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy%1096648857.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine), m_sClient(p_sClient)
  //## end XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy%1096648857.initialization
{
  //## begin XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy%1096648857.body preserve=yes
  //## end XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy%1096648857.body
}

XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy (XCOExceptionError* p_pOrigException)
  //## begin XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy%1096648858.hasinit preserve=no
  //## end XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy%1096648858.hasinit
  //## begin XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy%1096648858.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy%1096648858.initialization
{
  //## begin XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy%1096648858.body preserve=yes
    m_sClient = ((XSYExceptionErrorDeviceBusy*)p_pOrigException)->GetsClient();
  //## end XSYExceptionErrorDeviceBusy::XSYExceptionErrorDeviceBusy%1096648858.body
}


XSYExceptionErrorDeviceBusy::~XSYExceptionErrorDeviceBusy()
{
  //## begin XSYExceptionErrorDeviceBusy::~XSYExceptionErrorDeviceBusy%.body preserve=yes
  //## end XSYExceptionErrorDeviceBusy::~XSYExceptionErrorDeviceBusy%.body
}



//## Other Operations (implementation)
CString XSYExceptionErrorDeviceBusy::GetPlainText ()
{
  //## begin XSYExceptionErrorDeviceBusy::GetPlainText%1096656424.body preserve=yes
    return m_sClient;
  //## end XSYExceptionErrorDeviceBusy::GetPlainText%1096656424.body
}

void XSYExceptionErrorDeviceBusy::Throw ()
{
  //## begin XSYExceptionErrorDeviceBusy::Throw%1096648859.body preserve=yes
    throw this;
  //## end XSYExceptionErrorDeviceBusy::Throw%1096648859.body
}

XCOException* XSYExceptionErrorDeviceBusy::Clone ()
{
  //## begin XSYExceptionErrorDeviceBusy::Clone%1096648860.body preserve=yes
    XSYExceptionErrorDeviceBusy* l_pClone = new XSYExceptionErrorDeviceBusy(this);
    return l_pClone;
  //## end XSYExceptionErrorDeviceBusy::Clone%1096648860.body
}

//## Get and Set Operations for Associations (implementation)

CString& XSYExceptionErrorDeviceBusy::GetsClient ()
{
  //## begin XSYExceptionErrorDeviceBusy::GetsClient%415D8CE303B4.get preserve=no
  return m_sClient;
  //## end XSYExceptionErrorDeviceBusy::GetsClient%415D8CE303B4.get
}

// Additional Declarations
  //## begin XSYExceptionErrorDeviceBusy%415D8BA5015D.declarations preserve=yes
  //## end XSYExceptionErrorDeviceBusy%415D8BA5015D.declarations

//## begin module%415D8BFE00CE.epilog preserve=yes
//## end module%415D8BFE00CE.epilog
