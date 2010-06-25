// DrawRect.cpp : 구현 파일입니다.
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



// CDrawRect 메시지 처리기입니다.


int CDrawRect::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	CRect	drawRect;

	return 0;
}

void CDrawRect::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.

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

	dc.SetMapMode(MM_ANISOTROPIC);
	dc.SetWindowExt(VALUE_COUNT, MAX_INPUT_VALUE);
	dc.SetViewportExt(drawRect.Width(), drawRect.Height());

	mySolidPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	myDotPen.CreatePen(PS_DOT, 1, RGB(0, 0, 255));
	pOldPen = (CPen*)dc.SelectObject(&myDotPen);

	for(gridLine = 1; gridLine < HORIZONTAL_GRID_COUNT; gridLine++)
	{
		int vgrid_ypos = MAX_INPUT_VALUE / HORIZONTAL_GRID_COUNT * gridLine;
		dc.MoveTo(0, vgrid_ypos);
		dc.LineTo(VALUE_COUNT, vgrid_ypos);
	}
	for(gridLine = 1; gridLine < VERTICAL_GRID_COUNT; gridLine++)
	{
		int hgrid_xpos = VALUE_COUNT / VERTICAL_GRID_COUNT * gridLine;
		dc.MoveTo(hgrid_xpos, 0);
		dc.LineTo(hgrid_xpos, MAX_INPUT_VALUE);
	}
	dc.SelectObject(pOldPen);
	myDotPen.DeleteObject();
	mySolidPen.DeleteObject();

	/*---------------- GRID DRAW END ----------------------*/
	if(m_bLoading == FALSE)
		return ;

	CPen	graphPen;
	graphPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	pOldPen = dc.SelectObject(&graphPen);

	dc.MoveTo(0, MAX_INPUT_VALUE - m_dconvData[0] + 28);

	for(i = 0; i < VALUE_COUNT; i++)
	{
		dc.LineTo(i, MAX_INPUT_VALUE - m_dconvData[i] + 28);
	}

	dc.SelectObject(pOldPen);
	graphPen.DeleteObject();
	/*----------------- Graph Draw END -----------------*/

	/*----------------- 1 Volt Line ----------------*/
	CPen	Vol1LinePen;
	Vol1LinePen.CreatePen(PS_DOT, 1, RGB(255, 0, 0));
	pOldPen = dc.SelectObject(&Vol1LinePen);
	int vol_1 = 0, reverseFind =0, vol_Max;

	for(vol_1 = START_VOLTAGE_1; vol_1 < VALUE_COUNT; vol_1++)
	{
		if(m_dconvData[vol_1] <= 78)				// 1Volt
			break;
	}
	
	dc.MoveTo(vol_1, 0);
	dc.LineTo(vol_1, MAX_INPUT_VALUE);

	dc.SelectObject(pOldPen);
	Vol1LinePen.DeleteObject();

	/* ---------------- 1 Volt Line --------------*/
	/* ---------------- Down Line ------------------*/
	CPen	RingdownLinePen;
	RingdownLinePen.CreatePen(PS_DOT, 1, RGB(255, 0, 0));
	dc.SelectObject(&RingdownLinePen);

	int flag = 0;

	for(vol_Max = RINGDOWN_START; vol_Max < RINGDOWN_END; vol_Max++)
	{
		if(m_dconvData[vol_Max - 70] - m_dconvData[vol_Max] >= 3)
		{
			flag++;
			if(flag > 2)
				break;
		}
		else
		{
			flag = 0;
		}
	}

	RTrace(_T("Vol Max = %d\n"), vol_Max);

	dc.MoveTo(vol_Max, 0);
	dc.LineTo(vol_Max, MAX_INPUT_VALUE);
	dc.SelectObject(pOldPen);
	RingdownLinePen.DeleteObject();

	/* ---------------- Down Line ------------------*/
	//for(reverseFind = vol_1 - 1; reverseFind >= 0; reverseFind--)
	//{
	//	if(m_dconvData[reverseFind] + 1 < m_dconvData[reverseFind + 1])
	//		break;
	//}




	/*----------------- RingDown Start Draw End ----------------*/
}

void CDrawRect::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CStatic::OnShowWindow(bShow, nStatus);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
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
