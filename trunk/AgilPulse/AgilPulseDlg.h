// AgilPulseDlg.h : header file
//

#if !defined(AFX_AGILPULSEDLG_H__DF2A2E6D_996A_4909_92FC_4C1B647A4C9D__INCLUDED_)
#define AFX_AGILPULSEDLG_H__DF2A2E6D_996A_4909_92FC_4C1B647A4C9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAgilPulseDlg dialog

class CAgilPulseDlg : public CDialog
{
// Construction
public:
	CAgilPulseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAgilPulseDlg)
	enum { IDD = IDD_AGILPULSE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAgilPulseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAgilPulseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AGILPULSEDLG_H__DF2A2E6D_996A_4909_92FC_4C1B647A4C9D__INCLUDED_)
