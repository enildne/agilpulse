// PulseDisplayDlg.h : ��� ����
//

#pragma once


// CPulseDisplayDlg ��ȭ ����
class CPulseDisplayDlg : public CDialog
{
// ����
public:
	CPulseDisplayDlg(CWnd* pParent = NULL);	// ǥ�� ������

// ��ȭ ���� ������
	enum { IDD = IDD_PULSEDISPLAY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ����


// ����
protected:
	HICON m_hIcon;

	// �޽��� �� �Լ��� �����߽��ϴ�.
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
