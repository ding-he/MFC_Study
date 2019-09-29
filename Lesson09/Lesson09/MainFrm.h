
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "afxext.h"
#include "afxcmn.h"

#define UM_PROGRESS		WM_USER + 1

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
public:
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
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


