#pragma once


// CSecond ��ȭ �����Դϴ�.

class CSecond : public CPropertyPage
{
	DECLARE_DYNAMIC(CSecond)

public:
	CSecond();
	virtual ~CSecond();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
