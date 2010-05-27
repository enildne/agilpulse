// Third.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "Third.h"


// CThird 대화 상자입니다.

IMPLEMENT_DYNAMIC(CThird, CPropertyPage)
CThird::CThird()
	: CPropertyPage(CThird::IDD)
{
}

CThird::~CThird()
{
}

void CThird::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CThird, CPropertyPage)
END_MESSAGE_MAP()


// CThird 메시지 처리기입니다.
