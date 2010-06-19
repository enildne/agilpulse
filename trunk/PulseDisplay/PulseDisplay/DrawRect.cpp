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

	//VALUE_COUNT
	/*----------------- Reading Value -----------------*/
	CStdioFile		dataFile;
	CString			data[VALUE_COUNT + 1];
	CString			time, val;
	char			*timeLine, *valueLine;
	int				i = 0, rectHeight = 0, rectWidth = 0, zeroHeight = 0, interval = 0, x_pos = 0;
	double			height = 0;

	if(m_bLoading == FALSE)				// 매번 Loading 하지 않도록..
	{
		dataFile.Open(_T("SampleData.csv"), CFile::modeRead | CFile::typeText);

		while(1)
		{
			if(!dataFile.ReadString(data[i]))
			{
				RTrace(_T("Read Finish. %d\n"), i);
				dataFile.Close();
				break;
			}
			else
			{
				time = data[i].Left(data[i].Find(','));
				val = data[i].Mid(data[i].Find(',') + 1, data[i].GetLength() - data[i].Find(',') - 2);

				timeLine = time.GetBuffer();
				valueLine = val.GetBuffer();

				m_dconvData[i][0] = atof(timeLine);
				m_dconvData[i][1] = atof(valueLine);
				//RTrace(_T("data = %s\n"), data[i]);
				i++;
			}
		}
		/*----------------- Reading Value -----------------*/

		/*----------------- Check Min/Max -----------------*/
		for(i = 0; i < VALUE_COUNT; i++)
		{
			if(m_dconvData[i][1] != 0 && m_dconvData[i][1] < m_dMinVal)
			{
				m_dMinVal = m_dconvData[i][1];
			}
			if(m_dconvData[i][1] != 0 && m_dconvData[i][1] > m_dMaxVal)
			{

				m_dMaxVal = m_dconvData[i][1];
			}
		}
	}	

	height = m_dMaxVal - m_dMinVal; 

	/*----------------- Check Min/Max -----------------*/
	/*----------------- Graph Draw -----------------*/
	rectHeight = drawRect.Height() - (DRAW_TOP_PAD + DRAW_BOTTOM_PAD);
	rectWidth = drawRect.Width() - (DRAW_LEFT_PAD + DRAW_RIGHT_PAD);
	
	dc.MoveTo(DRAW_LEFT_PAD, (int)((double)rectHeight * (m_dMaxVal / height) + DRAW_TOP_PAD));
	dc.LineTo(rectWidth, (int)((double)rectHeight * (m_dMaxVal / height) + DRAW_TOP_PAD));
	
	zeroHeight = (int)((double)rectHeight * (m_dMaxVal / height) + DRAW_TOP_PAD);

	dc.MoveTo(DRAW_LEFT_PAD, zeroHeight - (int)((double)rectHeight * (m_dconvData[0][1] / height)));

	interval = VALUE_COUNT / rectWidth;
	x_pos = DRAW_LEFT_PAD;

	for(i = interval; i < VALUE_COUNT; i = i + interval)
	{
		if(x_pos >= rectWidth) 
		{
			break;
		}
		dc.LineTo(x_pos++, zeroHeight - (int)((double)rectHeight * (m_dconvData[i][1] / height)));
	}

	/*----------------- Graph Draw -----------------*/
}

void CDrawRect::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CStatic::OnShowWindow(bShow, nStatus);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
