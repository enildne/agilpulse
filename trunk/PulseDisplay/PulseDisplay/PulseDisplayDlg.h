// PulseDisplayDlg.h : 헤더 파일
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
#include "Signal.h"

#define TID_TIME				1					// 시계용 TIMER
#define	DATA_START_POSITION		6
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

	int			m_iLevelRangeMin;
	int			m_iLevelRangeMax;
	int			m_iLevelMin;
	int			m_iLevelMax;
	
	int			m_standard_1volt;

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
	afx_msg void OnBnClickedRtTest();
	afx_msg void OnBnClickedLevelTest();
	afx_msg void OnClose();
	CButton m_rdLevelTest;
	CButton m_rdRTTest;

	int CheckRingdownPosition(unsigned char* data);
	int CheckLevelOnePosition(unsigned char* data);
	bool Check16Value(unsigned char* data, int ringingPoint, int LevelOnePoint);
	bool CheckBeforeValue(unsigned char* data, int ringingPoint, int LevelOnePoint);
	void SignalReset(void);

	CStatic m_picLogo;
	CStatic m_stLog;
	CFont	m_font;
	void	SetLogData(CString name, int succCount, int failCount, CString testKind = "",double x1_data = 0, double x2_data = 0, double diff_data = 0, double volt_data = 0, BOOL bPass = FALSE);
	BOOL	m_bPass;

private:
	void		SetTAB1Disp(void);
	CString		m_UserName;
	int			m_iRingingSuccess, m_iRingingFail;
	int			m_iLevelSuccess, m_iLevelFail;
	CSignal		signalWindow[SIGNAL_COUNT];
	CSignal*	MainSignal;
	CStdioFile	m_logFile;							// Log 파일
	CStdioFile	m_flushLogFile;						// 마지막 줄 지울때 쓰는 Temp Log 파일
	CString		m_strLogFileName;					// Log 파일 이름

	// 구현
protected:
	HICON m_hIcon;

	// 메시지 맵 함수를 생성했습니다.
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void SetLogFile(void);
};

