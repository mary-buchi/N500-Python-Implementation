//## begin module%3F49F814007D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F49F814007D.cm

//## begin module%3F49F814007D.cp preserve=no
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
//## end module%3F49F814007D.cp

//## Module: EBI2CADCintf%3F49F814007D; Package specification
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Source file: R:\Embedded\src\EBI2CADC\EBI2CADCintf.h

#ifndef EBI2CADCintf_h
#define EBI2CADCintf_h 1

//## begin module%3F49F814007D.additionalIncludes preserve=no
//## end module%3F49F814007D.additionalIncludes

//## begin module%3F49F814007D.includes preserve=yes
//## end module%3F49F814007D.includes

// EBPIintf
#include "EBPIintf.h"


//## begin module%3F49F814007D.declarations preserve=no
//## end module%3F49F814007D.declarations

//## begin module%3F49F814007D.additionalDeclarations preserve=yes
//## end module%3F49F814007D.additionalDeclarations


//## begin CI2CADCMAX1037%3F4A122E0232.preface preserve=yes
//## end CI2CADCMAX1037%3F4A122E0232.preface

//## Class: CI2CADCMAX1037%3F4A122E0232
//## Category: EBI2CADC (I2C ADC)%3F49CFE2030D
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F4A185E002E;I2CADC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F4A188C0186;CI2CSTDLIBCmd { -> }
//## Uses: <unnamed>%3F4A188E0109;CI2CSTDLIBConvert { -> }
//## Uses: <unnamed>%3F5D79FA0290;CHIProcessImageParameter { -> }
//## Uses: <unnamed>%3FFC18640119;CPIComponentsState { -> }
//## Uses: <unnamed>%3FFC186700BB;CPISyncObjI2CDataStream { -> }
//## Uses: <unnamed>%3FFC186A0186;CHII2CWorkerThread { -> }
//## Uses: <unnamed>%3FFC186D0138;IHIInterface { -> }
//## Uses: <unnamed>%3FFC186F02EE;XI2CADCExceptionError { -> }
//## Uses: <unnamed>%3FFC1872009C;CI2CADCMAX1037Command { -> }

class EBI2CADC_DLL_DECL CI2CADCMAX1037 : public IPII2CADCMAX1037  //## Inherits: <unnamed>%3F4A124900AB
{
  //## begin CI2CADCMAX1037%3F4A122E0232.initialDeclarations preserve=yes
  //## end CI2CADCMAX1037%3F4A122E0232.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CI2CADCMAX1037%1061804165
      CI2CADCMAX1037 (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CI2CADCMAX1037();


    //## Other Operations (specified)
      //## Operation: GetuiID%1061804158
      virtual UINT GetuiID ();

      //## Operation: Startup%1061804159
      //	DESCRIPTION
      //	Links the object to the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Startup ();

      //## Operation: Shutdown%1061804160
      //	DESCRIPTION
      //	Detaches the object from the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Shutdown ();

      //## Operation: ConnectionEstablished%1061804161
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1061804162
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

      //## Operation: GetData%1061804163
      //	DESCRIPTION
      //	gets the actual temperature
      //
      //	RETURNS
      //	async int
      virtual CPISyncObjDataADCMAX1037* GetData ();

      //## Operation: Initialize%1061804164
      //	DESCRIPTION
      //	intializes the ADC
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Initialize ();

    // Additional Public Declarations
      //## begin CI2CADCMAX1037%3F4A122E0232.public preserve=yes
      //## end CI2CADCMAX1037%3F4A122E0232.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CADCMAX1037%3F4A122E0232.protected preserve=yes
      //## end CI2CADCMAX1037%3F4A122E0232.protected

  private:
    //## Constructors (generated)
      CI2CADCMAX1037();

      CI2CADCMAX1037(const CI2CADCMAX1037 &right);

    //## Assignment Operation (generated)
      const CI2CADCMAX1037 & operator=(const CI2CADCMAX1037 &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CADCMAX1037 &right) const;

      bool operator!=(const CI2CADCMAX1037 &right) const;


    //## Other Operations (specified)
      //## Operation: Setup%1073545769
      //	DESCRIPTION
      //	setup ADC
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Setup ();

      //## Operation: Configure%1073545770
      //	DESCRIPTION
      //	configure ADC
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Configure ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: cI2CDeviceAdr%3F5D79E90167
      const BYTE GetcI2CDeviceAdr () const;

      //## Attribute: cI2CBusNumber%3F5D79E90186
      const BYTE GetcI2CBusNumber () const;

      //## Attribute: cI2CTransferSpeed%3F5D79E90196
      const BYTE GetcI2CTransferSpeed () const;

      //## Attribute: cI2CDevice%3F5D79E901A5
      const BYTE GetcI2CDevice () const;

    // Data Members for Class Attributes

      //## Attribute: cSetup%3F4A12C301F4
      //	DESCRIPTION:
      //	Setup Byte:
      //	 - Internal Reference/AIN3=Analog Input / Ref. Always ON
      //	 - External Clock (no clock streching!!!)
      //	 - Unipolar range
      //	 - no configuration register reset
      //## begin CI2CADCMAX1037::cSetup%3F4A12C301F4.attr preserve=no  private: BYTE {U} 0xDA
      BYTE m_cSetup;
      //## end CI2CADCMAX1037::cSetup%3F4A12C301F4.attr

      //## Attribute: cConfiguration%3F4A12D801A5
      //	DESCRIPTION:
      //	Configuration Byte:
      //	 - Scan from AIN0 to AINx
      //	 - AIN3 Channel Select
      //	 - Single ended
      //## begin CI2CADCMAX1037::cConfiguration%3F4A12D801A5.attr preserve=no  private: BYTE {U} 0x07
      BYTE m_cConfiguration;
      //## end CI2CADCMAX1037::cConfiguration%3F4A12D801A5.attr

      //## Attribute: cAdrWrite%3F4A13030271
      //## begin CI2CADCMAX1037::cAdrWrite%3F4A13030271.attr preserve=no  private: BYTE {U} 0xC8
      BYTE m_cAdrWrite;
      //## end CI2CADCMAX1037::cAdrWrite%3F4A13030271.attr

      //## Attribute: cAdrRead%3F4A131B0271
      //## begin CI2CADCMAX1037::cAdrRead%3F4A131B0271.attr preserve=no  private: BYTE {U} 0xC9
      BYTE m_cAdrRead;
      //## end CI2CADCMAX1037::cAdrRead%3F4A131B0271.attr

      //## begin CI2CADCMAX1037::cI2CDeviceAdr%3F5D79E90167.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CDeviceAdr;
      //## end CI2CADCMAX1037::cI2CDeviceAdr%3F5D79E90167.attr

      //## begin CI2CADCMAX1037::cI2CBusNumber%3F5D79E90186.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CBusNumber;
      //## end CI2CADCMAX1037::cI2CBusNumber%3F5D79E90186.attr

      //## begin CI2CADCMAX1037::cI2CTransferSpeed%3F5D79E90196.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CTransferSpeed;
      //## end CI2CADCMAX1037::cI2CTransferSpeed%3F5D79E90196.attr

      //## begin CI2CADCMAX1037::cI2CDevice%3F5D79E901A5.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CDevice;
      //## end CI2CADCMAX1037::cI2CDevice%3F5D79E901A5.attr

      //## Attribute: cMaskWriteAccess%3FFD0D720251
      //## begin CI2CADCMAX1037::cMaskWriteAccess%3FFD0D720251.attr preserve=no  private: BYTE {U} 0xFE
      BYTE m_cMaskWriteAccess;
      //## end CI2CADCMAX1037::cMaskWriteAccess%3FFD0D720251.attr

      //## Attribute: cMaskReadAccess%3FFD0D720280
      //## begin CI2CADCMAX1037::cMaskReadAccess%3FFD0D720280.attr preserve=no  private: BYTE {U} 0x01
      BYTE m_cMaskReadAccess;
      //## end CI2CADCMAX1037::cMaskReadAccess%3FFD0D720280.attr

      //## Attribute: cMaskADCMAX1037%3FFD0E870203
      //## begin CI2CADCMAX1037::cMaskADCMAX1037%3FFD0E870203.attr preserve=no  private: BYTE {U} 0x1
      BYTE m_cMaskADCMAX1037;
      //## end CI2CADCMAX1037::cMaskADCMAX1037%3FFD0E870203.attr

    // Data Members for Associations

      //## Association: EBI2CADC (I2C ADC)::<unnamed>%3F4A161E0186
      //## Role: CI2CADCMAX1037::uiID%3F4A161E038A
      //## begin CI2CADCMAX1037::uiID%3F4A161E038A.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CI2CADCMAX1037::uiID%3F4A161E038A.role

      //## Association: EBI2CADC (I2C ADC)::<unnamed>%3FFC17EB01F4
      //## Role: CI2CADCMAX1037::bHWPresent%3FFC17EC008D
      //## begin CI2CADCMAX1037::bHWPresent%3FFC17EC008D.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bHWPresent;
      //## end CI2CADCMAX1037::bHWPresent%3FFC17EC008D.role

    // Additional Private Declarations
      //## begin CI2CADCMAX1037%3F4A122E0232.private preserve=yes
      //## end CI2CADCMAX1037%3F4A122E0232.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CADCMAX1037%3F4A122E0232.implementation preserve=yes
      //## end CI2CADCMAX1037%3F4A122E0232.implementation

};

//## begin CI2CADCMAX1037%3F4A122E0232.postscript preserve=yes
//## end CI2CADCMAX1037%3F4A122E0232.postscript

// Class CI2CADCMAX1037 

//## begin module%3F49F814007D.epilog preserve=yes
//## end module%3F49F814007D.epilog


#endif
