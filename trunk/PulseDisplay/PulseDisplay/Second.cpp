// Second.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "Second.h"


// CSecond ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSecond, CPropertyPage)
CSecond::CSecond()
	: CPropertyPage(CSecond::IDD)
{
}

CSecond::~CSecond()
{
}

void CSecond::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSecond, CPropertyPage)
END_MESSAGE_MAP()


// CSecond �޽��� ó�����Դϴ�.
