//## begin module%434137B002D8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%434137B002D8.cm

//## begin module%434137B002D8.cp preserve=no
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
//## end module%434137B002D8.cp

//## Module: EBSThome%434137B002D8; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSThome.h

#ifndef EBSThome_h
#define EBSThome_h 1

//## begin module%434137B002D8.additionalIncludes preserve=no
//## end module%434137B002D8.additionalIncludes

//## begin module%434137B002D8.includes preserve=yes
//## end module%434137B002D8.includes

// EBSTstat
#include "EBSTstat.h"

class CSTLimitWorkerThread;

//## begin module%434137B002D8.declarations preserve=no
//## end module%434137B002D8.declarations

//## begin module%434137B002D8.additionalDeclarations preserve=yes
//## end module%434137B002D8.additionalDeclarations


//## begin CSTStateHome%3E71A0AC0203.preface preserve=yes
//## end CSTStateHome%3E71A0AC0203.preface

//## Class: CSTStateHome%3E71A0AC0203
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E76E78F035E;CSTStateCreated { -> }
//## Uses: <unnamed>%3E76E78F035F;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3E7867F301FD;CSTState { -> }
//## Uses: <unnamed>%3E78683301EE;CSTStepperMotorImplementation { -> }
//## Uses: <unnamed>%3E787D5B027A;CPIStepperMotorConfig { -> }
//## Uses: <unnamed>%3E787D5F0161;CPIStepperMotorProfile { -> }
//## Uses: <unnamed>%3E8157EB00D9;CSTLimitHandler { -> }
//## Uses: <unnamed>%3F6581D50048;CSTHardwareConnection { -> }
//## Uses: <unnamed>%3F72B962021F;CSTStateConnectionNotConnected { -> }
//## Uses: <unnamed>%3F850FEC0399;CSTPositionMachine { -> }
//## Uses: <unnamed>%3F8A9F1101FF;XSTExcepitonHomingSensorNotFound { -> }
//## Uses: <unnamed>%3F8BF54F02EB;ESTValidType { -> }
//## Uses: <unnamed>%3F8BFE0603D5;IHIInterface { -> }
//## Uses: <unnamed>%3FBA3ECE0023;CSTActionMove { -> }

class CSTStateHome : public CSTState  //## Inherits: <unnamed>%3E75C72301AA
{
  //## begin CSTStateHome%3E71A0AC0203.initialDeclarations preserve=yes
  //## end CSTStateHome%3E71A0AC0203.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateHome();

    //## Destructor (generated)
      virtual ~CSTStateHome();


    //## Other Operations (specified)
      //## Operation: StopImmediately%1047904774
      virtual void StopImmediately (ICOStateMachineContext* p_pContext);

      //## Operation: CleanupInitialize%1053438562
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

      //## Operation: ConnectionLost%1055922859
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: OnLimitHit%1065684032
      virtual void OnLimitHit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID);

      //## Operation: OnSoftLimit%1065684033
      virtual bool OnSoftLimit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID);

      //## Operation: OnHardLimit%1065684034
      virtual bool OnHardLimit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID);

    // Additional Public Declarations
      //## begin CSTStateHome%3E71A0AC0203.public preserve=yes
      //## end CSTStateHome%3E71A0AC0203.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateHome%3E71A0AC0203.protected preserve=yes
      //## end CSTStateHome%3E71A0AC0203.protected

  private:
    //## Constructors (generated)
      CSTStateHome(const CSTStateHome &right);

    //## Assignment Operation (generated)
      const CSTStateHome & operator=(const CSTStateHome &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateHome &right) const;

      bool operator!=(const CSTStateHome &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E81773B0385
      //## Role: CSTStateHome::pLimitWorkerThread%3E81773C02E9
      //## begin CSTStateHome::pLimitWorkerThread%3E81773C02E9.role preserve=no  public: CSTLimitWorkerThread {1..1 -> 1..1RFHN}
      CSTLimitWorkerThread *m_pLimitWorkerThread;
      //## end CSTStateHome::pLimitWorkerThread%3E81773C02E9.role

    // Additional Private Declarations
      //## begin CSTStateHome%3E71A0AC0203.private preserve=yes
      //## end CSTStateHome%3E71A0AC0203.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateHome%3E71A0AC0203.implementation preserve=yes
      //## end CSTStateHome%3E71A0AC0203.implementation

};

//## begin CSTStateHome%3E71A0AC0203.postscript preserve=yes
//## end CSTStateHome%3E71A0AC0203.postscript

//## begin CSTStateHomePrepare%4341371702C4.preface preserve=yes
//## end CSTStateHomePrepare%4341371702C4.preface

//## Class: CSTStateHomePrepare%4341371702C4
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%434139F900A8;CSTLimitHandler { -> }
//## Uses: <unnamed>%434139FC017F;CSTLimitWorkerThread { -> }
//## Uses: <unnamed>%434139FF01C9;CSTStepperMotorImplementation { -> }
//## Uses: <unnamed>%43413A020141;CSTState { -> }
//## Uses: <unnamed>%43413A180247;CSTPositionMachine { -> }
//## Uses: <unnamed>%43413A420338;CSTLogic { -> }
//## Uses: <unnamed>%43413D6303D0;CSTActionMove { -> }
//## Uses: <unnamed>%43413D7C0015;ST_IDENTIFIERS { -> }
//## Uses: <unnamed>%43413D8B01A7;CPIStepperMotorProfile { -> }
//## Uses: <unnamed>%43413FCC0193;CSTHardwareConnection { -> }
//## Uses: <unnamed>%43413FEA01F0;XSTExcepitonHomingSensorNotFound { -> }
//## Uses: <unnamed>%4341454A00AE;CSTStateCreated { -> }
//## Uses: <unnamed>%434299C00150;IHIInterface { -> }

class CSTStateHomePrepare : public CSTStateHome  //## Inherits: <unnamed>%434137CE00DC
{
  //## begin CSTStateHomePrepare%4341371702C4.initialDeclarations preserve=yes
  //## end CSTStateHomePrepare%4341371702C4.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateHomePrepare();

    //## Destructor (generated)
      virtual ~CSTStateHomePrepare();


    //## Other Operations (specified)
      //## Operation: Create%1128347816
      static void Create ();

      //## Operation: Delete%1128347817
      static void Delete ();

      //## Operation: GetInstance%1128347818
      static CSTStateHomePrepare* GetInstance ();

      //## Operation: Do%1128347819
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
      //## begin CSTStateHomePrepare%4341371702C4.public preserve=yes
      //## end CSTStateHomePrepare%4341371702C4.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateHomePrepare%4341371702C4.protected preserve=yes
      //## end CSTStateHomePrepare%4341371702C4.protected

  private:
    //## Constructors (generated)
      CSTStateHomePrepare(const CSTStateHomePrepare &right);

    //## Assignment Operation (generated)
      const CSTStateHomePrepare & operator=(const CSTStateHomePrepare &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateHomePrepare &right) const;

      bool operator!=(const CSTStateHomePrepare &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%434138330037
      //## Role: CSTStateHomePrepare::pInstance%4341383401B6
      //## begin CSTStateHomePrepare::pInstance%4341383401B6.role preserve=no  public: static CSTStateHomePrepare {1..1 -> 1..1RFHN}
      static CSTStateHomePrepare *m_pInstance;
      //## end CSTStateHomePrepare::pInstance%4341383401B6.role

    // Additional Private Declarations
      //## begin CSTStateHomePrepare%4341371702C4.private preserve=yes
      //## end CSTStateHomePrepare%4341371702C4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateHomePrepare%4341371702C4.implementation preserve=yes
      //## end CSTStateHomePrepare%4341371702C4.implementation

};

//## begin CSTStateHomePrepare%4341371702C4.postscript preserve=yes
//## end CSTStateHomePrepare%4341371702C4.postscript

//## begin CSTStateHomeFastFindingLimit%434137230271.preface preserve=yes
//## end CSTStateHomeFastFindingLimit%434137230271.preface

//## Class: CSTStateHomeFastFindingLimit%434137230271
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateHomeFastFindingLimit : public CSTStateHome  //## Inherits: <unnamed>%434137D0036A
{
  //## begin CSTStateHomeFastFindingLimit%434137230271.initialDeclarations preserve=yes
  //## end CSTStateHomeFastFindingLimit%434137230271.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateHomeFastFindingLimit();

    //## Destructor (generated)
      virtual ~CSTStateHomeFastFindingLimit();


    //## Other Operations (specified)
      //## Operation: Create%1128347820
      static void Create ();

      //## Operation: Delete%1128347821
      static void Delete ();

      //## Operation: GetInstance%1128347822
      static CSTStateHomeFastFindingLimit* GetInstance ();

      //## Operation: Do%1128347823
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
      //## begin CSTStateHomeFastFindingLimit%434137230271.public preserve=yes
      //## end CSTStateHomeFastFindingLimit%434137230271.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateHomeFastFindingLimit%434137230271.protected preserve=yes
      //## end CSTStateHomeFastFindingLimit%434137230271.protected

  private:
    //## Constructors (generated)
      CSTStateHomeFastFindingLimit(const CSTStateHomeFastFindingLimit &right);

    //## Assignment Operation (generated)
      const CSTStateHomeFastFindingLimit & operator=(const CSTStateHomeFastFindingLimit &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateHomeFastFindingLimit &right) const;

      bool operator!=(const CSTStateHomeFastFindingLimit &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%4341386C0057
      //## Role: CSTStateHomeFastFindingLimit::pInstance%4341386D0243
      //## begin CSTStateHomeFastFindingLimit::pInstance%4341386D0243.role preserve=no  public: static CSTStateHomeFastFindingLimit {1..1 -> 1..1RFHN}
      static CSTStateHomeFastFindingLimit *m_pInstance;
      //## end CSTStateHomeFastFindingLimit::pInstance%4341386D0243.role

    // Additional Private Declarations
      //## begin CSTStateHomeFastFindingLimit%434137230271.private preserve=yes
      //## end CSTStateHomeFastFindingLimit%434137230271.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateHomeFastFindingLimit%434137230271.implementation preserve=yes
      //## end CSTStateHomeFastFindingLimit%434137230271.implementation

};

//## begin CSTStateHomeFastFindingLimit%434137230271.postscript preserve=yes
//## end CSTStateHomeFastFindingLimit%434137230271.postscript

//## begin CSTStateHomeMovingBackToLatchedLimit%4341374B014C.preface preserve=yes
//## end CSTStateHomeMovingBackToLatchedLimit%4341374B014C.preface

//## Class: CSTStateHomeMovingBackToLatchedLimit%4341374B014C
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateHomeMovingBackToLatchedLimit : public CSTStateHome  //## Inherits: <unnamed>%434137D40009
{
  //## begin CSTStateHomeMovingBackToLatchedLimit%4341374B014C.initialDeclarations preserve=yes
  //## end CSTStateHomeMovingBackToLatchedLimit%4341374B014C.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateHomeMovingBackToLatchedLimit();

    //## Destructor (generated)
      virtual ~CSTStateHomeMovingBackToLatchedLimit();


    //## Other Operations (specified)
      //## Operation: Create%1128347824
      static void Create ();

      //## Operation: Delete%1128347825
      static void Delete ();

      //## Operation: GetInstance%1128347826
      static CSTStateHomeMovingBackToLatchedLimit* GetInstance ();

      //## Operation: Do%1128347827
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
      //## begin CSTStateHomeMovingBackToLatchedLimit%4341374B014C.public preserve=yes
      //## end CSTStateHomeMovingBackToLatchedLimit%4341374B014C.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateHomeMovingBackToLatchedLimit%4341374B014C.protected preserve=yes
      //## end CSTStateHomeMovingBackToLatchedLimit%4341374B014C.protected

  private:
    //## Constructors (generated)
      CSTStateHomeMovingBackToLatchedLimit(const CSTStateHomeMovingBackToLatchedLimit &right);

    //## Assignment Operation (generated)
      const CSTStateHomeMovingBackToLatchedLimit & operator=(const CSTStateHomeMovingBackToLatchedLimit &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateHomeMovingBackToLatchedLimit &right) const;

      bool operator!=(const CSTStateHomeMovingBackToLatchedLimit &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%4341387003A6
      //## Role: CSTStateHomeMovingBackToLatchedLimit::pInstance%4341387201D2
      //## begin CSTStateHomeMovingBackToLatchedLimit::pInstance%4341387201D2.role preserve=no  public: static CSTStateHomeMovingBackToLatchedLimit {1..1 -> 1..1RFHN}
      static CSTStateHomeMovingBackToLatchedLimit *m_pInstance;
      //## end CSTStateHomeMovingBackToLatchedLimit::pInstance%4341387201D2.role

    // Additional Private Declarations
      //## begin CSTStateHomeMovingBackToLatchedLimit%4341374B014C.private preserve=yes
      //## end CSTStateHomeMovingBackToLatchedLimit%4341374B014C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateHomeMovingBackToLatchedLimit%4341374B014C.implementation preserve=yes
      //## end CSTStateHomeMovingBackToLatchedLimit%4341374B014C.implementation

};

//## begin CSTStateHomeMovingBackToLatchedLimit%4341374B014C.postscript preserve=yes
//## end CSTStateHomeMovingBackToLatchedLimit%4341374B014C.postscript

//## begin CSTStateHomeDeceleratingToStop%434142360083.preface preserve=yes
//## end CSTStateHomeDeceleratingToStop%434142360083.preface

//## Class: CSTStateHomeDeceleratingToStop%434142360083
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateHomeDeceleratingToStop : public CSTStateHome  //## Inherits: <unnamed>%4341425C0100
{
  //## begin CSTStateHomeDeceleratingToStop%434142360083.initialDeclarations preserve=yes
  //## end CSTStateHomeDeceleratingToStop%434142360083.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateHomeDeceleratingToStop();

    //## Destructor (generated)
      virtual ~CSTStateHomeDeceleratingToStop();


    //## Other Operations (specified)
      //## Operation: Create%1128347828
      static void Create ();

      //## Operation: Delete%1128347829
      static void Delete ();

      //## Operation: GetInstance%1128347830
      static CSTStateHomeDeceleratingToStop* GetInstance ();

      //## Operation: Do%1128347831
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
      //## begin CSTStateHomeDeceleratingToStop%434142360083.public preserve=yes
      //## end CSTStateHomeDeceleratingToStop%434142360083.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateHomeDeceleratingToStop%434142360083.protected preserve=yes
      //## end CSTStateHomeDeceleratingToStop%434142360083.protected

  private:
    //## Constructors (generated)
      CSTStateHomeDeceleratingToStop(const CSTStateHomeDeceleratingToStop &right);

    //## Assignment Operation (generated)
      const CSTStateHomeDeceleratingToStop & operator=(const CSTStateHomeDeceleratingToStop &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateHomeDeceleratingToStop &right) const;

      bool operator!=(const CSTStateHomeDeceleratingToStop &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%434142790179
      //## Role: CSTStateHomeDeceleratingToStop::pInstance%4341427A0262
      //## begin CSTStateHomeDeceleratingToStop::pInstance%4341427A0262.role preserve=no  public: static CSTStateHomeDeceleratingToStop { -> 1..1RFHN}
      static CSTStateHomeDeceleratingToStop *m_pInstance;
      //## end CSTStateHomeDeceleratingToStop::pInstance%4341427A0262.role

    // Additional Private Declarations
      //## begin CSTStateHomeDeceleratingToStop%434142360083.private preserve=yes
      //## end CSTStateHomeDeceleratingToStop%434142360083.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateHomeDeceleratingToStop%434142360083.implementation preserve=yes
      //## end CSTStateHomeDeceleratingToStop%434142360083.implementation

};

//## begin CSTStateHomeDeceleratingToStop%434142360083.postscript preserve=yes
//## end CSTStateHomeDeceleratingToStop%434142360083.postscript

//## begin CSTStateHomeAtLatchedLimit%43426A9902FD.preface preserve=yes
//## end CSTStateHomeAtLatchedLimit%43426A9902FD.preface

//## Class: CSTStateHomeAtLatchedLimit%43426A9902FD
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateHomeAtLatchedLimit : public CSTStateHome  //## Inherits: <unnamed>%43426AF702C6
{
  //## begin CSTStateHomeAtLatchedLimit%43426A9902FD.initialDeclarations preserve=yes
  //## end CSTStateHomeAtLatchedLimit%43426A9902FD.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateHomeAtLatchedLimit();

    //## Destructor (generated)
      virtual ~CSTStateHomeAtLatchedLimit();


    //## Other Operations (specified)
      //## Operation: Create%1128355569
      static void Create ();

      //## Operation: Delete%1128355570
      static void Delete ();

      //## Operation: GetInstance%1128355571
      static CSTStateHomeAtLatchedLimit* GetInstance ();

      //## Operation: Do%1128355572
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
      //## begin CSTStateHomeAtLatchedLimit%43426A9902FD.public preserve=yes
      //## end CSTStateHomeAtLatchedLimit%43426A9902FD.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateHomeAtLatchedLimit%43426A9902FD.protected preserve=yes
      //## end CSTStateHomeAtLatchedLimit%43426A9902FD.protected

  private:
    //## Constructors (generated)
      CSTStateHomeAtLatchedLimit(const CSTStateHomeAtLatchedLimit &right);

    //## Assignment Operation (generated)
      const CSTStateHomeAtLatchedLimit & operator=(const CSTStateHomeAtLatchedLimit &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateHomeAtLatchedLimit &right) const;

      bool operator!=(const CSTStateHomeAtLatchedLimit &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%43426B0E019D
      //## Role: CSTStateHomeAtLatchedLimit::pInstance%43426B0F0290
      //## begin CSTStateHomeAtLatchedLimit::pInstance%43426B0F0290.role preserve=no  public: static CSTStateHomeAtLatchedLimit {1..1 -> 1..1RFHN}
      static CSTStateHomeAtLatchedLimit *m_pInstance;
      //## end CSTStateHomeAtLatchedLimit::pInstance%43426B0F0290.role

    // Additional Private Declarations
      //## begin CSTStateHomeAtLatchedLimit%43426A9902FD.private preserve=yes
      //## end CSTStateHomeAtLatchedLimit%43426A9902FD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateHomeAtLatchedLimit%43426A9902FD.implementation preserve=yes
      //## end CSTStateHomeAtLatchedLimit%43426A9902FD.implementation

};

//## begin CSTStateHomeAtLatchedLimit%43426A9902FD.postscript preserve=yes
//## end CSTStateHomeAtLatchedLimit%43426A9902FD.postscript

//## begin CSTStateHomeLeavingLimit%4342732102D5.preface preserve=yes
//## end CSTStateHomeLeavingLimit%4342732102D5.preface

//## Class: CSTStateHomeLeavingLimit%4342732102D5
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateHomeLeavingLimit : public CSTStateHome  //## Inherits: <unnamed>%4342734C01A1
{
  //## begin CSTStateHomeLeavingLimit%4342732102D5.initialDeclarations preserve=yes
  //## end CSTStateHomeLeavingLimit%4342732102D5.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateHomeLeavingLimit();

    //## Destructor (generated)
      virtual ~CSTStateHomeLeavingLimit();


    //## Other Operations (specified)
      //## Operation: Create%1128355574
      static void Create ();

      //## Operation: Delete%1128355575
      static void Delete ();

      //## Operation: GetInstance%1128355576
      static CSTStateHomeLeavingLimit* GetInstance ();

      //## Operation: Do%1128355577
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
      //## begin CSTStateHomeLeavingLimit%4342732102D5.public preserve=yes
      //## end CSTStateHomeLeavingLimit%4342732102D5.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateHomeLeavingLimit%4342732102D5.protected preserve=yes
      //## end CSTStateHomeLeavingLimit%4342732102D5.protected

  private:
    //## Constructors (generated)
      CSTStateHomeLeavingLimit(const CSTStateHomeLeavingLimit &right);

    //## Assignment Operation (generated)
      const CSTStateHomeLeavingLimit & operator=(const CSTStateHomeLeavingLimit &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateHomeLeavingLimit &right) const;

      bool operator!=(const CSTStateHomeLeavingLimit &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%43427360018C
      //## Role: CSTStateHomeLeavingLimit::pInstance%4342736102F6
      //## begin CSTStateHomeLeavingLimit::pInstance%4342736102F6.role preserve=no  public: static CSTStateHomeLeavingLimit {1..1 -> 1..1RFHN}
      static CSTStateHomeLeavingLimit *m_pInstance;
      //## end CSTStateHomeLeavingLimit::pInstance%4342736102F6.role

    // Additional Private Declarations
      //## begin CSTStateHomeLeavingLimit%4342732102D5.private preserve=yes
      //## end CSTStateHomeLeavingLimit%4342732102D5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateHomeLeavingLimit%4342732102D5.implementation preserve=yes
      //## end CSTStateHomeLeavingLimit%4342732102D5.implementation

};

//## begin CSTStateHomeLeavingLimit%4342732102D5.postscript preserve=yes
//## end CSTStateHomeLeavingLimit%4342732102D5.postscript

//## begin CSTStateHomeSlowlyFindingLimit%434295F20109.preface preserve=yes
//## end CSTStateHomeSlowlyFindingLimit%434295F20109.preface

//## Class: CSTStateHomeSlowlyFindingLimit%434295F20109
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateHomeSlowlyFindingLimit : public CSTStateHome  //## Inherits: <unnamed>%434296380146
{
  //## begin CSTStateHomeSlowlyFindingLimit%434295F20109.initialDeclarations preserve=yes
  //## end CSTStateHomeSlowlyFindingLimit%434295F20109.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateHomeSlowlyFindingLimit();

    //## Destructor (generated)
      virtual ~CSTStateHomeSlowlyFindingLimit();


    //## Other Operations (specified)
      //## Operation: Create%1128355578
      static void Create ();

      //## Operation: Delete%1128355579
      static void Delete ();

      //## Operation: GetInstance%1128355580
      static CSTStateHomeSlowlyFindingLimit* GetInstance ();

      //## Operation: Do%1128355581
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
      //## begin CSTStateHomeSlowlyFindingLimit%434295F20109.public preserve=yes
      //## end CSTStateHomeSlowlyFindingLimit%434295F20109.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateHomeSlowlyFindingLimit%434295F20109.protected preserve=yes
      //## end CSTStateHomeSlowlyFindingLimit%434295F20109.protected

  private:
    //## Constructors (generated)
      CSTStateHomeSlowlyFindingLimit(const CSTStateHomeSlowlyFindingLimit &right);

    //## Assignment Operation (generated)
      const CSTStateHomeSlowlyFindingLimit & operator=(const CSTStateHomeSlowlyFindingLimit &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateHomeSlowlyFindingLimit &right) const;

      bool operator!=(const CSTStateHomeSlowlyFindingLimit &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%4342963C00C0
      //## Role: CSTStateHomeSlowlyFindingLimit::pInstance%4342963D01A8
      //## begin CSTStateHomeSlowlyFindingLimit::pInstance%4342963D01A8.role preserve=no  public: static CSTStateHomeSlowlyFindingLimit {1..1 -> 1..1RFHN}
      static CSTStateHomeSlowlyFindingLimit *m_pInstance;
      //## end CSTStateHomeSlowlyFindingLimit::pInstance%4342963D01A8.role

    // Additional Private Declarations
      //## begin CSTStateHomeSlowlyFindingLimit%434295F20109.private preserve=yes
      //## end CSTStateHomeSlowlyFindingLimit%434295F20109.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateHomeSlowlyFindingLimit%434295F20109.implementation preserve=yes
      //## end CSTStateHomeSlowlyFindingLimit%434295F20109.implementation

};

//## begin CSTStateHomeSlowlyFindingLimit%434295F20109.postscript preserve=yes
//## end CSTStateHomeSlowlyFindingLimit%434295F20109.postscript

//## begin CSTStateHomeMovingOutOfLimit%43437355024E.preface preserve=yes
//## end CSTStateHomeMovingOutOfLimit%43437355024E.preface

//## Class: CSTStateHomeMovingOutOfLimit%43437355024E
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateHomeMovingOutOfLimit : public CSTStateHome  //## Inherits: <unnamed>%434373B70321
{
  //## begin CSTStateHomeMovingOutOfLimit%43437355024E.initialDeclarations preserve=yes
  //## end CSTStateHomeMovingOutOfLimit%43437355024E.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateHomeMovingOutOfLimit();

    //## Destructor (generated)
      virtual ~CSTStateHomeMovingOutOfLimit();


    //## Other Operations (specified)
      //## Operation: Create%1128355582
      static void Create ();

      //## Operation: Delete%1128355583
      static void Delete ();

      //## Operation: GetInstance%1128355584
      static CSTStateHomeMovingOutOfLimit* GetInstance ();

      //## Operation: Do%1128355585
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
      //## begin CSTStateHomeMovingOutOfLimit%43437355024E.public preserve=yes
      //## end CSTStateHomeMovingOutOfLimit%43437355024E.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateHomeMovingOutOfLimit%43437355024E.protected preserve=yes
      //## end CSTStateHomeMovingOutOfLimit%43437355024E.protected

  private:
    //## Constructors (generated)
      CSTStateHomeMovingOutOfLimit(const CSTStateHomeMovingOutOfLimit &right);

    //## Assignment Operation (generated)
      const CSTStateHomeMovingOutOfLimit & operator=(const CSTStateHomeMovingOutOfLimit &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateHomeMovingOutOfLimit &right) const;

      bool operator!=(const CSTStateHomeMovingOutOfLimit &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%43437C5801E7
      //## Role: CSTStateHomeMovingOutOfLimit::pInstance%43437C5903A2
      //## begin CSTStateHomeMovingOutOfLimit::pInstance%43437C5903A2.role preserve=no  public: static CSTStateHomeMovingOutOfLimit {1..1 -> 1..1RFHN}
      static CSTStateHomeMovingOutOfLimit *m_pInstance;
      //## end CSTStateHomeMovingOutOfLimit::pInstance%43437C5903A2.role

    // Additional Private Declarations
      //## begin CSTStateHomeMovingOutOfLimit%43437355024E.private preserve=yes
      //## end CSTStateHomeMovingOutOfLimit%43437355024E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateHomeMovingOutOfLimit%43437355024E.implementation preserve=yes
      //## end CSTStateHomeMovingOutOfLimit%43437355024E.implementation

};

//## begin CSTStateHomeMovingOutOfLimit%43437355024E.postscript preserve=yes
//## end CSTStateHomeMovingOutOfLimit%43437355024E.postscript

//## begin CSTStateHomeAccelerating%4487D2A10346.preface preserve=yes
//## end CSTStateHomeAccelerating%4487D2A10346.preface

//## Class: CSTStateHomeAccelerating%4487D2A10346
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateHomeAccelerating : public CSTStateHome  //## Inherits: <unnamed>%4487D2D50228
{
  //## begin CSTStateHomeAccelerating%4487D2A10346.initialDeclarations preserve=yes
  //## end CSTStateHomeAccelerating%4487D2A10346.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateHomeAccelerating();

    //## Destructor (generated)
      virtual ~CSTStateHomeAccelerating();


    //## Other Operations (specified)
      //## Operation: Create%1149752278
      static void Create ();

      //## Operation: Delete%1149752279
      static void Delete ();

      //## Operation: GetInstance%1149752280
      static CSTStateHomeAccelerating* GetInstance ();

      //## Operation: Do%1149752281
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
      //## begin CSTStateHomeAccelerating%4487D2A10346.public preserve=yes
      //## end CSTStateHomeAccelerating%4487D2A10346.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateHomeAccelerating%4487D2A10346.protected preserve=yes
      //## end CSTStateHomeAccelerating%4487D2A10346.protected

  private:
    //## Constructors (generated)
      CSTStateHomeAccelerating(const CSTStateHomeAccelerating &right);

    //## Assignment Operation (generated)
      const CSTStateHomeAccelerating & operator=(const CSTStateHomeAccelerating &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateHomeAccelerating &right) const;

      bool operator!=(const CSTStateHomeAccelerating &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%4487D34F0260
      //## Role: CSTStateHomeAccelerating::pInstance%4487D3510322
      //## begin CSTStateHomeAccelerating::pInstance%4487D3510322.role preserve=no  public: static CSTStateHomeAccelerating {1..1 -> 1..1RFHN}
      static CSTStateHomeAccelerating *m_pInstance;
      //## end CSTStateHomeAccelerating::pInstance%4487D3510322.role

    // Additional Private Declarations
      //## begin CSTStateHomeAccelerating%4487D2A10346.private preserve=yes
      //## end CSTStateHomeAccelerating%4487D2A10346.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateHomeAccelerating%4487D2A10346.implementation preserve=yes
      //## end CSTStateHomeAccelerating%4487D2A10346.implementation

};

//## begin CSTStateHomeAccelerating%4487D2A10346.postscript preserve=yes
//## end CSTStateHomeAccelerating%4487D2A10346.postscript

//## begin CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.preface preserve=yes
//## end CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.preface

//## Class: CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateHomeSlowlyFindingLimitFromOpposite : public CSTStateHome  //## Inherits: <unnamed>%471CF27D0038
{
  //## begin CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.initialDeclarations preserve=yes
  //## end CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateHomeSlowlyFindingLimitFromOpposite();

    //## Destructor (generated)
      virtual ~CSTStateHomeSlowlyFindingLimitFromOpposite();


    //## Other Operations (specified)
      //## Operation: Create%1193077631
      static void Create ();

      //## Operation: Delete%1193077632
      static void Delete ();

      //## Operation: GetInstance%1193077633
      static CSTStateHomeSlowlyFindingLimitFromOpposite* GetInstance ();

      //## Operation: Do%1193077634
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
      //## begin CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.public preserve=yes
      //## end CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.protected preserve=yes
      //## end CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.protected

  private:
    //## Constructors (generated)
      CSTStateHomeSlowlyFindingLimitFromOpposite(const CSTStateHomeSlowlyFindingLimitFromOpposite &right);

    //## Assignment Operation (generated)
      const CSTStateHomeSlowlyFindingLimitFromOpposite & operator=(const CSTStateHomeSlowlyFindingLimitFromOpposite &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateHomeSlowlyFindingLimitFromOpposite &right) const;

      bool operator!=(const CSTStateHomeSlowlyFindingLimitFromOpposite &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%471CF2AF018E
      //## Role: CSTStateHomeSlowlyFindingLimitFromOpposite::pInstance%471CF2B00320
      //## begin CSTStateHomeSlowlyFindingLimitFromOpposite::pInstance%471CF2B00320.role preserve=no  public: static CSTStateHomeSlowlyFindingLimitFromOpposite {1..1 -> 1..1RFHN}
      static CSTStateHomeSlowlyFindingLimitFromOpposite *m_pInstance;
      //## end CSTStateHomeSlowlyFindingLimitFromOpposite::pInstance%471CF2B00320.role

    // Additional Private Declarations
      //## begin CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.private preserve=yes
      //## end CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.implementation preserve=yes
      //## end CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.implementation

};

//## begin CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.postscript preserve=yes
//## end CSTStateHomeSlowlyFindingLimitFromOpposite%471CF22F03BB.postscript

// Class CSTStateHome 

// Class CSTStateHomePrepare 

// Class CSTStateHomeFastFindingLimit 

// Class CSTStateHomeMovingBackToLatchedLimit 

// Class CSTStateHomeDeceleratingToStop 

// Class CSTStateHomeAtLatchedLimit 

// Class CSTStateHomeLeavingLimit 

// Class CSTStateHomeSlowlyFindingLimit 

// Class CSTStateHomeMovingOutOfLimit 

// Class CSTStateHomeAccelerating 

// Class CSTStateHomeSlowlyFindingLimitFromOpposite 

//## begin module%434137B002D8.epilog preserve=yes
//## end module%434137B002D8.epilog


#endif
