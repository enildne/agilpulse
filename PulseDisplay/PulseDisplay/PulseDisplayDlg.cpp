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
	: CDialog(CPulseDisplayDlg::IDD, pParent)
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
	//DDX_Control(pDX, IDC_TAB1_DRAW, m_stDraw1);
	DDX_Control(pDX, IDC_DEVICE_NAME, m_stDevName);
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
	while(loginDlg.DoModal() != IDOK)
	{
		AfxMessageBox(INVALID_USER);
	}
	// 로그인 화면 종료
#endif

#ifdef SCREEN_MAX
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
#ifdef SCREEN_MAX
	m_ctlTabMain.SetItemSize(CSize(cy / 4 - 5));
#else
	m_ctlTabMain.SetItemSize(CSize(MAIN_DLG_WIDTH / 4 - 5));
#endif

	m_modelName.Empty();				// 모델이름 초기화

	SetTAB1Disp();

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
		m_btnTab1_1.ShowWindow(SW_SHOW);
		m_btnTab1_2.ShowWindow(SW_SHOW);
		m_btnTab1_3.ShowWindow(SW_SHOW);
		m_btnTab1_4.ShowWindow(SW_SHOW);
		m_stDevName.ShowWindow(SW_SHOW);
		m_stDraw.ShowWindow(SW_SHOW);
		break;
	
	case 1:
		m_btnTab1_1.ShowWindow(SW_HIDE);
		m_btnTab1_2.ShowWindow(SW_HIDE);
		m_btnTab1_3.ShowWindow(SW_HIDE);
		m_btnTab1_4.ShowWindow(SW_HIDE);
		m_stDevName.ShowWindow(SW_HIDE);
		m_stDraw.ShowWindow(SW_HIDE);
		break;
	case 2:
		m_btnTab1_1.ShowWindow(SW_HIDE);
		m_btnTab1_2.ShowWindow(SW_HIDE);
		m_btnTab1_3.ShowWindow(SW_HIDE);
		m_btnTab1_4.ShowWindow(SW_HIDE);
		m_stDevName.ShowWindow(SW_HIDE);
		m_stDraw.ShowWindow(SW_HIDE);
		break;
	case 3:
		m_btnTab1_1.ShowWindow(SW_HIDE);
		m_btnTab1_2.ShowWindow(SW_HIDE);
		m_btnTab1_3.ShowWindow(SW_HIDE);
		m_btnTab1_4.ShowWindow(SW_HIDE);
		m_stDevName.ShowWindow(SW_HIDE);
		m_stDraw.ShowWindow(SW_HIDE);
		break;

	}

}

void CPulseDisplayDlg::OnBnClickedTab1Btn1()
{
	CDevList	devList(this);
	if(devList.DoModal() == IDOK) {
		m_modelName = devList.GetDevice();
		m_stDevName.SetWindowText(CString(_T(" Device : ")) + m_modelName);
	}
	else {
		AfxMessageBox(NOTSELECT_DEVICE);
	}
}

void CPulseDisplayDlg::OnBnClickedTab1Btn2()
{
#ifndef _DEBUG					// 개발 시에는 Device 가 붙지 않아도 창이 뜰 수 있도록..
	if(m_modelName.IsEmpty() == TRUE) {
		AfxMessageBox(NOTSELECT_DEVICE);
		return;
	}
#endif

	CSetList	setList(this);
	ViStatus	status;
	CString		setCmdByFile;
	unsigned long actual;

	if(setList.DoModal() == IDOK) {
		BeginWaitCursor();
		setCmdByFile = setList.GetSettingString();

		status = viOpenDefaultRM(&defaultRM);
		if (status < VI_SUCCESS) goto error;
		status = viOpen(defaultRM, GetDeviceDesc(), VI_NULL, VI_NULL, &vi);
		if (status < VI_SUCCESS) goto error;
		status = viWrite(vi, (ViBuf)setCmdByFile.GetBuffer(setCmdByFile.GetLength()), setCmdByFile.GetLength(), &actual);
		if (status < VI_SUCCESS) goto error;
		viClose(vi);
		viClose(defaultRM);
		Sleep(1000);
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
	ViStatus status;
	ViChar buffer[256];
	double* wfm = NULL;

	//long elements, i;
	char CurveCmd[] = "CURVE?";

	BeginWaitCursor();
	// Open a default Session
	status = viOpenDefaultRM(&defaultRM);
	if (status < VI_SUCCESS) goto error;

	status = viOpen(defaultRM, GetDeviceDesc(), VI_NULL, VI_NULL, &vi);
	if (status < VI_SUCCESS) goto error;

	unsigned long actual;
	char strres [3000];
	memset(strres, NULL, sizeof(strres));
	//char com[] = ":HEADER 0;:VERBOSE ON;:SELECT:CH1 ON; CH2 OFF;:CH1:COUPLING DC; BANDWIDTH OFF; PROBE 1; SCALE 100E-2; INVERT OFF; POSITION -3;:HORIZONTAL:VIEW MAIN;:HORIZONTAL:MAIN:SCALE 2.5E-3; POSITION 1.0E-2;:TRIGGER:MAIN:TYPE EDGE;:TRIGGER:MAIN:EDGE:SOURCE CH1; COUPLING DC; SLOPE RISE;:TRIGGER:MAIN:MODE AUTO; HOLDOFF:VALUE 5.0E-7;:TRIGGER:MAIN:LEVEL 2.0E0;:DATA:ENCDG RIBINARY; DESTINATION REFA; SOURCE CH1; START 1; STOP 2500; WIDTH 2";
	//status = viWrite(vi, (ViBuf)com, strlen(com), &actual);
	//if (status < VI_SUCCESS) goto error;

	status = viClear(vi);
	if (status < VI_SUCCESS) goto error;

	status = viWrite(vi, (ViBuf)CurveCmd, (ViUInt32)strlen(CurveCmd), &actual);
	if (status < VI_SUCCESS) goto error;
	/* Read results */

	status = viBufRead(vi, (ViBuf)strres, sizeof(strres), &actual);
	if (status < VI_SUCCESS) goto error;

	/* NULL terminate the string */
	strres[actual] = '\0';
	/* Print results */
	printf("Measurement Results: %s\n", strres);
	/* Close session */

	viClose(vi); // Not needed, but makes things a bit more understandable
	viClose(defaultRM);

	return;

error:
	// Report error and clean up
	EndWaitCursor();
	viStatusDesc(vi, status, buffer);
	fprintf(stderr, "failure: %s\n", buffer);
	if (vi != VI_NULL)			viClose(vi);
	if (defaultRM != VI_NULL)	viClose(defaultRM);
	if (wfm != NULL)			free(wfm);

	return;
}

void CPulseDisplayDlg::OnBnClickedTab1Btn4()
{
	RTrace(_T("[zest] Tab1 Button4 Clicked\n"));
}

int CPulseDisplayDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	m_stDraw.Create(_T("DrawPlace"), WS_CHILD | WS_THICKFRAME, CRect(0, 0, 0, 0), this, IDC_TAB1_DRAW_MAIN);
	m_stDraw.ShowWindow(SW_SHOW);

	return 0;
}

void CPulseDisplayDlg::SetTAB1Disp(void)
{
	CRect	winRect, tabRect;
	::GetClientRect(this->GetSafeHwnd(), &winRect);		
	m_ctlTabMain.MoveWindow(0, 0, winRect.right, winRect.Height() / 8 * 7);
	m_ctlTabMain.GetClientRect(&tabRect);


	if(m_btnTab1_1) {
		m_btnTab1_1.SetWindowText(_T(TAB1_BTN1_NAME));
		m_btnTab1_1.MoveWindow(&CRect(INTAB_BTN_START_X, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 0, BUTTON_WIDTH, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 0 + BUTTON_HEIGHT), TRUE);
	}
	if(m_btnTab1_2) {
		m_btnTab1_2.SetWindowText(_T(TAB1_BTN2_NAME));
		m_btnTab1_2.MoveWindow(&CRect(INTAB_BTN_START_X, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 1, BUTTON_WIDTH, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 1 + BUTTON_HEIGHT), TRUE);
	}
	if(m_btnTab1_3) {
		m_btnTab1_3.SetWindowText(_T(TAB1_BTN3_NAME));
		m_btnTab1_3.MoveWindow(&CRect(INTAB_BTN_START_X, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 2, BUTTON_WIDTH, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 2 + BUTTON_HEIGHT), TRUE);
	}
	if(m_btnTab1_4)	{
		m_btnTab1_4.SetWindowText(_T(TAB1_BTN4_NAME));
		m_btnTab1_4.MoveWindow(&CRect(INTAB_BTN_START_X, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 3, BUTTON_WIDTH, INTAB_BTN_START_Y + (BUTTON_HEIGHT + BUTTON_GAP) * 3 + BUTTON_HEIGHT), TRUE);
	}
	
	if(m_stDraw)
		m_stDraw.MoveWindow(&CRect(INTAB_BTN_START_X + BUTTON_WIDTH, INTAB_BTN_START_Y, tabRect.right - 5, tabRect.bottom - DEVNAME_HEIGHT + 1));
	
	if(m_stDevName)	{
		m_stDevName.SetWindowText(_T(TAB1_ST_DEVICE_NAME));
		m_stDevName.ModifyStyle(NULL, SS_CENTERIMAGE, NULL);
		m_stDevName.MoveWindow(&CRect(INTAB_BTN_START_X + BUTTON_WIDTH, tabRect.bottom - DEVNAME_HEIGHT, tabRect.right - 5, tabRect.bottom), TRUE);
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

double* CPulseDisplayDlg::ReadWaveform(ViSession vi, long* elements)
{
	ViStatus status;
	//float yoffset, ymult;
	ViChar buffer[256];
	ViChar c;
	long count, i;
	double* ptr = NULL;
	unsigned char szBuff[256] = { 0,};

	ASSERT(elements != NULL);

	//status = viSetAttribute(vi,VI_ATTR_WR_BUF_OPER_MODE, VI_FLUSH_ON_ACCESS);
	//status = viSetAttribute(vi,VI_ATTR_RD_BUF_OPER_MODE, VI_FLUSH_ON_ACCESS);

	// Turn headers off, this makes parsing easier
	//status = viPrintf(vi, "header off\n");
	//if (status < VI_SUCCESS) goto error;

	// Get record length value
	//status = viQueryf(vi, "hor:reco?\n", "%ld", elements);
	//if (status < VI_SUCCESS) goto error;

	//// Make sure start, stop values for curve query match the full record length
	//status = viPrintf(vi, "data:start 1;data:stop %d\n", *elements);
	//if (status < VI_SUCCESS) goto error;

	// Get the yoffset to help calculate the vertical values.

	//status = viQueryf(vi, "WFMOutpre:YOFF?\n", "%f", &yoffset);
	//if (status < VI_SUCCESS) goto error;

	//// Get the ymult to help calculate the vertical values.
	//status = viQueryf(vi, "WFMOutpre:YMULT?\n", "%f", &ymult);
	//if (status < VI_SUCCESS) goto error;

	// Request 8bit binary data on the curve query
	status = viPrintf(vi, "DATA:ENCDG RIBINARY;WIDTH 1\n");
	if (status < VI_SUCCESS) goto error;

	// Request the curve
	status = viPrintf(vi, "CURVE?\n");
	if (status < VI_SUCCESS) goto error;

	// Always flush if a viScanf follows a viPrintf or viBufWrite.
	//status = viFlush(vi, VI_WRITE_BUF | VI_READ_BUF_DISCARD);
	//if (status < VI_SUCCESS) goto error;

	// Get first char and validate
	//status = viSetAttribute(vi,VI_ATTR_RD_BUF_OPER_MODE, VI_FLUSH_DISABLE);
	status = viScanf(vi, "%c", &c);
	if (status < VI_SUCCESS) goto error;
	ASSERT(c == '#');

	// Get width of element field.
	status = viScanf(vi, "%c", &c);
	if (status < VI_SUCCESS) goto error;
	ASSERT(c >= '0' && c <= '9');

	// Read element characters
	count = c - '0';
	for (i = 0; i < count; i++) {
		status = viScanf(vi, "%c", &c);
		if (status < VI_SUCCESS) goto error;
		ASSERT(c >= '0' && c <= '9');
	}

	// Read waveform into allocated storage
	//ptr = (double*) malloc(*elements*sizeof(double));

	//for (i = 0; i < *elements; i++) {
	//	status = viScanf(vi, "%c", &c);
	//	if (status < VI_SUCCESS) goto error;
	//	ptr[i] = (((double) c) - yoffset) * ymult;
	//}

	//status = viFlush(vi, VI_WRITE_BUF | VI_READ_BUF_DISCARD);
	//if (status < VI_SUCCESS) goto error;

	return ptr;

error:
	// Report error and clean up
	viStatusDesc(vi, status, buffer);
	fprintf(stderr, "failure: %s\n", buffer);
	if (ptr != NULL) free(ptr);
	return NULL;
}
