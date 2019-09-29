
// MailslotSrvView.cpp : CMailslotSrvView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MailslotSrv.h"
#endif

#include "MailslotSrvDoc.h"
#include "MailslotSrvView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMailslotSrvView

IMPLEMENT_DYNCREATE(CMailslotSrvView, CView)

BEGIN_MESSAGE_MAP(CMailslotSrvView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_MAILSLOT_RECV, &CMailslotSrvView::OnMailslotRecv)
END_MESSAGE_MAP()

// CMailslotSrvView ����/����

CMailslotSrvView::CMailslotSrvView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMailslotSrvView::~CMailslotSrvView()
{
}

BOOL CMailslotSrvView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMailslotSrvView ����

void CMailslotSrvView::OnDraw(CDC* /*pDC*/)
{
	CMailslotSrvDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMailslotSrvView ��ӡ

BOOL CMailslotSrvView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMailslotSrvView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMailslotSrvView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMailslotSrvView ���

#ifdef _DEBUG
void CMailslotSrvView::AssertValid() const
{
	CView::AssertValid();
}

void CMailslotSrvView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMailslotSrvDoc* CMailslotSrvView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMailslotSrvDoc)));
	return (CMailslotSrvDoc*)m_pDocument;
}
#endif //_DEBUG


// CMailslotSrvView ��Ϣ�������


void CMailslotSrvView::OnMailslotRecv()
{
	// TODO:  �ڴ���������������
	HANDLE hMailslot = CreateMailslot("\\\\.\\mailslot\\MyMailslot", 0, MAILSLOT_WAIT_FOREVER, NULL);			//�����ʲ�
	if (INVALID_HANDLE_VALUE == hMailslot)
	{
		MessageBox("�����ʲ�ʧ��");
		return;
	}

	char buf[100];
	DWORD dwRecv;
	if (!ReadFile(hMailslot, buf, 100, &dwRecv, NULL))		//��������
	{
		MessageBox("��������ʧ��");
		CloseHandle(hMailslot);
		return;
	}

	MessageBox(buf);
	CloseHandle(hMailslot);
}
