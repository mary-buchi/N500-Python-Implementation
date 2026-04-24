//## begin module%3DBC09170286.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC09170286.cm

//## begin module%3DBC09170286.cp preserve=no
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
//## end module%3DBC09170286.cp

//## Module: EBETchct%3DBC09170286; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchct.h

#ifndef EBETchct_h
#define EBETchct_h 1

//## begin module%3DBC09170286.additionalIncludes preserve=no
//## end module%3DBC09170286.additionalIncludes

//## begin module%3DBC09170286.includes preserve=yes
//## end module%3DBC09170286.includes

// EBETchan
#include "EBETchan.h"
//## begin module%3DBC09170286.declarations preserve=no
//## end module%3DBC09170286.declarations

//## begin module%3DBC09170286.additionalDeclarations preserve=yes
//## end module%3DBC09170286.additionalDeclarations


//## begin CETChannelControlTemperature%3DBC087400C9.preface preserve=yes
//## end CETChannelControlTemperature%3DBC087400C9.preface

//## Class: CETChannelControlTemperature%3DBC087400C9
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD3568403AC;IPITemperatureControlInterface { -> }
//## Uses: <unnamed>%3DD39287008F;CETChannelMessage { -> }
//## Uses: <unnamed>%3DD39A3B0293;XCOException { -> }
//## Uses: <unnamed>%3DD39A5201F7;CETChannelWriter { -> }
//## Uses: <unnamed>%3DD39A5F0320;CPIObjectFactory { -> }

class CETChannelControlTemperature : public CETChannel  //## Inherits: <unnamed>%3DBC09D7017E
{
  //## begin CETChannelControlTemperature%3DBC087400C9.initialDeclarations preserve=yes
  //## end CETChannelControlTemperature%3DBC087400C9.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelControlTemperature();

    //## Destructor (generated)
      virtual ~CETChannelControlTemperature();


    //## Other Operations (specified)
      //## Operation: UnwrapTelegram%1037257503
      virtual CETChannelMessage* UnwrapTelegram (BYTE* p_pbyStream, UINT p_uiStreamLength);

    // Additional Public Declarations
      //## begin CETChannelControlTemperature%3DBC087400C9.public preserve=yes
      //## end CETChannelControlTemperature%3DBC087400C9.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessMessage%1035733651
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartup%1035733652
      virtual void OnStartup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnShutdown%1035733653
      virtual void OnShutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetProfile%1037257504
      virtual void OnSetProfile (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnSetConfiguration%1037257505
      virtual void OnSetConfiguration (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStart%1037257506
      virtual void OnStart (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStop%1037257507
      virtual void OnStop (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnGetTemperature%1037257508
      virtual void OnGetTemperature (CETChannelMessageEnvoy* p_pMsg);

    // Additional Protected Declarations
      //## begin CETChannelControlTemperature%3DBC087400C9.protected preserve=yes
      //## end CETChannelControlTemperature%3DBC087400C9.protected

  private:
    //## Constructors (generated)
      CETChannelControlTemperature(const CETChannelControlTemperature &right);

    //## Assignment Operation (generated)
      const CETChannelControlTemperature & operator=(const CETChannelControlTemperature &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelControlTemperature &right) const;

      bool operator!=(const CETChannelControlTemperature &right) const;

    // Additional Private Declarations
      //## begin CETChannelControlTemperature%3DBC087400C9.private preserve=yes
      //## end CETChannelControlTemperature%3DBC087400C9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelControlTemperature%3DBC087400C9.implementation preserve=yes
      //## end CETChannelControlTemperature%3DBC087400C9.implementation

};

//## begin CETChannelControlTemperature%3DBC087400C9.postscript preserve=yes
//## end CETChannelControlTemperature%3DBC087400C9.postscript

// Class CETChannelControlTemperature 

//## begin module%3DBC09170286.epilog preserve=yes
//## end module%3DBC09170286.epilog


#endif
