#include <Windows.h>
#include <iostream>

using namespace std;


DWORD WINAPI ThreadProc1(
	_In_ LPVOID lpParameter
	);
DWORD WINAPI ThreadProc2(
	_In_ LPVOID lpParameter
	);

int tickets = 100;
//CRITICAL_SECTION g_cs;
CRITICAL_SECTION g_csA;		//����
CRITICAL_SECTION g_csB;

void main()
{
	HANDLE hThread1;
	HANDLE hThread2;
	hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);
	CloseHandle(hThread1);	//���̷߳���hThead1������
	CloseHandle(hThread2);

	//InitializeCriticalSection(&g_cs);	//�����ٽ�������
	InitializeCriticalSection(&g_csA);
	InitializeCriticalSection(&g_csB);

	Sleep(4000);
	//DeleteCriticalSection(&g_cs);		//�ͷ��ٽ�������
	DeleteCriticalSection(&g_csA);
	DeleteCriticalSection(&g_csB);
}

//�̺߳���
DWORD WINAPI ThreadProc1(
	_In_ LPVOID lpParameter
	)
{
	while (TRUE)
	{
		//EnterCriticalSection(&g_cs);	//����ٽ������������Ȩ
		EnterCriticalSection(&g_csA);
		Sleep(1);
		EnterCriticalSection(&g_csB);
		//Sleep(1);
		if (tickets > 0)
		{
			//Sleep(1);
			cout << "thread1 sell ticket: " << tickets-- << endl;
		}
		else
			break;
		//LeaveCriticalSection(&g_cs);	//�ͷ��ٽ������������Ȩ
		LeaveCriticalSection(&g_csB);
		LeaveCriticalSection(&g_csA);
		Sleep(1);
	}

	return 0;
}

DWORD WINAPI ThreadProc2(
	_In_ LPVOID lpParameter
	)
{
	while (TRUE)
	{
		//EnterCriticalSection(&g_cs);	//����ٽ������������Ȩ
		EnterCriticalSection(&g_csB);
		Sleep(1);
		EnterCriticalSection(&g_csA);
		//Sleep(1);
		if (tickets > 0)
		{
			//Sleep(1);
			cout << "thread2 sell ticket: " << tickets-- << endl;
		}
		else
			break;
		//LeaveCriticalSection(&g_cs);	//�ͷ��ٽ������������Ȩ
		LeaveCriticalSection(&g_csA);
		LeaveCriticalSection(&g_csB);
		Sleep(1);
	}

	return 0;
}