
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "Lesson09.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(IDM_VIEW_NEWTOOLBAR, &CMainFrame::OnViewNewtoolbar)
	ON_UPDATE_COMMAND_UI(IDM_VIEW_NEWTOOLBAR, &CMainFrame::OnUpdateViewNewtoolbar)
	//ON_MESSAGE(UM_PROGRESS, &CMainFrame::OnProgress)
	ON_MESSAGE(UM_PROGRESS, &CMainFrame::OnProgress)
	ON_WM_PAINT()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	IDS_TIMER,
	IDS_PROGRESS,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO:  在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

extern CLesson09App theApp;
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

	// TODO:  如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	SetWindowLong(m_hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);
	SetWindowLong(m_hWnd, GWL_STYLE, GetWindowLong(m_hWnd, GWL_STYLE) & ~WS_MAXIMIZEBOX);

	SetClassLong(m_hWnd, GCL_HICON, (LONG)LoadIcon(NULL, IDI_WARNING));

	m_hIcons[0] = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	m_hIcons[1] = LoadIcon(theApp.m_hInstance, MAKEINTRESOURCE(IDI_ICON2));
	m_hIcons[2] = LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON3));

	SetClassLong(m_hWnd, GCL_HICON, (LONG)m_hIcons[0]);
	SetTimer(1, 1000, NULL);

	if (!m_newToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_RIGHT | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_newToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	m_newToolBar.EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_newToolBar);

	//GetMenu()->GetSubMenu(2)->CheckMenuItem(2, MF_BYPOSITION | MF_CHECKED);

	CTime time = CTime::GetCurrentTime();
	CString strTime = time.Format("%H:%M:%S");
	CClientDC dc(this);

	CSize sz = dc.GetTextExtent(strTime);

	int index = m_wndStatusBar.CommandToIndex(IDS_TIMER);//求索引
	m_wndStatusBar.SetPaneInfo(index, IDS_TIMER, SBPS_NORMAL, sz.cx);
	m_wndStatusBar.SetPaneText(index, strTime);

	//m_progress.Create(WS_CHILD | WS_VISIBLE, CRect(100, 100, 300, 120), this, 102);
	//m_progress.Create(WS_CHILD | WS_VISIBLE | PBS_VERTICAL, CRect(100, 100, 120, 300), this, 102);
	/*CRect rect;
	m_wndStatusBar.GetItemRect(2, &rect);
	m_progress.Create(WS_CHILD | WS_VISIBLE, rect, &m_wndStatusBar, 102);
	m_progress.SetPos(30);*/

	//SendMessage(UM_PROGRESS);
	//PostMessage(UM_PROGRESS);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	/*cs.cx = 800;
	cs.cy = 600;

	cs.lpszName = "Hello World!";
	//cs.style &= ~FWS_ADDTOTITLE;
	cs.style = WS_OVERLAPPEDWINDOW;*/

	/*WNDCLASS wndcls;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_HELP);
	wndcls.hIcon = LoadIcon(NULL, IDI_WARNING);
	wndcls.hInstance = AfxGetInstanceHandle();
	wndcls.lpfnWndProc = ::DefWindowProc;
	wndcls.lpszClassName = "hello";
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndcls);

	cs.lpszClass = "hello";*/

	//cs.lpszClass = AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW, 0, 0, LoadIcon(NULL, IDI_ERROR));
	//cs.lpszClass = AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW, 0, 0, 0);

	//::MessageBox((HWND)0x00030A22, "Test", "Hello", 0);
	//SetWindowLong((HWND)0x00030A22, GWL_STYLE, GetWindowLong((HWND)0x00030A22, GWL_STYLE) & ~WS_VISIBLE);
	
	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	static int index = 1;
	SetClassLong(m_hWnd, GCL_HICON, (LONG)m_hIcons[index]);
	index = ++index % 3;

	CTime time = CTime::GetCurrentTime();
	CString strTime = time.Format("%H:%M:%S");
	CClientDC dc(this);

	CSize sz = dc.GetTextExtent(strTime);

	m_wndStatusBar.SetPaneInfo(1, IDS_TIMER, SBPS_NORMAL, sz.cx);
	m_wndStatusBar.SetPaneText(1, strTime);

	m_progress.SetRange(0, 59);
	m_progress.SetStep(1);
	m_progress.StepIt();

	CFrameWnd::OnTimer(nIDEvent);
}


void CMainFrame::OnViewNewtoolbar()
{
	// TODO:  在此添加命令处理程序代码
	/*if (m_newToolBar.IsVisible())
	{
		m_newToolBar.ShowWindow(SW_HIDE);
		GetMenu()->GetSubMenu(2)->CheckMenuItem(2, MF_BYPOSITION | MF_UNCHECKED);
	}
	else
	{
		m_newToolBar.ShowWindow(SW_SHOW);
		GetMenu()->GetSubMenu(2)->CheckMenuItem(2, MF_BYPOSITION | MF_CHECKED);
	}
	RecalcLayout();
	DockControlBar(&m_newToolBar);*/

	ShowControlBar(&m_newToolBar, !m_newToolBar.IsVisible(), FALSE);
	//GetMenu()->GetSubMenu(2)->CheckMenuItem(2, MF_BYPOSITION | (m_newToolBar.IsVisible() ? MF_CHECKED : MF_UNCHECKED));
}


void CMainFrame::OnUpdateViewNewtoolbar(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_newToolBar.IsVisible());
}



afx_msg LRESULT CMainFrame::OnProgress(WPARAM wParam, LPARAM lParam)
{
	CRect rect;
	m_wndStatusBar.GetItemRect(2, &rect);
	m_progress.Create(WS_CHILD | WS_VISIBLE | PBS_SMOOTH, rect, &m_wndStatusBar, 102);
	m_progress.SetPos(30);
	return 0;
}


void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CFrameWnd::OnPaint()
	CRect rect;
	m_wndStatusBar.SetPaneInfo(2, IDS_PROGRESS, SBPS_NORMAL, 120);
	m_wndStatusBar.GetItemRect(2, &rect);
	if (!m_progress.m_hWnd)
		m_progress.Create(WS_CHILD | WS_VISIBLE | PBS_SMOOTH, rect, &m_wndStatusBar, 102);
	else
		m_progress.MoveWindow(&rect);
	//m_progress.SetPos(30);
	CTime time = CTime::GetCurrentTime();
	CString str = time.Format("%S");
	int i = atoi(str);
	m_progress.SetPos(i);
}
