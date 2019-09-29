#include <Windows.h>
#include <iostream>

using namespace std;


DWORD WINAPI ThreadProc1(
	_In_ LPVOID lpParameter
	);
DWORD WINAPI ThreadProc2(
	_In_ LPVOID lpParameter
	);

int nCount = 0;
int tickets = 100;
HANDLE g_hEvent;
void main()
{
	HANDLE hThread1;
	HANDLE hThread2;
	hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);
	CloseHandle(hThread1);	//���̷߳���hThead1������
	CloseHandle(hThread2);
	
	g_hEvent = CreateEvent(NULL, FALSE, FALSE, "hello");	//�����¼�����

	if (g_hEvent)
	{
		if (GetLastError() == ERROR_ALREADY_EXISTS)
		{
			cout << "there is already an instance of existence" << endl;
			return;
		}
	}
	SetEvent(g_hEvent);

	Sleep(4000);
}

//�̺߳���
DWORD WINAPI ThreadProc1(
	_In_ LPVOID lpParameter
	)
{
	while (TRUE)
	{
		WaitForSingleObject(g_hEvent, INFINITE);	//�ȴ������û������Ϊ���ź�״̬
		//ResetEvent(g_hEvent);
		if (tickets > 0)
		{
			//Sleep(1);
			cout << "thread1 sell ticket: " << tickets-- << endl;
		}
		else
			break;
		SetEvent(g_hEvent);
	}

	return 0;
}

DWORD WINAPI ThreadProc2(
	_In_ LPVOID lpParameter
	)
{
	while (TRUE)
	{
		WaitForSingleObject(g_hEvent, INFINITE); 
		//ResetEvent(g_hEvent);
		if (tickets > 0)
		{
			//Sleep(1);
			cout << "thread2 sell ticket: " << tickets-- << endl;
		}
		else
			break;
		SetEvent(g_hEvent);
	}

	return 0;
}