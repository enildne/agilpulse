#pragma once

#include "First.h"
#include "Second.h"
#include "Third.h"
#include "Fourth.h"

// CBaseSheet

class CBaseSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CBaseSheet)

public:
	CBaseSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CBaseSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CBaseSheet();

	CFirst	m_firstPage;
	CSecond	m_secondPage;
	CThird	m_thirdPage;
	CFourth	m_fourthPage;

protected:
	DECLARE_MESSAGE_MAP()
};


