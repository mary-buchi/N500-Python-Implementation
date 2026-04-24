//## begin module%3EE08A2B0372.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE08A2B0372.cm

//## begin module%3EE08A2B0372.cp preserve=no
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
//## end module%3EE08A2B0372.cp

//## Module: EBSYrdsw%3EE08A2B0372; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYrdsw.h

#ifndef EBSYrdsw_h
#define EBSYrdsw_h 1

//## begin module%3EE08A2B0372.additionalIncludes preserve=no
//## end module%3EE08A2B0372.additionalIncludes

//## begin module%3EE08A2B0372.includes preserve=yes
//## end module%3EE08A2B0372.includes

// EBSYproc
#include "EBSYproc.h"
// EBSYcons
#include "EBSYcons.h"

class EBCO_DLL_DECL CCOSyncObject;

//## begin module%3EE08A2B0372.declarations preserve=no
//## end module%3EE08A2B0372.declarations

//## begin module%3EE08A2B0372.additionalDeclarations preserve=yes
//## end module%3EE08A2B0372.additionalDeclarations


//## begin CSYStateProcessReadSoftwareVersions%3FA232640138.preface preserve=yes
//## end CSYStateProcessReadSoftwareVersions%3FA232640138.preface

//## Class: CSYStateProcessReadSoftwareVersions%3FA232640138
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%400695500283;CSYStateProcessIdle { -> }
//## Uses: <unnamed>%4091151C0269;CSYModuleHandling { -> }

class CSYStateProcessReadSoftwareVersions : public CSYStateProcess  //## Inherits: <unnamed>%3FA232720399
{
  //## begin CSYStateProcessReadSoftwareVersions%3FA232640138.initialDeclarations preserve=yes
  //## end CSYStateProcessReadSoftwareVersions%3FA232640138.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateProcessReadSoftwareVersions();

    //## Destructor (generated)
      virtual ~CSYStateProcessReadSoftwareVersions();


    //## Other Operations (specified)
      //## Operation: Create%1067594679
      static void Create ();

      //## Operation: Delete%1067594680
      static void Delete ();

      //## Operation: GetInstance%1067594681
      static CSYStateProcessReadSoftwareVersions* GetInstance ();

      //## Operation: Do%1067594682
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBSY (System Control)::<unnamed>%409114E20095
      //## Role: CSYStateProcessReadSoftwareVersions::pClientSyncObj%409114E202B8
      void SetpClientSyncObj (CCOSyncObject * value);

    // Additional Public Declarations
      //## begin CSYStateProcessReadSoftwareVersions%3FA232640138.public preserve=yes
      //## end CSYStateProcessReadSoftwareVersions%3FA232640138.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateProcessReadSoftwareVersions%3FA232640138.protected preserve=yes
      //## end CSYStateProcessReadSoftwareVersions%3FA232640138.protected

  private:
    //## Constructors (generated)
      CSYStateProcessReadSoftwareVersions(const CSYStateProcessReadSoftwareVersions &right);

    //## Assignment Operation (generated)
      const CSYStateProcessReadSoftwareVersions & operator=(const CSYStateProcessReadSoftwareVersions &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateProcessReadSoftwareVersions &right) const;

      bool operator!=(const CSYStateProcessReadSoftwareVersions &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3FA232AE0203
      //## Role: CSYStateProcessReadSoftwareVersions::pInstance%3FA232AF01B6
      //## begin CSYStateProcessReadSoftwareVersions::pInstance%3FA232AF01B6.role preserve=no  public: static CSYStateProcessReadSoftwareVersions {1..1 -> RFHN}
      static CSYStateProcessReadSoftwareVersions *m_pInstance;
      //## end CSYStateProcessReadSoftwareVersions::pInstance%3FA232AF01B6.role

      //## Association: EBSY (System Control)::<unnamed>%409114E20095
      //## begin CSYStateProcessReadSoftwareVersions::pClientSyncObj%409114E202B8.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pClientSyncObj;
      //## end CSYStateProcessReadSoftwareVersions::pClientSyncObj%409114E202B8.role

    // Additional Private Declarations
      //## begin CSYStateProcessReadSoftwareVersions%3FA232640138.private preserve=yes
      //## end CSYStateProcessReadSoftwareVersions%3FA232640138.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateProcessReadSoftwareVersions%3FA232640138.implementation preserve=yes
      //## end CSYStateProcessReadSoftwareVersions%3FA232640138.implementation

};

//## begin CSYStateProcessReadSoftwareVersions%3FA232640138.postscript preserve=yes
//## end CSYStateProcessReadSoftwareVersions%3FA232640138.postscript

//## begin CSYStateConstitutionReadSoftwareVersions%4006866E0293.preface preserve=yes
//## end CSYStateConstitutionReadSoftwareVersions%4006866E0293.preface

//## Class: CSYStateConstitutionReadSoftwareVersions%4006866E0293
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%400693D10060;CSYStateConstitutionConnected { -> }
//## Uses: <unnamed>%41DD5B650332;IHIInterface { -> }

class CSYStateConstitutionReadSoftwareVersions : public CSYStateConstitution  //## Inherits: <unnamed>%400686FD0264
{
  //## begin CSYStateConstitutionReadSoftwareVersions%4006866E0293.initialDeclarations preserve=yes
  //## end CSYStateConstitutionReadSoftwareVersions%4006866E0293.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitutionReadSoftwareVersions();

    //## Destructor (generated)
      virtual ~CSYStateConstitutionReadSoftwareVersions();


    //## Other Operations (specified)
      //## Operation: Create%1074169738
      static void Create ();

      //## Operation: Delete%1074169739
      static void Delete ();

      //## Operation: GetInstance%1074169740
      static CSYStateConstitutionReadSoftwareVersions* GetInstance ();

      //## Operation: Do%1074169741
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: GetDeviceState%1074169742
      virtual EPIDeviceState GetDeviceState ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBSY (System Control)::<unnamed>%40911347023A
      //## Role: CSYStateConstitutionReadSoftwareVersions::pClientSyncObj%409113480047
      void SetpClientSyncObj (CCOSyncObject * value);

    // Additional Public Declarations
      //## begin CSYStateConstitutionReadSoftwareVersions%4006866E0293.public preserve=yes
      //## end CSYStateConstitutionReadSoftwareVersions%4006866E0293.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateConstitutionReadSoftwareVersions%4006866E0293.protected preserve=yes
      //## end CSYStateConstitutionReadSoftwareVersions%4006866E0293.protected

  private:
    //## Constructors (generated)
      CSYStateConstitutionReadSoftwareVersions(const CSYStateConstitutionReadSoftwareVersions &right);

    //## Assignment Operation (generated)
      const CSYStateConstitutionReadSoftwareVersions & operator=(const CSYStateConstitutionReadSoftwareVersions &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitutionReadSoftwareVersions &right) const;

      bool operator!=(const CSYStateConstitutionReadSoftwareVersions &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%40068773012B
      //## Role: CSYStateConstitutionReadSoftwareVersions::pInstance%400687740013
      //## begin CSYStateConstitutionReadSoftwareVersions::pInstance%400687740013.role preserve=no  public: static CSYStateConstitutionReadSoftwareVersions {1..1 -> 1..1RFHN}
      static CSYStateConstitutionReadSoftwareVersions *m_pInstance;
      //## end CSYStateConstitutionReadSoftwareVersions::pInstance%400687740013.role

      //## Association: EBSY (System Control)::<unnamed>%40911347023A
      //## begin CSYStateConstitutionReadSoftwareVersions::pClientSyncObj%409113480047.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pClientSyncObj;
      //## end CSYStateConstitutionReadSoftwareVersions::pClientSyncObj%409113480047.role

    // Additional Private Declarations
      //## begin CSYStateConstitutionReadSoftwareVersions%4006866E0293.private preserve=yes
      //## end CSYStateConstitutionReadSoftwareVersions%4006866E0293.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitutionReadSoftwareVersions%4006866E0293.implementation preserve=yes
      //## end CSYStateConstitutionReadSoftwareVersions%4006866E0293.implementation

};

//## begin CSYStateConstitutionReadSoftwareVersions%4006866E0293.postscript preserve=yes
//## end CSYStateConstitutionReadSoftwareVersions%4006866E0293.postscript

// Class CSYStateProcessReadSoftwareVersions 

// Class CSYStateConstitutionReadSoftwareVersions 

//## begin module%3EE08A2B0372.epilog preserve=yes
//## end module%3EE08A2B0372.epilog


#endif
