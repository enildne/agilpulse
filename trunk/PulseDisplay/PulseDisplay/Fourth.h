#pragma once


// CFourth ��ȭ �����Դϴ�.

class CFourth : public CPropertyPage
{
	DECLARE_DYNAMIC(CFourth)

public:
	CFourth();
	virtual ~CFourth();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
