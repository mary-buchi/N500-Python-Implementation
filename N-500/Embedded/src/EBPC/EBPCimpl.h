//## begin module%3EED769F0374.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F0374.cm

//## begin module%3EED769F0374.cp preserve=no
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
//## end module%3EED769F0374.cp

//## Module: EBPCimpl%3EED769F0374; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCimpl.h

#ifndef EBPCimpl_h
#define EBPCimpl_h 1

//## begin module%3EED769F0374.additionalIncludes preserve=no
//## end module%3EED769F0374.additionalIncludes

//## begin module%3EED769F0374.includes preserve=yes
//## end module%3EED769F0374.includes

// EBCOimpl
#include "EBCOimpl.h"

class EBPI_DLL_DECL CPIPowerControlProfile;
class EBPI_DLL_DECL CPIPowerControlConfig;
class EBPC_DLL_DECL CPCPowerControlInterface;
class EBPC_DLL_DECL CPCLogic;
class CPCPid;

//## begin module%3EED769F0374.declarations preserve=no
//## end module%3EED769F0374.declarations

//## begin module%3EED769F0374.additionalDeclarations preserve=yes
//## end module%3EED769F0374.additionalDeclarations


//## begin CPCPowerControlImplementation%3EED76CC032D.preface preserve=yes
//## end CPCPowerControlImplementation%3EED76CC032D.preface

//## Class: CPCPowerControlImplementation%3EED76CC032D
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EED76CC0332;CPCPowerControlInterface { -> F}
//## Uses: <unnamed>%3EED76CC0335;CPCStateMachineEngine { -> }

class CPCPowerControlImplementation : public ICOAsyncImplementation  //## Inherits: <unnamed>%3EED76CC032F
{
  //## begin CPCPowerControlImplementation%3EED76CC032D.initialDeclarations preserve=yes
  //## end CPCPowerControlImplementation%3EED76CC032D.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPCPowerControlImplementation%1038899314
      CPCPowerControlImplementation (CPCPowerControlInterface* p_pInterface);

    //## Destructor (generated)
      virtual ~CPCPowerControlImplementation();


    //## Other Operations (specified)
      //## Operation: InitInstance%1038899315
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPC (Power Control)::<unnamed>%3EED76CC08EB
      //## Role: CPCPowerControlImplementation::pLogic%3EED76CC08F0
      CPCLogic * GetpLogic ();

      //## Association: EBPC (Power Control)::<unnamed>%3F0E8CCD0181
      //## Role: CPCPowerControlImplementation::pConfig%3F0E8CCD01CF
      CPIPowerControlConfig * GetpConfig ();
      void SetpConfig (CPIPowerControlConfig * value);

      //## Association: EBPC (Power Control)::<unnamed>%3F13F7730096
      //## Role: CPCPowerControlImplementation::pProfile%3F13F773028B
      CPIPowerControlProfile * GetpProfile ();
      void SetpProfile (CPIPowerControlProfile * value);

      //## Association: EBPC (Power Control)::<unnamed>%40346A6E02B7
      //## Role: CPCPowerControlImplementation::pPID%40346A6F017F
      CPCPid * GetpPID ();

    // Additional Public Declarations
      //## begin CPCPowerControlImplementation%3EED76CC032D.public preserve=yes
      //## end CPCPowerControlImplementation%3EED76CC032D.public

  protected:
    // Additional Protected Declarations
      //## begin CPCPowerControlImplementation%3EED76CC032D.protected preserve=yes
      //## end CPCPowerControlImplementation%3EED76CC032D.protected

  private:
    //## Constructors (generated)
      CPCPowerControlImplementation();

      CPCPowerControlImplementation(const CPCPowerControlImplementation &right);

    //## Assignment Operation (generated)
      const CPCPowerControlImplementation & operator=(const CPCPowerControlImplementation &right);

    //## Equality Operations (generated)
      bool operator==(const CPCPowerControlImplementation &right) const;

      bool operator!=(const CPCPowerControlImplementation &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%3EED76CC08EB
      //## begin CPCPowerControlImplementation::pLogic%3EED76CC08F0.role preserve=no  public: CPCLogic {1..1 -> 1..1RFHN}
      CPCLogic *m_pLogic;
      //## end CPCPowerControlImplementation::pLogic%3EED76CC08F0.role

      //## Association: EBPC (Power Control)::<unnamed>%3F0E8CCD0181
      //## begin CPCPowerControlImplementation::pConfig%3F0E8CCD01CF.role preserve=no  public: CPIPowerControlConfig {1..1 -> 1..1RFHN}
      CPIPowerControlConfig *m_pConfig;
      //## end CPCPowerControlImplementation::pConfig%3F0E8CCD01CF.role

      //## Association: EBPC (Power Control)::<unnamed>%3F13F7730096
      //## begin CPCPowerControlImplementation::pProfile%3F13F773028B.role preserve=no  public: CPIPowerControlProfile {1..1 -> 1..1RFHN}
      CPIPowerControlProfile *m_pProfile;
      //## end CPCPowerControlImplementation::pProfile%3F13F773028B.role

      //## Association: EBPC (Power Control)::<unnamed>%40346A6E02B7
      //## begin CPCPowerControlImplementation::pPID%40346A6F017F.role preserve=no  public: CPCPid {1..1 -> 1..1RFHN}
      CPCPid *m_pPID;
      //## end CPCPowerControlImplementation::pPID%40346A6F017F.role

    // Additional Private Declarations
      //## begin CPCPowerControlImplementation%3EED76CC032D.private preserve=yes
      //## end CPCPowerControlImplementation%3EED76CC032D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCPowerControlImplementation%3EED76CC032D.implementation preserve=yes
      //## end CPCPowerControlImplementation%3EED76CC032D.implementation

};

//## begin CPCPowerControlImplementation%3EED76CC032D.postscript preserve=yes
//## end CPCPowerControlImplementation%3EED76CC032D.postscript

// Class CPCPowerControlImplementation 

//## begin module%3EED769F0374.epilog preserve=yes
//## end module%3EED769F0374.epilog


#endif
