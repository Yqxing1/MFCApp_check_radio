
// MFCApplication2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include "m_radio.h"
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
}

BEGIN_MESSAGE_MAP(CMFCDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCDlg 消息处理程序

BOOL CMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
