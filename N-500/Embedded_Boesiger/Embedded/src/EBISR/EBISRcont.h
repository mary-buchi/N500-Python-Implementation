//## begin module%3E41319D034B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3E41319D034B.cm

//## begin module%3E41319D034B.cp preserve=no
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
//## end module%3E41319D034B.cp

//## Module: EBISRcont%3E41319D034B; Package specification
//## Subsystem: EBISR (Interrupt Service Routine)%3E40DF6A00CB
//## Source file: R:\Embedded\src\EBISR\EBISRcont.h

#ifndef EBISRcont_h
#define EBISRcont_h 1

//## begin module%3E41319D034B.additionalIncludes preserve=no
//## end module%3E41319D034B.additionalIncludes

//## begin module%3E41319D034B.includes preserve=yes
//## end module%3E41319D034B.includes

// EBHITtype
#include "EBHITtype.h"
// EBISRtype
#include "EBISRtype.h"


//## begin module%3E41319D034B.declarations preserve=no
//## end module%3E41319D034B.declarations

//## begin module%3E41319D034B.additionalDeclarations preserve=yes
//## end module%3E41319D034B.additionalDeclarations


//## begin CISRWCPIDControl%3E40E116000F.preface preserve=yes
//## end CISRWCPIDControl%3E40E116000F.preface

//## Class: CISRWCPIDControl%3E40E116000F
//## Category: EBISR (Interrupt Service Routine)%3E40DF26004E
//## Subsystem: EBISR (Interrupt Service Routine)%3E40DF6A00CB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3E4228300186;EISRWCPosState { -> }
//## Uses: <unnamed>%3E42284502BF;CHIIOCSetWCConfiguration { -> }
//## Uses: <unnamed>%3E422A8500AB;CHIIOCSetWCProfile { -> }
//## Uses: <unnamed>%3EC88CD30196;CHITReservedSharedMemory { -> }
//## Uses: <unnamed>%4004143F0203;ISR_IDENTIFIERS { -> }

class CISRWCPIDControl 
{
  //## begin CISRWCPIDControl%3E40E116000F.initialDeclarations preserve=yes
  //## end CISRWCPIDControl%3E40E116000F.initialDeclarations

  public:
    //## begin CISRWCPIDControl::ISRWCNomValue%3E4207660128.preface preserve=yes
    //int CISRWCPIDControl::Test(int x);
    //## end CISRWCPIDControl::ISRWCNomValue%3E4207660128.preface

    //## Class: ISRWCNomValue%3E4207660128
    //## Category: EBISR (Interrupt Service Routine)%3E40DF26004E
    //## Subsystem: EBISR (Interrupt Service Routine)%3E40DF6A00CB
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef void (CISRWCPIDControl::* ISRWCNomValue)(void);

    //## begin CISRWCPIDControl::ISRWCNomValue%3E4207660128.postscript preserve=yes
    //## end CISRWCPIDControl::ISRWCNomValue%3E4207660128.postscript

    //## begin CISRWCPIDControl::ControllerType%3E50E65A0232.preface preserve=yes
    //## end CISRWCPIDControl::ControllerType%3E50E65A0232.preface

    //## Class: ControllerType%3E50E65A0232
    //## Category: EBISR (Interrupt Service Routine)%3E40DF26004E
    //## Subsystem: EBISR (Interrupt Service Routine)%3E40DF6A00CB
    //## Persistence: Transient
    //## Cardinality/Multiplicity: n

    typedef int ControllerType;

    //## begin CISRWCPIDControl::ControllerType%3E50E65A0232.postscript preserve=yes
    //## end CISRWCPIDControl::ControllerType%3E50E65A0232.postscript

    //## Constructors (generated)
      CISRWCPIDControl();

    //## Destructor (generated)
      virtual ~CISRWCPIDControl();

    //## Storage Management Operations (generated)
      static void * operator new(size_t size);

      static void operator delete(void *object);


    //## Other Operations (specified)
      //## Operation: WCPIDControlHandler%1044516520
      DWORD WCPIDControlHandler (DWORD p_dwWCCmd, LPVOID p_pInBufWC = NULL, DWORD p_dwInBufSizeWC = 0, LPVOID p_pOutBufWC = NULL, DWORD p_dwOutBufSizeWC = 0);

      //## Operation: WCPIDController%1045489184
      void WCPIDController ();

      //## Operation: WCPIDControllerAlgorithm%1045489183
      //	DESCRIPTION:
      //	PID Controller algorithm
      //
      //	INPUT:
      //	x_nom:      Regler Sollwert
      //	x_act:       aktueller Istwert
      //	Kp:            P-Faktor
      //	Ki:             I-Faktor
      //	Kd:            D-Faktor
      //	LimitUp:     oberes Limit - Stellwert Begrenzung DAC
      //	LimitDown: unteres Limit - Stellwert Begrenzung DAC
      //	LimitSlr:       Slew Rate Limit - d y_k / Ts
      //	Ts:              Reglertakt
      //	DACConvFactor: Computation conversion factor
      //	y_DAC_Os  DAC Offset Korrektur
      //
      //	OUTPUT:
      //	y_k:           Stellsignal (begrenzt)
      //
      //	RETURN VALUES:
      //	0:    ok
      //	1:    Stellsignal am oberen Limit
      //	2:    Stellsignal am unteren Limit
      DWORD WCPIDControllerAlgorithm (ControllerType& p_x_nom, ControllerType& p_x_act, const ControllerType& p_Kp, const ControllerType& p_Ki, const ControllerType& p_Kd, const ControllerType& p_LimitUp, const ControllerType& p_LimitDown, const ControllerType& p_LimitSlr, const ControllerType& p_Ts, const ControllerType& p_DAC_ConvFactor, const ControllerType& p_y_DAC_Os, ControllerType& p_y_k);

      //## Operation: WCGetNomValue%1044516521
      int WCGetNomValue ();

      //## Operation: WCGetLastVelocityCounts%1044873119
      //	DESCRIPTION:
      //	Reads the T-Register (Last full laser cycle duration)
      //
      //	INPUT:
      //	-
      //
      //	OUTPUT:
      //	last full laser cycle duration counts (Wdg_Last_Vlc ->
      //	wedge last velocity)
      DWORD WCGetLastVelocityCounts ();

      //## Operation: WCGetActVelocityCounts%1044873120
      //	DESCRIPTION:
      //	Reads the t-Register (time after last positiv zero cross)
      //
      //	INPUT:
      //	-
      //
      //	OUTPUT:
      //	last positiv zero cross counts
      DWORD WCGetActVelocityCounts ();

      //## Operation: WCGetActPositionCounter%1044873121
      //	DESCRIPTION:
      //	Reads the wedge position (number of positiv zero crosses)
      //
      //	OUTPUT:
      //	wedge position (number of positiv zero crosses)
      int WCGetActPositionCounter ();

      //## Operation: WCSetDACValue%1045557184
      void WCSetDACValue (DWORD p_dwDACValue = 0);

      //## Operation: WCSetDirection%1044873122
      //	DESCRIPTION:
      //	Sets the direction of the wedge control in the Control
      //	Register (d-Counter Register)
      //
      //	INPUT:
      //	wedge control direction l_dwPosition
      //	  0: indicates FORWARD direction
      //	  1: indicates BACKWARD direction
      //
      //	OUTPUT:
      //	-
      void WCSetDirection (bool p_bDirection = true);

      //## Operation: WCSetEventRegister%1053327437
      //	DESCRIPTION:
      //	Sets the events of the wedge control in the Event
      //	Register
      //	Events: Initialized, Referenced, Parked, Stopped, etc.
      //
      //	INPUT:
      //	event bit mask
      //
      //	OUTPUT:
      //	-
      void WCSetEventRegister (DWORD p_dwEventMask = 0);

      //## Operation: WCClearEventRegister%1053327438
      //	DESCRIPTION:
      //	Clear the events of the wedge control in the Event
      //	Register
      //	Events: Initialized, Referenced, Parked, Stopped, etc.
      //
      //	INPUT:
      //	event bit mask
      //
      //	OUTPUT:
      //	-
      void WCClearEventRegister (DWORD p_dwEventMask = 0xFFFFFFFF);

      //## Operation: WCGetDirection%1045031044
      //	DESCRIPTION:
      //	Gets the direction of the wedge control from the Control
      //	Register (d-Counter Register)
      //
      //	INPUT:
      //	-
      //
      //	OUTPUT:
      //	wedge control direction l_dwPosition
      //	  0: indicates FORWARD direction
      //	  1: indicates BACKWARD direction
      DWORD WCGetDirection ();

      //## Operation: WCGetLightBarrierState%1044873123
      //	DESCRIPTION:
      //	Reads the state of the wedge control light barrier
      //
      //	INPUT:
      //	-
      //
      //	OUTPUT:
      //	 0: light barrier free
      //	 1: light barrier occupied
      DWORD WCGetLightBarrierState ();

      //## Operation: WCGetActValue%1044873126
      //	DESCRIPTION:
      //	calculate the actual "velocity" counts
      //
      //	INPUT:
      //	-
      //
      //	OUTPUT:
      //	actual value counts at lacht time
      int WCGetActValue ();

      //## Operation: WCLightBarrierLeft%1067936075
      //	DESCRIPTION:
      //	the wedge coil has left the light barrier
      //	(only one IRQ sample high!!!)
      //
      //	INPUT:
      //	-
      //	OUTPUT:
      //	 0: light barrier not left
      //	 1: light barrier was left
      DWORD WCLightBarrierLeft ();

      //## Operation: WCLightBarrierAchieved%1067936076
      //	DESCRIPTION:
      //	the wedge coil has achieved the light barrier
      //	(only one IRQ sample high!!!)
      //
      //	INPUT:
      //	-
      //	OUTPUT:
      //	 0: light barrier not achieved
      //	 1: light barrier was achieved
      DWORD WCLightBarrierAchieved ();

      //## Operation: WCSetEnable%1068014454
      //	DESCRIPTION:
      //	wedge controlloop factor (1 factor normal, 0 factor low
      //	(off))
      //
      //	INPUT:
      //	0   factor loww (off)
      //	1   factor normal
      void WCSetEnable (bool p_bValue);

      //## Operation: WCSetPositionReset%1068014455
      //	DESCRIPTION:
      //	wedge position reset counter
      //
      //	INPUT:
      //	0   position will be count
      //	1   position will be set to 0
      void WCSetPositionReset (bool p_bValue);

      //## Operation: TEST_WCGetActValue%1066825080
      //	DESCRIPTION:
      //	TEST_WCGetActValue calculates the state of a voice coil
      //	drive in the next time interval if an electrical current
      //	Ia is applied to the coil and the direction of movement
      //	is dfa (1=fw, -1=rv). The state of the vc in the last
      //	time interval is passed as a paramter.
      //
      //	INPUT:
      //	p_Wdg_Volt: DAC Value [Digit]
      //	p_dfa: direction of movement (1=fw, -1=rv)
      int TEST_WCGetActValue (int p_Wdg_Volt, int p_dfa, DWORD& p_clast, DWORD& p_cdiff, int& p_cp);

      //## Operation: WCEmergencyStop%1068453036
      //	DESCRIPTION:
      //	stops the wedge drive immediately
      void WCEmergencyStop ();

      //## Operation: WCSetDigOutput%1068703783
      void WCSetDigOutput (DWORD p_dwValue);

      //## Operation: WCClearDigOutput%1068703784
      void WCClearDigOutput (DWORD p_dwValue);

      //## Operation: WCIncScanCounter%1073896760
      //	DESCRIPTION:
      //	Increments the Number of Scan register counter
      void WCIncScanCounter ();

      //## Operation: WCCheckLaserDetection%1073998356
      //	DESCRIPTION:
      //	checks the laser detection
      //
      //	RETURN:
      //	true:  laser detection OK
      //	false: laser detection NOK
      bool WCCheckLaserDetection ();

      //## Operation: WCSetException%1073998357
      //	DESCRIPTION:
      //	set a spec. exception in the WC exception register
      //
      //	PARAMETER:
      //	exception bit mask
      void WCSetException (DWORD p_dwExceptionBitMask);

      //## Operation: WCClearException%1076491968
      //	DESCRIPTION:
      //	clear WC exception register
      void WCClearException ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: TEST_ACT_DIR%3E4A749E0138
      DWORD GetTEST_ACT_DIR ();
      void SetTEST_ACT_DIR (DWORD value);

      //## Attribute: TEST_X_NOM%3E523C8A0290
      DWORD GetTEST_X_NOM ();
      void SetTEST_X_NOM (DWORD value);

      //## Attribute: TEST_X_ACT%3E523CB0001F
      DWORD GetTEST_X_ACT ();
      void SetTEST_X_ACT (DWORD value);

      //## Attribute: TEST_Y_K%3E523CC002CE
      DWORD GetTEST_Y_K ();

      //## Attribute: TEST_INDEX%3E524A55002E
      DWORD GetTEST_INDEX ();
      void SetTEST_INDEX (DWORD value);

      //## Attribute: TEST_POS_FORWARD%3F8A4D6801C5
      DWORD GetTEST_POS_FORWARD ();
      void SetTEST_POS_FORWARD (DWORD value);

      //## Attribute: TEST_POS_BACKWARD%3F8A4D69005D
      DWORD GetTEST_POS_BACKWARD ();
      void SetTEST_POS_BACKWARD (DWORD value);

      //## Attribute: TEST_LAST_VELOCITY%3F979FD10148
      DWORD GetTEST_LAST_VELOCITY ();
      void SetTEST_LAST_VELOCITY (DWORD value);

      //## Attribute: TEST_ACT_VELOCITY%3F979FD102DE
      DWORD GetTEST_ACT_VELOCITY ();
      void SetTEST_ACT_VELOCITY (DWORD value);

      //## Attribute: TEST_POSITION%3F979FD201E4
      int GetTEST_POSITION ();
      void SetTEST_POSITION (int value);

      //## Attribute: TEST_DAC%3FA6556E01E4
      DWORD GetTEST_DAC ();
      void SetTEST_DAC (DWORD value);

      //## Attribute: TEST_LB_LEFT%3FA91D6B0157
      DWORD GetTEST_LB_LEFT ();
      void SetTEST_LB_LEFT (DWORD value);

      //## Attribute: TEST_LB_ACHIEVED%3FA91D7B01E4
      DWORD GetTEST_LB_ACHIEVED ();
      void SetTEST_LB_ACHIEVED (DWORD value);

      //## Attribute: nAvStaticFriction%3FAB445A00BB
      //	DESCRIPTION:
      //	static average friction
      //	Fr = (Fr_Forward - Fr_Backward) / 2;
      //	=> Static Average Friction = 2*Fr
      //
      //	UNIT:
      //	DAC count average value
      int GetnAvStaticFriction ();

      //## Attribute: dwWCWriteRegValue%3FB3830F006D
      //	DESCRIPTION:
      //	write value to wedge control write register
      DWORD GetdwWCWriteRegValue ();

      //## Attribute: nWCCnt%3FB3A7BF029F
      //	DESCRIPTION:
      //	loop counter
      int GetnWCCnt ();

      //## Attribute: nWCMaxCurCounter%4028F6D70186
      //	DESCRIPTION:
      //	Current time counter
      //	if this counter more than this value, an emergency stop
      //	will occurs.
      int GetnWCMaxCurCounter ();

    //## Get and Set Operations for Associations (generated)

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3E4223AF0399
      //## Role: CISRWCPIDControl::eWCPosState%3E4223B00223
      const EISRWCPosState GeteWCPosState () const;

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3E422F0B004E
      //## Role: CISRWCPIDControl::nActValue%3E422F0B02A0
      const ControllerType GetnActValue () const;

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3E435B2800AB
      //## Role: CISRWCPIDControl::dwActPosCounterForward%3E435B290001
      const DWORD GetdwActPosCounterForward () const;

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3E47B89B02AF
      //## Role: CISRWCPIDControl::dwActPosCounterBackward%3E47B89C0252
      const DWORD GetdwActPosCounterBackward () const;

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3FAB65DC038A
      //## Role: CISRWCPIDControl::nControllOutputValue%3FAB65DD02DF
      ControllerType GetnControllOutputValue ();

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3FAB78A702DE
      //## Role: CISRWCPIDControl::nNomValue%3FAB78A800FB
      ControllerType GetnNomValue ();

    // Data Members for Class Attributes

      //## begin CISRWCPIDControl::nAvStaticFriction%3FAB445A00BB.attr preserve=no  public: int {U} m_cnIniAvStaticFriction
      int m_nAvStaticFriction;
      //## end CISRWCPIDControl::nAvStaticFriction%3FAB445A00BB.attr

      //## begin CISRWCPIDControl::dwWCWriteRegValue%3FB3830F006D.attr preserve=no  public: DWORD {U} 0
      DWORD m_dwWCWriteRegValue;
      //## end CISRWCPIDControl::dwWCWriteRegValue%3FB3830F006D.attr

      //## begin CISRWCPIDControl::nWCCnt%3FB3A7BF029F.attr preserve=no  public: int {U} 0
      int m_nWCCnt;
      //## end CISRWCPIDControl::nWCCnt%3FB3A7BF029F.attr

      //## begin CISRWCPIDControl::nWCMaxCurCounter%4028F6D70186.attr preserve=no  public: int {U} 0
      int m_nWCMaxCurCounter;
      //## end CISRWCPIDControl::nWCMaxCurCounter%4028F6D70186.attr

    // Data Members for Associations

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3E4223AF0399
      //## begin CISRWCPIDControl::eWCPosState%3E4223B00223.role preserve=no  public: EISRWCPosState {1..1 -> 1..1VFHN}
      EISRWCPosState m_eWCPosState;
      //## end CISRWCPIDControl::eWCPosState%3E4223B00223.role

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3E422F0B004E
      //## begin CISRWCPIDControl::nActValue%3E422F0B02A0.role preserve=no  public: CISRWCPIDControl::ControllerType {1..1 -> 1..1VFHN}
      ControllerType m_nActValue;
      //## end CISRWCPIDControl::nActValue%3E422F0B02A0.role

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3FAB65DC038A
      //## begin CISRWCPIDControl::nControllOutputValue%3FAB65DD02DF.role preserve=no  public: CISRWCPIDControl::ControllerType {1..1 -> 1..1VFHN}
      ControllerType m_nControllOutputValue;
      //## end CISRWCPIDControl::nControllOutputValue%3FAB65DD02DF.role

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3FAB78A702DE
      //## begin CISRWCPIDControl::nNomValue%3FAB78A800FB.role preserve=no  public: CISRWCPIDControl::ControllerType {1..1 -> 1..1VFHN}
      ControllerType m_nNomValue;
      //## end CISRWCPIDControl::nNomValue%3FAB78A800FB.role

  public:
    // Additional Public Declarations
      //## begin CISRWCPIDControl%3E40E116000F.public preserve=yes
      //## end CISRWCPIDControl%3E40E116000F.public

  protected:
    // Additional Protected Declarations
      //## begin CISRWCPIDControl%3E40E116000F.protected preserve=yes
      //## end CISRWCPIDControl%3E40E116000F.protected

  private:
    //## Constructors (generated)
      CISRWCPIDControl(const CISRWCPIDControl &right);

    //## Assignment Operation (generated)
      const CISRWCPIDControl & operator=(const CISRWCPIDControl &right);

    //## Equality Operations (generated)
      bool operator==(const CISRWCPIDControl &right) const;

      bool operator!=(const CISRWCPIDControl &right) const;


    //## Other Operations (specified)
      //## Operation: NomValueIdleState%1068703781
      void NomValueIdleState ();

      //## Operation: NomValueInit%1067936068
      void NomValueInit ();

      //## Operation: NomValueStartPosition%1067936069
      void NomValueStartPosition ();

      //## Operation: NomValueForwardAcc%1067936066
      void NomValueForwardAcc ();

      //## Operation: NomValueForwardMeasuring%1067936067
      void NomValueForwardMeasuring ();

      //## Operation: NomValueForwardDec%1067936070
      void NomValueForwardDec ();

      //## Operation: NomValueReversePosition%1067936071
      void NomValueReversePosition ();

      //## Operation: NomValueBackwardAcc%1067936072
      void NomValueBackwardAcc ();

      //## Operation: NomValueBackwardMeasuring%1067936073
      void NomValueBackwardMeasuring ();

      //## Operation: NomValueBackwardDec%1067936074
      void NomValueBackwardDec ();

      //## Operation: WCCalculateStaticFriction%1068189083
      //	DESCRIPTION:
      //	calculate the static average friction
      void WCCalculateStaticFriction ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: bWCStart%3E491C5D004E
      bool GetbWCStart ();
      void SetbWCStart (bool value);

      //## Attribute: bOsciOn%3FABBAFA02BF
      bool GetbOsciOn ();
      void SetbOsciOn (bool value);

    // Data Members for Class Attributes

      //## Attribute: cMemorySize%3E47646A009C
      //## begin CISRWCPIDControl::cMemorySize%3E47646A009C.attr preserve=no  private: static char[256] {U} 
      static char m_cMemorySize[256];
      //## end CISRWCPIDControl::cMemorySize%3E47646A009C.attr

      //## Attribute: cdwFactor%3F827E9C0157
      //	DESCRIPTION:
      //	calculation  factor for INTEGER multiplication and
      //	division operation
      //## begin CISRWCPIDControl::cdwFactor%3F827E9C0157.attr preserve=no  private: static DWORD {U} 10000
      static DWORD m_cdwFactor;
      //## end CISRWCPIDControl::cdwFactor%3F827E9C0157.attr

      //## Attribute: cnIniAvStaticFriction%3FAB909500BB
      //	DESCRIPTION:
      //	standard ini. static friction of the wedge drive
      //## begin CISRWCPIDControl::cnIniAvStaticFriction%3FAB909500BB.attr preserve=no  private: static int {U} 130
      static int m_cnIniAvStaticFriction;
      //## end CISRWCPIDControl::cnIniAvStaticFriction%3FAB909500BB.attr

      //## Attribute: nNumberOfScan%3F865198030D
      //	DESCRIPTION:
      //	number of scans (scans means one forward AND one
      //	bachward movement)
      //## begin CISRWCPIDControl::nNumberOfScan%3F865198030D.attr preserve=no  private: int {U} 0
      int m_nNumberOfScan;
      //## end CISRWCPIDControl::nNumberOfScan%3F865198030D.attr

      //## begin CISRWCPIDControl::bWCStart%3E491C5D004E.attr preserve=no  private: bool {U} false
      bool m_bWCStart;
      //## end CISRWCPIDControl::bWCStart%3E491C5D004E.attr

      //## begin CISRWCPIDControl::bOsciOn%3FABBAFA02BF.attr preserve=no  private: bool {U} false
      bool m_bOsciOn;
      //## end CISRWCPIDControl::bOsciOn%3FABBAFA02BF.attr

      //## Attribute: dwActLightBarrierState%3FA7BE4000BB
      //	DESCRIPTION:
      //	actual light barrier state
      //	  1 light barrier occupied
      //	  0 light barrier free
      //## begin CISRWCPIDControl::dwActLightBarrierState%3FA7BE4000BB.attr preserve=no  private: DWORD {U} 0
      DWORD m_dwActLightBarrierState;
      //## end CISRWCPIDControl::dwActLightBarrierState%3FA7BE4000BB.attr

      //## Attribute: dwLastLightBarrierState%3F8D087D0186
      //	DESCRIPTION:
      //	last light barrier state
      //	  1 light barrier was occupied
      //	  0 light barrier was free
      //## begin CISRWCPIDControl::dwLastLightBarrierState%3F8D087D0186.attr preserve=no  private: DWORD {U} 0
      DWORD m_dwLastLightBarrierState;
      //## end CISRWCPIDControl::dwLastLightBarrierState%3F8D087D0186.attr

      //## begin CISRWCPIDControl::TEST_ACT_DIR%3E4A749E0138.attr preserve=no  public: DWORD {U} 0
      DWORD m_TEST_ACT_DIR;
      //## end CISRWCPIDControl::TEST_ACT_DIR%3E4A749E0138.attr

      //## begin CISRWCPIDControl::TEST_X_NOM%3E523C8A0290.attr preserve=no  public: DWORD {U} 
      DWORD m_TEST_X_NOM;
      //## end CISRWCPIDControl::TEST_X_NOM%3E523C8A0290.attr

      //## begin CISRWCPIDControl::TEST_X_ACT%3E523CB0001F.attr preserve=no  public: DWORD {U} 
      DWORD m_TEST_X_ACT;
      //## end CISRWCPIDControl::TEST_X_ACT%3E523CB0001F.attr

      //## begin CISRWCPIDControl::TEST_Y_K%3E523CC002CE.attr preserve=no  public: DWORD {U} 
      DWORD m_TEST_Y_K;
      //## end CISRWCPIDControl::TEST_Y_K%3E523CC002CE.attr

      //## begin CISRWCPIDControl::TEST_INDEX%3E524A55002E.attr preserve=no  public: DWORD {U} 
      DWORD m_TEST_INDEX;
      //## end CISRWCPIDControl::TEST_INDEX%3E524A55002E.attr

      //## begin CISRWCPIDControl::TEST_POS_FORWARD%3F8A4D6801C5.attr preserve=no  public: DWORD {U} 
      DWORD m_TEST_POS_FORWARD;
      //## end CISRWCPIDControl::TEST_POS_FORWARD%3F8A4D6801C5.attr

      //## begin CISRWCPIDControl::TEST_POS_BACKWARD%3F8A4D69005D.attr preserve=no  public: DWORD {U} 
      DWORD m_TEST_POS_BACKWARD;
      //## end CISRWCPIDControl::TEST_POS_BACKWARD%3F8A4D69005D.attr

      //## begin CISRWCPIDControl::TEST_LAST_VELOCITY%3F979FD10148.attr preserve=no  public: DWORD {U} 0
      DWORD m_TEST_LAST_VELOCITY;
      //## end CISRWCPIDControl::TEST_LAST_VELOCITY%3F979FD10148.attr

      //## begin CISRWCPIDControl::TEST_ACT_VELOCITY%3F979FD102DE.attr preserve=no  public: DWORD {U} 0
      DWORD m_TEST_ACT_VELOCITY;
      //## end CISRWCPIDControl::TEST_ACT_VELOCITY%3F979FD102DE.attr

      //## begin CISRWCPIDControl::TEST_POSITION%3F979FD201E4.attr preserve=no  public: int {U} 0
      int m_TEST_POSITION;
      //## end CISRWCPIDControl::TEST_POSITION%3F979FD201E4.attr

      //## begin CISRWCPIDControl::TEST_DAC%3FA6556E01E4.attr preserve=no  public: DWORD {U} 0
      DWORD m_TEST_DAC;
      //## end CISRWCPIDControl::TEST_DAC%3FA6556E01E4.attr

      //## begin CISRWCPIDControl::TEST_LB_LEFT%3FA91D6B0157.attr preserve=no  public: DWORD {U} 0
      DWORD m_TEST_LB_LEFT;
      //## end CISRWCPIDControl::TEST_LB_LEFT%3FA91D6B0157.attr

      //## begin CISRWCPIDControl::TEST_LB_ACHIEVED%3FA91D7B01E4.attr preserve=no  public: DWORD {U} 0
      DWORD m_TEST_LB_ACHIEVED;
      //## end CISRWCPIDControl::TEST_LB_ACHIEVED%3FA91D7B01E4.attr

      //## Attribute: nAccMovementDistance%3FA89AB902BF
      //## begin CISRWCPIDControl::nAccMovementDistance%3FA89AB902BF.attr preserve=no  private: int {U} 0
      int m_nAccMovementDistance;
      //## end CISRWCPIDControl::nAccMovementDistance%3FA89AB902BF.attr

      //## Attribute: nDecMovementDistance%3FA89B5101D4
      //## begin CISRWCPIDControl::nDecMovementDistance%3FA89B5101D4.attr preserve=no  private: int {U} 0
      int m_nDecMovementDistance;
      //## end CISRWCPIDControl::nDecMovementDistance%3FA89B5101D4.attr

      //## Attribute: nForwardMovementDistance%3FA76B8D01A5
      //## begin CISRWCPIDControl::nForwardMovementDistance%3FA76B8D01A5.attr preserve=no  private: int {U} 0
      int m_nForwardMovementDistance;
      //## end CISRWCPIDControl::nForwardMovementDistance%3FA76B8D01A5.attr

      //## Attribute: nBackwardMovementDistance%3FA76BA90148
      //## begin CISRWCPIDControl::nBackwardMovementDistance%3FA76BA90148.attr preserve=no  private: int {U} 0
      int m_nBackwardMovementDistance;
      //## end CISRWCPIDControl::nBackwardMovementDistance%3FA76BA90148.attr

      //## Attribute: nAccCounter%3FA76E8F02AF
      //## begin CISRWCPIDControl::nAccCounter%3FA76E8F02AF.attr preserve=no  private: int {U} 0
      int m_nAccCounter;
      //## end CISRWCPIDControl::nAccCounter%3FA76E8F02AF.attr

      //## Attribute: nDecCounter%3FA76EA40196
      //## begin CISRWCPIDControl::nDecCounter%3FA76EA40196.attr preserve=no  private: int {U} 0
      int m_nDecCounter;
      //## end CISRWCPIDControl::nDecCounter%3FA76EA40196.attr

      //## Attribute: cnMaxMovementDistance%3FAA17EE0251
      //	DESCRIPTION:
      //	max wedge movement distance, which the wedge may drive
      //
      //	UNIT:
      //	number of laser zero cross counts
      //	  max movement distance [mm] / laser zero cross distance
      //	  -> 30mm / 12.1um
      //## begin CISRWCPIDControl::cnMaxMovementDistance%3FAA17EE0251.attr preserve=no  private: static int {U} 2480
      static int m_cnMaxMovementDistance;
      //## end CISRWCPIDControl::cnMaxMovementDistance%3FAA17EE0251.attr

      //## Attribute: nAvForwardFriction%3FAB441501D4
      //	DESCRIPTION:
      //	static friction forward direction
      //
      //	UNIT:
      //	DAC count average value
      //## begin CISRWCPIDControl::nAvForwardFriction%3FAB441501D4.attr preserve=no  private: int {U} 0
      int m_nAvForwardFriction;
      //## end CISRWCPIDControl::nAvForwardFriction%3FAB441501D4.attr

      //## Attribute: nAvBackwardFriction%3FAB444A01D4
      //	DESCRIPTION:
      //	static friction backward direction
      //
      //	UNIT:
      //	DAC count average value
      //## begin CISRWCPIDControl::nAvBackwardFriction%3FAB444A01D4.attr preserve=no  private: int {U} 0
      int m_nAvBackwardFriction;
      //## end CISRWCPIDControl::nAvBackwardFriction%3FAB444A01D4.attr

      //## Attribute: cnDACEmergencyStopValue%3FAF4BD701E4
      //	DESCRIPTION:
      //	the wedge drive releases an emergency stop
      //## begin CISRWCPIDControl::cnDACEmergencyStopValue%3FAF4BD701E4.attr preserve=no  private: static int {U} 0x97000000
      static int m_cnDACEmergencyStopValue;
      //## end CISRWCPIDControl::cnDACEmergencyStopValue%3FAF4BD701E4.attr

      //## Attribute: bWCControllerOn%3FAF939B031C
      //## begin CISRWCPIDControl::bWCControllerOn%3FAF939B031C.attr preserve=no  private: BOOL {U} false
      BOOL m_bWCControllerOn;
      //## end CISRWCPIDControl::bWCControllerOn%3FAF939B031C.attr

      //## Attribute: bFirstStateInitialization%3FB8C4E00242
      //## begin CISRWCPIDControl::bFirstStateInitialization%3FB8C4E00242.attr preserve=no  private: bool {U} false
      bool m_bFirstStateInitialization;
      //## end CISRWCPIDControl::bFirstStateInitialization%3FB8C4E00242.attr

      //## Attribute: bFirstControllerIni%3FD081A600DA
      //## begin CISRWCPIDControl::bFirstControllerIni%3FD081A600DA.attr preserve=no  private: bool {U} false
      bool m_bFirstControllerIni;
      //## end CISRWCPIDControl::bFirstControllerIni%3FD081A600DA.attr

      //## Attribute: bFirstAcc%4028CC6C005D
      //## begin CISRWCPIDControl::bFirstAcc%4028CC6C005D.attr preserve=no  private: bool {U} false
      bool m_bFirstAcc;
      //## end CISRWCPIDControl::bFirstAcc%4028CC6C005D.attr

    // Data Members for Associations

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3E4209F20242
      //## Role: CISRWCPIDControl::fnPtrNomValue%3E4209F301C6
      //## begin CISRWCPIDControl::fnPtrNomValue%3E4209F301C6.role preserve=no  public: CISRWCPIDControl::ISRWCNomValue {1..1 -> 1..1VFHN}
      ISRWCNomValue m_fnPtrNomValue;
      //## end CISRWCPIDControl::fnPtrNomValue%3E4209F301C6.role

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3E4226AA02BF
      //## Role: CISRWCPIDControl::pWCConfig%3E4226AB0158
      //## begin CISRWCPIDControl::pWCConfig%3E4226AB0158.role preserve=no  public: CHIIOCSetWCConfiguration {1..1 -> 1..1RFHN}
      CHIIOCSetWCConfiguration *m_pWCConfig;
      //## end CISRWCPIDControl::pWCConfig%3E4226AB0158.role

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3E422AAC03C8
      //## Role: CISRWCPIDControl::pWCProfile%3E422AAD038A
      //## begin CISRWCPIDControl::pWCProfile%3E422AAD038A.role preserve=no  public: CHIIOCSetWCProfile {1..1 -> 1..1RFHN}
      CHIIOCSetWCProfile *m_pWCProfile;
      //## end CISRWCPIDControl::pWCProfile%3E422AAD038A.role

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3E435B2800AB
      //## begin CISRWCPIDControl::dwActPosCounterForward%3E435B290001.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwActPosCounterForward;
      //## end CISRWCPIDControl::dwActPosCounterForward%3E435B290001.role

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3E47B89B02AF
      //## begin CISRWCPIDControl::dwActPosCounterBackward%3E47B89C0252.role preserve=no  public: DWORD {1..1 -> 1..1VFHN}
      DWORD m_dwActPosCounterBackward;
      //## end CISRWCPIDControl::dwActPosCounterBackward%3E47B89C0252.role

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3E4A6099032C
      //## Role: CISRWCPIDControl::eWCState%3E4A609A0232
      //## begin CISRWCPIDControl::eWCState%3E4A609A0232.role preserve=no  public: EISRWCState {1..1 -> 1..1VFHN}
      EISRWCState m_eWCState;
      //## end CISRWCPIDControl::eWCState%3E4A609A0232.role

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%3E50E91D035B
      //## Role: CISRWCPIDControl::HWDef%3E50E91F003F
      //## begin CISRWCPIDControl::HWDef%3E50E91F003F.role preserve=no  public: CHITDefinitions {1..1 -> 1..1VFHN}
      CHITDefinitions m_HWDef;
      //## end CISRWCPIDControl::HWDef%3E50E91F003F.role

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%402386DA01F4
      //## Role: CISRWCPIDControl::bDirection%402386DB00FA
      //## begin CISRWCPIDControl::bDirection%402386DB00FA.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bDirection;
      //## end CISRWCPIDControl::bDirection%402386DB00FA.role

      //## Association: EBISR (Interrupt Service Routine)::<unnamed>%456EF73F0256
      //## Role: CISRWCPIDControl::bLBFoundInBackwardMovement%456EF740015D
      //## begin CISRWCPIDControl::bLBFoundInBackwardMovement%456EF740015D.role preserve=no  public: bool {1..1 -> 1..1VFHN}
      bool m_bLBFoundInBackwardMovement;
      //## end CISRWCPIDControl::bLBFoundInBackwardMovement%456EF740015D.role

    // Additional Private Declarations
      //## begin CISRWCPIDControl%3E40E116000F.private preserve=yes
      //## end CISRWCPIDControl%3E40E116000F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CISRWCPIDControl%3E40E116000F.implementation preserve=yes
      //## end CISRWCPIDControl%3E40E116000F.implementation

};

//## begin CISRWCPIDControl%3E40E116000F.postscript preserve=yes
//## end CISRWCPIDControl%3E40E116000F.postscript

// Class CISRWCPIDControl 

//## begin module%3E41319D034B.epilog preserve=yes
//## end module%3E41319D034B.epilog


#endif
