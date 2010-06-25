// Signal.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "Signal.h"
#include ".\signal.h"


// CSignal

IMPLEMENT_DYNAMIC(CSignal, CStatic)
CSignal::CSignal() :
setColor(0)
{
}

CSignal::~CSignal()
{
}


BEGIN_MESSAGE_MAP(CSignal, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CSignal 메시지 처리기입니다.


void CSignal::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.

	CRect	rect;
	GetClientRect(&rect);

	if(setColor == SET_NONE)
	{
		CBrush brush;
		brush.CreateSolidBrush( RGB(255, 255,255));
		CBrush* oldBrush = dc.SelectObject( &brush );
		dc.Ellipse( 30, 10, rect.right - 30, rect.bottom - 150);
		dc.SelectObject( oldBrush );
		brush.DeleteObject();
	}
	else if(setColor == SET_RED)
	{
		CBrush brush;
		brush.CreateSolidBrush( RGB(255, 0, 0));
		CBrush* oldBrush = dc.SelectObject( &brush );
		dc.Ellipse( 30, 10, rect.right - 30, rect.bottom - 150);
		dc.SelectObject( oldBrush );
		brush.DeleteObject();
	}
	else
	{
		CBrush brush;
		brush.CreateSolidBrush( RGB(0, 255, 0));
		CBrush* oldBrush = dc.SelectObject( &brush );
		dc.Ellipse( 30, 10, rect.right - 30, rect.bottom - 150);
		dc.SelectObject( oldBrush );
		brush.DeleteObject();
	}
}
