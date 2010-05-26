#pragma once

#include "First.h"

// CBaseSheet

class CBaseSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CBaseSheet)

public:
	CBaseSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CBaseSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CBaseSheet();

	CFirst	m_firstPage;

protected:
	DECLARE_MESSAGE_MAP()
};


