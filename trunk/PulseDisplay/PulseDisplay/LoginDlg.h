#pragma once
#include "afxwin.h"

#include "DefineAndSize.h"

// CLoginDlg ��ȭ �����Դϴ�.

class CLoginDlg : public CDialog
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CLoginDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	CString	m_UserName;

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadioUser();
	afx_msg void OnBnClickedRadioAdmin();
	afx_msg void OnBnClickedLoginBtn();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	CStatic m_stLoginName;
	CStatic m_stLoginPwd;
	CEdit m_edtLoginName;
	CEdit m_edtLoginPwd;
	CButton m_btnLogin;
	CButton m_rdUser;
	CButton m_rdAdmin;

	void setUserName(CString& name) {m_UserName = name;}
	CString	getUserName(void) {return m_UserName;}
};

#define USER_ACCOUNT	"user"
#define ADMIN_ACCOUNT	"admin"
