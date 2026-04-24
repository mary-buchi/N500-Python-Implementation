//## begin module%3E19811A01D0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E19811A01D0.cm

//## begin module%3E19811A01D0.cp preserve=no
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
//## end module%3E19811A01D0.cp

//## Module: EBDIintf%3E19811A01D0; Package specification
//## Subsystem: EBDI (Diagnostics)%3E197C2800D6
//## Source file: R:\Embedded\src\EBDI\EBDIintf.h

#ifndef EBDIintf_h
#define EBDIintf_h 1

//## begin module%3E19811A01D0.additionalIncludes preserve=no
//## end module%3E19811A01D0.additionalIncludes

//## begin module%3E19811A01D0.includes preserve=yes
//## end module%3E19811A01D0.includes

// EBPIintf
#include "EBPIintf.h"


//## begin module%3E19811A01D0.declarations preserve=no
//## end module%3E19811A01D0.declarations

//## begin module%3E19811A01D0.additionalDeclarations preserve=yes
//## end module%3E19811A01D0.additionalDeclarations


//## begin CDIDiagnosticInterface%3E198CAE029B.preface preserve=yes
//## end CDIDiagnosticInterface%3E198CAE029B.preface

//## Class: CDIDiagnosticInterface%3E198CAE029B
//## Category: EBDI (Diagnostics)%3E197C790124
//## Subsystem: EBDI (Diagnostics)%3E197C2800D6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E199D2E027C;DI_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F55DB6A0290;CPIComponentsState { -> }
//## Uses: <unnamed>%3F55DB6D0232;IHIInterface { -> }
//## Uses: <unnamed>%4141A0A400FA;IPII2CEprom24LC515 { -> }
//## Uses: <unnamed>%41455CAD00FA;CPIObjectFactory { -> }
//## Uses: <unnamed>%4147EE6C008C;XCOExceptionError { -> }

class EBDI_DLL_DECL CDIDiagnosticInterface : public IPIDiagnosticInterface  //## Inherits: <unnamed>%3E198CBC0366
{
  //## begin CDIDiagnosticInterface%3E198CAE029B.initialDeclarations preserve=yes
  //## end CDIDiagnosticInterface%3E198CAE029B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CDIDiagnosticInterface%1041861676
      CDIDiagnosticInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CDIDiagnosticInterface();


    //## Other Operations (specified)
      //## Operation: Startup%1041861679
      //	DESCRIPTION
      //	Links the object to the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Startup ();

      //## Operation: Shutdown%1041861680
      //	DESCRIPTION
      //	Detaches the object from the hardware
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* Shutdown ();

      //## Operation: ConnectionEstablished%1055770102
      //	DESCRIPTION
      //	The connection to the PC has been established
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionEstablished ();

      //## Operation: ConnectionLost%1055770103
      //	DESCRIPTION
      //	The connection to the PC has been lost
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* ConnectionLost ();

      //## Operation: GetuiID%1041922647
      virtual UINT GetuiID ();

      //## Operation: ReadDWord%1041861677
      //	DESCRIPTION
      //	Reads a double word from a specific PCI address
      //
      //	RETURNS
      //	async integer
      virtual CCOSyncObjectInt* ReadDWord (UINT p_uiAddress, EPIRegisterType p_eRegisterType);

      //## Operation: WriteDWord%1041861678
      //	DESCRIPTION
      //	Writes a double word to a specific PCI address
      //
      //	RETURNS
      //	async void
      virtual CCOSyncObject* WriteDWord (UINT p_uiAddress, UINT p_uiValue, EPIRegisterType p_eRegisterType);

      //## Operation: EnableEventSignalisation%1066028230
      //	DESCRIPTION
      //	enables the event signalisation (open events)
      virtual CCOSyncObject* EnableEventSignalisation ();

      //## Operation: DisableEventSignalisation%1066028231
      //	DESCRIPTION
      //	disables the event signalisation (open events)
      virtual CCOSyncObject* DisableEventSignalisation ();

      //## Operation: PCSetNomVoltage%1094803150
      //	DESCRIPTION:
      //	sets the nominal voltage for the primary or secondary
      //	lamp
      //
      //	select lamp (primary or secondary first with function
      //	PCLampSelection
      //
      //	INPUT:
      //	DAC value
      virtual CCOSyncObject* PCSetNomVoltage (DWORD p_dwDACValue);

      //## Operation: PCLampSelection%1094803151
      //	DESCRIPTION:
      //	selects the primary or secondary lamp
      //
      //
      //	INPUT:
      //	 - EPILamp
      virtual CCOSyncObject* PCLampSelection (EPILamp p_eSelection);

      //## Operation: PCLampOnOff%1094803152
      //	DESCRIPTION:
      //	primary or secondary lamp On / Off
      //
      //
      //	INPUT:
      //	false: OFF default
      //	true:  ON
      virtual CCOSyncObject* PCLampOnOff (bool p_bSelection = false);

      //## Operation: PCGetActCurrent%1094803153
      //	DESCRIPTION:
      //	gets the actual current from the selected lamp (primary
      //	or secondary)
      //
      //	RETURN:
      //	actual current
      virtual CCOSyncObjectInt* PCGetActCurrent ();

      //## Operation: PCGetActVoltage%1094803154
      //	DESCRIPTION:
      //	gets the actual voltage from the selected lamp (primary
      //	or secondary)
      //
      //	INPUT:
      //	 - EPILamp
      //
      //	RETURN:
      //	actual voltage
      virtual CCOSyncObjectInt* PCGetActVoltage (EPILamp p_eSelection);

      //## Operation: PCGetLampIdentification%1094803155
      //	DESCRIPTION:
      //	gets the selected lamp identification (primary or
      //	secondary)
      //
      //	INPUT:
      //	 - EPILamp
      //
      //	RETURN:
      //	lamp identification
      virtual CCOSyncObjectInt* PCGetLampIdentification (EPILamp p_eSelection);

      //## Operation: WCGetActVelocityCounts%1094803156
      //	DESCRIPTION:
      //	gets the actual wedge velocity counts
      //
      //	RETURN:
      //	actual velocity counts (wdg_act_vlc)
      virtual CCOSyncObjectInt* WCGetActVelocityCounts ();

      //## Operation: WCGetLastVelocityCounts%1094803157
      //	DESCRIPTION:
      //	gets the last wedge velocity counts
      //
      //	RETURN:
      //	last velocity counts (wdg_last_vlc)
      virtual CCOSyncObjectInt* WCGetLastVelocityCounts ();

      //## Operation: WCGetPosition%1094803158
      //	DESCRIPTION:
      //	gets the wedge position
      //
      //	RETURN:
      //	position (wdg_pos_vlc)
      virtual CCOSyncObjectInt* WCGetPosition ();

      //## Operation: WCInitializeDAC%1094803159
      //	DESCRIPTION:
      //	initialize the wedge control DAC
      virtual CCOSyncObject* WCInitializeDAC ();

      //## Operation: WCSetDACValue%1094803160
      //	DESCRIPTION:
      //	sets the DAC wedge value
      //
      //	INPUT:
      //	DAC value
      virtual CCOSyncObject* WCSetDACValue (DWORD p_dwDACValue);

      //## Operation: ReadFpgaArtNr%1094803162
      //	DESCRIPTION:
      //	reads the FPGA software article number from the FPGA
      //
      //	RETURN:
      //	Article Number e.g. "045400"
      virtual CCOSyncObjectCString* ReadFpgaArtNr ();

      //## Operation: ReadFpgaSwVersion%1094803163
      //	DESCRIPTION:
      //	reads the FPGA softwareversion from the FPGA
      //
      //	RETURN:
      //	Version e.g. ""
      virtual CCOSyncObjectCString* ReadFpgaSwVersion ();

      //## Operation: I2CEpromByteRead%1094803164
      //	DESCRIPTION
      //	Reads a byte from the specific eprom address
      //
      //	RETURNS
      //	async int
      virtual CCOSyncObjectInt* I2CEpromByteRead (DWORD p_uiObjID, WORD p_uiAddress);

      //## Operation: I2CEpromByteWrite%1094803166
      //	DESCRIPTION
      //	writes a byte to the specific eprom address
      virtual CCOSyncObject* I2CEpromByteWrite (DWORD p_uiObjID, WORD p_uiAddress, BYTE p_cValue);

      //## Operation: GetDigitsLaserLevelDetection%1097650515
      //	DESCRIPTION:
      //	gets the Digits from the Laser Level Detection ADC
      //
      //
      //	RETURN:
      //	ADC Digits
      virtual CCOSyncObjectInt* GetDigitsLaserLevelDetection ();

      //## Operation: ReleaseHWReset%1097650516
      //	DESCRIPTION:
      //	release hardware reset (over hardware watchdog)
      virtual CCOSyncObject* ReleaseHWReset ();

      //## Operation: DisableWatchdog%1097650517
      //	DESCRIPTION:
      //	disables hardware watchdog
      virtual CCOSyncObject* DisableWatchdog ();

      //## Operation: GetOsVersion%1108365888
      //	DESCRIPTION:
      //	reads the Os Version
      //
      //	RETURN:
      //	Version String e.g. Major.Minor.Build.0
      virtual CCOSyncObjectCString* GetOsVersion ();

      //## Operation: GetUsedMemory%1174554258
      //	DESCRIPTION:
      //	reads the memory information
      //
      //	RETURN:
      //	available and used memory
      virtual CCOSyncObjectInt* GetUsedMemory ();

      //## Operation: GetMemoryAllocInfo%1174997741
      //	DESCRIPTION:
      //	reads the memory allocation info. Only valid in debug
      //	mode
      //
      //	RETURN:
      //	available memory allocation info
      virtual CCOSyncObjectCString* GetMemoryAllocInfo ();

    // Additional Public Declarations
      //## begin CDIDiagnosticInterface%3E198CAE029B.public preserve=yes
      //## end CDIDiagnosticInterface%3E198CAE029B.public

  protected:
    // Additional Protected Declarations
      //## begin CDIDiagnosticInterface%3E198CAE029B.protected preserve=yes
      //## end CDIDiagnosticInterface%3E198CAE029B.protected

  private:
    //## Constructors (generated)
      CDIDiagnosticInterface();

      CDIDiagnosticInterface(const CDIDiagnosticInterface &right);

    //## Assignment Operation (generated)
      const CDIDiagnosticInterface & operator=(const CDIDiagnosticInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CDIDiagnosticInterface &right) const;

      bool operator!=(const CDIDiagnosticInterface &right) const;

    // Data Members for Associations

      //## Association: EBDI (Diagnostics)::<unnamed>%3E19917803D3
      //## Role: CDIDiagnosticInterface::uiID%3E19917901C1
      //## begin CDIDiagnosticInterface::uiID%3E19917901C1.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CDIDiagnosticInterface::uiID%3E19917901C1.role

      //## Association: EBDI (Diagnostics)::<unnamed>%3F55D95702CE
      //## Role: CDIDiagnosticInterface::bHardwarePresent%3F55D95702D0
      //## begin CDIDiagnosticInterface::bHardwarePresent%3F55D95702D0.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bHardwarePresent;
      //## end CDIDiagnosticInterface::bHardwarePresent%3F55D95702D0.role

    // Additional Private Declarations
      //## begin CDIDiagnosticInterface%3E198CAE029B.private preserve=yes
      //## end CDIDiagnosticInterface%3E198CAE029B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CDIDiagnosticInterface%3E198CAE029B.implementation preserve=yes
      //## end CDIDiagnosticInterface%3E198CAE029B.implementation

};

//## begin CDIDiagnosticInterface%3E198CAE029B.postscript preserve=yes
//## end CDIDiagnosticInterface%3E198CAE029B.postscript

// Class CDIDiagnosticInterface 

//## begin module%3E19811A01D0.epilog preserve=yes
//## end module%3E19811A01D0.epilog


#endif
