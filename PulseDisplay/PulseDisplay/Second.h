#pragma once


// CSecond 대화 상자입니다.

class CSecond : public CPropertyPage
{
	DECLARE_DYNAMIC(CSecond)

public:
	CSecond();
	virtual ~CSecond();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
