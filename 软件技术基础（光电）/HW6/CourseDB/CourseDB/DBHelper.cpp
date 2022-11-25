#include "DBHelper.h"

DBHelper::DBHelper(string &dbFileName) {
	CoInitialize(NULL);
	_ConnectionPtr temp(__uuidof(Connection));
	pConn = temp;
	try
	{
		string connStr = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=";
		connStr += dbFileName;
		pConn->Open(_bstr_t(connStr.c_str()), "", "", adModeUnknown);
	}
	catch (_com_error& e)
	{
		cerr << "[Error] Open failed: " << e.Description() << endl << endl;
	}
}

void DBHelper::printTable(_RecordsetPtr& pRec,	vector<string>& items) {
	try
	{
		if (!pRec->BOF) {
			pRec->MoveFirst();
		}

		cout << "|";
		int countWidth = 1;
		for (auto &item : items) {
			cout << item;
			for (int i = item.length(); i < 15; i++)
				cout << " ";
			cout << "|";

			countWidth += 1 + max(item.length(), 15);
		}
		cout << endl;
		cout.width(countWidth + 1);
		cout.fill('-');
		cout << ' ' << endl;
		cout.fill(' ');

		int cnt = 0;
		while (!pRec->adoEOF) {
			cnt++;
			_variant_t var;
			cout << "|";
			for (auto &item : items) {
				var = pRec->GetCollect(item.c_str());
				cout.width(max(item.length(), 15));
				if (var.vt != VT_NULL) {
					cout << var2str(var) << "|";
				}
				else {
					cout << "null" << "|";
				}
			}
			cout << "\n";
			pRec->MoveNext();
		}
		cout << "\n" << "查询到 " << cnt << " 条记录。\n";
		cout << endl;
	}
	catch (_com_error& e)
	{
		cerr << "[Error] " << e.Description() << endl << endl;
	}
}

void DBHelper::runSQL(string& cmd) {
	try
	{
		_CommandPtr pCmd;
		pCmd.CreateInstance(_uuidof(Command));
		pCmd->ActiveConnection = pConn;   //m_pConnection连接数据库文件
		pCmd->CommandText = _bstr_t(cmd.c_str());  //m_strCmd为sql命令
		pCmd->Execute(NULL, NULL, adCmdText);
	}
	catch (_com_error& e)
	{
		cerr << "[Error] " << e.Description() << endl << endl;
	}
}

void DBHelper::runSQL(string& cmd, vector<string>& items) {
	try
	{
		_CommandPtr pCmd;
		pCmd.CreateInstance(_uuidof(Command));
		pCmd->ActiveConnection = pConn;   //m_pConnection连接数据库文件
		pCmd->CommandText = _bstr_t(cmd.c_str());  //m_strCmd为sql命令
		//执行SQL命令，将执行结果保存在智能指针
		_RecordsetPtr pRec = pCmd->Execute(NULL, NULL, adCmdText);
		printTable(pRec, items);
	}
	catch (_com_error& e)
	{
		cerr << "[Error] " << e.Description() << endl << endl;
	}
}

int DBHelper::getTblMaxID(const string& const tblName) {
	stringstream cmd;
	cmd.str("");
	cmd << "select max(ID) as m from " << tblName;
	try
	{
		_CommandPtr pCmd;
		pCmd.CreateInstance(_uuidof(Command));
		pCmd->ActiveConnection = pConn;   //m_pConnection连接数据库文件
		pCmd->CommandText = _bstr_t(cmd.str().c_str());  //m_strCmd为sql命令
		//执行SQL命令，将执行结果保存在智能指针
		_RecordsetPtr pRec = pCmd->Execute(NULL, NULL, adCmdText);
		
		string item = "m";
		_variant_t var = pRec->GetCollect(item.c_str());
		return var2int(var);
	}
	catch (_com_error& e)
	{
		cerr << "[Error] " << e.Description() << endl << endl;
	}
	return -1;
}

int DBHelper::var2int(_variant_t& var) {
	return _ttoi((LPCTSTR)(_bstr_t)var);
}

string DBHelper::var2str(_variant_t& var) {
	string str = (const char*)_bstr_t(var);
	return str;
}