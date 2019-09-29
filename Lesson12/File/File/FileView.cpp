
// FileView.cpp : CFileView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "File.h"
#endif

#include "FileDoc.h"
#include "FileView.h"
#include <fstream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileView

IMPLEMENT_DYNCREATE(CFileView, CView)

BEGIN_MESSAGE_MAP(CFileView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_FILE_READ, &CFileView::OnFileRead)
	ON_COMMAND(IDM_FILE_WRITE, &CFileView::OnFileWrite)
	ON_COMMAND(IDM_REG_WRITE, &CFileView::OnRegWrite)
	ON_COMMAND(IDM_REG_READ, &CFileView::OnRegRead)
END_MESSAGE_MAP()

// CFileView ����/����

CFileView::CFileView()
{
	// TODO:  �ڴ˴���ӹ������

}

CFileView::~CFileView()
{
}

BOOL CFileView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFileView ����

void CFileView::OnDraw(CDC* /*pDC*/)
{
	CFileDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CFileView ��ӡ

BOOL CFileView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFileView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CFileView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CFileView ���

#ifdef _DEBUG
void CFileView::AssertValid() const
{
	CView::AssertValid();
}

void CFileView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFileDoc* CFileView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileDoc)));
	return (CFileDoc*)m_pDocument;
}
#endif //_DEBUG


// CFileView ��Ϣ�������


void CFileView::OnFileRead()
{
	// TODO:  �ڴ���������������
	/*FILE *pFile;
	fopen_s(&pFile, "1.txt", "r");
	//char buf[100];
	//memset(buf, 0, 100);
	char *pBuf;
	fseek(pFile, 0, SEEK_END);
	int len = ftell(pFile);
	pBuf = new char[len + 1];
	rewind(pFile);	//���½��ļ�ָ��ָ���ļ���ͷ
	fread(pBuf, 1, 100, pFile);
	pBuf[len] = 0;
	fclose(pFile);
	MessageBox(pBuf);*/

	/*FILE *pFile;
	//fopen_s(&pFile, "2.txt", "r");	//���ı���ʽ��
	fopen_s(&pFile, "2.txt", "rb");		//�Զ����ƶ�
	char buf[100];
	fread(buf, 1, 100, pFile);
	buf[3] = 0;
	fclose(pFile);
	MessageBox(buf);*/

	/*ifstream ifs("4.txt");
	char buf[100];
	memset(buf, 0, 100);
	ifs.read(buf, 100);
	ifs.close();
	MessageBox(buf);*/

	/*HANDLE hFile;
	hFile = CreateFile("5.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	char buf[100];
	DWORD dwReads;
	ReadFile(hFile, buf, 100, &dwReads, NULL);
	buf[dwReads] = 0;
	CloseHandle(hFile);
	MessageBox(buf);*/

	/*CFile file("6.txt", CFile::modeRead);
	DWORD dwFileLen = file.GetLength();
	char *pBuf = new char[dwFileLen + 1];
	pBuf[dwFileLen] = 0;
	file.Read(pBuf, dwFileLen);
	file.Close();
	MessageBox(pBuf);*/

	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle = "�ҵ��ļ�";	//�Ի������
	fileDlg.m_ofn.lpstrFilter = "Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";	//�ļ���ʽ������
	if (IDOK == fileDlg.DoModal())
	{
		CFile file(fileDlg.GetFileName(), CFile::modeRead);
		DWORD dwFileLen = file.GetLength();
		char *pBuf = new char[dwFileLen + 1];
		pBuf[dwFileLen] = 0;
		file.Read(pBuf, dwFileLen);
		file.Close();
		MessageBox(pBuf);
	}
}


void CFileView::OnFileWrite()
{
	// TODO:  �ڴ���������������
	/*FILE *pFile;
	fopen_s(&pFile, "1.txt", "w");
	fwrite("Hello World!", 1, strlen("Hello World!"), pFile);
	//fseek(pFile, 0, SEEK_SET);	//�ƶ��ļ�ָ�����ļ���ͷ
	//fwrite("Fuck ", 1, strlen("Fuck "), pFile);
	fclose(pFile);
	//int res = fflush(pFile);	//�����ӻ�������д�����
	//char ch[10];
	//_itoa_s(res, ch, 10);
	//MessageBox(ch);*/

	/*FILE *pFile;
	//fopen_s(&pFile, "2.txt", "w");	//���ı���ʽд
	fopen_s(&pFile, "2.txt", "wb");		//�Զ����Ʒ�ʽд
	char ch[3];
	ch[0] = 'a';
	ch[1] = 10;
	ch[2] = 'b';
	fwrite(ch, 1, 3, pFile);
	fclose(pFile);*/

	/*FILE *pFile;
	fopen_s(&pFile, "3.txt", "w");
	int val = 98341;
	char ch[5];
	//_itoa_s(val, ch, 5);
	for (int i = 0; i < 5; i++)
	{
		ch[5 - i - 1] = val % 10 + 0x30;
		val /= 10;
	}
	//fwrite(&val, 4, 1, pFile);
	fwrite(ch, 1, 5, pFile);
	fclose(pFile);*/

	/*ofstream ofs("4.txt");
	ofs.write("Hello World", strlen("Hello World"));
	ofs.close();*/

	/*HANDLE hFile;
	hFile = CreateFile("5.txt", FILE_GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD dwWrites;
	WriteFile(hFile, "Hello World!", strlen("Hello World!"), &dwWrites, NULL);
	CloseHandle(hFile);*/

	/*CFile file("6.txt", CFile::modeWrite | CFile::modeCreate);
	file.Write("Hello World", strlen("Hello World"));
	file.Close();*/

	CFileDialog fileDlg(FALSE);
	fileDlg.m_ofn.lpstrTitle = "�ҵ��ļ�";	//�Ի������
	fileDlg.m_ofn.lpstrFilter = "Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";	//�ļ���ʽ������
	fileDlg.m_ofn.lpstrDefExt = "txt";		//Ĭ���ļ���ʽ
	//char name[] = "hello";
	//fileDlg.m_ofn.lpstrFile = name;
	if (IDOK == fileDlg.DoModal())
	{
		CFile file(fileDlg.GetPathName(), CFile::modeWrite | CFile::modeCreate);
		file.Write("Hello World!", strlen("Hello World!"));
		file.Close();
	}
}


void CFileView::OnRegWrite()
{
	// TODO:  �ڴ���������������
	HKEY hKey;
	RegCreateKey(HKEY_LOCAL_MACHINE, "SOFTWARE\\Hello\\admin", &hKey);
	RegSetValue(hKey, NULL, REG_SZ, "DingHe", strlen("DingHe"));
	DWORD dwAge = 20;
	RegSetValueEx(hKey, "age", 0, REG_DWORD, (const BYTE*)&dwAge, 4);
	RegCloseKey(hKey);
}


void CFileView::OnRegRead()
{
	// TODO:  �ڴ���������������
	/*LONG lValue;
	RegQueryValue(HKEY_LOCAL_MACHINE, "SOFTWARE\\Hello\\admin", NULL, &lValue);	//��һ�η��س���
	char *pBuf = new char[lValue];		//������'\0'
	RegQueryValue(HKEY_LOCAL_MACHINE, "SOFTWARE\\Hello\\admin", pBuf, &lValue);	//�ڶ��η���ֵ
	MessageBox(pBuf);*/
	HKEY hKey;
	RegOpenKey(HKEY_LOCAL_MACHINE, "SOFTWARE\\Hello\\admin", &hKey);
	DWORD dwType;
	DWORD dwAge;
	DWORD dwValue;
	RegQueryValueEx(hKey, "age", 0, &dwType, (LPBYTE)&dwAge, &dwValue);
	RegCloseKey(hKey);
	CString str;
	str.Format("age=%d", dwAge);
	MessageBox(str);
}
