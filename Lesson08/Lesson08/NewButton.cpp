// NewButton.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Lesson08.h"
#include "NewButton.h"


// CNewButton

IMPLEMENT_DYNAMIC(CNewButton, CButton)

CNewButton::CNewButton()
: m_pBtn(NULL)
{

}

CNewButton::~CNewButton()
{
}


BEGIN_MESSAGE_MAP(CNewButton, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CNewButton ��Ϣ�������




void CNewButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ShowWindow(SW_HIDE);//���ر���
	m_pBtn->ShowWindow(SW_SHOW);//��ʾ��һ��
	CButton::OnMouseMove(nFlags, point);
}
