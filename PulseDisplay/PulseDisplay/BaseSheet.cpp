// BaseSheet.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "BaseSheet.h"


// CBaseSheet

IMPLEMENT_DYNAMIC(CBaseSheet, CPropertySheet)
CBaseSheet::CBaseSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_firstPage);
	AddPage(&m_secondPage);
	AddPage(&m_thirdPage);
	AddPage(&m_fourthPage);
}

CBaseSheet::CBaseSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CBaseSheet::~CBaseSheet()
{
}


BEGIN_MESSAGE_MAP(CBaseSheet, CPropertySheet)
END_MESSAGE_MAP()


// CBaseSheet 메시지 처리기입니다.
