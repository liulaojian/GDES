#pragma once

#include "AcUiBaseDlg.h"

// 将非模态对话框的3个消息放在了基类DockBarChildDlg
// 这样派生类就可以只专注对话框本身的消息处理
// 同时减少重复代码
class DockBarChildDlg : public AcUiBaseDlg 
{
	DECLARE_DYNAMIC (DockBarChildDlg)

public:
	virtual ~DockBarChildDlg();

protected:
	DECLARE_MESSAGE_MAP()

protected:
	DockBarChildDlg(UINT idd, CWnd *pParent =NULL, HINSTANCE hInstance = NULL) ;

public:
	//显示/隐藏父窗口(dockbar)
	void ShowParentControlBar(BOOL bShow) const;
	virtual void OnClosing(); // 默认实现为空(如果需要处理关闭，重载该函数)
	virtual BOOL OnCommand (WPARAM wParam, LPARAM lParam) ;
	afx_msg void OnSize (UINT nType, int cx, int cy) ;
	afx_msg LRESULT OnAcadKeepFocus (WPARAM wParam, LPARAM lParam) ;
	virtual BOOL OnInitDialog();
} ;

//切换controlbar显示
class ControlBarShowSwitch
{
public:
	//构造函数隐藏controlbar
	ControlBarShowSwitch(DockBarChildDlg* _dlg) : dlg(_dlg)
	{
		dlg->ShowParentControlBar(FALSE);
	}
	//析构函数显示controlbar
	~ControlBarShowSwitch()
	{
		dlg->ShowParentControlBar(TRUE);
	}
	DockBarChildDlg* dlg;
};
