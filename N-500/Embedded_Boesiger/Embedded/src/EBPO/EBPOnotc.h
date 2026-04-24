//## begin module%3F93ABF403C0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F93ABF403C0.cm

//## begin module%3F93ABF403C0.cp preserve=no
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
//## end module%3F93ABF403C0.cp

//## Module: EBPOnotc%3F93ABF403C0; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOnotc.h

#ifndef EBPOnotc_h
#define EBPOnotc_h 1

//## begin module%3F93ABF403C0.additionalIncludes preserve=no
//## end module%3F93ABF403C0.additionalIncludes

//## begin module%3F93ABF403C0.includes preserve=yes
//## end module%3F93ABF403C0.includes

// EBPOstat
#include "EBPOstat.h"
//## begin module%3F93ABF403C0.declarations preserve=no
//## end module%3F93ABF403C0.declarations

//## begin module%3F93ABF403C0.additionalDeclarations preserve=yes
//## end module%3F93ABF403C0.additionalDeclarations


//## begin CPOStateNotConnected%3F93AEF40258.preface preserve=yes
//## end CPOStateNotConnected%3F93AEF40258.preface

//## Class: CPOStateNotConnected%3F93AEF40258
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F9CF69E01C1;CPOStateIdle { -> }
//## Uses: <unnamed>%3F9CF6EF02EA;CPOStateShuttingDown { -> }
//## Uses: <unnamed>%405AA9030058;CPOLifeTimeCounterHandler { -> }
//## Uses: <unnamed>%405AA93C028A;CPITicksAtStart { -> }

class CPOStateNotConnected : public CPOState  //## Inherits: <unnamed>%3F93CAE6019D
{
  //## begin CPOStateNotConnected%3F93AEF40258.initialDeclarations preserve=yes
  //## end CPOStateNotConnected%3F93AEF40258.initialDeclarations

  public:
    //## Constructors (generated)
      CPOStateNotConnected();

    //## Destructor (generated)
      virtual ~CPOStateNotConnected();


    //## Other Operations (specified)
      //## Operation: Shutdown%1066888972
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: Create%1066889000
      static void Create ();

      //## Operation: Delete%1066889001
      static void Delete ();

      //## Operation: GetInstance%1066889002
      static CPOStateNotConnected * GetInstance ();

      //## Operation: ConnectionEstablished%1067251212
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: Do%1079681378
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
      //## begin CPOStateNotConnected%3F93AEF40258.public preserve=yes
      //## end CPOStateNotConnected%3F93AEF40258.public

  protected:
    // Additional Protected Declarations
      //## begin CPOStateNotConnected%3F93AEF40258.protected preserve=yes
      //## end CPOStateNotConnected%3F93AEF40258.protected

  private:
    //## Constructors (generated)
      CPOStateNotConnected(const CPOStateNotConnected &right);

    //## Assignment Operation (generated)
      const CPOStateNotConnected & operator=(const CPOStateNotConnected &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateNotConnected &right) const;

      bool operator!=(const CPOStateNotConnected &right) const;

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3F97CD74017E
      //## Role: CPOStateNotConnected::pInstance%3F97CD7500F3
      //## begin CPOStateNotConnected::pInstance%3F97CD7500F3.role preserve=no  public: static CPOStateNotConnected {1..1 -> 1..1RFHN}
      static CPOStateNotConnected *m_pInstance;
      //## end CPOStateNotConnected::pInstance%3F97CD7500F3.role

    // Additional Private Declarations
      //## begin CPOStateNotConnected%3F93AEF40258.private preserve=yes
      //## end CPOStateNotConnected%3F93AEF40258.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateNotConnected%3F93AEF40258.implementation preserve=yes
      //## end CPOStateNotConnected%3F93AEF40258.implementation

};

//## begin CPOStateNotConnected%3F93AEF40258.postscript preserve=yes
//## end CPOStateNotConnected%3F93AEF40258.postscript

// Class CPOStateNotConnected 

//## begin module%3F93ABF403C0.epilog preserve=yes
//## end module%3F93ABF403C0.epilog


#endif
