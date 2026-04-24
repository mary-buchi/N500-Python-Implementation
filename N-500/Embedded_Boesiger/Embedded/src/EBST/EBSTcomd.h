//## begin module%3DAA5DCF00FC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAA5DCF00FC.cm

//## begin module%3DAA5DCF00FC.cp preserve=no
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
//## end module%3DAA5DCF00FC.cp

//## Module: EBSTcomd%3DAA5DCF00FC; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTcomd.h

#ifndef EBSTcomd_h
#define EBSTcomd_h 1

//## begin module%3DAA5DCF00FC.additionalIncludes preserve=no
//## end module%3DAA5DCF00FC.additionalIncludes

//## begin module%3DAA5DCF00FC.includes preserve=yes
//## end module%3DAA5DCF00FC.includes

// EBPIenum
#include "EBPIenum.h"
// EBCOcomd
#include "EBCOcomd.h"

class EBPI_DLL_DECL CPIObjIdentification;
class EBPI_DLL_DECL CPIStepperMotorProfile;
class EBPI_DLL_DECL CPIStepperMotorConfig;
class CSTState;

//## begin module%3DAA5DCF00FC.declarations preserve=no
//## end module%3DAA5DCF00FC.declarations

//## begin module%3DAA5DCF00FC.additionalDeclarations preserve=yes
//## end module%3DAA5DCF00FC.additionalDeclarations


//## begin CSTCommand%3DAA5E350215.preface preserve=yes
//## end CSTCommand%3DAA5E350215.preface

//## Class: CSTCommand%3DAA5E350215
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAA5F8B039C;CSTState { -> F}

class CSTCommand : public CCOCommand  //## Inherits: <unnamed>%3DAA5E4601D7
{
  //## begin CSTCommand%3DAA5E350215.initialDeclarations preserve=yes
  //## end CSTCommand%3DAA5E350215.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommand%1034575083
      CSTCommand (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSTCommand();


    //## Other Operations (specified)
      //## Operation: Execute%1034575084
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CCOState* p_pCurrentState);

      //## Operation: Execute%1034575085
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState) = 0;

    // Additional Public Declarations
      //## begin CSTCommand%3DAA5E350215.public preserve=yes
      //## end CSTCommand%3DAA5E350215.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommand%3DAA5E350215.protected preserve=yes
      //## end CSTCommand%3DAA5E350215.protected

  private:
    //## Constructors (generated)
      CSTCommand();

      CSTCommand(const CSTCommand &right);

    //## Assignment Operation (generated)
      const CSTCommand & operator=(const CSTCommand &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommand &right) const;

      bool operator!=(const CSTCommand &right) const;

    // Additional Private Declarations
      //## begin CSTCommand%3DAA5E350215.private preserve=yes
      //## end CSTCommand%3DAA5E350215.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommand%3DAA5E350215.implementation preserve=yes
      //## end CSTCommand%3DAA5E350215.implementation

};

//## begin CSTCommand%3DAA5E350215.postscript preserve=yes
//## end CSTCommand%3DAA5E350215.postscript

//## begin CSTCommandGetPosition%3DAA5DAE02D1.preface preserve=yes
//## end CSTCommandGetPosition%3DAA5DAE02D1.preface

//## Class: CSTCommandGetPosition%3DAA5DAE02D1
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandGetPosition : public CSTCommand  //## Inherits: <unnamed>%3DAA5DBD0263
{
  //## begin CSTCommandGetPosition%3DAA5DAE02D1.initialDeclarations preserve=yes
  //## end CSTCommandGetPosition%3DAA5DAE02D1.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandGetPosition%1034575081
      CSTCommandGetPosition (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSTCommandGetPosition();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1034575092
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1034575082
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandGetPosition%3DAA5DAE02D1.public preserve=yes
      //## end CSTCommandGetPosition%3DAA5DAE02D1.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandGetPosition%3DAA5DAE02D1.protected preserve=yes
      //## end CSTCommandGetPosition%3DAA5DAE02D1.protected

  private:
    //## Constructors (generated)
      CSTCommandGetPosition();

      CSTCommandGetPosition(const CSTCommandGetPosition &right);

    //## Assignment Operation (generated)
      const CSTCommandGetPosition & operator=(const CSTCommandGetPosition &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandGetPosition &right) const;

      bool operator!=(const CSTCommandGetPosition &right) const;

    // Additional Private Declarations
      //## begin CSTCommandGetPosition%3DAA5DAE02D1.private preserve=yes
      //## end CSTCommandGetPosition%3DAA5DAE02D1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandGetPosition%3DAA5DAE02D1.implementation preserve=yes
      //## end CSTCommandGetPosition%3DAA5DAE02D1.implementation

};

//## begin CSTCommandGetPosition%3DAA5DAE02D1.postscript preserve=yes
//## end CSTCommandGetPosition%3DAA5DAE02D1.postscript

//## begin CSTCommandMoveAbsolute%3DE1EF47021F.preface preserve=yes
//## end CSTCommandMoveAbsolute%3DE1EF47021F.preface

//## Class: CSTCommandMoveAbsolute%3DE1EF47021F
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandMoveAbsolute : public CSTCommand  //## Inherits: <unnamed>%3DE1EF5A00E6
{
  //## begin CSTCommandMoveAbsolute%3DE1EF47021F.initialDeclarations preserve=yes
  //## end CSTCommandMoveAbsolute%3DE1EF47021F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandMoveAbsolute%1038217265
      CSTCommandMoveAbsolute (ICOStateMachineContext* p_pContext, INT p_iTargetPosition, INT p_iSearchDistance);

    //## Destructor (generated)
      virtual ~CSTCommandMoveAbsolute();


    //## Other Operations (specified)
      //## Operation: Execute%1038217266
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandMoveAbsolute%3DE1EF47021F.public preserve=yes
      //## end CSTCommandMoveAbsolute%3DE1EF47021F.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandMoveAbsolute%3DE1EF47021F.protected preserve=yes
      //## end CSTCommandMoveAbsolute%3DE1EF47021F.protected

  private:
    //## Constructors (generated)
      CSTCommandMoveAbsolute();

      CSTCommandMoveAbsolute(const CSTCommandMoveAbsolute &right);

    //## Assignment Operation (generated)
      const CSTCommandMoveAbsolute & operator=(const CSTCommandMoveAbsolute &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandMoveAbsolute &right) const;

      bool operator!=(const CSTCommandMoveAbsolute &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE367A20291
      //## Role: CSTCommandMoveAbsolute::iTargetPosition%3DE367A300CD
      //## begin CSTCommandMoveAbsolute::iTargetPosition%3DE367A300CD.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iTargetPosition;
      //## end CSTCommandMoveAbsolute::iTargetPosition%3DE367A300CD.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE367A7011A
      //## Role: CSTCommandMoveAbsolute::iSearchDistance%3DE367A8010C
      //## begin CSTCommandMoveAbsolute::iSearchDistance%3DE367A8010C.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iSearchDistance;
      //## end CSTCommandMoveAbsolute::iSearchDistance%3DE367A8010C.role

    // Additional Private Declarations
      //## begin CSTCommandMoveAbsolute%3DE1EF47021F.private preserve=yes
      //## end CSTCommandMoveAbsolute%3DE1EF47021F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandMoveAbsolute%3DE1EF47021F.implementation preserve=yes
      //## end CSTCommandMoveAbsolute%3DE1EF47021F.implementation

};

//## begin CSTCommandMoveAbsolute%3DE1EF47021F.postscript preserve=yes
//## end CSTCommandMoveAbsolute%3DE1EF47021F.postscript

//## begin CSTCommandMoveRelative%3DE1F01100D7.preface preserve=yes
//## end CSTCommandMoveRelative%3DE1F01100D7.preface

//## Class: CSTCommandMoveRelative%3DE1F01100D7
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandMoveRelative : public CSTCommand  //## Inherits: <unnamed>%3DE1F03C0163
{
  //## begin CSTCommandMoveRelative%3DE1F01100D7.initialDeclarations preserve=yes
  //## end CSTCommandMoveRelative%3DE1F01100D7.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandMoveRelative%1038217267
      CSTCommandMoveRelative (ICOStateMachineContext* p_pContext, INT p_iTotalDistance, INT p_iSearchDistance);

    //## Destructor (generated)
      virtual ~CSTCommandMoveRelative();


    //## Other Operations (specified)
      //## Operation: Execute%1038217268
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandMoveRelative%3DE1F01100D7.public preserve=yes
      //## end CSTCommandMoveRelative%3DE1F01100D7.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandMoveRelative%3DE1F01100D7.protected preserve=yes
      //## end CSTCommandMoveRelative%3DE1F01100D7.protected

  private:
    //## Constructors (generated)
      CSTCommandMoveRelative();

      CSTCommandMoveRelative(const CSTCommandMoveRelative &right);

    //## Assignment Operation (generated)
      const CSTCommandMoveRelative & operator=(const CSTCommandMoveRelative &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandMoveRelative &right) const;

      bool operator!=(const CSTCommandMoveRelative &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE367AC033D
      //## Role: CSTCommandMoveRelative::iTotalDistance%3DE367AD03CB
      //## begin CSTCommandMoveRelative::iTotalDistance%3DE367AD03CB.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iTotalDistance;
      //## end CSTCommandMoveRelative::iTotalDistance%3DE367AD03CB.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE367B20149
      //## Role: CSTCommandMoveRelative::iSearchDistance%3DE367B30179
      //## begin CSTCommandMoveRelative::iSearchDistance%3DE367B30179.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iSearchDistance;
      //## end CSTCommandMoveRelative::iSearchDistance%3DE367B30179.role

    // Additional Private Declarations
      //## begin CSTCommandMoveRelative%3DE1F01100D7.private preserve=yes
      //## end CSTCommandMoveRelative%3DE1F01100D7.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandMoveRelative%3DE1F01100D7.implementation preserve=yes
      //## end CSTCommandMoveRelative%3DE1F01100D7.implementation

};

//## begin CSTCommandMoveRelative%3DE1F01100D7.postscript preserve=yes
//## end CSTCommandMoveRelative%3DE1F01100D7.postscript

//## begin CSTCommandMoveManual%3DE1F1160357.preface preserve=yes
//## end CSTCommandMoveManual%3DE1F1160357.preface

//## Class: CSTCommandMoveManual%3DE1F1160357
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandMoveManual : public CSTCommand  //## Inherits: <unnamed>%3DE1F13101C1
{
  //## begin CSTCommandMoveManual%3DE1F1160357.initialDeclarations preserve=yes
  //## end CSTCommandMoveManual%3DE1F1160357.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandMoveManual%1038217269
      CSTCommandMoveManual (ICOStateMachineContext* p_pContext, INT p_iEndPosition, INT p_uiSpeed);

    //## Destructor (generated)
      virtual ~CSTCommandMoveManual();


    //## Other Operations (specified)
      //## Operation: Execute%1038217270
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandMoveManual%3DE1F1160357.public preserve=yes
      //## end CSTCommandMoveManual%3DE1F1160357.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandMoveManual%3DE1F1160357.protected preserve=yes
      //## end CSTCommandMoveManual%3DE1F1160357.protected

  private:
    //## Constructors (generated)
      CSTCommandMoveManual();

      CSTCommandMoveManual(const CSTCommandMoveManual &right);

    //## Assignment Operation (generated)
      const CSTCommandMoveManual & operator=(const CSTCommandMoveManual &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandMoveManual &right) const;

      bool operator!=(const CSTCommandMoveManual &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE367B6032E
      //## Role: CSTCommandMoveManual::iEndPosition%3DE367B7012B
      //## begin CSTCommandMoveManual::iEndPosition%3DE367B7012B.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iEndPosition;
      //## end CSTCommandMoveManual::iEndPosition%3DE367B7012B.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE367BD02D0
      //## Role: CSTCommandMoveManual::uiSpeed%3DE367BE03BB
      //## begin CSTCommandMoveManual::uiSpeed%3DE367BE03BB.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_uiSpeed;
      //## end CSTCommandMoveManual::uiSpeed%3DE367BE03BB.role

    // Additional Private Declarations
      //## begin CSTCommandMoveManual%3DE1F1160357.private preserve=yes
      //## end CSTCommandMoveManual%3DE1F1160357.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandMoveManual%3DE1F1160357.implementation preserve=yes
      //## end CSTCommandMoveManual%3DE1F1160357.implementation

};

//## begin CSTCommandMoveManual%3DE1F1160357.postscript preserve=yes
//## end CSTCommandMoveManual%3DE1F1160357.postscript

//## begin CSTCommandStop%3DE1F1EE0183.preface preserve=yes
//## end CSTCommandStop%3DE1F1EE0183.preface

//## Class: CSTCommandStop%3DE1F1EE0183
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandStop : public CSTCommand  //## Inherits: <unnamed>%3DE1F1FE03B5
{
  //## begin CSTCommandStop%3DE1F1EE0183.initialDeclarations preserve=yes
  //## end CSTCommandStop%3DE1F1EE0183.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandStop%1038217271
      CSTCommandStop (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSTCommandStop();


    //## Other Operations (specified)
      //## Operation: Execute%1038217272
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandStop%3DE1F1EE0183.public preserve=yes
      //## end CSTCommandStop%3DE1F1EE0183.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandStop%3DE1F1EE0183.protected preserve=yes
      //## end CSTCommandStop%3DE1F1EE0183.protected

  private:
    //## Constructors (generated)
      CSTCommandStop();

      CSTCommandStop(const CSTCommandStop &right);

    //## Assignment Operation (generated)
      const CSTCommandStop & operator=(const CSTCommandStop &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandStop &right) const;

      bool operator!=(const CSTCommandStop &right) const;

    // Additional Private Declarations
      //## begin CSTCommandStop%3DE1F1EE0183.private preserve=yes
      //## end CSTCommandStop%3DE1F1EE0183.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandStop%3DE1F1EE0183.implementation preserve=yes
      //## end CSTCommandStop%3DE1F1EE0183.implementation

};

//## begin CSTCommandStop%3DE1F1EE0183.postscript preserve=yes
//## end CSTCommandStop%3DE1F1EE0183.postscript

//## begin CSTCommandStopImmediately%3DE1F2C200A8.preface preserve=yes
//## end CSTCommandStopImmediately%3DE1F2C200A8.preface

//## Class: CSTCommandStopImmediately%3DE1F2C200A8
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandStopImmediately : public CSTCommand  //## Inherits: <unnamed>%3DE1F2EA022F
{
  //## begin CSTCommandStopImmediately%3DE1F2C200A8.initialDeclarations preserve=yes
  //## end CSTCommandStopImmediately%3DE1F2C200A8.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandStopImmediately%1038217273
      CSTCommandStopImmediately (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSTCommandStopImmediately();


    //## Other Operations (specified)
      //## Operation: Execute%1038217274
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandStopImmediately%3DE1F2C200A8.public preserve=yes
      //## end CSTCommandStopImmediately%3DE1F2C200A8.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandStopImmediately%3DE1F2C200A8.protected preserve=yes
      //## end CSTCommandStopImmediately%3DE1F2C200A8.protected

  private:
    //## Constructors (generated)
      CSTCommandStopImmediately();

      CSTCommandStopImmediately(const CSTCommandStopImmediately &right);

    //## Assignment Operation (generated)
      const CSTCommandStopImmediately & operator=(const CSTCommandStopImmediately &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandStopImmediately &right) const;

      bool operator!=(const CSTCommandStopImmediately &right) const;

    // Additional Private Declarations
      //## begin CSTCommandStopImmediately%3DE1F2C200A8.private preserve=yes
      //## end CSTCommandStopImmediately%3DE1F2C200A8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandStopImmediately%3DE1F2C200A8.implementation preserve=yes
      //## end CSTCommandStopImmediately%3DE1F2C200A8.implementation

};

//## begin CSTCommandStopImmediately%3DE1F2C200A8.postscript preserve=yes
//## end CSTCommandStopImmediately%3DE1F2C200A8.postscript

//## begin CSTCommandSetProfile%3DE1F36E01B2.preface preserve=yes
//## end CSTCommandSetProfile%3DE1F36E01B2.preface

//## Class: CSTCommandSetProfile%3DE1F36E01B2
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandSetProfile : public CSTCommand  //## Inherits: <unnamed>%3DE1F38401D1
{
  //## begin CSTCommandSetProfile%3DE1F36E01B2.initialDeclarations preserve=yes
  //## end CSTCommandSetProfile%3DE1F36E01B2.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandSetProfile%1038217275
      CSTCommandSetProfile (ICOStateMachineContext* p_pContext, CPIStepperMotorProfile* p_pProfile);

    //## Destructor (generated)
      virtual ~CSTCommandSetProfile();


    //## Other Operations (specified)
      //## Operation: Execute%1038217276
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandSetProfile%3DE1F36E01B2.public preserve=yes
      //## end CSTCommandSetProfile%3DE1F36E01B2.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandSetProfile%3DE1F36E01B2.protected preserve=yes
      //## end CSTCommandSetProfile%3DE1F36E01B2.protected

  private:
    //## Constructors (generated)
      CSTCommandSetProfile();

      CSTCommandSetProfile(const CSTCommandSetProfile &right);

    //## Assignment Operation (generated)
      const CSTCommandSetProfile & operator=(const CSTCommandSetProfile &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandSetProfile &right) const;

      bool operator!=(const CSTCommandSetProfile &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E7595C10350
      //## Role: CSTCommandSetProfile::pProfile%3E7595C201D9
      //## begin CSTCommandSetProfile::pProfile%3E7595C201D9.role preserve=no  public: CPIStepperMotorProfile {1..1 -> 1..1RFHN}
      CPIStepperMotorProfile *m_pProfile;
      //## end CSTCommandSetProfile::pProfile%3E7595C201D9.role

    // Additional Private Declarations
      //## begin CSTCommandSetProfile%3DE1F36E01B2.private preserve=yes
      //## end CSTCommandSetProfile%3DE1F36E01B2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandSetProfile%3DE1F36E01B2.implementation preserve=yes
      //## end CSTCommandSetProfile%3DE1F36E01B2.implementation

};

//## begin CSTCommandSetProfile%3DE1F36E01B2.postscript preserve=yes
//## end CSTCommandSetProfile%3DE1F36E01B2.postscript

//## begin CSTCommandSetSpeed%3DE1F3D10348.preface preserve=yes
//## end CSTCommandSetSpeed%3DE1F3D10348.preface

//## Class: CSTCommandSetSpeed%3DE1F3D10348
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandSetSpeed : public CSTCommand  //## Inherits: <unnamed>%3DE1F3DF0386
{
  //## begin CSTCommandSetSpeed%3DE1F3D10348.initialDeclarations preserve=yes
  //## end CSTCommandSetSpeed%3DE1F3D10348.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandSetSpeed%1038217277
      CSTCommandSetSpeed (ICOStateMachineContext* p_pContext, UINT p_uiSpeed);

    //## Destructor (generated)
      virtual ~CSTCommandSetSpeed();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1038217279
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1038217278
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandSetSpeed%3DE1F3D10348.public preserve=yes
      //## end CSTCommandSetSpeed%3DE1F3D10348.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandSetSpeed%3DE1F3D10348.protected preserve=yes
      //## end CSTCommandSetSpeed%3DE1F3D10348.protected

  private:
    //## Constructors (generated)
      CSTCommandSetSpeed();

      CSTCommandSetSpeed(const CSTCommandSetSpeed &right);

    //## Assignment Operation (generated)
      const CSTCommandSetSpeed & operator=(const CSTCommandSetSpeed &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandSetSpeed &right) const;

      bool operator!=(const CSTCommandSetSpeed &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE366B3011A
      //## Role: CSTCommandSetSpeed::uiSpeed%3DE366B4013B
      //## begin CSTCommandSetSpeed::uiSpeed%3DE366B4013B.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiSpeed;
      //## end CSTCommandSetSpeed::uiSpeed%3DE366B4013B.role

    // Additional Private Declarations
      //## begin CSTCommandSetSpeed%3DE1F3D10348.private preserve=yes
      //## end CSTCommandSetSpeed%3DE1F3D10348.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandSetSpeed%3DE1F3D10348.implementation preserve=yes
      //## end CSTCommandSetSpeed%3DE1F3D10348.implementation

};

//## begin CSTCommandSetSpeed%3DE1F3D10348.postscript preserve=yes
//## end CSTCommandSetSpeed%3DE1F3D10348.postscript

//## begin CSTCommandLimitAdd%3DE1F6F20069.preface preserve=yes
//## end CSTCommandLimitAdd%3DE1F6F20069.preface

//## Class: CSTCommandLimitAdd%3DE1F6F20069
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandLimitAdd : public CSTCommand  //## Inherits: <unnamed>%3DE1F70F01F0
{
  //## begin CSTCommandLimitAdd%3DE1F6F20069.initialDeclarations preserve=yes
  //## end CSTCommandLimitAdd%3DE1F6F20069.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandLimitAdd%1038217281
      CSTCommandLimitAdd (ICOStateMachineContext* p_pContext, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction, CPIObjIdentification* p_pSensor);

    //## Destructor (generated)
      virtual ~CSTCommandLimitAdd();


    //## Other Operations (specified)
      //## Operation: Execute%1038217282
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandLimitAdd%3DE1F6F20069.public preserve=yes
      //## end CSTCommandLimitAdd%3DE1F6F20069.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandLimitAdd%3DE1F6F20069.protected preserve=yes
      //## end CSTCommandLimitAdd%3DE1F6F20069.protected

  private:
    //## Constructors (generated)
      CSTCommandLimitAdd();

      CSTCommandLimitAdd(const CSTCommandLimitAdd &right);

    //## Assignment Operation (generated)
      const CSTCommandLimitAdd & operator=(const CSTCommandLimitAdd &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandLimitAdd &right) const;

      bool operator!=(const CSTCommandLimitAdd &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE38D6C004F
      //## Role: CSTCommandLimitAdd::eLimitCharacteristics%3DE38D6C02B2
      //## begin CSTCommandLimitAdd::eLimitCharacteristics%3DE38D6C02B2.role preserve=no  public: EPILimitCharacteristics {1..1 -> 1..1VHN}
      EPILimitCharacteristics m_eLimitCharacteristics;
      //## end CSTCommandLimitAdd::eLimitCharacteristics%3DE38D6C02B2.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE38D6F008E
      //## Role: CSTCommandLimitAdd::eLimitAction%3DE38D6F02D1
      //## begin CSTCommandLimitAdd::eLimitAction%3DE38D6F02D1.role preserve=no  public: EPILimitAction {1..1 -> 1..1VHN}
      EPILimitAction m_eLimitAction;
      //## end CSTCommandLimitAdd::eLimitAction%3DE38D6F02D1.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE38D720168
      //## Role: CSTCommandLimitAdd::pSensor%3DE38D730041
      //## begin CSTCommandLimitAdd::pSensor%3DE38D730041.role preserve=no  public: CPIObjIdentification {1..1 -> 1..1RFHN}
      CPIObjIdentification *m_pSensor;
      //## end CSTCommandLimitAdd::pSensor%3DE38D730041.role

    // Additional Private Declarations
      //## begin CSTCommandLimitAdd%3DE1F6F20069.private preserve=yes
      //## end CSTCommandLimitAdd%3DE1F6F20069.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandLimitAdd%3DE1F6F20069.implementation preserve=yes
      //## end CSTCommandLimitAdd%3DE1F6F20069.implementation

};

//## begin CSTCommandLimitAdd%3DE1F6F20069.postscript preserve=yes
//## end CSTCommandLimitAdd%3DE1F6F20069.postscript

//## begin CSTCommandLimitConfig%3DE1F764001B.preface preserve=yes
//## end CSTCommandLimitConfig%3DE1F764001B.preface

//## Class: CSTCommandLimitConfig%3DE1F764001B
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandLimitConfig : public CSTCommand  //## Inherits: <unnamed>%3DE1F77203B5
{
  //## begin CSTCommandLimitConfig%3DE1F764001B.initialDeclarations preserve=yes
  //## end CSTCommandLimitConfig%3DE1F764001B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandLimitConfig%1038217283
      CSTCommandLimitConfig (ICOStateMachineContext* p_pContext, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction, CPIObjIdentification* p_pSensor);

    //## Destructor (generated)
      virtual ~CSTCommandLimitConfig();


    //## Other Operations (specified)
      //## Operation: Execute%1038217284
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandLimitConfig%3DE1F764001B.public preserve=yes
      //## end CSTCommandLimitConfig%3DE1F764001B.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandLimitConfig%3DE1F764001B.protected preserve=yes
      //## end CSTCommandLimitConfig%3DE1F764001B.protected

  private:
    //## Constructors (generated)
      CSTCommandLimitConfig();

      CSTCommandLimitConfig(const CSTCommandLimitConfig &right);

    //## Assignment Operation (generated)
      const CSTCommandLimitConfig & operator=(const CSTCommandLimitConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandLimitConfig &right) const;

      bool operator!=(const CSTCommandLimitConfig &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE46E540038
      //## Role: CSTCommandLimitConfig::eLimitCharacteristics%3DE46E540356
      //## begin CSTCommandLimitConfig::eLimitCharacteristics%3DE46E540356.role preserve=no  public: EPILimitCharacteristics {1..1 -> 1..1VFHN}
      EPILimitCharacteristics m_eLimitCharacteristics;
      //## end CSTCommandLimitConfig::eLimitCharacteristics%3DE46E540356.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE46E570345
      //## Role: CSTCommandLimitConfig::eLimitAction%3DE46E58021D
      //## begin CSTCommandLimitConfig::eLimitAction%3DE46E58021D.role preserve=no  public: EPILimitAction {1..1 -> 1..1VFHN}
      EPILimitAction m_eLimitAction;
      //## end CSTCommandLimitConfig::eLimitAction%3DE46E58021D.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE46E5A0384
      //## Role: CSTCommandLimitConfig::pSensor%3DE46E5B022D
      //## begin CSTCommandLimitConfig::pSensor%3DE46E5B022D.role preserve=no  public: CPIObjIdentification {1..1 -> 1..1RFHN}
      CPIObjIdentification *m_pSensor;
      //## end CSTCommandLimitConfig::pSensor%3DE46E5B022D.role

    // Additional Private Declarations
      //## begin CSTCommandLimitConfig%3DE1F764001B.private preserve=yes
      //## end CSTCommandLimitConfig%3DE1F764001B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandLimitConfig%3DE1F764001B.implementation preserve=yes
      //## end CSTCommandLimitConfig%3DE1F764001B.implementation

};

//## begin CSTCommandLimitConfig%3DE1F764001B.postscript preserve=yes
//## end CSTCommandLimitConfig%3DE1F764001B.postscript

//## begin CSTCommandLimitActivate%3DE1F833003B.preface preserve=yes
//## end CSTCommandLimitActivate%3DE1F833003B.preface

//## Class: CSTCommandLimitActivate%3DE1F833003B
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandLimitActivate : public CSTCommand  //## Inherits: <unnamed>%3DE1F84503E4
{
  //## begin CSTCommandLimitActivate%3DE1F833003B.initialDeclarations preserve=yes
  //## end CSTCommandLimitActivate%3DE1F833003B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandLimitActivate%1038217285
      CSTCommandLimitActivate (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSTCommandLimitActivate();


    //## Other Operations (specified)
      //## Operation: Execute%1038217286
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandLimitActivate%3DE1F833003B.public preserve=yes
      //## end CSTCommandLimitActivate%3DE1F833003B.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandLimitActivate%3DE1F833003B.protected preserve=yes
      //## end CSTCommandLimitActivate%3DE1F833003B.protected

  private:
    //## Constructors (generated)
      CSTCommandLimitActivate();

      CSTCommandLimitActivate(const CSTCommandLimitActivate &right);

    //## Assignment Operation (generated)
      const CSTCommandLimitActivate & operator=(const CSTCommandLimitActivate &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandLimitActivate &right) const;

      bool operator!=(const CSTCommandLimitActivate &right) const;

    // Additional Private Declarations
      //## begin CSTCommandLimitActivate%3DE1F833003B.private preserve=yes
      //## end CSTCommandLimitActivate%3DE1F833003B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandLimitActivate%3DE1F833003B.implementation preserve=yes
      //## end CSTCommandLimitActivate%3DE1F833003B.implementation

};

//## begin CSTCommandLimitActivate%3DE1F833003B.postscript preserve=yes
//## end CSTCommandLimitActivate%3DE1F833003B.postscript

//## begin CSTCommandLimitDeactivate%3DE1F8AE01C1.preface preserve=yes
//## end CSTCommandLimitDeactivate%3DE1F8AE01C1.preface

//## Class: CSTCommandLimitDeactivate%3DE1F8AE01C1
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandLimitDeactivate : public CSTCommand  //## Inherits: <unnamed>%3DE1F8C40069
{
  //## begin CSTCommandLimitDeactivate%3DE1F8AE01C1.initialDeclarations preserve=yes
  //## end CSTCommandLimitDeactivate%3DE1F8AE01C1.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandLimitDeactivate%1038217287
      CSTCommandLimitDeactivate (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSTCommandLimitDeactivate();


    //## Other Operations (specified)
      //## Operation: Execute%1038217288
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandLimitDeactivate%3DE1F8AE01C1.public preserve=yes
      //## end CSTCommandLimitDeactivate%3DE1F8AE01C1.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandLimitDeactivate%3DE1F8AE01C1.protected preserve=yes
      //## end CSTCommandLimitDeactivate%3DE1F8AE01C1.protected

  private:
    //## Constructors (generated)
      CSTCommandLimitDeactivate();

      CSTCommandLimitDeactivate(const CSTCommandLimitDeactivate &right);

    //## Assignment Operation (generated)
      const CSTCommandLimitDeactivate & operator=(const CSTCommandLimitDeactivate &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandLimitDeactivate &right) const;

      bool operator!=(const CSTCommandLimitDeactivate &right) const;

    // Additional Private Declarations
      //## begin CSTCommandLimitDeactivate%3DE1F8AE01C1.private preserve=yes
      //## end CSTCommandLimitDeactivate%3DE1F8AE01C1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandLimitDeactivate%3DE1F8AE01C1.implementation preserve=yes
      //## end CSTCommandLimitDeactivate%3DE1F8AE01C1.implementation

};

//## begin CSTCommandLimitDeactivate%3DE1F8AE01C1.postscript preserve=yes
//## end CSTCommandLimitDeactivate%3DE1F8AE01C1.postscript

//## begin CSTCommandHome%3DE1F92501D1.preface preserve=yes
//## end CSTCommandHome%3DE1F92501D1.preface

//## Class: CSTCommandHome%3DE1F92501D1
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandHome : public CSTCommand  //## Inherits: <unnamed>%3DE1F93300E6
{
  //## begin CSTCommandHome%3DE1F92501D1.initialDeclarations preserve=yes
  //## end CSTCommandHome%3DE1F92501D1.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandHome%1038217289
      CSTCommandHome (ICOStateMachineContext* p_pContext, const EPIMotorPolarity p_eFastFindingDirection, const bool p_bSearchLimitFromOpposite, CPIObjIdentification* p_pHomeLimitID);

    //## Destructor (generated)
      virtual ~CSTCommandHome();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1193385558
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1038217290
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandHome%3DE1F92501D1.public preserve=yes
      //## end CSTCommandHome%3DE1F92501D1.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandHome%3DE1F92501D1.protected preserve=yes
      //## end CSTCommandHome%3DE1F92501D1.protected

  private:
    //## Constructors (generated)
      CSTCommandHome();

      CSTCommandHome(const CSTCommandHome &right);

    //## Assignment Operation (generated)
      const CSTCommandHome & operator=(const CSTCommandHome &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandHome &right) const;

      bool operator!=(const CSTCommandHome &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3FBCDA0E00B1
      //## Role: CSTCommandHome::eFastFindingDirection%3FBCDA0E0360
      //## begin CSTCommandHome::eFastFindingDirection%3FBCDA0E0360.role preserve=no  public: EPIMotorPolarity {1..1 -> 1..1VFHN}
      EPIMotorPolarity m_eFastFindingDirection;
      //## end CSTCommandHome::eFastFindingDirection%3FBCDA0E0360.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3FBCDA3A012E
      //## Role: CSTCommandHome::pHomeLimitID%3FBCDA3A03BE
      //## begin CSTCommandHome::pHomeLimitID%3FBCDA3A03BE.role preserve=no  public: CPIObjIdentification {1..1 -> 1..1RFHN}
      CPIObjIdentification *m_pHomeLimitID;
      //## end CSTCommandHome::pHomeLimitID%3FBCDA3A03BE.role

      //## Association: EBST (Stepper Motor)::<unnamed>%471CEBC5011B
      //## Role: CSTCommandHome::bSearchLimitFromOpposite%471CEBC602B8
      //## begin CSTCommandHome::bSearchLimitFromOpposite%471CEBC602B8.role preserve=no  public: bool {1..1 -> VFHN}
      bool m_bSearchLimitFromOpposite;
      //## end CSTCommandHome::bSearchLimitFromOpposite%471CEBC602B8.role

    // Additional Private Declarations
      //## begin CSTCommandHome%3DE1F92501D1.private preserve=yes
      //## end CSTCommandHome%3DE1F92501D1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandHome%3DE1F92501D1.implementation preserve=yes
      //## end CSTCommandHome%3DE1F92501D1.implementation

};

//## begin CSTCommandHome%3DE1F92501D1.postscript preserve=yes
//## end CSTCommandHome%3DE1F92501D1.postscript

//## begin CSTCommandHomeSetPosition%3DE1F97A00F6.preface preserve=yes
//## end CSTCommandHomeSetPosition%3DE1F97A00F6.preface

//## Class: CSTCommandHomeSetPosition%3DE1F97A00F6
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandHomeSetPosition : public CSTCommand  //## Inherits: <unnamed>%3DE1F9890319
{
  //## begin CSTCommandHomeSetPosition%3DE1F97A00F6.initialDeclarations preserve=yes
  //## end CSTCommandHomeSetPosition%3DE1F97A00F6.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandHomeSetPosition%1038217291
      CSTCommandHomeSetPosition (ICOStateMachineContext* p_pContext, INT p_iPosition);

    //## Destructor (generated)
      virtual ~CSTCommandHomeSetPosition();


    //## Other Operations (specified)
      //## Operation: Execute%1038217292
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandHomeSetPosition%3DE1F97A00F6.public preserve=yes
      //## end CSTCommandHomeSetPosition%3DE1F97A00F6.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandHomeSetPosition%3DE1F97A00F6.protected preserve=yes
      //## end CSTCommandHomeSetPosition%3DE1F97A00F6.protected

  private:
    //## Constructors (generated)
      CSTCommandHomeSetPosition();

      CSTCommandHomeSetPosition(const CSTCommandHomeSetPosition &right);

    //## Assignment Operation (generated)
      const CSTCommandHomeSetPosition & operator=(const CSTCommandHomeSetPosition &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandHomeSetPosition &right) const;

      bool operator!=(const CSTCommandHomeSetPosition &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3DE476ED026A
      //## Role: CSTCommandHomeSetPosition::iPosition%3DE476EE01AF
      //## begin CSTCommandHomeSetPosition::iPosition%3DE476EE01AF.role preserve=no  public: INT {1..1 -> 1..1VFHN}
      INT m_iPosition;
      //## end CSTCommandHomeSetPosition::iPosition%3DE476EE01AF.role

    // Additional Private Declarations
      //## begin CSTCommandHomeSetPosition%3DE1F97A00F6.private preserve=yes
      //## end CSTCommandHomeSetPosition%3DE1F97A00F6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandHomeSetPosition%3DE1F97A00F6.implementation preserve=yes
      //## end CSTCommandHomeSetPosition%3DE1F97A00F6.implementation

};

//## begin CSTCommandHomeSetPosition%3DE1F97A00F6.postscript preserve=yes
//## end CSTCommandHomeSetPosition%3DE1F97A00F6.postscript

//## begin CSTCommandLimitGetFootPrint%3DE1FA110183.preface preserve=yes
//## end CSTCommandLimitGetFootPrint%3DE1FA110183.preface

//## Class: CSTCommandLimitGetFootPrint%3DE1FA110183
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandLimitGetFootPrint : public CSTCommand  //## Inherits: <unnamed>%3DE1FA280089
{
  //## begin CSTCommandLimitGetFootPrint%3DE1FA110183.initialDeclarations preserve=yes
  //## end CSTCommandLimitGetFootPrint%3DE1FA110183.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandLimitGetFootPrint%1038217293
      CSTCommandLimitGetFootPrint (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSTCommandLimitGetFootPrint();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1038217295
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1038217294
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandLimitGetFootPrint%3DE1FA110183.public preserve=yes
      //## end CSTCommandLimitGetFootPrint%3DE1FA110183.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandLimitGetFootPrint%3DE1FA110183.protected preserve=yes
      //## end CSTCommandLimitGetFootPrint%3DE1FA110183.protected

  private:
    //## Constructors (generated)
      CSTCommandLimitGetFootPrint();

      CSTCommandLimitGetFootPrint(const CSTCommandLimitGetFootPrint &right);

    //## Assignment Operation (generated)
      const CSTCommandLimitGetFootPrint & operator=(const CSTCommandLimitGetFootPrint &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandLimitGetFootPrint &right) const;

      bool operator!=(const CSTCommandLimitGetFootPrint &right) const;

    // Additional Private Declarations
      //## begin CSTCommandLimitGetFootPrint%3DE1FA110183.private preserve=yes
      //## end CSTCommandLimitGetFootPrint%3DE1FA110183.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandLimitGetFootPrint%3DE1FA110183.implementation preserve=yes
      //## end CSTCommandLimitGetFootPrint%3DE1FA110183.implementation

};

//## begin CSTCommandLimitGetFootPrint%3DE1FA110183.postscript preserve=yes
//## end CSTCommandLimitGetFootPrint%3DE1FA110183.postscript

//## begin CSTCommandSetConfig%3E71EC1A0261.preface preserve=yes
//## end CSTCommandSetConfig%3E71EC1A0261.preface

//## Class: CSTCommandSetConfig%3E71EC1A0261
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandSetConfig : public CSTCommand  //## Inherits: <unnamed>%3E71ECAA0176
{
  //## begin CSTCommandSetConfig%3E71EC1A0261.initialDeclarations preserve=yes
  //## end CSTCommandSetConfig%3E71EC1A0261.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandSetConfig%1047647375
      CSTCommandSetConfig (ICOStateMachineContext* p_pContext, CPIStepperMotorConfig* p_pConfig);

    //## Destructor (generated)
      virtual ~CSTCommandSetConfig();


    //## Other Operations (specified)
      //## Operation: Execute%1047647376
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandSetConfig%3E71EC1A0261.public preserve=yes
      //## end CSTCommandSetConfig%3E71EC1A0261.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandSetConfig%3E71EC1A0261.protected preserve=yes
      //## end CSTCommandSetConfig%3E71EC1A0261.protected

  private:
    //## Constructors (generated)
      CSTCommandSetConfig();

      CSTCommandSetConfig(const CSTCommandSetConfig &right);

    //## Assignment Operation (generated)
      const CSTCommandSetConfig & operator=(const CSTCommandSetConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandSetConfig &right) const;

      bool operator!=(const CSTCommandSetConfig &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E71F4970261
      //## Role: CSTCommandSetConfig::pConfig%3E71F498008D
      //## begin CSTCommandSetConfig::pConfig%3E71F498008D.role preserve=no  public: CPIStepperMotorConfig {1..1 -> 1..1RFHN}
      CPIStepperMotorConfig *m_pConfig;
      //## end CSTCommandSetConfig::pConfig%3E71F498008D.role

    // Additional Private Declarations
      //## begin CSTCommandSetConfig%3E71EC1A0261.private preserve=yes
      //## end CSTCommandSetConfig%3E71EC1A0261.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandSetConfig%3E71EC1A0261.implementation preserve=yes
      //## end CSTCommandSetConfig%3E71EC1A0261.implementation

};

//## begin CSTCommandSetConfig%3E71EC1A0261.postscript preserve=yes
//## end CSTCommandSetConfig%3E71EC1A0261.postscript

//## begin CSTCommandOnLimitHit%3E8060F7021B.preface preserve=yes
//## end CSTCommandOnLimitHit%3E8060F7021B.preface

//## Class: CSTCommandOnLimitHit%3E8060F7021B
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandOnLimitHit : public CSTCommand  //## Inherits: <unnamed>%3E80610C019E
{
  //## begin CSTCommandOnLimitHit%3E8060F7021B.initialDeclarations preserve=yes
  //## end CSTCommandOnLimitHit%3E8060F7021B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTCommandOnLimitHit%1048581160
      CSTCommandOnLimitHit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID);

    //## Destructor (generated)
      virtual ~CSTCommandOnLimitHit();


    //## Other Operations (specified)
      //## Operation: Execute%1048581161
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CSTCommandOnLimitHit%3E8060F7021B.public preserve=yes
      //## end CSTCommandOnLimitHit%3E8060F7021B.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandOnLimitHit%3E8060F7021B.protected preserve=yes
      //## end CSTCommandOnLimitHit%3E8060F7021B.protected

  private:
    //## Constructors (generated)
      CSTCommandOnLimitHit();

      CSTCommandOnLimitHit(const CSTCommandOnLimitHit &right);

    //## Assignment Operation (generated)
      const CSTCommandOnLimitHit & operator=(const CSTCommandOnLimitHit &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandOnLimitHit &right) const;

      bool operator!=(const CSTCommandOnLimitHit &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E806EA30075
      //## Role: CSTCommandOnLimitHit::pLimitID%3E806EA302E7
      //## begin CSTCommandOnLimitHit::pLimitID%3E806EA302E7.role preserve=no  public: CPIObjIdentification {1..1 -> 1..1RFHN}
      CPIObjIdentification *m_pLimitID;
      //## end CSTCommandOnLimitHit::pLimitID%3E806EA302E7.role

    // Additional Private Declarations
      //## begin CSTCommandOnLimitHit%3E8060F7021B.private preserve=yes
      //## end CSTCommandOnLimitHit%3E8060F7021B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandOnLimitHit%3E8060F7021B.implementation preserve=yes
      //## end CSTCommandOnLimitHit%3E8060F7021B.implementation

};

//## begin CSTCommandOnLimitHit%3E8060F7021B.postscript preserve=yes
//## end CSTCommandOnLimitHit%3E8060F7021B.postscript

//## begin CSTCcommandConnectionLost%3EE892D80184.preface preserve=yes
//## end CSTCcommandConnectionLost%3EE892D80184.preface

//## Class: CSTCcommandConnectionLost%3EE892D80184
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCcommandConnectionLost : public CSTCommand  //## Inherits: <unnamed>%3EE8930C0201
{
  //## begin CSTCcommandConnectionLost%3EE892D80184.initialDeclarations preserve=yes
  //## end CSTCcommandConnectionLost%3EE892D80184.initialDeclarations

  public:
    //## Destructor (generated)
      virtual ~CSTCcommandConnectionLost();


    //## Other Operations (specified)
      //## Operation: Execute%1055428402
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

      //## Operation: CSTcommandConnectionLost%1055428405
      void CSTcommandConnectionLost (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CSTCcommandConnectionLost%3EE892D80184.public preserve=yes
      //## end CSTCcommandConnectionLost%3EE892D80184.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCcommandConnectionLost%3EE892D80184.protected preserve=yes
      //## end CSTCcommandConnectionLost%3EE892D80184.protected

  private:
    //## Constructors (generated)
      CSTCcommandConnectionLost();

      CSTCcommandConnectionLost(const CSTCcommandConnectionLost &right);

    //## Assignment Operation (generated)
      const CSTCcommandConnectionLost & operator=(const CSTCcommandConnectionLost &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCcommandConnectionLost &right) const;

      bool operator!=(const CSTCcommandConnectionLost &right) const;

    // Additional Private Declarations
      //## begin CSTCcommandConnectionLost%3EE892D80184.private preserve=yes
      //## end CSTCcommandConnectionLost%3EE892D80184.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCcommandConnectionLost%3EE892D80184.implementation preserve=yes
      //## end CSTCcommandConnectionLost%3EE892D80184.implementation

};

//## begin CSTCcommandConnectionLost%3EE892D80184.postscript preserve=yes
//## end CSTCcommandConnectionLost%3EE892D80184.postscript

//## begin CSTCommandConnectionEstablished%3EE89369007A.preface preserve=yes
//## end CSTCommandConnectionEstablished%3EE89369007A.preface

//## Class: CSTCommandConnectionEstablished%3EE89369007A
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSTCommandConnectionEstablished : public CSTCommand  //## Inherits: <unnamed>%3EE89386024F
{
  //## begin CSTCommandConnectionEstablished%3EE89369007A.initialDeclarations preserve=yes
  //## end CSTCommandConnectionEstablished%3EE89369007A.initialDeclarations

  public:
    //## Destructor (generated)
      virtual ~CSTCommandConnectionEstablished();


    //## Other Operations (specified)
      //## Operation: Execute%1055428404
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CSTState* p_pCurrentState);

      //## Operation: CStCommandConnectionEstablished%1055428403
      void CStCommandConnectionEstablished (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CSTCommandConnectionEstablished%3EE89369007A.public preserve=yes
      //## end CSTCommandConnectionEstablished%3EE89369007A.public

  protected:
    // Additional Protected Declarations
      //## begin CSTCommandConnectionEstablished%3EE89369007A.protected preserve=yes
      //## end CSTCommandConnectionEstablished%3EE89369007A.protected

  private:
    //## Constructors (generated)
      CSTCommandConnectionEstablished();

      CSTCommandConnectionEstablished(const CSTCommandConnectionEstablished &right);

    //## Assignment Operation (generated)
      const CSTCommandConnectionEstablished & operator=(const CSTCommandConnectionEstablished &right);

    //## Equality Operations (generated)
      bool operator==(const CSTCommandConnectionEstablished &right) const;

      bool operator!=(const CSTCommandConnectionEstablished &right) const;

    // Additional Private Declarations
      //## begin CSTCommandConnectionEstablished%3EE89369007A.private preserve=yes
      //## end CSTCommandConnectionEstablished%3EE89369007A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTCommandConnectionEstablished%3EE89369007A.implementation preserve=yes
      //## end CSTCommandConnectionEstablished%3EE89369007A.implementation

};

//## begin CSTCommandConnectionEstablished%3EE89369007A.postscript preserve=yes
//## end CSTCommandConnectionEstablished%3EE89369007A.postscript

// Class CSTCommand 

// Class CSTCommandGetPosition 

// Class CSTCommandMoveAbsolute 

// Class CSTCommandMoveRelative 

// Class CSTCommandMoveManual 

// Class CSTCommandStop 

// Class CSTCommandStopImmediately 

// Class CSTCommandSetProfile 

// Class CSTCommandSetSpeed 

// Class CSTCommandLimitAdd 

// Class CSTCommandLimitConfig 

// Class CSTCommandLimitActivate 

// Class CSTCommandLimitDeactivate 

// Class CSTCommandHome 

// Class CSTCommandHomeSetPosition 

// Class CSTCommandLimitGetFootPrint 

// Class CSTCommandSetConfig 

// Class CSTCommandOnLimitHit 

// Class CSTCcommandConnectionLost 

// Class CSTCommandConnectionEstablished 

//## begin module%3DAA5DCF00FC.epilog preserve=yes
//## end module%3DAA5DCF00FC.epilog


#endif
