//## begin module%3FBA3851035F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3FBA3851035F.cm

//## begin module%3FBA3851035F.cp preserve=no
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
//## end module%3FBA3851035F.cp

//## Module: EBSTactn%3FBA3851035F; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTactn.h

#ifndef EBSTactn_h
#define EBSTactn_h 1

//## begin module%3FBA3851035F.additionalIncludes preserve=no
//## end module%3FBA3851035F.additionalIncludes

//## begin module%3FBA3851035F.includes preserve=yes
//## end module%3FBA3851035F.includes

// EBCOactn
#include "EBCOactn.h"


//## begin module%3FBA3851035F.declarations preserve=no
//## end module%3FBA3851035F.declarations

//## begin module%3FBA3851035F.additionalDeclarations preserve=yes
//## end module%3FBA3851035F.additionalDeclarations


//## begin CSTActionMove%3FBA381E015C.preface preserve=yes
//## end CSTActionMove%3FBA381E015C.preface

//## Class: CSTActionMove%3FBA381E015C
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FBA38AB00FE;CSTHardwareConnection { -> }
//## Uses: <unnamed>%3FBA39B600FE;CSTStepperMotorImplementation { -> }
//## Uses: <unnamed>%3FBA3B4C02E2;ST_IDENTIFIERS { -> }
//## Uses: <unnamed>%4150702E02D2;CCOSyncObject { -> }
//## Uses: <unnamed>%415070510062;CPIStepperMotorConfig { -> }
//## Uses: <unnamed>%4150707E012D;EHIOpenEventRegistration { -> }
//## Uses: <unnamed>%415070A5038F;IHIInterface { -> }

class CSTActionMove : public CCOAction  //## Inherits: <unnamed>%3FBA382B0302
{
  //## begin CSTActionMove%3FBA381E015C.initialDeclarations preserve=yes
  //## end CSTActionMove%3FBA381E015C.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CSTActionMove%1069168815
      CSTActionMove (ICOStateMachineContext* p_pContext);

    //## Destructor (generated)
      virtual ~CSTActionMove();


    //## Other Operations (specified)
      //## Operation: Done%1095785913
      //	DESCRIPTION
      //	Tells an action that the server signalled completion.
      //	Therefore the sync object can be thrown away.
      //
      //	RETURNS
      //	void
      virtual void Done ();

      //## Operation: Cancel%1095854205
      //	DESCRIPTION
      //	Cancels an action. Resets the current references to
      //	client and server sync objects.
      //
      //	RETURNS
      //	void
      virtual void Cancel ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBST (Stepper Motor)::<unnamed>%3FBA39350033
      //## Role: CSTActionMove::dwSteps%3FBA393502A5
      void SetdwSteps (DWORD value);

      //## Association: EBST (Stepper Motor)::<unnamed>%3FBA3D82010E
      //## Role: CSTActionMove::dwSpeed%3FBA3D830024
      void SetdwSpeed (DWORD value);

    // Additional Public Declarations
      //## begin CSTActionMove%3FBA381E015C.public preserve=yes
      //## end CSTActionMove%3FBA381E015C.public

  protected:

    //## Other Operations (specified)
      //## Operation: ExecuteAction%1069168816
      virtual CCOSyncObject* ExecuteAction ();

    // Additional Protected Declarations
      //## begin CSTActionMove%3FBA381E015C.protected preserve=yes
      //## end CSTActionMove%3FBA381E015C.protected

  private:
    //## Constructors (generated)
      CSTActionMove();

      CSTActionMove(const CSTActionMove &right);

    //## Assignment Operation (generated)
      const CSTActionMove & operator=(const CSTActionMove &right);

    //## Equality Operations (generated)
      bool operator==(const CSTActionMove &right) const;

      bool operator!=(const CSTActionMove &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3FBA39350033
      //## begin CSTActionMove::dwSteps%3FBA393502A5.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwSteps;
      //## end CSTActionMove::dwSteps%3FBA393502A5.role

      //## Association: EBST (Stepper Motor)::<unnamed>%3FBA3D82010E
      //## begin CSTActionMove::dwSpeed%3FBA3D830024.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwSpeed;
      //## end CSTActionMove::dwSpeed%3FBA3D830024.role

    // Additional Private Declarations
      //## begin CSTActionMove%3FBA381E015C.private preserve=yes
      //## end CSTActionMove%3FBA381E015C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTActionMove%3FBA381E015C.implementation preserve=yes
      //## end CSTActionMove%3FBA381E015C.implementation

};

//## begin CSTActionMove%3FBA381E015C.postscript preserve=yes
//## end CSTActionMove%3FBA381E015C.postscript

// Class CSTActionMove 

//## begin module%3FBA3851035F.epilog preserve=yes
//## end module%3FBA3851035F.epilog


#endif
