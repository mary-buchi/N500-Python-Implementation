//## begin module%3DA6C17A03E5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA6C17A03E5.cm

//## begin module%3DA6C17A03E5.cp preserve=no
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
//## end module%3DA6C17A03E5.cp

//## Module: EBSTsten%3DA6C17A03E5; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTsten.h

#ifndef EBSTsten_h
#define EBSTsten_h 1

//## begin module%3DA6C17A03E5.additionalIncludes preserve=no
//## end module%3DA6C17A03E5.additionalIncludes

//## begin module%3DA6C17A03E5.includes preserve=yes
//## end module%3DA6C17A03E5.includes

// EBCOimct
#include "EBCOimct.h"
//## begin module%3DA6C17A03E5.declarations preserve=no
//## end module%3DA6C17A03E5.declarations

//## begin module%3DA6C17A03E5.additionalDeclarations preserve=yes
//## end module%3DA6C17A03E5.additionalDeclarations


//## begin CSTStateMachineEngine%3DA6C1A50397.preface preserve=yes
//## end CSTStateMachineEngine%3DA6C1A50397.preface

//## Class: CSTStateMachineEngine%3DA6C1A50397
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DA6C3270358;CSTStateCreated { -> }
//## Uses: <unnamed>%3E799A9D0209;CSTStateConfig { -> }
//## Uses: <unnamed>%3E799AAB017C;CSTStateHome { -> }
//## Uses: <unnamed>%3E799ABA0238;CSTStateMoving { -> }
//## Uses: <unnamed>%3E82ED2702FD;CHIInterface { -> }
//## Uses: <unnamed>%3E799A810322;CSTStateIdle { -> }
//## Uses: <unnamed>%3EF061D200F7;CSTStateConnectionNotConnected { -> }
//## Uses: <unnamed>%3FBA3BC60294;CSTActionMove { -> }
//## Uses: <unnamed>%43413A96002C;CSTStateHomePrepare { -> }

class CSTStateMachineEngine : public CCOStateMachineEngine  //## Inherits: <unnamed>%3DA6C1AF023F
{
  //## begin CSTStateMachineEngine%3DA6C1A50397.initialDeclarations preserve=yes
  //## end CSTStateMachineEngine%3DA6C1A50397.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTStateMachineEngine%1034329212
      CSTStateMachineEngine (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSTStateMachineEngine();


    //## Other Operations (specified)
      //## Operation: BuildStateMachine%1034329214
      //	DESCRIPTION
      //	Builds up the entire state machine.
      //
      //	RETURNS
      //	void
      static void BuildStateMachine ();

      //## Operation: DeleteStateMachine%1034329213
      //	DESCRIPTION
      //	Cleans up the entire state machine.
      //
      //	RETURNS
      //	void
      static void DeleteStateMachine ();

    // Additional Public Declarations
      //## begin CSTStateMachineEngine%3DA6C1A50397.public preserve=yes
      //## end CSTStateMachineEngine%3DA6C1A50397.public

  protected:

    //## Other Operations (specified)
      //## Operation: GetInitializeState%1042097146
      //	DESCRIPTION
      //	Gets the initialize state
      //
      //	RETURNS
      //	Pointer to initial state
      virtual CCOState* GetInitializeState ();

      //## Operation: CreateActions%1034329215
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
      //## begin CSTStateMachineEngine%3DA6C1A50397.protected preserve=yes
      //## end CSTStateMachineEngine%3DA6C1A50397.protected

  private:
    //## Constructors (generated)
      CSTStateMachineEngine();

      CSTStateMachineEngine(const CSTStateMachineEngine &right);

    //## Assignment Operation (generated)
      const CSTStateMachineEngine & operator=(const CSTStateMachineEngine &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateMachineEngine &right) const;

      bool operator!=(const CSTStateMachineEngine &right) const;

    // Additional Private Declarations
      //## begin CSTStateMachineEngine%3DA6C1A50397.private preserve=yes
      //## end CSTStateMachineEngine%3DA6C1A50397.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateMachineEngine%3DA6C1A50397.implementation preserve=yes
      //## end CSTStateMachineEngine%3DA6C1A50397.implementation

};

//## begin CSTStateMachineEngine%3DA6C1A50397.postscript preserve=yes
//## end CSTStateMachineEngine%3DA6C1A50397.postscript

// Class CSTStateMachineEngine 

//## begin module%3DA6C17A03E5.epilog preserve=yes
//## end module%3DA6C17A03E5.epilog


#endif
