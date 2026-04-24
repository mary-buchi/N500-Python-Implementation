//## begin module%3DE5EE21011E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EE21011E.cm

//## begin module%3DE5EE21011E.cp preserve=no
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
//## end module%3DE5EE21011E.cp

//## Module: EBTCstat%3DE5EE21011E; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCstat.h

#ifndef EBTCstat_h
#define EBTCstat_h 1

//## begin module%3DE5EE21011E.additionalIncludes preserve=no
//## end module%3DE5EE21011E.additionalIncludes

//## begin module%3DE5EE21011E.includes preserve=yes
//## end module%3DE5EE21011E.includes

// EBCOsypr
#include "EBCOsypr.h"
// EBCOstat
#include "EBCOstat.h"

class EBPI_DLL_DECL CPITemperatureControlConfig;
class EBPI_DLL_DECL CPITemperatureControlProfile;
class CTCTemperatureControlImplementation;

//## begin module%3DE5EE21011E.declarations preserve=no
//## end module%3DE5EE21011E.declarations

//## begin module%3DE5EE21011E.additionalDeclarations preserve=yes
//## end module%3DE5EE21011E.additionalDeclarations


//## begin CTCState%3DEC7197017A.preface preserve=yes
//## end CTCState%3DEC7197017A.preface

//## Class: CTCState%3DEC7197017A
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DEC724D037D;CPITemperatureControlProfile { -> F}
//## Uses: <unnamed>%3DEC72500022;CPITemperatureControlConfig { -> F}
//## Uses: <unnamed>%3DEC727A016A;XCOException { -> }
//## Uses: <unnamed>%3DEC727C034E;TC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3DF49D460153;CCOSyncObjectInt { -> }
//## Uses: <unnamed>%3E53B5F10044;CTCTemperatureControlImplementation { -> F}
//## Uses: <unnamed>%3F15625C02F5;CTCLogic { -> }

class CTCState : public CCOState  //## Inherits: <unnamed>%3DEC719F036E
{
  //## begin CTCState%3DEC7197017A.initialDeclarations preserve=yes
  //## end CTCState%3DEC7197017A.initialDeclarations

  public:
    //## Constructors (generated)
      CTCState();

    //## Destructor (generated)
      virtual ~CTCState();


    //## Other Operations (specified)
      //## Operation: SetProfile%1038899345
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPITemperatureControlProfile* p_pProfile);

      //## Operation: SetConfiguration%1038899346
      virtual void SetConfiguration (ICOStateMachineContext* p_pContext, CPITemperatureControlConfig* p_pConfig);

      //## Operation: Start%1038899347
      virtual void Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pIncidentSyncObj);

      //## Operation: Stop%1038899348
      virtual void Stop (ICOStateMachineContext* p_pContext);

      //## Operation: GetTemperature%1038899349
      virtual void GetTemperature (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj);

      //## Operation: GetpContext%1045561405
      virtual CTCTemperatureControlImplementation* GetpContext (ICOStateMachineContext* p_pContext);

      //## Operation: CellUndocked%1216975785
      virtual void CellUndocked (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CTCState%3DEC7197017A.public preserve=yes
      //## end CTCState%3DEC7197017A.public

  protected:
    // Additional Protected Declarations
      //## begin CTCState%3DEC7197017A.protected preserve=yes
      //## end CTCState%3DEC7197017A.protected

  private:
    //## Constructors (generated)
      CTCState(const CTCState &right);

    //## Assignment Operation (generated)
      const CTCState & operator=(const CTCState &right);

    //## Equality Operations (generated)
      bool operator==(const CTCState &right) const;

      bool operator!=(const CTCState &right) const;

    // Additional Private Declarations
      //## begin CTCState%3DEC7197017A.private preserve=yes
      //## end CTCState%3DEC7197017A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCState%3DEC7197017A.implementation preserve=yes
      //## end CTCState%3DEC7197017A.implementation

};

//## begin CTCState%3DEC7197017A.postscript preserve=yes
//## end CTCState%3DEC7197017A.postscript

// Class CTCState 

//## begin module%3DE5EE21011E.epilog preserve=yes
//## end module%3DE5EE21011E.epilog


#endif
