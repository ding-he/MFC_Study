
// Lesson10View.h : CLesson10View 类的接口
//

#pragma once
#include "atltypes.h"
#include "afxwin.h"


class CLesson10View : public CView
{
protected: // 仅从序列化创建
	CLesson10View();
	DECLARE_DYNCREATE(CLesson10View)

// 特性
public:
	CLesson10Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CLesson10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDot();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnEllipse();
private:
	UINT m_nDrawType;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	CPoint m_ptOrigin;
public:
	afx_msg void OnSetting();
private:
	UINT m_nLineWidth;
	int m_nLineStyle;
public:
	afx_msg void OnColor();
private:
	COLORREF m_color;
public:
	afx_msg void OnFont();
private:
	CFont m_font;
	CString m_strFontName;
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // Lesson10View.cpp 中的调试版本
inline CLesson10Doc* CLesson10View::GetDocument() const
   { return reinterpret_cast<CLesson10Doc*>(m_pDocument); }
#endif

