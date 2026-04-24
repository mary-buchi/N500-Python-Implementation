//## begin module%468A41A3036C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%468A41A3036C.cm

//## begin module%468A41A3036C.cp preserve=no
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
//## end module%468A41A3036C.cp

//## Module: EBETsess%468A41A3036C; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETsess.h

#ifndef EBETsess_h
#define EBETsess_h 1

//## begin module%468A41A3036C.additionalIncludes preserve=no
//## end module%468A41A3036C.additionalIncludes

//## begin module%468A41A3036C.includes preserve=yes
//## end module%468A41A3036C.includes


class CETSession;

//## begin module%468A41A3036C.declarations preserve=no
//## end module%468A41A3036C.declarations

//## begin module%468A41A3036C.additionalDeclarations preserve=yes
//## end module%468A41A3036C.additionalDeclarations


//## begin CETSessionManager%468A41E703BA.preface preserve=yes
//## end CETSessionManager%468A41E703BA.preface

//## Class: CETSessionManager%468A41E703BA
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETSessionManager 
{
  //## begin CETSessionManager%468A41E703BA.initialDeclarations preserve=yes
  //## end CETSessionManager%468A41E703BA.initialDeclarations

  public:
    //## Destructor (generated)
      virtual ~CETSessionManager();


    //## Other Operations (specified)
      //## Operation: Create%1183443828
      static void Create ();

      //## Operation: Delete%1183443829
      static void Delete ();

      //## Operation: GetInstance%1183443830
      static CETSessionManager* GetInstance ();

      //## Operation: AddToSession%1183443831
      CETSession* AddToSession (UINT p_uiPortNo, SOCKET p_hSocket);

      //## Operation: RemoveFromSession%1183443838
      void RemoveFromSession (UINT p_uiPortNo, SOCKET p_hSocket);

      //## Operation: FindSessionBySocket%1183443832
      CETSession* FindSessionBySocket (SOCKET p_hSocket);

      //## Operation: SetPrimarySession%1183536495
      void SetPrimarySession (CETSession* p_pSession);

    // Additional Public Declarations
      //## begin CETSessionManager%468A41E703BA.public preserve=yes
      //## end CETSessionManager%468A41E703BA.public

  protected:
    // Additional Protected Declarations
      //## begin CETSessionManager%468A41E703BA.protected preserve=yes
      //## end CETSessionManager%468A41E703BA.protected

  private:
    //## Constructors (generated)
      CETSessionManager();

      CETSessionManager(const CETSessionManager &right);

    //## Assignment Operation (generated)
      const CETSessionManager & operator=(const CETSessionManager &right);

    //## Equality Operations (generated)
      bool operator==(const CETSessionManager &right) const;

      bool operator!=(const CETSessionManager &right) const;


    //## Other Operations (specified)
      //## Operation: FindOpeningSession%1183494354
      CETSession* FindOpeningSession ();

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%468A4248007A
      //## Role: CETSessionManager::pInstance%468A42490249
      //## begin CETSessionManager::pInstance%468A42490249.role preserve=no  public: static CETSessionManager { -> RFHN}
      static CETSessionManager *m_pInstance;
      //## end CETSessionManager::pInstance%468A42490249.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%468A43CB006D
      //## Role: CETSessionManager::Sessions%468A43CB02E4
      //## begin CETSessionManager::Sessions%468A43CB02E4.role preserve=no  public: CETSession {1 -> nRFHN}
      CTypedPtrList<CPtrList, CETSession*> m_Sessions;
      //## end CETSessionManager::Sessions%468A43CB02E4.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%468A66B50245
      //## Role: CETSessionManager::AccessLock%468A66B60125
      //## begin CETSessionManager::AccessLock%468A66B60125.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_AccessLock;
      //## end CETSessionManager::AccessLock%468A66B60125.role

    // Additional Private Declarations
      //## begin CETSessionManager%468A41E703BA.private preserve=yes
      //## end CETSessionManager%468A41E703BA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETSessionManager%468A41E703BA.implementation preserve=yes
      //## end CETSessionManager%468A41E703BA.implementation

};

//## begin CETSessionManager%468A41E703BA.postscript preserve=yes
//## end CETSessionManager%468A41E703BA.postscript

//## begin EETSessionState%468AB04801B5.preface preserve=yes
//## end EETSessionState%468AB04801B5.preface

//## Class: EETSessionState%468AB04801B5
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum { eOpening, eOpen, eClosing } EETSessionState;

//## begin EETSessionState%468AB04801B5.postscript preserve=yes
//## end EETSessionState%468AB04801B5.postscript

//## begin CETSession%468A41DC0011.preface preserve=yes
//## end CETSession%468A41DC0011.preface

//## Class: CETSession%468A41DC0011
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%468A5F4C0392;CETChannel { -> }
//## Uses: <unnamed>%468AC3E503A9;CPIObjectFactory { -> }
//## Uses: <unnamed>%468AC3E80128;IPISystemInterface { -> }
//## Uses: <unnamed>%468B90AB02EE;XCOException { -> }
//## Uses: <unnamed>%468BB2E3029B;CETFileLogger { -> }

class CETSession 
{
  //## begin CETSession%468A41DC0011.initialDeclarations preserve=yes
  //## end CETSession%468A41DC0011.initialDeclarations

  public:
    //## Constructors (generated)
      CETSession();

    //## Constructors (specified)
      //## Operation: CETSession%1183443839
      CETSession (bool p_bIsPrimary);

    //## Destructor (generated)
      virtual ~CETSession();


    //## Other Operations (specified)
      //## Operation: SetSocket%1183443833
      void SetSocket (UINT p_iPortNo, SOCKET p_hSocket);

      //## Operation: ContainsSocket%1183443834
      bool ContainsSocket (SOCKET p_hSocket);

      //## Operation: IsComplete%1183443836
      bool IsComplete ();

      //## Operation: RemoveSocket%1183443837
      bool RemoveSocket (SOCKET p_hSocket);

      //## Operation: IsOpening%1183494355
      bool IsOpening ();

      //## Operation: IsOpen%1183494356
      bool IsOpen ();

      //## Operation: IsClosing%1183494357
      bool IsClosing ();

      //## Operation: WaitForSession%1183704511
      void WaitForSession ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: iSessenID%468C8C4F0385
      int GetiSessenID ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%468A6A93034D
      //## Role: CETSession::bIsPrimary%468A6A9401A0
      bool GetbIsPrimary ();
      void SetbIsPrimary (bool value);

      //## Association: EBET (Ethernet Transport)::<unnamed>%468DFF5B01B6
      //## Role: CETSession::sName%468DFF5C0064
      const CString& GetsName () const;
      void SetsName (const CString& value);

    // Additional Public Declarations
      //## begin CETSession%468A41DC0011.public preserve=yes
      //## end CETSession%468A41DC0011.public

  protected:
    // Additional Protected Declarations
      //## begin CETSession%468A41DC0011.protected preserve=yes
      //## end CETSession%468A41DC0011.protected

  private:
    //## Constructors (generated)
      CETSession(const CETSession &right);

    //## Assignment Operation (generated)
      const CETSession & operator=(const CETSession &right);

    //## Equality Operations (generated)
      bool operator==(const CETSession &right) const;

      bool operator!=(const CETSession &right) const;

    // Data Members for Class Attributes

      //## Attribute: PortNumbers%468A5EEA0034
      //## begin CETSession::PortNumbers%468A5EEA0034.attr preserve=no  private: CList<UINT,UINT&> {U} 
      CList<UINT,UINT&> m_PortNumbers;
      //## end CETSession::PortNumbers%468A5EEA0034.attr

      //## Attribute: iStartTime%468AB1F90167
      //## begin CETSession::iStartTime%468AB1F90167.attr preserve=no  private: int {U} 0
      int m_iStartTime;
      //## end CETSession::iStartTime%468AB1F90167.attr

      //## begin CETSession::iSessenID%468C8C4F0385.attr preserve=no  public: int {U} 0
      int m_iSessenID;
      //## end CETSession::iSessenID%468C8C4F0385.attr

      //## Attribute: iNextSessionID%468C8C86023A
      //## begin CETSession::iNextSessionID%468C8C86023A.attr preserve=no  private: static int {U} 0
      static int m_iNextSessionID;
      //## end CETSession::iNextSessionID%468C8C86023A.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%468A42AA002B
      //## Role: CETSession::Sockets%468A42AA0343
      //## Constraints:
      //	ordered
      //## Qualifier: class%468A430B02F1; UINT
      //## begin CETSession::Sockets%468A42AA0343.role preserve=no  public: SOCKET {1 -> 1VFHON}
      CMap<UINT, UINT&, SOCKET, SOCKET&> m_Sockets;
      //## end CETSession::Sockets%468A42AA0343.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%468A5EA70272
      //## Role: CETSession::AccessLock%468A5EA8006C
      //## begin CETSession::AccessLock%468A5EA8006C.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_AccessLock;
      //## end CETSession::AccessLock%468A5EA8006C.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%468A6A93034D
      //## begin CETSession::bIsPrimary%468A6A9401A0.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bIsPrimary;
      //## end CETSession::bIsPrimary%468A6A9401A0.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%468AB0A801D4
      //## Role: CETSession::eState%468AB0A90119
      //## begin CETSession::eState%468AB0A90119.role preserve=no  public: EETSessionState {1..1 -> 1..1VHN}
      EETSessionState m_eState;
      //## end CETSession::eState%468AB0A90119.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%468DFF5B01B6
      //## begin CETSession::sName%468DFF5C0064.role preserve=no  public: CString {1..1 -> 1..1VFHN}
      CString m_sName;
      //## end CETSession::sName%468DFF5C0064.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%468E015C009B
      //## Role: CETSession::hSessionOpenEvent%468E015C0359
      //## begin CETSession::hSessionOpenEvent%468E015C0359.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hSessionOpenEvent;
      //## end CETSession::hSessionOpenEvent%468E015C0359.role

    // Additional Private Declarations
      //## begin CETSession%468A41DC0011.private preserve=yes
      //## end CETSession%468A41DC0011.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETSession%468A41DC0011.implementation preserve=yes
      //## end CETSession%468A41DC0011.implementation

};

//## begin CETSession%468A41DC0011.postscript preserve=yes
//## end CETSession%468A41DC0011.postscript

// Class CETSessionManager 

// Class CETSession 

//## begin module%468A41A3036C.epilog preserve=yes
//## end module%468A41A3036C.epilog


#endif
