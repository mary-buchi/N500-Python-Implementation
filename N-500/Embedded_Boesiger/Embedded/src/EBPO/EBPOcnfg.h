//## begin module%3F93A8D50249.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F93A8D50249.cm

//## begin module%3F93A8D50249.cp preserve=no
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
//## end module%3F93A8D50249.cp

//## Module: EBPOcnfg%3F93A8D50249; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOcnfg.h

#ifndef EBPOcnfg_h
#define EBPOcnfg_h 1

//## begin module%3F93A8D50249.additionalIncludes preserve=no
//## end module%3F93A8D50249.additionalIncludes

//## begin module%3F93A8D50249.includes preserve=yes
//## end module%3F93A8D50249.includes

// EBPOstat
#include "EBPOstat.h"
//## begin module%3F93A8D50249.declarations preserve=no
//## end module%3F93A8D50249.declarations

//## begin module%3F93A8D50249.additionalDeclarations preserve=yes
//## end module%3F93A8D50249.additionalDeclarations


//## begin CPOStateConfig%3F93AD120120.preface preserve=yes
//## end CPOStateConfig%3F93AD120120.preface

//## Class: CPOStateConfig%3F93AD120120
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F9CE0C40144;CPOStateIdle { -> }
//## Uses: <unnamed>%3FA60DE1036B;CPOStateNotConnected { -> }
//## Uses: <unnamed>%3FA66F550399;CPOEpromManager { -> }
//## Uses: <unnamed>%40050056030D;CPOLogic { -> }

class CPOStateConfig : public CPOState  //## Inherits: <unnamed>%3F93B1A0017E
{
  //## begin CPOStateConfig%3F93AD120120.initialDeclarations preserve=yes
  //## end CPOStateConfig%3F93AD120120.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateConfig();

    //## Destructor (generated)
      virtual ~CPOStateConfig();


    //## Other Operations (specified)
      //## Operation: Startup%1067238812
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

      //## Operation: SetConfig%1067238813
      //	DESCRIPTION
      //	Configurates the persistent object parameters
      //
      //	PARAMETERS
      //	p_PersistentConfig
      //
      //	RETURNS
      //	async void
      virtual void SetConfig (ICOStateMachineContext* p_pContext, CPIPersistentConfig* p_pConfig);

      //## Operation: CleanupInitialize%1067238814
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

      //## Operation: ConnectionLost%1067243913
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1067262118
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPOStateConfig%3F93AD120120.public preserve=yes
      //## end CPOStateConfig%3F93AD120120.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateConfig%3F93AD120120.protected preserve=yes
      //## end CPOStateConfig%3F93AD120120.protected

  private:
    //## Constructors (generated)
      CPOStateConfig(const CPOStateConfig &right);

    //## Assignment Operation (generated)
      const CPOStateConfig & operator=(const CPOStateConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateConfig &right) const;

      bool operator!=(const CPOStateConfig &right) const;

    // Additional Private Declarations
      //## begin CPOStateConfig%3F93AD120120.private preserve=yes
      //## end CPOStateConfig%3F93AD120120.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateConfig%3F93AD120120.implementation preserve=yes
      //## end CPOStateConfig%3F93AD120120.implementation

};

//## begin CPOStateConfig%3F93AD120120.postscript preserve=yes
//## end CPOStateConfig%3F93AD120120.postscript

//## begin CPOStateConfigStart%3F93AD2F0074.preface preserve=yes
//## end CPOStateConfigStart%3F93AD2F0074.preface

//## Class: CPOStateConfigStart%3F93AD2F0074
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%405AD10501DE;CPOLifeTimeCounterHandler { -> }

class CPOStateConfigStart : public CPOStateConfig  //## Inherits: <unnamed>%3F93B1E80268
{
  //## begin CPOStateConfigStart%3F93AD2F0074.initialDeclarations preserve=yes
  //## end CPOStateConfigStart%3F93AD2F0074.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateConfigStart();

    //## Destructor (generated)
      virtual ~CPOStateConfigStart();


    //## Other Operations (specified)
      //## Operation: Create%1066888991
      static void Create ();

      //## Operation: Delete%1066888992
      static void Delete ();

      //## Operation: GetInstance%1066888993
      static CPOStateConfigStart* GetInstance ();

      //## Operation: Do%1067238815
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
      //## begin CPOStateConfigStart%3F93AD2F0074.public preserve=yes
      //## end CPOStateConfigStart%3F93AD2F0074.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateConfigStart%3F93AD2F0074.protected preserve=yes
      //## end CPOStateConfigStart%3F93AD2F0074.protected

  private:
    //## Constructors (generated)
      CPOStateConfigStart(const CPOStateConfigStart &right);

    //## Assignment Operation (generated)
      const CPOStateConfigStart & operator=(const CPOStateConfigStart &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateConfigStart &right) const;

      bool operator!=(const CPOStateConfigStart &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97CD8A0140
      //## Role: CPOStateConfigStart::pInstance%3F97CD8B00D3
      //## begin CPOStateConfigStart::pInstance%3F97CD8B00D3.role preserve=no  public: static CPOStateConfigStart {1..1 -> 1..1RFHN}
      static CPOStateConfigStart *m_pInstance;
      //## end CPOStateConfigStart::pInstance%3F97CD8B00D3.role

    // Additional Private Declarations
      //## begin CPOStateConfigStart%3F93AD2F0074.private preserve=yes
      //## end CPOStateConfigStart%3F93AD2F0074.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateConfigStart%3F93AD2F0074.implementation preserve=yes
      //## end CPOStateConfigStart%3F93AD2F0074.implementation

};

//## begin CPOStateConfigStart%3F93AD2F0074.postscript preserve=yes
//## end CPOStateConfigStart%3F93AD2F0074.postscript

//## begin CPOStateConfigAssigned%3F93AD8501FB.preface preserve=yes
//## end CPOStateConfigAssigned%3F93AD8501FB.preface

//## Class: CPOStateConfigAssigned%3F93AD8501FB
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOStateConfigAssigned : public CPOStateConfig  //## Inherits: <unnamed>%3F93B1BD02D5
{
  //## begin CPOStateConfigAssigned%3F93AD8501FB.initialDeclarations preserve=yes
  //## end CPOStateConfigAssigned%3F93AD8501FB.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateConfigAssigned();

    //## Destructor (generated)
      virtual ~CPOStateConfigAssigned();


    //## Other Operations (specified)
      //## Operation: Create%1066888994
      static void Create ();

      //## Operation: Delete%1066888995
      static void Delete ();

      //## Operation: GetInstance%1066888996
      static CPOStateConfigAssigned * GetInstance ();

      //## Operation: Do%1067238816
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
      //## begin CPOStateConfigAssigned%3F93AD8501FB.public preserve=yes
      //## end CPOStateConfigAssigned%3F93AD8501FB.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateConfigAssigned%3F93AD8501FB.protected preserve=yes
      //## end CPOStateConfigAssigned%3F93AD8501FB.protected

  private:
    //## Constructors (generated)
      CPOStateConfigAssigned(const CPOStateConfigAssigned &right);

    //## Assignment Operation (generated)
      const CPOStateConfigAssigned & operator=(const CPOStateConfigAssigned &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateConfigAssigned &right) const;

      bool operator!=(const CPOStateConfigAssigned &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97CD8D0101
      //## Role: CPOStateConfigAssigned::pInstance%3F97CD8E0066
      //## begin CPOStateConfigAssigned::pInstance%3F97CD8E0066.role preserve=no  public: static CPOStateConfigAssigned {1..1 -> 1..1RFHN}
      static CPOStateConfigAssigned *m_pInstance;
      //## end CPOStateConfigAssigned::pInstance%3F97CD8E0066.role

    // Additional Private Declarations
      //## begin CPOStateConfigAssigned%3F93AD8501FB.private preserve=yes
      //## end CPOStateConfigAssigned%3F93AD8501FB.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateConfigAssigned%3F93AD8501FB.implementation preserve=yes
      //## end CPOStateConfigAssigned%3F93AD8501FB.implementation

};

//## begin CPOStateConfigAssigned%3F93AD8501FB.postscript preserve=yes
//## end CPOStateConfigAssigned%3F93AD8501FB.postscript

// Class CPOStateConfig 

// Class CPOStateConfigStart 

// Class CPOStateConfigAssigned 

//## begin module%3F93A8D50249.epilog preserve=yes
//## end module%3F93A8D50249.epilog


#endif
