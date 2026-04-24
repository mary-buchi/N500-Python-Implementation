// EBNFDlgI2CADC.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"

#include "EBPIintf.h"
#include "EBPIfact.h"

#include "EBPItype.h"
#include "EBCOexcp.h"

#include "EBNFDlgI2CADC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgI2CADC dialog


CDlgI2CADC::CDlgI2CADC(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgI2CADC::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgI2CADC)
	m_nAIN0 = 0;
	m_nAIN1 = 0;
	m_nAIN2 = 0;
	m_nAIN3 = 0;
	m_dwDeviceID = 5105;
	//}}AFX_DATA_INIT
}


void CDlgI2CADC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgI2CADC)
	DDX_Text(pDX, IDC_EDT_ADC_AIN0, m_nAIN0);
	DDX_Text(pDX, IDC_EDT_ADC_AIN1, m_nAIN1);
	DDX_Text(pDX, IDC_EDT_ADC_AIN2, m_nAIN2);
	DDX_Text(pDX, IDC_EDT_ADC_AIN3, m_nAIN3);
	DDX_Text(pDX, IDC_EDT_DEVICE_ID, m_dwDeviceID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgI2CADC, CDialog)
	//{{AFX_MSG_MAP(CDlgI2CADC)
	ON_BN_CLICKED(IDC_BTN_ADC_INI, OnBtnAdcIni)
	ON_BN_CLICKED(IDC_BTN_ADC_GET_DATA, OnBtnAdcGetData)
	ON_BN_CLICKED(IDC_BTN_STARTUP, OnBtnStartup)
	ON_BN_CLICKED(IDC_BTN_SHUTDOWN, OnBtnShutdown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgI2CADC message handlers

BOOL CDlgI2CADC::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_pADC = NULL;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgI2CADC::OnBtnAdcIni() 
{
  if (m_pADC == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  UpdateData(TRUE);
  try
  {
    CCOSyncObject* l_SynObj = m_pADC->Initialize();
    l_SynObj->Synchronize();
    l_SynObj->ReleaseRef();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }
  
}

void CDlgI2CADC::OnBtnAdcGetData() 
{
  if (m_pADC == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  UpdateData(TRUE);

  try
  {
    CPISyncObjDataADCMAX1037* l_pSyncObj = m_pADC->GetData();
    l_pSyncObj->Synchronize();
    CPIDataADCMAX1037* l_pData = (CPIDataADCMAX1037*)l_pSyncObj->GetValue();
    m_nAIN0 = l_pData->GetDataAIN0();
    m_nAIN1 = l_pData->GetDataAIN1();
    m_nAIN2 = l_pData->GetDataAIN2();
    m_nAIN3 = l_pData->GetDataAIN3();
    l_pSyncObj->ReleaseRef();
    l_pData->ReleaseRef();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);
	
}

void CDlgI2CADC::OnBtnStartup() 
{
  UpdateData(TRUE);
  if (m_dwDeviceID == 0)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
 
  m_pADC = CPIObjectFactory::GetInstance()->CreateADCMAX1037(m_dwDeviceID, _T(""));
}

void CDlgI2CADC::OnBtnShutdown() 
{
  UpdateData(TRUE);
  if (m_pADC == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  if (m_pADC)
  {
	  CCOSyncObjectPtr l_pSyncObj = m_pADC->Shutdown();
	  l_pSyncObj->Synchronize();	
	  m_pADC = NULL;
  }
}
