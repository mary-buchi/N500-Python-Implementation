//## begin module%3E2279B2020D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E2279B2020D.cm

//## begin module%3E2279B2020D.cp preserve=no
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
//## end module%3E2279B2020D.cp

//## Module: EBHIintf%3E2279B2020D; Package specification
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Source file: R:\Embedded\src\EBHI\EBHIintf.h

#ifndef EBHIintf_h
#define EBHIintf_h 1

//## begin module%3E2279B2020D.additionalIncludes preserve=no
//## end module%3E2279B2020D.additionalIncludes

//## begin module%3E2279B2020D.includes preserve=yes
//## end module%3E2279B2020D.includes

// EBCOvers
#include "EBCOvers.h"
// EBPIenum
#include "EBPIenum.h"
// EBPItype
#include "EBPItype.h"
// EBHIenum
#include "EBHIenum.h"

class EBCO_DLL_DECL CCOSyncObject;
class EBHI_DLL_DECL CHIInterface;
class CHIProcessNodeConfig;
struct CHIIOCEventMasks;
class CHIIOCSetWCConfiguration;
class CHIIOCSetWCProfile;

//## begin module%3E2279B2020D.declarations preserve=no
//## end module%3E2279B2020D.declarations

//## begin module%3E2279B2020D.additionalDeclarations preserve=yes
//## end module%3E2279B2020D.additionalDeclarations


//## begin IHIInterface%3E2271C40106.preface preserve=yes
//## end IHIInterface%3E2271C40106.preface

//## Class: IHIInterface%3E2271C40106
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E22CDA1027B;CHIInterface { -> F}
//## Uses: <unnamed>%3F93A0E901A7;EPIRegisterType { -> }
//## Uses: <unnamed>%3F9D2FE50119;EHIStaticObjID { -> }

class EBHI_DLL_DECL IHIInterface 
{
  //## begin IHIInterface%3E2271C40106.initialDeclarations preserve=yes
  //## end IHIInterface%3E2271C40106.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: IHIInterface%1042447542
      IHIInterface (const CString& p_sSubsystemID);

    //## Destructor (generated)
      virtual ~IHIInterface();


    //## Other Operations (specified)
      //## Operation: GetInstance%1043393618
      static IHIInterface* GetInstance ();

      //## Operation: LoadConfig%1068729291
      //	required FPGA version
      virtual CCOVersion LoadConfig (const CString& p_sXmlDocStream = *((CString*)NULL)) = 0;

      //## Operation: MCDataAcquisitionStart%1049118886
      //	DESCRIPTION:
      //	Starts the data (IFM and Laser) acquisition
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual DWORD MCDataAcquisitionStart () = 0;

      //## Operation: MCDataAcquisitionStop%1049118887
      //	DESCRIPTION:
      //	Stops the data (IFM and Laser) acquisition
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual DWORD MCDataAcquisitionStop () = 0;

      //## Operation: MCGetDataPackage%1042447545
      //	DESCRIPTION:
      //	gets a data package (IFM and Laser)
      //
      //	RETURN:
      //	Sync Obj Data Package
      virtual CPISyncObjDataPackage* MCGetDataPackage () = 0;

      //## Operation: DIReadDWord%1042447547
      //	DESCRIPTION
      //	Reads a double word from the specified PCI address
      //
      //	PARAMETER
      //	PCI read address
      virtual DWORD DIReadDWord (DWORD p_dwAddress, EPIRegisterType p_eRegisterType) = 0;

      //## Operation: DIWriteDWord%1042447548
      //	DESCRIPTION
      //	Writes a double word to the specified PCI address
      //
      //	PARAMETER
      //	PCI write address
      //	value to write to spec. address
      virtual void DIWriteDWord (DWORD p_dwAddress, DWORD p_dwValue, EPIRegisterType p_eRegisterType) = 0;

      //## Operation: WCReset%1088517552
      //	DESCRIPTION
      //	Resets the Wedge Control
      //
      //	PARAMETER
      //	-
      virtual void WCReset () = 0;

      //## Operation: WCStart%1042527960
      //	DESCRIPTION
      //	Starts the Wedge Control
      //
      //	PARAMETER
      //	-
      virtual void WCStart () = 0;

      //## Operation: WCStop%1042527961
      //	DESCRIPTION
      //	Stops the Wedge Control
      virtual CCOSyncObject* WCStop (DWORD p_dwStoppedEvent) = 0;

      //## Operation: WCSetProfile%1042527962
      //	DESCRIPTION
      //	Sets the Wedge Control Profile
      virtual void WCSetProfile (CHIIOCSetWCProfile* p_pProfile) = 0;

      //## Operation: WCSetConfiguration%1042527963
      //	DESCRIPTION
      //	Stes the Wedge Control Configuration
      virtual void WCSetConfiguration (CHIIOCSetWCConfiguration* p_pConfig) = 0;

      //## Operation: WCReferencing%1042527965
      //	DESCRIPTION
      //	Parks the Wedge Control
      virtual CCOSyncObject* WCReferencing (DWORD p_dwReferencedEvent) = 0;

      //## Operation: WCInitialize%1042527966
      //	DESCRIPTION
      //	Parks the Wedge Control
      virtual CCOSyncObject* WCInitialize (DWORD p_dwInitializedEvent) = 0;

      //## Operation: WCEmergencyStop%1068453038
      //	DESCRIPTION
      //	stops the wedge drive immediately
      //
      //	PARAMETER
      //	-
      virtual DWORD WCEmergencyStop () = 0;

      //## Operation: EnableWCIrq%1046761791
      virtual DWORD EnableWCIrq () = 0;

      //## Operation: DisableWCIrq%1046761792
      virtual DWORD DisableWCIrq () = 0;

      //## Operation: ClearWCIrq%1070368616
      virtual DWORD ClearWCIrq () = 0;

      //## Operation: TEST%1046940013
      //	DESCRIPTION
      //	Test function
      virtual void TEST (DWORD p_Test) = 0;

      //## Operation: GetDWord%1048077959
      //	DESCRIPTION
      //	gets DWORD value from the spec. identifier address
      //
      //	PARAMETER
      //	Identifier
      virtual DWORD GetDWord (DWORD p_dwObjID) = 0;

      //## Operation: SetDWord%1048077960
      //	DESCRIPTION
      //	sets a DWORD value at the spec. identifier address
      //
      //	PARAMETER
      //	- Identifier
      //	- Value
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual DWORD SetDWord (DWORD p_dwObjID, DWORD p_dwValue) = 0;

      //## Operation: SetDataValid%1060343697
      //	DESCRIPTION
      //	sets a data valid bit
      //
      //	PARAMETER
      //	- Identifier
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual BOOL SetDataValid (DWORD p_dwObjID) = 0;

      //## Operation: OpenEvent%1048077963
      //	DESCRIPTION
      //	open a event. If a digital In-/Output has changed a sync
      //	object is set.
      //
      //	INPUT:
      //	- identifier of the spec. In-/Output
      //	- notification kind (high active, low active etc.)
      virtual CCOSyncObject* OpenEvent (DWORD p_dwObjID, EHIOpenEventRegistration p_eRegistration) = 0;

      //## Operation: CloseEvent%1048077964
      //	DESCRIPTION
      //	closes the spec event.
      virtual void CloseEvent (DWORD p_dwObjID, CCOSyncObject* p_pSyncObj) = 0;

      //## Operation: DebugGetEvents%1051517664
      virtual CCOSyncObjectArray* DebugGetEvents (DWORD p_dwID) = 0;

      //## Operation: DebugSetEvents%1056632009
      virtual void DebugSetEvents (DWORD p_dwObjID) = 0;

      //## Operation: TESTSetData%1052718393
      //	DESCRIPTION
      //	Test function
      virtual void TESTSetData (DWORD p_Test = 0) = 0;

      //## Operation: GetNodeMap%1053584950
      //	DESCRIPTION
      //	Test function
      virtual CMap<DWORD, DWORD&, CHIProcessNodeConfig *, CHIProcessNodeConfig *&>& GetNodeMap () = 0;

      //## Operation: GetIdMap%1063107744
      virtual CMap<DWORD, DWORD&, DWORD, DWORD&>& GetIdMap () = 0;

      //## Operation: EnableEventSignalisation%1066028222
      //	DESCRIPTION
      //	enables the event signalisation (open events)
      virtual CCOSyncObject* EnableEventSignalisation () = 0;

      //## Operation: DisableEventSignalisation%1066028224
      //	DESCRIPTION
      //	disables the event signalisation (open events)
      virtual CCOSyncObject* DisableEventSignalisation () = 0;

      //## Operation: GetStaticObjID%1067255366
      //	DESCRIPTION
      //	Returns the object identification of the specified,
      //	static hardware object (used by the core system)
      virtual DWORD GetStaticObjID (EHIStaticObjID p_eStaticObjID) = 0;

      //## Operation: WCGetActVelocityCounts%1068453044
      //	DESCRIPTION:
      //	gets the actual wedge velocity counts
      //
      //	RETURN:
      //	actual velocity counts (wdg_act_vlc)
      virtual CCOSyncObjectInt* WCGetActVelocityCounts () = 0;

      //## Operation: WCGetLastVelocityCounts%1068453045
      //	DESCRIPTION:
      //	gets the last wedge velocity counts
      //
      //	RETURN:
      //	last velocity counts (wdg_last_vlc)
      virtual CCOSyncObjectInt* WCGetLastVelocityCounts () = 0;

      //## Operation: WCGetPosition%1068453046
      //	DESCRIPTION:
      //	gets the wedge position
      //
      //	RETURN:
      //	position (wdg_pos_vlc)
      virtual CCOSyncObjectInt* WCGetPosition () = 0;

      //## Operation: WCGetLightBarrierState%1068453050
      //	DESCRIPTION:
      //	gets the state of the light barrier LB (wedge drive)
      //
      //	RETURN:
      //	state LB
      virtual CCOSyncObjectInt* WCGetLightBarrierState () = 0;

      //## Operation: WCInitializeDAC%1068530377
      //	DESCRIPTION:
      //	initialize the wedge control DAC
      virtual CCOSyncObject* WCInitializeDAC () = 0;

      //## Operation: WCCalibrateDAC%1069249957
      //	DESCRIPTION:
      //	calibrate the wedge control DAC
      //
      //	RETURN:
      //	Calibrated DAC offset Value
      //
      //	UNIT:
      //	[DAC Counts]
      virtual CCOSyncObjectInt* WCCalibrateDAC () = 0;

      //## Operation: WCSetDACValue%1068453047
      //	DESCRIPTION:
      //	sets the DAC wedge value
      //
      //	INPUT:
      //	DAC value
      virtual void WCSetDACValue (DWORD p_dwDACValue) = 0;

      //## Operation: WCControllerON%1068453048
      //	DESCRIPTION:
      //	switchs the wedge controller on
      //
      //	INPUT:
      //	1: controller ON
      //	0: controller OFF
      virtual CCOSyncObject* WCControllerON (DWORD p_dwFlag) = 0;

      //## Operation: MaskHWEvent%1069662405
      //	DESCRIPTION:
      //	mask the HW or WC event register. The specified event
      //	will not be signaled!
      //
      //	PARAMETER
      //	- Event Identifier
      //	- Event Type (Hardware or Wedge Control)
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual DWORD MaskHWEvent (DWORD p_dwLogEventID, EHIEventMaskType p_eType) = 0;

      //## Operation: UnMaskHWEvent%1069662406
      //	DESCRIPTION:
      //	unmask the HW or WC event register. The specified event
      //	will be signaled!
      //
      //	PARAMETER
      //	- Event Identifier
      //	- Event Type (Hardware or Wedge Control)
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual DWORD UnMaskHWEvent (DWORD p_dwLogEventID, EHIEventMaskType p_eType) = 0;

      //## Operation: NotifyWCISRtoSendEvent%1070368618
      //	DESCRIPTION:
      //	notify the ISR to send an event
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual DWORD NotifyWCISRtoSendEvent () = 0;

      //## Operation: GetI2CWriteStartAdr%1071824386
      //	DESCRIPTION:
      //	gets the start address of the I2C write register
      //	(process image)
      //
      //	RETURN:
      //	start adr I2C process image write register
      virtual DWORD* GetI2CWriteStartAdr () = 0;

      //## Operation: GetI2CReadStartAdr%1071824387
      //	DESCRIPTION:
      //	gets the start address of the I2C read register (process
      //	image)
      //
      //	RETURN:
      //	start adr I2C process image read register
      virtual DWORD* GetI2CReadStartAdr () = 0;

      //## Operation: GetNumberOfWCScan%1073285405
      //	DESCRIPTION:
      //	gets the number of actual scan
      //
      //	RETURN:
      //	number of scan
      virtual CCOSyncObjectInt* GetNumberOfWCScan () = 0;

      //## Operation: GetCurrentLaserLevelDetection%1073998354
      //	DESCRIPTION:
      //	gets the actual current of the laser level detecion
      //
      //	RETURN:
      //	[uA]
      virtual double GetCurrentLaserLevelDetection () = 0;

      //## Operation: GetDigitsLaserLevelDetection%1097650514
      //	DESCRIPTION:
      //	gets the actual current of the laser level detecion
      //
      //	RETURN:
      //	async int
      //	[Digits]
      virtual CCOSyncObjectInt* GetDigitsLaserLevelDetection () = 0;

      //## Operation: GetHWExceptionErrorCode%1074258761
      //	DESCRIPTION:
      //	gets the last HW exception error code
      //
      //	RETURN:
      //	HW Error Code
      virtual DWORD GetHWExceptionErrorCode () = 0;

      //## Operation: SetHWExceptionEventNr%1074582786
      //	DESCRIPTION:
      //	sets the HW exception event number
      virtual void SetHWExceptionEventNr (DWORD p_dwExceptionEventNr) = 0;

      //## Operation: ReadFpgaArtNr%1076322544
      //	DESCRIPTION:
      //	reads the FPGA software article number from the FPGA
      //
      //	RETURN:
      //	Article Number e.g. "045400"
      virtual CCOSyncObjectCString* ReadFpgaArtNr () = 0;

      //## Operation: ReadFpgaSwVersion%1076322545
      //	DESCRIPTION:
      //	reads the FPGA softwareversion from the FPGA
      //
      //	RETURN:
      //	Version e.g. ""
      virtual CCOSyncObjectCString* ReadFpgaSwVersion () = 0;

      //## Operation: SetNewStreamBufferSize%1085576034
      //	DESCRIPTION:
      //	sets a new stream buffer size
      //
      //	RETURN:
      //	async void
      virtual CCOSyncObject* SetNewStreamBufferSize (DWORD p_dwSize) = 0;

      //## Operation: DisableWatchdog%1085723666
      //	DESCRIPTION:
      //	disable the hardware watchdog
      //
      //	RETURN:
      //	-
      virtual void DisableWatchdog () = 0;

      //## Operation: EnableWatchdog%1085723667
      //	DESCRIPTION:
      //	release hardware reset
      //
      //	RETURN:
      //	-
      virtual void EnableWatchdog (EHIWatchDogTime p_eWatchdog) = 0;

      //## Operation: PCSetNomVoltage%1094799186
      //	DESCRIPTION:
      //	sets the nominal voltage for the primary or secondary
      //	lamp
      //
      //	select lamp (primary or secondary first with function
      //	PCLampSelection
      //
      //	INPUT:
      //	DAC value
      virtual void PCSetNomVoltage (DWORD p_dwDACValue) = 0;

      //## Operation: PCLampSelection%1094799187
      //	DESCRIPTION:
      //	selects the primary or secondary lamp
      //
      //
      //	INPUT:
      //	 - EPILamp
      virtual void PCLampSelection (EPILamp p_eSelection) = 0;

      //## Operation: PCLampOnOff%1094799188
      //	DESCRIPTION:
      //	primary or secondary lamp On / Off
      //
      //	INPUT:
      //	false: OFF default
      //	true:  ON
      virtual void PCLampOnOff (bool p_bSelection = false) = 0;

      //## Operation: PCGetActCurrent%1094799189
      //	DESCRIPTION:
      //	gets the actual current from the selected lamp (primary
      //	or secondary)
      //
      //	RETURN:
      //	actual current
      virtual CCOSyncObjectInt* PCGetActCurrent () = 0;

      //## Operation: PCGetActVoltage%1094799190
      //	DESCRIPTION:
      //	gets the actual voltage from the selected lamp (primary
      //	or secondary)
      //
      //	INPUT:
      //	 - EPILamp
      //
      //	RETURN:
      //	actual voltage
      virtual CCOSyncObjectInt* PCGetActVoltage (EPILamp p_eSelection) = 0;

      //## Operation: PCGetLampIdentification%1094799191
      //	DESCRIPTION:
      //	gets the selected lamp identification (primary or
      //	secondary)
      //
      //	INPUT:
      //	 - EPILamp
      //
      //	RETURN:
      //	lamp identification
      virtual CCOSyncObjectInt* PCGetLampIdentification (EPILamp p_eSelection) = 0;

      //## Operation: GetLogicalID%1096438041
      virtual DWORD GetLogicalID (DWORD p_dwID) = 0;

      //## Operation: AcknowledgeEventSignalisation%1101976961
      //	DESCRIPTION
      //	Acknowledge the ISR event signalisation
      virtual bool AcknowledgeEventSignalisation () = 0;

      //## Operation: GetsXMLVersion%1105025575
      virtual CString GetsXMLVersion () = 0;

      //## Operation: GetOsVersion%1108550311
      //	DESCRIPTION:
      //	reads the WinCE OS version
      //
      //	RETURN:
      //	OS Version Major.Minor.Build.0 e.g 5.0.1400.0
      virtual CCOSyncObjectCString* GetOsVersion () = 0;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwWCIrqNumber%3E63337002CE
      const DWORD GetdwWCIrqNumber () const;
      void SetdwWCIrqNumber (DWORD value);

    // Additional Public Declarations
      //## begin IHIInterface%3E2271C40106.public preserve=yes
      //## end IHIInterface%3E2271C40106.public

  protected:
    // Additional Protected Declarations
      //## begin IHIInterface%3E2271C40106.protected preserve=yes
      //## end IHIInterface%3E2271C40106.protected

  private:
    //## Constructors (generated)
      IHIInterface();

      IHIInterface(const IHIInterface &right);

    //## Assignment Operation (generated)
      const IHIInterface & operator=(const IHIInterface &right);

    //## Equality Operations (generated)
      bool operator==(const IHIInterface &right) const;

      bool operator!=(const IHIInterface &right) const;

    // Data Members for Class Attributes

      //## begin IHIInterface::dwWCIrqNumber%3E63337002CE.attr preserve=no  public: DWORD {U} 0
      DWORD m_dwWCIrqNumber;
      //## end IHIInterface::dwWCIrqNumber%3E63337002CE.attr

    // Additional Private Declarations
      //## begin IHIInterface%3E2271C40106.private preserve=yes
      //LPVOID m_pVa; 
      //LPVOID m_pPa;
      static const DWORD  m_cStreamBufferSize;
      //## end IHIInterface%3E2271C40106.private
  private: //## implementation
    // Additional Implementation Declarations
      //## begin IHIInterface%3E2271C40106.implementation preserve=yes
      //## end IHIInterface%3E2271C40106.implementation

};

//## begin IHIInterface%3E2271C40106.postscript preserve=yes
//## end IHIInterface%3E2271C40106.postscript

//## begin CHIInterface%3E2271DE02EA.preface preserve=yes
//## end CHIInterface%3E2271DE02EA.preface

//## Class: CHIInterface%3E2271DE02EA
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E22CCEF01BF;HI_IDENTIFIERS { -> }
//## Uses: <unnamed>%3E24082700BE;CPIWedgeControlConfig { -> F}
//## Uses: <unnamed>%3E240829037D;CPIWedgeControlProfile { -> F}
//## Uses: <unnamed>%3E26CF1A006B;CHIIOCWriteDWord { -> }
//## Uses: <unnamed>%3E3142770117;CHIIOCSetWCConfiguration { -> F}
//## Uses: <unnamed>%3E31427A001D;CHIIOCSetWCProfile { -> F}
//## Uses: <unnamed>%3E364E430196;XHIExceptionError { -> }
//## Uses: <unnamed>%3E59F7D2004E;CHIReservedSharedMemory { -> }
//## Uses: <unnamed>%3E5E0E5801D4;CCOSyncObject { -> F}
//## Uses: <unnamed>%3E67499C0261;CHITReservedSharedMemory { -> }
//## Uses: <unnamed>%3E6C5F480232;CHIMCParameter { -> }
//## Uses: <unnamed>%3E6E08BC0271;CPISyncObjDataPackage { -> }
//## Uses: <unnamed>%3E6EDA4803C8;CHIEventWorkerThread { -> }
//## Uses: <unnamed>%3E894149004E;EHIOpenEventRegistration { -> }
//## Uses: <unnamed>%3E9BCADF02BF;CHIEventWorkerThread { -> }
//## Uses: <unnamed>%3F54618B036B;HI_PCINTF_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F5DBC9502FD;CPIComponentsState { -> }
//## Uses: <unnamed>%3FB39F2E0011;CCOMarkup { -> }
//## Uses: <unnamed>%406C25CE0301;CCOVersion { -> }
//## Uses: <unnamed>%4141509B02BF;EPILamp { -> }

class EBHI_DLL_DECL CHIInterface : public IHIInterface  //## Inherits: <unnamed>%3E2271EE00E6
{
  //## begin CHIInterface%3E2271DE02EA.initialDeclarations preserve=yes
  //## end CHIInterface%3E2271DE02EA.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CHIInterface%1042447564
      CHIInterface (UINT p_uiID);

    //## Destructor (generated)
      virtual ~CHIInterface();


    //## Other Operations (specified)
      //## Operation: Create%1042447561
      static void Create ();

      //## Operation: Delete%1042447562
      static void Delete ();

      //## Operation: GetInstance%1043393617
      static IHIInterface* GetInstance ();

      //## Operation: WCReset%1088517551
      //	DESCRIPTION
      //	Resets the Wedge Control
      //
      //	PARAMETER
      //	-
      virtual void WCReset ();

      //## Operation: WCEmergencyStop%1068453037
      //	DESCRIPTION
      //	stops the wedge drive immediately
      //
      //	PARAMETER
      //	-
      virtual DWORD WCEmergencyStop ();

      //## Operation: GetDWord%1048077957
      //	DESCRIPTION
      //	gets DWORD value from the spec. identifier address
      //
      //	PARAMETER
      //	Identifier
      virtual DWORD GetDWord (DWORD p_dwObjID);

      //## Operation: SetDWord%1048077958
      //	DESCRIPTION
      //	sets a DWORD value at the spec. identifier address
      //
      //	PARAMETER
      //	- Identifier
      //	- Value
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual DWORD SetDWord (DWORD p_dwObjID, DWORD p_dwValue);

      //## Operation: SetDataValid%1060343696
      //	DESCRIPTION
      //	sets a data valid bit
      //
      //	PARAMETER
      //	- Identifier
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual BOOL SetDataValid (DWORD p_dwObjID);

      //## Operation: OpenEvent%1048077961
      //	DESCRIPTION
      //	open a event. If a digital In-/Output has changed a sync
      //	object is set.
      //
      //	INPUT:
      //	- identifier of the spec. In-/Output
      //	- notification kind (high active, low active etc.)
      virtual CCOSyncObject* OpenEvent (DWORD p_dwObjID, EHIOpenEventRegistration p_eRegistration);

      //## Operation: CloseEvent%1048077962
      //	DESCRIPTION
      //	closes the spec event.
      virtual void CloseEvent (DWORD p_dwObjID, CCOSyncObject* p_pSyncObj);

      //## Operation: DebugGetEvents%1051517665
      virtual CCOSyncObjectArray* DebugGetEvents (DWORD p_dwID);

      //## Operation: DebugSetEvents%1056608819
      virtual void DebugSetEvents (DWORD p_dwObjID);

      //## Operation: TESTSetData%1052718392
      //	DESCRIPTION
      //	TEST function
      virtual void TESTSetData (DWORD p_Test = 0);

      //## Operation: EnableEventSignalisation%1066028223
      //	DESCRIPTION
      //	enables the event signalisation (open events)
      virtual CCOSyncObject* EnableEventSignalisation ();

      //## Operation: DisableEventSignalisation%1066028225
      //	DESCRIPTION
      //	disables the event signalisation (open events)
      virtual CCOSyncObject* DisableEventSignalisation ();

      //## Operation: ClearWCIrq%1070368615
      virtual DWORD ClearWCIrq ();

      //## Operation: GetStaticObjID%1067255365
      //	DESCRIPTION
      //	Returns the object identification of the specified,
      //	static hardware object (used by the core system)
      virtual DWORD GetStaticObjID (EHIStaticObjID p_eStaticObjID);

      //## Operation: WCGetActVelocityCounts%1068453039
      //	DESCRIPTION:
      //	gets the actual wedge velocity counts
      //
      //	RETURN:
      //	actual velocity counts (wdg_act_vlc)
      virtual CCOSyncObjectInt* WCGetActVelocityCounts ();

      //## Operation: WCGetLastVelocityCounts%1068453040
      //	DESCRIPTION:
      //	gets the last wedge velocity counts
      //
      //	RETURN:
      //	last velocity counts (wdg_last_vlc)
      virtual CCOSyncObjectInt* WCGetLastVelocityCounts ();

      //## Operation: WCGetPosition%1068453041
      //	DESCRIPTION:
      //	gets the wedge position
      //
      //	RETURN:
      //	position (wdg_pos_vlc)
      virtual CCOSyncObjectInt* WCGetPosition ();

      //## Operation: WCInitializeDAC%1068530376
      //	DESCRIPTION:
      //	initialize the wedge control DAC
      virtual CCOSyncObject* WCInitializeDAC ();

      //## Operation: WCSetDACValue%1068453042
      //	DESCRIPTION:
      //	sets the DAC wedge value
      //
      //	INPUT:
      //	DAC value
      virtual void WCSetDACValue (DWORD p_dwDACValue);

      //## Operation: WCControllerON%1068453043
      //	DESCRIPTION:
      //	switchs the wedge controller on
      //
      //	INPUT:
      //	1: controller ON
      //	0: controller OFF
      virtual CCOSyncObject* WCControllerON (DWORD p_dwFlag);

      //## Operation: WCGetLightBarrierState%1068453049
      //	DESCRIPTION:
      //	gets the state of the light barrier LB (wedge drive)
      //
      //	RETURN:
      //	state LB
      virtual CCOSyncObjectInt* WCGetLightBarrierState ();

      //## Operation: LoadConfig%1068729290
      //	returns the minimum FPGA version
      CCOVersion LoadConfig (const CString& p_sXmlDocStream = *((CString*)NULL));

      //## Operation: WCCalibrateDAC%1069249956
      //	DESCRIPTION:
      //	calibrate the wedge control DAC
      //
      //	RETURN:
      //	Calibrated DAC offset Value
      //
      //	UNIT:
      //	[DAC Counts]
      virtual CCOSyncObjectInt* WCCalibrateDAC ();

      //## Operation: MaskHWEvent%1069662407
      //	DESCRIPTION:
      //	mask the HW or WC event register. The specified event
      //	will not be signaled!
      //
      //	PARAMETER
      //	- Event Identifier
      //	- Event Type (Hardware or Wedge Control)
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual DWORD MaskHWEvent (DWORD p_dwLogEventID, EHIEventMaskType p_eType);

      //## Operation: UnMaskHWEvent%1069662408
      //	DESCRIPTION:
      //	unmask the HW or WC event register. The specified event
      //	will be signaled!
      //
      //	PARAMETER
      //	- Event Identifier
      //	- Event Type (Hardware or Wedge Control)
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual DWORD UnMaskHWEvent (DWORD p_dwLogEventID, EHIEventMaskType p_eType);

      //## Operation: NotifyWCISRtoSendEvent%1070368617
      //	DESCRIPTION:
      //	notify the ISR to send an event
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual DWORD NotifyWCISRtoSendEvent ();

      //## Operation: GetI2CWriteStartAdr%1071824383
      //	DESCRIPTION:
      //	gets the start address of the I2C write register
      //	(process image)
      //
      //	RETURN:
      //	start adr I2C process image write register
      virtual DWORD* GetI2CWriteStartAdr ();

      //## Operation: GetI2CReadStartAdr%1071824384
      //	DESCRIPTION:
      //	gets the start address of the I2C read register (process
      //	image)
      //
      //	RETURN:
      //	start adr I2C process image read register
      virtual DWORD* GetI2CReadStartAdr ();

      //## Operation: GetNumberOfWCScan%1073285404
      //	DESCRIPTION:
      //	gets the number of completed scan
      //
      //	RETURN:
      //	number of scan
      virtual CCOSyncObjectInt* GetNumberOfWCScan ();

      //## Operation: GetCurrentLaserLevelDetection%1073998353
      //	DESCRIPTION:
      //	gets the actual current of the laser detecion
      //
      //	RETURN:
      //	[uA]
      virtual double GetCurrentLaserLevelDetection ();

      //## Operation: GetDigitsLaserLevelDetection%1097650513
      //	DESCRIPTION:
      //	gets the actual current of the laser level detecion
      //
      //	RETURN:
      //	async int
      //	[Digits]
      virtual CCOSyncObjectInt* GetDigitsLaserLevelDetection ();

      //## Operation: GetHWExceptionErrorCode%1074258760
      //	DESCRIPTION:
      //	gets the last HW exception error code
      //
      //	RETURN:
      //	HW Error Code
      virtual DWORD GetHWExceptionErrorCode ();

      //## Operation: SetHWExceptionEventNr%1074582785
      //	DESCRIPTION:
      //	sets the HW exception event number
      virtual void SetHWExceptionEventNr (DWORD p_dwExceptionEventNr);

      //## Operation: GetLogicalID%1075107935
      virtual DWORD GetLogicalID (DWORD p_dwID);

      //## Operation: ReadFpgaArtNr%1076322542
      //	DESCRIPTION:
      //	reads the FPGA software article number from the FPGA
      //
      //	RETURN:
      //	Article Number e.g. "045400"
      virtual CCOSyncObjectCString* ReadFpgaArtNr ();

      //## Operation: ReadFpgaSwVersion%1076322543
      //	DESCRIPTION:
      //	reads the FPGA softwareversion from the FPGA
      //
      //	RETURN:
      //	Version e.g. ""
      virtual CCOSyncObjectCString* ReadFpgaSwVersion ();

      //## Operation: SetNewStreamBufferSize%1085576033
      //	DESCRIPTION:
      //	sets a new stream buffer size
      //
      //	RETURN:
      //	async void
      virtual CCOSyncObject* SetNewStreamBufferSize (DWORD p_dwSize);

      //## Operation: DisableWatchdog%1085723664
      //	DESCRIPTION:
      //	disable the hardware watchdog
      //
      //	RETURN:
      //	-
      virtual void DisableWatchdog ();

      //## Operation: EnableWatchdog%1085723665
      //	DESCRIPTION:
      //	release hardware reset
      //
      //	RETURN:
      //	-
      virtual void EnableWatchdog (EHIWatchDogTime p_eWatchDogTime);

      //## Operation: PCSetNomVoltage%1094799192
      //	DESCRIPTION:
      //	sets the nominal voltage for the primary or secondary
      //	lamp
      //
      //	select lamp (primary or secondary first with function
      //	PCLampSelection
      //
      //	INPUT:
      //	DAC value
      virtual void PCSetNomVoltage (DWORD p_dwDACValue);

      //## Operation: PCLampSelection%1094799193
      //	DESCRIPTION:
      //	selects the primary or secondary lamp
      //
      //
      //	INPUT:
      //	 - EPILamp
      virtual void PCLampSelection (EPILamp p_eSelection);

      //## Operation: PCLampOnOff%1094799194
      //	DESCRIPTION:
      //	primary or secondary lamp On / Off
      //
      //
      //	INPUT:
      //	false: OFF default
      //	true:  ON
      virtual void PCLampOnOff (bool p_bSelection = false);

      //## Operation: PCGetActCurrent%1094799195
      //	DESCRIPTION:
      //	gets the actual current from the selected lamp (primary
      //	or secondary)
      //
      //	RETURN:
      //	actual current
      virtual CCOSyncObjectInt* PCGetActCurrent ();

      //## Operation: PCGetActVoltage%1094799196
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

      //## Operation: PCGetLampIdentification%1094799197
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

      //## Operation: AcknowledgeEventSignalisation%1101976960
      //	DESCRIPTION
      //	Acknowledge the ISR event signalisation
      virtual bool AcknowledgeEventSignalisation ();

      //## Operation: GetOsVersion%1108550310
      //	DESCRIPTION:
      //	reads the WinCE OS version
      //
      //	RETURN:
      //	OS Version Major.Minor.Build.0 e.g 5.0.1400.0
      virtual CCOSyncObjectCString* GetOsVersion ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: bHardwarePresent%3F448E380138
      bool GetbHardwarePresent ();
      void SetbHardwarePresent (bool value);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E96C0A3009C
      //## Role: CHIInterface::NodeMap%3E96C0A3032C
      //## Constraints:
      //	ordered
      //## Qualifier: class%3E96C0C60251; DWORD
      virtual CMap<DWORD, DWORD&, CHIProcessNodeConfig *, CHIProcessNodeConfig *&>& GetNodeMap ();

      //## Association: EBHI (Hardware Interface)::<unnamed>%3EB669D20213
      //## Role: CHIInterface::dwLogNrDigIOArray%3EB669D3000F
      //## Constraints:
      //	ordered
      CArray<DWORD,DWORD>& GetdwLogNrDigIOArray ();

      //## Association: EBHI (Hardware Interface)::<unnamed>%3ECCC4190242
      //## Role: CHIInterface::dwLogNrWCEventArray%3ECCC41A0148
      //## Constraints:
      //	ordered
      CArray<DWORD,DWORD>& GetdwLogNrWCEventArray ();

      //## Association: EBHI (Hardware Interface)::<unnamed>%3ECCC5020232
      //## Role: CHIInterface::dwLogNrHWExceptionArray%3ECCC5030157
      //## Constraints:
      //	ordered
      CArray<DWORD,DWORD>& GetdwLogNrHWExceptionArray ();

      //## Association: EBHI (Hardware Interface)::<unnamed>%3EF99742031C
      //## Role: CHIInterface::IdMap%3EF997440000
      //## Constraints:
      //	ordered
      //## Qualifier: class%3EF998D9002E; DWORD
      virtual CMap<DWORD, DWORD&, DWORD, DWORD&>& GetIdMap ();

      //## Association: EBHI (Hardware Interface)::<unnamed>%41DD59F5012A
      //## Role: CHIInterface::sXMLVersion%41DD59F50365
      CString GetsXMLVersion ();

    // Data Members for Associations

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E96C0A3009C
      //## begin CHIInterface::NodeMap%3E96C0A3032C.role preserve=no  public: CHIProcessNodeConfig { -> 1RFHON}
      CMap<DWORD, DWORD&, CHIProcessNodeConfig *, CHIProcessNodeConfig *&> m_NodeMap;
      //## end CHIInterface::NodeMap%3E96C0A3032C.role

    // Additional Public Declarations
      //## begin CHIInterface%3E2271DE02EA.public preserve=yes
      //## end CHIInterface%3E2271DE02EA.public

  protected:
    // Additional Protected Declarations
      //## begin CHIInterface%3E2271DE02EA.protected preserve=yes
      //## end CHIInterface%3E2271DE02EA.protected

  private:
    //## Constructors (generated)
      CHIInterface();

      CHIInterface(const CHIInterface &right);

    //## Assignment Operation (generated)
      const CHIInterface & operator=(const CHIInterface &right);

    //## Equality Operations (generated)
      bool operator==(const CHIInterface &right) const;

      bool operator!=(const CHIInterface &right) const;


    //## Other Operations (specified)
      //## Operation: Initialize%1042447565
      void Initialize ();

      //## Operation: DeInitialize%1042645876
      void DeInitialize ();

      //## Operation: ReadWCIrqNumber%1046687700
      DWORD ReadWCIrqNumber ();

      //## Operation: MCDataAcquisitionStart%1049118884
      //	DESCRIPTION:
      //	Starts the data (IFM and Laser) acquisition
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual DWORD MCDataAcquisitionStart ();

      //## Operation: MCDataAcquisitionStop%1049118885
      //	DESCRIPTION:
      //	Stops the data (IFM and Laser) acquisition
      //
      //	RETURN:
      //	Nonzero if the operation is successful otherwise, it is
      //	0.
      virtual DWORD MCDataAcquisitionStop ();

      //## Operation: MCGetDataPackage%1042447549
      virtual CPISyncObjDataPackage* MCGetDataPackage ();

      //## Operation: DIReadDWord%1042447559
      //	DESCRIPTION
      //	Reads a double word from the specified PCI address
      //
      //
      //	PARAMETER
      //	PCI read address
      virtual DWORD DIReadDWord (DWORD p_dwAddress, EPIRegisterType p_eRegisterType);

      //## Operation: DIWriteDWord%1042447560
      //	DESCRIPTION
      //	Writes a double word to the specified PCI address
      //
      //	PARAMETER
      //	PCI write address
      //	value to write to spec. address
      virtual void DIWriteDWord (DWORD p_dwAddress, DWORD p_dwValue, EPIRegisterType p_eRegisterType);

      //## Operation: WCStart%1042527953
      //	DESCRIPTION
      //	Starts the Wedge Control
      //
      //
      //	PARAMETER
      //	-
      virtual void WCStart ();

      //## Operation: WCStop%1042527954
      //	DESCRIPTION
      //	Stops the Wedge Control
      virtual CCOSyncObject* WCStop (DWORD p_dwStoppedEvent);

      //## Operation: WCSetProfile%1042527955
      //	DESCRIPTION
      //	Sets the Wedge Control Profile
      virtual void WCSetProfile (CHIIOCSetWCProfile* p_pProfile);

      //## Operation: WCSetConfiguration%1042527956
      //	DESCRIPTION
      //	Stes the Wedge Control Configuration
      virtual void WCSetConfiguration (CHIIOCSetWCConfiguration* p_pConfig);

      //## Operation: WCReferencing%1042527958
      //	DESCRIPTION
      //	Parks the Wedge Control
      virtual CCOSyncObject* WCReferencing (DWORD p_dwReferencedEvent);

      //## Operation: EnableWCIrq%1046761789
      virtual DWORD EnableWCIrq ();

      //## Operation: DisableWCIrq%1046761790
      virtual DWORD DisableWCIrq ();

      //## Operation: TEST%1046940012
      //	DESCRIPTION
      //	TEST function
      virtual void TEST (DWORD p_Test);

      //## Operation: WCInitialize%1042527959
      //	DESCRIPTION
      //	Parks the Wedge Control
      virtual CCOSyncObject* WCInitialize (DWORD p_dwInitializedEvent);

      //## Operation: SetNodeConfig%1050303226
      void SetNodeConfig (DWORD p_dwLogID = 0, DWORD p_dwAdrOffset = 0, DWORD p_dwIndex = 0);

      //## Operation: GetNodeConfig%1050303227
      CHIProcessNodeConfig* GetNodeConfig (DWORD p_dwLogID = 0);

    // Data Members for Class Attributes

      //## begin CHIInterface::bHardwarePresent%3F448E380138.attr preserve=no  public: bool {U} 
      bool m_bHardwarePresent;
      //## end CHIInterface::bHardwarePresent%3F448E380138.attr

    // Data Members for Associations

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E2285660142
      //## Role: CHIInterface::pInstance%3E22856A0182
      //## begin CHIInterface::pInstance%3E22856A0182.role preserve=no  public: static CHIInterface {1..1 -> 1..1RFHN}
      static CHIInterface *m_pInstance;
      //## end CHIInterface::pInstance%3E22856A0182.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E22BE9601CF
      //## Role: CHIInterface::uiID%3E22BE97000B
      //## begin CHIInterface::uiID%3E22BE97000B.role preserve=no  public: UINT {1..1 -> 1..1VFHN}
      UINT m_uiID;
      //## end CHIInterface::uiID%3E22BE97000B.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E2583510259
      //## Role: CHIInterface::pVa%3E258352017F
      //## begin CHIInterface::pVa%3E258352017F.role preserve=no  public: LPVOID {1..1 -> 1..1VFHN}
      LPVOID m_pVa;
      //## end CHIInterface::pVa%3E258352017F.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E2583DD017E
      //## Role: CHIInterface::pPa%3E2583DD03B2
      //## begin CHIInterface::pPa%3E2583DD03B2.role preserve=no  public: LPVOID {1..1 -> 1..1VFHN}
      LPVOID m_pPa;
      //## end CHIInterface::pPa%3E2583DD03B2.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E265378010C
      //## Role: CHIInterface::dwPageSize%3E26537803CC
      //## begin CHIInterface::dwPageSize%3E26537803CC.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwPageSize;
      //## end CHIInterface::dwPageSize%3E26537803CC.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E2653B5008F
      //## Role: CHIInterface::dwNumberOfPages%3E2653B503BD
      //## begin CHIInterface::dwNumberOfPages%3E2653B503BD.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwNumberOfPages;
      //## end CHIInterface::dwNumberOfPages%3E2653B503BD.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E26587D0003
      //## Role: CHIInterface::hPCIDevice%3E26587D038D
      //## begin CHIInterface::hPCIDevice%3E26587D038D.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hPCIDevice;
      //## end CHIInterface::hPCIDevice%3E26587D038D.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3E2663E802B2
      //## Role: CHIInterface::hPCIFile%3E2663E90206
      //## begin CHIInterface::hPCIFile%3E2663E90206.role preserve=no  public: HANDLE {1..1 -> 1..1VFHN}
      HANDLE m_hPCIFile;
      //## end CHIInterface::hPCIFile%3E2663E90206.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3EB669D20213
      //## begin CHIInterface::dwLogNrDigIOArray%3EB669D3000F.role preserve=no  public: DWORD { -> 0..32VFHON}
      CArray<DWORD,DWORD> m_dwLogNrDigIOArray;
      //## end CHIInterface::dwLogNrDigIOArray%3EB669D3000F.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3EBB98DD02BF
      //## Role: CHIInterface::AccessLock%3EBB98DE01B5
      //## begin CHIInterface::AccessLock%3EBB98DE01B5.role preserve=no  public: CCriticalSection {1..1 -> 1..1VFHN}
      CCriticalSection m_AccessLock;
      //## end CHIInterface::AccessLock%3EBB98DE01B5.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3ECCC4190242
      //## begin CHIInterface::dwLogNrWCEventArray%3ECCC41A0148.role preserve=no  public: DWORD { -> 0..32VFHON}
      CArray<DWORD,DWORD> m_dwLogNrWCEventArray;
      //## end CHIInterface::dwLogNrWCEventArray%3ECCC41A0148.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3ECCC5020232
      //## begin CHIInterface::dwLogNrHWExceptionArray%3ECCC5030157.role preserve=no  public: DWORD { -> 0..32VFHON}
      CArray<DWORD,DWORD> m_dwLogNrHWExceptionArray;
      //## end CHIInterface::dwLogNrHWExceptionArray%3ECCC5030157.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3EF99742031C
      //## begin CHIInterface::IdMap%3EF997440000.role preserve=no  public: DWORD {1..1 -> 1VFHON}
      CMap<DWORD, DWORD&, DWORD, DWORD&> m_IdMap;
      //## end CHIInterface::IdMap%3EF997440000.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3EFAA440006D
      //## Role: CHIInterface::TestProcImMap%3EFAA4410000
      //## Constraints:
      //	ordered
      //## Qualifier: class%3EFAA46603C8; DWORD
      //## begin CHIInterface::TestProcImMap%3EFAA4410000.role preserve=no  public: DWORD {1..1 -> 1VFHON}
      CMap<DWORD, DWORD&, DWORD, DWORD&> m_TestProcImMap;
      //## end CHIInterface::TestProcImMap%3EFAA4410000.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%3FCDD1000290
      //## Role: CHIInterface::pEventMask%3FCDD1010186
      //## begin CHIInterface::pEventMask%3FCDD1010186.role preserve=no  public: static CHIIOCEventMasks {1..1 -> 1..1RFHN}
      static CHIIOCEventMasks *m_pEventMask;
      //## end CHIInterface::pEventMask%3FCDD1010186.role

      //## Association: EBHI (Hardware Interface)::<unnamed>%41DD59F5012A
      //## begin CHIInterface::sXMLVersion%41DD59F50365.role preserve=no  public: CString {1..1 -> 1..1VFHN}
      CString m_sXMLVersion;
      //## end CHIInterface::sXMLVersion%41DD59F50365.role

    // Additional Private Declarations
      //## begin CHIInterface%3E2271DE02EA.private preserve=yes
      //## end CHIInterface%3E2271DE02EA.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIInterface%3E2271DE02EA.implementation preserve=yes
      //## end CHIInterface%3E2271DE02EA.implementation

};

//## begin CHIInterface%3E2271DE02EA.postscript preserve=yes
//## end CHIInterface%3E2271DE02EA.postscript

//## begin CHIProcessNodeConfig%3E96C03C034B.preface preserve=yes
//## end CHIProcessNodeConfig%3E96C03C034B.preface

//## Class: CHIProcessNodeConfig%3E96C03C034B
//## Category: EBHI (Hardware Interface)%3E22670202FA
//## Subsystem: EBHI (Hardware Interface)%3E22667D00C7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CHIProcessNodeConfig 
{
  //## begin CHIProcessNodeConfig%3E96C03C034B.initialDeclarations preserve=yes
  //## end CHIProcessNodeConfig%3E96C03C034B.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CHIProcessNodeConfig%1050062593
      CHIProcessNodeConfig (DWORD p_dwAdrOffset = 0, DWORD p_dwIndex = 0);

    //## Destructor (generated)
      virtual ~CHIProcessNodeConfig();


    //## Other Operations (specified)
      //## Operation: GetAddress%1050062594
      DWORD* GetAddress ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: dwAdrOffset%3E96C5CF0128
      DWORD GetdwAdrOffset ();

      //## Attribute: dwIndex%3E96C629034B
      DWORD GetdwIndex ();

    // Additional Public Declarations
      //## begin CHIProcessNodeConfig%3E96C03C034B.public preserve=yes
      //## end CHIProcessNodeConfig%3E96C03C034B.public

  protected:
    // Additional Protected Declarations
      //## begin CHIProcessNodeConfig%3E96C03C034B.protected preserve=yes
      //## end CHIProcessNodeConfig%3E96C03C034B.protected

  private:
    //## Constructors (generated)
      CHIProcessNodeConfig(const CHIProcessNodeConfig &right);

    //## Assignment Operation (generated)
      const CHIProcessNodeConfig & operator=(const CHIProcessNodeConfig &right);

    //## Equality Operations (generated)
      bool operator==(const CHIProcessNodeConfig &right) const;

      bool operator!=(const CHIProcessNodeConfig &right) const;

    // Data Members for Class Attributes

      //## begin CHIProcessNodeConfig::dwAdrOffset%3E96C5CF0128.attr preserve=no  public: DWORD {U} p_dwAdrOffset
      DWORD m_dwAdrOffset;
      //## end CHIProcessNodeConfig::dwAdrOffset%3E96C5CF0128.attr

      //## begin CHIProcessNodeConfig::dwIndex%3E96C629034B.attr preserve=no  public: DWORD {U} p_dwIndex
      DWORD m_dwIndex;
      //## end CHIProcessNodeConfig::dwIndex%3E96C629034B.attr

      //## Attribute: eDataType%3EB65A7F0232
      //## begin CHIProcessNodeConfig::eDataType%3EB65A7F0232.attr preserve=no  public: EHIProcessImageDataType {U} eHIDWORD
      EHIProcessImageDataType m_eDataType;
      //## end CHIProcessNodeConfig::eDataType%3EB65A7F0232.attr

    // Additional Private Declarations
      //## begin CHIProcessNodeConfig%3E96C03C034B.private preserve=yes
      //## end CHIProcessNodeConfig%3E96C03C034B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CHIProcessNodeConfig%3E96C03C034B.implementation preserve=yes
      //## end CHIProcessNodeConfig%3E96C03C034B.implementation

};

//## begin CHIProcessNodeConfig%3E96C03C034B.postscript preserve=yes
//## end CHIProcessNodeConfig%3E96C03C034B.postscript

// Class IHIInterface 

// Class CHIInterface 

// Class CHIProcessNodeConfig 

//## begin module%3E2279B2020D.epilog preserve=yes
//## end module%3E2279B2020D.epilog


#endif
