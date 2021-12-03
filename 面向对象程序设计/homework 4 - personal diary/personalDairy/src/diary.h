#pragma once
#include"pch.h"

using namespace std;

class Diary {
	string date;
	vector<string> contents;
public:
	void init();					//clean the contents 
	void setDate(string &date);		//setter
	string getDate()const;			//getter
	void addLine(string &text);		//add a line to the end
	void printDiary(int tag);		//print the whole Diary (date + contents)
};
