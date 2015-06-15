#pragma once

#include "acui.h"
#include "resource.h"
#include "DockBarChildDlg.h"

class RcuDesignDlg : public DockBarChildDlg
{
	DECLARE_DYNAMIC(RcuDesignDlg)

public:
	RcuDesignDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~RcuDesignDlg();

// 对话框数据
	enum { IDD = IDD_RCU_DESIGN_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	//输出按钮消息
	afx_msg void OnBnClickedExport();
	//listctrl双击消息
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	//listctrl右键消息(可以弹出菜单，但无法响应菜单消息)
	//因为cad的主窗口总是试图抢夺非模态对话框的焦点(WM_ACAD_KEEPFOCUS)
	//在消息映射暂时屏蔽右键消息
	afx_msg void OnNMRclickList1(NMHDR *pNMHDR, LRESULT *pResult);
	//目前这些菜单项无妨响应非模态对话框的消息
	//仍保留作为以后学习用
	afx_msg void OnHilightCommand();
	afx_msg void OnModifyCommand();
	afx_msg void OnDeleteCommand();
	afx_msg void OnAddCommand();

	virtual BOOL OnInitDialog();
	virtual void OnClosing();
};
