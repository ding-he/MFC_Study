
// Lesson05View.h : CLesson05View ��Ľӿ�
//

#pragma once
#include "afxwin.h"


class CLesson05View : public CView
{
protected: // �������л�����
	CLesson05View();
	DECLARE_DYNCREATE(CLesson05View)

// ����
public:
	CLesson05Doc* GetDocument() const;

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
	virtual ~CLesson05View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	CBitmap bitmap;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CString m_strLine;
	CPoint m_ptOrigin;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	int m_nWidth;
};

#ifndef _DEBUG  // Lesson05View.cpp �еĵ��԰汾
inline CLesson05Doc* CLesson05View::GetDocument() const
   { return reinterpret_cast<CLesson05Doc*>(m_pDocument); }
#endif

