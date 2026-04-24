//## begin module%3E7AD31C004B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E7AD31C004B.cm

//## begin module%3E7AD31C004B.cp preserve=no
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
//## end module%3E7AD31C004B.cp

//## Module: EBSTlmwk%3E7AD31C004B; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTlmwk.h

#ifndef EBSTlmwk_h
#define EBSTlmwk_h 1

//## begin module%3E7AD31C004B.additionalIncludes preserve=no
//## end module%3E7AD31C004B.additionalIncludes

//## begin module%3E7AD31C004B.includes preserve=yes
//## end module%3E7AD31C004B.includes

// EBCOthrd
#include "EBCOthrd.h"

class EBCO_DLL_DECL CCOSyncObjectArray;
class EBCO_DLL_DECL CCOSyncObject;
class CSTLimitHandler;

//## begin module%3E7AD31C004B.declarations preserve=no
//## end module%3E7AD31C004B.declarations

//## begin module%3E7AD31C004B.additionalDeclarations preserve=yes
//## end module%3E7AD31C004B.additionalDeclarations


//## begin CSTLimitWorkerThread%3E7AD30701A3.preface preserve=yes
//## end CSTLimitWorkerThread%3E7AD30701A3.preface

//## Class: CSTLimitWorkerThread%3E7AD30701A3
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E7ADC930126;CCOSyncObjectArray { -> F}
//## Uses: <unnamed>%3FBE106A0306;CSTStepperMotorImplementation { -> }
//## Uses: <unnamed>%3FBE108E0086;CSTLogic { -> }

class CSTLimitWorkerThread : public ICOThreadWork  //## Inherits: <unnamed>%3E7AD34D0135
{
  //## begin CSTLimitWorkerThread%3E7AD30701A3.initialDeclarations preserve=yes
  //## end CSTLimitWorkerThread%3E7AD30701A3.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTLimitWorkerThread%1048237047
      CSTLimitWorkerThread (CSTLimitHandler* p_pContext);

    //## Destructor (generated)
      virtual ~CSTLimitWorkerThread();


    //## Other Operations (specified)
      //## Operation: ThreadMain%1048237048
      virtual int ThreadMain ();

      //## Operation: Activate%1048237050
      CCOSyncObject* Activate ();

      //## Operation: Deactivate%1048237051
      CCOSyncObject* Deactivate ();

    // Additional Public Declarations
      //## begin CSTLimitWorkerThread%3E7AD30701A3.public preserve=yes
      //## end CSTLimitWorkerThread%3E7AD30701A3.public

  protected:
    // Additional Protected Declarations
      //## begin CSTLimitWorkerThread%3E7AD30701A3.protected preserve=yes
      //## end CSTLimitWorkerThread%3E7AD30701A3.protected

  private:
    //## Constructors (generated)
      CSTLimitWorkerThread();

      CSTLimitWorkerThread(const CSTLimitWorkerThread &right);

    //## Assignment Operation (generated)
      const CSTLimitWorkerThread & operator=(const CSTLimitWorkerThread &right);

    //## Equality Operations (generated)
      bool operator==(const CSTLimitWorkerThread &right) const;

      bool operator!=(const CSTLimitWorkerThread &right) const;


    //## Other Operations (specified)
      //## Operation: DoIdle%1048237052
      bool DoIdle ();

      //## Operation: DoLimits%1048237053
      bool DoLimits ();

    // Data Members for Class Attributes

      //## Attribute: bStarted%3E7AD6E4008A
      //## begin CSTLimitWorkerThread::bStarted%3E7AD6E4008A.attr preserve=no  private: bool {U} false
      bool m_bStarted;
      //## end CSTLimitWorkerThread::bStarted%3E7AD6E4008A.attr

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E7AD3D402BC
      //## Role: CSTLimitWorkerThread::pContext%3E7AD3D500F8
      //## begin CSTLimitWorkerThread::pContext%3E7AD3D500F8.role preserve=no  public: CSTLimitHandler {1..1 -> 1..1RFHN}
      CSTLimitHandler *m_pContext;
      //## end CSTLimitWorkerThread::pContext%3E7AD3D500F8.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3E7AD7A8005B
      //## Role: CSTLimitWorkerThread::StartEvent%3E7AD7A801E2
      //## begin CSTLimitWorkerThread::StartEvent%3E7AD7A801E2.role preserve=no  public: CEvent {1..1 -> 1..1VFHN}
      CEvent m_StartEvent;
      //## end CSTLimitWorkerThread::StartEvent%3E7AD7A801E2.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3E7AD7AA004B
      //## Role: CSTLimitWorkerThread::StopEvent%3E7AD7AA026E
      //## begin CSTLimitWorkerThread::StopEvent%3E7AD7AA026E.role preserve=no  public: CEvent {1..1 -> 1..1VFHN}
      CEvent m_StopEvent;
      //## end CSTLimitWorkerThread::StopEvent%3E7AD7AA026E.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3E7AD7B202AC
      //## Role: CSTLimitWorkerThread::AccessLock%3E7AD7B3004C
      //## begin CSTLimitWorkerThread::AccessLock%3E7AD7B3004C.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_AccessLock;
      //## end CSTLimitWorkerThread::AccessLock%3E7AD7B3004C.role

      //## Association: EBST (Stepper Motor)::<unnamed>%401E6EA302F2
      //## Role: CSTLimitWorkerThread::pCmdSyncObj%401E6EA40254
      //## begin CSTLimitWorkerThread::pCmdSyncObj%401E6EA40254.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pCmdSyncObj;
      //## end CSTLimitWorkerThread::pCmdSyncObj%401E6EA40254.role

    // Additional Private Declarations
      //## begin CSTLimitWorkerThread%3E7AD30701A3.private preserve=yes
      //## end CSTLimitWorkerThread%3E7AD30701A3.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTLimitWorkerThread%3E7AD30701A3.implementation preserve=yes
      //## end CSTLimitWorkerThread%3E7AD30701A3.implementation

};

//## begin CSTLimitWorkerThread%3E7AD30701A3.postscript preserve=yes
//## end CSTLimitWorkerThread%3E7AD30701A3.postscript

// Class CSTLimitWorkerThread 

//## begin module%3E7AD31C004B.epilog preserve=yes
//## end module%3E7AD31C004B.epilog


#endif
