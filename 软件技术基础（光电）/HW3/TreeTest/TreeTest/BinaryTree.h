#pragma once
#include "stdafx.h"
#include <queue>

using namespace std;

#ifdef _HEHE

//该宏定义用于判断T类型
template<class T>
struct TypeParseTraits;
#define REGISTER_PARSE_TYPE(X) template <> struct TypeParseTraits<X> \
    { static const char* name; } ; const char* TypeParseTraits<X>::name = #X
REGISTER_PARSE_TYPE(int);
REGISTER_PARSE_TYPE(float);
REGISTER_PARSE_TYPE(double);
REGISTER_PARSE_TYPE(char);
REGISTER_PARSE_TYPE(TCHAR);

#endif

//二叉树结点
template <class T>
struct Btnode
{
	T d;
	Btnode *lchild;
	Btnode *rchild;
	Btnode *father;
};

//二叉树类
template <class T>
class Binary_Tree
{
private:
	Btnode<T> *BT;    //根
	CString Sequence; //遍历序列
	int level;
public:
	Binary_Tree()     //构造函数，初始化
	{
		BT=NULL;
		return;
	}
	int getLevel() { return level; }
	void creat_Binary_Tree(T*, T);   //生成树
	CString pretrav_Binary_Tree();   //先序遍历
	CString intrav_Binary_Tree();    //中序遍历
	CString postrav_Binary_Tree();   //后序遍历
	CString levelrav_Binary_Tree();	 //层序遍历
	Btnode<T> *getRoot() { return BT; }
};

//输出结点内容
template <class T>
static CString output(T a)
{
	CString s;
	char* name= (char*)TypeParseTraits<T>::name;
	if(strcmp(name, "int")==0)
	{
		s.Format(L"%d", a);
	}
	else if(strcmp(name, "double")==0 ||strcmp(name, "float")==0)
	{
		s.Format(L"%f", a);
	}
	else if(strcmp(name, "char")==0 || strcmp(name, "TCHAR")==0) 
	{
		s.Format(L"%c", a);
	}
	return s;
}

//生成树
template <class T>
void Binary_Tree<T>::creat_Binary_Tree(T* nodes, T end)
{
	if(nodes==NULL) return;
	
	Btnode<T> *p;
	T* tmpnodes=nodes;
	T x=tmpnodes[0];
	if(x==end) return;

	p=new Btnode<T>;
	p->d=x;
	p->lchild = NULL;
	p->rchild = NULL;
	p->father = NULL;
	BT=p;

	creat(p, tmpnodes, 1, end);
	creat(p, tmpnodes, 2, end);
}
template <class T>
static void creat(Btnode<T>*p, T*& nodes, int k, T end)
{
	nodes++;
	Btnode<T> *q;
	T x=nodes[0];
	if(x!=end)
	{
		q=new Btnode<T>;
		q->d=x;
		q->lchild = NULL;
		q->rchild = NULL;
		q->father = p;
		if(k==1) p->lchild=q;
		if(k==2) p->rchild=q;
		creat(q, nodes, 1, end);
		creat(q, nodes, 2, end);
	}
}

//先序遍历
template <class T>
CString Binary_Tree<T>::pretrav_Binary_Tree()
{
	Btnode<T>*p;
	p=BT;
	Sequence="";
	pretrav(p, Sequence);
	return Sequence;
}
template <class T>
static void pretrav(Btnode<T> *p, CString & s0)
{
	if(p!=NULL)
	{
		s0 +=output(p->d);
		pretrav(p->lchild, s0);
		pretrav(p->rchild, s0);
	}
}

//中序遍历
template <class T>
CString Binary_Tree<T>::intrav_Binary_Tree()
{
	Btnode<T>*p;
	p=BT;
	Sequence="";
	intrav(p, Sequence);
	return Sequence;
}
template <class T>
static void intrav(Btnode<T> *p, CString & s0)
{
	if(p!=NULL)
	{
		intrav(p->lchild, s0);
		s0 +=output(p->d);
		intrav(p->rchild, s0);
	}
}

//后序遍历
template <class T>
CString Binary_Tree<T>::postrav_Binary_Tree()
{
	Btnode<T>*p;
	p=BT;
	Sequence="";
	postrav(p, Sequence);
	return Sequence;
}
template <class T>
static void postrav(Btnode<T> *p, CString & s0)
{
	if(p!=NULL)
	{
		postrav(p->lchild, s0);
		postrav(p->rchild, s0);
		s0 +=output(p->d);
	}
}

//层序遍历
template <class T>
CString Binary_Tree<T>::levelrav_Binary_Tree()
{
	Btnode<T>*p;
	p = BT;
	Sequence = "";
	level = levelrav(p, Sequence);
	return Sequence;
}
template <class T>
static int levelrav(Btnode<T> *p, CString & s0)
{
	int maxLevel = 0;
	if (p != NULL)
	{
		queue<Btnode<T> *> q;
		queue<int> levelCounter;
		q.push(p); levelCounter.push(1);
		while (!q.empty()) {
			Btnode<T> *cnt = q.front();
			s0 += output(cnt->d);
			q.pop();
			if (cnt->lchild) {
				q.push(cnt->lchild);
				levelCounter.push(levelCounter.front() + 1);
			}
			if (cnt->rchild) {
				q.push(cnt->rchild);
				levelCounter.push(levelCounter.front() + 1);
			}
			maxLevel = max(maxLevel, levelCounter.front());
			levelCounter.pop();
		}
	}
	return maxLevel;
}