//## begin module%3E59DEEF0109.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E59DEEF0109.cm

//## begin module%3E59DEEF0109.cp preserve=no
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
//## end module%3E59DEEF0109.cp

//## Module: EBHIrsm%3E59DEEF0109; Package body
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIrsm.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E59DEEF0109.additionalIncludes preserve=no
//## end module%3E59DEEF0109.additionalIncludes

//## begin module%3E59DEEF0109.includes preserve=yes
//## end module%3E59DEEF0109.includes

// EBHIrsm
#include "EBHIrsm.h"
// EBHIexcp
#include "EBHIexcp.h"
// EBHIident
#include "EBHIident.h"
// EBHITrsm
#include "EBHITrsm.h"
// EBHITtype
#include "EBHITtype.h"


//## begin module%3E59DEEF0109.declarations preserve=no
//## end module%3E59DEEF0109.declarations

//## begin module%3E59DEEF0109.additionalDeclarations preserve=yes
#ifdef _WIN32_WCE
  #include <pkfuncs.h>
#endif
//## end module%3E59DEEF0109.additionalDeclarations


// Class CHIReservedSharedMemory 

//## begin CHIReservedSharedMemory::pVAdrStreamBuffer%3E661B6E03BA.role preserve=no  public: static DWORD {1..1 -> 1..1RFHN}
DWORD *CHIReservedSharedMemory::m_pVAdrStreamBuffer = NULL;
//## end CHIReservedSharedMemory::pVAdrStreamBuffer%3E661B6E03BA.role

//## begin CHIReservedSharedMemory::pVAdrProcessImage%3E67212002C0.role preserve=no  public: static DWORD {1..1 -> 1..1RFHN}
DWORD *CHIReservedSharedMemory::m_pVAdrProcessImage = NULL;
//## end CHIReservedSharedMemory::pVAdrProcessImage%3E67212002C0.role

CHIReservedSharedMemory::CHIReservedSharedMemory()
  //## begin CHIReservedSharedMemory::CHIReservedSharedMemory%.hasinit preserve=no
  //## end CHIReservedSharedMemory::CHIReservedSharedMemory%.hasinit
  //## begin CHIReservedSharedMemory::CHIReservedSharedMemory%.initialization preserve=yes
  //## end CHIReservedSharedMemory::CHIReservedSharedMemory%.initialization
{
  //## begin CHIReservedSharedMemory::CHIReservedSharedMemory%.body preserve=yes
  //## end CHIReservedSharedMemory::CHIReservedSharedMemory%.body
}


CHIReservedSharedMemory::~CHIReservedSharedMemory()
{
  //## begin CHIReservedSharedMemory::~CHIReservedSharedMemory%.body preserve=yes
  //## end CHIReservedSharedMemory::~CHIReservedSharedMemory%.body
}



//## Other Operations (implementation)
void CHIReservedSharedMemory::AllocRSMProcessImage (DWORD p_dwMemorySize)
{
  //## begin CHIReservedSharedMemory::AllocRSMProcessImage%1046077270.body preserve=yes
#ifdef _WIN32_WCE
    // allocate buffre for the process image
    DWORD l_dwError = 0;
    DWORD l_dwProcessImageSize = 0;
    BOOL l_bRetVal = FALSE;
    LPVOID l_pVAdr = NULL;

    l_dwProcessImageSize = CHITReservedSharedMemory::GetcdwProcessImageSizeInByte(); // size in bytes
    l_pVAdr = VirtualAlloc(0,                    // determines where to allocate the region
                           l_dwProcessImageSize, // size in bytes
                           MEM_RESERVE,          // Reserves a range of the virtual address space of the process without allocating any physical storage               
                           PAGE_NOACCESS);       // Disables all access to the committed region of pages

    CO_TRACE1(HI_ID, _T("EBHI - AllocRSMProcessImage() VirtualAlloc reservation 0x%8.8lx\r\n"), l_pVAdr);

    if (!l_pVAdr)
    {
      l_dwError = GetLastError();
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_ALLOC_PROCESSIMAGE_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }

    LPVOID l_pPAdr = CHITReservedSharedMemory::GetclpPhysAdrProcessImage();
    
    l_bRetVal = VirtualCopy(l_pVAdr,                        // destination memory
                            l_pPAdr, // pointer to the committed memory
                            l_dwProcessImageSize,           // size in bytes
                            PAGE_READWRITE | PAGE_NOCACHE ); // no caching, read / write access

    m_pVAdrProcessImage = (DWORD*)l_pVAdr;
    CO_TRACE1(HI_ID, _T("EBHI - AllocRSMProcessImage() VirtualCopy returned: %d\r\n"), l_bRetVal);

    if (!l_bRetVal)
    {
      l_dwError = GetLastError();
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_ALLOC_PROCESSIMAGE_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }

    // clear virtual memory
    ZeroMemory(l_pVAdr, l_dwProcessImageSize);

    CO_TRACE(HI_ID, _T("EBHI - AllocRSMProcessImage() virtual ProcessImage address is mapped to the phys. memory.\r\n"));    
#endif
  //## end CHIReservedSharedMemory::AllocRSMProcessImage%1046077270.body
}

void CHIReservedSharedMemory::DeAllocRSMProcessImage ()
{
  //## begin CHIReservedSharedMemory::DeAllocRSMProcessImage%1046077271.body preserve=yes
#ifdef _WIN32_WCE
    DWORD l_dwError = 0;
    BOOL l_bRetVal = FALSE;

    l_bRetVal = VirtualFree((LPVOID)m_pVAdrProcessImage,  // base address of the region of pages to be freed
                            0,                    // size in bytes must be 0
                            MEM_RELEASE);         // type of free operation
    
    if (!l_bRetVal)
    {
      l_dwError = GetLastError();
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_ALLOC_PROCESSIMAGE_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }

    CO_TRACE(HI_ID, _T("EBHI - DeAllocRSMProcessImage() virtual Process Image is released.\r\n"));    
#endif
  //## end CHIReservedSharedMemory::DeAllocRSMProcessImage%1046077271.body
}

void CHIReservedSharedMemory::AllocRSMStreamBuffer (DWORD p_dwMemorySize)
{
  //## begin CHIReservedSharedMemory::AllocRSMStreamBuffer%1046077272.body preserve=yes
#ifdef _WIN32_WCE
    // allocate stream buffer for IFM and Laser data
    DWORD l_dwError = 0;
    DWORD l_dwStreamBufferSize = 0;
    BOOL l_bRetVal = FALSE;
    LPVOID l_pVAdr = NULL;
    LPVOID l_pBase = NULL;

    l_dwStreamBufferSize = CHITReservedSharedMemory::GetcdwStreamBufferSizeInByte(); // size in bytes
    l_pVAdr = VirtualAlloc(0,                    // determines where to allocate the region
                           l_dwStreamBufferSize, // size in bytes
                           MEM_RESERVE,          // Reserves a range of the virtual address space of the process without allocating any physical storage               
                           PAGE_NOACCESS);       // Disables all access to the committed region of pages
    
    CO_TRACE1(HI_ID, _T("EBHI - AllocRSMStreamBuffer() VirtualAlloc reservation 0x%8.8lx\r\n"), l_pVAdr);

    if (!l_pVAdr)
    {
      l_dwError = GetLastError();
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_ALLOC_STREAMBUFFER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }

    LPVOID l_pPAdr = CHITReservedSharedMemory::GetclpPhysAdrStreamBuffer();
    l_bRetVal = VirtualCopy(l_pVAdr,            // destination memory
                            l_pPAdr, // pointer to the committed memory
                            l_dwStreamBufferSize,           // size in bytes
                            PAGE_READWRITE | PAGE_NOCACHE); // no caching, read / write access

    m_pVAdrStreamBuffer = (DWORD*)l_pVAdr;

    CO_TRACE1(HI_ID, _T("EBHI - AllocRSMStreamBuffer() VirtualCopy returned: %d\r\n"), l_bRetVal);

    if (!l_bRetVal)
    {
      l_dwError = GetLastError();
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_ALLOC_STREAMBUFFER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }


    FillMemory(l_pVAdr, l_dwStreamBufferSize, 0x0);

    CO_TRACE(HI_ID,_T("EBHI - AllocRSMStreamBuffer() virtual StreamBuffer address is mapped to the phys. memory\r\n"));    
#endif
  //## end CHIReservedSharedMemory::AllocRSMStreamBuffer%1046077272.body
}

void CHIReservedSharedMemory::DeAllocRSMStreamBuffer ()
{
  //## begin CHIReservedSharedMemory::DeAllocRSMStreamBuffer%1046077273.body preserve=yes
#ifdef _WIN32_WCE
    DWORD l_dwError = 0;
    DWORD l_dwStreamBufferSize = 0;
    BOOL l_bRetVal = FALSE;

    l_bRetVal = VirtualFree((LPVOID)m_pVAdrStreamBuffer,  // base address of the region of pages to be freed
                            0,                    // size in bytes must be 0
                            MEM_RELEASE);         // type of free operation
    
    if (!l_bRetVal)
    {
      l_dwError = GetLastError();
      throw new XHIExceptionError(HI_ID, IDE_HW_INTF_ALLOC_STREAMBUFFER_ERROR, _T(__FILE__), __LINE__, l_dwError);
    }

    CO_TRACE(HI_ID,_T("EBHI - DeAllocRSMStreamBuffer() virtual StreamBuffer is released.\r\n"));    
#endif
  //## end CHIReservedSharedMemory::DeAllocRSMStreamBuffer%1046077273.body
}

//## Get and Set Operations for Associations (implementation)

DWORD * CHIReservedSharedMemory::GetpVAdrStreamBuffer ()
{
  //## begin CHIReservedSharedMemory::GetpVAdrStreamBuffer%3E661B6E03BA.get preserve=no
  return m_pVAdrStreamBuffer;
  //## end CHIReservedSharedMemory::GetpVAdrStreamBuffer%3E661B6E03BA.get
}

DWORD * CHIReservedSharedMemory::GetpVAdrProcessImage ()
{
  //## begin CHIReservedSharedMemory::GetpVAdrProcessImage%3E67212002C0.get preserve=no
  return m_pVAdrProcessImage;
  //## end CHIReservedSharedMemory::GetpVAdrProcessImage%3E67212002C0.get
}

// Additional Declarations
  //## begin CHIReservedSharedMemory%3E59DEAC029F.declarations preserve=yes
  //## end CHIReservedSharedMemory%3E59DEAC029F.declarations

//## begin module%3E59DEEF0109.epilog preserve=yes
//## end module%3E59DEEF0109.epilog
