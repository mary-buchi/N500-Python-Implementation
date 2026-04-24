//## begin module%3DD1046603CA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD1046603CA.cm

//## begin module%3DD1046603CA.cp preserve=no
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
//## end module%3DD1046603CA.cp

//## Module: EBWCidle%3DD1046603CA; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCidle.h

#ifndef EBWCidle_h
#define EBWCidle_h 1

//## begin module%3DD1046603CA.additionalIncludes preserve=no
//## end module%3DD1046603CA.additionalIncludes

//## begin module%3DD1046603CA.includes preserve=yes
//## end module%3DD1046603CA.includes

// EBWCstat
#include "EBWCstat.h"
//## begin module%3DD1046603CA.declarations preserve=no
//## end module%3DD1046603CA.declarations

//## begin module%3DD1046603CA.additionalDeclarations preserve=yes
//## end module%3DD1046603CA.additionalDeclarations


//## begin CWCStateCreated%3DD10496013A.preface preserve=yes
//## end CWCStateCreated%3DD10496013A.preface

//## Class: CWCStateCreated%3DD10496013A
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DE1D34B0371;CWCCommandSetConfiguration { -> }
//## Uses: <unnamed>%3DE1D3520267;CWCCommandStop { -> }
//## Uses: <unnamed>%3E393AC802FD;CWCStateConfigNotAssign { -> }
//## Uses: <unnamed>%3E393AE703B9;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3FBDE1F900BB;WC_IDENTIFIERS { -> }

class CWCStateCreated : public CWCState  //## Inherits: <unnamed>%3DD104BF02FF
{
  //## begin CWCStateCreated%3DD10496013A.initialDeclarations preserve=yes
  //## end CWCStateCreated%3DD10496013A.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateCreated();

    //## Destructor (generated)
      virtual ~CWCStateCreated();


    //## Other Operations (specified)
      //## Operation: Create%1037094246
      static void Create ();

      //## Operation: Delete%1037094247
      static void Delete ();

      //## Operation: GetInstance%1037094248
      static CWCStateCreated* GetInstance ();

      //## Operation: Startup%1037094249
      //	DESCRIPTION
      //	Brings the subsystem up to the state "WCConfigNotAssign"
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Startup (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1037094250
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionEstablished%1063223351
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1063223352
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
      //## begin CWCStateCreated%3DD10496013A.public preserve=yes
      //## end CWCStateCreated%3DD10496013A.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateCreated%3DD10496013A.protected preserve=yes
      //## end CWCStateCreated%3DD10496013A.protected

  private:
    //## Constructors (generated)
      CWCStateCreated(const CWCStateCreated &right);

    //## Assignment Operation (generated)
      const CWCStateCreated & operator=(const CWCStateCreated &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateCreated &right) const;

      bool operator!=(const CWCStateCreated &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3DD104D101B7
      //## Role: CWCStateCreated::pInstance%3DD104D500AF
      //## begin CWCStateCreated::pInstance%3DD104D500AF.role preserve=no  public: static CWCStateCreated {1..1 -> 1..1RFHN}
      static CWCStateCreated *m_pInstance;
      //## end CWCStateCreated::pInstance%3DD104D500AF.role

    // Additional Private Declarations
      //## begin CWCStateCreated%3DD10496013A.private preserve=yes
      //## end CWCStateCreated%3DD10496013A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateCreated%3DD10496013A.implementation preserve=yes
      //## end CWCStateCreated%3DD10496013A.implementation

};

//## begin CWCStateCreated%3DD10496013A.postscript preserve=yes
//## end CWCStateCreated%3DD10496013A.postscript

// Class CWCStateCreated 

//## begin module%3DD1046603CA.epilog preserve=yes
//## end module%3DD1046603CA.epilog


#endif
