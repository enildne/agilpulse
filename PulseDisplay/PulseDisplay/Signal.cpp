// Signal.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "Signal.h"
#include ".\signal.h"


// CSignal

IMPLEMENT_DYNAMIC(CSignal, CStatic)
CSignal::CSignal() :
setColor(0),
m_bSetText(FALSE)
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

	dc.FillRect(rect, WHITE_BRUSH);

	int circlePosition_x = rect.Width() / 4;
	int circlePosition_y = 10;
	int circlePosition_cx = (rect.Width() / 4) * 3;
	int circlePosition_cy = circlePosition_y + (rect.Width() / 4) * 2 ;

	int bmp_x = rect.left + 2;
	int bmp_y = circlePosition_cy + 2;
	int bmp_cx = rect.Width() - 4;
	int bmp_cy = rect.Height() - circlePosition_cy - 4;

	int text_x = 5;
	int text_y = circlePosition_cy + 5;
	int text_cx = rect.Width() - text_x;
	int text_cy = rect.Height() - 5;

	if(setColor == SET_NONE)
	{
		HDC MemDC;
		HBITMAP OldBitmap;
		BITMAP bit;
		CBitmap m_hBitmap;
		int bx, by;
		CBrush brush;
		CBrush* oldBrush;

		brush.CreateSolidBrush( RGB(255, 255,255));
		oldBrush = dc.SelectObject( &brush );
		dc.Ellipse( circlePosition_x, circlePosition_y, circlePosition_cx, circlePosition_cy);
		dc.SelectObject( oldBrush );
		brush.DeleteObject();
		
		m_hBitmap.LoadBitmap(MAKEINTRESOURCE(m_IDBmp_OK));
		MemDC=::CreateCompatibleDC(dc);
		OldBitmap=(HBITMAP)::SelectObject(MemDC, m_hBitmap);
		::GetObject(m_hBitmap, sizeof(BITMAP), &bit);
		bx=bit.bmWidth;
		by=bit.bmHeight;
		::TransparentBlt(dc, bmp_x, bmp_y, bmp_cx, bmp_cy, MemDC, 0, 0, bx, by, RGB(0,0,0));
		::SelectObject(MemDC, OldBitmap);
		m_hBitmap.DeleteObject();
	}
	else if(setColor == SET_RED)
	{
		HDC MemDC;
		HBITMAP OldBitmap;
		BITMAP bit;
		CBitmap m_hBitmap;
		int bx, by;
		CBrush brush;
		CBrush* oldBrush;

		brush.CreateSolidBrush( RGB(255, 0, 0));
		oldBrush = dc.SelectObject( &brush );
		dc.Ellipse( circlePosition_x, circlePosition_y, circlePosition_cx, circlePosition_cy);
		dc.SelectObject( oldBrush );
		brush.DeleteObject();

		m_hBitmap.LoadBitmap(MAKEINTRESOURCE(m_IDBmp_Fail));
		MemDC=::CreateCompatibleDC(dc);
		OldBitmap=(HBITMAP)::SelectObject(MemDC, m_hBitmap);
		::GetObject(m_hBitmap, sizeof(BITMAP), &bit);
		bx=bit.bmWidth;
		by=bit.bmHeight;
		::TransparentBlt(dc, bmp_x, bmp_y, bmp_cx, bmp_cy, MemDC, 0, 0, bx, by, RGB(0,0,0));
		::SelectObject(MemDC, OldBitmap);
		m_hBitmap.DeleteObject();
	}
	else if(setColor == SET_GREEN)
	{
		HDC MemDC;
		HBITMAP OldBitmap;
		BITMAP bit;
		CBitmap m_hBitmap;
		int bx, by;
		CBrush brush;
		CBrush* oldBrush;

		brush.CreateSolidBrush( RGB(0, 255, 0));
		oldBrush = dc.SelectObject( &brush );
		dc.Ellipse( circlePosition_x, circlePosition_y, circlePosition_cx, circlePosition_cy);
		dc.SelectObject( oldBrush );
		brush.DeleteObject();

		m_hBitmap.LoadBitmap(MAKEINTRESOURCE(m_IDBmp_OK));
		MemDC=::CreateCompatibleDC(dc);
		OldBitmap=(HBITMAP)::SelectObject(MemDC, m_hBitmap);
		::GetObject(m_hBitmap, sizeof(BITMAP), &bit);
		bx=bit.bmWidth;
		by=bit.bmHeight;
		::TransparentBlt(dc, bmp_x, bmp_y, bmp_cx, bmp_cy, MemDC, 0, 0, bx, by, RGB(0,0,0));
		::SelectObject(MemDC, OldBitmap);
		m_hBitmap.DeleteObject();
	}
	
	if(m_bSetText)
	{
		if(m_Font == NULL)
		{
			m_Font->DeleteObject();//Detach();
			m_Font->CreateFont(20, 0, 0, 0, 0, FALSE, FALSE, 0,
				DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Tahoma"));
			this->SetFont(m_Font);
		}
		dc.DrawText(m_String, CRect(text_x, text_y, text_cx, text_cy), DT_LEFT);
	}
}
