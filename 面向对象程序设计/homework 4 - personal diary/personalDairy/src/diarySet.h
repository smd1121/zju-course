#pragma once
#include "diary.h"

bool comp(Diary &a, Diary &b);		/* compare function for sort in <algorithm> */

/* a set of diary */
class DiarySet {
	vector<Diary> diarySet;
public:
	int eraseDiary(string &date);					/* remove the diary of DATE from the set */
	void sortSet();									/* sort the diarys by date */
	void addDiary(Diary &diary);					/* add a new diary. If an entity of the same date is in the diary, the existing one will be replaced. */
	void printSet(int tag);							/* print each Diary in the set */
	void printPartSet(string start, string end);	/* print Diaries with date between START and END */
};
