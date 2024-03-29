// SetList.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "SetList.h"
#include ".\setlist.h"


// CSetList 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSetList, CDialog)
CSetList::CSetList(CWnd* pParent /*=NULL*/)
	: CDialog(CSetList::IDD, pParent)
{
}

CSetList::~CSetList()
{
}

void CSetList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SET_LIST, m_lstSetting);
}


BEGIN_MESSAGE_MAP(CSetList, CDialog)
	ON_WM_CREATE()
	ON_LBN_DBLCLK(IDC_SET_LIST, OnLbnDblclkSetList)
END_MESSAGE_MAP()

// CSetList 메시지 처리기입니다.

BOOL CSetList::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	CRect	dlgRect;
	GetClientRect(&dlgRect);
	m_lstSetting.MoveWindow(&dlgRect);

	// 파일 목록을 찾는다.
	CFileFind finder;
	CString strWildCard("*.set");

	BOOL bWorking = finder.FindFile( strWildCard );
	while( bWorking )
	{
		bWorking = finder.FindNextFile();
		if( finder.IsDots() || finder.IsDirectory() )
			continue;  
		else
		{
			CString filePath = finder.GetFileName();
			filePath = filePath.Left(filePath.GetLength() - 4);			// 뒤의 .set 을 지우기 위해서
			m_lstSetting.AddString(filePath);
		}
	} 
	finder.Close();

	if(m_lstSetting.GetCount() == 0)
	{
		AfxMessageBox(STR_NO_SETTING_FILE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

int CSetList::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	this->MoveWindow(0, 0, SETTING_LIST_WIDTH, SETTING_LIST_HEIGHT);
	this->SetWindowText(STR_SETTING_LIST);

	return 0;
}

void CSetList::OnLbnDblclkSetList()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString		selFileName;
	CStdioFile	dataFile;

	if(m_lstSetting.GetCurSel() < 0)
		return;

	m_lstSetting.GetText(m_lstSetting.GetCurSel(), selFileName);
	selFileName = selFileName + _T(".set");

	dataFile.Open(selFileName, CFile::modeRead | CFile::typeText);
	if(dataFile != NULL)
	{
		dataFile.ReadString(m_setDefaultString);		// Default Setting	
		dataFile.ReadString(m_setRingdownString);		// Ringdown Setting
		dataFile.ReadString(m_setLevelString);			// Level Setting
		dataFile.ReadString(m_Standard_Volt);			// 기준 1볼트
		dataFile.ReadString(m_voltTestStartPosition);	// Volt 1 check start position
		dataFile.ReadString(m_voltTestEndPosition);			// Volt 1 check end position
		dataFile.ReadString(m_rtTestLowPosition);
		dataFile.ReadString(m_rtTestLowLimit);
		dataFile.ReadString(m_rtTestHighPosition);
		dataFile.ReadString(m_rtTestHighLimit);
		dataFile.ReadString(m_test1Min);		 
		dataFile.ReadString(m_test1Max);		 
		dataFile.ReadString(m_test2Min);		 
		dataFile.ReadString(m_test2Max);		 
		dataFile.ReadString(m_testDiff);		 
		dataFile.ReadString(m_levelTestRangeMin);
		dataFile.ReadString(m_levelTestRangeMax);
		dataFile.ReadString(m_levelTestLevelMin);
		dataFile.ReadString(m_levelTestLevelMax);
		dataFile.Close();
	}

	OnOK();
}
