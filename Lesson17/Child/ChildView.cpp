
// ChildView.cpp : CChildView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Child.h"
#endif

#include "ChildDoc.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

IMPLEMENT_DYNCREATE(CChildView, CView)

BEGIN_MESSAGE_MAP(CChildView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_PIPE_READ, &CChildView::OnPipeRead)
	ON_COMMAND(IDM_PIPE_WRITE, &CChildView::OnPipeWrite)
END_MESSAGE_MAP()

// CChildView ����/����

CChildView::CChildView()
{
	// TODO:  �ڴ˴���ӹ������
	hRead = NULL;
	hWrite = NULL;
}

CChildView::~CChildView()
{
	if (hRead)
		CloseHandle(hRead);
	if (hWrite)
		CloseHandle(hWrite);
}

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CChildView ����

void CChildView::OnDraw(CDC* /*pDC*/)
{
	CChildDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CChildView ��ӡ

BOOL CChildView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CChildView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CChildView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CChildView ���

#ifdef _DEBUG
void CChildView::AssertValid() const
{
	CView::AssertValid();
}

void CChildView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChildDoc* CChildView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChildDoc)));
	return (CChildDoc*)m_pDocument;
}
#endif //_DEBUG


// CChildView ��Ϣ�������


void CChildView::OnPipeRead()
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


void CChildView::OnPipeWrite()
{
	// TODO:  �ڴ���������������
	char buf[] = "this is child";
	DWORD dwWrite;
	if (!WriteFile(hWrite, buf, strlen(buf) + 1, &dwWrite, NULL))
	{
		MessageBox("д������ʧ��");
		return;
	}
}


void CChildView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
	hRead = GetStdHandle(STD_INPUT_HANDLE);		//get the handle of the standard input and output
	hWrite = GetStdHandle(STD_OUTPUT_HANDLE);
}
