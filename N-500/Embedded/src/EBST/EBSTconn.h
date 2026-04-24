//## begin module%3EE5C9AF012E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EE5C9AF012E.cm

//## begin module%3EE5C9AF012E.cp preserve=no
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
//## end module%3EE5C9AF012E.cp

//## Module: EBSTconn%3EE5C9AF012E; Package specification
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Source file: R:\Embedded\Src\EBST\EBSTconn.h

#ifndef EBSTconn_h
#define EBSTconn_h 1

//## begin module%3EE5C9AF012E.additionalIncludes preserve=no
//## end module%3EE5C9AF012E.additionalIncludes

//## begin module%3EE5C9AF012E.includes preserve=yes
//## end module%3EE5C9AF012E.includes

// EBSTstat
#include "EBSTstat.h"
//## begin module%3EE5C9AF012E.declarations preserve=no
//## end module%3EE5C9AF012E.declarations

//## begin module%3EE5C9AF012E.additionalDeclarations preserve=yes
//## end module%3EE5C9AF012E.additionalDeclarations


//## begin CSTStateConnectionNotConnected%3EE5C6A900FF.preface preserve=yes
//## end CSTStateConnectionNotConnected%3EE5C6A900FF.preface

//## Class: CSTStateConnectionNotConnected%3EE5C6A900FF
//## Category: EBST (Stepper Motor)%3DA5BC8A00A5
//## Subsystem: EBST (Stepper Motor)%3DA5BC6C0264
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EF05B320128;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3EF154F3036B;CSTStateIdle { -> }
//## Uses: <unnamed>%3F718F1A004E;ST_IDENTIFIERS { -> }
//## Uses: <unnamed>%416259A200D7;CSTHardwareConnection { -> }
//## Uses: <unnamed>%416259C90089;CSTStepperMotorImplementation { -> }
//## Uses: <unnamed>%416259E30192;CSTLimitHandler { -> }

class CSTStateConnectionNotConnected : public CSTState  //## Inherits: <unnamed>%3F6586650133
{
  //## begin CSTStateConnectionNotConnected%3EE5C6A900FF.initialDeclarations preserve=yes
  //## end CSTStateConnectionNotConnected%3EE5C6A900FF.initialDeclarations

  public:
    //## Constructors (generated)
      CSTStateConnectionNotConnected();

    //## Destructor (generated)
      virtual ~CSTStateConnectionNotConnected();


    //## Other Operations (specified)
      //## Operation: Create%1055247437
      static void Create ();

      //## Operation: Delete%1055247438
      static void Delete ();

      //## Operation: GetInstance%1055247439
      static CSTStateConnectionNotConnected* GetInstance ();

      //## Operation: Do%1055247440
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionEstablished%1056003014
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1064494053
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CSTStateConnectionNotConnected%3EE5C6A900FF.public preserve=yes
      //## end CSTStateConnectionNotConnected%3EE5C6A900FF.public

  protected:
    // Additional Protected Declarations
      //## begin CSTStateConnectionNotConnected%3EE5C6A900FF.protected preserve=yes
      //## end CSTStateConnectionNotConnected%3EE5C6A900FF.protected

  private:
    //## Constructors (generated)
      CSTStateConnectionNotConnected(const CSTStateConnectionNotConnected &right);

    //## Assignment Operation (generated)
      const CSTStateConnectionNotConnected & operator=(const CSTStateConnectionNotConnected &right);

    //## Equality Operations (generated)
      bool operator==(const CSTStateConnectionNotConnected &right) const;

      bool operator!=(const CSTStateConnectionNotConnected &right) const;

    // Data Members for Associations

      //## Association: EBST (Stepper Motor)::<unnamed>%3EE5CABF0331
      //## Role: CSTStateConnectionNotConnected::pInstance%3EE5CAC10073
      //## begin CSTStateConnectionNotConnected::pInstance%3EE5CAC10073.role preserve=no  public: static CSTStateConnectionNotConnected {1..1 -> 1..1RFHN}
      static CSTStateConnectionNotConnected *m_pInstance;
      //## end CSTStateConnectionNotConnected::pInstance%3EE5CAC10073.role

    // Additional Private Declarations
      //## begin CSTStateConnectionNotConnected%3EE5C6A900FF.private preserve=yes
      //## end CSTStateConnectionNotConnected%3EE5C6A900FF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSTStateConnectionNotConnected%3EE5C6A900FF.implementation preserve=yes
      //## end CSTStateConnectionNotConnected%3EE5C6A900FF.implementation

};

//## begin CSTStateConnectionNotConnected%3EE5C6A900FF.postscript preserve=yes
//## end CSTStateConnectionNotConnected%3EE5C6A900FF.postscript

// Class CSTStateConnectionNotConnected 

//## begin module%3EE5C9AF012E.epilog preserve=yes
//## end module%3EE5C9AF012E.epilog


#endif
