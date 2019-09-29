
// Lesson03View.cpp : CLesson03View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CLesson03View 构造/析构

CLesson03View::CLesson03View()
{
	// TODO:  在此处添加构造代码

}

CLesson03View::~CLesson03View()
{
}

BOOL CLesson03View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLesson03View 绘制

void CLesson03View::OnDraw(CDC* /*pDC*/)
{
	CLesson03Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CLesson03View 打印

BOOL CLesson03View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CLesson03View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CLesson03View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CLesson03View 诊断

#ifdef _DEBUG
void CLesson03View::AssertValid() const
{
	CView::AssertValid();
}

void CLesson03View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson03Doc* CLesson03View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson03Doc)));
	return (CLesson03Doc*)m_pDocument;
}
#endif //_DEBUG


// CLesson03View 消息处理程序


int CLesson03View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	m_btn.Create(_T("Demo"), WS_CHILD | BS_PUSHBUTTON, CRect(0, 0, 100, 100),GetParent(),  /*this,*/ 123);
	m_btn.ShowWindow(SW_NORMAL);

	return 0;
}
