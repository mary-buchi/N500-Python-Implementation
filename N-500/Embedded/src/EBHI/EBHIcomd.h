//## begin module%3E2299750375.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E2299750375.cm

//## begin module%3E2299750375.cp preserve=no
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
//## end module%3E2299750375.cp

//## Module: EBHIcomd%3E2299750375; Package specification
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIcomd.h

#ifndef EBHIcomd_h
#define EBHIcomd_h 1

//## begin module%3E2299750375.additionalIncludes preserve=no
//## end module%3E2299750375.additionalIncludes

//## begin module%3E2299750375.includes preserve=yes
//## end module%3E2299750375.includes

// EBCOrefc
#include "EBCOrefc.h"
// EBPItype
#include "EBPItype.h"
//## begin module%3E2299750375.declarations preserve=no
//## end module%3E2299750375.declarations

//## begin module%3E2299750375.additionalDeclarations preserve=yes
//## end module%3E2299750375.additionalDeclarations


//## begin CHII2CCommand%3E22999502B9.preface preserve=yes
//## end CHII2CCommand%3E22999502B9.preface

//## Class: CHII2CCommand%3E22999502B9
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class EBHI_DLL_DECL CHII2CCommand : public ICORefCounting  //## Inherits: <unnamed>%3FD824430186
{
  //## begin CHII2CCommand%3E22999502B9.initialDeclarations preserve=yes
  //## end CHII2CCommand%3E22999502B9.initialDeclarations

  public:
    //## Constructors (generated)
      CHII2CCommand();

    //## Destructor (generated)
      virtual ~CHII2CCommand();


    //## Other Operations (specified)
      //## Operation: Execute%1042447557
      //	DESCRIPTION
      //	Executes the current command.
      //
      //	PARAMETERS
      //	-
      //
      //	RETURNS
      //	true, if the command is finished and the clients sync
      //	object may be signalled
      virtual bool Execute () = 0;

      //## Operation: CreateSyncObjects%1042447558
      virtual void CreateSyncObjects ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E229A1C0327
      //## Role: CHII2CCommand::pSyncObj%3E229A1D0134
      CPISyncObjI2CDataStream * GetpSyncObj ();

    // Additional Public Declarations
      //## begin CHII2CCommand%3E22999502B9.public preserve=yes
      //## end CHII2CCommand%3E22999502B9.public

  protected:
    // Data Members for Associations

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E229A1C0327
      //## begin CHII2CCommand::pSyncObj%3E229A1D0134.role preserve=no  public: CPISyncObjI2CDataStream {1..1 -> 1..1RHN}
      CPISyncObjI2CDataStream *m_pSyncObj;
      //## end CHII2CCommand::pSyncObj%3E229A1D0134.role

    // Additional Protected Declarations
      //## begin CHII2CCommand%3E22999502B9.protected preserve=yes
      //## end CHII2CCommand%3E22999502B9.protected

  private:
    //## Constructors (generated)
      CHII2CCommand(const CHII2CCommand &right);

    //## Assignment Operation (generated)
      const CHII2CCommand & operator=(const CHII2CCommand &right);

    //## Equality Operations (generated)
      bool operator==(const CHII2CCommand &right) const;

      bool operator!=(const CHII2CCommand &right) const;

    // Additional Private Declarations
      //## begin CHII2CCommand%3E22999502B9.private preserve=yes
      //## end CHII2CCommand%3E22999502B9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHII2CCommand%3E22999502B9.implementation preserve=yes
      //## end CHII2CCommand%3E22999502B9.implementation

};

//## begin CHII2CCommand%3E22999502B9.postscript preserve=yes
//## end CHII2CCommand%3E22999502B9.postscript

// Class CHII2CCommand 

//## begin module%3E2299750375.epilog preserve=yes
//## end module%3E2299750375.epilog


#endif
