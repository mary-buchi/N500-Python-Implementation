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
//
//  Module Name:  
//  
//      pcidrv.h
//  
//  Abstract:  
//  
//  Functions:
//  
//  Notes:
//  
// -----------------------------------------------------------------------------
#ifndef __PCIDRV_H__
#define __PCIDRV_H__


//
// Includes common to all the wave driver files.
//
#include <windows.h>
//#include <oemkfuncs.h>

#include <pci_buchi.h>
#include <mmddk.h>
#include <mmreg.h>
#include "debug.h"
#include "cregkey.h"
#include "xc2s200.h"

#define DEVICE_NAME     L"M&F ME1400"
#define DRIVER_VERSION  0x100

void CalibrateStallCounter (void);

#define MMFAILED(mmresult) ((mmresult)!=MMSYSERR_NOERROR)

typedef class CDriverContext * PDriverContext, * HDRIVER;

/////////////////////////////////////////////////////////////////////////////
// class: CDriverContext
// Driver Context Data
//
// This class abstracts the notion of a device driver instance. Each instance 
// of the driver (WAV1, WAV2) gets one of these.
// A fully general driver that supports multiple physical devices (e.g. two
// separate PCI cards, one appearing as WAV1 and the other as WAV2) 
// should create separate CDriverContext objects for each driver instance.
// 
// There's an important distinction between physical devices that are exposed to
// the Device Manager and separate waveform devices as understood by
// the waveform API. Consider the hypothetical case of a PCI audio adapter
// that has two separate stereo channels (e.g. Speaker A, Speaker B).
// The Windows CE Device Manager will view this a single physical device
// but the waveform API will treat each speaker set a separate waveform
// device.
// 
/////////////////////////////////////////////////////////////////////////////
class CDriverContext
{
public:
    CDriverContext (void);
    ~CDriverContext ();
    DWORD       PCIBuchiMessage(PPCI_BUCHI_MESSAGE pParams);
    BOOL     Initialize (PCTSTR pszActiveKey);

    // power management support
    void PowerUp (void);
    void PowerDown (void);
	DWORD __inline ReadRegister (DWORD AdrOffset) { return m_pDevice->ReadRegister(AdrOffset); }
	void __inline WriteRegister (DWORD AdrOffset, DWORD val) { m_pDevice->WriteRegister(AdrOffset,val); }


private:
// Device configuration
    CRegKey * m_pRegKey;
    XC2S200 *       m_pDevice;
    MYTHIS_DECLARATION;
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

#endif // __PCIDRV_H__
