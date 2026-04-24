//## begin module%3DE5EB7100A1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EB7100A1.cm

//## begin module%3DE5EB7100A1.cp preserve=no
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
//## end module%3DE5EB7100A1.cp

//## Module: EBPOcomd%3DE5EB7100A1; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOcomd.h

#ifndef EBPOcomd_h
#define EBPOcomd_h 1

//## begin module%3DE5EB7100A1.additionalIncludes preserve=no
//## end module%3DE5EB7100A1.additionalIncludes

//## begin module%3DE5EB7100A1.includes preserve=yes
//## end module%3DE5EB7100A1.includes

// EBCOcomd
#include "EBCOcomd.h"
// EBPItype
#include "EBPItype.h"

class CPOState;

//## begin module%3DE5EB7100A1.declarations preserve=no
//## end module%3DE5EB7100A1.declarations

//## begin module%3DE5EB7100A1.additionalDeclarations preserve=yes
//## end module%3DE5EB7100A1.additionalDeclarations


//## begin CPOCommand%3DECB1FA035E.preface preserve=yes
//## end CPOCommand%3DECB1FA035E.preface

//## Class: CPOCommand%3DECB1FA035E
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DECB3400245;CPOState { -> F}

class CPOCommand : public CCOCommand  //## Inherits: <unnamed>%3DECB2080245
{
  //## begin CPOCommand%3DECB1FA035E.initialDeclarations preserve=yes
  //## end CPOCommand%3DECB1FA035E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOCommand%1038899353
      CPOCommand (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPOCommand();


    //## Other Operations (specified)
      //## Operation: Execute%1038899354
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

      //## Operation: Execute%1038899355
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPOState* p_pCurrentState) = 0;

    // Additional Public Declarations
      //## begin CPOCommand%3DECB1FA035E.public preserve=yes
      //## end CPOCommand%3DECB1FA035E.public

  protected:
    // Additional Protected Declarations
      //## begin CPOCommand%3DECB1FA035E.protected preserve=yes
      //## end CPOCommand%3DECB1FA035E.protected

  private:
    //## Constructors (generated)
      CPOCommand();

      CPOCommand(const CPOCommand &right);

    //## Assignment Operation (generated)
      const CPOCommand & operator=(const CPOCommand &right);

    //## Equality Operations (generated)
      bool operator==(const CPOCommand &right) const;

      bool operator!=(const CPOCommand &right) const;

    // Additional Private Declarations
      //## begin CPOCommand%3DECB1FA035E.private preserve=yes
      //## end CPOCommand%3DECB1FA035E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOCommand%3DECB1FA035E.implementation preserve=yes
      //## end CPOCommand%3DECB1FA035E.implementation

};

//## begin CPOCommand%3DECB1FA035E.postscript preserve=yes
//## end CPOCommand%3DECB1FA035E.postscript

//## begin CPOCommandReadParameters%3DF44C5700C2.preface preserve=yes
//## end CPOCommandReadParameters%3DF44C5700C2.preface

//## Class: CPOCommandReadParameters%3DF44C5700C2
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOCommandReadParameters : public CPOCommand  //## Inherits: <unnamed>%3F964F3D03E3
{
  //## begin CPOCommandReadParameters%3DF44C5700C2.initialDeclarations preserve=yes
  //## end CPOCommandReadParameters%3DF44C5700C2.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOCommandReadParameters%1039418956
      CPOCommandReadParameters (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPOCommandReadParameters();


    //## Other Operations (specified)
      //## Operation: CreateSyncObjects%1039418957
      virtual void CreateSyncObjects ();

      //## Operation: Execute%1039418958
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPOCommandReadParameters%3DF44C5700C2.public preserve=yes
      //## end CPOCommandReadParameters%3DF44C5700C2.public

  protected:
    // Additional Protected Declarations
      //## begin CPOCommandReadParameters%3DF44C5700C2.protected preserve=yes
      //## end CPOCommandReadParameters%3DF44C5700C2.protected

  private:
    //## Constructors (generated)
      CPOCommandReadParameters();

      CPOCommandReadParameters(const CPOCommandReadParameters &right);

    //## Assignment Operation (generated)
      const CPOCommandReadParameters & operator=(const CPOCommandReadParameters &right);

    //## Equality Operations (generated)
      bool operator==(const CPOCommandReadParameters &right) const;

      bool operator!=(const CPOCommandReadParameters &right) const;

    // Additional Private Declarations
      //## begin CPOCommandReadParameters%3DF44C5700C2.private preserve=yes
      //## end CPOCommandReadParameters%3DF44C5700C2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOCommandReadParameters%3DF44C5700C2.implementation preserve=yes
      //## end CPOCommandReadParameters%3DF44C5700C2.implementation

};

//## begin CPOCommandReadParameters%3DF44C5700C2.postscript preserve=yes
//## end CPOCommandReadParameters%3DF44C5700C2.postscript

//## begin CPOCommandWriteParameter%3DF4672D0385.preface preserve=yes
//## end CPOCommandWriteParameter%3DF4672D0385.preface

//## Class: CPOCommandWriteParameter%3DF4672D0385
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOCommandWriteParameter : public CPOCommand  //## Inherits: <unnamed>%3F964F410162
{
  //## begin CPOCommandWriteParameter%3DF4672D0385.initialDeclarations preserve=yes
  //## end CPOCommandWriteParameter%3DF4672D0385.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOCommandWriteParameter%1039418959
      CPOCommandWriteParameter (ICOStateMachineContext *p_pContext, CPIPersistentPara *p_pParameter);

    //## Destructor (generated)
      virtual ~CPOCommandWriteParameter();


    //## Other Operations (specified)
      //## Operation: Execute%1039418960
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPOCommandWriteParameter%3DF4672D0385.public preserve=yes
      //## end CPOCommandWriteParameter%3DF4672D0385.public

  protected:
    // Additional Protected Declarations
      //## begin CPOCommandWriteParameter%3DF4672D0385.protected preserve=yes
      //## end CPOCommandWriteParameter%3DF4672D0385.protected

  private:
    //## Constructors (generated)
      CPOCommandWriteParameter();

      CPOCommandWriteParameter(const CPOCommandWriteParameter &right);

    //## Assignment Operation (generated)
      const CPOCommandWriteParameter & operator=(const CPOCommandWriteParameter &right);

    //## Equality Operations (generated)
      bool operator==(const CPOCommandWriteParameter &right) const;

      bool operator!=(const CPOCommandWriteParameter &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3DF4693D00B7
      //## Role: CPOCommandWriteParameter::pParameter%3DF4693E01FF
      //## begin CPOCommandWriteParameter::pParameter%3DF4693E01FF.role preserve=no  public: CPIPersistentPara {1..1 -> 1..1RFHN}
      CPIPersistentPara *m_pParameter;
      //## end CPOCommandWriteParameter::pParameter%3DF4693E01FF.role

    // Additional Private Declarations
      //## begin CPOCommandWriteParameter%3DF4672D0385.private preserve=yes
      //## end CPOCommandWriteParameter%3DF4672D0385.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOCommandWriteParameter%3DF4672D0385.implementation preserve=yes
      //## end CPOCommandWriteParameter%3DF4672D0385.implementation

};

//## begin CPOCommandWriteParameter%3DF4672D0385.postscript preserve=yes
//## end CPOCommandWriteParameter%3DF4672D0385.postscript

//## begin CPOCommandSetConfig%3F96424A0395.preface preserve=yes
//## end CPOCommandSetConfig%3F96424A0395.preface

//## Class: CPOCommandSetConfig%3F96424A0395
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOCommandSetConfig : public CPOCommand  //## Inherits: <unnamed>%3F964F3B00F5
{
  //## begin CPOCommandSetConfig%3F96424A0395.initialDeclarations preserve=yes
  //## end CPOCommandSetConfig%3F96424A0395.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOCommandSetConfig%1066813276
      CPOCommandSetConfig (ICOStateMachineContext* p_pContext, CPIPersistentConfig* p_pConfig);

    //## Destructor (generated)
      virtual ~CPOCommandSetConfig();


    //## Other Operations (specified)
      //## Operation: Execute%1066813277
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPOCommandSetConfig%3F96424A0395.public preserve=yes
      //## end CPOCommandSetConfig%3F96424A0395.public

  protected:
    // Additional Protected Declarations
      //## begin CPOCommandSetConfig%3F96424A0395.protected preserve=yes
      //## end CPOCommandSetConfig%3F96424A0395.protected

  private:
    //## Constructors (generated)
      CPOCommandSetConfig(const CPOCommandSetConfig &right);

    //## Assignment Operation (generated)
      const CPOCommandSetConfig & operator=(const CPOCommandSetConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CPOCommandSetConfig &right) const;

      bool operator!=(const CPOCommandSetConfig &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%403F1329035B
      //## Role: CPOCommandSetConfig::pConfig%403F132A0197
      //## begin CPOCommandSetConfig::pConfig%403F132A0197.role preserve=no  public: CPIPersistentConfig {1..1 -> 1..1RHN}
      CPIPersistentConfig *m_pConfig;
      //## end CPOCommandSetConfig::pConfig%403F132A0197.role

    // Additional Private Declarations
      //## begin CPOCommandSetConfig%3F96424A0395.private preserve=yes
      //## end CPOCommandSetConfig%3F96424A0395.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOCommandSetConfig%3F96424A0395.implementation preserve=yes
      //## end CPOCommandSetConfig%3F96424A0395.implementation

};

//## begin CPOCommandSetConfig%3F96424A0395.postscript preserve=yes
//## end CPOCommandSetConfig%3F96424A0395.postscript

//## begin CPOCommandReadIdentifications%3F9642E001D0.preface preserve=yes
//## end CPOCommandReadIdentifications%3F9642E001D0.preface

//## Class: CPOCommandReadIdentifications%3F9642E001D0
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOCommandReadIdentifications : public CPOCommand  //## Inherits: <unnamed>%3F964F44021E
{
  //## begin CPOCommandReadIdentifications%3F9642E001D0.initialDeclarations preserve=yes
  //## end CPOCommandReadIdentifications%3F9642E001D0.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOCommandReadIdentifications%1066888952
      CPOCommandReadIdentifications (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPOCommandReadIdentifications();


    //## Other Operations (specified)
      //## Operation: Execute%1066813278
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPOState* p_pCurrentState);

      //## Operation: CreateSyncObjects%1066918323
      virtual void CreateSyncObjects ();

    // Additional Public Declarations
      //## begin CPOCommandReadIdentifications%3F9642E001D0.public preserve=yes
      //## end CPOCommandReadIdentifications%3F9642E001D0.public

  protected:
    // Additional Protected Declarations
      //## begin CPOCommandReadIdentifications%3F9642E001D0.protected preserve=yes
      //## end CPOCommandReadIdentifications%3F9642E001D0.protected

  private:
    //## Constructors (generated)
      CPOCommandReadIdentifications();

      CPOCommandReadIdentifications(const CPOCommandReadIdentifications &right);

    //## Assignment Operation (generated)
      const CPOCommandReadIdentifications & operator=(const CPOCommandReadIdentifications &right);

    //## Equality Operations (generated)
      bool operator==(const CPOCommandReadIdentifications &right) const;

      bool operator!=(const CPOCommandReadIdentifications &right) const;

    // Additional Private Declarations
      //## begin CPOCommandReadIdentifications%3F9642E001D0.private preserve=yes
      //## end CPOCommandReadIdentifications%3F9642E001D0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOCommandReadIdentifications%3F9642E001D0.implementation preserve=yes
      //## end CPOCommandReadIdentifications%3F9642E001D0.implementation

};

//## begin CPOCommandReadIdentifications%3F9642E001D0.postscript preserve=yes
//## end CPOCommandReadIdentifications%3F9642E001D0.postscript

//## begin CPOCommandWriteIdentification%3F96436C0114.preface preserve=yes
//## end CPOCommandWriteIdentification%3F96436C0114.preface

//## Class: CPOCommandWriteIdentification%3F96436C0114
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOCommandWriteIdentification : public CPOCommand  //## Inherits: <unnamed>%3F964F4B0318
{
  //## begin CPOCommandWriteIdentification%3F96436C0114.initialDeclarations preserve=yes
  //## end CPOCommandWriteIdentification%3F96436C0114.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOCommandWriteIdentification%1066888953
      CPOCommandWriteIdentification (ICOStateMachineContext* p_pContext, CPIPersistentIdent* p_pIdentification);

    //## Destructor (generated)
      virtual ~CPOCommandWriteIdentification();


    //## Other Operations (specified)
      //## Operation: Execute%1066813279
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPOCommandWriteIdentification%3F96436C0114.public preserve=yes
      //## end CPOCommandWriteIdentification%3F96436C0114.public

  protected:
    // Additional Protected Declarations
      //## begin CPOCommandWriteIdentification%3F96436C0114.protected preserve=yes
      //## end CPOCommandWriteIdentification%3F96436C0114.protected

  private:
    //## Constructors (generated)
      CPOCommandWriteIdentification(const CPOCommandWriteIdentification &right);

    //## Assignment Operation (generated)
      const CPOCommandWriteIdentification & operator=(const CPOCommandWriteIdentification &right);

    //## Equality Operations (generated)
      bool operator==(const CPOCommandWriteIdentification &right) const;

      bool operator!=(const CPOCommandWriteIdentification &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97707603D8
      //## Role: CPOCommandWriteIdentification::pIdentification%3F9770770158
      //## begin CPOCommandWriteIdentification::pIdentification%3F9770770158.role preserve=no  public: CPIPersistentIdent {1..1 -> 1..1RFHN}
      CPIPersistentIdent *m_pIdentification;
      //## end CPOCommandWriteIdentification::pIdentification%3F9770770158.role

    // Additional Private Declarations
      //## begin CPOCommandWriteIdentification%3F96436C0114.private preserve=yes
      //## end CPOCommandWriteIdentification%3F96436C0114.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOCommandWriteIdentification%3F96436C0114.implementation preserve=yes
      //## end CPOCommandWriteIdentification%3F96436C0114.implementation

};

//## begin CPOCommandWriteIdentification%3F96436C0114.postscript preserve=yes
//## end CPOCommandWriteIdentification%3F96436C0114.postscript

//## begin CPOCommandReadLifeTimeCounter%3F96438B01C0.preface preserve=yes
//## end CPOCommandReadLifeTimeCounter%3F96438B01C0.preface

//## Class: CPOCommandReadLifeTimeCounter%3F96438B01C0
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOCommandReadLifeTimeCounter : public CPOCommand  //## Inherits: <unnamed>%3F964F4E00A7
{
  //## begin CPOCommandReadLifeTimeCounter%3F96438B01C0.initialDeclarations preserve=yes
  //## end CPOCommandReadLifeTimeCounter%3F96438B01C0.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOCommandReadLifeTimeCounter%1066888954
      CPOCommandReadLifeTimeCounter (ICOStateMachineContext* p_pContext, EPILifeTimeCounter p_eCounter);

    //## Destructor (generated)
      virtual ~CPOCommandReadLifeTimeCounter();


    //## Other Operations (specified)
      //## Operation: Execute%1066813280
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPOState* p_pCurrentState);

      //## Operation: CreateSyncObjects%1066918324
      virtual void CreateSyncObjects ();

    // Additional Public Declarations
      //## begin CPOCommandReadLifeTimeCounter%3F96438B01C0.public preserve=yes
      //## end CPOCommandReadLifeTimeCounter%3F96438B01C0.public

  protected:
    // Additional Protected Declarations
      //## begin CPOCommandReadLifeTimeCounter%3F96438B01C0.protected preserve=yes
      //## end CPOCommandReadLifeTimeCounter%3F96438B01C0.protected

  private:
    //## Constructors (generated)
      CPOCommandReadLifeTimeCounter();

      CPOCommandReadLifeTimeCounter(const CPOCommandReadLifeTimeCounter &right);

    //## Assignment Operation (generated)
      const CPOCommandReadLifeTimeCounter & operator=(const CPOCommandReadLifeTimeCounter &right);

    //## Equality Operations (generated)
      bool operator==(const CPOCommandReadLifeTimeCounter &right) const;

      bool operator!=(const CPOCommandReadLifeTimeCounter &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97F15F03C0
      //## Role: CPOCommandReadLifeTimeCounter::eCounter%3F97F1600325
      //## begin CPOCommandReadLifeTimeCounter::eCounter%3F97F1600325.role preserve=no  public: EPILifeTimeCounter {1..1 -> 1..1VFHN}
      EPILifeTimeCounter m_eCounter;
      //## end CPOCommandReadLifeTimeCounter::eCounter%3F97F1600325.role

    // Additional Private Declarations
      //## begin CPOCommandReadLifeTimeCounter%3F96438B01C0.private preserve=yes
      //## end CPOCommandReadLifeTimeCounter%3F96438B01C0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOCommandReadLifeTimeCounter%3F96438B01C0.implementation preserve=yes
      //## end CPOCommandReadLifeTimeCounter%3F96438B01C0.implementation

};

//## begin CPOCommandReadLifeTimeCounter%3F96438B01C0.postscript preserve=yes
//## end CPOCommandReadLifeTimeCounter%3F96438B01C0.postscript

//## begin CPOCommandWriteLifeTimeCounter%3F9643D0022D.preface preserve=yes
//## end CPOCommandWriteLifeTimeCounter%3F9643D0022D.preface

//## Class: CPOCommandWriteLifeTimeCounter%3F9643D0022D
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOCommandWriteLifeTimeCounter : public CPOCommand  //## Inherits: <unnamed>%3F964F51000A
{
  //## begin CPOCommandWriteLifeTimeCounter%3F9643D0022D.initialDeclarations preserve=yes
  //## end CPOCommandWriteLifeTimeCounter%3F9643D0022D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOCommandWriteLifeTimeCounter%1066888958
      CPOCommandWriteLifeTimeCounter (ICOStateMachineContext* p_pContext, EPILifeTimeCounter p_eCounter, UINT p_uiValue);

    //## Destructor (generated)
      virtual ~CPOCommandWriteLifeTimeCounter();


    //## Other Operations (specified)
      //## Operation: Execute%1066813284
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPOCommandWriteLifeTimeCounter%3F9643D0022D.public preserve=yes
      //## end CPOCommandWriteLifeTimeCounter%3F9643D0022D.public

  protected:
    // Additional Protected Declarations
      //## begin CPOCommandWriteLifeTimeCounter%3F9643D0022D.protected preserve=yes
      //## end CPOCommandWriteLifeTimeCounter%3F9643D0022D.protected

  private:
    //## Constructors (generated)
      CPOCommandWriteLifeTimeCounter();

      CPOCommandWriteLifeTimeCounter(const CPOCommandWriteLifeTimeCounter &right);

    //## Assignment Operation (generated)
      const CPOCommandWriteLifeTimeCounter & operator=(const CPOCommandWriteLifeTimeCounter &right);

    //## Equality Operations (generated)
      bool operator==(const CPOCommandWriteLifeTimeCounter &right) const;

      bool operator!=(const CPOCommandWriteLifeTimeCounter &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F9778E401F4
      //## Role: CPOCommandWriteLifeTimeCounter::uiValue%3F9778E5005E
      //## begin CPOCommandWriteLifeTimeCounter::uiValue%3F9778E5005E.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiValue;
      //## end CPOCommandWriteLifeTimeCounter::uiValue%3F9778E5005E.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97E70002F5
      //## Role: CPOCommandWriteLifeTimeCounter::eCounter%3F97E701018F
      //## begin CPOCommandWriteLifeTimeCounter::eCounter%3F97E701018F.role preserve=no  public: EPILifeTimeCounter {1..1 -> 1..1VFHN}
      EPILifeTimeCounter m_eCounter;
      //## end CPOCommandWriteLifeTimeCounter::eCounter%3F97E701018F.role

    // Additional Private Declarations
      //## begin CPOCommandWriteLifeTimeCounter%3F9643D0022D.private preserve=yes
      //## end CPOCommandWriteLifeTimeCounter%3F9643D0022D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOCommandWriteLifeTimeCounter%3F9643D0022D.implementation preserve=yes
      //## end CPOCommandWriteLifeTimeCounter%3F9643D0022D.implementation

};

//## begin CPOCommandWriteLifeTimeCounter%3F9643D0022D.postscript preserve=yes
//## end CPOCommandWriteLifeTimeCounter%3F9643D0022D.postscript

//## begin CPOCommandStartMonitoring%3F96454C01DF.preface preserve=yes
//## end CPOCommandStartMonitoring%3F96454C01DF.preface

//## Class: CPOCommandStartMonitoring%3F96454C01DF
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOCommandStartMonitoring : public CPOCommand  //## Inherits: <unnamed>%3F964F560039
{
  //## begin CPOCommandStartMonitoring%3F96454C01DF.initialDeclarations preserve=yes
  //## end CPOCommandStartMonitoring%3F96454C01DF.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOCommandStartMonitoring%1066888957
      CPOCommandStartMonitoring (ICOStateMachineContext* p_pContext, EPILifeTimeCounter p_eCounter);

    //## Destructor (generated)
      virtual ~CPOCommandStartMonitoring();


    //## Other Operations (specified)
      //## Operation: Execute%1066813283
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPOCommandStartMonitoring%3F96454C01DF.public preserve=yes
      //## end CPOCommandStartMonitoring%3F96454C01DF.public

  protected:
    // Additional Protected Declarations
      //## begin CPOCommandStartMonitoring%3F96454C01DF.protected preserve=yes
      //## end CPOCommandStartMonitoring%3F96454C01DF.protected

  private:
    //## Constructors (generated)
      CPOCommandStartMonitoring();

      CPOCommandStartMonitoring(const CPOCommandStartMonitoring &right);

    //## Assignment Operation (generated)
      const CPOCommandStartMonitoring & operator=(const CPOCommandStartMonitoring &right);

    //## Equality Operations (generated)
      bool operator==(const CPOCommandStartMonitoring &right) const;

      bool operator!=(const CPOCommandStartMonitoring &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97E4EB0382
      //## Role: CPOCommandStartMonitoring::eCounter%3F97E4EC03E1
      //## begin CPOCommandStartMonitoring::eCounter%3F97E4EC03E1.role preserve=no  public: EPILifeTimeCounter {1..1 -> 1..1VFHN}
      EPILifeTimeCounter m_eCounter;
      //## end CPOCommandStartMonitoring::eCounter%3F97E4EC03E1.role

    // Additional Private Declarations
      //## begin CPOCommandStartMonitoring%3F96454C01DF.private preserve=yes
      //## end CPOCommandStartMonitoring%3F96454C01DF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOCommandStartMonitoring%3F96454C01DF.implementation preserve=yes
      //## end CPOCommandStartMonitoring%3F96454C01DF.implementation

};

//## begin CPOCommandStartMonitoring%3F96454C01DF.postscript preserve=yes
//## end CPOCommandStartMonitoring%3F96454C01DF.postscript

//## begin CPOCommandStopMonitoring%3F96455800D6.preface preserve=yes
//## end CPOCommandStopMonitoring%3F96455800D6.preface

//## Class: CPOCommandStopMonitoring%3F96455800D6
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOCommandStopMonitoring : public CPOCommand  //## Inherits: <unnamed>%3F964F5800C6
{
  //## begin CPOCommandStopMonitoring%3F96455800D6.initialDeclarations preserve=yes
  //## end CPOCommandStopMonitoring%3F96455800D6.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOCommandStopMonitoring%1066888956
      CPOCommandStopMonitoring (ICOStateMachineContext* p_pContext, EPILifeTimeCounter p_eCounter);

    //## Destructor (generated)
      virtual ~CPOCommandStopMonitoring();


    //## Other Operations (specified)
      //## Operation: Execute%1066813282
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPOCommandStopMonitoring%3F96455800D6.public preserve=yes
      //## end CPOCommandStopMonitoring%3F96455800D6.public

  protected:
    // Additional Protected Declarations
      //## begin CPOCommandStopMonitoring%3F96455800D6.protected preserve=yes
      //## end CPOCommandStopMonitoring%3F96455800D6.protected

  private:
    //## Constructors (generated)
      CPOCommandStopMonitoring();

      CPOCommandStopMonitoring(const CPOCommandStopMonitoring &right);

    //## Assignment Operation (generated)
      const CPOCommandStopMonitoring & operator=(const CPOCommandStopMonitoring &right);

    //## Equality Operations (generated)
      bool operator==(const CPOCommandStopMonitoring &right) const;

      bool operator!=(const CPOCommandStopMonitoring &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97E4F402E6
      //## Role: CPOCommandStopMonitoring::eCounter%3F97E4F501AE
      //## begin CPOCommandStopMonitoring::eCounter%3F97E4F501AE.role preserve=no  public: EPILifeTimeCounter {1..1 -> 1..1VFHN}
      EPILifeTimeCounter m_eCounter;
      //## end CPOCommandStopMonitoring::eCounter%3F97E4F501AE.role

    // Additional Private Declarations
      //## begin CPOCommandStopMonitoring%3F96455800D6.private preserve=yes
      //## end CPOCommandStopMonitoring%3F96455800D6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOCommandStopMonitoring%3F96455800D6.implementation preserve=yes
      //## end CPOCommandStopMonitoring%3F96455800D6.implementation

};

//## begin CPOCommandStopMonitoring%3F96455800D6.postscript preserve=yes
//## end CPOCommandStopMonitoring%3F96455800D6.postscript

//## begin CPOCommandSave%3F96458D01FE.preface preserve=yes
//## end CPOCommandSave%3F96458D01FE.preface

//## Class: CPOCommandSave%3F96458D01FE
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOCommandSave : public CPOCommand  //## Inherits: <unnamed>%3F964F5B029B
{
  //## begin CPOCommandSave%3F96458D01FE.initialDeclarations preserve=yes
  //## end CPOCommandSave%3F96458D01FE.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOCommandSave%1066888955
      CPOCommandSave (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPOCommandSave();


    //## Other Operations (specified)
      //## Operation: Execute%1066813281
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPOCommandSave%3F96458D01FE.public preserve=yes
      //## end CPOCommandSave%3F96458D01FE.public

  protected:
    // Additional Protected Declarations
      //## begin CPOCommandSave%3F96458D01FE.protected preserve=yes
      //## end CPOCommandSave%3F96458D01FE.protected

  private:
    //## Constructors (generated)
      CPOCommandSave();

      CPOCommandSave(const CPOCommandSave &right);

    //## Assignment Operation (generated)
      const CPOCommandSave & operator=(const CPOCommandSave &right);

    //## Equality Operations (generated)
      bool operator==(const CPOCommandSave &right) const;

      bool operator!=(const CPOCommandSave &right) const;

    // Additional Private Declarations
      //## begin CPOCommandSave%3F96458D01FE.private preserve=yes
      //## end CPOCommandSave%3F96458D01FE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOCommandSave%3F96458D01FE.implementation preserve=yes
      //## end CPOCommandSave%3F96458D01FE.implementation

};

//## begin CPOCommandSave%3F96458D01FE.postscript preserve=yes
//## end CPOCommandSave%3F96458D01FE.postscript

//## begin CPOCommandReset%3FF17A45017C.preface preserve=yes
//## end CPOCommandReset%3FF17A45017C.preface

//## Class: CPOCommandReset%3FF17A45017C
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOCommandReset : public CPOCommand  //## Inherits: <unnamed>%3FF17A5E0360
{
  //## begin CPOCommandReset%3FF17A45017C.initialDeclarations preserve=yes
  //## end CPOCommandReset%3FF17A45017C.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOCommandReset%1072788294
      CPOCommandReset (ICOStateMachineContext* p_pContext, EPIEpromSection p_eSection);

    //## Destructor (generated)
      virtual ~CPOCommandReset();


    //## Other Operations (specified)
      //## Operation: Execute%1072788297
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPOCommandReset%3FF17A45017C.public preserve=yes
      //## end CPOCommandReset%3FF17A45017C.public

  protected:
    // Additional Protected Declarations
      //## begin CPOCommandReset%3FF17A45017C.protected preserve=yes
      //## end CPOCommandReset%3FF17A45017C.protected

  private:
    //## Constructors (generated)
      CPOCommandReset();

      CPOCommandReset(const CPOCommandReset &right);

    //## Assignment Operation (generated)
      const CPOCommandReset & operator=(const CPOCommandReset &right);

    //## Equality Operations (generated)
      bool operator==(const CPOCommandReset &right) const;

      bool operator!=(const CPOCommandReset &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3FF17AB50341
      //## Role: CPOCommandReset::eSection%3FF17AB6013E
      //## begin CPOCommandReset::eSection%3FF17AB6013E.role preserve=no  public: EPIEpromSection {1..1 -> 1..1VFHN}
      EPIEpromSection m_eSection;
      //## end CPOCommandReset::eSection%3FF17AB6013E.role

    // Additional Private Declarations
      //## begin CPOCommandReset%3FF17A45017C.private preserve=yes
      //## end CPOCommandReset%3FF17A45017C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOCommandReset%3FF17A45017C.implementation preserve=yes
      //## end CPOCommandReset%3FF17A45017C.implementation

};

//## begin CPOCommandReset%3FF17A45017C.postscript preserve=yes
//## end CPOCommandReset%3FF17A45017C.postscript

//## begin CPOCommandMeasurementCellUndocked%4061AEC801F4.preface preserve=yes
//## end CPOCommandMeasurementCellUndocked%4061AEC801F4.preface

//## Class: CPOCommandMeasurementCellUndocked%4061AEC801F4
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPOCommandMeasurementCellUndocked : public CPOCommand  //## Inherits: <unnamed>%4061AEE30167
{
  //## begin CPOCommandMeasurementCellUndocked%4061AEC801F4.initialDeclarations preserve=yes
  //## end CPOCommandMeasurementCellUndocked%4061AEC801F4.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOCommandMeasurementCellUndocked%1080142973
      CPOCommandMeasurementCellUndocked (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPOCommandMeasurementCellUndocked();


    //## Other Operations (specified)
      //## Operation: Execute%1080142974
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	Pointer to the current State
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute (CPOState* p_pCurrentState);

    // Additional Public Declarations
      //## begin CPOCommandMeasurementCellUndocked%4061AEC801F4.public preserve=yes
      //## end CPOCommandMeasurementCellUndocked%4061AEC801F4.public

  protected:
    // Additional Protected Declarations
      //## begin CPOCommandMeasurementCellUndocked%4061AEC801F4.protected preserve=yes
      //## end CPOCommandMeasurementCellUndocked%4061AEC801F4.protected

  private:
    //## Constructors (generated)
      CPOCommandMeasurementCellUndocked();

      CPOCommandMeasurementCellUndocked(const CPOCommandMeasurementCellUndocked &right);

    //## Assignment Operation (generated)
      const CPOCommandMeasurementCellUndocked & operator=(const CPOCommandMeasurementCellUndocked &right);

    //## Equality Operations (generated)
      bool operator==(const CPOCommandMeasurementCellUndocked &right) const;

      bool operator!=(const CPOCommandMeasurementCellUndocked &right) const;

    // Additional Private Declarations
      //## begin CPOCommandMeasurementCellUndocked%4061AEC801F4.private preserve=yes
      //## end CPOCommandMeasurementCellUndocked%4061AEC801F4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOCommandMeasurementCellUndocked%4061AEC801F4.implementation preserve=yes
      //## end CPOCommandMeasurementCellUndocked%4061AEC801F4.implementation

};

//## begin CPOCommandMeasurementCellUndocked%4061AEC801F4.postscript preserve=yes
//## end CPOCommandMeasurementCellUndocked%4061AEC801F4.postscript

// Class CPOCommand 

// Class CPOCommandReadParameters 

// Class CPOCommandWriteParameter 

// Class CPOCommandSetConfig 

// Class CPOCommandReadIdentifications 

// Class CPOCommandWriteIdentification 

// Class CPOCommandReadLifeTimeCounter 

// Class CPOCommandWriteLifeTimeCounter 

// Class CPOCommandStartMonitoring 

// Class CPOCommandStopMonitoring 

// Class CPOCommandSave 

// Class CPOCommandReset 

// Class CPOCommandMeasurementCellUndocked 

//## begin module%3DE5EB7100A1.epilog preserve=yes
//## end module%3DE5EB7100A1.epilog


#endif
