//## begin module%3EE5C0510205.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE5C0510205.cm

//## begin module%3EE5C0510205.cp preserve=no
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
//## end module%3EE5C0510205.cp

//## Module: EBETchi2%3EE5C0510205; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchi2.h

#ifndef EBETchi2_h
#define EBETchi2_h 1

//## begin module%3EE5C0510205.additionalIncludes preserve=no
//## end module%3EE5C0510205.additionalIncludes

//## begin module%3EE5C0510205.includes preserve=yes
//## end module%3EE5C0510205.includes

// EBETchan
#include "EBETchan.h"
//## begin module%3EE5C0510205.declarations preserve=no
//## end module%3EE5C0510205.declarations

//## begin module%3EE5C0510205.additionalDeclarations preserve=yes
//## end module%3EE5C0510205.additionalDeclarations


//## begin CETChannelI2CBus%3EE5D34500AE.preface preserve=yes
//## end CETChannelI2CBus%3EE5D34500AE.preface

//## Class: CETChannelI2CBus%3EE5D34500AE
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EE5E62E01F6;IPII2CTempSensorDS1631Z { -> }
//## Uses: <unnamed>%3EE5E63002E0;CETChannelMessage { -> }
//## Uses: <unnamed>%3EE5E632036D;XCOException { -> }
//## Uses: <unnamed>%3EE5E6350040;CPIObjectFactory { -> }
//## Uses: <unnamed>%3EE5E637011B;CETChannelWriter { -> }

class CETChannelI2CBus : public CETChannel  //## Inherits: <unnamed>%3EE5D36E037C
{
  //## begin CETChannelI2CBus%3EE5D34500AE.initialDeclarations preserve=yes
  //## end CETChannelI2CBus%3EE5D34500AE.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelI2CBus();

    //## Destructor (generated)
      virtual ~CETChannelI2CBus();


    //## Other Operations (specified)
      //## Operation: UnwrapTelegram%1057156748
      virtual CETChannelMessage* UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength);

    // Additional Public Declarations
      //## begin CETChannelI2CBus%3EE5D34500AE.public preserve=yes
      //## end CETChannelI2CBus%3EE5D34500AE.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessMessage%1055243211
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnTempDS1631ZStartup%1055243212
      virtual void OnTempDS1631ZStartup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnTempDS1631ZShutdown%1055243213
      virtual void OnTempDS1631ZShutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnTempDS1631ZSetConfig%1055243214
      virtual void OnTempDS1631ZSetConfig (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnTempDS1631ZGetValue%1055243215
      virtual void OnTempDS1631ZGetValue (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnAdcMax1037Startup%1074861335
      virtual void OnAdcMax1037Startup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnAdcMax1037Shutdown%1074861336
      virtual void OnAdcMax1037Shutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnAdcMax1037Initialize%1074846782
      void OnAdcMax1037Initialize (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnAdcMax1037GetData%1074846783
      void OnAdcMax1037GetData (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPotiAD5245Startup%1074861337
      virtual void OnPotiAD5245Startup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPotiAD5245Shutdown%1074861338
      virtual void OnPotiAD5245Shutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPotiAD5245ReadValue%1074846784
      void OnPotiAD5245ReadValue (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPotiAD5245WriteValue%1074846785
      void OnPotiAD5245WriteValue (CETChannelMessageEnvoy* p_pMsg);

    // Additional Protected Declarations
      //## begin CETChannelI2CBus%3EE5D34500AE.protected preserve=yes
      //## end CETChannelI2CBus%3EE5D34500AE.protected

  private:
    //## Constructors (generated)
      CETChannelI2CBus(const CETChannelI2CBus &right);

    //## Assignment Operation (generated)
      const CETChannelI2CBus & operator=(const CETChannelI2CBus &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelI2CBus &right) const;

      bool operator!=(const CETChannelI2CBus &right) const;

    // Additional Private Declarations
      //## begin CETChannelI2CBus%3EE5D34500AE.private preserve=yes
      //## end CETChannelI2CBus%3EE5D34500AE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelI2CBus%3EE5D34500AE.implementation preserve=yes
      //## end CETChannelI2CBus%3EE5D34500AE.implementation

};

//## begin CETChannelI2CBus%3EE5D34500AE.postscript preserve=yes
//## end CETChannelI2CBus%3EE5D34500AE.postscript

// Class CETChannelI2CBus 

//## begin module%3EE5C0510205.epilog preserve=yes
//## end module%3EE5C0510205.epilog


#endif
