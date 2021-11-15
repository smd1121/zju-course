#include "myHeader.h"

Mindmap currentNode = NULL;
bool isMovingCenter = FALSE, isMovingStatus = FALSE;

void MouseEventProcess(int x, int y, int button, int event)
{
	static double omx = 0.0, omy = 0.0;
	double mx = ScaleXInches(x), my = ScaleYInches(y);
	
	if (event == BUTTON_DOWN && button == LEFT_BUTTON && isMovingStatus)
		isMovingCenter = TRUE;
	if (event == BUTTON_UP && button == LEFT_BUTTON)
		isMovingCenter = FALSE;
	if (event == MOUSEMOVE && isMovingCenter)
		centerX += omx - mx, centerY += omy - my;
	
	if (event == BUTTON_DOWN && button == LEFT_BUTTON
	 && mx >= 0 && mx <= 12 && my >= 0 && my <= 8.7)
		currentNode = inNode(MindmapRoot, mx, my);
	
	if (event == MOUSEMOVE)
		overedButton = findButton(mx, my);
	
	if (event == BUTTON_DOWN && button == LEFT_BUTTON)
		buttonEvent(findButton(mx, my));
	
	omx = mx, omy = my;
	display();
}

Mindmap inNode(Mindmap M, double mx, double my)
{
	if (!M)	return NULL;
	if (mx >= M->posX - centerX 
	 && mx <= M->posX + MindmapLevelWidth[M->level] - centerX
	 && my >= M->posY - M->selfHeight / 2 - centerY 
	 && my <= M->posY + M->selfHeight / 2 - centerY)
	 	return M;
	
	if (M->isFolded)	return NULL;
	Mindmap returnV = NULL;
	Mindmap temp = M->firstChild;
	while (temp)
	{
		if (inNode(temp, mx, my))
			returnV = inNode(temp, mx, my);
		temp = temp->nextSibling;
	}
	return returnV;
}

#define _b buttons[mode][i]

int findButton(double mx, double my)
{
	int i;
	for (i = 0; i < BUTTON_NUM; i++)
	{
		if (_b.posX - _b.sizeX / 2 <= mx && mx <= _b.posX + _b.sizeX / 2
		 && _b.posY - _b.sizeY / 2 <= my && my <= _b.posY + _b.sizeY / 2)
		 	return i;
	}
	return -1;
}
