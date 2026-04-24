//## begin module%3F6CA80A036B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F6CA80A036B.cm

//## begin module%3F6CA80A036B.cp preserve=no
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
//## end module%3F6CA80A036B.cp

//## Module: EBETsmon%3F6CA80A036B; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETsmon.h

#ifndef EBETsmon_h
#define EBETsmon_h 1

//## begin module%3F6CA80A036B.additionalIncludes preserve=no
//## end module%3F6CA80A036B.additionalIncludes

//## begin module%3F6CA80A036B.includes preserve=yes
//## end module%3F6CA80A036B.includes

// EBETthrd
#include "EBETthrd.h"
// EBCOsmon
#include "EBCOsmon.h"

class CETSystemMonitorMessage;
class EBCO_DLL_DECL CCOSyncObject;

//## begin module%3F6CA80A036B.declarations preserve=no
//## end module%3F6CA80A036B.declarations

//## begin module%3F6CA80A036B.additionalDeclarations preserve=yes
//## end module%3F6CA80A036B.additionalDeclarations


//## begin CETSystemMonitor%3F6CA7AD024F.preface preserve=yes
//## end CETSystemMonitor%3F6CA7AD024F.preface

//## Class: CETSystemMonitor%3F6CA7AD024F
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETSystemMonitor : public CETThread, //## Inherits: <unnamed>%3F6CA7F50357
                            	public CCOSystemMonitorInterface  //## Inherits: <unnamed>%3F708DA30089
{
  //## begin CETSystemMonitor%3F6CA7AD024F.initialDeclarations preserve=yes
  //## end CETSystemMonitor%3F6CA7AD024F.initialDeclarations

  public:
    //## Constructors (generated)
      CETSystemMonitor();

    //## Destructor (generated)
      virtual ~CETSystemMonitor();


    //## Other Operations (specified)
      //## Operation: Create%1064085910
      static void Create ();

      //## Operation: Delete%1064085911
      static void Delete ();

      //## Operation: GetInstance%1064085912
      static CETSystemMonitor* GetInstance ();

      //## Operation: Initialize%1064085914
      void Initialize ();

      //## Operation: AddMessage%1064258348
      virtual void AddMessage (const CString& p_sUnitID, const CString& p_sMessage);

      //## Operation: FlushQueue%1084342562
      virtual void FlushQueue ();

    // Additional Public Declarations
      //## begin CETSystemMonitor%3F6CA7AD024F.public preserve=yes
      //## end CETSystemMonitor%3F6CA7AD024F.public

  protected:

    //## Other Operations (specified)
      //## Operation: ThreadMain%1064085913
      virtual DWORD ThreadMain ();

      //## Operation: AcceptListener%1064085915
      virtual void AcceptListener ();

    // Additional Protected Declarations
      //## begin CETSystemMonitor%3F6CA7AD024F.protected preserve=yes
      //## end CETSystemMonitor%3F6CA7AD024F.protected

  private:
    //## Constructors (generated)
      CETSystemMonitor(const CETSystemMonitor &right);

    //## Assignment Operation (generated)
      const CETSystemMonitor & operator=(const CETSystemMonitor &right);

    //## Equality Operations (generated)
      bool operator==(const CETSystemMonitor &right) const;

      bool operator!=(const CETSystemMonitor &right) const;


    //## Other Operations (specified)
      //## Operation: ProcessMessages%1064258349
      void ProcessMessages ();

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F6CA82F0093
      //## Role: CETSystemMonitor::pInstance%3F6CA8300064
      //## begin CETSystemMonitor::pInstance%3F6CA8300064.role preserve=no  public: static CETSystemMonitor {1..1 -> 1..1RFHN}
      static CETSystemMonitor *m_pInstance;
      //## end CETSystemMonitor::pInstance%3F6CA8300064.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F6CA8CD014F
      //## Role: CETSystemMonitor::Listeners%3F6CA8CD0377
      //## begin CETSystemMonitor::Listeners%3F6CA8CD0377.role preserve=no  public: SOCKET {0 -> nVFHN}
      CList<SOCKET, SOCKET> m_Listeners;
      //## end CETSystemMonitor::Listeners%3F6CA8CD0377.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F6CA8F90062
      //## Role: CETSystemMonitor::hSocketEvent%3F6CA8F902DA
      //## begin CETSystemMonitor::hSocketEvent%3F6CA8F902DA.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hSocketEvent;
      //## end CETSystemMonitor::hSocketEvent%3F6CA8F902DA.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F6CA90E0170
      //## Role: CETSystemMonitor::hMessageEvent%3F6CA90E02D0
      //## begin CETSystemMonitor::hMessageEvent%3F6CA90E02D0.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hMessageEvent;
      //## end CETSystemMonitor::hMessageEvent%3F6CA90E02D0.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F6CA96F0148
      //## Role: CETSystemMonitor::QueueLock%3F6CA96F02ED
      //## begin CETSystemMonitor::QueueLock%3F6CA96F02ED.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_QueueLock;
      //## end CETSystemMonitor::QueueLock%3F6CA96F02ED.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F6CAA9E0144
      //## Role: CETSystemMonitor::hSocket%3F6CAA9E0374
      //## begin CETSystemMonitor::hSocket%3F6CAA9E0374.role preserve=no  public: SOCKET {1..1 -> 1..1VFHN}
      SOCKET m_hSocket;
      //## end CETSystemMonitor::hSocket%3F6CAA9E0374.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F6CAB0102CC
      //## Role: CETSystemMonitor::uiPortNo%3F6CAB020062
      //## begin CETSystemMonitor::uiPortNo%3F6CAB020062.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiPortNo;
      //## end CETSystemMonitor::uiPortNo%3F6CAB020062.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F6CAEAD0242
      //## Role: CETSystemMonitor::Messages%3F6CAEAE0104
      //## begin CETSystemMonitor::Messages%3F6CAEAE0104.role preserve=no  public: CETSystemMonitorMessage {0 -> nRFHN}
      CTypedPtrList<CPtrList, CETSystemMonitorMessage*> m_Messages;
      //## end CETSystemMonitor::Messages%3F6CAEAE0104.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%40A1C24802F3
      //## Role: CETSystemMonitor::pQueueFlushSyncObj%40A1C249016D
      //## begin CETSystemMonitor::pQueueFlushSyncObj%40A1C249016D.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pQueueFlushSyncObj;
      //## end CETSystemMonitor::pQueueFlushSyncObj%40A1C249016D.role

    // Additional Private Declarations
      //## begin CETSystemMonitor%3F6CA7AD024F.private preserve=yes
      //## end CETSystemMonitor%3F6CA7AD024F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETSystemMonitor%3F6CA7AD024F.implementation preserve=yes
      //## end CETSystemMonitor%3F6CA7AD024F.implementation

};

//## begin CETSystemMonitor%3F6CA7AD024F.postscript preserve=yes
//## end CETSystemMonitor%3F6CA7AD024F.postscript

//## begin CETSystemMonitorMessage%3F6CAE3501D1.preface preserve=yes
//## end CETSystemMonitorMessage%3F6CAE3501D1.preface

//## Class: CETSystemMonitorMessage%3F6CAE3501D1
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETSystemMonitorMessage 
{
  //## begin CETSystemMonitorMessage%3F6CAE3501D1.initialDeclarations preserve=yes
  //## end CETSystemMonitorMessage%3F6CAE3501D1.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETSystemMonitorMessage%1064258347
      CETSystemMonitorMessage (const CString& p_sUnitID, const CString& p_sMessage);

    //## Destructor (generated)
      virtual ~CETSystemMonitorMessage();


    //## Other Operations (specified)
      //## Operation: Serialize%1064258350
      void Serialize (BYTE*& p_pbyBuffer, DWORD& p_dwSize);

      //## Operation: Trace%1064258351
      void Trace ();

    // Additional Public Declarations
      //## begin CETSystemMonitorMessage%3F6CAE3501D1.public preserve=yes
      //## end CETSystemMonitorMessage%3F6CAE3501D1.public

  protected:
    // Additional Protected Declarations
      //## begin CETSystemMonitorMessage%3F6CAE3501D1.protected preserve=yes
      //## end CETSystemMonitorMessage%3F6CAE3501D1.protected

  private:
    //## Constructors (generated)
      CETSystemMonitorMessage();

      CETSystemMonitorMessage(const CETSystemMonitorMessage &right);

    //## Assignment Operation (generated)
      const CETSystemMonitorMessage & operator=(const CETSystemMonitorMessage &right);

    //## Equality Operations (generated)
      bool operator==(const CETSystemMonitorMessage &right) const;

      bool operator!=(const CETSystemMonitorMessage &right) const;

    // Data Members for Class Attributes

      //## Attribute: sUnitID%3F6CAE530026
      //## begin CETSystemMonitorMessage::sUnitID%3F6CAE530026.attr preserve=no  private: CString {U} p_sUnitID
      CString m_sUnitID;
      //## end CETSystemMonitorMessage::sUnitID%3F6CAE530026.attr

      //## Attribute: sTimeStamp%3F6F4C69026E
      //## begin CETSystemMonitorMessage::sTimeStamp%3F6F4C69026E.attr preserve=no  private: CString {U} 
      CString m_sTimeStamp;
      //## end CETSystemMonitorMessage::sTimeStamp%3F6F4C69026E.attr

      //## Attribute: sMessage%3F6F4CAF0016
      //## begin CETSystemMonitorMessage::sMessage%3F6F4CAF0016.attr preserve=no  private: CString {U} p_sMessage
      CString m_sMessage;
      //## end CETSystemMonitorMessage::sMessage%3F6F4CAF0016.attr

    // Additional Private Declarations
      //## begin CETSystemMonitorMessage%3F6CAE3501D1.private preserve=yes
      //## end CETSystemMonitorMessage%3F6CAE3501D1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETSystemMonitorMessage%3F6CAE3501D1.implementation preserve=yes
      //## end CETSystemMonitorMessage%3F6CAE3501D1.implementation

};

//## begin CETSystemMonitorMessage%3F6CAE3501D1.postscript preserve=yes
//## end CETSystemMonitorMessage%3F6CAE3501D1.postscript

// Class CETSystemMonitor 

// Class CETSystemMonitorMessage 

//## begin module%3F6CA80A036B.epilog preserve=yes
//## end module%3F6CA80A036B.epilog


#endif
