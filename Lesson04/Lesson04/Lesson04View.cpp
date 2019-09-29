
// Lesson04View.cpp : CLesson04View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Lesson04.h"
#endif

#include "Lesson04Doc.h"
#include "Lesson04View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLesson04View

IMPLEMENT_DYNCREATE(CLesson04View, CView)

BEGIN_MESSAGE_MAP(CLesson04View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CLesson04View ����/����

CLesson04View::CLesson04View()
	: m_ptOrigin(0)
	, m_bDraw(FALSE)
	, m_ptOld(0)
{
	// TODO:  �ڴ˴���ӹ������

}

CLesson04View::~CLesson04View()
{
}

BOOL CLesson04View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLesson04View ����

void CLesson04View::OnDraw(CDC* /*pDC*/)
{
	CLesson04Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CLesson04View ��ӡ

BOOL CLesson04View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CLesson04View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CLesson04View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CLesson04View ���

#ifdef _DEBUG
void CLesson04View::AssertValid() const
{
	CView::AssertValid();
}

void CLesson04View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson04Doc* CLesson04View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson04Doc)));
	return (CLesson04Doc*)m_pDocument;
}
#endif //_DEBUG


// CLesson04View ��Ϣ�������


void CLesson04View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//��������
	m_ptOrigin = m_ptOld = point;
	m_bDraw = TRUE;
	//MessageBox(_T("��������"));
	CView::OnLButtonDown(nFlags, point);
}


void CLesson04View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//����̧��
	//MessageBox(_T("����̧��"));
	//1
	/*HDC hdc;
	hdc = ::GetDC(m_hWnd);
	MoveToEx(hdc, m_ptOrigin.x, m_ptOrigin.y, NULL);//�ƶ���ֱ��ԭ��
	LineTo(hdc, point.x, point.y);//���ߵ�ֱ���յ�
	::ReleaseDC(m_hWnd, hdc);
	CView::OnLButtonUp(nFlags, point);*/

	//2
	/*CDC *pDc = GetDC();
	pDc->MoveTo(m_ptOrigin);
	pDc->LineTo(point);
	ReleaseDC(pDc);*/

	//3
	/*CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CClientDC dc(this);
	CPen *pOldPen = dc.SelectObject(&pen);
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);
	dc.SelectObject(pOldPen);*/

	//4
	/*CWindowDC dc(GetDesktopWindow());
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);*/

	//5
	//CBrush brush(RGB(255, 0, 0));
	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_BITMAP1);
	//CBrush brush(&bitmap);
	//CClientDC dc(this);
	//dc.FillRect(CRect(m_ptOrigin, point), &brush);
	/*CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush = dc.SelectObject(pBrush);
	dc.Rectangle(CRect(m_ptOrigin, point));
	dc.SelectObject(pOldBrush);*/

	m_bDraw = FALSE;
	CView::OnLButtonUp(nFlags, point);
}


void CLesson04View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_bDraw == TRUE)//��갴��
	{
		CClientDC dc(this);
		CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
		CPen *pOldPen = dc.SelectObject(&pen);
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(m_ptOld);
		dc.MoveTo(m_ptOld);
		dc.LineTo(point);
		m_ptOld = point;//�ѵ�ǰ�㸳����ʼ��
		dc.SelectObject(pOldPen);
	}
	CView::OnMouseMove(nFlags, point);
}
