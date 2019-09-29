
// GraphicDoc.cpp : CGraphicDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CGraphicDoc 构造/析构

CGraphicDoc::CGraphicDoc()
{
	// TODO:  在此添加一次性构造代码

}

CGraphicDoc::~CGraphicDoc()
{
}

BOOL CGraphicDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  在此添加重新初始化代码
	// (SDI 文档将重用该文档)
	//SetTitle("Hello World");	//设置文档标题

	return TRUE;
}




// CGraphicDoc 序列化

void CGraphicDoc::Serialize(CArchive& ar)
{
	POSITION pos = GetFirstViewPosition();
	CGraphicView *pView = (CGraphicView*)GetNextView(pos);
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
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
		// TODO:  在此添加加载代码
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

// 缩略图的支持
void CGraphicDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CGraphicDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CGraphicDoc 诊断

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


// CGraphicDoc 命令


void CGraphicDoc::DeleteContents()
{
	// TODO:  在此添加专用代码和/或调用基类
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
