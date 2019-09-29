
// Lesson08_KEYDOWN.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Lesson08_KEYDOWN.h"
#include "Lesson08_KEYDOWNDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLesson08_KEYDOWNApp

BEGIN_MESSAGE_MAP(CLesson08_KEYDOWNApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CLesson08_KEYDOWNApp ����

CLesson08_KEYDOWNApp::CLesson08_KEYDOWNApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CLesson08_KEYDOWNApp ����

CLesson08_KEYDOWNApp theApp;


// CLesson08_KEYDOWNApp ��ʼ��

BOOL CLesson08_KEYDOWNApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO:  Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CLesson08_KEYDOWNDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO:  �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO:  �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	m_hwndDlg = NULL;
	return FALSE;
}



BOOL CLesson08_KEYDOWNApp::ProcessMessageFilter(int code, LPMSG lpMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���
	/*if (m_hwndDlg != NULL)
	{
		if ((lpMsg->hwnd == m_hwndDlg) || ::IsChild(m_hwndDlg, lpMsg->hwnd))
		{
			if (lpMsg->message == WM_KEYDOWN)
			{
				AfxMessageBox("����WM_KEYDOWN��Ϣ�ɹ�");
			}
		}
	}*/
	return CWinApp::ProcessMessageFilter(code, lpMsg);
}
