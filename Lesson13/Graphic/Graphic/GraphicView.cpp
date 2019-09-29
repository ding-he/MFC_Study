
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
//	ON_COMMAND(ID_FILE_SAVE, &CGraphicView::OnFileSave)
//	ON_COMMAND(ID_FILE_OPEN, &CGraphicView::OnFileOpen)
	ON_COMMAND(IDM_FILE_WRITE, &CGraphicView::OnFileWrite)
	ON_COMMAND(IDM_FILE_READ, &CGraphicView::OnFileRead)
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
	int nCount = pDoc->m_obArray.GetSize();
	for (int i = 0; i < nCount; i++)
	{
		//((CGraph*)m_obArray.GetAt(i))->Draw(pDC);
		((CGraph*)pDoc->m_obArray.GetAt(i))->Draw(pDC);
	}
	
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

	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	dc.SelectObject(pBrush);

	
	switch (m_nDrawType)
	{
	case 0:
		dc.SetPixel(point, RGB(255, 0, 0));
		break;
	case 1:
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		break;
	case 2:
		dc.Rectangle(CRect(m_ptOrigin, point));
		break;
	case 3:
		dc.Ellipse(CRect(m_ptOrigin, point));
		break;
	default:
		break;
	}

	CGraph *pGraph = new CGraph(m_nDrawType, m_ptOrigin, point);
	//m_obArray.Add(pGraph);

	CGraphicDoc *pDoc = GetDocument();
	pDoc->m_obArray.Add(pGraph);

	CScrollView::OnLButtonUp(nFlags, point);
}


void CGraphicView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	SetScrollSizes(MM_TEXT, CSize(1200, 1000));
}


//void CGraphicView::OnFileSave()
//{
//	// TODO:  在此添加命令处理程序代码
//	HMETAFILE hmf;
//	hmf = m_dcMetaFile.Close();
//	CopyMetaFile(hmf, "meta.wmf");	//保存到文件中
//	m_dcMetaFile.Create();
//	DeleteMetaFile(hmf);
//}


//void CGraphicView::OnFileOpen()
//{
//	// TODO:  在此添加命令处理程序代码
//	HMETAFILE hmf;
//	hmf = GetMetaFile("meta.wmf");	//打开元文件
//	m_dcMetaFile.PlayMetaFile(hmf);
//	DeleteMetaFile(hmf);
//	Invalidate();	//引起窗口重绘, 画出图形
//}


void CGraphicView::OnFileWrite()
{
	// TODO:  在此添加命令处理程序代码
	//构造CFile对象
	CFile file("1.txt", CFile::modeWrite | CFile::modeCreate);
	//构造CArchive对象
	CArchive ar(&file, CArchive::store);
	int i = 12;
	char ch = 'm';
	float pi = 3.14f;
	CString str("hello world");
	//保存数据
	ar << i << ch << pi << str;
//	file.Close();	//CArchive对象自动关闭CFile对象, 不需手动调用CLose()关闭
}


void CGraphicView::OnFileRead()
{
	// TODO:  在此添加命令处理程序代码
	CFile file("1.txt", CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	int i;
	char ch;
	float pi;
	CString str;
	CString strResult;
	ar >> i >> ch >> pi >> str;		//读与写顺序保持一致
	strResult.Format("%d, %c, %f, %s", i, ch, pi, str);
	MessageBox(strResult);
//	file.Close();
}
