#pragma once


// CDrawRect

class CDrawRect : public CStatic
{
	DECLARE_DYNAMIC(CDrawRect)

public:
	CDrawRect();
	virtual ~CDrawRect();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};


