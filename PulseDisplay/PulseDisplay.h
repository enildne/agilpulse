// PulseDisplay.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error PCH���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����Ͻʽÿ�.
#endif

#include "resource.h"		// �� ��ȣ


// CPulseDisplayApp:
// �� Ŭ������ ������ ���ؼ��� PulseDisplay.cpp�� �����Ͻʽÿ�.
//

class CPulseDisplayApp : public CWinApp
{
public:
	CPulseDisplayApp();

// ������
	public:
	virtual BOOL InitInstance();

// ����

	DECLARE_MESSAGE_MAP()
};

extern CPulseDisplayApp theApp;
