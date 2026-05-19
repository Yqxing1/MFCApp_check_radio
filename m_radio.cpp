// m_radio.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication2.h"
#include "afxdialogex.h"
#include "m_radio.h"


// m_radio 对话框

IMPLEMENT_DYNAMIC(m_radio, CDialog)

m_radio::m_radio(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MFCAPPLICATION2_DIALOG, pParent)
{

}

m_radio::~m_radio()
{
}

void m_radio::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(m_radio, CDialog)
END_MESSAGE_MAP()


// m_radio 消息处理程序
