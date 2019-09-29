
// Lesson08_PropView.cpp : CLesson08_PropView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Lesson08_Prop.h"
#endif

#include "Lesson08_PropDoc.h"
#include "Lesson08_PropView.h"
#include "PropSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLesson08_PropView

IMPLEMENT_DYNCREATE(CLesson08_PropView, CView)

BEGIN_MESSAGE_MAP(CLesson08_PropView, CView)
	ON_COMMAND(IDM_PROPERTYSHEET, &CLesson08_PropView::OnPropertysheet)
END_MESSAGE_MAP()

// CLesson08_PropView ����/����

CLesson08_PropView::CLesson08_PropView()
	: m_iOccupation(-1)
	, m_strWorkAddr(_T(""))
	, m_strSalary(_T(""))
{
	// TODO:  �ڴ˴���ӹ������
	memset(m_bLike, 0, sizeof(m_bLike));//�ڴ�������
}

CLesson08_PropView::~CLesson08_PropView()
{
}

BOOL CLesson08_PropView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLesson08_PropView ����

void CLesson08_PropView::OnDraw(CDC* pDC)
{
	CLesson08_PropDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CFont font;
	font.CreatePointFont(300, "�����п�");

	CFont *pOldFont = pDC->SelectObject(&font);

	CString strTemp;
	strTemp = "���ְҵ: ";
	switch (m_iOccupation)
	{
	case 0:
		strTemp += "����Ա";
		break;
	case 1:
		strTemp += "��ʦ";
		break;
	case 2:
		strTemp += "ҽ��";
		break;
	default:
		break;
	}

	pDC->TextOutA(0, 0, strTemp);

	strTemp = "��Ĺ����ص�: ";
	strTemp += m_strWorkAddr;

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);

	pDC->TextOutA(0, tm.tmHeight, strTemp);

	strTemp = "�����Ȥ����: ";
	if (m_bLike[0])
	{
		strTemp += "���� ";
	}
	if (m_bLike[1])
	{
		strTemp += "���� ";
	}
	if (m_bLike[2])
	{
		strTemp += "��Ϸ ";
	}
	if (m_bLike[3])
	{
		strTemp += "��Ӿ ";
	}
	pDC->TextOutA(0, tm.tmHeight * 2, strTemp);

	strTemp = "���н��ˮƽ: ";
	strTemp += m_strSalary;

	pDC->TextOutA(0, tm.tmHeight * 3, strTemp);

	pDC->SelectObject(pOldFont);
}


// CLesson08_PropView ���

#ifdef _DEBUG
void CLesson08_PropView::AssertValid() const
{
	CView::AssertValid();
}

void CLesson08_PropView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson08_PropDoc* CLesson08_PropView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson08_PropDoc)));
	return (CLesson08_PropDoc*)m_pDocument;
}
#endif //_DEBUG


// CLesson08_PropView ��Ϣ�������


void CLesson08_PropView::OnPropertysheet()
{
	// TODO:  �ڴ���������������
	CPropSheet propSheet("����");
	propSheet.SetWizardMode();
	if (ID_WIZFINISH == propSheet.DoModal())
	{
		m_iOccupation = propSheet.m_prop1.m_occupation;
		m_strWorkAddr = propSheet.m_prop1.m_workAddr;
		m_bLike[0] = propSheet.m_prop2.m_basketball;
		m_bLike[1] = propSheet.m_prop2.m_football;
		m_bLike[2] = propSheet.m_prop2.m_game;
		m_bLike[3] = propSheet.m_prop2.m_swim;
		m_strSalary = propSheet.m_prop3.m_strSalary;
		Invalidate();
	}
}
