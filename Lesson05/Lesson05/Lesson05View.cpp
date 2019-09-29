
// Lesson05View.cpp : CLesson05View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Lesson05.h"
#endif

#include "Lesson05Doc.h"
#include "Lesson05View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLesson05View

IMPLEMENT_DYNCREATE(CLesson05View, CView)

BEGIN_MESSAGE_MAP(CLesson05View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CLesson05View 构造/析构

CLesson05View::CLesson05View()
	: m_strLine(_T(""))
	, m_ptOrigin(0)
	, m_nWidth(0)
{
	// TODO:  在此处添加构造代码

}

CLesson05View::~CLesson05View()
{
}

BOOL CLesson05View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLesson05View 绘制

void CLesson05View::OnDraw(CDC* pDC)
{
	CLesson05Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	CString str;// ("Hello World 世界,你好");
	str = "Hello World 世界,你好";
	pDC->TextOutW(50, 50, str);

	CSize sz = pDC->GetTextExtent(str);//获取字符串长度宽度信息

	str.LoadStringW(IDS_MYSTRING);
	pDC->TextOutW(0, 200, str);

	pDC->BeginPath();
	pDC->Rectangle(CRect(50, 50, 50 + sz.cx, 50 + sz.cy));
	pDC->EndPath();

	pDC->SelectClipPath(RGN_DIFF);

	for (int i = 0; i < 300; i += 10)
	{
		pDC->MoveTo(0, i);
		pDC->LineTo(300, i);
		pDC->MoveTo(i, 0);
		pDC->LineTo(i, 300);
	}
}


// CLesson05View 打印

BOOL CLesson05View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CLesson05View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CLesson05View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CLesson05View 诊断

#ifdef _DEBUG
void CLesson05View::AssertValid() const
{
	CView::AssertValid();
}

void CLesson05View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson05Doc* CLesson05View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson05Doc)));
	return (CLesson05Doc*)m_pDocument;
}
#endif //_DEBUG


// CLesson05View 消息处理程序


int CLesson05View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	/*CreateSolidCaret(20, 100);//宽度,高度  的插入符
	//CreateSolidCaret(0, 0);*/

	/*CClientDC dc(this);
	TEXTMETRIC tm;	//文本结构体变量

	dc.GetTextMetrics(&tm);	//获取文本信息
	CreateSolidCaret(tm.tmAveCharWidth / 8, tm.tmHeight);*/

	//static CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	CreateCaret(&bitmap);

	ShowCaret();	//显示插入符

	SetTimer(1, 100, NULL);//定时器: 100ms
	return 0;
}


void CLesson05View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point);
	m_strLine.Empty();
	m_ptOrigin = point;
	CView::OnLButtonDown(nFlags, point);
}


void CLesson05View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//注意: 使用WCHAR转换, 不用char
	WCHAR ch = (WCHAR)nChar;
	CClientDC dc(this);

	CFont font;
	font.CreatePointFont(300, _T("楷体"), NULL);		//字体设置
	CFont *pOldFont = dc.SelectObject(&font);

	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	if (0x0d == ch)
	{
		//回车
		m_ptOrigin.y += tm.tmHeight;
		m_strLine.Empty();
	}
	else if (0x08 == ch)
	{
		//退格
		COLORREF oldClr = dc.SetTextColor(dc.GetBkColor());
		dc.TextOutW(m_ptOrigin.x, m_ptOrigin.y, m_strLine);
		m_strLine = m_strLine.Left(m_strLine.GetLength() - 1);
		dc.SetTextColor(oldClr);
	}
	else
	{
		m_strLine += ch;
	}

	dc.TextOutW(m_ptOrigin.x, m_ptOrigin.y, m_strLine);

	//改变光标位置
	CSize sz = dc.GetTextExtent(m_strLine);
	SetCaretPos(CPoint(m_ptOrigin.x + sz.cx, m_ptOrigin.y));

	dc.SelectObject(pOldFont);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CLesson05View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	m_nWidth += 5;
	CClientDC dc(this);

	CString str;
	str.LoadStringW(IDS_MYSTRING);
	

	
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	//变色矩形区域
	CRect rect;
	rect.left = 0;
	rect.top = 200;
	rect.right = m_nWidth;
	rect.bottom = rect.top + tm.tmHeight;

	dc.SetTextColor(RGB(255, 0, 0));
	
	dc.DrawText(str, rect, DT_LEFT);

	/*rect.top = 150;
	rect.bottom = rect.top + tm.tmHeight;
	dc.DrawText(str, rect, DT_RIGHT);*/

	CSize sz = dc.GetTextExtent(str);
	if (m_nWidth > sz.cx)
	{
		m_nWidth = 0;
		dc.SetTextColor(RGB(0, 0, 0));
		dc.TextOutW(0, 200, str);
	}

	CView::OnTimer(nIDEvent);
}
