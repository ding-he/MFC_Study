
// Lesson03View.cpp : CLesson03View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Lesson03.h"
#endif

#include "Lesson03Doc.h"
#include "Lesson03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLesson03View

IMPLEMENT_DYNCREATE(CLesson03View, CView)

BEGIN_MESSAGE_MAP(CLesson03View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CLesson03View ����/����

CLesson03View::CLesson03View()
{
	// TODO:  �ڴ˴���ӹ������

}

CLesson03View::~CLesson03View()
{
}

BOOL CLesson03View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLesson03View ����

void CLesson03View::OnDraw(CDC* /*pDC*/)
{
	CLesson03Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CLesson03View ��ӡ

BOOL CLesson03View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CLesson03View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CLesson03View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CLesson03View ���

#ifdef _DEBUG
void CLesson03View::AssertValid() const
{
	CView::AssertValid();
}

void CLesson03View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson03Doc* CLesson03View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson03Doc)));
	return (CLesson03Doc*)m_pDocument;
}
#endif //_DEBUG


// CLesson03View ��Ϣ�������


int CLesson03View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	m_btn.Create(_T("Demo"), WS_CHILD | BS_PUSHBUTTON, CRect(0, 0, 100, 100),GetParent(),  /*this,*/ 123);
	m_btn.ShowWindow(SW_NORMAL);

	return 0;
}
