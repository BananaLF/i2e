// ConnectFile.cpp : 实现文件
//

#include "stdafx.h"
#include "RecordAnalyzer.h"
#include "ConnectFile.h"
#include "afxdialogex.h"


// CConnectFile 对话框

IMPLEMENT_DYNAMIC(CConnectFile, CDialogEx)

CConnectFile::CConnectFile(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CONNECT, pParent)
{

}

CConnectFile::~CConnectFile()
{
}

void CConnectFile::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConnectFile, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT_CHOOSE, &CConnectFile::OnBnClickedButtonConnectChoose)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT_OK, &CConnectFile::OnBnClickedButtonConnectOk)
END_MESSAGE_MAP()


// CConnectFile 消息处理程序
void CConnectFile::OnBnClickedButtonConnectChoose()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strFile = _T("");

	CFileDialog  dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.cfg)|*.cfg|All Files (*.*)|*.*||"), NULL);

	if (dlgFile.DoModal())
	{
		strFile = dlgFile.GetPathName();
	}

	SetDlgItemText(IDC_EDIT_CONNECT_FILE, strFile);
}


void CConnectFile::OnBnClickedButtonConnectOk()
{
	CString strFile = _T("");
	GetDlgItemText(IDC_EDIT_CONNET_NAME, strFile);

	strFile = _T("");
	GetDlgItemText(IDC_EDIT_CONNECT_FILE, strFile);

	this->DestroyWindow();
}
