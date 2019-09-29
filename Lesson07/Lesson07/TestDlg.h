#pragma once
#include "afxwin.h"


// CTestDlg 对话框

class CTestDlg : public CDialog
{
	DECLARE_DYNAMIC(CTestDlg)

public:
	CTestDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTestDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedBtnAdd();
private:
	CButton m_btn;
	BOOL m_bIsCreated;
public:
	afx_msg void OnClickedNumber1();
private:
	int m_num1;
	int m_num2;
	int m_num3;
private:
	CEdit m_edit1;
	CEdit m_edit2;
	CEdit m_edit3;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
