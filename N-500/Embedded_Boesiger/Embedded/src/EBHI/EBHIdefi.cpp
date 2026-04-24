//## begin module%3E68A3C7031C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E68A3C7031C.cm

//## begin module%3E68A3C7031C.cp preserve=no
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
//## end module%3E68A3C7031C.cp

//## Module: EBHIdefi%3E68A3C7031C; Package body
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIdefi.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E68A3C7031C.additionalIncludes preserve=no
//## end module%3E68A3C7031C.additionalIncludes

//## begin module%3E68A3C7031C.includes preserve=yes
//## end module%3E68A3C7031C.includes

// EBHIdefi
#include "EBHIdefi.h"
//## begin module%3E68A3C7031C.declarations preserve=no
//## end module%3E68A3C7031C.declarations

//## begin module%3E68A3C7031C.additionalDeclarations preserve=yes
//## end module%3E68A3C7031C.additionalDeclarations


// Class CHIMCParameter 

//## begin CHIMCParameter::dwMinTransferDataSize%3E68A30203A9.attr preserve=no  public: static DWORD {U} 
DWORD CHIMCParameter::m_dwMinTransferDataSize;
//## end CHIMCParameter::dwMinTransferDataSize%3E68A30203A9.attr

//## begin CHIMCParameter::dwMaxTransferDataSize%3E6C40D501D4.attr preserve=no  public: static DWORD {U} 
DWORD CHIMCParameter::m_dwMaxTransferDataSize;
//## end CHIMCParameter::dwMaxTransferDataSize%3E6C40D501D4.attr

//## begin CHIMCParameter::dwCycleID%3E6DF77801A5.attr preserve=no  public: static DWORD {U} 
DWORD CHIMCParameter::m_dwCycleID;
//## end CHIMCParameter::dwCycleID%3E6DF77801A5.attr

//## Get and Set Operations for Class Attributes (implementation)

DWORD CHIMCParameter::GetdwMinTransferDataSize ()
{
  //## begin CHIMCParameter::GetdwMinTransferDataSize%3E68A30203A9.get preserve=no
  return m_dwMinTransferDataSize;
  //## end CHIMCParameter::GetdwMinTransferDataSize%3E68A30203A9.get
}

void CHIMCParameter::SetdwMinTransferDataSize (DWORD value)
{
  //## begin CHIMCParameter::SetdwMinTransferDataSize%3E68A30203A9.set preserve=no
  m_dwMinTransferDataSize = value;
  //## end CHIMCParameter::SetdwMinTransferDataSize%3E68A30203A9.set
}

DWORD CHIMCParameter::GetdwMaxTransferDataSize ()
{
  //## begin CHIMCParameter::GetdwMaxTransferDataSize%3E6C40D501D4.get preserve=no
  return m_dwMaxTransferDataSize;
  //## end CHIMCParameter::GetdwMaxTransferDataSize%3E6C40D501D4.get
}

void CHIMCParameter::SetdwMaxTransferDataSize (DWORD value)
{
  //## begin CHIMCParameter::SetdwMaxTransferDataSize%3E6C40D501D4.set preserve=no
  m_dwMaxTransferDataSize = value;
  //## end CHIMCParameter::SetdwMaxTransferDataSize%3E6C40D501D4.set
}

DWORD CHIMCParameter::GetdwCycleID ()
{
  //## begin CHIMCParameter::GetdwCycleID%3E6DF77801A5.get preserve=no
  return m_dwCycleID;
  //## end CHIMCParameter::GetdwCycleID%3E6DF77801A5.get
}

void CHIMCParameter::SetdwCycleID (DWORD value)
{
  //## begin CHIMCParameter::SetdwCycleID%3E6DF77801A5.set preserve=no
  m_dwCycleID = value;
  //## end CHIMCParameter::SetdwCycleID%3E6DF77801A5.set
}

// Additional Declarations
  //## begin CHIMCParameter%3E68A38000DA.declarations preserve=yes
  //## end CHIMCParameter%3E68A38000DA.declarations

// Class CHIProcessImageParameter 

//## begin CHIProcessImageParameter::cdwMaskOffsetAdr%3EBA1117037A.attr preserve=no  public: static DWORD {UC} 0x0FFFF000
const DWORD  CHIProcessImageParameter::m_cdwMaskOffsetAdr = 0x0FFFF000;
//## end CHIProcessImageParameter::cdwMaskOffsetAdr%3EBA1117037A.attr

//## begin CHIProcessImageParameter::cdwMaskDataWidth%3EBA11580138.attr preserve=no  public: static DWORD {UC} 0x00000FC0
const DWORD  CHIProcessImageParameter::m_cdwMaskDataWidth = 0x00000FC0;
//## end CHIProcessImageParameter::cdwMaskDataWidth%3EBA11580138.attr

//## begin CHIProcessImageParameter::cdwMaskBitPosition%3EBA11580399.attr preserve=no  public: static DWORD {UC} 0x0000003F
const DWORD  CHIProcessImageParameter::m_cdwMaskBitPosition = 0x0000003F;
//## end CHIProcessImageParameter::cdwMaskBitPosition%3EBA11580399.attr

//## begin CHIProcessImageParameter::cdwMaskControlStates%3EBA11590222.attr preserve=no  public: static DWORD {UC} 0xF0000000
const DWORD  CHIProcessImageParameter::m_cdwMaskControlStates = 0xF0000000;
//## end CHIProcessImageParameter::cdwMaskControlStates%3EBA11590222.attr

//## begin CHIProcessImageParameter::cdwMaskWriteBit%3F54A1640232.attr preserve=no  public: static DWORD {UC} 0x80000000
const DWORD  CHIProcessImageParameter::m_cdwMaskWriteBit = 0x80000000;
//## end CHIProcessImageParameter::cdwMaskWriteBit%3F54A1640232.attr

//## begin CHIProcessImageParameter::cdwMaskDeleteRegister%41B08309031C.attr preserve=no  public: static DWORD {UC} 0x20000000
const DWORD  CHIProcessImageParameter::m_cdwMaskDeleteRegister = 0x20000000;
//## end CHIProcessImageParameter::cdwMaskDeleteRegister%41B08309031C.attr

//## begin CHIProcessImageParameter::cdwShiftCountsOffsetAdr%3EBA143300AB.attr preserve=no  public: static DWORD {UC} 12
const DWORD  CHIProcessImageParameter::m_cdwShiftCountsOffsetAdr = 12;
//## end CHIProcessImageParameter::cdwShiftCountsOffsetAdr%3EBA143300AB.attr

//## begin CHIProcessImageParameter::cdwShiftCountsDataWidth%3EBA1481038A.attr preserve=no  public: static DWORD {UC} 6
const DWORD  CHIProcessImageParameter::m_cdwShiftCountsDataWidth = 6;
//## end CHIProcessImageParameter::cdwShiftCountsDataWidth%3EBA1481038A.attr

//## begin CHIProcessImageParameter::cdwShiftCountsBitPosition%3EBA14840000.attr preserve=no  public: static DWORD {UC} 0
const DWORD  CHIProcessImageParameter::m_cdwShiftCountsBitPosition = 0;
//## end CHIProcessImageParameter::cdwShiftCountsBitPosition%3EBA14840000.attr

//## begin CHIProcessImageParameter::cdwShiftCountsControlStates%3EBA1486001F.attr preserve=no  public: static DWORD {UC} 28
const DWORD  CHIProcessImageParameter::m_cdwShiftCountsControlStates = 28;
//## end CHIProcessImageParameter::cdwShiftCountsControlStates%3EBA1486001F.attr

//## begin CHIProcessImageParameter::cdwMaskI2CBusNumber%3F5C6CB3002E.attr preserve=no  public: static DWORD {UC} 0x00000FC0
const DWORD  CHIProcessImageParameter::m_cdwMaskI2CBusNumber = 0x00000FC0;
//## end CHIProcessImageParameter::cdwMaskI2CBusNumber%3F5C6CB3002E.attr

//## begin CHIProcessImageParameter::cdwMaskI2CTransferSpeed%3F5C6CB3004E.attr preserve=no  public: static DWORD {UC} 0x0000003F
const DWORD  CHIProcessImageParameter::m_cdwMaskI2CTransferSpeed = 0x0000003F;
//## end CHIProcessImageParameter::cdwMaskI2CTransferSpeed%3F5C6CB3004E.attr

//## begin CHIProcessImageParameter::cdwShiftCountsI2CBusNumber%3F5C6CEC03D8.attr preserve=no  public: static DWORD {UC} 6
const DWORD  CHIProcessImageParameter::m_cdwShiftCountsI2CBusNumber = 6;
//## end CHIProcessImageParameter::cdwShiftCountsI2CBusNumber%3F5C6CEC03D8.attr

//## begin CHIProcessImageParameter::cdwShiftCountsI2CTransferSpeed%3F5C6CED0000.attr preserve=no  public: static DWORD {UC} 0
const DWORD  CHIProcessImageParameter::m_cdwShiftCountsI2CTransferSpeed = 0;
//## end CHIProcessImageParameter::cdwShiftCountsI2CTransferSpeed%3F5C6CED0000.attr

//## Get and Set Operations for Class Attributes (implementation)

const DWORD CHIProcessImageParameter::GetcdwMaskOffsetAdr ()
{
  //## begin CHIProcessImageParameter::GetcdwMaskOffsetAdr%3EBA1117037A.get preserve=no
  return m_cdwMaskOffsetAdr;
  //## end CHIProcessImageParameter::GetcdwMaskOffsetAdr%3EBA1117037A.get
}

const DWORD CHIProcessImageParameter::GetcdwMaskDataWidth ()
{
  //## begin CHIProcessImageParameter::GetcdwMaskDataWidth%3EBA11580138.get preserve=no
  return m_cdwMaskDataWidth;
  //## end CHIProcessImageParameter::GetcdwMaskDataWidth%3EBA11580138.get
}

const DWORD CHIProcessImageParameter::GetcdwMaskBitPosition ()
{
  //## begin CHIProcessImageParameter::GetcdwMaskBitPosition%3EBA11580399.get preserve=no
  return m_cdwMaskBitPosition;
  //## end CHIProcessImageParameter::GetcdwMaskBitPosition%3EBA11580399.get
}

const DWORD CHIProcessImageParameter::GetcdwMaskControlStates ()
{
  //## begin CHIProcessImageParameter::GetcdwMaskControlStates%3EBA11590222.get preserve=no
  return m_cdwMaskControlStates;
  //## end CHIProcessImageParameter::GetcdwMaskControlStates%3EBA11590222.get
}

const DWORD CHIProcessImageParameter::GetcdwMaskWriteBit ()
{
  //## begin CHIProcessImageParameter::GetcdwMaskWriteBit%3F54A1640232.get preserve=no
  return m_cdwMaskWriteBit;
  //## end CHIProcessImageParameter::GetcdwMaskWriteBit%3F54A1640232.get
}

const DWORD CHIProcessImageParameter::GetcdwMaskDeleteRegister ()
{
  //## begin CHIProcessImageParameter::GetcdwMaskDeleteRegister%41B08309031C.get preserve=no
  return m_cdwMaskDeleteRegister;
  //## end CHIProcessImageParameter::GetcdwMaskDeleteRegister%41B08309031C.get
}

const DWORD CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr ()
{
  //## begin CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr%3EBA143300AB.get preserve=no
  return m_cdwShiftCountsOffsetAdr;
  //## end CHIProcessImageParameter::GetcdwShiftCountsOffsetAdr%3EBA143300AB.get
}

const DWORD CHIProcessImageParameter::GetcdwShiftCountsDataWidth ()
{
  //## begin CHIProcessImageParameter::GetcdwShiftCountsDataWidth%3EBA1481038A.get preserve=no
  return m_cdwShiftCountsDataWidth;
  //## end CHIProcessImageParameter::GetcdwShiftCountsDataWidth%3EBA1481038A.get
}

const DWORD CHIProcessImageParameter::GetcdwShiftCountsBitPosition ()
{
  //## begin CHIProcessImageParameter::GetcdwShiftCountsBitPosition%3EBA14840000.get preserve=no
  return m_cdwShiftCountsBitPosition;
  //## end CHIProcessImageParameter::GetcdwShiftCountsBitPosition%3EBA14840000.get
}

const DWORD CHIProcessImageParameter::GetcdwShiftCountsControlStates ()
{
  //## begin CHIProcessImageParameter::GetcdwShiftCountsControlStates%3EBA1486001F.get preserve=no
  return m_cdwShiftCountsControlStates;
  //## end CHIProcessImageParameter::GetcdwShiftCountsControlStates%3EBA1486001F.get
}

const DWORD CHIProcessImageParameter::GetcdwMaskI2CBusNumber ()
{
  //## begin CHIProcessImageParameter::GetcdwMaskI2CBusNumber%3F5C6CB3002E.get preserve=no
  return m_cdwMaskI2CBusNumber;
  //## end CHIProcessImageParameter::GetcdwMaskI2CBusNumber%3F5C6CB3002E.get
}

const DWORD CHIProcessImageParameter::GetcdwMaskI2CTransferSpeed ()
{
  //## begin CHIProcessImageParameter::GetcdwMaskI2CTransferSpeed%3F5C6CB3004E.get preserve=no
  return m_cdwMaskI2CTransferSpeed;
  //## end CHIProcessImageParameter::GetcdwMaskI2CTransferSpeed%3F5C6CB3004E.get
}

const DWORD CHIProcessImageParameter::GetcdwShiftCountsI2CBusNumber ()
{
  //## begin CHIProcessImageParameter::GetcdwShiftCountsI2CBusNumber%3F5C6CEC03D8.get preserve=no
  return m_cdwShiftCountsI2CBusNumber;
  //## end CHIProcessImageParameter::GetcdwShiftCountsI2CBusNumber%3F5C6CEC03D8.get
}

const DWORD CHIProcessImageParameter::GetcdwShiftCountsI2CTransferSpeed ()
{
  //## begin CHIProcessImageParameter::GetcdwShiftCountsI2CTransferSpeed%3F5C6CED0000.get preserve=no
  return m_cdwShiftCountsI2CTransferSpeed;
  //## end CHIProcessImageParameter::GetcdwShiftCountsI2CTransferSpeed%3F5C6CED0000.get
}

// Additional Declarations
  //## begin CHIProcessImageParameter%3EBA10D00128.declarations preserve=yes
  //## end CHIProcessImageParameter%3EBA10D00128.declarations

// Class CHII2CParameter 

//## begin CHII2CParameter::cdwI2CEventID%3FD9C4F5035B.attr preserve=no  public: static DWORD {UC} 5000
const DWORD  CHII2CParameter::m_cdwI2CEventID = 5000;
//## end CHII2CParameter::cdwI2CEventID%3FD9C4F5035B.attr

//## begin CHII2CParameter::cdwI2CLogID%3FD9D0720213.attr preserve=no  public: static DWORD {UC} 0x00140040
const DWORD  CHII2CParameter::m_cdwI2CLogID = 0x00140040;
//## end CHII2CParameter::cdwI2CLogID%3FD9D0720213.attr

//## begin CHII2CParameter::cdwI2CMaxDataSize%3FD9D93702EE.attr preserve=no  public: static DWORD {UC} 256
const DWORD  CHII2CParameter::m_cdwI2CMaxDataSize = 256;
//## end CHII2CParameter::cdwI2CMaxDataSize%3FD9D93702EE.attr

//## begin CHII2CParameter::cdwI2CValidID%3FD9DBEF0000.attr preserve=no  public: static DWORD {UC} 5001
const DWORD  CHII2CParameter::m_cdwI2CValidID = 5001;
//## end CHII2CParameter::cdwI2CValidID%3FD9DBEF0000.attr

//## begin CHII2CParameter::cdwI2CBusNumberID%3FFD5DE101D4.attr preserve=no  public: static DWORD {UC} 5007
const DWORD  CHII2CParameter::m_cdwI2CBusNumberID = 5007;
//## end CHII2CParameter::cdwI2CBusNumberID%3FFD5DE101D4.attr

//## begin CHII2CParameter::cdwI2CTransferSpeedID%3FFD5DE200AB.attr preserve=no  public: static DWORD {UC} 5008
const DWORD  CHII2CParameter::m_cdwI2CTransferSpeedID = 5008;
//## end CHII2CParameter::cdwI2CTransferSpeedID%3FFD5DE200AB.attr

//## Get and Set Operations for Class Attributes (implementation)

const DWORD CHII2CParameter::GetcdwI2CEventID ()
{
  //## begin CHII2CParameter::GetcdwI2CEventID%3FD9C4F5035B.get preserve=no
  return m_cdwI2CEventID;
  //## end CHII2CParameter::GetcdwI2CEventID%3FD9C4F5035B.get
}

const DWORD CHII2CParameter::GetcdwI2CLogID ()
{
  //## begin CHII2CParameter::GetcdwI2CLogID%3FD9D0720213.get preserve=no
  return m_cdwI2CLogID;
  //## end CHII2CParameter::GetcdwI2CLogID%3FD9D0720213.get
}

const DWORD CHII2CParameter::GetcdwI2CMaxDataSize ()
{
  //## begin CHII2CParameter::GetcdwI2CMaxDataSize%3FD9D93702EE.get preserve=no
  return m_cdwI2CMaxDataSize;
  //## end CHII2CParameter::GetcdwI2CMaxDataSize%3FD9D93702EE.get
}

const DWORD CHII2CParameter::GetcdwI2CValidID ()
{
  //## begin CHII2CParameter::GetcdwI2CValidID%3FD9DBEF0000.get preserve=no
  return m_cdwI2CValidID;
  //## end CHII2CParameter::GetcdwI2CValidID%3FD9DBEF0000.get
}

const DWORD CHII2CParameter::GetcdwI2CBusNumberID ()
{
  //## begin CHII2CParameter::GetcdwI2CBusNumberID%3FFD5DE101D4.get preserve=no
  return m_cdwI2CBusNumberID;
  //## end CHII2CParameter::GetcdwI2CBusNumberID%3FFD5DE101D4.get
}

const DWORD CHII2CParameter::GetcdwI2CTransferSpeedID ()
{
  //## begin CHII2CParameter::GetcdwI2CTransferSpeedID%3FFD5DE200AB.get preserve=no
  return m_cdwI2CTransferSpeedID;
  //## end CHII2CParameter::GetcdwI2CTransferSpeedID%3FFD5DE200AB.get
}

// Additional Declarations
  //## begin CHII2CParameter%3FD9C47E033C.declarations preserve=yes
  //## end CHII2CParameter%3FD9C47E033C.declarations

//## begin module%3E68A3C7031C.epilog preserve=yes
//## end module%3E68A3C7031C.epilog
