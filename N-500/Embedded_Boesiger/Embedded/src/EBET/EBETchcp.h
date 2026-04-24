//## begin module%3DBC092B01A8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC092B01A8.cm

//## begin module%3DBC092B01A8.cp preserve=no
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
//## end module%3DBC092B01A8.cp

//## Module: EBETchcp%3DBC092B01A8; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchcp.h

#ifndef EBETchcp_h
#define EBETchcp_h 1

//## begin module%3DBC092B01A8.additionalIncludes preserve=no
//## end module%3DBC092B01A8.additionalIncludes

//## begin module%3DBC092B01A8.includes preserve=yes
//## end module%3DBC092B01A8.includes

// EBETchan
#include "EBETchan.h"
//## begin module%3DBC092B01A8.declarations preserve=no
//## end module%3DBC092B01A8.declarations

//## begin module%3DBC092B01A8.additionalDeclarations preserve=yes
//## end module%3DBC092B01A8.additionalDeclarations


//## begin CETChannelControlPower%3DBC088203AE.preface preserve=yes
//## end CETChannelControlPower%3DBC088203AE.preface

//## Class: CETChannelControlPower%3DBC088203AE
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD4145A0126;CETChannelMessage { -> }
//## Uses: <unnamed>%3DD4146100C2;XCOException { -> }
//## Uses: <unnamed>%3DD4148401D1;IPIPowerControlInterface { -> }
//## Uses: <unnamed>%3DD4148D02E2;CPIObjectFactory { -> }
//## Uses: <unnamed>%3DD4149F018A;CETChannelWriter { -> }

class CETChannelControlPower : public CETChannel  //## Inherits: <unnamed>%3DBC09E002AD
{
  //## begin CETChannelControlPower%3DBC088203AE.initialDeclarations preserve=yes
  //## end CETChannelControlPower%3DBC088203AE.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelControlPower();

    //## Destructor (generated)
      virtual ~CETChannelControlPower();


    //## Other Operations (specified)
      //## Operation: UnwrapTelegram%1037257515
      virtual CETChannelMessage* UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength);

    // Additional Public Declarations
      //## begin CETChannelControlPower%3DBC088203AE.public preserve=yes
      //## end CETChannelControlPower%3DBC088203AE.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessMessage%1035733647
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartup%1035733648
      virtual void OnStartup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnShutdown%1035733649
      virtual void OnShutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetProfile%1037257511
      virtual void OnSetProfile (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetConfiguration%1037308030
      virtual void OnSetConfiguration (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStart%1037257513
      virtual void OnStart (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStop%1037257514
      virtual void OnStop (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPowerOn%1076659629
      virtual void OnPowerOn (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPowerOff%1076659630
      virtual void OnPowerOff (CETChannelMessageEnvoy* p_pMsg);

    // Additional Protected Declarations
      //## begin CETChannelControlPower%3DBC088203AE.protected preserve=yes
      //## end CETChannelControlPower%3DBC088203AE.protected

  private:
    //## Constructors (generated)
      CETChannelControlPower(const CETChannelControlPower &right);

    //## Assignment Operation (generated)
      const CETChannelControlPower & operator=(const CETChannelControlPower &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelControlPower &right) const;

      bool operator!=(const CETChannelControlPower &right) const;

    // Additional Private Declarations
      //## begin CETChannelControlPower%3DBC088203AE.private preserve=yes
      //## end CETChannelControlPower%3DBC088203AE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelControlPower%3DBC088203AE.implementation preserve=yes
      //## end CETChannelControlPower%3DBC088203AE.implementation

};

//## begin CETChannelControlPower%3DBC088203AE.postscript preserve=yes
//## end CETChannelControlPower%3DBC088203AE.postscript

// Class CETChannelControlPower 

//## begin module%3DBC092B01A8.epilog preserve=yes
//## end module%3DBC092B01A8.epilog


#endif
