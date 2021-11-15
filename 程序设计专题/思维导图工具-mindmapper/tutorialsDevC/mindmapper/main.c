#include "myHeader.h"

void display()
{
	DisplayClear();
	
	if (mode)
		drawShape(RECTANGLE, 7.5, 4.5, 15, 9, NULL, 0, "Black", NULL, TRUE);
	
	displayMindmap(MindmapRoot, 0);
	
	if (currentNode)
	{
		drawShape(ROUNDED_RECT, 
				currentNode->posX + MindmapLevelWidth[currentNode->level] / 2 - centerX,
            	currentNode->posY - centerY, 
				MindmapLevelWidth[currentNode->level] + 0.1, 
				currentNode->selfHeight + 0.1, 
              	NULL, 1, "Red", "Black", FALSE);
	}
	
	if (mode == 0)
	{
		drawShape(RECTANGLE, 7.5, 8.85, 15, 0.3, NULL, 0, "Gray", NULL, TRUE);
		drawShape(RECTANGLE, 13.5, 4.5, 3, 9, NULL, 0, "Light Gray", NULL, TRUE);
	}
	else
	{
		drawShape(RECTANGLE, 7.5, 8.85, 15, 0.3, NULL, 0, "Black", NULL, TRUE);
		drawShape(RECTANGLE, 13.5, 4.5, 3, 9, NULL, 0, "Black", NULL, TRUE);
	}
	
	displayButtons();
}
extern FILE *fp;
void Main()
{
	SetWindowTitle("Mindmapper");
	SetWindowSize(15, 9);
	InitGraphics();
	initDebug();
	
	DefineColor("Pink", 255.0/255, 192.0/255, 203.0/255);
	//registerTimerEvent(mytimer);
	//startTimer(0, (int)(200/speed));
	registerKeyboardEvent(KeyboardEventProcess);
	registerMouseEvent(MouseEventProcess);
	registerCharEvent(CharEventProcess);
	
	MindmapRoot = newMindmapNode(FALSE, FALSE, 2, "Blue", "Black", "ROOT", NULL);
	Mindmap t1 = newMindmapNode(FALSE, FALSE, 1, "Blue", "Black", "1", MindmapRoot);
	Mindmap t2 = newMindmapNode(FALSE, FALSE, 1, "Blue", "Black", "234", MindmapRoot);
	newMindmapNode(FALSE, FALSE, 1, "Blue", "Black", "3", MindmapRoot);
	newMindmapNode(FALSE, FALSE, 1, "Blue", "Black", "4", MindmapRoot);
	Mindmap t3 = newMindmapNode(FALSE, FALSE, 1, "Blue", "Black", "555555", t1); 
	//t2->isFolded = TRUE;
	newMindmapNode(FALSE, FALSE, 1, "Blue", "Black", "6", t2); 
	newMindmapNode(FALSE, FALSE, 1, "Blue", "Black", "7", t3); 
	newMindmapNode(FALSE, FALSE, 1, "Blue", "Black", "6", t2); 
	newMindmapNode(FALSE, FALSE, 1, "Blue", "Black", "7", t3); 
	newMindmapNode(FALSE, FALSE, 1, "Blue", "Black", "6", t2); 
	newMindmapNode(FALSE, FALSE, 1, "Blue", "Black", "7", t3); 
	newMindmapNode(FALSE, FALSE, 1, "Blue", "Black", "6", t2); 
	newMindmapNode(FALSE, FALSE, 1, "Blue", "Black", "7", t3);
	display();
}
