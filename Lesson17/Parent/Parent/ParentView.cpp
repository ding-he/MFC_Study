
// ParentView.cpp : CParentView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Parent.h"
#endif

#include "ParentDoc.h"
#include "ParentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CParentView

IMPLEMENT_DYNCREATE(CParentView, CView)

BEGIN_MESSAGE_MAP(CParentView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_PIPE_CREATE, &CParentView::OnPipeCreate)
	ON_COMMAND(IDM_PIPE_READ, &CParentView::OnPipeRead)
	ON_COMMAND(IDM_PIPE_WRITE, &CParentView::OnPipeWrite)
END_MESSAGE_MAP()

// CParentView ����/����

CParentView::CParentView()
{
	// TODO:  �ڴ˴���ӹ������
	hRead = NULL;
	hWrite = NULL;
}

CParentView::~CParentView()
{
	if (hRead)
		CloseHandle(hRead);
	if (hWrite)
		CloseHandle(hWrite);
}

BOOL CParentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CParentView ����

void CParentView::OnDraw(CDC* /*pDC*/)
{
	CParentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CParentView ��ӡ

BOOL CParentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CParentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CParentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CParentView ���

#ifdef _DEBUG
void CParentView::AssertValid() const
{
	CView::AssertValid();
}

void CParentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CParentDoc* CParentView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CParentDoc)));
	return (CParentDoc*)m_pDocument;
}
#endif //_DEBUG


// CParentView ��Ϣ�������


void CParentView::OnPipeCreate()
{
	// TODO:  �ڴ���������������
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = TRUE;			//�ӽ��̼̳�
	sa.lpSecurityDescriptor = NULL;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);

	if (!CreatePipe(&hRead, &hWrite, &sa, 0))
	{
		//DWORD dwErr = GetLastError();
		MessageBox("���������ܵ�ʧ��");
		return;
	}

	STARTUPINFO sui;
	PROCESS_INFORMATION pi;
	ZeroMemory(&sui, sizeof(STARTUPINFO));
	sui.cb = sizeof(STARTUPINFO);
	sui.dwFlags = STARTF_USESTDHANDLES;			//��׼�������,����
	sui.hStdInput = hRead;
	sui.hStdOutput = hWrite;
	sui.hStdError = GetStdHandle(STD_ERROR_HANDLE);

	//if (!CreateProcess("..\\Child\\Debug\\Child.exe", NULL, NULL, NULL, TRUE, 0, NULL, NULL, &sui, &pi))
	if (!CreateProcess("..\\Debug\\Child.exe", NULL, NULL, NULL, TRUE, 0, NULL, NULL, &sui, &pi))
	{
		DWORD dwErr = GetLastError();
		CloseHandle(hRead);
		CloseHandle(hWrite);
		hRead = NULL;
		hWrite = NULL;
		MessageBox("�����ӽ���ʧ��");
	}
	else
	{
		CloseHandle(pi.hProcess);				//�����̲����������ӽ���, ��ر�
		CloseHandle(pi.hThread);
	}
}


void CParentView::OnPipeRead()
{
	// TODO:  �ڴ���������������
	char buf[100];
	DWORD dwRead;
	if (!ReadFile(hRead, buf, 100, &dwRead, NULL))
	{
		MessageBox("��ȡ����ʧ��");
		return;
	}
	MessageBox(buf);
}


void CParentView::OnPipeWrite()
{
	// TODO:  �ڴ���������������
	char buf[] = "hello world!";
	DWORD dwWrite;
	if (!WriteFile(hWrite, buf, strlen(buf) + 1, &dwWrite, NULL))
	{
		MessageBox("д������ʧ��");
		return;
	}
}
