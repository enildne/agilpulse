#pragma once

#include "DefineAndSize.h"
// CDrawRect

class CDrawRect : public CStatic
{
	DECLARE_DYNAMIC(CDrawRect)

public:
	CDrawRect();
	virtual ~CDrawRect();

	afx_msg int		OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void	OnPaint();
	afx_msg void	OnShowWindow(BOOL bShow, UINT nStatus);

	void		setPulseData(unsigned char* data);
	void		setGraphDraw(BOOL set) {m_bLoading = set;}		// FALSE �̸� GRID�� �׸���.

protected:
	DECLARE_MESSAGE_MAP()
	BOOL		m_bLoading;	
	double		m_dMinVal, m_dMaxVal;
	unsigned char	m_dconvData[VALUE_COUNT + 1];
};


