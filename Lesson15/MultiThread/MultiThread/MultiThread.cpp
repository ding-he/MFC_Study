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
	CloseHandle(hThread1);	//主线程放弃hThead1的引用
	CloseHandle(hThread2);
	/*while (nCount++<1000)
		cout << "main thread is running" << endl;
	//Sleep(1000);*/

	//hMutex = CreateMutex(NULL, TRUE, NULL);	//内部计数 = 1	//创建互斥对象
	hMutex = CreateMutex(NULL, TRUE, "hello");
	WaitForSingleObject(hMutex, INFINITE);	//内部计数 = 2
	if (hMutex)
	{
		if (GetLastError() == ERROR_ALREADY_EXISTS)
		{
			//已经运行了一个实例
			cout << "There is already an istance of existence" << endl;
			return;
		}
	}
	ReleaseMutex(hMutex);					//内部计数 = 1
	ReleaseMutex(hMutex);					//内部计数 = 0
	Sleep(4000);
}

//线程函数
DWORD WINAPI ThreadProc1(
	_In_ LPVOID lpParameter
	)
{
	/*while (nCount++<1000)
		cout << "thread1 is running" << endl;*/
	/*while (TRUE)
	{
		WaitForSingleObject(hMutex, INFINITE);	//等待并设置互斥对象为非信号状态
		if (tickets > 0)
		{
			//Sleep(1);
			cout << "thread1 sell ticket: " << tickets-- << endl;
		}
		else
			break;
		ReleaseMutex(hMutex);	//释放互斥对象所有权
	}*/

	WaitForSingleObject(hMutex, INFINITE);	//线程结束, 自动释放互斥对象
	cout << "thread1 is running" << endl;	//并清零计数器
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