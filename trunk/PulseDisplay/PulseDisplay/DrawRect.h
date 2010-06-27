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
	void		setGraphDraw(BOOL set)	{ m_bLoading = set; }		// FALSE 이면 GRID만 그린다.
	BOOL		GetGraphDraw(void)		{ return m_bLoading; }
	int			GetCheckedLevel(void)		{ return m_CheckedLevel; }
	void		setVolt1Start(int val)	{ m_voltage_1_start =  val; }
	void		setVolt1End(int val)	{ m_voltage_1_end =  val; }
	void		setStandardVolt(int val)	{ m_standard_voltage_1 =  val; }

	int			m_levelRangeMax;
	int			m_levelRangeMin;
	int			m_levelMax;
	int			m_levelMin;
	int			m_CheckedLevel;

protected:
	DECLARE_MESSAGE_MAP()
	BOOL		m_bLoading;	
	unsigned char	m_dconvData[VALUE_COUNT + 1];
	int			m_voltage_1_start;
	int			m_voltage_1_end;
	int			m_standard_voltage_1;					// 기준 1volt
};
