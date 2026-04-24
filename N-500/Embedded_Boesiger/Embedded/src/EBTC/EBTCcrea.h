//## begin module%3DE5EE04019B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EE04019B.cm

//## begin module%3DE5EE04019B.cp preserve=no
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
//## end module%3DE5EE04019B.cp

//## Module: EBTCcrea%3DE5EE04019B; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCcrea.h

#ifndef EBTCcrea_h
#define EBTCcrea_h 1

//## begin module%3DE5EE04019B.additionalIncludes preserve=no
//## end module%3DE5EE04019B.additionalIncludes

//## begin module%3DE5EE04019B.includes preserve=yes
//## end module%3DE5EE04019B.includes

// EBPIcrea
#include "EBPIcrea.h"
//## begin module%3DE5EE04019B.declarations preserve=no
//## end module%3DE5EE04019B.declarations

//## begin module%3DE5EE04019B.additionalDeclarations preserve=yes
//## end module%3DE5EE04019B.additionalDeclarations


//## begin CTCTemperatureControlCreatorV0%3DEC5681031D.preface preserve=yes
//## end CTCTemperatureControlCreatorV0%3DEC5681031D.preface

//## Class: CTCTemperatureControlCreatorV0%3DEC5681031D
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DEC5B1900BB;CTCTemperatureControlInterface { -> }

class CTCTemperatureControlCreatorV0 : public CPIObjCreatorTemperatureControl  //## Inherits: <unnamed>%3DEC569E034C
{
  //## begin CTCTemperatureControlCreatorV0%3DEC5681031D.initialDeclarations preserve=yes
  //## end CTCTemperatureControlCreatorV0%3DEC5681031D.initialDeclarations

  public:
    //## Constructors (generated)
      CTCTemperatureControlCreatorV0();

    //## Destructor (generated)
      virtual ~CTCTemperatureControlCreatorV0();


    //## Other Operations (specified)
      //## Operation: Create%1038899301
      virtual IPITemperatureControlInterface* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CTCTemperatureControlCreatorV0%3DEC5681031D.public preserve=yes
      //## end CTCTemperatureControlCreatorV0%3DEC5681031D.public

  protected:
    // Additional Protected Declarations
      //## begin CTCTemperatureControlCreatorV0%3DEC5681031D.protected preserve=yes
      //## end CTCTemperatureControlCreatorV0%3DEC5681031D.protected

  private:
    //## Constructors (generated)
      CTCTemperatureControlCreatorV0(const CTCTemperatureControlCreatorV0 &right);

    //## Assignment Operation (generated)
      const CTCTemperatureControlCreatorV0 & operator=(const CTCTemperatureControlCreatorV0 &right);

    //## Equality Operations (generated)
      bool operator==(const CTCTemperatureControlCreatorV0 &right) const;

      bool operator!=(const CTCTemperatureControlCreatorV0 &right) const;

    // Additional Private Declarations
      //## begin CTCTemperatureControlCreatorV0%3DEC5681031D.private preserve=yes
      //## end CTCTemperatureControlCreatorV0%3DEC5681031D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCTemperatureControlCreatorV0%3DEC5681031D.implementation preserve=yes
      //## end CTCTemperatureControlCreatorV0%3DEC5681031D.implementation

};

//## begin CTCTemperatureControlCreatorV0%3DEC5681031D.postscript preserve=yes
//## end CTCTemperatureControlCreatorV0%3DEC5681031D.postscript

//## begin CTCTemperatureControlCreatorV2%489C283403A8.preface preserve=yes
//## end CTCTemperatureControlCreatorV2%489C283403A8.preface

//## Class: CTCTemperatureControlCreatorV2%489C283403A8
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%489C2897004A;CTCTemperatureControlInterface2 { -> }

class CTCTemperatureControlCreatorV2 : public CPIObjCreatorTemperatureControl  //## Inherits: <unnamed>%489C287400D4
{
  //## begin CTCTemperatureControlCreatorV2%489C283403A8.initialDeclarations preserve=yes
  //## end CTCTemperatureControlCreatorV2%489C283403A8.initialDeclarations

  public:
    //## Constructors (generated)
      CTCTemperatureControlCreatorV2();

    //## Destructor (generated)
      virtual ~CTCTemperatureControlCreatorV2();


    //## Other Operations (specified)
      //## Operation: Create%1218193718
      virtual IPITemperatureControlInterface* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CTCTemperatureControlCreatorV2%489C283403A8.public preserve=yes
      //## end CTCTemperatureControlCreatorV2%489C283403A8.public

  protected:
    // Additional Protected Declarations
      //## begin CTCTemperatureControlCreatorV2%489C283403A8.protected preserve=yes
      //## end CTCTemperatureControlCreatorV2%489C283403A8.protected

  private:
    //## Constructors (generated)
      CTCTemperatureControlCreatorV2(const CTCTemperatureControlCreatorV2 &right);

    //## Assignment Operation (generated)
      const CTCTemperatureControlCreatorV2 & operator=(const CTCTemperatureControlCreatorV2 &right);

    //## Equality Operations (generated)
      bool operator==(const CTCTemperatureControlCreatorV2 &right) const;

      bool operator!=(const CTCTemperatureControlCreatorV2 &right) const;

    // Additional Private Declarations
      //## begin CTCTemperatureControlCreatorV2%489C283403A8.private preserve=yes
      //## end CTCTemperatureControlCreatorV2%489C283403A8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCTemperatureControlCreatorV2%489C283403A8.implementation preserve=yes
      //## end CTCTemperatureControlCreatorV2%489C283403A8.implementation

};

//## begin CTCTemperatureControlCreatorV2%489C283403A8.postscript preserve=yes
//## end CTCTemperatureControlCreatorV2%489C283403A8.postscript

// Class CTCTemperatureControlCreatorV0 

// Class CTCTemperatureControlCreatorV2 

//## begin module%3DE5EE04019B.epilog preserve=yes
//## end module%3DE5EE04019B.epilog


#endif
