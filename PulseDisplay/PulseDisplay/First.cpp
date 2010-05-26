// First.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "First.h"


// CFirst 대화 상자입니다.

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


// CFirst 메시지 처리기입니다.
