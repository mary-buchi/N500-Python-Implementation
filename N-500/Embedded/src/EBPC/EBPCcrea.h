//## begin module%3EED769F0370.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F0370.cm

//## begin module%3EED769F0370.cp preserve=no
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
//## end module%3EED769F0370.cp

//## Module: EBPCcrea%3EED769F0370; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCcrea.h

#ifndef EBPCcrea_h
#define EBPCcrea_h 1

//## begin module%3EED769F0370.additionalIncludes preserve=no
//## end module%3EED769F0370.additionalIncludes

//## begin module%3EED769F0370.includes preserve=yes
//## end module%3EED769F0370.includes

// EBPIcrea
#include "EBPIcrea.h"
// EBPCstat
#include "EBPCstat.h"
//## begin module%3EED769F0370.declarations preserve=no
//## end module%3EED769F0370.declarations

//## begin module%3EED769F0370.additionalDeclarations preserve=yes
//## end module%3EED769F0370.additionalDeclarations


//## begin CPCPowerControlCreatorV0%3EED76CC02EB.preface preserve=yes
//## end CPCPowerControlCreatorV0%3EED76CC02EB.preface

//## Class: CPCPowerControlCreatorV0%3EED76CC02EB
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EED76CC02F0;CPCPowerControlInterface { -> }

class CPCPowerControlCreatorV0 : public CPIObjCreatorPowerControl  //## Inherits: <unnamed>%3EED76CC02ED
{
  //## begin CPCPowerControlCreatorV0%3EED76CC02EB.initialDeclarations preserve=yes
  //## end CPCPowerControlCreatorV0%3EED76CC02EB.initialDeclarations

  public:
    //## Constructors (generated)
      CPCPowerControlCreatorV0();

    //## Destructor (generated)
      virtual ~CPCPowerControlCreatorV0();


    //## Other Operations (specified)
      //## Operation: Create%1038899301
      virtual IPIPowerControlInterface* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CPCPowerControlCreatorV0%3EED76CC02EB.public preserve=yes
      //## end CPCPowerControlCreatorV0%3EED76CC02EB.public

  protected:
    // Additional Protected Declarations
      //## begin CPCPowerControlCreatorV0%3EED76CC02EB.protected preserve=yes
      //## end CPCPowerControlCreatorV0%3EED76CC02EB.protected

  private:
    //## Constructors (generated)
      CPCPowerControlCreatorV0(const CPCPowerControlCreatorV0 &right);

    //## Assignment Operation (generated)
      const CPCPowerControlCreatorV0 & operator=(const CPCPowerControlCreatorV0 &right);

    //## Equality Operations (generated)
      bool operator==(const CPCPowerControlCreatorV0 &right) const;

      bool operator!=(const CPCPowerControlCreatorV0 &right) const;

    // Additional Private Declarations
      //## begin CPCPowerControlCreatorV0%3EED76CC02EB.private preserve=yes
      //## end CPCPowerControlCreatorV0%3EED76CC02EB.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCPowerControlCreatorV0%3EED76CC02EB.implementation preserve=yes
      //## end CPCPowerControlCreatorV0%3EED76CC02EB.implementation

};

//## begin CPCPowerControlCreatorV0%3EED76CC02EB.postscript preserve=yes
//## end CPCPowerControlCreatorV0%3EED76CC02EB.postscript

//## begin CPCStateCreated%3EED76CC035E.preface preserve=yes
//## end CPCStateCreated%3EED76CC035E.preface

//## Class: CPCStateCreated%3EED76CC035E
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EED76CC0366;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3F8E57EE0341;PC_IDENTIFIERS { -> }
//## Uses: <unnamed>%4027A53A016E;CPCStateConfigNotSet { -> }

class CPCStateCreated : public CPCState  //## Inherits: <unnamed>%3EED76CC0360
{
  //## begin CPCStateCreated%3EED76CC035E.initialDeclarations preserve=yes
  //## end CPCStateCreated%3EED76CC035E.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateCreated();

    //## Destructor (generated)
      virtual ~CPCStateCreated();


    //## Other Operations (specified)
      //## Operation: Create%1038899331
      static void Create ();

      //## Operation: Delete%1044522140
      static void Delete ();

      //## Operation: GetInstance%1038899333
      static CPCStateCreated* GetInstance ();

      //## Operation: Startup%1044629618
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

      //## Operation: ConnectionEstablished%1063223347
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1063223348
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
      //## begin CPCStateCreated%3EED76CC035E.public preserve=yes
      //## end CPCStateCreated%3EED76CC035E.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateCreated%3EED76CC035E.protected preserve=yes
      //## end CPCStateCreated%3EED76CC035E.protected

  private:
    //## Constructors (generated)
      CPCStateCreated(const CPCStateCreated &right);

    //## Assignment Operation (generated)
      const CPCStateCreated & operator=(const CPCStateCreated &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateCreated &right) const;

      bool operator!=(const CPCStateCreated &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%3EED76CC089B
      //## Role: CPCStateCreated::pInstance%3EED76CC08A0
      //## begin CPCStateCreated::pInstance%3EED76CC08A0.role preserve=no  public: static CPCStateCreated {1..1 -> 1..1RFHN}
      static CPCStateCreated *m_pInstance;
      //## end CPCStateCreated::pInstance%3EED76CC08A0.role

    // Additional Private Declarations
      //## begin CPCStateCreated%3EED76CC035E.private preserve=yes
      //## end CPCStateCreated%3EED76CC035E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateCreated%3EED76CC035E.implementation preserve=yes
      //## end CPCStateCreated%3EED76CC035E.implementation

};

//## begin CPCStateCreated%3EED76CC035E.postscript preserve=yes
//## end CPCStateCreated%3EED76CC035E.postscript

// Class CPCPowerControlCreatorV0 

// Class CPCStateCreated 

//## begin module%3EED769F0370.epilog preserve=yes
//## end module%3EED769F0370.epilog


#endif
