//## begin module%3E42648802CE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E42648802CE.cm

//## begin module%3E42648802CE.cp preserve=no
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
//## end module%3E42648802CE.cp

//## Module: EBHITtype%3E42648802CE; Package body
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Source file: R:\Embedded\src\EBHIT\EBHITtype.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E42648802CE.additionalIncludes preserve=no
//## end module%3E42648802CE.additionalIncludes

//## begin module%3E42648802CE.includes preserve=yes
//## end module%3E42648802CE.includes

// EBHITtype
#include "EBHITtype.h"


//## begin module%3E42648802CE.declarations preserve=no
//## end module%3E42648802CE.declarations

//## begin module%3E42648802CE.additionalDeclarations preserve=yes
//## end module%3E42648802CE.additionalDeclarations


// Class CHIIOCWriteDWord 



CHIIOCWriteDWord::CHIIOCWriteDWord (DWORD p_dwAddress, DWORD p_dwValue)
  //## begin CHIIOCWriteDWord::CHIIOCWriteDWord%1042699232.hasinit preserve=no
      : m_dwAddress(p_dwAddress), m_dwValue(p_dwValue)
  //## end CHIIOCWriteDWord::CHIIOCWriteDWord%1042699232.hasinit
  //## begin CHIIOCWriteDWord::CHIIOCWriteDWord%1042699232.initialization preserve=yes
  //## end CHIIOCWriteDWord::CHIIOCWriteDWord%1042699232.initialization
{
  //## begin CHIIOCWriteDWord::CHIIOCWriteDWord%1042699232.body preserve=yes
  //## end CHIIOCWriteDWord::CHIIOCWriteDWord%1042699232.body
}


//## Get and Set Operations for Associations (implementation)

const DWORD CHIIOCWriteDWord::GetdwAddress () const
{
  //## begin CHIIOCWriteDWord::GetdwAddress%3E26CCE90251.get preserve=no
  return m_dwAddress;
  //## end CHIIOCWriteDWord::GetdwAddress%3E26CCE90251.get
}

const DWORD CHIIOCWriteDWord::GetdwValue () const
{
  //## begin CHIIOCWriteDWord::GetdwValue%3E26CE750156.get preserve=no
  return m_dwValue;
  //## end CHIIOCWriteDWord::GetdwValue%3E26CE750156.get
}

// Additional Declarations
  //## begin CHIIOCWriteDWord%3E26CCC202CD.declarations preserve=yes
  //## end CHIIOCWriteDWord%3E26CCC202CD.declarations

// Class CHIIOCSetRSMAddress 



CHIIOCSetRSMAddress::CHIIOCSetRSMAddress (LPVOID p_pRSMStreamBuffer, LPVOID p_pRSMProcessImage)
  //## begin CHIIOCSetRSMAddress::CHIIOCSetRSMAddress%1043067484.hasinit preserve=no
      : m_pRSMProcessImage(p_pRSMProcessImage), m_pRSMStreamBuffer(p_pRSMStreamBuffer)
  //## end CHIIOCSetRSMAddress::CHIIOCSetRSMAddress%1043067484.hasinit
  //## begin CHIIOCSetRSMAddress::CHIIOCSetRSMAddress%1043067484.initialization preserve=yes
  //## end CHIIOCSetRSMAddress::CHIIOCSetRSMAddress%1043067484.initialization
{
  //## begin CHIIOCSetRSMAddress::CHIIOCSetRSMAddress%1043067484.body preserve=yes
  //## end CHIIOCSetRSMAddress::CHIIOCSetRSMAddress%1043067484.body
}


//## Get and Set Operations for Associations (implementation)

const LPVOID CHIIOCSetRSMAddress::GetpRSMProcessImage () const
{
  //## begin CHIIOCSetRSMAddress::GetpRSMProcessImage%3E54807202FE.get preserve=no
  return m_pRSMProcessImage;
  //## end CHIIOCSetRSMAddress::GetpRSMProcessImage%3E54807202FE.get
}

const LPVOID CHIIOCSetRSMAddress::GetpRSMStreamBuffer () const
{
  //## begin CHIIOCSetRSMAddress::GetpRSMStreamBuffer%3E2C219E00BA.get preserve=no
  return m_pRSMStreamBuffer;
  //## end CHIIOCSetRSMAddress::GetpRSMStreamBuffer%3E2C219E00BA.get
}

void CHIIOCSetRSMAddress::SetpRSMStreamBuffer (LPVOID value)
{
  //## begin CHIIOCSetRSMAddress::SetpRSMStreamBuffer%3E2C219E00BA.set preserve=no
  m_pRSMStreamBuffer = value;
  //## end CHIIOCSetRSMAddress::SetpRSMStreamBuffer%3E2C219E00BA.set
}

// Additional Declarations
  //## begin CHIIOCSetRSMAddress%3E2C215E01B3.declarations preserve=yes
  //## end CHIIOCSetRSMAddress%3E2C215E01B3.declarations

// Class CHITDefinitions 

//## begin CHITDefinitions::cMemorySize%3FABB366000F.attr preserve=no  private: static char[256] {U} 
char CHITDefinitions::m_cMemorySize[256];
//## end CHITDefinitions::cMemorySize%3FABB366000F.attr

//## begin CHITDefinitions::cdwPCIFrequenz%3E30F1D000C6.attr preserve=no  public: static DWORD {UC} 33334919
const DWORD  CHITDefinitions::m_cdwPCIFrequenz = 33334919;
//## end CHITDefinitions::cdwPCIFrequenz%3E30F1D000C6.attr

//## begin CHITDefinitions::cdwDataSampleDivider%3E3100F7009A.attr preserve=no  public: static DWORD {UC} 64
const DWORD  CHITDefinitions::m_cdwDataSampleDivider = 64;
//## end CHITDefinitions::cdwDataSampleDivider%3E3100F7009A.attr

//## begin CHITDefinitions::cdwOverSampleDivider%3E3100E800F7.attr preserve=no  public: static DWORD {UC} 6
const DWORD  CHITDefinitions::m_cdwOverSampleDivider = 6;
//## end CHITDefinitions::cdwOverSampleDivider%3E3100E800F7.attr

//## begin CHITDefinitions::cdwDataStackDivider%3E310100001D.attr preserve=no  public: static DWORD {UC} DATA_STACK_DIVIDER
const DWORD  CHITDefinitions::m_cdwDataStackDivider = DATA_STACK_DIVIDER;
//## end CHITDefinitions::cdwDataStackDivider%3E310100001D.attr

//## begin CHITDefinitions::cdLaserZeroCrossDistance%3E54B13F00AB.attr preserve=no  public: static double {UC} 0.0000121
const double  CHITDefinitions::m_cdLaserZeroCrossDistance = 0.0000121;
//## end CHITDefinitions::cdLaserZeroCrossDistance%3E54B13F00AB.attr

//## begin CHITDefinitions::dwIsrSampleTime%3E5227940290.attr preserve=no  public: static DWORD {U} 
DWORD CHITDefinitions::m_dwIsrSampleTime;
//## end CHITDefinitions::dwIsrSampleTime%3E5227940290.attr



CHITDefinitions::CHITDefinitions()
  //## begin CHITDefinitions::CHITDefinitions%.hasinit preserve=no
  //## end CHITDefinitions::CHITDefinitions%.hasinit
  //## begin CHITDefinitions::CHITDefinitions%.initialization preserve=yes
  //## end CHITDefinitions::CHITDefinitions%.initialization
{
  //## begin CHITDefinitions::CHITDefinitions%.body preserve=yes
  DWORD l_dwTmpResult = m_cdwPCIFrequenz / m_cdwOverSampleDivider / m_cdwDataSampleDivider / m_cdwDataStackDivider;
  // ISR sample time in [ns]
  m_dwIsrSampleTime = 1000000000 / l_dwTmpResult;
  //## end CHITDefinitions::CHITDefinitions%.body
}


CHITDefinitions::~CHITDefinitions()
{
  //## begin CHITDefinitions::~CHITDefinitions%.body preserve=yes
  //## end CHITDefinitions::~CHITDefinitions%.body
}


void * CHITDefinitions::operator new(size_t size)
{
  //## begin CHITDefinitions::operatornew%.body preserve=yes
  if (size > sizeof(m_cMemorySize))
  {
    return NULL;
  }
  else
  {
    return (void*)m_cMemorySize;
  }
  //## end CHITDefinitions::operatornew%.body
}

void CHITDefinitions::operator delete(void *object)
{
  //## begin CHITDefinitions::operatordelete%.body preserve=yes
  //## end CHITDefinitions::operatordelete%.body
}


//## Get and Set Operations for Class Attributes (implementation)

const DWORD CHITDefinitions::GetcdwPCIFrequenz ()
{
  //## begin CHITDefinitions::GetcdwPCIFrequenz%3E30F1D000C6.get preserve=no
  return m_cdwPCIFrequenz;
  //## end CHITDefinitions::GetcdwPCIFrequenz%3E30F1D000C6.get
}

const DWORD CHITDefinitions::GetcdwDataSampleDivider ()
{
  //## begin CHITDefinitions::GetcdwDataSampleDivider%3E3100F7009A.get preserve=no
  return m_cdwDataSampleDivider;
  //## end CHITDefinitions::GetcdwDataSampleDivider%3E3100F7009A.get
}

const DWORD CHITDefinitions::GetcdwOverSampleDivider ()
{
  //## begin CHITDefinitions::GetcdwOverSampleDivider%3E3100E800F7.get preserve=no
  return m_cdwOverSampleDivider;
  //## end CHITDefinitions::GetcdwOverSampleDivider%3E3100E800F7.get
}

const DWORD CHITDefinitions::GetcdwDataStackDivider ()
{
  //## begin CHITDefinitions::GetcdwDataStackDivider%3E310100001D.get preserve=no
  return m_cdwDataStackDivider;
  //## end CHITDefinitions::GetcdwDataStackDivider%3E310100001D.get
}

const double CHITDefinitions::GetcdLaserZeroCrossDistance ()
{
  //## begin CHITDefinitions::GetcdLaserZeroCrossDistance%3E54B13F00AB.get preserve=no
  return m_cdLaserZeroCrossDistance;
  //## end CHITDefinitions::GetcdLaserZeroCrossDistance%3E54B13F00AB.get
}

const DWORD CHITDefinitions::GetdwIsrSampleTime ()
{
  //## begin CHITDefinitions::GetdwIsrSampleTime%3E5227940290.get preserve=no
  return m_dwIsrSampleTime;
  //## end CHITDefinitions::GetdwIsrSampleTime%3E5227940290.get
}

// Additional Declarations
  //## begin CHITDefinitions%3E4BB85401C5.declarations preserve=yes
  //## end CHITDefinitions%3E4BB85401C5.declarations

// Class CHIIOCPCISettings 

//## begin CHIIOCPCISettings::clpAdrPCIMasterTransferMemory%3EAD1F7F00DA.attr preserve=no  public: static LPVOID {UC} (LPVOID)0x81420000
const LPVOID  CHIIOCPCISettings::m_clpAdrPCIMasterTransferMemory = (LPVOID)0x81420000;
//## end CHIIOCPCISettings::clpAdrPCIMasterTransferMemory%3EAD1F7F00DA.attr

//## begin CHIIOCPCISettings::cMemorySize%3F1D2C4401F4.attr preserve=no  private: static char[256] {U} 
char CHIIOCPCISettings::m_cMemorySize[256];
//## end CHIIOCPCISettings::cMemorySize%3F1D2C4401F4.attr

//## begin CHIIOCPCISettings::cdwAdrOffsetFpgaArtNr%402762C10109.attr preserve=no  public: static DWORD {UC} 0x0
const DWORD  CHIIOCPCISettings::m_cdwAdrOffsetFpgaArtNr = 0x0;
//## end CHIIOCPCISettings::cdwAdrOffsetFpgaArtNr%402762C10109.attr

//## begin CHIIOCPCISettings::cdwAdrOffsetFpgaSwVersion%402762E703B9.attr preserve=no  public: static DWORD {UC} 0x4
const DWORD  CHIIOCPCISettings::m_cdwAdrOffsetFpgaSwVersion = 0x4;
//## end CHIIOCPCISettings::cdwAdrOffsetFpgaSwVersion%402762E703B9.attr

//## begin CHIIOCPCISettings::cdwNumberOfDWordFpgaArtNr%4027A72C02AF.attr preserve=no  public: static DWORD {UC} 0x2
const DWORD  CHIIOCPCISettings::m_cdwNumberOfDWordFpgaArtNr = 0x2;
//## end CHIIOCPCISettings::cdwNumberOfDWordFpgaArtNr%4027A72C02AF.attr

//## begin CHIIOCPCISettings::cdwNumberOfDWordFpgaSwVersion%4027A7540000.attr preserve=no  public: static DWORD {UC} 0x2
const DWORD  CHIIOCPCISettings::m_cdwNumberOfDWordFpgaSwVersion = 0x2;
//## end CHIIOCPCISettings::cdwNumberOfDWordFpgaSwVersion%4027A7540000.attr













CHIIOCPCISettings::CHIIOCPCISettings (DWORD p_dwPCIReadBaseAdr, DWORD p_dwPCIWriteBaseAdr, DWORD p_dwSysintr, DWORD p_IntMask)
  //## begin CHIIOCPCISettings::CHIIOCPCISettings%1050478287.hasinit preserve=no
      : m_dwPCIWriteBaseAdr(p_dwPCIWriteBaseAdr), m_dwSysintr(p_dwSysintr), m_IntMask(p_IntMask), m_dwWriteDataBaseOffset(0x140), m_dwReadDataTransferDWordSize(0x70), m_dwOffsetInterruptClear(0x60), m_dwOffsetIrqValue(0x60), m_dwPCIReadBaseAdr(p_dwPCIReadBaseAdr), m_dwWriteDataTransferDWordSize(0x70), m_dwReadDataBaseOffset(0x140), m_dwReadIFMDataAdrOffset(0x300), m_dwReadLaserDataAdrOffset(0x320)
  //## end CHIIOCPCISettings::CHIIOCPCISettings%1050478287.hasinit
  //## begin CHIIOCPCISettings::CHIIOCPCISettings%1050478287.initialization preserve=yes
  //## end CHIIOCPCISettings::CHIIOCPCISettings%1050478287.initialization
{
  //## begin CHIIOCPCISettings::CHIIOCPCISettings%1050478287.body preserve=yes
  //## end CHIIOCPCISettings::CHIIOCPCISettings%1050478287.body
}


void * CHIIOCPCISettings::operator new(size_t size)
{
  //## begin CHIIOCPCISettings::operatornew%.body preserve=yes
  if (size > sizeof(m_cMemorySize))
  {
    return NULL;
  }
  else
  {
    return (void*)m_cMemorySize;
  }
  //## end CHIIOCPCISettings::operatornew%.body
}

void CHIIOCPCISettings::operator delete(void *object)
{
  //## begin CHIIOCPCISettings::operatordelete%.body preserve=yes
  //## end CHIIOCPCISettings::operatordelete%.body
}



//## Other Operations (implementation)
BYTE* CHIIOCPCISettings::GetpPCIWriteBasePtr ()
{
  //## begin CHIIOCPCISettings::GetpPCIWriteBasePtr%1064568409.body preserve=yes
    return (BYTE*)(m_dwPCIWriteBaseAdr);
  //## end CHIIOCPCISettings::GetpPCIWriteBasePtr%1064568409.body
}

BYTE* CHIIOCPCISettings::GetpPCIUserWriteBasePtr ()
{
  //## begin CHIIOCPCISettings::GetpPCIUserWriteBasePtr%1064568411.body preserve=yes
    return (BYTE*)(m_dwPCIWriteBaseAdr + m_dwWriteDataBaseOffset);
  //## end CHIIOCPCISettings::GetpPCIUserWriteBasePtr%1064568411.body
}

BYTE* CHIIOCPCISettings::GetpPCIReadBasePtr ()
{
  //## begin CHIIOCPCISettings::GetpPCIReadBasePtr%1064913332.body preserve=yes
    return (BYTE*)(m_dwPCIReadBaseAdr);
  //## end CHIIOCPCISettings::GetpPCIReadBasePtr%1064913332.body
}

BYTE* CHIIOCPCISettings::GetpPCIUserReadBasePtr ()
{
  //## begin CHIIOCPCISettings::GetpPCIUserReadBasePtr%1064913333.body preserve=yes
    return (BYTE*)(m_dwPCIReadBaseAdr + m_dwReadDataBaseOffset);
  //## end CHIIOCPCISettings::GetpPCIUserReadBasePtr%1064913333.body
}

BYTE* CHIIOCPCISettings::GetpPCIReadIFMDataAdr ()
{
  //## begin CHIIOCPCISettings::GetpPCIReadIFMDataAdr%1076310548.body preserve=yes
    return (BYTE*)(m_dwPCIReadBaseAdr + m_dwReadIFMDataAdrOffset);
  //## end CHIIOCPCISettings::GetpPCIReadIFMDataAdr%1076310548.body
}

BYTE* CHIIOCPCISettings::GetpPCIReadLaserDataAdr ()
{
  //## begin CHIIOCPCISettings::GetpPCIReadLaserDataAdr%1076310549.body preserve=yes
    return (BYTE*)(m_dwPCIReadBaseAdr + m_dwReadLaserDataAdrOffset);
  //## end CHIIOCPCISettings::GetpPCIReadLaserDataAdr%1076310549.body
}

//## Get and Set Operations for Class Attributes (implementation)

const LPVOID CHIIOCPCISettings::GetclpAdrPCIMasterTransferMemory ()
{
  //## begin CHIIOCPCISettings::GetclpAdrPCIMasterTransferMemory%3EAD1F7F00DA.get preserve=no
  return m_clpAdrPCIMasterTransferMemory;
  //## end CHIIOCPCISettings::GetclpAdrPCIMasterTransferMemory%3EAD1F7F00DA.get
}

const DWORD CHIIOCPCISettings::GetcdwAdrOffsetFpgaArtNr ()
{
  //## begin CHIIOCPCISettings::GetcdwAdrOffsetFpgaArtNr%402762C10109.get preserve=no
  return m_cdwAdrOffsetFpgaArtNr;
  //## end CHIIOCPCISettings::GetcdwAdrOffsetFpgaArtNr%402762C10109.get
}

const DWORD CHIIOCPCISettings::GetcdwAdrOffsetFpgaSwVersion ()
{
  //## begin CHIIOCPCISettings::GetcdwAdrOffsetFpgaSwVersion%402762E703B9.get preserve=no
  return m_cdwAdrOffsetFpgaSwVersion;
  //## end CHIIOCPCISettings::GetcdwAdrOffsetFpgaSwVersion%402762E703B9.get
}

const DWORD CHIIOCPCISettings::GetcdwNumberOfDWordFpgaArtNr ()
{
  //## begin CHIIOCPCISettings::GetcdwNumberOfDWordFpgaArtNr%4027A72C02AF.get preserve=no
  return m_cdwNumberOfDWordFpgaArtNr;
  //## end CHIIOCPCISettings::GetcdwNumberOfDWordFpgaArtNr%4027A72C02AF.get
}

const DWORD CHIIOCPCISettings::GetcdwNumberOfDWordFpgaSwVersion ()
{
  //## begin CHIIOCPCISettings::GetcdwNumberOfDWordFpgaSwVersion%4027A7540000.get preserve=no
  return m_cdwNumberOfDWordFpgaSwVersion;
  //## end CHIIOCPCISettings::GetcdwNumberOfDWordFpgaSwVersion%4027A7540000.get
}

//## Get and Set Operations for Associations (implementation)

DWORD CHIIOCPCISettings::GetdwSysintr ()
{
  //## begin CHIIOCPCISettings::GetdwSysintr%3E9D084302B0.get preserve=no
  return m_dwSysintr;
  //## end CHIIOCPCISettings::GetdwSysintr%3E9D084302B0.get
}

void CHIIOCPCISettings::SetdwSysintr (DWORD value)
{
  //## begin CHIIOCPCISettings::SetdwSysintr%3E9D084302B0.set preserve=no
  m_dwSysintr = value;
  //## end CHIIOCPCISettings::SetdwSysintr%3E9D084302B0.set
}

DWORD CHIIOCPCISettings::GetIntMask ()
{
  //## begin CHIIOCPCISettings::GetIntMask%3E9D092A00AC.get preserve=no
  return m_IntMask;
  //## end CHIIOCPCISettings::GetIntMask%3E9D092A00AC.get
}

void CHIIOCPCISettings::SetIntMask (DWORD value)
{
  //## begin CHIIOCPCISettings::SetIntMask%3E9D092A00AC.set preserve=no
  m_IntMask = value;
  //## end CHIIOCPCISettings::SetIntMask%3E9D092A00AC.set
}

DWORD CHIIOCPCISettings::GetdwWriteDataBaseOffset ()
{
  //## begin CHIIOCPCISettings::GetdwWriteDataBaseOffset%3F74063802CF.get preserve=no
  return m_dwWriteDataBaseOffset;
  //## end CHIIOCPCISettings::GetdwWriteDataBaseOffset%3F74063802CF.get
}

DWORD CHIIOCPCISettings::GetdwReadDataTransferDWordSize ()
{
  //## begin CHIIOCPCISettings::GetdwReadDataTransferDWordSize%3F7408BA0233.get preserve=no
  return m_dwReadDataTransferDWordSize;
  //## end CHIIOCPCISettings::GetdwReadDataTransferDWordSize%3F7408BA0233.get
}

DWORD CHIIOCPCISettings::GetdwOffsetInterruptClear ()
{
  //## begin CHIIOCPCISettings::GetdwOffsetInterruptClear%3F74094C03D9.get preserve=no
  return m_dwOffsetInterruptClear;
  //## end CHIIOCPCISettings::GetdwOffsetInterruptClear%3F74094C03D9.get
}

DWORD CHIIOCPCISettings::GetdwOffsetIrqValue ()
{
  //## begin CHIIOCPCISettings::GetdwOffsetIrqValue%3F7996920178.get preserve=no
  return m_dwOffsetIrqValue;
  //## end CHIIOCPCISettings::GetdwOffsetIrqValue%3F7996920178.get
}

DWORD CHIIOCPCISettings::GetdwWriteDataTransferDWordSize ()
{
  //## begin CHIIOCPCISettings::GetdwWriteDataTransferDWordSize%3F7A8CB203BA.get preserve=no
  return m_dwWriteDataTransferDWordSize;
  //## end CHIIOCPCISettings::GetdwWriteDataTransferDWordSize%3F7A8CB203BA.get
}

DWORD CHIIOCPCISettings::GetdwReadDataBaseOffset ()
{
  //## begin CHIIOCPCISettings::GetdwReadDataBaseOffset%3F7A8D7B039A.get preserve=no
  return m_dwReadDataBaseOffset;
  //## end CHIIOCPCISettings::GetdwReadDataBaseOffset%3F7A8D7B039A.get
}

DWORD CHIIOCPCISettings::GetdwReadIFMDataAdrOffset ()
{
  //## begin CHIIOCPCISettings::GetdwReadIFMDataAdrOffset%40274B7D00FB.get preserve=no
  return m_dwReadIFMDataAdrOffset;
  //## end CHIIOCPCISettings::GetdwReadIFMDataAdrOffset%40274B7D00FB.get
}

DWORD CHIIOCPCISettings::GetdwReadLaserDataAdrOffset ()
{
  //## begin CHIIOCPCISettings::GetdwReadLaserDataAdrOffset%40274B8001F5.get preserve=no
  return m_dwReadLaserDataAdrOffset;
  //## end CHIIOCPCISettings::GetdwReadLaserDataAdrOffset%40274B8001F5.get
}

// Additional Declarations
  //## begin CHIIOCPCISettings%3E9D051D01C5.declarations preserve=yes
  //## end CHIIOCPCISettings%3E9D051D01C5.declarations

// Class CHIIOCSetWCProfile 

//## begin CHIIOCSetWCProfile::cMemorySize%3F93FD1F034B.attr preserve=no  private: static char[256] {U} 
char CHIIOCSetWCProfile::m_cMemorySize[256];
//## end CHIIOCSetWCProfile::cMemorySize%3F93FD1F034B.attr




CHIIOCSetWCProfile::CHIIOCSetWCProfile(const CHIIOCSetWCProfile &right)
  //## begin CHIIOCSetWCProfile::CHIIOCSetWCProfile%copy.hasinit preserve=no
  //## end CHIIOCSetWCProfile::CHIIOCSetWCProfile%copy.hasinit
  //## begin CHIIOCSetWCProfile::CHIIOCSetWCProfile%copy.initialization preserve=yes
  //## end CHIIOCSetWCProfile::CHIIOCSetWCProfile%copy.initialization
{
  //## begin CHIIOCSetWCProfile::CHIIOCSetWCProfile%copy.body preserve=yes
  m_dwRefDistance2 = right.m_dwRefDistance2;
  m_dwScanMode = right.m_dwScanMode;
  //## end CHIIOCSetWCProfile::CHIIOCSetWCProfile%copy.body
}

CHIIOCSetWCProfile::CHIIOCSetWCProfile (DWORD p_dwScanMode, DWORD p_dwRefDistance2)
  //## begin CHIIOCSetWCProfile::CHIIOCSetWCProfile%1066663001.hasinit preserve=no
  //## end CHIIOCSetWCProfile::CHIIOCSetWCProfile%1066663001.hasinit
  //## begin CHIIOCSetWCProfile::CHIIOCSetWCProfile%1066663001.initialization preserve=yes
  //## end CHIIOCSetWCProfile::CHIIOCSetWCProfile%1066663001.initialization
{
  //## begin CHIIOCSetWCProfile::CHIIOCSetWCProfile%1066663001.body preserve=yes
  m_dwRefDistance2 = p_dwRefDistance2;
  m_dwScanMode = p_dwScanMode;
  //## end CHIIOCSetWCProfile::CHIIOCSetWCProfile%1066663001.body
}


void * CHIIOCSetWCProfile::operator new(size_t size)
{
  //## begin CHIIOCSetWCProfile::operatornew%.body preserve=yes
  if (size > sizeof(m_cMemorySize))
  {
    return NULL;
  }
  else
  {
    return (void*)m_cMemorySize;
  }
  //## end CHIIOCSetWCProfile::operatornew%.body
}

void CHIIOCSetWCProfile::operator delete(void *object)
{
  //## begin CHIIOCSetWCProfile::operatordelete%.body preserve=yes
  //## end CHIIOCSetWCProfile::operatordelete%.body
}


const CHIIOCSetWCProfile & CHIIOCSetWCProfile::operator=(const CHIIOCSetWCProfile &right)
{
  //## begin CHIIOCSetWCProfile::operator=%.body preserve=yes
  if(this == &right)
  {
    return *this;
  }
  m_dwScanMode = right.m_dwScanMode;
  m_dwRefDistance2 = right.m_dwRefDistance2;
  return *this;
  //## end CHIIOCSetWCProfile::operator=%.body
}


//## Get and Set Operations for Class Attributes (implementation)

const DWORD CHIIOCSetWCProfile::GetdwScanMode () const
{
  //## begin CHIIOCSetWCProfile::GetdwScanMode%3FBC8F4D00CB.get preserve=no
  return m_dwScanMode;
  //## end CHIIOCSetWCProfile::GetdwScanMode%3FBC8F4D00CB.get
}

void CHIIOCSetWCProfile::SetdwScanMode (DWORD value)
{
  //## begin CHIIOCSetWCProfile::SetdwScanMode%3FBC8F4D00CB.set preserve=no
  m_dwScanMode = value;
  //## end CHIIOCSetWCProfile::SetdwScanMode%3FBC8F4D00CB.set
}

const DWORD CHIIOCSetWCProfile::GetdwRefDistance2 () const
{
  //## begin CHIIOCSetWCProfile::GetdwRefDistance2%3FD5C17401A5.get preserve=no
  return m_dwRefDistance2;
  //## end CHIIOCSetWCProfile::GetdwRefDistance2%3FD5C17401A5.get
}

void CHIIOCSetWCProfile::SetdwRefDistance2 (DWORD value)
{
  //## begin CHIIOCSetWCProfile::SetdwRefDistance2%3FD5C17401A5.set preserve=no
  m_dwRefDistance2 = value;
  //## end CHIIOCSetWCProfile::SetdwRefDistance2%3FD5C17401A5.set
}

// Additional Declarations
  //## begin CHIIOCSetWCProfile%3F93FCF600DA.declarations preserve=yes
  //## end CHIIOCSetWCProfile%3F93FCF600DA.declarations

// Class CHIIOCSetWCConfiguration 

//## begin CHIIOCSetWCConfiguration::cMemorySize%3F94C3E7031C.attr preserve=no  private: static char[256] {U} 
char CHIIOCSetWCConfiguration::m_cMemorySize[256];
//## end CHIIOCSetWCConfiguration::cMemorySize%3F94C3E7031C.attr

































CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration(const CHIIOCSetWCConfiguration &right)
  //## begin CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration%copy.hasinit preserve=no
  //## end CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration%copy.hasinit
  //## begin CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration%copy.initialization preserve=yes
  //## end CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration%copy.initialization
{
  //## begin CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration%copy.body preserve=yes
  m_dwNomVelocity = right.m_dwNomVelocity;
  m_dwNomAcc = right.m_dwNomAcc;
  m_dwIniAcc = right.m_dwIniAcc;
  m_dwAccDistance =  right.m_dwAccDistance;
  m_dwNomDec = right.m_dwNomDec;
  m_dwRestDec = right.m_dwRestDec;
  m_dwDecDistance = right.m_dwDecDistance;
  m_dwWedgeControllerVelocityEdge = right.m_dwWedgeControllerVelocityEdge;
  m_dwStaticFrictionForward = right.m_dwStaticFrictionForward;
  m_dwStaticFrictionBackward = right.m_dwStaticFrictionBackward;
  m_dwVelocityWarnHighRange = right.m_dwVelocityWarnHighRange;
  m_dwVelocityWarnLowRange = right.m_dwVelocityWarnLowRange;
  m_dwVelocityErrorHighRange = right.m_dwVelocityErrorHighRange;
  m_dwVelocityErrorLowRange = right.m_dwVelocityErrorLowRange;
  m_dwForwardStartDistance = right.m_dwForwardStartDistance;
  m_dwForwardEndDistance = right.m_dwForwardEndDistance;
  m_dwMeasuringDistance = right.m_dwMeasuringDistance;
  m_dwBackwardStartDistance = right.m_dwBackwardStartDistance;
  m_dwRefDistance1 = right.m_dwRefDistance1;
  m_dwWC_Kp = right.m_dwWC_Kp;
  m_dwWC_Ki = right.m_dwWC_Ki;
  m_dwWC_Kd = right.m_dwWC_Kd;
  m_dwWC_DACConvFactor = right.m_dwWC_DACConvFactor;
  m_dwWC_Ydac = right.m_dwWC_Ydac;
  m_dwDACLimitDown = right.m_dwDACLimitDown;
  m_dwDACLimitUp = right.m_dwDACLimitUp;
  m_dwDACLimitSlr = right.m_dwDACLimitSlr;
  m_dwRunAfterTimeTicks = right.m_dwRunAfterTimeTicks;
  m_dwAccStandBy = right.m_dwAccStandBy;
  m_dwMaxCurrentTimeTicks = right.m_dwMaxCurrentTimeTicks;
  //## end CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration%copy.body
}

CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration (DWORD p_dwNomVelocity, DWORD p_dwNomAcc, DWORD p_dwIniAcc, DWORD p_dwAccDistance, DWORD p_dwNomDec, DWORD p_dwRestDec, DWORD p_dwDecDistance, DWORD p_dwWedgeControllerVelocityEdge, DWORD p_dwStaticFrictionForward, DWORD p_dwStaticFrictionBackward, DWORD p_dwVelocityWarnHighRange, DWORD p_dwVelocityWarnLowRange, DWORD p_dwVelocityErrorHighRange, DWORD p_dwVelocityErrorLowRange, DWORD p_dwForwardStartDistance, DWORD p_dwForwardEndDistance, DWORD p_dwMeasuringDistance, DWORD p_dwBackwardStartDistance, DWORD p_dwRefDistance1, DWORD p_dwWC_Kp, DWORD p_dwWC_Ki, DWORD p_dwWC_Kd, DWORD p_dwWC_DACConvFactor, DWORD p_dwWC_Ydac, DWORD p_dwDACLimitUp, DWORD p_dwDACLimitDown, DWORD p_dwDACLimitSlr, DWORD p_dwRunAfterTimeTicks, DWORD p_dwAccStandBy, DWORD p_dwMaxCurrentTimeTicks)
  //## begin CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration%1066714379.hasinit preserve=no
  //## end CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration%1066714379.hasinit
  //## begin CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration%1066714379.initialization preserve=yes
  //## end CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration%1066714379.initialization
{
  //## begin CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration%1066714379.body preserve=yes
  m_dwNomVelocity = p_dwNomVelocity;
  m_dwNomAcc = p_dwNomAcc;
  m_dwIniAcc = p_dwIniAcc;
  m_dwAccDistance =  p_dwAccDistance;
  m_dwNomDec = p_dwNomDec;
  m_dwRestDec = p_dwRestDec;
  m_dwDecDistance = p_dwDecDistance;
  m_dwWedgeControllerVelocityEdge = p_dwWedgeControllerVelocityEdge;
  m_dwStaticFrictionForward = p_dwStaticFrictionForward;
  m_dwStaticFrictionBackward = p_dwStaticFrictionBackward;
  m_dwVelocityWarnHighRange = p_dwVelocityWarnHighRange;
  m_dwVelocityWarnLowRange = p_dwVelocityWarnLowRange;
  m_dwVelocityErrorHighRange = p_dwVelocityErrorHighRange;
  m_dwVelocityErrorLowRange = p_dwVelocityErrorLowRange;
  m_dwForwardStartDistance = p_dwForwardStartDistance;
  m_dwForwardEndDistance = p_dwForwardEndDistance;
  m_dwMeasuringDistance = p_dwMeasuringDistance;
  m_dwBackwardStartDistance = p_dwBackwardStartDistance;
  m_dwRefDistance1 = p_dwRefDistance1;
  m_dwWC_Kp = p_dwWC_Kp;
  m_dwWC_Ki = p_dwWC_Ki;
  m_dwWC_Kd = p_dwWC_Kd;
  m_dwWC_DACConvFactor = p_dwWC_DACConvFactor;
  m_dwWC_Ydac = p_dwWC_Ydac;
  m_dwDACLimitDown = p_dwDACLimitDown;
  m_dwDACLimitUp = p_dwDACLimitUp;
  m_dwDACLimitSlr = p_dwDACLimitSlr;
  m_dwRunAfterTimeTicks = p_dwRunAfterTimeTicks;
  m_dwAccStandBy = p_dwAccStandBy;
  m_dwMaxCurrentTimeTicks = p_dwMaxCurrentTimeTicks;
  //## end CHIIOCSetWCConfiguration::CHIIOCSetWCConfiguration%1066714379.body
}


void * CHIIOCSetWCConfiguration::operator new(size_t size)
{
  //## begin CHIIOCSetWCConfiguration::operatornew%.body preserve=yes
  if (size > sizeof(m_cMemorySize))
  {
    return NULL;
  }
  else
  {
    return (void*)m_cMemorySize;
  }
  //## end CHIIOCSetWCConfiguration::operatornew%.body
}

void CHIIOCSetWCConfiguration::operator delete(void *object)
{
  //## begin CHIIOCSetWCConfiguration::operatordelete%.body preserve=yes
  //## end CHIIOCSetWCConfiguration::operatordelete%.body
}


const CHIIOCSetWCConfiguration & CHIIOCSetWCConfiguration::operator=(const CHIIOCSetWCConfiguration &right)
{
  //## begin CHIIOCSetWCConfiguration::operator=%.body preserve=yes
  if(this == &right)
  {
    return *this;
  }
  m_dwNomVelocity = right.m_dwNomVelocity;
  m_dwNomAcc = right.m_dwNomAcc;
  m_dwIniAcc = right.m_dwIniAcc;
  m_dwAccDistance =  right.m_dwAccDistance;
  m_dwNomDec = right.m_dwNomDec;
  m_dwRestDec = right.m_dwRestDec;
  m_dwDecDistance = right.m_dwDecDistance;
  m_dwWedgeControllerVelocityEdge = right.m_dwWedgeControllerVelocityEdge;
  m_dwStaticFrictionForward = right.m_dwStaticFrictionForward;
  m_dwStaticFrictionBackward = right.m_dwStaticFrictionBackward;
  m_dwVelocityWarnHighRange = right.m_dwVelocityWarnHighRange;
  m_dwVelocityWarnLowRange = right.m_dwVelocityWarnLowRange;
  m_dwVelocityErrorHighRange = right.m_dwVelocityErrorHighRange;
  m_dwVelocityErrorLowRange = right.m_dwVelocityErrorLowRange;
  m_dwForwardStartDistance = right.m_dwForwardStartDistance;
  m_dwForwardEndDistance = right.m_dwForwardEndDistance;
  m_dwMeasuringDistance = right.m_dwMeasuringDistance;
  m_dwBackwardStartDistance = right.m_dwBackwardStartDistance;
  m_dwRefDistance1 = right.m_dwRefDistance1;
  m_dwWC_Kp = right.m_dwWC_Kp;
  m_dwWC_Ki = right.m_dwWC_Ki;
  m_dwWC_Kd = right.m_dwWC_Kd;
  m_dwWC_DACConvFactor = right.m_dwWC_DACConvFactor;
  m_dwWC_Ydac = right.m_dwWC_Ydac;
  m_dwDACLimitDown = right.m_dwDACLimitDown;
  m_dwDACLimitUp = right.m_dwDACLimitUp;
  m_dwDACLimitSlr = right.m_dwDACLimitSlr;
  m_dwRunAfterTimeTicks = right.m_dwRunAfterTimeTicks;
  m_dwAccStandBy = right.m_dwAccStandBy;
  m_dwMaxCurrentTimeTicks = right.m_dwMaxCurrentTimeTicks;

  return *this;
  //## end CHIIOCSetWCConfiguration::operator=%.body
}


//## Get and Set Operations for Class Attributes (implementation)

const DWORD CHIIOCSetWCConfiguration::GetdwNomVelocity () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwNomVelocity%3FD5C156000F.get preserve=no
  return m_dwNomVelocity;
  //## end CHIIOCSetWCConfiguration::GetdwNomVelocity%3FD5C156000F.get
}

const DWORD CHIIOCSetWCConfiguration::GetdwNomAcc () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwNomAcc%3FD5C15502AF.get preserve=no
  return m_dwNomAcc;
  //## end CHIIOCSetWCConfiguration::GetdwNomAcc%3FD5C15502AF.get
}

const DWORD CHIIOCSetWCConfiguration::GetdwIniAcc () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwIniAcc%3FD5C15502EE.get preserve=no
  return m_dwIniAcc;
  //## end CHIIOCSetWCConfiguration::GetdwIniAcc%3FD5C15502EE.get
}

const DWORD CHIIOCSetWCConfiguration::GetdwAccDistance () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwAccDistance%3FD5C155031C.get preserve=no
  return m_dwAccDistance;
  //## end CHIIOCSetWCConfiguration::GetdwAccDistance%3FD5C155031C.get
}

const DWORD CHIIOCSetWCConfiguration::GetdwNomDec () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwNomDec%3FD5C155035B.get preserve=no
  return m_dwNomDec;
  //## end CHIIOCSetWCConfiguration::GetdwNomDec%3FD5C155035B.get
}

const DWORD CHIIOCSetWCConfiguration::GetdwRestDec () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwRestDec%3FD5C155038A.get preserve=no
  return m_dwRestDec;
  //## end CHIIOCSetWCConfiguration::GetdwRestDec%3FD5C155038A.get
}

const DWORD CHIIOCSetWCConfiguration::GetdwDecDistance () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwDecDistance%3FD5C15503B9.get preserve=no
  return m_dwDecDistance;
  //## end CHIIOCSetWCConfiguration::GetdwDecDistance%3FD5C15503B9.get
}

const DWORD CHIIOCSetWCConfiguration::GetdwWedgeControllerVelocityEdge () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwWedgeControllerVelocityEdge%3FB49FCD032C.get preserve=no
  return m_dwWedgeControllerVelocityEdge;
  //## end CHIIOCSetWCConfiguration::GetdwWedgeControllerVelocityEdge%3FB49FCD032C.get
}

const DWORD CHIIOCSetWCConfiguration::GetdwStaticFrictionForward () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwStaticFrictionForward%402B9D26005D.get preserve=no
  return m_dwStaticFrictionForward;
  //## end CHIIOCSetWCConfiguration::GetdwStaticFrictionForward%402B9D26005D.get
}

const DWORD CHIIOCSetWCConfiguration::GetdwStaticFrictionBackward () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwStaticFrictionBackward%402B9D26008C.get preserve=no
  return m_dwStaticFrictionBackward;
  //## end CHIIOCSetWCConfiguration::GetdwStaticFrictionBackward%402B9D26008C.get
}

const DWORD CHIIOCSetWCConfiguration::GetdwVelocityWarnHighRange () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwVelocityWarnHighRange%3F94C3E7032C.get preserve=no
  return m_dwVelocityWarnHighRange;
  //## end CHIIOCSetWCConfiguration::GetdwVelocityWarnHighRange%3F94C3E7032C.get
}

void CHIIOCSetWCConfiguration::SetdwVelocityWarnHighRange (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwVelocityWarnHighRange%3F94C3E7032C.set preserve=no
  m_dwVelocityWarnHighRange = value;
  //## end CHIIOCSetWCConfiguration::SetdwVelocityWarnHighRange%3F94C3E7032C.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwVelocityWarnLowRange () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwVelocityWarnLowRange%3F94C3E7033C.get preserve=no
  return m_dwVelocityWarnLowRange;
  //## end CHIIOCSetWCConfiguration::GetdwVelocityWarnLowRange%3F94C3E7033C.get
}

void CHIIOCSetWCConfiguration::SetdwVelocityWarnLowRange (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwVelocityWarnLowRange%3F94C3E7033C.set preserve=no
  m_dwVelocityWarnLowRange = value;
  //## end CHIIOCSetWCConfiguration::SetdwVelocityWarnLowRange%3F94C3E7033C.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwVelocityErrorHighRange () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwVelocityErrorHighRange%3F94C3E7035B.get preserve=no
  return m_dwVelocityErrorHighRange;
  //## end CHIIOCSetWCConfiguration::GetdwVelocityErrorHighRange%3F94C3E7035B.get
}

void CHIIOCSetWCConfiguration::SetdwVelocityErrorHighRange (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwVelocityErrorHighRange%3F94C3E7035B.set preserve=no
  m_dwVelocityErrorHighRange = value;
  //## end CHIIOCSetWCConfiguration::SetdwVelocityErrorHighRange%3F94C3E7035B.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwVelocityErrorLowRange () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwVelocityErrorLowRange%3F94C3E7036B.get preserve=no
  return m_dwVelocityErrorLowRange;
  //## end CHIIOCSetWCConfiguration::GetdwVelocityErrorLowRange%3F94C3E7036B.get
}

void CHIIOCSetWCConfiguration::SetdwVelocityErrorLowRange (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwVelocityErrorLowRange%3F94C3E7036B.set preserve=no
  m_dwVelocityErrorLowRange = value;
  //## end CHIIOCSetWCConfiguration::SetdwVelocityErrorLowRange%3F94C3E7036B.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwForwardStartDistance () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwForwardStartDistance%3F94C3E8002E.get preserve=no
  return m_dwForwardStartDistance;
  //## end CHIIOCSetWCConfiguration::GetdwForwardStartDistance%3F94C3E8002E.get
}

void CHIIOCSetWCConfiguration::SetdwForwardStartDistance (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwForwardStartDistance%3F94C3E8002E.set preserve=no
  m_dwForwardStartDistance = value;
  //## end CHIIOCSetWCConfiguration::SetdwForwardStartDistance%3F94C3E8002E.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwForwardEndDistance () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwForwardEndDistance%3F94C3E8003E.get preserve=no
  return m_dwForwardEndDistance;
  //## end CHIIOCSetWCConfiguration::GetdwForwardEndDistance%3F94C3E8003E.get
}

void CHIIOCSetWCConfiguration::SetdwForwardEndDistance (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwForwardEndDistance%3F94C3E8003E.set preserve=no
  m_dwForwardEndDistance = value;
  //## end CHIIOCSetWCConfiguration::SetdwForwardEndDistance%3F94C3E8003E.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwMeasuringDistance () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwMeasuringDistance%3F94C3E8004E.get preserve=no
  return m_dwMeasuringDistance;
  //## end CHIIOCSetWCConfiguration::GetdwMeasuringDistance%3F94C3E8004E.get
}

void CHIIOCSetWCConfiguration::SetdwMeasuringDistance (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwMeasuringDistance%3F94C3E8004E.set preserve=no
  m_dwMeasuringDistance = value;
  //## end CHIIOCSetWCConfiguration::SetdwMeasuringDistance%3F94C3E8004E.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwBackwardStartDistance () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwBackwardStartDistance%3F94C3E8006D.get preserve=no
  return m_dwBackwardStartDistance;
  //## end CHIIOCSetWCConfiguration::GetdwBackwardStartDistance%3F94C3E8006D.get
}

void CHIIOCSetWCConfiguration::SetdwBackwardStartDistance (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwBackwardStartDistance%3F94C3E8006D.set preserve=no
  m_dwBackwardStartDistance = value;
  //## end CHIIOCSetWCConfiguration::SetdwBackwardStartDistance%3F94C3E8006D.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwRefDistance1 () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwRefDistance1%3F94C3E8007D.get preserve=no
  return m_dwRefDistance1;
  //## end CHIIOCSetWCConfiguration::GetdwRefDistance1%3F94C3E8007D.get
}

void CHIIOCSetWCConfiguration::SetdwRefDistance1 (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwRefDistance1%3F94C3E8007D.set preserve=no
  m_dwRefDistance1 = value;
  //## end CHIIOCSetWCConfiguration::SetdwRefDistance1%3F94C3E8007D.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwWC_Kp () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwWC_Kp%3F94C3E8009C.get preserve=no
  return m_dwWC_Kp;
  //## end CHIIOCSetWCConfiguration::GetdwWC_Kp%3F94C3E8009C.get
}

void CHIIOCSetWCConfiguration::SetdwWC_Kp (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwWC_Kp%3F94C3E8009C.set preserve=no
  m_dwWC_Kp = value;
  //## end CHIIOCSetWCConfiguration::SetdwWC_Kp%3F94C3E8009C.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwWC_Ki () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwWC_Ki%3F94C3E800BB.get preserve=no
  return m_dwWC_Ki;
  //## end CHIIOCSetWCConfiguration::GetdwWC_Ki%3F94C3E800BB.get
}

void CHIIOCSetWCConfiguration::SetdwWC_Ki (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwWC_Ki%3F94C3E800BB.set preserve=no
  m_dwWC_Ki = value;
  //## end CHIIOCSetWCConfiguration::SetdwWC_Ki%3F94C3E800BB.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwWC_Kd () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwWC_Kd%3F94C3E800CB.get preserve=no
  return m_dwWC_Kd;
  //## end CHIIOCSetWCConfiguration::GetdwWC_Kd%3F94C3E800CB.get
}

void CHIIOCSetWCConfiguration::SetdwWC_Kd (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwWC_Kd%3F94C3E800CB.set preserve=no
  m_dwWC_Kd = value;
  //## end CHIIOCSetWCConfiguration::SetdwWC_Kd%3F94C3E800CB.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwWC_DACConvFactor () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwWC_DACConvFactor%3F97DE13004E.get preserve=no
  return m_dwWC_DACConvFactor;
  //## end CHIIOCSetWCConfiguration::GetdwWC_DACConvFactor%3F97DE13004E.get
}

void CHIIOCSetWCConfiguration::SetdwWC_DACConvFactor (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwWC_DACConvFactor%3F97DE13004E.set preserve=no
  m_dwWC_DACConvFactor = value;
  //## end CHIIOCSetWCConfiguration::SetdwWC_DACConvFactor%3F97DE13004E.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwWC_Ydac () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwWC_Ydac%3F952D3C002E.get preserve=no
  return m_dwWC_Ydac;
  //## end CHIIOCSetWCConfiguration::GetdwWC_Ydac%3F952D3C002E.get
}

void CHIIOCSetWCConfiguration::SetdwWC_Ydac (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwWC_Ydac%3F952D3C002E.set preserve=no
  m_dwWC_Ydac = value;
  //## end CHIIOCSetWCConfiguration::SetdwWC_Ydac%3F952D3C002E.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwDACLimitUp () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwDACLimitUp%3F94C3E800DA.get preserve=no
  return m_dwDACLimitUp;
  //## end CHIIOCSetWCConfiguration::GetdwDACLimitUp%3F94C3E800DA.get
}

void CHIIOCSetWCConfiguration::SetdwDACLimitUp (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwDACLimitUp%3F94C3E800DA.set preserve=no
  m_dwDACLimitUp = value;
  //## end CHIIOCSetWCConfiguration::SetdwDACLimitUp%3F94C3E800DA.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwDACLimitDown () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwDACLimitDown%3F94C3E800EA.get preserve=no
  return m_dwDACLimitDown;
  //## end CHIIOCSetWCConfiguration::GetdwDACLimitDown%3F94C3E800EA.get
}

void CHIIOCSetWCConfiguration::SetdwDACLimitDown (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwDACLimitDown%3F94C3E800EA.set preserve=no
  m_dwDACLimitDown = value;
  //## end CHIIOCSetWCConfiguration::SetdwDACLimitDown%3F94C3E800EA.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwDACLimitSlr () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwDACLimitSlr%3F952DA60167.get preserve=no
  return m_dwDACLimitSlr;
  //## end CHIIOCSetWCConfiguration::GetdwDACLimitSlr%3F952DA60167.get
}

void CHIIOCSetWCConfiguration::SetdwDACLimitSlr (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwDACLimitSlr%3F952DA60167.set preserve=no
  m_dwDACLimitSlr = value;
  //## end CHIIOCSetWCConfiguration::SetdwDACLimitSlr%3F952DA60167.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwRunAfterTimeTicks () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwRunAfterTimeTicks%3F94C3E800FA.get preserve=no
  return m_dwRunAfterTimeTicks;
  //## end CHIIOCSetWCConfiguration::GetdwRunAfterTimeTicks%3F94C3E800FA.get
}

void CHIIOCSetWCConfiguration::SetdwRunAfterTimeTicks (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwRunAfterTimeTicks%3F94C3E800FA.set preserve=no
  m_dwRunAfterTimeTicks = value;
  //## end CHIIOCSetWCConfiguration::SetdwRunAfterTimeTicks%3F94C3E800FA.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwAccStandBy () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwAccStandBy%3F94C3E80119.get preserve=no
  return m_dwAccStandBy;
  //## end CHIIOCSetWCConfiguration::GetdwAccStandBy%3F94C3E80119.get
}

void CHIIOCSetWCConfiguration::SetdwAccStandBy (DWORD value)
{
  //## begin CHIIOCSetWCConfiguration::SetdwAccStandBy%3F94C3E80119.set preserve=no
  m_dwAccStandBy = value;
  //## end CHIIOCSetWCConfiguration::SetdwAccStandBy%3F94C3E80119.set
}

const DWORD CHIIOCSetWCConfiguration::GetdwMaxCurrentTimeTicks () const
{
  //## begin CHIIOCSetWCConfiguration::GetdwMaxCurrentTimeTicks%402B9D6D0232.get preserve=no
  return m_dwMaxCurrentTimeTicks;
  //## end CHIIOCSetWCConfiguration::GetdwMaxCurrentTimeTicks%402B9D6D0232.get
}

// Additional Declarations
  //## begin CHIIOCSetWCConfiguration%3F94C3BB01D4.declarations preserve=yes
  //## end CHIIOCSetWCConfiguration%3F94C3BB01D4.declarations

// Class CHITDACMAX5712 

//## begin CHITDACMAX5712::cdwWakeUpValue%3FABA043001F.attr preserve=no  public: static DWORD {UC} 0xF000
const DWORD  CHITDACMAX5712::m_cdwWakeUpValue = 0xF000;
//## end CHITDACMAX5712::cdwWakeUpValue%3FABA043001F.attr

//## begin CHITDACMAX5712::cdwWaitTimePwrEnable%3FABA0A30222.attr preserve=no  public: static DWORD {UC} 500000
const DWORD  CHITDACMAX5712::m_cdwWaitTimePwrEnable = 500000;
//## end CHITDACMAX5712::cdwWaitTimePwrEnable%3FABA0A30222.attr

//## begin CHITDACMAX5712::cdwWaitTimeCalibration%3FABA0F50251.attr preserve=no  public: static DWORD {UC} 1000
const DWORD  CHITDACMAX5712::m_cdwWaitTimeCalibration = 1000;
//## end CHITDACMAX5712::cdwWaitTimeCalibration%3FABA0F50251.attr

//## begin CHITDACMAX5712::cdwWaitTimeAutoCalibration%3FBCBAFE00AB.attr preserve=no  public: static DWORD {UC} 10
const DWORD  CHITDACMAX5712::m_cdwWaitTimeAutoCalibration = 10;
//## end CHITDACMAX5712::cdwWaitTimeAutoCalibration%3FBCBAFE00AB.attr

//## begin CHITDACMAX5712::cdwEmergencyStopDAC%3FABB98D0251.attr preserve=no  public: static DWORD {UC} 0x97000000
const DWORD  CHITDACMAX5712::m_cdwEmergencyStopDAC = 0x97000000;
//## end CHITDACMAX5712::cdwEmergencyStopDAC%3FABB98D0251.attr

//## begin CHITDACMAX5712::cdwDefaultOffsetValue%3FB1F2B80280.attr preserve=no  public: static DWORD {UC} 2416
const DWORD  CHITDACMAX5712::m_cdwDefaultOffsetValue = 2416;
//## end CHITDACMAX5712::cdwDefaultOffsetValue%3FB1F2B80280.attr

//## begin CHITDACMAX5712::cdwLowerLimit%3FB39C96007D.attr preserve=no  public: static DWORD {UC} 511
const DWORD  CHITDACMAX5712::m_cdwLowerLimit = 511;
//## end CHITDACMAX5712::cdwLowerLimit%3FB39C96007D.attr

//## begin CHITDACMAX5712::cdwUpperLimit%3FB39CFA036B.attr preserve=no  public: static DWORD {UC} 0xFFF
const DWORD  CHITDACMAX5712::m_cdwUpperLimit = 0xFFF;
//## end CHITDACMAX5712::cdwUpperLimit%3FB39CFA036B.attr

//## begin CHITDACMAX5712::cdwMaxOffsetCalibError%3FBDD364033C.attr preserve=no  public: static DWORD {UC} 260
const DWORD  CHITDACMAX5712::m_cdwMaxOffsetCalibError = 260;
//## end CHITDACMAX5712::cdwMaxOffsetCalibError%3FBDD364033C.attr

CHITDACMAX5712::CHITDACMAX5712 ()
  //## begin CHITDACMAX5712::CHITDACMAX5712%1068189085.hasinit preserve=no
  //## end CHITDACMAX5712::CHITDACMAX5712%1068189085.hasinit
  //## begin CHITDACMAX5712::CHITDACMAX5712%1068189085.initialization preserve=yes
  //## end CHITDACMAX5712::CHITDACMAX5712%1068189085.initialization
{
  //## begin CHITDACMAX5712::CHITDACMAX5712%1068189085.body preserve=yes
  //## end CHITDACMAX5712::CHITDACMAX5712%1068189085.body
}


//## Get and Set Operations for Class Attributes (implementation)

const DWORD CHITDACMAX5712::GetcdwWakeUpValue ()
{
  //## begin CHITDACMAX5712::GetcdwWakeUpValue%3FABA043001F.get preserve=no
  return m_cdwWakeUpValue;
  //## end CHITDACMAX5712::GetcdwWakeUpValue%3FABA043001F.get
}

const DWORD CHITDACMAX5712::GetcdwWaitTimePwrEnable ()
{
  //## begin CHITDACMAX5712::GetcdwWaitTimePwrEnable%3FABA0A30222.get preserve=no
  return m_cdwWaitTimePwrEnable;
  //## end CHITDACMAX5712::GetcdwWaitTimePwrEnable%3FABA0A30222.get
}

const DWORD CHITDACMAX5712::GetcdwWaitTimeCalibration ()
{
  //## begin CHITDACMAX5712::GetcdwWaitTimeCalibration%3FABA0F50251.get preserve=no
  return m_cdwWaitTimeCalibration;
  //## end CHITDACMAX5712::GetcdwWaitTimeCalibration%3FABA0F50251.get
}

const DWORD CHITDACMAX5712::GetcdwWaitTimeAutoCalibration ()
{
  //## begin CHITDACMAX5712::GetcdwWaitTimeAutoCalibration%3FBCBAFE00AB.get preserve=no
  return m_cdwWaitTimeAutoCalibration;
  //## end CHITDACMAX5712::GetcdwWaitTimeAutoCalibration%3FBCBAFE00AB.get
}

const DWORD CHITDACMAX5712::GetcdwEmergencyStopDAC ()
{
  //## begin CHITDACMAX5712::GetcdwEmergencyStopDAC%3FABB98D0251.get preserve=no
  return m_cdwEmergencyStopDAC;
  //## end CHITDACMAX5712::GetcdwEmergencyStopDAC%3FABB98D0251.get
}

const DWORD CHITDACMAX5712::GetcdwDefaultOffsetValue ()
{
  //## begin CHITDACMAX5712::GetcdwDefaultOffsetValue%3FB1F2B80280.get preserve=no
  return m_cdwDefaultOffsetValue;
  //## end CHITDACMAX5712::GetcdwDefaultOffsetValue%3FB1F2B80280.get
}

const DWORD CHITDACMAX5712::GetcdwLowerLimit ()
{
  //## begin CHITDACMAX5712::GetcdwLowerLimit%3FB39C96007D.get preserve=no
  return m_cdwLowerLimit;
  //## end CHITDACMAX5712::GetcdwLowerLimit%3FB39C96007D.get
}

const DWORD CHITDACMAX5712::GetcdwUpperLimit ()
{
  //## begin CHITDACMAX5712::GetcdwUpperLimit%3FB39CFA036B.get preserve=no
  return m_cdwUpperLimit;
  //## end CHITDACMAX5712::GetcdwUpperLimit%3FB39CFA036B.get
}

const DWORD CHITDACMAX5712::GetcdwMaxOffsetCalibError ()
{
  //## begin CHITDACMAX5712::GetcdwMaxOffsetCalibError%3FBDD364033C.get preserve=no
  return m_cdwMaxOffsetCalibError;
  //## end CHITDACMAX5712::GetcdwMaxOffsetCalibError%3FBDD364033C.get
}

// Additional Declarations
  //## begin CHITDACMAX5712%3FAB9F6A01B5.declarations preserve=yes
  //## end CHITDACMAX5712%3FAB9F6A01B5.declarations

// Class CHIIOCEventMasks 




// Additional Declarations
  //## begin CHIIOCEventMasks%3FC1D67501C5.declarations preserve=yes
  //## end CHIIOCEventMasks%3FC1D67501C5.declarations

// Class CHITADCMAX1281 

//## begin CHITADCMAX1281::cdADCRefVoltage%4003C42002AF.attr preserve=no  public: static double {UC} 2.5
const double  CHITADCMAX1281::m_cdADCRefVoltage = 2.5;
//## end CHITADCMAX1281::cdADCRefVoltage%4003C42002AF.attr

//## begin CHITADCMAX1281::cdwADCCurGainResistor%4003C45C0186.attr preserve=no  public: static DWORD {UC} 130000
const DWORD  CHITADCMAX1281::m_cdwADCCurGainResistor = 130000;
//## end CHITADCMAX1281::cdwADCCurGainResistor%4003C45C0186.attr

//## begin CHITADCMAX1281::cdwADCRange%4003C4D600BB.attr preserve=no  public: static DWORD {UC} 4096
const DWORD  CHITADCMAX1281::m_cdwADCRange = 4096;
//## end CHITADCMAX1281::cdwADCRange%4003C4D600BB.attr

//## begin CHITADCMAX1281::cdwADCLowerLimitDigit%4003CAC1037A.attr preserve=no  public: static DWORD {UC} 300
const DWORD  CHITADCMAX1281::m_cdwADCLowerLimitDigit = 300;
//## end CHITADCMAX1281::cdwADCLowerLimitDigit%4003CAC1037A.attr

//## begin CHITADCMAX1281::cdADCLowerLimitCur%4003CAFF001F.attr preserve=no  public: static double {UC} 0.02
const double  CHITADCMAX1281::m_cdADCLowerLimitCur = 0.02;
//## end CHITADCMAX1281::cdADCLowerLimitCur%4003CAFF001F.attr

//## begin CHITADCMAX1281::cdwShiftCountsCurLaserDet%4003F38601C5.attr preserve=no  public: static DWORD {UC} 4
const DWORD  CHITADCMAX1281::m_cdwShiftCountsCurLaserDet = 4;
//## end CHITADCMAX1281::cdwShiftCountsCurLaserDet%4003F38601C5.attr

//## begin CHITADCMAX1281::cdwBitMaskCurLaserDet%4003EA96003E.attr preserve=no  public: static DWORD {UC} 0x0000FFF0
const DWORD  CHITADCMAX1281::m_cdwBitMaskCurLaserDet = 0x0000FFF0;
//## end CHITADCMAX1281::cdwBitMaskCurLaserDet%4003EA96003E.attr

CHITADCMAX1281::CHITADCMAX1281()
  //## begin CHITADCMAX1281::CHITADCMAX1281%.hasinit preserve=no
  //## end CHITADCMAX1281::CHITADCMAX1281%.hasinit
  //## begin CHITADCMAX1281::CHITADCMAX1281%.initialization preserve=yes
  //## end CHITADCMAX1281::CHITADCMAX1281%.initialization
{
  //## begin CHITADCMAX1281::CHITADCMAX1281%.body preserve=yes
  //## end CHITADCMAX1281::CHITADCMAX1281%.body
}


//## Get and Set Operations for Class Attributes (implementation)

const double CHITADCMAX1281::GetcdADCRefVoltage ()
{
  //## begin CHITADCMAX1281::GetcdADCRefVoltage%4003C42002AF.get preserve=no
  return m_cdADCRefVoltage;
  //## end CHITADCMAX1281::GetcdADCRefVoltage%4003C42002AF.get
}

const DWORD CHITADCMAX1281::GetcdwADCCurGainResistor ()
{
  //## begin CHITADCMAX1281::GetcdwADCCurGainResistor%4003C45C0186.get preserve=no
  return m_cdwADCCurGainResistor;
  //## end CHITADCMAX1281::GetcdwADCCurGainResistor%4003C45C0186.get
}

const DWORD CHITADCMAX1281::GetcdwADCRange ()
{
  //## begin CHITADCMAX1281::GetcdwADCRange%4003C4D600BB.get preserve=no
  return m_cdwADCRange;
  //## end CHITADCMAX1281::GetcdwADCRange%4003C4D600BB.get
}

const DWORD CHITADCMAX1281::GetcdwADCLowerLimitDigit ()
{
  //## begin CHITADCMAX1281::GetcdwADCLowerLimitDigit%4003CAC1037A.get preserve=no
  return m_cdwADCLowerLimitDigit;
  //## end CHITADCMAX1281::GetcdwADCLowerLimitDigit%4003CAC1037A.get
}

const double CHITADCMAX1281::GetcdADCLowerLimitCur ()
{
  //## begin CHITADCMAX1281::GetcdADCLowerLimitCur%4003CAFF001F.get preserve=no
  return m_cdADCLowerLimitCur;
  //## end CHITADCMAX1281::GetcdADCLowerLimitCur%4003CAFF001F.get
}

const DWORD CHITADCMAX1281::GetcdwShiftCountsCurLaserDet ()
{
  //## begin CHITADCMAX1281::GetcdwShiftCountsCurLaserDet%4003F38601C5.get preserve=no
  return m_cdwShiftCountsCurLaserDet;
  //## end CHITADCMAX1281::GetcdwShiftCountsCurLaserDet%4003F38601C5.get
}

const DWORD CHITADCMAX1281::GetcdwBitMaskCurLaserDet ()
{
  //## begin CHITADCMAX1281::GetcdwBitMaskCurLaserDet%4003EA96003E.get preserve=no
  return m_cdwBitMaskCurLaserDet;
  //## end CHITADCMAX1281::GetcdwBitMaskCurLaserDet%4003EA96003E.get
}

// Additional Declarations
  //## begin CHITADCMAX1281%4003C3DC02CE.declarations preserve=yes
  //## end CHITADCMAX1281%4003C3DC02CE.declarations

//## begin module%3E42648802CE.epilog preserve=yes
//## end module%3E42648802CE.epilog
