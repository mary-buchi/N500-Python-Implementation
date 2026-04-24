//## begin module%3B8D2E9A0002.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8D2E9A0002.cm

//## begin module%3B8D2E9A0002.cp preserve=no
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
//## end module%3B8D2E9A0002.cp

//## Module: EBCOwkth%3B8D2E9A0002; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOwkth.h

#ifndef EBCOwkth_h
#define EBCOwkth_h 1

//## begin module%3B8D2E9A0002.additionalIncludes preserve=no
//## end module%3B8D2E9A0002.additionalIncludes

//## begin module%3B8D2E9A0002.includes preserve=yes
//## end module%3B8D2E9A0002.includes

// EBCOthrd
#include "EBCOthrd.h"
// EBCOenum
#include "EBCOenum.h"
// EBCOtype
#include "EBCOtype.h"

class EBCO_DLL_DECL CCOCommand;
class CCOCommandQueue;
class EBCO_DLL_DECL ICOAsyncImplementation;
class CCOThreadTimer;

//## begin module%3B8D2E9A0002.declarations preserve=no
//## end module%3B8D2E9A0002.declarations

//## begin module%3B8D2E9A0002.additionalDeclarations preserve=yes
//## end module%3B8D2E9A0002.additionalDeclarations


//## begin CCOThreadWorkImplementation%3B8D2E6C0377.preface preserve=yes
//## end CCOThreadWorkImplementation%3B8D2E6C0377.preface

//## Class: CCOThreadWorkImplementation%3B8D2E6C0377
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B8D3F140061;ECOAsyncCallQueue { -> }
//## Uses: <unnamed>%3B8FECBB0280;XCOException { -> }
//## Uses: <unnamed>%3B8FECC70150;CCOCommand { -> }
//## Uses: <unnamed>%3EC8D5FD0255;CCOCommand { -> F}
//## Uses: <unnamed>%3EC8D64500CE;ECOInterruptReason { -> }

class CCOThreadWorkImplementation : public ICOThreadWork  //## Inherits: <unnamed>%3B8D2EB8022C
{
  //## begin CCOThreadWorkImplementation%3B8D2E6C0377.initialDeclarations preserve=yes
  //## end CCOThreadWorkImplementation%3B8D2E6C0377.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CCOThreadWorkImplementation%999108313
      CCOThreadWorkImplementation (ICOAsyncImplementation* p_pContext, const CString& p_sName, const UINT p_uiStackSize = 0);

    //## Destructor (generated)
      virtual ~CCOThreadWorkImplementation();


    //## Other Operations (specified)
      //## Operation: AddCommand%999280845
      //	DESCRIPTION
      //	Adds an asynchronous command to the command queue of the
      //	worker thread
      //
      //	RETURNS
      //	void
      virtual void AddCommand (CCOCommand* p_pCommand, const ECOAsyncCallQueue p_ePriority, const bool p_bUniqCommand = false);

      //## Operation: SuspendCommandQueue%1000752290
      //	DESCRIPTION
      //	Suspends the specified command queue. Incoming calls
      //	will be stored in the queue but not executed.
      //
      //	PARAMETER
      //	Queue specifier
      //
      //	RETURNS
      //	void
      virtual void SuspendCommandQueue (const ECOAsyncCallQueue p_eQueue);

      //## Operation: ResumeCommandQueue%1000752291
      //	DESCRIPTION
      //	Resumes the specified command queue. Commands delayed in
      //	the queue will be executed immediately
      //
      //	PARAMETER
      //	Queue specifier
      //
      //	RETURNS
      //	void
      virtual void ResumeCommandQueue (const ECOAsyncCallQueue p_eQueue);

      //## Operation: FlushCommandQueue%1000752292
      //	DESCRIPTION
      //	Flushes the specified command queue. All commands
      //	remaining in the queue will be deleted and with an
      //	exception  to the client signalled
      //
      //	PARAMETER
      //	Queue specifier
      //
      //	RETURNS
      //	void
      virtual void FlushCommandQueue (const ECOAsyncCallQueue p_eQueue);

      //## Operation: WaitOnActionDone%1001017247
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
      virtual ECOInterruptReason WaitOnActionDone (CCOSyncObjectArray* p_pSyncArray, const DWORD p_dwWakeUpMask = CO_WAKE_MASK_DEFAULT, const DWORD p_dwTimeout = INFINITE, UINT& p_uiSignalledIndex = *((UINT*)NULL));

      //## Operation: StartTimer%1053348759
      virtual void StartTimer (UINT p_uiInterval);

      //## Operation: StopTimer%1053348760
      virtual void StopTimer ();

      //## Operation: OnTimer%1053348757
      virtual void OnTimer ();

    // Additional Public Declarations
      //## begin CCOThreadWorkImplementation%3B8D2E6C0377.public preserve=yes
      //## end CCOThreadWorkImplementation%3B8D2E6C0377.public

  protected:

    //## Other Operations (specified)
      //## Operation: ThreadMain%999108314
      virtual int ThreadMain ();

      //## Operation: WaitForEvent%999108316
      virtual ECOAsyncThreadWakeUpReason WaitForEvent (CArray<CSyncObject*, CSyncObject*>* p_pSyncArray, const DWORD p_dwTimeout = INFINITE, UINT& p_uiSignalledIndex = *((UINT*)NULL));

      //## Operation: BuildStandardSyncArray%999108317
      virtual CArray<CSyncObject*, CSyncObject*>* BuildStandardSyncArray ();

      //## Operation: DispatchCommand%999108318
      virtual void DispatchCommand (const ECOAsyncCallQueue p_eCommandQueue);

    // Additional Protected Declarations
      //## begin CCOThreadWorkImplementation%3B8D2E6C0377.protected preserve=yes
      //## end CCOThreadWorkImplementation%3B8D2E6C0377.protected

  private:
    //## Constructors (generated)
      CCOThreadWorkImplementation();

      CCOThreadWorkImplementation(const CCOThreadWorkImplementation &right);

    //## Assignment Operation (generated)
      const CCOThreadWorkImplementation & operator=(const CCOThreadWorkImplementation &right);

    //## Equality Operations (generated)
      bool operator==(const CCOThreadWorkImplementation &right) const;

      bool operator!=(const CCOThreadWorkImplementation &right) const;

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69AA7027E
      //## Role: CCOThreadWorkImplementation::pContext%3DA69AA80185
      //## begin CCOThreadWorkImplementation::pContext%3DA69AA80185.role preserve=no  public: ICOAsyncImplementation {1..1 -> 1..1RFHN}
      ICOAsyncImplementation *m_pContext;
      //## end CCOThreadWorkImplementation::pContext%3DA69AA80185.role

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69AE601F1
      //## Role: CCOThreadWorkImplementation::DummyEvent%3DA69AE700B9
      //## begin CCOThreadWorkImplementation::DummyEvent%3DA69AE700B9.role preserve=no  public: CEvent {1..1 -> 1..1VFHN}
      CEvent m_DummyEvent;
      //## end CCOThreadWorkImplementation::DummyEvent%3DA69AE700B9.role

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69E280155
      //## Role: CCOThreadWorkImplementation::QueueEvents%3DA69E280388
      //## Constraints:
      //	ordered
      //## begin CCOThreadWorkImplementation::QueueEvents%3DA69E280388.role preserve=no  public: CEvent {0 -> nRFHON}
      CTypedPtrArray<CPtrArray,CEvent*> m_QueueEvents;
      //## end CCOThreadWorkImplementation::QueueEvents%3DA69E280388.role

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69E670378
      //## Role: CCOThreadWorkImplementation::CommandQueues%3DA69E6801F2
      //## Constraints:
      //	ordered
      //## begin CCOThreadWorkImplementation::CommandQueues%3DA69E6801F2.role preserve=no  public: CCOCommandQueue {0 -> nRFHON}
      CTypedPtrArray<CPtrArray,CCOCommandQueue*> m_CommandQueues;
      //## end CCOThreadWorkImplementation::CommandQueues%3DA69E6801F2.role

      //## Association: EBCO (Core Classes)::<unnamed>%3EC8D30002F1
      //## Role: CCOThreadWorkImplementation::pTimer%3EC8D301015C
      //## begin CCOThreadWorkImplementation::pTimer%3EC8D301015C.role preserve=no  public: CCOThreadTimer {1..1 -> 1..1RFHN}
      CCOThreadTimer *m_pTimer;
      //## end CCOThreadWorkImplementation::pTimer%3EC8D301015C.role

      //## Association: EBCO (Core Classes)::<unnamed>%3EC8DA860071
      //## Role: CCOThreadWorkImplementation::TimerAccessLock%3EC8DA8603DD
      //## begin CCOThreadWorkImplementation::TimerAccessLock%3EC8DA8603DD.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_TimerAccessLock;
      //## end CCOThreadWorkImplementation::TimerAccessLock%3EC8DA8603DD.role

    // Additional Private Declarations
      //## begin CCOThreadWorkImplementation%3B8D2E6C0377.private preserve=yes
      //## end CCOThreadWorkImplementation%3B8D2E6C0377.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOThreadWorkImplementation%3B8D2E6C0377.implementation preserve=yes
      //## end CCOThreadWorkImplementation%3B8D2E6C0377.implementation

};

//## begin CCOThreadWorkImplementation%3B8D2E6C0377.postscript preserve=yes
//## end CCOThreadWorkImplementation%3B8D2E6C0377.postscript

// Class CCOThreadWorkImplementation 

//## begin module%3B8D2E9A0002.epilog preserve=yes
//## end module%3B8D2E9A0002.epilog


#endif
