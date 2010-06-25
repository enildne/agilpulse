// PulseDisplayDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "visa.h"

#include "DrawRect.h"
#include "DefineAndSize.h"
#include "DevList.h"
#include "LoginDlg.h"
#include "SetList.h"

#define TID_TIME				1					// �ð�� TIMER
#define	DATA_START_POSITION		6
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

public:
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl	m_ctlTabMain;
	CButton		m_btnTab1_1;
	CButton		m_btnTab1_2;
	CButton		m_btnTab1_3;
	CButton		m_btnTab1_4;
	CDrawRect	m_stDraw;
	CString		m_modelName;
	CString		m_defaultSetCmd;
	CString		m_ringdownSetCmd;
	CString		m_levelSetCmd;

	int			m_iVolOneStartPosition;
	int			m_iVolOneEndPosition;
	int			m_iRingdownStartPosition;
	int			m_iRingdownEndPosition;
	int			m_iRTTestHighPosition;
	int			m_iRTTestLowPosition;
	int			m_iRTTestHighLimit;
	int			m_iRTTestLowLimit;

	int			m_iRTTestDiff;

	int			m_iPreRingdownStart;
	int			m_iPreRingdownEnd;

	ViSession	defaultRM, vi ;
	char		m_cBuf[256];
	CStatic		m_stDevName;
	
	ViChar		m_devDesc[256];
	void SetDeviceDesc(ViChar* selDev)	{
		memset(m_devDesc, NULL, sizeof(m_devDesc));
		memcpy((void*)m_devDesc, (void*)selDev, strlen(selDev));
	}
	ViChar* GetDeviceDesc(void) {
		return m_devDesc;
	}

	void ShowFirstTabCtrl(void);
	void HideFirstTabCtrl(void);
	afx_msg void OnBnClickedTab1Btn1();
	afx_msg void OnBnClickedTab1Btn2();
	afx_msg void OnBnClickedTab1Btn3();
	afx_msg void OnBnClickedTab1Btn4();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);

private:
	void SetTAB1Disp(void);
	CString	m_UserName;

	// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_rdLevelTest;
	CButton m_rdRTTest;
	afx_msg void OnBnClickedRtTest();
	afx_msg void OnBnClickedLevelTest();
	int CheckRingdownPosition(unsigned char* data);
	int CheckLevelOnePosition(unsigned char* data);
};

