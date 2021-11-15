#ifndef _BUTTONS_H_
#define _BUTTONS_H_

#define BUTTON_NUM 46

struct button{
	int index;
	double posX, posY, sizeX, sizeY;
	char contents[64], *color, *overedColor;
};

extern struct button buttons[2][BUTTON_NUM];
void displayButtons();
extern int overedButton, mode;

#endif
