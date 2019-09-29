
// ChatDlg.h : ͷ�ļ�
//

#pragma once
#include <WS2tcpip.h>

#define WM_SOCK				WM_USER + 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1

// CChatDlg �Ի���
class CChatDlg : public CDialogEx
{
// ����
public:
	CChatDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CHAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	SOCKET m_socket;
	BOOL InitSocket();
protected:
	afx_msg LRESULT OnSock(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedBtnSend();
	~CChatDlg();
};
