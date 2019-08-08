#pragma once


// CConnectFile 对话框

class CConnectFile : public CDialogEx
{
	DECLARE_DYNAMIC(CConnectFile)

public:
	CConnectFile(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CConnectFile();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonConnectChoose();
	afx_msg void OnBnClickedButtonConnectOk();
};
