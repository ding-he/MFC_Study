
// Lesson08_Prop.h : Lesson08_Prop Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CLesson08_PropApp:
// �йش����ʵ�֣������ Lesson08_Prop.cpp
//

class CLesson08_PropApp : public CWinApp
{
public:
	CLesson08_PropApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLesson08_PropApp theApp;
