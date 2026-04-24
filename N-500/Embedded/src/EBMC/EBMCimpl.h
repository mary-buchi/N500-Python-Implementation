//## begin module%3DAAE3BD02E2.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAE3BD02E2.cm

//## begin module%3DAAE3BD02E2.cp preserve=no
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
//## end module%3DAAE3BD02E2.cp

//## Module: EBMCimpl%3DAAE3BD02E2; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCimpl.h

#ifndef EBMCimpl_h
#define EBMCimpl_h 1

//## begin module%3DAAE3BD02E2.additionalIncludes preserve=no
//## end module%3DAAE3BD02E2.additionalIncludes

//## begin module%3DAAE3BD02E2.includes preserve=yes
//## end module%3DAAE3BD02E2.includes

// EBCOimpl
#include "EBCOimpl.h"

class EBMC_DLL_DECL CMCMeasurementChannelInterface;
class CMCCtrlSimulation;

//## begin module%3DAAE3BD02E2.declarations preserve=no
//## end module%3DAAE3BD02E2.declarations

//## begin module%3DAAE3BD02E2.additionalDeclarations preserve=yes
//## end module%3DAAE3BD02E2.additionalDeclarations


//## begin CMCMeasurementChannelImplementation%3DAAE59100EE.preface preserve=yes
//## end CMCMeasurementChannelImplementation%3DAAE59100EE.preface

//## Class: CMCMeasurementChannelImplementation%3DAAE59100EE
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAAEAEB0288;CMCStateMachineEngine { -> }
//## Uses: <unnamed>%3DAAEB7D03D1;CMCMeasurementChannelInterface { -> F}
//## Uses: <unnamed>%3F97851D013B;CPIComponentsState { -> }
//## Uses: <unnamed>%3F97852E009F;MC_IDENTIFIERS { -> }

class CMCMeasurementChannelImplementation : public ICOAsyncImplementation  //## Inherits: <unnamed>%3DAAE5D90330
{
  //## begin CMCMeasurementChannelImplementation%3DAAE59100EE.initialDeclarations preserve=yes
  //## end CMCMeasurementChannelImplementation%3DAAE59100EE.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CMCMeasurementChannelImplementation%1034611448
      CMCMeasurementChannelImplementation (CMCMeasurementChannelInterface* p_pInterface);

    //## Destructor (generated)
      virtual ~CMCMeasurementChannelImplementation();


    //## Other Operations (specified)
      //## Operation: InitInstance%1034611449
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: bHWPresent%3F97846101F7
      bool GetbHWPresent ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBMC (Measurement Channel)::<unnamed>%3F978853018A
      //## Role: CMCMeasurementChannelImplementation::pCtrlSimulation%3F97885303DB
      CMCCtrlSimulation * GetpCtrlSimulation ();

    // Additional Public Declarations
      //## begin CMCMeasurementChannelImplementation%3DAAE59100EE.public preserve=yes
      //## end CMCMeasurementChannelImplementation%3DAAE59100EE.public

  protected:
    // Additional Protected Declarations
      //## begin CMCMeasurementChannelImplementation%3DAAE59100EE.protected preserve=yes
      //## end CMCMeasurementChannelImplementation%3DAAE59100EE.protected

  private:
    //## Constructors (generated)
      CMCMeasurementChannelImplementation();

      CMCMeasurementChannelImplementation(const CMCMeasurementChannelImplementation &right);

    //## Assignment Operation (generated)
      const CMCMeasurementChannelImplementation & operator=(const CMCMeasurementChannelImplementation &right);

    //## Equality Operations (generated)
      bool operator==(const CMCMeasurementChannelImplementation &right) const;

      bool operator!=(const CMCMeasurementChannelImplementation &right) const;

    // Data Members for Class Attributes

      //## begin CMCMeasurementChannelImplementation::bHWPresent%3F97846101F7.attr preserve=no  public: bool {U} false
      bool m_bHWPresent;
      //## end CMCMeasurementChannelImplementation::bHWPresent%3F97846101F7.attr

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3F978853018A
      //## begin CMCMeasurementChannelImplementation::pCtrlSimulation%3F97885303DB.role preserve=no  public: CMCCtrlSimulation {1..1 -> 1..1RFHN}
      CMCCtrlSimulation *m_pCtrlSimulation;
      //## end CMCMeasurementChannelImplementation::pCtrlSimulation%3F97885303DB.role

    // Additional Private Declarations
      //## begin CMCMeasurementChannelImplementation%3DAAE59100EE.private preserve=yes
      //## end CMCMeasurementChannelImplementation%3DAAE59100EE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCMeasurementChannelImplementation%3DAAE59100EE.implementation preserve=yes
      //## end CMCMeasurementChannelImplementation%3DAAE59100EE.implementation

};

//## begin CMCMeasurementChannelImplementation%3DAAE59100EE.postscript preserve=yes
//## end CMCMeasurementChannelImplementation%3DAAE59100EE.postscript

// Class CMCMeasurementChannelImplementation 

//## begin module%3DAAE3BD02E2.epilog preserve=yes
//## end module%3DAAE3BD02E2.epilog


#endif
