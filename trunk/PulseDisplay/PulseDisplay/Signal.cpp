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

	int circlePosition_x = rect.Width() / 4;
	int circlePosition_y = 10;
	int circlePosition_cx = (rect.Width() / 4) * 3;
	int circlePosition_cy = circlePosition_y + (rect.Width() / 4) * 2 ;

	int text_x = 5;
	int text_y = circlePosition_cy + 5;
	int text_cx = rect.Width() - text_x;
	int text_cy = text_y + 30;

	if(setColor == SET_NONE)
	{
		CBrush brush;
		brush.CreateSolidBrush( RGB(255, 255,255));
		CBrush* oldBrush = dc.SelectObject( &brush );
		dc.Ellipse( circlePosition_x, circlePosition_y, circlePosition_cx, circlePosition_cy);
		dc.SelectObject( oldBrush );
		brush.DeleteObject();
		
		dc.TextOut(text_x, text_y, m_String);
	}
	else if(setColor == SET_RED)
	{
		CBrush brush;
		brush.CreateSolidBrush( RGB(255, 0, 0));
		CBrush* oldBrush = dc.SelectObject( &brush );
		dc.Ellipse( circlePosition_x, circlePosition_y, circlePosition_cx, circlePosition_cy);
		dc.SelectObject( oldBrush );
		brush.DeleteObject();
		dc.TextOut(text_x, text_y, m_String);
	}
	else
	{
		CBrush brush;
		brush.CreateSolidBrush( RGB(0, 255, 0));
		CBrush* oldBrush = dc.SelectObject( &brush );
		dc.Ellipse( circlePosition_x, circlePosition_y, circlePosition_cx, circlePosition_cy);
		dc.SelectObject( oldBrush );
		brush.DeleteObject();
		dc.TextOut(text_x, text_y, m_String);
	}
}
