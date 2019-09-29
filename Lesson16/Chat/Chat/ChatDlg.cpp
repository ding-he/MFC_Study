
// ChatDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Chat.h"
#include "ChatDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CChatDlg �Ի���



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


// CChatDlg ��Ϣ�������

BOOL CChatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	InitSocket();		//��ʼ���׽���

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CChatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CChatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CChatDlg::InitSocket()
{
	//�����׽���
	m_socket = WSASocketW(AF_INET, SOCK_DGRAM, 0, NULL, 0, 0);

	if (m_socket == INVALID_SOCKET)
	{
		MessageBox("�����׽���ʧ��");
		return FALSE;
	}

	SOCKADDR_IN addrSock;
	addrSock.sin_family = AF_INET;
	addrSock.sin_port = htons(6000);
	addrSock.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	int err = bind(m_socket, (SOCKADDR*)&addrSock, sizeof(SOCKADDR));
	if (err == SOCKET_ERROR)
	{
		MessageBox("��ʧ��");
		return FALSE;
	}

	//ע�������ȡ�¼�
	err = WSAAsyncSelect(m_socket, m_hWnd, WM_SOCK, FD_READ);
	//err = WSAEventSelect(m_socket, m_hWnd, WM_SOCK, FD_READ);
	if (err == SOCKET_ERROR)
	{
		MessageBox("ע�������ȡ�¼�ʧ��");
		return FALSE;
	}

	return TRUE;
}


afx_msg LRESULT CChatDlg::OnSock(WPARAM wParam, LPARAM lParam)
{

	//�ж��¼�����
	switch (LOWORD(lParam))
	{
	case FD_READ:						//��ȡ
	{
		WSABUF wsaBuf;					//��������
		wsaBuf.buf = new char[200];
		wsaBuf.len = 200;

		DWORD dwRead;					//ʵ������
		DWORD dwFlag = 0;

		SOCKADDR_IN addrSock;
		int len = sizeof(SOCKADDR);		//��ַ��Ϣ

		CString str;
		CString strTemp;

		if (SOCKET_ERROR == WSARecvFrom(m_socket, &wsaBuf, 1, &dwRead, &dwFlag, (SOCKADDR*)&addrSock, &len, NULL, NULL))
		{
			MessageBox("��������ʧ��");
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
		//�س�����
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	DWORD dwIP;
	CString strSend;
	WSABUF wsaBuf;
	DWORD dwSend;
	int len;
	SOCKADDR_IN addrSock;

	CString strHostName;			//������
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

	SetDlgItemText(IDC_EDIT_SEND, "");			//���

	if (SOCKET_ERROR == WSASendTo(m_socket, &wsaBuf, 1, &dwSend, 0, (SOCKADDR*)&addrSock, sizeof(SOCKADDR), NULL, NULL))
	{
		MessageBox("��������ʧ��");
		return;
	}
}


CChatDlg::~CChatDlg()
{
	//�ر��׽���
	if (m_socket)
	{
		closesocket(m_socket);
	}
}
