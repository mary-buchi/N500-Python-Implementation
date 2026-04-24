//## begin module%3B86D1D001C3.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B86D1D001C3.cm

//## begin module%3B86D1D001C3.cp preserve=no
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
//## end module%3B86D1D001C3.cp

//## Module: EBCOthrd%3B86D1D001C3; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOthrd.h

#ifndef EBCOthrd_h
#define EBCOthrd_h 1

//## begin module%3B86D1D001C3.additionalIncludes preserve=no
//## end module%3B86D1D001C3.additionalIncludes

//## begin module%3B86D1D001C3.includes preserve=yes
//## end module%3B86D1D001C3.includes

// EBCOsypr
#include "EBCOsypr.h"

class EBCO_DLL_DECL CCOSyncObject;

//## begin module%3B86D1D001C3.declarations preserve=no
//## end module%3B86D1D001C3.declarations

//## begin module%3B86D1D001C3.additionalDeclarations preserve=yes
//## end module%3B86D1D001C3.additionalDeclarations


//## begin ICOThread%3B8AB1B0035A.preface preserve=yes
//## end ICOThread%3B8AB1B0035A.preface

//## Class: ICOThread%3B8AB1B0035A
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BAE28B2033C;XCOExceptionErrorNative { -> }
//## Uses: <unnamed>%3BAE28BB0122; { -> }
//## Uses: <unnamed>%3BAE28C2019A; { -> }
//## Uses: <unnamed>%3DA3C17E00B1;CO_IDENTIFIERS { -> }
//## Uses: <unnamed>%3DA3C1E4015D;CO_EXCEPTIONS { -> }

class EBCO_DLL_DECL ICOThread : public CWinThread  //## Inherits: <unnamed>%3B8AB1F603E7
{
  //## begin ICOThread%3B8AB1B0035A.initialDeclarations preserve=yes
  //## end ICOThread%3B8AB1B0035A.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: ICOThread%998945406
      ICOThread (const CString& p_sName, const INT p_iPriority = THREAD_PRIORITY_NORMAL, const UINT p_uiStackSize = 0);

    //## Destructor (generated)
      virtual ~ICOThread();


    //## Other Operations (specified)
      //## Operation: TranslateException%1001268500
      //	DESCRIPTION
      //	Handles Win32 exceptions (C structured exceptions) as
      //	C++ typed exceptions.
      static void TranslateException (unsigned int p_uiExceptionCode, EXCEPTION_POINTERS*  p_pExceptionInfo);

      //## Operation: TerminateThread%999108315
      virtual void TerminateThread ();

      //## Operation: Start%1037192862
      //	Starts the worker thread. The returned sync object can
      //	be used to synchronize with the thread when it enters
      //	its main function.
      virtual CCOSyncObject* Start ();

    // Additional Public Declarations
      //## begin ICOThread%3B8AB1B0035A.public preserve=yes
      //## end ICOThread%3B8AB1B0035A.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: bRunning%3E82CF650167
      //## begin ICOThread::bRunning%3E82CF650167.attr preserve=no  protected: bool {U} false
      bool m_bRunning;
      //## end ICOThread::bRunning%3E82CF650167.attr

      //## Attribute: iPriority%3FCAF0EA002D
      //## begin ICOThread::iPriority%3FCAF0EA002D.attr preserve=no  protected: int {U} p_iPriority
      int m_iPriority;
      //## end ICOThread::iPriority%3FCAF0EA002D.attr

    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3B8AB222014B
      //## Role: ICOThread::sName%3B8AB2220341
      //## begin ICOThread::sName%3B8AB2220341.role preserve=no  public: CString {1..1 -> 1..1VHN}
      CString m_sName;
      //## end ICOThread::sName%3B8AB2220341.role

      //## Association: EBCO (Core Classes)::<unnamed>%3B8D395C0319
      //## Role: ICOThread::TerminationEvent%3B8D395D0113
      //## begin ICOThread::TerminationEvent%3B8D395D0113.role preserve=no  public: CEvent {1..1 -> 1..1VHN}
      CEvent m_TerminationEvent;
      //## end ICOThread::TerminationEvent%3B8D395D0113.role

      //## Association: EBCO (Core Classes)::<unnamed>%3DD24EE20300
      //## Role: ICOThread::uiStackSize%3DD24EE3012C
      //## begin ICOThread::uiStackSize%3DD24EE3012C.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiStackSize;
      //## end ICOThread::uiStackSize%3DD24EE3012C.role

      //## Association: EBCO (Core Classes)::<unnamed>%4030AFA602CA
      //## Role: ICOThread::pStartupSyncObj%4030AFA7015A
      //## begin ICOThread::pStartupSyncObj%4030AFA7015A.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pStartupSyncObj;
      //## end ICOThread::pStartupSyncObj%4030AFA7015A.role

    // Additional Protected Declarations
      //## begin ICOThread%3B8AB1B0035A.protected preserve=yes
      //## end ICOThread%3B8AB1B0035A.protected

  private:
    //## Constructors (generated)
      ICOThread();

      ICOThread(const ICOThread &right);

    //## Assignment Operation (generated)
      const ICOThread & operator=(const ICOThread &right);

    //## Equality Operations (generated)
      bool operator==(const ICOThread &right) const;

      bool operator!=(const ICOThread &right) const;

    // Additional Private Declarations
      //## begin ICOThread%3B8AB1B0035A.private preserve=yes
      //## end ICOThread%3B8AB1B0035A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin ICOThread%3B8AB1B0035A.implementation preserve=yes
      //## end ICOThread%3B8AB1B0035A.implementation

};

//## begin ICOThread%3B8AB1B0035A.postscript preserve=yes
//## end ICOThread%3B8AB1B0035A.postscript

//## begin ICOThreadWork%3B86D25701E5.preface preserve=yes
//## end ICOThreadWork%3B86D25701E5.preface

//## Class: ICOThreadWork%3B86D25701E5
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL ICOThreadWork : public ICOThread  //## Inherits: <unnamed>%3B8AB1F2014C
{
  //## begin ICOThreadWork%3B86D25701E5.initialDeclarations preserve=yes
  //## end ICOThreadWork%3B86D25701E5.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: ICOThreadWork%998945407
      ICOThreadWork (const CString& p_sName, const INT p_iPriority = THREAD_PRIORITY_NORMAL, const UINT p_uiStackSize = 0);

    //## Destructor (generated)
      virtual ~ICOThreadWork();


    //## Other Operations (specified)
      //## Operation: InitInstance%998945410; C++
      //	running and idle processing
      virtual BOOL InitInstance ();

      //## Operation: ThreadMain%998945411
      virtual int ThreadMain () = 0;

    // Additional Public Declarations
      //## begin ICOThreadWork%3B86D25701E5.public preserve=yes
      //## end ICOThreadWork%3B86D25701E5.public

  protected:
    // Additional Protected Declarations
      //## begin ICOThreadWork%3B86D25701E5.protected preserve=yes
      //## end ICOThreadWork%3B86D25701E5.protected

  private:
    //## Constructors (generated)
      ICOThreadWork();

      ICOThreadWork(const ICOThreadWork &right);

    //## Assignment Operation (generated)
      const ICOThreadWork & operator=(const ICOThreadWork &right);

    //## Equality Operations (generated)
      bool operator==(const ICOThreadWork &right) const;

      bool operator!=(const ICOThreadWork &right) const;


    //## Other Operations (specified)
      //## Operation: Run%998945409; C++
      virtual int Run ();

    // Additional Private Declarations
      //## begin ICOThreadWork%3B86D25701E5.private preserve=yes
      //## end ICOThreadWork%3B86D25701E5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin ICOThreadWork%3B86D25701E5.implementation preserve=yes
      //## end ICOThreadWork%3B86D25701E5.implementation

};

//## begin ICOThreadWork%3B86D25701E5.postscript preserve=yes
//## end ICOThreadWork%3B86D25701E5.postscript

//## begin CCOSyncObjectView%3B9B500301B4.preface preserve=yes
//## end CCOSyncObjectView%3B9B500301B4.preface

//## Class: CCOSyncObjectView%3B9B500301B4; Instantiated Class
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef CCOSyncObjectParameterizedByRef< CDialog* > CCOSyncObjectView;

//## begin CCOSyncObjectView%3B9B500301B4.postscript preserve=yes
//## end CCOSyncObjectView%3B9B500301B4.postscript

// Class ICOThread 

// Class ICOThreadWork 

//## begin CCOSyncObjectView.instantiation preserve=no
template class CCOSyncObjectParameterizedByRef< CDialog* >;
//## end CCOSyncObjectView.instantiation
//## begin module%3B86D1D001C3.epilog preserve=yes
//## end module%3B86D1D001C3.epilog


#endif
