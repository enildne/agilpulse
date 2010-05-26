#pragma once


// CFirst 대화 상자입니다.

class CFirst : public CPropertyPage
{
	DECLARE_DYNAMIC(CFirst)

public:
	CFirst();
	virtual ~CFirst();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
