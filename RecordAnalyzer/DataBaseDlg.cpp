// DataBaseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RecordAnalyzer.h"
#include "DataBaseDlg.h"
#include "afxdialogex.h"


// CDataBaseDlg 对话框

IMPLEMENT_DYNAMIC(CDataBaseDlg, CDialogEx)

CDataBaseDlg::CDataBaseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_DATABASE, pParent)
{

}

CDataBaseDlg::~CDataBaseDlg()
{
}

void CDataBaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDataBaseDlg, CDialogEx)
END_MESSAGE_MAP()


// CDataBaseDlg 消息处理程序
