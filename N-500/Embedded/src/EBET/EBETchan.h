//## begin module%3D9D88460355.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3D9D88460355.cm

//## begin module%3D9D88460355.cp preserve=no
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
//## end module%3D9D88460355.cp

//## Module: EBETchan%3D9D88460355; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchan.h

#ifndef EBETchan_h
#define EBETchan_h 1

//## begin module%3D9D88460355.additionalIncludes preserve=no
//## end module%3D9D88460355.additionalIncludes

//## begin module%3D9D88460355.includes preserve=yes
//## end module%3D9D88460355.includes

// EBETthrd
#include "EBETthrd.h"
// EBCOsypr
#include "EBCOsypr.h"
// EBCOrefc
#include "EBCOrefc.h"
// EBPItype
#include "EBPItype.h"

class CETChannelReader;
class CETChannel;
class CETChannelMessage;
class CETChannelMessageEnvoy;
class CETChannelWriter;
class CETBrowserService;
class CETClient;
class EBCO_DLL_DECL CCOSyncObject;

//## begin module%3D9D88460355.declarations preserve=no
//## end module%3D9D88460355.declarations

//## begin module%3D9D88460355.additionalDeclarations preserve=yes
//## end module%3D9D88460355.additionalDeclarations


//## begin CETChannel%3DA2F3090146.preface preserve=yes
//## end CETChannel%3DA2F3090146.preface

//## Class: CETChannel%3DA2F3090146
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DA6D4200368;CCOSyncObject { -> }
//## Uses: <unnamed>%3DA87AB0024F;XCOException { -> }
//## Uses: <unnamed>%468A4A6C03DE;CETSessionManager { -> }
//## Uses: <unnamed>%468BB22C0374;CETFileLogger { -> }
//## Uses: <unnamed>%4A1BF173038A;CPIObjectFactory { -> }
//## Uses: <unnamed>%4A1BF26E01C6;IPISystemInterface { -> }
//## Uses: <unnamed>%4A1BF2C903AF;XSYExceptionErrorDeviceBusy { -> }

class CETChannel : public CETThread  //## Inherits: <unnamed>%3DA3D2560295
{
  //## begin CETChannel%3DA2F3090146.initialDeclarations preserve=yes
  //## end CETChannel%3DA2F3090146.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannel%1034142084
      CETChannel (const CString& p_sName, const UINT p_uiPortNo);

    //## Destructor (generated)
      virtual ~CETChannel();


    //## Other Operations (specified)
      //## Operation: Initialize%1034142088
      virtual void Initialize (DWORD p_dwIPConfig);

      //## Operation: AddMessage%1034230430
      virtual void AddMessage (CETChannelMessageEnvoy* p_pMessage);

      //## Operation: FindWriter%1034230446
      virtual CETChannelWriter* FindWriter (SOCKET p_hSocket);

      //## Operation: UnwrapTelegram%1035273379
      virtual CETChannelMessage* UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength);

      //## Operation: ReaderTerminated%1164812376
      virtual void ReaderTerminated (CETChannelReader* p_pReader);

      //## Operation: TerminateConnection%1182942146
      virtual void TerminateConnection (SOCKET p_hSocket);

      //## Operation: GetPortNumbers%1183443835
      static void GetPortNumbers (CList<UINT, UINT&>& p_PortNumbers);

    // Additional Public Declarations
      //## begin CETChannel%3DA2F3090146.public preserve=yes
      //## end CETChannel%3DA2F3090146.public

  protected:

    //## Other Operations (specified)
      //## Operation: ThreadMain%1034142085
      virtual DWORD ThreadMain ();

      //## Operation: AcceptClient%1034142089
      virtual void AcceptClient ();

      //## Operation: HandleNewMessage%1034230431
      virtual void HandleNewMessage ();

      //## Operation: HandleEndedReaders%1183386645
      virtual void HandleEndedReaders ();

      //## Operation: ProcessMessage%1034230432
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: DetermineSocketEvent%1064223157
      //	Determines, whether the current socket event is a
      //	accept, or close event
      //
      //	Returns
      //	True, if it is an accept event
      virtual BOOL DetermineSocketEvent ();

      //## Operation: OnNameConnection%1182942149
      //	gives an active connection a name.
      //	if other connections with the same name exists, then
      //	these connections are shutdown and the system processes
      //	a connection lost event.
      //
      //	returns:
      //	True, if at least one connection has been terminated
      virtual void OnNameConnection (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: NameConnection%1182971545
      //	gives an active connection a name.
      //	if other connections with the same name exists, then
      //	these connections are shutdown and the system processes
      //	a connection lost event.
      //
      //	returns:
      //	True, if at least one connection has been terminated
      virtual bool NameConnection (CETChannelMessageEnvoy* p_pMsg);

    // Data Members for Class Attributes

      //## Attribute: uiPortNo%3DA3D50403DD
      //## begin CETChannel::uiPortNo%3DA3D50403DD.attr preserve=no  private: UINT {U} p_uiPortNo
      UINT m_uiPortNo;
      //## end CETChannel::uiPortNo%3DA3D50403DD.attr

      //## Attribute: uiPortNoObjCreator%3DB50428033E
      //## begin CETChannel::uiPortNoObjCreator%3DB50428033E.attr preserve=no  private: static UINT {U} 8090
      static UINT m_uiPortNoObjCreator;
      //## end CETChannel::uiPortNoObjCreator%3DB50428033E.attr

      //## Attribute: uiPortNoStepperMotors%3DB5045E00EC
      //## begin CETChannel::uiPortNoStepperMotors%3DB5045E00EC.attr preserve=no  private: static UINT {U} 8091
      static UINT m_uiPortNoStepperMotors;
      //## end CETChannel::uiPortNoStepperMotors%3DB5045E00EC.attr

      //## Attribute: uiPortNoMeasChannel%3DB5045F00AE
      //## begin CETChannel::uiPortNoMeasChannel%3DB5045F00AE.attr preserve=no  private: static UINT {U} 8092
      static UINT m_uiPortNoMeasChannel;
      //## end CETChannel::uiPortNoMeasChannel%3DB5045F00AE.attr

      //## Attribute: uiPortNoPersistentObjects%3DBC0AD70316
      //## begin CETChannel::uiPortNoPersistentObjects%3DBC0AD70316.attr preserve=no  private: static UINT {U} 8093
      static UINT m_uiPortNoPersistentObjects;
      //## end CETChannel::uiPortNoPersistentObjects%3DBC0AD70316.attr

      //## Attribute: uiPortNoSensors%3DBC0AE700CA
      //## begin CETChannel::uiPortNoSensors%3DBC0AE700CA.attr preserve=no  private: static UINT {U} 8094
      static UINT m_uiPortNoSensors;
      //## end CETChannel::uiPortNoSensors%3DBC0AE700CA.attr

      //## Attribute: uiPortNoOutputs%3DBC0AED0368
      //## begin CETChannel::uiPortNoOutputs%3DBC0AED0368.attr preserve=no  private: static UINT {U} 8095
      static UINT m_uiPortNoOutputs;
      //## end CETChannel::uiPortNoOutputs%3DBC0AED0368.attr

      //## Attribute: uiPortNoTempControl%3DBC0AF803A0
      //## begin CETChannel::uiPortNoTempControl%3DBC0AF803A0.attr preserve=no  private: static UINT {U} 8096
      static UINT m_uiPortNoTempControl;
      //## end CETChannel::uiPortNoTempControl%3DBC0AF803A0.attr

      //## Attribute: uiPortNoPowerControl%3DBC0B05007D
      //## begin CETChannel::uiPortNoPowerControl%3DBC0B05007D.attr preserve=no  private: static UINT {U} 8097
      static UINT m_uiPortNoPowerControl;
      //## end CETChannel::uiPortNoPowerControl%3DBC0B05007D.attr

      //## Attribute: uiPortNoWedgeControl%3DBC0B0D00C5
      //## begin CETChannel::uiPortNoWedgeControl%3DBC0B0D00C5.attr preserve=no  private: static UINT {U} 8098
      static UINT m_uiPortNoWedgeControl;
      //## end CETChannel::uiPortNoWedgeControl%3DBC0B0D00C5.attr

      //## Attribute: uiPortNoEvents%3DBC0B180233
      //## begin CETChannel::uiPortNoEvents%3DBC0B180233.attr preserve=no  private: static UINT {U} 8099
      static UINT m_uiPortNoEvents;
      //## end CETChannel::uiPortNoEvents%3DBC0B180233.attr

      //## Attribute: uiPortNoDiagnostic%3DF736B901FC
      //## begin CETChannel::uiPortNoDiagnostic%3DF736B901FC.attr preserve=no  private: static UINT {U} 8100
      static UINT m_uiPortNoDiagnostic;
      //## end CETChannel::uiPortNoDiagnostic%3DF736B901FC.attr

      //## Attribute: uiPortNoSystem%3EE5C32203BB
      //## begin CETChannel::uiPortNoSystem%3EE5C32203BB.attr preserve=no  private: static UINT {U} 8101
      static UINT m_uiPortNoSystem;
      //## end CETChannel::uiPortNoSystem%3EE5C32203BB.attr

      //## Attribute: uiPortNoI2CBus%3EE5EB2A01A8
      //## begin CETChannel::uiPortNoI2CBus%3EE5EB2A01A8.attr preserve=no  private: static UINT {U} 8102
      static UINT m_uiPortNoI2CBus;
      //## end CETChannel::uiPortNoI2CBus%3EE5EB2A01A8.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA3D5290014
      //## Role: CETChannel::hSocket%3DA3D52A0092
      //## begin CETChannel::hSocket%3DA3D52A0092.role preserve=no  public: SOCKET {1..1 -> 1..1VFHN}
      SOCKET m_hSocket;
      //## end CETChannel::hSocket%3DA3D52A0092.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA525DD00ED
      //## Role: CETChannel::MessageList%3DA525DD03CC
      //## begin CETChannel::MessageList%3DA525DD03CC.role preserve=no  public: CETChannelMessageEnvoy {0 -> nRFHN}
      CTypedPtrList<CPtrList, CETChannelMessageEnvoy*> m_MessageList;
      //## end CETChannel::MessageList%3DA525DD03CC.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F6EE26902FB
      //## Role: CETChannel::Clients%3F6EE26C005B
      //## Constraints:
      //	ordered
      //## Qualifier: class%3F6EE2830368; SOCKET
      //## begin CETChannel::Clients%3F6EE26C005B.role preserve=no  public: CETClient {1 -> 1RFHON}
      CMap<SOCKET, SOCKET&, CETClient *, CETClient *&> m_Clients;
      //## end CETChannel::Clients%3F6EE26C005B.role

    // Additional Protected Declarations
      //## begin CETChannel%3DA2F3090146.protected preserve=yes
      //## end CETChannel%3DA2F3090146.protected

  private:
    //## Constructors (generated)
      CETChannel();

      CETChannel(const CETChannel &right);

    //## Assignment Operation (generated)
      const CETChannel & operator=(const CETChannel &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannel &right) const;

      bool operator!=(const CETChannel &right) const;


    //## Other Operations (specified)
      //## Operation: TerminateHelpers%1064223158
      //	Terminates all reader and writer helper threads
      void TerminateHelpers ();

    // Data Members for Class Attributes

      //## Attribute: iState%468CFAEB03B4
      //## begin CETChannel::iState%468CFAEB03B4.attr preserve=no  private: int {U} 0
      int m_iState;
      //## end CETChannel::iState%468CFAEB03B4.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA417A9019C
      //## Role: CETChannel::hSocketEvent%3DA417AA0084
      //## begin CETChannel::hSocketEvent%3DA417AA0084.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hSocketEvent;
      //## end CETChannel::hSocketEvent%3DA417AA0084.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA5263F033F
      //## Role: CETChannel::MessageLock%3DA52640018A
      //## begin CETChannel::MessageLock%3DA52640018A.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_MessageLock;
      //## end CETChannel::MessageLock%3DA52640018A.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA5270802D1
      //## Role: CETChannel::hMessageEvent%3DA52709016B
      //## begin CETChannel::hMessageEvent%3DA52709016B.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hMessageEvent;
      //## end CETChannel::hMessageEvent%3DA52709016B.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F6EF9680107
      //## Role: CETChannel::ChannelWriters%3F6EF96A003B
      //## Constraints:
      //	ordered
      //## Qualifier: class%3F6EF98103A6; SOCKET
      //## begin CETChannel::ChannelWriters%3F6EF96A003B.role preserve=no  public: CETChannelWriter {1 -> 1RFHON}
      CMap<SOCKET, SOCKET&, CETChannelWriter *, CETChannelWriter *&> m_ChannelWriters;
      //## end CETChannel::ChannelWriters%3F6EF96A003B.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3F6EFC9A0107
      //## Role: CETChannel::ChannelReaders%3F6EFC9B01F1
      //## Constraints:
      //	ordered
      //## Qualifier: class%3F6EFCAE01F1; SOCKET
      //## begin CETChannel::ChannelReaders%3F6EFC9B01F1.role preserve=no  public: CETChannelReader {1 -> 1RFHON}
      CMap<SOCKET, SOCKET&, CETChannelReader *, CETChannelReader *&> m_ChannelReaders;
      //## end CETChannel::ChannelReaders%3F6EFC9B01F1.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%456DA17C00D7
      //## Role: CETChannel::EndedReaderLock%456DA17D00E3
      //## begin CETChannel::EndedReaderLock%456DA17D00E3.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_EndedReaderLock;
      //## end CETChannel::EndedReaderLock%456DA17D00E3.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%46890D8D02A3
      //## Role: CETChannel::EndedReaders%46890D8E024A
      //## begin CETChannel::EndedReaders%46890D8E024A.role preserve=no  public: SOCKET {1 -> nVFHN}
      CList<SOCKET, SOCKET> m_EndedReaders;
      //## end CETChannel::EndedReaders%46890D8E024A.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%46890E7301C8
      //## Role: CETChannel::hEndedReaderEvent%46890E74016F
      //## begin CETChannel::hEndedReaderEvent%46890E74016F.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hEndedReaderEvent;
      //## end CETChannel::hEndedReaderEvent%46890E74016F.role

    // Additional Private Declarations
      //## begin CETChannel%3DA2F3090146.private preserve=yes
      //## end CETChannel%3DA2F3090146.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannel%3DA2F3090146.implementation preserve=yes
      //## end CETChannel%3DA2F3090146.implementation

};

//## begin CETChannel%3DA2F3090146.postscript preserve=yes
//## end CETChannel%3DA2F3090146.postscript

//## begin CETChannelFactory%3DA2F3530175.preface preserve=yes
//## end CETChannelFactory%3DA2F3530175.preface

//## Class: CETChannelFactory%3DA2F3530175
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAAAF2300DF;CETChannelObjCreator { -> }
//## Uses: <unnamed>%3DAAAF2500B0;CETChannelStepperMotors { -> }
//## Uses: <unnamed>%3DAAB16F013C;CETChannelMeasurementChannel { -> }
//## Uses: <unnamed>%3DBC0CF502E4;CETChannelPersistentObjects { -> }
//## Uses: <unnamed>%3DBC0CFA039F;CETChannelEvents { -> }
//## Uses: <unnamed>%3DBC0CFD008C;CETChannelControlWedge { -> }
//## Uses: <unnamed>%3DBC0CFF02AC;CETChannelControlPower { -> }
//## Uses: <unnamed>%3DBC0D0200BB;CETChannelControlTemperature { -> }
//## Uses: <unnamed>%3DBC0D08006A;CETChannelOutputs { -> }
//## Uses: <unnamed>%3DBC0D0A022F;CETChannelSensors { -> }
//## Uses: <unnamed>%3DF737ED020B;CETChannelDiagnostics { -> }
//## Uses: <unnamed>%3EE5D2EE035D;CETChannelSystem { -> }
//## Uses: <unnamed>%3EE5E5D000AE;CETChannelI2CBus { -> }

class EBET_DLL_DECL CETChannelFactory 
{
  //## begin CETChannelFactory%3DA2F3530175.initialDeclarations preserve=yes
  //## end CETChannelFactory%3DA2F3530175.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelFactory();

    //## Destructor (generated)
      virtual ~CETChannelFactory();


    //## Other Operations (specified)
      //## Operation: Create%1034087076
      static void Create ();

      //## Operation: Delete%1034087077
      static void Delete ();

      //## Operation: GetInstance%1034087078
      static CETChannelFactory* GetInstance ();

      //## Operation: CreateChannels%1034087079
      void CreateChannels ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%477629AD02D0
      //## Role: CETChannelFactory::pBrowserService%477629AE0245
      CETBrowserService * GetpBrowserService ();

    // Additional Public Declarations
      //## begin CETChannelFactory%3DA2F3530175.public preserve=yes
      //## end CETChannelFactory%3DA2F3530175.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelFactory%3DA2F3530175.protected preserve=yes
      //## end CETChannelFactory%3DA2F3530175.protected

  private:
    //## Constructors (generated)
      CETChannelFactory(const CETChannelFactory &right);

    //## Assignment Operation (generated)
      const CETChannelFactory & operator=(const CETChannelFactory &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelFactory &right) const;

      bool operator!=(const CETChannelFactory &right) const;

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA2F370030B
      //## Role: CETChannelFactory::pInstance%3DA2F3710399
      //## begin CETChannelFactory::pInstance%3DA2F3710399.role preserve=no  public: static CETChannelFactory {1..1 -> 1..1RFHN}
      static CETChannelFactory *m_pInstance;
      //## end CETChannelFactory::pInstance%3DA2F3710399.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA2F4610378
      //## Role: CETChannelFactory::ChannelList%3DA2F4620399
      //## begin CETChannelFactory::ChannelList%3DA2F4620399.role preserve=no  public: CETChannel {0 -> nRFHN}
      CTypedPtrList<CPtrList, CETChannel*> m_ChannelList;
      //## end CETChannelFactory::ChannelList%3DA2F4620399.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%477629AD02D0
      //## begin CETChannelFactory::pBrowserService%477629AE0245.role preserve=no  public: CETBrowserService {1..1 -> 1..1RFHN}
      CETBrowserService *m_pBrowserService;
      //## end CETChannelFactory::pBrowserService%477629AE0245.role

    // Additional Private Declarations
      //## begin CETChannelFactory%3DA2F3530175.private preserve=yes
      //## end CETChannelFactory%3DA2F3530175.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelFactory%3DA2F3530175.implementation preserve=yes
      //## end CETChannelFactory%3DA2F3530175.implementation

};

//## begin CETChannelFactory%3DA2F3530175.postscript preserve=yes
//## end CETChannelFactory%3DA2F3530175.postscript

//## begin CETChannelMessageEnvoy%3DA5492902E8.preface preserve=yes
//## end CETChannelMessageEnvoy%3DA5492902E8.preface

//## Class: CETChannelMessageEnvoy%3DA5492902E8
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageEnvoy : public ICORefCounting  //## Inherits: <unnamed>%3E3654090176
{
  //## begin CETChannelMessageEnvoy%3DA5492902E8.initialDeclarations preserve=yes
  //## end CETChannelMessageEnvoy%3DA5492902E8.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageEnvoy%1034230445
      CETChannelMessageEnvoy (CETChannelMessage* p_pMsg, SOCKET p_hSocket);

      //## Operation: CETChannelMessageEnvoy%1034407671
      CETChannelMessageEnvoy (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj = NULL);


    //## Other Operations (specified)
      //## Operation: HandleReturnValue%1037346554
      void HandleReturnValue ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA5494502D8
      //## Role: CETChannelMessageEnvoy::pMsg%3DA5494601DF
      CETChannelMessage * GetpMsg ();

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA549700132
      //## Role: CETChannelMessageEnvoy::hSocket%3DA549700374
      SOCKET GethSocket ();

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA6D3A902EB
      //## Role: CETChannelMessageEnvoy::pServerSyncObj%3DA6D3AA0156
      CCOSyncObject * GetpServerSyncObj ();
      void SetpServerSyncObj (CCOSyncObject * value);

    // Additional Public Declarations
      //## begin CETChannelMessageEnvoy%3DA5492902E8.public preserve=yes
      //## end CETChannelMessageEnvoy%3DA5492902E8.public

  protected:
    //## Destructor (generated)
      virtual ~CETChannelMessageEnvoy();


    //## Other Operations (specified)
      //## Operation: ProcessAsyncReturnValue%1034575095
      virtual void ProcessAsyncReturnValue ();

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA5494502D8
      //## begin CETChannelMessageEnvoy::pMsg%3DA5494601DF.role preserve=no  public: CETChannelMessage {1..1 -> 1..1RFHN}
      CETChannelMessage *m_pMsg;
      //## end CETChannelMessageEnvoy::pMsg%3DA5494601DF.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA549700132
      //## begin CETChannelMessageEnvoy::hSocket%3DA549700374.role preserve=no  public: SOCKET {1..1 -> 1..1VFHN}
      SOCKET m_hSocket;
      //## end CETChannelMessageEnvoy::hSocket%3DA549700374.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA6D3A902EB
      //## begin CETChannelMessageEnvoy::pServerSyncObj%3DA6D3AA0156.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pServerSyncObj;
      //## end CETChannelMessageEnvoy::pServerSyncObj%3DA6D3AA0156.role

    // Additional Protected Declarations
      //## begin CETChannelMessageEnvoy%3DA5492902E8.protected preserve=yes
      //## end CETChannelMessageEnvoy%3DA5492902E8.protected

  private:
    //## Constructors (generated)
      CETChannelMessageEnvoy();

      CETChannelMessageEnvoy(const CETChannelMessageEnvoy &right);

    //## Assignment Operation (generated)
      const CETChannelMessageEnvoy & operator=(const CETChannelMessageEnvoy &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageEnvoy &right) const;

      bool operator!=(const CETChannelMessageEnvoy &right) const;

    // Additional Private Declarations
      //## begin CETChannelMessageEnvoy%3DA5492902E8.private preserve=yes
      //## end CETChannelMessageEnvoy%3DA5492902E8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageEnvoy%3DA5492902E8.implementation preserve=yes
      //## end CETChannelMessageEnvoy%3DA5492902E8.implementation

};

//## begin CETChannelMessageEnvoy%3DA5492902E8.postscript preserve=yes
//## end CETChannelMessageEnvoy%3DA5492902E8.postscript

//## begin CETChannelMessageEnvoyInt%3DAA82B90275.preface preserve=yes
//## end CETChannelMessageEnvoyInt%3DAA82B90275.preface

//## Class: CETChannelMessageEnvoyInt%3DAA82B90275
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAAAF5401C9;CCOSyncObjectInt { -> }

class CETChannelMessageEnvoyInt : public CETChannelMessageEnvoy  //## Inherits: <unnamed>%3DAA82CE02C3
{
  //## begin CETChannelMessageEnvoyInt%3DAA82B90275.initialDeclarations preserve=yes
  //## end CETChannelMessageEnvoyInt%3DAA82B90275.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageEnvoyInt%1034575094
      CETChannelMessageEnvoyInt (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj = NULL);


    //## Other Operations (specified)
      //## Operation: ProcessAsyncReturnValue%1034575096
      virtual void ProcessAsyncReturnValue ();

    // Additional Public Declarations
      //## begin CETChannelMessageEnvoyInt%3DAA82B90275.public preserve=yes
      //## end CETChannelMessageEnvoyInt%3DAA82B90275.public

  protected:
    //## Destructor (generated)
      virtual ~CETChannelMessageEnvoyInt();

    // Additional Protected Declarations
      //## begin CETChannelMessageEnvoyInt%3DAA82B90275.protected preserve=yes
      //## end CETChannelMessageEnvoyInt%3DAA82B90275.protected

  private:
    //## Constructors (generated)
      CETChannelMessageEnvoyInt();

      CETChannelMessageEnvoyInt(const CETChannelMessageEnvoyInt &right);

    //## Assignment Operation (generated)
      const CETChannelMessageEnvoyInt & operator=(const CETChannelMessageEnvoyInt &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageEnvoyInt &right) const;

      bool operator!=(const CETChannelMessageEnvoyInt &right) const;

    // Additional Private Declarations
      //## begin CETChannelMessageEnvoyInt%3DAA82B90275.private preserve=yes
      //## end CETChannelMessageEnvoyInt%3DAA82B90275.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageEnvoyInt%3DAA82B90275.implementation preserve=yes
      //## end CETChannelMessageEnvoyInt%3DAA82B90275.implementation

};

//## begin CETChannelMessageEnvoyInt%3DAA82B90275.postscript preserve=yes
//## end CETChannelMessageEnvoyInt%3DAA82B90275.postscript

//## begin CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.preface preserve=yes
//## end CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.preface

//## Class: CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAFB28E02AA;CPISyncObjDataPackage { -> }
//## Uses: <unnamed>%3DAFB2990059;CETChannelMessageMeasurementDataPackage { -> }

class CETChannelMessageEnvoyMeasurementDataPackage : public CETChannelMessageEnvoy  //## Inherits: <unnamed>%3DAFADBC0133
{
  //## begin CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.initialDeclarations preserve=yes
  //## end CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageEnvoyMeasurementDataPackage%1034922743
      CETChannelMessageEnvoyMeasurementDataPackage (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj = NULL);

    //## Destructor (generated)
      virtual ~CETChannelMessageEnvoyMeasurementDataPackage();

    // Additional Public Declarations
      //## begin CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.public preserve=yes
      //## end CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessAsyncReturnValue%1034922744
      virtual void ProcessAsyncReturnValue ();

    // Additional Protected Declarations
      //## begin CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.protected preserve=yes
      //## end CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.protected

  private:
    //## Constructors (generated)
      CETChannelMessageEnvoyMeasurementDataPackage();

      CETChannelMessageEnvoyMeasurementDataPackage(const CETChannelMessageEnvoyMeasurementDataPackage &right);

    //## Assignment Operation (generated)
      const CETChannelMessageEnvoyMeasurementDataPackage & operator=(const CETChannelMessageEnvoyMeasurementDataPackage &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageEnvoyMeasurementDataPackage &right) const;

      bool operator!=(const CETChannelMessageEnvoyMeasurementDataPackage &right) const;

    // Additional Private Declarations
      //## begin CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.private preserve=yes
      //## end CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.implementation preserve=yes
      //## end CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.implementation

};

//## begin CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.postscript preserve=yes
//## end CETChannelMessageEnvoyMeasurementDataPackage%3DAFAD970327.postscript

//## begin CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.preface preserve=yes
//## end CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.preface

//## Class: CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageEnvoyStepperLimitFootPrint : public CETChannelMessageEnvoy  //## Inherits: <unnamed>%3DCB6AF4026A
{
  //## begin CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.initialDeclarations preserve=yes
  //## end CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageEnvoyStepperLimitFootPrint%1036738403
      CETChannelMessageEnvoyStepperLimitFootPrint (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj = NULL);

    //## Destructor (generated)
      virtual ~CETChannelMessageEnvoyStepperLimitFootPrint();

    // Additional Public Declarations
      //## begin CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.public preserve=yes
      //## end CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessAsyncReturnValue%1036738404
      virtual void ProcessAsyncReturnValue ();

    // Additional Protected Declarations
      //## begin CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.protected preserve=yes
      //## end CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.protected

  private:
    //## Constructors (generated)
      CETChannelMessageEnvoyStepperLimitFootPrint();

      CETChannelMessageEnvoyStepperLimitFootPrint(const CETChannelMessageEnvoyStepperLimitFootPrint &right);

    //## Assignment Operation (generated)
      const CETChannelMessageEnvoyStepperLimitFootPrint & operator=(const CETChannelMessageEnvoyStepperLimitFootPrint &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageEnvoyStepperLimitFootPrint &right) const;

      bool operator!=(const CETChannelMessageEnvoyStepperLimitFootPrint &right) const;

    // Additional Private Declarations
      //## begin CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.private preserve=yes
      //## end CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.implementation preserve=yes
      //## end CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.implementation

};

//## begin CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.postscript preserve=yes
//## end CETChannelMessageEnvoyStepperLimitFootPrint%3DCB6ADB01ED.postscript

//## begin CETChannelMessageEnvoyBool%3DD4EC600336.preface preserve=yes
//## end CETChannelMessageEnvoyBool%3DD4EC600336.preface

//## Class: CETChannelMessageEnvoyBool%3DD4EC600336
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageEnvoyBool : public CETChannelMessageEnvoy  //## Inherits: <unnamed>%3DD4EC7B024C
{
  //## begin CETChannelMessageEnvoyBool%3DD4EC600336.initialDeclarations preserve=yes
  //## end CETChannelMessageEnvoyBool%3DD4EC600336.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageEnvoyBool%1037346569
      CETChannelMessageEnvoyBool (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj = NULL);


    //## Other Operations (specified)
      //## Operation: ProcessAsyncReturnValue%1037346570
      virtual void ProcessAsyncReturnValue ();

    // Additional Public Declarations
      //## begin CETChannelMessageEnvoyBool%3DD4EC600336.public preserve=yes
      //## end CETChannelMessageEnvoyBool%3DD4EC600336.public

  protected:
    //## Destructor (generated)
      virtual ~CETChannelMessageEnvoyBool();

    // Additional Protected Declarations
      //## begin CETChannelMessageEnvoyBool%3DD4EC600336.protected preserve=yes
      //## end CETChannelMessageEnvoyBool%3DD4EC600336.protected

  private:
    //## Constructors (generated)
      CETChannelMessageEnvoyBool();

      CETChannelMessageEnvoyBool(const CETChannelMessageEnvoyBool &right);

    //## Assignment Operation (generated)
      const CETChannelMessageEnvoyBool & operator=(const CETChannelMessageEnvoyBool &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageEnvoyBool &right) const;

      bool operator!=(const CETChannelMessageEnvoyBool &right) const;

    // Additional Private Declarations
      //## begin CETChannelMessageEnvoyBool%3DD4EC600336.private preserve=yes
      //## end CETChannelMessageEnvoyBool%3DD4EC600336.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageEnvoyBool%3DD4EC600336.implementation preserve=yes
      //## end CETChannelMessageEnvoyBool%3DD4EC600336.implementation

};

//## begin CETChannelMessageEnvoyBool%3DD4EC600336.postscript preserve=yes
//## end CETChannelMessageEnvoyBool%3DD4EC600336.postscript

//## begin CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.preface preserve=yes
//## end CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.preface

//## Class: CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF5FBD40334;CPIPersistentIdent { -> }
//## Uses: <unnamed>%3DF5FBEB0017;CPIPersistentItemList { -> }

class CETChannelMessageEnvoyPersistentIdentification : public CETChannelMessageEnvoy  //## Inherits: <unnamed>%3DF5FBA70140
{
  //## begin CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.initialDeclarations preserve=yes
  //## end CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageEnvoyPersistentIdentification%1039528816
      CETChannelMessageEnvoyPersistentIdentification (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj);

    //## Destructor (generated)
      virtual ~CETChannelMessageEnvoyPersistentIdentification();

    // Additional Public Declarations
      //## begin CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.public preserve=yes
      //## end CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessAsyncReturnValue%1039528817
      virtual void ProcessAsyncReturnValue ();

    // Additional Protected Declarations
      //## begin CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.protected preserve=yes
      //## end CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.protected

  private:
    //## Constructors (generated)
      CETChannelMessageEnvoyPersistentIdentification();

      CETChannelMessageEnvoyPersistentIdentification(const CETChannelMessageEnvoyPersistentIdentification &right);

    //## Assignment Operation (generated)
      const CETChannelMessageEnvoyPersistentIdentification & operator=(const CETChannelMessageEnvoyPersistentIdentification &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageEnvoyPersistentIdentification &right) const;

      bool operator!=(const CETChannelMessageEnvoyPersistentIdentification &right) const;

    // Additional Private Declarations
      //## begin CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.private preserve=yes
      //## end CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.implementation preserve=yes
      //## end CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.implementation

};

//## begin CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.postscript preserve=yes
//## end CETChannelMessageEnvoyPersistentIdentification%3DF5FB5003C0.postscript

//## begin CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.preface preserve=yes
//## end CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.preface

//## Class: CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF5FE290027;CETChannelMessagePersistentParameter { -> }
//## Uses: <unnamed>%3DF5FE3F02E6; { -> }
//## Uses: <unnamed>%4002D1C40232;CPIPersistentItemList { -> }

class CETChannelMessageEnvoyPersistentParameter : public CETChannelMessageEnvoy  //## Inherits: <unnamed>%3DF5FE300278
{
  //## begin CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.initialDeclarations preserve=yes
  //## end CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageEnvoyPersistentParameter%1039528818
      CETChannelMessageEnvoyPersistentParameter (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj);

    //## Destructor (generated)
      virtual ~CETChannelMessageEnvoyPersistentParameter();

    // Additional Public Declarations
      //## begin CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.public preserve=yes
      //## end CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessAsyncReturnValue%1039528819
      virtual void ProcessAsyncReturnValue ();

    // Additional Protected Declarations
      //## begin CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.protected preserve=yes
      //## end CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.protected

  private:
    //## Constructors (generated)
      CETChannelMessageEnvoyPersistentParameter();

      CETChannelMessageEnvoyPersistentParameter(const CETChannelMessageEnvoyPersistentParameter &right);

    //## Assignment Operation (generated)
      const CETChannelMessageEnvoyPersistentParameter & operator=(const CETChannelMessageEnvoyPersistentParameter &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageEnvoyPersistentParameter &right) const;

      bool operator!=(const CETChannelMessageEnvoyPersistentParameter &right) const;

    // Additional Private Declarations
      //## begin CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.private preserve=yes
      //## end CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.implementation preserve=yes
      //## end CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.implementation

};

//## begin CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.postscript preserve=yes
//## end CETChannelMessageEnvoyPersistentParameter%3DF5FDF20121.postscript

//## begin CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.preface preserve=yes
//## end CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.preface

//## Class: CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF5FE8401EC;CETChannelMessagePersistentSoftwareComponentVersion { -> }
//## Uses: <unnamed>%3DF5FE9301CC;CPISyncObjListSWCompVersion { -> }

class CETChannelMessageEnvoyPersistentSoftwareComponentVersion : public CETChannelMessageEnvoy  //## Inherits: <unnamed>%3DF5FFB00269
{
  //## begin CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.initialDeclarations preserve=yes
  //## end CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageEnvoyPersistentSoftwareComponentVersion%1039528820
      CETChannelMessageEnvoyPersistentSoftwareComponentVersion (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj);

    //## Destructor (generated)
      virtual ~CETChannelMessageEnvoyPersistentSoftwareComponentVersion();

    // Additional Public Declarations
      //## begin CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.public preserve=yes
      //## end CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessAsyncReturnValue%1039528821
      virtual void ProcessAsyncReturnValue ();

    // Additional Protected Declarations
      //## begin CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.protected preserve=yes
      //## end CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.protected

  private:
    //## Constructors (generated)
      CETChannelMessageEnvoyPersistentSoftwareComponentVersion();

      CETChannelMessageEnvoyPersistentSoftwareComponentVersion(const CETChannelMessageEnvoyPersistentSoftwareComponentVersion &right);

    //## Assignment Operation (generated)
      const CETChannelMessageEnvoyPersistentSoftwareComponentVersion & operator=(const CETChannelMessageEnvoyPersistentSoftwareComponentVersion &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageEnvoyPersistentSoftwareComponentVersion &right) const;

      bool operator!=(const CETChannelMessageEnvoyPersistentSoftwareComponentVersion &right) const;

    // Additional Private Declarations
      //## begin CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.private preserve=yes
      //## end CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.implementation preserve=yes
      //## end CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.implementation

};

//## begin CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.postscript preserve=yes
//## end CETChannelMessageEnvoyPersistentSoftwareComponentVersion%3DF5FE55017E.postscript

//## begin CETChannelMessageEnvoySystemGetObjectList%3F6728910377.preface preserve=yes
//## end CETChannelMessageEnvoySystemGetObjectList%3F6728910377.preface

//## Class: CETChannelMessageEnvoySystemGetObjectList%3F6728910377
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F6728B50125;CETChannelMessageSystemGetObjectList { -> }
//## Uses: <unnamed>%3F6728E300E7;CPISyncObjectStringArray { -> }

class CETChannelMessageEnvoySystemGetObjectList : public CETChannelMessageEnvoy  //## Inherits: <unnamed>%3F6728B2002B
{
  //## begin CETChannelMessageEnvoySystemGetObjectList%3F6728910377.initialDeclarations preserve=yes
  //## end CETChannelMessageEnvoySystemGetObjectList%3F6728910377.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageEnvoySystemGetObjectList%1063715465
      CETChannelMessageEnvoySystemGetObjectList (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj);

    //## Destructor (generated)
      virtual ~CETChannelMessageEnvoySystemGetObjectList();

    // Additional Public Declarations
      //## begin CETChannelMessageEnvoySystemGetObjectList%3F6728910377.public preserve=yes
      //## end CETChannelMessageEnvoySystemGetObjectList%3F6728910377.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessAsyncReturnValue%1063715466
      virtual void ProcessAsyncReturnValue ();

    // Additional Protected Declarations
      //## begin CETChannelMessageEnvoySystemGetObjectList%3F6728910377.protected preserve=yes
      //## end CETChannelMessageEnvoySystemGetObjectList%3F6728910377.protected

  private:
    //## Constructors (generated)
      CETChannelMessageEnvoySystemGetObjectList();

      CETChannelMessageEnvoySystemGetObjectList(const CETChannelMessageEnvoySystemGetObjectList &right);

    //## Assignment Operation (generated)
      const CETChannelMessageEnvoySystemGetObjectList & operator=(const CETChannelMessageEnvoySystemGetObjectList &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageEnvoySystemGetObjectList &right) const;

      bool operator!=(const CETChannelMessageEnvoySystemGetObjectList &right) const;

    // Additional Private Declarations
      //## begin CETChannelMessageEnvoySystemGetObjectList%3F6728910377.private preserve=yes
      //## end CETChannelMessageEnvoySystemGetObjectList%3F6728910377.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageEnvoySystemGetObjectList%3F6728910377.implementation preserve=yes
      //## end CETChannelMessageEnvoySystemGetObjectList%3F6728910377.implementation

};

//## begin CETChannelMessageEnvoySystemGetObjectList%3F6728910377.postscript preserve=yes
//## end CETChannelMessageEnvoySystemGetObjectList%3F6728910377.postscript

//## begin CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.preface preserve=yes
//## end CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.preface

//## Class: CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%40111F79004A;CPIDataADCMAX1037 { -> }

class CETChannelMessageEnvoyI2CAdcMax1037 : public CETChannelMessageEnvoy  //## Inherits: <unnamed>%40111EB90088
{
  //## begin CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.initialDeclarations preserve=yes
  //## end CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageEnvoyI2CAdcMax1037%1074861339
      CETChannelMessageEnvoyI2CAdcMax1037 (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj);

    //## Destructor (generated)
      virtual ~CETChannelMessageEnvoyI2CAdcMax1037();

    // Additional Public Declarations
      //## begin CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.public preserve=yes
      //## end CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessAsyncReturnValue%1074861340
      virtual void ProcessAsyncReturnValue ();

    // Additional Protected Declarations
      //## begin CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.protected preserve=yes
      //## end CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.protected

  private:
    //## Constructors (generated)
      CETChannelMessageEnvoyI2CAdcMax1037();

      CETChannelMessageEnvoyI2CAdcMax1037(const CETChannelMessageEnvoyI2CAdcMax1037 &right);

    //## Assignment Operation (generated)
      const CETChannelMessageEnvoyI2CAdcMax1037 & operator=(const CETChannelMessageEnvoyI2CAdcMax1037 &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageEnvoyI2CAdcMax1037 &right) const;

      bool operator!=(const CETChannelMessageEnvoyI2CAdcMax1037 &right) const;

    // Additional Private Declarations
      //## begin CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.private preserve=yes
      //## end CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.implementation preserve=yes
      //## end CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.implementation

};

//## begin CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.postscript preserve=yes
//## end CETChannelMessageEnvoyI2CAdcMax1037%40111E2F00D7.postscript

//## begin CETChannelMessageEnvoyString%4148088C0213.preface preserve=yes
//## end CETChannelMessageEnvoyString%4148088C0213.preface

//## Class: CETChannelMessageEnvoyString%4148088C0213
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelMessageEnvoyString : public CETChannelMessageEnvoy  //## Inherits: <unnamed>%414808AF007D
{
  //## begin CETChannelMessageEnvoyString%4148088C0213.initialDeclarations preserve=yes
  //## end CETChannelMessageEnvoyString%4148088C0213.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelMessageEnvoyString%1095233134
      CETChannelMessageEnvoyString (CETChannelMessage* p_pMsg, CCOSyncObject* p_pSyncObj = NULL);


    //## Other Operations (specified)
      //## Operation: ProcessAsyncReturnValue%1095233135
      virtual void ProcessAsyncReturnValue ();

    // Additional Public Declarations
      //## begin CETChannelMessageEnvoyString%4148088C0213.public preserve=yes
      //## end CETChannelMessageEnvoyString%4148088C0213.public

  protected:
    //## Destructor (generated)
      virtual ~CETChannelMessageEnvoyString();

    // Additional Protected Declarations
      //## begin CETChannelMessageEnvoyString%4148088C0213.protected preserve=yes
      //## end CETChannelMessageEnvoyString%4148088C0213.protected

  private:
    //## Constructors (generated)
      CETChannelMessageEnvoyString();

      CETChannelMessageEnvoyString(const CETChannelMessageEnvoyString &right);

    //## Assignment Operation (generated)
      const CETChannelMessageEnvoyString & operator=(const CETChannelMessageEnvoyString &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMessageEnvoyString &right) const;

      bool operator!=(const CETChannelMessageEnvoyString &right) const;

    // Additional Private Declarations
      //## begin CETChannelMessageEnvoyString%4148088C0213.private preserve=yes
      //## end CETChannelMessageEnvoyString%4148088C0213.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMessageEnvoyString%4148088C0213.implementation preserve=yes
      //## end CETChannelMessageEnvoyString%4148088C0213.implementation

};

//## begin CETChannelMessageEnvoyString%4148088C0213.postscript preserve=yes
//## end CETChannelMessageEnvoyString%4148088C0213.postscript

//## begin CETClient%468225410089.preface preserve=yes
//## end CETClient%468225410089.preface

//## Class: CETClient%468225410089
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETClient 
{
  //## begin CETClient%468225410089.initialDeclarations preserve=yes
  //## end CETClient%468225410089.initialDeclarations

  public:
    //## Constructors (generated)
      CETClient();

    //## Constructors (specified)
      //## Operation: CETClient%1182934535
      CETClient (SOCKET p_hClient);

    //## Destructor (generated)
      virtual ~CETClient();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: sName%4682255B0299
      const CString GetsName () const;
      void SetsName (CString value);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%46822592003F
      //## Role: CETClient::hClient%46822592025D
      SOCKET GethClient ();

    // Additional Public Declarations
      //## begin CETClient%468225410089.public preserve=yes
      //## end CETClient%468225410089.public

  protected:
    // Additional Protected Declarations
      //## begin CETClient%468225410089.protected preserve=yes
      //## end CETClient%468225410089.protected

  private:
    //## Constructors (generated)
      CETClient(const CETClient &right);

    //## Assignment Operation (generated)
      const CETClient & operator=(const CETClient &right);

    //## Equality Operations (generated)
      bool operator==(const CETClient &right) const;

      bool operator!=(const CETClient &right) const;

    // Data Members for Class Attributes

      //## begin CETClient::sName%4682255B0299.attr preserve=no  public: CString {U} 
      CString m_sName;
      //## end CETClient::sName%4682255B0299.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%46822592003F
      //## begin CETClient::hClient%46822592025D.role preserve=no  public: SOCKET {1..1 -> 1..1VFHN}
      SOCKET m_hClient;
      //## end CETClient::hClient%46822592025D.role

    // Additional Private Declarations
      //## begin CETClient%468225410089.private preserve=yes
      //## end CETClient%468225410089.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETClient%468225410089.implementation preserve=yes
      //## end CETClient%468225410089.implementation

};

//## begin CETClient%468225410089.postscript preserve=yes
//## end CETClient%468225410089.postscript

// Class CETChannel 

// Class CETChannelFactory 

// Class CETChannelMessageEnvoy 

// Class CETChannelMessageEnvoyInt 

// Class CETChannelMessageEnvoyMeasurementDataPackage 

// Class CETChannelMessageEnvoyStepperLimitFootPrint 

// Class CETChannelMessageEnvoyBool 

// Class CETChannelMessageEnvoyPersistentIdentification 

// Class CETChannelMessageEnvoyPersistentParameter 

// Class CETChannelMessageEnvoyPersistentSoftwareComponentVersion 

// Class CETChannelMessageEnvoySystemGetObjectList 

// Class CETChannelMessageEnvoyI2CAdcMax1037 

// Class CETChannelMessageEnvoyString 

// Class CETClient 

//## begin module%3D9D88460355.epilog preserve=yes
//## end module%3D9D88460355.epilog


#endif
