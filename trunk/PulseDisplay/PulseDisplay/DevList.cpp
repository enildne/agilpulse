// DevList.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DevList.h"
#include ".\devlist.h"

// CDevList 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDevList, CDialog)
CDevList::CDevList(CWnd* pParent /*=NULL*/)
	: CDialog(CDevList::IDD, pParent)
{
	memset(m_arrayDesc, NULL, sizeof(m_arrayDesc));
	descCount = 0;
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

	CRect	dlgRect;
	GetClientRect(&dlgRect);
	m_lstDevice.MoveWindow(&dlgRect);

	ViSession rm, vi;
	ViStatus status;
	ViChar desc[256] = "", id[256] = "";
	ViUInt32 itemCnt;
	ViFindList list;
	ViUInt32 i;

	// Open a default Session
	status = viOpenDefaultRM(&rm);
	if (status < VI_SUCCESS) goto GPIB;
	// Find all USB devices
	status = viFindRsrc(rm, "USB?*INSTR", &list, &itemCnt, desc);
	if (status < VI_SUCCESS) goto GPIB;
	for (i = 0; i < itemCnt; i++) {
		// desc 구문을 전역변수에 저장
		memcpy((void*)m_arrayDesc[descCount++], (void*)desc, strlen(desc));
		// Open resource found in rsrc list
		status = viOpen(rm, desc, VI_NULL, VI_NULL, &vi);
		if (status < VI_SUCCESS) goto GPIB;
		
		status = viClear(vi);
		if (status < VI_SUCCESS) goto GPIB;
		
		status = viPrintf(vi, "*IDN?");
		if (status < VI_SUCCESS) goto GPIB;
		
		status = viScanf(vi, "%t", id);
		if (status < VI_SUCCESS) goto GPIB;
		
		m_lstDevice.AddString(id);
		memset(id, NULL, sizeof(id));
		// We’re done with this device so close it
		viClose(vi);
		// Get the next item
		viFindNext(list, desc);
	}
	// Clean up
	viClose(rm);
	Sleep(500);

GPIB:
#ifdef USE_GPIB_DEVICE
	status = viOpenDefaultRM(&rm);
	if (status < VI_SUCCESS) goto ASRL;
	// Find all GPIB devices
	status = viFindRsrc(rm, "GPIB?*INSTR", &list, &itemCnt, desc);
	if (status < VI_SUCCESS) goto ASRL;
	for (i = 0; i < itemCnt; i++) {
		// desc 구문을 전역변수에 저장
		memcpy((void*)m_arrayDesc[descCount++], (void*)desc, strlen(desc));

		status = viOpen(rm, desc, VI_NULL, VI_NULL, &vi);
		if (status < VI_SUCCESS) goto ASRL;
		
		status = viClear(vi);
		if (status < VI_SUCCESS) goto ASRL;

		status = viPrintf(vi, "*IDN?");
		if (status < VI_SUCCESS) goto ASRL;

		status = viScanf(vi, "%t", id);
		if (status < VI_SUCCESS) goto ASRL;

		m_lstDevice.AddString(id);
		memset(id, NULL, sizeof(id));
		// We’re done with this device so close it
		viClose(vi);
		// Get the next item
		viFindNext(list, desc);
	}
	// Clean up
	viClose(rm);
	Sleep(500);

ASRL:
#endif
#ifdef USE_ASRL_DEVICE
	status = viOpenDefaultRM(&rm);
	if (status < VI_SUCCESS) goto error;
	// Find all ASRL devices
	status = viFindRsrc(rm, "ASRL?*INSTR", &list, &itemCnt, desc);
	if (status < VI_SUCCESS) goto error;
	for (i = 0; i < itemCnt; i++) {
		// desc 구문을 전역변수에 저장
		memcpy((void*)m_arrayDesc[descCount++], (void*)desc, strlen(desc));

		// Open resource found in rsrc list
		status = viOpen(rm, desc, VI_NULL, VI_NULL, &vi);
		if (status < VI_SUCCESS) goto error;

		status = viClear(vi);
		if (status < VI_SUCCESS) goto error;

		status = viPrintf(vi, "*IDN?");
		if (status < VI_SUCCESS) goto error;

		status = viScanf(vi, "%t", id);
		if (status < VI_SUCCESS) goto error;

		m_lstDevice.AddString(id);
		memset(id, NULL, sizeof(id));
		// We’re done with this device so close it
		viClose(vi);
		// Get the next item
		viFindNext(list, desc);
	}
	// Clean up
	viClose(rm);
	return TRUE;
error:
#endif

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

int CDevList::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	this->MoveWindow(0, 0, DEVICE_LIST_WIDTH, DEVICE_LIST_HEIGHT);
	this->SetWindowText(STR_DEVICE_LIST);
    
	return 0;
}

void CDevList::OnLbnDblclkDevList()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(m_lstDevice.GetCurSel() < 0)
		return;

	m_lstDevice.GetText(m_lstDevice.GetCurSel(), selDevice);
	if(selDevice.IsEmpty() == FALSE)
	{
		((CPulseDisplayDlg*)GetParent())->SetDeviceDesc(m_arrayDesc[m_lstDevice.GetCurSel()]);
		OnOK();
	}
}
