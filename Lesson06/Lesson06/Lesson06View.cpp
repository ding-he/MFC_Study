
// Lesson06View.cpp : CLesson06View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Lesson06.h"
#endif

#include "Lesson06Doc.h"
#include "Lesson06View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLesson06View

IMPLEMENT_DYNCREATE(CLesson06View, CView)

BEGIN_MESSAGE_MAP(CLesson06View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_COMMAND(IDM_TEST, &CLesson06View::OnTest)
	ON_COMMAND(ID_TEST, &CLesson06View::OnTest)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_SHOW, &CLesson06View::OnShow)
	ON_WM_CHAR()
	ON_COMMAND(IDM_PHONE1, &CLesson06View::OnPhone1)
	ON_COMMAND(IDM_PHONE2, &CLesson06View::OnPhone2)
	ON_COMMAND(IDM_PHONE3, &CLesson06View::OnPhone3)
	ON_COMMAND(IDM_PHONE4, &CLesson06View::OnPhone4)
END_MESSAGE_MAP()

// CLesson06View 构造/析构

CLesson06View::CLesson06View()
	: m_nIndex(-1)
	, m_strLine(_T(""))
{
	// TODO:  在此处添加构造代码

}

CLesson06View::~CLesson06View()
{
}

BOOL CLesson06View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLesson06View 绘制

void CLesson06View::OnDraw(CDC* /*pDC*/)
{
	CLesson06Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CLesson06View 打印

BOOL CLesson06View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CLesson06View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CLesson06View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CLesson06View 诊断

#ifdef _DEBUG
void CLesson06View::AssertValid() const
{
	CView::AssertValid();
}

void CLesson06View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson06Doc* CLesson06View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson06Doc)));
	return (CLesson06Doc*)m_pDocument;
}
#endif //_DEBUG


// CLesson06View 消息处理程序


//void CLesson06View::OnTest()
//{
//	// TODO:  在此添加命令处理程序代码
//	MessageBox(_T("View Clicked"));
//}


void CLesson06View::OnTest()
{
	// TODO:  在此添加命令处理程序代码
}


void CLesson06View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);

	CMenu *pPopup = menu.GetSubMenu(0);

	ClientToScreen(&point);
	//pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);//显示右键
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, GetParent());//显示右键

	CView::OnRButtonDown(nFlags, point);
}


void CLesson06View::OnShow()
{
	// TODO:  在此添加命令处理程序代码
	MessageBox(_T("View Show"));
}


void CLesson06View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	WCHAR ch = (WCHAR)nChar;

	CClientDC dc(this);

	if (0x0d == ch)
	{
		//回车
		if (0 == ++m_nIndex)
		{
			//第一次, 添加菜单
			m_menu.CreateMenu();
			//调用父窗口CMainFrame
			GetParent()->GetMenu()->AppendMenuW(MF_POPUP, (UINT)m_menu.m_hMenu, _T("PhoneBook"));
			GetParent()->DrawMenuBar();//重绘菜单

		}
		m_strArray.Add(m_strLine);
		m_menu.AppendMenuW(MF_STRING, IDM_PHONE1 + m_nIndex, m_strLine.Left(m_strLine.Find(' ')));
		m_strLine.Empty();//清空字符串
		Invalidate();//重绘窗口, 擦除上一次的笔迹
	}
	else
	{
		m_strLine += ch;
		dc.TextOutW(0, 0, m_strLine);
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CLesson06View::OnPhone1()
{
	// TODO:  在此添加命令处理程序代码
	CClientDC dc(this);
	//Invalidate();
	dc.TextOutW(0, 0, m_strArray.GetAt(0));
}


void CLesson06View::OnPhone2()
{
	// TODO:  在此添加命令处理程序代码
	CClientDC dc(this);
	//Invalidate();
	dc.TextOutW(0, 0, m_strArray.GetAt(1));
}


void CLesson06View::OnPhone3()
{
	// TODO:  在此添加命令处理程序代码
	CClientDC dc(this);
	//Invalidate();
	dc.TextOutW(0, 0, m_strArray.GetAt(2));
}


void CLesson06View::OnPhone4()
{
	// TODO:  在此添加命令处理程序代码
	CClientDC dc(this);
	//Invalidate();
	dc.TextOutW(0, 0, m_strArray.GetAt(3));
}
