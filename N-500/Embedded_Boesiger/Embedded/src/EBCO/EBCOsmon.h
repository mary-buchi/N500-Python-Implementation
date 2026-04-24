//## begin module%3F708CF80047.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F708CF80047.cm

//## begin module%3F708CF80047.cp preserve=no
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
//## end module%3F708CF80047.cp

//## Module: EBCOsmon%3F708CF80047; Package specification
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Source file: R:\Embedded\Src\EBCO\EBCOsmon.h

#ifndef EBCOsmon_h
#define EBCOsmon_h 1

//## begin module%3F708CF80047.additionalIncludes preserve=no
//## end module%3F708CF80047.additionalIncludes

//## begin module%3F708CF80047.includes preserve=yes
//## end module%3F708CF80047.includes

//## begin module%3F708CF80047.declarations preserve=no
//## end module%3F708CF80047.declarations

//## begin module%3F708CF80047.additionalDeclarations preserve=yes
//## end module%3F708CF80047.additionalDeclarations


//## begin CCOSystemMonitorInterface%3F708CB8023A.preface preserve=yes
//## end CCOSystemMonitorInterface%3F708CB8023A.preface

//## Class: CCOSystemMonitorInterface%3F708CB8023A
//## Category: EBCO (Core Classes)%3B86CD280273
//## Subsystem: EBCO (Core Classes)%3B86CCF602D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBCO_DLL_DECL CCOSystemMonitorInterface 
{
  //## begin CCOSystemMonitorInterface%3F708CB8023A.initialDeclarations preserve=yes
  //## end CCOSystemMonitorInterface%3F708CB8023A.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: AddMessage%1064337359
      virtual void AddMessage (const CString& p_sUnitID, const CString& p_sMessage) = 0;

      //## Operation: FlushQueue%1084342561
      virtual void FlushQueue () = 0;

    //## Get and Set Operations for Associations (generated)

      //## Association: EBCO (Core Classes)::<unnamed>%3F708E5B02C8
      //## Role: CCOSystemMonitorInterface::pMonitor%3F708E5D0092
      static CCOSystemMonitorInterface * GetpMonitor ();

    // Additional Public Declarations
      //## begin CCOSystemMonitorInterface%3F708CB8023A.public preserve=yes
      //## end CCOSystemMonitorInterface%3F708CB8023A.public

  protected:
    // Data Members for Associations

      //## Association: EBCO (Core Classes)::<unnamed>%3F708E5B02C8
      //## begin CCOSystemMonitorInterface::pMonitor%3F708E5D0092.role preserve=no  public: static CCOSystemMonitorInterface {1..1 -> 1..1RFHN}
      static CCOSystemMonitorInterface *m_pMonitor;
      //## end CCOSystemMonitorInterface::pMonitor%3F708E5D0092.role

    // Additional Protected Declarations
      //## begin CCOSystemMonitorInterface%3F708CB8023A.protected preserve=yes
      //## end CCOSystemMonitorInterface%3F708CB8023A.protected

  private:
    // Additional Private Declarations
      //## begin CCOSystemMonitorInterface%3F708CB8023A.private preserve=yes
      //## end CCOSystemMonitorInterface%3F708CB8023A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CCOSystemMonitorInterface%3F708CB8023A.implementation preserve=yes
      //## end CCOSystemMonitorInterface%3F708CB8023A.implementation

};

//## begin CCOSystemMonitorInterface%3F708CB8023A.postscript preserve=yes
//## end CCOSystemMonitorInterface%3F708CB8023A.postscript

// Class CCOSystemMonitorInterface 

//## begin module%3F708CF80047.epilog preserve=yes
//## end module%3F708CF80047.epilog


#endif
