//## begin module%3EE737A6001F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE737A6001F.cm

//## begin module%3EE737A6001F.cp preserve=no
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
//## end module%3EE737A6001F.cp

//## Module: EBI2CEPROMintf%3EE737A6001F; Package specification
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Source file: R:\Embedded\src\EBI2CEPROM\EBI2CEPROMintf.h

#ifndef EBI2CEPROMintf_h
#define EBI2CEPROMintf_h 1

//## begin module%3EE737A6001F.additionalIncludes preserve=no
//## end module%3EE737A6001F.additionalIncludes

//## begin module%3EE737A6001F.includes preserve=yes
//## end module%3EE737A6001F.includes

// EBPIintf
#include "EBPIintf.h"

class CI2CEpromSimulation;

//## begin module%3EE737A6001F.declarations preserve=no
//## end module%3EE737A6001F.declarations

//## begin module%3EE737A6001F.additionalDeclarations preserve=yes
//## end module%3EE737A6001F.additionalDeclarations


//## begin CI2CEprom24LC515%3EDD9FC402FD.preface preserve=yes
//## end CI2CEprom24LC515%3EDD9FC402FD.preface

//## Class: CI2CEprom24LC515%3EDD9FC402FD
//## Category: EBI2CEprom (I2C Eprom Device)%3EE73672030D
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EE830B202BF;I2CEPROM_IDENTIFIERS { -> }
//## Uses: <unnamed>%3EE830B50242;XI2CEpromExceptionError { -> }
//## Uses: <unnamed>%3EE830B703C8;CI2CSTDLIBConvert { -> }
//## Uses: <unnamed>%3EFBFB54002E;CI2CSTDLIBCmd { -> }
//## Uses: <unnamed>%3EFC0F170119;CCOSyncObject { -> }
//## Uses: <unnamed>%3F5D710C0148;CHIProcessImageParameter { -> }
//## Uses: <unnamed>%3FDDB7F5004E;CPIComponentsState { -> }
//## Uses: <unnamed>%3FDDB80903A9;CPISyncObjI2CDataStream { -> }
//## Uses: <unnamed>%3FDDB81A0399;CI2CEprom24LC515Command { -> }
//## Uses: <unnamed>%3FDDB836035B;IHIInterface { -> }
//## Uses: <unnamed>%3FDDB83E036B;CHII2CWorkerThread { -> }

class EBI2CEPROM_DLL_DECL CI2CEprom24LC515 : public IPII2CEprom24LC515  //## Inherits: <unnamed>%3EDD9FDA00CB
{
  //## begin CI2CEprom24LC515%3EDD9FC402FD.initialDeclarations preserve=yes
  //## end CI2CEprom24LC515%3EDD9FC402FD.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CI2CEprom24LC515%1054707801
      CI2CEprom24LC515 (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CI2CEprom24LC515();


    //## Other Operations (specified)
      //## Operation: Startup%1054707810
      //	DESCRIPTION
      //	Links the object to the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Startup ();

      //## Operation: Shutdown%1054707811
      //	DESCRIPTION
      //	Detaches the object from the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Shutdown ();

      //## Operation: GetuiID%1054794435
      virtual UINT GetuiID ();

      //## Operation: ByteRead%1054707802
      //	DESCRIPTION
      //	Reads a byte from the specific eprom address
      //
      //	RETURNS
      //	async int
      virtual CCOSyncObjectInt* ByteRead (WORD p_uiAddress);

      //## Operation: BlockRead%1054707803
      //	DESCRIPTION
      //	Reads a number of byte from the specific eprom address
      //
      //	RETURNS
      //	async void
      virtual CPISyncObjI2CDataStream* BlockRead (WORD p_uiAddress, UINT p_uiSize);

      //## Operation: ReadContent%1054707804
      //	DESCRIPTION
      //	Reads the all contents of the eprom
      //
      //	RETURNS
      //	void
      virtual CPISyncObjI2CDataStream* ReadContent ();

      //## Operation: ByteWrite%1054707805
      //	DESCRIPTION
      //	writes a byte to the specific eprom address
      virtual CCOSyncObject* ByteWrite (WORD p_uiAddress, BYTE p_cValue);

      //## Operation: PageWrite%1054707806
      //	DESCRIPTION
      //	writes a page size (max 64 byte) to the specific eprom
      //	address
      virtual CCOSyncObject* PageWrite (WORD p_uiAddress, BYTE* p_pcValue, UINT p_uiSize);

      //## Operation: WriteContent%1054707807
      //	DESCRIPTION
      //	writes the specified contents to the eprom
      //
      //	RETURNS
      //	void
      virtual CCOSyncObject* WriteContent (BYTE* &p_pContent, UINT p_uiDataSize);

      //## Operation: ConnectionEstablished%1056459656
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1056459657
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

      //## Operation: GetEprom24LC515SizeInByte%1061369815
      //	DESCRIPTION
      //	Gets the eprom size in byte
      //
      //	RETURNS
      //	size in byte
      virtual UINT GetEprom24LC515SizeInByte ();

      //## Operation: GetEprom24LC515PageSizeInByte%1061378414
      //	DESCRIPTION
      //	Gets the eprom page size in byte
      //
      //	RETURNS
      //	page size in byte
      virtual UINT GetEprom24LC515PageSizeInByte ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: cnPageSize%3EFC302C031C
      static int GetcnPageSize ();

    // Additional Public Declarations
      //## begin CI2CEprom24LC515%3EDD9FC402FD.public preserve=yes
      //## end CI2CEprom24LC515%3EDD9FC402FD.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CEprom24LC515%3EDD9FC402FD.protected preserve=yes
      //## end CI2CEprom24LC515%3EDD9FC402FD.protected

  private:
    //## Constructors (generated)
      CI2CEprom24LC515();

      CI2CEprom24LC515(const CI2CEprom24LC515 &right);

    //## Assignment Operation (generated)
      const CI2CEprom24LC515 & operator=(const CI2CEprom24LC515 &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CEprom24LC515 &right) const;

      bool operator!=(const CI2CEprom24LC515 &right) const;


    //## Other Operations (specified)
      //## Operation: AcknowledgePolling%1108044741
      bool AcknowledgePolling (BYTE p_cWriteCmd);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: cuiEEPROMSizeInByte%3F278BB101D4
      const UINT GetcuiEEPROMSizeInByte () const;

      //## Attribute: cI2CDeviceAdr%3F5D708C0242
      const BYTE GetcI2CDeviceAdr () const;

      //## Attribute: cI2CBusNumber%3F5D708C0251
      const BYTE GetcI2CBusNumber () const;

      //## Attribute: cI2CTransferSpeed%3F5D708C0261
      const BYTE GetcI2CTransferSpeed () const;

      //## Attribute: cI2CDevice%3F5D708C0280
      const BYTE GetcI2CDevice () const;

    // Data Members for Class Attributes

      //## Attribute: cMaskE2PROM24LC515%3EF7E9030251
      //## begin CI2CEprom24LC515::cMaskE2PROM24LC515%3EF7E9030251.attr preserve=no  private: DWORD {U} 0x1
      DWORD m_cMaskE2PROM24LC515;
      //## end CI2CEprom24LC515::cMaskE2PROM24LC515%3EF7E9030251.attr

      //## Attribute: cdwAddressBoundary%3F266367037A
      //## begin CI2CEprom24LC515::cdwAddressBoundary%3F266367037A.attr preserve=no  private: DWORD {U} 0x8000
      DWORD m_cdwAddressBoundary;
      //## end CI2CEprom24LC515::cdwAddressBoundary%3F266367037A.attr

      //## Attribute: cWriteControlByte%3EF7F35501A5
      //## begin CI2CEprom24LC515::cWriteControlByte%3EF7F35501A5.attr preserve=no  private: BYTE {U} 0xA0
      BYTE m_cWriteControlByte;
      //## end CI2CEprom24LC515::cWriteControlByte%3EF7F35501A5.attr

      //## Attribute: cReadControlByte%3EF7F35501B5
      //## begin CI2CEprom24LC515::cReadControlByte%3EF7F35501B5.attr preserve=no  private: BYTE {U} 0xA1
      BYTE m_cReadControlByte;
      //## end CI2CEprom24LC515::cReadControlByte%3EF7F35501B5.attr

      //## begin CI2CEprom24LC515::cnPageSize%3EFC302C031C.attr preserve=no  public: static int {U} 64
      static int m_cnPageSize;
      //## end CI2CEprom24LC515::cnPageSize%3EFC302C031C.attr

      //## Attribute: cBlockSelectBit%3F26346C02EE
      //## begin CI2CEprom24LC515::cBlockSelectBit%3F26346C02EE.attr preserve=no  private: BYTE {U} 0x08
      BYTE m_cBlockSelectBit;
      //## end CI2CEprom24LC515::cBlockSelectBit%3F26346C02EE.attr

      //## begin CI2CEprom24LC515::cuiEEPROMSizeInByte%3F278BB101D4.attr preserve=no  private: UINT {U} 65536
      UINT m_cuiEEPROMSizeInByte;
      //## end CI2CEprom24LC515::cuiEEPROMSizeInByte%3F278BB101D4.attr

      //## begin CI2CEprom24LC515::cI2CDeviceAdr%3F5D708C0242.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CDeviceAdr;
      //## end CI2CEprom24LC515::cI2CDeviceAdr%3F5D708C0242.attr

      //## begin CI2CEprom24LC515::cI2CBusNumber%3F5D708C0251.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CBusNumber;
      //## end CI2CEprom24LC515::cI2CBusNumber%3F5D708C0251.attr

      //## begin CI2CEprom24LC515::cI2CTransferSpeed%3F5D708C0261.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CTransferSpeed;
      //## end CI2CEprom24LC515::cI2CTransferSpeed%3F5D708C0261.attr

      //## begin CI2CEprom24LC515::cI2CDevice%3F5D708C0280.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CDevice;
      //## end CI2CEprom24LC515::cI2CDevice%3F5D708C0280.attr

    // Data Members for Associations

      //## Association: EBI2CEprom (I2C Eprom Device)::<unnamed>%3EE86D54032C
      //## Role: CI2CEprom24LC515::uiID%3EE86D550128
      //## begin CI2CEprom24LC515::uiID%3EE86D550128.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CI2CEprom24LC515::uiID%3EE86D550128.role

      //## Association: EBI2CEprom (I2C Eprom Device)::<unnamed>%3EE86D9B0128
      //## Role: CI2CEprom24LC515::hFile%3EE86D9B038B
      //## begin CI2CEprom24LC515::hFile%3EE86D9B038B.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hFile;
      //## end CI2CEprom24LC515::hFile%3EE86D9B038B.role

      //## Association: EBI2CEprom (I2C Eprom Device)::<unnamed>%3FFE813900FA
      //## Role: CI2CEprom24LC515::pEpromSimulation%3FFE813902DF
      //## begin CI2CEprom24LC515::pEpromSimulation%3FFE813902DF.role preserve=no  public: CI2CEpromSimulation {1..1 -> 1..1RFHN}
      CI2CEpromSimulation *m_pEpromSimulation;
      //## end CI2CEprom24LC515::pEpromSimulation%3FFE813902DF.role

      //## Association: EBI2CEprom (I2C Eprom Device)::<unnamed>%4002BA9B0138
      //## Role: CI2CEprom24LC515::bHWPresent%4002BA9B033C
      //## begin CI2CEprom24LC515::bHWPresent%4002BA9B033C.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bHWPresent;
      //## end CI2CEprom24LC515::bHWPresent%4002BA9B033C.role

    // Additional Private Declarations
      //## begin CI2CEprom24LC515%3EDD9FC402FD.private preserve=yes
      //## end CI2CEprom24LC515%3EDD9FC402FD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CEprom24LC515%3EDD9FC402FD.implementation preserve=yes
      //## end CI2CEprom24LC515%3EDD9FC402FD.implementation

};

//## begin CI2CEprom24LC515%3EDD9FC402FD.postscript preserve=yes
//## end CI2CEprom24LC515%3EDD9FC402FD.postscript

//## begin CI2CEpromSimulation%3FFE805A03D8.preface preserve=yes
//## end CI2CEpromSimulation%3FFE805A03D8.preface

//## Class: CI2CEpromSimulation%3FFE805A03D8
//## Category: EBI2CEprom (I2C Eprom Device)%3EE73672030D
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CI2CEpromSimulation 
{
  //## begin CI2CEpromSimulation%3FFE805A03D8.initialDeclarations preserve=yes
  //## end CI2CEpromSimulation%3FFE805A03D8.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CI2CEpromSimulation%1073630608
      CI2CEpromSimulation (const UINT p_uiID);

    //## Destructor (generated)
      virtual ~CI2CEpromSimulation();


    //## Other Operations (specified)
      //## Operation: ByteRead%1073920700
      //	DESCRIPTION
      //	writes a byte to the specific eprom address
      virtual void ByteRead (WORD p_uiAddress, BYTE* p_cValue);

      //## Operation: BlockRead%1073630609
      //	DESCRIPTION
      //	Reads a number of byte from the specific eprom address
      //
      //	RETURNS
      //	async void
      virtual void BlockRead (WORD p_uiAddress, BYTE* &p_cValue, UINT p_uiSize);

      //## Operation: ReadContent%1073630610
      //	DESCRIPTION
      //	Reads the all contents of the eprom
      //
      //	RETURNS
      //	void
      virtual void ReadContent (BYTE* &p_pContent, UINT& p_uiDataSize);

      //## Operation: ByteWrite%1073630611
      //	DESCRIPTION
      //	writes a byte to the specific eprom address
      virtual void ByteWrite (WORD p_uiAddress, BYTE p_cValue);

      //## Operation: PageWrite%1073630612
      //	DESCRIPTION
      //	writes a page size (max 64 byte) to the specific eprom
      //	address
      virtual void PageWrite (WORD p_uiAddress, BYTE* p_pcValue, UINT p_uiSize);

      //## Operation: WriteContent%1073630613
      //	DESCRIPTION
      //	writes the specified contents to the eprom
      //
      //	RETURNS
      //	void
      virtual void WriteContent (BYTE* &p_pContent, UINT p_uiDataSize);

    // Additional Public Declarations
      //## begin CI2CEpromSimulation%3FFE805A03D8.public preserve=yes
      //## end CI2CEpromSimulation%3FFE805A03D8.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CEpromSimulation%3FFE805A03D8.protected preserve=yes
      //## end CI2CEpromSimulation%3FFE805A03D8.protected

  private:
    //## Constructors (generated)
      CI2CEpromSimulation();

      CI2CEpromSimulation(const CI2CEpromSimulation &right);

    //## Assignment Operation (generated)
      const CI2CEpromSimulation & operator=(const CI2CEpromSimulation &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CEpromSimulation &right) const;

      bool operator!=(const CI2CEpromSimulation &right) const;


    //## Other Operations (specified)
      //## Operation: OpenFile%1073630614
      bool OpenFile ();

      //## Operation: CloseFile%1073630615
      void CloseFile ();

    // Data Members for Associations

      //## Association: EBI2CEprom (I2C Eprom Device)::<unnamed>%3FDDB90E005D
      //## Role: CI2CEpromSimulation::bSimulationFilePresent%3FDDB90E029F
      //## begin CI2CEpromSimulation::bSimulationFilePresent%3FDDB90E029F.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bSimulationFilePresent;
      //## end CI2CEpromSimulation::bSimulationFilePresent%3FDDB90E029F.role

      //## Association: EBI2CEprom (I2C Eprom Device)::<unnamed>%3FFE80E1038A
      //## Role: CI2CEpromSimulation::sFileName%3FFE80E30272
      //## begin CI2CEpromSimulation::sFileName%3FFE80E30272.role preserve=no  public: CString {1..1 -> 1..1VFHN}
      CString m_sFileName;
      //## end CI2CEpromSimulation::sFileName%3FFE80E30272.role

      //## Association: EBI2CEprom (I2C Eprom Device)::<unnamed>%3FFE81100109
      //## Role: CI2CEpromSimulation::File%3FFE8110038A
      //## begin CI2CEpromSimulation::File%3FFE8110038A.role preserve=no  public: CFile {1..1 -> 1..1VFHN}
      CFile m_File;
      //## end CI2CEpromSimulation::File%3FFE8110038A.role

    // Additional Private Declarations
      //## begin CI2CEpromSimulation%3FFE805A03D8.private preserve=yes
      //## end CI2CEpromSimulation%3FFE805A03D8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CEpromSimulation%3FFE805A03D8.implementation preserve=yes
      //## end CI2CEpromSimulation%3FFE805A03D8.implementation

};

//## begin CI2CEpromSimulation%3FFE805A03D8.postscript preserve=yes
//## end CI2CEpromSimulation%3FFE805A03D8.postscript

// Class CI2CEprom24LC515 

// Class CI2CEpromSimulation 

//## begin module%3EE737A6001F.epilog preserve=yes
//## end module%3EE737A6001F.epilog


#endif
