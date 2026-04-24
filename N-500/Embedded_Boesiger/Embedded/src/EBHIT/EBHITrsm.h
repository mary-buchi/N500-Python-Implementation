//## begin module%3E54997201B5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E54997201B5.cm

//## begin module%3E54997201B5.cp preserve=no
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
//## end module%3E54997201B5.cp

//## Module: EBHITrsm%3E54997201B5; Package specification
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Source file: R:\Embedded\src\EBHIT\EBHITrsm.h

#ifndef EBHITrsm_h
#define EBHITrsm_h 1

//## begin module%3E54997201B5.additionalIncludes preserve=no
//## end module%3E54997201B5.additionalIncludes

//## begin module%3E54997201B5.includes preserve=yes
//## end module%3E54997201B5.includes



//## begin module%3E54997201B5.declarations preserve=no
//## end module%3E54997201B5.declarations

//## begin module%3E54997201B5.additionalDeclarations preserve=yes
#define EBHIT_NUMBER_OF_WC_EVENT_REG  4
#define EBHIT_NUMBER_OF_HW_EVENT_REG  4
#define EBHIT_NUMBER_OF_DI_EVENT_REG  2
//## end module%3E54997201B5.additionalDeclarations


//## begin CHITReservedSharedMemory%3E54992F0148.preface preserve=yes
//## end CHITReservedSharedMemory%3E54992F0148.preface

//## Class: CHITReservedSharedMemory%3E54992F0148
//## Category: EBHIT (Hardware Interface Types)%3E425F410109
//## Subsystem: EBHIT (Hardware Interface Types)%3E425F5A034B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E55F3920196;CHITDefinitions { -> }

class CHITReservedSharedMemory 
{
  //## begin CHITReservedSharedMemory%3E54992F0148.initialDeclarations preserve=yes
  //## end CHITReservedSharedMemory%3E54992F0148.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: InitInstance%1046077274
      static void InitInstance (DWORD* p_pVAdrStreamBuffer, DWORD* p_pVAdrProcessImage);

      //## Operation: DeleteInstance%1046077275
      static void DeleteInstance ();

      //## Operation: SetInitialStreamBufferData%1070956919
      //	DESCRIPTION:
      //	sets the initial streambuffer values:
      //	 - ISR address pointer
      //	 - USER address pointer
      //	 - actual available data size in DWORD
      static void SetInitialStreamBufferData ();

      //## Operation: GetIFMDataVirtualStartAdr%1045725376
      static DWORD* GetIFMDataVirtualStartAdr ();

      //## Operation: GetIFMDataVirtualStartAdrOffset%1047626960
      static DWORD GetIFMDataVirtualStartAdrOffset ();

      //## Operation: SetIFMDataVirtualStartAdrOffset%1047626962
      //	DESCRIPTION:
      //	sets the new IFM data address offsetin the shared memory
      //
      //	PARAMETER:
      //	address offset
      static void SetIFMDataVirtualStartAdrOffset (DWORD p_AdrOffset);

      //## Operation: GetIFMDataSizeAdr%1047539537
      static DWORD* GetIFMDataSizeAdr ();

      //## Operation: GetIFMDataSize%1046940008
      static DWORD GetIFMDataSize ();

      //## Operation: DecIFMDataSize%1047539535
      //	DESCRIPTION:
      //	decrements the IFM data size in the shared memory
      //
      //	PARAMETER:
      //	decrement value
      static void DecIFMDataSize (DWORD p_DecValue);

      //## Operation: GetLaserDataVirtualStartAdr%1045813565
      static DWORD* GetLaserDataVirtualStartAdr ();

      //## Operation: GetLaserDataVirtualStartAdrOffset%1047626961
      static DWORD GetLaserDataVirtualStartAdrOffset ();

      //## Operation: SetLaserDataVirtualStartAdrOffset%1047626963
      //	DESCRIPTION:
      //	sets the new Laser data address offsetin the shared
      //	memory
      //
      //	PARAMETER:
      //	address offset
      static void SetLaserDataVirtualStartAdrOffset (DWORD p_AdrOffset);

      //## Operation: GetLaserDataSizeAdr%1047539538
      static DWORD* GetLaserDataSizeAdr ();

      //## Operation: GetLaserDataSize%1046940009
      static DWORD GetLaserDataSize ();

      //## Operation: DecLaserDataSize%1047539536
      //	DESCRIPTION:
      //	decrements the IFM data size in the shared memory
      //
      //	PARAMETER:
      //	decrement value
      static void DecLaserDataSize (DWORD p_DecValue);

      //## Operation: TEST%1048683265
      //	DESCRIPTION:
      //	only for TESTs
      static void TEST (DWORD p_Test = 0);

      //## Operation: GetIFMBufferBaseAdr%1048767195
      //	DESCRIPTION:
      //	gets the IFM buffer base address
      static DWORD* GetIFMBufferBaseAdr ();

      //## Operation: GetLaserBufferBaseAdr%1048767196
      //	DESCRIPTION:
      //	gets the laser buffer base address
      static DWORD* GetLaserBufferBaseAdr ();

      //## Operation: MemCopy%1049261730
      static DWORD MemCopy (BYTE* p_pDest, BYTE* p_pSrc, DWORD p_dwSize);

      //## Operation: MemCopyByForLoop%1083575153
      static void MemCopyByForLoop (DWORD* p_pDest, DWORD* p_pSrc, DWORD p_dwSize);

      //## Operation: GetUserProcImReadBaseAdr%1052393963
      static DWORD* GetUserProcImReadBaseAdr ();

      //## Operation: GetUserProcImWriteBaseAdr%1052393964
      static DWORD* GetUserProcImWriteBaseAdr ();

      //## Operation: GetKernelProcImReadBaseAdr%1064913334
      static DWORD* GetKernelProcImReadBaseAdr ();

      //## Operation: GetKernelProcImWriteBaseAdr%1064913335
      static DWORD* GetKernelProcImWriteBaseAdr ();

      //## Operation: GetUserProcImReadDataStartAdr%1064913330
      //	DESCRIPTION:
      //	gets the user start address of the READ process image
      static DWORD* GetUserProcImReadDataStartAdr ();

      //## Operation: GetKernelProcImReadDataStartAdr%1064913331
      //	DESCRIPTION:
      //	gets the kernel start address of the READ process image
      static DWORD* GetKernelProcImReadDataStartAdr ();

      //## Operation: GetUserProcImWriteDataStartAdr%1064913328
      //	DESCRIPTION:
      //	gets the user start address of the WRITE process image
      static DWORD* GetUserProcImWriteDataStartAdr ();

      //## Operation: GetKernelProcImWriteDataStartAdr%1064913329
      //	DESCRIPTION:
      //	gets the kernel start address of the WRITE process image
      static DWORD* GetKernelProcImWriteDataStartAdr ();

      //## Operation: GetProcImIFMDataStartAdr%1073659207
      static DWORD* GetProcImIFMDataStartAdr ();

      //## Operation: GetProcImLaserDataStartAdr%1073659208
      static DWORD* GetProcImLaserDataStartAdr ();

      //## Operation: SetDirectionBit%1052718389
      //	DESCRIPTION:
      //	sets the direction bit in the IFM and Laser Data
      //
      //	PARAMETER:
      //	 - IFM Data
      //	 - Laser Data
      //	 - Direction Bit
      //	      0: indicates FORWARD direction
      //	      1: indicates BACKWARD direction
      //
      //	RETURN:
      //	-
      static void SetDirectionBit (DWORD* p_pdwIFMData = NULL, DWORD* p_pdwLaserData = NULL, BOOL p_bDirection = FALSE);

      //## Operation: SetOverflowBit%1052718390
      //	DESCRIPTION:
      //	sets the overflow bit in the IFM and Laser Data
      //
      //	PARAMETER:
      //	 - IFM or Laser Data
      //
      //	RETURN:
      //	-
      static void SetOverflowBit (DWORD* p_pdwData = NULL);

      //## Operation: CheckHardwareError%1052718391
      //	DESCRIPTION:
      //	checks the hardware error flags and sets the Hardware
      //	Overflow Error Bit
      //
      //	PARAMETER:
      //	-
      //
      //	RETURN:
      //	-
      static void CheckHardwareError (DWORD* p_pdwIFMData = NULL, DWORD* p_pdwLaserData = NULL);

      //## Operation: GetWCEventRegStartAdr%1053584948
      //	DESCRIPTION:
      //	gets the start address of the WC event register 1
      //
      //	RETURNS:
      //	start address WC event register 1
      static DWORD* GetWCEventRegStartAdr ();

      //## Operation: GetHWExceptionRegStartAdr%1052718395
      //	DESCRIPTION:
      //	gets the start address of the HW exception register 1
      //
      //	RETURNS:
      //	start address exception register
      static DWORD* GetHWExceptionRegStartAdr ();

      //## Operation: GetDigInputEventRegStartAdr%1052718397
      //	DESCRIPTION:
      //	gets the start address of the digital input event
      //	register
      //
      //	RETURNS:
      //	start address dig. input event register
      static DWORD* GetDigInputEventRegStartAdr ();

      //## Operation: GetDigInputRaisingEdgeRegStartAdr%1071644211
      //	DESCRIPTION:
      //	gets the start address of the digital input raising edge
      //	register
      //
      //	RETURNS:
      //	start address dig input raising edge register
      static DWORD* GetDigInputRaisingEdgeRegStartAdr ();

      //## Operation: GetDigInputTrailingEdgeRegStartAdr%1071644212
      //	DESCRIPTION:
      //	gets the start address of the digital input trailing
      //	edge register
      //
      //	RETURNS:
      //	start address dig input trailing edge register
      static DWORD* GetDigInputTrailingEdgeRegStartAdr ();

      //## Operation: GetStepperEventRegStartAdr%1066028229
      //	DESCRIPTION:
      //	gets the start address of the stepper motor event
      //	register
      //
      //	RETURNS:
      //	start address stepper motor event register
      static DWORD* GetStepperEventRegStartAdr ();

      //## Operation: GetI2CEventRegStartAdr%1071211736
      //	DESCRIPTION:
      //	gets the start address of the I2C event register 1
      //
      //	RETURNS:
      //	start address I2C Event register
      static DWORD* GetI2CEventRegStartAdr ();

      //## Operation: GetDigInputRegStartAdr%1053509634
      //	DESCRIPTION:
      //	gets the start address of the dig input register 1
      //
      //	RETURNS:
      //	start address dig input register 1
      static DWORD* GetDigInputRegStartAdr ();

      //## Operation: GetWedgePositionAdr%1066199124
      //	DESCRIPTION:
      //	gets the address of the wedge position register (counter)
      //
      //	RETURNS:
      //	wedge position register
      static DWORD* GetWedgePositionAdr ();

      //## Operation: GetWedgeActVelocityAdr%1066199125
      //	DESCRIPTION:
      //	gets the address of the wedge actual velocity register
      //	(counter)
      //
      //	RETURNS:
      //	wedge actual velocity register
      static DWORD* GetWedgeActVelocityAdr ();

      //## Operation: GetWedgeLastVelocityAdr%1066199126
      //	DESCRIPTION:
      //	gets the address of the wedge last velocity register
      //	(counter)
      //
      //	RETURNS:
      //	wedge last velocity register
      static DWORD* GetWedgeLastVelocityAdr ();

      //## Operation: GetWedgeWriteRegAdr%1066199127
      //	DESCRIPTION:
      //	gets the address of the wedge control write register
      //
      //	RETURNS:
      //	wedge control write register
      static DWORD* GetWedgeWriteRegAdr ();

      //## Operation: GetDigOutputRegStartAdr%1068703782
      //	DESCRIPTION:
      //	gets the start address of the dig output register 1
      //
      //	RETURNS:
      //	start address dig output register 1
      static DWORD* GetDigOutputRegStartAdr ();

      //## Operation: GetI2CDataValidAdr%1083326885
      //	DESCRIPTION:
      //	gets the address of the I2C Data Valid
      //
      //	RETURNS:
      //	I2C data valid register
      static DWORD* GetI2CDataValidAdr ();

      //## Operation: GetI2CWriteStartAdr%1071211737
      //	DESCRIPTION:
      //	gets the start address of the I2C write register
      //
      //	RETURNS:
      //	I2C start write register
      static DWORD* GetI2CWriteStartAdr ();

      //## Operation: GetI2CReadStartAdr%1071211738
      //	DESCRIPTION:
      //	gets the start address of the I2C read register
      //
      //	RETURNS:
      //	I2C start read register
      static DWORD* GetI2CReadStartAdr ();

      //## Operation: GetNumberOfWCScanAdr%1073895840
      //	DESCRIPTION:
      //	gets the address of the Number of WC Scan register
      //
      //	RETURNS:
      //	Number of WC Scan register
      static DWORD* GetNumberOfWCScanAdr ();

      //## Operation: GetLaserDetectionAdr%1073998355
      //	DESCRIPTION:
      //	gets the start address of the Laser Detecion register
      //
      //	RETURNS:
      //	Laser Detecion read register
      static DWORD* GetLaserDetectionAdr ();

      //## Operation: SetNewStreamBufferSize%1085576035
      //	DESCRIPTION:
      //	sets a new stream buffer size
      //
      //	PARAMETER:
      //	- new size [Byte]
      //
      //	RETURN:
      //	-
      static void SetNewStreamBufferSize (DWORD p_dwSize = m_cdwStreamBufferSizeInByte);

      //## Operation: GetActHwErrAndWarnStateAdr%1102084608
      //	DESCRIPTION:
      //	gets the address of the actual HW error and warning
      //	state register
      //
      //	RETURNS:
      //	actual HW error and warning read register
      static DWORD* GetActHwErrAndWarnStateAdr ();

      //## Operation: GetHwErrAndWarnStateAdr%1102084609
      //	DESCRIPTION:
      //	gets the address of the HW error and warning state
      //	register
      //
      //	RETURNS:
      //	HW error and warning read register - stored state
      static DWORD* GetHwErrAndWarnStateAdr ();

      //## Operation: SetStreamData%1140691385
      //	DESCRIPTION:
      //	sets the IFM data into the stream buffer and updates the
      //	actual available data sizes.
      //
      //	RETURN:
      //	Nonzero indicates success
      static void SetStreamData (DWORD* p_pdwIFMData, DWORD* p_pdwLaserData);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: clpPhysAdrStreamBuffer%3E6708A100BB
      static const LPVOID GetclpPhysAdrStreamBuffer ();

      //## Attribute: clpPhysAdrProcessImage%3E6708D20290
      static const LPVOID GetclpPhysAdrProcessImage ();

      //## Attribute: cdwStreamBufferSizeInByte%3E6709DE01A5
      //	DESCRIPTION:
      //	Size Stream Buffer
      //
      //	UNIT:
      //	Size in Byte
      static const DWORD GetcdwStreamBufferSizeInByte ();

      //## Attribute: cdwProcessImageSizeInByte%3E670A940119
      //	DESCRIPTION:
      //	Size Process Image
      //
      //	UNIT:
      //	Size in Byte
      static const DWORD GetcdwProcessImageSizeInByte ();

      //## Attribute: cdwAdrOffsetSbLaserData%3E676BE00000
      //	DESCRIPTION:
      //	Stream Buffer Offset Laser Data
      //
      //	UNIT:
      //	Size in DWORD
      //	(Size in Byte = 0x800000)
      static const DWORD GetcdwAdrOffsetSbLaserData ();

      //## Attribute: cdwAdrOffsetSbIsrData%3E676DD7032C
      //	DESCRIPTION:
      //	Offset ISR pointer data stream buffer
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetcdwAdrOffsetSbIsrData ();

      //## Attribute: cdwAdrOffsetSbData%3E676E7F0399
      //	DESCRIPTION:
      //	Offset pointer data stream buffer
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetcdwAdrOffsetSbData ();

      //## Attribute: cdwAdrOffsetDataSize%3E676EC2035B
      //	DESCRIPTION:
      //	Offset actual valid size IFM data
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetcdwAdrOffsetDataSize ();

      //## Attribute: cdwFirstDataAdr%3E684AE6002E
      //	DESCRIPTION:
      //	Offset first data address ring buffer
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetcdwFirstDataAdr ();

      //## Attribute: dwIFMTotalBufferSize%3E6C5AAB0280
      //	DESCRIPTION:
      //	Offset first laser data address ring buffer
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetdwIFMTotalBufferSize ();

      //## Attribute: dwLaserTotalBufferSize%3E6C5D7B0290
      //	DESCRIPTION:
      //	Offset first laser data address ring buffer
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetdwLaserTotalBufferSize ();

      //## Attribute: dwIFMDataBufferSizeInByte%3EAE7EF90232
      //	DESCRIPTION:
      //	Offset first laser data address ring buffer
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetdwIFMDataBufferSizeInByte ();

      //## Attribute: dwLaserDataBufferSizeInByte%3EAE7EFB0399
      //	DESCRIPTION:
      //	Offset first laser data address ring buffer
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetdwLaserDataBufferSizeInByte ();

      //## Attribute: cdwAdrOffsetProcImIFMData%3FFEBCFF007D
      //	DESCRIPTION:
      //	Process Image Offset IFM Data
      //
      //	UNIT:
      //	Size in Byte
      static const DWORD GetcdwAdrOffsetProcImIFMData ();

      //## Attribute: cdwAdrOffsetProcImLaserData%3FFEBCD2004E
      //	DESCRIPTION:
      //	Process Image Offset Laser Data
      //
      //	UNIT:
      //	Size in Byte
      static const DWORD GetcdwAdrOffsetProcImLaserData ();

      //## Attribute: cdwAdrOffsetReadData%3F7BC03502BF
      //	DESCRIPTION:
      //	process image read data offset
      //
      //	UNIT:
      //	Size in Byte
      static const DWORD GetcdwAdrOffsetReadData ();

      //## Attribute: cdwAdrOffsetWriteData%3EBA4636036B
      //	DESCRIPTION:
      //	process image write data offset
      //
      //	UNIT:
      //	Size in Byte
      static const DWORD GetcdwAdrOffsetWriteData ();

      //## Attribute: cdwAdrOffsetUserReadData%3F798D5101E4
      //	DESCRIPTION:
      //	Offset user read data
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetUserReadData ();

      //## Attribute: cdwAdrOffsetUserWriteData%3F794B83036B
      //	DESCRIPTION:
      //	Offset user write data
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetUserWriteData ();

      //## Attribute: cdwNumbersOfWCEventReg%3ECC8E720251
      //	DESCRIPTION:
      //	Number of the Process Image WC (wedge control) Event
      //	Register
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetcdwNumbersOfWCEventReg ();

      //## Attribute: cdwNumbersOfHWExceptionReg%3EBFAA64007D
      //	DESCRIPTION:
      //	Number of the Process Image Hardware Exception Register
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwNumbersOfHWExceptionReg ();

      //## Attribute: cdwNumbersOfDigInputEventReg%3EBFAAAF0148
      //	DESCRIPTION:
      //	Number of the process image dig input event register
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetcdwNumbersOfDigInputEventReg ();

      //## Attribute: cdwNumbersOfEventReg%3F7D10A50203
      //	DESCRIPTION:
      //	Number of the process image event register
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetcdwNumbersOfEventReg ();

      //## Attribute: cdwNumbersOfStepperEventReg%3F8B959502EE
      //	DESCRIPTION:
      //	Number of the process image stepper motor event register
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetcdwNumbersOfStepperEventReg ();

      //## Attribute: cdwNumbersOfDataValidReg%3F33907C00AB
      //	DESCRIPTION:
      //	Number of the Process Image Data Valid Register
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetcdwNumbersOfDataValidReg ();

      //## Attribute: cdwNumbersOfI2CData%40924171037A
      //	DESCRIPTION:
      //	Number of the I2C Data
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetcdwNumbersOfI2CData ();

      //## Attribute: cdwAdrOffsetEventReg%3F7D24EE0177
      //	DESCRIPTION:
      //	address offset event register
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetEventReg ();

      //## Attribute: cdwAdrOffsetHWExceptionReg%3ECC8FD1002E
      //	DESCRIPTION:
      //	Address Offset WC Exception Register
      static const DWORD GetcdwAdrOffsetHWExceptionReg ();

      //## Attribute: cdwAdrOffsetWCEventReg%3EC8DA5003C8
      //	DESCRIPTION:
      //	Address Offset WC Event Register
      //
      //	UNIT:
      //	Size in DWORD
      static const DWORD GetcdwAdrOffsetWCEventReg ();

      //## Attribute: cdwAdrOffsetDigInputEventReg%3EBFABBF03A9
      //	DESCRIPTION:
      //	address offset digital input event register
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetDigInputEventReg ();

      //## Attribute: cdwAdrOffsetDigInputReg%3ECB939E008C
      //	DESCRIPTION:
      //	Address Offset dig Input Register
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetDigInputReg ();

      //## Attribute: cdwAdrOffsetDigInputRaisingEdgeReg%3FE013CB0251
      //	DESCRIPTION:
      //	address offset digital input raising edge register
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetDigInputRaisingEdgeReg ();

      //## Attribute: cdwAdrOffsetDigInputTrailingEdgeReg%3FE0186700FA
      //	DESCRIPTION:
      //	address offset digital input trailing edge register
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetDigInputTrailingEdgeReg ();

      //## Attribute: cdwAdrOffsetDigOutputReg%3FB3445002AF
      //	DESCRIPTION:
      //	Address Offset dig Ouput Register
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetDigOutputReg ();

      //## Attribute: cdwAdrOffsetStepperEventReg%3F8B95D400DA
      //	DESCRIPTION:
      //	Address Offset stepper motor events
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetStepperEventReg ();

      //## Attribute: cdwAdrOffsetDataValidReg%3F33900901D4
      //	DESCRIPTION:
      //	Address Offset Data Valid Register
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetDataValidReg ();

      //## Attribute: cdwAdrOffsetWedgePos%3F8CE6B003C8
      //	DESCRIPTION:
      //	Address Offset wedge position counter
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetWedgePos ();

      //## Attribute: cdwAdrOffsetWedgeActVelocity%3F8CE6EB02DE
      //	DESCRIPTION:
      //	Address Offset wedge actual velocity (counter)
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetWedgeActVelocity ();

      //## Attribute: cdwAdrOffsetWedgeLastVelocity%3F8CE6ED01B5
      //	DESCRIPTION:
      //	Address Offset wedge last velocity (counter)
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetWedgeLastVelocity ();

      //## Attribute: cdwAdrOffsetWedgeWriteReg%3F8CED05031C
      //	DESCRIPTION:
      //	Address Offset wedge control write register
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetWedgeWriteReg ();

      //## Attribute: cdwAdrOffsetI2CWriteReg%3FD9D2BA0280
      //	DESCRIPTION:
      //	Address Offset I2C write register
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetI2CWriteReg ();

      //## Attribute: cdwAdrOffsetI2CReadReg%3FD9D2ED03C8
      //	DESCRIPTION:
      //	Address Offset I2C read register
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetI2CReadReg ();

      //## Attribute: cdwAdrOffsetNumberOfWCScanReg%4002595E02AF
      //	DESCRIPTION:
      //	address offset number of wedge drive scan register
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetNumberOfWCScanReg ();

      //## Attribute: cdwAdrOffsetCurLaserDet%4003EA5801D4
      //	DESCRIPTION:
      //	Offset current laser detecion
      static const DWORD GetcdwAdrOffsetCurLaserDet ();

      //## Attribute: cdwAdrOffsetLampCtrl%41415A7A0399
      //	DESCRIPTION:
      //	address offset  lamp control (nominal voltage primary or
      //	secondary lamp, lamp selection, lamp on/off)
      //
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetLampCtrl ();

      //## Attribute: cdwAdrOffsetLampCurr%41415B1300BB
      //	DESCRIPTION:
      //	address offset  lamp actual current
      //
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetLampCurr ();

      //## Attribute: cdwAdrOffsetLampPrimary%41415B4B0167
      //	DESCRIPTION:
      //	address offset  primary lamp (lamp identification, lamp
      //	actual voltage)
      //
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetLampPrimary ();

      //## Attribute: cdwAdrOffsetLampSecondary%41415B83006D
      //	DESCRIPTION:
      //	address offset  primary lamp (lamp identification, lamp
      //	actual voltage)
      //
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetLampSecondary ();

      //## Attribute: cdwAdrOffsetActHwErrWarnState%41B07910005D
      //	DESCRIPTION:
      //	address offset hardware errors and warnings mc
      //	comunication -> ACTUAL state
      //
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetActHwErrWarnState ();

      //## Attribute: cdwAdrOffsetHwErrWarnState%41B07978002E
      //	DESCRIPTION:
      //	address offset hardware errors and warnings mc
      //	comunication -> stored state
      //
      //
      //	UNIT:
      //	Size in BYTE
      static const DWORD GetcdwAdrOffsetHwErrWarnState ();

      //## Attribute: cdwBitMaskWCInitialized%3EBFB73303A9
      //	DESCRIPTION:
      //	Bit Mask Wedge Control (WC) initialized
      static const DWORD GetcdwBitMaskWCInitialized ();

      //## Attribute: cdwBitMaskWCReferenced%3EBFB771033C
      //	DESCRIPTION:
      //	Bit Mask Wedge Control (WC) referenced
      static const DWORD GetcdwBitMaskWCReferenced ();

      //## Attribute: cdwBitMaskWCException%3EBFB7980242
      //	DESCRIPTION:
      //	Bit Mask Wedge Control (WC) has exception
      static const DWORD GetcdwBitMaskWCException ();

      //## Attribute: cdwBitMaskWCStoped%3EC87E17035B
      //	DESCRIPTION:
      //	Bit Mask Wedge Control (WC) stoped
      static const DWORD GetcdwBitMaskWCStoped ();

      //## Attribute: cdwBitMaskWCMeasuring%3EC8CF9B00AB
      //	DESCRIPTION:
      //	Bit Mask Wedge Control (WC) measuring
      static const DWORD GetcdwBitMaskWCMeasuring ();

      //## Attribute: cdwBitMaskForwardScan%3EBBB5EE0203
      //	DESCRIPTION:
      //	Bit Mask for Forward Scan
      static const DWORD GetcdwBitMaskForwardScan ();

      //## Attribute: cdwBitMaskBackwardScan%3EBBB62B032C
      //	DESCRIPTION:
      //	Bit Mask for Backward Scan
      static const DWORD GetcdwBitMaskBackwardScan ();

      //## Attribute: cdwBitMaskDataBufferOverflow%3EBBB6450148
      //	DESCRIPTION:
      //	Bit Mask Stream Data Buffer Overflow
      static const DWORD GetcdwBitMaskDataBufferOverflow ();

      //## Attribute: cdwBitMaskHWError%3EBBB67603D8
      //	DESCRIPTION:
      //	Bit Mask Hardware Error (Parity, etc.)
      static const DWORD GetcdwBitMaskHWError ();

      //## Attribute: cdwBitMaskWCEnable%3F8CED8E0290
      //	DESCRIPTION:
      //	Bit Mask Wedge Control (WC) enable controlloop factor
      //	  1 factor normal
      //	  0 factor low (off)
      static const DWORD GetcdwBitMaskWCEnable ();

      //## Attribute: cdwBitMaskWCPosReset%3F8CEDED0128
      //	DESCRIPTION:
      //	Bit Mask Wedge Control (WC) position reset
      //	  1 position counter set to 0
      //	  0 position counter counts the pos. laser zero cross
      static const DWORD GetcdwBitMaskWCPosReset ();

      //## Attribute: cdwBitMaskWCDirection%3F8CEE57032C
      //	DESCRIPTION:
      //	Bit Mask Wedge Control (WC) direction
      //	  1 position counter counts +
      //	  0 position counter counts -
      static const DWORD GetcdwBitMaskWCDirection ();

      //## Attribute: cdwBitMaskWCLightBarrier%3F8D073603C8
      //	DESCRIPTION:
      //	Bit Mask Wedge Control (WC) light barrier
      //	  1 light barrier occupied
      //	  0 light barrier free
      static const DWORD GetcdwBitMaskWCLightBarrier ();

      //## Attribute: cdwBitMaskWCDACValue%3F8D1163006D
      //	DESCRIPTION:
      //	bit mask for wedge control DAC output value
      static const DWORD GetcdwBitMaskWCDACValue ();

      //## Attribute: cdwBitMaskWCDACWakeUp%3FB3769D0167
      //	DESCRIPTION:
      //	bit mask for wedge control DAC wake up
      static const DWORD GetcdwBitMaskWCDACWakeUp ();

      //## Attribute: cdwBitMaskWCDigOutputs%3FB0F67A01A5
      //	DESCRIPTION:
      //	bit mask for wedge control digital output
      static const DWORD GetcdwBitMaskWCDigOutputs ();

      //## Attribute: cdwBitMaskWCActValue%3F990E1E01C5
      //	DESCRIPTION:
      //	bit mask for wedge control intput values
      //	(e.g. Wedge Position, Wedge Actual Velocity, Wedge Last
      //	Velocity)
      static const DWORD GetcdwBitMaskWCActValue ();

      //## Attribute: cdwBitMaskLeadingSignWCPosition%3FAB6F460280
      //	DESCRIPTION:
      //	bit mask for detectetion the leading sign of the
      //	position counter register (Wdg_Pos).
      static const DWORD GetcdwBitMaskLeadingSignWCPosition ();

      //## Attribute: cdwBitMaskPCNomVoltage%41415CCF01B5
      //	DESCRIPTION:
      //	bit mask for lamp nominal voltage
      static const DWORD GetcdwBitMaskPCNomVoltage ();

      //## Attribute: cdwBitMaskPCLampSel%41415E050177
      //	DESCRIPTION:
      //	bit mask for lamp selection
      //	0: primary
      //	1: secondary
      static const DWORD GetcdwBitMaskPCLampSel ();

      //## Attribute: cdwBitMaskPCActCurr%41415E3B032C
      //	DESCRIPTION:
      //	bit mask for lamp actual current
      static const DWORD GetcdwBitMaskPCActCurr ();

      //## Attribute: cdwBitMaskPCActVolt%41415E6F02FD
      //	DESCRIPTION:
      //	bit mask for lamp actual voltage
      static const DWORD GetcdwBitMaskPCActVolt ();

      //## Attribute: cdwBitMaskPCOnOff%41415E8A03A9
      //	DESCRIPTION:
      //	bit mask for lamp ON/OFF
      static const DWORD GetcdwBitMaskPCOnOff ();

      //## Attribute: cdwBitMaskPCLampIdent%41416F67032C
      //	DESCRIPTION:
      //	bit mask for lamp identification
      static const DWORD GetcdwBitMaskPCLampIdent ();

      //## Attribute: cdwWCDACValueLeftShiftCounts%3F8CEF21035B
      //	DESCRIPTION:
      //	wedge control output (voltage 16 Bit) - number of left
      //	shift counts
      static const DWORD GetcdwWCDACValueLeftShiftCounts ();

      //## Attribute: cdwLeftShiftCntPCLampOnOff%41415BBA01A5
      //	DESCRIPTION:
      //	lamp on/off - number of left shift counts
      static const DWORD GetcdwLeftShiftCntPCLampOnOff ();

      //## Attribute: cdwLeftShiftCntPCLampSel%41415C0F01B5
      //	DESCRIPTION:
      //	lamp selection - number of left shift counts
      static const DWORD GetcdwLeftShiftCntPCLampSel ();

      //## Attribute: cdwLeftShiftCntPCLampNomVoltage%41415C22029F
      //	DESCRIPTION:
      //	lamp nominal voltage - number of left shift counts
      static const DWORD GetcdwLeftShiftCntPCLampNomVoltage ();

      //## Attribute: cdwLeftShiftCntPCLampActCurrent%41415C70001F
      //	DESCRIPTION:
      //	lamp actual current - number of left shift counts
      static const DWORD GetcdwLeftShiftCntPCLampActCurrent ();

      //## Attribute: cdwLeftShiftCntPCLampActVoltage%41415C98002E
      //	DESCRIPTION:
      //	lamp actual voltage- number of left shift counts
      static const DWORD GetcdwLeftShiftCntPCLampActVoltage ();

      //## Attribute: cdwLeftShiftCntPCLampIdent%41415CAE03B9
      //	DESCRIPTION:
      //	lamp identification - number of left shift counts
      static const DWORD GetcdwLeftShiftCntPCLampIdent ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3E59F2DD00EA
      //## Role: CHITReservedSharedMemory::pVAdrStreamBuffer%3E59F2DD029F
      static DWORD * GetpVAdrStreamBuffer ();

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3E67662301C5
      //## Role: CHITReservedSharedMemory::pVAdrProcessImage%3E6766240010
      static DWORD * GetpVAdrProcessImage ();

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%43FDAA3B00B3
      //## Role: CHITReservedSharedMemory::bBufferOverflow%43FDAA3C0050
      static bool GetbBufferOverflow ();

    // Additional Public Declarations
      //## begin CHITReservedSharedMemory%3E54992F0148.public preserve=yes
      //## end CHITReservedSharedMemory%3E54992F0148.public

  protected:
    // Additional Protected Declarations
      //## begin CHITReservedSharedMemory%3E54992F0148.protected preserve=yes
      //## end CHITReservedSharedMemory%3E54992F0148.protected

  private:
    //## Constructors (generated)
      CHITReservedSharedMemory();

      CHITReservedSharedMemory(const CHITReservedSharedMemory &right);

    //## Assignment Operation (generated)
      const CHITReservedSharedMemory & operator=(const CHITReservedSharedMemory &right);

    //## Equality Operations (generated)
      bool operator==(const CHITReservedSharedMemory &right) const;

      bool operator!=(const CHITReservedSharedMemory &right) const;

    // Data Members for Class Attributes

      //## begin CHITReservedSharedMemory::clpPhysAdrStreamBuffer%3E6708A100BB.attr preserve=no  public: static LPVOID {UC} (LPVOID)0x80420000
      static const LPVOID  m_clpPhysAdrStreamBuffer;
      //## end CHITReservedSharedMemory::clpPhysAdrStreamBuffer%3E6708A100BB.attr

      //## begin CHITReservedSharedMemory::clpPhysAdrProcessImage%3E6708D20290.attr preserve=no  public: static LPVOID {UC} (LPVOID)0x80220000
      static const LPVOID  m_clpPhysAdrProcessImage;
      //## end CHITReservedSharedMemory::clpPhysAdrProcessImage%3E6708D20290.attr

      //## begin CHITReservedSharedMemory::cdwStreamBufferSizeInByte%3E6709DE01A5.attr preserve=no  public: static DWORD {UC} 0x1000000
      static const DWORD  m_cdwStreamBufferSizeInByte;
      //## end CHITReservedSharedMemory::cdwStreamBufferSizeInByte%3E6709DE01A5.attr

      //## begin CHITReservedSharedMemory::cdwProcessImageSizeInByte%3E670A940119.attr preserve=no  public: static DWORD {UC} 0x200000
      static const DWORD  m_cdwProcessImageSizeInByte;
      //## end CHITReservedSharedMemory::cdwProcessImageSizeInByte%3E670A940119.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetSbLaserData%3E676BE00000.attr preserve=no  public: static DWORD {UC} 0x200000
      static const DWORD  m_cdwAdrOffsetSbLaserData;
      //## end CHITReservedSharedMemory::cdwAdrOffsetSbLaserData%3E676BE00000.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetSbIsrData%3E676DD7032C.attr preserve=no  public: static DWORD {UC} 0x0
      static const DWORD  m_cdwAdrOffsetSbIsrData;
      //## end CHITReservedSharedMemory::cdwAdrOffsetSbIsrData%3E676DD7032C.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetSbData%3E676E7F0399.attr preserve=no  public: static DWORD {UC} 0x1
      static const DWORD  m_cdwAdrOffsetSbData;
      //## end CHITReservedSharedMemory::cdwAdrOffsetSbData%3E676E7F0399.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetDataSize%3E676EC2035B.attr preserve=no  public: static DWORD {UC} 0x2
      static const DWORD  m_cdwAdrOffsetDataSize;
      //## end CHITReservedSharedMemory::cdwAdrOffsetDataSize%3E676EC2035B.attr

      //## begin CHITReservedSharedMemory::cdwFirstDataAdr%3E684AE6002E.attr preserve=no  public: static DWORD {UC} 0x8
      static const DWORD  m_cdwFirstDataAdr;
      //## end CHITReservedSharedMemory::cdwFirstDataAdr%3E684AE6002E.attr

      //## begin CHITReservedSharedMemory::dwIFMTotalBufferSize%3E6C5AAB0280.attr preserve=no  public: static DWORD {U} 
      static DWORD m_dwIFMTotalBufferSize;
      //## end CHITReservedSharedMemory::dwIFMTotalBufferSize%3E6C5AAB0280.attr

      //## begin CHITReservedSharedMemory::dwLaserTotalBufferSize%3E6C5D7B0290.attr preserve=no  public: static DWORD {U} 
      static DWORD m_dwLaserTotalBufferSize;
      //## end CHITReservedSharedMemory::dwLaserTotalBufferSize%3E6C5D7B0290.attr

      //## begin CHITReservedSharedMemory::dwIFMDataBufferSizeInByte%3EAE7EF90232.attr preserve=no  public: static DWORD {U} 
      static DWORD m_dwIFMDataBufferSizeInByte;
      //## end CHITReservedSharedMemory::dwIFMDataBufferSizeInByte%3EAE7EF90232.attr

      //## begin CHITReservedSharedMemory::dwLaserDataBufferSizeInByte%3EAE7EFB0399.attr preserve=no  public: static DWORD {U} 
      static DWORD m_dwLaserDataBufferSizeInByte;
      //## end CHITReservedSharedMemory::dwLaserDataBufferSizeInByte%3EAE7EFB0399.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetProcImIFMData%3FFEBCFF007D.attr preserve=no  public: static DWORD {UC} 0x300
      static const DWORD  m_cdwAdrOffsetProcImIFMData;
      //## end CHITReservedSharedMemory::cdwAdrOffsetProcImIFMData%3FFEBCFF007D.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetProcImLaserData%3FFEBCD2004E.attr preserve=no  public: static DWORD {UC} 0x320
      static const DWORD  m_cdwAdrOffsetProcImLaserData;
      //## end CHITReservedSharedMemory::cdwAdrOffsetProcImLaserData%3FFEBCD2004E.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetReadData%3F7BC03502BF.attr preserve=no  public: static DWORD {UC} 0x0
      static const DWORD  m_cdwAdrOffsetReadData;
      //## end CHITReservedSharedMemory::cdwAdrOffsetReadData%3F7BC03502BF.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetWriteData%3EBA4636036B.attr preserve=no  public: static DWORD {UC} 0x100000
      static const DWORD  m_cdwAdrOffsetWriteData;
      //## end CHITReservedSharedMemory::cdwAdrOffsetWriteData%3EBA4636036B.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetUserReadData%3F798D5101E4.attr preserve=no  public: static DWORD {UC} 0x140
      static const DWORD  m_cdwAdrOffsetUserReadData;
      //## end CHITReservedSharedMemory::cdwAdrOffsetUserReadData%3F798D5101E4.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetUserWriteData%3F794B83036B.attr preserve=no  public: static DWORD {UC} 0x140
      static const DWORD  m_cdwAdrOffsetUserWriteData;
      //## end CHITReservedSharedMemory::cdwAdrOffsetUserWriteData%3F794B83036B.attr

      //## begin CHITReservedSharedMemory::cdwNumbersOfWCEventReg%3ECC8E720251.attr preserve=no  public: static DWORD {UC} EBHIT_NUMBER_OF_WC_EVENT_REG
      static const DWORD  m_cdwNumbersOfWCEventReg;
      //## end CHITReservedSharedMemory::cdwNumbersOfWCEventReg%3ECC8E720251.attr

      //## begin CHITReservedSharedMemory::cdwNumbersOfHWExceptionReg%3EBFAA64007D.attr preserve=no  public: static DWORD {UC} 0x1
      static const DWORD  m_cdwNumbersOfHWExceptionReg;
      //## end CHITReservedSharedMemory::cdwNumbersOfHWExceptionReg%3EBFAA64007D.attr

      //## begin CHITReservedSharedMemory::cdwNumbersOfDigInputEventReg%3EBFAAAF0148.attr preserve=no  public: static DWORD {UC} EBHIT_NUMBER_OF_DI_EVENT_REG
      static const DWORD  m_cdwNumbersOfDigInputEventReg;
      //## end CHITReservedSharedMemory::cdwNumbersOfDigInputEventReg%3EBFAAAF0148.attr

      //## begin CHITReservedSharedMemory::cdwNumbersOfEventReg%3F7D10A50203.attr preserve=no  public: static DWORD {UC} EBHIT_NUMBER_OF_HW_EVENT_REG
      static const DWORD  m_cdwNumbersOfEventReg;
      //## end CHITReservedSharedMemory::cdwNumbersOfEventReg%3F7D10A50203.attr

      //## begin CHITReservedSharedMemory::cdwNumbersOfStepperEventReg%3F8B959502EE.attr preserve=no  public: static DWORD {UC} 0x1
      static const DWORD  m_cdwNumbersOfStepperEventReg;
      //## end CHITReservedSharedMemory::cdwNumbersOfStepperEventReg%3F8B959502EE.attr

      //## begin CHITReservedSharedMemory::cdwNumbersOfDataValidReg%3F33907C00AB.attr preserve=no  public: static DWORD {UC} 0x4
      static const DWORD  m_cdwNumbersOfDataValidReg;
      //## end CHITReservedSharedMemory::cdwNumbersOfDataValidReg%3F33907C00AB.attr

      //## begin CHITReservedSharedMemory::cdwNumbersOfI2CData%40924171037A.attr preserve=no  public: static DWORD {UC} 0x40
      static const DWORD  m_cdwNumbersOfI2CData;
      //## end CHITReservedSharedMemory::cdwNumbersOfI2CData%40924171037A.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetEventReg%3F7D24EE0177.attr preserve=no  public: static DWORD {UC} 0x140
      static const DWORD  m_cdwAdrOffsetEventReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetEventReg%3F7D24EE0177.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetHWExceptionReg%3ECC8FD1002E.attr preserve=no  public: static DWORD {UC} 0x408
      static const DWORD  m_cdwAdrOffsetHWExceptionReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetHWExceptionReg%3ECC8FD1002E.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetWCEventReg%3EC8DA5003C8.attr preserve=no  public: static DWORD {U} 0x400
      static DWORD m_cdwAdrOffsetWCEventReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetWCEventReg%3EC8DA5003C8.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetDigInputEventReg%3EBFABBF03A9.attr preserve=no  public: static DWORD {UC} 0x144
      static const DWORD  m_cdwAdrOffsetDigInputEventReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetDigInputEventReg%3EBFABBF03A9.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetDigInputReg%3ECB939E008C.attr preserve=no  public: static DWORD {UC} 0x170
      static const DWORD  m_cdwAdrOffsetDigInputReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetDigInputReg%3ECB939E008C.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetDigInputRaisingEdgeReg%3FE013CB0251.attr preserve=no  public: static DWORD {UC} 0x410
      static const DWORD  m_cdwAdrOffsetDigInputRaisingEdgeReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetDigInputRaisingEdgeReg%3FE013CB0251.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetDigInputTrailingEdgeReg%3FE0186700FA.attr preserve=no  public: static DWORD {UC} 0x418
      static const DWORD  m_cdwAdrOffsetDigInputTrailingEdgeReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetDigInputTrailingEdgeReg%3FE0186700FA.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetDigOutputReg%3FB3445002AF.attr preserve=no  public: static DWORD {UC} 0x170
      static const DWORD  m_cdwAdrOffsetDigOutputReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetDigOutputReg%3FB3445002AF.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetStepperEventReg%3F8B95D400DA.attr preserve=no  public: static DWORD {UC} 0x14C
      static const DWORD  m_cdwAdrOffsetStepperEventReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetStepperEventReg%3F8B95D400DA.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetDataValidReg%3F33900901D4.attr preserve=no  public: static DWORD {UC} 0x140
      static const DWORD  m_cdwAdrOffsetDataValidReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetDataValidReg%3F33900901D4.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetWedgePos%3F8CE6B003C8.attr preserve=no  public: static DWORD {UC} 0x184
      static const DWORD  m_cdwAdrOffsetWedgePos;
      //## end CHITReservedSharedMemory::cdwAdrOffsetWedgePos%3F8CE6B003C8.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetWedgeActVelocity%3F8CE6EB02DE.attr preserve=no  public: static DWORD {UC} 0x188
      static const DWORD  m_cdwAdrOffsetWedgeActVelocity;
      //## end CHITReservedSharedMemory::cdwAdrOffsetWedgeActVelocity%3F8CE6EB02DE.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetWedgeLastVelocity%3F8CE6ED01B5.attr preserve=no  public: static DWORD {UC} 0x18C
      static const DWORD  m_cdwAdrOffsetWedgeLastVelocity;
      //## end CHITReservedSharedMemory::cdwAdrOffsetWedgeLastVelocity%3F8CE6ED01B5.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetWedgeWriteReg%3F8CED05031C.attr preserve=no  public: static DWORD {UC} 0x17C
      static const DWORD  m_cdwAdrOffsetWedgeWriteReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetWedgeWriteReg%3F8CED05031C.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetI2CWriteReg%3FD9D2BA0280.attr preserve=no  public: static DWORD {UC} 0x200
      static const DWORD  m_cdwAdrOffsetI2CWriteReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetI2CWriteReg%3FD9D2BA0280.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetI2CReadReg%3FD9D2ED03C8.attr preserve=no  public: static DWORD {UC} 0x200
      static const DWORD  m_cdwAdrOffsetI2CReadReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetI2CReadReg%3FD9D2ED03C8.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetNumberOfWCScanReg%4002595E02AF.attr preserve=no  public: static DWORD {UC} 0x430
      static const DWORD  m_cdwAdrOffsetNumberOfWCScanReg;
      //## end CHITReservedSharedMemory::cdwAdrOffsetNumberOfWCScanReg%4002595E02AF.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetCurLaserDet%4003EA5801D4.attr preserve=no  public: static DWORD {UC} 0x190
      static const DWORD  m_cdwAdrOffsetCurLaserDet;
      //## end CHITReservedSharedMemory::cdwAdrOffsetCurLaserDet%4003EA5801D4.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetLampCtrl%41415A7A0399.attr preserve=no  public: static DWORD {UC} 0x178
      static const DWORD  m_cdwAdrOffsetLampCtrl;
      //## end CHITReservedSharedMemory::cdwAdrOffsetLampCtrl%41415A7A0399.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetLampCurr%41415B1300BB.attr preserve=no  public: static DWORD {UC} 0x178
      static const DWORD  m_cdwAdrOffsetLampCurr;
      //## end CHITReservedSharedMemory::cdwAdrOffsetLampCurr%41415B1300BB.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetLampPrimary%41415B4B0167.attr preserve=no  public: static DWORD {UC} 0x17C
      static const DWORD  m_cdwAdrOffsetLampPrimary;
      //## end CHITReservedSharedMemory::cdwAdrOffsetLampPrimary%41415B4B0167.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetLampSecondary%41415B83006D.attr preserve=no  public: static DWORD {UC} 0x180
      static const DWORD  m_cdwAdrOffsetLampSecondary;
      //## end CHITReservedSharedMemory::cdwAdrOffsetLampSecondary%41415B83006D.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetActHwErrWarnState%41B07910005D.attr preserve=no  public: static DWORD {UC} 0x198
      static const DWORD  m_cdwAdrOffsetActHwErrWarnState;
      //## end CHITReservedSharedMemory::cdwAdrOffsetActHwErrWarnState%41B07910005D.attr

      //## begin CHITReservedSharedMemory::cdwAdrOffsetHwErrWarnState%41B07978002E.attr preserve=no  public: static DWORD {UC} 0x440
      static const DWORD  m_cdwAdrOffsetHwErrWarnState;
      //## end CHITReservedSharedMemory::cdwAdrOffsetHwErrWarnState%41B07978002E.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskWCInitialized%3EBFB73303A9.attr preserve=no  public: static DWORD {UC} 0x00000001
      static const DWORD  m_cdwBitMaskWCInitialized;
      //## end CHITReservedSharedMemory::cdwBitMaskWCInitialized%3EBFB73303A9.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskWCReferenced%3EBFB771033C.attr preserve=no  public: static DWORD {UC} 0x00000002
      static const DWORD  m_cdwBitMaskWCReferenced;
      //## end CHITReservedSharedMemory::cdwBitMaskWCReferenced%3EBFB771033C.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskWCException%3EBFB7980242.attr preserve=no  public: static DWORD {UC} 0x00000008
      static const DWORD  m_cdwBitMaskWCException;
      //## end CHITReservedSharedMemory::cdwBitMaskWCException%3EBFB7980242.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskWCStoped%3EC87E17035B.attr preserve=no  public: static DWORD {UC} 0x00000004
      static const DWORD  m_cdwBitMaskWCStoped;
      //## end CHITReservedSharedMemory::cdwBitMaskWCStoped%3EC87E17035B.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskWCMeasuring%3EC8CF9B00AB.attr preserve=no  public: static DWORD {UC} 0x00000010
      static const DWORD  m_cdwBitMaskWCMeasuring;
      //## end CHITReservedSharedMemory::cdwBitMaskWCMeasuring%3EC8CF9B00AB.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskForwardScan%3EBBB5EE0203.attr preserve=no  public: static DWORD {UC} 0x80000000
      static const DWORD  m_cdwBitMaskForwardScan;
      //## end CHITReservedSharedMemory::cdwBitMaskForwardScan%3EBBB5EE0203.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskBackwardScan%3EBBB62B032C.attr preserve=no  public: static DWORD {UC} 0x40000000
      static const DWORD  m_cdwBitMaskBackwardScan;
      //## end CHITReservedSharedMemory::cdwBitMaskBackwardScan%3EBBB62B032C.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskDataBufferOverflow%3EBBB6450148.attr preserve=no  public: static DWORD {UC} 0x20000000
      static const DWORD  m_cdwBitMaskDataBufferOverflow;
      //## end CHITReservedSharedMemory::cdwBitMaskDataBufferOverflow%3EBBB6450148.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskHWError%3EBBB67603D8.attr preserve=no  public: static DWORD {UC} 0x10000000
      static const DWORD  m_cdwBitMaskHWError;
      //## end CHITReservedSharedMemory::cdwBitMaskHWError%3EBBB67603D8.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskWCEnable%3F8CED8E0290.attr preserve=no  public: static DWORD {UC} 0x00000020
      static const DWORD  m_cdwBitMaskWCEnable;
      //## end CHITReservedSharedMemory::cdwBitMaskWCEnable%3F8CED8E0290.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskWCPosReset%3F8CEDED0128.attr preserve=no  public: static DWORD {UC} 0x00000100
      static const DWORD  m_cdwBitMaskWCPosReset;
      //## end CHITReservedSharedMemory::cdwBitMaskWCPosReset%3F8CEDED0128.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskWCDirection%3F8CEE57032C.attr preserve=no  public: static DWORD {UC} 0x00000200
      static const DWORD  m_cdwBitMaskWCDirection;
      //## end CHITReservedSharedMemory::cdwBitMaskWCDirection%3F8CEE57032C.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskWCLightBarrier%3F8D073603C8.attr preserve=no  public: static DWORD {UC} 0x00010000
      static const DWORD  m_cdwBitMaskWCLightBarrier;
      //## end CHITReservedSharedMemory::cdwBitMaskWCLightBarrier%3F8D073603C8.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskWCDACValue%3F8D1163006D.attr preserve=no  public: static DWORD {UC} 0x0FFF0000
      static const DWORD  m_cdwBitMaskWCDACValue;
      //## end CHITReservedSharedMemory::cdwBitMaskWCDACValue%3F8D1163006D.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskWCDACWakeUp%3FB3769D0167.attr preserve=no  public: static DWORD {UC} 0xFFFF0000
      static const DWORD  m_cdwBitMaskWCDACWakeUp;
      //## end CHITReservedSharedMemory::cdwBitMaskWCDACWakeUp%3FB3769D0167.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskWCDigOutputs%3FB0F67A01A5.attr preserve=no  public: static DWORD {UC} 0x0000FFFF
      static const DWORD  m_cdwBitMaskWCDigOutputs;
      //## end CHITReservedSharedMemory::cdwBitMaskWCDigOutputs%3FB0F67A01A5.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskWCActValue%3F990E1E01C5.attr preserve=no  public: static DWORD {UC} 0x000FFFFF
      static const DWORD  m_cdwBitMaskWCActValue;
      //## end CHITReservedSharedMemory::cdwBitMaskWCActValue%3F990E1E01C5.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskLeadingSignWCPosition%3FAB6F460280.attr preserve=no  public: static DWORD {UC} 0x00080000
      static const DWORD  m_cdwBitMaskLeadingSignWCPosition;
      //## end CHITReservedSharedMemory::cdwBitMaskLeadingSignWCPosition%3FAB6F460280.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskPCNomVoltage%41415CCF01B5.attr preserve=no  public: static DWORD {UC} 0xFFF00000
      static const DWORD  m_cdwBitMaskPCNomVoltage;
      //## end CHITReservedSharedMemory::cdwBitMaskPCNomVoltage%41415CCF01B5.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskPCLampSel%41415E050177.attr preserve=no  public: static DWORD {UC} 0x00000002
      static const DWORD  m_cdwBitMaskPCLampSel;
      //## end CHITReservedSharedMemory::cdwBitMaskPCLampSel%41415E050177.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskPCActCurr%41415E3B032C.attr preserve=no  public: static DWORD {UC} 0x0000FFF0
      static const DWORD  m_cdwBitMaskPCActCurr;
      //## end CHITReservedSharedMemory::cdwBitMaskPCActCurr%41415E3B032C.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskPCActVolt%41415E6F02FD.attr preserve=no  public: static DWORD {UC} 0x0000FFF0
      static const DWORD  m_cdwBitMaskPCActVolt;
      //## end CHITReservedSharedMemory::cdwBitMaskPCActVolt%41415E6F02FD.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskPCOnOff%41415E8A03A9.attr preserve=no  public: static DWORD {UC} 0x1
      static const DWORD  m_cdwBitMaskPCOnOff;
      //## end CHITReservedSharedMemory::cdwBitMaskPCOnOff%41415E8A03A9.attr

      //## begin CHITReservedSharedMemory::cdwBitMaskPCLampIdent%41416F67032C.attr preserve=no  public: static DWORD {UC} 0xFFF00000
      static const DWORD  m_cdwBitMaskPCLampIdent;
      //## end CHITReservedSharedMemory::cdwBitMaskPCLampIdent%41416F67032C.attr

      //## begin CHITReservedSharedMemory::cdwWCDACValueLeftShiftCounts%3F8CEF21035B.attr preserve=no  public: static DWORD {UC} 16
      static const DWORD  m_cdwWCDACValueLeftShiftCounts;
      //## end CHITReservedSharedMemory::cdwWCDACValueLeftShiftCounts%3F8CEF21035B.attr

      //## begin CHITReservedSharedMemory::cdwLeftShiftCntPCLampOnOff%41415BBA01A5.attr preserve=no  public: static DWORD {UC} 0
      static const DWORD  m_cdwLeftShiftCntPCLampOnOff;
      //## end CHITReservedSharedMemory::cdwLeftShiftCntPCLampOnOff%41415BBA01A5.attr

      //## begin CHITReservedSharedMemory::cdwLeftShiftCntPCLampSel%41415C0F01B5.attr preserve=no  public: static DWORD {UC} 1
      static const DWORD  m_cdwLeftShiftCntPCLampSel;
      //## end CHITReservedSharedMemory::cdwLeftShiftCntPCLampSel%41415C0F01B5.attr

      //## begin CHITReservedSharedMemory::cdwLeftShiftCntPCLampNomVoltage%41415C22029F.attr preserve=no  public: static DWORD {UC} 20
      static const DWORD  m_cdwLeftShiftCntPCLampNomVoltage;
      //## end CHITReservedSharedMemory::cdwLeftShiftCntPCLampNomVoltage%41415C22029F.attr

      //## begin CHITReservedSharedMemory::cdwLeftShiftCntPCLampActCurrent%41415C70001F.attr preserve=no  public: static DWORD {UC} 4
      static const DWORD  m_cdwLeftShiftCntPCLampActCurrent;
      //## end CHITReservedSharedMemory::cdwLeftShiftCntPCLampActCurrent%41415C70001F.attr

      //## begin CHITReservedSharedMemory::cdwLeftShiftCntPCLampActVoltage%41415C98002E.attr preserve=no  public: static DWORD {UC} 4
      static const DWORD  m_cdwLeftShiftCntPCLampActVoltage;
      //## end CHITReservedSharedMemory::cdwLeftShiftCntPCLampActVoltage%41415C98002E.attr

      //## begin CHITReservedSharedMemory::cdwLeftShiftCntPCLampIdent%41415CAE03B9.attr preserve=no  public: static DWORD {UC} 20
      static const DWORD  m_cdwLeftShiftCntPCLampIdent;
      //## end CHITReservedSharedMemory::cdwLeftShiftCntPCLampIdent%41415CAE03B9.attr

    // Data Members for Associations

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3E59F2DD00EA
      //## begin CHITReservedSharedMemory::pVAdrStreamBuffer%3E59F2DD029F.role preserve=no  public: static DWORD {1..1 -> 1..1RFHN}
      static DWORD *m_pVAdrStreamBuffer;
      //## end CHITReservedSharedMemory::pVAdrStreamBuffer%3E59F2DD029F.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%3E67662301C5
      //## begin CHITReservedSharedMemory::pVAdrProcessImage%3E6766240010.role preserve=no  public: static DWORD {1..1 -> 1..1RFHN}
      static DWORD *m_pVAdrProcessImage;
      //## end CHITReservedSharedMemory::pVAdrProcessImage%3E6766240010.role

      //## Association: EBHIT (Hardware Interface Types)::<unnamed>%43FDAA3B00B3
      //## begin CHITReservedSharedMemory::bBufferOverflow%43FDAA3C0050.role preserve=no  public: static bool {1..1 -> 1..1VFHN}
      static bool m_bBufferOverflow;
      //## end CHITReservedSharedMemory::bBufferOverflow%43FDAA3C0050.role

    // Additional Private Declarations
      //## begin CHITReservedSharedMemory%3E54992F0148.private preserve=yes
      //## end CHITReservedSharedMemory%3E54992F0148.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHITReservedSharedMemory%3E54992F0148.implementation preserve=yes
      //## end CHITReservedSharedMemory%3E54992F0148.implementation

};

//## begin CHITReservedSharedMemory%3E54992F0148.postscript preserve=yes
//## end CHITReservedSharedMemory%3E54992F0148.postscript

// Class CHITReservedSharedMemory 

//## begin module%3E54997201B5.epilog preserve=yes
//## end module%3E54997201B5.epilog


#endif
