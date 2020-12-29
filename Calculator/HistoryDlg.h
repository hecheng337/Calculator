#pragma once


// HistoryDlg 对话框

class HistoryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(HistoryDlg)

public:
	HistoryDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~HistoryDlg();
	CString History;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HISTORY};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		BOOL OnInitDialog();
	void OnEnChangeEdit1();
};
