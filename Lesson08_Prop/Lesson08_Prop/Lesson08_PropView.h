
// Lesson08_PropView.h : CLesson08_PropView 类的接口
//

#pragma once


class CLesson08_PropView : public CView
{
protected: // 仅从序列化创建
	CLesson08_PropView();
	DECLARE_DYNCREATE(CLesson08_PropView)

// 特性
public:
	CLesson08_PropDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CLesson08_PropView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPropertysheet();
private:
	int m_iOccupation;
	CString m_strWorkAddr;
	BOOL m_bLike[4];
	CString m_strSalary;
};

#ifndef _DEBUG  // Lesson08_PropView.cpp 中的调试版本
inline CLesson08_PropDoc* CLesson08_PropView::GetDocument() const
   { return reinterpret_cast<CLesson08_PropDoc*>(m_pDocument); }
#endif

