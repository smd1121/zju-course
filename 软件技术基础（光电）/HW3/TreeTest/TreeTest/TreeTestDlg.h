
// TreeTestDlg.h : ͷ�ļ�
//

#pragma once
#include "BinaryTree.h"


// CTreeTestDlg �Ի���
class CTreeTestDlg : public CDialogEx
{
// ����
public:
	CTreeTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TREETEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
