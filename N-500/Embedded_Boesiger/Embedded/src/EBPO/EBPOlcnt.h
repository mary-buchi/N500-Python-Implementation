//## begin module%3F93A93A0064.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F93A93A0064.cm

//## begin module%3F93A93A0064.cp preserve=no
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
//## end module%3F93A93A0064.cp

//## Module: EBPOlcnt%3F93A93A0064; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOlcnt.h

#ifndef EBPOlcnt_h
#define EBPOlcnt_h 1

//## begin module%3F93A93A0064.additionalIncludes preserve=no
//## end module%3F93A93A0064.additionalIncludes

//## begin module%3F93A93A0064.includes preserve=yes
//## end module%3F93A93A0064.includes

// EBPOstat
#include "EBPOstat.h"
//## begin module%3F93A93A0064.declarations preserve=no
//## end module%3F93A93A0064.declarations

//## begin module%3F93A93A0064.additionalDeclarations preserve=yes
//## end module%3F93A93A0064.additionalDeclarations


//## begin CPOStateLifeTimeCounter%3F9E208F0333.preface preserve=yes
//## end CPOStateLifeTimeCounter%3F9E208F0333.preface

//## Class: CPOStateLifeTimeCounter%3F9E208F0333
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F9E21090120;CPOStateIdle { -> }
//## Uses: <unnamed>%3F9E426F0026;CPOLifeTimeCounterHandler { -> }
//## Uses: <unnamed>%420213740142;XCOExceptionCellUndocked { -> }
//## Uses: <unnamed>%420213780317;CPOLifeTimeCounterHandler { -> }
//## Uses: <unnamed>%42025997029A;CPOLogic { -> }

class CPOStateLifeTimeCounter : public CPOState  //## Inherits: <unnamed>%3F9E20B30352
{
  //## begin CPOStateLifeTimeCounter%3F9E208F0333.initialDeclarations preserve=yes
  //## end CPOStateLifeTimeCounter%3F9E208F0333.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateLifeTimeCounter();

    //## Destructor (generated)
      virtual ~CPOStateLifeTimeCounter();


    //## Other Operations (specified)
      //## Operation: CleanupInitialize%1067325000
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
      //## begin CPOStateLifeTimeCounter%3F9E208F0333.public preserve=yes
      //## end CPOStateLifeTimeCounter%3F9E208F0333.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateLifeTimeCounter%3F9E208F0333.protected preserve=yes
      //## end CPOStateLifeTimeCounter%3F9E208F0333.protected

  private:
    //## Constructors (generated)
      CPOStateLifeTimeCounter(const CPOStateLifeTimeCounter &right);

    //## Assignment Operation (generated)
      const CPOStateLifeTimeCounter & operator=(const CPOStateLifeTimeCounter &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateLifeTimeCounter &right) const;

      bool operator!=(const CPOStateLifeTimeCounter &right) const;

    // Additional Private Declarations
      //## begin CPOStateLifeTimeCounter%3F9E208F0333.private preserve=yes
      //## end CPOStateLifeTimeCounter%3F9E208F0333.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateLifeTimeCounter%3F9E208F0333.implementation preserve=yes
      //## end CPOStateLifeTimeCounter%3F9E208F0333.implementation

};

//## begin CPOStateLifeTimeCounter%3F9E208F0333.postscript preserve=yes
//## end CPOStateLifeTimeCounter%3F9E208F0333.postscript

//## begin CPOStateLifeTimeCounterSum%3F93AEB500E1.preface preserve=yes
//## end CPOStateLifeTimeCounterSum%3F93AEB500E1.preface

//## Class: CPOStateLifeTimeCounterSum%3F93AEB500E1
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOStateLifeTimeCounterSum : public CPOStateLifeTimeCounter  //## Inherits: <unnamed>%3F9E20B80304
{
  //## begin CPOStateLifeTimeCounterSum%3F93AEB500E1.initialDeclarations preserve=yes
  //## end CPOStateLifeTimeCounterSum%3F93AEB500E1.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateLifeTimeCounterSum();

    //## Destructor (generated)
      virtual ~CPOStateLifeTimeCounterSum();


    //## Other Operations (specified)
      //## Operation: Create%1066889006
      static void Create ();

      //## Operation: Delete%1066889007
      static void Delete ();

      //## Operation: GetInstance%1066889008
      static CPOStateLifeTimeCounterSum* GetInstance ();

      //## Operation: Do%1067251216
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
      //## begin CPOStateLifeTimeCounterSum%3F93AEB500E1.public preserve=yes
      //## end CPOStateLifeTimeCounterSum%3F93AEB500E1.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateLifeTimeCounterSum%3F93AEB500E1.protected preserve=yes
      //## end CPOStateLifeTimeCounterSum%3F93AEB500E1.protected

  private:
    //## Constructors (generated)
      CPOStateLifeTimeCounterSum(const CPOStateLifeTimeCounterSum &right);

    //## Assignment Operation (generated)
      const CPOStateLifeTimeCounterSum & operator=(const CPOStateLifeTimeCounterSum &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateLifeTimeCounterSum &right) const;

      bool operator!=(const CPOStateLifeTimeCounterSum &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97CD950130
      //## Role: CPOStateLifeTimeCounterSum::pInstance%3F97CD960007
      //## begin CPOStateLifeTimeCounterSum::pInstance%3F97CD960007.role preserve=no  public: static CPOStateLifeTimeCounterSum {1..1 -> 1..1RFHN}
      static CPOStateLifeTimeCounterSum *m_pInstance;
      //## end CPOStateLifeTimeCounterSum::pInstance%3F97CD960007.role

    // Additional Private Declarations
      //## begin CPOStateLifeTimeCounterSum%3F93AEB500E1.private preserve=yes
      //## end CPOStateLifeTimeCounterSum%3F93AEB500E1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateLifeTimeCounterSum%3F93AEB500E1.implementation preserve=yes
      //## end CPOStateLifeTimeCounterSum%3F93AEB500E1.implementation

};

//## begin CPOStateLifeTimeCounterSum%3F93AEB500E1.postscript preserve=yes
//## end CPOStateLifeTimeCounterSum%3F93AEB500E1.postscript

//## begin CPOStateLifeTimeCounterSave%3F93AECC0333.preface preserve=yes
//## end CPOStateLifeTimeCounterSave%3F93AECC0333.preface

//## Class: CPOStateLifeTimeCounterSave%3F93AECC0333
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOStateLifeTimeCounterSave : public CPOStateLifeTimeCounter  //## Inherits: <unnamed>%3F9E20B6015E
{
  //## begin CPOStateLifeTimeCounterSave%3F93AECC0333.initialDeclarations preserve=yes
  //## end CPOStateLifeTimeCounterSave%3F93AECC0333.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateLifeTimeCounterSave();

    //## Destructor (generated)
      virtual ~CPOStateLifeTimeCounterSave();


    //## Other Operations (specified)
      //## Operation: Create%1066889003
      static void Create ();

      //## Operation: Delete%1066889004
      static void Delete ();

      //## Operation: GetInstance%1066889005
      static CPOStateLifeTimeCounterSave* GetInstance ();

      //## Operation: Do%1067251217
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
      //## begin CPOStateLifeTimeCounterSave%3F93AECC0333.public preserve=yes
      //## end CPOStateLifeTimeCounterSave%3F93AECC0333.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateLifeTimeCounterSave%3F93AECC0333.protected preserve=yes
      //## end CPOStateLifeTimeCounterSave%3F93AECC0333.protected

  private:
    //## Constructors (generated)
      CPOStateLifeTimeCounterSave(const CPOStateLifeTimeCounterSave &right);

    //## Assignment Operation (generated)
      const CPOStateLifeTimeCounterSave & operator=(const CPOStateLifeTimeCounterSave &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateLifeTimeCounterSave &right) const;

      bool operator!=(const CPOStateLifeTimeCounterSave &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97CD920269
      //## Role: CPOStateLifeTimeCounterSave::pInstance%3F97CD930102
      //## begin CPOStateLifeTimeCounterSave::pInstance%3F97CD930102.role preserve=no  public: static CPOStateLifeTimeCounterSave {1..1 -> 1..1RFHN}
      static CPOStateLifeTimeCounterSave *m_pInstance;
      //## end CPOStateLifeTimeCounterSave::pInstance%3F97CD930102.role

    // Additional Private Declarations
      //## begin CPOStateLifeTimeCounterSave%3F93AECC0333.private preserve=yes
      //## end CPOStateLifeTimeCounterSave%3F93AECC0333.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateLifeTimeCounterSave%3F93AECC0333.implementation preserve=yes
      //## end CPOStateLifeTimeCounterSave%3F93AECC0333.implementation

};

//## begin CPOStateLifeTimeCounterSave%3F93AECC0333.postscript preserve=yes
//## end CPOStateLifeTimeCounterSave%3F93AECC0333.postscript

// Class CPOStateLifeTimeCounter 

// Class CPOStateLifeTimeCounterSum 

// Class CPOStateLifeTimeCounterSave 

//## begin module%3F93A93A0064.epilog preserve=yes
//## end module%3F93A93A0064.epilog


#endif
