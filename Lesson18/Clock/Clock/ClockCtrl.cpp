// ClockCtrl.cpp : CClockCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "Clock.h"
#include "ClockCtrl.h"
#include "ClockPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CClockCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CClockCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CClockCtrl, COleControl)
	DISP_FUNCTION_ID(CClockCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_STOCKPROP_BACKCOLOR()
	DISP_STOCKPROP_FORECOLOR()
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CClockCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO:  按需要添加更多属性页。  请记住增加计数!
BEGIN_PROPPAGEIDS(CClockCtrl, 1)
	PROPPAGEID(CClockPropPage::guid)
END_PROPPAGEIDS(CClockCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CClockCtrl, "CLOCK.ClockCtrl.1",
	0xd4de08fa, 0x2261, 0x4d9a, 0x84, 0xe6, 0x8d, 0xf6, 0xcb, 0x60, 0x94, 0x9a)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CClockCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DClock = { 0x446C6DAC, 0x46DD, 0x4226, { 0x9C, 0x26, 0x3D, 0x9E, 0xED, 0xBA, 0x2, 0xA9 } };
const IID IID_DClockEvents = { 0xE8B85249, 0x5ACB, 0x45B0, { 0xBD, 0xA4, 0xBB, 0xC1, 0x28, 0xC9, 0xAE, 0x14 } };

// 控件类型信息

static const DWORD _dwClockOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CClockCtrl, IDS_CLOCK, _dwClockOleMisc)

// CClockCtrl::CClockCtrlFactory::UpdateRegistry -
// 添加或移除 CClockCtrl 的系统注册表项

BOOL CClockCtrl::CClockCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_CLOCK,
			IDB_CLOCK,
			afxRegApartmentThreading,
			_dwClockOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CClockCtrl::CClockCtrl - 构造函数

CClockCtrl::CClockCtrl()
{
	InitializeIIDs(&IID_DClock, &IID_DClockEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CClockCtrl::~CClockCtrl - 析构函数

CClockCtrl::~CClockCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CClockCtrl::OnDraw - 绘图函数

void CClockCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);

	CTime time = CTime::GetCurrentTime();
	CString strTime = time.Format("%H:%M:%S");
	pdc->TextOutW(0, 0, strTime);
}

// CClockCtrl::DoPropExchange - 持久性支持

void CClockCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  为每个持久的自定义属性调用 PX_ 函数。
}


// CClockCtrl::OnResetState - 将控件重置为默认状态

void CClockCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CClockCtrl::AboutBox - 向用户显示“关于”框

void CClockCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_CLOCK);
	dlgAbout.DoModal();
}


// CClockCtrl 消息处理程序


int CClockCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(1, 1000, NULL);
	return 0;
}


void CClockCtrl::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	Invalidate();
	COleControl::OnTimer(nIDEvent);
}
