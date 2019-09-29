// Clock.cpp : CClockApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "Clock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CClockApp theApp;

const GUID CDECL _tlid = { 0xB0AD96A5, 0x2EE1, 0x415A, { 0x88, 0xC4, 0x50, 0x35, 0x95, 0xE8, 0x76, 0xDF } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CClockApp::InitInstance - DLL 初始化

BOOL CClockApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CClockApp::ExitInstance - DLL 终止

int CClockApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
