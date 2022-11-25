
// TreeTestDlg.cpp : 实现文件
//

#include "stdafx.h"

#define _HEHE

#include "TreeTest.h"
#include "TreeTestDlg.h"
#include "afxdialogex.h"
#include "resource.h"

//#include "BinaryTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTreeTestDlg 对话框




CTreeTestDlg::CTreeTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTreeTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTreeTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTreeTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDTEST, &CTreeTestDlg::OnBnClickedTest)
	ON_EN_CHANGE(IDC_EDIT_TREE, &CTreeTestDlg::OnEnChangeEditTree)
	ON_BN_CLICKED(IDOK, &CTreeTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDOK2, &CTreeTestDlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDTEST2, &CTreeTestDlg::OnBnClickedTest2)
	ON_EN_CHANGE(IDC_EDIT_LEVELTRAV, &CTreeTestDlg::OnEnChangeEditLeveltrav)
END_MESSAGE_MAP()


// CTreeTestDlg 消息处理程序

BOOL CTreeTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CString s0=L"abd##ef###c#gh##i##";
	GetDlgItem(IDC_EDIT_TREE)->SetWindowTextW(s0);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTreeTestDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTreeTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTreeTestDlg::OnBnClickedTest()
{
	//获取输入信息
	CString s0;
	GetDlgItem(IDC_EDIT_TREE)->GetWindowTextW(s0);
	TCHAR *p=(TCHAR*)s0.GetBuffer(0);

	//创建树
	t = new Binary_Tree<TCHAR>();
	t->creat_Binary_Tree(p, '#');

	//先序遍历
	CString s1=t->pretrav_Binary_Tree();
	GetDlgItem(IDC_EDIT_PRETRAV)->SetWindowTextW(s1);

	//中序遍历
	CString s2=t->intrav_Binary_Tree();
	GetDlgItem(IDC_EDIT_INTRAV)->SetWindowTextW(s2);

	//后序遍历
	CString s3=t->postrav_Binary_Tree();
	GetDlgItem(IDC_EDIT_POSTRAV)->SetWindowTextW(s3);

	//层序遍历
	CString s4= t->levelrav_Binary_Tree();
	GetDlgItem(LEVEL_ORDER)->SetWindowTextW(s4);

	//绘图DEMO
	DrawTree(false);
}

void DrawTreeNode(HDC &hdc, Btnode<TCHAR> *tree, bool isInverse, int width, int height,
	int radius, int totLev, int lev, int ind, int lastX0, int lastY0) {
	// 计算位置
	int x0 = 0, y0 = 0;
	if (totLev > 1)
		x0 = ((1 << (totLev - lev)) + (ind - 1) * (1 << (totLev - lev + 1)) - 1) * radius,
		y0 = (lev - 1) * (height - radius) / (totLev - 1);

	// 画点
	Ellipse(hdc, x0, y0, x0 + 2 * radius, y0 + 2 * radius);

	// 显示结点内容
	CString s = output(tree->d);
	TextOutW(hdc, x0 + radius / 2, y0, s.GetBuffer(0), s.GetLength());

	// 画父节点与该结点之间的线
	if (lastX0 + lastY0) {
		double dis = sqrt((x0 - lastX0) * (x0 - lastX0) + (y0 - lastY0) * (y0 - lastY0));
		double deltaX = radius / dis * (lastX0 - x0),
			   deltaY = radius / dis * (lastY0 - y0);
		MoveToEx(hdc, lastX0 + radius - deltaX, lastY0 + radius - deltaY, NULL);
		LineTo(hdc, x0 + radius + deltaX, y0 + radius + deltaY);
	}

	// 画子结点
	if (tree->lchild)
		DrawTreeNode(hdc, tree->lchild, isInverse, width, height, radius, totLev,
			lev + 1, !isInverse ? ind * 2 - 1 : ind * 2, x0, y0);
	if (tree->rchild)
		DrawTreeNode(hdc, tree->rchild, isInverse, width, height, radius, totLev,
			lev + 1, !isInverse ? ind * 2 : ind * 2 - 1, x0, y0);
}

//自定义，绘图DEMO，演示基本绘图方法
void CTreeTestDlg::DrawTree(bool isInverse)
{	
	//获取绘图控件的句柄，这里是在IDC_STATIC_PIC图像框中绘制
	HDC myhdc=::GetDC(GetDlgItem(IDC_STATIC_PIC)->GetSafeHwnd()); 

	//设置绘图用的画笔，这里设置的为实线、线宽为1、颜色为红色
	HPEN hpen1=CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN hpen_old=(HPEN)SelectObject(myhdc, hpen1);
	
	//设置绘图用的画刷，这里设置的为实填充、颜色为蓝色
	HBRUSH hbrush1=CreateSolidBrush(RGB(0, 255, 255));
	//HBRUSH hbrush1=(HBRUSH)GetStockObject(NULL_BRUSH);  //透明画刷
	HBRUSH hbrush_old=(HBRUSH)SelectObject(myhdc, hbrush1);

	//=============绘图在这里进行start======================================================
	
	CRect rectCtrl;
	GetDlgItem(IDC_STATIC_PIC)->GetWindowRect(&rectCtrl);

	// 通过画一个白色矩形实现清屏
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(myhdc, brush);
	Rectangle(myhdc, 0, 0, rectCtrl.Width(), rectCtrl.Height());
	SelectObject(myhdc, hbrush1);

	int radius = min((rectCtrl.Width()) / ((1 << t->getLevel())), 
					rectCtrl.Height() / t->getLevel() / 2);

	//设置绘制文字用的字体
	CFont font1;
	font1.CreateFontW(radius * 2,            //字体大小
		0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
		_T("Arial"));  //字体名称
	CFont *font_old = (CFont*)SelectObject(myhdc, font1);
	SetBkMode(myhdc, TRANSPARENT);       //设置文字背景透明

	DrawTreeNode(myhdc, t->getRoot(), isInverse, rectCtrl.Width() - radius,
		rectCtrl.Height() - radius, radius, t->getLevel(), 1, 1, 0, 0);
	
	//=============绘图在这里进行end========================================================

	//恢复控件原始设置
	SelectObject(myhdc, hpen_old);
	SelectObject(myhdc, hbrush_old);
	SelectObject(myhdc, font_old);
}

void CTreeTestDlg::OnEnChangeEditTree()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTreeTestDlg::OnBnClickedOk()
{
	DrawTree(true);
}

// Exit
void CTreeTestDlg::OnBnClickedOk2()
{
	CDialogEx::OnOK();
}

Btnode<TCHAR> *findNode(Btnode<TCHAR> *tree, TCHAR ch) {
	if (!tree || tree->d == ch)
		return tree;
	if (tree->lchild) tree->lchild->father = tree;
	if (tree->rchild) tree->rchild->father = tree;
	Btnode<TCHAR> *result = nullptr;
	result = findNode(tree->lchild, ch);
	if (!result)
		result = findNode(tree->rchild, ch);
	return result;
}

CString findRoute(Btnode<TCHAR> *tree, TCHAR from, TCHAR to) {
	Btnode<TCHAR> *f = findNode(tree, from), *t = findNode(tree, to);

	if (!f || !t)
		return L"Point given not found.";

	CString s = L"";

	vector<TCHAR> fromToRoot, toToRoot;
	Btnode<TCHAR> *temp = f;
	while (temp) {
		fromToRoot.push_back(temp->d);
		temp = temp->father;
	}
	temp = t;
	while (temp) {
		toToRoot.push_back(temp->d);
		temp = temp->father;
	}

	int i = 1, fLen = fromToRoot.size(), tLen = toToRoot.size();
	for (; i < min(fLen, tLen); i++) {
		if (fromToRoot[fLen - i] != toToRoot[tLen - i])
			break;
	}
	if (i == min(fLen, tLen)) {
		if (fLen >= tLen) {
			for (int j = 0; ; j++) {
				s += fromToRoot[j];
				if (fromToRoot[j] == to)
					break;
			}
		}
		else {
			bool hasArrived = false;
			for (int j = tLen - 1; j >= 0; j--) {
				if (toToRoot[j] == from)
					hasArrived = true;
				if (hasArrived)
					s += toToRoot[j];
			}
		}
		return s;
	}
	for (int j = 0; j <= fLen - i; j++)
		s += fromToRoot[j];
	s += fromToRoot[fLen - i + 1];
	for (int j = tLen - i; j >= 0; j--)
		s += toToRoot[j];

	return s;
}

// 寻路
void CTreeTestDlg::OnBnClickedTest2()
{
	OnBnClickedTest();

	CString s0;
	GetDlgItem(ROUTE_FROM)->GetWindowTextW(s0);
	TCHAR *p = (TCHAR*)s0.GetBuffer(0);
	CString s1;
	GetDlgItem(ROUTE_TO)->GetWindowTextW(s1);
	TCHAR *q = (TCHAR*)s1.GetBuffer(0);

	CString s2 = findRoute(t->getRoot(), p[0], q[0]);
	GetDlgItem(ROUTE_ANS)->SetWindowTextW(s2);
}


void CTreeTestDlg::OnEnChangeEditLeveltrav()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
