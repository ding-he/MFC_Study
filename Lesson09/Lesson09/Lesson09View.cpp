
// Lesson09View.cpp : CLesson09View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Lesson09.h"
#endif

#include "Lesson09Doc.h"
#include "Lesson09View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLesson09View

IMPLEMENT_DYNCREATE(CLesson09View, CView)

BEGIN_MESSAGE_MAP(CLesson09View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_COMMAND(IDM_TEST, &CLesson09View::OnTest)
//	ON_COMMAND(IDM_VIEW_NEWTOOLBAR, &CLesson09View::OnViewNewtoolbar)
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CLesson09View ����/����

CLesson09View::CLesson09View()
{
	// TODO:  �ڴ˴���ӹ������

}

CLesson09View::~CLesson09View()
{
}

BOOL CLesson09View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	//cs.lpszClass = "hello";//�Ѿ�ע���������
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, LoadCursor(NULL, IDC_HAND), (HBRUSH)GetStockObject(GRAY_BRUSH), 0);
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, LoadCursor(NULL, IDC_HAND), (HBRUSH)GetStockObject(NULL_BRUSH), 0);
	//cs.lpszClass = AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW, 0, 0, 0);
	return CView::PreCreateWindow(cs);
}

// CLesson09View ����

void CLesson09View::OnDraw(CDC* /*pDC*/)
{
	CLesson09Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CLesson09View ��ӡ

BOOL CLesson09View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CLesson09View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CLesson09View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CLesson09View ���

#ifdef _DEBUG
void CLesson09View::AssertValid() const
{
	CView::AssertValid();
}

void CLesson09View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson09Doc* CLesson09View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson09Doc)));
	return (CLesson09Doc*)m_pDocument;
}
#endif //_DEBUG


// CLesson09View ��Ϣ�������


int CLesson09View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	//SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_HAND));
	return 0;
}


void CLesson09View::OnTest()
{
	// TODO:  �ڴ���������������
	MessageBox("Test");
}


//void CLesson09View::OnViewNewtoolbar()
//{
//	// TODO:  �ڴ���������������
//	if ()
//}


void CLesson09View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	str.Format("x = %d, y = %d", point.x, point.y);
	//((CMainFrame*)GetParent())->m_wndStatusBar.SetWindowTextA(str);
	//((CMainFrame*)GetParent())->SetMessageText(str);
	//((CMainFrame*)GetParent())->GetMessageBar()->SetWindowText(str);
	GetParent()->GetDescendantWindow(AFX_IDW_STATUS_BAR)->SetWindowTextA(str);
	CView::OnMouseMove(nFlags, point);
}
