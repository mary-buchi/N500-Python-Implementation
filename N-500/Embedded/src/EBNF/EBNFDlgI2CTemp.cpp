// DlgI2CTemp.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"

#include "EBPItype.h"
#include "EBCOexcp.h"

#include "EBHIintf.h"
#include "EBPIfact.h"
#include "EBPIintf.h"

#include "EBNFDlgI2CTemp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgI2CTemp dialog


CDlgI2CTemp::CDlgI2CTemp(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgI2CTemp::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgI2CTemp)
	m_nGetConfig = 0;
	m_nGetTemp = 0;
	m_dwDeviceId = 5004;
	//}}AFX_DATA_INIT
  m_pTemp = NULL;
}


void CDlgI2CTemp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgI2CTemp)
	DDX_Text(pDX, IDC_EDT_GET_CONFIG, m_nGetConfig);
	DDX_Text(pDX, IDC_EDT_GET_TEMP, m_nGetTemp);
	DDX_Text(pDX, IDC_EDT_DEVICE_ID, m_dwDeviceId);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgI2CTemp, CDialog)
	//{{AFX_MSG_MAP(CDlgI2CTemp)
	ON_BN_CLICKED(IDC_BTN_GET_CONFIG, OnBtnGetConfig)
	ON_BN_CLICKED(IDC_BTN_GET_TEMP, OnBtnGetTemp)
	ON_BN_CLICKED(IDC_BTN_SET_CONFIG, OnBtnSetConfig)
	ON_BN_CLICKED(IDC_BTN_STARTUP, OnBtnStartup)
	ON_BN_CLICKED(IDC_BTN_SHUTDOWN, OnBtnShutdown)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgI2CTemp message handlers

void CDlgI2CTemp::OnBtnGetConfig() 
{
  UpdateData(TRUE);
  if (m_pTemp == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }

  try
  {
    CCOSyncObjectInt* l_SynObj = m_pTemp->GetSensorConfig();
    l_SynObj->Synchronize();
    m_nGetConfig = l_SynObj->GetValue();
    l_SynObj->ReleaseRef();

  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);
	
}

void CDlgI2CTemp::OnBtnGetTemp() 
{
  UpdateData(TRUE);
  if (m_pTemp == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }

  try
  {
    CCOSyncObjectInt* l_pSyncObj = m_pTemp->GetTemperature();
    l_pSyncObj->Synchronize();
    m_nGetTemp = l_pSyncObj->GetValue();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

  UpdateData(FALSE);
	
}

void CDlgI2CTemp::OnBtnSetConfig() 
{
  if (m_pTemp == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  UpdateData(TRUE);
  EPIResolutionDS1631Z l_eRes; 
  EPIModeDS1631Z l_eMode;
  UpdateData(TRUE);
 
  if (m_pTemp == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }

   if (((CButton*)GetDlgItem(IDC_RDO_NORMAL))->GetCheck())
     l_eRes = eNormal;
   else if (((CButton*)GetDlgItem(IDC_RDO_LOW))->GetCheck())
     l_eRes = eResLow;
   else if (((CButton*)GetDlgItem(IDC_RDO_ABOVE_LOW))->GetCheck())
     l_eRes = eAboveLow;
   else if (((CButton*)GetDlgItem(IDC_RDO_HIGH))->GetCheck())
     l_eRes = eHigh;
   else
   {
     MessageBox(_T("No Resolution selected"));
     return;
   }

   if (((CButton*)GetDlgItem(IDC_RDO_CONTINOUS))->GetCheck())
     l_eMode = eModeContinuous;
   else if (((CButton*)GetDlgItem(IDC_RDO_SINGLE))->GetCheck())
     l_eMode = eModeOneShot;
   else
   {
     MessageBox(_T("No Mode selected"));
     return;
   }
  
  try
  {
     CPIConfigDS1631Z* l_pConfig = new CPIConfigDS1631Z(l_eMode, l_eRes);

     CCOSyncObjectPtr l_SynObj = m_pTemp->SetSensorConfig(l_pConfig);
     l_SynObj->Synchronize();


     l_pConfig->ReleaseRef();
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
    int qq;
    qq=0;
  }
	
}

void CDlgI2CTemp::OnBtnStartup() 
{
  UpdateData(TRUE);
  if (m_dwDeviceId == 0)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
 
  try
  {
	m_pTemp = CPIObjectFactory::GetInstance()->CreateSensorDS1631Z(m_dwDeviceId, _T(""));
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }
}

void CDlgI2CTemp::OnBtnShutdown() 
{
  UpdateData(TRUE);
  if (m_pTemp == NULL)
  {
    MessageBox(_T("No Device selected"));
    return;
  }
  
  try
  {
	CCOSyncObjectPtr l_pSyncObj = m_pTemp->Shutdown();
	l_pSyncObj->Synchronize();	
	m_pTemp = NULL;
  }
  catch(XCOException* l_pException)
  {
    l_pException->Delete();
  }

}

BOOL CDlgI2CTemp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_pTemp = NULL;

 ((CButton*)GetDlgItem(IDC_RDO_CONTINOUS))->SetCheck(1);		
 ((CButton*)GetDlgItem(IDC_RDO_NORMAL))->SetCheck(1);		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
