
// NamedPipeSrvView.cpp : CNamedPipeSrvView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "NamedPipeSrv.h"
#endif

#include "NamedPipeSrvDoc.h"
#include "NamedPipeSrvView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNamedPipeSrvView

IMPLEMENT_DYNCREATE(CNamedPipeSrvView, CView)

BEGIN_MESSAGE_MAP(CNamedPipeSrvView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_PIPE_CREATE, &CNamedPipeSrvView::OnPipeCreate)
	ON_COMMAND(IDM_PIPE_READ, &CNamedPipeSrvView::OnPipeRead)
	ON_COMMAND(IDM_PIPE_WRITE, &CNamedPipeSrvView::OnPipeWrite)
END_MESSAGE_MAP()

// CNamedPipeSrvView 构造/析构

CNamedPipeSrvView::CNamedPipeSrvView()
{
	// TODO:  在此处添加构造代码
	hPipe = NULL;
}

CNamedPipeSrvView::~CNamedPipeSrvView()
{
	if (hPipe)
		CloseHandle(hPipe);
}

BOOL CNamedPipeSrvView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CNamedPipeSrvView 绘制

void CNamedPipeSrvView::OnDraw(CDC* /*pDC*/)
{
	CNamedPipeSrvDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CNamedPipeSrvView 打印

BOOL CNamedPipeSrvView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CNamedPipeSrvView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CNamedPipeSrvView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CNamedPipeSrvView 诊断

#ifdef _DEBUG
void CNamedPipeSrvView::AssertValid() const
{
	CView::AssertValid();
}

void CNamedPipeSrvView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNamedPipeSrvDoc* CNamedPipeSrvView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNamedPipeSrvDoc)));
	return (CNamedPipeSrvDoc*)m_pDocument;
}
#endif //_DEBUG


// CNamedPipeSrvView 消息处理程序


void CNamedPipeSrvView::OnPipeCreate()
{
	// TODO:  在此添加命令处理程序代码
	hPipe = CreateNamedPipe("\\\\.\\pipe\\MyPipe", PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED, 0, 1, 1024, 1024, 0, NULL);
	if (INVALID_HANDLE_VALUE == hPipe)
	{
		MessageBox("创建命名管道失败");
		hPipe = NULL;
		return;
	}

	HANDLE hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);		//创建人工重置对象

	if (!hEvent)
	{
		MessageBox("创建事件对象失败");
		CloseHandle(hEvent);
		hEvent = NULL;
		return;
	}

	OVERLAPPED ol;
	ZeroMemory(&ol, sizeof(OVERLAPPED));		//必要的一步, 防止随机数扰乱程序运行
	ol.hEvent = hEvent;
	if (!ConnectNamedPipe(hPipe, &ol))			//等待连接
	{
		if (ERROR_IO_PENDING != GetLastError())	//不是此错误
		{
			MessageBox("等待连接失败");
			CloseHandle(hPipe);
			CloseHandle(hEvent);
			hPipe = NULL;
			return;
		}
	}

	if (WAIT_FAILED == WaitForSingleObject(hEvent, INFINITE))
	{
		MessageBox("等待对象失败");
		CloseHandle(hPipe);
		CloseHandle(hEvent);
		hPipe = NULL;
		return;
	}

	CloseHandle(hEvent);						//关闭事件对象
}


void CNamedPipeSrvView::OnPipeRead()
{
	// TODO:  在此添加命令处理程序代码
	char buf[100];
	DWORD dwRead;
	if (!ReadFile(hPipe, buf, 100, &dwRead, NULL))
	{
		MessageBox("读取数据失败");
		return;
	}
	MessageBox(buf);
}


void CNamedPipeSrvView::OnPipeWrite()
{
	// TODO:  在此添加命令处理程序代码
	char buf[] = "this is servers";
	DWORD dwWrite;
	if (!WriteFile(hPipe, buf, strlen(buf) + 1, &dwWrite, NULL))
	{
		MessageBox("写入数据失败");
		return;
	}
}
