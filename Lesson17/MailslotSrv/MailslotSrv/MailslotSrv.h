
// MailslotSrv.h : MailslotSrv Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMailslotSrvApp:
// �йش����ʵ�֣������ MailslotSrv.cpp
//

class CMailslotSrvApp : public CWinAppEx
{
public:
	CMailslotSrvApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMailslotSrvApp theApp;
