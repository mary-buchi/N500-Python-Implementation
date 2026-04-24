//## begin module%3DA3CC620295.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA3CC620295.cm

//## begin module%3DA3CC620295.cp preserve=no
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
//## end module%3DA3CC620295.cp

//## Module: EBETthrd%3DA3CC620295; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETthrd.h

#ifndef EBETthrd_h
#define EBETthrd_h 1

//## begin module%3DA3CC620295.additionalIncludes preserve=no
//## end module%3DA3CC620295.additionalIncludes

//## begin module%3DA3CC620295.includes preserve=yes
//## end module%3DA3CC620295.includes



//## begin module%3DA3CC620295.declarations preserve=no
//## end module%3DA3CC620295.declarations

//## begin module%3DA3CC620295.additionalDeclarations preserve=yes
//## end module%3DA3CC620295.additionalDeclarations


//## begin CETThread%3DA3CC7902A5.preface preserve=yes
//## end CETThread%3DA3CC7902A5.preface

//## Class: CETThread%3DA3CC7902A5
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%468C8A390229;CETFileLogger { -> }

class CETThread 
{
  //## begin CETThread%3DA3CC7902A5.initialDeclarations preserve=yes
  //## end CETThread%3DA3CC7902A5.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETThread%1034142080
      CETThread (const CString& p_sName);

    //## Destructor (generated)
      virtual ~CETThread();


    //## Other Operations (specified)
      //## Operation: Start%1034142083
      virtual void Start ();

      //## Operation: Terminate%1034142086
      virtual void Terminate ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: sName%3DA3CE5E02E3
      CString GetsName ();

    // Additional Public Declarations
      //## begin CETThread%3DA3CC7902A5.public preserve=yes
      //## end CETThread%3DA3CC7902A5.public

  protected:

    //## Other Operations (specified)
      //## Operation: ThreadMain%1034142081
      virtual DWORD ThreadMain () = 0;

      //## Operation: ThreadMain_%1034142082
      static DWORD ThreadMain_ (LPVOID p_Parameter);

    // Data Members for Class Attributes

      //## Attribute: dwThreadID%3DA3CD53018B
      //## begin CETThread::dwThreadID%3DA3CD53018B.attr preserve=no  private: DWORD {U} 0
      DWORD m_dwThreadID;
      //## end CETThread::dwThreadID%3DA3CD53018B.attr

      //## begin CETThread::sName%3DA3CE5E02E3.attr preserve=no  public: CString {U} p_sName
      CString m_sName;
      //## end CETThread::sName%3DA3CE5E02E3.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA3CCF202E3
      //## Role: CETThread::hTerminationEvent%3DA3CCF30238
      //## begin CETThread::hTerminationEvent%3DA3CCF30238.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hTerminationEvent;
      //## end CETThread::hTerminationEvent%3DA3CCF30238.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA3D4090237
      //## Role: CETThread::hThread%3DA3D40A0083
      //## begin CETThread::hThread%3DA3D40A0083.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hThread;
      //## end CETThread::hThread%3DA3D40A0083.role

    // Additional Protected Declarations
      //## begin CETThread%3DA3CC7902A5.protected preserve=yes
      //## end CETThread%3DA3CC7902A5.protected

  private:
    //## Constructors (generated)
      CETThread();

      CETThread(const CETThread &right);

    //## Assignment Operation (generated)
      const CETThread & operator=(const CETThread &right);

    //## Equality Operations (generated)
      bool operator==(const CETThread &right) const;

      bool operator!=(const CETThread &right) const;

    // Additional Private Declarations
      //## begin CETThread%3DA3CC7902A5.private preserve=yes
      //## end CETThread%3DA3CC7902A5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETThread%3DA3CC7902A5.implementation preserve=yes
      //## end CETThread%3DA3CC7902A5.implementation

};

//## begin CETThread%3DA3CC7902A5.postscript preserve=yes
//## end CETThread%3DA3CC7902A5.postscript

// Class CETThread 

//## begin module%3DA3CC620295.epilog preserve=yes
//## end module%3DA3CC620295.epilog


#endif
