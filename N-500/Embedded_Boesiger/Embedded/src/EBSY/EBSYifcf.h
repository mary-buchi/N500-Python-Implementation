//## begin module%3EE5D738028F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE5D738028F.cm

//## begin module%3EE5D738028F.cp preserve=no
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
//## end module%3EE5D738028F.cp

//## Module: EBSYifcf%3EE5D738028F; Package specification
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Source file: R:\Embedded\src\EBSY\EBSYifcf.h

#ifndef EBSYifcf_h
#define EBSYifcf_h 1

//## begin module%3EE5D738028F.additionalIncludes preserve=no
//## end module%3EE5D738028F.additionalIncludes

//## begin module%3EE5D738028F.includes preserve=yes
//## end module%3EE5D738028F.includes

// EBSYcons
#include "EBSYcons.h"

class EBPI_DLL_DECL CPIInterfaceConfig;

//## begin module%3EE5D738028F.declarations preserve=no
//## end module%3EE5D738028F.declarations

//## begin module%3EE5D738028F.additionalDeclarations preserve=yes
//## end module%3EE5D738028F.additionalDeclarations


//## begin CSYStateConstitutionConfigInterface%3EE5D24D00D0.preface preserve=yes
//## end CSYStateConstitutionConfigInterface%3EE5D24D00D0.preface

//## Class: CSYStateConstitutionConfigInterface%3EE5D24D00D0
//## Category: EBSY (System Control)%3EDC5B9C004B
//## Subsystem: EBSY (System Control)%3EDC5B3C01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EF9539400B2;CSYStateShuttingDown { -> }
//## Uses: <unnamed>%3F2F750E03AA;CSYInterfaceSettings { -> }
//## Uses: <unnamed>%4111FC6E00F3;CSYSystemImplementation { -> }

class CSYStateConstitutionConfigInterface : public CSYStateConstitution  //## Inherits: <unnamed>%400563FA031C
{
  //## begin CSYStateConstitutionConfigInterface%3EE5D24D00D0.initialDeclarations preserve=yes
  //## end CSYStateConstitutionConfigInterface%3EE5D24D00D0.initialDeclarations

  public:
    //## Constructors (generated)
      CSYStateConstitutionConfigInterface();

    //## Destructor (generated)
      virtual ~CSYStateConstitutionConfigInterface();


    //## Other Operations (specified)
      //## Operation: Create%1055252179
      static void Create ();

      //## Operation: Delete%1055252180
      static void Delete ();

      //## Operation: GetInstance%1055252181
      static CSYStateConstitutionConfigInterface* GetInstance ();

      //## Operation: GetDeviceState%1056436752
      virtual EPIDeviceState GetDeviceState ();

      //## Operation: Do%1056523874
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

      //## Association: EBSY (System Control)::<unnamed>%4097FFAE0315
      //## Role: CSYStateConstitutionConfigInterface::pInterfaceConfig%4097FFAF00F9
      void SetpInterfaceConfig (CPIInterfaceConfig * value);

    // Additional Public Declarations
      //## begin CSYStateConstitutionConfigInterface%3EE5D24D00D0.public preserve=yes
      //## end CSYStateConstitutionConfigInterface%3EE5D24D00D0.public

  protected:
    // Additional Protected Declarations
      //## begin CSYStateConstitutionConfigInterface%3EE5D24D00D0.protected preserve=yes
      //## end CSYStateConstitutionConfigInterface%3EE5D24D00D0.protected

  private:
    //## Constructors (generated)
      CSYStateConstitutionConfigInterface(const CSYStateConstitutionConfigInterface &right);

    //## Assignment Operation (generated)
      const CSYStateConstitutionConfigInterface & operator=(const CSYStateConstitutionConfigInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CSYStateConstitutionConfigInterface &right) const;

      bool operator!=(const CSYStateConstitutionConfigInterface &right) const;

    // Data Members for Associations

      //## Association: EBSY (System Control)::<unnamed>%3EE5D24D00E3
      //## Role: CSYStateConstitutionConfigInterface::pInstance%3EE5D24D00E5
      //## begin CSYStateConstitutionConfigInterface::pInstance%3EE5D24D00E5.role preserve=no  public: static CSYStateConstitutionConfigInterface {1..1 -> 1..1RFHN}
      static CSYStateConstitutionConfigInterface *m_pInstance;
      //## end CSYStateConstitutionConfigInterface::pInstance%3EE5D24D00E5.role

      //## Association: EBSY (System Control)::<unnamed>%4097FFAE0315
      //## begin CSYStateConstitutionConfigInterface::pInterfaceConfig%4097FFAF00F9.role preserve=no  public: CPIInterfaceConfig {1..1 -> 1..1RFHN}
      CPIInterfaceConfig *m_pInterfaceConfig;
      //## end CSYStateConstitutionConfigInterface::pInterfaceConfig%4097FFAF00F9.role

    // Additional Private Declarations
      //## begin CSYStateConstitutionConfigInterface%3EE5D24D00D0.private preserve=yes
      //## end CSYStateConstitutionConfigInterface%3EE5D24D00D0.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSYStateConstitutionConfigInterface%3EE5D24D00D0.implementation preserve=yes
      //## end CSYStateConstitutionConfigInterface%3EE5D24D00D0.implementation

};

//## begin CSYStateConstitutionConfigInterface%3EE5D24D00D0.postscript preserve=yes
//## end CSYStateConstitutionConfigInterface%3EE5D24D00D0.postscript

// Class CSYStateConstitutionConfigInterface 

//## begin module%3EE5D738028F.epilog preserve=yes
//## end module%3EE5D738028F.epilog


#endif
