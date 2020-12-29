// ReadmeDlg.cpp: 实现文件
//

#include "pch.h"
#include "Calculator.h"
#include "ReadmeDlg.h"
#include "afxdialogex.h"


// ReadmeDlg 对话框

IMPLEMENT_DYNAMIC(ReadmeDlg, CDialogEx)

ReadmeDlg::ReadmeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_README, pParent)
{

}

ReadmeDlg::~ReadmeDlg()
{
}

void ReadmeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ReadmeDlg, CDialogEx)
END_MESSAGE_MAP()


// ReadmeDlg 消息处理程序
