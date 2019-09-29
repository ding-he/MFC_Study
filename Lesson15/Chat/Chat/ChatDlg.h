
// ChatDlg.h : 头文件
//

#pragma once

#define WM_RECVDATA		WM_USER + 1

// CChatDlg 对话框
class CChatDlg : public CDialogEx
{
// 构造
public:
	CChatDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CChatDlg();

// 对话框数据
	enum { IDD = IDD_CHAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	SOCKET m_socket;
private:
	BOOL InitSocket();

private:
	static DWORD WINAPI RecvProc(	//必须声明为静态方法
		_In_ LPVOID lpParameter
		);
protected:
	afx_msg LRESULT OnRecvdata(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedBtnSend();
};

//套接字和对话框句柄
struct RECVPARAM
{
	SOCKET sock;
	HWND hwnd;
};
