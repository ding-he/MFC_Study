#include "stdafx.h"
#include "Graph.h"

IMPLEMENT_SERIAL(CGraph, CObject, 1)

CGraph::CGraph()
	: m_nDrawType(-1)
	, m_ptOrigin(0)
	, m_ptEnd(0)
{
}


CGraph::~CGraph()
{
}

CGraph::CGraph(int m_nDrawType, CPoint m_ptOrigin, CPoint m_ptEnd)
{
	this->m_nDrawType = m_nDrawType;
	this->m_ptOrigin = m_ptOrigin;
	this->m_ptEnd = m_ptEnd;
}

void CGraph::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar << m_nDrawType << m_ptOrigin << m_ptEnd;
	}
	else
	{	// loading code
		ar >> m_nDrawType >> m_ptOrigin >> m_ptEnd;
	}
}


//void CGraph::AssertValid() const
//{
//	CObject::AssertValid();
//
//	// TODO:  在此添加专用代码和/或调用基类
//}


void CGraph::Draw(CDC* pDC)
{
	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush = pDC->SelectObject(pBrush);
	switch (m_nDrawType)
	{
	case 0:
		pDC->SetPixel(m_ptEnd, RGB(255, 0, 0));
		break;
	case 1:
		pDC->MoveTo(m_ptOrigin);
		pDC->LineTo(m_ptEnd);
		break;
	case 2:
		pDC->Rectangle(CRect(m_ptOrigin, m_ptEnd));
		break;
	case 3:
		pDC->Ellipse(CRect(m_ptOrigin, m_ptEnd));
		break;
	default:
		break;
	}
	pDC->SelectObject(pOldBrush);
}
