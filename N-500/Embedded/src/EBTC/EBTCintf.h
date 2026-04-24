//## begin module%3DE5EE0B012D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DE5EE0B012D.cm

//## begin module%3DE5EE0B012D.cp preserve=no
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
//## end module%3DE5EE0B012D.cp

//## Module: EBTCintf%3DE5EE0B012D; Package specification
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Source file: R:\Embedded\src\EBTC\EBTCintf.h

#ifndef EBTCintf_h
#define EBTCintf_h 1

//## begin module%3DE5EE0B012D.additionalIncludes preserve=no
//## end module%3DE5EE0B012D.additionalIncludes

//## begin module%3DE5EE0B012D.includes preserve=yes
//## end module%3DE5EE0B012D.includes

// EBPIintf
#include "EBPIintf.h"


//## begin module%3DE5EE0B012D.declarations preserve=no
//## end module%3DE5EE0B012D.declarations

//## begin module%3DE5EE0B012D.additionalDeclarations preserve=yes
//## end module%3DE5EE0B012D.additionalDeclarations


//## begin CTCTemperatureControlInterface%3DEC5892036B.preface preserve=yes
//## end CTCTemperatureControlInterface%3DEC5892036B.preface

//## Class: CTCTemperatureControlInterface%3DEC5892036B
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DEC60BD0138;CTCTemperatureControlImplementation { -> }
//## Uses: <unnamed>%3DEC83BD00AF;CCOSyncObject { -> }
//## Uses: <unnamed>%3DEC83DD01B8;TC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3E68769A01D1;CTCCommand { -> }

class EBTC_DLL_DECL CTCTemperatureControlInterface : public IPITemperatureControlInterface  //## Inherits: <unnamed>%3DEC58AA03C9
{
  //## begin CTCTemperatureControlInterface%3DEC5892036B.initialDeclarations preserve=yes
  //## end CTCTemperatureControlInterface%3DEC5892036B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCTemperatureControlInterface%1038899302
      CTCTemperatureControlInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CTCTemperatureControlInterface();


    //## Other Operations (specified)
      //## Operation: InitInstance%1039429741
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

      //## Operation: GetuiID%1038899351
      virtual UINT GetuiID ();

      //## Operation: SetProfile%1038899307
      //	DESCRIPTION
      //	Configures the profile of the temperature control unit
      //
      //	PARAMETERS
      //	Profile data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetProfile (CPITemperatureControlProfile* p_pProfile);

      //## Operation: SetConfiguration%1038899303
      //	DESCRIPTION
      //	Configures the active temperature nominal and range
      //	values
      //
      //	PARAMETERS
      //	Config data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetConfiguration (CPITemperatureControlConfig* p_pConfig);

      //## Operation: Start%1038899304
      //	DESCRIPTION
      //	Starts the control cycle. The supplied sync object is
      //	used to pass exception events such as warning or failure
      //	events to the client.
      //
      //	RETURNS
      //	async array:
      //	[0]: Start executed
      //	[1]: Exceptions
      virtual CCOSyncObjectArray* Start ();

      //## Operation: Stop%1038899305
      //	DESCRIPTION
      //	Stops the control cycle.
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Stop ();

      //## Operation: GetTemperature%1038899306
      //	DESCRIPTION
      //	Returns the current temperature value
      //
      //	RETURNS
      //	async integer
      virtual CCOSyncObjectInt* GetTemperature ();

      //## Operation: ConnectionEstablished%1055922847
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1055922848
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

    // Additional Public Declarations
      //## begin CTCTemperatureControlInterface%3DEC5892036B.public preserve=yes
      //## end CTCTemperatureControlInterface%3DEC5892036B.public

  protected:
    // Additional Protected Declarations
      //## begin CTCTemperatureControlInterface%3DEC5892036B.protected preserve=yes
      //## end CTCTemperatureControlInterface%3DEC5892036B.protected

  private:
    //## Constructors (generated)
      CTCTemperatureControlInterface();

      CTCTemperatureControlInterface(const CTCTemperatureControlInterface &right);

    //## Assignment Operation (generated)
      const CTCTemperatureControlInterface & operator=(const CTCTemperatureControlInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CTCTemperatureControlInterface &right) const;

      bool operator!=(const CTCTemperatureControlInterface &right) const;

    // Data Members for Associations

      //## Association: EBTC (Temperature Control)::<unnamed>%3DEC5AB401C5
      //## Role: CTCTemperatureControlInterface::uiID%3DEC5AB50178
      //## begin CTCTemperatureControlInterface::uiID%3DEC5AB50178.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CTCTemperatureControlInterface::uiID%3DEC5AB50178.role

    // Additional Private Declarations
      //## begin CTCTemperatureControlInterface%3DEC5892036B.private preserve=yes
      //## end CTCTemperatureControlInterface%3DEC5892036B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCTemperatureControlInterface%3DEC5892036B.implementation preserve=yes
      //## end CTCTemperatureControlInterface%3DEC5892036B.implementation

};

//## begin CTCTemperatureControlInterface%3DEC5892036B.postscript preserve=yes
//## end CTCTemperatureControlInterface%3DEC5892036B.postscript

//## begin CTCTemperatureControlInterface2%48971482009A.preface preserve=yes
//## end CTCTemperatureControlInterface2%48971482009A.preface

//## Class: CTCTemperatureControlInterface2%48971482009A
//## Category: EBTC (Temperature Control)%3DE5E81C010E
//## Subsystem: EBTC (Temperature Control)%3DE5E83800D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%489715100350;CTCTemperatureControlImplementation2 { -> }

class EBTC_DLL_DECL CTCTemperatureControlInterface2 : public CTCTemperatureControlInterface  //## Inherits: <unnamed>%4897149E01CB
{
  //## begin CTCTemperatureControlInterface2%48971482009A.initialDeclarations preserve=yes
  //## end CTCTemperatureControlInterface2%48971482009A.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CTCTemperatureControlInterface2%1218193719
      CTCTemperatureControlInterface2 (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CTCTemperatureControlInterface2();


    //## Other Operations (specified)
      //## Operation: InitInstance%1217858755
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

    // Additional Public Declarations
      //## begin CTCTemperatureControlInterface2%48971482009A.public preserve=yes
      //## end CTCTemperatureControlInterface2%48971482009A.public

  protected:
    // Additional Protected Declarations
      //## begin CTCTemperatureControlInterface2%48971482009A.protected preserve=yes
      //## end CTCTemperatureControlInterface2%48971482009A.protected

  private:
    //## Constructors (generated)
      CTCTemperatureControlInterface2();

      CTCTemperatureControlInterface2(const CTCTemperatureControlInterface2 &right);

    //## Assignment Operation (generated)
      const CTCTemperatureControlInterface2 & operator=(const CTCTemperatureControlInterface2 &right);

    //## Equality Operations (generated)
      bool operator==(const CTCTemperatureControlInterface2 &right) const;

      bool operator!=(const CTCTemperatureControlInterface2 &right) const;

    // Additional Private Declarations
      //## begin CTCTemperatureControlInterface2%48971482009A.private preserve=yes
      //## end CTCTemperatureControlInterface2%48971482009A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CTCTemperatureControlInterface2%48971482009A.implementation preserve=yes
      //## end CTCTemperatureControlInterface2%48971482009A.implementation

};

//## begin CTCTemperatureControlInterface2%48971482009A.postscript preserve=yes
//## end CTCTemperatureControlInterface2%48971482009A.postscript

// Class CTCTemperatureControlInterface 

// Class CTCTemperatureControlInterface2 

//## begin module%3DE5EE0B012D.epilog preserve=yes
//## end module%3DE5EE0B012D.epilog


#endif
