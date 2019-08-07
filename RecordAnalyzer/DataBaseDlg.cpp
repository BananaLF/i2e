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
	DDX_Control(pDX, IDC_LIST_TABEL, m_pListTable);
}


BEGIN_MESSAGE_MAP(CDataBaseDlg, CDialogEx)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_DB_FILE, &CDataBaseDlg::OnTvnSelchangedTreeDbFile)
	ON_NOTIFY(NM_RCLICK, IDC_TREE_DB_FILE, &CDataBaseDlg::OnNMRClickTreeDbFile)
END_MESSAGE_MAP()


// CDataBaseDlg 消息处理程序


void CDataBaseDlg::OnTvnSelchangedTreeDbFile(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CDataBaseDlg::OnNMRClickTreeDbFile(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	CPoint ScreenPt;
	GetCursorPos(&ScreenPt);
	CPoint ScreenTemp(ScreenPt.x, ScreenPt.y);

	//获取到当前鼠标选择的树节点
	::ScreenToClient(m_hWnd, &ScreenTemp);
	//m_pListTable.ScreenToClient(&ScreenPt);
	HTREEITEM hItem = NULL;
	int item = m_pListTable.HitTest(ScreenTemp);
	if (item > 0)
	{
		OnRClickNodeMenu(hItem,ScreenPt);
	}
	else
	{
		OnRClickMenu(ScreenPt);
	}
	*pResult = 0;
}

BOOL CDataBaseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CWnd* hWnd = (CWnd*)GetDlgItem(IDC_TREE_DB_FILE);
	m_pTreeFile.Attach(*hWnd);

	HTREEITEM hRootItem = m_pTreeFile.InsertItem(L"话单数据库", NULL, TVE_EXPAND);
	m_pTreeFile.InsertItem(L"话单表1", hRootItem, TVI_LAST);
	m_pTreeFile.InsertItem(L"话单表2", hRootItem, TVI_LAST);
	m_pTreeFile.InsertItem(L"话单表3", hRootItem, TVI_LAST);
	m_pTreeFile.InsertItem(L"话单表4", hRootItem, TVI_LAST);

	//list
	m_pListTable.InsertColumn(0, L"姓名", LVCFMT_LEFT, 150);
	m_pListTable.InsertColumn(1, L"年龄", LVCFMT_LEFT, 100);
	m_pListTable.InsertColumn(2, L"拼音", LVCFMT_LEFT, 100);
	m_pListTable.InsertColumn(3, L"职位", LVCFMT_LEFT, 100);

	m_pListTable.SetColumnWidth(2, 100);

	m_pListTable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_ONECLICKACTIVATE);  //设置网格状


	return TRUE;
}

void CDataBaseDlg::OnRClickNodeMenu(HTREEITEM hi, CPoint pt)
{
	//CMenu menu;
	//menu.LoadMenuW(IDR_MENU1);
	//CMenu* pPopup = menu.GetSubMenu(0);//装载第一个子菜单，即我们菜单的第一

	//iDMenu = pPopup->TrackPopupMenu(TPM_RETURNCMD, pt.x, pt.y, this);//弹出菜单
}

void CDataBaseDlg::OnRClickMenu(CPoint pt)
{
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	CMenu* pPopup = menu.GetSubMenu(1);//装载第一个子菜单，即我们菜单的第一
	int iDMenu = pPopup->TrackPopupMenu(TPM_RETURNCMD, pt.x, pt.y, this);//弹出菜单

	wchar_t szMsg[100] = { 0 };
	wsprintf(szMsg, L"选择了第%d项。",iDMenu);
	MessageBox(szMsg, L"右键点击",NULL);
}