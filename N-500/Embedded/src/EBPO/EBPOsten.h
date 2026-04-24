//## begin module%3DE5EB5D01D9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EB5D01D9.cm

//## begin module%3DE5EB5D01D9.cp preserve=no
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
//## end module%3DE5EB5D01D9.cp

//## Module: EBPOsten%3DE5EB5D01D9; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOsten.h

#ifndef EBPOsten_h
#define EBPOsten_h 1

//## begin module%3DE5EB5D01D9.additionalIncludes preserve=no
//## end module%3DE5EB5D01D9.additionalIncludes

//## begin module%3DE5EB5D01D9.includes preserve=yes
//## end module%3DE5EB5D01D9.includes

// EBCOimct
#include "EBCOimct.h"
//## begin module%3DE5EB5D01D9.declarations preserve=no
//## end module%3DE5EB5D01D9.declarations

//## begin module%3DE5EB5D01D9.additionalDeclarations preserve=yes
//## end module%3DE5EB5D01D9.additionalDeclarations


//## begin CPOStateMachineEngine%3DE636EE02D3.preface preserve=yes
//## end CPOStateMachineEngine%3DE636EE02D3.preface

//## Class: CPOStateMachineEngine%3DE636EE02D3
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DE64062015C;CPOStateCreated { -> }
//## Uses: <unnamed>%3F990D8B0162;CPOStateIdle { -> }
//## Uses: <unnamed>%3F990E72028B;CPOStateStore { -> }
//## Uses: <unnamed>%3F990E890317;CPOStateNotConnected { -> }
//## Uses: <unnamed>%3F990EC10049;CPOStateConfig { -> }
//## Uses: <unnamed>%3F990ED2029A;CPOStateShuttingDown { -> }
//## Uses: <unnamed>%3FA1202A02FD;CPOStateLifeTimeCounter { -> }

class CPOStateMachineEngine : public CCOStateMachineEngine  //## Inherits: <unnamed>%3DE6372B036F
{
  //## begin CPOStateMachineEngine%3DE636EE02D3.initialDeclarations preserve=yes
  //## end CPOStateMachineEngine%3DE636EE02D3.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOStateMachineEngine%1038495073
      CPOStateMachineEngine (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPOStateMachineEngine();


    //## Other Operations (specified)
      //## Operation: BuildStateMachine%1038495058
      //	DESCRIPTION
      //	Builds up the entire state machine.
      //
      //	RETURNS
      //	void
      static void BuildStateMachine ();

      //## Operation: DeleteStateMachine%1038495057
      //	DESCRIPTION
      //	Cleans up the entire state machine.
      //
      //	RETURNS
      //	void
      static void DeleteStateMachine ();

    // Additional Public Declarations
      //## begin CPOStateMachineEngine%3DE636EE02D3.public preserve=yes
      //## end CPOStateMachineEngine%3DE636EE02D3.public

  protected:

    //## Other Operations (specified)
      //## Operation: GetInitializeState%1042097145
      //	DESCRIPTION
      //	Gets the initialize state
      //
      //	RETURNS
      //	Pointer to initial state
      virtual CCOState* GetInitializeState ();

      //## Operation: CreateActions%1038495059
      //	DESCRIPTION
      //	Creates all existing actions and places them into the
      //	array of actions.
      //
      //	PARAMETER
      //	Action pointer List
      //
      //	RETURNS
      //	void
      virtual void CreateActions (CTypedPtrList<CPtrList, CCOAction*>& p_ActionList);

    // Additional Protected Declarations
      //## begin CPOStateMachineEngine%3DE636EE02D3.protected preserve=yes
      //## end CPOStateMachineEngine%3DE636EE02D3.protected

  private:
    //## Constructors (generated)
      CPOStateMachineEngine();

      CPOStateMachineEngine(const CPOStateMachineEngine &right);

    //## Assignment Operation (generated)
      const CPOStateMachineEngine & operator=(const CPOStateMachineEngine &right);

    //## Equality Operations (generated)
      bool operator==(const CPOStateMachineEngine &right) const;

      bool operator!=(const CPOStateMachineEngine &right) const;

    // Additional Private Declarations
      //## begin CPOStateMachineEngine%3DE636EE02D3.private preserve=yes
      //## end CPOStateMachineEngine%3DE636EE02D3.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOStateMachineEngine%3DE636EE02D3.implementation preserve=yes
      //## end CPOStateMachineEngine%3DE636EE02D3.implementation

};

//## begin CPOStateMachineEngine%3DE636EE02D3.postscript preserve=yes
//## end CPOStateMachineEngine%3DE636EE02D3.postscript

// Class CPOStateMachineEngine 

//## begin module%3DE5EB5D01D9.epilog preserve=yes
//## end module%3DE5EB5D01D9.epilog


#endif
