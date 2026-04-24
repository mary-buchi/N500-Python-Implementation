//## begin module%3DBC09000156.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC09000156.cm

//## begin module%3DBC09000156.cp preserve=no
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
//## end module%3DBC09000156.cp

//## Module: EBETchot%3DBC09000156; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchot.h

#ifndef EBETchot_h
#define EBETchot_h 1

//## begin module%3DBC09000156.additionalIncludes preserve=no
//## end module%3DBC09000156.additionalIncludes

//## begin module%3DBC09000156.includes preserve=yes
//## end module%3DBC09000156.includes

// EBETchan
#include "EBETchan.h"
//## begin module%3DBC09000156.declarations preserve=no
//## end module%3DBC09000156.declarations

//## begin module%3DBC09000156.additionalDeclarations preserve=yes
//## end module%3DBC09000156.additionalDeclarations


//## begin CETChannelOutputs%3DBC085F01D7.preface preserve=yes
//## end CETChannelOutputs%3DBC085F01D7.preface

//## Class: CETChannelOutputs%3DBC085F01D7
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD4E86100F4;IPIOutputAnalogInterface { -> }
//## Uses: <unnamed>%3DD4E8870327;IPIOutputDigitalInterface { -> }
//## Uses: <unnamed>%3DD4EA1E01B0;CETChannelMessage { -> }
//## Uses: <unnamed>%3DD4EA24024C;XCOException { -> }
//## Uses: <unnamed>%3DD4EA3100F4;CPIObjectFactory { -> }
//## Uses: <unnamed>%3DD4EA4200B6;CETChannelWriter { -> }

class CETChannelOutputs : public CETChannel  //## Inherits: <unnamed>%3DBC09CD0274
{
  //## begin CETChannelOutputs%3DBC085F01D7.initialDeclarations preserve=yes
  //## end CETChannelOutputs%3DBC085F01D7.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelOutputs();

    //## Destructor (generated)
      virtual ~CETChannelOutputs();

    // Additional Public Declarations
      //## begin CETChannelOutputs%3DBC085F01D7.public preserve=yes
      //## end CETChannelOutputs%3DBC085F01D7.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessMessage%1035733655
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartup%1035733656
      virtual void OnStartup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnShutdown%1035733657
      virtual void OnShutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnAnalogSetValue%1037346562
      virtual void OnAnalogSetValue (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnAnalogGetValue%1037346563
      virtual void OnAnalogGetValue (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnDigitalSet%1037346564
      virtual void OnDigitalSet (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnDigitalClear%1037346565
      virtual void OnDigitalClear (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnDigitalIsActive%1037346568
      virtual void OnDigitalIsActive (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnDigitalSetPolarity%1037346566
      virtual void OnDigitalSetPolarity (CETChannelMessageEnvoy* p_pMsg);

    // Additional Protected Declarations
      //## begin CETChannelOutputs%3DBC085F01D7.protected preserve=yes
      //## end CETChannelOutputs%3DBC085F01D7.protected

  private:
    //## Constructors (generated)
      CETChannelOutputs(const CETChannelOutputs &right);

    //## Assignment Operation (generated)
      const CETChannelOutputs & operator=(const CETChannelOutputs &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelOutputs &right) const;

      bool operator!=(const CETChannelOutputs &right) const;

    // Additional Private Declarations
      //## begin CETChannelOutputs%3DBC085F01D7.private preserve=yes
      //## end CETChannelOutputs%3DBC085F01D7.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelOutputs%3DBC085F01D7.implementation preserve=yes
      //## end CETChannelOutputs%3DBC085F01D7.implementation

};

//## begin CETChannelOutputs%3DBC085F01D7.postscript preserve=yes
//## end CETChannelOutputs%3DBC085F01D7.postscript

// Class CETChannelOutputs 

//## begin module%3DBC09000156.epilog preserve=yes
//## end module%3DBC09000156.epilog


#endif
