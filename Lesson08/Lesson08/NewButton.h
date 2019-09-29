#pragma once


// CNewButton

class CNewButton : public CButton
{
	DECLARE_DYNAMIC(CNewButton)

public:
	CNewButton();
	virtual ~CNewButton();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CNewButton *m_pBtn;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};


