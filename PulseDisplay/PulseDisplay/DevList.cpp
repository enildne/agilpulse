// DevList.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "PulseDisplayDlg.h"
#include "DevList.h"
#include ".\devlist.h"
#include "DefineAndSize.h"

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
	ViUInt32 retCnt, itemCnt;
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
		// Send an ID query.
		status = viWrite(vi, (ViBuf) "*idn?", 5, &retCnt);
		if (status < VI_SUCCESS) goto GPIB;
		// Clear the buffer and read the response
		status = viRead(vi, (ViBuf) id, sizeof(id), &retCnt);
		id[retCnt] = '\0';
		if (status < VI_SUCCESS) goto GPIB;
		// Print the response
		//printf("id: %s: %s\n", desc, id);

		m_lstDevice.AddString(id);
		memset(id, NULL, sizeof(id));
		// We’re done with this device so close it
		viClose(vi);
		// Get the next item
		viFindNext(list, desc);
	}
	// Clean up
	viClose(rm);

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

		// Open resource found in rsrc 		
		status = viOpen(rm, desc, VI_NULL, VI_NULL, &vi);
		if (status < VI_SUCCESS) goto ASRL;
		// Send an ID query.
		status = viWrite(vi, (ViBuf) "*idn?", 5, &retCnt);
		if (status < VI_SUCCESS) goto ASRL;
		// Clear the buffer and read the response
		status = viRead(vi, (ViBuf) id, sizeof(id), &retCnt);
		id[retCnt] = '\0';
		if (status < VI_SUCCESS) goto ASRL;
		// Print the response
		//printf("id: %s: %s\n", desc, id);

		m_lstDevice.AddString(id);
		memset(id, NULL, sizeof(id));
		// We’re done with this device so close it
		viClose(vi);
		// Get the next item
		viFindNext(list, desc);
	}
	// Clean up
	viClose(rm);
#endif

ASRL:
#ifdef USE_ASRL_DEVICE
	status = viOpenDefaultRM(&rm);
	if (status < VI_SUCCESS) goto error;
	// Find all ASRL devices
	status = viFindRsrc(rm, "ASRL?*INSTR", &list, &itemCnt, desc);
	if (status < VI_SUCCESS) goto error;
	for (i = 0; i < itemCnt; i++) {
		// Open resource found in rsrc list
		status = viOpen(rm, desc, VI_NULL, VI_NULL, &vi);
		if (status < VI_SUCCESS) goto error;
		// Send an ID query.
		status = viWrite(vi, (ViBuf) "*idn?", 5, &retCnt);
		if (status < VI_SUCCESS) goto error;
		// Clear the buffer and read the response
		status = viRead(vi, (ViBuf) id, sizeof(id), &retCnt);
		id[retCnt] = '\0';
		if (status < VI_SUCCESS) goto error;
		// Print the response
		//printf("id: %s: %s\n", desc, id);

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
	m_lstDevice.GetText(m_lstDevice.GetCurSel(), selDevice);
	((CPulseDisplayDlg*)GetParent())->SetDeviceDesc(m_arrayDesc[m_lstDevice.GetCurSel()]);
	OnOK();
}
