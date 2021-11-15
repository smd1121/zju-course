#ifndef BUTTON_H
#define BUTTON_H

#define MAX_BUTTON 16
enum interShapeStatus {INVISIBLE, NORMAL, OVER, SELECTED};
enum buttonNames {RESUME_FROM_PAUSE, SAVE, TEXTBOX, SUBMIT, START, LOAD, MENU_FROM_RANK, 
				  Save1, Save2, Save3, Load1, Load2, Load3, RESUME_FROM_SAVE, MENU_FROM_SAVE, QUIT};

typedef struct interShape
{
	enum interShapeStatus status;
	Shape *shape;
} interShape;

extern interShape buttons[MAX_BUTTON];
extern const int gamestatusButtonIndex[MAX_GAME_STATUS + 1];
extern char buttonContents[MAX_BUTTON][100];

extern int textboxLength;
extern bool isTextboxInput;

void initButtons();
void buttonEvent(enum buttonNames index);
void DrawButton(enum buttonNames index);
void mouseToButton(double mx, double my, int event);
void changeButtonStatus(int index, int toStatus);

#endif // BUTTON_H
