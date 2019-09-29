
// MailSlotCltView.h : CMailSlotCltView ��Ľӿ�
//

#pragma once


class CMailSlotCltView : public CView
{
protected: // �������л�����
	CMailSlotCltView();
	DECLARE_DYNCREATE(CMailSlotCltView)

// ����
public:
	CMailSlotCltDoc* GetDocument() const;

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
	virtual ~CMailSlotCltView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMailslotSend();
};

#ifndef _DEBUG  // MailSlotCltView.cpp �еĵ��԰汾
inline CMailSlotCltDoc* CMailSlotCltView::GetDocument() const
   { return reinterpret_cast<CMailSlotCltDoc*>(m_pDocument); }
#endif

