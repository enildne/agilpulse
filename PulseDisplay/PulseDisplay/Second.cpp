// Second.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "Second.h"


// CSecond 대화 상자입니다.

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


// CSecond 메시지 처리기입니다.
