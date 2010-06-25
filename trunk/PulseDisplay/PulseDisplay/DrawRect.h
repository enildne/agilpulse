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
	void		setGraphDraw(BOOL set) {m_bLoading = set;}		// FALSE 이면 GRID만 그린다.
	void		setVolt1Start(int val) {m_voltage_1_start =  val;}
	void		setVolt1End(int val) {m_voltage_1_end =  val;}

protected:
	DECLARE_MESSAGE_MAP()
	BOOL		m_bLoading;	
	unsigned char	m_dconvData[VALUE_COUNT + 1];
	int			m_voltage_1_start;
	int			m_voltage_1_end;
};
