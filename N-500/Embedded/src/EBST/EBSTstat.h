//## begin module%3DA6C2490378.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DA6C2490378.cm

//## begin module%3DA6C2490378.cp preserve=no
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
//## end module%3DA6C2490378.cp

//## Module: EBSTstat%3DA6C2490378; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTstat.h

#ifndef EBSTstat_h
#define EBSTstat_h 1

//## begin module%3DA6C2490378.additionalIncludes preserve=no
//## end module%3DA6C2490378.additionalIncludes

//## begin module%3DA6C2490378.includes preserve=yes
//## end module%3DA6C2490378.includes

// EBCOstat
#include "EBCOstat.h"
// EBCOsypr
#include "EBCOsypr.h"
// EBPIenum
#include "EBPIenum.h"

class EBPI_DLL_DECL CPIObjIdentification;
class EBPI_DLL_DECL CPIStepperMotorProfile;
class EBPI_DLL_DECL CPIStepperMotorConfig;
class EBST_DLL_DECL CSTStepperMotorImplementation;
class EBST_DLL_DECL CSTLimitSwitch;

//## begin module%3DA6C2490378.declarations preserve=no
//## end module%3DA6C2490378.declarations

//## begin module%3DA6C2490378.additionalDeclarations preserve=yes
//## end module%3DA6C2490378.additionalDeclarations


//## begin CSTState%3DA6C29E0136.preface preserve=yes
//## end CSTState%3DA6C29E0136.preface

//## Class: CSTState%3DA6C29E0136
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAE59F500F6;ST_IDENTIFIERS { -> }
//## Uses: <unnamed>%3DAE59F70125;XCOException { -> }
//## Uses: <unnamed>%3DE377760234;CCOSyncObjectInt { -> }
//## Uses: <unnamed>%3DE38FE902A1;EPILimitCharacteristics { -> }
//## Uses: <unnamed>%3DE38FED0262;EPILimitAction { -> }
//## Uses: <unnamed>%3DE38FF00243;CPIObjIdentification { -> F}
//## Uses: <unnamed>%3DE47DB10103;CCOIntegerArray { -> }
//## Uses: <unnamed>%3E719D500186;CPIPowerControlProfile { -> }
//## Uses: <unnamed>%3E719D54002E;CCOSyncObjectInt { -> }
//## Uses: <unnamed>%3E719E010195;EPILimitAction { -> }
//## Uses: <unnamed>%3E719E0401F3;EPILimitCharacteristics { -> }
//## Uses: <unnamed>%3E719E0A0232;CPIObjIdentification { -> }
//## Uses: <unnamed>%3E719E0E03D8;CCOIntegerArray { -> }
//## Uses: <unnamed>%3E7591C201D9;CPIStepperMotorConfig { -> F}
//## Uses: <unnamed>%3E7592DE00FE;CPIStepperMotorProfile { -> F}
//## Uses: <unnamed>%3E78492A0394;CSTStepperMotorImplementation { -> F}
//## Uses: <unnamed>%3E816AB40358;CSTLimitSwitch { -> F}
//## Uses: <unnamed>%3ECB45DE0399;XSTExceptionError { -> }

class CSTState : public CCOState  //## Inherits: <unnamed>%3DA6C2A400E7
{
  //## begin CSTState%3DA6C29E0136.initialDeclarations preserve=yes
  //## end CSTState%3DA6C29E0136.initialDeclarations

  public:
    //## Constructors (generated)
      CSTState();

    //## Destructor (generated)
      virtual ~CSTState();


    //## Other Operations (specified)
      //## Operation: GetPosition%1034575087
      virtual void GetPosition (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj);

      //## Operation: MoveAbsolute%1038217297
      virtual void MoveAbsolute (ICOStateMachineContext* p_pContext, INT p_iTargetPosition, INT p_iSearchDistance);

      //## Operation: MoveRelative%1038217298
      virtual void MoveRelative (ICOStateMachineContext* p_pContext, INT p_iTotalDistance, INT p_iSearchDistance);

      //## Operation: MoveManual%1038217299
      virtual void MoveManual (ICOStateMachineContext* p_pContext, INT p_iEndPosition, INT p_uiSpeed);

      //## Operation: Stop%1038217300
      //	returns true, if the stop sync object maybe signalled
      virtual bool Stop (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pClientSyncObj);

      //## Operation: StopImmediately%1038217301
      virtual void StopImmediately (ICOStateMachineContext* p_pContext);

      //## Operation: SetProfile%1038217302
      virtual void SetProfile (ICOStateMachineContext* p_pContext, CPIStepperMotorProfile* p_pProfile);

      //## Operation: LimitAdd%1038217304
      virtual void LimitAdd (ICOStateMachineContext* p_pContext, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction, CPIObjIdentification* p_pSensor);

      //## Operation: LimitConfig%1038217305
      virtual void LimitConfig (ICOStateMachineContext* p_pContext, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction, CPIObjIdentification* p_pSensor);

      //## Operation: LimitActivate%1038217306
      virtual void LimitActivate (ICOStateMachineContext* p_pContext);

      //## Operation: LimitDeactivate%1038217307
      virtual void LimitDeactivate (ICOStateMachineContext* p_pContext);

      //## Operation: Home%1038217308
      virtual void Home (ICOStateMachineContext* p_pContext, const EPIMotorPolarity p_eFastFindingDirection, const bool p_bSearchLimitFromOpposite, CPIObjIdentification* p_pHomeLimitID, CCOSyncObjectInt* p_pClientSyncObj);

      //## Operation: HomeSetPosition%1038217309
      virtual void HomeSetPosition (ICOStateMachineContext* p_pContext, INT p_iPosition);

      //## Operation: LimitGetFootPrint%1038217310
      virtual void LimitGetFootPrint (ICOStateMachineContext* p_pContext, CCOSyncObjectIntArray* p_pClientSyncObj);

      //## Operation: SetConfig%1047647377
      virtual void SetConfig (ICOStateMachineContext* p_pContext, CPIStepperMotorConfig* p_pConfig);

      //## Operation: SetSpeed%1047904790
      virtual void SetSpeed (ICOStateMachineContext* p_pContext, CCOSyncObjectInt* p_pClientSyncObj, UINT p_uiSpeed);

      //## Operation: GetpContext%1048057976
      virtual CSTStepperMotorImplementation* GetpContext (ICOStateMachineContext* p_pContext);

      //## Operation: OnLimitHit%1048581162
      virtual void OnLimitHit (ICOStateMachineContext* p_pContext, CPIObjIdentification* p_pLimitID);

    // Additional Public Declarations
      //## begin CSTState%3DA6C29E0136.public preserve=yes
      //## end CSTState%3DA6C29E0136.public

  protected:
    // Additional Protected Declarations
      //## begin CSTState%3DA6C29E0136.protected preserve=yes
      //## end CSTState%3DA6C29E0136.protected

  private:
    //## Constructors (generated)
      CSTState(const CSTState &right);

    //## Assignment Operation (generated)
      const CSTState & operator=(const CSTState &right);

    //## Equality Operations (generated)
      bool operator==(const CSTState &right) const;

      bool operator!=(const CSTState &right) const;

    // Additional Private Declarations
      //## begin CSTState%3DA6C29E0136.private preserve=yes
      //## end CSTState%3DA6C29E0136.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTState%3DA6C29E0136.implementation preserve=yes
      //## end CSTState%3DA6C29E0136.implementation

};

//## begin CSTState%3DA6C29E0136.postscript preserve=yes
//## end CSTState%3DA6C29E0136.postscript

// Class CSTState 

//## begin module%3DA6C2490378.epilog preserve=yes
//## end module%3DA6C2490378.epilog


#endif
