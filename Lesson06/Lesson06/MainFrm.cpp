
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
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
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO:  �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//GetMenu()->GetSubMenu(0)->CheckMenuItem(0, MF_CHECKED | MF_BYPOSITION);//�ļ�-�½�
	//GetMenu()->GetSubMenu(0)->CheckMenuItem(ID_FILE_NEW, MF_CHECKED | MF_BYCOMMAND);//�ļ�-�½�
	//GetMenu()->GetSubMenu(0)->SetDefaultItem(ID_FILE_OPEN, FALSE);
	//GetMenu()->GetSubMenu(0)->SetDefaultItem(1, TRUE);

/*	static CBitmap bitmap;	//��������Ϊ�ֲ�����, ��������Ϊview�ĳ�Ա����
	bitmap.LoadBitmapW(IDB_BITMAP1);

	//��ȡ�˵�λͼ����
	CString str;
	str.Format(_T("x = %d, y = %d"), GetSystemMetrics(SM_CXMENUCHECK), GetSystemMetrics(SM_CYMENUCHECK));
	MessageBox(str);		//x = 19, y = 19

	GetMenu()->GetSubMenu(0)->SetMenuItemBitmaps(0, MF_BYPOSITION, &bitmap, &bitmap);

	//���ý���
	GetMenu()->GetSubMenu(0)->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);

	SetMenu(NULL);	//���ò˵�
	/*static*/ CMenu menu;
/*	menu.LoadMenuW(IDR_MAINFRAME);
	SetMenu(&menu);
	menu.Detach();//�˵�����Ͳ˵��������, ��menu��һ���ֲ�����
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

	//ɾ��
	GetMenu()->DeleteMenu(1, MF_BYPOSITION);
	GetMenu()->GetSubMenu(0)->DeleteMenu(1, MF_BYPOSITION);
*/
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ�������



//void CMainFrame::OnTest()
//{
//	// TODO:  �ڴ���������������
//	MessageBox(_T("MainFrame Clicked"));
//}


void CMainFrame::OnUpdateEditCopy(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	//if (ID_EDIT_COPY == pCmdUI->m_nID)
	//if (3 == pCmdUI->m_nIndex)//����
		pCmdUI->Enable();
}


void CMainFrame::OnUpdateFileNew(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	//if (ID_FILE_NEW == pCmdUI->m_nID)//�ĸ��˵�����������, ID�����ĸ��˵����
	if (0 == pCmdUI->m_nIndex)//����
		pCmdUI->Enable(FALSE);
}


void CMainFrame::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//���ܼ���CMainFrame����
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);

	CMenu *pPopup = menu.GetSubMenu(0);

	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);//��ʾ�Ҽ�

	CFrameWnd::OnRButtonDown(nFlags, point);
}


void CMainFrame::OnShow()
{
	// TODO:  �ڴ���������������
	MessageBox(_T("Main Show"));
}

void CMainFrame::OnHello()
{
	MessageBox(_T("Hello World"));
}

BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO:  �ڴ����ר�ô����/����û���
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
