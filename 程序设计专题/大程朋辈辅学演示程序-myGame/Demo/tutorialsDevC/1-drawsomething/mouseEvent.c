#include "myHeader.h"

void MouseEventProcess(int x, int y, int button, int event)
{
	/* Part 1: Add Circle */		/* 7 - click to create circle */
	if (event == BUTTON_DOWN && button == LEFT_BUTTON && !gameStatus
		&& ScaleYInches(y) >= 3 && ScaleYInches(y) <= 8)
	{
		createShape(TRUE, rand() % 2, 1, ScaleXInches(x), ScaleYInches(y), 
					rand() % 10 / 30.0 + 0.2, 0, colorList[rand()%validColorNumber]);
	}
	
	/* Part 2: Delete Circle */		/* 9 - click to delete circle */
	if (event == BUTTON_DOWN && button == RIGHT_BUTTON && !gameStatus 
		&& ScaleYInches(y) >= 0 && ScaleYInches(y) <= 3)
	{
		Shape *temp = head;
		while (temp) 
		{
			if (isInShape(ScaleXInches(x), ScaleYInches(y), temp))
			{
				deleteShape(temp);
				break;
			}
			temp = temp->next;
		}
	}
	
	/* Part 3: Button */
	if (event == MOUSEMOVE)
		mouseToButton(ScaleXInches(x), ScaleYInches(y), 0);
	if (event == BUTTON_DOWN && button == LEFT_BUTTON)
		mouseToButton(ScaleXInches(x), ScaleYInches(y), 1);
	display();
}
