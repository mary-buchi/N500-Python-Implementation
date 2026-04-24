//## begin module%3DA14874033F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA14874033F.cm

//## begin module%3DA14874033F.cp preserve=no
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
//## end module%3DA14874033F.cp

//## Module: EBETread%3DA14874033F; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETread.h

#ifndef EBETread_h
#define EBETread_h 1

//## begin module%3DA14874033F.additionalIncludes preserve=no
//## end module%3DA14874033F.additionalIncludes

//## begin module%3DA14874033F.includes preserve=yes
//## end module%3DA14874033F.includes

// EBETthrd
#include "EBETthrd.h"

class CETChannel;
class CETChannelReaderDataPackage;
class CETChannelWriter;

//## begin module%3DA14874033F.declarations preserve=no
//## end module%3DA14874033F.declarations

//## begin module%3DA14874033F.additionalDeclarations preserve=yes
//## end module%3DA14874033F.additionalDeclarations


//## begin CETChannelReader%3DA148910273.preface preserve=yes
//## end CETChannelReader%3DA148910273.preface

//## Class: CETChannelReader%3DA148910273
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DA2B9FC027E;CETChannelMessage { -> }
//## Uses: <unnamed>%468BB2B5003C;CETFileLogger { -> }

class CETChannelReader : public CETThread  //## Inherits: <unnamed>%3DA3D06803CE
{
  //## begin CETChannelReader%3DA148910273.initialDeclarations preserve=yes
  //## end CETChannelReader%3DA148910273.initialDeclarations

  public:
    //## begin CETChannelReader::DataPackageHandler%3DB3E3CD032E.preface preserve=yes
    //## end CETChannelReader::DataPackageHandler%3DB3E3CD032E.preface

    //## Class: DataPackageHandler%3DB3E3CD032E
    //## Category: EBET (Ethernet Transport)%3D9D858B01A0
    //## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef bool (CETChannelReader::* DataPackageHandler)() ;

    //## begin CETChannelReader::DataPackageHandler%3DB3E3CD032E.postscript preserve=yes
    //## end CETChannelReader::DataPackageHandler%3DB3E3CD032E.postscript

    //## Constructors (specified)
      //## Operation: CETChannelReader%1033980241
      CETChannelReader (CETChannel* p_pContext, const CString& p_sName, SOCKET p_hSocket, HANDLE p_hSocketEvent, CETChannelWriter* p_pWriter);

    //## Destructor (generated)
      virtual ~CETChannelReader();


    //## Other Operations (specified)
      //## Operation: End%1183386646
      void End ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: bDisconnected%3F6F0ECB0164
      bool GetbDisconnected ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA14903014B
      //## Role: CETChannelReader::hSocket%3DA1490400A0
      SOCKET GethSocket ();

  public:
    // Additional Public Declarations
      //## begin CETChannelReader%3DA148910273.public preserve=yes
      //## end CETChannelReader%3DA148910273.public

  protected:

    //## Other Operations (specified)
      //## Operation: ThreadMain%1033980243
      virtual DWORD ThreadMain ();

      //## Operation: ReadData%1033980244
      //	throws XETExceptionConnectionLost when the termination
      //	event has been signalled,
      //
      //	returns true, if the data is valid,
      //	and false, if the thread has to enter the disconnected
      //	state
      bool ReadData (DWORD& p_dwReadBytes, CETChannelReaderDataPackage* p_pDataPackage);

    // Additional Protected Declarations
      //## begin CETChannelReader%3DA148910273.protected preserve=yes
      //## end CETChannelReader%3DA148910273.protected

  private:
    //## Constructors (generated)
      CETChannelReader();

      CETChannelReader(const CETChannelReader &right);

    //## Assignment Operation (generated)
      const CETChannelReader & operator=(const CETChannelReader &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelReader &right) const;

      bool operator!=(const CETChannelReader &right) const;


    //## Other Operations (specified)
      //## Operation: ExpectNewTelegram%1035183484
      bool ExpectNewTelegram ();

      //## Operation: ExpectNextDataPackage%1035183485
      bool ExpectNextDataPackage ();

      //## Operation: ExpectMinimalDataPackage%1064564699
      bool ExpectMinimalDataPackage ();

      //## Operation: DoDisconnected%1057242738
      bool DoDisconnected ();

      //## Operation: DoEnded%1183386644
      bool DoEnded ();

      //## Operation: MergeTempDataPackages%1035183488
      CETChannelReaderDataPackage* MergeTempDataPackages ();

      //## Operation: HandleNewDataPackage%1064516449
      bool HandleNewDataPackage (CETChannelReaderDataPackage* p_pDataPackage);

    // Data Members for Class Attributes

      //## Attribute: pmfnDataPackageHandler%3DB3E446034D
      //## begin CETChannelReader::pmfnDataPackageHandler%3DB3E446034D.attr preserve=no  private: DataPackageHandler {U} NULL
      DataPackageHandler m_pmfnDataPackageHandler;
      //## end CETChannelReader::pmfnDataPackageHandler%3DB3E446034D.attr

      //## Attribute: dwTotalReadBytes%3DB3EA480021
      //## begin CETChannelReader::dwTotalReadBytes%3DB3EA480021.attr preserve=no  private: DWORD {U} 0
      DWORD m_dwTotalReadBytes;
      //## end CETChannelReader::dwTotalReadBytes%3DB3EA480021.attr

      //## Attribute: dwCurrentTelegramSize%3DB3EB390244
      //## begin CETChannelReader::dwCurrentTelegramSize%3DB3EB390244.attr preserve=no  private: DWORD {U} 0
      DWORD m_dwCurrentTelegramSize;
      //## end CETChannelReader::dwCurrentTelegramSize%3DB3EB390244.attr

      //## begin CETChannelReader::bDisconnected%3F6F0ECB0164.attr preserve=no  public: bool {U} false
      bool m_bDisconnected;
      //## end CETChannelReader::bDisconnected%3F6F0ECB0164.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA14903014B
      //## begin CETChannelReader::hSocket%3DA1490400A0.role preserve=no  public: SOCKET {1..1 -> 1..1VHN}
      SOCKET m_hSocket;
      //## end CETChannelReader::hSocket%3DA1490400A0.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA17DB00300
      //## Role: CETChannelReader::hDataEvent%3DA17DB101E7
      //## begin CETChannelReader::hDataEvent%3DA17DB101E7.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hDataEvent;
      //## end CETChannelReader::hDataEvent%3DA17DB101E7.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DA47E0500F0
      //## Role: CETChannelReader::pContext%3DA47E060071
      //## begin CETChannelReader::pContext%3DA47E060071.role preserve=no  public: CETChannel {1..1 -> 1..1RFHN}
      CETChannel *m_pContext;
      //## end CETChannelReader::pContext%3DA47E060071.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DB3E1CB0253
      //## Role: CETChannelReader::uiDataBufferSize%3DB3E1CC00DC
      //## begin CETChannelReader::uiDataBufferSize%3DB3E1CC00DC.role preserve=no  public: static UINT {1..1 -> 1..1VFHN}
      static UINT m_uiDataBufferSize;
      //## end CETChannelReader::uiDataBufferSize%3DB3E1CC00DC.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DB3E6790030
      //## Role: CETChannelReader::TempDataPackages%3DB3E67902C1
      //## begin CETChannelReader::TempDataPackages%3DB3E67902C1.role preserve=no  public: CETChannelReaderDataPackage {0 -> nRFHN}
      CTypedPtrList<CPtrList, CETChannelReaderDataPackage*> m_TempDataPackages;
      //## end CETChannelReader::TempDataPackages%3DB3E67902C1.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%456DA02B00AB
      //## Role: CETChannelReader::hSocketEvent%456DA02C0202
      //## begin CETChannelReader::hSocketEvent%456DA02C0202.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hSocketEvent;
      //## end CETChannelReader::hSocketEvent%456DA02C0202.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%456DA0C70041
      //## Role: CETChannelReader::pWriter%456DA0C702A4
      //## begin CETChannelReader::pWriter%456DA0C702A4.role preserve=no  public: CETChannelWriter {1..1 -> 1..1RFHN}
      CETChannelWriter *m_pWriter;
      //## end CETChannelReader::pWriter%456DA0C702A4.role

      //## Association: EBET (Ethernet Transport)::<unnamed>%468914CD02A2
      //## Role: CETChannelReader::hEndEvent%468914CE01DC
      //## begin CETChannelReader::hEndEvent%468914CE01DC.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hEndEvent;
      //## end CETChannelReader::hEndEvent%468914CE01DC.role

    // Additional Private Declarations
      //## begin CETChannelReader%3DA148910273.private preserve=yes
      //## end CETChannelReader%3DA148910273.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelReader%3DA148910273.implementation preserve=yes
      //## end CETChannelReader%3DA148910273.implementation

};

//## begin CETChannelReader%3DA148910273.postscript preserve=yes
//## end CETChannelReader%3DA148910273.postscript

//## begin CETChannelReaderDataPackage%3DB3E5F50188.preface preserve=yes
//## end CETChannelReaderDataPackage%3DB3E5F50188.preface

//## Class: CETChannelReaderDataPackage%3DB3E5F50188
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CETChannelReaderDataPackage 
{
  //## begin CETChannelReaderDataPackage%3DB3E5F50188.initialDeclarations preserve=yes
  //## end CETChannelReaderDataPackage%3DB3E5F50188.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CETChannelReaderDataPackage%1035183486
      CETChannelReaderDataPackage (UINT p_uiSize);

      //## Operation: CETChannelReaderDataPackage%1064516448
      CETChannelReaderDataPackage (BYTE* p_pbyDataPackage, UINT p_uiSize);

    //## Destructor (generated)
      virtual ~CETChannelReaderDataPackage();


    //## Other Operations (specified)
      //## Operation: DetermineTotalTelegramSize%1035183487
      DWORD DetermineTotalTelegramSize ();

      //## Operation: ExtractMessage%1043747867
      void ExtractMessage (UINT p_uiSize);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: uiBufferSize%3DB3E621039B
      UINT GetuiBufferSize ();

      //## Attribute: uiDataSize%3DB3F39B005F
      UINT GetuiDataSize ();
      void SetuiDataSize (UINT value);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DB3E748034D
      //## Role: CETChannelReaderDataPackage::Data%3DB3E7490253
      WSABUF& GetData ();

    // Additional Public Declarations
      //## begin CETChannelReaderDataPackage%3DB3E5F50188.public preserve=yes
      //## end CETChannelReaderDataPackage%3DB3E5F50188.public

  protected:
    // Additional Protected Declarations
      //## begin CETChannelReaderDataPackage%3DB3E5F50188.protected preserve=yes
      //## end CETChannelReaderDataPackage%3DB3E5F50188.protected

  private:
    //## Constructors (generated)
      CETChannelReaderDataPackage();

      CETChannelReaderDataPackage(const CETChannelReaderDataPackage &right);

    //## Assignment Operation (generated)
      const CETChannelReaderDataPackage & operator=(const CETChannelReaderDataPackage &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelReaderDataPackage &right) const;

      bool operator!=(const CETChannelReaderDataPackage &right) const;

    // Data Members for Class Attributes

      //## begin CETChannelReaderDataPackage::uiBufferSize%3DB3E621039B.attr preserve=no  public: UINT {U} p_uiSize
      UINT m_uiBufferSize;
      //## end CETChannelReaderDataPackage::uiBufferSize%3DB3E621039B.attr

      //## begin CETChannelReaderDataPackage::uiDataSize%3DB3F39B005F.attr preserve=no  public: UINT {U} 0
      UINT m_uiDataSize;
      //## end CETChannelReaderDataPackage::uiDataSize%3DB3F39B005F.attr

    // Data Members for Associations

      //## Association: EBET (Ethernet Transport)::<unnamed>%3DB3E748034D
      //## begin CETChannelReaderDataPackage::Data%3DB3E7490253.role preserve=no  public: WSABUF {1..1 -> 1..1VFHN}
      WSABUF m_Data;
      //## end CETChannelReaderDataPackage::Data%3DB3E7490253.role

    // Additional Private Declarations
      //## begin CETChannelReaderDataPackage%3DB3E5F50188.private preserve=yes
      //## end CETChannelReaderDataPackage%3DB3E5F50188.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelReaderDataPackage%3DB3E5F50188.implementation preserve=yes
      //## end CETChannelReaderDataPackage%3DB3E5F50188.implementation

};

//## begin CETChannelReaderDataPackage%3DB3E5F50188.postscript preserve=yes
//## end CETChannelReaderDataPackage%3DB3E5F50188.postscript

// Class CETChannelReader 

// Class CETChannelReaderDataPackage 

//## begin module%3DA14874033F.epilog preserve=yes
//## end module%3DA14874033F.epilog


#endif
