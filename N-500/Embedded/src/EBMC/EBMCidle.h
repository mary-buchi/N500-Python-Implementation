//## begin module%3DAAE824018B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAE824018B.cm

//## begin module%3DAAE824018B.cp preserve=no
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
//## end module%3DAAE824018B.cp

//## Module: EBMCidle%3DAAE824018B; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCidle.h

#ifndef EBMCidle_h
#define EBMCidle_h 1

//## begin module%3DAAE824018B.additionalIncludes preserve=no
//## end module%3DAAE824018B.additionalIncludes

//## begin module%3DAAE824018B.includes preserve=yes
//## end module%3DAAE824018B.includes

// EBMCstat
#include "EBMCstat.h"
//## begin module%3DAAE824018B.declarations preserve=no
//## end module%3DAAE824018B.declarations

//## begin module%3DAAE824018B.additionalDeclarations preserve=yes
//## end module%3DAAE824018B.additionalDeclarations


//## begin CMCStateCreated%3DAAE83A01D9.preface preserve=yes
//## end CMCStateCreated%3DAAE83A01D9.preface

//## Class: CMCStateCreated%3DAAE83A01D9
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAAE92D0052;CMCCommandGetDataPackage { -> }
//## Uses: <unnamed>%3DAE5B37033A;CPIMeasurementChannelDataPackage { -> }
//## Uses: <unnamed>%3DF83EB001FD;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3E6DE4BD000F;CMCStateProfileNotAssign { -> }

class CMCStateCreated : public CMCState  //## Inherits: <unnamed>%3DAAE84102E2
{
  //## begin CMCStateCreated%3DAAE83A01D9.initialDeclarations preserve=yes
  //## end CMCStateCreated%3DAAE83A01D9.initialDeclarations

  public:
    //## Constructors (generated)
      CMCStateCreated();

    //## Destructor (generated)
      virtual ~CMCStateCreated();


    //## Other Operations (specified)
      //## Operation: Delete%1034575115
      static void Delete ();

      //## Operation: Create%1034575114
      static void Create ();

      //## Operation: GetInstance%1034575116
      static CMCStateCreated* GetInstance ();

      //## Operation: Startup%1034922745
      //	DESCRIPTION
      //	Brings the subsystem up to the state 'ConfigProcessModel
      //	Setup'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Startup (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionEstablished%1063223349
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1063223350
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CMCStateCreated%3DAAE83A01D9.public preserve=yes
      //## end CMCStateCreated%3DAAE83A01D9.public

  protected:
    // Additional Protected Declarations
      //## begin CMCStateCreated%3DAAE83A01D9.protected preserve=yes
      //## end CMCStateCreated%3DAAE83A01D9.protected

  private:
    //## Constructors (generated)
      CMCStateCreated(const CMCStateCreated &right);

    //## Assignment Operation (generated)
      const CMCStateCreated & operator=(const CMCStateCreated &right);

    //## Equality Operations (generated)
      bool operator==(const CMCStateCreated &right) const;

      bool operator!=(const CMCStateCreated &right) const;

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3DAAE8500311
      //## Role: CMCStateCreated::pInstance%3DAAE85103AE
      //## begin CMCStateCreated::pInstance%3DAAE85103AE.role preserve=no  public: static CMCStateCreated {1..1 -> 1..1RFHN}
      static CMCStateCreated *m_pInstance;
      //## end CMCStateCreated::pInstance%3DAAE85103AE.role

    // Additional Private Declarations
      //## begin CMCStateCreated%3DAAE83A01D9.private preserve=yes
      //## end CMCStateCreated%3DAAE83A01D9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCStateCreated%3DAAE83A01D9.implementation preserve=yes
      //## end CMCStateCreated%3DAAE83A01D9.implementation

};

//## begin CMCStateCreated%3DAAE83A01D9.postscript preserve=yes
//## end CMCStateCreated%3DAAE83A01D9.postscript

// Class CMCStateCreated 

//## begin module%3DAAE824018B.epilog preserve=yes
//## end module%3DAAE824018B.epilog


#endif
