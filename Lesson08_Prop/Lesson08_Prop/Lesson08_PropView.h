
// Lesson08_PropView.h : CLesson08_PropView ��Ľӿ�
//

#pragma once


class CLesson08_PropView : public CView
{
protected: // �������л�����
	CLesson08_PropView();
	DECLARE_DYNCREATE(CLesson08_PropView)

// ����
public:
	CLesson08_PropDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CLesson08_PropView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // Lesson08_PropView.cpp �еĵ��԰汾
inline CLesson08_PropDoc* CLesson08_PropView::GetDocument() const
   { return reinterpret_cast<CLesson08_PropDoc*>(m_pDocument); }
#endif

