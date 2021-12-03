#include "pch.h"
#include "diarySet.h"

int main(int argc, char *argv[]) {
	/* if there isn't an argument, return. */
	if(argc <= 1)	return 0;
	
	string date = argv[1];
	freopen("diary.log", "r", stdin);
	freopen("diary.out", "w", stdout);
	DiarySet diaryset;
	string str;
	
	/* read (from diary.log) till EOF */
	while (!cin.eof()) {
		cin >> str;
		if(str=="")	continue;
		Diary diary;
		diary.setDate(str);
		while (!cin.eof()) {
			cin >> str;
			if (str == ".")	break;
			diary.addLine(str);
		}
		diaryset.addDiary(diary);
	}
	
	/* print the diary of DATE */
	diaryset.printPartSet(date, date);
	return 0;
}
