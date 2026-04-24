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
// GIISR.c
//
// Generic Installable Interrupt Service Routine.
//
//

#ifdef _WIN32_WCE
#include "stdafx.h"
#include <nkintr.h>
#include <ceddk.h>

#include <giisr.h>


/////////////////////////////////////////////
// BUCHI Start - Include

#include "EBISRcont.h"
#include "EBHITrsm.h"
#include "EBHITtype.h"

// BUCHI END
/////////////////////////////////////////////


// Globals
// DWORD g_PortValue;
const DWORD g_ISRInstance = 1;



/////////////////////////////////////////////
// BUCHI Start
// Globals
bool g_bDataAcquisitionOn = false;

CISRWCPIDControl* g_pWCPIDControl = NULL; // WC PID Controller
CHIIOCPCISettings* g_pPCISettings = NULL; // global ISR Settings

CHIIOCEventMasks g_sEventMaskReg;

DWORD g_dwCounter = 0;
bool g_bEvent = false;
bool g_bEventSignalisationOn = true;

// BUCHI END
/////////////////////////////////////////////

/*
 @doc INTERNAL
 @func    BOOL | DllEntry | Process attach/detach api.
 *
 @rdesc The return is a BOOL, representing success (TRUE) or failure (FALSE).
 */
BOOL __stdcall
DllEntry(
    HINSTANCE hinstDll,         // @parm Instance pointer.
    DWORD dwReason,             // @parm Reason routine is called.
    LPVOID lpReserved           // @parm system parameter.
     )
{
     if (dwReason == DLL_PROCESS_ATTACH) 
     {      
	    
        g_pWCPIDControl = new CISRWCPIDControl();
    	  if (g_pWCPIDControl == NULL)
        {
          __asm int 3   // debug break
        }
      
  	    g_pPCISettings = new CHIIOCPCISettings();
        if(g_pPCISettings == NULL)
        {
          __asm int 3   // debug break
        }
      
        g_pPCISettings->SetdwSysintr(0);
        g_pPCISettings->SetIntMask(0);
        
        for (int ii = 0; ii < EBHIT_NUMBER_OF_HW_EVENT_REG; ii++)
        {
          g_sEventMaskReg.m_dwHWEventMask[ii] = 0xFFFFFFFF;
        }

        for (int jj = 0; jj < EBHIT_NUMBER_OF_WC_EVENT_REG; jj++)
        {
          g_sEventMaskReg.m_dwWCEventMask[jj] = 0xFFFFFFFF;
        }

        g_bEventSignalisationOn = true;
     }

     if (dwReason == DLL_PROCESS_DETACH)
     {
       if (g_pWCPIDControl)
       {
         delete g_pWCPIDControl;
       }
       g_pWCPIDControl = NULL;

       if (g_pPCISettings)
       {
         delete g_pPCISettings;
       }
       g_pPCISettings = NULL;
     }
     return TRUE;
}


extern "C" DWORD __declspec(dllexport) CreateInstance(
    void
    )
{

    // Initialize info
    g_pPCISettings->SetdwSysintr(SYSINTR_CHAIN);

    return g_ISRInstance;
}


// The compiler generates a call to memcpy() for assignments of large objects.
// Since this library is not linked to the CRT, define our own copy routine.
void InfoCopy(PVOID dst, PVOID src, DWORD size)
{

    PBYTE l_dst = NULL;
    PBYTE l_src = NULL;
    DWORD Index = 0;

    l_dst = (PBYTE)dst;
    l_src = (PBYTE)src;

    while(Index < size)
    {
        l_dst[Index] = l_src[Index];
        Index++;
    }
}


extern "C" BOOL __declspec(dllexport)
IOControl(
    DWORD   InstanceIndex,
    DWORD   IoControlCode, 
    LPVOID  pInBuf, 
    DWORD   InBufSize,
    LPVOID  pOutBuf, 
    DWORD   OutBufSize, 
    LPDWORD pBytesReturned
    ) 
{
    DWORD l_Index = 0;
	
    if (pBytesReturned) {
        *pBytesReturned = 0;
    }

    int ii = 0;
    DWORD *l_pdwI2C = NULL;
    bool l_bFlag = true;
    
    PBYTE l_pDummy = NULL;
    DWORD l_dwDataSize = 0;

    switch (IoControlCode) {
        
    case IOCTL_HAL_SET_ISR_PCI_SETTINGS:
        // Copy instance information
        if ((InBufSize != sizeof(CHIIOCPCISettings)) || !pInBuf) {
            // Invalid size of input buffer or input buffer pointer
            return FALSE;
        }

        InfoCopy(g_pPCISettings, (CHIIOCPCISettings*)pInBuf, sizeof(CHIIOCPCISettings));
        
        break;

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // BUCHI Start - IOControl Commands

    // sets the wedge control configuration
    case IOCTL_HAL_PCI_WC_SETCONFIG:
    // sets the wedge control profile
    case IOCTL_HAL_PCI_WC_SETPROFILE:
    // resets the wedge control
    case IOCTL_HAL_PCI_WC_RESET:
    // starts the wedge control
    case IOCTL_HAL_PCI_WC_START:
    // stops the wedge control
    case IOCTL_HAL_PCI_WC_STOP:
    // starts the referencing mode
    case IOCTL_HAL_PCI_WC_REFERENCING:
    // initialize the wedge control
    case IOCTL_HAL_PCI_WC_INI:
    // stops the wedge drive immediately
    case IOCTL_HAL_PCI_WC_EMERGENCY_STOP:
    // sets the wedge DAC value (Wdg_Volt)
    case IOCTL_HAL_PCI_WC_SET_DAC:
    // switches on/off wedge controller
    case IOCTL_HAL_PCI_WC_CONTROLLER:
        if (!g_pWCPIDControl->WCPIDControlHandler(IoControlCode, pInBuf, InBufSize))
        {
          return FALSE;
        }
        break;

    // gets the actual wedge velocity (Wdg_Act_Vlc)
    case IOCTL_HAL_PCI_WC_GET_ACT_VELOCITY:
    // gets the last wedge velocity (Wdg_Last_Vlc)
    case IOCTL_HAL_PCI_WC_GET_LAST_VELOCITY:
    // gets the wedge position (Wdg_Pos)
    case IOCTL_HAL_PCI_WC_GET_POSITION:
    // light barrier state
    case IOCTL_HAL_PCI_WC_LB_STATE:       
        if (!g_pWCPIDControl->WCPIDControlHandler(IoControlCode, pInBuf, InBufSize, pOutBuf, OutBufSize))
        {
          return FALSE;
        }
        break;

    // Starts the data acquisition  (IFM and Laser)
    case IOCTL_HAL_PCI_DATA_ON:
        CHITReservedSharedMemory::SetInitialStreamBufferData();
        g_bDataAcquisitionOn = true;
        break;
    // Stops the data acquisition  (IFM and Laser)
    case IOCTL_HAL_PCI_DATA_OFF:
        g_bDataAcquisitionOn = false;
        break;
    
    // Sets the "Reserved Shared Memory" address pointer for to the ISR
    case IOCTL_HAL_PCI_SET_RSM_ADDRESS:
        if ((InBufSize != sizeof(CHIIOCSetRSMAddress)) || !pInBuf) {
            // Invalid size of input buffer or input buffer pointer
            return FALSE;
        }
        
        CHITReservedSharedMemory::InitInstance((DWORD*)((CHIIOCSetRSMAddress*)pInBuf)->GetpRSMStreamBuffer(),
                                               (DWORD*)((CHIIOCSetRSMAddress*)pInBuf)->GetpRSMProcessImage());
        

        break;

    // set new stream buffer size
    case IOCTL_HAL_PCI_SET_BUFFERSIZE:
        if ((InBufSize != sizeof(DWORD)) || !pInBuf) {
            // Invalid size of input buffer or input buffer pointer
            return FALSE;
        }

        CHITReservedSharedMemory::SetNewStreamBufferSize(*(int*)pInBuf);
        break;   

    // mask HW and WC event register
    case IOCTL_HAL_PCI_WC_MASK_EVENT_REG:
        if ((InBufSize != sizeof(CHIIOCEventMasks)) || !pInBuf) {
            // Invalid size of input buffer or input buffer pointer
            return FALSE;
        }
        g_sEventMaskReg = *((CHIIOCEventMasks*)pInBuf);
        break;
    
    // Clears the "Reserved Shared Memory" address pointer for to ISR
    case IOCTL_HAL_PCI_CLEAR_RSM_ADDRESS:
        
        CHITReservedSharedMemory::DeleteInstance();
      
        break;
    
    // notify the ISR to send an event
    case IOCTL_HAL_PCI_WC_SEND_EVENT:        
        g_bEvent = true;
        g_bEventSignalisationOn = true;
        break;

    case IOCTL_HAL_PCI_ACK_EVENT:
        g_bEventSignalisationOn = true;
        break;
    // BUCHI End
    ////////////////////////////////////////////////////////////////////////////////////////////////


    default:
        // Invalid IOCTL
        // TODO
        return FALSE;
    }
    
    return TRUE;
}

extern "C" DWORD __declspec(dllexport)
ISRHandler(
    DWORD InstanceIndex
    )
{
    DWORD l_dwIntRetVal = SYSINTR_NOP;
    
    
    DWORD l_dwIFMStreamData[DATA_STACK_DIVIDER];
    DWORD l_dwLaserStreamData[DATA_STACK_DIVIDER];

// 1
// *((PDWORD)(g_pPCISettings->GetpPCIWriteBasePtr() + 0x170)) = *(CHITReservedSharedMemory::GetKernelProcImWriteDataStartAdr()+0xC) | 4;
    __asm {
      cli
    }
    
    PDWORD l_pAdrDigInput = CHITReservedSharedMemory::GetDigInputRegStartAdr();
    DWORD l_dwLastDigInputState[EBHIT_NUMBER_OF_DI_EVENT_REG];
    for (int jj = 0; jj < EBHIT_NUMBER_OF_DI_EVENT_REG; jj++)
    {
      l_dwLastDigInputState[jj] = *(l_pAdrDigInput + jj);
    }

    ////////////////////////////////////////    
    // READ FROM PCI (MASTER MODE) - Process Image
    // move the HW PCI read register into the SW process image
    // the HW PCI event register must be "verodert" with the SW process image event register !!!
    //
    // First check the I2C Event Bit; if I2C Event set -> copy all Data; if I2C Event not set -> copy Data
    // without I2C Data!
    DWORD l_dwNoEventReg = CHITReservedSharedMemory::GetcdwNumbersOfEventReg();
    PDWORD l_pDest = CHITReservedSharedMemory::GetKernelProcImReadDataStartAdr() + l_dwNoEventReg;
    PDWORD l_pSrc = ((PDWORD)g_pPCISettings->GetpPCIUserReadBasePtr()) + l_dwNoEventReg;
    DWORD l_dwDataSize = g_pPCISettings->GetdwReadDataTransferDWordSize() - l_dwNoEventReg; // all Data (inc. I2C) size in DWORD

    PDWORD l_pI2CEventReg = (PDWORD)g_pPCISettings->GetpPCIUserReadBasePtr();

    if (g_bDataAcquisitionOn)
    {
      if (*l_pI2CEventReg == 0)
      { // no I2C Data available
        l_dwDataSize-= CHITReservedSharedMemory::GetcdwNumbersOfI2CData();
      }
	    
      // copy process image data
      CHITReservedSharedMemory::MemCopyByForLoop(l_pDest, l_pSrc, l_dwDataSize);

	  }
	  else
	  {
		    // copy laser and ifm data snap shot to shared memory for diagnostic interface
 //2
 //     *((PDWORD)(g_pPCISettings->GetpPCIWriteBasePtr() + 0x170)) = *(CHITReservedSharedMemory::GetKernelProcImWriteDataStartAdr()+0xC) | 4;
          if (*l_pI2CEventReg == 0)
          { 
            // no I2C Data available
            // copy process image data exc. I2C Data
            l_dwDataSize-= CHITReservedSharedMemory::GetcdwNumbersOfI2CData();
            CHITReservedSharedMemory::MemCopyByForLoop(l_pDest, l_pSrc, l_dwDataSize);          

            // now copy stream data to the process image
            l_pDest = CHITReservedSharedMemory::GetProcImIFMDataStartAdr();
            l_pSrc = (PDWORD)g_pPCISettings->GetpPCIReadIFMDataAdr();
            l_dwDataSize = 2 * DATA_STACK_DIVIDER;
            CHITReservedSharedMemory::MemCopyByForLoop(l_pDest, l_pSrc, l_dwDataSize);
          }
          else
          {
            // copy process image data inc. I2C Data and Stream Data
            l_dwDataSize+=  (2 * DATA_STACK_DIVIDER);
            CHITReservedSharedMemory::MemCopyByForLoop(l_pDest, l_pSrc, l_dwDataSize);
          }
	  }
//3
//    *((PDWORD)(g_pPCISettings->GetpPCIWriteBasePtr() + 0x170)) = *(CHITReservedSharedMemory::GetKernelProcImWriteDataStartAdr()+0xC) | 4;

    ////////////////////////////////////////
    // Wedge Control WC 
    if (g_pWCPIDControl != NULL)
    {
      g_pWCPIDControl->WCPIDController();
    }

    ////////////////////////////////////////    
    // Data Aquistion
    if (g_bDataAcquisitionOn)
    {
		  ////////////////////////////////////////    
		  // READ FROM PCI (MASTER MODE) - Process Image
		  // move IFM and LASER data to streambuffer
          l_pSrc = (PDWORD)g_pPCISettings->GetpPCIReadIFMDataAdr();
          CHITReservedSharedMemory::MemCopyByForLoop(l_dwIFMStreamData, l_pSrc, DATA_STACK_DIVIDER);
		      
          l_pSrc = (PDWORD)g_pPCISettings->GetpPCIReadLaserDataAdr();
          CHITReservedSharedMemory::MemCopyByForLoop(l_dwLaserStreamData, l_pSrc, DATA_STACK_DIVIDER);

		  ////////////////////////////////////////
		  // Copy Stream Data into Stream-Buffers
		  CHITReservedSharedMemory::SetStreamData(l_dwIFMStreamData, l_dwLaserStreamData);
    }

    
    ////////////////////////////////////////////////////////////
    // check HW event register from PCI
    PDWORD l_pEventReg = (PDWORD)g_pPCISettings->GetpPCIUserReadBasePtr();

    PDWORD l_pProcImEventRegAdr = (CHITReservedSharedMemory::GetKernelProcImReadBaseAdr() + (CHITReservedSharedMemory::GetcdwAdrOffsetEventReg() / sizeof(DWORD)));
    PDWORD l_pHWEventMask = NULL;
    DWORD  l_dwEventMaskSize = 0;
    DWORD l_dwNewEventReg = 0;
	DWORD l_dwCnt; //scch
    for (l_dwCnt = 0; l_dwCnt < l_dwNoEventReg; l_dwCnt++)
    {
      // mask new input events
      l_dwNewEventReg = l_pEventReg[l_dwCnt] & g_sEventMaskReg.m_dwHWEventMask[l_dwCnt];    

      if (l_dwNewEventReg != 0)
      {
        g_bEvent = true;
      }

      l_pProcImEventRegAdr[l_dwCnt]|= l_dwNewEventReg;
    }

    // check WC event register
    PDWORD l_pWCEventReg = NULL;
    PDWORD l_pWCEventMask = NULL;
    
    l_dwNewEventReg = 0;
    l_pWCEventReg = CHITReservedSharedMemory::GetWCEventRegStartAdr();
    l_dwNoEventReg = CHITReservedSharedMemory::GetcdwNumbersOfWCEventReg();
  
    for (l_dwCnt = 0; l_dwCnt < l_dwNoEventReg; l_dwCnt++)
    {
       // mask new WC input events
       l_dwNewEventReg = l_pWCEventReg[l_dwCnt] & g_sEventMaskReg.m_dwWCEventMask[l_dwCnt];    
     
       if (l_dwNewEventReg != 0)
       {
          g_bEvent = true;
       }

    }


    ////////////////////////////////////////
    // check dig. input -> trailing edge
    l_pAdrDigInput = CHITReservedSharedMemory::GetDigInputRegStartAdr();
    PDWORD l_pAdrDigInputEdge = CHITReservedSharedMemory::GetDigInputTrailingEdgeRegStartAdr();
    
    for (int ii = 0; ii < EBHIT_NUMBER_OF_DI_EVENT_REG; ii++)
    {
      l_pAdrDigInputEdge[ii]|= (l_dwLastDigInputState[ii] & ~l_pAdrDigInput[ii]);
    }

    ////////////////////////////////////////
    // check dig. input -> rising edge
    l_pAdrDigInput = CHITReservedSharedMemory::GetDigInputRegStartAdr();
    l_pAdrDigInputEdge = CHITReservedSharedMemory::GetDigInputRaisingEdgeRegStartAdr();
    
    for (int tt = 0; tt < EBHIT_NUMBER_OF_DI_EVENT_REG; tt++)
    {
      l_pAdrDigInputEdge[tt]|= (~l_dwLastDigInputState[tt] & l_pAdrDigInput[tt]);
    }

    //////////////////////////////////////////
    // check HW Error and Warning State
    PDWORD l_pAdrActHwErrWarnState = CHITReservedSharedMemory::GetActHwErrAndWarnStateAdr();
    PDWORD l_pAdrHwErrWarnState = CHITReservedSharedMemory::GetHwErrAndWarnStateAdr();
    *l_pAdrHwErrWarnState|= *l_pAdrActHwErrWarnState;

    ////////////////////////////////////////    
    // WRITE TO PCI (TARGET MODE) - Process Image
    l_pDest = (PDWORD)g_pPCISettings->GetpPCIUserWriteBasePtr();
    l_pSrc = CHITReservedSharedMemory::GetKernelProcImWriteDataStartAdr();
    
    // check for I2C Data Valid Bit
    PDWORD l_pI2CDataValidReg = CHITReservedSharedMemory::GetI2CDataValidAdr();
    if (*l_pI2CDataValidReg == 0)
    {  // no I2C Data available
      l_dwDataSize = g_pPCISettings->GetdwWriteDataTransferDWordSize() - CHITReservedSharedMemory::GetcdwNumbersOfI2CData(); // size in DWORD
    }
    else
    { // I2C Data available
      l_dwDataSize = g_pPCISettings->GetdwWriteDataTransferDWordSize(); // size in DWORD
    }
    
    CHITReservedSharedMemory::MemCopyByForLoop(l_pDest, l_pSrc, l_dwDataSize);

    // clear all data valid bits in the SW process image
    PDWORD l_pProcImDataValidAdr = (CHITReservedSharedMemory::GetKernelProcImWriteBaseAdr() + (CHITReservedSharedMemory::GetcdwAdrOffsetDataValidReg() / sizeof(DWORD)));
    DWORD l_dwNumberOfDataValidRegsiter = (CHITReservedSharedMemory::GetcdwNumbersOfDataValidReg());
    
    for (l_dwCnt = 0; l_dwCnt < l_dwNumberOfDataValidRegsiter; l_dwCnt++)
    {
        l_pProcImDataValidAdr[l_dwCnt] = 0;
    }
    
    if (g_bEventSignalisationOn)
    {    
       // check events 
      if (g_bEvent)
      {
        // get our interrupt number
        DWORD l_dwIntNumber = *((PDWORD)(g_pPCISettings->GetpPCIWriteBasePtr() + g_pPCISettings->GetdwOffsetIrqValue()));

        // send notification to IST (interrupt service thread)
        if (l_dwIntNumber & g_pPCISettings->GetIntMask())
        {
          // its our interrupt
          l_dwIntRetVal = g_pPCISettings->GetdwSysintr();
          g_bEventSignalisationOn = false;
        }
        else
        {
          // continue to next ISR handler
          l_dwIntRetVal = SYSINTR_CHAIN;
        }

        // clear event signalisation
        g_bEvent = false;
  
      }
    }
    
   // Clear Int
    *((PDWORD)(g_pPCISettings->GetpPCIWriteBasePtr() + g_pPCISettings->GetdwOffsetInterruptClear())) = 0x1;
    
    __asm
    {
      sti ; enable interrupt state
    }

    return l_dwIntRetVal;

}

#endif
