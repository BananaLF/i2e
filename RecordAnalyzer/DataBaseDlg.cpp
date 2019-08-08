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
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_TABEL, &CDataBaseDlg::OnLvnColumnclickListTabel)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_TABEL, &CDataBaseDlg::OnNMRClickListTabel)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_DB_FILE, &CDataBaseDlg::OnNMDblclkTreeDbFile)
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
	//::ScreenToClient(m_hWnd, &ScreenTemp);
	m_pTreeFile.ScreenToClient(&ScreenTemp);
	HTREEITEM hItem = m_pTreeFile.HitTest(ScreenTemp);
	if (hItem)
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


	HICON hIcon[2];      // 图标句柄数组   

	hIcon[0] = theApp.LoadIcon(IDC_ICON_TABEL);
	hIcon[1] = theApp.LoadIcon(IDC_ICON_TABEL);


	// 创建图像序列CImageList对象   
	m_imageList.Create(16, 16, ILC_COLOR32, 2, 2);
	// 将三个图标添加到图像序列   
	for (int i = 0; i<2; i++)
	{
		m_imageList.Add(hIcon[i]);
	}

	// 为树形控件设置图像序列   
	m_pTreeFile.SetImageList(&m_imageList, TVSIL_NORMAL);


	HTREEITEM hRootItem = m_pTreeFile.InsertItem(L"话单数据库", NULL, TVE_EXPAND);
	m_pTreeFile.InsertItem(L"话单表1", hRootItem, TVI_LAST);
	m_pTreeFile.InsertItem(L"话单表2", hRootItem, TVI_LAST);
	m_pTreeFile.InsertItem(L"话单表3", hRootItem, TVI_LAST);
	m_pTreeFile.InsertItem(L"话单表4", hRootItem, TVI_LAST);

	HTREEITEM hRootItem2 = m_pTreeFile.InsertItem(L"银行数据库", NULL, TVE_EXPAND);

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
	int iDMenu = ShowCustonMenu(pt, 1);
}

void CDataBaseDlg::OnRClickMenu(CPoint pt)
{
	int iDMenu = ShowCustonMenu(pt,0);

	switch (iDMenu)
	{
	case ID_RC_ADD:
		m_ConnectDlg.Create(IDD_DIALOG_CONNECT,this);
		m_ConnectDlg.ShowWindow(SW_SHOW);
		m_ConnectDlg.CenterWindow();
		break;
	case ID_RC_REMOVE:
		break;
	case ID_RC_EMPTY:
		break;
	case ID_RC_PULL:
		break;
	case ID_RC_PUSH:
		break;
	}
}
int CDataBaseDlg::ShowCustonMenu(CPoint pt, int index )
{
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	CMenu* pPopup = menu.GetSubMenu(index);//装载第一个子菜单，即我们菜单的第一
	
	return  pPopup->TrackPopupMenu(TPM_RETURNCMD, pt.x, pt.y, this);
}

void CDataBaseDlg::OnLvnColumnclickListTabel(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	*pResult = 0;
}


void CDataBaseDlg::OnNMRClickListTabel(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	CPoint ScreenPt;
	GetCursorPos(&ScreenPt);

	int iDMenu = ShowCustonMenu(ScreenPt, 2);


	*pResult = 0;
}


//双击选中表
void CDataBaseDlg::OnNMDblclkTreeDbFile(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;
}
