#pragma once
#include "afxwin.h"
#include "visa.h"
#include "PulseDisplay.h"
#include "PulseDisplayDlg.h"
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
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLbnDblclkDevList();

	CString	selDevice;
	CString	GetDevice(void)	{return selDevice;}
	ViChar	m_arrayDesc[256][256];				// 256������ ��������
	int		descCount;
};
