//## begin module%3FA65AE00261.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FA65AE00261.cm

//## begin module%3FA65AE00261.cp preserve=no
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
//## end module%3FA65AE00261.cp

//## Module: EBPOsimu%3FA65AE00261; Package specification
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Source file: R:\Embedded\src\EBPO\EBPOsimu.h

#ifndef EBPOsimu_h
#define EBPOsimu_h 1

//## begin module%3FA65AE00261.additionalIncludes preserve=no
//## end module%3FA65AE00261.additionalIncludes

//## begin module%3FA65AE00261.includes preserve=yes
//## end module%3FA65AE00261.includes

// afx
#include "afx.h"
// EBPIintf
#include "EBPIintf.h"


//## begin module%3FA65AE00261.declarations preserve=no
//## end module%3FA65AE00261.declarations

//## begin module%3FA65AE00261.additionalDeclarations preserve=yes
//## end module%3FA65AE00261.additionalDeclarations


//## begin CPOEpromSimulation%3FA65A9C03C8.preface preserve=yes
//## end CPOEpromSimulation%3FA65A9C03C8.preface

//## Class: CPOEpromSimulation%3FA65A9C03C8
//## Category: EBPO (Persistent Object)%3DE4880C0352
//## Subsystem: EBPO (Persistent Object)%3DE487EC01DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%401116DA033A;PO_IDENTIFIERS { -> }

class EBPO_DLL_DECL CPOEpromSimulation : public IPII2CEprom24LC515  //## Inherits: <unnamed>%4010E4D300F0
{
  //## begin CPOEpromSimulation%3FA65A9C03C8.initialDeclarations preserve=yes
  //## end CPOEpromSimulation%3FA65A9C03C8.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPOEpromSimulation%1067863157
      CPOEpromSimulation (LPCTSTR p_uiFileName);

    //## Destructor (generated)
      virtual ~CPOEpromSimulation();


    //## Other Operations (specified)
      //## Operation: ByteRead%1074846582
      //	DESCRIPTION
      //	Reads a byte from the specific eprom address
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObjectInt* ByteRead (WORD p_uiAddress);

      //## Operation: BlockRead%1074846583
      //	DESCRIPTION
      //	Reads a number of byte from the specific eprom address
      //
      //	RETURNS
      //	async void
      virtual CPISyncObjI2CDataStream* BlockRead (WORD p_uiAddress, UINT p_uiSize);

      //## Operation: ReadContent%1074846584
      //	DESCRIPTION
      //	Reads the all contents of the eprom
      //
      //	RETURNS
      //	void
      virtual CPISyncObjI2CDataStream* ReadContent ();

      //## Operation: ByteWrite%1074846585
      //	DESCRIPTION
      //	writes a byte to the specific eprom address
      virtual CCOSyncObject* ByteWrite (WORD p_uiAddress, BYTE p_cValue);

      //## Operation: PageWrite%1074846586
      //	DESCRIPTION
      //	writes a page size (max 64 byte) to the specific eprom
      //	address
      virtual CCOSyncObject* PageWrite (WORD p_uiAddress, BYTE* p_pcValue, UINT p_uiSize);

      //## Operation: WriteContent%1074846587
      //	DESCRIPTION
      //	writes the specified contents to the eprom
      //
      //	RETURNS
      //	void
      virtual CCOSyncObject* WriteContent (BYTE* &p_pContent, UINT p_uiDataSize);

      //## Operation: GetEprom24LC515SizeInByte%1074846588
      //	DESCRIPTION
      //	Gets the eprom size in byte
      //
      //	RETURNS
      //	size in byte
      virtual UINT GetEprom24LC515SizeInByte ();

      //## Operation: GetEprom24LC515PageSizeInByte%1074846589
      //	DESCRIPTION
      //	Gets the eprom page size in byte
      //
      //	RETURNS
      //	page size in byte
      virtual UINT GetEprom24LC515PageSizeInByte ();

      //## Operation: GetuiID%1074846598
      virtual UINT GetuiID ();

      //## Operation: Startup%1074846599
      //	DESCRIPTION
      //	Links the object to the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Startup ();

      //## Operation: Shutdown%1074846600
      //	DESCRIPTION
      //	Detaches the object from the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Shutdown ();

      //## Operation: ConnectionEstablished%1074846601
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1074846602
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

    // Additional Public Declarations
      //## begin CPOEpromSimulation%3FA65A9C03C8.public preserve=yes
      //## end CPOEpromSimulation%3FA65A9C03C8.public

  protected:
    // Additional Protected Declarations
      //## begin CPOEpromSimulation%3FA65A9C03C8.protected preserve=yes
      //## end CPOEpromSimulation%3FA65A9C03C8.protected

  private:
    //## Constructors (generated)
      CPOEpromSimulation();

      CPOEpromSimulation(const CPOEpromSimulation &right);

    //## Assignment Operation (generated)
      const CPOEpromSimulation & operator=(const CPOEpromSimulation &right);

    //## Equality Operations (generated)
      bool operator==(const CPOEpromSimulation &right) const;

      bool operator!=(const CPOEpromSimulation &right) const;


    //## Other Operations (specified)
      //## Operation: OpenFile%1067863158
      void OpenFile ();

      //## Operation: CloseFile%1067863159
      void CloseFile ();

    // Data Members for Associations

      //## Association: EBPO (Persistent Object)::<unnamed>%3FA666620148
      //## Role: CPOEpromSimulation::File%3FA6666202AF
      //## begin CPOEpromSimulation::File%3FA6666202AF.role preserve=no  public: CFile {1..1 -> 1..1VFHN}
      CFile m_File;
      //## end CPOEpromSimulation::File%3FA6666202AF.role

      //## Association: EBPO (Persistent Object)::<unnamed>%3FA666B3004E
      //## Role: CPOEpromSimulation::sFileName%3FA666B301D4
      //## begin CPOEpromSimulation::sFileName%3FA666B301D4.role preserve=no  public: CString {1..1 -> 1..1VHN}
      CString m_sFileName;
      //## end CPOEpromSimulation::sFileName%3FA666B301D4.role

    // Additional Private Declarations
      //## begin CPOEpromSimulation%3FA65A9C03C8.private preserve=yes
      //## end CPOEpromSimulation%3FA65A9C03C8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPOEpromSimulation%3FA65A9C03C8.implementation preserve=yes
      //## end CPOEpromSimulation%3FA65A9C03C8.implementation

};

//## begin CPOEpromSimulation%3FA65A9C03C8.postscript preserve=yes
//## end CPOEpromSimulation%3FA65A9C03C8.postscript

// Class CPOEpromSimulation 

//## begin module%3FA65AE00261.epilog preserve=yes
//## end module%3FA65AE00261.epilog


#endif
