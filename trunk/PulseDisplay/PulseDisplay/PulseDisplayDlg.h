// PulseDisplayDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "visa.h"

#include "DrawRect.h"
#include "DefineAndSize.h"
#include "DevList.h"

// CPulseDisplayDlg 대화 상자
class CPulseDisplayDlg : public CDialog
{
// 생성
public:
	CPulseDisplayDlg(CWnd* pParent = NULL);	// 표준 생성자

// 대화 상자 데이터
	enum { IDD = IDD_PULSEDISPLAY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원


// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
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
	CString		m_modelName;

	ViSession	defaultRM, vi ;
	char		m_cBuf[256];
	CStatic		m_stDevName;
	double*		ReadWaveform(ViSession vi, long* elements);
	ViChar		devDesc[256];

	void SetDeviceDesc(ViChar* selDev)
	{
		memset(devDesc, NULL, sizeof(devDesc));
		memcpy((void*)devDesc, (void*)selDev, strlen(selDev));
	}

	afx_msg void OnBnClickedTab1Btn1();
	afx_msg void OnBnClickedTab1Btn2();
	afx_msg void OnBnClickedTab1Btn3();
	afx_msg void OnBnClickedTab1Btn4();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);


private:
	void SetTAB1Disp(void);

};

#define TID_TIME	1
