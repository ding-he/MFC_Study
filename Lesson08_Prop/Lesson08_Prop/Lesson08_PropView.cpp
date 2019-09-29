
// Lesson08_PropView.cpp : CLesson08_PropView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Lesson08_Prop.h"
#endif

#include "Lesson08_PropDoc.h"
#include "Lesson08_PropView.h"
#include "PropSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLesson08_PropView

IMPLEMENT_DYNCREATE(CLesson08_PropView, CView)

BEGIN_MESSAGE_MAP(CLesson08_PropView, CView)
	ON_COMMAND(IDM_PROPERTYSHEET, &CLesson08_PropView::OnPropertysheet)
END_MESSAGE_MAP()

// CLesson08_PropView 构造/析构

CLesson08_PropView::CLesson08_PropView()
	: m_iOccupation(-1)
	, m_strWorkAddr(_T(""))
	, m_strSalary(_T(""))
{
	// TODO:  在此处添加构造代码
	memset(m_bLike, 0, sizeof(m_bLike));//内存设置数
}

CLesson08_PropView::~CLesson08_PropView()
{
}

BOOL CLesson08_PropView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLesson08_PropView 绘制

void CLesson08_PropView::OnDraw(CDC* pDC)
{
	CLesson08_PropDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	CFont font;
	font.CreatePointFont(300, "华文行楷");

	CFont *pOldFont = pDC->SelectObject(&font);

	CString strTemp;
	strTemp = "你的职业: ";
	switch (m_iOccupation)
	{
	case 0:
		strTemp += "程序员";
		break;
	case 1:
		strTemp += "教师";
		break;
	case 2:
		strTemp += "医生";
		break;
	default:
		break;
	}

	pDC->TextOutA(0, 0, strTemp);

	strTemp = "你的工作地点: ";
	strTemp += m_strWorkAddr;

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);

	pDC->TextOutA(0, tm.tmHeight, strTemp);

	strTemp = "你的兴趣爱好: ";
	if (m_bLike[0])
	{
		strTemp += "篮球 ";
	}
	if (m_bLike[1])
	{
		strTemp += "足球 ";
	}
	if (m_bLike[2])
	{
		strTemp += "游戏 ";
	}
	if (m_bLike[3])
	{
		strTemp += "游泳 ";
	}
	pDC->TextOutA(0, tm.tmHeight * 2, strTemp);

	strTemp = "你的薪资水平: ";
	strTemp += m_strSalary;

	pDC->TextOutA(0, tm.tmHeight * 3, strTemp);

	pDC->SelectObject(pOldFont);
}


// CLesson08_PropView 诊断

#ifdef _DEBUG
void CLesson08_PropView::AssertValid() const
{
	CView::AssertValid();
}

void CLesson08_PropView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson08_PropDoc* CLesson08_PropView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson08_PropDoc)));
	return (CLesson08_PropDoc*)m_pDocument;
}
#endif //_DEBUG


// CLesson08_PropView 消息处理程序


void CLesson08_PropView::OnPropertysheet()
{
	// TODO:  在此添加命令处理程序代码
	CPropSheet propSheet("属性");
	propSheet.SetWizardMode();
	if (ID_WIZFINISH == propSheet.DoModal())
	{
		m_iOccupation = propSheet.m_prop1.m_occupation;
		m_strWorkAddr = propSheet.m_prop1.m_workAddr;
		m_bLike[0] = propSheet.m_prop2.m_basketball;
		m_bLike[1] = propSheet.m_prop2.m_football;
		m_bLike[2] = propSheet.m_prop2.m_game;
		m_bLike[3] = propSheet.m_prop2.m_swim;
		m_strSalary = propSheet.m_prop3.m_strSalary;
		Invalidate();
	}
}
