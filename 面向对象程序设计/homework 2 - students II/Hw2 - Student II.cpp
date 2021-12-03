#include "pch.h"

using namespace std;

const int MAX_SCORE = 5;

class Course {
private:
	static int crsNum;
	static Course *head, *tail;
	
	Course *next = nullptr;
	string crsName;
	int minScore = 0, maxScore = 0, selectedNum = 0, index;
	float totScore = 0;
	
	//constructor
	Course(string &crsName, int index) : crsName(crsName), index(index) {}

	//extend the linked list
	static void inflate(string &str);

public:
	//create the first node in the list
	static void createList(string &str);

	//add a score to the list
	void newCrsScore(int score);

	 /*search the index of the current course in the course table
	   if no one matches, create a new one*/
	static Course *search(string &str);

	//getters
	 int getIndex() { return index; }
	 int getMinScore() { return minScore; }
	 int getMaxScore() { return maxScore; }
	 float getAvgScore() { return totScore / selectedNum; }
	 static int getCrsNum() { return crsNum; }
	 string &getCrsName() { return crsName; }
	 Course *getNext() { return next; }
	 static Course *getHead() { return head; }
};
int Course::crsNum = 0;
Course *Course::head = nullptr;
Course *Course::tail = nullptr;

class StuCrsScore {
private:
	int score, index = 1;
	bool selected = 0;
	StuCrsScore *next = nullptr;

	//extend the linked list
	void inflate(StuCrsScore *currentIndex);

public:
	/*search the index of the current course in the course table
	   if no one matches, create a new one*/
	StuCrsScore *search(StuCrsScore *currentIndex, int index);

	//getters & setters
	void setScore(int score);
	int getScore();
	StuCrsScore *getNext() { return next; }
};


class Student {
private:
	static int stuNum;
	static Student *head, *tail;

	Student *next = nullptr;
	string name;
	float totScore = 0;
	int selectNum = 0;
	StuCrsScore *scoreHead = new StuCrsScore();

	//constructor
	Student(string &name) : name(name) {}
	
public:
	//extend the linked list
	static void inflate(string &str);

	//create the first node in the list
	static void createList(string &str);

	//add a course to the list
	void newCourse(string &crsName, int score);

	//trans the whole line to effective data
	static void operateData(string &data);

	//getters
	int getSelectNum() { return selectNum; }
	float getAvgScore() { return totScore / selectNum; }
	string &getName() { return name; }
	static Student *getHead() { return head; }
	Student *getNext() { return next; }
	StuCrsScore *getScoreHead() { return scoreHead; }
};
int Student::stuNum = 0;
Student *Student::head = nullptr;
Student *Student::tail = nullptr;

void readData();
void printData();
void printToFile();

int main() {
	readData();
	printData();
	printToFile();
	system("pause");
	return 0;
}

void readData() {
	ifstream file1;
	file1.open("studentData.txt", ios::in);
	bool tag = 0;
	for (; !file1.eof();) {
		string name;
		file1 >> name;

		if (name.empty()) continue;
		// ignore the blank lines in the text

		Student::inflate(name);

		string temp;
		getline(file1, temp);
		Student::operateData(temp);
	}

	file1.close();
}

void printData() {
	cout << setiosflags(ios::left);

	cout << "no        name      ";

	for (Course *currentCrs = Course::getHead(); currentCrs != nullptr; currentCrs = currentCrs->getNext()) {
		cout.width(10);
		cout << currentCrs->getCrsName();
	}
	cout << "average" << endl;

	int i = 1;
	for (Student *currentStu = Student::getHead(); currentStu != nullptr; currentStu = currentStu->getNext()) {
		cout.width(10);
		cout << i++;

		cout.width(10);
		cout << currentStu->getName();

		StuCrsScore *currentScore = currentStu->getScoreHead();
		for (int j = 0; j < Course::getCrsNum(); j++) {
			cout.width(10);
			if (currentScore != nullptr) {
				if(currentScore->getScore() != -1)		cout << currentScore->getScore();	
				else															cout << "-";
				currentScore = currentScore->getNext();
			}
			else
				cout << "-";
		}

		if (currentStu->getSelectNum()) {
			cout.precision(6);
			cout << currentStu->getAvgScore() << endl;
		}
		else cout << "-" << endl;
	}


	cout << "          average   ";
	for (Course *currentCrs = Course::getHead(); currentCrs != nullptr; currentCrs = currentCrs->getNext()) {
		cout.width(10);
		cout.precision(2);
		cout << currentCrs->getAvgScore();
	}

	cout << endl << "          min       ";
	for (Course *currentCrs = Course::getHead(); currentCrs != nullptr; currentCrs = currentCrs->getNext()) {
		cout.width(10);
		cout << currentCrs->getMinScore();
	}

	cout << endl << "          max       ";
	for (Course *currentCrs = Course::getHead(); currentCrs != nullptr; currentCrs = currentCrs->getNext()) {
		cout.width(10);
		cout << currentCrs->getMaxScore();
	}
}

void printToFile() {
	ofstream file2;
	file2.open("studentList.txt", ios::out | ios::trunc);

	file2 << setiosflags(ios::left);

	file2 << "no        name      ";

	for (Course *currentCrs = Course::getHead(); currentCrs != nullptr; currentCrs = currentCrs->getNext()) {
		file2.width(10);
		file2 << currentCrs->getCrsName();
	}
	file2 << "average" << endl;

	int i = 1;
	for (Student *currentStu = Student::getHead(); currentStu != nullptr; currentStu = currentStu->getNext()) {
		file2.width(10);
		file2 << i++;

		file2.width(10);
		file2 << currentStu->getName();

		StuCrsScore *currentScore = currentStu->getScoreHead();
		for (int j = 0; j < Course::getCrsNum(); j++) {
			file2.width(10);
			if (currentScore != nullptr) {
				if (currentScore->getScore() != -1)		file2 << currentScore->getScore();
				else															file2 << "-";
				currentScore = currentScore->getNext();
			}
			else
				file2 << "-";
		}

		if (currentStu->getSelectNum()) {
			file2.precision(6);
			file2 << currentStu->getAvgScore() << endl;
		}
		else file2 << "-" << endl;
	}


	file2 << "          average   ";
	for (Course *currentCrs = Course::getHead(); currentCrs != nullptr; currentCrs = currentCrs->getNext()) {
		file2.width(10);
		file2.precision(2);
		file2 << currentCrs->getAvgScore();
	}

	file2 << endl << "          min       ";
	for (Course *currentCrs = Course::getHead(); currentCrs != nullptr; currentCrs = currentCrs->getNext()) {
		file2.width(10);
		file2 << currentCrs->getMinScore();
	}

	file2 << endl << "          max       ";
	for (Course *currentCrs = Course::getHead(); currentCrs != nullptr; currentCrs = currentCrs->getNext()) {
		file2.width(10);
		file2 << currentCrs->getMaxScore();
	}

	file2.close();
}

void Course::inflate(string &str) {
	Course *course = new Course(str, ++crsNum);
	course->minScore = MAX_SCORE;
	if (tail != nullptr) tail->next = course;
	tail = course;
}

void Course::createList(string &str) {
	Course *course = new Course(str, 1);
	course->minScore = MAX_SCORE;
	tail = head = course;
	crsNum = 1;
}

void Course::newCrsScore(int score) {
	totScore += score;
	selectedNum++;
	if (score >= maxScore) maxScore = score;
	if (score <= minScore) minScore = score;
}

//search the index of the current course in the course table
Course *Course::search(string &str) {
	if (head == nullptr)	createList(str);
	Course *current = head;
	do {
		if (current->crsName == str) return current;
		current = current->next;
	} while (current != nullptr);
	// if no one matches, create a new one
	inflate(str);
	return current = tail;
}

void StuCrsScore::inflate(StuCrsScore *currentIndex) {
	StuCrsScore *stuCrsScore = new StuCrsScore;
	stuCrsScore->index = index + 1;
	currentIndex->next = stuCrsScore;
}

StuCrsScore *StuCrsScore::search(StuCrsScore *currentIndex, int index) {
	for (int i = 1; i < index; i++) {
		if (currentIndex->next == nullptr)		inflate(currentIndex);
		currentIndex = currentIndex->next;
	}
	return currentIndex;
}

void StuCrsScore::setScore(int scr) {
	score = scr;
	selected = 1;
}

int StuCrsScore::getScore() {
	if (selected)		return score;
	else						return -1;
}

void Student::inflate(string &str) {
	if (head == nullptr) {
		createList(str);
		return;
	}
	Student *student = new Student(str);
	if(tail != nullptr)	tail->next = student;
	tail = student;
	stuNum++;
}

void Student::createList(string &str) {
	Student *student = new Student(str);
	head = student;
	tail = student;
}

void Student::newCourse(string &crsName, int score) {
	totScore += score, selectNum++;
	Course *currentCrs = Course::search(crsName);
	currentCrs->newCrsScore(score);
	StuCrsScore *currentScr = scoreHead->search(scoreHead, currentCrs->getIndex());
	currentScr->setScore(score);
}

void Student::operateData(string &str) {
	ofstream fout;
	fout.open("temp.txt", ios::out | ios::trunc);
	fout << str;
	fout.close();

	ifstream fin;
	fin.open("temp.txt", ios::in);
	while (!fin.eof()) {
		int score;
		string crsName;
		fin >> crsName >> score;
		if (crsName.empty())	continue;
		tail->newCourse(crsName, score);
	}
	fin.close();
}//end of operateData