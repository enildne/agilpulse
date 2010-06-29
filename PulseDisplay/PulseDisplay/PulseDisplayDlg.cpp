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

void CPulseDisplayDlg::OnBnClickedTab1Btn1()
{
	CDevList	devList(this);
	if(devList.DoModal() == IDOK) {
		m_modelName = devList.GetDevice();
		m_stDevName.SetWindowText(CString(_T(" Device : ")) + m_modelName + CString(_T("                        ")));
		// 뒷부분 Padding 24칸은 시간 표시를 위한 빈칸임
	}
	else {
		AfxMessageBox(NOTSELECT_DEVICE);
	}
}

void CPulseDisplayDlg::OnBnClickedTab1Btn2()
{
	if(m_modelName.IsEmpty() == TRUE) {
		AfxMessageBox(NOTSELECT_DEVICE);
		return;
	}

	CSetList	setList(this);
	ViStatus	status;
	unsigned long actual;

	if(setList.DoModal() == IDOK) {
		BeginWaitCursor();
		m_defaultSetCmd = setList.GetDefaultSetting();
		m_ringdownSetCmd = setList.GetRingdownSetting();
		m_levelSetCmd = setList.GetLevelSetting();

		// 1차 Test 항목
		m_iRTTestHighPosition = atoi(setList.GetRTTestHighPosition());
		m_iRTTestLowPosition = atoi(setList.GetRTTestLowPosition());
		m_iRTTestHighLimit = atoi(setList.GetRTTestHighLimit());
		m_iRTTestLowLimit = atoi(setList.GetRTTestLowLimit());
		
		// 2차 Test 항목
		m_iRingdownStartPosition = atoi(setList.GetRTTest1Min());
		m_iRingdownEndPosition = atoi(setList.GetRTTest1Max());;
		m_iVolOneStartPosition = atoi(setList.GetRTTest2Min());;
		m_iVolOneEndPosition = atoi(setList.GetRTTest2Max());;

		m_iPreRingdownStart = atoi(setList.GetvoltTestStartPosition());
		m_iPreRingdownEnd = atoi(setList.GetvoltTestEndPosition());
		m_stDraw.setVolt1Start(m_iPreRingdownStart);
		m_stDraw.setVolt1End(m_iPreRingdownEnd);
		m_standard_1volt = atoi(setList.GetStandardVolt());
		m_stDraw.setStandardVolt(m_standard_1volt);
		m_iRTTestDiff = atoi(setList.GetRTTestDiff());

		m_stDraw.m_levelRangeMax = atoi(setList.GetLevelRangeMax());
		m_stDraw.m_levelMax = atoi(setList.GetLevelMax());
		m_stDraw.m_levelRangeMin = atoi(setList.GetLevelRangeMin());
		m_stDraw.m_levelMin = atoi(setList.GetLevelMin());

		status = viOpenDefaultRM(&defaultRM);
		if (status < VI_SUCCESS) goto error;
		status = viOpen(defaultRM, GetDeviceDesc(), VI_NULL, VI_NULL, &vi);
		if (status < VI_SUCCESS) goto error;
		status = viWrite(vi, (ViBuf)m_defaultSetCmd.GetBuffer(m_defaultSetCmd.GetLength()), m_defaultSetCmd.GetLength(), &actual);
		//status = viPrintf(vi, m_setCmdByFile.GetBuffer());
		if (status < VI_SUCCESS) goto error;
		viClose(vi);
		viClose(defaultRM);
		Sleep(1500);
		AfxMessageBox(DEVICE_SET_SUCCESS);
		EndWaitCursor();
	}
	else {
		AfxMessageBox(NOTSELECT_CFG);
	}
	return;

error:
	EndWaitCursor();
	AfxMessageBox(DEVICE_SET_FAILED);
	if (vi != VI_NULL)			viClose(vi);
	if (defaultRM != VI_NULL)	viClose(defaultRM);

	return;

}

void CPulseDisplayDlg::OnBnClickedTab1Btn3()
{
#ifndef USE_RANDOM_DATA
	if(m_modelName.IsEmpty() == TRUE) {
		AfxMessageBox(NOTSELECT_DEVICE);
		return;
	}

	if(m_defaultSetCmd.IsEmpty() == TRUE || m_ringdownSetCmd.IsEmpty() == TRUE || m_levelSetCmd.IsEmpty() == TRUE) {
		AfxMessageBox(NOTSELECT_CFG);
		return;
	}
#endif

	ViStatus status;
	ViChar buffer[256];
	double* wfm = NULL;
	char CurveCmd[] = "CURVE?";
	unsigned char strres [VALUE_COUNT + 10];
	memset(strres, NULL, sizeof(strres));
	unsigned long actual;
	int	repeat = 0, readFailFlag = 0, dataFailCount = 0;
	char	dataFailed[5] = "";
	BOOL	Failed = FALSE;
	CString dispData;
	double	volt;
	double	x1, x2, diff;
	int ringDown, levelOne;

	m_btnTab1_3.EnableWindow(FALSE);

	m_stDraw.setGraphDraw(FALSE);
	m_stDraw.Invalidate();
	m_stDraw.UpdateWindow();

	BeginWaitCursor();
	// Open a default Session
#ifdef MAKE_SAMPLE_FILE
	CFile	sampleCreate;
#endif

#ifdef USE_SAMPLE_FILE
	CFile	sampleFile;
	sampleFile.Open(_T("sample.bin"), CFile::modeRead);

	sampleFile.Read(strres, sizeof(strres));

	m_stDraw.setPulseData(&strres[DATA_START_POSITION]);			// #42500 를 제외한 시작점 
	m_stDraw.Invalidate();
	m_stDraw.UpdateWindow();
#else

#ifndef USE_RANDOM_DATA
	status = viOpenDefaultRM(&defaultRM);
	if (status < VI_SUCCESS) goto error;

	status = viOpen(defaultRM, GetDeviceDesc(), VI_NULL, VI_NULL, &vi);
	if (status < VI_SUCCESS) goto error;
#endif

	if(m_rdRTTest.GetCheck() == TRUE)
	{
#ifndef USE_RANDOM_DATA
		SignalReset();
		resetBuffer();
		for(repeat = 0; repeat < MAX_REPEAT_PER_TEST; repeat++)
		{
			if(readFailFlag >= 3)					// FAIL 이 3번 이상
			{
				AfxMessageBox(INVALID_CURVE);
				m_stDraw.setPulseData(&strres[DATA_START_POSITION]);			// #42500 를 제외한 시작점 
				m_stDraw.Invalidate();
				m_stDraw.UpdateWindow();
				SignalReset();
				break;
			}

			status = viClear(vi);
			if (status < VI_SUCCESS) goto error;

			status = viWrite(vi, (ViBuf)CurveCmd, (ViUInt32)strlen(CurveCmd), &actual);
			//status = viPrintf(vi, CurveCmd);
			if (status < VI_SUCCESS) goto error;

			status = viScanf(vi, "%t", strres);
			if (status < VI_SUCCESS) goto error;

			if(strres[m_iRTTestLowPosition + DATA_START_POSITION] <= m_iRTTestLowLimit &&
				strres[m_iRTTestHighPosition + DATA_START_POSITION] >= m_iRTTestHighLimit)			// Data Get 조건
			{
				ringDown = CheckRingdownPosition(&strres[DATA_START_POSITION]);
				levelOne = CheckLevelOnePosition(&strres[DATA_START_POSITION]);
				
				if(ringDown <= m_iRingdownStartPosition || levelOne <= m_iVolOneStartPosition)
				{
					dataFailed[0] = dataFailed[0] + 1;
					m_dataBuf[repeat].t_failCount++;
					m_dataBuf[repeat].t_pass = FALSE;
					RTrace(_T("#RT 1 : Ringing 짧음\n"));			// Ringing 짧음
				}	
				if(ringDown >= m_iRingdownEndPosition || levelOne >= m_iVolOneEndPosition)
				{
					dataFailed[1] = dataFailed[1] + 1;
					m_dataBuf[repeat].t_failCount++;
					m_dataBuf[repeat].t_pass = FALSE;
					RTrace(_T("#RT 2 : Ringing 김\n"));			// Ringing 김
				}
				if(levelOne - ringDown >= m_iRTTestDiff)
				{
					dataFailed[2] = dataFailed[2] + 1;
					m_dataBuf[repeat].t_failCount++;
					m_dataBuf[repeat].t_pass = FALSE;
					RTrace(_T("#RT 3 : 늘어짐\n"));			// 늘어짐
				}
				if(Check16Value(&strres[DATA_START_POSITION], ringDown, levelOne) == FALSE)
				{
					dataFailed[3] = dataFailed[3] + 1;
					m_dataBuf[repeat].t_failCount++;
					m_dataBuf[repeat].t_pass = FALSE;
					RTrace(_T("#RT 4 : 16개 전 테스트\n"));
				}
				if(CheckBeforeValue(&strres[DATA_START_POSITION], ringDown, levelOne) == FALSE)
				{
					dataFailed[4] = dataFailed[4] + 1;
					m_dataBuf[repeat].t_failCount++;
					m_dataBuf[repeat].t_pass = FALSE;
					RTrace(_T("#RT 5 : 직전값 테스트\n"));
				}
				m_dataBuf[repeat].t_ringDown = ringDown;
				m_dataBuf[repeat].t_levelOne = levelOne;
				memcpy(m_dataBuf[repeat].t_strres, strres, sizeof(strres));			// data 저장
				//m_stDraw.setPulseData(&strres[DATA_START_POSITION]);
			}
			else										// Data 가 이상한 경우.
			{
				readFailFlag++;
			}
		}
#ifdef MAKE_SAMPLE_FILE
		sampleCreate.Open(_T("sample.bin"), CFile::modeCreate | CFile::modeWrite);
		sampleCreate.Write(strres, sizeof(strres));
		sampleCreate.Close();
#endif
		if(readFailFlag < 3)					// FAIL 이 3번 미만
		{
			m_bPass = TRUE;
			for(int check = 0; check < 5; check++)
			{
				if(dataFailed[check] >= 3)
				{
					signalWindow[check + 1].setColor = SET_RED;
					MainSignal->setColor = SET_RED;
					m_bPass = FALSE;
				}
			}

			if(m_bPass)
			{
				for(int pos = 1; pos < SIGNAL_COUNT - 1; pos++)
				{
					signalWindow[pos].setColor = SET_GREEN;
					MainSignal->setColor = SET_GREEN;
				}

				for(int rep = 0; rep < MAX_REPEAT_PER_TEST; rep++)
				{
					if(m_dataBuf[rep].t_pass = TRUE)
					{
						ringDown = m_dataBuf[rep].t_ringDown;
						levelOne = m_dataBuf[rep].t_levelOne;
						m_stDraw.setPulseData(&(m_dataBuf[rep].t_strres[DATA_START_POSITION]));
						break;
					}
				}
				if(rep == MAX_REPEAT_PER_TEST)				// 다 돌았는데 다 FALSE인 경우 가장 Fail 이 적은 것으로..
				{
					int minFailedBufPos = 0;
					for(rep = 0; rep < MAX_REPEAT_PER_TEST; rep++)
					{
						if(m_dataBuf[minFailedBufPos].t_failCount >= m_dataBuf[rep].t_failCount)
							minFailedBufPos = rep;
					}
					ringDown = m_dataBuf[minFailedBufPos].t_ringDown;
					levelOne = m_dataBuf[minFailedBufPos].t_levelOne;
					m_stDraw.setPulseData(&(m_dataBuf[minFailedBufPos].t_strres[DATA_START_POSITION]));
				}

				m_iRingingSuccess++;
			}
			else
			{
				int maxFailedBufPos = 0;
				for(int repMax = 0; repMax < MAX_REPEAT_PER_TEST; repMax++)
				{
					if(m_dataBuf[maxFailedBufPos].t_failCount <= m_dataBuf[repMax].t_failCount)
						maxFailedBufPos = repMax;
				}
				ringDown = m_dataBuf[maxFailedBufPos].t_ringDown;
				levelOne = m_dataBuf[maxFailedBufPos].t_levelOne;
				m_stDraw.setPulseData(&(m_dataBuf[maxFailedBufPos].t_strres[DATA_START_POSITION]));

				m_iRingingFail++;
			}

			x1 = (double)ringDown * 0.002;
			x2 = (double)levelOne * 0.002;
			diff = x2 - x1;
			dispData.Format(RINGING_OUTPUT, x1, x2, diff);

			MainSignal->SetString(dispData);
			SetLogData(m_UserName, m_iRingingSuccess, m_iRingingFail, STR_RINGING, x1, x2, diff, 0, m_bPass, dataFailed);

			m_stDraw.Invalidate();
			m_stDraw.UpdateWindow();

			for(int sig = 0; sig < SIGNAL_COUNT; sig++)
			{
				signalWindow[sig].Invalidate();
				signalWindow[sig].UpdateWindow();
			}
		}

#else		// USE_RANDOM_DATA
	SignalReset();
	resetBuffer();
	if(1)
	{
		for(int ran = 0; ran < 15; ran++)
		{
			dataFailed[ran % 5] += rand() % 2;
		}

		m_bPass = TRUE;
		for(int check = 0; check < SIGNAL_COUNT; check++)
		{
			if(dataFailed[check] >= 3)
			{
				signalWindow[check + 1].setColor = SET_RED;
				MainSignal->setColor = SET_RED;
				m_bPass = FALSE;
			}
		}
		if(m_bPass)
		{
			for(int pos = 1; pos < SIGNAL_COUNT; pos++)
			{
				signalWindow[pos].setColor = SET_GREEN;
				MainSignal->setColor = SET_GREEN;
			}
			m_iRingingSuccess++;
		}
		else
		{
			m_iRingingFail++;
		}
		CString dispData;
		double	x1, x2, diff;
		x1 = (double)(rand() % 2500) * 0.002;
		x2 = (double)(rand() % 2500) * 0.002;
		diff = x2 - x1;
		dispData.Format(RINGING_OUTPUT, x1, x2, diff);

		MainSignal->SetString(dispData);

		SetLogData(m_UserName, m_iRingingSuccess, m_iRingingFail, STR_RINGING,x1, x2, diff, 0, m_bPass, dataFailed);

		for(int sig = 0; sig < SIGNAL_COUNT; sig++)
		{
			signalWindow[sig].Invalidate();
			signalWindow[sig].UpdateWindow();
		}
	}
#endif
	}
	else
	{
		RTrace(_T("Level TEST\n"));
#ifndef USE_RANDOM_DATA
		status = viClear(vi);
		if (status < VI_SUCCESS) goto error;

		status = viWrite(vi, (ViBuf)CurveCmd, (ViUInt32)strlen(CurveCmd), &actual);
		if (status < VI_SUCCESS) goto error;

		status = viScanf(vi, "%t", strres);
		if (status < VI_SUCCESS) goto error;

		m_stDraw.setPulseData(&strres[DATA_START_POSITION]);

		m_stDraw.Invalidate();
		m_stDraw.UpdateWindow();
		
		volt = (double)m_stDraw.GetCheckedLevel();
		
		m_bPass = TRUE;
		if(volt >= m_stDraw.m_levelMax || volt <= m_stDraw.m_levelMin) {
			MainSignal->setColor = SET_RED;
			m_iLevelFail++;
			m_bPass = FALSE;
		}
		else {
			MainSignal->setColor = SET_GREEN;
			m_iLevelSuccess++;
		}

		SetLogData(m_UserName, m_iLevelSuccess, m_iLevelFail, STR_LEVEL, 0, 0, 0, volt, m_bPass);
		dispData.Format(LEVEL_OUTPUT, (volt - 53) / 50);
		MainSignal->SetString(dispData);
		MainSignal->Invalidate();
		MainSignal->UpdateWindow();
#else
		CString dispData;
		double	volt = rand() % 200 + 53;

		m_bPass = TRUE;
		if(volt >= 200 || volt <= 100) {
			MainSignal->setColor = SET_RED;
			m_iLevelFail++;
			m_bPass = FALSE;
		}
		else {
			MainSignal->setColor = SET_GREEN;
			m_iLevelSuccess++;
		}

		SetLogData(m_UserName, m_iLevelSuccess, m_iLevelFail, STR_LEVEL, 0, 0, 0, volt, m_bPass);

		dispData.Format(LEVEL_OUTPUT, (volt - 53) / 50);
		MainSignal->SetString(dispData);
		MainSignal->Invalidate();
		MainSignal->UpdateWindow();
#endif
	}

#ifndef USE_RANDOM_DATA
	viClose(vi);
	viClose(defaultRM);
#endif

#endif // USE_SAMPLE_FILE

	m_btnTab1_3.EnableWindow(TRUE);
	EndWaitCursor();
	return;

error:
	// Report error and clean up
	EndWaitCursor();
	viStatusDesc(vi, status, buffer);
	//fprintf(stderr, "failure: %s\n", buffer);
	RTrace(_T("failure: %s\n"), buffer);
	if (vi != VI_NULL)			viClose(vi);
	if (defaultRM != VI_NULL)	viClose(defaultRM);
	if (wfm != NULL)			free(wfm);

	m_btnTab1_3.EnableWindow(TRUE);
	return;
}

void CPulseDisplayDlg::OnBnClickedTab1Btn4()
{
	RTrace(_T("[zest] Tab1 Button4 Clicked\n"));

	if(m_rdRTTest.GetCheck() == TRUE)
	{
		if(m_bPass == TRUE)
			m_iRingingSuccess -= 1;
		else
			m_iRingingFail -= 1;
	}
	else
	{
		if(m_bPass == TRUE)
			m_iLevelSuccess -= 1;
		else
			m_iLevelFail -= 1;
	}

	m_logFile.SeekToBegin();
	m_flushLogFile.Open(STR_TEMP_LOG, CStdioFile::modeCreate | CStdioFile::modeWrite |CStdioFile::modeNoTruncate);
	CString	data, tempData;
	while(1)
	{
		if(m_logFile.ReadString(data) == NULL){
			break;
		}
		else
		{
			if(tempData.IsEmpty() == FALSE)
				m_flushLogFile.WriteString(tempData + "\n");
		}
		tempData = data;
		RTrace(_T("%s"), data);
	}
	
    m_logFile.Close();
	m_flushLogFile.Close();

	CFile::Remove(m_strLogFileName);
	CFile::Rename(STR_TEMP_LOG, m_strLogFileName);

	m_logFile.Open(m_strLogFileName, CStdioFile::modeReadWrite |CStdioFile::modeNoTruncate);
	m_logFile.SeekToEnd();

	OnBnClickedTab1Btn3();
	// 현재의 Log 에서 -1 하고 난 다음에 다시 Btn3 수행
}

int CPulseDisplayDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_stDraw.Create(_T("DrawPlace"), WS_CHILD | WS_THICKFRAME, CRect(0, 0, 0, 0), this, IDC_TAB1_DRAW_MAIN);
	m_stDraw.ShowWindow(SW_SHOW);

	return 0;
}

void CPulseDisplayDlg::SetTAB1Disp(void)
{
	CRect	winRect, tabRect;
	::GetClientRect(this->GetSafeHwnd(), &winRect);		
	m_ctlTabMain.MoveWindow(0, 0, winRect.right, (int)((double)winRect.Height() * (double)TAB_WND_RATIO));
	m_ctlTabMain.GetClientRect(&tabRect);

	if(m_btnTab1_1) {
		m_btnTab1_1.SetWindowText(_T(TAB1_BTN1_NAME));
		m_btnTab1_1.MoveWindow(&CRect(INTAB_BTN_START_X, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 0, \
			BUTTON_WIDTH, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 0 + BUTTON_HEIGHT), TRUE);
	}
	if(m_btnTab1_2) {
		m_btnTab1_2.SetWindowText(_T(TAB1_BTN2_NAME));
		m_btnTab1_2.MoveWindow(&CRect(INTAB_BTN_START_X, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 1, \
			BUTTON_WIDTH, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 1 + BUTTON_HEIGHT), TRUE);
	}
	if(m_btnTab1_3) {
		m_btnTab1_3.SetWindowText(_T(TAB1_BTN3_NAME));
		m_btnTab1_3.MoveWindow(&CRect(INTAB_BTN_START_X, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 2, \
			BUTTON_WIDTH, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 2 + BUTTON_HEIGHT), TRUE);
	}
	if(m_btnTab1_4)	{
		m_btnTab1_4.SetWindowText(_T(TAB1_BTN4_NAME));
		m_btnTab1_4.MoveWindow(&CRect(INTAB_BTN_START_X, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 3, \
			BUTTON_WIDTH, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 3 + BUTTON_HEIGHT), TRUE);
	}
	if(m_rdRTTest) {
		m_rdRTTest.SetButtonStyle(m_rdRTTest.GetStyle() | WS_EX_TRANSPARENT);
		m_rdRTTest.SetWindowText(_T(RT_TEST));
		m_rdRTTest.MoveWindow(&CRect(INTAB_BTN_START_X, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 4, \
			BUTTON_WIDTH, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 4 + (BUTTON_HEIGHT / 2)), TRUE);
		m_rdRTTest.SetCheck(TRUE);
	}
	if(m_rdLevelTest) {
		m_rdLevelTest.SetButtonStyle(m_rdLevelTest.GetStyle() | WS_EX_TRANSPARENT);
		m_rdLevelTest.SetWindowText(_T(LEVEL_TEST));
		m_rdLevelTest.MoveWindow(&CRect(INTAB_BTN_START_X, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 4 + (BUTTON_HEIGHT / 2), \
			BUTTON_WIDTH, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 4 + (BUTTON_HEIGHT)), TRUE);
		m_rdLevelTest.SetCheck(FALSE);
	}

	if(m_stLog) {
		int	fontHeight = 25;
		m_font.DeleteObject();//Detach();
		m_font.CreateFont(fontHeight, 0, 0, 0, 0, FALSE, FALSE, 0,
			DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Tahoma"));
		//m_font.CreatePointFont(fontHeight, "Verdana");
		
		m_stLog.SetFont(&m_font);
		m_stLog.MoveWindow(&CRect(INTAB_BTN_START_X, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 5, \
			BUTTON_WIDTH, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 5 + (fontHeight * 4)));
		SetLogData(m_UserName, m_iRingingSuccess, m_iRingingFail);
	}

	if(m_stDraw) {
		m_stDraw.MoveWindow(&CRect(INTAB_BTN_START_X + BUTTON_WIDTH, INTAB_BTN_START_Y, tabRect.right - 5, tabRect.bottom - DEVNAME_HEIGHT + 1));
	}

	if(m_picLogo) {
		m_picLogo.MoveWindow(&CRect(INTAB_BTN_START_X, tabRect.bottom - 100 - 5, \
			INTAB_BTN_START_X + BUTTON_WIDTH, tabRect.bottom - 5));
	}

	if(m_stDevName)	{
		m_stDevName.SetWindowText(_T(TAB1_ST_DEVICE_NAME));
		m_stDevName.ModifyStyle(NULL, SS_CENTERIMAGE, NULL);
		m_stDevName.MoveWindow(&CRect(INTAB_BTN_START_X + BUTTON_WIDTH, tabRect.bottom - DEVNAME_HEIGHT, tabRect.right - 5, tabRect.bottom), TRUE);
	}

	int Pos_x = (winRect.Width() / SIGNAL_COUNT);
	int Pos_y = (int)((double)winRect.Height() * (double)TAB_WND_RATIO);

	for(int sigCount = 0; sigCount < SIGNAL_COUNT; sigCount++)
	{
		signalWindow[sigCount].Create(_T("ERROR_1"), WS_CHILD | WS_THICKFRAME, CRect(Pos_x * sigCount, Pos_y, Pos_x * (sigCount + 1) - 1, winRect.Height()), this, IDC_SIGNAL_1 + sigCount);
		signalWindow[sigCount].ShowWindow(SW_SHOW);
	}

	MainSignal = &signalWindow[0];
	MainSignal->SetText(TRUE);							// MAIN SIGNAL 글씨 셋팅
	CString dispData;
	dispData.Format(RINGING_OUTPUT, 0, 0, 0);
	MainSignal->SetString(dispData);

	signalWindow[SIGNAL_COUNT - 1].ShowWindow(SW_HIDE);

	int sigNum, sigBmpID;

	for(sigNum = 1, sigBmpID = IDB_FIRST_ERR; sigNum < SIGNAL_COUNT; sigNum++)
	{
		signalWindow[sigNum].SetFailBmp(sigBmpID++);
		signalWindow[sigNum].SetOKBmp(sigBmpID++);
	}
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

void CPulseDisplayDlg::OnBnClickedRtTest()
{
	CString dispData;

	BeginWaitCursor();
	if(m_ringdownSetCmd.IsEmpty() == FALSE)
	{
		ViStatus status;
		unsigned long actual;

		status = viOpenDefaultRM(&defaultRM);
		if (status < VI_SUCCESS) goto error;

		status = viOpen(defaultRM, GetDeviceDesc(), VI_NULL, VI_NULL, &vi);
		if (status < VI_SUCCESS) goto error;

		status = viWrite(vi, (ViBuf)m_ringdownSetCmd.GetBuffer(m_ringdownSetCmd.GetLength()), m_ringdownSetCmd.GetLength(), &actual);
		if (status < VI_SUCCESS) goto error;

		viClose(vi);
		viClose(defaultRM);
	}

	Sleep(1000);
	m_rdLevelTest.SetCheck(FALSE);
	m_rdRTTest.SetCheck(TRUE);

	SignalReset();
	dispData.Format(RINGING_OUTPUT, 0, 0, 0);
	MainSignal->SetString(dispData);
	SetLogData(m_UserName, m_iRingingSuccess, m_iRingingFail);
	MainSignal->Invalidate();
	MainSignal->UpdateWindow();
	
	EndWaitCursor();
	return;
error:
	EndWaitCursor();
	if (vi != VI_NULL)			viClose(vi);
	if (defaultRM != VI_NULL)	viClose(defaultRM);
	return;
}

void CPulseDisplayDlg::OnBnClickedLevelTest()
{
	CString dispData;

	BeginWaitCursor();
	if(m_levelSetCmd.IsEmpty() == FALSE)
	{
		ViStatus status;
		unsigned long actual;

		status = viOpenDefaultRM(&defaultRM);
		if (status < VI_SUCCESS) goto error;

		status = viOpen(defaultRM, GetDeviceDesc(), VI_NULL, VI_NULL, &vi);
		if (status < VI_SUCCESS) goto error;

		status = viWrite(vi, (ViBuf)m_levelSetCmd.GetBuffer(m_levelSetCmd.GetLength()), m_levelSetCmd.GetLength(), &actual);
		if (status < VI_SUCCESS) goto error;

		viClose(vi);
		viClose(defaultRM);
	}

	Sleep(1000);
	m_rdRTTest.SetCheck(FALSE);
	m_rdLevelTest.SetCheck(TRUE);

	SignalReset();
	dispData.Format(LEVEL_OUTPUT, 0);
	MainSignal->SetString(dispData);
	SetLogData(m_UserName, m_iLevelSuccess, m_iLevelFail);
	MainSignal->Invalidate();
	MainSignal->UpdateWindow();
	
	EndWaitCursor();
	return;

error:
	EndWaitCursor();
	if (vi != VI_NULL)			viClose(vi);
	if (defaultRM != VI_NULL)	viClose(defaultRM);
	return;
}

int CPulseDisplayDlg::CheckRingdownPosition(unsigned char* data)
{
	int flag = 0, pos = 0;

	for(pos = m_iPreRingdownStart; pos < m_iPreRingdownEnd; pos++) {
		if(data[pos - 70] - data[pos] >= 3) {
			flag++;
			if(flag > 2)
				return pos;
		}
		else {
			flag = 0;
		}
	}

	return 0;
}

int CPulseDisplayDlg::CheckLevelOnePosition(unsigned char* data)
{
	int pos = 0;

	for(pos = m_iPreRingdownStart; pos < m_iPreRingdownEnd; pos++)
	{
		if(data[pos] <= m_standard_1volt)				// 1Volt
			return pos;
	}
	
	return 0;
}

bool CPulseDisplayDlg::Check16Value(unsigned char* data, int ringingPoint, int LevelOnePoint)
{
	int pos = ringingPoint;

	for(pos; pos < LevelOnePoint + 200; pos++)
	{
		if(data[pos] >= (data[pos - 16] + 10))
		{
			RTrace(_T("현재 Data = %d, 16개전 Data = %d"), data[pos], data[pos - 16]);
			return false;
		}
	}

	return true;
}

bool CPulseDisplayDlg::CheckBeforeValue(unsigned char* data, int ringingPoint, int LevelOnePoint)
{
	int pos = ringingPoint;

	for(pos; pos < LevelOnePoint; pos++)
	{
		if(data[pos] >= (data[pos - 1] + 2))
		{
			RTrace(_T("현재 Data = %d, 직전 Data = %d"), data[pos], data[pos - 1]);
			return false;
		}
	}

	return true;
}

void CPulseDisplayDlg::SignalReset(void)
{
    int i = 0;
    
	for(i = 0; i < SIGNAL_COUNT; i++) {
		signalWindow[i].setColor = SET_NONE;
		signalWindow[i].Invalidate();
		signalWindow[i].UpdateWindow();
	}

}

void CPulseDisplayDlg::SetLogData(CString name, int succCount, int failCount, CString testKind, double x1_data , double x2_data , double diff_data , double volt_data , BOOL bPass, char failDetail[5])
{
	CString winText;
	CString	logText;
	CTime CurTime;
	CurTime = CTime::GetCurrentTime(); // 현재 시스템 시각을 구한다.

	winText.Format("%s\n%s%4d\n%s%4d\n%s%4d", name, STR_SUCCESS, succCount, STR_FAIL, failCount, STR_TOTAL, succCount + failCount);
	m_stLog.SetWindowText(winText);

	if(testKind.GetLength() != 0)
	{
		// _T("%s,%4d-%02d-%02d,%02d:%02d:%02d,%s,%0.4f,%0.4f,%0.4f,%0.2f,%s,%s,%s,%s,%s,%s\n")
		logText.Format(RESULT_FORMAT, \
			name, 
			CurTime.GetYear(), CurTime.GetMonth(), CurTime.GetDay(), 
			CurTime.GetHour(), CurTime.GetMinute(), CurTime.GetSecond(),
			testKind,
			x1_data,
			x2_data,
			diff_data,
			volt_data,
			(bPass == TRUE) ? "Pass" : "Fail",
			(failDetail[0] >= 3) ? "#1" : "0",
			(failDetail[1] >= 3) ? "#2" : "0",
			(failDetail[2] >= 3) ? "#3" : "0",
			(failDetail[3] >= 3) ? "#4" : "0",
			(failDetail[4] >= 3) ? "#5" : "0");

		m_logFile.SeekToEnd();
		m_logFile.WriteString(logText);
	}
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
