#pragma once


// CConnectFile �Ի���

class CConnectFile : public CDialogEx
{
	DECLARE_DYNAMIC(CConnectFile)

public:
	CConnectFile(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CConnectFile();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonConnectChoose();
	afx_msg void OnBnClickedButtonConnectOk();
};
