
// Lesson10View.h : CLesson10View ��Ľӿ�
//

#pragma once
#include "atltypes.h"
#include "afxwin.h"


class CLesson10View : public CView
{
protected: // �������л�����
	CLesson10View();
	DECLARE_DYNCREATE(CLesson10View)

// ����
public:
	CLesson10Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CLesson10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // Lesson10View.cpp �еĵ��԰汾
inline CLesson10Doc* CLesson10View::GetDocument() const
   { return reinterpret_cast<CLesson10Doc*>(m_pDocument); }
#endif

