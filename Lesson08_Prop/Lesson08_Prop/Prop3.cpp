// Prop3.cpp : 实现文件
//

#include "stdafx.h"
#include "Lesson08_Prop.h"
#include "Prop3.h"
#include "afxdialogex.h"


// CProp3 对话框

IMPLEMENT_DYNAMIC(CProp3, CPropertyPage)

CProp3::CProp3()
	: CPropertyPage(CProp3::IDD)
	, m_strSalary(_T(""))
{

}

CProp3::~CProp3()
{
}

void CProp3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, m_strSalary);
}


BEGIN_MESSAGE_MAP(CProp3, CPropertyPage)
END_MESSAGE_MAP()


// CProp3 消息处理程序


BOOL CProp3::OnSetActive()
{
	// TODO:  在此添加专用代码和/或调用基类
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);
	return CPropertyPage::OnSetActive();
}


BOOL CProp3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("5000元以下");
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("5000-10000元");
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("10000-20000元");
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("20000元以上");
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


BOOL CProp3::OnWizardFinish()
{
	// TODO:  在此添加专用代码和/或调用基类
	int index = ((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetLBText(index, m_strSalary);
	return CPropertyPage::OnWizardFinish();
}
