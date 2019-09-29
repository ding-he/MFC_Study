
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
//	ON_COMMAND(ID_FILE_SAVE, &CGraphicView::OnFileSave)
//	ON_COMMAND(ID_FILE_OPEN, &CGraphicView::OnFileOpen)
	ON_COMMAND(IDM_FILE_WRITE, &CGraphicView::OnFileWrite)
	ON_COMMAND(IDM_FILE_READ, &CGraphicView::OnFileRead)
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
	int nCount = pDoc->m_obArray.GetSize();
	for (int i = 0; i < nCount; i++)
	{
		//((CGraph*)m_obArray.GetAt(i))->Draw(pDC);
		((CGraph*)pDoc->m_obArray.GetAt(i))->Draw(pDC);
	}
	
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

	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	dc.SelectObject(pBrush);

	
	switch (m_nDrawType)
	{
	case 0:
		dc.SetPixel(point, RGB(255, 0, 0));
		break;
	case 1:
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		break;
	case 2:
		dc.Rectangle(CRect(m_ptOrigin, point));
		break;
	case 3:
		dc.Ellipse(CRect(m_ptOrigin, point));
		break;
	default:
		break;
	}

	CGraph *pGraph = new CGraph(m_nDrawType, m_ptOrigin, point);
	//m_obArray.Add(pGraph);

	CGraphicDoc *pDoc = GetDocument();
	pDoc->m_obArray.Add(pGraph);

	CScrollView::OnLButtonUp(nFlags, point);
}


void CGraphicView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
	SetScrollSizes(MM_TEXT, CSize(1200, 1000));
}


//void CGraphicView::OnFileSave()
//{
//	// TODO:  �ڴ���������������
//	HMETAFILE hmf;
//	hmf = m_dcMetaFile.Close();
//	CopyMetaFile(hmf, "meta.wmf");	//���浽�ļ���
//	m_dcMetaFile.Create();
//	DeleteMetaFile(hmf);
//}


//void CGraphicView::OnFileOpen()
//{
//	// TODO:  �ڴ���������������
//	HMETAFILE hmf;
//	hmf = GetMetaFile("meta.wmf");	//��Ԫ�ļ�
//	m_dcMetaFile.PlayMetaFile(hmf);
//	DeleteMetaFile(hmf);
//	Invalidate();	//���𴰿��ػ�, ����ͼ��
//}


void CGraphicView::OnFileWrite()
{
	// TODO:  �ڴ���������������
	//����CFile����
	CFile file("1.txt", CFile::modeWrite | CFile::modeCreate);
	//����CArchive����
	CArchive ar(&file, CArchive::store);
	int i = 12;
	char ch = 'm';
	float pi = 3.14f;
	CString str("hello world");
	//��������
	ar << i << ch << pi << str;
//	file.Close();	//CArchive�����Զ��ر�CFile����, �����ֶ�����CLose()�ر�
}


void CGraphicView::OnFileRead()
{
	// TODO:  �ڴ���������������
	CFile file("1.txt", CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	int i;
	char ch;
	float pi;
	CString str;
	CString strResult;
	ar >> i >> ch >> pi >> str;		//����д˳�򱣳�һ��
	strResult.Format("%d, %c, %f, %s", i, ch, pi, str);
	MessageBox(strResult);
//	file.Close();
}
