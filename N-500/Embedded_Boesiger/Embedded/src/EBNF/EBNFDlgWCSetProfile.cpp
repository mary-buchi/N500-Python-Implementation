// DlgWCSetProfile.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "EBNFDlgWCSetProfile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgWCSetProfile dialog


DlgWCSetProfile::DlgWCSetProfile(CWnd* pParent /*=NULL*/)
	: CDialog(DlgWCSetProfile::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgWCSetProfile)
	m_dw01NomAcc = 10;
	m_dw02NomDec = 10;
	m_dw03NomVelocity = 10000;
	//}}AFX_DATA_INIT
}


void DlgWCSetProfile::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgWCSetProfile)
	DDX_Text(pDX, IDC_EDT_WC_1, m_dw01NomAcc);
	DDX_Text(pDX, IDC_EDT_WC_2, m_dw02NomDec);
	DDX_Text(pDX, IDC_EDT_WC_3, m_dw03NomVelocity);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgWCSetProfile, CDialog)
	//{{AFX_MSG_MAP(DlgWCSetProfile)
	ON_BN_CLICKED(IDC_BTN_WCPROFILE_SET_DEFAULT, OnBtnWcprofileSetDefault)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgWCSetProfile message handlers

BOOL DlgWCSetProfile::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgWCSetProfile::OnBtnWcprofileSetDefault() 
{
	m_dw01NomAcc = 10;
	m_dw02NomDec = 10;
	m_dw03NomVelocity = 10;
  UpdateData(FALSE);	
}
