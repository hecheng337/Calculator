#pragma once


// ReadmeDlg 对话框

class ReadmeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ReadmeDlg)

public:
	ReadmeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ReadmeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_README };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
