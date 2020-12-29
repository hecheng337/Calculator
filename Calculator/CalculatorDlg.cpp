
// CalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include "cstring"
#include "string.h"
#include "Calculate.h"
#include <exception>
#include <algorithm>
#include "HistoryDlg.h"
#include "ReadmeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON20, &CCalculatorDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CCalculatorDlg::OnBnClickedButton21)
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON19, &CCalculatorDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON23, &CCalculatorDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON22, &CCalculatorDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON29, &CCalculatorDlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON27, &CCalculatorDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON26, &CCalculatorDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON28, &CCalculatorDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON24, &CCalculatorDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON31, &CCalculatorDlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON32, &CCalculatorDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON25, &CCalculatorDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON30, &CCalculatorDlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculatorDlg::OnBnClickedButton11)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 调整字体。
	m_oFont.CreatePointFont(180, _T("黑体"));
	m_edit.SetFont(&m_oFont);

	History = _T("");
	Mem = 0;
	Ans = 0;

	// 激活快捷键。
	m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));

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

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{

	if (::TranslateAccelerator(m_hWnd,m_hAccel,pMsg))
{
    return true;
}

	return CDialog::PreTranslateMessage(pMsg);
}

void CCalculatorDlg::OnBnClickedButton1()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("1"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("1");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton2()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("2"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("2");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton12()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("."));//追加内容
	if ((strChat.Find(_T("=")) != -1) || strChat.GetLength() == 1) strChat = _T("0.");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton20()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("("));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("(");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton21()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T(")"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCalculatorDlg::OnBnClickedButton19()
{
	HistoryDlg dlg;
	dlg.History = History;
	dlg.DoModal();
}


void CCalculatorDlg::OnBnClickedButton15()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("*"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("ans*");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton17()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("/"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("ans/");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton18()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("%"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("ans%");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton23()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Delete(strChat.GetLength() - 1);//删除内容
	if (strChat.Find(_T("=")) != -1) strChat = strChat.Left(strChat.Find(_T("=")) - 1);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton22()
{
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(_T(""));//清空内容
}


void CCalculatorDlg::OnBnClickedButton29()
{
	CCalculatorDlg::OnBnClickedButton10();
	Mem -= Ans;
}


void CCalculatorDlg::OnBnClickedButton27()
{
	Mem = 0;
}


void CCalculatorDlg::OnBnClickedButton26()
{
	CString strChat;
	strChat.Format(_T("%lf"), Mem);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton28()
{
	CCalculatorDlg::OnBnClickedButton10();
	Mem += Ans;
}


void CCalculatorDlg::OnBnClickedButton16()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("-"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("ans-");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton9()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("9"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("9");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton8()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("8"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("8");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton7()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("7"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("7");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton4()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("4"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("4");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton5()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("5"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("5");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton6()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("6"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("6");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton14()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("+"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("ans+");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton24()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("sqr("));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("sqr(ans)");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton31()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("^"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("ans^");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton32()
{
	ReadmeDlg dlg;
	dlg.DoModal();
}


void CCalculatorDlg::OnBnClickedButton25()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	//修改内容
	int split = strChat.GetLength();
	if (split > 0) {
		for (; split > 0; split--) {
			if ((strChat.Mid(split - 1, 1).Compare(_T("9")) < 1) && (strChat.Mid(split - 1, 1).Compare(_T("0")) > -1))
				continue;
			break;
		}
		strChat = strChat.Left(split) + _T("1/") + strChat.Right(strChat.GetLength() - split);
	}
	else
		strChat.Append(_T("1/"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("1/ans");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton3()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("3"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("3");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容}
}

void CCalculatorDlg::OnBnClickedButton30()
{
	CAboutDlg dlg;
	dlg.DoModal();
}


void CCalculatorDlg::OnBnClickedButton10()
{
	CString strChat;
	CString str_result;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容

	if ((strChat.Find(_T("=")) != -1) || strChat.GetLength() == 0) strChat = _T("ans");

	string express = CT2A(strChat.GetString());

	try {
		for (size_t i = express.find_first_of("an"); i < express.length(); i = express.find_first_of("an", i)) {
			if (i < 0) break;
			express = express.substr(0, i) + std::to_string(Ans) + express.substr(i+3);
		}
		double result = calculate(express);//进行计算
		str_result.Format(_T(" = %g"), result);
		Ans = result;
		History.Append(_T(" | ") + strChat + str_result);
	}
	catch (const std::exception&)
	{
		str_result.Format(_T("输入有误!"));
	}

	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat + str_result);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton13()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("ans"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("ans");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}


void CCalculatorDlg::OnBnClickedButton11()
{
	CString strChat;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(strChat);//得到原有内容
	strChat.Append(_T("0"));//追加内容
	if (strChat.Find(_T("=")) != -1) strChat = _T("0");
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(strChat);//显示改变后内容
}
