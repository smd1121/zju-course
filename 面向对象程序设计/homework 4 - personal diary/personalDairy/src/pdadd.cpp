#include "pch.h"
#include "diarySet.h"

int main() {
	freopen("diary.in", "r", stdin);
	DiarySet diaryset;
	string str;
	
	/* read (from diary.in) till EOF */
	while (!cin.eof()) {
		Diary diary;
		cin >> str;
		diary.setDate(str);
		/* if EOF or ".", read next Diary (if there is one) */ 
		while (!cin.eof()) {
			cin >> str;
			if (str == ".")	break;
			diary.addLine(str);
		}
		/* push DIARY into the set */ 
		diaryset.addDiary(diary);
	}
	/* sort the diaries by date */
	diaryset.sortSet();
	
	/* save the diaries to diary.log */
	freopen("diary.log", "w", stdout);
	diaryset.printSet(1);
	return 0;
}
