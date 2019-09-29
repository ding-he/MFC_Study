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
HANDLE hMutex;
void main()
{
	HANDLE hThread1;
	HANDLE hThread2;
	hThread1 = CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);
	CloseHandle(hThread1);	//���̷߳���hThead1������
	CloseHandle(hThread2);
	/*while (nCount++<1000)
		cout << "main thread is running" << endl;
	//Sleep(1000);*/

	//hMutex = CreateMutex(NULL, TRUE, NULL);	//�ڲ����� = 1	//�����������
	hMutex = CreateMutex(NULL, TRUE, "hello");
	WaitForSingleObject(hMutex, INFINITE);	//�ڲ����� = 2
	if (hMutex)
	{
		if (GetLastError() == ERROR_ALREADY_EXISTS)
		{
			//�Ѿ�������һ��ʵ��
			cout << "There is already an istance of existence" << endl;
			return;
		}
	}
	ReleaseMutex(hMutex);					//�ڲ����� = 1
	ReleaseMutex(hMutex);					//�ڲ����� = 0
	Sleep(4000);
}

//�̺߳���
DWORD WINAPI ThreadProc1(
	_In_ LPVOID lpParameter
	)
{
	/*while (nCount++<1000)
		cout << "thread1 is running" << endl;*/
	/*while (TRUE)
	{
		WaitForSingleObject(hMutex, INFINITE);	//�ȴ������û������Ϊ���ź�״̬
		if (tickets > 0)
		{
			//Sleep(1);
			cout << "thread1 sell ticket: " << tickets-- << endl;
		}
		else
			break;
		ReleaseMutex(hMutex);	//�ͷŻ����������Ȩ
	}*/

	WaitForSingleObject(hMutex, INFINITE);	//�߳̽���, �Զ��ͷŻ������
	cout << "thread1 is running" << endl;	//�����������
	return 0;
}

DWORD WINAPI ThreadProc2(
	_In_ LPVOID lpParameter
	)
{
	/*while (TRUE)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets > 0)
		{
			//Sleep(1);
			cout << "thread2 sell ticket: " << tickets-- << endl;
		}
		else
			break;
		ReleaseMutex(hMutex);
	}*/

	WaitForSingleObject(hMutex, INFINITE);
	cout << "thread2 is running" << endl;
	return 0;
}