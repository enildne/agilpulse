// Fourth.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "Fourth.h"


// CFourth 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFourth, CPropertyPage)
CFourth::CFourth()
	: CPropertyPage(CFourth::IDD)
{
}

CFourth::~CFourth()
{
}

void CFourth::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFourth, CPropertyPage)
END_MESSAGE_MAP()


// CFourth 메시지 처리기입니다.
