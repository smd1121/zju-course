/* 
 * Input: studentData.txt
 * Output: console; studentList.txt
 */

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#define MAX_SCORE 5

using namespace std;

struct Student {
public:
	string name;
	int score[3];
	float averageScore = 0.0;
} students[15];

int totScore[3], maxScore[3], minScore[3] = { MAX_SCORE, MAX_SCORE, MAX_SCORE };
int numOfStu = 0;

void readData() {
	ifstream file1;
	file1.open("studentData.txt", ios::in);

	for ( ; !file1.eof(); numOfStu++) {
		file1 >> students[numOfStu].name;

		if (students[numOfStu].name.empty()) {
			numOfStu--;
			continue;
		}	// ignore the blank lines in the text

		for (int j = 0; j < 3; j++)
			file1 >> students[numOfStu].score[j];

		for (int j = 0; j < 3; j++) {
			totScore[j] += students[numOfStu].score[j];
			students[numOfStu].averageScore += students[numOfStu].score[j] / 3.0;

			if (students[numOfStu].score[j] > maxScore[j])
				maxScore[j] = students[numOfStu].score[j];
			if (students[numOfStu].score[j] < minScore[j])
				minScore[j] = students[numOfStu].score[j];
		}
	}

	file1.close();
}

void printList() {
	if (!numOfStu) {
		puts("No available data!");
		return;
	}
	
	cout << setiosflags(ios::left);

	cout << "no      name    score1  score2  score3  average" << endl;
	for (int i = 0; i < numOfStu; i++) {
		cout.width(8);
		cout << i + 1;

		cout.width(8);
		cout << students[i].name;

		for (int j = 0; j < 3; j++) {
			cout.width(8);
			cout << students[i].score[j];
		}

		cout.precision(6);
		cout << students[i].averageScore << endl;
	}

	
	cout << "        average ";
	for (int j = 0; j < 3; j++) {
		cout.width(8);
		cout.precision(2);
		cout << (float) totScore[j] / numOfStu;
	}

	cout << endl << "        min     ";
	for (int j = 0; j < 3; j++){
		cout.width(8);
		cout << minScore[j];
	}

	cout << endl << "        max     ";
	for (int j = 0; j < 3; j++){
		cout.width(8);
		cout << maxScore[j];
	}

	cout << endl << endl;
}

void printToFile() {
	ofstream file2;
	file2.open("studentList.txt", ios::out | ios::trunc);

	if (!numOfStu) {
		file2 << "No available data!\n";
		return;
	}

	file2 << setiosflags(ios::left);

	file2 << "no      name    score1  score2  score3  average" << endl;
	for (int i = 0; i < numOfStu; i++) {
		file2.width(8);
		file2 << i + 1;

		file2.width(8);
		file2 << students[i].name;

		for (int j = 0; j < 3; j++) {
			file2.width(8);
			file2 << students[i].score[j];
		}

		file2.precision(6);
		file2 << students[i].averageScore << endl;
	}


	file2 << "        average ";
	for (int j = 0; j < 3; j++) {
		file2.width(8);
		file2.precision(2);
		file2 << (float)totScore[j] / numOfStu;
	}

	file2 << endl << "        min     ";
	for (int j = 0; j < 3; j++) {
		file2.width(8);
		file2 << minScore[j];
	}

	file2 << endl << "        max     ";
	for (int j = 0; j < 3; j++) {
		file2.width(8);
		file2 << maxScore[j];
	}

	file2.close();
}

int main()
{
	readData();
	printList();
	printToFile();
	system("pause");
	return 0;
}
