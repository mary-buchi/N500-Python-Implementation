//## begin module%3DA2A5A102CD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA2A5A102CD.cm

//## begin module%3DA2A5A102CD.cp preserve=no
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
//## end module%3DA2A5A102CD.cp

//## Module: EBETmesg%3DA2A5A102CD; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETmesg.h

#ifndef EBETmesg_h
#define EBETmesg_h 1

//## begin module%3DA2A5A102CD.additionalIncludes preserve=no
//## end module%3DA2A5A102CD.additionalIncludes

//## begin module%3DA2A5A102CD.includes preserve=yes
//## end module%3DA2A5A102CD.includes

// EBPIenum
#include "EBPIenum.h"

class EBCO_DLL_DECL CCOIntegerArray;
class EBPI_DLL_DECL CPIPersistentSoftwareComponentVersion;
class EBPI_DLL_DECL CPIMeasurementChannelDataPackage;
class EBPI_DLL_DECL CPIMeasurementChannelProfile;
class EBPI_DLL_DECL CPIWedgeControlConfig;
class EBPI_DLL_DECL CPIWedgeControlProfile;
class EBPI_DLL_DECL CPIPowerControlProfile;
class EBPI_DLL_DECL CPITemperatureControlConfig;
class EBPI_DLL_DECL CPITemperatureControlProfile;
class EBPI_DLL_DECL CPIConfigDS1631Z;
class EBPI_DLL_DECL CPIInterfaceConfig;
class EBPI_DLL_DECL CPIStepperMotorProfile;
class EBPI_DLL_DECL CPIStepperMotorConfig;
class EBPI_DLL_DECL CPIPersistentSoftwareComponentList;
class EBPI_DLL_DECL CPIPersistentItemList;
class EBPI_DLL_DECL CPIPowerControlConfig;
class EBPI_DLL_DECL CPIPersistentConfig;
class EBPI_DLL_DECL CPIDataADCMAX1037;

//## begin module%3DA2A5A102CD.declarations preserve=no
//## end module%3DA2A5A102CD.declarations

//## begin module%3DA2A5A102CD.additionalDeclarations preserve=yes
//## end module%3DA2A5A102CD.additionalDeclarations


//## begin EETChannelCommand%3DA2A62202FB.preface preserve=yes
//## end EETChannelCommand%3DA2A62202FB.preface

//## Class: EETChannelCommand%3DA2A62202FB
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {
  eObjCrDeleteObject              = 0,
  eObjCrMotorStepper              = 1,
  eObjCrMeasurementChannel        = 2,
  eObjCrSensorAnalog              = 3,
  eObjCrSensorDigital             = 4,
  eObjCrOutputAnalog              = 5,
  eObjCrOutputDigital             = 6,
  eObjCrTemperatureControl        = 7,
  eObjCrPowerControl              = 8,
  eObjCrWedgeControl              = 9,
  eObjCrEventSource               = 10,
  eObJCrPersistentObjMananager    = 11,
  eObjCrDiagnostics               = 12,
  eObjCrSystem                    = 13,
  eObjCrI2CTempSensorDS1631Z      = 14,
  eObjCrI2CAdcMax1037             = 15,
  eObjCrI2CDigitalPotiAD5245      = 16,
  
  eCmdStartup                     = 20,
  eCmdShutdown                    = 21,
  eCmdErrorReply                    = 22,
  
  eCmdStepperMoveAbsolute         = 30,
  eCmdStepperMoveRelative         = 31,
  eCmdStepperMoveManual           = 32,
  eCmdStepperGetPosition          = 35,
  eCmdStepperStop                 = 36,
  eCmdStepperStopImmediately      = 37,
  eCmdStepperSetProfile           = 40,
  eCmdStepperSetSpeed             = 41,
  eCmdStepperLimitAdd             = 45,
  eCmdStepperLimitConfig          = 46,
  eCmdStepperLimitGetFootPrint    = 47,
  eCmdStepperLimitActivate        = 48,
  eCmdStepperLimitDeactivate      = 49,
  eCmdStepperHome                 = 55,
  eCmdStepperHomeSetPosition      = 56,
  eCmdStepperSetConfig            = 57,
  eCmdStepperHome2                = 58,
  
  eCmdMeasChannelSetProfile       = 60,
  eCmdMeasChannelInitialize       = 61,
  eCmdMeasChannelStart            = 62,
  eCmdMeasChannelStop             = 63,
  eCmdMeasChannelGetDataPackage   = 64,
  
  eCmdSensorAnalogGetValue        = 70,
  eCmdSensorDigitalIsActive       = 71,
  eCmdSensorDigitalSetPolarity    = 72,
  
  eCmdOutputAnalogSetValue        = 80,
  eCmdOutputAnalogGetValue        = 81,
  eCmdOutputDigitalSet            = 85,
  eCmdOutputDigitalClear          = 86,
  eCmdOutputDigitalIsActive       = 87,
  eCmdOutputDigitalSetPolarity    = 88,
  
  eCmdTempCtrlSetProfile          = 100,
  eCmdTempCtrlSetConfig           = 101,
  eCmdTempCtrlGetTemperature      = 102,
  eCmdTempCtrlStart               = 103,
  eCmdTempCtrlStop                = 104,
  
  eCmdPwrCtrlSetProfile           = 110,
  eCmdPwrCtrlSetConfig            = 111,
  eCmdPwrCtrlStart                = 112,
  eCmdPwrCtrlStop                 = 113,
  eCmdPwrCtrlPowerOn          = 114,
  eCmdPwrCtrlPowerOff          = 115,
  
  eCmdWedgeCtrlSetProfile         = 120,
  eCmdWedgeCtrlSetConfig          = 121,
  eCmdWedgeCtrlPark               = 122,
  eCmdWedgeCtrlInitialize         = 123,
  eCmdWedgeCtrlReference          = 124,
  eCmdWedgeCtrlStart              = 125,
  eCmdWedgeCtrlStop               = 126,
  eCmdWedgeCtrlGetDacZeroCurrent = 127,

  eCmdEventSourceRegister         = 130,
  eCmdEventSourceUnregister       = 131,

  eCmdPsObjReadParameters         = 140,
  eCmdPsObjWriteParameter         = 141,
  eCmdPsObjStartMonitoring        = 142,
  eCmdPsObjStopMonitoring         = 143,
  eCmdPsObjSave                   = 144,
  eCmdPsObjReadLifeTimeCounter    = 145,
  eCmdPsObjWriteLifeTimeCounter   = 146,
  eCmdPsObjReadIdentifications    = 147,
  eCmdPsObjWriteIdentification    = 148,
  eCmdPsObjSetConfig              = 149,
  eCmdPsObjReset                  = 150,
  eCmdPsObjCellUndocked     = 151,

  eCmdDiagReadDWord               = 160,
  eCmdDiagWriteDWord              = 161,
  eCmdDiagEnableEventSignal       = 162,
  eCmdDiagDisableEventSignal      = 163,
  eCmdDiagPCSetNomVoltage         = 164,
  eCmdDiagPCLampSelection         = 165,
  eCmdDiagPCLampOnOff             = 166,
  eCmdDiagPCGetActCurrent         = 167,
  eCmdDiagPCGetActVoltage         = 168,
  eCmdDiagPCGetLampIdentification = 169,
  eCmdDiagWCGetActVelocityCounts  = 170,
  eCmdDiagWCGetLastVelocityCounts = 171,
  eCmdDiagWCGetPosition           = 172,
  eCmdDiagWCInitializeDAC         = 173,
  eCmdDiagWCSetDACValue           = 174,
  eCmdDiagReadFpgaArtNr           = 175,
  eCmdDiagReadFpgaSwVersion       = 176,
  eCmdDiagI2CEpromByteRead        = 177,
  eCmdDiagI2CEpromByteWrite       = 178,
  eCmdDiagGetDigitsLaserLevelDetection  = 179,
  eCmdDiagReleaseHWReset                = 180,
  eCmdDiagDisableWatchdog               = 181,
  eCmdDiagGetOsVersion                      = 182,
  eCmdDiagGetUsedMemory           = 183,
  eCmdDiagGetMemoryAllocInfo      = 184,

  eCmdSysGetState                 = 200,
  eCmdSysReset                    = 201,
  eCmdSysStart                    = 202,
  eCmdSysReadIdentifications      = 203,
  eCmdSysWriteIdentification      = 204,
  eCmdSysReadSWVersions           = 205,
  eCmdSysDownloadSoftware         = 206,
  eCmdSysSetInterfaceConfig       = 207,
  eCmdSysSetComponentState        = 208,
  eCmdSysGetObjectList            = 209,
  eCmdSysSetTime                  = 210,
  eCmdSysRegisterClient        = 211,
  eCmdSysGetVersion              = 212,
  eCmdSysSetStandbyTimeout = 213,
  eCmdSysPing                         = 214,
  eCmdSysGetOsVersion             = 215,
  eCmdSysGetFpgaVersion           = 216, 
  eCmdSysStartDownload             = 217,
  eCmdSysDownloadSoftwareComponent   = 218,
  eCmdSysEndDownload              = 219,

  eCmdI2CTempDS1631ZStartup       = 250,
  eCmdI2CTempDS1631ZShutdown      = 251,
  eCmdI2CTempDS1631ZSetConfig     = 252,
  eCmdI2CTempDS1631ZGetValue      = 253,

  eCmdI2CAdcMax1037Startup        = 260,
  eCmdI2CAdcMax1037Shutdown       = 261,
  eCmdI2CAdcMax1037Initialize     = 262,
  eCmdI2CAdcMax1037GetData        = 263,

  eCmdI2CPotiAD5245Startup        = 270,
  eCmdI2CPotiAD5245Shutdown       = 271,
  eCmdI2CPotiAD5245WriteValue     = 272,
  eCmdI2CPotiAD5245ReadValue      = 273,


  eCmdNameConnection     = 300,
 }
 EETChannelCommand;

//## begin EETChannelCommand%3DA2A62202FB.postscript preserve=yes
//## end EETChannelCommand%3DA2A62202FB.postscript

//## begin EETChannelExpectedReturn%3DA2A6670221.preface preserve=yes
//## end EETChannelExpectedReturn%3DA2A6670221.preface

//## Class: EETChannelExpectedReturn%3DA2A6670221
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {
  eNone,
  eEvent } EETChannelExpectedReturn;

//## begin EETChannelExpectedReturn%3DA2A6670221.postscript preserve=yes
//## end EETChannelExpectedReturn%3DA2A6670221.postscript

//## begin EETChannelMessageType%3DA2BA7F02FB.preface preserve=yes
//## end EETChannelMessageType%3DA2BA7F02FB.preface

//## Class: EETChannelMessageType%3DA2BA7F02FB
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {
  eInitial,
  eReply } EETChannelMessageType;

//## begin EETChannelMessageType%3DA2BA7F02FB.postscript preserve=yes
//## end EETChannelMessageType%3DA2BA7F02FB.postscript

//## begin CETChannelMessage%3DA2A5C40146.preface preserve=yes
//## end CETChannelMessage%3DA2A5C40146.preface

//## Class: CETChannelMessage%3DA2A5C40146
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DA2B7CE0156;EETChannelCommand { -> }
//## Uses: <unnamed>%3DA2B7D00398;EETChannelExpectedReturn { -> }
//## Uses: <unnamed>%3DA2BAA201F2;EETChannelMessageType { -> }
//## Uses: <unnamed>%40642F2803A9;XCOExceptionErrorMemoryAllocation { -> }

class CETChannelMessage 
{
  //## begin CETChannelMessage%3DA2A5C40146.initialDeclarations preserve=yes
  //## end CETChannelMessage%3DA2A5C40146.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelMessage(const CETChannelMessage &right);

    //## Constructors (specified)
      //## Operation: CETChannelMessage%1034074177
      CETChannelMessage (UINT p_uiID, EETChannelCommand p_eCommand, EETChannelExpectedReturn p_eExpectedReturn, INT p_iData, UINT p_uiObjRefID, UINT p_uiTelegramSize = m_uiBaseMessageSize);

      //## Operation: CETChannelMessage%1034074178
      CETChannelMessage (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessage();


    //## Other Operations (specified)
      //## Operation: Serialize%1034074179
      virtual void Serialize (BYTE*& p_byStream, INT& p_iStreamLength);

      //## Operation: GetReply%1034074180
      CETChannelMessage* GetReply ();

      //## Operation: GetErrorReply%1080293050
      CETChannelMessage* GetErrorReply (const UINT p_uiExceptionID);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: uiTelegramSize%3DB002DC005A
      UINT GetuiTelegramSize ();

      //## Attribute: uiID%3DA2A5F3034A
      UINT GetuiID ();

      //## Attribute: eCommand%3DA2A61503D6
      EETChannelCommand GeteCommand ();

      //## Attribute: eExpectedReturn%3DA2A69D0359
      EETChannelExpectedReturn GeteExpectedReturn ();

      //## Attribute: uiObjRefID%3DA2A6C80184
      UINT GetuiObjRefID ();
      void SetuiObjRefID (UINT value);

      //## Attribute: iData%3DA2A716003C
      INT GetiData ();
      void SetiData (INT value);

      //## Attribute: uiExceptionID%3DA2D72D02DC
      void SetuiExceptionID (UINT value);

      //## Attribute: sObjRefVersion%3DA2D74C0165
      WCHAR* GetsObjRefVersion ();
      void SetsObjRefVersion (WCHAR* value);

    // Additional Public Declarations
      //## begin CETChannelMessage%3DA2A5C40146.public preserve=yes
      //## end CETChannelMessage%3DA2A5C40146.public

  protected:
    // Data Members for Class Attributes

      //## begin CETChannelMessage::uiTelegramSize%3DB002DC005A.attr preserve=no  public: UINT {U} 
      UINT m_uiTelegramSize;
      //## end CETChannelMessage::uiTelegramSize%3DB002DC005A.attr

      //## begin CETChannelMessage::uiID%3DA2A5F3034A.attr preserve=no  public: UINT {U} 
      UINT m_uiID;
      //## end CETChannelMessage::uiID%3DA2A5F3034A.attr

      //## begin CETChannelMessage::eCommand%3DA2A61503D6.attr preserve=no  public: EETChannelCommand {U} 
      EETChannelCommand m_eCommand;
      //## end CETChannelMessage::eCommand%3DA2A61503D6.attr

      //## begin CETChannelMessage::eExpectedReturn%3DA2A69D0359.attr preserve=no  public: EETChannelExpectedReturn {U} 
      EETChannelExpectedReturn m_eExpectedReturn;
      //## end CETChannelMessage::eExpectedReturn%3DA2A69D0359.attr

      //## begin CETChannelMessage::uiObjRefID%3DA2A6C80184.attr preserve=no  public: UINT {U} 
      UINT m_uiObjRefID;
      //## end CETChannelMessage::uiObjRefID%3DA2A6C80184.attr

      //## begin CETChannelMessage::iData%3DA2A716003C.attr preserve=no  public: INT {U} 
      INT m_iData;
      //## end CETChannelMessage::iData%3DA2A716003C.attr

      //## Attribute: eType%3DA2BAAB025F
      //## begin CETChannelMessage::eType%3DA2BAAB025F.attr preserve=no  private: EETChannelMessageType {U} 
      EETChannelMessageType m_eType;
      //## end CETChannelMessage::eType%3DA2BAAB025F.attr

      //## begin CETChannelMessage::uiExceptionID%3DA2D72D02DC.attr preserve=no  public: UINT {U} 
      UINT m_uiExceptionID;
      //## end CETChannelMessage::uiExceptionID%3DA2D72D02DC.attr

      //## begin CETChannelMessage::sObjRefVersion%3DA2D74C0165.attr preserve=no  public: WCHAR[16] {U} 
      WCHAR m_sObjRefVersion[16];
      //## end CETChannelMessage::sObjRefVersion%3DA2D74C0165.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DB3A4E302F7
      //## Role: CETChannelMessage::uiBaseMessageSize%3DB3A4E401AF
      //## begin CETChannelMessage::uiBaseMessageSize%3DB3A4E401AF.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
      static UINT m_uiBaseMessageSize;
      //## end CETChannelMessage::uiBaseMessageSize%3DB3A4E401AF.role

    // Additional Protected Declarations
      //## begin CETChannelMessage%3DA2A5C40146.protected preserve=yes
      //## end CETChannelMessage%3DA2A5C40146.protected

  private:
    //## Constructors (generated)
      CETChannelMessage();

    //## Assignment Operation (generated)
      const CETChannelMessage & operator=(const CETChannelMessage &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessage &right) const;

      bool operator!=(const CETChannelMessage &right) const;

    // Additional Private Declarations
      //## begin CETChannelMessage%3DA2A5C40146.private preserve=yes
      //## end CETChannelMessage%3DA2A5C40146.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessage%3DA2A5C40146.implementation preserve=yes
      //## end CETChannelMessage%3DA2A5C40146.implementation

};

//## begin CETChannelMessage%3DA2A5C40146.postscript preserve=yes
//## end CETChannelMessage%3DA2A5C40146.postscript

//## begin CETChannelMessageMeasurementDataPackage%3DAFADFE022D.preface preserve=yes
//## end CETChannelMessageMeasurementDataPackage%3DAFADFE022D.preface

//## Class: CETChannelMessageMeasurementDataPackage%3DAFADFE022D
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageMeasurementDataPackage : public CETChannelMessage  //## Inherits: <unnamed>%3DD4C41200D5
{
  //## begin CETChannelMessageMeasurementDataPackage%3DAFADFE022D.initialDeclarations preserve=yes
  //## end CETChannelMessageMeasurementDataPackage%3DAFADFE022D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageMeasurementDataPackage%1034922741
      CETChannelMessageMeasurementDataPackage (CETChannelMessage* p_pStdMessage);

    //## Destructor (generated)
      virtual ~CETChannelMessageMeasurementDataPackage();


    //## Other Operations (specified)
      //## Operation: Serialize%1034922742
      virtual void Serialize (BYTE*& p_byStream, INT& p_iStreamLength);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DAFB1290039
      //## Role: CETChannelMessageMeasurementDataPackage::pDataPackage%3DAFB12902BB
      void SetpDataPackage (CPIMeasurementChannelDataPackage * value);

    // Additional Public Declarations
      //## begin CETChannelMessageMeasurementDataPackage%3DAFADFE022D.public preserve=yes
      //## end CETChannelMessageMeasurementDataPackage%3DAFADFE022D.public

  protected:
    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DB3A5420335
      //## Role: CETChannelMessageMeasurementDataPackage::uiMessageSize%3DB3A5430162
      //## begin CETChannelMessageMeasurementDataPackage::uiMessageSize%3DB3A5430162.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
      static UINT m_uiMessageSize;
      //## end CETChannelMessageMeasurementDataPackage::uiMessageSize%3DB3A5430162.role

    // Additional Protected Declarations
      //## begin CETChannelMessageMeasurementDataPackage%3DAFADFE022D.protected preserve=yes
      //## end CETChannelMessageMeasurementDataPackage%3DAFADFE022D.protected

  private:
    //## Constructors (generated)
      CETChannelMessageMeasurementDataPackage();

      CETChannelMessageMeasurementDataPackage(const CETChannelMessageMeasurementDataPackage &right);

    //## Assignment Operation (generated)
      const CETChannelMessageMeasurementDataPackage & operator=(const CETChannelMessageMeasurementDataPackage &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageMeasurementDataPackage &right) const;

      bool operator!=(const CETChannelMessageMeasurementDataPackage &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DAFB1290039
      //## begin CETChannelMessageMeasurementDataPackage::pDataPackage%3DAFB12902BB.role preserve=no  public: CPIMeasurementChannelDataPackage {1..1 -> 1..1RFHN}
      CPIMeasurementChannelDataPackage *m_pDataPackage;
      //## end CETChannelMessageMeasurementDataPackage::pDataPackage%3DAFB12902BB.role

    // Additional Private Declarations
      //## begin CETChannelMessageMeasurementDataPackage%3DAFADFE022D.private preserve=yes
      //## end CETChannelMessageMeasurementDataPackage%3DAFADFE022D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageMeasurementDataPackage%3DAFADFE022D.implementation preserve=yes
      //## end CETChannelMessageMeasurementDataPackage%3DAFADFE022D.implementation

};

//## begin CETChannelMessageMeasurementDataPackage%3DAFADFE022D.postscript preserve=yes
//## end CETChannelMessageMeasurementDataPackage%3DAFADFE022D.postscript

//## begin CETChannelMessageTwoInteger%3DC93935034A.preface preserve=yes
//## end CETChannelMessageTwoInteger%3DC93935034A.preface

//## Class: CETChannelMessageTwoInteger%3DC93935034A
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageTwoInteger : public CETChannelMessage  //## Inherits: <unnamed>%3DC9395200AA
{
  //## begin CETChannelMessageTwoInteger%3DC93935034A.initialDeclarations preserve=yes
  //## end CETChannelMessageTwoInteger%3DC93935034A.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageTwoInteger%1036597636
      CETChannelMessageTwoInteger (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageTwoInteger();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: iInt0%3DC939A50117
      int GetiInt0 ();

      //## Attribute: iInt1%3DC939A50127
      int GetiInt1 ();

    // Additional Public Declarations
      //## begin CETChannelMessageTwoInteger%3DC93935034A.public preserve=yes
      //## end CETChannelMessageTwoInteger%3DC93935034A.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessageTwoInteger%3DC93935034A.protected preserve=yes
      //## end CETChannelMessageTwoInteger%3DC93935034A.protected

  private:
    //## Constructors (generated)
      CETChannelMessageTwoInteger();

      CETChannelMessageTwoInteger(const CETChannelMessageTwoInteger &right);

    //## Assignment Operation (generated)
      const CETChannelMessageTwoInteger & operator=(const CETChannelMessageTwoInteger &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageTwoInteger &right) const;

      bool operator!=(const CETChannelMessageTwoInteger &right) const;

    // Data Members for Class Attributes

      //## begin CETChannelMessageTwoInteger::iInt0%3DC939A50117.attr preserve=no  public: int {U} 
      int m_iInt0;
      //## end CETChannelMessageTwoInteger::iInt0%3DC939A50117.attr

      //## begin CETChannelMessageTwoInteger::iInt1%3DC939A50127.attr preserve=no  public: int {U} 
      int m_iInt1;
      //## end CETChannelMessageTwoInteger::iInt1%3DC939A50127.attr

      //## Attribute: uiMessageSize%3DCA83850346
      //## begin CETChannelMessageTwoInteger::uiMessageSize%3DCA83850346.attr preserve=no  private: static UINT {U} m_uiBaseMessageSize+8
      static UINT m_uiMessageSize;
      //## end CETChannelMessageTwoInteger::uiMessageSize%3DCA83850346.attr

    // Additional Private Declarations
      //## begin CETChannelMessageTwoInteger%3DC93935034A.private preserve=yes
      //## end CETChannelMessageTwoInteger%3DC93935034A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageTwoInteger%3DC93935034A.implementation preserve=yes
      //## end CETChannelMessageTwoInteger%3DC93935034A.implementation

};

//## begin CETChannelMessageTwoInteger%3DC93935034A.postscript preserve=yes
//## end CETChannelMessageTwoInteger%3DC93935034A.postscript

//## begin CETChannelMessageStepperLimit%3DCA80DC00B6.preface preserve=yes
//## end CETChannelMessageStepperLimit%3DCA80DC00B6.preface

//## Class: CETChannelMessageStepperLimit%3DCA80DC00B6
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageStepperLimit : public CETChannelMessage  //## Inherits: <unnamed>%3DCA810102E8
{
  //## begin CETChannelMessageStepperLimit%3DCA80DC00B6.initialDeclarations preserve=yes
  //## end CETChannelMessageStepperLimit%3DCA80DC00B6.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageStepperLimit%1036680712
      CETChannelMessageStepperLimit (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageStepperLimit();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: uiSensorID%3DCA815601CF
      UINT GetuiSensorID ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DCA816C026B
      //## Role: CETChannelMessageStepperLimit::eLimitAction%3DCA816D00B7
      EPILimitAction GeteLimitAction ();

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DCA8726020E
      //## Role: CETChannelMessageStepperLimit::eLimitCharacteristics%3DCA872700D6
      EPILimitCharacteristics GeteLimitCharacteristics ();

    // Additional Public Declarations
      //## begin CETChannelMessageStepperLimit%3DCA80DC00B6.public preserve=yes
      //## end CETChannelMessageStepperLimit%3DCA80DC00B6.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessageStepperLimit%3DCA80DC00B6.protected preserve=yes
      //## end CETChannelMessageStepperLimit%3DCA80DC00B6.protected

  private:
    //## Constructors (generated)
      CETChannelMessageStepperLimit();

      CETChannelMessageStepperLimit(const CETChannelMessageStepperLimit &right);

    //## Assignment Operation (generated)
      const CETChannelMessageStepperLimit & operator=(const CETChannelMessageStepperLimit &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageStepperLimit &right) const;

      bool operator!=(const CETChannelMessageStepperLimit &right) const;

    // Data Members for Class Attributes

      //## begin CETChannelMessageStepperLimit::uiSensorID%3DCA815601CF.attr preserve=no  public: UINT {U} 
      UINT m_uiSensorID;
      //## end CETChannelMessageStepperLimit::uiSensorID%3DCA815601CF.attr

      //## Attribute: uiMessageSize%3DCA833B0394
      //## begin CETChannelMessageStepperLimit::uiMessageSize%3DCA833B0394.attr preserve=no  private: static UINT {U} m_uiBaseMessageSize+12
      static UINT m_uiMessageSize;
      //## end CETChannelMessageStepperLimit::uiMessageSize%3DCA833B0394.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DCA816C026B
      //## begin CETChannelMessageStepperLimit::eLimitAction%3DCA816D00B7.role preserve=no  public: EPILimitAction {1..1 -> 1..1VHN}
      EPILimitAction m_eLimitAction;
      //## end CETChannelMessageStepperLimit::eLimitAction%3DCA816D00B7.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DCA8726020E
      //## begin CETChannelMessageStepperLimit::eLimitCharacteristics%3DCA872700D6.role preserve=no  public: EPILimitCharacteristics {1..1 -> 1..1VHN}
      EPILimitCharacteristics m_eLimitCharacteristics;
      //## end CETChannelMessageStepperLimit::eLimitCharacteristics%3DCA872700D6.role

    // Additional Private Declarations
      //## begin CETChannelMessageStepperLimit%3DCA80DC00B6.private preserve=yes
      //## end CETChannelMessageStepperLimit%3DCA80DC00B6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageStepperLimit%3DCA80DC00B6.implementation preserve=yes
      //## end CETChannelMessageStepperLimit%3DCA80DC00B6.implementation

};

//## begin CETChannelMessageStepperLimit%3DCA80DC00B6.postscript preserve=yes
//## end CETChannelMessageStepperLimit%3DCA80DC00B6.postscript

//## begin CETChannelMessageStepperProfile%3DCA81A8021D.preface preserve=yes
//## end CETChannelMessageStepperProfile%3DCA81A8021D.preface

//## Class: CETChannelMessageStepperProfile%3DCA81A8021D
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageStepperProfile : public CETChannelMessage  //## Inherits: <unnamed>%3DCA81C30077
{
  //## begin CETChannelMessageStepperProfile%3DCA81A8021D.initialDeclarations preserve=yes
  //## end CETChannelMessageStepperProfile%3DCA81A8021D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageStepperProfile%1036680713
      CETChannelMessageStepperProfile (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageStepperProfile();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DCA81DD028B
      //## Role: CETChannelMessageStepperProfile::pProfile%3DCA81DE00A7
      CPIStepperMotorProfile * GetpProfile ();

    // Additional Public Declarations
      //## begin CETChannelMessageStepperProfile%3DCA81A8021D.public preserve=yes
      //## end CETChannelMessageStepperProfile%3DCA81A8021D.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessageStepperProfile%3DCA81A8021D.protected preserve=yes
      //## end CETChannelMessageStepperProfile%3DCA81A8021D.protected

  private:
    //## Constructors (generated)
      CETChannelMessageStepperProfile();

      CETChannelMessageStepperProfile(const CETChannelMessageStepperProfile &right);

    //## Assignment Operation (generated)
      const CETChannelMessageStepperProfile & operator=(const CETChannelMessageStepperProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageStepperProfile &right) const;

      bool operator!=(const CETChannelMessageStepperProfile &right) const;

    // Data Members for Class Attributes

      //## Attribute: uiMessageSize%3E95355A03B1
      //## begin CETChannelMessageStepperProfile::uiMessageSize%3E95355A03B1.attr preserve=no  public: static UINT {U} m_uiBaseMessageSize+5*sizeof(DWORD)
      static UINT m_uiMessageSize;
      //## end CETChannelMessageStepperProfile::uiMessageSize%3E95355A03B1.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DCA81DD028B
      //## begin CETChannelMessageStepperProfile::pProfile%3DCA81DE00A7.role preserve=no  public: CPIStepperMotorProfile {1..1 -> 1..1RFHN}
      CPIStepperMotorProfile *m_pProfile;
      //## end CETChannelMessageStepperProfile::pProfile%3DCA81DE00A7.role

    // Additional Private Declarations
      //## begin CETChannelMessageStepperProfile%3DCA81A8021D.private preserve=yes
      //## end CETChannelMessageStepperProfile%3DCA81A8021D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageStepperProfile%3DCA81A8021D.implementation preserve=yes
      //## end CETChannelMessageStepperProfile%3DCA81A8021D.implementation

};

//## begin CETChannelMessageStepperProfile%3DCA81A8021D.postscript preserve=yes
//## end CETChannelMessageStepperProfile%3DCA81A8021D.postscript

//## begin CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.preface preserve=yes
//## end CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.preface

//## Class: CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageStepperLimitFootPrint : public CETChannelMessage  //## Inherits: <unnamed>%3DCB5EC80066
{
  //## begin CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.initialDeclarations preserve=yes
  //## end CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageStepperLimitFootPrint%1036738399
      CETChannelMessageStepperLimitFootPrint (CETChannelMessage* p_pStdMessage);

    //## Destructor (generated)
      virtual ~CETChannelMessageStepperLimitFootPrint();


    //## Other Operations (specified)
      //## Operation: Serialize%1036738400
      virtual void Serialize (BYTE*& p_byStream, INT& p_iStreamLength);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DCB6F2E00F3
      //## Role: CETChannelMessageStepperLimitFootPrint::pFootPrint%3DCB6F2E0317
      CCOIntegerArray * GetpFootPrint ();
      void SetpFootPrint (CCOIntegerArray * value);

    // Additional Public Declarations
      //## begin CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.public preserve=yes
      //## end CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.protected preserve=yes
      //## end CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.protected

  private:
    //## Constructors (generated)
      CETChannelMessageStepperLimitFootPrint();

      CETChannelMessageStepperLimitFootPrint(const CETChannelMessageStepperLimitFootPrint &right);

    //## Assignment Operation (generated)
      const CETChannelMessageStepperLimitFootPrint & operator=(const CETChannelMessageStepperLimitFootPrint &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageStepperLimitFootPrint &right) const;

      bool operator!=(const CETChannelMessageStepperLimitFootPrint &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DCB6F2E00F3
      //## begin CETChannelMessageStepperLimitFootPrint::pFootPrint%3DCB6F2E0317.role preserve=no  public: CCOIntegerArray {1..1 -> 1..1RFHN}
      CCOIntegerArray *m_pFootPrint;
      //## end CETChannelMessageStepperLimitFootPrint::pFootPrint%3DCB6F2E0317.role

    // Additional Private Declarations
      //## begin CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.private preserve=yes
      //## end CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.implementation preserve=yes
      //## end CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.implementation

};

//## begin CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.postscript preserve=yes
//## end CETChannelMessageStepperLimitFootPrint%3DCB5EAC0326.postscript

//## begin CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.preface preserve=yes
//## end CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.preface

//## Class: CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageMeasurementChannelProfile : public CETChannelMessage  //## Inherits: <unnamed>%3DD1FE6D02C6
{
  //## begin CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.initialDeclarations preserve=yes
  //## end CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageMeasurementChannelProfile%1037172628
      CETChannelMessageMeasurementChannelProfile (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageMeasurementChannelProfile();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD1FEAE0064
      //## Role: CETChannelMessageMeasurementChannelProfile::pProfile%3DD1FEAE0269
      CPIMeasurementChannelProfile * GetpProfile ();

    // Additional Public Declarations
      //## begin CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.public preserve=yes
      //## end CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.public

  protected:
    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD1FF5300A3
      //## Role: CETChannelMessageMeasurementChannelProfile::uiMessageSize%3DD1FF530298
      //## begin CETChannelMessageMeasurementChannelProfile::uiMessageSize%3DD1FF530298.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
      static UINT m_uiMessageSize;
      //## end CETChannelMessageMeasurementChannelProfile::uiMessageSize%3DD1FF530298.role

    // Additional Protected Declarations
      //## begin CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.protected preserve=yes
      //## end CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.protected

  private:
    //## Constructors (generated)
      CETChannelMessageMeasurementChannelProfile();

      CETChannelMessageMeasurementChannelProfile(const CETChannelMessageMeasurementChannelProfile &right);

    //## Assignment Operation (generated)
      const CETChannelMessageMeasurementChannelProfile & operator=(const CETChannelMessageMeasurementChannelProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageMeasurementChannelProfile &right) const;

      bool operator!=(const CETChannelMessageMeasurementChannelProfile &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD1FEAE0064
      //## begin CETChannelMessageMeasurementChannelProfile::pProfile%3DD1FEAE0269.role preserve=no  public: CPIMeasurementChannelProfile {1..1 -> 1..1RFHN}
      CPIMeasurementChannelProfile *m_pProfile;
      //## end CETChannelMessageMeasurementChannelProfile::pProfile%3DD1FEAE0269.role

    // Additional Private Declarations
      //## begin CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.private preserve=yes
      //## end CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.implementation preserve=yes
      //## end CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.implementation

};

//## begin CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.postscript preserve=yes
//## end CETChannelMessageMeasurementChannelProfile%3DD1FE4B0100.postscript

//## begin CETChannelMessageWedgeProfile%3DD2064D01EB.preface preserve=yes
//## end CETChannelMessageWedgeProfile%3DD2064D01EB.preface

//## Class: CETChannelMessageWedgeProfile%3DD2064D01EB
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageWedgeProfile : public CETChannelMessage  //## Inherits: <unnamed>%3DD2068D014F
{
  //## begin CETChannelMessageWedgeProfile%3DD2064D01EB.initialDeclarations preserve=yes
  //## end CETChannelMessageWedgeProfile%3DD2064D01EB.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageWedgeProfile%1037172629
      CETChannelMessageWedgeProfile (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageWedgeProfile();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD206D80006
      //## Role: CETChannelMessageWedgeProfile::pProfile%3DD206D801AD
      CPIWedgeControlProfile * GetpProfile ();

    // Additional Public Declarations
      //## begin CETChannelMessageWedgeProfile%3DD2064D01EB.public preserve=yes
      //## end CETChannelMessageWedgeProfile%3DD2064D01EB.public

  protected:
    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD207130064
      //## Role: CETChannelMessageWedgeProfile::uiMessageSize%3DD20713021B
      //## begin CETChannelMessageWedgeProfile::uiMessageSize%3DD20713021B.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
      static UINT m_uiMessageSize;
      //## end CETChannelMessageWedgeProfile::uiMessageSize%3DD20713021B.role

    // Additional Protected Declarations
      //## begin CETChannelMessageWedgeProfile%3DD2064D01EB.protected preserve=yes
      //## end CETChannelMessageWedgeProfile%3DD2064D01EB.protected

  private:
    //## Constructors (generated)
      CETChannelMessageWedgeProfile();

      CETChannelMessageWedgeProfile(const CETChannelMessageWedgeProfile &right);

    //## Assignment Operation (generated)
      const CETChannelMessageWedgeProfile & operator=(const CETChannelMessageWedgeProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageWedgeProfile &right) const;

      bool operator!=(const CETChannelMessageWedgeProfile &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD206D80006
      //## begin CETChannelMessageWedgeProfile::pProfile%3DD206D801AD.role preserve=no  public: CPIWedgeControlProfile {1..1 -> 1..1RFHN}
      CPIWedgeControlProfile *m_pProfile;
      //## end CETChannelMessageWedgeProfile::pProfile%3DD206D801AD.role

    // Additional Private Declarations
      //## begin CETChannelMessageWedgeProfile%3DD2064D01EB.private preserve=yes
      //## end CETChannelMessageWedgeProfile%3DD2064D01EB.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageWedgeProfile%3DD2064D01EB.implementation preserve=yes
      //## end CETChannelMessageWedgeProfile%3DD2064D01EB.implementation

};

//## begin CETChannelMessageWedgeProfile%3DD2064D01EB.postscript preserve=yes
//## end CETChannelMessageWedgeProfile%3DD2064D01EB.postscript

//## begin CETChannelMessageWedgeConfig%3DD20666014F.preface preserve=yes
//## end CETChannelMessageWedgeConfig%3DD20666014F.preface

//## Class: CETChannelMessageWedgeConfig%3DD20666014F
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageWedgeConfig : public CETChannelMessage  //## Inherits: <unnamed>%3DD2068F0083
{
  //## begin CETChannelMessageWedgeConfig%3DD20666014F.initialDeclarations preserve=yes
  //## end CETChannelMessageWedgeConfig%3DD20666014F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageWedgeConfig%1037172630
      CETChannelMessageWedgeConfig (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageWedgeConfig();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD206DA014F
      //## Role: CETChannelMessageWedgeConfig::pConfig%3DD206DA0324
      CPIWedgeControlConfig * GetpConfig ();

    // Additional Public Declarations
      //## begin CETChannelMessageWedgeConfig%3DD20666014F.public preserve=yes
      //## end CETChannelMessageWedgeConfig%3DD20666014F.public

  protected:
    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD2074402B6
      //## Role: CETChannelMessageWedgeConfig::uiMessageSize%3DD207450121
      //## begin CETChannelMessageWedgeConfig::uiMessageSize%3DD207450121.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
      static UINT m_uiMessageSize;
      //## end CETChannelMessageWedgeConfig::uiMessageSize%3DD207450121.role

    // Additional Protected Declarations
      //## begin CETChannelMessageWedgeConfig%3DD20666014F.protected preserve=yes
      //## end CETChannelMessageWedgeConfig%3DD20666014F.protected

  private:
    //## Constructors (generated)
      CETChannelMessageWedgeConfig();

      CETChannelMessageWedgeConfig(const CETChannelMessageWedgeConfig &right);

    //## Assignment Operation (generated)
      const CETChannelMessageWedgeConfig & operator=(const CETChannelMessageWedgeConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageWedgeConfig &right) const;

      bool operator!=(const CETChannelMessageWedgeConfig &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD206DA014F
      //## begin CETChannelMessageWedgeConfig::pConfig%3DD206DA0324.role preserve=no  public: CPIWedgeControlConfig {1..1 -> 1..1RFHN}
      CPIWedgeControlConfig *m_pConfig;
      //## end CETChannelMessageWedgeConfig::pConfig%3DD206DA0324.role

    // Additional Private Declarations
      //## begin CETChannelMessageWedgeConfig%3DD20666014F.private preserve=yes
      //## end CETChannelMessageWedgeConfig%3DD20666014F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageWedgeConfig%3DD20666014F.implementation preserve=yes
      //## end CETChannelMessageWedgeConfig%3DD20666014F.implementation

};

//## begin CETChannelMessageWedgeConfig%3DD20666014F.postscript preserve=yes
//## end CETChannelMessageWedgeConfig%3DD20666014F.postscript

//## begin CETChannelMessageTemperatureProfile%3DD37AE200DD.preface preserve=yes
//## end CETChannelMessageTemperatureProfile%3DD37AE200DD.preface

//## Class: CETChannelMessageTemperatureProfile%3DD37AE200DD
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageTemperatureProfile : public CETChannelMessage  //## Inherits: <unnamed>%3DD37B21037D
{
  //## begin CETChannelMessageTemperatureProfile%3DD37AE200DD.initialDeclarations preserve=yes
  //## end CETChannelMessageTemperatureProfile%3DD37AE200DD.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageTemperatureProfile%1037257509
      CETChannelMessageTemperatureProfile (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageTemperatureProfile();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD39243011C
      //## Role: CETChannelMessageTemperatureProfile::pProfile%3DD3924303AD
      CPITemperatureControlProfile * GetpProfile ();

    // Additional Public Declarations
      //## begin CETChannelMessageTemperatureProfile%3DD37AE200DD.public preserve=yes
      //## end CETChannelMessageTemperatureProfile%3DD37AE200DD.public

  protected:
    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD3920701D7
      //## Role: CETChannelMessageTemperatureProfile::uiMessageSize%3DD392080033
      //## begin CETChannelMessageTemperatureProfile::uiMessageSize%3DD392080033.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
      static UINT m_uiMessageSize;
      //## end CETChannelMessageTemperatureProfile::uiMessageSize%3DD392080033.role

    // Additional Protected Declarations
      //## begin CETChannelMessageTemperatureProfile%3DD37AE200DD.protected preserve=yes
      //## end CETChannelMessageTemperatureProfile%3DD37AE200DD.protected

  private:
    //## Constructors (generated)
      CETChannelMessageTemperatureProfile();

      CETChannelMessageTemperatureProfile(const CETChannelMessageTemperatureProfile &right);

    //## Assignment Operation (generated)
      const CETChannelMessageTemperatureProfile & operator=(const CETChannelMessageTemperatureProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageTemperatureProfile &right) const;

      bool operator!=(const CETChannelMessageTemperatureProfile &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD39243011C
      //## begin CETChannelMessageTemperatureProfile::pProfile%3DD3924303AD.role preserve=no  public: CPITemperatureControlProfile {1..1 -> 1..1RFHN}
      CPITemperatureControlProfile *m_pProfile;
      //## end CETChannelMessageTemperatureProfile::pProfile%3DD3924303AD.role

    // Additional Private Declarations
      //## begin CETChannelMessageTemperatureProfile%3DD37AE200DD.private preserve=yes
      //## end CETChannelMessageTemperatureProfile%3DD37AE200DD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageTemperatureProfile%3DD37AE200DD.implementation preserve=yes
      //## end CETChannelMessageTemperatureProfile%3DD37AE200DD.implementation

};

//## begin CETChannelMessageTemperatureProfile%3DD37AE200DD.postscript preserve=yes
//## end CETChannelMessageTemperatureProfile%3DD37AE200DD.postscript

//## begin CETChannelMessageTemperatureConfig%3DD37AF7039D.preface preserve=yes
//## end CETChannelMessageTemperatureConfig%3DD37AF7039D.preface

//## Class: CETChannelMessageTemperatureConfig%3DD37AF7039D
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageTemperatureConfig : public CETChannelMessage  //## Inherits: <unnamed>%3DD37B23035E
{
  //## begin CETChannelMessageTemperatureConfig%3DD37AF7039D.initialDeclarations preserve=yes
  //## end CETChannelMessageTemperatureConfig%3DD37AF7039D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageTemperatureConfig%1037257510
      CETChannelMessageTemperatureConfig (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageTemperatureConfig();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD3925E0293
      //## Role: CETChannelMessageTemperatureConfig::pConfig%3DD3925F0061
      CPITemperatureControlConfig * GetpConfig ();

    // Additional Public Declarations
      //## begin CETChannelMessageTemperatureConfig%3DD37AF7039D.public preserve=yes
      //## end CETChannelMessageTemperatureConfig%3DD37AF7039D.public

  protected:
    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD3920A01B8
      //## Role: CETChannelMessageTemperatureConfig::uiMessageSize%3DD3920A035F
      //## begin CETChannelMessageTemperatureConfig::uiMessageSize%3DD3920A035F.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
      static UINT m_uiMessageSize;
      //## end CETChannelMessageTemperatureConfig::uiMessageSize%3DD3920A035F.role

    // Additional Protected Declarations
      //## begin CETChannelMessageTemperatureConfig%3DD37AF7039D.protected preserve=yes
      //## end CETChannelMessageTemperatureConfig%3DD37AF7039D.protected

  private:
    //## Constructors (generated)
      CETChannelMessageTemperatureConfig();

      CETChannelMessageTemperatureConfig(const CETChannelMessageTemperatureConfig &right);

    //## Assignment Operation (generated)
      const CETChannelMessageTemperatureConfig & operator=(const CETChannelMessageTemperatureConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageTemperatureConfig &right) const;

      bool operator!=(const CETChannelMessageTemperatureConfig &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD3925E0293
      //## begin CETChannelMessageTemperatureConfig::pConfig%3DD3925F0061.role preserve=no  public: CPITemperatureControlConfig {1..1 -> 1..1RFHN}
      CPITemperatureControlConfig *m_pConfig;
      //## end CETChannelMessageTemperatureConfig::pConfig%3DD3925F0061.role

    // Additional Private Declarations
      //## begin CETChannelMessageTemperatureConfig%3DD37AF7039D.private preserve=yes
      //## end CETChannelMessageTemperatureConfig%3DD37AF7039D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageTemperatureConfig%3DD37AF7039D.implementation preserve=yes
      //## end CETChannelMessageTemperatureConfig%3DD37AF7039D.implementation

};

//## begin CETChannelMessageTemperatureConfig%3DD37AF7039D.postscript preserve=yes
//## end CETChannelMessageTemperatureConfig%3DD37AF7039D.postscript

//## begin CETChannelMessagePowerProfile%3DD4110F0355.preface preserve=yes
//## end CETChannelMessagePowerProfile%3DD4110F0355.preface

//## Class: CETChannelMessagePowerProfile%3DD4110F0355
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessagePowerProfile : public CETChannelMessage  //## Inherits: <unnamed>%3DD411380169
{
  //## begin CETChannelMessagePowerProfile%3DD4110F0355.initialDeclarations preserve=yes
  //## end CETChannelMessagePowerProfile%3DD4110F0355.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessagePowerProfile%1037308032
      CETChannelMessagePowerProfile (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessagePowerProfile();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD411C70346
      //## Role: CETChannelMessagePowerProfile::pProfile%3DD411C801E0
      CPIPowerControlProfile * GetpProfile ();

    // Additional Public Declarations
      //## begin CETChannelMessagePowerProfile%3DD4110F0355.public preserve=yes
      //## end CETChannelMessagePowerProfile%3DD4110F0355.public

  protected:
    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD4117202D5
      //## Role: CETChannelMessagePowerProfile::uiMessageSize%3DD411730043
      //## begin CETChannelMessagePowerProfile::uiMessageSize%3DD411730043.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
      static UINT m_uiMessageSize;
      //## end CETChannelMessagePowerProfile::uiMessageSize%3DD411730043.role

    // Additional Protected Declarations
      //## begin CETChannelMessagePowerProfile%3DD4110F0355.protected preserve=yes
      //## end CETChannelMessagePowerProfile%3DD4110F0355.protected

  private:
    //## Constructors (generated)
      CETChannelMessagePowerProfile();

      CETChannelMessagePowerProfile(const CETChannelMessagePowerProfile &right);

    //## Assignment Operation (generated)
      const CETChannelMessagePowerProfile & operator=(const CETChannelMessagePowerProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessagePowerProfile &right) const;

      bool operator!=(const CETChannelMessagePowerProfile &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD411C70346
      //## begin CETChannelMessagePowerProfile::pProfile%3DD411C801E0.role preserve=no  public: CPIPowerControlProfile {1..1 -> 1..1RFHN}
      CPIPowerControlProfile *m_pProfile;
      //## end CETChannelMessagePowerProfile::pProfile%3DD411C801E0.role

    // Additional Private Declarations
      //## begin CETChannelMessagePowerProfile%3DD4110F0355.private preserve=yes
      //## end CETChannelMessagePowerProfile%3DD4110F0355.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessagePowerProfile%3DD4110F0355.implementation preserve=yes
      //## end CETChannelMessagePowerProfile%3DD4110F0355.implementation

};

//## begin CETChannelMessagePowerProfile%3DD4110F0355.postscript preserve=yes
//## end CETChannelMessagePowerProfile%3DD4110F0355.postscript

//## begin CETChannelMessagePowerConfig%3DD4111D01C5.preface preserve=yes
//## end CETChannelMessagePowerConfig%3DD4111D01C5.preface

//## Class: CETChannelMessagePowerConfig%3DD4111D01C5
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessagePowerConfig : public CETChannelMessage  //## Inherits: <unnamed>%3DD4113A0220
{
  //## begin CETChannelMessagePowerConfig%3DD4111D01C5.initialDeclarations preserve=yes
  //## end CETChannelMessagePowerConfig%3DD4111D01C5.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessagePowerConfig%1037308031
      CETChannelMessagePowerConfig (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessagePowerConfig();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD411E40329
      //## Role: CETChannelMessagePowerConfig::pConfig%3DD411E5012D
      CPIPowerControlConfig * GetpConfig ();

    // Additional Public Declarations
      //## begin CETChannelMessagePowerConfig%3DD4111D01C5.public preserve=yes
      //## end CETChannelMessagePowerConfig%3DD4111D01C5.public

  protected:
    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD4119E00BC
      //## Role: CETChannelMessagePowerConfig::uiMessageSize%3DD4119E030B
      //## begin CETChannelMessagePowerConfig::uiMessageSize%3DD4119E030B.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
      static UINT m_uiMessageSize;
      //## end CETChannelMessagePowerConfig::uiMessageSize%3DD4119E030B.role

    // Additional Protected Declarations
      //## begin CETChannelMessagePowerConfig%3DD4111D01C5.protected preserve=yes
      //## end CETChannelMessagePowerConfig%3DD4111D01C5.protected

  private:
    //## Constructors (generated)
      CETChannelMessagePowerConfig();

      CETChannelMessagePowerConfig(const CETChannelMessagePowerConfig &right);

    //## Assignment Operation (generated)
      const CETChannelMessagePowerConfig & operator=(const CETChannelMessagePowerConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessagePowerConfig &right) const;

      bool operator!=(const CETChannelMessagePowerConfig &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD411E40329
      //## begin CETChannelMessagePowerConfig::pConfig%3DD411E5012D.role preserve=no  public: CPIPowerControlConfig {1..1 -> 1..1RFHN}
      CPIPowerControlConfig *m_pConfig;
      //## end CETChannelMessagePowerConfig::pConfig%3DD411E5012D.role

    // Additional Private Declarations
      //## begin CETChannelMessagePowerConfig%3DD4111D01C5.private preserve=yes
      //## end CETChannelMessagePowerConfig%3DD4111D01C5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessagePowerConfig%3DD4111D01C5.implementation preserve=yes
      //## end CETChannelMessagePowerConfig%3DD4111D01C5.implementation

};

//## begin CETChannelMessagePowerConfig%3DD4111D01C5.postscript preserve=yes
//## end CETChannelMessagePowerConfig%3DD4111D01C5.postscript

//## begin CETChannelMessagePersistentIdentification%3DD4F0160019.preface preserve=yes
//## end CETChannelMessagePersistentIdentification%3DD4F0160019.preface

//## Class: CETChannelMessagePersistentIdentification%3DD4F0160019
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessagePersistentIdentification : public CETChannelMessage  //## Inherits: <unnamed>%3DD4F0760058
{
  //## begin CETChannelMessagePersistentIdentification%3DD4F0160019.initialDeclarations preserve=yes
  //## end CETChannelMessagePersistentIdentification%3DD4F0160019.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessagePersistentIdentification%1037346580
      CETChannelMessagePersistentIdentification (BYTE* p_byStream, INT p_iStreamLength);

      //## Operation: CETChannelMessagePersistentIdentification%1074584186
      CETChannelMessagePersistentIdentification (CETChannelMessage*  p_pStdMessage);

    //## Destructor (generated)
      virtual ~CETChannelMessagePersistentIdentification();


    //## Other Operations (specified)
      //## Operation: Serialize%1037632254
      virtual void Serialize (BYTE*& p_byStream, INT& p_iStreamLength);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%400CE11E034F
      //## Role: CETChannelMessagePersistentIdentification::pPersistentIdentification%400CE11F02A4
      CPIPersistentItemList * GetpPersistentIdentification ();
      void SetpPersistentIdentification (CPIPersistentItemList * value);

    // Additional Public Declarations
      //## begin CETChannelMessagePersistentIdentification%3DD4F0160019.public preserve=yes
      //## end CETChannelMessagePersistentIdentification%3DD4F0160019.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessagePersistentIdentification%3DD4F0160019.protected preserve=yes
      //## end CETChannelMessagePersistentIdentification%3DD4F0160019.protected

  private:
    //## Constructors (generated)
      CETChannelMessagePersistentIdentification();

      CETChannelMessagePersistentIdentification(const CETChannelMessagePersistentIdentification &right);

    //## Assignment Operation (generated)
      const CETChannelMessagePersistentIdentification & operator=(const CETChannelMessagePersistentIdentification &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessagePersistentIdentification &right) const;

      bool operator!=(const CETChannelMessagePersistentIdentification &right) const;


    //## Other Operations (specified)
      //## Operation: BuildIdentificationStream%1074522947
      //	Build stream of all identification objects and set the
      //	telegram size
      void BuildIdentificationStream ();

    // Data Members for Class Attributes

      //## Attribute: sIdentifcationStream%400D2BE30154
      //	Contains one stream of identifications objects
      //## begin CETChannelMessagePersistentIdentification::sIdentifcationStream%400D2BE30154.attr preserve=no  private: CString {U} 
      CString m_sIdentifcationStream;
      //## end CETChannelMessagePersistentIdentification::sIdentifcationStream%400D2BE30154.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%400CE11E034F
      //## begin CETChannelMessagePersistentIdentification::pPersistentIdentification%400CE11F02A4.role preserve=no  public: CPIPersistentItemList {1..1 -> 1..1RFHN}
      CPIPersistentItemList *m_pPersistentIdentification;
      //## end CETChannelMessagePersistentIdentification::pPersistentIdentification%400CE11F02A4.role

    // Additional Private Declarations
      //## begin CETChannelMessagePersistentIdentification%3DD4F0160019.private preserve=yes
      //## end CETChannelMessagePersistentIdentification%3DD4F0160019.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessagePersistentIdentification%3DD4F0160019.implementation preserve=yes
      //## end CETChannelMessagePersistentIdentification%3DD4F0160019.implementation

};

//## begin CETChannelMessagePersistentIdentification%3DD4F0160019.postscript preserve=yes
//## end CETChannelMessagePersistentIdentification%3DD4F0160019.postscript

//## begin CETChannelMessagePersistentParameter%3DD4F0230190.preface preserve=yes
//## end CETChannelMessagePersistentParameter%3DD4F0230190.preface

//## Class: CETChannelMessagePersistentParameter%3DD4F0230190
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessagePersistentParameter : public CETChannelMessage  //## Inherits: <unnamed>%3DD4F0770336
{
  //## begin CETChannelMessagePersistentParameter%3DD4F0230190.initialDeclarations preserve=yes
  //## end CETChannelMessagePersistentParameter%3DD4F0230190.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessagePersistentParameter%1037346581
      CETChannelMessagePersistentParameter (BYTE* p_byStream, INT p_iStreamLength);

      //## Operation: CETChannelMessagePersistentParameter%1074687336
      CETChannelMessagePersistentParameter (CETChannelMessage*  p_pStdMessage);

    //## Destructor (generated)
      virtual ~CETChannelMessagePersistentParameter();


    //## Other Operations (specified)
      //## Operation: Serialize%1037632256
      virtual void Serialize (BYTE*& p_byStream, INT& p_iStreamLength);

      //## Operation: BuildParameterStream%1074687337
      //	Build stream of all parameters objects and set the
      //	telegram size
      void BuildParameterStream ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%400E75B002C3
      //## Role: CETChannelMessagePersistentParameter::pPersistentParameter%400E75B10237
      CPIPersistentItemList * GetpPersistentParameter ();
      void SetpPersistentParameter (CPIPersistentItemList * value);

    // Additional Public Declarations
      //## begin CETChannelMessagePersistentParameter%3DD4F0230190.public preserve=yes
      //## end CETChannelMessagePersistentParameter%3DD4F0230190.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessagePersistentParameter%3DD4F0230190.protected preserve=yes
      //## end CETChannelMessagePersistentParameter%3DD4F0230190.protected

  private:
    //## Constructors (generated)
      CETChannelMessagePersistentParameter();

      CETChannelMessagePersistentParameter(const CETChannelMessagePersistentParameter &right);

    //## Assignment Operation (generated)
      const CETChannelMessagePersistentParameter & operator=(const CETChannelMessagePersistentParameter &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessagePersistentParameter &right) const;

      bool operator!=(const CETChannelMessagePersistentParameter &right) const;

    // Data Members for Class Attributes

      //## Attribute: sParameterStream%400E706E00FE
      //	Contains one stream of parameter objects
      //## begin CETChannelMessagePersistentParameter::sParameterStream%400E706E00FE.attr preserve=no  private: CString {U} 
      CString m_sParameterStream;
      //## end CETChannelMessagePersistentParameter::sParameterStream%400E706E00FE.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%400E75B002C3
      //## begin CETChannelMessagePersistentParameter::pPersistentParameter%400E75B10237.role preserve=no  public: CPIPersistentItemList {1..1 -> 1..1RFHN}
      CPIPersistentItemList *m_pPersistentParameter;
      //## end CETChannelMessagePersistentParameter::pPersistentParameter%400E75B10237.role

    // Additional Private Declarations
      //## begin CETChannelMessagePersistentParameter%3DD4F0230190.private preserve=yes
      //## end CETChannelMessagePersistentParameter%3DD4F0230190.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessagePersistentParameter%3DD4F0230190.implementation preserve=yes
      //## end CETChannelMessagePersistentParameter%3DD4F0230190.implementation

};

//## begin CETChannelMessagePersistentParameter%3DD4F0230190.postscript preserve=yes
//## end CETChannelMessagePersistentParameter%3DD4F0230190.postscript

//## begin CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.preface preserve=yes
//## end CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.preface

//## Class: CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessagePersistentSoftwareComponent : public CETChannelMessage  //## Inherits: <unnamed>%3DD4F0790307
{
  //## begin CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.initialDeclarations preserve=yes
  //## end CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessagePersistentSoftwareComponent%1037346582
      CETChannelMessagePersistentSoftwareComponent (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessagePersistentSoftwareComponent();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD4F1B901EE
      //## Role: CETChannelMessagePersistentSoftwareComponent::pComponents%3DD4F1BA0068
      CPIPersistentSoftwareComponentList * GetpComponents ();

    // Additional Public Declarations
      //## begin CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.public preserve=yes
      //## end CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.protected preserve=yes
      //## end CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.protected

  private:
    //## Constructors (generated)
      CETChannelMessagePersistentSoftwareComponent();

      CETChannelMessagePersistentSoftwareComponent(const CETChannelMessagePersistentSoftwareComponent &right);

    //## Assignment Operation (generated)
      const CETChannelMessagePersistentSoftwareComponent & operator=(const CETChannelMessagePersistentSoftwareComponent &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessagePersistentSoftwareComponent &right) const;

      bool operator!=(const CETChannelMessagePersistentSoftwareComponent &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD4F1B901EE
      //## begin CETChannelMessagePersistentSoftwareComponent::pComponents%3DD4F1BA0068.role preserve=no  public: CPIPersistentSoftwareComponentList {1..1 -> 1..1RFHN}
      CPIPersistentSoftwareComponentList *m_pComponents;
      //## end CETChannelMessagePersistentSoftwareComponent::pComponents%3DD4F1BA0068.role

    // Additional Private Declarations
      //## begin CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.private preserve=yes
      //## end CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.implementation preserve=yes
      //## end CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.implementation

};

//## begin CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.postscript preserve=yes
//## end CETChannelMessagePersistentSoftwareComponent%3DD4F03703A4.postscript

//## begin CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.preface preserve=yes
//## end CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.preface

//## Class: CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessagePersistentSoftwareComponentVersion : public CETChannelMessage  //## Inherits: <unnamed>%3DD4F07C00A6
{
  //## begin CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.initialDeclarations preserve=yes
  //## end CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessagePersistentSoftwareComponentVersion%1037346583
      CETChannelMessagePersistentSoftwareComponentVersion (BYTE* p_byStream, INT p_iStreamLength);

      //## Operation: CETChannelMessagePersistentSoftwareComponentVersion%1037632257
      CETChannelMessagePersistentSoftwareComponentVersion (CETChannelMessage* p_pStdMessage);

    //## Destructor (generated)
      virtual ~CETChannelMessagePersistentSoftwareComponentVersion();


    //## Other Operations (specified)
      //## Operation: Serialize%1037632258
      virtual void Serialize (BYTE*& p_byStream, INT& p_iStreamLength);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD4F1D800A6
      //## Role: CETChannelMessagePersistentSoftwareComponentVersion::ComponentVersions%3DD4F1D80318
      CTypedPtrList<CPtrList, CPIPersistentSoftwareComponentVersion*>& GetComponentVersions ();
      void SetComponentVersions (const CTypedPtrList<CPtrList, CPIPersistentSoftwareComponentVersion*>& value);

    // Additional Public Declarations
      //## begin CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.public preserve=yes
      //## end CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.protected preserve=yes
      //## end CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.protected

  private:
    //## Constructors (generated)
      CETChannelMessagePersistentSoftwareComponentVersion();

      CETChannelMessagePersistentSoftwareComponentVersion(const CETChannelMessagePersistentSoftwareComponentVersion &right);

    //## Assignment Operation (generated)
      const CETChannelMessagePersistentSoftwareComponentVersion & operator=(const CETChannelMessagePersistentSoftwareComponentVersion &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessagePersistentSoftwareComponentVersion &right) const;

      bool operator!=(const CETChannelMessagePersistentSoftwareComponentVersion &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD4F1D800A6
      //## begin CETChannelMessagePersistentSoftwareComponentVersion::ComponentVersions%3DD4F1D80318.role preserve=no  public: CPIPersistentSoftwareComponentVersion {0 -> nRFHN}
      CTypedPtrList<CPtrList, CPIPersistentSoftwareComponentVersion*> m_ComponentVersions;
      //## end CETChannelMessagePersistentSoftwareComponentVersion::ComponentVersions%3DD4F1D80318.role

    // Additional Private Declarations
      //## begin CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.private preserve=yes
      //## end CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.implementation preserve=yes
      //## end CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.implementation

};

//## begin CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.postscript preserve=yes
//## end CETChannelMessagePersistentSoftwareComponentVersion%3DD4F05A0113.postscript

//## begin CETChannelMessageStepperConfig%3E9533CE0111.preface preserve=yes
//## end CETChannelMessageStepperConfig%3E9533CE0111.preface

//## Class: CETChannelMessageStepperConfig%3E9533CE0111
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageStepperConfig : public CETChannelMessage  //## Inherits: <unnamed>%3E95342B01AE
{
  //## begin CETChannelMessageStepperConfig%3E9533CE0111.initialDeclarations preserve=yes
  //## end CETChannelMessageStepperConfig%3E9533CE0111.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageStepperConfig%1049965451
      CETChannelMessageStepperConfig (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageStepperConfig();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3E9533F00085
      //## Role: CETChannelMessageStepperConfig::pConfig%3E9533F002B8
      CPIStepperMotorConfig * GetpConfig ();

    // Additional Public Declarations
      //## begin CETChannelMessageStepperConfig%3E9533CE0111.public preserve=yes
      //## end CETChannelMessageStepperConfig%3E9533CE0111.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessageStepperConfig%3E9533CE0111.protected preserve=yes
      //## end CETChannelMessageStepperConfig%3E9533CE0111.protected

  private:
    //## Constructors (generated)
      CETChannelMessageStepperConfig();

      CETChannelMessageStepperConfig(const CETChannelMessageStepperConfig &right);

    //## Assignment Operation (generated)
      const CETChannelMessageStepperConfig & operator=(const CETChannelMessageStepperConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageStepperConfig &right) const;

      bool operator!=(const CETChannelMessageStepperConfig &right) const;

    // Data Members for Class Attributes

      //## Attribute: uiMessageSize%3E9535CD0363
      //## begin CETChannelMessageStepperConfig::uiMessageSize%3E9535CD0363.attr preserve=no  public: static UINT {U} m_uiBaseMessageSize+12*sizeof(DWORD)
      static UINT m_uiMessageSize;
      //## end CETChannelMessageStepperConfig::uiMessageSize%3E9535CD0363.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3E9533F00085
      //## begin CETChannelMessageStepperConfig::pConfig%3E9533F002B8.role preserve=no  public: CPIStepperMotorConfig {1..1 -> 1..1RFHN}
      CPIStepperMotorConfig *m_pConfig;
      //## end CETChannelMessageStepperConfig::pConfig%3E9533F002B8.role

    // Additional Private Declarations
      //## begin CETChannelMessageStepperConfig%3E9533CE0111.private preserve=yes
      //## end CETChannelMessageStepperConfig%3E9533CE0111.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageStepperConfig%3E9533CE0111.implementation preserve=yes
      //## end CETChannelMessageStepperConfig%3E9533CE0111.implementation

};

//## begin CETChannelMessageStepperConfig%3E9533CE0111.postscript preserve=yes
//## end CETChannelMessageStepperConfig%3E9533CE0111.postscript

//## begin CETChannelMessageSystemInterfaceConfig%3EE5D0440040.preface preserve=yes
//## end CETChannelMessageSystemInterfaceConfig%3EE5D0440040.preface

//## Class: CETChannelMessageSystemInterfaceConfig%3EE5D0440040
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageSystemInterfaceConfig : public CETChannelMessage  //## Inherits: <unnamed>%3EE5D066007F
{
  //## begin CETChannelMessageSystemInterfaceConfig%3EE5D0440040.initialDeclarations preserve=yes
  //## end CETChannelMessageSystemInterfaceConfig%3EE5D0440040.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageSystemInterfaceConfig%1055243209
      CETChannelMessageSystemInterfaceConfig (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageSystemInterfaceConfig();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3EE5D0860040
      //## Role: CETChannelMessageSystemInterfaceConfig::pConfig%3EE5D0860274
      CPIInterfaceConfig * GetpConfig ();

    // Additional Public Declarations
      //## begin CETChannelMessageSystemInterfaceConfig%3EE5D0440040.public preserve=yes
      //## end CETChannelMessageSystemInterfaceConfig%3EE5D0440040.public

  protected:
    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3EE5D0A5007F
      //## Role: CETChannelMessageSystemInterfaceConfig::uiMessageSize%3EE5D0A501E6
      //## begin CETChannelMessageSystemInterfaceConfig::uiMessageSize%3EE5D0A501E6.role preserve=no  public: static UINT { -> VFHN}
      static UINT m_uiMessageSize;
      //## end CETChannelMessageSystemInterfaceConfig::uiMessageSize%3EE5D0A501E6.role

    // Additional Protected Declarations
      //## begin CETChannelMessageSystemInterfaceConfig%3EE5D0440040.protected preserve=yes
      //## end CETChannelMessageSystemInterfaceConfig%3EE5D0440040.protected

  private:
    //## Constructors (generated)
      CETChannelMessageSystemInterfaceConfig();

      CETChannelMessageSystemInterfaceConfig(const CETChannelMessageSystemInterfaceConfig &right);

    //## Assignment Operation (generated)
      const CETChannelMessageSystemInterfaceConfig & operator=(const CETChannelMessageSystemInterfaceConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageSystemInterfaceConfig &right) const;

      bool operator!=(const CETChannelMessageSystemInterfaceConfig &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3EE5D0860040
      //## begin CETChannelMessageSystemInterfaceConfig::pConfig%3EE5D0860274.role preserve=no  public: CPIInterfaceConfig {1..1 -> 1..1RFHN}
      CPIInterfaceConfig *m_pConfig;
      //## end CETChannelMessageSystemInterfaceConfig::pConfig%3EE5D0860274.role

    // Additional Private Declarations
      //## begin CETChannelMessageSystemInterfaceConfig%3EE5D0440040.private preserve=yes
      //## end CETChannelMessageSystemInterfaceConfig%3EE5D0440040.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageSystemInterfaceConfig%3EE5D0440040.implementation preserve=yes
      //## end CETChannelMessageSystemInterfaceConfig%3EE5D0440040.implementation

};

//## begin CETChannelMessageSystemInterfaceConfig%3EE5D0440040.postscript preserve=yes
//## end CETChannelMessageSystemInterfaceConfig%3EE5D0440040.postscript

//## begin CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.preface preserve=yes
//## end CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.preface

//## Class: CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageI2CTempDS1631ZConfig : public CETChannelMessage  //## Inherits: <unnamed>%3EE5EDAA010B
{
  //## begin CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.initialDeclarations preserve=yes
  //## end CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageI2CTempDS1631ZConfig%1055243216
      CETChannelMessageI2CTempDS1631ZConfig (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageI2CTempDS1631ZConfig();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3EE5EDB6011B
      //## Role: CETChannelMessageI2CTempDS1631ZConfig::pConfig%3EE5EDB6033F
      CPIConfigDS1631Z * GetpConfig ();

    // Additional Public Declarations
      //## begin CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.public preserve=yes
      //## end CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.public

  protected:
    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3EE5EDAC0179
      //## Role: CETChannelMessageI2CTempDS1631ZConfig::uiMessageSize%3EE5EDAC03BC
      //## begin CETChannelMessageI2CTempDS1631ZConfig::uiMessageSize%3EE5EDAC03BC.role preserve=no  public: static UINT { -> VFHN}
      static UINT m_uiMessageSize;
      //## end CETChannelMessageI2CTempDS1631ZConfig::uiMessageSize%3EE5EDAC03BC.role

    // Additional Protected Declarations
      //## begin CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.protected preserve=yes
      //## end CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.protected

  private:
    //## Constructors (generated)
      CETChannelMessageI2CTempDS1631ZConfig();

      CETChannelMessageI2CTempDS1631ZConfig(const CETChannelMessageI2CTempDS1631ZConfig &right);

    //## Assignment Operation (generated)
      const CETChannelMessageI2CTempDS1631ZConfig & operator=(const CETChannelMessageI2CTempDS1631ZConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageI2CTempDS1631ZConfig &right) const;

      bool operator!=(const CETChannelMessageI2CTempDS1631ZConfig &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3EE5EDB6011B
      //## begin CETChannelMessageI2CTempDS1631ZConfig::pConfig%3EE5EDB6033F.role preserve=no  public: CPIConfigDS1631Z {1..1 -> 1..1RFHN}
      CPIConfigDS1631Z *m_pConfig;
      //## end CETChannelMessageI2CTempDS1631ZConfig::pConfig%3EE5EDB6033F.role

    // Additional Private Declarations
      //## begin CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.private preserve=yes
      //## end CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.implementation preserve=yes
      //## end CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.implementation

};

//## begin CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.postscript preserve=yes
//## end CETChannelMessageI2CTempDS1631ZConfig%3EE5ED56009E.postscript

//## begin CETChannelMessageSystemComponentState%3F4627E90315.preface preserve=yes
//## end CETChannelMessageSystemComponentState%3F4627E90315.preface

//## Class: CETChannelMessageSystemComponentState%3F4627E90315
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageSystemComponentState : public CETChannelMessage  //## Inherits: <unnamed>%3F46281F0306
{
  //## begin CETChannelMessageSystemComponentState%3F4627E90315.initialDeclarations preserve=yes
  //## end CETChannelMessageSystemComponentState%3F4627E90315.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageSystemComponentState%1061562116
      CETChannelMessageSystemComponentState (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageSystemComponentState();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: sCpoName%3F46287703C1
      WCHAR* GetsCpoName ();

      //## Attribute: bState%3F4628920392
      bool GetbState ();

    // Additional Public Declarations
      //## begin CETChannelMessageSystemComponentState%3F4627E90315.public preserve=yes
      //## end CETChannelMessageSystemComponentState%3F4627E90315.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessageSystemComponentState%3F4627E90315.protected preserve=yes
      //## end CETChannelMessageSystemComponentState%3F4627E90315.protected

  private:
    //## Constructors (generated)
      CETChannelMessageSystemComponentState();

      CETChannelMessageSystemComponentState(const CETChannelMessageSystemComponentState &right);

    //## Assignment Operation (generated)
      const CETChannelMessageSystemComponentState & operator=(const CETChannelMessageSystemComponentState &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageSystemComponentState &right) const;

      bool operator!=(const CETChannelMessageSystemComponentState &right) const;

    // Data Members for Class Attributes

      //## begin CETChannelMessageSystemComponentState::sCpoName%3F46287703C1.attr preserve=no  public: WCHAR[32] {U} 
      WCHAR m_sCpoName[32];
      //## end CETChannelMessageSystemComponentState::sCpoName%3F46287703C1.attr

      //## begin CETChannelMessageSystemComponentState::bState%3F4628920392.attr preserve=no  public: bool {U} 
      bool m_bState;
      //## end CETChannelMessageSystemComponentState::bState%3F4628920392.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F46282201CD
      //## Role: CETChannelMessageSystemComponentState::uiMessageSize%3F4628230067
      //## begin CETChannelMessageSystemComponentState::uiMessageSize%3F4628230067.role preserve=no  public: static UINT { -> VFHN}
      static UINT m_uiMessageSize;
      //## end CETChannelMessageSystemComponentState::uiMessageSize%3F4628230067.role

    // Additional Private Declarations
      //## begin CETChannelMessageSystemComponentState%3F4627E90315.private preserve=yes
      //## end CETChannelMessageSystemComponentState%3F4627E90315.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageSystemComponentState%3F4627E90315.implementation preserve=yes
      //## end CETChannelMessageSystemComponentState%3F4627E90315.implementation

};

//## begin CETChannelMessageSystemComponentState%3F4627E90315.postscript preserve=yes
//## end CETChannelMessageSystemComponentState%3F4627E90315.postscript

//## begin CETChannelMessageSystemGetObjectList%3F6726EE0106.preface preserve=yes
//## end CETChannelMessageSystemGetObjectList%3F6726EE0106.preface

//## Class: CETChannelMessageSystemGetObjectList%3F6726EE0106
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageSystemGetObjectList : public CETChannelMessage  //## Inherits: <unnamed>%3F67273201F0
{
  //## begin CETChannelMessageSystemGetObjectList%3F6726EE0106.initialDeclarations preserve=yes
  //## end CETChannelMessageSystemGetObjectList%3F6726EE0106.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageSystemGetObjectList%1063715462
      CETChannelMessageSystemGetObjectList (BYTE* p_byStream, INT p_iStreamLength);

      //## Operation: CETChannelMessageSystemGetObjectList%1063715467
      CETChannelMessageSystemGetObjectList (const CETChannelMessage& p_Right);

    //## Destructor (generated)
      virtual ~CETChannelMessageSystemGetObjectList();


    //## Other Operations (specified)
      //## Operation: Serialize%1063715463
      virtual void Serialize (BYTE*& p_byStream, INT& p_iStreamLength);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F6727440089
      //## Role: CETChannelMessageSystemGetObjectList::pObjList%3F672744025F
      void SetpObjList (CStringArray * value);

    // Additional Public Declarations
      //## begin CETChannelMessageSystemGetObjectList%3F6726EE0106.public preserve=yes
      //## end CETChannelMessageSystemGetObjectList%3F6726EE0106.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessageSystemGetObjectList%3F6726EE0106.protected preserve=yes
      //## end CETChannelMessageSystemGetObjectList%3F6726EE0106.protected

  private:
    //## Constructors (generated)
      CETChannelMessageSystemGetObjectList();

      CETChannelMessageSystemGetObjectList(const CETChannelMessageSystemGetObjectList &right);

    //## Assignment Operation (generated)
      const CETChannelMessageSystemGetObjectList & operator=(const CETChannelMessageSystemGetObjectList &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageSystemGetObjectList &right) const;

      bool operator!=(const CETChannelMessageSystemGetObjectList &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F6727440089
      //## begin CETChannelMessageSystemGetObjectList::pObjList%3F672744025F.role preserve=no  public: CStringArray {1..1 -> 1..1RFHN}
      CStringArray *m_pObjList;
      //## end CETChannelMessageSystemGetObjectList::pObjList%3F672744025F.role

    // Additional Private Declarations
      //## begin CETChannelMessageSystemGetObjectList%3F6726EE0106.private preserve=yes
      //## end CETChannelMessageSystemGetObjectList%3F6726EE0106.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageSystemGetObjectList%3F6726EE0106.implementation preserve=yes
      //## end CETChannelMessageSystemGetObjectList%3F6726EE0106.implementation

};

//## begin CETChannelMessageSystemGetObjectList%3F6726EE0106.postscript preserve=yes
//## end CETChannelMessageSystemGetObjectList%3F6726EE0106.postscript

//## begin CETChannelMessageSystemSetTime%3F71E6DD030E.preface preserve=yes
//## end CETChannelMessageSystemSetTime%3F71E6DD030E.preface

//## Class: CETChannelMessageSystemSetTime%3F71E6DD030E
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageSystemSetTime : public CETChannelMessage  //## Inherits: <unnamed>%3F71E6F900BF
{
  //## begin CETChannelMessageSystemSetTime%3F71E6DD030E.initialDeclarations preserve=yes
  //## end CETChannelMessageSystemSetTime%3F71E6DD030E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageSystemSetTime%1064429412
      CETChannelMessageSystemSetTime (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageSystemSetTime();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F71E7460048
      //## Role: CETChannelMessageSystemSetTime::SystemTime%3F71E746028E
      SYSTEMTIME GetSystemTime ();

    // Additional Public Declarations
      //## begin CETChannelMessageSystemSetTime%3F71E6DD030E.public preserve=yes
      //## end CETChannelMessageSystemSetTime%3F71E6DD030E.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessageSystemSetTime%3F71E6DD030E.protected preserve=yes
      //## end CETChannelMessageSystemSetTime%3F71E6DD030E.protected

  private:
    //## Constructors (generated)
      CETChannelMessageSystemSetTime();

      CETChannelMessageSystemSetTime(const CETChannelMessageSystemSetTime &right);

    //## Assignment Operation (generated)
      const CETChannelMessageSystemSetTime & operator=(const CETChannelMessageSystemSetTime &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageSystemSetTime &right) const;

      bool operator!=(const CETChannelMessageSystemSetTime &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F71E7460048
      //## begin CETChannelMessageSystemSetTime::SystemTime%3F71E746028E.role preserve=no  public: SYSTEMTIME {1..1 -> 1..1VFHN}
      SYSTEMTIME m_SystemTime;
      //## end CETChannelMessageSystemSetTime::SystemTime%3F71E746028E.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F71E836009D
      //## Role: CETChannelMessageSystemSetTime::uiMessageSize%3F71E8370261
      //## begin CETChannelMessageSystemSetTime::uiMessageSize%3F71E8370261.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
      static UINT m_uiMessageSize;
      //## end CETChannelMessageSystemSetTime::uiMessageSize%3F71E8370261.role

    // Additional Private Declarations
      //## begin CETChannelMessageSystemSetTime%3F71E6DD030E.private preserve=yes
      //## end CETChannelMessageSystemSetTime%3F71E6DD030E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageSystemSetTime%3F71E6DD030E.implementation preserve=yes
      //## end CETChannelMessageSystemSetTime%3F71E6DD030E.implementation

};

//## begin CETChannelMessageSystemSetTime%3F71E6DD030E.postscript preserve=yes
//## end CETChannelMessageSystemSetTime%3F71E6DD030E.postscript

//## begin CETChannelMessagePersistentConfig%40054737017B.preface preserve=yes
//## end CETChannelMessagePersistentConfig%40054737017B.preface

//## Class: CETChannelMessagePersistentConfig%40054737017B
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessagePersistentConfig : public CETChannelMessage  //## Inherits: <unnamed>%4005474201F8
{
  //## begin CETChannelMessagePersistentConfig%40054737017B.initialDeclarations preserve=yes
  //## end CETChannelMessagePersistentConfig%40054737017B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessagePersistentConfig%1074090279
      CETChannelMessagePersistentConfig (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessagePersistentConfig();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%40054A150061
      //## Role: CETChannelMessagePersistentConfig::pConfig%40054A150370
      CPIPersistentConfig * GetpConfig ();

    // Additional Public Declarations
      //## begin CETChannelMessagePersistentConfig%40054737017B.public preserve=yes
      //## end CETChannelMessagePersistentConfig%40054737017B.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessagePersistentConfig%40054737017B.protected preserve=yes
      //## end CETChannelMessagePersistentConfig%40054737017B.protected

  private:
    //## Constructors (generated)
      CETChannelMessagePersistentConfig();

      CETChannelMessagePersistentConfig(const CETChannelMessagePersistentConfig &right);

    //## Assignment Operation (generated)
      const CETChannelMessagePersistentConfig & operator=(const CETChannelMessagePersistentConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessagePersistentConfig &right) const;

      bool operator!=(const CETChannelMessagePersistentConfig &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%40054A150061
      //## begin CETChannelMessagePersistentConfig::pConfig%40054A150370.role preserve=no  public: CPIPersistentConfig {1..1 -> 1..1RFHN}
      CPIPersistentConfig *m_pConfig;
      //## end CETChannelMessagePersistentConfig::pConfig%40054A150370.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%400554230052
      //## Role: CETChannelMessagePersistentConfig::uiMessageSize%4005542302B4
      //## begin CETChannelMessagePersistentConfig::uiMessageSize%4005542302B4.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
      static UINT m_uiMessageSize;
      //## end CETChannelMessagePersistentConfig::uiMessageSize%4005542302B4.role

    // Additional Private Declarations
      //## begin CETChannelMessagePersistentConfig%40054737017B.private preserve=yes
      //## end CETChannelMessagePersistentConfig%40054737017B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessagePersistentConfig%40054737017B.implementation preserve=yes
      //## end CETChannelMessagePersistentConfig%40054737017B.implementation

};

//## begin CETChannelMessagePersistentConfig%40054737017B.postscript preserve=yes
//## end CETChannelMessagePersistentConfig%40054737017B.postscript

//## begin CETChannelMessageI2CAdcMax1037%4011233C0079.preface preserve=yes
//## end CETChannelMessageI2CAdcMax1037%4011233C0079.preface

//## Class: CETChannelMessageI2CAdcMax1037%4011233C0079
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageI2CAdcMax1037 : public CETChannelMessage  //## Inherits: <unnamed>%4011236F0105
{
  //## begin CETChannelMessageI2CAdcMax1037%4011233C0079.initialDeclarations preserve=yes
  //## end CETChannelMessageI2CAdcMax1037%4011233C0079.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageI2CAdcMax1037%1074861342
      CETChannelMessageI2CAdcMax1037 (CETChannelMessage* p_pStdMessage);

    //## Destructor (generated)
      virtual ~CETChannelMessageI2CAdcMax1037();


    //## Other Operations (specified)
      //## Operation: Serialize%1074861341
      virtual void Serialize (BYTE*& p_byStream, INT& p_iStreamLength);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%4011244501F0
      //## Role: CETChannelMessageI2CAdcMax1037::pDataAdc%4011244503E4
      void SetpDataAdc (CPIDataADCMAX1037 * value);

    // Additional Public Declarations
      //## begin CETChannelMessageI2CAdcMax1037%4011233C0079.public preserve=yes
      //## end CETChannelMessageI2CAdcMax1037%4011233C0079.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessageI2CAdcMax1037%4011233C0079.protected preserve=yes
      //## end CETChannelMessageI2CAdcMax1037%4011233C0079.protected

  private:
    //## Constructors (generated)
      CETChannelMessageI2CAdcMax1037();

      CETChannelMessageI2CAdcMax1037(const CETChannelMessageI2CAdcMax1037 &right);

    //## Assignment Operation (generated)
      const CETChannelMessageI2CAdcMax1037 & operator=(const CETChannelMessageI2CAdcMax1037 &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageI2CAdcMax1037 &right) const;

      bool operator!=(const CETChannelMessageI2CAdcMax1037 &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%4011244501F0
      //## begin CETChannelMessageI2CAdcMax1037::pDataAdc%4011244503E4.role preserve=no  public: CPIDataADCMAX1037 {1..1 -> 1..1RFHN}
      CPIDataADCMAX1037 *m_pDataAdc;
      //## end CETChannelMessageI2CAdcMax1037::pDataAdc%4011244503E4.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%401128BB0173
      //## Role: CETChannelMessageI2CAdcMax1037::uiMessageSize%401128BB0329
      //## begin CETChannelMessageI2CAdcMax1037::uiMessageSize%401128BB0329.role preserve=no  public: static UINT32 {1..1 -> 1..1VFHN}
      static UINT32 m_uiMessageSize;
      //## end CETChannelMessageI2CAdcMax1037::uiMessageSize%401128BB0329.role

    // Additional Private Declarations
      //## begin CETChannelMessageI2CAdcMax1037%4011233C0079.private preserve=yes
      //## end CETChannelMessageI2CAdcMax1037%4011233C0079.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageI2CAdcMax1037%4011233C0079.implementation preserve=yes
      //## end CETChannelMessageI2CAdcMax1037%4011233C0079.implementation

};

//## begin CETChannelMessageI2CAdcMax1037%4011233C0079.postscript preserve=yes
//## end CETChannelMessageI2CAdcMax1037%4011233C0079.postscript

//## begin CETChannelMessageString%41480C1102BF.preface preserve=yes
//## end CETChannelMessageString%41480C1102BF.preface

//## Class: CETChannelMessageString%41480C1102BF
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageString : public CETChannelMessage  //## Inherits: <unnamed>%41480C290157
{
  //## begin CETChannelMessageString%41480C1102BF.initialDeclarations preserve=yes
  //## end CETChannelMessageString%41480C1102BF.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageString%1095233136
      CETChannelMessageString (BYTE* p_byStream, INT p_iStreamLength);

      //## Operation: CETChannelMessageString%1095233138
      CETChannelMessageString (CETChannelMessage* p_pStdMessage);

    //## Destructor (generated)
      virtual ~CETChannelMessageString();


    //## Other Operations (specified)
      //## Operation: Serialize%1095233137
      virtual void Serialize (BYTE*& p_byStream, INT& p_iStreamLength);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: sString%41480C7A037A
      CString GetsString ();
      void SetsString (CString value);

    // Additional Public Declarations
      //## begin CETChannelMessageString%41480C1102BF.public preserve=yes
      //## end CETChannelMessageString%41480C1102BF.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessageString%41480C1102BF.protected preserve=yes
      //## end CETChannelMessageString%41480C1102BF.protected

  private:
    //## Constructors (generated)
      CETChannelMessageString();

      CETChannelMessageString(const CETChannelMessageString &right);

    //## Assignment Operation (generated)
      const CETChannelMessageString & operator=(const CETChannelMessageString &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageString &right) const;

      bool operator!=(const CETChannelMessageString &right) const;

    // Data Members for Class Attributes

      //## begin CETChannelMessageString::sString%41480C7A037A.attr preserve=no  public: CString {U} 
      CString m_sString;
      //## end CETChannelMessageString::sString%41480C7A037A.attr

      //## Attribute: uiMessageSize%41480C7A038A
      //## begin CETChannelMessageString::uiMessageSize%41480C7A038A.attr preserve=no  private: static UINT {U} m_uiBaseMessageSize+8
      static UINT m_uiMessageSize;
      //## end CETChannelMessageString::uiMessageSize%41480C7A038A.attr

    // Additional Private Declarations
      //## begin CETChannelMessageString%41480C1102BF.private preserve=yes
      //## end CETChannelMessageString%41480C1102BF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageString%41480C1102BF.implementation preserve=yes
      //## end CETChannelMessageString%41480C1102BF.implementation

};

//## begin CETChannelMessageString%41480C1102BF.postscript preserve=yes
//## end CETChannelMessageString%41480C1102BF.postscript

//## begin CETChannelMessageStepperHome%471CFB8C0213.preface preserve=yes
//## end CETChannelMessageStepperHome%471CFB8C0213.preface

//## Class: CETChannelMessageStepperHome%471CFB8C0213
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageStepperHome : public CETChannelMessage  //## Inherits: <unnamed>%471CFBA603E7
{
  //## begin CETChannelMessageStepperHome%471CFB8C0213.initialDeclarations preserve=yes
  //## end CETChannelMessageStepperHome%471CFB8C0213.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageStepperHome%1193077639
      CETChannelMessageStepperHome (BYTE* p_byStream, INT p_iStreamLength);

    //## Destructor (generated)
      virtual ~CETChannelMessageStepperHome();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: iLimitID%471CFC85024D
      INT GetiLimitID ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%471CFC1503C9
      //## Role: CETChannelMessageStepperHome::eFastFindingDirection%471CFC160295
      EPIMotorPolarity GeteFastFindingDirection ();

      //## Association: EBET (Ethernet Transport)::<unnamed>%471CFC520019
      //## Role: CETChannelMessageStepperHome::bSearchLimitFromOpposite%471CFC530223
      bool GetbSearchLimitFromOpposite ();

    // Additional Public Declarations
      //## begin CETChannelMessageStepperHome%471CFB8C0213.public preserve=yes
      //## end CETChannelMessageStepperHome%471CFB8C0213.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelMessageStepperHome%471CFB8C0213.protected preserve=yes
      //## end CETChannelMessageStepperHome%471CFB8C0213.protected

  private:
    //## Constructors (generated)
      CETChannelMessageStepperHome();

      CETChannelMessageStepperHome(const CETChannelMessageStepperHome &right);

    //## Assignment Operation (generated)
      const CETChannelMessageStepperHome & operator=(const CETChannelMessageStepperHome &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageStepperHome &right) const;

      bool operator!=(const CETChannelMessageStepperHome &right) const;

    // Data Members for Class Attributes

      //## begin CETChannelMessageStepperHome::iLimitID%471CFC85024D.attr preserve=no  public: INT {U} 
      INT m_iLimitID;
      //## end CETChannelMessageStepperHome::iLimitID%471CFC85024D.attr

      //## Attribute: uiMessageSize%471CFD490277
      //## begin CETChannelMessageStepperHome::uiMessageSize%471CFD490277.attr preserve=no  private: static UINT {U} m_uiBaseMessageSize+12
      static UINT m_uiMessageSize;
      //## end CETChannelMessageStepperHome::uiMessageSize%471CFD490277.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%471CFC1503C9
      //## begin CETChannelMessageStepperHome::eFastFindingDirection%471CFC160295.role preserve=no  public: EPIMotorPolarity {1..1 -> 1..1VHN}
      EPIMotorPolarity m_eFastFindingDirection;
      //## end CETChannelMessageStepperHome::eFastFindingDirection%471CFC160295.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%471CFC520019
      //## begin CETChannelMessageStepperHome::bSearchLimitFromOpposite%471CFC530223.role preserve=no  public: bool {1..1 -> 1..1VHN}
      bool m_bSearchLimitFromOpposite;
      //## end CETChannelMessageStepperHome::bSearchLimitFromOpposite%471CFC530223.role

    // Additional Private Declarations
      //## begin CETChannelMessageStepperHome%471CFB8C0213.private preserve=yes
      //## end CETChannelMessageStepperHome%471CFB8C0213.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageStepperHome%471CFB8C0213.implementation preserve=yes
      //## end CETChannelMessageStepperHome%471CFB8C0213.implementation

};

//## begin CETChannelMessageStepperHome%471CFB8C0213.postscript preserve=yes
//## end CETChannelMessageStepperHome%471CFB8C0213.postscript

// Class CETChannelMessage 

// Class CETChannelMessageMeasurementDataPackage 

// Class CETChannelMessageTwoInteger 

// Class CETChannelMessageStepperLimit 

// Class CETChannelMessageStepperProfile 

// Class CETChannelMessageStepperLimitFootPrint 

// Class CETChannelMessageMeasurementChannelProfile 

// Class CETChannelMessageWedgeProfile 

// Class CETChannelMessageWedgeConfig 

// Class CETChannelMessageTemperatureProfile 

// Class CETChannelMessageTemperatureConfig 

// Class CETChannelMessagePowerProfile 

// Class CETChannelMessagePowerConfig 

// Class CETChannelMessagePersistentIdentification 

// Class CETChannelMessagePersistentParameter 

// Class CETChannelMessagePersistentSoftwareComponent 

// Class CETChannelMessagePersistentSoftwareComponentVersion 

// Class CETChannelMessageStepperConfig 

// Class CETChannelMessageSystemInterfaceConfig 

// Class CETChannelMessageI2CTempDS1631ZConfig 

// Class CETChannelMessageSystemComponentState 

// Class CETChannelMessageSystemGetObjectList 

// Class CETChannelMessageSystemSetTime 

// Class CETChannelMessagePersistentConfig 

// Class CETChannelMessageI2CAdcMax1037 

// Class CETChannelMessageString 

// Class CETChannelMessageStepperHome 

//## begin module%3DA2A5A102CD.epilog preserve=yes
//## end module%3DA2A5A102CD.epilog


#endif
