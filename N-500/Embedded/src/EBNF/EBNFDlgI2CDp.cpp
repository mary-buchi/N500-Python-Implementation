// EBNFDlgI2CDp.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "EBCOexcp.h"

#include "EBPImain.h"
#include "EBPIenum.h"
#include "EBPIfact.h"
#include "EBPIintf.h"
#include "EBPItype.h"
#include "EBHIintf.h"
#include "EBHITrsm.h"


#include "EBNFdlgi2cdp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgI2CDp dialog


CDlgI2CDp::CDlgI2CDp(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgI2CDp::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgI2CDp)
	m_nDPRead = 0;
	m_nDPWrite = 0;
	m_dwDeviceID = 5104;
	//}}AFX_DATA_INIT
}


void CDlgI2CDp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgI2CDp)
	DDX_Text(pDX, IDC_EDT_DP_READ, m_nDPRead);
	DDX_Text(pDX, IDC_EDT_DP_WRITE, m_nDPWrite);
	DDX_Text(pDX, IDC_EDT_DEVICE_ID, m_dwDeviceID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgI2CDp, CDialog)
	//{{AFX_MSG_MAP(CDlgI2CDp)
	ON_BN_CLICKED(IDC_BTN_DP_READ, OnBtnDpRead)
	ON_BN_CLICKED(IDC_BTN_DP_WRITE, OnBtnDpWrite)
	ON_BN_CLICKED(IDC_BTN_STARTUP, OnBtnStartup)
	ON_BN_CLICKED(IDC_BTN_SHUTDOWN, OnBtnShutdown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgI2CDp message handlers

void CDlgI2CDp::OnBtnDpRead() 
{
  if (m_pDP == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  UpdateData(TRUE);
  try
  {
    CCOSyncObjectInt* l_SynObj = m_pDP->ReadValue();
    l_SynObj->Synchronize();
    m_nDPRead = (int)l_SynObj->GetValue();
    l_SynObj->ReleaseRef();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);
	
}

void CDlgI2CDp::OnBtnDpWrite() 
{
  if (m_pDP == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  UpdateData(TRUE);
  
  try
  {
    CCOSyncObject* l_SynObj = m_pDP->WriteValue(m_nDPWrite);
    l_SynObj->Synchronize();
    l_SynObj->ReleaseRef();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }
  
}

BOOL CDlgI2CDp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_pDP = NULL;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgI2CDp::OnBtnStartup() 
{
  UpdateData(TRUE);
  if (m_dwDeviceID == 0)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  
  m_pDP = CPIObjectFactory::GetInstance()->CreateDigitalPotiAD5245(m_dwDeviceID, _T(""));
}

void CDlgI2CDp::OnBtnShutdown() 
{
  UpdateData(TRUE);
  if (m_pDP == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  if (m_pDP)
  {
	CCOSyncObjectPtr l_pSyncObj = m_pDP->Shutdown();
	l_pSyncObj->Synchronize();	
	m_pDP = NULL;
  }
}
