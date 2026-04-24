//## begin module%3DAAE3D40081.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAE3D40081.cm

//## begin module%3DAAE3D40081.cp preserve=no
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
//## end module%3DAAE3D40081.cp

//## Module: EBMCsten%3DAAE3D40081; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCsten.h

#ifndef EBMCsten_h
#define EBMCsten_h 1

//## begin module%3DAAE3D40081.additionalIncludes preserve=no
//## end module%3DAAE3D40081.additionalIncludes

//## begin module%3DAAE3D40081.includes preserve=yes
//## end module%3DAAE3D40081.includes

// EBCOimct
#include "EBCOimct.h"
//## begin module%3DAAE3D40081.declarations preserve=no
//## end module%3DAAE3D40081.declarations

//## begin module%3DAAE3D40081.additionalDeclarations preserve=yes
//## end module%3DAAE3D40081.additionalDeclarations


//## begin CMCStateMachineEngine%3DAAE9820294.preface preserve=yes
//## end CMCStateMachineEngine%3DAAE9820294.preface

//## Class: CMCStateMachineEngine%3DAAE9820294
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAAE9B90023;CMCStateCreated { -> }
//## Uses: <unnamed>%3E6E0EED02FD;CMCStateProcess { -> }
//## Uses: <unnamed>%3E6E0EF00109;CMCStateData { -> }
//## Uses: <unnamed>%3E6E0F1200FA;CMCActionGetDataPackage { -> }
//## Uses: <unnamed>%3E6E0F2300EA;MC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F6164320138;CMCStateNotConnected { -> }

class CMCStateMachineEngine : public CCOStateMachineEngine  //## Inherits: <unnamed>%3DAAE98A0285
{
  //## begin CMCStateMachineEngine%3DAAE9820294.initialDeclarations preserve=yes
  //## end CMCStateMachineEngine%3DAAE9820294.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CMCStateMachineEngine%1034575117
      CMCStateMachineEngine (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CMCStateMachineEngine();


    //## Other Operations (specified)
      //## Operation: BuildStateMachine%1034575119
      //	DESCRIPTION
      //	Builds up the entire state machine.
      //
      //	RETURNS
      //	void
      static void BuildStateMachine ();

      //## Operation: DeleteStateMachine%1034575118
      //	DESCRIPTION
      //	Cleans up the entire state machine.
      //
      //	RETURNS
      //	void
      static void DeleteStateMachine ();

    // Additional Public Declarations
      //## begin CMCStateMachineEngine%3DAAE9820294.public preserve=yes
      //## end CMCStateMachineEngine%3DAAE9820294.public

  protected:

    //## Other Operations (specified)
      //## Operation: GetInitializeState%1042097143
      //	DESCRIPTION
      //	Gets the initialize state
      //
      //	RETURNS
      //	Pointer to initial state
      virtual CCOState* GetInitializeState ();

      //## Operation: CreateActions%1034575120
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
      //## begin CMCStateMachineEngine%3DAAE9820294.protected preserve=yes
      //## end CMCStateMachineEngine%3DAAE9820294.protected

  private:
    //## Constructors (generated)
      CMCStateMachineEngine();

      CMCStateMachineEngine(const CMCStateMachineEngine &right);

    //## Assignment Operation (generated)
      const CMCStateMachineEngine & operator=(const CMCStateMachineEngine &right);

    //## Equality Operations (generated)
      bool operator==(const CMCStateMachineEngine &right) const;

      bool operator!=(const CMCStateMachineEngine &right) const;

    // Additional Private Declarations
      //## begin CMCStateMachineEngine%3DAAE9820294.private preserve=yes
      //## end CMCStateMachineEngine%3DAAE9820294.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCStateMachineEngine%3DAAE9820294.implementation preserve=yes
      //## end CMCStateMachineEngine%3DAAE9820294.implementation

};

//## begin CMCStateMachineEngine%3DAAE9820294.postscript preserve=yes
//## end CMCStateMachineEngine%3DAAE9820294.postscript

// Class CMCStateMachineEngine 

//## begin module%3DAAE3D40081.epilog preserve=yes
//## end module%3DAAE3D40081.epilog


#endif
