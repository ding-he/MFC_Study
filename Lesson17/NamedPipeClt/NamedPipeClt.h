
// NamedPipeClt.h : NamedPipeClt Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CNamedPipeCltApp:
// �йش����ʵ�֣������ NamedPipeClt.cpp
//

class CNamedPipeCltApp : public CWinAppEx
{
public:
	CNamedPipeCltApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CNamedPipeCltApp theApp;
