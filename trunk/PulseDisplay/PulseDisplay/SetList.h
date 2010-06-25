#pragma once
#include "afxwin.h"

#include "PulseDisplay.h"
#include "PulseDisplayDlg.h"

// CSetList ��ȭ �����Դϴ�.

class CSetList : public CDialog
{
	DECLARE_DYNAMIC(CSetList)

public:
	CSetList(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSetList();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SETLIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
