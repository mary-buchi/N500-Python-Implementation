//## begin module%3B91278600C3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B91278600C3.cm

//## begin module%3B91278600C3.cp preserve=no
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
//## end module%3B91278600C3.cp

//## Module: EBCOimct%3B91278600C3; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOimct.h

#ifndef EBCOimct_h
#define EBCOimct_h 1

//## begin module%3B91278600C3.additionalIncludes preserve=no
//## end module%3B91278600C3.additionalIncludes

//## begin module%3B91278600C3.includes preserve=yes
//## end module%3B91278600C3.includes

// EBCOtype
#include "EBCOtype.h"
// EBCOactn
#include "EBCOactn.h"

class EBCO_DLL_DECL CCOSyncObjectArray;
class EBCO_DLL_DECL CCOSyncObject;
class EBCO_DLL_DECL ICOStateMachineContext;
class EBCO_DLL_DECL CCOStateMachineEngine;
class EBCO_DLL_DECL CCOState;
class EBCO_DLL_DECL CCOCommand;

//## begin module%3B91278600C3.declarations preserve=no
//## end module%3B91278600C3.declarations

//## begin module%3B91278600C3.additionalDeclarations preserve=yes
//## end module%3B91278600C3.additionalDeclarations


//## begin CCOStateMachineEngine%3B91276F0143.preface preserve=yes
//## end CCOStateMachineEngine%3B91276F0143.preface

//## Class: CCOStateMachineEngine%3B91276F0143
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B91383A002C;CCOCommand { -> F}
//## Uses: <unnamed>%3BA8EB8201C7;CCOActionArray { -> }

class EBCO_DLL_DECL CCOStateMachineEngine 
{
  //## begin CCOStateMachineEngine%3B91276F0143.initialDeclarations preserve=yes
  //## end CCOStateMachineEngine%3B91276F0143.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOStateMachineEngine%999369756
      CCOStateMachineEngine (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CCOStateMachineEngine();


    //## Other Operations (specified)
      //## Operation: Create%1000406958
      //	DESCRIPTION
      //	Sets up the entire state machine (state singletons) and
      //	calls 'BuildStateMachine' which has to be oberloaded by
      //	the specialized class.
      //
      //	RETURNS
      //	void
      virtual void Create ();

      //## Operation: Run%999369751
      //	DESCRIPTION
      //	Executes the given command and runs the state machine
      //	through its states.
      //
      //	PARAMETER
      //	- Optional command to execute
      //
      //	RETURNS
      //	void
      virtual void Run (CCOCommand* p_pCommand = NULL);

      //## Operation: ChangeState%999369763
      //	DESCRIPTION
      //	Sets the value of the 'pNextState' according to the
      //	given paramater.
      //
      //	PARAMETER
      //	- Pointer to the next state to enter
      //	- Array of actions to execute within the state transition
      //
      //	RETURNS
      //	void
      virtual void ChangeState (CCOState* p_pNextState, CCOActionArray& p_ActionArray = *((CCOActionArray*)NULL));

      //## Operation: ChangeState%1000925462
      //	DESCRIPTION
      //	Sets the value of the 'pNextState' according to the
      //	given paramater.
      //
      //	PARAMETER
      //	- Pointer to the next state to enter
      //	- single action to execute within state transition
      //
      //	RETURNS
      //	void
      virtual void ChangeState (CCOState* p_pNextState, CCOAction* p_pSingleAction);

      //## Operation: Cleanup%1001240168
      //	DESCRIPTION
      //	Called from the DispatchCommand method in case of a
      //	caught exception. Cleans up the sync objects of the
      //	stored actions which are not used any more.
      //
      //	RETURNS
      //	void
      virtual void Cleanup ();

      //## Operation: GetsCurrentState%1000031201
      //	DESCRIPTION
      //	Returns the current state of the unit in text.
      //
      //	RETURNS
      //	State name
      virtual CString GetsCurrentState ();

      //## Operation: GetAction%1000925475
      //	DESCRIPTION
      //	Scans the array of actions for the given ID and returns
      //	the pointer to the specific action.
      //
      //	PARAMETER
      //	ID of the action
      //
      //	RETURNS
      //	Pointer to action
      virtual CCOAction* GetAction (const UINT p_uiID);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBCO (Core Classes)::<unnamed>%3DA6A192006A
      //## Role: CCOStateMachineEngine::pCurrentState%3DA6A192023F
      CCOState * GetpCurrentState ();

      //## Association: EBCO (Core Classes)::<unnamed>%3DA6A1A8007A
      //## Role: CCOStateMachineEngine::pNextState%3DA6A1A802FC
      CCOState * GetpNextState ();

      //## Association: EBCO (Core Classes)::<unnamed>%3DA6A1BE00D8
      //## Role: CCOStateMachineEngine::pHistoryState%3DA6A1BE0359
      CCOState * GetpHistoryState ();

    // Additional Public Declarations
      //## begin CCOStateMachineEngine%3B91276F0143.public preserve=yes
      //## end CCOStateMachineEngine%3B91276F0143.public

  protected:

    //## Other Operations (specified)
      //## Operation: CreateActions%1000925460
      //	DESCRIPTION
      //	Creates all existing actions and places them into the
      //	array of actions.
      //
      //	PARAMETER
      //	Action pointer List
      //
      //	RETURNS
      //	void
      virtual void CreateActions (CTypedPtrList<CPtrList, CCOAction*>& p_ActionList) = 0;

      //## Operation: GetInitializeState%1042097139
      //	DESCRIPTION
      //	Gets the initialize state
      //
      //	RETURNS
      //	Pointer to initial state
      virtual CCOState* GetInitializeState () = 0;

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3DA6A14C008A
      //## Role: CCOStateMachineEngine::pContext%3DA6A14C027F
      //## begin CCOStateMachineEngine::pContext%3DA6A14C027F.role preserve=no  public: ICOStateMachineContext {1..1 -> 1..1RFHN}
      ICOStateMachineContext *m_pContext;
      //## end CCOStateMachineEngine::pContext%3DA6A14C027F.role

      //## Association: EBCO (Core Classes)::<unnamed>%3DA6A192006A
      //## begin CCOStateMachineEngine::pCurrentState%3DA6A192023F.role preserve=no  public: CCOState {1..1 -> 1..1RFHN}
      CCOState *m_pCurrentState;
      //## end CCOStateMachineEngine::pCurrentState%3DA6A192023F.role

      //## Association: EBCO (Core Classes)::<unnamed>%3DA6A1A8007A
      //## begin CCOStateMachineEngine::pNextState%3DA6A1A802FC.role preserve=no  public: CCOState {1..1 -> 1..1RFHN}
      CCOState *m_pNextState;
      //## end CCOStateMachineEngine::pNextState%3DA6A1A802FC.role

      //## Association: EBCO (Core Classes)::<unnamed>%3DA6A1BE00D8
      //## begin CCOStateMachineEngine::pHistoryState%3DA6A1BE0359.role preserve=no  public: CCOState {1..1 -> 1..1RFHN}
      CCOState *m_pHistoryState;
      //## end CCOStateMachineEngine::pHistoryState%3DA6A1BE0359.role

    // Additional Protected Declarations
      //## begin CCOStateMachineEngine%3B91276F0143.protected preserve=yes
      //## end CCOStateMachineEngine%3B91276F0143.protected

  private:
    //## Constructors (generated)
      CCOStateMachineEngine();

      CCOStateMachineEngine(const CCOStateMachineEngine &right);

    //## Assignment Operation (generated)
      const CCOStateMachineEngine & operator=(const CCOStateMachineEngine &right);

    //## Equality Operations (generated)
      bool operator==(const CCOStateMachineEngine &right) const;

      bool operator!=(const CCOStateMachineEngine &right) const;

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3DA6AF6D024F
      //## Role: CCOStateMachineEngine::ActionMap%3DA6AF6E0221
      //## Constraints:
      //	ordered
      //## Qualifier: $UNNAMED$55%3DA6AF95023F; UINT
      //## begin CCOStateMachineEngine::ActionMap%3DA6AF6E0221.role preserve=no  public: CCOAction {1 -> RFHON}
      CMap<UINT, UINT&, CCOAction *, CCOAction *&> m_ActionMap;
      //## end CCOStateMachineEngine::ActionMap%3DA6AF6E0221.role

    // Additional Private Declarations
      //## begin CCOStateMachineEngine%3B91276F0143.private preserve=yes
      //## end CCOStateMachineEngine%3B91276F0143.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOStateMachineEngine%3B91276F0143.implementation preserve=yes
      //## end CCOStateMachineEngine%3B91276F0143.implementation

};

//## begin CCOStateMachineEngine%3B91276F0143.postscript preserve=yes
//## end CCOStateMachineEngine%3B91276F0143.postscript

//## begin ICOStateMachineContext%3B913B7C0053.preface preserve=yes
//## end ICOStateMachineContext%3B913B7C0053.preface

//## Class: ICOStateMachineContext%3B913B7C0053
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BAA4D51028B;ECOInterruptReason { -> }
//## Uses: <unnamed>%3BAA4E380143;CO_WAKE_UP_MASK { -> }
//## Uses: <unnamed>%3BAA51C803D9;CCOAction { -> F}
//## Uses: <unnamed>%3BAA52E50158;CCOSyncObject { -> F}
//## Uses: <unnamed>%3BAA52EA0264;CCOSyncObjectArray { -> F}

class EBCO_DLL_DECL ICOStateMachineContext 
{
  //## begin ICOStateMachineContext%3B913B7C0053.initialDeclarations preserve=yes
  //## end ICOStateMachineContext%3B913B7C0053.initialDeclarations

  public:
    //## Constructors (generated)
      ICOStateMachineContext();

    //## Destructor (generated)
      virtual ~ICOStateMachineContext();


    //## Other Operations (specified)
      //## Operation: ChangeState%1001010367
      //	DESCRIPTION
      //	Sets the value of the 'pNextState' according to the
      //	given paramater.
      //
      //	PARAMETER
      //	- Pointer to the next state to enter
      //	- Array of actions to execute within the state transition
      //
      //	RETURNS
      //	void
      virtual void ChangeState (CCOState* p_pNextState, CCOActionArray& p_ActionArray = *((CCOActionArray*)NULL));

      //## Operation: ChangeState%1001010368
      //	DESCRIPTION
      //	Sets the value of the 'pNextState' according to the
      //	given paramater.
      //
      //	PARAMETER
      //	- Pointer to the next state to enter
      //	- single action to execute within state transition
      //
      //	RETURNS
      //	void
      virtual void ChangeState (CCOState* p_pNextState, CCOAction* p_pSingleAction);

      //## Operation: RestoreHistory%1000836380
      //	DESCRIPTION
      //	Takes the previously stored history state and enters it
      //	again.
      //
      //	RETURNS
      //	void
      virtual void RestoreHistory ();

      //## Operation: GetAction%1001017246
      //	DESCRIPTION
      //	Scans the array of actions for the given ID and returns
      //	the pointer to the specific action.
      //
      //	PARAMETER
      //	ID of the action
      //
      //	RETURNS
      //	Pointer to action
      virtual CCOAction* GetAction (const UINT p_uiID);

      //## Operation: GetsContextID%1000925466
      //	DESCRIPTION
      //	Returns an identification of the state machine context.
      //	Used for creating and identification of exceptions.
      //
      //	RETURNS
      //	String Identifier
      virtual CString GetsContextID () = 0;

      //## Operation: WaitOnActionDone%1001017244
      //	DESCRIPTION
      //	Waits until all the given sync objects have been
      //	signalled or another event occured such us an above
      //	normal resp. high prio command.
      //
      //	PARAMETERS
      //	- array of sync objects
      //	- wake up mask. Defaults to high prio commands only
      //	- timeout in ms. Defaults to infinite
      //	- optional parameter, indicating the index of the
      //	signalled action. Only together with the wake up mask CO_
      //	WAKE_MASK_ACTIONS_ONE
      //
      //	RETURNS
      //	Reason of interruption resp. action completion.
      virtual ECOInterruptReason WaitOnActionDone (CCOSyncObjectArray* p_pSyncArray, const DWORD p_dwWakeUpMask = CO_WAKE_MASK_DEFAULT, const DWORD p_dwTimeout = INFINITE, UINT& p_uiSignalledIndex = *((UINT*)NULL)) = 0;

      //## Operation: WaitOnActionDone%1001017245
      //	DESCRIPTION
      //	Waits until all the given sync objects have been
      //	signalled or another event occured such us an above
      //	normal resp. high prio command.
      //
      //	PARAMETERS
      //	- sync object
      //	- wake up mask. Defaults to high prio commands only
      //	- timeout in ms. Defaults to infinite
      //
      //	RETURNS
      //	Reason of interruption resp. action completion.
      virtual ECOInterruptReason WaitOnActionDone (CCOSyncObject* p_pSyncObj, const DWORD p_dwWakeUpMask = CO_WAKE_MASK_DEFAULT, const DWORD p_dwTimeout = INFINITE) = 0;

    //## Get and Set Operations for Associations (generated)

      //## Association: EBCO (Core Classes)::<unnamed>%3DA6A0A7004B
      //## Role: ICOStateMachineContext::pStateMachineEngine%3DA6A0A7029D
      CCOStateMachineEngine * GetpStateMachineEngine ();

    // Additional Public Declarations
      //## begin ICOStateMachineContext%3B913B7C0053.public preserve=yes
      //## end ICOStateMachineContext%3B913B7C0053.public

  protected:
    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3DA6A0A7004B
      //## begin ICOStateMachineContext::pStateMachineEngine%3DA6A0A7029D.role preserve=no  public: CCOStateMachineEngine {1..1 -> 1..1RFHN}
      CCOStateMachineEngine *m_pStateMachineEngine;
      //## end ICOStateMachineContext::pStateMachineEngine%3DA6A0A7029D.role

    // Additional Protected Declarations
      //## begin ICOStateMachineContext%3B913B7C0053.protected preserve=yes
      //## end ICOStateMachineContext%3B913B7C0053.protected

  private:
    // Additional Private Declarations
      //## begin ICOStateMachineContext%3B913B7C0053.private preserve=yes
      //## end ICOStateMachineContext%3B913B7C0053.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin ICOStateMachineContext%3B913B7C0053.implementation preserve=yes
      //## end ICOStateMachineContext%3B913B7C0053.implementation

};

//## begin ICOStateMachineContext%3B913B7C0053.postscript preserve=yes
//## end ICOStateMachineContext%3B913B7C0053.postscript

// Class CCOStateMachineEngine 

// Class ICOStateMachineContext 

//## begin module%3B91278600C3.epilog preserve=yes
//## end module%3B91278600C3.epilog


#endif
