// HistoryDlg.cpp: 实现文件
//

#include "pch.h"
#include "Calculator.h"
#include "HistoryDlg.h"
#include "afxdialogex.h"


// HistoryDlg 对话框

IMPLEMENT_DYNAMIC(HistoryDlg, CDialogEx)

HistoryDlg::HistoryDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HISTORY, pParent)
{
}

HistoryDlg::~HistoryDlg()
{
}

void HistoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HistoryDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &HistoryDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


BOOL HistoryDlg::OnInitDialog() {
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(History);
	return TRUE;
}

// HistoryDlg 消息处理程序


void HistoryDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
