//## begin module%3E6DE60702DE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E6DE60702DE.cm

//## begin module%3E6DE60702DE.cp preserve=no
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
//## end module%3E6DE60702DE.cp

//## Module: EBMCdata%3E6DE60702DE; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCdata.h

#ifndef EBMCdata_h
#define EBMCdata_h 1

//## begin module%3E6DE60702DE.additionalIncludes preserve=no
//## end module%3E6DE60702DE.additionalIncludes

//## begin module%3E6DE60702DE.includes preserve=yes
//## end module%3E6DE60702DE.includes

// EBMCproc
#include "EBMCproc.h"
//## begin module%3E6DE60702DE.declarations preserve=no
//## end module%3E6DE60702DE.declarations

//## begin module%3E6DE60702DE.additionalDeclarations preserve=yes
//## end module%3E6DE60702DE.additionalDeclarations


//## begin CMCStateData%3E6DDA46036B.preface preserve=yes
//## end CMCStateData%3E6DDA46036B.preface

//## Class: CMCStateData%3E6DDA46036B
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMCStateData : public CMCStateProcess  //## Inherits: <unnamed>%3E6DDB5A038A
{
  //## begin CMCStateData%3E6DDA46036B.initialDeclarations preserve=yes
  //## end CMCStateData%3E6DDA46036B.initialDeclarations

  public:
    //## Constructors (generated)
      CMCStateData();

    //## Destructor (generated)
      virtual ~CMCStateData();


    //## Other Operations (specified)
      //## Operation: Stop%1047364719
      virtual void Stop (ICOStateMachineContext* p_pContext);

      //## Operation: CleanupInitialize%1080293047
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

      //## Operation: ConnectionLost%1083826160
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
      //## begin CMCStateData%3E6DDA46036B.public preserve=yes
      //## end CMCStateData%3E6DDA46036B.public

  protected:
    // Additional Protected Declarations
      //## begin CMCStateData%3E6DDA46036B.protected preserve=yes
      //## end CMCStateData%3E6DDA46036B.protected

  private:
    //## Constructors (generated)
      CMCStateData(const CMCStateData &right);

    //## Assignment Operation (generated)
      const CMCStateData & operator=(const CMCStateData &right);

    //## Equality Operations (generated)
      bool operator==(const CMCStateData &right) const;

      bool operator!=(const CMCStateData &right) const;

    // Additional Private Declarations
      //## begin CMCStateData%3E6DDA46036B.private preserve=yes
      //## end CMCStateData%3E6DDA46036B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCStateData%3E6DDA46036B.implementation preserve=yes
      //## end CMCStateData%3E6DDA46036B.implementation

};

//## begin CMCStateData%3E6DDA46036B.postscript preserve=yes
//## end CMCStateData%3E6DDA46036B.postscript

//## begin CMCStateDataAcquistionReady%3E6DDBF60261.preface preserve=yes
//## end CMCStateDataAcquistionReady%3E6DDBF60261.preface

//## Class: CMCStateDataAcquistionReady%3E6DDBF60261
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E6DFBDE037A;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3E6DFBF70251;MC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3E6DFF0E00CB;IHIInterface { -> }

class CMCStateDataAcquistionReady : public CMCStateData  //## Inherits: <unnamed>%3E6DDC200399
{
  //## begin CMCStateDataAcquistionReady%3E6DDBF60261.initialDeclarations preserve=yes
  //## end CMCStateDataAcquistionReady%3E6DDBF60261.initialDeclarations

  public:
    //## Constructors (generated)
      CMCStateDataAcquistionReady();

    //## Destructor (generated)
      virtual ~CMCStateDataAcquistionReady();


    //## Other Operations (specified)
      //## Operation: Delete%1047364730
      static void Delete ();

      //## Operation: Create%1047364731
      static void Create ();

      //## Operation: GetInstance%1047364732
      static CMCStateDataAcquistionReady* GetInstance ();

      //## Operation: GetDataPackage%1047364720
      virtual void GetDataPackage (ICOStateMachineContext* p_pContext, CPISyncObjDataPackage* p_pClientSyncObj);

    // Additional Public Declarations
      //## begin CMCStateDataAcquistionReady%3E6DDBF60261.public preserve=yes
      //## end CMCStateDataAcquistionReady%3E6DDBF60261.public

  protected:
    // Additional Protected Declarations
      //## begin CMCStateDataAcquistionReady%3E6DDBF60261.protected preserve=yes
      //## end CMCStateDataAcquistionReady%3E6DDBF60261.protected

  private:
    //## Constructors (generated)
      CMCStateDataAcquistionReady(const CMCStateDataAcquistionReady &right);

    //## Assignment Operation (generated)
      const CMCStateDataAcquistionReady & operator=(const CMCStateDataAcquistionReady &right);

    //## Equality Operations (generated)
      bool operator==(const CMCStateDataAcquistionReady &right) const;

      bool operator!=(const CMCStateDataAcquistionReady &right) const;

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3E6DDCAE032C
      //## Role: CMCStateDataAcquistionReady::pInstance%3E6DDCB101D5
      //## begin CMCStateDataAcquistionReady::pInstance%3E6DDCB101D5.role preserve=no  public: static CMCStateDataAcquistionReady {1..1 -> 1..1RFHN}
      static CMCStateDataAcquistionReady *m_pInstance;
      //## end CMCStateDataAcquistionReady::pInstance%3E6DDCB101D5.role

    // Additional Private Declarations
      //## begin CMCStateDataAcquistionReady%3E6DDBF60261.private preserve=yes
      //## end CMCStateDataAcquistionReady%3E6DDBF60261.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCStateDataAcquistionReady%3E6DDBF60261.implementation preserve=yes
      //## end CMCStateDataAcquistionReady%3E6DDBF60261.implementation

};

//## begin CMCStateDataAcquistionReady%3E6DDBF60261.postscript preserve=yes
//## end CMCStateDataAcquistionReady%3E6DDBF60261.postscript

//## begin CMCStateGetDataPackage%3E6DDC0D03D8.preface preserve=yes
//## end CMCStateGetDataPackage%3E6DDC0D03D8.preface

//## Class: CMCStateGetDataPackage%3E6DDC0D03D8
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E6DFC79029F;CMCMeasurementChannelImplementation { -> }
//## Uses: <unnamed>%3E6DFC830280;XCOExceptionError { -> }
//## Uses: <unnamed>%3FD03242035B;XMCExceptionError { -> }

class CMCStateGetDataPackage : public CMCStateData  //## Inherits: <unnamed>%3E6DDC2301C5
{
  //## begin CMCStateGetDataPackage%3E6DDC0D03D8.initialDeclarations preserve=yes
  //## end CMCStateGetDataPackage%3E6DDC0D03D8.initialDeclarations

  public:
    //## Constructors (generated)
      CMCStateGetDataPackage();

    //## Destructor (generated)
      virtual ~CMCStateGetDataPackage();


    //## Other Operations (specified)
      //## Operation: Delete%1047364733
      static void Delete ();

      //## Operation: Create%1047364734
      static void Create ();

      //## Operation: GetInstance%1047364735
      static CMCStateGetDataPackage* GetInstance ();

      //## Operation: Do%1047390944
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
      //## begin CMCStateGetDataPackage%3E6DDC0D03D8.public preserve=yes
      //## end CMCStateGetDataPackage%3E6DDC0D03D8.public

  protected:
    // Additional Protected Declarations
      //## begin CMCStateGetDataPackage%3E6DDC0D03D8.protected preserve=yes
      //## end CMCStateGetDataPackage%3E6DDC0D03D8.protected

  private:
    //## Constructors (generated)
      CMCStateGetDataPackage(const CMCStateGetDataPackage &right);

    //## Assignment Operation (generated)
      const CMCStateGetDataPackage & operator=(const CMCStateGetDataPackage &right);

    //## Equality Operations (generated)
      bool operator==(const CMCStateGetDataPackage &right) const;

      bool operator!=(const CMCStateGetDataPackage &right) const;

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3E6DDCB703A9
      //## Role: CMCStateGetDataPackage::pInstance%3E6DDCBA0109
      //## begin CMCStateGetDataPackage::pInstance%3E6DDCBA0109.role preserve=no  public: static CMCStateGetDataPackage {1..1 -> RFHN}
      static CMCStateGetDataPackage *m_pInstance;
      //## end CMCStateGetDataPackage::pInstance%3E6DDCBA0109.role

    // Additional Private Declarations
      //## begin CMCStateGetDataPackage%3E6DDC0D03D8.private preserve=yes
      //## end CMCStateGetDataPackage%3E6DDC0D03D8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCStateGetDataPackage%3E6DDC0D03D8.implementation preserve=yes
      //## end CMCStateGetDataPackage%3E6DDC0D03D8.implementation

};

//## begin CMCStateGetDataPackage%3E6DDC0D03D8.postscript preserve=yes
//## end CMCStateGetDataPackage%3E6DDC0D03D8.postscript

//## begin CMCStateDataSimulationPrepare%3F9786DF0301.preface preserve=yes
//## end CMCStateDataSimulationPrepare%3F9786DF0301.preface

//## Class: CMCStateDataSimulationPrepare%3F9786DF0301
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F978ED8012C;CMCCtrlSimulation { -> }

class CMCStateDataSimulationPrepare : public CMCStateData  //## Inherits: <unnamed>%3F9786F7018A
{
  //## begin CMCStateDataSimulationPrepare%3F9786DF0301.initialDeclarations preserve=yes
  //## end CMCStateDataSimulationPrepare%3F9786DF0301.initialDeclarations

  public:
    //## Constructors (generated)
      CMCStateDataSimulationPrepare();

    //## Destructor (generated)
      virtual ~CMCStateDataSimulationPrepare();


    //## Other Operations (specified)
      //## Operation: Delete%1066894463
      static void Delete ();

      //## Operation: Create%1066894464
      static void Create ();

      //## Operation: GetInstance%1066894465
      static CMCStateDataSimulationPrepare* GetInstance ();

      //## Operation: Do%1066894466
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
      //## begin CMCStateDataSimulationPrepare%3F9786DF0301.public preserve=yes
      //## end CMCStateDataSimulationPrepare%3F9786DF0301.public

  protected:
    // Additional Protected Declarations
      //## begin CMCStateDataSimulationPrepare%3F9786DF0301.protected preserve=yes
      //## end CMCStateDataSimulationPrepare%3F9786DF0301.protected

  private:
    //## Constructors (generated)
      CMCStateDataSimulationPrepare(const CMCStateDataSimulationPrepare &right);

    //## Assignment Operation (generated)
      const CMCStateDataSimulationPrepare & operator=(const CMCStateDataSimulationPrepare &right);

    //## Equality Operations (generated)
      bool operator==(const CMCStateDataSimulationPrepare &right) const;

      bool operator!=(const CMCStateDataSimulationPrepare &right) const;

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3F97874101E7
      //## Role: CMCStateDataSimulationPrepare::pInstance%3F9787420236
      //## begin CMCStateDataSimulationPrepare::pInstance%3F9787420236.role preserve=no  public: static CMCStateDataSimulationPrepare {1..1 -> 1..1RFHN}
      static CMCStateDataSimulationPrepare *m_pInstance;
      //## end CMCStateDataSimulationPrepare::pInstance%3F9787420236.role

      //## Association: EBMC (Measurement Channel)::<unnamed>%3F97874101E7
      //## Role: CMCStateDataSimulationPrepare::<m_CMCStateDataSimulationPrepare>%3F9787420235
      //## begin CMCStateDataSimulationPrepare::<m_CMCStateDataSimulationPrepare>%3F9787420235.role preserve=no  public: CMCStateDataSimulationPrepare {1..1 -> 1..1RFHGN}
      CMCStateDataSimulationPrepare *m_CMCStateDataSimulationPrepare;
      //## end CMCStateDataSimulationPrepare::<m_CMCStateDataSimulationPrepare>%3F9787420235.role

    // Additional Private Declarations
      //## begin CMCStateDataSimulationPrepare%3F9786DF0301.private preserve=yes
      //## end CMCStateDataSimulationPrepare%3F9786DF0301.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCStateDataSimulationPrepare%3F9786DF0301.implementation preserve=yes
      //## end CMCStateDataSimulationPrepare%3F9786DF0301.implementation

};

//## begin CMCStateDataSimulationPrepare%3F9786DF0301.postscript preserve=yes
//## end CMCStateDataSimulationPrepare%3F9786DF0301.postscript

//## begin CMCStateDataSimulationReady%3F979AAD036E.preface preserve=yes
//## end CMCStateDataSimulationReady%3F979AAD036E.preface

//## Class: CMCStateDataSimulationReady%3F979AAD036E
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CMCStateDataSimulationReady : public CMCStateData  //## Inherits: <unnamed>%3F979ADF0274
{
  //## begin CMCStateDataSimulationReady%3F979AAD036E.initialDeclarations preserve=yes
  //## end CMCStateDataSimulationReady%3F979AAD036E.initialDeclarations

  public:
    //## Constructors (generated)
      CMCStateDataSimulationReady();

    //## Destructor (generated)
      virtual ~CMCStateDataSimulationReady();


    //## Other Operations (specified)
      //## Operation: Delete%1066894468
      static void Delete ();

      //## Operation: Create%1066894469
      static void Create ();

      //## Operation: GetInstance%1066894470
      static CMCStateDataSimulationReady* GetInstance ();

      //## Operation: Do%1066894471
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: GetDataPackage%1066894472
      virtual void GetDataPackage (ICOStateMachineContext* p_pContext, CPISyncObjDataPackage* p_pClientSyncObj);

    // Additional Public Declarations
      //## begin CMCStateDataSimulationReady%3F979AAD036E.public preserve=yes
      //## end CMCStateDataSimulationReady%3F979AAD036E.public

  protected:
    // Additional Protected Declarations
      //## begin CMCStateDataSimulationReady%3F979AAD036E.protected preserve=yes
      //## end CMCStateDataSimulationReady%3F979AAD036E.protected

  private:
    //## Constructors (generated)
      CMCStateDataSimulationReady(const CMCStateDataSimulationReady &right);

    //## Assignment Operation (generated)
      const CMCStateDataSimulationReady & operator=(const CMCStateDataSimulationReady &right);

    //## Equality Operations (generated)
      bool operator==(const CMCStateDataSimulationReady &right) const;

      bool operator!=(const CMCStateDataSimulationReady &right) const;

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3F979AF7018A
      //## Role: CMCStateDataSimulationReady::pInstance%3F979AF801D9
      //## begin CMCStateDataSimulationReady::pInstance%3F979AF801D9.role preserve=no  public: static CMCStateDataSimulationReady {1..1 -> 1..1RFHN}
      static CMCStateDataSimulationReady *m_pInstance;
      //## end CMCStateDataSimulationReady::pInstance%3F979AF801D9.role

    // Additional Private Declarations
      //## begin CMCStateDataSimulationReady%3F979AAD036E.private preserve=yes
      //## end CMCStateDataSimulationReady%3F979AAD036E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCStateDataSimulationReady%3F979AAD036E.implementation preserve=yes
      //## end CMCStateDataSimulationReady%3F979AAD036E.implementation

};

//## begin CMCStateDataSimulationReady%3F979AAD036E.postscript preserve=yes
//## end CMCStateDataSimulationReady%3F979AAD036E.postscript

// Class CMCStateData 

// Class CMCStateDataAcquistionReady 

// Class CMCStateGetDataPackage 

// Class CMCStateDataSimulationPrepare 

// Class CMCStateDataSimulationReady 

//## begin module%3E6DE60702DE.epilog preserve=yes
//## end module%3E6DE60702DE.epilog


#endif
