
// Lesson03.h : Lesson03 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CLesson03App:
// �йش����ʵ�֣������ Lesson03.cpp
//

class CLesson03App : public CWinAppEx
{
public:
	CLesson03App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLesson03App theApp;
