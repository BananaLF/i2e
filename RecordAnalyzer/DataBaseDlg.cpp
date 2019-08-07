// DataBaseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RecordAnalyzer.h"
#include "DataBaseDlg.h"
#include "afxdialogex.h"


// CDataBaseDlg �Ի���

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


// CDataBaseDlg ��Ϣ�������


void CDataBaseDlg::OnTvnSelchangedTreeDbFile(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CDataBaseDlg::OnNMRClickTreeDbFile(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPoint ScreenPt;
	GetCursorPos(&ScreenPt);
	CPoint ScreenTemp(ScreenPt.x, ScreenPt.y);

	//��ȡ����ǰ���ѡ������ڵ�
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

	HTREEITEM hRootItem = m_pTreeFile.InsertItem(L"�������ݿ�", NULL, TVE_EXPAND);
	m_pTreeFile.InsertItem(L"������1", hRootItem, TVI_LAST);
	m_pTreeFile.InsertItem(L"������2", hRootItem, TVI_LAST);
	m_pTreeFile.InsertItem(L"������3", hRootItem, TVI_LAST);
	m_pTreeFile.InsertItem(L"������4", hRootItem, TVI_LAST);

	//list
	m_pListTable.InsertColumn(0, L"����", LVCFMT_LEFT, 150);
	m_pListTable.InsertColumn(1, L"����", LVCFMT_LEFT, 100);
	m_pListTable.InsertColumn(2, L"ƴ��", LVCFMT_LEFT, 100);
	m_pListTable.InsertColumn(3, L"ְλ", LVCFMT_LEFT, 100);

	m_pListTable.SetColumnWidth(2, 100);

	m_pListTable.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_ONECLICKACTIVATE);  //��������״


	return TRUE;
}

void CDataBaseDlg::OnRClickNodeMenu(HTREEITEM hi, CPoint pt)
{
	//CMenu menu;
	//menu.LoadMenuW(IDR_MENU1);
	//CMenu* pPopup = menu.GetSubMenu(0);//װ�ص�һ���Ӳ˵��������ǲ˵��ĵ�һ

	//iDMenu = pPopup->TrackPopupMenu(TPM_RETURNCMD, pt.x, pt.y, this);//�����˵�
}

void CDataBaseDlg::OnRClickMenu(CPoint pt)
{
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	CMenu* pPopup = menu.GetSubMenu(1);//װ�ص�һ���Ӳ˵��������ǲ˵��ĵ�һ
	int iDMenu = pPopup->TrackPopupMenu(TPM_RETURNCMD, pt.x, pt.y, this);//�����˵�

	wchar_t szMsg[100] = { 0 };
	wsprintf(szMsg, L"ѡ���˵�%d�",iDMenu);
	MessageBox(szMsg, L"�Ҽ����",NULL);
}