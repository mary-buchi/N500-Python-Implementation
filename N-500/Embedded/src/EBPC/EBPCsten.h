//## begin module%3EED769F0376.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F0376.cm

//## begin module%3EED769F0376.cp preserve=no
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
//## end module%3EED769F0376.cp

//## Module: EBPCsten%3EED769F0376; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCsten.h

#ifndef EBPCsten_h
#define EBPCsten_h 1

//## begin module%3EED769F0376.additionalIncludes preserve=no
//## end module%3EED769F0376.additionalIncludes

//## begin module%3EED769F0376.includes preserve=yes
//## end module%3EED769F0376.includes

// EBCOimct
#include "EBCOimct.h"
//## begin module%3EED769F0376.declarations preserve=no
//## end module%3EED769F0376.declarations

//## begin module%3EED769F0376.additionalDeclarations preserve=yes
//## end module%3EED769F0376.additionalDeclarations


//## begin CPCStateMachineEngine%3EED76CC033F.preface preserve=yes
//## end CPCStateMachineEngine%3EED76CC033F.preface

//## Class: CPCStateMachineEngine%3EED76CC033F
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EED76CC0344;CPCStateCreated { -> }
//## Uses: <unnamed>%3EED76CC034D;CPCStateNotConnected { -> }
//## Uses: <unnamed>%40279FB40342;CPCStateConfigNotSet { -> }
//## Uses: <unnamed>%40279FD40304;CPCStateConfigSet { -> }
//## Uses: <unnamed>%40279FF400B2;CPCStateConfigProfileNotSet { -> }
//## Uses: <unnamed>%4027A0070314;CPCStateConfigProfileSet { -> }
//## Uses: <unnamed>%4027A02002F4;CPCStateIdlePowerOff { -> }
//## Uses: <unnamed>%4027A0620304;CPCStateIdleStarting { -> }
//## Uses: <unnamed>%4027A2190100;CPCStateProcessControling { -> }
//## Uses: <unnamed>%4027A27302B6;CPCStateIdleCheckPower { -> }
//## Uses: <unnamed>%4027A2810342;CPCStateIdleStandBy { -> }

class CPCStateMachineEngine : public CCOStateMachineEngine  //## Inherits: <unnamed>%3EED76CC0341
{
  //## begin CPCStateMachineEngine%3EED76CC033F.initialDeclarations preserve=yes
  //## end CPCStateMachineEngine%3EED76CC033F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPCStateMachineEngine%1038899318
      CPCStateMachineEngine (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CPCStateMachineEngine();


    //## Other Operations (specified)
      //## Operation: BuildStateMachine%1038899319
      //	DESCRIPTION
      //	Builds up the entire state machine.
      //
      //	RETURNS
      //	void
      static void BuildStateMachine ();

      //## Operation: DeleteStateMachine%1038899321
      //	DESCRIPTION
      //	Cleans up the entire state machine.
      //
      //	RETURNS
      //	void
      static void DeleteStateMachine ();

    // Additional Public Declarations
      //## begin CPCStateMachineEngine%3EED76CC033F.public preserve=yes
      //## end CPCStateMachineEngine%3EED76CC033F.public

  protected:

    //## Other Operations (specified)
      //## Operation: GetInitializeState%1042097147
      //	DESCRIPTION
      //	Gets the initialize state
      //
      //	RETURNS
      //	Pointer to initial state
      virtual CCOState* GetInitializeState ();

      //## Operation: CreateActions%1038899320
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
      //## begin CPCStateMachineEngine%3EED76CC033F.protected preserve=yes
      //## end CPCStateMachineEngine%3EED76CC033F.protected

  private:
    //## Constructors (generated)
      CPCStateMachineEngine();

      CPCStateMachineEngine(const CPCStateMachineEngine &right);

    //## Assignment Operation (generated)
      const CPCStateMachineEngine & operator=(const CPCStateMachineEngine &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateMachineEngine &right) const;

      bool operator!=(const CPCStateMachineEngine &right) const;

    // Additional Private Declarations
      //## begin CPCStateMachineEngine%3EED76CC033F.private preserve=yes
      //## end CPCStateMachineEngine%3EED76CC033F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateMachineEngine%3EED76CC033F.implementation preserve=yes
      //## end CPCStateMachineEngine%3EED76CC033F.implementation

};

//## begin CPCStateMachineEngine%3EED76CC033F.postscript preserve=yes
//## end CPCStateMachineEngine%3EED76CC033F.postscript

// Class CPCStateMachineEngine 

//## begin module%3EED769F0376.epilog preserve=yes
//## end module%3EED769F0376.epilog


#endif
