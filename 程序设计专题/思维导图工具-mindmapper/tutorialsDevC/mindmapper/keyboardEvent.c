#include "myHeader.h"

bool isCtrl = FALSE;
void KeyboardEventProcess(int key, int event)
{
	switch(key)
	{
		case VK_LCONTROL: case VK_RCONTROL: case VK_CONTROL:
			isCtrl = !event;
			break;
		case 'N':
			if (isCtrl && currentNode && event == KEY_DOWN)
			{
				newMindmapNode(FALSE, currentNode->isToRight, 1, currentNode->backgroundColor,
							   currentNode->foregroundColor, "新建结点", currentNode);
			}
			break;
		case 'D':
			if (isCtrl && currentNode && event == KEY_DOWN)
			{
				if (currentNode == MindmapRoot)
				{
					MindmapRoot = newMindmapNode(FALSE, FALSE, 1, "Black", "Black", "新建结点", NULL);
					break;
				}
				if (currentNode->lastSibling)
					currentNode->lastSibling->nextSibling = currentNode->nextSibling;
				else
					currentNode->father->firstChild = currentNode->nextSibling;
				if (currentNode->nextSibling)
					currentNode->nextSibling->lastSibling = currentNode->lastSibling;
				currentNode = NULL;
			}
			break;
		case 'M':
			if (isCtrl && event == KEY_DOWN)
			{
				isMovingStatus = !isMovingStatus;
			}
			break;
		case 'S':
			if (isCtrl && event == KEY_DOWN)
			{
				saveIntoFile();
			}
			break;
		case 'O':
			if (isCtrl && event == KEY_DOWN)
			{
				readFromFile();
			}
			break;
		case 'B':
			if (isCtrl && event == KEY_DOWN)
			{
				saveIntoBinaryFile();
			}
			break;
		case 'F':
			if (isCtrl && event == KEY_DOWN)
			{
				buttonEvent(3);
			}
			break;
	}
	display();
}
