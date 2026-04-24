//## begin module%3F6017C6003E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F6017C6003E.cm

//## begin module%3F6017C6003E.cp preserve=no
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
//## end module%3F6017C6003E.cp

//## Module: EBWCconn%3F6017C6003E; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCconn.h

#ifndef EBWCconn_h
#define EBWCconn_h 1

//## begin module%3F6017C6003E.additionalIncludes preserve=no
//## end module%3F6017C6003E.additionalIncludes

//## begin module%3F6017C6003E.includes preserve=yes
//## end module%3F6017C6003E.includes

// EBWCstat
#include "EBWCstat.h"
//## begin module%3F6017C6003E.declarations preserve=no
//## end module%3F6017C6003E.declarations

//## begin module%3F6017C6003E.additionalDeclarations preserve=yes
//## end module%3F6017C6003E.additionalDeclarations


//## begin CWCStateNotConnected%3F6017910242.preface preserve=yes
//## end CWCStateNotConnected%3F6017910242.preface

//## Class: CWCStateNotConnected%3F6017910242
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F6029050213;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3F60291801F4;CWCStateCreated { -> }
//## Uses: <unnamed>%3F65B5B402EE;CWCStateInitializing { -> }
//## Uses: <unnamed>%3F65B62401D4;WC_IDENTIFIERS { -> }

class CWCStateNotConnected : public CWCState  //## Inherits: <unnamed>%3F6017A800FA
{
  //## begin CWCStateNotConnected%3F6017910242.initialDeclarations preserve=yes
  //## end CWCStateNotConnected%3F6017910242.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateNotConnected();

    //## Destructor (generated)
      virtual ~CWCStateNotConnected();


    //## Other Operations (specified)
      //## Operation: Create%1063260189
      static void Create ();

      //## Operation: GetInstance%1063260190
      static CWCStateNotConnected* GetInstance ();

      //## Operation: Delete%1063260191
      static void Delete ();

      //## Operation: ConnectionEstablished%1063260193
      //	DESCRIPTION
      //	Brings the subsystem down to the state 'Intializing'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1063260194
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
      //## begin CWCStateNotConnected%3F6017910242.public preserve=yes
      //## end CWCStateNotConnected%3F6017910242.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateNotConnected%3F6017910242.protected preserve=yes
      //## end CWCStateNotConnected%3F6017910242.protected

  private:
    //## Constructors (generated)
      CWCStateNotConnected(const CWCStateNotConnected &right);

    //## Assignment Operation (generated)
      const CWCStateNotConnected & operator=(const CWCStateNotConnected &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateNotConnected &right) const;

      bool operator!=(const CWCStateNotConnected &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3F601831034B
      //## Role: CWCStateNotConnected::pInstance%3F6018350187
      //## begin CWCStateNotConnected::pInstance%3F6018350187.role preserve=no  public: static CWCStateNotConnected {1..1 -> 1..1RFHN}
      static CWCStateNotConnected *m_pInstance;
      //## end CWCStateNotConnected::pInstance%3F6018350187.role

    // Additional Private Declarations
      //## begin CWCStateNotConnected%3F6017910242.private preserve=yes
      //## end CWCStateNotConnected%3F6017910242.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateNotConnected%3F6017910242.implementation preserve=yes
      //## end CWCStateNotConnected%3F6017910242.implementation

};

//## begin CWCStateNotConnected%3F6017910242.postscript preserve=yes
//## end CWCStateNotConnected%3F6017910242.postscript

//## begin CWCStateNotConnectedDuringConfig%3FCB31E80232.preface preserve=yes
//## end CWCStateNotConnectedDuringConfig%3FCB31E80232.preface

//## Class: CWCStateNotConnectedDuringConfig%3FCB31E80232
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3FCB34680186;CWCStateConfigNotAssign { -> }

class CWCStateNotConnectedDuringConfig : public CWCState  //## Inherits: <unnamed>%3FCB331A009C
{
  //## begin CWCStateNotConnectedDuringConfig%3FCB31E80232.initialDeclarations preserve=yes
  //## end CWCStateNotConnectedDuringConfig%3FCB31E80232.initialDeclarations

  public:
    //## Constructors (generated)
      CWCStateNotConnectedDuringConfig();

    //## Destructor (generated)
      virtual ~CWCStateNotConnectedDuringConfig();


    //## Other Operations (specified)
      //## Operation: Create%1070263829
      static void Create ();

      //## Operation: GetInstance%1070263830
      static CWCStateNotConnectedDuringConfig* GetInstance ();

      //## Operation: Delete%1070263831
      static void Delete ();

      //## Operation: ConnectionEstablished%1070263832
      //	DESCRIPTION
      //	Brings the subsystem down to the state 'Intializing'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1070263833
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
      //## begin CWCStateNotConnectedDuringConfig%3FCB31E80232.public preserve=yes
      //## end CWCStateNotConnectedDuringConfig%3FCB31E80232.public

  protected:
    // Additional Protected Declarations
      //## begin CWCStateNotConnectedDuringConfig%3FCB31E80232.protected preserve=yes
      //## end CWCStateNotConnectedDuringConfig%3FCB31E80232.protected

  private:
    //## Constructors (generated)
      CWCStateNotConnectedDuringConfig(const CWCStateNotConnectedDuringConfig &right);

    //## Assignment Operation (generated)
      const CWCStateNotConnectedDuringConfig & operator=(const CWCStateNotConnectedDuringConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CWCStateNotConnectedDuringConfig &right) const;

      bool operator!=(const CWCStateNotConnectedDuringConfig &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3FCB331E03C8
      //## Role: CWCStateNotConnectedDuringConfig::pInstance%3FCB33210233
      //## begin CWCStateNotConnectedDuringConfig::pInstance%3FCB33210233.role preserve=no  public: static CWCStateNotConnectedDuringConfig {1..1 -> 1..1RFHN}
      static CWCStateNotConnectedDuringConfig *m_pInstance;
      //## end CWCStateNotConnectedDuringConfig::pInstance%3FCB33210233.role

    // Additional Private Declarations
      //## begin CWCStateNotConnectedDuringConfig%3FCB31E80232.private preserve=yes
      //## end CWCStateNotConnectedDuringConfig%3FCB31E80232.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCStateNotConnectedDuringConfig%3FCB31E80232.implementation preserve=yes
      //## end CWCStateNotConnectedDuringConfig%3FCB31E80232.implementation

};

//## begin CWCStateNotConnectedDuringConfig%3FCB31E80232.postscript preserve=yes
//## end CWCStateNotConnectedDuringConfig%3FCB31E80232.postscript

// Class CWCStateNotConnected 

// Class CWCStateNotConnectedDuringConfig 

//## begin module%3F6017C6003E.epilog preserve=yes
//## end module%3F6017C6003E.epilog


#endif
