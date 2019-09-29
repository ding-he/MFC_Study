
// GraphicView.cpp : CGraphicView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Graphic.h"
#endif

#include "GraphicDoc.h"
#include "GraphicView.h"
#include "Graph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphicView

IMPLEMENT_DYNCREATE(CGraphicView, CScrollView)

BEGIN_MESSAGE_MAP(CGraphicView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(IDM_DOT, &CGraphicView::OnDot)
	ON_COMMAND(IDM_LINE, &CGraphicView::OnLine)
	ON_COMMAND(IDM_RECTANGLE, &CGraphicView::OnRectangle)
	ON_COMMAND(IDM_ELLIPSE, &CGraphicView::OnEllipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_FILE_SAVE, &CGraphicView::OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, &CGraphicView::OnFileOpen)
END_MESSAGE_MAP()

// CGraphicView 构造/析构

CGraphicView::CGraphicView()
	: m_ptOrigin(0)
{
	// TODO:  在此处添加构造代码

	m_nDrawType = -1;
	m_dcMetaFile.Create();
}

CGraphicView::~CGraphicView()
{
}

BOOL CGraphicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CGraphicView 绘制

void CGraphicView::OnDraw(CDC* pDC)
{
	CGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	/*CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	pDC->SelectObject(&pen);

	pDC->SelectObject(CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)));

	for (int i = 0; i < m_ptrArray.GetSize(); i++)
	{
		switch (((CGraph*)m_ptrArray.GetAt(i))->m_nDrawType)
		{
		case 0:
			pDC->SetPixel(((CGraph*)m_ptrArray.GetAt(i))->m_ptEnd, RGB(255, 0, 0));
			break;
		case 1:
			pDC->MoveTo(((CGraph*)m_ptrArray.GetAt(i))->m_ptOrigin);
			pDC->LineTo(((CGraph*)m_ptrArray.GetAt(i))->m_ptEnd);
			break;
		case 2:
			pDC->Rectangle(CRect(((CGraph*)m_ptrArray.GetAt(i))->m_ptOrigin, ((CGraph*)m_ptrArray.GetAt(i))->m_ptEnd));
			break;
		case 3:
			pDC->Ellipse(CRect(((CGraph*)m_ptrArray.GetAt(i))->m_ptOrigin, ((CGraph*)m_ptrArray.GetAt(i))->m_ptEnd));
			break;
		default:
			break;
		}
	}*/

	/*//1. 关闭元文件
	HMETAFILE hMetaFile;
	hMetaFile = m_dcMetaFile.Close();
	//2. 播放元文件
	pDC->PlayMetaFile(hMetaFile);
	//3. 创建新的元文件
	m_dcMetaFile.Create();
	m_dcMetaFile.PlayMetaFile(hMetaFile);	//播放原来的到当前的元文件中
	//4. 删除资源
	DeleteMetaFile(hMetaFile);*/

	CRect rect;
	GetClientRect(&rect);
	//将源设备上下文的位图到此当前设备上下文
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &m_dcCompatible, 0, 0, SRCCOPY);
}


// CGraphicView 打印

BOOL CGraphicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGraphicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CGraphicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CGraphicView 诊断

#ifdef _DEBUG
void CGraphicView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CGraphicView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CGraphicDoc* CGraphicView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicDoc)));
	return (CGraphicDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphicView 消息处理程序


void CGraphicView::OnDot()
{
	// TODO:  在此添加命令处理程序代码
	m_nDrawType = 0;
}


void CGraphicView::OnLine()
{
	// TODO:  在此添加命令处理程序代码
	m_nDrawType = 1;
}


void CGraphicView::OnRectangle()
{
	// TODO:  在此添加命令处理程序代码
	m_nDrawType = 2;
}


void CGraphicView::OnEllipse()
{
	// TODO:  在此添加命令处理程序代码
	m_nDrawType = 3;
}


void CGraphicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	m_ptOrigin = point;
	CScrollView::OnLButtonDown(nFlags, point);
}


void CGraphicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	dc.SelectObject(&pen);
	//m_dcMetaFile.SelectObject(&pen);

	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	dc.SelectObject(pBrush);
	//m_dcMetaFile.SelectObject(CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)));

	if (!m_dcCompatible.m_hDC)
	{
		m_dcCompatible.CreateCompatibleDC(&dc);		//创建兼容DC
		CRect rect;
		GetClientRect(&rect);

		CBitmap bitmap;
		bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());	//初始化兼容位图

		m_dcCompatible.SelectObject(&bitmap);	//将原DC设备选入兼容DC中
		//将位图的颜色等资源选入兼容DC中
		m_dcCompatible.BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);
		m_dcCompatible.SelectObject(&pen);
		m_dcCompatible.SelectObject(pBrush);
	}
	
	switch (m_nDrawType)
	{
	case 0:
		dc.SetPixel(point, RGB(255, 0, 0));
		m_dcCompatible.SetPixel(point, RGB(255, 0, 0));
		//m_dcMetaFile.SetPixel(point, RGB(255, 0, 0));
		break;
	case 1:
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		m_dcCompatible.MoveTo(m_ptOrigin);
		m_dcCompatible.LineTo(point);
		//m_dcMetaFile.MoveTo(m_ptOrigin);
		//m_dcMetaFile.LineTo(point);
		break;
	case 2:
		dc.Rectangle(CRect(m_ptOrigin, point));
		m_dcCompatible.Rectangle(CRect(m_ptOrigin, point));
		//m_dcMetaFile.Rectangle(CRect(m_ptOrigin, point));
		break;
	case 3:
		dc.Ellipse(CRect(m_ptOrigin, point));
		m_dcCompatible.Ellipse(CRect(m_ptOrigin, point));
		//m_dcMetaFile.Ellipse(CRect(m_ptOrigin, point));
		break;
	default:
		break;
	}

	/*OnPrepareDC(&dc);	//防止图像错位
	dc.DPtoLP(&m_ptOrigin);		//将组件坐标转为逻辑坐标
	dc.DPtoLP(&point);

	//内存对象, 会析构
	//CGraph graph(m_nDrawType, m_ptOrigin, point);	//创建画图对象
	CGraph *pGraph = new CGraph(m_nDrawType, m_ptOrigin, point);	//堆内存, 应用程序结束发生析构
	m_ptrArray.Add(pGraph);		//添加进集合中*/

	CScrollView::OnLButtonUp(nFlags, point);
}


void CGraphicView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	SetScrollSizes(MM_TEXT, CSize(1200, 1000));
}


void CGraphicView::OnFileSave()
{
	// TODO:  在此添加命令处理程序代码
	HMETAFILE hmf;
	hmf = m_dcMetaFile.Close();
	CopyMetaFile(hmf, "meta.wmf");	//保存到文件中
	m_dcMetaFile.Create();
	DeleteMetaFile(hmf);
}


void CGraphicView::OnFileOpen()
{
	// TODO:  在此添加命令处理程序代码
	HMETAFILE hmf;
	hmf = GetMetaFile("meta.wmf");	//打开元文件
	m_dcMetaFile.PlayMetaFile(hmf);
	DeleteMetaFile(hmf);
	Invalidate();	//引起窗口重绘, 画出图形
}
