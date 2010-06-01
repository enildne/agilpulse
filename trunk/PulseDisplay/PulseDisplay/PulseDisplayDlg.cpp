// PulseDisplayDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "PulseDisplayDlg.h"
#include ".\pulsedisplaydlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPulseDisplayDlg ��ȭ ����



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
END_MESSAGE_MAP()


// CPulseDisplayDlg �޽��� ó����

BOOL CPulseDisplayDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	// �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	this->SetWindowPos(&CWnd::wndTopMost, 0, 0, 800, 600, SWP_NOMOVE);

	m_ctlTabMain.InsertItem(1, _T("RT"));
	m_ctlTabMain.InsertItem(2, _T("���ļ�"));
	m_ctlTabMain.InsertItem(3, _T("Reserved"));
	m_ctlTabMain.InsertItem(4, _T("Reserved"));

	return TRUE;  // ��Ʈ�ѿ� ���� ��Ŀ���� �������� ���� ��� TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸����� 
// �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
// �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CPulseDisplayDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	m_btnTab1_1.MoveWindow(&CRect(10, 10, 100, 100), TRUE);
	m_btnTab1_2.MoveWindow(&CRect(10, 110, 100, 200), TRUE);
	m_btnTab1_3.MoveWindow(&CRect(10, 210, 100, 300), TRUE);
	m_btnTab1_4.MoveWindow(&CRect(10, 310, 100, 400), TRUE);
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�. 
HCURSOR CPulseDisplayDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPulseDisplayDlg::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
	
	RTrace(_T("[zest] Select = %d\n"), m_ctlTabMain.GetCurSel());
	
	switch(m_ctlTabMain.GetCurSel())
	{
	case 0:						// ������ ��
	default:
		m_btnTab1_1.ShowWindow(SW_SHOW);
		m_btnTab1_2.ShowWindow(SW_SHOW);
		m_btnTab1_3.ShowWindow(SW_SHOW);
		m_btnTab1_4.ShowWindow(SW_SHOW);
		//m_stDraw1.ShowWindow(SW_SHOW);
		break;
	
	case 1:
		m_btnTab1_1.ShowWindow(SW_HIDE);
		m_btnTab1_2.ShowWindow(SW_HIDE);
		m_btnTab1_3.ShowWindow(SW_HIDE);
		m_btnTab1_4.ShowWindow(SW_HIDE);
		//m_stDraw1.ShowWindow(SW_HIDE);
		break;
	case 2:
		m_btnTab1_1.ShowWindow(SW_HIDE);
		m_btnTab1_2.ShowWindow(SW_HIDE);
		m_btnTab1_3.ShowWindow(SW_HIDE);
		m_btnTab1_4.ShowWindow(SW_HIDE);
		//m_stDraw1.ShowWindow(SW_HIDE);
		break;
	case 3:
		m_btnTab1_1.ShowWindow(SW_HIDE);
		m_btnTab1_2.ShowWindow(SW_HIDE);
		m_btnTab1_3.ShowWindow(SW_HIDE);
		m_btnTab1_4.ShowWindow(SW_HIDE);
		//m_stDraw1.ShowWindow(SW_HIDE);
		break;

	}

}

void CPulseDisplayDlg::OnBnClickedTab1Btn1()
{
	RTrace(_T("[zest] Tab1 Button1 Clicked\n"));
}

void CPulseDisplayDlg::OnBnClickedTab1Btn2()
{
	RTrace(_T("[zest] Tab1 Button2 Clicked\n"));
}

void CPulseDisplayDlg::OnBnClickedTab1Btn3()
{
	RTrace(_T("[zest] Tab1 Button3 Clicked\n"));
}

void CPulseDisplayDlg::OnBnClickedTab1Btn4()
{
	RTrace(_T("[zest] Tab1 Button4 Clicked\n"));
}

int CPulseDisplayDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	m_stDraw.Create(_T("Test"), WS_CHILD, CRect(100, 100, 200, 200), this, IDC_TAB1_DRAW_MAIN);
	m_stDraw.MoveWindow(&CRect(110, 10, 800, 800));
	m_stDraw.ShowWindow(SW_SHOW);

	return 0;
}
