
// GraphicView.cpp : CGraphicView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Graphic.h"
#endif

#include "GraphicDoc.h"
#include "GraphicView.h"
#include "Graph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphicView

IMPLEMENT_DYNCREATE(CGraphicView, CScrollView)

BEGIN_MESSAGE_MAP(CGraphicView, CScrollView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(IDM_DOT, &CGraphicView::OnDot)
	ON_COMMAND(IDM_LINE, &CGraphicView::OnLine)
	ON_COMMAND(IDM_RECTANGLE, &CGraphicView::OnRectangle)
	ON_COMMAND(IDM_ELLIPSE, &CGraphicView::OnEllipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_FILE_SAVE, &CGraphicView::OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, &CGraphicView::OnFileOpen)
END_MESSAGE_MAP()

// CGraphicView ����/����

CGraphicView::CGraphicView()
	: m_ptOrigin(0)
{
	// TODO:  �ڴ˴���ӹ������

	m_nDrawType = -1;
	m_dcMetaFile.Create();
}

CGraphicView::~CGraphicView()
{
}

BOOL CGraphicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// CGraphicView ����

void CGraphicView::OnDraw(CDC* pDC)
{
	CGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	/*CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	pDC->SelectObject(&pen);

	pDC->SelectObject(CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)));

	for (int i = 0; i < m_ptrArray.GetSize(); i++)
	{
		switch (((CGraph*)m_ptrArray.GetAt(i))->m_nDrawType)
		{
		case 0:
			pDC->SetPixel(((CGraph*)m_ptrArray.GetAt(i))->m_ptEnd, RGB(255, 0, 0));
			break;
		case 1:
			pDC->MoveTo(((CGraph*)m_ptrArray.GetAt(i))->m_ptOrigin);
			pDC->LineTo(((CGraph*)m_ptrArray.GetAt(i))->m_ptEnd);
			break;
		case 2:
			pDC->Rectangle(CRect(((CGraph*)m_ptrArray.GetAt(i))->m_ptOrigin, ((CGraph*)m_ptrArray.GetAt(i))->m_ptEnd));
			break;
		case 3:
			pDC->Ellipse(CRect(((CGraph*)m_ptrArray.GetAt(i))->m_ptOrigin, ((CGraph*)m_ptrArray.GetAt(i))->m_ptEnd));
			break;
		default:
			break;
		}
	}*/

	/*//1. �ر�Ԫ�ļ�
	HMETAFILE hMetaFile;
	hMetaFile = m_dcMetaFile.Close();
	//2. ����Ԫ�ļ�
	pDC->PlayMetaFile(hMetaFile);
	//3. �����µ�Ԫ�ļ�
	m_dcMetaFile.Create();
	m_dcMetaFile.PlayMetaFile(hMetaFile);	//����ԭ���ĵ���ǰ��Ԫ�ļ���
	//4. ɾ����Դ
	DeleteMetaFile(hMetaFile);*/

	CRect rect;
	GetClientRect(&rect);
	//��Դ�豸�����ĵ�λͼ���˵�ǰ�豸������
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &m_dcCompatible, 0, 0, SRCCOPY);
}


// CGraphicView ��ӡ

BOOL CGraphicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CGraphicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CGraphicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CGraphicView ���

#ifdef _DEBUG
void CGraphicView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CGraphicView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CGraphicDoc* CGraphicView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicDoc)));
	return (CGraphicDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphicView ��Ϣ�������


void CGraphicView::OnDot()
{
	// TODO:  �ڴ���������������
	m_nDrawType = 0;
}


void CGraphicView::OnLine()
{
	// TODO:  �ڴ���������������
	m_nDrawType = 1;
}


void CGraphicView::OnRectangle()
{
	// TODO:  �ڴ���������������
	m_nDrawType = 2;
}


void CGraphicView::OnEllipse()
{
	// TODO:  �ڴ���������������
	m_nDrawType = 3;
}


void CGraphicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_ptOrigin = point;
	CScrollView::OnLButtonDown(nFlags, point);
}


void CGraphicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	dc.SelectObject(&pen);
	//m_dcMetaFile.SelectObject(&pen);

	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	dc.SelectObject(pBrush);
	//m_dcMetaFile.SelectObject(CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)));

	if (!m_dcCompatible.m_hDC)
	{
		m_dcCompatible.CreateCompatibleDC(&dc);		//��������DC
		CRect rect;
		GetClientRect(&rect);

		CBitmap bitmap;
		bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());	//��ʼ������λͼ

		m_dcCompatible.SelectObject(&bitmap);	//��ԭDC�豸ѡ�����DC��
		//��λͼ����ɫ����Դѡ�����DC��
		m_dcCompatible.BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);
		m_dcCompatible.SelectObject(&pen);
		m_dcCompatible.SelectObject(pBrush);
	}
	
	switch (m_nDrawType)
	{
	case 0:
		dc.SetPixel(point, RGB(255, 0, 0));
		m_dcCompatible.SetPixel(point, RGB(255, 0, 0));
		//m_dcMetaFile.SetPixel(point, RGB(255, 0, 0));
		break;
	case 1:
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		m_dcCompatible.MoveTo(m_ptOrigin);
		m_dcCompatible.LineTo(point);
		//m_dcMetaFile.MoveTo(m_ptOrigin);
		//m_dcMetaFile.LineTo(point);
		break;
	case 2:
		dc.Rectangle(CRect(m_ptOrigin, point));
		m_dcCompatible.Rectangle(CRect(m_ptOrigin, point));
		//m_dcMetaFile.Rectangle(CRect(m_ptOrigin, point));
		break;
	case 3:
		dc.Ellipse(CRect(m_ptOrigin, point));
		m_dcCompatible.Ellipse(CRect(m_ptOrigin, point));
		//m_dcMetaFile.Ellipse(CRect(m_ptOrigin, point));
		break;
	default:
		break;
	}

	/*OnPrepareDC(&dc);	//��ֹͼ���λ
	dc.DPtoLP(&m_ptOrigin);		//���������תΪ�߼�����
	dc.DPtoLP(&point);

	//�ڴ����, ������
	//CGraph graph(m_nDrawType, m_ptOrigin, point);	//������ͼ����
	CGraph *pGraph = new CGraph(m_nDrawType, m_ptOrigin, point);	//���ڴ�, Ӧ�ó��������������
	m_ptrArray.Add(pGraph);		//��ӽ�������*/

	CScrollView::OnLButtonUp(nFlags, point);
}


void CGraphicView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
	SetScrollSizes(MM_TEXT, CSize(1200, 1000));
}


void CGraphicView::OnFileSave()
{
	// TODO:  �ڴ���������������
	HMETAFILE hmf;
	hmf = m_dcMetaFile.Close();
	CopyMetaFile(hmf, "meta.wmf");	//���浽�ļ���
	m_dcMetaFile.Create();
	DeleteMetaFile(hmf);
}


void CGraphicView::OnFileOpen()
{
	// TODO:  �ڴ���������������
	HMETAFILE hmf;
	hmf = GetMetaFile("meta.wmf");	//��Ԫ�ļ�
	m_dcMetaFile.PlayMetaFile(hmf);
	DeleteMetaFile(hmf);
	Invalidate();	//���𴰿��ػ�, ����ͼ��
}
