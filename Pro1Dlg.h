
// Pro1Dlg.h: 头文件
//

#pragma once

extern CString CString_b1, CString_d1, CString_b2, CString_d2, CString_h1, CString_d3, CString_S0, CString_y0, CString_Jz;
extern double double_b1, double_d1, double_b2, double_d2, double_h1, double_d3, double_S0, double_y0, double_Jz;

double CalculateArea(double b1, double d1, double b2, double d2, double h1, double d3);
double CalculateNeutralAxis(double b1, double d1, double b2, double d2, double h1, double d3);
double CalculateInertia(double b1, double d1, double b2, double d2, double h1, double d3, double y0);


// CPro1Dlg 对话框
class CPro1Dlg : public CDialogEx
{
// 构造
public:
	CPro1Dlg(CWnd* pParent = nullptr);	// 标准构造函数
	afx_msg void OnPaint();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRO1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit7();
	CEdit IDC_EDIT7_CString;
	CEdit IDC_EDIT8_CString;
	CEdit IDC_EDIT9_CString;
};

