#pragma once
#include "pch.h"
class DBHelper
{
private:
	// ���ݿ�����
	_ConnectionPtr pConn;
	// _varint_t ����ת��Ϊ int �� string
	int var2int(_variant_t&);
	string var2str(_variant_t&);
	// ���� items �е���Ŀ����ӡ _RecordsetPtr ָ��ı�
	void printTable(_RecordsetPtr& pRec, vector<string>& items);
	
public:
	// ���캯�������Խ�������
	DBHelper(string& dbFileName);
	// ���� SQL ���
	void runSQL(string& cmd);
	// ���� SQL ��䣬����ӡ���صı����Ŀ�洢�� items ��
	void runSQL(string& cmd, vector<string>& items);
	// ����һ�����е� max(ID)
	int getTblMaxID(const string& const tblName);
};

