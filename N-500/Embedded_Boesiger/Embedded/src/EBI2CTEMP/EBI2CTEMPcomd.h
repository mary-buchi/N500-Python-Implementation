//## begin module%3FD73D82033C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FD73D82033C.cm

//## begin module%3FD73D82033C.cp preserve=no
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
//## end module%3FD73D82033C.cp

//## Module: EBI2CTEMPcomd%3FD73D82033C; Package specification
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Source file: R:\Embedded\src\EBI2CTEMP\EBI2CTEMPcomd.h

#ifndef EBI2CTEMPcomd_h
#define EBI2CTEMPcomd_h 1

//## begin module%3FD73D82033C.additionalIncludes preserve=no
//## end module%3FD73D82033C.additionalIncludes

//## begin module%3FD73D82033C.includes preserve=yes
//## end module%3FD73D82033C.includes

// EBHIcomd
#include "EBHIcomd.h"

class EBPI_DLL_DECL CPII2CDataStream;

//## begin module%3FD73D82033C.declarations preserve=no
//## end module%3FD73D82033C.declarations

//## begin module%3FD73D82033C.additionalDeclarations preserve=yes
//## end module%3FD73D82033C.additionalDeclarations


//## begin CI2CTempSensor1631ZCommand%3FD73DCC00BB.preface preserve=yes
//## end CI2CTempSensor1631ZCommand%3FD73DCC00BB.preface

//## Class: CI2CTempSensor1631ZCommand%3FD73DCC00BB
//## Category: EBI2CTemp (I2C Temperature Device)%3EE73654004E
//## Subsystem: EBI2CTemp (I2C Temperature Device)%3EE7361D0232
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FD998FF0242;I2CTEMP_IDENTIFIERS { -> }
//## Uses: <unnamed>%3FD9DE4F00EA;CHITReservedSharedMemory { -> }
//## Uses: <unnamed>%3FD9DEA103B9;CHII2CParameter { -> }
//## Uses: <unnamed>%3FD9DEB402FD;IHIInterface { -> }
//## Uses: <unnamed>%3FDD7BB4035B;XI2CTempExceptionError { -> }

class CI2CTempSensor1631ZCommand : public CHII2CCommand  //## Inherits: <unnamed>%3FD73DFA0290
{
  //## begin CI2CTempSensor1631ZCommand%3FD73DCC00BB.initialDeclarations preserve=yes
  //## end CI2CTempSensor1631ZCommand%3FD73DCC00BB.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CI2CTempSensor1631ZCommand%1071063016
      CI2CTempSensor1631ZCommand (BYTE* p_pcI2CStream, int p_nLength, DWORD p_dwI2CBusNumber, DWORD p_dwI2CTransferSpeed);

    //## Destructor (generated)
      virtual ~CI2CTempSensor1631ZCommand();


    //## Other Operations (specified)
      //## Operation: Execute%1071063017
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
      //## begin CI2CTempSensor1631ZCommand%3FD73DCC00BB.public preserve=yes
      //## end CI2CTempSensor1631ZCommand%3FD73DCC00BB.public

  protected:
    // Additional Protected Declarations
      //## begin CI2CTempSensor1631ZCommand%3FD73DCC00BB.protected preserve=yes
      //## end CI2CTempSensor1631ZCommand%3FD73DCC00BB.protected

  private:
    //## Constructors (generated)
      CI2CTempSensor1631ZCommand();

      CI2CTempSensor1631ZCommand(const CI2CTempSensor1631ZCommand &right);

    //## Assignment Operation (generated)
      const CI2CTempSensor1631ZCommand & operator=(const CI2CTempSensor1631ZCommand &right);

    //## Equality Operations (generated)
      bool operator==(const CI2CTempSensor1631ZCommand &right) const;

      bool operator!=(const CI2CTempSensor1631ZCommand &right) const;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwI2CBusNumber%3FFD6125004E
      const DWORD GetdwI2CBusNumber () const;

      //## Attribute: dwI2CTransferSpeed%3FFD6125007D
      const DWORD GetdwI2CTransferSpeed () const;

    // Data Members for Class Attributes

      //## begin CI2CTempSensor1631ZCommand::dwI2CBusNumber%3FFD6125004E.attr preserve=no  private: DWORD {U} p_dwI2CBusNumber
      DWORD m_dwI2CBusNumber;
      //## end CI2CTempSensor1631ZCommand::dwI2CBusNumber%3FFD6125004E.attr

      //## begin CI2CTempSensor1631ZCommand::dwI2CTransferSpeed%3FFD6125007D.attr preserve=no  private: DWORD {U} p_dwI2CTransferSpeed
      DWORD m_dwI2CTransferSpeed;
      //## end CI2CTempSensor1631ZCommand::dwI2CTransferSpeed%3FFD6125007D.attr

    // Data Members for Associations

      //## Association: EBI2CTemp (I2C Temperature Device)::<unnamed>%3FD9828A038A
      //## Role: CI2CTempSensor1631ZCommand::pI2CDataStream%3FD9828B01B6
      //## begin CI2CTempSensor1631ZCommand::pI2CDataStream%3FD9828B01B6.role preserve=no  public: CPII2CDataStream {1..1 -> 1..1RFHN}
      CPII2CDataStream *m_pI2CDataStream;
      //## end CI2CTempSensor1631ZCommand::pI2CDataStream%3FD9828B01B6.role

    // Additional Private Declarations
      //## begin CI2CTempSensor1631ZCommand%3FD73DCC00BB.private preserve=yes
      //## end CI2CTempSensor1631ZCommand%3FD73DCC00BB.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CI2CTempSensor1631ZCommand%3FD73DCC00BB.implementation preserve=yes
      //## end CI2CTempSensor1631ZCommand%3FD73DCC00BB.implementation

};

//## begin CI2CTempSensor1631ZCommand%3FD73DCC00BB.postscript preserve=yes
//## end CI2CTempSensor1631ZCommand%3FD73DCC00BB.postscript

// Class CI2CTempSensor1631ZCommand 

//## begin module%3FD73D82033C.epilog preserve=yes
//## end module%3FD73D82033C.epilog


#endif
