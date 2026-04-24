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
#include "debug.h"
#include "cregkey.h"
#include "xc2s200.h"

#include <ddkreg.h>
#include <wdm.h>
#include <oemkfuncs.h>

#include "EBHITtype.h"

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
XC2S200::XC2S200 (void)
{
	//initialize our member variables

  m_bPCIMemoryIsMapped = FALSE;
  m_hIsrHandler=NULL;
  DevDesc.g_pPPhysMemory = 0;
  DevDesc.g_pVPhysMemory = NULL;
}


//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
XC2S200::~XC2S200 ()
{
  //invalidate our member variables

}

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
BOOL XC2S200::FindDevice(PCTSTR pszActiveKey, PDEVICE_DESC pDevDesc)
{
  ULONG               l_uiAddressSpace = 0;
  PHYSICAL_ADDRESS    l_PhysicalMemPCIBaseAdr;
  PCI_SLOT_NUMBER     l_PCISlotNumber;
  PCI_COMMON_CONFIG   l_PCICommonConfig;
  int                 l_nPCIBusNumber = 0;
  int                 l_nPCIDevice = 0;
  int                 l_nPCIFunction = 0;
  int                 l_nLength = 0;
  BOOL                l_bFoundIt = FALSE;
  PVOID               l_pPtr = NULL;
  DWORD               l_dwRetValue = 0;
  DWORD               l_dwQuery = 0;
  DWORD               l_dwSize;
  SYSINTR_MASK_PARMS  l_IntMaskParameter;
  BOOL                l_bRetVal = FALSE;
  
  PULONG              l_paPages = new ULONG[1];
  LPVOID              l_pVAdr = NULL;
  LPVOID              l_pPAdr = NULL;
  DWORD               l_dwError = 0;


  // set up convenient access to our registry key
  CRegKey cRegKey(pszActiveKey);

  if (cRegKey.QueryDword(TEXT("Class"),l_dwQuery))
  {
    pDevDesc->BaseClass = (UCHAR)l_dwQuery;
  }

  if (cRegKey.QueryDword(TEXT("SubClass"),l_dwQuery))
  {
    pDevDesc->SubClass = (UCHAR)l_dwQuery;
  }

  if (cRegKey.QueryDword(TEXT("ProgIF"),l_dwQuery))
  {
    pDevDesc->ProgIF = (UCHAR)l_dwQuery;
  }

  if (cRegKey.QueryDword(TEXT("VendorID"),l_dwQuery))
  {
    pDevDesc->VendorID = (USHORT)l_dwQuery;
  }
  if (cRegKey.QueryDword(TEXT("DeviceID"),l_dwQuery))
  {
    pDevDesc->DeviceID = (USHORT)l_dwQuery;
  }

  l_dwSize = sizeof(pDevDesc->szIsrDll);
  cRegKey.QuerySzW(TEXT("IsrDll"),l_dwSize,pDevDesc->szIsrDll);

  l_dwSize = sizeof(pDevDesc->szIsrHandler);
  cRegKey.QuerySzW(TEXT("IsrHandler"),l_dwSize,pDevDesc->szIsrHandler);

  // Scan for the PCI bridge
  for (l_nPCIBusNumber = 0; l_nPCIBusNumber < PCI_MAX_BUS; l_nPCIBusNumber++)
  {
    for (l_nPCIDevice = 0; l_nPCIDevice < PCI_MAX_DEVICES; l_nPCIDevice++)
    {
      l_PCISlotNumber.u.bits.DeviceNumber = l_nPCIDevice;

      for (l_nPCIFunction = 0; l_nPCIFunction < PCI_MAX_FUNCTION; l_nPCIFunction++)
      {
        l_PCISlotNumber.u.bits.FunctionNumber = l_nPCIFunction;

        // retrieves configuration information about PCI bus
        l_nLength = HalGetBusData(PCIConfiguration,          // bus data type -> PCI
                               l_nPCIBusNumber,           // PCI bus number
                               l_PCISlotNumber.u.AsULONG, // slot number
                               &l_PCICommonConfig,        // buffer to the PCI configuration
			                         sizeof(l_PCICommonConfig) - sizeof(l_PCICommonConfig.DeviceSpecific));


        if (l_nLength == 0 || l_PCICommonConfig.VendorID == 0xFFFF) 
            break;

        // If the device is a PCI bridge, see if it is the one we're looking for
        if ((l_PCICommonConfig.BaseClass == pDevDesc->BaseClass) && 
          (l_PCICommonConfig.SubClass == pDevDesc->SubClass))
        {
          // If vendor and device IDs match, we have found the PCI bridge we're looking for
          if ((l_PCICommonConfig.VendorID == pDevDesc->VendorID) && 
            (l_PCICommonConfig.DeviceID == pDevDesc->DeviceID))
          {
            l_bFoundIt = TRUE;
					  break;
          }
         }
      
        if (l_nPCIFunction == 0 && !(l_PCICommonConfig.HeaderType & 0x80)) 
          break;
    
      } // end for (l_nPCIFunction = 0
      
      if (l_bFoundIt || l_nLength == 0)
        break;
    
    } // end for (l_nPCIDevice = 0
    
    if (l_bFoundIt || (l_nLength == 0 && l_nPCIDevice == 0))
      break;
  } // end for (l_nPCIBusNumber = 0

  if (!l_bFoundIt) 
  {
    return FALSE;
  }

  // setup size of the pci register window (byte)
  pDevDesc->dwPciWindowSize = DEVICE_WINDOW_SIZE;

  // We found the Xilinx Spartan-II
  pDevDesc->dwIrq = l_PCICommonConfig.u.type0.InterruptLine; // PCI interrupt line register
  
  // gets the Software (system) IRQ Number
  if (!KernelIoControl( IOCTL_HAL_REQUEST_SYSINTR, 
                        (LPVOID)&pDevDesc->dwIrq, 
                        sizeof(DWORD), 
                        (LPVOID)&pDevDesc->dwSysintr, 
                        sizeof(DWORD), 
                        &l_dwRetValue))
  {
      pDevDesc->dwSysintr = NULL;
      return FALSE;
  }

  // PCI base address
  l_PhysicalMemPCIBaseAdr.HighPart = 0; // must be equal to 0 for PCI
  // mask off the non-address bits of the lower part of bus address
  l_PhysicalMemPCIBaseAdr.LowPart = l_PCICommonConfig.u.type0.BaseAddresses[DEVICE_BASE_ADDR_NUM] & PCI_ADDRESS_MEMORY_ADDRESS_MASK;
  
  // Old adTEST.PB
  //l_PhysicalMemPCIBaseAdr.LowPart = l_PCICommonConfig.u.type0.BaseAddresses[DEVICE_BASE_ADDR_NUM] & 0xFFFFFFF0;

  // set the SYSINTR as non maskable INT
  l_IntMaskParameter.SysIntr = pDevDesc->dwSysintr;
  l_IntMaskParameter.Mask = FALSE;

  // set mask, so we have a free running ISR with asynchronous IST notification
  if (!KernelIoControl( IOCTL_HAL_SET_SYSINTR_MASKABLE, 
                        (LPVOID)&l_IntMaskParameter, 
                        sizeof(l_IntMaskParameter), 
                        NULL, 
                        0, 
                        &l_dwRetValue))
  {
    pDevDesc->dwSysintr = NULL;
    return FALSE;
  }

  // converts the PCI physical memory address into a system physical address 
  l_uiAddressSpace = 0; // should be memory address
  l_bRetVal = TransBusAddrToVirtual( PCIBus,
                                     l_nPCIBusNumber,            // PCI Bus number
                                     l_PhysicalMemPCIBaseAdr,    // PCI Bus physical base address
                                     pDevDesc->dwPciWindowSize,  // number of bytes to map on the device
                                     &l_uiAddressSpace,          // address space
                                     &l_pPtr);                   // virtual static addr. where the func. map the phy.addr.
  if (!l_bRetVal) 
  {
    pDevDesc->dwUserMemBase = NULL;
    return FALSE;
  }
  pDevDesc->dwUserMemBase = (DWORD)l_pPtr;

  // translates a bus-relative address to a system or logical address, then it creates a static,
  // process independent, virtual address mapping for that location
  l_uiAddressSpace = 0; // should be memory address
  l_bRetVal = TransBusAddrToStatic(PCIBus,                     // bus interface type
                                   l_nPCIBusNumber,            // PCI Bus number
                                   l_PhysicalMemPCIBaseAdr,    // PCI Bus physical base address
                                   pDevDesc->dwPciWindowSize,  // number of bytes to map on the device
                                   &l_uiAddressSpace,          // address space
                                   &l_pPtr);                   // virtual static addr. where the func. map the phy.addr.
  if (!l_bRetVal) 
  {
    pDevDesc->dwKernelMemBase = NULL;
    return FALSE;
  }
  // statically mapped address to the PCI device for use in the ISR only!!!
  pDevDesc->dwKernelMemBase = (DWORD)l_pPtr;


  l_dwSize = UserKInfo[KINX_PAGESIZE];         // system page size
  l_pVAdr = VirtualAlloc(0,                    // determines where to allocate the region
                         l_dwSize,             // size in bytes
                         MEM_RESERVE,          // Reserves a range of the virtual address space of the process without allocating any physical storage               
                         PAGE_NOACCESS);       // Disables all access to the committed region of pages


  if (!l_pVAdr)
  {
    l_dwError = GetLastError();
    ASSERT(FALSE);
    // TODO EXCEPTION TEST.PB
  }

  l_pPAdr = CHIIOCPCISettings::GetclpAdrPCIMasterTransferMemory(); // PCI memory address (see CONFIG.BIB WinCE 0x81420000)

  l_bRetVal = VirtualCopy(l_pVAdr,                         // destination virtual memory
                          l_pPAdr,                         // pointer to the committed physical memory
                          l_dwSize,                        // size in bytes
                          PAGE_READWRITE | PAGE_NOCACHE ); // no caching, read / write access

  if (!l_bRetVal)
  {
    l_dwError = GetLastError();
    ASSERT(FALSE);
    // TODO EXCEPTION TEST.PB
  }

  DevDesc.g_pVPhysMemory = l_pVAdr;
  DevDesc.g_pPVaPhysMemory = CHIIOCPCISettings::GetclpAdrPCIMasterTransferMemory();

  // determine actual physical address
  l_bRetVal = LockPages(l_pVAdr,                 // Starting address of a region of committed pages
                        UserKInfo[KINX_PAGESIZE],// Number of bytes to lock
                        l_paPages,               // pointer to the CPU-dependent physical addresses of the pages
                        LOCKFLAG_WRITE);         // Write access required (locking excludes other writers)
  if (!l_bRetVal)
  {
     l_dwError = GetLastError();
  }
  DevDesc.g_pPPhysMemory = (ULONG)(l_paPages[0] << UserKInfo[KINX_PFN_SHIFT]); // real phys. memory address
  
  if (l_paPages != NULL)
  {
    delete [] l_paPages;
  }
  l_paPages = NULL;

  return TRUE;
}



//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
BOOL XC2S200::KLibIoControl(DWORD dwIoControlCode, LPVOID lpInBuf, DWORD nInBufSize, LPVOID lpOutBuf, DWORD nOutBufSize, LPDWORD lpBytesReturned)

{
  if (m_hIsrHandler)
    return KernelLibIoControl(m_hIsrHandler, dwIoControlCode, lpInBuf, nInBufSize, lpOutBuf, nOutBufSize, lpBytesReturned);
  else 
    return FALSE;
}



//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
BOOL XC2S200::MapDevice (PCTSTR pszActiveKey)
{
  DWORD dwError=0;

  // set up convenient access to our registry key
  CRegKey cRegKey(pszActiveKey);

  // Install ISR handler if there is one and if there is a device for
  if (FindDevice(pszActiveKey,&DevDesc)) 
  {    
    //install Buchi EBISR Handler 
    m_hIsrHandler = LoadIntChainHandler(DevDesc.szIsrDll,     // filename that names the DLL ISR executable module
                                        DevDesc.szIsrHandler, // Name of the interrupt handler entry point
                                        (BYTE) DevDesc.dwIrq);// IRQ value that is used to identify what interrupt the installed ISR will service
    dwError = GetLastError();
    if (m_hIsrHandler == NULL)
	  {
      ASSERT(FALSE);
    }
	  else
	  {

	      CHIIOCPCISettings* l_pPCISettings = new CHIIOCPCISettings(
              (DWORD)CHIIOCPCISettings::GetclpAdrPCIMasterTransferMemory(), // physical memory PCI Master mode (read)
			        DevDesc.dwKernelMemBase,                               // physical memory PCI Target mode (write)
			        DevDesc.dwSysintr,		                                 // System Interrupt number
			        (DWORD)0x00000001);		                                 // Interrupt Mask

	      if (!KernelLibIoControl(m_hIsrHandler, IOCTL_HAL_SET_ISR_PCI_SETTINGS, l_pPCISettings, sizeof(CHIIOCPCISettings), NULL, 0, NULL))
	      {
	        ASSERT(FALSE);
          if (l_pPCISettings)
          {
             delete l_pPCISettings;
          }
          l_pPCISettings = NULL;

		    return FALSE;
	      }

		    // set the PCI address for the Master Transfer
        SetBurstHostAdr(DevDesc.g_pPPhysMemory);

        if (l_pPCISettings)
        {
           delete l_pPCISettings;
        }
        l_pPCISettings = NULL;

     }
  }
  else
  {
    return FALSE;
  }

  return TRUE;
}



//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
BOOL XC2S200::UnMapDevice (void)
{
  DWORD               l_dwRetValue;
  SYSINTR_MASK_PARMS  l_IntMaskParameter;

  // for sure disable XC2S200 int before removing the ISR hooked in
  DisableInt();

  // set the SYSINTR back as maskable INT
  l_IntMaskParameter.SysIntr = DevDesc.dwSysintr;
  l_IntMaskParameter.Mask = TRUE;

  // set mask, so we have a free running ISR with asynchronous IST notification
  if (!KernelIoControl( IOCTL_HAL_SET_SYSINTR_MASKABLE, 
                                (LPVOID)&l_IntMaskParameter, 
                                sizeof(l_IntMaskParameter), 
                                NULL, 
                                0, 
                                &l_dwRetValue))
  {
    DevDesc.dwSysintr = NULL;
    return FALSE;
  }

  // disable the IRQ source handeled by the PIC
  InterruptDisable(DevDesc.dwSysintr);

  if (m_hIsrHandler != NULL) {
    FreeIntChainHandler(m_hIsrHandler);
    m_hIsrHandler = NULL;
  }

  // finally  release Sysintr
  if (!KernelIoControl( IOCTL_HAL_RELEASE_SYSINTR, 
                                (LPVOID)&DevDesc.dwSysintr, 
                                sizeof(DWORD), 
                                NULL, 
                                0, 
                                &l_dwRetValue))
  {
    //DEBUGMSG(ZONE_ERROR, (TEXT("XC2S200: Failed RequestSysIntr\r\n")));
    return FALSE;
  }


  if (m_bPCIMemoryIsMapped) {
    MmUnmapIoSpace((PVOID)DevDesc.dwUserMemBase, DevDesc.dwPciWindowSize);
    m_bPCIMemoryIsMapped = FALSE;
  }


  if (DevDesc.g_pVPhysMemory != NULL)
    FreePhysMem(DevDesc.g_pVPhysMemory);

  DevDesc.g_pVPhysMemory = NULL;


  return TRUE;
}
