#pragma once


// CFirst ��ȭ �����Դϴ�.

class CFirst : public CPropertyPage
{
	DECLARE_DYNAMIC(CFirst)

public:
	CFirst();
	virtual ~CFirst();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
