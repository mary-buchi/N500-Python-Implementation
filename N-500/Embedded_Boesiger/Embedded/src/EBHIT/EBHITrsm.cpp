//## begin module%3E5499530138.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E5499530138.cm

//## begin module%3E5499530138.cp preserve=no
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
//## end module%3E5499530138.cp

//## Module: EBHITrsm%3E5499530138; Package body
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Source file: R:\Embedded\src\EBHIT\EBHITrsm.cpp

// stdafx
#include "stdafx.h"
//## begin module%3E5499530138.additionalIncludes preserve=no
//## end module%3E5499530138.additionalIncludes

//## begin module%3E5499530138.includes preserve=yes
//## end module%3E5499530138.includes

// EBHITrsm
#include "EBHITrsm.h"
// EBHITtype
#include "EBHITtype.h"


//## begin module%3E5499530138.declarations preserve=no
//## end module%3E5499530138.declarations

//## begin module%3E5499530138.additionalDeclarations preserve=yes
#ifdef _WIN32_WCE
#include <pkfuncs.h>
#endif


// RSM Reserved Shared Memory Stream Buffer for IFM and Laser Data 
// 
// Total Size:      0x1000000 (16MB)
// Size IFM Data:   0x0800000 (8MB)
// Size Laser Data: 0x0800000 (8MB)
//
//   OffsetAddress:    DWORD Value (MSB) 31 ............. 0 (LSB)            
// ------------------------------------------------------------------
//      00x0000000: start address (physical) ring buffer IFM Data
//      0x00000001: start address (virtual) ring buffer IFM Data
//      0x00000002: actual IFM Data size  
//      0x00000003: Reserve 
//      0x00000004: Reserve 
//      0x00000005: Reserve
//      0x00000006: Reserve
//      0x00000007: Reserve
//      0x00000008: START - ring buffer IFM Data
//      0x00000009:   :
//      0x0000000A:   :
//      0x0000000x:   :
//      0x000000xx:   :
//      0x00000xxx:   :
//      0x007FFFFF: END - ring buffer IFM Data
// -------------------------------------------------------------------
//      0x00800000: start address (physical) ring buffer Laser Data
//      0x00800001: start address (virtual) ring buffer Laser Data
//      0x00800002: actual Laser Data size 
//      0x00800003: Reserve 
//      0x00800004: Reserve 
//      0x00800005: Reserve
//      0x00800006: Reserve
//      0x00800007: Reserve
//      0x00800008: START - ring buffer Laser Data
//      0x00800009:   :
//      0x0080000A:   :
//      0x0080000x:   :
//      0x008000xx:   :
//      0x00800xxx:   :
//      0x00FFFFFF: END - ring buffer Laser Data
//////////////////////////////////////////////////////////////////////////////////////////////////
// Stream Data
//
//       MSB                    LSB
//        |                      |
//      0x00000000 0000 ..... 0000  
//        |||||||| |-------------|
//        ||||||||        |-------  0 .. 23: IFM- / Laser Data 24 Bit 
//        |||||||| 
//        ||||||| ----------------  24: Reserve
//        |||||||-----------------  25: Reserve  
//        |||||| -----------------  26: Reserve
//        |||||-------------------  27: Reserve
//        ||||--------------------  28: Reserve
//        |||---------------------  29: Overflow (Stream Buffer Overflow)
//        ||----------------------  30: Backward Direction
//        |-----------------------  31: Forward Direction
//
//


//////////////////////////////////////////////////////////////////////////////////////////////////
// RSM Reserved Shared Memory Process Image
// 
// Total Size:                  0x0200000 (2MB)
// Process Image Read Buffer:   0x0100000 (1MB) (Read  -> Data from HW)
// Process Image Write Buffer:  0x0100000 (1MB) (Write -> Data to HW)
//
// READ BUFFER:
//   OffsetAddress:    DWORD Value (MSB) 31 ............. 0 (LSB)            
// ------------------------------------------------------------------
//      0x00000000: Reserved for System Register
//      0x0000000x: Reserved for System Register
//      0x000000xx: Reserved for System Register
//      0x00000140: Event I2C Bus
//      0x00000144: Event digital Input Onboard
//      0x00000148: Event digital Input MC
//      0x0000014C: Event Stepper Motor
//      0x00000150: Data .. 
//      0x00000154: Data ..
//      0x00000158: Data ..
//      0x0000015C: Data ..
//      0x00000160: Data ..
//      0x00000164: Data ..
//      0x00000168: Data ..
//      0x000001xx:   :
//      0x00000xxx:   :
//      0x000FFFFF: END - read buffer process image

// -------------------------------------------------------------------
// WRITE BUFFER:
//   OffsetAddress:    DWORD Value (MSB) 31 ............. 0 (LSB)            
// ------------------------------------------------------------------
//      0x00100000: Reserved for System Register
//      0x0010000x: Reserved for System Register
//      0x001000xx: Reserved for System Register
//      0x00100140: Valid Register 1
//      0x00100144: Valid Register 2 
//      0x00100148: Valid Register 3
//      0x0010014C: Valid Register Stepper Motors
//      0x00100150:   :
//      0x00100154:   :
//      0x0010000x:   :
//      0x001000xx:   :
//      0x00100xxx:   :
//      0x001FFFFF: END - write buffer process image


//## end module%3E5499530138.additionalDeclarations


// Class CHITReservedSharedMemory 

//## begin CHITReservedSharedMemory::clpPhysAdrStreamBuffer%3E6708A100BB.attr preserve=no  public: static LPVOID {UC} (LPVOID)0x80420000
const LPVOID  CHITReservedSharedMemory::m_clpPhysAdrStreamBuffer = (LPVOID)0x80420000;
//## end CHITReservedSharedMemory::clpPhysAdrStreamBuffer%3E6708A100BB.attr

//## begin CHITReservedSharedMemory::clpPhysAdrProcessImage%3E6708D20290.attr preserve=no  public: static LPVOID {UC} (LPVOID)0x80220000
const LPVOID  CHITReservedSharedMemory::m_clpPhysAdrProcessImage = (LPVOID)0x80220000;
//## end CHITReservedSharedMemory::clpPhysAdrProcessImage%3E6708D20290.attr

//## begin CHITReservedSharedMemory::cdwStreamBufferSizeInByte%3E6709DE01A5.attr preserve=no  public: static DWORD {UC} 0x1000000
const DWORD  CHITReservedSharedMemory::m_cdwStreamBufferSizeInByte = 0x1000000;
//## end CHITReservedSharedMemory::cdwStreamBufferSizeInByte%3E6709DE01A5.attr

//## begin CHITReservedSharedMemory::cdwProcessImageSizeInByte%3E670A940119.attr preserve=no  public: static DWORD {UC} 0x200000
const DWORD  CHITReservedSharedMemory::m_cdwProcessImageSizeInByte = 0x200000;
//## end CHITReservedSharedMemory::cdwProcessImageSizeInByte%3E670A940119.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetSbLaserData%3E676BE00000.attr preserve=no  public: static DWORD {UC} 0x200000
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetSbLaserData = 0x200000;
//## end CHITReservedSharedMemory::cdwAdrOffsetSbLaserData%3E676BE00000.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetSbIsrData%3E676DD7032C.attr preserve=no  public: static DWORD {UC} 0x0
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetSbIsrData = 0x0;
//## end CHITReservedSharedMemory::cdwAdrOffsetSbIsrData%3E676DD7032C.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetSbData%3E676E7F0399.attr preserve=no  public: static DWORD {UC} 0x1
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetSbData = 0x1;
//## end CHITReservedSharedMemory::cdwAdrOffsetSbData%3E676E7F0399.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetDataSize%3E676EC2035B.attr preserve=no  public: static DWORD {UC} 0x2
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetDataSize = 0x2;
//## end CHITReservedSharedMemory::cdwAdrOffsetDataSize%3E676EC2035B.attr

//## begin CHITReservedSharedMemory::cdwFirstDataAdr%3E684AE6002E.attr preserve=no  public: static DWORD {UC} 0x8
const DWORD  CHITReservedSharedMemory::m_cdwFirstDataAdr = 0x8;
//## end CHITReservedSharedMemory::cdwFirstDataAdr%3E684AE6002E.attr

//## begin CHITReservedSharedMemory::dwIFMTotalBufferSize%3E6C5AAB0280.attr preserve=no  public: static DWORD {U} 
DWORD CHITReservedSharedMemory::m_dwIFMTotalBufferSize;
//## end CHITReservedSharedMemory::dwIFMTotalBufferSize%3E6C5AAB0280.attr

//## begin CHITReservedSharedMemory::dwLaserTotalBufferSize%3E6C5D7B0290.attr preserve=no  public: static DWORD {U} 
DWORD CHITReservedSharedMemory::m_dwLaserTotalBufferSize;
//## end CHITReservedSharedMemory::dwLaserTotalBufferSize%3E6C5D7B0290.attr

//## begin CHITReservedSharedMemory::dwIFMDataBufferSizeInByte%3EAE7EF90232.attr preserve=no  public: static DWORD {U} 
DWORD CHITReservedSharedMemory::m_dwIFMDataBufferSizeInByte;
//## end CHITReservedSharedMemory::dwIFMDataBufferSizeInByte%3EAE7EF90232.attr

//## begin CHITReservedSharedMemory::dwLaserDataBufferSizeInByte%3EAE7EFB0399.attr preserve=no  public: static DWORD {U} 
DWORD CHITReservedSharedMemory::m_dwLaserDataBufferSizeInByte;
//## end CHITReservedSharedMemory::dwLaserDataBufferSizeInByte%3EAE7EFB0399.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetProcImIFMData%3FFEBCFF007D.attr preserve=no  public: static DWORD {UC} 0x300
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetProcImIFMData = 0x300;
//## end CHITReservedSharedMemory::cdwAdrOffsetProcImIFMData%3FFEBCFF007D.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetProcImLaserData%3FFEBCD2004E.attr preserve=no  public: static DWORD {UC} 0x320
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetProcImLaserData = 0x320;
//## end CHITReservedSharedMemory::cdwAdrOffsetProcImLaserData%3FFEBCD2004E.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetReadData%3F7BC03502BF.attr preserve=no  public: static DWORD {UC} 0x0
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetReadData = 0x0;
//## end CHITReservedSharedMemory::cdwAdrOffsetReadData%3F7BC03502BF.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetWriteData%3EBA4636036B.attr preserve=no  public: static DWORD {UC} 0x100000
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetWriteData = 0x100000;
//## end CHITReservedSharedMemory::cdwAdrOffsetWriteData%3EBA4636036B.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetUserReadData%3F798D5101E4.attr preserve=no  public: static DWORD {UC} 0x140
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetUserReadData = 0x140;
//## end CHITReservedSharedMemory::cdwAdrOffsetUserReadData%3F798D5101E4.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetUserWriteData%3F794B83036B.attr preserve=no  public: static DWORD {UC} 0x140
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetUserWriteData = 0x140;
//## end CHITReservedSharedMemory::cdwAdrOffsetUserWriteData%3F794B83036B.attr

//## begin CHITReservedSharedMemory::cdwNumbersOfWCEventReg%3ECC8E720251.attr preserve=no  public: static DWORD {UC} EBHIT_NUMBER_OF_WC_EVENT_REG
const DWORD  CHITReservedSharedMemory::m_cdwNumbersOfWCEventReg = EBHIT_NUMBER_OF_WC_EVENT_REG;
//## end CHITReservedSharedMemory::cdwNumbersOfWCEventReg%3ECC8E720251.attr

//## begin CHITReservedSharedMemory::cdwNumbersOfHWExceptionReg%3EBFAA64007D.attr preserve=no  public: static DWORD {UC} 0x1
const DWORD  CHITReservedSharedMemory::m_cdwNumbersOfHWExceptionReg = 0x1;
//## end CHITReservedSharedMemory::cdwNumbersOfHWExceptionReg%3EBFAA64007D.attr

//## begin CHITReservedSharedMemory::cdwNumbersOfDigInputEventReg%3EBFAAAF0148.attr preserve=no  public: static DWORD {UC} EBHIT_NUMBER_OF_DI_EVENT_REG
const DWORD  CHITReservedSharedMemory::m_cdwNumbersOfDigInputEventReg = EBHIT_NUMBER_OF_DI_EVENT_REG;
//## end CHITReservedSharedMemory::cdwNumbersOfDigInputEventReg%3EBFAAAF0148.attr

//## begin CHITReservedSharedMemory::cdwNumbersOfEventReg%3F7D10A50203.attr preserve=no  public: static DWORD {UC} EBHIT_NUMBER_OF_HW_EVENT_REG
const DWORD  CHITReservedSharedMemory::m_cdwNumbersOfEventReg = EBHIT_NUMBER_OF_HW_EVENT_REG;
//## end CHITReservedSharedMemory::cdwNumbersOfEventReg%3F7D10A50203.attr

//## begin CHITReservedSharedMemory::cdwNumbersOfStepperEventReg%3F8B959502EE.attr preserve=no  public: static DWORD {UC} 0x1
const DWORD  CHITReservedSharedMemory::m_cdwNumbersOfStepperEventReg = 0x1;
//## end CHITReservedSharedMemory::cdwNumbersOfStepperEventReg%3F8B959502EE.attr

//## begin CHITReservedSharedMemory::cdwNumbersOfDataValidReg%3F33907C00AB.attr preserve=no  public: static DWORD {UC} 0x4
const DWORD  CHITReservedSharedMemory::m_cdwNumbersOfDataValidReg = 0x4;
//## end CHITReservedSharedMemory::cdwNumbersOfDataValidReg%3F33907C00AB.attr

//## begin CHITReservedSharedMemory::cdwNumbersOfI2CData%40924171037A.attr preserve=no  public: static DWORD {UC} 0x40
const DWORD  CHITReservedSharedMemory::m_cdwNumbersOfI2CData = 0x40;
//## end CHITReservedSharedMemory::cdwNumbersOfI2CData%40924171037A.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetEventReg%3F7D24EE0177.attr preserve=no  public: static DWORD {UC} 0x140
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetEventReg = 0x140;
//## end CHITReservedSharedMemory::cdwAdrOffsetEventReg%3F7D24EE0177.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetHWExceptionReg%3ECC8FD1002E.attr preserve=no  public: static DWORD {UC} 0x408
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetHWExceptionReg = 0x408;
//## end CHITReservedSharedMemory::cdwAdrOffsetHWExceptionReg%3ECC8FD1002E.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetWCEventReg%3EC8DA5003C8.attr preserve=no  public: static DWORD {U} 0x400
DWORD CHITReservedSharedMemory::m_cdwAdrOffsetWCEventReg = 0x400;
//## end CHITReservedSharedMemory::cdwAdrOffsetWCEventReg%3EC8DA5003C8.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetDigInputEventReg%3EBFABBF03A9.attr preserve=no  public: static DWORD {UC} 0x144
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetDigInputEventReg = 0x144;
//## end CHITReservedSharedMemory::cdwAdrOffsetDigInputEventReg%3EBFABBF03A9.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetDigInputReg%3ECB939E008C.attr preserve=no  public: static DWORD {UC} 0x170
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetDigInputReg = 0x170;
//## end CHITReservedSharedMemory::cdwAdrOffsetDigInputReg%3ECB939E008C.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetDigInputRaisingEdgeReg%3FE013CB0251.attr preserve=no  public: static DWORD {UC} 0x410
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetDigInputRaisingEdgeReg = 0x410;
//## end CHITReservedSharedMemory::cdwAdrOffsetDigInputRaisingEdgeReg%3FE013CB0251.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetDigInputTrailingEdgeReg%3FE0186700FA.attr preserve=no  public: static DWORD {UC} 0x418
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetDigInputTrailingEdgeReg = 0x418;
//## end CHITReservedSharedMemory::cdwAdrOffsetDigInputTrailingEdgeReg%3FE0186700FA.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetDigOutputReg%3FB3445002AF.attr preserve=no  public: static DWORD {UC} 0x170
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetDigOutputReg = 0x170;
//## end CHITReservedSharedMemory::cdwAdrOffsetDigOutputReg%3FB3445002AF.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetStepperEventReg%3F8B95D400DA.attr preserve=no  public: static DWORD {UC} 0x14C
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetStepperEventReg = 0x14C;
//## end CHITReservedSharedMemory::cdwAdrOffsetStepperEventReg%3F8B95D400DA.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetDataValidReg%3F33900901D4.attr preserve=no  public: static DWORD {UC} 0x140
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetDataValidReg = 0x140;
//## end CHITReservedSharedMemory::cdwAdrOffsetDataValidReg%3F33900901D4.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetWedgePos%3F8CE6B003C8.attr preserve=no  public: static DWORD {UC} 0x184
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetWedgePos = 0x184;
//## end CHITReservedSharedMemory::cdwAdrOffsetWedgePos%3F8CE6B003C8.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetWedgeActVelocity%3F8CE6EB02DE.attr preserve=no  public: static DWORD {UC} 0x188
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetWedgeActVelocity = 0x188;
//## end CHITReservedSharedMemory::cdwAdrOffsetWedgeActVelocity%3F8CE6EB02DE.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetWedgeLastVelocity%3F8CE6ED01B5.attr preserve=no  public: static DWORD {UC} 0x18C
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetWedgeLastVelocity = 0x18C;
//## end CHITReservedSharedMemory::cdwAdrOffsetWedgeLastVelocity%3F8CE6ED01B5.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetWedgeWriteReg%3F8CED05031C.attr preserve=no  public: static DWORD {UC} 0x17C
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetWedgeWriteReg = 0x17C;
//## end CHITReservedSharedMemory::cdwAdrOffsetWedgeWriteReg%3F8CED05031C.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetI2CWriteReg%3FD9D2BA0280.attr preserve=no  public: static DWORD {UC} 0x200
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetI2CWriteReg = 0x200;
//## end CHITReservedSharedMemory::cdwAdrOffsetI2CWriteReg%3FD9D2BA0280.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetI2CReadReg%3FD9D2ED03C8.attr preserve=no  public: static DWORD {UC} 0x200
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetI2CReadReg = 0x200;
//## end CHITReservedSharedMemory::cdwAdrOffsetI2CReadReg%3FD9D2ED03C8.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetNumberOfWCScanReg%4002595E02AF.attr preserve=no  public: static DWORD {UC} 0x430
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetNumberOfWCScanReg = 0x430;
//## end CHITReservedSharedMemory::cdwAdrOffsetNumberOfWCScanReg%4002595E02AF.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetCurLaserDet%4003EA5801D4.attr preserve=no  public: static DWORD {UC} 0x190
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetCurLaserDet = 0x190;
//## end CHITReservedSharedMemory::cdwAdrOffsetCurLaserDet%4003EA5801D4.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetLampCtrl%41415A7A0399.attr preserve=no  public: static DWORD {UC} 0x178
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetLampCtrl = 0x178;
//## end CHITReservedSharedMemory::cdwAdrOffsetLampCtrl%41415A7A0399.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetLampCurr%41415B1300BB.attr preserve=no  public: static DWORD {UC} 0x178
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetLampCurr = 0x178;
//## end CHITReservedSharedMemory::cdwAdrOffsetLampCurr%41415B1300BB.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetLampPrimary%41415B4B0167.attr preserve=no  public: static DWORD {UC} 0x17C
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetLampPrimary = 0x17C;
//## end CHITReservedSharedMemory::cdwAdrOffsetLampPrimary%41415B4B0167.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetLampSecondary%41415B83006D.attr preserve=no  public: static DWORD {UC} 0x180
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetLampSecondary = 0x180;
//## end CHITReservedSharedMemory::cdwAdrOffsetLampSecondary%41415B83006D.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetActHwErrWarnState%41B07910005D.attr preserve=no  public: static DWORD {UC} 0x198
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetActHwErrWarnState = 0x198;
//## end CHITReservedSharedMemory::cdwAdrOffsetActHwErrWarnState%41B07910005D.attr

//## begin CHITReservedSharedMemory::cdwAdrOffsetHwErrWarnState%41B07978002E.attr preserve=no  public: static DWORD {UC} 0x440
const DWORD  CHITReservedSharedMemory::m_cdwAdrOffsetHwErrWarnState = 0x440;
//## end CHITReservedSharedMemory::cdwAdrOffsetHwErrWarnState%41B07978002E.attr

//## begin CHITReservedSharedMemory::cdwBitMaskWCInitialized%3EBFB73303A9.attr preserve=no  public: static DWORD {UC} 0x00000001
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskWCInitialized = 0x00000001;
//## end CHITReservedSharedMemory::cdwBitMaskWCInitialized%3EBFB73303A9.attr

//## begin CHITReservedSharedMemory::cdwBitMaskWCReferenced%3EBFB771033C.attr preserve=no  public: static DWORD {UC} 0x00000002
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskWCReferenced = 0x00000002;
//## end CHITReservedSharedMemory::cdwBitMaskWCReferenced%3EBFB771033C.attr

//## begin CHITReservedSharedMemory::cdwBitMaskWCException%3EBFB7980242.attr preserve=no  public: static DWORD {UC} 0x00000008
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskWCException = 0x00000008;
//## end CHITReservedSharedMemory::cdwBitMaskWCException%3EBFB7980242.attr

//## begin CHITReservedSharedMemory::cdwBitMaskWCStoped%3EC87E17035B.attr preserve=no  public: static DWORD {UC} 0x00000004
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskWCStoped = 0x00000004;
//## end CHITReservedSharedMemory::cdwBitMaskWCStoped%3EC87E17035B.attr

//## begin CHITReservedSharedMemory::cdwBitMaskWCMeasuring%3EC8CF9B00AB.attr preserve=no  public: static DWORD {UC} 0x00000010
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskWCMeasuring = 0x00000010;
//## end CHITReservedSharedMemory::cdwBitMaskWCMeasuring%3EC8CF9B00AB.attr

//## begin CHITReservedSharedMemory::cdwBitMaskForwardScan%3EBBB5EE0203.attr preserve=no  public: static DWORD {UC} 0x80000000
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskForwardScan = 0x80000000;
//## end CHITReservedSharedMemory::cdwBitMaskForwardScan%3EBBB5EE0203.attr

//## begin CHITReservedSharedMemory::cdwBitMaskBackwardScan%3EBBB62B032C.attr preserve=no  public: static DWORD {UC} 0x40000000
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskBackwardScan = 0x40000000;
//## end CHITReservedSharedMemory::cdwBitMaskBackwardScan%3EBBB62B032C.attr

//## begin CHITReservedSharedMemory::cdwBitMaskDataBufferOverflow%3EBBB6450148.attr preserve=no  public: static DWORD {UC} 0x20000000
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskDataBufferOverflow = 0x20000000;
//## end CHITReservedSharedMemory::cdwBitMaskDataBufferOverflow%3EBBB6450148.attr

//## begin CHITReservedSharedMemory::cdwBitMaskHWError%3EBBB67603D8.attr preserve=no  public: static DWORD {UC} 0x10000000
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskHWError = 0x10000000;
//## end CHITReservedSharedMemory::cdwBitMaskHWError%3EBBB67603D8.attr

//## begin CHITReservedSharedMemory::cdwBitMaskWCEnable%3F8CED8E0290.attr preserve=no  public: static DWORD {UC} 0x00000020
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskWCEnable = 0x00000020;
//## end CHITReservedSharedMemory::cdwBitMaskWCEnable%3F8CED8E0290.attr

//## begin CHITReservedSharedMemory::cdwBitMaskWCPosReset%3F8CEDED0128.attr preserve=no  public: static DWORD {UC} 0x00000100
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskWCPosReset = 0x00000100;
//## end CHITReservedSharedMemory::cdwBitMaskWCPosReset%3F8CEDED0128.attr

//## begin CHITReservedSharedMemory::cdwBitMaskWCDirection%3F8CEE57032C.attr preserve=no  public: static DWORD {UC} 0x00000200
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskWCDirection = 0x00000200;
//## end CHITReservedSharedMemory::cdwBitMaskWCDirection%3F8CEE57032C.attr

//## begin CHITReservedSharedMemory::cdwBitMaskWCLightBarrier%3F8D073603C8.attr preserve=no  public: static DWORD {UC} 0x00010000
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskWCLightBarrier = 0x00010000;
//## end CHITReservedSharedMemory::cdwBitMaskWCLightBarrier%3F8D073603C8.attr

//## begin CHITReservedSharedMemory::cdwBitMaskWCDACValue%3F8D1163006D.attr preserve=no  public: static DWORD {UC} 0x0FFF0000
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskWCDACValue = 0x0FFF0000;
//## end CHITReservedSharedMemory::cdwBitMaskWCDACValue%3F8D1163006D.attr

//## begin CHITReservedSharedMemory::cdwBitMaskWCDACWakeUp%3FB3769D0167.attr preserve=no  public: static DWORD {UC} 0xFFFF0000
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskWCDACWakeUp = 0xFFFF0000;
//## end CHITReservedSharedMemory::cdwBitMaskWCDACWakeUp%3FB3769D0167.attr

//## begin CHITReservedSharedMemory::cdwBitMaskWCDigOutputs%3FB0F67A01A5.attr preserve=no  public: static DWORD {UC} 0x0000FFFF
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskWCDigOutputs = 0x0000FFFF;
//## end CHITReservedSharedMemory::cdwBitMaskWCDigOutputs%3FB0F67A01A5.attr

//## begin CHITReservedSharedMemory::cdwBitMaskWCActValue%3F990E1E01C5.attr preserve=no  public: static DWORD {UC} 0x000FFFFF
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskWCActValue = 0x000FFFFF;
//## end CHITReservedSharedMemory::cdwBitMaskWCActValue%3F990E1E01C5.attr

//## begin CHITReservedSharedMemory::cdwBitMaskLeadingSignWCPosition%3FAB6F460280.attr preserve=no  public: static DWORD {UC} 0x00080000
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskLeadingSignWCPosition = 0x00080000;
//## end CHITReservedSharedMemory::cdwBitMaskLeadingSignWCPosition%3FAB6F460280.attr

//## begin CHITReservedSharedMemory::cdwBitMaskPCNomVoltage%41415CCF01B5.attr preserve=no  public: static DWORD {UC} 0xFFF00000
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskPCNomVoltage = 0xFFF00000;
//## end CHITReservedSharedMemory::cdwBitMaskPCNomVoltage%41415CCF01B5.attr

//## begin CHITReservedSharedMemory::cdwBitMaskPCLampSel%41415E050177.attr preserve=no  public: static DWORD {UC} 0x00000002
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskPCLampSel = 0x00000002;
//## end CHITReservedSharedMemory::cdwBitMaskPCLampSel%41415E050177.attr

//## begin CHITReservedSharedMemory::cdwBitMaskPCActCurr%41415E3B032C.attr preserve=no  public: static DWORD {UC} 0x0000FFF0
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskPCActCurr = 0x0000FFF0;
//## end CHITReservedSharedMemory::cdwBitMaskPCActCurr%41415E3B032C.attr

//## begin CHITReservedSharedMemory::cdwBitMaskPCActVolt%41415E6F02FD.attr preserve=no  public: static DWORD {UC} 0x0000FFF0
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskPCActVolt = 0x0000FFF0;
//## end CHITReservedSharedMemory::cdwBitMaskPCActVolt%41415E6F02FD.attr

//## begin CHITReservedSharedMemory::cdwBitMaskPCOnOff%41415E8A03A9.attr preserve=no  public: static DWORD {UC} 0x1
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskPCOnOff = 0x1;
//## end CHITReservedSharedMemory::cdwBitMaskPCOnOff%41415E8A03A9.attr

//## begin CHITReservedSharedMemory::cdwBitMaskPCLampIdent%41416F67032C.attr preserve=no  public: static DWORD {UC} 0xFFF00000
const DWORD  CHITReservedSharedMemory::m_cdwBitMaskPCLampIdent = 0xFFF00000;
//## end CHITReservedSharedMemory::cdwBitMaskPCLampIdent%41416F67032C.attr

//## begin CHITReservedSharedMemory::cdwWCDACValueLeftShiftCounts%3F8CEF21035B.attr preserve=no  public: static DWORD {UC} 16
const DWORD  CHITReservedSharedMemory::m_cdwWCDACValueLeftShiftCounts = 16;
//## end CHITReservedSharedMemory::cdwWCDACValueLeftShiftCounts%3F8CEF21035B.attr

//## begin CHITReservedSharedMemory::cdwLeftShiftCntPCLampOnOff%41415BBA01A5.attr preserve=no  public: static DWORD {UC} 0
const DWORD  CHITReservedSharedMemory::m_cdwLeftShiftCntPCLampOnOff = 0;
//## end CHITReservedSharedMemory::cdwLeftShiftCntPCLampOnOff%41415BBA01A5.attr

//## begin CHITReservedSharedMemory::cdwLeftShiftCntPCLampSel%41415C0F01B5.attr preserve=no  public: static DWORD {UC} 1
const DWORD  CHITReservedSharedMemory::m_cdwLeftShiftCntPCLampSel = 1;
//## end CHITReservedSharedMemory::cdwLeftShiftCntPCLampSel%41415C0F01B5.attr

//## begin CHITReservedSharedMemory::cdwLeftShiftCntPCLampNomVoltage%41415C22029F.attr preserve=no  public: static DWORD {UC} 20
const DWORD  CHITReservedSharedMemory::m_cdwLeftShiftCntPCLampNomVoltage = 20;
//## end CHITReservedSharedMemory::cdwLeftShiftCntPCLampNomVoltage%41415C22029F.attr

//## begin CHITReservedSharedMemory::cdwLeftShiftCntPCLampActCurrent%41415C70001F.attr preserve=no  public: static DWORD {UC} 4
const DWORD  CHITReservedSharedMemory::m_cdwLeftShiftCntPCLampActCurrent = 4;
//## end CHITReservedSharedMemory::cdwLeftShiftCntPCLampActCurrent%41415C70001F.attr

//## begin CHITReservedSharedMemory::cdwLeftShiftCntPCLampActVoltage%41415C98002E.attr preserve=no  public: static DWORD {UC} 4
const DWORD  CHITReservedSharedMemory::m_cdwLeftShiftCntPCLampActVoltage = 4;
//## end CHITReservedSharedMemory::cdwLeftShiftCntPCLampActVoltage%41415C98002E.attr

//## begin CHITReservedSharedMemory::cdwLeftShiftCntPCLampIdent%41415CAE03B9.attr preserve=no  public: static DWORD {UC} 20
const DWORD  CHITReservedSharedMemory::m_cdwLeftShiftCntPCLampIdent = 20;
//## end CHITReservedSharedMemory::cdwLeftShiftCntPCLampIdent%41415CAE03B9.attr

//## begin CHITReservedSharedMemory::pVAdrStreamBuffer%3E59F2DD029F.role preserve=no  public: static DWORD {1..1 -> 1..1RFHN}
DWORD *CHITReservedSharedMemory::m_pVAdrStreamBuffer = NULL;
//## end CHITReservedSharedMemory::pVAdrStreamBuffer%3E59F2DD029F.role

//## begin CHITReservedSharedMemory::pVAdrProcessImage%3E6766240010.role preserve=no  public: static DWORD {1..1 -> 1..1RFHN}
DWORD *CHITReservedSharedMemory::m_pVAdrProcessImage = NULL;
//## end CHITReservedSharedMemory::pVAdrProcessImage%3E6766240010.role

//## begin CHITReservedSharedMemory::bBufferOverflow%43FDAA3C0050.role preserve=no  public: static bool {1..1 -> 1..1VFHN}
bool CHITReservedSharedMemory::m_bBufferOverflow = false;
//## end CHITReservedSharedMemory::bBufferOverflow%43FDAA3C0050.role


//## Other Operations (implementation)
void CHITReservedSharedMemory::InitInstance (DWORD* p_pVAdrStreamBuffer, DWORD* p_pVAdrProcessImage)
{
  //## begin CHITReservedSharedMemory::InitInstance%1046077274.body preserve=yes
	m_pVAdrStreamBuffer = p_pVAdrStreamBuffer;
	m_pVAdrProcessImage = p_pVAdrProcessImage;

	// sets the initial values (stream buffer)
	SetInitialStreamBufferData();

	// Total Stream Buffer Size (Byte) "m_cdwStreamBufferSizeInByte"
	SetNewStreamBufferSize();
  //## end CHITReservedSharedMemory::InitInstance%1046077274.body
}

void CHITReservedSharedMemory::DeleteInstance ()
{
  //## begin CHITReservedSharedMemory::DeleteInstance%1046077275.body preserve=yes
	m_pVAdrStreamBuffer = NULL;
	m_pVAdrProcessImage = NULL;
  //## end CHITReservedSharedMemory::DeleteInstance%1046077275.body
}

void CHITReservedSharedMemory::SetInitialStreamBufferData ()
{
  //## begin CHITReservedSharedMemory::SetInitialStreamBufferData%1070956919.body preserve=yes
	m_pVAdrStreamBuffer[m_cdwAdrOffsetSbIsrData]  = m_cdwFirstDataAdr;
	m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetSbIsrData] = m_cdwFirstDataAdr;
	m_pVAdrStreamBuffer[m_cdwAdrOffsetSbData]   = m_cdwFirstDataAdr;
	m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetSbData]  = m_cdwFirstDataAdr;
	m_pVAdrStreamBuffer[m_cdwAdrOffsetDataSize]      = 0;
	m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetDataSize]     = 0;
	m_bBufferOverflow = false;
  //## end CHITReservedSharedMemory::SetInitialStreamBufferData%1070956919.body
}

DWORD* CHITReservedSharedMemory::GetIFMDataVirtualStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetIFMDataVirtualStartAdr%1045725376.body preserve=yes
	if (m_pVAdrStreamBuffer)
	{
		return (&m_pVAdrStreamBuffer[m_pVAdrStreamBuffer[m_cdwAdrOffsetSbData]]);
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetIFMDataVirtualStartAdr%1045725376.body
}

DWORD CHITReservedSharedMemory::GetIFMDataVirtualStartAdrOffset ()
{
  //## begin CHITReservedSharedMemory::GetIFMDataVirtualStartAdrOffset%1047626960.body preserve=yes
	if (m_pVAdrStreamBuffer)
	{
		return (m_pVAdrStreamBuffer[m_cdwAdrOffsetSbData]);
	}

	return 0;
  //## end CHITReservedSharedMemory::GetIFMDataVirtualStartAdrOffset%1047626960.body
}

void CHITReservedSharedMemory::SetIFMDataVirtualStartAdrOffset (DWORD p_AdrOffset)
{
  //## begin CHITReservedSharedMemory::SetIFMDataVirtualStartAdrOffset%1047626962.body preserve=yes
	if (m_pVAdrStreamBuffer)
	{
		m_pVAdrStreamBuffer[m_cdwAdrOffsetSbData] = p_AdrOffset;
	}
  //## end CHITReservedSharedMemory::SetIFMDataVirtualStartAdrOffset%1047626962.body
}

DWORD* CHITReservedSharedMemory::GetIFMDataSizeAdr ()
{
  //## begin CHITReservedSharedMemory::GetIFMDataSizeAdr%1047539537.body preserve=yes
	if (m_pVAdrStreamBuffer)
	{
		return (&m_pVAdrStreamBuffer[m_cdwAdrOffsetDataSize]);
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetIFMDataSizeAdr%1047539537.body
}

DWORD CHITReservedSharedMemory::GetIFMDataSize ()
{
  //## begin CHITReservedSharedMemory::GetIFMDataSize%1046940008.body preserve=yes
	if (m_pVAdrStreamBuffer)
	{
		return (m_pVAdrStreamBuffer[m_cdwAdrOffsetDataSize]);
	}

	return 0;
  //## end CHITReservedSharedMemory::GetIFMDataSize%1046940008.body
}

void CHITReservedSharedMemory::DecIFMDataSize (DWORD p_DecValue)
{
  //## begin CHITReservedSharedMemory::DecIFMDataSize%1047539535.body preserve=yes
	if (m_pVAdrStreamBuffer)
	{
		m_pVAdrStreamBuffer[m_cdwAdrOffsetDataSize]-= p_DecValue;
	}
  //## end CHITReservedSharedMemory::DecIFMDataSize%1047539535.body
}

DWORD* CHITReservedSharedMemory::GetLaserDataVirtualStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetLaserDataVirtualStartAdr%1045813565.body preserve=yes
	if (m_pVAdrStreamBuffer)
	{
		return (&m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetSbData]]);
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetLaserDataVirtualStartAdr%1045813565.body
}

DWORD CHITReservedSharedMemory::GetLaserDataVirtualStartAdrOffset ()
{
  //## begin CHITReservedSharedMemory::GetLaserDataVirtualStartAdrOffset%1047626961.body preserve=yes
	if (m_pVAdrStreamBuffer)
	{
		return (m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetSbData]);
	}

	return 0;
  //## end CHITReservedSharedMemory::GetLaserDataVirtualStartAdrOffset%1047626961.body
}

void CHITReservedSharedMemory::SetLaserDataVirtualStartAdrOffset (DWORD p_AdrOffset)
{
  //## begin CHITReservedSharedMemory::SetLaserDataVirtualStartAdrOffset%1047626963.body preserve=yes
	if (m_pVAdrStreamBuffer)
	{
		m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetSbData] = p_AdrOffset;
	}
  //## end CHITReservedSharedMemory::SetLaserDataVirtualStartAdrOffset%1047626963.body
}

DWORD* CHITReservedSharedMemory::GetLaserDataSizeAdr ()
{
  //## begin CHITReservedSharedMemory::GetLaserDataSizeAdr%1047539538.body preserve=yes
	if (m_pVAdrStreamBuffer)
	{
		return (&m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetDataSize]);
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetLaserDataSizeAdr%1047539538.body
}

DWORD CHITReservedSharedMemory::GetLaserDataSize ()
{
  //## begin CHITReservedSharedMemory::GetLaserDataSize%1046940009.body preserve=yes
	if (m_pVAdrStreamBuffer)
	{
		return (m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetDataSize]);
	}

	return 0;
  //## end CHITReservedSharedMemory::GetLaserDataSize%1046940009.body
}

void CHITReservedSharedMemory::DecLaserDataSize (DWORD p_DecValue)
{
  //## begin CHITReservedSharedMemory::DecLaserDataSize%1047539536.body preserve=yes
	if (m_pVAdrStreamBuffer)
	{
		m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetDataSize]-= p_DecValue;
	}
  //## end CHITReservedSharedMemory::DecLaserDataSize%1047539536.body
}

void CHITReservedSharedMemory::TEST (DWORD p_Test)
{
  //## begin CHITReservedSharedMemory::TEST%1048683265.body preserve=yes
	DWORD l_dwAdrOffset = m_pVAdrStreamBuffer[m_cdwAdrOffsetSbIsrData];

  //## end CHITReservedSharedMemory::TEST%1048683265.body
}

DWORD* CHITReservedSharedMemory::GetIFMBufferBaseAdr ()
{
  //## begin CHITReservedSharedMemory::GetIFMBufferBaseAdr%1048767195.body preserve=yes
	return m_pVAdrStreamBuffer;
  //## end CHITReservedSharedMemory::GetIFMBufferBaseAdr%1048767195.body
}

DWORD* CHITReservedSharedMemory::GetLaserBufferBaseAdr ()
{
  //## begin CHITReservedSharedMemory::GetLaserBufferBaseAdr%1048767196.body preserve=yes
	return (&m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData]);
  //## end CHITReservedSharedMemory::GetLaserBufferBaseAdr%1048767196.body
}

DWORD CHITReservedSharedMemory::MemCopy (BYTE* p_pDest, BYTE* p_pSrc, DWORD p_dwSize)
{
  //## begin CHITReservedSharedMemory::MemCopy%1049261730.body preserve=yes
	__asm {
		push ecx            ; Save register
			push esi
			push edi
			mov ecx,p_dwSize  ; ecx = p_dwSize
			mov esi,p_pSrc    ; esi = ->"p_pSrc"
			mov edi,p_pDest   ; edi = ->"p_pDest"
			rep movsd         ; mov [esi] ==> [edi] and increment both addresses
			pop edi           ; Restore register
			pop esi
			pop ecx
	}
	return 1;
  //## end CHITReservedSharedMemory::MemCopy%1049261730.body
}

void CHITReservedSharedMemory::MemCopyByForLoop (DWORD* p_pDest, DWORD* p_pSrc, DWORD p_dwSize)
{
  //## begin CHITReservedSharedMemory::MemCopyByForLoop%1083575153.body preserve=yes
	for(int ll = 0; ll < (int)p_dwSize; ll++)
	{
		p_pDest[ll] = p_pSrc[ll];
	}
  //## end CHITReservedSharedMemory::MemCopyByForLoop%1083575153.body
}

DWORD* CHITReservedSharedMemory::GetUserProcImReadBaseAdr ()
{
  //## begin CHITReservedSharedMemory::GetUserProcImReadBaseAdr%1052393963.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + (m_cdwAdrOffsetReadData / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetUserProcImReadBaseAdr%1052393963.body
}

DWORD* CHITReservedSharedMemory::GetUserProcImWriteBaseAdr ()
{
  //## begin CHITReservedSharedMemory::GetUserProcImWriteBaseAdr%1052393964.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + (m_cdwAdrOffsetWriteData / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetUserProcImWriteBaseAdr%1052393964.body
}

DWORD* CHITReservedSharedMemory::GetKernelProcImReadBaseAdr ()
{
  //## begin CHITReservedSharedMemory::GetKernelProcImReadBaseAdr%1064913334.body preserve=yes
	if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + (m_cdwAdrOffsetReadData / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetKernelProcImReadBaseAdr%1064913334.body
}

DWORD* CHITReservedSharedMemory::GetKernelProcImWriteBaseAdr ()
{
  //## begin CHITReservedSharedMemory::GetKernelProcImWriteBaseAdr%1064913335.body preserve=yes
	if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + (m_cdwAdrOffsetWriteData / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetKernelProcImWriteBaseAdr%1064913335.body
}

DWORD* CHITReservedSharedMemory::GetUserProcImReadDataStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetUserProcImReadDataStartAdr%1064913330.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetUserReadData) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetUserProcImReadDataStartAdr%1064913330.body
}

DWORD* CHITReservedSharedMemory::GetKernelProcImReadDataStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetKernelProcImReadDataStartAdr%1064913331.body preserve=yes
	if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetUserReadData) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetKernelProcImReadDataStartAdr%1064913331.body
}

DWORD* CHITReservedSharedMemory::GetUserProcImWriteDataStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetUserProcImWriteDataStartAdr%1064913328.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetWriteData + m_cdwAdrOffsetUserWriteData) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetUserProcImWriteDataStartAdr%1064913328.body
}

DWORD* CHITReservedSharedMemory::GetKernelProcImWriteDataStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetKernelProcImWriteDataStartAdr%1064913329.body preserve=yes
	if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetWriteData + m_cdwAdrOffsetUserWriteData) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetKernelProcImWriteDataStartAdr%1064913329.body
}

DWORD* CHITReservedSharedMemory::GetProcImIFMDataStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetProcImIFMDataStartAdr%1073659207.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return ((PDWORD)m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetProcImIFMData) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetProcImIFMData) / sizeof(DWORD)));
	}
	return NULL;
  //## end CHITReservedSharedMemory::GetProcImIFMDataStartAdr%1073659207.body
}

DWORD* CHITReservedSharedMemory::GetProcImLaserDataStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetProcImLaserDataStartAdr%1073659208.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return ((PDWORD)m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetProcImLaserData) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetProcImLaserData) / sizeof(DWORD)));
	}
	return NULL;
  //## end CHITReservedSharedMemory::GetProcImLaserDataStartAdr%1073659208.body
}

void CHITReservedSharedMemory::SetDirectionBit (DWORD* p_pdwIFMData, DWORD* p_pdwLaserData, BOOL p_bDirection)
{
  //## begin CHITReservedSharedMemory::SetDirectionBit%1052718389.body preserve=yes
	DWORD l_dwBitMaskDirection = 0;
	if (p_pdwIFMData && p_pdwLaserData)
	{    
		(p_bDirection == TRUE) ? l_dwBitMaskDirection = m_cdwBitMaskBackwardScan : l_dwBitMaskDirection = m_cdwBitMaskForwardScan;

		for (DWORD ii = 0; ii < CHITDefinitions::GetcdwDataStackDivider(); ii++)
		{
			p_pdwIFMData[ii] = (p_pdwIFMData[ii] >> 8) & 0x00FFFFFF;
			p_pdwLaserData[ii] = (p_pdwLaserData[ii] >> 8) & 0x00FFFFFF;
		}
	}
	else
	{
		for (DWORD ii = 0; ii < CHITDefinitions::GetcdwDataStackDivider(); ii++)
		{
			p_pdwIFMData[ii] = 0x00FFFFFF;
			p_pdwLaserData[ii] = 0x00FFFFFF;
		}
	}
  //## end CHITReservedSharedMemory::SetDirectionBit%1052718389.body
}

void CHITReservedSharedMemory::SetOverflowBit (DWORD* p_pdwData)
{
  //## begin CHITReservedSharedMemory::SetOverflowBit%1052718390.body preserve=yes
	if (p_pdwData)
	{
		for (DWORD ii = 0; ii < CHITDefinitions::GetcdwDataStackDivider(); ii++)
		{
			p_pdwData[ii] |= m_cdwBitMaskDataBufferOverflow;
		}
	}
  //## end CHITReservedSharedMemory::SetOverflowBit%1052718390.body
}

void CHITReservedSharedMemory::CheckHardwareError (DWORD* p_pdwIFMData, DWORD* p_pdwLaserData)
{
  //## begin CHITReservedSharedMemory::CheckHardwareError%1052718391.body preserve=yes
	if (p_pdwIFMData && p_pdwLaserData)
	{
		// Chech HW error flags
		// TEST.PB TODO
		for (DWORD ii = 0; ii < CHITDefinitions::GetcdwDataStackDivider(); ii++)
		{
			p_pdwIFMData[ii] |= m_cdwBitMaskHWError;
			p_pdwLaserData[ii] |= m_cdwBitMaskHWError;
		}
	}
  //## end CHITReservedSharedMemory::CheckHardwareError%1052718391.body
}

DWORD* CHITReservedSharedMemory::GetWCEventRegStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetWCEventRegStartAdr%1053584948.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetWCEventReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetWCEventReg) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetWCEventRegStartAdr%1053584948.body
}

DWORD* CHITReservedSharedMemory::GetHWExceptionRegStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetHWExceptionRegStartAdr%1052718395.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetHWExceptionReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetHWExceptionReg) / sizeof(DWORD)));
	}
	return NULL;
  //## end CHITReservedSharedMemory::GetHWExceptionRegStartAdr%1052718395.body
}

DWORD* CHITReservedSharedMemory::GetDigInputEventRegStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetDigInputEventRegStartAdr%1052718397.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetDigInputEventReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetDigInputEventReg) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetDigInputEventRegStartAdr%1052718397.body
}

DWORD* CHITReservedSharedMemory::GetDigInputRaisingEdgeRegStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetDigInputRaisingEdgeRegStartAdr%1071644211.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetDigInputRaisingEdgeReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetDigInputRaisingEdgeReg) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetDigInputRaisingEdgeRegStartAdr%1071644211.body
}

DWORD* CHITReservedSharedMemory::GetDigInputTrailingEdgeRegStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetDigInputTrailingEdgeRegStartAdr%1071644212.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetDigInputTrailingEdgeReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetDigInputTrailingEdgeReg) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetDigInputTrailingEdgeRegStartAdr%1071644212.body
}

DWORD* CHITReservedSharedMemory::GetStepperEventRegStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetStepperEventRegStartAdr%1066028229.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetStepperEventReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetStepperEventReg) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetStepperEventRegStartAdr%1066028229.body
}

DWORD* CHITReservedSharedMemory::GetI2CEventRegStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetI2CEventRegStartAdr%1071211736.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetDataValidReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetDataValidReg) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetI2CEventRegStartAdr%1071211736.body
}

DWORD* CHITReservedSharedMemory::GetDigInputRegStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetDigInputRegStartAdr%1053509634.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetDigInputReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetDigInputReg) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetDigInputRegStartAdr%1053509634.body
}

DWORD* CHITReservedSharedMemory::GetWedgePositionAdr ()
{
  //## begin CHITReservedSharedMemory::GetWedgePositionAdr%1066199124.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetWedgePos) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetWedgePos) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetWedgePositionAdr%1066199124.body
}

DWORD* CHITReservedSharedMemory::GetWedgeActVelocityAdr ()
{
  //## begin CHITReservedSharedMemory::GetWedgeActVelocityAdr%1066199125.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetWedgeActVelocity) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetWedgeActVelocity) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetWedgeActVelocityAdr%1066199125.body
}

DWORD* CHITReservedSharedMemory::GetWedgeLastVelocityAdr ()
{
  //## begin CHITReservedSharedMemory::GetWedgeLastVelocityAdr%1066199126.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetWedgeLastVelocity) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetWedgeLastVelocity) / sizeof(DWORD)));
	}
	return NULL;
  //## end CHITReservedSharedMemory::GetWedgeLastVelocityAdr%1066199126.body
}

DWORD* CHITReservedSharedMemory::GetWedgeWriteRegAdr ()
{
  //## begin CHITReservedSharedMemory::GetWedgeWriteRegAdr%1066199127.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetWriteData + m_cdwAdrOffsetWedgeWriteReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetWriteData + m_cdwAdrOffsetWedgeWriteReg) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetWedgeWriteRegAdr%1066199127.body
}

DWORD* CHITReservedSharedMemory::GetDigOutputRegStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetDigOutputRegStartAdr%1068703782.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetWriteData + m_cdwAdrOffsetDigOutputReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetWriteData + m_cdwAdrOffsetDigOutputReg) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetDigOutputRegStartAdr%1068703782.body
}

DWORD* CHITReservedSharedMemory::GetI2CDataValidAdr ()
{
  //## begin CHITReservedSharedMemory::GetI2CDataValidAdr%1083326885.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetWriteData + m_cdwAdrOffsetDataValidReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetWriteData + m_cdwAdrOffsetDataValidReg) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetI2CDataValidAdr%1083326885.body
}

DWORD* CHITReservedSharedMemory::GetI2CWriteStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetI2CWriteStartAdr%1071211737.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetWriteData + m_cdwAdrOffsetI2CWriteReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetWriteData + m_cdwAdrOffsetI2CWriteReg) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetI2CWriteStartAdr%1071211737.body
}

DWORD* CHITReservedSharedMemory::GetI2CReadStartAdr ()
{
  //## begin CHITReservedSharedMemory::GetI2CReadStartAdr%1071211738.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetI2CReadReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetI2CReadReg) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetI2CReadStartAdr%1071211738.body
}

DWORD* CHITReservedSharedMemory::GetNumberOfWCScanAdr ()
{
  //## begin CHITReservedSharedMemory::GetNumberOfWCScanAdr%1073895840.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetNumberOfWCScanReg) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetNumberOfWCScanReg) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetNumberOfWCScanAdr%1073895840.body
}

DWORD* CHITReservedSharedMemory::GetLaserDetectionAdr ()
{
  //## begin CHITReservedSharedMemory::GetLaserDetectionAdr%1073998355.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetCurLaserDet) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetCurLaserDet) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetLaserDetectionAdr%1073998355.body
}

void CHITReservedSharedMemory::SetNewStreamBufferSize (DWORD p_dwSize)
{
  //## begin CHITReservedSharedMemory::SetNewStreamBufferSize%1085576035.body preserve=yes

	m_dwIFMTotalBufferSize = (p_dwSize / (2 * sizeof(DWORD)));
	m_dwLaserTotalBufferSize = m_dwIFMTotalBufferSize;

	m_dwIFMDataBufferSizeInByte = (p_dwSize / 2) - (m_cdwFirstDataAdr * sizeof(DWORD));
	m_dwLaserDataBufferSizeInByte = m_dwIFMDataBufferSizeInByte;

  //## end CHITReservedSharedMemory::SetNewStreamBufferSize%1085576035.body
}

DWORD* CHITReservedSharedMemory::GetActHwErrAndWarnStateAdr ()
{
  //## begin CHITReservedSharedMemory::GetActHwErrAndWarnStateAdr%1102084608.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetActHwErrWarnState) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetActHwErrWarnState) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetActHwErrAndWarnStateAdr%1102084608.body
}

DWORD* CHITReservedSharedMemory::GetHwErrAndWarnStateAdr ()
{
  //## begin CHITReservedSharedMemory::GetHwErrAndWarnStateAdr%1102084609.body preserve=yes
	if (m_pVAdrProcessImage)
	{
		return (m_pVAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetHwErrWarnState) / sizeof(DWORD)));
	}
	else if (m_clpPhysAdrProcessImage)
	{
		return ((PDWORD)m_clpPhysAdrProcessImage + ((m_cdwAdrOffsetReadData + m_cdwAdrOffsetHwErrWarnState) / sizeof(DWORD)));
	}

	return NULL;
  //## end CHITReservedSharedMemory::GetHwErrAndWarnStateAdr%1102084609.body
}

void CHITReservedSharedMemory::SetStreamData (DWORD* p_pdwIFMData, DWORD* p_pdwLaserData)
{
  //## begin CHITReservedSharedMemory::SetStreamData%1140691385.body preserve=yes
	DWORD l_dwAdrOffset = 0;
	DWORD l_dwActIFMDataSize = m_pVAdrStreamBuffer[m_cdwAdrOffsetDataSize];
	DWORD l_dwIFMStreamBufferSize = m_dwIFMDataBufferSizeInByte / sizeof(DWORD);
	DWORD l_dwFreeIFMBufferSizeAfterOverflow = l_dwIFMStreamBufferSize / 2;
	DWORD l_dwNumberOfDataToCopy = CHITDefinitions::GetcdwDataStackDivider(); // Number of DWORD
	DWORD l_dwActLaserDataSize = m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetDataSize];
	DWORD l_dwLaserStreamBufferSize = m_dwLaserDataBufferSizeInByte / sizeof(DWORD);
	DWORD l_dwFreeLaserBufferSizeAfterOverflow = l_dwLaserStreamBufferSize / 2;


	if (m_pVAdrStreamBuffer == NULL)
		return;

	if (!m_bBufferOverflow)
	{
		if ((l_dwActIFMDataSize + l_dwNumberOfDataToCopy) >= l_dwIFMStreamBufferSize ||
			(l_dwActLaserDataSize + l_dwNumberOfDataToCopy) >= l_dwLaserStreamBufferSize)
		{
			// data ring buffer already full -> mark data as overflow
			m_bBufferOverflow = true;
		}
	}

	// buffer overflow - wait until buffer size is again free
	if (m_bBufferOverflow)      
	{
		if (l_dwActIFMDataSize <= l_dwFreeIFMBufferSizeAfterOverflow &&
			l_dwActLaserDataSize <= l_dwFreeLaserBufferSizeAfterOverflow)
		{  
			// read the IFM data ring buffer start address
			l_dwAdrOffset = m_pVAdrStreamBuffer[m_cdwAdrOffsetSbIsrData];    

			PDWORD l_pAdr = NULL;
			DWORD ii;
			for (ii = 0; ii < l_dwNumberOfDataToCopy; ii++)
			{
				l_pAdr = &m_pVAdrStreamBuffer[l_dwAdrOffset + ii];
				*l_pAdr = p_pdwIFMData[ii] | m_cdwBitMaskDataBufferOverflow;
			}

			l_dwAdrOffset += l_dwNumberOfDataToCopy;

			if (l_dwAdrOffset >= m_dwIFMTotalBufferSize)
				l_dwAdrOffset = m_cdwFirstDataAdr;

			// write the currently ISR address and curently available IFM data size
			m_pVAdrStreamBuffer[m_cdwAdrOffsetSbIsrData] = l_dwAdrOffset;
			m_pVAdrStreamBuffer[m_cdwAdrOffsetDataSize] += l_dwNumberOfDataToCopy;


			// read the Laser data ring buffer start address
			l_dwAdrOffset = m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetSbIsrData];    

			l_pAdr = NULL;
			for (ii = 0; ii < l_dwNumberOfDataToCopy; ii++)
			{
				l_pAdr = &m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + l_dwAdrOffset + ii];
				*l_pAdr = p_pdwLaserData[ii] | m_cdwBitMaskDataBufferOverflow;
			}

			l_dwAdrOffset+= l_dwNumberOfDataToCopy;

			if (l_dwAdrOffset >= m_dwLaserTotalBufferSize)
				l_dwAdrOffset = m_cdwFirstDataAdr;

			// write the currently physical address and curently available Laser data size
			m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetSbIsrData] = l_dwAdrOffset;
			m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetDataSize] += l_dwNumberOfDataToCopy;


			m_bBufferOverflow = false;
			return;
		}
	}
	else
	{
		// read the IFM data ring buffer start address
		l_dwAdrOffset = m_pVAdrStreamBuffer[m_cdwAdrOffsetSbIsrData];    

		PDWORD l_pAdr = NULL;
		l_pAdr = &m_pVAdrStreamBuffer[l_dwAdrOffset];
		MemCopy((BYTE*)l_pAdr, (BYTE*)p_pdwIFMData, l_dwNumberOfDataToCopy /*DWORDs*/);

		l_dwAdrOffset+= l_dwNumberOfDataToCopy;

		if (l_dwAdrOffset >= m_dwIFMTotalBufferSize)
			l_dwAdrOffset = m_cdwFirstDataAdr;

		// write the currently ISR address and curently available IFM data size
		m_pVAdrStreamBuffer[m_cdwAdrOffsetSbIsrData] = l_dwAdrOffset;
		m_pVAdrStreamBuffer[m_cdwAdrOffsetDataSize] += l_dwNumberOfDataToCopy;


		// read the Laser data ring buffer start address
		l_dwAdrOffset = m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetSbIsrData];    

		l_pAdr = NULL;
		l_pAdr = &m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + l_dwAdrOffset];
		MemCopy((BYTE*)l_pAdr, (BYTE*)p_pdwLaserData, l_dwNumberOfDataToCopy /*DWORDs*/);

		l_dwAdrOffset+= l_dwNumberOfDataToCopy;

		if (l_dwAdrOffset >= m_dwLaserTotalBufferSize)
			l_dwAdrOffset = m_cdwFirstDataAdr;

		// write the currently physical address and curently available Laser data size
		m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetSbIsrData] = l_dwAdrOffset;
		m_pVAdrStreamBuffer[m_cdwAdrOffsetSbLaserData + m_cdwAdrOffsetDataSize] += l_dwNumberOfDataToCopy;
	}
  //## end CHITReservedSharedMemory::SetStreamData%1140691385.body
}

//## Get and Set Operations for Class Attributes (implementation)

const LPVOID CHITReservedSharedMemory::GetclpPhysAdrStreamBuffer ()
{
  //## begin CHITReservedSharedMemory::GetclpPhysAdrStreamBuffer%3E6708A100BB.get preserve=no
  return m_clpPhysAdrStreamBuffer;
  //## end CHITReservedSharedMemory::GetclpPhysAdrStreamBuffer%3E6708A100BB.get
}

const LPVOID CHITReservedSharedMemory::GetclpPhysAdrProcessImage ()
{
  //## begin CHITReservedSharedMemory::GetclpPhysAdrProcessImage%3E6708D20290.get preserve=no
  return m_clpPhysAdrProcessImage;
  //## end CHITReservedSharedMemory::GetclpPhysAdrProcessImage%3E6708D20290.get
}

const DWORD CHITReservedSharedMemory::GetcdwStreamBufferSizeInByte ()
{
  //## begin CHITReservedSharedMemory::GetcdwStreamBufferSizeInByte%3E6709DE01A5.get preserve=no
  return m_cdwStreamBufferSizeInByte;
  //## end CHITReservedSharedMemory::GetcdwStreamBufferSizeInByte%3E6709DE01A5.get
}

const DWORD CHITReservedSharedMemory::GetcdwProcessImageSizeInByte ()
{
  //## begin CHITReservedSharedMemory::GetcdwProcessImageSizeInByte%3E670A940119.get preserve=no
  return m_cdwProcessImageSizeInByte;
  //## end CHITReservedSharedMemory::GetcdwProcessImageSizeInByte%3E670A940119.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetSbLaserData ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetSbLaserData%3E676BE00000.get preserve=no
  return m_cdwAdrOffsetSbLaserData;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetSbLaserData%3E676BE00000.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetSbIsrData ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetSbIsrData%3E676DD7032C.get preserve=no
  return m_cdwAdrOffsetSbIsrData;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetSbIsrData%3E676DD7032C.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetSbData ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetSbData%3E676E7F0399.get preserve=no
  return m_cdwAdrOffsetSbData;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetSbData%3E676E7F0399.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetDataSize ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetDataSize%3E676EC2035B.get preserve=no
  return m_cdwAdrOffsetDataSize;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetDataSize%3E676EC2035B.get
}

const DWORD CHITReservedSharedMemory::GetcdwFirstDataAdr ()
{
  //## begin CHITReservedSharedMemory::GetcdwFirstDataAdr%3E684AE6002E.get preserve=no
  return m_cdwFirstDataAdr;
  //## end CHITReservedSharedMemory::GetcdwFirstDataAdr%3E684AE6002E.get
}

const DWORD CHITReservedSharedMemory::GetdwIFMTotalBufferSize ()
{
  //## begin CHITReservedSharedMemory::GetdwIFMTotalBufferSize%3E6C5AAB0280.get preserve=no
  return m_dwIFMTotalBufferSize;
  //## end CHITReservedSharedMemory::GetdwIFMTotalBufferSize%3E6C5AAB0280.get
}

const DWORD CHITReservedSharedMemory::GetdwLaserTotalBufferSize ()
{
  //## begin CHITReservedSharedMemory::GetdwLaserTotalBufferSize%3E6C5D7B0290.get preserve=no
  return m_dwLaserTotalBufferSize;
  //## end CHITReservedSharedMemory::GetdwLaserTotalBufferSize%3E6C5D7B0290.get
}

const DWORD CHITReservedSharedMemory::GetdwIFMDataBufferSizeInByte ()
{
  //## begin CHITReservedSharedMemory::GetdwIFMDataBufferSizeInByte%3EAE7EF90232.get preserve=no
  return m_dwIFMDataBufferSizeInByte;
  //## end CHITReservedSharedMemory::GetdwIFMDataBufferSizeInByte%3EAE7EF90232.get
}

const DWORD CHITReservedSharedMemory::GetdwLaserDataBufferSizeInByte ()
{
  //## begin CHITReservedSharedMemory::GetdwLaserDataBufferSizeInByte%3EAE7EFB0399.get preserve=no
  return m_dwLaserDataBufferSizeInByte;
  //## end CHITReservedSharedMemory::GetdwLaserDataBufferSizeInByte%3EAE7EFB0399.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetProcImIFMData ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetProcImIFMData%3FFEBCFF007D.get preserve=no
  return m_cdwAdrOffsetProcImIFMData;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetProcImIFMData%3FFEBCFF007D.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetProcImLaserData ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetProcImLaserData%3FFEBCD2004E.get preserve=no
  return m_cdwAdrOffsetProcImLaserData;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetProcImLaserData%3FFEBCD2004E.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetReadData ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetReadData%3F7BC03502BF.get preserve=no
  return m_cdwAdrOffsetReadData;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetReadData%3F7BC03502BF.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetWriteData ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetWriteData%3EBA4636036B.get preserve=no
  return m_cdwAdrOffsetWriteData;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetWriteData%3EBA4636036B.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetUserReadData ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetUserReadData%3F798D5101E4.get preserve=no
  return m_cdwAdrOffsetUserReadData;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetUserReadData%3F798D5101E4.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetUserWriteData ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetUserWriteData%3F794B83036B.get preserve=no
  return m_cdwAdrOffsetUserWriteData;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetUserWriteData%3F794B83036B.get
}

const DWORD CHITReservedSharedMemory::GetcdwNumbersOfWCEventReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwNumbersOfWCEventReg%3ECC8E720251.get preserve=no
  return m_cdwNumbersOfWCEventReg;
  //## end CHITReservedSharedMemory::GetcdwNumbersOfWCEventReg%3ECC8E720251.get
}

const DWORD CHITReservedSharedMemory::GetcdwNumbersOfHWExceptionReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwNumbersOfHWExceptionReg%3EBFAA64007D.get preserve=no
  return m_cdwNumbersOfHWExceptionReg;
  //## end CHITReservedSharedMemory::GetcdwNumbersOfHWExceptionReg%3EBFAA64007D.get
}

const DWORD CHITReservedSharedMemory::GetcdwNumbersOfDigInputEventReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwNumbersOfDigInputEventReg%3EBFAAAF0148.get preserve=no
  return m_cdwNumbersOfDigInputEventReg;
  //## end CHITReservedSharedMemory::GetcdwNumbersOfDigInputEventReg%3EBFAAAF0148.get
}

const DWORD CHITReservedSharedMemory::GetcdwNumbersOfEventReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwNumbersOfEventReg%3F7D10A50203.get preserve=no
  return m_cdwNumbersOfEventReg;
  //## end CHITReservedSharedMemory::GetcdwNumbersOfEventReg%3F7D10A50203.get
}

const DWORD CHITReservedSharedMemory::GetcdwNumbersOfStepperEventReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwNumbersOfStepperEventReg%3F8B959502EE.get preserve=no
  return m_cdwNumbersOfStepperEventReg;
  //## end CHITReservedSharedMemory::GetcdwNumbersOfStepperEventReg%3F8B959502EE.get
}

const DWORD CHITReservedSharedMemory::GetcdwNumbersOfDataValidReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwNumbersOfDataValidReg%3F33907C00AB.get preserve=no
  return m_cdwNumbersOfDataValidReg;
  //## end CHITReservedSharedMemory::GetcdwNumbersOfDataValidReg%3F33907C00AB.get
}

const DWORD CHITReservedSharedMemory::GetcdwNumbersOfI2CData ()
{
  //## begin CHITReservedSharedMemory::GetcdwNumbersOfI2CData%40924171037A.get preserve=no
  return m_cdwNumbersOfI2CData;
  //## end CHITReservedSharedMemory::GetcdwNumbersOfI2CData%40924171037A.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetEventReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetEventReg%3F7D24EE0177.get preserve=no
  return m_cdwAdrOffsetEventReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetEventReg%3F7D24EE0177.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetHWExceptionReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetHWExceptionReg%3ECC8FD1002E.get preserve=no
  return m_cdwAdrOffsetHWExceptionReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetHWExceptionReg%3ECC8FD1002E.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetWCEventReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetWCEventReg%3EC8DA5003C8.get preserve=no
  return m_cdwAdrOffsetWCEventReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetWCEventReg%3EC8DA5003C8.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetDigInputEventReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetDigInputEventReg%3EBFABBF03A9.get preserve=no
  return m_cdwAdrOffsetDigInputEventReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetDigInputEventReg%3EBFABBF03A9.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetDigInputReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetDigInputReg%3ECB939E008C.get preserve=no
  return m_cdwAdrOffsetDigInputReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetDigInputReg%3ECB939E008C.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetDigInputRaisingEdgeReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetDigInputRaisingEdgeReg%3FE013CB0251.get preserve=no
  return m_cdwAdrOffsetDigInputRaisingEdgeReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetDigInputRaisingEdgeReg%3FE013CB0251.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetDigInputTrailingEdgeReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetDigInputTrailingEdgeReg%3FE0186700FA.get preserve=no
  return m_cdwAdrOffsetDigInputTrailingEdgeReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetDigInputTrailingEdgeReg%3FE0186700FA.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetDigOutputReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetDigOutputReg%3FB3445002AF.get preserve=no
  return m_cdwAdrOffsetDigOutputReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetDigOutputReg%3FB3445002AF.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetStepperEventReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetStepperEventReg%3F8B95D400DA.get preserve=no
  return m_cdwAdrOffsetStepperEventReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetStepperEventReg%3F8B95D400DA.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetDataValidReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetDataValidReg%3F33900901D4.get preserve=no
  return m_cdwAdrOffsetDataValidReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetDataValidReg%3F33900901D4.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetWedgePos ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetWedgePos%3F8CE6B003C8.get preserve=no
  return m_cdwAdrOffsetWedgePos;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetWedgePos%3F8CE6B003C8.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetWedgeActVelocity ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetWedgeActVelocity%3F8CE6EB02DE.get preserve=no
  return m_cdwAdrOffsetWedgeActVelocity;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetWedgeActVelocity%3F8CE6EB02DE.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetWedgeLastVelocity ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetWedgeLastVelocity%3F8CE6ED01B5.get preserve=no
  return m_cdwAdrOffsetWedgeLastVelocity;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetWedgeLastVelocity%3F8CE6ED01B5.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetWedgeWriteReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetWedgeWriteReg%3F8CED05031C.get preserve=no
  return m_cdwAdrOffsetWedgeWriteReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetWedgeWriteReg%3F8CED05031C.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetI2CWriteReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetI2CWriteReg%3FD9D2BA0280.get preserve=no
  return m_cdwAdrOffsetI2CWriteReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetI2CWriteReg%3FD9D2BA0280.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetI2CReadReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetI2CReadReg%3FD9D2ED03C8.get preserve=no
  return m_cdwAdrOffsetI2CReadReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetI2CReadReg%3FD9D2ED03C8.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetNumberOfWCScanReg ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetNumberOfWCScanReg%4002595E02AF.get preserve=no
  return m_cdwAdrOffsetNumberOfWCScanReg;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetNumberOfWCScanReg%4002595E02AF.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetCurLaserDet ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetCurLaserDet%4003EA5801D4.get preserve=no
  return m_cdwAdrOffsetCurLaserDet;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetCurLaserDet%4003EA5801D4.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetLampCtrl ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetLampCtrl%41415A7A0399.get preserve=no
  return m_cdwAdrOffsetLampCtrl;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetLampCtrl%41415A7A0399.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetLampCurr ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetLampCurr%41415B1300BB.get preserve=no
  return m_cdwAdrOffsetLampCurr;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetLampCurr%41415B1300BB.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetLampPrimary ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetLampPrimary%41415B4B0167.get preserve=no
  return m_cdwAdrOffsetLampPrimary;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetLampPrimary%41415B4B0167.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetLampSecondary ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetLampSecondary%41415B83006D.get preserve=no
  return m_cdwAdrOffsetLampSecondary;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetLampSecondary%41415B83006D.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetActHwErrWarnState ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetActHwErrWarnState%41B07910005D.get preserve=no
  return m_cdwAdrOffsetActHwErrWarnState;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetActHwErrWarnState%41B07910005D.get
}

const DWORD CHITReservedSharedMemory::GetcdwAdrOffsetHwErrWarnState ()
{
  //## begin CHITReservedSharedMemory::GetcdwAdrOffsetHwErrWarnState%41B07978002E.get preserve=no
  return m_cdwAdrOffsetHwErrWarnState;
  //## end CHITReservedSharedMemory::GetcdwAdrOffsetHwErrWarnState%41B07978002E.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskWCInitialized ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskWCInitialized%3EBFB73303A9.get preserve=no
  return m_cdwBitMaskWCInitialized;
  //## end CHITReservedSharedMemory::GetcdwBitMaskWCInitialized%3EBFB73303A9.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskWCReferenced ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskWCReferenced%3EBFB771033C.get preserve=no
  return m_cdwBitMaskWCReferenced;
  //## end CHITReservedSharedMemory::GetcdwBitMaskWCReferenced%3EBFB771033C.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskWCException ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskWCException%3EBFB7980242.get preserve=no
  return m_cdwBitMaskWCException;
  //## end CHITReservedSharedMemory::GetcdwBitMaskWCException%3EBFB7980242.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskWCStoped ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskWCStoped%3EC87E17035B.get preserve=no
  return m_cdwBitMaskWCStoped;
  //## end CHITReservedSharedMemory::GetcdwBitMaskWCStoped%3EC87E17035B.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskWCMeasuring ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskWCMeasuring%3EC8CF9B00AB.get preserve=no
  return m_cdwBitMaskWCMeasuring;
  //## end CHITReservedSharedMemory::GetcdwBitMaskWCMeasuring%3EC8CF9B00AB.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskForwardScan ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskForwardScan%3EBBB5EE0203.get preserve=no
  return m_cdwBitMaskForwardScan;
  //## end CHITReservedSharedMemory::GetcdwBitMaskForwardScan%3EBBB5EE0203.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskBackwardScan ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskBackwardScan%3EBBB62B032C.get preserve=no
  return m_cdwBitMaskBackwardScan;
  //## end CHITReservedSharedMemory::GetcdwBitMaskBackwardScan%3EBBB62B032C.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskDataBufferOverflow ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskDataBufferOverflow%3EBBB6450148.get preserve=no
  return m_cdwBitMaskDataBufferOverflow;
  //## end CHITReservedSharedMemory::GetcdwBitMaskDataBufferOverflow%3EBBB6450148.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskHWError ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskHWError%3EBBB67603D8.get preserve=no
  return m_cdwBitMaskHWError;
  //## end CHITReservedSharedMemory::GetcdwBitMaskHWError%3EBBB67603D8.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskWCEnable ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskWCEnable%3F8CED8E0290.get preserve=no
  return m_cdwBitMaskWCEnable;
  //## end CHITReservedSharedMemory::GetcdwBitMaskWCEnable%3F8CED8E0290.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskWCPosReset ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskWCPosReset%3F8CEDED0128.get preserve=no
  return m_cdwBitMaskWCPosReset;
  //## end CHITReservedSharedMemory::GetcdwBitMaskWCPosReset%3F8CEDED0128.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskWCDirection ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskWCDirection%3F8CEE57032C.get preserve=no
  return m_cdwBitMaskWCDirection;
  //## end CHITReservedSharedMemory::GetcdwBitMaskWCDirection%3F8CEE57032C.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskWCLightBarrier ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskWCLightBarrier%3F8D073603C8.get preserve=no
  return m_cdwBitMaskWCLightBarrier;
  //## end CHITReservedSharedMemory::GetcdwBitMaskWCLightBarrier%3F8D073603C8.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskWCDACValue ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskWCDACValue%3F8D1163006D.get preserve=no
  return m_cdwBitMaskWCDACValue;
  //## end CHITReservedSharedMemory::GetcdwBitMaskWCDACValue%3F8D1163006D.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskWCDACWakeUp ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskWCDACWakeUp%3FB3769D0167.get preserve=no
  return m_cdwBitMaskWCDACWakeUp;
  //## end CHITReservedSharedMemory::GetcdwBitMaskWCDACWakeUp%3FB3769D0167.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskWCDigOutputs ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskWCDigOutputs%3FB0F67A01A5.get preserve=no
  return m_cdwBitMaskWCDigOutputs;
  //## end CHITReservedSharedMemory::GetcdwBitMaskWCDigOutputs%3FB0F67A01A5.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskWCActValue ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskWCActValue%3F990E1E01C5.get preserve=no
  return m_cdwBitMaskWCActValue;
  //## end CHITReservedSharedMemory::GetcdwBitMaskWCActValue%3F990E1E01C5.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskLeadingSignWCPosition ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskLeadingSignWCPosition%3FAB6F460280.get preserve=no
  return m_cdwBitMaskLeadingSignWCPosition;
  //## end CHITReservedSharedMemory::GetcdwBitMaskLeadingSignWCPosition%3FAB6F460280.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskPCNomVoltage ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskPCNomVoltage%41415CCF01B5.get preserve=no
  return m_cdwBitMaskPCNomVoltage;
  //## end CHITReservedSharedMemory::GetcdwBitMaskPCNomVoltage%41415CCF01B5.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskPCLampSel ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskPCLampSel%41415E050177.get preserve=no
  return m_cdwBitMaskPCLampSel;
  //## end CHITReservedSharedMemory::GetcdwBitMaskPCLampSel%41415E050177.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskPCActCurr ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskPCActCurr%41415E3B032C.get preserve=no
  return m_cdwBitMaskPCActCurr;
  //## end CHITReservedSharedMemory::GetcdwBitMaskPCActCurr%41415E3B032C.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskPCActVolt ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskPCActVolt%41415E6F02FD.get preserve=no
  return m_cdwBitMaskPCActVolt;
  //## end CHITReservedSharedMemory::GetcdwBitMaskPCActVolt%41415E6F02FD.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskPCOnOff ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskPCOnOff%41415E8A03A9.get preserve=no
  return m_cdwBitMaskPCOnOff;
  //## end CHITReservedSharedMemory::GetcdwBitMaskPCOnOff%41415E8A03A9.get
}

const DWORD CHITReservedSharedMemory::GetcdwBitMaskPCLampIdent ()
{
  //## begin CHITReservedSharedMemory::GetcdwBitMaskPCLampIdent%41416F67032C.get preserve=no
  return m_cdwBitMaskPCLampIdent;
  //## end CHITReservedSharedMemory::GetcdwBitMaskPCLampIdent%41416F67032C.get
}

const DWORD CHITReservedSharedMemory::GetcdwWCDACValueLeftShiftCounts ()
{
  //## begin CHITReservedSharedMemory::GetcdwWCDACValueLeftShiftCounts%3F8CEF21035B.get preserve=no
  return m_cdwWCDACValueLeftShiftCounts;
  //## end CHITReservedSharedMemory::GetcdwWCDACValueLeftShiftCounts%3F8CEF21035B.get
}

const DWORD CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampOnOff ()
{
  //## begin CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampOnOff%41415BBA01A5.get preserve=no
  return m_cdwLeftShiftCntPCLampOnOff;
  //## end CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampOnOff%41415BBA01A5.get
}

const DWORD CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampSel ()
{
  //## begin CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampSel%41415C0F01B5.get preserve=no
  return m_cdwLeftShiftCntPCLampSel;
  //## end CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampSel%41415C0F01B5.get
}

const DWORD CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampNomVoltage ()
{
  //## begin CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampNomVoltage%41415C22029F.get preserve=no
  return m_cdwLeftShiftCntPCLampNomVoltage;
  //## end CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampNomVoltage%41415C22029F.get
}

const DWORD CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampActCurrent ()
{
  //## begin CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampActCurrent%41415C70001F.get preserve=no
  return m_cdwLeftShiftCntPCLampActCurrent;
  //## end CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampActCurrent%41415C70001F.get
}

const DWORD CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampActVoltage ()
{
  //## begin CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampActVoltage%41415C98002E.get preserve=no
  return m_cdwLeftShiftCntPCLampActVoltage;
  //## end CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampActVoltage%41415C98002E.get
}

const DWORD CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampIdent ()
{
  //## begin CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampIdent%41415CAE03B9.get preserve=no
  return m_cdwLeftShiftCntPCLampIdent;
  //## end CHITReservedSharedMemory::GetcdwLeftShiftCntPCLampIdent%41415CAE03B9.get
}

//## Get and Set Operations for Associations (implementation)

DWORD * CHITReservedSharedMemory::GetpVAdrStreamBuffer ()
{
  //## begin CHITReservedSharedMemory::GetpVAdrStreamBuffer%3E59F2DD029F.get preserve=no
  return m_pVAdrStreamBuffer;
  //## end CHITReservedSharedMemory::GetpVAdrStreamBuffer%3E59F2DD029F.get
}

DWORD * CHITReservedSharedMemory::GetpVAdrProcessImage ()
{
  //## begin CHITReservedSharedMemory::GetpVAdrProcessImage%3E6766240010.get preserve=no
  return m_pVAdrProcessImage;
  //## end CHITReservedSharedMemory::GetpVAdrProcessImage%3E6766240010.get
}

bool CHITReservedSharedMemory::GetbBufferOverflow ()
{
  //## begin CHITReservedSharedMemory::GetbBufferOverflow%43FDAA3C0050.get preserve=no
  return m_bBufferOverflow;
  //## end CHITReservedSharedMemory::GetbBufferOverflow%43FDAA3C0050.get
}

// Additional Declarations
  //## begin CHITReservedSharedMemory%3E54992F0148.declarations preserve=yes
  //## end CHITReservedSharedMemory%3E54992F0148.declarations

//## begin module%3E5499530138.epilog preserve=yes
//## end module%3E5499530138.epilog
