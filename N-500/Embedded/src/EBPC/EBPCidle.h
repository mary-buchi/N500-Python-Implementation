//## begin module%3EED769F037A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F037A.cm

//## begin module%3EED769F037A.cp preserve=no
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
//## end module%3EED769F037A.cp

//## Module: EBPCidle%3EED769F037A; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCidle.h

#ifndef EBPCidle_h
#define EBPCidle_h 1

//## begin module%3EED769F037A.additionalIncludes preserve=no
//## end module%3EED769F037A.additionalIncludes

//## begin module%3EED769F037A.includes preserve=yes
//## end module%3EED769F037A.includes

// EBPCstat
#include "EBPCstat.h"
//## begin module%3EED769F037A.declarations preserve=no
//## end module%3EED769F037A.declarations

//## begin module%3EED769F037A.additionalDeclarations preserve=yes
//## end module%3EED769F037A.additionalDeclarations


//## begin CPCStateIdle%3EED76CC07BF.preface preserve=yes
//## end CPCStateIdle%3EED76CC07BF.preface

//## Class: CPCStateIdle%3EED76CC07BF
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%40288A100006;CPCStateCreated { -> }
//## Uses: <unnamed>%40288A490362;CPCStateConfigNotSet { -> }
//## Uses: <unnamed>%40288A820026;CPCStateNotConnected { -> }
//## Uses: <unnamed>%403235820269;PC_IDENTIFIERS { -> }

class CPCStateIdle : public CPCState  //## Inherits: <unnamed>%40278EC0017D
{
  //## begin CPCStateIdle%3EED76CC07BF.initialDeclarations preserve=yes
  //## end CPCStateIdle%3EED76CC07BF.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateIdle();

    //## Destructor (generated)
      virtual ~CPCStateIdle();


    //## Other Operations (specified)
      //## Operation: CleanupInitialize%1063954793
      //	DESCRIPTION
      //	Recovers from a 'Initialize Cleanup' exception. State
      //	machine should be broght to the 'ConfigReady' state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void CleanupInitialize (ICOStateMachineContext* p_pContext);

      //## Operation: Startup%1076339193
      //	DESCRIPTION
      //	Brings the subsystem up to the state 'ConfigProcessModel
      //	Setup'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Startup (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1076339201
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1076339202
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: Stop%1077027754
      virtual void Stop (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPCStateIdle%3EED76CC07BF.public preserve=yes
      //## end CPCStateIdle%3EED76CC07BF.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateIdle%3EED76CC07BF.protected preserve=yes
      //## end CPCStateIdle%3EED76CC07BF.protected

  private:
    //## Constructors (generated)
      CPCStateIdle(const CPCStateIdle &right);

    //## Assignment Operation (generated)
      const CPCStateIdle & operator=(const CPCStateIdle &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateIdle &right) const;

      bool operator!=(const CPCStateIdle &right) const;

    // Additional Private Declarations
      //## begin CPCStateIdle%3EED76CC07BF.private preserve=yes
      //## end CPCStateIdle%3EED76CC07BF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateIdle%3EED76CC07BF.implementation preserve=yes
      //## end CPCStateIdle%3EED76CC07BF.implementation

};

//## begin CPCStateIdle%3EED76CC07BF.postscript preserve=yes
//## end CPCStateIdle%3EED76CC07BF.postscript

//## begin CPCStateIdleStarting%3EED76CC06C6.preface preserve=yes
//## end CPCStateIdleStarting%3EED76CC06C6.preface

//## Class: CPCStateIdleStarting%3EED76CC06C6
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EED76CC06CB;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3EED76CC06D4;CPCPowerControlImplementation { -> }
//## Uses: <unnamed>%3F13FA710394;XPCExceptionErrorInterrupted { -> }
//## Uses: <unnamed>%3F13FA740086;XPCExceptionErrorShorted { -> }

class CPCStateIdleStarting : public CPCStateIdle  //## Inherits: <unnamed>%4027A60C0026
{
  //## begin CPCStateIdleStarting%3EED76CC06C6.initialDeclarations preserve=yes
  //## end CPCStateIdleStarting%3EED76CC06C6.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateIdleStarting();

    //## Destructor (generated)
      virtual ~CPCStateIdleStarting();


    //## Other Operations (specified)
      //## Operation: Create%1076330421
      static void Create ();

      //## Operation: Delete%1076330422
      static void Delete ();

      //## Operation: GetInstance%1076330423
      static CPCStateIdleStarting* GetInstance ();

      //## Operation: Do%1076330424
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPCStateIdleStarting%3EED76CC06C6.public preserve=yes
      //## end CPCStateIdleStarting%3EED76CC06C6.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateIdleStarting%3EED76CC06C6.protected preserve=yes
      //## end CPCStateIdleStarting%3EED76CC06C6.protected

  private:
    //## Constructors (generated)
      CPCStateIdleStarting(const CPCStateIdleStarting &right);

    //## Assignment Operation (generated)
      const CPCStateIdleStarting & operator=(const CPCStateIdleStarting &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateIdleStarting &right) const;

      bool operator!=(const CPCStateIdleStarting &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%40279104016E
      //## Role: CPCStateIdleStarting::pInstance%4027910500A3
      //## begin CPCStateIdleStarting::pInstance%4027910500A3.role preserve=no  public: static CPCStateIdleStarting {1..1 -> 1..1RFHN}
      static CPCStateIdleStarting *m_pInstance;
      //## end CPCStateIdleStarting::pInstance%4027910500A3.role

    // Additional Private Declarations
      //## begin CPCStateIdleStarting%3EED76CC06C6.private preserve=yes
      //## end CPCStateIdleStarting%3EED76CC06C6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateIdleStarting%3EED76CC06C6.implementation preserve=yes
      //## end CPCStateIdleStarting%3EED76CC06C6.implementation

};

//## begin CPCStateIdleStarting%3EED76CC06C6.postscript preserve=yes
//## end CPCStateIdleStarting%3EED76CC06C6.postscript

//## begin CPCStateIdlePowerOff%3EED76CC0724.preface preserve=yes
//## end CPCStateIdlePowerOff%3EED76CC0724.preface

//## Class: CPCStateIdlePowerOff%3EED76CC0724
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPCStateIdlePowerOff : public CPCStateIdle  //## Inherits: <unnamed>%4027A6060352
{
  //## begin CPCStateIdlePowerOff%3EED76CC0724.initialDeclarations preserve=yes
  //## end CPCStateIdlePowerOff%3EED76CC0724.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateIdlePowerOff();

    //## Destructor (generated)
      virtual ~CPCStateIdlePowerOff();


    //## Other Operations (specified)
      //## Operation: Create%1044522158
      static void Create ();

      //## Operation: GetInstance%1044522159
      static CPCStateIdlePowerOff* GetInstance ();

      //## Operation: Delete%1044522160
      static void Delete ();

      //## Operation: Do%1045140119
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: PowerOn%1076339213
      //	DESCRIPTION
      //	Starts the power after lamp change.
      //
      //	RETURNS
      //	async void
      virtual void PowerOn (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPCStateIdlePowerOff%3EED76CC0724.public preserve=yes
      //## end CPCStateIdlePowerOff%3EED76CC0724.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateIdlePowerOff%3EED76CC0724.protected preserve=yes
      //## end CPCStateIdlePowerOff%3EED76CC0724.protected

  private:
    //## Constructors (generated)
      CPCStateIdlePowerOff(const CPCStateIdlePowerOff &right);

    //## Assignment Operation (generated)
      const CPCStateIdlePowerOff & operator=(const CPCStateIdlePowerOff &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateIdlePowerOff &right) const;

      bool operator!=(const CPCStateIdlePowerOff &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%3EED76CC08C3
      //## Role: CPCStateIdlePowerOff::pInstance%3EED76CC08C8
      //## begin CPCStateIdlePowerOff::pInstance%3EED76CC08C8.role preserve=no  public: static CPCStateIdlePowerOff {1..1 -> 1..1RFHN}
      static CPCStateIdlePowerOff *m_pInstance;
      //## end CPCStateIdlePowerOff::pInstance%3EED76CC08C8.role

    // Additional Private Declarations
      //## begin CPCStateIdlePowerOff%3EED76CC0724.private preserve=yes
      //## end CPCStateIdlePowerOff%3EED76CC0724.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateIdlePowerOff%3EED76CC0724.implementation preserve=yes
      //## end CPCStateIdlePowerOff%3EED76CC0724.implementation

};

//## begin CPCStateIdlePowerOff%3EED76CC0724.postscript preserve=yes
//## end CPCStateIdlePowerOff%3EED76CC0724.postscript

//## begin CPCStateIdleCheckPower%402790940381.preface preserve=yes
//## end CPCStateIdleCheckPower%402790940381.preface

//## Class: CPCStateIdleCheckPower%402790940381
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%4027AF02018D;CPIPowerControlProfile { -> }
//## Uses: <unnamed>%4027AF210333;CPCLogic { -> }

class CPCStateIdleCheckPower : public CPCStateIdle  //## Inherits: <unnamed>%4027A6130248
{
  //## begin CPCStateIdleCheckPower%402790940381.initialDeclarations preserve=yes
  //## end CPCStateIdleCheckPower%402790940381.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateIdleCheckPower();

    //## Destructor (generated)
      virtual ~CPCStateIdleCheckPower();


    //## Other Operations (specified)
      //## Operation: Create%1076330417
      static void Create ();

      //## Operation: Delete%1076330418
      static void Delete ();

      //## Operation: GetInstance%1076330419
      static CPCStateIdleCheckPower* GetInstance ();

      //## Operation: Do%1076330420
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPCStateIdleCheckPower%402790940381.public preserve=yes
      //## end CPCStateIdleCheckPower%402790940381.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateIdleCheckPower%402790940381.protected preserve=yes
      //## end CPCStateIdleCheckPower%402790940381.protected

  private:
    //## Constructors (generated)
      CPCStateIdleCheckPower(const CPCStateIdleCheckPower &right);

    //## Assignment Operation (generated)
      const CPCStateIdleCheckPower & operator=(const CPCStateIdleCheckPower &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateIdleCheckPower &right) const;

      bool operator!=(const CPCStateIdleCheckPower &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%4027989D0381
      //## Role: CPCStateIdleCheckPower::pInstance%4027989E0324
      //## begin CPCStateIdleCheckPower::pInstance%4027989E0324.role preserve=no  public: static CPCStateIdleCheckPower {1..1 -> 1..1RFHN}
      static CPCStateIdleCheckPower *m_pInstance;
      //## end CPCStateIdleCheckPower::pInstance%4027989E0324.role

    // Additional Private Declarations
      //## begin CPCStateIdleCheckPower%402790940381.private preserve=yes
      //## end CPCStateIdleCheckPower%402790940381.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateIdleCheckPower%402790940381.implementation preserve=yes
      //## end CPCStateIdleCheckPower%402790940381.implementation

};

//## begin CPCStateIdleCheckPower%402790940381.postscript preserve=yes
//## end CPCStateIdleCheckPower%402790940381.postscript

//## begin CPCStateIdleStandBy%40279A2A03BF.preface preserve=yes
//## end CPCStateIdleStandBy%40279A2A03BF.preface

//## Class: CPCStateIdleStandBy%40279A2A03BF
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%4027BC6C012F;CPCStateProcessControling { -> }
//## Uses: <unnamed>%403228D90055;EHIStaticObjID { -> }
//## Uses: <unnamed>%4034935E03D0;CPCPid { -> }
//## Uses: <unnamed>%468BBA1F01DF;CHIInterface { -> }

class CPCStateIdleStandBy : public CPCStateIdle  //## Inherits: <unnamed>%4027A6100287
{
  //## begin CPCStateIdleStandBy%40279A2A03BF.initialDeclarations preserve=yes
  //## end CPCStateIdleStandBy%40279A2A03BF.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateIdleStandBy();

    //## Destructor (generated)
      virtual ~CPCStateIdleStandBy();


    //## Other Operations (specified)
      //## Operation: Create%1076330425
      static void Create ();

      //## Operation: Delete%1076330426
      static void Delete ();

      //## Operation: GetInstance%1076330427
      static CPCStateIdleStandBy* GetInstance ();

      //## Operation: Do%1076330428
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: Start%1076339212
      virtual void Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObject);

      //## Operation: PowerOff%1076339214
      //	DESCRIPTION
      //	Power off for lamp change.
      //
      //	RETURNS
      //	async void
      virtual void PowerOff (ICOStateMachineContext* p_pContext);

      //## Operation: Exit%1076482787
      //	DESCRIPTION
      //	Leaves a state. Place to set up flags.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Exit (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPCStateIdleStandBy%40279A2A03BF.public preserve=yes
      //## end CPCStateIdleStandBy%40279A2A03BF.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateIdleStandBy%40279A2A03BF.protected preserve=yes
      //## end CPCStateIdleStandBy%40279A2A03BF.protected

  private:
    //## Constructors (generated)
      CPCStateIdleStandBy(const CPCStateIdleStandBy &right);

    //## Assignment Operation (generated)
      const CPCStateIdleStandBy & operator=(const CPCStateIdleStandBy &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateIdleStandBy &right) const;

      bool operator!=(const CPCStateIdleStandBy &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%40279A3A02A6
      //## Role: CPCStateIdleStandBy::pInstance%40279A3B020A
      //## begin CPCStateIdleStandBy::pInstance%40279A3B020A.role preserve=no  public: static CPCStateIdleStandBy {1..1 -> 1..1RFHN}
      static CPCStateIdleStandBy *m_pInstance;
      //## end CPCStateIdleStandBy::pInstance%40279A3B020A.role

    // Additional Private Declarations
      //## begin CPCStateIdleStandBy%40279A2A03BF.private preserve=yes
      //## end CPCStateIdleStandBy%40279A2A03BF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateIdleStandBy%40279A2A03BF.implementation preserve=yes
      //## end CPCStateIdleStandBy%40279A2A03BF.implementation

};

//## begin CPCStateIdleStandBy%40279A2A03BF.postscript preserve=yes
//## end CPCStateIdleStandBy%40279A2A03BF.postscript

// Class CPCStateIdle 

// Class CPCStateIdleStarting 

// Class CPCStateIdlePowerOff 

// Class CPCStateIdleCheckPower 

// Class CPCStateIdleStandBy 

//## begin module%3EED769F037A.epilog preserve=yes
//## end module%3EED769F037A.epilog


#endif
