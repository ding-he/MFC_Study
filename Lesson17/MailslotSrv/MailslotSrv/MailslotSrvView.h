
// MailslotSrvView.h : CMailslotSrvView ��Ľӿ�
//

#pragma once


class CMailslotSrvView : public CView
{
protected: // �������л�����
	CMailslotSrvView();
	DECLARE_DYNCREATE(CMailslotSrvView)

// ����
public:
	CMailslotSrvDoc* GetDocument() const;

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
	virtual ~CMailslotSrvView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMailslotRecv();
};

#ifndef _DEBUG  // MailslotSrvView.cpp �еĵ��԰汾
inline CMailslotSrvDoc* CMailslotSrvView::GetDocument() const
   { return reinterpret_cast<CMailslotSrvDoc*>(m_pDocument); }
#endif

