
// MailSlotCltView.cpp : CMailSlotCltView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MailSlotClt.h"
#endif

#include "MailSlotCltDoc.h"
#include "MailSlotCltView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMailSlotCltView

IMPLEMENT_DYNCREATE(CMailSlotCltView, CView)

BEGIN_MESSAGE_MAP(CMailSlotCltView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_MAILSLOT_SEND, &CMailSlotCltView::OnMailslotSend)
END_MESSAGE_MAP()

// CMailSlotCltView ����/����

CMailSlotCltView::CMailSlotCltView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMailSlotCltView::~CMailSlotCltView()
{
}

BOOL CMailSlotCltView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMailSlotCltView ����

void CMailSlotCltView::OnDraw(CDC* /*pDC*/)
{
	CMailSlotCltDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMailSlotCltView ��ӡ

BOOL CMailSlotCltView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMailSlotCltView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMailSlotCltView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMailSlotCltView ���

#ifdef _DEBUG
void CMailSlotCltView::AssertValid() const
{
	CView::AssertValid();
}

void CMailSlotCltView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMailSlotCltDoc* CMailSlotCltView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMailSlotCltDoc)));
	return (CMailSlotCltDoc*)m_pDocument;
}
#endif //_DEBUG


// CMailSlotCltView ��Ϣ�������


void CMailSlotCltView::OnMailslotSend()
{
	// TODO:  �ڴ���������������
	//���ʲ�
	HANDLE hMailslot = CreateFile("\\\\.\\mailslot\\MyMailslot", GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hMailslot)
	{
		MessageBox("���ʲ�ʧ��");
		return;
	}

	char buf[] = "hello world";
	DWORD dwSend;
	if (!WriteFile(hMailslot, buf, strlen(buf) + 1, &dwSend, NULL))		//д����
	{
		MessageBox("д��ʧ��");
		CloseHandle(hMailslot);
		return;
	}
	CloseHandle(hMailslot);
}
