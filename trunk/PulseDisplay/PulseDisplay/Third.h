#pragma once


// CThird ��ȭ �����Դϴ�.

class CThird : public CPropertyPage
{
	DECLARE_DYNAMIC(CThird)

public:
	CThird();
	virtual ~CThird();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
