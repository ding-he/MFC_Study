
// InnerHook.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CInnerHookApp: 
// �йش����ʵ�֣������ InnerHook.cpp
//

class CInnerHookApp : public CWinApp
{
public:
	CInnerHookApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CInnerHookApp theApp;