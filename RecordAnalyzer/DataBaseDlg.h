#pragma once


// CDataBaseDlg 对话框

class CDataBaseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDataBaseDlg)

public:
	CDataBaseDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDataBaseDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DATABASE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
