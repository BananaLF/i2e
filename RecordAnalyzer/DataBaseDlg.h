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
};
