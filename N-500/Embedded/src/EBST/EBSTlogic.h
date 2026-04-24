//## begin module%3E75E2660360.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E75E2660360.cm

//## begin module%3E75E2660360.cp preserve=no
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
//## end module%3E75E2660360.cp

//## Module: EBSTlogic%3E75E2660360; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTlogic.h

#ifndef EBSTlogic_h
#define EBSTlogic_h 1

//## begin module%3E75E2660360.additionalIncludes preserve=no
//## end module%3E75E2660360.additionalIncludes

//## begin module%3E75E2660360.includes preserve=yes
//## end module%3E75E2660360.includes

// EBPIenum
#include "EBPIenum.h"

class EBST_DLL_DECL CSTStepperMotorImplementation;

//## begin module%3E75E2660360.declarations preserve=no
//## end module%3E75E2660360.declarations

//## begin module%3E75E2660360.additionalDeclarations preserve=yes
//## end module%3E75E2660360.additionalDeclarations


//## begin CSTPositionMachine%3E8A978E032C.preface preserve=yes
//## end CSTPositionMachine%3E8A978E032C.preface

//## Class: CSTPositionMachine%3E8A978E032C
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBST_DLL_DECL CSTPositionMachine 
{
  //## begin CSTPositionMachine%3E8A978E032C.initialDeclarations preserve=yes
  //## end CSTPositionMachine%3E8A978E032C.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTPositionMachine%1070350935
      CSTPositionMachine (CSTStepperMotorImplementation* p_pContext);

    //## Destructor (generated)
      virtual ~CSTPositionMachine();


    //## Other Operations (specified)
      //## Operation: MoveAbsolute%1049266860
      void MoveAbsolute (const INT p_iPosition);

      //## Operation: MoveRelative%1049266861
      void MoveRelative (const INT p_iSteps);

      //## Operation: TrackPosition%1069405834
      void TrackPosition ();

      //## Operation: Reset%1070350934
      void Reset ();

      //## Operation: Distance%1071668966
      void Distance ();

      //## Operation: Polarity%1071668967
      void Polarity ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: iStartPos%3E8A9E4E036E
      INT GetiStartPos ();
      void SetiStartPos (INT value);

      //## Attribute: iEndPos%3E8A9E7502C3
      INT GetiEndPos ();
      void SetiEndPos (INT value);

      //## Attribute: ePolarity%3F54403900FA
      EPIMotorPolarity GetePolarity ();
      void SetePolarity (EPIMotorPolarity value);

      //## Attribute: uiDistance%3F5741B50186
      UINT GetuiDistance ();
      void SetuiDistance (UINT value);

      //## Attribute: uiSearchDistance%3F58762A0290
      UINT GetuiSearchDistance ();
      void SetuiSearchDistance (UINT value);

      //## Attribute: eFastFindingDirection%3FE0603E0244
      EPIMotorPolarity GeteFastFindingDirection ();
      void SeteFastFindingDirection (EPIMotorPolarity value);

      //## Attribute: bSearchLimitFromOpposite%471CEEC601E9
      bool GetbSearchLimitFromOpposite ();
      void SetbSearchLimitFromOpposite (bool value);

    // Additional Public Declarations
      //## begin CSTPositionMachine%3E8A978E032C.public preserve=yes
      //## end CSTPositionMachine%3E8A978E032C.public

  protected:
    // Additional Protected Declarations
      //## begin CSTPositionMachine%3E8A978E032C.protected preserve=yes
      //## end CSTPositionMachine%3E8A978E032C.protected

  private:
    //## Constructors (generated)
      CSTPositionMachine();

      CSTPositionMachine(const CSTPositionMachine &right);

    //## Assignment Operation (generated)
      const CSTPositionMachine & operator=(const CSTPositionMachine &right);

    //## Equality Operations (generated)
      bool operator==(const CSTPositionMachine &right) const;

      bool operator!=(const CSTPositionMachine &right) const;

    // Data Members for Class Attributes

      //## begin CSTPositionMachine::iStartPos%3E8A9E4E036E.attr preserve=no  public: INT {U} 0
      INT m_iStartPos;
      //## end CSTPositionMachine::iStartPos%3E8A9E4E036E.attr

      //## begin CSTPositionMachine::iEndPos%3E8A9E7502C3.attr preserve=no  public: INT {U} 0
      INT m_iEndPos;
      //## end CSTPositionMachine::iEndPos%3E8A9E7502C3.attr

      //## begin CSTPositionMachine::ePolarity%3F54403900FA.attr preserve=no  public: EPIMotorPolarity {U} ePIMotorPolarityNormal
      EPIMotorPolarity m_ePolarity;
      //## end CSTPositionMachine::ePolarity%3F54403900FA.attr

      //## begin CSTPositionMachine::uiDistance%3F5741B50186.attr preserve=no  public: UINT {U} 0
      UINT m_uiDistance;
      //## end CSTPositionMachine::uiDistance%3F5741B50186.attr

      //## begin CSTPositionMachine::uiSearchDistance%3F58762A0290.attr preserve=no  public: UINT {U} 0
      UINT m_uiSearchDistance;
      //## end CSTPositionMachine::uiSearchDistance%3F58762A0290.attr

      //## begin CSTPositionMachine::eFastFindingDirection%3FE0603E0244.attr preserve=no  public: EPIMotorPolarity {U} ePIMotorPolarityNormal
      EPIMotorPolarity m_eFastFindingDirection;
      //## end CSTPositionMachine::eFastFindingDirection%3FE0603E0244.attr

      //## begin CSTPositionMachine::bSearchLimitFromOpposite%471CEEC601E9.attr preserve=no  public: bool {U} false
      bool m_bSearchLimitFromOpposite;
      //## end CSTPositionMachine::bSearchLimitFromOpposite%471CEEC601E9.attr

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3FCC534C017E
      //## Role: CSTPositionMachine::pContext%3FCC534E00E2
      //## begin CSTPositionMachine::pContext%3FCC534E00E2.role preserve=no  public: CSTStepperMotorImplementation {1..1 -> 1..1RFHN}
      CSTStepperMotorImplementation *m_pContext;
      //## end CSTPositionMachine::pContext%3FCC534E00E2.role

    // Additional Private Declarations
      //## begin CSTPositionMachine%3E8A978E032C.private preserve=yes
      //## end CSTPositionMachine%3E8A978E032C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTPositionMachine%3E8A978E032C.implementation preserve=yes
      //## end CSTPositionMachine%3E8A978E032C.implementation

};

//## begin CSTPositionMachine%3E8A978E032C.postscript preserve=yes
//## end CSTPositionMachine%3E8A978E032C.postscript

//## begin ESTIterationType%3F8173FD004D.preface preserve=yes
//## end ESTIterationType%3F8173FD004D.preface

//## Class: ESTIterationType%3F8173FD004D
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum { eIT1, eIT3, eIT5 } ESTIterationType;

//## begin ESTIterationType%3F8173FD004D.postscript preserve=yes
//## end ESTIterationType%3F8173FD004D.postscript

//## begin CSTLogic%3F4F6A1B03A9.preface preserve=yes
//## end CSTLogic%3F4F6A1B03A9.preface

//## Class: CSTLogic%3F4F6A1B03A9
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F532EFB033C;CSTHardwareConnection { -> }
//## Uses: <unnamed>%3F57359001E4;EPIMotorPolarity { -> }
//## Uses: <unnamed>%3F66AFAA006C;CPIStepperMotorProfile { -> }
//## Uses: <unnamed>%3F66AFAC0212;CPIStepperMotorConfig { -> }
//## Uses: <unnamed>%3F718DC00223;ST_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F82866B0295;XSTExceptionErrorStepsDeviation { -> }
//## Uses: <unnamed>%3FBE2D9A0299;IHIInterface { -> }
//## Uses: <unnamed>%3F81744303A8;ESTIterationType { -> }
//## Uses: <unnamed>%3F8273AE01BB;ESTIterationType { -> }

class CSTLogic 
{
  //## begin CSTLogic%3F4F6A1B03A9.initialDeclarations preserve=yes
  //## end CSTLogic%3F4F6A1B03A9.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTLogic%1062145997
      CSTLogic (CSTStepperMotorImplementation* p_pContext);

    //## Destructor (generated)
      virtual ~CSTLogic();


    //## Other Operations (specified)
      //## Operation: AjustActualSpeed%1062398083
      void AjustActualSpeed (UINT p_uiSpeedRate = 0);

      //## Operation: ElapsedTime%1063892106
      void ElapsedTime (const CString& p_sMsg);

      //## Operation: Ramp%1065074933
      void Ramp ();

      //## Operation: Accelerate%1065074934
      //	computes the next velocity value
      void Accelerate (double &p_dDeltaT, double &p_dSpeed, const double &p_da, const double &p_dvo);

      //## Operation: GetDeltaTime%1065125307
      //	returns the elapsed time relative to the local time base
      //	member
      double GetDeltaTime ();

      //## Operation: SetTimeBaseToNow%1065125308
      void SetTimeBaseToNow ();

      //## Operation: AddMissedIterations%1065164418
      void AddMissedIterations (DWORD p_dwMissedIterations);

      //## Operation: NextIterationStep%1065164419
      //	returns true, if the acceleration has to be continued
      bool NextIterationStep ();

      //## Operation: ResetIteration%1065164420
      void ResetIteration (ESTIterationType p_eIterationType);

      //## Operation: GetDeltaSpeed%1065164421
      //	returns the speed step used in one acceleration step
      double GetDeltaSpeed (const double p_dbAcceleration);

      //## Operation: WatchStepsDeviation%1065511408
      void WatchStepsDeviation (const int p_iNomPos, const int p_iActPos);

      //## Operation: MakeHardwareVelocity%1065511413
      double MakeHardwareVelocity (const double& p_dbValue = 0);

      //## Operation: GetTickNumber%1065684040
      //	returns a high resolution time. ::gettickcount() has not
      //	enough resolution.
      bool GetTickNumber (double& p_dbTickNumber);

      //## Operation: CheckHomePosition%1066031291
      bool CheckHomePosition ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwSteps%3F5331A50148
      DWORD GetdwSteps ();
      void SetdwSteps (DWORD value);

      //## Attribute: bLimitHit%3FE05E9302A2
      bool GetbLimitHit ();
      void SetbLimitHit (bool value);

      //## Attribute: dwSpeedRateOld%3EA51E100203
      DWORD GetdwSpeedRateOld ();
      void SetdwSpeedRateOld (DWORD value);

      //## Attribute: dbVEnd%3E9560BA0213
      double GetdbVEnd ();
      void SetdbVEnd (double value);

      //## Attribute: dbSearchDuration%3F582EFC029F
      double GetdbSearchDuration ();

      //## Attribute: dbAccDuration%3F7A83F702C4
      double GetdbAccDuration ();
      void SetdbAccDuration (double value);

      //## Attribute: dwCurIterations%3F7BE61A0266
      DWORD GetdwCurIterations ();

      //## Attribute: dwCurIterationCnt%3F7C880E011C
      DWORD GetdwCurIterationCnt ();

      //## Attribute: dbTimeBase%3F7C8541005D
      double GetdbTimeBase ();

      //## Attribute: dbDeltaT%3F7C87A903DE
      double GetdbDeltaT ();

      //## Attribute: dbBaseTimeLimit%3FBE0DEC0160
      double GetdbBaseTimeLimit ();
      void SetdbBaseTimeLimit (double value);

      //## Attribute: dbS1%3F8160440166
      double GetdbS1 ();

      //## Attribute: dbS2%3F81607D0157
      double GetdbS2 ();

      //## Attribute: dbS3%3F81607F02CE
      double GetdbS3 ();

      //## Attribute: dbS4%3F8160810166
      double GetdbS4 ();

      //## Attribute: dbS5%3F81608401D4
      double GetdbS5 ();

      //## Attribute: dbVEndOrg%3F8161F800DA
      double GetdbVEndOrg ();

      //## Attribute: bNoAccelleration%3F81622B034B
      bool GetbNoAccelleration ();

      //## Attribute: bNoRunSpeed%3F81626102CE
      bool GetbNoRunSpeed ();

      //## Attribute: dbRunDuration%3F8162BA03D7
      double GetdbRunDuration ();

      //## Attribute: dwIT1%3F81733D01F3
      DWORD GetdwIT1 ();

      //## Attribute: dwIT3%3F8173950109
      DWORD GetdwIT3 ();

      //## Attribute: dwIT5%3F8173960270
      DWORD GetdwIT5 ();

      //## Attribute: dwHomingCounter%3F8A6BF002AB
      DWORD GetdwHomingCounter ();
      void SetdwHomingCounter (DWORD value);

      //## Attribute: iHomingOldPosition%3F8A6C430079
      void SetiHomingOldPosition (int value);

      //## Attribute: iHomingLatchedPosition%43424A840131
      INT GetiHomingLatchedPosition ();
      void SetiHomingLatchedPosition (INT value);

      //## Attribute: dbSpeedAfterAcceleration%4A1242C30192
      double GetdbSpeedAfterAcceleration ();
      void SetdbSpeedAfterAcceleration (double value);

    // Additional Public Declarations
      //## begin CSTLogic%3F4F6A1B03A9.public preserve=yes
      //## end CSTLogic%3F4F6A1B03A9.public

  protected:
    // Additional Protected Declarations
      //## begin CSTLogic%3F4F6A1B03A9.protected preserve=yes
      //## end CSTLogic%3F4F6A1B03A9.protected

  private:
    //## Constructors (generated)
      CSTLogic();

      CSTLogic(const CSTLogic &right);

    //## Assignment Operation (generated)
      const CSTLogic & operator=(const CSTLogic &right);

    //## Equality Operations (generated)
      bool operator==(const CSTLogic &right) const;

      bool operator!=(const CSTLogic &right) const;

    // Data Members for Class Attributes

      //## begin CSTLogic::dwSteps%3F5331A50148.attr preserve=no  public: DWORD {U} 0
      DWORD m_dwSteps;
      //## end CSTLogic::dwSteps%3F5331A50148.attr

      //## begin CSTLogic::bLimitHit%3FE05E9302A2.attr preserve=no  public: bool {U} false
      bool m_bLimitHit;
      //## end CSTLogic::bLimitHit%3FE05E9302A2.attr

      //## begin CSTLogic::dwSpeedRateOld%3EA51E100203.attr preserve=no  public: DWORD {U} 0
      DWORD m_dwSpeedRateOld;
      //## end CSTLogic::dwSpeedRateOld%3EA51E100203.attr

      //## begin CSTLogic::dbVEnd%3E9560BA0213.attr preserve=no  public: double {U} 0.0
      double m_dbVEnd;
      //## end CSTLogic::dbVEnd%3E9560BA0213.attr

      //## begin CSTLogic::dbSearchDuration%3F582EFC029F.attr preserve=no  public: double {U} 0
      double m_dbSearchDuration;
      //## end CSTLogic::dbSearchDuration%3F582EFC029F.attr

      //## begin CSTLogic::dbAccDuration%3F7A83F702C4.attr preserve=no  public: double {U} 0
      double m_dbAccDuration;
      //## end CSTLogic::dbAccDuration%3F7A83F702C4.attr

      //## begin CSTLogic::dwCurIterations%3F7BE61A0266.attr preserve=no  public: DWORD {U} 0
      DWORD m_dwCurIterations;
      //## end CSTLogic::dwCurIterations%3F7BE61A0266.attr

      //## begin CSTLogic::dwCurIterationCnt%3F7C880E011C.attr preserve=no  public: DWORD {U} 0
      DWORD m_dwCurIterationCnt;
      //## end CSTLogic::dwCurIterationCnt%3F7C880E011C.attr

      //## begin CSTLogic::dbTimeBase%3F7C8541005D.attr preserve=no  public: double {U} 0
      double m_dbTimeBase;
      //## end CSTLogic::dbTimeBase%3F7C8541005D.attr

      //## begin CSTLogic::dbDeltaT%3F7C87A903DE.attr preserve=no  public: double {U} 0.0
      double m_dbDeltaT;
      //## end CSTLogic::dbDeltaT%3F7C87A903DE.attr

      //## begin CSTLogic::dbBaseTimeLimit%3FBE0DEC0160.attr preserve=no  public: double {U} 0
      double m_dbBaseTimeLimit;
      //## end CSTLogic::dbBaseTimeLimit%3FBE0DEC0160.attr

      //## begin CSTLogic::dbS1%3F8160440166.attr preserve=no  public: double {U} 0
      double m_dbS1;
      //## end CSTLogic::dbS1%3F8160440166.attr

      //## begin CSTLogic::dbS2%3F81607D0157.attr preserve=no  public: double {U} 0
      double m_dbS2;
      //## end CSTLogic::dbS2%3F81607D0157.attr

      //## begin CSTLogic::dbS3%3F81607F02CE.attr preserve=no  public: double {U} 0
      double m_dbS3;
      //## end CSTLogic::dbS3%3F81607F02CE.attr

      //## begin CSTLogic::dbS4%3F8160810166.attr preserve=no  public: double {U} 0
      double m_dbS4;
      //## end CSTLogic::dbS4%3F8160810166.attr

      //## begin CSTLogic::dbS5%3F81608401D4.attr preserve=no  public: double {U} 0
      double m_dbS5;
      //## end CSTLogic::dbS5%3F81608401D4.attr

      //## begin CSTLogic::dbVEndOrg%3F8161F800DA.attr preserve=no  public: double {U} 0
      double m_dbVEndOrg;
      //## end CSTLogic::dbVEndOrg%3F8161F800DA.attr

      //## begin CSTLogic::bNoAccelleration%3F81622B034B.attr preserve=no  public: bool {U} false
      bool m_bNoAccelleration;
      //## end CSTLogic::bNoAccelleration%3F81622B034B.attr

      //## begin CSTLogic::bNoRunSpeed%3F81626102CE.attr preserve=no  public: bool {U} false
      bool m_bNoRunSpeed;
      //## end CSTLogic::bNoRunSpeed%3F81626102CE.attr

      //## begin CSTLogic::dbRunDuration%3F8162BA03D7.attr preserve=no  public: double {U} 0
      double m_dbRunDuration;
      //## end CSTLogic::dbRunDuration%3F8162BA03D7.attr

      //## begin CSTLogic::dwIT1%3F81733D01F3.attr preserve=no  public: DWORD {U} 0
      DWORD m_dwIT1;
      //## end CSTLogic::dwIT1%3F81733D01F3.attr

      //## begin CSTLogic::dwIT3%3F8173950109.attr preserve=no  public: DWORD {U} 0
      DWORD m_dwIT3;
      //## end CSTLogic::dwIT3%3F8173950109.attr

      //## begin CSTLogic::dwIT5%3F8173960270.attr preserve=no  public: DWORD {U} 0
      DWORD m_dwIT5;
      //## end CSTLogic::dwIT5%3F8173960270.attr

      //## begin CSTLogic::dwHomingCounter%3F8A6BF002AB.attr preserve=no  public: DWORD {U} 0
      DWORD m_dwHomingCounter;
      //## end CSTLogic::dwHomingCounter%3F8A6BF002AB.attr

      //## begin CSTLogic::iHomingOldPosition%3F8A6C430079.attr preserve=no  public: int {U} 0
      int m_iHomingOldPosition;
      //## end CSTLogic::iHomingOldPosition%3F8A6C430079.attr

      //## begin CSTLogic::iHomingLatchedPosition%43424A840131.attr preserve=no  public: INT {U} 0
      INT m_iHomingLatchedPosition;
      //## end CSTLogic::iHomingLatchedPosition%43424A840131.attr

      //## begin CSTLogic::dbSpeedAfterAcceleration%4A1242C30192.attr preserve=no  public: double {U} 0.0
      double m_dbSpeedAfterAcceleration;
      //## end CSTLogic::dbSpeedAfterAcceleration%4A1242C30192.attr

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3F4F6BAD0251
      //## Role: CSTLogic::pContext%3F4F6BAE038B
      //## begin CSTLogic::pContext%3F4F6BAE038B.role preserve=no  public: CSTStepperMotorImplementation {1..1 -> 1..1RFHN}
      CSTStepperMotorImplementation *m_pContext;
      //## end CSTLogic::pContext%3F4F6BAE038B.role

      //## Association: EBST (Stepper Motor)::<unnamed>%4105FCA9010D
      //## Role: CSTLogic::liFrequency%4105FCA90320
      //## begin CSTLogic::liFrequency%4105FCA90320.role preserve=no  public: LARGE_INTEGER {1..1 -> 1..1VFHN}
      LARGE_INTEGER m_liFrequency;
      //## end CSTLogic::liFrequency%4105FCA90320.role

    // Additional Private Declarations
      //## begin CSTLogic%3F4F6A1B03A9.private preserve=yes
      //## end CSTLogic%3F4F6A1B03A9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTLogic%3F4F6A1B03A9.implementation preserve=yes
      //## end CSTLogic%3F4F6A1B03A9.implementation

};

//## begin CSTLogic%3F4F6A1B03A9.postscript preserve=yes
//## end CSTLogic%3F4F6A1B03A9.postscript

// Class CSTPositionMachine 

// Class CSTLogic 

//## begin module%3E75E2660360.epilog preserve=yes
//## end module%3E75E2660360.epilog


#endif
