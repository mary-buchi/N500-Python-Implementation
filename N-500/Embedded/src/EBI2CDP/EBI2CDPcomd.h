//## begin module%3FFBC9EB037A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FFBC9EB037A.cm

//## begin module%3FFBC9EB037A.cp preserve=no
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
//## end module%3FFBC9EB037A.cp

//## Module: EBI2CDPcomd%3FFBC9EB037A; Package specification
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Source file: R:\Embedded\src\EBI2CDP\EBI2CDPcomd.h

#ifndef EBI2CDPcomd_h
#define EBI2CDPcomd_h 1

//## begin module%3FFBC9EB037A.additionalIncludes preserve=no
//## end module%3FFBC9EB037A.additionalIncludes

//## begin module%3FFBC9EB037A.includes preserve=yes
//## end module%3FFBC9EB037A.includes

// EBHIcomd
#include "EBHIcomd.h"

class EBPI_DLL_DECL CPII2CDataStream;

//## begin module%3FFBC9EB037A.declarations preserve=no
//## end module%3FFBC9EB037A.declarations

//## begin module%3FFBC9EB037A.additionalDeclarations preserve=yes
//## end module%3FFBC9EB037A.additionalDeclarations


//## begin CI2CDigitalPotiAD5245Command%3FFBC99C0290.preface preserve=yes
//## end CI2CDigitalPotiAD5245Command%3FFBC99C0290.preface

//## Class: CI2CDigitalPotiAD5245Command%3FFBC99C0290
//## Category: EBI2CDP (I2C Digital Potentiometer)%3F4B4CE20177
//## Subsystem: EBI2CDP (I2C Digital Potentiometer)%3F4B4D0A007D
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FFBCB140261;XI2CDigitalPotiExceptionError { -> }
//## Uses: <unnamed>%3FFBCB1603C8;I2CDP_IDENTIFIERS { -> }
//## Uses: <unnamed>%3FFBCB1900EA;CHII2CParameter { -> }
//## Uses: <unnamed>%3FFBCB1B01C5;IHIInterface { -> }

class CI2CDigitalPotiAD5245Command : public CHII2CCommand  //## Inherits: <unnamed>%3FFBCA6201B5
{
  //## begin CI2CDigitalPotiAD5245Command%3FFBC99C0290.initialDeclarations preserve=yes
  //## end CI2CDigitalPotiAD5245Command%3FFBC99C0290.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CI2CDigitalPotiAD5245Command%1073465616
      CI2CDigitalPotiAD5245Command (BYTE* p_pcI2CStream, int p_nLength, DWORD p_dwI2CBusNumber, DWORD p_dwI2CTransferSpeed);

    //## Destructor (generated)
      virtual ~CI2CDigitalPotiAD5245Command();


    //## Other Operations (specified)
      //## Operation: Execute%1073465617
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
      //## begin CI2CDigitalPotiAD5245Command%3FFBC99C0290.public preserve=yes
      //## end CI2CDigitalPotiAD5245Command%3FFBC99C0290.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CDigitalPotiAD5245Command%3FFBC99C0290.protected preserve=yes
      //## end CI2CDigitalPotiAD5245Command%3FFBC99C0290.protected

  private:
    //## Constructors (generated)
      CI2CDigitalPotiAD5245Command();

      CI2CDigitalPotiAD5245Command(const CI2CDigitalPotiAD5245Command &right);

    //## Assignment Operation (generated)
      const CI2CDigitalPotiAD5245Command & operator=(const CI2CDigitalPotiAD5245Command &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CDigitalPotiAD5245Command &right) const;

      bool operator!=(const CI2CDigitalPotiAD5245Command &right) const;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwI2CBusNumber%3FFD60EA0222
      const DWORD GetdwI2CBusNumber () const;

      //## Attribute: dwI2CTransferSpeed%3FFD60EA0242
      const DWORD GetdwI2CTransferSpeed () const;

    // Data Members for Class Attributes

      //## begin CI2CDigitalPotiAD5245Command::dwI2CBusNumber%3FFD60EA0222.attr preserve=no  private: DWORD {U} p_dwI2CBusNumber
      DWORD m_dwI2CBusNumber;
      //## end CI2CDigitalPotiAD5245Command::dwI2CBusNumber%3FFD60EA0222.attr

      //## begin CI2CDigitalPotiAD5245Command::dwI2CTransferSpeed%3FFD60EA0242.attr preserve=no  private: DWORD {U} p_dwI2CTransferSpeed
      DWORD m_dwI2CTransferSpeed;
      //## end CI2CDigitalPotiAD5245Command::dwI2CTransferSpeed%3FFD60EA0242.attr

    // Data Members for Associations

      //## Association: EBI2CDP (I2C Digital Potentiometer)::<unnamed>%3FFBCA8E00AB
      //## Role: CI2CDigitalPotiAD5245Command::pI2CDataStream%3FFBCA8E02B0
      //## begin CI2CDigitalPotiAD5245Command::pI2CDataStream%3FFBCA8E02B0.role preserve=no  public: CPII2CDataStream {1..1 -> 1..1RFHN}
      CPII2CDataStream *m_pI2CDataStream;
      //## end CI2CDigitalPotiAD5245Command::pI2CDataStream%3FFBCA8E02B0.role

    // Additional Private Declarations
      //## begin CI2CDigitalPotiAD5245Command%3FFBC99C0290.private preserve=yes
      //## end CI2CDigitalPotiAD5245Command%3FFBC99C0290.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CDigitalPotiAD5245Command%3FFBC99C0290.implementation preserve=yes
      //## end CI2CDigitalPotiAD5245Command%3FFBC99C0290.implementation

};

//## begin CI2CDigitalPotiAD5245Command%3FFBC99C0290.postscript preserve=yes
//## end CI2CDigitalPotiAD5245Command%3FFBC99C0290.postscript

// Class CI2CDigitalPotiAD5245Command 

//## begin module%3FFBC9EB037A.epilog preserve=yes
//## end module%3FFBC9EB037A.epilog


#endif
