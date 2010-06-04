#pragma once
#include "afxwin.h"


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
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
