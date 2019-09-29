// ClockCtrl.cpp : CClockCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "Clock.h"
#include "ClockCtrl.h"
#include "ClockPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CClockCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CClockCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CClockCtrl, COleControl)
	DISP_FUNCTION_ID(CClockCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_STOCKPROP_BACKCOLOR()
	DISP_STOCKPROP_FORECOLOR()
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CClockCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO:  ����Ҫ��Ӹ�������ҳ��  ���ס���Ӽ���!
BEGIN_PROPPAGEIDS(CClockCtrl, 1)
	PROPPAGEID(CClockPropPage::guid)
END_PROPPAGEIDS(CClockCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CClockCtrl, "CLOCK.ClockCtrl.1",
	0xd4de08fa, 0x2261, 0x4d9a, 0x84, 0xe6, 0x8d, 0xf6, 0xcb, 0x60, 0x94, 0x9a)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CClockCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DClock = { 0x446C6DAC, 0x46DD, 0x4226, { 0x9C, 0x26, 0x3D, 0x9E, 0xED, 0xBA, 0x2, 0xA9 } };
const IID IID_DClockEvents = { 0xE8B85249, 0x5ACB, 0x45B0, { 0xBD, 0xA4, 0xBB, 0xC1, 0x28, 0xC9, 0xAE, 0x14 } };

// �ؼ�������Ϣ

static const DWORD _dwClockOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CClockCtrl, IDS_CLOCK, _dwClockOleMisc)

// CClockCtrl::CClockCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CClockCtrl ��ϵͳע�����

BOOL CClockCtrl::CClockCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

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


// CClockCtrl::CClockCtrl - ���캯��

CClockCtrl::CClockCtrl()
{
	InitializeIIDs(&IID_DClock, &IID_DClockEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// CClockCtrl::~CClockCtrl - ��������

CClockCtrl::~CClockCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

// CClockCtrl::OnDraw - ��ͼ����

void CClockCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);

	CTime time = CTime::GetCurrentTime();
	CString strTime = time.Format("%H:%M:%S");
	pdc->TextOutW(0, 0, strTime);
}

// CClockCtrl::DoPropExchange - �־���֧��

void CClockCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CClockCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CClockCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CClockCtrl::AboutBox - ���û���ʾ�����ڡ���

void CClockCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_CLOCK);
	dlgAbout.DoModal();
}


// CClockCtrl ��Ϣ�������


int CClockCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	SetTimer(1, 1000, NULL);
	return 0;
}


void CClockCtrl::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Invalidate();
	COleControl::OnTimer(nIDEvent);
}
