//## begin module%3E410469020B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E410469020B.cm

//## begin module%3E410469020B.cp preserve=no
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
//## end module%3E410469020B.cp

//## Module: EBTCprocess%3E410469020B; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCprocess.h

#ifndef EBTCprocess_h
#define EBTCprocess_h 1

//## begin module%3E410469020B.additionalIncludes preserve=no
//## end module%3E410469020B.additionalIncludes

//## begin module%3E410469020B.includes preserve=yes
//## end module%3E410469020B.includes

// EBTCstat
#include "EBTCstat.h"
//## begin module%3E410469020B.declarations preserve=no
//## end module%3E410469020B.declarations

//## begin module%3E410469020B.additionalDeclarations preserve=yes
//## end module%3E410469020B.additionalDeclarations


//## begin CTCStateProcess%3E41070F017F.preface preserve=yes
//## end CTCStateProcess%3E41070F017F.preface

//## Class: CTCStateProcess%3E41070F017F
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E47B0EB00FA;ICOStateMachineContext { -> }
//## Uses: <unnamed>%3E47B7F0031C;CTCStateConfig { -> }
//## Uses: <unnamed>%3E4B9FC4019A;CTCStateCreated { -> }
//## Uses: <unnamed>%3E562CE703B1;CTCTemperatureControlImplementation { -> }
//## Uses: <unnamed>%3E562E9402C6;CTCLogic { -> }
//## Uses: <unnamed>%3EE8167D0215;CTCStateNotConnectedProcess { -> }
//## Uses: <unnamed>%3F154C5D03A1;CPITemperatureControlConfig { -> }
//## Uses: <unnamed>%3FD098B103E0;TC_IDENTIFIERS { -> }
//## Uses: <unnamed>%417FB19701DA;XCOExceptionCellUndocked { -> }
//## Uses: <unnamed>%468BB9750343;IHIInterface { -> }

class CTCStateProcess : public CTCState  //## Inherits: <unnamed>%3E410EC802B7
{
  //## begin CTCStateProcess%3E41070F017F.initialDeclarations preserve=yes
  //## end CTCStateProcess%3E41070F017F.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateProcess();

    //## Destructor (generated)
      virtual ~CTCStateProcess();


    //## Other Operations (specified)
      //## Operation: Stop%1044604252
      virtual void Stop (ICOStateMachineContext* p_pContext);

      //## Operation: CleanupInitialize%1055317631
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

      //## Operation: ConnectionLost%1055922853
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void ConnectionLost (ICOStateMachineContext* p_pContext);

      //## Operation: Start%1056003015
      virtual void Start (ICOStateMachineContext* p_pContext, CCOSyncObject* p_pIncidentSyncObj);

      //## Operation: Shutdown%1183379135
      //	DESCRIPTION
      //	Brings the subsystem down to the initial state 'Created'
      //
      //	PARAMETER
      //	- Context
      //
      //	RETURNS
      //	void
      virtual void Shutdown (ICOStateMachineContext* p_pContext);

      //## Operation: CellUndocked%1216975786
      virtual void CellUndocked (ICOStateMachineContext* p_pContext);

    // Additional Public Declarations
      //## begin CTCStateProcess%3E41070F017F.public preserve=yes
      //## end CTCStateProcess%3E41070F017F.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateProcess%3E41070F017F.protected preserve=yes
      //## end CTCStateProcess%3E41070F017F.protected

  private:
    //## Constructors (generated)
      CTCStateProcess(const CTCStateProcess &right);

    //## Assignment Operation (generated)
      const CTCStateProcess & operator=(const CTCStateProcess &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateProcess &right) const;

      bool operator!=(const CTCStateProcess &right) const;

    // Additional Private Declarations
      //## begin CTCStateProcess%3E41070F017F.private preserve=yes
      //## end CTCStateProcess%3E41070F017F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateProcess%3E41070F017F.implementation preserve=yes
      //## end CTCStateProcess%3E41070F017F.implementation

};

//## begin CTCStateProcess%3E41070F017F.postscript preserve=yes
//## end CTCStateProcess%3E41070F017F.postscript

//## begin CTCStateProcessControl%3E410AAF0353.preface preserve=yes
//## end CTCStateProcessControl%3E410AAF0353.preface

//## Class: CTCStateProcessControl%3E410AAF0353
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCStateProcessControl : public CTCStateProcess  //## Inherits: <unnamed>%3E42290400B1
{
  //## begin CTCStateProcessControl%3E410AAF0353.initialDeclarations preserve=yes
  //## end CTCStateProcessControl%3E410AAF0353.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateProcessControl();

    //## Destructor (generated)
      virtual ~CTCStateProcessControl();


    //## Other Operations (specified)
      //## Operation: Create%1044522166
      static void Create ();

      //## Operation: GetInstance%1044522167
      static CTCStateProcessControl* GetInstance ();

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
      //## begin CTCStateProcessControl%3E410AAF0353.public preserve=yes
      //## end CTCStateProcessControl%3E410AAF0353.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateProcessControl%3E410AAF0353.protected preserve=yes
      //## end CTCStateProcessControl%3E410AAF0353.protected

  private:
    //## Constructors (generated)
      CTCStateProcessControl(const CTCStateProcessControl &right);

    //## Assignment Operation (generated)
      const CTCStateProcessControl & operator=(const CTCStateProcessControl &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateProcessControl &right) const;

      bool operator!=(const CTCStateProcessControl &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3E51FF36006A
      //## Role: CTCStateProcessControl::pInstance%3E51FF3702CD
      //## begin CTCStateProcessControl::pInstance%3E51FF3702CD.role preserve=no  public: static CTCStateProcessControl {1..1 -> 1..1RFHN}
      static CTCStateProcessControl *m_pInstance;
      //## end CTCStateProcessControl::pInstance%3E51FF3702CD.role

    // Additional Private Declarations
      //## begin CTCStateProcessControl%3E410AAF0353.private preserve=yes
      //## end CTCStateProcessControl%3E410AAF0353.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateProcessControl%3E410AAF0353.implementation preserve=yes
      //## end CTCStateProcessControl%3E410AAF0353.implementation

};

//## begin CTCStateProcessControl%3E410AAF0353.postscript preserve=yes
//## end CTCStateProcessControl%3E410AAF0353.postscript

//## begin CTCStateProcessIdle%3E410A8301DC.preface preserve=yes
//## end CTCStateProcessIdle%3E410A8301DC.preface

//## Class: CTCStateProcessIdle%3E410A8301DC
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCStateProcessIdle : public CTCStateProcess  //## Inherits: <unnamed>%3E42290100FF
{
  //## begin CTCStateProcessIdle%3E410A8301DC.initialDeclarations preserve=yes
  //## end CTCStateProcessIdle%3E410A8301DC.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateProcessIdle();

    //## Destructor (generated)
      virtual ~CTCStateProcessIdle();


    //## Other Operations (specified)
      //## Operation: Create%1044522158
      static void Create ();

      //## Operation: GetInstance%1044522159
      static CTCStateProcessIdle* GetInstance ();

      //## Operation: Delete%1044522160
      static void Delete ();

      //## Operation: Do%1045140119
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
      //## begin CTCStateProcessIdle%3E410A8301DC.public preserve=yes
      //## end CTCStateProcessIdle%3E410A8301DC.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateProcessIdle%3E410A8301DC.protected preserve=yes
      //## end CTCStateProcessIdle%3E410A8301DC.protected

  private:
    //## Constructors (generated)
      CTCStateProcessIdle(const CTCStateProcessIdle &right);

    //## Assignment Operation (generated)
      const CTCStateProcessIdle & operator=(const CTCStateProcessIdle &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateProcessIdle &right) const;

      bool operator!=(const CTCStateProcessIdle &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3E4230D903D0
      //## Role: CTCStateProcessIdle::pInstance%3E4230DB0095
      //## begin CTCStateProcessIdle::pInstance%3E4230DB0095.role preserve=no  public: static CTCStateProcessIdle {1..1 -> 1..1RFHN}
      static CTCStateProcessIdle *m_pInstance;
      //## end CTCStateProcessIdle::pInstance%3E4230DB0095.role

    // Additional Private Declarations
      //## begin CTCStateProcessIdle%3E410A8301DC.private preserve=yes
      //## end CTCStateProcessIdle%3E410A8301DC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateProcessIdle%3E410A8301DC.implementation preserve=yes
      //## end CTCStateProcessIdle%3E410A8301DC.implementation

};

//## begin CTCStateProcessIdle%3E410A8301DC.postscript preserve=yes
//## end CTCStateProcessIdle%3E410A8301DC.postscript

//## begin CTCStateProcessPwmHigh%40CD681A0065.preface preserve=yes
//## end CTCStateProcessPwmHigh%40CD681A0065.preface

//## Class: CTCStateProcessPwmHigh%40CD681A0065
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCStateProcessPwmHigh : public CTCStateProcess  //## Inherits: <unnamed>%40CD683C016F
{
  //## begin CTCStateProcessPwmHigh%40CD681A0065.initialDeclarations preserve=yes
  //## end CTCStateProcessPwmHigh%40CD681A0065.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateProcessPwmHigh();

    //## Destructor (generated)
      virtual ~CTCStateProcessPwmHigh();


    //## Other Operations (specified)
      //## Operation: Create%1087195410
      static void Create ();

      //## Operation: GetInstance%1087195411
      static CTCStateProcessPwmHigh* GetInstance ();

      //## Operation: Delete%1087195412
      static void Delete ();

      //## Operation: Do%1087195413
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
      //## begin CTCStateProcessPwmHigh%40CD681A0065.public preserve=yes
      //## end CTCStateProcessPwmHigh%40CD681A0065.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateProcessPwmHigh%40CD681A0065.protected preserve=yes
      //## end CTCStateProcessPwmHigh%40CD681A0065.protected

  private:
    //## Constructors (generated)
      CTCStateProcessPwmHigh(const CTCStateProcessPwmHigh &right);

    //## Assignment Operation (generated)
      const CTCStateProcessPwmHigh & operator=(const CTCStateProcessPwmHigh &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateProcessPwmHigh &right) const;

      bool operator!=(const CTCStateProcessPwmHigh &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%40CD688D01BD
      //## Role: CTCStateProcessPwmHigh::pInstance%40CD688E01BE
      //## begin CTCStateProcessPwmHigh::pInstance%40CD688E01BE.role preserve=no  public: static CTCStateProcessPwmHigh {1..1 -> 1..1RFHN}
      static CTCStateProcessPwmHigh *m_pInstance;
      //## end CTCStateProcessPwmHigh::pInstance%40CD688E01BE.role

    // Additional Private Declarations
      //## begin CTCStateProcessPwmHigh%40CD681A0065.private preserve=yes
      //## end CTCStateProcessPwmHigh%40CD681A0065.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateProcessPwmHigh%40CD681A0065.implementation preserve=yes
      //## end CTCStateProcessPwmHigh%40CD681A0065.implementation

};

//## begin CTCStateProcessPwmHigh%40CD681A0065.postscript preserve=yes
//## end CTCStateProcessPwmHigh%40CD681A0065.postscript

//## begin CTCStateProcessPwmLow%40CD682C01CD.preface preserve=yes
//## end CTCStateProcessPwmLow%40CD682C01CD.preface

//## Class: CTCStateProcessPwmLow%40CD682C01CD
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CTCStateProcessPwmLow : public CTCStateProcess  //## Inherits: <unnamed>%40CD683F01CD
{
  //## begin CTCStateProcessPwmLow%40CD682C01CD.initialDeclarations preserve=yes
  //## end CTCStateProcessPwmLow%40CD682C01CD.initialDeclarations

  public:
    //## Constructors (generated)
      CTCStateProcessPwmLow();

    //## Destructor (generated)
      virtual ~CTCStateProcessPwmLow();


    //## Other Operations (specified)
      //## Operation: Create%1087195414
      static void Create ();

      //## Operation: GetInstance%1087195415
      static CTCStateProcessPwmLow* GetInstance ();

      //## Operation: Delete%1087195416
      static void Delete ();

      //## Operation: Do%1087195417
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
      //## begin CTCStateProcessPwmLow%40CD682C01CD.public preserve=yes
      //## end CTCStateProcessPwmLow%40CD682C01CD.public

  protected:
    // Additional Protected Declarations
      //## begin CTCStateProcessPwmLow%40CD682C01CD.protected preserve=yes
      //## end CTCStateProcessPwmLow%40CD682C01CD.protected

  private:
    //## Constructors (generated)
      CTCStateProcessPwmLow(const CTCStateProcessPwmLow &right);

    //## Assignment Operation (generated)
      const CTCStateProcessPwmLow & operator=(const CTCStateProcessPwmLow &right);

    //## Equality Operations (generated)
      bool operator==(const CTCStateProcessPwmLow &right) const;

      bool operator!=(const CTCStateProcessPwmLow &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%40CD689002D6
      //## Role: CTCStateProcessPwmLow::pInstance%40CD68910289
      //## begin CTCStateProcessPwmLow::pInstance%40CD68910289.role preserve=no  public: static CTCStateProcessPwmLow {1..1 -> 1..1RFHN}
      static CTCStateProcessPwmLow *m_pInstance;
      //## end CTCStateProcessPwmLow::pInstance%40CD68910289.role

    // Additional Private Declarations
      //## begin CTCStateProcessPwmLow%40CD682C01CD.private preserve=yes
      //## end CTCStateProcessPwmLow%40CD682C01CD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCStateProcessPwmLow%40CD682C01CD.implementation preserve=yes
      //## end CTCStateProcessPwmLow%40CD682C01CD.implementation

};

//## begin CTCStateProcessPwmLow%40CD682C01CD.postscript preserve=yes
//## end CTCStateProcessPwmLow%40CD682C01CD.postscript

// Class CTCStateProcess 

// Class CTCStateProcessControl 

// Class CTCStateProcessIdle 

// Class CTCStateProcessPwmHigh 

// Class CTCStateProcessPwmLow 

//## begin module%3E410469020B.epilog preserve=yes
//## end module%3E410469020B.epilog


#endif
