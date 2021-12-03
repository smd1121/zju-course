#include "pch.h"
#include "diarySet.h"

int main(int argc, char *argv[]) {
	/* if there isn't an argument, return -1 */
	if(argc <= 1)	return -1;
	
	string date = argv[1];
	freopen("diary.log", "r", stdin);
	DiarySet diaryset;
	string str;
	
	/* read (from diary.log) till EOF */
	while (!cin.eof()) {
		cin >> str;
		if(str=="" || str == ".")	continue;
		Diary diary;
		diary.setDate(str);
		while (!cin.eof()) {
			cin >> str;
			if (str == ".")	break;
			diary.addLine(str);
		}
		diaryset.addDiary(diary);
	}
	
	/* delete the diary of DATE */
	int flag = diaryset.eraseDiary(date);
	
	/* save the diaries to diary.log */
	freopen("diary.log", "w", stdout);
	diaryset.printSet(1);
	
	return flag;
}
