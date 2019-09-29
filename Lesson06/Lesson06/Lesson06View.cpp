
// Lesson06View.cpp : CLesson06View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Lesson06.h"
#endif

#include "Lesson06Doc.h"
#include "Lesson06View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLesson06View

IMPLEMENT_DYNCREATE(CLesson06View, CView)

BEGIN_MESSAGE_MAP(CLesson06View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_COMMAND(IDM_TEST, &CLesson06View::OnTest)
	ON_COMMAND(ID_TEST, &CLesson06View::OnTest)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_SHOW, &CLesson06View::OnShow)
	ON_WM_CHAR()
	ON_COMMAND(IDM_PHONE1, &CLesson06View::OnPhone1)
	ON_COMMAND(IDM_PHONE2, &CLesson06View::OnPhone2)
	ON_COMMAND(IDM_PHONE3, &CLesson06View::OnPhone3)
	ON_COMMAND(IDM_PHONE4, &CLesson06View::OnPhone4)
END_MESSAGE_MAP()

// CLesson06View ����/����

CLesson06View::CLesson06View()
	: m_nIndex(-1)
	, m_strLine(_T(""))
{
	// TODO:  �ڴ˴���ӹ������

}

CLesson06View::~CLesson06View()
{
}

BOOL CLesson06View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLesson06View ����

void CLesson06View::OnDraw(CDC* /*pDC*/)
{
	CLesson06Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CLesson06View ��ӡ

BOOL CLesson06View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CLesson06View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CLesson06View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CLesson06View ���

#ifdef _DEBUG
void CLesson06View::AssertValid() const
{
	CView::AssertValid();
}

void CLesson06View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson06Doc* CLesson06View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson06Doc)));
	return (CLesson06Doc*)m_pDocument;
}
#endif //_DEBUG


// CLesson06View ��Ϣ�������


//void CLesson06View::OnTest()
//{
//	// TODO:  �ڴ���������������
//	MessageBox(_T("View Clicked"));
//}


void CLesson06View::OnTest()
{
	// TODO:  �ڴ���������������
}


void CLesson06View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);

	CMenu *pPopup = menu.GetSubMenu(0);

	ClientToScreen(&point);
	//pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);//��ʾ�Ҽ�
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, GetParent());//��ʾ�Ҽ�

	CView::OnRButtonDown(nFlags, point);
}


void CLesson06View::OnShow()
{
	// TODO:  �ڴ���������������
	MessageBox(_T("View Show"));
}


void CLesson06View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	WCHAR ch = (WCHAR)nChar;

	CClientDC dc(this);

	if (0x0d == ch)
	{
		//�س�
		if (0 == ++m_nIndex)
		{
			//��һ��, ��Ӳ˵�
			m_menu.CreateMenu();
			//���ø�����CMainFrame
			GetParent()->GetMenu()->AppendMenuW(MF_POPUP, (UINT)m_menu.m_hMenu, _T("PhoneBook"));
			GetParent()->DrawMenuBar();//�ػ�˵�

		}
		m_strArray.Add(m_strLine);
		m_menu.AppendMenuW(MF_STRING, IDM_PHONE1 + m_nIndex, m_strLine.Left(m_strLine.Find(' ')));
		m_strLine.Empty();//����ַ���
		Invalidate();//�ػ洰��, ������һ�εıʼ�
	}
	else
	{
		m_strLine += ch;
		dc.TextOutW(0, 0, m_strLine);
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CLesson06View::OnPhone1()
{
	// TODO:  �ڴ���������������
	CClientDC dc(this);
	//Invalidate();
	dc.TextOutW(0, 0, m_strArray.GetAt(0));
}


void CLesson06View::OnPhone2()
{
	// TODO:  �ڴ���������������
	CClientDC dc(this);
	//Invalidate();
	dc.TextOutW(0, 0, m_strArray.GetAt(1));
}


void CLesson06View::OnPhone3()
{
	// TODO:  �ڴ���������������
	CClientDC dc(this);
	//Invalidate();
	dc.TextOutW(0, 0, m_strArray.GetAt(2));
}


void CLesson06View::OnPhone4()
{
	// TODO:  �ڴ���������������
	CClientDC dc(this);
	//Invalidate();
	dc.TextOutW(0, 0, m_strArray.GetAt(3));
}
