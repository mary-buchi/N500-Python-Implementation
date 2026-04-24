//## begin module%3E71A7470251.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E71A7470251.cm

//## begin module%3E71A7470251.cp preserve=no
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
//## end module%3E71A7470251.cp

//## Module: EBSTconfig%3E71A7470251; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTconfig.h

#ifndef EBSTconfig_h
#define EBSTconfig_h 1

//## begin module%3E71A7470251.additionalIncludes preserve=no
//## end module%3E71A7470251.additionalIncludes

//## begin module%3E71A7470251.includes preserve=yes
//## end module%3E71A7470251.includes

// EBSTstat
#include "EBSTstat.h"
//## begin module%3E71A7470251.declarations preserve=no
//## end module%3E71A7470251.declarations

//## begin module%3E71A7470251.additionalDeclarations preserve=yes
//## end module%3E71A7470251.additionalDeclarations


//## begin CSTStateConfig%3E719E9F03A9.preface preserve=yes
//## end CSTStateConfig%3E719E9F03A9.preface

//## Class: CSTStateConfig%3E719E9F03A9
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E76E1E90207;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3E76E4B602E1;CSTStateCreated { -> }
//## Uses: <unnamed>%3E87E019029B;CSTStepperMotorImplementation { -> }
//## Uses: <unnamed>%3E9566E40252;CPIStepperMotorProfile { -> }
//## Uses: <unnamed>%3F6713D2004A;CSTLogic { -> }
//## Uses: <unnamed>%3F718F2F02EE;ST_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F8EA61F0063;CSTHardwareConnection { -> }

class CSTStateConfig : public CSTState  //## Inherits: <unnamed>%3E75A0DC03AE
{
  //## begin CSTStateConfig%3E719E9F03A9.initialDeclarations preserve=yes
  //## end CSTStateConfig%3E719E9F03A9.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateConfig();

    //## Destructor (generated)
      virtual ~CSTStateConfig();


    //## Other Operations (specified)
      //## Operation: Shutdown%1047892473
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: CleanupInitialize%1053438555
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

      //## Operation: ConnectionLost%1055428401
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: SetConfig%1064473096
      virtual void SetConfig (ICOStateMachineContext* p_pContext, CPIStepperMotorConfig* p_pConfig);

    // Additional Public Declarations
      //## begin CSTStateConfig%3E719E9F03A9.public preserve=yes
      //## end CSTStateConfig%3E719E9F03A9.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateConfig%3E719E9F03A9.protected preserve=yes
      //## end CSTStateConfig%3E719E9F03A9.protected

  private:
    //## Constructors (generated)
      CSTStateConfig(const CSTStateConfig &right);

    //## Assignment Operation (generated)
      const CSTStateConfig & operator=(const CSTStateConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateConfig &right) const;

      bool operator!=(const CSTStateConfig &right) const;

    // Additional Private Declarations
      //## begin CSTStateConfig%3E719E9F03A9.private preserve=yes
      //## end CSTStateConfig%3E719E9F03A9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateConfig%3E719E9F03A9.implementation preserve=yes
      //## end CSTStateConfig%3E719E9F03A9.implementation

};

//## begin CSTStateConfig%3E719E9F03A9.postscript preserve=yes
//## end CSTStateConfig%3E719E9F03A9.postscript

//## begin CSTStateConfigStart%3E71A141028F.preface preserve=yes
//## end CSTStateConfigStart%3E71A141028F.preface

//## Class: CSTStateConfigStart%3E71A141028F
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateConfigStart : public CSTStateConfig  //## Inherits: <unnamed>%3E76E09B01D8
{
  //## begin CSTStateConfigStart%3E71A141028F.initialDeclarations preserve=yes
  //## end CSTStateConfigStart%3E71A141028F.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateConfigStart();

    //## Destructor (generated)
      virtual ~CSTStateConfigStart();


    //## Other Operations (specified)
      //## Operation: Create%1047892464
      static void Create ();

      //## Operation: Delete%1047892465
      static void Delete ();

      //## Operation: GetInstance%1047892466
      static CSTStateConfigStart* GetInstance ();

    // Additional Public Declarations
      //## begin CSTStateConfigStart%3E71A141028F.public preserve=yes
      //## end CSTStateConfigStart%3E71A141028F.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateConfigStart%3E71A141028F.protected preserve=yes
      //## end CSTStateConfigStart%3E71A141028F.protected

  private:
    //## Constructors (generated)
      CSTStateConfigStart(const CSTStateConfigStart &right);

    //## Assignment Operation (generated)
      const CSTStateConfigStart & operator=(const CSTStateConfigStart &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateConfigStart &right) const;

      bool operator!=(const CSTStateConfigStart &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E75C8A500B0
      //## Role: CSTStateConfigStart::pInstance%3E75C8A60208
      //## begin CSTStateConfigStart::pInstance%3E75C8A60208.role preserve=no  public: static CSTStateConfigStart {1..1 -> 1..1RFHN}
      static CSTStateConfigStart *m_pInstance;
      //## end CSTStateConfigStart::pInstance%3E75C8A60208.role

    // Additional Private Declarations
      //## begin CSTStateConfigStart%3E71A141028F.private preserve=yes
      //## end CSTStateConfigStart%3E71A141028F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateConfigStart%3E71A141028F.implementation preserve=yes
      //## end CSTStateConfigStart%3E71A141028F.implementation

};

//## begin CSTStateConfigStart%3E71A141028F.postscript preserve=yes
//## end CSTStateConfigStart%3E71A141028F.postscript

//## begin CSTStateConfigConfigSet%3E71A1AF02BE.preface preserve=yes
//## end CSTStateConfigConfigSet%3E71A1AF02BE.preface

//## Class: CSTStateConfigConfigSet%3E71A1AF02BE
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateConfigConfigSet : public CSTStateConfig  //## Inherits: <unnamed>%3E76E0B203AD
{
  //## begin CSTStateConfigConfigSet%3E71A1AF02BE.initialDeclarations preserve=yes
  //## end CSTStateConfigConfigSet%3E71A1AF02BE.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateConfigConfigSet();

    //## Destructor (generated)
      virtual ~CSTStateConfigConfigSet();


    //## Other Operations (specified)
      //## Operation: Create%1047892467
      static void Create ();

      //## Operation: Delete%1047892468
      static void Delete ();

      //## Operation: GetInstance%1047892469
      static CSTStateConfigConfigSet* GetInstance ();

      //## Operation: SetProfile%1047904788
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPIStepperMotorProfile* p_pProfile);

      //## Operation: Do%1066295286
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
      //## begin CSTStateConfigConfigSet%3E71A1AF02BE.public preserve=yes
      //## end CSTStateConfigConfigSet%3E71A1AF02BE.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateConfigConfigSet%3E71A1AF02BE.protected preserve=yes
      //## end CSTStateConfigConfigSet%3E71A1AF02BE.protected

  private:
    //## Constructors (generated)
      CSTStateConfigConfigSet(const CSTStateConfigConfigSet &right);

    //## Assignment Operation (generated)
      const CSTStateConfigConfigSet & operator=(const CSTStateConfigConfigSet &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateConfigConfigSet &right) const;

      bool operator!=(const CSTStateConfigConfigSet &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E75C8AC00DF
      //## Role: CSTStateConfigConfigSet::pInstance%3E75C8AD00E0
      //## begin CSTStateConfigConfigSet::pInstance%3E75C8AD00E0.role preserve=no  public: static CSTStateConfigConfigSet {1..1 -> 1..1RFHN}
      static CSTStateConfigConfigSet *m_pInstance;
      //## end CSTStateConfigConfigSet::pInstance%3E75C8AD00E0.role

    // Additional Private Declarations
      //## begin CSTStateConfigConfigSet%3E71A1AF02BE.private preserve=yes
      //## end CSTStateConfigConfigSet%3E71A1AF02BE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateConfigConfigSet%3E71A1AF02BE.implementation preserve=yes
      //## end CSTStateConfigConfigSet%3E71A1AF02BE.implementation

};

//## begin CSTStateConfigConfigSet%3E71A1AF02BE.postscript preserve=yes
//## end CSTStateConfigConfigSet%3E71A1AF02BE.postscript

//## begin CSTStateConfigProfileSet%3E71A1B20241.preface preserve=yes
//## end CSTStateConfigProfileSet%3E71A1B20241.preface

//## Class: CSTStateConfigProfileSet%3E71A1B20241
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTStateConfigProfileSet : public CSTStateConfig  //## Inherits: <unnamed>%3E76E0B802E1
{
  //## begin CSTStateConfigProfileSet%3E71A1B20241.initialDeclarations preserve=yes
  //## end CSTStateConfigProfileSet%3E71A1B20241.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateConfigProfileSet();

    //## Destructor (generated)
      virtual ~CSTStateConfigProfileSet();


    //## Other Operations (specified)
      //## Operation: Create%1047892470
      static void Create ();

      //## Operation: Delete%1047892471
      static void Delete ();

      //## Operation: GetInstance%1047892472
      static CSTStateConfigProfileSet* GetInstance ();

      //## Operation: Do%1047971049
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
      //## begin CSTStateConfigProfileSet%3E71A1B20241.public preserve=yes
      //## end CSTStateConfigProfileSet%3E71A1B20241.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateConfigProfileSet%3E71A1B20241.protected preserve=yes
      //## end CSTStateConfigProfileSet%3E71A1B20241.protected

  private:
    //## Constructors (generated)
      CSTStateConfigProfileSet(const CSTStateConfigProfileSet &right);

    //## Assignment Operation (generated)
      const CSTStateConfigProfileSet & operator=(const CSTStateConfigProfileSet &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateConfigProfileSet &right) const;

      bool operator!=(const CSTStateConfigProfileSet &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E75C8AF0237
      //## Role: CSTStateConfigProfileSet::pInstance%3E75C8B001BB
      //## begin CSTStateConfigProfileSet::pInstance%3E75C8B001BB.role preserve=no  public: static CSTStateConfigProfileSet {1..1 -> 1..1RFHN}
      static CSTStateConfigProfileSet *m_pInstance;
      //## end CSTStateConfigProfileSet::pInstance%3E75C8B001BB.role

    // Additional Private Declarations
      //## begin CSTStateConfigProfileSet%3E71A1B20241.private preserve=yes
      //## end CSTStateConfigProfileSet%3E71A1B20241.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateConfigProfileSet%3E71A1B20241.implementation preserve=yes
      //## end CSTStateConfigProfileSet%3E71A1B20241.implementation

};

//## begin CSTStateConfigProfileSet%3E71A1B20241.postscript preserve=yes
//## end CSTStateConfigProfileSet%3E71A1B20241.postscript

// Class CSTStateConfig 

// Class CSTStateConfigStart 

// Class CSTStateConfigConfigSet 

// Class CSTStateConfigProfileSet 

//## begin module%3E71A7470251.epilog preserve=yes
//## end module%3E71A7470251.epilog


#endif
