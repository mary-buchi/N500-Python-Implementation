// DlgWCVlcCnt.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"

#include "EBPImain.h"
#include "EBPIenum.h"
#include "EBPIfact.h"
#include "EBPIintf.h"
#include "EBPItype.h"
#include "EBHIintf.h"

#include "EBHIifid.h"

#include "EBNFDlgWCVlcCnt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgWCVlcCnt dialog


CDlgWCVlcCnt::CDlgWCVlcCnt(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgWCVlcCnt::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgWCVlcCnt)
	m_strWCActPos = _T("");
	m_strWCLastVlc = _T("");
	m_strWCActVlc = _T("");
	m_dwWCDAC = 0;
	m_strLBState = _T("");
	m_nActPos = 0;
	//}}AFX_DATA_INIT
}


void CDlgWCVlcCnt::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgWCVlcCnt)
	DDX_Text(pDX, IDC_EDT_WDG_POS, m_strWCActPos);
	DDX_Text(pDX, IDC_EDT_WDG_LAST_VLC, m_strWCLastVlc);
	DDX_Text(pDX, IDC_EDT_WDG_ACT_VLC, m_strWCActVlc);
	DDX_Text(pDX, IDC_EDT_WDG_WDG_VOLT, m_dwWCDAC);
	DDX_Text(pDX, IDC_EDT_LB, m_strLBState);
	DDX_Text(pDX, IDC_EDT_WDG_POS_INT, m_nActPos);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgWCVlcCnt, CDialog)
	//{{AFX_MSG_MAP(CDlgWCVlcCnt)
	ON_BN_CLICKED(IDC_BTN_UPDATE_COUNTER, OnBtnUpdateCounter)
	ON_BN_CLICKED(IDC_BTN_RESET_POSITION, OnBtnResetPosition)
	ON_BN_CLICKED(IDC_RDO_POS_DIR, OnRdoPosDir)
	ON_BN_CLICKED(IDC_RDO_NEG_DIR, OnRdoNegDir)
	ON_BN_CLICKED(IDC_BTN_EMERGENCY_STOP, OnBtnEmergencyStop)
	ON_BN_CLICKED(IDC_BTN_DAC_SET, OnBtnDacSet)
	ON_BN_CLICKED(IDC_BTN_DAC_CONTROLLER_ON_OFF, OnBtnDacControllerOnOff)
	ON_BN_CLICKED(IDC_BTN_DAC_INI, OnBtnDacIni)
	ON_BN_CLICKED(IDC_BTN_LASER_ON, OnBtnLaserOn)
	ON_BN_CLICKED(IDC_BTN_LB, OnBtnLb)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgWCVlcCnt message handlers

BOOL CDlgWCVlcCnt::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  UpdateData();

  m_pHWIntf = IHIInterface::GetInstance();
  m_pWCIntf = CPIObjectFactory::GetInstance()->QueryWedgeControl(1);

  SetTimer(1,50,NULL);

  m_strWCActPos = _T("0x00000000");
  m_strWCActVlc = _T("0x00000000");
  m_strWCLastVlc = _T("0x00000000");
  m_dwWCDAC = 0x0;
  m_nActPos = 0;

  //m_pHWIntf->SetDWord(2098,1);
  Sleep(1);
  //m_pHWIntf->SetDWord(2098,0);
  
  //m_pHWIntf->SetDWord(2099,1);
  ((CButton*)GetDlgItem(IDC_RDO_POS_DIR))->SetCheck(1);		
	
  //m_pHWIntf->SetDWord(2096,0);
  //m_pHWIntf->SetDWord(2097,0);

  ((CButton*)GetDlgItem(IDC_RDO_LSR_ON))->SetCheck(1);		
  ((CButton*)GetDlgItem(IDC_RDO_CONTROLLER_ON))->SetCheck(1);
  
  UpdateData(FALSE);
  return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgWCVlcCnt::OnBtnUpdateCounter() 
{
  int l_nRetVal = 0;
  UpdateData();
  CCOSyncObjectInt* l_pSyncObjInt = NULL;

  l_pSyncObjInt = m_pHWIntf->WCGetPosition();
  l_pSyncObjInt->Synchronize();
  l_nRetVal = l_pSyncObjInt->GetValue();
  m_strWCActPos.Format(_T("%#08x"), l_nRetVal);
  m_nActPos = l_nRetVal;

  l_pSyncObjInt = m_pHWIntf->WCGetActVelocityCounts();
  l_pSyncObjInt->Synchronize();
  l_nRetVal = l_pSyncObjInt->GetValue();
  m_strWCActVlc.Format(_T("%#08x"), l_nRetVal);

  l_pSyncObjInt = m_pHWIntf->WCGetLastVelocityCounts();
  l_pSyncObjInt->Synchronize();
  l_nRetVal = l_pSyncObjInt->GetValue();
  m_strWCLastVlc.Format(_T("%#08x"), l_nRetVal);
  
  UpdateData(FALSE);
}

void CDlgWCVlcCnt::OnBtnResetPosition() 
{
  UpdateData();
  m_pHWIntf->SetDWord(2098,1);
  Sleep(1);
  m_pHWIntf->SetDWord(2098,0);
  UpdateData(FALSE);

}

void CDlgWCVlcCnt::OnRdoPosDir() 
{
  UpdateData();
  m_pHWIntf->SetDWord(2099,1);
  UpdateData(FALSE);
}

void CDlgWCVlcCnt::OnRdoNegDir() 
{
  m_pHWIntf->SetDWord(2099,0);
  UpdateData(FALSE);
}


void CDlgWCVlcCnt::OnBtnEmergencyStop() 
{
  UpdateData();
  m_pHWIntf->WCEmergencyStop();  
  UpdateData(FALSE);
}


void CDlgWCVlcCnt::OnBtnDacSet() 
{
  UpdateData();
  DWORD l_dwVal = 0;
  l_dwVal = m_dwWCDAC;
  m_pHWIntf->WCSetDACValue(l_dwVal);

  UpdateData(FALSE);
}

void CDlgWCVlcCnt::OnBtnDacControllerOnOff() 
{
  UpdateData();
  // Controller On / Off
  if (((CButton*)GetDlgItem(IDC_RDO_CONTROLLER_ON))->GetCheck() == BST_CHECKED)
  { // ON
    m_pHWIntf->WCControllerON(TRUE);
  }
  else if (((CButton*)GetDlgItem(IDC_RDO_CONTROLLER_OFF))->GetCheck() == BST_CHECKED)
  { // OFF
    m_pHWIntf->WCControllerON(FALSE);
  }
  else
  {
    MessageBox(_T("no On / Off state active!"));
  }
  UpdateData(FALSE);
	
}

void CDlgWCVlcCnt::OnBtnDacIni() 
{

  m_pHWIntf->WCInitializeDAC();

}

void CDlgWCVlcCnt::OnBtnLaserOn() 
{
  UpdateData();
  // Laser On / Off
  if (((CButton*)GetDlgItem(IDC_RDO_LSR_ON))->GetCheck() == BST_CHECKED)
  { // ON
    m_pHWIntf->SetDWord(2020, TRUE);
  }
  else if (((CButton*)GetDlgItem(IDC_RDO_LSR_OFF))->GetCheck() == BST_CHECKED)
  { // OFF
    m_pHWIntf->SetDWord(2020, FALSE);
  }
  else
  {
    MessageBox(_T("no On / Off state active!"));
  }
  UpdateData(FALSE);
}

void CDlgWCVlcCnt::OnBtnLb() 
{
  CCOSyncObjectInt* l_pSyncObjInt = NULL;

  l_pSyncObjInt = m_pHWIntf->WCGetLightBarrierState();
  l_pSyncObjInt->Synchronize();
  if (l_pSyncObjInt->GetValue() == 1)
    m_strLBState = _T("occupied");
  else
    m_strLBState = _T("free");

  UpdateData(FALSE);

}

void CDlgWCVlcCnt::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1)
	{
		try
		{
			if (((CButton*)GetDlgItem(IDC_CHK_AUTO_UPDATE))->GetCheck() == BST_CHECKED)
      {
        int l_nRetVal = 0;
        UpdateData();
        CCOSyncObjectInt* l_pSyncObjInt = NULL;

        l_pSyncObjInt = m_pHWIntf->WCGetPosition();
        l_pSyncObjInt->Synchronize();
        l_nRetVal = l_pSyncObjInt->GetValue();
        m_strWCActPos.Format(_T("%#08x"), l_nRetVal);
        m_nActPos = l_nRetVal;

        l_pSyncObjInt = m_pHWIntf->WCGetActVelocityCounts();
        l_pSyncObjInt->Synchronize();
        l_nRetVal = l_pSyncObjInt->GetValue();
        m_strWCActVlc.Format(_T("%#08x"), l_nRetVal);

        l_pSyncObjInt = m_pHWIntf->WCGetLastVelocityCounts();
        l_pSyncObjInt->Synchronize();
        l_nRetVal = l_pSyncObjInt->GetValue();
        m_strWCLastVlc.Format(_T("%#08x"), l_nRetVal);
  
        UpdateData(FALSE);
      }
		}
		catch(...)
		{
			KillTimer(nIDEvent);
		}
	}
	
	CDialog::OnTimer(nIDEvent);
}
