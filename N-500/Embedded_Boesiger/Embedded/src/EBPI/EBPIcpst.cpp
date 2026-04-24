//## begin module%3F4239B700D0.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3F4239B700D0.cm

//## begin module%3F4239B700D0.cp preserve=no
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
//## end module%3F4239B700D0.cp

//## Module: EBPIcpst%3F4239B700D0; Package body
//## Subsystem: EBPI (PC Interface)%3DA48803001C
//## Source file: R:\Embedded\Src\EBPI\EBPIcpst.cpp

// stdafx
#include "stdafx.h"
//## begin module%3F4239B700D0.additionalIncludes preserve=no
//## end module%3F4239B700D0.additionalIncludes

//## begin module%3F4239B700D0.includes preserve=yes
#include "atlbase.h"
//## end module%3F4239B700D0.includes

// EBPIcpst
#include "EBPIcpst.h"
//## begin module%3F4239B700D0.declarations preserve=no
//## end module%3F4239B700D0.declarations

//## begin module%3F4239B700D0.additionalDeclarations preserve=yes
static const WCHAR ZERO[]= _T("0");
static const WCHAR ONE[]= _T("1");

#ifdef _WIN32_WCE
static const WCHAR sComponentStateKey[] = _T("SOFTWARE\\Buchi\\NIRWare");
#else
static const WCHAR sComponentStateKey[] = _T("SOFTWARE\\GEMINIII\\SOFTWARE\\Buchi\\NIRWare\\ComponentState");
#endif
//## end module%3F4239B700D0.additionalDeclarations


// Class CPIComponentsState 

//## begin CPIComponentsState::pInstance%3F4235EA0014.role preserve=no  public: static CPIComponentsState {1..1 -> 1..1RFHN}
CPIComponentsState *CPIComponentsState::s_pInstance;
//## end CPIComponentsState::pInstance%3F4235EA0014.role


CPIComponentsState::CPIComponentsState()
  //## begin CPIComponentsState::CPIComponentsState%.hasinit preserve=no
  //## end CPIComponentsState::CPIComponentsState%.hasinit
  //## begin CPIComponentsState::CPIComponentsState%.initialization preserve=yes
  //## end CPIComponentsState::CPIComponentsState%.initialization
{
  //## begin CPIComponentsState::CPIComponentsState%.body preserve=yes
  //## end CPIComponentsState::CPIComponentsState%.body
}


CPIComponentsState::~CPIComponentsState()
{
  //## begin CPIComponentsState::~CPIComponentsState%.body preserve=yes
  //## end CPIComponentsState::~CPIComponentsState%.body
}



//## Other Operations (implementation)
void CPIComponentsState::Create ()
{
  //## begin CPIComponentsState::Create%1061301417.body preserve=yes

    ASSERT(s_pInstance == NULL);
    s_pInstance = new CPIComponentsState();

  //## end CPIComponentsState::Create%1061301417.body
}

void CPIComponentsState::Delete ()
{
  //## begin CPIComponentsState::Delete%1061301418.body preserve=yes

    if (s_pInstance)
    {
        delete s_pInstance;
    }

    s_pInstance = NULL;

  //## end CPIComponentsState::Delete%1061301418.body
}

CPIComponentsState* CPIComponentsState::GetInstance ()
{
  //## begin CPIComponentsState::GetInstance%1061301419.body preserve=yes

    return s_pInstance;

  //## end CPIComponentsState::GetInstance%1061301419.body
}

bool CPIComponentsState::GetComponentState (const CString& p_sComponentId)
{
  //## begin CPIComponentsState::GetComponentState%1061301420.body preserve=yes

	// Local declarations //
	CString l_sRegName(p_sComponentId);
    l_sRegName.MakeUpper();

	CRegKey  l_oRegKey;

	bool l_bRetVal;

  // Open key. //
  if (l_oRegKey.Open(HKEY_LOCAL_MACHINE, sComponentStateKey) != ERROR_SUCCESS)
	{
		// Key does not exit -> Create it and set it to true.
		SetComponentState(l_sRegName, true);

		// Retry to open.
		if (l_oRegKey.Open(HKEY_LOCAL_MACHINE, sComponentStateKey) != ERROR_SUCCESS)
			ASSERT(false);
	}

	// Query value.
	WCHAR l_sRegValue[12];	// zero terminated
	ULONG l_ulSize = 10;		// zero terminated

#ifdef _WIN32_WCE
	HRESULT l_hrRes = l_oRegKey.QueryValue(l_sRegValue, l_sRegName, &l_ulSize);
#else
	HRESULT l_hrRes = l_oRegKey.QueryStringValue(l_sRegName, l_sRegValue, &l_ulSize);
#endif

	if (l_hrRes != ERROR_SUCCESS)
	{
		// Reg entry not found. Creat one and set it to true.
		SetComponentState(l_sRegName, true);
		wcscpy(l_sRegValue, ONE);
	}

	// Check range.
	if (!wcscmp(l_sRegValue, ONE))
		// Assign return value.
		l_bRetVal = true;
	else if (!wcscmp(l_sRegValue, ZERO))
		 l_bRetVal = false;
	else
		ASSERT(false);
  
	// Close RegKey.
	if (l_oRegKey.Close())
		ASSERT(false);

    return l_bRetVal;

  //## end CPIComponentsState::GetComponentState%1061301420.body
}

void CPIComponentsState::SetComponentState (const CString& p_sComponentId, const bool p_bActive)
{
  //## begin CPIComponentsState::SetComponentState%1061301421.body preserve=yes
	
	// Reg entry name.
	CString l_sRegName(p_sComponentId);
	l_sRegName.MakeUpper();
	
	// Reg entry value.
	CString l_sRegValue;
	p_bActive ? l_sRegValue = ONE : l_sRegValue = ZERO;
    
	CRegKey  l_oRegKey;

	// Open key. 
	if (l_oRegKey.Open(HKEY_LOCAL_MACHINE, sComponentStateKey, KEY_WRITE) !=  ERROR_SUCCESS)
	{
		// Could not open. Create it.
		if (l_oRegKey.Create(HKEY_LOCAL_MACHINE, sComponentStateKey) != ERROR_SUCCESS)
			ASSERT(false); // Could not create.
	}

#ifdef _WIN32_WCE
	HRESULT l_hrRes = l_oRegKey.SetValue(l_sRegValue, l_sRegName);
#else
	HRESULT l_hrRes = l_oRegKey.SetStringValue(l_sRegName, l_sRegValue);
#endif

	if (l_hrRes != ERROR_SUCCESS)
		ASSERT(false);	// Value not set.

	// Close key.
	if (l_oRegKey.Close() != ERROR_SUCCESS)
		ASSERT(false);  // Could not set value.

  //## end CPIComponentsState::SetComponentState%1061301421.body
}

// Additional Declarations
  //## begin CPIComponentsState%3F4235EA0005.declarations preserve=yes
  //## end CPIComponentsState%3F4235EA0005.declarations

//## begin module%3F4239B700D0.epilog preserve=yes
//## end module%3F4239B700D0.epilog
