//## begin module%3EED769F0393.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3EED769F0393.cm

//## begin module%3EED769F0393.cp preserve=no
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
//## end module%3EED769F0393.cp

//## Module: EBPClogic%3EED769F0393; Package body
//## Subsystem: EBPC (Power Control)%3EED769F0343
//## Source file: R:\Embedded\src\EBPC\EBPClogic.cpp

// stdafx
#include "stdafx.h"
//## begin module%3EED769F0393.additionalIncludes preserve=no
//## end module%3EED769F0393.additionalIncludes

//## begin module%3EED769F0393.includes preserve=yes
#ifdef _WIN32_WCE
  #include <pkfuncs.h>
#else
  #include <math.h>
#endif
//## end module%3EED769F0393.includes

// EBCOsync
#include "EBCOsync.h"
// EBPIcpst
#include "EBPIcpst.h"
// EBPIenum
#include "EBPIenum.h"
// EBPCexcp
#include "EBPCexcp.h"
// EBPClogic
#include "EBPClogic.h"
// EBPCimpl
#include "EBPCimpl.h"
// EBPCident
#include "EBPCident.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3EED769F0393.declarations preserve=no
//## end module%3EED769F0393.declarations

//## begin module%3EED769F0393.additionalDeclarations preserve=yes
static const DWORD PRIMARY_LAMP = 0;
static const DWORD SECONDARY_LAMP = 1;

//## end module%3EED769F0393.additionalDeclarations


// Class CPCLogic 











CPCLogic::CPCLogic (CPCPowerControlImplementation* p_pContext)
  //## begin CPCLogic::CPCLogic%1045561403.hasinit preserve=no
      : m_iLoopCounter(0), m_bInitDone(false), m_iSoftStartLoopCnt(0), m_bHardwarePresent(false), m_dwTimeBase(0), m_uiSettlingTime(0), m_pContext(p_pContext), m_pStartSyncObject(NULL)
  //## end CPCLogic::CPCLogic%1045561403.hasinit
  //## begin CPCLogic::CPCLogic%1045561403.initialization preserve=yes
  //## end CPCLogic::CPCLogic%1045561403.initialization
{
  //## begin CPCLogic::CPCLogic%1045561403.body preserve=yes
	m_bHardwarePresent = CPIComponentsState::GetInstance()->GetComponentState(PC_ID);
  //## end CPCLogic::CPCLogic%1045561403.body
}


CPCLogic::~CPCLogic()
{
  //## begin CPCLogic::~CPCLogic%.body preserve=yes
	if(m_pStartSyncObject)
		m_pStartSyncObject->ReleaseRef();

	m_pStartSyncObject = NULL;

  //## end CPCLogic::~CPCLogic%.body
}



//## Other Operations (implementation)
DWORD CPCLogic::PID (double& x_nom, double& x_act, const double Kp, const double Ti, const double Tv, const double LimitUp, const double LimitDown, const double Ts, double&  y_k)
{
  //## begin CPCLogic::PID%1046071781.body preserve=yes

  ///////////////////////////////////////////////////
  // x_nom      -> Regler Sollwert
  // x_act      -> aktueller Istwert
  // Kp         -> P-Verstärkungsfaktor
  // Ti         -> Nachstellzeit (I-Anteil)
  // Tv         -> Vorstellzeit (D-Anteil)
  // LimitUp    -> oberes Limit - Stellwert Begrenzung
  // LimitDown  -> unteres Limit - Stellwert Begrenzung
  // Ts         -> Reglertakt
  // y_k        -> Stellsignal begrenzt
  //////////////////////////////////////////////////////////////////////////////////////////////////
  // Definition Controller Variablen
	// Error Codes:
	const DWORD UPPER_LIMIT = 1;
	const DWORD LOWER_LIMIT = 2;
	const DWORD TS_NULL = 4;
	DWORD dwRetVal = 0;

	static double x_d = 0;		// Regelabweichung zum Zeitpunkt k	
	static double y_I = 0;      // I-Anteil(k)
	static double y_P = 0;      // P-Anteil(k)
	static double y_D = 0;      // D-Anteil(k)
	static double y_I1 = 0;	    // I-Anteil(k-1) 
	static double x_d1 = 0;     // Regelabweichung zum Zeitpunkt k-1
  ////////////////////////////////////////////////////////////////////////////////////////////////////
  if (!m_bInitDone)
  {
    m_bInitDone = true;
    x_d = 0;	// Regelabweichung zum Zeitpunkt k	
	y_I = 0;    // I-Anteil(k)
	y_P = 0;    // P-Anteil(k)
	y_D = 0;    // D-Anteil(k)
	y_I1 = 0;	// I-Anteil(k-1) 
	x_d1 = 0;   // Regelabweichung zum Zeitpunkt k-1
  }
  
  // deviation
  x_d = x_nom - x_act;

  // P-control
  y_P = Kp * x_d;

  // D-control
  if (Ts == 0)
	  dwRetVal = TS_NULL;

  if (Tv != 0 && Ts != 0)
  {
  	y_D = (Tv / Ts) * (x_d - x_d1);
  }
  else
  { // Vorhaltezeit = 0 => kein Differential berechnen
  	y_D= 0;
  }

  // control signal
  y_k = y_P + y_I + y_D;


  // upper limit control signal
  if (y_k > LimitUp)
  { // Wenn der Stellwert y_k am oberen Anschlag ist wird er auf den Anschlagwert gesetzt.
		// In dieser Situation erfolgt ein Aufsummieren des Integralanteils nur dann, wenn der
		// Istwert über dem Sollwert liegt.
    y_k = LimitUp;
    dwRetVal = UPPER_LIMIT;
		if (x_d < 0)
		{ // Integrate
			(Ti != 0) ? (y_I = y_I1 + ((Ts / (2 * Ti)) * (x_d + x_d1))) : (y_I = 0);
		}
  } 
	else if (y_k < LimitDown) // lower limit control signal
  { // Wenn der Stellwert y_k am unteren Anschlag ist wird er auf den Anschlagwert gesetzt.
		// In dieser Situation erfolgt ein Aufsummieren des Integralanteils nur dann, wenn der
		// Istwert unter dem Sollwert liegt.
    y_k = LimitDown;
    dwRetVal = LOWER_LIMIT;
		if (x_d > 0)
		{	// Integrate
			(Ti != 0) ? (y_I = y_I1 + ((Ts / (2 * Ti)) * (x_d + x_d1))) : (y_I = 0);
		}
  }
	else
	{	// Integrate
		(Ti != 0) ? (y_I = y_I1 + ((Ts / (2 * Ti)) * (x_d + x_d1))) : (y_I = 0);
	}

	// xd(k-1) = xd(k)
	x_d1 = x_d;

  // yi(k-1) = y(k)
  y_I1 = y_I;
  
  return dwRetVal;
  //## end CPCLogic::PID%1046071781.body
}

UINT CPCLogic::LimitVoltage (UINT p_uiValue)
{
  //## begin CPCLogic::LimitVoltage%1046071782.body preserve=yes
	
	UINT l_uiVLLimit = m_pContext->GetpConfig()->GetuiNominalVoltageLLimit();
	UINT l_uiVULimit = m_pContext->GetpConfig()->GetuiNominalVoltageULimit();

	if (p_uiValue < l_uiVLLimit)
	{
		return l_uiVLLimit;
	}
	else if (p_uiValue > l_uiVULimit)
	{
		return l_uiVULimit;
	}
	else
	{
		return p_uiValue;
	}

  //## end CPCLogic::LimitVoltage%1046071782.body
}

void CPCLogic::SetVoltage (UINT p_uiVolt)
{
  //## begin CPCLogic::SetVoltage%1057913135.body preserve=yes

	// get config parameter
	DWORD l_dwIDNomVoltage			= m_pContext->GetpConfig()->GetdwIDNomVoltage();
	UINT l_uiRegisterRange			= m_pContext->GetpConfig()->GetuiNominalVoltageRegisterRange();
	double l_dbNominalVoltageGain	= (double)m_pContext->GetpConfig()->GetuiNominalVoltageGain() / 1000;
	INT l_iNominalVoltageOffset		= m_pContext->GetpConfig()->GetiNominalVoltageOffset();
	UINT l_uiLmpNomValue			= 0;

	// p_uiVolt commes in [V]
	UINT l_uiVolt = LimitVoltage(p_uiVolt);
    
	// convert volts to adc counts
	l_uiLmpNomValue = (UINT)((l_dbNominalVoltageGain * l_uiVolt) / 1000 + l_iNominalVoltageOffset);

	// set hardware voltage output. round down is ok.
	if (m_bHardwarePresent)		
		IHIInterface::GetInstance()->SetDWord(l_dwIDNomVoltage, l_uiLmpNomValue);

  //## end CPCLogic::SetVoltage%1057913135.body
}

UINT CPCLogic::ActCurrent ()
{
  //## begin CPCLogic::ActCurrent%1057913136.body preserve=yes

	// Get values from the config.
	double l_dGain			= (double)m_pContext->GetpConfig()->GetuiIMeteringGain();
	double l_dADCOffset		= (double)m_pContext->GetpConfig()->GetiIMeteringADCOffset() / 1000;
	double l_dADCRange		= (double)m_pContext->GetpConfig()->GetuiIMeteringADCRange();
	double l_dRShunt		= (double)m_pContext->GetpConfig()->GetuiIMeteringRShunt() / 1000;
	double l_dADCVRef		= (double)m_pContext->GetpConfig()->GetuiIMeteringADCVRef() / 1000;
	double l_dILamp			= 0;
	DWORD l_dwIMeteringID	= m_pContext->GetpConfig()->GetdwIDActCurrent();
	UINT l_uiRegDigits		= 3000;
	
	// Read register digits from hi.
	if (m_bHardwarePresent)
		l_uiRegDigits = IHIInterface::GetInstance()->GetDWord(l_dwIMeteringID);

	CString l_sTrace;
	l_sTrace.Format(_T("ActCurrentDigits:%d"),l_uiRegDigits);
	CO_TRACE(PC_ID, l_sTrace);

	// Calculate actual lamp current  [A]
	l_dILamp = ((l_uiRegDigits - l_dADCOffset) / l_dADCRange) *  ( l_dADCVRef / (l_dGain * l_dRShunt) );

	// Make [mA]
	l_dILamp *= 1000; 

	return (UINT)l_dILamp; // [mA]
  //## end CPCLogic::ActCurrent%1057913136.body
}

UINT CPCLogic::ActVoltage ()
{
  //## begin CPCLogic::ActVoltage%1057913137.body preserve=yes

	// get parameter from config
	double l_dGain			= (double)m_pContext->GetpConfig()->GetuiVMeteringGain() / 1000000;
	double l_dADCOffset		= (double)m_pContext->GetpConfig()->GetiVMeteringADCOffset();
	double l_dADCRange		= (double)m_pContext->GetpConfig()->GetuiVMeteringADCRange();
	double l_dULamp			= 4600;
	double l_dUAct			= 0;
	double l_dVRef			= (double)m_pContext->GetpConfig()->GetuiVMeteringADCVRef()/1000;
	DWORD l_dwVMeteringID	= m_pContext->GetpConfig()->GetdwIDActVoltage();
	UINT l_uiRegDigits		= 2600;
	
	// Read register digits from hi.
	if (m_bHardwarePresent)
		l_uiRegDigits = IHIInterface::GetInstance()->GetDWord(l_dwVMeteringID);

	CString l_sTrace;
	l_sTrace.Format(_T("ActVoltageDigits:%d"), l_uiRegDigits);
	CO_TRACE(PC_ID, l_sTrace);

	// Calculate actual lamp voltage.
	l_dULamp = ( (l_uiRegDigits - l_dADCOffset) / l_dADCRange ) * (l_dVRef / l_dGain);

	// makes [mA]
	l_dULamp *= 1000;

	return (UINT)l_dULamp;	// [mV]

  //## end CPCLogic::ActVoltage%1057913137.body
}

DWORD CPCLogic::GetDWordPC (const DWORD p_dwID)
{
  //## begin CPCLogic::GetDWordPC%1061890359.body preserve=yes
	if (m_bHardwarePresent)
		// Set dword in process image.
		return IHIInterface::GetInstance()->GetDWord(p_dwID);
	else
		return 0;

  //## end CPCLogic::GetDWordPC%1061890359.body
}

void CPCLogic::SetDWordPC (const DWORD p_dwID, const DWORD p_dwValue)
{
  //## begin CPCLogic::SetDWordPC%1061890360.body preserve=yes
	if (m_bHardwarePresent)
		// Set dword in process image.
		IHIInterface::GetInstance()->SetDWord(p_dwID, p_dwValue);

  //## end CPCLogic::SetDWordPC%1061890360.body
}

void CPCLogic::PowerOn ()
{
  //## begin CPCLogic::PowerOn%1063700378.body preserve=yes

	// get config or profile stuff
	DWORD l_dwIDLampOnOff = m_pContext->GetpConfig()->GetdwIDLampOnOff();
	UINT l_uiPowerULimit = m_pContext->GetpProfile()->GetuiPowerErrorULimit(); // [mW]
	UINT l_uiPowerLLimit = m_pContext->GetpProfile()->GetuiPowerErrorLLimit(); // [mW]
	UINT l_uiNominalVoltageLLimit = m_pContext->GetpConfig()->GetuiNominalVoltageLLimit();

	// get actual power [mW]
	UINT l_uiPower = ActPower();

	// power over upper limit. -> exception.
	if (l_uiPower > l_uiPowerULimit)
	{
		CString l_sTrace;
		l_sTrace.Format(_T("Exeption in file: %s line: %d \n"),_T(__FILE__), __LINE__);
		CO_TRACE(PC_ID,l_sTrace);
		throw new XPCExceptionErrorShorted(PC_ID, IDE_PC_SHORTED, _T(__FILE__), __LINE__, 0);
	}
	
	// Power under lower limit. Switch on lamp.
	if (l_uiPower < l_uiPowerLLimit)
	{	
		// Switch lamp on.
		SelectLamp();
		SetVoltage(l_uiNominalVoltageLLimit);
		if (m_bHardwarePresent)
			IHIInterface::GetInstance()->SetDWord(l_dwIDLampOnOff, 1);
	}

  //## end CPCLogic::PowerOn%1063700378.body
}

UINT CPCLogic::ActPower ()
{
  //## begin CPCLogic::ActPower%1063700379.body preserve=yes
	UINT l_uiPower = 0;
    
	UINT l_uiVLampAct = ActVoltage();
	UINT l_uiILampAct = ActCurrent();
    
	l_uiPower = l_uiVLampAct * l_uiILampAct / 1000;
	
	return l_uiPower; // [mW]
  //## end CPCLogic::ActPower%1063700379.body
}

void CPCLogic::PowerOff ()
{
  //## begin CPCLogic::PowerOff%1063954791.body preserve=yes
	// Get config or profile stuff.
	DWORD l_dwIDLampOnOff = m_pContext->GetpConfig()->GetdwIDLampOnOff();
	SelectLamp();
	// Switch lamp off.
	if (m_bHardwarePresent)
		IHIInterface::GetInstance()->SetDWord(l_dwIDLampOnOff, 0);
  //## end CPCLogic::PowerOff%1063954791.body
}

void CPCLogic::SelectLamp ()
{
  //## begin CPCLogic::SelectLamp%1075281202.body preserve=yes

	EPILamp eLamp = m_pContext->GetpConfig()->GeteActiveLamp();
	DWORD l_dwLampSelection = m_pContext->GetpConfig()->GetdwIDLampSelection();
	DWORD l_dwValue = 0;

	switch (eLamp)
	{
	case eLampPrimary:
		l_dwValue = 0; // 0 = primary
		break;

	case eLampSecondary:
		l_dwValue = 1; // 1 = secondary
		break;

	default:
		ASSERT(false); // lamp type undefined
	}

	if (m_bHardwarePresent)
		IHIInterface::GetInstance()->SetDWord(l_dwLampSelection, l_dwValue);

  //## end CPCLogic::SelectLamp%1075281202.body
}

bool CPCLogic::IncVoltage ()
{
  //## begin CPCLogic::IncVoltage%1077174616.body preserve=yes
	return 0;
  //## end CPCLogic::IncVoltage%1077174616.body
}

void CPCLogic::SetDAC (const DWORD p_dwDigits)
{
  //## begin CPCLogic::SetDAC%1090333015.body preserve=yes

	// get config parameter
	DWORD l_dwIDNomVoltage = m_pContext->GetpConfig()->GetdwIDNomVoltage();

	if (m_bHardwarePresent)
		// Set dword in process image.
		IHIInterface::GetInstance()->SetDWord(l_dwIDNomVoltage, p_dwDigits);

  //## end CPCLogic::SetDAC%1090333015.body
}

//## Get and Set Operations for Class Attributes (implementation)

int CPCLogic::GetiLoopCounter ()
{
  //## begin CPCLogic::GetiLoopCounter%3EED76CC0763.get preserve=no
  return m_iLoopCounter;
  //## end CPCLogic::GetiLoopCounter%3EED76CC0763.get
}

void CPCLogic::SetiLoopCounter (int value)
{
  //## begin CPCLogic::SetiLoopCounter%3EED76CC0763.set preserve=no
  m_iLoopCounter = value;
  //## end CPCLogic::SetiLoopCounter%3EED76CC0763.set
}

bool CPCLogic::GetbInitDone ()
{
  //## begin CPCLogic::GetbInitDone%3EED76CC0765.get preserve=no
  return m_bInitDone;
  //## end CPCLogic::GetbInitDone%3EED76CC0765.get
}

void CPCLogic::SetbInitDone (bool value)
{
  //## begin CPCLogic::SetbInitDone%3EED76CC0765.set preserve=no
  m_bInitDone = value;
  //## end CPCLogic::SetbInitDone%3EED76CC0765.set
}

int CPCLogic::GetiSoftStartLoopCnt ()
{
  //## begin CPCLogic::GetiSoftStartLoopCnt%3F13B01D01EA.get preserve=no
  return m_iSoftStartLoopCnt;
  //## end CPCLogic::GetiSoftStartLoopCnt%3F13B01D01EA.get
}

void CPCLogic::SetiSoftStartLoopCnt (int value)
{
  //## begin CPCLogic::SetiSoftStartLoopCnt%3F13B01D01EA.set preserve=no
  m_iSoftStartLoopCnt = value;
  //## end CPCLogic::SetiSoftStartLoopCnt%3F13B01D01EA.set
}

DWORD& CPCLogic::GetdwTimeBase ()
{
  //## begin CPCLogic::GetdwTimeBase%403323AB0243.get preserve=no
  return m_dwTimeBase;
  //## end CPCLogic::GetdwTimeBase%403323AB0243.get
}

void CPCLogic::SetdwTimeBase (const DWORD& value)
{
  //## begin CPCLogic::SetdwTimeBase%403323AB0243.set preserve=no
  m_dwTimeBase = value;
  //## end CPCLogic::SetdwTimeBase%403323AB0243.set
}

UINT CPCLogic::GetuiSettlingTime ()
{
  //## begin CPCLogic::GetuiSettlingTime%4035D5A603E0.get preserve=no
  return m_uiSettlingTime;
  //## end CPCLogic::GetuiSettlingTime%4035D5A603E0.get
}

void CPCLogic::SetuiSettlingTime (UINT value)
{
  //## begin CPCLogic::SetuiSettlingTime%4035D5A603E0.set preserve=no
  m_uiSettlingTime = value;
  //## end CPCLogic::SetuiSettlingTime%4035D5A603E0.set
}

//## Get and Set Operations for Associations (implementation)

CCOSyncObject * CPCLogic::GetpStartSyncObject ()
{
  //## begin CPCLogic::GetpStartSyncObject%4035E0F001FC.get preserve=no
  return m_pStartSyncObject;
  //## end CPCLogic::GetpStartSyncObject%4035E0F001FC.get
}

void CPCLogic::SetpStartSyncObject (CCOSyncObject * value)
{
  //## begin CPCLogic::SetpStartSyncObject%4035E0F001FC.set preserve=yes
	if (m_pStartSyncObject)
		m_pStartSyncObject->ReleaseRef();

	m_pStartSyncObject = value;
	if (m_pStartSyncObject)
		m_pStartSyncObject->AddRef();
  //## end CPCLogic::SetpStartSyncObject%4035E0F001FC.set
}

// Additional Declarations
  //## begin CPCLogic%3EED76CC0744.declarations preserve=yes
  //## end CPCLogic%3EED76CC0744.declarations

//## begin module%3EED769F0393.epilog preserve=yes
//## end module%3EED769F0393.epilog
