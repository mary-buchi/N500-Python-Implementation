//## begin module%3DF72EE00017.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DF72EE00017.cm

//## begin module%3DF72EE00017.cp preserve=no
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
//## end module%3DF72EE00017.cp

//## Module: EBETchdg%3DF72EE00017; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchdg.h

#ifndef EBETchdg_h
#define EBETchdg_h 1

//## begin module%3DF72EE00017.additionalIncludes preserve=no
//## end module%3DF72EE00017.additionalIncludes

//## begin module%3DF72EE00017.includes preserve=yes
//## end module%3DF72EE00017.includes

// EBETchan
#include "EBETchan.h"
//## begin module%3DF72EE00017.declarations preserve=no
//## end module%3DF72EE00017.declarations

//## begin module%3DF72EE00017.additionalDeclarations preserve=yes
//## end module%3DF72EE00017.additionalDeclarations


//## begin CETChannelDiagnostics%3DF72EBF025A.preface preserve=yes
//## end CETChannelDiagnostics%3DF72EBF025A.preface

//## Class: CETChannelDiagnostics%3DF72EBF025A
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF72F9F025A;IPIDiagnosticInterface { -> }
//## Uses: <unnamed>%3DF72FA102B7;CETChannelMessage { -> }
//## Uses: <unnamed>%3DF72FA30363;XCOException { -> }
//## Uses: <unnamed>%3DF72FA50344;CPIObjectFactory { -> }
//## Uses: <unnamed>%3DF72FA70344;CETChannelWriter { -> }

class CETChannelDiagnostics : public CETChannel  //## Inherits: <unnamed>%3DF72F3402E6
{
  //## begin CETChannelDiagnostics%3DF72EBF025A.initialDeclarations preserve=yes
  //## end CETChannelDiagnostics%3DF72EBF025A.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelDiagnostics();

    //## Destructor (generated)
      virtual ~CETChannelDiagnostics();


    //## Other Operations (specified)
      //## Operation: UnwrapTelegram%1039609797
      virtual CETChannelMessage* UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength);

    // Additional Public Declarations
      //## begin CETChannelDiagnostics%3DF72EBF025A.public preserve=yes
      //## end CETChannelDiagnostics%3DF72EBF025A.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessMessage%1039609788
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartup%1039609789
      virtual void OnStartup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnShutdown%1039609790
      virtual void OnShutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnReadDWord%1039609791
      virtual void OnReadDWord (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnWriteDWord%1039609792
      virtual void OnWriteDWord (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnEnableEventSignalisation%1066286191
      virtual void OnEnableEventSignalisation (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnDisableEventSignalisation%1066286192
      virtual void OnDisableEventSignalisation (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPCSetNomVoltage%1095062172
      virtual void OnPCSetNomVoltage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPCLampSelection%1095062173
      virtual void OnPCLampSelection (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPCLampOnOff%1095062174
      virtual void OnPCLampOnOff (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPCGetActCurrent%1095062175
      virtual void OnPCGetActCurrent (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPCGetActVoltage%1095062176
      virtual void OnPCGetActVoltage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnPCGetLampIdentification%1095062177
      virtual void OnPCGetLampIdentification (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnWCGetActVelocityCounts%1095062178
      virtual void OnWCGetActVelocityCounts (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnWCGetLastVelocityCounts%1095062179
      virtual void OnWCGetLastVelocityCounts (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnWCGetPosition%1095062180
      virtual void OnWCGetPosition (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnWCInitializeDAC%1095062181
      virtual void OnWCInitializeDAC (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnWCSetDACValue%1095062182
      virtual void OnWCSetDACValue (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnReadFpgaArtNr%1095062183
      virtual void OnReadFpgaArtNr (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnReadFpgaSwVersion%1095062184
      virtual void OnReadFpgaSwVersion (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnI2CEpromByteRead%1095062185
      virtual void OnI2CEpromByteRead (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnI2CEpromByteWrite%1095062186
      virtual void OnI2CEpromByteWrite (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnGetDigitsLaserLevelDetection%1097656363
      virtual void OnGetDigitsLaserLevelDetection (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnReleaseHWReset%1097656364
      virtual void OnReleaseHWReset (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnDisableWatchdog%1097656365
      virtual void OnDisableWatchdog (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnGetOsVersion%1108366392
      virtual void OnGetOsVersion (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnGetUsedMemory%1174554256
      virtual void OnGetUsedMemory (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnGetMemoryAllocInfo%1174997742
      virtual void OnGetMemoryAllocInfo (CETChannelMessageEnvoy* p_pMsg);

    // Additional Protected Declarations
      //## begin CETChannelDiagnostics%3DF72EBF025A.protected preserve=yes
      //## end CETChannelDiagnostics%3DF72EBF025A.protected

  private:
    //## Constructors (generated)
      CETChannelDiagnostics(const CETChannelDiagnostics &right);

    //## Assignment Operation (generated)
      const CETChannelDiagnostics & operator=(const CETChannelDiagnostics &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelDiagnostics &right) const;

      bool operator!=(const CETChannelDiagnostics &right) const;

    // Additional Private Declarations
      //## begin CETChannelDiagnostics%3DF72EBF025A.private preserve=yes
      //## end CETChannelDiagnostics%3DF72EBF025A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelDiagnostics%3DF72EBF025A.implementation preserve=yes
      //## end CETChannelDiagnostics%3DF72EBF025A.implementation

};

//## begin CETChannelDiagnostics%3DF72EBF025A.postscript preserve=yes
//## end CETChannelDiagnostics%3DF72EBF025A.postscript

// Class CETChannelDiagnostics 

//## begin module%3DF72EE00017.epilog preserve=yes
//## end module%3DF72EE00017.epilog


#endif
