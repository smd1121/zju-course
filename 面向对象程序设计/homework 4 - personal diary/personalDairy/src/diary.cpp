#include"pch.h"

using namespace std;

class Diary {
	string date;
	vector<string> contents;
public:
	void init();
	void setDate(string &date);
	string getDate()const;
	void addLine(string &text);
	void printDiary(int tag);
};

/* clean the strings */
void Diary::init() {
	contents.empty();
}

void Diary::setDate(string &date) {
	this->date = date;
}

string Diary::getDate()const {
	return date;
}

/* add a line to the end */
void Diary::addLine(string &text) {
	contents.push_back(text);
}

/* print the whole diary */
void Diary::printDiary(int tag) {
	cout << date << endl;
	for (vector<string>::iterator i = contents.begin(); i != contents.end(); i++)
		cout << *i << endl;
	if(tag) cout << "." << endl; 
}
