#pragma once
#include "afxwin.h"
#include "visa.h"
#include "PulseDisplay.h"
#include "PulseDisplayDlg.h"
// CDevList 대화 상자입니다.

class CDevList : public CDialog
{
	DECLARE_DYNAMIC(CDevList)

public:
	CDevList(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDevList();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DEVLIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_lstDevice;
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLbnDblclkDevList();

	CString	selDevice;
	CString	GetDevice(void)	{return selDevice;}
	ViChar	m_arrayDesc[256][256];				// 256개까지 연결지원
	int		descCount;
};
