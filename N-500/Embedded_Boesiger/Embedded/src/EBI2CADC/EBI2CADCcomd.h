//## begin module%3FFC0E0A004E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FFC0E0A004E.cm

//## begin module%3FFC0E0A004E.cp preserve=no
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
//## end module%3FFC0E0A004E.cp

//## Module: EBI2CADCcomd%3FFC0E0A004E; Package specification
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Source file: R:\Embedded\src\EBI2CADC\EBI2CADCcomd.h

#ifndef EBI2CADCcomd_h
#define EBI2CADCcomd_h 1

//## begin module%3FFC0E0A004E.additionalIncludes preserve=no
//## end module%3FFC0E0A004E.additionalIncludes

//## begin module%3FFC0E0A004E.includes preserve=yes
//## end module%3FFC0E0A004E.includes

// EBHIcomd
#include "EBHIcomd.h"

class EBPI_DLL_DECL CPII2CDataStream;

//## begin module%3FFC0E0A004E.declarations preserve=no
//## end module%3FFC0E0A004E.declarations

//## begin module%3FFC0E0A004E.additionalDeclarations preserve=yes
//## end module%3FFC0E0A004E.additionalDeclarations


//## begin CI2CADCMAX1037Command%3FFC0E700261.preface preserve=yes
//## end CI2CADCMAX1037Command%3FFC0E700261.preface

//## Class: CI2CADCMAX1037Command%3FFC0E700261
//## Category: EBI2CADC (I2C ADC)%3F49CFE2030D
//## Subsystem: EBI2CADC (I2C ADC)%3F49CFF0033C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FFC104902BF;XI2CADCExceptionError { -> }
//## Uses: <unnamed>%3FFC104C004E;I2CADC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3FFC104E0222;CHII2CParameter { -> }
//## Uses: <unnamed>%3FFC10500261;IHIInterface { -> }

class CI2CADCMAX1037Command : public CHII2CCommand  //## Inherits: <unnamed>%3FFC0E8C03B9
{
  //## begin CI2CADCMAX1037Command%3FFC0E700261.initialDeclarations preserve=yes
  //## end CI2CADCMAX1037Command%3FFC0E700261.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CI2CADCMAX1037Command%1073465618
      CI2CADCMAX1037Command (BYTE* p_pcI2CStream, int p_nLength, DWORD p_dwI2CBusNumber, DWORD p_dwI2CTransferSpeed);

    //## Destructor (generated)
      virtual ~CI2CADCMAX1037Command();


    //## Other Operations (specified)
      //## Operation: Execute%1073465619
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	-
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute ();

    // Additional Public Declarations
      //## begin CI2CADCMAX1037Command%3FFC0E700261.public preserve=yes
      //## end CI2CADCMAX1037Command%3FFC0E700261.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CADCMAX1037Command%3FFC0E700261.protected preserve=yes
      //## end CI2CADCMAX1037Command%3FFC0E700261.protected

  private:
    //## Constructors (generated)
      CI2CADCMAX1037Command();

      CI2CADCMAX1037Command(const CI2CADCMAX1037Command &right);

    //## Assignment Operation (generated)
      const CI2CADCMAX1037Command & operator=(const CI2CADCMAX1037Command &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CADCMAX1037Command &right) const;

      bool operator!=(const CI2CADCMAX1037Command &right) const;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwI2CBusNumber%3FFD5F5D004E
      const DWORD GetdwI2CBusNumber () const;

      //## Attribute: dwI2CTransferSpeed%3FFD5F5D007D
      const DWORD GetdwI2CTransferSpeed () const;

    // Data Members for Class Attributes

      //## begin CI2CADCMAX1037Command::dwI2CBusNumber%3FFD5F5D004E.attr preserve=no  private: DWORD {U} p_dwI2CBusNumber
      DWORD m_dwI2CBusNumber;
      //## end CI2CADCMAX1037Command::dwI2CBusNumber%3FFD5F5D004E.attr

      //## begin CI2CADCMAX1037Command::dwI2CTransferSpeed%3FFD5F5D007D.attr preserve=no  private: DWORD {U} p_dwI2CTransferSpeed
      DWORD m_dwI2CTransferSpeed;
      //## end CI2CADCMAX1037Command::dwI2CTransferSpeed%3FFD5F5D007D.attr

    // Data Members for Associations

      //## Association: EBI2CADC (I2C ADC)::<unnamed>%3FFC0ECC031C
      //## Role: CI2CADCMAX1037Command::pI2CDataStream%3FFC0ECD0139
      //## begin CI2CADCMAX1037Command::pI2CDataStream%3FFC0ECD0139.role preserve=no  public: CPII2CDataStream {1..1 -> 1..1RFHN}
      CPII2CDataStream *m_pI2CDataStream;
      //## end CI2CADCMAX1037Command::pI2CDataStream%3FFC0ECD0139.role

    // Additional Private Declarations
      //## begin CI2CADCMAX1037Command%3FFC0E700261.private preserve=yes
      //## end CI2CADCMAX1037Command%3FFC0E700261.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CADCMAX1037Command%3FFC0E700261.implementation preserve=yes
      //## end CI2CADCMAX1037Command%3FFC0E700261.implementation

};

//## begin CI2CADCMAX1037Command%3FFC0E700261.postscript preserve=yes
//## end CI2CADCMAX1037Command%3FFC0E700261.postscript

// Class CI2CADCMAX1037Command 

//## begin module%3FFC0E0A004E.epilog preserve=yes
//## end module%3FFC0E0A004E.epilog


#endif
