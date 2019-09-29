#define _CRT_SECURE_NO_DEPRECATE
#include <Windows.h>
#include <stdio.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	//主函数
	//1.注册类
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//背景颜色
	wndClass.hCursor = LoadCursor(NULL, IDC_HAND);//光标
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = "Hello";
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_VREDRAW | CS_HREDRAW;
	RegisterClass(&wndClass);//注册

	//2.创建窗口
	HWND hwnd = CreateWindow("Hello", "Hello World", WS_OVERLAPPEDWINDOW, 50, 50, 600, 400, NULL, NULL, hInstance, NULL);

	//3.显示窗口
	ShowWindow(hwnd, SW_SHOWNORMAL);
	//4.更新窗口
	UpdateWindow(hwnd);

	//5.消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)){
		//获得消息
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

int count = 0;

//回调函数
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	switch (uMsg){
		//绘制
	case WM_PAINT:
		HDC hDC;
		PAINTSTRUCT ps;
		hDC = BeginPaint(hWnd, &ps);
		TextOut(hDC, 0, 0, "Hello World!", strlen("Hello World!"));
		EndPaint(hWnd, &ps);
		break;
		//按键按下
	case WM_CHAR:
		char sChar[200];
		sprintf_s(sChar, 200, "char is %c, ASCII is %d", wParam, wParam);
		MessageBox(hWnd, sChar, "Demo", MB_HELP);
		break;
	case WM_LBUTTONDOWN:
		//鼠标左键
		MessageBox(hWnd, "mouse is clicked", "Demo", 0);
		HDC hdc;
		hdc = GetDC(hWnd);
		count += 20;
		TextOut(hdc, 0, count, "Big dradra", strlen("Big dradra"));
		ReleaseDC(hWnd, hdc);
		break;
		//关闭
	case WM_CLOSE:
		if (IDYES == MessageBox(hWnd, "Are you OK?", "Exit", MB_YESNO)){
			DestroyWindow(hWnd);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}