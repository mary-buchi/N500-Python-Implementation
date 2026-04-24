//## begin module%3EED8B5000B3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED8B5000B3.cm

//## begin module%3EED8B5000B3.cp preserve=no
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
//## end module%3EED8B5000B3.cp

//## Module: EBSYcons%3EED8B5000B3; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYcons.h

#ifndef EBSYcons_h
#define EBSYcons_h 1

//## begin module%3EED8B5000B3.additionalIncludes preserve=no
//## end module%3EED8B5000B3.additionalIncludes

//## begin module%3EED8B5000B3.includes preserve=yes
//## end module%3EED8B5000B3.includes

// EBSYstat
#include "EBSYstat.h"
//## begin module%3EED8B5000B3.declarations preserve=no
//## end module%3EED8B5000B3.declarations

//## begin module%3EED8B5000B3.additionalDeclarations preserve=yes
//## end module%3EED8B5000B3.additionalDeclarations


//## begin CSYStateConstitution%3EDC5B9C02DC.preface preserve=yes
//## end CSYStateConstitution%3EDC5B9C02DC.preface

//## Class: CSYStateConstitution%3EDC5B9C02DC
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EF8462600A4;CSYStateShuttingDown { -> }
//## Uses: <unnamed>%4097F5C2029A;CPIComponentsState { -> }
//## Uses: <unnamed>%4097F5F10266;IHIInterface { -> }
//## Uses: <unnamed>%4097F6380222;CPITicksAtStart { -> }
//## Uses: <unnamed>%4097F69B0043;CSYModuleHandling { -> }
//## Uses: <unnamed>%4097F793028F;CPISystem { -> }
//## Uses: <unnamed>%409809E8032D;CPIObjectFactory { -> }

class CSYStateConstitution : public CSYState  //## Inherits: <unnamed>%3EDC5B9C02DE
{
  //## begin CSYStateConstitution%3EDC5B9C02DC.initialDeclarations preserve=yes
  //## end CSYStateConstitution%3EDC5B9C02DC.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitution();

    //## Destructor (generated)
      virtual ~CSYStateConstitution();


    //## Other Operations (specified)
      //## Operation: Shutdown%1044959867
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: GetDeviceState%1056436741
      virtual EPIDeviceState GetDeviceState ();

      //## Operation: Startup%1064318158
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

      //## Operation: GetVersion%1096656419
      virtual void GetVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

      //## Operation: CleanupStop%1083651472
      //	DESCRIPTION
      //	Recovers from a 'Stop Cleanup' exception. State machine
      //	should be broght to the 'Initialized' state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void CleanupStop (ICOStateMachineContext* p_pContext);

      //## Operation: CleanupInitialize%1083651473
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

      //## Operation: GetOsVersion%1108540796
      virtual void GetOsVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

      //## Operation: GetFpgaVersion%1108540797
      virtual void GetFpgaVersion (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

    // Additional Public Declarations
      //## begin CSYStateConstitution%3EDC5B9C02DC.public preserve=yes
      //## end CSYStateConstitution%3EDC5B9C02DC.public

  protected:

    //## Other Operations (specified)
      //## Operation: WarmUp%1083700294
      //	activates the current lamp and turns on the laser
      virtual void WarmUp ();

      //## Operation: SetLmpNomReg%1083700295
      virtual void SetLmpNomReg (const DWORD p_uiRegValue);

    // Additional Protected Declarations
      //## begin CSYStateConstitution%3EDC5B9C02DC.protected preserve=yes
      //## end CSYStateConstitution%3EDC5B9C02DC.protected

  private:
    //## Constructors (generated)
      CSYStateConstitution(const CSYStateConstitution &right);

    //## Assignment Operation (generated)
      const CSYStateConstitution & operator=(const CSYStateConstitution &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitution &right) const;

      bool operator!=(const CSYStateConstitution &right) const;

    // Additional Private Declarations
      //## begin CSYStateConstitution%3EDC5B9C02DC.private preserve=yes
      //## end CSYStateConstitution%3EDC5B9C02DC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitution%3EDC5B9C02DC.implementation preserve=yes
      //## end CSYStateConstitution%3EDC5B9C02DC.implementation

};

//## begin CSYStateConstitution%3EDC5B9C02DC.postscript preserve=yes
//## end CSYStateConstitution%3EDC5B9C02DC.postscript

//## begin CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.preface preserve=yes
//## end CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.preface

//## Class: CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EEDAD350294;CSYStateConstitutionConnected { -> }
//## Uses: <unnamed>%3EF842310075;CPISystem { -> }
//## Uses: <unnamed>%3EFBE69E032E;CSYStateCreated { -> }
//## Uses: <unnamed>%3F9D3475028F;CHIInterface { -> }
//## Uses: <unnamed>%401123C402BC;CSYStateShuttingDown { -> }
//## Uses: <unnamed>%4098888001BC;CSYSystemImplementation { -> }

class CSYStateConstitutionStandByWarmingUp : public CSYStateConstitution  //## Inherits: <unnamed>%4098B1870200
{
  //## begin CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.initialDeclarations preserve=yes
  //## end CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitutionStandByWarmingUp();

    //## Destructor (generated)
      virtual ~CSYStateConstitutionStandByWarmingUp();


    //## Other Operations (specified)
      //## Operation: Create%1044959869
      static void Create ();

      //## Operation: Delete%1044959871
      static void Delete ();

      //## Operation: GetInstance%1044959870
      static CSYStateConstitutionStandByWarmingUp* GetInstance ();

      //## Operation: GetDeviceState%1056436750
      virtual EPIDeviceState GetDeviceState ();

      //## Operation: ConnectionEstablished%1055753492
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: ResetDevice%1056640217
      //	DESCRIPTION
      //	Shutdown system
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ResetDevice (ICOStateMachineContext* p_pContext);

      //## Operation: Enter%1083737618
      //	DESCRIPTION
      //	Enters into a state. Place to set some flags or init
      //	vars.
      //	Actions should be placed in the Do method.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Enter (ICOStateMachineContext* p_pContext);

      //## Operation: OnTimer%1083737619
      //	DESCRIPTION
      //	Notifies the subsystem of a timer event
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void OnTimer (ICOStateMachineContext* p_pContext);

      //## Operation: Exit%1083737620
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
      //## begin CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.public preserve=yes
      //## end CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.protected preserve=yes
      //## end CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.protected

  private:
    //## Constructors (generated)
      CSYStateConstitutionStandByWarmingUp(const CSYStateConstitutionStandByWarmingUp &right);

    //## Assignment Operation (generated)
      const CSYStateConstitutionStandByWarmingUp & operator=(const CSYStateConstitutionStandByWarmingUp &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitutionStandByWarmingUp &right) const;

      bool operator!=(const CSYStateConstitutionStandByWarmingUp &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3EDC5B9C031F
      //## Role: CSYStateConstitutionStandByWarmingUp::pInstance%3EDC5B9C0324
      //## begin CSYStateConstitutionStandByWarmingUp::pInstance%3EDC5B9C0324.role preserve=no  public: static CSYStateConstitutionStandByWarmingUp {1..1 -> 1..1RFHN}
      static CSYStateConstitutionStandByWarmingUp *m_pInstance;
      //## end CSYStateConstitutionStandByWarmingUp::pInstance%3EDC5B9C0324.role

    // Additional Private Declarations
      //## begin CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.private preserve=yes
      //## end CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.implementation preserve=yes
      //## end CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.implementation

};

//## begin CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.postscript preserve=yes
//## end CSYStateConstitutionStandByWarmingUp%3EDC5B9C028E.postscript

//## begin CSYStateConstitutionStartingUp%4097F361038F.preface preserve=yes
//## end CSYStateConstitutionStartingUp%4097F361038F.preface

//## Class: CSYStateConstitutionStartingUp%4097F361038F
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYStateConstitutionStartingUp : public CSYStateConstitution  //## Inherits: <unnamed>%4097F43900E6
{
  //## begin CSYStateConstitutionStartingUp%4097F361038F.initialDeclarations preserve=yes
  //## end CSYStateConstitutionStartingUp%4097F361038F.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitutionStartingUp();

    //## Destructor (generated)
      virtual ~CSYStateConstitutionStartingUp();


    //## Other Operations (specified)
      //## Operation: Create%1083700290
      static void Create ();

      //## Operation: Delete%1083700291
      static void Delete ();

      //## Operation: GetInstance%1083700292
      static CSYStateConstitutionStartingUp* GetInstance ();

      //## Operation: Do%1083700293
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: ReadIPConfig%1199351101
      bool ReadIPConfig (bool& p_bDHCPEnabled, CString& p_sAddress, CString& p_sSubnetMask);

    // Additional Public Declarations
      //## begin CSYStateConstitutionStartingUp%4097F361038F.public preserve=yes
      //## end CSYStateConstitutionStartingUp%4097F361038F.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateConstitutionStartingUp%4097F361038F.protected preserve=yes
      //## end CSYStateConstitutionStartingUp%4097F361038F.protected

  private:
    //## Constructors (generated)
      CSYStateConstitutionStartingUp(const CSYStateConstitutionStartingUp &right);

    //## Assignment Operation (generated)
      const CSYStateConstitutionStartingUp & operator=(const CSYStateConstitutionStartingUp &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitutionStartingUp &right) const;

      bool operator!=(const CSYStateConstitutionStartingUp &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%4097F40703CA
      //## Role: CSYStateConstitutionStartingUp::pInstance%4097F4090110
      //## begin CSYStateConstitutionStartingUp::pInstance%4097F4090110.role preserve=no  public: static CSYStateConstitutionStartingUp {1..1 -> 1..1RFHN}
      static CSYStateConstitutionStartingUp *m_pInstance;
      //## end CSYStateConstitutionStartingUp::pInstance%4097F4090110.role

    // Additional Private Declarations
      //## begin CSYStateConstitutionStartingUp%4097F361038F.private preserve=yes
      //## end CSYStateConstitutionStartingUp%4097F361038F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitutionStartingUp%4097F361038F.implementation preserve=yes
      //## end CSYStateConstitutionStartingUp%4097F361038F.implementation

};

//## begin CSYStateConstitutionStartingUp%4097F361038F.postscript preserve=yes
//## end CSYStateConstitutionStartingUp%4097F361038F.postscript

//## begin CSYStateConstitutionStandBy%40980690021E.preface preserve=yes
//## end CSYStateConstitutionStandBy%40980690021E.preface

//## Class: CSYStateConstitutionStandBy%40980690021E
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYStateConstitutionStandBy : public CSYStateConstitution  //## Inherits: <unnamed>%409806E40034
{
  //## begin CSYStateConstitutionStandBy%40980690021E.initialDeclarations preserve=yes
  //## end CSYStateConstitutionStandBy%40980690021E.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitutionStandBy();

    //## Destructor (generated)
      virtual ~CSYStateConstitutionStandBy();


    //## Other Operations (specified)
      //## Operation: Create%1083700296
      static void Create ();

      //## Operation: Delete%1083700297
      static void Delete ();

      //## Operation: GetInstance%1083700298
      static CSYStateConstitutionStandBy* GetInstance ();

      //## Operation: ConnectionEstablished%1083700300
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: ResetDevice%1083700301
      //	DESCRIPTION
      //	Shutdown system
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ResetDevice (ICOStateMachineContext* p_pContext);

      //## Operation: Enter%1096648862
      //	DESCRIPTION
      //	Enters into a state. Place to set some flags or init
      //	vars.
      //	Actions should be placed in the Do method.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Enter (ICOStateMachineContext* p_pContext);

      //## Operation: Do%1083700299
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
      //## begin CSYStateConstitutionStandBy%40980690021E.public preserve=yes
      //## end CSYStateConstitutionStandBy%40980690021E.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateConstitutionStandBy%40980690021E.protected preserve=yes
      //## end CSYStateConstitutionStandBy%40980690021E.protected

  private:
    //## Constructors (generated)
      CSYStateConstitutionStandBy(const CSYStateConstitutionStandBy &right);

    //## Assignment Operation (generated)
      const CSYStateConstitutionStandBy & operator=(const CSYStateConstitutionStandBy &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitutionStandBy &right) const;

      bool operator!=(const CSYStateConstitutionStandBy &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%409806C60334
      //## Role: CSYStateConstitutionStandBy::pInstance%409806C703A4
      //## begin CSYStateConstitutionStandBy::pInstance%409806C703A4.role preserve=no  public: static CSYStateConstitutionStandBy {1..1 -> 1..1RFHN}
      static CSYStateConstitutionStandBy *m_pInstance;
      //## end CSYStateConstitutionStandBy::pInstance%409806C703A4.role

    // Additional Private Declarations
      //## begin CSYStateConstitutionStandBy%40980690021E.private preserve=yes
      //## end CSYStateConstitutionStandBy%40980690021E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitutionStandBy%40980690021E.implementation preserve=yes
      //## end CSYStateConstitutionStandBy%40980690021E.implementation

};

//## begin CSYStateConstitutionStandBy%40980690021E.postscript preserve=yes
//## end CSYStateConstitutionStandBy%40980690021E.postscript

//## begin CSYStateConstitutionConsiderInterfaceReset%4110FD380329.preface preserve=yes
//## end CSYStateConstitutionConsiderInterfaceReset%4110FD380329.preface

//## Class: CSYStateConstitutionConsiderInterfaceReset%4110FD380329
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSYStateConstitutionConsiderInterfaceReset : public CSYStateConstitution  //## Inherits: <unnamed>%4110FDC10193
{
  //## begin CSYStateConstitutionConsiderInterfaceReset%4110FD380329.initialDeclarations preserve=yes
  //## end CSYStateConstitutionConsiderInterfaceReset%4110FD380329.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitutionConsiderInterfaceReset();

    //## Destructor (generated)
      virtual ~CSYStateConstitutionConsiderInterfaceReset();


    //## Other Operations (specified)
      //## Operation: Create%1091609205
      static void Create ();

      //## Operation: Delete%1091609206
      static void Delete ();

      //## Operation: GetInstance%1091609207
      static CSYStateConstitutionConsiderInterfaceReset* GetInstance ();

      //## Operation: Do%1091609208
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
      //## begin CSYStateConstitutionConsiderInterfaceReset%4110FD380329.public preserve=yes
      //## end CSYStateConstitutionConsiderInterfaceReset%4110FD380329.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateConstitutionConsiderInterfaceReset%4110FD380329.protected preserve=yes
      //## end CSYStateConstitutionConsiderInterfaceReset%4110FD380329.protected

  private:
    //## Constructors (generated)
      CSYStateConstitutionConsiderInterfaceReset(const CSYStateConstitutionConsiderInterfaceReset &right);

    //## Assignment Operation (generated)
      const CSYStateConstitutionConsiderInterfaceReset & operator=(const CSYStateConstitutionConsiderInterfaceReset &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitutionConsiderInterfaceReset &right) const;

      bool operator!=(const CSYStateConstitutionConsiderInterfaceReset &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%4110FD80030A
      //## Role: CSYStateConstitutionConsiderInterfaceReset::pInstance%4110FD82002C
      //## begin CSYStateConstitutionConsiderInterfaceReset::pInstance%4110FD82002C.role preserve=no  public: static CSYStateConstitutionConsiderInterfaceReset {1..1 -> 1..1RFHN}
      static CSYStateConstitutionConsiderInterfaceReset *m_pInstance;
      //## end CSYStateConstitutionConsiderInterfaceReset::pInstance%4110FD82002C.role

    // Additional Private Declarations
      //## begin CSYStateConstitutionConsiderInterfaceReset%4110FD380329.private preserve=yes
      //## end CSYStateConstitutionConsiderInterfaceReset%4110FD380329.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitutionConsiderInterfaceReset%4110FD380329.implementation preserve=yes
      //## end CSYStateConstitutionConsiderInterfaceReset%4110FD380329.implementation

};

//## begin CSYStateConstitutionConsiderInterfaceReset%4110FD380329.postscript preserve=yes
//## end CSYStateConstitutionConsiderInterfaceReset%4110FD380329.postscript

//## begin CSYStateConstitutionResetInterface%4110FDDD0164.preface preserve=yes
//## end CSYStateConstitutionResetInterface%4110FDDD0164.preface

//## Class: CSYStateConstitutionResetInterface%4110FDDD0164
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%411100FF0367;CSYInterfaceSettings { -> }

class CSYStateConstitutionResetInterface : public CSYStateConstitution  //## Inherits: <unnamed>%4110FE420135
{
  //## begin CSYStateConstitutionResetInterface%4110FDDD0164.initialDeclarations preserve=yes
  //## end CSYStateConstitutionResetInterface%4110FDDD0164.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitutionResetInterface();

    //## Destructor (generated)
      virtual ~CSYStateConstitutionResetInterface();


    //## Other Operations (specified)
      //## Operation: Create%1091609209
      static void Create ();

      //## Operation: Delete%1091609210
      static void Delete ();

      //## Operation: GetInstance%1091609211
      static CSYStateConstitutionResetInterface* GetInstance ();

      //## Operation: Do%1091609212
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
      //## begin CSYStateConstitutionResetInterface%4110FDDD0164.public preserve=yes
      //## end CSYStateConstitutionResetInterface%4110FDDD0164.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateConstitutionResetInterface%4110FDDD0164.protected preserve=yes
      //## end CSYStateConstitutionResetInterface%4110FDDD0164.protected

  private:
    //## Constructors (generated)
      CSYStateConstitutionResetInterface(const CSYStateConstitutionResetInterface &right);

    //## Assignment Operation (generated)
      const CSYStateConstitutionResetInterface & operator=(const CSYStateConstitutionResetInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitutionResetInterface &right) const;

      bool operator!=(const CSYStateConstitutionResetInterface &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%4110FE1D0099
      //## Role: CSYStateConstitutionResetInterface::pInstance%4110FE1F0201
      //## begin CSYStateConstitutionResetInterface::pInstance%4110FE1F0201.role preserve=no  public: static CSYStateConstitutionResetInterface {1..1 -> 1..1RFHN}
      static CSYStateConstitutionResetInterface *m_pInstance;
      //## end CSYStateConstitutionResetInterface::pInstance%4110FE1F0201.role

    // Additional Private Declarations
      //## begin CSYStateConstitutionResetInterface%4110FDDD0164.private preserve=yes
      //## end CSYStateConstitutionResetInterface%4110FDDD0164.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitutionResetInterface%4110FDDD0164.implementation preserve=yes
      //## end CSYStateConstitutionResetInterface%4110FDDD0164.implementation

};

//## begin CSYStateConstitutionResetInterface%4110FDDD0164.postscript preserve=yes
//## end CSYStateConstitutionResetInterface%4110FDDD0164.postscript

// Class CSYStateConstitution 

// Class CSYStateConstitutionStandByWarmingUp 

// Class CSYStateConstitutionStartingUp 

// Class CSYStateConstitutionStandBy 

// Class CSYStateConstitutionConsiderInterfaceReset 

// Class CSYStateConstitutionResetInterface 

//## begin module%3EED8B5000B3.epilog preserve=yes
//## end module%3EED8B5000B3.epilog


#endif
