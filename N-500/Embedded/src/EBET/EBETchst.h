//## begin module%3DAAACEB0294.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAACEB0294.cm

//## begin module%3DAAACEB0294.cp preserve=no
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
//## end module%3DAAACEB0294.cp

//## Module: EBETchst%3DAAACEB0294; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchst.h

#ifndef EBETchst_h
#define EBETchst_h 1

//## begin module%3DAAACEB0294.additionalIncludes preserve=no
//## end module%3DAAACEB0294.additionalIncludes

//## begin module%3DAAACEB0294.includes preserve=yes
//## end module%3DAAACEB0294.includes

// EBETchan
#include "EBETchan.h"

class CETChannelMessage;

//## begin module%3DAAACEB0294.declarations preserve=no
//## end module%3DAAACEB0294.declarations

//## begin module%3DAAACEB0294.additionalDeclarations preserve=yes
//## end module%3DAAACEB0294.additionalDeclarations


//## begin CETChannelStepperMotors%3DA58EA500A5.preface preserve=yes
//## end CETChannelStepperMotors%3DA58EA500A5.preface

//## Class: CETChannelStepperMotors%3DA58EA500A5
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAAAE9503CD;CETChannelWriter { -> }
//## Uses: <unnamed>%3DAAAEB40052;CETChannelMessage { -> F}
//## Uses: <unnamed>%3DAAAEC80302;XCOException { -> }
//## Uses: <unnamed>%3DAAAEE801D9;IPIStepperMotorInterface { -> }
//## Uses: <unnamed>%3DAAAEFB039E;CPIObjectFactory { -> }

class CETChannelStepperMotors : public CETChannel  //## Inherits: <unnamed>%3DA58EB1027A
{
  //## begin CETChannelStepperMotors%3DA58EA500A5.initialDeclarations preserve=yes
  //## end CETChannelStepperMotors%3DA58EA500A5.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelStepperMotors();

    //## Destructor (generated)
      virtual ~CETChannelStepperMotors();


    //## Other Operations (specified)
      //## Operation: UnwrapTelegram%1035273380
      virtual CETChannelMessage* UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength);

    // Additional Public Declarations
      //## begin CETChannelStepperMotors%3DA58EA500A5.public preserve=yes
      //## end CETChannelStepperMotors%3DA58EA500A5.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessMessage%1034230448
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartup%1034230449
      virtual void OnStartup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnShutdown%1034407672
      virtual void OnShutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnMoveAbsolute%1035273377
      virtual void OnMoveAbsolute (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnMoveRelative%1036680699
      virtual void OnMoveRelative (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnMoveManual%1036680700
      virtual void OnMoveManual (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnGetPosition%1034575093
      virtual void OnGetPosition (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStop%1036680701
      virtual void OnStop (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStopImmediately%1036680702
      virtual void OnStopImmediately (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetProfile%1036680703
      virtual void OnSetProfile (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetConfig%1049965452
      virtual void OnSetConfig (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetSpeed%1036680704
      virtual void OnSetSpeed (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnLimitAdd%1036680705
      virtual void OnLimitAdd (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnLimitConfig%1036680706
      virtual void OnLimitConfig (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnLimitGetFootPrint%1036680707
      virtual void OnLimitGetFootPrint (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnLimitActivate%1036680708
      virtual void OnLimitActivate (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnLimitDeactivate%1036680709
      virtual void OnLimitDeactivate (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnHome%1036680710
      virtual void OnHome (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnHome2%1193077640
      virtual void OnHome2 (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnHomeSetPosition%1036680711
      virtual void OnHomeSetPosition (CETChannelMessageEnvoy* p_pMsg);

    // Additional Protected Declarations
      //## begin CETChannelStepperMotors%3DA58EA500A5.protected preserve=yes
      //## end CETChannelStepperMotors%3DA58EA500A5.protected

  private:
    //## Constructors (generated)
      CETChannelStepperMotors(const CETChannelStepperMotors &right);

    //## Assignment Operation (generated)
      const CETChannelStepperMotors & operator=(const CETChannelStepperMotors &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelStepperMotors &right) const;

      bool operator!=(const CETChannelStepperMotors &right) const;

    // Additional Private Declarations
      //## begin CETChannelStepperMotors%3DA58EA500A5.private preserve=yes
      //## end CETChannelStepperMotors%3DA58EA500A5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelStepperMotors%3DA58EA500A5.implementation preserve=yes
      //## end CETChannelStepperMotors%3DA58EA500A5.implementation

};

//## begin CETChannelStepperMotors%3DA58EA500A5.postscript preserve=yes
//## end CETChannelStepperMotors%3DA58EA500A5.postscript

// Class CETChannelStepperMotors 

//## begin module%3DAAACEB0294.epilog preserve=yes
//## end module%3DAAACEB0294.epilog


#endif
