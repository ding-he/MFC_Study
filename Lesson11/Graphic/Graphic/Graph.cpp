#include "stdafx.h"
#include "Graph.h"


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