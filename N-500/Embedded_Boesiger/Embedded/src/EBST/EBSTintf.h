//## begin module%3DA5BCC70034.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA5BCC70034.cm

//## begin module%3DA5BCC70034.cp preserve=no
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
//## end module%3DA5BCC70034.cp

//## Module: EBSTintf%3DA5BCC70034; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTintf.h

#ifndef EBSTintf_h
#define EBSTintf_h 1

//## begin module%3DA5BCC70034.additionalIncludes preserve=no
//## end module%3DA5BCC70034.additionalIncludes

//## begin module%3DA5BCC70034.includes preserve=yes
//## end module%3DA5BCC70034.includes

// EBCOsypr
#include "EBCOsypr.h"
// EBPIintf
#include "EBPIintf.h"
// EBSTlimit
#include "EBSTlimit.h"


//## begin module%3DA5BCC70034.declarations preserve=no
//## end module%3DA5BCC70034.declarations

//## begin module%3DA5BCC70034.additionalDeclarations preserve=yes
//## end module%3DA5BCC70034.additionalDeclarations


//## begin CSTStepperMotorInterface%3DA5340400AE.preface preserve=yes
//## end CSTStepperMotorInterface%3DA5340400AE.preface

//## Class: CSTStepperMotorInterface%3DA5340400AE
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DA6BEF00201;ST_IDENTIFIERS { -> }
//## Uses: <unnamed>%3DA6C02B0397;CSTStepperMotorImplementation { -> }
//## Uses: <unnamed>%3DAA5E9801E6;CSTCommand { -> }
//## Uses: <unnamed>%3DAA6C1400BD;CCOSyncObjectInt { -> }
//## Uses: <unnamed>%3E7588340285;ICOAsyncImplementation { -> }
//## Uses: <unnamed>%3E806C0200C3;CSTLimitSwitch { -> }

class EBST_DLL_DECL CSTStepperMotorInterface : public IPIStepperMotorInterface  //## Inherits: <unnamed>%3DA5340F0245
{
  //## begin CSTStepperMotorInterface%3DA5340400AE.initialDeclarations preserve=yes
  //## end CSTStepperMotorInterface%3DA5340400AE.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTStepperMotorInterface%1034230439
      CSTStepperMotorInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CSTStepperMotorInterface();


    //## Other Operations (specified)
      //## Operation: InitInstance%1034329210
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

      //## Operation: MoveAbsolute%1035273363
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
      virtual CCOSyncObject* MoveAbsolute (INT p_iTargetPosition, INT p_iSearchDistance = 0);

      //## Operation: MoveRelative%1035273364
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
      virtual CCOSyncObject* MoveRelative (INT p_iTotalDistance, INT p_iSearchDistance = 0);

      //## Operation: MoveManual%1035273365
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
      virtual CCOSyncObject* MoveManual (INT p_iEndPosition, UINT p_uiSpeed);

      //## Operation: GetPosition%1034575080
      //	DESCRIPTION
      //	Reads the current position of the motor
      //	All distances and positions are in steps
      //
      //	RETURNS
      //	async int
      virtual CCOSyncObjectInt* GetPosition ();

      //## Operation: Stop%1035273366
      //	DESCRIPTION
      //	Stops the motor using the predefined slow down slope.
      //
      //	RETURNS
      //	asynchronous void
      virtual CCOSyncObject* Stop ();

      //## Operation: StopImmediately%1035273367
      //	DESCRIPTION
      //	Stops the motor immediately.
      //
      //	RETURNS
      //	asynchronous void
      virtual CCOSyncObject* StopImmediately ();

      //## Operation: SetProfile%1035273368
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
      virtual CCOSyncObject* SetProfile (CPIStepperMotorProfile* p_pProfile);

      //## Operation: SetSpeed%1035273369
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
      virtual CCOSyncObjectInt* SetSpeed (UINT p_uiSpeed = 100);

      //## Operation: LimitAdd%1035273370
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
      virtual CCOSyncObject* LimitAdd (CPIObjIdentification* p_pSensorID, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction);

      //## Operation: LimitConfig%1035273371
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
      virtual CCOSyncObject* LimitConfig (CPIObjIdentification* p_pSensorID, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction);

      //## Operation: LimitActivate%1035273372
      //	DESCRIPTION
      //	disables or enables all limits of a motor according to
      //	their configuration
      virtual CCOSyncObject* LimitActivate ();

      //## Operation: LimitDeactivate%1035273373
      //	DESCRIPTION
      //	disables or enables all limits of a motor according to
      //	their configuration
      virtual CCOSyncObject* LimitDeactivate ();

      //## Operation: Home%1035273374
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
      virtual CCOSyncObjectInt* Home (const EPIMotorPolarity p_eMotorPolarity, CPIObjIdentification* p_pHomeLimitID);

      //## Operation: Home%1193077630
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
      virtual CCOSyncObjectInt* Home (const EPIMotorPolarity p_eFastFindDirection, const bool p_bSearchLimitFromOpposite, CPIObjIdentification* p_pHomeLimitID);

      //## Operation: HomeSetPosition%1035273375
      //	DESCRIPTION
      //	assigns a logical corrdinate to the home position. This
      //	will affect all further absolute movements
      //
      //	PARAMETERS
      //	position in um assigned to the home position
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* HomeSetPosition (INT p_iPosition);

      //## Operation: LimitGetFootPrint%1035273376
      //	DESCRIPTION
      //	returns the position (steps) of detected soft limit
      //	edges of the last movement
      //
      //	RETURNS
      //	asynchronous : integer array with positions
      virtual CCOSyncObjectIntArray* LimitGetFootPrint ();

      //## Operation: SetConfig%1048149993
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
      virtual CCOSyncObject* SetConfig (CPIStepperMotorConfig* p_pConfig);

      //## Operation: OnLimitHit%1048581159
      //	DESCRIPTION
      //	is executed, if a limit switch is hit
      //
      //	PARAMETERS
      //	limit switch which has triggered the event
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* OnLimitHit (CPIObjIdentification* p_pLimitSwitch);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPI (PC Interface)::<unnamed>%3DA537A000C5
      //## Role: CSTStepperMotorInterface::uiID%3DA537A10078
      virtual UINT GetuiID ();

    // Additional Public Declarations
      //## begin CSTStepperMotorInterface%3DA5340400AE.public preserve=yes
      //## end CSTStepperMotorInterface%3DA5340400AE.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStepperMotorInterface%3DA5340400AE.protected preserve=yes
      //## end CSTStepperMotorInterface%3DA5340400AE.protected

  private:
    //## Constructors (generated)
      CSTStepperMotorInterface();

      CSTStepperMotorInterface(const CSTStepperMotorInterface &right);

    //## Assignment Operation (generated)
      const CSTStepperMotorInterface & operator=(const CSTStepperMotorInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStepperMotorInterface &right) const;

      bool operator!=(const CSTStepperMotorInterface &right) const;


    //## Other Operations (specified)
      //## Operation: GetpImplementation%1049871950
      virtual CSTStepperMotorImplementation* GetpImplementation ();

    // Data Members for Associations

      //## Association: EBPI (PC Interface)::<unnamed>%3DA537A000C5
      //## begin CSTStepperMotorInterface::uiID%3DA537A10078.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CSTStepperMotorInterface::uiID%3DA537A10078.role

    // Additional Private Declarations
      //## begin CSTStepperMotorInterface%3DA5340400AE.private preserve=yes
      //## end CSTStepperMotorInterface%3DA5340400AE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStepperMotorInterface%3DA5340400AE.implementation preserve=yes
	  friend class CTestSTDlg;
      //## end CSTStepperMotorInterface%3DA5340400AE.implementation
};

//## begin CSTStepperMotorInterface%3DA5340400AE.postscript preserve=yes
//## end CSTStepperMotorInterface%3DA5340400AE.postscript

// Class CSTStepperMotorInterface 

//## begin module%3DA5BCC70034.epilog preserve=yes
//## end module%3DA5BCC70034.epilog


#endif
