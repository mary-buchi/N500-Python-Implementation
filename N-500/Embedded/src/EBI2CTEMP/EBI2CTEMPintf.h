//## begin module%3EE737460186.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE737460186.cm

//## begin module%3EE737460186.cp preserve=no
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
//## end module%3EE737460186.cp

//## Module: EBI2CTEMPintf%3EE737460186; Package specification
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Source file: R:\Embedded\src\EBI2CTEMP\EBI2CTEMPintf.h

#ifndef EBI2CTEMPintf_h
#define EBI2CTEMPintf_h 1

//## begin module%3EE737460186.additionalIncludes preserve=no
//## end module%3EE737460186.additionalIncludes

//## begin module%3EE737460186.includes preserve=yes
//## end module%3EE737460186.includes

// EBPIintf
#include "EBPIintf.h"


//## begin module%3EE737460186.declarations preserve=no
//## end module%3EE737460186.declarations

//## begin module%3EE737460186.additionalDeclarations preserve=yes
//## end module%3EE737460186.additionalDeclarations


//## begin CI2CTempSensorDS1631Z%3EDD8EC503D8.preface preserve=yes
//## end CI2CTempSensorDS1631Z%3EDD8EC503D8.preface

//## Class: CI2CTempSensorDS1631Z%3EDD8EC503D8
//## Category: EBI2CTemp (I2C Temperature Device)%3EE73654004E
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EE818FF037A;I2CTEMP_IDENTIFIERS { -> }
//## Uses: <unnamed>%3EE8226F0177;CI2CSTDLIBConvert { -> }
//## Uses: <unnamed>%3EE8803402CE;XI2CTempExceptionError { -> }
//## Uses: <unnamed>%3EE893C00271;CI2CSTDLIBCmd { -> }
//## Uses: <unnamed>%3F5C688203D8;CHIProcessImageParameter { -> }
//## Uses: <unnamed>%3F5DC74B0232;IHIInterface { -> }
//## Uses: <unnamed>%3FD8217B032C;CHII2CWorkerThread { -> }
//## Uses: <unnamed>%3FD8239B005D;CI2CTempSensor1631ZCommand { -> }
//## Uses: <unnamed>%3FD832D202EE;CPISyncObjI2CDataStream { -> }
//## Uses: <unnamed>%3FDDB7EB0128;CPIComponentsState { -> }

class EBI2CTEMP_DLL_DECL CI2CTempSensorDS1631Z : public IPII2CTempSensorDS1631Z  //## Inherits: <unnamed>%3EDD8EDA0280
{
  //## begin CI2CTempSensorDS1631Z%3EDD8EC503D8.initialDeclarations preserve=yes
  //## end CI2CTempSensorDS1631Z%3EDD8EC503D8.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CI2CTempSensorDS1631Z%1054707797
      CI2CTempSensorDS1631Z (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CI2CTempSensorDS1631Z();


    //## Other Operations (specified)
      //## Operation: Startup%1054707808
      //	DESCRIPTION
      //	Links the object to the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Startup ();

      //## Operation: Shutdown%1054707809
      //	DESCRIPTION
      //	Detaches the object from the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Shutdown ();

      //## Operation: GetuiID%1054794434
      virtual UINT GetuiID ();

      //## Operation: SetSensorConfig%1054707798
      //	DESCRIPTION
      //	sets the appropriate temperature sensor configuration
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetSensorConfig (CPIConfigDS1631Z* p_pConfig);

      //## Operation: GetSensorConfig%1054707799
      //	DESCRIPTION
      //	gets the appropriate temperature sensor configuration
      //
      //	RETURNS
      //	async int
      virtual CCOSyncObjectInt* GetSensorConfig ();

      //## Operation: GetTemperature%1054707800
      //	DESCRIPTION
      //	gets the actual temperature
      //
      //	RETURNS
      //	async int
      virtual CCOSyncObjectInt* GetTemperature ();

      //## Operation: ConnectionEstablished%1056459658
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1056459659
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

    // Additional Public Declarations
      //## begin CI2CTempSensorDS1631Z%3EDD8EC503D8.public preserve=yes
      //## end CI2CTempSensorDS1631Z%3EDD8EC503D8.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CTempSensorDS1631Z%3EDD8EC503D8.protected preserve=yes
      //## end CI2CTempSensorDS1631Z%3EDD8EC503D8.protected

  private:
    //## Constructors (generated)
      CI2CTempSensorDS1631Z();

      CI2CTempSensorDS1631Z(const CI2CTempSensorDS1631Z &right);

    //## Assignment Operation (generated)
      const CI2CTempSensorDS1631Z & operator=(const CI2CTempSensorDS1631Z &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CTempSensorDS1631Z &right) const;

      bool operator!=(const CI2CTempSensorDS1631Z &right) const;


    //## Other Operations (specified)
      //## Operation: StartTemperatureConvertion%1056519544
      //	DESCRIPTION
      //	starts the temperature convertion
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* StartTemperatureConvertion ();

      //## Operation: StopTemperatureConvertion%1056519545
      //	DESCRIPTION
      //	stops the temperature convertion
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* StopTemperatureConvertion ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: cI2CDeviceAdr%3F5C507D03D8
      const BYTE GetcI2CDeviceAdr () const;

      //## Attribute: cI2CBusNumber%3F5C51070186
      const BYTE GetcI2CBusNumber () const;

      //## Attribute: cI2CTransferSpeed%3F5C51080109
      const BYTE GetcI2CTransferSpeed () const;

      //## Attribute: cI2CDevice%3F5C752C00EA
      const BYTE GetcI2CDevice () const;

    // Data Members for Class Attributes

      //## Attribute: cStartConvertT%3EDDEBF202BF
      //## begin CI2CTempSensorDS1631Z::cStartConvertT%3EDDEBF202BF.attr preserve=no  private: BYTE {U} 0x51
      BYTE m_cStartConvertT;
      //## end CI2CTempSensorDS1631Z::cStartConvertT%3EDDEBF202BF.attr

      //## Attribute: cStopConvertT%3EDDEC4101F4
      //## begin CI2CTempSensorDS1631Z::cStopConvertT%3EDDEC4101F4.attr preserve=no  private: BYTE {U} 0x22
      BYTE m_cStopConvertT;
      //## end CI2CTempSensorDS1631Z::cStopConvertT%3EDDEC4101F4.attr

      //## Attribute: cReadTemperature%3EDDEC53034B
      //## begin CI2CTempSensorDS1631Z::cReadTemperature%3EDDEC53034B.attr preserve=no  private: BYTE {U} 0xAA
      BYTE m_cReadTemperature;
      //## end CI2CTempSensorDS1631Z::cReadTemperature%3EDDEC53034B.attr

      //## Attribute: cAccessTH%3EDDEC7201D4
      //## begin CI2CTempSensorDS1631Z::cAccessTH%3EDDEC7201D4.attr preserve=no  private: BYTE {U} 0xA1
      BYTE m_cAccessTH;
      //## end CI2CTempSensorDS1631Z::cAccessTH%3EDDEC7201D4.attr

      //## Attribute: cAccessTL%3EDDEC8A02FD
      //## begin CI2CTempSensorDS1631Z::cAccessTL%3EDDEC8A02FD.attr preserve=no  private: BYTE {U} 0xA2
      BYTE m_cAccessTL;
      //## end CI2CTempSensorDS1631Z::cAccessTL%3EDDEC8A02FD.attr

      //## Attribute: cAccessConfig%3EDDEC9A034B
      //## begin CI2CTempSensorDS1631Z::cAccessConfig%3EDDEC9A034B.attr preserve=no  private: BYTE {U} 0xAC
      BYTE m_cAccessConfig;
      //## end CI2CTempSensorDS1631Z::cAccessConfig%3EDDEC9A034B.attr

      //## Attribute: cSoftwarePOR%3EDDECAE01A5
      //## begin CI2CTempSensorDS1631Z::cSoftwarePOR%3EDDECAE01A5.attr preserve=no  private: BYTE {U} 0x54
      BYTE m_cSoftwarePOR;
      //## end CI2CTempSensorDS1631Z::cSoftwarePOR%3EDDECAE01A5.attr

      //## Attribute: cWriteControlByte%3EDEFE5B01A5
      //## begin CI2CTempSensorDS1631Z::cWriteControlByte%3EDEFE5B01A5.attr preserve=no  private: BYTE {U} 0x90
      BYTE m_cWriteControlByte;
      //## end CI2CTempSensorDS1631Z::cWriteControlByte%3EDEFE5B01A5.attr

      //## Attribute: cReadControlByte%3EDF0EB60138
      //## begin CI2CTempSensorDS1631Z::cReadControlByte%3EDF0EB60138.attr preserve=no  private: BYTE {U} 0x91
      BYTE m_cReadControlByte;
      //## end CI2CTempSensorDS1631Z::cReadControlByte%3EDF0EB60138.attr

      //## Attribute: cMaskTempSensorDS1631Z%3EDDF4F20399
      //## begin CI2CTempSensorDS1631Z::cMaskTempSensorDS1631Z%3EDDF4F20399.attr preserve=no  private: BYTE {U} 0x1
      BYTE m_cMaskTempSensorDS1631Z;
      //## end CI2CTempSensorDS1631Z::cMaskTempSensorDS1631Z%3EDDF4F20399.attr

      //## Attribute: cdwMaskAddressOffset%3EDDF53103B9
      //## begin CI2CTempSensorDS1631Z::cdwMaskAddressOffset%3EDDF53103B9.attr preserve=no  private: DWORD {U} 0x00007000
      DWORD m_cdwMaskAddressOffset;
      //## end CI2CTempSensorDS1631Z::cdwMaskAddressOffset%3EDDF53103B9.attr

      //## Attribute: cbMaskTempResolution%3EE96D60004E
      //## begin CI2CTempSensorDS1631Z::cbMaskTempResolution%3EE96D60004E.attr preserve=no  private: BYTE {U} 0xC
      BYTE m_cbMaskTempResolution;
      //## end CI2CTempSensorDS1631Z::cbMaskTempResolution%3EE96D60004E.attr

      //## Attribute: cdwAddressRightShifter%3EDDF574008C
      //## begin CI2CTempSensorDS1631Z::cdwAddressRightShifter%3EDDF574008C.attr preserve=no  private: DWORD {U} 0xC
      DWORD m_cdwAddressRightShifter;
      //## end CI2CTempSensorDS1631Z::cdwAddressRightShifter%3EDDF574008C.attr

      //## Attribute: cnTempUnit%3EE9B8C300EA
      //	Temperature Unit m°C
      //## begin CI2CTempSensorDS1631Z::cnTempUnit%3EE9B8C300EA.attr preserve=no  private: int {U} 1000
      int m_cnTempUnit;
      //## end CI2CTempSensorDS1631Z::cnTempUnit%3EE9B8C300EA.attr

      //## begin CI2CTempSensorDS1631Z::cI2CDeviceAdr%3F5C507D03D8.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CDeviceAdr;
      //## end CI2CTempSensorDS1631Z::cI2CDeviceAdr%3F5C507D03D8.attr

      //## begin CI2CTempSensorDS1631Z::cI2CBusNumber%3F5C51070186.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CBusNumber;
      //## end CI2CTempSensorDS1631Z::cI2CBusNumber%3F5C51070186.attr

      //## begin CI2CTempSensorDS1631Z::cI2CTransferSpeed%3F5C51080109.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CTransferSpeed;
      //## end CI2CTempSensorDS1631Z::cI2CTransferSpeed%3F5C51080109.attr

      //## begin CI2CTempSensorDS1631Z::cI2CDevice%3F5C752C00EA.attr preserve=no  private: BYTE {U} 
      BYTE m_cI2CDevice;
      //## end CI2CTempSensorDS1631Z::cI2CDevice%3F5C752C00EA.attr

    // Data Members for Associations

      //## Association: EBI2CTemp (I2C Temperature Device)::<unnamed>%3EE8760D0280
      //## Role: CI2CTempSensorDS1631Z::hFile%3EE8760E011A
      //## begin CI2CTempSensorDS1631Z::hFile%3EE8760E011A.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hFile;
      //## end CI2CTempSensorDS1631Z::hFile%3EE8760E011A.role

      //## Association: EBI2CTemp (I2C Temperature Device)::<unnamed>%3EE87628004E
      //## Role: CI2CTempSensorDS1631Z::uiID%3EE87628034B
      //## begin CI2CTempSensorDS1631Z::uiID%3EE87628034B.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CI2CTempSensorDS1631Z::uiID%3EE87628034B.role

      //## Association: EBI2CTemp (I2C Temperature Device)::<unnamed>%3EE96CDB029F
      //## Role: CI2CTempSensorDS1631Z::eTempResolution%3EE96CDC00EB
      //## begin CI2CTempSensorDS1631Z::eTempResolution%3EE96CDC00EB.role preserve=no  public: EPIResolutionDS1631Z {1..1 -> 1..1VFHN}
      EPIResolutionDS1631Z m_eTempResolution;
      //## end CI2CTempSensorDS1631Z::eTempResolution%3EE96CDC00EB.role

      //## Association: EBI2CTemp (I2C Temperature Device)::<unnamed>%3EF956D60177
      //## Role: CI2CTempSensorDS1631Z::eConversionMode%3EF956D7003E
      //## begin CI2CTempSensorDS1631Z::eConversionMode%3EF956D7003E.role preserve=no  public: EPIModeDS1631Z {1..1 -> 1..1VFHN}
      EPIModeDS1631Z m_eConversionMode;
      //## end CI2CTempSensorDS1631Z::eConversionMode%3EF956D7003E.role

      //## Association: EBI2CTemp (I2C Temperature Device)::<unnamed>%3F9FBB7F02F4
      //## Role: CI2CTempSensorDS1631Z::bHWPresent%3F9FBB800101
      //## begin CI2CTempSensorDS1631Z::bHWPresent%3F9FBB800101.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bHWPresent;
      //## end CI2CTempSensorDS1631Z::bHWPresent%3F9FBB800101.role

    // Additional Private Declarations
      //## begin CI2CTempSensorDS1631Z%3EDD8EC503D8.private preserve=yes
      //## end CI2CTempSensorDS1631Z%3EDD8EC503D8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CTempSensorDS1631Z%3EDD8EC503D8.implementation preserve=yes
      //## end CI2CTempSensorDS1631Z%3EDD8EC503D8.implementation

};

//## begin CI2CTempSensorDS1631Z%3EDD8EC503D8.postscript preserve=yes
//## end CI2CTempSensorDS1631Z%3EDD8EC503D8.postscript

// Class CI2CTempSensorDS1631Z 

//## begin module%3EE737460186.epilog preserve=yes
//## end module%3EE737460186.epilog


#endif
