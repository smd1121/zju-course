#include "myHeader.h"

char ranklistNames[5][100];
int ranklistScores[5];

void newRanklist() {
	FILE *rklist = fopen("ranklist.txt", "w");
	fprintf(rklist, "A 1000\nB 800\nC 600\nD 400\nE 200\n");
	fclose(rklist);
}

void readRanklist() {
	FILE *rklist = fopen("ranklist.txt", "r");
	if (!rklist)	newRanklist();
	rklist = fopen("ranklist.txt", "r");
	
	int i = 0;
	for (; i < 5; i++)
		fscanf(rklist, "%s%d", ranklistNames[i], &ranklistScores[i]);
	fclose(rklist);
}

// score, name
void renewRanklist() {
	readRanklist();
	FILE *rklist = fopen("ranklist.txt", "w");
	
	int i = 0;
	bool hasIn = FALSE;
	for (; i < 5; i++) {
		if (!hasIn && score > ranklistScores[i]) {
			if (!textboxLength) fprintf(rklist, "-");
			else				fprintf(rklist, "%s", buttonContents[TEXTBOX]);
			fprintf(rklist, " %d\n", score);
			hasIn = TRUE;
		}
		if (i == 4 && hasIn)	break;
		fprintf(rklist, "%s %d\n", ranklistNames[i], ranklistScores[i]);
	}
	
	fclose(rklist);
}
