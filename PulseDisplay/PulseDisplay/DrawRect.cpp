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

	return 0;
}

void CDrawRect::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.

	CRect	drawRect;
	GetClientRect(&drawRect);

	//VALUE_COUNT
	/*----------------- Reading Value -----------------*/
	CStdioFile		dataFile;
	CString			data[VALUE_COUNT + 1];
	double			convData[VALUE_COUNT + 1][2];
	CString			time, val;
	char			*timeLine, *valueLine;
	int				i = 0;

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

			convData[i][0] = atof(timeLine);
			convData[i][1] = atof(valueLine);
			//RTrace(_T("data = %s\n"), data[i]);
			i++;
		}
	}
	/*----------------- Reading Value -----------------*/

	/*----------------- Check Min/Max -----------------*/
	double MinVal = 0, MaxVal = 0;
	for(i = 0; i < VALUE_COUNT; i++)
	{
		if(convData[i][1] != 0 && convData[i][1] < MinVal)
		{
			MinVal = convData[i][1];
		}
		if(convData[i][1] != 0 && convData[i][1] > MaxVal)
		{
			MaxVal = convData[i][1];
		}
	}
	
	double height = MaxVal - MinVal; 

	RTrace(_T("Min = %f, Max = %f, height = %f\n"), MinVal, MaxVal, height);
	/*----------------- Check Min/Max -----------------*/
	/*----------------- Graph Draw -----------------*/
	int rectHeight = drawRect.Height() - (DRAW_TOP_PAD + DRAW_BOTTOM_PAD);
	int rectWidth = drawRect.Width() - (DRAW_LEFT_PAD + DRAW_RIGHT_PAD);
	
	int zeroHeight;
	
	RTrace(_T("rectHeight = %d, rectWidth = %d\n"), rectHeight, rectWidth);

	dc.MoveTo(DRAW_LEFT_PAD, rectHeight * (MaxVal / height) + DRAW_TOP_PAD);
	dc.LineTo(rectWidth, rectHeight * (MaxVal / height) + DRAW_TOP_PAD);
	
	zeroHeight = rectHeight * (MaxVal / height) + DRAW_TOP_PAD;

	dc.MoveTo(DRAW_LEFT_PAD, zeroHeight - (rectHeight * (convData[0][1] / height)));

	int interval = VALUE_COUNT / rectWidth;
	int j = DRAW_LEFT_PAD;

	for(i = interval; i < VALUE_COUNT; i = i + interval)
	{
		if(j > rectWidth - DRAW_RIGHT_PAD)
			break;
		dc.LineTo(j++, zeroHeight - (rectHeight * (convData[i][1] / height)));
	}

	/*----------------- Graph Draw -----------------*/
}

void CDrawRect::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CStatic::OnShowWindow(bShow, nStatus);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}
