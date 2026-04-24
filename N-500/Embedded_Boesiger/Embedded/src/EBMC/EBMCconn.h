//## begin module%3F60193C034B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F60193C034B.cm

//## begin module%3F60193C034B.cp preserve=no
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
//## end module%3F60193C034B.cp

//## Module: EBMCconn%3F60193C034B; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCconn.h

#ifndef EBMCconn_h
#define EBMCconn_h 1

//## begin module%3F60193C034B.additionalIncludes preserve=no
//## end module%3F60193C034B.additionalIncludes

//## begin module%3F60193C034B.includes preserve=yes
//## end module%3F60193C034B.includes

// EBMCstat
#include "EBMCstat.h"
//## begin module%3F60193C034B.declarations preserve=no
//## end module%3F60193C034B.declarations

//## begin module%3F60193C034B.additionalDeclarations preserve=yes
//## end module%3F60193C034B.additionalDeclarations


//## begin CMCStateNotConnected%3F60190A006D.preface preserve=yes
//## end CMCStateNotConnected%3F60190A006D.preface

//## Class: CMCStateNotConnected%3F60190A006D
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F602A320000;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3F602A55032C;CMCStateCreated { -> }
//## Uses: <unnamed>%3F658AA50157;CMCStateInitialized { -> }

class CMCStateNotConnected : public CMCState  //## Inherits: <unnamed>%3F601A6E01F4
{
  //## begin CMCStateNotConnected%3F60190A006D.initialDeclarations preserve=yes
  //## end CMCStateNotConnected%3F60190A006D.initialDeclarations

  public:
    //## Constructors (generated)
      CMCStateNotConnected();

    //## Destructor (generated)
      virtual ~CMCStateNotConnected();


    //## Other Operations (specified)
      //## Operation: GetInstance%1063260195
      static CMCStateNotConnected* GetInstance ();

      //## Operation: Delete%1063260196
      static void Delete ();

      //## Operation: ConnectionEstablished%1063260198
      //	DESCRIPTION
      //	Brings the subsystem down to the state 'MC Initialized'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1063260199
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: Create%1063260204
      static void Create ();

    // Additional Public Declarations
      //## begin CMCStateNotConnected%3F60190A006D.public preserve=yes
      //## end CMCStateNotConnected%3F60190A006D.public

  protected:
    // Additional Protected Declarations
      //## begin CMCStateNotConnected%3F60190A006D.protected preserve=yes
      //## end CMCStateNotConnected%3F60190A006D.protected

  private:
    //## Constructors (generated)
      CMCStateNotConnected(const CMCStateNotConnected &right);

    //## Assignment Operation (generated)
      const CMCStateNotConnected & operator=(const CMCStateNotConnected &right);

    //## Equality Operations (generated)
      bool operator==(const CMCStateNotConnected &right) const;

      bool operator!=(const CMCStateNotConnected &right) const;

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3F60199800DA
      //## Role: CMCStateNotConnected::pInstance%3F60199A03BA
      //## begin CMCStateNotConnected::pInstance%3F60199A03BA.role preserve=no  public: static CMCStateNotConnected {1..1 -> 1..1RFHN}
      static CMCStateNotConnected *m_pInstance;
      //## end CMCStateNotConnected::pInstance%3F60199A03BA.role

    // Additional Private Declarations
      //## begin CMCStateNotConnected%3F60190A006D.private preserve=yes
      //## end CMCStateNotConnected%3F60190A006D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCStateNotConnected%3F60190A006D.implementation preserve=yes
      //## end CMCStateNotConnected%3F60190A006D.implementation

};

//## begin CMCStateNotConnected%3F60190A006D.postscript preserve=yes
//## end CMCStateNotConnected%3F60190A006D.postscript

// Class CMCStateNotConnected 

//## begin module%3F60193C034B.epilog preserve=yes
//## end module%3F60193C034B.epilog


#endif
