// DlgWCSetConfig.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "EBNFDlgWCSetConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgWCSetConfig dialog


DlgWCSetConfig::DlgWCSetConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DlgWCSetConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgWCSetConfig)
	m_dw01VelocityWarnLevelHigh = 10200;
	m_dw02VelocityWarnLevelLow = 10200;
	m_dw03VelocityErrorLevelHigh = 20000;
	m_dw04VelocityErrorLevelLow = 20000;
	m_dw05IniWatchTime = 10;
	m_dw06NomVelocityIniTime = 15;
	m_dw07ForwardWatchTime = 250;
	m_dw08BackwardWatchTime = 500;
	m_dw09ParkWatchTime = 250;
	m_dw10WatchTime = 5000;
	m_dw11RefWatchTime1 = 250;
	m_dw12RefWatchTime2 = 500;
	m_dw13StartDisForward = 100;
	m_dw15MeasuringDistance = 90;
	m_dw14EndDisForward = 1850;
	m_dw16StartDisBackward = 110;
	m_dw17RefDistance1 = 100;
	m_dw18RefDistance2 = 400;
	m_dw19PFactor = 1;
	m_dwIFactor = 100;
	m_dw21DFactor = 0;
	m_dw22UpperLimit = 65500;
	m_i23LowerLimit = -65500;
	m_dw24RunAfterTime = 60;
	m_dw25AccStandByMode = 1;
	//}}AFX_DATA_INIT
}


void DlgWCSetConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgWCSetConfig)
	DDX_Text(pDX, IDC_EDT_WC_1, m_dw01VelocityWarnLevelHigh);
	DDX_Text(pDX, IDC_EDT_WC_2, m_dw02VelocityWarnLevelLow);
	DDX_Text(pDX, IDC_EDT_WC_3, m_dw03VelocityErrorLevelHigh);
	DDX_Text(pDX, IDC_EDT_WC_4, m_dw04VelocityErrorLevelLow);
	DDX_Text(pDX, IDC_EDT_WC_5, m_dw05IniWatchTime);
	DDX_Text(pDX, IDC_EDT_WC_6, m_dw06NomVelocityIniTime);
	DDX_Text(pDX, IDC_EDT_WC_7, m_dw07ForwardWatchTime);
	DDX_Text(pDX, IDC_EDT_WC_8, m_dw08BackwardWatchTime);
	DDX_Text(pDX, IDC_EDT_WC_9, m_dw09ParkWatchTime);
	DDX_Text(pDX, IDC_EDT_WC_10, m_dw10WatchTime);
	DDX_Text(pDX, IDC_EDT_WC_11, m_dw11RefWatchTime1);
	DDX_Text(pDX, IDC_EDT_WC_12, m_dw12RefWatchTime2);
	DDX_Text(pDX, IDC_EDT_WC_13, m_dw13StartDisForward);
	DDX_Text(pDX, IDC_EDT_WC_15, m_dw15MeasuringDistance);
	DDX_Text(pDX, IDC_EDT_WC_14, m_dw14EndDisForward);
	DDX_Text(pDX, IDC_EDT_WC_16, m_dw16StartDisBackward);
	DDX_Text(pDX, IDC_EDT_WC_17, m_dw17RefDistance1);
	DDX_Text(pDX, IDC_EDT_WC_18, m_dw18RefDistance2);
	DDX_Text(pDX, IDC_EDT_WC_19, m_dw19PFactor);
	DDX_Text(pDX, IDC_EDT_WC_20, m_dwIFactor);
	DDX_Text(pDX, IDC_EDT_WC_21, m_dw21DFactor);
	DDX_Text(pDX, IDC_EDT_WC_22, m_dw22UpperLimit);
	DDX_Text(pDX, IDC_EDT_WC_23, m_i23LowerLimit);
	DDX_Text(pDX, IDC_EDT_WC_24, m_dw24RunAfterTime);
	DDX_Text(pDX, IDC_EDT_WC_25, m_dw25AccStandByMode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgWCSetConfig, CDialog)
	//{{AFX_MSG_MAP(DlgWCSetConfig)
	ON_BN_CLICKED(IDC_BTN_WCCONFIG_SET_DEFAULT, OnBtnWcconfigSetDefault)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgWCSetConfig message handlers

BOOL DlgWCSetConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgWCSetConfig::OnBtnWcconfigSetDefault() 
{
	m_dw01VelocityWarnLevelHigh = 10200;
	m_dw02VelocityWarnLevelLow = 10200;
	m_dw03VelocityErrorLevelHigh = 20000;
	m_dw04VelocityErrorLevelLow = 20000;
	m_dw05IniWatchTime = 10;
	m_dw06NomVelocityIniTime = 15;
	m_dw07ForwardWatchTime = 250;
	m_dw08BackwardWatchTime = 500;
	m_dw09ParkWatchTime = 250;
	m_dw10WatchTime = 5000;
	m_dw11RefWatchTime1 = 250;
	m_dw12RefWatchTime2 = 500;
	m_dw13StartDisForward = 100;
	m_dw15MeasuringDistance = 90;
	m_dw14EndDisForward = 1850;
	m_dw16StartDisBackward = 110;
	m_dw17RefDistance1 = 100;
	m_dw18RefDistance2 = 400;
	m_dw19PFactor = 1000;
	m_dwIFactor = 1000;
	m_dw21DFactor = 0;
	m_dw22UpperLimit = 65500;
	m_i23LowerLimit = -65500;
	m_dw24RunAfterTime = 60;
	m_dw25AccStandByMode = 100;
  UpdateData(FALSE);	
}
