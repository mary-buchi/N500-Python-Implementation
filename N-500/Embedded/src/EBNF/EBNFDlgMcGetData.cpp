// DlgMcGetData.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "EBNFDlgMcGetData.h"

#include "EBPImain.h"
#include "EBPIenum.h"
#include "EBPIfact.h"
#include "EBPIintf.h"
#include "EBHIintf.h"
#include "EBHITrsm.h"

#include "EBCOsync.h"
#include "EBCOexcp.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMcGetData dialog




CDlgMcGetData::CDlgMcGetData(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMcGetData::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMcGetData)
	m_SetData = 0;
	m_strActState = _T("");
	m_dwNumberOfPackage = 0;
	//}}AFX_DATA_INIT
}


void CDlgMcGetData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMcGetData)
	DDX_Text(pDX, IDC_EDT_MCSETDATA, m_SetData);
	DDX_Text(pDX, IDC_EDT_MCACTSTATE, m_strActState);
	DDX_Text(pDX, IDC_EDT_MCNUMBER_OF_PACKAGE, m_dwNumberOfPackage);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMcGetData, CDialog)
	//{{AFX_MSG_MAP(CDlgMcGetData)
	ON_BN_CLICKED(IDC_BTN_MCGETDATA, OnBtnMcgetdata)
	ON_BN_CLICKED(IDC_BTN_MCSETDATA, OnBtnMcsetdata)
	ON_BN_CLICKED(IDC_BTN_MCSTARTUP, OnBtnMcstartup)
	ON_BN_CLICKED(IDC_BTN_MCSETPROFILE, OnBtnMcsetprofile)
	ON_BN_CLICKED(IDC_BTN_MCINITIALIZE, OnBtnMcinitialize)
	ON_BN_CLICKED(IDC_BTN_MCSTART, OnBtnMcstart)
	ON_BN_CLICKED(IDC_BTN_MCSTOP, OnBtnMcstop)
	ON_BN_CLICKED(IDC_BTN_MCGETDATAPACKAGE, OnBtnMcgetdatapackage)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_MCGETDATASTART, OnBtnMcgetdatastart)
	ON_BN_CLICKED(IDC_BTN_MC_TEST, OnBtnMcTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMcGetData message handlers
BOOL CDlgMcGetData::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_pHWIntf = IHIInterface::GetInstance();

  m_pMCIntf = CPIObjectFactory::GetInstance()->CreateMeasurementChannel(1,_T(""));
  m_strActState = _T("no state active");
  UpdateData(FALSE);
  //SetTimer(1, 1000, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMcGetData::OnBtnMcgetdata() 
{

 
  CPISyncObjDataPackage *pSyncObj = NULL;
  pSyncObj = m_pHWIntf->MCGetDataPackage();
  pSyncObj->Synchronize();
  pSyncObj->ReleaseRef();
  m_strActState = m_pMCIntf->GetsCurrentState();
  UpdateData(FALSE);
}

void CDlgMcGetData::OnBtnMcsetdata() 
{
  UpdateData();
  
  DWORD dwCount = m_SetData; // Full buffer -> m_SetData = 262142

  m_pHWIntf->TESTSetData(dwCount);
  
  m_strActState = m_pMCIntf->GetsCurrentState();
  UpdateData(FALSE);
}

void CDlgMcGetData::OnBtnMcstartup() 
{
	CCOSyncObjectPtr l_SyncObjMC = m_pMCIntf->Startup();
	ASSERT(l_SyncObjMC != NULL);
	l_SyncObjMC->Synchronize();
  m_strActState = m_pMCIntf->GetsCurrentState();
  UpdateData(FALSE);
}

void CDlgMcGetData::OnBtnMcsetprofile() 
{
  m_pMCProfile = new CPIMeasurementChannelProfile(1024,1024000);
  CCOSyncObjectPtr l_SyncObjMC = m_pMCIntf->SetProfile(m_pMCProfile);
	ASSERT(l_SyncObjMC != NULL);
	l_SyncObjMC->Synchronize();
  m_strActState = m_pMCIntf->GetsCurrentState();
  UpdateData(FALSE);
}

void CDlgMcGetData::OnBtnMcinitialize() 
{
	CCOSyncObjectPtr l_SyncObjMC = m_pMCIntf->Initialize();
	ASSERT(l_SyncObjMC != NULL);
	l_SyncObjMC->Synchronize();
  m_strActState = m_pMCIntf->GetsCurrentState();
  UpdateData(FALSE);
}

void CDlgMcGetData::OnBtnMcstart() 
{
	CCOSyncObjectPtr l_SyncObjMC = m_pMCIntf->Start(1);
	ASSERT(l_SyncObjMC != NULL);
	l_SyncObjMC->Synchronize();
  m_strActState = m_pMCIntf->GetsCurrentState();
  UpdateData(FALSE);
}

void CDlgMcGetData::OnBtnMcstop() 
{
	CCOSyncObjectPtr l_SyncObjMC = m_pMCIntf->Stop();
	ASSERT(l_SyncObjMC != NULL);
	l_SyncObjMC->Synchronize();
  m_strActState = m_pMCIntf->GetsCurrentState();
  UpdateData(FALSE);
}

void CDlgMcGetData::OnBtnMcgetdatapackage() 
{

  CPISyncObjDataPackage * l_SyncObjMC = m_pMCIntf->GetDataPackage();
	ASSERT(l_SyncObjMC != NULL);
	l_SyncObjMC->Synchronize();

  CPIMeasurementChannelDataPackage* l_pDataPackage = l_SyncObjMC->GetValue();
    
  m_strActState = m_pMCIntf->GetsCurrentState();
  l_pDataPackage->ReleaseRef();
  UpdateData(FALSE);
}


void CDlgMcGetData::OnTimer(UINT nIDEvent) 
{

  m_strActState = m_pMCIntf->GetsCurrentState();
  UpdateData(FALSE);
	CDialog::OnTimer(nIDEvent);
}

void CDlgMcGetData::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if (m_pMCProfile)
		m_pMCProfile->ReleaseRef();
	m_pMCProfile = NULL;
  //KillTimer(1);
  CDialog::OnClose();
}

void CDlgMcGetData::OnBtnMcgetdatastart() 
{
	
  int l_nCount = m_dwNumberOfPackage;
  CCOSyncObjectPtr l_SyncObjMC = NULL;

  do
  {
    l_SyncObjMC = m_pMCIntf->GetDataPackage();
	  ASSERT(l_SyncObjMC != NULL);
	  l_SyncObjMC->Synchronize();
    l_nCount--;
  }
  while (l_nCount > 0);
  m_strActState = m_pMCIntf->GetsCurrentState();
  UpdateData(FALSE);
}

void CDlgMcGetData::OnBtnMcTest() 
{

  m_pHWIntf->TEST(0);

}
