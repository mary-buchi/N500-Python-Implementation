//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// Use of this source code is subject to the terms of the Microsoft end-user
// license agreement (EULA) under which you licensed this SOFTWARE PRODUCT.
// If you did not accept the terms of the EULA, you are not authorized to use
// this source code. For a copy of the EULA, please see the LICENSE.RTF on your
// install media.
//
// Copyright 1985-2002 (c) Mettler & Fuchs AG, Dietikon.  All rights reserved.
// Portions copyright 1999-2000 (c) Microsoft Corporation.  All rights reserved.
//
// XC2S200.H
//
// Comments: contains class definition for the Xylinx SPARTAN-II XC2S200
//
#ifndef XC2S200_H
#define XC2S200_H

#include <devload.h>

#define DEVICE_BASE_ADDR_NUM    0x00
#define DEVICE_WINDOW_SIZE    0x1000


// Write System Registers
#define REG_SYS_WRITE_COMMAND                       0x44
#define REG_SYS_WRITE_MODE                          0x48
#define REG_SYS_WRITE_WATCHDOG                      0x4C
#define REG_SYS_WRITE_MASTER_TRANSFER_ADDRESS       0x50
#define REG_SYS_WRITE_INTERRUPT_ACKNOWLEDGE         0x60
#define REG_SYS_WRITE_INTERRUPT_ENABLE              0x64

// Read System Registers
#define REG_SYS_READ_FPGA_IDENTIFICATION            0x00
#define REG_SYS_READ_STATUS                         0x40
#define REG_SYS_READ_INTERRUPT                      0x60


typedef struct _DEVICE_DESC {
  // PCI_COMMON_CONFIG
  USHORT VendorID;            // the PCI Vendor ID
  USHORT DeviceID;            // the PCI Device ID
  UCHAR ProgIF;
  UCHAR BaseClass;
  UCHAR SubClass;
  // DDKISRINFO
  DWORD dwIrq;
  DWORD dwSysintr;            // Interrupt ID
  WCHAR szIsrDll[DEVDLL_LEN];
  WCHAR szIsrHandler[DEVENTRY_LEN];
  // mapped address
  DWORD dwPciWindowSize;      // size of the mapped PCI window
  DWORD dwKernelMemBase;      // mapped by TransBusAddrToStatic, to be used in the ISR only !!
  DWORD dwUserMemBase;        // mapped by TransBusAddrToVirtual, to be used in IST
  LPVOID g_pVPhysMemory;      // virtual pointer to phys. memory
  LPVOID g_pPVaPhysMemory;    // pointer to phys. memory reserved in system (WinCE EBPCI)
  ULONG g_pPPhysMemory;       // phys. pointer to phys memory
} DEVICE_DESC, *PDEVICE_DESC;

typedef class XC2S200 * PDeviceContext, * HDEVICE;

class XC2S200
{
public:
	XC2S200::XC2S200();
  ~XC2S200 ();

	// PCI routines
  BOOL MapDevice (PCTSTR pszActiveKey);
  BOOL UnMapDevice (void);
  BOOL FindDevice (PCTSTR pszActiveKey, PDEVICE_DESC pDevDesc);

  BOOL KLibIoControl(DWORD dwIoControlCode, LPVOID lpInBuf, DWORD nInBufSize, LPVOID lpOutBuf, DWORD nOutBufSize, LPDWORD lpBytesReturned);

  DWORD __inline GetSysIntr (void)
  {
      return DevDesc.dwSysintr;
  }

  void __inline EnableInt (void)
  {
    if (DevDesc.dwUserMemBase) 
    {

      // interrupt acknowledge
      *((PDWORD)(DevDesc.dwUserMemBase + REG_SYS_WRITE_INTERRUPT_ACKNOWLEDGE))= 0x00000001;
      *((PDWORD)(DevDesc.dwUserMemBase + REG_SYS_WRITE_INTERRUPT_ENABLE))= 0x00000001;

      // enable master transfer
      *((PDWORD)(DevDesc.dwUserMemBase + REG_SYS_WRITE_MODE))= 0x00000001;
    }
  }

  void __inline ClearInt (void)
  {
    if (DevDesc.dwUserMemBase) 
    {
      // interrupt acknowledge
      *((PDWORD)(DevDesc.dwUserMemBase + REG_SYS_WRITE_INTERRUPT_ACKNOWLEDGE))= 0x00000001;
    }
  }

	void __inline DisableInt (void)
  {
    if (DevDesc.dwUserMemBase) 
    {
      // disable PCI Master transfer
      *((PDWORD)(DevDesc.dwUserMemBase + REG_SYS_WRITE_MODE))= 0x00000000;

      // system interrupt disable
      *((PDWORD)(DevDesc.dwUserMemBase + REG_SYS_WRITE_INTERRUPT_ENABLE))= 0x00000000;
    }
  }


	void __inline WriteRegister (DWORD AdrOffset, DWORD val)
  {
    if (DevDesc.dwUserMemBase) 
    {
      *((PDWORD)(DevDesc.dwUserMemBase + AdrOffset))= val;
    }
  }

  /*
	void __inline SetBurstLenght (DWORD val)
  {
    if (DevDesc.dwUserMemBase && (val >= 1)) 
    {
      *((PDWORD)(DevDesc.dwUserMemBase + 0x54)) = val - 1;
    }
  }*/

	void __inline RefreshWatchdog (DWORD val)
  {
    if (DevDesc.dwUserMemBase) 
    {
      *((PDWORD)(DevDesc.dwUserMemBase + REG_SYS_WRITE_WATCHDOG)) = val;
    }
  }
	void __inline DisableWatchdog ()
  {
    if (DevDesc.dwUserMemBase) 
    {
      *((PDWORD)(DevDesc.dwUserMemBase + REG_SYS_WRITE_WATCHDOG)) = 0x00000003;
    }
  }

	void __inline SetBurstHostAdr (DWORD val)
  {
    if (DevDesc.dwUserMemBase) 
    {
      *((PDWORD)(DevDesc.dwUserMemBase + REG_SYS_WRITE_MASTER_TRANSFER_ADDRESS)) = val; // Ini. Xmit_Host_Adr
    }
  }

  DWORD __inline ReadRegister (DWORD AdrOffset)
  {
    if (DevDesc.dwUserMemBase) 
    {
      return *((PDWORD)(DevDesc.dwUserMemBase + (AdrOffset*sizeof(DWORD))));
    }
    else
    {
      return 0;
    }
  }

    // global variables pointing to pre-allocated memory
private:

  // Member Variable
  HANDLE m_hIsrHandler;       // installable ISR handler
  BOOL	m_bPCIMemoryIsMapped;	        // must call MmUnmapIoSpace when destroyed

  DEVICE_DESC DevDesc;

};

// CAutoLock helper class
class CAutoLock
{
public:
  CAutoLock (CRITICAL_SECTION * cs)
  {
    pcs = cs;
    EnterCriticalSection(pcs);
  }
    ~CAutoLock ()
  {
    LeaveCriticalSection(pcs);
  }
private:
  CRITICAL_SECTION * pcs;
};

#endif  // XC2S200_H
