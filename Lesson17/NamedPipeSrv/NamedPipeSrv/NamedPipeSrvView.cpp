
// NamedPipeSrvView.cpp : CNamedPipeSrvView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "NamedPipeSrv.h"
#endif

#include "NamedPipeSrvDoc.h"
#include "NamedPipeSrvView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNamedPipeSrvView

IMPLEMENT_DYNCREATE(CNamedPipeSrvView, CView)

BEGIN_MESSAGE_MAP(CNamedPipeSrvView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_PIPE_CREATE, &CNamedPipeSrvView::OnPipeCreate)
	ON_COMMAND(IDM_PIPE_READ, &CNamedPipeSrvView::OnPipeRead)
	ON_COMMAND(IDM_PIPE_WRITE, &CNamedPipeSrvView::OnPipeWrite)
END_MESSAGE_MAP()

// CNamedPipeSrvView ����/����

CNamedPipeSrvView::CNamedPipeSrvView()
{
	// TODO:  �ڴ˴���ӹ������
	hPipe = NULL;
}

CNamedPipeSrvView::~CNamedPipeSrvView()
{
	if (hPipe)
		CloseHandle(hPipe);
}

BOOL CNamedPipeSrvView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CNamedPipeSrvView ����

void CNamedPipeSrvView::OnDraw(CDC* /*pDC*/)
{
	CNamedPipeSrvDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CNamedPipeSrvView ��ӡ

BOOL CNamedPipeSrvView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CNamedPipeSrvView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CNamedPipeSrvView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CNamedPipeSrvView ���

#ifdef _DEBUG
void CNamedPipeSrvView::AssertValid() const
{
	CView::AssertValid();
}

void CNamedPipeSrvView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNamedPipeSrvDoc* CNamedPipeSrvView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNamedPipeSrvDoc)));
	return (CNamedPipeSrvDoc*)m_pDocument;
}
#endif //_DEBUG


// CNamedPipeSrvView ��Ϣ�������


void CNamedPipeSrvView::OnPipeCreate()
{
	// TODO:  �ڴ���������������
	hPipe = CreateNamedPipe("\\\\.\\pipe\\MyPipe", PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED, 0, 1, 1024, 1024, 0, NULL);
	if (INVALID_HANDLE_VALUE == hPipe)
	{
		MessageBox("���������ܵ�ʧ��");
		hPipe = NULL;
		return;
	}

	HANDLE hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);		//�����˹����ö���

	if (!hEvent)
	{
		MessageBox("�����¼�����ʧ��");
		CloseHandle(hEvent);
		hEvent = NULL;
		return;
	}

	OVERLAPPED ol;
	ZeroMemory(&ol, sizeof(OVERLAPPED));		//��Ҫ��һ��, ��ֹ��������ҳ�������
	ol.hEvent = hEvent;
	if (!ConnectNamedPipe(hPipe, &ol))			//�ȴ�����
	{
		if (ERROR_IO_PENDING != GetLastError())	//���Ǵ˴���
		{
			MessageBox("�ȴ�����ʧ��");
			CloseHandle(hPipe);
			CloseHandle(hEvent);
			hPipe = NULL;
			return;
		}
	}

	if (WAIT_FAILED == WaitForSingleObject(hEvent, INFINITE))
	{
		MessageBox("�ȴ�����ʧ��");
		CloseHandle(hPipe);
		CloseHandle(hEvent);
		hPipe = NULL;
		return;
	}

	CloseHandle(hEvent);						//�ر��¼�����
}


void CNamedPipeSrvView::OnPipeRead()
{
	// TODO:  �ڴ���������������
	char buf[100];
	DWORD dwRead;
	if (!ReadFile(hPipe, buf, 100, &dwRead, NULL))
	{
		MessageBox("��ȡ����ʧ��");
		return;
	}
	MessageBox(buf);
}


void CNamedPipeSrvView::OnPipeWrite()
{
	// TODO:  �ڴ���������������
	char buf[] = "this is servers";
	DWORD dwWrite;
	if (!WriteFile(hPipe, buf, strlen(buf) + 1, &dwWrite, NULL))
	{
		MessageBox("д������ʧ��");
		return;
	}
}
