#pragma once


// CDataBaseDlg �Ի���

class CDataBaseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDataBaseDlg)

public:
	CDataBaseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDataBaseDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DATABASE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchangedTreeDbFile(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickTreeDbFile(NMHDR *pNMHDR, LRESULT *pResult);

	virtual BOOL OnInitDialog();

	void OnRClickNodeMenu(HTREEITEM hi, CPoint pt);
	void OnRClickMenu(CPoint pt);

private:
	CTreeCtrl m_pTreeFile;
	CListCtrl m_pListTable;

public:
	afx_msg void OnRcAdd();
	afx_msg void OnRcRemove();
	afx_msg void OnRcEmpty();
	afx_msg void OnRcPull();
	afx_msg void OnRcPush();
};
