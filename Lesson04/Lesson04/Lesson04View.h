
// Lesson04View.h : CLesson04View 类的接口
//

#pragma once
#include "atltypes.h"


class CLesson04View : public CView
{
protected: // 仅从序列化创建
	CLesson04View();
	DECLARE_DYNCREATE(CLesson04View)

// 特性
public:
	CLesson04Doc* GetDocument() const;

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
	virtual ~CLesson04View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
private:
	CPoint m_ptOrigin;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	BOOL m_bDraw;
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
	CPoint m_ptOld;
};

#ifndef _DEBUG  // Lesson04View.cpp 中的调试版本
inline CLesson04Doc* CLesson04View::GetDocument() const
   { return reinterpret_cast<CLesson04Doc*>(m_pDocument); }
#endif

