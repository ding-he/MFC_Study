
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include "afxext.h"
#include "afxcmn.h"

#define UM_PROGRESS		WM_USER + 1

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CToolBar          m_wndToolBar;
public:
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//afx_msg LRESULT OnProgress();
	afx_msg LRESULT OnProgress(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

private:
	HICON m_hIcons[3];
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	CToolBar m_newToolBar;
public:
	afx_msg void OnViewNewtoolbar();
	afx_msg void OnUpdateViewNewtoolbar(CCmdUI *pCmdUI);
private:
	CProgressCtrl m_progress;
protected:
	//afx_msg LRESULT OnProgress(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnPaint();
};


