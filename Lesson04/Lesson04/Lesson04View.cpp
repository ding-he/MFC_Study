
// Lesson04View.cpp : CLesson04View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CLesson04View 构造/析构

CLesson04View::CLesson04View()
	: m_ptOrigin(0)
	, m_bDraw(FALSE)
	, m_ptOld(0)
{
	// TODO:  在此处添加构造代码

}

CLesson04View::~CLesson04View()
{
}

BOOL CLesson04View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLesson04View 绘制

void CLesson04View::OnDraw(CDC* /*pDC*/)
{
	CLesson04Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CLesson04View 打印

BOOL CLesson04View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CLesson04View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CLesson04View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CLesson04View 诊断

#ifdef _DEBUG
void CLesson04View::AssertValid() const
{
	CView::AssertValid();
}

void CLesson04View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson04Doc* CLesson04View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson04Doc)));
	return (CLesson04Doc*)m_pDocument;
}
#endif //_DEBUG


// CLesson04View 消息处理程序


void CLesson04View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//按键按下
	m_ptOrigin = m_ptOld = point;
	m_bDraw = TRUE;
	//MessageBox(_T("按键按下"));
	CView::OnLButtonDown(nFlags, point);
}


void CLesson04View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//按键抬起
	//MessageBox(_T("按键抬起"));
	//1
	/*HDC hdc;
	hdc = ::GetDC(m_hWnd);
	MoveToEx(hdc, m_ptOrigin.x, m_ptOrigin.y, NULL);//移动到直线原点
	LineTo(hdc, point.x, point.y);//画线到直线终点
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
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (m_bDraw == TRUE)//鼠标按下
	{
		CClientDC dc(this);
		CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
		CPen *pOldPen = dc.SelectObject(&pen);
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(m_ptOld);
		dc.MoveTo(m_ptOld);
		dc.LineTo(point);
		m_ptOld = point;//把当前点赋给起始点
		dc.SelectObject(pOldPen);
	}
	CView::OnMouseMove(nFlags, point);
}
