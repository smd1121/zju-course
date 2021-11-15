#include "myHeader.h"

void mytimer(int);
void KeyboardEventProcess(int key, int event);
void MouseEventProcess(int x, int y, int button, int event);
void CharEventProcess(char c);

extern char ranklistNames[5][100];
extern int ranklistScores[5];

/* 
 * 0 - gaming, 1 - pause, 2 - gameover, 3 - welcome
 * 4 - rank, 5 - save, 6 - load, 7 - saved
 */
int gameStatus = 3; /* 6 - Ctrl + P to pause */

Shape *board; int boardDirection = 1;
double speed = 1.0; int score = 0;

void display()
{
	DisplayClear();
	
	switch (gameStatus) {
		case 0: {	// gaming
			/* 3 - windows structure */
			SetPenColor("Black");
			MovePen(0, 9);
			DrawLine(6, 0);
			MovePen(0, 8.5);
			DrawLine(6, 0);
			MovePen(0, 8);
			DrawLine(6, 0);
			SetPenColor("Super Light Gray");
			MovePen(0, 3);
			DrawLine(6, 0);
			
			SetPenColor("Black");
			char speedDisplay[100], scoreDisplay[100];	
			sprintf(speedDisplay, "CURRENT SPEED: %-.4lf", speed);
			MovePen(1.7, 8.67);
			DrawTextString(speedDisplay);
			sprintf(scoreDisplay, "SCORE: %d", score);
			MovePen(1.7, 8.17);
			DrawTextString(scoreDisplay);
			
			DrawShape(board);
			/* End of 3 */
			
			/* 7 - click to create circle */
			Shape *temp = head;
			while (temp) 
			{
				DrawShape(temp);
				temp = temp->next;
			}
			/* End of 7 */
		} // end of case 0
		
		case 3: {
			break;
		} // end of case 3
		
		case 4: {
			readRanklist();
			
			SetPenColor("Black");
			MovePen(1.7, 7.67);
			char ranklistDisplay[120] = "Rank List";
			DrawTextString(ranklistDisplay);
			
			int i;
			for (i = 0; i < 5; i++) {
				MovePen(1.7, 7.17 - i / 2.0);
				sprintf(ranklistDisplay, "%d %s %d", i + 1, ranklistNames[i], ranklistScores[i]);
				DrawTextString(ranklistDisplay);
			}
			
			break;
		}
	} // end of switch (gameStatus)
	
	if (gameStatus) {
		int i = gamestatusButtonIndex[gameStatus-1];
		for (; i < gamestatusButtonIndex[gameStatus]; i++)
			DrawButton(i);
	}
}

void Main()
{
	SetWindowTitle("Game");							/* 3 - windows structure */
	SetWindowSize(6, 9);							/* 3 - windows structure */
	InitGraphics();
	
	DefineColor("Super Light Gray", .9, .9, .9);	/* 3 - windows structure */
	
	board = createShape(FALSE, TRUE, 0, 3, 0.05, 0.8, 0.1, "Black");
													/* 3 - windows structure */
	
	/* 4 - timer */
	registerTimerEvent(mytimer);
	startTimer(0, (int)(200/speed));
	/* end of 4 */
	
	/* 5 - press R */
	registerKeyboardEvent(KeyboardEventProcess);
	/* end of 5 */
	
	/* 7 - click to create circle */
	registerMouseEvent(MouseEventProcess);
	/* end of 7 */
	
	registerCharEvent(CharEventProcess);
	
	initButtons();
	
	display();
}
