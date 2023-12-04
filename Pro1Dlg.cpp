
// Pro1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Pro1.h"
#include "Pro1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString CString_b1, CString_d1, CString_b2, CString_d2, CString_h1, CString_d3, CString_S0, CString_y0, CString_Jz;
double double_b1, double_d1, double_b2, double_d2, double_h1, double_d3, double_S0, double_y0, double_Jz;


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPro1Dlg 对话框



CPro1Dlg::CPro1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PRO1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPro1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT7, IDC_EDIT7_CString);
	DDX_Control(pDX, IDC_EDIT8, IDC_EDIT8_CString);
	DDX_Control(pDX, IDC_EDIT7, IDC_EDIT7_CString);
	DDX_Control(pDX, IDC_EDIT8, IDC_EDIT8_CString);
	DDX_Control(pDX, IDC_EDIT9, IDC_EDIT9_CString);
}

BEGIN_MESSAGE_MAP(CPro1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPro1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPro1Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT2, &CPro1Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDCANCEL, &CPro1Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CPro1Dlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CPro1Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT7, &CPro1Dlg::OnEnChangeEdit7)
	ON_BN_CLICKED(IDC_BUTTON1, &CPro1Dlg::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CPro1Dlg 消息处理程序

BOOL CPro1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPro1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。



//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPro1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPro1Dlg::OnBnClickedButton1()
{
	GetDlgItemText(IDC_EDIT1, CString_b1);
	GetDlgItemText(IDC_EDIT2, CString_d1);
	GetDlgItemText(IDC_EDIT3, CString_b2);
	GetDlgItemText(IDC_EDIT4, CString_d2);
	GetDlgItemText(IDC_EDIT5, CString_h1);
	GetDlgItemText(IDC_EDIT6, CString_d3);
	double_b1 = _ttof(CString_b1);
	double_d1 = _ttof(CString_d1);
	double_b2 = _ttof(CString_b2);
	double_d2 = _ttof(CString_d2);
	double_h1 = _ttof(CString_h1);
	double_d3 = _ttof(CString_d3);

	double_S0 = CalculateArea(double_b1, double_d1, double_b2, double_d2, double_h1, double_d3);
	double_y0 = CalculateNeutralAxis(double_b1, double_d1, double_b2, double_d2, double_h1, double_d3);
	double_Jz = CalculateInertia(double_b1, double_d1, double_b2, double_d2, double_h1, double_d3, double_y0);

	CString_S0.Format(_T("%lf"), double_S0);
	CString_y0.Format(_T("%lf"), double_y0);
	CString_Jz.Format(_T("%lf"), double_Jz);


	IDC_EDIT7_CString.SetWindowText(CString_S0);
	IDC_EDIT8_CString.SetWindowText(CString_y0);
	IDC_EDIT9_CString.SetWindowText(CString_Jz);

	Invalidate();


}
double CalculateArea(double b1, double d1, double b2, double d2, double h1, double d3)
{
	return (b1 * d1) + (h1 * d3) + (b2 * d2);
}
double CalculateNeutralAxis(double b1, double d1, double b2, double d2, double h1, double d3)
{
	double A1 = b1 * d1; // 上翼缘板面积
	double A2 = b2 * d2; // 下翼缘板面积
	double A3 = h1 * d3; // 腹板面积

	double y1 = d1 + h1 + d2 / 2.0; // 上翼缘板重心到下翼板底部的距离
	double y2 = d2 / 2.0;           // 下翼缘板重心到下翼板底部的距离
	double y3 = d2 + h1 / 2.0;      // 腹板重心到下翼板底部的距离

	double S0 = A1 + A2 + A3;
	double y0 = (A1 * y1 + A2 * y2 + A3 * y3) / S0;
	return y0 / 2.0; // 中性轴位置相对于下翼板底部
}

double CalculateInertia(double b1, double d1, double b2, double d2, double h1, double d3, double y0)
{
	double A1 = b1 * d1;
	double A2 = b2 * d2;
	double A3 = h1 * d3;

	double y1 = d1 + h1 + d2 / 2.0;
	double y2 = d2 / 2.0;
	double y3 = d2 + h1 / 2.0;

	// 计算各部分的截面惯性矩
	double J1 = (b1 * pow(d1, 3)) / 12.0 + A1 * pow(y0*2 - y1, 2);
	double J2 = (b2 * pow(d2, 3)) / 12.0 + A2 * pow(y0*2 - y2, 2);
	double J3 = (d3 * pow(h1, 3)) / 12.0 + A3 * pow(y0*2 - y3, 2);

	// 计算整个截面的惯性矩
	double Jz = J1 + J2 + J3;
	return Jz; // 截面惯性矩相对于中性轴
}


void CPro1Dlg::OnBnClickedButton2()
{
	CDialogEx::OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}


void CPro1Dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CPro1Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CPro1Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CPro1Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CPro1Dlg::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
}


void CPro1Dlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// 假设所有参数都已经通过用户输入得到并转换为了双精度浮点数
	// 以下是示例参数，您需要从对话框中获取实际的参数
	double b1 = double_b1; // 上翼缘板宽
	double d1 = double_d1; // 上翼缘板厚
	double b2 = double_b2; // 下翼缘板宽
	double d2 = double_d2; // 下翼缘板厚
	double h1 = double_h1; // 腹板净高
	double d3 = double_d3; // 腹板厚

	// 计算绘制的起始点，这里我们将图形绘制在对话框的中心
	CRect rect;
	GetClientRect(&rect);
	int centerX = rect.Width() / 2 / 2;
	int centerY = rect.Height() / 2;
	int topY = centerY - (h1 + d1 + d2) / 2;

	// 绘制上翼缘
	dc.Rectangle(centerX - b1 / 2, topY, centerX + b1 / 2, topY + d1);

	// 绘制腹板
	dc.Rectangle(centerX - d3 / 2, topY + d1, centerX + d3 / 2, topY + d1 + h1);

	// 绘制下翼缘
	dc.Rectangle(centerX - b2 / 2, topY + d1 + h1, centerX + b2 / 2, topY + d1 + h1 + d2);

	// 调用默认的OnPaint处理程序来处理未处理的消息
	CDialogEx::OnPaint();
}