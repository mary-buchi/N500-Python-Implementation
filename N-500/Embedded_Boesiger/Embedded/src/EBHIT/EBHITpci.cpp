//## begin module%3E8BE6960261.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E8BE6960261.cm

//## begin module%3E8BE6960261.cp preserve=no
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
//## end module%3E8BE6960261.cp

//## Module: EBHITpci%3E8BE6960261; Package body
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Source file: R:\Embedded\src\EBHIT\EBHITpci.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E8BE6960261.additionalIncludes preserve=no
//## end module%3E8BE6960261.additionalIncludes

//## begin module%3E8BE6960261.includes preserve=yes
//## end module%3E8BE6960261.includes

// EBHITpci
#include "EBHITpci.h"
//## begin module%3E8BE6960261.declarations preserve=no
//## end module%3E8BE6960261.declarations

//## begin module%3E8BE6960261.additionalDeclarations preserve=yes
//## end module%3E8BE6960261.additionalDeclarations


// Class CHITPCIAccess 

//## begin CHITPCIAccess::cdwSysStatus%3F30A21B0167.attr preserve=no  public: static DWORD {UC} 0x0
const DWORD  CHITPCIAccess::m_cdwSysStatus = 0x0;
//## end CHITPCIAccess::cdwSysStatus%3F30A21B0167.attr

//## begin CHITPCIAccess::cdwSysCmd%3F30A33B0213.attr preserve=no  public: static DWORD {UC} 0x4
const DWORD  CHITPCIAccess::m_cdwSysCmd = 0x4;
//## end CHITPCIAccess::cdwSysCmd%3F30A33B0213.attr

//## begin CHITPCIAccess::cdwSysMode%3F30A33C033C.attr preserve=no  public: static DWORD {UC} 0x8
const DWORD  CHITPCIAccess::m_cdwSysMode = 0x8;
//## end CHITPCIAccess::cdwSysMode%3F30A33C033C.attr

//## begin CHITPCIAccess::cdwSysMXmitHostAdr%3F30A33D004E.attr preserve=no  public: static DWORD {UC} 0x10
const DWORD  CHITPCIAccess::m_cdwSysMXmitHostAdr = 0x10;
//## end CHITPCIAccess::cdwSysMXmitHostAdr%3F30A33D004E.attr

//## begin CHITPCIAccess::cdwIrqClearIrq%3F30A3FE0290.attr preserve=no  public: static DWORD {UC} 0x20
const DWORD  CHITPCIAccess::m_cdwIrqClearIrq = 0x20;
//## end CHITPCIAccess::cdwIrqClearIrq%3F30A3FE0290.attr

//## begin CHITPCIAccess::cdwIrqEnableIrq%3F30A4470128.attr preserve=no  public: static DWORD {UC} 0x24
const DWORD  CHITPCIAccess::m_cdwIrqEnableIrq = 0x24;
//## end CHITPCIAccess::cdwIrqEnableIrq%3F30A4470128.attr


//## Other Operations (implementation)
bool CHITPCIAccess::ReadBlockRAM (DWORD* p_pDest, DWORD* p_pPCIAdr, DWORD p_dwSize)
{
  //## begin CHITPCIAccess::ReadBlockRAM%1049356540.body preserve=yes
  if (!(p_dwSize % 4)) // mod 4 -> DWORD alignment
  {
    __asm {
      pushfd            ; Save interrupt state
      cli
      mov ecx,p_dwSize  ; ecx = count
      mov esi,p_pPCIAdr ; esi = ->"x"
      mov edi,p_pDest   ; edi = ->"y"
      rep movsd         ; mov [esi] ==> [edi] and increment both addresses
      popfd             ; Restore interrupt state
    }
    return true;
  }

  return false;
  //## end CHITPCIAccess::ReadBlockRAM%1049356540.body
}

bool CHITPCIAccess::WriteBlockRAM (DWORD* p_pDest, DWORD* p_pPCIAdr, DWORD p_dwSize)
{
  //## begin CHITPCIAccess::WriteBlockRAM%1049356541.body preserve=yes
  if (!(p_dwSize % 4)) // mod 4 -> DWORD alignment
  {
    __asm {
      pushfd            ; Save interrupt state
      cli
      mov ecx,p_dwSize  ; ecx = count
      mov esi,p_pDest   ; esi = ->"x"
      mov edi,p_pPCIAdr ; edi = ->"y"
      rep movsd         ; mov [esi] ==> [edi] and increment both addresses
      popfd             ; Restore interrupt state
    }
    return true;
  }
  
  return false;
  //## end CHITPCIAccess::WriteBlockRAM%1049356541.body
}

//## Get and Set Operations for Class Attributes (implementation)

const DWORD CHITPCIAccess::GetcdwSysStatus ()
{
  //## begin CHITPCIAccess::GetcdwSysStatus%3F30A21B0167.get preserve=no
  return m_cdwSysStatus;
  //## end CHITPCIAccess::GetcdwSysStatus%3F30A21B0167.get
}

const DWORD CHITPCIAccess::GetcdwSysCmd ()
{
  //## begin CHITPCIAccess::GetcdwSysCmd%3F30A33B0213.get preserve=no
  return m_cdwSysCmd;
  //## end CHITPCIAccess::GetcdwSysCmd%3F30A33B0213.get
}

const DWORD CHITPCIAccess::GetcdwSysMode ()
{
  //## begin CHITPCIAccess::GetcdwSysMode%3F30A33C033C.get preserve=no
  return m_cdwSysMode;
  //## end CHITPCIAccess::GetcdwSysMode%3F30A33C033C.get
}

const DWORD CHITPCIAccess::GetcdwSysMXmitHostAdr ()
{
  //## begin CHITPCIAccess::GetcdwSysMXmitHostAdr%3F30A33D004E.get preserve=no
  return m_cdwSysMXmitHostAdr;
  //## end CHITPCIAccess::GetcdwSysMXmitHostAdr%3F30A33D004E.get
}

const DWORD CHITPCIAccess::GetcdwIrqClearIrq ()
{
  //## begin CHITPCIAccess::GetcdwIrqClearIrq%3F30A3FE0290.get preserve=no
  return m_cdwIrqClearIrq;
  //## end CHITPCIAccess::GetcdwIrqClearIrq%3F30A3FE0290.get
}

const DWORD CHITPCIAccess::GetcdwIrqEnableIrq ()
{
  //## begin CHITPCIAccess::GetcdwIrqEnableIrq%3F30A4470128.get preserve=no
  return m_cdwIrqEnableIrq;
  //## end CHITPCIAccess::GetcdwIrqEnableIrq%3F30A4470128.get
}

// Additional Declarations
  //## begin CHITPCIAccess%3E8BE636034B.declarations preserve=yes
  //## end CHITPCIAccess%3E8BE636034B.declarations

//## begin module%3E8BE6960261.epilog preserve=yes
//## end module%3E8BE6960261.epilog
