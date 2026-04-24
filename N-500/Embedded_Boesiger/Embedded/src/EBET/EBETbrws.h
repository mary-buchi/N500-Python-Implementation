//## begin module%47761E4002CA.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%47761E4002CA.cm

//## begin module%47761E4002CA.cp preserve=no
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
//## end module%47761E4002CA.cp

//## Module: EBETbrws%47761E4002CA; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETbrws.h

#ifndef EBETbrws_h
#define EBETbrws_h 1

//## begin module%47761E4002CA.additionalIncludes preserve=no
//## end module%47761E4002CA.additionalIncludes

//## begin module%47761E4002CA.includes preserve=yes
//## end module%47761E4002CA.includes

// EBETthrd
#include "EBETthrd.h"


//## begin module%47761E4002CA.declarations preserve=no
//## end module%47761E4002CA.declarations

//## begin module%47761E4002CA.additionalDeclarations preserve=yes
//## end module%47761E4002CA.additionalDeclarations


//## begin CETBrowserService%47761E500146.preface preserve=yes
//## end CETBrowserService%47761E500146.preface

//## Class: CETBrowserService%47761E500146
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%47769BED02A3;IPIPersistentObjInterface { -> }
//## Uses: <unnamed>%47769C050289;CPIObjectFactory { -> }
//## Uses: <unnamed>%47769F1B039E;XCOException { -> }

class CETBrowserService : public CETThread  //## Inherits: <unnamed>%47761E650205
{
  //## begin CETBrowserService%47761E500146.initialDeclarations preserve=yes
  //## end CETBrowserService%47761E500146.initialDeclarations

  public:
    //## Constructors (generated)
      CETBrowserService();

    //## Destructor (generated)
      virtual ~CETBrowserService();

    // Additional Public Declarations
      //## begin CETBrowserService%47761E500146.public preserve=yes
      //## end CETBrowserService%47761E500146.public

  protected:

    //## Other Operations (specified)
      //## Operation: ThreadMain%1198923433
      virtual DWORD ThreadMain ();

    // Additional Protected Declarations
      //## begin CETBrowserService%47761E500146.protected preserve=yes
      //## end CETBrowserService%47761E500146.protected

  private:
    //## Constructors (generated)
      CETBrowserService(const CETBrowserService &right);

    //## Assignment Operation (generated)
      const CETBrowserService & operator=(const CETBrowserService &right);

    //## Equality Operations (generated)
      bool operator==(const CETBrowserService &right) const;

      bool operator!=(const CETBrowserService &right) const;


    //## Other Operations (specified)
      //## Operation: ReadData%1198923434
      void ReadData ();

      //## Operation: SendHello%1241507175
      void SendHello ();

      //## Operation: SendGoodbye%1241507176
      void SendGoodbye ();

      //## Operation: SplitMessage%1198923435
      bool SplitMessage (const CString& p_sMsg, CString& p_sText, CString& p_sHostIP);

      //## Operation: InitializeAdapterInfo%1198923436
      void InitializeAdapterInfo ();

      //## Operation: InitializeSerialNo%1198923437
      void InitializeSerialNo ();

    // Data Members for Class Attributes

      //## Attribute: iPortNo%477621EE0292
      //## begin CETBrowserService::iPortNo%477621EE0292.attr preserve=no  private: int {U} 51229
      int m_iPortNo;
      //## end CETBrowserService::iPortNo%477621EE0292.attr

      //## Attribute: sScanMessage%477630BC007F
      //## begin CETBrowserService::sScanMessage%477630BC007F.attr preserve=no  private: CString {U} _T("Buchi DeviceScan")
      CString m_sScanMessage;
      //## end CETBrowserService::sScanMessage%477630BC007F.attr

      //## Attribute: sScanMessageReply%49FFE35502D1
      //## begin CETBrowserService::sScanMessageReply%49FFE35502D1.attr preserve=no  private: CString {U} _T("Buchi DeviceScan Reply")
      CString m_sScanMessageReply;
      //## end CETBrowserService::sScanMessageReply%49FFE35502D1.attr

      //## Attribute: uiInstrumentEpromID%47769E01038E
      //## begin CETBrowserService::uiInstrumentEpromID%47769E01038E.attr preserve=no  private: UINT {U} 5006
      UINT m_uiInstrumentEpromID;
      //## end CETBrowserService::uiInstrumentEpromID%47769E01038E.attr

      //## Attribute: sIPAddress%47769A5803E1
      //## begin CETBrowserService::sIPAddress%47769A5803E1.attr preserve=no  private: CString {U} _T("????")
      CString m_sIPAddress;
      //## end CETBrowserService::sIPAddress%47769A5803E1.attr

      //## Attribute: sArticleNo%49FFE3980126
      //## begin CETBrowserService::sArticleNo%49FFE3980126.attr preserve=no  private: CString {U} _T("46210")
      CString m_sArticleNo;
      //## end CETBrowserService::sArticleNo%49FFE3980126.attr

      //## Attribute: sSerialNo%47769BD000CB
      //## begin CETBrowserService::sSerialNo%47769BD000CB.attr preserve=no  private: CString {U} _T("????")
      CString m_sSerialNo;
      //## end CETBrowserService::sSerialNo%47769BD000CB.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%47761FAF035E
      //## Role: CETBrowserService::hSocket%47761FB001BC
      //## begin CETBrowserService::hSocket%47761FB001BC.role preserve=no  public: SOCKET {1..1 -> 1..1VFHN}
      SOCKET m_hSocket;
      //## end CETBrowserService::hSocket%47761FB001BC.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%477624F702AE
      //## Role: CETBrowserService::hEvent%477624F800D9
      //## begin CETBrowserService::hEvent%477624F800D9.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hEvent;
      //## end CETBrowserService::hEvent%477624F800D9.role

    // Additional Private Declarations
      //## begin CETBrowserService%47761E500146.private preserve=yes
      //## end CETBrowserService%47761E500146.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETBrowserService%47761E500146.implementation preserve=yes
      //## end CETBrowserService%47761E500146.implementation

};

//## begin CETBrowserService%47761E500146.postscript preserve=yes
//## end CETBrowserService%47761E500146.postscript

// Class CETBrowserService 

//## begin module%47761E4002CA.epilog preserve=yes
//## end module%47761E4002CA.epilog


#endif
