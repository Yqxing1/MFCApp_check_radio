
// MFCApplication2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include "m_radio.h"
#include"CSubDlg1.h"
#include"CSubDlg2.h"
#include"CSubDlg3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDlg 对话框


CMFCDlg::CMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MFCAPPLICATION2_DIALOG, pParent)
	, nameradio(FALSE)
	, namecheck1(FALSE)
	, namecheck2(FALSE)
	, namecheck3(FALSE)
	, namecheck4(FALSE)
	, chaeckall(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, nameradio);
	DDX_Check(pDX, IDC_CHECK1, namecheck1);
	DDX_Check(pDX, IDC_CHECK2, namecheck2);
	DDX_Check(pDX, IDC_CHECK3, namecheck3);
	DDX_Check(pDX, IDC_CHECK4, namecheck4);
	DDX_Check(pDX, IDC_CHECKall, chaeckall);
	DDX_Control(pDX, IDC_user, m_username);
	DDX_Control(pDX, IDC_password, m_password);
	DDX_Control(pDX, IDC_PROGRESS3, m_progers);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CMFCDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECKall, &CMFCDlg::OnBnClickedCheckall)
	ON_COMMAND_RANGE(IDC_CHECK1, IDC_CHECK4, OnCommandRange)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCDlg::OnBnClickedlogin)
	ON_WM_HSCROLL()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCDlg::OnBnClickedButton4)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMFCDlg::OnTcnSelchangeTab1)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, &CMFCDlg::OnNMRClickList1)
	ON_COMMAND(ID_32771, &CMFCDlg::Onclick)
END_MESSAGE_MAP()


// CMFCDlg 消息处理程序

BOOL CMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_username.SetLimitText(10);
	m_password.SetLimitText(8);
	m_password.SetPasswordChar('/');
	m_progers.SetRange(0, 100);
	m_slider.SetRange(0, 100);
	m_progers.SetPos(0);
	m_progers.SetStep(5);
	SetTimer(0x11, 100, NULL);
    m_combo1.InsertString(0,L"选项一");
    m_combo1.InsertString(1,L"选项二");
	m_combo1.InsertString(2,L"选项三");
    m_tab.InsertItem(0, L"标签一");
	m_tab.InsertItem(1, L"标签二");
	m_tab.InsertItem(2, L"标签三");
	dlg[0] = new CSubDlg1();
	dlg[1] = new CSubDlg2();
	dlg[2] = new CSubDlg3();
	dlg[0]->Create(IDD_DIALOG1, &m_tab);
	dlg[1]->Create(IDD_DIALOG2, &m_tab);
	dlg[2]->Create(IDD_DIALOG3, &m_tab);

	CRect crect = { 0 };
	m_tab.GetClientRect(&crect);
	crect.DeflateRect(8, 35, 10, 10);
	for (int i = 0; i < 3; i++)
	{
		dlg[i]->MoveWindow(crect);
	}

	dlg[0]->ShowWindow(SW_SHOWNORMAL);
	imagelist.Create(24,24, ILC_COLOR32,3,0);
	imagelist.Add(LoadIconW(NULL, IDI_APPLICATION));
	imagelist.Add(LoadIconW(NULL, IDI_ERROR));
	imagelist.Add(LoadIconW(NULL, IDI_ASTERISK));

	m_list.SetImageList(&imagelist,LVSIL_SMALL);

	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);
	m_list.InsertColumn(0,L"程序名称", LVCFMT_LEFT,100,-1);
	m_list.InsertColumn(1, L"进程ID", LVCFMT_LEFT, 100, -1);
	m_list.InsertColumn(2, L"描述信息", LVCFMT_LEFT, 100, -1);

	m_list.InsertItem(0, L"QQ.exe",0);
	m_list.SetItemText(0, 1, L"0x12121");
	m_list.SetItemText(0, 2, L"这个是聊天软件");

	m_list.InsertItem(1, L"微信.exe",1);
	m_list.SetItemText(1, 1, L"0x12221");
	m_list.SetItemText(1 ,2, L"这个是聊天软件");

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCDlg::OnBnClickedButton1()
{
    CString str;
    UpdateData(TRUE);
    GetDlgItemTextW(IDC_RADIO1+nameradio, str);
    MessageBoxW(str);
	// TODO: 在此添加控件通知处理程序代码
}

void CMFCDlg::OnBnClickedButton2()
{
    CString result, temp;
    UpdateData(TRUE);
	for(int CID= IDC_CHECK1; CID<=IDC_CHECK4; CID++)
	{
		if(((CButton*)GetDlgItem(CID))->GetCheck())
		{
			GetDlgItemTextW(CID, temp);
			result += temp + L" ";
		}
    }	
    MessageBoxW(result);
	// TODO: 在此添加控件通知处理程序代码
}

void CMFCDlg::OnBnClickedCheckall()
{
	UpdateData(TRUE);
	namecheck1 = chaeckall;
	namecheck2 = chaeckall;
	namecheck3 = chaeckall;
	namecheck4 = chaeckall;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}

void CMFCDlg::OnCommandRange(UINT id)
{
    //MessageBoxW(L"选项发生改变");
	UpdateData(TRUE);
    int count = 0;
	count += namecheck1;
	count += namecheck2;
	count += namecheck3;
	count += namecheck4;
	if (count == 4)
	{
		chaeckall = 1;
	}
	else
	{
		chaeckall = 0;
	}
	UpdateData(FALSE);
}


void CMFCDlg::OnBnClickedlogin()
{
	// TODO: 在此添加控件通知处理程序代码
	CString username, password;
	m_username.GetWindowText(username);
	m_password.GetWindowText(password);

	if (username.IsEmpty())
	{
		MessageBoxW(L"用户名不能为空");
	}
	else if(password.IsEmpty())
	{
		MessageBoxW(L"密码不能为空");
	}	
}



void CMFCDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UpdateData();

	m_progers.SetPos(m_slider.GetPos());
	UpdateData(FALSE);
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CMFCDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//m_progers.StepIt();
	CDialog::OnTimer(nIDEvent);
}

void CMFCDlg::OnBnClickedButton4()
{
	CString str;
    m_combo1.GetWindowTextW(str);
    MessageBoxW(str);
	// TODO: 在此添加控件通知处理程序代码
}

void CMFCDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int idex = m_tab.GetCurSel();
	for (int i = 0; i < 3; i++)
	{
		if (idex == i)
		{
			dlg[i]->ShowWindow(SW_SHOWNORMAL);

		}
		else
		{
			dlg[i]->ShowWindow(SW_HIDE);

		}
	}
}


void CMFCDlg::OnNMRClickList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	POINT point{ 0 };
	GetCursorPos(&point);
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	CMenu* pmenu = menu.GetSubMenu(0);
	pmenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
	*pResult = 0;
}

void CMFCDlg::Onclick()
{
	MessageBox(L"123");
	// TODO: 在此添加命令处理程序代码
}
