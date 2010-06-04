// PulseDisplayDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "visa.h"

#include "DrawRect.h"
#include "StringRc.h"
#include "DevList.h"

// CPulseDisplayDlg ��ȭ ����
class CPulseDisplayDlg : public CDialog
{
// ����
public:
	CPulseDisplayDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	enum { IDD = IDD_PULSEDISPLAY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl	m_ctlTabMain;
	CButton		m_btnTab1_1;
	CButton		m_btnTab1_2;
	CButton		m_btnTab1_3;
	CButton		m_btnTab1_4;
	CDrawRect	m_stDraw;

	ViSession	defaultRM, vi ;
	char m_cBuf[256];

	afx_msg void OnBnClickedTab1Btn1();
	afx_msg void OnBnClickedTab1Btn2();
	afx_msg void OnBnClickedTab1Btn3();
	afx_msg void OnBnClickedTab1Btn4();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	void SetTAB1Disp(void);
};

#define INTAB_BTN_START_X		10
#define INTAB_BTN_START_Y		40

#define BUTTON_WIDTH			80
#define BUTTON_HEIGHT			30
#define BUTTON_GAP				10

#define MAIN_DLG_WIDTH			800
#define MAIN_DLG_HEIGHT			600

#define CONFIG_EXT				TEXT(".cfg")