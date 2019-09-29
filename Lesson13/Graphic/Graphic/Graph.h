#pragma once
#include "atltypes.h"
class CGraph : public CObject
{
	DECLARE_SERIAL(CGraph)
public:
	CGraph();
	CGraph(int m_nDrawType, CPoint m_ptOrigin, CPoint m_ptEnd);
	~CGraph();
	int m_nDrawType;
	CPoint m_ptOrigin;
	CPoint m_ptEnd;
	
	virtual void Serialize(CArchive& ar);
//	virtual void AssertValid() const;
	void Draw(CDC* pDC);
};

