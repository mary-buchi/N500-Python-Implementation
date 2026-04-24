//## begin module%3B8D3ACC0214.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B8D3ACC0214.cm

//## begin module%3B8D3ACC0214.cp preserve=no
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
//## end module%3B8D3ACC0214.cp

//## Module: EBCOimpl%3B8D3ACC0214; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOimpl.h

#ifndef EBCOimpl_h
#define EBCOimpl_h 1

//## begin module%3B8D3ACC0214.additionalIncludes preserve=no
//## end module%3B8D3ACC0214.additionalIncludes

//## begin module%3B8D3ACC0214.includes preserve=yes
//## end module%3B8D3ACC0214.includes

// EBCOimct
#include "EBCOimct.h"
// EBCOenum
#include "EBCOenum.h"

class EBCO_DLL_DECL ICOAsyncInterface;
class EBCO_DLL_DECL XCOExceptionError;
class CCOThreadWorkImplementation;
class EBCO_DLL_DECL CCOCommand;

//## begin module%3B8D3ACC0214.declarations preserve=no
//## end module%3B8D3ACC0214.declarations

//## begin module%3B8D3ACC0214.additionalDeclarations preserve=yes
//## end module%3B8D3ACC0214.additionalDeclarations


//## begin ICOAsyncImplementation%3B8D3AAC02FE.preface preserve=yes
//## end ICOAsyncImplementation%3B8D3AAC02FE.preface

//## Class: ICOAsyncImplementation%3B8D3AAC02FE
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3B8D531D0021;CCOCommand { -> F}
//## Uses: <unnamed>%3B8FEAAA0120;ECOAsyncCallQueue { -> }
//## Uses: <unnamed>%3BADBB52023A;XCOException { -> }
//## Uses: <unnamed>%3BADC67101CF; { -> }
//## Uses: <unnamed>%3BADC67D0096; { -> }
//## Uses: <unnamed>%3BADC68D039C; { -> }
//## Uses: <unnamed>%3BADC6A2012F; { -> }
//## Uses: <unnamed>%3DA6939B0339;CO_IDENTIFIERS { -> }
//## Uses: <unnamed>%3FE057C401DE;XCOExceptionError { -> F}

class EBCO_DLL_DECL ICOAsyncImplementation : public ICOStateMachineContext  //## Inherits: <unnamed>%3B913D9200B5
{
  //## begin ICOAsyncImplementation%3B8D3AAC02FE.initialDeclarations preserve=yes
  //## end ICOAsyncImplementation%3B8D3AAC02FE.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: ICOAsyncImplementation%999204134
      ICOAsyncImplementation (ICOAsyncInterface* p_pInterface);

    //## Destructor (generated)
      virtual ~ICOAsyncImplementation();


    //## Other Operations (specified)
      //## Operation: InitInstance%999280838
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

      //## Operation: ExitInstance%999280841
      //	DESCRIPTION
      //	stops the implementation's worker thread and prepares
      //	for the final cleanup
      //
      //	RETURNS
      //	void
      virtual void ExitInstance ();

      //## Operation: DispatchCommand%999108321
      //	DESCRIPTION
      //	Executes the current command
      //
      //	RETURNS
      //	void
      virtual void DispatchCommand (CCOCommand* p_pCommand);

      //## Operation: AddCommand%999280844
      //	DESCRIPTION
      //	Adds an asynchronous command to the command queue of the
      //	worker thread
      //
      //	RETURNS
      //	void
      virtual void AddCommand (CCOCommand* p_pCommand, const ECOAsyncCallQueue p_ePriority);

      //## Operation: GetsCurrentState%1000031200
      //	DESCRIPTION
      //	Returns the current state of the unit in text.
      //
      //	RETURNS
      //	State name
      virtual CString GetsCurrentState ();

      //## Operation: GetsContextID%1000925470
      //	DESCRIPTION
      //	Returns an identification of the state machine context.
      //	Used for creating and identification of exceptions.
      //
      //	RETURNS
      //	String Identifier
      virtual CString GetsContextID ();

      //## Operation: StartTimer%1053348766
      //	DESCRIPTION
      //
      //	Starts a timer sending 'OnTimer' events to the state
      //	machine. The time is in ms.
      virtual void StartTimer (UINT p_uiInterval);

      //## Operation: StopTimer%1053348767
      virtual void StopTimer ();

      //## Operation: WaitOnActionDone%1001017242
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

      //## Operation: WaitOnActionDone%1001017243
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
      virtual ECOInterruptReason WaitOnActionDone (CCOSyncObject* p_pSyncObj, const DWORD p_dwWakeUpMask = CO_WAKE_MASK_DEFAULT, const DWORD p_dwTimeout = INFINITE);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: sSubsystemID%3B8FD97801E9
      const CString GetsSubsystemID () const;

    //## Get and Set Operations for Associations (generated)

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69D4602BC
      //## Role: ICOAsyncImplementation::pInterface%3DA69D4700A9
      ICOAsyncInterface * GetpInterface ();

    // Additional Public Declarations
      //## begin ICOAsyncImplementation%3B8D3AAC02FE.public preserve=yes
      //## end ICOAsyncImplementation%3B8D3AAC02FE.public

  protected:

    //## Other Operations (specified)
      //## Operation: SuspendCommandQueue%1000752293
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

      //## Operation: ResumeCommandQueue%1000752294
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

      //## Operation: FlushCommandQueue%1000752295
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

      //## Operation: ResetWaitReasonFlags%1066286190
      //	gets called within a WaitOnActionDone by the framework
      //	to allow the specific state machine context to reset its
      //	wait reason flags such as above normal timer events or
      //	other high prio commands
      void ResetWaitReasonFlags ();

      //## Operation: HandleErrorException%1071666883
      //	returns true, if the given exception should be thrown
      //	out of the subsystem interface
      virtual bool HandleErrorException (XCOExceptionError* p_pException);

    // Data Members for Class Attributes

      //## begin ICOAsyncImplementation::sSubsystemID%3B8FD97801E9.attr preserve=no  public: CString {UC} p_pInterface->GetsSubsystemID()
      const CString  m_sSubsystemID;
      //## end ICOAsyncImplementation::sSubsystemID%3B8FD97801E9.attr

    // Additional Protected Declarations
      //## begin ICOAsyncImplementation%3B8D3AAC02FE.protected preserve=yes
      //## end ICOAsyncImplementation%3B8D3AAC02FE.protected

  private:
    //## Constructors (generated)
      ICOAsyncImplementation();

      ICOAsyncImplementation(const ICOAsyncImplementation &right);

    //## Assignment Operation (generated)
      const ICOAsyncImplementation & operator=(const ICOAsyncImplementation &right);

    //## Equality Operations (generated)
      bool operator==(const ICOAsyncImplementation &right) const;

      bool operator!=(const ICOAsyncImplementation &right) const;

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69D4602BC
      //## begin ICOAsyncImplementation::pInterface%3DA69D4700A9.role preserve=no  public: ICOAsyncInterface {1..1 -> 1..1RFHN}
      ICOAsyncInterface *m_pInterface;
      //## end ICOAsyncImplementation::pInterface%3DA69D4700A9.role

      //## Association: EBCO (Core Classes)::<unnamed>%3DA69FFB0349
      //## Role: ICOAsyncImplementation::pWorkerThread%3DA69FFC0156
      //## begin ICOAsyncImplementation::pWorkerThread%3DA69FFC0156.role preserve=no  public: CCOThreadWorkImplementation {1..1 -> 1..1RFHN}
      CCOThreadWorkImplementation *m_pWorkerThread;
      //## end ICOAsyncImplementation::pWorkerThread%3DA69FFC0156.role

    // Additional Private Declarations
      //## begin ICOAsyncImplementation%3B8D3AAC02FE.private preserve=yes
      //## end ICOAsyncImplementation%3B8D3AAC02FE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin ICOAsyncImplementation%3B8D3AAC02FE.implementation preserve=yes
      //## end ICOAsyncImplementation%3B8D3AAC02FE.implementation

};

//## begin ICOAsyncImplementation%3B8D3AAC02FE.postscript preserve=yes
//## end ICOAsyncImplementation%3B8D3AAC02FE.postscript

// Class ICOAsyncImplementation 

//## begin module%3B8D3ACC0214.epilog preserve=yes
//## end module%3B8D3ACC0214.epilog


#endif
