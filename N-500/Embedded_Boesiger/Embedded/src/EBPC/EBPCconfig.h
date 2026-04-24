//## begin module%3EED769F0388.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F0388.cm

//## begin module%3EED769F0388.cp preserve=no
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
//## end module%3EED769F0388.cp

//## Module: EBPCconfig%3EED769F0388; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCconfig.h

#ifndef EBPCconfig_h
#define EBPCconfig_h 1

//## begin module%3EED769F0388.additionalIncludes preserve=no
//## end module%3EED769F0388.additionalIncludes

//## begin module%3EED769F0388.includes preserve=yes
//## end module%3EED769F0388.includes

// EBPCstat
#include "EBPCstat.h"
//## begin module%3EED769F0388.declarations preserve=no
//## end module%3EED769F0388.declarations

//## begin module%3EED769F0388.additionalDeclarations preserve=yes
//## end module%3EED769F0388.additionalDeclarations


//## begin CPCStateConfig%3EED76CC069A.preface preserve=yes
//## end CPCStateConfig%3EED76CC069A.preface

//## Class: CPCStateConfig%3EED76CC069A
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EED76CC069F;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3EED76CC06A2;CPCStateCreated { -> }
//## Uses: <unnamed>%3EED76CC06A8;CPITemperatureControlConfig { -> }
//## Uses: <unnamed>%3EED76CC06AB;CPCPowerControlImplementation { -> }
//## Uses: <unnamed>%3EED76CC06AE;CPCLogic { -> }
//## Uses: <unnamed>%3EED76CC06B1;CPCStateNotConnected { -> }
//## Uses: <unnamed>%3F8E570303AF;PC_IDENTIFIERS { -> }

class CPCStateConfig : public CPCState  //## Inherits: <unnamed>%3EED76CC069C
{
  //## begin CPCStateConfig%3EED76CC069A.initialDeclarations preserve=yes
  //## end CPCStateConfig%3EED76CC069A.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateConfig();

    //## Destructor (generated)
      virtual ~CPCStateConfig();


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
      virtual void SetConfiguration (ICOStateMachineContext* p_pContext, CPIPowerControlConfig* p_pConfig);

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

      //## Operation: Startup%1063717517
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

    // Additional Public Declarations
      //## begin CPCStateConfig%3EED76CC069A.public preserve=yes
      //## end CPCStateConfig%3EED76CC069A.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateConfig%3EED76CC069A.protected preserve=yes
      //## end CPCStateConfig%3EED76CC069A.protected

  private:
    //## Constructors (generated)
      CPCStateConfig(const CPCStateConfig &right);

    //## Assignment Operation (generated)
      const CPCStateConfig & operator=(const CPCStateConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateConfig &right) const;

      bool operator!=(const CPCStateConfig &right) const;

    // Additional Private Declarations
      //## begin CPCStateConfig%3EED76CC069A.private preserve=yes
      //## end CPCStateConfig%3EED76CC069A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateConfig%3EED76CC069A.implementation preserve=yes
      //## end CPCStateConfig%3EED76CC069A.implementation

};

//## begin CPCStateConfig%3EED76CC069A.postscript preserve=yes
//## end CPCStateConfig%3EED76CC069A.postscript

//## begin CPCStateConfigNotSet%3EED76CC068D.preface preserve=yes
//## end CPCStateConfigNotSet%3EED76CC068D.preface

//## Class: CPCStateConfigNotSet%3EED76CC068D
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPCStateConfigNotSet : public CPCStateConfig  //## Inherits: <unnamed>%3EED76CC068F
{
  //## begin CPCStateConfigNotSet%3EED76CC068D.initialDeclarations preserve=yes
  //## end CPCStateConfigNotSet%3EED76CC068D.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateConfigNotSet();

    //## Destructor (generated)
      virtual ~CPCStateConfigNotSet();


    //## Other Operations (specified)
      //## Operation: Create%1044457421
      static void Create ();

      //## Operation: GetInstance%1044457422
      static CPCStateConfigNotSet* GetInstance ();

      //## Operation: Delete%1038899332
      static void Delete ();

    // Additional Public Declarations
      //## begin CPCStateConfigNotSet%3EED76CC068D.public preserve=yes
      //## end CPCStateConfigNotSet%3EED76CC068D.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateConfigNotSet%3EED76CC068D.protected preserve=yes
      //## end CPCStateConfigNotSet%3EED76CC068D.protected

  private:
    //## Constructors (generated)
      CPCStateConfigNotSet(const CPCStateConfigNotSet &right);

    //## Assignment Operation (generated)
      const CPCStateConfigNotSet & operator=(const CPCStateConfigNotSet &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateConfigNotSet &right) const;

      bool operator!=(const CPCStateConfigNotSet &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%3EED76CC08BB
      //## Role: CPCStateConfigNotSet::pInstance%3EED76CC08C0
      //## begin CPCStateConfigNotSet::pInstance%3EED76CC08C0.role preserve=no  public: static CPCStateConfigNotSet {1..1 -> 1..1RFHN}
      static CPCStateConfigNotSet *m_pInstance;
      //## end CPCStateConfigNotSet::pInstance%3EED76CC08C0.role

    // Additional Private Declarations
      //## begin CPCStateConfigNotSet%3EED76CC068D.private preserve=yes
      //## end CPCStateConfigNotSet%3EED76CC068D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateConfigNotSet%3EED76CC068D.implementation preserve=yes
      //## end CPCStateConfigNotSet%3EED76CC068D.implementation

};

//## begin CPCStateConfigNotSet%3EED76CC068D.postscript preserve=yes
//## end CPCStateConfigNotSet%3EED76CC068D.postscript

//## begin CPCStateConfigProfileNotSet%3EED76CC06ED.preface preserve=yes
//## end CPCStateConfigProfileNotSet%3EED76CC06ED.preface

//## Class: CPCStateConfigProfileNotSet%3EED76CC06ED
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPCStateConfigProfileNotSet : public CPCStateConfig  //## Inherits: <unnamed>%3EED76CC06EF
{
  //## begin CPCStateConfigProfileNotSet%3EED76CC06ED.initialDeclarations preserve=yes
  //## end CPCStateConfigProfileNotSet%3EED76CC06ED.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateConfigProfileNotSet();

    //## Destructor (generated)
      virtual ~CPCStateConfigProfileNotSet();


    //## Other Operations (specified)
      //## Operation: Delete%1044522141
      static void Delete ();

      //## Operation: Create%1044522142
      static void Create ();

      //## Operation: GetInstance%1044522143
      static CPCStateConfigProfileNotSet* GetInstance ();

      //## Operation: SetProfile%1044604256
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPIPowerControlProfile* p_pProfile);

    // Additional Public Declarations
      //## begin CPCStateConfigProfileNotSet%3EED76CC06ED.public preserve=yes
      //## end CPCStateConfigProfileNotSet%3EED76CC06ED.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateConfigProfileNotSet%3EED76CC06ED.protected preserve=yes
      //## end CPCStateConfigProfileNotSet%3EED76CC06ED.protected

  private:
    //## Constructors (generated)
      CPCStateConfigProfileNotSet(const CPCStateConfigProfileNotSet &right);

    //## Assignment Operation (generated)
      const CPCStateConfigProfileNotSet & operator=(const CPCStateConfigProfileNotSet &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateConfigProfileNotSet &right) const;

      bool operator!=(const CPCStateConfigProfileNotSet &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%3EED76CC08AB
      //## Role: CPCStateConfigProfileNotSet::pInstance%3EED76CC08B0
      //## begin CPCStateConfigProfileNotSet::pInstance%3EED76CC08B0.role preserve=no  public: static CPCStateConfigProfileNotSet {1..1 -> 1..1RFHN}
      static CPCStateConfigProfileNotSet *m_pInstance;
      //## end CPCStateConfigProfileNotSet::pInstance%3EED76CC08B0.role

    // Additional Private Declarations
      //## begin CPCStateConfigProfileNotSet%3EED76CC06ED.private preserve=yes
      //## end CPCStateConfigProfileNotSet%3EED76CC06ED.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateConfigProfileNotSet%3EED76CC06ED.implementation preserve=yes
      //## end CPCStateConfigProfileNotSet%3EED76CC06ED.implementation

};

//## begin CPCStateConfigProfileNotSet%3EED76CC06ED.postscript preserve=yes
//## end CPCStateConfigProfileNotSet%3EED76CC06ED.postscript

//## begin CPCStateConfigProfileSet%3EED76CC0701.preface preserve=yes
//## end CPCStateConfigProfileSet%3EED76CC0701.preface

//## Class: CPCStateConfigProfileSet%3EED76CC0701
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%4027ADFF0381;CPCStateIdleCheckPower { -> }

class CPCStateConfigProfileSet : public CPCStateConfig  //## Inherits: <unnamed>%3EED76CC0703
{
  //## begin CPCStateConfigProfileSet%3EED76CC0701.initialDeclarations preserve=yes
  //## end CPCStateConfigProfileSet%3EED76CC0701.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateConfigProfileSet();

    //## Destructor (generated)
      virtual ~CPCStateConfigProfileSet();


    //## Other Operations (specified)
      //## Operation: Delete%1044522144
      static void Delete ();

      //## Operation: Create%1044522145
      static void Create ();

      //## Operation: GetInstance%1044522146
      static CPCStateConfigProfileSet* GetInstance ();

      //## Operation: Do%1076339192
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
      //## begin CPCStateConfigProfileSet%3EED76CC0701.public preserve=yes
      //## end CPCStateConfigProfileSet%3EED76CC0701.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateConfigProfileSet%3EED76CC0701.protected preserve=yes
      //## end CPCStateConfigProfileSet%3EED76CC0701.protected

  private:
    //## Constructors (generated)
      CPCStateConfigProfileSet(const CPCStateConfigProfileSet &right);

    //## Assignment Operation (generated)
      const CPCStateConfigProfileSet & operator=(const CPCStateConfigProfileSet &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateConfigProfileSet &right) const;

      bool operator!=(const CPCStateConfigProfileSet &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%3EED76CC08B3
      //## Role: CPCStateConfigProfileSet::pInstance%3EED76CC08B8
      //## begin CPCStateConfigProfileSet::pInstance%3EED76CC08B8.role preserve=no  public: static CPCStateConfigProfileSet {1..1 -> 1..1RFHN}
      static CPCStateConfigProfileSet *m_pInstance;
      //## end CPCStateConfigProfileSet::pInstance%3EED76CC08B8.role

    // Additional Private Declarations
      //## begin CPCStateConfigProfileSet%3EED76CC0701.private preserve=yes
      //## end CPCStateConfigProfileSet%3EED76CC0701.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateConfigProfileSet%3EED76CC0701.implementation preserve=yes
      //## end CPCStateConfigProfileSet%3EED76CC0701.implementation

};

//## begin CPCStateConfigProfileSet%3EED76CC0701.postscript preserve=yes
//## end CPCStateConfigProfileSet%3EED76CC0701.postscript

//## begin CPCStateConfigSet%3EED76CC0734.preface preserve=yes
//## end CPCStateConfigSet%3EED76CC0734.preface

//## Class: CPCStateConfigSet%3EED76CC0734
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%40346D1902A7;CPCPid { -> }

class CPCStateConfigSet : public CPCStateConfig  //## Inherits: <unnamed>%3EED76CC0736
{
  //## begin CPCStateConfigSet%3EED76CC0734.initialDeclarations preserve=yes
  //## end CPCStateConfigSet%3EED76CC0734.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateConfigSet();

    //## Destructor (generated)
      virtual ~CPCStateConfigSet();


    //## Other Operations (specified)
      //## Operation: Create%1044522148
      static void Create ();

      //## Operation: GetInstance%1044522149
      static CPCStateConfigSet* GetInstance ();

      //## Operation: Delete%1044522147
      static void Delete ();

      //## Operation: Do%1076339194
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
      //## begin CPCStateConfigSet%3EED76CC0734.public preserve=yes
      //## end CPCStateConfigSet%3EED76CC0734.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateConfigSet%3EED76CC0734.protected preserve=yes
      //## end CPCStateConfigSet%3EED76CC0734.protected

  private:
    //## Constructors (generated)
      CPCStateConfigSet(const CPCStateConfigSet &right);

    //## Assignment Operation (generated)
      const CPCStateConfigSet & operator=(const CPCStateConfigSet &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateConfigSet &right) const;

      bool operator!=(const CPCStateConfigSet &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%3EED76CC08D3
      //## Role: CPCStateConfigSet::pInstance%3EED76CC08D8
      //## begin CPCStateConfigSet::pInstance%3EED76CC08D8.role preserve=no  public: static CPCStateConfigSet {1..1 -> 1..1RFHN}
      static CPCStateConfigSet *m_pInstance;
      //## end CPCStateConfigSet::pInstance%3EED76CC08D8.role

    // Additional Private Declarations
      //## begin CPCStateConfigSet%3EED76CC0734.private preserve=yes
      //## end CPCStateConfigSet%3EED76CC0734.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateConfigSet%3EED76CC0734.implementation preserve=yes
      //## end CPCStateConfigSet%3EED76CC0734.implementation

};

//## begin CPCStateConfigSet%3EED76CC0734.postscript preserve=yes
//## end CPCStateConfigSet%3EED76CC0734.postscript

// Class CPCStateConfig 

// Class CPCStateConfigNotSet 

// Class CPCStateConfigProfileNotSet 

// Class CPCStateConfigProfileSet 

// Class CPCStateConfigSet 

//## begin module%3EED769F0388.epilog preserve=yes
//## end module%3EED769F0388.epilog


#endif
