#pragma once
#include "afxdialogex.h"


// m_radio 对话框

class m_radio : public CDialog
{
	DECLARE_DYNAMIC(m_radio)

public:
	m_radio(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~m_radio();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
