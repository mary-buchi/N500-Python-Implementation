//## begin module%3DD100D80031.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD100D80031.cm

//## begin module%3DD100D80031.cp preserve=no
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
//## end module%3DD100D80031.cp

//## Module: EBWCsten%3DD100D80031; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCsten.h

#ifndef EBWCsten_h
#define EBWCsten_h 1

//## begin module%3DD100D80031.additionalIncludes preserve=no
//## end module%3DD100D80031.additionalIncludes

//## begin module%3DD100D80031.includes preserve=yes
//## end module%3DD100D80031.includes

// EBCOimct
#include "EBCOimct.h"
//## begin module%3DD100D80031.declarations preserve=no
//## end module%3DD100D80031.declarations

//## begin module%3DD100D80031.additionalDeclarations preserve=yes
//## end module%3DD100D80031.additionalDeclarations


//## begin CWCStateMachineEngine%3DD100ED0031.preface preserve=yes
//## end CWCStateMachineEngine%3DD100ED0031.preface

//## Class: CWCStateMachineEngine%3DD100ED0031
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD1F9B1019C;CWCStateCreated { -> }
//## Uses: <unnamed>%3E437DB1029F;CWCStateConfig { -> }
//## Uses: <unnamed>%3E437DB701C5;CWCStateInitialize { -> }
//## Uses: <unnamed>%3E437DB903B9;CWCStateProcess { -> }
//## Uses: <unnamed>%3E5E10480242;WC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3E5E18A701B5;CWCActionInitialize { -> }
//## Uses: <unnamed>%3F6163DA00BB;CWCStateNotConnected { -> }
//## Uses: <unnamed>%3FCB591501A5;CWCStateEmergencyStop { -> }
//## Uses: <unnamed>%3FCB592200FA;CWCStateNotConnectedDuringConfig { -> }

class CWCStateMachineEngine : public CCOStateMachineEngine  //## Inherits: <unnamed>%3DD102A2014A
{
  //## begin CWCStateMachineEngine%3DD100ED0031.initialDeclarations preserve=yes
  //## end CWCStateMachineEngine%3DD100ED0031.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCStateMachineEngine%1037094242
      CWCStateMachineEngine (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CWCStateMachineEngine();


    //## Other Operations (specified)
      //## Operation: BuildStateMachine%1037094244
      //	DESCRIPTION
      //	Builds up the entire state machine.
      //
      //	RETURNS
      //	void
      static void BuildStateMachine ();

      //## Operation: DeleteStateMachine%1037094243
      //	DESCRIPTION
      //	Cleans up the entire state machine.
      //
      //	RETURNS
      //	void
      static void DeleteStateMachine ();

    // Additional Public Declarations
      //## begin CWCStateMachineEngine%3DD100ED0031.public preserve=yes
      //## end CWCStateMachineEngine%3DD100ED0031.public

  protected:

    //## Other Operations (specified)
      //## Operation: GetInitializeState%1042097140
      //	DESCRIPTION
      //	Gets the initialize state
      //
      //	RETURNS
      //	Pointer to initial state
      virtual CCOState* GetInitializeState ();

      //## Operation: CreateActions%1037094245
      //	DESCRIPTION
      //	Creates all existing actions and places them into the
      //	array of actions.
      //
      //	PARAMETER
      //	Action pointer List
      //
      //	RETURNS
      //	void
      virtual void CreateActions (CTypedPtrList<CPtrList,CCOAction*>& p_ActionList);

    // Additional Protected Declarations
      //## begin CWCStateMachineEngine%3DD100ED0031.protected preserve=yes
      //## end CWCStateMachineEngine%3DD100ED0031.protected

  private:
    //## Constructors (generated)
      CWCStateMachineEngine();

      CWCStateMachineEngine(const CWCStateMachineEngine &right);

    //## Assignment Operation (generated)
      const CWCStateMachineEngine & operator=(const CWCStateMachineEngine &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateMachineEngine &right) const;

      bool operator!=(const CWCStateMachineEngine &right) const;

    // Additional Private Declarations
      //## begin CWCStateMachineEngine%3DD100ED0031.private preserve=yes
      //## end CWCStateMachineEngine%3DD100ED0031.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateMachineEngine%3DD100ED0031.implementation preserve=yes
      //## end CWCStateMachineEngine%3DD100ED0031.implementation

};

//## begin CWCStateMachineEngine%3DD100ED0031.postscript preserve=yes
//## end CWCStateMachineEngine%3DD100ED0031.postscript

// Class CWCStateMachineEngine 

//## begin module%3DD100D80031.epilog preserve=yes
//## end module%3DD100D80031.epilog


#endif
