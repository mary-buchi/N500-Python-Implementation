//## begin module%3EED769F039F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F039F.cm

//## begin module%3EED769F039F.cp preserve=no
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
//## end module%3EED769F039F.cp

//## Module: EBPCconn%3EED769F039F; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCconn.h

#ifndef EBPCconn_h
#define EBPCconn_h 1

//## begin module%3EED769F039F.additionalIncludes preserve=no
//## end module%3EED769F039F.additionalIncludes

//## begin module%3EED769F039F.includes preserve=yes
//## end module%3EED769F039F.includes

// EBPCstat
#include "EBPCstat.h"
//## begin module%3EED769F039F.declarations preserve=no
//## end module%3EED769F039F.declarations

//## begin module%3EED769F039F.additionalDeclarations preserve=yes
//## end module%3EED769F039F.additionalDeclarations


//## begin CPCStateNotConnected%3EED76CC07A4.preface preserve=yes
//## end CPCStateNotConnected%3EED76CC07A4.preface

//## Class: CPCStateNotConnected%3EED76CC07A4
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EED76CC07A9;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3EED76CC07AC;CPCStateCreated { -> }
//## Uses: <unnamed>%3F8E3A0A0172;CPCStateIdle { -> }
//## Uses: <unnamed>%3F8E3A3802F9;PC_IDENTIFIERS { -> }
//## Uses: <unnamed>%4035C44A01AD;CPCLogic { -> }
//## Uses: <unnamed>%4035C47E0140;CPCPowerControlImplementation { -> }
//## Uses: <unnamed>%468BBA0A00BD;CHIInterface { -> }

class CPCStateNotConnected : public CPCState  //## Inherits: <unnamed>%3EED76CC07A6
{
  //## begin CPCStateNotConnected%3EED76CC07A4.initialDeclarations preserve=yes
  //## end CPCStateNotConnected%3EED76CC07A4.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateNotConnected();

    //## Destructor (generated)
      virtual ~CPCStateNotConnected();


    //## Other Operations (specified)
      //## Operation: Create%1055317642
      static void Create ();

      //## Operation: GetInstance%1055317643
      static CPCStateNotConnected* GetInstance ();

      //## Operation: Delete%1055317644
      static void Delete ();

      //## Operation: Do%1055317645
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      void Do (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1055317655
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionEstablished%1066285475
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPCStateNotConnected%3EED76CC07A4.public preserve=yes
      //## end CPCStateNotConnected%3EED76CC07A4.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateNotConnected%3EED76CC07A4.protected preserve=yes
      //## end CPCStateNotConnected%3EED76CC07A4.protected

  private:
    //## Constructors (generated)
      CPCStateNotConnected(const CPCStateNotConnected &right);

    //## Assignment Operation (generated)
      const CPCStateNotConnected & operator=(const CPCStateNotConnected &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateNotConnected &right) const;

      bool operator!=(const CPCStateNotConnected &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%3EED76CC0923
      //## Role: CPCStateNotConnected::pInstance%3EED76CC0928
      //## begin CPCStateNotConnected::pInstance%3EED76CC0928.role preserve=no  public: static CPCStateNotConnected {1..1 -> 1..1RFHN}
      static CPCStateNotConnected *m_pInstance;
      //## end CPCStateNotConnected::pInstance%3EED76CC0928.role

    // Additional Private Declarations
      //## begin CPCStateNotConnected%3EED76CC07A4.private preserve=yes
      //## end CPCStateNotConnected%3EED76CC07A4.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateNotConnected%3EED76CC07A4.implementation preserve=yes
      //## end CPCStateNotConnected%3EED76CC07A4.implementation

};

//## begin CPCStateNotConnected%3EED76CC07A4.postscript preserve=yes
//## end CPCStateNotConnected%3EED76CC07A4.postscript

//## begin CPCStateNotConnectedNoConfig%410613A80267.preface preserve=yes
//## end CPCStateNotConnectedNoConfig%410613A80267.preface

//## Class: CPCStateNotConnectedNoConfig%410613A80267
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%410614C901AE;CPCStateConfigNotSet { -> }
//## Uses: <unnamed>%410614D30162;CPCStateCreated { -> }

class CPCStateNotConnectedNoConfig : public CPCState  //## Inherits: <unnamed>%410613C002BB
{
  //## begin CPCStateNotConnectedNoConfig%410613A80267.initialDeclarations preserve=yes
  //## end CPCStateNotConnectedNoConfig%410613A80267.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateNotConnectedNoConfig();

    //## Destructor (generated)
      virtual ~CPCStateNotConnectedNoConfig();


    //## Other Operations (specified)
      //## Operation: Create%1090917496
      static void Create ();

      //## Operation: GetInstance%1090917497
      static CPCStateNotConnectedNoConfig* GetInstance ();

      //## Operation: Delete%1090917498
      static void Delete ();

      //## Operation: Do%1090917499
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1090917500
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionEstablished%1090917501
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPCStateNotConnectedNoConfig%410613A80267.public preserve=yes
      //## end CPCStateNotConnectedNoConfig%410613A80267.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateNotConnectedNoConfig%410613A80267.protected preserve=yes
      //## end CPCStateNotConnectedNoConfig%410613A80267.protected

  private:
    //## Constructors (generated)
      CPCStateNotConnectedNoConfig(const CPCStateNotConnectedNoConfig &right);

    //## Assignment Operation (generated)
      const CPCStateNotConnectedNoConfig & operator=(const CPCStateNotConnectedNoConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateNotConnectedNoConfig &right) const;

      bool operator!=(const CPCStateNotConnectedNoConfig &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%4106141C00C9
      //## Role: CPCStateNotConnectedNoConfig::pInstance%4106141D0003
      //## begin CPCStateNotConnectedNoConfig::pInstance%4106141D0003.role preserve=no  public: static CPCStateNotConnectedNoConfig {1..1 -> 1..1RFHN}
      static CPCStateNotConnectedNoConfig *m_pInstance;
      //## end CPCStateNotConnectedNoConfig::pInstance%4106141D0003.role

    // Additional Private Declarations
      //## begin CPCStateNotConnectedNoConfig%410613A80267.private preserve=yes
      //## end CPCStateNotConnectedNoConfig%410613A80267.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateNotConnectedNoConfig%410613A80267.implementation preserve=yes
      //## end CPCStateNotConnectedNoConfig%410613A80267.implementation

};

//## begin CPCStateNotConnectedNoConfig%410613A80267.postscript preserve=yes
//## end CPCStateNotConnectedNoConfig%410613A80267.postscript

// Class CPCStateNotConnected 

// Class CPCStateNotConnectedNoConfig 

//## begin module%3EED769F039F.epilog preserve=yes
//## end module%3EED769F039F.epilog


#endif
