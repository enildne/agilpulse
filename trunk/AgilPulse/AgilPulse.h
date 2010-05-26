// AgilPulse.h : main header file for the AGILPULSE application
//

#if !defined(AFX_AGILPULSE_H__C9C1BBF0_017C_4775_AE79_1A3539F7B233__INCLUDED_)
#define AFX_AGILPULSE_H__C9C1BBF0_017C_4775_AE79_1A3539F7B233__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAgilPulseApp:
// See AgilPulse.cpp for the implementation of this class
//

class CAgilPulseApp : public CWinApp
{
public:
	CAgilPulseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAgilPulseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAgilPulseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AGILPULSE_H__C9C1BBF0_017C_4775_AE79_1A3539F7B233__INCLUDED_)
