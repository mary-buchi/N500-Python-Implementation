//## begin module%3DA2A5B3034A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA2A5B3034A.cm

//## begin module%3DA2A5B3034A.cp preserve=no
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
//## end module%3DA2A5B3034A.cp

//## Module: EBETmesg%3DA2A5B3034A; Package body
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETmesg.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DA2A5B3034A.additionalIncludes preserve=no
//## end module%3DA2A5B3034A.additionalIncludes

//## begin module%3DA2A5B3034A.includes preserve=yes
//## end module%3DA2A5B3034A.includes

// EBETmesg
#include "EBETmesg.h"
// EBCOtype
#include "EBCOtype.h"
// EBCOexcp
#include "EBCOexcp.h"
// EBPItype
#include "EBPItype.h"


//## begin module%3DA2A5B3034A.declarations preserve=no
//## end module%3DA2A5B3034A.declarations

//## begin module%3DA2A5B3034A.additionalDeclarations preserve=yes
#include "EBETflog.h"
//## end module%3DA2A5B3034A.additionalDeclarations


// Class CETChannelMessage 











//## begin CETChannelMessage::uiBaseMessageSize%3DB3A4E401AF.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
UINT CETChannelMessage::m_uiBaseMessageSize = 64;
//## end CETChannelMessage::uiBaseMessageSize%3DB3A4E401AF.role

CETChannelMessage::CETChannelMessage(const CETChannelMessage &right)
  //## begin CETChannelMessage::CETChannelMessage%copy.hasinit preserve=no
  //## end CETChannelMessage::CETChannelMessage%copy.hasinit
  //## begin CETChannelMessage::CETChannelMessage%copy.initialization preserve=yes
  //## end CETChannelMessage::CETChannelMessage%copy.initialization
{
  //## begin CETChannelMessage::CETChannelMessage%copy.body preserve=yes
    m_uiTelegramSize    = m_uiBaseMessageSize;
    m_uiID              = right.m_uiID;
    m_eCommand          = right.m_eCommand;
    m_eExpectedReturn   = right.m_eExpectedReturn;
    m_uiObjRefID        = right.m_uiObjRefID;
    m_iData             = right.m_iData;
    m_eType             = right.m_eType;
	m_uiExceptionID		= right.m_uiExceptionID;

    wcscpy(m_sObjRefVersion, right.m_sObjRefVersion);


	if (m_eCommand == eCmdStartup)
	{
		CString l_sMsg;
		l_sMsg.Format(_T("Received Startup Command on ObjRefID= %.i"), m_uiObjRefID);
		CETFileLogger::GetInstance()->AddMessage(l_sMsg);
	}
	if (m_eCommand == eCmdShutdown)
	{
		CString l_sMsg;
		l_sMsg.Format(_T("Received Shutdown Command on ObjRefID= %.i"), m_uiObjRefID);
		CETFileLogger::GetInstance()->AddMessage(l_sMsg);
	}
  //## end CETChannelMessage::CETChannelMessage%copy.body
}

CETChannelMessage::CETChannelMessage (UINT p_uiID, EETChannelCommand p_eCommand, EETChannelExpectedReturn p_eExpectedReturn, INT p_iData, UINT p_uiObjRefID, UINT p_uiTelegramSize)
  //## begin CETChannelMessage::CETChannelMessage%1034074177.hasinit preserve=no
  //## end CETChannelMessage::CETChannelMessage%1034074177.hasinit
  //## begin CETChannelMessage::CETChannelMessage%1034074177.initialization preserve=yes
    : m_uiTelegramSize(p_uiTelegramSize), m_uiID(p_uiID), m_eCommand(p_eCommand), m_eExpectedReturn(p_eExpectedReturn), m_uiObjRefID(p_uiObjRefID), m_iData(p_iData), m_eType(eInitial), m_uiExceptionID(0)
  //## end CETChannelMessage::CETChannelMessage%1034074177.initialization
{
  //## begin CETChannelMessage::CETChannelMessage%1034074177.body preserve=yes
    wcscpy(m_sObjRefVersion, L"");
  //## end CETChannelMessage::CETChannelMessage%1034074177.body
}

CETChannelMessage::CETChannelMessage (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessage::CETChannelMessage%1034074178.hasinit preserve=no
  //## end CETChannelMessage::CETChannelMessage%1034074178.hasinit
  //## begin CETChannelMessage::CETChannelMessage%1034074178.initialization preserve=yes
  //## end CETChannelMessage::CETChannelMessage%1034074178.initialization
{
  //## begin CETChannelMessage::CETChannelMessage%1034074178.body preserve=yes
    ASSERT(p_iStreamLength >= sizeof(CETChannelMessage)-4);

    m_uiTelegramSize    = *((UINT*)p_byStream);
    m_uiID              = *((UINT*)(p_byStream+4));
    m_eCommand          = *((EETChannelCommand*)(p_byStream+8));
    m_eExpectedReturn   = *((EETChannelExpectedReturn*)(p_byStream+12));
    m_uiObjRefID        = *((UINT*)(p_byStream+16));
    m_iData             = *((INT*)(p_byStream+20));
    m_eType             = *((EETChannelMessageType*)(p_byStream+24));
    m_uiExceptionID     = *((UINT*)(p_byStream+28));

    // copy object reference version
    memset(m_sObjRefVersion, 0, sizeof(m_sObjRefVersion));
    memcpy(m_sObjRefVersion, p_byStream+32, sizeof(m_sObjRefVersion));

  //## end CETChannelMessage::CETChannelMessage%1034074178.body
}


CETChannelMessage::~CETChannelMessage()
{
  //## begin CETChannelMessage::~CETChannelMessage%.body preserve=yes
  //## end CETChannelMessage::~CETChannelMessage%.body
}



//## Other Operations (implementation)
void CETChannelMessage::Serialize (BYTE*& p_byStream, INT& p_iStreamLength)
{
  //## begin CETChannelMessage::Serialize%1034074179.body preserve=yes
        p_iStreamLength = sizeof(CETChannelMessage)-4;
    p_byStream = new BYTE[p_iStreamLength];

    *((UINT*)p_byStream)       = m_uiTelegramSize;
    *((UINT*)(p_byStream+4))   = m_uiID;
    *((UINT*)(p_byStream+8))   = (UINT)m_eCommand;
    *((UINT*)(p_byStream+12))  = (UINT)m_eExpectedReturn;
    *((UINT*)(p_byStream+16))  = (UINT)m_uiObjRefID;
    *((UINT*)(p_byStream+20))  = (UINT)m_iData;
    *((UINT*)(p_byStream+24))  = (UINT)m_eType;
    *((UINT*)(p_byStream+28))  = (UINT)m_uiExceptionID;

    // copy object version
    wcscpy((wchar_t*)(p_byStream+32), m_sObjRefVersion);
  //## end CETChannelMessage::Serialize%1034074179.body
}

CETChannelMessage* CETChannelMessage::GetReply ()
{
  //## begin CETChannelMessage::GetReply%1034074180.body preserve=yes
    CETChannelMessage* p_Reply = new CETChannelMessage(*this);
    p_Reply->m_eType = eReply;

    return p_Reply;
  //## end CETChannelMessage::GetReply%1034074180.body
}

CETChannelMessage* CETChannelMessage::GetErrorReply (const UINT p_uiExceptionID)
{
  //## begin CETChannelMessage::GetErrorReply%1080293050.body preserve=yes
    CETChannelMessage* p_Reply = new CETChannelMessage(*this);
    p_Reply->m_eType          = eReply;
    p_Reply->m_eCommand       = eCmdErrorReply;
    p_Reply->m_uiExceptionID  = p_uiExceptionID;

    return p_Reply;
  //## end CETChannelMessage::GetErrorReply%1080293050.body
}

//## Get and Set Operations for Class Attributes (implementation)

UINT CETChannelMessage::GetuiTelegramSize ()
{
  //## begin CETChannelMessage::GetuiTelegramSize%3DB002DC005A.get preserve=no
  return m_uiTelegramSize;
  //## end CETChannelMessage::GetuiTelegramSize%3DB002DC005A.get
}

UINT CETChannelMessage::GetuiID ()
{
  //## begin CETChannelMessage::GetuiID%3DA2A5F3034A.get preserve=no
  return m_uiID;
  //## end CETChannelMessage::GetuiID%3DA2A5F3034A.get
}

EETChannelCommand CETChannelMessage::GeteCommand ()
{
  //## begin CETChannelMessage::GeteCommand%3DA2A61503D6.get preserve=no
  return m_eCommand;
  //## end CETChannelMessage::GeteCommand%3DA2A61503D6.get
}

EETChannelExpectedReturn CETChannelMessage::GeteExpectedReturn ()
{
  //## begin CETChannelMessage::GeteExpectedReturn%3DA2A69D0359.get preserve=no
  return m_eExpectedReturn;
  //## end CETChannelMessage::GeteExpectedReturn%3DA2A69D0359.get
}

UINT CETChannelMessage::GetuiObjRefID ()
{
  //## begin CETChannelMessage::GetuiObjRefID%3DA2A6C80184.get preserve=no
  return m_uiObjRefID;
  //## end CETChannelMessage::GetuiObjRefID%3DA2A6C80184.get
}

void CETChannelMessage::SetuiObjRefID (UINT value)
{
  //## begin CETChannelMessage::SetuiObjRefID%3DA2A6C80184.set preserve=no
  m_uiObjRefID = value;
  //## end CETChannelMessage::SetuiObjRefID%3DA2A6C80184.set
}

INT CETChannelMessage::GetiData ()
{
  //## begin CETChannelMessage::GetiData%3DA2A716003C.get preserve=no
  return m_iData;
  //## end CETChannelMessage::GetiData%3DA2A716003C.get
}

void CETChannelMessage::SetiData (INT value)
{
  //## begin CETChannelMessage::SetiData%3DA2A716003C.set preserve=no
  m_iData = value;
  //## end CETChannelMessage::SetiData%3DA2A716003C.set
}

void CETChannelMessage::SetuiExceptionID (UINT value)
{
  //## begin CETChannelMessage::SetuiExceptionID%3DA2D72D02DC.set preserve=no
  m_uiExceptionID = value;
  //## end CETChannelMessage::SetuiExceptionID%3DA2D72D02DC.set
}

WCHAR* CETChannelMessage::GetsObjRefVersion ()
{
  //## begin CETChannelMessage::GetsObjRefVersion%3DA2D74C0165.get preserve=no
  return m_sObjRefVersion;
  //## end CETChannelMessage::GetsObjRefVersion%3DA2D74C0165.get
}

void CETChannelMessage::SetsObjRefVersion (WCHAR* value)
{
  //## begin CETChannelMessage::SetsObjRefVersion%3DA2D74C0165.set preserve=yes
    memset(m_sObjRefVersion, 0, 32);
    memcpy(m_sObjRefVersion, value, 30);
  //## end CETChannelMessage::SetsObjRefVersion%3DA2D74C0165.set
}

// Additional Declarations
  //## begin CETChannelMessage%3DA2A5C40146.declarations preserve=yes
  //## end CETChannelMessage%3DA2A5C40146.declarations

// Class CETChannelMessageMeasurementDataPackage 


//## begin CETChannelMessageMeasurementDataPackage::uiMessageSize%3DB3A5430162.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
UINT CETChannelMessageMeasurementDataPackage::m_uiMessageSize = m_uiBaseMessageSize+8;
//## end CETChannelMessageMeasurementDataPackage::uiMessageSize%3DB3A5430162.role

CETChannelMessageMeasurementDataPackage::CETChannelMessageMeasurementDataPackage (CETChannelMessage* p_pStdMessage)
  //## begin CETChannelMessageMeasurementDataPackage::CETChannelMessageMeasurementDataPackage%1034922741.hasinit preserve=no
      : m_pDataPackage(NULL)
  //## end CETChannelMessageMeasurementDataPackage::CETChannelMessageMeasurementDataPackage%1034922741.hasinit
  //## begin CETChannelMessageMeasurementDataPackage::CETChannelMessageMeasurementDataPackage%1034922741.initialization preserve=yes
  , CETChannelMessage(p_pStdMessage->GetuiID(), p_pStdMessage->GeteCommand(), p_pStdMessage->GeteExpectedReturn(), p_pStdMessage->GetiData(), p_pStdMessage->GetuiObjRefID(), m_uiMessageSize)
  //## end CETChannelMessageMeasurementDataPackage::CETChannelMessageMeasurementDataPackage%1034922741.initialization
{
  //## begin CETChannelMessageMeasurementDataPackage::CETChannelMessageMeasurementDataPackage%1034922741.body preserve=yes
    // throw away the std message
    delete p_pStdMessage;
  //## end CETChannelMessageMeasurementDataPackage::CETChannelMessageMeasurementDataPackage%1034922741.body
}


CETChannelMessageMeasurementDataPackage::~CETChannelMessageMeasurementDataPackage()
{
  //## begin CETChannelMessageMeasurementDataPackage::~CETChannelMessageMeasurementDataPackage%.body preserve=yes
    if (m_pDataPackage)
        m_pDataPackage->ReleaseRef();
    m_pDataPackage = NULL;
  //## end CETChannelMessageMeasurementDataPackage::~CETChannelMessageMeasurementDataPackage%.body
}



//## Other Operations (implementation)
void CETChannelMessageMeasurementDataPackage::Serialize (BYTE*& p_byStream, INT& p_iStreamLength)
{
  //## begin CETChannelMessageMeasurementDataPackage::Serialize%1034922742.body preserve=yes
    // serialize base class
    BYTE* l_pbyBaseStream;
    INT   l_iBaseStreamSize;
    CETChannelMessage::Serialize(l_pbyBaseStream, l_iBaseStreamSize);

    if (!m_pDataPackage)
    {
        p_iStreamLength = m_uiMessageSize;
        p_byStream = new BYTE[p_iStreamLength];
        
        // copy base data
        memcpy(p_byStream, l_pbyBaseStream, l_iBaseStreamSize);

        // throw away the buffer supplied by the base
        delete [] l_pbyBaseStream;

        // copy data package header
        *((UINT*)(p_byStream+l_iBaseStreamSize))    = 0;
        *((UINT*)(p_byStream+l_iBaseStreamSize+4))  = 0;
    }
    else
    {
        p_iStreamLength = m_uiMessageSize + 2*m_pDataPackage->GetuiSize();
        p_byStream = new BYTE[p_iStreamLength];
        if (p_byStream != NULL)
        {
          // copy base data
          memcpy(p_byStream, l_pbyBaseStream, l_iBaseStreamSize);

          // throw away the buffer supplied by the base
          delete [] l_pbyBaseStream;

          // copy data package header
          *((UINT*)(p_byStream+l_iBaseStreamSize))    = m_pDataPackage->GetuiID();
          *((UINT*)(p_byStream+l_iBaseStreamSize+4))  = 2*m_pDataPackage->GetuiSize();

          // copy data package data
          memcpy(p_byStream+l_iBaseStreamSize+8, m_pDataPackage->GetpLaserData(), m_pDataPackage->GetuiSize());
          memcpy(p_byStream+l_iBaseStreamSize+8+m_pDataPackage->GetuiSize(), m_pDataPackage->GetpDetectorData(), m_pDataPackage->GetuiSize());
        }
        else
        {
          // memory allocation exception
          throw new XCOExceptionErrorMemoryAllocation(__FILE__, __LINE__);
        }
    }
  //## end CETChannelMessageMeasurementDataPackage::Serialize%1034922742.body
}

//## Get and Set Operations for Associations (implementation)

void CETChannelMessageMeasurementDataPackage::SetpDataPackage (CPIMeasurementChannelDataPackage * value)
{
  //## begin CETChannelMessageMeasurementDataPackage::SetpDataPackage%3DAFB12902BB.set preserve=yes
    m_pDataPackage = value;

    // update telegram size
    m_uiTelegramSize = m_uiMessageSize + 2*m_pDataPackage->GetuiSize();
  //## end CETChannelMessageMeasurementDataPackage::SetpDataPackage%3DAFB12902BB.set
}

// Additional Declarations
  //## begin CETChannelMessageMeasurementDataPackage%3DAFADFE022D.declarations preserve=yes
  //## end CETChannelMessageMeasurementDataPackage%3DAFADFE022D.declarations

// Class CETChannelMessageTwoInteger 



//## begin CETChannelMessageTwoInteger::uiMessageSize%3DCA83850346.attr preserve=no  private: static UINT {U} m_uiBaseMessageSize+8
UINT CETChannelMessageTwoInteger::m_uiMessageSize = m_uiBaseMessageSize+8;
//## end CETChannelMessageTwoInteger::uiMessageSize%3DCA83850346.attr

CETChannelMessageTwoInteger::CETChannelMessageTwoInteger (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageTwoInteger::CETChannelMessageTwoInteger%1036597636.hasinit preserve=no
  //## end CETChannelMessageTwoInteger::CETChannelMessageTwoInteger%1036597636.hasinit
  //## begin CETChannelMessageTwoInteger::CETChannelMessageTwoInteger%1036597636.initialization preserve=yes
  : CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageTwoInteger::CETChannelMessageTwoInteger%1036597636.initialization
{
  //## begin CETChannelMessageTwoInteger::CETChannelMessageTwoInteger%1036597636.body preserve=yes
    ASSERT(p_iStreamLength == (int)m_uiMessageSize);
    m_iInt0 = *((int*)(p_byStream+m_uiBaseMessageSize));
	m_iInt1 = *((int*)(p_byStream+m_uiBaseMessageSize+4));
  //## end CETChannelMessageTwoInteger::CETChannelMessageTwoInteger%1036597636.body
}


CETChannelMessageTwoInteger::~CETChannelMessageTwoInteger()
{
  //## begin CETChannelMessageTwoInteger::~CETChannelMessageTwoInteger%.body preserve=yes
  //## end CETChannelMessageTwoInteger::~CETChannelMessageTwoInteger%.body
}


//## Get and Set Operations for Class Attributes (implementation)

int CETChannelMessageTwoInteger::GetiInt0 ()
{
  //## begin CETChannelMessageTwoInteger::GetiInt0%3DC939A50117.get preserve=no
  return m_iInt0;
  //## end CETChannelMessageTwoInteger::GetiInt0%3DC939A50117.get
}

int CETChannelMessageTwoInteger::GetiInt1 ()
{
  //## begin CETChannelMessageTwoInteger::GetiInt1%3DC939A50127.get preserve=no
  return m_iInt1;
  //## end CETChannelMessageTwoInteger::GetiInt1%3DC939A50127.get
}

// Additional Declarations
  //## begin CETChannelMessageTwoInteger%3DC93935034A.declarations preserve=yes
  //## end CETChannelMessageTwoInteger%3DC93935034A.declarations

// Class CETChannelMessageStepperLimit 


//## begin CETChannelMessageStepperLimit::uiMessageSize%3DCA833B0394.attr preserve=no  private: static UINT {U} m_uiBaseMessageSize+12
UINT CETChannelMessageStepperLimit::m_uiMessageSize = m_uiBaseMessageSize+12;
//## end CETChannelMessageStepperLimit::uiMessageSize%3DCA833B0394.attr



CETChannelMessageStepperLimit::CETChannelMessageStepperLimit (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageStepperLimit::CETChannelMessageStepperLimit%1036680712.hasinit preserve=no
  //## end CETChannelMessageStepperLimit::CETChannelMessageStepperLimit%1036680712.hasinit
  //## begin CETChannelMessageStepperLimit::CETChannelMessageStepperLimit%1036680712.initialization preserve=yes
  : CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageStepperLimit::CETChannelMessageStepperLimit%1036680712.initialization
{
  //## begin CETChannelMessageStepperLimit::CETChannelMessageStepperLimit%1036680712.body preserve=yes
    ASSERT(p_iStreamLength == (int)m_uiMessageSize);
    m_uiSensorID            = *((UINT*)(p_byStream+m_uiBaseMessageSize));
    m_eLimitCharacteristics = *((EPILimitCharacteristics*)(p_byStream+m_uiBaseMessageSize+4));
	m_eLimitAction          = *((EPILimitAction*)(p_byStream+m_uiBaseMessageSize+8));
  //## end CETChannelMessageStepperLimit::CETChannelMessageStepperLimit%1036680712.body
}


CETChannelMessageStepperLimit::~CETChannelMessageStepperLimit()
{
  //## begin CETChannelMessageStepperLimit::~CETChannelMessageStepperLimit%.body preserve=yes
  //## end CETChannelMessageStepperLimit::~CETChannelMessageStepperLimit%.body
}


//## Get and Set Operations for Class Attributes (implementation)

UINT CETChannelMessageStepperLimit::GetuiSensorID ()
{
  //## begin CETChannelMessageStepperLimit::GetuiSensorID%3DCA815601CF.get preserve=no
  return m_uiSensorID;
  //## end CETChannelMessageStepperLimit::GetuiSensorID%3DCA815601CF.get
}

//## Get and Set Operations for Associations (implementation)

EPILimitAction CETChannelMessageStepperLimit::GeteLimitAction ()
{
  //## begin CETChannelMessageStepperLimit::GeteLimitAction%3DCA816D00B7.get preserve=no
  return m_eLimitAction;
  //## end CETChannelMessageStepperLimit::GeteLimitAction%3DCA816D00B7.get
}

EPILimitCharacteristics CETChannelMessageStepperLimit::GeteLimitCharacteristics ()
{
  //## begin CETChannelMessageStepperLimit::GeteLimitCharacteristics%3DCA872700D6.get preserve=no
  return m_eLimitCharacteristics;
  //## end CETChannelMessageStepperLimit::GeteLimitCharacteristics%3DCA872700D6.get
}

// Additional Declarations
  //## begin CETChannelMessageStepperLimit%3DCA80DC00B6.declarations preserve=yes
  //## end CETChannelMessageStepperLimit%3DCA80DC00B6.declarations

// Class CETChannelMessageStepperProfile 

//## begin CETChannelMessageStepperProfile::uiMessageSize%3E95355A03B1.attr preserve=no  public: static UINT {U} m_uiBaseMessageSize+5*sizeof(DWORD)
UINT CETChannelMessageStepperProfile::m_uiMessageSize = m_uiBaseMessageSize+5*sizeof(DWORD);
//## end CETChannelMessageStepperProfile::uiMessageSize%3E95355A03B1.attr


CETChannelMessageStepperProfile::CETChannelMessageStepperProfile (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageStepperProfile::CETChannelMessageStepperProfile%1036680713.hasinit preserve=no
      : m_pProfile(NULL)
  //## end CETChannelMessageStepperProfile::CETChannelMessageStepperProfile%1036680713.hasinit
  //## begin CETChannelMessageStepperProfile::CETChannelMessageStepperProfile%1036680713.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageStepperProfile::CETChannelMessageStepperProfile%1036680713.initialization
{
  //## begin CETChannelMessageStepperProfile::CETChannelMessageStepperProfile%1036680713.body preserve=yes
    ASSERT(p_iStreamLength == (int)m_uiMessageSize);
    m_pProfile= new CPIStepperMotorProfile(*((DWORD*)(p_byStream+m_uiBaseMessageSize)),
										   *((DWORD*)(p_byStream+m_uiBaseMessageSize+4)),
                                           *((DWORD*)(p_byStream+m_uiBaseMessageSize+8)),
                                           *((DWORD*)(p_byStream+m_uiBaseMessageSize+12)),
                                           *((DWORD*)(p_byStream+m_uiBaseMessageSize+16)));
  //## end CETChannelMessageStepperProfile::CETChannelMessageStepperProfile%1036680713.body
}


CETChannelMessageStepperProfile::~CETChannelMessageStepperProfile()
{
  //## begin CETChannelMessageStepperProfile::~CETChannelMessageStepperProfile%.body preserve=yes
    if (m_pProfile)
    {
        m_pProfile->ReleaseRef();
        m_pProfile = NULL;
    }
  //## end CETChannelMessageStepperProfile::~CETChannelMessageStepperProfile%.body
}


//## Get and Set Operations for Associations (implementation)

CPIStepperMotorProfile * CETChannelMessageStepperProfile::GetpProfile ()
{
  //## begin CETChannelMessageStepperProfile::GetpProfile%3DCA81DE00A7.get preserve=no
  return m_pProfile;
  //## end CETChannelMessageStepperProfile::GetpProfile%3DCA81DE00A7.get
}

// Additional Declarations
  //## begin CETChannelMessageStepperProfile%3DCA81A8021D.declarations preserve=yes
  //## end CETChannelMessageStepperProfile%3DCA81A8021D.declarations

// Class CETChannelMessageStepperLimitFootPrint 


CETChannelMessageStepperLimitFootPrint::CETChannelMessageStepperLimitFootPrint (CETChannelMessage* p_pStdMessage)
  //## begin CETChannelMessageStepperLimitFootPrint::CETChannelMessageStepperLimitFootPrint%1036738399.hasinit preserve=no
      : m_pFootPrint(NULL)
  //## end CETChannelMessageStepperLimitFootPrint::CETChannelMessageStepperLimitFootPrint%1036738399.hasinit
  //## begin CETChannelMessageStepperLimitFootPrint::CETChannelMessageStepperLimitFootPrint%1036738399.initialization preserve=yes
  , CETChannelMessage(p_pStdMessage->GetuiID(), p_pStdMessage->GeteCommand(), p_pStdMessage->GeteExpectedReturn(), p_pStdMessage->GetiData(), p_pStdMessage->GetuiObjRefID(), p_pStdMessage->GetuiTelegramSize())
  //## end CETChannelMessageStepperLimitFootPrint::CETChannelMessageStepperLimitFootPrint%1036738399.initialization
{
  //## begin CETChannelMessageStepperLimitFootPrint::CETChannelMessageStepperLimitFootPrint%1036738399.body preserve=yes
    // throw away the std message
    delete p_pStdMessage;
  //## end CETChannelMessageStepperLimitFootPrint::CETChannelMessageStepperLimitFootPrint%1036738399.body
}


CETChannelMessageStepperLimitFootPrint::~CETChannelMessageStepperLimitFootPrint()
{
  //## begin CETChannelMessageStepperLimitFootPrint::~CETChannelMessageStepperLimitFootPrint%.body preserve=yes
    if (m_pFootPrint)
        m_pFootPrint->ReleaseRef();
    m_pFootPrint = NULL;
  //## end CETChannelMessageStepperLimitFootPrint::~CETChannelMessageStepperLimitFootPrint%.body
}



//## Other Operations (implementation)
void CETChannelMessageStepperLimitFootPrint::Serialize (BYTE*& p_byStream, INT& p_iStreamLength)
{
  //## begin CETChannelMessageStepperLimitFootPrint::Serialize%1036738400.body preserve=yes
    // serialize base class
    BYTE* l_pbyBaseStream;
    INT   l_iBaseStreamSize;
    CETChannelMessage::Serialize(l_pbyBaseStream, l_iBaseStreamSize);

    p_iStreamLength = m_uiBaseMessageSize + sizeof(INT) + m_pFootPrint->GetArray().GetSize() * sizeof(INT);
    p_byStream = new BYTE[p_iStreamLength];
    
    // copy base data
    memcpy(p_byStream, l_pbyBaseStream, l_iBaseStreamSize);

    // throw away the buffer supplied by the base
    delete [] l_pbyBaseStream;

    // serialize foot print
    CArray<INT,INT>& l_Array = m_pFootPrint->GetArray();

    // supply array size
    *((INT*)(p_byStream+l_iBaseStreamSize)) = l_Array.GetSize();

    for (int l_iCnt=0; l_iCnt<l_Array.GetSize(); l_iCnt++)
    {
        *((INT*)(p_byStream+l_iBaseStreamSize+(l_iCnt+1)*sizeof(INT))) = l_Array.GetAt(l_iCnt);
    }
  //## end CETChannelMessageStepperLimitFootPrint::Serialize%1036738400.body
}

//## Get and Set Operations for Associations (implementation)

CCOIntegerArray * CETChannelMessageStepperLimitFootPrint::GetpFootPrint ()
{
  //## begin CETChannelMessageStepperLimitFootPrint::GetpFootPrint%3DCB6F2E0317.get preserve=no
  return m_pFootPrint;
  //## end CETChannelMessageStepperLimitFootPrint::GetpFootPrint%3DCB6F2E0317.get
}

void CETChannelMessageStepperLimitFootPrint::SetpFootPrint (CCOIntegerArray * value)
{
  //## begin CETChannelMessageStepperLimitFootPrint::SetpFootPrint%3DCB6F2E0317.set preserve=yes
    m_pFootPrint = value;

    // update telegram size
    m_uiTelegramSize = m_uiBaseMessageSize + sizeof(INT) + m_pFootPrint->GetArray().GetSize() * sizeof(INT);
  //## end CETChannelMessageStepperLimitFootPrint::SetpFootPrint%3DCB6F2E0317.set
}

// Additional Declarations
  //## begin CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.declarations preserve=yes
  //## end CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.declarations

// Class CETChannelMessageMeasurementChannelProfile 


//## begin CETChannelMessageMeasurementChannelProfile::uiMessageSize%3DD1FF530298.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
UINT CETChannelMessageMeasurementChannelProfile::m_uiMessageSize = m_uiBaseMessageSize+8;
//## end CETChannelMessageMeasurementChannelProfile::uiMessageSize%3DD1FF530298.role

CETChannelMessageMeasurementChannelProfile::CETChannelMessageMeasurementChannelProfile (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageMeasurementChannelProfile::CETChannelMessageMeasurementChannelProfile%1037172628.hasinit preserve=no
      : m_pProfile(NULL)
  //## end CETChannelMessageMeasurementChannelProfile::CETChannelMessageMeasurementChannelProfile%1037172628.hasinit
  //## begin CETChannelMessageMeasurementChannelProfile::CETChannelMessageMeasurementChannelProfile%1037172628.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageMeasurementChannelProfile::CETChannelMessageMeasurementChannelProfile%1037172628.initialization
{
  //## begin CETChannelMessageMeasurementChannelProfile::CETChannelMessageMeasurementChannelProfile%1037172628.body preserve=yes
    ASSERT(p_iStreamLength == (int)m_uiMessageSize);
    m_pProfile= new CPIMeasurementChannelProfile(*((DWORD*)(p_byStream+m_uiBaseMessageSize)),
                                                 *((DWORD*)(p_byStream+m_uiBaseMessageSize+4)));
  //## end CETChannelMessageMeasurementChannelProfile::CETChannelMessageMeasurementChannelProfile%1037172628.body
}


CETChannelMessageMeasurementChannelProfile::~CETChannelMessageMeasurementChannelProfile()
{
  //## begin CETChannelMessageMeasurementChannelProfile::~CETChannelMessageMeasurementChannelProfile%.body preserve=yes
    if (m_pProfile)
        m_pProfile->ReleaseRef();
    m_pProfile = NULL;
  //## end CETChannelMessageMeasurementChannelProfile::~CETChannelMessageMeasurementChannelProfile%.body
}


//## Get and Set Operations for Associations (implementation)

CPIMeasurementChannelProfile * CETChannelMessageMeasurementChannelProfile::GetpProfile ()
{
  //## begin CETChannelMessageMeasurementChannelProfile::GetpProfile%3DD1FEAE0269.get preserve=no
  return m_pProfile;
  //## end CETChannelMessageMeasurementChannelProfile::GetpProfile%3DD1FEAE0269.get
}

// Additional Declarations
  //## begin CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.declarations preserve=yes
  //## end CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.declarations

// Class CETChannelMessageWedgeProfile 


//## begin CETChannelMessageWedgeProfile::uiMessageSize%3DD20713021B.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
UINT CETChannelMessageWedgeProfile::m_uiMessageSize = m_uiBaseMessageSize+(2*sizeof(DWORD));
//## end CETChannelMessageWedgeProfile::uiMessageSize%3DD20713021B.role

CETChannelMessageWedgeProfile::CETChannelMessageWedgeProfile (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageWedgeProfile::CETChannelMessageWedgeProfile%1037172629.hasinit preserve=no
      : m_pProfile(NULL)
  //## end CETChannelMessageWedgeProfile::CETChannelMessageWedgeProfile%1037172629.hasinit
  //## begin CETChannelMessageWedgeProfile::CETChannelMessageWedgeProfile%1037172629.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageWedgeProfile::CETChannelMessageWedgeProfile%1037172629.initialization
{
  //## begin CETChannelMessageWedgeProfile::CETChannelMessageWedgeProfile%1037172629.body preserve=yes

  ASSERT(p_iStreamLength == (int)m_uiMessageSize);
  m_pProfile = new CPIWedgeControlProfile(*((DWORD*)(p_byStream+m_uiBaseMessageSize)),
                                          *((DWORD*)(p_byStream+m_uiBaseMessageSize+4)));
    
 
  //## end CETChannelMessageWedgeProfile::CETChannelMessageWedgeProfile%1037172629.body
}


CETChannelMessageWedgeProfile::~CETChannelMessageWedgeProfile()
{
  //## begin CETChannelMessageWedgeProfile::~CETChannelMessageWedgeProfile%.body preserve=yes
    if (m_pProfile)
        m_pProfile->ReleaseRef();
    m_pProfile = NULL;
  //## end CETChannelMessageWedgeProfile::~CETChannelMessageWedgeProfile%.body
}


//## Get and Set Operations for Associations (implementation)

CPIWedgeControlProfile * CETChannelMessageWedgeProfile::GetpProfile ()
{
  //## begin CETChannelMessageWedgeProfile::GetpProfile%3DD206D801AD.get preserve=no
  return m_pProfile;
  //## end CETChannelMessageWedgeProfile::GetpProfile%3DD206D801AD.get
}

// Additional Declarations
  //## begin CETChannelMessageWedgeProfile%3DD2064D01EB.declarations preserve=yes
  //## end CETChannelMessageWedgeProfile%3DD2064D01EB.declarations

// Class CETChannelMessageWedgeConfig 


//## begin CETChannelMessageWedgeConfig::uiMessageSize%3DD207450121.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
UINT CETChannelMessageWedgeConfig::m_uiMessageSize = m_uiBaseMessageSize+(35*sizeof(DWORD));
//## end CETChannelMessageWedgeConfig::uiMessageSize%3DD207450121.role

CETChannelMessageWedgeConfig::CETChannelMessageWedgeConfig (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageWedgeConfig::CETChannelMessageWedgeConfig%1037172630.hasinit preserve=no
      : m_pConfig(NULL)
  //## end CETChannelMessageWedgeConfig::CETChannelMessageWedgeConfig%1037172630.hasinit
  //## begin CETChannelMessageWedgeConfig::CETChannelMessageWedgeConfig%1037172630.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageWedgeConfig::CETChannelMessageWedgeConfig%1037172630.initialization
{
  //## begin CETChannelMessageWedgeConfig::CETChannelMessageWedgeConfig%1037172630.body preserve=yes
  
  ASSERT(p_iStreamLength == (int)m_uiMessageSize);
  m_pConfig = new CPIWedgeControlConfig( *((DWORD*)(p_byStream+m_uiBaseMessageSize)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+4)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+8)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+12)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+16)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+20)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+24)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+28)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+32)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+36)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+40)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+44)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+48)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+52)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+56)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+60)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+64)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+68)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+72)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+76)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+80)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+84)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+88)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+92)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+96)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+100)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+104)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+108)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+112)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+116)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+120)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+124)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+128)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+132)),
                                         *((DWORD*)(p_byStream+m_uiBaseMessageSize+136)));

  //## end CETChannelMessageWedgeConfig::CETChannelMessageWedgeConfig%1037172630.body
}


CETChannelMessageWedgeConfig::~CETChannelMessageWedgeConfig()
{
  //## begin CETChannelMessageWedgeConfig::~CETChannelMessageWedgeConfig%.body preserve=yes
    if (m_pConfig)
        m_pConfig->ReleaseRef();
    m_pConfig = NULL;
  //## end CETChannelMessageWedgeConfig::~CETChannelMessageWedgeConfig%.body
}


//## Get and Set Operations for Associations (implementation)

CPIWedgeControlConfig * CETChannelMessageWedgeConfig::GetpConfig ()
{
  //## begin CETChannelMessageWedgeConfig::GetpConfig%3DD206DA0324.get preserve=no
  return m_pConfig;
  //## end CETChannelMessageWedgeConfig::GetpConfig%3DD206DA0324.get
}

// Additional Declarations
  //## begin CETChannelMessageWedgeConfig%3DD20666014F.declarations preserve=yes
  //## end CETChannelMessageWedgeConfig%3DD20666014F.declarations

// Class CETChannelMessageTemperatureProfile 

//## begin CETChannelMessageTemperatureProfile::uiMessageSize%3DD392080033.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
UINT CETChannelMessageTemperatureProfile::m_uiMessageSize = m_uiBaseMessageSize+5*4;
//## end CETChannelMessageTemperatureProfile::uiMessageSize%3DD392080033.role


CETChannelMessageTemperatureProfile::CETChannelMessageTemperatureProfile (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageTemperatureProfile::CETChannelMessageTemperatureProfile%1037257509.hasinit preserve=no
      : m_pProfile(NULL)
  //## end CETChannelMessageTemperatureProfile::CETChannelMessageTemperatureProfile%1037257509.hasinit
  //## begin CETChannelMessageTemperatureProfile::CETChannelMessageTemperatureProfile%1037257509.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageTemperatureProfile::CETChannelMessageTemperatureProfile%1037257509.initialization
{
  //## begin CETChannelMessageTemperatureProfile::CETChannelMessageTemperatureProfile%1037257509.body preserve=yes
    ASSERT(p_iStreamLength == (int)m_uiMessageSize);
    m_pProfile = new CPITemperatureControlProfile(
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+4)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+8)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+12)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+16)));
  //## end CETChannelMessageTemperatureProfile::CETChannelMessageTemperatureProfile%1037257509.body
}


CETChannelMessageTemperatureProfile::~CETChannelMessageTemperatureProfile()
{
  //## begin CETChannelMessageTemperatureProfile::~CETChannelMessageTemperatureProfile%.body preserve=yes
    if (m_pProfile)
        m_pProfile->ReleaseRef();
    m_pProfile = NULL;
  //## end CETChannelMessageTemperatureProfile::~CETChannelMessageTemperatureProfile%.body
}


//## Get and Set Operations for Associations (implementation)

CPITemperatureControlProfile * CETChannelMessageTemperatureProfile::GetpProfile ()
{
  //## begin CETChannelMessageTemperatureProfile::GetpProfile%3DD3924303AD.get preserve=no
  return m_pProfile;
  //## end CETChannelMessageTemperatureProfile::GetpProfile%3DD3924303AD.get
}

// Additional Declarations
  //## begin CETChannelMessageTemperatureProfile%3DD37AE200DD.declarations preserve=yes
  //## end CETChannelMessageTemperatureProfile%3DD37AE200DD.declarations

// Class CETChannelMessageTemperatureConfig 

//## begin CETChannelMessageTemperatureConfig::uiMessageSize%3DD3920A035F.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
UINT CETChannelMessageTemperatureConfig::m_uiMessageSize = m_uiBaseMessageSize+(9+2)*4;
//## end CETChannelMessageTemperatureConfig::uiMessageSize%3DD3920A035F.role


CETChannelMessageTemperatureConfig::CETChannelMessageTemperatureConfig (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageTemperatureConfig::CETChannelMessageTemperatureConfig%1037257510.hasinit preserve=no
      : m_pConfig(NULL)
  //## end CETChannelMessageTemperatureConfig::CETChannelMessageTemperatureConfig%1037257510.hasinit
  //## begin CETChannelMessageTemperatureConfig::CETChannelMessageTemperatureConfig%1037257510.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageTemperatureConfig::CETChannelMessageTemperatureConfig%1037257510.initialization
{
  //## begin CETChannelMessageTemperatureConfig::CETChannelMessageTemperatureConfig%1037257510.body preserve=yes
    ASSERT(p_iStreamLength == (int)m_uiMessageSize);
	CPIConfigDS1631Z* l_pTempCfg = new CPIConfigDS1631Z(
                        *((EPIModeDS1631Z*)(p_byStream+m_uiBaseMessageSize+36)),
                        *((EPIResolutionDS1631Z*)(p_byStream+m_uiBaseMessageSize+40)));

    m_pConfig = new CPITemperatureControlConfig(
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+0)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+4)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+8)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+12)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+16)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+20)),
                        *((EPILineVoltage*)(p_byStream+m_uiBaseMessageSize+24)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+28)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+32)),
						l_pTempCfg);
	l_pTempCfg->ReleaseRef();

  //## end CETChannelMessageTemperatureConfig::CETChannelMessageTemperatureConfig%1037257510.body
}


CETChannelMessageTemperatureConfig::~CETChannelMessageTemperatureConfig()
{
  //## begin CETChannelMessageTemperatureConfig::~CETChannelMessageTemperatureConfig%.body preserve=yes
    if (m_pConfig)
        m_pConfig->ReleaseRef();
    m_pConfig = NULL;
  //## end CETChannelMessageTemperatureConfig::~CETChannelMessageTemperatureConfig%.body
}


//## Get and Set Operations for Associations (implementation)

CPITemperatureControlConfig * CETChannelMessageTemperatureConfig::GetpConfig ()
{
  //## begin CETChannelMessageTemperatureConfig::GetpConfig%3DD3925F0061.get preserve=no
  return m_pConfig;
  //## end CETChannelMessageTemperatureConfig::GetpConfig%3DD3925F0061.get
}

// Additional Declarations
  //## begin CETChannelMessageTemperatureConfig%3DD37AF7039D.declarations preserve=yes
  //## end CETChannelMessageTemperatureConfig%3DD37AF7039D.declarations

// Class CETChannelMessagePowerProfile 

//## begin CETChannelMessagePowerProfile::uiMessageSize%3DD411730043.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
UINT CETChannelMessagePowerProfile::m_uiMessageSize = m_uiBaseMessageSize+3*4;
//## end CETChannelMessagePowerProfile::uiMessageSize%3DD411730043.role


CETChannelMessagePowerProfile::CETChannelMessagePowerProfile (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessagePowerProfile::CETChannelMessagePowerProfile%1037308032.hasinit preserve=no
      : m_pProfile(NULL)
  //## end CETChannelMessagePowerProfile::CETChannelMessagePowerProfile%1037308032.hasinit
  //## begin CETChannelMessagePowerProfile::CETChannelMessagePowerProfile%1037308032.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessagePowerProfile::CETChannelMessagePowerProfile%1037308032.initialization
{
  //## begin CETChannelMessagePowerProfile::CETChannelMessagePowerProfile%1037308032.body preserve=yes
    ASSERT(p_iStreamLength == (int)m_uiMessageSize);
    m_pProfile = new CPIPowerControlProfile(
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+4)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+8)));
  //## end CETChannelMessagePowerProfile::CETChannelMessagePowerProfile%1037308032.body
}


CETChannelMessagePowerProfile::~CETChannelMessagePowerProfile()
{
  //## begin CETChannelMessagePowerProfile::~CETChannelMessagePowerProfile%.body preserve=yes
    if (m_pProfile)
	    m_pProfile->ReleaseRef();
	m_pProfile = NULL;
  //## end CETChannelMessagePowerProfile::~CETChannelMessagePowerProfile%.body
}


//## Get and Set Operations for Associations (implementation)

CPIPowerControlProfile * CETChannelMessagePowerProfile::GetpProfile ()
{
  //## begin CETChannelMessagePowerProfile::GetpProfile%3DD411C801E0.get preserve=no
  return m_pProfile;
  //## end CETChannelMessagePowerProfile::GetpProfile%3DD411C801E0.get
}

// Additional Declarations
  //## begin CETChannelMessagePowerProfile%3DD4110F0355.declarations preserve=yes
  //## end CETChannelMessagePowerProfile%3DD4110F0355.declarations

// Class CETChannelMessagePowerConfig 

//## begin CETChannelMessagePowerConfig::uiMessageSize%3DD4119E030B.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
UINT CETChannelMessagePowerConfig::m_uiMessageSize = m_uiBaseMessageSize+34*4;
//## end CETChannelMessagePowerConfig::uiMessageSize%3DD4119E030B.role


CETChannelMessagePowerConfig::CETChannelMessagePowerConfig (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessagePowerConfig::CETChannelMessagePowerConfig%1037308031.hasinit preserve=no
      : m_pConfig(NULL)
  //## end CETChannelMessagePowerConfig::CETChannelMessagePowerConfig%1037308031.hasinit
  //## begin CETChannelMessagePowerConfig::CETChannelMessagePowerConfig%1037308031.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessagePowerConfig::CETChannelMessagePowerConfig%1037308031.initialization
{
  //## begin CETChannelMessagePowerConfig::CETChannelMessagePowerConfig%1037308031.body preserve=yes
    ASSERT(p_iStreamLength == (int)m_uiMessageSize);
    m_pConfig = new CPIPowerControlConfig(
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+0)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+4)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+8)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+12)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+16)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+20)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+24)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+28)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+32)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+36)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+40)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+44)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+48)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+52)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+56)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+60)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+64)),
                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+68)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+72)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+76)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+80)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+84)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+88)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+92)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+96)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+100)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+104)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+108)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+112)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+116)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+120)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+124)),
						*((DWORD*)(p_byStream+m_uiBaseMessageSize+128)),
						*((EPILamp*)(p_byStream+m_uiBaseMessageSize+132)));
  //## end CETChannelMessagePowerConfig::CETChannelMessagePowerConfig%1037308031.body
}


CETChannelMessagePowerConfig::~CETChannelMessagePowerConfig()
{
  //## begin CETChannelMessagePowerConfig::~CETChannelMessagePowerConfig%.body preserve=yes
    if (m_pConfig)
	    m_pConfig->ReleaseRef();
	m_pConfig = NULL;
  //## end CETChannelMessagePowerConfig::~CETChannelMessagePowerConfig%.body
}


//## Get and Set Operations for Associations (implementation)

CPIPowerControlConfig * CETChannelMessagePowerConfig::GetpConfig ()
{
  //## begin CETChannelMessagePowerConfig::GetpConfig%3DD411E5012D.get preserve=no
  return m_pConfig;
  //## end CETChannelMessagePowerConfig::GetpConfig%3DD411E5012D.get
}

// Additional Declarations
  //## begin CETChannelMessagePowerConfig%3DD4111D01C5.declarations preserve=yes
  //## end CETChannelMessagePowerConfig%3DD4111D01C5.declarations

// Class CETChannelMessagePersistentIdentification 



CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification%1037346580.hasinit preserve=no
      : m_pPersistentIdentification(NULL)
  //## end CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification%1037346580.hasinit
  //## begin CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification%1037346580.initialization preserve=yes
  ,CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification%1037346580.initialization
{
  //## begin CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification%1037346580.body preserve=yes

    // write the identification to position 0
    CPIPersistentIdent*  l_pIdent  = new CPIPersistentIdent((WCHAR*)(p_byStream + m_uiBaseMessageSize));
    ASSERT(l_pIdent != NULL);

    // add item to list
    CTypedPtrList<CPtrList, CPIPersistentItem*> l_PersistentList;
    l_PersistentList.AddTail(l_pIdent);
    m_pPersistentIdentification = new CPIPersistentItemList(l_PersistentList);
  //## end CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification%1037346580.body
}

CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification (CETChannelMessage*  p_pStdMessage)
  //## begin CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification%1074584186.hasinit preserve=no
      : m_pPersistentIdentification(NULL)
  //## end CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification%1074584186.hasinit
  //## begin CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification%1074584186.initialization preserve=yes
    ,CETChannelMessage(p_pStdMessage->GetuiID(), p_pStdMessage->GeteCommand(), p_pStdMessage->GeteExpectedReturn(), p_pStdMessage->GetiData(), p_pStdMessage->GetuiObjRefID(), m_uiBaseMessageSize)
  //## end CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification%1074584186.initialization
{
  //## begin CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification%1074584186.body preserve=yes
    delete p_pStdMessage;
  //## end CETChannelMessagePersistentIdentification::CETChannelMessagePersistentIdentification%1074584186.body
}


CETChannelMessagePersistentIdentification::~CETChannelMessagePersistentIdentification()
{
  //## begin CETChannelMessagePersistentIdentification::~CETChannelMessagePersistentIdentification%.body preserve=yes
    if (m_pPersistentIdentification)
    {
        m_pPersistentIdentification->ReleaseRef();
        m_pPersistentIdentification = NULL;
    }
  //## end CETChannelMessagePersistentIdentification::~CETChannelMessagePersistentIdentification%.body
}



//## Other Operations (implementation)
void CETChannelMessagePersistentIdentification::Serialize (BYTE*& p_byStream, INT& p_iStreamLength)
{
  //## begin CETChannelMessagePersistentIdentification::Serialize%1037632254.body preserve=yes

    // serialize base class
    BYTE* l_pbyBaseStream;
    INT   l_iBaseStreamSize;
    CETChannelMessage::Serialize(l_pbyBaseStream, l_iBaseStreamSize);

    // build stream
    p_iStreamLength = m_uiTelegramSize;
    p_byStream = new BYTE[p_iStreamLength];
    
    // copy base data
    memcpy(p_byStream, l_pbyBaseStream, l_iBaseStreamSize);

    // throw away the buffer supplied by the base
    delete [] l_pbyBaseStream;

    // copy all identifications
    if (m_sIdentifcationStream.GetLength() > 0)
    {
        memcpy(p_byStream + l_iBaseStreamSize, m_sIdentifcationStream, m_sIdentifcationStream.GetLength() * 2);
    }
  //## end CETChannelMessagePersistentIdentification::Serialize%1037632254.body
}

void CETChannelMessagePersistentIdentification::BuildIdentificationStream ()
{
  //## begin CETChannelMessagePersistentIdentification::BuildIdentificationStream%1074522947.body preserve=yes
    m_sIdentifcationStream = "";
    CPIPersistentItem* l_pObjID = NULL;

    // build one stream form all identifications
	for (POSITION l_Pos=m_pPersistentIdentification->GetItems().GetHeadPosition(); l_Pos!=NULL;)
	{
        l_pObjID = m_pPersistentIdentification->GetItems().GetNext(l_Pos);
		m_sIdentifcationStream += l_pObjID->ToString();
	}

    // set size of telegram (unicode)
    m_uiTelegramSize = m_uiBaseMessageSize + 2 * (m_sIdentifcationStream.GetLength());
  //## end CETChannelMessagePersistentIdentification::BuildIdentificationStream%1074522947.body
}

//## Get and Set Operations for Associations (implementation)

CPIPersistentItemList * CETChannelMessagePersistentIdentification::GetpPersistentIdentification ()
{
  //## begin CETChannelMessagePersistentIdentification::GetpPersistentIdentification%400CE11F02A4.get preserve=no
  return m_pPersistentIdentification;
  //## end CETChannelMessagePersistentIdentification::GetpPersistentIdentification%400CE11F02A4.get
}

void CETChannelMessagePersistentIdentification::SetpPersistentIdentification (CPIPersistentItemList * value)
{
  //## begin CETChannelMessagePersistentIdentification::SetpPersistentIdentification%400CE11F02A4.set preserve=yes
    m_pPersistentIdentification = value;

    // build identification stream and set telegram size
    BuildIdentificationStream();
  //## end CETChannelMessagePersistentIdentification::SetpPersistentIdentification%400CE11F02A4.set
}

// Additional Declarations
  //## begin CETChannelMessagePersistentIdentification%3DD4F0160019.declarations preserve=yes
  //## end CETChannelMessagePersistentIdentification%3DD4F0160019.declarations

// Class CETChannelMessagePersistentParameter 



CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter%1037346581.hasinit preserve=no
      : m_pPersistentParameter(NULL)
  //## end CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter%1037346581.hasinit
  //## begin CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter%1037346581.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter%1037346581.initialization
{
  //## begin CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter%1037346581.body preserve=yes
    // write the parameter to position 0
    CPIPersistentPara* l_pParameter = new CPIPersistentPara((WCHAR*)(p_byStream + m_uiBaseMessageSize));

    // add item to list
    CTypedPtrList<CPtrList, CPIPersistentItem*> l_ParameterList;
    l_ParameterList.AddTail(l_pParameter);
    m_pPersistentParameter = new CPIPersistentItemList(l_ParameterList);
  //## end CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter%1037346581.body
}

CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter (CETChannelMessage*  p_pStdMessage)
  //## begin CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter%1074687336.hasinit preserve=no
      : m_pPersistentParameter(NULL)
  //## end CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter%1074687336.hasinit
  //## begin CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter%1074687336.initialization preserve=yes
  ,CETChannelMessage(p_pStdMessage->GetuiID(), p_pStdMessage->GeteCommand(), p_pStdMessage->GeteExpectedReturn(), p_pStdMessage->GetiData(), p_pStdMessage->GetuiObjRefID(), m_uiBaseMessageSize)
  //## end CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter%1074687336.initialization
{
  //## begin CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter%1074687336.body preserve=yes
  delete p_pStdMessage;
  //## end CETChannelMessagePersistentParameter::CETChannelMessagePersistentParameter%1074687336.body
}


CETChannelMessagePersistentParameter::~CETChannelMessagePersistentParameter()
{
  //## begin CETChannelMessagePersistentParameter::~CETChannelMessagePersistentParameter%.body preserve=yes
    if (m_pPersistentParameter)
    {
        m_pPersistentParameter->ReleaseRef();
        m_pPersistentParameter = NULL;
    }
  //## end CETChannelMessagePersistentParameter::~CETChannelMessagePersistentParameter%.body
}



//## Other Operations (implementation)
void CETChannelMessagePersistentParameter::Serialize (BYTE*& p_byStream, INT& p_iStreamLength)
{
  //## begin CETChannelMessagePersistentParameter::Serialize%1037632256.body preserve=yes

    // serialize base class
    BYTE* l_pbyBaseStream;
    INT   l_iBaseStreamSize;
    CETChannelMessage::Serialize(l_pbyBaseStream, l_iBaseStreamSize);

    // build stream
    p_iStreamLength = m_uiTelegramSize;
    p_byStream = new BYTE[p_iStreamLength];

    // copy base data
    memcpy(p_byStream, l_pbyBaseStream, l_iBaseStreamSize);

    // throw away the buffer supplied by the base
    delete [] l_pbyBaseStream;

    // copy all identifications
    if (m_sParameterStream.GetLength() > 0)
    {
        memcpy(p_byStream + l_iBaseStreamSize, m_sParameterStream, m_sParameterStream.GetLength() * 2);
    }
  //## end CETChannelMessagePersistentParameter::Serialize%1037632256.body
}

void CETChannelMessagePersistentParameter::BuildParameterStream ()
{
  //## begin CETChannelMessagePersistentParameter::BuildParameterStream%1074687337.body preserve=yes
    m_sParameterStream = "";
    CPIPersistentItem* l_pObjID = NULL;

    // build one stream from all parameters
	for (POSITION l_Pos=m_pPersistentParameter->GetItems().GetHeadPosition(); l_Pos!=NULL;)
	{
        l_pObjID = m_pPersistentParameter->GetItems().GetNext(l_Pos);

        m_sParameterStream += l_pObjID->ToString();
	}

    // set size of telegram (unicode)
    m_uiTelegramSize = m_uiBaseMessageSize + 2 * (m_sParameterStream.GetLength());
  //## end CETChannelMessagePersistentParameter::BuildParameterStream%1074687337.body
}

//## Get and Set Operations for Associations (implementation)

CPIPersistentItemList * CETChannelMessagePersistentParameter::GetpPersistentParameter ()
{
  //## begin CETChannelMessagePersistentParameter::GetpPersistentParameter%400E75B10237.get preserve=no
  return m_pPersistentParameter;
  //## end CETChannelMessagePersistentParameter::GetpPersistentParameter%400E75B10237.get
}

void CETChannelMessagePersistentParameter::SetpPersistentParameter (CPIPersistentItemList * value)
{
  //## begin CETChannelMessagePersistentParameter::SetpPersistentParameter%400E75B10237.set preserve=yes
  m_pPersistentParameter = value;

  // build parameter stream and set telegram length
  BuildParameterStream();
  //## end CETChannelMessagePersistentParameter::SetpPersistentParameter%400E75B10237.set
}

// Additional Declarations
  //## begin CETChannelMessagePersistentParameter%3DD4F0230190.declarations preserve=yes
  //## end CETChannelMessagePersistentParameter%3DD4F0230190.declarations

// Class CETChannelMessagePersistentSoftwareComponent 


CETChannelMessagePersistentSoftwareComponent::CETChannelMessagePersistentSoftwareComponent (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessagePersistentSoftwareComponent::CETChannelMessagePersistentSoftwareComponent%1037346582.hasinit preserve=no
  //## end CETChannelMessagePersistentSoftwareComponent::CETChannelMessagePersistentSoftwareComponent%1037346582.hasinit
  //## begin CETChannelMessagePersistentSoftwareComponent::CETChannelMessagePersistentSoftwareComponent%1037346582.initialization preserve=yes
  : CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessagePersistentSoftwareComponent::CETChannelMessagePersistentSoftwareComponent%1037346582.initialization
{
  //## begin CETChannelMessagePersistentSoftwareComponent::CETChannelMessagePersistentSoftwareComponent%1037346582.body preserve=yes

    CTypedPtrList<CPtrList, CPIPersistentSoftwareComponent*> l_SWCpoList;

    const unsigned int uiFNameLength = 32 * 2; // 32 Unicode characters 
    unsigned int uiCompOffset = 0;

    int iFileCount = *(int*) (p_byStream+m_uiBaseMessageSize);
    uiCompOffset += sizeof(int);

    // For each file in stream
    for (int i = 0; i < iFileCount; i++)
    {
        unsigned int uiOffset = 0;

        // Get name of file
        WCHAR* sName = (WCHAR*)(p_byStream+m_uiBaseMessageSize+uiCompOffset + uiOffset);
        uiOffset += uiFNameLength;

        // Get reboot flag of file
        bool    bReBoot     = *(int*)(p_byStream+m_uiBaseMessageSize+uiCompOffset + uiOffset) != 0;
        uiOffset += sizeof(int);
        
        // TODO PB
        // Get FPGA Source flag of file
        bool bIsFPGASource = false;
        bIsFPGASource     = *(int*)(p_byStream+m_uiBaseMessageSize+uiCompOffset + uiOffset) != 0;
        uiOffset += sizeof(int);
        
        // Get WinCE Image flag of file
        bool bIsWinCEImage = false;
        bIsWinCEImage     = *(int*)(p_byStream+m_uiBaseMessageSize+uiCompOffset + uiOffset) != 0;
        uiOffset += sizeof(int);

        // Get Filelength (leave it in stream)
        int iFileLength = *(int*) (p_byStream + m_uiBaseMessageSize+uiCompOffset + uiOffset); 
        uiOffset += sizeof(int);

        // bImage = filelength(int) + content of file
        byte* bImage = new byte[iFileLength];
        memcpy(bImage, p_byStream + m_uiBaseMessageSize+uiCompOffset + uiOffset, iFileLength);
        uiOffset += iFileLength;

        // Create object for file and add ist to list
        CPIPersistentSoftwareComponent* pSoftwareComponent = 
            new CPIPersistentSoftwareComponent(sName, bReBoot, bIsFPGASource, bIsWinCEImage, bImage, iFileLength);
        l_SWCpoList.AddTail(pSoftwareComponent);

        uiCompOffset += uiOffset;
    }

    m_pComponents = new CPIPersistentSoftwareComponentList(l_SWCpoList);

  //## end CETChannelMessagePersistentSoftwareComponent::CETChannelMessagePersistentSoftwareComponent%1037346582.body
}


CETChannelMessagePersistentSoftwareComponent::~CETChannelMessagePersistentSoftwareComponent()
{
  //## begin CETChannelMessagePersistentSoftwareComponent::~CETChannelMessagePersistentSoftwareComponent%.body preserve=yes
    if (m_pComponents)
        m_pComponents->ReleaseRef();
    m_pComponents = NULL;
  //## end CETChannelMessagePersistentSoftwareComponent::~CETChannelMessagePersistentSoftwareComponent%.body
}


//## Get and Set Operations for Associations (implementation)

CPIPersistentSoftwareComponentList * CETChannelMessagePersistentSoftwareComponent::GetpComponents ()
{
  //## begin CETChannelMessagePersistentSoftwareComponent::GetpComponents%3DD4F1BA0068.get preserve=no
  return m_pComponents;
  //## end CETChannelMessagePersistentSoftwareComponent::GetpComponents%3DD4F1BA0068.get
}

// Additional Declarations
  //## begin CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.declarations preserve=yes
  //## end CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.declarations

// Class CETChannelMessagePersistentSoftwareComponentVersion 


CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion%1037346583.hasinit preserve=no
  //## end CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion%1037346583.hasinit
  //## begin CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion%1037346583.initialization preserve=yes
  : CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion%1037346583.initialization
{
  //## begin CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion%1037346583.body preserve=yes
  //## end CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion%1037346583.body
}

CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion (CETChannelMessage* p_pStdMessage)
  //## begin CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion%1037632257.hasinit preserve=no
  //## end CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion%1037632257.hasinit
  //## begin CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion%1037632257.initialization preserve=yes
  : CETChannelMessage(p_pStdMessage->GetuiID(), p_pStdMessage->GeteCommand(), p_pStdMessage->GeteExpectedReturn(), p_pStdMessage->GetiData(), p_pStdMessage->GetuiObjRefID(), p_pStdMessage->GetuiTelegramSize())
  //## end CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion%1037632257.initialization
{
  //## begin CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion%1037632257.body preserve=yes
    // delete unused standard message
    delete p_pStdMessage;
  //## end CETChannelMessagePersistentSoftwareComponentVersion::CETChannelMessagePersistentSoftwareComponentVersion%1037632257.body
}


CETChannelMessagePersistentSoftwareComponentVersion::~CETChannelMessagePersistentSoftwareComponentVersion()
{
  //## begin CETChannelMessagePersistentSoftwareComponentVersion::~CETChannelMessagePersistentSoftwareComponentVersion%.body preserve=yes
    // cleanup
    for (POSITION l_Pos=m_ComponentVersions.GetHeadPosition(); l_Pos!=NULL;)
    {
        m_ComponentVersions.GetNext(l_Pos)->ReleaseRef();
    }
    m_ComponentVersions.RemoveAll();
  //## end CETChannelMessagePersistentSoftwareComponentVersion::~CETChannelMessagePersistentSoftwareComponentVersion%.body
}



//## Other Operations (implementation)
void CETChannelMessagePersistentSoftwareComponentVersion::Serialize (BYTE*& p_byStream, INT& p_iStreamLength)
{
  //## begin CETChannelMessagePersistentSoftwareComponentVersion::Serialize%1037632258.body preserve=yes
    // serialize base class
    BYTE* l_pbyBaseStream;
    INT   l_iBaseStreamSize;
    CETChannelMessage::Serialize(l_pbyBaseStream, l_iBaseStreamSize);

    p_iStreamLength = m_uiTelegramSize;
    p_byStream = new BYTE[p_iStreamLength];
    
    // copy base data
    memcpy(p_byStream, l_pbyBaseStream, l_iBaseStreamSize);

    // throw away the buffer supplied by the base
    delete [] l_pbyBaseStream;

    // serialize in string
	WCHAR* l_pBuffer = (WCHAR*)(p_byStream+l_iBaseStreamSize);
	*l_pBuffer = _T('\0');
    for (POSITION l_Pos=m_ComponentVersions.GetHeadPosition(); l_Pos!=NULL;)
    {
		CPIPersistentSoftwareComponentVersion* l_CpoVersion = m_ComponentVersions.GetNext(l_Pos);

		wcscat(l_pBuffer, l_CpoVersion->GetsName());
		wcscat(l_pBuffer, _T("%"));
		wcscat(l_pBuffer, l_CpoVersion->GetsVersion());
		wcscat(l_pBuffer, _T(";"));
    }
  //## end CETChannelMessagePersistentSoftwareComponentVersion::Serialize%1037632258.body
}

//## Get and Set Operations for Associations (implementation)

CTypedPtrList<CPtrList, CPIPersistentSoftwareComponentVersion*>& CETChannelMessagePersistentSoftwareComponentVersion::GetComponentVersions ()
{
  //## begin CETChannelMessagePersistentSoftwareComponentVersion::GetComponentVersions%3DD4F1D80318.get preserve=no
  return m_ComponentVersions;
  //## end CETChannelMessagePersistentSoftwareComponentVersion::GetComponentVersions%3DD4F1D80318.get
}

void CETChannelMessagePersistentSoftwareComponentVersion::SetComponentVersions (const CTypedPtrList<CPtrList, CPIPersistentSoftwareComponentVersion*>& value)
{
  //## begin CETChannelMessagePersistentSoftwareComponentVersion::SetComponentVersions%3DD4F1D80318.set preserve=yes
    ASSERT(m_ComponentVersions.GetCount() == 0);
	int l_iSize = 0;
    for (POSITION l_Pos=value.GetHeadPosition(); l_Pos!=NULL;)
    {
		CPIPersistentSoftwareComponentVersion* l_CpoVersion = value.GetNext(l_Pos);
		l_iSize += wcslen(l_CpoVersion->GetsName())*2 + 2 + wcslen(l_CpoVersion->GetsVersion())*2 + 2 + 2;

        l_CpoVersion->AddRef();
        m_ComponentVersions.AddTail(l_CpoVersion);
    }

    // update telegram size
	m_uiTelegramSize = m_uiBaseMessageSize + l_iSize + 2;
  //## end CETChannelMessagePersistentSoftwareComponentVersion::SetComponentVersions%3DD4F1D80318.set
}

// Additional Declarations
  //## begin CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.declarations preserve=yes
  //## end CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.declarations

// Class CETChannelMessageStepperConfig 

//## begin CETChannelMessageStepperConfig::uiMessageSize%3E9535CD0363.attr preserve=no  public: static UINT {U} m_uiBaseMessageSize+12*sizeof(DWORD)
UINT CETChannelMessageStepperConfig::m_uiMessageSize = m_uiBaseMessageSize+12*sizeof(DWORD);
//## end CETChannelMessageStepperConfig::uiMessageSize%3E9535CD0363.attr


CETChannelMessageStepperConfig::CETChannelMessageStepperConfig (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageStepperConfig::CETChannelMessageStepperConfig%1049965451.hasinit preserve=no
      : m_pConfig(NULL)
  //## end CETChannelMessageStepperConfig::CETChannelMessageStepperConfig%1049965451.hasinit
  //## begin CETChannelMessageStepperConfig::CETChannelMessageStepperConfig%1049965451.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageStepperConfig::CETChannelMessageStepperConfig%1049965451.initialization
{
  //## begin CETChannelMessageStepperConfig::CETChannelMessageStepperConfig%1049965451.body preserve=yes

     ASSERT(p_iStreamLength == (int)m_uiMessageSize);
    m_pConfig = new CPIStepperMotorConfig(*((DWORD*)(p_byStream+m_uiBaseMessageSize+0)),
                                          *((DWORD*)(p_byStream+m_uiBaseMessageSize+4)),
                                          *((DWORD*)(p_byStream+m_uiBaseMessageSize+8)),
                                          *((DWORD*)(p_byStream+m_uiBaseMessageSize+12)),
										  *((DWORD*)(p_byStream+m_uiBaseMessageSize+16)),
										  *((DWORD*)(p_byStream+m_uiBaseMessageSize+20)),
										  *((DWORD*)(p_byStream+m_uiBaseMessageSize+24)),
										  *((DWORD*)(p_byStream+m_uiBaseMessageSize+28)),
										  *((DWORD*)(p_byStream+m_uiBaseMessageSize+32)),
										  *((DWORD*)(p_byStream+m_uiBaseMessageSize+36)),
										  *((DWORD*)(p_byStream+m_uiBaseMessageSize+40)),
										  *((DWORD*)(p_byStream+m_uiBaseMessageSize+44)));
  //## end CETChannelMessageStepperConfig::CETChannelMessageStepperConfig%1049965451.body
}


CETChannelMessageStepperConfig::~CETChannelMessageStepperConfig()
{
  //## begin CETChannelMessageStepperConfig::~CETChannelMessageStepperConfig%.body preserve=yes
    if (m_pConfig)
        m_pConfig->ReleaseRef();
    m_pConfig = NULL;
  //## end CETChannelMessageStepperConfig::~CETChannelMessageStepperConfig%.body
}


//## Get and Set Operations for Associations (implementation)

CPIStepperMotorConfig * CETChannelMessageStepperConfig::GetpConfig ()
{
  //## begin CETChannelMessageStepperConfig::GetpConfig%3E9533F002B8.get preserve=no
  return m_pConfig;
  //## end CETChannelMessageStepperConfig::GetpConfig%3E9533F002B8.get
}

// Additional Declarations
  //## begin CETChannelMessageStepperConfig%3E9533CE0111.declarations preserve=yes
  //## end CETChannelMessageStepperConfig%3E9533CE0111.declarations

// Class CETChannelMessageSystemInterfaceConfig 


//## begin CETChannelMessageSystemInterfaceConfig::uiMessageSize%3EE5D0A501E6.role preserve=no  public: static UINT { -> VFHN}
UINT CETChannelMessageSystemInterfaceConfig::m_uiMessageSize = m_uiBaseMessageSize+5*4;
//## end CETChannelMessageSystemInterfaceConfig::uiMessageSize%3EE5D0A501E6.role

CETChannelMessageSystemInterfaceConfig::CETChannelMessageSystemInterfaceConfig (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageSystemInterfaceConfig::CETChannelMessageSystemInterfaceConfig%1055243209.hasinit preserve=no
      : m_pConfig(NULL)
  //## end CETChannelMessageSystemInterfaceConfig::CETChannelMessageSystemInterfaceConfig%1055243209.hasinit
  //## begin CETChannelMessageSystemInterfaceConfig::CETChannelMessageSystemInterfaceConfig%1055243209.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageSystemInterfaceConfig::CETChannelMessageSystemInterfaceConfig%1055243209.initialization
{
  //## begin CETChannelMessageSystemInterfaceConfig::CETChannelMessageSystemInterfaceConfig%1055243209.body preserve=yes
    ASSERT(p_iStreamLength == (int)m_uiMessageSize);
    m_pConfig = new CPIInterfaceConfig(*((EPIInterface*)(p_byStream+m_uiBaseMessageSize)),
                                       *((DWORD*)(p_byStream+m_uiBaseMessageSize+4)),
                                       *((DWORD*)(p_byStream+m_uiBaseMessageSize+8)),
                                       *((DWORD*)(p_byStream+m_uiBaseMessageSize+12)),
                                       *((bool*)(p_byStream+m_uiBaseMessageSize+16)));
  //## end CETChannelMessageSystemInterfaceConfig::CETChannelMessageSystemInterfaceConfig%1055243209.body
}


CETChannelMessageSystemInterfaceConfig::~CETChannelMessageSystemInterfaceConfig()
{
  //## begin CETChannelMessageSystemInterfaceConfig::~CETChannelMessageSystemInterfaceConfig%.body preserve=yes
  //## end CETChannelMessageSystemInterfaceConfig::~CETChannelMessageSystemInterfaceConfig%.body
}


//## Get and Set Operations for Associations (implementation)

CPIInterfaceConfig * CETChannelMessageSystemInterfaceConfig::GetpConfig ()
{
  //## begin CETChannelMessageSystemInterfaceConfig::GetpConfig%3EE5D0860274.get preserve=no
  return m_pConfig;
  //## end CETChannelMessageSystemInterfaceConfig::GetpConfig%3EE5D0860274.get
}

// Additional Declarations
  //## begin CETChannelMessageSystemInterfaceConfig%3EE5D0440040.declarations preserve=yes
  //## end CETChannelMessageSystemInterfaceConfig%3EE5D0440040.declarations

// Class CETChannelMessageI2CTempDS1631ZConfig 

//## begin CETChannelMessageI2CTempDS1631ZConfig::uiMessageSize%3EE5EDAC03BC.role preserve=no  public: static UINT { -> VFHN}
UINT CETChannelMessageI2CTempDS1631ZConfig::m_uiMessageSize = m_uiBaseMessageSize+2*4;
//## end CETChannelMessageI2CTempDS1631ZConfig::uiMessageSize%3EE5EDAC03BC.role


CETChannelMessageI2CTempDS1631ZConfig::CETChannelMessageI2CTempDS1631ZConfig (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageI2CTempDS1631ZConfig::CETChannelMessageI2CTempDS1631ZConfig%1055243216.hasinit preserve=no
      : m_pConfig(NULL)
  //## end CETChannelMessageI2CTempDS1631ZConfig::CETChannelMessageI2CTempDS1631ZConfig%1055243216.hasinit
  //## begin CETChannelMessageI2CTempDS1631ZConfig::CETChannelMessageI2CTempDS1631ZConfig%1055243216.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageI2CTempDS1631ZConfig::CETChannelMessageI2CTempDS1631ZConfig%1055243216.initialization
{
  //## begin CETChannelMessageI2CTempDS1631ZConfig::CETChannelMessageI2CTempDS1631ZConfig%1055243216.body preserve=yes
    ASSERT(p_iStreamLength == (int)m_uiMessageSize);
    m_pConfig = new CPIConfigDS1631Z(*((EPIModeDS1631Z*)(p_byStream+m_uiBaseMessageSize)),
                                     *((EPIResolutionDS1631Z*)(p_byStream+m_uiBaseMessageSize+4)));
  //## end CETChannelMessageI2CTempDS1631ZConfig::CETChannelMessageI2CTempDS1631ZConfig%1055243216.body
}


CETChannelMessageI2CTempDS1631ZConfig::~CETChannelMessageI2CTempDS1631ZConfig()
{
  //## begin CETChannelMessageI2CTempDS1631ZConfig::~CETChannelMessageI2CTempDS1631ZConfig%.body preserve=yes
    if (m_pConfig)
        m_pConfig->ReleaseRef();
    m_pConfig = NULL;
  //## end CETChannelMessageI2CTempDS1631ZConfig::~CETChannelMessageI2CTempDS1631ZConfig%.body
}


//## Get and Set Operations for Associations (implementation)

CPIConfigDS1631Z * CETChannelMessageI2CTempDS1631ZConfig::GetpConfig ()
{
  //## begin CETChannelMessageI2CTempDS1631ZConfig::GetpConfig%3EE5EDB6033F.get preserve=no
  return m_pConfig;
  //## end CETChannelMessageI2CTempDS1631ZConfig::GetpConfig%3EE5EDB6033F.get
}

// Additional Declarations
  //## begin CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.declarations preserve=yes
  //## end CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.declarations

// Class CETChannelMessageSystemComponentState 



//## begin CETChannelMessageSystemComponentState::uiMessageSize%3F4628230067.role preserve=no  public: static UINT { -> VFHN}
UINT CETChannelMessageSystemComponentState::m_uiMessageSize = m_uiBaseMessageSize+4+32;
//## end CETChannelMessageSystemComponentState::uiMessageSize%3F4628230067.role

CETChannelMessageSystemComponentState::CETChannelMessageSystemComponentState (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageSystemComponentState::CETChannelMessageSystemComponentState%1061562116.hasinit preserve=no
  //## end CETChannelMessageSystemComponentState::CETChannelMessageSystemComponentState%1061562116.hasinit
  //## begin CETChannelMessageSystemComponentState::CETChannelMessageSystemComponentState%1061562116.initialization preserve=yes
  : CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageSystemComponentState::CETChannelMessageSystemComponentState%1061562116.initialization
{
  //## begin CETChannelMessageSystemComponentState::CETChannelMessageSystemComponentState%1061562116.body preserve=yes
    wcscpy(m_sCpoName, (wchar_t*)(p_byStream+m_uiBaseMessageSize));
    m_bState = *((bool*)(p_byStream+m_uiBaseMessageSize+32));
  //## end CETChannelMessageSystemComponentState::CETChannelMessageSystemComponentState%1061562116.body
}


CETChannelMessageSystemComponentState::~CETChannelMessageSystemComponentState()
{
  //## begin CETChannelMessageSystemComponentState::~CETChannelMessageSystemComponentState%.body preserve=yes
  //## end CETChannelMessageSystemComponentState::~CETChannelMessageSystemComponentState%.body
}


//## Get and Set Operations for Class Attributes (implementation)

WCHAR* CETChannelMessageSystemComponentState::GetsCpoName ()
{
  //## begin CETChannelMessageSystemComponentState::GetsCpoName%3F46287703C1.get preserve=no
  return m_sCpoName;
  //## end CETChannelMessageSystemComponentState::GetsCpoName%3F46287703C1.get
}

bool CETChannelMessageSystemComponentState::GetbState ()
{
  //## begin CETChannelMessageSystemComponentState::GetbState%3F4628920392.get preserve=no
  return m_bState;
  //## end CETChannelMessageSystemComponentState::GetbState%3F4628920392.get
}

// Additional Declarations
  //## begin CETChannelMessageSystemComponentState%3F4627E90315.declarations preserve=yes
  //## end CETChannelMessageSystemComponentState%3F4627E90315.declarations

// Class CETChannelMessageSystemGetObjectList 


CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList%1063715462.hasinit preserve=no
      : m_pObjList(NULL)
  //## end CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList%1063715462.hasinit
  //## begin CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList%1063715462.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList%1063715462.initialization
{
  //## begin CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList%1063715462.body preserve=yes
  //## end CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList%1063715462.body
}

CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList (const CETChannelMessage& p_Right)
  //## begin CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList%1063715467.hasinit preserve=no
      : m_pObjList(NULL)
  //## end CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList%1063715467.hasinit
  //## begin CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList%1063715467.initialization preserve=yes
  , CETChannelMessage(p_Right)
  //## end CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList%1063715467.initialization
{
  //## begin CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList%1063715467.body preserve=yes
  //## end CETChannelMessageSystemGetObjectList::CETChannelMessageSystemGetObjectList%1063715467.body
}


CETChannelMessageSystemGetObjectList::~CETChannelMessageSystemGetObjectList()
{
  //## begin CETChannelMessageSystemGetObjectList::~CETChannelMessageSystemGetObjectList%.body preserve=yes
    if (m_pObjList)
        delete m_pObjList;
    m_pObjList = NULL;
  //## end CETChannelMessageSystemGetObjectList::~CETChannelMessageSystemGetObjectList%.body
}



//## Other Operations (implementation)
void CETChannelMessageSystemGetObjectList::Serialize (BYTE*& p_byStream, INT& p_iStreamLength)
{
  //## begin CETChannelMessageSystemGetObjectList::Serialize%1063715463.body preserve=yes
    // serialize base class
    BYTE* l_pbyBaseStream;
    INT   l_iBaseStreamSize;
    CETChannelMessage::Serialize(l_pbyBaseStream, l_iBaseStreamSize);

    p_iStreamLength = m_uiTelegramSize;
    p_byStream = new BYTE[p_iStreamLength];
    
    // copy base data
    memcpy(p_byStream, l_pbyBaseStream, l_iBaseStreamSize);

    // throw away the buffer supplied by the base
    delete [] l_pbyBaseStream;

    // add number of objects
    *((INT*)(p_byStream+m_uiBaseMessageSize)) = m_pObjList->GetSize();

    // serialize all objects
    for (int l_iCnt=0; l_iCnt<m_pObjList->GetSize(); l_iCnt++)
    {
        // 128 Bytes per state
        memcpy((INT*)(p_byStream+m_uiBaseMessageSize+sizeof(INT)+l_iCnt*128), (LPCTSTR)m_pObjList->GetAt(l_iCnt), 128);
    }
  //## end CETChannelMessageSystemGetObjectList::Serialize%1063715463.body
}

//## Get and Set Operations for Associations (implementation)

void CETChannelMessageSystemGetObjectList::SetpObjList (CStringArray * value)
{
  //## begin CETChannelMessageSystemGetObjectList::SetpObjList%3F672744025F.set preserve=yes
    m_pObjList = value;
    ASSERT(m_pObjList != NULL);

    // compute message size
    m_uiTelegramSize = m_uiBaseMessageSize + sizeof(UINT) + m_pObjList->GetSize()*128;
  //## end CETChannelMessageSystemGetObjectList::SetpObjList%3F672744025F.set
}

// Additional Declarations
  //## begin CETChannelMessageSystemGetObjectList%3F6726EE0106.declarations preserve=yes
  //## end CETChannelMessageSystemGetObjectList%3F6726EE0106.declarations

// Class CETChannelMessageSystemSetTime 


//## begin CETChannelMessageSystemSetTime::uiMessageSize%3F71E8370261.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
UINT CETChannelMessageSystemSetTime::m_uiMessageSize = m_uiBaseMessageSize+6*sizeof(DWORD);
//## end CETChannelMessageSystemSetTime::uiMessageSize%3F71E8370261.role

CETChannelMessageSystemSetTime::CETChannelMessageSystemSetTime (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageSystemSetTime::CETChannelMessageSystemSetTime%1064429412.hasinit preserve=no
  //## end CETChannelMessageSystemSetTime::CETChannelMessageSystemSetTime%1064429412.hasinit
  //## begin CETChannelMessageSystemSetTime::CETChannelMessageSystemSetTime%1064429412.initialization preserve=yes
  : CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageSystemSetTime::CETChannelMessageSystemSetTime%1064429412.initialization
{
  //## begin CETChannelMessageSystemSetTime::CETChannelMessageSystemSetTime%1064429412.body preserve=yes
    ASSERT(p_iStreamLength == (int)m_uiMessageSize);

	memset(&m_SystemTime, 0, sizeof(SYSTEMTIME));
	m_SystemTime.wYear		= (WORD)*((DWORD*)(p_byStream+m_uiBaseMessageSize));
	m_SystemTime.wMonth		= (WORD)*((DWORD*)(p_byStream+m_uiBaseMessageSize+4));
	m_SystemTime.wDay		= (WORD)*((DWORD*)(p_byStream+m_uiBaseMessageSize+8));
	m_SystemTime.wHour		= (WORD)*((DWORD*)(p_byStream+m_uiBaseMessageSize+12));
	m_SystemTime.wMinute	= (WORD)*((DWORD*)(p_byStream+m_uiBaseMessageSize+16));
	m_SystemTime.wSecond	= (WORD)*((DWORD*)(p_byStream+m_uiBaseMessageSize+20));
  //## end CETChannelMessageSystemSetTime::CETChannelMessageSystemSetTime%1064429412.body
}


CETChannelMessageSystemSetTime::~CETChannelMessageSystemSetTime()
{
  //## begin CETChannelMessageSystemSetTime::~CETChannelMessageSystemSetTime%.body preserve=yes
  //## end CETChannelMessageSystemSetTime::~CETChannelMessageSystemSetTime%.body
}


//## Get and Set Operations for Associations (implementation)

SYSTEMTIME CETChannelMessageSystemSetTime::GetSystemTime ()
{
  //## begin CETChannelMessageSystemSetTime::GetSystemTime%3F71E746028E.get preserve=no
  return m_SystemTime;
  //## end CETChannelMessageSystemSetTime::GetSystemTime%3F71E746028E.get
}

// Additional Declarations
  //## begin CETChannelMessageSystemSetTime%3F71E6DD030E.declarations preserve=yes
  //## end CETChannelMessageSystemSetTime%3F71E6DD030E.declarations

// Class CETChannelMessagePersistentConfig 


//## begin CETChannelMessagePersistentConfig::uiMessageSize%4005542302B4.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
UINT CETChannelMessagePersistentConfig::m_uiMessageSize = m_uiBaseMessageSize+3*4;
//## end CETChannelMessagePersistentConfig::uiMessageSize%4005542302B4.role

CETChannelMessagePersistentConfig::CETChannelMessagePersistentConfig (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessagePersistentConfig::CETChannelMessagePersistentConfig%1074090279.hasinit preserve=no
      : m_pConfig(NULL)
  //## end CETChannelMessagePersistentConfig::CETChannelMessagePersistentConfig%1074090279.hasinit
  //## begin CETChannelMessagePersistentConfig::CETChannelMessagePersistentConfig%1074090279.initialization preserve=yes
  , CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessagePersistentConfig::CETChannelMessagePersistentConfig%1074090279.initialization
{
  //## begin CETChannelMessagePersistentConfig::CETChannelMessagePersistentConfig%1074090279.body preserve=yes
    ASSERT(p_iStreamLength == (int)m_uiMessageSize);
    m_pConfig = new CPIPersistentConfig(*((DWORD*)(p_byStream+m_uiBaseMessageSize+0)),
                                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+4)),
                                        *((DWORD*)(p_byStream+m_uiBaseMessageSize+8)));
  //## end CETChannelMessagePersistentConfig::CETChannelMessagePersistentConfig%1074090279.body
}


CETChannelMessagePersistentConfig::~CETChannelMessagePersistentConfig()
{
  //## begin CETChannelMessagePersistentConfig::~CETChannelMessagePersistentConfig%.body preserve=yes
    if (m_pConfig)
        m_pConfig->ReleaseRef();
    m_pConfig = NULL;
  //## end CETChannelMessagePersistentConfig::~CETChannelMessagePersistentConfig%.body
}


//## Get and Set Operations for Associations (implementation)

CPIPersistentConfig * CETChannelMessagePersistentConfig::GetpConfig ()
{
  //## begin CETChannelMessagePersistentConfig::GetpConfig%40054A150370.get preserve=no
  return m_pConfig;
  //## end CETChannelMessagePersistentConfig::GetpConfig%40054A150370.get
}

// Additional Declarations
  //## begin CETChannelMessagePersistentConfig%40054737017B.declarations preserve=yes
  //## end CETChannelMessagePersistentConfig%40054737017B.declarations

// Class CETChannelMessageI2CAdcMax1037 


//## begin CETChannelMessageI2CAdcMax1037::uiMessageSize%401128BB0329.role preserve=no  public: static UINT32 {1..1 -> 1..1VFHN}
UINT32 CETChannelMessageI2CAdcMax1037::m_uiMessageSize = m_uiBaseMessageSize+4*4;
//## end CETChannelMessageI2CAdcMax1037::uiMessageSize%401128BB0329.role

CETChannelMessageI2CAdcMax1037::CETChannelMessageI2CAdcMax1037 (CETChannelMessage* p_pStdMessage)
  //## begin CETChannelMessageI2CAdcMax1037::CETChannelMessageI2CAdcMax1037%1074861342.hasinit preserve=no
      : m_pDataAdc(NULL)
  //## end CETChannelMessageI2CAdcMax1037::CETChannelMessageI2CAdcMax1037%1074861342.hasinit
  //## begin CETChannelMessageI2CAdcMax1037::CETChannelMessageI2CAdcMax1037%1074861342.initialization preserve=yes
  , CETChannelMessage(p_pStdMessage->GetuiID(), p_pStdMessage->GeteCommand(), p_pStdMessage->GeteExpectedReturn(), p_pStdMessage->GetiData(), p_pStdMessage->GetuiObjRefID(), m_uiMessageSize)
  //## end CETChannelMessageI2CAdcMax1037::CETChannelMessageI2CAdcMax1037%1074861342.initialization
{
  //## begin CETChannelMessageI2CAdcMax1037::CETChannelMessageI2CAdcMax1037%1074861342.body preserve=yes
    delete p_pStdMessage;
  //## end CETChannelMessageI2CAdcMax1037::CETChannelMessageI2CAdcMax1037%1074861342.body
}


CETChannelMessageI2CAdcMax1037::~CETChannelMessageI2CAdcMax1037()
{
  //## begin CETChannelMessageI2CAdcMax1037::~CETChannelMessageI2CAdcMax1037%.body preserve=yes
    if (m_pDataAdc)
    {
        m_pDataAdc->ReleaseRef();
        m_pDataAdc = NULL;
    }

  //## end CETChannelMessageI2CAdcMax1037::~CETChannelMessageI2CAdcMax1037%.body
}



//## Other Operations (implementation)
void CETChannelMessageI2CAdcMax1037::Serialize (BYTE*& p_byStream, INT& p_iStreamLength)
{
  //## begin CETChannelMessageI2CAdcMax1037::Serialize%1074861341.body preserve=yes
     // serialize base class
    BYTE* l_pbyBaseStream;
    INT   l_iBaseStreamSize;
    CETChannelMessage::Serialize(l_pbyBaseStream, l_iBaseStreamSize);

    // build stream
    p_iStreamLength = m_uiTelegramSize;
    p_byStream = new BYTE[p_iStreamLength];

    // copy base data
    memcpy(p_byStream, l_pbyBaseStream, l_iBaseStreamSize);

    // throw away the buffer supplied by the base
    delete [] l_pbyBaseStream;

	if (m_pDataAdc != NULL)
	{
		// copy all data
		*((UINT*)(p_byStream + l_iBaseStreamSize))      = (UINT)m_pDataAdc->GetDataAIN0();
		*((UINT*)(p_byStream + l_iBaseStreamSize + 4))  = (UINT)m_pDataAdc->GetDataAIN1();
		*((UINT*)(p_byStream + l_iBaseStreamSize + 8))  = (UINT)m_pDataAdc->GetDataAIN2();
		*((UINT*)(p_byStream + l_iBaseStreamSize + 12)) = (UINT)m_pDataAdc->GetDataAIN3();
	}
  //## end CETChannelMessageI2CAdcMax1037::Serialize%1074861341.body
}

//## Get and Set Operations for Associations (implementation)

void CETChannelMessageI2CAdcMax1037::SetpDataAdc (CPIDataADCMAX1037 * value)
{
  //## begin CETChannelMessageI2CAdcMax1037::SetpDataAdc%4011244503E4.set preserve=no
  m_pDataAdc = value;
  //## end CETChannelMessageI2CAdcMax1037::SetpDataAdc%4011244503E4.set
}

// Additional Declarations
  //## begin CETChannelMessageI2CAdcMax1037%4011233C0079.declarations preserve=yes
  //## end CETChannelMessageI2CAdcMax1037%4011233C0079.declarations

// Class CETChannelMessageString 


//## begin CETChannelMessageString::uiMessageSize%41480C7A038A.attr preserve=no  private: static UINT {U} m_uiBaseMessageSize+8
UINT CETChannelMessageString::m_uiMessageSize = m_uiBaseMessageSize+8;
//## end CETChannelMessageString::uiMessageSize%41480C7A038A.attr

CETChannelMessageString::CETChannelMessageString (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageString::CETChannelMessageString%1095233136.hasinit preserve=no
  //## end CETChannelMessageString::CETChannelMessageString%1095233136.hasinit
  //## begin CETChannelMessageString::CETChannelMessageString%1095233136.initialization preserve=yes
  : CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageString::CETChannelMessageString%1095233136.initialization
{
  //## begin CETChannelMessageString::CETChannelMessageString%1095233136.body preserve=yes
    DWORD l_dwSize = *((DWORD*)(p_byStream+m_uiBaseMessageSize+0));
    WCHAR* l_pStr = new WCHAR[l_dwSize+2];
    memset(l_pStr, 0, l_dwSize*2+2);
    memcpy(l_pStr, p_byStream+m_uiBaseMessageSize+4, l_dwSize*2);

    m_sString = l_pStr;
    delete[] l_pStr;
  //## end CETChannelMessageString::CETChannelMessageString%1095233136.body
}

CETChannelMessageString::CETChannelMessageString (CETChannelMessage* p_pStdMessage)
  //## begin CETChannelMessageString::CETChannelMessageString%1095233138.hasinit preserve=no
  //## end CETChannelMessageString::CETChannelMessageString%1095233138.hasinit
  //## begin CETChannelMessageString::CETChannelMessageString%1095233138.initialization preserve=yes
  : CETChannelMessage(p_pStdMessage->GetuiID(), p_pStdMessage->GeteCommand(), p_pStdMessage->GeteExpectedReturn(), p_pStdMessage->GetiData(), p_pStdMessage->GetuiObjRefID(), m_uiBaseMessageSize)
  //## end CETChannelMessageString::CETChannelMessageString%1095233138.initialization
{
  //## begin CETChannelMessageString::CETChannelMessageString%1095233138.body preserve=yes
  delete p_pStdMessage;
  //## end CETChannelMessageString::CETChannelMessageString%1095233138.body
}


CETChannelMessageString::~CETChannelMessageString()
{
  //## begin CETChannelMessageString::~CETChannelMessageString%.body preserve=yes
  //## end CETChannelMessageString::~CETChannelMessageString%.body
}



//## Other Operations (implementation)
void CETChannelMessageString::Serialize (BYTE*& p_byStream, INT& p_iStreamLength)
{
  //## begin CETChannelMessageString::Serialize%1095233137.body preserve=yes
    // serialize base class
    BYTE* l_pbyBaseStream;
    INT   l_iBaseStreamSize;
    CETChannelMessage::Serialize(l_pbyBaseStream, l_iBaseStreamSize);

    // build stream
    p_iStreamLength = m_uiTelegramSize;
    p_byStream = new BYTE[p_iStreamLength];
    
    // copy base data
    memcpy(p_byStream, l_pbyBaseStream, l_iBaseStreamSize);

    // throw away the buffer supplied by the base
    delete [] l_pbyBaseStream;

    *((int*)(p_byStream+l_iBaseStreamSize)) = m_sString.GetLength();
    wcscpy((wchar_t*)(p_byStream+l_iBaseStreamSize+sizeof(int)), (LPCTSTR)m_sString);

  //## end CETChannelMessageString::Serialize%1095233137.body
}

//## Get and Set Operations for Class Attributes (implementation)

CString CETChannelMessageString::GetsString ()
{
  //## begin CETChannelMessageString::GetsString%41480C7A037A.get preserve=no
  return m_sString;
  //## end CETChannelMessageString::GetsString%41480C7A037A.get
}

void CETChannelMessageString::SetsString (CString value)
{
  //## begin CETChannelMessageString::SetsString%41480C7A037A.set preserve=yes
    m_sString = value;

    m_uiTelegramSize = m_uiBaseMessageSize + sizeof(int) + m_sString.GetLength() * 2 + sizeof(int);
  //## end CETChannelMessageString::SetsString%41480C7A037A.set
}

// Additional Declarations
  //## begin CETChannelMessageString%41480C1102BF.declarations preserve=yes
  //## end CETChannelMessageString%41480C1102BF.declarations

// Class CETChannelMessageStepperHome 


//## begin CETChannelMessageStepperHome::uiMessageSize%471CFD490277.attr preserve=no  private: static UINT {U} m_uiBaseMessageSize+12
UINT CETChannelMessageStepperHome::m_uiMessageSize = m_uiBaseMessageSize+12;
//## end CETChannelMessageStepperHome::uiMessageSize%471CFD490277.attr



CETChannelMessageStepperHome::CETChannelMessageStepperHome (BYTE* p_byStream, INT p_iStreamLength)
  //## begin CETChannelMessageStepperHome::CETChannelMessageStepperHome%1193077639.hasinit preserve=no
  //## end CETChannelMessageStepperHome::CETChannelMessageStepperHome%1193077639.hasinit
  //## begin CETChannelMessageStepperHome::CETChannelMessageStepperHome%1193077639.initialization preserve=yes
  : CETChannelMessage(p_byStream, p_iStreamLength)
  //## end CETChannelMessageStepperHome::CETChannelMessageStepperHome%1193077639.initialization
{
  //## begin CETChannelMessageStepperHome::CETChannelMessageStepperHome%1193077639.body preserve=yes
    ASSERT(p_iStreamLength == (int)m_uiMessageSize);
    m_eFastFindingDirection = *((EPIMotorPolarity*)(p_byStream+m_uiBaseMessageSize));
    m_bSearchLimitFromOpposite	= *((bool*)(p_byStream+m_uiBaseMessageSize+4));
	m_iLimitID				= *((int*)(p_byStream+m_uiBaseMessageSize+8));
  //## end CETChannelMessageStepperHome::CETChannelMessageStepperHome%1193077639.body
}


CETChannelMessageStepperHome::~CETChannelMessageStepperHome()
{
  //## begin CETChannelMessageStepperHome::~CETChannelMessageStepperHome%.body preserve=yes
  //## end CETChannelMessageStepperHome::~CETChannelMessageStepperHome%.body
}


//## Get and Set Operations for Class Attributes (implementation)

INT CETChannelMessageStepperHome::GetiLimitID ()
{
  //## begin CETChannelMessageStepperHome::GetiLimitID%471CFC85024D.get preserve=no
  return m_iLimitID;
  //## end CETChannelMessageStepperHome::GetiLimitID%471CFC85024D.get
}

//## Get and Set Operations for Associations (implementation)

EPIMotorPolarity CETChannelMessageStepperHome::GeteFastFindingDirection ()
{
  //## begin CETChannelMessageStepperHome::GeteFastFindingDirection%471CFC160295.get preserve=no
  return m_eFastFindingDirection;
  //## end CETChannelMessageStepperHome::GeteFastFindingDirection%471CFC160295.get
}

bool CETChannelMessageStepperHome::GetbSearchLimitFromOpposite ()
{
  //## begin CETChannelMessageStepperHome::GetbSearchLimitFromOpposite%471CFC530223.get preserve=no
  return m_bSearchLimitFromOpposite;
  //## end CETChannelMessageStepperHome::GetbSearchLimitFromOpposite%471CFC530223.get
}

// Additional Declarations
  //## begin CETChannelMessageStepperHome%471CFB8C0213.declarations preserve=yes
  //## end CETChannelMessageStepperHome%471CFB8C0213.declarations

//## begin module%3DA2A5B3034A.epilog preserve=yes
//## end module%3DA2A5B3034A.epilog
