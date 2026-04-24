//## begin module%3E4104640075.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E4104640075.cm

//## begin module%3E4104640075.cp preserve=no
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
//## end module%3E4104640075.cp

//## Module: EBTCconfig%3E4104640075; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCconfig.h

#ifndef EBTCconfig_h
#define EBTCconfig_h 1

//## begin module%3E4104640075.additionalIncludes preserve=no
//## end module%3E4104640075.additionalIncludes

//## begin module%3E4104640075.includes preserve=yes
//## end module%3E4104640075.includes

// EBTCstat
#include "EBTCstat.h"
//## begin module%3E4104640075.declarations preserve=no
//## end module%3E4104640075.declarations

//## begin module%3E4104640075.additionalDeclarations preserve=yes
//## end module%3E4104640075.additionalDeclarations


//## begin CTCStateConfig%3E4106B80324.preface preserve=yes
//## end CTCStateConfig%3E4106B80324.preface

//## Class: CTCStateConfig%3E4106B80324
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E4793F2033C;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3E479586038A;CTCStateCreated { -> }
//## Uses: <unnamed>%3E47B86300FA;CTCStateProcess { -> }
//## Uses: <unnamed>%3E5B1B8B019E;CTCTemperatureControlImplementation { -> }
//## Uses: <unnamed>%3E689C9D0183;CTCLogic { -> }
//## Uses: <unnamed>%3EE8180D0021;CTCStateNotConnectedProcess { -> }
//## Uses: <unnamed>%3FD0970C03C0;TC_IDENTIFIERS { -> }

class CTCStateConfig : public CTCState  //## Inherits: <unnamed>%3E410EBD022A
{
  //## begin CTCStateConfig%3E4106B80324.initialDeclarations preserve=yes
  //## end CTCStateConfig%3E4106B80324.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateConfig();

    //## Destructor (generated)
      virtual ~CTCStateConfig();


    //## Other Operations (specified)
      //## Operation: Shutdown%1044457420
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: SetConfiguration%1044604253
      virtual void SetConfiguration (ICOStateMachineContext* p_pContext, CPITemperatureControlConfig* p_pConfig);

      //## Operation: CleanupInitialize%1055317629
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

      //## Operation: ConnectionLost%1055335989
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: Startup%1055922854
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

      //## Operation: Stop%1070632807
      virtual void Stop (ICOStateMachineContext* p_pContext);

      //## Operation: CellUndocked%1216975790
      virtual void CellUndocked (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CTCStateConfig%3E4106B80324.public preserve=yes
      //## end CTCStateConfig%3E4106B80324.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateConfig%3E4106B80324.protected preserve=yes
      //## end CTCStateConfig%3E4106B80324.protected

  private:
    //## Constructors (generated)
      CTCStateConfig(const CTCStateConfig &right);

    //## Assignment Operation (generated)
      const CTCStateConfig & operator=(const CTCStateConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateConfig &right) const;

      bool operator!=(const CTCStateConfig &right) const;

    // Additional Private Declarations
      //## begin CTCStateConfig%3E4106B80324.private preserve=yes
      //## end CTCStateConfig%3E4106B80324.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateConfig%3E4106B80324.implementation preserve=yes
      //## end CTCStateConfig%3E4106B80324.implementation

};

//## begin CTCStateConfig%3E4106B80324.postscript preserve=yes
//## end CTCStateConfig%3E4106B80324.postscript

//## begin CTCStateConfigNotSet%3E40E95001FC.preface preserve=yes
//## end CTCStateConfigNotSet%3E40E95001FC.preface

//## Class: CTCStateConfigNotSet%3E40E95001FC
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCStateConfigNotSet : public CTCStateConfig  //## Inherits: <unnamed>%3E411F2700F2
{
  //## begin CTCStateConfigNotSet%3E40E95001FC.initialDeclarations preserve=yes
  //## end CTCStateConfigNotSet%3E40E95001FC.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateConfigNotSet();

    //## Destructor (generated)
      virtual ~CTCStateConfigNotSet();


    //## Other Operations (specified)
      //## Operation: Create%1044457421
      static void Create ();

      //## Operation: GetInstance%1044457422
      static CTCStateConfigNotSet* GetInstance ();

      //## Operation: Delete%1038899332
      static void Delete ();

    // Additional Public Declarations
      //## begin CTCStateConfigNotSet%3E40E95001FC.public preserve=yes
      //## end CTCStateConfigNotSet%3E40E95001FC.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateConfigNotSet%3E40E95001FC.protected preserve=yes
      //## end CTCStateConfigNotSet%3E40E95001FC.protected

  private:
    //## Constructors (generated)
      CTCStateConfigNotSet(const CTCStateConfigNotSet &right);

    //## Assignment Operation (generated)
      const CTCStateConfigNotSet & operator=(const CTCStateConfigNotSet &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateConfigNotSet &right) const;

      bool operator!=(const CTCStateConfigNotSet &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3E4120AE019E
      //## Role: CTCStateConfigNotSet::pInstance%3E4120AF01DD
      //## begin CTCStateConfigNotSet::pInstance%3E4120AF01DD.role preserve=no  public: static CTCStateConfigNotSet {1..1 -> 1..1RFHN}
      static CTCStateConfigNotSet *m_pInstance;
      //## end CTCStateConfigNotSet::pInstance%3E4120AF01DD.role

    // Additional Private Declarations
      //## begin CTCStateConfigNotSet%3E40E95001FC.private preserve=yes
      //## end CTCStateConfigNotSet%3E40E95001FC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateConfigNotSet%3E40E95001FC.implementation preserve=yes
      //## end CTCStateConfigNotSet%3E40E95001FC.implementation

};

//## begin CTCStateConfigNotSet%3E40E95001FC.postscript preserve=yes
//## end CTCStateConfigNotSet%3E40E95001FC.postscript

//## begin CTCStateConfigProfileNotSet%3E41072601FC.preface preserve=yes
//## end CTCStateConfigProfileNotSet%3E41072601FC.preface

//## Class: CTCStateConfigProfileNotSet%3E41072601FC
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCStateConfigProfileNotSet : public CTCStateConfig  //## Inherits: <unnamed>%3E411F360102
{
  //## begin CTCStateConfigProfileNotSet%3E41072601FC.initialDeclarations preserve=yes
  //## end CTCStateConfigProfileNotSet%3E41072601FC.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateConfigProfileNotSet();

    //## Destructor (generated)
      virtual ~CTCStateConfigProfileNotSet();


    //## Other Operations (specified)
      //## Operation: Delete%1044522141
      static void Delete ();

      //## Operation: Create%1044522142
      static void Create ();

      //## Operation: GetInstance%1044522143
      static CTCStateConfigProfileNotSet* GetInstance ();

      //## Operation: SetProfile%1044604256
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPITemperatureControlProfile* p_pProfile);

    // Additional Public Declarations
      //## begin CTCStateConfigProfileNotSet%3E41072601FC.public preserve=yes
      //## end CTCStateConfigProfileNotSet%3E41072601FC.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateConfigProfileNotSet%3E41072601FC.protected preserve=yes
      //## end CTCStateConfigProfileNotSet%3E41072601FC.protected

  private:
    //## Constructors (generated)
      CTCStateConfigProfileNotSet(const CTCStateConfigProfileNotSet &right);

    //## Assignment Operation (generated)
      const CTCStateConfigProfileNotSet & operator=(const CTCStateConfigProfileNotSet &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateConfigProfileNotSet &right) const;

      bool operator!=(const CTCStateConfigProfileNotSet &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3E41200F0305
      //## Role: CTCStateConfigProfileNotSet::pInstance%3E4120100334
      //## begin CTCStateConfigProfileNotSet::pInstance%3E4120100334.role preserve=no  public: static CTCStateConfigProfileNotSet {1..1 -> 1..1RFHN}
      static CTCStateConfigProfileNotSet *m_pInstance;
      //## end CTCStateConfigProfileNotSet::pInstance%3E4120100334.role

    // Additional Private Declarations
      //## begin CTCStateConfigProfileNotSet%3E41072601FC.private preserve=yes
      //## end CTCStateConfigProfileNotSet%3E41072601FC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateConfigProfileNotSet%3E41072601FC.implementation preserve=yes
      //## end CTCStateConfigProfileNotSet%3E41072601FC.implementation

};

//## begin CTCStateConfigProfileNotSet%3E41072601FC.postscript preserve=yes
//## end CTCStateConfigProfileNotSet%3E41072601FC.postscript

//## begin CTCStateConfigSetProfile%3E4107360140.preface preserve=yes
//## end CTCStateConfigSetProfile%3E4107360140.preface

//## Class: CTCStateConfigSetProfile%3E4107360140
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCStateConfigSetProfile : public CTCStateConfig  //## Inherits: <unnamed>%3E411F3B02D6
{
  //## begin CTCStateConfigSetProfile%3E4107360140.initialDeclarations preserve=yes
  //## end CTCStateConfigSetProfile%3E4107360140.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateConfigSetProfile();

    //## Destructor (generated)
      virtual ~CTCStateConfigSetProfile();


    //## Other Operations (specified)
      //## Operation: Delete%1044522144
      static void Delete ();

      //## Operation: Create%1044522145
      static void Create ();

      //## Operation: GetInstance%1044522146
      static CTCStateConfigSetProfile* GetInstance ();

      //## Operation: Do%1044873652
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
      //## begin CTCStateConfigSetProfile%3E4107360140.public preserve=yes
      //## end CTCStateConfigSetProfile%3E4107360140.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateConfigSetProfile%3E4107360140.protected preserve=yes
      //## end CTCStateConfigSetProfile%3E4107360140.protected

  private:
    //## Constructors (generated)
      CTCStateConfigSetProfile(const CTCStateConfigSetProfile &right);

    //## Assignment Operation (generated)
      const CTCStateConfigSetProfile & operator=(const CTCStateConfigSetProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateConfigSetProfile &right) const;

      bool operator!=(const CTCStateConfigSetProfile &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3E41201700B3
      //## Role: CTCStateConfigSetProfile::pInstance%3E41201801FC
      //## begin CTCStateConfigSetProfile::pInstance%3E41201801FC.role preserve=no  public: static CTCStateConfigSetProfile {1..1 -> 1..1RFHN}
      static CTCStateConfigSetProfile *m_pInstance;
      //## end CTCStateConfigSetProfile::pInstance%3E41201801FC.role

    // Additional Private Declarations
      //## begin CTCStateConfigSetProfile%3E4107360140.private preserve=yes
      //## end CTCStateConfigSetProfile%3E4107360140.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateConfigSetProfile%3E4107360140.implementation preserve=yes
      //## end CTCStateConfigSetProfile%3E4107360140.implementation

};

//## begin CTCStateConfigSetProfile%3E4107360140.postscript preserve=yes
//## end CTCStateConfigSetProfile%3E4107360140.postscript

//## begin CTCStateConfigSetConfig%3E410F1E020B.preface preserve=yes
//## end CTCStateConfigSetConfig%3E410F1E020B.preface

//## Class: CTCStateConfigSetConfig%3E410F1E020B
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCStateConfigSetConfig : public CTCStateConfig  //## Inherits: <unnamed>%3E411F2B00E2
{
  //## begin CTCStateConfigSetConfig%3E410F1E020B.initialDeclarations preserve=yes
  //## end CTCStateConfigSetConfig%3E410F1E020B.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateConfigSetConfig();

    //## Destructor (generated)
      virtual ~CTCStateConfigSetConfig();


    //## Other Operations (specified)
      //## Operation: Create%1044522148
      static void Create ();

      //## Operation: GetInstance%1044522149
      static CTCStateConfigSetConfig* GetInstance ();

      //## Operation: Delete%1044522147
      static void Delete ();

      //## Operation: Do%1044873650
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
      //## begin CTCStateConfigSetConfig%3E410F1E020B.public preserve=yes
      //## end CTCStateConfigSetConfig%3E410F1E020B.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateConfigSetConfig%3E410F1E020B.protected preserve=yes
      //## end CTCStateConfigSetConfig%3E410F1E020B.protected

  private:
    //## Constructors (generated)
      CTCStateConfigSetConfig(const CTCStateConfigSetConfig &right);

    //## Assignment Operation (generated)
      const CTCStateConfigSetConfig & operator=(const CTCStateConfigSetConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateConfigSetConfig &right) const;

      bool operator!=(const CTCStateConfigSetConfig &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3E412DD303C1
      //## Role: CTCStateConfigSetConfig::pInstance%3E412DD800A5
      //## begin CTCStateConfigSetConfig::pInstance%3E412DD800A5.role preserve=no  public: static CTCStateConfigSetConfig {1..1 -> 1..1RFHN}
      static CTCStateConfigSetConfig *m_pInstance;
      //## end CTCStateConfigSetConfig::pInstance%3E412DD800A5.role

    // Additional Private Declarations
      //## begin CTCStateConfigSetConfig%3E410F1E020B.private preserve=yes
      //## end CTCStateConfigSetConfig%3E410F1E020B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateConfigSetConfig%3E410F1E020B.implementation preserve=yes
      //## end CTCStateConfigSetConfig%3E410F1E020B.implementation

};

//## begin CTCStateConfigSetConfig%3E410F1E020B.postscript preserve=yes
//## end CTCStateConfigSetConfig%3E410F1E020B.postscript

//## begin CTCStateConfigIdle%3EE6F4F10399.preface preserve=yes
//## end CTCStateConfigIdle%3EE6F4F10399.preface

//## Class: CTCStateConfigIdle%3EE6F4F10399
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%40C94FD00360;CTCPid { -> }
//## Uses: <unnamed>%40C94FD50256;CPITemperatureControlConfig { -> }
//## Uses: <unnamed>%468BB8E9011B;IHIInterface { -> }
//## Uses: <unnamed>%468BB9330349;XCOExceptionCellUndocked { -> }

class CTCStateConfigIdle : public CTCStateConfig  //## Inherits: <unnamed>%3EE6F4F1039D
{
  //## begin CTCStateConfigIdle%3EE6F4F10399.initialDeclarations preserve=yes
  //## end CTCStateConfigIdle%3EE6F4F10399.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateConfigIdle();

    //## Destructor (generated)
      virtual ~CTCStateConfigIdle();


    //## Other Operations (specified)
      //## Operation: Create%1055317650
      static void Create ();

      //## Operation: GetInstance%1055317651
      static CTCStateConfigIdle* GetInstance ();

      //## Operation: Delete%1055317652
      static void Delete ();

      //## Operation: SetProfile%1055317653
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPITemperatureControlProfile* p_pProfile);

      //## Operation: Start%1055335990
      virtual void Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pIncidentSyncObj);

      //## Operation: Enter%1055833092
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

    // Additional Public Declarations
      //## begin CTCStateConfigIdle%3EE6F4F10399.public preserve=yes
      //## end CTCStateConfigIdle%3EE6F4F10399.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateConfigIdle%3EE6F4F10399.protected preserve=yes
      //## end CTCStateConfigIdle%3EE6F4F10399.protected

  private:
    //## Constructors (generated)
      CTCStateConfigIdle(const CTCStateConfigIdle &right);

    //## Assignment Operation (generated)
      const CTCStateConfigIdle & operator=(const CTCStateConfigIdle &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateConfigIdle &right) const;

      bool operator!=(const CTCStateConfigIdle &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3EE6F4F1039E
      //## Role: CTCStateConfigIdle::pInstance%3EE6F4F103A0
      //## begin CTCStateConfigIdle::pInstance%3EE6F4F103A0.role preserve=no  public: static CTCStateConfigIdle {1..1 -> 1..1RFHN}
      static CTCStateConfigIdle *m_pInstance;
      //## end CTCStateConfigIdle::pInstance%3EE6F4F103A0.role

    // Additional Private Declarations
      //## begin CTCStateConfigIdle%3EE6F4F10399.private preserve=yes
      //## end CTCStateConfigIdle%3EE6F4F10399.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateConfigIdle%3EE6F4F10399.implementation preserve=yes
      //## end CTCStateConfigIdle%3EE6F4F10399.implementation

};

//## begin CTCStateConfigIdle%3EE6F4F10399.postscript preserve=yes
//## end CTCStateConfigIdle%3EE6F4F10399.postscript

// Class CTCStateConfig 

// Class CTCStateConfigNotSet 

// Class CTCStateConfigProfileNotSet 

// Class CTCStateConfigSetProfile 

// Class CTCStateConfigSetConfig 

// Class CTCStateConfigIdle 

//## begin module%3E4104640075.epilog preserve=yes
//## end module%3E4104640075.epilog


#endif
