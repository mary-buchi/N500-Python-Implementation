//## begin module%3FDD8925031C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FDD8925031C.cm

//## begin module%3FDD8925031C.cp preserve=no
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
//## end module%3FDD8925031C.cp

//## Module: EBI2CEPROMcomd%3FDD8925031C; Package specification
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Source file: R:\Embedded\src\EBI2CEPROM\EBI2CEPROMcomd.h

#ifndef EBI2CEPROMcomd_h
#define EBI2CEPROMcomd_h 1

//## begin module%3FDD8925031C.additionalIncludes preserve=no
//## end module%3FDD8925031C.additionalIncludes

//## begin module%3FDD8925031C.includes preserve=yes
//## end module%3FDD8925031C.includes

// EBHIcomd
#include "EBHIcomd.h"

class EBPI_DLL_DECL CPII2CDataStream;

//## begin module%3FDD8925031C.declarations preserve=no
//## end module%3FDD8925031C.declarations

//## begin module%3FDD8925031C.additionalDeclarations preserve=yes
//## end module%3FDD8925031C.additionalDeclarations


//## begin CI2CEprom24LC515Command%3FDD8FA5000F.preface preserve=yes
//## end CI2CEprom24LC515Command%3FDD8FA5000F.preface

//## Class: CI2CEprom24LC515Command%3FDD8FA5000F
//## Category: EBI2CEprom (I2C Eprom Device)%3EE73672030D
//## Subsystem: EBI2CEprom (I2C Eprom Device)%3EE7363600CB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FDDB21200CB;XI2CEpromExceptionError { -> }
//## Uses: <unnamed>%3FDDB2140109;I2CEPROM_IDENTIFIERS { -> }
//## Uses: <unnamed>%3FDDB216029F;CHII2CParameter { -> }
//## Uses: <unnamed>%3FDDB21A032C;CHITReservedSharedMemory { -> }
//## Uses: <unnamed>%3FDDB21D0186;IHIInterface { -> }
//## Uses: <unnamed>%3FFE575603B9;CPIComponentsState { -> }

class CI2CEprom24LC515Command : public CHII2CCommand  //## Inherits: <unnamed>%3FDD8FF803D8
{
  //## begin CI2CEprom24LC515Command%3FDD8FA5000F.initialDeclarations preserve=yes
  //## end CI2CEprom24LC515Command%3FDD8FA5000F.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CI2CEprom24LC515Command%1071483522
      CI2CEprom24LC515Command (BYTE* p_pcI2CStream, int p_nLength, DWORD p_dwI2CBusNumber, DWORD p_dwI2CTransferSpeed);

    //## Destructor (generated)
      virtual ~CI2CEprom24LC515Command();


    //## Other Operations (specified)
      //## Operation: Execute%1071483523
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
      //## begin CI2CEprom24LC515Command%3FDD8FA5000F.public preserve=yes
      //## end CI2CEprom24LC515Command%3FDD8FA5000F.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CEprom24LC515Command%3FDD8FA5000F.protected preserve=yes
      //## end CI2CEprom24LC515Command%3FDD8FA5000F.protected

  private:
    //## Constructors (generated)
      CI2CEprom24LC515Command();

      CI2CEprom24LC515Command(const CI2CEprom24LC515Command &right);

    //## Assignment Operation (generated)
      const CI2CEprom24LC515Command & operator=(const CI2CEprom24LC515Command &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CEprom24LC515Command &right) const;

      bool operator!=(const CI2CEprom24LC515Command &right) const;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwI2CBusNumber%3FFD6127038A
      const DWORD GetdwI2CBusNumber () const;

      //## Attribute: dwI2CTransferSpeed%3FFD612703A9
      const DWORD GetdwI2CTransferSpeed () const;

    // Data Members for Class Attributes

      //## begin CI2CEprom24LC515Command::dwI2CBusNumber%3FFD6127038A.attr preserve=no  private: DWORD {U} p_dwI2CBusNumber
      DWORD m_dwI2CBusNumber;
      //## end CI2CEprom24LC515Command::dwI2CBusNumber%3FFD6127038A.attr

      //## begin CI2CEprom24LC515Command::dwI2CTransferSpeed%3FFD612703A9.attr preserve=no  private: DWORD {U} p_dwI2CTransferSpeed
      DWORD m_dwI2CTransferSpeed;
      //## end CI2CEprom24LC515Command::dwI2CTransferSpeed%3FFD612703A9.attr

    // Data Members for Associations

      //## Association: EBI2CEprom (I2C Eprom Device)::<unnamed>%3FDDAECC034B
      //## Role: CI2CEprom24LC515Command::pI2CDataStream%3FDDAECD0178
      //## begin CI2CEprom24LC515Command::pI2CDataStream%3FDDAECD0178.role preserve=no  public: CPII2CDataStream {1..1 -> 1..1RFHN}
      CPII2CDataStream *m_pI2CDataStream;
      //## end CI2CEprom24LC515Command::pI2CDataStream%3FDDAECD0178.role

    // Additional Private Declarations
      //## begin CI2CEprom24LC515Command%3FDD8FA5000F.private preserve=yes
      //## end CI2CEprom24LC515Command%3FDD8FA5000F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CEprom24LC515Command%3FDD8FA5000F.implementation preserve=yes
      //## end CI2CEprom24LC515Command%3FDD8FA5000F.implementation

};

//## begin CI2CEprom24LC515Command%3FDD8FA5000F.postscript preserve=yes
//## end CI2CEprom24LC515Command%3FDD8FA5000F.postscript

// Class CI2CEprom24LC515Command 

//## begin module%3FDD8925031C.epilog preserve=yes
//## end module%3FDD8925031C.epilog


#endif
