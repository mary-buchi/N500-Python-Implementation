//## begin module%3F93ABA902D5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F93ABA902D5.cm

//## begin module%3F93ABA902D5.cp preserve=no
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
//## end module%3F93ABA902D5.cp

//## Module: EBPOstor%3F93ABA902D5; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOstor.h

#ifndef EBPOstor_h
#define EBPOstor_h 1

//## begin module%3F93ABA902D5.additionalIncludes preserve=no
//## end module%3F93ABA902D5.additionalIncludes

//## begin module%3F93ABA902D5.includes preserve=yes
//## end module%3F93ABA902D5.includes

// EBPOstat
#include "EBPOstat.h"
//## begin module%3F93ABA902D5.declarations preserve=no
//## end module%3F93ABA902D5.declarations

//## begin module%3F93ABA902D5.additionalDeclarations preserve=yes
//## end module%3F93ABA902D5.additionalDeclarations


//## begin CPOStateStore%3F93AE250035.preface preserve=yes
//## end CPOStateStore%3F93AE250035.preface

//## Class: CPOStateStore%3F93AE250035
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F9D17FB01F0;CPOStateIdle { -> }
//## Uses: <unnamed>%3FAFAA270399;CPOLogic { -> }
//## Uses: <unnamed>%4202130E01EE;XCOExceptionCellUndocked { -> }
//## Uses: <unnamed>%42021359025B;CPOLifeTimeCounterHandler { -> }

class CPOStateStore : public CPOState  //## Inherits: <unnamed>%3F93CB4E0239
{
  //## begin CPOStateStore%3F93AE250035.initialDeclarations preserve=yes
  //## end CPOStateStore%3F93AE250035.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateStore();

    //## Destructor (generated)
      virtual ~CPOStateStore();


    //## Other Operations (specified)
      //## Operation: CleanupInitialize%1067251219
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

    // Additional Public Declarations
      //## begin CPOStateStore%3F93AE250035.public preserve=yes
      //## end CPOStateStore%3F93AE250035.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateStore%3F93AE250035.protected preserve=yes
      //## end CPOStateStore%3F93AE250035.protected

  private:
    //## Constructors (generated)
      CPOStateStore(const CPOStateStore &right);

    //## Assignment Operation (generated)
      const CPOStateStore & operator=(const CPOStateStore &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateStore &right) const;

      bool operator!=(const CPOStateStore &right) const;

    // Additional Private Declarations
      //## begin CPOStateStore%3F93AE250035.private preserve=yes
      //## end CPOStateStore%3F93AE250035.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateStore%3F93AE250035.implementation preserve=yes
      //## end CPOStateStore%3F93AE250035.implementation

};

//## begin CPOStateStore%3F93AE250035.postscript preserve=yes
//## end CPOStateStore%3F93AE250035.postscript

//## begin CPOStateStoreReading%3F93AE3B0287.preface preserve=yes
//## end CPOStateStoreReading%3F93AE3B0287.preface

//## Class: CPOStateStoreReading%3F93AE3B0287
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOStateStoreReading : public CPOStateStore  //## Inherits: <unnamed>%420246D201FE
{
  //## begin CPOStateStoreReading%3F93AE3B0287.initialDeclarations preserve=yes
  //## end CPOStateStoreReading%3F93AE3B0287.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateStoreReading();

    //## Destructor (generated)
      virtual ~CPOStateStoreReading();


    //## Other Operations (specified)
      //## Operation: Create%1066889015
      static void Create ();

      //## Operation: Delete%1066889016
      static void Delete ();

      //## Operation: GetInstance%1066889017
      static CPOStateStoreReading * GetInstance ();

      //## Operation: Do%1067251220
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
      //## begin CPOStateStoreReading%3F93AE3B0287.public preserve=yes
      //## end CPOStateStoreReading%3F93AE3B0287.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateStoreReading%3F93AE3B0287.protected preserve=yes
      //## end CPOStateStoreReading%3F93AE3B0287.protected

  private:
    //## Constructors (generated)
      CPOStateStoreReading(const CPOStateStoreReading &right);

    //## Assignment Operation (generated)
      const CPOStateStoreReading & operator=(const CPOStateStoreReading &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateStoreReading &right) const;

      bool operator!=(const CPOStateStoreReading &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97CD9702D6
      //## Role: CPOStateStoreReading::pInstance%3F97CD9801AD
      //## begin CPOStateStoreReading::pInstance%3F97CD9801AD.role preserve=no  public: static CPOStateStoreReading {1..1 -> 1..1RFHN}
      static CPOStateStoreReading *m_pInstance;
      //## end CPOStateStoreReading::pInstance%3F97CD9801AD.role

    // Additional Private Declarations
      //## begin CPOStateStoreReading%3F93AE3B0287.private preserve=yes
      //## end CPOStateStoreReading%3F93AE3B0287.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateStoreReading%3F93AE3B0287.implementation preserve=yes
      //## end CPOStateStoreReading%3F93AE3B0287.implementation

};

//## begin CPOStateStoreReading%3F93AE3B0287.postscript preserve=yes
//## end CPOStateStoreReading%3F93AE3B0287.postscript

//## begin CPOStateStoreParse%3F93AE5101FB.preface preserve=yes
//## end CPOStateStoreParse%3F93AE5101FB.preface

//## Class: CPOStateStoreParse%3F93AE5101FB
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOStateStoreParse : public CPOStateStore  //## Inherits: <unnamed>%420246D50113
{
  //## begin CPOStateStoreParse%3F93AE5101FB.initialDeclarations preserve=yes
  //## end CPOStateStoreParse%3F93AE5101FB.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateStoreParse();

    //## Destructor (generated)
      virtual ~CPOStateStoreParse();


    //## Other Operations (specified)
      //## Operation: Create%1066889012
      static void Create ();

      //## Operation: Delete%1066889013
      static void Delete ();

      //## Operation: GetInstance%1066889014
      static CPOStateStoreParse * GetInstance ();

      //## Operation: Do%1067251221
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
      //## begin CPOStateStoreParse%3F93AE5101FB.public preserve=yes
      //## end CPOStateStoreParse%3F93AE5101FB.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateStoreParse%3F93AE5101FB.protected preserve=yes
      //## end CPOStateStoreParse%3F93AE5101FB.protected

  private:
    //## Constructors (generated)
      CPOStateStoreParse(const CPOStateStoreParse &right);

    //## Assignment Operation (generated)
      const CPOStateStoreParse & operator=(const CPOStateStoreParse &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateStoreParse &right) const;

      bool operator!=(const CPOStateStoreParse &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97CD9A0027
      //## Role: CPOStateStoreParse::pInstance%3F97CD9A026A
      //## begin CPOStateStoreParse::pInstance%3F97CD9A026A.role preserve=no  public: static CPOStateStoreParse {1..1 -> RFHN}
      static CPOStateStoreParse *m_pInstance;
      //## end CPOStateStoreParse::pInstance%3F97CD9A026A.role

    // Additional Private Declarations
      //## begin CPOStateStoreParse%3F93AE5101FB.private preserve=yes
      //## end CPOStateStoreParse%3F93AE5101FB.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateStoreParse%3F93AE5101FB.implementation preserve=yes
      //## end CPOStateStoreParse%3F93AE5101FB.implementation

};

//## begin CPOStateStoreParse%3F93AE5101FB.postscript preserve=yes
//## end CPOStateStoreParse%3F93AE5101FB.postscript

//## begin CPOStateStoreWriting%3F93AE620258.preface preserve=yes
//## end CPOStateStoreWriting%3F93AE620258.preface

//## Class: CPOStateStoreWriting%3F93AE620258
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOStateStoreWriting : public CPOStateStore  //## Inherits: <unnamed>%420246D801A0
{
  //## begin CPOStateStoreWriting%3F93AE620258.initialDeclarations preserve=yes
  //## end CPOStateStoreWriting%3F93AE620258.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateStoreWriting();

    //## Destructor (generated)
      virtual ~CPOStateStoreWriting();


    //## Other Operations (specified)
      //## Operation: Create%1066889009
      static void Create ();

      //## Operation: Delete%1066889010
      static void Delete ();

      //## Operation: GetInstance%1066889011
      static CPOStateStoreWriting * GetInstance ();

      //## Operation: Do%1067251222
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
      //## begin CPOStateStoreWriting%3F93AE620258.public preserve=yes
      //## end CPOStateStoreWriting%3F93AE620258.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateStoreWriting%3F93AE620258.protected preserve=yes
      //## end CPOStateStoreWriting%3F93AE620258.protected

  private:
    //## Constructors (generated)
      CPOStateStoreWriting(const CPOStateStoreWriting &right);

    //## Assignment Operation (generated)
      const CPOStateStoreWriting & operator=(const CPOStateStoreWriting &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateStoreWriting &right) const;

      bool operator!=(const CPOStateStoreWriting &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97CD9C019E
      //## Role: CPOStateStoreWriting::pInstance%3F97CD9D0018
      //## begin CPOStateStoreWriting::pInstance%3F97CD9D0018.role preserve=no  public: static CPOStateStoreWriting {1..1 -> 1..1RFHN}
      static CPOStateStoreWriting *m_pInstance;
      //## end CPOStateStoreWriting::pInstance%3F97CD9D0018.role

    // Additional Private Declarations
      //## begin CPOStateStoreWriting%3F93AE620258.private preserve=yes
      //## end CPOStateStoreWriting%3F93AE620258.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateStoreWriting%3F93AE620258.implementation preserve=yes
      //## end CPOStateStoreWriting%3F93AE620258.implementation

};

//## begin CPOStateStoreWriting%3F93AE620258.postscript preserve=yes
//## end CPOStateStoreWriting%3F93AE620258.postscript

// Class CPOStateStore 

// Class CPOStateStoreReading 

// Class CPOStateStoreParse 

// Class CPOStateStoreWriting 

//## begin module%3F93ABA902D5.epilog preserve=yes
//## end module%3F93ABA902D5.epilog


#endif
