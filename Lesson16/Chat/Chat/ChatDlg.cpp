
// ChatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Chat.h"
#include "ChatDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChatDlg 对话框



CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChatDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChatDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_SOCK, &CChatDlg::OnSock)
	ON_BN_CLICKED(IDC_BTN_SEND, &CChatDlg::OnBnClickedBtnSend)
END_MESSAGE_MAP()


// CChatDlg 消息处理程序

BOOL CChatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	InitSocket();		//初始化套接字

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CChatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CChatDlg::InitSocket()
{
	//创建套接字
	m_socket = WSASocketW(AF_INET, SOCK_DGRAM, 0, NULL, 0, 0);

	if (m_socket == INVALID_SOCKET)
	{
		MessageBox("创建套接字失败");
		return FALSE;
	}

	SOCKADDR_IN addrSock;
	addrSock.sin_family = AF_INET;
	addrSock.sin_port = htons(6000);
	addrSock.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	int err = bind(m_socket, (SOCKADDR*)&addrSock, sizeof(SOCKADDR));
	if (err == SOCKET_ERROR)
	{
		MessageBox("绑定失败");
		return FALSE;
	}

	//注册网络读取事件
	err = WSAAsyncSelect(m_socket, m_hWnd, WM_SOCK, FD_READ);
	//err = WSAEventSelect(m_socket, m_hWnd, WM_SOCK, FD_READ);
	if (err == SOCKET_ERROR)
	{
		MessageBox("注册网络读取事件失败");
		return FALSE;
	}

	return TRUE;
}


afx_msg LRESULT CChatDlg::OnSock(WPARAM wParam, LPARAM lParam)
{

	//判断事件类型
	switch (LOWORD(lParam))
	{
	case FD_READ:						//读取
	{
		WSABUF wsaBuf;					//接收数据
		wsaBuf.buf = new char[200];
		wsaBuf.len = 200;

		DWORD dwRead;					//实际所读
		DWORD dwFlag = 0;

		SOCKADDR_IN addrSock;
		int len = sizeof(SOCKADDR);		//地址信息

		CString str;
		CString strTemp;

		if (SOCKET_ERROR == WSARecvFrom(m_socket, &wsaBuf, 1, &dwRead, &dwFlag, (SOCKADDR*)&addrSock, &len, NULL, NULL))
		{
			MessageBox("接收数据失败");
			delete[] wsaBuf.buf;
			return 0;
		}

		//char ipBuf[20];
		//inet_ntop(AF_INET, &addrSock.sin_addr.S_un.S_addr, ipBuf, 16);

		HOSTENT *pHost;
		pHost = gethostbyaddr((char*)&addrSock.sin_addr.S_un.S_addr, 4, AF_INET);
		//str.Format("%s say: %s", ipBuf, wsaBuf.buf);
		str.Format("%s say: %s", pHost->h_name, wsaBuf.buf);

		GetDlgItemText(IDC_EDIT_RECV, strTemp);
		CTime time = CTime::GetCurrentTime();
		//回车换行
		str = time.Format("%H:%M:%S") + "\r\n" + str + "\r\n";
		strTemp += str;
		SetDlgItemText(IDC_EDIT_RECV, strTemp);
		break;
	}
	default:
		break;
	}
	return 0;
}


void CChatDlg::OnBnClickedBtnSend()
{
	// TODO:  在此添加控件通知处理程序代码
	DWORD dwIP;
	CString strSend;
	WSABUF wsaBuf;
	DWORD dwSend;
	int len;
	SOCKADDR_IN addrSock;

	CString strHostName;			//主机名
	HOSTENT *pHost;
	
	GetDlgItemText(IDC_EDIT_HOSTNAME, strHostName);
	if (strHostName == "")
	{
		((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1))->GetAddress(dwIP);
		addrSock.sin_addr.S_un.S_addr = htonl(dwIP);
	}
	else
	{
		pHost = gethostbyname(strHostName);			//"DingHe-PC"
		addrSock.sin_addr.S_un.S_addr = *((u_long*)pHost->h_addr_list[0]);
	}

	addrSock.sin_family = AF_INET;
	addrSock.sin_port = htons(6000);

	GetDlgItemText(IDC_EDIT_SEND, strSend);
	len = strSend.GetLength();
	wsaBuf.buf = strSend.GetBuffer(len);
	wsaBuf.len = len + 1;

	SetDlgItemText(IDC_EDIT_SEND, "");			//清空

	if (SOCKET_ERROR == WSASendTo(m_socket, &wsaBuf, 1, &dwSend, 0, (SOCKADDR*)&addrSock, sizeof(SOCKADDR), NULL, NULL))
	{
		MessageBox("发送数据失败");
		return;
	}
}


CChatDlg::~CChatDlg()
{
	//关闭套接字
	if (m_socket)
	{
		closesocket(m_socket);
	}
}
