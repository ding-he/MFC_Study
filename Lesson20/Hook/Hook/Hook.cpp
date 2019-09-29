#include <Windows.h>

_declspec(dllexport) HHOOK g_hMouse = NULL;
HHOOK g_hKeyboard = NULL;
//_declspec(dllexport) HINSTANCE g_hInst = NULL;
HWND g_hWnd = NULL;

_declspec(dllexport) LRESULT CALLBACK MouseProc(
	_In_ int    nCode,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
	)
{
	return 1;
}

/*BOOL WINAPI DllMain(
	_Out_ HINSTANCE hInstance,
	_In_  ULONG     ulReason,
	LPVOID    Reserved
	)
{
	g_hInst = hInstance;
}*/

LRESULT CALLBACK KeyboardProc(
	_In_ int    code,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
	)
{
	if (VK_F2 == wParam)
	{
		SendMessage(g_hWnd, WM_CLOSE, 0, 0);
		UnhookWindowsHookEx(g_hMouse);
		UnhookWindowsHookEx(g_hKeyboard);
	}
	return 1;
}

_declspec(dllexport) void SetHook(HWND hwnd)
{
	g_hWnd = hwnd;
	g_hMouse = SetWindowsHookEx(WH_MOUSE, MouseProc, GetModuleHandle("Hook"), 0);		//È«¾Ö¹³×Ó
	g_hKeyboard = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, GetModuleHandle("Hook"), 0);
	//MessageBox(NULL, "hello", "hello", 0);
}
