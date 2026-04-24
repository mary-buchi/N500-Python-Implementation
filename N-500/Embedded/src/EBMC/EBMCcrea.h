//## begin module%3DAAD4BE00BF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAD4BE00BF.cm

//## begin module%3DAAD4BE00BF.cp preserve=no
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
//## end module%3DAAD4BE00BF.cp

//## Module: EBMCcrea%3DAAD4BE00BF; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCcrea.h

#ifndef EBMCcrea_h
#define EBMCcrea_h 1

//## begin module%3DAAD4BE00BF.additionalIncludes preserve=no
//## end module%3DAAD4BE00BF.additionalIncludes

//## begin module%3DAAD4BE00BF.includes preserve=yes
//## end module%3DAAD4BE00BF.includes

// EBPIcrea
#include "EBPIcrea.h"

class EBMC_DLL_DECL CMCMeasurementChannelInterface;

//## begin module%3DAAD4BE00BF.declarations preserve=no
//## end module%3DAAD4BE00BF.declarations

//## begin module%3DAAD4BE00BF.additionalDeclarations preserve=yes
//## end module%3DAAD4BE00BF.additionalDeclarations


//## begin CMCMeasurementChannelCreatorV0%3DAAD4A8018B.preface preserve=yes
//## end CMCMeasurementChannelCreatorV0%3DAAD4A8018B.preface

//## Class: CMCMeasurementChannelCreatorV0%3DAAD4A8018B
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAAD5E702D3;CMCMeasurementChannelInterface { -> F}

class CMCMeasurementChannelCreatorV0 : public CPIObjCreatorMeasurementChannel  //## Inherits: <unnamed>%3DAAD4E100DF
{
  //## begin CMCMeasurementChannelCreatorV0%3DAAD4A8018B.initialDeclarations preserve=yes
  //## end CMCMeasurementChannelCreatorV0%3DAAD4A8018B.initialDeclarations

  public:
    //## Constructors (generated)
      CMCMeasurementChannelCreatorV0();

    //## Destructor (generated)
      virtual ~CMCMeasurementChannelCreatorV0();


    //## Other Operations (specified)
      //## Operation: Create%1034575109
      virtual IPIMeasurementChannelInterface* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CMCMeasurementChannelCreatorV0%3DAAD4A8018B.public preserve=yes
      //## end CMCMeasurementChannelCreatorV0%3DAAD4A8018B.public

  protected:
    // Additional Protected Declarations
      //## begin CMCMeasurementChannelCreatorV0%3DAAD4A8018B.protected preserve=yes
      //## end CMCMeasurementChannelCreatorV0%3DAAD4A8018B.protected

  private:
    //## Constructors (generated)
      CMCMeasurementChannelCreatorV0(const CMCMeasurementChannelCreatorV0 &right);

    //## Assignment Operation (generated)
      const CMCMeasurementChannelCreatorV0 & operator=(const CMCMeasurementChannelCreatorV0 &right);

    //## Equality Operations (generated)
      bool operator==(const CMCMeasurementChannelCreatorV0 &right) const;

      bool operator!=(const CMCMeasurementChannelCreatorV0 &right) const;

    // Additional Private Declarations
      //## begin CMCMeasurementChannelCreatorV0%3DAAD4A8018B.private preserve=yes
      //## end CMCMeasurementChannelCreatorV0%3DAAD4A8018B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCMeasurementChannelCreatorV0%3DAAD4A8018B.implementation preserve=yes
      //## end CMCMeasurementChannelCreatorV0%3DAAD4A8018B.implementation

};

//## begin CMCMeasurementChannelCreatorV0%3DAAD4A8018B.postscript preserve=yes
//## end CMCMeasurementChannelCreatorV0%3DAAD4A8018B.postscript

// Class CMCMeasurementChannelCreatorV0 

//## begin module%3DAAD4BE00BF.epilog preserve=yes
//## end module%3DAAD4BE00BF.epilog


#endif
