
// NamedPipeSrv.h : NamedPipeSrv Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CNamedPipeSrvApp:
// �йش����ʵ�֣������ NamedPipeSrv.cpp
//

class CNamedPipeSrvApp : public CWinAppEx
{
public:
	CNamedPipeSrvApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CNamedPipeSrvApp theApp;
