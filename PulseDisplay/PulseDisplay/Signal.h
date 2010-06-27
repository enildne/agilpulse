#pragma once

#include "Strings.h"

// CSignal
enum
{
	SET_NONE = 0,
	SET_GREEN,
	SET_RED,
	SET_TEXT
};

class CSignal : public CStatic
{
	DECLARE_DYNAMIC(CSignal)

public:
	CSignal();
	virtual ~CSignal();

	int setColor;
	void	SetString(CString setStr) { m_String = setStr; }
	void	SetOKBmp(int set) { m_IDBmp_OK = set; }
	void	SetFailBmp(int set) { m_IDBmp_Fail = set; }

protected:
	DECLARE_MESSAGE_MAP()

	CString		m_String;

	int			m_IDBmp_OK;
	int			m_IDBmp_Fail;
	
public:
	afx_msg void OnPaint();
};


