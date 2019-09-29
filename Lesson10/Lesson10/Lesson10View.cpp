
// Lesson10View.cpp : CLesson10View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Lesson10.h"
#endif

#include "Lesson10Doc.h"
#include "Lesson10View.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLesson10View

IMPLEMENT_DYNCREATE(CLesson10View, CView)

BEGIN_MESSAGE_MAP(CLesson10View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_DOT, &CLesson10View::OnDot)
	ON_COMMAND(IDM_LINE, &CLesson10View::OnLine)
	ON_COMMAND(IDM_RECTANGLE, &CLesson10View::OnRectangle)
	ON_COMMAND(IDM_ELLIPSE, &CLesson10View::OnEllipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDM_SETTING, &CLesson10View::OnSetting)
	ON_COMMAND(IDM_COLOR, &CLesson10View::OnColor)
	ON_COMMAND(IDM_FONT, &CLesson10View::OnFont)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CLesson10View 构造/析构

CLesson10View::CLesson10View()
	: m_nDrawType(0)
	, m_ptOrigin(0)
	, m_nLineWidth(0)
	, m_nLineStyle(0)
{
	// TODO:  在此处添加构造代码
	m_color = RGB(255, 0, 0);
	m_font.CreatePointFont(300, "华文行楷");
	LOGFONT *pLogFont = new LOGFONT;
	m_font.GetLogFont(pLogFont);
	m_strFontName = pLogFont->lfFaceName;
	delete pLogFont;
}

CLesson10View::~CLesson10View()
{
}

BOOL CLesson10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLesson10View 绘制

void CLesson10View::OnDraw(CDC* pDC)
{
	CLesson10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	CFont *pOldFont = pDC->SelectObject(&m_font);;
	pDC->TextOutA(0, 0, m_strFontName);
	pDC->SelectObject(pOldFont);

	/*//有闪烁
	//1. 加载位图
	CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BITMAP1);

	BITMAP bm;
	bitmap.GetBitmap(&bm);

	//2. 创建兼容DC
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);

	//3. 将位图选入兼容DC中
	dcCompatible.SelectObject(&bitmap);

	//4. 将兼容DC复制到当前DC中
	CRect rect;
	GetClientRect(&rect);

	int nX = rect.left + (rect.Width() - bm.bmWidth) / 2;
	int nY = rect.top + (rect.Height() - bm.bmHeight) / 2;

	//pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);
	//pDC->BitBlt(nX, nY, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);	//在中间显示
	//拉伸或压缩位图以适应目标矩形的尺寸
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);*/
}


// CLesson10View 打印

BOOL CLesson10View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CLesson10View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CLesson10View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CLesson10View 诊断

#ifdef _DEBUG
void CLesson10View::AssertValid() const
{
	CView::AssertValid();
}

void CLesson10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson10Doc* CLesson10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson10Doc)));
	return (CLesson10Doc*)m_pDocument;
}
#endif //_DEBUG


// CLesson10View 消息处理程序


void CLesson10View::OnDot()
{
	// TODO:  在此添加命令处理程序代码
	m_nDrawType = 1;
}


void CLesson10View::OnLine()
{
	// TODO:  在此添加命令处理程序代码
	m_nDrawType = 2;
}


void CLesson10View::OnRectangle()
{
	// TODO:  在此添加命令处理程序代码
	m_nDrawType = 3;
}


void CLesson10View::OnEllipse()
{
	// TODO:  在此添加命令处理程序代码
	m_nDrawType = 4;
}


void CLesson10View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	m_ptOrigin = point;//保存基点
	CView::OnLButtonDown(nFlags, point);
}


void CLesson10View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	//CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen pen(m_nLineStyle, m_nLineWidth, m_color);
	dc.SelectObject(&pen);		//指定笔
	dc.SelectObject(CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)));	//指定画刷

	switch (m_nDrawType)
	{
	case 1:
		//dot
		dc.SetPixel(point, m_color);
		break;
	case 2:
		//line
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		break;
	case 3:
		//rectangle
		dc.Rectangle(CRect(m_ptOrigin, point));
		break;
	case 4:
		//ellipse
		dc.Ellipse(CRect(m_ptOrigin, point));
		break;
	default:
		break;
	}

	CView::OnLButtonUp(nFlags, point);
}


void CLesson10View::OnSetting()
{
	// TODO:  在此添加命令处理程序代码
	CSettingDlg dlg;	//m_nLineWidth=0
	dlg.m_nLineWidth = m_nLineWidth;	//把当前的线宽传入dlg
	dlg.m_nLineStyle = m_nLineStyle;
	dlg.m_color = m_color;
	if (IDOK == dlg.DoModal())
	{
		m_nLineWidth = dlg.m_nLineWidth;	//传入线宽
		m_nLineStyle = dlg.m_nLineStyle;	//传入线型
	}
}


void CLesson10View::OnColor()
{
	// TODO:  在此添加命令处理程序代码
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_RGBINIT;// | CC_FULLOPEN;
	dlg.m_cc.rgbResult = m_color;
	if (IDOK == dlg.DoModal())
	{
		m_color = dlg.m_cc.rgbResult;
	}
}


void CLesson10View::OnFont()
{
	// TODO:  在此添加命令处理程序代码
	CFontDialog dlg;
	if (IDOK == dlg.DoModal())
	{
		if (m_font.m_hObject)
			m_font.DeleteObject();
		m_font.CreateFontIndirect(dlg.m_cf.lpLogFont);
		m_strFontName = dlg.m_cf.lpLogFont->lfFaceName;
	}
	Invalidate();
}

//擦除背景消息
BOOL CLesson10View::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//1. 加载位图
	CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BITMAP1);

	BITMAP bm;
	bitmap.GetBitmap(&bm);
	
	//2. 创建兼容DC
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);

	//3. 将位图选入兼容DC中
	dcCompatible.SelectObject(&bitmap);

	//4. 将兼容DC复制到当前DC中
	CRect rect;
	GetClientRect(&rect);
	
	int nX = rect.left + (rect.Width() - bm.bmWidth) / 2;
	int nY = rect.top + (rect.Height() - bm.bmHeight) / 2;

	//pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);
	//pDC->BitBlt(nX, nY, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);	//在中间显示
	//拉伸或压缩位图以适应目标矩形的尺寸
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);

	//return CView::OnEraseBkgnd(pDC);
	return TRUE;
}
