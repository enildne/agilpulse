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
	CString		m_setDefaultString;
	CString		m_setLevelString;
	CString		m_setRingdownString;
	CString		m_voltTestStartPosition;		// Volt 1 check start position
	CString		m_voltTestEndPosition;			// Volt 1 check end position
	CString		m_test1Min;		 
	CString		m_test1Max;		 
	CString		m_test2Min;		 
	CString		m_test2Max;		 
	CString		m_testDiff;		 
	CString		m_rtTestLowPosition;
	CString		m_rtTestLowLimit;
	CString		m_rtTestHighPosition;
	CString		m_rtTestHighLimit;

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_lstSetting;
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLbnDblclkSetList();

	CString		GetDefaultSetting(void)		{return m_setDefaultString;}
	CString		GetLevelSetting(void)		{return m_setLevelString;}
	CString		GetRingdownSetting(void)	{return m_setRingdownString;}
	CString		GetvoltTestStartPosition(void)		{return m_voltTestStartPosition;}
	CString		GetvoltTestEndPosition(void)		{return m_voltTestEndPosition;}
	CString		GetvoltTestLowPosition(void)		{return m_rtTestLowPosition;}
	CString		GetvoltTestLowLimit(void)			{return m_rtTestLowLimit;}
	CString		GetvoltTestHighPosition(void)		{return m_rtTestHighPosition;}
	CString		GetvoltTestHighLimit(void)			{return m_rtTestHighLimit;}

	//CString		GetRingdownSetting(void)	{return m_setRingdownString;}
};
