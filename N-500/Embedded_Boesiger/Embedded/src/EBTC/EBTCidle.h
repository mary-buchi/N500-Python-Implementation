//## begin module%3DE5EE27017B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EE27017B.cm

//## begin module%3DE5EE27017B.cp preserve=no
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
//## end module%3DE5EE27017B.cp

//## Module: EBTCidle%3DE5EE27017B; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCidle.h

#ifndef EBTCidle_h
#define EBTCidle_h 1

//## begin module%3DE5EE27017B.additionalIncludes preserve=no
//## end module%3DE5EE27017B.additionalIncludes

//## begin module%3DE5EE27017B.includes preserve=yes
//## end module%3DE5EE27017B.includes

// EBTCstat
#include "EBTCstat.h"
//## begin module%3DE5EE27017B.declarations preserve=no
//## end module%3DE5EE27017B.declarations

//## begin module%3DE5EE27017B.additionalDeclarations preserve=yes
//## end module%3DE5EE27017B.additionalDeclarations


//## begin CTCStateCreated%3DEC6EBA03DB.preface preserve=yes
//## end CTCStateCreated%3DEC6EBA03DB.preface

//## Class: CTCStateCreated%3DEC6EBA03DB
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E43D21C00EA;CTCStateConfigNotSet { -> }
//## Uses: <unnamed>%3E43D27401F4;ICOStateMachineContext { -> }

class CTCStateCreated : public CTCState  //## Inherits: <unnamed>%3E410D790259
{
  //## begin CTCStateCreated%3DEC6EBA03DB.initialDeclarations preserve=yes
  //## end CTCStateCreated%3DEC6EBA03DB.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateCreated();

    //## Destructor (generated)
      virtual ~CTCStateCreated();


    //## Other Operations (specified)
      //## Operation: Create%1038899331
      static void Create ();

      //## Operation: Delete%1044522140
      static void Delete ();

      //## Operation: GetInstance%1038899333
      static CTCStateCreated* GetInstance ();

      //## Operation: Startup%1044629618
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

      //## Operation: ConnectionEstablished%1063223345
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionEstablished (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1063223346
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
      //## begin CTCStateCreated%3DEC6EBA03DB.public preserve=yes
      //## end CTCStateCreated%3DEC6EBA03DB.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateCreated%3DEC6EBA03DB.protected preserve=yes
      //## end CTCStateCreated%3DEC6EBA03DB.protected

  private:
    //## Constructors (generated)
      CTCStateCreated(const CTCStateCreated &right);

    //## Assignment Operation (generated)
      const CTCStateCreated & operator=(const CTCStateCreated &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateCreated &right) const;

      bool operator!=(const CTCStateCreated &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3DEC6F230216
      //## Role: CTCStateCreated::pInstance%3DEC6F2901AA
      //## begin CTCStateCreated::pInstance%3DEC6F2901AA.role preserve=no  public: static CTCStateCreated {1..1 -> 1..1RFHN}
      static CTCStateCreated *m_pInstance;
      //## end CTCStateCreated::pInstance%3DEC6F2901AA.role

    // Additional Private Declarations
      //## begin CTCStateCreated%3DEC6EBA03DB.private preserve=yes
      //## end CTCStateCreated%3DEC6EBA03DB.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateCreated%3DEC6EBA03DB.implementation preserve=yes
      //## end CTCStateCreated%3DEC6EBA03DB.implementation

};

//## begin CTCStateCreated%3DEC6EBA03DB.postscript preserve=yes
//## end CTCStateCreated%3DEC6EBA03DB.postscript

// Class CTCStateCreated 

//## begin module%3DE5EE27017B.epilog preserve=yes
//## end module%3DE5EE27017B.epilog


#endif
