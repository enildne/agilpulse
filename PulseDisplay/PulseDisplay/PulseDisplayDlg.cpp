// PulseDisplayDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "PulseDisplayDlg.h"
#include ".\pulsedisplaydlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPulseDisplayDlg 대화 상자



CPulseDisplayDlg::CPulseDisplayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPulseDisplayDlg::IDD, pParent),
	m_iRingingSuccess(0),
	m_iRingingFail(0),
	m_iLevelSuccess(0),
	m_iLevelFail(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPulseDisplayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MAIN, m_ctlTabMain);
	DDX_Control(pDX, IDC_TAB1_BTN1, m_btnTab1_1);
	DDX_Control(pDX, IDC_TAB1_BTN2, m_btnTab1_2);
	DDX_Control(pDX, IDC_TAB1_BTN3, m_btnTab1_3);
	DDX_Control(pDX, IDC_TAB1_BTN4, m_btnTab1_4);
	DDX_Control(pDX, IDC_DEVICE_NAME, m_stDevName);
	DDX_Control(pDX, IDC_RT_TEST, m_rdRTTest);
	DDX_Control(pDX, IDC_LEVEL_TEST, m_rdLevelTest);
	DDX_Control(pDX, IDC_LOGO_PIC, m_picLogo);
	DDX_Control(pDX, IDC_ST_LOG, m_stLog);
}

BEGIN_MESSAGE_MAP(CPulseDisplayDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, OnTcnSelchangeTabMain)
	ON_BN_CLICKED(IDC_TAB1_BTN1, OnBnClickedTab1Btn1)
	ON_BN_CLICKED(IDC_TAB1_BTN2, OnBnClickedTab1Btn2)
	ON_BN_CLICKED(IDC_TAB1_BTN3, OnBnClickedTab1Btn3)
	ON_BN_CLICKED(IDC_TAB1_BTN4, OnBnClickedTab1Btn4)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RT_TEST, OnBnClickedRtTest)
	ON_BN_CLICKED(IDC_LEVEL_TEST, OnBnClickedLevelTest)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CPulseDisplayDlg 메시지 처리기

BOOL CPulseDisplayDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	// 프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// 로그인 화면 구성 필요.
#ifdef LOGIN_DLG
	CLoginDlg	loginDlg;
	BOOL		noLogin = FALSE;
	while(loginDlg.DoModal() != IDOK)
	{
		if(AfxMessageBox(INVALID_USER, MB_OKCANCEL, NULL) == IDOK)
		{
			noLogin = TRUE;
			break;
		}
	}
	
	if(noLogin)
	{
		::PostQuitMessage(WM_QUIT);
		return FALSE;
	}
	else
		m_UserName = loginDlg.getUserName();

	// 로그인 화면 종료
#endif

#ifndef LIMIT_SCREEN_SIZE
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);

	this->SetWindowPos(&CWnd::wndNoTopMost, 0, 0, cx, cy, SWP_NOMOVE);
#else
	this->SetWindowPos(&CWnd::wndNoTopMost, 0, 0, MAIN_DLG_WIDTH, MAIN_DLG_HEIGHT, SWP_NOMOVE);
#endif

	this->SetWindowText(MAIN_WINDOW_NAME);

	SetTimer(TID_TIME, 1000, NULL);

	m_ctlTabMain.InsertItem(0, _T(TAB1_DSP_NAME));
	m_ctlTabMain.InsertItem(1, _T(TAB2_DSP_NAME));
	m_ctlTabMain.InsertItem(2, _T(TAB3_DSP_NAME));
	m_ctlTabMain.InsertItem(3, _T(TAB4_DSP_NAME));
#ifndef LIMIT_SCREEN_SIZE
	m_ctlTabMain.SetItemSize(CSize(cy / 4 - 5));
#else
	m_ctlTabMain.SetItemSize(CSize(MAIN_DLG_WIDTH / 4 - 5));
#endif

	m_modelName.Empty();				// 모델이름 초기화

	SetTAB1Disp();
	SetLogFile();

	return TRUE;  // 컨트롤에 대한 포커스를 설정하지 않을 경우 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면 
// 아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
// 프레임워크에서 이 작업을 자동으로 수행합니다.

void CPulseDisplayDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.FillRect(rect, WHITE_BRUSH);

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다. 
HCURSOR CPulseDisplayDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPulseDisplayDlg::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
	
	switch(m_ctlTabMain.GetCurSel()) {
	case 0:						// 최좌측 탭
	default:
		ShowFirstTabCtrl();
		break;
	case 1:
		HideFirstTabCtrl();
		break;
	case 2:
		HideFirstTabCtrl();
		break;
	case 3:
		HideFirstTabCtrl();
		break;
	}

}


int CPulseDisplayDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_stDraw.Create(_T("DrawPlace"), WS_CHILD | WS_THICKFRAME, CRect(0, 0, 0, 0), this, IDC_TAB1_DRAW_MAIN);
	m_stDraw.ShowWindow(SW_SHOW);

	return 0;
}


void CPulseDisplayDlg::OnTimer(UINT nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(nIDEvent == TID_TIME)
	{
		CString CurrentTimeText, devName;
		CTime CurTime;

		CurTime = CTime::GetCurrentTime(); // 현재 시스템 시각을 구한다.
		CurrentTimeText.Format( " - %04d-%02d-%02d / %02d:%02d:%02d"
			, CurTime.GetYear()
			, CurTime.GetMonth()
			, CurTime.GetDay()
			, CurTime.GetHour()
			, CurTime.GetMinute()
			, CurTime.GetSecond()
			);
			
		m_stDevName.GetWindowText(devName);
		m_stDevName.SetWindowText(devName.Left(devName.GetLength() - CurrentTimeText.GetLength()) + CurrentTimeText);
	}

	CDialog::OnTimer(nIDEvent);
}


void CPulseDisplayDlg::ShowFirstTabCtrl(void)
{
	m_btnTab1_1.ShowWindow(SW_SHOW);
	m_btnTab1_2.ShowWindow(SW_SHOW);
	m_btnTab1_3.ShowWindow(SW_SHOW);
	m_btnTab1_4.ShowWindow(SW_SHOW);
	m_stDevName.ShowWindow(SW_SHOW);
	m_stDraw.ShowWindow(SW_SHOW);
	m_rdRTTest.ShowWindow(SW_SHOW);
	m_rdLevelTest.ShowWindow(SW_SHOW);
	m_stLog.ShowWindow(SW_SHOW);
	m_picLogo.ShowWindow(SW_SHOW);
	SignalReset();
	SetTimer(TID_TIME, 1000, NULL);
}

void CPulseDisplayDlg::HideFirstTabCtrl(void)
{
	m_btnTab1_1.ShowWindow(SW_HIDE);
	m_btnTab1_2.ShowWindow(SW_HIDE);
	m_btnTab1_3.ShowWindow(SW_HIDE);
	m_btnTab1_4.ShowWindow(SW_HIDE);
	m_stDevName.ShowWindow(SW_HIDE);
	m_stDraw.ShowWindow(SW_HIDE);
	m_rdRTTest.ShowWindow(SW_HIDE);
	m_rdLevelTest.ShowWindow(SW_HIDE);
	m_stLog.ShowWindow(SW_HIDE);
	m_picLogo.ShowWindow(SW_HIDE);
	SignalReset();
	KillTimer(TID_TIME);
}

void CPulseDisplayDlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CString		result_message;
	result_message.Format(RESUT_MESSAGE, \
		m_iRingingSuccess, m_iRingingFail, m_iLevelSuccess, m_iLevelFail);
	
	m_logFile.SeekToEnd();
	m_logFile.WriteString(result_message);
	m_logFile.Close();

	CDialog::OnClose();
}

void CPulseDisplayDlg::SetLogFile(void)
{
	CTime CurTime;
	CurTime = CTime::GetCurrentTime(); // 현재 시스템 시각을 구한다.

	CreateDirectory(STR_LOG_DIR, NULL);
	m_strLogFileName.Format(LOG_FILE_NAME_FORMAT, \
		STR_LOG_DIR, CurTime.GetYear(), CurTime.GetMonth(), CurTime.GetDay(), CurTime.GetHour(), CurTime.GetMinute(), m_UserName);

	m_logFile.Open(m_strLogFileName, CStdioFile::modeCreate | CStdioFile::modeReadWrite |CStdioFile::modeNoTruncate);
}
