// SettingDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Lesson10.h"
#include "SettingDlg.h"
#include "afxdialogex.h"


// CSettingDlg 对话框

IMPLEMENT_DYNAMIC(CSettingDlg, CDialog)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
: CDialog(CSettingDlg::IDD, pParent)
, m_nLineWidth(0)
, m_nLineStyle(-1)
{
	m_color = RGB(255, 0, 0);
	m_brush.CreateSolidBrush(RGB(0, 0, 255));
	m_font.CreatePointFont(200, "隶书");
}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LINE_WIDTH, m_nLineWidth);
	DDX_Radio(pDX, IDC_RADIO1, m_nLineStyle);
	DDX_Control(pDX, IDOK, m_btnTest);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
	ON_EN_CHANGE(IDC_LINE_WIDTH, &CSettingDlg::OnChangeLineWidth)
	ON_BN_CLICKED(IDC_RADIO1, &CSettingDlg::OnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CSettingDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CSettingDlg::OnBnClickedRadio3)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSettingDlg 消息处理程序


void CSettingDlg::OnChangeLineWidth()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	Invalidate();
}


void CSettingDlg::OnClickedRadio1()
{
	// TODO:  在此添加控件通知处理程序代码
	Invalidate();
}


void CSettingDlg::OnBnClickedRadio2()
{
	// TODO:  在此添加控件通知处理程序代码
	Invalidate();
}


void CSettingDlg::OnBnClickedRadio3()
{
	// TODO:  在此添加控件通知处理程序代码
	Invalidate();
}


void CSettingDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	UpdateData();
	CPen pen(m_nLineStyle, m_nLineWidth, m_color);
	dc.SelectObject(&pen);

	CRect rect;
	GetDlgItem(IDC_SAMPLE)->GetWindowRect(&rect);
	ScreenToClient(&rect);		//屏幕坐标转为客户端坐标

	dc.MoveTo(rect.left + 20, rect.bottom - rect.Height() / 2);
	dc.LineTo(rect.right - 20, rect.bottom - rect.Height() / 2);
}


HBRUSH CSettingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	if (pWnd->GetDlgCtrlID() == IDC_LINE_STYLE)
	{
		pDC->SetTextColor(RGB(255, 0, 0));
		//pDC->SetBkMode(TRANSPARENT);	//设置文字背景透明
		pDC->SetBkColor(RGB(0, 255, 0));
		return m_brush;		//重载了HBRUSH操作符
	}
	if (pWnd->GetDlgCtrlID() == IDC_TEXT)
	{
		pDC->SelectObject(&m_font);
	}
	if (pWnd->GetDlgCtrlID() == IDOK)
	{
		//pDC->SetTextColor(RGB(255, 0, 0));		//无效
		//return m_brush;						//无效
	}
	return hbr;
}
