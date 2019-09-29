
// GraphicView.h : CGraphicView ��Ľӿ�
//

#pragma once
#include "atltypes.h"
#include "afxcoll.h"
#include "afxext.h"
#include "afxwin.h"


class CGraphicView : public CScrollView
{
protected: // �������л�����
	CGraphicView();
	DECLARE_DYNCREATE(CGraphicView)

// ����
public:
	CGraphicDoc* GetDocument() const;

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
	virtual ~CGraphicView();
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

#ifndef _DEBUG  // GraphicView.cpp �еĵ��԰汾
inline CGraphicDoc* CGraphicView::GetDocument() const
   { return reinterpret_cast<CGraphicDoc*>(m_pDocument); }
#endif

