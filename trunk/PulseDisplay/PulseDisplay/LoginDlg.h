#pragma once
#include "afxwin.h"

#include "DefineAndSize.h"

// CLoginDlg 대화 상자입니다.

class CLoginDlg : public CDialog
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CLoginDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadioUser();
	afx_msg void OnBnClickedRadioAdmin();
	afx_msg void OnBnClickedLoginBtn();

	CStatic m_stLoginName;
	CStatic m_stLoginPwd;
	CEdit m_edtLoginName;
	CEdit m_edtLoginPwd;
	CButton m_btnLogin;
	CButton m_rdUser;
	CButton m_rdAdmin;
protected:
	virtual void OnCancel();
};
