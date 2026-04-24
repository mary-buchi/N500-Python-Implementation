//## begin module%3DD0BC070038.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DD0BC070038.cm

//## begin module%3DD0BC070038.cp preserve=no
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
//## end module%3DD0BC070038.cp

//## Module: EBWCintf%3DD0BC070038; Package specification
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Source file: R:\Embedded\src\EBWC\EBWCintf.h

#ifndef EBWCintf_h
#define EBWCintf_h 1

//## begin module%3DD0BC070038.additionalIncludes preserve=no
//## end module%3DD0BC070038.additionalIncludes

//## begin module%3DD0BC070038.includes preserve=yes
//## end module%3DD0BC070038.includes

// EBPIintf
#include "EBPIintf.h"


//## begin module%3DD0BC070038.declarations preserve=no
//## end module%3DD0BC070038.declarations

//## begin module%3DD0BC070038.additionalDeclarations preserve=yes
//## end module%3DD0BC070038.additionalDeclarations


//## begin CWCWedgeControlInterface%3DD0BC940123.preface preserve=yes
//## end CWCWedgeControlInterface%3DD0BC940123.preface

//## Class: CWCWedgeControlInterface%3DD0BC940123
//## Category: EBWC (Wedge Control)%3DCFD60400E4
//## Subsystem: EBWC (Wedge Control)%3DCFD5DD00C5
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DD205D50005;WC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3DD205DB0276;CWCWedgeControlImplementation { -> }
//## Uses: <unnamed>%3DD3BD34026E;CCOSyncObject { -> }
//## Uses: <unnamed>%3DF490150059;CWCCommand { -> }

class EBWC_DLL_DECL CWCWedgeControlInterface : public IPIWedgeControlInterface  //## Inherits: <unnamed>%3DD0F0E30205
{
  //## begin CWCWedgeControlInterface%3DD0BC940123.initialDeclarations preserve=yes
  //## end CWCWedgeControlInterface%3DD0BC940123.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CWCWedgeControlInterface%1037094239
      CWCWedgeControlInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CWCWedgeControlInterface();


    //## Other Operations (specified)
      //## Operation: InitInstance%1037094238
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

      //## Operation: GetuiID%1037174257
      virtual UINT GetuiID ();

      //## Operation: SetProfile%1037174258
      //	DESCRIPTION
      //	Configures the profile of the wedge control unit
      //
      //	PARAMETERS
      //	Profile data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetProfile (CPIWedgeControlProfile* p_pProfile);

      //## Operation: SetConfiguration%1037174259
      //	DESCRIPTION
      //	Configures the active window and speed settings of the
      //	wedge control unit
      //
      //	PARAMETERS
      //	Config data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetConfiguration (CPIWedgeControlConfig* p_pConfig);

      //## Operation: Initialize%1037174260
      //	DESCRIPTION
      //	initializes the wedge drive using the light fork
      //	reference sensor
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Initialize ();

      //## Operation: Start%1037174261
      //	DESCRIPTION
      //	Starts the control cycle. The supplied sync object is
      //	used to pass exception events such as warning or failure
      //	events to the client.
      //
      //	PARAMETER
      //	- p_iScan: numbers of scans
      //
      //	RETURNS
      //	async array:
      //	[0]: Start executed
      //	[1]: Exceptions
      virtual CCOSyncObjectArray* Start (int p_iScan = -1);

      //## Operation: Stop%1037174262
      //	DESCRIPTION
      //	Stops the control cycle.
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Stop ();

      //## Operation: Referencing%1037976625
      //	DESCRIPTION
      //	References the wegde
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Referencing ();

      //## Operation: Park%1053509632
      //	DESCRIPTION
      //	Parks the control cycle.
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Park ();

      //## Operation: ConnectionEstablished%1063260177
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1063260178
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

      //## Operation: GetDacZeroCurrent%1149159894
      //	DESCRIPTION
      //	Reads the dac value of the zero current
      //
      //	RETURNS
      //	async int
      virtual CCOSyncObjectInt* GetDacZeroCurrent ();

    // Additional Public Declarations
      //## begin CWCWedgeControlInterface%3DD0BC940123.public preserve=yes
      //## end CWCWedgeControlInterface%3DD0BC940123.public

  protected:
    // Additional Protected Declarations
      //## begin CWCWedgeControlInterface%3DD0BC940123.protected preserve=yes
      //## end CWCWedgeControlInterface%3DD0BC940123.protected

  private:
    //## Constructors (generated)
      CWCWedgeControlInterface();

      CWCWedgeControlInterface(const CWCWedgeControlInterface &right);

    //## Assignment Operation (generated)
      const CWCWedgeControlInterface & operator=(const CWCWedgeControlInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CWCWedgeControlInterface &right) const;

      bool operator!=(const CWCWedgeControlInterface &right) const;

    // Data Members for Associations

      //## Association: EBWC (Wedge Control)::<unnamed>%3DD0F20F0225
      //## Role: CWCWedgeControlInterface::uiID%3DD0F21002E1
      //## begin CWCWedgeControlInterface::uiID%3DD0F21002E1.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CWCWedgeControlInterface::uiID%3DD0F21002E1.role

    // Additional Private Declarations
      //## begin CWCWedgeControlInterface%3DD0BC940123.private preserve=yes
      //## end CWCWedgeControlInterface%3DD0BC940123.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CWCWedgeControlInterface%3DD0BC940123.implementation preserve=yes
      //## end CWCWedgeControlInterface%3DD0BC940123.implementation

};

//## begin CWCWedgeControlInterface%3DD0BC940123.postscript preserve=yes
//## end CWCWedgeControlInterface%3DD0BC940123.postscript

// Class CWCWedgeControlInterface 

//## begin module%3DD0BC070038.epilog preserve=yes
//## end module%3DD0BC070038.epilog


#endif
