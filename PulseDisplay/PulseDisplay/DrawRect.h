#pragma once

#include "DefineAndSize.h"
// CDrawRect

class CDrawRect : public CStatic
{
	DECLARE_DYNAMIC(CDrawRect)

public:
	CDrawRect();
	virtual ~CDrawRect();

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);

	void setLoading(BOOL set) {m_bLoading = set;}

protected:
	DECLARE_MESSAGE_MAP()
	double		m_dconvData[VALUE_COUNT + 1][2];
	BOOL		m_bLoading;	
	double		m_dMinVal, m_dMaxVal;
};


