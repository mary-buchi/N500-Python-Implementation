//## begin module%3DBC093F02E8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC093F02E8.cm

//## begin module%3DBC093F02E8.cp preserve=no
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
//## end module%3DBC093F02E8.cp

//## Module: EBETchcw%3DBC093F02E8; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchcw.h

#ifndef EBETchcw_h
#define EBETchcw_h 1

//## begin module%3DBC093F02E8.additionalIncludes preserve=no
//## end module%3DBC093F02E8.additionalIncludes

//## begin module%3DBC093F02E8.includes preserve=yes
//## end module%3DBC093F02E8.includes

// EBETchan
#include "EBETchan.h"
//## begin module%3DBC093F02E8.declarations preserve=no
//## end module%3DBC093F02E8.declarations

//## begin module%3DBC093F02E8.additionalDeclarations preserve=yes
//## end module%3DBC093F02E8.additionalDeclarations


//## begin CETChannelControlWedge%3DBC0894025F.preface preserve=yes
//## end CETChannelControlWedge%3DBC0894025F.preface

//## Class: CETChannelControlWedge%3DBC0894025F
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD2144803B0;CETChannelMessage { -> }
//## Uses: <unnamed>%3DD2145A0304;XCOException { -> }
//## Uses: <unnamed>%3DD214740297;CETChannelWriter { -> }
//## Uses: <unnamed>%3DD34B1D00BE;IPIWedgeControlInterface { -> }
//## Uses: <unnamed>%3DD34B300283;CPIObjectFactory { -> }

class CETChannelControlWedge : public CETChannel  //## Inherits: <unnamed>%3DBC09E90238
{
  //## begin CETChannelControlWedge%3DBC0894025F.initialDeclarations preserve=yes
  //## end CETChannelControlWedge%3DBC0894025F.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelControlWedge();

    //## Destructor (generated)
      virtual ~CETChannelControlWedge();


    //## Other Operations (specified)
      //## Operation: UnwrapTelegram%1037172636
      virtual CETChannelMessage* UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength);

    // Additional Public Declarations
      //## begin CETChannelControlWedge%3DBC0894025F.public preserve=yes
      //## end CETChannelControlWedge%3DBC0894025F.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessMessage%1035733643
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartup%1035733644
      virtual void OnStartup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnShutdown%1035733645
      virtual void OnShutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetProfile%1037172631
      virtual void OnSetProfile (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetConfig%1037172637
      virtual void OnSetConfig (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnInitialize%1037172632
      virtual void OnInitialize (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnReference%1069774272
      virtual void OnReference (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStart%1037172633
      virtual void OnStart (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStop%1037172634
      virtual void OnStop (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPark%1037172635
      virtual void OnPark (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnGetDacZeroCurrent%1149159893
      virtual void OnGetDacZeroCurrent (CETChannelMessageEnvoy* p_pMsg);

    // Additional Protected Declarations
      //## begin CETChannelControlWedge%3DBC0894025F.protected preserve=yes
      //## end CETChannelControlWedge%3DBC0894025F.protected

  private:
    //## Constructors (generated)
      CETChannelControlWedge(const CETChannelControlWedge &right);

    //## Assignment Operation (generated)
      const CETChannelControlWedge & operator=(const CETChannelControlWedge &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelControlWedge &right) const;

      bool operator!=(const CETChannelControlWedge &right) const;

    // Additional Private Declarations
      //## begin CETChannelControlWedge%3DBC0894025F.private preserve=yes
      //## end CETChannelControlWedge%3DBC0894025F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelControlWedge%3DBC0894025F.implementation preserve=yes
      //## end CETChannelControlWedge%3DBC0894025F.implementation

};

//## begin CETChannelControlWedge%3DBC0894025F.postscript preserve=yes
//## end CETChannelControlWedge%3DBC0894025F.postscript

// Class CETChannelControlWedge 

//## begin module%3DBC093F02E8.epilog preserve=yes
//## end module%3DBC093F02E8.epilog


#endif
