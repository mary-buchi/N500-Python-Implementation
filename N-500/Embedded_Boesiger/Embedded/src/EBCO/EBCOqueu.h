//## begin module%3B8D4D3D006E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8D4D3D006E.cm

//## begin module%3B8D4D3D006E.cp preserve=no
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
//## end module%3B8D4D3D006E.cp

//## Module: EBCOqueu%3B8D4D3D006E; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOqueu.h

#ifndef EBCOqueu_h
#define EBCOqueu_h 1

//## begin module%3B8D4D3D006E.additionalIncludes preserve=no
//## end module%3B8D4D3D006E.additionalIncludes

//## begin module%3B8D4D3D006E.includes preserve=yes
//## end module%3B8D4D3D006E.includes

// EBCOenum
#include "EBCOenum.h"

class EBCO_DLL_DECL CCOCommand;

//## begin module%3B8D4D3D006E.declarations preserve=no
//## end module%3B8D4D3D006E.declarations

//## begin module%3B8D4D3D006E.additionalDeclarations preserve=yes
//## end module%3B8D4D3D006E.additionalDeclarations


//## begin CCOCommandQueue%3B8D4D120026.preface preserve=yes
//## end CCOCommandQueue%3B8D4D120026.preface

//## Class: CCOCommandQueue%3B8D4D120026
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BA64E1C033E;XCOException { -> }
//## Uses: <unnamed>%3BA64E2E00AF; { -> }
//## Uses: <unnamed>%3DA69FA100E7;CO_IDENTIFIERS { -> }

class CCOCommandQueue 
{
  //## begin CCOCommandQueue%3B8D4D120026.initialDeclarations preserve=yes
  //## end CCOCommandQueue%3B8D4D120026.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOCommandQueue%1066286189
      CCOCommandQueue (ECOAsyncCallQueue p_eQueueType);

    //## Destructor (generated)
      virtual ~CCOCommandQueue();


    //## Other Operations (specified)
      //## Operation: AddTail%999108319
      void AddTail (CCOCommand* p_pCommand, const bool p_bUniqCommand = false);

      //## Operation: RemoveHead%999108320
      CCOCommand* RemoveHead ();

      //## Operation: Suspend%1000752287
      void Suspend ();

      //## Operation: Resume%1000752288
      void Resume ();

      //## Operation: Flush%1000752289
      void Flush ();

      //## Operation: SkipCommand%1053348765
      void SkipCommand (const type_info& p_CommandType);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69EA50387
      //## Role: CCOCommandQueue::QueueEvent%3DA69EA601F2
      CEvent& GetQueueEvent ();

    // Additional Public Declarations
      //## begin CCOCommandQueue%3B8D4D120026.public preserve=yes
      //## end CCOCommandQueue%3B8D4D120026.public

  protected:
    // Additional Protected Declarations
      //## begin CCOCommandQueue%3B8D4D120026.protected preserve=yes
      //## end CCOCommandQueue%3B8D4D120026.protected

  private:
    //## Constructors (generated)
      CCOCommandQueue();

      CCOCommandQueue(const CCOCommandQueue &right);

    //## Assignment Operation (generated)
      const CCOCommandQueue & operator=(const CCOCommandQueue &right);

    //## Equality Operations (generated)
      bool operator==(const CCOCommandQueue &right) const;

      bool operator!=(const CCOCommandQueue &right) const;


    //## Other Operations (specified)
      //## Operation: IsUniq%1053348764
      bool IsUniq (CCOCommand* p_pCommand);

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69EA50387
      //## begin CCOCommandQueue::QueueEvent%3DA69EA601F2.role preserve=no  public: CEvent {1..1 -> 1..1VFHN}
      CEvent m_QueueEvent;
      //## end CCOCommandQueue::QueueEvent%3DA69EA601F2.role

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69EBA032A
      //## Role: CCOCommandQueue::AccessLock%3DA69EBB0175
      //## begin CCOCommandQueue::AccessLock%3DA69EBB0175.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_AccessLock;
      //## end CCOCommandQueue::AccessLock%3DA69EBB0175.role

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69ED701C2
      //## Role: CCOCommandQueue::Commands%3DA69ED80127
      //## begin CCOCommandQueue::Commands%3DA69ED80127.role preserve=no  public: CCOCommand {0 -> nRFHN}
      CTypedPtrList<CPtrList, CCOCommand*> m_Commands;
      //## end CCOCommandQueue::Commands%3DA69ED80127.role

      //## Association: EBCO (Core Classes)::<unnamed>%3EC8DFE600CE
      //## Role: CCOCommandQueue::bSuspended%3EC8DFE602D3
      //## begin CCOCommandQueue::bSuspended%3EC8DFE602D3.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bSuspended;
      //## end CCOCommandQueue::bSuspended%3EC8DFE602D3.role

      //## Association: EBCO (Core Classes)::<unnamed>%3F8E3C2303CD
      //## Role: CCOCommandQueue::eQueueType%3F8E3C2402A5
      //## begin CCOCommandQueue::eQueueType%3F8E3C2402A5.role preserve=no  public: ECOAsyncCallQueue {1..1 -> 1..1VHN}
      ECOAsyncCallQueue m_eQueueType;
      //## end CCOCommandQueue::eQueueType%3F8E3C2402A5.role

    // Additional Private Declarations
      //## begin CCOCommandQueue%3B8D4D120026.private preserve=yes
      //## end CCOCommandQueue%3B8D4D120026.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOCommandQueue%3B8D4D120026.implementation preserve=yes
      //## end CCOCommandQueue%3B8D4D120026.implementation

};

//## begin CCOCommandQueue%3B8D4D120026.postscript preserve=yes
//## end CCOCommandQueue%3B8D4D120026.postscript

// Class CCOCommandQueue 

//## begin module%3B8D4D3D006E.epilog preserve=yes
//## end module%3B8D4D3D006E.epilog


#endif
