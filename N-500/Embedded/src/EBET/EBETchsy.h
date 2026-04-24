//## begin module%3EE5C047006F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE5C047006F.cm

//## begin module%3EE5C047006F.cp preserve=no
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
//## end module%3EE5C047006F.cp

//## Module: EBETchsy%3EE5C047006F; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchsy.h

#ifndef EBETchsy_h
#define EBETchsy_h 1

//## begin module%3EE5C047006F.additionalIncludes preserve=no
//## end module%3EE5C047006F.additionalIncludes

//## begin module%3EE5C047006F.includes preserve=yes
//## end module%3EE5C047006F.includes

// EBETchan
#include "EBETchan.h"
//## begin module%3EE5C047006F.declarations preserve=no
//## end module%3EE5C047006F.declarations

//## begin module%3EE5C047006F.additionalDeclarations preserve=yes
//## end module%3EE5C047006F.additionalDeclarations


//## begin CETChannelSystem%3EE5C01E031F.preface preserve=yes
//## end CETChannelSystem%3EE5C01E031F.preface

//## Class: CETChannelSystem%3EE5C01E031F
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EE5C3BF0169;IPISystemInterface { -> }
//## Uses: <unnamed>%3EE5C3C10198;CETChannelMessage { -> }
//## Uses: <unnamed>%3EE5C3C3013A;XCOException { -> }
//## Uses: <unnamed>%3EE5C3C50292;CPIObjectFactory { -> }
//## Uses: <unnamed>%3EE5C3C800AE;CETChannelWriter { -> }
//## Uses: <unnamed>%468E06C7008C;CETSession { -> }
//## Uses: <unnamed>%468E06D703B0;CETFileLogger { -> }

class CETChannelSystem : public CETChannel  //## Inherits: <unnamed>%3EE5C0A2033E
{
  //## begin CETChannelSystem%3EE5C01E031F.initialDeclarations preserve=yes
  //## end CETChannelSystem%3EE5C01E031F.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelSystem();

    //## Destructor (generated)
      virtual ~CETChannelSystem();


    //## Other Operations (specified)
      //## Operation: UnwrapTelegram%1055243196
      virtual CETChannelMessage* UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength);

    // Additional Public Declarations
      //## begin CETChannelSystem%3EE5C01E031F.public preserve=yes
      //## end CETChannelSystem%3EE5C01E031F.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessMessage%1055243197
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartup%1055243198
      virtual void OnStartup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnShutdown%1055243199
      virtual void OnShutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnReadIdentifications%1055243200
      virtual void OnReadIdentifications (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnWriteIdentification%1055243201
      virtual void OnWriteIdentification (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnReadSoftwareVersions%1055243202
      virtual void OnReadSoftwareVersions (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnDownloadSoftwareComponents%1055243203
      virtual void OnDownloadSoftwareComponents (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartDevice%1055243205
      virtual void OnStartDevice (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnResetDevice%1055243206
      virtual void OnResetDevice (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnGetState%1055243207
      virtual void OnGetState (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetInterfaceConfig%1055243208
      virtual void OnSetInterfaceConfig (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetComponentState%1061562115
      virtual void OnSetComponentState (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnGetObjectList%1063715464
      virtual void OnGetObjectList (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetTime%1064429413
      virtual void OnSetTime (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnRegisterClient%1096656412
      virtual void OnRegisterClient (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnGetVersion%1096656421
      virtual void OnGetVersion (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetStandbyTimeout%1096717652
      virtual void OnSetStandbyTimeout (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPing%1101721837
      virtual void OnPing (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnGetOsVersion%1108540802
      virtual void OnGetOsVersion (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnGetFpgaVersion%1108540803
      virtual void OnGetFpgaVersion (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartDownload%1200053481
      virtual void OnStartDownload (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnDownloadSoftwareComponent%1200053482
      virtual void OnDownloadSoftwareComponent (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnEndDownload%1200053483
      virtual void OnEndDownload (CETChannelMessageEnvoy* p_pMsg);

    // Additional Protected Declarations
      //## begin CETChannelSystem%3EE5C01E031F.protected preserve=yes
      //## end CETChannelSystem%3EE5C01E031F.protected

  private:
    //## Constructors (generated)
      CETChannelSystem(const CETChannelSystem &right);

    //## Assignment Operation (generated)
      const CETChannelSystem & operator=(const CETChannelSystem &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelSystem &right) const;

      bool operator!=(const CETChannelSystem &right) const;

    // Additional Private Declarations
      //## begin CETChannelSystem%3EE5C01E031F.private preserve=yes
      //## end CETChannelSystem%3EE5C01E031F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelSystem%3EE5C01E031F.implementation preserve=yes
      //## end CETChannelSystem%3EE5C01E031F.implementation

};

//## begin CETChannelSystem%3EE5C01E031F.postscript preserve=yes
//## end CETChannelSystem%3EE5C01E031F.postscript

// Class CETChannelSystem 

//## begin module%3EE5C047006F.epilog preserve=yes
//## end module%3EE5C047006F.epilog


#endif
