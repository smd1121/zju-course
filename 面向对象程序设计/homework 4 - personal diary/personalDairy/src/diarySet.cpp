#include"pch.h"
#include "diary.h"

/* compare function for sort in <algorithm> */
bool comp(const Diary &a, const Diary &b) {
	return a.getDate() < b.getDate();
}

/* a set of diary */
class DiarySet {
	vector<Diary> diarySet;
public:
	int eraseDiary(string &date);
	void sortSet();
	void addDiary(Diary &diary);
	void printSet(int tag);
	void printPartSet(string start, string end);
};

/* remove the diary of DATE from the set */
int DiarySet::eraseDiary(string &date){
	for (vector<Diary>::iterator i = diarySet.begin(); i != diarySet.end(); i++)
		if (i->getDate() == date) {
			diarySet.erase(i);
			return 0;
		}
	return -1;
}

/* sort the diarys by date */
void DiarySet::sortSet() {
	sort(diarySet.begin(), diarySet.end(), comp);
}

/* add a new diary. If an entity of the same date is in the diary, the existing one will be replaced. */
void DiarySet::addDiary(Diary &diary) {
	for (vector<Diary>::iterator i = diarySet.begin(); i != diarySet.end(); i++)
		if (i->getDate() == diary.getDate()) {
			diarySet.erase(i);
			break;
		}
	diarySet.push_back(diary);
}

/* print each Diary in the set */
void DiarySet::printSet(int tag) {
	for (vector<Diary>::iterator i = diarySet.begin(); i != diarySet.end(); i++)
		i->printDiary(tag);
}

/* print Diaries with date between START and END */
void DiarySet::printPartSet(string start, string end) {
	for (vector<Diary>::iterator i = diarySet.begin(); i != diarySet.end(); i++)
		if (i->getDate() >= start)
			if (i->getDate() <= end)
				i->printDiary(0);
			else break;
}
