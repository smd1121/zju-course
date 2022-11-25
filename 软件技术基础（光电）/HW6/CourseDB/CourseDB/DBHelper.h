#pragma once
#include "pch.h"
class DBHelper
{
private:
	// 数据库连接
	_ConnectionPtr pConn;
	// _varint_t 类型转化为 int 和 string
	int var2int(_variant_t&);
	string var2str(_variant_t&);
	// 根据 items 中的条目，打印 _RecordsetPtr 指向的表
	void printTable(_RecordsetPtr& pRec, vector<string>& items);
	
public:
	// 构造函数：尝试建立连接
	DBHelper(string& dbFileName);
	// 运行 SQL 语句
	void runSQL(string& cmd);
	// 运行 SQL 语句，并打印返回的表格；条目存储在 items 中
	void runSQL(string& cmd, vector<string>& items);
	// 返回一个表中的 max(ID)
	int getTblMaxID(const string& const tblName);
};

