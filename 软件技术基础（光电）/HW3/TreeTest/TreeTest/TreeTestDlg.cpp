
// TreeTestDlg.cpp : ʵ���ļ�
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


// CTreeTestDlg �Ի���




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


// CTreeTestDlg ��Ϣ�������

BOOL CTreeTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CString s0=L"abd##ef###c#gh##i##";
	GetDlgItem(IDC_EDIT_TREE)->SetWindowTextW(s0);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTreeTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTreeTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTreeTestDlg::OnBnClickedTest()
{
	//��ȡ������Ϣ
	CString s0;
	GetDlgItem(IDC_EDIT_TREE)->GetWindowTextW(s0);
	TCHAR *p=(TCHAR*)s0.GetBuffer(0);

	//������
	t = new Binary_Tree<TCHAR>();
	t->creat_Binary_Tree(p, '#');

	//�������
	CString s1=t->pretrav_Binary_Tree();
	GetDlgItem(IDC_EDIT_PRETRAV)->SetWindowTextW(s1);

	//�������
	CString s2=t->intrav_Binary_Tree();
	GetDlgItem(IDC_EDIT_INTRAV)->SetWindowTextW(s2);

	//�������
	CString s3=t->postrav_Binary_Tree();
	GetDlgItem(IDC_EDIT_POSTRAV)->SetWindowTextW(s3);

	//�������
	CString s4= t->levelrav_Binary_Tree();
	GetDlgItem(LEVEL_ORDER)->SetWindowTextW(s4);

	//��ͼDEMO
	DrawTree(false);
}

void DrawTreeNode(HDC &hdc, Btnode<TCHAR> *tree, bool isInverse, int width, int height,
	int radius, int totLev, int lev, int ind, int lastX0, int lastY0) {
	// ����λ��
	int x0 = 0, y0 = 0;
	if (totLev > 1)
		x0 = ((1 << (totLev - lev)) + (ind - 1) * (1 << (totLev - lev + 1)) - 1) * radius,
		y0 = (lev - 1) * (height - radius) / (totLev - 1);

	// ����
	Ellipse(hdc, x0, y0, x0 + 2 * radius, y0 + 2 * radius);

	// ��ʾ�������
	CString s = output(tree->d);
	TextOutW(hdc, x0 + radius / 2, y0, s.GetBuffer(0), s.GetLength());

	// �����ڵ���ý��֮�����
	if (lastX0 + lastY0) {
		double dis = sqrt((x0 - lastX0) * (x0 - lastX0) + (y0 - lastY0) * (y0 - lastY0));
		double deltaX = radius / dis * (lastX0 - x0),
			   deltaY = radius / dis * (lastY0 - y0);
		MoveToEx(hdc, lastX0 + radius - deltaX, lastY0 + radius - deltaY, NULL);
		LineTo(hdc, x0 + radius + deltaX, y0 + radius + deltaY);
	}

	// ���ӽ��
	if (tree->lchild)
		DrawTreeNode(hdc, tree->lchild, isInverse, width, height, radius, totLev,
			lev + 1, !isInverse ? ind * 2 - 1 : ind * 2, x0, y0);
	if (tree->rchild)
		DrawTreeNode(hdc, tree->rchild, isInverse, width, height, radius, totLev,
			lev + 1, !isInverse ? ind * 2 : ind * 2 - 1, x0, y0);
}

//�Զ��壬��ͼDEMO����ʾ������ͼ����
void CTreeTestDlg::DrawTree(bool isInverse)
{	
	//��ȡ��ͼ�ؼ��ľ������������IDC_STATIC_PICͼ����л���
	HDC myhdc=::GetDC(GetDlgItem(IDC_STATIC_PIC)->GetSafeHwnd()); 

	//���û�ͼ�õĻ��ʣ��������õ�Ϊʵ�ߡ��߿�Ϊ1����ɫΪ��ɫ
	HPEN hpen1=CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN hpen_old=(HPEN)SelectObject(myhdc, hpen1);
	
	//���û�ͼ�õĻ�ˢ���������õ�Ϊʵ��䡢��ɫΪ��ɫ
	HBRUSH hbrush1=CreateSolidBrush(RGB(0, 255, 255));
	//HBRUSH hbrush1=(HBRUSH)GetStockObject(NULL_BRUSH);  //͸����ˢ
	HBRUSH hbrush_old=(HBRUSH)SelectObject(myhdc, hbrush1);

	//=============��ͼ���������start======================================================
	
	CRect rectCtrl;
	GetDlgItem(IDC_STATIC_PIC)->GetWindowRect(&rectCtrl);

	// ͨ����һ����ɫ����ʵ������
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(myhdc, brush);
	Rectangle(myhdc, 0, 0, rectCtrl.Width(), rectCtrl.Height());
	SelectObject(myhdc, hbrush1);

	int radius = min((rectCtrl.Width()) / ((1 << t->getLevel())), 
					rectCtrl.Height() / t->getLevel() / 2);

	//���û��������õ�����
	CFont font1;
	font1.CreateFontW(radius * 2,            //�����С
		0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
		_T("Arial"));  //��������
	CFont *font_old = (CFont*)SelectObject(myhdc, font1);
	SetBkMode(myhdc, TRANSPARENT);       //�������ֱ���͸��

	DrawTreeNode(myhdc, t->getRoot(), isInverse, rectCtrl.Width() - radius,
		rectCtrl.Height() - radius, radius, t->getLevel(), 1, 1, 0, 0);
	
	//=============��ͼ���������end========================================================

	//�ָ��ؼ�ԭʼ����
	SelectObject(myhdc, hpen_old);
	SelectObject(myhdc, hbrush_old);
	SelectObject(myhdc, font_old);
}

void CTreeTestDlg::OnEnChangeEditTree()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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

// Ѱ·
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
