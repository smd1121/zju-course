#include "myHeader.h"

interShape buttons[MAX_BUTTON];

double buttonPosAndSize[MAX_BUTTON][4] = {
	{3, 5, 2, 1}, {3, 2.5, 2, 1},
	{3, 5, 2, 1}, {3, 2.5, 2, 1},
	{3, 5, 2, 1}, {3, 2.5, 2, 1},
	{3, 2.5, 2, 1},
	{3, 6.5, 2, 1}, {3, 5, 2, 1}, {3, 3.5, 2, 1},
	{3, 6.5, 2, 1}, {3, 5, 2, 1}, {3, 3.5, 2, 1}
};

/* i-th gameStatus, gamestatusButtonIndex[i-1] ~ gamestatusButtonIndex[i] - 1 */
const int gamestatusButtonIndex[MAX_GAME_STATUS + 1] = {0, 2, 4, 6, 7, 10, 13, 16};

int textboxLength = 0;
bool isTextboxInput = FALSE;

char buttonContents[MAX_BUTTON][100] = {
	"RESUME", "SAVE",						/* 2 0~1 Pause */
	"Input your name", "SUBMIT",			/* 2 2~3 Gameover */
	"START", "LOAD",						/* 2 4~5 Welcome */
	"MENU",									/* 1 6   Rank */
	"1", "2", "3",							/* 3 7~9 Save */
	"1", "2", "3",							/* 3 10~12 Load */
	"RESUME", "MENU", "QUIT"				/* 3 13~15 Saved */
};

void initButtons() {
	int i = 0;
	for (; i < MAX_BUTTON; i++) {
		buttons[i].shape = createShape(FALSE, TRUE, 0, buttonPosAndSize[i][0], 	buttonPosAndSize[i][1], 
									   buttonPosAndSize[i][2], buttonPosAndSize[i][3], "Light Gray");
		buttons[i].status = (i == 0);
	}
}

void buttonEvent(enum buttonNames index) {
	switch (index) {
		case START:
			gameStatus = 0;
			break;
		case TEXTBOX:
			isTextboxInput = TRUE;
			break;
		case SUBMIT:
			renewRanklist();
			gameStatus = 4;
			break;
	} // end of switch(index)
}

void DrawButton(enum buttonNames index) {			
	if (!gameStatus
	 || index <  gamestatusButtonIndex[gameStatus-1]
	 || index >= gamestatusButtonIndex[gameStatus])
		return;
	
	DrawShape(buttons[index].shape);
	
	double stringLen = TextStringWidth(buttonContents[index]);
	SetPenColor("Black");
	MovePen(buttons[index].shape->posX - stringLen / 2, buttons[index].shape->posY - GetFontAscent() / 2);
	DrawTextString(buttonContents[index]);
}

/* event: 0 - move, 1 - left click */
void mouseToButton(double mx, double my, int event) {
	int i = 0;
	if (event == 0) {
		for (i = gamestatusButtonIndex[gameStatus-1]; i < gamestatusButtonIndex[gameStatus]; i++)
		{
			if (isInShape(mx, my, buttons[i].shape))
				changeButtonStatus(i, OVER);
			else if (buttons[i].status == OVER && !isInShape(mx, my, buttons[i].shape))
				changeButtonStatus(i, NORMAL);
		}
	}
	else {
		isTextboxInput = FALSE;
		for (i = gamestatusButtonIndex[gameStatus-1]; i < gamestatusButtonIndex[gameStatus]; i++)
			if (isInShape(mx, my, buttons[i].shape))
				changeButtonStatus(i, SELECTED);
	}
}

void changeButtonStatus(int index, int toStatus) {
	buttons[index].status = toStatus;
	switch (toStatus) {
		case INVISIBLE:
			break;
		case NORMAL:
			buttons[index].shape->color = "Light Gray", buttons[index].shape->isFilled = TRUE;
			break;
		case OVER:
			buttons[index].shape->color = "Super Light Gray", buttons[index].shape->isFilled = TRUE;
			break;
		case SELECTED:
			buttonEvent(index);
			buttons[index].shape->color = "Super Light Gray", buttons[index].shape->isFilled = FALSE;
			break;
	}
	display();
}

