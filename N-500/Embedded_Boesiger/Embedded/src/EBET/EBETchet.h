//## begin module%3DBC095501BD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DBC095501BD.cm

//## begin module%3DBC095501BD.cp preserve=no
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
//## end module%3DBC095501BD.cp

//## Module: EBETchet%3DBC095501BD; Package specification
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Source file: R:\Embedded\Src\EBET\EBETchet.h

#ifndef EBETchet_h
#define EBETchet_h 1

//## begin module%3DBC095501BD.additionalIncludes preserve=no
//## end module%3DBC095501BD.additionalIncludes

//## begin module%3DBC095501BD.includes preserve=yes
//## end module%3DBC095501BD.includes

// EBETchan
#include "EBETchan.h"
//## begin module%3DBC095501BD.declarations preserve=no
//## end module%3DBC095501BD.declarations

//## begin module%3DBC095501BD.additionalDeclarations preserve=yes
//## end module%3DBC095501BD.additionalDeclarations


//## begin CETChannelEvents%3DBC08AE0217.preface preserve=yes
//## end CETChannelEvents%3DBC08AE0217.preface

//## Class: CETChannelEvents%3DBC08AE0217
//## Category: EBET (Ethernet Transport)%3D9D858B01A0
//## Subsystem: EBET (Ethernet Transport)%3D9D854401AF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD90B9500C6;IPIEventSourceInterface { -> }
//## Uses: <unnamed>%3DD90D6701E0;CETChannelMessage { -> }
//## Uses: <unnamed>%3DD90D69021E;XCOException { -> }
//## Uses: <unnamed>%3DD90D6B024D;CPIObjectFactory { -> }
//## Uses: <unnamed>%3DD90D7D0088;CETChannelWriter { -> }

class CETChannelEvents : public CETChannel  //## Inherits: <unnamed>%3DBC09F20190
{
  //## begin CETChannelEvents%3DBC08AE0217.initialDeclarations preserve=yes
  //## end CETChannelEvents%3DBC08AE0217.initialDeclarations

  public:
    //## Constructors (generated)
      CETChannelEvents();

    //## Destructor (generated)
      virtual ~CETChannelEvents();

    // Additional Public Declarations
      //## begin CETChannelEvents%3DBC08AE0217.public preserve=yes
      //## end CETChannelEvents%3DBC08AE0217.public

  protected:

    //## Other Operations (specified)
      //## Operation: ProcessMessage%1035733639
      virtual void ProcessMessage (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnStartup%1035733640
      virtual void OnStartup (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnShutdown%1035733641
      virtual void OnShutdown (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnRegisterForEvent%1037632260
      virtual void OnRegisterForEvent (CETChannelMessageEnvoy* p_pMsg);

      //## Operation: OnUnregisterFromEvent%1037632261
      virtual void OnUnregisterFromEvent (CETChannelMessageEnvoy* p_pMsg);

    // Additional Protected Declarations
      //## begin CETChannelEvents%3DBC08AE0217.protected preserve=yes
      //## end CETChannelEvents%3DBC08AE0217.protected

  private:
    //## Constructors (generated)
      CETChannelEvents(const CETChannelEvents &right);

    //## Assignment Operation (generated)
      const CETChannelEvents & operator=(const CETChannelEvents &right);

    //## Equality Operations (generated)
      bool operator==(const CETChannelEvents &right) const;

      bool operator!=(const CETChannelEvents &right) const;

    // Additional Private Declarations
      //## begin CETChannelEvents%3DBC08AE0217.private preserve=yes
      //## end CETChannelEvents%3DBC08AE0217.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CETChannelEvents%3DBC08AE0217.implementation preserve=yes
      //## end CETChannelEvents%3DBC08AE0217.implementation

};

//## begin CETChannelEvents%3DBC08AE0217.postscript preserve=yes
//## end CETChannelEvents%3DBC08AE0217.postscript

// Class CETChannelEvents 

//## begin module%3DBC095501BD.epilog preserve=yes
//## end module%3DBC095501BD.epilog


#endif
