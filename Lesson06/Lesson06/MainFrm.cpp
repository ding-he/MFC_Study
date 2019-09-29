
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "Lesson06.h"

#include "MainFrm.h"
#include "Lesson06Doc.h"
#include "Lesson06View.h"

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
//	ON_COMMAND(IDM_TEST, &CMainFrame::OnTest)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, &CMainFrame::OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, &CMainFrame::OnUpdateFileNew)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_SHOW, &CMainFrame::OnShow)
	ON_COMMAND(IDM_HELLO, &CMainFrame::OnHello)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO:  在此添加成员初始化代码
	//m_bAutoMenuEnable = FALSE;
}

CMainFrame::~CMainFrame()
{
}

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
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO:  如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//GetMenu()->GetSubMenu(0)->CheckMenuItem(0, MF_CHECKED | MF_BYPOSITION);//文件-新建
	//GetMenu()->GetSubMenu(0)->CheckMenuItem(ID_FILE_NEW, MF_CHECKED | MF_BYCOMMAND);//文件-新建
	//GetMenu()->GetSubMenu(0)->SetDefaultItem(ID_FILE_OPEN, FALSE);
	//GetMenu()->GetSubMenu(0)->SetDefaultItem(1, TRUE);

/*	static CBitmap bitmap;	//不能设置为局部变量, 或者设置为view的成员变量
	bitmap.LoadBitmapW(IDB_BITMAP1);

	//获取菜单位图像素
	CString str;
	str.Format(_T("x = %d, y = %d"), GetSystemMetrics(SM_CXMENUCHECK), GetSystemMetrics(SM_CYMENUCHECK));
	MessageBox(str);		//x = 19, y = 19

	GetMenu()->GetSubMenu(0)->SetMenuItemBitmaps(0, MF_BYPOSITION, &bitmap, &bitmap);

	//设置禁用
	GetMenu()->GetSubMenu(0)->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);

	SetMenu(NULL);	//设置菜单
	/*static*/ CMenu menu;
/*	menu.LoadMenuW(IDR_MAINFRAME);
	SetMenu(&menu);
	menu.Detach();//菜单句柄和菜单对象分离, 因menu是一个局部变量
*/
/*	CMenu m;
	m.CreateMenu();
	//GetMenu()->AppendMenuW(MF_POPUP, (UINT)m.m_hMenu, _T("test"));
	GetMenu()->InsertMenuW(2, MF_POPUP | MF_BYPOSITION, (UINT)m.m_hMenu, _T("test"));
	m.AppendMenuW(MF_STRING, 101, _T("Hello"));
	m.AppendMenuW(MF_STRING, 102, _T("World"));
	m.AppendMenuW(MF_STRING, 103, _T("!"));
	m.Detach();

	GetMenu()->GetSubMenu(0)->AppendMenuW(MF_STRING, 104, _T("Hello World!"));
	GetMenu()->GetSubMenu(0)->InsertMenuW(2, MF_BYPOSITION | MF_STRING, 104, _T("Hello World!"));

	//删除
	GetMenu()->DeleteMenu(1, MF_BYPOSITION);
	GetMenu()->GetSubMenu(0)->DeleteMenu(1, MF_BYPOSITION);
*/
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

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



//void CMainFrame::OnTest()
//{
//	// TODO:  在此添加命令处理程序代码
//	MessageBox(_T("MainFrame Clicked"));
//}


void CMainFrame::OnUpdateEditCopy(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	//if (ID_EDIT_COPY == pCmdUI->m_nID)
	//if (3 == pCmdUI->m_nIndex)//索引
		pCmdUI->Enable();
}


void CMainFrame::OnUpdateFileNew(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	//if (ID_FILE_NEW == pCmdUI->m_nID)//哪个菜单项的命令更新, ID就是哪个菜单项的
	if (0 == pCmdUI->m_nIndex)//索引
		pCmdUI->Enable(FALSE);
}


void CMainFrame::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//不能加在CMainFrame类中
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);

	CMenu *pPopup = menu.GetSubMenu(0);

	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);//显示右键

	CFrameWnd::OnRButtonDown(nFlags, point);
}


void CMainFrame::OnShow()
{
	// TODO:  在此添加命令处理程序代码
	MessageBox(_T("Main Show"));
}

void CMainFrame::OnHello()
{
	MessageBox(_T("Hello World"));
}

BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO:  在此添加专用代码和/或调用基类
	int MenuCmdID = LOWORD(wParam);
	CLesson06View *pView = (CLesson06View *)GetActiveView();

	if (MenuCmdID >= IDM_PHONE1 && MenuCmdID < IDM_PHONE1 + pView->m_strArray.GetSize())
	{
		//MessageBox(_T("Test"));
		CClientDC dc(pView);
		dc.TextOutW(0, 0, pView->m_strArray.GetAt(MenuCmdID - IDM_PHONE1));
		return TRUE;
	}

	return CFrameWnd::OnCommand(wParam, lParam);
}
