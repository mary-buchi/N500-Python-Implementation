//## begin module%3DD103C1013A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD103C1013A.cm

//## begin module%3DD103C1013A.cp preserve=no
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
//## end module%3DD103C1013A.cp

//## Module: EBWCstat%3DD103C1013A; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCstat.h

#ifndef EBWCstat_h
#define EBWCstat_h 1

//## begin module%3DD103C1013A.additionalIncludes preserve=no
//## end module%3DD103C1013A.additionalIncludes

//## begin module%3DD103C1013A.includes preserve=yes
//## end module%3DD103C1013A.includes

// EBCOsypr
#include "EBCOsypr.h"
// EBCOstat
#include "EBCOstat.h"

class EBCO_DLL_DECL CCOSyncObject;
class EBPI_DLL_DECL CPIWedgeControlConfig;
class EBPI_DLL_DECL CPIWedgeControlProfile;
class CWCWedgeControlImplementation;
class EBHI_DLL_DECL IHIInterface;

//## begin module%3DD103C1013A.declarations preserve=no
//## end module%3DD103C1013A.declarations

//## begin module%3DD103C1013A.additionalDeclarations preserve=yes
//## end module%3DD103C1013A.additionalDeclarations


//## begin CWCState%3DD10434032E.preface preserve=yes
//## end CWCState%3DD10434032E.preface

//## Class: CWCState%3DD10434032E
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD20D4B0060;WC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3DD3BA0403E5;XCOException { -> }
//## Uses: <unnamed>%3DE332060300;CPIWedgeControlConfig { -> F}
//## Uses: <unnamed>%3DE33216035E;CPIWedgeControlProfile { -> F}
//## Uses: <unnamed>%3ECA194202BF;CWCWedgeControlImplementation { -> F}
//## Uses: <unnamed>%4007E4C203B9;CCOSyncObject { -> F}
//## Uses: <unnamed>%400BA89F0196;CCOSyncObjectInt { -> }

class CWCState : public CCOState  //## Inherits: <unnamed>%3DD1043D02FF
{
  //## begin CWCState%3DD10434032E.initialDeclarations preserve=yes
  //## end CWCState%3DD10434032E.initialDeclarations

  public:
    //## Constructors (generated)
      CWCState();

    //## Destructor (generated)
      virtual ~CWCState();


    //## Other Operations (specified)
      //## Operation: GetpContext%1053429541
      virtual CWCWedgeControlImplementation* GetpContext (ICOStateMachineContext* p_pContext);

      //## Operation: Start%1037279662
      virtual void Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pSyncStartObj, CCOSyncObjectInt* p_pSyncExcObj);

      //## Operation: SetProfile%1037951605
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPIWedgeControlProfile* p_pProfile);

      //## Operation: Stop%1037951606
      virtual void Stop (ICOStateMachineContext* p_pContext);

      //## Operation: SetConfiguration%1037951607
      virtual void SetConfiguration (ICOStateMachineContext* p_pContext, CPIWedgeControlConfig* p_pConfig);

      //## Operation: Park%1038217317
      virtual void Park (ICOStateMachineContext* p_pContext);

      //## Operation: Referencing%1038217318
      virtual void Referencing (ICOStateMachineContext* p_pContext);

      //## Operation: Initialize%1038217321
      virtual void Initialize (ICOStateMachineContext* p_pContext);

      //## Operation: GetDacZeroCurrent%1149148978
      virtual void GetDacZeroCurrent (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj);

    // Additional Public Declarations
      //## begin CWCState%3DD10434032E.public preserve=yes
      //## end CWCState%3DD10434032E.public

  protected:
    // Additional Protected Declarations
      //## begin CWCState%3DD10434032E.protected preserve=yes
      //## end CWCState%3DD10434032E.protected

  private:
    //## Constructors (generated)
      CWCState(const CWCState &right);

    //## Assignment Operation (generated)
      const CWCState & operator=(const CWCState &right);

    //## Equality Operations (generated)
      bool operator==(const CWCState &right) const;

      bool operator!=(const CWCState &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3E2E94DF005B
      //## Role: CWCState::pHWIntf%3E2E94DF031B
      //## begin CWCState::pHWIntf%3E2E94DF031B.role preserve=no  public: IHIInterface {1..1 -> 1..1RFHN}
      IHIInterface *m_pHWIntf;
      //## end CWCState::pHWIntf%3E2E94DF031B.role

    // Additional Private Declarations
      //## begin CWCState%3DD10434032E.private preserve=yes
      //## end CWCState%3DD10434032E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCState%3DD10434032E.implementation preserve=yes
      //## end CWCState%3DD10434032E.implementation

};

//## begin CWCState%3DD10434032E.postscript preserve=yes
//## end CWCState%3DD10434032E.postscript

// Class CWCState 

//## begin module%3DD103C1013A.epilog preserve=yes
//## end module%3DD103C1013A.epilog


#endif
