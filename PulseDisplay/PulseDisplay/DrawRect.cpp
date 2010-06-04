// DrawRect.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "DrawRect.h"
#include ".\drawrect.h"


// CDrawRect

IMPLEMENT_DYNAMIC(CDrawRect, CStatic)
CDrawRect::CDrawRect()
{
}

CDrawRect::~CDrawRect()
{
}


BEGIN_MESSAGE_MAP(CDrawRect, CStatic)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()



// CDrawRect �޽��� ó�����Դϴ�.


int CDrawRect::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	CRect	drawRect;

	//CDC*	pDC;

	//pDC = GetParent()->GetDC();	
	//GetClientRect(&drawRect);
	//pDC->FillRect(&drawRect, &CBrush(RGB(255,255,255)));
	//pDC->DeleteDC();

	return 0;
}

void CDrawRect::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.

	CRect	drawRect;
	GetClientRect(&drawRect);

	dc.FillRect(&drawRect, &CBrush(RGB(255,255,255)));
	dc.MoveTo(0, 0);
	dc.LineTo(drawRect.right, drawRect.bottom);
	dc.MoveTo(drawRect.right, 0);
	dc.LineTo(0, drawRect.bottom);
}

void CDrawRect::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CStatic::OnShowWindow(bShow, nStatus);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}
