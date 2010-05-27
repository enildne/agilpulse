#pragma once


// CFourth 대화 상자입니다.

class CFourth : public CPropertyPage
{
	DECLARE_DYNAMIC(CFourth)

public:
	CFourth();
	virtual ~CFourth();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
