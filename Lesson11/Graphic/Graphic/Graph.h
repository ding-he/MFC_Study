#pragma once
#include "atltypes.h"
class CGraph
{
public:
	CGraph();
	CGraph(int m_nDrawType, CPoint m_ptOrigin, CPoint m_ptEnd);
	~CGraph();
	int m_nDrawType;
	CPoint m_ptOrigin;
	CPoint m_ptEnd;
};

