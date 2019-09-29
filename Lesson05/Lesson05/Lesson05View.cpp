
// Lesson05View.cpp : CLesson05View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Lesson05.h"
#endif

#include "Lesson05Doc.h"
#include "Lesson05View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLesson05View

IMPLEMENT_DYNCREATE(CLesson05View, CView)

BEGIN_MESSAGE_MAP(CLesson05View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CLesson05View ����/����

CLesson05View::CLesson05View()
	: m_strLine(_T(""))
	, m_ptOrigin(0)
	, m_nWidth(0)
{
	// TODO:  �ڴ˴���ӹ������

}

CLesson05View::~CLesson05View()
{
}

BOOL CLesson05View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLesson05View ����

void CLesson05View::OnDraw(CDC* pDC)
{
	CLesson05Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CString str;// ("Hello World ����,���");
	str = "Hello World ����,���";
	pDC->TextOutW(50, 50, str);

	CSize sz = pDC->GetTextExtent(str);//��ȡ�ַ������ȿ����Ϣ

	str.LoadStringW(IDS_MYSTRING);
	pDC->TextOutW(0, 200, str);

	pDC->BeginPath();
	pDC->Rectangle(CRect(50, 50, 50 + sz.cx, 50 + sz.cy));
	pDC->EndPath();

	pDC->SelectClipPath(RGN_DIFF);

	for (int i = 0; i < 300; i += 10)
	{
		pDC->MoveTo(0, i);
		pDC->LineTo(300, i);
		pDC->MoveTo(i, 0);
		pDC->LineTo(i, 300);
	}
}


// CLesson05View ��ӡ

BOOL CLesson05View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CLesson05View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CLesson05View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CLesson05View ���

#ifdef _DEBUG
void CLesson05View::AssertValid() const
{
	CView::AssertValid();
}

void CLesson05View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson05Doc* CLesson05View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson05Doc)));
	return (CLesson05Doc*)m_pDocument;
}
#endif //_DEBUG


// CLesson05View ��Ϣ�������


int CLesson05View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	/*CreateSolidCaret(20, 100);//���,�߶�  �Ĳ����
	//CreateSolidCaret(0, 0);*/

	/*CClientDC dc(this);
	TEXTMETRIC tm;	//�ı��ṹ�����

	dc.GetTextMetrics(&tm);	//��ȡ�ı���Ϣ
	CreateSolidCaret(tm.tmAveCharWidth / 8, tm.tmHeight);*/

	//static CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	CreateCaret(&bitmap);

	ShowCaret();	//��ʾ�����

	SetTimer(1, 100, NULL);//��ʱ��: 100ms
	return 0;
}


void CLesson05View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCaretPos(point);
	m_strLine.Empty();
	m_ptOrigin = point;
	CView::OnLButtonDown(nFlags, point);
}


void CLesson05View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//ע��: ʹ��WCHARת��, ����char
	WCHAR ch = (WCHAR)nChar;
	CClientDC dc(this);

	CFont font;
	font.CreatePointFont(300, _T("����"), NULL);		//��������
	CFont *pOldFont = dc.SelectObject(&font);

	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	if (0x0d == ch)
	{
		//�س�
		m_ptOrigin.y += tm.tmHeight;
		m_strLine.Empty();
	}
	else if (0x08 == ch)
	{
		//�˸�
		COLORREF oldClr = dc.SetTextColor(dc.GetBkColor());
		dc.TextOutW(m_ptOrigin.x, m_ptOrigin.y, m_strLine);
		m_strLine = m_strLine.Left(m_strLine.GetLength() - 1);
		dc.SetTextColor(oldClr);
	}
	else
	{
		m_strLine += ch;
	}

	dc.TextOutW(m_ptOrigin.x, m_ptOrigin.y, m_strLine);

	//�ı���λ��
	CSize sz = dc.GetTextExtent(m_strLine);
	SetCaretPos(CPoint(m_ptOrigin.x + sz.cx, m_ptOrigin.y));

	dc.SelectObject(pOldFont);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CLesson05View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_nWidth += 5;
	CClientDC dc(this);

	CString str;
	str.LoadStringW(IDS_MYSTRING);
	

	
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	//��ɫ��������
	CRect rect;
	rect.left = 0;
	rect.top = 200;
	rect.right = m_nWidth;
	rect.bottom = rect.top + tm.tmHeight;

	dc.SetTextColor(RGB(255, 0, 0));
	
	dc.DrawText(str, rect, DT_LEFT);

	/*rect.top = 150;
	rect.bottom = rect.top + tm.tmHeight;
	dc.DrawText(str, rect, DT_RIGHT);*/

	CSize sz = dc.GetTextExtent(str);
	if (m_nWidth > sz.cx)
	{
		m_nWidth = 0;
		dc.SetTextColor(RGB(0, 0, 0));
		dc.TextOutW(0, 200, str);
	}

	CView::OnTimer(nIDEvent);
}
