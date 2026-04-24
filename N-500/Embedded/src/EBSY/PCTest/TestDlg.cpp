// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "TestDlg.h"

#include "EBPIfact.h"
#include "EBPItype.h"
#include "EBPIcpst.h"

#include "EBSYintf.h"
#include "EBSYmain.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTestDlg dialog



CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
    , m_sState(_T("")), m_sCommState(_T("")), m_uiTimerID(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_STATE, m_sState);
    DDX_Text(pDX, IDC_COMM_STATE, m_sCommState);
    DDX_Control(pDX, IDC_LIST_OBJLIST, m_ListBoxObjects);
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_BUTTON_START_DEVICE, OnBnClickedButtonStartDevice)
    ON_BN_CLICKED(IDC_BUTTON_CONNECTION_ESTABLISHED, OnBnClickedButtonConnectionEstablished)
    ON_BN_CLICKED(IDC_BUTTON_CONNECTION_LOST, OnBnClickedButtonConnectionLost)
    ON_WM_TIMER()
    ON_BN_CLICKED(IDC_BUTTON_RESET_DEVICE, OnBnClickedButtonResetDevice)
    ON_BN_CLICKED(IDC_BUTTON_READ_IDENTFICATIONS, OnBnClickedButtonReadIdentfications)
    ON_BN_CLICKED(IDC_BUTTON_READ_SOFTWARE_VERSIONS, OnBnClickedButtonReadSoftwareVersions)
    ON_BN_CLICKED(IDC_BUTTON_SETINTERFACE_CONFIG, OnBnClickedButtonSetinterfaceConfig)
    ON_BN_CLICKED(IDC_BUTTON_DOWNLOAD_SOFTWARE_COMPONENTS, OnBnClickedButtonDownloadSoftwareComponents)
    ON_BN_CLICKED(IDC_BUTTON_WRITE_IDENTFICATION, OnBnClickedButtonWriteIdentfication)
    ON_BN_CLICKED(IDC_BUTTON_SPECIAL_TEST1, OnBnClickedButtonSpecialTest1)
    ON_BN_CLICKED(IDC_BUTTON_SPECIAL_TEST2, OnBnClickedButtonSpecialTest2)
    ON_WM_DESTROY()
    ON_STN_CLICKED(IDC_STATE, OnStnClickedState)
    ON_BN_CLICKED(IDC_BUTTON_SHOW_OBJLIST, OnBnClickedButtonShowObjlist)
	ON_BN_CLICKED(IDC_BUTTON_TRACE_REFOBJS, OnBnClickedButtonTraceRefobjs)
END_MESSAGE_MAP()


// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

    SetTimer(m_uiTimerID, 500, NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTestDlg::OnTimer(UINT nIDEvent)
{
    if (nIDEvent == m_uiTimerID)
    {
        IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();            
        m_sState = pIntf->GetsCurrentState();
        EPIDeviceState eDeviceState = pIntf->GetDeviceState();
        switch (eDeviceState)
        {
            case eNotConnected:     m_sCommState = _T("Not Connected"); break; 
            case eReadyForDownload: m_sCommState = _T("Ready for download"); break;
            case eRunning:          m_sCommState = _T("Running"); break;
            default:                m_sCommState = _T("Undefined");
        }
        UpdateData(FALSE);
    }
    else
        CDialog::OnTimer(nIDEvent);
}

void CTestDlg::OnBnClickedButtonConnectionEstablished()
{
    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr pSyncObj;

    pSyncObj = pIntf->ConnectionEstablished();
    pSyncObj->Synchronize();
}

void CTestDlg::OnBnClickedButtonStartDevice()
{
    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr pSyncObj;

    pSyncObj = pIntf->StartDevice();
    pSyncObj->Synchronize();
}

void CTestDlg::OnBnClickedButtonConnectionLost()
{
    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr pSyncObj;

    pSyncObj = pIntf->ConnectionLost();
    pSyncObj->Synchronize();
}

void CTestDlg::OnBnClickedButtonResetDevice()
{
    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObjectPtr pSyncObj;

    pSyncObj = pIntf->ResetDevice();
    pSyncObj->Synchronize();
}


void CTestDlg::OnBnClickedButtonReadIdentfications()
{
/*    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CPISyncObjListPersistentItems*  pSyncObj;

    pSyncObj = pIntf->ReadIdentifications();
    pSyncObj->Synchronize();
    pSyncObj->ReleaseRef();*/
}

void CTestDlg::OnBnClickedButtonReadSoftwareVersions()
{
    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CPISyncObjListSWCompVersion*  pSyncObj;

    pSyncObj = pIntf->ReadSoftwareVersions();
    pSyncObj->Synchronize();
    pSyncObj->ReleaseRef();
}

void CTestDlg::OnBnClickedButtonSetinterfaceConfig()
{
    ULONG ulInetAddr     = inet_addr("192.168.1.22");
    ULONG ulInetMask     = inet_addr("255.255.255.0");
    ULONG ulInetGateWay  = inet_addr("192.168.1.1");

    CPIInterfaceConfig* pInterfaceConfig = new CPIInterfaceConfig(eEthernet, ulInetAddr, ulInetMask, ulInetGateWay, false);
    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObject*  pSyncObj;

    pSyncObj = pIntf->SetInterfaceConfig(pInterfaceConfig);
    pSyncObj->Synchronize();
    pSyncObj->ReleaseRef();
    pInterfaceConfig->ReleaseRef();
}

void CTestDlg::OnBnClickedButtonDownloadSoftwareComponents()
{
    CTypedPtrList<CPtrList, CPIPersistentSoftwareComponent*> pComponents;
    CPIPersistentSoftwareComponentList* pComponentList = new CPIPersistentSoftwareComponentList(pComponents);
    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObject*  pSyncObj;

    CFile cFile("R:\\BIN\\EBMC.ddll");
    ULONG ulFileSize = (ULONG)cFile.GetLength();
    BYTE* bImage = new BYTE[ulFileSize];
    cFile.Read(bImage, (ULONG)ulFileSize);

    CPIPersistentSoftwareComponent* pSWComp = new CPIPersistentSoftwareComponent(_T("EBPC"), false, false, false, bImage, ulFileSize);
    pComponents.AddTail(pSWComp);

    pSyncObj = pIntf->DownloadSoftwareComponents(pComponentList);
    pSyncObj->Synchronize();
    pComponentList->ReleaseRef();
    pSyncObj->ReleaseRef();
    
    delete [] bImage;

}

void CTestDlg::OnBnClickedButtonWriteIdentfication()
{
/*    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObject*  pSyncObj;
    CPIPersistentObjIdentification* pIdentification = new CPIPersistentObjIdentification(1, _T("TEST"));

    pSyncObj = pIntf->WriteIdentification(pIdentification);
    pSyncObj->Synchronize();
    pSyncObj->ReleaseRef();*/
	ASSERT(false);
}

void CTestDlg::OnBnClickedButtonSpecialTest1()
{
    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObject*  pSyncObj;

    pSyncObj = pIntf->SetComponentState(_T("SY"), false);
    pSyncObj->Synchronize();
    pSyncObj->ReleaseRef();
    pSyncObj = pIntf->SetComponentState(_T("MC"), false);
    pSyncObj->Synchronize();
    pSyncObj->ReleaseRef();
#if 0
    CPIStepperMotorConfig  *pConfig  = new CPIStepperMotorConfig(1,2,3,4);
    CPIStepperMotorProfile *pProfile = new CPIStepperMotorProfile(1,2,3,4);

    IPIStepperMotorInterface* pIntf = CPIObjectFactory::GetInstance()->CreateStepperMotor(1, _T(""));
    pIntf->Startup();;
    pIntf->SetConfig(pConfig);
    pIntf->SetProfile(pProfile);

    pConfig->ReleaseRef();
    pProfile->ReleaseRef();
    CPIInterfaceConfig* pInterfaceConfig = new CPIInterfaceConfig(eEthernet,1,2,3);
    CSYInterfaceSettings::SetIPAddress(pInterfaceConfig);
    pInterfaceConfig->ReleaseRef();
#endif
}

void CTestDlg::OnBnClickedButtonSpecialTest2()
{
    CString sComp = _T("SY");
    bool test = CPIComponentsState::GetInstance()->GetComponentState(sComp);
    TRACE2("State of %s is %d\n", sComp, test);
    sComp = _T("PC");
    test = CPIComponentsState::GetInstance()->GetComponentState(sComp);
    TRACE2("State of %s is %d\n", sComp, test);
    sComp = _T("MC");
    test = CPIComponentsState::GetInstance()->GetComponentState(sComp);
    TRACE2("State of %s is %d\n", sComp, test);
    sComp = _T("ET");
    test = CPIComponentsState::GetInstance()->GetComponentState(sComp);
    TRACE2("State of %s is %d\n", sComp, test);
/*
    CPIPersistentObjIdentification* pIdentification = new CPIPersistentObjIdentification(1, _T("TEST"));
    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObject*  pSyncObj;

    pSyncObj = pIntf->WriteIdentification(pIdentification);
    pSyncObj->Synchronize();
    pSyncObj->ReleaseRef();
    pIdentification->ReleaseRef();
/*
    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CCOSyncObject*  pSyncObj;

    pSyncObj = ((CSYSystemInterface*)(pIntf))->SetConfig(100000);
    pSyncObj->Synchronize();
    pSyncObj->ReleaseRef();
*/
}

void CTestDlg::OnDestroy()
{
    KillTimer(m_uiTimerID);

    CDialog::OnDestroy();
	CSYSystem::Delete();

	ICORefCounting::TraceLivingObjects();
}

void CTestDlg::OnStnClickedState()
{
    // TODO: Add your control notification handler code here
}

void CTestDlg::OnBnClickedButtonShowObjlist()
{
    m_ListBoxObjects.ResetContent();

    IPISystemInterface* pIntf = CPIObjectFactory::GetInstance()->QuerySystemInterface();
    CPISyncObjectStringArray* l_SyncObj = pIntf->GetObjectList();
    l_SyncObj->Synchronize();

    CStringArray* l_sObjList = l_SyncObj->GetValue();
    l_SyncObj->ReleaseRef();

    for (int l_iCnt=0; l_iCnt<l_sObjList->GetCount(); l_iCnt++)
    {
        m_ListBoxObjects.AddString(l_sObjList->GetAt(l_iCnt));
    }
    delete l_sObjList;
}

void CTestDlg::OnBnClickedButtonTraceRefobjs()
{
	ICORefCounting::TraceLivingObjects();
}
