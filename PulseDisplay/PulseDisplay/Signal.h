#pragma once


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
	
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


