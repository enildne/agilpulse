// LoginDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "LoginDlg.h"
#include ".\logindlg.h"


// CLoginDlg 대화 상자입니다.

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


// CLoginDlg 메시지 처리기입니다.

int CLoginDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	this->SetWindowText(LOGIN_DLG_NAME);

	return 0;
}

BOOL CLoginDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_stLoginName.SetWindowText(LOGIN_STRING_NAME);
	m_stLoginPwd.SetWindowText(LOGIN_STRING_PWD);
	m_btnLogin.SetWindowText(LOGIN_BTN);

	m_rdUser.SetWindowText(LOGIN_RD_USER);
	m_rdAdmin.SetWindowText(LOGIN_RD_ADMIN);

	m_rdUser.SetCheck(TRUE);
	m_rdAdmin.SetCheck(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CString		inputName, inputPwd, inputData;
	CStdioFile	accountFile;
	BOOL		isValidUser = FALSE;
	char		dataForRead[1024] = "";
	int			len = 0;

	m_edtLoginName.GetWindowText(inputName);
	m_edtLoginPwd.GetWindowText(inputPwd);

	if(inputName.IsEmpty() || inputPwd.IsEmpty())
	{
		CDialog::OnCancel();
		return;
	}

	if(m_rdAdmin.GetCheck() == TRUE)
	{
		inputData.Format(_T("%s:%s:%s"), inputName, inputPwd, ADMIN_ACCOUNT);
		RTrace(_T("[zest] Admin, data = %s\n"), inputData);		// Admin Check 루틴
	}
	else if(m_rdUser.GetCheck() == TRUE)
	{
		inputData.Format(_T("%s:%s:%s"), inputName, inputPwd, USER_ACCOUNT);
		RTrace(_T("[zest] User, data = %s\n"), inputData);		// User Check 루틴
	}
	
	memcpy(dataForRead, (unsigned char*)(LPCTSTR)inputData, inputData.GetLength());
	len = inputData.GetLength();

	for(int i = 0; i < len; i++)
		dataForRead[i] = ~dataForRead[i];
	dataForRead[i] = 0x0d;

	accountFile.Open(LOGIN_FILE_NAME, CFile::modeRead);

	if(accountFile.m_pStream == NULL)
	{
		AfxMessageBox(NO_USER_ACCOUNT_FILE);
		return;
	}

	while(1)
	{
		CString		fromFileData;

		if(accountFile.ReadString(fromFileData) != NULL)
		{
			if(strcmp(dataForRead, fromFileData.GetBuffer(fromFileData.GetLength())) == 0)
			{
				setUserName(inputName);
				isValidUser = TRUE;
				RTrace("[zest] Match! %s\n", inputData);
				break;
			}
			else
			{
				RTrace("[zest] UnMatch! %s\n", inputData);
			}
		}
		else
			break;
	}
	accountFile.Close();

	if(isValidUser == FALSE)
	{
		AfxMessageBox(NO_USER_ACCOUNT);
		m_edtLoginName.SetWindowText("");
		m_edtLoginPwd.SetWindowText("");
		return;
	}

	CDialog::OnOK();
}

void CLoginDlg::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	GetParent()->DestroyWindow();
}


BOOL CLoginDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	if(pMsg->message == WM_KEYDOWN)
	{
		if(pMsg->wParam == 'A' && GetKeyState(VK_CONTROL) < 0)
		{
			RTrace(_T("[zest] 필요할 경우 User 입력 루틴 추가!\n"));		// User Check 루틴

			CString			accountLevel, inputName, inputPwd, inputData;
			CStdioFile		accountFile;
			unsigned char	dataForWrite[1024] = "";
			int				i = 0, len = 0;

			if(m_rdUser.GetCheck() == TRUE)
				accountLevel.Format(_T("%s"), USER_ACCOUNT);
			else
				accountLevel.Format(_T("%s"), ADMIN_ACCOUNT);

			m_edtLoginName.GetWindowText(inputName);
			m_edtLoginPwd.GetWindowText(inputPwd);

			if(inputName.IsEmpty() || inputPwd.IsEmpty())
				return CDialog::PreTranslateMessage(pMsg);

			inputData.Format(_T("%s:%s:%s"),inputName, inputPwd, accountLevel);

			memcpy(dataForWrite, (unsigned char*)(LPCTSTR)inputData, inputData.GetLength());
			len = inputData.GetLength();

			for(i = 0; i < len; i++)
			{
				dataForWrite[i] = ~dataForWrite[i];
			}
			dataForWrite[i] = 0x0d;
			dataForWrite[i + 1] = 0x0a;
	
			accountFile.Open(LOGIN_FILE_NAME, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
			accountFile.SeekToEnd();
			accountFile.Write(dataForWrite, i + 2);
			accountFile.Close();
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}

