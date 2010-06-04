// DevList.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "DevList.h"
#include ".\devlist.h"
#include "StringRc.h"

// CDevList 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDevList, CDialog)
CDevList::CDevList(CWnd* pParent /*=NULL*/)
	: CDialog(CDevList::IDD, pParent)
{
}

CDevList::~CDevList()
{
}

void CDevList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DEV_LIST, m_lstDevice);
}


BEGIN_MESSAGE_MAP(CDevList, CDialog)
	ON_WM_CREATE()
	ON_LBN_DBLCLK(IDC_DEV_LIST, OnLbnDblclkDevList)
END_MESSAGE_MAP()


// CDevList 메시지 처리기입니다.

BOOL CDevList::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

#if 0
	viFindRsrc/* Find a list of resources associated with a specified interface	2--25 */
	viFindNext /* Return the next resource from the find list 2--23 */
	viParseRsrc /* Parses a resource string to get the interface information 2--41 */
#endif

	m_lstDevice.AddString(_T("테스트 1"));
	m_lstDevice.AddString(_T("테스트 2"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

int CDevList::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	this->SetWindowText(STR_DEVICE_LIST);

	return 0;
}

void CDevList::OnLbnDblclkDevList()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_lstDevice.GetText(m_lstDevice.GetCurSel(), selDevice);

	OnOK();
}
