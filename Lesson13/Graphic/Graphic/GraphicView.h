
// GraphicView.h : CGraphicView 类的接口
//

#pragma once
#include "atltypes.h"
#include "afxcoll.h"
#include "afxext.h"
#include "afxwin.h"


class CGraphicView : public CScrollView
{
protected: // 仅从序列化创建
	CGraphicView();
	DECLARE_DYNCREATE(CGraphicView)

// 特性
public:
	CGraphicDoc* GetDocument() const;

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
	virtual ~CGraphicView();
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
	int m_nDrawType;
	CPoint m_ptOrigin;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	CPtrArray m_ptrArray;
public:
	virtual void OnInitialUpdate();
private:
	CMetaFileDC m_dcMetaFile;
public:
//	afx_msg void OnFileSave();
//	afx_msg void OnFileOpen();
private:
	CDC m_dcCompatible;
public:
	afx_msg void OnFileWrite();
	afx_msg void OnFileRead();
	CObArray m_obArray;
};

#ifndef _DEBUG  // GraphicView.cpp 中的调试版本
inline CGraphicDoc* CGraphicView::GetDocument() const
   { return reinterpret_cast<CGraphicDoc*>(m_pDocument); }
#endif

