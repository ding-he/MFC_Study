
// GraphicDoc.cpp : CGraphicDoc ���ʵ��
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

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CGraphicDoc

IMPLEMENT_DYNCREATE(CGraphicDoc, CDocument)

BEGIN_MESSAGE_MAP(CGraphicDoc, CDocument)
END_MESSAGE_MAP()


// CGraphicDoc ����/����

CGraphicDoc::CGraphicDoc()
{
	// TODO:  �ڴ����һ���Թ������

}

CGraphicDoc::~CGraphicDoc()
{
}

BOOL CGraphicDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	//SetTitle("Hello World");	//�����ĵ�����

	return TRUE;
}




// CGraphicDoc ���л�

void CGraphicDoc::Serialize(CArchive& ar)
{
	POSITION pos = GetFirstViewPosition();
	CGraphicView *pView = (CGraphicView*)GetNextView(pos);
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
		/*int i = 3;
		float f = 3.14f;
		char ch = 's';
		ar << i << f << ch;*/
		/*int nCount = pView->m_obArray.GetSize();
		ar << nCount;
		for (int i = 0; i < nCount; i++)
		{
			ar << pView->m_obArray.GetAt(i);
		}*/
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
		/*int i;
		float f;
		char ch;
		ar >> i >> f >> ch;
		CString str;
		str.Format("%d, %f, %c", i, f, ch);
		AfxMessageBox(str);*/
		/*int nCount;
		ar >> nCount;
		CGraph *pGraph;
		for (int i = 0; i < nCount; i++)
		{
			ar >> pGraph;
			pView->m_obArray.Add(pGraph);
		}*/
	}

	//pView->m_obArray.Serialize(ar);
	m_obArray.Serialize(ar);
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CGraphicDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CGraphicDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CGraphicDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CGraphicDoc ���

#ifdef _DEBUG
void CGraphicDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGraphicDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGraphicDoc ����


void CGraphicDoc::DeleteContents()
{
	// TODO:  �ڴ����ר�ô����/����û���
	int nCount = m_obArray.GetSize();
	for (int i = 0; i < nCount; i++)
	{
		delete m_obArray.GetAt(i);
	}
	m_obArray.RemoveAll();

	/*while (nCount--)
	{
		delete m_obArray.GetAt(nCount);
		m_obArray.RemoveAt(nCount);
	}*/
	CDocument::DeleteContents();
}
