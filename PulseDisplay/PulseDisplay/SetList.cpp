// SetList.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "SetList.h"
#include ".\setlist.h"


// CSetList ��ȭ �����Դϴ�.

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


// CSetList �޽��� ó�����Դϴ�.

BOOL CSetList::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	CRect	dlgRect;
	GetClientRect(&dlgRect);
	m_lstSetting.MoveWindow(&dlgRect);

	// ���� ����� ã�´�.
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
			filePath = filePath.Left(filePath.GetLength() - 4);			// ���� .set �� ����� ���ؼ�
			m_lstSetting.AddString(filePath);
		}
	} 
	finder.Close();

	if(m_lstSetting.GetCount() == 0)
	{
		AfxMessageBox(STR_NO_SETTING_FILE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

int CSetList::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	this->MoveWindow(0, 0, SETTING_LIST_WIDTH, SETTING_LIST_HEIGHT);
	this->SetWindowText(STR_SETTING_LIST);

	return 0;
}

void CSetList::OnLbnDblclkSetList()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString		selFileName;
	CStdioFile	dataFile;

	if(m_lstSetting.GetCurSel() < 0)
		return;

	m_lstSetting.GetText(m_lstSetting.GetCurSel(), selFileName);
	selFileName = selFileName + _T(".set");

	dataFile.Open(selFileName, CFile::modeRead | CFile::typeText);
	if(dataFile != NULL)
	{
		dataFile.ReadString(m_setDefaultString);		// ù��(Set ���)�� �д´�
		dataFile.ReadString(m_setRingdownString);		// ù��(Set ���)�� �д´�
		dataFile.ReadString(m_setLevelString);		// ù��(Set ���)�� �д´�
		dataFile.Close();
	}

	OnOK();
}
