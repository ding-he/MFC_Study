
// Lesson08_KEYDOWN.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLesson08_KEYDOWNApp: 
// �йش����ʵ�֣������ Lesson08_KEYDOWN.cpp
//

class CLesson08_KEYDOWNApp : public CWinApp
{
public:
	CLesson08_KEYDOWNApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
public:
	HWND m_hwndDlg;
	virtual BOOL ProcessMessageFilter(int code, LPMSG lpMsg);
};

extern CLesson08_KEYDOWNApp theApp;