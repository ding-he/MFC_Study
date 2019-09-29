#pragma once


// CProp2 对话框

class CProp2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp2)

public:
	CProp2();
	virtual ~CProp2();

// 对话框数据
	enum { IDD = IDD_PROP2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
public:
	BOOL m_basketball;
	BOOL m_football;
	BOOL m_game;
	BOOL m_swim;
public:
	virtual LRESULT OnWizardNext();
};
