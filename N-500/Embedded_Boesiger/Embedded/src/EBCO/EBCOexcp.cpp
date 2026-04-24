//## begin module%3B8D591703BA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8D591703BA.cm

//## begin module%3B8D591703BA.cp preserve=no
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
//## end module%3B8D591703BA.cp

//## Module: EBCOexcp%3B8D591703BA; Package body
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOexcp.cpp

// stdafx
#include "stdafx.h"
//## begin module%3B8D591703BA.additionalIncludes preserve=no
//## end module%3B8D591703BA.additionalIncludes

//## begin module%3B8D591703BA.includes preserve=yes
//## end module%3B8D591703BA.includes

// EBCOexcp
#include "EBCOexcp.h"
//## begin module%3B8D591703BA.declarations preserve=no
//## end module%3B8D591703BA.declarations

//## begin module%3B8D591703BA.additionalDeclarations preserve=yes
//## end module%3B8D591703BA.additionalDeclarations


// Class XCOException 








XCOException::XCOException (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const CString& p_sRawText)
  //## begin XCOException::XCOException%1000031206.hasinit preserve=no
  //## end XCOException::XCOException%1000031206.hasinit
  //## begin XCOException::XCOException%1000031206.initialization preserve=yes
      : m_sUnitID(p_sUnitID), m_uiExceptionID(p_uiExceptionID), m_sModuleName(p_sModuleName), m_uiModuleLine(p_uiModuleLine), m_sRawText(p_sRawText)
  //## end XCOException::XCOException%1000031206.initialization
{
  //## begin XCOException::XCOException%1000031206.body preserve=yes
  m_dwErrorCode = 0;
  //## end XCOException::XCOException%1000031206.body
}

XCOException::XCOException (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XCOException::XCOException%1043748201.hasinit preserve=no
  //## end XCOException::XCOException%1043748201.hasinit
  //## begin XCOException::XCOException%1043748201.initialization preserve=yes
      : m_sUnitID(p_sUnitID), m_uiExceptionID(p_uiExceptionID), m_sModuleName(p_sModuleName), m_uiModuleLine(p_uiModuleLine), m_dwErrorCode(p_dwErrorCode)
  //## end XCOException::XCOException%1043748201.initialization
{
  //## begin XCOException::XCOException%1043748201.body preserve=yes
  //## end XCOException::XCOException%1043748201.body
}

XCOException::XCOException (XCOException* p_pOrigException)
  //## begin XCOException::XCOException%1000031213.hasinit preserve=no
  //## end XCOException::XCOException%1000031213.hasinit
  //## begin XCOException::XCOException%1000031213.initialization preserve=yes
  //## end XCOException::XCOException%1000031213.initialization
{
  //## begin XCOException::XCOException%1000031213.body preserve=yes
    m_sUnitID       = p_pOrigException->m_sUnitID;
    m_uiExceptionID = p_pOrigException->m_uiExceptionID;
    m_sModuleName   = p_pOrigException->m_sModuleName;
    m_uiModuleLine  = p_pOrigException->m_uiModuleLine;
    m_sRawText      = p_pOrigException->m_sRawText;
    m_dwErrorCode   = p_pOrigException->m_dwErrorCode;
  //## end XCOException::XCOException%1000031213.body
}


XCOException::~XCOException()
{
  //## begin XCOException::~XCOException%.body preserve=yes
  //## end XCOException::~XCOException%.body
}



//## Other Operations (implementation)
CString XCOException::GetPlainText ()
{
  //## begin XCOException::GetPlainText%1096656423.body preserve=yes
    return _T("");
  //## end XCOException::GetPlainText%1096656423.body
}

//## Get and Set Operations for Class Attributes (implementation)

const CString XCOException::GetsUnitID () const
{
  //## begin XCOException::GetsUnitID%3B9BD67A002B.get preserve=no
  return m_sUnitID;
  //## end XCOException::GetsUnitID%3B9BD67A002B.get
}

const UINT XCOException::GetuiExceptionID () const
{
  //## begin XCOException::GetuiExceptionID%3B9BD64502D8.get preserve=no
  return m_uiExceptionID;
  //## end XCOException::GetuiExceptionID%3B9BD64502D8.get
}

const CString XCOException::GetsModuleName () const
{
  //## begin XCOException::GetsModuleName%3B9BD5D403DA.get preserve=no
  return m_sModuleName;
  //## end XCOException::GetsModuleName%3B9BD5D403DA.get
}

const UINT XCOException::GetuiModuleLine () const
{
  //## begin XCOException::GetuiModuleLine%3B9BD6020386.get preserve=no
  return m_uiModuleLine;
  //## end XCOException::GetuiModuleLine%3B9BD6020386.get
}

const CString XCOException::GetsRawText () const
{
  //## begin XCOException::GetsRawText%3B9BD6A2000A.get preserve=no
  return m_sRawText;
  //## end XCOException::GetsRawText%3B9BD6A2000A.get
}

const DWORD XCOException::GetdwErrorCode () const
{
  //## begin XCOException::GetdwErrorCode%3E3678D503B9.get preserve=no
  return m_dwErrorCode;
  //## end XCOException::GetdwErrorCode%3E3678D503B9.get
}

// Additional Declarations
  //## begin XCOException%3B8D5928002F.declarations preserve=yes
  //## end XCOException%3B8D5928002F.declarations

// Class XCOExceptionInvalidState 

XCOExceptionInvalidState::XCOExceptionInvalidState (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine)
  //## begin XCOExceptionInvalidState::XCOExceptionInvalidState%1000031208.hasinit preserve=no
  //## end XCOExceptionInvalidState::XCOExceptionInvalidState%1000031208.hasinit
  //## begin XCOExceptionInvalidState::XCOExceptionInvalidState%1000031208.initialization preserve=yes
  : XCOException(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine)
  //## end XCOExceptionInvalidState::XCOExceptionInvalidState%1000031208.initialization
{
  //## begin XCOExceptionInvalidState::XCOExceptionInvalidState%1000031208.body preserve=yes
  //## end XCOExceptionInvalidState::XCOExceptionInvalidState%1000031208.body
}

XCOExceptionInvalidState::XCOExceptionInvalidState (XCOException* p_pOrigException)
  //## begin XCOExceptionInvalidState::XCOExceptionInvalidState%1000031214.hasinit preserve=no
  //## end XCOExceptionInvalidState::XCOExceptionInvalidState%1000031214.hasinit
  //## begin XCOExceptionInvalidState::XCOExceptionInvalidState%1000031214.initialization preserve=yes
  : XCOException(p_pOrigException)
  //## end XCOExceptionInvalidState::XCOExceptionInvalidState%1000031214.initialization
{
  //## begin XCOExceptionInvalidState::XCOExceptionInvalidState%1000031214.body preserve=yes
  //## end XCOExceptionInvalidState::XCOExceptionInvalidState%1000031214.body
}


XCOExceptionInvalidState::~XCOExceptionInvalidState()
{
  //## begin XCOExceptionInvalidState::~XCOExceptionInvalidState%.body preserve=yes
  //## end XCOExceptionInvalidState::~XCOExceptionInvalidState%.body
}



//## Other Operations (implementation)
void XCOExceptionInvalidState::Throw ()
{
  //## begin XCOExceptionInvalidState::Throw%1000031209.body preserve=yes
	throw this;
  //## end XCOExceptionInvalidState::Throw%1000031209.body
}

XCOException* XCOExceptionInvalidState::Clone ()
{
  //## begin XCOExceptionInvalidState::Clone%1000031210.body preserve=yes
    // create clone
    XCOException* l_pClone = new XCOExceptionInvalidState(this);

    return l_pClone;
  //## end XCOExceptionInvalidState::Clone%1000031210.body
}

// Additional Declarations
  //## begin XCOExceptionInvalidState%3B9BD7BF02BD.declarations preserve=yes
  //## end XCOExceptionInvalidState%3B9BD7BF02BD.declarations

// Class XCOExceptionCleanup 

XCOExceptionCleanup::XCOExceptionCleanup (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine)
  //## begin XCOExceptionCleanup::XCOExceptionCleanup%1000752296.hasinit preserve=no
  //## end XCOExceptionCleanup::XCOExceptionCleanup%1000752296.hasinit
  //## begin XCOExceptionCleanup::XCOExceptionCleanup%1000752296.initialization preserve=yes
  : XCOException(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine)
  //## end XCOExceptionCleanup::XCOExceptionCleanup%1000752296.initialization
{
  //## begin XCOExceptionCleanup::XCOExceptionCleanup%1000752296.body preserve=yes
  //## end XCOExceptionCleanup::XCOExceptionCleanup%1000752296.body
}

XCOExceptionCleanup::XCOExceptionCleanup (XCOException* p_pOrigException)
  //## begin XCOExceptionCleanup::XCOExceptionCleanup%1000752306.hasinit preserve=no
  //## end XCOExceptionCleanup::XCOExceptionCleanup%1000752306.hasinit
  //## begin XCOExceptionCleanup::XCOExceptionCleanup%1000752306.initialization preserve=yes
  : XCOException(p_pOrigException)
  //## end XCOExceptionCleanup::XCOExceptionCleanup%1000752306.initialization
{
  //## begin XCOExceptionCleanup::XCOExceptionCleanup%1000752306.body preserve=yes
  //## end XCOExceptionCleanup::XCOExceptionCleanup%1000752306.body
}


XCOExceptionCleanup::~XCOExceptionCleanup()
{
  //## begin XCOExceptionCleanup::~XCOExceptionCleanup%.body preserve=yes
  //## end XCOExceptionCleanup::~XCOExceptionCleanup%.body
}


// Additional Declarations
  //## begin XCOExceptionCleanup%3BA6498E00F2.declarations preserve=yes
  //## end XCOExceptionCleanup%3BA6498E00F2.declarations

// Class XCOExceptionError 

XCOExceptionError::XCOExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const CString& p_sRawText)
  //## begin XCOExceptionError::XCOExceptionError%1000752297.hasinit preserve=no
  //## end XCOExceptionError::XCOExceptionError%1000752297.hasinit
  //## begin XCOExceptionError::XCOExceptionError%1000752297.initialization preserve=yes
  : XCOException(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine)
  //## end XCOExceptionError::XCOExceptionError%1000752297.initialization
{
  //## begin XCOExceptionError::XCOExceptionError%1000752297.body preserve=yes
  //## end XCOExceptionError::XCOExceptionError%1000752297.body
}

XCOExceptionError::XCOExceptionError (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const DWORD p_dwErrorCode)
  //## begin XCOExceptionError::XCOExceptionError%1043748200.hasinit preserve=no
  //## end XCOExceptionError::XCOExceptionError%1043748200.hasinit
  //## begin XCOExceptionError::XCOExceptionError%1043748200.initialization preserve=yes
  : XCOException(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_dwErrorCode)
  //## end XCOExceptionError::XCOExceptionError%1043748200.initialization
{
  //## begin XCOExceptionError::XCOExceptionError%1043748200.body preserve=yes
  //## end XCOExceptionError::XCOExceptionError%1043748200.body
}

XCOExceptionError::XCOExceptionError (XCOExceptionError* p_pOrigException)
  //## begin XCOExceptionError::XCOExceptionError%1001060427.hasinit preserve=no
  //## end XCOExceptionError::XCOExceptionError%1001060427.hasinit
  //## begin XCOExceptionError::XCOExceptionError%1001060427.initialization preserve=yes
  : XCOException(p_pOrigException)
  //## end XCOExceptionError::XCOExceptionError%1001060427.initialization
{
  //## begin XCOExceptionError::XCOExceptionError%1001060427.body preserve=yes
  //## end XCOExceptionError::XCOExceptionError%1001060427.body
}


XCOExceptionError::~XCOExceptionError()
{
  //## begin XCOExceptionError::~XCOExceptionError%.body preserve=yes
  //## end XCOExceptionError::~XCOExceptionError%.body
}


// Additional Declarations
  //## begin XCOExceptionError%3BA649E20099.declarations preserve=yes
  //## end XCOExceptionError%3BA649E20099.declarations

// Class XCOExceptionCleanupInitialize 

XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine)
  //## begin XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize%1000752298.hasinit preserve=no
  //## end XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize%1000752298.hasinit
  //## begin XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize%1000752298.initialization preserve=yes
  : XCOExceptionCleanup(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine)
  //## end XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize%1000752298.initialization
{
  //## begin XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize%1000752298.body preserve=yes
  //## end XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize%1000752298.body
}

XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize (XCOException* p_pOrigException)
  //## begin XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize%1000752299.hasinit preserve=no
  //## end XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize%1000752299.hasinit
  //## begin XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize%1000752299.initialization preserve=yes
  : XCOExceptionCleanup(p_pOrigException)
  //## end XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize%1000752299.initialization
{
  //## begin XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize%1000752299.body preserve=yes
  //## end XCOExceptionCleanupInitialize::XCOExceptionCleanupInitialize%1000752299.body
}


XCOExceptionCleanupInitialize::~XCOExceptionCleanupInitialize()
{
  //## begin XCOExceptionCleanupInitialize::~XCOExceptionCleanupInitialize%.body preserve=yes
  //## end XCOExceptionCleanupInitialize::~XCOExceptionCleanupInitialize%.body
}



//## Other Operations (implementation)
void XCOExceptionCleanupInitialize::Throw ()
{
  //## begin XCOExceptionCleanupInitialize::Throw%1000752300.body preserve=yes
    throw this;
  //## end XCOExceptionCleanupInitialize::Throw%1000752300.body
}

XCOException* XCOExceptionCleanupInitialize::Clone ()
{
  //## begin XCOExceptionCleanupInitialize::Clone%1000752301.body preserve=yes
    // create clone
    XCOException* l_pClone = new XCOExceptionCleanupInitialize(this);

    return l_pClone;
  //## end XCOExceptionCleanupInitialize::Clone%1000752301.body
}

// Additional Declarations
  //## begin XCOExceptionCleanupInitialize%3BA64A6701EF.declarations preserve=yes
  //## end XCOExceptionCleanupInitialize%3BA64A6701EF.declarations

// Class XCOExceptionCleanupStop 

XCOExceptionCleanupStop::XCOExceptionCleanupStop (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine)
  //## begin XCOExceptionCleanupStop::XCOExceptionCleanupStop%1000752302.hasinit preserve=no
  //## end XCOExceptionCleanupStop::XCOExceptionCleanupStop%1000752302.hasinit
  //## begin XCOExceptionCleanupStop::XCOExceptionCleanupStop%1000752302.initialization preserve=yes
  : XCOExceptionCleanup(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine)
  //## end XCOExceptionCleanupStop::XCOExceptionCleanupStop%1000752302.initialization
{
  //## begin XCOExceptionCleanupStop::XCOExceptionCleanupStop%1000752302.body preserve=yes
  //## end XCOExceptionCleanupStop::XCOExceptionCleanupStop%1000752302.body
}

XCOExceptionCleanupStop::XCOExceptionCleanupStop (XCOException* p_pOrigException)
  //## begin XCOExceptionCleanupStop::XCOExceptionCleanupStop%1000752303.hasinit preserve=no
  //## end XCOExceptionCleanupStop::XCOExceptionCleanupStop%1000752303.hasinit
  //## begin XCOExceptionCleanupStop::XCOExceptionCleanupStop%1000752303.initialization preserve=yes
  : XCOExceptionCleanup(p_pOrigException)
  //## end XCOExceptionCleanupStop::XCOExceptionCleanupStop%1000752303.initialization
{
  //## begin XCOExceptionCleanupStop::XCOExceptionCleanupStop%1000752303.body preserve=yes
  //## end XCOExceptionCleanupStop::XCOExceptionCleanupStop%1000752303.body
}


XCOExceptionCleanupStop::~XCOExceptionCleanupStop()
{
  //## begin XCOExceptionCleanupStop::~XCOExceptionCleanupStop%.body preserve=yes
  //## end XCOExceptionCleanupStop::~XCOExceptionCleanupStop%.body
}



//## Other Operations (implementation)
void XCOExceptionCleanupStop::Throw ()
{
  //## begin XCOExceptionCleanupStop::Throw%1000752304.body preserve=yes
    throw this;
  //## end XCOExceptionCleanupStop::Throw%1000752304.body
}

XCOException* XCOExceptionCleanupStop::Clone ()
{
  //## begin XCOExceptionCleanupStop::Clone%1000752305.body preserve=yes
    // create clone
    XCOException* l_pClone = new XCOExceptionCleanupStop(this);

    return l_pClone;
  //## end XCOExceptionCleanupStop::Clone%1000752305.body
}

// Additional Declarations
  //## begin XCOExceptionCleanupStop%3BA64A9E01C6.declarations preserve=yes
  //## end XCOExceptionCleanupStop%3BA64A9E01C6.declarations

// Class XCOExceptionErrorNative 

XCOExceptionErrorNative::XCOExceptionErrorNative (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine, const CString& p_sRawText)
  //## begin XCOExceptionErrorNative::XCOExceptionErrorNative%1001268501.hasinit preserve=no
  //## end XCOExceptionErrorNative::XCOExceptionErrorNative%1001268501.hasinit
  //## begin XCOExceptionErrorNative::XCOExceptionErrorNative%1001268501.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine, p_sRawText)
  //## end XCOExceptionErrorNative::XCOExceptionErrorNative%1001268501.initialization
{
  //## begin XCOExceptionErrorNative::XCOExceptionErrorNative%1001268501.body preserve=yes
  //## end XCOExceptionErrorNative::XCOExceptionErrorNative%1001268501.body
}

XCOExceptionErrorNative::XCOExceptionErrorNative (XCOExceptionError* p_pOrigException)
  //## begin XCOExceptionErrorNative::XCOExceptionErrorNative%1001268502.hasinit preserve=no
  //## end XCOExceptionErrorNative::XCOExceptionErrorNative%1001268502.hasinit
  //## begin XCOExceptionErrorNative::XCOExceptionErrorNative%1001268502.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XCOExceptionErrorNative::XCOExceptionErrorNative%1001268502.initialization
{
  //## begin XCOExceptionErrorNative::XCOExceptionErrorNative%1001268502.body preserve=yes
  //## end XCOExceptionErrorNative::XCOExceptionErrorNative%1001268502.body
}


XCOExceptionErrorNative::~XCOExceptionErrorNative()
{
  //## begin XCOExceptionErrorNative::~XCOExceptionErrorNative%.body preserve=yes
  //## end XCOExceptionErrorNative::~XCOExceptionErrorNative%.body
}



//## Other Operations (implementation)
void XCOExceptionErrorNative::Throw ()
{
  //## begin XCOExceptionErrorNative::Throw%1001268503.body preserve=yes
    throw this;
  //## end XCOExceptionErrorNative::Throw%1001268503.body
}

XCOException* XCOExceptionErrorNative::Clone ()
{
  //## begin XCOExceptionErrorNative::Clone%1001268504.body preserve=yes
    XCOExceptionErrorNative* l_pClone = new XCOExceptionErrorNative(this);
    return l_pClone;
  //## end XCOExceptionErrorNative::Clone%1001268504.body
}

// Additional Declarations
  //## begin XCOExceptionErrorNative%3BAE269E03CD.declarations preserve=yes
  //## end XCOExceptionErrorNative%3BAE269E03CD.declarations

// Class XCOExceptionErrorMemoryAllocation 

XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation (const CString& p_sModuleName, const UINT p_uiModuleLine)
  //## begin XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation%1080293051.hasinit preserve=no
  //## end XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation%1080293051.hasinit
  //## begin XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation%1080293051.initialization preserve=yes
  : XCOExceptionError(CO_ID, IDE_CORE_MEMORY_EXCEPTION, p_sModuleName, p_uiModuleLine)
  //## end XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation%1080293051.initialization
{
  //## begin XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation%1080293051.body preserve=yes
  //## end XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation%1080293051.body
}

XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation (XCOExceptionError* p_pOrigException)
  //## begin XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation%1080293052.hasinit preserve=no
  //## end XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation%1080293052.hasinit
  //## begin XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation%1080293052.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation%1080293052.initialization
{
  //## begin XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation%1080293052.body preserve=yes
  //## end XCOExceptionErrorMemoryAllocation::XCOExceptionErrorMemoryAllocation%1080293052.body
}


XCOExceptionErrorMemoryAllocation::~XCOExceptionErrorMemoryAllocation()
{
  //## begin XCOExceptionErrorMemoryAllocation::~XCOExceptionErrorMemoryAllocation%.body preserve=yes
  //## end XCOExceptionErrorMemoryAllocation::~XCOExceptionErrorMemoryAllocation%.body
}



//## Other Operations (implementation)
void XCOExceptionErrorMemoryAllocation::Throw ()
{
  //## begin XCOExceptionErrorMemoryAllocation::Throw%1080293053.body preserve=yes
  throw this;
  //## end XCOExceptionErrorMemoryAllocation::Throw%1080293053.body
}

XCOException* XCOExceptionErrorMemoryAllocation::Clone ()
{
  //## begin XCOExceptionErrorMemoryAllocation::Clone%1080293054.body preserve=yes
    XCOExceptionErrorMemoryAllocation* l_pClone = new XCOExceptionErrorMemoryAllocation(this);
    return l_pClone;
  //## end XCOExceptionErrorMemoryAllocation::Clone%1080293054.body
}

// Additional Declarations
  //## begin XCOExceptionErrorMemoryAllocation%40642D890119.declarations preserve=yes
  //## end XCOExceptionErrorMemoryAllocation%40642D890119.declarations

// Class XCOExceptionErrorTimeout 

XCOExceptionErrorTimeout::XCOExceptionErrorTimeout (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine)
  //## begin XCOExceptionErrorTimeout::XCOExceptionErrorTimeout%1083932475.hasinit preserve=no
  //## end XCOExceptionErrorTimeout::XCOExceptionErrorTimeout%1083932475.hasinit
  //## begin XCOExceptionErrorTimeout::XCOExceptionErrorTimeout%1083932475.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine)
  //## end XCOExceptionErrorTimeout::XCOExceptionErrorTimeout%1083932475.initialization
{
  //## begin XCOExceptionErrorTimeout::XCOExceptionErrorTimeout%1083932475.body preserve=yes
  //## end XCOExceptionErrorTimeout::XCOExceptionErrorTimeout%1083932475.body
}

XCOExceptionErrorTimeout::XCOExceptionErrorTimeout (XCOExceptionError* p_pOrigException)
  //## begin XCOExceptionErrorTimeout::XCOExceptionErrorTimeout%1083932476.hasinit preserve=no
  //## end XCOExceptionErrorTimeout::XCOExceptionErrorTimeout%1083932476.hasinit
  //## begin XCOExceptionErrorTimeout::XCOExceptionErrorTimeout%1083932476.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XCOExceptionErrorTimeout::XCOExceptionErrorTimeout%1083932476.initialization
{
  //## begin XCOExceptionErrorTimeout::XCOExceptionErrorTimeout%1083932476.body preserve=yes
  //## end XCOExceptionErrorTimeout::XCOExceptionErrorTimeout%1083932476.body
}


XCOExceptionErrorTimeout::~XCOExceptionErrorTimeout()
{
  //## begin XCOExceptionErrorTimeout::~XCOExceptionErrorTimeout%.body preserve=yes
  //## end XCOExceptionErrorTimeout::~XCOExceptionErrorTimeout%.body
}



//## Other Operations (implementation)
void XCOExceptionErrorTimeout::Throw ()
{
  //## begin XCOExceptionErrorTimeout::Throw%1083932477.body preserve=yes
    throw this;
  //## end XCOExceptionErrorTimeout::Throw%1083932477.body
}

XCOException* XCOExceptionErrorTimeout::Clone ()
{
  //## begin XCOExceptionErrorTimeout::Clone%1083932478.body preserve=yes
    XCOExceptionErrorTimeout* l_pClone = new XCOExceptionErrorTimeout(this);
    return l_pClone;
  //## end XCOExceptionErrorTimeout::Clone%1083932478.body
}

// Additional Declarations
  //## begin XCOExceptionErrorTimeout%409B7ECF02F4.declarations preserve=yes
  //## end XCOExceptionErrorTimeout%409B7ECF02F4.declarations

// Class XCOExceptionCellUndocked 

XCOExceptionCellUndocked::XCOExceptionCellUndocked (const CString& p_sUnitID, const UINT p_uiExceptionID, const CString& p_sModuleName, const UINT p_uiModuleLine)
  //## begin XCOExceptionCellUndocked::XCOExceptionCellUndocked%1098886885.hasinit preserve=no
  //## end XCOExceptionCellUndocked::XCOExceptionCellUndocked%1098886885.hasinit
  //## begin XCOExceptionCellUndocked::XCOExceptionCellUndocked%1098886885.initialization preserve=yes
  : XCOExceptionError(p_sUnitID, p_uiExceptionID, p_sModuleName, p_uiModuleLine)
  //## end XCOExceptionCellUndocked::XCOExceptionCellUndocked%1098886885.initialization
{
  //## begin XCOExceptionCellUndocked::XCOExceptionCellUndocked%1098886885.body preserve=yes
  //## end XCOExceptionCellUndocked::XCOExceptionCellUndocked%1098886885.body
}

XCOExceptionCellUndocked::XCOExceptionCellUndocked (XCOExceptionError* p_pOrigException)
  //## begin XCOExceptionCellUndocked::XCOExceptionCellUndocked%1098886886.hasinit preserve=no
  //## end XCOExceptionCellUndocked::XCOExceptionCellUndocked%1098886886.hasinit
  //## begin XCOExceptionCellUndocked::XCOExceptionCellUndocked%1098886886.initialization preserve=yes
  : XCOExceptionError(p_pOrigException)
  //## end XCOExceptionCellUndocked::XCOExceptionCellUndocked%1098886886.initialization
{
  //## begin XCOExceptionCellUndocked::XCOExceptionCellUndocked%1098886886.body preserve=yes
  //## end XCOExceptionCellUndocked::XCOExceptionCellUndocked%1098886886.body
}


XCOExceptionCellUndocked::~XCOExceptionCellUndocked()
{
  //## begin XCOExceptionCellUndocked::~XCOExceptionCellUndocked%.body preserve=yes
  //## end XCOExceptionCellUndocked::~XCOExceptionCellUndocked%.body
}



//## Other Operations (implementation)
void XCOExceptionCellUndocked::Throw ()
{
  //## begin XCOExceptionCellUndocked::Throw%1098886887.body preserve=yes
    throw this;
  //## end XCOExceptionCellUndocked::Throw%1098886887.body
}

XCOException* XCOExceptionCellUndocked::Clone ()
{
  //## begin XCOExceptionCellUndocked::Clone%1098886888.body preserve=yes
    XCOExceptionCellUndocked* l_pClone = new XCOExceptionCellUndocked(this);
    return l_pClone;
  //## end XCOExceptionCellUndocked::Clone%1098886888.body
}

// Additional Declarations
  //## begin XCOExceptionCellUndocked%417FAE9300FE.declarations preserve=yes
  //## end XCOExceptionCellUndocked%417FAE9300FE.declarations

//## begin module%3B8D591703BA.epilog preserve=yes
//## end module%3B8D591703BA.epilog
