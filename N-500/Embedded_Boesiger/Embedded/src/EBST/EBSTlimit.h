//## begin module%3E797F3F03BF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E797F3F03BF.cm

//## begin module%3E797F3F03BF.cp preserve=no
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
//## end module%3E797F3F03BF.cp

//## Module: EBSTlimit%3E797F3F03BF; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTlimit.h

#ifndef EBSTlimit_h
#define EBSTlimit_h 1

//## begin module%3E797F3F03BF.additionalIncludes preserve=no
//## end module%3E797F3F03BF.additionalIncludes

//## begin module%3E797F3F03BF.includes preserve=yes
//## end module%3E797F3F03BF.includes

// EBCOrefc
#include "EBCOrefc.h"
// EBPIenum
#include "EBPIenum.h"

class EBCO_DLL_DECL CCOSyncObjectArray;
class EBCO_DLL_DECL CCOSyncObject;
class EBST_DLL_DECL CSTStepperMotorImplementation;
class EBPI_DLL_DECL CPIObjIdentification;
class EBST_DLL_DECL CSTLimitSwitch;
class CSTLimitWorkerThread;

//## begin module%3E797F3F03BF.declarations preserve=no
//## end module%3E797F3F03BF.declarations

//## begin module%3E797F3F03BF.additionalDeclarations preserve=yes
//## end module%3E797F3F03BF.additionalDeclarations


//## begin CSTLimitHandler%3E7974260025.preface preserve=yes
//## end CSTLimitHandler%3E7974260025.preface

//## Class: CSTLimitHandler%3E7974260025
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E7ECFCE001A;EPILimitAction { -> }
//## Uses: <unnamed>%3E7ECFD10375;EPILimitCharacteristics { -> }
//## Uses: <unnamed>%3EA4EFBD0177;CCOSyncObjectArray { -> F}
//## Uses: <unnamed>%3EA553970026;CSTStepperMotorInterface { -> }
//## Uses: <unnamed>%3F3268100360;CSTHardwareConnection { -> }
//## Uses: <unnamed>%3FBB1B4402CD;ST_IDENTIFIERS { -> }
//## Uses: <unnamed>%3FBCF25700E0;XSTExceptionHomingLimitConfig { -> }
//## Uses: <unnamed>%3FBB39CF0332;CSTLogic { -> }

class CSTLimitHandler : public ICORefCounting  //## Inherits: <unnamed>%3E7EFA280385
{
  //## begin CSTLimitHandler%3E7974260025.initialDeclarations preserve=yes
  //## end CSTLimitHandler%3E7974260025.initialDeclarations

  public:
    //## Constructors (generated)
      CSTLimitHandler();

    //## Constructors (specified)
      //## Operation: CSTLimitHandler%1048149994
      CSTLimitHandler (CSTStepperMotorImplementation* p_pContext);

    //## Destructor (generated)
      virtual ~CSTLimitHandler();


    //## Other Operations (specified)
      //## Operation: Add%1048149995
      void Add (CPIObjIdentification* p_pSensorID, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction);

      //## Operation: Config%1048149996
      virtual void Config (CPIObjIdentification* p_pSensor, EPILimitCharacteristics p_eLimitCharacteristics, EPILimitAction p_eLimitAction);

      //## Operation: Activate%1048149997
      void Activate ();

      //## Operation: Deactivate%1048149998
      void Deactivate ();

      //## Operation: GetFootprint%1048149999
      CArray<INT, INT>* GetFootprint ();

      //## Operation: SetFootprint%1048150000
      void SetFootprint (const int p_iPosition);

      //## Operation: OnHit%1048150001
      void OnHit (UINT p_uiLimitID);

      //## Operation: Reset%1053438554
      void Reset ();

      //## Operation: Start%1048150002
      void Start ();

      //## Operation: Stop%1048150003
      void Stop ();

      //## Operation: GetLimitSwitchEvents%1048237054
      CCOSyncObjectArray* GetLimitSwitchEvents (CArray<UINT, UINT>& p_LimitIDs);

      //## Operation: FindLimitSwitch%1048836484
      CSTLimitSwitch* FindLimitSwitch (CPIObjIdentification* p_pLimitID);

      //## Operation: SoftLimitPresent%1049092070
      bool SoftLimitPresent ();

      //## Operation: ResetFootprint%1060170828
      void ResetFootprint ();

      //## Operation: ResetEvents%1069232321
      void ResetEvents ();

      //## Operation: IsAtHome%1066031268
      bool IsAtHome ();

      //## Operation: ResetJitterTime%1091177734
      void ResetJitterTime ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBST (Stepper Motor)::<unnamed>%3E797B640286
      //## Role: CSTLimitHandler::pContext%3E797B660016
      CSTStepperMotorImplementation * GetpContext ();

      //## Association: EBST (Stepper Motor)::<unnamed>%3EA92B5D024F
      //## Role: CSTLimitHandler::pLimitSwitchIDHit%3EA92B5E0201
      CPIObjIdentification * GetpLimitSwitchIDHit ();
      void SetpLimitSwitchIDHit (CPIObjIdentification * value);

      //## Association: EBST (Stepper Motor)::<unnamed>%3EACC6A8020B
      //## Role: CSTLimitHandler::bLimitsEnabled%3EACC6A803B2
      bool GetbLimitsEnabled ();
      void SetbLimitsEnabled (bool value);

      //## Association: EBST (Stepper Motor)::<unnamed>%3FBCE53B0024
      //## Role: CSTLimitHandler::pHomeLimitID%3FBCE53B0277
      CPIObjIdentification * GetpHomeLimitID ();
      void SetpHomeLimitID (CPIObjIdentification * value);

    // Additional Public Declarations
      //## begin CSTLimitHandler%3E7974260025.public preserve=yes
      //## end CSTLimitHandler%3E7974260025.public

  protected:
    // Additional Protected Declarations
      //## begin CSTLimitHandler%3E7974260025.protected preserve=yes
      //## end CSTLimitHandler%3E7974260025.protected

  private:
    //## Constructors (generated)
      CSTLimitHandler(const CSTLimitHandler &right);

    //## Assignment Operation (generated)
      const CSTLimitHandler & operator=(const CSTLimitHandler &right);

    //## Equality Operations (generated)
      bool operator==(const CSTLimitHandler &right) const;

      bool operator!=(const CSTLimitHandler &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E797B640286
      //## begin CSTLimitHandler::pContext%3E797B660016.role preserve=no  public: CSTStepperMotorImplementation {1..1 -> 1..1RFHN}
      CSTStepperMotorImplementation *m_pContext;
      //## end CSTLimitHandler::pContext%3E797B660016.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3E797C4B0219
      //## Role: CSTLimitHandler::Limits%3E797C4C0064
      //## Constraints:
      //	ordered
      //## Qualifier: class%3FE7FE4C03A8; UINT
      //## begin CSTLimitHandler::Limits%3E797C4C0064.role preserve=no  public: CSTLimitSwitch { -> 1RFHON}
      CMap<UINT, UINT&, CSTLimitSwitch *, CSTLimitSwitch *&> m_Limits;
      //## end CSTLimitHandler::Limits%3E797C4C0064.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3E7AD3B503D5
      //## Role: CSTLimitHandler::pLimitWorkerThread%3E7AD3B60221
      //## begin CSTLimitHandler::pLimitWorkerThread%3E7AD3B60221.role preserve=no  public: CSTLimitWorkerThread {1..1 -> 1..1RFHN}
      CSTLimitWorkerThread *m_pLimitWorkerThread;
      //## end CSTLimitHandler::pLimitWorkerThread%3E7AD3B60221.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3EA92B5D024F
      //## begin CSTLimitHandler::pLimitSwitchIDHit%3EA92B5E0201.role preserve=no  public: CPIObjIdentification {1..1 -> 1..1RFHN}
      CPIObjIdentification *m_pLimitSwitchIDHit;
      //## end CSTLimitHandler::pLimitSwitchIDHit%3EA92B5E0201.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3EACC6A8020B
      //## begin CSTLimitHandler::bLimitsEnabled%3EACC6A803B2.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bLimitsEnabled;
      //## end CSTLimitHandler::bLimitsEnabled%3EACC6A803B2.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3FBCE53B0024
      //## begin CSTLimitHandler::pHomeLimitID%3FBCE53B0277.role preserve=no  public: CPIObjIdentification {1..1 -> 1..1RFHN}
      CPIObjIdentification *m_pHomeLimitID;
      //## end CSTLimitHandler::pHomeLimitID%3FBCE53B0277.role

    // Additional Private Declarations
      //## begin CSTLimitHandler%3E7974260025.private preserve=yes
      //## end CSTLimitHandler%3E7974260025.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTLimitHandler%3E7974260025.implementation preserve=yes
      //## end CSTLimitHandler%3E7974260025.implementation

};

//## begin CSTLimitHandler%3E7974260025.postscript preserve=yes
//## end CSTLimitHandler%3E7974260025.postscript

//## begin CSTLimitSwitch%3E7980A4013E.preface preserve=yes
//## end CSTLimitSwitch%3E7980A4013E.preface

//## Class: CSTLimitSwitch%3E7980A4013E
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E8021AE0131;CHIInterface { -> }
//## Uses: <unnamed>%3E8807230327;IHIInterface { -> }
//## Uses: <unnamed>%3E880D400375;EHIOpenEventRegistration { -> }

class EBST_DLL_DECL CSTLimitSwitch 
{
  //## begin CSTLimitSwitch%3E7980A4013E.initialDeclarations preserve=yes
  //## end CSTLimitSwitch%3E7980A4013E.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTLimitSwitch%1048237049
      CSTLimitSwitch (CPIObjIdentification* p_pLimitID, const EPILimitAction p_eLimitAction, const EPILimitCharacteristics p_eLimitCharacteristics);

    //## Destructor (generated)
      virtual ~CSTLimitSwitch();


    //## Other Operations (specified)
      //## Operation: GetEvent%1048237055
      CCOSyncObject* GetEvent ();

      //## Operation: AddFootprint%1059997034
      void AddFootprint (const int p_iPosition);

      //## Operation: ResetFootprints%1059997035
      void ResetFootprints ();

      //## Operation: GetFootprints%1060170829
      CArray<INT,INT>* GetFootprints ();

      //## Operation: ResetEvent%1069232322
      void ResetEvent ();

      //## Operation: ActivateReverseCharacteristics%1128355573
      void ActivateReverseCharacteristics ();

      //## Operation: RestoreOriginalCharacteristics%1128355586
      void RestoreOriginalCharacteristics ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBST (Stepper Motor)::<unnamed>%3E797E120073
      //## Role: CSTLimitSwitch::eLimitAction%3E797E120352
      EPILimitAction GeteLimitAction ();
      void SeteLimitAction (EPILimitAction value);

      //## Association: EBST (Stepper Motor)::<unnamed>%3E797E150342
      //## Role: CSTLimitSwitch::eCurLimitCharacteristics%3E797E16018D
      EPILimitCharacteristics GeteCurLimitCharacteristics ();

      //## Association: EBST (Stepper Motor)::<unnamed>%3E7ED67900F5
      //## Role: CSTLimitSwitch::pLimitID%3E7ED67A0088
      CPIObjIdentification * GetpLimitID ();
      void SetpLimitID (CPIObjIdentification * value);

      //## Association: EBST (Stepper Motor)::<unnamed>%3FBB2AF3033B
      //## Role: CSTLimitSwitch::dbTimeStamp%3FBB2AF40250
      double GetdbTimeStamp ();
      void SetdbTimeStamp (double value);

      //## Association: EBST (Stepper Motor)::<unnamed>%4343CFBD0177
      //## Role: CSTLimitSwitch::eOriginalLimitCharacteristics%4343CFBE0007
      void SeteOriginalLimitCharacteristics (EPILimitCharacteristics value);

    // Additional Public Declarations
      //## begin CSTLimitSwitch%3E7980A4013E.public preserve=yes
      //## end CSTLimitSwitch%3E7980A4013E.public

  protected:
    // Additional Protected Declarations
      //## begin CSTLimitSwitch%3E7980A4013E.protected preserve=yes
      //## end CSTLimitSwitch%3E7980A4013E.protected

  private:
    //## Constructors (generated)
      CSTLimitSwitch();

      CSTLimitSwitch(const CSTLimitSwitch &right);

    //## Assignment Operation (generated)
      const CSTLimitSwitch & operator=(const CSTLimitSwitch &right);

    //## Equality Operations (generated)
      bool operator==(const CSTLimitSwitch &right) const;

      bool operator!=(const CSTLimitSwitch &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3E797E120073
      //## begin CSTLimitSwitch::eLimitAction%3E797E120352.role preserve=no  public: EPILimitAction {1..1 -> 1..1VHN}
      EPILimitAction m_eLimitAction;
      //## end CSTLimitSwitch::eLimitAction%3E797E120352.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3E797E150342
      //## begin CSTLimitSwitch::eCurLimitCharacteristics%3E797E16018D.role preserve=no  public: EPILimitCharacteristics {1..1 -> 1..1VHN}
      EPILimitCharacteristics m_eCurLimitCharacteristics;
      //## end CSTLimitSwitch::eCurLimitCharacteristics%3E797E16018D.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3E7ED67900F5
      //## begin CSTLimitSwitch::pLimitID%3E7ED67A0088.role preserve=no  public: CPIObjIdentification {1..1 -> 1..1RFHN}
      CPIObjIdentification *m_pLimitID;
      //## end CSTLimitSwitch::pLimitID%3E7ED67A0088.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3E84022203A4
      //## Role: CSTLimitSwitch::pOpenEvent%3E8402230308
      //## begin CSTLimitSwitch::pOpenEvent%3E8402230308.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pOpenEvent;
      //## end CSTLimitSwitch::pOpenEvent%3E8402230308.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3F2E45410119
      //## Role: CSTLimitSwitch::pFootprint%3F2E45420010
      //## begin CSTLimitSwitch::pFootprint%3F2E45420010.role preserve=no  public: INT {0..1 -> *VFHN}
      CList<INT, INT> m_pFootprint;
      //## end CSTLimitSwitch::pFootprint%3F2E45420010.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3FBB2AF3033B
      //## begin CSTLimitSwitch::dbTimeStamp%3FBB2AF40250.role preserve=no  public: double {1..1 -> 1..1VFHN}
      double m_dbTimeStamp;
      //## end CSTLimitSwitch::dbTimeStamp%3FBB2AF40250.role

      //## Association: EBST (Stepper Motor)::<unnamed>%4343CFBD0177
      //## begin CSTLimitSwitch::eOriginalLimitCharacteristics%4343CFBE0007.role preserve=no  public: EPILimitCharacteristics {1..1 -> 1..1VFHN}
      EPILimitCharacteristics m_eOriginalLimitCharacteristics;
      //## end CSTLimitSwitch::eOriginalLimitCharacteristics%4343CFBE0007.role

    // Additional Private Declarations
      //## begin CSTLimitSwitch%3E7980A4013E.private preserve=yes
      //## end CSTLimitSwitch%3E7980A4013E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTLimitSwitch%3E7980A4013E.implementation preserve=yes
      //## end CSTLimitSwitch%3E7980A4013E.implementation

};

//## begin CSTLimitSwitch%3E7980A4013E.postscript preserve=yes
//## end CSTLimitSwitch%3E7980A4013E.postscript

// Class CSTLimitHandler 

// Class CSTLimitSwitch 

//## begin module%3E797F3F03BF.epilog preserve=yes
//## end module%3E797F3F03BF.epilog


#endif
