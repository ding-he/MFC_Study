
// NamedPipeCltView.cpp : CNamedPipeCltView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "NamedPipeClt.h"
#endif

#include "NamedPipeCltDoc.h"
#include "NamedPipeCltView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNamedPipeCltView

IMPLEMENT_DYNCREATE(CNamedPipeCltView, CView)

BEGIN_MESSAGE_MAP(CNamedPipeCltView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_PIPE_CONNECT, &CNamedPipeCltView::OnPipeConnect)
	ON_COMMAND(IDM_PIPE_READ, &CNamedPipeCltView::OnPipeRead)
	ON_COMMAND(IDM_PIPE_WRITE, &CNamedPipeCltView::OnPipeWrite)
END_MESSAGE_MAP()

// CNamedPipeCltView ����/����

CNamedPipeCltView::CNamedPipeCltView()
{
	// TODO:  �ڴ˴���ӹ������
	hPipe = NULL;
}

CNamedPipeCltView::~CNamedPipeCltView()
{
	if (hPipe)
		CloseHandle(hPipe);
}

BOOL CNamedPipeCltView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CNamedPipeCltView ����

void CNamedPipeCltView::OnDraw(CDC* /*pDC*/)
{
	CNamedPipeCltDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CNamedPipeCltView ��ӡ

BOOL CNamedPipeCltView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CNamedPipeCltView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CNamedPipeCltView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CNamedPipeCltView ���

#ifdef _DEBUG
void CNamedPipeCltView::AssertValid() const
{
	CView::AssertValid();
}

void CNamedPipeCltView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNamedPipeCltDoc* CNamedPipeCltView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNamedPipeCltDoc)));
	return (CNamedPipeCltDoc*)m_pDocument;
}
#endif //_DEBUG


// CNamedPipeCltView ��Ϣ�������


void CNamedPipeCltView::OnPipeConnect()
{
	// TODO:  �ڴ���������������
	if (!WaitNamedPipe("\\\\.\\pipe\\MyPipe", NMPWAIT_WAIT_FOREVER))	//�ȴ��Ƿ��п��õĹܵ�
	{
		MessageBox("û�п��õ�");
		return;
	}

	hPipe = CreateFile("\\\\.\\pipe\\MyPipe", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);		//���ӹܵ�
	if (INVALID_HANDLE_VALUE == hPipe)
	{
		MessageBox("����ʧ��");
		hPipe = NULL;
		return;
	}
}


void CNamedPipeCltView::OnPipeRead()
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


void CNamedPipeCltView::OnPipeWrite()
{
	// TODO:  �ڴ���������������
	char buf[] = "this is client";
	DWORD dwWrite;
	if (!WriteFile(hPipe, buf, strlen(buf) + 1, &dwWrite, NULL))
	{
		MessageBox("д������ʧ��");
		return;
	}
}
