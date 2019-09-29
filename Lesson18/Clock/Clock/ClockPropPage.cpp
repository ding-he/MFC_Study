// ClockPropPage.cpp : CClockPropPage 属性页类的实现。

#include "stdafx.h"
#include "Clock.h"
#include "ClockPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CClockPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CClockPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CClockPropPage, "CLOCK.ClockPropPage.1",
	0x83b293f1, 0x8591, 0x4fa0, 0x8e, 0x9a, 0x70, 0xf7, 0x2e, 0x36, 0x26, 0xd0)

// CClockPropPage::CClockPropPageFactory::UpdateRegistry -
// 添加或移除 CClockPropPage 的系统注册表项

BOOL CClockPropPage::CClockPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CLOCK_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CClockPropPage::CClockPropPage - 构造函数

CClockPropPage::CClockPropPage() :
	COlePropertyPage(IDD, IDS_CLOCK_PPG_CAPTION)
{
}

// CClockPropPage::DoDataExchange - 在页和属性间移动数据

void CClockPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CClockPropPage 消息处理程序
