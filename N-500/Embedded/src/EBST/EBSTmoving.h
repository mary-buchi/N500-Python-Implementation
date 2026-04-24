//## begin module%3E71A71301F3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E71A71301F3.cm

//## begin module%3E71A71301F3.cp preserve=no
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
//## end module%3E71A71301F3.cp

//## Module: EBSTmoving%3E71A71301F3; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTmoving.h

#ifndef EBSTmoving_h
#define EBSTmoving_h 1

//## begin module%3E71A71301F3.additionalIncludes preserve=no
//## end module%3E71A71301F3.additionalIncludes

//## begin module%3E71A71301F3.includes preserve=yes
//## end module%3E71A71301F3.includes

// EBSTstat
#include "EBSTstat.h"

class CSTLogic;

//## begin module%3E71A71301F3.declarations preserve=no
//## end module%3E71A71301F3.declarations

//## begin module%3E71A71301F3.additionalDeclarations preserve=yes
//## end module%3E71A71301F3.additionalDeclarations


//## begin CSTStateMoving%3E71A09D035B.preface preserve=yes
//## end CSTStateMoving%3E71A09D035B.preface

//## Class: CSTStateMoving%3E71A09D035B
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E76E71E03AD;CSTStateCreated { -> }
//## Uses: <unnamed>%3E76E73F00ED;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3E7866FA02A9;CSTStepperMotorImplementation { -> }
//## Uses: <unnamed>%3E8157F60250;CSTLimitHandler { -> }
//## Uses: <unnamed>%3E82CD8302DE;CSTLimitWorkerThread { -> }
//## Uses: <unnamed>%3F44E25D0226;CSTHardwareConnection { -> }
//## Uses: <unnamed>%3F718D9402A0;ST_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F72B92E02EA;CSTStateConnectionNotConnected { -> }
//## Uses: <unnamed>%3FE04F830300;XSTExceptionSoftLimitHit { -> }
//## Uses: <unnamed>%3FE04F99007F;XSTExceptionHardLimitHit { -> }
//## Uses: <unnamed>%4105079902EA;CSTLogic { -> F}
//## Uses: <unnamed>%415060E203C3;EHIOpenEventRegistration { -> }
//## Uses: <unnamed>%4150616F0191;IHIInterface { -> }

class CSTStateMoving : public CSTState  //## Inherits: <unnamed>%3E75C6E00246
{
  //## begin CSTStateMoving%3E71A09D035B.initialDeclarations preserve=yes
  //## end CSTStateMoving%3E71A09D035B.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateMoving();

    //## Destructor (generated)
      virtual ~CSTStateMoving();


    //## Other Operations (specified)
      //## Operation: StopImmediately%1047904772
      virtual void StopImmediately (ICOStateMachineContext* p_pContext);

      //## Operation: Stop%1047904789
      //	returns true, if the stop sync object maybe signalled
      virtual bool Stop (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

      //## Operation: OnSoftLimit%1051258412
      virtual bool OnSoftLimit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID);

      //## Operation: OnHardLimit%1048669926
      virtual bool OnHardLimit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID);

      //## Operation: OnLimitHit%1048669927
      virtual void OnLimitHit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID);

      //## Operation: CleanupInitialize%1053438558
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

      //## Operation: ConnectionLost%1055922858
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CSTStateMoving%3E71A09D035B.public preserve=yes
      //## end CSTStateMoving%3E71A09D035B.public

  protected:

    //## Other Operations (specified)
      //## Operation: ComputeTiming%1090846594
      virtual void ComputeTiming (CSTLogic* p_pLogic, double p_dDeltaT, DWORD& p_dwTimeout, DWORD& p_dwNominalTime, DWORD& p_dwMissedTime, DWORD& p_dwMissedSteps);

    // Additional Protected Declarations
      //## begin CSTStateMoving%3E71A09D035B.protected preserve=yes
      //## end CSTStateMoving%3E71A09D035B.protected

  private:
    //## Constructors (generated)
      CSTStateMoving(const CSTStateMoving &right);

    //## Assignment Operation (generated)
      const CSTStateMoving & operator=(const CSTStateMoving &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateMoving &right) const;

      bool operator!=(const CSTStateMoving &right) const;

    // Additional Private Declarations
      //## begin CSTStateMoving%3E71A09D035B.private preserve=yes
      //## end CSTStateMoving%3E71A09D035B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateMoving%3E71A09D035B.implementation preserve=yes
      //## end CSTStateMoving%3E71A09D035B.implementation

};

//## begin CSTStateMoving%3E71A09D035B.postscript preserve=yes
//## end CSTStateMoving%3E71A09D035B.postscript

//## begin CSTStateMovingIncreaseSpeed%3E71A1440167.preface preserve=yes
//## end CSTStateMovingIncreaseSpeed%3E71A1440167.preface

//## Class: CSTStateMovingIncreaseSpeed%3E71A1440167
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E81D87C021A;CPIStepperMotorConfig { -> }
//## Uses: <unnamed>%3E8AF88C019A;CSTPositionMachine { -> }

class CSTStateMovingIncreaseSpeed : public CSTStateMoving  //## Inherits: <unnamed>%3E75C77A01E9
{
  //## begin CSTStateMovingIncreaseSpeed%3E71A1440167.initialDeclarations preserve=yes
  //## end CSTStateMovingIncreaseSpeed%3E71A1440167.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateMovingIncreaseSpeed();

    //## Destructor (generated)
      virtual ~CSTStateMovingIncreaseSpeed();


    //## Other Operations (specified)
      //## Operation: Create%1047892492
      static void Create ();

      //## Operation: Delete%1047892493
      static void Delete ();

      //## Operation: GetInstance%1047892494
      static CSTStateMovingIncreaseSpeed* GetInstance ();

      //## Operation: Do%1047971043
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
      //## begin CSTStateMovingIncreaseSpeed%3E71A1440167.public preserve=yes
      //## end CSTStateMovingIncreaseSpeed%3E71A1440167.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateMovingIncreaseSpeed%3E71A1440167.protected preserve=yes
      //## end CSTStateMovingIncreaseSpeed%3E71A1440167.protected

  private:
    //## Constructors (generated)
      CSTStateMovingIncreaseSpeed(const CSTStateMovingIncreaseSpeed &right);

    //## Assignment Operation (generated)
      const CSTStateMovingIncreaseSpeed & operator=(const CSTStateMovingIncreaseSpeed &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateMovingIncreaseSpeed &right) const;

      bool operator!=(const CSTStateMovingIncreaseSpeed &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E75C8B20256
      //## Role: CSTStateMovingIncreaseSpeed::pInstance%3E75C8B300E0
      //## begin CSTStateMovingIncreaseSpeed::pInstance%3E75C8B300E0.role preserve=no  public: static CSTStateMovingIncreaseSpeed {1..1 -> 1..1RFHN}
      static CSTStateMovingIncreaseSpeed *m_pInstance;
      //## end CSTStateMovingIncreaseSpeed::pInstance%3E75C8B300E0.role

    // Additional Private Declarations
      //## begin CSTStateMovingIncreaseSpeed%3E71A1440167.private preserve=yes
      //## end CSTStateMovingIncreaseSpeed%3E71A1440167.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateMovingIncreaseSpeed%3E71A1440167.implementation preserve=yes
      //## end CSTStateMovingIncreaseSpeed%3E71A1440167.implementation

};

//## begin CSTStateMovingIncreaseSpeed%3E71A1440167.postscript preserve=yes
//## end CSTStateMovingIncreaseSpeed%3E71A1440167.postscript

//## begin CSTStateMovingRunSpeed%3E71A1530212.preface preserve=yes
//## end CSTStateMovingRunSpeed%3E71A1530212.preface

//## Class: CSTStateMovingRunSpeed%3E71A1530212
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateMovingRunSpeed : public CSTStateMoving  //## Inherits: <unnamed>%3E75C77F015C
{
  //## begin CSTStateMovingRunSpeed%3E71A1530212.initialDeclarations preserve=yes
  //## end CSTStateMovingRunSpeed%3E71A1530212.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateMovingRunSpeed();

    //## Destructor (generated)
      virtual ~CSTStateMovingRunSpeed();


    //## Other Operations (specified)
      //## Operation: Create%1047892495
      static void Create ();

      //## Operation: Delete%1047892496
      static void Delete ();

      //## Operation: GetInstance%1047892497
      static CSTStateMovingRunSpeed* GetInstance ();

      //## Operation: Do%1047971044
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: OnHardLimit%1065684039
      virtual bool OnHardLimit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID);

    // Additional Public Declarations
      //## begin CSTStateMovingRunSpeed%3E71A1530212.public preserve=yes
      //## end CSTStateMovingRunSpeed%3E71A1530212.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateMovingRunSpeed%3E71A1530212.protected preserve=yes
      //## end CSTStateMovingRunSpeed%3E71A1530212.protected

  private:
    //## Constructors (generated)
      CSTStateMovingRunSpeed(const CSTStateMovingRunSpeed &right);

    //## Assignment Operation (generated)
      const CSTStateMovingRunSpeed & operator=(const CSTStateMovingRunSpeed &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateMovingRunSpeed &right) const;

      bool operator!=(const CSTStateMovingRunSpeed &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E75C8B502C3
      //## Role: CSTStateMovingRunSpeed::pInstance%3E75C8B601AB
      //## begin CSTStateMovingRunSpeed::pInstance%3E75C8B601AB.role preserve=no  public: static CSTStateMovingRunSpeed {1..1 -> 1..1RFHN}
      static CSTStateMovingRunSpeed *m_pInstance;
      //## end CSTStateMovingRunSpeed::pInstance%3E75C8B601AB.role

    // Additional Private Declarations
      //## begin CSTStateMovingRunSpeed%3E71A1530212.private preserve=yes
      //## end CSTStateMovingRunSpeed%3E71A1530212.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateMovingRunSpeed%3E71A1530212.implementation preserve=yes
      //## end CSTStateMovingRunSpeed%3E71A1530212.implementation

};

//## begin CSTStateMovingRunSpeed%3E71A1530212.postscript preserve=yes
//## end CSTStateMovingRunSpeed%3E71A1530212.postscript

//## begin CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.preface preserve=yes
//## end CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.preface

//## Class: CSTStateMovingDecreaseToSearchSpeed%3E71A157029F
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateMovingDecreaseToSearchSpeed : public CSTStateMoving  //## Inherits: <unnamed>%3E75C79201E9
{
  //## begin CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.initialDeclarations preserve=yes
  //## end CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateMovingDecreaseToSearchSpeed();

    //## Destructor (generated)
      virtual ~CSTStateMovingDecreaseToSearchSpeed();


    //## Other Operations (specified)
      //## Operation: Create%1047892498
      static void Create ();

      //## Operation: Delete%1047892499
      static void Delete ();

      //## Operation: GetInstance%1047892500
      static CSTStateMovingDecreaseToSearchSpeed* GetInstance ();

      //## Operation: Do%1047971045
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
      //## begin CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.public preserve=yes
      //## end CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.protected preserve=yes
      //## end CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.protected

  private:
    //## Constructors (generated)
      CSTStateMovingDecreaseToSearchSpeed(const CSTStateMovingDecreaseToSearchSpeed &right);

    //## Assignment Operation (generated)
      const CSTStateMovingDecreaseToSearchSpeed & operator=(const CSTStateMovingDecreaseToSearchSpeed &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateMovingDecreaseToSearchSpeed &right) const;

      bool operator!=(const CSTStateMovingDecreaseToSearchSpeed &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E75C8C6010E
      //## Role: CSTStateMovingDecreaseToSearchSpeed::pInstance%3E75C8C70073
      //## begin CSTStateMovingDecreaseToSearchSpeed::pInstance%3E75C8C70073.role preserve=no  public: static CSTStateMovingDecreaseToSearchSpeed {1..1 -> 1..1RFHN}
      static CSTStateMovingDecreaseToSearchSpeed *m_pInstance;
      //## end CSTStateMovingDecreaseToSearchSpeed::pInstance%3E75C8C70073.role

    // Additional Private Declarations
      //## begin CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.private preserve=yes
      //## end CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.implementation preserve=yes
      //## end CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.implementation

};

//## begin CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.postscript preserve=yes
//## end CSTStateMovingDecreaseToSearchSpeed%3E71A157029F.postscript

//## begin CSTStateMovingSearchSpeed%3E71A15C0128.preface preserve=yes
//## end CSTStateMovingSearchSpeed%3E71A15C0128.preface

//## Class: CSTStateMovingSearchSpeed%3E71A15C0128
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateMovingSearchSpeed : public CSTStateMoving  //## Inherits: <unnamed>%3E75C796012D
{
  //## begin CSTStateMovingSearchSpeed%3E71A15C0128.initialDeclarations preserve=yes
  //## end CSTStateMovingSearchSpeed%3E71A15C0128.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateMovingSearchSpeed();

    //## Destructor (generated)
      virtual ~CSTStateMovingSearchSpeed();


    //## Other Operations (specified)
      //## Operation: Create%1047892501
      static void Create ();

      //## Operation: Delete%1047892502
      static void Delete ();

      //## Operation: GetInstance%1047892503
      static CSTStateMovingSearchSpeed* GetInstance ();

      //## Operation: Do%1047971046
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: OnSoftLimit%1065684035
      virtual bool OnSoftLimit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID);

    // Additional Public Declarations
      //## begin CSTStateMovingSearchSpeed%3E71A15C0128.public preserve=yes
      //## end CSTStateMovingSearchSpeed%3E71A15C0128.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateMovingSearchSpeed%3E71A15C0128.protected preserve=yes
      //## end CSTStateMovingSearchSpeed%3E71A15C0128.protected

  private:
    //## Constructors (generated)
      CSTStateMovingSearchSpeed(const CSTStateMovingSearchSpeed &right);

    //## Assignment Operation (generated)
      const CSTStateMovingSearchSpeed & operator=(const CSTStateMovingSearchSpeed &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateMovingSearchSpeed &right) const;

      bool operator!=(const CSTStateMovingSearchSpeed &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E75C8C30275
      //## Role: CSTStateMovingSearchSpeed::pInstance%3E75C8C4015D
      //## begin CSTStateMovingSearchSpeed::pInstance%3E75C8C4015D.role preserve=no  public: static CSTStateMovingSearchSpeed {1..1 -> 1..1RFHN}
      static CSTStateMovingSearchSpeed *m_pInstance;
      //## end CSTStateMovingSearchSpeed::pInstance%3E75C8C4015D.role

    // Additional Private Declarations
      //## begin CSTStateMovingSearchSpeed%3E71A15C0128.private preserve=yes
      //## end CSTStateMovingSearchSpeed%3E71A15C0128.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateMovingSearchSpeed%3E71A15C0128.implementation preserve=yes
      //## end CSTStateMovingSearchSpeed%3E71A15C0128.implementation

};

//## begin CSTStateMovingSearchSpeed%3E71A15C0128.postscript preserve=yes
//## end CSTStateMovingSearchSpeed%3E71A15C0128.postscript

//## begin CSTStateMovingDecreaseToStop%3E71A1A801A5.preface preserve=yes
//## end CSTStateMovingDecreaseToStop%3E71A1A801A5.preface

//## Class: CSTStateMovingDecreaseToStop%3E71A1A801A5
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateMovingDecreaseToStop : public CSTStateMoving  //## Inherits: <unnamed>%3E75C7C70360
{
  //## begin CSTStateMovingDecreaseToStop%3E71A1A801A5.initialDeclarations preserve=yes
  //## end CSTStateMovingDecreaseToStop%3E71A1A801A5.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateMovingDecreaseToStop();

    //## Destructor (generated)
      virtual ~CSTStateMovingDecreaseToStop();


    //## Other Operations (specified)
      //## Operation: Create%1047892504
      static void Create ();

      //## Operation: Delete%1047892505
      static void Delete ();

      //## Operation: GetInstance%1047892506
      static CSTStateMovingDecreaseToStop* GetInstance ();

      //## Operation: Do%1047971047
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
      //## begin CSTStateMovingDecreaseToStop%3E71A1A801A5.public preserve=yes
      //## end CSTStateMovingDecreaseToStop%3E71A1A801A5.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateMovingDecreaseToStop%3E71A1A801A5.protected preserve=yes
      //## end CSTStateMovingDecreaseToStop%3E71A1A801A5.protected

  private:
    //## Constructors (generated)
      CSTStateMovingDecreaseToStop(const CSTStateMovingDecreaseToStop &right);

    //## Assignment Operation (generated)
      const CSTStateMovingDecreaseToStop & operator=(const CSTStateMovingDecreaseToStop &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateMovingDecreaseToStop &right) const;

      bool operator!=(const CSTStateMovingDecreaseToStop &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E75C8C100A0
      //## Role: CSTStateMovingDecreaseToStop::pInstance%3E75C8C1039F
      //## begin CSTStateMovingDecreaseToStop::pInstance%3E75C8C1039F.role preserve=no  public: static CSTStateMovingDecreaseToStop {1..1 -> 1..1RFHN}
      static CSTStateMovingDecreaseToStop *m_pInstance;
      //## end CSTStateMovingDecreaseToStop::pInstance%3E75C8C1039F.role

    // Additional Private Declarations
      //## begin CSTStateMovingDecreaseToStop%3E71A1A801A5.private preserve=yes
      //## end CSTStateMovingDecreaseToStop%3E71A1A801A5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateMovingDecreaseToStop%3E71A1A801A5.implementation preserve=yes
      //## end CSTStateMovingDecreaseToStop%3E71A1A801A5.implementation

};

//## begin CSTStateMovingDecreaseToStop%3E71A1A801A5.postscript preserve=yes
//## end CSTStateMovingDecreaseToStop%3E71A1A801A5.postscript

//## begin CSTStateMovingEndPosition%3E71A1AB002E.preface preserve=yes
//## end CSTStateMovingEndPosition%3E71A1AB002E.preface

//## Class: CSTStateMovingEndPosition%3E71A1AB002E
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateMovingEndPosition : public CSTStateMoving  //## Inherits: <unnamed>%3E75C7CF00A0
{
  //## begin CSTStateMovingEndPosition%3E71A1AB002E.initialDeclarations preserve=yes
  //## end CSTStateMovingEndPosition%3E71A1AB002E.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateMovingEndPosition();

    //## Destructor (generated)
      virtual ~CSTStateMovingEndPosition();


    //## Other Operations (specified)
      //## Operation: Create%1047892507
      static void Create ();

      //## Operation: Delete%1047892508
      static void Delete ();

      //## Operation: GetInstance%1047892509
      static CSTStateMovingEndPosition* GetInstance ();

      //## Operation: Do%1047971048
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
      //## begin CSTStateMovingEndPosition%3E71A1AB002E.public preserve=yes
      //## end CSTStateMovingEndPosition%3E71A1AB002E.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateMovingEndPosition%3E71A1AB002E.protected preserve=yes
      //## end CSTStateMovingEndPosition%3E71A1AB002E.protected

  private:
    //## Constructors (generated)
      CSTStateMovingEndPosition(const CSTStateMovingEndPosition &right);

    //## Assignment Operation (generated)
      const CSTStateMovingEndPosition & operator=(const CSTStateMovingEndPosition &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateMovingEndPosition &right) const;

      bool operator!=(const CSTStateMovingEndPosition &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E75C8BE0285
      //## Role: CSTStateMovingEndPosition::pInstance%3E75C8BF01CA
      //## begin CSTStateMovingEndPosition::pInstance%3E75C8BF01CA.role preserve=no  public: static CSTStateMovingEndPosition {1..1 -> 1..1RFHN}
      static CSTStateMovingEndPosition *m_pInstance;
      //## end CSTStateMovingEndPosition::pInstance%3E75C8BF01CA.role

    // Additional Private Declarations
      //## begin CSTStateMovingEndPosition%3E71A1AB002E.private preserve=yes
      //## end CSTStateMovingEndPosition%3E71A1AB002E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateMovingEndPosition%3E71A1AB002E.implementation preserve=yes
      //## end CSTStateMovingEndPosition%3E71A1AB002E.implementation

};

//## begin CSTStateMovingEndPosition%3E71A1AB002E.postscript preserve=yes
//## end CSTStateMovingEndPosition%3E71A1AB002E.postscript

//## begin CSTStateMovingPreparation%3E967F6E0119.preface preserve=yes
//## end CSTStateMovingPreparation%3E967F6E0119.preface

//## Class: CSTStateMovingPreparation%3E967F6E0119
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateMovingPreparation : public CSTStateMoving  //## Inherits: <unnamed>%3E967F9003D8
{
  //## begin CSTStateMovingPreparation%3E967F6E0119.initialDeclarations preserve=yes
  //## end CSTStateMovingPreparation%3E967F6E0119.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateMovingPreparation();

    //## Destructor (generated)
      virtual ~CSTStateMovingPreparation();


    //## Other Operations (specified)
      //## Operation: Create%1050050605
      static void Create ();

      //## Operation: Delete%1050050606
      static void Delete ();

      //## Operation: GetInstance%1050050607
      static CSTStateMovingPreparation* GetInstance ();

      //## Operation: Do%1050050608
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
      //## begin CSTStateMovingPreparation%3E967F6E0119.public preserve=yes
      //## end CSTStateMovingPreparation%3E967F6E0119.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateMovingPreparation%3E967F6E0119.protected preserve=yes
      //## end CSTStateMovingPreparation%3E967F6E0119.protected

  private:
    //## Constructors (generated)
      CSTStateMovingPreparation(const CSTStateMovingPreparation &right);

    //## Assignment Operation (generated)
      const CSTStateMovingPreparation & operator=(const CSTStateMovingPreparation &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateMovingPreparation &right) const;

      bool operator!=(const CSTStateMovingPreparation &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E967F97038A
      //## Role: CSTStateMovingPreparation::pInstance%3E967F990197
      //## begin CSTStateMovingPreparation::pInstance%3E967F990197.role preserve=no  public: static CSTStateMovingPreparation {1..1 -> 1..1RFHN}
      static CSTStateMovingPreparation *m_pInstance;
      //## end CSTStateMovingPreparation::pInstance%3E967F990197.role

    // Additional Private Declarations
      //## begin CSTStateMovingPreparation%3E967F6E0119.private preserve=yes
      //## end CSTStateMovingPreparation%3E967F6E0119.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateMovingPreparation%3E967F6E0119.implementation preserve=yes
      //## end CSTStateMovingPreparation%3E967F6E0119.implementation

};

//## begin CSTStateMovingPreparation%3E967F6E0119.postscript preserve=yes
//## end CSTStateMovingPreparation%3E967F6E0119.postscript

//## begin CSTStateMovingWithStartupSpeed%3ECDD21800E9.preface preserve=yes
//## end CSTStateMovingWithStartupSpeed%3ECDD21800E9.preface

//## Class: CSTStateMovingWithStartupSpeed%3ECDD21800E9
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateMovingWithStartupSpeed : public CSTStateMoving  //## Inherits: <unnamed>%3ECDD28402BD
{
  //## begin CSTStateMovingWithStartupSpeed%3ECDD21800E9.initialDeclarations preserve=yes
  //## end CSTStateMovingWithStartupSpeed%3ECDD21800E9.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateMovingWithStartupSpeed();

    //## Destructor (generated)
      virtual ~CSTStateMovingWithStartupSpeed();


    //## Other Operations (specified)
      //## Operation: Create%1053672324
      static void Create ();

      //## Operation: Delete%1053672325
      static void Delete ();

      //## Operation: GetInstance%1053672326
      static CSTStateMovingWithStartupSpeed* GetInstance ();

      //## Operation: Do%1053672327
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
      //## begin CSTStateMovingWithStartupSpeed%3ECDD21800E9.public preserve=yes
      //## end CSTStateMovingWithStartupSpeed%3ECDD21800E9.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateMovingWithStartupSpeed%3ECDD21800E9.protected preserve=yes
      //## end CSTStateMovingWithStartupSpeed%3ECDD21800E9.protected

  private:
    //## Constructors (generated)
      CSTStateMovingWithStartupSpeed(const CSTStateMovingWithStartupSpeed &right);

    //## Assignment Operation (generated)
      const CSTStateMovingWithStartupSpeed & operator=(const CSTStateMovingWithStartupSpeed &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateMovingWithStartupSpeed &right) const;

      bool operator!=(const CSTStateMovingWithStartupSpeed &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3ECDD2F100E9
      //## Role: CSTStateMovingWithStartupSpeed::pInstance%3ECDD2F201B5
      //## begin CSTStateMovingWithStartupSpeed::pInstance%3ECDD2F201B5.role preserve=no  public: static CSTStateMovingWithStartupSpeed {1..1 -> 1..1RFHN}
      static CSTStateMovingWithStartupSpeed *m_pInstance;
      //## end CSTStateMovingWithStartupSpeed::pInstance%3ECDD2F201B5.role

    // Additional Private Declarations
      //## begin CSTStateMovingWithStartupSpeed%3ECDD21800E9.private preserve=yes
      //## end CSTStateMovingWithStartupSpeed%3ECDD21800E9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateMovingWithStartupSpeed%3ECDD21800E9.implementation preserve=yes
      //## end CSTStateMovingWithStartupSpeed%3ECDD21800E9.implementation

};

//## begin CSTStateMovingWithStartupSpeed%3ECDD21800E9.postscript preserve=yes
//## end CSTStateMovingWithStartupSpeed%3ECDD21800E9.postscript

// Class CSTStateMoving 

// Class CSTStateMovingIncreaseSpeed 

// Class CSTStateMovingRunSpeed 

// Class CSTStateMovingDecreaseToSearchSpeed 

// Class CSTStateMovingSearchSpeed 

// Class CSTStateMovingDecreaseToStop 

// Class CSTStateMovingEndPosition 

// Class CSTStateMovingPreparation 

// Class CSTStateMovingWithStartupSpeed 

//## begin module%3E71A71301F3.epilog preserve=yes
//## end module%3E71A71301F3.epilog


#endif
