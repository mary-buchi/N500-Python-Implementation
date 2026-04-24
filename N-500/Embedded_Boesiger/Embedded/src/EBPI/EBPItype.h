//## begin module%3DAE54C202D2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAE54C202D2.cm

//## begin module%3DAE54C202D2.cp preserve=no
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
//## end module%3DAE54C202D2.cp

//## Module: EBPItype%3DAE54C202D2; Package specification
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPItype.h

#ifndef EBPItype_h
#define EBPItype_h 1

//## begin module%3DAE54C202D2.additionalIncludes preserve=no
//## end module%3DAE54C202D2.additionalIncludes

//## begin module%3DAE54C202D2.includes preserve=yes
//## end module%3DAE54C202D2.includes

// EBCOrefc
#include "EBCOrefc.h"
// EBPIenum
#include "EBPIenum.h"
// EBCOsypr
#include "EBCOsypr.h"

class EBPI_DLL_DECL CPIMeasurementChannelDataPackage;
class EBPI_DLL_DECL CPIPersistentSoftwareComponentVersion;
class EBPI_DLL_DECL CPIPersistentSoftwareComponent;
class EBPI_DLL_DECL CPIDataADCMAX1037;
class EBPI_DLL_DECL CPIConfigDS1631Z;
class EBPI_DLL_DECL CPII2CDataStream;
class EBPI_DLL_DECL CPIPersistentItem;

//## begin module%3DAE54C202D2.declarations preserve=no
#define PI_PERSISTENT_OBJ_ID_LENGTH  64
#define PI_PERSISTENT_SW_CPO_NAME_LENGTH 128
#define PI_PERSISTENT_SW_CPO_VERSION_LENGTH 16
//## end module%3DAE54C202D2.declarations

//## begin module%3DAE54C202D2.additionalDeclarations preserve=yes
//## end module%3DAE54C202D2.additionalDeclarations


//## begin CPIMeasurementChannelDataPackage%3DAE54DC0264.preface preserve=yes
//## end CPIMeasurementChannelDataPackage%3DAE54DC0264.preface

//## Class: CPIMeasurementChannelDataPackage%3DAE54DC0264
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIMeasurementChannelDataPackage : public ICORefCounting  //## Inherits: <unnamed>%3DF856040316
{
  //## begin CPIMeasurementChannelDataPackage%3DAE54DC0264.initialDeclarations preserve=yes
  //## end CPIMeasurementChannelDataPackage%3DAE54DC0264.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIMeasurementChannelDataPackage%1034835012
      CPIMeasurementChannelDataPackage (UINT p_uiID, UINT p_uiSize, BYTE* p_pLaserData, BYTE* p_pDetectorData);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: uiID%3DAE5531011D
      UINT GetuiID ();

      //## Attribute: uiSize%3DAE555601C9
      UINT GetuiSize ();

      //## Attribute: pLaserData%3DAE556F0071
      BYTE* GetpLaserData ();

      //## Attribute: pDetectorData%3DB7BC81018C
      BYTE* GetpDetectorData ();

    // Additional Public Declarations
      //## begin CPIMeasurementChannelDataPackage%3DAE54DC0264.public preserve=yes
      //## end CPIMeasurementChannelDataPackage%3DAE54DC0264.public

  protected:
    // Additional Protected Declarations
      //## begin CPIMeasurementChannelDataPackage%3DAE54DC0264.protected preserve=yes
      //## end CPIMeasurementChannelDataPackage%3DAE54DC0264.protected

  private:
    //## Constructors (generated)
      CPIMeasurementChannelDataPackage();

      CPIMeasurementChannelDataPackage(const CPIMeasurementChannelDataPackage &right);

    //## Destructor (generated)
      virtual ~CPIMeasurementChannelDataPackage();

    //## Assignment Operation (generated)
      const CPIMeasurementChannelDataPackage & operator=(const CPIMeasurementChannelDataPackage &right);

    //## Equality Operations (generated)
      bool operator==(const CPIMeasurementChannelDataPackage &right) const;

      bool operator!=(const CPIMeasurementChannelDataPackage &right) const;

    // Data Members for Class Attributes

      //## begin CPIMeasurementChannelDataPackage::uiID%3DAE5531011D.attr preserve=no  public: UINT {U} p_uiID
      UINT m_uiID;
      //## end CPIMeasurementChannelDataPackage::uiID%3DAE5531011D.attr

      //## begin CPIMeasurementChannelDataPackage::uiSize%3DAE555601C9.attr preserve=no  public: UINT {U} p_uiSize
      UINT m_uiSize;
      //## end CPIMeasurementChannelDataPackage::uiSize%3DAE555601C9.attr

      //## begin CPIMeasurementChannelDataPackage::pLaserData%3DAE556F0071.attr preserve=no  public: BYTE* {U} p_pLaserData
      BYTE* m_pLaserData;
      //## end CPIMeasurementChannelDataPackage::pLaserData%3DAE556F0071.attr

      //## begin CPIMeasurementChannelDataPackage::pDetectorData%3DB7BC81018C.attr preserve=no  public: BYTE* {U} p_pDetectorData
      BYTE* m_pDetectorData;
      //## end CPIMeasurementChannelDataPackage::pDetectorData%3DB7BC81018C.attr

    // Additional Private Declarations
      //## begin CPIMeasurementChannelDataPackage%3DAE54DC0264.private preserve=yes
      //## end CPIMeasurementChannelDataPackage%3DAE54DC0264.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIMeasurementChannelDataPackage%3DAE54DC0264.implementation preserve=yes
      //## end CPIMeasurementChannelDataPackage%3DAE54DC0264.implementation

};

//## begin CPIMeasurementChannelDataPackage%3DAE54DC0264.postscript preserve=yes
//## end CPIMeasurementChannelDataPackage%3DAE54DC0264.postscript

//## begin CPISyncObjDataPackage%3DAE55EB02B4.preface preserve=yes
//## end CPISyncObjDataPackage%3DAE55EB02B4.preface

//## Class: CPISyncObjDataPackage%3DAE55EB02B4; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAE56750238;CPIMeasurementChannelDataPackage { -> F}

typedef CCOSyncObjectParameterizedByRef< CPIMeasurementChannelDataPackage* > CPISyncObjDataPackage;

//## begin CPISyncObjDataPackage%3DAE55EB02B4.postscript preserve=yes
//## end CPISyncObjDataPackage%3DAE55EB02B4.postscript

//## begin CPIObjIdentification%3DB50C20034E.preface preserve=yes
//## end CPIObjIdentification%3DB50C20034E.preface

//## Class: CPIObjIdentification%3DB50C20034E
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIObjIdentification : public ICORefCounting  //## Inherits: <unnamed>%3DE38B4F0188
{
  //## begin CPIObjIdentification%3DB50C20034E.initialDeclarations preserve=yes
  //## end CPIObjIdentification%3DB50C20034E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIObjIdentification%1036680714
      CPIObjIdentification (UINT p_uiID);

    //## Equality Operations (generated)
      bool operator==(const CPIObjIdentification &right) const;

      bool operator!=(const CPIObjIdentification &right) const;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: uiID%3DCA8DFE023C
      UINT GetuiID ();

    // Additional Public Declarations
      //## begin CPIObjIdentification%3DB50C20034E.public preserve=yes
      //## end CPIObjIdentification%3DB50C20034E.public

  protected:
    // Additional Protected Declarations
      //## begin CPIObjIdentification%3DB50C20034E.protected preserve=yes
      //## end CPIObjIdentification%3DB50C20034E.protected

  private:
    //## Constructors (generated)
      CPIObjIdentification();

      CPIObjIdentification(const CPIObjIdentification &right);

    //## Destructor (generated)
      virtual ~CPIObjIdentification();

    //## Assignment Operation (generated)
      const CPIObjIdentification & operator=(const CPIObjIdentification &right);

    // Data Members for Class Attributes

      //## begin CPIObjIdentification::uiID%3DCA8DFE023C.attr preserve=no  public: UINT {U} p_uiID
      UINT m_uiID;
      //## end CPIObjIdentification::uiID%3DCA8DFE023C.attr

    // Additional Private Declarations
      //## begin CPIObjIdentification%3DB50C20034E.private preserve=yes
      //## end CPIObjIdentification%3DB50C20034E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIObjIdentification%3DB50C20034E.implementation preserve=yes
      //## end CPIObjIdentification%3DB50C20034E.implementation

};

//## begin CPIObjIdentification%3DB50C20034E.postscript preserve=yes
//## end CPIObjIdentification%3DB50C20034E.postscript

//## begin CPIPersistentSoftwareComponent%3DB9016E0298.preface preserve=yes
//## end CPIPersistentSoftwareComponent%3DB9016E0298.preface

//## Class: CPIPersistentSoftwareComponent%3DB9016E0298
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIPersistentSoftwareComponent : public ICORefCounting  //## Inherits: <unnamed>%3DD904BA0134
{
  //## begin CPIPersistentSoftwareComponent%3DB9016E0298.initialDeclarations preserve=yes
  //## end CPIPersistentSoftwareComponent%3DB9016E0298.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIPersistentSoftwareComponent%1035528319
      CPIPersistentSoftwareComponent (WCHAR* p_sName, bool p_bRequiresReboot, bool p_bIsFPGASource, bool p_bIsWinCEImage, BYTE* p_pbyImage, INT p_iImageSize);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: sName%3DB901AE03B2
      WCHAR* GetsName ();

      //## Attribute: bRequiresReboot%3DB901D500D3
      bool GetbRequiresReboot ();

      //## Attribute: pImage%3DB902150066
      BYTE* GetpImage ();

      //## Attribute: iImageSize%40960A9F00CB
      INT GetiImageSize ();

      //## Attribute: bIsFPGASource%4107608C007D
      bool GetbIsFPGASource ();

      //## Attribute: bIsWinCEImage%410760CB036B
      bool GetbIsWinCEImage ();

    // Additional Public Declarations
      //## begin CPIPersistentSoftwareComponent%3DB9016E0298.public preserve=yes
      //## end CPIPersistentSoftwareComponent%3DB9016E0298.public

  protected:
    // Additional Protected Declarations
      //## begin CPIPersistentSoftwareComponent%3DB9016E0298.protected preserve=yes
      //## end CPIPersistentSoftwareComponent%3DB9016E0298.protected

  private:
    //## Constructors (generated)
      CPIPersistentSoftwareComponent();

      CPIPersistentSoftwareComponent(const CPIPersistentSoftwareComponent &right);

    //## Destructor (generated)
      virtual ~CPIPersistentSoftwareComponent();

    //## Assignment Operation (generated)
      const CPIPersistentSoftwareComponent & operator=(const CPIPersistentSoftwareComponent &right);

    //## Equality Operations (generated)
      bool operator==(const CPIPersistentSoftwareComponent &right) const;

      bool operator!=(const CPIPersistentSoftwareComponent &right) const;

    // Data Members for Class Attributes

      //## begin CPIPersistentSoftwareComponent::sName%3DB901AE03B2.attr preserve=no  public: WCHAR[PI_PERSISTENT_SW_CPO_NAME_LENGTH] {U} 
      WCHAR m_sName[PI_PERSISTENT_SW_CPO_NAME_LENGTH];
      //## end CPIPersistentSoftwareComponent::sName%3DB901AE03B2.attr

      //## begin CPIPersistentSoftwareComponent::bRequiresReboot%3DB901D500D3.attr preserve=no  public: bool {U} p_bRequiresReboot
      bool m_bRequiresReboot;
      //## end CPIPersistentSoftwareComponent::bRequiresReboot%3DB901D500D3.attr

      //## begin CPIPersistentSoftwareComponent::pImage%3DB902150066.attr preserve=no  public: BYTE* {U} p_pbyImage
      BYTE* m_pImage;
      //## end CPIPersistentSoftwareComponent::pImage%3DB902150066.attr

      //## begin CPIPersistentSoftwareComponent::iImageSize%40960A9F00CB.attr preserve=no  public: INT {U} p_iImageSize
      INT m_iImageSize;
      //## end CPIPersistentSoftwareComponent::iImageSize%40960A9F00CB.attr

      //## begin CPIPersistentSoftwareComponent::bIsFPGASource%4107608C007D.attr preserve=no  public: bool {U} p_bIsFPGASource
      bool m_bIsFPGASource;
      //## end CPIPersistentSoftwareComponent::bIsFPGASource%4107608C007D.attr

      //## begin CPIPersistentSoftwareComponent::bIsWinCEImage%410760CB036B.attr preserve=no  public: bool {U} p_bIsWinCEImage
      bool m_bIsWinCEImage;
      //## end CPIPersistentSoftwareComponent::bIsWinCEImage%410760CB036B.attr

    // Additional Private Declarations
      //## begin CPIPersistentSoftwareComponent%3DB9016E0298.private preserve=yes
      //## end CPIPersistentSoftwareComponent%3DB9016E0298.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIPersistentSoftwareComponent%3DB9016E0298.implementation preserve=yes
      //## end CPIPersistentSoftwareComponent%3DB9016E0298.implementation

};

//## begin CPIPersistentSoftwareComponent%3DB9016E0298.postscript preserve=yes
//## end CPIPersistentSoftwareComponent%3DB9016E0298.postscript

//## begin CPIPersistentSoftwareComponentVersion%3DB9049E01CD.preface preserve=yes
//## end CPIPersistentSoftwareComponentVersion%3DB9049E01CD.preface

//## Class: CPIPersistentSoftwareComponentVersion%3DB9049E01CD
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIPersistentSoftwareComponentVersion : public ICORefCounting  //## Inherits: <unnamed>%3DD904B70328
{
  //## begin CPIPersistentSoftwareComponentVersion%3DB9049E01CD.initialDeclarations preserve=yes
  //## end CPIPersistentSoftwareComponentVersion%3DB9049E01CD.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIPersistentSoftwareComponentVersion%1035528320
      CPIPersistentSoftwareComponentVersion (WCHAR* p_sName, WCHAR* p_sVersion);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: sName%3DB904D50335
      WCHAR* GetsName ();

      //## Attribute: sVersion%3DB904D70018
      WCHAR* GetsVersion ();

    // Additional Public Declarations
      //## begin CPIPersistentSoftwareComponentVersion%3DB9049E01CD.public preserve=yes
      //## end CPIPersistentSoftwareComponentVersion%3DB9049E01CD.public

  protected:
    // Additional Protected Declarations
      //## begin CPIPersistentSoftwareComponentVersion%3DB9049E01CD.protected preserve=yes
      //## end CPIPersistentSoftwareComponentVersion%3DB9049E01CD.protected

  private:
    //## Constructors (generated)
      CPIPersistentSoftwareComponentVersion();

      CPIPersistentSoftwareComponentVersion(const CPIPersistentSoftwareComponentVersion &right);

    //## Destructor (generated)
      virtual ~CPIPersistentSoftwareComponentVersion();

    //## Assignment Operation (generated)
      const CPIPersistentSoftwareComponentVersion & operator=(const CPIPersistentSoftwareComponentVersion &right);

    //## Equality Operations (generated)
      bool operator==(const CPIPersistentSoftwareComponentVersion &right) const;

      bool operator!=(const CPIPersistentSoftwareComponentVersion &right) const;

    // Data Members for Class Attributes

      //## begin CPIPersistentSoftwareComponentVersion::sName%3DB904D50335.attr preserve=no  public: WCHAR[PI_PERSISTENT_SW_CPO_NAME_LENGTH] {U} 
      WCHAR m_sName[PI_PERSISTENT_SW_CPO_NAME_LENGTH];
      //## end CPIPersistentSoftwareComponentVersion::sName%3DB904D50335.attr

      //## begin CPIPersistentSoftwareComponentVersion::sVersion%3DB904D70018.attr preserve=no  public: WCHAR[PI_PERSISTENT_SW_CPO_VERSION_LENGTH] {U} 
      WCHAR m_sVersion[PI_PERSISTENT_SW_CPO_VERSION_LENGTH];
      //## end CPIPersistentSoftwareComponentVersion::sVersion%3DB904D70018.attr

    // Additional Private Declarations
      //## begin CPIPersistentSoftwareComponentVersion%3DB9049E01CD.private preserve=yes
      //## end CPIPersistentSoftwareComponentVersion%3DB9049E01CD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIPersistentSoftwareComponentVersion%3DB9049E01CD.implementation preserve=yes
      //## end CPIPersistentSoftwareComponentVersion%3DB9049E01CD.implementation

};

//## begin CPIPersistentSoftwareComponentVersion%3DB9049E01CD.postscript preserve=yes
//## end CPIPersistentSoftwareComponentVersion%3DB9049E01CD.postscript

//## begin CPITemperatureControlProfile%3DB937ED017F.preface preserve=yes
//## end CPITemperatureControlProfile%3DB937ED017F.preface

//## Class: CPITemperatureControlProfile%3DB937ED017F
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPITemperatureControlProfile : public ICORefCounting  //## Inherits: <unnamed>%3DD399790080
{
  //## begin CPITemperatureControlProfile%3DB937ED017F.initialDeclarations preserve=yes
  //## end CPITemperatureControlProfile%3DB937ED017F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPITemperatureControlProfile%1049124052
      CPITemperatureControlProfile (int p_iTemperatureNominal, int p_iTemperatureWarningULimit, int p_iTemperatureWarningLLimit, int p_iTemperatureErrorULimit, int p_iTemperatureErrorLLimit);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: iTemperatureNominal%3DB93F4202A8
      //	[milli degrees] Temperature set value.
      int GetiTemperatureNominal ();

      //## Attribute: iTemperatureWarningULimit%3DB9387F03E1
      //	[milli degrees] Temperature warning level upper limit.
      int GetiTemperatureWarningULimit ();

      //## Attribute: iTemperatureWarningLLimit%3DB938500364
      //	[milli degrees] Temperature warning level lower limit.
      int GetiTemperatureWarningLLimit ();

      //## Attribute: iTemperatureErrorULimit%3DB9389F01CD
      //	[milli degrees] Temperature error level upper limit.
      int GetiTemperatureErrorULimit ();

      //## Attribute: iTemperatureErrorLLimit%3DB9388C026A
      //	[milli degrees]  Temperature error level lower limit.
      int GetiTemperatureErrorLLimit ();

    // Additional Public Declarations
      //## begin CPITemperatureControlProfile%3DB937ED017F.public preserve=yes
      //## end CPITemperatureControlProfile%3DB937ED017F.public

  protected:
    // Additional Protected Declarations
      //## begin CPITemperatureControlProfile%3DB937ED017F.protected preserve=yes
      //## end CPITemperatureControlProfile%3DB937ED017F.protected

  private:
    //## Constructors (generated)
      CPITemperatureControlProfile();

      CPITemperatureControlProfile(const CPITemperatureControlProfile &right);

    //## Destructor (generated)
      virtual ~CPITemperatureControlProfile();

    //## Assignment Operation (generated)
      const CPITemperatureControlProfile & operator=(const CPITemperatureControlProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CPITemperatureControlProfile &right) const;

      bool operator!=(const CPITemperatureControlProfile &right) const;

    // Data Members for Class Attributes

      //## begin CPITemperatureControlProfile::iTemperatureNominal%3DB93F4202A8.attr preserve=no  public: int {U} p_iTemperatureNominal
      int m_iTemperatureNominal;
      //## end CPITemperatureControlProfile::iTemperatureNominal%3DB93F4202A8.attr

      //## begin CPITemperatureControlProfile::iTemperatureWarningULimit%3DB9387F03E1.attr preserve=no  public: int {U} p_iTemperatureWarningULimit
      int m_iTemperatureWarningULimit;
      //## end CPITemperatureControlProfile::iTemperatureWarningULimit%3DB9387F03E1.attr

      //## begin CPITemperatureControlProfile::iTemperatureWarningLLimit%3DB938500364.attr preserve=no  public: int {U} p_iTemperatureWarningLLimit
      int m_iTemperatureWarningLLimit;
      //## end CPITemperatureControlProfile::iTemperatureWarningLLimit%3DB938500364.attr

      //## begin CPITemperatureControlProfile::iTemperatureErrorULimit%3DB9389F01CD.attr preserve=no  public: int {U} p_iTemperatureErrorULimit
      int m_iTemperatureErrorULimit;
      //## end CPITemperatureControlProfile::iTemperatureErrorULimit%3DB9389F01CD.attr

      //## begin CPITemperatureControlProfile::iTemperatureErrorLLimit%3DB9388C026A.attr preserve=no  public: int {U} p_iTemperatureErrorLLimit
      int m_iTemperatureErrorLLimit;
      //## end CPITemperatureControlProfile::iTemperatureErrorLLimit%3DB9388C026A.attr

    // Additional Private Declarations
      //## begin CPITemperatureControlProfile%3DB937ED017F.private preserve=yes
      //## end CPITemperatureControlProfile%3DB937ED017F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPITemperatureControlProfile%3DB937ED017F.implementation preserve=yes
      //## end CPITemperatureControlProfile%3DB937ED017F.implementation

};

//## begin CPITemperatureControlProfile%3DB937ED017F.postscript preserve=yes
//## end CPITemperatureControlProfile%3DB937ED017F.postscript

//## begin CPITemperatureControlConfig%3DB93818022B.preface preserve=yes
//## end CPITemperatureControlConfig%3DB93818022B.preface

//## Class: CPITemperatureControlConfig%3DB93818022B
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPITemperatureControlConfig : public ICORefCounting  //## Inherits: <unnamed>%3DD3997B0080
{
  //## begin CPITemperatureControlConfig%3DB93818022B.initialDeclarations preserve=yes
  //## end CPITemperatureControlConfig%3DB93818022B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPITemperatureControlConfig%1035548922
      CPITemperatureControlConfig (const int p_iPid_Kp, const int p_iPid_Ti, const int p_iPid_Tv, const int p_iPid_LLimit, const int p_iPid_ULimit, const int p_iPid_Ts, EPILineVoltage p_eLineVoltage, const DWORD p_dwIDHeaterTemperatureSensor, const DWORD p_dwIDHeaterOutput, CPIConfigDS1631Z* p_pSensorConfig);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: iPid_Kp%3E5C7DAA0321
      //	DESCRIPTION:
      //	P-Factor (PID controller).
      //
      //	UNIT: [10^-3]
      INT GetiPid_Kp ();

      //## Attribute: iPid_Ti%3E5C7DF401B9
      //	DESCRIPTION:
      //	I-Factor (PID controller).
      //
      //	UNIT: [10^-3]
      INT GetiPid_Ti ();

      //## Attribute: iPid_Tv%3E5C7E0F00DE
      //	DESCRIPTION:
      //	D-Factor (PID controller).
      //
      //	UNIT: [10^-3]
      INT GetiPid_Tv ();

      //## Attribute: iPid_LLimit%3E5C7E94035F
      //	DESCRIPTION:
      //	Limits PID controller output. In per cent of the nominal
      //	temperature.
      //
      //	UNIT: [% * 10^-3]
      INT GetiPid_LLimit ();

      //## Attribute: iPid_ULimit%40D14CEF0157
      //	DESCRIPTION:
      //	Limits PID controller output. In per cent of the nominal
      //	temperature.
      //
      //	UNIT: [% * 10^-3]
      INT GetiPid_ULimit ();

      //## Attribute: iPid_Ts%3E5C7EC00071
      //	DESCRIPTION:
      //	Sampling Time.
      //
      //	UNIT: [s * 10^-3]
      INT GetiPid_Ts ();

      //## Attribute: dwIDHeaterTemperatureSensor%3F151FC300A4
      //	DESCRIPTION:
      //	Corresponding logical identification (ID) to get the
      //	temperature from the hardware.
      //
      //	UNIT: [-]
      const DWORD GetdwIDHeaterTemperatureSensor ();

      //## Attribute: dwIDHeaterOutput%3F15204E03B1
      //	DESCRIPTION:
      //	Corresponding identification (ID) to set voltage on the
      //	hardware interface (HI).
      //
      //	UNIT: [-]
      DWORD GetdwIDHeaterOutput ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPI (PC Interface)::<unnamed>%40C9ADE701A2
      //## Role: CPITemperatureControlConfig::pSensorConfig%40C9ADE8000C
      CPIConfigDS1631Z * GetpSensorConfig ();

      //## Association: EBPI (PC Interface)::<unnamed>%41947CE20313
      //## Role: CPITemperatureControlConfig::eLineVoltage%41947CE30292
      EPILineVoltage GeteLineVoltage ();

    // Additional Public Declarations
      //## begin CPITemperatureControlConfig%3DB93818022B.public preserve=yes
      //## end CPITemperatureControlConfig%3DB93818022B.public

  protected:
    // Additional Protected Declarations
      //## begin CPITemperatureControlConfig%3DB93818022B.protected preserve=yes
      //## end CPITemperatureControlConfig%3DB93818022B.protected

  private:
    //## Constructors (generated)
      CPITemperatureControlConfig();

      CPITemperatureControlConfig(const CPITemperatureControlConfig &right);

    //## Destructor (generated)
      virtual ~CPITemperatureControlConfig();

    //## Assignment Operation (generated)
      const CPITemperatureControlConfig & operator=(const CPITemperatureControlConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CPITemperatureControlConfig &right) const;

      bool operator!=(const CPITemperatureControlConfig &right) const;

    // Data Members for Class Attributes

      //## begin CPITemperatureControlConfig::iPid_Kp%3E5C7DAA0321.attr preserve=no  public: INT {U} p_iPid_Kp
      INT m_iPid_Kp;
      //## end CPITemperatureControlConfig::iPid_Kp%3E5C7DAA0321.attr

      //## begin CPITemperatureControlConfig::iPid_Ti%3E5C7DF401B9.attr preserve=no  public: INT {U} p_iPid_Ti
      INT m_iPid_Ti;
      //## end CPITemperatureControlConfig::iPid_Ti%3E5C7DF401B9.attr

      //## begin CPITemperatureControlConfig::iPid_Tv%3E5C7E0F00DE.attr preserve=no  public: INT {U} p_iPid_Tv
      INT m_iPid_Tv;
      //## end CPITemperatureControlConfig::iPid_Tv%3E5C7E0F00DE.attr

      //## begin CPITemperatureControlConfig::iPid_LLimit%3E5C7E94035F.attr preserve=no  public: INT {U} p_iPid_LLimit
      INT m_iPid_LLimit;
      //## end CPITemperatureControlConfig::iPid_LLimit%3E5C7E94035F.attr

      //## begin CPITemperatureControlConfig::iPid_ULimit%40D14CEF0157.attr preserve=no  public: INT {U} p_iPid_ULimit
      INT m_iPid_ULimit;
      //## end CPITemperatureControlConfig::iPid_ULimit%40D14CEF0157.attr

      //## begin CPITemperatureControlConfig::iPid_Ts%3E5C7EC00071.attr preserve=no  public: INT {U} p_iPid_Ts
      INT m_iPid_Ts;
      //## end CPITemperatureControlConfig::iPid_Ts%3E5C7EC00071.attr

      //## begin CPITemperatureControlConfig::dwIDHeaterTemperatureSensor%3F151FC300A4.attr preserve=no  public: const DWORD {U} p_dwIDHeaterTemperatureSensor
      const DWORD m_dwIDHeaterTemperatureSensor;
      //## end CPITemperatureControlConfig::dwIDHeaterTemperatureSensor%3F151FC300A4.attr

      //## begin CPITemperatureControlConfig::dwIDHeaterOutput%3F15204E03B1.attr preserve=no  public: DWORD {U} p_dwIDHeaterOutput
      DWORD m_dwIDHeaterOutput;
      //## end CPITemperatureControlConfig::dwIDHeaterOutput%3F15204E03B1.attr

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%40C9ADE701A2
      //## begin CPITemperatureControlConfig::pSensorConfig%40C9ADE8000C.role preserve=no  public: CPIConfigDS1631Z {1..1 -> 1..1RFHN}
      CPIConfigDS1631Z *m_pSensorConfig;
      //## end CPITemperatureControlConfig::pSensorConfig%40C9ADE8000C.role

      //## Association: EBPI (PC Interface)::<unnamed>%41947CE20313
      //## begin CPITemperatureControlConfig::eLineVoltage%41947CE30292.role preserve=no  public: EPILineVoltage {1..1 -> 1..1VFHN}
      EPILineVoltage m_eLineVoltage;
      //## end CPITemperatureControlConfig::eLineVoltage%41947CE30292.role

    // Additional Private Declarations
      //## begin CPITemperatureControlConfig%3DB93818022B.private preserve=yes
      //## end CPITemperatureControlConfig%3DB93818022B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPITemperatureControlConfig%3DB93818022B.implementation preserve=yes
      //## end CPITemperatureControlConfig%3DB93818022B.implementation

};

//## begin CPITemperatureControlConfig%3DB93818022B.postscript preserve=yes
//## end CPITemperatureControlConfig%3DB93818022B.postscript

//## begin CPIPowerControlProfile%3DB9480101BE.preface preserve=yes
//## end CPIPowerControlProfile%3DB9480101BE.preface

//## Class: CPIPowerControlProfile%3DB9480101BE
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIPowerControlProfile : public ICORefCounting  //## Inherits: <unnamed>%3DD39E2102E1
{
  //## begin CPIPowerControlProfile%3DB9480101BE.initialDeclarations preserve=yes
  //## end CPIPowerControlProfile%3DB9480101BE.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIPowerControlProfile%1049124051
      CPIPowerControlProfile (const UINT p_uiPowerNominal, const UINT p_uiPowerErrorULimit, const UINT p_uiPowerErrorLLimit);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: uiPowerNominal%3E8961F3006D
      //	DESCRIPTION:
      //	Power set value.
      //
      //	UNIT:
      //	[W * 10^-3] (milli watt)
      UINT GetuiPowerNominal ();

      //## Attribute: uiPowerErrorULimit%3E8962000271
      //	DESCRIPTION:
      //	Power error level upper limit.
      //
      //	UNIT:
      //	[W * 10^-3] (milli watt)
      UINT GetuiPowerErrorULimit ();

      //## Attribute: uiPowerErrorLLimit%3E8961FE029F
      //	DESCRIPTION:
      //	Power error level lower limit.
      //
      //	UNIT:
      //	[W * 10^-3] (milli watt)
      UINT GetuiPowerErrorLLimit ();

    // Additional Public Declarations
      //## begin CPIPowerControlProfile%3DB9480101BE.public preserve=yes
      //## end CPIPowerControlProfile%3DB9480101BE.public

  protected:
    // Additional Protected Declarations
      //## begin CPIPowerControlProfile%3DB9480101BE.protected preserve=yes
      //## end CPIPowerControlProfile%3DB9480101BE.protected

  private:
    //## Constructors (generated)
      CPIPowerControlProfile();

      CPIPowerControlProfile(const CPIPowerControlProfile &right);

    //## Destructor (generated)
      virtual ~CPIPowerControlProfile();

    //## Assignment Operation (generated)
      const CPIPowerControlProfile & operator=(const CPIPowerControlProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CPIPowerControlProfile &right) const;

      bool operator!=(const CPIPowerControlProfile &right) const;

    // Data Members for Class Attributes

      //## begin CPIPowerControlProfile::uiPowerNominal%3E8961F3006D.attr preserve=no  public: UINT {U} p_uiPowerNominal
      UINT m_uiPowerNominal;
      //## end CPIPowerControlProfile::uiPowerNominal%3E8961F3006D.attr

      //## begin CPIPowerControlProfile::uiPowerErrorULimit%3E8962000271.attr preserve=no  public: UINT {U} p_uiPowerErrorULimit
      UINT m_uiPowerErrorULimit;
      //## end CPIPowerControlProfile::uiPowerErrorULimit%3E8962000271.attr

      //## begin CPIPowerControlProfile::uiPowerErrorLLimit%3E8961FE029F.attr preserve=no  public: UINT {U} p_uiPowerErrorLLimit
      UINT m_uiPowerErrorLLimit;
      //## end CPIPowerControlProfile::uiPowerErrorLLimit%3E8961FE029F.attr

    // Additional Private Declarations
      //## begin CPIPowerControlProfile%3DB9480101BE.private preserve=yes
      //## end CPIPowerControlProfile%3DB9480101BE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIPowerControlProfile%3DB9480101BE.implementation preserve=yes
      //## end CPIPowerControlProfile%3DB9480101BE.implementation

};

//## begin CPIPowerControlProfile%3DB9480101BE.postscript preserve=yes
//## end CPIPowerControlProfile%3DB9480101BE.postscript

//## begin CPIWedgeControlProfile%3DB9494E0354.preface preserve=yes
//## end CPIWedgeControlProfile%3DB9494E0354.preface

//## Class: CPIWedgeControlProfile%3DB9494E0354
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIWedgeControlProfile : public ICORefCounting  //## Inherits: <unnamed>%3DD205EE020A
{
  //## begin CPIWedgeControlProfile%3DB9494E0354.initialDeclarations preserve=yes
  //## end CPIWedgeControlProfile%3DB9494E0354.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIWedgeControlProfile%1043748202
      CPIWedgeControlProfile (DWORD p_dwScanMode, DWORD p_dwRefDistance2);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwScanMode%3FBC8ED501A5
      //	DESCRIPTION
      //	half or full scan
      //
      //	0: half scan
      //	1: full scan
      const DWORD GetdwScanMode () const;
      void SetdwScanMode (DWORD value);

      //## Attribute: dwRefDistance2%3E2E73A100F7
      //	DESCRIPTION
      //	Distance which is driven off after reaching the light
      //	barrier during the referencing mode
      //
      //	UNIT: [Sample Points]
      //	(Distance um / ~12.1um)
      const DWORD GetdwRefDistance2 () const;
      void SetdwRefDistance2 (DWORD value);

    // Additional Public Declarations
      //## begin CPIWedgeControlProfile%3DB9494E0354.public preserve=yes
      //## end CPIWedgeControlProfile%3DB9494E0354.public

  protected:
    // Additional Protected Declarations
      //## begin CPIWedgeControlProfile%3DB9494E0354.protected preserve=yes
      //## end CPIWedgeControlProfile%3DB9494E0354.protected

  private:
    //## Constructors (generated)
      CPIWedgeControlProfile();

      CPIWedgeControlProfile(const CPIWedgeControlProfile &right);

    //## Destructor (generated)
      virtual ~CPIWedgeControlProfile();

    //## Assignment Operation (generated)
      const CPIWedgeControlProfile & operator=(const CPIWedgeControlProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CPIWedgeControlProfile &right) const;

      bool operator!=(const CPIWedgeControlProfile &right) const;

    // Data Members for Class Attributes

      //## begin CPIWedgeControlProfile::dwScanMode%3FBC8ED501A5.attr preserve=no  public: DWORD {U} p_dwScanMode
      DWORD m_dwScanMode;
      //## end CPIWedgeControlProfile::dwScanMode%3FBC8ED501A5.attr

      //## begin CPIWedgeControlProfile::dwRefDistance2%3E2E73A100F7.attr preserve=no  public: DWORD {U} p_dwRefDistance2
      DWORD m_dwRefDistance2;
      //## end CPIWedgeControlProfile::dwRefDistance2%3E2E73A100F7.attr

    // Additional Private Declarations
      //## begin CPIWedgeControlProfile%3DB9494E0354.private preserve=yes
      //## end CPIWedgeControlProfile%3DB9494E0354.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIWedgeControlProfile%3DB9494E0354.implementation preserve=yes
      //## end CPIWedgeControlProfile%3DB9494E0354.implementation

};

//## begin CPIWedgeControlProfile%3DB9494E0354.postscript preserve=yes
//## end CPIWedgeControlProfile%3DB9494E0354.postscript

//## begin CPIWedgeControlConfig%3DB9495C0095.preface preserve=yes
//## end CPIWedgeControlConfig%3DB9495C0095.preface

//## Class: CPIWedgeControlConfig%3DB9495C0095
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIWedgeControlConfig : public ICORefCounting  //## Inherits: <unnamed>%3DD205EC0239
{
  //## begin CPIWedgeControlConfig%3DB9495C0095.initialDeclarations preserve=yes
  //## end CPIWedgeControlConfig%3DB9495C0095.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIWedgeControlConfig%1043229923
      CPIWedgeControlConfig (DWORD p_dwNomVelocity, DWORD p_dwNomAcc, DWORD p_dwNomDec, DWORD p_dwWedgeControllerVelocityEdge, DWORD p_dwStaticFrictionForward, DWORD p_dwStaticFrictionBackward, DWORD p_dwVelocityWarnHighRange, DWORD p_dwVelocityWarnLowRange, DWORD p_dwVelocityErrorHighRange, DWORD p_dwVelocityErrorLowRange, DWORD p_dwForwardStartDistance, DWORD p_dwForwardEndDistance, DWORD p_dwMeasuringDistance, DWORD p_dwBackwardStartDistance, DWORD p_dwRefDistance1, DWORD p_dwWC_P, DWORD p_dwWC_TN, DWORD p_dwWC_TV, DWORD p_dwWC_Kdac, DWORD p_dwWC_Gain_DAC, DWORD p_dwWC_Offset_DAC, DWORD p_dwDACLimitUp, DWORD p_dwDACLimitDown, DWORD p_dwDACLimitSlewRate, DWORD p_dwRunAfterTime, DWORD p_dwMaxCurrentTime, DWORD p_dwAccStandBy, DWORD p_dwWCIdInitializedEvent, DWORD p_dwWCIdReferencedEvent, DWORD p_dwWCIdStoppedEvent, DWORD p_dwWCIdParkedEvent, DWORD p_dwWCIdCurDirEvent, DWORD p_dwWCLightBarrierEvent, DWORD p_dwWCIdMeasuringExcEvent, DWORD p_dwWCIdCurDirInput);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwNomVelocity%3E36570B0280
      //	UNIT: [Hz]
      const DWORD GetdwNomVelocity () const;
      void SetdwNomVelocity (DWORD value);

      //## Attribute: dwNomAcc%3E36568E0148
      //	UNIT: [m/s^2]
      const DWORD GetdwNomAcc () const;
      void SetdwNomAcc (DWORD value);

      //## Attribute: dwNomDec%3E3656D6029F
      //	UNIT: [m/s^2]
      const DWORD GetdwNomDec () const;
      void SetdwNomDec (DWORD value);

      //## Attribute: dwWedgeControllerVelocityEdge%3FB4A9840138
      //	DESCRIPTION
      //	velocity limit, which the wedge controller switch off
      //
      //	UNIT: [Hz]
      const DWORD GetdwWedgeControllerVelocityEdge () const;
      void SetdwWedgeControllerVelocityEdge (DWORD value);

      //## Attribute: dwStaticFrictionForward%402B97560251
      //	DESCRIPTION
      //	init value to overcome the static friction during the
      //	forward acceleration
      //	(only first acc, and max until Parameter   "p_dwWedge
      //	ControllerVelocityEdge")
      //
      //	UNIT: [DAC Digit]
      const DWORD GetdwStaticFrictionForward () const;
      void SetdwStaticFrictionForward (DWORD value);

      //## Attribute: dwStaticFrictionBackward%402B98E202DE
      //	DESCRIPTION
      //	init value to overcome the static friction during the
      //	forward acceleration
      //	(only first acc, and max until Parameter   "p_dwWedge
      //	ControllerVelocityEdge")
      //
      //	UNIT: [DAC Digit]
      const DWORD GetdwStaticFrictionBackward () const;
      void SetdwStaticFrictionBackward (DWORD value);

      //## Attribute: dwVelocityWarnHighRange%3E2E69C100A9
      //	DESCRIPTION:
      //	Upper warning limit velocity range
      //
      //	UNIT: [Hz]
      const DWORD GetdwVelocityWarnHighRange () const;
      void SetdwVelocityWarnHighRange (DWORD value);

      //## Attribute: dwVelocityWarnLowRange%3E2E6D670117
      //	DESCRIPTION:
      //	Lower warning limit velocity range
      //
      //	UNIT: [Hz]
      const DWORD GetdwVelocityWarnLowRange () const;
      void SetdwVelocityWarnLowRange (DWORD value);

      //## Attribute: dwVelocityErrorHighRange%3E2E6FA80201
      //	DESCRIPTION:
      //	Upper error limit velocity range
      //
      //	UNIT: [Hz]
      const DWORD GetdwVelocityErrorHighRange () const;
      void SetdwVelocityErrorHighRange (DWORD value);

      //## Attribute: dwVelocityErrorLowRange%3E2E708A01F1
      //	DESCRIPTION:
      //	Lower error limit velocity range
      //
      //	UNIT: [Hz]
      const DWORD GetdwVelocityErrorLowRange () const;
      void SetdwVelocityErrorLowRange (DWORD value);

      //## Attribute: dwForwardStartDistance%3E2E720D0136
      //	DESCRIPTION
      //	Distance which is driven off after reaching the nominal
      //	velocity during the measuring mode (forward movement)
      //
      //	UNIT: [Sample Points]
      //	(Distance um / ~12.1um)
      const DWORD GetdwForwardStartDistance () const;
      void SetdwForwardStartDistance (DWORD value);

      //## Attribute: dwForwardEndDistance%3E2E7274024F
      //	DESCRIPTION
      //	Distance which is driven off at the end of the measuring
      //	distance until the wedge drive brakes  (forward movement)
      //
      //	UNIT: [Sample Points]
      //	(Distance um / ~12.1um)
      const DWORD GetdwForwardEndDistance () const;
      void SetdwForwardEndDistance (DWORD value);

      //## Attribute: dwMeasuringDistance%3E2E72A20339
      //	DESCRIPTION
      //	Measuring distance (forward and backward movement)
      //
      //	UNIT: [Sample Points]
      //	(Distance um / ~12.1um)
      const DWORD GetdwMeasuringDistance () const;
      void SetdwMeasuringDistance (DWORD value);

      //## Attribute: dwBackwardStartDistance%3E2E72FE02EB
      //	DESCRIPTION
      //	Distance which is driven off after reaching the nominal
      //	velocity during the measuring mode (backward movement)
      //
      //	UNIT: [Sample Points]
      //	(Distance um / ~12.1um)
      const DWORD GetdwBackwardStartDistance () const;
      void SetdwBackwardStartDistance (DWORD value);

      //## Attribute: dwRefDistance1%3E2E737002DC
      //	DESCRIPTION
      //	Distance which is driven off after leaving the light
      //	barrier during the referencing mode
      //
      //	UNIT: [Sample Points]
      //	(Distance um / ~12.1um)
      const DWORD GetdwRefDistance1 () const;
      void SetdwRefDistance1 (DWORD value);

      //## Attribute: dwWC_P%3E2E73EF005B
      //	DESCRIPTION
      //	P-Factor (PID controller)
      //
      //	UNIT
      //	-
      const DWORD GetdwWC_P () const;
      void SetdwWC_P (DWORD value);

      //## Attribute: dwWC_TN%3E2E741102DC
      //	DESCRIPTION
      //	I-Factor (PID controller) - reset time
      //
      //	UNIT
      //	[us]
      const DWORD GetdwWC_TN () const;
      void SetdwWC_TN (DWORD value);

      //## Attribute: dwWC_TV%3E2E7437009A
      //	DESCRIPTION
      //	D-Factor (PID controller) - ahead time
      //
      //	UNIT
      //	[us]
      const DWORD GetdwWC_TV () const;
      void SetdwWC_TV (DWORD value);

      //## Attribute: dwWC_Kdac%3F9642460177
      //	DESCRIPTION
      //	DAC convertion factor
      //
      //	UNIT
      //	[As^2]
      const DWORD GetdwWC_Kdac () const;
      void SetdwWC_Kdac (DWORD value);

      //## Attribute: dwWC_Gain_DAC%3F9642780242
      //	DESCRIPTION
      //	Gain factor DAC
      //
      //	UNIT
      //	[nA / DAC Digit]
      const DWORD GetdwWC_Gain_DAC () const;
      void SetdwWC_Gain_DAC (DWORD value);

      //## Attribute: dwWC_Offset_DAC%3F9642AF0119
      //	DESCRIPTION
      //	Offset factor DAC
      //
      //	UNIT
      //	[DAC Digit]
      const DWORD GetdwWC_Offset_DAC () const;
      void SetdwWC_Offset_DAC (DWORD value);

      //## Attribute: dwDACLimitUp%3E2E74570174
      //	DESCRIPTION
      //	Upper limit adjusting signal (PID controller output)
      //
      //	UNIT
      //	[DAC Digit]
      const DWORD GetdwDACLimitUp () const;
      void SetdwDACLimitUp (DWORD value);

      //## Attribute: dwDACLimitDown%3E2E748A0397
      //	DESCRIPTION
      //	Lower limit adjusting signal (PID controller output)
      //
      //	UNIT
      //	[DAC Digit]
      const DWORD GetdwDACLimitDown () const;
      void SetdwDACLimitDown (DWORD value);

      //## Attribute: dwDACLimitSlewRate%3F9642CE03A9
      //	DESCRIPTION
      //	Slew Rate Limit DAC
      //
      //	UNIT
      //	[DAC Digit]
      const DWORD GetdwDACLimitSlewRate () const;
      void SetdwDACLimitSlewRate (DWORD value);

      //## Attribute: dwRunAfterTime%3E2E74AD01D2
      //	DESCRIPTION
      //	Time, which the wedge drive drives still after a
      //	measurement
      //
      //	UNIT: [s]
      const DWORD GetdwRunAfterTime () const;
      void SetdwRunAfterTime (DWORD value);

      //## Attribute: dwMaxCurrentTime%402B948E0213
      //	DESCRIPTION
      //	Max.Time, in which the max electric current may be apply
      //	at the wedge drive
      //
      //	UNIT: [ms]
      const DWORD GetdwMaxCurrentTime () const;
      void SetdwMaxCurrentTime (DWORD value);

      //## Attribute: dwAccStandBy%3E53A45700AB
      //	DESCRIPTION
      //	Acceleration, which the wedge drive drives still after a
      //	measurement
      //
      //	UNIT: [Hz/s]
      const DWORD GetdwAccStandBy () const;
      void SetdwAccStandBy (DWORD value);

      //## Attribute: dwWCIdInitializedEvent%3FB4A9CD031C
      //	DESCRIPTION
      //	Event Number Wedge Drive initialized
      const DWORD GetdwWCIdInitializedEvent () const;
      void SetdwWCIdInitializedEvent (DWORD value);

      //## Attribute: dwWCIdReferencedEvent%3FB4A9FD008C
      //	DESCRIPTION
      //	Event Number Wedge Drive referenced
      const DWORD GetdwWCIdReferencedEvent () const;
      void SetdwWCIdReferencedEvent (DWORD value);

      //## Attribute: dwWCIdStoppedEvent%3FB4A9FD030D
      //	DESCRIPTION
      //	Event Number Wedge Drive stopped
      const DWORD GetdwWCIdStoppedEvent () const;
      void SetdwWCIdStoppedEvent (DWORD value);

      //## Attribute: dwWCIdParkedEvent%3FB4A9FE00FA
      //	DESCRIPTION
      //	Event Number Wedge Drive parked
      const DWORD GetdwWCIdParkedEvent () const;
      void SetdwWCIdParkedEvent (DWORD value);

      //## Attribute: dwWCIdCurDirEvent%3FBB74B2037A
      //	DESCRIPTION
      //	Event Number Wedge Drive DAC Current Direction
      const DWORD GetdwWCIdCurDirEvent () const;
      void SetdwWCIdCurDirEvent (DWORD value);

      //## Attribute: dwWCLightBarrierEvent%3FD5A351031C
      //	DESCRIPTION
      //	Event Number Wedge Drive Light Barrier
      const DWORD GetdwWCLightBarrierEvent () const;
      void SetdwWCLightBarrierEvent (DWORD value);

      //## Attribute: dwWCIdMeasuringExcEvent%402B93ED003E
      //	DESCRIPTION
      //	Event Number Wedge Drive Exception
      const DWORD GetdwWCIdMeasuringExcEvent () const;
      void SetdwWCIdMeasuringExcEvent (DWORD value);

      //## Attribute: dwWCIdCurDirInput%3FBCD8E50399
      //	DESCRIPTION
      //	Input Number Wedge Drive DAC Current Direction
      const DWORD GetdwWCIdCurDirInput () const;
      void SetdwWCIdCurDirInput (DWORD value);

    // Additional Public Declarations
      //## begin CPIWedgeControlConfig%3DB9495C0095.public preserve=yes
      //## end CPIWedgeControlConfig%3DB9495C0095.public

  protected:
    // Additional Protected Declarations
      //## begin CPIWedgeControlConfig%3DB9495C0095.protected preserve=yes
      //## end CPIWedgeControlConfig%3DB9495C0095.protected

  private:
    //## Constructors (generated)
      CPIWedgeControlConfig();

      CPIWedgeControlConfig(const CPIWedgeControlConfig &right);

    //## Destructor (generated)
      virtual ~CPIWedgeControlConfig();

    //## Assignment Operation (generated)
      const CPIWedgeControlConfig & operator=(const CPIWedgeControlConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CPIWedgeControlConfig &right) const;

      bool operator!=(const CPIWedgeControlConfig &right) const;

    // Data Members for Class Attributes

      //## begin CPIWedgeControlConfig::dwNomVelocity%3E36570B0280.attr preserve=no  public: DWORD {U} p_dwNomVelocity
      DWORD m_dwNomVelocity;
      //## end CPIWedgeControlConfig::dwNomVelocity%3E36570B0280.attr

      //## begin CPIWedgeControlConfig::dwNomAcc%3E36568E0148.attr preserve=no  public: DWORD {U} p_dwNomAcc
      DWORD m_dwNomAcc;
      //## end CPIWedgeControlConfig::dwNomAcc%3E36568E0148.attr

      //## begin CPIWedgeControlConfig::dwNomDec%3E3656D6029F.attr preserve=no  public: DWORD {U} p_dwNomDec
      DWORD m_dwNomDec;
      //## end CPIWedgeControlConfig::dwNomDec%3E3656D6029F.attr

      //## begin CPIWedgeControlConfig::dwWedgeControllerVelocityEdge%3FB4A9840138.attr preserve=no  public: DWORD {U} p_dwWedgeControllerVelocityEdge
      DWORD m_dwWedgeControllerVelocityEdge;
      //## end CPIWedgeControlConfig::dwWedgeControllerVelocityEdge%3FB4A9840138.attr

      //## begin CPIWedgeControlConfig::dwStaticFrictionForward%402B97560251.attr preserve=no  public: DWORD {U} p_dwStaticFrictionForward
      DWORD m_dwStaticFrictionForward;
      //## end CPIWedgeControlConfig::dwStaticFrictionForward%402B97560251.attr

      //## begin CPIWedgeControlConfig::dwStaticFrictionBackward%402B98E202DE.attr preserve=no  public: DWORD {U} p_dwStaticFrictionBackward
      DWORD m_dwStaticFrictionBackward;
      //## end CPIWedgeControlConfig::dwStaticFrictionBackward%402B98E202DE.attr

      //## begin CPIWedgeControlConfig::dwVelocityWarnHighRange%3E2E69C100A9.attr preserve=no  public: DWORD {U} p_dwVelocityWarnHighRange
      DWORD m_dwVelocityWarnHighRange;
      //## end CPIWedgeControlConfig::dwVelocityWarnHighRange%3E2E69C100A9.attr

      //## begin CPIWedgeControlConfig::dwVelocityWarnLowRange%3E2E6D670117.attr preserve=no  public: DWORD {U} p_dwVelocityWarnLowRange
      DWORD m_dwVelocityWarnLowRange;
      //## end CPIWedgeControlConfig::dwVelocityWarnLowRange%3E2E6D670117.attr

      //## begin CPIWedgeControlConfig::dwVelocityErrorHighRange%3E2E6FA80201.attr preserve=no  public: DWORD {U} p_dwVelocityErrorHighRange
      DWORD m_dwVelocityErrorHighRange;
      //## end CPIWedgeControlConfig::dwVelocityErrorHighRange%3E2E6FA80201.attr

      //## begin CPIWedgeControlConfig::dwVelocityErrorLowRange%3E2E708A01F1.attr preserve=no  public: DWORD {U} p_dwVelocityErrorLowRange
      DWORD m_dwVelocityErrorLowRange;
      //## end CPIWedgeControlConfig::dwVelocityErrorLowRange%3E2E708A01F1.attr

      //## begin CPIWedgeControlConfig::dwForwardStartDistance%3E2E720D0136.attr preserve=no  public: DWORD {U} p_dwForwardStartDistance
      DWORD m_dwForwardStartDistance;
      //## end CPIWedgeControlConfig::dwForwardStartDistance%3E2E720D0136.attr

      //## begin CPIWedgeControlConfig::dwForwardEndDistance%3E2E7274024F.attr preserve=no  public: DWORD {U} p_dwForwardEndDistance
      DWORD m_dwForwardEndDistance;
      //## end CPIWedgeControlConfig::dwForwardEndDistance%3E2E7274024F.attr

      //## begin CPIWedgeControlConfig::dwMeasuringDistance%3E2E72A20339.attr preserve=no  public: DWORD {U} p_dwMeasuringDistance
      DWORD m_dwMeasuringDistance;
      //## end CPIWedgeControlConfig::dwMeasuringDistance%3E2E72A20339.attr

      //## begin CPIWedgeControlConfig::dwBackwardStartDistance%3E2E72FE02EB.attr preserve=no  public: DWORD {U} p_dwBackwardStartDistance
      DWORD m_dwBackwardStartDistance;
      //## end CPIWedgeControlConfig::dwBackwardStartDistance%3E2E72FE02EB.attr

      //## begin CPIWedgeControlConfig::dwRefDistance1%3E2E737002DC.attr preserve=no  public: DWORD {U} p_dwRefDistance1
      DWORD m_dwRefDistance1;
      //## end CPIWedgeControlConfig::dwRefDistance1%3E2E737002DC.attr

      //## begin CPIWedgeControlConfig::dwWC_P%3E2E73EF005B.attr preserve=no  public: DWORD {U} p_dwWC_P
      DWORD m_dwWC_P;
      //## end CPIWedgeControlConfig::dwWC_P%3E2E73EF005B.attr

      //## begin CPIWedgeControlConfig::dwWC_TN%3E2E741102DC.attr preserve=no  public: DWORD {U} p_dwWC_TN
      DWORD m_dwWC_TN;
      //## end CPIWedgeControlConfig::dwWC_TN%3E2E741102DC.attr

      //## begin CPIWedgeControlConfig::dwWC_TV%3E2E7437009A.attr preserve=no  public: DWORD {U} p_dwWC_TV
      DWORD m_dwWC_TV;
      //## end CPIWedgeControlConfig::dwWC_TV%3E2E7437009A.attr

      //## begin CPIWedgeControlConfig::dwWC_Kdac%3F9642460177.attr preserve=no  public: DWORD {U} p_dwWC_Kdac
      DWORD m_dwWC_Kdac;
      //## end CPIWedgeControlConfig::dwWC_Kdac%3F9642460177.attr

      //## begin CPIWedgeControlConfig::dwWC_Gain_DAC%3F9642780242.attr preserve=no  public: DWORD {U} p_dwWC_Gain_DAC
      DWORD m_dwWC_Gain_DAC;
      //## end CPIWedgeControlConfig::dwWC_Gain_DAC%3F9642780242.attr

      //## begin CPIWedgeControlConfig::dwWC_Offset_DAC%3F9642AF0119.attr preserve=no  public: DWORD {U} p_dwWC_Offset_DAC
      DWORD m_dwWC_Offset_DAC;
      //## end CPIWedgeControlConfig::dwWC_Offset_DAC%3F9642AF0119.attr

      //## begin CPIWedgeControlConfig::dwDACLimitUp%3E2E74570174.attr preserve=no  public: DWORD {U} p_dwDACLimitUp
      DWORD m_dwDACLimitUp;
      //## end CPIWedgeControlConfig::dwDACLimitUp%3E2E74570174.attr

      //## begin CPIWedgeControlConfig::dwDACLimitDown%3E2E748A0397.attr preserve=no  public: DWORD {U} p_dwDACLimitDown
      DWORD m_dwDACLimitDown;
      //## end CPIWedgeControlConfig::dwDACLimitDown%3E2E748A0397.attr

      //## begin CPIWedgeControlConfig::dwDACLimitSlewRate%3F9642CE03A9.attr preserve=no  public: DWORD {U} p_dwDACLimitSlewRate
      DWORD m_dwDACLimitSlewRate;
      //## end CPIWedgeControlConfig::dwDACLimitSlewRate%3F9642CE03A9.attr

      //## begin CPIWedgeControlConfig::dwRunAfterTime%3E2E74AD01D2.attr preserve=no  public: DWORD {U} p_dwRunAfterTime
      DWORD m_dwRunAfterTime;
      //## end CPIWedgeControlConfig::dwRunAfterTime%3E2E74AD01D2.attr

      //## begin CPIWedgeControlConfig::dwMaxCurrentTime%402B948E0213.attr preserve=no  public: DWORD {U} p_dwMaxCurrentTime
      DWORD m_dwMaxCurrentTime;
      //## end CPIWedgeControlConfig::dwMaxCurrentTime%402B948E0213.attr

      //## begin CPIWedgeControlConfig::dwAccStandBy%3E53A45700AB.attr preserve=no  public: DWORD {U} p_dwAccStandBy
      DWORD m_dwAccStandBy;
      //## end CPIWedgeControlConfig::dwAccStandBy%3E53A45700AB.attr

      //## begin CPIWedgeControlConfig::dwWCIdInitializedEvent%3FB4A9CD031C.attr preserve=no  public: DWORD {U} p_dwWCIdInitializedEvent
      DWORD m_dwWCIdInitializedEvent;
      //## end CPIWedgeControlConfig::dwWCIdInitializedEvent%3FB4A9CD031C.attr

      //## begin CPIWedgeControlConfig::dwWCIdReferencedEvent%3FB4A9FD008C.attr preserve=no  public: DWORD {U} p_dwWCIdReferencedEvent
      DWORD m_dwWCIdReferencedEvent;
      //## end CPIWedgeControlConfig::dwWCIdReferencedEvent%3FB4A9FD008C.attr

      //## begin CPIWedgeControlConfig::dwWCIdStoppedEvent%3FB4A9FD030D.attr preserve=no  public: DWORD {U} p_dwWCIdStoppedEvent
      DWORD m_dwWCIdStoppedEvent;
      //## end CPIWedgeControlConfig::dwWCIdStoppedEvent%3FB4A9FD030D.attr

      //## begin CPIWedgeControlConfig::dwWCIdParkedEvent%3FB4A9FE00FA.attr preserve=no  public: DWORD {U} p_dwWCIdParkedEvent
      DWORD m_dwWCIdParkedEvent;
      //## end CPIWedgeControlConfig::dwWCIdParkedEvent%3FB4A9FE00FA.attr

      //## begin CPIWedgeControlConfig::dwWCIdCurDirEvent%3FBB74B2037A.attr preserve=no  public: DWORD {U} p_dwWCIdCurDirEvent
      DWORD m_dwWCIdCurDirEvent;
      //## end CPIWedgeControlConfig::dwWCIdCurDirEvent%3FBB74B2037A.attr

      //## begin CPIWedgeControlConfig::dwWCLightBarrierEvent%3FD5A351031C.attr preserve=no  public: DWORD {U} p_dwWCLightBarrierEvent
      DWORD m_dwWCLightBarrierEvent;
      //## end CPIWedgeControlConfig::dwWCLightBarrierEvent%3FD5A351031C.attr

      //## begin CPIWedgeControlConfig::dwWCIdMeasuringExcEvent%402B93ED003E.attr preserve=no  public: DWORD {U} p_dwWCIdMeasuringExcEvent
      DWORD m_dwWCIdMeasuringExcEvent;
      //## end CPIWedgeControlConfig::dwWCIdMeasuringExcEvent%402B93ED003E.attr

      //## begin CPIWedgeControlConfig::dwWCIdCurDirInput%3FBCD8E50399.attr preserve=no  public: DWORD {U} p_dwWCIdCurDirInput
      DWORD m_dwWCIdCurDirInput;
      //## end CPIWedgeControlConfig::dwWCIdCurDirInput%3FBCD8E50399.attr

    // Additional Private Declarations
      //## begin CPIWedgeControlConfig%3DB9495C0095.private preserve=yes
      //## end CPIWedgeControlConfig%3DB9495C0095.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIWedgeControlConfig%3DB9495C0095.implementation preserve=yes
      //## end CPIWedgeControlConfig%3DB9495C0095.implementation

};

//## begin CPIWedgeControlConfig%3DB9495C0095.postscript preserve=yes
//## end CPIWedgeControlConfig%3DB9495C0095.postscript

//## begin CPIMeasurementChannelProfile%3DBCE42E023C.preface preserve=yes
//## end CPIMeasurementChannelProfile%3DBCE42E023C.preface

//## Class: CPIMeasurementChannelProfile%3DBCE42E023C
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIMeasurementChannelProfile : public ICORefCounting  //## Inherits: <unnamed>%3DD201840258
{
  //## begin CPIMeasurementChannelProfile%3DBCE42E023C.initialDeclarations preserve=yes
  //## end CPIMeasurementChannelProfile%3DBCE42E023C.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIMeasurementChannelProfile%1047390943
      CPIMeasurementChannelProfile (DWORD p_dwMinDataSize, DWORD p_dwMaxDataSize, DWORD p_dwStreamBufferSizeInByte = 0);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwMinDataSize%3E6DEA91006D
      //	DESCRIPTION:
      //	min data packgae size for ethernet transfer
      //
      //	UNIT:
      //	Byte
      DWORD GetdwMinDataSize ();

      //## Attribute: dwMaxDataSize%3E6DEA91008C
      //	DESCRIPTION:
      //	min data packgae size for ethernet transfer
      //
      //	UNIT:
      //	Byte
      DWORD GetdwMaxDataSize ();

      //## Attribute: dwStreamBufferSizeInByte%40B5A5E50177
      //	DESCRIPTION:
      //	sets stream buffer size in byte
      //
      //	UNIT:
      //	Byte
      DWORD GetdwStreamBufferSizeInByte ();

    // Additional Public Declarations
      //## begin CPIMeasurementChannelProfile%3DBCE42E023C.public preserve=yes
      //## end CPIMeasurementChannelProfile%3DBCE42E023C.public

  protected:
    // Additional Protected Declarations
      //## begin CPIMeasurementChannelProfile%3DBCE42E023C.protected preserve=yes
      //## end CPIMeasurementChannelProfile%3DBCE42E023C.protected

  private:
    //## Constructors (generated)
      CPIMeasurementChannelProfile();

      CPIMeasurementChannelProfile(const CPIMeasurementChannelProfile &right);

    //## Destructor (generated)
      virtual ~CPIMeasurementChannelProfile();

    //## Assignment Operation (generated)
      const CPIMeasurementChannelProfile & operator=(const CPIMeasurementChannelProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CPIMeasurementChannelProfile &right) const;

      bool operator!=(const CPIMeasurementChannelProfile &right) const;

    // Data Members for Class Attributes

      //## begin CPIMeasurementChannelProfile::dwMinDataSize%3E6DEA91006D.attr preserve=no  public: DWORD {U} p_dwMinDataSize
      DWORD m_dwMinDataSize;
      //## end CPIMeasurementChannelProfile::dwMinDataSize%3E6DEA91006D.attr

      //## begin CPIMeasurementChannelProfile::dwMaxDataSize%3E6DEA91008C.attr preserve=no  public: DWORD {U} p_dwMaxDataSize
      DWORD m_dwMaxDataSize;
      //## end CPIMeasurementChannelProfile::dwMaxDataSize%3E6DEA91008C.attr

      //## begin CPIMeasurementChannelProfile::dwStreamBufferSizeInByte%40B5A5E50177.attr preserve=no  public: DWORD {U} p_dwStreamBufferSizeInByte
      DWORD m_dwStreamBufferSizeInByte;
      //## end CPIMeasurementChannelProfile::dwStreamBufferSizeInByte%40B5A5E50177.attr

    // Additional Private Declarations
      //## begin CPIMeasurementChannelProfile%3DBCE42E023C.private preserve=yes
      //## end CPIMeasurementChannelProfile%3DBCE42E023C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIMeasurementChannelProfile%3DBCE42E023C.implementation preserve=yes
      //## end CPIMeasurementChannelProfile%3DBCE42E023C.implementation

};

//## begin CPIMeasurementChannelProfile%3DBCE42E023C.postscript preserve=yes
//## end CPIMeasurementChannelProfile%3DBCE42E023C.postscript

//## begin CPIPowerControlConfig%3DD410A003E2.preface preserve=yes
//## end CPIPowerControlConfig%3DD410A003E2.preface

//## Class: CPIPowerControlConfig%3DD410A003E2
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F6AA2E1000F;EPILamp { -> }

class EBPI_DLL_DECL CPIPowerControlConfig : public ICORefCounting  //## Inherits: <unnamed>%3DD410B30168
{
  //## begin CPIPowerControlConfig%3DD410A003E2.initialDeclarations preserve=yes
  //## end CPIPowerControlConfig%3DD410A003E2.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIPowerControlConfig%1049124050
      CPIPowerControlConfig (const DWORD p_dwIDActCurrent, const DWORD p_dwIDActVoltage, const DWORD p_dwIDNomVoltage, const DWORD p_dwIDLampSelection, const DWORD p_dwIDLampOnOff, const UINT p_uiPid_Kp, const UINT p_uiPid_Ti, const UINT p_uiPid_Tv, const INT p_iPid_ULimit, const INT p_iPid_LLimit, const UINT p_uiPid_Ts, const UINT p_uiSoftStartDeltaVoltage, const UINT p_uiSoftStartDeltaTime, const UINT p_uiWarmUpTime, const UINT p_uiNominalVoltage, const UINT p_uiNominalVoltageLLimit, const UINT p_uiNominalVoltageULimit, const UINT p_uiNominalVoltageRegisterRange, const UINT p_uiNominalVoltageGain, const INT p_iNominalVoltageOffset, const UINT p_uiVMeteringADCRange, const INT p_iVMeteringADCOffset, const UINT p_uiVMeteringADCVRef, const UINT p_uiVMeteringGain, const UINT p_uiVMeteringSmoothFactor, const UINT p_uiIMeteringADCRange, const INT p_iIMeteringADCOffset, const UINT p_uiIMeteringADCVRef, const UINT p_uiIMeteringGain, const UINT p_uiIMeteringRShunt, const UINT p_uiIMeteringSmoothFactor, const UINT p_uiMaxSettlingTime, const UINT p_uiDeltaOszillationLimit, EPILamp p_eActiveLamp);

    //## Destructor (generated)
      virtual ~CPIPowerControlConfig();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwIDActCurrent%3F0D6A8303B0
      //	DESCRIPTION:
      //	Corresponding identification (ID) to read current from
      //	the hardware interface (HI).
      //
      //	UNIT: [-]
      DWORD GetdwIDActCurrent ();

      //## Attribute: dwIDActVoltage%3F0D69D20352
      //	DESCRIPTION:
      //	Corresponding identification (ID) to read voltage from
      //	the hardware interface (HI).
      //
      //	UNIT: [-]
      DWORD GetdwIDActVoltage ();

      //## Attribute: dwIDNomVoltage%3F0D6B0801DB
      //	DESCRIPTION:
      //	Corresponding identification (ID) to set voltage on the
      //	hardware interface (HI).
      //
      //	UNIT: [-]
      DWORD GetdwIDNomVoltage ();

      //## Attribute: dwIDLampSelection%3F6A92640157
      //	DESCRIPTION:
      //	Corresponding identification (ID) to set the lamp
      //	selection on the hardware interface (HI).
      //
      //	UNIT: [-]
      DWORD GetdwIDLampSelection ();

      //## Attribute: dwIDLampOnOff%3F6A929E02AF
      //	DESCRIPTION:
      //	Corresponding identification (ID) to switch the lamp
      //	on/off on the hardware interface (HI).
      //
      //	UNIT: [-]
      DWORD GetdwIDLampOnOff ();

      //## Attribute: uiPid_Kp%3E896204000F
      //	DESCRIPTION:
      //	P-Factor (PID controller).
      //
      //	UNIT: [10^-3]
      UINT GetuiPid_Kp ();

      //## Attribute: uiPid_Ti%3E8962060000
      //	DESCRIPTION:
      //	I-Factor (PID controller).
      //
      //	UNIT: [10^-3]
      UINT GetuiPid_Ti ();

      //## Attribute: uiPid_Tv%3E89620C034B
      //	DESCRIPTION:
      //	D-Factor (PID controller).
      //
      //	UNIT: [10^-3]
      UINT GetuiPid_Tv ();

      //## Attribute: iPid_ULimit%3E89620F001F
      //	DESCRIPTION:
      //	Upper limit adjusting signal (PID controller output).
      //
      //	UNIT: [W * 10^-3]
      INT GetiPid_ULimit ();

      //## Attribute: iPid_LLimit%3E896211009C
      //	DESCRIPTION:
      //	Lower limit adjusting signal (PID controller output).
      //
      //	UNIT: [W * 10^-3]
      INT GetiPid_LLimit ();

      //## Attribute: uiPid_Ts%3E896212036B
      //	DESCRIPTION:
      //	Sampling Time.
      //
      //	UNIT: [s * 10^-3]
      UINT GetuiPid_Ts ();

      //## Attribute: uiSoftStartDeltaVoltage%3F0D6B3401EB
      //	DESCRIPTION:
      //	Softstart: Voltage to increment in dwDeltaTimeSoftStart
      //
      //	UNIT: [V * 10^-3]
      UINT GetuiSoftStartDeltaVoltage ();

      //## Attribute: uiSoftStartDeltaTime%3F0D6B590064
      //	DESCRIPTION:
      //	Softstart: (dwDeltaVoltageSoftStart) is added to voltage
      //	output in (dwDeltaTimeSoftStart) time fragments
      //
      //	UNIT: [s * 10^-3]
      UINT GetuiSoftStartDeltaTime ();

      //## Attribute: uiWarmUpTime%4018C8DB000F
      //	DESCRIPTION:
      //	Lamp is switched on with "nominal voltage lower limit".
      //	After WarmUpTime the voltage is increased to nominal
      //	voltage.
      //
      //	UNIT: [V * 10^-3]
      UINT GetuiWarmUpTime ();

      //## Attribute: uiNominalVoltage%3F0D6C0D013F
      //	DESCRIPTION:
      //	Device operating voltage. Nominal Voltage.
      //
      //	UNIT: [V * 10^-3]
      UINT GetuiNominalVoltage ();

      //## Attribute: uiNominalVoltageLLimit%40177EEE0232
      //	DESCRIPTION:
      //	Nominal voltage lower limit.
      //
      //	UNIT: [V * 10^-3]
      UINT GetuiNominalVoltageLLimit ();

      //## Attribute: uiNominalVoltageULimit%40177EF4004E
      //	DESCRIPTION:
      //	Nominal voltage upper limit.
      //
      //	UNIT: [V * 10^-3]
      UINT GetuiNominalVoltageULimit ();

      //## Attribute: uiNominalVoltageRegisterRange%40178C3701F4
      //	DESCRIPTION:
      //	Converting voltage to register digits. This is the
      //	offset. Value is in digits.
      //
      //	UNIT: []
      UINT GetuiNominalVoltageRegisterRange ();

      //## Attribute: uiNominalVoltageGain%4017800E0177
      //	DESCRIPTION:
      //	Converting voltage to register digits. This is its gain.
      //
      //	UNIT: [10^-3]
      UINT GetuiNominalVoltageGain ();

      //## Attribute: iNominalVoltageOffset%401780AD00EA
      //	DESCRIPTION:
      //	Converting voltage to register digits. This is the
      //	offset. Value is in digits.
      //
      //	UNIT: []
      INT GetiNominalVoltageOffset ();

      //## Attribute: uiVMeteringADCRange%3F0D6BC300E1
      //	DESCRIPTION:
      //	Resolution: Analog digital converter constant. e.g. 12
      //	Bits --> 4096
      //
      //	UNIT: [-]
      UINT GetuiVMeteringADCRange ();

      //## Attribute: iVMeteringADCOffset%3F0E728B0181
      //	DESCRIPTION:
      //	Hardware offset in the voltage measurement. Value in
      //	digits of the ADC.
      //
      //	UNIT: [-]
      INT GetiVMeteringADCOffset ();

      //## Attribute: uiVMeteringADCVRef%40177F710232
      //	DESCRIPTION:
      //	Reference voltage in the voltage measurement.
      //
      //	UNIT: [V * 10^-3]
      UINT GetuiVMeteringADCVRef ();

      //## Attribute: uiVMeteringGain%3F0E865002F8
      //	DESCRIPTION:
      //	Hardware circuit gain.
      //
      //	UNIT: [V * 10^-6]
      UINT GetuiVMeteringGain ();

      //## Attribute: uiVMeteringSmoothFactor%401931F80280
      //	DESCRIPTION:
      //	Smooth factor to eliminate jitting from the ADC.
      //
      //	UNIT: [-]
      UINT GetuiVMeteringSmoothFactor ();

      //## Attribute: uiIMeteringADCRange%3F12B46C0140
      //	DESCRIPTION:
      //	Resolution: Analog digital converter constant. e.g. 12
      //	Bits --> 4096
      //
      //	UNIT: [-]
      UINT GetuiIMeteringADCRange ();

      //## Attribute: iIMeteringADCOffset%3F0E7D880048
      //	DESCRIPTION:
      //	Hardware offset in the current measurement. Value is in
      //	digits.
      //
      //	UNIT: []
      INT GetiIMeteringADCOffset ();

      //## Attribute: uiIMeteringADCVRef%401782B803A9
      //	DESCRIPTION:
      //	Reference voltage of the ADC.
      //
      //	UNIT: [V *10^-3]
      UINT GetuiIMeteringADCVRef ();

      //## Attribute: uiIMeteringGain%3F0E81E3000A
      //	DESCRIPTION:
      //	Hardware circuit gain.
      //
      //	UNIT: []
      UINT GetuiIMeteringGain ();

      //## Attribute: uiIMeteringRShunt%3F6A90B00000
      //	DESCRIPTION:
      //	Shunt resistor to measure the voltage.
      //
      //	UNIT: [Ohm * 10^-3]
      UINT GetuiIMeteringRShunt ();

      //## Attribute: uiIMeteringSmoothFactor%401933FA004E
      //	DESCRIPTION:
      //	Smooth factor to eliminate jitting from the ADC.
      //
      //	UNIT: [-]
      UINT GetuiIMeteringSmoothFactor ();

      //## Attribute: uiMaxSettlingTime%403F22B100FA
      //	DESCRIPTION:
      //	Lamp start. If oszillation PID is not finished after
      //	this time. An exception is generated.
      //
      //	UNIT: [ms]
      UINT GetuiMaxSettlingTime ();

      //## Attribute: uiDeltaOszillationLimit%403F22B300FA
      //	DESCRIPTION:
      //	Oszillation limit in per mil of the nominal power value.
      //
      //	UNIT: [per mil]
      UINT GetuiDeltaOszillationLimit ();

      //## Attribute: eActiveLamp%3F6A92FF03C8
      //	DESCRIPTION:
      //	Active lamp. Primary or secondary.
      //
      //	UNIT: [-]
      EPILamp GeteActiveLamp ();

    // Additional Public Declarations
      //## begin CPIPowerControlConfig%3DD410A003E2.public preserve=yes
      //## end CPIPowerControlConfig%3DD410A003E2.public

  protected:
    // Additional Protected Declarations
      //## begin CPIPowerControlConfig%3DD410A003E2.protected preserve=yes
      //## end CPIPowerControlConfig%3DD410A003E2.protected

  private:
    //## Constructors (generated)
      CPIPowerControlConfig();

      CPIPowerControlConfig(const CPIPowerControlConfig &right);

    //## Assignment Operation (generated)
      const CPIPowerControlConfig & operator=(const CPIPowerControlConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CPIPowerControlConfig &right) const;

      bool operator!=(const CPIPowerControlConfig &right) const;

    // Data Members for Class Attributes

      //## begin CPIPowerControlConfig::dwIDActCurrent%3F0D6A8303B0.attr preserve=no  public: DWORD {U} p_dwIDActCurrent
      DWORD m_dwIDActCurrent;
      //## end CPIPowerControlConfig::dwIDActCurrent%3F0D6A8303B0.attr

      //## begin CPIPowerControlConfig::dwIDActVoltage%3F0D69D20352.attr preserve=no  public: DWORD {U} p_dwIDActVoltage
      DWORD m_dwIDActVoltage;
      //## end CPIPowerControlConfig::dwIDActVoltage%3F0D69D20352.attr

      //## begin CPIPowerControlConfig::dwIDNomVoltage%3F0D6B0801DB.attr preserve=no  public: DWORD {U} p_dwIDNomVoltage
      DWORD m_dwIDNomVoltage;
      //## end CPIPowerControlConfig::dwIDNomVoltage%3F0D6B0801DB.attr

      //## begin CPIPowerControlConfig::dwIDLampSelection%3F6A92640157.attr preserve=no  public: DWORD {U} p_dwIDLampSelection
      DWORD m_dwIDLampSelection;
      //## end CPIPowerControlConfig::dwIDLampSelection%3F6A92640157.attr

      //## begin CPIPowerControlConfig::dwIDLampOnOff%3F6A929E02AF.attr preserve=no  public: DWORD {U} p_dwIDLampOnOff
      DWORD m_dwIDLampOnOff;
      //## end CPIPowerControlConfig::dwIDLampOnOff%3F6A929E02AF.attr

      //## begin CPIPowerControlConfig::uiPid_Kp%3E896204000F.attr preserve=no  public: UINT {U} p_uiPid_Kp
      UINT m_uiPid_Kp;
      //## end CPIPowerControlConfig::uiPid_Kp%3E896204000F.attr

      //## begin CPIPowerControlConfig::uiPid_Ti%3E8962060000.attr preserve=no  public: UINT {U} p_uiPid_Ti
      UINT m_uiPid_Ti;
      //## end CPIPowerControlConfig::uiPid_Ti%3E8962060000.attr

      //## begin CPIPowerControlConfig::uiPid_Tv%3E89620C034B.attr preserve=no  public: UINT {U} p_uiPid_Tv
      UINT m_uiPid_Tv;
      //## end CPIPowerControlConfig::uiPid_Tv%3E89620C034B.attr

      //## begin CPIPowerControlConfig::iPid_ULimit%3E89620F001F.attr preserve=no  public: INT {U} p_iPid_ULimit
      INT m_iPid_ULimit;
      //## end CPIPowerControlConfig::iPid_ULimit%3E89620F001F.attr

      //## begin CPIPowerControlConfig::iPid_LLimit%3E896211009C.attr preserve=no  public: INT {U} p_iPid_LLimit
      INT m_iPid_LLimit;
      //## end CPIPowerControlConfig::iPid_LLimit%3E896211009C.attr

      //## begin CPIPowerControlConfig::uiPid_Ts%3E896212036B.attr preserve=no  public: UINT {U} p_uiPid_Ts
      UINT m_uiPid_Ts;
      //## end CPIPowerControlConfig::uiPid_Ts%3E896212036B.attr

      //## begin CPIPowerControlConfig::uiSoftStartDeltaVoltage%3F0D6B3401EB.attr preserve=no  public: UINT {U} p_uiSoftStartDeltaVoltage
      UINT m_uiSoftStartDeltaVoltage;
      //## end CPIPowerControlConfig::uiSoftStartDeltaVoltage%3F0D6B3401EB.attr

      //## begin CPIPowerControlConfig::uiSoftStartDeltaTime%3F0D6B590064.attr preserve=no  public: UINT {U} p_uiSoftStartDeltaTime
      UINT m_uiSoftStartDeltaTime;
      //## end CPIPowerControlConfig::uiSoftStartDeltaTime%3F0D6B590064.attr

      //## begin CPIPowerControlConfig::uiWarmUpTime%4018C8DB000F.attr preserve=no  public: UINT {U} p_uiWarmUpTime
      UINT m_uiWarmUpTime;
      //## end CPIPowerControlConfig::uiWarmUpTime%4018C8DB000F.attr

      //## begin CPIPowerControlConfig::uiNominalVoltage%3F0D6C0D013F.attr preserve=no  public: UINT {U} p_uiNominalVoltage
      UINT m_uiNominalVoltage;
      //## end CPIPowerControlConfig::uiNominalVoltage%3F0D6C0D013F.attr

      //## begin CPIPowerControlConfig::uiNominalVoltageLLimit%40177EEE0232.attr preserve=no  public: UINT {U} p_uiNominalVoltageLLimit
      UINT m_uiNominalVoltageLLimit;
      //## end CPIPowerControlConfig::uiNominalVoltageLLimit%40177EEE0232.attr

      //## begin CPIPowerControlConfig::uiNominalVoltageULimit%40177EF4004E.attr preserve=no  public: UINT {U} p_uiNominalVoltageULimit
      UINT m_uiNominalVoltageULimit;
      //## end CPIPowerControlConfig::uiNominalVoltageULimit%40177EF4004E.attr

      //## begin CPIPowerControlConfig::uiNominalVoltageRegisterRange%40178C3701F4.attr preserve=no  public: UINT {U} p_uiNominalVoltageRegisterRange
      UINT m_uiNominalVoltageRegisterRange;
      //## end CPIPowerControlConfig::uiNominalVoltageRegisterRange%40178C3701F4.attr

      //## begin CPIPowerControlConfig::uiNominalVoltageGain%4017800E0177.attr preserve=no  public: UINT {U} p_uiNominalVoltageGain
      UINT m_uiNominalVoltageGain;
      //## end CPIPowerControlConfig::uiNominalVoltageGain%4017800E0177.attr

      //## begin CPIPowerControlConfig::iNominalVoltageOffset%401780AD00EA.attr preserve=no  public: INT {U} p_iNominalVoltageOffset
      INT m_iNominalVoltageOffset;
      //## end CPIPowerControlConfig::iNominalVoltageOffset%401780AD00EA.attr

      //## begin CPIPowerControlConfig::uiVMeteringADCRange%3F0D6BC300E1.attr preserve=no  public: UINT {U} p_uiVMeteringADCRange
      UINT m_uiVMeteringADCRange;
      //## end CPIPowerControlConfig::uiVMeteringADCRange%3F0D6BC300E1.attr

      //## begin CPIPowerControlConfig::iVMeteringADCOffset%3F0E728B0181.attr preserve=no  public: INT {U} p_iVMeteringADCOffset
      INT m_iVMeteringADCOffset;
      //## end CPIPowerControlConfig::iVMeteringADCOffset%3F0E728B0181.attr

      //## begin CPIPowerControlConfig::uiVMeteringADCVRef%40177F710232.attr preserve=no  public: UINT {U} p_uiVMeteringADCVRef
      UINT m_uiVMeteringADCVRef;
      //## end CPIPowerControlConfig::uiVMeteringADCVRef%40177F710232.attr

      //## begin CPIPowerControlConfig::uiVMeteringGain%3F0E865002F8.attr preserve=no  public: UINT {U} p_uiVMeteringGain
      UINT m_uiVMeteringGain;
      //## end CPIPowerControlConfig::uiVMeteringGain%3F0E865002F8.attr

      //## begin CPIPowerControlConfig::uiVMeteringSmoothFactor%401931F80280.attr preserve=no  public: UINT {U} p_uiVMeteringSmoothFactor
      UINT m_uiVMeteringSmoothFactor;
      //## end CPIPowerControlConfig::uiVMeteringSmoothFactor%401931F80280.attr

      //## begin CPIPowerControlConfig::uiIMeteringADCRange%3F12B46C0140.attr preserve=no  public: UINT {U} p_uiIMeteringADCRange
      UINT m_uiIMeteringADCRange;
      //## end CPIPowerControlConfig::uiIMeteringADCRange%3F12B46C0140.attr

      //## begin CPIPowerControlConfig::iIMeteringADCOffset%3F0E7D880048.attr preserve=no  public: INT {U} p_iIMeteringADCOffset
      INT m_iIMeteringADCOffset;
      //## end CPIPowerControlConfig::iIMeteringADCOffset%3F0E7D880048.attr

      //## begin CPIPowerControlConfig::uiIMeteringADCVRef%401782B803A9.attr preserve=no  public: UINT {U} p_uiIMeteringADCVRef
      UINT m_uiIMeteringADCVRef;
      //## end CPIPowerControlConfig::uiIMeteringADCVRef%401782B803A9.attr

      //## begin CPIPowerControlConfig::uiIMeteringGain%3F0E81E3000A.attr preserve=no  public: UINT {U} p_uiIMeteringGain
      UINT m_uiIMeteringGain;
      //## end CPIPowerControlConfig::uiIMeteringGain%3F0E81E3000A.attr

      //## begin CPIPowerControlConfig::uiIMeteringRShunt%3F6A90B00000.attr preserve=no  public: UINT {U} p_uiIMeteringRShunt
      UINT m_uiIMeteringRShunt;
      //## end CPIPowerControlConfig::uiIMeteringRShunt%3F6A90B00000.attr

      //## begin CPIPowerControlConfig::uiIMeteringSmoothFactor%401933FA004E.attr preserve=no  public: UINT {U} p_uiIMeteringSmoothFactor
      UINT m_uiIMeteringSmoothFactor;
      //## end CPIPowerControlConfig::uiIMeteringSmoothFactor%401933FA004E.attr

      //## begin CPIPowerControlConfig::uiMaxSettlingTime%403F22B100FA.attr preserve=no  public: UINT {U} p_uiMaxSettlingTime
      UINT m_uiMaxSettlingTime;
      //## end CPIPowerControlConfig::uiMaxSettlingTime%403F22B100FA.attr

      //## begin CPIPowerControlConfig::uiDeltaOszillationLimit%403F22B300FA.attr preserve=no  public: UINT {U} p_uiDeltaOszillationLimit
      UINT m_uiDeltaOszillationLimit;
      //## end CPIPowerControlConfig::uiDeltaOszillationLimit%403F22B300FA.attr

      //## begin CPIPowerControlConfig::eActiveLamp%3F6A92FF03C8.attr preserve=no  public: EPILamp {U} p_eActiveLamp
      EPILamp m_eActiveLamp;
      //## end CPIPowerControlConfig::eActiveLamp%3F6A92FF03C8.attr

    // Additional Private Declarations
      //## begin CPIPowerControlConfig%3DD410A003E2.private preserve=yes
      //## end CPIPowerControlConfig%3DD410A003E2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIPowerControlConfig%3DD410A003E2.implementation preserve=yes
      //## end CPIPowerControlConfig%3DD410A003E2.implementation

};

//## begin CPIPowerControlConfig%3DD410A003E2.postscript preserve=yes
//## end CPIPowerControlConfig%3DD410A003E2.postscript

//## begin CPIPersistentItemList%3DF6090302A7.preface preserve=yes
//## end CPIPersistentItemList%3DF6090302A7.preface

//## Class: CPIPersistentItemList%3DF6090302A7
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIPersistentItemList : public ICORefCounting  //## Inherits: <unnamed>%3FF9267F0186
{
  //## begin CPIPersistentItemList%3DF6090302A7.initialDeclarations preserve=yes
  //## end CPIPersistentItemList%3DF6090302A7.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIPersistentItemList%1066980584
      CPIPersistentItemList (const CTypedPtrList<CPtrList, CPIPersistentItem*>& p_Items);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPI (PC Interface)::<unnamed>%3F93E08901DB
      //## Role: CPIPersistentItemList::Items%3F93E08903A0
      CTypedPtrList<CPtrList, CPIPersistentItem*>& GetItems ();

    // Additional Public Declarations
      //## begin CPIPersistentItemList%3DF6090302A7.public preserve=yes
      //## end CPIPersistentItemList%3DF6090302A7.public

  protected:
    // Additional Protected Declarations
      //## begin CPIPersistentItemList%3DF6090302A7.protected preserve=yes
      //## end CPIPersistentItemList%3DF6090302A7.protected

  private:
    //## Constructors (generated)
      CPIPersistentItemList();

      CPIPersistentItemList(const CPIPersistentItemList &right);

    //## Destructor (generated)
      virtual ~CPIPersistentItemList();

    //## Assignment Operation (generated)
      const CPIPersistentItemList & operator=(const CPIPersistentItemList &right);

    //## Equality Operations (generated)
      bool operator==(const CPIPersistentItemList &right) const;

      bool operator!=(const CPIPersistentItemList &right) const;

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%3F93E08901DB
      //## begin CPIPersistentItemList::Items%3F93E08903A0.role preserve=no  public: CPIPersistentItem {1 -> nRFHN}
      CTypedPtrList<CPtrList, CPIPersistentItem*> m_Items;
      //## end CPIPersistentItemList::Items%3F93E08903A0.role

    // Additional Private Declarations
      //## begin CPIPersistentItemList%3DF6090302A7.private preserve=yes
      //## end CPIPersistentItemList%3DF6090302A7.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIPersistentItemList%3DF6090302A7.implementation preserve=yes
      //## end CPIPersistentItemList%3DF6090302A7.implementation

};

//## begin CPIPersistentItemList%3DF6090302A7.postscript preserve=yes
//## end CPIPersistentItemList%3DF6090302A7.postscript

//## begin CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.preface preserve=yes
//## end CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.preface

//## Class: CPIPersistentSoftwareComponentVersionList%3DF60AA3020B
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIPersistentSoftwareComponentVersionList : public ICORefCounting  //## Inherits: <unnamed>%3DF60AD602B7
{
  //## begin CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.initialDeclarations preserve=yes
  //## end CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIPersistentSoftwareComponentVersionList%1039528824
      CPIPersistentSoftwareComponentVersionList (const CTypedPtrList<CPtrList, CPIPersistentSoftwareComponentVersion*>& p_ComponentVersions);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPI (PC Interface)::<unnamed>%3DF60AE602E6
      //## Role: CPIPersistentSoftwareComponentVersionList::ComponentVersions%3DF60AE7016F
      CTypedPtrList<CPtrList, CPIPersistentSoftwareComponentVersion*>& GetComponentVersions ();

    // Additional Public Declarations
      //## begin CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.public preserve=yes
      //## end CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.public

  protected:
    // Additional Protected Declarations
      //## begin CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.protected preserve=yes
      //## end CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.protected

  private:
    //## Constructors (generated)
      CPIPersistentSoftwareComponentVersionList();

      CPIPersistentSoftwareComponentVersionList(const CPIPersistentSoftwareComponentVersionList &right);

    //## Destructor (generated)
      virtual ~CPIPersistentSoftwareComponentVersionList();

    //## Assignment Operation (generated)
      const CPIPersistentSoftwareComponentVersionList & operator=(const CPIPersistentSoftwareComponentVersionList &right);

    //## Equality Operations (generated)
      bool operator==(const CPIPersistentSoftwareComponentVersionList &right) const;

      bool operator!=(const CPIPersistentSoftwareComponentVersionList &right) const;

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%3DF60AE602E6
      //## begin CPIPersistentSoftwareComponentVersionList::ComponentVersions%3DF60AE7016F.role preserve=no  public: CPIPersistentSoftwareComponentVersion {1 -> *RFHN}
      CTypedPtrList<CPtrList, CPIPersistentSoftwareComponentVersion*> m_ComponentVersions;
      //## end CPIPersistentSoftwareComponentVersionList::ComponentVersions%3DF60AE7016F.role

    // Additional Private Declarations
      //## begin CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.private preserve=yes
      //## end CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.implementation preserve=yes
      //## end CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.implementation

};

//## begin CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.postscript preserve=yes
//## end CPIPersistentSoftwareComponentVersionList%3DF60AA3020B.postscript

//## begin CPISyncObjListSWCompVersion%3DEDCB510249.preface preserve=yes
//## end CPISyncObjListSWCompVersion%3DEDCB510249.preface

//## Class: CPISyncObjListSWCompVersion%3DEDCB510249; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DEDCC8F0074;CPIPersistentSoftwareComponentVersionList { -> }

typedef CCOSyncObjectParameterizedByRef< CPIPersistentSoftwareComponentVersionList* > CPISyncObjListSWCompVersion;

//## begin CPISyncObjListSWCompVersion%3DEDCB510249.postscript preserve=yes
//## end CPISyncObjListSWCompVersion%3DEDCB510249.postscript

//## begin CPIPersistentSoftwareComponentList%3DF60C110343.preface preserve=yes
//## end CPIPersistentSoftwareComponentList%3DF60C110343.preface

//## Class: CPIPersistentSoftwareComponentList%3DF60C110343
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIPersistentSoftwareComponentList : public ICORefCounting  //## Inherits: <unnamed>%3DF60C260382
{
  //## begin CPIPersistentSoftwareComponentList%3DF60C110343.initialDeclarations preserve=yes
  //## end CPIPersistentSoftwareComponentList%3DF60C110343.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIPersistentSoftwareComponentList%1039528825
      CPIPersistentSoftwareComponentList (const CTypedPtrList<CPtrList, CPIPersistentSoftwareComponent*>& p_Components);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPI (PC Interface)::<unnamed>%3DF60C2C0372
      //## Role: CPIPersistentSoftwareComponentList::Components%3DF60C2D0344
      CTypedPtrList<CPtrList, CPIPersistentSoftwareComponent*>& GetComponents ();

    // Additional Public Declarations
      //## begin CPIPersistentSoftwareComponentList%3DF60C110343.public preserve=yes
      //## end CPIPersistentSoftwareComponentList%3DF60C110343.public

  protected:
    // Additional Protected Declarations
      //## begin CPIPersistentSoftwareComponentList%3DF60C110343.protected preserve=yes
      //## end CPIPersistentSoftwareComponentList%3DF60C110343.protected

  private:
    //## Constructors (generated)
      CPIPersistentSoftwareComponentList();

      CPIPersistentSoftwareComponentList(const CPIPersistentSoftwareComponentList &right);

    //## Destructor (generated)
      virtual ~CPIPersistentSoftwareComponentList();

    //## Assignment Operation (generated)
      const CPIPersistentSoftwareComponentList & operator=(const CPIPersistentSoftwareComponentList &right);

    //## Equality Operations (generated)
      bool operator==(const CPIPersistentSoftwareComponentList &right) const;

      bool operator!=(const CPIPersistentSoftwareComponentList &right) const;

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%3DF60C2C0372
      //## begin CPIPersistentSoftwareComponentList::Components%3DF60C2D0344.role preserve=no  public: CPIPersistentSoftwareComponent {1 -> *RFHN}
      CTypedPtrList<CPtrList, CPIPersistentSoftwareComponent*> m_Components;
      //## end CPIPersistentSoftwareComponentList::Components%3DF60C2D0344.role

    // Additional Private Declarations
      //## begin CPIPersistentSoftwareComponentList%3DF60C110343.private preserve=yes
      //## end CPIPersistentSoftwareComponentList%3DF60C110343.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIPersistentSoftwareComponentList%3DF60C110343.implementation preserve=yes
      //## end CPIPersistentSoftwareComponentList%3DF60C110343.implementation

};

//## begin CPIPersistentSoftwareComponentList%3DF60C110343.postscript preserve=yes
//## end CPIPersistentSoftwareComponentList%3DF60C110343.postscript

//## begin CPIStepperMotorConfig%3E70582C0280.preface preserve=yes
//## end CPIStepperMotorConfig%3E70582C0280.preface

//## Class: CPIStepperMotorConfig%3E70582C0280
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIStepperMotorConfig : public ICORefCounting  //## Inherits: <unnamed>%3E7058470213
{
  //## begin CPIStepperMotorConfig%3E70582C0280.initialDeclarations preserve=yes
  //## end CPIStepperMotorConfig%3E70582C0280.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIStepperMotorConfig%1047636419
      CPIStepperMotorConfig (const DWORD p_dwAxisPlay, const DWORD p_dwHomingTimeout, const DWORD p_dwIDMovingTerminationEvent, const UINT p_uiSamplingTime, const DWORD p_dwIDStepValid, const DWORD p_dwIDVelValid, const DWORD p_dwIDStep, const DWORD p_dwIDVelocity, const DWORD p_dwIDActualPos,  const DWORD p_dwIDActualDirection, const DWORD p_dwIDDirection,  const DWORD p_dwIDRestartValid);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwAxisPlay%434F757B03CB
      //	DESCRIPTION:
      //	Number of steps of the mechanical play of the axis
      DWORD GetdwAxisPlay ();

      //## Attribute: dwHomingTimeout%434F766B014F
      //	DESCRIPTION
      //	Time in [ms] which the stepper spends on searching the
      //	limit sensor
      DWORD GetdwHomingTimeout ();

      //## Attribute: dwIDMovingTerminationEvent%3E70A2E10138
      //	DESCRIPTION:
      //	Logical ID for the moving termination event.
      //
      //	UNIT: [-]
      DWORD GetdwIDMovingTerminationEvent ();

      //## Attribute: uiSamplingTime%3E8AF8060032
      //	[ms] The speed is increased or decreased in sampling
      //	time gaps.
      UINT GetuiSamplingTime ();

      //## Attribute: dwIDStepValid%3F4469B70291
      //	[-] Corresponding logical identification (ID) to write
      //	the the step valid bit into the hardware register.
      DWORD GetdwIDStepValid ();

      //## Attribute: dwIDVelValid%3F446A2102D0
      //	[-] Corresponding logical identification (ID) to write
      //	the the velocity valid bit into the hardware register.
      DWORD GetdwIDVelValid ();

      //## Attribute: dwIDStep%3F446A3900AD
      //	[-] Corresponding logical identification (ID) to write
      //	the the step into the hardware register.
      DWORD GetdwIDStep ();

      //## Attribute: dwIDVelocity%3F446A8D005F
      //	[-] Corresponding logical identification (ID) to write
      //	the the velocity into the hardware register.
      DWORD GetdwIDVelocity ();

      //## Attribute: dwIDActualPos%3F446AB00253
      //	[-] Corresponding logical identification (ID) to get the
      //	the actual position from the hardware.
      DWORD GetdwIDActualPos ();

      //## Attribute: dwIDActualDirection%3F446ACC038B
      //	[-] Corresponding logical identification (ID) to get the
      //	the actual motor direction from the hardware.
      DWORD GetdwIDActualDirection ();

      //## Attribute: dwIDDirection%3F446A55030E
      //	[-] Corresponding logical identification (ID) to set the
      //	the motor direction into the hardware register.
      DWORD GetdwIDDirection ();

      //## Attribute: dwIDRestartValid%3F56FD90032C
      //	[-] Steps AND speed will be updated in the hardware
      DWORD GetdwIDRestartValid ();

    // Additional Public Declarations
      //## begin CPIStepperMotorConfig%3E70582C0280.public preserve=yes
      //## end CPIStepperMotorConfig%3E70582C0280.public

  protected:
    // Additional Protected Declarations
      //## begin CPIStepperMotorConfig%3E70582C0280.protected preserve=yes
      //## end CPIStepperMotorConfig%3E70582C0280.protected

  private:
    //## Constructors (generated)
      CPIStepperMotorConfig();

      CPIStepperMotorConfig(const CPIStepperMotorConfig &right);

    //## Destructor (generated)
      virtual ~CPIStepperMotorConfig();

    //## Assignment Operation (generated)
      const CPIStepperMotorConfig & operator=(const CPIStepperMotorConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CPIStepperMotorConfig &right) const;

      bool operator!=(const CPIStepperMotorConfig &right) const;

    // Data Members for Class Attributes

      //## begin CPIStepperMotorConfig::dwAxisPlay%434F757B03CB.attr preserve=no  public: DWORD {U} p_dwAxisPlay
      DWORD m_dwAxisPlay;
      //## end CPIStepperMotorConfig::dwAxisPlay%434F757B03CB.attr

      //## begin CPIStepperMotorConfig::dwHomingTimeout%434F766B014F.attr preserve=no  public: DWORD {U} p_dwHomingTimeout
      DWORD m_dwHomingTimeout;
      //## end CPIStepperMotorConfig::dwHomingTimeout%434F766B014F.attr

      //## begin CPIStepperMotorConfig::dwIDMovingTerminationEvent%3E70A2E10138.attr preserve=no  public: DWORD {U} p_dwIDMovingTerminationEvent
      DWORD m_dwIDMovingTerminationEvent;
      //## end CPIStepperMotorConfig::dwIDMovingTerminationEvent%3E70A2E10138.attr

      //## begin CPIStepperMotorConfig::uiSamplingTime%3E8AF8060032.attr preserve=no  public: UINT {U} p_uiSamplingTime
      UINT m_uiSamplingTime;
      //## end CPIStepperMotorConfig::uiSamplingTime%3E8AF8060032.attr

      //## begin CPIStepperMotorConfig::dwIDStepValid%3F4469B70291.attr preserve=no  public: DWORD {U} p_dwIDStepValid
      DWORD m_dwIDStepValid;
      //## end CPIStepperMotorConfig::dwIDStepValid%3F4469B70291.attr

      //## begin CPIStepperMotorConfig::dwIDVelValid%3F446A2102D0.attr preserve=no  public: DWORD {U} p_dwIDVelValid
      DWORD m_dwIDVelValid;
      //## end CPIStepperMotorConfig::dwIDVelValid%3F446A2102D0.attr

      //## begin CPIStepperMotorConfig::dwIDStep%3F446A3900AD.attr preserve=no  public: DWORD {U} p_dwIDStep
      DWORD m_dwIDStep;
      //## end CPIStepperMotorConfig::dwIDStep%3F446A3900AD.attr

      //## begin CPIStepperMotorConfig::dwIDVelocity%3F446A8D005F.attr preserve=no  public: DWORD {U} p_dwIDVelocity
      DWORD m_dwIDVelocity;
      //## end CPIStepperMotorConfig::dwIDVelocity%3F446A8D005F.attr

      //## begin CPIStepperMotorConfig::dwIDActualPos%3F446AB00253.attr preserve=no  public: DWORD {U} p_dwIDActualPos
      DWORD m_dwIDActualPos;
      //## end CPIStepperMotorConfig::dwIDActualPos%3F446AB00253.attr

      //## begin CPIStepperMotorConfig::dwIDActualDirection%3F446ACC038B.attr preserve=no  public: DWORD {U} p_dwIDActualDirection
      DWORD m_dwIDActualDirection;
      //## end CPIStepperMotorConfig::dwIDActualDirection%3F446ACC038B.attr

      //## begin CPIStepperMotorConfig::dwIDDirection%3F446A55030E.attr preserve=no  public: DWORD {U} p_dwIDDirection
      DWORD m_dwIDDirection;
      //## end CPIStepperMotorConfig::dwIDDirection%3F446A55030E.attr

      //## begin CPIStepperMotorConfig::dwIDRestartValid%3F56FD90032C.attr preserve=no  public: DWORD {U} p_dwIDRestartValid
      DWORD m_dwIDRestartValid;
      //## end CPIStepperMotorConfig::dwIDRestartValid%3F56FD90032C.attr

    // Additional Private Declarations
      //## begin CPIStepperMotorConfig%3E70582C0280.private preserve=yes
      //## end CPIStepperMotorConfig%3E70582C0280.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIStepperMotorConfig%3E70582C0280.implementation preserve=yes
      //## end CPIStepperMotorConfig%3E70582C0280.implementation

};

//## begin CPIStepperMotorConfig%3E70582C0280.postscript preserve=yes
//## end CPIStepperMotorConfig%3E70582C0280.postscript

//## begin CPIStepperMotorProfile%3E71AE8803C8.preface preserve=yes
//## end CPIStepperMotorProfile%3E71AE8803C8.preface

//## Class: CPIStepperMotorProfile%3E71AE8803C8
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIStepperMotorProfile : public ICORefCounting  //## Inherits: <unnamed>%3E71B35F030C
{
  //## begin CPIStepperMotorProfile%3E71AE8803C8.initialDeclarations preserve=yes
  //## end CPIStepperMotorProfile%3E71AE8803C8.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIStepperMotorProfile%1047636420
      CPIStepperMotorProfile (const UINT p_uiSpeedHome, const UINT p_uiSpeedStartup, const UINT p_uiNomAccDec, const UINT p_uiSpeed, const UINT p_uiSpeedSearch);

    //## Destructor (generated)
      virtual ~CPIStepperMotorProfile();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: uiSpeedHome%434F778F0177
      UINT GetuiSpeedHome ();

      //## Attribute: uiSpeedStartup%3E71B3E60147
      //	[Hz] Start up speed.
      UINT GetuiSpeedStartup ();

      //## Attribute: uiSpeedSearch%3E71B4D802CE
      //	[Hz] Search speed.
      UINT GetuiSpeedSearch ();

      //## Attribute: uiSpeed%3E71B413028F
      //	[Hz] Run speed.
      UINT GetuiSpeed ();

      //## Attribute: uiNomAccDec%3E71B41201A5
      //	[Hz/s] Moving acceleration and deceleration.
      UINT GetuiNomAccDec ();

    // Additional Public Declarations
      //## begin CPIStepperMotorProfile%3E71AE8803C8.public preserve=yes
      //## end CPIStepperMotorProfile%3E71AE8803C8.public

  protected:
    // Additional Protected Declarations
      //## begin CPIStepperMotorProfile%3E71AE8803C8.protected preserve=yes
      //## end CPIStepperMotorProfile%3E71AE8803C8.protected

  private:
    //## Constructors (generated)
      CPIStepperMotorProfile(const CPIStepperMotorProfile &right);

    //## Assignment Operation (generated)
      const CPIStepperMotorProfile & operator=(const CPIStepperMotorProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CPIStepperMotorProfile &right) const;

      bool operator!=(const CPIStepperMotorProfile &right) const;

    // Data Members for Class Attributes

      //## begin CPIStepperMotorProfile::uiSpeedHome%434F778F0177.attr preserve=no  public: UINT {U} p_uiSpeedHome
      UINT m_uiSpeedHome;
      //## end CPIStepperMotorProfile::uiSpeedHome%434F778F0177.attr

      //## begin CPIStepperMotorProfile::uiSpeedStartup%3E71B3E60147.attr preserve=no  public: UINT {U} p_uiSpeedStartup
      UINT m_uiSpeedStartup;
      //## end CPIStepperMotorProfile::uiSpeedStartup%3E71B3E60147.attr

      //## begin CPIStepperMotorProfile::uiSpeedSearch%3E71B4D802CE.attr preserve=no  public: UINT {U} p_uiSpeedSearch
      UINT m_uiSpeedSearch;
      //## end CPIStepperMotorProfile::uiSpeedSearch%3E71B4D802CE.attr

      //## begin CPIStepperMotorProfile::uiSpeed%3E71B413028F.attr preserve=no  public: UINT {U} p_uiSpeed
      UINT m_uiSpeed;
      //## end CPIStepperMotorProfile::uiSpeed%3E71B413028F.attr

      //## begin CPIStepperMotorProfile::uiNomAccDec%3E71B41201A5.attr preserve=no  public: UINT {U} p_uiNomAccDec
      UINT m_uiNomAccDec;
      //## end CPIStepperMotorProfile::uiNomAccDec%3E71B41201A5.attr

    // Additional Private Declarations
      //## begin CPIStepperMotorProfile%3E71AE8803C8.private preserve=yes
      //## end CPIStepperMotorProfile%3E71AE8803C8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIStepperMotorProfile%3E71AE8803C8.implementation preserve=yes
      //## end CPIStepperMotorProfile%3E71AE8803C8.implementation

};

//## begin CPIStepperMotorProfile%3E71AE8803C8.postscript preserve=yes
//## end CPIStepperMotorProfile%3E71AE8803C8.postscript

//## begin EPIDeviceState%3EE5A89C00DD.preface preserve=yes
//## end EPIDeviceState%3EE5A89C00DD.preface

//## Class: EPIDeviceState%3EE5A89C00DD
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum { eNotConnected, eReadyForDownload, eRunning } EPIDeviceState;

//## begin EPIDeviceState%3EE5A89C00DD.postscript preserve=yes
//## end EPIDeviceState%3EE5A89C00DD.postscript

//## begin EPIResolutionDS1631Z%3EE5DF6B0031.preface preserve=yes
//## end EPIResolutionDS1631Z%3EE5DF6B0031.preface

//## Class: EPIResolutionDS1631Z%3EE5DF6B0031
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {eResLow, eAboveLow, eNormal, eHigh } EPIResolutionDS1631Z;

//## begin EPIResolutionDS1631Z%3EE5DF6B0031.postscript preserve=yes
//## end EPIResolutionDS1631Z%3EE5DF6B0031.postscript

//## begin EPIModeDS1631Z%3EE5E02E00CD.preface preserve=yes
//## end EPIModeDS1631Z%3EE5E02E00CD.preface

//## Class: EPIModeDS1631Z%3EE5E02E00CD
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum { eModeContinuous, eModeOneShot } EPIModeDS1631Z;

//## begin EPIModeDS1631Z%3EE5E02E00CD.postscript preserve=yes
//## end EPIModeDS1631Z%3EE5E02E00CD.postscript

//## begin CPIConfigDS1631Z%3EE5DF1300EC.preface preserve=yes
//## end CPIConfigDS1631Z%3EE5DF1300EC.preface

//## Class: CPIConfigDS1631Z%3EE5DF1300EC
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIConfigDS1631Z : public ICORefCounting  //## Inherits: <unnamed>%3EE5DF36011B
{
  //## begin CPIConfigDS1631Z%3EE5DF1300EC.initialDeclarations preserve=yes
  //## end CPIConfigDS1631Z%3EE5DF1300EC.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIConfigDS1631Z%1055243210
      CPIConfigDS1631Z (EPIModeDS1631Z p_eMode, EPIResolutionDS1631Z p_eResolution);

    //## Destructor (generated)
      virtual ~CPIConfigDS1631Z();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPI (PC Interface)::<unnamed>%3EE5E002035D
      //## Role: CPIConfigDS1631Z::eResolution%3EE5E003014B
      EPIResolutionDS1631Z GeteResolution ();

      //## Association: EBPI (PC Interface)::<unnamed>%3EE5E08102FF
      //## Role: CPIConfigDS1631Z::eMode%3EE5E082013B
      EPIModeDS1631Z GeteMode ();

    // Additional Public Declarations
      //## begin CPIConfigDS1631Z%3EE5DF1300EC.public preserve=yes
      //## end CPIConfigDS1631Z%3EE5DF1300EC.public

  protected:
    // Additional Protected Declarations
      //## begin CPIConfigDS1631Z%3EE5DF1300EC.protected preserve=yes
      //## end CPIConfigDS1631Z%3EE5DF1300EC.protected

  private:
    //## Constructors (generated)
      CPIConfigDS1631Z();

      CPIConfigDS1631Z(const CPIConfigDS1631Z &right);

    //## Assignment Operation (generated)
      const CPIConfigDS1631Z & operator=(const CPIConfigDS1631Z &right);

    //## Equality Operations (generated)
      bool operator==(const CPIConfigDS1631Z &right) const;

      bool operator!=(const CPIConfigDS1631Z &right) const;

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%3EE5E002035D
      //## begin CPIConfigDS1631Z::eResolution%3EE5E003014B.role preserve=no  public: EPIResolutionDS1631Z {1..1 -> 1..1VHN}
      EPIResolutionDS1631Z m_eResolution;
      //## end CPIConfigDS1631Z::eResolution%3EE5E003014B.role

      //## Association: EBPI (PC Interface)::<unnamed>%3EE5E08102FF
      //## begin CPIConfigDS1631Z::eMode%3EE5E082013B.role preserve=no  public: EPIModeDS1631Z {1..1 -> 1..1VHN}
      EPIModeDS1631Z m_eMode;
      //## end CPIConfigDS1631Z::eMode%3EE5E082013B.role

    // Additional Private Declarations
      //## begin CPIConfigDS1631Z%3EE5DF1300EC.private preserve=yes
      //## end CPIConfigDS1631Z%3EE5DF1300EC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIConfigDS1631Z%3EE5DF1300EC.implementation preserve=yes
      //## end CPIConfigDS1631Z%3EE5DF1300EC.implementation

};

//## begin CPIConfigDS1631Z%3EE5DF1300EC.postscript preserve=yes
//## end CPIConfigDS1631Z%3EE5DF1300EC.postscript

//## begin EPIInterface%3EE88D7C016D.preface preserve=yes
//## end EPIInterface%3EE88D7C016D.preface

//## Class: EPIInterface%3EE88D7C016D
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum { eEthernet, eUSB } EPIInterface;

//## begin EPIInterface%3EE88D7C016D.postscript preserve=yes
//## end EPIInterface%3EE88D7C016D.postscript

//## begin CPIInterfaceConfig%3EE5B9DC00DD.preface preserve=yes
//## end CPIInterfaceConfig%3EE5B9DC00DD.preface

//## Class: CPIInterfaceConfig%3EE5B9DC00DD
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIInterfaceConfig : public ICORefCounting  //## Inherits: <unnamed>%3EE5BA830060
{
  //## begin CPIInterfaceConfig%3EE5B9DC00DD.initialDeclarations preserve=yes
  //## end CPIInterfaceConfig%3EE5B9DC00DD.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIInterfaceConfig%1055243186
      CPIInterfaceConfig (const EPIInterface p_eInterface, const DWORD p_dwAddress, const DWORD p_dwMask, const DWORD p_dwGateway, const bool p_bUseDHCP);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwAddress%3EE5BA3702A2
      DWORD GetdwAddress ();

      //## Attribute: dwMask%3EE5BA480031
      DWORD GetdwMask ();

      //## Attribute: dwGateway%3EE5BA510198
      DWORD GetdwGateway ();

      //## Attribute: bUseDHCP%4110A2B703D5
      bool GetbUseDHCP ();

    // Additional Public Declarations
      //## begin CPIInterfaceConfig%3EE5B9DC00DD.public preserve=yes
      //## end CPIInterfaceConfig%3EE5B9DC00DD.public

  protected:
    // Additional Protected Declarations
      //## begin CPIInterfaceConfig%3EE5B9DC00DD.protected preserve=yes
      //## end CPIInterfaceConfig%3EE5B9DC00DD.protected

  private:
    //## Constructors (generated)
      CPIInterfaceConfig();

      CPIInterfaceConfig(const CPIInterfaceConfig &right);

    //## Destructor (generated)
      virtual ~CPIInterfaceConfig();

    //## Assignment Operation (generated)
      const CPIInterfaceConfig & operator=(const CPIInterfaceConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CPIInterfaceConfig &right) const;

      bool operator!=(const CPIInterfaceConfig &right) const;

    // Data Members for Class Attributes

      //## begin CPIInterfaceConfig::dwAddress%3EE5BA3702A2.attr preserve=no  public: DWORD {U} p_dwAddress
      DWORD m_dwAddress;
      //## end CPIInterfaceConfig::dwAddress%3EE5BA3702A2.attr

      //## begin CPIInterfaceConfig::dwMask%3EE5BA480031.attr preserve=no  public: DWORD {U} p_dwMask
      DWORD m_dwMask;
      //## end CPIInterfaceConfig::dwMask%3EE5BA480031.attr

      //## begin CPIInterfaceConfig::dwGateway%3EE5BA510198.attr preserve=no  public: DWORD {U} p_dwGateway
      DWORD m_dwGateway;
      //## end CPIInterfaceConfig::dwGateway%3EE5BA510198.attr

      //## begin CPIInterfaceConfig::bUseDHCP%4110A2B703D5.attr preserve=no  public: bool {U} p_bUseDHCP
      bool m_bUseDHCP;
      //## end CPIInterfaceConfig::bUseDHCP%4110A2B703D5.attr

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%3EE88DEA01DD
      //## Role: CPIInterfaceConfig::eInterface%3EE88DEA03B3
      //## begin CPIInterfaceConfig::eInterface%3EE88DEA03B3.role preserve=no  public: EPIInterface { -> 1..1VHN}
      EPIInterface m_eInterface;
      //## end CPIInterfaceConfig::eInterface%3EE88DEA03B3.role

    // Additional Private Declarations
      //## begin CPIInterfaceConfig%3EE5B9DC00DD.private preserve=yes
      //## end CPIInterfaceConfig%3EE5B9DC00DD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIInterfaceConfig%3EE5B9DC00DD.implementation preserve=yes
      //## end CPIInterfaceConfig%3EE5B9DC00DD.implementation

};

//## begin CPIInterfaceConfig%3EE5B9DC00DD.postscript preserve=yes
//## end CPIInterfaceConfig%3EE5B9DC00DD.postscript

//## begin CPIDataADCMAX1037%3F49CE12000F.preface preserve=yes
//## end CPIDataADCMAX1037%3F49CE12000F.preface

//## Class: CPIDataADCMAX1037%3F49CE12000F
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIDataADCMAX1037 : public ICORefCounting  //## Inherits: <unnamed>%3F49D60A03D8
{
  //## begin CPIDataADCMAX1037%3F49CE12000F.initialDeclarations preserve=yes
  //## end CPIDataADCMAX1037%3F49CE12000F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIDataADCMAX1037%1061804143
      CPIDataADCMAX1037 (BYTE p_cAIN0, BYTE p_cAIN1, BYTE p_cAIN2, BYTE p_cAIN3);

    //## Destructor (generated)
      virtual ~CPIDataADCMAX1037();


    //## Other Operations (specified)
      //## Operation: GetDataAIN0%1061804146
      BYTE GetDataAIN0 ();

      //## Operation: GetDataAIN1%1061804147
      BYTE GetDataAIN1 ();

      //## Operation: GetDataAIN2%1061804148
      BYTE GetDataAIN2 ();

      //## Operation: GetDataAIN3%1061804149
      BYTE GetDataAIN3 ();

    // Additional Public Declarations
      //## begin CPIDataADCMAX1037%3F49CE12000F.public preserve=yes
      //## end CPIDataADCMAX1037%3F49CE12000F.public

  protected:
    // Additional Protected Declarations
      //## begin CPIDataADCMAX1037%3F49CE12000F.protected preserve=yes
      //## end CPIDataADCMAX1037%3F49CE12000F.protected

  private:
    //## Constructors (generated)
      CPIDataADCMAX1037();

      CPIDataADCMAX1037(const CPIDataADCMAX1037 &right);

    //## Assignment Operation (generated)
      const CPIDataADCMAX1037 & operator=(const CPIDataADCMAX1037 &right);

    //## Equality Operations (generated)
      bool operator==(const CPIDataADCMAX1037 &right) const;

      bool operator!=(const CPIDataADCMAX1037 &right) const;

    // Data Members for Class Attributes

      //## Attribute: cDataAIN0%3FFD556500AB
      //## begin CPIDataADCMAX1037::cDataAIN0%3FFD556500AB.attr preserve=no  private: BYTE {U} p_cAIN0
      BYTE m_cDataAIN0;
      //## end CPIDataADCMAX1037::cDataAIN0%3FFD556500AB.attr

      //## Attribute: cDataAIN1%3FFD559403C8
      //## begin CPIDataADCMAX1037::cDataAIN1%3FFD559403C8.attr preserve=no  private: BYTE {U} p_cAIN1
      BYTE m_cDataAIN1;
      //## end CPIDataADCMAX1037::cDataAIN1%3FFD559403C8.attr

      //## Attribute: cDataAIN2%3FFD55950280
      //## begin CPIDataADCMAX1037::cDataAIN2%3FFD55950280.attr preserve=no  private: BYTE {U} p_cAIN2
      BYTE m_cDataAIN2;
      //## end CPIDataADCMAX1037::cDataAIN2%3FFD55950280.attr

      //## Attribute: cDataAIN3%3FFD5596009C
      //## begin CPIDataADCMAX1037::cDataAIN3%3FFD5596009C.attr preserve=no  private: BYTE {U} p_cAIN3
      BYTE m_cDataAIN3;
      //## end CPIDataADCMAX1037::cDataAIN3%3FFD5596009C.attr

    // Additional Private Declarations
      //## begin CPIDataADCMAX1037%3F49CE12000F.private preserve=yes
      //## end CPIDataADCMAX1037%3F49CE12000F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIDataADCMAX1037%3F49CE12000F.implementation preserve=yes
      //## end CPIDataADCMAX1037%3F49CE12000F.implementation

};

//## begin CPIDataADCMAX1037%3F49CE12000F.postscript preserve=yes
//## end CPIDataADCMAX1037%3F49CE12000F.postscript

//## begin CPISyncObjDataADCMAX1037%3F49D7B80242.preface preserve=yes
//## end CPISyncObjDataADCMAX1037%3F49D7B80242.preface

//## Class: CPISyncObjDataADCMAX1037%3F49D7B80242; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F49D87C02EE;CPIDataADCMAX1037 { -> F}

typedef CCOSyncObjectParameterizedByRef< CPIDataADCMAX1037* > CPISyncObjDataADCMAX1037;

//## begin CPISyncObjDataADCMAX1037%3F49D7B80242.postscript preserve=yes
//## end CPISyncObjDataADCMAX1037%3F49D7B80242.postscript

//## begin CPII2CConfig%3F5C983E0399.preface preserve=yes
//## end CPII2CConfig%3F5C983E0399.preface

//## Class: CPII2CConfig%3F5C983E0399
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPII2CConfig : public ICORefCounting  //## Inherits: <unnamed>%3F5C985303D8
{
  //## begin CPII2CConfig%3F5C983E0399.initialDeclarations preserve=yes
  //## end CPII2CConfig%3F5C983E0399.initialDeclarations

  public:
    //## Constructors (generated)
      CPII2CConfig();

    //## Constructors (specified)
      //## Operation: CPII2CConfig%1063032868
      CPII2CConfig (DWORD p_dwLogIDBusNumber, DWORD p_dwLogIDTransferSpeed, DWORD p_dwLogIDInData, DWORD p_dwLogIDOutData);

    //## Destructor (generated)
      virtual ~CPII2CConfig();

    // Additional Public Declarations
      //## begin CPII2CConfig%3F5C983E0399.public preserve=yes
      //## end CPII2CConfig%3F5C983E0399.public

  protected:
    // Additional Protected Declarations
      //## begin CPII2CConfig%3F5C983E0399.protected preserve=yes
      //## end CPII2CConfig%3F5C983E0399.protected

  private:
    //## Constructors (generated)
      CPII2CConfig(const CPII2CConfig &right);

    //## Assignment Operation (generated)
      const CPII2CConfig & operator=(const CPII2CConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CPII2CConfig &right) const;

      bool operator!=(const CPII2CConfig &right) const;

    // Additional Private Declarations
      //## begin CPII2CConfig%3F5C983E0399.private preserve=yes
      //## end CPII2CConfig%3F5C983E0399.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPII2CConfig%3F5C983E0399.implementation preserve=yes
      //## end CPII2CConfig%3F5C983E0399.implementation

};

//## begin CPII2CConfig%3F5C983E0399.postscript preserve=yes
//## end CPII2CConfig%3F5C983E0399.postscript

//## begin CPISyncObjectStringArray%3F6706F3001C.preface preserve=yes
//## end CPISyncObjectStringArray%3F6706F3001C.preface

//## Class: CPISyncObjectStringArray%3F6706F3001C; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef CCOSyncObjectParameterized< CStringArray* > CPISyncObjectStringArray;

//## begin CPISyncObjectStringArray%3F6706F3001C.postscript preserve=yes
//## end CPISyncObjectStringArray%3F6706F3001C.postscript

//## begin CPIPersistentItem%3F93E453014F.preface preserve=yes
//## end CPIPersistentItem%3F93E453014F.preface

//## Class: CPIPersistentItem%3F93E453014F
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FAA62AB00C3;PI_CONST { -> }

class EBPI_DLL_DECL CPIPersistentItem : public ICORefCounting  //## Inherits: <unnamed>%3F98E23C0191
{
  //## begin CPIPersistentItem%3F93E453014F.initialDeclarations preserve=yes
  //## end CPIPersistentItem%3F93E453014F.initialDeclarations

  public:
    //## Constructors (generated)
      CPIPersistentItem();


    //## Other Operations (specified)
      //## Operation: ToString%1066654502
      virtual CString ToString () = 0;

      //## Operation: Split%1074531758
      static void Split (LPCTSTR p_sSource, LPCTSTR p_sSeparator, CStringList& p_List);

    // Additional Public Declarations
      //## begin CPIPersistentItem%3F93E453014F.public preserve=yes
      //## end CPIPersistentItem%3F93E453014F.public

  protected:
    //## Destructor (generated)
      virtual ~CPIPersistentItem();

    // Additional Protected Declarations
      //## begin CPIPersistentItem%3F93E453014F.protected preserve=yes
      //## end CPIPersistentItem%3F93E453014F.protected

  private:
    //## Constructors (generated)
      CPIPersistentItem(const CPIPersistentItem &right);

    //## Assignment Operation (generated)
      const CPIPersistentItem & operator=(const CPIPersistentItem &right);

    //## Equality Operations (generated)
      bool operator==(const CPIPersistentItem &right) const;

      bool operator!=(const CPIPersistentItem &right) const;

    // Additional Private Declarations
      //## begin CPIPersistentItem%3F93E453014F.private preserve=yes
      //## end CPIPersistentItem%3F93E453014F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIPersistentItem%3F93E453014F.implementation preserve=yes
      //## end CPIPersistentItem%3F93E453014F.implementation

};

//## begin CPIPersistentItem%3F93E453014F.postscript preserve=yes
//## end CPIPersistentItem%3F93E453014F.postscript

//## begin CPIPersistentLifeTimeCounter%3F781CA30021.preface preserve=yes
//## end CPIPersistentLifeTimeCounter%3F781CA30021.preface

//## Class: CPIPersistentLifeTimeCounter%3F781CA30021
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%4200A10F0352;XPIExceptionErrorTokenizing { -> }

class EBPI_DLL_DECL CPIPersistentLifeTimeCounter : public CPIPersistentItem  //## Inherits: <unnamed>%3F93EC4C0333
{
  //## begin CPIPersistentLifeTimeCounter%3F781CA30021.initialDeclarations preserve=yes
  //## end CPIPersistentLifeTimeCounter%3F781CA30021.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIPersistentLifeTimeCounter%1064853107
      CPIPersistentLifeTimeCounter (const CString& p_sItem);

      //## Operation: CPIPersistentLifeTimeCounter%1068448312
      CPIPersistentLifeTimeCounter (const EPILifeTimeCounter p_eDevice, const UINT p_uiValue);

    //## Destructor (generated)
      virtual ~CPIPersistentLifeTimeCounter();


    //## Other Operations (specified)
      //## Operation: ToString%1074505553
      virtual CString ToString ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPI (PC Interface)::<unnamed>%3F781D34036C
      //## Role: CPIPersistentLifeTimeCounter::eDevice%3F781D350264
      EPILifeTimeCounter GeteDevice ();

      //## Association: EBPI (PC Interface)::<unnamed>%3F781D5D00BD
      //## Role: CPIPersistentLifeTimeCounter::uiValue%3F781D5D035E
      UINT GetuiValue ();

    // Additional Public Declarations
      //## begin CPIPersistentLifeTimeCounter%3F781CA30021.public preserve=yes
      //## end CPIPersistentLifeTimeCounter%3F781CA30021.public

  protected:
    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%3F781D34036C
      //## begin CPIPersistentLifeTimeCounter::eDevice%3F781D350264.role preserve=no  public: EPILifeTimeCounter {1..1 -> 1..1VN}
      EPILifeTimeCounter m_eDevice;
      //## end CPIPersistentLifeTimeCounter::eDevice%3F781D350264.role

      //## Association: EBPI (PC Interface)::<unnamed>%3F781D5D00BD
      //## begin CPIPersistentLifeTimeCounter::uiValue%3F781D5D035E.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiValue;
      //## end CPIPersistentLifeTimeCounter::uiValue%3F781D5D035E.role

    // Additional Protected Declarations
      //## begin CPIPersistentLifeTimeCounter%3F781CA30021.protected preserve=yes
      //## end CPIPersistentLifeTimeCounter%3F781CA30021.protected

  private:
    //## Constructors (generated)
      CPIPersistentLifeTimeCounter();

      CPIPersistentLifeTimeCounter(const CPIPersistentLifeTimeCounter &right);

    //## Assignment Operation (generated)
      const CPIPersistentLifeTimeCounter & operator=(const CPIPersistentLifeTimeCounter &right);

    //## Equality Operations (generated)
      bool operator==(const CPIPersistentLifeTimeCounter &right) const;

      bool operator!=(const CPIPersistentLifeTimeCounter &right) const;

    // Additional Private Declarations
      //## begin CPIPersistentLifeTimeCounter%3F781CA30021.private preserve=yes
      //## end CPIPersistentLifeTimeCounter%3F781CA30021.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIPersistentLifeTimeCounter%3F781CA30021.implementation preserve=yes
      //## end CPIPersistentLifeTimeCounter%3F781CA30021.implementation

};

//## begin CPIPersistentLifeTimeCounter%3F781CA30021.postscript preserve=yes
//## end CPIPersistentLifeTimeCounter%3F781CA30021.postscript

//## begin CPISyncObjListPersistentItems%3F93FDAD0258.preface preserve=yes
//## end CPISyncObjListPersistentItems%3F93FDAD0258.preface

//## Class: CPISyncObjListPersistentItems%3F93FDAD0258; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F93FDE30333;CPIPersistentItemList { -> }

typedef CCOSyncObjectParameterizedByRef< CPIPersistentItemList* > CPISyncObjListPersistentItems;

//## begin CPISyncObjListPersistentItems%3F93FDAD0258.postscript preserve=yes
//## end CPISyncObjListPersistentItems%3F93FDAD0258.postscript

//## begin CPIPersistentPara%3F94CBBD0345.preface preserve=yes
//## end CPIPersistentPara%3F94CBBD0345.preface

//## Class: CPIPersistentPara%3F94CBBD0345
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FAA614402D6;PI_IDENTIFIERS { -> }

class EBPI_DLL_DECL CPIPersistentPara : public CPIPersistentItem  //## Inherits: <unnamed>%3F93F8160268
{
  //## begin CPIPersistentPara%3F94CBBD0345.initialDeclarations preserve=yes
  //## end CPIPersistentPara%3F94CBBD0345.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIPersistentPara%1066715715
      CPIPersistentPara (const CString& p_sPara);


    //## Other Operations (specified)
      //## Operation: ToString%1074505554
      virtual CString ToString ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPI (PC Interface)::<unnamed>%3F93E29101FB
      //## Role: CPIPersistentPara::sParaName%3F93E2920017
      CString GetsParaName ();

      //## Association: EBPI (PC Interface)::<unnamed>%40602B7F00CD
      //## Role: CPIPersistentPara::sVersion%40602B7F030F
      CString GetsVersion ();

    // Additional Public Declarations
      //## begin CPIPersistentPara%3F94CBBD0345.public preserve=yes
      //## end CPIPersistentPara%3F94CBBD0345.public

  protected:
    // Additional Protected Declarations
      //## begin CPIPersistentPara%3F94CBBD0345.protected preserve=yes
      //## end CPIPersistentPara%3F94CBBD0345.protected

  private:
    //## Constructors (generated)
      CPIPersistentPara(const CPIPersistentPara &right);

    //## Destructor (generated)
      virtual ~CPIPersistentPara();

    //## Assignment Operation (generated)
      const CPIPersistentPara & operator=(const CPIPersistentPara &right);

    //## Equality Operations (generated)
      bool operator==(const CPIPersistentPara &right) const;

      bool operator!=(const CPIPersistentPara &right) const;

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%3F93E29101FB
      //## begin CPIPersistentPara::sParaName%3F93E2920017.role preserve=no  public: CString {1..1 -> 1..1VFHN}
      CString m_sParaName;
      //## end CPIPersistentPara::sParaName%3F93E2920017.role

      //## Association: EBPI (PC Interface)::<unnamed>%3F93F9300093
      //## Role: CPIPersistentPara::sData%3F93F93001BD
      //## begin CPIPersistentPara::sData%3F93F93001BD.role preserve=no  public: CString {1..1 -> 1..1VFHN}
      CString m_sData;
      //## end CPIPersistentPara::sData%3F93F93001BD.role

      //## Association: EBPI (PC Interface)::<unnamed>%3F9FD0500157
      //## Role: CPIPersistentPara::eParameterType%3F9FD05002EF
      //## begin CPIPersistentPara::eParameterType%3F9FD05002EF.role preserve=no  public: EPIPersistentParameterType { -> VFHN}
      EPIPersistentParameterType m_eParameterType;
      //## end CPIPersistentPara::eParameterType%3F9FD05002EF.role

      //## Association: EBPI (PC Interface)::<unnamed>%40602B7F00CD
      //## begin CPIPersistentPara::sVersion%40602B7F030F.role preserve=no  public: CString {1..1 -> 1..1VFHN}
      CString m_sVersion;
      //## end CPIPersistentPara::sVersion%40602B7F030F.role

    // Additional Private Declarations
      //## begin CPIPersistentPara%3F94CBBD0345.private preserve=yes
      //## end CPIPersistentPara%3F94CBBD0345.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIPersistentPara%3F94CBBD0345.implementation preserve=yes
      //## end CPIPersistentPara%3F94CBBD0345.implementation

};

//## begin CPIPersistentPara%3F94CBBD0345.postscript preserve=yes
//## end CPIPersistentPara%3F94CBBD0345.postscript

//## begin CPIPersistentConfig%3F9500740096.preface preserve=yes
//## end CPIPersistentConfig%3F9500740096.preface

//## Class: CPIPersistentConfig%3F9500740096
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIPersistentConfig : public ICORefCounting  //## Inherits: <unnamed>%3F95008F020D
{
  //## begin CPIPersistentConfig%3F9500740096.initialDeclarations preserve=yes
  //## end CPIPersistentConfig%3F9500740096.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIPersistentConfig%1066803566
      CPIPersistentConfig (const DWORD p_dwTimerIntervalFactor, const DWORD p_dwTimerInterval, const DWORD p_dwHeaderStartAddress);

    //## Destructor (generated)
      virtual ~CPIPersistentConfig();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwTimerIntervalFactor%3F951F13024B
      //	DESCRIPTION:
      //	If this time is elapsed, all life time counters will be
      //	saved to the persistent store.
      //
      //	UNIT: [s]
      DWORD GetdwTimerIntervalFactor ();

      //## Attribute: dwTimerInterval%3FA0C20003A9
      //	DESCRIPTION:
      //	If this time is elapsed, all life time counters will be
      //	incremented with the time timerinterval.
      //
      //	UNIT: [s]
      DWORD GetdwTimerInterval ();

      //## Attribute: dwHeaderStartAddress%4004F31A029F
      //	DESCRIPTION:
      //	The header can start at any address.
      //
      //	UNIT: []
      DWORD GetdwHeaderStartAddress ();

    // Additional Public Declarations
      //## begin CPIPersistentConfig%3F9500740096.public preserve=yes
      //## end CPIPersistentConfig%3F9500740096.public

  protected:
    // Additional Protected Declarations
      //## begin CPIPersistentConfig%3F9500740096.protected preserve=yes
      //## end CPIPersistentConfig%3F9500740096.protected

  private:
    //## Constructors (generated)
      CPIPersistentConfig(const CPIPersistentConfig &right);

    //## Assignment Operation (generated)
      const CPIPersistentConfig & operator=(const CPIPersistentConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CPIPersistentConfig &right) const;

      bool operator!=(const CPIPersistentConfig &right) const;

    // Data Members for Class Attributes

      //## begin CPIPersistentConfig::dwTimerIntervalFactor%3F951F13024B.attr preserve=no  public: DWORD {U} p_dwTimerIntervalFactor
      DWORD m_dwTimerIntervalFactor;
      //## end CPIPersistentConfig::dwTimerIntervalFactor%3F951F13024B.attr

      //## begin CPIPersistentConfig::dwTimerInterval%3FA0C20003A9.attr preserve=no  public: DWORD {U} p_dwTimerInterval
      DWORD m_dwTimerInterval;
      //## end CPIPersistentConfig::dwTimerInterval%3FA0C20003A9.attr

      //## begin CPIPersistentConfig::dwHeaderStartAddress%4004F31A029F.attr preserve=no  public: DWORD {U} p_dwHeaderStartAddress
      DWORD m_dwHeaderStartAddress;
      //## end CPIPersistentConfig::dwHeaderStartAddress%4004F31A029F.attr

    // Additional Private Declarations
      //## begin CPIPersistentConfig%3F9500740096.private preserve=yes
      //## end CPIPersistentConfig%3F9500740096.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIPersistentConfig%3F9500740096.implementation preserve=yes
      //## end CPIPersistentConfig%3F9500740096.implementation

};

//## begin CPIPersistentConfig%3F9500740096.postscript preserve=yes
//## end CPIPersistentConfig%3F9500740096.postscript

//## begin CPIIdentificationVersion%3F98E79701A0.preface preserve=yes
//## end CPIIdentificationVersion%3F98E79701A0.preface

//## Class: CPIIdentificationVersion%3F98E79701A0
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIIdentificationVersion : public ICORefCounting  //## Inherits: <unnamed>%4003ACCD0118
{
  //## begin CPIIdentificationVersion%3F98E79701A0.initialDeclarations preserve=yes
  //## end CPIIdentificationVersion%3F98E79701A0.initialDeclarations

  public:
    //## Constructors (generated)
      CPIIdentificationVersion();

      CPIIdentificationVersion(const CPIIdentificationVersion &right);

    //## Constructors (specified)
      //## Operation: CPIIdentificationVersion%1066980586
      CPIIdentificationVersion (const UINT p_uiMajor, const UINT p_uiMinor);

      //## Operation: CPIIdentificationVersion%1074678215
      CPIIdentificationVersion (LPCTSTR p_sVersion);

    //## Destructor (generated)
      virtual ~CPIIdentificationVersion();

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%3F782693005F
      //## Role: CPIIdentificationVersion::uiMajor%3F78269401E7
      //## begin CPIIdentificationVersion::uiMajor%3F78269401E7.role preserve=no  public: UINT {1..1 -> 1..1VFN}
      UINT m_uiMajor;
      //## end CPIIdentificationVersion::uiMajor%3F78269401E7.role

      //## Association: EBPI (PC Interface)::<unnamed>%3F78269503BA
      //## Role: CPIIdentificationVersion::uiMinor%3F7826970001
      //## begin CPIIdentificationVersion::uiMinor%3F7826970001.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiMinor;
      //## end CPIIdentificationVersion::uiMinor%3F7826970001.role

      //## Association: EBPI (PC Interface)::<unnamed>%400E491302FC
      //## Role: CPIIdentificationVersion::sVersion%400E49140119
      //## begin CPIIdentificationVersion::sVersion%400E49140119.role preserve=no  public: CString {1..1 -> 1..1VHN}
      CString m_sVersion;
      //## end CPIIdentificationVersion::sVersion%400E49140119.role

    // Additional Public Declarations
      //## begin CPIIdentificationVersion%3F98E79701A0.public preserve=yes
      //## end CPIIdentificationVersion%3F98E79701A0.public

  protected:
    // Additional Protected Declarations
      //## begin CPIIdentificationVersion%3F98E79701A0.protected preserve=yes
      //## end CPIIdentificationVersion%3F98E79701A0.protected

  private:
    //## Assignment Operation (generated)
      const CPIIdentificationVersion & operator=(const CPIIdentificationVersion &right);

    //## Equality Operations (generated)
      bool operator==(const CPIIdentificationVersion &right) const;

      bool operator!=(const CPIIdentificationVersion &right) const;

    // Additional Private Declarations
      //## begin CPIIdentificationVersion%3F98E79701A0.private preserve=yes
      //## end CPIIdentificationVersion%3F98E79701A0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIIdentificationVersion%3F98E79701A0.implementation preserve=yes
      //## end CPIIdentificationVersion%3F98E79701A0.implementation

};

//## begin CPIIdentificationVersion%3F98E79701A0.postscript preserve=yes
//## end CPIIdentificationVersion%3F98E79701A0.postscript

//## begin CPIPersistentIdent%3F781CB9032E.preface preserve=yes
//## end CPIPersistentIdent%3F781CB9032E.preface

//## Class: CPIPersistentIdent%3F781CB9032E
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPIPersistentIdent : public CPIPersistentItem  //## Inherits: <unnamed>%3F93ED4C0007
{
  //## begin CPIPersistentIdent%3F781CB9032E.initialDeclarations preserve=yes
  //## end CPIPersistentIdent%3F781CB9032E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPIPersistentIdent%1066717292
      CPIPersistentIdent (LPCTSTR p_sIdent);

      //## Operation: CPIPersistentIdent%1073378938
      CPIPersistentIdent (LPCTSTR p_sSerialNo, LPCTSTR p_sArticleNo, CPIIdentificationVersion p_oVersion);

    //## Destructor (generated)
      virtual ~CPIPersistentIdent();


    //## Other Operations (specified)
      //## Operation: ToString%1074505555
      virtual CString ToString ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPI (PC Interface)::<unnamed>%3F7825D203CA
      //## Role: CPIPersistentIdent::sSerialNo%3F7825D40199
      CString GetsSerialNo ();

      //## Association: EBPI (PC Interface)::<unnamed>%3F7825D701B7
      //## Role: CPIPersistentIdent::sArticleNo%3F7825D703CB
      CString GetsArticleNo ();

    // Additional Public Declarations
      //## begin CPIPersistentIdent%3F781CB9032E.public preserve=yes
      //## end CPIPersistentIdent%3F781CB9032E.public

  protected:
    // Additional Protected Declarations
      //## begin CPIPersistentIdent%3F781CB9032E.protected preserve=yes
      //## end CPIPersistentIdent%3F781CB9032E.protected

  private:
    //## Constructors (generated)
      CPIPersistentIdent(const CPIPersistentIdent &right);

    //## Assignment Operation (generated)
      const CPIPersistentIdent & operator=(const CPIPersistentIdent &right);

    //## Equality Operations (generated)
      bool operator==(const CPIPersistentIdent &right) const;

      bool operator!=(const CPIPersistentIdent &right) const;

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%3F7825D203CA
      //## begin CPIPersistentIdent::sSerialNo%3F7825D40199.role preserve=no  public: CString {1..1 -> 1..1VHN}
      CString m_sSerialNo;
      //## end CPIPersistentIdent::sSerialNo%3F7825D40199.role

      //## Association: EBPI (PC Interface)::<unnamed>%3F7825D701B7
      //## begin CPIPersistentIdent::sArticleNo%3F7825D703CB.role preserve=no  public: CString {1..1 -> 1..1VHN}
      CString m_sArticleNo;
      //## end CPIPersistentIdent::sArticleNo%3F7825D703CB.role

      //## Association: EBPI (PC Interface)::<unnamed>%3F98E8460385
      //## Role: CPIPersistentIdent::oVersion%3F98E8470376
      //## begin CPIPersistentIdent::oVersion%3F98E8470376.role preserve=no  public: CPIIdentificationVersion {1..1 -> 1..1VHN}
      CPIIdentificationVersion m_oVersion;
      //## end CPIPersistentIdent::oVersion%3F98E8470376.role

    // Additional Private Declarations
      //## begin CPIPersistentIdent%3F781CB9032E.private preserve=yes
      //## end CPIPersistentIdent%3F781CB9032E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPIPersistentIdent%3F781CB9032E.implementation preserve=yes
      //## end CPIPersistentIdent%3F781CB9032E.implementation

};

//## begin CPIPersistentIdent%3F781CB9032E.postscript preserve=yes
//## end CPIPersistentIdent%3F781CB9032E.postscript

//## begin CPISyncObjI2CDataStream%3FD82B6701B5.preface preserve=yes
//## end CPISyncObjI2CDataStream%3FD82B6701B5.preface

//## Class: CPISyncObjI2CDataStream%3FD82B6701B5; Instantiated Class
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FD8319C0251;CPII2CDataStream { -> F}

typedef CCOSyncObjectParameterizedByRef< CPII2CDataStream* > CPISyncObjI2CDataStream;

//## begin CPISyncObjI2CDataStream%3FD82B6701B5.postscript preserve=yes
//## end CPISyncObjI2CDataStream%3FD82B6701B5.postscript

//## begin CPII2CDataStream%3FD8310603B9.preface preserve=yes
//## end CPII2CDataStream%3FD8310603B9.preface

//## Class: CPII2CDataStream%3FD8310603B9
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL CPII2CDataStream : public ICORefCounting  //## Inherits: <unnamed>%3FD831970138
{
  //## begin CPII2CDataStream%3FD8310603B9.initialDeclarations preserve=yes
  //## end CPII2CDataStream%3FD8310603B9.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPII2CDataStream%1071126821
      CPII2CDataStream (BYTE* p_pI2CDataStream, int p_nSize);

    //## Destructor (generated)
      virtual ~CPII2CDataStream();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: pcI2CDataStream%3FD83AC302DE
      BYTE* GetpcI2CDataStream ();

      //## Attribute: nSize%3FD83B42035B
      int GetnSize ();

    // Additional Public Declarations
      //## begin CPII2CDataStream%3FD8310603B9.public preserve=yes
      //## end CPII2CDataStream%3FD8310603B9.public

  protected:
    // Additional Protected Declarations
      //## begin CPII2CDataStream%3FD8310603B9.protected preserve=yes
      //## end CPII2CDataStream%3FD8310603B9.protected

  private:
    //## Constructors (generated)
      CPII2CDataStream();

      CPII2CDataStream(const CPII2CDataStream &right);

    //## Assignment Operation (generated)
      const CPII2CDataStream & operator=(const CPII2CDataStream &right);

    //## Equality Operations (generated)
      bool operator==(const CPII2CDataStream &right) const;

      bool operator!=(const CPII2CDataStream &right) const;

    // Data Members for Class Attributes

      //## begin CPII2CDataStream::pcI2CDataStream%3FD83AC302DE.attr preserve=no  public: BYTE* {U} p_pI2CDataStream
      BYTE* m_pcI2CDataStream;
      //## end CPII2CDataStream::pcI2CDataStream%3FD83AC302DE.attr

      //## begin CPII2CDataStream::nSize%3FD83B42035B.attr preserve=no  public: int {U} p_nSize
      int m_nSize;
      //## end CPII2CDataStream::nSize%3FD83B42035B.attr

    // Additional Private Declarations
      //## begin CPII2CDataStream%3FD8310603B9.private preserve=yes
      //## end CPII2CDataStream%3FD8310603B9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPII2CDataStream%3FD8310603B9.implementation preserve=yes
      //## end CPII2CDataStream%3FD8310603B9.implementation

};

//## begin CPII2CDataStream%3FD8310603B9.postscript preserve=yes
//## end CPII2CDataStream%3FD8310603B9.postscript

// Class CPIMeasurementChannelDataPackage 

// Class CPIObjIdentification 

// Class CPIPersistentSoftwareComponent 

// Class CPIPersistentSoftwareComponentVersion 

// Class CPITemperatureControlProfile 

// Class CPITemperatureControlConfig 

// Class CPIPowerControlProfile 

// Class CPIWedgeControlProfile 

// Class CPIWedgeControlConfig 

// Class CPIMeasurementChannelProfile 

// Class CPIPowerControlConfig 

// Class CPIPersistentItemList 

// Class CPIPersistentSoftwareComponentVersionList 

// Class CPIPersistentSoftwareComponentList 

// Class CPIStepperMotorConfig 

// Class CPIStepperMotorProfile 

// Class CPIConfigDS1631Z 

// Class CPIInterfaceConfig 

// Class CPIDataADCMAX1037 

// Class CPII2CConfig 

// Class CPIPersistentItem 

// Class CPIPersistentLifeTimeCounter 

// Class CPIPersistentPara 

// Class CPIPersistentConfig 

// Class CPIIdentificationVersion 

// Class CPIPersistentIdent 

// Class CPII2CDataStream 

//## begin CPISyncObjDataPackage.instantiation preserve=no
template class CCOSyncObjectParameterizedByRef< CPIMeasurementChannelDataPackage* >;
//## end CPISyncObjDataPackage.instantiation
//## begin CPISyncObjDataADCMAX1037.instantiation preserve=no
template class CCOSyncObjectParameterizedByRef< CPIDataADCMAX1037* >;
//## end CPISyncObjDataADCMAX1037.instantiation
//## begin CPISyncObjI2CDataStream.instantiation preserve=no
template class CCOSyncObjectParameterizedByRef< CPII2CDataStream* >;
//## end CPISyncObjI2CDataStream.instantiation
//## begin module%3DAE54C202D2.epilog preserve=yes
//## end module%3DAE54C202D2.epilog


#endif
