// ClockPropPage.cpp : CClockPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "Clock.h"
#include "ClockPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CClockPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CClockPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CClockPropPage, "CLOCK.ClockPropPage.1",
	0x83b293f1, 0x8591, 0x4fa0, 0x8e, 0x9a, 0x70, 0xf7, 0x2e, 0x36, 0x26, 0xd0)

// CClockPropPage::CClockPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CClockPropPage ��ϵͳע�����

BOOL CClockPropPage::CClockPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CLOCK_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CClockPropPage::CClockPropPage - ���캯��

CClockPropPage::CClockPropPage() :
	COlePropertyPage(IDD, IDS_CLOCK_PPG_CAPTION)
{
}

// CClockPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CClockPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CClockPropPage ��Ϣ�������
