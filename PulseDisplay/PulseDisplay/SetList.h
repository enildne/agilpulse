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
	CString		m_setDefaultString;
	CString		m_setRingdownString;
	CString		m_setLevelString;
	CString		m_voltTestStartPosition;		// Volt 1 check start position
	CString		m_voltTestEndPosition;			// Volt 1 check end position
	CString		m_rtTestLowPosition;
	CString		m_rtTestLowLimit;
	CString		m_rtTestHighPosition;
	CString		m_rtTestHighLimit;
	CString		m_test1Min;		 
	CString		m_test1Max;		 
	CString		m_test2Min;		 
	CString		m_test2Max;		 
	CString		m_testDiff;		 

	CString		m_levelTestRangeMin;
	CString		m_levelTestRangeMax;
	CString		m_levelTestLevelMin;
	CString		m_levelTestLevelMax;

	CString		m_Standard_Volt;

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_lstSetting;
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLbnDblclkSetList();

	CString		GetDefaultSetting(void)				{return m_setDefaultString;}
	CString		GetLevelSetting(void)				{return m_setLevelString;}
	CString		GetRingdownSetting(void)			{return m_setRingdownString;}
	CString		GetvoltTestStartPosition(void)		{return m_voltTestStartPosition;}
	CString		GetvoltTestEndPosition(void)		{return m_voltTestEndPosition;}
	CString		GetRTTestLowPosition(void)			{return m_rtTestLowPosition;}
	CString		GetRTTestLowLimit(void)				{return m_rtTestLowLimit;}
	CString		GetRTTestHighPosition(void)			{return m_rtTestHighPosition;}
	CString		GetRTTestHighLimit(void)			{return m_rtTestHighLimit;}
	CString		GetRTTest1Min(void)					{return m_test1Min;}
	CString		GetRTTest1Max(void)					{return m_test1Max;}
	CString		GetRTTest2Min(void)					{return m_test2Min;}
	CString		GetRTTest2Max(void)					{return m_test2Max;}
	CString		GetRTTestDiff(void)					{return m_testDiff;}

	CString		GetLevelRangeMax(void)				{return m_levelTestRangeMax;}
	CString		GetLevelRangeMin(void)				{return m_levelTestRangeMin;}
	CString		GetLevelMin(void)					{return m_levelTestLevelMin;}
	CString		GetLevelMax(void)					{return m_levelTestLevelMax;}
	CString		GetStandardVolt(void)				{return m_Standard_Volt;}

};
