// TestBtn.cpp : 实现文件
//

#include "stdafx.h"
#include "Lesson10.h"
#include "TestBtn.h"


// CTestBtn

IMPLEMENT_DYNAMIC(CTestBtn, CButton)

CTestBtn::CTestBtn()
{

}

CTestBtn::~CTestBtn()
{
}


BEGIN_MESSAGE_MAP(CTestBtn, CButton)
END_MESSAGE_MAP()



// CTestBtn 消息处理程序




void CTestBtn::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO:  添加您的代码以绘制指定项
	UINT uStyle = DFCS_BUTTONPUSH;

	// This code only works with buttons.
	ASSERT(lpDrawItemStruct->CtlType == ODT_BUTTON);

	// If drawing selected, add the pushed style to DrawFrameControl.
	if (lpDrawItemStruct->itemState & ODS_SELECTED)
		uStyle |= DFCS_PUSHED;

	// Draw the button frame.
	::DrawFrameControl(lpDrawItemStruct->hDC, &lpDrawItemStruct->rcItem,
		DFC_BUTTON, uStyle);

	// Get the button's text.
	CString strText;
	GetWindowText(strText);

	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);

	CBrush brush(RGB(0, 0, 255));
	dc.FillRect(&lpDrawItemStruct->rcItem, &brush);	//按键背景颜色
	// Draw the button text using the text color red.
	COLORREF crOldColor = ::SetTextColor(lpDrawItemStruct->hDC, RGB(255, 0, 0));		//文字颜色
	::SetBkColor(lpDrawItemStruct->hDC, RGB(0, 255, 0));		//文字背景颜色
	::DrawText(lpDrawItemStruct->hDC, strText, strText.GetLength(),
		&lpDrawItemStruct->rcItem, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	::SetTextColor(lpDrawItemStruct->hDC, crOldColor);

}
