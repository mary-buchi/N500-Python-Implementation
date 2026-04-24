//## begin module%3DE5EE1400A1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EE1400A1.cm

//## begin module%3DE5EE1400A1.cp preserve=no
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
//## end module%3DE5EE1400A1.cp

//## Module: EBTCimpl%3DE5EE1400A1; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCimpl.h

#ifndef EBTCimpl_h
#define EBTCimpl_h 1

//## begin module%3DE5EE1400A1.additionalIncludes preserve=no
//## end module%3DE5EE1400A1.additionalIncludes

//## begin module%3DE5EE1400A1.includes preserve=yes
//## end module%3DE5EE1400A1.includes

// EBCOimpl
#include "EBCOimpl.h"

class EBPI_DLL_DECL CPITemperatureControlConfig;
class EBPI_DLL_DECL CPITemperatureControlProfile;
class EBTC_DLL_DECL CTCTemperatureControlInterface;
class EBTC_DLL_DECL CTCLogic;
class EBTC_DLL_DECL CTCTemperatureControlInterface2;
class CTCPid2;
class CTCPid;

//## begin module%3DE5EE1400A1.declarations preserve=no
//## end module%3DE5EE1400A1.declarations

//## begin module%3DE5EE1400A1.additionalDeclarations preserve=yes
//## end module%3DE5EE1400A1.additionalDeclarations


//## begin CTCTemperatureControlImplementation%3DEC5F100252.preface preserve=yes
//## end CTCTemperatureControlImplementation%3DEC5F100252.preface

//## Class: CTCTemperatureControlImplementation%3DEC5F100252
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DEC60C103A9;CTCTemperatureControlInterface { -> F}
//## Uses: <unnamed>%3DEC841300AF;CTCStateMachineEngine { -> }
//## Uses: <unnamed>%48899C99003D;CTCCommandCellUndocked { -> }
//## Uses: <unnamed>%48899C9F0195;XCOExceptionCellUndocked { -> }

class CTCTemperatureControlImplementation : public ICOAsyncImplementation  //## Inherits: <unnamed>%3DEC5F2A0196
{
  //## begin CTCTemperatureControlImplementation%3DEC5F100252.initialDeclarations preserve=yes
  //## end CTCTemperatureControlImplementation%3DEC5F100252.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCTemperatureControlImplementation%1038899314
      CTCTemperatureControlImplementation (CTCTemperatureControlInterface* p_pInterface);

    //## Destructor (generated)
      virtual ~CTCTemperatureControlImplementation();


    //## Other Operations (specified)
      //## Operation: InitInstance%1038899315
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

      //## Operation: PIDDo%1216975787
      virtual double PIDDo (double p_pActualTemp);

      //## Operation: PIDReset%1216975788
      virtual void PIDReset ();

      //## Operation: PIDSet%1216975789
      virtual void PIDSet (double p_NomTemp, double p_dKp, double p_dTi, double p_dTv, double p_dLLimit, double p_dULimit, double p_dTs);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBTC (Temperature Control)::<unnamed>%3E53978D01EA
      //## Role: CTCTemperatureControlImplementation::pLogic%3E53978E010F
      CTCLogic * GetpLogic ();

      //## Association: EBTC (Temperature Control)::<unnamed>%3E53B62D039F
      //## Role: CTCTemperatureControlImplementation::pConfig%3E53B62E0287
      CPITemperatureControlConfig * GetpConfig ();
      void SetpConfig (CPITemperatureControlConfig * value);

      //## Association: EBTC (Temperature Control)::<unnamed>%3E8C23F301F6
      //## Role: CTCTemperatureControlImplementation::pProfile%3E8C23F40051
      CPITemperatureControlProfile * GetpProfile ();
      void SetpProfile (CPITemperatureControlProfile * value);

      //## Association: EBTC (Temperature Control)::<unnamed>%40C87A01004B
      //## Role: CTCTemperatureControlImplementation::pPidController%40C87A01029C
      CTCPid * GetpPidController ();

    // Additional Public Declarations
      //## begin CTCTemperatureControlImplementation%3DEC5F100252.public preserve=yes
      //## end CTCTemperatureControlImplementation%3DEC5F100252.public

  protected:

    //## Other Operations (specified)
      //## Operation: HandleErrorException%1216975782
      //	returns true, if the given exception should be thrown
      //	out of the subsystem interface
      virtual bool HandleErrorException (XCOExceptionError* p_pException);

    // Additional Protected Declarations
      //## begin CTCTemperatureControlImplementation%3DEC5F100252.protected preserve=yes
      //## end CTCTemperatureControlImplementation%3DEC5F100252.protected

  private:
    //## Constructors (generated)
      CTCTemperatureControlImplementation();

      CTCTemperatureControlImplementation(const CTCTemperatureControlImplementation &right);

    //## Assignment Operation (generated)
      const CTCTemperatureControlImplementation & operator=(const CTCTemperatureControlImplementation &right);

    //## Equality Operations (generated)
      bool operator==(const CTCTemperatureControlImplementation &right) const;

      bool operator!=(const CTCTemperatureControlImplementation &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3E53978D01EA
      //## begin CTCTemperatureControlImplementation::pLogic%3E53978E010F.role preserve=no  public: CTCLogic {1..1 -> 1..1RFHN}
      CTCLogic *m_pLogic;
      //## end CTCTemperatureControlImplementation::pLogic%3E53978E010F.role

      //## Association: EBTC (Temperature Control)::<unnamed>%3E53B62D039F
      //## begin CTCTemperatureControlImplementation::pConfig%3E53B62E0287.role preserve=no  public: CPITemperatureControlConfig {1..1 -> 1..1RFHN}
      CPITemperatureControlConfig *m_pConfig;
      //## end CTCTemperatureControlImplementation::pConfig%3E53B62E0287.role

      //## Association: EBTC (Temperature Control)::<unnamed>%3E8C23F301F6
      //## begin CTCTemperatureControlImplementation::pProfile%3E8C23F40051.role preserve=no  public: CPITemperatureControlProfile {1..1 -> 1..1RFHN}
      CPITemperatureControlProfile *m_pProfile;
      //## end CTCTemperatureControlImplementation::pProfile%3E8C23F40051.role

      //## Association: EBTC (Temperature Control)::<unnamed>%40C87A01004B
      //## begin CTCTemperatureControlImplementation::pPidController%40C87A01029C.role preserve=no  public: CTCPid {1..1 -> 1..1RFHN}
      CTCPid *m_pPidController;
      //## end CTCTemperatureControlImplementation::pPidController%40C87A01029C.role

    // Additional Private Declarations
      //## begin CTCTemperatureControlImplementation%3DEC5F100252.private preserve=yes
      //## end CTCTemperatureControlImplementation%3DEC5F100252.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCTemperatureControlImplementation%3DEC5F100252.implementation preserve=yes
      //## end CTCTemperatureControlImplementation%3DEC5F100252.implementation

};

//## begin CTCTemperatureControlImplementation%3DEC5F100252.postscript preserve=yes
//## end CTCTemperatureControlImplementation%3DEC5F100252.postscript

//## begin CTCTemperatureControlImplementation2%48970A5402EA.preface preserve=yes
//## end CTCTemperatureControlImplementation2%48970A5402EA.preface

//## Class: CTCTemperatureControlImplementation2%48970A5402EA
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%4897152401D1;CTCTemperatureControlInterface2 { -> F}

class CTCTemperatureControlImplementation2 : public CTCTemperatureControlImplementation  //## Inherits: <unnamed>%48970A7001DB
{
  //## begin CTCTemperatureControlImplementation2%48970A5402EA.initialDeclarations preserve=yes
  //## end CTCTemperatureControlImplementation2%48970A5402EA.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCTemperatureControlImplementation2%1217858754
      CTCTemperatureControlImplementation2 (CTCTemperatureControlInterface2* p_pInterface);

    //## Destructor (generated)
      virtual ~CTCTemperatureControlImplementation2();


    //## Other Operations (specified)
      //## Operation: InitInstance%1217858753
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

      //## Operation: PIDDo%1217858750
      virtual double PIDDo (double p_pActualTemp);

      //## Operation: PIDReset%1217858751
      virtual void PIDReset ();

      //## Operation: PIDSet%1217858752
      virtual void PIDSet (double p_NomTemp, double p_dKp, double p_dTi, double p_dTv, double p_dLLimit, double p_dULimit, double p_dTs);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBTC (Temperature Control)::<unnamed>%48970AE702F9
      //## Role: CTCTemperatureControlImplementation2::pPidController2%48970AE80181
      CTCPid2 * GetpPidController2 ();

    // Additional Public Declarations
      //## begin CTCTemperatureControlImplementation2%48970A5402EA.public preserve=yes
      //## end CTCTemperatureControlImplementation2%48970A5402EA.public

  protected:
    // Additional Protected Declarations
      //## begin CTCTemperatureControlImplementation2%48970A5402EA.protected preserve=yes
      //## end CTCTemperatureControlImplementation2%48970A5402EA.protected

  private:
    //## Constructors (generated)
      CTCTemperatureControlImplementation2();

      CTCTemperatureControlImplementation2(const CTCTemperatureControlImplementation2 &right);

    //## Assignment Operation (generated)
      const CTCTemperatureControlImplementation2 & operator=(const CTCTemperatureControlImplementation2 &right);

    //## Equality Operations (generated)
      bool operator==(const CTCTemperatureControlImplementation2 &right) const;

      bool operator!=(const CTCTemperatureControlImplementation2 &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%48970AE702F9
      //## begin CTCTemperatureControlImplementation2::pPidController2%48970AE80181.role preserve=no  public: CTCPid2 {1..1 -> 1..1RFHN}
      CTCPid2 *m_pPidController2;
      //## end CTCTemperatureControlImplementation2::pPidController2%48970AE80181.role

    // Additional Private Declarations
      //## begin CTCTemperatureControlImplementation2%48970A5402EA.private preserve=yes
      //## end CTCTemperatureControlImplementation2%48970A5402EA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCTemperatureControlImplementation2%48970A5402EA.implementation preserve=yes
      //## end CTCTemperatureControlImplementation2%48970A5402EA.implementation

};

//## begin CTCTemperatureControlImplementation2%48970A5402EA.postscript preserve=yes
//## end CTCTemperatureControlImplementation2%48970A5402EA.postscript

// Class CTCTemperatureControlImplementation 

// Class CTCTemperatureControlImplementation2 

//## begin module%3DE5EE1400A1.epilog preserve=yes
//## end module%3DE5EE1400A1.epilog


#endif
