//## begin module%3EED769F0378.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F0378.cm

//## begin module%3EED769F0378.cp preserve=no
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
//## end module%3EED769F0378.cp

//## Module: EBPCstat%3EED769F0378; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCstat.h

#ifndef EBPCstat_h
#define EBPCstat_h 1

//## begin module%3EED769F0378.additionalIncludes preserve=no
//## end module%3EED769F0378.additionalIncludes

//## begin module%3EED769F0378.includes preserve=yes
//## end module%3EED769F0378.includes

// EBCOstat
#include "EBCOstat.h"
// EBCOsypr
#include "EBCOsypr.h"

class EBPI_DLL_DECL CPIPowerControlProfile;
class EBPI_DLL_DECL CPIPowerControlConfig;
class CPCPowerControlImplementation;

//## begin module%3EED769F0378.declarations preserve=no
//## end module%3EED769F0378.declarations

//## begin module%3EED769F0378.additionalDeclarations preserve=yes
//## end module%3EED769F0378.additionalDeclarations


//## begin CPCState%3EED76CC0377.preface preserve=yes
//## end CPCState%3EED76CC0377.preface

//## Class: CPCState%3EED76CC0377
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EED76CC037F;CPIPowerControlConfig { -> F}
//## Uses: <unnamed>%3EED76CC0382;XCOException { -> }
//## Uses: <unnamed>%3EED76CC0385;PC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3EED76CC0388;CCOSyncObjectInt { -> }
//## Uses: <unnamed>%3EED76CC038B;CPCPowerControlImplementation { -> F}
//## Uses: <unnamed>%3EEDC71F036C;CPIPowerControlProfile { -> F}

class CPCState : public CCOState  //## Inherits: <unnamed>%3EED76CC0379
{
  //## begin CPCState%3EED76CC0377.initialDeclarations preserve=yes
  //## end CPCState%3EED76CC0377.initialDeclarations

  public:
    //## Constructors (generated)
      CPCState();

    //## Destructor (generated)
      virtual ~CPCState();


    //## Other Operations (specified)
      //## Operation: SetProfile%1038899345
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPIPowerControlProfile* p_pProfile);

      //## Operation: SetConfiguration%1038899346
      virtual void SetConfiguration (ICOStateMachineContext* p_pContext, CPIPowerControlConfig* p_pConfig);

      //## Operation: Start%1038899347
      virtual void Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObject);

      //## Operation: Stop%1038899348
      virtual void Stop (ICOStateMachineContext* p_pContext);

      //## Operation: GetpImplementation%1045561405
      virtual CPCPowerControlImplementation* GetpImplementation (ICOStateMachineContext* p_pContext);

      //## Operation: PowerOff%1076339199
      //	DESCRIPTION
      //	Power off for lamp change.
      //
      //	RETURNS
      //	async void
      virtual void PowerOff (ICOStateMachineContext* p_pContext);

      //## Operation: PowerOn%1076339200
      //	DESCRIPTION
      //	Starts the power after lamp change.
      //
      //	RETURNS
      //	async void
      virtual void PowerOn (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPCState%3EED76CC0377.public preserve=yes
      //## end CPCState%3EED76CC0377.public

  protected:
    // Additional Protected Declarations
      //## begin CPCState%3EED76CC0377.protected preserve=yes
      //## end CPCState%3EED76CC0377.protected

  private:
    //## Constructors (generated)
      CPCState(const CPCState &right);

    //## Assignment Operation (generated)
      const CPCState & operator=(const CPCState &right);

    //## Equality Operations (generated)
      bool operator==(const CPCState &right) const;

      bool operator!=(const CPCState &right) const;

    // Additional Private Declarations
      //## begin CPCState%3EED76CC0377.private preserve=yes
      //## end CPCState%3EED76CC0377.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCState%3EED76CC0377.implementation preserve=yes
      //## end CPCState%3EED76CC0377.implementation

};

//## begin CPCState%3EED76CC0377.postscript preserve=yes
//## end CPCState%3EED76CC0377.postscript

// Class CPCState 

//## begin module%3EED769F0378.epilog preserve=yes
//## end module%3EED769F0378.epilog


#endif
