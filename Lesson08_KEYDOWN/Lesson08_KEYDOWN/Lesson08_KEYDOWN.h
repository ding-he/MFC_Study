
// Lesson08_KEYDOWN.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CLesson08_KEYDOWNApp: 
// 有关此类的实现，请参阅 Lesson08_KEYDOWN.cpp
//

class CLesson08_KEYDOWNApp : public CWinApp
{
public:
	CLesson08_KEYDOWNApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
public:
	HWND m_hwndDlg;
	virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg);
};

extern CLesson08_KEYDOWNApp theApp;