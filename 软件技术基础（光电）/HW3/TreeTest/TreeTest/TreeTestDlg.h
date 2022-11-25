
// TreeTestDlg.h : 头文件
//

#pragma once
#include "BinaryTree.h"


// CTreeTestDlg 对话框
class CTreeTestDlg : public CDialogEx
{
// 构造
public:
	CTreeTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TREETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTest();

private:
	void DrawTree(bool isInverse);
	Binary_Tree<TCHAR> *t;
public:
	afx_msg void OnEnChangeEditTree();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedOk2();
	afx_msg void OnBnClickedTest2();
	afx_msg void OnEnChangeEditLeveltrav();
};
