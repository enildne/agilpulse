// DrawRect.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PulseDisplay.h"
#include "DrawRect.h"
#include ".\drawrect.h"


// CDrawRect

IMPLEMENT_DYNAMIC(CDrawRect, CStatic)
CDrawRect::CDrawRect() :
m_bLoading(FALSE),
m_dMinVal(0),
m_dMaxVal(0)
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

	return 0;
}

void CDrawRect::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.

	CRect	drawRect;
	GetClientRect(&drawRect);
	dc.Rectangle(&drawRect);

	//VALUE_COUNT
	CStdioFile		dataFile;
	CString			data[VALUE_COUNT + 1];
	CString			time, val;
	int				i = 0, rectHeight = 0, rectWidth = 0, zeroHeight = 0, interval = 0, x_pos = 0, y_pos = 0;
	double			height = 0;

	/*---------------- GRID DRAW ----------------------*/
	CPen	*pOldPen, myDotPen, mySolidPen;
	int		gridLine = 0;

	mySolidPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	myDotPen.CreatePen(PS_DOT, 1, RGB(0, 0, 255));
	pOldPen = (CPen*)dc.SelectObject(&myDotPen);

	for(gridLine = 1; gridLine < VERTICAL_GRID_COUNT; gridLine++)
	{
		// �߾� ���ߴ� �κ�
		//if(gridLine * 2 == VERTICAL_GRID_COUNT)
		//	dc.SelectObject(&mySolidPen);
		//else
		//	dc.SelectObject(&myDotPen);

		dc.MoveTo(DRAW_LEFT_PAD, drawRect.Height() / VERTICAL_GRID_COUNT * gridLine);
		dc.LineTo( drawRect.Width() - DRAW_RIGHT_PAD, drawRect.Height() / VERTICAL_GRID_COUNT * gridLine);
	}
	for(gridLine = 1; gridLine < HORIZONTAL_GRID_COUNT; gridLine++)
	{
		// �߾� ���ߴ� �κ�
		//if(gridLine * 2 == HORIZONTAL_GRID_COUNT)
		//	dc.SelectObject(&mySolidPen);
		//else
		//	dc.SelectObject(&myDotPen);

		dc.MoveTo(drawRect.Width() / HORIZONTAL_GRID_COUNT * gridLine, DRAW_LEFT_PAD);
		dc.LineTo(drawRect.Width() / HORIZONTAL_GRID_COUNT * gridLine, drawRect.Height() - DRAW_BOTTOM_PAD);
	}
	dc.SelectObject(pOldPen);
	myDotPen.DeleteObject();
	mySolidPen.DeleteObject();
	/*---------------- GRID DRAW END ----------------------*/

	if(m_bLoading == FALSE)
		return ;

	height = m_dMaxVal - m_dMinVal; 

	/*----------------- Check Min/Max -----------------*/

	/*----------------- Graph Draw -----------------*/
	CPen	graphPen;
	graphPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	pOldPen = dc.SelectObject(&graphPen);

	rectHeight = drawRect.Height() - (DRAW_TOP_PAD + DRAW_BOTTOM_PAD);
	rectWidth = drawRect.Width() - (DRAW_LEFT_PAD + DRAW_RIGHT_PAD);
	
	// 0 ���� �׸��� ��ƾ. ����� �ʿ� ����.
	//dc.MoveTo(DRAW_LEFT_PAD, (int)((double)rectHeight * (m_dMaxVal / height) + DRAW_TOP_PAD));
	//dc.LineTo(rectWidth, (int)((double)rectHeight * (m_dMaxVal / height) + DRAW_TOP_PAD));
	
	zeroHeight = (int)((double)rectHeight * (m_dMaxVal / height) + DRAW_TOP_PAD);

	dc.MoveTo(DRAW_LEFT_PAD, zeroHeight - (int)((double)rectHeight * (m_dconvData[0] / height)));

	interval = VALUE_COUNT / rectWidth;
	x_pos = DRAW_LEFT_PAD;

	BOOL illegalRect = FALSE;

	for(i = interval; i < VALUE_COUNT; i = i + interval)
	{
		if(x_pos > rectWidth + DRAW_LEFT_PAD) 
			break;
		
		y_pos = zeroHeight - (int)((double)rectHeight * (m_dconvData[i] / height));
		
		if(y_pos < drawRect.top + DRAW_TOP_PAD) {
			if(illegalRect == FALSE)
				dc.LineTo(x_pos, drawRect.top + DRAW_TOP_PAD);
			dc.MoveTo(x_pos++, y_pos);
			illegalRect = TRUE;
		}
		else if(y_pos > drawRect.bottom - DRAW_BOTTOM_PAD) {
			if(illegalRect == FALSE)
				dc.LineTo(x_pos, drawRect.bottom - DRAW_BOTTOM_PAD);
			dc.MoveTo(x_pos++, y_pos);
			illegalRect = TRUE;
		}
		else{
			illegalRect = FALSE;
			dc.LineTo(x_pos++, y_pos);
		}
	}

	dc.SelectObject(pOldPen);
	graphPen.DeleteObject();
	/*----------------- Graph Draw END -----------------*/
}

void CDrawRect::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CStatic::OnShowWindow(bShow, nStatus);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

void CDrawRect::setPulseData(unsigned char* data)
{
	setGraphDraw(TRUE);
	m_dMaxVal = MAX_GRAPH_VALUE;
	m_dMinVal = MIN_GRAPH_VALUE;
	for(int i = 0; i < VALUE_COUNT; i++)
	{
		m_dconvData[i] = data[i];
	}
}
