//## begin module%3EED769F0372.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F0372.cm

//## begin module%3EED769F0372.cp preserve=no
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
//## end module%3EED769F0372.cp

//## Module: EBPCintf%3EED769F0372; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPCintf.h

#ifndef EBPCintf_h
#define EBPCintf_h 1

//## begin module%3EED769F0372.additionalIncludes preserve=no
//## end module%3EED769F0372.additionalIncludes

//## begin module%3EED769F0372.includes preserve=yes
//## end module%3EED769F0372.includes

// EBPIintf
#include "EBPIintf.h"


//## begin module%3EED769F0372.declarations preserve=no
//## end module%3EED769F0372.declarations

//## begin module%3EED769F0372.additionalDeclarations preserve=yes
//## end module%3EED769F0372.additionalDeclarations


//## begin CPCPowerControlInterface%3EED76CC0307.preface preserve=yes
//## end CPCPowerControlInterface%3EED76CC0307.preface

//## Class: CPCPowerControlInterface%3EED76CC0307
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3EED76CC030C;CPCPowerControlImplementation { -> }
//## Uses: <unnamed>%3EED76CC030F;CCOSyncObject { -> }
//## Uses: <unnamed>%3EED76CC0312;PC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3EED76CC0315;CPCCommand { -> }

class EBPC_DLL_DECL CPCPowerControlInterface : public IPIPowerControlInterface  //## Inherits: <unnamed>%3EED76CC0309
{
  //## begin CPCPowerControlInterface%3EED76CC0307.initialDeclarations preserve=yes
  //## end CPCPowerControlInterface%3EED76CC0307.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPCPowerControlInterface%1038899302
      CPCPowerControlInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CPCPowerControlInterface();


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
      virtual CCOSyncObject* SetProfile (CPIPowerControlProfile* p_pProfile);

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
      virtual CCOSyncObject* SetConfiguration (CPIPowerControlConfig* p_pConfig);

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

      //## Operation: ConnectionEstablished%1055922849
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1055922850
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

      //## Operation: PowerOff%1076339197
      //	DESCRIPTION
      //	Power off for lamp change.
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* PowerOff ();

      //## Operation: PowerOn%1076339198
      //	DESCRIPTION
      //	Starts the power after lamp change.
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* PowerOn ();

    // Additional Public Declarations
      //## begin CPCPowerControlInterface%3EED76CC0307.public preserve=yes
      //## end CPCPowerControlInterface%3EED76CC0307.public

  protected:
    // Additional Protected Declarations
      //## begin CPCPowerControlInterface%3EED76CC0307.protected preserve=yes
      //## end CPCPowerControlInterface%3EED76CC0307.protected

  private:
    //## Constructors (generated)
      CPCPowerControlInterface();

      CPCPowerControlInterface(const CPCPowerControlInterface &right);

    //## Assignment Operation (generated)
      const CPCPowerControlInterface & operator=(const CPCPowerControlInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CPCPowerControlInterface &right) const;

      bool operator!=(const CPCPowerControlInterface &right) const;

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%4034670301AD
      //## Role: CPCPowerControlInterface::uiID%403467040066
      //## begin CPCPowerControlInterface::uiID%403467040066.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CPCPowerControlInterface::uiID%403467040066.role

    // Additional Private Declarations
      //## begin CPCPowerControlInterface%3EED76CC0307.private preserve=yes
      //## end CPCPowerControlInterface%3EED76CC0307.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCPowerControlInterface%3EED76CC0307.implementation preserve=yes
      //## end CPCPowerControlInterface%3EED76CC0307.implementation

};

//## begin CPCPowerControlInterface%3EED76CC0307.postscript preserve=yes
//## end CPCPowerControlInterface%3EED76CC0307.postscript

// Class CPCPowerControlInterface 

//## begin module%3EED769F0372.epilog preserve=yes
//## end module%3EED769F0372.epilog


#endif
