#pragma once
#include "afxwin.h"


// CDevList ��ȭ �����Դϴ�.

class CDevList : public CDialog
{
	DECLARE_DYNAMIC(CDevList)

public:
	CDevList(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDevList();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DEVLIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_lstDevice;
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
