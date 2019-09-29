
// Lesson06View.h : CLesson06View 类的接口
//

#pragma once
#include "afxwin.h"
#include "afxcoll.h"


class CLesson06View : public CView
{
protected: // 仅从序列化创建
	CLesson06View();
	DECLARE_DYNCREATE(CLesson06View)

// 特性
public:
	CLesson06Doc* GetDocument() const;

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
	virtual ~CLesson06View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnTest();
	afx_msg void OnTest();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnShow();
private:
	int m_nIndex;
	CMenu m_menu;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	CString m_strLine;
public:
	CStringArray m_strArray;
	afx_msg void OnPhone1();
	afx_msg void OnPhone2();
	afx_msg void OnPhone3();
	afx_msg void OnPhone4();
};

#ifndef _DEBUG  // Lesson06View.cpp 中的调试版本
inline CLesson06Doc* CLesson06View::GetDocument() const
   { return reinterpret_cast<CLesson06Doc*>(m_pDocument); }
#endif

