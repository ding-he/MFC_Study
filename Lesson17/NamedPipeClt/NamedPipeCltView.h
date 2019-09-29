
// NamedPipeCltView.h : CNamedPipeCltView ��Ľӿ�
//

#pragma once


class CNamedPipeCltView : public CView
{
protected: // �������л�����
	CNamedPipeCltView();
	DECLARE_DYNCREATE(CNamedPipeCltView)

// ����
public:
	CNamedPipeCltDoc* GetDocument() const;

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
	virtual ~CNamedPipeCltView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPipeConnect();
	afx_msg void OnPipeRead();
	afx_msg void OnPipeWrite();
private:
	HANDLE hPipe;
};

#ifndef _DEBUG  // NamedPipeCltView.cpp �еĵ��԰汾
inline CNamedPipeCltDoc* CNamedPipeCltView::GetDocument() const
   { return reinterpret_cast<CNamedPipeCltDoc*>(m_pDocument); }
#endif

