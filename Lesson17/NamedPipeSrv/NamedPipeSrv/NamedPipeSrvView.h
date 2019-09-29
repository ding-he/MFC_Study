
// NamedPipeSrvView.h : CNamedPipeSrvView ��Ľӿ�
//

#pragma once


class CNamedPipeSrvView : public CView
{
protected: // �������л�����
	CNamedPipeSrvView();
	DECLARE_DYNCREATE(CNamedPipeSrvView)

// ����
public:
	CNamedPipeSrvDoc* GetDocument() const;

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
	virtual ~CNamedPipeSrvView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPipeCreate();
	afx_msg void OnPipeRead();
	afx_msg void OnPipeWrite();
private:
	HANDLE hPipe;
};

#ifndef _DEBUG  // NamedPipeSrvView.cpp �еĵ��԰汾
inline CNamedPipeSrvDoc* CNamedPipeSrvView::GetDocument() const
   { return reinterpret_cast<CNamedPipeSrvDoc*>(m_pDocument); }
#endif

