//## begin module%3DF5AF6101F4.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3DF5AF6101F4.cm

//## begin module%3DF5AF6101F4.cp preserve=no
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
//## end module%3DF5AF6101F4.cp

//## Module: EBIOintf%3DF5AF6101F4; Package body
//## Subsystem: EBIO (Analog- / Digital- In-/Output)%3DF5A4B6036B
//## Source file: R:\Embedded\src\EBIO\EBIOintf.cpp

// stdafx
#include "stdafx.h"
//## begin module%3DF5AF6101F4.additionalIncludes preserve=no
//## end module%3DF5AF6101F4.additionalIncludes

//## begin module%3DF5AF6101F4.includes preserve=yes
//## end module%3DF5AF6101F4.includes

// EBPIcpst
#include "EBPIcpst.h"
// EBPIenum
#include "EBPIenum.h"
// EBIOstat
#include "EBIOstat.h"
// EBIOintf
#include "EBIOintf.h"
// EBIOident
#include "EBIOident.h"
// EBHIintf
#include "EBHIintf.h"


//## begin module%3DF5AF6101F4.declarations preserve=no
//## end module%3DF5AF6101F4.declarations

//## begin module%3DF5AF6101F4.additionalDeclarations preserve=yes
#define DUMMY_RETURN {  \
    CCOSyncObject* l_pSyncObj = new CCOSyncObject();		\
    l_pSyncObj->SignalCompletion();							\
    return l_pSyncObj;										\
}

#define DUMMY_RETURN_INT {  \
    CCOSyncObjectInt* l_pSyncObjInt = new CCOSyncObjectInt(0);	\
    l_pSyncObjInt->SignalCompletion();							\
    return l_pSyncObjInt;										\
}

#define DUMMY_RETURN_BOOL {  \
    CCOSyncObjectBool* l_pSyncObjBool = new CCOSyncObjectBool(false);	\
    l_pSyncObjBool->SignalCompletion();									\
    return l_pSyncObjBool;												\
}

//## end module%3DF5AF6101F4.additionalDeclarations


// Class CIOOutputAnalogInterface 




CIOOutputAnalogInterface::CIOOutputAnalogInterface (UINT p_uiID)
  //## begin CIOOutputAnalogInterface::CIOOutputAnalogInterface%1039513443.hasinit preserve=no
      : m_uiID(p_uiID), m_dwNominalValue(0)
  //## end CIOOutputAnalogInterface::CIOOutputAnalogInterface%1039513443.hasinit
  //## begin CIOOutputAnalogInterface::CIOOutputAnalogInterface%1039513443.initialization preserve=yes
  ,IPIOutputAnalogInterface(IOAO_ID)
  //## end CIOOutputAnalogInterface::CIOOutputAnalogInterface%1039513443.initialization
{
  //## begin CIOOutputAnalogInterface::CIOOutputAnalogInterface%1039513443.body preserve=yes

	m_bHardwarePresent = CPIComponentsState::GetInstance()->GetComponentState(IO_ID);
	CString l_sTrace;
	CString l_sDummy(IOAO_ID);
	
	if (m_bHardwarePresent)
	{
		l_sTrace.Format( _T(" Device: ") + l_sDummy + _T(" ID: %d ") + _T("HardwarePresent: Yes"), m_uiID);
	}
	else
	{
		l_sTrace.Format( _T(" Device: ") + l_sDummy + _T(" ID: %d ") + _T("HardwarePresent: No"), m_uiID);
	}
    
	CO_TRACE(IOAS_ID, l_sTrace);

  //## end CIOOutputAnalogInterface::CIOOutputAnalogInterface%1039513443.body
}


CIOOutputAnalogInterface::~CIOOutputAnalogInterface()
{
  //## begin CIOOutputAnalogInterface::~CIOOutputAnalogInterface%.body preserve=yes
  //## end CIOOutputAnalogInterface::~CIOOutputAnalogInterface%.body
}



//## Other Operations (implementation)
CCOSyncObject* CIOOutputAnalogInterface::Startup ()
{
  //## begin CIOOutputAnalogInterface::Startup%1061910451.body preserve=yes
	DUMMY_RETURN
  //## end CIOOutputAnalogInterface::Startup%1061910451.body
}

CCOSyncObject* CIOOutputAnalogInterface::Shutdown ()
{
  //## begin CIOOutputAnalogInterface::Shutdown%1061910452.body preserve=yes
	DUMMY_RETURN
  //## end CIOOutputAnalogInterface::Shutdown%1061910452.body
}

CCOSyncObject* CIOOutputAnalogInterface::ConnectionLost ()
{
  //## begin CIOOutputAnalogInterface::ConnectionLost%1061910454.body preserve=yes
	DUMMY_RETURN
  //## end CIOOutputAnalogInterface::ConnectionLost%1061910454.body
}

CCOSyncObject* CIOOutputAnalogInterface::ConnectionEstablished ()
{
  //## begin CIOOutputAnalogInterface::ConnectionEstablished%1061910453.body preserve=yes
	DUMMY_RETURN
  //## end CIOOutputAnalogInterface::ConnectionEstablished%1061910453.body
}

UINT CIOOutputAnalogInterface::GetuiID ()
{
  //## begin CIOOutputAnalogInterface::GetuiID%1039513446.body preserve=yes
	return m_uiID;
  //## end CIOOutputAnalogInterface::GetuiID%1039513446.body
}

CCOSyncObject* CIOOutputAnalogInterface::SetValue (INT p_iValue)
{
  //## begin CIOOutputAnalogInterface::SetValue%1039513447.body preserve=yes
	CO_TRACE1(IOAO_ID, _T("OutputAnalog ID: %d SetValue"), m_uiID);

	if (m_bHardwarePresent)														
	{
		CHIInterface::GetInstance()->SetDWord((DWORD)m_uiID,(DWORD)p_iValue);
	}

    m_dwNominalValue = (DWORD)p_iValue;

	DUMMY_RETURN
  //## end CIOOutputAnalogInterface::SetValue%1039513447.body
}

CCOSyncObjectInt* CIOOutputAnalogInterface::GetValue ()
{
  //## begin CIOOutputAnalogInterface::GetValue%1039513448.body preserve=yes
	DWORD l_iValue = m_dwNominalValue;

	CCOSyncObjectInt* l_pSyncObjInt = new CCOSyncObjectInt(l_iValue);		
    l_pSyncObjInt->SignalCompletion();				
	CO_TRACE1(IOAO_ID, _T("OutputAnalog ID: %d GetValue"), m_uiID);
    return l_pSyncObjInt;													 
  //## end CIOOutputAnalogInterface::GetValue%1039513448.body
}

// Additional Declarations
  //## begin CIOOutputAnalogInterface%3DF5BE8B0148.declarations preserve=yes
  //## end CIOOutputAnalogInterface%3DF5BE8B0148.declarations

// Class CIOSensorAnalogInterface 



CIOSensorAnalogInterface::CIOSensorAnalogInterface (UINT p_uiID)
  //## begin CIOSensorAnalogInterface::CIOSensorAnalogInterface%1039513449.hasinit preserve=no
      : m_uiID(p_uiID)
  //## end CIOSensorAnalogInterface::CIOSensorAnalogInterface%1039513449.hasinit
  //## begin CIOSensorAnalogInterface::CIOSensorAnalogInterface%1039513449.initialization preserve=yes
  ,IPISensorAnalogInterface(IOAS_ID)
  //## end CIOSensorAnalogInterface::CIOSensorAnalogInterface%1039513449.initialization
{
  //## begin CIOSensorAnalogInterface::CIOSensorAnalogInterface%1039513449.body preserve=yes

	m_bHardwarePresent = CPIComponentsState::GetInstance()->GetComponentState(IO_ID);
	CString l_sTrace;
	CString l_sDummy(IOAS_ID);
	
	if (m_bHardwarePresent)
	{
		l_sTrace.Format( _T(" Device: ") + l_sDummy + _T(" ID: %d ") + _T("HardwarePresent: Yes"), m_uiID);
	}
	else
	{
		l_sTrace.Format( _T(" Device: ") + l_sDummy + _T(" ID: %d ") + _T("HardwarePresent: No"), m_uiID);
	}
    
	CO_TRACE(IOAS_ID, l_sTrace);

  //## end CIOSensorAnalogInterface::CIOSensorAnalogInterface%1039513449.body
}


CIOSensorAnalogInterface::~CIOSensorAnalogInterface()
{
  //## begin CIOSensorAnalogInterface::~CIOSensorAnalogInterface%.body preserve=yes
  //## end CIOSensorAnalogInterface::~CIOSensorAnalogInterface%.body
}



//## Other Operations (implementation)
CCOSyncObject* CIOSensorAnalogInterface::Startup ()
{
  //## begin CIOSensorAnalogInterface::Startup%1039513450.body preserve=yes
	DUMMY_RETURN
  //## end CIOSensorAnalogInterface::Startup%1039513450.body
}

CCOSyncObject* CIOSensorAnalogInterface::Shutdown ()
{
  //## begin CIOSensorAnalogInterface::Shutdown%1039513451.body preserve=yes
	DUMMY_RETURN
  //## end CIOSensorAnalogInterface::Shutdown%1039513451.body
}

CCOSyncObject* CIOSensorAnalogInterface::ConnectionEstablished ()
{
  //## begin CIOSensorAnalogInterface::ConnectionEstablished%1055744810.body preserve=yes
	DUMMY_RETURN
  //## end CIOSensorAnalogInterface::ConnectionEstablished%1055744810.body
}

CCOSyncObject* CIOSensorAnalogInterface::ConnectionLost ()
{
  //## begin CIOSensorAnalogInterface::ConnectionLost%1055744811.body preserve=yes
	DUMMY_RETURN
  //## end CIOSensorAnalogInterface::ConnectionLost%1055744811.body
}

UINT CIOSensorAnalogInterface::GetuiID ()
{
  //## begin CIOSensorAnalogInterface::GetuiID%1039513452.body preserve=yes
	return m_uiID;
  //## end CIOSensorAnalogInterface::GetuiID%1039513452.body
}

CCOSyncObjectInt* CIOSensorAnalogInterface::GetValue ()
{
  //## begin CIOSensorAnalogInterface::GetValue%1039513453.body preserve=yes
	int l_iValue = 0;

	if (m_bHardwarePresent)			
	{
		l_iValue = int(CHIInterface::GetInstance()->GetDWord((DWORD)m_uiID));	
	}

	CCOSyncObjectInt* l_pSyncObjInt = new CCOSyncObjectInt(l_iValue);		
    l_pSyncObjInt->SignalCompletion();			
	CO_TRACE1(IOAS_ID, _T("SensorAnalog ID: %d GetValue"), m_uiID);
	return l_pSyncObjInt;													 
  //## end CIOSensorAnalogInterface::GetValue%1039513453.body
}

// Additional Declarations
  //## begin CIOSensorAnalogInterface%3DF5BE9E037A.declarations preserve=yes
  //## end CIOSensorAnalogInterface%3DF5BE9E037A.declarations

// Class CIOOutputDigitalInterface 





CIOOutputDigitalInterface::CIOOutputDigitalInterface (UINT p_uiID)
  //## begin CIOOutputDigitalInterface::CIOOutputDigitalInterface%1039513454.hasinit preserve=no
      : m_uiID(p_uiID), m_bNomialState(false), m_ePolarity(eSensorActiveHigh)
  //## end CIOOutputDigitalInterface::CIOOutputDigitalInterface%1039513454.hasinit
  //## begin CIOOutputDigitalInterface::CIOOutputDigitalInterface%1039513454.initialization preserve=yes
  ,IPIOutputDigitalInterface(IODO_ID)
  //## end CIOOutputDigitalInterface::CIOOutputDigitalInterface%1039513454.initialization
{
  //## begin CIOOutputDigitalInterface::CIOOutputDigitalInterface%1039513454.body preserve=yes

	m_bHardwarePresent = CPIComponentsState::GetInstance()->GetComponentState(IO_ID);
	CString l_sTrace;
	CString l_sDummy(IODO_ID);
	
	if (m_bHardwarePresent)
	{
		l_sTrace.Format( _T(" Device: ") + l_sDummy + _T(" ID: %d ") + _T("HardwarePresent: Yes"), m_uiID);
	}
	else
	{
		l_sTrace.Format( _T(" Device: ") + l_sDummy + _T(" ID: %d ") + _T("HardwarePresent: No"), m_uiID);
	}
    
	CO_TRACE(IOAS_ID, l_sTrace);

  //## end CIOOutputDigitalInterface::CIOOutputDigitalInterface%1039513454.body
}


CIOOutputDigitalInterface::~CIOOutputDigitalInterface()
{
  //## begin CIOOutputDigitalInterface::~CIOOutputDigitalInterface%.body preserve=yes
  //## end CIOOutputDigitalInterface::~CIOOutputDigitalInterface%.body
}



//## Other Operations (implementation)
CCOSyncObject* CIOOutputDigitalInterface::Startup ()
{
  //## begin CIOOutputDigitalInterface::Startup%1039513455.body preserve=yes
	DUMMY_RETURN
  //## end CIOOutputDigitalInterface::Startup%1039513455.body
}

CCOSyncObject* CIOOutputDigitalInterface::Shutdown ()
{
  //## begin CIOOutputDigitalInterface::Shutdown%1039513456.body preserve=yes
	DUMMY_RETURN
  //## end CIOOutputDigitalInterface::Shutdown%1039513456.body
}

CCOSyncObject* CIOOutputDigitalInterface::ConnectionEstablished ()
{
  //## begin CIOOutputDigitalInterface::ConnectionEstablished%1055744812.body preserve=yes
	DUMMY_RETURN
  //## end CIOOutputDigitalInterface::ConnectionEstablished%1055744812.body
}

CCOSyncObject* CIOOutputDigitalInterface::ConnectionLost ()
{
  //## begin CIOOutputDigitalInterface::ConnectionLost%1055744813.body preserve=yes
	DUMMY_RETURN
  //## end CIOOutputDigitalInterface::ConnectionLost%1055744813.body
}

UINT CIOOutputDigitalInterface::GetuiID ()
{
  //## begin CIOOutputDigitalInterface::GetuiID%1039513457.body preserve=yes
	return m_uiID;
  //## end CIOOutputDigitalInterface::GetuiID%1039513457.body
}

CCOSyncObject* CIOOutputDigitalInterface::Set ()
{
  //## begin CIOOutputDigitalInterface::Set%1039513458.body preserve=yes

	CO_TRACE1(IODO_ID, _T("OutputDigital ID: %d Set"), m_uiID);

    bool l_bSetValue = CheckPolarity(true);
	if (m_bHardwarePresent)
    {
		IHIInterface::GetInstance()->SetDWord((DWORD)m_uiID, (DWORD)l_bSetValue);
    }
	else
	{
		CIODigitalState::SetState((DWORD)m_uiID, true);
	}

    m_bNomialState = l_bSetValue;

	DUMMY_RETURN
  //## end CIOOutputDigitalInterface::Set%1039513458.body
}

CCOSyncObject* CIOOutputDigitalInterface::Clear ()
{
  //## begin CIOOutputDigitalInterface::Clear%1039513459.body preserve=yes

	CO_TRACE1(IODO_ID, _T("OutputDigital ID: %d Clear"), m_uiID);

    bool l_bClearValue = CheckPolarity(false);
	if (m_bHardwarePresent)
	{
		IHIInterface::GetInstance()->SetDWord((DWORD)m_uiID, (DWORD)l_bClearValue);
	}
	else
	{
		CIODigitalState::SetState((DWORD)m_uiID, l_bClearValue);
	}

    m_bNomialState = l_bClearValue;

	DUMMY_RETURN
  //## end CIOOutputDigitalInterface::Clear%1039513459.body
}

CCOSyncObjectBool* CIOOutputDigitalInterface::IsActive ()
{
  //## begin CIOOutputDigitalInterface::IsActive%1039513460.body preserve=yes
	// Declaration
	DWORD l_dwValue = 0;
	bool l_bIsActive = false;

	if (m_bHardwarePresent)
	{
		// return nominal state		
		l_bIsActive = m_bNomialState;
	}

    l_bIsActive = CheckPolarity(l_bIsActive);
	if (l_bIsActive)
	{
		CO_TRACE1(IODO_ID, _T("OutputDigital ID: %d TRUE"), m_uiID);
	}
	else
	{
		CO_TRACE1(IODO_ID, _T("OutputDigital  ID: %d FALSE"), m_uiID);
	}

	CCOSyncObjectBool *l_pSyncObjectBool = new CCOSyncObjectBool(l_bIsActive);
	l_pSyncObjectBool->SignalCompletion();

	return l_pSyncObjectBool;
  //## end CIOOutputDigitalInterface::IsActive%1039513460.body
}

CCOSyncObject* CIOOutputDigitalInterface::SetPolarity (EPIPolarity p_ePolarity)
{
  //## begin CIOOutputDigitalInterface::SetPolarity%1039513461.body preserve=yes
    m_ePolarity = p_ePolarity;
	DUMMY_RETURN
  //## end CIOOutputDigitalInterface::SetPolarity%1039513461.body
}

bool CIOOutputDigitalInterface::CheckPolarity (const bool p_bIsActive)
{
  //## begin CIOOutputDigitalInterface::CheckPolarity%1071671742.body preserve=yes
    bool l_bIsActive = p_bIsActive;

    if (m_ePolarity == eSensorActiveLow)
        l_bIsActive = !l_bIsActive;

    return l_bIsActive;
  //## end CIOOutputDigitalInterface::CheckPolarity%1071671742.body
}

// Additional Declarations
  //## begin CIOOutputDigitalInterface%3DF5BEB603B9.declarations preserve=yes
  //## end CIOOutputDigitalInterface%3DF5BEB603B9.declarations

// Class CIOSensorDigitalInterface 




CIOSensorDigitalInterface::CIOSensorDigitalInterface (UINT p_uiID)
  //## begin CIOSensorDigitalInterface::CIOSensorDigitalInterface%1039513462.hasinit preserve=no
      : m_uiID(p_uiID), m_ePolarity(eSensorActiveHigh)
  //## end CIOSensorDigitalInterface::CIOSensorDigitalInterface%1039513462.hasinit
  //## begin CIOSensorDigitalInterface::CIOSensorDigitalInterface%1039513462.initialization preserve=yes
  ,IPISensorDigitalInterface(IODS_ID)
  //## end CIOSensorDigitalInterface::CIOSensorDigitalInterface%1039513462.initialization
{
  //## begin CIOSensorDigitalInterface::CIOSensorDigitalInterface%1039513462.body preserve=yes

	m_bHardwarePresent = CPIComponentsState::GetInstance()->GetComponentState(IO_ID);
	CString l_sTrace;
	CString l_sDummy(IODS_ID);

	if (m_bHardwarePresent)
	{
		l_sTrace.Format( _T(" Device: ") + l_sDummy + _T(" ID: %d ") + _T("HardwarePresent: Yes"), m_uiID);
	}
	else
	{
		l_sTrace.Format( _T(" Device: ") + l_sDummy + _T(" ID: %d ") + _T("HardwarePresent: No"), m_uiID);
	}
    
	CO_TRACE(IOAS_ID, l_sTrace);

  //## end CIOSensorDigitalInterface::CIOSensorDigitalInterface%1039513462.body
}


CIOSensorDigitalInterface::~CIOSensorDigitalInterface()
{
  //## begin CIOSensorDigitalInterface::~CIOSensorDigitalInterface%.body preserve=yes
  //## end CIOSensorDigitalInterface::~CIOSensorDigitalInterface%.body
}



//## Other Operations (implementation)
CCOSyncObject* CIOSensorDigitalInterface::Startup ()
{
  //## begin CIOSensorDigitalInterface::Startup%1039513463.body preserve=yes
	DUMMY_RETURN
  //## end CIOSensorDigitalInterface::Startup%1039513463.body
}

CCOSyncObject* CIOSensorDigitalInterface::Shutdown ()
{
  //## begin CIOSensorDigitalInterface::Shutdown%1039513464.body preserve=yes
	DUMMY_RETURN
  //## end CIOSensorDigitalInterface::Shutdown%1039513464.body
}

CCOSyncObject* CIOSensorDigitalInterface::ConnectionEstablished ()
{
  //## begin CIOSensorDigitalInterface::ConnectionEstablished%1055744814.body preserve=yes
	DUMMY_RETURN
  //## end CIOSensorDigitalInterface::ConnectionEstablished%1055744814.body
}

CCOSyncObject* CIOSensorDigitalInterface::ConnectionLost ()
{
  //## begin CIOSensorDigitalInterface::ConnectionLost%1055744815.body preserve=yes
	DUMMY_RETURN
  //## end CIOSensorDigitalInterface::ConnectionLost%1055744815.body
}

UINT CIOSensorDigitalInterface::GetuiID ()
{
  //## begin CIOSensorDigitalInterface::GetuiID%1039513465.body preserve=yes
	return m_uiID;
  //## end CIOSensorDigitalInterface::GetuiID%1039513465.body
}

CCOSyncObjectBool* CIOSensorDigitalInterface::IsActive ()
{
  //## begin CIOSensorDigitalInterface::IsActive%1039513466.body preserve=yes
	
	// Declaration
	DWORD l_dwValue = 0;
	bool l_bIsActive = false;

	if (m_bHardwarePresent)
	{
		// Get value from process image
		l_dwValue = IHIInterface::GetInstance()->GetDWord((DWORD)m_uiID);
		l_bIsActive = (l_dwValue == 1);
	}
	else
	{    
		l_bIsActive = CIODigitalState::GetState((DWORD)m_uiID);
	}
	
    l_bIsActive = CheckPolarity(l_bIsActive);
	if (l_bIsActive)
	{
		CO_TRACE1(IODO_ID, _T("SensorDigital ID: %d TRUE"), m_uiID);
	}
	else
	{
		CO_TRACE1(IODO_ID, _T("SensorDigital  ID: %d FALSE"), m_uiID);
	}

	CCOSyncObjectBool *l_pSyncObjectBool = new CCOSyncObjectBool(l_bIsActive);
	l_pSyncObjectBool->SignalCompletion();

	return l_pSyncObjectBool;

  //## end CIOSensorDigitalInterface::IsActive%1039513466.body
}

CCOSyncObject* CIOSensorDigitalInterface::SetPolarity (EPIPolarity p_ePolarity)
{
  //## begin CIOSensorDigitalInterface::SetPolarity%1039513467.body preserve=yes
    m_ePolarity = p_ePolarity;
	DUMMY_RETURN
  //## end CIOSensorDigitalInterface::SetPolarity%1039513467.body
}

bool CIOSensorDigitalInterface::CheckPolarity (const bool p_bIsActive)
{
  //## begin CIOSensorDigitalInterface::CheckPolarity%1071671741.body preserve=yes
    bool l_bIsActive = p_bIsActive;

    if (m_ePolarity == eSensorActiveLow)
        l_bIsActive = !l_bIsActive;

    return l_bIsActive;
  //## end CIOSensorDigitalInterface::CheckPolarity%1071671741.body
}

// Additional Declarations
  //## begin CIOSensorDigitalInterface%3DF5BECD030D.declarations preserve=yes
  //## end CIOSensorDigitalInterface%3DF5BECD030D.declarations

//## begin module%3DF5AF6101F4.epilog preserve=yes
//## end module%3DF5AF6101F4.epilog
