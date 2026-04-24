//## begin module%3DAAACFA01C9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAACFA01C9.cm

//## begin module%3DAAACFA01C9.cp preserve=no
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
//## end module%3DAAACFA01C9.cp

//## Module: EBETchmc%3DAAACFA01C9; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchmc.h

#ifndef EBETchmc_h
#define EBETchmc_h 1

//## begin module%3DAAACFA01C9.additionalIncludes preserve=no
//## end module%3DAAACFA01C9.additionalIncludes

//## begin module%3DAAACFA01C9.includes preserve=yes
//## end module%3DAAACFA01C9.includes

// EBETchan
#include "EBETchan.h"

class CETChannelMessage;

//## begin module%3DAAACFA01C9.declarations preserve=no
//## end module%3DAAACFA01C9.declarations

//## begin module%3DAAACFA01C9.additionalDeclarations preserve=yes
//## end module%3DAAACFA01C9.additionalDeclarations


//## begin CETChannelMeasurementChannel%3DAAAFC6014C.preface preserve=yes
//## end CETChannelMeasurementChannel%3DAAAFC6014C.preface

//## Class: CETChannelMeasurementChannel%3DAAAFC6014C
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAAB0B001E8;CETChannelMessage { -> F}
//## Uses: <unnamed>%3DAAB0C701B9;XCOException { -> }
//## Uses: <unnamed>%3DAAB0D701B9;CETChannelWriter { -> }
//## Uses: <unnamed>%3DAFAAF20153;IPIMeasurementChannelInterface { -> }
//## Uses: <unnamed>%468BB24702F0;CPIObjectFactory { -> }

class CETChannelMeasurementChannel : public CETChannel  //## Inherits: <unnamed>%3DAAAFFD0014
{
  //## begin CETChannelMeasurementChannel%3DAAAFC6014C.initialDeclarations preserve=yes
  //## end CETChannelMeasurementChannel%3DAAAFC6014C.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelMeasurementChannel();

    //## Destructor (generated)
      virtual ~CETChannelMeasurementChannel();


    //## Other Operations (specified)
      //## Operation: UnwrapTelegram%1037103470
      virtual CETChannelMessage* UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength);

    // Additional Public Declarations
      //## begin CETChannelMeasurementChannel%3DAAAFC6014C.public preserve=yes
      //## end CETChannelMeasurementChannel%3DAAAFC6014C.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessMessage%1034575098
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartup%1034575099
      virtual void OnStartup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnShutdown%1034575100
      virtual void OnShutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetProfile%1037103466
      virtual void OnSetProfile (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnInitialize%1037103467
      virtual void OnInitialize (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStart%1037103468
      virtual void OnStart (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStop%1037103469
      virtual void OnStop (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnGetDataPackage%1034835018
      virtual void OnGetDataPackage (CETChannelMessageEnvoy* p_pMsg);

    // Additional Protected Declarations
      //## begin CETChannelMeasurementChannel%3DAAAFC6014C.protected preserve=yes
      //## end CETChannelMeasurementChannel%3DAAAFC6014C.protected

  private:
    //## Constructors (generated)
      CETChannelMeasurementChannel(const CETChannelMeasurementChannel &right);

    //## Assignment Operation (generated)
      const CETChannelMeasurementChannel & operator=(const CETChannelMeasurementChannel &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelMeasurementChannel &right) const;

      bool operator!=(const CETChannelMeasurementChannel &right) const;

    // Additional Private Declarations
      //## begin CETChannelMeasurementChannel%3DAAAFC6014C.private preserve=yes
      //## end CETChannelMeasurementChannel%3DAAAFC6014C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelMeasurementChannel%3DAAAFC6014C.implementation preserve=yes
      //## end CETChannelMeasurementChannel%3DAAAFC6014C.implementation

};

//## begin CETChannelMeasurementChannel%3DAAAFC6014C.postscript preserve=yes
//## end CETChannelMeasurementChannel%3DAAAFC6014C.postscript

// Class CETChannelMeasurementChannel 

//## begin module%3DAAACFA01C9.epilog preserve=yes
//## end module%3DAAACFA01C9.epilog


#endif
