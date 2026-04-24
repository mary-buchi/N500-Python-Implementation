//## begin module%3DA52EE301A8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA52EE301A8.cm

//## begin module%3DA52EE301A8.cp preserve=no
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
//## end module%3DA52EE301A8.cp

//## Module: EBPIintf%3DA52EE301A8; Package specification
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPIintf.h

#ifndef EBPIintf_h
#define EBPIintf_h 1

//## begin module%3DA52EE301A8.additionalIncludes preserve=no
//## end module%3DA52EE301A8.additionalIncludes

//## begin module%3DA52EE301A8.includes preserve=yes
//## end module%3DA52EE301A8.includes

// EBPIenum
#include "EBPIenum.h"
// EBPItype
#include "EBPItype.h"
// EBCOsypr
#include "EBCOsypr.h"
// EBCOintf
#include "EBCOintf.h"

class EBCO_DLL_DECL CCOSyncObject;

//## begin module%3DA52EE301A8.declarations preserve=no
//## end module%3DA52EE301A8.declarations

//## begin module%3DA52EE301A8.additionalDeclarations preserve=yes
//## end module%3DA52EE301A8.additionalDeclarations


//## begin IPIStepperMotorInterface%3DA52EF90225.preface preserve=yes
//## end IPIStepperMotorInterface%3DA52EF90225.preface

//## Class: IPIStepperMotorInterface%3DA52EF90225
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAA5EF903BB;CCOSyncObject { -> F}
//## Uses: <unnamed>%3DAA6C350273;CCOSyncObjectInt { -> }
//## Uses: <unnamed>%3DB50C6500FC;CPIObjIdentification { -> F}
//## Uses: <unnamed>%3DB50E230215;EPIMotorPolarity { -> }
//## Uses: <unnamed>%3DB519E7006F;CCOSyncObjectIntArray { -> }

class EBPI_DLL_DECL IPIStepperMotorInterface : public ICOAsyncInterface  //## Inherits: <unnamed>%3DA6BBFA0136
{
  //## begin IPIStepperMotorInterface%3DA52EF90225.initialDeclarations preserve=yes
  //## end IPIStepperMotorInterface%3DA52EF90225.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPIStepperMotorInterface%1034329209
      IPIStepperMotorInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPIStepperMotorInterface();


    //## Other Operations (specified)
      //## Operation: MoveAbsolute%1035273349
      //	DESCRIPTION
      //	Moves the motor to the given position using the absolute
      //	scale.
      //	All distances and positions are in steps
      //
      //	PARAMETERS
      //	p_iTargetPosition: target position where the motor will
      //	drive to
      //	p_iSearchDistance: distance before target position is
      //	reached where the motor will drive using the search speed
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* MoveAbsolute (INT p_iTargetPosition, INT p_iSearchDistance = 0) = 0;

      //## Operation: MoveRelative%1035273350
      //	DESCRIPTION
      //	Moves the motor the given distance relative to the
      //	current position
      //	All distances and positions are in steps
      //
      //	PARAMETERS
      //	p_iTotalDistance:  relative distance the motor will move
      //	p_iSearchDistance: distance before target position is
      //	reached where the motor will drive using the search speed
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* MoveRelative (INT p_iTotalDistance, INT p_iSearchDistance = 0) = 0;

      //## Operation: MoveManual%1035273351
      //	DESCRIPTION
      //	Starts manual moving towards the given end position.
      //
      //	PARAMETERS
      //	- p_iEndPosition: maximum position of the manual move
      //	- p_uiSpeed: speed in %
      //
      //	RETURNS
      //	asynchronous void, signalling that the end position is
      //	reached
      virtual CCOSyncObject* MoveManual (INT p_iEndPosition, UINT p_uiSpeed) = 0;

      //## Operation: GetPosition%1034575079
      //	DESCRIPTION
      //	Reads the current position of the motor
      //	All distances and positions are in steps
      //
      //	RETURNS
      //	async int
      virtual CCOSyncObjectInt* GetPosition () = 0;

      //## Operation: Stop%1035273352
      //	DESCRIPTION
      //	Stops the motor using the predefined slow down slope.
      //
      //	RETURNS
      //	asynchronous void
      virtual CCOSyncObject* Stop () = 0;

      //## Operation: StopImmediately%1035273353
      //	DESCRIPTION
      //	Stops the motor immediately.
      //
      //	RETURNS
      //	asynchronous void
      virtual CCOSyncObject* StopImmediately () = 0;

      //## Operation: SetProfile%1035273354
      //	DESCRIPTION
      //	Configurates the motor parameters to the motor object
      //	All speed parameters are in [Hz].
      //	All current values are in [mA].
      //
      //	PARAMETERS
      //	- p_MotorProfile: Motor profile data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetProfile (CPIStepperMotorProfile* p_pProfile) = 0;

      //## Operation: SetSpeed%1035273355
      //	DESCRIPTION
      //	Sets the currently used speed. The value is in
      //	percentage of the normal speed frequency set during
      //	profile configuration
      //
      //	PARAMETER
      //	- p_uiSpeed: speed percentage
      //
      //	RETURNS
      //	async: previously set speed
      virtual CCOSyncObjectInt* SetSpeed (UINT p_uiSpeed = 100) = 0;

      //## Operation: LimitAdd%1035273356
      //	DESCRIPTION
      //	adds a limit to the motor.
      //
      //	PARAMETERS
      //	p_pSensor: identification of the limit sensor
      //	p_eLimitCharacteristics: falling or raising edge
      //	configuration
      //	p_eLimitAction: underlying action after a limit has been
      //	hit
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* LimitAdd (CPIObjIdentification* p_pSensorID, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction) = 0;

      //## Operation: LimitConfig%1035273357
      //	DESCRIPTION
      //	configures a specific limit
      //
      //	PARAMETERS
      //	p_pSensor: identification of the limit sensor
      //	p_eLimitCharacteristics:falling or raising edge
      //	configuration
      //	p_eLimitAction: underlying action after a limit has been
      //	hit
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* LimitConfig (CPIObjIdentification* p_pSensorID, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction) = 0;

      //## Operation: LimitActivate%1035273358
      //	DESCRIPTION
      //	disables or enables all limits of a motor according to
      //	their configuration
      virtual CCOSyncObject* LimitActivate () = 0;

      //## Operation: LimitDeactivate%1035273359
      //	DESCRIPTION
      //	disables or enables all limits of a motor according to
      //	their configuration
      virtual CCOSyncObject* LimitDeactivate () = 0;

      //## Operation: Home%1035273360
      //	DESCRIPTION
      //	detects the raising or falling slope of previously set
      //	in a reproducable mannor
      //
      //	PARAMETERS
      //	true, if the home sequence is started into the positive
      //	direction of the axis
      //
      //	RETURNS
      //	asynchronous int(homing steps)
      virtual CCOSyncObjectInt* Home (const EPIMotorPolarity p_eMotorPolarity, CPIObjIdentification* p_pHomeLimitID) = 0;

      //## Operation: Home%1193077629
      //	DESCRIPTION
      //	detects the raising or falling slope of previously set
      //	in a reproducable mannor
      //
      //	PARAMETERS
      //	- direction for "fast-finding" the home limit
      //	- true, if the limit ought to be slowly approached from
      //	the opposite direction
      //	- home sensor ID
      //
      //	RETURNS
      //	asynchronous int(homing steps)
      virtual CCOSyncObjectInt* Home (const EPIMotorPolarity p_eFastFindDirection, const bool p_bSearchLimitFromOpposite, CPIObjIdentification* p_pHomeLimitID) = 0;

      //## Operation: HomeSetPosition%1035273361
      //	DESCRIPTION
      //	assigns a logical corrdinate to the home position. This
      //	will affect all further absolute movements
      //
      //	PARAMETERS
      //	position in um assigned to the home position
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* HomeSetPosition (INT p_iPosition) = 0;

      //## Operation: LimitGetFootPrint%1035273362
      //	DESCRIPTION
      //	returns the position (steps) of detected soft limit
      //	edges of the last movement
      //
      //	RETURNS
      //	asynchronous : integer array with positions
      virtual CCOSyncObjectIntArray* LimitGetFootPrint () = 0;

      //## Operation: SetConfig%1048171419
      //	DESCRIPTION
      //	Configurates the motor parameters to the motor object
      //	All speed parameters are in [Hz].
      //	All current values are in [mA].
      //
      //	PARAMETERS
      //	- p_MotorProfile: Motor profile data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetConfig (CPIStepperMotorConfig* p_pConfig) = 0;

    // Additional Public Declarations
      //## begin IPIStepperMotorInterface%3DA52EF90225.public preserve=yes
      //## end IPIStepperMotorInterface%3DA52EF90225.public

  protected:
    // Additional Protected Declarations
      //## begin IPIStepperMotorInterface%3DA52EF90225.protected preserve=yes
      //## end IPIStepperMotorInterface%3DA52EF90225.protected

  private:
    //## Constructors (generated)
      IPIStepperMotorInterface();

      IPIStepperMotorInterface(const IPIStepperMotorInterface &right);

    //## Assignment Operation (generated)
      const IPIStepperMotorInterface & operator=(const IPIStepperMotorInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IPIStepperMotorInterface &right) const;

      bool operator!=(const IPIStepperMotorInterface &right) const;

    // Additional Private Declarations
      //## begin IPIStepperMotorInterface%3DA52EF90225.private preserve=yes
      //## end IPIStepperMotorInterface%3DA52EF90225.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPIStepperMotorInterface%3DA52EF90225.implementation preserve=yes
      //## end IPIStepperMotorInterface%3DA52EF90225.implementation

};

//## begin IPIStepperMotorInterface%3DA52EF90225.postscript preserve=yes
//## end IPIStepperMotorInterface%3DA52EF90225.postscript

//## begin IPIMeasurementChannelInterface%3DAAAC33012D.preface preserve=yes
//## end IPIMeasurementChannelInterface%3DAAAC33012D.preface

//## Class: IPIMeasurementChannelInterface%3DAAAC33012D
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAFABE50124;CPISyncObjDataPackage { -> }

class EBPI_DLL_DECL IPIMeasurementChannelInterface : public ICOAsyncInterface  //## Inherits: <unnamed>%3DAAAC5C037F
{
  //## begin IPIMeasurementChannelInterface%3DAAAC33012D.initialDeclarations preserve=yes
  //## end IPIMeasurementChannelInterface%3DAAAC33012D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPIMeasurementChannelInterface%1034575106
      IPIMeasurementChannelInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPIMeasurementChannelInterface();


    //## Other Operations (specified)
      //## Operation: SetProfile%1035789467
      //	DESCRIPTION
      //	Configures the profile of the measurement channel
      //
      //	PARAMETERS
      //	Profile data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetProfile (CPIMeasurementChannelProfile* p_pProfile) = 0;

      //## Operation: Initialize%1035789468
      //	DESCRIPTION
      //	Initializes the measurement channel (DMA transfer)
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Initialize () = 0;

      //## Operation: Start%1035789469
      //	DESCRIPTION
      //	Starts the transfer of measuremen data packages. After
      //	Start has been called GetDataPackage may be called.
      //
      //	PARAMETERS
      //	identification of the ongoing measurement cycle
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Start (UINT p_uiCycleID) = 0;

      //## Operation: Stop%1035789470
      //	DESCRIPTION
      //	Stops the measurement process.
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Stop () = 0;

      //## Operation: GetDataPackage%1034922740
      //	DESCRIPTION
      //	transfers a data package to the PC. The datapackage can
      //	be of any size and consists always of the same amount of
      //	bytes in both data streams (laser and detector).
      //
      //	RETURNS
      //	async CPIMeasurementChannelDataPackage
      virtual CPISyncObjDataPackage* GetDataPackage () = 0;

    // Additional Public Declarations
      //## begin IPIMeasurementChannelInterface%3DAAAC33012D.public preserve=yes
      //## end IPIMeasurementChannelInterface%3DAAAC33012D.public

  protected:
    // Additional Protected Declarations
      //## begin IPIMeasurementChannelInterface%3DAAAC33012D.protected preserve=yes
      //## end IPIMeasurementChannelInterface%3DAAAC33012D.protected

  private:
    //## Constructors (generated)
      IPIMeasurementChannelInterface();

      IPIMeasurementChannelInterface(const IPIMeasurementChannelInterface &right);

    //## Assignment Operation (generated)
      const IPIMeasurementChannelInterface & operator=(const IPIMeasurementChannelInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IPIMeasurementChannelInterface &right) const;

      bool operator!=(const IPIMeasurementChannelInterface &right) const;

    // Additional Private Declarations
      //## begin IPIMeasurementChannelInterface%3DAAAC33012D.private preserve=yes
      //## end IPIMeasurementChannelInterface%3DAAAC33012D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPIMeasurementChannelInterface%3DAAAC33012D.implementation preserve=yes
      //## end IPIMeasurementChannelInterface%3DAAAC33012D.implementation

};

//## begin IPIMeasurementChannelInterface%3DAAAC33012D.postscript preserve=yes
//## end IPIMeasurementChannelInterface%3DAAAC33012D.postscript

//## begin IPIPersistentObjInterface%3DB8095A0065.preface preserve=yes
//## end IPIPersistentObjInterface%3DB8095A0065.preface

//## Class: IPIPersistentObjInterface%3DB8095A0065
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F967A01021E;EPILifeTimeCounter { -> }
//## Uses: <unnamed>%3F967A94001A;CPIPersistentConfig { -> }
//## Uses: <unnamed>%3F967AAA0356;CPIPersistentIdent { -> }
//## Uses: <unnamed>%3F967DBA0191;CPIPersistentLifeTimeCounter { -> }
//## Uses: <unnamed>%3F967DCF027B;CPISyncObjListPersistentItems { -> }

class EBPI_DLL_DECL IPIPersistentObjInterface : public ICOAsyncInterface  //## Inherits: <unnamed>%3DD105B20165
{
  //## begin IPIPersistentObjInterface%3DB8095A0065.initialDeclarations preserve=yes
  //## end IPIPersistentObjInterface%3DB8095A0065.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPIPersistentObjInterface%1037103456
      IPIPersistentObjInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPIPersistentObjInterface();


    //## Other Operations (specified)
      //## Operation: WriteParameter%1066808239
      //	DESCRIPTION
      //	Writes a single parameter into the persistent memory.
      //
      //	PARAMETERS
      //	- Parameter to write
      //	- Parameter location
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* WriteParameter (CPIPersistentPara* p_pParameter) = 0;

      //## Operation: ReadParameters%1035528317
      //	DESCRIPTION
      //	Returns a list with CPIPersistentParameter Objects,
      //	describing the complete set of persistent parameter
      //	information
      //
      //	PARAMETERS
      //
      //
      //	RETURNS
      //	CPISyncObjListParameter*
      virtual CPISyncObjListPersistentItems* ReadParameters () = 0;

      //## Operation: StartMonitoring%1066717294
      //	DESCRIPTION
      //	Starts counting operating data. e.g. (number of scans,
      //	operating duration)
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject * StartMonitoring (EPILifeTimeCounter p_eDevice) = 0;

      //## Operation: StopMonitoring%1066717295
      //	DESCRIPTION
      //	Stops counting operating data. e.g. (number of scans,
      //	operating duration)
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject * StopMonitoring (EPILifeTimeCounter p_eDevice) = 0;

      //## Operation: Save%1035528314
      //	DESCRIPTION
      //	Saves data (parameters, operating data, identifications)
      //	to eeprom.
      //
      //	RETURNS
      //	async - void
      virtual CCOSyncObject* Save () = 0;

      //## Operation: ReadLifeTimeCounter%1066717296
      //	DESCRIPTION
      //	Reads the value of the specified operating data counter
      //	from the persistent object store
      //
      //	PARAMETERS
      //	Operating data counter to read
      //
      //	RETURNS
      //	async: int [s] or [number of scans]
      virtual CCOSyncObjectInt* ReadLifeTimeCounter (EPILifeTimeCounter p_eCounter) = 0;

      //## Operation: WriteLifeTimeCounter%1050325540
      //	DESCRIPTION
      //	Writes the value of the specified operating data counter
      //	to the persistent object store
      //
      //	PARAMETERS
      //	- Operating data counter to write
      //	- Value to write
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* WriteLifeTimeCounter (EPILifeTimeCounter p_eCounter, UINT p_uiValue) = 0;

      //## Operation: ReadIdentifications%1050325539
      //	DESCRIPTION
      //	Reads all identifications from the persistent object
      //	store.
      //
      //	PARAMETERS
      //
      //	RETURNS
      //	CPISyncObjListIPersistentItems*
      virtual CPISyncObjListPersistentItems* ReadIdentifications () = 0;

      //## Operation: WriteIdentification%1066717297
      //	DESCRIPTION
      //	Writes the value of the specified identification to the
      //	persistent object store
      //
      //	PARAMETERS
      //	- PersistentItem
      //	- Parameter item location
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* WriteIdentification (CPIPersistentIdent* p_oIdentification) = 0;

      //## Operation: SetConfig%1066813274
      //	DESCRIPTION
      //	Configurates the persistent object parameters
      //
      //	PARAMETERS
      //	p_PersistentConfig
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetConfig (CPIPersistentConfig* p_pConfig) = 0;

      //## Operation: Reset%1072788292
      //	DESCRIPTION
      //	Resets a eprom section
      //
      //	PARAMETERS
      //	p_eSection
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Reset (EPIEpromSection p_eSection) = 0;

      //## Operation: MeasurementCellUndocked%1080141459
      //	DESCRIPTION
      //	tells the persistent object manager that the measurement
      //	cell has been undocked, meaning that the eprom has gone
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* MeasurementCellUndocked () = 0;

    // Additional Public Declarations
      //## begin IPIPersistentObjInterface%3DB8095A0065.public preserve=yes
      //## end IPIPersistentObjInterface%3DB8095A0065.public

  protected:
    // Additional Protected Declarations
      //## begin IPIPersistentObjInterface%3DB8095A0065.protected preserve=yes
      //## end IPIPersistentObjInterface%3DB8095A0065.protected

  private:
    //## Constructors (generated)
      IPIPersistentObjInterface();

      IPIPersistentObjInterface(const IPIPersistentObjInterface &right);

    //## Assignment Operation (generated)
      const IPIPersistentObjInterface & operator=(const IPIPersistentObjInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IPIPersistentObjInterface &right) const;

      bool operator!=(const IPIPersistentObjInterface &right) const;

    // Additional Private Declarations
      //## begin IPIPersistentObjInterface%3DB8095A0065.private preserve=yes
      //## end IPIPersistentObjInterface%3DB8095A0065.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPIPersistentObjInterface%3DB8095A0065.implementation preserve=yes
      //## end IPIPersistentObjInterface%3DB8095A0065.implementation

};

//## begin IPIPersistentObjInterface%3DB8095A0065.postscript preserve=yes
//## end IPIPersistentObjInterface%3DB8095A0065.postscript

//## begin IPISensorAnalogInterface%3DB9120A021B.preface preserve=yes
//## end IPISensorAnalogInterface%3DB9120A021B.preface

//## Class: IPISensorAnalogInterface%3DB9120A021B
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL IPISensorAnalogInterface : public ICOSyncInterface  //## Inherits: <unnamed>%3DB92FB9018F
{
  //## begin IPISensorAnalogInterface%3DB9120A021B.initialDeclarations preserve=yes
  //## end IPISensorAnalogInterface%3DB9120A021B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPISensorAnalogInterface%1039527541
      IPISensorAnalogInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPISensorAnalogInterface();


    //## Other Operations (specified)
      //## Operation: GetValue%1035528324
      //	DESCRIPTION
      //	Returns the value of the analog sensor
      //
      //	RETURNS
      //	async integer
      virtual CCOSyncObjectInt* GetValue () = 0;

    // Additional Public Declarations
      //## begin IPISensorAnalogInterface%3DB9120A021B.public preserve=yes
      //## end IPISensorAnalogInterface%3DB9120A021B.public

  protected:
    // Additional Protected Declarations
      //## begin IPISensorAnalogInterface%3DB9120A021B.protected preserve=yes
      //## end IPISensorAnalogInterface%3DB9120A021B.protected

  private:
    //## Constructors (generated)
      IPISensorAnalogInterface();

      IPISensorAnalogInterface(const IPISensorAnalogInterface &right);

    //## Assignment Operation (generated)
      const IPISensorAnalogInterface & operator=(const IPISensorAnalogInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IPISensorAnalogInterface &right) const;

      bool operator!=(const IPISensorAnalogInterface &right) const;

    // Additional Private Declarations
      //## begin IPISensorAnalogInterface%3DB9120A021B.private preserve=yes
      //## end IPISensorAnalogInterface%3DB9120A021B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPISensorAnalogInterface%3DB9120A021B.implementation preserve=yes
      //## end IPISensorAnalogInterface%3DB9120A021B.implementation

};

//## begin IPISensorAnalogInterface%3DB9120A021B.postscript preserve=yes
//## end IPISensorAnalogInterface%3DB9120A021B.postscript

//## begin IPISensorDigitalInterface%3DB928DC0121.preface preserve=yes
//## end IPISensorDigitalInterface%3DB928DC0121.preface

//## Class: IPISensorDigitalInterface%3DB928DC0121
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DB929E902D7;EPIPolarity { -> }

class EBPI_DLL_DECL IPISensorDigitalInterface : public ICOSyncInterface  //## Inherits: <unnamed>%3DB92FBB0279
{
  //## begin IPISensorDigitalInterface%3DB928DC0121.initialDeclarations preserve=yes
  //## end IPISensorDigitalInterface%3DB928DC0121.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPISensorDigitalInterface%1039527542
      IPISensorDigitalInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPISensorDigitalInterface();


    //## Other Operations (specified)
      //## Operation: IsActive%1035528325
      //	DESCRIPTION
      //	returns the digital value from the sensor.
      //
      //	RETURNS
      //	async true, if the sensor is active
      virtual CCOSyncObjectBool* IsActive () = 0;

      //## Operation: SetPolarity%1035528326
      //	DESCRIPTION
      //	Sets the sensor's polarity
      //
      //	PARAMETERS
      //	polarity of the sensor, either high or low
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetPolarity (EPIPolarity p_ePolarity) = 0;

    // Additional Public Declarations
      //## begin IPISensorDigitalInterface%3DB928DC0121.public preserve=yes
      //## end IPISensorDigitalInterface%3DB928DC0121.public

  protected:
    // Additional Protected Declarations
      //## begin IPISensorDigitalInterface%3DB928DC0121.protected preserve=yes
      //## end IPISensorDigitalInterface%3DB928DC0121.protected

  private:
    //## Constructors (generated)
      IPISensorDigitalInterface();

      IPISensorDigitalInterface(const IPISensorDigitalInterface &right);

    //## Assignment Operation (generated)
      const IPISensorDigitalInterface & operator=(const IPISensorDigitalInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IPISensorDigitalInterface &right) const;

      bool operator!=(const IPISensorDigitalInterface &right) const;

    // Additional Private Declarations
      //## begin IPISensorDigitalInterface%3DB928DC0121.private preserve=yes
      //## end IPISensorDigitalInterface%3DB928DC0121.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPISensorDigitalInterface%3DB928DC0121.implementation preserve=yes
      //## end IPISensorDigitalInterface%3DB928DC0121.implementation

};

//## begin IPISensorDigitalInterface%3DB928DC0121.postscript preserve=yes
//## end IPISensorDigitalInterface%3DB928DC0121.postscript

//## begin IPIOutputAnalogInterface%3DB92AB900C4.preface preserve=yes
//## end IPIOutputAnalogInterface%3DB92AB900C4.preface

//## Class: IPIOutputAnalogInterface%3DB92AB900C4
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL IPIOutputAnalogInterface : public ICOSyncInterface  //## Inherits: <unnamed>%3DB92FBE0085
{
  //## begin IPIOutputAnalogInterface%3DB92AB900C4.initialDeclarations preserve=yes
  //## end IPIOutputAnalogInterface%3DB92AB900C4.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPIOutputAnalogInterface%1039527543
      IPIOutputAnalogInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPIOutputAnalogInterface();


    //## Other Operations (specified)
      //## Operation: SetValue%1035528328
      //	DESCRIPTION
      //	writes the given value to the analog output
      //
      //	PARAMETERS
      //	value to write
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetValue (INT p_iValue) = 0;

      //## Operation: GetValue%1035528329
      //	DESCRIPTION
      //	Returns the current value of the analog output
      //
      //	RETURNS
      //	async integer
      virtual CCOSyncObjectInt* GetValue () = 0;

    // Additional Public Declarations
      //## begin IPIOutputAnalogInterface%3DB92AB900C4.public preserve=yes
      //## end IPIOutputAnalogInterface%3DB92AB900C4.public

  protected:
    // Additional Protected Declarations
      //## begin IPIOutputAnalogInterface%3DB92AB900C4.protected preserve=yes
      //## end IPIOutputAnalogInterface%3DB92AB900C4.protected

  private:
    //## Constructors (generated)
      IPIOutputAnalogInterface();

      IPIOutputAnalogInterface(const IPIOutputAnalogInterface &right);

    //## Assignment Operation (generated)
      const IPIOutputAnalogInterface & operator=(const IPIOutputAnalogInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IPIOutputAnalogInterface &right) const;

      bool operator!=(const IPIOutputAnalogInterface &right) const;

    // Additional Private Declarations
      //## begin IPIOutputAnalogInterface%3DB92AB900C4.private preserve=yes
      //## end IPIOutputAnalogInterface%3DB92AB900C4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPIOutputAnalogInterface%3DB92AB900C4.implementation preserve=yes
      //## end IPIOutputAnalogInterface%3DB92AB900C4.implementation

};

//## begin IPIOutputAnalogInterface%3DB92AB900C4.postscript preserve=yes
//## end IPIOutputAnalogInterface%3DB92AB900C4.postscript

//## begin IPIOutputDigitalInterface%3DB92BE30121.preface preserve=yes
//## end IPIOutputDigitalInterface%3DB92BE30121.preface

//## Class: IPIOutputDigitalInterface%3DB92BE30121
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL IPIOutputDigitalInterface : public ICOSyncInterface  //## Inherits: <unnamed>%3DB92FC70335
{
  //## begin IPIOutputDigitalInterface%3DB92BE30121.initialDeclarations preserve=yes
  //## end IPIOutputDigitalInterface%3DB92BE30121.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPIOutputDigitalInterface%1039527544
      IPIOutputDigitalInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPIOutputDigitalInterface();


    //## Other Operations (specified)
      //## Operation: Set%1035528330
      //	DESCRIPTIONS
      //	Activates the current output
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Set () = 0;

      //## Operation: Clear%1035528331
      //	DESCRIPTIONS
      //	Releases the current output
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Clear () = 0;

      //## Operation: IsActive%1037346567
      //	DESCRIPTIONS
      //	Checks, whether the current output is set
      //
      //	RETURNS
      //	async bool
      virtual CCOSyncObjectBool* IsActive () = 0;

      //## Operation: SetPolarity%1035528332
      //	DESCRIPTION
      //	Sets the output's polarity
      //
      //	PARAMETERS
      //	polarity of the output, either high or low
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetPolarity (EPIPolarity p_ePolarity) = 0;

    // Additional Public Declarations
      //## begin IPIOutputDigitalInterface%3DB92BE30121.public preserve=yes
      //## end IPIOutputDigitalInterface%3DB92BE30121.public

  protected:
    // Additional Protected Declarations
      //## begin IPIOutputDigitalInterface%3DB92BE30121.protected preserve=yes
      //## end IPIOutputDigitalInterface%3DB92BE30121.protected

  private:
    //## Constructors (generated)
      IPIOutputDigitalInterface();

      IPIOutputDigitalInterface(const IPIOutputDigitalInterface &right);

    //## Assignment Operation (generated)
      const IPIOutputDigitalInterface & operator=(const IPIOutputDigitalInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IPIOutputDigitalInterface &right) const;

      bool operator!=(const IPIOutputDigitalInterface &right) const;

    // Additional Private Declarations
      //## begin IPIOutputDigitalInterface%3DB92BE30121.private preserve=yes
      //## end IPIOutputDigitalInterface%3DB92BE30121.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPIOutputDigitalInterface%3DB92BE30121.implementation preserve=yes
      //## end IPIOutputDigitalInterface%3DB92BE30121.implementation

};

//## begin IPIOutputDigitalInterface%3DB92BE30121.postscript preserve=yes
//## end IPIOutputDigitalInterface%3DB92BE30121.postscript

//## begin IPITemperatureControlInterface%3DB939EB0037.preface preserve=yes
//## end IPITemperatureControlInterface%3DB939EB0037.preface

//## Class: IPITemperatureControlInterface%3DB939EB0037
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DB9414A0121;CPITemperatureControlConfig { -> F}
//## Uses: <unnamed>%3DB9414C01BE;CPITemperatureControlProfile { -> F}

class EBPI_DLL_DECL IPITemperatureControlInterface : public ICOAsyncInterface  //## Inherits: <unnamed>%3DB93A270008
{
  //## begin IPITemperatureControlInterface%3DB939EB0037.initialDeclarations preserve=yes
  //## end IPITemperatureControlInterface%3DB939EB0037.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPITemperatureControlInterface%1035548923
      IPITemperatureControlInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPITemperatureControlInterface();


    //## Other Operations (specified)
      //## Operation: SetProfile%1035548924
      //	DESCRIPTION
      //	Configures the profile of the temperature control unit
      //
      //	PARAMETERS
      //	Profile data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetProfile (CPITemperatureControlProfile* p_pProfile) = 0;

      //## Operation: SetConfiguration%1035548925
      //	DESCRIPTION
      //	Configures the active temperature nominal and range
      //	values
      //
      //	PARAMETERS
      //	Config data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetConfiguration (CPITemperatureControlConfig* p_pConfig) = 0;

      //## Operation: Start%1035548926
      //	DESCRIPTION
      //	Starts the control cycle. The supplied sync object is
      //	used to pass exception events such as warning or failure
      //	events to the client.
      //
      //	RETURNS
      //	async array:
      //	[0]: Start executed
      //	[1]: Exceptions
      virtual CCOSyncObjectArray* Start () = 0;

      //## Operation: Stop%1035548927
      //	DESCRIPTION
      //	Stops the control cycle.
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Stop () = 0;

      //## Operation: GetTemperature%1035548928
      //	DESCRIPTION
      //	Returns the current temperature value
      //
      //	RETURNS
      //	async integer
      virtual CCOSyncObjectInt* GetTemperature () = 0;

    // Additional Public Declarations
      //## begin IPITemperatureControlInterface%3DB939EB0037.public preserve=yes
      //## end IPITemperatureControlInterface%3DB939EB0037.public

  protected:
    // Additional Protected Declarations
      //## begin IPITemperatureControlInterface%3DB939EB0037.protected preserve=yes
      //## end IPITemperatureControlInterface%3DB939EB0037.protected

  private:
    //## Constructors (generated)
      IPITemperatureControlInterface();

      IPITemperatureControlInterface(const IPITemperatureControlInterface &right);

    //## Assignment Operation (generated)
      const IPITemperatureControlInterface & operator=(const IPITemperatureControlInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IPITemperatureControlInterface &right) const;

      bool operator!=(const IPITemperatureControlInterface &right) const;

    // Additional Private Declarations
      //## begin IPITemperatureControlInterface%3DB939EB0037.private preserve=yes
      //## end IPITemperatureControlInterface%3DB939EB0037.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPITemperatureControlInterface%3DB939EB0037.implementation preserve=yes
      //## end IPITemperatureControlInterface%3DB939EB0037.implementation

};

//## begin IPITemperatureControlInterface%3DB939EB0037.postscript preserve=yes
//## end IPITemperatureControlInterface%3DB939EB0037.postscript

//## begin IPIPowerControlInterface%3DB947960315.preface preserve=yes
//## end IPIPowerControlInterface%3DB947960315.preface

//## Class: IPIPowerControlInterface%3DB947960315
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DB948EE0160;CPIPowerControlProfile { -> F}

class EBPI_DLL_DECL IPIPowerControlInterface : public ICOAsyncInterface  //## Inherits: <unnamed>%3DB9487301BE
{
  //## begin IPIPowerControlInterface%3DB947960315.initialDeclarations preserve=yes
  //## end IPIPowerControlInterface%3DB947960315.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPIPowerControlInterface%1035548929
      IPIPowerControlInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPIPowerControlInterface();


    //## Other Operations (specified)
      //## Operation: SetProfile%1035548930
      //	DESCRIPTION
      //	Configures the profile of the power control unit
      //
      //	PARAMETERS
      //	Profile data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetProfile (CPIPowerControlProfile* p_pProfile) = 0;

      //## Operation: SetConfiguration%1035548931
      //	DESCRIPTION
      //	Configures the active power nominal value
      //
      //	PARAMETERS
      //	Config data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetConfiguration (CPIPowerControlConfig* p_pConfig) = 0;

      //## Operation: Start%1035548932
      //	DESCRIPTION
      //	Starts the control cycle. The supplied sync object is
      //	used to pass exception events such as warning or failure
      //	events to the client.
      //
      //	RETURNS
      //	async array:
      //	[0]: Start executed
      //	[1]: Exceptions
      virtual CCOSyncObjectArray* Start () = 0;

      //## Operation: Stop%1035548933
      //	DESCRIPTION
      //	Stops the control cycle.
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Stop () = 0;

      //## Operation: PowerOff%1076339195
      //	DESCRIPTION
      //	Power off for lamp change.
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* PowerOff () = 0;

      //## Operation: PowerOn%1076339196
      //	DESCRIPTION
      //	Starts the power after lamp change.
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* PowerOn () = 0;

    // Additional Public Declarations
      //## begin IPIPowerControlInterface%3DB947960315.public preserve=yes
      //## end IPIPowerControlInterface%3DB947960315.public

  protected:
    // Additional Protected Declarations
      //## begin IPIPowerControlInterface%3DB947960315.protected preserve=yes
      //## end IPIPowerControlInterface%3DB947960315.protected

  private:
    //## Constructors (generated)
      IPIPowerControlInterface();

      IPIPowerControlInterface(const IPIPowerControlInterface &right);

    //## Assignment Operation (generated)
      const IPIPowerControlInterface & operator=(const IPIPowerControlInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IPIPowerControlInterface &right) const;

      bool operator!=(const IPIPowerControlInterface &right) const;

    // Additional Private Declarations
      //## begin IPIPowerControlInterface%3DB947960315.private preserve=yes
      //## end IPIPowerControlInterface%3DB947960315.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPIPowerControlInterface%3DB947960315.implementation preserve=yes
      //## end IPIPowerControlInterface%3DB947960315.implementation

};

//## begin IPIPowerControlInterface%3DB947960315.postscript preserve=yes
//## end IPIPowerControlInterface%3DB947960315.postscript

//## begin IPIWedgeControlInterface%3DB949A6018F.preface preserve=yes
//## end IPIWedgeControlInterface%3DB949A6018F.preface

//## Class: IPIWedgeControlInterface%3DB949A6018F
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DB94AA200E3;CPIWedgeControlConfig { -> F}
//## Uses: <unnamed>%3DB94AA402C7;CPIWedgeControlProfile { -> F}
//## Uses: <unnamed>%3DD34B8E00DD;CPIWedgeControlConfig { -> F}
//## Uses: <unnamed>%3DD34B9001C8;CPIWedgeControlProfile { -> F}

class EBPI_DLL_DECL IPIWedgeControlInterface : public ICOAsyncInterface  //## Inherits: <unnamed>%3DB949F30344
{
  //## begin IPIWedgeControlInterface%3DB949A6018F.initialDeclarations preserve=yes
  //## end IPIWedgeControlInterface%3DB949A6018F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPIWedgeControlInterface%1035548934
      IPIWedgeControlInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPIWedgeControlInterface();


    //## Other Operations (specified)
      //## Operation: SetProfile%1035548935
      //	DESCRIPTION
      //	Configures the profile of the wedge control unit
      //
      //	PARAMETERS
      //	Profile data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetProfile (CPIWedgeControlProfile* p_pProfile) = 0;

      //## Operation: SetConfiguration%1035548936
      //	DESCRIPTION
      //	Configures the active window and speed settings of the
      //	wedge control unit
      //
      //	PARAMETERS
      //	Config data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetConfiguration (CPIWedgeControlConfig* p_pConfig) = 0;

      //## Operation: Initialize%1035789475
      //	DESCRIPTION
      //	initializes the wedge drive using the light fork
      //	reference sensor
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Initialize () = 0;

      //## Operation: Start%1035548937
      //	DESCRIPTION
      //	Starts the control cycle. The supplied sync object is
      //	used to pass exception events such as warning or failure
      //	events to the client.
      //
      //	PARAMETER
      //	- p_iScan: numbers of scans
      //
      //	RETURNS
      //	async array:
      //	[0]: Start executed
      //	[1]: Exceptions
      virtual CCOSyncObjectArray* Start (int p_iScan = -1) = 0;

      //## Operation: Stop%1035548938
      //	DESCRIPTION
      //	Stops the control cycle.
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Stop () = 0;

      //## Operation: Referencing%1037976624
      //	DESCRIPTION
      //	References the wegde
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Referencing () = 0;

      //## Operation: Park%1053509633
      //	DESCRIPTION
      //	Parks the control cycle.
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Park () = 0;

      //## Operation: GetDacZeroCurrent%1149168382
      //	DESCRIPTION
      //	Reads the Dac value for zero current of the wedge drive.
      //
      //	RETURNS
      //	async int
      virtual CCOSyncObjectInt* GetDacZeroCurrent () = 0;

    // Additional Public Declarations
      //## begin IPIWedgeControlInterface%3DB949A6018F.public preserve=yes
      //## end IPIWedgeControlInterface%3DB949A6018F.public

  protected:
    // Additional Protected Declarations
      //## begin IPIWedgeControlInterface%3DB949A6018F.protected preserve=yes
      //## end IPIWedgeControlInterface%3DB949A6018F.protected

  private:
    //## Constructors (generated)
      IPIWedgeControlInterface();

      IPIWedgeControlInterface(const IPIWedgeControlInterface &right);

    //## Assignment Operation (generated)
      const IPIWedgeControlInterface & operator=(const IPIWedgeControlInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IPIWedgeControlInterface &right) const;

      bool operator!=(const IPIWedgeControlInterface &right) const;

    // Additional Private Declarations
      //## begin IPIWedgeControlInterface%3DB949A6018F.private preserve=yes
      //## end IPIWedgeControlInterface%3DB949A6018F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPIWedgeControlInterface%3DB949A6018F.implementation preserve=yes
      //## end IPIWedgeControlInterface%3DB949A6018F.implementation

};

//## begin IPIWedgeControlInterface%3DB949A6018F.postscript preserve=yes
//## end IPIWedgeControlInterface%3DB949A6018F.postscript

//## begin IPIEventSourceInterface%3DB94D5F02B8.preface preserve=yes
//## end IPIEventSourceInterface%3DB94D5F02B8.preface

//## Class: IPIEventSourceInterface%3DB94D5F02B8
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL IPIEventSourceInterface : public ICOSyncInterface  //## Inherits: <unnamed>%3EF6FB7602F6
{
  //## begin IPIEventSourceInterface%3DB94D5F02B8.initialDeclarations preserve=yes
  //## end IPIEventSourceInterface%3DB94D5F02B8.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPIEventSourceInterface%1038845452
      IPIEventSourceInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPIEventSourceInterface();


    //## Other Operations (specified)
      //## Operation: RegisterForEvent%1035548940
      //	DESCRIPTION
      //	registers the given client to the event manager.
      //
      //	PARAMETERS
      //	type of event being interested in
      //	process image id of the input being interested in
      //
      //	RETURNS
      //	async array:
      //	[0]: async int, ID for later unregistering, command
      //	executed
      //	[1]: event occured
      virtual CCOSyncObjectArray* RegisterForEvent (UINT p_uiInputID, INT& p_iEventID) = 0;

      //## Operation: UnRegisterFromEvent%1035548941
      //	DESCRIPTION
      //	unregisters the given client from the event manager.
      //
      //	PARAMETERS
      //	client identification
      //	type of event being interested in
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* UnRegisterFromEvent (UINT p_uiClientID) = 0;

    // Additional Public Declarations
      //## begin IPIEventSourceInterface%3DB94D5F02B8.public preserve=yes
      //## end IPIEventSourceInterface%3DB94D5F02B8.public

  protected:
    // Additional Protected Declarations
      //## begin IPIEventSourceInterface%3DB94D5F02B8.protected preserve=yes
      //## end IPIEventSourceInterface%3DB94D5F02B8.protected

  private:
    //## Constructors (generated)
      IPIEventSourceInterface();

      IPIEventSourceInterface(const IPIEventSourceInterface &right);

    //## Assignment Operation (generated)
      const IPIEventSourceInterface & operator=(const IPIEventSourceInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IPIEventSourceInterface &right) const;

      bool operator!=(const IPIEventSourceInterface &right) const;

    // Additional Private Declarations
      //## begin IPIEventSourceInterface%3DB94D5F02B8.private preserve=yes
      //## end IPIEventSourceInterface%3DB94D5F02B8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPIEventSourceInterface%3DB94D5F02B8.implementation preserve=yes
      //## end IPIEventSourceInterface%3DB94D5F02B8.implementation

};

//## begin IPIEventSourceInterface%3DB94D5F02B8.postscript preserve=yes
//## end IPIEventSourceInterface%3DB94D5F02B8.postscript

//## begin IPIDiagnosticInterface%3DF5F2B4014F.preface preserve=yes
//## end IPIDiagnosticInterface%3DF5F2B4014F.preface

//## Class: IPIDiagnosticInterface%3DF5F2B4014F
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL IPIDiagnosticInterface : public ICOSyncInterface  //## Inherits: <unnamed>%3DF5F3100075
{
  //## begin IPIDiagnosticInterface%3DF5F2B4014F.initialDeclarations preserve=yes
  //## end IPIDiagnosticInterface%3DF5F2B4014F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPIDiagnosticInterface%1039528813
      IPIDiagnosticInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPIDiagnosticInterface();


    //## Other Operations (specified)
      //## Operation: ReadDWord%1039528814
      //	DESCRIPTION
      //	Reads a double word from a specific PCI address
      //
      //	RETURNS
      //	async integer
      virtual CCOSyncObjectInt* ReadDWord (UINT p_uiAddress, EPIRegisterType p_eRegisterType) = 0;

      //## Operation: WriteDWord%1039528815
      //	DESCRIPTION
      //	Writes a double word to a specific PCI address
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* WriteDWord (UINT p_uiAddress, UINT p_uiValue, EPIRegisterType p_eRegisterType) = 0;

      //## Operation: EnableEventSignalisation%1066122686
      //	DESCRIPTION
      //	enables the event signalisation (open events)
      virtual CCOSyncObject* EnableEventSignalisation () = 0;

      //## Operation: DisableEventSignalisation%1066122687
      //	DESCRIPTION
      //	disables the event signalisation (open events)
      virtual CCOSyncObject* DisableEventSignalisation () = 0;

      //## Operation: PCSetNomVoltage%1095058549
      //	DESCRIPTION:
      //	sets the nominal voltage for the primary or secondary
      //	lamp
      //
      //	select lamp (primary or secondary first with function
      //	PCLampSelection
      //
      //	INPUT:
      //	DAC value
      virtual CCOSyncObject* PCSetNomVoltage (DWORD p_dwDACValue) = 0;

      //## Operation: PCLampSelection%1095058550
      //	DESCRIPTION:
      //	selects the primary or secondary lamp
      //
      //
      //	INPUT:
      //	 - EPILamp
      virtual CCOSyncObject* PCLampSelection (EPILamp p_eSelection) = 0;

      //## Operation: PCLampOnOff%1095058551
      //	DESCRIPTION:
      //	primary or secondary lamp On / Off
      //
      //
      //	INPUT:
      //	false: OFF default
      //	true:  ON
      virtual CCOSyncObject* PCLampOnOff (bool p_bSelection = false) = 0;

      //## Operation: PCGetActCurrent%1095058552
      //	DESCRIPTION:
      //	gets the actual current from the selected lamp (primary
      //	or secondary)
      //
      //	RETURN:
      //	actual current
      virtual CCOSyncObjectInt* PCGetActCurrent () = 0;

      //## Operation: PCGetActVoltage%1095058553
      //	DESCRIPTION:
      //	gets the actual voltage from the selected lamp (primary
      //	or secondary)
      //
      //	INPUT:
      //	 - EPILamp
      //
      //	RETURN:
      //	actual voltage
      virtual CCOSyncObjectInt* PCGetActVoltage (EPILamp p_eSelection) = 0;

      //## Operation: PCGetLampIdentification%1095058554
      //	DESCRIPTION:
      //	gets the selected lamp identification (primary or
      //	secondary)
      //
      //	INPUT:
      //	 - EPILamp
      //
      //	RETURN:
      //	lamp identification
      virtual CCOSyncObjectInt* PCGetLampIdentification (EPILamp p_eSelection) = 0;

      //## Operation: WCGetActVelocityCounts%1095058555
      //	DESCRIPTION:
      //	gets the actual wedge velocity counts
      //
      //	RETURN:
      //	actual velocity counts (wdg_act_vlc)
      virtual CCOSyncObjectInt* WCGetActVelocityCounts () = 0;

      //## Operation: WCGetLastVelocityCounts%1095058556
      //	DESCRIPTION:
      //	gets the last wedge velocity counts
      //
      //	RETURN:
      //	last velocity counts (wdg_last_vlc)
      virtual CCOSyncObjectInt* WCGetLastVelocityCounts () = 0;

      //## Operation: WCGetPosition%1095058557
      //	DESCRIPTION:
      //	gets the wedge position
      //
      //	RETURN:
      //	position (wdg_pos_vlc)
      virtual CCOSyncObjectInt* WCGetPosition () = 0;

      //## Operation: WCInitializeDAC%1095058558
      //	DESCRIPTION:
      //	initialize the wedge control DAC
      virtual CCOSyncObject* WCInitializeDAC () = 0;

      //## Operation: WCSetDACValue%1095058559
      //	DESCRIPTION:
      //	sets the DAC wedge value
      //
      //	INPUT:
      //	DAC value
      virtual CCOSyncObject* WCSetDACValue (DWORD p_dwDACValue) = 0;

      //## Operation: ReadFpgaArtNr%1095058560
      //	DESCRIPTION:
      //	reads the FPGA software article number from the FPGA
      //
      //	RETURN:
      //	Article Number e.g. "045400"
      virtual CCOSyncObjectCString* ReadFpgaArtNr () = 0;

      //## Operation: ReadFpgaSwVersion%1095058561
      //	DESCRIPTION:
      //	reads the FPGA softwareversion from the FPGA
      //
      //	RETURN:
      //	Version e.g. ""
      virtual CCOSyncObjectCString* ReadFpgaSwVersion () = 0;

      //## Operation: I2CEpromByteRead%1095058562
      //	DESCRIPTION
      //	Reads a byte from the specific eprom address
      //
      //	RETURNS
      //	async int
      virtual CCOSyncObjectInt* I2CEpromByteRead (DWORD p_uiObjID, WORD p_uiAddress) = 0;

      //## Operation: I2CEpromByteWrite%1095058563
      //	DESCRIPTION
      //	writes a byte to the specific eprom address
      virtual CCOSyncObject* I2CEpromByteWrite (DWORD p_uiObjID, WORD p_uiAddress, BYTE p_cValue) = 0;

      //## Operation: GetDigitsLaserLevelDetection%1097650518
      //	DESCRIPTION:
      //	gets the Digits from the Laser Level Detection ADC
      //
      //
      //	RETURN:
      //	ADC Digits
      virtual CCOSyncObjectInt* GetDigitsLaserLevelDetection () = 0;

      //## Operation: ReleaseHWReset%1097650519
      //	DESCRIPTION:
      //	release hardware reset (over hardware watchdog)
      virtual CCOSyncObject* ReleaseHWReset () = 0;

      //## Operation: DisableWatchdog%1097650520
      //	DESCRIPTION:
      //	disables hardware watchdog
      virtual CCOSyncObject* DisableWatchdog () = 0;

      //## Operation: GetOsVersion%1108366393
      //	DESCRIPTION:
      //	reads the OS Version
      //
      //	RETURN:
      //	OS VErsion e.g. 5.0.1400.0 (Major.Minor.Build.0)
      virtual CCOSyncObjectCString* GetOsVersion () = 0;

      //## Operation: GetUsedMemory%1174554257
      //	DESCRIPTION:
      //	reads the memory information
      //
      //	RETURN:
      //	available and used memory
      virtual CCOSyncObjectInt* GetUsedMemory () = 0;

      //## Operation: GetMemoryAllocInfo%1174997740
      //	DESCRIPTION:
      //	reads the memory allocation info. Only valid in debug
      //	mode
      //
      //	RETURN:
      //	available memory allocation info
      virtual CCOSyncObjectCString* GetMemoryAllocInfo () = 0;

    // Additional Public Declarations
      //## begin IPIDiagnosticInterface%3DF5F2B4014F.public preserve=yes
      //## end IPIDiagnosticInterface%3DF5F2B4014F.public

  protected:
    // Additional Protected Declarations
      //## begin IPIDiagnosticInterface%3DF5F2B4014F.protected preserve=yes
      //## end IPIDiagnosticInterface%3DF5F2B4014F.protected

  private:
    //## Constructors (generated)
      IPIDiagnosticInterface();

      IPIDiagnosticInterface(const IPIDiagnosticInterface &right);

    //## Assignment Operation (generated)
      const IPIDiagnosticInterface & operator=(const IPIDiagnosticInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IPIDiagnosticInterface &right) const;

      bool operator!=(const IPIDiagnosticInterface &right) const;

    // Additional Private Declarations
      //## begin IPIDiagnosticInterface%3DF5F2B4014F.private preserve=yes
      //## end IPIDiagnosticInterface%3DF5F2B4014F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPIDiagnosticInterface%3DF5F2B4014F.implementation preserve=yes
      //## end IPIDiagnosticInterface%3DF5F2B4014F.implementation

};

//## begin IPIDiagnosticInterface%3DF5F2B4014F.postscript preserve=yes
//## end IPIDiagnosticInterface%3DF5F2B4014F.postscript

//## begin IPII2CEprom24LC515%3EDC3C5901B5.preface preserve=yes
//## end IPII2CEprom24LC515%3EDC3C5901B5.preface

//## Class: IPII2CEprom24LC515%3EDC3C5901B5
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL IPII2CEprom24LC515 : public ICOSyncInterface  //## Inherits: <unnamed>%3EDC3C9100EA
{
  //## begin IPII2CEprom24LC515%3EDC3C5901B5.initialDeclarations preserve=yes
  //## end IPII2CEprom24LC515%3EDC3C5901B5.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPII2CEprom24LC515%1054620987
      IPII2CEprom24LC515 (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPII2CEprom24LC515();


    //## Other Operations (specified)
      //## Operation: ByteRead%1054620992
      //	DESCRIPTION
      //	Reads a byte from the specific eprom address
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObjectInt* ByteRead (WORD p_uiAddress) = 0;

      //## Operation: BlockRead%1054620993
      //	DESCRIPTION
      //	Reads a number of byte from the specific eprom address
      //
      //	RETURNS
      //	async void
      virtual CPISyncObjI2CDataStream* BlockRead (WORD p_uiAddress, UINT p_uiSize) = 0;

      //## Operation: ReadContent%1054620994
      //	DESCRIPTION
      //	Reads the all contents of the eprom
      //
      //	RETURNS
      //	void
      virtual CPISyncObjI2CDataStream* ReadContent () = 0;

      //## Operation: ByteWrite%1054620995
      //	DESCRIPTION
      //	writes a byte to the specific eprom address
      virtual CCOSyncObject* ByteWrite (WORD p_uiAddress, BYTE p_cValue) = 0;

      //## Operation: PageWrite%1054620996
      //	DESCRIPTION
      //	writes a page size (max 64 byte) to the specific eprom
      //	address
      virtual CCOSyncObject* PageWrite (WORD p_uiAddress, BYTE* p_pcValue, UINT p_uiSize) = 0;

      //## Operation: WriteContent%1054620997
      //	DESCRIPTION
      //	writes the specified contents to the eprom
      //
      //	RETURNS
      //	void
      virtual CCOSyncObject* WriteContent (BYTE* &p_pContent, UINT p_uiDataSize) = 0;

      //## Operation: GetEprom24LC515SizeInByte%1061369814
      //	DESCRIPTION
      //	Gets the eprom size in byte
      //
      //	RETURNS
      //	size in byte
      virtual UINT GetEprom24LC515SizeInByte () = 0;

      //## Operation: GetEprom24LC515PageSizeInByte%1074589428
      //	DESCRIPTION
      //	Gets the eprom page size in byte
      //
      //	RETURNS
      //	page size in byte
      virtual UINT GetEprom24LC515PageSizeInByte () = 0;

    // Additional Public Declarations
      //## begin IPII2CEprom24LC515%3EDC3C5901B5.public preserve=yes
      //## end IPII2CEprom24LC515%3EDC3C5901B5.public

  protected:
    // Additional Protected Declarations
      //## begin IPII2CEprom24LC515%3EDC3C5901B5.protected preserve=yes
      //## end IPII2CEprom24LC515%3EDC3C5901B5.protected

  private:
    //## Constructors (generated)
      IPII2CEprom24LC515();

      IPII2CEprom24LC515(const IPII2CEprom24LC515 &right);

    //## Assignment Operation (generated)
      const IPII2CEprom24LC515 & operator=(const IPII2CEprom24LC515 &right);

    //## Equality Operations (generated)
      bool operator==(const IPII2CEprom24LC515 &right) const;

      bool operator!=(const IPII2CEprom24LC515 &right) const;

    // Additional Private Declarations
      //## begin IPII2CEprom24LC515%3EDC3C5901B5.private preserve=yes
      //## end IPII2CEprom24LC515%3EDC3C5901B5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPII2CEprom24LC515%3EDC3C5901B5.implementation preserve=yes
      //## end IPII2CEprom24LC515%3EDC3C5901B5.implementation

};

//## begin IPII2CEprom24LC515%3EDC3C5901B5.postscript preserve=yes
//## end IPII2CEprom24LC515%3EDC3C5901B5.postscript

//## begin IPII2CTempSensorDS1631Z%3EDC3DC60261.preface preserve=yes
//## end IPII2CTempSensorDS1631Z%3EDC3DC60261.preface

//## Class: IPII2CTempSensorDS1631Z%3EDC3DC60261
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EE5E1150011;CPIConfigDS1631Z { -> F}

class EBPI_DLL_DECL IPII2CTempSensorDS1631Z : public ICOSyncInterface  //## Inherits: <unnamed>%3EDC3E14001F
{
  //## begin IPII2CTempSensorDS1631Z%3EDC3DC60261.initialDeclarations preserve=yes
  //## end IPII2CTempSensorDS1631Z%3EDC3DC60261.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPII2CTempSensorDS1631Z%1054620988
      IPII2CTempSensorDS1631Z (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPII2CTempSensorDS1631Z();


    //## Other Operations (specified)
      //## Operation: SetSensorConfig%1054620989
      //	DESCRIPTION
      //	sets the appropriate temperature sensor configuration
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetSensorConfig (CPIConfigDS1631Z* p_pConfig) = 0;

      //## Operation: GetTemperature%1054620991
      //	DESCRIPTION
      //	gets the actual temperature
      //
      //	RETURNS
      //	async int
      virtual CCOSyncObjectInt* GetTemperature () = 0;

      //## Operation: GetSensorConfig%1056459660
      //	DESCRIPTION
      //	gets the appropriate temperature sensor configuration
      //
      //	RETURNS
      //	async int
      virtual CCOSyncObjectInt* GetSensorConfig () = 0;

    // Additional Public Declarations
      //## begin IPII2CTempSensorDS1631Z%3EDC3DC60261.public preserve=yes
      //## end IPII2CTempSensorDS1631Z%3EDC3DC60261.public

  protected:
    // Additional Protected Declarations
      //## begin IPII2CTempSensorDS1631Z%3EDC3DC60261.protected preserve=yes
      //## end IPII2CTempSensorDS1631Z%3EDC3DC60261.protected

  private:
    //## Constructors (generated)
      IPII2CTempSensorDS1631Z();

      IPII2CTempSensorDS1631Z(const IPII2CTempSensorDS1631Z &right);

    //## Assignment Operation (generated)
      const IPII2CTempSensorDS1631Z & operator=(const IPII2CTempSensorDS1631Z &right);

    //## Equality Operations (generated)
      bool operator==(const IPII2CTempSensorDS1631Z &right) const;

      bool operator!=(const IPII2CTempSensorDS1631Z &right) const;

    // Additional Private Declarations
      //## begin IPII2CTempSensorDS1631Z%3EDC3DC60261.private preserve=yes
      //## end IPII2CTempSensorDS1631Z%3EDC3DC60261.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPII2CTempSensorDS1631Z%3EDC3DC60261.implementation preserve=yes
      //## end IPII2CTempSensorDS1631Z%3EDC3DC60261.implementation

};

//## begin IPII2CTempSensorDS1631Z%3EDC3DC60261.postscript preserve=yes
//## end IPII2CTempSensorDS1631Z%3EDC3DC60261.postscript

//## begin IPISystemInterface%3EE5A73D02D1.preface preserve=yes
//## end IPISystemInterface%3EE5A73D02D1.preface

//## Class: IPISystemInterface%3EE5A73D02D1
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DEDD1C001CC;CPISyncObjListSWCompVersion { -> }
//## Uses: <unnamed>%4002D45602B2;CPIPersistentIdent { -> }

class EBPI_DLL_DECL IPISystemInterface : public ICOAsyncInterface  //## Inherits: <unnamed>%3EE5A79E00BD
{
  //## begin IPISystemInterface%3EE5A73D02D1.initialDeclarations preserve=yes
  //## end IPISystemInterface%3EE5A73D02D1.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPISystemInterface%1055243187
      IPISystemInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPISystemInterface();


    //## Other Operations (specified)
      //## Operation: RegisterClient%1096656405
      //	registers a certain user as the current client.
      //	throws an 'XSYSystemBusy' exeption in case another
      //	client is already registered
      virtual CCOSyncObject* RegisterClient (const CString& p_sClient) = 0;

      //## Operation: StartDevice%1055243188
      //	DESCRIPTION
      //	Starts the device
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* StartDevice () = 0;

      //## Operation: ResetDevice%1055243189
      //	DESCRIPTION
      //	Reset's the device
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ResetDevice () = 0;

      //## Operation: GetDeviceState%1055243190
      //	DESCRIPTION
      //	Queries for the device' state
      //
      //	RETURNS
      //	device state
      virtual EPIDeviceState GetDeviceState () = 0;

      //## Operation: ReadSoftwareVersions%1055243193
      //	DESCRIPTION
      //	Returns a list with CPIPersistentSoftwareComponent
      //	Version Objects, describing the current software version
      //	of the modules managing the inital startup and
      //	communication
      //
      //	PARAMETERS
      //
      //
      //	RETURNS
      //	CPISyncObjListSWCompVersion*
      virtual CPISyncObjListSWCompVersion* ReadSoftwareVersions () = 0;

      //## Operation: DownloadSoftwareComponents%1055243194
      //	DESCRIPTION
      //	Installs software components on the embedded system.
      //
      //	PARAMETERS
      //	software components for download
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* DownloadSoftwareComponents (CPIPersistentSoftwareComponentList* p_pComponentList) = 0;

      //## Operation: DownloadSoftwareComponent%1199783744
      //	DESCRIPTION
      //	Installs software components on the embedded system.
      //
      //	PARAMETERS
      //	software component for download
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* DownloadSoftwareComponent (CPIPersistentSoftwareComponent* p_pComponent) = 0;

      //## Operation: SetInterfaceConfig%1055243195
      //	DESCRIPTION
      //	Configures the PC Interface of the device
      //
      //	PARAMETERS
      //	Interface Config
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetInterfaceConfig (CPIInterfaceConfig* p_pInterfaceConfig) = 0;

      //## Operation: SetComponentState%1061301411
      //	DESCRIPTION
      //	Sets the state for a component to on (true) or off
      //	(false)
      //
      //	PARAMETERS
      //	ComponentId (String)
      //	State (bool)
      //
      //	RETURNS
      //	Sync Object
      virtual CCOSyncObject* SetComponentState (const CString& p_sComponentId, const bool p_bActive) = 0;

      //## Operation: GetObjectList%1063715456
      //	DESCRIPTION
      //	Returns a complete list of present objects in the
      //	currently living in the embedded system
      //
      //	RETURNS
      //	async: CStringArray
      virtual CPISyncObjectStringArray* GetObjectList () = 0;

      //## Operation: SetSystemTime%1064429414
      //	DESCRIPTION
      //	sets the system time according to the given parameter
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetSystemTime (const SYSTEMTIME& p_SystemTime) = 0;

      //## Operation: GetVersion%1096656413
      virtual CCOSyncObjectCString* GetVersion () = 0;

      //## Operation: SetStandbyTimeout%1096717073
      //	activates the standby timeout of the device
      //	timeout is in ms
      virtual CCOSyncObject* SetStandbyTimeout (const UINT p_uiTimeout) = 0;

      //## Operation: GetOsVersion%1108540784
      //	DESCRIPTION
      //	Gets the WinCE OS Version
      //
      //	RETURNS:
      //	Version Major.Minor.Build.0 e.g. 5.0.1400.0
      virtual CCOSyncObjectCString* GetOsVersion () = 0;

      //## Operation: GetFpgaVersion%1108540785
      //	DESCRIPTION
      //	Gets the FPGA Version
      //
      //	RETURNS:
      //	Version Major.Minor.Build.0 e.g. 5.0.1400.0
      virtual CCOSyncObjectCString* GetFpgaVersion () = 0;

      //## Operation: StartDownload%1199783742
      //	DESCRIPTION
      //	Starts a download process
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* StartDownload () = 0;

      //## Operation: EndDownload%1199783743
      //	DESCRIPTION
      //	Ends and completes a download process
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* EndDownload () = 0;

    // Additional Public Declarations
      //## begin IPISystemInterface%3EE5A73D02D1.public preserve=yes
      //## end IPISystemInterface%3EE5A73D02D1.public

  protected:
    // Additional Protected Declarations
      //## begin IPISystemInterface%3EE5A73D02D1.protected preserve=yes
      //## end IPISystemInterface%3EE5A73D02D1.protected

  private:
    //## Constructors (generated)
      IPISystemInterface();

      IPISystemInterface(const IPISystemInterface &right);

    //## Assignment Operation (generated)
      const IPISystemInterface & operator=(const IPISystemInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IPISystemInterface &right) const;

      bool operator!=(const IPISystemInterface &right) const;

    // Additional Private Declarations
      //## begin IPISystemInterface%3EE5A73D02D1.private preserve=yes
      //## end IPISystemInterface%3EE5A73D02D1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPISystemInterface%3EE5A73D02D1.implementation preserve=yes
      //## end IPISystemInterface%3EE5A73D02D1.implementation

};

//## begin IPISystemInterface%3EE5A73D02D1.postscript preserve=yes
//## end IPISystemInterface%3EE5A73D02D1.postscript

//## begin IPII2CDigitalPotiAD5245%3F44C077032C.preface preserve=yes
//## end IPII2CDigitalPotiAD5245%3F44C077032C.preface

//## Class: IPII2CDigitalPotiAD5245%3F44C077032C
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBPI_DLL_DECL IPII2CDigitalPotiAD5245 : public ICOSyncInterface  //## Inherits: <unnamed>%3F44C09C033C
{
  //## begin IPII2CDigitalPotiAD5245%3F44C077032C.initialDeclarations preserve=yes
  //## end IPII2CDigitalPotiAD5245%3F44C077032C.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPII2CDigitalPotiAD5245%1061902089
      IPII2CDigitalPotiAD5245 (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPII2CDigitalPotiAD5245();


    //## Other Operations (specified)
      //## Operation: WriteValue%1061532011
      //	DESCRIPTION
      //	writes the value to the digital potentiometer
      //
      //	INPUT:
      //	- data byte
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* WriteValue (BYTE p_cValue) = 0;

      //## Operation: ReadValue%1061532012
      //	DESCRIPTION
      //	gets the digital potentiometer value
      //
      //	RETURNS
      //	async int
      virtual CCOSyncObjectInt* ReadValue () = 0;

    // Additional Public Declarations
      //## begin IPII2CDigitalPotiAD5245%3F44C077032C.public preserve=yes
      //## end IPII2CDigitalPotiAD5245%3F44C077032C.public

  protected:
    // Additional Protected Declarations
      //## begin IPII2CDigitalPotiAD5245%3F44C077032C.protected preserve=yes
      //## end IPII2CDigitalPotiAD5245%3F44C077032C.protected

  private:
    //## Constructors (generated)
      IPII2CDigitalPotiAD5245();

      IPII2CDigitalPotiAD5245(const IPII2CDigitalPotiAD5245 &right);

    //## Assignment Operation (generated)
      const IPII2CDigitalPotiAD5245 & operator=(const IPII2CDigitalPotiAD5245 &right);

    //## Equality Operations (generated)
      bool operator==(const IPII2CDigitalPotiAD5245 &right) const;

      bool operator!=(const IPII2CDigitalPotiAD5245 &right) const;

    // Additional Private Declarations
      //## begin IPII2CDigitalPotiAD5245%3F44C077032C.private preserve=yes
      //## end IPII2CDigitalPotiAD5245%3F44C077032C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPII2CDigitalPotiAD5245%3F44C077032C.implementation preserve=yes
      //## end IPII2CDigitalPotiAD5245%3F44C077032C.implementation

};

//## begin IPII2CDigitalPotiAD5245%3F44C077032C.postscript preserve=yes
//## end IPII2CDigitalPotiAD5245%3F44C077032C.postscript

//## begin IPII2CADCMAX1037%3F49C9660290.preface preserve=yes
//## end IPII2CADCMAX1037%3F49C9660290.preface

//## Class: IPII2CADCMAX1037%3F49C9660290
//## Category: EBPI (PC Interface)%3DA488100179
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F49D8F7005D;CPISyncObjDataADCMAX1037 { -> }

class EBPI_DLL_DECL IPII2CADCMAX1037 : public ICOSyncInterface  //## Inherits: <unnamed>%3F49CA9D0242
{
  //## begin IPII2CADCMAX1037%3F49C9660290.initialDeclarations preserve=yes
  //## end IPII2CADCMAX1037%3F49C9660290.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IPII2CADCMAX1037%1061804166
      IPII2CADCMAX1037 (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IPII2CADCMAX1037();


    //## Other Operations (specified)
      //## Operation: GetData%1061804150
      //	DESCRIPTION
      //	gets the actual temperature
      //
      //	RETURNS
      //	async int
      virtual CPISyncObjDataADCMAX1037* GetData () = 0;

      //## Operation: Initialize%1061804151
      //	DESCRIPTION
      //	intializes the ADC
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Initialize () = 0;

    // Additional Public Declarations
      //## begin IPII2CADCMAX1037%3F49C9660290.public preserve=yes
      //## end IPII2CADCMAX1037%3F49C9660290.public

  protected:
    // Additional Protected Declarations
      //## begin IPII2CADCMAX1037%3F49C9660290.protected preserve=yes
      //## end IPII2CADCMAX1037%3F49C9660290.protected

  private:
    //## Constructors (generated)
      IPII2CADCMAX1037();

      IPII2CADCMAX1037(const IPII2CADCMAX1037 &right);

    //## Assignment Operation (generated)
      const IPII2CADCMAX1037 & operator=(const IPII2CADCMAX1037 &right);

    //## Equality Operations (generated)
      bool operator==(const IPII2CADCMAX1037 &right) const;

      bool operator!=(const IPII2CADCMAX1037 &right) const;

    // Additional Private Declarations
      //## begin IPII2CADCMAX1037%3F49C9660290.private preserve=yes
      //## end IPII2CADCMAX1037%3F49C9660290.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin IPII2CADCMAX1037%3F49C9660290.implementation preserve=yes
      //## end IPII2CADCMAX1037%3F49C9660290.implementation

};

//## begin IPII2CADCMAX1037%3F49C9660290.postscript preserve=yes
//## end IPII2CADCMAX1037%3F49C9660290.postscript

// Class IPIStepperMotorInterface 

// Class IPIMeasurementChannelInterface 

// Class IPIPersistentObjInterface 

// Class IPISensorAnalogInterface 

// Class IPISensorDigitalInterface 

// Class IPIOutputAnalogInterface 

// Class IPIOutputDigitalInterface 

// Class IPITemperatureControlInterface 

// Class IPIPowerControlInterface 

// Class IPIWedgeControlInterface 

// Class IPIEventSourceInterface 

// Class IPIDiagnosticInterface 

// Class IPII2CEprom24LC515 

// Class IPII2CTempSensorDS1631Z 

// Class IPISystemInterface 

// Class IPII2CDigitalPotiAD5245 

// Class IPII2CADCMAX1037 

//## begin module%3DA52EE301A8.epilog preserve=yes
//## end module%3DA52EE301A8.epilog


#endif
