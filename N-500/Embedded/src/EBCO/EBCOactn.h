//## begin module%3BA8E6D20027.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BA8E6D20027.cm

//## begin module%3BA8E6D20027.cp preserve=no
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
//## end module%3BA8E6D20027.cp

//## Module: EBCOactn%3BA8E6D20027; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOactn.h

#ifndef EBCOactn_h
#define EBCOactn_h 1

//## begin module%3BA8E6D20027.additionalIncludes preserve=no
//## end module%3BA8E6D20027.additionalIncludes

//## begin module%3BA8E6D20027.includes preserve=yes
//## end module%3BA8E6D20027.includes


class EBCO_DLL_DECL CCOSyncObject;
class EBCO_DLL_DECL ICOStateMachineContext;

//## begin module%3BA8E6D20027.declarations preserve=no
//## end module%3BA8E6D20027.declarations

//## begin module%3BA8E6D20027.additionalDeclarations preserve=yes
//## end module%3BA8E6D20027.additionalDeclarations


//## begin CCOAction%3BA8E6F2039E.preface preserve=yes
//## end CCOAction%3BA8E6F2039E.preface

//## Class: CCOAction%3BA8E6F2039E
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BA8F28B03C5;XCOExceptionCleanupStop { -> }

class EBCO_DLL_DECL CCOAction 
{
  //## begin CCOAction%3BA8E6F2039E.initialDeclarations preserve=yes
  //## end CCOAction%3BA8E6F2039E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOAction%1000925467
      CCOAction (const UINT p_uiID, ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CCOAction();


    //## Other Operations (specified)
      //## Operation: Execute%1000925464
      //	DESCRIPTION
      //	Calls by the state machine engine to execute an action.
      //	The action calls the protected method Execute which has
      //	to be overloaded by any specialized class.
      //
      //	RETURNS
      //	void
      void Execute ();

      //## Operation: Cancel%1000925463
      //	DESCRIPTION
      //	Cancels an action. Resets the current references to
      //	client and server sync objects.
      //
      //	RETURNS
      //	void
      virtual void Cancel ();

      //## Operation: Done%1000925468
      //	DESCRIPTION
      //	Tells an action that the server signalled completion.
      //	Therefore the sync object can be thrown away.
      //
      //	RETURNS
      //	void
      virtual void Done ();

      //## Operation: SetpClientSyncObj%1000925469
      //	DESCRIPTION
      //	Stores a client sync object in the action. It will be
      //	signalled, if 'Done' is called. The action keeps an own
      //	reference to the sync object.
      //
      //	PARAMETER
      //	Pointer to sync object
      //
      //	RETURNS
      //	void
      virtual void SetpClientSyncObj (CCOSyncObject* p_pSyncObject);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: uiID%3BA9001B0346
      UINT GetuiID ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69BAC0397
      //## Role: CCOAction::pClientSyncObj%3DA69BAD0231
      CCOSyncObject * GetpClientSyncObj ();

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69BB00220
      //## Role: CCOAction::pServerSyncObj%3DA69BB1004C
      CCOSyncObject * GetpServerSyncObj ();

    // Additional Public Declarations
      //## begin CCOAction%3BA8E6F2039E.public preserve=yes
      //## end CCOAction%3BA8E6F2039E.public

  protected:

    //## Other Operations (specified)
      //## Operation: ExecuteAction%1000925465
      virtual CCOSyncObject* ExecuteAction () = 0;

    // Data Members for Class Attributes

      //## begin CCOAction::uiID%3BA9001B0346.attr preserve=no  public: UINT {U} p_uiID
      UINT m_uiID;
      //## end CCOAction::uiID%3BA9001B0346.attr

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69BAC0397
      //## begin CCOAction::pClientSyncObj%3DA69BAD0231.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pClientSyncObj;
      //## end CCOAction::pClientSyncObj%3DA69BAD0231.role

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69BB00220
      //## begin CCOAction::pServerSyncObj%3DA69BB1004C.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pServerSyncObj;
      //## end CCOAction::pServerSyncObj%3DA69BB1004C.role

      //## Association: EBCO (Core Classes)::<unnamed>%3DA6AF4F03B6
      //## Role: CCOAction::pContext%3DA6AF5001D3
      //## begin CCOAction::pContext%3DA6AF5001D3.role preserve=no  public: ICOStateMachineContext {1..1 -> 1..1RFHN}
      ICOStateMachineContext *m_pContext;
      //## end CCOAction::pContext%3DA6AF5001D3.role

    // Additional Protected Declarations
      //## begin CCOAction%3BA8E6F2039E.protected preserve=yes
      //## end CCOAction%3BA8E6F2039E.protected

  private:
    //## Constructors (generated)
      CCOAction();

      CCOAction(const CCOAction &right);

    //## Assignment Operation (generated)
      const CCOAction & operator=(const CCOAction &right);

    //## Equality Operations (generated)
      bool operator==(const CCOAction &right) const;

      bool operator!=(const CCOAction &right) const;

    // Additional Private Declarations
      //## begin CCOAction%3BA8E6F2039E.private preserve=yes
      //## end CCOAction%3BA8E6F2039E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOAction%3BA8E6F2039E.implementation preserve=yes
      //## end CCOAction%3BA8E6F2039E.implementation

};

//## begin CCOAction%3BA8E6F2039E.postscript preserve=yes
//## end CCOAction%3BA8E6F2039E.postscript

//## begin CCOActionArray%3BA8EABE00D5.preface preserve=yes
//## end CCOActionArray%3BA8EABE00D5.preface

//## Class: CCOActionArray%3BA8EABE00D5; Instantiated Class
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BA8EAEA02C3;CCOAction { -> }

typedef CTypedPtrArray< CPtrArray,CCOAction* > CCOActionArray;

//## begin CCOActionArray%3BA8EABE00D5.postscript preserve=yes
//## end CCOActionArray%3BA8EABE00D5.postscript

// Class CCOAction 

//## begin module%3BA8E6D20027.epilog preserve=yes
//## end module%3BA8E6D20027.epilog


#endif
