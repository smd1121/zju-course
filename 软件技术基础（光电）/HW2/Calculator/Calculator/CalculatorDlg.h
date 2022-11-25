﻿
// CalculatorDlg.h: 头文件
//

#pragma once
#include "myCalculator.h"

// CCalculatorDlg 对话框
class CCalculatorDlg : public CDialogEx
{
// 构造
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void startCalc();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCalc();
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnEnChangeEditInput();
	CString &getInput();
	void setOutput(CString &output);
	BOOL PreTranslateMessage(MSG * pMsg);
private:
	MyCalculator myCalculator;
	CString calcInput;
	CString calcOutput;
};
