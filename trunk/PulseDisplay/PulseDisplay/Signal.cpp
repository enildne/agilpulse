// Signal.cpp : ���� �����Դϴ�.
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



// CSignal �޽��� ó�����Դϴ�.


void CSignal::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.

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
