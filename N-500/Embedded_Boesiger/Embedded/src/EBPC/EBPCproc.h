//## begin module%3EED769F038A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F038A.cm

//## begin module%3EED769F038A.cp preserve=no
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
//## end module%3EED769F038A.cp

//## Module: EBPCproc%3EED769F038A; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCproc.h

#ifndef EBPCproc_h
#define EBPCproc_h 1

//## begin module%3EED769F038A.additionalIncludes preserve=no
//## end module%3EED769F038A.additionalIncludes

//## begin module%3EED769F038A.includes preserve=yes
//## end module%3EED769F038A.includes

// EBPCstat
#include "EBPCstat.h"
//## begin module%3EED769F038A.declarations preserve=no
//## end module%3EED769F038A.declarations

//## begin module%3EED769F038A.additionalDeclarations preserve=yes
//## end module%3EED769F038A.additionalDeclarations


//## begin CPCStateProcess%4033805B0086.preface preserve=yes
//## end CPCStateProcess%4033805B0086.preface

//## Class: CPCStateProcess%4033805B0086
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%4688F7630363;CPCStateCreated { -> }

class CPCStateProcess : public CPCState  //## Inherits: <unnamed>%403380B303E1
{
  //## begin CPCStateProcess%4033805B0086.initialDeclarations preserve=yes
  //## end CPCStateProcess%4033805B0086.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateProcess();

    //## Destructor (generated)
      virtual ~CPCStateProcess();


    //## Other Operations (specified)
      //## Operation: Stop%1077117394
      virtual void Stop (ICOStateMachineContext* p_pContext);

      //## Operation: CleanupInitialize%1077117395
      //	DESCRIPTION
      //	Recovers from a 'Initialize Cleanup' exception. State
      //	machine should be broght to the 'ConfigReady' state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void CleanupInitialize (ICOStateMachineContext* p_pContext);

      //## Operation: ConnectionLost%1077117396
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: Shutdown%1183379134
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
      //## begin CPCStateProcess%4033805B0086.public preserve=yes
      //## end CPCStateProcess%4033805B0086.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateProcess%4033805B0086.protected preserve=yes
      //## end CPCStateProcess%4033805B0086.protected

  private:
    //## Constructors (generated)
      CPCStateProcess(const CPCStateProcess &right);

    //## Assignment Operation (generated)
      const CPCStateProcess & operator=(const CPCStateProcess &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateProcess &right) const;

      bool operator!=(const CPCStateProcess &right) const;

    // Additional Private Declarations
      //## begin CPCStateProcess%4033805B0086.private preserve=yes
      //## end CPCStateProcess%4033805B0086.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateProcess%4033805B0086.implementation preserve=yes
      //## end CPCStateProcess%4033805B0086.implementation

};

//## begin CPCStateProcess%4033805B0086.postscript preserve=yes
//## end CPCStateProcess%4033805B0086.postscript

//## begin CPCStateProcessControling%3EED76CC0714.preface preserve=yes
//## end CPCStateProcessControling%3EED76CC0714.preface

//## Class: CPCStateProcessControling%3EED76CC0714
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%4027BC7101BC;CPCStateIdleStandBy { -> }
//## Uses: <unnamed>%402888AB0229;CPCStateNotConnected { -> }
//## Uses: <unnamed>%4028898601DB;ICOStateMachineContext { -> }
//## Uses: <unnamed>%40288C1F03A0;CPIPowerControlProfile { -> }
//## Uses: <unnamed>%40288C3C0229;CPCPowerControlImplementation { -> }
//## Uses: <unnamed>%40288C470100;CPCLogic { -> }
//## Uses: <unnamed>%40288C700074;XPCExceptionErrorInterrupted { -> }
//## Uses: <unnamed>%40288C990120;XPCExceptionErrorShorted { -> }
//## Uses: <unnamed>%40288CAC01CB;PC_IDENTIFIERS { -> }
//## Uses: <unnamed>%40346D6B0017;CPCPid { -> }

class CPCStateProcessControling : public CPCStateProcess  //## Inherits: <unnamed>%403380B701AF
{
  //## begin CPCStateProcessControling%3EED76CC0714.initialDeclarations preserve=yes
  //## end CPCStateProcessControling%3EED76CC0714.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateProcessControling();

    //## Destructor (generated)
      virtual ~CPCStateProcessControling();


    //## Other Operations (specified)
      //## Operation: Create%1044522166
      static void Create ();

      //## Operation: GetInstance%1044522167
      static CPCStateProcessControling* GetInstance ();

      //## Operation: Delete%1044522168
      static void Delete ();

      //## Operation: Do%1045140118
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPCStateProcessControling%3EED76CC0714.public preserve=yes
      //## end CPCStateProcessControling%3EED76CC0714.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateProcessControling%3EED76CC0714.protected preserve=yes
      //## end CPCStateProcessControling%3EED76CC0714.protected

  private:
    //## Constructors (generated)
      CPCStateProcessControling(const CPCStateProcessControling &right);

    //## Assignment Operation (generated)
      const CPCStateProcessControling & operator=(const CPCStateProcessControling &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateProcessControling &right) const;

      bool operator!=(const CPCStateProcessControling &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%3EED76CC08E3
      //## Role: CPCStateProcessControling::pInstance%3EED76CC08E8
      //## begin CPCStateProcessControling::pInstance%3EED76CC08E8.role preserve=no  public: static CPCStateProcessControling {1..1 -> 1..1RFHN}
      static CPCStateProcessControling *m_pInstance;
      //## end CPCStateProcessControling::pInstance%3EED76CC08E8.role

    // Additional Private Declarations
      //## begin CPCStateProcessControling%3EED76CC0714.private preserve=yes
      //## end CPCStateProcessControling%3EED76CC0714.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateProcessControling%3EED76CC0714.implementation preserve=yes
      //## end CPCStateProcessControling%3EED76CC0714.implementation

};

//## begin CPCStateProcessControling%3EED76CC0714.postscript preserve=yes
//## end CPCStateProcessControling%3EED76CC0714.postscript

//## begin CPCStateProcessStarting%4033806E01ED.preface preserve=yes
//## end CPCStateProcessStarting%4033806E01ED.preface

//## Class: CPCStateProcessStarting%4033806E01ED
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%4034CD7403B9;CHIInterface { -> }

class CPCStateProcessStarting : public CPCStateProcess  //## Inherits: <unnamed>%403380BD0345
{
  //## begin CPCStateProcessStarting%4033806E01ED.initialDeclarations preserve=yes
  //## end CPCStateProcessStarting%4033806E01ED.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateProcessStarting();

    //## Destructor (generated)
      virtual ~CPCStateProcessStarting();


    //## Other Operations (specified)
      //## Operation: Create%1077117397
      static void Create ();

      //## Operation: GetInstance%1077117398
      static CPCStateProcessStarting* GetInstance ();

      //## Operation: Delete%1077117399
      static void Delete ();

      //## Operation: Do%1077117400
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPCStateProcessStarting%4033806E01ED.public preserve=yes
      //## end CPCStateProcessStarting%4033806E01ED.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateProcessStarting%4033806E01ED.protected preserve=yes
      //## end CPCStateProcessStarting%4033806E01ED.protected

  private:
    //## Constructors (generated)
      CPCStateProcessStarting(const CPCStateProcessStarting &right);

    //## Assignment Operation (generated)
      const CPCStateProcessStarting & operator=(const CPCStateProcessStarting &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateProcessStarting &right) const;

      bool operator!=(const CPCStateProcessStarting &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%403381730048
      //## Role: CPCStateProcessStarting::pInstance%4033817400E5
      //## begin CPCStateProcessStarting::pInstance%4033817400E5.role preserve=no  public: static CPCStateProcessStarting {1..1 -> 1..1RFHN}
      static CPCStateProcessStarting *m_pInstance;
      //## end CPCStateProcessStarting::pInstance%4033817400E5.role

    // Additional Private Declarations
      //## begin CPCStateProcessStarting%4033806E01ED.private preserve=yes
      //## end CPCStateProcessStarting%4033806E01ED.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateProcessStarting%4033806E01ED.implementation preserve=yes
      //## end CPCStateProcessStarting%4033806E01ED.implementation

};

//## begin CPCStateProcessStarting%4033806E01ED.postscript preserve=yes
//## end CPCStateProcessStarting%4033806E01ED.postscript

//## begin CPCStateProcessSwinging%4035CCCD03C1.preface preserve=yes
//## end CPCStateProcessSwinging%4035CCCD03C1.preface

//## Class: CPCStateProcessSwinging%4035CCCD03C1
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CPCStateProcessSwinging : public CPCStateProcess  //## Inherits: <unnamed>%4035CCFB0121
{
  //## begin CPCStateProcessSwinging%4035CCCD03C1.initialDeclarations preserve=yes
  //## end CPCStateProcessSwinging%4035CCCD03C1.initialDeclarations

  public:
    //## Constructors (generated)
      CPCStateProcessSwinging();

    //## Destructor (generated)
      virtual ~CPCStateProcessSwinging();


    //## Other Operations (specified)
      //## Operation: Create%1077262878
      static void Create ();

      //## Operation: GetInstance%1077262879
      static CPCStateProcessSwinging* GetInstance ();

      //## Operation: Delete%1077262880
      static void Delete ();

      //## Operation: Do%1077262881
      //	DESCRIPTION
      //	Processes actions within a certain state.
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Do (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CPCStateProcessSwinging%4035CCCD03C1.public preserve=yes
      //## end CPCStateProcessSwinging%4035CCCD03C1.public

  protected:
    // Additional Protected Declarations
      //## begin CPCStateProcessSwinging%4035CCCD03C1.protected preserve=yes
      //## end CPCStateProcessSwinging%4035CCCD03C1.protected

  private:
    //## Constructors (generated)
      CPCStateProcessSwinging(const CPCStateProcessSwinging &right);

    //## Assignment Operation (generated)
      const CPCStateProcessSwinging & operator=(const CPCStateProcessSwinging &right);

    //## Equality Operations (generated)
      bool operator==(const CPCStateProcessSwinging &right) const;

      bool operator!=(const CPCStateProcessSwinging &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%4035CCFF0392
      //## Role: CPCStateProcessSwinging::pInstance%4035CD000364
      //## begin CPCStateProcessSwinging::pInstance%4035CD000364.role preserve=no  public: static CPCStateProcessSwinging {1..1 -> 1..1RFHN}
      static CPCStateProcessSwinging *m_pInstance;
      //## end CPCStateProcessSwinging::pInstance%4035CD000364.role

    // Additional Private Declarations
      //## begin CPCStateProcessSwinging%4035CCCD03C1.private preserve=yes
      //## end CPCStateProcessSwinging%4035CCCD03C1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCStateProcessSwinging%4035CCCD03C1.implementation preserve=yes
      //## end CPCStateProcessSwinging%4035CCCD03C1.implementation

};

//## begin CPCStateProcessSwinging%4035CCCD03C1.postscript preserve=yes
//## end CPCStateProcessSwinging%4035CCCD03C1.postscript

// Class CPCStateProcess 

// Class CPCStateProcessControling 

// Class CPCStateProcessStarting 

// Class CPCStateProcessSwinging 

//## begin module%3EED769F038A.epilog preserve=yes
//## end module%3EED769F038A.epilog


#endif
