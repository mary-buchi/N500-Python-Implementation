//## begin module%3DE5EE1B0024.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EE1B0024.cm

//## begin module%3DE5EE1B0024.cp preserve=no
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
//## end module%3DE5EE1B0024.cp

//## Module: EBTCsten%3DE5EE1B0024; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCsten.h

#ifndef EBTCsten_h
#define EBTCsten_h 1

//## begin module%3DE5EE1B0024.additionalIncludes preserve=no
//## end module%3DE5EE1B0024.additionalIncludes

//## begin module%3DE5EE1B0024.includes preserve=yes
//## end module%3DE5EE1B0024.includes

// EBCOimct
#include "EBCOimct.h"
//## begin module%3DE5EE1B0024.declarations preserve=no
//## end module%3DE5EE1B0024.declarations

//## begin module%3DE5EE1B0024.additionalDeclarations preserve=yes
//## end module%3DE5EE1B0024.additionalDeclarations


//## begin CTCStateMachineEngine%3DEC63C60252.preface preserve=yes
//## end CTCStateMachineEngine%3DEC63C60252.preface

//## Class: CTCStateMachineEngine%3DEC63C60252
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DEC856F0274;CTCStateCreated { -> }
//## Uses: <unnamed>%3E43D4DA034B;CTCStateConfig { -> }
//## Uses: <unnamed>%3E4775D300EA;CTCStateProcess { -> }
//## Uses: <unnamed>%3EE82F2E0198;CTCStateNotConnectedProcess { -> }

class CTCStateMachineEngine : public CCOStateMachineEngine  //## Inherits: <unnamed>%3DEC63D90129
{
  //## begin CTCStateMachineEngine%3DEC63C60252.initialDeclarations preserve=yes
  //## end CTCStateMachineEngine%3DEC63C60252.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCStateMachineEngine%1038899318
      CTCStateMachineEngine (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CTCStateMachineEngine();


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
      //## begin CTCStateMachineEngine%3DEC63C60252.public preserve=yes
      //## end CTCStateMachineEngine%3DEC63C60252.public

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
      //## begin CTCStateMachineEngine%3DEC63C60252.protected preserve=yes
      //## end CTCStateMachineEngine%3DEC63C60252.protected

  private:
    //## Constructors (generated)
      CTCStateMachineEngine();

      CTCStateMachineEngine(const CTCStateMachineEngine &right);

    //## Assignment Operation (generated)
      const CTCStateMachineEngine & operator=(const CTCStateMachineEngine &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateMachineEngine &right) const;

      bool operator!=(const CTCStateMachineEngine &right) const;

    // Additional Private Declarations
      //## begin CTCStateMachineEngine%3DEC63C60252.private preserve=yes
      //## end CTCStateMachineEngine%3DEC63C60252.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateMachineEngine%3DEC63C60252.implementation preserve=yes
      //## end CTCStateMachineEngine%3DEC63C60252.implementation

};

//## begin CTCStateMachineEngine%3DEC63C60252.postscript preserve=yes
//## end CTCStateMachineEngine%3DEC63C60252.postscript

// Class CTCStateMachineEngine 

//## begin module%3DE5EE1B0024.epilog preserve=yes
//## end module%3DE5EE1B0024.epilog


#endif
