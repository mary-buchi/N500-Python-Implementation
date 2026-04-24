//## begin module%3DA53C1D0326.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA53C1D0326.cm

//## begin module%3DA53C1D0326.cp preserve=no
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
//## end module%3DA53C1D0326.cp

//## Module: EBETwrit%3DA53C1D0326; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETwrit.h

#ifndef EBETwrit_h
#define EBETwrit_h 1

//## begin module%3DA53C1D0326.additionalIncludes preserve=no
//## end module%3DA53C1D0326.additionalIncludes

//## begin module%3DA53C1D0326.includes preserve=yes
//## end module%3DA53C1D0326.includes

// EBETthrd
#include "EBETthrd.h"

class CETChannelMessageEnvoy;
class CETChannel;

//## begin module%3DA53C1D0326.declarations preserve=no
//## end module%3DA53C1D0326.declarations

//## begin module%3DA53C1D0326.additionalDeclarations preserve=yes
//## end module%3DA53C1D0326.additionalDeclarations


//## begin XETExceptionConnectionLost%3F6F5546039D.preface preserve=yes
//## end XETExceptionConnectionLost%3F6F5546039D.preface

//## Class: XETExceptionConnectionLost%3F6F5546039D
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class XETExceptionConnectionLost : public CException  //## Inherits: <unnamed>%3F6F556E00A2
{
  //## begin XETExceptionConnectionLost%3F6F5546039D.initialDeclarations preserve=yes
  //## end XETExceptionConnectionLost%3F6F5546039D.initialDeclarations

  public:
    //## Constructors (generated)
      XETExceptionConnectionLost();

    //## Destructor (generated)
      virtual ~XETExceptionConnectionLost();

    // Additional Public Declarations
      //## begin XETExceptionConnectionLost%3F6F5546039D.public preserve=yes
      //## end XETExceptionConnectionLost%3F6F5546039D.public

  protected:
    // Additional Protected Declarations
      //## begin XETExceptionConnectionLost%3F6F5546039D.protected preserve=yes
      //## end XETExceptionConnectionLost%3F6F5546039D.protected

  private:
    //## Constructors (generated)
      XETExceptionConnectionLost(const XETExceptionConnectionLost &right);

    //## Assignment Operation (generated)
      const XETExceptionConnectionLost & operator=(const XETExceptionConnectionLost &right);

    //## Equality Operations (generated)
      bool operator==(const XETExceptionConnectionLost &right) const;

      bool operator!=(const XETExceptionConnectionLost &right) const;

    // Additional Private Declarations
      //## begin XETExceptionConnectionLost%3F6F5546039D.private preserve=yes
      //## end XETExceptionConnectionLost%3F6F5546039D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin XETExceptionConnectionLost%3F6F5546039D.implementation preserve=yes
      //## end XETExceptionConnectionLost%3F6F5546039D.implementation

};

//## begin XETExceptionConnectionLost%3F6F5546039D.postscript preserve=yes
//## end XETExceptionConnectionLost%3F6F5546039D.postscript

//## begin CETChannelWriter%3DA53BEC022C.preface preserve=yes
//## end CETChannelWriter%3DA53BEC022C.preface

//## Class: CETChannelWriter%3DA53BEC022C
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DA7D3CB031D;CETChannelMessage { -> }
//## Uses: <unnamed>%3DA7D3D202F5;CCOSyncObject { -> }
//## Uses: <unnamed>%3F6F557702D5;XETExceptionConnectionLost { -> }
//## Uses: <unnamed>%40642EC8001F;XCOExceptionErrorMemoryAllocation { -> }

class CETChannelWriter : public CETThread  //## Inherits: <unnamed>%3DA53BF80113
{
  //## begin CETChannelWriter%3DA53BEC022C.initialDeclarations preserve=yes
  //## end CETChannelWriter%3DA53BEC022C.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelWriter%1034230440
      CETChannelWriter (CETChannel* p_pContext, const CString& p_sName, SOCKET p_hSocket);

    //## Destructor (generated)
      virtual ~CETChannelWriter();


    //## Other Operations (specified)
      //## Operation: AddMessage%1034230441
      virtual void AddMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: AddIncidentMessage%1037346552
      virtual void AddIncidentMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: RemoveIncidentMessage%1037346555
      virtual void RemoveIncidentMessage (UINT p_uiObjRefID);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: bDisconnected%3F6F57D0022F
      BOOL GetbDisconnected ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA53C4A019F
      //## Role: CETChannelWriter::hSocket%3DA53C4B0048
      SOCKET GethSocket ();

    // Additional Public Declarations
      //## begin CETChannelWriter%3DA53BEC022C.public preserve=yes
      //## end CETChannelWriter%3DA53BEC022C.public

  protected:

    //## Other Operations (specified)
      //## Operation: ThreadMain%1034230442
      virtual DWORD ThreadMain ();

      //## Operation: NewMessages%1034230443
      virtual void NewMessages ();

      //## Operation: ProcessSignalledMessage%1034329221
      virtual void ProcessSignalledMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: ProcessSignalledIncidentMessage%1037346553
      virtual void ProcessSignalledIncidentMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: CreateWaitHandleArray%1034407670
      virtual INT CreateWaitHandleArray (HANDLE*& p_hArray, CTypedPtrArray<CPtrArray, CETChannelMessageEnvoy*>& p_LinkedMessages, INT& p_iIncidentStartIndex);

    // Additional Protected Declarations
      //## begin CETChannelWriter%3DA53BEC022C.protected preserve=yes
      //## end CETChannelWriter%3DA53BEC022C.protected

  private:
    //## Constructors (generated)
      CETChannelWriter();

      CETChannelWriter(const CETChannelWriter &right);

    //## Assignment Operation (generated)
      const CETChannelWriter & operator=(const CETChannelWriter &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelWriter &right) const;

      bool operator!=(const CETChannelWriter &right) const;

    // Data Members for Class Attributes

      //## Attribute: dwWaitIndexNewMessage%3DA7F08F0069
      //## begin CETChannelWriter::dwWaitIndexNewMessage%3DA7F08F0069.attr preserve=no  private: DWORD {UC} 0
      const DWORD  m_dwWaitIndexNewMessage;
      //## end CETChannelWriter::dwWaitIndexNewMessage%3DA7F08F0069.attr

      //## Attribute: dwWaitIndexTermination%3DA7F0D2023C
      //## begin CETChannelWriter::dwWaitIndexTermination%3DA7F0D2023C.attr preserve=no  private: DWORD {UC} 1
      const DWORD  m_dwWaitIndexTermination;
      //## end CETChannelWriter::dwWaitIndexTermination%3DA7F0D2023C.attr

      //## Attribute: dwWaitIndexStartMessageSignalled%3DA7F0E30074
      //## begin CETChannelWriter::dwWaitIndexStartMessageSignalled%3DA7F0E30074.attr preserve=no  private: DWORD {UC} 2
      const DWORD  m_dwWaitIndexStartMessageSignalled;
      //## end CETChannelWriter::dwWaitIndexStartMessageSignalled%3DA7F0E30074.attr

      //## begin CETChannelWriter::bDisconnected%3F6F57D0022F.attr preserve=no  public: BOOL {U} false
      BOOL m_bDisconnected;
      //## end CETChannelWriter::bDisconnected%3F6F57D0022F.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA53C4A019F
      //## begin CETChannelWriter::hSocket%3DA53C4B0048.role preserve=no  public: SOCKET {1..1 -> 1..1VFHN}
      SOCKET m_hSocket;
      //## end CETChannelWriter::hSocket%3DA53C4B0048.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA53CA400B5
      //## Role: CETChannelWriter::hMessageEvent%3DA53CA40375
      //## begin CETChannelWriter::hMessageEvent%3DA53CA40375.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hMessageEvent;
      //## end CETChannelWriter::hMessageEvent%3DA53CA40375.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA53CBD0384
      //## Role: CETChannelWriter::MessageList%3DA53CBE01FE
      //## begin CETChannelWriter::MessageList%3DA53CBE01FE.role preserve=no  public: CETChannelMessageEnvoy {0 -> nRFHN}
      CTypedPtrList<CPtrList, CETChannelMessageEnvoy*> m_MessageList;
      //## end CETChannelWriter::MessageList%3DA53CBE01FE.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA53CDE027A
      //## Role: CETChannelWriter::MessageLock%3DA53CDF0087
      //## begin CETChannelWriter::MessageLock%3DA53CDF0087.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_MessageLock;
      //## end CETChannelWriter::MessageLock%3DA53CDF0087.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA5406C023C
      //## Role: CETChannelWriter::pContext%3DA5406D0067
      //## begin CETChannelWriter::pContext%3DA5406D0067.role preserve=no  public: CETChannel {1..1 -> 1..1RFHN}
      CETChannel *m_pContext;
      //## end CETChannelWriter::pContext%3DA5406D0067.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DD4A93100D1
      //## Role: CETChannelWriter::IncidentMessageList%3DD4A9310343
      //## begin CETChannelWriter::IncidentMessageList%3DD4A9310343.role preserve=no  public: CETChannelMessageEnvoy {0 -> nRFHN}
      CTypedPtrList<CPtrList, CETChannelMessageEnvoy*> m_IncidentMessageList;
      //## end CETChannelWriter::IncidentMessageList%3DD4A9310343.role

    // Additional Private Declarations
      //## begin CETChannelWriter%3DA53BEC022C.private preserve=yes
      //## end CETChannelWriter%3DA53BEC022C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelWriter%3DA53BEC022C.implementation preserve=yes
      //## end CETChannelWriter%3DA53BEC022C.implementation

};

//## begin CETChannelWriter%3DA53BEC022C.postscript preserve=yes
//## end CETChannelWriter%3DA53BEC022C.postscript

// Class XETExceptionConnectionLost 

// Class CETChannelWriter 

//## begin module%3DA53C1D0326.epilog preserve=yes
//## end module%3DA53C1D0326.epilog


#endif
