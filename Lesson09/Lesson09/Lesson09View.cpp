
// Lesson09View.cpp : CLesson09View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_COMMAND(IDM_TEST, &CLesson09View::OnTest)
//	ON_COMMAND(IDM_VIEW_NEWTOOLBAR, &CLesson09View::OnViewNewtoolbar)
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CLesson09View 构造/析构

CLesson09View::CLesson09View()
{
	// TODO:  在此处添加构造代码

}

CLesson09View::~CLesson09View()
{
}

BOOL CLesson09View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	//cs.lpszClass = "hello";//已经注册了这个类
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, LoadCursor(NULL, IDC_HAND), (HBRUSH)GetStockObject(GRAY_BRUSH), 0);
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, LoadCursor(NULL, IDC_HAND), (HBRUSH)GetStockObject(NULL_BRUSH), 0);
	//cs.lpszClass = AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW, 0, 0, 0);
	return CView::PreCreateWindow(cs);
}

// CLesson09View 绘制

void CLesson09View::OnDraw(CDC* /*pDC*/)
{
	CLesson09Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CLesson09View 打印

BOOL CLesson09View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CLesson09View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CLesson09View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CLesson09View 诊断

#ifdef _DEBUG
void CLesson09View::AssertValid() const
{
	CView::AssertValid();
}

void CLesson09View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson09Doc* CLesson09View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson09Doc)));
	return (CLesson09Doc*)m_pDocument;
}
#endif //_DEBUG


// CLesson09View 消息处理程序


int CLesson09View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	//SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_HAND));
	return 0;
}


void CLesson09View::OnTest()
{
	// TODO:  在此添加命令处理程序代码
	MessageBox("Test");
}


//void CLesson09View::OnViewNewtoolbar()
//{
//	// TODO:  在此添加命令处理程序代码
//	if ()
//}


void CLesson09View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CString str;
	str.Format("x = %d, y = %d", point.x, point.y);
	//((CMainFrame*)GetParent())->m_wndStatusBar.SetWindowTextA(str);
	//((CMainFrame*)GetParent())->SetMessageText(str);
	//((CMainFrame*)GetParent())->GetMessageBar()->SetWindowText(str);
	GetParent()->GetDescendantWindow(AFX_IDW_STATUS_BAR)->SetWindowTextA(str);
	CView::OnMouseMove(nFlags, point);
}
