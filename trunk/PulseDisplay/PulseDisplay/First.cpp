// First.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "First.h"


// CFirst ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFirst, CPropertyPage)
CFirst::CFirst()
	: CPropertyPage(CFirst::IDD)
{
}

CFirst::~CFirst()
{
}

void CFirst::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFirst, CPropertyPage)
END_MESSAGE_MAP()


// CFirst �޽��� ó�����Դϴ�.
