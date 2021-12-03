#include "pch.h"
#include "diarySet.h"

int main(int argc, char *argv[]) {
	string start, end;
	if(argc > 2)
		start = argv[1], end = argv[2];
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
	
	/* if there are arguments, print the diarys within the range; if there aren't, print the whole set */
	if(argc > 2)
		diaryset.printPartSet(start, end);
	else
		diaryset.printSet(0);
	return 0;
}
