//## begin module%3E6E06A8034B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E6E06A8034B.cm

//## begin module%3E6E06A8034B.cp preserve=no
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
//## end module%3E6E06A8034B.cp

//## Module: EBMCacti%3E6E06A8034B; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCacti.h

#ifndef EBMCacti_h
#define EBMCacti_h 1

//## begin module%3E6E06A8034B.additionalIncludes preserve=no
//## end module%3E6E06A8034B.additionalIncludes

//## begin module%3E6E06A8034B.includes preserve=yes
//## end module%3E6E06A8034B.includes

// EBCOactn
#include "EBCOactn.h"
//## begin module%3E6E06A8034B.declarations preserve=no
//## end module%3E6E06A8034B.declarations

//## begin module%3E6E06A8034B.additionalDeclarations preserve=yes
//## end module%3E6E06A8034B.additionalDeclarations


//## begin CMCActionGetDataPackage%3E6E068801F4.preface preserve=yes
//## end CMCActionGetDataPackage%3E6E068801F4.preface

//## Class: CMCActionGetDataPackage%3E6E068801F4
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E6E06D201F4;IHIInterface { -> }
//## Uses: <unnamed>%3FFAB432006D;MC_IDENTIFIERS { -> }
//## Uses: <unnamed>%4063F6B5036B;XHIExceptionError { -> }

class CMCActionGetDataPackage : public CCOAction  //## Inherits: <unnamed>%3E6E06C300DA
{
  //## begin CMCActionGetDataPackage%3E6E068801F4.initialDeclarations preserve=yes
  //## end CMCActionGetDataPackage%3E6E068801F4.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CMCActionGetDataPackage%1047390945
      CMCActionGetDataPackage (const UINT p_uiID, ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CMCActionGetDataPackage();


    //## Other Operations (specified)
      //## Operation: Done%1047390947
      //	DESCRIPTION
      //	Tells an action that the server signalled completion.
      //	Therefore the sync object can be thrown away.
      //
      //	RETURNS
      //	void
      virtual void Done ();

    // Additional Public Declarations
      //## begin CMCActionGetDataPackage%3E6E068801F4.public preserve=yes
      //## end CMCActionGetDataPackage%3E6E068801F4.public

  protected:

    //## Other Operations (specified)
      //## Operation: ExecuteAction%1047390946
      virtual CCOSyncObject* ExecuteAction ();

    // Additional Protected Declarations
      //## begin CMCActionGetDataPackage%3E6E068801F4.protected preserve=yes
      //## end CMCActionGetDataPackage%3E6E068801F4.protected

  private:
    //## Constructors (generated)
      CMCActionGetDataPackage();

      CMCActionGetDataPackage(const CMCActionGetDataPackage &right);

    //## Assignment Operation (generated)
      const CMCActionGetDataPackage & operator=(const CMCActionGetDataPackage &right);

    //## Equality Operations (generated)
      bool operator==(const CMCActionGetDataPackage &right) const;

      bool operator!=(const CMCActionGetDataPackage &right) const;

    // Additional Private Declarations
      //## begin CMCActionGetDataPackage%3E6E068801F4.private preserve=yes
      //## end CMCActionGetDataPackage%3E6E068801F4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCActionGetDataPackage%3E6E068801F4.implementation preserve=yes
      //## end CMCActionGetDataPackage%3E6E068801F4.implementation

};

//## begin CMCActionGetDataPackage%3E6E068801F4.postscript preserve=yes
//## end CMCActionGetDataPackage%3E6E068801F4.postscript

// Class CMCActionGetDataPackage 

//## begin module%3E6E06A8034B.epilog preserve=yes
//## end module%3E6E06A8034B.epilog


#endif
