
// Lesson08_KEYDOWNDlg.h : ͷ�ļ�
//

#pragma once


// CLesson08_KEYDOWNDlg �Ի���
class CLesson08_KEYDOWNDlg : public CDialogEx
{
// ����
public:
	CLesson08_KEYDOWNDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LESSON08_KEYDOWN_DIALOG };

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
public:
//	HWND m_hwndDlg;
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};
