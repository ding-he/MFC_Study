// TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Lesson07.h"
#include "TestDlg.h"
#include "afxdialogex.h"

#define _CRT_SECURE_NO_WARNINGS


// CTestDlg �Ի���

IMPLEMENT_DYNAMIC(CTestDlg, CDialog)

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
	, m_bIsCreated(FALSE)
	, m_num1(0)
	, m_num2(0)
	, m_num3(0)
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDX_Text(pDX, IDC_EDIT2, m_num2);
	DDX_Text(pDX, IDC_EDIT3, m_num3);
	DDV_MinMaxInt(pDX, m_num1, 0, 100);
	DDV_MinMaxInt(pDX, m_num2, 0, 100);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_ADD, &CTestDlg::OnClickedBtnAdd)
	ON_STN_CLICKED(IDC_NUMBER1, &CTestDlg::OnClickedNumber1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CTestDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTestDlg ��Ϣ�������


void CTestDlg::OnClickedBtnAdd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//static BOOL bIsCreated = FALSE;
	//if (bIsCreated == FALSE)
	/*if (!m_btn.m_hWnd)	//�еĻ���Ϊ��
	{
		m_btn.Create("Test", BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD, CRect(0, 0, 100, 100), this, 111);
		//bIsCreated = TRUE;
	}
	else
	{
		m_btn.DestroyWindow();
		//bIsCreated = FALSE;
	}*/

	/*int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];

	//��ȡֵ
	GetDlgItem(IDC_EDIT1)->GetWindowText(ch1, 10);
	GetDlgItem(IDC_EDIT2)->GetWindowText(ch2, 10);

	//ת��
	num1 = atoi(ch1);
	num2 = atoi(ch2);
	num3 = num1 + num2;

	_itoa_s(num3, ch3, 10);

	GetDlgItem(IDC_EDIT3)->SetWindowText(ch3);*/

	/*int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];

	GetDlgItemText(IDC_EDIT1, ch1, 10);//GetDlgItem(IDC_EDIT1)->GetWindowText(ch1, 10);
	GetDlgItemText(IDC_EDIT2, ch2, 10);

	num1 = atoi(ch1);
	num2 = atoi(ch2);
	num3 = num1 + num2;
	_itoa_s(num3, ch3, 10);
	SetDlgItemText(IDC_EDIT3, ch3);*/

	/*int num1, num2, num3;
	
	num1 = GetDlgItemInt(IDC_EDIT1);
	num2 = GetDlgItemInt(IDC_EDIT2);

	num3 = num1 + num2;
	SetDlgItemInt(IDC_EDIT3, num3);*/

	/*UpdateData();
	m_num3 = m_num1 + m_num2;
	UpdateData(FALSE);*/

	/*int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];

	m_edit1.GetWindowText(ch1, 10);
	m_edit2.GetWindowText(ch2, 10);

	num1 = atoi(ch1);
	num2 = atoi(ch2);
	num3 = num1 + num2;

	_itoa_s(num3, ch3, 10);
	m_edit3.SetWindowText(ch3);*/

	/*int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];

	::SendMessage(GetDlgItem(IDC_EDIT1)->m_hWnd, WM_GETTEXT, 10, (LPARAM)ch1);
	::SendMessage(m_edit2.m_hWnd, WM_GETTEXT, 10, (LPARAM)ch2);

	num1 = atoi(ch1);
	num2 = atoi(ch2);
	num3 = num1 + num2;

	_itoa_s(num3, ch3, 10);
	::SendMessage(m_edit3.m_hWnd, WM_SETTEXT, 0, (LPARAM)ch3);*/

	int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];

	SendDlgItemMessage(IDC_EDIT1, WM_GETTEXT, 10, (LPARAM)ch1);
	SendDlgItemMessage(IDC_EDIT2, WM_GETTEXT, 10, (LPARAM)ch2);

	num1 = atoi(ch1);
	num2 = atoi(ch2);
	num3 = num1 + num2;

	_itoa_s(num3, ch3, 10);
	SendDlgItemMessage(IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)ch3);

	//SendDlgItemMessage(IDC_EDIT3, EM_SETSEL, 1, 3);//��ѡ��� ��ͷ����β
	SendDlgItemMessage(IDC_EDIT3, EM_SETSEL, 0, -1);//��ѡ��� ��ѡȫ��
	m_edit3.SetFocus();//��ý���
}


void CTestDlg::OnClickedNumber1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItem(IDC_NUMBER1)->GetWindowText(str);//��ȡ�ı�ֵ
	if (str == "Number1:")
	{
		GetDlgItem(IDC_NUMBER1)->SetWindowTextA("��ֵ1:");
	}
	else
	{
		GetDlgItem(IDC_NUMBER1)->SetWindowTextA("Number1:");
	}
}


void CTestDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItemText(IDC_BUTTON2, str);

	static CRect rectLarge;
	static CRect rectSmall;

	if (rectLarge.IsRectNull())
	{
		//��һ��
		CRect rectSeperator;
		GetDlgItem(IDC_SEPERATOR)->GetWindowRect(&rectSeperator);//�ָ���
		GetWindowRect(&rectLarge);//�󴰿ھ���

		rectSmall.left = rectLarge.left;
		rectSmall.top = rectLarge.top;
		rectSmall.right = rectLarge.right;
		rectSmall.bottom = rectSeperator.bottom;
	}

	if (str == "����>>")
	{
		SetDlgItemText(IDC_BUTTON2, "��չ<<");
		SetWindowPos(NULL, 0, 0, rectSmall.Width(), rectSmall.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}
	else
	{
		SetDlgItemText(IDC_BUTTON2, "����>>");
		SetWindowPos(NULL, 0, 0, rectLarge.Width(), rectLarge.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}
}


void CTestDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//GetDlgItem(IDC_EDIT1)->GetNextWindow()->SetFocus();
	//GetFocus()->GetNextWindow()->SetFocus();
	GetNextDlgTabItem(GetFocus())->SetFocus();
	//CDialog::OnOK();
}

WNDPROC prevProc;
LRESULT CALLBACK NewEditProc(
	_In_ HWND   hwnd,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
	)
{
	if (uMsg == WM_CHAR && wParam == 0x0d)
	{
		//::SetFocus(GetNextWindow(hwnd, GW_HWNDNEXT));//��һ���ڵĽ���
		//::SetFocus(GetWindow(hwnd, GW_HWNDNEXT));//��һ���ڵĽ���
		::SetFocus(GetNextDlgTabItem(GetParent(hwnd), hwnd, FALSE));//��һ���ڵĽ���
		return 1;
	}
	else
	{
		return prevProc(hwnd, uMsg, wParam, lParam);
	}
}



BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	prevProc = (WNDPROC)SetWindowLong(GetDlgItem(IDC_EDIT1)->m_hWnd, GWL_WNDPROC, (LONG)NewEditProc);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
