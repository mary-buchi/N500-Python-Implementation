//## begin module%3DAAD5340350.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DAAD5340350.cm

//## begin module%3DAAD5340350.cp preserve=no
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
//## end module%3DAAD5340350.cp

//## Module: EBMCintf%3DAAD5340350; Package specification
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Source file: R:\Embedded\Src\EBMC\EBMCintf.h

#ifndef EBMCintf_h
#define EBMCintf_h 1

//## begin module%3DAAD5340350.additionalIncludes preserve=no
//## end module%3DAAD5340350.additionalIncludes

//## begin module%3DAAD5340350.includes preserve=yes
//## end module%3DAAD5340350.includes

// EBPItype
#include "EBPItype.h"
// EBPIintf
#include "EBPIintf.h"


//## begin module%3DAAD5340350.declarations preserve=no
//## end module%3DAAD5340350.declarations

//## begin module%3DAAD5340350.additionalDeclarations preserve=yes
//## end module%3DAAD5340350.additionalDeclarations


//## begin CMCMeasurementChannelInterface%3DAAD55E00BF.preface preserve=yes
//## end CMCMeasurementChannelInterface%3DAAD55E00BF.preface

//## Class: CMCMeasurementChannelInterface%3DAAD55E00BF
//## Category: EBMC (Measurement Channel)%3DAAD38C01E8
//## Subsystem: EBMC (Measurement Channel)%3DAAD35002C3
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3DAAD856012D;MC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3DAAEAF602F5;CMCMeasurementChannelImplementation { -> }
//## Uses: <unnamed>%3DAAEB8F0122;CMCCommand { -> }
//## Uses: <unnamed>%3DAE56A20044;CPISyncObjDataPackage { -> }

class EBMC_DLL_DECL CMCMeasurementChannelInterface : public IPIMeasurementChannelInterface  //## Inherits: <unnamed>%3DAAD573017B
{
  //## begin CMCMeasurementChannelInterface%3DAAD55E00BF.initialDeclarations preserve=yes
  //## end CMCMeasurementChannelInterface%3DAAD55E00BF.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CMCMeasurementChannelInterface%1034575107
      CMCMeasurementChannelInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CMCMeasurementChannelInterface();


    //## Other Operations (specified)
      //## Operation: InitInstance%1034575108
      //	DESCRIPTION
      //	Makes the basic initialisation and gets the worker
      //	thread running
      //
      //	RETURNS
      //	void
      virtual void InitInstance ();

      //## Operation: SetProfile%1035789471
      //	DESCRIPTION
      //	Configures the profile of the measurement channel
      //
      //	PARAMETERS
      //	Profile data
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* SetProfile (CPIMeasurementChannelProfile* p_pProfile);

      //## Operation: Initialize%1035789472
      //	DESCRIPTION
      //	Initializes the measurement channel (DMA transfer)
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Initialize ();

      //## Operation: Start%1035789473
      //	DESCRIPTION
      //	Starts the transfer of measuremen data packages. After
      //	Start has been called GetDataPackage may be called.
      //
      //	PARAMETERS
      //	identification of the ongoing measurement cycle
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Start (UINT p_uiCycleID);

      //## Operation: Stop%1035789474
      //	DESCRIPTION
      //	Stops the measurement process.
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Stop ();

      //## Operation: GetDataPackage%1034835013
      virtual CPISyncObjDataPackage* GetDataPackage ();

      //## Operation: ConnectionEstablished%1063260179
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1063260180
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBMC (Measurement Channel)::<unnamed>%3DAAD5A20227
      //## Role: CMCMeasurementChannelInterface::uiID%3DAAD5A30082
      virtual UINT GetuiID ();

    // Additional Public Declarations
      //## begin CMCMeasurementChannelInterface%3DAAD55E00BF.public preserve=yes
      //## end CMCMeasurementChannelInterface%3DAAD55E00BF.public

  protected:
    // Additional Protected Declarations
      //## begin CMCMeasurementChannelInterface%3DAAD55E00BF.protected preserve=yes
      //## end CMCMeasurementChannelInterface%3DAAD55E00BF.protected

  private:
    //## Constructors (generated)
      CMCMeasurementChannelInterface();

      CMCMeasurementChannelInterface(const CMCMeasurementChannelInterface &right);

    //## Assignment Operation (generated)
      const CMCMeasurementChannelInterface & operator=(const CMCMeasurementChannelInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CMCMeasurementChannelInterface &right) const;

      bool operator!=(const CMCMeasurementChannelInterface &right) const;

    // Data Members for Associations

      //## Association: EBMC (Measurement Channel)::<unnamed>%3DAAD5A20227
      //## begin CMCMeasurementChannelInterface::uiID%3DAAD5A30082.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CMCMeasurementChannelInterface::uiID%3DAAD5A30082.role

    // Additional Private Declarations
      //## begin CMCMeasurementChannelInterface%3DAAD55E00BF.private preserve=yes
      //## end CMCMeasurementChannelInterface%3DAAD55E00BF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CMCMeasurementChannelInterface%3DAAD55E00BF.implementation preserve=yes
      //## end CMCMeasurementChannelInterface%3DAAD55E00BF.implementation

};

//## begin CMCMeasurementChannelInterface%3DAAD55E00BF.postscript preserve=yes
//## end CMCMeasurementChannelInterface%3DAAD55E00BF.postscript

// Class CMCMeasurementChannelInterface 

//## begin module%3DAAD5340350.epilog preserve=yes
//## end module%3DAAD5340350.epilog


#endif
