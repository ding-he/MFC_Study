
// FileView.cpp : CFileView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_FILE_READ, &CFileView::OnFileRead)
	ON_COMMAND(IDM_FILE_WRITE, &CFileView::OnFileWrite)
	ON_COMMAND(IDM_REG_WRITE, &CFileView::OnRegWrite)
	ON_COMMAND(IDM_REG_READ, &CFileView::OnRegRead)
END_MESSAGE_MAP()

// CFileView 构造/析构

CFileView::CFileView()
{
	// TODO:  在此处添加构造代码

}

CFileView::~CFileView()
{
}

BOOL CFileView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFileView 绘制

void CFileView::OnDraw(CDC* /*pDC*/)
{
	CFileDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CFileView 打印

BOOL CFileView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFileView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CFileView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CFileView 诊断

#ifdef _DEBUG
void CFileView::AssertValid() const
{
	CView::AssertValid();
}

void CFileView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFileDoc* CFileView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileDoc)));
	return (CFileDoc*)m_pDocument;
}
#endif //_DEBUG


// CFileView 消息处理程序


void CFileView::OnFileRead()
{
	// TODO:  在此添加命令处理程序代码
	/*FILE *pFile;
	fopen_s(&pFile, "1.txt", "r");
	//char buf[100];
	//memset(buf, 0, 100);
	char *pBuf;
	fseek(pFile, 0, SEEK_END);
	int len = ftell(pFile);
	pBuf = new char[len + 1];
	rewind(pFile);	//重新将文件指针指向文件开头
	fread(pBuf, 1, 100, pFile);
	pBuf[len] = 0;
	fclose(pFile);
	MessageBox(pBuf);*/

	/*FILE *pFile;
	//fopen_s(&pFile, "2.txt", "r");	//以文本方式读
	fopen_s(&pFile, "2.txt", "rb");		//以二进制读
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
	fileDlg.m_ofn.lpstrTitle = "我的文件";	//对话框标题
	fileDlg.m_ofn.lpstrFilter = "Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";	//文件格式过滤器
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
	// TODO:  在此添加命令处理程序代码
	/*FILE *pFile;
	fopen_s(&pFile, "1.txt", "w");
	fwrite("Hello World!", 1, strlen("Hello World!"), pFile);
	//fseek(pFile, 0, SEEK_SET);	//移动文件指针至文件开头
	//fwrite("Fuck ", 1, strlen("Fuck "), pFile);
	fclose(pFile);
	//int res = fflush(pFile);	//立即从缓冲区中写入磁盘
	//char ch[10];
	//_itoa_s(res, ch, 10);
	//MessageBox(ch);*/

	/*FILE *pFile;
	//fopen_s(&pFile, "2.txt", "w");	//以文本方式写
	fopen_s(&pFile, "2.txt", "wb");		//以二进制方式写
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
	fileDlg.m_ofn.lpstrTitle = "我的文件";	//对话框标题
	fileDlg.m_ofn.lpstrFilter = "Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0";	//文件格式过滤器
	fileDlg.m_ofn.lpstrDefExt = "txt";		//默认文件格式
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
	// TODO:  在此添加命令处理程序代码
	HKEY hKey;
	RegCreateKey(HKEY_LOCAL_MACHINE, "SOFTWARE\\Hello\\admin", &hKey);
	RegSetValue(hKey, NULL, REG_SZ, "DingHe", strlen("DingHe"));
	DWORD dwAge = 20;
	RegSetValueEx(hKey, "age", 0, REG_DWORD, (const BYTE*)&dwAge, 4);
	RegCloseKey(hKey);
}


void CFileView::OnRegRead()
{
	// TODO:  在此添加命令处理程序代码
	/*LONG lValue;
	RegQueryValue(HKEY_LOCAL_MACHINE, "SOFTWARE\\Hello\\admin", NULL, &lValue);	//第一次返回长度
	char *pBuf = new char[lValue];		//包含了'\0'
	RegQueryValue(HKEY_LOCAL_MACHINE, "SOFTWARE\\Hello\\admin", pBuf, &lValue);	//第二次返回值
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
