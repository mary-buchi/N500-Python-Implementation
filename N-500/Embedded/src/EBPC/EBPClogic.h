//## begin module%3EED769F0391.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F0391.cm

//## begin module%3EED769F0391.cp preserve=no
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
//## end module%3EED769F0391.cp

//## Module: EBPClogic%3EED769F0391; Package specification
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPClogic.h

#ifndef EBPClogic_h
#define EBPClogic_h 1

//## begin module%3EED769F0391.additionalIncludes preserve=no
//## end module%3EED769F0391.additionalIncludes

//## begin module%3EED769F0391.includes preserve=yes
//## end module%3EED769F0391.includes


class EBCO_DLL_DECL CCOSyncObject;
class CPCPowerControlImplementation;

//## begin module%3EED769F0391.declarations preserve=no
//## end module%3EED769F0391.declarations

//## begin module%3EED769F0391.additionalDeclarations preserve=yes
//## end module%3EED769F0391.additionalDeclarations


//## begin CPCLogic%3EED76CC0744.preface preserve=yes
//## end CPCLogic%3EED76CC0744.preface

//## Class: CPCLogic%3EED76CC0744
//## Category: EBPC (Power Control)%3EED76CC02E5
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3F0D5B42019C;IHIInterface { -> }
//## Uses: <unnamed>%3F4B615400A4;CPIComponentsState { -> }
//## Uses: <unnamed>%3F4B6209021B;PC_IDENTIFIERS { -> }
//## Uses: <unnamed>%3F66FB200105;EPILamp { -> }
//## Uses: <unnamed>%3F66FB3503C3;XPCExceptionErrorShorted { -> }

class EBPC_DLL_DECL CPCLogic 
{
  //## begin CPCLogic%3EED76CC0744.initialDeclarations preserve=yes
  //## end CPCLogic%3EED76CC0744.initialDeclarations

  public:
    //## Constructors (specified)
      //## Operation: CPCLogic%1045561403
      CPCLogic (CPCPowerControlImplementation* p_pContext);

    //## Destructor (generated)
      virtual ~CPCLogic();


    //## Other Operations (specified)
      //## Operation: PID%1046071781
      DWORD PID (double& x_nom, double& x_act, const double Kp, const double Ti, const double Tv, const double LimitUp, const double LimitDown, const double Ts, double&  y_k);

      //## Operation: LimitVoltage%1046071782
      UINT LimitVoltage (UINT p_uiValue);

      //## Operation: SetVoltage%1057913135
      void SetVoltage (UINT p_uiVolt);

      //## Operation: ActCurrent%1057913136
      //	Return Value [mV]
      UINT ActCurrent ();

      //## Operation: ActVoltage%1057913137
      UINT ActVoltage ();

      //## Operation: GetDWordPC%1061890359
      DWORD GetDWordPC (const DWORD p_dwID);

      //## Operation: SetDWordPC%1061890360
      void SetDWordPC (const DWORD p_dwID, const DWORD p_dwValue);

      //## Operation: PowerOn%1063700378
      void PowerOn ();

      //## Operation: ActPower%1063700379
      UINT ActPower ();

      //## Operation: PowerOff%1063954791
      void PowerOff ();

      //## Operation: SelectLamp%1075281202
      void SelectLamp ();

      //## Operation: IncVoltage%1077174616
      bool IncVoltage ();

      //## Operation: SetDAC%1090333015
      void SetDAC (const DWORD p_dwDigits = 0);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: iLoopCounter%3EED76CC0763
      int GetiLoopCounter ();
      void SetiLoopCounter (int value);

      //## Attribute: bInitDone%3EED76CC0765
      bool GetbInitDone ();
      void SetbInitDone (bool value);

      //## Attribute: iSoftStartLoopCnt%3F13B01D01EA
      int GetiSoftStartLoopCnt ();
      void SetiSoftStartLoopCnt (int value);

      //## Attribute: dwTimeBase%403323AB0243
      DWORD& GetdwTimeBase ();
      void SetdwTimeBase (const DWORD& value);

      //## Attribute: uiSettlingTime%4035D5A603E0
      UINT GetuiSettlingTime ();
      void SetuiSettlingTime (UINT value);

    //## Get and Set Operations for Associations (generated)

      //## Association: EBPC (Power Control)::<unnamed>%4035E0F00056
      //## Role: CPCLogic::pStartSyncObject%4035E0F001FC
      CCOSyncObject * GetpStartSyncObject ();
      void SetpStartSyncObject (CCOSyncObject * value);

    // Additional Public Declarations
      //## begin CPCLogic%3EED76CC0744.public preserve=yes
      //## end CPCLogic%3EED76CC0744.public

  protected:
    // Additional Protected Declarations
      //## begin CPCLogic%3EED76CC0744.protected preserve=yes
      //## end CPCLogic%3EED76CC0744.protected

  private:
    //## Constructors (generated)
      CPCLogic();

      CPCLogic(const CPCLogic &right);

    //## Assignment Operation (generated)
      const CPCLogic & operator=(const CPCLogic &right);

    //## Equality Operations (generated)
      bool operator==(const CPCLogic &right) const;

      bool operator!=(const CPCLogic &right) const;

    // Data Members for Class Attributes

      //## begin CPCLogic::iLoopCounter%3EED76CC0763.attr preserve=no  public: int {U} 0
      int m_iLoopCounter;
      //## end CPCLogic::iLoopCounter%3EED76CC0763.attr

      //## begin CPCLogic::bInitDone%3EED76CC0765.attr preserve=no  public: bool {U} false
      bool m_bInitDone;
      //## end CPCLogic::bInitDone%3EED76CC0765.attr

      //## begin CPCLogic::iSoftStartLoopCnt%3F13B01D01EA.attr preserve=no  public: int {U} 0
      int m_iSoftStartLoopCnt;
      //## end CPCLogic::iSoftStartLoopCnt%3F13B01D01EA.attr

      //## Attribute: bHardwarePresent %3F41EB4A0128
      //## begin CPCLogic::bHardwarePresent %3F41EB4A0128.attr preserve=no  public: bool {U} false
      bool m_bHardwarePresent;
      //## end CPCLogic::bHardwarePresent %3F41EB4A0128.attr

      //## begin CPCLogic::dwTimeBase%403323AB0243.attr preserve=no  public: DWORD {U} 0
      DWORD m_dwTimeBase;
      //## end CPCLogic::dwTimeBase%403323AB0243.attr

      //## begin CPCLogic::uiSettlingTime%4035D5A603E0.attr preserve=no  public: UINT {U} 0
      UINT m_uiSettlingTime;
      //## end CPCLogic::uiSettlingTime%4035D5A603E0.attr

    // Data Members for Associations

      //## Association: EBPC (Power Control)::<unnamed>%3EED76CC08F3
      //## Role: CPCLogic::pContext%3EED76CC08F8
      //## begin CPCLogic::pContext%3EED76CC08F8.role preserve=no  public: CPCPowerControlImplementation {1..1 -> 1..1RFHN}
      CPCPowerControlImplementation *m_pContext;
      //## end CPCLogic::pContext%3EED76CC08F8.role

      //## Association: EBPC (Power Control)::<unnamed>%3F1264F902FD
      //## Role: CPCLogic::<m_INT>%3F1264FA007E
      //## begin CPCLogic::<m_INT>%3F1264FA007E.role preserve=no  public: INT { -> UFHN}
      INT m_INT;
      //## end CPCLogic::<m_INT>%3F1264FA007E.role

      //## Association: EBPC (Power Control)::<unnamed>%4035E0F00056
      //## begin CPCLogic::pStartSyncObject%4035E0F001FC.role preserve=no  public: CCOSyncObject {1..1 -> 1..1RFHN}
      CCOSyncObject *m_pStartSyncObject;
      //## end CPCLogic::pStartSyncObject%4035E0F001FC.role

    // Additional Private Declarations
      //## begin CPCLogic%3EED76CC0744.private preserve=yes
      //## end CPCLogic%3EED76CC0744.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CPCLogic%3EED76CC0744.implementation preserve=yes
      //## end CPCLogic%3EED76CC0744.implementation

};

//## begin CPCLogic%3EED76CC0744.postscript preserve=yes
//## end CPCLogic%3EED76CC0744.postscript

// Class CPCLogic 

//## begin module%3EED769F0391.epilog preserve=yes
//## end module%3EED769F0391.epilog


#endif
