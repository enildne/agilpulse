#pragma once

#include "Strings.h"

// CSignal
enum
{
	SET_NONE = 0,
	SET_GREEN,
	SET_RED
};

class CSignal : public CStatic
{
	DECLARE_DYNAMIC(CSignal)

public:
	CSignal();
	virtual ~CSignal();

	int setColor;
	void	SetString(CString setStr) { m_String = setStr; }

protected:
	DECLARE_MESSAGE_MAP()

	CString		m_String;
public:
	afx_msg void OnPaint();
};


