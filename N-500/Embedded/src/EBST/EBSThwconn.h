//## begin module%3F3234340208.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F3234340208.cm

//## begin module%3F3234340208.cp preserve=no
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
//## end module%3F3234340208.cp

//## Module: EBSThwconn%3F3234340208; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSThwconn.h

#ifndef EBSThwconn_h
#define EBSThwconn_h 1

//## begin module%3F3234340208.additionalIncludes preserve=no
//## end module%3F3234340208.additionalIncludes

//## begin module%3F3234340208.includes preserve=yes
//## end module%3F3234340208.includes


class EBST_DLL_DECL CSTStepperMotorImplementation;
class EBCO_DLL_DECL CCOSyncObject;

//## begin module%3F3234340208.declarations preserve=no
//## end module%3F3234340208.declarations

//## begin module%3F3234340208.additionalDeclarations preserve=yes
//## end module%3F3234340208.additionalDeclarations


//## begin ESTValidType%3F8BF4B4006A.preface preserve=yes
//## end ESTValidType%3F8BF4B4006A.preface

//## Class: ESTValidType%3F8BF4B4006A
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {eVelocityValid, eStepsValid, eStepsAndVelocityValid} ESTValidType;

//## begin ESTValidType%3F8BF4B4006A.postscript preserve=yes
//## end ESTValidType%3F8BF4B4006A.postscript

//## begin ESTMotorCommands%3F8BFC4903A7.preface preserve=yes
//## end ESTMotorCommands%3F8BFC4903A7.preface

//## Class: ESTMotorCommands%3F8BFC4903A7
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum {eStop = 0x0, eContinuous=0xFFFFF } ESTMotorCommands;

//## begin ESTMotorCommands%3F8BFC4903A7.postscript preserve=yes
//## end ESTMotorCommands%3F8BFC4903A7.postscript

//## begin CSTHardwareConnection%3F3233A902A4.preface preserve=yes
//## end CSTHardwareConnection%3F3233A902A4.preface

//## Class: CSTHardwareConnection%3F3233A902A4
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F32449003BE;IHIInterface { -> }
//## Uses: <unnamed>%3F3369C2032B;CSTPositionMachine { -> }
//## Uses: <unnamed>%3F4B2A0A01DC;CPIComponentsState { -> }
//## Uses: <unnamed>%3F4B2AE703B1;ST_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F8A8AF8029C;CSTLimitHandler { -> }
//## Uses: <unnamed>%3F8A91B202F9;XSTExceptionHomingLimitConfig { -> }
//## Uses: <unnamed>%3F8BF530004B;ESTValidType { -> }
//## Uses: <unnamed>%3F8BFCEE01C2;ESTMotorCommands { -> }

class CSTHardwareConnection 
{
  //## begin CSTHardwareConnection%3F3233A902A4.initialDeclarations preserve=yes
  //## end CSTHardwareConnection%3F3233A902A4.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTHardwareConnection%1060332619
      CSTHardwareConnection (CSTStepperMotorImplementation* p_pContext);

    //## Destructor (generated)
      virtual ~CSTHardwareConnection();


    //## Other Operations (specified)
      //## Operation: SetSteps%1060256022
      void SetSteps (const DWORD p_dwSteps = 0);

      //## Operation: SetVelocity%1060256024
      //	effective set hardware speed
      double SetVelocity (const double p_dbVelocity = 0);

      //## Operation: GetRelativePos%1061458021
      INT GetRelativePos (const int p_iPos = 0);

      //## Operation: Stoping%1064993962
      void Stoping ();

      //## Operation: SetValid%1066136883
      void SetValid (ESTValidType p_eValid);

      //## Operation: Moving%1066202866
      void Moving (const DWORD p_dwSteps = 0);

      //## Operation: IsActive%1069341918
      bool IsActive (const DWORD p_dwInputID);

      //## Operation: StartHoming%1193385554
      void StartHoming (INT p_iCurrentPosition);

      //## Operation: TrackHomingSteps%1193385557
      void TrackHomingSteps ();

      //## Operation: GetHomingSteps%1193385555
      INT GetHomingSteps ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: bHardwarePresent%3F423CC202F5
      bool GetbHardwarePresent ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBST (Stepper Motor)::<unnamed>%415167B302DE
      //## Role: CSTHardwareConnection::pMovingEvent%415167B40271
      CCOSyncObject * GetpMovingEvent ();
      void SetpMovingEvent (CCOSyncObject * value);

    // Additional Public Declarations
      //## begin CSTHardwareConnection%3F3233A902A4.public preserve=yes
      //## end CSTHardwareConnection%3F3233A902A4.public

  protected:
    // Additional Protected Declarations
      //## begin CSTHardwareConnection%3F3233A902A4.protected preserve=yes
      //## end CSTHardwareConnection%3F3233A902A4.protected

  private:
    //## Constructors (generated)
      CSTHardwareConnection(const CSTHardwareConnection &right);

    //## Assignment Operation (generated)
      const CSTHardwareConnection & operator=(const CSTHardwareConnection &right);

    //## Equality Operations (generated)
      bool operator==(const CSTHardwareConnection &right) const;

      bool operator!=(const CSTHardwareConnection &right) const;

    // Data Members for Class Attributes

      //## begin CSTHardwareConnection::bHardwarePresent%3F423CC202F5.attr preserve=no  public: bool {U} false
      bool m_bHardwarePresent;
      //## end CSTHardwareConnection::bHardwarePresent%3F423CC202F5.attr

      //## Attribute: iHomingSteps%47219E8102B7
      //## begin CSTHardwareConnection::iHomingSteps%47219E8102B7.attr preserve=no  private: INT {U} 0
      INT m_iHomingSteps;
      //## end CSTHardwareConnection::iHomingSteps%47219E8102B7.attr

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3F3363FF0128
      //## Role: CSTHardwareConnection::pContext%3F33640002DE
      //## begin CSTHardwareConnection::pContext%3F33640002DE.role preserve=no  public: CSTStepperMotorImplementation {1..1 -> 1..1RFHN}
      CSTStepperMotorImplementation *m_pContext;
      //## end CSTHardwareConnection::pContext%3F33640002DE.role

      //## Association: EBST (Stepper Motor)::<unnamed>%415167B302DE
      //## begin CSTHardwareConnection::pMovingEvent%415167B40271.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pMovingEvent;
      //## end CSTHardwareConnection::pMovingEvent%415167B40271.role

    // Additional Private Declarations
      //## begin CSTHardwareConnection%3F3233A902A4.private preserve=yes
      //## end CSTHardwareConnection%3F3233A902A4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTHardwareConnection%3F3233A902A4.implementation preserve=yes
      //## end CSTHardwareConnection%3F3233A902A4.implementation

};

//## begin CSTHardwareConnection%3F3233A902A4.postscript preserve=yes
//## end CSTHardwareConnection%3F3233A902A4.postscript

// Class CSTHardwareConnection 

//## begin module%3F3234340208.epilog preserve=yes
//## end module%3F3234340208.epilog


#endif
