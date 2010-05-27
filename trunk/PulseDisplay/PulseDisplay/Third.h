#pragma once


// CThird 대화 상자입니다.

class CThird : public CPropertyPage
{
	DECLARE_DYNAMIC(CThird)

public:
	CThird();
	virtual ~CThird();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
