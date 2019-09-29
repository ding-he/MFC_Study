// SettingDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Lesson10.h"
#include "SettingDlg.h"
#include "afxdialogex.h"


// CSettingDlg �Ի���

IMPLEMENT_DYNAMIC(CSettingDlg, CDialog)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
: CDialog(CSettingDlg::IDD, pParent)
, m_nLineWidth(0)
, m_nLineStyle(-1)
{
	m_color = RGB(255, 0, 0);
	m_brush.CreateSolidBrush(RGB(0, 0, 255));
	m_font.CreatePointFont(200, "����");
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


// CSettingDlg ��Ϣ�������


void CSettingDlg::OnChangeLineWidth()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Invalidate();
}


void CSettingDlg::OnClickedRadio1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Invalidate();
}


void CSettingDlg::OnBnClickedRadio2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Invalidate();
}


void CSettingDlg::OnBnClickedRadio3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Invalidate();
}


void CSettingDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	UpdateData();
	CPen pen(m_nLineStyle, m_nLineWidth, m_color);
	dc.SelectObject(&pen);

	CRect rect;
	GetDlgItem(IDC_SAMPLE)->GetWindowRect(&rect);
	ScreenToClient(&rect);		//��Ļ����תΪ�ͻ�������

	dc.MoveTo(rect.left + 20, rect.bottom - rect.Height() / 2);
	dc.LineTo(rect.right - 20, rect.bottom - rect.Height() / 2);
}


HBRUSH CSettingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if (pWnd->GetDlgCtrlID() == IDC_LINE_STYLE)
	{
		pDC->SetTextColor(RGB(255, 0, 0));
		//pDC->SetBkMode(TRANSPARENT);	//�������ֱ���͸��
		pDC->SetBkColor(RGB(0, 255, 0));
		return m_brush;		//������HBRUSH������
	}
	if (pWnd->GetDlgCtrlID() == IDC_TEXT)
	{
		pDC->SelectObject(&m_font);
	}
	if (pWnd->GetDlgCtrlID() == IDOK)
	{
		//pDC->SetTextColor(RGB(255, 0, 0));		//��Ч
		//return m_brush;						//��Ч
	}
	return hbr;
}
