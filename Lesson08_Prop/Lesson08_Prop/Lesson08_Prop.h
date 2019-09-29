
// Lesson08_Prop.h : Lesson08_Prop 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CLesson08_PropApp:
// 有关此类的实现，请参阅 Lesson08_Prop.cpp
//

class CLesson08_PropApp : public CWinApp
{
public:
	CLesson08_PropApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLesson08_PropApp theApp;
