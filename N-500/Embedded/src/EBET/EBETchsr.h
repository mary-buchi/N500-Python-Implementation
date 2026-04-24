//## begin module%3DBC08EB023C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC08EB023C.cm

//## begin module%3DBC08EB023C.cp preserve=no
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
//## end module%3DBC08EB023C.cp

//## Module: EBETchsr%3DBC08EB023C; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchsr.h

#ifndef EBETchsr_h
#define EBETchsr_h 1

//## begin module%3DBC08EB023C.additionalIncludes preserve=no
//## end module%3DBC08EB023C.additionalIncludes

//## begin module%3DBC08EB023C.includes preserve=yes
//## end module%3DBC08EB023C.includes

// EBETchan
#include "EBETchan.h"
//## begin module%3DBC08EB023C.declarations preserve=no
//## end module%3DBC08EB023C.declarations

//## begin module%3DBC08EB023C.additionalDeclarations preserve=yes
//## end module%3DBC08EB023C.additionalDeclarations


//## begin CETChannelSensors%3DBC08530266.preface preserve=yes
//## end CETChannelSensors%3DBC08530266.preface

//## Class: CETChannelSensors%3DBC08530266
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD4D08500D5;CETChannelMessage { -> }
//## Uses: <unnamed>%3DD4D08C01A0;XCOException { -> }
//## Uses: <unnamed>%3DD4D0A20058;CETChannelWriter { -> }
//## Uses: <unnamed>%3DD4D0E90029;ICOSyncInterface { -> }
//## Uses: <unnamed>%3DD4D0FA03E2;CPIObjectFactory { -> }
//## Uses: <unnamed>%3DD4E5AF0133;IPISensorAnalogInterface { -> }

class CETChannelSensors : public CETChannel  //## Inherits: <unnamed>%3DBC09C60089
{
  //## begin CETChannelSensors%3DBC08530266.initialDeclarations preserve=yes
  //## end CETChannelSensors%3DBC08530266.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelSensors();

    //## Destructor (generated)
      virtual ~CETChannelSensors();

    // Additional Public Declarations
      //## begin CETChannelSensors%3DBC08530266.public preserve=yes
      //## end CETChannelSensors%3DBC08530266.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessMessage%1035733659
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartup%1035733660
      virtual void OnStartup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnShutdown%1035733661
      virtual void OnShutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnAnalogGetValue%1037346556
      virtual void OnAnalogGetValue (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnDigitalSetPolarity%1037346558
      virtual void OnDigitalSetPolarity (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnDigitalIsActive%1037346559
      virtual void OnDigitalIsActive (CETChannelMessageEnvoy* p_pMsg);

    // Additional Protected Declarations
      //## begin CETChannelSensors%3DBC08530266.protected preserve=yes
      //## end CETChannelSensors%3DBC08530266.protected

  private:
    //## Constructors (generated)
      CETChannelSensors(const CETChannelSensors &right);

    //## Assignment Operation (generated)
      const CETChannelSensors & operator=(const CETChannelSensors &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelSensors &right) const;

      bool operator!=(const CETChannelSensors &right) const;

    // Additional Private Declarations
      //## begin CETChannelSensors%3DBC08530266.private preserve=yes
      //## end CETChannelSensors%3DBC08530266.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelSensors%3DBC08530266.implementation preserve=yes
      //## end CETChannelSensors%3DBC08530266.implementation

};

//## begin CETChannelSensors%3DBC08530266.postscript preserve=yes
//## end CETChannelSensors%3DBC08530266.postscript

// Class CETChannelSensors 

//## begin module%3DBC08EB023C.epilog preserve=yes
//## end module%3DBC08EB023C.epilog


#endif
