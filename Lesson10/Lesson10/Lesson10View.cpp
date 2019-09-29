
// Lesson10View.cpp : CLesson10View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Lesson10.h"
#endif

#include "Lesson10Doc.h"
#include "Lesson10View.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLesson10View

IMPLEMENT_DYNCREATE(CLesson10View, CView)

BEGIN_MESSAGE_MAP(CLesson10View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_DOT, &CLesson10View::OnDot)
	ON_COMMAND(IDM_LINE, &CLesson10View::OnLine)
	ON_COMMAND(IDM_RECTANGLE, &CLesson10View::OnRectangle)
	ON_COMMAND(IDM_ELLIPSE, &CLesson10View::OnEllipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDM_SETTING, &CLesson10View::OnSetting)
	ON_COMMAND(IDM_COLOR, &CLesson10View::OnColor)
	ON_COMMAND(IDM_FONT, &CLesson10View::OnFont)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CLesson10View ����/����

CLesson10View::CLesson10View()
	: m_nDrawType(0)
	, m_ptOrigin(0)
	, m_nLineWidth(0)
	, m_nLineStyle(0)
{
	// TODO:  �ڴ˴���ӹ������
	m_color = RGB(255, 0, 0);
	m_font.CreatePointFont(300, "�����п�");
	LOGFONT *pLogFont = new LOGFONT;
	m_font.GetLogFont(pLogFont);
	m_strFontName = pLogFont->lfFaceName;
	delete pLogFont;
}

CLesson10View::~CLesson10View()
{
}

BOOL CLesson10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLesson10View ����

void CLesson10View::OnDraw(CDC* pDC)
{
	CLesson10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CFont *pOldFont = pDC->SelectObject(&m_font);;
	pDC->TextOutA(0, 0, m_strFontName);
	pDC->SelectObject(pOldFont);

	/*//����˸
	//1. ����λͼ
	CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BITMAP1);

	BITMAP bm;
	bitmap.GetBitmap(&bm);

	//2. ��������DC
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);

	//3. ��λͼѡ�����DC��
	dcCompatible.SelectObject(&bitmap);

	//4. ������DC���Ƶ���ǰDC��
	CRect rect;
	GetClientRect(&rect);

	int nX = rect.left + (rect.Width() - bm.bmWidth) / 2;
	int nY = rect.top + (rect.Height() - bm.bmHeight) / 2;

	//pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);
	//pDC->BitBlt(nX, nY, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);	//���м���ʾ
	//�����ѹ��λͼ����ӦĿ����εĳߴ�
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);*/
}


// CLesson10View ��ӡ

BOOL CLesson10View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CLesson10View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CLesson10View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CLesson10View ���

#ifdef _DEBUG
void CLesson10View::AssertValid() const
{
	CView::AssertValid();
}

void CLesson10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLesson10Doc* CLesson10View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLesson10Doc)));
	return (CLesson10Doc*)m_pDocument;
}
#endif //_DEBUG


// CLesson10View ��Ϣ�������


void CLesson10View::OnDot()
{
	// TODO:  �ڴ���������������
	m_nDrawType = 1;
}


void CLesson10View::OnLine()
{
	// TODO:  �ڴ���������������
	m_nDrawType = 2;
}


void CLesson10View::OnRectangle()
{
	// TODO:  �ڴ���������������
	m_nDrawType = 3;
}


void CLesson10View::OnEllipse()
{
	// TODO:  �ڴ���������������
	m_nDrawType = 4;
}


void CLesson10View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_ptOrigin = point;//�������
	CView::OnLButtonDown(nFlags, point);
}


void CLesson10View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	//CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen pen(m_nLineStyle, m_nLineWidth, m_color);
	dc.SelectObject(&pen);		//ָ����
	dc.SelectObject(CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)));	//ָ����ˢ

	switch (m_nDrawType)
	{
	case 1:
		//dot
		dc.SetPixel(point, m_color);
		break;
	case 2:
		//line
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		break;
	case 3:
		//rectangle
		dc.Rectangle(CRect(m_ptOrigin, point));
		break;
	case 4:
		//ellipse
		dc.Ellipse(CRect(m_ptOrigin, point));
		break;
	default:
		break;
	}

	CView::OnLButtonUp(nFlags, point);
}


void CLesson10View::OnSetting()
{
	// TODO:  �ڴ���������������
	CSettingDlg dlg;	//m_nLineWidth=0
	dlg.m_nLineWidth = m_nLineWidth;	//�ѵ�ǰ���߿���dlg
	dlg.m_nLineStyle = m_nLineStyle;
	dlg.m_color = m_color;
	if (IDOK == dlg.DoModal())
	{
		m_nLineWidth = dlg.m_nLineWidth;	//�����߿�
		m_nLineStyle = dlg.m_nLineStyle;	//��������
	}
}


void CLesson10View::OnColor()
{
	// TODO:  �ڴ���������������
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_RGBINIT;// | CC_FULLOPEN;
	dlg.m_cc.rgbResult = m_color;
	if (IDOK == dlg.DoModal())
	{
		m_color = dlg.m_cc.rgbResult;
	}
}


void CLesson10View::OnFont()
{
	// TODO:  �ڴ���������������
	CFontDialog dlg;
	if (IDOK == dlg.DoModal())
	{
		if (m_font.m_hObject)
			m_font.DeleteObject();
		m_font.CreateFontIndirect(dlg.m_cf.lpLogFont);
		m_strFontName = dlg.m_cf.lpLogFont->lfFaceName;
	}
	Invalidate();
}

//����������Ϣ
BOOL CLesson10View::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//1. ����λͼ
	CBitmap bitmap;
	bitmap.LoadBitmapA(IDB_BITMAP1);

	BITMAP bm;
	bitmap.GetBitmap(&bm);
	
	//2. ��������DC
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);

	//3. ��λͼѡ�����DC��
	dcCompatible.SelectObject(&bitmap);

	//4. ������DC���Ƶ���ǰDC��
	CRect rect;
	GetClientRect(&rect);
	
	int nX = rect.left + (rect.Width() - bm.bmWidth) / 2;
	int nY = rect.top + (rect.Height() - bm.bmHeight) / 2;

	//pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);
	//pDC->BitBlt(nX, nY, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);	//���м���ʾ
	//�����ѹ��λͼ����ӦĿ����εĳߴ�
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);

	//return CView::OnEraseBkgnd(pDC);
	return TRUE;
}
