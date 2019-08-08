#pragma once
#include "Uitles\structinfo.h"
#include "ConnectFile.h"

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
public:
	afx_msg void OnTvnSelchangedTreeDbFile(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickTreeDbFile(NMHDR *pNMHDR, LRESULT *pResult);

	virtual BOOL OnInitDialog();

	void OnRClickNodeMenu(HTREEITEM hi, CPoint pt);
	void OnRClickMenu(CPoint pt);

	int ShowCustonMenu(CPoint pt, int index = 0);

private:
	CTreeCtrl m_pTreeFile;
	CListCtrl m_pListTable;
	CImageList m_imageList;

	CConnectFile m_ConnectDlg;

public:
	afx_msg void OnLvnColumnclickListTabel(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickListTabel(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkTreeDbFile(NMHDR *pNMHDR, LRESULT *pResult);
};
