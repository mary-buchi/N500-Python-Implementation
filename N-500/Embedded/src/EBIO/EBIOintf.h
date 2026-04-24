//## begin module%3DF5AFAF0232.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DF5AFAF0232.cm

//## begin module%3DF5AFAF0232.cp preserve=no
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
//## end module%3DF5AFAF0232.cp

//## Module: EBIOintf%3DF5AFAF0232; Package specification
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Source file: R:\Embedded\src\EBIO\EBIOintf.h

#ifndef EBIOintf_h
#define EBIOintf_h 1

//## begin module%3DF5AFAF0232.additionalIncludes preserve=no
//## end module%3DF5AFAF0232.additionalIncludes

//## begin module%3DF5AFAF0232.includes preserve=yes
//## end module%3DF5AFAF0232.includes

// EBPIintf
#include "EBPIintf.h"


//## begin module%3DF5AFAF0232.declarations preserve=no
//## end module%3DF5AFAF0232.declarations

//## begin module%3DF5AFAF0232.additionalDeclarations preserve=yes
//## end module%3DF5AFAF0232.additionalDeclarations


//## begin CIOOutputAnalogInterface%3DF5BE8B0148.preface preserve=yes
//## end CIOOutputAnalogInterface%3DF5BE8B0148.preface

//## Class: CIOOutputAnalogInterface%3DF5BE8B0148
//## Category: EBIO (Analog- / Digital- In-/Output)%3DF5A45203B9
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF5DEE502BF;IOAO_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F4B8D630167;CPIComponentsState { -> }
//## Uses: <unnamed>%3F4B91DC007D;IHIInterface { -> }

class EBIO_DLL_DECL CIOOutputAnalogInterface : public IPIOutputAnalogInterface  //## Inherits: <unnamed>%3DF5BEDF02FD
{
  //## begin CIOOutputAnalogInterface%3DF5BE8B0148.initialDeclarations preserve=yes
  //## end CIOOutputAnalogInterface%3DF5BE8B0148.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CIOOutputAnalogInterface%1039513443
      CIOOutputAnalogInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CIOOutputAnalogInterface();


    //## Other Operations (specified)
      //## Operation: Startup%1061910451
      //	DESCRIPTION
      //	Links the object to the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Startup ();

      //## Operation: Shutdown%1061910452
      //	DESCRIPTION
      //	Detaches the object from the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Shutdown ();

      //## Operation: ConnectionLost%1061910454
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

      //## Operation: ConnectionEstablished%1061910453
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: GetuiID%1039513446
      virtual UINT GetuiID ();

      //## Operation: SetValue%1039513447
      //	DESCRIPTION
      //	writes the given value to the analog output
      //
      //	PARAMETERS
      //	value to write
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetValue (INT p_iValue);

      //## Operation: GetValue%1039513448
      //	DESCRIPTION
      //	Returns the current value of the analog output
      //
      //	RETURNS
      //	async integer
      virtual CCOSyncObjectInt* GetValue ();

    // Additional Public Declarations
      //## begin CIOOutputAnalogInterface%3DF5BE8B0148.public preserve=yes
      //## end CIOOutputAnalogInterface%3DF5BE8B0148.public

  protected:
    // Additional Protected Declarations
      //## begin CIOOutputAnalogInterface%3DF5BE8B0148.protected preserve=yes
      //## end CIOOutputAnalogInterface%3DF5BE8B0148.protected

  private:
    //## Constructors (generated)
      CIOOutputAnalogInterface();

      CIOOutputAnalogInterface(const CIOOutputAnalogInterface &right);

    //## Assignment Operation (generated)
      const CIOOutputAnalogInterface & operator=(const CIOOutputAnalogInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CIOOutputAnalogInterface &right) const;

      bool operator!=(const CIOOutputAnalogInterface &right) const;

    // Data Members for Associations

      //## Association: EBIO (Analog- / Digital- In-/Output)::<unnamed>%3DF5BFE601B5
      //## Role: CIOOutputAnalogInterface::uiID%3DF5BFE603AA
      //## begin CIOOutputAnalogInterface::uiID%3DF5BFE603AA.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CIOOutputAnalogInterface::uiID%3DF5BFE603AA.role

      //## Association: EBIO (Analog- / Digital- In-/Output)::<unnamed>%3F4B8BA703B9
      //## Role: CIOOutputAnalogInterface::bHardwarePresent%3F4B8BA80187
      //## begin CIOOutputAnalogInterface::bHardwarePresent%3F4B8BA80187.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bHardwarePresent;
      //## end CIOOutputAnalogInterface::bHardwarePresent%3F4B8BA80187.role

      //## Association: EBIO (Analog- / Digital- In-/Output)::<unnamed>%40222CF6009B
      //## Role: CIOOutputAnalogInterface::dwNominalValue%40222CF6035B
      //## begin CIOOutputAnalogInterface::dwNominalValue%40222CF6035B.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwNominalValue;
      //## end CIOOutputAnalogInterface::dwNominalValue%40222CF6035B.role

    // Additional Private Declarations
      //## begin CIOOutputAnalogInterface%3DF5BE8B0148.private preserve=yes
      //## end CIOOutputAnalogInterface%3DF5BE8B0148.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CIOOutputAnalogInterface%3DF5BE8B0148.implementation preserve=yes
      //## end CIOOutputAnalogInterface%3DF5BE8B0148.implementation

};

//## begin CIOOutputAnalogInterface%3DF5BE8B0148.postscript preserve=yes
//## end CIOOutputAnalogInterface%3DF5BE8B0148.postscript

//## begin CIOSensorAnalogInterface%3DF5BE9E037A.preface preserve=yes
//## end CIOSensorAnalogInterface%3DF5BE9E037A.preface

//## Class: CIOSensorAnalogInterface%3DF5BE9E037A
//## Category: EBIO (Analog- / Digital- In-/Output)%3DF5A45203B9
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF5DEE9038A;IOAI_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F4B8D6C0186;CPIComponentsState { -> }
//## Uses: <unnamed>%3F4B91E50109;IHIInterface { -> }

class EBIO_DLL_DECL CIOSensorAnalogInterface : public IPISensorAnalogInterface  //## Inherits: <unnamed>%3DF5BEE30290
{
  //## begin CIOSensorAnalogInterface%3DF5BE9E037A.initialDeclarations preserve=yes
  //## end CIOSensorAnalogInterface%3DF5BE9E037A.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CIOSensorAnalogInterface%1039513449
      CIOSensorAnalogInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CIOSensorAnalogInterface();


    //## Other Operations (specified)
      //## Operation: Startup%1039513450
      //	DESCRIPTION
      //	Links the object to the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Startup ();

      //## Operation: Shutdown%1039513451
      //	DESCRIPTION
      //	Detaches the object from the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Shutdown ();

      //## Operation: ConnectionEstablished%1055744810
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1055744811
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

      //## Operation: GetuiID%1039513452
      virtual UINT GetuiID ();

      //## Operation: GetValue%1039513453
      //	DESCRIPTION
      //	Returns the current value of the analog input
      //
      //	RETURNS
      //	async integer
      virtual CCOSyncObjectInt* GetValue ();

    // Additional Public Declarations
      //## begin CIOSensorAnalogInterface%3DF5BE9E037A.public preserve=yes
      //## end CIOSensorAnalogInterface%3DF5BE9E037A.public

  protected:
    // Additional Protected Declarations
      //## begin CIOSensorAnalogInterface%3DF5BE9E037A.protected preserve=yes
      //## end CIOSensorAnalogInterface%3DF5BE9E037A.protected

  private:
    //## Constructors (generated)
      CIOSensorAnalogInterface();

      CIOSensorAnalogInterface(const CIOSensorAnalogInterface &right);

    //## Assignment Operation (generated)
      const CIOSensorAnalogInterface & operator=(const CIOSensorAnalogInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CIOSensorAnalogInterface &right) const;

      bool operator!=(const CIOSensorAnalogInterface &right) const;

    // Data Members for Associations

      //## Association: EBIO (Analog- / Digital- In-/Output)::<unnamed>%3DF5C57501A6
      //## Role: CIOSensorAnalogInterface::uiID%3DF5C57503BA
      //## begin CIOSensorAnalogInterface::uiID%3DF5C57503BA.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CIOSensorAnalogInterface::uiID%3DF5C57503BA.role

      //## Association: EBIO (Analog- / Digital- In-/Output)::<unnamed>%3F4B8C1E033C
      //## Role: CIOSensorAnalogInterface::bHardwarePresent%3F4B8C1F0203
      //## begin CIOSensorAnalogInterface::bHardwarePresent%3F4B8C1F0203.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bHardwarePresent;
      //## end CIOSensorAnalogInterface::bHardwarePresent%3F4B8C1F0203.role

    // Additional Private Declarations
      //## begin CIOSensorAnalogInterface%3DF5BE9E037A.private preserve=yes
      //## end CIOSensorAnalogInterface%3DF5BE9E037A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CIOSensorAnalogInterface%3DF5BE9E037A.implementation preserve=yes
      //## end CIOSensorAnalogInterface%3DF5BE9E037A.implementation

};

//## begin CIOSensorAnalogInterface%3DF5BE9E037A.postscript preserve=yes
//## end CIOSensorAnalogInterface%3DF5BE9E037A.postscript

//## begin CIOOutputDigitalInterface%3DF5BEB603B9.preface preserve=yes
//## end CIOOutputDigitalInterface%3DF5BEB603B9.preface

//## Class: CIOOutputDigitalInterface%3DF5BEB603B9
//## Category: EBIO (Analog- / Digital- In-/Output)%3DF5A45203B9
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF5DEE7031D;IODO_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F4B8D660138;CPIComponentsState { -> }
//## Uses: <unnamed>%3F4B91DF0000;IHIInterface { -> }
//## Uses: <unnamed>%3FA119D1038A;CIODigitalState { -> }

class EBIO_DLL_DECL CIOOutputDigitalInterface : public IPIOutputDigitalInterface  //## Inherits: <unnamed>%3DF5BEE60203
{
  //## begin CIOOutputDigitalInterface%3DF5BEB603B9.initialDeclarations preserve=yes
  //## end CIOOutputDigitalInterface%3DF5BEB603B9.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CIOOutputDigitalInterface%1039513454
      CIOOutputDigitalInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CIOOutputDigitalInterface();


    //## Other Operations (specified)
      //## Operation: Startup%1039513455
      //	DESCRIPTION
      //	Links the object to the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Startup ();

      //## Operation: Shutdown%1039513456
      //	DESCRIPTION
      //	Detaches the object from the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Shutdown ();

      //## Operation: ConnectionEstablished%1055744812
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1055744813
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

      //## Operation: GetuiID%1039513457
      virtual UINT GetuiID ();

      //## Operation: Set%1039513458
      //	DESCRIPTIONS
      //	Activates the current output
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Set ();

      //## Operation: Clear%1039513459
      //	DESCRIPTIONS
      //	Releases the current output
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Clear ();

      //## Operation: IsActive%1039513460
      //	DESCRIPTIONS
      //	Checks, whether the current output is set
      //
      //	RETURNS
      //	async bool
      virtual CCOSyncObjectBool* IsActive ();

      //## Operation: SetPolarity%1039513461
      //	DESCRIPTION
      //	Sets the output's polarity
      //
      //	PARAMETERS
      //	polarity of the output, either high or low
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetPolarity (EPIPolarity p_ePolarity);

    // Additional Public Declarations
      //## begin CIOOutputDigitalInterface%3DF5BEB603B9.public preserve=yes
      //## end CIOOutputDigitalInterface%3DF5BEB603B9.public

  protected:
    // Additional Protected Declarations
      //## begin CIOOutputDigitalInterface%3DF5BEB603B9.protected preserve=yes
      //## end CIOOutputDigitalInterface%3DF5BEB603B9.protected

  private:
    //## Constructors (generated)
      CIOOutputDigitalInterface();

      CIOOutputDigitalInterface(const CIOOutputDigitalInterface &right);

    //## Assignment Operation (generated)
      const CIOOutputDigitalInterface & operator=(const CIOOutputDigitalInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CIOOutputDigitalInterface &right) const;

      bool operator!=(const CIOOutputDigitalInterface &right) const;


    //## Other Operations (specified)
      //## Operation: CheckPolarity%1071671742
      bool CheckPolarity (const bool p_bIsActive);

    // Data Members for Associations

      //## Association: EBIO (Analog- / Digital- In-/Output)::<unnamed>%3DF5C57800DB
      //## Role: CIOOutputDigitalInterface::uiID%3DF5C57802C0
      //## begin CIOOutputDigitalInterface::uiID%3DF5C57802C0.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CIOOutputDigitalInterface::uiID%3DF5C57802C0.role

      //## Association: EBIO (Analog- / Digital- In-/Output)::<unnamed>%3F4B8C220399
      //## Role: CIOOutputDigitalInterface::bHardwarePresent%3F4B8C230139
      //## begin CIOOutputDigitalInterface::bHardwarePresent%3F4B8C230139.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bHardwarePresent;
      //## end CIOOutputDigitalInterface::bHardwarePresent%3F4B8C230139.role

      //## Association: EBIO (Analog- / Digital- In-/Output)::<unnamed>%40221B52009B
      //## Role: CIOOutputDigitalInterface::bNomialState%40221B52032B
      //## begin CIOOutputDigitalInterface::bNomialState%40221B52032B.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bNomialState;
      //## end CIOOutputDigitalInterface::bNomialState%40221B52032B.role

      //## Association: EBIO (Analog- / Digital- In-/Output)::<unnamed>%40221BAB01E3
      //## Role: CIOOutputDigitalInterface::ePolarity%40221BAC003E
      //## begin CIOOutputDigitalInterface::ePolarity%40221BAC003E.role preserve=no  public: EPIPolarity {1..1 -> 1..1VFHN}
      EPIPolarity m_ePolarity;
      //## end CIOOutputDigitalInterface::ePolarity%40221BAC003E.role

    // Additional Private Declarations
      //## begin CIOOutputDigitalInterface%3DF5BEB603B9.private preserve=yes
      //## end CIOOutputDigitalInterface%3DF5BEB603B9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CIOOutputDigitalInterface%3DF5BEB603B9.implementation preserve=yes
      //## end CIOOutputDigitalInterface%3DF5BEB603B9.implementation

};

//## begin CIOOutputDigitalInterface%3DF5BEB603B9.postscript preserve=yes
//## end CIOOutputDigitalInterface%3DF5BEB603B9.postscript

//## begin CIOSensorDigitalInterface%3DF5BECD030D.preface preserve=yes
//## end CIOSensorDigitalInterface%3DF5BECD030D.preface

//## Class: CIOSensorDigitalInterface%3DF5BECD030D
//## Category: EBIO (Analog- / Digital- In-/Output)%3DF5A45203B9
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF5DEEB038A;IODI_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F4B8D69006D;CPIComponentsState { -> }
//## Uses: <unnamed>%3F4B91E100BB;IHIInterface { -> }
//## Uses: <unnamed>%3FA119E402AF;CIODigitalState { -> }

class EBIO_DLL_DECL CIOSensorDigitalInterface : public IPISensorDigitalInterface  //## Inherits: <unnamed>%3DF5BEE9007D
{
  //## begin CIOSensorDigitalInterface%3DF5BECD030D.initialDeclarations preserve=yes
  //## end CIOSensorDigitalInterface%3DF5BECD030D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CIOSensorDigitalInterface%1039513462
      CIOSensorDigitalInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CIOSensorDigitalInterface();


    //## Other Operations (specified)
      //## Operation: Startup%1039513463
      //	DESCRIPTION
      //	Links the object to the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Startup ();

      //## Operation: Shutdown%1039513464
      //	DESCRIPTION
      //	Detaches the object from the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Shutdown ();

      //## Operation: ConnectionEstablished%1055744814
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1055744815
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

      //## Operation: GetuiID%1039513465
      virtual UINT GetuiID ();

      //## Operation: IsActive%1039513466
      //	DESCRIPTION
      //	returns the digital value from the sensor.
      //
      //	RETURNS
      //	async true, if the sensor is active
      virtual CCOSyncObjectBool* IsActive ();

      //## Operation: SetPolarity%1039513467
      //	DESCRIPTION
      //	Sets the sensor's polarity
      //
      //	PARAMETERS
      //	polarity of the sensor, either high or low
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetPolarity (EPIPolarity p_ePolarity);

    // Additional Public Declarations
      //## begin CIOSensorDigitalInterface%3DF5BECD030D.public preserve=yes
      //## end CIOSensorDigitalInterface%3DF5BECD030D.public

  protected:
    // Additional Protected Declarations
      //## begin CIOSensorDigitalInterface%3DF5BECD030D.protected preserve=yes
      //## end CIOSensorDigitalInterface%3DF5BECD030D.protected

  private:
    //## Constructors (generated)
      CIOSensorDigitalInterface();

      CIOSensorDigitalInterface(const CIOSensorDigitalInterface &right);

    //## Assignment Operation (generated)
      const CIOSensorDigitalInterface & operator=(const CIOSensorDigitalInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CIOSensorDigitalInterface &right) const;

      bool operator!=(const CIOSensorDigitalInterface &right) const;


    //## Other Operations (specified)
      //## Operation: CheckPolarity%1071671741
      bool CheckPolarity (const bool p_bIsActive);

    // Data Members for Associations

      //## Association: EBIO (Analog- / Digital- In-/Output)::<unnamed>%3DF5C57B00FA
      //## Role: CIOSensorDigitalInterface::uiID%3DF5C57B02D0
      //## begin CIOSensorDigitalInterface::uiID%3DF5C57B02D0.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CIOSensorDigitalInterface::uiID%3DF5C57B02D0.role

      //## Association: EBIO (Analog- / Digital- In-/Output)::<unnamed>%3F4B8C270167
      //## Role: CIOSensorDigitalInterface::bHardwarePresent%3F4B8C27033D
      //## begin CIOSensorDigitalInterface::bHardwarePresent%3F4B8C27033D.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bHardwarePresent;
      //## end CIOSensorDigitalInterface::bHardwarePresent%3F4B8C27033D.role

      //## Association: EBIO (Analog- / Digital- In-/Output)::<unnamed>%40221D1D009B
      //## Role: CIOSensorDigitalInterface::ePolarity%40221D1D02FC
      //## begin CIOSensorDigitalInterface::ePolarity%40221D1D02FC.role preserve=no  public: EPIPolarity {1..1 -> 1..1VFHN}
      EPIPolarity m_ePolarity;
      //## end CIOSensorDigitalInterface::ePolarity%40221D1D02FC.role

    // Additional Private Declarations
      //## begin CIOSensorDigitalInterface%3DF5BECD030D.private preserve=yes
      //## end CIOSensorDigitalInterface%3DF5BECD030D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CIOSensorDigitalInterface%3DF5BECD030D.implementation preserve=yes
      //## end CIOSensorDigitalInterface%3DF5BECD030D.implementation

};

//## begin CIOSensorDigitalInterface%3DF5BECD030D.postscript preserve=yes
//## end CIOSensorDigitalInterface%3DF5BECD030D.postscript

// Class CIOOutputAnalogInterface 

// Class CIOSensorAnalogInterface 

// Class CIOOutputDigitalInterface 

// Class CIOSensorDigitalInterface 

//## begin module%3DF5AFAF0232.epilog preserve=yes
//## end module%3DF5AFAF0232.epilog


#endif
