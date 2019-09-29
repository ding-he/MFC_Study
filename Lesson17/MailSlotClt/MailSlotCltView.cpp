
// MailSlotCltView.cpp : CMailSlotCltView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MailSlotClt.h"
#endif

#include "MailSlotCltDoc.h"
#include "MailSlotCltView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMailSlotCltView

IMPLEMENT_DYNCREATE(CMailSlotCltView, CView)

BEGIN_MESSAGE_MAP(CMailSlotCltView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_MAILSLOT_SEND, &CMailSlotCltView::OnMailslotSend)
END_MESSAGE_MAP()

// CMailSlotCltView 构造/析构

CMailSlotCltView::CMailSlotCltView()
{
	// TODO:  在此处添加构造代码

}

CMailSlotCltView::~CMailSlotCltView()
{
}

BOOL CMailSlotCltView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMailSlotCltView 绘制

void CMailSlotCltView::OnDraw(CDC* /*pDC*/)
{
	CMailSlotCltDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMailSlotCltView 打印

BOOL CMailSlotCltView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMailSlotCltView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMailSlotCltView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMailSlotCltView 诊断

#ifdef _DEBUG
void CMailSlotCltView::AssertValid() const
{
	CView::AssertValid();
}

void CMailSlotCltView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMailSlotCltDoc* CMailSlotCltView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMailSlotCltDoc)));
	return (CMailSlotCltDoc*)m_pDocument;
}
#endif //_DEBUG


// CMailSlotCltView 消息处理程序


void CMailSlotCltView::OnMailslotSend()
{
	// TODO:  在此添加命令处理程序代码
	//打开邮槽
	HANDLE hMailslot = CreateFile("\\\\.\\mailslot\\MyMailslot", GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hMailslot)
	{
		MessageBox("打开邮槽失败");
		return;
	}

	char buf[] = "hello world";
	DWORD dwSend;
	if (!WriteFile(hMailslot, buf, strlen(buf) + 1, &dwSend, NULL))		//写数据
	{
		MessageBox("写入失败");
		CloseHandle(hMailslot);
		return;
	}
	CloseHandle(hMailslot);
}
