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
// -----------------------------------------------------------------------------
//
//      THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//      ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//      THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//      PARTICULAR PURPOSE.
//  
// -----------------------------------------------------------------------------

#define INSTANTIATE_DEBUG
#include "debug.h"
#include "cregkey.h"
#include "xc2s200.h"


#include <winioctl.h>
// EBHItype
#include "EBHITtype.h"


// -----------------------------------------------------------------------------
// DllMain
// -----------------------------------------------------------------------------
BOOL __stdcall
DllMain (
    HANDLE  hinstDLL,
    DWORD   Op,
    LPVOID  lpvReserved
    )
{

    switch (Op) {

        case DLL_PROCESS_ATTACH :
            DEBUGREGISTER((HINSTANCE)hinstDLL);
			      DisableThreadLibraryCalls((HMODULE) hinstDLL);
            break;

        case DLL_PROCESS_DETACH :
            break;
            
        case DLL_THREAD_DETACH :
            break;
            
        case DLL_THREAD_ATTACH :
            break;
            
        default :
            break;
    }
    return TRUE;
}


// OPENHANDLES are created on PCI_Open and get passed in to PCI_IoControl, PCI_Write, etc.
typedef struct _tag_OPENHANDLE
{
    HDEVICE hDriver;
} OPENHANDLE, *POPENHANDLE;

// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
HDEVICE
PCI_Init(PCTSTR pszActiveKey)
{ 
	HDEVICE pDevice;
    
  pDevice = new XC2S200();
  if (pDevice != NULL)
  {
    if (!pDevice->MapDevice(pszActiveKey))
    {
      //PCI_Init FAILED 
      delete pDevice;
      pDevice = NULL;
    } 
  }
  return pDevice;
}

// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
BOOL
PCI_Deinit(
    HDEVICE pDevice
    )
{
//    //DEBUGMSG (ZONE_DRIVER, (TEXT("PCI_Deinit(0x%X)\r\n"), pDevice));

  if (pDevice)
  {
    if (! pDevice->UnMapDevice()) {
      //DEBUGMSG(ZONE_ERROR, (TEXT("PCI_Deinit FAILED")));
    } 
    delete pDevice;
    pDevice = NULL;
  }
  return TRUE;
}

// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
VOID
PCI_PowerUp(
    HDEVICE pDevice
    )
{
  //  //DEBUGMSG (ZONE_DRIVER, (TEXT("PCI_PowerUp(%08x)\r\n"), pDevice));

//    pDevice->PowerUp();
}



// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
VOID
PCI_PowerDown(
    HDEVICE pDevice
    )
{
  //  //DEBUGMSG (ZONE_DRIVER, (TEXT("PCI_PowerDown(%08x)\r\n"), pDevice));

//    pDevice->PowerDown();
}


// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
POPENHANDLE
PCI_Open(
    HDEVICE pDevice, 
    DWORD dwAccess, 
    DWORD dwShareMode
    )
{ POPENHANDLE pHandle;

    ////DEBUGMSG (ZONE_DRIVER, (TEXT("PCI_Open(0x%X)\r\n"), pDevice));

    pHandle = new OPENHANDLE;
    if (pHandle != NULL) {
        pHandle->hDriver = pDevice;
    }
    return pHandle;
}



// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
BOOL
PCI_Close(
    POPENHANDLE pOpenHandle
    )
{
    //  //DEBUGMSG (ZONE_DRIVER, (TEXT("PCI_Close(0x%X)\r\n"), pOpenHandle));

    LocalFree(pOpenHandle);
    return TRUE;
}



// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
DWORD
PCI_Read(
    POPENHANDLE pOpenHandle,
    LPVOID pBuf, 
    DWORD Len
    )
{
  //  //DEBUGMSG (ZONE_DRIVER, (TEXT("PCI_Read(0x%X, 0x%X, %d)\r\n"), pOpenHandle, pBuf, Len));

    // Return length read
    return 0;
}




// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
DWORD
PCI_Write(
    POPENHANDLE pOpenHandle,
    LPCVOID pBuf, 
    DWORD Len
    )
{
  //  //DEBUGMSG (ZONE_DRIVER, (TEXT("PCI_Write(0x%X, 0x%X, %d)\r\n"), pOpenHandle, pBuf, Len));

    // return number of bytes written (or -1 for error)
    return 0;
}



// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
DWORD
PCI_Seek(
    POPENHANDLE pOpenHandle,
    long pos, 
    DWORD type
    )
{
    //  //DEBUGMSG (ZONE_DRIVER, (TEXT("PCI_Seek(0x%X, %d, %d)\r\n"), pOpenHandle,pos, type));

    // return an error
    return (DWORD)-1;
}


// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
BOOL
PCI_IOControl(
    POPENHANDLE pOpenHandle, 
    DWORD  dwCode, 
    PVOID pBufIn,
    DWORD  dwLenIn, 
    PDWORD  pdwBufOut, 
    DWORD  dwLenOut,
    PDWORD pdwActualOut
    )
{ 

	HDEVICE pDevice = pOpenHandle->hDriver;

    switch (dwCode)
    {
      case IOCTL_HAL_PCI_READ_REGISTER:
		  {
			  *pdwBufOut = pDevice->ReadRegister(*(PDWORD)pBufIn);
			  dwLenOut = sizeof(*pdwBufOut);
			  break;
		  }
      case IOCTL_HAL_PCI_WRITE_REGISTER:
		  {
			  pDevice->WriteRegister(((CHIIOCWriteDWord *)pBufIn)->GetdwAddress(),((CHIIOCWriteDWord *)pBufIn)->GetdwValue());
			  pdwBufOut = NULL;
			  dwLenOut = 0;
			  break;
		  }
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
      // set the RSM address (stream buffer and process image)
      case IOCTL_HAL_PCI_SET_RSM_ADDRESS:
      // clear the RSM address (stream buffer and process image)
      case IOCTL_HAL_PCI_CLEAR_RSM_ADDRESS:
      // stops the wedge drive immediately
      case IOCTL_HAL_PCI_WC_EMERGENCY_STOP:
      // gets the actual wedge velocity (Wdg_Act_Vlc)
      case IOCTL_HAL_PCI_WC_GET_ACT_VELOCITY:
      // gets the last wedge velocity (Wdg_Last_Vlc)
      case IOCTL_HAL_PCI_WC_GET_LAST_VELOCITY:
      // gets the wedge position (Wdg_Pos)
      case IOCTL_HAL_PCI_WC_GET_POSITION:
      // sets the wedge DAC value (Wdg_Volt)
      case IOCTL_HAL_PCI_WC_SET_DAC:
      // switches on/off wedge controller
      case IOCTL_HAL_PCI_WC_CONTROLLER:
      // light barrier state
      case IOCTL_HAL_PCI_WC_LB_STATE:
      // wedge controller ocsilloscope
      case IOCTL_HAL_PCI_SET_BUFFERSIZE:
      // mask the HW and WC event register
      case IOCTL_HAL_PCI_WC_MASK_EVENT_REG:
      // acknowledge the ISR event signalisation
      case IOCTL_HAL_PCI_ACK_EVENT:
      // notify the ISR to send an event
      case IOCTL_HAL_PCI_WC_SEND_EVENT:
          {
            if (!pDevice->KLibIoControl(dwCode, pBufIn, dwLenIn, pdwBufOut, dwLenOut, NULL)) {
                return FALSE;
            }
            break;
          }

      // checks the driver state
      case IOCTL_HAL_PCI_DRIVER_READY:
        {
          // returns device SYSINTR
          *pdwBufOut = pDevice->GetSysIntr();
  			  dwLenOut = sizeof(DWORD);

          return TRUE;
        }
      // clears the WC ISR
      case IOCTL_HAL_PCI_WCISR_CLEAR:
        {
          pDevice->ClearInt();
			    pdwBufOut = NULL;
			    dwLenOut = 0;
          return TRUE;
        }
      // Enables the WC ISR
      case IOCTL_HAL_PCI_WCISR_ENABLE:
        {
          pDevice->EnableInt();
			    pdwBufOut = NULL;
			    dwLenOut = 0;
          return TRUE;
        }

      // Disables the WC ISR
      case IOCTL_HAL_PCI_WCISR_DISABLE:
        {
          pDevice->DisableInt();
			    pdwBufOut = NULL;
			    dwLenOut = 0;
          return TRUE;
        }
      // Starts the data acquisition  (IFM and Laser)
      case IOCTL_HAL_PCI_DATA_ON:
        {
          if (!pDevice->KLibIoControl(dwCode, pBufIn, dwLenIn, NULL, 0, NULL)) {
              return FALSE;
          }
          break;
        }
      // Stops the data acquisition  (IFM and Laser)
      case IOCTL_HAL_PCI_DATA_OFF:
        {
          if (!pDevice->KLibIoControl(dwCode, pBufIn, dwLenIn, NULL, 0, NULL)) {
              return FALSE;
          }
          break;
        }
      // disables HW watchdog
      case IOCTL_HAL_PCI_WD_DISABLE:
        {
          pDevice->DisableWatchdog();
			    pdwBufOut = NULL;
			    dwLenOut = 0;
          return TRUE;
        }
      // enables HW watchdog
      case IOCTL_HAL_PCI_WD_REFRESH:
        {
          pDevice->RefreshWatchdog(*(PDWORD)pBufIn);
			    pdwBufOut = NULL;
			    dwLenOut = 0;
          return TRUE;
        }
      default:
        // Unrecognized IOCTL
        *pdwBufOut = PCI_ERROR_INVALID_FUNCTION;
	      dwLenOut = sizeof(*pdwBufOut);
		    return FALSE;
      }
	return TRUE;
}
