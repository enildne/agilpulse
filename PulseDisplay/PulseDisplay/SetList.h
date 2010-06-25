#pragma once
#include "afxwin.h"

#include "PulseDisplay.h"
#include "PulseDisplayDlg.h"

// CSetList 대화 상자입니다.

class CSetList : public CDialog
{
	DECLARE_DYNAMIC(CSetList)

public:
	CSetList(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSetList();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SETLIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_lstSetting;
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLbnDblclkSetList();

	CString		m_setDefaultString;
	CString		m_setLevelString;
	CString		m_setRingdownString;
	CString		GetDefaultSetting(void)		{return m_setDefaultString;}
	CString		GetLevelSetting(void)		{return m_setLevelString;}
	CString		GetRingdownSetting(void)	{return m_setRingdownString;}
};
