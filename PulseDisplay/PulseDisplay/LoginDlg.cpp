// LoginDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "LoginDlg.h"
#include ".\logindlg.h"


// CLoginDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CLoginDlg, CDialog)
CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOGIN_NAME, m_stLoginName);
	DDX_Control(pDX, IDC_LOGIN_PWD, m_stLoginPwd);
	DDX_Control(pDX, IDC_EDT_LOGIN_NAME, m_edtLoginName);
	DDX_Control(pDX, IDC_EDT_LOGIN_PWD, m_edtLoginPwd);
	DDX_Control(pDX, IDC_RADIO_USER, m_rdUser);
	DDX_Control(pDX, IDC_RADIO_ADMIN, m_rdAdmin);
	DDX_Control(pDX, ID_LOGIN_BTN, m_btnLogin);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_RADIO_USER, OnBnClickedRadioUser)
	ON_BN_CLICKED(IDC_RADIO_ADMIN, OnBnClickedRadioAdmin)
	ON_BN_CLICKED(ID_LOGIN_BTN, OnBnClickedLoginBtn)
END_MESSAGE_MAP()


// CLoginDlg �޽��� ó�����Դϴ�.

int CLoginDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	this->SetWindowText(LOGIN_DLG_NAME);

	return 0;
}

BOOL CLoginDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_stLoginName.SetWindowText(LOGIN_STRING_NAME);
	m_stLoginPwd.SetWindowText(LOGIN_STRING_PWD);
	m_btnLogin.SetWindowText(LOGIN_BTN);

	m_rdUser.SetWindowText(LOGIN_RD_USER);
	m_rdAdmin.SetWindowText(LOGIN_RD_ADMIN);

	m_rdUser.SetCheck(TRUE);
	m_rdAdmin.SetCheck(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CLoginDlg::OnBnClickedRadioUser()
{
	m_rdAdmin.SetCheck(FALSE);
	m_rdUser.SetCheck(TRUE);
}

void CLoginDlg::OnBnClickedRadioAdmin()
{
	m_rdUser.SetCheck(FALSE);
	m_rdAdmin.SetCheck(TRUE);
}

void CLoginDlg::OnBnClickedLoginBtn()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if(m_rdAdmin.GetCheck() == TRUE)
	{
		RTrace(_T("[zest] Admin\n"));		// Admin Check ��ƾ
	}
	else if(m_rdUser.GetCheck() == TRUE)
	{
		RTrace(_T("[zest] User\n"));		// User Check ��ƾ
	}

	CDialog::OnOK();
}
