// DlgSystemControl.cpp : implementation file
//
#include "stdafx.h"
#include "Iphlpapi.h"
#include "resource.h"
#include "EBNFDlgSystemControl.h"
#include "EBNFDlgSystemCompState.h"

#include "EBCOexcp.h"
#include "EBPIfact.h"
#include "EBPItype.h"

#include "EBSYintf.h"
#include "EBSYmain.h"

#include "EBHIintf.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgSystemControl dialog


DlgSystemControl::DlgSystemControl(CWnd* pParent /*=NULL*/)
	: CDialog(DlgSystemControl::IDD, pParent), m_uiTimerID(1)
{
	//{{AFX_DATA_INIT(DlgSystemControl)
	m_sSystemState = _T("");
	m_sSysConnState = _T("");
	m_sVersion = _T("");
	m_sFPGAVersion = _T("");
	m_sOsVersion = _T("");
	m_sIPAddress = _T("");
	//}}AFX_DATA_INIT
}


void DlgSystemControl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgSystemControl)
	DDX_Text(pDX, IDC_EDT_SYS_STATE, m_sSystemState);
	DDX_Text(pDX, IDC_EDT_SYS_CONN_STATE, m_sSysConnState);
	DDX_Text(pDX, IDC_EDIT_VERSION, m_sVersion);
	DDX_Text(pDX, IDC_EDIT_FPGA_VERSION, m_sFPGAVersion);
	DDX_Text(pDX, IDC_EDIT_OSVERSION, m_sOsVersion);
	DDX_Text(pDX, IDC_EDIT_IP_ADDRESS, m_sIPAddress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgSystemControl, CDialog)
	//{{AFX_MSG_MAP(DlgSystemControl)
    ON_WM_TIMER()
    ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_SYS_CONNECTION_ESTABLISHED, OnBtnSysConnectionEstablished)
	ON_BN_CLICKED(IDC_BTN_SYS_CONNECTION_LOST, OnBtnSysConnectionLost)
	ON_BN_CLICKED(IDC_BTN_SYS_DL_SW_COMP, OnBtnSysDlSwComp)
	ON_BN_CLICKED(IDC_BTN_SYS_READ_SW_VERSIONS, OnBtnSysReadSwVersions)
	ON_BN_CLICKED(IDC_BTN_SYS_RESET_DEVICE, OnBtnSysResetDevice)
	ON_BN_CLICKED(IDC_BTN_SYS_SET_IF_CONFIG, OnBtnSysSetIfConfig)
	ON_BN_CLICKED(IDC_BTN_SYS_START_DEVICE, OnBtnSysStartDevice)
	ON_BN_CLICKED(IDC_BTN_SYS_COMPONENT_STATE, OnBtnSysComponentState)
	ON_BN_CLICKED(IDC_BTN_SYS_DL_SW_TRACESYNC, OnBtnSysDlSwTraceSync)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgSystemControl message handlers
BOOL DlgSystemControl::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_sVersion = GetSoftwareVersion();
    CCOSyncObjectCString* l_pSyncObj = IHIInterface::GetInstance()->ReadFpgaSwVersion();
    l_pSyncObj->Synchronize();

    m_sFPGAVersion = l_pSyncObj->GetValue();
	l_pSyncObj->ReleaseRef();
	
	l_pSyncObj = IHIInterface::GetInstance()->GetOsVersion();
    l_pSyncObj->Synchronize();
	m_sOsVersion = l_pSyncObj->GetValue();
    l_pSyncObj->ReleaseRef();

	m_sIPAddress = GetIPAddress();

    SetTimer(m_uiTimerID, 500, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgSystemControl::OnDestroy()
{
    KillTimer(m_uiTimerID);
    CDialog::OnDestroy();
}


CString DlgSystemControl::GetSoftwareVersion ()
{
   VS_FIXEDFILEINFO sVSFixed;
   BYTE*            pVersionInfo;
   CString          sVersion;
   DWORD            dwLen         = 0;
   DWORD            dwDummyHandle = 1;      // dummy handle needed by ::GetFileVersionInfoSize
   bool             bRetval        = FALSE; // return value
   LPTSTR           szFilename = _T("NIRFlex.exe");

   dwLen = ::GetFileVersionInfoSize (szFilename, &dwDummyHandle);
   if (dwLen > 0)
   {
      ::ZeroMemory (&sVSFixed, sizeof (VS_FIXEDFILEINFO));
      pVersionInfo = new BYTE [dwLen]; // allocate version info
      if (::GetFileVersionInfo (szFilename, 0, dwLen, pVersionInfo) == TRUE)
      {
         UINT iLen = 0;
         LPVOID pVoid = NULL;
         if (::VerQueryValue (pVersionInfo, _T ("\\"), &pVoid, &iLen))
         {
            // copy VS_FIXED structure
            sVSFixed = *((VS_FIXEDFILEINFO*)pVoid);
            sVersion.Format(_T("%02d.%02d.%02d.%02d"), 
                            (sVSFixed.dwProductVersionMS >> 16),
                            (sVSFixed.dwProductVersionMS & 0x0000FFFF),
                            (sVSFixed.dwProductVersionLS >> 16),
                            (sVSFixed.dwProductVersionLS & 0x0000FFFF));
         }
      }

      delete [] pVersionInfo;
   }

   return sVersion;
}

CString DlgSystemControl::GetIPAddress()
{
    BYTE* l_pBuffer = NULL;
    ULONG l_ulBufferSize = 0;
    PIP_ADAPTER_ADDRESSES l_pAddresses = NULL;
	CString l_sIPAddress;

    ::GetAdaptersAddresses(AF_INET, 0, NULL, l_pAddresses, &l_ulBufferSize);
    l_pBuffer = new BYTE[l_ulBufferSize];
    l_pAddresses = (PIP_ADAPTER_ADDRESSES)l_pBuffer;
    if (GetAdaptersAddresses(AF_INET, 0, NULL, l_pAddresses, &l_ulBufferSize) != ERROR_SUCCESS)
    {
        l_sIPAddress = _T("????");
    }
	else
	{
		PIP_ADAPTER_ADDRESSES l_pAdapter = NULL;
		PIP_ADAPTER_ADDRESSES l_pLocalPtr = l_pAddresses;
		CString l_sFriendlyName = _T("Local Area Connection");
		do
		{
			if (l_sFriendlyName == l_pLocalPtr->FriendlyName)
			{
				l_pAdapter = l_pLocalPtr;
				break;
			}
			l_pLocalPtr = l_pLocalPtr->Next;
		} while (l_pLocalPtr != NULL);

		if (l_pAdapter == NULL)
			l_pAdapter = l_pAddresses;

		if (l_pAdapter != NULL && l_pAdapter->FirstUnicastAddress)
		{
			sockaddr_in* l_pAddress = (sockaddr_in*)l_pAdapter->FirstUnicastAddress->Address.lpSockaddr;
			l_sIPAddress = inet_ntoa(l_pAddress->sin_addr);
		}
	}

    delete [] l_pBuffer;
	return l_sIPAddress;
}


void DlgSystemControl::OnTimer(UINT nIDEvent)
{
    if (nIDEvent == m_uiTimerID)
    {
	    try
	    {
		    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();            
		    m_sSystemState = pIntf->GetsCurrentState();
		    EPIDeviceState eDeviceState = pIntf->GetDeviceState();
		    switch (eDeviceState)
		    {
			    case eNotConnected:     m_sSysConnState = _T("Not Connected"); break; 
			    case eReadyForDownload: m_sSysConnState = _T("Ready for download"); break;
			    case eRunning:          m_sSysConnState = _T("Running"); break;
			    default:                m_sSysConnState = _T("Undefined");
		    }
		    UpdateData(FALSE);
	    }
	    catch(XCOException* p_Exception)
	    {
		    MessageBox(_T("OnBtnSysUpdateState: Exception caught"));
		    p_Exception->Delete();
	    }
    }
    else
	  {
          CDialog::OnTimer(nIDEvent);
	  }
}


void DlgSystemControl::OnBtnSysConnectionEstablished() 
{
	try
	{
		IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
		CCOSyncObjectPtr pSyncObj;

		pSyncObj = pIntf->ConnectionEstablished();
		pSyncObj->Synchronize();
	}
	catch(XCOException* p_Exception)
	{
		MessageBox(_T("OnBtnSysConnectionLost: Exception caught"));
		p_Exception->Delete();
	}
}

void DlgSystemControl::OnBtnSysConnectionLost() 
{
	try
	{
		IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
		CCOSyncObjectPtr pSyncObj;

		pSyncObj = pIntf->ConnectionLost();
		pSyncObj->Synchronize();
	}
	catch(XCOException* p_Exception)
	{
		MessageBox(_T("OnBtnSysConnectionLost: Exception caught"));
		p_Exception->Delete();
	}
}

void DlgSystemControl::OnBtnSysDlSwComp() 
{
	try
	{
    bool bIsFPGASource = true;
    bool bIsWinCEImage = false;
		CFile cFile;
		cFile.Open(_T("\\Hard Disk\\GIISW\\Test.xsvf"), CFile::modeRead);
		ULONG ulFileLength = cFile.GetLength();
		BYTE* bImage = new BYTE[ulFileLength];
		cFile.Read(bImage, ulFileLength);
		cFile.Close();

		CTypedPtrList<CPtrList, CPIPersistentSoftwareComponent*> pComponents;
		CPIPersistentSoftwareComponent* pSWComp = new CPIPersistentSoftwareComponent(_T("Test.xsvf"), false, bIsFPGASource, bIsWinCEImage, bImage, ulFileLength);
		pComponents.AddTail(pSWComp);
		CPIPersistentSoftwareComponentList* pComponentList = new CPIPersistentSoftwareComponentList(pComponents);

		IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
		CCOSyncObject*  pSyncObj;
		pSyncObj = pIntf->DownloadSoftwareComponents(pComponentList);
		pSyncObj->Synchronize();
		pComponentList->ReleaseRef();
		pSyncObj->ReleaseRef();
	}
	catch(XCOException* p_Exception)
	{
		MessageBox(_T("OnBtnSysDlSwComp: Exception caught"));
		p_Exception->Delete();
	}
}

void DlgSystemControl::OnBtnSysReadIdentifications() 
{
	try
	{
		IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
/*		CPISyncObjListIdent*  pSyncObj;

		pSyncObj = pIntf->ReadIdentifications();
		pSyncObj->Synchronize();
		pSyncObj->ReleaseRef();*/ // todo remove
	}
	catch(XCOException* p_Exception)
	{
		MessageBox(_T("OnBtnSysReadIdentifications: Exception caught"));
		p_Exception->Delete();
	}
}

void DlgSystemControl::OnBtnSysReadSwVersions() 
{
	try
	{
		IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
		CPISyncObjListSWCompVersion*  pSyncObj;

		pSyncObj = pIntf->ReadSoftwareVersions();
		pSyncObj->Synchronize();
		pSyncObj->ReleaseRef();
	}
	catch(XCOException* p_Exception)
	{
		MessageBox(_T("OnBtnSysReadSwVersions: Exception caught"));
		p_Exception->Delete();
	}
}

void DlgSystemControl::OnBtnSysResetDevice() 
{
	try
	{
		IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
		CCOSyncObjectPtr pSyncObj;

		pSyncObj = pIntf->ResetDevice();
		pSyncObj->Synchronize();
	}
	catch(XCOException* p_Exception)
	{
		MessageBox(_T("OnBtnSysResetDevice: Exception caught"));
		p_Exception->Delete();
	}
}

void DlgSystemControl::OnBtnSysSetIfConfig() 
{
	try
	{
		ULONG ulInetAddr     = inet_addr("10.10.41.196");
		ULONG ulInetMask     = inet_addr("255.255.0.0");
		ULONG ulInetGateWay  = inet_addr("10.10.10.20");

		CPIInterfaceConfig* pInterfaceConfig = new CPIInterfaceConfig(eEthernet, ulInetAddr, ulInetMask, ulInetGateWay, false);
		IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
		CCOSyncObject*  pSyncObj;

		pSyncObj = pIntf->SetInterfaceConfig(pInterfaceConfig);
		pSyncObj->Synchronize();
		pSyncObj->ReleaseRef();
		pInterfaceConfig->ReleaseRef();
	}
	catch(XCOException* p_Exception)
	{
		MessageBox(_T("OnBtnSysSetIfConfig: Exception caught"));
		p_Exception->Delete();
	}
}


void DlgSystemControl::OnBtnSysStartDevice() 
{
 	try
	{
        IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
		CCOSyncObjectPtr pSyncObj;

		pSyncObj = pIntf->StartDevice();
		pSyncObj->Synchronize();
	}
	catch(XCOException* p_Exception)
	{
		MessageBox(_T("OnBtnSysStartDevice: Exception caught"));
		p_Exception->Delete();
	}
}

void DlgSystemControl::OnBtnSysWriteIdentifications() 
{
	try
	{
		IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
/*		CCOSyncObject*  pSyncObj;
		CPIPersistentObjIdentification* pIdentification = new CPIPersistentObjIdentification(1, _T("TEST"));

		pSyncObj = pIntf->WriteIdentification(pIdentification);
		pSyncObj->Synchronize();
		pSyncObj->ReleaseRef();*/ // todo remove
	}
	catch(XCOException* p_Exception)
	{
		MessageBox(_T("OnBtnSysWriteIdentifications: Exception caught"));
		p_Exception->Delete();
	}
}



void DlgSystemControl::OnOK() 
{
	// TODO: Add extra cleanup here
	CDialog::OnOK();
}

void DlgSystemControl::OnBtnSysComponentState() 
{
	// TODO: Add your control notification handler code here
	DlgSystemCompState	dlg;
	dlg.DoModal();
}

void DlgSystemControl::OnBtnSysDlSwTraceSync() 
{
#ifdef DEBUG
	int l_iObjNum = ICORefCounting::TraceLivingObjects();
	int l_iAllocNum = ::GetNumberOfAllocatedBlocks();
	CString l_sMsg;
	l_sMsg.Format(_T("Number of living ref count objects = %d\nNumber of allocated memory blocks = %d"), l_iObjNum, l_iAllocNum);
	MessageBox((LPCTSTR)l_sMsg);
#endif	
}
