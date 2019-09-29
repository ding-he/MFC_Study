// Clock.cpp : CClockApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "Clock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CClockApp theApp;

const GUID CDECL _tlid = { 0xB0AD96A5, 0x2EE1, 0x415A, { 0x88, 0xC4, 0x50, 0x35, 0x95, 0xE8, 0x76, 0xDF } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CClockApp::InitInstance - DLL ��ʼ��

BOOL CClockApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CClockApp::ExitInstance - DLL ��ֹ

int CClockApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
