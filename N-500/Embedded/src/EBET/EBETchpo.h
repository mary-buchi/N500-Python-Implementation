//## begin module%3DBC08CF0188.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC08CF0188.cm

//## begin module%3DBC08CF0188.cp preserve=no
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
//## end module%3DBC08CF0188.cp

//## Module: EBETchpo%3DBC08CF0188; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchpo.h

#ifndef EBETchpo_h
#define EBETchpo_h 1

//## begin module%3DBC08CF0188.additionalIncludes preserve=no
//## end module%3DBC08CF0188.additionalIncludes

//## begin module%3DBC08CF0188.includes preserve=yes
//## end module%3DBC08CF0188.includes

// EBETchan
#include "EBETchan.h"
//## begin module%3DBC08CF0188.declarations preserve=no
//## end module%3DBC08CF0188.declarations

//## begin module%3DBC08CF0188.additionalDeclarations preserve=yes
//## end module%3DBC08CF0188.additionalDeclarations


//## begin CETChannelPersistentObjects%3DBC082C02E2.preface preserve=yes
//## end CETChannelPersistentObjects%3DBC082C02E2.preface

//## Class: CETChannelPersistentObjects%3DBC082C02E2
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD4EF3F00D5;IPIPersistentObjInterface { -> }
//## Uses: <unnamed>%3DD4F3360365;CETChannelMessage { -> }
//## Uses: <unnamed>%3DD4F3C80077;XCOException { -> }
//## Uses: <unnamed>%3DD4F3D30123;CPIObjectFactory { -> }
//## Uses: <unnamed>%3DD4F3DB00B6;CETChannelWriter { -> }

class CETChannelPersistentObjects : public CETChannel  //## Inherits: <unnamed>%3DBC09BC0125
{
  //## begin CETChannelPersistentObjects%3DBC082C02E2.initialDeclarations preserve=yes
  //## end CETChannelPersistentObjects%3DBC082C02E2.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelPersistentObjects();

    //## Destructor (generated)
      virtual ~CETChannelPersistentObjects();


    //## Other Operations (specified)
      //## Operation: UnwrapTelegram%1037346571
      virtual CETChannelMessage* UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength);

    // Additional Public Declarations
      //## begin CETChannelPersistentObjects%3DBC082C02E2.public preserve=yes
      //## end CETChannelPersistentObjects%3DBC082C02E2.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessMessage%1035733663
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartup%1035733664
      virtual void OnStartup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnShutdown%1035733665
      virtual void OnShutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnReadParameters%1037346576
      virtual void OnReadParameters (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnWriteParameter%1037346577
      virtual void OnWriteParameter (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartMonitoring%1074087101
      //	Starts counting operating data (life time counter)
      virtual void OnStartMonitoring (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStopMonitoring%1074087102
      //	Stop counting operating data (life time counter)
      virtual void OnStopMonitoring (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSave%1074087103
      //	Save data to eprom
      virtual void OnSave (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnReadLifeTimeCounter%1050325541
      virtual void OnReadLifeTimeCounter (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnWriteLifeTimeCounter%1050325542
      virtual void OnWriteLifeTimeCounter (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnReadIdentifications%1037346572
      virtual void OnReadIdentifications (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnWriteIdentification%1037346573
      virtual void OnWriteIdentification (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetConfig%1074087104
      //	Set configuration
      virtual void OnSetConfig (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnReset%1074087105
      //	Reset an eprom section
      virtual void OnReset (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnMeasurementCellUndocked%1080141460
      //	The measurement cell has been undocked - meaning that
      //	the eprom has gone
      virtual void OnMeasurementCellUndocked (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnReadSoftwareVersions%1037346578
      virtual void OnReadSoftwareVersions (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnDownloadSoftwareComponents%1037346579
      virtual void OnDownloadSoftwareComponents (CETChannelMessageEnvoy* p_pMsg);

    // Additional Protected Declarations
      //## begin CETChannelPersistentObjects%3DBC082C02E2.protected preserve=yes
      //## end CETChannelPersistentObjects%3DBC082C02E2.protected

  private:
    //## Constructors (generated)
      CETChannelPersistentObjects(const CETChannelPersistentObjects &right);

    //## Assignment Operation (generated)
      const CETChannelPersistentObjects & operator=(const CETChannelPersistentObjects &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelPersistentObjects &right) const;

      bool operator!=(const CETChannelPersistentObjects &right) const;

    // Additional Private Declarations
      //## begin CETChannelPersistentObjects%3DBC082C02E2.private preserve=yes
      //## end CETChannelPersistentObjects%3DBC082C02E2.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelPersistentObjects%3DBC082C02E2.implementation preserve=yes
      //## end CETChannelPersistentObjects%3DBC082C02E2.implementation

};

//## begin CETChannelPersistentObjects%3DBC082C02E2.postscript preserve=yes
//## end CETChannelPersistentObjects%3DBC082C02E2.postscript

// Class CETChannelPersistentObjects 

//## begin module%3DBC08CF0188.epilog preserve=yes
//## end module%3DBC08CF0188.epilog


#endif
