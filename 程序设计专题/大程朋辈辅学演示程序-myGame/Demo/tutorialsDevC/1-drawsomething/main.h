#ifndef _MAIN_H_
#define _MAIN_H_

#include "shape.h"

#define MAX_GAME_STATUS 8
extern int gameStatus;

extern Shape *board; 
extern int boardDirection;

extern int score;
extern double speed;

extern char colorList[100][100];
extern const int colorNumber, validColorNumber;

extern Shape *head, *tail;

void display();

void Main();

#endif // _MAIN_H_
