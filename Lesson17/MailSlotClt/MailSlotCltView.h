
// MailSlotCltView.h : CMailSlotCltView 类的接口
//

#pragma once


class CMailSlotCltView : public CView
{
protected: // 仅从序列化创建
	CMailSlotCltView();
	DECLARE_DYNCREATE(CMailSlotCltView)

// 特性
public:
	CMailSlotCltDoc* GetDocument() const;

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
	virtual ~CMailSlotCltView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMailslotSend();
};

#ifndef _DEBUG  // MailSlotCltView.cpp 中的调试版本
inline CMailSlotCltDoc* CMailSlotCltView::GetDocument() const
   { return reinterpret_cast<CMailSlotCltDoc*>(m_pDocument); }
#endif

