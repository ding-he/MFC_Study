#define DLL1_API extern "C" _declspec(dllexport)
#include "Dll1.h"

#include <Windows.h>
#include <stdio.h>

DLL1_API int /*_stdcall*/ add(int x, int y)
{
	return x + y;
}

DLL1_API int /*_stdcall*/ subtract(int x, int y)
{
	return x - y;
}



/*void Point::output(int x, int y)
{
	HWND hwnd = GetForegroundWindow();		//获得前景窗口句柄
	HDC hdc = GetDC(hwnd);
	char buf[20];
	memset(buf, 0, 20);
	sprintf_s(buf, "x = %d, y = %d", x, y);
	TextOut(hdc, 0, 0, buf, strlen(buf));
	ReleaseDC(hwnd, hdc);					//释放DC
}*/