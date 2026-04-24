//## begin module%3DF5AFA5008C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DF5AFA5008C.cm

//## begin module%3DF5AFA5008C.cp preserve=no
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
//## end module%3DF5AFA5008C.cp

//## Module: EBIOcrea%3DF5AFA5008C; Package specification
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Source file: R:\Embedded\src\EBIO\EBIOcrea.h

#ifndef EBIOcrea_h
#define EBIOcrea_h 1

//## begin module%3DF5AFA5008C.additionalIncludes preserve=no
//## end module%3DF5AFA5008C.additionalIncludes

//## begin module%3DF5AFA5008C.includes preserve=yes
//## end module%3DF5AFA5008C.includes

// EBPIcrea
#include "EBPIcrea.h"
//## begin module%3DF5AFA5008C.declarations preserve=no
//## end module%3DF5AFA5008C.declarations

//## begin module%3DF5AFA5008C.additionalDeclarations preserve=yes
//## end module%3DF5AFA5008C.additionalDeclarations


//## begin CIOOutputAnalogCreatorV0%3DF5B6DF0196.preface preserve=yes
//## end CIOOutputAnalogCreatorV0%3DF5B6DF0196.preface

//## Class: CIOOutputAnalogCreatorV0%3DF5B6DF0196
//## Category: EBIO (Analog- / Digital- In-/Output)%3DF5A45203B9
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF5F1390109;CIOOutputAnalogInterface { -> }

class CIOOutputAnalogCreatorV0 : public CPIObjCreatorOutputAnalog  //## Inherits: <unnamed>%3DF5B702006D
{
  //## begin CIOOutputAnalogCreatorV0%3DF5B6DF0196.initialDeclarations preserve=yes
  //## end CIOOutputAnalogCreatorV0%3DF5B6DF0196.initialDeclarations

  public:
    //## Constructors (generated)
      CIOOutputAnalogCreatorV0();

    //## Destructor (generated)
      virtual ~CIOOutputAnalogCreatorV0();


    //## Other Operations (specified)
      //## Operation: Create%1039513438
      virtual IPIOutputAnalogInterface* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CIOOutputAnalogCreatorV0%3DF5B6DF0196.public preserve=yes
      //## end CIOOutputAnalogCreatorV0%3DF5B6DF0196.public

  protected:
    // Additional Protected Declarations
      //## begin CIOOutputAnalogCreatorV0%3DF5B6DF0196.protected preserve=yes
      //## end CIOOutputAnalogCreatorV0%3DF5B6DF0196.protected

  private:
    //## Constructors (generated)
      CIOOutputAnalogCreatorV0(const CIOOutputAnalogCreatorV0 &right);

    //## Assignment Operation (generated)
      const CIOOutputAnalogCreatorV0 & operator=(const CIOOutputAnalogCreatorV0 &right);

    //## Equality Operations (generated)
      bool operator==(const CIOOutputAnalogCreatorV0 &right) const;

      bool operator!=(const CIOOutputAnalogCreatorV0 &right) const;

    // Additional Private Declarations
      //## begin CIOOutputAnalogCreatorV0%3DF5B6DF0196.private preserve=yes
      //## end CIOOutputAnalogCreatorV0%3DF5B6DF0196.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CIOOutputAnalogCreatorV0%3DF5B6DF0196.implementation preserve=yes
      //## end CIOOutputAnalogCreatorV0%3DF5B6DF0196.implementation

};

//## begin CIOOutputAnalogCreatorV0%3DF5B6DF0196.postscript preserve=yes
//## end CIOOutputAnalogCreatorV0%3DF5B6DF0196.postscript

//## begin CIOSensorAnalogCreatorV0%3DF5BAE10148.preface preserve=yes
//## end CIOSensorAnalogCreatorV0%3DF5BAE10148.preface

//## Class: CIOSensorAnalogCreatorV0%3DF5BAE10148
//## Category: EBIO (Analog- / Digital- In-/Output)%3DF5A45203B9
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF5F14F0232;CIOSensorAnalogInterface { -> }

class CIOSensorAnalogCreatorV0 : public CPIObjCreatorSensorAnalog  //## Inherits: <unnamed>%3DF5BB2C02A0
{
  //## begin CIOSensorAnalogCreatorV0%3DF5BAE10148.initialDeclarations preserve=yes
  //## end CIOSensorAnalogCreatorV0%3DF5BAE10148.initialDeclarations

  public:
    //## Constructors (generated)
      CIOSensorAnalogCreatorV0();

    //## Destructor (generated)
      virtual ~CIOSensorAnalogCreatorV0();


    //## Other Operations (specified)
      //## Operation: Create%1039513440
      virtual IPISensorAnalogInterface* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CIOSensorAnalogCreatorV0%3DF5BAE10148.public preserve=yes
      //## end CIOSensorAnalogCreatorV0%3DF5BAE10148.public

  protected:
    // Additional Protected Declarations
      //## begin CIOSensorAnalogCreatorV0%3DF5BAE10148.protected preserve=yes
      //## end CIOSensorAnalogCreatorV0%3DF5BAE10148.protected

  private:
    //## Constructors (generated)
      CIOSensorAnalogCreatorV0(const CIOSensorAnalogCreatorV0 &right);

    //## Assignment Operation (generated)
      const CIOSensorAnalogCreatorV0 & operator=(const CIOSensorAnalogCreatorV0 &right);

    //## Equality Operations (generated)
      bool operator==(const CIOSensorAnalogCreatorV0 &right) const;

      bool operator!=(const CIOSensorAnalogCreatorV0 &right) const;

    // Additional Private Declarations
      //## begin CIOSensorAnalogCreatorV0%3DF5BAE10148.private preserve=yes
      //## end CIOSensorAnalogCreatorV0%3DF5BAE10148.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CIOSensorAnalogCreatorV0%3DF5BAE10148.implementation preserve=yes
      //## end CIOSensorAnalogCreatorV0%3DF5BAE10148.implementation

};

//## begin CIOSensorAnalogCreatorV0%3DF5BAE10148.postscript preserve=yes
//## end CIOSensorAnalogCreatorV0%3DF5BAE10148.postscript

//## begin CIOSensorDigitalCreatorV0%3DF5BAFE0196.preface preserve=yes
//## end CIOSensorDigitalCreatorV0%3DF5BAFE0196.preface

//## Class: CIOSensorDigitalCreatorV0%3DF5BAFE0196
//## Category: EBIO (Analog- / Digital- In-/Output)%3DF5A45203B9
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF5F2060148;CIOSensorDigitalInterface { -> }

class CIOSensorDigitalCreatorV0 : public CPIObjCreatorSensorDigital  //## Inherits: <unnamed>%3DF5BB2F01A6
{
  //## begin CIOSensorDigitalCreatorV0%3DF5BAFE0196.initialDeclarations preserve=yes
  //## end CIOSensorDigitalCreatorV0%3DF5BAFE0196.initialDeclarations

  public:
    //## Constructors (generated)
      CIOSensorDigitalCreatorV0();

    //## Destructor (generated)
      virtual ~CIOSensorDigitalCreatorV0();


    //## Other Operations (specified)
      //## Operation: Create%1039513442
      virtual IPISensorDigitalInterface* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CIOSensorDigitalCreatorV0%3DF5BAFE0196.public preserve=yes
      //## end CIOSensorDigitalCreatorV0%3DF5BAFE0196.public

  protected:
    // Additional Protected Declarations
      //## begin CIOSensorDigitalCreatorV0%3DF5BAFE0196.protected preserve=yes
      //## end CIOSensorDigitalCreatorV0%3DF5BAFE0196.protected

  private:
    //## Constructors (generated)
      CIOSensorDigitalCreatorV0(const CIOSensorDigitalCreatorV0 &right);

    //## Assignment Operation (generated)
      const CIOSensorDigitalCreatorV0 & operator=(const CIOSensorDigitalCreatorV0 &right);

    //## Equality Operations (generated)
      bool operator==(const CIOSensorDigitalCreatorV0 &right) const;

      bool operator!=(const CIOSensorDigitalCreatorV0 &right) const;

    // Additional Private Declarations
      //## begin CIOSensorDigitalCreatorV0%3DF5BAFE0196.private preserve=yes
      //## end CIOSensorDigitalCreatorV0%3DF5BAFE0196.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CIOSensorDigitalCreatorV0%3DF5BAFE0196.implementation preserve=yes
      //## end CIOSensorDigitalCreatorV0%3DF5BAFE0196.implementation

};

//## begin CIOSensorDigitalCreatorV0%3DF5BAFE0196.postscript preserve=yes
//## end CIOSensorDigitalCreatorV0%3DF5BAFE0196.postscript

//## begin CIOOutputDigitalCreatorV0%3DF5BB14038A.preface preserve=yes
//## end CIOOutputDigitalCreatorV0%3DF5BB14038A.preface

//## Class: CIOOutputDigitalCreatorV0%3DF5BB14038A
//## Category: EBIO (Analog- / Digital- In-/Output)%3DF5A45203B9
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DF5F1F801C5;CIOOutputDigitalInterface { -> }

class CIOOutputDigitalCreatorV0 : public CPIObjCreatorOutputDigital  //## Inherits: <unnamed>%3DF5BB37034C
{
  //## begin CIOOutputDigitalCreatorV0%3DF5BB14038A.initialDeclarations preserve=yes
  //## end CIOOutputDigitalCreatorV0%3DF5BB14038A.initialDeclarations

  public:
    //## Constructors (generated)
      CIOOutputDigitalCreatorV0();

    //## Destructor (generated)
      virtual ~CIOOutputDigitalCreatorV0();


    //## Other Operations (specified)
      //## Operation: Create%1039513441
      virtual IPIOutputDigitalInterface* Create (UINT p_uiID);

    // Additional Public Declarations
      //## begin CIOOutputDigitalCreatorV0%3DF5BB14038A.public preserve=yes
      //## end CIOOutputDigitalCreatorV0%3DF5BB14038A.public

  protected:
    // Additional Protected Declarations
      //## begin CIOOutputDigitalCreatorV0%3DF5BB14038A.protected preserve=yes
      //## end CIOOutputDigitalCreatorV0%3DF5BB14038A.protected

  private:
    //## Constructors (generated)
      CIOOutputDigitalCreatorV0(const CIOOutputDigitalCreatorV0 &right);

    //## Assignment Operation (generated)
      const CIOOutputDigitalCreatorV0 & operator=(const CIOOutputDigitalCreatorV0 &right);

    //## Equality Operations (generated)
      bool operator==(const CIOOutputDigitalCreatorV0 &right) const;

      bool operator!=(const CIOOutputDigitalCreatorV0 &right) const;

    // Additional Private Declarations
      //## begin CIOOutputDigitalCreatorV0%3DF5BB14038A.private preserve=yes
      //## end CIOOutputDigitalCreatorV0%3DF5BB14038A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CIOOutputDigitalCreatorV0%3DF5BB14038A.implementation preserve=yes
      //## end CIOOutputDigitalCreatorV0%3DF5BB14038A.implementation

};

//## begin CIOOutputDigitalCreatorV0%3DF5BB14038A.postscript preserve=yes
//## end CIOOutputDigitalCreatorV0%3DF5BB14038A.postscript

// Class CIOOutputAnalogCreatorV0 

// Class CIOSensorAnalogCreatorV0 

// Class CIOSensorDigitalCreatorV0 

// Class CIOOutputDigitalCreatorV0 

//## begin module%3DF5AFA5008C.epilog preserve=yes
//## end module%3DF5AFA5008C.epilog


#endif
